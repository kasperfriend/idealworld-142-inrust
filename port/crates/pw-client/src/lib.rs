//! `pw-client` — 1:1 Port of `elementclient.exe` (Build `2305`) & `elementlocalize.exe`.
//!
//! Mirrors `CECGame::Init` (`0x42d700.c`), `CECGame::Run`, `CECGameRun` (`0x434b80.c`),
//! `CECHostPlayer`, Win32 Window/DIB/ClearType/Cursor loop, and `elementlocalize.exe`.

pub mod game_app;
pub mod generated_rtti;
pub mod win32_gui;

pub use game_app::{ClientScreenState, InteractiveClientApp, ServerListEntry};
pub use generated_rtti::{RttiClassSpec, ELEMENTCLIENT_RTTI_CLASSES};

use std::collections::HashMap;
use std::fs;
use std::path::{Path, PathBuf};

use pw_aui::AuiManager;
use pw_core::{
    decode_gbk, decode_gbk_null_terminated, decode_utf16le_null_terminated,
    find_path_case_insensitive, IniFile, PwError, PwResult, Vec3,
};
use pw_data::{
    AiPolicyDatabase, DomainDatabase, DynTasksDatabase, ElementSectionData, ElementsDatabase,
    GShopClientDatabase, TaskNpcDatabase, TasksDatabase,
};
use pw_gnet::CecGameSession;
use pw_pck::{PckArchive, VirtualFileSystem};
use pw_render_audio::{parse_truetype_font, A3DCamera, ShaderCatalog, SystemSettings, TrueTypeFontInfo};
use pw_skill::{ElementSkill, Profession, ELEMENT_SKILL_VERSION};
use pw_world::{MapInstanceBundle, SceneCtrlConfig};

/// `DAT_00951a7c` in `elementclient.exe` (`Build 2305`).
pub const ELEMENTCLIENT_BUILD_VERSION: u32 = 2305;

/// All 16 Angelica `.pck` archives in a full Perfect World 1.4.2 `element/` directory.
pub const ALL_ELEMENT_PCKS: &[(&str, &str)] = &[
    ("configs", "configs.pck"),
    ("interfaces", "interfaces.pck"),
    ("shaders", "shaders.pck"),
    ("fonts", "fonts.pck"),
    ("surfaces", "surfaces.pck"),
    ("textures", "textures.pck"),
    ("models", "models.pck"),
    ("building", "building.pck"),
    ("grasses", "grasses.pck"),
    ("trees", "trees.pck"),
    ("sfx", "sfx.pck"),
    ("gfx", "gfx.pck"),
    ("litmodels", "litmodels.pck"),
    ("facedata", "facedata.pck"),
    ("loddata", "loddata.pck"),
    ("script", "help/script.pck"),
];

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum GameRunState {
    Login,
    InWorld,
}

#[derive(Debug, Clone)]
pub struct CecHostPlayer {
    pub role_id: u32,
    pub name: String,
    pub profession: Profession,
    pub level: u32,
    pub position: Vec3,
    pub active_quests: Vec<u32>,
}

impl CecHostPlayer {
    pub fn new(
        role_id: u32,
        name: impl Into<String>,
        cls: i32,
        level: u32,
        position: Vec3,
    ) -> Self {
        Self {
            role_id,
            name: name.into(),
            profession: Profession::from_cls(cls),
            level,
            position,
            active_quests: Vec::new(),
        }
    }

    pub fn cast_skill(&self, skill_id: u32, level: i32) -> PwResult<ElementSkill> {
        ElementSkill::create(skill_id, level)
            .ok_or_else(|| PwError::InvalidData(format!("unknown skill ID {skill_id}")))
    }
}

#[derive(Debug, Clone)]
pub struct CoordDataSpawn {
    pub template_id: u32,
    pub map_name: String,
    pub pos: Vec3,
}

#[derive(Debug, Clone)]
pub struct NpcEssenceInfo {
    pub id: u32,
    pub name: String,
    pub ecm_path: String,
    pub greeting: String,
}

#[derive(Debug, Clone)]
pub struct MonsterEssenceInfo {
    pub id: u32,
    pub name: String,
    pub short_desc: String,
    pub level: u32,
    pub max_hp: u32,
    pub ecm_path: String,
}

pub struct CecGame {
    pub build_version: u32,
    pub skill_abi_version: u32,
    pub element_root: PathBuf,
    pub system_settings: IniFile,
    pub video_audio_settings: SystemSettings,
    pub customize_catalog: pw_data::CustomizePresetCatalog,
    pub vfs: VirtualFileSystem,
    pub elements_db: ElementsDatabase,
    pub npc_essences: HashMap<u32, NpcEssenceInfo>,
    pub monster_essences: HashMap<u32, MonsterEssenceInfo>,
    pub coord_spawns: Vec<CoordDataSpawn>,
    pub skill_names: HashMap<u32, String>,
    pub loc_tables: pw_data::EnglishLocalizationTables,
    pub tasks_db: TasksDatabase,
    pub dyn_tasks_db: DynTasksDatabase,
    pub task_npc_db: TaskNpcDatabase,
    pub gshop_db: GShopClientDatabase,
    pub domain_db: DomainDatabase,
    pub aipolicy_db: AiPolicyDatabase,
    pub aui_manager: AuiManager,
    pub shader_catalog: ShaderCatalog,
    pub fonts: Vec<TrueTypeFontInfo>,
    pub raw_font_blobs: Vec<Vec<u8>>,
    pub server_list: Vec<ServerListEntry>,
    pub scene_ctrl: SceneCtrlConfig,
    pub camera_presets: Vec<(Vec3, Vec3)>,
    pub available_maps: Vec<String>,
    pub active_map: MapInstanceBundle,
    pub camera: A3DCamera,
    pub run_state: GameRunState,
    pub session: CecGameSession,
    pub host_player: Option<CecHostPlayer>,
}

