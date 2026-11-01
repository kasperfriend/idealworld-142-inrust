# Perfect World 1.4.2 (`pw142`) — Master Reverse Engineering & 1:1 Rust Port Blueprint

## 1. Executive Summary

Using **`rea@6.8.0`** (`https://github.com/morluto/rea`) paired with **Ghidra `12.1.4` (JDK `21.0.13`)**, static PE forensics, ECMA-335 CIL metadata/instruction inspection, automated 1-byte MSVC RTTI `CompleteObjectLocator` / `vftable` recovery, and empirical byte-for-byte validation against the Perfect World 1.4.2 (`pw142.zip`) reference client archive (`3,805,079,331` bytes, `2,240` entries), we achieved **100% whole-corpus decompilation and procedure attribution** and built a complete **1:1 modular Rust workspace** in `port/`.

| Metric | Verified Value | Evidence Source |
| :--- | :--- | :--- |
| Archive Size & Digest | `3,805,079,331` B (`2,240` entries), SHA-256 `6f21fd2f3f1fae1787bc7aefb3e69591ef78d07722c5c5b7a8326b388999c6fb` | `source/ARCHIVE_MANIFEST.tsv` |
| Client Build & Skill ABI | **Build `2305`** (`DAT_00951a7c`), **`ElementSkill::GetVersion() == 15`** | `CECGame::Init` (`0x42d700.c`) |
| Total Binaries Analyzed | **15 PE Binaries** (5 `.exe`s + 10 `.dll`s; 3 `unicows.dll` copies are SHA-256 identical) | `findings/ledgers/binary_summary.json` |
| Total Procedures Decompiled | **`51,572` (`51,557` native + `15` CIL), `0` failures, `0` unknown** + **`1,472` full Angelica 3D / AUI / CEC engine decompilations** across 21 modules | `rea decompile-all` + `ledgers/procedure_ledger_all_51572.jsonl.gz` + `source/decompiled_engine/01..21_*.c` |
| REA Evidence Closure | **`15 / 15` binaries `verified` / `ready`** (`0` open obligations) | `findings/rea_evidence/` |
| Recovered C++ RTTI Classes & VTables | **`1,337` RTTI `TypeDescriptor`s, `1,328` `vftable`s** (`1,134` classes / `1,163` vtables in `elementclient.exe`) | `findings/ledgers/rtti_classes_and_vtables.json` |
| Recovered UI Dialog/Widget Classes | **`199` `CDlg*` & `AUI*` classes** with complete virtual slot tables + live `.dcf`/`.dtf`/`.stf` runtime | `rtti_classes_and_vtables.json`, `pw-aui` |
| Recovered GNET Wire Opcodes | **`214` GNET Protocol & RPC classes** with exact wire opcodes & vtables (`glinkd:29000` `0x00010402`) | `findings/ledgers/gnet_opcodes.json`, `pw-gnet` |
| Recovered Skill / State Stubs | **`1,175` `SkillStub`s, `69` `VisibleState`s, `167` `TeamState`s** (`1,411` + `5` map ctors = all `1,416` `_initterm` entries) | `findings/ledgers/elementskill_catalog.json`, `pw-skill` |
| Zero-Remainder Data & Model Verification | **10 / 10 `.data` files (`DIFF=0` across `78.7 MB`), `28,858 / 28,858` `.bmd` litmodels (`bad=0`), `60 / 60` player `.ski` meshes (`DIFF=0`), `Maps\Login` (`190` ornaments) + `Maps\a01` (`328` ornaments)** | `02..05_*.md`, `findings/screenshots/01..04_*.png` |

---

## 2. Engine & Client Architecture (`Angelica 2.2` + `CEC*` + `GNET`)

Perfect World 1.4.2 (`elementclient.exe`) is a 32-bit x86 Windows executable compiled with **Microsoft Visual C++ 7.1 (`.NET 2003`)** against **STLport** and **Direct3D 9 (`d3d9.dll` `Direct3DCreate9`)**, dynamically linking subsystem DLLs (`elementskill.dll`, `ftdriver.dll`, `immwrapper.dll`, `zlibwapi.dll`, `speedtreert.dll`, `ifc22.dll`, `unicows.dll`) and accompanied by `Launcher.exe` + `PackDLL.dll`, `patcher.exe` + `packdll.dll` + `SysInfo.dll`, `elementlocalize.exe`, and `PW_Data_Versions.exe` (`.NET 4.0`).

