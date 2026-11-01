//! `pw-launcher-patcher` — 1:1 Port of `Launcher.exe`, `patcher.exe`, `PackDLL.dll`,
//! `SysInfo.dll`, and `PW_Data_Versions.exe`.

pub mod generated_rtti;
pub use generated_rtti::{RttiClassSpec, LAUNCHER_RTTI_CLASSES, PATCHER_RTTI_CLASSES};

use std::fs;
use std::path::Path;

use pw_core::{
    decode_utf16le_null_terminated, zlib_compress, zlib_uncompress, BinaryCursor, IniFile, PwError,
    PwResult,
};
use pw_pck::PckArchive;

// ---------------------------------------------------------------------------
// 1. `PackDLL.dll` 1:1 Port (`.x` Compression & `version.sw` Package Versioning)
// ---------------------------------------------------------------------------

/// `CalcCompressFile` (`0x10001120.c`): `u32_le uncompressed_len` + (`zlib` if smaller, else raw).
pub fn packdll_compress_x(raw: &[u8]) -> PwResult<Vec<u8>> {
    let comp = zlib_compress(raw, 6)?;
    let payload: &[u8] = if comp.len() < raw.len() { &comp } else { raw };
    let mut out = Vec::with_capacity(4 + payload.len());
    out.extend_from_slice(&(raw.len() as u32).to_le_bytes());
    out.extend_from_slice(payload);
    Ok(out)
}

/// `DecompressFile` (`0x10001240.c`): reads `u32_le uncompressed_len`; copies raw if `len + 4 == size`, else `zlib_uncompress`.
pub fn packdll_decompress_x(x_bytes: &[u8]) -> PwResult<Vec<u8>> {
    let mut cur = BinaryCursor::new(x_bytes);
    let uncomp_len = cur.read_u32_le()? as usize;
    let body = cur.remaining_slice();
    if uncomp_len + 4 == x_bytes.len() {
        Ok(body.to_vec())
    } else {
        zlib_uncompress(body, uncomp_len)
    }
}

/// `GetPackVersion` (`0x10002270.c`): reads `<pack>\version.sw` inside a `.pck` archive.
pub fn packdll_read_pck_version(pck: &PckArchive, pack_stem: &str) -> Option<i32> {
    let vpath = format!("{pack_stem}\\version.sw");
    let bytes = pck.read_by_path(&vpath).ok()?;
    let s = String::from_utf8_lossy(&bytes);
    s.split_whitespace().next()?.parse().ok()
}

// ---------------------------------------------------------------------------
// 2. `SysInfo.dll` 1:1 Port (Hardware Probe & Preset Selector)
// ---------------------------------------------------------------------------

#[derive(Debug, Clone)]
pub struct HardwareProfile {
    pub logical_cpus: usize,
    pub total_ram_mb: u64,
    pub recommended_preset_ini: &'static str,
}

pub fn probe_sysinfo() -> HardwareProfile {
    let logical_cpus = std::thread::available_parallelism().map(|n| n.get()).unwrap_or(2);
    let total_ram_mb = fs::read_to_string("/proc/meminfo")
        .ok()
        .and_then(|s| {
            s.lines()
                .find(|l| l.starts_with("MemTotal:"))
                .and_then(|l| l.split_whitespace().nth(1))
                .and_then(|kb| kb.parse::<u64>().ok())
                .map(|kb| kb / 1024)
        })
        .unwrap_or(2048);

    let recommended_preset_ini = if total_ram_mb >= 2048 && logical_cpus >= 4 {
        "GeForce 6800.ini"
    } else if total_ram_mb >= 1024 {
        "GeForce FX 5200.ini"
    } else {
        "Default.ini"
    };

    HardwareProfile { logical_cpus, total_ram_mb, recommended_preset_ini }
}

// ---------------------------------------------------------------------------
// 3. `Launcher.exe` & `patcher.exe` Configuration / Server List Loaders
// ---------------------------------------------------------------------------

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct ServerEntry {
    pub group: String,
    pub name: String,
    pub address: String,
}

pub fn parse_server_list(bytes: &[u8]) -> Vec<ServerEntry> {
    let text = if bytes.starts_with(&[0xFF, 0xFE]) {
        decode_utf16le_null_terminated(&bytes[2..])
    } else {
        String::from_utf8_lossy(bytes).into_owned()
    };
    let mut group = String::new();
    let mut out = Vec::new();
    for raw in text.lines() {
        let line = raw.trim();
        if line.is_empty() || line.starts_with('#') || line.starts_with("//") {
            continue;
        }
        let cols: Vec<&str> = line.split('\t').filter(|c| !c.trim().is_empty()).collect();
        if cols.len() == 1 {
            group = cols[0].trim().to_string();
        } else if cols.len() >= 2 {
            out.push(ServerEntry {
                group: group.clone(),
                name: cols[0].trim().to_string(),
                address: cols[1].trim().to_string(),
            });
        }
    }
    out
}