impl CecGame {
    /// Executes the complete `CECGame::Init` (`0x42d700.c`) boot sequence on an `element/` directory.
    pub fn init(element_root: impl AsRef<Path>) -> PwResult<Self> {
        let passed = element_root.as_ref();
        let root = if find_path_case_insensitive(passed, "configs.pck").is_some() {
            passed.to_path_buf()
        } else if find_path_case_insensitive(passed, "element/configs.pck").is_some() {
            find_path_case_insensitive(passed, "element").unwrap_or_else(|| passed.join("element"))
        } else {
            passed.to_path_buf()
        };

        // 1. Enforce ElementSkill DLL ABI == 15 (`0x42d700.c`)
        let skill_ver = ElementSkill::get_version();
        if skill_ver != ELEMENT_SKILL_VERSION {
            return Err(PwError::UnsupportedVersion {
                format: "ElementSkill ABI",
                version: skill_ver,
            });
        }

        // 2. Load SystemSettings.ini if present (case-insensitive for Windows/Linux parity)
        let system_settings = find_path_case_insensitive(&root, "userdata/SystemSettings.ini")
            .or_else(|| find_path_case_insensitive(&root, "../config/default/SystemSettings.ini"))
            .and_then(|p| fs::read(p).ok())
            .map(|b| IniFile::parse_bytes(&b))
            .unwrap_or_default();
        let video_audio_settings = SystemSettings::from_ini(&system_settings);

        // 3. Mount all available Angelica .pck v2.0.2 packages lazily (seeking trailer only, <5MB RAM)
        let mut vfs = VirtualFileSystem::new(Some(root.clone()));
        let configs_path = find_path_case_insensitive(&root, "configs.pck")
            .unwrap_or_else(|| root.join("configs.pck"));
        let interfaces_path = find_path_case_insensitive(&root, "interfaces.pck")
            .unwrap_or_else(|| root.join("interfaces.pck"));
        let shaders_path = find_path_case_insensitive(&root, "shaders.pck")
            .unwrap_or_else(|| root.join("shaders.pck"));
        let fonts_path = find_path_case_insensitive(&root, "fonts.pck")
            .unwrap_or_else(|| root.join("fonts.pck"));

        let configs_pck = PckArchive::open_path(configs_path)?;
        let interfaces_pck = PckArchive::open_path(interfaces_path)?;
        let shaders_pck = PckArchive::open_path(shaders_path)?;
        let fonts_pck = PckArchive::open_path(fonts_path)?;

        let aui_manager = AuiManager::load_from_interfaces_pck(&interfaces_pck);
        let shader_catalog = ShaderCatalog::load_from_shaders_pck(&shaders_pck)?;
        let mut fonts = Vec::with_capacity(fonts_pck.len());
        let mut raw_font_blobs = Vec::with_capacity(fonts_pck.len());
        for entry in &fonts_pck.entries {
            let bytes = fonts_pck.read_entry(entry)?;
            fonts.push(parse_truetype_font(&bytes)?);
            raw_font_blobs.push(bytes);
        }

        let scene_ctrl = parse_scenectrl_config(&configs_pck);
        let coord_spawns = parse_coord_data_spawns(&configs_pck);
        let skill_names = parse_skillstr_names(&configs_pck);
        let camera_presets: Vec<(Vec3, Vec3)> = scene_ctrl
            .cameras
            .iter()
            .map(|c| (c.pos, c.dir))
            .collect();

        vfs.mount_pck("configs", configs_pck);
        vfs.mount_pck("interfaces", interfaces_pck);
        vfs.mount_pck("shaders", shaders_pck);
        vfs.mount_pck("fonts", fonts_pck);

        for &(mount_name, rel_pck) in &ALL_ELEMENT_PCKS[4..] {
            if let Some(p) = find_path_case_insensitive(&root, rel_pck) {
                if p.is_file() {
                    if let Ok(archive) = PckArchive::open_path(&p) {
                        vfs.mount_pck(mount_name, archive);
                    }
                }
            }
        }

        let loc_tables = pw_data::EnglishLocalizationTables::load_from_reader(|p| vfs.read_file(p).ok());

        // 4. Parse `userdata/server/serverlist.txt` & `userdata/currentserver.ini`
        let server_list = load_server_list(&root);

        // 5. Load static world databases (`elements.data`, `tasks*.data`, `gshop.data`, `domain.data`, `aipolicy.data`)
        let data_dir = find_path_case_insensitive(&root, "data").unwrap_or_else(|| root.join("data"));
        let elements_path = find_path_case_insensitive(&data_dir, "elements.data")
            .unwrap_or_else(|| data_dir.join("elements.data"));
        let elements_db = ElementsDatabase::parse_exact(&pw_core::read_file_checked(elements_path)?)?;
        let (npc_essences, monster_essences) = index_npc_and_monster_essences(&elements_db);

        let tasks_path = find_path_case_insensitive(&data_dir, "tasks.data")
            .or_else(|| find_path_case_insensitive(&data_dir, "tasks_sample.data"))
            .unwrap_or_else(|| data_dir.join("tasks.data"));
        let tasks_db = TasksDatabase::parse_exact(&pw_core::read_file_checked(&tasks_path)?)?;

        let dyn_path = find_path_case_insensitive(&data_dir, "dyn_tasks.data")
            .or_else(|| find_path_case_insensitive(&root, "userdata/dyn_tasks.data"))
            .unwrap_or_else(|| data_dir.join("dyn_tasks.data"));
        let dyn_tasks_db = DynTasksDatabase::parse_exact(&pw_core::read_file_checked(dyn_path)?)?;

        let task_npc_path = find_path_case_insensitive(&data_dir, "task_npc.data")
            .unwrap_or_else(|| data_dir.join("task_npc.data"));
        let task_npc_db = TaskNpcDatabase::parse_exact(&pw_core::read_file_checked(task_npc_path)?)?;

        let gshop_path = find_path_case_insensitive(&data_dir, "gshop.data")
            .unwrap_or_else(|| data_dir.join("gshop.data"));
        let gshop_db = GShopClientDatabase::parse_exact(&pw_core::read_file_checked(gshop_path)?)?;

        let domain_path = find_path_case_insensitive(&data_dir, "domain.data")
            .unwrap_or_else(|| data_dir.join("domain.data"));
        let domain_db = DomainDatabase::parse_exact(&pw_core::read_file_checked(domain_path)?)?;

        let aipolicy_path = find_path_case_insensitive(&data_dir, "aipolicy.data")
            .unwrap_or_else(|| data_dir.join("aipolicy.data"));
        let aipolicy_db = AiPolicyDatabase::parse_exact(&pw_core::read_file_checked(aipolicy_path)?)?;

        // 6. Discover available maps (`maps/*`) and load initial map (`Maps\Login` if present, else `maps\a01`)
        let available_maps = discover_maps(&root);
        let active_map = if let Some(login_dir) = find_path_case_insensitive(&root, "maps/login") {
            MapInstanceBundle::load_map_dir(&login_dir, "login").or_else(|_| {
                let a01 = find_path_case_insensitive(&root, "maps/a01")
                    .unwrap_or_else(|| root.join("maps/a01"));
                MapInstanceBundle::load_map_dir(a01, "a01")
            })?
        } else {
            let a01 = find_path_case_insensitive(&root, "maps/a01")
                .unwrap_or_else(|| root.join("maps/a01"));
            MapInstanceBundle::load_map_dir(a01, "a01")?
        };

        let camera = A3DCamera::from_settings(&video_audio_settings);

        Ok(Self {
            build_version: ELEMENTCLIENT_BUILD_VERSION,
            skill_abi_version: skill_ver,
            element_root: root.clone(),
            system_settings,
            video_audio_settings,
            customize_catalog: pw_data::CustomizePresetCatalog::load_from_element_dir(&root),
            vfs,
            elements_db,
            npc_essences,
            monster_essences,
            coord_spawns,
            skill_names,
            loc_tables,
            tasks_db,
            dyn_tasks_db,
            task_npc_db,
            gshop_db,
            domain_db,
            aipolicy_db,
            aui_manager,
            shader_catalog,
            fonts,
            raw_font_blobs,
            server_list,
            scene_ctrl,
            camera_presets,
            available_maps,
            active_map,
            camera,
            run_state: GameRunState::Login,
            session: CecGameSession::new("player", ""),
            host_player: None,
        })
    }

