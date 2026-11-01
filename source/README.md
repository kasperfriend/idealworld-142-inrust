# Decompiled Reference Sources & Asset Manifest (`source/`)

This directory holds all human-readable reverse-engineered C and C# reference code extracted from the Perfect World 1.4.2 (`Build 2305`) binaries using REA (`rea-agents`) + Ghidra 12.1.4, the complete `pw142.zip` CRC-32 file manifest, and lightweight `.ini`/`.xml` configuration presets.

---

## Contents

1. **`ARCHIVE_MANIFEST.tsv`** (`2,240` rows)
   - Complete manifest of every file inside `pw142.zip` (`3,805,079,331` bytes), recording exact relative path, uncompressed byte size, compressed size, and CRC-32 checksum.

2. **`decompiled_engine/`** (`21` files, `87,039` lines / `1,472` C functions)
   - Subsystem-grouped Ghidra C decompilations of `elementclient.exe` covering `CECScene` (`.ecwld`/`.ecbsd`), `CECWorld`, `CECGame::Init`, `CECGameRun`, `WinMain`, `CECOrnament`/`Water`/`Grass`, `CECGameUIMan`, `CECLoginUIMan`, `AUIManager`/`AUIDialog`/`AUIObject` controls, `A3DCamera`/`A3DDevice`, `A3DTerrain2` (`.trn2`/`.t2bk`/`.t2mk`/`.t2lm`), `A3DSkeleton`/`A3DSkinModel`/`A3DSkin`, `A3DSkySphere`, and `A3DLitModel` (`.bmd`).

3. **`decompiled_highlights/`** (`30` annotated `.c` files)
   - Key entrypoints and format loaders including `CECGame_Init_Build2305.c`, `CECFace_Init_0x559250.c`, `AFilePackage_Open_PCK_v202.c`, `ElementDataMan_Load_elements_data_v27.c`, `ATaskTemplMan_LoadTasksFromPack_v75.c`, `CECGameSession_OnKeyExchange_RC4_MPPC.c`, `ElementSkill_Create.c`, and `PackDLL_*.c`.

4. **`reconstructed_csharp/PW_Data_Versions/`**
   - 1:1 C# source reconstruction of the .NET utility `element/data/PW Data Versions.exe`.

5. **`pw142/`** (Lightweight Reference Configs + Local Asset Mount Point)
   - Contains lightweight text configs (`config/`, `launcher/launcher.ini`, `patcher/skin/mainuni.xml`, `patcher/stringtab.txt`, `element/userdata/SystemSettings.ini`, `element/userdata/Layout/1024.ini`, `element/userdata/server/serverlist.txt`, and `element/userdata/character/character00..71.ini`).
   - **To run with full game assets locally**: Either unpack your `pw142.zip` into `source/pw142/` (binary `.pck`/`.data`/`.exe`/`.dll`/`maps/` files are already gitignored in `../.gitignore`) OR set `PW142_ELEMENT_DIR=/path/to/pw142/element`.
