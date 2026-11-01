// rea decompile_all
// name: FUN_00770990
// address: 0x770990
// body: available
// range: 0x770990-0x770ddf inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e1ad533d4cc0333c2136fe0894217de2d61feea098240326e78633f9e4ddcbf9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00770990(void)

{
  char *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  char *in_ECX;
  char *pcVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  uint uVar11;
  int local_20;
  undefined4 local_1c;
  char *local_18;
  int *local_14;
  undefined4 *local_10;
  char *local_c;
  undefined4 *local_8;
  undefined4 *local_4;
  
  if (*(int *)(in_ECX + 0x114) == 0) {
    if (*in_ECX != '\0') {
      iVar10 = *(int *)(in_ECX + 0xc);
      local_20 = 0;
      uVar4 = FUN_00771ba0(&local_20);
      if ((char)uVar4 == '\0') {
        return uVar4;
      }
      iVar10 = iVar10 + local_20;
      *(uint *)(in_ECX + 0xc) = *(uint *)(in_ECX + 0xc) ^ DAT_00987124;
      FUN_00772030(in_ECX + 4,0x110,1);
      local_1c = *(undefined4 *)(in_ECX + 0x124);
      *(uint *)(in_ECX + 0xc) = *(uint *)(in_ECX + 0xc) ^ DAT_00987124;
      FUN_00772030(&local_1c,4,1);
      FUN_00772030(in_ECX + 8,4,1);
      FUN_00772380(iVar10 + 0x118);
      FUN_00771b30();
      *in_ECX = '\0';
    }
  }
  else if (*(int *)(in_ECX + 0x114) == 1) {
    local_20 = *(int *)(in_ECX + 0x124);
    uVar4 = FUN_00771ba0(0);
    if ((char)uVar4 == '\0') {
      return uVar4;
    }
    *(uint *)(in_ECX + 0xc) = *(uint *)(in_ECX + 0xc) ^ DAT_00987124;
    FUN_00772030(in_ECX + 4,0x110,1);
    *(uint *)(in_ECX + 0xc) = *(uint *)(in_ECX + 0xc) ^ DAT_00987124;
    FUN_00772030(&local_20,4,1);
    FUN_00772030(in_ECX + 8,4,1);
    FUN_00771b30();
  }
  if (*(int *)(in_ECX + 0x1a8) != 0) {
    FUN_00771eb0();
    iVar10 = *(int *)(in_ECX + 0x1a8);
    if (iVar10 != 0) {
      FUN_00430860();
      thunk_FUN_007631b0(iVar10);
    }
    in_ECX[0x1a8] = '\0';
    in_ECX[0x1a9] = '\0';
    in_ECX[0x1aa] = '\0';
    in_ECX[0x1ab] = '\0';
  }
  iVar10 = 0;
  local_20 = 0;
  if (0 < *(int *)(in_ECX + 0x124)) {
    do {
      thunk_FUN_007631b0(*(undefined4 *)(*(int *)(in_ECX + 0x120) + iVar10 * 4));
      iVar10 = iVar10 + 1;
    } while (iVar10 < *(int *)(in_ECX + 0x124));
  }
  iVar10 = 0;
  if (0 < *(int *)(in_ECX + 0x13c)) {
    do {
      iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 0x138) + iVar10 * 4) + 4);
      if (iVar2 != 0) {
        FUN_007631b0(iVar2);
        *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x138) + iVar10 * 4) + 4) = 0;
      }
      thunk_FUN_007631b0(*(undefined4 *)(*(int *)(in_ECX + 0x138) + iVar10 * 4));
      iVar10 = iVar10 + 1;
    } while (iVar10 < *(int *)(in_ECX + 0x13c));
  }
  if (*(int *)(in_ECX + 0x120) != 0) {
    thunk_FUN_007631b0(*(int *)(in_ECX + 0x120));
    in_ECX[0x120] = '\0';
    in_ECX[0x121] = '\0';
    in_ECX[0x122] = '\0';
    in_ECX[0x123] = '\0';
  }
  in_ECX[0x128] = '\0';
  in_ECX[0x129] = '\0';
  in_ECX[0x12a] = '\0';
  in_ECX[299] = '\0';
  in_ECX[0x124] = '\0';
  in_ECX[0x125] = '\0';
  in_ECX[0x126] = '\0';
  in_ECX[0x127] = '\0';
  if (*(int *)(in_ECX + 0x138) != 0) {
    thunk_FUN_007631b0(*(int *)(in_ECX + 0x138));
    in_ECX[0x138] = '\0';
    in_ECX[0x139] = '\0';
    in_ECX[0x13a] = '\0';
    in_ECX[0x13b] = '\0';
  }
  in_ECX[0x140] = '\0';
  in_ECX[0x141] = '\0';
  in_ECX[0x142] = '\0';
  in_ECX[0x143] = '\0';
  in_ECX[0x13c] = '\0';
  in_ECX[0x13d] = '\0';
  in_ECX[0x13e] = '\0';
  in_ECX[0x13f] = '\0';
  pcVar1 = in_ECX + 0x160;
  FUN_0077bef0(pcVar1);
