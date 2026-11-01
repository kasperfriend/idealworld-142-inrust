// rea decompile_all
// name: FUN_007a1ce0
// address: 0x7a1ce0
// body: available
// range: 0x7a1ce0-0x7a2405 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e1ad533d4cc0333c2136fe0894217de2d61feea098240326e78633f9e4ddcbf9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_007a1ce0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  int in_ECX;
  int iVar8;
  undefined4 unaff_ESI;
  int *piVar9;
  uint *puVar10;
  undefined4 unaff_EDI;
  int *piVar11;
  undefined4 *puVar12;
  undefined4 *puStack_84;
  char *pcStack_80;
  int **ppiStack_7c;
  undefined4 uStack_78;
  undefined4 *puStack_74;
  undefined4 local_60;
  undefined4 auStack_5c [5];
  int aiStack_48 [3];
  int *local_3c [3];
  undefined4 uStack_30;
  int iStack_2c;
  ushort uStack_28;
  ushort uStack_26;
  undefined2 uStack_24;
  undefined2 uStack_22;
  int *local_20;
  undefined4 *puStack_1c;
  int iStack_18;
  int *piStack_14;
  undefined4 uStack_10;
  int *piStack_8;
  
  uVar6 = *(uint *)(in_ECX + 0x894);
  puStack_74 = &local_60;
  piVar9 = (int *)(in_ECX + 0x10);
  if (uVar6 < 2) {
    ppiStack_7c = local_3c;
    uStack_78 = 0x10;
    pcStack_80 = (char *)0x7a1d14;
    cVar5 = (**(code **)(*piVar9 + 0x10))();
    if (cVar5 == '\0') {
      pcStack_80 = s_A3DTrn2SubLoaderB__ReadBlockData_0098d110;
      puStack_84 = (undefined4 *)&DAT_009d2f20;
      uVar6 = FUN_007647d0();
      return uVar6 & 0xffffff00;
    }
    iStack_2c = aiStack_48[0];
    uStack_24 = (undefined2)aiStack_48[2];
    uStack_22 = (undefined2)((uint)aiStack_48[2] >> 0x10);
    local_20 = local_3c[0];
    uStack_28 = (ushort)aiStack_48[1];
    uStack_26 = (ushort)((uint)aiStack_48[1] >> 0x10);
    puStack_1c = (undefined4 *)(*(int *)(param_1 + 0x6c) * 4);
    iStack_18 = *(int *)(param_1 + 0x6c) * 0xc;
  }
  else {
    if (2 < uVar6) {
      if (uVar6 < 4) {
        ppiStack_7c = local_3c;
        uStack_78 = 0x1c;
        pcStack_80 = (char *)0x7a1e30;
        cVar5 = (**(code **)(*piVar9 + 0x10))();
        if (cVar5 == '\0') {
          pcStack_80 = s_A3DTrn2SubLoaderB__ReadBlockData_0098d110;
          puStack_84 = (undefined4 *)&DAT_009d2f20;
          uVar6 = FUN_007647d0();
          return uVar6 & 0xffffff00;
        }
        piVar9 = aiStack_48;
        piVar11 = &iStack_2c;
        for (iVar8 = 7; iVar8 != 0; iVar8 = iVar8 + -1) {
          *piVar11 = *piVar9;
          piVar9 = piVar9 + 1;
          piVar11 = piVar11 + 1;
        }
        uStack_10 = 0;
      }
      else {
        ppiStack_7c = &local_20;
        uStack_78 = 0x20;
        pcStack_80 = (char *)0x7a1e78;
        cVar5 = (**(code **)(*piVar9 + 0x10))();
        if (cVar5 == '\0') {
          pcStack_80 = s_A3DTrn2SubLoaderB__ReadBlockData_0098d110;
          puStack_84 = (undefined4 *)&DAT_009d2f20;
          uVar6 = FUN_007647d0();
          return uVar6 & 0xffffff00;
        }
      }
      goto LAB_007a1d76;
    }
    ppiStack_7c = local_3c;
    uStack_78 = 0x18;
    pcStack_80 = (char *)0x7a1de9;
    cVar5 = (**(code **)(*piVar9 + 0x10))();
    if (cVar5 == '\0') {
      pcStack_80 = s_A3DTrn2SubLoaderB__ReadBlockData_0098d110;
      puStack_84 = (undefined4 *)&DAT_009d2f20;
      uVar6 = FUN_007647d0();
      return uVar6 & 0xffffff00;
    }
    piVar9 = aiStack_48;
    piVar11 = &iStack_2c;
    for (iVar8 = 6; iVar8 != 0; iVar8 = iVar8 + -1) {
      *piVar11 = *piVar9;
      piVar9 = piVar9 + 1;
      piVar11 = piVar11 + 1;
    }
  }
  piStack_14 = (int *)0x0;
