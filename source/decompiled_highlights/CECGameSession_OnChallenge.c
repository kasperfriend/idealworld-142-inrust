// rea decompile_all
// name: FUN_005d8c60
// address: 0x5d8c60
// body: available
// range: 0x5d8c60-0x5d8fa6 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e1ad533d4cc0333c2136fe0894217de2d61feea098240326e78633f9e4ddcbf9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_005d8c60(LPCRITICAL_SECTION param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int in_ECX;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  char *local_44;
  undefined4 local_40;
  undefined4 *local_3c;
  char local_38;
  undefined **local_34;
  undefined4 local_30;
  undefined **local_2c;
  void *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined **local_1c;
  void *local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_008ba2d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00430620(DAT_009b3eec,0xff00ff00,u_NET___protocol_challenge_00973128);
  FUN_005cffe0(0,0,0);
  iVar4 = (int)param_1;
  FUN_007636f0(*(int *)((int)param_1 + 0x24),
               *(int *)((int)param_1 + 0x28) - *(int *)((int)param_1 + 0x24));
  local_4 = 0;
  iVar2 = FUN_00430870();
  if (*(int *)(iVar4 + 0x18) == iVar2) {
    iVar2 = _stricmp(*(char **)(DAT_009b3eec + 0x4fc),local_44);
    if (iVar2 == 0) {
      uVar5 = **(undefined4 **)(iVar4 + 0xc);
      *(undefined4 *)(in_ECX + 0x16c) = uVar5;
      local_28 = (void *)0x0;
      *(undefined4 *)(in_ECX + 0x15c) = *(undefined4 *)(*(int *)(iVar4 + 0xc) + 4);
      local_24 = 0;
      local_20 = 0;
      local_2c = &PTR_FUN_008d6c34;
      local_18 = (void *)0x0;
      local_14 = 0;
      local_10 = 0;
      local_1c = &PTR_FUN_008d6c34;
      local_34 = &PTR_FUN_008e4568;
      local_30 = 3;
      local_4 = CONCAT31(local_4._1_3_,2);
      FUN_005c02c0(&local_34,*(undefined4 *)(in_ECX + 0x134),*(undefined4 *)(in_ECX + 0x138),
                   iVar4 + 8,CONCAT31((int3)((uint)uVar5 >> 8),*(undefined1 *)(iVar4 + 0x1c)));
      pcVar3 = (char *)FUN_00763ef0();
      uVar7 = 0xffffffff;
      pcVar9 = pcVar3;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      for (uVar8 = ~uVar7 - 1 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        pcVar3[0] = '\0';
        pcVar3[1] = '\0';
        pcVar3[2] = '\0';
        pcVar3[3] = '\0';
        pcVar3 = pcVar3 + 4;
      }
      for (uVar7 = ~uVar7 - 1 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar3 = '\0';
        pcVar3 = pcVar3 + 1;
      }
      FUN_00763f40();
      FUN_005cfb00(&local_34,0);
      local_1c = &PTR_FUN_008d6c34;
      free(local_18);
      local_2c = &PTR_FUN_008d6c34;
      free(local_28);
      local_34 = &PTR_LAB_008d6c3c;
      goto LAB_005d8f81;
    }
  }
  FUN_00764590(1,s_local_ver___s_00973118,*(undefined4 *)(DAT_009b3eec + 0x4fc));
  FUN_00764590(1,s_svr_ver___s_0097310c,local_44);
  param_1 = (LPCRITICAL_SECTION)(DAT_009b3eec + 0x3c);
  if (*(int *)(*(int *)(DAT_009b3eec + 0x1c) + 4) == 0) {
    param_1 = (LPCRITICAL_SECTION)0x16;
    FUN_006496d0(&local_3c,&param_1);
    if (local_38 == '\0') {
      uVar5 = 0;
    }
    else {
      uVar5 = *(undefined4 *)*local_3c;
    }
    (*(code *)PTR_FUN_009b3bac)
              (*(undefined4 *)(DAT_009b3eec + 0x274),u_Element_client_009730ec,uVar5,0);
  }
  else {
    uVar7 = FUN_00430870();
    if (uVar7 < *(uint *)(iVar4 + 0x18)) {
LAB_005d8ea2:
      local_40 = 0x16;
      FUN_006496d0(&local_3c,&local_40);
      if (local_38 != '\0') {
        FUN_005ab020(*(undefined4 *)*local_3c,&DAT_009b3c44);
        goto LAB_005d8f23;
      }
    }
    else {
      iVar4 = _stricmp(*(char **)(DAT_009b3eec + 0x4fc),local_44);
      if (iVar4 != 0) goto LAB_005d8ea2;
      local_40 = 0x98;
      FUN_006496d0(&local_3c,&local_40);
      if (local_38 != '\0') {
        FUN_005ab020(*(undefined4 *)*local_3c,&DAT_009b3c44);
        goto LAB_005d8f23;
      }
    }
    FUN_005ab020(0,&DAT_009b3c44);
  }
LAB_005d8f23:
  *(undefined1 *)(in_ECX + 0x130) = 0;
  DAT_009bcf30 = 1;
  iVar4 = *(int *)(in_ECX + 0xac);
  uVar5 = *(undefined4 *)(iVar4 + 0x44);
  lpCriticalSection = (LPCRITICAL_SECTION)(iVar4 + 0x10);
  param_1 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  local_4 = CONCAT31(local_4._1_3_,1);
  piVar6 = (int *)FUN_005d8fb0(uVar5);
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 4))();
  }
  param_1 = (LPCRITICAL_SECTION)CONCAT31(param_1._1_3_,piVar6 != (int *)0x0);
  LeaveCriticalSection(lpCriticalSection);
  if ((char)param_1 == '\0') {
    *(undefined4 *)(iVar4 + 0x6c) = 4;
  }
  else {
    *(undefined4 *)(iVar4 + 0x6c) = 0;
  }
LAB_005d8f81:
  local_4 = 0xffffffff;
  FUN_007637f0();
  ExceptionList = local_c;
  return;
}