pub fn load_launcher_ini(pw_root: impl AsRef<Path>) -> PwResult<IniFile> {
    let base = pw_root.as_ref();
    let candidates = [
        base.join("config/patcher/sysinfo.ini"),
        base.join("patcher/server/pid.ini"),
        base.join("launcher/Launcher.ini"),
        base.join("config/default/SystemSettings.ini"),
    ];
    for c in &candidates {
        if c.is_file() {
            return Ok(IniFile::parse_bytes(&pw_core::read_file_checked(c)?));
        }
    }
    Ok(IniFile::default())
}

// ---------------------------------------------------------------------------
// 4. `PW_Data_Versions.exe` Exact CIL 1:1 Port (`RVAs 8272..10952`)
// ---------------------------------------------------------------------------

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct DataVersionRow {
    pub file_name: String,
    pub version: String,
    pub last_modified: String,
    pub time_stamped: Option<String>,
}

impl DataVersionRow {
    /// Mirrors `btnSave_Click` (`RVA 10540`): `"col0 - col1 - col2[ - col3]"`.
    pub fn to_save_line(&self) -> String {
        match &self.time_stamped {
            Some(ts) => format!("{} - {} - {} - {}", self.file_name, self.version, self.last_modified, ts),
            None => format!("{} - {} - {}", self.file_name, self.version, self.last_modified),
        }
    }
}

/// Pure-Rust civil calendar formatter matching `.NET` `new DateTime(1970,1,1,0,0,0,0).AddSeconds(ts).ToString("yyyy-MM-dd HH:mm:ss")`.
pub fn format_unix_timestamp_utc(ts_secs: i64) -> String {
    let days = ts_secs.div_euclid(86_400);
    let rem = ts_secs.rem_euclid(86_400);
    let hour = rem / 3600;
    let minute = (rem % 3600) / 60;
    let second = rem % 60;

    // Howard Hinnant civil_from_days algorithm
    let z = days + 719_468;
    let era = if z >= 0 { z } else { z - 146_096 } / 146_097;
    let doe = (z - era * 146_097) as u64;
    let yoe = (doe - doe / 1460 + doe / 36524 - doe / 146_096) / 365;
    let y = (yoe as i64) + era * 400;
    let doy = doe - (365 * yoe + yoe / 4 - yoe / 100);
    let mp = (5 * doy + 2) / 153;
    let d = doy - (153 * mp + 2) / 5 + 1;
    let m = if mp < 10 { mp + 3 } else { mp - 9 };
    let year = if m <= 2 { y + 1 } else { y };

    format!("{year:04}-{m:02}-{d:02} {hour:02}:{minute:02}:{second:02}")
}

fn file_mtime_short_date(path: &Path) -> String {
    let secs = fs::metadata(path)
        .ok()
        .and_then(|m| m.modified().ok())
        .and_then(|t| t.duration_since(std::time::UNIX_EPOCH).ok())
        .map(|d| d.as_secs() as i64)
        .unwrap_or(0);
    format_unix_timestamp_utc(secs)[..10].to_string()
}

/// Exact 1:1 port of `PW_Data_Versions.main::popList(string dir)` (`RVA 8372`).
pub fn inspect_pw_data_versions(dir: impl AsRef<Path>) -> PwResult<Vec<DataVersionRow>> {
    let dir = dir.as_ref();
    let mut rows = Vec::new();

    // 1. elements.data -> ReadInt16() at offset 0
    let el_path = dir.join("elements.data");
    if el_path.is_file() {
        let head = fs::read(&el_path)?;
        if head.len() < 2 {
            return Err(PwError::UnexpectedEof { offset: 0, needed: 2, available: head.len() });
        }
        let ver = i16::from_le_bytes([head[0], head[1]]);
        rows.push(DataVersionRow {
            file_name: "elements.data".into(),
            version: ver.to_string(),
            last_modified: file_mtime_short_date(&el_path),
            time_stamped: None,
        });
    }

    // 2. tasks.data (or tasks_sample.data fallback when inspecting trimmed workspace) -> second ReadInt32()
    let tasks_candidates = [("tasks.data", dir.join("tasks.data")), ("tasks_sample.data", dir.join("tasks_sample.data"))];
    if let Some((label, tpath)) = tasks_candidates.into_iter().find(|(_, p)| p.is_file()) {
        let head = fs::read(&tpath)?;
        if head.len() >= 8 {
            let ver = i32::from_le_bytes([head[4], head[5], head[6], head[7]]);
            rows.push(DataVersionRow {
                file_name: label.into(),
                version: ver.to_string(),
                last_modified: file_mtime_short_date(&tpath),
                time_stamped: None,
            });
        }
    }

    // 3. gshop{""|1..}.data
    for idx in 0usize.. {
        let fname = if idx == 0 { "gshop.data".to_string() } else { format!("gshop{idx}.data") };
        let fpath = dir.join(&fname);
        if !fpath.is_file() {
            break;
        }
        let head = fs::read(&fpath)?;
        if head.len() >= 4 {
            let ts = i32::from_le_bytes([head[0], head[1], head[2], head[3]]);
            rows.push(DataVersionRow {
                file_name: fname,
                version: ts.to_string(),
                last_modified: file_mtime_short_date(&fpath),
                time_stamped: Some(format_unix_timestamp_utc(ts as i64)),
            });
        }
    }

    // 4. gshopsev{""|1..}.data
    for idx in 0usize.. {
        let fname = if idx == 0 { "gshopsev.data".to_string() } else { format!("gshopsev{idx}.data") };
        let fpath = dir.join(&fname);
        if !fpath.is_file() {
            break;
        }
        let head = fs::read(&fpath)?;
        if head.len() >= 4 {
            let ts = i32::from_le_bytes([head[0], head[1], head[2], head[3]]);
            rows.push(DataVersionRow {
                file_name: fname,
                version: ts.to_string(),
                last_modified: file_mtime_short_date(&fpath),
                time_stamped: Some(format_unix_timestamp_utc(ts as i64)),
            });
        }
    }

    Ok(rows)
}

