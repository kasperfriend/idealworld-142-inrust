use std::env;
use std::fs;
use std::process;

use pw_client::{summarize_localization, CecGame};
use pw_core::{is_cli_flag_token, resolve_element_root};

fn main() {
    let args: Vec<String> = env::args().skip(1).collect();
    let mut explicit_root: Option<String> = None;
    let mut verify_english = false;
    let mut export_tsv: Option<String> = None;

    let mut i = 0usize;
    while i < args.len() {
        let a = &args[i];
        let low = a.to_ascii_lowercase();
        if low == "--verify-english" {
            verify_english = true;
        } else if low == "--export-tsv" && i + 1 < args.len() {
            export_tsv = Some(args[i + 1].clone());
            i += 1;
        } else if !is_cli_flag_token(a) && explicit_root.is_none() {
            explicit_root = Some(a.clone());
        }
        i += 1;
    }

    let root = match resolve_element_root(explicit_root.as_deref()) {
        Ok(p) => p,
        Err(e) => {
            eprintln!("Error: {e}");
            process::exit(1);
        }
    };
    let game = match CecGame::init(&root) {
        Ok(g) => g,
        Err(e) => {
            eprintln!("Failed to load element data from '{}': {e}", root.display());
            process::exit(1);
        }
    };
    let summary = summarize_localization(&game);
    println!("Perfect World 1.4.2 Localization Tool (elementlocalize 1:1 port)");
    println!("  Element Root:                        {}", game.element_root.display());
    println!("  NPC Talk Trees (elements.data [59]): {}", summary.element_talk_trees);
    println!("  Quest Nodes (tasks + dyn_tasks):     {}", summary.quest_nodes_scanned);
    println!("  AI Talk Operations (aipolicy.data):  {}", summary.ai_talk_operations);
    println!("  Boutique Items (gshop.data):         {}", summary.gshop_named_items);
    println!("  Localized Skills (skillstr.txt):     {}", game.loc_tables.skills.len());
    println!("  Localized Buffs  (buff_str.txt):     {}", game.loc_tables.buffs.len());
    println!("  Fixed UI Strings (fixed_msg.txt):    {}", game.loc_tables.fixed_msgs.len());

    if verify_english {
        let mut cjk_leaks = 0usize;
        for (&id, (nm, desc)) in &game.loc_tables.skills {
            if pw_data::has_cjk(nm) || pw_data::has_cjk(desc) {
                eprintln!("  [CJK] skill #{id}: {nm}");
                cjk_leaks += 1;
            }
        }
        for dlg in game.aui_manager.dialogs.values() {
            for ctrl in &dlg.controls {
                if pw_data::has_cjk(&ctrl.resolved_text) || pw_data::has_cjk(&ctrl.resolved_hint) {
                    cjk_leaks += 1;
                }
            }
        }
        println!("  Pure-English CJK Audit:              {cjk_leaks} CJK leaks");
        if cjk_leaks > 0 {
            process::exit(2);
        }
    }

    if let Some(tsv_path) = export_tsv {
        let mut out = String::from("table\tid\tname\tdescription\n");
        let mut skill_ids: Vec<u32> = game.loc_tables.skills.keys().copied().collect();
        skill_ids.sort_unstable();
        for id in skill_ids {
            if let Some((nm, desc)) = game.loc_tables.skills.get(&id) {
                let clean_desc = desc.replace(['\r', '\n', '\t'], " ");
                out.push_str(&format!("skillstr\t{id}\t{nm}\t{clean_desc}\n"));
            }
        }
        let mut buff_ids: Vec<u32> = game.loc_tables.buffs.keys().copied().collect();
        buff_ids.sort_unstable();
        for id in buff_ids {
            if let Some((nm, desc)) = game.loc_tables.buffs.get(&id) {
                let clean_desc = desc.replace(['\r', '\n', '\t'], " ");
                out.push_str(&format!("buff_str\t{id}\t{nm}\t{clean_desc}\n"));
            }
        }
        for (idx, txt) in game.loc_tables.fixed_msgs.iter().enumerate() {
            let clean_txt = txt.replace(['\r', '\n', '\t'], " ");
            out.push_str(&format!("fixed_msg\t{idx}\t\t{clean_txt}\n"));
        }
        fs::write(&tsv_path, out).unwrap_or_else(|e| {
            eprintln!("Failed to write '{tsv_path}': {e}");
            process::exit(1);
        });
        println!("  Exported UTF-8 localization TSV -> {tsv_path}");
    }
}
