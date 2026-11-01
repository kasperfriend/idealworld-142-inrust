// rea decompile_all
// name: FUN_0076da20
// address: 0x76da20
// body: available
// range: 0x76da20-0x76db0f inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e1ad533d4cc0333c2136fe0894217de2d61feea098240326e78633f9e4ddcbf9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0076da20(undefined4 param_1,uint param_2)

{
  char cVar1;
  int *in_ECX;
  int iStack_8;
  undefined1 auStack_4 [4];
  
  if ((char)in_ECX[0x86] != '\0') {
    (**(code **)(*in_ECX + 0xc))();
  }
  cVar1 = FUN_0076d810(param_1);
  if (cVar1 != '\0') {
    if ((param_2 & 1) == 0) {
      if (DAT_009d2c48 != 0) {
        FUN_007647d0(DAT_009d2c48,s_AFileImage__Open_Current_we_only_00986f70);
      }
    }
    else {
      in_ECX[0x84] = param_2 & 0xffffffe7;
      cVar1 = FUN_0076db40(&iStack_8,4,auStack_4);
      if (cVar1 != '\0') {
        if (iStack_8 == 0x42584f4d) {
          *(undefined1 *)(in_ECX + 0x86) = 1;
          in_ECX[0x84] = in_ECX[0x84] | 0x10;
          return 1;
        }
        if (iStack_8 == 0x54584f4d) {
          *(undefined1 *)(in_ECX + 0x86) = 1;
          in_ECX[0x84] = in_ECX[0x84] | 8;
          return 1;
        }
        in_ECX[0x84] = in_ECX[0x84] | 8;
        FUN_0076dca0(0,0);
        *(undefined1 *)(in_ECX + 0x86) = 1;
        return 1;
      }
    }
  }
  return 0;
}

