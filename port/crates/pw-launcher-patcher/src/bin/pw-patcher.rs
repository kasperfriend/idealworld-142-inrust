use std::env;
use std::fs;
use std::path::Path;
use std::process::{self, Command};

use pw_core::{find_path_case_insensitive, is_cli_flag_token, resolve_pw142_root};
use pw_launcher_patcher::{
    packdll_read_pck_version, parse_patcher_skin_xml, parse_resolution_list, parse_stringtab,
    PackDllMutablePck, PatchIncOp, PatcherIncManifest, PatcherUpdateConfig, PatcherVideoConfig,
    PACKDLL_CANONICAL_PACK_STEMS, PATCHER_RTTI_CLASSES,
};
use pw_pck::PckArchive;

fn main() {
    let args: Vec<String> = env::args().skip(1).collect();
    let mut explicit_root: Option<String> = None;
    let mut apply_inc: Option<(String, String)> = None;
    let mut extract_req: Option<(String, String, String)> = None;
    let mut launch_play = false;

    let mut i = 0usize;
    while i < args.len() {
        let a = &args[i];
        let low = a.to_ascii_lowercase();
        if low == "--play" {
            launch_play = true;
        } else if low == "--apply-inc" && i + 2 < args.len() {
            apply_inc = Some((args[i + 1].clone(), args[i + 2].clone()));
            i += 2;
        } else if low == "--extract" && i + 3 < args.len() {
            extract_req = Some((args[i + 1].clone(), args[i + 2].clone(), args[i + 3].clone()));
            i += 3;
        } else if !is_cli_flag_token(a) && explicit_root.is_none() {
            explicit_root = Some(a.clone());
        }
        i += 1;
    }

    if let Some((pck_file, vfs_entry, out_file)) = extract_req {
        let pkg = PckArchive::open_path(&pck_file).unwrap_or_else(|e| {
            eprintln!("Failed to open PCK '{pck_file}': {e}");
            process::exit(1);
        });
        let data = pkg.read_by_path(&vfs_entry).unwrap_or_else(|e| {
            eprintln!("Entry '{vfs_entry}' not found in '{pck_file}': {e}");
            process::exit(1);
        });
        if let Some(parent) = Path::new(&out_file).parent() {
            let _ = fs::create_dir_all(parent);
        }
        fs::write(&out_file, &data).unwrap_or_else(|e| {
            eprintln!("Failed to write '{out_file}': {e}");
            process::exit(1);
        });
        println!("Extracted '{}' ({} bytes) -> {}", vfs_entry, data.len(), out_file);
        return;
    }

    let root = match resolve_pw142_root(explicit_root.as_deref()) {
        Ok(p) => p,
        Err(e) => {
            eprintln!("Error: {e}");
            process::exit(1);
        }
    };

    println!(
        "Perfect World 1.4.2 Patcher & PackDLL Engine (1:1 Rust Port — {} RTTI classes)",
        PATCHER_RTTI_CLASSES.len()
    );
    println!("  PW142 Root: {}", root.display());

    if let Some(skin_p) = find_path_case_insensitive(&root, "patcher/skin/mainuni.xml") {
        if let Ok(raw) = fs::read(&skin_p) {
            let skin = parse_patcher_skin_xml(&raw);
            println!(
                "  Skin XML:   {} windows, {} styles, {} options",
                skin.windows.len(),
                skin.styles.len(),
                skin.options.len()
            );
        }
    }
    if let Some(st_p) = find_path_case_insensitive(&root, "patcher/stringtab.txt") {
        if let Ok(raw) = fs::read(&st_p) {
            let tab = parse_stringtab(&raw);
            println!("  StringTab:  {} localized entries", tab.len());
        }
    }
    if let Some(up_p) = find_path_case_insensitive(&root, "config/patcher/update.cfg") {
        if let Ok(raw) = fs::read(&up_p) {
            let cfg = PatcherUpdateConfig::parse_bytes(&raw);
            println!(
                "  UpdateCfg:  Server='{}' AutoUpdating={} AutoContinue={}",
                cfg.update_server_select, cfg.auto_updating, cfg.auto_continue
            );
        }
    }
    if let Some(vid_p) = find_path_case_insensitive(&root, "config/patcher/video.cfg") {
        if let Ok(raw) = fs::read(&vid_p) {
            let vcfg = PatcherVideoConfig::parse_bytes(&raw);
            println!(
                "  VideoCfg:   Res='{}' FullScreen={} Water={} Cloud={} Sight={}",
                vcfg.resolution_select,
                vcfg.full_screen_select,
                vcfg.water_select,
                vcfg.cloud_select,
                vcfg.sight_select
            );
        }
    }
    if let Some(res_p) = find_path_case_insensitive(&root, "config/patcher/resolution.txt") {
        if let Ok(raw) = fs::read(&res_p) {
            let res = parse_resolution_list(&raw);
            println!("  Resolutions: {} presets", res.len());
        }
    }

    let mut found_pcks = 0usize;
    for &stem in PACKDLL_CANONICAL_PACK_STEMS {
        let p = root.join(format!("element/{stem}.pck"));
        if let Ok(pkg) = PckArchive::open_path(&p) {
            found_pcks += 1;
            println!(
                "  [{found_pcks:02}] {stem}.pck: v{:#x}, {:>5} files, pack_ver={:?}",
                pkg.header.version,
                pkg.len(),
                packdll_read_pck_version(&pkg, stem)
            );
        }
    }

    if let Some((inc_path, patch_dir)) = apply_inc {
        let inc_text = fs::read_to_string(&inc_path).unwrap_or_else(|e| {
            eprintln!("Failed to read inc manifest '{inc_path}': {e}");
            process::exit(1);
        });
        let manifest = PatcherIncManifest::parse_text(&inc_text);
        println!(
            "  Applying patch manifest v{} -> v{} ({} operations)...",
            manifest.version_from,
            manifest.version_to,
            manifest.ops.len()
        );
        let mut sessions: std::collections::BTreeMap<String, PackDllMutablePck> =
            std::collections::BTreeMap::new();
        for op in &manifest.ops {
            let rel = match op {
                PatchIncOp::AddOrReplace { rel_path, .. } => rel_path.as_str(),
                PatchIncOp::Delete { rel_path } => rel_path.as_str(),
            };
            let norm = rel.replace('/', "\\");
            let Some((first_dir, _)) = norm.split_once('\\') else {
                continue;
            };
            let stem_lc = first_dir.to_ascii_lowercase();
            if !PACKDLL_CANONICAL_PACK_STEMS
                .iter()
                .any(|s| s.eq_ignore_ascii_case(&stem_lc))
            {
                continue;
            }
            if !sessions.contains_key(&stem_lc) {
                let pck_path = root.join(format!("element/{stem_lc}.pck"));
                let sess = if let Ok(pkg) = PckArchive::open_path(&pck_path) {
                    PackDllMutablePck::from_archive(&stem_lc, &pkg).unwrap()
                } else {
                    PackDllMutablePck::new(&stem_lc)
                };
                sessions.insert(stem_lc.clone(), sess);
            }
            let sess = sessions.get_mut(&stem_lc).unwrap();
            match op {
                PatchIncOp::Delete { rel_path } => {
                    sess.remove_file(rel_path);
                }
                PatchIncOp::AddOrReplace { rel_path, .. } => {
                    let x_cand = Path::new(&patch_dir).join(format!("{}.x", rel_path.replace('\\', "/")));
                    let raw_cand = Path::new(&patch_dir).join(rel_path.replace('\\', "/"));
                    if let Ok(xb) = fs::read(&x_cand) {
                        sess.apply_x_patch_file(rel_path, &xb).unwrap();
                    } else if let Ok(rb) = fs::read(&raw_cand) {
                        sess.add_or_replace_file(rel_path, rb);
                    }
                }
            }
        }
        for (stem, mut sess) in sessions {
            if manifest.version_to > 0 {
                sess.fill_pack_version(manifest.version_to);
            }
            let out_bytes = sess.to_pck_bytes().unwrap();
            let out_path = root.join(format!("element/{stem}.pck"));
            fs::write(&out_path, out_bytes).unwrap();
            println!("  Updated {} -> v{}", out_path.display(), manifest.version_to);
        }
    }

    if launch_play {
        let elem_dir = find_path_case_insensitive(&root, "element").unwrap_or_else(|| root.join("element"));
        let bin_name = if cfg!(windows) { "pw-elementclient.exe" } else { "pw-elementclient" };
        let sibling = env::current_exe()
            .ok()
            .and_then(|p| p.parent().map(|d| d.join(bin_name)));
        let chosen = sibling
            .filter(|p| p.is_file())
            .unwrap_or_else(|| elem_dir.join(bin_name));
        if chosen.is_file() {
            println!("  Spawning {} startbypatcher nocheck game:cpw console:1 ...", chosen.display());
            let _ = Command::new(&chosen)
                .current_dir(&elem_dir)
                .args(["startbypatcher", "nocheck", "game:cpw", "console:1"])
                .spawn();
        } else {
            eprintln!("  Client binary not found at {}", chosen.display());
        }
    }
}
