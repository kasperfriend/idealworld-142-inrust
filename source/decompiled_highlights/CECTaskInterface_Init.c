// rea decompile_all
// name: FUN_0067ccd0
// address: 0x67ccd0
// body: available
// range: 0x67ccd0-0x67cf06 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e1ad533d4cc0333c2136fe0894217de2d61feea098240326e78633f9e4ddcbf9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4
FUN_0067ccd0(undefined4 *param_1,uint param_2,undefined4 *param_3,uint param_4,undefined4 *param_5,
            uint param_6,undefined4 *param_7,uint param_8)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_007631a0(0xc88);
  *(int *)(in_ECX + 8) = iVar1;
  if (iVar1 == 0) {
    FUN_0043c590(2,s_CECTaskInterface__Init_009786a4,0x5d);
    return 0;
  }
  iVar1 = FUN_007631a0(0x1000);
  *(int *)(in_ECX + 0xc) = iVar1;
  if (iVar1 == 0) {
    FUN_007631b0(*(undefined4 *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 0xc) = 0;
    FUN_0043c590(2,s_CECTaskInterface__Init_009786a4,0x65);
    return 0;
  }
  iVar1 = FUN_007631a0(0x2800);
  *(int *)(in_ECX + 0x10) = iVar1;
  if (iVar1 == 0) {
    FUN_007631b0(*(undefined4 *)(in_ECX + 8));
    FUN_007631b0(*(undefined4 *)(in_ECX + 0xc));
    FUN_0043c590(2,s_CECTaskInterface__Init_009786a4,0x6d);
    return 0;
  }
  iVar1 = FUN_007631a0(0x2800);
  *(int *)(in_ECX + 0x14) = iVar1;
  if (iVar1 == 0) {
    FUN_007631b0(*(undefined4 *)(in_ECX + 8));
    FUN_007631b0(*(undefined4 *)(in_ECX + 0xc));
    FUN_007631b0(*(undefined4 *)(in_ECX + 0x14));
    FUN_0043c590(2,s_CECTaskInterface__Init_009786a4,0x76);
    return 0;
  }
  puVar3 = *(undefined4 **)(in_ECX + 8);
  for (uVar2 = param_2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = *param_1;
    param_1 = param_1 + 1;
    puVar3 = puVar3 + 1;
  }
  for (uVar2 = param_2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar3 = *(undefined1 *)param_1;
    param_1 = (undefined4 *)((int)param_1 + 1);
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  puVar3 = *(undefined4 **)(in_ECX + 0xc);
  for (uVar2 = param_4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = *param_3;
    param_3 = param_3 + 1;
    puVar3 = puVar3 + 1;
  }
  for (uVar2 = param_4 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar3 = *(undefined1 *)param_3;
    param_3 = (undefined4 *)((int)param_3 + 1);
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  puVar3 = *(undefined4 **)(in_ECX + 0x10);
  for (uVar2 = param_6 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = *param_5;
    param_5 = param_5 + 1;
    puVar3 = puVar3 + 1;
  }
  for (uVar2 = param_6 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar3 = *(undefined1 *)param_5;
    param_5 = (undefined4 *)((int)param_5 + 1);
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  puVar3 = *(undefined4 **)(in_ECX + 0x14);
  for (uVar2 = param_8 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = *param_7;
    param_7 = param_7 + 1;
    puVar3 = puVar3 + 1;
  }
  for (uVar2 = param_8 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar3 = *(undefined1 *)param_7;
    param_7 = (undefined4 *)((int)param_7 + 1);
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  if ((int)param_2 < 0xc88) {
    puVar3 = (undefined4 *)(param_2 + *(int *)(in_ECX + 8));
    for (uVar2 = 0xc88 - param_2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    for (uVar2 = 0xc88 - param_2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar3 = 0;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
  }
  if ((int)param_4 < 0x1000) {
    puVar3 = (undefined4 *)(param_4 + *(int *)(in_ECX + 0xc));
    for (uVar2 = 0x1000 - param_4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    for (uVar2 = 0x1000 - param_4 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar3 = 0;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
  }
  if ((int)param_6 < 0x2800) {
    puVar3 = (undefined4 *)(param_6 + *(int *)(in_ECX + 0x10));
    for (uVar2 = 0x2800 - param_6 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    for (uVar2 = 0x2800 - param_6 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar3 = 0;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
  }
  if ((int)param_8 < 0x2800) {
    puVar3 = (undefined4 *)(param_8 + *(int *)(in_ECX + 0x14));
    for (uVar2 = 0x2800 - param_8 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    for (uVar2 = 0x2800 - param_8 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar3 = 0;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
  }
  FUN_0067cc50();
  FUN_00689080();
  FUN_006892f0(s_data_tasks_data_00951c78,1);
  FUN_0068a330(s_data_task_npc_data_00978690);
  FUN_00688c80(s_userdata_dyn_tasks_data_00978678);
  FUN_00680fa0();
  return 1;
}

