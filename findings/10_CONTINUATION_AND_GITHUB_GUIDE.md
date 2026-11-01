# 10 — Developer Continuation & GitHub Guide

This document provides everything needed to unpack the repository onto GitHub, mount your full `pw142.zip` (`3.8 GB`) Perfect World 1.4.2 client assets, build and test on Linux or Windows, and continue advancing remaining live-server and VFX polish items.

---

## 1. Repository Directory Layout

```text
.
├── README.md                     # Top-level project overview, quickstart, and architecture
├── .gitignore                    # Configured so proprietary .pck/.data/.exe/.dll assets stay out of Git
├── port/                         # Complete 10-crate zero-dependency Rust workspace (36,635 LOC)
│   ├── Cargo.toml
│   └── crates/
│       ├── pw-core/              # Math (Vec3/Mat4/Quat), GBK/UTF-16/XOR, INI, MOXB/MOXT, pure-Rust + FFI zlib
│       ├── pw-pck/               # Angelica v2.0.2 .pck & split .pck+.pkx archive reader/writer + VirtualFileSystem
│       ├── pw-data/              # Exact parsers/serializers for elements.data v27, tasks.data v75, gshop, domain, aipolicy, 18-section CECFace .ini, English skillstr/buff_str
│       ├── pw-gnet/              # GNET protocol registry (218 opcodes), RC4, HMAC-MD5, MPPC, live TCP state machine + outer social/economy & 48 s2c / 38 c2s inner gs codecs
│       ├── pw-skill/             # ElementSkill.dll ABI v15 catalog (1,175 SkillStubs + evaluate_level_params, 69 VisibleStates, 167 TeamStates)
│       ├── pw-launcher-patcher/  # Ports of Launcher.exe, patcher.exe, PackDLL.dll (.x codec), SysInfo.dll, PW_Data_Versions.exe
│       ├── pw-world/             # .ecwld v12, .ecbsd, .trn2 (88-tile Midlands streaming), .t2bk, .t2hc, .t2mk, .t2lm, bsdata water/grass, precinct.clt
│       ├── pw-aui/               # AUI .dcf/.dtf/.stf/.htf parser & runtime state machine (all 459 dialogs, 20/20 control types, 199 RTTI UI classes)
│       ├── pw-render-audio/      # Hardware D3D9 + d3dcompiler_47 ps_2_0 + perspective/anisotropic CPU rasterizer, a3d_gfx.rs (.gfx particles), audio_ogg.rs (Ogg/Vorbis + IMA-ADPCM + 3D mixer), CECFace morphing
│       └── pw-client/            # CECGame::Init, InteractiveClientApp (all 12 modals + Squad/Pet/Buff HUD), Linux X11 + Win32 native clients, and CLI binaries
├── source/                       # Decompiled C/C# reference sources, archive manifest, & lightweight reference .ini configs
│   ├── ARCHIVE_MANIFEST.tsv      # Complete 2,240-file inventory of pw142.zip (uncompressed/compressed sizes + CRC-32)
│   ├── decompiled_engine/        # 21 subsystem C files (87,039 lines / 1,472 Ghidra-decompiled functions from elementclient.exe)
│   ├── decompiled_highlights/    # 30 annotated C files for key entrypoints (CECGame::Init, CECFace::Init 0x559250, PCK, tasks, GNET, etc.)
│   ├── reconstructed_csharp/     # 1:1 C# CIL reconstruction of PW Data Versions.exe
│   └── pw142/                    # Lightweight reference configs (userdata/character/character00..71.ini, Layout/1024.ini, patcher XML); drop full pw142 here locally!
├── findings/                     # Architectural & reverse-engineering reports 00..10
└── evidence/                     # Forensic proof artifacts, procedure ledgers, REA/Ghidra JSON traces, test logs, & 23 rendered screenshots
    ├── ledgers/                  # procedure_ledger_all_51572.jsonl.gz, rtti_classes_and_vtables.json, gnet_opcodes.json, elementskill_catalog.json
    ├── rea_traces/               # 112 REA + Ghidra 12.1.4 JSON inspection/import/export/cert/decompilation manifests across all 15 binaries
    ├── screenshots/              # 01..23 1280x800 PNG renders verifying Login, CharSelect/Create, a01, Midlands cities, AUI modals, & pure English UI
    └── verification_logs/        # Clean transcripts of `cargo test --workspace --release` (32/32 ok) & `cargo check --target x86_64-pc-windows-gnu`
```

---

## 2. Attaching Your Full `pw142.zip` Game Client Locally

To keep the GitHub repository compact, clean, and free of proprietary multi-GB archives, raw `.pck`, `.data`, `.exe`, `.dll`, and `maps/` terrain blobs are listed in `.gitignore`.

After cloning/unpacking the repo on your workstation:

1. **Option A — Environment Variable (recommended, zero copying)**:
   Unzip your `pw142.zip` anywhere on disk (e.g. `D:\Games\pw142` or `~/pw142`) and export:
   ```bash
   export PW142_ROOT=/path/to/pw142
   export PW142_ELEMENT_DIR=/path/to/pw142/element
   ```
