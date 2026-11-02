# 11 — Full UI Parity Plan (headless, real-client-asset ground truth)

**Date:** 2026-11-02 · **Branch:** `arena/b9bbe66c-idealworld-142-inrust` · **PR:** #2

## Why headless
The literal ask (boot the `.ova` VM server + run the real Windows client side-by-side) is not
possible inside this Linux sandbox:
- The `.ova` VM images on Drive are 3.7–8.7 GB; the Drive download tool caps at ~100 MB/file.
- No VirtualBox/QEMU runtime here, and sandbox egress only allows github/npm/pypi/Drive.
- The real client is a Windows PE32 binary needing Direct3D9; it cannot execute on Linux.

So "full UI parity" is verified **against the real client's own UI definition assets** staged from
`Games\pw142\element` on Google Drive — `interfaces.pck` (459 `.dtf` dialogs, 483 `.stf` string
tables, 177 `.htf` hint tables, `Layout/*.ini`), `configs.pck`, `fonts.pck` — which are the exact
files the real client loads. If our `pw-aui` engine loads, instantiates and renders every one of
them identically (same controls, positions, visibility, strings), the UI is 1:1 with the real
client by construction.

## Phases

1. **Stage UI assets** from Drive `element` (`1_T0KQIqTrJVfHe4ubAbhoBaG0TW8cdc-`) into
   `/home/user/pw142/element/`: `interfaces.pck`, `configs.pck`, `fonts.pck`, `shaders.pck`,
   `surfaces.pck`, `gfx.pck`, `trees.pck`, `grasses.pck`, `facedata.pck`, `data/*.data`,
   `cursors/`, `userdata/`, `maps/login`, `maps/world`, `maps/a01`.
   Over-cap pcks (models 888 MB, litmodels, building, sfx, loddata, textures) stay fallback —
   they affect 3D content, not UI layout.
2. **Boot & smoke**: `pw-elementclient --check --offline` must report 459 DTFs / 483 STF /
   177 HTF / 166 shaders / 2 fonts.
3. **Full UI screenshot sweep**: extend the CLI with `--ui-shots DIR` rendering all 3 pre-world
   screens (login, character select, character create) + all 19 `InWorldModal`s at 1280×800,
   alongside the existing 20-scene `--screenshots` suite.
4. **Automated parity audit** (`--ui-audit` → JSON report): parse every `.dtf`/`.stf`/`.htf`/
   `Layout/*.ini` via `pw-aui`; assert (a) all parse with zero errors, (b) expected counts,
   (c) every modal's `.dtf` exists and its named controls are instantiated in `game_app`,
   (d) every `.stf` string referenced by a dialog resolves, (e) clock-icon/rich-text/slider/
   treeview/combobox control types all exercised.
5. **Fix & re-verify**: fix every discrepancy found in `pw-aui`/`pw-client`, re-run audit +
   screenshots until the report is clean, then commit, push, and post evidence on PR #2.
