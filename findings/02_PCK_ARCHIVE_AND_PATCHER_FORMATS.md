# 02 — Angelica `.pck` v2.0.2, `AFileImage`, & Patcher Archive Formats

Verified directly from `AFilePackage::Open` (`0x76fff0.c`), `AFilePackage::Close` (`0x770990.c`), `AFileImage::Open` (`0x76da20.c`), `.rdata` XOR key table (`VA 0x00987120`), `patcher/packdll.dll` (`0x10001120.c..0x10002270.c`), and lossless extraction of all **1,430 files** across `configs.pck` (72), `interfaces.pck` (1,158), `shaders.pck` (166), `fonts.pck` (2), and `help/script.pck` (32) with **0 errors**.

## 1. Angelica `.pck` / `.pkx` v2.0.2 Binary Layout

1. **12-Byte File Header (`offset 0`)**:
   - `u32 magic0 = 0x4dca23ef` (`FSIG_1`)
   - `u32 total_pack_size` (32-bit byte size across `.pck` + `.pkx` overflow span when `> 0x7fffff00`)
   - `u32 magic1 = 0x56a089b7` (`FSIG_2`)
2. **Compressed Payload Region (`offset 12 .. entry_table_offset`)**:
   - Raw or `zlib`-compressed file payloads; uncompressed when `compressed_size == uncompressed_size`.
3. **Encrypted & Compressed Entry Directory (`offset = raw_entry_offset ^ 0xa8937462`)**:
   - For each of `entry_count` files:
     - `u32 len1_enc`, `u32 len2_enc`: `entry_block_size = len1_enc ^ 0xa8937462` (verified equal to `len2_enc ^ 0xf1a43653`).
     - If `entry_block_size < 0x114` (`276` B), `zlib::uncompress` into `0x114` bytes; if `entry_block_size == 0x114`, read raw `0x114` bytes.
   - **`FILEENTRY` (`0x114` = `276` bytes)**:
     - `char szFileName[260]` (`0x00..0x104`): GBK null-terminated path normalized with `\` separators.
     - `u32 dwOffset` (`0x104`): Byte offset of payload inside archive.
     - `u32 dwLength` (`0x108`): Uncompressed byte length.
     - `u32 dwCompressedLength` (`0x10c`): Stored compressed byte length.
     - `i32 iAccessCnt` (`0x110`): Runtime access reference count (`0` on disk).
4. **280-Byte Archive Trailer (`total_size - 0x118`)**:
   - `FILEHEADER` (`272` B at `size - 0x118`):
     - `u32 dwGuardByte0 = 0xfdfdfeee`
     - `u32 dwVersion = 0x00020002` (v2.0.2)
     - `u32 dwEntryOffset = actual_entry_offset ^ 0xa8937462`
     - `u32 dwFlags` (`0x80000000` safe-header flag when bit 31 set)
     - `char szDescription[252]` (`"lica File Package, Perfect World Co. Ltd. 2002~2008. All Rights Reserved. "`)
     - `u32 dwGuardByte1 = 0xf00dbeef`
   - `u32 dwNumEntry` (`size - 8`)
   - `u32 dwTrailerVersion = 0x00020002` (`size - 4`)

## 2. `AFileImage::Open` (`0x76da20.c`) Magic Stream Framing

Angelica's virtual memory-mapped file reader checks the first 4 bytes of any opened file:
- `0x42584f4d` (`"MOXB"`): Sets binary flag `0x10` and advances stream cursor to byte `4` (used by `domain.data`, `a01.ecbsd`, `a01.cld`).
- `0x54584f4d` (`"MOXT"`): Sets text flag `0x08` and advances stream cursor to byte `4`.
- Any other 4-byte sequence: Rewinds cursor to byte `0` and defaults to text/raw mode.

## 3. `PackDLL.dll` `.x` Stream & `version.sw` Patcher Protocol

- **`CalcCompressFile` (`0x10001120.c`) / `DecompressFile` (`0x10001240.c`)**:
  - Prepends `u32_le uncompressed_len` (`4` B), followed by `zlib` stream (`compress2`), or raw bytes if `compressed_len >= uncompressed_len` (`file_size == uncompressed_len + 4`).
- **`GetPackVersion` (`0x10002270.c`) / `FillPackVersion` (`0x10002110.c`)**:
  - Reads/updates `<pack>\version.sw` (`"%d"` integer version) across the 15 client `.pck` archives (`configs` through `loddata`) and returns the minimum pack version.
