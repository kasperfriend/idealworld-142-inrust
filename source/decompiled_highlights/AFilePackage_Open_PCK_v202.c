// rea decompile_all
// name: FUN_0076fff0
// address: 0x76fff0
// body: available
// range: 0x76fff0-0x7708a7 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e1ad533d4cc0333c2136fe0894217de2d61feea098240326e78633f9e4ddcbf9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_0076fff0(char *param_1,char *param_2,char *param_3,char param_4,undefined1 param_5)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined1 *in_ECX;
  uint uVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  char *pcVar12;
  int local_138;
  uint local_134;
  uint local_130;
  undefined4 *local_12c;
  undefined4 *local_128;
  int local_124;
  uint local_120;
  int local_11c;
  int local_118;
  int local_114;
  char local_110 [260];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_008cc15c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0076edb0(local_110,param_1);
  pcVar12 = in_ECX + 0x2b0;
  in_ECX[2] = param_5;
  strncpy(pcVar12,param_2,0x104);
  _strlwr(pcVar12);
  FUN_00770e00(pcVar12);
  uVar8 = 0xffffffff;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar1 != '\0');
  uVar8 = ~uVar8;
  if (in_ECX[uVar8 + 0x2ae] != '\\') {
    in_ECX[uVar8 + 0x2af] = 0x5c;
    in_ECX[uVar8 + 0x2b0] = 0;
  }
  if (param_3 == (char *)0x0) {
    in_ECX[1] = 0;
    local_124 = thunk_FUN_007631a0(0x248);
    local_4 = 0;
    if (local_124 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_00771ce0();
    }
    local_4 = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x1a8) = uVar2;
    cVar1 = FUN_00771d20(local_110,&DAT_009872a8);
    if (cVar1 == '\0') {
      cVar1 = FUN_00771d20(local_110,&DAT_00950990);
      if (cVar1 == '\0') {
        iVar9 = *(int *)(in_ECX + 0x1a8);
        if (iVar9 != 0) {
          FUN_00430860();
          thunk_FUN_007631b0(iVar9);
        }
        *(undefined4 *)(in_ECX + 0x1a8) = 0;
        uVar8 = 0;
        if (DAT_009d2c48 == 0) goto LAB_0077088b;
        param_3 = local_110;
        pcVar12 = s_AFilePackage__Open____Can_not_op_00987278;
        goto LAB_00770882;
      }
      in_ECX[1] = 1;
    }
    strncpy(in_ECX + 0x1ac,param_1,0x104);
    FUN_00771a70();
    FUN_00772250(0,0,2);
    iVar9 = FUN_00772370();
    local_118 = iVar9;
    FUN_00772250(0,0,0);
    if (in_ECX[0x3d4] != '\0') {
      iVar9 = *(int *)(in_ECX + 0x3dc);
      local_118 = iVar9;
    }
    FUN_00772250(iVar9 + -4,0,0);
    FUN_00771f20(&local_114,4,1);
    if ((local_114 != 0x20002) && (local_114 != 0x20001)) {
      uVar8 = DAT_009d2c48;
      if (DAT_009d2c48 != 0) {
        uVar8 = FUN_007647d0(DAT_009d2c48,s_AFilePackage__Open____Incorrect_v_0098724c);
      }
      goto LAB_0077088b;
    }
    FUN_00772250(iVar9 + -8,0,0);
    FUN_00771f20(&local_138,4,1);
    FUN_00772250(iVar9 + -0x118,0,0);
    FUN_00771f20(in_ECX + 4,0x110,1);
    pcVar12 = strstr(in_ECX + 0x14,s_lica_File_Package_00987238);
    uVar8 = 0;
    if (pcVar12 == (char *)0x0) goto LAB_0077088b;
    strncpy(in_ECX + 0x14,s_Angelica_File_Package__Perfect_W_009872b0,0xfc);
    if (param_4 == '\0') {
      if (*(int *)(in_ECX + 0x10) < 0) goto LAB_00770493;
    }
    else if (-1 < *(int *)(in_ECX + 0x10)) {
LAB_00770493:
      uVar8 = DAT_009d2c48;
      if (DAT_009d2c48 != 0) {
        uVar8 = FUN_007647d0(DAT_009d2c48,s_AFilePackage__Open____wrong_encr_0098720c);
      }
      goto LAB_0077088b;
    }
    uVar8 = *(uint *)(in_ECX + 0xc) ^ DAT_00987124;
    *(uint *)(in_ECX + 0xc) = uVar8;
    if ((*(int *)(in_ECX + 4) == DAT_0098711c) && (*(int *)(in_ECX + 0x110) == DAT_00987120)) {
      FUN_00772250(uVar8,0,0);
      iVar9 = local_138;
      *(undefined4 *)(in_ECX + 300) = 100;
      if (local_138 == 0) {
        if (*(int *)(in_ECX + 0x120) != 0) {
          thunk_FUN_007631b0(*(int *)(in_ECX + 0x120));
          *(undefined4 *)(in_ECX + 0x120) = 0;
        }
        *(undefined4 *)(in_ECX + 0x128) = 0;
        *(undefined4 *)(in_ECX + 0x124) = 0;
      }
      else if (*(int *)(in_ECX + 0x128) < local_138) {
        iVar7 = thunk_FUN_007631a0(local_138 * 4);
        if (iVar7 == 0) {
          FUN_00764590(1,s_AArray__SetSize__Not_enough_memo_009505a4);
        }
        else {
          if (*(int *)(in_ECX + 0x120) != 0) {
            iVar10 = *(int *)(in_ECX + 0x124);
            if (iVar9 <= *(int *)(in_ECX + 0x124)) {
              iVar10 = iVar9;
            }
            iVar3 = 0;
            if (0 < iVar10) {
              do {
                iVar3 = iVar3 + 1;
                *(undefined4 *)(iVar7 + -4 + iVar3 * 4) =
                     *(undefined4 *)(*(int *)(in_ECX + 0x120) + -4 + iVar3 * 4);
              } while (iVar3 < iVar10);
            }
            thunk_FUN_007631b0(*(undefined4 *)(in_ECX + 0x120));
          }
          *(int *)(in_ECX + 0x124) = iVar9;
          *(int *)(in_ECX + 0x128) = iVar9;
          *(int *)(in_ECX + 0x120) = iVar7;
        }
      }
      else {
        *(int *)(in_ECX + 0x124) = local_138;
      }
      iVar9 = local_138;
      *(undefined4 *)(in_ECX + 0x144) = 100;
      if (local_138 == 0) {
        if (*(int *)(in_ECX + 0x138) != 0) {
          thunk_FUN_007631b0(*(int *)(in_ECX + 0x138));
          *(undefined4 *)(in_ECX + 0x138) = 0;
        }
        *(undefined4 *)(in_ECX + 0x140) = 0;
        *(undefined4 *)(in_ECX + 0x13c) = 0;
      }
      else if (*(int *)(in_ECX + 0x140) < local_138) {
        iVar7 = thunk_FUN_007631a0(local_138 * 4);
        if (iVar7 == 0) {
          FUN_00764590(1,s_AArray__SetSize__Not_enough_memo_009505a4);
        }
        else {
          if (*(int *)(in_ECX + 0x138) != 0) {
            iVar10 = *(int *)(in_ECX + 0x13c);
            if (iVar9 <= *(int *)(in_ECX + 0x13c)) {
              iVar10 = iVar9;
            }
            iVar3 = 0;
            if (0 < iVar10) {
              do {
                iVar3 = iVar3 + 1;
                *(undefined4 *)(iVar7 + -4 + iVar3 * 4) =
                     *(undefined4 *)(*(int *)(in_ECX + 0x138) + -4 + iVar3 * 4);
              } while (iVar3 < iVar10);
            }
            thunk_FUN_007631b0(*(undefined4 *)(in_ECX + 0x138));
          }
          *(int *)(in_ECX + 0x13c) = iVar9;
          *(int *)(in_ECX + 0x140) = iVar9;
          *(int *)(in_ECX + 0x138) = iVar7;
        }
      }
      else {
        *(int *)(in_ECX + 0x13c) = local_138;
      }
      local_11c = 0;
      if (0 < local_138) {
        do {
          iVar9 = local_11c;
          puVar4 = (undefined4 *)thunk_FUN_007631a0(0x114);
          local_12c = puVar4;
          if (puVar4 == (undefined4 *)0x0) {
LAB_00770808:
            uVar8 = 0;
            if (DAT_009d2c48 != 0) {
              uVar8 = FUN_007647d0(DAT_009d2c48,s_AFilePackage__Open____Not_enough_009871e0);
            }
            goto LAB_0077088b;
          }
          puVar4[0x44] = 0;
          puVar5 = (uint *)thunk_FUN_007631a0(8);
          if (puVar5 == (uint *)0x0) goto LAB_00770808;
          *puVar5 = 0;
          puVar5[1] = 0;
          FUN_00771f20(&local_134,4,1);
          local_134 = local_134 ^ DAT_00987124;
          FUN_00771f20(&local_120,4,1);
          local_120 = local_120 ^ s_1B7YAFilePackage__Open____GuardB_00987128._0_4_ ^ DAT_00987124;
          if (local_134 != local_120) {
            uVar8 = DAT_009d2c48;
            if (DAT_009d2c48 != 0) {
              uVar8 = FUN_007647d0(DAT_009d2c48,s_AFilePackage__Open____Check_Byte_009871b8);
            }
            goto LAB_0077088b;
          }
          *puVar5 = local_134;
          uVar8 = FUN_007631a0(local_134);
          puVar5[1] = uVar8;
          if (uVar8 == 0) {
            uVar8 = DAT_009d2c48;
            if (DAT_009d2c48 != 0) {
              uVar8 = FUN_007647d0(DAT_009d2c48,s_AFilePackage__Open____Not_enough_0098718c);
            }
            goto LAB_0077088b;
          }
          FUN_00771f20(uVar8,local_134,1);
          local_124 = 0x114;
          if (local_134 == 0x114) {
            puVar6 = (undefined4 *)puVar5[1];
            for (iVar9 = 0x45; iVar9 != 0; iVar9 = iVar9 + -1) {
              *puVar4 = *puVar6;
              puVar6 = puVar6 + 1;
              puVar4 = puVar4 + 1;
            }
            local_130 = local_134;
            local_128 = (undefined4 *)FUN_007631a0(0x114);
            iVar9 = FUN_00771a00(local_12c,0x114,local_128,&local_130);
            if ((iVar9 != 0) || (0x113 < local_130)) {
              local_130 = 0x114;
              puVar4 = local_12c;
              puVar6 = local_128;
              for (iVar9 = 0x45; iVar9 != 0; iVar9 = iVar9 + -1) {
                *puVar6 = *puVar4;
                puVar4 = puVar4 + 1;
                puVar6 = puVar6 + 1;
              }
            }
            *puVar5 = local_130;
            puVar6 = (undefined4 *)FUN_007631c0(puVar5[1],local_130);
            uVar8 = local_130 >> 2;
            puVar5[1] = (uint)puVar6;
            puVar4 = local_128;
            for (; uVar8 != 0; uVar8 = uVar8 - 1) {
              *puVar6 = *puVar4;
              puVar4 = puVar4 + 1;
              puVar6 = puVar6 + 1;
            }
            for (uVar8 = local_130 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
              *(undefined1 *)puVar6 = *(undefined1 *)puVar4;
              puVar4 = (undefined4 *)((int)puVar4 + 1);
              puVar6 = (undefined4 *)((int)puVar6 + 1);
            }
            FUN_007631b0(local_128);
            iVar9 = local_11c;
            puVar4 = local_12c;
          }
          else {
            iVar7 = FUN_00771a40(puVar5[1],local_134,puVar4,&local_124);
            if (iVar7 != 0) {
              uVar8 = DAT_009d2c48;
              if (DAT_009d2c48 != 0) {
                uVar8 = FUN_007647d0(DAT_009d2c48,s_AFilePackage__Open____decode_fil_0098715c);
              }
              goto LAB_0077088b;
            }
          }
          local_11c = iVar9 + 1;
          *(undefined4 **)(*(int *)(in_ECX + 0x120) + -4 + local_11c * 4) = puVar4;
          *(uint **)(*(int *)(in_ECX + 0x138) + -4 + local_11c * 4) = puVar5;
        } while (local_11c < local_138);
      }
      FUN_007714d0();
      if (in_ECX[0x3d4] != '\0') {
        *(int *)(in_ECX + 0xc) = local_118;
      }
LAB_007707e2:
      *in_ECX = 0;
      *(char **)(in_ECX + 0x114) = param_3;
      *(undefined4 *)(in_ECX + 0x3d0) = 0;
      *(undefined4 *)(in_ECX + 0x3cc) = 0;
      ExceptionList = local_c;
      return 1;
    }
    uVar8 = DAT_009d2c48;
    if (DAT_009d2c48 == 0) goto LAB_0077088b;
    pcVar12 = s_1B7YAFilePackage__Open____GuardB_00987128 + 4;
    param_3 = param_1;
  }
  else if (param_3 == (char *)0x1) {
    in_ECX[1] = 0;
    local_124 = thunk_FUN_007631a0(0x248);
    local_4 = 1;
    if (local_124 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_00771ce0();
    }
    local_4 = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x1a8) = uVar2;
    cVar1 = FUN_00771d20(local_110,&DAT_0094e544);
    if (cVar1 != '\0') {
      strncpy(in_ECX + 0x1ac,param_1,0x104);
      FUN_00771b00();
      piVar11 = (int *)(in_ECX + 4);
      for (iVar9 = 0x44; iVar7 = DAT_0098711c, iVar9 != 0; iVar9 = iVar9 + -1) {
        *piVar11 = 0;
        piVar11 = piVar11 + 1;
      }
      *(undefined4 *)(in_ECX + 0xc) = 0xc;
      *(int *)(in_ECX + 4) = iVar7;
      *(undefined4 *)(in_ECX + 8) = 0x20002;
      *(uint *)(in_ECX + 0x10) = -(uint)(param_4 != '\0') & 0x80000000;
      *(int *)(in_ECX + 0x110) = DAT_00987120;
      strncpy(in_ECX + 0x14,s_Angelica_File_Package__Perfect_W_009872b0,0xfc);
      if (*(int *)(in_ECX + 0x120) != 0) {
        thunk_FUN_007631b0(*(int *)(in_ECX + 0x120));
        *(undefined4 *)(in_ECX + 0x120) = 0;
      }
      *(undefined4 *)(in_ECX + 0x128) = 0;
      *(undefined4 *)(in_ECX + 0x124) = 0;
      if (*(int *)(in_ECX + 0x138) != 0) {
        thunk_FUN_007631b0(*(int *)(in_ECX + 0x138));
        *(undefined4 *)(in_ECX + 0x138) = 0;
      }
      *(undefined4 *)(in_ECX + 0x140) = 0;
      *(undefined4 *)(in_ECX + 0x13c) = 0;
      goto LAB_007707e2;
    }
    iVar9 = *(int *)(in_ECX + 0x1a8);
    if (iVar9 != 0) {
      FUN_00430860();
      thunk_FUN_007631b0(iVar9);
    }
    *(undefined4 *)(in_ECX + 0x1a8) = 0;
    uVar8 = 0;
    if (DAT_009d2c48 == 0) goto LAB_0077088b;
    param_3 = local_110;
    pcVar12 = s_AFilePackage__Open____Can_not_cr_00987300;
  }
  else {
    uVar8 = DAT_009d2c48;
    if (DAT_009d2c48 == 0) goto LAB_0077088b;
    pcVar12 = s_AFilePackage__Open____Unknown_op_00987330;
  }
LAB_00770882:
  uVar8 = FUN_007647d0(DAT_009d2c48,pcVar12,param_3);
LAB_0077088b:
  ExceptionList = local_c;
  return uVar8 & 0xffffff00;
}

