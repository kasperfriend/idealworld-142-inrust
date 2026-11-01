// rea decompile_all
// name: FUN_100089b5
// address: 0x100089b5
// body: available
// range: 0x100089b5-0x10008a23 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e763201e522a4b123fb330eede09834c44ddf2bb90702e50eea219801be95539
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * FUN_100089b5(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined *this;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar3;
  uint *puVar4;
  
  FUN_1006d9d8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  extraout_ECX[1] = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)((int)extraout_ECX + 0x6a) = 1;
  extraout_ECX[0x1d] = 0;
  extraout_ECX[0x1e] = 0;
  extraout_ECX[0x1b] = 0;
  extraout_ECX[0x1c] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_LAB_100712a4;
  iVar2 = FUN_10001a81();
  if (iVar2 == 0) {
    uVar1 = extraout_ECX[1];
    *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
    *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    puVar4 = (uint *)(unaff_EBP + -0x18);
    puVar3 = (undefined4 *)(unaff_EBP + -0x28);
    this = FUN_10006a45();
    FUN_1000b361(this,puVar3,puVar4);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

