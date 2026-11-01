// rea decompile_all
// name: FUN_10050977
// address: 0x10050977
// body: available
// range: 0x10050977-0x10050a07 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e763201e522a4b123fb330eede09834c44ddf2bb90702e50eea219801be95539
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __fastcall FUN_10050977(undefined4 *param_1)

{
  FUN_100089b5();
  *(undefined4 *)((int)param_1 + 0x36) = 0;
  param_1[0x10] = 0;
  *(undefined4 *)((int)param_1 + 0x3a) = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  *(undefined1 *)((int)param_1 + 0x53) = 0;
  *(undefined4 *)((int)param_1 + 0x31) = 0;
  *(undefined1 *)((int)param_1 + 0x1d) = 0;
  *(undefined1 *)((int)param_1 + 0x52) = 0;
  *(undefined1 *)(param_1 + 0x15) = 0;
  param_1[0x13] = 0;
  *(undefined1 *)((int)param_1 + 0x35) = 0;
  *(undefined1 *)((int)param_1 + 0x3f) = 0;
  *(undefined4 *)((int)param_1 + 0x5a) = 0;
  *(undefined4 *)((int)param_1 + 0x5e) = 0;
  *param_1 = &PTR_GetRequiredGenius_1007a440;
  param_1[2] = 0x7f;
  param_1[3] = &DAT_100a6f70;
  param_1[4] = &DAT_100a6f5c;
  param_1[5] = &DAT_100aed30;
  param_1[6] = 5;
  *(undefined1 *)(param_1 + 7) = 3;
  *(undefined2 *)((int)param_1 + 0x1e) = 1;
  param_1[0x11] = 1;
  *(undefined1 *)(param_1 + 0x12) = 1;
  *(undefined1 *)((int)param_1 + 0x49) = 1;
  *(undefined1 *)((int)param_1 + 0x4a) = 1;
  *(undefined **)((int)param_1 + 0x62) = &DAT_100a6f44;
  *(undefined1 *)((int)param_1 + 0x6a) = 2;
  *(undefined1 *)((int)param_1 + 0x3e) = 1;
  return param_1;
}

