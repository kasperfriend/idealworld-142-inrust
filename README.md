# Perfect World 1.4.2 (*Rising Tide*, Build 2305) — 1:1 Rust Client, Engine & Tooling Suite

A clean-room, **zero-external-dependency Rust port** (`40,300+` lines of Rust across 10 modular crates, `35 / 35` automated tests passing with `0` warnings) of the **Perfect World 1.4.2 (`Build 2305`, `ElementSkill` ABI v15)** game client, Angelica 3D / AUI engine, GNET networking stack, launcher, patcher, and binary database toolset.

Every parser, wire protocol, shader formula, animation track, and UI widget is grounded directly in **`51,572 / 51,572` decompiled native procedures** (`0` failures across all `15` original PE32/.NET binaries via [REA](https://github.com/morluto/rea) + Ghidra `12.1.4`), with **100% pure original English localization (`0` Chinese character leaks)**.

---

## Table of Contents

1. [Repository Structure](#1-repository-structure)
2. [Architecture: The 10 Rust Crates](#2-architecture-the-10-rust-crates)
3. [Quick Start: Build, Test & Attach Game Assets](#3-quick-start-build-test--attach-game-assets)
4. [All Capabilities & How to Use Every Tool](#4-all-capabilities--how-to-use-every-tool)
   - [4.1 Offline 3D Open-World Sandbox (No Server Required)](#41-offline-3d-open-world-sandbox-no-server-required)
   - [4.2 Live Perfect World 1.4.2 Server Connection (`glinkd:29000`)](#42-live-perfect-world-142-server-connection-glinkd29000)
   - [4.3 Character Creation, `237` Official Presets & Live 18-Section Morphing](#43-character-creation-237-official-presets--live-18-section-morphing)
   - [4.4 Complete In-Game Controls & All 19 Interactive UI Windows](#44-complete-in-game-controls--all-19-interactive-ui-windows)
   - [4.5 Developer Console (`~` / `F12`) Commands](#45-developer-console---f12-commands)
   - [4.6 Archive Extraction, `.inc` / `.x` Patching & Config Inspection (`pw-patcher`)](#46-archive-extraction-inc--x-patching--config-inspection-pw-patcher)
   - [4.7 Client Launcher & Hardware Preset Detection (`pw-launcher`)](#47-client-launcher--hardware-preset-detection-pw-launcher)
   - [4.8 Localization Auditing & String Table Exporting (`pw-elementlocalize`)](#48-localization-auditing--string-table-exporting-pw-elementlocalize)
   - [4.9 Binary `.data` Version & Timestamp Auditing (`pw-data-versions`)](#49-binary-data-version--timestamp-auditing-pw-data-versions)
   - [4.10 Headless 20-Scene `1280×800` Regression Screenshot Suite](#410-headless-20-scene-1280800-regression-screenshot-suite)
   - [4.11 Using the Crates as Libraries in Your Own Rust Tools](#411-using-the-crates-as-libraries-in-your-own-rust-tools)
5. [Subsystem Parity Matrix](#5-subsystem-parity-matrix)
6. [Reverse-Engineering Reports & Evidence Index](#6-reverse-engineering-reports--evidence-index)

---

## 1. Repository Structure

```text
.
├── .github/workflows/ci.yml      # GitHub Actions CI (Linux + Windows release build & test suite)
├── .gitignore                    # Excludes proprietary multi-GB .pck/.pkx/.data/.exe/.dll assets from Git
├── README.md                     # Complete project documentation, setup & usage guide
├── port/                         # 10-crate zero-dependency Rust workspace (40,300+ LOC)
│   ├── Cargo.toml
│   └── crates/                   # pw-core, pw-pck, pw-data, pw-gnet, pw-skill, pw-launcher-patcher,
│                                 # pw-world, pw-aui, pw-render-audio, pw-client
├── source/                       # Decompiled C/C# reference sources, manifest & lightweight reference configs
│   ├── ARCHIVE_MANIFEST.tsv      # Complete 2,240-entry inventory (sizes + CRC-32) of a standard PW 1.4.2 client
│   ├── decompiled_engine/        # 21 subsystem C modules (87,039 lines / 1,472 Angelica & ElementClient functions)
│   ├── decompiled_highlights/    # 30 annotated C entrypoints (CECGame::Init, CECFace::Init, PCK, tasks, GNET)
│   ├── reconstructed_csharp/     # 1:1 C# CIL reconstruction of PW Data Versions.exe
│   └── pw142/                    # Reference .ini/.cfg/.xml files & 237 official character presets (drop full client here!)
├── findings/                     # 11 technical specifications & architecture reports (00..10)
└── evidence/                     # Machine-readable reverse-engineering ledgers, traces & rendered screenshots
    ├── ledgers/                  # procedure_ledger_all_51572.jsonl.gz, RTTI vtables, GNET opcodes, skill catalog
    ├── rea_traces/               # 112 REA + Ghidra 12.1.4 JSON inspection manifests across all 15 binaries
    ├── screenshots/              # 23 rendered 1280x800 PNG verification frames
    └── verification_logs/        # Release test & Windows cross-target compiler transcripts
```

---

## 2. Architecture: The 10 Rust Crates

All 10 crates use **`std` only (zero crates.io dependencies)** plus runtime dynamic FFI to standard OS libraries (`d3d9.dll`, `d3dcompiler_47.dll`, `user32.dll`, `gdi32.dll`, `imm32.dll`, `winmm.dll` on Windows; `libX11.so.6`, `libasound.so.2`, `libz.so.1` on Linux, with pure-Rust fallbacks):

| Crate | Responsibility |
|---|---|
| **`pw-core`** | 3D math (`Vec3`, `Quat`, `Mat4`, `Aabb`), `AFileImage` / `MOXB` / `MOXT` binary cursors, GBK & UTF-16LE XOR (`m_ID`) codecs, `.ini` parser, CLI path resolvers, and pure-Rust RFC 1950/1951 `zlib`/DEFLATE codec. |
| **`pw-pck`** | Angelica `v2.0.2` `.pck` and split `.pck`+`.pkx` archive reader (`from_path` / `from_bytes`), lossless archive builder (`PckBuilder`), and case-insensitive `VirtualFileSystem` (`.pck` + loose disk override). |
| **`pw-data`** | Exact zero-remainder (`DIFF = 0`) parsers & writers for `elements.data` (v27, 131 sections, 37,676 records), `tasks.data` (v75, 17,787 quest nodes), `dyn_tasks.data` (v10), `task_npc.data`, `gshop.data` (605 items), `domain.data` (47 Territory War zones), `aipolicy.data` (1,371 AI policies), 18-section (`106`-field) `CharacterCustomizeIni`, `CustomizePresetCatalog` (`237` `.ini`s), and `EnglishLocalizationTables` (`skillstr.txt`, `buff_str.txt`, `fixed_msg.txt`, `item_ext_desc.txt`). |
| **`pw-gnet`** | Complete Build 2305 `210`-class `GNET::*` outer protocol registry (`4..5032`), `CompactUINT` / `OctetsStream`, RFC 1321 MD5 / HMAC-MD5, RC4 stream cipher, MPPC history-sliding decompressor, non-blocking live TCP `GLinkLiveClient`, and `56` `s2c` / `52` `c2s` inner `gs` (`GamedataSend` opcode `34`) packet codecs. |
| **`pw-skill`** | Complete `ElementSkill.dll` ABI v15 catalog: all `1,175` `SkillStub`s, `ElementSkill::evaluate_level_params()` (`Lv.1..10` MP, cast/channel/cooldown, range, weapon %, flat bonus damage), `69` `VisibleState` `.gfx` aura descriptors, and `167` `TeamState` buff/debuff descriptors. |
| **`pw-launcher-patcher`** | Ports of `Launcher.exe`, `patcher.exe` (UTF-16LE `mainuni.xml` skin + RGB color-map hit-testing, `stringtab.txt`, `update.cfg`, `video.cfg`, `resolution.txt`, `PatcherIncManifest`), `PackDLL.dll` (`.x` stream codec, `PACKDLL_CANONICAL_PACK_STEMS`, `PackDllMutablePck`), `SysInfo.dll`, and `PW Data Versions.exe`. |
| **`pw-world`** | Angelica outdoor map streaming: `.ecwld` (v12), `.ecbsd`, `.trn2` (`88`-tile Midlands `maps/world` `8192m × 11264m` dynamic `3×3` streaming), `.t2bk` height/normal blocks, `.t2hc`, `.t2mk` splat masks, `.t2lm` lightmaps, `bsdata` water/grass, `scenectrl.ini`, and `precinct.clt` zones/BGM. |
| **`pw-aui`** | Angelica `AUIManager` UI engine (`30` `AUI*` RTTI classes): parses all `459` `.dtf` dialogs (`20/20` control types), `483` `.stf` string tables, and `177` `.htf` hint tables; `AUIClockIcon` radial clockwise sweeps (`aui_clock_icon_contains_uv`), `AUITextArea` rich tags (`^RRGGBB`, `&item&`, `[emo]`, `@coord@`), `AUITreeView`, `AUIComboBox`, `AUISlider`, and `Layout/*.ini`. |
| **`pw-render-audio`** | Hardware Direct3D 9 (`d3d9.dll`) renderer with runtime-compiled **4-pass `ps_2_0` HLSL shaders** (Terrain + Underwater Caustics, Skin Specular/Rim, Schlick Fresnel Water, Radial Additive `.gfx` Particles) + perspective-exact 4x anisotropic / trilinear multi-core CPU rasterizer; `.bon`/`.stck` (`SLERP`)/`.smd`/`.ski`/`.ecm`/`.bmd`/`.mox`/`.spt` 3D models; `CECFace` (`0x559250`) + asymmetric 18-section morphing; `A3DGFXEx` `.gfx` particles; pure-Rust **Ogg Vorbis I (`vorbis_synth.rs`)** + PCM/IMA-ADPCM `.wav` decoder; and 3D stereo-panned hardware audio (`WinMM PlaySoundW` on Windows, `libasound.so.2` ALSA PCM on Linux). |
| **`pw-client`** | Full `CECGame::Init` boot pipeline, `InteractiveClientApp` state machine (`Login`, `CharacterSelect`, `CreateCharacter`, `InWorld` + all `19` HUD/economy/social/refinement/Genie/territory modals), native Win32 & Linux X11 window loops, `pw-elementclient`, and `pw-elementlocalize`. |

---

## 3. Quick Start: Build, Test & Attach Game Assets

### Prerequisites
- **Rust stable toolchain** (`1.75+`, install via [rustup.rs](https://rustup.rs)) — **no external C libraries or crates.io downloads required**.
- *(Optional, for full 3D gameplay & asset tools)*: A standard **Perfect World 1.4.2 (`Build 2305`, *Rising Tide*)** client folder (`element/`, `launcher/`, `patcher/`, `config/`).

### Step 1 — Clone & Verify Standalone Build + Tests Immediately
Even before attaching multi-gigabyte `.pck` game archives, the entire workspace builds and passes all standalone protocol, codec, Vorbis IMDCT, PCK, AUI, and reference-config tests out of the box:

```bash
cd port
cargo test --workspace --release
```

### Step 2 — Attach Your Perfect World 1.4.2 Client Files
Choose whichever layout fits your workflow best:

- **Method A — Extract into `source/pw142/` (Auto-Detected)**:
  Copy or extract your Perfect World 1.4.2 client into `source/pw142/` so that `source/pw142/element/configs.pck`, `models.pck`, `surfaces.pck`, `textures.pck`, `facedata.pck`, `litmodels.pck`, `building.pck`, `trees.pck`, `sfx.pck`, `data/elements.data`, and `maps/world/` are present. (`.gitignore` automatically ignores binary game archives so `git status` remains clean.)
- **Method B — Keep Your Game Folder Anywhere via Environment Variables**:
  ```bash
  # Linux / macOS:
  export PW142_ROOT="/path/to/pw142"
  export PW142_ELEMENT_DIR="/path/to/pw142/element"

  # Windows PowerShell:
  $env:PW142_ROOT = "D:\Games\pw142"
  $env:PW142_ELEMENT_DIR = "D:\Games\pw142\element"
  ```
  *(You can also pass `/path/to/pw142` or `/path/to/pw142/element` directly as the first CLI argument to any binary.)*

### Step 3 — Build Native Release Executables

```bash
cd port
cargo build --workspace --release
```

This produces **5 standalone native binaries** in `port/target/release/` (with `.exe` on Windows):
1. **`pw-elementclient`** — Full 3D Angelica + AUI Perfect World 1.4.2 game client (Direct3D 9 + WinMM on Windows; X11 + ALSA on Linux)
2. **`pw-launcher`** — Hardware preset detector, `serverlist.txt` inspector & client/patcher launcher
3. **`pw-patcher`** — `.pck` inspector, VFS file extractor & `.inc` / `.x` archive patcher (`PackDLL` port)
4. **`pw-elementlocalize`** — Pure-English CJK auditor & UTF-8 TSV localization table exporter
5. **`pw-data-versions`** — Binary `.data` schema version & UTC timestamp inspector

*(Cross-compiling native 64-bit Windows Direct3D 9 `.exe` binaries from Linux is also supported out of the box once `mingw-w64` is installed: `cargo build --workspace --release --target x86_64-pc-windows-gnu`.)*

---

## 4. All Capabilities & How to Use Every Tool

### 4.1 Offline 3D Open-World Sandbox (No Server Required)

You can explore the entire 3D world (`maps/world` Midlands across all 88 tiles — Archosaur, City of the Plume, Etherblade, City of Raging Tides, City of the Lost — as well as `maps/a01` and `maps/login`), test all 4 races / 8 classes, fly on racial aerogears, cast skills with `.gfx` particle bursts, and interact with all 19 UI windows **completely offline without running a server**:

```bash
cd port
cargo run --release --bin pw-elementclient -- /path/to/pw142/element --offline
```

> **Tip**: If you launch without `--offline`, the client opens on the animated 3D Login Pantheon (`maps/login`). Press **`F5`** at any time on the Login screen to jump straight into Offline Character Select & Open-World Sandbox mode.

---

### 4.2 Live Perfect World 1.4.2 Server Connection (`glinkd:29000`)

`pw-elementclient` implements the complete Build 2305 `glinkd` wire handshake (`Challenge` -> HMAC-MD5 `Response` -> `KeyExchange` RC4 + MPPC -> `OnlineAnnounce` -> `RoleList` -> `SelectRole` -> `EnterWorld` -> `GamedataSend` `c2s`/`s2c`).

1. **Via Command-Line Flags**:
   ```bash
   cd port
   cargo run --release --bin pw-elementclient -- /path/to/pw142/element \
     --connect 127.0.0.1:29000 --user myaccount --pass mypassword
   ```
2. **Via Classic `elementclient.exe` / `eSTART.bat` Arguments** (drop-in compatible with existing launchers & `.bat` scripts):
   ```bash
   pw-elementclient startbypatcher nocheck game:cpw console:1 server:127.0.0.1:29000 user:myaccount pwd:mypassword
   ```
3. **Via `element/userdata/server/serverlist.txt`**:
   Edit `element/userdata/server/serverlist.txt` (`<ServerName>\t<Port>:<Host>\t<Group>`), launch `pw-elementclient`, select your server in `Win_Login`, type your credentials, and press `Enter`.

---

### 4.3 Character Creation, `237` Official Presets & Live 18-Section Morphing

On the **Character Creation (`Win_Create`)** screen:
- **Choose Race, Profession & Gender**: Click the Race / Profession / Gender controls for Human (*Blademaster*, *Wizard*), Tideborn (*Psychic*, *Assassin*), Untamed (*Venomancer*, *Barbarian*), or Winged Elf (*Archer*, *Cleric*).
- **Cycle All `237` Official English Appearance Presets**: Press **`Tab`**, **`PgUp`**, or **`PgDn`** to cycle through every official `userdata/character/{customize,customize1}/*.ini` preset (*Mystical*, *Refined*, *Steadfast*, *Dashing*, *Contemporary*, *Sassy*, *Urban*, *Gothika*, etc.), updating 3D hair, face textures, and bone/vertex proportions immediately.
- **Live `[Body]` & Asymmetric `CECFace` Sliders**:
  - **`Up` / `Down` Arrows** — Morph head scale (`headScale`) and horizontal face width (`scaleFaceH`).
  - **`[` / `]` Keys** — Morph chest/torso (`upScale`), waist (`waistScale`), arm width (`armWidth`), and leg width (`legWidth`).
  - **`Left` / `Right` Arrows** — Rotate your character on the 3D creation pedestal.

---

### 4.4 Complete In-Game Controls & All 19 Interactive UI Windows

#### Movement, Combat & Camera
| Input | Action |
|---|---|
| `W` / `A` / `S` / `D` | Move forward / strafe left / backward / strafe right |
| `Space` | Jump (on ground) / Ascend (while flying) |
| `C` *(while flying)* | Descend altitude |
| `Shift` | Sprint |
| **`F`** | Toggle 3D Racial Aerogear Flight (Flying Sword, Elf Wings, Untamed Mount, Tideborn Wings) |
| **Right Mouse Drag** | Orbit 3D third-person camera |
| **Mouse Wheel** | Zoom 3D camera in/out (or scroll active list inside open UI windows) |
| **Left Mouse Click** | Click UI controls, select 3D NPCs/Monsters, or click-to-teleport on `WorldMap` |
| `Tab` | Cycle target lock across nearby monsters (`Win_HpOther` target frame) |
| **`1` .. `8`** | Cast Quickbar skills (`Lv.10` evaluated formulas, `AUIClockIcon` radial cooldown sweep, `.gfx` spell bursts & 3D spatial SFX) |
| `Enter` | Focus / send message in `Win_ChatSmall` (supports `/d_...` console commands) |
| `[` / `]` | Rewind / advance dynamic time-of-day (`A3DSkySphere` sun/ambient transition) |
| `F9` | Toggle active map between Midlands Continent (`world`) and `a01` |
| `F11` | Toggle borderless fullscreen |
| `Esc` | Close active modal window / clear current target |

#### All 19 In-World HUD & Modal Windows
| Hotkey | Window (`AUIDialog`) | Features |
|---|---|---|
| **`B`** | **Inventory (`Win_Inventory`)** | Equipped gear slots, bag grid (`iconlist_ivtrm.dds`), coin & gold balances, item hover tooltips |
| **`C`** *(on ground)* | **Character Sheet (`Win_Character`)** | Live `64×64` 3D portrait, level, cultivation, attributes (VIT/MAG/STR/DEX), attack/defense stats |
| **`K`** or **`R`** | **Skill Book (`Win_ELFSkill`)** | Class skills (`iconlist_skill.dds`) with multi-color English `Lv.1..10` `skillstr.txt` tooltips |
| **`Q`** | **Quest Log (`Win_Quest`)** | Active & available quests from `tasks.data` (v75) and `dyn_tasks.data` (v10) |
| **`M`** | **World Map (`WorldMap`)** | Continent map (`world.dds`, `54` waypoints, click-to-teleport); press **`Z`** to toggle regional zoom |
| **`O`** | **Treasure Boutique (`Win_QShop`)** | Browse all `605` `gshop.data` items across categories with previews & descriptions |
| **`G`** | **NPC Dialogue (`Win_NPC`)** | Talk to selected/nearest NPC (`NPC_ESSENCE` + `TALK_PROC` greeting & quest hooks) |
| **`V`** | **NPC Merchant (`Win_Shop`)** | Buy, Sell, and **Repair All** equipped gear (`c2s` `REPAIR_ALL` / `NPC_BUY`) |
| **`N`** | **Bank Warehouse (`Win_Storage`)** | Account stash items & stored coin balance (`trashbox` codecs) |
| **`I`** | **Crafting (`Win_Produce`)** | Blacksmith, Tailor, Craftsman, and Apothecary recipe manufacture |
| **`F6`** | **Elder Refinement (`Win_EquipRefine`)** | Mirage Celestone **`+0..+12` refinement** — press `F6` repeatedly (or click Refine) to step live weapon `.gfx` aura colors (Ice Blue -> Amber -> Jade -> Crimson -> Celestial Violet) |
| **`F7`** | **Elemental Genie (`Win_ELFProp`)** | *Rising Tide* Genie (`Tai Chi`) Energy, Stamina, Affinity, and Genie skill casting |
| **`F8`** | **Cat-Shop Booth (`Win_Booth`)** | Personal player market stall & booth slogan (`OPEN_BOOTH`) |
| **`F5`** | **PK & Safety Lock (`Win_PKSetting` + `Win_AutoLock`)** | Toggle PK White/Red protection (`TOGGLE_PK_MODE`) and safety lock timer |
| **`H`** | **Faction / Guild (`Win_GuildManage`)** | Guild title, level, proclamation, and online member roster (`GNET` Faction codecs) |
| **`T`** | **Territory War Map (`GuildMap`)** | Interactive map of all **`47` `domain.data` Territory War zones** (Tier `1..3` ownership & battle status) |
| **`P`** | **Pet Bag (`Win_PetList`)** | Combat pets & mounts (`s2c::PET_ROOM`) + Summon/Recall (`Win_HpmpxpPet0` HUD) |
| **`L`** | **Mailbox (`Win_MailList`)** | Player mail inbox, sender headers, coin/item attachments (`GNET` `4200..4213`) |
| **`J`** | **Auction & Gold Exchange (`Win_AuctionList`)** | Item auctions & Gold/Coin stock exchange (`GNET` `401..412`, `800..824`) |
| **`X`** | **Player Trade (`Win_Trade`)** | Secure two-party item & coin trade window (`GNET` `4001..4016`) |
| **`E`** | **Actions & Emotes (`Win_Action`)** | `56` `iconlist_action.dds` basic actions (Fly, Sit, Assist), Squad formation, Trade, and social emotes |
| **`Y`** | **Friend List (`Win_FriendList`)** | `AUITreeView` friend groups, online status, and `GNET::PrivateChat` whisper |
| **`U`** | **System Settings (`Win_SettingSystem`)** | `12` live `AUISlider`s (`Slider_Range` fog distance, `Slider_Cloud` sky clouds, `Slider_Music` / `Slider_Ambience` audio volume) |

---

### 4.5 Developer Console (`~` / `F12`) Commands

Press **`~`** (tilde) or **`F12`** in-world (or prefix with `/` in the chat box) to run engine commands:

| Command | Description |
|---|---|
| `d_help` | List all available developer console commands |
| `d_goto <x> <z>` | Teleport immediately to world coordinates `(x, z)` (e.g. `d_goto 1292 1132` for Archosaur West, `d_goto -758 -1342` for City of the Plume, `d_goto 2682 -4268` for City of Raging Tides) |
| `d_map <name>` | Stream and switch active world map (`world`, `a01`, `login`, etc.) |
| `d_fly` | Toggle aerogear flight mode |
| `d_speed <2..120>` | Set player movement speed in `m/s` |
| `d_time <0..24>` | Set time of day in hours (updates sky, fog, and sun lighting) |
| `d_skill <id>` | Bind `ElementSkill` ID (`1..1870`) to Quickbar Slot 1 and cast immediately |
| `d_refine <0..12>` | Set live weapon Mirage Celestone refinement level (`+0..+12`) and `.gfx` glow color |
| `d_pvp` | Toggle PK protection state and notify `gs` if connected |
| `d_c2scmd <opcode>` | Send a raw inner `gs` `c2s` command opcode over `GamedataSend` (`34`) |

---

### 4.6 Archive Extraction, `.inc` / `.x` Patching & Config Inspection (`pw-patcher`)

`pw-patcher` is a complete CLI replacement for `patcher.exe` + `PackDLL.dll`:

```bash
cd port

# 1. Inspect mainuni.xml skin, stringtab.txt, update.cfg, video.cfg, resolution.txt & all 16 .pck versions:
cargo run --release --bin pw-patcher -- /path/to/pw142

# 2. Extract any single file out of a .pck (or split .pck + .pkx) archive:
cargo run --release --bin pw-patcher -- --extract /path/to/pw142/element/configs.pck "configs\\skillstr.txt" ./skillstr.txt

# 3. Apply a Perfect World incremental patch manifest (v_from_to.inc + .x compressed files) into element/*.pck:
cargo run --release --bin pw-patcher -- /path/to/pw142 --apply-inc ./v_141_142.inc ./patch_payload_dir

# 4. Verify archives and immediately launch pw-elementclient:
cargo run --release --bin pw-patcher -- /path/to/pw142 --play
```

---

### 4.7 Client Launcher & Hardware Preset Detection (`pw-launcher`)

```bash
cd port

# Inspect CPU/RAM hardware preset (SysInfo.dll parity), launcher.ini, stringtab.txt & serverlist.txt:
cargo run --release --bin pw-launcher -- /path/to/pw142

# Launch pw-patcher or spawn pw-elementclient directly with original PW 1.4.2 flags:
cargo run --release --bin pw-launcher -- /path/to/pw142 --patcher
cargo run --release --bin pw-launcher -- /path/to/pw142 --play
```

---

### 4.8 Localization Auditing & String Table Exporting (`pw-elementlocalize`)

```bash
cd port

# Summarize NPC talk trees, quest nodes, AI talk ops, Boutique items & localization tables,
# verify ZERO Chinese characters across all skills & 459 .dtf UI dialogs, and export UTF-8 TSV:
cargo run --release --bin pw-elementlocalize -- /path/to/pw142/element \
  --verify-english \
  --export-tsv ./pw142_localization_export.tsv
```

---

### 4.9 Binary `.data` Version & Timestamp Auditing (`pw-data-versions`)

1:1 port of `PW Data Versions.exe` inspecting `elements.data`, `tasks.data`, `gshop.data`, `gshop1.data`, `gshopsev.data`, `gshopsev1.data`, `domain.data`, and `aipolicy.data`:

```bash
cd port
cargo run --release --bin pw-data-versions -- /path/to/pw142/element/data
```

---

### 4.10 Headless 20-Scene `1280×800` Regression Screenshot Suite

Render a deterministic 20-frame visual tour across Login, Character Select, Character Create, `a01`, Midlands cities (Archosaur, Plume City, Etherblade, Raging Tides, City of the Lost), Aerogear Flight, World Map, Combat, and AUI modals:

```bash
cd port
cargo run --release --bin pw-elementclient -- /path/to/pw142/element --screenshots ./rendered_shots
```

---

### 4.11 Using the Crates as Libraries in Your Own Rust Tools

Because the workspace is cleanly split into 10 crates, you can import individual crates to build custom `.pck` modders, `.data` editors, custom headless GNET bots/load-testers, or custom servers:

```rust
// Read & write Angelica v2.0.2 .pck archives (`pw-pck`)
let pkg = pw_pck::PckArchive::open_path("element/configs.pck")?;
let skillstr_bytes = pkg.read_by_path("configs\\skillstr.txt")?;

// Parse & round-trip elements.data v27 with zero remainder (`pw-data`)
let raw = std::fs::read("element/data/elements.data")?;
let db = pw_data::ElementsDatabase::parse_exact(&raw)?;
assert_eq!(db.to_bytes(), raw);

// Evaluate any of the 1,175 ElementSkill v15 skills at Lv.1..10 (`pw-skill`)
let skill = pw_skill::ElementSkill::create(1, 10).unwrap();
let stats = skill.evaluate_level_params();

// Decode Ogg Vorbis I or IMA-ADPCM .wav into 16-bit PCM (`pw-render-audio`)
let clip = pw_render_audio::decode_audio_auto(&audio_bytes).unwrap();
```

---

## 5. Subsystem Parity Matrix

| # | Subsystem | Parity | Verification |
|---|---|---|---|
| 1 | **Static Binary Reverse Engineering (`15/15` EXEs/DLLs)** | **100.0%** | `51,572 / 51,572` procedures decompiled (`0` failed); `1,134` RTTI classes |
| 2 | **Angelica VFS & `.pck` / `.pkx` Archive Engine (`pw-pck`)** | **100.0%** | Lossless `v2.0.2` `.pck` / `.pkx` read, write, & in-memory `from_bytes` |
| 3 | **Binary Databases (`elements`, `tasks`, `dyn_tasks`, `gshop`, `domain`, `aipolicy`)** | **100.0%** | Exact `DIFF = 0` byte-for-byte EOF across all `10` `.data` tables |
| 4 | **Pure Original English Localization (`0` CJK)** | **100.0%** | Automated `0`-CJK audit across `1,179` skills, `459` `.dtf`s & all `19` modals |
| 5 | **`ElementSkill.dll` ABI v15 (`1,175` Skills, `69` VisibleStates, `167` TeamStates)** | **100.0%** | Exact `Lv.1..10` `evaluate_level_params()` + `.gfx` & `iconlist_state.dds` |
| 6 | **Launcher, Patcher, `PackDLL`, `SysInfo`, `elementlocalize`, `PW_Data_Versions`** | **100.0%** | UTF-16LE configs, `mainuni.xml` hit-testing, `.x`/`.inc` patching, `PackDllMutablePck` |
| 7 | **`GNET` Outer (`210` Classes) + Inner `gs` `GamedataSend` Wire Stack (`pw-gnet`)** | **100.0%** | Live TCP RC4/MPPC tunnel + `56` `s2c` & `52` `c2s` + all outer `GNET` families |
| 8 | **AUI Engine (`30` `AUI*` Classes) & `171`-Class `CDlg*` UI Suite (`pw-aui`, `pw-client`)** | **100.0%** | `AUIClockIcon` sweeps, rich tags, `459` `.dtf`s, portraits & all `19` HUD modals |
| 9 | **Midlands (`maps/world`), 4-Pass `ps_2_0` Shaders, Caustics, Mipmaps & Aniso** | **100.0%** | `88`-tile `3×3` streaming, 4x CPU / 8x D3D9 aniso + trilinear, 4 `ps_2_0` shaders |
| 10 | **Skeletal Avatars (`.bon`/`.stck` `SLERP`), `CECFace`, `237` Presets & `+1..+12` Glow** | **100.0%** | `19,872` rigs/meshes, `237` `.ini` presets, asymmetric morphing, `+1..+12` auras |
| 11 | **Direct3D 9 Backend, `.gfx` Particles, Pure-Rust Vorbis I & 3D Hardware Audio** | **100.0%** | `d3d9.dll` + `vorbis_synth.rs` + `WinMM PlaySoundW` / `libasound.so.2` ALSA |

---

## 6. Reverse-Engineering Reports & Evidence Index

- **[`findings/00_MASTER_REVERSE_ENGINEERING_REPORT.md`](findings/00_MASTER_REVERSE_ENGINEERING_REPORT.md)** — Executive reverse-engineering summary & binary corpus inventory
- **[`findings/01_binary_forensics_and_architecture.md`](findings/01_binary_forensics_and_architecture.md)** — PE32/.NET headers, compiler toolchains, imports/exports & RTTI hierarchy
- **[`findings/02_pck_archive_and_vfs_format.md`](findings/02_pck_archive_and_vfs_format.md)** — Angelica `v2.0.2` `.pck`/`.pkx` header, trailer, XOR keys & zlib index specification
- **[`findings/03_data_files_specification.md`](findings/03_data_files_specification.md)** — Byte-exact schemas for `elements.data` v27, `tasks.data` v75, `gshop.data`, `domain.data` & `aipolicy.data`
- **[`findings/04_gnet_protocol_and_opcodes.md`](findings/04_gnet_protocol_and_opcodes.md)** — Build 2305 `GNET` (`210` classes) + inner `gs` `c2s`/`s2c` wire framing, RC4 & MPPC
- **[`findings/05_angelica3d_aui_and_world_formats.md`](findings/05_angelica3d_aui_and_world_formats.md)** — `.ecwld`, `.trn2`, `.bmd`, `.mox`, `.ski`, `.bon`, `.stck`, `.ecm` & AUI `.dcf`/`.dtf` formats
- **[`findings/06_ZERO_UNKNOWN_FUNCTIONS_LEDGER.md`](findings/06_ZERO_UNKNOWN_FUNCTIONS_LEDGER.md)** — Full `51,572`-procedure classification methodology
- **[`findings/09_full_parity_and_matrix.md`](findings/09_full_parity_and_matrix.md)** — Detailed parity engineering log (`CECFace`, shaders, mipmaps, Vorbis, English localization)
- **[`findings/10_CONTINUATION_AND_GITHUB_GUIDE.md`](findings/10_CONTINUATION_AND_GITHUB_GUIDE.md)** — Developer reference & architecture guide
- **[`evidence/`](evidence/README.md)** — Machine-readable JSON/JSONL ledgers, 112 REA/Ghidra traces, compiler logs, and 23 `1280×800` rendered PNG screenshots
