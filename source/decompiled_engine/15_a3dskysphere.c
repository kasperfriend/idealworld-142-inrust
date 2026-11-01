/* Authentic Ghidra 12.1.4 Decompilation — elementclient.exe (PW 1.4.2 Build 2305) */
/* Module: 15_a3dskysphere.c */

/* ==================================================================== */
/* Address: 0x007998b0 | Classified: Angelica3D::proc_7998b0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007998b0(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x5b9);
  while (cVar1 != '\0') {
    Sleep(5);
    cVar1 = *(char *)(param_1 + 0x5b9);
  }
  if (*(int *)(param_1 + 0x54) != 0) {
    func_0x0077c560((undefined4 *)(param_1 + 0x54));
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  if (*(int *)(param_1 + 0x5ac) != 0) {
    func_0x0077c560((undefined4 *)(param_1 + 0x5ac));
    *(undefined4 *)(param_1 + 0x5ac) = 0;
  }
  if (*(int *)(param_1 + 0x5a4) != 0) {
    func_0x0077c560((undefined4 *)(param_1 + 0x5a4));
    *(undefined4 *)(param_1 + 0x5a4) = 0;
  }
  if (*(int *)(param_1 + 0x5a8) != 0) {
    func_0x0077c560((undefined4 *)(param_1 + 0x5a8));
    *(undefined4 *)(param_1 + 0x5a8) = 0;
  }
  if (*(int *)(param_1 + 0x8d0) != 0) {
    func_0x0077c560((undefined4 *)(param_1 + 0x8d0));
    *(undefined4 *)(param_1 + 0x8d0) = 0;
  }
  if (*(int *)(param_1 + 0x8c8) != 0) {
    func_0x0077c560((undefined4 *)(param_1 + 0x8c8));
    *(undefined4 *)(param_1 + 0x8c8) = 0;
  }
  if (*(int *)(param_1 + 0x8cc) != 0) {
    func_0x0077c560((undefined4 *)(param_1 + 0x8cc));
    *(undefined4 *)(param_1 + 0x8cc) = 0;
  }
  if (*(int *)(param_1 + 0x584) != 0) {
    func_0x00785220();
    if (*(undefined4 **)(param_1 + 0x584) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x584))(1);
    }
    *(undefined4 *)(param_1 + 0x584) = 0;
  }
  if (*(int *)(param_1 + 0x588) != 0) {
    func_0x00785220();
    if (*(undefined4 **)(param_1 + 0x588) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x588))(1);
    }
    *(undefined4 *)(param_1 + 0x588) = 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00799a40 | Classified: elementclient::A3DSky__Render_DrawIndexPrimitiv@0x799a40 */
/* ==================================================================== */

