# 01 — Complete Binary Inventory & PE Forensics (All 15 Binaries)

Every executable and dynamic library inside `pw142.zip` (`17` PE file entries = `15` unique binaries + `2` byte-identical `unicows.dll` duplicates across `launcher/` and `patcher/`) was inspected with REA (`rea inspect-desktop-application`, `rea inspect-pe-imports`, `rea inspect-pe-resources`, `rea inspect-pe-load-config`, `rea inspect-pe-certificates`, `rea inspect-byte-entropy`, `rea inspect-managed-artifact`, `rea inspect-managed-members`) and decompiled 100% with `rea decompile-all --provider ghidra` (Ghidra `12.1.4`).

## 1. Binary Matrix (`51,572` Procedures, `0` Failures)

| Binary ID | Archive Path | Size (B) | SHA-256 Prefix | Procedures | RTTI / VTables | Target Rust Crate |
| :--- | :--- | ---: | :--- | ---: | ---: | :--- |
| `elementclient` | `pw142/element/elementclient.exe` | `6,000,640` | `a290998dc13cc555…` | `28,730` | `1134` / `1163` | `pw-client` |
| `elementskill` | `pw142/element/elementskill.dll` | `798,720` | `036f866f3dcacee0…` | `7,188` | `0` / `0` | `pw-skill` |
| `elementlocalize` | `pw142/element/elementlocalize.exe` | `622,592` | `20238f2fc5b5866a…` | `3,808` | `0` / `0` | `pw-launcher-patcher` |
| `patcher_exe` | `pw142/patcher/patcher.exe` | `561,152` | `cc48504d07d3ccdf…` | `2,941` | `100` / `75` | `pw-launcher-patcher` |
| `launcher_exe` | `pw142/launcher/Launcher.exe` | `421,888` | `529a822140aecb38…` | `1,863` | `45` / `40` | `pw-launcher-patcher` |
| `speedtreert` | `pw142/element/speedtreert.dll` | `450,560` | `7f0a401688f63c52…` | `3,050` | `58` / `50` | `pw-world` |
| `unicows` | `pw142/element/unicows.dll` | `258,352` | `f06f36fa03a5db49…` | `1,645` | `0` / `0` | `pw-core` |
| `ifc22` | `pw142/element/ifc22.dll` | `196,608` | `04654e83e7488851…` | `899` | `0` / `0` | `pw-core` |
| `ftdriver` | `pw142/element/ftdriver.dll` | `135,168` | `52394a8bfc07e116…` | `488` | `0` / `0` | `pw-aui` |
| `patcher_packdll` | `pw142/patcher/packdll.dll` | `73,728` | `18575cf86679c0cb…` | `248` | `0` / `0` | `pw-pck` |
| `launcher_packdll` | `pw142/launcher/PackDLL.dll` | `69,632` | `dc77813a1a38c285…` | `230` | `0` / `0` | `pw-pck` |
| `zlibwapi` | `pw142/element/zlibwapi.dll` | `72,704` | `0d38360003865e84…` | `195` | `0` / `0` | `pw-pck` |
| `sysinfo` | `pw142/patcher/SysInfo.dll` | `28,672` | `e81b14c3da009bdf…` | `180` | `0` / `0` | `pw-core` |
| `immwrapper` | `pw142/element/immwrapper.dll` | `24,576` | `845f9bf1cfcdd694…` | `92` | `0` / `0` | `pw-core` |
| `PW_Data_Versions` | `pw142/element/data/PW_Data_Versions.exe` | `12,800` | `486b3f087af2dd6a…` | `15` | `5` / `0` | `pw-data` |

### `unicows.dll` Deduplication Proof
All three copies of `unicows.dll` (`element/unicows.dll`, `launcher/unicows.dll`, `patcher/unicows.dll`) are **258,368 bytes** with identical SHA-256 digest:
`f06f36fa03a5db4980c9d1120ada1d9e558515be73eff5b7cd34c48c0d9afd35`.

