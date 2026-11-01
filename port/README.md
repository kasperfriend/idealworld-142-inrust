# Perfect World 1.4.2 (`pw142`) — 1:1 Rust Port Workspace

This 10-crate Cargo workspace (`port/`) is a clean-room, **zero-external-dependency** 1:1 Rust port of the Perfect World 1.4.2 client suite (`pw142.zip`), reverse-engineered with **`rea@6.8.0` + Ghidra `12.1.4`** (`51,572` decompiled procedures across all 15 binaries + `1,472` full Angelica 3D / AUI / CEC engine functions).

Because the workspace has **zero third-party `crates.io` dependencies**, it builds **100% offline** in ~4–8 seconds across **Windows (`x86_64-pc-windows-msvc`)**, **Linux**, and **macOS**, linking directly to OS-native Win32 (`user32.dll`, `gdi32.dll`, `kernel32.dll`, `winmm.dll`, and dynamic `d3d9.dll` COM `Direct3DCreate9`) on Windows.

---

## 1. Quick Start on Windows (`E:\pw142\element\pw-elementclient.exe`)

```powershell
cd path\to\port
cargo build --release --workspace
Copy-Item .\target\release\pw-elementclient.exe E:\pw142\element\pw-elementclient.exe -Force
E:\pw142\element\pw-elementclient.exe
```

You can also launch with `eSTART.bat` flags (`pw-elementclient.exe nocheck game:cpw console:1`), start directly in offline Character Select with `pw-elementclient.exe --offline`, or run one-shot verification with `pw-elementclient.exe --check`.

### Authentic Game Flow & Controls

- **Login Screen (`Maps\Login` `Cam[0]` + `interfaces\loginui.dcf`)**:
  - **Account / Password / Server (`Win_Login`)**: Click any `AUIEditBox` (or press **`Tab`**) to type; click **`START`** or press **`Enter`** to connect live over TCP to `userdata\server\serverlist.txt` (`glinkd:29000`, `0x00010402` `Challenge -> HMAC-MD5 KeyExchange -> C2S RC4 + S2C RC4/MPPC -> OnlineAnnounce -> RoleList`).
  - **Offline Mode (`F5`)**: Press **`F5`** at any time on the Login screen to enter Character Selection & the 3D world offline without requiring a running `glinkd` VM.
  - **Fullscreen Toggle**: Press **`F11`** or **`Alt+Enter`** to toggle borderless native/UltraWide fullscreen.
- **Character Select & Creation (`Maps\Login` `Cam[10+cls]` / `CREATE_CAM_FOR_CLASS` + `.ski` 3D Models)**:
  - Select any character slot in `Win_Select`, click **`CREATE`** to customize Name, Race, Profession (`0..7`), and Gender across `Win_Create*`, or click **`START`** / press **`Enter`** to enter the world.