undefined4 __thiscall FUN_00799a40(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  float10 fVar5;
  undefined4 auStack_40 [13];
  float fStack_c;
  char cStack_4;
  
  if (param_2 != (int *)0x0) {
    fVar5 = (float10)fcos((float10)*(float *)(param_1 + 0x4c4));
    puVar3 = (undefined4 *)(param_1 + 0x14);
    puVar4 = auStack_40;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    fStack_c = (float)((float10)fStack_c - fVar5 * (float10)*(float *)(param_1 + 0x4c8));
    func_0x00779ca0(auStack_40);
    func_0x0077a1f0(0,2);
    if (cStack_4 == '\0') {
      iVar2 = param_1 + 0x504;
    }
    else {
      iVar2 = param_1 + 0x544;
    }
    func_0x00779da0(0,iVar2);
    (**(code **)(*param_2 + 0x18))(0);
    func_0x00785550(0,1);
    cVar1 = func_0x0077a590(4,0,*(undefined4 *)(param_1 + 0x59c),0,*(int *)(param_1 + 0x5a0) / 3);
    if (cVar1 == '\0') {
      func_0x007647d0(0x9d2f20,0x98bf8c);
      return 0;
    }
    (**(code **)(*param_2 + 0x1c))(0);
    func_0x0077a1f0(0,0);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00799b40 | Classified: elementclient::A3DSky__Render_DrawIndexPrimitiv@0x799b40 */
/* ==================================================================== */

undefined4 __fastcall FUN_00799b40(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uStack_8c;
  undefined1 auStack_4c [68];
  int *piStack_8;
  int *piStack_4;
  
  uStack_8c = 3;
  func_0x0077a0e0(0,3);
  if (piStack_8 != (int *)0x0) {
    func_0x00779ca0(param_1 + 0x14);
    (**(code **)(*piStack_8 + 0x18))(0);
    func_0x00785550(0,1);
    cVar1 = func_0x0077a590(4,0,*(undefined4 *)(param_1 + 0x58c),0,*(int *)(param_1 + 0x590) / 3);
    if (cVar1 == '\0') {
      func_0x007647d0(0x9d2f20,0x98bf8c);
      return 0;
    }
    (**(code **)(*piStack_8 + 0x1c))(0);
  }
  if (piStack_4 != (int *)0x0) {
    func_0x00787fa0(&uStack_8c);
    uStack_8c = 0xbf800000;
    uVar2 = func_0x007873a0(auStack_4c,&uStack_8c,param_1 + 0x14);
    func_0x00779ca0(uVar2);
    (**(code **)(*piStack_4 + 0x18))(0);
    func_0x00785550(0,1);
    cVar1 = func_0x0077a590(4,0,*(undefined4 *)(param_1 + 0x58c),0,*(int *)(param_1 + 0x590) / 3);
    if (cVar1 == '\0') {
      func_0x007647d0(0x9d2f20,0x98bfb4);
      return 0;
    }
    (**(code **)(*piStack_4 + 0x1c))(0);
  }
  func_0x0077a0e0(0,1,1);
  return 1;
}


/* ==================================================================== */
/* Address: 0x0079a040 | Classified: Angelica3D::proc_79a040 */
/* ==================================================================== */

undefined4 __fastcall FUN_0079a040(int param_1)

{
  int iVar1;
  
  if (((*(int *)(param_1 + 0xc) != 0) &&
      (FUN_0079a0e0(param_1 + 0x504,param_1 + 0x4cc), *(int *)(param_1 + 0x5b4) != 0)) &&
     (*(char *)(param_1 + 0x5b9) == '\0')) {
    FUN_0079a0e0(param_1 + 0x544,param_1 + 0x4e8);
    if (*(char *)(param_1 + 0x5b8) == '\0') {
      iVar1 = *(int *)(param_1 + 0x5b4) + 0x21;
      *(int *)(param_1 + 0x5b4) = iVar1;
      if (iVar1 < *(int *)(param_1 + 0x5b0)) {
        return 1;
      }
    }
    else {
      iVar1 = *(int *)(param_1 + 0x5b4) + -0x21;
      *(int *)(param_1 + 0x5b4) = iVar1;
      if (-1 < iVar1) {
        return 1;
      }
    }
    *(undefined4 *)(param_1 + 0x5b4) = 0;
    FUN_0079b180();
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0079a0e0 | Classified: Angelica3D::proc_79a0e0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079a0e0(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int aiStack_6c [10];
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 auStack_24 [36];
  
  aiStack_6c[2] = 0;
  aiStack_6c[1] = 0;
  aiStack_6c[5] = 0;
  aiStack_6c[3] = 0;
  aiStack_6c[7] = 0;
  aiStack_6c[6] = 0;
  aiStack_6c[8] = 0x3f800000;
  aiStack_6c[4] = 0x3f800000;
  aiStack_6c[0] = 0x3f800000;
  if ((float)param_2[3] != _DAT_008effc4) {
    aiStack_6c[6] = -0x41000000;
    aiStack_6c[7] = -0x41000000;
    fVar1 = (float)param_2[3] * _DAT_008f14bc + (float)param_2[6];
    param_2[6] = (int)fVar1;
    piVar3 = (int *)func_0x00789ec0(aiStack_6c + 9,aiStack_6c,fVar1);
    piVar5 = aiStack_6c;
    for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar5 = *piVar3;
      piVar3 = piVar3 + 1;
      piVar5 = piVar5 + 1;
    }
    piVar3 = (int *)func_0x00789f20(aiStack_6c + 9,aiStack_6c,0x3f000000,0x3f000000);
    piVar5 = aiStack_6c;
    for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar5 = *piVar3;
      piVar3 = piVar3 + 1;
      piVar5 = piVar5 + 1;
    }
  }
  iVar4 = *param_2;
  if (iVar4 != 0x3f800000) {
    uStack_40 = 0;
    uStack_44 = 0;
    uStack_34 = 0;
    uStack_3c = 0;
    uStack_2c = 0;
    uStack_30 = 0;
    uStack_28 = 0x3f800000;
    aiStack_6c[9] = iVar4;
    iStack_38 = iVar4;
    piVar3 = (int *)func_0x00787170(auStack_24,aiStack_6c,aiStack_6c + 9);
    piVar5 = aiStack_6c;
    for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar5 = *piVar3;
      piVar3 = piVar3 + 1;
      piVar5 = piVar5 + 1;
    }
  }
  if (((float)param_2[1] != _DAT_008effc4) || ((float)param_2[2] != _DAT_008effc4)) {
    fVar1 = (float)param_2[1] * _DAT_008f14bc + (float)param_2[4];
    param_2[4] = (int)fVar1;
    fVar2 = (float)param_2[2] * _DAT_008f14bc + (float)param_2[5];
    param_2[5] = (int)fVar2;
    piVar3 = (int *)func_0x00789f20(auStack_24,aiStack_6c,fVar1,fVar2);
    piVar5 = aiStack_6c;
    for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar5 = *piVar3;
      piVar3 = piVar3 + 1;
      piVar5 = piVar5 + 1;
    }
  }
  func_0x00787460();
  *param_1 = aiStack_6c[0];
  param_1[1] = aiStack_6c[1];
  param_1[2] = aiStack_6c[2];
  param_1[4] = aiStack_6c[3];
  param_1[6] = aiStack_6c[5];
  param_1[5] = aiStack_6c[4];
  param_1[8] = aiStack_6c[6];
  param_1[10] = aiStack_6c[8];
  param_1[9] = aiStack_6c[7];
  return;
}