    pub fn load_map_by_name(&mut self, map_name: &str) -> PwResult<()> {
        let center = if map_name.eq_ignore_ascii_case("world") {
            MapInstanceBundle::ARCHOSAUR_DEFAULT_CENTER
        } else {
            Vec3::ZERO
        };
        self.load_map_by_name_at(map_name, center)
    }

    /// Returns the pure original English skill name from `configs\skillstr.txt` (`id * 10`),
    /// guaranteed completely free of Chinese symbols!
    pub fn english_skill_name(&self, skill_id: u32) -> String {
        if let Some((n, _)) = self.loc_tables.skills.get(&skill_id) {
            if !n.is_empty() && !pw_data::has_cjk(n) {
                return n.clone();
            }
        }
        if let Some(n) = self.skill_names.get(&skill_id) {
            if !n.is_empty() && !pw_data::has_cjk(n) {
                return n.clone();
            }
        }
        format!("Skill #{skill_id}")
    }

    /// Formats the authentic multi-color `^RRGGBB` English skill tooltip from `configs\skillstr.txt`
    /// (`id * 10` & `id * 10 + 1`) using per-level `ElementSkill::evaluate_level_params()`.
    pub fn english_skill_tooltip(&self, skill_id: u32, level: i32, hotkey: Option<usize>) -> String {
        let formatted = if let Some(sk) = ElementSkill::create(skill_id, level) {
            let p = sk.evaluate_level_params();
            self.loc_tables.format_skill_tooltip_with_eval(
                skill_id,
                p.level.max(1) as u32,
                p.range_m,
                p.mp_cost,
                p.channel_s,
                p.cast_s,
                p.cooldown_s,
                p.weapon_damage_pct,
                p.flat_bonus_damage,
            )
        } else {
            self.loc_tables
                .format_skill_tooltip(skill_id, level.max(1) as u32, 125.0, 6.0)
        };
        if let Some(k) = hotkey {
            format!("^8ce8ff[Hotkey {k}]\n{formatted}")
        } else {
            formatted
        }
    }

    /// Resolves any `ElementSkill` `TeamState` (`1..=167`) to `(EnglishName, EnglishDesc, Option<dds_icon>)`
    /// using `configs\buff_str.txt` + `TEAM_STATES` (`iconlist_state.dds`), guaranteed `0` CJK!
    pub fn english_buff_info(&self, state_id: u32) -> (String, String, Option<&'static str>) {
        let icon = ElementSkill::query_team_state(state_id)
            .map(|ts| ts.icon)
            .filter(|s| !s.is_empty());
        if let Some((name, desc)) = self.loc_tables.buffs.get(&state_id) {
            return (name.clone(), desc.clone(), icon);
        }
        let fallback_name = match state_id {
            1 => "Stunned",
            2 => "Sleep",
            3 => "Slowed",
            4 => "Physical Thorns",
            5 => "Plume Shield",
            6 => "Pyrogram Shell",
            7 => "Glacial Embrace",
            28 => "Wing Shield",
            _ => "",
        };
        let name = if fallback_name.is_empty() {
            format!("Status #{state_id}")
        } else {
            fallback_name.to_string()
        };
        (name, "Active cultivation status effect.".to_string(), icon)
    }

    pub fn load_map_by_name_at(&mut self, map_name: &str, center: Vec3) -> PwResult<()> {
        let rel = format!("maps/{map_name}");
        let dir = find_path_case_insensitive(&self.element_root, &rel)
            .ok_or_else(|| PwError::InvalidData(format!("map directory not found: {rel}")))?;
        self.active_map = MapInstanceBundle::load_map_dir_at(dir, map_name, Some(center))?;
        Ok(())
    }

    pub fn enter_world(&mut self, player: CecHostPlayer) {
        self.host_player = Some(player);
        self.run_state = GameRunState::InWorld;
    }
}

fn discover_maps(root: &Path) -> Vec<String> {
    let mut maps = Vec::new();
    if let Some(maps_dir) = find_path_case_insensitive(root, "maps") {
        if let Ok(rd) = fs::read_dir(maps_dir) {
            for entry in rd.flatten() {
                if entry.path().is_dir() {
                    if let Some(name) = entry.file_name().to_str() {
                        maps.push(name.to_string());
                    }
                }
            }
        }
    }
    maps.sort_by_key(|a| a.to_ascii_lowercase());
    maps
}

