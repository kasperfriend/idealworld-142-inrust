use std::env;
use std::process;

use pw_client::win32_gui::run_win32_client;
use pw_client::{CecGame, InteractiveClientApp, ELEMENTCLIENT_RTTI_CLASSES};
use pw_core::{is_cli_flag_token, resolve_element_root};

fn main() {
    let args: Vec<String> = env::args().skip(1).collect();
    let mut headless = false;
    let mut start_offline = false;
    let mut console_enabled = false;
    let mut screenshot_dir: Option<String> = None;
    let mut explicit_path: Option<String> = None;
    let mut connect_addr: Option<String> = None;
    let mut cli_user: Option<String> = None;
    let mut cli_pass: Option<String> = None;
    let mut cli_role: Option<String> = None;

    let mut idx = 0usize;
    while idx < args.len() {
        let a = &args[idx];
        let low = a.to_ascii_lowercase();
        if low == "--check" || low == "--headless" {
            headless = true;
        } else if low == "--offline" {
            start_offline = true;
        } else if low == "--screenshots" {
            if idx + 1 < args.len() {
                screenshot_dir = Some(args[idx + 1].clone());
                idx += 1;
            }
        } else if low == "--connect" || low == "--server" {
            if idx + 1 < args.len() {
                connect_addr = Some(args[idx + 1].clone());
                idx += 1;
            }
        } else if low == "--user" || low == "--account" {
            if idx + 1 < args.len() {
                cli_user = Some(args[idx + 1].clone());
                idx += 1;
            }
        } else if low == "--pass" || low == "--password" {
            if idx + 1 < args.len() {
                cli_pass = Some(args[idx + 1].clone());
                idx += 1;
            }
        } else if low == "--role" {
            if idx + 1 < args.len() {
                cli_role = Some(args[idx + 1].clone());
                idx += 1;
            }
        } else if let Some(v) = a.strip_prefix("server:").or_else(|| a.strip_prefix("SERVER:")) {
            connect_addr = Some(v.to_string());
        } else if let Some(v) = a.strip_prefix("user:").or_else(|| a.strip_prefix("USER:")) {
            cli_user = Some(v.to_string());
        } else if let Some(v) = a.strip_prefix("pwd:").or_else(|| a.strip_prefix("PWD:")) {
            cli_pass = Some(v.to_string());
        } else if let Some(v) = a.strip_prefix("role:").or_else(|| a.strip_prefix("ROLE:")) {
            cli_role = Some(v.to_string());
        } else if low == "console:1" || low == "--console" {
            console_enabled = true;
        } else if !is_cli_flag_token(a) && explicit_path.is_none() {
            explicit_path = Some(a.clone());
        }
        idx += 1;
    }

    let root = match resolve_element_root(explicit_path.as_deref()) {
        Ok(p) => p,
        Err(e) => {
            eprintln!("Error: {e}");
            process::exit(1);
        }
    };

    let game = match CecGame::init(&root) {
        Ok(g) => g,
        Err(e) => {
            eprintln!("CECGame::Init failed (root = '{}'): {e}", root.display());
            process::exit(1);
        }
    };

    let default_srv = game
        .server_list
        .first()
        .map(|s| format!("{} ({})", s.name, s.addr))
        .unwrap_or_else(|| "127.0.0.1:29000".into());

    println!(
        "Perfect World 1.4.2 Rust Client (Build {}, Skill ABI v{}) initialized!",
        game.build_version, game.skill_abi_version
    );
    println!("  Element Root: {}", game.element_root.display());
    println!(
        "  VFS Packages: {} ({} indexed files)",
        game.vfs.package_count(),
        game.vfs.total_indexed_files()
    );
    println!(
        "  elements.data: v{} ({} sections, {} records)",
        game.elements_db.version_low_u16,
        game.elements_db.sections.len(),
        game.elements_db.total_records()
    );
    println!(
        "  tasks: v{} ({} top-level, {} total nodes) + {} dyn_tasks + {} task_npcs",
        game.tasks_db.version,
        game.tasks_db.top_tasks.len(),
        game.tasks_db.total_nodes,
        game.dyn_tasks_db.tasks.len(),
        game.task_npc_db.entries.len()
    );
    println!(
        "  gshop: {} items | domain: {} territories | aipolicy: {} policies",
        game.gshop_db.items.len(),
        game.domain_db.zones.len(),
        game.aipolicy_db.policies.len()
    );
    println!(
        "  UI Dialogs: {} DTFs | Shaders: {} | Fonts: {} | Map '{}': {}x{}m ({}x{} mesh) | Server: {} | RTTI: {}",
        game.aui_manager.dialogs.len(),
        game.shader_catalog.total_files,
        game.fonts.len(),
        game.active_map.map_name,
        game.active_map.world.world_width,
        game.active_map.world.world_length,
        game.active_map.height_mesh.verts_per_side,
        game.active_map.height_mesh.verts_per_side,
        default_srv,
        ELEMENTCLIENT_RTTI_CLASSES.len()
    );

    if let Some(sdir) = screenshot_dir {
        let out_dir = std::path::Path::new(&sdir);
        let _ = std::fs::create_dir_all(out_dir);
        let mut app = InteractiveClientApp::new(game);
        let mut fb = pw_render_audio::FrameBuffer::new(1280, 800);
        let idle_in = pw_client::game_app::InputSnapshot::default();

        // 01: Login (`Maps\Login` + SpeedTree foliage + `SceneBoxArea` sky/fog + TrueType `loginui.dcf`)
        app.tick(0.05, &idle_in);
        app.render(&mut fb, 640, 400);
        std::fs::write(out_dir.join("01_login_3d_aui.bmp"), fb.encode_bmp()).unwrap();

        // 02: Character Select (Skeletal `.bon`/`.stck` idle pose + `HH_righthandweapon` weapon)
        app.enter_offline_character_select();
        app.tick(0.45, &idle_in);
        app.render(&mut fb, 640, 400);
        std::fs::write(out_dir.join("02_character_select_3d_aui.bmp"), fb.encode_bmp()).unwrap();

        // 03: Character Create + Live Face/Hair/Armor Customization (`Btn_FaceCustomize`)
        app.screen = pw_client::game_app::ClientScreenState::CreateCharacter;
        app.create_occupation = 6; // Winged Elf Archer
        app.create_gender = 1;
        app.create_appearance_preset = 1;
        app.tick(0.35, &idle_in);
        app.render(&mut fb, 640, 400);
        std::fs::write(out_dir.join("03_character_create_custom_3d_aui.bmp"), fb.encode_bmp()).unwrap();

        // 04: In-World `"a01"` (`"鬼城"`) Open World + Real `.ecm` NPCs & Monsters + Floating Nameplates + Minimap + Skill Icons
        app.screen = pw_client::game_app::ClientScreenState::CharacterSelect;
        app.selected_role_idx = 0;
        app.enter_world_with_selected_role();
        app.tick(0.55, &idle_in);
        app.render(&mut fb, 640, 400);
        std::fs::write(out_dir.join("04_inworld_a01_3d_aui.bmp"), fb.encode_bmp()).unwrap();

        // 05: Active Combat + `Win_HpmpOther` Target Frame + Attack Animation + Skill Floater + Cooldown
        app.cast_quickbar_slot(0);
        app.tick(0.22, &idle_in);
        app.render(&mut fb, 640, 400);
        std::fs::write(out_dir.join("05_inworld_combat_target_3d_aui.bmp"), fb.encode_bmp()).unwrap();

        // 06: Inventory (`Win_InventoryM` + `Win_Bag` with `32x32` `iconlist_ivtrm.dds` icons)
        app.modal = pw_client::game_app::InWorldModal::Inventory;
        app.tick(0.15, &idle_in);
        app.render(&mut fb, 640, 400);
        std::fs::write(out_dir.join("06_inworld_inventory_icons_aui.bmp"), fb.encode_bmp()).unwrap();

        // 07: SkillBook (`Win_ELFSkill` with `iconlist_skill.dds`) & Character Sheet (`Win_Character`)
        app.modal = pw_client::game_app::InWorldModal::SkillBook;
        app.tick(0.15, &idle_in);
        app.render(&mut fb, 640, 400);
        std::fs::write(out_dir.join("07_inworld_skillbook_icons_aui.bmp"), fb.encode_bmp()).unwrap();

        app.modal = pw_client::game_app::InWorldModal::CharacterSheet;
        app.tick(0.15, &idle_in);
        app.render(&mut fb, 640, 400);
        std::fs::write(out_dir.join("08_inworld_character_sheet_aui.bmp"), fb.encode_bmp()).unwrap();

        // 09..14: Midlands (`maps/world`, `8192m x 11264m` Main Continent) Multi-Tile Tour!
        if app.game.active_map.map_name.eq_ignore_ascii_case("world") {
            app.modal = pw_client::game_app::InWorldModal::None;
            app.flying_mode = false;
            app.cam_dist = 9.5;
            app.cam_pitch = 0.22;
            app.player_yaw = 2.18;
            app.cam_yaw = 2.18;
            app.teleport_to_world_pos(1292.0, 1132.0, Some("Archosaur West Plaza"));
            app.tick(0.35, &idle_in);
            app.render(&mut fb, 640, 400);
            std::fs::write(out_dir.join("09_midlands_archosaur_west_3d.bmp"), fb.encode_bmp()).unwrap();

            // 10: 3D Racial Aerogear Flight high above Archosaur Central Avenue (`world_38`)
            app.selected_role_idx = 1; // SylphWing (Winged Elf Archer -> `六翼天鹅之翅` 3D wings!)
            app.enter_world_with_selected_role();
            app.teleport_to_world_pos(1316.0, 1008.0, Some("Archosaur Central Cross-Bridge"));
            app.flying_mode = true;
            if let Some(hp) = &mut app.game.host_player {
                hp.position.y += 28.0;
            }
            app.cam_dist = 11.0;
            app.cam_pitch = 0.28;
            app.player_yaw = 0.08;
            app.cam_yaw = 0.08;
            app.tick(0.35, &idle_in);
            app.render(&mut fb, 640, 400);
            std::fs::write(
                out_dir.join("10_midlands_archosaur_aerogear_flight_3d.bmp"),
                fb.encode_bmp(),
            )
            .unwrap();

            // 11: Interactive Midlands Continent `WorldMap` (`surfaces/ingame/world.dds` + 54 `world_targets.txt`)
            app.modal = pw_client::game_app::InWorldModal::WorldMap;
            app.world_map_regional_zoom = false;
            app.tick(0.15, &idle_in);
            app.render(&mut fb, 640, 400);
            std::fs::write(
                out_dir.join("11_midlands_continent_worldmap_aui.bmp"),
                fb.encode_bmp(),
            )
            .unwrap();

            // 12: City of the Plume (`(-758.54, -1342.07)`, Winged Elf Capital) + 3D `.mox` Grass & SpeedTree
            app.modal = pw_client::game_app::InWorldModal::None;
            app.flying_mode = false;
            app.cam_dist = 10.5;
            app.cam_pitch = 0.18;
            app.player_yaw = 0.65;
            app.cam_yaw = 0.65;
            app.teleport_to_world_pos(-758.54, -1342.07, Some("City of the Plume"));
            app.tick(0.35, &idle_in);
            app.render(&mut fb, 640, 400);
            std::fs::write(out_dir.join("12_midlands_plume_city_3d.bmp"), fb.encode_bmp()).unwrap();

            // 13: Etherblade (`(487.0, 3239.12)`, Human Capital) + Interactive NPC Dialogue (`Win_NPC`) + `Win_HpmpOther` 3D NPC Portrait!
            app.player_yaw = 3.10;
            app.cam_yaw = 3.10;
            app.teleport_to_world_pos(487.0, 3239.12, Some("Etherblade"));
            if let Some(npc_id) = app
                .world_entities
                .iter()
                .find(|e| e.kind == pw_render_audio::EntityVisualKind::Npc)
                .map(|e| e.id)
            {
                app.selected_entity_id = Some(npc_id);
            }
            app.modal = pw_client::game_app::InWorldModal::NpcDialog;
            app.tick(0.25, &idle_in);
            app.render(&mut fb, 640, 400);
            std::fs::write(
                out_dir.join("13_midlands_etherblade_npc_dialog_3d.bmp"),
                fb.encode_bmp(),
            )
            .unwrap();

            // 14: City of Raging Tides (`(2681.93, -4268.36)`, Tideborn Capital) + `Win_Quest` + `Win_QShop` + Tideborn `幻彩翅膀`
            app.selected_role_idx = 2; // AbyssTide (Tideborn Assassin -> `幻彩翅膀.ecm`!)
            app.enter_world_with_selected_role();
            app.teleport_to_world_pos(2681.93, -4268.36, Some("City of Raging Tides"));
            app.flying_mode = true;
            if let Some(hp) = &mut app.game.host_player {
                hp.position.y += 6.5;
            }
            app.modal = pw_client::game_app::InWorldModal::None;
            app.player_yaw = -0.85;
            app.cam_yaw = -0.85;
            app.cam_pitch = 0.20;
            app.cam_dist = 8.2;
            app.tick(0.35, &idle_in);
            app.render(&mut fb, 640, 400);
            std::fs::write(out_dir.join("14_midlands_raging_tides_3d.bmp"), fb.encode_bmp()).unwrap();

            // 15: `Win_Quest` (`quest.dtf` native controls + 9-slice border + close button)
            app.flying_mode = false;
            app.modal = pw_client::game_app::InWorldModal::QuestLog;
            app.tick(0.15, &idle_in);
            app.render(&mut fb, 640, 400);
            std::fs::write(out_dir.join("15_inworld_quest_log_aui.bmp"), fb.encode_bmp()).unwrap();

            // 16: `Win_QShop` (`qshop.dtf` Treasure Boutique 8-card grid + featured item + close button)
            app.modal = pw_client::game_app::InWorldModal::Boutique;
            app.tick(0.15, &idle_in);
            app.render(&mut fb, 640, 400);
            std::fs::write(out_dir.join("16_inworld_qshop_boutique_aui.bmp"), fb.encode_bmp()).unwrap();

            // 17: `Win_Action` (`action.dtf` 56 `iconlist_action.dds` Action & Emote Icons + `Win_Main2` Subbar)
            app.teleport_to_world_pos(1292.0, 1132.0, Some("Archosaur West Plaza"));
            app.modal = pw_client::game_app::InWorldModal::ActionPanel;
            app.show_main2 = true;
            app.show_main3 = false;
            app.tick(0.25, &idle_in);
            app.render(&mut fb, 1185, 775);
            std::fs::write(out_dir.join("17_inworld_action_emotes_aui.bmp"), fb.encode_bmp()).unwrap();

            // 18: `Win_SettingSystem` (`setting_system.dtf` 12 live `AUISlider`s + Checkboxes + `Win_Main3` Subbar)
            app.modal = pw_client::game_app::InWorldModal::SystemSettings;
            app.show_main2 = false;
            app.show_main3 = true;
            app.tick(0.25, &idle_in);
            app.render(&mut fb, 1235, 775);
            std::fs::write(out_dir.join("18_inworld_system_settings_aui.bmp"), fb.encode_bmp()).unwrap();

            // 19: `Win_FriendList` (`Tv_FriendList` `AUITreeView`) + Floating `.htf`/Skill `InGameHintFrame.dds` Tooltip + `hand.cur`
            app.modal = pw_client::game_app::InWorldModal::FriendList;
            app.show_main3 = false;
            app.tick(0.25, &idle_in);
            // Hover Quickbar Slot 1 (`Win_Quickbar8Ha::Item_1`) to showcase floating `InGameHintFrame.dds` tooltip & `hand.cur`!
            let (hx, hy) = app
                .ingame_ui
                .find_control_screen_rect(&app.game.aui_manager, "Win_Quickbar8Ha", "Item_1", 1280, 800)
                .map(|(x, y, w, h)| (x + w / 2, y + h / 2))
                .unwrap_or((540, 775));
            app.render(&mut fb, hx, hy);
            std::fs::write(out_dir.join("19_inworld_friendlist_hover_tooltip.bmp"), fb.encode_bmp()).unwrap();

            // 20: Untamed Barbarian (`TigerLord`) in City of the Lost + `Win_HpOther` Monster Target Frame + Tiger 3D Portrait!
            app.selected_role_idx = 4; // TigerLord (Untamed Barbarian -> `妖兽男标准脸` + `虎.dds`!)
            app.enter_world_with_selected_role();
            app.teleport_to_world_pos(-1350.0, 1280.0, Some("City of the Lost"));
            app.modal = pw_client::game_app::InWorldModal::None;
            app.flying_mode = false;
            app.cam_dist = 8.4;
            app.cam_pitch = 0.20;
            app.player_yaw = 0.42;
            app.cam_yaw = 0.42;
            app.cast_quickbar_slot(0);
            app.tick(0.25, &idle_in);
            app.render(&mut fb, 640, 400);
            std::fs::write(
                out_dir.join("20_midlands_untamed_barbarian_monster_target_3d.bmp"),
                fb.encode_bmp(),
            )
            .unwrap();

            println!(
                "  Saved 20 full-parity 1280x800 frames (all 4 races, Midlands cities, Win_HpOther & Win_HpmpOther portraits, mipmaps/anisotropic, & pure English UI) to '{}'",
                out_dir.display()
            );
        } else {
            println!("  Saved 8 full-parity 1280x800 frames to '{}'", out_dir.display());
        }
        return;
    }

    if headless {
        return;
    }

    println!("  Launching CECGame::Run interactive client window (F11 = Fullscreen, F5 = Offline 3D Sandbox)...");
    let mut app = InteractiveClientApp::new(game);
    if console_enabled {
        app.console_log
            .push("Developer console unlocked via console:1 (press ~ or F12 in-world).".into());
    }
    if let Some(role_name) = cli_role {
        app.create_name_input = role_name;
    }
    if let Some(addr) = connect_addr.clone() {
        app.server_addr_input = addr;
    }
    if let Some(u) = cli_user.clone() {
        app.account_input = u;
    }
    if let Some(p) = cli_pass.clone() {
        app.password_input = p;
    }
    if start_offline {
        app.enter_offline_character_select();
    } else if connect_addr.is_some() || (cli_user.is_some() && cli_pass.is_some()) {
        app.start_online_login();
    }
    if let Err(e) = run_win32_client(app) {
        eprintln!("CECGame::Run window error: {e}");
        process::exit(1);
    }
}
