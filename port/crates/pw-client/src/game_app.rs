//! `CECGameRun` (`0x434b80`) + `CECLoginUIMan` (`08_cecloginuiman.c`) + `CECGameUIMan` (`07_cecgameuiman.c`).
//!
//! 100% grounded in real Perfect World 1.4.2 files and decompiled engine logic:
//! - Loads & renders the real `Maps\Login` and `Maps\a01` (`CECWorld` / `CECScene` / `A3DTerrain2` /
//!   `A3DLitModel` `.bmd` / `A3DSkinModel` `.ski` / `A3DSkySphere` / `A3DWaterArea`) via `LoadedScene3D`.
//! - Uses the exact camera & character-pedestal rigs from `configs\scenectrl.ini` (`SceneCtrlConfig`).
//! - Executes the real `interfaces\loginui.dcf` (`Win_Login`, `Win_LoginWait`, `Win_LoginServerList`,
//!   `Win_Select`, `Win_Manage`, `Win_Manage2`, `Win_Create`, `Win_CreateInfo0..7`) and
//!   `interfaces\ingame.dcf` (`Win_Hpmpxp`, `Win_Map`, `Win_Chat`, `Win_Quickbar8Ha`, `Win_Quickbar9Va`,
//!   `Win_Main`, `Win_HpmpOther`, `Win_InventoryM/F`, `Win_Bag`, `Win_ELFSkill`, `Win_Quest`,
//!   `Win_QShop`, `WorldMap`, `Dlg_Console`) via `AuiRuntime` + `surfaces.pck` sprites.
//! - Drives both the hardware Windows `d3d9.dll` COM renderer (`D3d9Renderer` via `prepare_frame`)
//!   and the perspective-correct reference rasterizer (`render_scene_and_ui_cpu` via `render`).

use pw_aui::AuiRuntime;
use pw_core::{
    decode_gbk_null_terminated, decode_utf16le_null_terminated, find_path_case_insensitive,
    IniFile, PwResult, Vec3,
};
use pw_data::ElementSectionData;
use pw_gnet::{CharacterSummary, GLinkEvent, GLinkLiveClient, GsS2cPacket};
use pw_render_audio::{
    build_aui_draw_list, class_aerogear_ecm, emit_aui_hover_tooltip, emit_software_cursor_quad,
    project_world_to_screen, render_scene_and_ui_cpu, A3DCamera, ActorActionKind, AmSoundEngine,
    DynamicCharacterActor, EntityVisualKind, FrameBuffer, LoadedScene3D, UiQuad2D, UiText2D,
    WorldEntity3D, REAL_MONSTER_ECMS, REAL_NPC_ECMS,
};
use pw_skill::ElementSkill;
use pw_world::MapInstanceBundle;

use crate::{CecGame, CecHostPlayer};

const VK_BACK: u32 = 0x08;
const VK_TAB: u32 = 0x09;
const VK_RETURN: u32 = 0x0D;
const VK_ESCAPE: u32 = 0x1B;
const VK_F5: u32 = 0x74;
const VK_F9: u32 = 0x78;
const VK_F12: u32 = 0x7B;
const VK_OEM_3: u32 = 0xC0; // `~
const VK_OEM_4: u32 = 0xDB; // [
const VK_OEM_6: u32 = 0xDD; // ]