// ---------------------------------------------------------------------------
// 5. `patcher.exe` `<SkinApp>` XML (`patcher/skin/mainuni.xml`) & `stringtab.txt` Loader
// ---------------------------------------------------------------------------

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct PatcherSkinStyle {
    pub name: String,
    pub face: String,
    pub height: i32,
    pub default_rgb: [u8; 3],
    pub hover_rgb: [u8; 3],
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct PatcherSkinControl {
    pub kind: String,
    pub name: String,
    pub text: String,
    pub map_color: Option<[u8; 3]>,
    pub command_click: Option<String>,
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct PatcherSkinWindow {
    pub name: String,
    pub title: String,
    pub background_image: Option<String>,
    pub map_image: Option<String>,
    pub transparent_key: Option<[u8; 3]>,
    pub controls: Vec<PatcherSkinControl>,
}

#[derive(Debug, Clone, Default)]
pub struct PatcherSkinApp {
    pub styles: Vec<PatcherSkinStyle>,
    pub options: Vec<(String, String)>,
    pub windows: Vec<PatcherSkinWindow>,
}

fn parse_rgb_triplet(s: &str) -> Option<[u8; 3]> {
    let mut it = s.split(',').filter_map(|p| p.trim().parse::<u8>().ok());
    Some([it.next()?, it.next()?, it.next()?])
}

fn xml_attr(tag: &str, key: &str) -> Option<String> {
    let pat = format!("{key}=\"");
    let pos = tag.find(&pat)? + pat.len();
    let rest = &tag[pos..];
    let end = rest.find('"')?;
    Some(rest[..end].to_string())
}

pub fn parse_patcher_skin_xml(bytes: &[u8]) -> PatcherSkinApp {
    let text = if bytes.starts_with(&[0xFF, 0xFE]) {
        decode_utf16le_null_terminated(&bytes[2..])
    } else {
        String::from_utf8_lossy(bytes).into_owned()
    };

    let mut app = PatcherSkinApp::default();
    let mut cur_win: Option<PatcherSkinWindow> = None;
    let mut cur_ctrl: Option<PatcherSkinControl> = None;

    let mut pos = 0usize;
    let raw = text.as_bytes();
    while let Some(rel_lt) = text[pos..].find('<') {
        let lt = pos + rel_lt;
        let Some(rel_gt) = text[lt..].find('>') else {
            break;
        };
        let gt = lt + rel_gt;
        pos = gt + 1;
        if gt <= lt + 1 {
            continue;
        }
        let tag = text[lt + 1..gt].trim();
        if tag.starts_with("!--") || tag.starts_with('?') {
            continue;
        }
        let is_close = tag.starts_with('/');
        let self_close = tag.ends_with('/');
        let clean = tag.trim_start_matches('/').trim_end_matches('/').trim();
        let tag_name = clean.split_whitespace().next().unwrap_or("");
        let _ = raw;

        if is_close {
            if tag_name == "SkinWindow" {
                if let Some(c) = cur_ctrl.take() {
                    if let Some(w) = &mut cur_win {
                        w.controls.push(c);
                    }
                }
                if let Some(w) = cur_win.take() {
                    app.windows.push(w);
                }
            } else if tag_name.starts_with("Skin") && tag_name != "SkinArt" && tag_name != "SkinApp" {
                if let Some(c) = cur_ctrl.take() {
                    if let Some(w) = &mut cur_win {
                        w.controls.push(c);
                    }
                }
            }
            continue;
        }

        match tag_name {
            "Style" => {
                app.styles.push(PatcherSkinStyle {
                    name: xml_attr(clean, "Name").unwrap_or_default(),
                    face: xml_attr(clean, "Face").unwrap_or_else(|| "Tahoma".into()),
                    height: xml_attr(clean, "Height")
                        .and_then(|v| v.parse().ok())
                        .unwrap_or(12),
                    default_rgb: xml_attr(clean, "Default")
                        .and_then(|v| parse_rgb_triplet(&v))
                        .unwrap_or([250, 232, 162]),
                    hover_rgb: xml_attr(clean, "Hover")
                        .and_then(|v| parse_rgb_triplet(&v))
                        .unwrap_or([255, 255, 255]),
                });
            }
            "Option" => {
                if let (Some(n), Some(f)) = (xml_attr(clean, "Name"), xml_attr(clean, "FileName")) {
                    app.options.push((n, f));
                }
            }
            "SkinWindow" => {
                if let Some(prev) = cur_win.take() {
                    app.windows.push(prev);
                }
                cur_win = Some(PatcherSkinWindow {
                    name: xml_attr(clean, "Name").unwrap_or_default(),
                    title: xml_attr(clean, "Text").unwrap_or_default(),
                    background_image: None,
                    map_image: None,
                    transparent_key: None,
                    controls: Vec::new(),
                });
            }
            "SkinArt" => {
                if let Some(w) = &mut cur_win {
                    w.transparent_key =
                        xml_attr(clean, "BackgroundColor").and_then(|v| parse_rgb_triplet(&v));
                }
            }
            "Image" => {
                if cur_ctrl.is_none() {
                    if let Some(w) = &mut cur_win {
                        let ty = xml_attr(clean, "Type").unwrap_or_default();
                        let path = xml_attr(clean, "Path");
                        if ty == "BackgroundImage" {
                            w.background_image = path;
                        } else if ty == "MapImage" {
                            w.map_image = path;
                        }
                    }
                }
            }
            "Command" => {
                if let Some(c) = &mut cur_ctrl {
                    if xml_attr(clean, "Event").as_deref() == Some("OnClick") {
                        c.command_click = xml_attr(clean, "Name");
                    }
                }
            }
            _ if tag_name.starts_with("Skin") && tag_name != "SkinApp" => {
                if let Some(prev_c) = cur_ctrl.take() {
                    if let Some(w) = &mut cur_win {
                        w.controls.push(prev_c);
                    }
                }
                let ctrl = PatcherSkinControl {
                    kind: tag_name.to_string(),
                    name: xml_attr(clean, "Name").unwrap_or_default(),
                    text: xml_attr(clean, "Text").unwrap_or_default(),
                    map_color: xml_attr(clean, "MapColor").and_then(|v| parse_rgb_triplet(&v)),
                    command_click: None,
                };
                if self_close {
                    if let Some(w) = &mut cur_win {
                        w.controls.push(ctrl);
                    }
                } else {
                    cur_ctrl = Some(ctrl);
                }
            }
            _ => {}
        }
    }
    app
}

pub fn parse_stringtab(bytes: &[u8]) -> std::collections::HashMap<u32, String> {
    let text = if bytes.starts_with(&[0xFF, 0xFE]) {
        decode_utf16le_null_terminated(&bytes[2..])
    } else {
        pw_core::decode_gbk(bytes)
    };
    let mut map = std::collections::HashMap::new();
    for line in text.lines() {
        let t = line.trim();
        if t.is_empty() {
            continue;
        }
        if let Some(idx) = t.find(|c: char| c.is_whitespace()) {
            if let Ok(id) = t[..idx].parse::<u32>() {
                map.insert(id, t[idx..].trim().to_string());
            }
        }
    }
    map
}

/// Formats a `stringtab.txt` message template (`%s` placeholders) 1:1 with `patcher.exe` / `Launcher.exe`.
pub fn format_stringtab_entry(
    table: &std::collections::HashMap<u32, String>,
    id: u32,
    args: &[&str],
) -> String {
    let Some(mut tpl) = table.get(&id).cloned() else {
        return String::new();
    };
    for &arg in args {
        if let Some(pos) = tpl.find("%s") {
            tpl.replace_range(pos..pos + 2, arg);
        }
    }
    tpl
}

// ---------------------------------------------------------------------------
// 6. `config/patcher/{update.cfg, video.cfg, resolution.txt}` & `PackDLL` Mutable Patch Engine
// ---------------------------------------------------------------------------

/// Canonical 15 `.pck` stems iterated by `PackDLL::FillPackVersion` (`0x10002110`, `0x1000f030..0x1000f06c`).
pub const PACKDLL_CANONICAL_PACK_STEMS: &[&str] = &[
    "configs",
    "facedata",
    "fonts",
    "gfx",
    "grasses",
    "help",
    "interfaces",
    "litmodels",
    "loddata",
    "models",
    "sfx",
    "shaders",
    "surfaces",
    "textures",
    "trees",
];

fn decode_cfg_utf16_or_utf8(bytes: &[u8]) -> String {
    if bytes.starts_with(&[0xFF, 0xFE]) {
        let mut units = Vec::with_capacity((bytes.len() - 2) / 2);
        for ch in bytes[2..].chunks_exact(2) {
            let u = u16::from_le_bytes([ch[0], ch[1]]);
            if u == 0 {
                break;
            }
            units.push(u);
        }
        String::from_utf16_lossy(&units)
    } else {
        String::from_utf8_lossy(bytes).into_owned()
    }
}

fn encode_cfg_utf16le_with_bom(text: &str) -> Vec<u8> {
    let mut out = Vec::with_capacity(2 + text.len() * 2);
    out.extend_from_slice(&[0xFF, 0xFE]);
    for u in text.encode_utf16() {
        out.extend_from_slice(&u.to_le_bytes());
    }
    out
}

/// 1:1 Codec for `config/patcher/update.cfg`.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct PatcherUpdateConfig {
    pub auto_continue: i32,
    pub select_server_every_time: i32,
    pub auto_updating: i32,
    pub update_server_select: String,
}

impl Default for PatcherUpdateConfig {
    fn default() -> Self {
        Self {
            auto_continue: 0,
            select_server_every_time: 1,
            auto_updating: 0,
            update_server_select: "patch".to_string(),
        }
    }
}

impl PatcherUpdateConfig {
    pub fn parse_bytes(bytes: &[u8]) -> Self {
        let mut cfg = Self::default();
        for line in decode_cfg_utf16_or_utf8(bytes).lines() {
            let mut it = line.split_whitespace();
            let Some(k) = it.next() else { continue };
            let v = it.collect::<Vec<_>>().join(" ");
            match k {
                "AutoContinue" => cfg.auto_continue = v.parse().unwrap_or(0),
                "SelectServerEveryTime" => cfg.select_server_every_time = v.parse().unwrap_or(1),
                "AutoUpdating" => cfg.auto_updating = v.parse().unwrap_or(0),
                "UpdateServerSelect" => cfg.update_server_select = v,
                _ => {}
            }
        }
        cfg
    }

    pub fn to_utf16le_bytes(&self) -> Vec<u8> {
        let s = format!(
            "AutoContinue {}\r\nSelectServerEveryTime {}\r\nAutoUpdating {}\r\nUpdateServerSelect {}\r\n",
            self.auto_continue,
            self.select_server_every_time,
            self.auto_updating,
            self.update_server_select
        );
        encode_cfg_utf16le_with_bom(&s)
    }
}

/// 1:1 Codec for `config/patcher/video.cfg` (all 17 video/audio selector keys).
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct PatcherVideoConfig {
    pub terrain_select: i32,
    pub audio_select: i32,
    pub cloud_select: i32,
    pub grass_select: i32,
    pub water_select: i32,
    pub sight_select: i32,
    pub vegetation_select: i32,
    pub graph_select: i32,
    pub resolution_select: String,
    pub full_glow_select: i32,
    pub mipmap_bias_select: i32,
    pub vertical_sync_select: i32,
    pub space_warp_select: i32,
    pub sun_flare_select: i32,
    pub shadow_select: i32,
    pub wide_screen_select: i32,
    pub full_screen_select: i32,
}

impl Default for PatcherVideoConfig {
    fn default() -> Self {
        Self {
            terrain_select: 1,
            audio_select: 2,
            cloud_select: 4,
            grass_select: 4,
            water_select: 2,
            sight_select: 4,
            vegetation_select: 4,
            graph_select: 2,
            resolution_select: "1280x800".to_string(),
            full_glow_select: 1,
            mipmap_bias_select: 1,
            vertical_sync_select: 1,
            space_warp_select: 1,
            sun_flare_select: 1,
            shadow_select: 1,
            wide_screen_select: 1,
            full_screen_select: 0,
        }
    }
}

impl PatcherVideoConfig {
    pub fn parse_bytes(bytes: &[u8]) -> Self {
        let mut c = Self::default();
        for line in decode_cfg_utf16_or_utf8(bytes).lines() {
            let mut it = line.split_whitespace();
            let Some(k) = it.next() else { continue };
            let Some(v) = it.next() else { continue };
            match k {
                "TerrainSelect" => c.terrain_select = v.parse().unwrap_or(c.terrain_select),
                "AudioSelect" => c.audio_select = v.parse().unwrap_or(c.audio_select),
                "CloudSelect" => c.cloud_select = v.parse().unwrap_or(c.cloud_select),
                "GrassSelect" => c.grass_select = v.parse().unwrap_or(c.grass_select),
                "WaterSelect" => c.water_select = v.parse().unwrap_or(c.water_select),
                "SightSelect" => c.sight_select = v.parse().unwrap_or(c.sight_select),
                "VegetationSelect" => c.vegetation_select = v.parse().unwrap_or(c.vegetation_select),
                "GraphSelect" => c.graph_select = v.parse().unwrap_or(c.graph_select),
                "ResolutionSelect" => c.resolution_select = v.to_string(),
                "FullGlowSelect" => c.full_glow_select = v.parse().unwrap_or(c.full_glow_select),
                "MipMapBiasSelect" => c.mipmap_bias_select = v.parse().unwrap_or(c.mipmap_bias_select),
                "VerticalSyncSelect" => c.vertical_sync_select = v.parse().unwrap_or(c.vertical_sync_select),
                "SpaceWarpSelect" => c.space_warp_select = v.parse().unwrap_or(c.space_warp_select),
                "SunFlareSelect" => c.sun_flare_select = v.parse().unwrap_or(c.sun_flare_select),
                "ShadowSelect" => c.shadow_select = v.parse().unwrap_or(c.shadow_select),
                "WideScreenSelect" => c.wide_screen_select = v.parse().unwrap_or(c.wide_screen_select),
                "FullScreenSelect" => c.full_screen_select = v.parse().unwrap_or(c.full_screen_select),
                _ => {}
            }
        }
        c
    }

    pub fn to_utf16le_bytes(&self) -> Vec<u8> {
        let s = format!(
            "TerrainSelect {}\r\nAudioSelect {}\r\nCloudSelect {}\r\nGrassSelect {}\r\nWaterSelect {}\r\nSightSelect {}\r\nVegetationSelect {}\r\nGraphSelect {}\r\nResolutionSelect {}\r\nFullGlowSelect {}\r\nMipMapBiasSelect {}\r\nVerticalSyncSelect {}\r\nSpaceWarpSelect {}\r\nSunFlareSelect {}\r\nShadowSelect {}\r\nWideScreenSelect {}\r\nFullScreenSelect {}\r\n",
            self.terrain_select,
            self.audio_select,
            self.cloud_select,
            self.grass_select,
            self.water_select,
            self.sight_select,
            self.vegetation_select,
            self.graph_select,
            self.resolution_select,
            self.full_glow_select,
            self.mipmap_bias_select,
            self.vertical_sync_select,
            self.space_warp_select,
            self.sun_flare_select,
            self.shadow_select,
            self.wide_screen_select,
            self.full_screen_select
        );
        encode_cfg_utf16le_with_bom(&s)
    }
}

/// Parses `config/patcher/resolution.txt` (`"WIDTHxHEIGHT"` lines) into `(width, height)` pairs.
pub fn parse_resolution_list(bytes: &[u8]) -> Vec<(u32, u32)> {
    let mut out = Vec::new();
    for line in decode_cfg_utf16_or_utf8(bytes).lines() {
        let clean = line.trim().trim_matches('"');
        if let Some((w, h)) = clean.split_once('x').or_else(|| clean.split_once('X')) {
            if let (Ok(pw), Ok(ph)) = (w.trim().parse::<u32>(), h.trim().parse::<u32>()) {
                out.push((pw, ph));
            }
        }
    }
    out
}

/// Incremental patch operation inside a `patcher.exe` `v_{from}_{to}.inc` manifest.
#[derive(Debug, Clone, PartialEq, Eq)]
pub enum PatchIncOp {
    AddOrReplace { md5_hex: String, rel_path: String },
    Delete { rel_path: String },
}

#[derive(Debug, Clone, Default, PartialEq, Eq)]
pub struct PatcherIncManifest {
    pub version_from: i32,
    pub version_to: i32,
    pub ops: Vec<PatchIncOp>,
}

impl PatcherIncManifest {
    pub fn parse_text(text: &str) -> Self {
        let mut m = Self::default();
        for raw in text.lines() {
            let line = raw.trim();
            if line.is_empty() {
                continue;
            }
            if let Some(rest) = line.strip_prefix('#') {
                let nums: Vec<i32> = rest
                    .split_whitespace()
                    .filter_map(|t| t.parse().ok())
                    .collect();
                if nums.len() >= 2 {
                    m.version_from = nums[0];
                    m.version_to = nums[1];
                }
                continue;
            }
            if let Some(del) = line.strip_prefix('-') {
                let p = del.trim().trim_start_matches(['/', '\\']).replace('/', "\\");
                if !p.is_empty() {
                    m.ops.push(PatchIncOp::Delete { rel_path: p });
                }
            } else {
                let body = line.strip_prefix('+').unwrap_or(line).trim();
                if let Some((hash, path)) = body.split_once(char::is_whitespace) {
                    let p = path.trim().trim_start_matches(['/', '\\']).replace('/', "\\");
                    if !p.is_empty() {
                        m.ops.push(PatchIncOp::AddOrReplace {
                            md5_hex: hash.trim().to_ascii_lowercase(),
                            rel_path: p,
                        });
                    }
                }
            }
        }
        m
    }
}

/// 1:1 Port of `PackDLL.dll`'s mutable `.pck` session (`AddFileToPack` `0x100042a0`,
/// `ReplaceFileInPack` `0x100047e0`, `RemoveFileFromPack`, and `FillPackVersion` `0x10002110`).
#[derive(Debug, Clone, Default)]
pub struct PackDllMutablePck {
    pub pack_stem: String,
    files: std::collections::BTreeMap<String, (String, Vec<u8>)>,
}

impl PackDllMutablePck {
    pub fn new(pack_stem: impl Into<String>) -> Self {
        Self {
            pack_stem: pack_stem.into(),
            files: std::collections::BTreeMap::new(),
        }
    }

    pub fn from_archive(pack_stem: impl Into<String>, archive: &PckArchive) -> PwResult<Self> {
        let mut s = Self::new(pack_stem);
        for entry in &archive.entries {
            let raw = archive.read_entry(entry)?;
            let key = pw_core::normalize_vfs_path(&entry.path);
            s.files.insert(key, (entry.path.replace('/', "\\"), raw));
        }
        Ok(s)
    }

    /// `AddFileToPack` (`0x100042a0`) / `ReplaceFileInPack` (`0x100047e0`).
    pub fn add_or_replace_file(&mut self, rel_path: &str, raw_bytes: Vec<u8>) {
        let display = rel_path.trim_start_matches(['/', '\\']).replace('/', "\\");
        let key = pw_core::normalize_vfs_path(&display);
        self.files.insert(key, (display, raw_bytes));
    }

    /// Decompresses a `.x` patch stream (`DecompressFile` `0x10001240`) and writes it into the `.pck`.
    pub fn apply_x_patch_file(&mut self, rel_path: &str, x_bytes: &[u8]) -> PwResult<()> {
        let raw = packdll_decompress_x(x_bytes)?;
        self.add_or_replace_file(rel_path, raw);
        Ok(())
    }

    /// Removes an entry from the `.pck` (`inc` `-path` directive).
    pub fn remove_file(&mut self, rel_path: &str) -> bool {
        let key = pw_core::normalize_vfs_path(rel_path);
        self.files.remove(&key).is_some()
    }

    /// `FillPackVersion` (`0x10002110`): writes `<pack_stem>\version.sw` (`<= 100` bytes).
    pub fn fill_pack_version(&mut self, version_num: i32) {
        let vpath = format!("{}\\version.sw", self.pack_stem);
        let payload = format!("{version_num} 0\r\n");
        let mut bytes = payload.into_bytes();
        bytes.truncate(100);
        self.add_or_replace_file(&vpath, bytes);
    }

    /// Serializes the updated archive to lossless Angelica `v2.0.2` `.pck` bytes.
    pub fn to_pck_bytes(&self) -> PwResult<Vec<u8>> {
        let mut builder = pw_pck::PckBuilder::new();
        for (orig_path, data) in self.files.values() {
            builder.add_file(orig_path, data.clone());
        }
        builder.build()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_packdll_x_roundtrip_and_pck_version() {
        let sample = b"PackDLL .x patch payload test ".repeat(64);
        let x = packdll_compress_x(&sample).unwrap();
        assert!(x.len() < sample.len());
        assert_eq!(packdll_decompress_x(&x).unwrap(), sample);

        // Also test incompressible 3-byte input (triggers raw branch: uncomp_len + 4 == x.len())
        let tiny = b"abc";
        let x_tiny = packdll_compress_x(tiny).unwrap();
        assert_eq!(x_tiny.len(), 7);
        assert_eq!(packdll_decompress_x(&x_tiny).unwrap(), tiny);

        // Verify RTTI counts recovered for patcher & launcher
        assert_eq!(PATCHER_RTTI_CLASSES.len(), 100);
        assert_eq!(LAUNCHER_RTTI_CLASSES.len(), 45);
        if let Some(elem) = pw_core::find_test_pw142_element(env!("CARGO_MANIFEST_DIR")) {
            let configs = PckArchive::open_path(elem.join("configs.pck")).unwrap();
            let _ = packdll_read_pck_version(&configs, "configs");
        }
    }

    #[test]
    fn test_pw_data_versions_cil_parity_on_real_data_dir() {
        let Some(elem) = pw_core::find_test_pw142_element(env!("CARGO_MANIFEST_DIR")) else {
            return;
        };
        let rows = inspect_pw_data_versions(elem.join("data")).unwrap();
        assert_eq!(rows.len(), 6);
        assert_eq!(rows[0].file_name, "elements.data");
        assert_eq!(rows[0].version, "27");
        assert_eq!(rows[1].version, "75");
        assert_eq!(rows[2].file_name, "gshop.data");
        assert_eq!(rows[2].time_stamped.as_deref(), Some("2019-05-03 15:33:11"));
        assert_eq!(rows[4].file_name, "gshopsev.data");
        assert_eq!(rows[4].time_stamped.as_deref(), Some("2019-05-03 15:33:11"));
    }

    #[test]
    fn test_sysinfo_and_launcher_configs() {
        let hw = probe_sysinfo();
        assert!(hw.logical_cpus >= 1);
        let fallback_root = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("../../../source/pw142");
        let pw_root = pw_core::find_test_pw142_root(env!("CARGO_MANIFEST_DIR"))
            .unwrap_or(fallback_root);
        assert!(pw_root.is_dir(), "expected pw142 root at {}", pw_root.display());

        let ini = load_launcher_ini(&pw_root).unwrap();
        assert!(!ini.sections.is_empty());
        let srv_bytes =
            fs::read(pw_root.join("element/userdata/server/serverlist.txt")).unwrap();
        let servers = parse_server_list(&srv_bytes);
        assert!(!servers.is_empty());

        let skin_bytes = fs::read(pw_root.join("patcher/skin/mainuni.xml")).unwrap();
        let skin = parse_patcher_skin_xml(&skin_bytes);
        assert!(skin.styles.len() >= 5);
        assert!(skin.windows.iter().any(|w| w.name == "Main" || w.name == "Choose"));

        let stab_bytes = fs::read(pw_root.join("patcher/stringtab.txt")).unwrap();
        let stab = parse_stringtab(&stab_bytes);
        assert!(stab.len() >= 15);
        let msg0 = format_stringtab_entry(&stab, 0, &["src.x", "dst.pck"]);
        assert!(msg0.contains("src.x") && msg0.contains("dst.pck"));

        let lstab_bytes = fs::read(pw_root.join("launcher/stringtab.txt")).unwrap();
        let lstab = parse_stringtab(&lstab_bytes);
        assert!(lstab.len() >= 15);

        // Verify `update.cfg`, `video.cfg`, and `resolution.txt` 1:1 roundtrips
        let ucfg_raw = fs::read(pw_root.join("config/patcher/update.cfg")).unwrap();
        let ucfg = PatcherUpdateConfig::parse_bytes(&ucfg_raw);
        assert_eq!(ucfg.update_server_select, "patch");
        assert_eq!(PatcherUpdateConfig::parse_bytes(&ucfg.to_utf16le_bytes()), ucfg);

        let vcfg_raw = fs::read(pw_root.join("config/patcher/video.cfg")).unwrap();
        let vcfg = PatcherVideoConfig::parse_bytes(&vcfg_raw);
        assert!(!vcfg.resolution_select.is_empty());
        assert_eq!(PatcherVideoConfig::parse_bytes(&vcfg.to_utf16le_bytes()), vcfg);

        let res_raw = fs::read(pw_root.join("config/patcher/resolution.txt")).unwrap();
        let res_list = parse_resolution_list(&res_raw);
        assert!(res_list.contains(&(1280, 800)) && res_list.contains(&(3440, 1440)));

        // Verify `PackDllMutablePck` + `.x` patch + `FillPackVersion` + `GetPackVersion`
        assert_eq!(PACKDLL_CANONICAL_PACK_STEMS.len(), 15);
        let inc = PatcherIncManifest::parse_text(
            "# 141 142\n+d41d8cd98f00b204e9800998ecf8427e configs\\skillstr.txt\n-configs\\obsolete.txt\n",
        );
        assert_eq!(inc.version_from, 141);
        assert_eq!(inc.version_to, 142);
        assert_eq!(inc.ops.len(), 2);

        let mut mpck = PackDllMutablePck::new("configs");
        let x_data = packdll_compress_x(b"Tiger Maw\0").unwrap();
        mpck.apply_x_patch_file("configs\\skillstr.txt", &x_data).unwrap();
        mpck.add_or_replace_file("configs\\obsolete.txt", b"old".to_vec());
        assert!(mpck.remove_file("configs/obsolete.txt"));
        mpck.fill_pack_version(142);
        let pck_bytes = mpck.to_pck_bytes().unwrap();
        let reopened = PckArchive::from_bytes(pck_bytes).unwrap();
        assert_eq!(packdll_read_pck_version(&reopened, "configs"), Some(142));
        assert_eq!(reopened.read_by_path("configs\\skillstr.txt").unwrap(), b"Tiger Maw\0");
    }
}
