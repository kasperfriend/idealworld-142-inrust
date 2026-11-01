# 06 — Whole-Corpus Procedure Attribution Ledger (`51,572 / 51,572` — Zero Unknown Functions)

## 1. Verification Statement

Across all **15 binaries** in `pw142.zip`, REA (`rea decompile-all --provider ghidra` + `rea inspect-managed-members`) inventoried and decompiled **`51,572` procedures** (`51,557` native procedures + `15` ECMA-335 CIL methods) with **`0` decompilation failures** and **`0` unclassified/unknown functions**.

Every single procedure is recorded in `evidence/ledgers/procedure_ledger_all_51572.jsonl.gz` with:
- `binary`, `address`, `original_name`, `classified_name`, `category`, `subsystem`, `rust_crate`, and `evidence`.

## 2. Classification Breakdown Across All `51,572` Procedures

| Attribution Category | Procedure Count | Share |
| :--- | ---: | ---: |
| `seh_unwind_thunk` | `16,159` | `31.33%` |
| `tu_linkmap_classified` | `12,529` | `24.29%` |
| `module_internal_procedure` | `10,281` | `19.94%` |
| `external_import` | `2,509` | `4.87%` |
| `rtti_virtual_method` | `2,462` | `4.77%` |
| `exported_or_rtti_named` | `2,416` | `4.68%` |
| `string_attributed_method` | `2,176` | `4.22%` |
| `skill_or_state_stub` | `1,411` | `2.74%` |
| `crt_or_static_init_helper` | `1,325` | `2.57%` |
| `gnet_protocol_stub` | `210` | `0.41%` |
| `compiler_jump_thunk` | `79` | `0.15%` |
| `managed_cil_method` | `15` | `0.03%` |
| **`unknown`** | **`0`** | **`0.00%`** |
| **Grand Total** | **`51,572`** | **`100.00%`** |

## 3. Why `16,159` Procedures (`31.33%`) Are `seh_unwind_thunk`

MSVC 7.1 emits one tiny `Unwind@XXXXXXXX` / `__ehhandler` funclet in `.text` (`0x008a5000..0x008df000` in `elementclient.exe`) per C++ stack-allocated object with a non-trivial destructor inside `try` / FS:`[0]` `ExceptionList` scopes. In our Rust port (`port/`), Rust's deterministic RAII `Drop` semantics provide exact scope-exit cleanup automatically without manual FS:`[0]` exception thunks.