/* ==================================================================== */
/* Address: 0x0079a330 | Classified: elementclient::A3DSkySphere__Init____Not_enough@0x79a330 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0079a330(int param_1)

{
  short sVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  ushort uVar11;
  ushort uVar12;
  short sVar13;
  undefined4 *unaff_FS_OFFSET;
  float10 fVar14;
  float10 fVar15;
  uint *puVar16;
  ushort uVar17;
  int iVar18;
  uint uStack_60;
  float afStack_5c [7];
  undefined4 uStack_38;
  undefined4 uStack_28;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd18b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  afStack_5c[6] = 1.00893e-43;
  *(uint *)(param_1 + 0x58c) = ((uint)*(ushort *)(param_1 + 0x4c0) * 5 + 5) * 2;
  *(uint *)(param_1 + 0x590) = (uint)*(ushort *)(param_1 + 0x4c0) * 0x30;
  afStack_5c[5] = 1.1170731e-38;
  iVar6 = func_0x00763250();
  uStack_4 = 0;
  if (iVar6 == 0) {
    iVar6 = 0;
  }
  else {
    afStack_5c[6] = 1.1170765e-38;
    iVar6 = func_0x00784d70();
  }
  uStack_4 = 0xffffffff;
  *(int *)(param_1 + 0x584) = iVar6;
  if (iVar6 == 0) {
    afStack_5c[6] = 1.4028068e-38;
    afStack_5c[5] = 1.4435078e-38;
    afStack_5c[4] = 1.1170816e-38;
    func_0x007647d0();
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  afStack_5c[4] = *(float *)(param_1 + 0x590);
  afStack_5c[3] = *(float *)(param_1 + 0x58c);
  afStack_5c[6] = 1.4013e-45;
  afStack_5c[5] = 1.4013e-45;
  afStack_5c[0] = *(float *)(param_1 + 0xc);
  afStack_5c[2] = 8.09951e-43;
  afStack_5c[1] = 4.48416e-44;
  uStack_60 = 0x79a3eb;
  cVar4 = func_0x00784f10();
  if (cVar4 == '\0') {
    uStack_60 = 0x98c058;
    func_0x007647d0(0x9d2f20);
    *unaff_FS_OFFSET = uStack_28;
    return 0;
  }
  uStack_60 = 0;
  cVar4 = func_0x007855c0(0,0,afStack_5c + 2);
  if (cVar4 != '\0') {
    puVar16 = &uStack_60;
    iVar6 = 0;
    cVar4 = func_0x00785700(0,0);
    if (cVar4 != '\0') {
      uVar12 = *(ushort *)(param_1 + 0x4c0);
      iVar7 = 0;
      fVar2 = *(float *)(param_1 + 0x4c8) * _DAT_008f14d0;
      iVar18 = 0;
      afStack_5c[0] = 1.0;
      afStack_5c[1] = 0.5;
      afStack_5c[2] = 0.167;
      sVar1 = uVar12 * 2 + 2;
      afStack_5c[3] = 0.0;
      afStack_5c[4] = -0.27;
      uVar17 = 0;
      do {
        uVar11 = 0;
        fVar3 = fVar2 * afStack_5c[uVar17];
        iVar9 = iVar18 * 6;
        iVar8 = iVar7 << 5;
        do {
          fVar14 = ((float10)_DAT_008f14cc * (float10)uVar11) / (float10)uVar12 +
                   (float10)_DAT_008f14cc;
          fVar15 = (float10)fcos(fVar14);
          *(float *)(iVar8 + (int)puVar16) = (float)(fVar15 * (float10)*(float *)(param_1 + 0x4c8));
          *(float *)(iVar8 + 4 + (int)puVar16) = fVar3;
          fVar14 = (float10)fsin(fVar14);
          *(float *)(iVar8 + 8 + (int)puVar16) =
               (float)(fVar14 * (float10)*(float *)(param_1 + 0x4c8));
          if (uVar17 == 0) {
            *(undefined4 *)(iVar8 + 0xc + (int)puVar16) = 0xffffff;
          }
          else {
            *(undefined4 *)(iVar8 + 0xc + (int)puVar16) = 0xffffffff;
          }
          *(float *)(iVar8 + 0x10 + (int)puVar16) =
               (float)((float10)_DAT_008effa0 -
                      (float10)uVar11 / (float10)*(ushort *)(param_1 + 0x4c0));
          if (uVar17 == 4) {
            *(undefined4 *)(iVar8 + 0x14 + (int)puVar16) = 0x3f000000;
          }
          else {
            *(float *)(iVar8 + 0x14 + (int)puVar16) =
                 (_DAT_008effa0 - fVar3 / fVar2) * _DAT_008f14c8 + _DAT_008f14c4;
          }
          *(undefined4 *)(iVar8 + 0x18 + (int)puVar16) = 0;
          *(undefined4 *)(iVar8 + 0x1c + (int)puVar16) = 0;
          if ((uVar11 != *(ushort *)(param_1 + 0x4c0)) && (uVar17 != 4)) {
            sVar5 = (short)iVar7;
            *(short *)(iVar9 + iVar6) = sVar5;
            *(short *)(iVar9 + 2 + iVar6) = sVar1 + sVar5;
            sVar13 = sVar5 + 1 + sVar1;
            *(short *)(iVar9 + 4 + iVar6) = sVar13;
            *(short *)(iVar9 + 6 + iVar6) = sVar5;
            *(short *)(iVar9 + 8 + iVar6) = sVar13;
            *(short *)(iVar9 + 10 + iVar6) = sVar5 + 1;
            iVar18 = iVar18 + 2;
            iVar9 = iVar9 + 0xc;
          }
          uVar12 = *(ushort *)(param_1 + 0x4c0);
          iVar7 = iVar7 + 1;
          iVar8 = iVar8 + 0x20;
          uVar11 = uVar11 + 1;
        } while (uVar11 <= uVar12);
        uVar11 = 0;
        iVar8 = iVar7 * 0x20;
        iVar9 = iVar18 * 6;
        do {
          fVar14 = ((float10)_DAT_008f14cc * (float10)uVar11) /
                   (float10)*(ushort *)(param_1 + 0x4c0);
          fVar15 = (float10)fcos(fVar14);
          *(float *)(iVar8 + (int)puVar16) = (float)(fVar15 * (float10)*(float *)(param_1 + 0x4c8));
          *(float *)(iVar8 + 4 + (int)puVar16) = fVar3;
          fVar14 = (float10)fsin(fVar14);
          *(float *)(iVar8 + 8 + (int)puVar16) =
               (float)(fVar14 * (float10)*(float *)(param_1 + 0x4c8));
          if (uVar17 == 0) {
            *(undefined4 *)(iVar8 + 0xc + (int)puVar16) = 0xffffff;
          }
          else {
            *(undefined4 *)(iVar8 + 0xc + (int)puVar16) = 0xffffffff;
          }
          uStack_60 = (uint)*(ushort *)(param_1 + 0x4c0);
          *(float *)(iVar8 + 0x10 + (int)puVar16) =
               (float)((float10)_DAT_008effa0 - (float10)uVar11 / (float10)uStack_60);
          if (uVar17 == 4) {
            *(undefined4 *)(iVar8 + 0x14 + (int)puVar16) = 0x3f000000;
          }
          else {
            *(float *)(iVar8 + 0x14 + (int)puVar16) =
                 (fVar3 / fVar2 + _DAT_008effa0) * _DAT_008eff98 * _DAT_008f14c0 + _DAT_008f14c4;
          }
          *(undefined4 *)(iVar8 + 0x18 + (int)puVar16) = 0;
          *(undefined4 *)(iVar8 + 0x1c + (int)puVar16) = 0;
          iVar10 = iVar9;
          if ((uVar11 != *(ushort *)(param_1 + 0x4c0)) && (uVar17 != 4)) {
            iVar18 = iVar18 + 2;
            sVar5 = (short)iVar7;
            *(short *)(iVar9 + iVar6) = sVar5;
            *(short *)(iVar9 + 2 + iVar6) = sVar1 + sVar5;
            iVar10 = iVar9 + 0xc;
            sVar13 = sVar5 + 1 + sVar1;
            *(short *)(iVar9 + 4 + iVar6) = sVar13;
            *(short *)(iVar9 + 6 + iVar6) = sVar5;
            *(short *)(iVar9 + 8 + iVar6) = sVar13;
            *(short *)(iVar9 + 10 + iVar6) = sVar5 + 1;
          }
          uVar12 = *(ushort *)(param_1 + 0x4c0);
          iVar7 = iVar7 + 1;
          iVar8 = iVar8 + 0x20;
          uVar11 = uVar11 + 1;
          iVar9 = iVar10;
        } while (uVar11 <= uVar12);
        uVar17 = uVar17 + 1;
      } while (uVar17 < 5);
      func_0x007856d0();
      func_0x00785810();
      *unaff_FS_OFFSET = afStack_5c[5];
      return 1;
    }
    func_0x007647d0(0x9d2f20,0x98bfe4);
    *unaff_FS_OFFSET = afStack_5c[5];
    return 0;
  }
  func_0x007647d0(0x9d2f20,0x98c020);
  *unaff_FS_OFFSET = uStack_38;
  return 0;
}


/* ==================================================================== */
/* Address: 0x0079a810 | Classified: elementclient::A3DSkySphere__Init____Not_enough@0x79a810 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __fastcall FUN_0079a810(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
  short sVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  short sVar13;
  int unaff_ESI;
  short sVar14;
  int iVar15;
  int iVar16;
  int *unaff_FS_OFFSET;
  float10 fVar17;
  float10 fVar18;
  float10 fVar19;
  float10 fVar20;
  int iStack_58;
  int iStack_54;
  int iStack_50;
  uint uStack_4c;
  int iStack_48;
  int iStack_44;
  float fStack_40;
  int iStack_28;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd1ab;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  uVar7 = (uint)*(ushort *)(param_1 + 0x4c0);
  fStack_40 = 1.00893e-43;
  *(uint *)(param_1 + 0x59c) = uVar7 * uVar7 * 4 + 1;
  *(uint *)(param_1 + 0x5a0) = (uVar7 * 0x18 + -0xc) * uVar7;
  iStack_44 = 0x79a863;
  iVar8 = func_0x00763250();
  uStack_4 = 0;
  if (iVar8 == 0) {
    iVar8 = 0;
  }
  else {
    fStack_40 = 1.1172534e-38;
    iVar8 = func_0x00784d70();
  }
  uStack_4 = 0xffffffff;
  *(int *)(param_1 + 0x588) = iVar8;
  if (iVar8 == 0) {
    fStack_40 = 1.4028068e-38;
    iStack_44 = 0x9d2f20;
    iStack_48 = 0x79a89f;
    func_0x007647d0();
    *unaff_FS_OFFSET = iStack_c;
    return 0;
  }
  iStack_48 = *(int *)(param_1 + 0x5a0);
  uStack_4c = *(undefined4 *)(param_1 + 0x59c);
  fStack_40 = 1.4013e-45;
  iStack_44 = 1;
  puVar4 = *(undefined4 **)(param_1 + 0xc);
  iStack_50 = 0x242;
  iStack_54 = 0x20;
  cVar6 = func_0x00784f10();
  if (cVar6 == '\0') {
    func_0x007647d0(0x9d2f20,0x98c0b8);
    *unaff_FS_OFFSET = iStack_28;
    return 0;
  }
  iVar8 = 0;
  cVar6 = func_0x007855c0(0,0,&iStack_48,0);
  if (cVar6 != '\0') {
    fVar17 = (float10)fsin((float10)*(float *)(param_1 + 0x4c4));
    iStack_50 = 0;
    fVar2 = *(float *)(param_1 + 0x4c8);
    *puVar4 = 0;
    puVar4[1] = *(undefined4 *)(param_1 + 0x4c8);
    puVar4[2] = 0;
    iVar15 = 1;
    puVar4[3] = 0xffffffff;
    uVar7 = (uint)*(ushort *)(param_1 + 0x4c0);
    iVar1 = uVar7 * 4;
    iVar12 = iVar1;
    uStack_4c = uVar7;
    if (uVar7 != 0) {
      do {
        iStack_48 = 0;
        if (iVar12 != 0) {
          iVar9 = iVar15 << 5;
          do {
            fVar18 = (float10)iStack_48;
            iVar15 = iVar15 + 1;
            iStack_48 = iStack_48 + 1;
            fVar18 = (fVar18 * (float10)_DAT_008f14d4) / (float10)iVar1;
            fVar19 = (float10)_DAT_008f14cc -
                     ((float10)(iStack_50 + 1) * (float10)*(float *)(param_1 + 0x4c4)) /
                     (float10)uStack_4c;
            fVar20 = (float10)fsin(fVar19);
            fStack_40 = (float)(fVar20 * (float10)*(float *)(param_1 + 0x4c8));
            fVar19 = (float10)fcos(fVar19);
            fVar20 = (float10)fsin(fVar18);
            fVar3 = *(float *)(param_1 + 0x4c8);
            fVar18 = (float10)fcos(fVar18);
            *(float *)(iVar9 + (int)puVar4) =
                 (float)(fVar18 * (float10)*(float *)(param_1 + 0x4c8) * fVar19);
            *(float *)(iVar9 + 4 + (int)puVar4) = fStack_40;
            *(float *)(iVar9 + 8 + (int)puVar4) = (float)(fVar20 * (float10)fVar3 * fVar19);
            *(undefined4 *)(iVar9 + 0xc + (int)puVar4) = 0xffffffff;
            uStack_4c = (uint)*(ushort *)(param_1 + 0x4c0);
            iVar12 = uStack_4c * 4;
            iVar9 = iVar9 + 0x20;
          } while (iStack_48 < iVar12);
        }
        uStack_4c = (uint)*(ushort *)(param_1 + 0x4c0);
        iStack_50 = iStack_50 + 1;
      } while (iStack_50 < (int)uStack_4c);
    }
    iVar12 = 0;
    if (0 < *(int *)(param_1 + 0x59c)) {
      fVar17 = (float10)_DAT_008effa0 / (fVar17 * (float10)fVar2);
      iVar15 = 0;
      do {
        *(float *)(iVar15 + 0x10 + (int)puVar4) =
             (float)((fVar17 * (float10)*(float *)(iVar15 + (int)puVar4) + (float10)_DAT_008effa0) *
                    (float10)_DAT_008eff98);
        *(float *)(iVar15 + 0x14 + (int)puVar4) =
             (float)((fVar17 * (float10)*(float *)(iVar15 + 8 + (int)puVar4) +
                     (float10)_DAT_008effa0) * (float10)_DAT_008eff98);
        iVar12 = iVar12 + 1;
        *(undefined4 *)(iVar15 + 0x18 + (int)puVar4) = 0;
        *(undefined4 *)(iVar15 + 0x1c + (int)puVar4) = 0;
        iVar15 = iVar15 + 0x20;
      } while (iVar12 < *(int *)(param_1 + 0x59c));
    }
    iStack_44 = iVar1;
    func_0x007856d0();
    cVar6 = func_0x00785700(0,0,&iStack_54,0);
    if (cVar6 != '\0') {
      uVar10 = 0;
      if (uVar7 != 0) {
        iVar12 = 0;
        do {
          *(undefined2 *)(iVar12 + iVar8) = 0;
          *(short *)(iVar12 + 2 + iVar8) = (short)uVar10 + 1;
          uVar10 = uVar10 + 1;
          *(short *)(iVar12 + 4 + iVar8) = (short)((int)uVar10 % iVar1) + 1;
          iVar12 = iVar12 + 6;
        } while ((int)uVar10 < iVar1);
      }
      iVar12 = 0;
      if (*(ushort *)(param_1 + 0x4c0) != 1 && -1 < (int)(*(ushort *)(param_1 + 0x4c0) - 1)) {
        iStack_50 = uVar7 * -4;
        iVar15 = 0;
        iStack_58 = 0;
        do {
          uVar11 = uVar10;
          if (uVar7 != 0) {
            uVar11 = uVar10 + uVar7 * 8;
            iVar9 = uVar10 * 6;
            iVar16 = iVar15;
            iStack_54 = iVar1;
            do {
              iVar16 = iVar16 + 1;
              sVar5 = (short)((iStack_58 + iVar16) % iVar1) + 1 + (short)iVar15;
              sVar14 = (short)iVar16;
              *(short *)(iVar9 + iVar8) = sVar14;
              *(short *)(iVar9 + 2 + iVar8) = sVar14 + (short)iVar1;
              sVar13 = sVar5 + (short)iVar1;
              *(short *)(iVar9 + 4 + iVar8) = sVar13;
              *(short *)(iVar9 + 6 + iVar8) = sVar14;
              *(short *)(iVar9 + 8 + iVar8) = sVar13;
              *(short *)(iVar9 + 10 + iVar8) = sVar5;
              iStack_54 = iStack_54 + -1;
              iVar9 = iVar9 + 0xc;
            } while (iStack_54 != 0);
            iStack_54 = 0;
            uStack_4c = uVar11;
          }
          iStack_58 = iStack_58 + iStack_50;
          iVar12 = iVar12 + 1;
          iVar15 = iVar15 + iVar1;
          uVar10 = uVar11;
        } while (iVar12 < (int)(*(ushort *)(param_1 + 0x4c0) - 1));
      }
      func_0x00785810();
      *unaff_FS_OFFSET = iStack_48;
      return 1;
    }
    *unaff_FS_OFFSET = iStack_48;
    return 0;
  }
  *unaff_FS_OFFSET = unaff_ESI;
  return 0;
}


/* ==================================================================== */
/* Address: 0x0079ac30 | Classified: elementclient::Textures_Sky__s@0x79ac30 */
/* ==================================================================== */

