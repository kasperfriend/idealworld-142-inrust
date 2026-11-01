// rea decompile_all
// name: FUN_00466c10
// address: 0x466c10
// body: available
// range: 0x466c10-0x466d3a inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e1ad533d4cc0333c2136fe0894217de2d61feea098240326e78633f9e4ddcbf9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00466c10(FILE *param_1,void *param_2)

{
  void *_DstBuf;
  undefined4 in_EAX;
  void *_DstBuf_00;
  undefined4 *puVar1;
  int local_8 [2];
  
  _DstBuf = param_2;
  if (param_2 == (void *)0x0) {
    return CONCAT31((int3)((uint)in_EAX >> 8),1);
  }
  param_2 = (void *)0x0;
  local_8[0] = 0;
  fread(_DstBuf,4,1,param_1);
  fread(&param_2,4,1,param_1);
  if (param_2 == (void *)0x0) {
    *(undefined4 *)((int)_DstBuf + 4) = 0;
  }
  else {
    _DstBuf_00 = malloc((size_t)param_2);
    *(void **)((int)_DstBuf + 4) = _DstBuf_00;
    fread(_DstBuf_00,(size_t)param_2,1,param_1);
  }
  do {
    while( true ) {
      while( true ) {
        fread(local_8,4,1,param_1);
        if (local_8[0] == 3) {
          *(undefined4 *)((int)_DstBuf + 8) = 0;
          *(undefined4 *)((int)_DstBuf + 0xc) = 0;
          goto LAB_00466d2f;
        }
        if (local_8[0] != 1) break;
        puVar1 = operator_new(0x10);
        if (puVar1 == (undefined4 *)0x0) {
          *(undefined4 *)((int)_DstBuf + 8) = 0;
          FUN_00466c10(param_1,(void *)0x0);
        }
        else {
          *puVar1 = 0;
          puVar1[1] = 0;
          puVar1[2] = 0;
          puVar1[3] = 0;
          *(undefined4 **)((int)_DstBuf + 8) = puVar1;
          FUN_00466c10(param_1,puVar1);
        }
      }
      if (local_8[0] != 2) break;
      puVar1 = operator_new(0x10);
      if (puVar1 == (undefined4 *)0x0) {
        *(undefined4 *)((int)_DstBuf + 0xc) = 0;
        FUN_00466c10(param_1,(void *)0x0);
      }
      else {
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
        puVar1[3] = 0;
        *(undefined4 **)((int)_DstBuf + 0xc) = puVar1;
        FUN_00466c10(param_1,puVar1);
      }
    }
  } while (local_8[0] != 4);
LAB_00466d2f:
  return CONCAT31((int3)((uint)local_8[0] >> 8),1);
}

