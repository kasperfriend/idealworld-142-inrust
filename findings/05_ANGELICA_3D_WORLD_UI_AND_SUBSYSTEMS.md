# 05 — Angelica 3D World/Model Formats, `ElementSkill` v15, & `AngelicaUI` (`199` Classes)

## 1. Map, `A3DTerrain2`, `CECScene`, & `A3DLitModel`/`A3DSkin` Formats (Verified on `maps/login/`, `maps/a01/`, `litmodels.pck`, & `models.pck`)

| File / Subsystem | Magic / Version / VA | Exact Decompiled Binary Specification |
| :--- | :--- | :--- |
| `.trn2` (`login.trn2`, `a01.trn2`) | `"TRN2"` (`0x54524e32`), v`1` | Master `A3DTerrain2` descriptor: `f32 terrain_width` (`1024.0`), `f32 terrain_length` (`1024.0`), `f32 block_size` (`64.0`), `i32 block_grid` (`32`), sub-terrain table, splat texture paths, `MODULATE2X` lightmap blend. |
| `.t2bk` (`login.t2bk`, `a01_1.t2bk`) | `"TBKB"` (`0x54424b42`), v`5`, `comp=0x35` (`0x007a1ce0`) | `256` `33x33` block offsets + `32`-byte v5 block header; bit `0x04` = `zlib` heights (`4,356B` `f32` or bit `0x08` = `2,186B` Saturn `u16` quantized), bit `0x10` = `zlib` normals (bit `0x20` = quantized), bit `0x01` = `zlib` day/night `BGRA` vertex colors. |
| `.t2mk` & `.t2lm` / `.t2lm1` | `"TMKB"` v`2`, `"T2LM"` v`2` (`0x007a1ce0`) | Per-block multi-layer splatting weights (`.t2mk`) + `DXT1`/RGB day & night terrain lightmaps (`.t2lm` / `.t2lm1`), composited with `MODULATE2X` (`2 * tex * lm`) into `768x768` per-`256m`-area textures. |
| `.ecwld` (`login.ecwld`, `a01.ecwld`) | `"ECWD"` (`0x45435744`), v`12` (`0x00422390`) | `0x74`-byte header + `256` block offsets. Each `ECWDFILEBLOCK9` (`44B` header) stores `[row:u16, col:u16, trees, water, grasses, ornaments, box_areas, effects, ecmodels, critters, beziers, sounds]` and streams `(id, bsd_off)` in exact `CECSceneBlock::Load` order (`trees, water, ornaments, box_areas, grasses, effects, ecmodels, critters, beziers, sounds`). |
| `.ecbsd` (`login.ecbsd`, `a01.ecbsd`) | `"MOXBFDSB"` + `ver:u32=12` (`0x00489e70`) | Binary Scene Data stream: `CECOrnament` (`pos:Vec3, dir:Vec3, up:Vec3, reflect:u8, refract:u8, pad:u16, astring rel_bmd`) resolved under `litmodels/<map_lower>/<rel>` (`190` ornaments in `login`, `328` in `a01`); `ECWDFILEBOXAREA` (`def:i32, flags:i32, pos:Vec3, ext:Vec3, axis[3]:36B, fog, cloud_fog:16B, light_dir, amb, dir_col, sky_textures`). |
| `bsdata/<sub_trn>.dat` | `0x10003000` (`A3DWaterArea` `0x007c01f0`) | Stores `u32 area_count` in the **4-byte file trailer (`len - 4`)** (`login.dat` = `4` ocean water areas @ `y = 229.0m`; `a01/bsdata/1.dat` = `16` bytes with `count = 0`). |
| `.bmd` (`litmodels.pck`, `28,858` files) | `"MOXB"` + `0x80000001`/`0x10000002` (`0x007b9eb0`) | Verified **`28,858 / 28,858` (`bad = 0`)**: `collide:u8` (if `0x80000001`) + `model_ver:u32`, `scale/dir/up/pos` (`48B`), `num_meshes:i32`, and per-mesh `msv = mesh_ver & 0x0FFF_FFFF` (`4` or `5`): `name[64]`, `tex[256]`, `nv:i32`, `nf:i32`, `verts[nv*24]`, `idx[nf*6]`, `nrm[nv*12]`, `day+night[nv*8]`, `A3DAABB[48]` (`0x30` bytes), `"MATERIAL: "[79] + two_sided:u8` (`80B` when `msv >= 5`), plus optional trailing `CECBuildingWithBrush` collision hulls. World matrix = `a3d_TransformMatrix(orn.dir, orn.up, orn.pos, bmd.scale)` (`0x00788960`, LH row-vector). |
| `.ski` (`models.pck`, `60/60` player meshes) | `"ASKI"` v`8`/v`9` (`0x0079e8d0`) | `A3DSkin`: texture list, `A3DMATERIALPARAM` list, `nSkinMesh` (`48B` vertices: `pos, weights[3], mat_indices:u32, normal, u, v`) + `nRigidMesh` (`32B` vertices + `bone_idx`). Prepends `-6mm`-inset `形象/{folder}/躯干/{folder}.ski` torso skin under equipment; `DXT3` alpha on body/armor is specular gloss (opaque), with cutout alpha only on `models/face` & hair. |
| `configs/scenectrl.ini` & `precinct.clt` | INI + `0xFFFE` UTF-16LE v`6` | `scenectrl.ini` stores scalar `PosX{i}/PosY{i}/PosZ{i}`, `DirX{i}/DirY{i}/DirZ{i}` (`Cam[0]` Login Sanctuary `(-78.0, 240.0, -478.0)`, `Cam[10+cls]` + `NewChar[cls]` Character Select, `CREATE_CAM_FOR_CLASS = [2,3,1,5,13,4,8,9]`). `precinct.clt` v`6` defines zone polygons, BGM playlists, and resurrection coordinates (e.g. `City of Abominations: Dragon` `(-455.42, 18.0, 420.27)`). |
| `A3DSkySphere` & `D3D9` Renderer | `0x0079a330` + `d3d9.dll` COM | `A3DSkySphere` dome (`Roof.bmp` cap + `01.bmp`/`02.bmp` cylinder skirt), `Direct3DCreate9` COM vtable (`D3d9Renderer` on Windows) + perspective-correct Sutherland-Hodgman near-plane-clipped (`cw >= 0.25`) software rasterizer (`DibSurface`). |