undefined4 __thiscall
FUN_0079ac30(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,float *param_5)

{
  int iVar1;
  undefined1 auStack_30c [260];
  undefined1 auStack_208 [260];
  undefined1 auStack_104 [260];
  
  if ((*(int *)(param_1 + 0x5b4) != 0) || (*(char *)(param_1 + 0x5b9) != '\0')) {
    return 0;
  }
  sprintf(auStack_208,0x98c0e8,param_2);
  sprintf(auStack_30c,0x98c0e8,param_3);
  sprintf(auStack_104,0x98c0e8,param_4);
  if ((*(int *)(param_1 + 0x5ac) != 0) &&
     ((*(int *)(param_1 + 0x5a4) != 0 && (*(int *)(param_1 + 0x5a8) != 0)))) {
    if (param_5 != (float *)0x0) {
      if (*(float *)(param_1 + 0x4cc) != *param_5) {
        return 1;
      }
      if (*(float *)(param_1 + 0x4d0) != param_5[1]) {
        return 1;
      }
      if (*(float *)(param_1 + 0x4d4) != param_5[2]) {
        return 1;
      }
      if (*(float *)(param_1 + 0x4d8) != param_5[3]) {
        return 1;
      }
    }
    iVar1 = _stricmp(auStack_208,*(undefined4 *)(*(int *)(param_1 + 0x5ac) + 0x24));
    if (((iVar1 == 0) &&
        (iVar1 = _stricmp(auStack_30c,*(undefined4 *)(*(int *)(param_1 + 0x5a4) + 0x24)), iVar1 == 0
        )) && (iVar1 = _stricmp(auStack_104,*(undefined4 *)(*(int *)(param_1 + 0x5a8) + 0x24)),
              iVar1 == 0)) {
      return 0;
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0079ad90 | Classified: elementclient::Textures_Sky@0x79ad90 */
/* ==================================================================== */

undefined4 FUN_0079ad90(int param_1)

{
  char cVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x8d0) != 0) {
    func_0x0077c560(param_1 + 0x8d0);
  }
  iVar2 = param_1 + 0x5ba;
  cVar1 = func_0x0077c1d0(iVar2,0x98bf7c,param_1 + 0x8d0,4,1);
  if (cVar1 != '\0') {
    if (*(int *)(param_1 + 0x8c8) != 0) {
      func_0x0077c560(param_1 + 0x8c8);
    }
    iVar2 = param_1 + 0x6be;
    cVar1 = func_0x0077c1d0(iVar2,0x98bf7c,param_1 + 0x8c8,4,1);
    if (cVar1 != '\0') {
      if (*(int *)(param_1 + 0x8cc) != 0) {
        func_0x0077c560(param_1 + 0x8cc);
      }
      iVar2 = param_1 + 0x7c2;
      cVar1 = func_0x0077c1d0(iVar2,0x98bf7c,param_1 + 0x8cc,4,1);
      if (cVar1 != '\0') {
        *(undefined1 *)(param_1 + 0x5b9) = 0;
        return 0;
      }
    }
  }
  func_0x007647d0(0x9d2f20,0x98c0f8,iVar2);
  *(undefined1 *)(param_1 + 0x5b9) = 0;
  return 0xffffffff;
}


/* ==================================================================== */
/* Address: 0x0079aeb0 | Classified: elementclient::Textures_Sky__s@0x79aeb0 */
/* ==================================================================== */

undefined4 __thiscall
FUN_0079aeb0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5,
            undefined4 *param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 auStack_310 [4];
  undefined1 auStack_30c [260];
  undefined1 auStack_208 [260];
  undefined1 auStack_104 [260];
  
  if ((*(int *)(param_1 + 0xc) != 0) && (*(char *)(param_1 + 0x5b9) == '\0')) {
    *(undefined1 *)(param_1 + 0x5b8) = 1;
    sprintf(auStack_30c,0x98c0e8,param_2);
    sprintf(auStack_208,0x98c0e8,param_3);
    sprintf(auStack_104,0x98c0e8,param_4);
    if ((*(int *)(param_1 + 0x5ac) != 0) &&
       ((*(int *)(param_1 + 0x5a4) != 0 && (*(int *)(param_1 + 0x5a8) != 0)))) {
      iVar1 = _stricmp(auStack_30c,*(undefined4 *)(*(int *)(param_1 + 0x5ac) + 0x24));
      if (iVar1 == 0) {
        iVar1 = _stricmp(auStack_208,*(undefined4 *)(*(int *)(param_1 + 0x5a4) + 0x24));
        if (iVar1 == 0) {
          iVar1 = _stricmp(auStack_104,*(undefined4 *)(*(int *)(param_1 + 0x5a8) + 0x24));
          if (iVar1 == 0) {
            if (param_6 != (undefined4 *)0x0) {
              puVar2 = (undefined4 *)(param_1 + 0x4cc);
              for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
                *puVar2 = *param_6;
                param_6 = param_6 + 1;
                puVar2 = puVar2 + 1;
              }
            }
            *(undefined1 *)(param_1 + 0x5b8) = 0;
            return 1;
          }
        }
      }
    }
    if (((*(int *)(param_1 + 0x8d0) != 0) && (*(int *)(param_1 + 0x8c8) != 0)) &&
       (*(int *)(param_1 + 0x8cc) != 0)) {
      iVar1 = _stricmp(auStack_30c,*(undefined4 *)(*(int *)(param_1 + 0x8d0) + 0x24));
      if (iVar1 == 0) {
        iVar1 = _stricmp(auStack_208,*(undefined4 *)(*(int *)(param_1 + 0x8c8) + 0x24));
        if (iVar1 == 0) {
          iVar1 = _stricmp(auStack_104,*(undefined4 *)(*(int *)(param_1 + 0x8cc) + 0x24));
          if (iVar1 == 0) {
            if (param_6 != (undefined4 *)0x0) {
              puVar2 = (undefined4 *)(param_1 + 0x4e8);
              for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
                *puVar2 = *param_6;
                param_6 = param_6 + 1;
                puVar2 = puVar2 + 1;
              }
            }
            *(undefined1 *)(param_1 + 0x5b8) = 1;
            return 1;
          }
        }
      }
    }
    iVar1 = 7;
    puVar2 = (undefined4 *)(param_1 + 0x4e8);
    if (param_6 == (undefined4 *)0x0) {
      param_6 = (undefined4 *)(param_1 + 0x4cc);
    }
    for (; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *param_6;
      param_6 = param_6 + 1;
      puVar2 = puVar2 + 1;
    }
    strncpy(param_1 + 0x5ba,param_2,0x104);
    strncpy(param_1 + 0x6be,param_3,0x104);
    strncpy(param_1 + 0x7c2,param_4,0x104);
    *(undefined1 *)(param_1 + 0x5b9) = 1;
    param_5 = ((int)param_5 < 1) - 1 & param_5;
    *(uint *)(param_1 + 0x5b0) = param_5;
    *(uint *)(param_1 + 0x5b4) = param_5;
    if (param_5 == 0) {
      iVar1 = FUN_0079ad90(param_1);
      if (iVar1 == -1) {
        return 0;
      }
      FUN_0079b180();
      return 1;
    }
    CreateThread(0,0,FUN_0079ad90,param_1,0,auStack_310);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0079b150 | Classified: Angelica3D::proc_79b150 */
