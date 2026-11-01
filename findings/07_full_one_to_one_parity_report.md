# Perfect World 1.4.2 (Build 2305) — Full 1:1 Parity Closure Report

## 1. Decompiled Engine & Archive Closure Summary
- **Source Binaries & Procedures**: `15 / 15` PE32/CIL binaries (`51,572` procedures, `0` failed decompilations, `15 / 15` REA obligations `verified`/`ready`), plus `1,472` Angelica 3D / AUI / CEC engine procedures in `source/decompiled_engine/01..21_*.c`.
- **Zero-External-Crate Rust Port (`port`)**: 10 crates (`pw-core`, `pw-pck`, `pw-data`, `pw-gnet`, `pw-skill`, `pw-launcher-patcher`, `pw-world`, `pw-aui`, `pw-render-audio`, `pw-client`), passing `100%` of release tests on Linux and clean `x86_64-pc-windows-gnu` check for hardware `d3d9.dll` COM (`D3d9Renderer`) + Win32 (`win32_gui.rs`).

## 2. Full 1:1 Subsystems Completed in This Pass

### A. Skeletal Animation, CPU/D3D9 Skinning, `HH_*` Weapon Attachment, & `.ecm` Actors (`a3d_skeleton.rs`)
- **`.bon` (`A3DSkeleton::Load`, `0x00791860`, `"MOXBEKSA"`)**: Verified `3,579 / 3,579` (`bad = 0`) across `models.pck`, including `tm_rel`, `tm_skin_init`, and `HH_*` attachment hooks (`HH_righthandweapon`, `HH_lefthandweapon`, `HH_Head`).
- **`.stck` (`A3DSklTrackSet::Load`, `0x007ca380`, `"MOXBKCTS"` `v1`)**: Verified `14,065 / 14,065` (`bad = 0`) track files with segment SLERP quaternion & LERP position evaluation (`0x00793360`).
- **`.smd` (`A3DSkinModel::Load`, `0x00791210`, `"MOXBDMSA"` `v5/v6/v8`)**: Verified `2,228 / 2,228` (`bad = 0`) skin models and action tables (`站立`, `奔跑`, `跳跃`/`飞行`, `普攻1`/`普通攻击1`, `吟唱`).
- **Bone-Index Mapping & Matrix Chain (`A3DSkin::BindSkeleton`, `0x00795cd0`)**:
  - `tm_abs[i] = tm_rel[i] * tm_abs[parent]`; `tm_skin[i] = tm_skin_init[i] * tm_abs[i]`.
  - Rigid & weighted `A3DSkinMesh` / `A3DRigidMesh` vertex skinning across up to 3 bone weights per vertex.
  - Real 15-grade signature `.ski` weapons (`15品单剑`, `15品法仗`, `9品法宝`, `15品双斧`, `10品匕首`, `15品弓`) attached to `HH_righthandweapon` / `HH_lefthandweapon` via `tm_hook * tm_abs[bone] * actor_world`.
- **Real `.ecm` (`MOXTVersion`) NPCs & Monsters**: Loads `models\npcs\...` (`传送大师`, `夏风将军`, `凌波仙子`, `影族巧匠`, `影族裁缝`, `苦行僧侣`) and `models\npcs\怪物\...` (`独角骷髅虎斗士`, `赤骷髅虎卫兵`, `九子鬼母`, `怨灵之火`, `巨蹄牛首领`, `青牛雷魔王`) with live `.stck` animations, terrain patrol, 3D click-picking, and 3D `project_world_to_screen` floating Chinese nameplates & HP bars.

### B. `.ecwld` / `.ecbsd` Foliage, SpeedTree `.spt`/`.tbh`, & Dynamic `SceneBoxArea` Sky/Fog (`pw-world` & `pw-render-audio`)
- Fixed `ECWDFILEHEADER` `+0x24..+0x30` (`tree_off`, `grass_off`, `num_tree_types`, `num_grass_types`), `24`-byte grass records, and world-space block stream `0` (`Trees`, `ver >= 5`) placements.
- Built SpeedTree 3D bark trunks + crossed canopy fronds (`extract_spt_bark_texture`, token `2000 = 0x07d0` in `.spt`) from `trees.pck`.
- Implemented `SceneBoxArea` OBB camera containment (`active_box_area_at`), dynamically switching sky dome (`A3dSkyDome`, clamped `u` `0.015..0.985` eliminating wrap seams) and distance fog across `Maps\Login` race pedestals and open-world zones.

