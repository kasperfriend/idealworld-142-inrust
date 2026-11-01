// rea decompile_all
// name: FUN_00689dc0
// address: 0x689dc0
// body: available
// range: 0x689dc0-0x68a147 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e1ad533d4cc0333c2136fe0894217de2d61feea098240326e78633f9e4ddcbf9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_00689dc0(uint *param_1,uint *param_2,char param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  undefined4 *puVar6;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_008c267b;
  local_c = ExceptionList;
  if (param_2 < 0xc) {
    ExceptionList = &local_c;
    uVar1 = FUN_00430860(0,0,0,s_UnmarshalDynTasks__wrong_size_00978aec);
    ExceptionList = local_c;
    return uVar1 & 0xffffff00;
  }
  if ((short)param_1[2] == 10) {
    if ((uint *)*param_1 == param_2) {
      iVar5 = CONCAT31((int3)((uint)param_2 >> 8),param_3);
      ExceptionList = &local_c;
      *(uint *)(in_ECX + 0x2c8) = param_1[1];
      if ((param_3 == '\0') &&
         (_param_3 = 0, param_2 = param_1 + 3, *(short *)((int)param_1 + 10) != 0)) {
        do {
          puVar2 = (undefined4 *)thunk_FUN_007631a0(0x758);
          local_4 = 0;
          if (puVar2 == (undefined4 *)0x0) {
            puVar2 = (undefined4 *)0x0;
          }
          else {
            puVar3 = puVar2;
            for (iVar5 = 0xd8; puVar3 = puVar3 + 1, iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar3 = 0;
            }
            *(undefined1 *)puVar3 = 0;
            puVar3 = (undefined4 *)thunk_FUN_007631a0(0xbb);
            if (puVar3 == (undefined4 *)0x0) {
              puVar3 = (undefined4 *)0x0;
            }
            else {
              puVar6 = puVar3;
              for (iVar5 = 0x2e; iVar5 != 0; iVar5 = iVar5 + -1) {
                *puVar6 = 0;
                puVar6 = puVar6 + 1;
              }
              *(undefined2 *)puVar6 = 0;
              *(undefined1 *)((int)puVar6 + 2) = 0;
            }
            *(undefined4 **)((int)puVar2 + 0x33d) = puVar3;
            DAT_009bf3c8 = DAT_009bf3c8 + 1;
            puVar3 = (undefined4 *)thunk_FUN_007631a0(0xbb);
            if (puVar3 == (undefined4 *)0x0) {
              puVar3 = (undefined4 *)0x0;
            }
            else {
              puVar6 = puVar3;
              for (iVar5 = 0x2e; iVar5 != 0; iVar5 = iVar5 + -1) {
                *puVar6 = 0;
                puVar6 = puVar6 + 1;
              }
              *(undefined2 *)puVar6 = 0;
              *(undefined1 *)((int)puVar6 + 2) = 0;
            }
            *(undefined4 **)((int)puVar2 + 0x341) = puVar3;
            DAT_009bf3c8 = DAT_009bf3c8 + 1;
            puVar3 = (undefined4 *)thunk_FUN_007631a0(0x1c);
            if (puVar3 == (undefined4 *)0x0) {
              puVar3 = (undefined4 *)0x0;
            }
            else {
              puVar6 = puVar3;
              for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
                *puVar6 = 0;
                puVar6 = puVar6 + 1;
              }
            }
            *(undefined4 **)((int)puVar2 + 0x345) = puVar3;
            DAT_009bf3c8 = DAT_009bf3c8 + 1;
            puVar3 = (undefined4 *)thunk_FUN_007631a0(0x1c);
            if (puVar3 == (undefined4 *)0x0) {
              puVar3 = (undefined4 *)0x0;
            }
            else {
              puVar6 = puVar3;
              for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
                *puVar6 = 0;
                puVar6 = puVar6 + 1;
              }
            }
            *(undefined4 **)((int)puVar2 + 0x349) = puVar3;
            DAT_009bf3c8 = DAT_009bf3c8 + 1;
            puVar3 = (undefined4 *)thunk_FUN_007631a0(0x20);
            if (puVar3 == (undefined4 *)0x0) {
              puVar3 = (undefined4 *)0x0;
            }
            else {
              puVar6 = puVar3;
              for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
                *puVar6 = 0;
                puVar6 = puVar6 + 1;
              }
            }
            *(undefined4 **)((int)puVar2 + 0x34d) = puVar3;
            DAT_009bf3c8 = DAT_009bf3c8 + 1;
            puVar3 = (undefined4 *)thunk_FUN_007631a0(0x20);
            if (puVar3 == (undefined4 *)0x0) {
              puVar3 = (undefined4 *)0x0;
            }
            else {
              puVar6 = puVar3;
              for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
                *puVar6 = 0;
                puVar6 = puVar6 + 1;
              }
            }
            *(undefined4 **)((int)puVar2 + 0x351) = puVar3;
            DAT_009bf3c8 = DAT_009bf3c8 + 1;
            puVar2[0xda] = 0;
            puVar2[0xdb] = 0;
            puVar2[0xdc] = 0;
            puVar2[0xdd] = 0;
            puVar2[0x11f] = 0;
            puVar2[0x120] = 0;
            puVar2[0x121] = 0;
            puVar2[0x122] = 0;
            *(undefined1 *)(puVar2 + 0x123) = 1;
            puVar2[0x124] = 0;
            puVar2[0x125] = 0;
            *(undefined1 *)(puVar2 + 0x126) = 0;
            FUN_00663990();
            FUN_00663990();
            FUN_00663990();
            FUN_00663990();
            FUN_00663990();
            *puVar2 = &PTR_FUN_008e9254;
            *(undefined1 *)(puVar2 + 0xde) = 0;
            puVar3 = puVar2 + 0x127;
            for (iVar5 = 0x23; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar3 = 0;
              puVar3 = puVar3 + 1;
            }
            puVar3 = puVar2 + 0x14a;
            for (iVar5 = 0x23; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar3 = 0;
              puVar3 = puVar3 + 1;
            }
            puVar3 = puVar2 + 0x16d;
            for (iVar5 = 0x23; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar3 = 0;
              puVar3 = puVar3 + 1;
            }
            puVar3 = puVar2 + 400;
            for (iVar5 = 0x23; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar3 = 0;
              puVar3 = puVar3 + 1;
            }
            puVar3 = puVar2 + 0x1b3;
            for (iVar5 = 0x23; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar3 = 0;
              puVar3 = puVar3 + 1;
            }
          }
          DAT_009bf3c8 = DAT_009bf3c8 + 1;
          local_4 = 0xffffffff;
          iVar4 = FUN_00686b70(param_2);
          FUN_006897f0(puVar2);
          FUN_00430860(0,puVar2[1],2,s_LoadDynTask_00978a9c);
          iVar5 = _param_3 + 1;
          param_2 = (uint *)((int)param_2 + iVar4);
          _param_3 = iVar5;
        } while ((ushort)iVar5 < *(ushort *)((int)param_1 + 10));
      }
      ExceptionList = local_c;
      return CONCAT31((int3)((uint)iVar5 >> 8),1);
    }
    ExceptionList = &local_c;
    uVar1 = FUN_00430860(0,0,0,s_UnmarshalDynTasks__wrong_header_00978aa8);
    ExceptionList = local_c;
    return uVar1 & 0xffffff00;
  }
  ExceptionList = &local_c;
  uVar1 = FUN_00430860(0,0,0,s_UnmarshalDynTasks__wrong_version_00978ac8);
  ExceptionList = local_c;
  return uVar1 & 0xffffff00;
}