- **In-World 3D Gameplay & `interfaces\ingame.dcf` HUD**:
  - **`W` / `A` / `S` / `D`** (hold **`Shift`** to sprint): Move across `A3DTerrain2` heightfields and raycast walkable `.bmd` architecture (`LoadedScene3D::sample_walkable_height`).
  - **Right-Mouse Drag** & **Mouse Wheel**: 360° 3D Orbit Camera & Zoom.
  - **`Space`**: Jump (or ascend while flying); **`F`** toggles **Aerogear Flight Mode** (**`C`** / **`Ctrl`** descends).
  - **Left-Click** / **`Tab`**: Target 3D `.ski` NPCs & Monsters; **`1`..`8`** casts real `elementskill.dll` (ABI v`15`) skills with `.dds` icons from `surfaces.pck`, cooldown sweeps, and mana/chi tracking.
  - **`B`** (`Win_InventoryM`/`F` & `Win_Bag`), **`K`** (Skill Book — `1,175` skills), **`Q`** (`Win_Quest` — `17,787` `tasks.data` v`75` nodes), **`O`** (`Win_QShop` — `605` `gshop.data` boutique items), **`M`** (`WorldMap` — `47` `domain.data` Territory War provinces + live map teleporter), **`` ` `` / `F12`** (`Dlg_Console`).

---

## 2. All 5 Native Executables Produced by `cargo build --release`

- `pw-elementclient` — 1:1 `elementclient.exe` (Build `2305`, Skill ABI v`15`) interactive Win32/D3D9 + software-fallback 3D/AUI/GNET game client
- `pw-elementlocalize` — 1:1 `elementlocalize.exe` string-table & localization tool
- `pw-launcher` — 1:1 `Launcher.exe` + `SysInfo.dll` hardware preset detector (`--play` launches `pw-elementclient`)
- `pw-patcher` — 1:1 `patcher.exe` + `PackDLL.dll` `.pck`/`.x` updater
- `pw-data-versions` — 1:1 `PW_Data_Versions.exe` data version & timestamp inspector

---

## 3. Running the Verification Test Suite

```bash
cargo test --release --workspace
cargo check --workspace --target x86_64-pc-windows-msvc --bins --lib
```

---

## 4. Crate Architecture (All 15 Binaries Covered)

| Crate | Source Binaries / Subsystems Ported | Key Capabilities |
| :--- | :--- | :--- |
| `pw-core` | `AngelicaCommon`, `zlibwapi.dll`, `unicows.dll` | Left-handed `a3d_TransformMatrix` (`0x788960`), `Mat4`/`Vec3`/`Aabb`, zero-copy LE cursors, `AFileImage` (`MOXB`/`MOXT`), cross-platform `zlib`, `GBK`/`UTF-16LE`/XOR codecs, `IniFile`. |
| `pw-pck` | `AngelicaFile` (`AFilePackage` `0x76fff0`) | Lazy seek-based `.pck`/`.pkx` v2.0.2 archive reader (mounts all `.pck`s in <5 MB RAM), lossless repacker (`PckBuilder`), and `VirtualFileSystem`. |
| `pw-data` | `elementdataman` (`0x6618f0`), `TaskTemplMan` (`0x687d60`), `GlobalData` (`0x675e10`), `CPolicyDataMan` | Exact **zero-remainder (`DIFF == 0`)** parsers & writers for `elements.data` (v27, 131 sections), `tasks.data` (v75 + XOR), `dyn_tasks.data` (v10), `task_npc.data`, `aipolicy.data`, `domain.data`, and `gshop*.data`. |
| `pw-gnet` | `CECGameSession` (`0x5d8c60`), `GNET::*` (`214` opcodes) | `CompactUINT`, `OctetsStream`, `MD5`, `HMAC-MD5`, `RC4` (`ArcFourSecurity`), stateful 8KB `MPPC` (`DecompressARCFourSecurity`), opcode registry, and live TCP `GLinkLiveClient` (`glinkd:29000`). |
| `pw-skill` | `elementskill.dll` (ABI Version `15`) | All **`1,175` `SkillStub`s, `69` `VisibleState`s, and `167` `TeamState`s** recovered from `_initterm` static initializers. |
| `pw-world` | `CECWorld`, `CECScene` (`0x422390`), `CECOrnament` (`0x489e70`), `A3DTerrain2` (`0x7a1ce0`), `A3DWaterArea` (`0x7c01f0`) | Decodes `.trn2`, `.t2bk` (`v2..v5`), `.t2mk`, `.t2lm`/`.t2lm1`, `.t2hc`, `.ecwld` v12, `.ecbsd` v12 (`ECWDFILEBOXAREA` + ornaments), `bsdata/*.dat` water areas, `scenelights.dat`, and `precinct.clt`/`region.clt`. |
| `pw-aui` | `AngelicaUI` (`AUIManager`/`AUIDialog` `0x735630`) & `199` `CDlg*` classes | Exact `TranslateAlignPos` layout, `.dcf`/`.dtf`/`.stf`/`.htf` runtime (`loginui.dcf` + `ingame.dcf`), 9-slice `AUIFrame` skinning, and `199`-class RTTI dialog registry. |
| `pw-render-audio` | `Angelica3D` (`A3DLitModel` `0x7b9eb0`, `A3DSkin` `0x79e8d0`, `A3DSkySphere` `0x79a330`, `D3D9`), `AngelicaMedia`, `ftdriver.dll` | Verified `28,858/28,858` `.bmd` litmodel & `60/60` player `.ski` loaders, `MODULATE2X` `768x768` terrain baker, `.dds` (`DXT1`/`DXT3`/`DXT5`)/`.tga`/`.bmp` decoders, `D3d9Renderer` COM + near-plane-clipped perspective software rasterizer, `SceneCtrlConfig`, `AmSoundEngine`, `shaders.pck`, `fonts.pck`. |
| `pw-client` | `elementclient.exe` (Build `2305`) + `elementlocalize.exe` | `CecGame::init`, `InteractiveClientApp` (`Login`/`CharacterSelect`/`CharacterCreate`/`InWorld`), `win32_gui` (`D3d9Renderer` + `CreateDIBSection` + ClearType + `.ani` cursors), `1,134` RTTI classes. |
| `pw-launcher-patcher` | `Launcher.exe`, `patcher.exe`, `PackDLL.dll`, `SysInfo.dll`, `PW_Data_Versions.exe` | `.x` stream codec, `version.sw`, hardware preset recommender, `pw-launcher`, `pw-patcher`, and CIL-exact `pw-data-versions` CLI binaries. |