## 2. `elementclient.exe` `.text` Link-Map Architecture

Because `elementclient.exe` was linked with MSVC 7.1 (`Linker 7.10`) without cross-module LTCG reordering, static libraries occupy deterministic, contiguous `.text` virtual address ranges (`0x00401000..0x008df000`):

| VA Range | Subsystem / Static Library | Key Anchors (RTTI / Source / Log Strings) | Rust Crate |
| :--- | :--- | :--- | :--- |
| `0x00401000..0x0057ffff` | `ElementClient` Core, World, Entities & UI Dialogs | `CECGame` (`0x42d700`), `CECGameRun` (`0x434b80`), `CECHostPlayer`, `201` `CDlg*` classes | `pw-client`, `pw-aui` |
| `0x00580000..0x005bffff` | `ElementClient` Customization, Matter, NPC & Skill | `CECCustomizeBound`, `CECMatterMan`, `CECNPCMan`, `CECSkill` | `pw-client` |
| `0x005c0000..0x0062ffff` | `GNET` Networking, Protocol Stubs, RC4 & MPPC | `CECGameSession` (`0x5d8c60`, `0x5d9700`), `214` `GNET::*` stub ctors (`0x5f62f0..0x618xxx`) | `pw-gnet` |
| `0x00630000..0x0065ffff` | `ElementClient` Sound Cache & BackMusic | `CECSoundCache`, `CECBackMusic` | `pw-render-audio` |
| `0x00660000..0x0067bfff` | `elementdataman` & `GlobalData` | `elementdataman::load_data` (`0x6618f0`), `talk_proc` (`0x6639b0`), `gshop`/`domain` (`0x675e10`) | `pw-data` |
| `0x0067c000..0x00694fff` | `TaskTemplMan` & `ATaskTempl` Engine | `CECTaskInterface::Init` (`0x67ccd0`), `ATaskTempl::LoadBinary` (`0x686980`, `0x687d60`) | `pw-data` |
| `0x00695000..0x00733fff` | `CECModel`, `CAutoHome`, `CECFace` | Procedural Homestead terrain/flora & character face morphing | `pw-world` |
| `0x00734000..0x00761fff` | `AngelicaUI` (`AUI*` Framework) | `AUIManager`, `AUIDialog`, `AUIObject`, `AUIFrame`, `AUILabel`, `AUIListBox` | `pw-aui` |
| `0x00762000..0x00772fff` | `AngelicaFile` (`AFilePackage`, `AFileImage`, `AMemory`) | `AFileImage::Open` (`0x76da20`), `AFilePackage::Open` (`0x76fff0`), `Close` (`0x770990`) | `pw-pck`, `pw-core` |
| `0x00773000..0x0081ffff` | `Angelica3D` (`A3DEngine`, `A3DTerrain2`, `A3DSkinModel`) | `A3DTrn2SubLoaderB` (`0x7a1ce0`), `A3DCamera`, `A3DShader`, `A3DStream` | `pw-render-audio`, `pw-world` |
| `0x00820000..0x0085bfff` | `AngelicaMedia` (`AMSoundEngine`, `AMVideoEngine`) | DirectSound3D & streaming audio buffers | `pw-render-audio` |
| `0x0085c000..0x00884fff` | Embedded Codecs (`OggVorbis`, `MP3`, `TinyXML`, `zlib`) | Static audio/XML/compression codecs | `pw-render-audio`, `pw-pck` |
| `0x00885000..0x008a4fff` | MSVC 7.1 C/C++ Runtime & STLport | `_initterm`, `operator new`, RB-tree helpers (`0x88cb10`), `__ehvec_ctor` (`0x892e84`) | `pw-core` |
| `0x008a5000..0x008df000` | MSVC SEH Frame Unwind Funclets | `11,292` `Unwind@*` / `__ehhandler` stack cleanup thunks | Eliminated via Rust RAII `Drop` |