fn parse_scenectrl_config(configs_pck: &PckArchive) -> SceneCtrlConfig {
    let Some(bytes) = configs_pck
        .read_by_path("configs\\scenectrl.ini")
        .ok()
        .or_else(|| configs_pck.read_by_path("scenectrl.ini").ok())
    else {
        return SceneCtrlConfig::from_ini(&IniFile::default());
    };
    SceneCtrlConfig::from_ini(&IniFile::parse_bytes(&bytes))
}

fn parse_coord_data_spawns(configs_pck: &PckArchive) -> Vec<CoordDataSpawn> {
    let Some(bytes) = configs_pck
        .read_by_path("configs\\coord_data.txt")
        .ok()
        .or_else(|| configs_pck.read_by_path("coord_data.txt").ok())
    else {
        return Vec::new();
    };
    let text = decode_gbk(&bytes);
    let mut out = Vec::new();
    for raw_line in text.lines() {
        let line = raw_line.trim();
        if line.is_empty() || line.starts_with('#') || line.starts_with("//") {
            continue;
        }
        let mut cols = line.split('\t').map(str::trim).filter(|s| !s.is_empty());
        let Some(id_s) = cols.next() else { continue };
        let Ok(template_id) = id_s.parse::<u32>() else {
            continue;
        };
        let Some(map_s) = cols.next() else { continue };
        let Some(coord_s) = cols.next() else { continue };
        // `coord_data.txt` stores either `<id>\t<map>\t<x> <y> <z>` or `<id>\t<map>\t<x>,<y>,<z>` or `<id>\t<map>\t<x>\t<y>\t<z>`
        let mut nums: Vec<f32> = coord_s
            .split(|c: char| c.is_whitespace() || c == ',')
            .filter(|s| !s.is_empty())
            .filter_map(|s| s.parse::<f32>().ok())
            .collect();
        for extra in cols {
            for tok in extra.split(|c: char| c.is_whitespace() || c == ',') {
                if let Ok(v) = tok.parse::<f32>() {
                    nums.push(v);
                }
            }
        }
        if nums.len() >= 3 {
            out.push(CoordDataSpawn {
                template_id,
                map_name: map_s.to_ascii_lowercase(),
                pos: Vec3::new(nums[0], nums[1], nums[2]),
            });
        }
    }
    out
}

fn parse_skillstr_names(configs_pck: &PckArchive) -> HashMap<u32, String> {
    let mut map = HashMap::new();
    let Some(bytes) = configs_pck
        .read_by_path("configs\\skillstr.txt")
        .ok()
        .or_else(|| configs_pck.read_by_path("skillstr.txt").ok())
    else {
        return map;
    };
    let text = if bytes.starts_with(&[0xFF, 0xFE]) {
        let u16s: Vec<u16> = bytes[2..]
            .chunks_exact(2)
            .map(|c| u16::from_le_bytes([c[0], c[1]]))
            .collect();
        String::from_utf16_lossy(&u16s)
    } else {
        decode_gbk(&bytes)
    };
    for raw_line in text.lines() {
        let line = raw_line.trim();
        if line.is_empty() || line.starts_with('#') || line.starts_with("//") {
            continue;
        }
        if let Some((num_part, rest)) = line.split_once(|c: char| c.is_whitespace()) {
            if let Ok(key_id) = num_part.trim().parse::<u32>() {
                // `skillstr.txt` stores `skill_id * 10` = Name (`key % 10 == 0`), `skill_id * 10 + 1` = Description
                if key_id >= 10 && key_id % 10 == 0 {
                    let clean = rest.trim().trim_matches('"').trim();
                    if !clean.is_empty() {
                        map.insert(key_id / 10, clean.to_string());
                    }
                }
            }
        }
    }
    map
}

fn index_npc_and_monster_essences(
    db: &ElementsDatabase,
) -> (HashMap<u32, NpcEssenceInfo>, HashMap<u32, MonsterEssenceInfo>) {
    let mut npcs = HashMap::new();
    let mut monsters = HashMap::new();

    // Section 39 = `MONSTER_ESSENCE` (`1528B`: `id @0`, `name @+8..72`, `short_desc @+104..136`, `ecm @+144..272`, `level @+544`, `hp @+552`)
    if let Some(ElementSectionData::FixedTable {
        record_size,
        count,
        raw_records,
    }) = db.sections.get(39)
    {
        let rsz = *record_size;
        if rsz >= 560 {
            for i in 0..*count {
                let rec = &raw_records[i * rsz..(i + 1) * rsz];
                let id = u32::from_le_bytes([rec[0], rec[1], rec[2], rec[3]]);
                let name = decode_utf16le_null_terminated(&rec[8..72]).trim().to_string();
                let short_desc = decode_utf16le_null_terminated(&rec[104..136])
                    .trim()
                    .to_string();
                let ecm_path = decode_gbk_null_terminated(&rec[144..272])
                    .trim()
                    .replace('\\', "/");
                let level = u32::from_le_bytes([rec[544], rec[545], rec[546], rec[547]]);
                let max_hp = u32::from_le_bytes([rec[552], rec[553], rec[554], rec[555]]);
                if id != 0
                    && !name.is_empty()
                    && !pw_data::has_cjk(&name)
                    && !ecm_path.is_empty()
                {
                    monsters.insert(
                        id,
                        MonsterEssenceInfo {
                            id,
                            name,
                            short_desc: if pw_data::has_cjk(&short_desc) {
                                String::new()
                            } else {
                                short_desc
                            },
                            level: level.max(1),
                            max_hp: max_hp.max(100),
                            ecm_path,
                        },
                    );
                }
            }
        }
    }

    // Section 58 = `NPC_ESSENCE` (`852B`: `id @0`, `name @+4..68`, `ecm @+80..208`, `greeting @+216..728`)
    if let Some(ElementSectionData::FixedTable {
        record_size,
        count,
        raw_records,
    }) = db.sections.get(58)
    {
        let rsz = *record_size;
        if rsz >= 728 {
            for i in 0..*count {
                let rec = &raw_records[i * rsz..(i + 1) * rsz];
                let id = u32::from_le_bytes([rec[0], rec[1], rec[2], rec[3]]);
                let name = decode_utf16le_null_terminated(&rec[4..68]).trim().to_string();
                let ecm_path = decode_gbk_null_terminated(&rec[80..208])
                    .trim()
                    .replace('\\', "/");
                let greeting = decode_utf16le_null_terminated(&rec[216..728])
                    .trim()
                    .to_string();
                if id != 0
                    && !name.is_empty()
                    && !pw_data::has_cjk(&name)
                    && !ecm_path.is_empty()
                {
                    npcs.insert(
                        id,
                        NpcEssenceInfo {
                            id,
                            name,
                            ecm_path,
                            greeting: if pw_data::has_cjk(&greeting) {
                                String::new()
                            } else {
                                greeting
                            },
                        },
                    );
                }
            }
        }
    }

    (npcs, monsters)
}