LAB_00770bec:
  if (((local_c == (char *)0x0) || (pcVar1 == (char *)0x0)) || (local_c == pcVar1)) {
    if (local_8 == (undefined4 *)0x0) {
      if (local_4 != (undefined4 *)0x0) goto LAB_00770c00;
      uVar8 = 0;
      if (*(int *)(in_ECX + 0x174) != 0) {
        do {
          puVar6 = *(undefined4 **)(*(int *)(in_ECX + 0x168) + uVar8 * 4);
          while (puVar6 != (undefined4 *)0x0) {
            puVar3 = (undefined4 *)*puVar6;
            thunk_FUN_007631b0(puVar6);
            puVar6 = puVar3;
          }
          uVar8 = uVar8 + 1;
          *(undefined4 *)(*(int *)(in_ECX + 0x168) + -4 + uVar8 * 4) = 0;
        } while (uVar8 < *(uint *)(in_ECX + 0x174));
      }
      in_ECX[0x164] = '\0';
      in_ECX[0x165] = '\0';
      in_ECX[0x166] = '\0';
      in_ECX[0x167] = '\0';
      if ((local_20 != 0) && (DAT_009d2c48 != 0)) {
        FUN_007647d0(DAT_009d2c48,s_AFilePackage__Close_____d_file_i_009873e0,local_20);
      }
      pcVar1 = in_ECX + 0x148;
      puVar6 = (undefined4 *)0x0;
      local_10 = (undefined4 *)0x0;
      local_14 = *(int **)(in_ECX + 0x150);
      pcVar7 = pcVar1;
      local_18 = pcVar1;
      if (local_14 == (int *)(*(int *)(in_ECX + 0x150) + *(int *)(in_ECX + 0x15c) * 4))
      goto LAB_00770d1d;
      local_10 = (undefined4 *)*local_14;
      puVar6 = local_10;
      piVar5 = local_14;
      if (local_10 == (undefined4 *)0x0) {
        FUN_00793ff0();
        puVar6 = local_10;
        piVar5 = local_14;
        pcVar7 = local_18;
      }
LAB_00770d23:
      do {
        if (((pcVar7 == (char *)0x0) || (pcVar1 == (char *)0x0)) || (pcVar7 == pcVar1)) {
          if (piVar5 == (int *)0x0) {
            if (puVar6 == (undefined4 *)0x0) {
              uVar11 = 0;
              uVar8 = 0;
              if (*(int *)(in_ECX + 0x15c) != 0) {
                do {
                  puVar6 = *(undefined4 **)(*(int *)(in_ECX + 0x150) + uVar11 * 4);
                  while (puVar6 != (undefined4 *)0x0) {
                    puVar3 = (undefined4 *)*puVar6;
                    thunk_FUN_007631b0(puVar6);
                    puVar6 = puVar3;
                  }
                  uVar11 = uVar11 + 1;
                  *(undefined4 *)(*(int *)(in_ECX + 0x150) + -4 + uVar11 * 4) = 0;
                  uVar8 = *(uint *)(in_ECX + 0x15c);
                } while (uVar11 < uVar8);
              }
              in_ECX[0x14c] = '\0';
              in_ECX[0x14d] = '\0';
              in_ECX[0x14e] = '\0';
              in_ECX[0x14f] = '\0';
              return CONCAT31((int3)(uVar8 >> 8),1);
            }
            goto LAB_00770d37;
          }
LAB_00770d87:
          piVar9 = puVar6 + 1;
        }
        else {
          if (piVar5 != (int *)0x0) goto LAB_00770d87;
LAB_00770d37:
          piVar9 = (int *)0x0;
        }
        iVar10 = *piVar9;
        if (iVar10 != 0) {
          thunk_FUN_007637f0();
          thunk_FUN_007631b0(iVar10);
          puVar6 = local_10;
          piVar5 = local_14;
          pcVar7 = local_18;
        }
        if (piVar5 != (int *)0x0) {
          if (puVar6 == (undefined4 *)0x0) goto LAB_00770d63;
          puVar6 = (undefined4 *)*puVar6;
          while (local_10 = puVar6, puVar6 == (undefined4 *)0x0) {
LAB_00770d63:
            piVar5 = piVar5 + 1;
            if (piVar5 == (int *)(*(int *)(pcVar7 + 8) + *(int *)(pcVar7 + 0x14) * 4))
            goto LAB_00770d1d;
            local_14 = piVar5;
            puVar6 = (undefined4 *)*piVar5;
          }
        }
      } while( true );
    }
LAB_00770c5a:
    piVar5 = local_4 + 1;
  }
  else {
    if (local_8 != (undefined4 *)0x0) goto LAB_00770c5a;
LAB_00770c00:
    piVar5 = (int *)0x0;
  }
  iVar10 = *piVar5;
  if (*(int *)(iVar10 + 8) != 0) {
    local_20 = local_20 + 1;
  }
  FUN_007631b0(*(undefined4 *)(iVar10 + 0xc));
  thunk_FUN_007631b0(iVar10);
  if (local_8 != (undefined4 *)0x0) {
    if (local_4 == (undefined4 *)0x0) goto LAB_00770c35;
    local_4 = (undefined4 *)*local_4;
    while (local_4 == (undefined4 *)0x0) {
LAB_00770c35:
      local_8 = local_8 + 1;
      if (local_8 == (undefined4 *)(*(int *)(local_c + 8) + *(int *)(local_c + 0x14) * 4)) {
        local_8 = (undefined4 *)0x0;
        break;
      }
      local_4 = (undefined4 *)*local_8;
    }
  }
  goto LAB_00770bec;
LAB_00770d1d:
  piVar5 = (int *)0x0;
  local_14 = (int *)0x0;
  goto LAB_00770d23;
}

