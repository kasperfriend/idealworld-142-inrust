// rea decompile_all
// name: FUN_005f6440
// address: 0x5f6440
// body: available
// range: 0x5f6440-0x5f6547 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e1ad533d4cc0333c2136fe0894217de2d61feea098240326e78633f9e4ddcbf9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_005f6440(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *in_ECX;
  undefined1 *puVar5;
  bool bVar6;
  int iVar7;
  undefined4 local_28;
  int local_24 [2];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  uint local_14 [2];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_008bb868;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  in_ECX[1] = 0x48;
  *in_ECX = &PTR_LAB_008d6c54;
  local_28 = 0x48;
  FUN_005c9230();
  FUN_005c3960(local_24,&local_28);
  piVar3 = (int *)FUN_005c9230();
  if ((local_24[0] != *piVar3) && (*(int *)(local_24[0] + 0x14) != 0)) goto LAB_005f652b;
  local_14[0] = in_ECX[1];
  piVar3 = (int *)FUN_005c9230();
  bVar6 = true;
  iVar1 = *piVar3;
  iVar2 = iVar1;
  iVar7 = *(int *)(iVar1 + 4);
  while (iVar7 != 0) {
    bVar6 = local_14[0] < *(uint *)(iVar7 + 0x10);
    iVar2 = iVar7;
    if (bVar6) {
      iVar7 = *(int *)(iVar7 + 8);
    }
    else {
      iVar7 = *(int *)(iVar7 + 0xc);
    }
  }
  iVar4 = iVar2;
  if (bVar6) {
    if (iVar2 != *(int *)(iVar1 + 8)) {
      iVar4 = FUN_0088cb10(iVar2);
      goto LAB_005f650b;
    }
    puVar5 = local_1c;
    iVar7 = iVar2;
  }
  else {
LAB_005f650b:
    if (local_14[0] <= *(uint *)(iVar4 + 0x10)) goto LAB_005f652b;
    puVar5 = local_18;
  }
  FUN_005cac50(puVar5,iVar7,iVar2,local_14,0);
LAB_005f652b:
  *in_ECX = &PTR_FUN_008e42e4;
  ExceptionList = local_c;
  return;
}

