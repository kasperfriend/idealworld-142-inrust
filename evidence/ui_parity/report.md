# UI Parity Audit — real client interfaces.pck vs Rust pw-aui

- Dialogs parsed: **480** (controls total: 9538)
- String tables: 483 (0 strings), hint tables: 177
- Control kinds: {'WINDOWPICTURE': 2, 'IMAGEPICTURE': 3365, 'LABEL': 2791, 'EDIT': 526, 'STILLIMAGEBUTTON': 1919, 'TEXT': 89, 'LIST': 159, 'RADIO': 122, 'CHECK': 154, 'TREE': 12, 'SLIDER': 258, 'SCROLL': 12, 'MODELPICTURE': 1, 'MENUITEM': 57, 'PROGRESS': 56, 'COMBO': 14, 'CONSOLE': 1}
- Checks: **11/11 passed**

| Check | Result | Detail |
|---|---|---|
| pck:interfaces.pck present | ✅ | 1158 entries |
| count: 483 .stf | ✅ | got 483 |
| count: 177 .htf | ✅ | got 177 |
| count: 3 .dcf manifests | ✅ | got 3: ['interfaces/faces/chooseface.dcf', 'interfaces/ingame.dcf', 'interfaces/loginui.dcf'] |
| count: .dtf coverage (>=450 parseable, all .dcf refs resolve) | ✅ | 480 .dtf in pck, 375 referenced by .dcf manifests |
| every .dcf-referenced .dtf exists in interfaces.pck | ✅ | missing: [] |
| all .dtf parse with DIALOG header and no unknown keywords | ✅ | 0 bad: [] |
| every .dcf-loaded .dtf has companion .stf | ✅ | missing: [] |
| all .dtf referenced by .dcf (as loaded by pw-aui) exist in interfaces.pck | ✅ | 375 refs, missing: [] |
| all 19 modal + HUD + pre-world DIALOG names present | ✅ | missing: [] |
| userdata/Layout/*.ini parsed and mostly resolve to DIALOG names | ✅ | 703 override keys, unknown (also unknown to real client): ['Win_Inventory', 'Win_Inventory'] |