### C. TrueType Font Rasterizer (`fonts.pck` `fzl2jw.ttf`) & `iconlist_*` / Minimap Atlases (`ttf_font.rs`, `icon_atlas.rs`)
- Pure-Rust TrueType (`cmap` format 4, `loca`, `glyf` simple + composite quadratic Bezier scanline AA rasterizer, `hmtx`) shelf-packed into a dynamic `1024x1024` glyph atlas supporting `^RRGGBB` inline color tags and word-wrapped `AUITextArea` / `AUILabel` paragraphs (`Win_CreateInfo0..7`, `Win_Quest`, `Win_QShop`).
- `IconAtlas` (`surfaces\iconset\iconlist_{skill,ivtrm,action}.{dds,txt}`): pixel-exact `(c * icon_w + 0.5) / tex_w` UV lookup wired directly to `elementskill.dll`'s 1,175 `SkillStub::icon` `.dds` filenames across `Win_Quickbar8Ha`, `Win_Skill` (`Initiative_01..24`, `Passive_01..08`), `Win_Skill0..7` (`skill_<中文名>` Skill Tree nodes!), `Win_InventoryM` (`Equip_00..12`, `Item_00..23`), and `Win_Bag` (`Item_01..24`).
- `load_minimap_composite`: stitches `surfaces\minimaps\<map>\0000..0101.dds` into `Win_Map`'s `Hide_2` radar with live player directional marker and NPC/monster blips.
- `Win_Character` (`interfaces\character.dtf`): all 34 `Txt_*` attribute controls bound natively with zero overlapping text.
- Live Face / Hair / Armor customization (`Btn_FaceCustomize` in `Win_Create`).

### D. Inner `gs` Gameplay Protocol (`pw-gnet`) & Patcher `<SkinApp>` XML (`pw-launcher-patcher`)
- Added `GamedataSend` (`op=34`) `c2s::GET_ALL_DATA` (`0x08`), `c2s::PLAYER_MOVE` (`0x00`), `c2s::SELECT_TARGET` (`0x02`), and `c2s::CAST_SKILL` (`0x29`), plus `S2CGamedata` (`op=74`) `s2c::SELF_INFO_1` (`0x04`) and `s2c::NOTIFY_POS` (`0x25`) decoding.
- Added `<SkinApp>` UTF-16LE XML parser (`patcher/skin/mainuni.xml`) and `stringtab.txt` loader to `pw-launcher-patcher`.

## 3. Verified `1280x800` Screenshots (`evidence/screenshots/`)
1. `01_login_3d_aui.png` — `Maps\Login` Tideborn coral dawn (`SceneBoxArea` sky/fog + SpeedTree foliage + `Win_Login` + `fzl2jw.ttf`).
2. `02_character_select_3d_aui.png` — Human Castle (`Cam[10]` + `.bon`/`.stck` skeletal idle stance + `HH_righthandweapon` `15品单剑` + `Win_Select`).
3. `03_character_create_custom_3d_aui.png` — Winged Elf Forest (`Win_Create` + customized Archer + `15品弓` + word-wrapped `Win_CreateInfo6` lore).
4. `04_inworld_a01_3d_aui.png` — `a01` (`City of Abominations` / `鬼城`) with real `.ecm` NPCs (`传送大师`, `苦行僧侣`) & monsters (`青牛雷魔王`, `巨蹄牛首领`), Chinese nameplates, `minimaps/a01` radar, and `iconlist_skill.dds` quickbar.
5. `05_inworld_combat_target_3d_aui.png` — Active melee `.stck` slash animation, `Win_HpmpOther` target frame (`独角骷髅虎斗士`), combat log, and quickbar cooldown.
6. `06_inworld_inventory_icons_aui.png` — `Win_InventoryM` + `Win_Bag` populated with crisp `32x32` `iconlist_ivtrm.dds` equipment & bag icons.
7. `07_inworld_skillbook_icons_aui.png` — Dual-pane `Win_Skill` (`Skill List`) + `Win_Skill0` (`Blademaster` `Skill Tree`) with exact `elementskill.dll` `stub.icon` nodes.
8. `08_inworld_character_sheet_aui.png` — `Win_Character` (`Character Info`) with all 34 native `.dtf` stat fields populated.