/* ==================================================================== */

undefined4 __thiscall FUN_0079b150(int *param_1,int param_2)

{
  if (param_1[0x16d] != 0) {
    param_2 = param_1[0x16d] - param_2;
    param_1[0x16d] = param_2;
    if (param_2 < 1) {
      param_1[0x16d] = 1;
    }
    (**(code **)(*param_1 + 0x10))();
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0079b180 | Classified: Angelica3D::proc_79b180 */
/* ==================================================================== */

undefined4 __fastcall FUN_0079b180(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (*(char *)(param_1 + 0x5b8) != '\0') {
    puVar3 = (undefined4 *)(param_1 + 0x5ac);
    if (*(int *)(param_1 + 0x5ac) != 0) {
      func_0x0077c560(puVar3);
      *puVar3 = 0;
    }
    puVar4 = (undefined4 *)(param_1 + 0x5a4);
    if (*(int *)(param_1 + 0x5a4) != 0) {
      func_0x0077c560(puVar4);
      *puVar4 = 0;
    }
    puVar1 = (undefined4 *)(param_1 + 0x5a8);
    if (*(int *)(param_1 + 0x5a8) != 0) {
      func_0x0077c560(puVar1);
      *puVar1 = 0;
    }
    *puVar3 = *(undefined4 *)(param_1 + 0x8d0);
    *puVar4 = *(undefined4 *)(param_1 + 0x8c8);
    *puVar1 = *(undefined4 *)(param_1 + 0x8cc);
    *(undefined4 *)(param_1 + 0x8d0) = 0;
    puVar3 = (undefined4 *)(param_1 + 0x4e8);
    puVar4 = (undefined4 *)(param_1 + 0x4cc);
    for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    *(undefined4 *)(param_1 + 0x8c8) = 0;
    puVar3 = (undefined4 *)(param_1 + 0x544);
    puVar4 = (undefined4 *)(param_1 + 0x504);
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    *(undefined4 *)(param_1 + 0x8cc) = 0;
    return 1;
  }
  if (*(int *)(param_1 + 0x8d0) != 0) {
    func_0x0077c560((undefined4 *)(param_1 + 0x8d0));
    *(undefined4 *)(param_1 + 0x8d0) = 0;
  }
  if (*(int *)(param_1 + 0x8c8) != 0) {
    func_0x0077c560((undefined4 *)(param_1 + 0x8c8));
    *(undefined4 *)(param_1 + 0x8c8) = 0;
  }
  if (*(int *)(param_1 + 0x8cc) != 0) {
    func_0x0077c560((undefined4 *)(param_1 + 0x8cc));
    *(undefined4 *)(param_1 + 0x8cc) = 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0079b2f0 | Classified: Angelica3D::proc_79b2f0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0079b2f0(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = _DAT_009858e4;
  *param_1 = &UNK_008f1548;
  *(undefined1 *)(param_1 + 0x1e) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x0079b310 | Classified: Angelica3D::proc_79b310 */
/* ==================================================================== */

undefined4 __thiscall FUN_0079b310(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x80) = param_2;
  *(undefined1 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = param_3;
  FUN_0079b370();
  return 1;
}


/* ==================================================================== */
/* Address: 0x0079b330 | Classified: Angelica3D::proc_79b330 */
/* ==================================================================== */

undefined1 FUN_0079b330(void)

{
  FUN_0079b370();
  return 1;
}


/* ==================================================================== */
/* Address: 0x0079b340 | Classified: Angelica3D::proc_79b340 */
/* ==================================================================== */

undefined4 __fastcall FUN_0079b340(int param_1)

{
  *(undefined1 *)(param_1 + 0x78) = 1;
  func_0x0077a3f0(*(undefined4 *)(param_1 + 0x7c),param_1 + 0x10);
  func_0x0077a420(*(undefined4 *)(param_1 + 0x7c),1);
  return 1;
}


/* ==================================================================== */
/* Address: 0x0079b370 | Classified: Angelica3D::proc_79b370 */
/* ==================================================================== */

undefined4 __fastcall FUN_0079b370(int param_1)

{
  *(undefined1 *)(param_1 + 0x78) = 0;
  func_0x0077a420(*(undefined4 *)(param_1 + 0x7c),0);
  return 1;
}


/* ==================================================================== */
/* Address: 0x0079b390 | Classified: Angelica3D::proc_79b390 */
/* ==================================================================== */

undefined4 __thiscall FUN_0079b390(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_1 + 0x10);
  *puVar1 = *param_2;
  *(undefined4 *)(param_1 + 0x14) = param_2[1];
  *(undefined4 *)(param_1 + 0x18) = param_2[2];
  *(undefined4 *)(param_1 + 0x1c) = param_2[3];
  *(undefined4 *)(param_1 + 0x20) = param_2[4];
  *(undefined4 *)(param_1 + 0x24) = param_2[5];
  *(undefined4 *)(param_1 + 0x28) = param_2[6];
  *(undefined4 *)(param_1 + 0x2c) = param_2[7];
  *(undefined4 *)(param_1 + 0x30) = param_2[8];
  *(undefined4 *)(param_1 + 0x34) = param_2[9];
  *(undefined4 *)(param_1 + 0x38) = param_2[10];
  *(undefined4 *)(param_1 + 0x3c) = param_2[0xb];
  *(undefined4 *)(param_1 + 0x40) = param_2[0xc];
  *(undefined4 *)(param_1 + 0x44) = param_2[0xd];
  *(undefined4 *)(param_1 + 0x48) = param_2[0xe];
  *(undefined4 *)(param_1 + 0x4c) = param_2[0xf];
  *(undefined4 *)(param_1 + 0x50) = param_2[0x10];
  *(undefined4 *)(param_1 + 0x54) = param_2[0x11];
  *(undefined4 *)(param_1 + 0x58) = param_2[0x12];
  *(undefined4 *)(param_1 + 0x5c) = param_2[0x13];
  *(undefined4 *)(param_1 + 0x60) = param_2[0x14];
  *(undefined4 *)(param_1 + 100) = param_2[0x15];
  *(undefined4 *)(param_1 + 0x68) = param_2[0x16];
  *(undefined4 *)(param_1 + 0x6c) = param_2[0x17];
  *(undefined4 *)(param_1 + 0x70) = param_2[0x18];
  *(undefined4 *)(param_1 + 0x74) = param_2[0x19];
  *(undefined4 *)(param_1 + 0xc) = *puVar1;
  func_0x0077a3f0(*(undefined4 *)(param_1 + 0x7c),puVar1);
  return 1;
}


/* ==================================================================== */
/* Address: 0x0079b450 | Classified: Angelica3D::proc_79b450 */
/* ==================================================================== */

undefined4 * __fastcall FUN_0079b450(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd1c8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  func_0x0079bb40();
  uStack_4 = 0;
  FUN_007662b0();
  param_1[3] = 0;
  param_1[0x5e5] = 0;
  param_1[0x5e0] = 0;
  param_1[0x5e1] = 0;
  param_1[0x5e2] = 0x43160000;
  param_1[0x5e3] = 0x43160000;
  *param_1 = &UNK_008f15c0;
  param_1[1] = 7;
  param_1[0x5e4] = 0x42700000;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0079b4e0 | Classified: Angelica3D::proc_79b4e0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0079b4e0(undefined4 param_1,byte param_2)

{
  FUN_0079b500();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0079b500 | Classified: Angelica3D::proc_79b500 */
/* ==================================================================== */

void __fastcall FUN_0079b500(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008cd1e8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f15c0;
  uStack_4 = 0;
  FUN_007662d0();
  uStack_4 = 0xffffffff;
  func_0x007dc680();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


