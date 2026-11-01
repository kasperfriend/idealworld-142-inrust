// rea decompile_all
// name: FUN_006892f0
// address: 0x6892f0
// body: available
// range: 0x6892f0-0x689756 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e1ad533d4cc0333c2136fe0894217de2d61feea098240326e78633f9e4ddcbf9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_006892f0(char *param_1)

{
  char cVar1;
  FILE *_File;
  undefined4 uVar2;
  long *_DstBuf;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined4 *puVar6;
  long *local_430;
  uint local_42c;
  uint local_424;
  int local_420;
  size_t local_41c;
  long *local_418;
  FILE *local_414;
  undefined4 *local_410;
  char local_40c [1024];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_008c2660;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00430860(0,0,2,s_LoadPack_begin_00978a38);
  _File = fopen(param_1,&DAT_00950990);
  if (((_File == (FILE *)0x0) ||
      (local_414 = _File, fread(&local_424,0xc,1,_File), local_424 != 0x93858361)) ||
     (local_420 != DAT_00978974)) {
    uVar2 = 0;
  }
  else if (local_41c == 0) {
    uVar2 = 1;
  }
  else {
    _DstBuf = (long *)thunk_FUN_007631a0(local_41c << 2);
    DAT_009bf3c8 = DAT_009bf3c8 + 1;
    local_418 = _DstBuf;
    fread(_DstBuf,4,local_41c,_File);
    local_42c = 0;
    local_430 = _DstBuf;
    if (local_41c != 0) {
      do {
        iVar3 = fseek(_File,*local_430,0);
        if (iVar3 == 0) {
          puVar4 = (undefined4 *)thunk_FUN_007631a0(0x758);
          local_4 = 0;
          local_410 = puVar4;
          if (puVar4 == (undefined4 *)0x0) {
            puVar4 = (undefined4 *)0x0;
          }
          else {
            puVar5 = puVar4;
            for (iVar3 = 0xd8; puVar5 = puVar5 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar5 = 0;
            }
            *(undefined1 *)puVar5 = 0;
            puVar5 = (undefined4 *)thunk_FUN_007631a0(0xbb);
            if (puVar5 == (undefined4 *)0x0) {
              puVar5 = (undefined4 *)0x0;
            }
            else {
              puVar6 = puVar5;
              for (iVar3 = 0x2e; iVar3 != 0; iVar3 = iVar3 + -1) {
                *puVar6 = 0;
                puVar6 = puVar6 + 1;
              }
              *(undefined2 *)puVar6 = 0;
              *(undefined1 *)((int)puVar6 + 2) = 0;
            }
            *(undefined4 **)((int)puVar4 + 0x33d) = puVar5;
            DAT_009bf3c8 = DAT_009bf3c8 + 1;
            puVar5 = (undefined4 *)thunk_FUN_007631a0(0xbb);
            if (puVar5 == (undefined4 *)0x0) {
              puVar5 = (undefined4 *)0x0;
            }
            else {
              puVar6 = puVar5;
              for (iVar3 = 0x2e; iVar3 != 0; iVar3 = iVar3 + -1) {
                *puVar6 = 0;
                puVar6 = puVar6 + 1;
              }
              *(undefined2 *)puVar6 = 0;
              *(undefined1 *)((int)puVar6 + 2) = 0;
            }
            *(undefined4 **)((int)puVar4 + 0x341) = puVar5;
            DAT_009bf3c8 = DAT_009bf3c8 + 1;
            puVar5 = (undefined4 *)thunk_FUN_007631a0(0x1c);
            if (puVar5 == (undefined4 *)0x0) {
              puVar5 = (undefined4 *)0x0;
            }
            else {
              puVar6 = puVar5;
              for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
                *puVar6 = 0;
                puVar6 = puVar6 + 1;
              }
            }
            *(undefined4 **)((int)puVar4 + 0x345) = puVar5;
            DAT_009bf3c8 = DAT_009bf3c8 + 1;
            puVar5 = (undefined4 *)thunk_FUN_007631a0(0x1c);
            if (puVar5 == (undefined4 *)0x0) {
              puVar5 = (undefined4 *)0x0;
            }
            else {
              puVar6 = puVar5;
              for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
                *puVar6 = 0;
                puVar6 = puVar6 + 1;
              }
            }
            *(undefined4 **)((int)puVar4 + 0x349) = puVar5;
            DAT_009bf3c8 = DAT_009bf3c8 + 1;
            puVar5 = (undefined4 *)thunk_FUN_007631a0(0x20);
            if (puVar5 == (undefined4 *)0x0) {
              puVar5 = (undefined4 *)0x0;
            }
            else {
              puVar6 = puVar5;
              for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
                *puVar6 = 0;
                puVar6 = puVar6 + 1;
              }
            }
            *(undefined4 **)((int)puVar4 + 0x34d) = puVar5;
            DAT_009bf3c8 = DAT_009bf3c8 + 1;
            puVar5 = (undefined4 *)thunk_FUN_007631a0(0x20);
            if (puVar5 == (undefined4 *)0x0) {
              puVar5 = (undefined4 *)0x0;
            }
            else {
              puVar6 = puVar5;
              for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
                *puVar6 = 0;
                puVar6 = puVar6 + 1;
              }
            }
            *(undefined4 **)((int)puVar4 + 0x351) = puVar5;
            DAT_009bf3c8 = DAT_009bf3c8 + 1;
            local_4._0_1_ = 1;
            puVar4[0xda] = 0;
            puVar4[0xdb] = 0;
            puVar4[0xdc] = 0;
            puVar4[0xdd] = 0;
            puVar4[0x11f] = 0;
            puVar4[0x120] = 0;
            puVar4[0x121] = 0;
            puVar4[0x122] = 0;
            *(undefined1 *)(puVar4 + 0x123) = 1;
            puVar4[0x124] = 0;
            puVar4[0x125] = 0;
            *(undefined1 *)(puVar4 + 0x126) = 0;
            FUN_00663990();
            local_4._0_1_ = 2;
            FUN_00663990();
            local_4._0_1_ = 3;
            FUN_00663990();
            local_4._0_1_ = 4;
            FUN_00663990();
            local_4 = CONCAT31(local_4._1_3_,5);
            FUN_00663990();
            *puVar4 = &PTR_FUN_008e9254;
            *(undefined1 *)(puVar4 + 0xde) = 0;
            puVar5 = puVar4 + 0x127;
            for (iVar3 = 0x23; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar5 = 0;
              puVar5 = puVar5 + 1;
            }
            puVar5 = puVar4 + 0x14a;
            for (iVar3 = 0x23; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar5 = 0;
              puVar5 = puVar5 + 1;
            }
            puVar5 = puVar4 + 0x16d;
            for (iVar3 = 0x23; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar5 = 0;
              puVar5 = puVar5 + 1;
            }
            puVar5 = puVar4 + 400;
            for (iVar3 = 0x23; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar5 = 0;
              puVar5 = puVar5 + 1;
            }
            puVar5 = puVar4 + 0x1b3;
            for (iVar3 = 0x23; _DstBuf = local_418, _File = local_414, iVar3 != 0;
                iVar3 = iVar3 + -1) {
              *puVar5 = 0;
              puVar5 = puVar5 + 1;
            }
          }
          DAT_009bf3c8 = DAT_009bf3c8 + 1;
          local_4 = 0xffffffff;
          cVar1 = FUN_00686980(_File);
          if (cVar1 == '\0') {
            FUN_00430860(0,puVar4[1],0,s_Cant_Load_Task_00978a28);
            if (puVar4 != (undefined4 *)0x0) {
              (**(code **)*puVar4)(1);
              DAT_009bf3cc = DAT_009bf3cc + 1;
            }
          }
          else {
            FUN_006897f0(puVar4);
            FUN_00430860(0,puVar4[1],2,s_LoadTask_00978a1c);
          }
        }
        local_42c = local_42c + 1;
        local_430 = local_430 + 1;
      } while (local_42c < local_41c);
    }
    sprintf(local_40c,s_LoadTask__Count____d_00978a04,*(undefined4 *)(in_ECX + 4));
    FUN_00430860(0,0,2,local_40c);
    if (_DstBuf != (long *)0x0) {
      thunk_FUN_007631b0(_DstBuf);
      DAT_009bf3cc = DAT_009bf3cc + 1;
    }
    fclose(_File);
    FUN_00419510();
    FUN_004194b0(s_Configs_task_err_txt_009789ec,1);
    uVar2 = 1;
  }
  ExceptionList = local_c;
  return uVar2;
}

