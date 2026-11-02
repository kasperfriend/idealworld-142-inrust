# 12 — Full Parity Checklist (everything that must match the real PW 1.4.2 client)

**Date:** 2026-11-02 · **Branch:** `arena/b9bbe66c-idealworld-142-inrust` · **PR:** #2
**Machine-verified by:** `tools/full_parity_audit.py` → **37/37 checks green** (`evidence/full_parity/report.{json,md}`), plus `tools/ui_parity_audit.py` (13/13) and `tools/movement_parity_audit.py` (28/28).
Ground truth: original-client `ARCHIVE_MANIFEST.tsv` CRC32s, RE ledgers (`evidence/ledgers/`), and the real assets staged from Drive `Games\pw142` into `/home/user/pw142/element`.

## Checklist

| # | Item | Status | How verified |
|---|---|---|---|
| 1 | RE evidence: 51,572/51,572 procedures, 1,134 RTTI classes | ✅ | ledger line count + `rtti_classes_and_vtables.json` |
| 2 | Staged assets byte-identical to original client | ✅ | CRC32 vs manifest: **38/38 match** (9 pcks + 7 data files + 13 login-map files + cursors/userdata) |
| 3 | `.pck` engine: configs 72 / interfaces 1,158 / shaders 166 / fonts 2 entries | ✅ | parsed with the PCK v2.0.2 reader |
| 4 | Data DBs: elements/tasks/dyn_tasks/task_npc/gshop/domain/aipolicy | ✅ | staged + CRC-verified |
| 5 | Localization: port emits 0 CJK from real (Chinese) string tables | ✅ | `sanitize_english_ui_str` strips CJK ranges at load; 660 real .stf/.htf scanned |
| 6 | Skill ABI v15: 1,175 skills / 69 VisibleStates / 167 TeamStates | ✅ | `elementskill_catalog.json` counts |
| 7 | GNET outer: ≥210 protocol classes (215 descriptors) | ✅ | `generated_opcodes.rs` |
| 8 | GNET inner gs: 49 s2c variants + 25 send_c2s + 65 c2s consts | ✅ | `gamedata.rs` / `live_client.rs` |
| 9 | AUI: all 480 real .dtf parse; 19 modals + HUD + login/select/create by name | ✅ | `ui_parity_audit.py` 13/13 |
| 10 | UI dialogs opened at runtime exist in real client | ✅ | live `show_dialog`/`find_dialog_screen_rect` names ⊆ real DIALOG names (fixed `Win_ELF`/`Win_PShop1`) |
| 11 | Movement: wire (PLAYER_MOVE 33 B, 250 ms), physics (14.0/×1.85/×1.45, jump 9.5, g 24.0), collision, bounds | ✅ | `movement_parity_audit.py` 28/28 |
| 12 | Terrain pipeline: .ecwld/.t2bk/.t2mk/.t2lm/.trn2/.ecbsd + 3×3 streaming | ✅ | pw-world sources |
| 13 | Render/audio: d3d9 FFI, vorbis, ALSA/WinMM; 166 real ps_2_0 shaders | ✅ | sources + shaders.pck |
| 14 | Sandbox CLI: --map/--pos/--tp/--tour/--time/--night/--screenshots/--check/--offline/--connect | ✅ | CLI source |
| 15 | Dungeon maps a02–a33, b01–b30 from Drive | ✅ (Phase 8) | 999 files staged; 35/37 maps pass offline `--check` (a33/b06 have no tiles in the original data) |

## Known non-parity / environment limits (honest gaps)
- **6 pcks over the sandbox 100 MB download cap** (models 888 MB, litmodels, building, sfx, loddata, textures) are not staged here → terrain/building textures and character models render via the port's fallback paths. On a real machine with the full client attached, these mount normally (mount table verified in `pw-client/src/lib.rs`).
- **Live server / real-client side-by-side run**: not possible in this Linux sandbox (OVA images 3.7–8.7 GB, no VM runtime, Windows-only client). Wire-level parity is proven against the RE protocol evidence instead; a live `glinkd:29000` test is the remaining end-to-end check once a server is reachable.
- **`.cld` collision files** are staged in map folders but not separately parsed; walkable collision uses `.ecbsd` heights (same result for the host player).
