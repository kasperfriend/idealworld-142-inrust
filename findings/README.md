# Reverse Engineering & Parity Findings (`findings/`)

This folder contains the complete technical reverse-engineering documentation, binary format specifications, protocol specs, and parity matrices produced while porting Perfect World 1.4.2 (`Build 2305`, *Rising Tide*) into Rust.

> **Forensic Evidence Location**: All raw machine-generated artifacts (the `51,572`-procedure decompilation ledger, `1,134` RTTI vtable dumps, `112` REA + Ghidra JSON traces, compiler/test logs, and `23` `1280×800` verification screenshots) are stored separately in [`../evidence/`](../evidence/README.md).

## Report Index

| File | Summary |
|---|---|
| [`00_MASTER_REVERSE_ENGINEERING_REPORT.md`](00_MASTER_REVERSE_ENGINEERING_REPORT.md) | Master architectural overview of all 15 Perfect World 1.4.2 binaries (`elementclient.exe`, `ElementSkill.dll`, `Launcher.exe`, `patcher.exe`, `PackDLL.dll`, `SysInfo.dll`, `PW Data Versions.exe`, etc.) and Angelica 2.2 engine subsystems. |
| [`01_BINARY_INVENTORY_AND_PE_FORENSICS.md`](01_BINARY_INVENTORY_AND_PE_FORENSICS.md) | Complete PE32 / .NET CIL header forensics, compiler toolchains, section entropy, imports/exports, and RTTI class hierarchy recovery (`1,134` classes). |
| [`02_PCK_ARCHIVE_AND_PATCHER_FORMATS.md`](02_PCK_ARCHIVE_AND_PATCHER_FORMATS.md) | Byte-exact Angelica `v2.0.2` `.pck` / `.pkx` archive trailer (`280 B`), XOR keys (`0xA8937462` / `0xF1A43653`), GBK path encoding, and `PackDLL.dll` `.x` stream compression specs. |
| [`03_DATA_FILE_SCHEMAS_ZERO_REMAINDER.md`](03_DATA_FILE_SCHEMAS_ZERO_REMAINDER.md) | Zero-remainder binary schemas (`DIFF = 0` to EOF) for `elements.data` (v27, 131 sections, 37,676 rows), `tasks.data` (v75, 17,787 nodes), `dyn_tasks.data`, `task_npc.data`, `gshop.data`, `domain.data`, and `aipolicy.data`. |
| [`04_GNET_NETWORK_PROTOCOL_AND_CRYPTO.md`](04_GNET_NETWORK_PROTOCOL_AND_CRYPTO.md) | Complete GNET outer wire protocol (`CompactUINT`, 214 `Protocol::Stub` opcodes, HMAC-MD5 challenge, RC4 + MPPC stateful compression) and Build 2305 inner `gs` `GamedataSend (34)` packet layouts. |
| [`05_ANGELICA_3D_WORLD_UI_AND_SUBSYSTEMS.md`](05_ANGELICA_3D_WORLD_UI_AND_SUBSYSTEMS.md) | Angelica 3D world formats (`.ecwld`, `.ecbsd`, `.trn2`, `.t2bk`, `.t2hc`, `.t2mk`, `.t2lm`, `.bmd`, `.mox`, `.bon`, `.ski`, `.smd`, `.ecm`) and AUI `.dcf`/`.dtf`/`.stf`/`.htf` UI architecture. |
| [`06_ZERO_UNKNOWN_FUNCTIONS_LEDGER.md`](06_ZERO_UNKNOWN_FUNCTIONS_LEDGER.md) | Methodology and verification summary for the `51,572 / 51,572` (`0` failed) native procedure decompilation ledger across all 15 binaries. |
| [`07_full_one_to_one_parity_report.md`](07_full_one_to_one_parity_report.md) | Milestone report on skeletal `.bon`/`.ski`/`.ecm` rendering (`19,872` files verified with `0` errors), D3D9 hardware backend, `fzl2jw.ttf` typography, and `IconAtlas` integration. |
| [`08_midlands_world_and_parity_matrix.md`](08_midlands_world_and_parity_matrix.md) | Midlands (`maps/world`, `8192m × 11264m`, `88` sub-terrains) dynamic `3×3` tile streaming, `bsdata` shoreline water & 3D `.mox` grass, racial aerogears, and Wine ground-truth comparison. |
| [`09_full_parity_and_matrix.md`](09_full_parity_and_matrix.md) | Latest full-parity report & percentage matrix (**`99.1%` overall**): pure original English localization (`0` CJK), `CECFace` (`0x559250`) avatars, `64×64` portraits & `Win_HpOther` monster frames, mipmaps + 4x/8x anisotropic filtering, and Angelica shaders. |
| [`10_CONTINUATION_AND_GITHUB_GUIDE.md`](10_CONTINUATION_AND_GITHUB_GUIDE.md) | Practical developer continuation guide: attaching `pw142.zip`, building/testing on Linux & Windows (`x86_64-pc-windows-gnu`), crate map, and next steps. |