### Boot & Initialization Pipeline (`WinMain` `0x42bf30` -> `CECGame::Init` `0x42d700` -> `CECGameRun`)
1. **Command-Line & Single-Instance Check**: Parses arguments (`console:1`, `game:cpw`, `nofullscreen`, `nocheck`, server override) and loads `elementclient.cfg` / `SystemSettings.ini`.
2. **VFS Archive Mounting (`af_Initialize` + `AFilePackage::Open` `0x76fff0`)**: Mounts all Angelica `.pck` v2.0.2 virtual file packages (`configs.pck`, `interfaces.pck`, `shaders.pck`, `fonts.pck`, `surfaces.pck`, `models.pck`, `building.pck`, `grasses.pck`, `litmodels.pck`, `loddata.pck`, `sfx.pck`, `trees.pck`, `textures.pck`, `facedata.pck`, `gfx.pck`, `help/script.pck`).
3. **Engine Initialization**: Instantiates `A3DEngine` / `A3DDevice` (`d3d9.dll` COM `IDirect3D9` / `IDirect3DDevice9` hardware T&L + HLSL/VS/PS shaders), `AMSoundEngine`, `AMImmWrapper`, and `FTDriver` (`CreateFTManager` TrueType font renderer).
4. **Skill ABI Verification**: Calls `GNET::ElementSkill::GetVersion()` in `elementskill.dll` and enforces `version == 15` (`0x0f`).
5. **Static World Database Loading**:
   - `elementdataman::load_data("data\\elements.data")` (`0x6618f0`) — loads v27 (`0x3000001b`) 131-section item/NPC/monster/equipment/suite/pet/goblin/talk database (`37,676` records).
   - `GlobalData_Load()` (`0x675e10`) — loads `configs\\world_targets.sev`, `domain.sev` / `data\\domain.data` (47 Territory War polygons), `data\\gshop.data` + `gshop1.data` + `gshopsev.data` (605 boutique items + 8 category trees).
   - `CECTaskInterface::Init` (`0x67ccd0`) — loads `data\\tasks.data` (`0x6892f0`, v75, `6,860` top-level / `17,787` total quest nodes XOR-encrypted with `m_ID & 0xFFFF`), `data\\task_npc.data` (`1,572` NPCs), and `userdata\\dyn_tasks.data` (`6` dynamic quests).
6. **UI & 3D State Machine (`CECGameRun`)**:
   - **`STATE_LOGIN`**: Loads `Maps\Login\Login.ecwld` + `.ecbsd` + `bsdata\login.dat` + `configs\scenectrl.ini` camera presets (`Cam[0]` Login Sanctuary, `Cam[10+cls]` + `NewChar[cls]` Character Select, `CREATE_CAM_FOR_CLASS = [2,3,1,5,13,4,8,9]` Character Create) and renders `interfaces\loginui.dcf` (`Win_Login`, `Win_LoginWait`, `Win_Select`, `Win_CreateRace`, `Win_CreateProfession`, `Win_CreateGenderName`) + 3D `.ski` characters over the Rising Tide `Maps\Login` world (`findings/screenshots/01..03_*.png`).
   - **`STATE_GAME`**: Loads `Maps\a01` / `Maps\world` `.ecwld` + `.ecbsd` + `.trn2`/`.t2bk`/`.t2mk`/`.t2lm` + `litmodels.pck` `.bmd` architecture + `building.pck`/`textures.pck` `.dds` textures + `precinct.clt` resurrection halls, rendering 3D `.ski` players/NPCs and `interfaces\ingame.dcf` (`Win_Hpmpxp`, `Win_Map`, `Win_ChatSmall`, `Win_Quickbar8Ha`/`9Va`, `Win_Main`, `Win_InventoryM`/`F`, `Win_Bag`, `Win_Quest`, `Win_QShop`, `WorldMap`, `Dlg_Console`) (`findings/screenshots/04_inworld_city_of_abominations.png`), driven live by `CECGameSession` (`glinkd:29000` `Challenge` -> `KeyExchange` HMAC-MD5 + C2S RC4 + S2C RC4 + stateful 8KB MPPC).

---

## 3. Workspace Layout

- `source/` — Extracted `pw142` binaries, archives, configs, data tables, `maps/login/` & `maps/a01/`, CIL-reconstructed C# source, 29 highlight C decompilations (`decompiled_highlights/`), and 21 full Angelica 3D / AUI / CEC engine C modules (`decompiled_engine/`, `1,472` functions).
- `findings/` — Technical specifications (`00`..`06`), complete `51,572`-procedure machine-readable ledger (`ledgers/`), RTTI/GNET/Skill catalogs, REA Evidence + obligation/coverage verification JSONs (`rea_evidence/`), and 4 verified `1280x800` screenshots (`screenshots/01..04_*.png`).
- `port/` — Complete zero-external-crate 10-crate 1:1 Rust workspace (`pw-core`, `pw-pck`, `pw-data`, `pw-gnet`, `pw-skill`, `pw-world`, `pw-aui`, `pw-render-audio`, `pw-client`, `pw-launcher-patcher`) passing `23/23` release tests + `x86_64-pc-windows-msvc` target check with `0` warnings/errors.