fn load_server_list(root: &Path) -> Vec<ServerListEntry> {
    let mut list = Vec::new();
    if let Some(p) = find_path_case_insensitive(root, "userdata/server/serverlist.txt") {
        if let Ok(bytes) = fs::read(p) {
            let text = if bytes.starts_with(&[0xFF, 0xFE]) {
                decode_utf16le_null_terminated(&bytes[2..])
            } else {
                String::from_utf8_lossy(&bytes).into_owned()
            };
            let mut current_group = "Perfect World".to_string();
            for raw_line in text.lines() {
                let line = raw_line.trim();
                if line.is_empty() || line.starts_with('#') || line.starts_with("//") {
                    continue;
                }
                let cols: Vec<&str> = line
                    .split('\t')
                    .map(str::trim)
                    .filter(|s| !s.is_empty())
                    .collect();
                if cols.len() == 1 {
                    current_group = cols[0].to_string();
                } else if cols.len() >= 2 {
                    let name = cols[0].to_string();
                    // PW `serverlist.txt` uses `29000:127.0.0.1` (`port:host`) OR `host:port`
                    let raw_ep = cols[1].split_whitespace().next().unwrap_or(cols[1]);
                    let addr = normalize_pw_endpoint(raw_ep);
                    list.push(ServerListEntry {
                        group: current_group.clone(),
                        name,
                        addr,
                    });
                }
            }
        }
    }
    if list.is_empty() {
        if let Some(p) = find_path_case_insensitive(root, "userdata/currentserver.ini") {
            if let Ok(bytes) = fs::read(p) {
                let ini = IniFile::parse_bytes(&bytes);
                if let Some(raw_ep) = ini.get("Server", "CurrentServerAddress") {
                    let name = ini
                        .get("Server", "CurrentServer")
                        .unwrap_or("Local")
                        .to_string();
                    list.push(ServerListEntry {
                        group: ini.get("Server", "CurrentLine").unwrap_or("PW 1.4.2").to_string(),
                        name,
                        addr: normalize_pw_endpoint(raw_ep),
                    });
                }
            }
        }
    }
    if list.is_empty() {
        list.push(ServerListEntry {
            group: "PW 1.4.2".to_string(),
            name: "Local".to_string(),
            addr: "127.0.0.1:29000".to_string(),
        });
    }
    list
}

fn normalize_pw_endpoint(ep: &str) -> String {
    let parts: Vec<&str> = ep.trim().split(':').collect();
    if parts.len() == 2 {
        // If first part is a port (`29000`) and second part has dots (`127.0.0.1`), swap to `host:port`!
        if parts[0].chars().all(|c| c.is_ascii_digit()) && parts[1].contains('.') {
            return format!("{}:{}", parts[1], parts[0]);
        }
        return format!("{}:{}", parts[0], parts[1]);
    }
    format!("{}:29000", ep.trim())
}

/// 1:1 port of `elementlocalize.exe` localization statistics & string extractor.
#[derive(Debug, Clone)]
pub struct LocalizationSummary {
    pub element_talk_trees: usize,
    pub quest_nodes_scanned: usize,
    pub ai_talk_operations: usize,
    pub gshop_named_items: usize,
}

