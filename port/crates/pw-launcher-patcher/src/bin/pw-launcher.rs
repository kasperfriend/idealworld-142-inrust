use std::env;
use std::fs;
use std::process::{self, Command};

use pw_core::{find_path_case_insensitive, is_cli_flag_token, resolve_pw142_root};
use pw_launcher_patcher::{load_launcher_ini, parse_server_list, parse_stringtab, probe_sysinfo};

fn main() {
    let args: Vec<String> = env::args().skip(1).collect();
    let launch_play = args.iter().any(|a| a.eq_ignore_ascii_case("--play"));
    let launch_patcher = args.iter().any(|a| a.eq_ignore_ascii_case("--patcher"));
    let explicit = args.iter().find(|a| !is_cli_flag_token(a)).map(String::as_str);

    let root = match resolve_pw142_root(explicit) {
        Ok(p) => p,
        Err(e) => {
            eprintln!("Error: {e}");
            process::exit(1);
        }
    };
    let ini = load_launcher_ini(&root).unwrap_or_default();
    let hw = probe_sysinfo();
    let servers = find_path_case_insensitive(&root, "element/userdata/server/serverlist.txt")
        .and_then(|p| fs::read(p).ok())
        .map(|b| parse_server_list(&b))
        .unwrap_or_default();
    let strtab_cnt = find_path_case_insensitive(&root, "launcher/stringtab.txt")
        .and_then(|p| fs::read(p).ok())
        .map(|b| parse_stringtab(&b).len())
        .unwrap_or(0);

    println!("Perfect World 1.4.2 Launcher (1:1 Rust Port)");
    println!("  PW142 Root: {}", root.display());
    println!(
        "  Hardware:   {} logical CPUs, {} MiB RAM -> preset '{}'",
        hw.logical_cpus, hw.total_ram_mb, hw.recommended_preset_ini
    );
    println!(
        "  Launcher INI sections: {} | StringTab entries: {}",
        ini.sections.len(),
        strtab_cnt
    );
    println!("  Configured Game Servers: {}", servers.len());
    for s in servers.iter().take(5) {
        println!("    [{}] {} -> {}", s.group, s.name, s.address);
    }

    let exe_dir = env::current_exe().ok().and_then(|p| p.parent().map(|d| d.to_path_buf()));
    if launch_patcher {
        let bin_name = if cfg!(windows) { "pw-patcher.exe" } else { "pw-patcher" };
        let chosen = exe_dir
            .as_ref()
            .map(|d| d.join(bin_name))
            .filter(|p| p.is_file())
            .unwrap_or_else(|| root.join("patcher").join(bin_name));
        if chosen.is_file() {
            println!("  Spawning {} {} ...", chosen.display(), root.display());
            let _ = Command::new(&chosen).arg(&root).spawn();
        } else {
            eprintln!("  Patcher binary not found at {}", chosen.display());
        }
    } else if launch_play {
        let elem_dir = find_path_case_insensitive(&root, "element").unwrap_or_else(|| root.join("element"));
        let bin_name = if cfg!(windows) { "pw-elementclient.exe" } else { "pw-elementclient" };
        let chosen = exe_dir
            .as_ref()
            .map(|d| d.join(bin_name))
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
