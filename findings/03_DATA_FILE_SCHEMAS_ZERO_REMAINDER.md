# 03 — Exact Client & Server `.data` Binary Schemas (`DIFF = 0` Verified)

Every `.data` file in `pw142` was parsed to **exact EOF (`0` unread bytes)** against the real binary files.

| File | Size (Bytes) | Version / Magic | Parsed Records | Unread Remainder | Decompiled Loader |
| :--- | ---: | :--- | :--- | ---: | :--- |
| `elements.data` | `28,613,176` | `0x3000001b` (v27), `ts=0x4b39c931` | `131` sections, `37,676` records (`3,341` `talk_proc`) | **`0` B** | `elementclient` `0x6618f0.c`, `0x6639b0.c` |
| `tasks.data` | `48,139,955` | `0x93858361`, v`75` (`0x4b`) | `6,860` top-level, `17,787` recursive quest nodes | **`0` B** | `elementclient` `0x6892f0.c`, `0x687d60.c`, `0x683ce0.c` |
| `aipolicy.data` | `980,119` | hdr `1`, trigger v`7` | `1,371` AI policies + condition ASTs + ops | **`0` B** | `elementlocalize` `0x467920.c`, `0x466f00.c`, `0x466c10.c` |
| `gshop.data` | `830,892` | `ts=0x5ccc5f37` | `605` items (`0x554` B) + `8` category trees | **`0` B** | `elementclient` `0x675e10.c` |
| `gshopsev.data` | `89,548` | `ts=0x5ccc5f37` | `605` server items (`0x94` = `148` B) | **`0` B** | `elementclient` `0x675e10.c` |
| `domain.data` | `31,624` | `"MOXB"` (`0x42584f4d`) | `47` territories (polygons + meshes + graph) + `7` war slots | **`0` B** | `AFileImage` + `CDomainDataMan` |
| `task_npc.data` | `18,876` | `size=0x49bc`, `ts=0x4b39c937`, v`1` | `1,572` NPC spawn entries (`12` B each) | **`0` B** | `elementclient` `0x68a330.c`, `0x68a150.c` |
| `dyn_tasks.data` | `3,306` | `size=0x0cea`, `ts=0x4b1cb189`, v`10` | `6` dynamic `ATaskTempl` bitmask records | **`0` B** | `elementclient` `0x688c80.c`, `0x689dc0.c`, `0x686b70.c` |
| `gshop1.data` | `1,064` | `ts=0x5ccc5fd3` | `0` items + `8` CN category trees | **`0` B** | `elementclient` `0x675e10.c` |
| `gshopsev1.data` | `8` | `ts=0x5ccc5fd3` | `0` server items | **`0` B** | `elementclient` `0x675e10.c` |

## Key Non-Trivial Format Discoveries

1. **`elements.data` Control Blocks (`CTRL_1` & `CTRL_2`)**:
   - Standard tables (`[0..19]`, `[21..58]`, `[60..100]`, `[102..130]`, except `[58]` NPC War Tower Build Service) store `i32 element_size` + `u32 count` + `count * element_size` bytes; table `[58]` omits the `element_size` prefix and uses fixed `0x9c` (`156` B).
   - Section `[20]` (`CTRL_1`): `u32 tag = 0xab7689dd`, `u32 byte_len = 8`, `byte_len` bytes, plus `u32 extra_timestamp = 0x4b39c932` (`12 + len` B).
   - Section `[59]` (`TALK_PROC`): `u32 num_talks = 3,341`, each with `u32 id_talk`, `char name[0x80]`, `u32 num_win`, and per-window `(u32 id, u32 id_parent, u32 talk_text_len, u16 text[talk_text_len], u32 num_option, 0x88 * num_option)`.
   - Section `[101]` (`CTRL_2`): `u32 tag = 0xee35679f`, `u32 byte_len = 86`, `byte_len` bytes (`8 + len` B, **no** trailing `u32`).
2. **`tasks.data` Per-Quest `m_ID` UTF-16 XOR Encryption (`0x683ce0.c`, `0x687d60.c`)**:
   - Every `ATaskTempl` encrypts its `m_szName[30]`, optional `m_pszSignature[30]`, `m_pwstrDescript`, `m_pwstrOkText`, `m_pwstrNoText`, `m_pwstrTribute`, and all 5 `talk_proc` dialog trees (`m_DelvTaskTalk`, `m_UnqualifiedTalk`, `m_DelvItemTalk`, `m_ExeTalk`, `m_AwardTalk`) by XORing every 16-bit `wchar_t` code unit with `key = (uint16_t)(m_ID & 0xFFFF)`.
3. **`aipolicy.data` Recursive Condition AST & v7 Trigger Operations (`0x466c10.c`, `0x466f00.c`)**:
   - Condition trees encode `(u32 cond_type, u32 param_len, u8[param_len])` followed by recursive child tags (`1` = left subtree, `2` = right subtree, `3` = leaf end, `4` = binary node end).
   - Trigger v7 operation `17` (`O_SUMMON_MONSTER`) is `24` bytes (`6 * u32`), `15` (`O_SET_GLOBAL`) is `12` bytes, `14` (`O_ACTIVE_CONTROLLER`) is `8` bytes, and `2` (`O_TALK_TEXT`) is `u32 byte_len + u16[byte_len/2]`.
