# Forensic Evidence, Ledgers, REA Traces, & Verification Screenshots (`evidence/`)

This directory stores all machine-verifiable reverse-engineering evidence, complete procedure/class ledgers, REA (`rea-agents` + Ghidra 12.1.4) binary forensics, automated test transcripts, and rendered `1280×800` verification screenshots.

---

## 1. `ledgers/` — Complete Decompilation & Class Ledgers

| File | Description |
|---|---|
| `procedure_ledger_all_51572.jsonl.gz` | Gzip-compressed JSON Lines ledger cataloging **all `51,572` native procedures** across all `15` Perfect World 1.4.2 PE binaries (`0` decompilation failures), with binary name, entry virtual address, byte size, signature, called addresses, and subsystem classification. |
| `rtti_classes_and_vtables.json` | Complete MSVC RTTI `TypeDescriptor` + `CompleteObjectLocator` + vtable map covering **`1,134` C++ classes** across `elementclient.exe` (including `199` AUI `CDlg*`/`AUI*` classes, `214` `GNET::*` protocol stubs, and `A3D*`/`CEC*` engine classes), `patcher.exe` (`100` classes), and `Launcher.exe` (`45` classes). |
| `elementskill_catalog.json` | Extracted catalog of all **`1,175` `GNET::SkillStub` definitions** from `elementskill.dll` (ABI v15). |
| `gnet_opcodes.json` | Extracted registry of all **`214` `GNET::Protocol::Stub`** wire opcodes, max sizes, and vtable addresses. |
| `binary_summary.json` | Exact SHA-256, byte size, architecture, and procedure counts across all `15` binaries in `pw142.zip`. |

---

## 2. `rea_traces/` — REA (`https://github.com/morluto/rea`) + Ghidra Forensics

Contains **`112` JSON artifacts** produced by `rea` (`rea inspect`, `rea decompile-all --provider ghidra`, PE certificates, section entropy, imports, exports, load configs, Win32 resources, .NET managed metadata for `PW Data Versions.exe`, and reconstruction obligation/coverage evaluations).

---

## 3. `verification_logs/` — Build & Test Transcripts

- `cargo_test_release_all_27.txt` — Full output of `cargo test --workspace --release` executing **all `27` unit and real-asset integration tests** across all 10 workspace crates (`0` failures, `0` warnings).
- `cargo_check_windows_x86_64.txt` — Clean cross-compilation verification (`cargo check --workspace --target x86_64-pc-windows-gnu`, `0` warnings, `0` errors) including `D3d9Renderer` and Win32 windowing/audio FFI.

---

## 4. `screenshots/` — `1280×800` Rendered Client Evidence (`01..23`)

- `01_login_3d_aui.png` — *Rising Tide* Login (`maps/login`) with `0x0079a330` `A3DSkySphere`, ocean water, `loginui.dcf`, and `hand.cur` gauntlet cursor.
- `02_character_select_3d_aui.png` — Character Select (`scenectrl.ini` `Cam[10+c]`, dual-wield Blademaster, `Win_Select` slot cards).
- `03_character_create_custom_3d_aui.png` — Character Create (`Cam[2+c]`, Winged Elf Archer + customization controls).
- `04_inworld_a01_3d_aui.png` — World `"a01"` (`鬼城`) with `.ecm` entities, circular `Win_Map` radar, and `St_1..4` buff icons.
- `05_inworld_combat_target_3d_aui.png` — Active combat with floating damage numbers and skill cooldown sweep.
- `06_inworld_inventory_icons_aui.png` — `Win_Inventory` (`iconlist_ivtrm.dds` `32×32` item icons).
- `07_inworld_skillbook_icons_aui.png` — `Win_ELFSkill` (`iconlist_skill.dds` skill tree).
- `08_inworld_character_sheet_aui.png` — `Win_Character` live vital & attribute sheet.
- `09_midlands_archosaur_west_3d.png` — Midlands (`maps/world` tile `38`) Archosaur West District (`529, 663`).
- `10_midlands_archosaur_aerogear_flight_3d.png` — Winged Elf aerial flight over Archosaur Central Cross-Bridge (`CC_chibang <-> HH_chibang`).
- `11_midlands_continent_worldmap_aui.png` — Full Midlands continent `WorldMap` (`world.dds` + interactive `world_targets.txt` pins).
- `12_midlands_plume_city_3d.png` — City of the Plume (`324, 416`) with `.mox` 3D grass and SpeedTree foliage.
- `13_midlands_etherblade_npc_dialog_3d.png` — Etherblade (`449, 874`) with `Win_NPC` dialogue & `tasks.data` quests.
- `14_midlands_raging_tides_3d.png` — City of Raging Tides (`668, 123`) with Tideborn `幻彩翅膀.ecm` translucent wings.
- `15_inworld_quest_log_aui.png` — `Win_Quest` (`quest.dtf`) with 9-sliced bevel frames and `normal.ani` cursor.
- `16_inworld_qshop_boutique_aui.png` — `Win_QShop` (`qshop.dtf`) Treasure Boutique (`605` `gshop.data` items).
- `17_inworld_action_emotes_aui.png` — `Win_Action` (`56` `iconlist_action.dds` icons) + `Win_Main2` + `.htf` tooltip.
- `18_inworld_system_settings_aui.png` — `Win_SettingSystem` (`12` `AUISlider`s, 3-frame checkboxes/radios, 9-sliced combos).
- `19_inworld_friendlist_hover_tooltip.png` — `Win_FriendList` + multi-color `InGameHintFrame.dds` skill tooltip.
- `20_midlands_untamed_barbarian_monster_target_3d.png` — Untamed Barbarian (`TigerLord`) targeting a monster via `Win_HpOther` (`Lv.150 No Attribute`).
- `21_plume_city_anisotropic_english_verification.png` — City of the Plume plaza verifying 4x anisotropic + trilinear mipmapped textures and pure English `Tiger Maw` / `Win_HpOther` HUD (`0` CJK).
- `22_system_settings_cloud_10px_verification.png` — `Win_SettingSystem` verifying crisp `10px` `"Cloud"` (`"0###"` font descriptor inheritance) and 4x anisotropic Archosaur masonry.
- `23_english_skillstr_tooltip_verification.png` — Pure English `configs\skillstr.txt` multi-color skill tooltip (`Earthen Rift Level 10`, `0` CJK).