2. **Option B — In-Tree Placement**:
   Extract `pw142.zip` directly into `source/pw142/` so `source/pw142/element/configs.pck`, `models.pck`, `surfaces.pck`, `textures.pck`, `trees.pck`, `facedata.pck`, `litmodels.pck`, `building.pck`, `data/elements.data`, and `maps/world/` are all present. (`.gitignore` already ignores these binary assets so `git status` stays clean!)

---

## 3. Building, Testing, & Running

All 10 crates use **zero external Cargo dependencies** (`std` + runtime dynamic FFI to OS libraries: `libX11.so.6` / `libz.so.1` on Linux; `d3d9.dll` / `user32.dll` / `gdi32.dll` / `imm32.dll` / `winmm.dll` / `dsound.dll` on Windows), so builds succeed completely offline with zero crates.io downloads:

```bash
cd port

# 1. Run all 32 unit & integration tests (passes both standalone in CI and with full pw142 assets!)
cargo test --workspace --release

# 2. Launch the interactive 3D + AUI game client (auto-uses X11 on Linux or Direct3D 9 + Win32 on Windows)
cargo run --release --bin pw-elementclient -- /path/to/pw142/element

# 3. Connect directly to a live Perfect World 1.4.2 server (glinkd TCP 29000)
cargo run --release --bin pw-elementclient -- /path/to/pw142/element \
  --connect 127.0.0.1:29000 --user admin --pass admin

# 4. Render the automated 20-scene 1280x800 regression screenshot suite
cargo run --release --bin pw-elementclient -- /path/to/pw142/element --screenshots /tmp/pw_shots

# 5. Cross-compile native 64-bit Windows Direct3D 9 executables from Linux (requires mingw-w64)
cargo build --workspace --release --target x86_64-pc-windows-gnu
```

### CLI Utilities Included in `port/`
- `pw-elementclient` — Full interactive 3D Angelica + AUI Perfect World 1.4.2 game client
- `pw-elementlocalize` — Localization & string-table extraction/inspection tool (`elementlocalize.exe` port)
- `pw-launcher` — Game client launcher (`Launcher.exe` port)
- `pw-patcher` — `.x` stream patcher & `.pck` archive updater (`patcher.exe` + `PackDLL.dll` port)
- `pw-data-versions` — Binary schema & timestamp inspector (`PW Data Versions.exe` port)

---

## 4. In-World Hotkeys & Optional Live-Server Extensions

### In-World & Character-Create Controls (`pw-elementclient`)
- **Movement & Flight**: `WASD` move, `Space` jump / ascend, `Z` descend, `F` toggle racial aerogear flight, RMB-drag orbit camera, mouse wheel zoom.
- **Character Create Live Morphing & Official `237` Presets**: `Tab` / `PgUp` / `PgDn` cycle all official English `userdata/character/{customize,customize1}/*.ini` presets (`Mystical`, `Refined`, `Steadfast`, `Dashing`, `Contemporary`, `Sassy`, `Urban`, etc.); `[` / `]` + `Up` / `Down` adjust live `[Body]` & asymmetric `CECFace` sliders; `Left` / `Right` rotate hero pedestal.
- **Core HUD Windows & `AUIClockIcon` Sweeps**: `1..8` Cast Skills (with authentic `AUIClockIcon` clockwise radial cooldown sweep), `B` Inventory, `C` Character Sheet, `K` Skill Tree (`Lv.1..10` evaluated formulas), `Q` Quest Log, `M` World / Regional Map, `O` Treasure Boutique, `E` Emotes/Actions, `Y` Friend List, `U` System Settings (`Slider_Cloud` dynamic sky clouds).
- **Complete Social, Economy, Vendor, Bank, Crafting, Refinement, Genie, Booth, & Territory War Suite**:
  - `H` — Faction / Guild Management (`Win_GuildManage`)
  - `T` — Territory War Map (`GuildMap` — plots all **`47` `domain.data` Territory War zones** by Tier `1..3`)
  - `P` — Pet Bag (`Win_PetList` + `Win_HpmpxpPet0` active companion HUD)
  - `L` — Mailbox (`Win_MailList`)
  - `J` — Auction House & Gold Stock Exchange (`Win_AuctionList`)
  - `X` — Player-to-Player Secure Trade (`Win_Trade`)
  - `V` — NPC Merchant Buy / Sell / Repair All (`Win_Shop`)
  - `N` — Banker Account Stash & Coin Warehouse (`Win_Storage`)
  - `I` — Master Crafting / Manufacture (`Win_Produce`)
  - `F5` — PK Protection Mode & Safety Lock (`Win_PKSetting` + `Win_AutoLock`)
  - `F6` — Elder Equipment Refinement (`Win_EquipRefine` — steps live **`+0..+12` Mirage Celestone weapon socket `.gfx` aura colors**!)
  - `F7` — Rising Tide Elemental Genie (`Win_ELFProp`)
  - `F8` — Personal Cat-Shop Market Booth (`Win_Booth`)