pub fn summarize_localization(game: &CecGame) -> LocalizationSummary {
    let element_talk_trees = game
        .elements_db
        .sections
        .iter()
        .map(|s| match s {
            pw_data::ElementSectionData::TalkTable(t) => t.len(),
            _ => 0,
        })
        .sum();
    let ai_talk_operations = game
        .aipolicy_db
        .policies
        .iter()
        .flat_map(|p| &p.triggers)
        .flat_map(|t| &t.operations)
        .filter(|op| op.op_type == 2)
        .count();
    LocalizationSummary {
        element_talk_trees,
        quest_nodes_scanned: game.tasks_db.total_nodes + game.dyn_tasks_db.tasks.len(),
        ai_talk_operations,
        gshop_named_items: game.gshop_db.items.len(),
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_full_cecgame_boot_and_localization_pipeline() {
        assert_eq!(ELEMENTCLIENT_RTTI_CLASSES.len(), 1_134);
        let Some(elem) = pw_core::find_test_pw142_element(env!("CARGO_MANIFEST_DIR")) else {
            return;
        };
        let mut game = CecGame::init(elem).unwrap();
        assert_eq!(game.build_version, 2305);
        assert_eq!(game.skill_abi_version, 15);
        assert!(game.vfs.package_count() >= 5);
        assert!(game.vfs.total_indexed_files() >= 1_430);
        assert_eq!(game.elements_db.total_records(), 37_676);
        assert_eq!(game.domain_db.zones.len(), 47);
        assert!(!game.server_list.is_empty());
        // Endpoint must be normalized `host:port` on the glinkd port; the exact host depends on
        // `userdata/server/serverlist.txt` vs `userdata/currentserver.ini` (127.0.0.1 in sandbox).
        let addr = &game.server_list[0].addr;
        let (host, port) = addr.rsplit_once(':').expect("host:port endpoint");
        assert!(!host.is_empty());
        assert_eq!(port, "29000");

        let player = CecHostPlayer::new(1024, "Archosaur", 0, 100, Vec3::new(128.0, 22.0, -64.0));
        let casted = player.cast_skill(1, 1).unwrap();
        assert_eq!(casted.stub.id, 1);
        game.enter_world(player);
        assert_eq!(game.run_state, GameRunState::InWorld);

        let loc = summarize_localization(&game);
        assert_eq!(loc.element_talk_trees, 3_341);
        assert!(loc.ai_talk_operations > 0);
        assert_eq!(loc.gshop_named_items, 605);
    }

    #[test]
    fn test_interactive_client_app_login_charselect_3d_world_and_modals() {
        let Some(elem) = pw_core::find_test_pw142_element(env!("CARGO_MANIFEST_DIR")) else {
            return;
        };
        let game = CecGame::init(elem).unwrap();
        let mut app = InteractiveClientApp::new(game);
        let mut fb = pw_render_audio::FrameBuffer::new(1280, 800);

        // 1. Render Login 3D world + UI
        app.tick(0.016, &game_app::InputSnapshot::default());
        app.render(&mut fb, 640, 400);
        assert_eq!(app.screen, ClientScreenState::Login);
        assert!(app.scene_3d.font_atlas.atlas_revision >= 1);

        // 2. Press F5 -> Offline Character Select & render 3D Hero stage
        app.on_key_down(0x74);
        assert_eq!(app.screen, ClientScreenState::CharacterSelect);
        app.render(&mut fb, 640, 400);

        // 3. Enter 3D World, move forward, toggle Flight, cast Skill #1, and render every modal!
        app.enter_world_with_selected_role();
        assert_eq!(app.screen, ClientScreenState::InWorld);
        let mut move_in = game_app::InputSnapshot::default();
        move_in.move_fwd = true;
        app.tick(0.1, &move_in);
        app.on_key_down(0x46); // F -> Fly
        assert!(app.flying_mode);
        app.cast_quickbar_slot(0);
        app.render(&mut fb, 640, 400);

        for vk in [0x42u32, 0x4B, 0x51, 0x4F, 0x4D, 0xC0] {
            app.on_key_down(vk);
            app.render(&mut fb, 640, 400);
            app.on_key_down(0x1B); // Esc closes modal
        }
        fb.rasterize_queued_text_fallback();

        // 4. Full `.pck` end-to-end visual verification (`Maps\Login` -> `Maps\a01` + `ingame.dcf`)
        if let Some(full_elem) = pw_core::find_test_pw142_element(env!("CARGO_MANIFEST_DIR"))
            .filter(|p| p.join("models.pck").is_file())
        {
            let tmp = std::env::temp_dir();
            let full_game = CecGame::init(&full_elem).unwrap();
            assert!(full_game.vfs.package_count() >= 10);
            assert!(full_game.scene_ctrl.cameras.len() >= 25);
            let mut full_app = InteractiveClientApp::new(full_game);
            full_app.render(&mut fb, 640, 400);
            std::fs::write(
                tmp.join("pw_verify_app_login.bmp"),
                pw_render_audio::SurfaceImage::encode_bmp_24(fb.width, fb.height, &fb.pixels),
            )
            .unwrap();

            full_app.enter_offline_character_select();
            full_app.render(&mut fb, 640, 400);
            std::fs::write(
                tmp.join("pw_verify_app_select.bmp"),
                pw_render_audio::SurfaceImage::encode_bmp_24(fb.width, fb.height, &fb.pixels),
            )
            .unwrap();

            full_app.screen = ClientScreenState::CreateCharacter;
            full_app.render(&mut fb, 640, 400);
            std::fs::write(
                tmp.join("pw_verify_app_create.bmp"),
                pw_render_audio::SurfaceImage::encode_bmp_24(fb.width, fb.height, &fb.pixels),
            )
            .unwrap();

            full_app.screen = ClientScreenState::CharacterSelect;
            full_app.enter_world_with_selected_role();
            assert_eq!(full_app.screen, ClientScreenState::InWorld);
            assert!(
                matches!(
                    full_app.game.active_map.map_name.to_ascii_lowercase().as_str(),
                    "world" | "a01"
                ),
                "unexpected active map: {}",
                full_app.game.active_map.map_name
            );
            full_app.render(&mut fb, 640, 400);
            std::fs::write(
                tmp.join("pw_verify_app_inworld.bmp"),
                pw_render_audio::SurfaceImage::encode_bmp_24(fb.width, fb.height, &fb.pixels),
            )
            .unwrap();
        }
    }

    #[test]
    fn test_zero_cjk_english_localization_everywhere() {
        let Some(elem) = pw_core::find_test_pw142_element(env!("CARGO_MANIFEST_DIR")) else {
            return;
        };
        let game = CecGame::init(elem).unwrap();

        // 1. Verify English `configs\skillstr.txt` & `buff_str.txt` loaded all ~1,179 English skills and ZERO CJK
        assert!(game.loc_tables.skills.len() >= 1150);
        assert_eq!(game.english_skill_name(1), "Tiger Maw");
        for (&id, (nm, _)) in &game.loc_tables.skills {
            assert!(
                !pw_data::has_cjk(nm),
                "CJK leaked in skillstr.txt skill #{id}: {nm}"
            );
        }
        for (&id, npc) in &game.npc_essences {
            assert!(!pw_data::has_cjk(&npc.name), "CJK in NPC #{id}: {}", npc.name);
        }
        for (&id, mob) in &game.monster_essences {
            assert!(
                !pw_data::has_cjk(&mob.name),
                "CJK in Monster #{id}: {}",
                mob.name
            );
            assert!(
                !pw_data::has_cjk(&mob.short_desc),
                "CJK in Monster short_desc #{id}: {}",
                mob.short_desc
            );
        }

        // 2. Verify ZERO CJK in any resolved `.dtf` dialog title or control text (`interfaces.pck`)
        for (dname, dlg) in &game.aui_manager.dialogs {
            assert!(
                !pw_data::has_cjk(&dlg.resolved_title),
                "CJK in dialog title {dname}: {}",
                dlg.resolved_title
            );
            for ctrl in &dlg.controls {
                assert!(
                    !pw_data::has_cjk(&ctrl.resolved_text),
                    "CJK in {dname}::{}: {}",
                    ctrl.name,
                    ctrl.resolved_text
                );
                assert!(
                    !pw_data::has_cjk(&ctrl.resolved_hint),
                    "CJK in hint {dname}::{}: {}",
                    ctrl.name,
                    ctrl.resolved_hint
                );
            }
        }

        // 3. Verify runtime chat log, cast floaters, and quickbar skill tooltips contain ZERO CJK
        let mut app = InteractiveClientApp::new(game);
        app.enter_offline_character_select();
        app.enter_world_with_selected_role();
        app.cast_quickbar_slot(0);
        for (_, msg) in &app.chat_log {
            assert!(!pw_data::has_cjk(msg), "CJK in chat_log: {msg}");
        }
        for ef in &app.active_effects {
            assert!(
                !pw_data::has_cjk(&ef.skill_name),
                "CJK in active_effect: {}",
                ef.skill_name
            );
        }
        for ((dlg, ctrl), txt) in &app.ingame_ui.text_overrides {
            assert!(
                !pw_data::has_cjk(txt),
                "CJK in text_override {dlg}::{ctrl}: {txt}"
            );
        }
        for ((dlg, ctrl), hnt) in &app.ingame_ui.hint_overrides {
            assert!(
                !pw_data::has_cjk(hnt),
                "CJK in hint_override {dlg}::{ctrl}: {hnt}"
            );
        }

        // 4. Verify all 166 Angelica 2.2 shaders (`ps/facerender/*`, `water_expensive`, `t2_lm_*`, `skin_mesh_m4_s`)
        assert_eq!(app.game.shader_catalog.total_files, 166);
        assert!(app.game.shader_catalog.pixel_shader_count >= 50);
        assert!(app.game.shader_catalog.vertex_shader_count >= 20);
        for req in [
            "shaders/ps/facerender/facerender.txt",
            "shaders/ps/facerender/browrender.txt",
            "shaders/ps/facerender/eyerender.txt",
            "shaders/ps/facerender/mouthrender.txt",
            "shaders/ps/facerender/noserender.txt",
            "shaders/ps/facerender/eyeballrender.txt",
            "shaders/ps/facerender/furrender.txt",
            "shaders/ps/facerender/hairrender.txt",
            "shaders/ps/water_expensive.txt",
            "shaders/ps/t2_lm_f1lay_caustic.txt",
            "shaders/vs/skin_mesh_m4_s.txt",
        ] {
            assert!(
                app.game.vfs.read_file(req).is_ok(),
                "missing required Angelica shader {req}"
            );
        }

        // 5. Verify Target Frame Dispatch (`Win_HpOther` for Monsters vs `Win_HpmpOther` for NPCs)
        let empty_in = crate::game_app::InputSnapshot::default();
        let npc_id = app
            .world_entities
            .iter()
            .find(|e| e.kind == pw_render_audio::EntityVisualKind::Npc)
            .map(|e| e.id)
            .expect("expected spawned NPC");
        app.selected_entity_id = Some(npc_id);
        for e in &mut app.world_entities {
            e.selected = e.id == npc_id;
        }
        app.tick(0.016, &empty_in);
        app.sync_aui_state();
        assert!(
            app.ingame_ui.is_dialog_visible("Win_HpmpOther"),
            "NPC must show Win_HpmpOther"
        );
        assert!(
            !app.ingame_ui.is_dialog_visible("Win_HpOther"),
            "NPC must hide Win_HpOther"
        );

        let mob_id = app
            .world_entities
            .iter()
            .find(|e| e.kind == pw_render_audio::EntityVisualKind::Monster)
            .map(|e| e.id)
            .expect("expected spawned Monster");
        app.selected_entity_id = Some(mob_id);
        for e in &mut app.world_entities {
            e.selected = e.id == mob_id;
        }
        app.tick(0.016, &empty_in);
        app.sync_aui_state();
        assert!(
            app.ingame_ui.is_dialog_visible("Win_HpOther"),
            "Monster must show Win_HpOther"
        );
        assert!(
            !app.ingame_ui.is_dialog_visible("Win_HpmpOther"),
            "Monster must hide Win_HpmpOther"
        );
        let att_txt = app
            .ingame_ui
            .text_overrides
            .get(&("Win_HpOther".to_string(), "Txt_Att".to_string()))
            .cloned()
            .unwrap_or_default();
        assert!(
            att_txt.contains("Lv."),
            "Win_HpOther::Txt_Att must display English level/element: {att_txt}"
        );
        assert!(!pw_data::has_cjk(&att_txt));

        // 6. Verify all 6 new social/economy/territory modals (`GuildManage`, `TerritoryMap`, `PetBag`, `MailBox`, `AuctionHouse`, `PlayerTrade`) & `.gfx` bursts
        app.cast_quickbar_slot(0);
        app.tick(0.032, &empty_in);
        assert!(app.scene_3d.gfx_manager.particle_count() > 0);
        for modal in [
            crate::game_app::InWorldModal::GuildManage,
            crate::game_app::InWorldModal::TerritoryMap,
            crate::game_app::InWorldModal::PetBag,
            crate::game_app::InWorldModal::MailBox,
            crate::game_app::InWorldModal::AuctionHouse,
            crate::game_app::InWorldModal::PlayerTrade,
        ] {
            app.modal = modal;
            let pf = app.prepare_frame(1280, 800, 640, 400);
            for t in &pf.ui_texts {
                assert!(!pw_data::has_cjk(&t.text), "CJK leak in {modal:?}: {}", t.text);
            }
        }
    }

    #[test]
    fn test_all_167_buff_states_and_1175_skill_level_eval_zero_cjk() {
        let loc = pw_data::EnglishLocalizationTables::default();
        for ts in pw_skill::TEAM_STATES {
            if let Some((nm, desc)) = loc.buffs.get(&ts.id) {
                assert!(!pw_data::has_cjk(nm));
                assert!(!pw_data::has_cjk(desc));
            }
            assert!(
                ts.id == 0 || ts.icon.ends_with(".dds"),
                "TeamState #{} icon '{}' must be .dds",
                ts.id,
                ts.icon
            );
        }
        for stub in pw_skill::SKILL_STUBS {
            let sk = ElementSkill::create(stub.id, stub.max_level).unwrap();
            let p = sk.evaluate_level_params();
            let tip = loc.format_skill_tooltip_with_eval(
                stub.id,
                p.level as u32,
                p.range_m,
                p.mp_cost,
                p.channel_s,
                p.cast_s,
                p.cooldown_s,
                p.weapon_damage_pct,
                p.flat_bonus_damage,
            );
            assert!(!pw_data::has_cjk(&tip), "CJK leak in skill #{}: {tip}", stub.id);
        }
    }

    #[test]
    fn test_standalone_client_morphing_particles_and_all_modals() {
        // 1. Always verify `A3dGfxManager` (`VisibleState` `1..=69` `.gfx` auras + bursts + weapon motes)
        //    and `SpatialAudioMixer` 3D panning + all 14 real `character00..71.ini` morph presets:
        let mut gfx = pw_render_audio::A3dGfxManager::default();
        let origin = pw_core::Vec3::new(100.0, 22.0, -50.0);
        for vs in [1u32, 12, 35, 69] {
            gfx.sync_visible_state_aura(vs, origin);
        }
        gfx.spawn_burst(origin, 0xFFFF_AA33, 0x00FF_3300, 24, 3.5, 0.35);
        gfx.emit_weapon_glow_motes(origin, 0xFF88_E0FF, 0.1);
        gfx.tick(0.05);
        assert!(gfx.particle_count() >= 24);

        let mut mixer = pw_render_audio::SpatialAudioMixer::default();
        mixer.listener_pos = origin;
        mixer.listener_right = pw_core::Vec3::new(1.0, 0.0, 0.0);
        let (left_g, right_g) = mixer.compute_stereo_gains(
            pw_core::Vec3::new(108.0, 22.0, -50.0),
            2.0,
            40.0,
        );
        assert!(right_g > left_g && right_g > 0.0, "emitter to listener right must pan right");
        let bgm = mixer.tick_bgm_playlist(
            "Archosaur",
            &["music\\city_archosaur.ogg".to_string()],
            1.0,
            180.0,
        );
        assert_eq!(bgm.as_deref(), Some("music\\city_archosaur.ogg"));

        // 2. When full PW 1.4.2 `.pck`/`.data` archives are mounted, run full `InteractiveClientApp` morph + modal suite:
        let Some(elem_root) = pw_core::find_test_pw142_element(env!("CARGO_MANIFEST_DIR")) else {
            return;
        };
        let game = CecGame::init(&elem_root).expect("CecGame init");
        let mut app = InteractiveClientApp::new(game);
        let empty_in = crate::game_app::InputSnapshot::default();
        let mut fb = pw_render_audio::FrameBuffer::new(320, 200);

        app.screen = ClientScreenState::CreateCharacter;
        let base_ini = app.scene_3d.get_custom_appearance(
            app.create_occupation as i32,
            app.create_gender,
            app.create_appearance_preset,
        );
        app.on_key_down(0x26); // VK_UP morphs `head_scale` & `scale_face_h`
        app.on_key_down(0xDD); // `]` morphs `up_scale`, `waist_scale`, `arm_width`, `leg_width`
        let morphed_ini = app.scene_3d.get_custom_appearance(
            app.create_occupation as i32,
            app.create_gender,
            app.create_appearance_preset,
        );
        assert!(morphed_ini.head_scale > base_ini.head_scale);
        assert!(morphed_ini.up_scale > base_ini.up_scale);
        app.render(&mut fb, 160, 100);

        app.enter_world_with_selected_role();
        app.cast_quickbar_slot(0);
        app.tick(0.05, &empty_in);
        assert!(app.scene_3d.gfx_manager.particle_count() > 0);
        app.render(&mut fb, 160, 100);

        for hk in [
            b'H' as u32,
            b'T' as u32,
            b'P' as u32,
            b'L' as u32,
            b'J' as u32,
            b'X' as u32,
            b'V' as u32,
            b'N' as u32,
            b'I' as u32,
            0x74,
            0x75,
            0x76,
            0x77,
        ] {
            app.on_key_down(hk);
            let mpf = app.prepare_frame(800, 600, 400, 300);
            for t in &mpf.ui_texts {
                assert!(!pw_data::has_cjk(&t.text), "CJK leak on hotkey {hk}: {}", t.text);
            }
            app.render(&mut fb, 160, 100);
            app.on_key_down(0x1B);
        }
    }

    #[test]
    fn test_hundred_percent_parity_presets_clockicon_and_audio_suite() {
        let ref_pw142 = std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../../source/pw142");
        // 1. Official 237-file `CustomizePresetCatalog` (`userdata/character/{customize,customize1}`)
        let ref_elem = ref_pw142.join("element");
        if ref_elem.is_dir() {
            let cat = pw_data::CustomizePresetCatalog::load_from_element_dir(&ref_elem);
            assert!(cat.total_presets() >= 180);
            for presets in cat.by_class_gender.values() {
                for (pname, ini) in presets {
                    assert!(!pw_data::has_cjk(pname));
                    assert!(ini.head_scale >= 1);
                }
            }
        }

        // 2. `AUIClockIcon` radial sweep + `parse_aui_rich_text`
        assert!(pw_aui::aui_clock_icon_contains_uv(0.25, 0.25, 0.50));
        assert!(!pw_aui::aui_clock_icon_contains_uv(0.75, 0.25, 0.50));
        let spans =
            pw_aui::parse_aui_rich_text("^FF8000Dragon^FFFFFF &item:1234:Celestone&", 0xFFFF_FFFF);
        assert!(spans.len() >= 2);

        // 3. Real `patcher/skin/sounds/click.wav` auto-decode + spatial RIFF WAV synthesis
        let wav_path = ref_pw142.join("patcher/skin/sounds/click.wav");
        if wav_path.is_file() {
            let raw = std::fs::read(wav_path).unwrap();
            let clip = pw_render_audio::decode_audio_auto(&raw).expect("click.wav decode");
            assert!(!clip.samples_i16.is_empty());
            let stereo_wav = pw_render_audio::encode_pcm16_to_riff_wav(&clip, 0.85, 0.40);
            assert_eq!(&stereo_wav[0..4], b"RIFF");
        }
    }
}