## 2. `elementskill.dll` (ABI Version `15`)

Walking the complete `_initterm` table (`0x10086000..0x10087624`, `1,416` non-null C++ static initializers) recovered:
- **`1,175` `GNET::SkillStub` classes** (covering Blademaster `0`, Wizard `1`, Psychic `2`, Venomancer `3`, Barbarian `4`, Assassin `5`, Archer `6`, Cleric `7`, Genie/Goblin `258`, Elf/Universal `255`/`127`), with exact UTF-16 display names, GBK native names, `.dds` icon paths, max levels, and cost/range/cooldown formulas (`findings/ledgers/elementskill_catalog.json`).
- **`69` `GNET::VisibleState` definitions** and **`167` `GNET::TeamState` definitions**.

## 3. `AngelicaUI` (`AUIManager` / `AUIDialog` `0x00735630`) & `199` RTTI Classes

- **Exact `AUIDialog::TranslateAlignPos` (`0x00735630`)** + compact `.dtf` attribute parsing (`IMAGEPICTURE` tex@`8`/`10`, `CHECK` tex@`8` `[0=Off, 1=On, 2=Dis]`, `RADIO` `(tex@8, id@9, grp@10)`), 9-slice `AUIFrame` skinning, and `surfaces.pck` `.dds`/`.tga`/`.bmp` decoding across both `interfaces\loginui.dcf` and `interfaces\ingame.dcf`.
- **All `199` `CDlg*` and `AUI*` RTTI classes** recovered at 1-byte `.rdata` alignment (`findings/ledgers/rtti_classes_and_vtables.json`) and registered in `pw-aui`.

## 4. Verified End-to-End Screenshots (`1280x800`, Real Assets & Engine Transforms)

- `findings/screenshots/01_login_screen.png` — `Maps\Login` (`Cam[0]`) + `A3DTerrain2` (`768x768`/area `MODULATE2X`) + `A3DWaterArea` (`y=229m`) + `190` `.bmd` ornaments + `loginui.dcf` `Win_Login`.
- `findings/screenshots/02_character_select.png` — `Maps\Login` (`Cam[10]`) + multi-mesh Archosaur pagoda/castle/waterfalls/bridge `.bmd`s + 3D `.ski` Blademaster + `Win_Select` (`SelectRole` / `SwitchButton`).
- `findings/screenshots/03_character_create.png` — `Maps\Login` (`CREATE_CAM_FOR_CLASS[0] = Cam[2]`) + 3D `.ski` Blademaster + `Win_CreateRace` / `Win_CreateProfession` / `Win_CreateGenderName` / `Win_RaceInfo`.
- `findings/screenshots/04_inworld_city_of_abominations.png` — `Maps\a01` (`City of Abominations: Dragon` at `(-455.4, 17.7, 420.3)`) inside multi-mesh `litmodel_527.bmd` imperial stone chamber (`building.pck` `.dds` textures), 3D `.ski` Blademaster & NPCs raycast onto `.bmd` stone tiles, and `ingame.dcf` HUD (`Win_Hpmpxp` with live 3D portrait, `Win_Map`, `Win_ChatSmall`, `Win_Quickbar8Ha`/`9Va`, `Win_Main`).