LAB_007a1d76:
  uVar6 = (uint)uStack_28;
  uVar4 = (uint)uStack_26;
  *(int **)(param_1 + 0x80) = local_20;
  iVar8 = 0;
  *(int *)(param_1 + 0x20) = iStack_2c;
  *(uint *)(param_1 + 0x28) = uVar6;
  *(uint *)(param_1 + 0x2c) = uVar4;
  *(undefined4 *)(param_1 + 0x7c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x70) = 3;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  do {
    if (((uint)local_20 & 1 << ((byte)iVar8 & 0x1f)) != 0) {
      *(int *)(param_1 + 0x84) = iVar8;
      break;
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 < 0x20);
  iVar8 = *(int *)(*(int *)(in_ECX + 4) + 0x1d4) / *(int *)(*(int *)(in_ECX + 4) + 0x1d0);
  *(int *)(param_1 + 0x30) = (int)((longlong)(ulonglong)uVar6 % (longlong)iVar8);
  *(int *)(param_1 + 0x34) = (int)((longlong)(ulonglong)uVar4 % (longlong)iVar8);
  iVar8 = *(int *)(in_ECX + 4);
  iVar7 = *(int *)(iVar8 + 0x1d8) / *(int *)(iVar8 + 0x1d0);
  *(int *)(param_1 + 0x1c) =
       (*(int *)(iVar8 + 0x188) / iVar7) * (int)((longlong)(ulonglong)uVar6 / (longlong)iVar7) +
       (int)((longlong)(ulonglong)uVar4 / (longlong)iVar7);
  iVar8 = *(int *)(in_ECX + 4);
  puVar10 = (uint *)(iVar8 + 0x310);
  local_60 = 0;
  auStack_5c[0] = 0;
  if (*(char *)(in_ECX + 0x890) != '\0') {
    pcStack_80 = (char *)auStack_5c;
    puStack_84 = &local_60;
    cVar5 = FUN_007a39f0(&stack0xffffff98,&stack0xffffff9c,0);
    if (cVar5 == '\0') {
      pcStack_80 = s_A3DTrn2SubLoaderB__ReadBlockData_0098d0d4;
      puStack_84 = (undefined4 *)&DAT_009d2f20;
      uVar6 = FUN_007647d0();
      return uVar6 & 0xffffff00;
    }
  }
  pcStack_80 = &stack0xffffff94;
  puStack_84 = puStack_1c;
  if ((*(byte *)(in_ECX + 0x890) & 0xc) == 0) {
    cVar5 = (**(code **)(*piStack_8 + 0x10))(*(undefined4 *)(iVar8 + 0x314));
    if (cVar5 == '\0') {
      uVar6 = FUN_007647d0(&DAT_009d2f20,s_A3DTrn2SubLoaderB__ReadBlockData_0098d090);
      return uVar6 & 0xffffff00;
    }
  }
  else {
    cVar5 = (**(code **)(*piStack_8 + 0x10))(0);
    if (cVar5 == '\0') {
      uVar6 = FUN_007647d0(&DAT_009d2f20,s_A3DTrn2SubLoaderB__ReadBlockData_0098d090);
      return uVar6 & 0xffffff00;
    }
    if ((*(byte *)(in_ECX + 0x890) & 8) == 0) {
      FUN_00771a40(puStack_74,CONCAT22(uStack_26,uStack_28),*(undefined4 *)(iVar8 + 0x314),
                   &stack0xffffff9c);
    }
    else if ((*(byte *)(in_ECX + 0x890) & 4) == 0) {
      FUN_0077f920(puStack_74,*(undefined4 *)(iVar8 + 0x314));
    }
    else {
      FUN_00771a40(puStack_74,CONCAT22(uStack_26,uStack_28),unaff_ESI,&stack0xffffff9c);
      FUN_0077f920(unaff_ESI,*(undefined4 *)(iVar8 + 0x314));
    }
  }
  if ((*(byte *)(in_ECX + 0x890) & 0x30) == 0) {
    cVar5 = (**(code **)(*piStack_14 + 0x10))(*(undefined4 *)(iVar8 + 0x318));
    if (cVar5 == '\0') {
      uVar6 = FUN_007647d0(&DAT_009d2f20,s_A3DTrn2SubLoaderB__ReadBlockData_0098d048);
      return uVar6 & 0xffffff00;
    }
  }
  else {
    cVar5 = (**(code **)(*piStack_14 + 0x10))(unaff_EDI,CONCAT22(uStack_22,uStack_24),&uStack_78);
    if (cVar5 == '\0') {
      uVar6 = FUN_007647d0(&DAT_009d2f20,s_A3DTrn2SubLoaderB__ReadBlockData_0098d048);
      return uVar6 & 0xffffff00;
    }
    if ((*(byte *)(in_ECX + 0x890) & 0x20) == 0) {
      FUN_00771a40(ppiStack_7c,uStack_30,*(undefined4 *)(iVar8 + 0x318),&stack0xffffff90);
    }
    else if ((*(byte *)(in_ECX + 0x890) & 0x10) == 0) {
      FUN_0077f990(ppiStack_7c,*(undefined4 *)(iVar8 + 0x318));
    }
    else {
      FUN_00771a40(ppiStack_7c,uStack_30,puStack_74,&stack0xffffff90);
      FUN_0077f990(puStack_74,*(undefined4 *)(iVar8 + 0x318));
    }
  }
  if (*(char *)(*(int *)(in_ECX + 4) + 0x1b5) != '\0') {
    if ((*(byte *)(in_ECX + 0x890) & 1) == 0) {
      if ((*(uint *)(in_ECX + 0x894) < 3) || (iStack_2c == 0)) {
        puVar12 = *(undefined4 **)(iVar8 + 0x31c);
        for (uVar6 = *puVar10 & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar12 = 0xffffffff;
          puVar12 = puVar12 + 1;
        }
        for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
          *(undefined1 *)puVar12 = 0xff;
          puVar12 = (undefined4 *)((int)puVar12 + 1);
        }
      }
      else {
        cVar5 = (**(code **)(*local_20 + 0x10))
                          (*(undefined4 *)(iVar8 + 0x31c),iStack_2c,&puStack_84);
        if (cVar5 == '\0') {
          uVar6 = FUN_007647d0(&DAT_009d2f20,s_A3DTrn2SubLoaderB__ReadBlockData_0098d000);
          return uVar6 & 0xffffff00;
        }
      }
      if ((*(uint *)(in_ECX + 0x894) < 4) || (CONCAT22(uStack_26,uStack_28) == 0)) {
        puVar12 = *(undefined4 **)(iVar8 + 800);
        for (uVar6 = *puVar10 & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar12 = 0xffffffff;
          puVar12 = puVar12 + 1;
        }
        for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
          *(undefined1 *)puVar12 = 0xff;
          puVar12 = (undefined4 *)((int)puVar12 + 1);
        }
      }
      else {
        cVar5 = (**(code **)(*local_20 + 0x10))
                          (*(undefined4 *)(iVar8 + 800),CONCAT22(uStack_26,uStack_28),&puStack_84);
        if (cVar5 == '\0') {
          uVar6 = FUN_007647d0(&DAT_009d2f20,s_A3DTrn2SubLoaderB__ReadBlockData_0098d000);
          return uVar6 & 0xffffff00;
        }
      }
    }
    else {
      ppiStack_7c = (int **)0x0;
      if (((iStack_2c != 0) || (CONCAT22(uStack_26,uStack_28) != 0)) &&
         (cVar5 = FUN_007a39f0(0,0,&ppiStack_7c,0,0), cVar5 == '\0')) {
        uVar6 = FUN_007647d0(&DAT_009d2f20,s_A3DTrn2SubLoaderB__ReadBlockData_0098d0d4);
        return uVar6 & 0xffffff00;
      }
      if ((2 < *(uint *)(in_ECX + 0x894)) && (iStack_2c != 0)) {
        cVar5 = (**(code **)(*local_20 + 0x10))(ppiStack_7c,iStack_2c,&puStack_84);
        if (cVar5 == '\0') {
          uVar6 = FUN_007647d0(&DAT_009d2f20,s_A3DTrn2SubLoaderB__ReadBlockData_0098d000);
          return uVar6 & 0xffffff00;
        }
        FUN_00771a40(ppiStack_7c,iStack_2c,*(undefined4 *)(iVar8 + 0x31c),&stack0xffffff90);
      }
      if ((3 < *(uint *)(in_ECX + 0x894)) && (CONCAT22(uStack_26,uStack_28) != 0)) {
        cVar5 = (**(code **)(*local_20 + 0x10))
                          (ppiStack_7c,CONCAT22(uStack_26,uStack_28),&puStack_84);
        if (cVar5 == '\0') {
          uVar6 = FUN_007647d0(&DAT_009d2f20,s_A3DTrn2SubLoaderB__ReadBlockData_0098d000);
          return uVar6 & 0xffffff00;
        }
        local_20 = (int *)(*puVar10 << 2);
        FUN_00771a40(ppiStack_7c,CONCAT22(uStack_26,uStack_28),*(undefined4 *)(iVar8 + 800),
                     &local_20);
      }
    }
  }
  cVar5 = FUN_007c3ad0(puStack_1c,iStack_18);
  if (cVar5 != '\0') {
    fVar1 = (*(float *)(param_1 + 0x54) + *(float *)(param_1 + 0x60)) * 0.5;
    fVar2 = (*(float *)(param_1 + 0x58) + *(float *)(param_1 + 100)) * 0.5;
    *(float *)(param_1 + 0x3c) = fVar1;
    fVar3 = (*(float *)(param_1 + 0x5c) + *(float *)(param_1 + 0x68)) * 0.5;
    *(float *)(param_1 + 0x44) = fVar3;
    *(float *)(param_1 + 0x40) = fVar2;
    *(float *)(param_1 + 0x48) = *(float *)(param_1 + 0x60) - fVar1;
    *(float *)(param_1 + 0x50) = *(float *)(param_1 + 0x68) - fVar3;
    *(float *)(param_1 + 0x4c) = *(float *)(param_1 + 100) - fVar2;
    *(undefined1 *)(param_1 + 0x18) = 1;
    return CONCAT31((int3)((uint)fVar2 >> 8),1);
  }
  uVar6 = FUN_007647d0(&DAT_009d2f20,s_A3DTrn2SubLoaderB__ReadBlockData_0098cfc0);
  return uVar6 & 0xffffff00;
}