#[derive(Debug, Clone)]
pub struct ServerListEntry {
    pub group: String,
    pub name: String,
    pub addr: String,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum ClientScreenState {
    Login,
    LoginWait,
    CharacterSelect,
    CreateCharacter,
    InWorld,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum LoginFocusField {
    ServerAddr,
    Account,
    Password,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum InWorldModal {
    None,
    CharacterSheet, // C — `Win_Character` (`character.dtf` attributes & stats)
    Inventory,      // B — `Win_InventoryM/F` + `Win_Bag` (`elements.data` + `iconlist_ivtrm.dds`)
    SkillBook,      // K — `Win_ELFSkill` (`elementskill.dll` 1,175 skills + `iconlist_skill.dds`)
    QuestLog,       // Q — `Win_Quest` (`tasks.data`)
    Boutique,       // O — `Win_QShop` (`gshop.data` 605 items)
    WorldMap,       // M — `WorldMap` (`surfaces\ingame\world.dds` + `54` `world_targets.txt` + `47` domains)
    NpcDialog,      // G / Click NPC — `Win_NPC` (`NPC_ESSENCE` + `TALK_PROC` + `tasks.data`)
    ActionPanel,    // E — `Win_Action` (`action.dtf` + `iconlist_action.dds` 56 basic/squad/trade/emote icons)
    FriendList,     // Y — `Win_FriendList` (`friendlist.dtf` `Tv_FriendList` `AUITreeView`)
    SystemSettings, // U — `Win_SettingSystem` (`setting_system.dtf` 12 live `AUISlider`s & checkboxes)
    GuildManage,    // F — `Win_GuildManage` (`GNET` Faction roster, rank, & proclamation)
    TerritoryMap,   // T — `GuildMap` (`domain.data` all 47 Territory War zones + `BattleGetMap`)
    PetBag,         // P — `Win_PetList` (`s2c::PET_ROOM` combat pets & mounts + `Summon`/`Recall`)
    MailBox,        // L — `Win_MailList` (`GNET` Mail inbox, sender, & attachments)
    AuctionHouse,   // J — `Win_AuctionList` / `Win_GoldTrade` (`GNET` Auction & Gold Stock Exchange)
    PlayerTrade,    // X — `Win_Trade` (`GNET` Player-to-player item & coin trade)
    NpcShop,        // V — `Win_Shop` (`CDlgShop` NPC Buy, Sell, & Repair All)
    Warehouse,      // N — `Win_Storage` (`CDlgStorage` Account Bank & Coin Stash)
    CraftProduce,   // I — `Win_Produce` (`CDlgProduce` Blacksmith / Tailor / Craftsman / Apothecary)
    EquipRefine,    // F6 — `Win_EquipRefine` (`CDlgEquipRefine` Elder `+1..+12` Mirage Refinement & Sockets)
    GenieElf,       // F7 — `Win_ELFProp` (`CDlgELFProp` Rising Tide Elemental Genie Skills & Stamina)
    PlayerBooth,    // F8 — `Win_Booth` (`CDlgBooth` Cat-Shop Personal Market Stall)
    PkAutolock,     // F5 — `Win_PKSetting` / `Win_AutoLock` (`CDlgPKSetting` + Safety Lock)
    DevConsole,     // ` / F12 — `Dlg_Console` (`configs/console_cmd.txt`)
}

#[derive(Debug, Clone, Default)]
pub struct InputSnapshot {
    pub move_fwd: bool,
    pub move_back: bool,
    pub move_left: bool,
    pub move_right: bool,
    pub ascend: bool,
    pub descend: bool,
    pub sprint: bool,
    pub mouse_x: i32,
    pub mouse_y: i32,
    pub lmb_down: bool,
    pub rmb_down: bool,
}

#[derive(Debug, Clone)]
pub struct CastEffect {
    pub pos: Vec3,
    pub skill_name: String,
    pub color: u32,
    pub ttl: f32,
}

#[allow(dead_code)]
#[derive(Debug, Clone)]
struct ElementItemPreview {
    section_name: &'static str,
    id: u32,
    name: String,
    icon_dds: String,
}

/// Complete per-frame 3D + 2D draw packet consumed directly by hardware `D3d9Renderer` (`d3d9.dll`)
/// or CPU reference rasterizer (`render_scene_and_ui_cpu`).
pub struct PreparedFrame {
    pub eye: Vec3,
    pub dir: Vec3,
    pub up: Vec3,
    pub cam_proj: A3DCamera,
    pub actors: Vec<DynamicCharacterActor>,
    pub ui_quads: Vec<UiQuad2D>,
    pub ui_texts: Vec<UiText2D>,
    pub anim_time: f32,
}

/// PW 1.4.2 Race -> Professions table (`08_cecloginuiman.c`):
/// Race 0 = Human (`[0=Blademaster, 1=Wizard]`),
/// Race 1 = Tideborn (`[2=Psychic, 5=Assassin]`),
/// Race 2 = Untamed (`[3=Venomancer, 4=Barbarian]`),
/// Race 3 = Winged Elf (`[6=Archer, 7=Cleric]`).
const RACE_NAMES: [&str; 4] = ["Human", "Tideborn", "Untamed", "Winged Elf"];
const RACE_CLASSES: [[u8; 2]; 4] = [[0, 1], [2, 5], [3, 4], [6, 7]];

fn race_for_class(cls: u8) -> usize {
    match cls {
        0 | 1 => 0,
        2 | 5 => 1,
        3 | 4 => 2,
        _ => 3,
    }
}

fn clamp_gender_for_class(cls: u8, gender: u8) -> u8 {
    match cls {
        3 => 1, // Venomancer is Female-only
        4 => 0, // Barbarian is Male-only
        _ => gender & 1,
    }
}

pub struct InteractiveClientApp {
    pub game: CecGame,
    pub scene_3d: LoadedScene3D,
    /// Increments whenever `scene_3d` reloads a new map so `D3d9Renderer` flushes old GPU textures.
    pub scene_generation: u64,
    pub login_ui: AuiRuntime,
    pub ingame_ui: AuiRuntime,
    pub net: GLinkLiveClient,
    pub audio: AmSoundEngine,
    pub screen: ClientScreenState,
    pub online_mode: bool,

    // Login & Server Selection state (`CECLoginUIMan`)
    pub selected_server_idx: usize,
    pub server_addr_input: String,
    pub account_input: String,
    pub password_input: String,
    pub force_login: bool,
    pub show_server_picker: bool,
    pub login_focus: LoginFocusField,
    pub status_banner: String,
    pub login_cam_preset_idx: usize,

    // Character Select / Create state (`CECLoginUIMan`)
    pub roster: Vec<CharacterSummary>,
    pub selected_role_idx: usize,
    pub pedestal_yaw_offset: f32,
    pub create_name_input: String,
    pub create_occupation: u8,
    pub create_gender: u8,
    pub create_appearance_preset: u8,
    pub role_appearance_presets: std::collections::HashMap<u32, u8>,

    // In-World 3D Simulation & Camera state (`CECGameRun` + `CECHostPlayer`)
    pub cam_yaw: f32,
    pub cam_pitch: f32,
    pub cam_dist: f32,
    /// Day→night terrain lightmap blend (`0.0` day `.t2lm`, `1.0` night `.t2lm1`); sandbox `--night`.
    pub night_weight: f32,
    pub player_yaw: f32,
    pub player_vel_y: f32,
    pub player_moving: bool,
    pub player_attack_timer: f32,
    pub move_packet_accum: f32,
    pub move_packet_stamp: u16,
    pub flying_mode: bool,
    pub move_speed: f32,
    pub time_of_day: f32,
    pub water_level: f32,
    pub anim_seconds: f32,
    pub fps_display: u32,

    // Combat / Skills / Entities / Chat / Modals (`CECGameUIMan`)
    pub host_hp: i32,
    pub host_max_hp: i32,
    pub host_mp: i32,
    pub host_max_mp: i32,
    pub host_chi: i32,
    pub quickbar_skills: [u32; 8],
    pub skill_cooldowns: [f32; 8],
    pub world_entities: Vec<WorldEntity3D>,
    pub entity_ecm_paths: std::collections::HashMap<u32, String>,
    pub entity_greetings: std::collections::HashMap<u32, String>,
    pub selected_entity_id: Option<u32>,
    pub active_effects: Vec<CastEffect>,
    pub modal: InWorldModal,
    pub show_main2: bool,
    pub show_main3: bool,
    pub world_map_regional_zoom: bool,
    pub active_bgm_rel: String,
    pub list_scroll: usize,
    pub gshop_cat_idx: usize,
    pub chat_active: bool,
    pub chat_input: String,
    pub chat_log: Vec<(u32, String)>,
    pub console_input: String,
    pub console_log: Vec<String>,
    pub active_buff_states: Vec<u16>,
    pub active_visible_states: Vec<u32>,
    pub team_members: Vec<pw_gnet::GsTeamMemberInfo>,
    pub pet_slots: Vec<(String, pw_gnet::GsPetSlotInfo)>,
    pub summoned_pet_idx: Option<usize>,
    pub mail_headers: Vec<pw_gnet::GnetMailHeader>,
    pub auction_items: Vec<(String, pw_gnet::GnetAuctionEntry)>,
    pub stock_cash_gold: i32,
    pub stock_coins: i32,
    pub faction_summary: pw_gnet::GnetFactionSummary,
    pub territory_owners: std::collections::HashMap<u16, String>,
    pub selected_domain_idx: usize,
    pub weapon_refine_level: u8,
    pub elf_vigor: i32,
    pub elf_stamina: i32,
    pub pvp_enabled: bool,
    pub autolock_minutes: u32,
    pub stash_coins: u32,
    pub booth_slogan: String,
    pub named_preset_cursor: usize,
    pub spatial_mixer: pw_render_audio::SpatialAudioMixer,

    #[allow(dead_code)]
    sample_items: Vec<ElementItemPreview>,
    layout_ini: Option<IniFile>,
    applied_layout_size: (u32, u32),
    last_rmb_pos: Option<(i32, i32)>,
    last_screen_dims: (u32, u32),
    pub should_quit: bool,
}

impl InteractiveClientApp {
    pub fn new(game: CecGame) -> Self {
        let default_addr = game
            .server_list
            .first()
            .map(|s| s.addr.clone())
            .unwrap_or_else(|| "127.0.0.1:29000".to_string());

        let mut audio = AmSoundEngine::new(
            game.video_audio_settings.music_vol,
            game.video_audio_settings.sound_vol,
        );
        for cand in ["music/theme_a.mp3", "music/theme_b.mp3", "music/theme_c.mp3"] {
            if let Some(p) = find_path_case_insensitive(&game.element_root, cand) {
                audio.play_bgm_file(&p);
                break;
            }
        }

        let mut scene_3d = LoadedScene3D::build_with_night(&game.active_map, &game.vfs, 0.0);
        scene_3d.load_cursors_from_dir(&game.element_root);
        scene_3d.show_software_cursor = true;
        let mut login_ui = AuiRuntime::from_dcf(&game.aui_manager, "interfaces/loginui.dcf");
        login_ui.focus_edit("Win_Login", "DEFAULT_Txt_Account");
        let mut ingame_ui = AuiRuntime::from_dcf(&game.aui_manager, "interfaces/ingame.dcf");
        // Seed `Win_SettingSystem` sliders, combos, and checkboxes (`SystemSettings.ini` defaults)
        for (sl_name, cur_lv, max_lv) in [
            ("Slider_Total", 4, 4),
            ("Slider_Range", 4, 4),
            ("Slider_Texture", 2, 2),
            ("Slider_Bright", 68, 100),
            ("Slider_Water", 2, 2),
            ("Slider_Tree", 4, 4),
            ("Slider_Grass", 4, 4),
            ("Slider_Cloud", 4, 4),
            ("Slider_Terrain", 1, 1),
            ("Slider_Music", game.video_audio_settings.music_vol as i32, 100),
            ("Slider_Ambience", game.video_audio_settings.sound_vol as i32, 100),
            ("Slider_Sample", 2, 2),
        ] {
            ingame_ui.set_slider("Win_SettingSystem", sl_name, cur_lv, max_lv);
        }
        ingame_ui.list_items.insert(
            ("Win_SettingSystem".to_string(), "Combo_Res".to_string()),
            vec!["1280x800".into(), "1920x1080".into(), "1024x768".into()],
        );
        ingame_ui.list_items.insert(
            ("Win_SettingSystem".to_string(), "Combo_Full".to_string()),
            vec!["Window".into(), "FullScr".into()],
        );
        for chk in ["Chk_WideScr", "Chk_Shade", "Chk_Mipmap", "Chk_Fullglow", "Chk_Sunflare"] {
            ingame_ui
                .check_states
                .insert(("Win_SettingSystem".to_string(), chk.to_string()), true);
        }
        ingame_ui.list_items.insert(
            ("Win_FriendList".to_string(), "Tv_FriendList".to_string()),
            vec![
                "[-] Celestial Friends (4/4)".into(),
                "  ◆ General Summer [Lv.105 BM]".into(),
                "  ◆ Lingbo Fairy [Lv.102 Psy]".into(),
                "  ◆ Master Li [Lv.101 Archer]".into(),
                "  ◆ Elder of Streams [Lv.103 Cleric]".into(),
                "[-] Archosaur Guard (Online)".into(),
                "  ◆ Tideborn Envoy [Lv.100 Sin]".into(),
                "  ◆ Untamed Warlord [Lv.101 Barb]".into(),
            ],
        );
        let mut layout_ini = None;
        for layout_cand in [
            "userdata/Layout/1024.ini",
            "userdata/layout/1024.ini",
            "userdata/Layout/default.ini",
        ] {
            if let Some(lp) = find_path_case_insensitive(&game.element_root, layout_cand) {
                if let Ok(bytes) = std::fs::read(&lp) {
                    let parsed = IniFile::parse_bytes(&bytes);
                    ingame_ui.apply_layout_ini(&game.aui_manager, &parsed, 1280, 800);
                    layout_ini = Some(parsed);
                    break;
                }
            }
        }

        let sample_items = extract_element_item_previews(&game);
        let default_roster = build_offline_archetype_roster();
        let water_level = game
            .active_map
            .scene
            .water_areas
            .first()
            .map(|w| w.water_height)
            .unwrap_or_else(|| (game.active_map.height_mesh.min_height + 4.5).max(198.0));

        let mut app = Self {
            net: GLinkLiveClient::new(default_addr.clone()),
            audio,
            scene_3d,
            scene_generation: 1,
            login_ui,
            ingame_ui,
            screen: ClientScreenState::Login,
            online_mode: false,
            selected_server_idx: 0,
            server_addr_input: default_addr.clone(),
            account_input: "admin".to_string(),
            password_input: String::new(),
            force_login: false,
            show_server_picker: false,
            login_focus: LoginFocusField::Password,
            status_banner: format!(
                "Server {} — Click [Start] to connect to glinkd, or press F5 for Offline Mode",
                default_addr
            ),
            login_cam_preset_idx: 0,
            roster: default_roster,
            selected_role_idx: 0,
            pedestal_yaw_offset: 0.0,
            create_name_input: "Archosaur".to_string(),
            create_occupation: 0,
            create_gender: 0,
            create_appearance_preset: 0,
            role_appearance_presets: std::collections::HashMap::new(),
            cam_yaw: 0.55,
            cam_pitch: 0.24,
            cam_dist: 8.5,
            night_weight: 0.0,
            player_yaw: 0.55,
            player_vel_y: 0.0,
            player_moving: false,
            player_attack_timer: 0.0,
            move_packet_accum: 0.0,
            move_packet_stamp: 0,
            flying_mode: false,
            move_speed: 14.0,
            time_of_day: 10.2,
            water_level,
            anim_seconds: 0.0,
            fps_display: 60,
            host_hp: 8450,
            host_max_hp: 8450,
            host_mp: 6200,
            host_max_mp: 6200,
            host_chi: 299,
            quickbar_skills: [1, 2, 3, 4, 5, 6, 7, 8],
            skill_cooldowns: [0.0; 8],
            world_entities: Vec::new(),
            entity_ecm_paths: std::collections::HashMap::new(),
            entity_greetings: std::collections::HashMap::new(),
            selected_entity_id: None,
            active_effects: Vec::new(),
            modal: InWorldModal::None,
            show_main2: false,
            show_main3: false,
            world_map_regional_zoom: false,
            active_bgm_rel: String::new(),
            list_scroll: 0,
            gshop_cat_idx: 0,
            chat_active: false,
            chat_input: String::new(),
            chat_log: vec![
                (
                    0xFFFF_4838,
                    format!(
                        "[Archosaur] Welcome to Perfect World 1.4.2 Rising Tide (Build {}, ElementSkill v{}) — Midlands (1292, 219.6, 1132)! Long system announcements automatically wrap and clip inside Win_ChatSmall.",
                        game.build_version, game.skill_abi_version
                    ),
                ),
                (
                    0xFF8C_E8FF,
                    "[World] WASD Move | RMB Orbit | F Fly | 1..9 Skills | B Bag | C Character | K Skills | Q Quests | O Boutique | M Map".into(),
                ),
            ],
            console_input: String::new(),
            console_log: vec![
                "Angelica 3D Console ready. Commands: d_fly, d_speed <n>, d_time <0..24>, d_goto <x> <z>, d_map <name>, d_skill <id>".into(),
            ],
            active_buff_states: vec![5, 6, 4],
            active_visible_states: vec![28],
            team_members: Vec::new(),
            pet_slots: vec![
                (
                    "Celestial Baby".to_string(),
                    pw_gnet::GsPetSlotInfo {
                        pet_index: 0,
                        pet_tid: 20194,
                        level: 100,
                        hp: 6840,
                        max_hp: 6840,
                        loyalty: 999,
                        hunger: 0,
                    },
                ),
                (
                    "Blazing Phoenix".to_string(),
                    pw_gnet::GsPetSlotInfo {
                        pet_index: 1,
                        pet_tid: 20195,
                        level: 101,
                        hp: 5920,
                        max_hp: 5920,
                        loyalty: 999,
                        hunger: 0,
                    },
                ),
                (
                    "Nine-Tailed Fox Mount".to_string(),
                    pw_gnet::GsPetSlotInfo {
                        pet_index: 2,
                        pet_tid: 20200,
                        level: 80,
                        hp: 4500,
                        max_hp: 4500,
                        loyalty: 950,
                        hunger: 0,
                    },
                ),
            ],
            summoned_pet_idx: None,
            mail_headers: vec![
                pw_gnet::GnetMailHeader {
                    mail_id: 1,
                    sender_id: 1001,
                    send_type: 1,
                    receiver_stamp: 1_700_000_000,
                    attribute: 1,
                    title: "Archosaur Defense Commendation".to_string(),
                    sender_name: "General Summer".to_string(),
                },
                pw_gnet::GnetMailHeader {
                    mail_id: 2,
                    sender_id: 1002,
                    send_type: 0,
                    receiver_stamp: 1_700_003_600,
                    attribute: 3,
                    title: "Territory War Reward Chest".to_string(),
                    sender_name: "Auctioneer".to_string(),
                },
            ],
            auction_items: sample_items
                .iter()
                .take(6)
                .enumerate()
                .map(|(idx, it)| {
                    (
                        it.name.clone(),
                        pw_gnet::GnetAuctionEntry {
                            auction_id: 5000 + idx as u32,
                            bid_price: 120_000 + (idx as u32) * 85_000,
                            bin_price: 250_000 + (idx as u32) * 150_000,
                            end_time: 7200,
                            item_id: it.id,
                            count: 1,
                            seller_id: 1024,
                            bidder_id: 0,
                        },
                    )
                })
                .collect(),
            stock_cash_gold: 2_500,
            stock_coins: 12_850_000,
            faction_summary: pw_gnet::GnetFactionSummary {
                faction_id: 1,
                name: "Vanguard".to_string(),
                level: 3,
                member_count: 198,
                announce: "Territory War Sat 20:00 — Rally at Archosaur West!".to_string(),
            },
            territory_owners: {
                let mut m = std::collections::HashMap::new();
                m.insert(10, "Vanguard".to_string());
                m.insert(23, "Vanguard".to_string());
                m.insert(1, "Eternity".to_string());
                m.insert(44, "Sovereign".to_string());
                m
            },
            selected_domain_idx: 0,
            weapon_refine_level: 8,
            elf_vigor: 135,
            elf_stamina: 999_999,
            pvp_enabled: false,
            autolock_minutes: 5,
            stash_coins: 50_000_000,
            booth_slogan: "Archosaur Gems & Mirage Stones!".to_string(),
            named_preset_cursor: 0,
            spatial_mixer: pw_render_audio::SpatialAudioMixer {
                music_volume: game.video_audio_settings.music_vol as f32 / 100.0,
                sfx_volume: game.video_audio_settings.sound_vol as f32 / 100.0,
                ..Default::default()
            },
            sample_items,
            layout_ini,
            applied_layout_size: (1280, 800),
            last_rmb_pos: None,
            last_screen_dims: (1280, 800),
            should_quit: false,
            game,
        };
        app.ensure_login_map_loaded();
        app.populate_world_entities();
        app
    }

    /// Sets the day→night terrain lightmap blend and rebuilds the 3D scene (sandbox `--night`).
    pub fn set_night_weight(&mut self, w: f32) {
        self.night_weight = w.clamp(0.0, 1.0);
        self.reload_active_scene_3d();
    }

    /// Switches the active map and rebuilds the 3D scene (sandbox teleport-menu map hop).
    pub fn load_map_and_reload(&mut self, map_name: &str, center: Vec3) -> PwResult<()> {
        self.game.load_map_by_name_at(map_name, center)?;
        self.reload_active_scene_3d();
        Ok(())
    }

    fn reload_active_scene_3d(&mut self) {
        self.water_level = self
            .game
            .active_map
            .scene
            .water_areas
            .first()
            .map(|w| w.water_height)
            .unwrap_or(-10_000.0);
        let keep_sw = self.scene_3d.show_software_cursor;
        self.scene_3d = LoadedScene3D::build(&self.game.active_map, &self.game.vfs);
        self.scene_3d.load_cursors_from_dir(&self.game.element_root);
        self.scene_3d.show_software_cursor = keep_sw;
        self.scene_generation = self.scene_generation.wrapping_add(1);
    }

    fn ensure_login_map_loaded(&mut self) {
        if !self.game.active_map.map_name.eq_ignore_ascii_case("login")
            && self
                .game
                .available_maps
                .iter()
                .any(|m| m.eq_ignore_ascii_case("login"))
        {
            if self.game.load_map_by_name("login").is_ok() {
                self.reload_active_scene_3d();
            }
        }
    }

    fn play_click_sfx(&mut self) {
        for cand in [
            "sfx\\interface\\clickb.wav",
            "sfx\\interface\\clicka.wav",
            "interface\\clickb.wav",
        ] {
            if let Ok(wav) = self.game.vfs.read_file(cand) {
                self.audio.play_sfx_wav_bytes(wav);
                break;
            }
        }
    }

    /// Computes exact walkable ground height at `(wx, wz)`, combining multi-subterrain `A3DTerrain2`,
    /// per-area `A3DWaterArea` bounds (never flooding dry valleys!), and walkable `.bmd` city/bridge geometry.
    pub fn sample_active_ground_y(&self, wx: f32, ref_y: f32, wz: f32) -> f32 {
        let mut ty = self.game.active_map.sample_world_height(wx, wz);
        if let Some(wy) = self.game.active_map.sample_water_height_at(wx, wz) {
            ty = ty.max(wy);
        }
        self.scene_3d.sample_walkable_height(wx, ref_y, wz, ty)
    }

    fn sync_precinct_bgm(&mut self, wx: f32, wz: f32) {
        if let Some(prec) = self.game.active_map.precinct_at(wx, wz) {
            if !prec.bgm_music.is_empty() && prec.bgm_music != self.active_bgm_rel {
                self.active_bgm_rel = prec.bgm_music.clone();
                if let Some(p) = find_path_case_insensitive(&self.game.element_root, &prec.bgm_music)
                {
                    self.audio.play_bgm_file(&p);
                }
            }
        }
    }

    /// Teleports the host player anywhere in the active map (including across all `88` `1024m` Midlands
    /// sub-terrains via `CECWorld::SetLoadCenter`), streaming terrain, `.bmd` buildings, 3D grass, radar, and spawns.
    pub fn teleport_to_world_pos(&mut self, wx: f32, wz: f32, label: Option<&str>) {
        let half_w = self.scene_3d.world_width * 0.495;
        let half_l = self.scene_3d.world_length * 0.495;
        let cx = wx.clamp(-half_w, half_w);
        let cz = wz.clamp(-half_l, half_l);

        if self
            .game
            .active_map
            .set_load_center(Vec3::new(cx, 220.0, cz))
            .unwrap_or(false)
        {
            self.reload_active_scene_3d();
        }
        self.scene_3d
            .refresh_minimap_for_pos(&self.game.vfs, cx, cz);
        let wy = self.sample_active_ground_y(cx, 520.0, cz);
        if let Some(p) = &mut self.game.host_player {
            p.position = Vec3::new(cx, wy, cz);
        }
        self.sync_precinct_bgm(cx, cz);
        self.populate_world_entities();

        let gx = ((cx + 4000.0) * 0.1).round() as i32;
        let gz = ((cz + 5500.0) * 0.1).round() as i32;
        let gy = (wy * 0.1).round().max(0.0) as i32;
        if let Some(lbl) = label {
            self.chat_log.push((
                0xFFFF_DF88,
                format!("[Teleport] Arrived at {lbl} ({gx}, {gz} H{gy} | {cx:.1}, {wy:.1}, {cz:.1})."),
            ));
        }
    }

    fn upsert_live_npc(&mut self, nid: u32, tid: u32, pos: (f32, f32, f32), dir: u8) {
        let yaw = (dir as f32 / 256.0) * core::f32::consts::TAU;
        let wy = self.sample_active_ground_y(pos.0, pos.1 + 3.0, pos.2);
        if let Some(existing) = self.world_entities.iter_mut().find(|e| e.id == nid) {
            existing.pos = Vec3::new(pos.0, wy, pos.2);
            existing.yaw = yaw;
            return;
        }
        if let Some(info) = self.game.npc_essences.get(&tid) {
            self.entity_ecm_paths.insert(nid, info.ecm_path.clone());
            if !info.greeting.is_empty() {
                self.entity_greetings.insert(nid, info.greeting.clone());
            }
            self.world_entities.push(WorldEntity3D {
                id: nid,
                name: info.name.trim().to_string(),
                title: String::new(),
                kind: EntityVisualKind::Npc,
                pos: Vec3::new(pos.0, wy, pos.2),
                yaw,
                scale: 1.0,
                primary_color: 0x2B6B58,
                accent_color: 0xE8C468,
                hp_ratio: 1.0,
                selected: false,
                flying: false,
            });
        } else if let Some(minfo) = self.game.monster_essences.get(&tid) {
            self.entity_ecm_paths.insert(nid, minfo.ecm_path.clone());
            let att = if minfo.short_desc.is_empty() {
                format!("Lv.{}", minfo.level)
            } else {
                format!("Lv.{}  {}", minfo.level, minfo.short_desc)
            };
            self.world_entities.push(WorldEntity3D {
                id: nid,
                name: minfo.name.trim().to_string(),
                title: att,
                kind: EntityVisualKind::Monster,
                pos: Vec3::new(pos.0, wy, pos.2),
                yaw,
                scale: 1.0,
                primary_color: 0x7A2424,
                accent_color: 0xFF7040,
                hp_ratio: 1.0,
                selected: false,
                flying: false,
            });
        }
    }

    fn populate_world_entities(&mut self) {
        self.world_entities.clear();
        self.entity_ecm_paths.clear();
        self.entity_greetings.clear();

        let center = self
            .game
            .host_player
            .as_ref()
            .map(|p| p.position)
            .unwrap_or_else(|| {
                let c = self.game.active_map.load_center;
                Vec3::new(c.x, self.game.active_map.sample_world_height(c.x, c.z), c.z)
            });

        let map_low = self.game.active_map.map_name.to_ascii_lowercase();
        let mut spawned_npcs = 0usize;
        let mut spawned_mobs = 0usize;

        // 1. Real `task_npc.data` + `configs/coord_data.txt` NPCs (`NPC_ESSENCE` Section 58)
        if map_low == "world" || !self.game.coord_spawns.is_empty() {
            let mut npc_cands: Vec<(f32, u32, f32, f32, Option<f32>)> = Vec::new();
            if map_low == "world" {
                for tn in &self.game.task_npc_db.entries {
                    let wx = tn.pos_x as f32;
                    let wz = tn.pos_y as f32;
                    let wy_opt = if tn.pos_z > 0 { Some(tn.pos_z as f32) } else { None };
                    let d2 = (wx - center.x).powi(2) + (wz - center.z).powi(2);
                    if d2 <= 420.0 * 420.0 && self.game.npc_essences.contains_key(&tn.npc_id) {
                        npc_cands.push((d2, tn.npc_id, wx, wz, wy_opt));
                    }
                }
            }
            for sp in &self.game.coord_spawns {
                if sp.map_name == map_low && self.game.npc_essences.contains_key(&sp.template_id) {
                    let d2 = (sp.pos.x - center.x).powi(2) + (sp.pos.z - center.z).powi(2);
                    if d2 <= 420.0 * 420.0 {
                        let dup = npc_cands.iter().any(|(_, id, x, z, _)| {
                            *id == sp.template_id && (*x - sp.pos.x).abs() < 3.0 && (*z - sp.pos.z).abs() < 3.0
                        });
                        if !dup {
                            npc_cands.push((
                                d2,
                                sp.template_id,
                                sp.pos.x,
                                sp.pos.z,
                                if sp.pos.y > 1.0 { Some(sp.pos.y) } else { None },
                            ));
                        }
                    }
                }
            }
            npc_cands.sort_by(|a, b| a.0.partial_cmp(&b.0).unwrap_or(core::cmp::Ordering::Equal));

            for &(_, npc_id, wx, wz, wy_hint) in npc_cands.iter().take(28) {
                if spawned_npcs >= 14 {
                    break;
                }
                if let Some(info) = self.game.npc_essences.get(&npc_id) {
                    let trimmed = info.name.trim();
                    if trimmed.is_empty()
                        || trimmed.starts_with("N/A")
                        || trimmed.starts_with('_')
                        || trimmed.starts_with("09 ")
                    {
                        continue;
                    }
                    let ref_y = wy_hint.unwrap_or(center.y + 18.0) + 3.0;
                    let y = self.sample_active_ground_y(wx, ref_y, wz);
                    let eid = 10_000 + spawned_npcs as u32;
                    let yaw = (center.x - wx).atan2(center.z - wz);
                    self.entity_ecm_paths.insert(eid, info.ecm_path.clone());
                    if !info.greeting.is_empty() {
                        self.entity_greetings.insert(eid, info.greeting.clone());
                    }
                    self.world_entities.push(WorldEntity3D {
                        id: eid,
                        name: trimmed.to_string(),
                        title: String::new(),
                        kind: EntityVisualKind::Npc,
                        pos: Vec3::new(wx, y, wz),
                        yaw,
                        scale: 1.0,
                        primary_color: 0x2B6B58,
                        accent_color: 0xE8C468,
                        hp_ratio: 1.0,
                        selected: false,
                        flying: false,
                    });
                    spawned_npcs += 1;
                }
            }

            // 2. Real `configs/coord_data.txt` Monsters (`MONSTER_ESSENCE` Section 39)
            let mut mob_cands: Vec<(f32, u32, f32, f32, Option<f32>)> = Vec::new();
            for sp in &self.game.coord_spawns {
                if sp.map_name == map_low && self.game.monster_essences.contains_key(&sp.template_id)
                {
                    let d2 = (sp.pos.x - center.x).powi(2) + (sp.pos.z - center.z).powi(2);
                    if (36.0..=620.0 * 620.0).contains(&d2) {
                        mob_cands.push((
                            d2,
                            sp.template_id,
                            sp.pos.x,
                            sp.pos.z,
                            if sp.pos.y > 1.0 { Some(sp.pos.y) } else { None },
                        ));
                    }
                }
            }
            mob_cands.sort_by(|a, b| a.0.partial_cmp(&b.0).unwrap_or(core::cmp::Ordering::Equal));
            for &(_, mob_id, wx, wz, wy_hint) in mob_cands.iter().take(24) {
                if spawned_mobs >= 10 {
                    break;
                }
                if let Some(info) = self.game.monster_essences.get(&mob_id) {
                    let trimmed = info.name.trim();
                    if trimmed.is_empty()
                        || trimmed.starts_with("N/A")
                        || trimmed.starts_with('_')
                        || trimmed.starts_with("09 ")
                    {
                        continue;
                    }
                    let ref_y = wy_hint.unwrap_or(center.y + 18.0) + 3.0;
                    let y = self.sample_active_ground_y(wx, ref_y, wz);
                    let eid = 20_000 + spawned_mobs as u32;
                    let yaw = (center.x - wx).atan2(center.z - wz);
                    self.entity_ecm_paths.insert(eid, info.ecm_path.clone());
                    let att = if info.short_desc.is_empty() {
                        format!("Lv.{}", info.level)
                    } else {
                        format!("Lv.{}  {}", info.level, info.short_desc)
                    };
                    self.world_entities.push(WorldEntity3D {
                        id: eid,
                        name: trimmed.to_string(),
                        title: att,
                        kind: EntityVisualKind::Monster,
                        pos: Vec3::new(wx, y, wz),
                        yaw,
                        scale: 1.0,
                        primary_color: 0x7A2424,
                        accent_color: 0xFF7040,
                        hp_ratio: 1.0,
                        selected: false,
                        flying: false,
                    });
                    spawned_mobs += 1;
                }
            }
        }

        // Supplement with archetype NPCs/Monsters on dungeon/instance maps without `coord_data` entries
        if spawned_npcs == 0 {
            for (i, &(nm, ttl, ecm)) in REAL_NPC_ECMS.iter().enumerate() {
                let ang = (i as f32) * 1.04 + 0.35;
                let dist = 7.0 + (i as f32) * 1.8;
                let x = center.x + ang.cos() * dist;
                let z = center.z + ang.sin() * dist;
                let y = self.sample_active_ground_y(x, center.y + 4.0, z);
                let eid = 10_500 + i as u32;
                self.entity_ecm_paths.insert(eid, ecm.to_string());
                self.world_entities.push(WorldEntity3D {
                    id: eid,
                    name: nm.to_string(),
                    title: ttl.to_string(),
                    kind: EntityVisualKind::Npc,
                    pos: Vec3::new(x, y, z),
                    yaw: ang + core::f32::consts::PI,
                    scale: 1.0,
                    primary_color: 0x2B6B58,
                    accent_color: 0xE8C468,
                    hp_ratio: 1.0,
                    selected: false,
                    flying: false,
                });
            }
        }
        if spawned_mobs == 0 {
            for (i, &(nm, ttl, ecm)) in REAL_MONSTER_ECMS.iter().enumerate() {
                let ang = (i as f32) * 1.05 + 0.8;
                let dist = 16.0 + (i as f32) * 3.5;
                let x = center.x + ang.cos() * dist;
                let z = center.z + ang.sin() * dist;
                let y = self.sample_active_ground_y(x, center.y + 4.0, z);
                let eid = 20_500 + i as u32;
                self.entity_ecm_paths.insert(eid, ecm.to_string());
                self.world_entities.push(WorldEntity3D {
                    id: eid,
                    name: nm.to_string(),
                    title: ttl.to_string(),
                    kind: EntityVisualKind::Monster,
                    pos: Vec3::new(x, y, z),
                    yaw: ang + core::f32::consts::PI,
                    scale: 1.0,
                    primary_color: 0x7A2424,
                    accent_color: 0xFF7040,
                    hp_ratio: 1.0,
                    selected: false,
                    flying: false,
                });
            }
        }
    }

    pub fn start_online_login(&mut self) {
        self.play_click_sfx();
        let addr = self.server_addr_input.trim().to_string();
        let acct = self.account_input.trim().to_string();
        let pwd = self.password_input.clone();
        if acct.is_empty() {
            self.status_banner = "Enter an Account name (or press F5 for Offline Mode).".into();
            return;
        }
        self.status_banner = format!("Connecting to glinkd {addr} as '{acct}'...");
        self.screen = ClientScreenState::LoginWait;
        match self.net.connect_and_login(&addr, &acct, &pwd) {
            Ok(()) => {
                self.online_mode = true;
                self.status_banner = format!("Connected to {addr} — awaiting Challenge (op 1)...");
            }
            Err(e) => {
                self.online_mode = false;
                self.screen = ClientScreenState::Login;
                self.status_banner = format!("{e} — Press F5 for Offline Character Select!");
            }
        }
    }

    pub fn enter_offline_character_select(&mut self) {
        self.play_click_sfx();
        self.net.disconnect();
        self.online_mode = false;
        self.ensure_login_map_loaded();
        if self.roster.is_empty() {
            self.roster = build_offline_archetype_roster();
        }
        self.selected_role_idx = 0;
        self.pedestal_yaw_offset = 0.0;
        self.screen = ClientScreenState::CharacterSelect;
        self.status_banner = "Select a character or click [Create] to customize a new hero.".into();
    }

    pub fn enter_world_with_selected_role(&mut self) {
        self.play_click_sfx();
        if self.roster.is_empty() {
            self.screen = ClientScreenState::CreateCharacter;
            return;
        }
        let role = self.roster[self.selected_role_idx.min(self.roster.len() - 1)].clone();

        if self.online_mode && self.net.is_connected() {
            let _ = self.net.select_and_enter_role(role.role_id);
        }

        if self.game.active_map.map_name.eq_ignore_ascii_case("login") {
            let has_world = self
                .game
                .available_maps
                .iter()
                .any(|m| m.eq_ignore_ascii_case("world"));
            let target_map = if has_world { "world" } else { "a01" };
            let init_center = if has_world {
                if role.pos.0.is_finite() && (role.pos.0.abs() > 0.01 || role.pos.2.abs() > 0.01) {
                    Vec3::new(role.pos.0, role.pos.1, role.pos.2)
                } else {
                    // West Archosaur Plaza (`(529, 663)` = `(1292.0, 219.61, 1132.0)` in `world_38`)
                    Vec3::new(1292.0, 219.61, 1132.0)
                }
            } else {
                Vec3::ZERO
            };
            if self.game.load_map_by_name_at(target_map, init_center).is_ok() {
                self.reload_active_scene_3d();
            }
        }

        let is_midlands = self.game.active_map.map_name.eq_ignore_ascii_case("world");
        let (spawn_x, spawn_y_hint, spawn_z) =
            if role.pos.0.is_finite() && (role.pos.0.abs() > 0.01 || role.pos.2.abs() > 0.01) {
                (role.pos.0, Some(role.pos.1), role.pos.2)
            } else if is_midlands {
                // West Archosaur (`world_38`) facing East-Southeast across the Archosaur boulevard & bridges
                self.player_yaw = 2.18;
                self.cam_yaw = 2.18;
                (1292.0, Some(219.61), 1132.0)
            } else if let Some(prec) = self.game.active_map.precincts.first() {
                let mut target_x = 0.0f32;
                let mut target_z = 0.0f32;
                let mut count_near = 0usize;
                for orn in &self.game.active_map.scene.ornaments {
                    let dx = orn.pos.x - prec.spawn_pos.x;
                    let dz = orn.pos.z - prec.spawn_pos.z;
                    if dx * dx + dz * dz < 220.0 * 220.0 {
                        target_x += orn.pos.x;
                        target_z += orn.pos.z;
                        count_near += 1;
                    }
                }
                let (aim_x, aim_z) = if count_near > 0 {
                    (target_x / count_near as f32, target_z / count_near as f32)
                } else {
                    (0.0, 0.0)
                };
                let yaw = (aim_x - prec.spawn_pos.x).atan2(aim_z - prec.spawn_pos.z);
                self.player_yaw = yaw;
                self.cam_yaw = yaw;
                (prec.spawn_pos.x, Some(prec.spawn_pos.y), prec.spawn_pos.z)
            } else {
                (0.0, None, 0.0)
            };
        let terrain_y = self.game.active_map.sample_world_height(spawn_x, spawn_z);
        let ref_y = spawn_y_hint
            .filter(|y| y.is_finite())
            .unwrap_or(terrain_y + 30.0);
        let spawn_y = self.sample_active_ground_y(spawn_x, ref_y + 4.0, spawn_z);

        let host = CecHostPlayer::new(
            role.role_id,
            role.name.clone(),
            role.occupation as i32,
            role.level.max(1) as u32,
            Vec3::new(spawn_x, spawn_y, spawn_z),
        );
        let class_skills = ElementSkill::skills_for_class(role.occupation as i32);
        for slot in 0..8 {
            if let Some(sk) = class_skills.get(slot) {
                self.quickbar_skills[slot] = sk.id;
            }
        }

        self.game.enter_world(host);
        self.screen = ClientScreenState::InWorld;
        self.modal = InWorldModal::None;
        self.sync_precinct_bgm(spawn_x, spawn_z);
        self.populate_world_entities();
        self.chat_log.push((
            0xFFFF_DF88,
            format!(
                "[World] Entered '{}' as {} (Lv.{} {}) at ({:.1}, {:.1}, {:.1}).",
                self.game.active_map.map_name,
                role.name,
                role.level,
                role.occupation_name(),
                spawn_x,
                spawn_y,
                spawn_z
            ),
        ));
    }

    pub fn cast_quickbar_slot(&mut self, slot: usize) {
        if slot >= 8 || self.skill_cooldowns[slot] > 0.01 {
            return;
        }
        let sk_id = self.quickbar_skills[slot];
        let Some(sk) = ElementSkill::create(sk_id, 10) else {
            return;
        };
        let params = sk.evaluate_level_params();
        let mp_cost = params.mp_cost.round() as i32;
        if self.host_mp < mp_cost {
            self.chat_log
                .push((0xFFFF_7A7A, "[Skill] Not enough Mana!".into()));
            return;
        }
        self.host_mp -= mp_cost;
        self.host_chi = (self.host_chi + params.chi_gain - params.chi_cost).clamp(0, 399);
        self.skill_cooldowns[slot] = params.cooldown_s.clamp(1.2, 18.0);
        self.player_attack_timer = 0.95;
        self.play_click_sfx();

        let origin = self
            .game
            .host_player
            .as_ref()
            .map(|p| p.position)
            .unwrap_or_default();
        self.scene_3d
            .gfx_manager
            .spawn_burst(origin, 0xFFFF_E488, 0x0058_B8FF, 18, 2.2, 0.30);
        let mut effect_pos = origin;

        if self.selected_entity_id.is_none() {
            if let Some(nearest) = self
                .world_entities
                .iter()
                .filter(|e| e.kind == EntityVisualKind::Monster)
                .min_by(|a, b| {
                    let da = (a.pos.x - origin.x).powi(2) + (a.pos.z - origin.z).powi(2);
                    let db = (b.pos.x - origin.x).powi(2) + (b.pos.z - origin.z).powi(2);
                    da.partial_cmp(&db).unwrap_or(core::cmp::Ordering::Equal)
                })
            {
                let nid = nearest.id;
                self.select_entity(Some(nid));
            }
        }

        if self.online_mode && self.net.is_connected() {
            let tlist: Vec<u32> = self.selected_entity_id.into_iter().collect();
            let _ = self.net.send_c2s_cast_skill(sk_id, 0, &tlist);
        }

        if let Some(tid) = self.selected_entity_id {
            if let Some(ent) = self.world_entities.iter_mut().find(|e| e.id == tid) {
                effect_pos = ent.pos;
                let dir_to_target = ent.pos.sub(origin);
                if dir_to_target.x.abs() > 0.05 || dir_to_target.z.abs() > 0.05 {
                    self.player_yaw = dir_to_target.x.atan2(dir_to_target.z);
                }
                let sk_en_name = self.game.english_skill_name(sk.stub.id);
                if ent.kind == EntityVisualKind::Monster {
                    let dmg = params.flat_bonus_damage.max(480) + ((sk_id * 53) % 640) as i32;
                    self.scene_3d
                        .gfx_manager
                        .spawn_burst(effect_pos, 0xFFFF_A848, 0x00FF_2010, 26, 3.1, 0.36);
                    ent.hp_ratio -= (dmg as f32) / 9500.0;
                    let ent_name = ent.name.clone();
                    if ent.hp_ratio <= 0.0 {
                        ent.hp_ratio = 1.0;
                        self.chat_log.push((
                            0xFFFF_D86B,
                            format!(
                                "[Combat] [{}] (#{}) defeated {} for {} dmg! (+4,200 EXP)",
                                sk_en_name, sk.stub.id, ent_name, dmg
                            ),
                        ));
                    } else {
                        self.chat_log.push((
                            0xFF9E_F59E,
                            format!(
                                "[Combat] [{}] (#{}) hit {} for {} dmg!",
                                sk_en_name, sk.stub.id, ent_name, dmg
                            ),
                        ));
                    }
                }
            }
        } else {
            let sk_en_name = self.game.english_skill_name(sk.stub.id);
            self.chat_log.push((
                0xFF8C_E8FF,
                format!("[Skill] Cast [{}] (#{}, Lv.10).", sk_en_name, sk.stub.id),
            ));
        }

        let sk_en_name = self.game.english_skill_name(sk.stub.id);
        // Play spatial 3D skill cast SFX (`sfx.pck` `.wav` or `.ogg`) panned to `effect_pos`!
        let (lg, rg) = self
            .spatial_mixer
            .compute_stereo_gains(effect_pos, 4.0, 52.0);
        for sfx_cand in [
            "sfx\\skill\\common\\cast.wav",
            "sfx\\interface\\skill.wav",
            "sfx\\interface\\clickb.wav",
        ] {
            if let Ok(sfx_bytes) = self.game.vfs.read_file(sfx_cand) {
                let _ = self.audio.play_spatial_audio_bytes(&sfx_bytes, lg, rg);
                break;
            }
        }
        self.active_effects.push(CastEffect {
            pos: effect_pos,
            skill_name: sk_en_name,
            color: 0xFF58_D8FF,
            ttl: 1.15,
        });
    }

    fn select_entity(&mut self, id: Option<u32>) {
        self.selected_entity_id = id;
        for e in &mut self.world_entities {
            e.selected = Some(e.id) == id;
        }
        if self.online_mode && self.net.is_connected() {
            if let Some(tid) = id {
                let _ = self.net.send_c2s_select_target(tid);
            }
        }
    }

    pub fn on_char_input(&mut self, ch: char) {
        if ch.is_control() {
            return;
        }
        match self.screen {
            ClientScreenState::Login => match self.login_focus {
                LoginFocusField::ServerAddr => {
                    if self.server_addr_input.len() < 48 {
                        self.server_addr_input.push(ch);
                    }
                }
                LoginFocusField::Account => {
                    if self.account_input.len() < 32 {
                        self.account_input.push(ch);
                    }
                }
                LoginFocusField::Password => {
                    if self.password_input.len() < 32 {
                        self.password_input.push(ch);
                    }
                }
            },
            ClientScreenState::CreateCharacter => {
                if self.create_name_input.chars().count() < 16 {
                    self.create_name_input.push(ch);
                }
            }
            ClientScreenState::InWorld => {
                if self.modal == InWorldModal::DevConsole && ch != '`' && ch != '~' {
                    if self.console_input.len() < 96 {
                        self.console_input.push(ch);
                    }
                } else if self.chat_active && self.chat_input.len() < 120 {
                    self.chat_input.push(ch);
                }
            }
            _ => {}
        }
    }

    pub fn on_key_down(&mut self, vk: u32) {
        if vk == VK_F5 && self.screen != ClientScreenState::InWorld {
            self.enter_offline_character_select();
            return;
        }

        match self.screen {
            ClientScreenState::Login => match vk {
                VK_BACK => match self.login_focus {
                    LoginFocusField::ServerAddr => {
                        self.server_addr_input.pop();
                    }
                    LoginFocusField::Account => {
                        self.account_input.pop();
                    }
                    LoginFocusField::Password => {
                        self.password_input.pop();
                    }
                },
                VK_TAB => {
                    self.login_focus = match self.login_focus {
                        LoginFocusField::Account => LoginFocusField::Password,
                        LoginFocusField::Password => LoginFocusField::Account,
                        LoginFocusField::ServerAddr => LoginFocusField::Account,
                    };
                }
                VK_RETURN => self.start_online_login(),
                VK_ESCAPE => {
                    if self.show_server_picker {
                        self.show_server_picker = false;
                    } else {
                        self.should_quit = true;
                    }
                }
                _ => {}
            },
            ClientScreenState::LoginWait => {
                if vk == VK_ESCAPE {
                    self.net.disconnect();
                    self.screen = ClientScreenState::Login;
                    self.status_banner = "Login cancelled.".into();
                }
            }
            ClientScreenState::CharacterSelect => match vk {
                VK_RETURN => self.enter_world_with_selected_role(),
                VK_ESCAPE => {
                    self.net.disconnect();
                    self.screen = ClientScreenState::Login;
                }
                0x26 => {
                    if !self.roster.is_empty() {
                        self.selected_role_idx =
                            (self.selected_role_idx + self.roster.len() - 1) % self.roster.len();
                        self.pedestal_yaw_offset = 0.0;
                    }
                }
                0x28 | VK_TAB => {
                    if !self.roster.is_empty() {
                        self.selected_role_idx = (self.selected_role_idx + 1) % self.roster.len();
                        self.pedestal_yaw_offset = 0.0;
                    }
                }
                0x25 => self.pedestal_yaw_offset -= 0.22,
                0x27 => self.pedestal_yaw_offset += 0.22,
                _ => {}
            },
            ClientScreenState::CreateCharacter => match vk {
                VK_BACK => {
                    self.create_name_input.pop();
                }
                VK_RETURN => self.confirm_create_character(),
                VK_ESCAPE => self.screen = ClientScreenState::CharacterSelect,
                0x25 => self.pedestal_yaw_offset -= 0.22,
                0x27 => self.pedestal_yaw_offset += 0.22,
                0x09 | 0x21 | 0x22 => {
                    // Tab / PgUp / PgDn — Cycle official `userdata/character/customize/*.ini` named presets!
                    let cls = self.create_occupation.min(7);
                    let gen = clamp_gender_for_class(cls, self.create_gender);
                    if let Some(presets) = self
                        .game
                        .customize_catalog
                        .by_class_gender
                        .get(&(cls, gen))
                    {
                        if !presets.is_empty() {
                            if vk == 0x21 {
                                self.named_preset_cursor =
                                    (self.named_preset_cursor + presets.len() - 1) % presets.len();
                            } else {
                                self.named_preset_cursor =
                                    (self.named_preset_cursor + 1) % presets.len();
                            }
                            let (preset_name, preset_ini) = &presets[self.named_preset_cursor];
                            self.status_banner = format!(
                                "Preset [{}/{}]: {} (FaceID={} HairID={})",
                                self.named_preset_cursor + 1,
                                presets.len(),
                                preset_name,
                                preset_ini.id_face_tex,
                                preset_ini.id_hair_model
                            );
                            self.scene_3d.set_custom_appearance(
                                cls as i32,
                                gen,
                                self.create_appearance_preset,
                                preset_ini.clone(),
                            );
                            self.play_click_sfx();
                        }
                    }
                }
                VK_OEM_4 | VK_OEM_6 | 0x26 | 0x28 => {
                    let cls = self.create_occupation as i32;
                    let gen = clamp_gender_for_class(self.create_occupation, self.create_gender);
                    let mut ini = self
                        .scene_3d
                        .get_custom_appearance(cls, gen, self.create_appearance_preset);
                    let delta: i16 = if vk == VK_OEM_6 || vk == 0x26 { 14 } else { -14 };
                    if vk == 0x26 || vk == 0x28 {
                        ini.head_scale = (ini.head_scale as i16 + delta).clamp(64, 192) as u8;
                        ini.scale_face_h = (ini.scale_face_h as i16 + delta).clamp(64, 192) as u8;
                    } else {
                        ini.up_scale = (ini.up_scale as i16 + delta).clamp(64, 192) as u8;
                        ini.waist_scale = (ini.waist_scale as i16 - delta / 2).clamp(64, 192) as u8;
                        ini.arm_width = (ini.arm_width as i16 + delta).clamp(64, 192) as u8;
                        ini.leg_width = (ini.leg_width as i16 + delta).clamp(64, 192) as u8;
                    }
                    self.status_banner = format!(
                        "Live Morph: Head={} FaceW={} Chest={} Waist={}",
                        ini.head_scale, ini.scale_face_h, ini.up_scale, ini.waist_scale
                    );
                    self.scene_3d
                        .set_custom_appearance(cls, gen, self.create_appearance_preset, ini);
                }
                _ => {}
            },
            ClientScreenState::InWorld => {
                if self.modal == InWorldModal::DevConsole {
                    match vk {
                        VK_BACK => {
                            self.console_input.pop();
                        }
                        VK_RETURN => {
                            let cmd = self.console_input.trim().to_string();
                            self.console_input.clear();
                            if !cmd.is_empty() {
                                self.execute_console_command(&cmd);
                            }
                        }
                        VK_ESCAPE | VK_OEM_3 | VK_F12 => self.modal = InWorldModal::None,
                        _ => {}
                    }
                    return;
                }

                if self.chat_active {
                    match vk {
                        VK_BACK => {
                            self.chat_input.pop();
                        }
                        VK_RETURN => {
                            let msg = self.chat_input.trim().to_string();
                            self.chat_input.clear();
                            self.chat_active = false;
                            if !msg.is_empty() {
                                if msg.starts_with('/') || msg.starts_with("d_") {
                                    self.execute_console_command(msg.trim_start_matches('/'));
                                } else {
                                    if self.online_mode && self.net.is_connected() {
                                        let _ = self.net.send_public_chat(&msg);
                                    }
                                    let sender = self
                                        .game
                                        .host_player
                                        .as_ref()
                                        .map(|p| p.name.as_str())
                                        .unwrap_or("You");
                                    self.chat_log
                                        .push((0xFFFF_FFFF, format!("[Common] {sender}: {msg}")));
                                }
                            }
                        }
                        VK_ESCAPE => {
                            self.chat_input.clear();
                            self.chat_active = false;
                        }
                        _ => {}
                    }
                    return;
                }

                match vk {
                    VK_RETURN => self.chat_active = true,
                    VK_OEM_3 | VK_F12 => self.modal = InWorldModal::DevConsole,
                    VK_ESCAPE => {
                        if self.modal != InWorldModal::None {
                            self.modal = InWorldModal::None;
                        } else if self.selected_entity_id.is_some() {
                            self.select_entity(None);
                        } else {
                            self.ensure_login_map_loaded();
                            self.screen = ClientScreenState::CharacterSelect;
                        }
                    }
                    VK_TAB => {
                        let monsters: Vec<u32> = self
                            .world_entities
                            .iter()
                            .filter(|e| e.kind == EntityVisualKind::Monster)
                            .map(|e| e.id)
                            .collect();
                        if !monsters.is_empty() {
                            let next = match self
                                .selected_entity_id
                                .and_then(|cur| monsters.iter().position(|&id| id == cur))
                            {
                                Some(idx) => monsters[(idx + 1) % monsters.len()],
                                None => monsters[0],
                            };
                            self.select_entity(Some(next));
                        }
                    }
                    0x46 => {
                        self.flying_mode = !self.flying_mode;
                        self.player_vel_y = 0.0;
                        if self.online_mode && self.net.is_connected() {
                            let _ = self.net.send_c2s_toggle_fly();
                        }
                        self.chat_log.push((
                            0xFF78_E8FF,
                            if self.flying_mode {
                                "[Aerogear] Flight activated (Space ascend, C descend).".into()
                            } else {
                                "[Aerogear] Landed on terrain.".into()
                            },
                        ));
                    }
                    0x43 if !self.flying_mode => self.toggle_modal(InWorldModal::CharacterSheet), // C
                    0x42 => self.toggle_modal(InWorldModal::Inventory), // B
                    0x4B | 0x52 => self.toggle_modal(InWorldModal::SkillBook), // K / R
                    0x51 => self.toggle_modal(InWorldModal::QuestLog),  // Q
                    0x4F => self.toggle_modal(InWorldModal::Boutique),  // O
                    0x4D => self.toggle_modal(InWorldModal::WorldMap),  // M
                    0x47 => self.toggle_modal(InWorldModal::NpcDialog), // G — Talk to selected/nearest NPC
                    0x45 => self.toggle_modal(InWorldModal::ActionPanel), // E — Actions & Emotes (`Win_Action`)
                    0x59 => self.toggle_modal(InWorldModal::FriendList),  // Y — Friend List (`Win_FriendList`)
                    0x55 => self.toggle_modal(InWorldModal::SystemSettings), // U — System/Video Settings (`Win_SettingSystem`)
                    0x48 => self.toggle_modal(InWorldModal::GuildManage), // H — Faction / Guild (`Win_GuildManage`)
                    0x54 => {
                        // T — Territory War Map (`GuildMap` — all 47 `domain.data` zones!)
                        if self.online_mode && self.net.is_connected() {
                            let _ = self.net.send_battle_get_map();
                        }
                        self.toggle_modal(InWorldModal::TerritoryMap);
                    }
                    0x50 => self.toggle_modal(InWorldModal::PetBag), // P — Pet Bag (`Win_PetList`)
                    0x4C => {
                        // L — Mail Inbox (`Win_MailList`)
                        if self.online_mode && self.net.is_connected() {
                            let _ = self.net.send_get_mail_list();
                        }
                        self.toggle_modal(InWorldModal::MailBox);
                    }
                    0x4A => {
                        // J — Auction House & Gold Exchange (`Win_AuctionList` / `Win_GoldTrade`)
                        if self.online_mode && self.net.is_connected() {
                            let _ = self.net.send_stock_account();
                        }
                        self.toggle_modal(InWorldModal::AuctionHouse);
                    }
                    0x58 => self.toggle_modal(InWorldModal::PlayerTrade), // X — Player Trade (`Win_Trade`)
                    0x56 => self.toggle_modal(InWorldModal::NpcShop),     // V — NPC Vendor (`Win_Shop`)
                    0x4E => self.toggle_modal(InWorldModal::Warehouse),   // N — Bank Warehouse (`Win_Storage`)
                    0x49 => self.toggle_modal(InWorldModal::CraftProduce), // I — Crafting (`Win_Produce`)
                    0x74 => {
                        // F5 — PK Protection & Safety Lock (`Win_PKSetting` / `Win_AutoLock`)
                        self.pvp_enabled = !self.pvp_enabled;
                        if self.online_mode && self.net.is_connected() {
                            let pkt = pw_gnet::encode_c2s_toggle_pk_mode(self.pvp_enabled);
                            if pkt.len() >= 2 {
                                let cmd = u16::from_le_bytes([pkt[0], pkt[1]]);
                                let _ = self.net.send_gamedata_c2s(cmd, &pkt[2..]);
                            }
                        }
                        self.toggle_modal(InWorldModal::PkAutolock);
                    }
                    0x75 => {
                        // F6 — Elder Equipment Refinement (`Win_EquipRefine` — cycles `+1..+12` weapon aura!)
                        if self.modal == InWorldModal::EquipRefine {
                            self.weapon_refine_level = (self.weapon_refine_level + 1) % 13;
                            self.play_click_sfx();
                        } else {
                            self.toggle_modal(InWorldModal::EquipRefine);
                        }
                    }
                    0x76 => self.toggle_modal(InWorldModal::GenieElf),    // F7 — Elemental Genie (`Win_ELFProp`)
                    0x77 => self.toggle_modal(InWorldModal::PlayerBooth), // F8 — Cat-Shop Booth (`Win_Booth`)
                    0x5A if self.modal == InWorldModal::WorldMap => {
                        // Z — Toggle Continent (`world.dds`) <-> Regional (`surfaces/maps/*.dds`) zoom!
                        self.world_map_regional_zoom = !self.world_map_regional_zoom;
                        self.play_click_sfx();
                    }
                    VK_F9 => {
                        let next_map = if self.game.active_map.map_name.eq_ignore_ascii_case("world")
                        {
                            "a01"
                        } else if self
                            .game
                            .available_maps
                            .iter()
                            .any(|m| m.eq_ignore_ascii_case("world"))
                        {
                            "world"
                        } else {
                            "a01"
                        };
                        self.execute_console_command(&format!("d_map {next_map}"));
                    }
                    VK_OEM_4 => self.time_of_day = (self.time_of_day - 0.75).rem_euclid(24.0),
                    VK_OEM_6 => self.time_of_day = (self.time_of_day + 0.75).rem_euclid(24.0),
                    0x31..=0x38 => self.cast_quickbar_slot((vk - 0x31) as usize),
                    _ => {}
                }
            }
        }
    }

    fn toggle_modal(&mut self, target: InWorldModal) {
        self.play_click_sfx();
        self.list_scroll = 0;
        self.modal = if self.modal == target {
            InWorldModal::None
        } else {
            target
        };
    }

    fn confirm_create_character(&mut self) {
        self.play_click_sfx();
        let name = if self.create_name_input.trim().is_empty() {
            "Archosaur".to_string()
        } else {
            self.create_name_input.trim().to_string()
        };
        let occ = self.create_occupation.min(7);
        let gender = clamp_gender_for_class(occ, self.create_gender);
        let rid = 4096 + self.roster.len() as u32;
        self.role_appearance_presets
            .insert(rid, self.create_appearance_preset);
        let role = CharacterSummary {
            role_id: rid,
            name,
            gender,
            race: race_for_class(occ) as u8,
            occupation: occ,
            level: 1,
            level2: 0,
            pos: (0.0, 0.0, 0.0),
            world_tag: 1,
        };
        self.roster.push(role);
        self.selected_role_idx = self.roster.len() - 1;
        self.pedestal_yaw_offset = 0.0;
        self.screen = ClientScreenState::CharacterSelect;
    }

    fn execute_console_command(&mut self, raw: &str) {
        self.console_log.push(format!("> {raw}"));
        let parts: Vec<&str> = raw.split_whitespace().collect();
        let Some(&cmd) = parts.first() else {
            return;
        };
        match cmd.to_ascii_lowercase().as_str() {
            "d_fly" | "fly" => {
                self.flying_mode = !self.flying_mode;
                self.console_log
                    .push(format!("Flight = {}", self.flying_mode));
            }
            "d_speed" | "speed" => {
                if let Some(v) = parts.get(1).and_then(|s| s.parse::<f32>().ok()) {
                    self.move_speed = v.clamp(2.0, 120.0);
                    self.console_log
                        .push(format!("Move speed = {:.1} m/s", self.move_speed));
                }
            }
            "d_time" | "time" => {
                if let Some(v) = parts.get(1).and_then(|s| s.parse::<f32>().ok()) {
                    self.time_of_day = v.rem_euclid(24.0);
                    self.console_log
                        .push(format!("Time of day = {:.2}h", self.time_of_day));
                }
            }
            "d_goto" | "goto" => {
                if let (Some(x), Some(z)) = (
                    parts.get(1).and_then(|s| s.parse::<f32>().ok()),
                    parts.get(2).and_then(|s| s.parse::<f32>().ok()),
                ) {
                    self.teleport_to_world_pos(x, z, Some("Console d_goto"));
                    let y = self
                        .game
                        .host_player
                        .as_ref()
                        .map(|p| p.position.y)
                        .unwrap_or(220.0);
                    self.console_log
                        .push(format!("Teleported to ({x:.1}, {y:.1}, {z:.1})"));
                }
            }
            "d_map" | "map" => {
                if let Some(&mname) = parts.get(1) {
                    match self.game.load_map_by_name(mname) {
                        Ok(()) => {
                            self.reload_active_scene_3d();
                            let (sx, sy_hint, sz) =
                                if self.game.active_map.map_name.eq_ignore_ascii_case("world") {
                                    (1292.0, Some(219.61), 1132.0)
                                } else if let Some(prec) = self.game.active_map.precincts.first() {
                                    (prec.spawn_pos.x, Some(prec.spawn_pos.y), prec.spawn_pos.z)
                                } else {
                                    (0.0, None, 0.0)
                                };
                            let y = self.sample_active_ground_y(
                                sx,
                                sy_hint.unwrap_or(230.0) + 6.0,
                                sz,
                            );
                            if let Some(p) = &mut self.game.host_player {
                                p.position = Vec3::new(sx, y, sz);
                            }
                            self.sync_precinct_bgm(sx, sz);
                            self.populate_world_entities();
                            self.console_log
                                .push(format!("Loaded map '{mname}' at ({sx:.1}, {y:.1}, {sz:.1})!"));
                        }
                        Err(e) => self.console_log.push(format!("Map error: {e}")),
                    }
                }
            }
            "d_skill" | "skill" => {
                if let Some(sid) = parts.get(1).and_then(|s| s.parse::<u32>().ok()) {
                    self.quickbar_skills[0] = sid;
                    self.cast_quickbar_slot(0);
                }
            }
            "d_refine" | "refine" => {
                if let Some(lv) = parts.get(1).and_then(|s| s.parse::<u8>().ok()) {
                    self.weapon_refine_level = lv.min(12);
                    self.console_log.push(format!(
                        "Weapon Mirage Refinement set to +{}",
                        self.weapon_refine_level
                    ));
                }
            }
            "d_pvp" | "pvp" => {
                self.pvp_enabled = !self.pvp_enabled;
                if self.online_mode && self.net.is_connected() {
                    let pkt = pw_gnet::encode_c2s_toggle_pk_mode(self.pvp_enabled);
                    if pkt.len() >= 2 {
                        let c2s = u16::from_le_bytes([pkt[0], pkt[1]]);
                        let _ = self.net.send_gamedata_c2s(c2s, &pkt[2..]);
                    }
                }
                self.console_log
                    .push(format!("PK Mode = {}", self.pvp_enabled));
            }
            "d_c2scmd" => {
                if let Some(op) = parts.get(1).and_then(|s| s.parse::<u16>().ok()) {
                    if self.online_mode && self.net.is_connected() {
                        let _ = self.net.send_gamedata_c2s(op, &[]);
                    }
                    self.console_log
                        .push(format!("Dispatched inner gs c2s_cmd={op}"));
                }
            }
            "d_help" | "help" => {
                self.console_log.push(
                    "Commands: d_fly, d_speed <m/s>, d_time <0..24>, d_goto <x> <z>, d_map <name>, d_skill <id>, d_refine <0..12>, d_pvp, d_c2scmd <op>".into(),
                );
            }
            _ => self.console_log.push(format!("Unknown command '{cmd}' (type d_help)")),
        }
    }

    pub fn on_mouse_wheel(&mut self, delta: i32) {
        if self.screen == ClientScreenState::InWorld {
            if self.modal != InWorldModal::None {
                if delta < 0 {
                    self.list_scroll = self.list_scroll.saturating_add(3);
                } else {
                    self.list_scroll = self.list_scroll.saturating_sub(3);
                }
            } else {
                let step = if delta > 0 { -1.2 } else { 1.2 };
                self.cam_dist = (self.cam_dist + step).clamp(3.0, 38.0);
            }
        }
    }

    pub fn on_mouse_click(&mut self, mx: i32, my: i32, fb_w: u32, fb_h: u32) {
        self.sync_aui_state();

        if self.screen != ClientScreenState::InWorld {
            if let Some((dlg, ctrl, cmd)) =
                self.login_ui
                    .hit_test(&self.game.aui_manager, mx, my, fb_w, fb_h)
            {
                self.handle_login_aui_command(&dlg, &ctrl, &cmd);
            }
            return;
        }

        // Interactive `WorldMap` (`M`): check `Win_Bigmap` / `Win_BigMapMark` buttons first, then click map to teleport!
        if self.modal == InWorldModal::WorldMap {
            if let Some((dlg, ctrl, cmd)) =
                self.ingame_ui
                    .hit_test(&self.game.aui_manager, mx, my, fb_w, fb_h)
            {
                self.handle_ingame_aui_command(&dlg, &ctrl, &cmd);
                return;
            }
            if mx >= 0 && mx < fb_w as i32 && my >= 0 && my < fb_h as i32 {
                self.play_click_sfx();
                let fx = (mx as f32) / (fb_w.max(1) as f32);
                let fy = (my as f32) / (fb_h.max(1) as f32);
                let (wx, wz) = if self.world_map_regional_zoom {
                    let p = self
                        .game
                        .host_player
                        .as_ref()
                        .map(|h| h.position)
                        .unwrap_or(MapInstanceBundle::ARCHOSAUR_DEFAULT_CENTER);
                    if let Some(trn) = &self.game.active_map.trn2_full {
                        let (sr, sc, _) = trn.sub_trn_for_world_pos(p.x, p.z);
                        let (ox, oz_top, _, _) = trn.sub_trn_bounds(sr, sc);
                        (ox + fx * 1024.0, oz_top - fy * 1024.0)
                    } else {
                        ((fx - 0.5) * 1024.0, (0.5 - fy) * 1024.0)
                    }
                } else {
                    ((fx - 0.5) * 15018.667, (0.5 - fy) * 11264.0)
                };
                let mut chosen = (wx, wz, None::<String>);
                for wt in &self.game.active_map.world_targets {
                    let d2 = (wt.pos.x - wx).powi(2) + (wt.pos.z - wz).powi(2);
                    if d2 <= 240.0 * 240.0 {
                        chosen = (wt.pos.x, wt.pos.z, Some(wt.name.clone()));
                        break;
                    }
                }
                let lbl = chosen.2.clone();
                self.modal = InWorldModal::None;
                self.teleport_to_world_pos(chosen.0, chosen.1, lbl.as_deref().or(Some("WorldMap")));
                return;
            }
        }

        // Interactive `NpcDialog` (`Win_NPC` `Lst_Main` at `20, 292, 273, 101`)
        if self.modal == InWorldModal::NpcDialog {
            if let Some((lx, ly, lw, lh)) = self.ingame_ui.find_control_screen_rect(
                &self.game.aui_manager,
                "Win_NPC",
                "Lst_Main",
                fb_w,
                fb_h,
            ) {
                if mx >= lx && mx < lx + lw && my >= ly && my < ly + lh {
                    self.play_click_sfx();
                    let row = (my - ly - 4).max(0) / 22;
                    match row {
                        0 => self.modal = InWorldModal::WorldMap,
                        1 => self.modal = InWorldModal::Boutique,
                        2 => self.modal = InWorldModal::QuestLog,
                        _ => self.modal = InWorldModal::None,
                    }
                    return;
                }
            }
        }

        // Dispatch interactive `AUISlider` / `AUICheckBox` / `AUIComboBox` / `AUITreeView` state updates first
        if let Some(ev) = self
            .ingame_ui
            .on_mouse_down(&self.game.aui_manager, mx, my, fb_w, fb_h)
        {
            self.ingame_ui.pressed_control = None;
            self.handle_ingame_aui_command(&ev.dialog_name, &ev.control_name, &ev.command);
            return;
        }
        self.ingame_ui.pressed_control = None;

        if let Some((dlg, ctrl, cmd)) =
            self.ingame_ui
                .hit_test(&self.game.aui_manager, mx, my, fb_w, fb_h)
        {
            self.handle_ingame_aui_command(&dlg, &ctrl, &cmd);
            return;
        }
        if self
            .ingame_ui
            .is_point_inside_visible_dialog(&self.game.aui_manager, mx, my, fb_w, fb_h)
        {
            return;
        }

        // 3D viewport click: pick nearest visible NPC / Monster (`CECGameRun` screen-space ray/projection pick)
        if let Some(host) = &self.game.host_player {
            let focus = Vec3::new(host.position.x, host.position.y + 1.45, host.position.z);
            let cp = self.cam_pitch.cos();
            let sp = self.cam_pitch.sin();
            let look_dir =
                Vec3::new(self.cam_yaw.sin() * cp, -sp, self.cam_yaw.cos() * cp).normalized();
            let eye_pos = focus.sub(look_dir.scale(self.cam_dist));
            let cam_proj = A3DCamera::new_perspective(fb_w.max(64), fb_h.max(64), 56.0);
            let mut best: Option<(u32, i32)> = None;
            for ent in &self.world_entities {
                let torso = Vec3::new(ent.pos.x, ent.pos.y + 1.1, ent.pos.z);
                if let Some((sx, sy, _)) = project_world_to_screen(
                    eye_pos,
                    look_dir,
                    Vec3::UNIT_Y,
                    &cam_proj,
                    fb_w,
                    fb_h,
                    torso,
                ) {
                    let d2 = (sx - mx).pow(2) + (sy - my).pow(2);
                    if d2 <= 54 * 54 && best.map_or(true, |(_, bd)| d2 < bd) {
                        best = Some((ent.id, d2));
                    }
                }
            }
            if let Some((picked_id, _)) = best {
                self.play_click_sfx();
                let is_npc = self
                    .world_entities
                    .iter()
                    .find(|e| e.id == picked_id)
                    .map(|e| e.kind == EntityVisualKind::Npc)
                    .unwrap_or(false);
                self.select_entity(Some(picked_id));
                if self.online_mode && self.net.is_connected() {
                    let _ = self.net.send_c2s_select_target(picked_id);
                    if is_npc {
                        let _ = self.net.send_c2s_hello_npc(picked_id);
                    }
                }
                if is_npc {
                    self.modal = InWorldModal::NpcDialog;
                }
            }
        }
    }

    fn handle_login_aui_command(&mut self, dlg: &str, ctrl: &str, cmd: &str) {
        self.play_click_sfx();
        let d_low = dlg.to_ascii_lowercase();
        let c_low = ctrl.to_ascii_lowercase();
        let m_low = cmd.to_ascii_lowercase();

        if d_low == "win_login" {
            if c_low == "default_txt_account" {
                self.login_focus = LoginFocusField::Account;
            } else if c_low == "txt_password" {
                self.login_focus = LoginFocusField::Password;
            } else if c_low == "chk_forcelog" {
                self.force_login = !self.force_login;
            } else if c_low.contains("changeserver") || m_low.contains("changeserver") {
                if !self.game.server_list.is_empty() {
                    self.selected_server_idx =
                        (self.selected_server_idx + 1) % self.game.server_list.len();
                    self.server_addr_input =
                        self.game.server_list[self.selected_server_idx].addr.clone();
                }
            } else if m_low == "confirm" || c_low == "btn_game" {
                self.start_online_login();
            } else if m_low == "idcancel" || c_low == "btn_quit" {
                self.should_quit = true;
            }
            return;
        }

        if d_low == "win_loginwait" && (m_low == "idcancel" || c_low.contains("cancel")) {
            self.net.disconnect();
            self.screen = ClientScreenState::Login;
            return;
        }

        if d_low == "win_select" {
            for idx in 1..=8 {
                if c_low == format!("rdo_char{idx}") || m_low == format!("char{idx}") {
                    if idx - 1 < self.roster.len() {
                        self.selected_role_idx = idx - 1;
                        self.pedestal_yaw_offset = 0.0;
                    }
                    return;
                }
            }
            if m_low == "createaccount" || c_low == "btn_create" {
                self.create_occupation = 0;
                self.create_gender = 0;
                self.pedestal_yaw_offset = 0.0;
                self.screen = ClientScreenState::CreateCharacter;
            } else if m_low == "deleteaccount" || c_low == "btn_delete" {
                if !self.roster.is_empty() && self.roster.len() > 1 {
                    let rem = self.selected_role_idx.min(self.roster.len() - 1);
                    self.roster.remove(rem);
                    self.selected_role_idx = self.selected_role_idx.min(self.roster.len() - 1);
                }
            }
            return;
        }

        if d_low == "win_manage" && (m_low == "confirm" || c_low == "btn_game") {
            self.enter_world_with_selected_role();
            return;
        }
        if d_low == "win_manage2" && (m_low == "idcancel" || c_low == "btn_quit") {
            self.net.disconnect();
            self.screen = ClientScreenState::Login;
            return;
        }

        if d_low == "win_create" {
            if c_low == "default_charname" {
                return;
            }
            if c_low == "btn_racel" || c_low == "btn_racer" {
                let cur_race = race_for_class(self.create_occupation);
                let next_race = if c_low.ends_with('l') {
                    (cur_race + 3) % 4
                } else {
                    (cur_race + 1) % 4
                };
                self.create_occupation = RACE_CLASSES[next_race][0];
                self.create_gender =
                    clamp_gender_for_class(self.create_occupation, self.create_gender);
                self.pedestal_yaw_offset = 0.0;
            } else if c_low == "btn_professionl"
                || c_low == "btn_professionr"
                || m_low == "professionchg"
            {
                let r = race_for_class(self.create_occupation);
                let pair = RACE_CLASSES[r];
                self.create_occupation = if self.create_occupation == pair[0] {
                    pair[1]
                } else {
                    pair[0]
                };
                self.create_gender =
                    clamp_gender_for_class(self.create_occupation, self.create_gender);
                self.pedestal_yaw_offset = 0.0;
            } else if c_low == "btn_genderl" || c_low == "btn_genderr" || m_low == "genderchg" {
                self.create_gender =
                    clamp_gender_for_class(self.create_occupation, self.create_gender ^ 1);
                self.pedestal_yaw_offset = 0.0;
            } else if c_low.contains("facecustomize") || m_low == "face_customize" {
                self.create_appearance_preset = (self.create_appearance_preset + 1) % 4;
                self.status_banner = format!(
                    "Face / Hair / Armor Preset #{} applied live!",
                    self.create_appearance_preset + 1
                );
            } else if m_low == "confirm" || c_low == "btn_confirm" {
                self.confirm_create_character();
            } else if m_low == "idcancel" || c_low == "btn_cancel" {
                self.screen = ClientScreenState::CharacterSelect;
            }
        }
    }

    fn handle_ingame_aui_command(&mut self, dlg: &str, ctrl: &str, cmd: &str) {
        self.play_click_sfx();
        let d_low = dlg.to_ascii_lowercase();
        let c_low = ctrl.to_ascii_lowercase();
        let m_low = cmd.to_ascii_lowercase();

        if d_low == "win_main" {
            match m_low.as_str() {
                "wcharacter" => self.toggle_modal(InWorldModal::CharacterSheet),
                "winventory" => self.toggle_modal(InWorldModal::Inventory),
                "wskill" => self.toggle_modal(InWorldModal::SkillBook),
                "wquest" => self.toggle_modal(InWorldModal::QuestLog),
                "wmain2" => {
                    self.show_main2 = !self.show_main2;
                    if self.show_main2 {
                        self.show_main3 = false;
                    }
                }
                "wmain3" => {
                    self.show_main3 = !self.show_main3;
                    if self.show_main3 {
                        self.show_main2 = false;
                    }
                }
                _ => {}
            }
            return;
        }
        if d_low == "win_main2" {
            self.show_main2 = false;
            match m_low.as_str() {
                "waction" => self.toggle_modal(InWorldModal::ActionPanel),
                "wfriend" => self.toggle_modal(InWorldModal::FriendList),
                "wfaction" => self.toggle_modal(InWorldModal::GuildManage),
                "wpet" => self.toggle_modal(InWorldModal::PetBag),
                "wteam" => {
                    if self.team_members.is_empty() {
                        self.team_members.push(pw_gnet::GsTeamMemberInfo {
                            member_id: 2049,
                            level: 101,
                            combat_state: 0,
                            pk_level: 0,
                            hp: 9850,
                            mp: 4200,
                            max_hp: 10200,
                            max_mp: 4500,
                        });
                    } else {
                        self.team_members.clear();
                    }
                }
                "wbroadcast" => self.chat_active = true,
                _ => {}
            }
            return;
        }
        if d_low == "win_main3" {
            self.show_main3 = false;
            match m_low.as_str() {
                "wsetting" | "wquickkey" => self.toggle_modal(InWorldModal::SystemSettings),
                "whelp" => self.toggle_modal(InWorldModal::QuestLog),
                "chat" => self.chat_active = true,
                "repick" => {
                    self.modal = InWorldModal::None;
                    self.ensure_login_map_loaded();
                    self.screen = ClientScreenState::CharacterSelect;
                }
                "quitgame" => self.should_quit = true,
                _ => {}
            }
            return;
        }
        if d_low == "win_action" {
            if c_low == "bsccmd_01" {
                self.cast_quickbar_slot(0);
            } else if c_low == "bsccmd_04" || c_low == "bsccmd_05" {
                self.flying_mode = !self.flying_mode;
                if self.online_mode && self.net.is_connected() {
                    let _ = self.net.send_c2s_toggle_fly();
                }
            } else if c_low.starts_with("teamcmd_") {
                if self.team_members.is_empty() {
                    self.team_members.push(pw_gnet::GsTeamMemberInfo {
                        member_id: 2049,
                        level: 101,
                        combat_state: 0,
                        pk_level: 0,
                        hp: 9850,
                        mp: 4200,
                        max_hp: 10200,
                        max_mp: 4500,
                    });
                    self.chat_log
                        .push((0xFF9E_F59E, "[Squad] Squad formed (2/6 members).".into()));
                } else {
                    self.team_members.clear();
                    if self.online_mode && self.net.is_connected() {
                        let _ = self.net.send_c2s_team_leave();
                    }
                }
            } else if c_low.starts_with("tradecmd_") {
                self.modal = InWorldModal::PlayerTrade;
            } else if c_low.starts_with("facecmd_") {
                let idx = c_low[8..].parse::<u16>().unwrap_or(1);
                if self.online_mode && self.net.is_connected() {
                    let _ = self.net.send_c2s_do_emote(idx);
                }
                self.chat_log
                    .push((0xFFFF_DF88, format!("[Emote] Performed social emote #{idx}!")));
            } else if m_low == "idcancel" || c_low.contains("close") {
                self.modal = InWorldModal::None;
            }
            return;
        }
        if d_low == "win_petlist" {
            if c_low.contains("summon") || m_low.contains("summon") || c_low.contains("call") {
                if self.summoned_pet_idx.is_some() {
                    self.summoned_pet_idx = None;
                    if self.online_mode && self.net.is_connected() {
                        let _ = self.net.send_c2s_recall_pet();
                    }
                } else if !self.pet_slots.is_empty() {
                    self.summoned_pet_idx = Some(0);
                    if self.online_mode && self.net.is_connected() {
                        let _ = self.net.send_c2s_summon_pet(0);
                    }
                }
                return;
            }
        }
        if d_low == "win_settingsystem" {
            if c_low == "slider_range" {
                let (lv, _) = self.ingame_ui.get_slider("Win_SettingSystem", "Slider_Range", 4);
                self.scene_3d.fog_end = 450.0 + (lv as f32) * 140.0;
            } else if c_low == "slider_cloud" {
                let (lv, _) = self.ingame_ui.get_slider("Win_SettingSystem", "Slider_Cloud", 4);
                self.scene_3d.clouds_enabled = lv > 0;
            } else if c_low == "slider_music" {
                let (lv, _) = self.ingame_ui.get_slider("Win_SettingSystem", "Slider_Music", 100);
                self.game.video_audio_settings.music_vol = lv.clamp(0, 100) as u8;
                self.spatial_mixer.music_volume = (lv.clamp(0, 100) as f32) / 100.0;
            } else if c_low == "slider_ambience" {
                let (lv, _) =
                    self.ingame_ui
                        .get_slider("Win_SettingSystem", "Slider_Ambience", 100);
                self.game.video_audio_settings.sound_vol = lv.clamp(0, 100) as u8;
                self.spatial_mixer.sfx_volume = (lv.clamp(0, 100) as f32) / 100.0;
            } else if m_low == "idcancel" || m_low == "confirm" || c_low.contains("close") {
                self.modal = InWorldModal::None;
            }
            return;
        }
        if d_low == "win_map" {
            match m_low.as_str() {
                "treasurebag" => self.toggle_modal(InWorldModal::Boutique),
                "bigmap" => self.toggle_modal(InWorldModal::WorldMap),
                "roomin" => self.cam_dist = (self.cam_dist - 2.0).max(2.5),
                "roomout" => self.cam_dist = (self.cam_dist + 2.0).min(28.0),
                _ => {}
            }
            return;
        }
        if d_low == "win_bigmap" {
            match m_low.as_str() {
                "inc" => self.world_map_regional_zoom = true,
                "dec" => self.world_map_regional_zoom = false,
                "idcancel" => self.modal = InWorldModal::None,
                _ => {}
            }
            return;
        }
        if d_low == "win_npc" && (m_low == "back" || m_low == "idcancel") {
            self.modal = InWorldModal::None;
            return;
        }
        if d_low == "win_equiprefine" && (c_low.contains("refine") || m_low.contains("confirm")) {
            self.weapon_refine_level = (self.weapon_refine_level + 1) % 13;
            if self.online_mode && self.net.is_connected() {
                let pkt = pw_gnet::encode_c2s_refine_equip(0, 20042, 0);
                if pkt.len() >= 2 {
                    let _ = self
                        .net
                        .send_gamedata_c2s(u16::from_le_bytes([pkt[0], pkt[1]]), &pkt[2..]);
                }
            }
            self.chat_log.push((
                0xFFFF_DF88,
                format!("[Elder] Equipment refined to +{}!", self.weapon_refine_level),
            ));
            return;
        }
        if d_low == "win_shop" && (c_low.contains("repair") || m_low.contains("repair")) {
            if self.online_mode && self.net.is_connected() {
                let pkt = pw_gnet::encode_c2s_repair_all();
                if pkt.len() >= 2 {
                    let _ = self
                        .net
                        .send_gamedata_c2s(u16::from_le_bytes([pkt[0], pkt[1]]), &pkt[2..]);
                }
            }
            self.chat_log
                .push((0xFF9E_F59E, "[Merchant] All equipped gear repaired to 100%.".into()));
            return;
        }
        if d_low == "win_elfprop" && (c_low.contains("skill") || m_low.contains("cast")) {
            if self.online_mode && self.net.is_connected() {
                let tgt = [self.selected_entity_id.unwrap_or(0)];
                let pkt = pw_gnet::encode_c2s_cast_elf_skill(1, 0, &tgt);
                if pkt.len() >= 2 {
                    let _ = self
                        .net
                        .send_gamedata_c2s(u16::from_le_bytes([pkt[0], pkt[1]]), &pkt[2..]);
                }
            }
            self.chat_log
                .push((0xFF78_E8FF, "[Genie] Elemental Genie skill Unleashed!".into()));
            return;
        }
        if d_low.starts_with("win_quickbar") {
            for s in 1..=8 {
                if c_low.ends_with(&s.to_string()) {
                    self.cast_quickbar_slot(s - 1);
                    return;
                }
            }
        }
        if m_low == "idcancel" || c_low.contains("close") {
            self.modal = InWorldModal::None;
        }
    }

    pub fn tick(&mut self, dt: f32, input: &InputSnapshot) {
        let dt = dt.clamp(0.001, 0.1);
        self.anim_seconds += dt;

        // 1. Poll live `glinkd:29000` non-blocking TCP events (`pw-gnet`)
        let events = self.net.poll();
        for ev in events {
            match ev {
                GLinkEvent::Connected(addr) => {
                    self.status_banner = format!("TCP connected to {addr}...");
                }
                GLinkEvent::ChallengeReceived { version, algo, .. } => {
                    self.status_banner = format!(
                        "Challenge v0x{version:08x} (algo {algo}) -> sending Response (op 3)..."
                    );
                }
                GLinkEvent::KeyExchangeComplete => {
                    self.status_banner =
                        "RC4 + MPPC KeyExchange complete -> awaiting OnlineAnnounce (op 4)...".into();
                }
                GLinkEvent::OnlineAnnounce { user_id, .. } => {
                    self.roster.clear();
                    self.status_banner =
                        format!("Authenticated uid={user_id} -> requesting RoleList (op 82)...");
                }
                GLinkEvent::RoleAdded(role) => {
                    self.roster.push(role);
                }
                GLinkEvent::RoleListFinished(_) => {
                    self.selected_role_idx = 0;
                    self.pedestal_yaw_offset = 0.0;
                    self.screen = if self.roster.is_empty() {
                        ClientScreenState::CreateCharacter
                    } else {
                        ClientScreenState::CharacterSelect
                    };
                }
                GLinkEvent::EnteredWorld { role_id } => {
                    self.chat_log.push((
                        0xFF7C_FF8A,
                        format!("[GNET] EnterWorld confirmed for role_id={role_id}!"),
                    ));
                }
                GLinkEvent::GsNotifyPos { pos, world_tag } => {
                    if let Some(host) = &mut self.game.host_player {
                        host.position = Vec3::new(pos.0, pos.1, pos.2);
                    }
                    self.chat_log.push((
                        0xFF8C_E8FF,
                        format!(
                            "[GS] NOTIFY_POS tag={world_tag} ({:.1}, {:.1}, {:.1})",
                            pos.0, pos.1, pos.2
                        ),
                    ));
                }
                GLinkEvent::ChatMessage {
                    sender_id, text, ..
                } => {
                    self.chat_log
                        .push((0xFFE8_F4FF, format!("[Role {sender_id}]: {text}")));
                }
                GLinkEvent::GsDecoded(pkt) => match pkt {
                    GsS2cPacket::SelfInfo1(info) => {
                        if let Some(host) = &mut self.game.host_player {
                            host.position = Vec3::new(info.pos.0, info.pos.1, info.pos.2);
                            if info.level > 0 {
                                host.level = info.level as u32;
                            }
                        }
                    }
                    GsS2cPacket::ExtProp(ep) => {
                        if ep.max_hp > 0 {
                            self.host_max_hp = ep.max_hp;
                            self.host_hp = self.host_hp.min(ep.max_hp).max(1);
                        }
                        if ep.max_mp > 0 {
                            self.host_max_mp = ep.max_mp;
                            self.host_mp = self.host_mp.min(ep.max_mp);
                        }
                        if ep.run_speed > 1.0 {
                            self.move_speed = ep.run_speed * 2.2;
                        }
                    }
                    GsS2cPacket::NpcInfoList(list) => {
                        for n in list {
                            self.upsert_live_npc(n.nid, n.tid, n.pos, n.dir);
                        }
                    }
                    GsS2cPacket::NpcEnterSlice(n) => {
                        self.upsert_live_npc(n.nid, n.tid, n.pos, n.dir);
                    }
                    GsS2cPacket::ObjectLeaveSlice { id } => {
                        self.world_entities.retain(|e| e.id != id);
                    }
                    GsS2cPacket::ObjectMove { id, dest, .. }
                    | GsS2cPacket::ObjectStopMove { id, pos: dest, .. } => {
                        if let Some(ent) = self.world_entities.iter_mut().find(|e| e.id == id) {
                            let dx = dest.0 - ent.pos.x;
                            let dz = dest.2 - ent.pos.z;
                            if dx * dx + dz * dz > 0.01 {
                                ent.yaw = dx.atan2(dz);
                            }
                            ent.pos = Vec3::new(dest.0, dest.1, dest.2);
                        }
                    }
                    GsS2cPacket::DamageInfo {
                        target_id, damage, ..
                    } => {
                        if let Some(ent) =
                            self.world_entities.iter_mut().find(|e| e.id == target_id)
                        {
                            ent.hp_ratio = (ent.hp_ratio - (damage as f32 / 5000.0)).clamp(0.0, 1.0);
                            self.active_effects.push(CastEffect {
                                pos: ent.pos,
                                skill_name: format!("-{damage}"),
                                color: 0xFFFF_5848,
                                ttl: 1.1,
                            });
                        }
                    }
                    GsS2cPacket::SkillData(sks) => {
                        for (slot, sk) in sks.iter().take(8).enumerate() {
                            self.quickbar_skills[slot] = sk.skill_id as u32;
                        }
                    }
                    GsS2cPacket::IconStateNotify { states, .. } => {
                        self.active_buff_states = states;
                    }
                    GsS2cPacket::TeamData { members, .. } => {
                        self.team_members = members;
                    }
                    GsS2cPacket::TeamMemberLeave { member_id, .. } => {
                        self.team_members.retain(|m| m.member_id != member_id);
                    }
                    GsS2cPacket::PetRoom { pets, .. } => {
                        self.pet_slots = pets
                            .into_iter()
                            .map(|p| {
                                let nm = self
                                    .game
                                    .monster_essences
                                    .get(&p.pet_tid)
                                    .map(|m| m.name.clone())
                                    .unwrap_or_else(|| format!("Companion #{}", p.pet_tid));
                                (nm, p)
                            })
                            .collect();
                    }
                    GsS2cPacket::SummonPet { pet_index, .. } => {
                        self.summoned_pet_idx = Some(pet_index as usize);
                    }
                    GsS2cPacket::RecallPet { .. } => {
                        self.summoned_pet_idx = None;
                    }
                    GsS2cPacket::LevelUp { id } => {
                        if let Some(host) = &mut self.game.host_player {
                            if host.role_id == id || id == 0 {
                                host.level += 1;
                                self.scene_3d.gfx_manager.spawn_burst(
                                    host.position,
                                    0xFFFF_F088,
                                    0x00FF_9820,
                                    48,
                                    3.6,
                                    0.46,
                                );
                            }
                        }
                    }
                    _ => {}
                },
                GLinkEvent::PrivateChat {
                    sender_name,
                    text,
                    ..
                } => {
                    let clean_name = pw_data::strip_cjk_fallback(&sender_name, "Cultivator");
                    let clean_txt = pw_data::strip_cjk_fallback(&text, "...");
                    self.chat_log
                        .push((0xFFFF_98F8, format!("[Whisper] {clean_name}: {clean_txt}")));
                }
                GLinkEvent::FactionChat { sender_id, text } => {
                    let clean_txt = pw_data::strip_cjk_fallback(&text, "...");
                    self.chat_log
                        .push((0xFF68_FF98, format!("[Faction #{sender_id}] {clean_txt}")));
                }
                GLinkEvent::FriendListUpdated(friends) => {
                    let mut rows = vec![format!("[-] Friends ({})", friends.len())];
                    for f in friends.iter().take(12) {
                        let nm = pw_data::strip_cjk_fallback(&f.name, &format!("Role #{}", f.role_id));
                        rows.push(format!("  ◆ {nm}"));
                    }
                    self.ingame_ui.list_items.insert(
                        ("Win_FriendList".to_string(), "Tv_FriendList".to_string()),
                        rows,
                    );
                }
                GLinkEvent::MailListReceived(mails) => {
                    self.mail_headers = mails;
                }
                GLinkEvent::NewMailAnnounced { .. } => {
                    self.chat_log
                        .push((0xFFFF_DF88, "[Mail] You have unread mail in your mailbox!".into()));
                }
                GLinkEvent::AuctionListReceived { items, .. } => {
                    self.auction_items = items
                        .into_iter()
                        .map(|a| (format!("Item #{}", a.item_id), a))
                        .collect();
                }
                GLinkEvent::StockAccountUpdated { cash, money } => {
                    self.stock_cash_gold = cash;
                    self.stock_coins = money;
                }
                GLinkEvent::BattleMapReceived(domains) => {
                    for d in domains {
                        if d.owner_faction_id != 0 {
                            self.territory_owners
                                .insert(d.domain_id, format!("Guild #{}", d.owner_faction_id));
                        }
                    }
                }
                GLinkEvent::FactionInfoUpdated(info) => {
                    self.faction_summary = info;
                }
                GLinkEvent::ServerError { code, message } => {
                    self.status_banner = format!("Server Error ({code}): {message}");
                    if self.screen == ClientScreenState::LoginWait {
                        self.screen = ClientScreenState::Login;
                    }
                }
                GLinkEvent::Disconnected(reason) => {
                    self.online_mode = false;
                    self.status_banner =
                        format!("Disconnected: {reason} (Press F5 for Offline Mode)");
                    if self.screen == ClientScreenState::LoginWait {
                        self.screen = ClientScreenState::Login;
                    }
                }
                _ => {}
            }
        }

        // 2. RMB drag: pedestal character rotation on Select/Create, or 3D camera orbit InWorld
        if input.rmb_down {
            if let Some((lx, ly)) = self.last_rmb_pos {
                let dx = (input.mouse_x - lx) as f32;
                let dy = (input.mouse_y - ly) as f32;
                if matches!(
                    self.screen,
                    ClientScreenState::CharacterSelect | ClientScreenState::CreateCharacter
                ) {
                    self.pedestal_yaw_offset += dx * 0.01;
                } else if self.screen == ClientScreenState::InWorld {
                    self.cam_yaw += dx * 0.0065;
                    self.cam_pitch = (self.cam_pitch + dy * 0.005).clamp(-0.65, 1.15);
                }
            }
            self.last_rmb_pos = Some((input.mouse_x, input.mouse_y));
        } else {
            self.last_rmb_pos = None;
        }

        // 3. In-World 3D HostPlayer movement, terrain collision, monster AI patrol, & skill cooldowns
        if self.screen == ClientScreenState::InWorld {
            self.player_attack_timer = (self.player_attack_timer - dt).max(0.0);
            for cd in &mut self.skill_cooldowns {
                *cd = (*cd - dt).max(0.0);
            }
            self.active_effects.retain_mut(|ef| {
                ef.ttl -= dt;
                ef.ttl > 0.0
            });
            if let Some(host) = &self.game.host_player {
                let p = host.position;
                self.spatial_mixer.listener_pos = p;
                self.spatial_mixer.listener_right =
                    Vec3::new(self.cam_yaw.cos(), 0.0, -self.cam_yaw.sin());
                for &vs in &self.active_visible_states {
                    self.scene_3d.gfx_manager.sync_visible_state_aura(vs, p);
                }
                let weap_pos = Vec3::new(
                    p.x + self.player_yaw.sin() * 0.48,
                    p.y + 1.08,
                    p.z + self.player_yaw.cos() * 0.48,
                );
                let refine_aura_argb = match self.weapon_refine_level {
                    0 => 0,
                    1..=4 => 0xFFA8_DCFF,  // +1..+4 Ice Blue Mirage Glow
                    5..=6 => 0xFFFF_D864,  // +5..+6 Golden Amber Glow
                    7..=9 => 0xFF68_FFB0,  // +7..+9 Emerald Jade Glow
                    10..=11 => 0xFFFF_5848, // +10..+11 Crimson Blaze Glow
                    _ => 0xFFE4_78FF,      // +12 Celestial Violet Glow
                };
                if refine_aura_argb != 0 {
                    self.scene_3d
                        .gfx_manager
                        .emit_weapon_glow_motes(weap_pos, refine_aura_argb, dt);
                }
            }
            self.scene_3d.gfx_manager.tick(dt);
            self.host_mp = (self.host_mp + (18.0 * dt) as i32).min(self.host_max_mp);

            // Gentle monster patrol on terrain so real `.ecm` monsters animate in the open world
            for (mi, ent) in self.world_entities.iter_mut().enumerate() {
                if ent.kind == EntityVisualKind::Monster {
                    let phase = self.anim_seconds * 0.55 + (mi as f32) * 1.3;
                    let turn = phase.sin() * 0.35 * dt;
                    ent.yaw += turn;
                    let step = 0.85 * dt;
                    let nx = ent.pos.x + ent.yaw.sin() * step;
                    let nz = ent.pos.z + ent.yaw.cos() * step;
                    let ty = self
                        .game
                        .active_map
                        .height_mesh
                        .sample_height(nx, nz)
                        .max(self.water_level);
                    ent.pos.x = nx;
                    ent.pos.z = nz;
                    ent.pos.y = self
                        .scene_3d
                        .sample_walkable_height(nx, ent.pos.y + 2.5, nz, ty);
                }
            }

            if !self.chat_active && self.modal != InWorldModal::DevConsole {
                let mut fwd_s = 0.0f32;
                let mut right_s = 0.0f32;
                if input.move_fwd {
                    fwd_s += 1.0;
                }
                if input.move_back {
                    fwd_s -= 1.0;
                }
                if input.move_right {
                    right_s += 1.0;
                }
                if input.move_left {
                    right_s -= 1.0;
                }

                let spd = self.move_speed
                    * if input.sprint { 1.85 } else { 1.0 }
                    * if self.flying_mode { 1.45 } else { 1.0 };

                let sy = self.cam_yaw.sin();
                let cy = self.cam_yaw.cos();
                let vx = sy * fwd_s + cy * right_s;
                let vz = cy * fwd_s - sy * right_s;
                let vlen = (vx * vx + vz * vz).sqrt();
                self.player_moving = vlen > 0.01;

                let mut new_host_pos: Option<Vec3> = None;
                let half_w = self.scene_3d.world_width * 0.495;
                let half_l = self.scene_3d.world_length * 0.495;

                if let Some(host) = &self.game.host_player {
                    let prev_pos = host.position;
                    let mut p = prev_pos;
                    if vlen > 0.01 {
                        let nx = vx / vlen;
                        let nz = vz / vlen;
                        p.x = (p.x + nx * spd * dt).clamp(-half_w, half_w);
                        p.z = (p.z + nz * spd * dt).clamp(-half_l, half_l);
                        self.player_yaw = nx.atan2(nz);
                    }
                    let ground_y = self.sample_active_ground_y(p.x, p.y, p.z);
                    if self.flying_mode {
                        if input.ascend {
                            p.y += spd * 0.75 * dt;
                        }
                        if input.descend {
                            p.y -= spd * 0.75 * dt;
                        }
                        p.y = p.y.clamp(ground_y, ground_y + 320.0);
                    } else if input.ascend && (p.y - ground_y).abs() < 0.25 {
                        self.player_vel_y = 9.5;
                        p.y += self.player_vel_y * dt;
                    } else {
                        self.player_vel_y -= 24.0 * dt;
                        p.y += self.player_vel_y * dt;
                        if p.y <= ground_y {
                            p.y = ground_y;
                            self.player_vel_y = 0.0;
                        }
                    }

                    if self.online_mode && self.net.is_connected() && self.player_moving {
                        self.move_packet_accum += dt;
                        if self.move_packet_accum >= 0.25 {
                            let ms = (self.move_packet_accum * 1000.0).round() as u16;
                            self.move_packet_accum = 0.0;
                            self.move_packet_stamp = self.move_packet_stamp.wrapping_add(1);
                            let cur_t = (prev_pos.x, prev_pos.y, prev_pos.z);
                            let nxt_t = (p.x, p.y, p.z);
                            let spd_cms = (spd * 256.0).round() as u16;
                            let mode = if self.flying_mode { 0x21 } else { 0x01 };
                            let _ = self.net.send_c2s_player_move(
                                cur_t,
                                nxt_t,
                                ms,
                                spd_cms,
                                mode,
                                self.move_packet_stamp,
                            );
                        }
                    }
                    new_host_pos = Some(p);
                }

                if let Some(p) = new_host_pos {
                    if let Some(host) = &mut self.game.host_player {
                        host.position = p;
                    }
                    if self.player_moving {
                        if self.game.active_map.set_load_center(p).unwrap_or(false) {
                            self.reload_active_scene_3d();
                            self.populate_world_entities();
                        }
                        self.scene_3d
                            .refresh_minimap_for_pos(&self.game.vfs, p.x, p.z);
                        self.sync_precinct_bgm(p.x, p.z);
                    }
                }
            } else {
                self.player_moving = false;
            }
        }
    }

    /// Synchronizes `login_ui` (`loginui.dcf`) and `ingame_ui` (`ingame.dcf`) controls with live game state.
    pub fn sync_aui_state(&mut self) {
        match self.screen {
            ClientScreenState::Login | ClientScreenState::LoginWait => {
                self.login_ui.hide_all_dialogs();
                self.login_ui.show_dialog("Win_Login", true);
                if self.screen == ClientScreenState::LoginWait {
                    self.login_ui.show_dialog("Win_LoginWait", true);
                    self.login_ui
                        .set_text("Win_LoginWait", "Txt_Message", self.status_banner.clone());
                }
                let srv_label = self
                    .game
                    .server_list
                    .get(self.selected_server_idx)
                    .map(|s| {
                        let compact = s.name.split_whitespace().collect::<Vec<_>>().join(" ");
                        compact.chars().take(15).collect::<String>()
                    })
                    .unwrap_or_else(|| self.server_addr_input.clone());
                self.login_ui
                    .set_text("Win_Login", "Txt_CurrentServer", srv_label);
                self.login_ui.set_edit_text(
                    "Win_Login",
                    "DEFAULT_Txt_Account",
                    self.account_input.clone(),
                );
                self.login_ui.set_edit_text(
                    "Win_Login",
                    "Txt_PassWord",
                    self.password_input.clone(),
                );
                self.login_ui.check_states.insert(
                    ("Win_Login".to_string(), "Chk_Forcelog".to_string()),
                    self.force_login,
                );
                match self.login_focus {
                    LoginFocusField::Account | LoginFocusField::ServerAddr => {
                        self.login_ui.focus_edit("Win_Login", "DEFAULT_Txt_Account");
                    }
                    LoginFocusField::Password => {
                        self.login_ui.focus_edit("Win_Login", "Txt_PassWord");
                    }
                }
            }
            ClientScreenState::CharacterSelect => {
                self.login_ui.hide_all_dialogs();
                self.login_ui.show_dialog("Win_Select", true);
                self.login_ui.show_dialog("Win_Manage", true);
                self.login_ui.show_dialog("Win_Manage2", true);
                self.login_ui.focused_edit = None;

                let sel_id = (self.selected_role_idx + 1) as i32;
                self.login_ui
                    .radio_groups
                    .insert(("Win_Select".to_string(), 1), sel_id);

                for slot in 1..=8 {
                    let rdo = format!("Rdo_Char{slot}");
                    let tname = format!("Txt_Name{slot}");
                    let tlvl = format!("Txt_Level{slot}");
                    if let Some(role) = self.roster.get(slot - 1) {
                        self.login_ui.set_control_visible("Win_Select", &rdo, true);
                        self.login_ui
                            .set_text("Win_Select", &tname, role.name.clone());
                        self.login_ui.set_text(
                            "Win_Select",
                            &tlvl,
                            format!("Lv.{} {}", role.level, role.occupation_name()),
                        );
                    } else {
                        self.login_ui.set_control_visible("Win_Select", &rdo, false);
                        self.login_ui.set_text("Win_Select", &tname, "");
                        self.login_ui.set_text("Win_Select", &tlvl, "");
                    }
                }
            }
            ClientScreenState::CreateCharacter => {
                self.login_ui.hide_all_dialogs();
                self.login_ui.show_dialog("Win_Create", true);
                let occ = self.create_occupation.min(7);
                let info_dlg = format!("Win_CreateInfo{occ}");
                self.login_ui.show_dialog(&info_dlg, true);

                let r_idx = race_for_class(occ);
                let tmp_summary = CharacterSummary {
                    role_id: 0,
                    name: String::new(),
                    gender: self.create_gender,
                    race: r_idx as u8,
                    occupation: occ,
                    level: 1,
                    level2: 0,
                    pos: (0.0, 0.0, 0.0),
                    world_tag: 1,
                };
                let g_str = if clamp_gender_for_class(occ, self.create_gender) == 0 {
                    "Male"
                } else {
                    "Female"
                };
                self.login_ui
                    .set_text("Win_Create", "Combo_Race", RACE_NAMES[r_idx]);
                self.login_ui.set_text(
                    "Win_Create",
                    "Combo_Profession",
                    tmp_summary.occupation_name(),
                );
                self.login_ui.set_text("Win_Create", "Combo_Gender", g_str);
                self.login_ui.set_edit_text(
                    "Win_Create",
                    "DEFAULT_CharName",
                    self.create_name_input.clone(),
                );
                self.login_ui.focus_edit("Win_Create", "DEFAULT_CharName");
            }
            ClientScreenState::InWorld => {
                self.ingame_ui.hide_all_dialogs();
                if self.modal == InWorldModal::WorldMap {
                    self.ingame_ui.show_dialog("Win_Bigmap", true);
                    self.ingame_ui.show_dialog("Win_BigMapMark", true);
                    return;
                }

                for hud_dlg in [
                    "Win_Hpmpxp",
                    "Win_Map",
                    "Win_Chat",
                    "Win_ChatSmall",
                    "Win_Quickbar8Ha",
                    "Win_Quickbar9Va",
                    "Win_Main",
                ] {
                    self.ingame_ui.show_dialog(hud_dlg, true);
                }

                // `Win_Main` (`winmain.dtf`): hide collapsed `Frame_System1` so expanded `Frame_System2` + all 6 icons show cleanly
                self.ingame_ui
                    .set_control_visible("Win_Main", "Frame_System1", false);
                self.ingame_ui
                    .set_control_visible("Win_Main", "Frame_System2", true);

                // `CDlgChat` (`chat.dtf`): `Img_Back0` (transparent) is active by default (`real_12_inworld_hud.png`),
                // and all messages wrap & clip strictly inside `Win_Chat::Txt_Content` (`0,0,315,128`) right above the chat bar!
                self.ingame_ui.show_dialog("Win_ChatSmall", false);
                for bg_i in 1..=5 {
                    let bname = format!("Img_Back{bg_i}");
                    self.ingame_ui
                        .set_control_visible("Win_Chat", &bname, false);
                    self.ingame_ui
                        .set_control_visible("Win_ChatSmall", &bname, false);
                }
                let mut all_chat_lines = Vec::with_capacity(self.chat_log.len());
                for &(col, ref msg) in &self.chat_log {
                    let hex = format!("{:06X}", col & 0x00FF_FFFF);
                    all_chat_lines.push(format!("^{hex}{msg}"));
                }
                self.ingame_ui
                    .set_text("Win_ChatSmall", "Txt_Content", String::new());
                self.ingame_ui
                    .set_text("Win_Chat", "Txt_Content", all_chat_lines.join("\n"));
                let speech_str = if self.chat_active {
                    self.chat_input.clone()
                } else {
                    String::new()
                };
                self.ingame_ui
                    .set_edit_text("Win_Chat", "DEFAULT_Txt_Speech", speech_str);
                if self.chat_active {
                    self.ingame_ui
                        .focus_edit("Win_Chat", "DEFAULT_Txt_Speech");
                } else if self.ingame_ui.focused_edit.as_ref().map(|(d, _)| d.as_str())
                    == Some("Win_Chat")
                {
                    self.ingame_ui.focused_edit = None;
                }

                // `CDlgHPMPXP` (`hpmpxp.dtf`): `Txt_Name` is the character's name (`real_12_inworld_hud.png`),
                // `Size`/`Control_11822592` are portrait rect placeholders, and `St_1..4` hold active cultivation buffs!
                for hidden_ctrl in ["Size", "Control_11822592", "Img_Leader", "CombatMask"] {
                    self.ingame_ui
                        .set_control_visible("Win_Hpmpxp", hidden_ctrl, false);
                }
                let active_buffs = [
                    ("St_1", "^ffcb4aCelestial Vanguard^ffffff\nPhysical Defense +60% (30m)"),
                    ("St_2", "^ffcb4aStream Blessing^ffffff\nMax HP & MP +15% (30m)"),
                    ("St_3", "^ffcb4aWindstride Aura^ffffff\nMovement Speed +20% (15m)"),
                    ("St_4", "^ffcb4aSpirit Harmony^ffffff\nMP Regeneration +25/s (30m)"),
                ];
                for st_i in 1..=20 {
                    let sname = format!("St_{st_i}");
                    if let Some((_, bhint)) = active_buffs.get(st_i - 1) {
                        self.ingame_ui
                            .set_control_visible("Win_Hpmpxp", &sname, true);
                        self.ingame_ui.set_hint("Win_Hpmpxp", &sname, *bhint);
                    } else {
                        self.ingame_ui
                            .set_control_visible("Win_Hpmpxp", &sname, false);
                    }
                }
                for slot in 0..8usize {
                    let sk_id = self.quickbar_skills[slot];
                    let cname = format!("Item_{}", slot + 1);
                    if ElementSkill::get_stub(sk_id).is_some() {
                        self.ingame_ui.set_hint(
                            "Win_Quickbar8Ha",
                            &cname,
                            self.game.english_skill_tooltip(sk_id, 10, Some(slot + 1)),
                        );
                    }
                }
                let (scr_w, scr_h) = self.last_screen_dims;
                if self.show_main2 {
                    self.ingame_ui.show_dialog("Win_Main2", true);
                    for d in &mut self.ingame_ui.dialog_order {
                        if d.dialog_name.eq_ignore_ascii_case("Win_Main2") {
                            d.pos_override = Some(((scr_w as i32) - 210, (scr_h as i32) - 82));
                        }
                    }
                }
                if self.show_main3 {
                    self.ingame_ui.show_dialog("Win_Main3", true);
                    for d in &mut self.ingame_ui.dialog_order {
                        if d.dialog_name.eq_ignore_ascii_case("Win_Main3") {
                            d.pos_override = Some(((scr_w as i32) - 162, (scr_h as i32) - 82));
                        }
                    }
                }

                // `CDlgMiniMap` (`map.dtf`): hide square `Hide_2` placeholder & raid timer labels so circular radar + `cover` shine!
                for hidden_map_ctrl in [
                    "Hide_2",
                    "Txt_RestMonster",
                    "Txt_RestTime",
                    "Txt_TankDistance",
                    "Chk_CloseInfo",
                    "Chk_Mail",
                ] {
                    self.ingame_ui
                        .set_control_visible("Win_Map", hidden_map_ctrl, false);
                }

                if let Some(host) = &self.game.host_player {
                    self.ingame_ui
                        .set_text("Win_Hpmpxp", "TXT_LV", format!("{}", host.level));
                    self.ingame_ui
                        .set_text("Win_Hpmpxp", "Txt_Name", format!("^78DCFF{}", host.name));
                    let zone_name = self
                        .game
                        .active_map
                        .precinct_at(host.position.x, host.position.z)
                        .map(|p| p.name.clone())
                        .unwrap_or_else(|| self.game.active_map.map_name.to_uppercase());
                    self.ingame_ui
                        .set_text("Win_Map", "Txt_Address", zone_name);
                    let gx = ((host.position.x + 4000.0) * 0.1).round() as i32;
                    let gz = ((host.position.z + 5500.0) * 0.1).round() as i32;
                    let gy = (host.position.y * 0.1).round().max(0.0) as i32;
                    self.ingame_ui
                        .set_text("Win_Map", "Txt_xyz", format!("{gx}, {gz} ↑{gy}"));
                }
                self.ingame_ui.set_text("Win_Hpmpxp", "TXT_EXP", "70.4%");
                for (spark_idx, req) in [(1, 100i32), (2, 200), (3, 300)] {
                    let has_spark = self.host_chi >= req;
                    self.ingame_ui.set_control_visible(
                        "Win_Hpmpxp",
                        &format!("Img_P{spark_idx}on"),
                        has_spark,
                    );
                    self.ingame_ui.set_control_visible(
                        "Win_Hpmpxp",
                        &format!("Img_P{spark_idx}flash"),
                        false,
                    );
                }
                self.ingame_ui.set_text(
                    "Win_Hpmpxp",
                    "Txt_HP",
                    format!("{}/{}", self.host_hp, self.host_max_hp),
                );
                self.ingame_ui.set_text(
                    "Win_Hpmpxp",
                    "Txt_MP",
                    format!("{}/{}", self.host_mp, self.host_max_mp),
                );
                self.ingame_ui.progress_values.insert(
                    ("Win_Hpmpxp".to_string(), "Prgs_HP".to_string()),
                    (self.host_hp as f32 / self.host_max_hp.max(1) as f32).clamp(0.0, 1.0),
                );
                self.ingame_ui.progress_values.insert(
                    ("Win_Hpmpxp".to_string(), "Prgs_MP".to_string()),
                    (self.host_mp as f32 / self.host_max_mp.max(1) as f32).clamp(0.0, 1.0),
                );
                self.ingame_ui.progress_values.insert(
                    ("Win_Hpmpxp".to_string(), "Prgs_EXP".to_string()),
                    0.704,
                );
                self.ingame_ui.progress_values.insert(
                    ("Win_Hpmpxp".to_string(), "Prgs_AP".to_string()),
                    ((self.host_chi % 100) as f32 / 100.0).clamp(0.0, 1.0),
                );

                if let Some(tid) = self.selected_entity_id {
                    if let Some(ent) = self.world_entities.iter().find(|e| e.id == tid) {
                        if ent.kind == EntityVisualKind::Monster {
                            // `Win_HpOther` (`hpother.dtf`, `人鱼传说新界面\目标怪物2.dds`): authentic PW 1.4.2 Monster Target Frame!
                            self.ingame_ui.show_dialog("Win_HpOther", true);
                            self.ingame_ui
                                .set_text("Win_HpOther", "Txt_Name", ent.name.clone());
                            let att = if ent.title.is_empty() {
                                "+MT-FR".to_string()
                            } else {
                                ent.title.clone()
                            };
                            self.ingame_ui.set_text("Win_HpOther", "Txt_Att", att);
                            self.ingame_ui.progress_values.insert(
                                ("Win_HpOther".to_string(), "Prgs_HP".to_string()),
                                ent.hp_ratio.clamp(0.0, 1.0),
                            );
                        } else {
                            // `Win_HpmpOther` (`hpmpother.dtf`): authentic PW 1.4.2 NPC / Player Target Portrait Frame!
                            self.ingame_ui.show_dialog("Win_HpmpOther", true);
                            self.ingame_ui
                                .set_text("Win_HpmpOther", "Txt_Name", ent.name.clone());
                            self.ingame_ui.progress_values.insert(
                                ("Win_HpmpOther".to_string(), "Prgs_HP".to_string()),
                                ent.hp_ratio.clamp(0.0, 1.0),
                            );
                            self.ingame_ui.progress_values.insert(
                                ("Win_HpmpOther".to_string(), "Prgs_MP".to_string()),
                                1.0,
                            );
                        }
                    }
                }

                match self.modal {
                    InWorldModal::None => {}
                    InWorldModal::CharacterSheet => {
                        self.ingame_ui.show_dialog("Win_Character", true);
                        if let Some(hp) = &self.game.host_player {
                            let lvl = hp.level as i32;
                            let prof_name = self
                                .roster
                                .iter()
                                .find(|r| r.role_id == hp.role_id)
                                .map(|r| r.occupation_name())
                                .unwrap_or("Blademaster");
                            for (k, v) in [
                                ("Txt_CharName", hp.name.clone()),
                                ("Txt_CharLevel", format!("{lvl}")),
                                ("Txt_Profession", prof_name.to_string()),
                                ("Txt_Partner", "None".to_string()),
                                ("Txt_Distinction", "35,000".to_string()),
                                ("Txt_ExpCurrent", "84,520,000".to_string()),
                                ("Txt_ExpRequire", "120,000,000".to_string()),
                                ("Txt_xz", "Celestial Sage".to_string()),
                                ("Txt_Faction", "Archosaur Guard".to_string()),
                                ("Txt_HP", format!("{}/{}", self.host_hp, self.host_max_hp)),
                                ("Txt_MP", format!("{}/{}", self.host_mp, self.host_max_mp)),
                                ("Txt_SP", "2,480,000".to_string()),
                                ("Txt_Point", "0".to_string()),
                                ("Txt_Vit", format!("{}", 60 + lvl * 2)),
                                ("Txt_Int", format!("{}", 50 + lvl)),
                                ("Txt_Str", format!("{}", 75 + lvl * 3)),
                                ("Txt_Agi", format!("{}", 65 + lvl * 2)),
                                ("Txt_Attack", format!("{}-{}", 3640 + lvl * 18, 4890 + lvl * 24)),
                                ("Txt_MgcAttack", format!("{}-{}", 1920 + lvl * 10, 2380 + lvl * 12)),
                                ("Txt_Critical", "14%".to_string()),
                                ("Txt_AtkSpeed", "2.50 /s".to_string()),
                                ("Txt_Definition", "4,680".to_string()),
                                ("Txt_Evade", "3,120".to_string()),
                                ("Txt_MoveSpeed", format!("{:.1} m/s", self.move_speed * 0.5)),
                                ("Txt_AttackLevel", "28".to_string()),
                                ("Txt_CrtPower", "200%".to_string()),
                                ("Txt_PhyDefense", format!("{}", 7320 + lvl * 25)),
                                ("Txt_MgcDefGold", "5,420".to_string()),
                                ("Txt_MgcDefWood", "5,380".to_string()),
                                ("Txt_MgcDefIce", "5,610".to_string()),
                                ("Txt_MgcDefFire", "5,540".to_string()),
                                ("Txt_MgcDefRock", "5,490".to_string()),
                                ("Txt_DefenseLevel", "32".to_string()),
                                ("Txt_SoulPower", "26,840".to_string()),
                            ] {
                                self.ingame_ui.set_text("Win_Character", k, v);
                            }
                        }
                    }
                    InWorldModal::Inventory => {
                        self.ingame_ui.show_dialog("Win_InventoryM", true);
                        self.ingame_ui.show_dialog("Win_Bag", true);
                        self.ingame_ui
                            .set_edit_text("Win_InventoryM", "Txt_Gold", "12,580,000");
                    }
                    InWorldModal::SkillBook => {
                        self.ingame_ui.show_dialog("Win_Skill", true);
                        let cls = self
                            .game
                            .host_player
                            .as_ref()
                            .map(|p| (p.profession as i32).clamp(0, 7))
                            .unwrap_or(0);
                        self.ingame_ui
                            .show_dialog(&format!("Win_Skill{cls}"), true);
                    }
                    InWorldModal::QuestLog => {
                        self.ingame_ui.show_dialog("Win_Quest", true);
                        // `quest.dtf` mutually exclusive toggle controls (`Current Quests` mode vs `Available Quests` search mode)
                        self.ingame_ui
                            .set_control_visible("Win_Quest", "Txt_HaveQuest", true);
                        self.ingame_ui
                            .set_control_visible("Win_Quest", "Btn_SearchQuest", true);
                        self.ingame_ui
                            .set_control_visible("Win_Quest", "Txt_SearchQuest", false);
                        self.ingame_ui
                            .set_control_visible("Win_Quest", "Btn_HaveQuest", false);
                        let mut seen_q = std::collections::HashSet::new();
                        let unique_quests: Vec<_> = self
                            .game
                            .tasks_db
                            .top_tasks
                            .iter()
                            .filter(|q| {
                                let t = q.name.trim();
                                !t.is_empty() && !pw_data::has_cjk(t) && seen_q.insert(t.to_string())
                            })
                            .collect();
                        if let Some(q) = unique_quests
                            .get(self.list_scroll)
                            .or_else(|| unique_quests.first())
                        {
                            self.ingame_ui.set_text(
                                "Win_Quest",
                                "Txt_Content",
                                format!(
                                    "^FFE082{} (Quest #{})\n^E8F0FFSpeak with the Elders of Archosaur in the West District (529, 663) to advance your Celestial Cultivation across the Midlands.",
                                    q.name.trim(), q.id
                                ),
                            );
                            self.ingame_ui.set_text(
                                "Win_Quest",
                                "Txt_QuestItem",
                                "^98F8A8Objectives:\n  * Visit General Summer in Archosaur (1/1)\n  * Survey the Orginia River Watchtower (0/1)",
                            );
                            self.ingame_ui.set_text(
                                "Win_Quest",
                                "Txt_BaseAward",
                                "Coins: 45,000   EXP: 75,000   Spirit: 18,500",
                            );
                            self.ingame_ui.set_text(
                                "Win_Quest",
                                "Txt_QuestNO",
                                format!("{}/20", unique_quests.len().min(8)),
                            );
                        }
                    }
                    InWorldModal::Boutique => {
                        self.ingame_ui.show_dialog("Win_QShop", true);
                        let sub_cats = ["Tops", "Pants", "Gloves", "Shoes"];
                        for sub_i in 0..8usize {
                            let bname = format!("Btn_SubType{sub_i}");
                            if let Some(&lbl) = sub_cats.get(sub_i) {
                                self.ingame_ui.set_control_visible("Win_QShop", &bname, true);
                                self.ingame_ui.set_text("Win_QShop", &bname, lbl);
                            } else {
                                self.ingame_ui.set_control_visible("Win_QShop", &bname, false);
                            }
                        }
                        self.ingame_ui
                            .set_text("Win_QShop", "Txt_Cash", "999,900 Gold");
                        if let Some(featured) = self
                            .game
                            .gshop_db
                            .items
                            .get(self.list_scroll)
                            .or_else(|| self.game.gshop_db.items.first())
                        {
                            self.ingame_ui
                                .set_text("Win_QShop", "Txt_ItemName", featured.name.clone());
                            self.ingame_ui.set_text(
                                "Win_QShop",
                                "Txt_ItemDesc",
                                format!(
                                    "Item #{} (x{})\nBoutique Entry #{}\nAuthentic PW 1.4.2 Treasure.",
                                    featured.item_id, featured.item_num, featured.local_id
                                ),
                            );
                        }
                        for slot in 0..8usize {
                            let cname = format!("Lab_Dialog{slot}");
                            if let Some(it) = self.game.gshop_db.items.get(self.list_scroll + slot) {
                                self.ingame_ui.set_text(
                                    "Win_QShop",
                                    &cname,
                                    format!("     {}", it.name),
                                );
                            } else {
                                self.ingame_ui.set_text("Win_QShop", &cname, "");
                            }
                        }
                    }
                    InWorldModal::WorldMap => {}
                    InWorldModal::NpcDialog => {
                        self.ingame_ui.show_dialog("Win_NPC", true);
                        let npc_ent = self
                            .selected_entity_id
                            .and_then(|id| {
                                self.world_entities
                                    .iter()
                                    .find(|e| e.id == id && e.kind == EntityVisualKind::Npc)
                            })
                            .or_else(|| {
                                self.world_entities
                                    .iter()
                                    .find(|e| e.kind == EntityVisualKind::Npc)
                            });
                        let (npc_name, greeting) = if let Some(ent) = npc_ent {
                            let greet = self.entity_greetings.get(&ent.id).cloned().unwrap_or_else(
                                || {
                                    "Greetings, traveler of Perfect World! How may Archosaur's guild assist you today?"
                                        .to_string()
                                },
                            );
                            (ent.name.clone(), greet)
                        } else {
                            (
                                "Teleportation Master".to_string(),
                                "Where in Perfect World do you wish to journey today?".to_string(),
                            )
                        };
                        self.ingame_ui.set_text("Win_NPC", "Txt_npc", npc_name);
                        self.ingame_ui
                            .set_text("Win_NPC", "Txt_Content", format!("\n\n{greeting}"));
                    }
                    InWorldModal::DevConsole => {
                        self.ingame_ui.show_dialog("Dlg_Console", true);
                    }
                    InWorldModal::ActionPanel => {
                        self.ingame_ui.show_dialog("Win_Action", true);
                    }
                    InWorldModal::FriendList => {
                        self.ingame_ui.show_dialog("Win_FriendList", true);
                    }
                    InWorldModal::SystemSettings => {
                        self.ingame_ui.show_dialog("Win_SettingSystem", true);
                        self.ingame_ui
                            .set_control_visible("Win_SettingSystem", "Lst_Res", false);
                    }
                    InWorldModal::GuildManage => {
                        self.ingame_ui.show_dialog("Win_GuildManage", true);
                    }
                    InWorldModal::TerritoryMap => {
                        self.ingame_ui.show_dialog("GuildMap", true);
                    }
                    InWorldModal::PetBag => {
                        self.ingame_ui.show_dialog("Win_PetList", true);
                    }
                    InWorldModal::MailBox => {
                        self.ingame_ui.show_dialog("Win_MailList", true);
                    }
                    InWorldModal::AuctionHouse => {
                        self.ingame_ui.show_dialog("Win_AuctionList", true);
                    }
                    InWorldModal::PlayerTrade => {
                        self.ingame_ui.show_dialog("Win_Trade", true);
                    }
                    InWorldModal::NpcShop => {
                        self.ingame_ui.show_dialog("Win_Shop", true);
                    }
                    InWorldModal::Warehouse => {
                        self.ingame_ui.show_dialog("Win_Storage", true);
                    }
                    InWorldModal::CraftProduce => {
                        self.ingame_ui.show_dialog("Win_Produce", true);
                    }
                    InWorldModal::EquipRefine => {
                        self.ingame_ui.show_dialog("Win_EquipRefine", true);
                    }
                    InWorldModal::GenieElf => {
                        self.ingame_ui.show_dialog("Win_ELFProp", true);
                    }
                    InWorldModal::PlayerBooth => {
                        self.ingame_ui.show_dialog("Win_Booth", true);
                    }
                    InWorldModal::PkAutolock => {
                        self.ingame_ui.show_dialog("Win_PKSetting", true);
                        self.ingame_ui.show_dialog("Win_AutoLock", true);
                    }
                }
                if !self.team_members.is_empty() {
                    self.ingame_ui.show_dialog("Win_TeamMain", true);
                    for idx in 1..=self.team_members.len().min(9) {
                        self.ingame_ui
                            .show_dialog(&format!("Win_TeamMate{idx}"), true);
                    }
                }
                if self.summoned_pet_idx.is_some() {
                    self.ingame_ui.show_dialog("Win_HpmpxpPet0", true);
                }
            }
        }
    }

    /// Builds the complete 3D camera, `.ski` character actors, and `AUIManager` 2D draw lists for the current frame.
    pub fn prepare_frame(
        &mut self,
        width: u32,
        height: u32,
        mouse_x: i32,
        mouse_y: i32,
    ) -> PreparedFrame {
        let w = width.max(64);
        let h = height.max(64);
        self.last_screen_dims = (w, h);
        self.scene_3d.ui_anim_ms = (self.anim_seconds.max(0.0) * 1000.0) as u64;
        self.scene_3d.day_phase_frame = ((self.time_of_day.rem_euclid(24.0) / 6.0) as u32) & 3;
        if self.applied_layout_size != (w, h) {
            if let Some(ini) = &self.layout_ini {
                self.ingame_ui
                    .apply_layout_ini(&self.game.aui_manager, ini, w, h);
            }
            self.applied_layout_size = (w, h);
        }
        self.sync_aui_state();

        let cam_proj = A3DCamera::new_perspective(w, h, 56.0);
        let mut actors = Vec::new();

        let (eye, dir, up, mut ui_quads, mut ui_texts) = match self.screen {
            ClientScreenState::Login | ClientScreenState::LoginWait => {
                self.login_ui
                    .on_mouse_move(&self.game.aui_manager, mouse_x, mouse_y, w, h);
                let cam = self
                    .game
                    .scene_ctrl
                    .cameras
                    .get(self.login_cam_preset_idx)
                    .copied()
                    .unwrap_or_else(|| self.game.scene_ctrl.login_camera());
                let mut q = Vec::new();
                if let Some(logo_tid) = self
                    .scene_3d
                    .ensure_ui_surface(&self.game.vfs, "logo.dds")
                    .or_else(|| {
                        self.scene_3d
                            .ensure_ui_surface(&self.game.vfs, "surfaces\\logo.dds")
                    })
                {
                    q.push(UiQuad2D {
                        x0: 24.0,
                        y0: 14.0,
                        x1: 280.0,
                        y1: 142.0,
                        u0: 0.0,
                        v0: 0.0,
                        u1: 1.0,
                        v1: 1.0,
                        color: 0xFFFF_FFFF,
                        tex_id: Some(logo_tid),
                        clip_rect: None,
                    });
                }
                let (aui_q, mut t) = build_aui_draw_list(
                    &mut self.scene_3d,
                    &self.game.vfs,
                    &self.game.aui_manager,
                    &self.login_ui,
                    w,
                    h,
                );
                q.extend(aui_q);
                t.push(UiText2D {
                    x: (w as i32) - 160,
                    y: (h as i32) - 22,
                    size_px: 12,
                    color: 0xFFFF_FFFF,
                    text: "Ver 1.4.2".to_string(),
                    shadow: true,
                    clip_rect: None,
                });
                t.push(UiText2D {
                    x: (w as i32) - 82,
                    y: (h as i32) - 22,
                    size_px: 12,
                    color: 0xFFFF_EE40,
                    text: format!("Build {}", self.game.build_version),
                    shadow: true,
                    clip_rect: None,
                });
                if self.online_mode || self.screen == ClientScreenState::LoginWait {
                    t.push(UiText2D {
                        x: 14,
                        y: (h as i32) - 22,
                        size_px: 12,
                        color: 0xFFE8_DCA8,
                        text: self.status_banner.clone(),
                        shadow: true,
                        clip_rect: None,
                    });
                }
                (cam.pos, cam.dir, cam.up, q, t)
            }
            ClientScreenState::CharacterSelect => {
                self.login_ui
                    .on_mouse_move(&self.game.aui_manager, mouse_x, mouse_y, w, h);
                let (cam, ped_pos, base_dir) = if let Some(role) =
                    self.roster.get(self.selected_role_idx)
                {
                    let (c, p, fd) = self
                        .game
                        .scene_ctrl
                        .select_rig_for_class(role.occupation as usize);
                    let yaw = fd.x.atan2(fd.z) + self.pedestal_yaw_offset;
                    let rot_dir = Vec3::new(yaw.sin(), 0.0, yaw.cos());
                    let preset = self
                        .role_appearance_presets
                        .get(&role.role_id)
                        .copied()
                        .unwrap_or((self.selected_role_idx & 3) as u8);
                    actors.push(DynamicCharacterActor {
                        role_id: role.role_id,
                        name: role.name.clone(),
                        cls: role.occupation as i32,
                        gender: clamp_gender_for_class(role.occupation, role.gender),
                        appearance_preset: preset,
                        action: ActorActionKind::Stand,
                        ecm_path: None,
                        fly_ecm_path: None,
                        pos: p,
                        dir: rot_dir,
                        scale: 1.0,
                        selected: false,
                    });
                    (c, p, rot_dir)
                } else {
                    self.game.scene_ctrl.select_rig_for_class(0)
                };
                let _ = (ped_pos, base_dir);
                let (q, t) = build_aui_draw_list(
                    &mut self.scene_3d,
                    &self.game.vfs,
                    &self.game.aui_manager,
                    &self.login_ui,
                    w,
                    h,
                );
                (cam.pos, cam.dir, cam.up, q, t)
            }
            ClientScreenState::CreateCharacter => {
                self.login_ui
                    .on_mouse_move(&self.game.aui_manager, mouse_x, mouse_y, w, h);
                let occ = self.create_occupation.min(7);
                let gender = clamp_gender_for_class(occ, self.create_gender);
                let (cam, ped_pos, fd) = self.game.scene_ctrl.create_rig(occ as usize);
                let yaw = fd.x.atan2(fd.z) + self.pedestal_yaw_offset;
                let rot_dir = Vec3::new(yaw.sin(), 0.0, yaw.cos());
                actors.push(DynamicCharacterActor {
                    role_id: 0,
                    name: self.create_name_input.clone(),
                    cls: occ as i32,
                    gender,
                    appearance_preset: self.create_appearance_preset,
                    action: ActorActionKind::Stand,
                    ecm_path: None,
                    fly_ecm_path: None,
                    pos: ped_pos,
                    dir: rot_dir,
                    scale: 1.0,
                    selected: false,
                });
                let (q, t) = build_aui_draw_list(
                    &mut self.scene_3d,
                    &self.game.vfs,
                    &self.game.aui_manager,
                    &self.login_ui,
                    w,
                    h,
                );
                (cam.pos, cam.dir, cam.up, q, t)
            }
            ClientScreenState::InWorld => {
                self.ingame_ui
                    .on_mouse_move(&self.game.aui_manager, mouse_x, mouse_y, w, h);
                let (p_pos, p_cls, p_name, p_id) = if let Some(h_pl) = &self.game.host_player {
                    (
                        h_pl.position,
                        h_pl.profession as i32,
                        h_pl.name.clone(),
                        h_pl.role_id,
                    )
                } else {
                    (Vec3::new(0.0, 220.0, 0.0), 0, "Hero".to_string(), 1024)
                };

                let p_gender = self
                    .roster
                    .iter()
                    .find(|r| r.role_id == p_id)
                    .map(|r| clamp_gender_for_class(r.occupation, r.gender))
                    .unwrap_or_else(|| clamp_gender_for_class(p_cls.clamp(0, 7) as u8, 0));
                let p_preset = self
                    .role_appearance_presets
                    .get(&p_id)
                    .copied()
                    .unwrap_or(0);
                let p_action = if self.player_attack_timer > 0.01 {
                    if matches!(p_cls, 1 | 2 | 3 | 7) {
                        ActorActionKind::SkillCast
                    } else {
                        ActorActionKind::Attack
                    }
                } else if self.flying_mode {
                    if self.player_moving {
                        ActorActionKind::FlyMove
                    } else {
                        ActorActionKind::FlyHover
                    }
                } else if self.player_moving {
                    ActorActionKind::Run
                } else {
                    ActorActionKind::Stand
                };

                let fly_ecm = if self.flying_mode {
                    Some(class_aerogear_ecm(p_cls.clamp(0, 7)).0.to_string())
                } else {
                    None
                };
                actors.push(DynamicCharacterActor {
                    role_id: p_id,
                    name: p_name,
                    cls: p_cls.clamp(0, 7),
                    gender: p_gender,
                    appearance_preset: p_preset,
                    action: p_action,
                    ecm_path: None,
                    fly_ecm_path: fly_ecm,
                    pos: p_pos,
                    dir: Vec3::new(self.player_yaw.sin(), 0.0, self.player_yaw.cos()),
                    scale: 1.0,
                    selected: false,
                });

                let mut npc_seq = 0usize;
                let mut mob_seq = 0usize;
                for ent in self.world_entities.iter().take(24) {
                    let (ecm, act) = if let Some(exact_ecm) = self.entity_ecm_paths.get(&ent.id) {
                        let a = if ent.kind == EntityVisualKind::Npc {
                            ActorActionKind::Stand
                        } else {
                            ActorActionKind::Run
                        };
                        (exact_ecm.clone(), a)
                    } else if ent.kind == EntityVisualKind::Npc {
                        let (_, _, p) = REAL_NPC_ECMS[npc_seq % REAL_NPC_ECMS.len()];
                        npc_seq += 1;
                        (p.to_string(), ActorActionKind::Stand)
                    } else {
                        let (_, _, p) = REAL_MONSTER_ECMS[mob_seq % REAL_MONSTER_ECMS.len()];
                        mob_seq += 1;
                        (p.to_string(), ActorActionKind::Run)
                    };
                    actors.push(DynamicCharacterActor {
                        role_id: ent.id,
                        name: ent.name.clone(),
                        cls: 0,
                        gender: 0,
                        appearance_preset: 0,
                        action: act,
                        ecm_path: Some(ecm),
                        fly_ecm_path: None,
                        pos: ent.pos,
                        dir: Vec3::new(ent.yaw.sin(), 0.0, ent.yaw.cos()),
                        scale: ent.scale,
                        selected: ent.selected,
                    });
                }

                let focus = Vec3::new(p_pos.x, p_pos.y + 1.45, p_pos.z);
                let cp = self.cam_pitch.cos();
                let sp = self.cam_pitch.sin();
                let look_dir =
                    Vec3::new(self.cam_yaw.sin() * cp, -sp, self.cam_yaw.cos() * cp).normalized();
                let mut eye_pos = focus.sub(look_dir.scale(self.cam_dist));
                let ground_at_eye =
                    self.sample_active_ground_y(eye_pos.x, eye_pos.y, eye_pos.z) + 0.65;
                if eye_pos.y < ground_at_eye {
                    eye_pos.y = ground_at_eye;
                }

                let mut world_quads = Vec::new();
                let mut world_texts = Vec::new();

                if self.modal == InWorldModal::WorldMap {
                    self.append_fullscreen_bigmap(w, h, p_pos, &mut world_quads);
                } else {
                    self.append_world_3d_nameplates(
                        w,
                        h,
                        eye_pos,
                        look_dir,
                        Vec3::UNIT_Y,
                        &cam_proj,
                        &mut world_quads,
                        &mut world_texts,
                    );
                    self.scene_3d
                        .flush_texts_to_quads(&mut world_quads, &mut world_texts);

                    if let Some((px, py, pw, ph)) = self
                        .ingame_ui
                        .find_control_screen_rect(&self.game.aui_manager, "Win_Hpmpxp", "Size", w, h)
                        .or_else(|| {
                            self.ingame_ui
                                .find_dialog_screen_rect(&self.game.aui_manager, "Win_Hpmpxp", w, h)
                                .map(|(dx, dy, _, _)| (dx + 12, dy + 13, 64, 64))
                        })
                    {
                        if let Some(port_tid) = self.scene_3d.ensure_player_portrait_tex(
                            &self.game.vfs,
                            p_cls.clamp(0, 7),
                            p_gender,
                            p_preset,
                        ) {
                            world_quads.push(UiQuad2D {
                                x0: (px + 2) as f32,
                                y0: (py + 2) as f32,
                                x1: (px + pw - 2) as f32,
                                y1: (py + ph - 2) as f32,
                                u0: 0.0,
                                v0: 0.0,
                                u1: 1.0,
                                v1: 1.0,
                                color: 0xFFFF_FFFF,
                                tex_id: Some(port_tid),
                                clip_rect: None,
                            });
                        }
                    }

                    if let Some((dx, dy, _, _)) = self.ingame_ui.find_dialog_screen_rect(
                        &self.game.aui_manager,
                        "Win_Map",
                        w,
                        h,
                    ) {
                        let radar_blips: Vec<(f32, f32, u32)> = self
                            .world_entities
                            .iter()
                            .take(28)
                            .map(|e| {
                                let col = if e.kind == EntityVisualKind::Npc {
                                    0xFF48_FF68
                                } else {
                                    0xFFFF_4040
                                };
                                (e.pos.x, e.pos.z, col)
                            })
                            .collect();
                        if let Some(circ_tid) = self.scene_3d.update_circular_minimap(
                            &self.game.vfs,
                            p_pos.x,
                            p_pos.z,
                            self.player_yaw,
                            self.cam_yaw,
                            &radar_blips,
                        ) {
                            world_quads.push(UiQuad2D {
                                x0: (dx + 190) as f32,
                                y0: (dy + 8) as f32,
                                x1: (dx + 294) as f32,
                                y1: (dy + 112) as f32,
                                u0: 0.0,
                                v0: 0.0,
                                u1: 1.0,
                                v1: 1.0,
                                color: 0xFFFF_FFFF,
                                tex_id: Some(circ_tid),
                                clip_rect: None,
                            });
                        }
                        if let Some(dir_tid) = self
                            .scene_3d
                            .ensure_ui_surface(&self.game.vfs, "ingame\\minimapdir.tga")
                        {
                            world_quads.push(UiQuad2D {
                                x0: (dx + 190) as f32,
                                y0: (dy + 8) as f32,
                                x1: (dx + 294) as f32,
                                y1: (dy + 112) as f32,
                                u0: 0.0,
                                v0: 0.0,
                                u1: 1.0,
                                v1: 1.0,
                                color: 0xFFFF_FFFF,
                                tex_id: Some(dir_tid),
                                clip_rect: None,
                            });
                        }
                    }
                }

                let (aui_q, t) = build_aui_draw_list(
                    &mut self.scene_3d,
                    &self.game.vfs,
                    &self.game.aui_manager,
                    &self.ingame_ui,
                    w,
                    h,
                );
                world_quads.extend(aui_q);
                (eye_pos, look_dir, Vec3::UNIT_Y, world_quads, t)
            }
        };

        // Append HUD portraits, minimap radar, `iconlist_*` 32x32 icons, chat, & modal rows ON TOP OF dialog frames
        if self.screen == ClientScreenState::InWorld {
            self.append_inworld_hud_and_modal_texts(w, h, &mut ui_quads, &mut ui_texts);
        }

        // Emit floating `.htf` / Skill / Item / Buff tooltip ON TOP OF all icons & dialog frames!
        let active_ui = if self.screen == ClientScreenState::InWorld {
            &self.ingame_ui
        } else {
            &self.login_ui
        };
        self.scene_3d.active_cursor = if active_ui.hovered_control.is_some() {
            "hand".to_string()
        } else {
            "normal".to_string()
        };
        emit_aui_hover_tooltip(
            &mut self.scene_3d,
            &self.game.vfs,
            &self.game.aui_manager,
            active_ui,
            w,
            h,
            &mut ui_quads,
            &mut ui_texts,
        );

        // Convert all TrueType (`fzl2jw.ttf`) `UiText2D` entries into crisp glyph-atlas `UiQuad2D`s
        // so BOTH hardware `D3d9Renderer` and CPU `render_scene_and_ui_cpu` render identical `^RRGGBB` CJK/Latin typography!
        self.scene_3d
            .flush_texts_to_quads(&mut ui_quads, &mut ui_texts);

        // Finally emit the authentic `cursors\normal.ani` / `hand.cur` cursor sprite at topmost Z!
        emit_software_cursor_quad(&self.scene_3d, mouse_x, mouse_y, &mut ui_quads);

        PreparedFrame {
            eye,
            dir,
            up,
            cam_proj,
            actors,
            ui_quads,
            ui_texts,
            anim_time: self.anim_seconds,
        }
    }

    fn append_fullscreen_bigmap(
        &mut self,
        w: u32,
        h: u32,
        pos: Vec3,
        quads: &mut Vec<UiQuad2D>,
    ) {
        let wf = w as f32;
        let hf = h as f32;

        if self.world_map_regional_zoom {
            let (sr, sc, ox, oz_top) = if let Some(trn) = &self.game.active_map.trn2_full {
                let (sr, sc, _) = trn.sub_trn_for_world_pos(pos.x, pos.z);
                let (ox, oz_top, _, _) = trn.sub_trn_bounds(sr, sc);
                (sr, sc, ox, oz_top)
            } else {
                (4usize, 5usize, -512.0f32, 512.0f32)
            };
            let reg_tid = self.scene_3d.ensure_regional_map_tex(&self.game.vfs, sr, sc);
            quads.push(UiQuad2D {
                x0: 0.0,
                y0: 0.0,
                x1: wf,
                y1: hf,
                u0: 0.0,
                v0: 0.0,
                u1: 1.0,
                v1: 1.0,
                color: 0xFFFF_FFFF,
                tex_id: reg_tid.or(self.scene_3d.minimap_tex_id),
                clip_rect: None,
            });
            for ent in &self.world_entities {
                let fx = (ent.pos.x - ox) / 1024.0;
                let fy = (oz_top - ent.pos.z) / 1024.0;
                if (0.0..=1.0).contains(&fx) && (0.0..=1.0).contains(&fy) {
                    let sx = fx * wf;
                    let sy = fy * hf;
                    let col = if ent.kind == EntityVisualKind::Npc {
                        0xFF48_FF78
                    } else {
                        0xFFFF_4848
                    };
                    quads.push(UiQuad2D {
                        x0: sx - 3.0,
                        y0: sy - 3.0,
                        x1: sx + 3.0,
                        y1: sy + 3.0,
                        u0: 0.0,
                        v0: 0.0,
                        u1: 1.0,
                        v1: 1.0,
                        color: col,
                        tex_id: None,
                        clip_rect: None,
                    });
                }
            }
            let psx = ((pos.x - ox) / 1024.0).clamp(0.02, 0.98) * wf;
            let psy = ((oz_top - pos.z) / 1024.0).clamp(0.02, 0.98) * hf;
            quads.push(UiQuad2D {
                x0: psx - 5.0,
                y0: psy - 5.0,
                x1: psx + 5.0,
                y1: psy + 5.0,
                u0: 0.0,
                v0: 0.0,
                u1: 1.0,
                v1: 1.0,
                color: 0xFF98_FF48,
                tex_id: None,
                clip_rect: None,
            });
        } else {
            // 1:1 `CDlgWorldMap` (`real_14_inworld_bigmap.png`):
            // `surfaces\ingame\world.dds` (`1024x1024`, active `1024x768` at `v in [0.125, 0.875]`) already contains
            // BOTH the calligraphed city/region names AND the bottom-left gold Rising Tide crest!
            quads.push(UiQuad2D {
                x0: 0.0,
                y0: 0.0,
                x1: wf,
                y1: hf,
                u0: 0.0,
                v0: 0.125,
                u1: 1.0,
                v1: 0.875,
                color: 0xFFFF_FFFF,
                tex_id: self.scene_3d.world_map_tex_id,
                clip_rect: None,
            });

            let pfx = (0.5 + pos.x / 15018.667).clamp(0.02, 0.98);
            let pfy = (0.5 - pos.z / 11264.0).clamp(0.02, 0.98);
            let psx = pfx * wf;
            let psy = pfy * hf;
            quads.push(UiQuad2D {
                x0: psx - 5.0,
                y0: psy - 5.0,
                x1: psx + 5.0,
                y1: psy + 5.0,
                u0: 0.0,
                v0: 0.0,
                u1: 1.0,
                v1: 1.0,
                color: 0xDD18_2410,
                tex_id: None,
                clip_rect: None,
            });
            quads.push(UiQuad2D {
                x0: psx - 3.5,
                y0: psy - 3.5,
                x1: psx + 3.5,
                y1: psy + 3.5,
                u0: 0.0,
                v0: 0.0,
                u1: 1.0,
                v1: 1.0,
                color: 0xFFB8_FF48,
                tex_id: None,
                clip_rect: None,
            });
        }
    }

    #[allow(clippy::too_many_arguments)]
    fn append_world_3d_nameplates(
        &mut self,
        w: u32,
        h: u32,
        eye: Vec3,
        dir: Vec3,
        up: Vec3,
        cam_proj: &A3DCamera,
        quads: &mut Vec<UiQuad2D>,
        texts: &mut Vec<UiText2D>,
    ) {
        for ent in self.world_entities.iter().take(24) {
            let head_pt = Vec3::new(ent.pos.x, ent.pos.y + 2.15 * ent.scale, ent.pos.z);
            let Some((sx, sy, dist)) =
                project_world_to_screen(eye, dir, up, cam_proj, w, h, head_pt)
            else {
                continue;
            };
            if dist > 38.0 {
                continue;
            }
            let name_col = if ent.kind == EntityVisualKind::Npc {
                0xFF88_FF98
            } else if ent.selected {
                0xFFFF_5858
            } else {
                0xFFFF_A078
            };
            let nw = self
                .scene_3d
                .font_atlas
                .measure_text_px(&mut self.scene_3d.textures, &ent.name, 12);
            texts.push(UiText2D {
                x: sx - nw / 2,
                y: sy - 14,
                size_px: 12,
                color: name_col,
                text: ent.name.clone(),
                shadow: true,
                clip_rect: None,
            });
            if ent.kind == EntityVisualKind::Npc && !ent.title.is_empty() {
                let ttl = format!("<{}>", ent.title);
                let tw =
                    self.scene_3d
                        .font_atlas
                        .measure_text_px(&mut self.scene_3d.textures, &ttl, 11);
                texts.push(UiText2D {
                    x: sx - tw / 2,
                    y: sy - 28,
                    size_px: 11,
                    color: 0xFFFF_D878,
                    text: ttl,
                    shadow: true,
                    clip_rect: None,
                });
            } else if ent.selected || ent.hp_ratio < 0.999 {
                let bw = 54.0f32;
                let bx = (sx as f32) - bw * 0.5;
                let by = (sy - 22) as f32;
                quads.push(UiQuad2D {
                    x0: bx - 1.0,
                    y0: by - 1.0,
                    x1: bx + bw + 1.0,
                    y1: by + 5.0,
                    u0: 0.0,
                    v0: 0.0,
                    u1: 1.0,
                    v1: 1.0,
                    color: 0xC810_1014,
                    tex_id: None,
                    clip_rect: None,
                });
                quads.push(UiQuad2D {
                    x0: bx,
                    y0: by,
                    x1: bx + bw * ent.hp_ratio.clamp(0.0, 1.0),
                    y1: by + 4.0,
                    u0: 0.0,
                    v0: 0.0,
                    u1: 1.0,
                    v1: 1.0,
                    color: 0xFFE8_3838,
                    tex_id: None,
                    clip_rect: None,
                });
            }
        }

        for ef in &self.active_effects {
            let pt = Vec3::new(ef.pos.x, ef.pos.y + 2.4 + (1.15 - ef.ttl) * 1.2, ef.pos.z);
            if let Some((sx, sy, _)) = project_world_to_screen(eye, dir, up, cam_proj, w, h, pt) {
                let label = format!("★ {}", ef.skill_name);
                let lw = self.scene_3d.font_atlas.measure_text_px(
                    &mut self.scene_3d.textures,
                    &label,
                    14,
                );
                texts.push(UiText2D {
                    x: sx - lw / 2,
                    y: sy,
                    size_px: 14,
                    color: ef.color,
                    text: label,
                    shadow: true,
                    clip_rect: None,
                });
            }
        }
    }

    fn append_inworld_hud_and_modal_texts(
        &mut self,
        w: u32,
        h: u32,
        quads: &mut Vec<UiQuad2D>,
        texts: &mut Vec<UiText2D>,
    ) {
        if self.modal == InWorldModal::WorldMap {
            return;
        }
        let _ui_scale = AuiRuntime::compute_ui_scale(w, h);

        // Active cultivation buff icons (`Win_Hpmpxp::St_1..St_4` from `surfaces/iconset/iconlist_state.dds` `16x16`)
        if let Some(st_atlas) = &self.scene_3d.state_icons {
            let st_tid = st_atlas.tex_id;
            let buff_names = ["坚甲符.dds", "生命上限增加.dds", "加速.dds", "mp恢复加快.dds"];
            for (bi, bname) in buff_names.iter().enumerate() {
                let sname = format!("St_{}", bi + 1);
                if let Some((sx, sy, sw, sh)) = self.ingame_ui.find_control_screen_rect(
                    &self.game.aui_manager,
                    "Win_Hpmpxp",
                    &sname,
                    w,
                    h,
                ) {
                    let (u0, v0, u1, v1) = st_atlas.uv_for_name(bname, bi + 2);
                    quads.push(UiQuad2D {
                        x0: sx as f32,
                        y0: sy as f32,
                        x1: (sx + sw) as f32,
                        y1: (sy + sh) as f32,
                        u0,
                        v0,
                        u1,
                        v1,
                        color: 0xFFFF_FFFF,
                        tex_id: Some(st_tid),
                        clip_rect: None,
                    });
                }
            }
        }

        // `Win_HpmpOther::Size` (`14,12,64,64`): genuine `64x64` circular-masked 3D NPC/Player headshot portrait!
        if self.ingame_ui.is_dialog_visible("Win_HpmpOther") {
            if let Some((px, py, pw, ph)) = self
                .ingame_ui
                .find_control_screen_rect(&self.game.aui_manager, "Win_HpmpOther", "Size", w, h)
                .or_else(|| {
                    self.ingame_ui
                        .find_dialog_screen_rect(&self.game.aui_manager, "Win_HpmpOther", w, h)
                        .map(|(dx, dy, _, _)| (dx + 14, dy + 12, 64, 64))
                })
            {
                let target_port_tid = self
                    .selected_entity_id
                    .and_then(|eid| self.entity_ecm_paths.get(&eid).cloned())
                    .and_then(|ecm| self.scene_3d.ensure_ecm_portrait_tex(&self.game.vfs, &ecm))
                    .or_else(|| {
                        self.scene_3d
                            .ensure_player_portrait_tex(&self.game.vfs, 0, 0, 0)
                    });
                if let Some(ptid) = target_port_tid {
                    quads.push(UiQuad2D {
                        x0: (px + 2) as f32,
                        y0: (py + 2) as f32,
                        x1: (px + pw - 2) as f32,
                        y1: (py + ph - 2) as f32,
                        u0: 0.0,
                        v0: 0.0,
                        u1: 1.0,
                        v1: 1.0,
                        color: 0xFFFF_FFFF,
                        tex_id: Some(ptid),
                        clip_rect: None,
                    });
                }
            }
        }

        if let Some(sk_atlas) = &self.scene_3d.skill_icons {
            let sk_tid = sk_atlas.tex_id;
            for slot in 0..8usize {
                let cname = format!("Item_{}", slot + 1);
                let Some((ix, iy, iw, ih)) = self.ingame_ui.find_control_screen_rect(
                    &self.game.aui_manager,
                    "Win_Quickbar8Ha",
                    &cname,
                    w,
                    h,
                ) else {
                    continue;
                };
                let sk_id = self.quickbar_skills[slot];
                let (u0, v0, u1, v1) = if let Some(stub) = ElementSkill::get_stub(sk_id) {
                    sk_atlas.uv_for_name(stub.icon, sk_id as usize)
                } else {
                    sk_atlas.uv_for_index(((sk_id as usize) * 7 + 12) % sk_atlas.total_icons.max(1))
                };
                quads.push(UiQuad2D {
                    x0: ix as f32 + 1.0,
                    y0: iy as f32 + 1.0,
                    x1: (ix + iw) as f32 - 1.0,
                    y1: (iy + ih) as f32 - 1.0,
                    u0,
                    v0,
                    u1,
                    v1,
                    color: 0xFFFF_FFFF,
                    tex_id: Some(sk_tid),
                    clip_rect: None,
                });
                if self.skill_cooldowns[slot] > 0.05 {
                    // Authentic `AUIClockIcon` (`aui_clock_icon_contains_uv`) radial clockwise cooldown sweep!
                    let rem_frac = (self.skill_cooldowns[slot] / 8.0).clamp(0.02, 1.0);
                    let grid_n = 8i32;
                    let sx = (iw - 2).max(8) as f32 / grid_n as f32;
                    let sy = (ih - 2).max(8) as f32 / grid_n as f32;
                    for gy in 0..grid_n {
                        for gx in 0..grid_n {
                            let u = (gx as f32 + 0.5) / grid_n as f32;
                            let v = (gy as f32 + 0.5) / grid_n as f32;
                            if pw_aui::aui_clock_icon_contains_uv(u, v, rem_frac) {
                                quads.push(UiQuad2D {
                                    x0: ix as f32 + 1.0 + gx as f32 * sx,
                                    y0: iy as f32 + 1.0 + gy as f32 * sy,
                                    x1: ix as f32 + 1.0 + (gx + 1) as f32 * sx,
                                    y1: iy as f32 + 1.0 + (gy + 1) as f32 * sy,
                                    u0: 0.0,
                                    v0: 0.0,
                                    u1: 1.0,
                                    v1: 1.0,
                                    color: 0xAA0C_1018,
                                    tex_id: None,
                                    clip_rect: None,
                                });
                            }
                        }
                    }
                    texts.push(UiText2D {
                        x: ix + 6,
                        y: iy + 8,
                        size_px: 12,
                        color: 0xFFFF_E068,
                        text: format!("{:.1}", self.skill_cooldowns[slot]),
                        shadow: true,
                        clip_rect: None,
                    });
                }
            }
        }

        match self.modal {
            InWorldModal::None | InWorldModal::WorldMap => {}
            InWorldModal::CharacterSheet => {
                let (p_cls, p_gender, p_preset) = if let Some(hp) = &self.game.host_player {
                    let g = self
                        .roster
                        .iter()
                        .find(|r| r.role_id == hp.role_id)
                        .map(|r| clamp_gender_for_class(r.occupation, r.gender))
                        .unwrap_or_else(|| {
                            clamp_gender_for_class((hp.profession as i32).clamp(0, 7) as u8, 0)
                        });
                    let pr = self
                        .role_appearance_presets
                        .get(&hp.role_id)
                        .copied()
                        .unwrap_or(0);
                    ((hp.profession as i32).clamp(0, 7), g, pr)
                } else {
                    (0, 0, 0)
                };
                if let Some((ix, iy, iw, ih)) = self.ingame_ui.find_control_screen_rect(
                    &self.game.aui_manager,
                    "Win_Character",
                    "Img_Char",
                    w,
                    h,
                ) {
                    if let Some(port_tid) = self.scene_3d.ensure_player_portrait_tex(
                        &self.game.vfs,
                        p_cls,
                        p_gender,
                        p_preset,
                    ) {
                        quads.push(UiQuad2D {
                            x0: ix as f32 + 2.0,
                            y0: iy as f32 + 2.0,
                            x1: (ix + iw) as f32 - 2.0,
                            y1: (iy + ih) as f32 - 2.0,
                            u0: 0.0,
                            v0: 0.0,
                            u1: 1.0,
                            v1: 1.0,
                            color: 0xFFFF_FFFF,
                            tex_id: Some(port_tid),
                            clip_rect: None,
                        });
                    }
                }
            }
            InWorldModal::Inventory => {
                if let Some(it_atlas) = &self.scene_3d.item_icons {
                    let it_tid = it_atlas.tex_id;
                    let item_cnt = self.sample_items.len().max(1);
                    for eq_slot in 0..=12usize {
                        let cname = format!("Equip_{eq_slot:02}");
                        if let Some((ix, iy, iw, ih)) = self.ingame_ui.find_control_screen_rect(
                            &self.game.aui_manager,
                            "Win_InventoryM",
                            &cname,
                            w,
                            h,
                        ) {
                            let (u0, v0, u1, v1) =
                                if let Some(it) = self.sample_items.get(eq_slot % item_cnt) {
                                    it_atlas.uv_for_name(&it.icon_dds, it.id as usize)
                                } else {
                                    it_atlas.uv_for_index(
                                        (eq_slot * 29 + 14) % it_atlas.total_icons.max(1),
                                    )
                                };
                            quads.push(UiQuad2D {
                                x0: ix as f32 + 1.0,
                                y0: iy as f32 + 1.0,
                                x1: (ix + iw) as f32 - 1.0,
                                y1: (iy + ih) as f32 - 1.0,
                                u0,
                                v0,
                                u1,
                                v1,
                                color: 0xFFFF_FFFF,
                                tex_id: Some(it_tid),
                                clip_rect: None,
                            });
                        }
                    }
                    for slot in 0..24usize {
                        let cname = format!("Item_{slot:02}");
                        if let Some((ix, iy, iw, ih)) = self.ingame_ui.find_control_screen_rect(
                            &self.game.aui_manager,
                            "Win_InventoryM",
                            &cname,
                            w,
                            h,
                        ) {
                            let idx = (slot + self.list_scroll) % item_cnt;
                            let (u0, v0, u1, v1) = if let Some(it) = self.sample_items.get(idx) {
                                it_atlas.uv_for_name(&it.icon_dds, it.id as usize)
                            } else {
                                it_atlas.uv_for_index(
                                    ((slot + self.list_scroll) * 19 + 45)
                                        % it_atlas.total_icons.max(1),
                                )
                            };
                            quads.push(UiQuad2D {
                                x0: ix as f32 + 1.0,
                                y0: iy as f32 + 1.0,
                                x1: (ix + iw) as f32 - 1.0,
                                y1: (iy + ih) as f32 - 1.0,
                                u0,
                                v0,
                                u1,
                                v1,
                                color: 0xFFFF_FFFF,
                                tex_id: Some(it_tid),
                                clip_rect: None,
                            });
                        }
                    }
                    for slot in 1..=24usize {
                        let cname = format!("Item_{slot:02}");
                        if let Some((ix, iy, iw, ih)) = self.ingame_ui.find_control_screen_rect(
                            &self.game.aui_manager,
                            "Win_Bag",
                            &cname,
                            w,
                            h,
                        ) {
                            let idx = (slot + 23 + self.list_scroll) % item_cnt;
                            let (u0, v0, u1, v1) = if let Some(it) = self.sample_items.get(idx) {
                                it_atlas.uv_for_name(&it.icon_dds, it.id as usize)
                            } else {
                                it_atlas.uv_for_index(
                                    (slot * 23 + 120 + self.list_scroll)
                                        % it_atlas.total_icons.max(1),
                                )
                            };
                            quads.push(UiQuad2D {
                                x0: ix as f32 + 1.0,
                                y0: iy as f32 + 1.0,
                                x1: (ix + iw) as f32 - 1.0,
                                y1: (iy + ih) as f32 - 1.0,
                                u0,
                                v0,
                                u1,
                                v1,
                                color: 0xFFFF_FFFF,
                                tex_id: Some(it_tid),
                                clip_rect: None,
                            });
                        }
                    }
                }
            }
            InWorldModal::SkillBook => {
                let cls = self
                    .game
                    .host_player
                    .as_ref()
                    .map(|p| p.profession as i32)
                    .unwrap_or(0);
                let skills = ElementSkill::skills_for_class(cls);
                if let Some(sk_atlas) = &self.scene_3d.skill_icons {
                    let sk_tid = sk_atlas.tex_id;
                    for (i, sk) in skills.iter().take(24).enumerate() {
                        let cname = format!("Initiative_{:02}", i + 1);
                        if let Some((ix, iy, iw, ih)) = self.ingame_ui.find_control_screen_rect(
                            &self.game.aui_manager,
                            "Win_Skill",
                            &cname,
                            w,
                            h,
                        ) {
                            let (u0, v0, u1, v1) = sk_atlas.uv_for_name(sk.icon, sk.id as usize);
                            quads.push(UiQuad2D {
                                x0: ix as f32 + 1.0,
                                y0: iy as f32 + 1.0,
                                x1: (ix + iw) as f32 - 1.0,
                                y1: (iy + ih) as f32 - 1.0,
                                u0,
                                v0,
                                u1,
                                v1,
                                color: 0xFFFF_FFFF,
                                tex_id: Some(sk_tid),
                                clip_rect: None,
                            });
                        }
                    }
                    for (p_idx, sk) in skills.iter().rev().take(8).enumerate() {
                        let cname = format!("Passive_{:02}", p_idx + 1);
                        if let Some((ix, iy, iw, ih)) = self.ingame_ui.find_control_screen_rect(
                            &self.game.aui_manager,
                            "Win_Skill",
                            &cname,
                            w,
                            h,
                        ) {
                            let (u0, v0, u1, v1) = sk_atlas.uv_for_name(sk.icon, sk.id as usize);
                            quads.push(UiQuad2D {
                                x0: ix as f32 + 1.0,
                                y0: iy as f32 + 1.0,
                                x1: (ix + iw) as f32 - 1.0,
                                y1: (iy + ih) as f32 - 1.0,
                                u0,
                                v0,
                                u1,
                                v1,
                                color: 0xFFFF_FFFF,
                                tex_id: Some(sk_tid),
                                clip_rect: None,
                            });
                        }
                    }
                    let tree_dlg = format!("Win_Skill{}", cls.clamp(0, 7));
                    if let Some(tree_layout) = self.game.aui_manager.dialogs.get(&tree_dlg) {
                        let tree_ctrls: Vec<String> = tree_layout
                            .controls
                            .iter()
                            .filter(|c| {
                                c.name.len() > 6 && c.name[..6].eq_ignore_ascii_case("skill_")
                            })
                            .map(|c| c.name.clone())
                            .collect();
                        for (n_idx, cname) in tree_ctrls.iter().enumerate() {
                            if let Some((ix, iy, iw, ih)) = self.ingame_ui.find_control_screen_rect(
                                &self.game.aui_manager,
                                &tree_dlg,
                                cname,
                                w,
                                h,
                            ) {
                                let cn_key = &cname[6..];
                                let (u0, v0, u1, v1) = if let Some(st) = skills
                                    .iter()
                                    .find(|s| s.name == cn_key || s.name.contains(cn_key))
                                {
                                    sk_atlas.uv_for_name(st.icon, st.id as usize)
                                } else {
                                    sk_atlas.uv_for_name(&format!("{cn_key}.dds"), n_idx + 20)
                                };
                                quads.push(UiQuad2D {
                                    x0: ix as f32 + 1.0,
                                    y0: iy as f32 + 1.0,
                                    x1: (ix + iw) as f32 - 1.0,
                                    y1: (iy + ih) as f32 - 1.0,
                                    u0,
                                    v0,
                                    u1,
                                    v1,
                                    color: 0xFFFF_FFFF,
                                    tex_id: Some(sk_tid),
                                    clip_rect: None,
                                });
                            }
                        }
                    }
                }
            }
            InWorldModal::QuestLog => {
                if let Some((tx, ty, tw, th)) = self.ingame_ui.find_control_screen_rect(
                    &self.game.aui_manager,
                    "Win_Quest",
                    "Tv_Quest",
                    w,
                    h,
                ) {
                    let clip = Some((tx + 3, ty + 3, (tw - 21).max(8), (th - 6).max(8)));
                    let mut seen_q = std::collections::HashSet::new();
                    for (i, q) in self
                        .game
                        .tasks_db
                        .top_tasks
                        .iter()
                        .filter(|q| {
                            let t = q.name.trim();
                            !t.is_empty() && !pw_data::has_cjk(t) && seen_q.insert(t.to_string())
                        })
                        .skip(self.list_scroll)
                        .take(11)
                        .enumerate()
                    {
                        let col = if i == 0 { 0xFFFF_E282 } else { 0xFFD8_F5D0 };
                        texts.push(UiText2D {
                            x: tx + 8,
                            y: ty + 8 + (i as i32) * 21,
                            size_px: 12,
                            color: col,
                            text: q.name.trim().to_string(),
                            shadow: true,
                            clip_rect: clip,
                        });
                    }
                }
            }
            InWorldModal::Boutique => {
                if let Some(it_atlas) = &self.scene_3d.item_icons {
                    let it_tid = it_atlas.tex_id;
                    if let Some(featured) = self
                        .game
                        .gshop_db
                        .items
                        .get(self.list_scroll)
                        .or_else(|| self.game.gshop_db.items.first())
                    {
                        if let Some((ix, iy, iw, ih)) = self.ingame_ui.find_control_screen_rect(
                            &self.game.aui_manager,
                            "Win_QShop",
                            "Img_Item",
                            w,
                            h,
                        ) {
                            let (u0, v0, u1, v1) =
                                it_atlas.uv_for_name(&featured.icon_dds, featured.item_id as usize);
                            quads.push(UiQuad2D {
                                x0: (ix + 32) as f32,
                                y0: (iy + 32) as f32,
                                x1: (ix + iw - 32) as f32,
                                y1: (iy + ih - 32) as f32,
                                u0,
                                v0,
                                u1,
                                v1,
                                color: 0xFFFF_FFFF,
                                tex_id: Some(it_tid),
                                clip_rect: None,
                            });
                        }
                    }
                    for slot in 0..8usize {
                        let cname = format!("Lab_Dialog{slot}");
                        if let (Some(it), Some((lx, ly, lw, lh))) = (
                            self.game.gshop_db.items.get(self.list_scroll + slot),
                            self.ingame_ui.find_control_screen_rect(
                                &self.game.aui_manager,
                                "Win_QShop",
                                &cname,
                                w,
                                h,
                            ),
                        ) {
                            let clip = Some((lx, ly, lw.max(8), lh.max(8)));
                            let (u0, v0, u1, v1) =
                                it_atlas.uv_for_name(&it.icon_dds, it.item_id as usize);
                            quads.push(UiQuad2D {
                                x0: (lx + 6) as f32,
                                y0: (ly + 18) as f32,
                                x1: (lx + 38) as f32,
                                y1: (ly + 50) as f32,
                                u0,
                                v0,
                                u1,
                                v1,
                                color: 0xFFFF_FFFF,
                                tex_id: Some(it_tid),
                                clip_rect: clip,
                            });
                            texts.push(UiText2D {
                                x: lx + 44,
                                y: ly + 42,
                                size_px: 11,
                                color: 0xFFFF_D878,
                                text: format!(
                                    "{} Gold  (x{})",
                                    (it.local_id % 9 + 1) * 50,
                                    it.item_num
                                ),
                                shadow: true,
                                clip_rect: clip,
                            });
                        }
                    }
                }
            }
            InWorldModal::NpcDialog => {
                if let Some((lx, ly, lw, lh)) = self.ingame_ui.find_control_screen_rect(
                    &self.game.aui_manager,
                    "Win_NPC",
                    "Lst_Main",
                    w,
                    h,
                ) {
                    let clip = Some((lx + 4, ly + 3, (lw - 20).max(8), (lh - 6).max(8)));
                    let opts = [
                        "• Teleport Service (Midlands Map)",
                        "• Treasure Boutique (605 Items)",
                        "• Quest & Cultivation Log",
                        "• Farewell",
                    ];
                    for (oi, opt) in opts.iter().enumerate() {
                        texts.push(UiText2D {
                            x: lx + 8,
                            y: ly + 6 + (oi as i32) * 22,
                            size_px: 12,
                            color: 0xFFFF_DF82,
                            text: (*opt).to_string(),
                            shadow: true,
                            clip_rect: clip,
                        });
                    }
                }
            }
            InWorldModal::DevConsole => {
                quads.push(UiQuad2D {
                    x0: 0.0,
                    y0: 0.0,
                    x1: 680.0,
                    y1: 210.0,
                    u0: 0.0,
                    v0: 0.0,
                    u1: 1.0,
                    v1: 1.0,
                    color: 0xDC0C_121A,
                    tex_id: None,
                    clip_rect: None,
                });
                let cclip = Some((4, 4, 672, 202));
                for (i, ln) in self.console_log.iter().rev().take(8).rev().enumerate() {
                    texts.push(UiText2D {
                        x: 12,
                        y: 10 + (i as i32) * 20,
                        size_px: 12,
                        color: 0xFFA8_F8B8,
                        text: ln.clone(),
                        shadow: true,
                        clip_rect: cclip,
                    });
                }
                texts.push(UiText2D {
                    x: 12,
                    y: 180,
                    size_px: 13,
                    color: 0xFFFF_F098,
                    text: format!("> {}|", self.console_input),
                    shadow: true,
                    clip_rect: cclip,
                });
            }
            InWorldModal::ActionPanel => {
                if let Some(act_atlas) = &self.scene_3d.action_icons {
                    let act_tid = act_atlas.tex_id;
                    let groups: &[(&str, usize, usize)] = &[
                        ("BscCmd", 16, 0),
                        ("TeamCmd", 8, 14),
                        ("TradeCmd", 8, 20),
                        ("FaceCmd", 32, 24),
                    ];
                    for &(prefix, cnt, base_idx) in groups {
                        for idx in 1..=cnt {
                            let cname = format!("{prefix}_{idx:02}");
                            if let Some((ix, iy, iw, ih)) = self.ingame_ui.find_control_screen_rect(
                                &self.game.aui_manager,
                                "Win_Action",
                                &cname,
                                w,
                                h,
                            ) {
                                let (u0, v0, u1, v1) = act_atlas.uv_for_index(
                                    (base_idx + idx - 1) % act_atlas.total_icons.max(1),
                                );
                                quads.push(UiQuad2D {
                                    x0: ix as f32 + 1.0,
                                    y0: iy as f32 + 1.0,
                                    x1: (ix + iw) as f32 - 1.0,
                                    y1: (iy + ih) as f32 - 1.0,
                                    u0,
                                    v0,
                                    u1,
                                    v1,
                                    color: 0xFFFF_FFFF,
                                    tex_id: Some(act_tid),
                                    clip_rect: None,
                                });
                            }
                        }
                    }
                }
            }
            InWorldModal::FriendList | InWorldModal::SystemSettings => {}
            InWorldModal::GuildManage => {
                let (dx, dy, dw, dh) = self
                    .ingame_ui
                    .find_dialog_screen_rect(&self.game.aui_manager, "Win_GuildManage", w, h)
                    .unwrap_or((w as i32 / 2 - 220, h as i32 / 2 - 170, 440, 340));
                let clip = Some((dx + 12, dy + 28, (dw - 24).max(80), (dh - 44).max(80)));
                let fname = pw_data::strip_cjk_fallback(&self.faction_summary.name, "Vanguard");
                let fann = pw_data::strip_cjk_fallback(
                    &self.faction_summary.announce,
                    "Rally at Archosaur West!",
                );
                texts.push(UiText2D {
                    x: dx + 22,
                    y: dy + 42,
                    size_px: 13,
                    color: 0xFFFF_E082,
                    text: format!(
                        "Faction: {}  (Lv.{}  |  {}/200 Members)",
                        fname, self.faction_summary.level, self.faction_summary.member_count
                    ),
                    shadow: true,
                    clip_rect: clip,
                });
                texts.push(UiText2D {
                    x: dx + 22,
                    y: dy + 64,
                    size_px: 12,
                    color: 0xFFA8_E8FF,
                    text: format!("Proclamation: {fann}"),
                    shadow: true,
                    clip_rect: clip,
                });
                for (ri, row) in [
                    "1. Archosaur      | Master   | Lv.100 Blademaster | Online",
                    "2. SylphWing      | Director | Lv.101 Archer      | Online",
                    "3. AbyssTide      | Marshal  | Lv.100 Assassin    | Online",
                    "4. VenoFox        | Executor | Lv.99  Venomancer  | Online",
                    "5. TigerLord      | Captain  | Lv.100 Barbarian   | Online",
                ]
                .iter()
                .enumerate()
                {
                    texts.push(UiText2D {
                        x: dx + 22,
                        y: dy + 96 + (ri as i32) * 22,
                        size_px: 12,
                        color: 0xFFE8_F0FA,
                        text: (*row).to_string(),
                        shadow: true,
                        clip_rect: clip,
                    });
                }
            }
            InWorldModal::TerritoryMap => {
                let (dx, dy, dw, dh) = self
                    .ingame_ui
                    .find_dialog_screen_rect(&self.game.aui_manager, "GuildMap", w, h)
                    .unwrap_or((w as i32 / 2 - 280, h as i32 / 2 - 210, 560, 420));
                let clip = Some((dx + 10, dy + 24, (dw - 20).max(120), (dh - 36).max(120)));
                let map_x0 = dx + 18;
                let map_y0 = dy + 54;
                let map_w = (dw - 220).max(200);
                let map_h = (dh - 76).max(180);
                if let Some(wtid) = self.scene_3d.world_map_tex_id {
                    quads.push(UiQuad2D {
                        x0: map_x0 as f32,
                        y0: map_y0 as f32,
                        x1: (map_x0 + map_w) as f32,
                        y1: (map_y0 + map_h) as f32,
                        u0: 0.0,
                        v0: 0.0,
                        u1: 1.0,
                        v1: 1.0,
                        color: 0xE8FF_FFFF,
                        tex_id: Some(wtid),
                        clip_rect: clip,
                    });
                }
                let total_domains = self.game.domain_db.zones.len();
                texts.push(UiText2D {
                    x: dx + 18,
                    y: dy + 30,
                    size_px: 13,
                    color: 0xFFFF_E082,
                    text: format!(
                        "Territory War Map ({total_domains} Domains | Max {} Simultaneous Battles)",
                        self.game.domain_db.max_simultaneous_battles
                    ),
                    shadow: true,
                    clip_rect: clip,
                });
                // Plot all 47 `domain.data` territory badges (`Tier 1/2/3` color-coded!)
                for z in &self.game.domain_db.zones {
                    let nx = (z.center_x as f32 / 1024.0).clamp(0.04, 0.96);
                    let ny = (z.center_y as f32 / 1024.0).clamp(0.04, 0.96);
                    let px = map_x0 + (nx * map_w as f32) as i32;
                    let py = map_y0 + (ny * map_h as f32) as i32;
                    let tier_col = match z.point {
                        3 => 0xE0FF_5848, // Tier 1 Capital (Archosaur / Thousand Streams)
                        2 => 0xE0FF_C848, // Tier 2 Major City
                        _ => 0xD858_D8FF, // Tier 3 Province
                    };
                    quads.push(UiQuad2D {
                        x0: (px - 4) as f32,
                        y0: (py - 4) as f32,
                        x1: (px + 4) as f32,
                        y1: (py + 4) as f32,
                        u0: 0.0,
                        v0: 0.0,
                        u1: 1.0,
                        v1: 1.0,
                        color: tier_col,
                        tex_id: None,
                        clip_rect: clip,
                    });
                }
                // List featured owned/contestable territories on the right ledger
                for (ri, z) in self
                    .game
                    .domain_db
                    .zones
                    .iter()
                    .skip(self.list_scroll)
                    .take(10)
                    .enumerate()
                {
                    let zname = pw_data::strip_cjk_fallback(&z.name, &format!("Zone #{}", z.id));
                    let owner = self
                        .territory_owners
                        .get(&(z.id as u16))
                        .map(String::as_str)
                        .unwrap_or("Unclaimed");
                    texts.push(UiText2D {
                        x: map_x0 + map_w + 10,
                        y: map_y0 + (ri as i32) * 20,
                        size_px: 11,
                        color: if owner == "Unclaimed" {
                            0xFFC8_D8EA
                        } else {
                            0xFF88_F8A8
                        },
                        text: format!("#{:02} {} [{}]", z.id, zname, owner),
                        shadow: true,
                        clip_rect: clip,
                    });
                }
            }
            InWorldModal::PetBag => {
                let (dx, dy, dw, dh) = self
                    .ingame_ui
                    .find_dialog_screen_rect(&self.game.aui_manager, "Win_PetList", w, h)
                    .unwrap_or((60, 120, 320, 280));
                let clip = Some((dx + 10, dy + 24, (dw - 20).max(80), (dh - 34).max(80)));
                texts.push(UiText2D {
                    x: dx + 16,
                    y: dy + 32,
                    size_px: 13,
                    color: 0xFFFF_E082,
                    text: format!(
                        "Pet Bag ({}/5 Active Slots) — {}",
                        self.pet_slots.len(),
                        if self.summoned_pet_idx.is_some() {
                            "Summoned"
                        } else {
                            "Standby"
                        }
                    ),
                    shadow: true,
                    clip_rect: clip,
                });
                for (pi, (pname, pinfo)) in self.pet_slots.iter().enumerate() {
                    let clean_nm = pw_data::strip_cjk_fallback(pname, "Companion");
                    texts.push(UiText2D {
                        x: dx + 16,
                        y: dy + 60 + (pi as i32) * 26,
                        size_px: 12,
                        color: if self.summoned_pet_idx == Some(pi) {
                            0xFF88_FF98
                        } else {
                            0xFFE8_F0FA
                        },
                        text: format!(
                            "[{}] {} Lv.{} | HP {}/{} | Loyalty {}",
                            pi + 1,
                            clean_nm,
                            pinfo.level,
                            pinfo.hp,
                            pinfo.max_hp,
                            pinfo.loyalty
                        ),
                        shadow: true,
                        clip_rect: clip,
                    });
                }
            }
            InWorldModal::MailBox => {
                let (dx, dy, dw, dh) = self
                    .ingame_ui
                    .find_dialog_screen_rect(&self.game.aui_manager, "Win_MailList", w, h)
                    .unwrap_or((w as i32 / 2 - 200, h as i32 / 2 - 150, 400, 300));
                let clip = Some((dx + 10, dy + 24, (dw - 20).max(80), (dh - 34).max(80)));
                texts.push(UiText2D {
                    x: dx + 18,
                    y: dy + 34,
                    size_px: 13,
                    color: 0xFFFF_E082,
                    text: format!("Mailbox Inbox ({} Messages)", self.mail_headers.len()),
                    shadow: true,
                    clip_rect: clip,
                });
                for (mi, mh) in self.mail_headers.iter().take(8).enumerate() {
                    let sender = pw_data::strip_cjk_fallback(&mh.sender_name, "Postmaster");
                    let title = pw_data::strip_cjk_fallback(&mh.title, "Parcel");
                    texts.push(UiText2D {
                        x: dx + 18,
                        y: dy + 64 + (mi as i32) * 24,
                        size_px: 12,
                        color: 0xFFE8_F0FA,
                        text: format!("[#{:02}] {}: {}", mh.mail_id, sender, title),
                        shadow: true,
                        clip_rect: clip,
                    });
                }
            }
            InWorldModal::AuctionHouse => {
                let (dx, dy, dw, dh) = self
                    .ingame_ui
                    .find_dialog_screen_rect(&self.game.aui_manager, "Win_AuctionList", w, h)
                    .unwrap_or((w as i32 / 2 - 240, h as i32 / 2 - 170, 480, 340));
                let clip = Some((dx + 10, dy + 24, (dw - 20).max(80), (dh - 34).max(80)));
                texts.push(UiText2D {
                    x: dx + 18,
                    y: dy + 34,
                    size_px: 13,
                    color: 0xFFFF_E082,
                    text: format!(
                        "Auction House & Gold Stock | Gold: {} | Coins: {}",
                        self.stock_cash_gold, self.stock_coins
                    ),
                    shadow: true,
                    clip_rect: clip,
                });
                for (ai, (iname, au)) in self.auction_items.iter().take(7).enumerate() {
                    let clean_nm = pw_data::strip_cjk_fallback(iname, "Treasure");
                    texts.push(UiText2D {
                        x: dx + 18,
                        y: dy + 64 + (ai as i32) * 24,
                        size_px: 12,
                        color: 0xFFD8_F0FF,
                        text: format!(
                            "#{}: {} (x{}) | Bid {} | Buyout {}",
                            au.auction_id, clean_nm, au.count, au.bid_price, au.bin_price
                        ),
                        shadow: true,
                        clip_rect: clip,
                    });
                }
            }
            InWorldModal::PlayerTrade => {
                let (dx, dy, dw, dh) = self
                    .ingame_ui
                    .find_dialog_screen_rect(&self.game.aui_manager, "Win_Trade", w, h)
                    .unwrap_or((80, 130, 340, 320));
                let clip = Some((dx + 10, dy + 24, (dw - 20).max(80), (dh - 34).max(80)));
                texts.push(UiText2D {
                    x: dx + 18,
                    y: dy + 34,
                    size_px: 13,
                    color: 0xFFFF_E082,
                    text: "Secure Player Trade — Lock & Confirm Ready".to_string(),
                    shadow: true,
                    clip_rect: clip,
                });
            }
            InWorldModal::NpcShop => {
                let (dx, dy, dw, dh) = self
                    .ingame_ui
                    .find_dialog_screen_rect(&self.game.aui_manager, "Win_Shop", w, h)
                    .unwrap_or((110, 120, 360, 380));
                let clip = Some((dx + 12, dy + 26, (dw - 24).max(80), (dh - 36).max(80)));
                texts.push(UiText2D {
                    x: dx + 18,
                    y: dy + 36,
                    size_px: 13,
                    color: 0xFFFF_E082,
                    text: format!("Archosaur Merchant | Coins: {} | Repair All Ready", self.stock_coins),
                    shadow: true,
                    clip_rect: clip,
                });
                for (si, it) in self.sample_items.iter().take(6).enumerate() {
                    texts.push(UiText2D {
                        x: dx + 18,
                        y: dy + 64 + (si as i32) * 24,
                        size_px: 12,
                        color: 0xFFD8_F0FF,
                        text: format!("{}. {} — {} Coins", si + 1, it.name, 2_500 * (si as u32 + 1)),
                        shadow: true,
                        clip_rect: clip,
                    });
                }
            }
            InWorldModal::Warehouse => {
                let (dx, dy, dw, dh) = self
                    .ingame_ui
                    .find_dialog_screen_rect(&self.game.aui_manager, "Win_Storage", w, h)
                    .unwrap_or((120, 130, 340, 360));
                let clip = Some((dx + 12, dy + 26, (dw - 24).max(80), (dh - 36).max(80)));
                texts.push(UiText2D {
                    x: dx + 18,
                    y: dy + 36,
                    size_px: 13,
                    color: 0xFFFF_E082,
                    text: format!("Banker Stash | Stored Coins: {}", self.stash_coins),
                    shadow: true,
                    clip_rect: clip,
                });
            }
            InWorldModal::CraftProduce => {
                let (dx, dy, dw, dh) = self
                    .ingame_ui
                    .find_dialog_screen_rect(&self.game.aui_manager, "Win_Produce", w, h)
                    .unwrap_or((140, 130, 380, 360));
                let clip = Some((dx + 12, dy + 26, (dw - 24).max(80), (dh - 36).max(80)));
                texts.push(UiText2D {
                    x: dx + 18,
                    y: dy + 36,
                    size_px: 13,
                    color: 0xFFFF_E082,
                    text: "Master Manufacture (Blacksmith / Tailor / Craftsman / Apothecary)".to_string(),
                    shadow: true,
                    clip_rect: clip,
                });
            }
            InWorldModal::EquipRefine => {
                let (dx, dy, dw, dh) = self
                    .ingame_ui
                    .find_dialog_screen_rect(&self.game.aui_manager, "Win_EquipRefine", w, h)
                    .unwrap_or((160, 140, 340, 320));
                let clip = Some((dx + 12, dy + 26, (dw - 24).max(80), (dh - 36).max(80)));
                texts.push(UiText2D {
                    x: dx + 18,
                    y: dy + 36,
                    size_px: 13,
                    color: 0xFFFF_E082,
                    text: format!(
                        "Elder Refinement: +{} Mirage Celestone Aura (Press F6 to step +0..+12)",
                        self.weapon_refine_level
                    ),
                    shadow: true,
                    clip_rect: clip,
                });
            }
            InWorldModal::GenieElf => {
                let (dx, dy, dw, dh) = self
                    .ingame_ui
                    .find_dialog_screen_rect(&self.game.aui_manager, "Win_ELFProp", w, h)
                    .unwrap_or((150, 130, 360, 340));
                let clip = Some((dx + 12, dy + 26, (dw - 24).max(80), (dh - 36).max(80)));
                texts.push(UiText2D {
                    x: dx + 18,
                    y: dy + 36,
                    size_px: 13,
                    color: 0xFFFF_E082,
                    text: format!(
                        "Rising Tide Genie (Tai Chi Lv.100) | Energy: {} | Stamina: {}",
                        self.elf_vigor, self.elf_stamina
                    ),
                    shadow: true,
                    clip_rect: clip,
                });
            }
            InWorldModal::PlayerBooth => {
                let (dx, dy, dw, dh) = self
                    .ingame_ui
                    .find_dialog_screen_rect(&self.game.aui_manager, "Win_Booth", w, h)
                    .unwrap_or((150, 130, 360, 360));
                let clip = Some((dx + 12, dy + 26, (dw - 24).max(80), (dh - 36).max(80)));
                texts.push(UiText2D {
                    x: dx + 18,
                    y: dy + 36,
                    size_px: 13,
                    color: 0xFFFF_E082,
                    text: format!("Cat-Shop Booth: {}", self.booth_slogan),
                    shadow: true,
                    clip_rect: clip,
                });
            }
            InWorldModal::PkAutolock => {
                let (dx, dy, dw, dh) = self
                    .ingame_ui
                    .find_dialog_screen_rect(&self.game.aui_manager, "Win_PKSetting", w, h)
                    .unwrap_or((180, 160, 320, 240));
                let clip = Some((dx + 12, dy + 24, (dw - 24).max(80), (dh - 32).max(80)));
                texts.push(UiText2D {
                    x: dx + 18,
                    y: dy + 36,
                    size_px: 13,
                    color: if self.pvp_enabled { 0xFFFF_7878 } else { 0xFF88_FF98 },
                    text: format!(
                        "PK Mode: {} | Safety Lock: {} min",
                        if self.pvp_enabled { "ENABLED (Swords)" } else { "PROTECTED (Shield)" },
                        self.autolock_minutes
                    ),
                    shadow: true,
                    clip_rect: clip,
                });
            }
        }

        // Render active `ElementSkill` `TeamState` (`1..=167`) buff icons (`iconlist_state.dds`) below `Win_Hpmpxp`!
        if !self.active_buff_states.is_empty() {
            let (hx, hy, _, hh) = self
                .ingame_ui
                .find_dialog_screen_rect(&self.game.aui_manager, "Win_Hpmpxp", w, h)
                .unwrap_or((8, 8, 240, 76));
            for (bi, &sid) in self.active_buff_states.iter().take(8).enumerate() {
                let bx = hx + 68 + (bi as i32) * 24;
                let by = hy + hh + 2;
                let (_, _, icon_opt) = self.game.english_buff_info(sid as u32);
                if let (Some(st_atlas), Some(icon_name)) = (&self.scene_3d.state_icons, icon_opt) {
                    let (u0, v0, u1, v1) = st_atlas.uv_for_name(icon_name, sid as usize);
                    quads.push(UiQuad2D {
                        x0: bx as f32,
                        y0: by as f32,
                        x1: (bx + 20) as f32,
                        y1: (by + 20) as f32,
                        u0,
                        v0,
                        u1,
                        v1,
                        color: 0xFFFF_FFFF,
                        tex_id: Some(st_atlas.tex_id),
                        clip_rect: None,
                    });
                }
            }
        }
    }

    /// Renders the complete 3D Angelica scene + 2D `AUIManager` UI into a CPU `FrameBuffer`
    /// (used for headless verification, `.bmp` screenshots, and non-D3D9 software fallback).
    pub fn render(&mut self, fb: &mut FrameBuffer, mouse_x: i32, mouse_y: i32) {
        let pf = self.prepare_frame(fb.width, fb.height, mouse_x, mouse_y);
        render_scene_and_ui_cpu(
            fb,
            &mut self.scene_3d,
            &self.game.vfs,
            pf.eye,
            pf.dir,
            pf.up,
            &pf.cam_proj,
            &pf.actors,
            &pf.ui_quads,
            &pf.ui_texts,
            pf.anim_time,
        );
    }
}

fn build_offline_archetype_roster() -> Vec<CharacterSummary> {
    vec![
        CharacterSummary {
            role_id: 1024,
            name: "Archosaur".into(),
            gender: 0,
            race: 0,
            occupation: 0, // Blademaster
            level: 100,
            level2: 30,
            pos: (0.0, 0.0, 0.0),
            world_tag: 1,
        },
        CharacterSummary {
            role_id: 1025,
            name: "SylphWing".into(),
            gender: 1,
            race: 3,
            occupation: 6, // Archer
            level: 101,
            level2: 30,
            pos: (0.0, 0.0, 0.0),
            world_tag: 1,
        },
        CharacterSummary {
            role_id: 1026,
            name: "AbyssTide".into(),
            gender: 1,
            race: 1,
            occupation: 5, // Assassin
            level: 100,
            level2: 20,
            pos: (0.0, 0.0, 0.0),
            world_tag: 1,
        },
        CharacterSummary {
            role_id: 1027,
            name: "VenoFox".into(),
            gender: 1,
            race: 2,
            occupation: 3, // Venomancer
            level: 99,
            level2: 20,
            pos: (0.0, 0.0, 0.0),
            world_tag: 1,
        },
        CharacterSummary {
            role_id: 1028,
            name: "TigerLord".into(),
            gender: 0,
            race: 2,
            occupation: 4, // Barbarian
            level: 100,
            level2: 30,
            pos: (0.0, 0.0, 0.0),
            world_tag: 1,
        },
    ]
}

#[allow(dead_code)]
fn extract_section_names(
    game: &CecGame,
    sec_idx: usize,
    limit: usize,
    fallbacks: &[&str],
) -> Vec<String> {
    let mut out = Vec::new();
    if let Some(ElementSectionData::FixedTable {
        record_size,
        count,
        raw_records,
    }) = game.elements_db.sections.get(sec_idx)
    {
        let rsz = *record_size;
        if rsz >= 68 {
            for i in 0..(*count).min(limit * 4) {
                let slice = &raw_records[i * rsz + 4..i * rsz + 68];
                let nm = decode_utf16le_null_terminated(slice);
                let trimmed = nm.trim();
                if !trimmed.is_empty() && trimmed.chars().count() >= 2 {
                    out.push(trimmed.to_string());
                    if out.len() >= limit {
                        break;
                    }
                }
            }
        }
    }
    if out.len() < limit {
        for &fb in fallbacks {
            if out.len() >= limit {
                break;
            }
            out.push(fb.to_string());
        }
    }
    out
}

fn extract_element_item_previews(game: &CecGame) -> Vec<ElementItemPreview> {
    let mut out = Vec::new();
    for &(sec_idx, name_off, label) in &[
        (3usize, 12usize, "Weapon"),
        (6, 12, "Armor"),
        (9, 12, "Ornament"),
        (12, 12, "Medicine"),
        (23, 4, "Aerogear"),
    ] {
        if let Some(ElementSectionData::FixedTable {
            record_size,
            count,
            raw_records,
        }) = game.elements_db.sections.get(sec_idx)
        {
            let rsz = *record_size;
            if rsz < name_off + 64 {
                continue;
            }
            for i in 0..(*count).min(16) {
                let off = i * rsz;
                let rec = &raw_records[off..off + rsz];
                let id = u32::from_le_bytes([rec[0], rec[1], rec[2], rec[3]]);
                let name = decode_utf16le_null_terminated(&rec[name_off..name_off + 64]);
                let icon_dds = find_embedded_dds_path(rec);
                if !name.trim().is_empty() {
                    out.push(ElementItemPreview {
                        section_name: label,
                        id,
                        name: name.trim().to_string(),
                        icon_dds,
                    });
                }
            }
        }
    }
    out
}

fn find_embedded_dds_path(rec: &[u8]) -> String {
    for i in 0..rec.len().saturating_sub(4) {
        if rec[i..i + 4].eq_ignore_ascii_case(b".dds") {
            let mut st = i;
            while st > 0 && rec[st - 1] >= 0x20 {
                st -= 1;
            }
            return decode_gbk_null_terminated(&rec[st..i + 4]);
        }
    }
    String::new()
}
