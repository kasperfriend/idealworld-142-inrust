/* Authentic Ghidra 12.1.4 Decompilation — elementclient.exe (PW 1.4.2 Build 2305) */
/* Module: 18_a3dlitmesh_litmodel_bmd.c */

/* ==================================================================== */
/* Address: 0x007b9430 | Classified: Angelica3D::proc_7b9430 */
/* ==================================================================== */

undefined4 __thiscall FUN_007b9430(undefined4 param_1,byte param_2)

{
  FUN_007b9450();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007b9450 | Classified: Angelica3D::proc_7b9450 */
/* ==================================================================== */

void __fastcall FUN_007b9450(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  uint uStack_4;
  
  puStack_8 = &UNK_008cdee6;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f29b0;
  uStack_4 = 1;
  FUN_007b95e0();
  uStack_4 = uStack_4 & 0xffffff00;
  func_0x007dc680();
  uStack_4 = 0xffffffff;
  *param_1 = &UNK_008d6410;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x007b94c0 | Classified: elementclient::A3DLitMesh__Create____failed_to_c@0x7b94c0 */
/* ==================================================================== */

undefined4 __thiscall
FUN_007b94c0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 auStack_44 [17];
  
  *(undefined4 *)(param_1 + 0x2c0) = param_3;
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x2c4) = param_4;
  strncpy(param_1 + 0x14,param_5,0x100);
  cVar1 = FUN_007b9a00();
  if (cVar1 == '\0') {
    func_0x007647d0(0x9d2f20,0x98ecd8);
    return 0;
  }
  cVar1 = FUN_007b9880();
  if (cVar1 == '\0') {
    func_0x007647d0(0x9d2f20,0x98eca8);
    return 0;
  }
  puVar3 = auStack_44;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  auStack_44[0] = 0x3f800000;
  auStack_44[1] = 0x3f800000;
  auStack_44[2] = 0x3f800000;
  auStack_44[3] = 0x3f800000;
  auStack_44[4] = 0x3f800000;
  auStack_44[5] = 0x3f800000;
  auStack_44[6] = 0x3f800000;
  auStack_44[7] = 0x3f800000;
  auStack_44[8] = 0;
  auStack_44[9] = 0;
  auStack_44[10] = 0;
  auStack_44[0xb] = 0x3f800000;
  auStack_44[0xc] = 0;
  auStack_44[0xd] = 0;
  auStack_44[0xe] = 0;
  auStack_44[0xf] = 0x3f800000;
  auStack_44[0x10] = 0;
  func_0x007b66d0(param_2,auStack_44);
  return 1;
}


/* ==================================================================== */
/* Address: 0x007b95e0 | Classified: Angelica3D::proc_7b95e0 */
/* ==================================================================== */

undefined1 FUN_007b95e0(void)

{
  FUN_007b99a0();
  FUN_007b9b30();
  return 1;
}


/* ==================================================================== */
/* Address: 0x007b9600 | Classified: Angelica3D::proc_7b9600 */
/* ==================================================================== */

undefined4 __thiscall FUN_007b9600(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  short *psVar12;
  int iVar13;
  undefined4 *puVar14;
  int iVar15;
  undefined4 *puVar16;
  
  iVar13 = *(int *)(param_1 + 0x2c0) + *(int *)(param_2 + 0x2c0);
  iVar15 = *(int *)(param_2 + 0x2c4) + *(int *)(param_1 + 0x2c4);
  puVar3 = (undefined4 *)func_0x00763250(iVar13 * 0x24);
  puVar4 = (undefined4 *)func_0x00763250(iVar15 * 6);
  puVar5 = (undefined4 *)func_0x00763250(iVar13 * 0xc);
  puVar6 = (undefined4 *)func_0x00763250(iVar13 * 4);
  puVar7 = (undefined4 *)func_0x00763250(iVar13 * 4);
  puVar14 = *(undefined4 **)(param_1 + 0x278);
  puVar16 = puVar3;
  for (uVar8 = *(int *)(param_1 + 0x2c0) * 9 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
    *puVar16 = *puVar14;
    puVar14 = puVar14 + 1;
    puVar16 = puVar16 + 1;
  }
  for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
    *(undefined1 *)puVar16 = *(undefined1 *)puVar14;
    puVar14 = (undefined4 *)((int)puVar14 + 1);
    puVar16 = (undefined4 *)((int)puVar16 + 1);
  }
  puVar14 = *(undefined4 **)(param_2 + 0x278);
  puVar16 = puVar3 + *(int *)(param_1 + 0x2c0) * 9;
  for (uVar8 = *(int *)(param_2 + 0x2c0) * 9 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
    *puVar16 = *puVar14;
    puVar14 = puVar14 + 1;
    puVar16 = puVar16 + 1;
  }
  for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
    *(undefined1 *)puVar16 = *(undefined1 *)puVar14;
    puVar14 = (undefined4 *)((int)puVar14 + 1);
    puVar16 = (undefined4 *)((int)puVar16 + 1);
  }
  puVar14 = *(undefined4 **)(param_1 + 0x280);
  puVar16 = puVar5;
  for (uVar8 = *(int *)(param_1 + 0x2c0) * 3 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
    *puVar16 = *puVar14;
    puVar14 = puVar14 + 1;
    puVar16 = puVar16 + 1;
  }
  for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
    *(undefined1 *)puVar16 = *(undefined1 *)puVar14;
    puVar14 = (undefined4 *)((int)puVar14 + 1);
    puVar16 = (undefined4 *)((int)puVar16 + 1);
  }
  puVar14 = *(undefined4 **)(param_2 + 0x280);
  puVar16 = puVar5 + *(int *)(param_1 + 0x2c0) * 3;
  for (uVar8 = *(int *)(param_2 + 0x2c0) * 3 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
    *puVar16 = *puVar14;
    puVar14 = puVar14 + 1;
    puVar16 = puVar16 + 1;
  }
  for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
    *(undefined1 *)puVar16 = *(undefined1 *)puVar14;
    puVar14 = (undefined4 *)((int)puVar14 + 1);
    puVar16 = (undefined4 *)((int)puVar16 + 1);
  }
  puVar14 = *(undefined4 **)(param_1 + 0x284);
  puVar16 = puVar6;
  for (uVar8 = *(uint *)(param_1 + 0x2c0) & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
    *puVar16 = *puVar14;
    puVar14 = puVar14 + 1;
    puVar16 = puVar16 + 1;
  }
  for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
    *(undefined1 *)puVar16 = *(undefined1 *)puVar14;
    puVar14 = (undefined4 *)((int)puVar14 + 1);
    puVar16 = (undefined4 *)((int)puVar16 + 1);
  }
  puVar14 = *(undefined4 **)(param_2 + 0x284);
  puVar16 = puVar6 + *(int *)(param_1 + 0x2c0);
  for (uVar8 = *(uint *)(param_2 + 0x2c0) & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
    *puVar16 = *puVar14;
    puVar14 = puVar14 + 1;
    puVar16 = puVar16 + 1;
  }
  for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
    *(undefined1 *)puVar16 = *(undefined1 *)puVar14;
    puVar14 = (undefined4 *)((int)puVar14 + 1);
    puVar16 = (undefined4 *)((int)puVar16 + 1);
  }
  puVar14 = *(undefined4 **)(param_1 + 0x288);
  puVar16 = puVar7;
  for (uVar8 = *(uint *)(param_1 + 0x2c0) & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
    *puVar16 = *puVar14;
    puVar14 = puVar14 + 1;
    puVar16 = puVar16 + 1;
  }
  for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
    *(undefined1 *)puVar16 = *(undefined1 *)puVar14;
    puVar14 = (undefined4 *)((int)puVar14 + 1);
    puVar16 = (undefined4 *)((int)puVar16 + 1);
  }
  puVar14 = *(undefined4 **)(param_2 + 0x288);
  puVar16 = puVar7 + *(int *)(param_1 + 0x2c0);
  for (uVar8 = *(uint *)(param_2 + 0x2c0) & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
    *puVar16 = *puVar14;
    puVar14 = puVar14 + 1;
    puVar16 = puVar16 + 1;
  }
  for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
    *(undefined1 *)puVar16 = *(undefined1 *)puVar14;
    puVar14 = (undefined4 *)((int)puVar14 + 1);
    puVar16 = (undefined4 *)((int)puVar16 + 1);
  }
  uVar8 = *(int *)(param_1 + 0x2c4) * 6;
  puVar14 = *(undefined4 **)(param_1 + 0x27c);
  puVar16 = puVar4;
  for (uVar10 = uVar8 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *puVar16 = *puVar14;
    puVar14 = puVar14 + 1;
    puVar16 = puVar16 + 1;
  }
  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined1 *)puVar16 = *(undefined1 *)puVar14;
    puVar14 = (undefined4 *)((int)puVar14 + 1);
    puVar16 = (undefined4 *)((int)puVar16 + 1);
  }
  iVar9 = *(int *)(param_2 + 0x27c);
  iVar11 = 0;
  iVar2 = *(int *)(param_2 + 0x2c4) * 3;
  if (0 < iVar2) {
    psVar12 = (short *)((int)puVar4 + *(int *)(param_1 + 0x2c4) * 6);
    do {
      iVar1 = iVar11 * 2;
      iVar11 = iVar11 + 1;
      *psVar12 = *(short *)(iVar9 + iVar1) + *(short *)(param_1 + 0x2c0);
      psVar12 = psVar12 + 1;
    } while (iVar11 < iVar2);
  }
  FUN_007b9b30();
  *(undefined4 **)(param_1 + 0x278) = puVar3;
  *(undefined4 **)(param_1 + 0x27c) = puVar4;
  *(undefined4 **)(param_1 + 0x284) = puVar6;
  *(undefined4 **)(param_1 + 0x280) = puVar5;
  *(int *)(param_1 + 0x2c4) = iVar15;
  *(undefined4 **)(param_1 + 0x288) = puVar7;
  *(int *)(param_1 + 0x2c0) = iVar13;
  func_0x00774a50(param_2 + 0x290);
  return 1;
}


/* ==================================================================== */
/* Address: 0x007b9880 | Classified: elementclient::A3DLitMesh__LoadTexture____faile@0x7b9880 */
/* ==================================================================== */

undefined4 __fastcall FUN_007b9880(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 uStack_114;
  
  uStack_114 = 0x7b9890;
  FUN_007b99a0();
  uStack_114 = 0;
  pcVar3 = (char *)(param_1 + 0x14);
  cVar1 = func_0x0077c230(pcVar3,param_1 + 0x114,0);
  if (cVar1 == '\0') {
    func_0x007647d0(0x9d2f20,0x98ed58,pcVar3);
    return 0;
  }
  uVar4 = 0xffffffff;
  pcVar5 = pcVar3;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (4 < ~uVar4 - 1) {
    iVar2 = strstr(pcVar3,0x98ed50);
    if (iVar2 != 0) {
      func_0x0076ee80(pcVar3,&uStack_114,0x104);
      iVar2 = param_1 + 0x118;
      sprintf(iVar2,0x98ed38,(int)&uStack_114 + 1);
      cVar1 = func_0x0076f1e0(iVar2);
      if (cVar1 == '\0') {
        pcVar3 = (char *)0x98ed14;
        do {
          cVar1 = *pcVar3;
          pcVar3[param_1 + -0x98ebfc] = cVar1;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
      }
      cVar1 = func_0x0077c230(iVar2,param_1 + 0x218,0,0);
      if (cVar1 == '\0') {
        func_0x007647d0(0x9d2f20,0x98ed58,iVar2);
        return 0;
      }
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007b99a0 | Classified: Angelica3D::proc_7b99a0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007b99a0(int param_1)

{
  if (*(int *)(param_1 + 0x114) != 0) {
    func_0x0077c560((undefined4 *)(param_1 + 0x114));
    *(undefined4 *)(param_1 + 0x114) = 0;
  }
  if (*(int *)(param_1 + 0x218) != 0) {
    func_0x0077c560((undefined4 *)(param_1 + 0x218));
    *(undefined4 *)(param_1 + 0x218) = 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007b9a00 | Classified: Angelica3D::proc_7b9a00 */
/* ==================================================================== */

undefined4 __fastcall FUN_007b9a00(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  FUN_007b9b30();
  uVar1 = func_0x00763250(*(int *)(param_1 + 0x2c0) * 0x24);
  *(undefined4 *)(param_1 + 0x278) = uVar1;
  uVar1 = func_0x00763250(*(int *)(param_1 + 0x2c4) * 6);
  *(undefined4 *)(param_1 + 0x27c) = uVar1;
  uVar1 = func_0x00763250(*(int *)(param_1 + 0x2c0) * 0xc);
  *(undefined4 *)(param_1 + 0x280) = uVar1;
  uVar1 = func_0x00763250(*(int *)(param_1 + 0x2c0) << 2);
  *(undefined4 *)(param_1 + 0x284) = uVar1;
  uVar1 = func_0x00763250(*(int *)(param_1 + 0x2c0) << 2);
  *(undefined4 *)(param_1 + 0x288) = uVar1;
  puVar5 = *(undefined4 **)(param_1 + 0x278);
  for (uVar2 = *(int *)(param_1 + 0x2c0) * 9 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar5 = 0;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  uVar2 = *(int *)(param_1 + 0x2c4) * 6;
  puVar5 = *(undefined4 **)(param_1 + 0x27c);
  for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar5 = 0;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  puVar5 = *(undefined4 **)(param_1 + 0x280);
  for (uVar2 = *(int *)(param_1 + 0x2c0) * 3 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar5 = 0;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  puVar5 = *(undefined4 **)(param_1 + 0x284);
  for (uVar2 = *(uint *)(param_1 + 0x2c0) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar5 = 0;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  puVar5 = *(undefined4 **)(param_1 + 0x288);
  for (uVar2 = *(uint *)(param_1 + 0x2c0) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar5 = 0;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007b9b30 | Classified: Angelica3D::proc_7b9b30 */
/* ==================================================================== */

undefined4 __fastcall FUN_007b9b30(int param_1)

{
  if (*(int *)(param_1 + 0x288) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x288));
    *(undefined4 *)(param_1 + 0x288) = 0;
  }
  if (*(int *)(param_1 + 0x284) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x284));
    *(undefined4 *)(param_1 + 0x284) = 0;
  }
  if (*(int *)(param_1 + 0x280) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x280));
    *(undefined4 *)(param_1 + 0x280) = 0;
  }
  if (*(int *)(param_1 + 0x27c) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x27c));
    *(undefined4 *)(param_1 + 0x27c) = 0;
  }
  if (*(int *)(param_1 + 0x278) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x278));
    *(undefined4 *)(param_1 + 0x278) = 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007b9bc0 | Classified: Angelica3D::proc_7b9bc0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007b9bc0(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iStack_4;
  
  iVar3 = func_0x00892e78();
  iVar5 = 0;
  iVar4 = 0xff - iVar3;
  if (0 < *(int *)(param_1 + 0x2c0)) {
    iStack_4 = 0;
    do {
      uVar1 = *(uint *)(*(int *)(param_1 + 0x284) + iVar5 * 4);
      uVar2 = *(uint *)(*(int *)(param_1 + 0x288) + iVar5 * 4);
      iVar5 = iVar5 + 1;
      *(uint *)(*(int *)(param_1 + 0x278) + 0x18 + iStack_4) =
           (((uVar2 & 0xff00) * iVar3 + (uVar1 & 0xff00) * iVar4 ^
            CONCAT22((short)(uVar2 >> 0x10),(ushort)(byte)uVar2) * iVar3 +
            CONCAT22((short)(uVar1 >> 0x10),(ushort)(byte)uVar1) * iVar4) & 0xff0000 ^
           (uVar2 & 0xff00ff) * iVar3 + (uVar1 & 0xff00ff) * iVar4) >> 8 | 0xff000000;
      iStack_4 = iStack_4 + 0x24;
    } while (iVar5 < *(int *)(param_1 + 0x2c0));
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007b9ca0 | Classified: Angelica3D::proc_7b9ca0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_007b9ca0(int param_1,undefined4 *param_2,short param_3,int param_4)

{
  float fVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_58 [12];
  undefined1 auStack_4c [12];
  undefined4 auStack_40 [16];
  
  fVar1 = *(float *)(*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x164) + 0x94) + 0x2c);
  if (_DAT_008f0ae4 < ABS(fVar1 - *(float *)(param_1 + 0x28c))) {
    *(float *)(param_1 + 0x28c) = fVar1;
    FUN_007b9bc0();
  }
  iVar6 = *(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x2cc) < 0xff) {
    if (*(char *)(iVar6 + 0x40) == '\0') {
      puVar2 = auStack_40;
      iVar7 = 4;
      do {
        iVar3 = 4;
        do {
          *puVar2 = *(undefined4 *)(((iVar6 + 0xb4) - (int)auStack_40) + (int)puVar2);
          puVar2 = puVar2 + 1;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      iVar6 = 0;
      if (0 < *(int *)(param_1 + 0x2c0)) {
        iVar7 = -(int)param_2;
        puVar2 = param_2 + 5;
        do {
          puVar5 = (undefined4 *)
                   func_0x00787290(auStack_58,
                                   (undefined1 *)
                                   ((int)puVar2 + *(int *)(param_1 + 0x278) + iVar7 + -0x14),
                                   auStack_40);
          puVar2[-5] = *puVar5;
          puVar2[-4] = puVar5[1];
          puVar2[-3] = puVar5[2];
          puVar5 = (undefined4 *)
                   func_0x007892c0(auStack_4c,
                                   (undefined1 *)
                                   ((int)puVar2 + *(int *)(param_1 + 0x278) + iVar7 + -8),auStack_40
                                  );
          puVar2[-2] = *puVar5;
          puVar2[-1] = puVar5[1];
          *puVar2 = puVar5[2];
          iVar6 = iVar6 + 1;
          puVar2[1] = *(uint *)((int)puVar2 + *(int *)(param_1 + 0x278) + iVar7 + 4) & 0xffffff |
                      *(int *)(param_1 + 0x2cc) << 0x18;
          puVar2[2] = *(undefined4 *)((int)puVar2 + *(int *)(param_1 + 0x278) + iVar7 + 8);
          puVar2[3] = *(undefined4 *)((int)puVar2 + *(int *)(param_1 + 0x278) + iVar7 + 0xc);
          puVar2 = puVar2 + 9;
        } while (iVar6 < *(int *)(param_1 + 0x2c0));
      }
    }
    else {
      iVar6 = 0;
      if (0 < *(int *)(param_1 + 0x2c0)) {
        iVar7 = -(int)param_2;
        puVar2 = param_2 + 5;
        do {
          puVar5 = (undefined4 *)((int)puVar2 + *(int *)(param_1 + 0x278) + iVar7 + -0x14);
          puVar2[-5] = *puVar5;
          puVar2[-4] = puVar5[1];
          puVar2[-3] = puVar5[2];
          iVar3 = *(int *)(param_1 + 0x278) + iVar7 + -8;
          puVar2[-2] = *(undefined4 *)((int)puVar2 + *(int *)(param_1 + 0x278) + iVar7 + -8);
          puVar2[-1] = *(undefined4 *)((int)puVar2 + iVar3 + 4);
          *puVar2 = *(undefined4 *)((int)puVar2 + iVar3 + 8);
          iVar6 = iVar6 + 1;
          puVar2[1] = *(uint *)((int)puVar2 + *(int *)(param_1 + 0x278) + iVar7 + 4) & 0xffffff |
                      *(int *)(param_1 + 0x2cc) << 0x18;
          puVar2[2] = *(undefined4 *)((int)puVar2 + *(int *)(param_1 + 0x278) + iVar7 + 8);
          puVar2[3] = *(undefined4 *)((int)puVar2 + *(int *)(param_1 + 0x278) + iVar7 + 0xc);
          puVar2 = puVar2 + 9;
        } while (iVar6 < *(int *)(param_1 + 0x2c0));
      }
    }
  }
  else if (*(char *)(iVar6 + 0x40) == '\0') {
    puVar2 = auStack_40;
    iVar7 = 4;
    do {
      iVar3 = 4;
      do {
        *puVar2 = *(undefined4 *)(((iVar6 + 0xb4) - (int)auStack_40) + (int)puVar2);
        puVar2 = puVar2 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    iVar6 = 0;
    if (0 < *(int *)(param_1 + 0x2c0)) {
      iVar7 = -(int)param_2;
      puVar2 = param_2 + 5;
      do {
        puVar5 = (undefined4 *)
                 func_0x00787290(auStack_4c,
                                 (undefined1 *)
                                 ((int)puVar2 + *(int *)(param_1 + 0x278) + iVar7 + -0x14),
                                 auStack_40);
        puVar2[-5] = *puVar5;
        puVar2[-4] = puVar5[1];
        puVar2[-3] = puVar5[2];
        puVar5 = (undefined4 *)
                 func_0x007892c0(auStack_58,
                                 (undefined1 *)
                                 ((int)puVar2 + *(int *)(param_1 + 0x278) + iVar7 + -8),auStack_40);
        puVar2[-2] = *puVar5;
        puVar2[-1] = puVar5[1];
        *puVar2 = puVar5[2];
        iVar6 = iVar6 + 1;
        puVar2[1] = *(undefined4 *)((int)puVar2 + *(int *)(param_1 + 0x278) + iVar7 + 4);
        puVar2[2] = *(undefined4 *)((int)puVar2 + *(int *)(param_1 + 0x278) + iVar7 + 8);
        puVar2[3] = *(undefined4 *)((int)puVar2 + *(int *)(param_1 + 0x278) + iVar7 + 0xc);
        puVar2 = puVar2 + 9;
      } while (iVar6 < *(int *)(param_1 + 0x2c0));
    }
  }
  else {
    puVar2 = *(undefined4 **)(param_1 + 0x278);
    for (uVar4 = *(int *)(param_1 + 0x2c0) * 9 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
      *param_2 = *puVar2;
      puVar2 = puVar2 + 1;
      param_2 = param_2 + 1;
    }
    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined1 *)param_2 = *(undefined1 *)puVar2;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
      param_2 = (undefined4 *)((int)param_2 + 1);
    }
  }
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 0x2c4) * 3) {
    do {
      *(short *)(param_4 + iVar6 * 2) = *(short *)(*(int *)(param_1 + 0x27c) + iVar6 * 2) + param_3;
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(param_1 + 0x2c4) * 3);
  }
  return CONCAT31((int3)((uint)iVar6 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007b9ff0 | Classified: Angelica3D::proc_7b9ff0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007b9ff0(int param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 in_EAX;
  undefined3 uVar5;
  float *pfVar4;
  undefined3 extraout_var;
  
  uVar5 = (undefined3)((uint)in_EAX >> 8);
  if (*(char *)(param_1 + 0x2c8) != '\0') {
    pfVar4 = (float *)func_0x007744f0();
    fVar1 = *pfVar4 - *(float *)(param_1 + 0x290);
    fVar3 = pfVar4[1] - *(float *)(param_1 + 0x294);
    fVar2 = pfVar4[2] - *(float *)(param_1 + 0x298);
    *(float *)(param_1 + 0x274) = SQRT(fVar1 * fVar1 + fVar3 * fVar3 + fVar2 * fVar2);
    FUN_007a8d90(param_2,param_1,0);
    uVar5 = extraout_var;
  }
  return CONCAT31(uVar5,1);
}


/* ==================================================================== */
/* Address: 0x007ba070 | Classified: elementclient::A3DLitMesh__Load____Unknown_vers@0x7ba070 */
/* ==================================================================== */

undefined4 __thiscall FUN_007ba070(int *param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puStack_184;
  undefined4 uStack_180;
  int *piStack_17c;
  int iVar7;
  int iVar8;
  int iVar9;
  int iStack_168;
  int iStack_164;
  undefined4 uStack_160;
  int iStack_15c;
  undefined4 uStack_150;
  undefined1 auStack_14c [60];
  undefined1 auStack_110 [4];
  undefined1 auStack_10c [260];
  undefined4 uStack_8;
  
  puStack_184 = &uStack_150;
  piStack_17c = &iStack_168;
  uStack_180 = 4;
  cVar2 = (**(code **)(*param_3 + 0x10))();
  if (cVar2 == '\0') goto LAB_007baa30;
  if (iStack_15c == 0x10000001) {
    return 0;
  }
  if (iStack_15c == 0x10000002) {
    cVar2 = (**(code **)(*param_3 + 0x10))(auStack_14c,0x40,&stack0xfffffe8c);
    if (cVar2 == '\0') goto LAB_007baa30;
    (**(code **)(*param_1 + 4))(auStack_14c);
    cVar2 = (**(code **)(*param_3 + 0x10))(auStack_110,0x100,&stack0xfffffe88);
    if (((cVar2 == '\0') ||
        (cVar2 = (**(code **)(*param_3 + 0x10))(&uStack_160,4,&stack0xfffffe8c), cVar2 == '\0')) ||
       (cVar2 = (**(code **)(*param_3 + 0x10))(&iStack_168,4,&stack0xfffffe8c), cVar2 == '\0'))
    goto LAB_007baa30;
    cVar2 = FUN_007b94c0(uStack_8,uStack_160,iStack_168,auStack_10c);
    if (cVar2 == '\0') goto LAB_007ba844;
    iVar3 = func_0x00763250(param_1[0xb0] * 0x1c);
    cVar2 = (**(code **)(*param_3 + 0x10))(iVar3,param_1[0xb0] * 0x1c,&puStack_184);
    if (((cVar2 == '\0') ||
        (cVar2 = (**(code **)(*param_3 + 0x10))(param_1[0x9f],param_1[0xb1] * 6,&stack0xfffffe8c),
        cVar2 == '\0')) ||
       (cVar2 = (**(code **)(*param_3 + 0x10))(param_1[0xa0],param_1[0xb0] * 0xc,&stack0xfffffe8c),
       cVar2 == '\0')) goto LAB_007baa30;
    iVar8 = 0;
    if (0 < param_1[0xb0]) {
      iVar7 = 0;
      iVar9 = 0;
      puVar4 = (undefined4 *)(iVar3 + 8);
      do {
        uVar1 = puVar4[-1];
        uStack_150 = *puVar4;
        puVar5 = (undefined4 *)(param_1[0x9e] + iVar9);
        *puVar5 = puVar4[-2];
        puVar5[2] = uStack_150;
        puVar5[1] = uVar1;
        puVar6 = (undefined4 *)(param_1[0xa0] + iVar7);
        puVar5 = (undefined4 *)(iVar9 + 0xc + param_1[0x9e]);
        *puVar5 = *puVar6;
        puVar5[1] = puVar6[1];
        puVar5[2] = puVar6[2];
        *(undefined4 *)(iVar9 + 0x1c + param_1[0x9e]) = puVar4[3];
        *(undefined4 *)(iVar9 + 0x20 + param_1[0x9e]) = puVar4[4];
        *(undefined4 *)(param_1[0xa1] + iVar8 * 4) = *(undefined4 *)(iVar9 + 0x18 + param_1[0x9e]);
        iVar8 = iVar8 + 1;
        *(undefined4 *)(param_1[0xa2] + -4 + iVar8 * 4) =
             *(undefined4 *)(iVar9 + 0x18 + param_1[0x9e]);
        iVar7 = iVar7 + 0xc;
        iVar9 = iVar9 + 0x24;
        puVar4 = puVar4 + 7;
        iVar3 = iStack_164;
      } while (iVar8 < param_1[0xb0]);
    }
LAB_007ba2c3:
    func_0x00763260(iVar3);
    param_1[0xa3] = -0x40800000;
    cVar2 = (**(code **)(*param_3 + 0x10))(param_1 + 0xa4,0x30,&stack0xfffffe8c);
  }
  else {
    if (iStack_15c != 0x10000003) {
      if (iStack_15c != 0x10000004) {
        if (iStack_15c != 0x10000005) {
          func_0x007647d0(0x9d2f20,0x98ed90,iStack_15c);
          return 0;
        }
        cVar2 = (**(code **)(*param_3 + 0x10))(auStack_14c,0x40,&stack0xfffffe8c);
        if (cVar2 != '\0') {
          (**(code **)(*param_1 + 4))(auStack_14c);
          cVar2 = (**(code **)(*param_3 + 0x10))(auStack_110,0x100,&stack0xfffffe88);
          if (((cVar2 != '\0') &&
              (cVar2 = (**(code **)(*param_3 + 0x10))(&uStack_160,4,&stack0xfffffe8c), cVar2 != '\0'
              )) && (cVar2 = (**(code **)(*param_3 + 0x10))(&iStack_164,4,&stack0xfffffe8c),
                    cVar2 != '\0')) {
            cVar2 = FUN_007b94c0(uStack_8,uStack_160,iStack_164,auStack_10c);
            if (cVar2 == '\0') goto LAB_007ba844;
            iVar3 = func_0x00763250(param_1[0xb0] * 0x18);
            cVar2 = (**(code **)(*param_3 + 0x10))(iVar3,param_1[0xb0] * 0x18,&puStack_184);
            if (((cVar2 != '\0') &&
                (cVar2 = (**(code **)(*param_3 + 0x10))
                                   (param_1[0x9f],param_1[0xb1] * 6,&stack0xfffffe8c), cVar2 != '\0'
                )) && ((cVar2 = (**(code **)(*param_3 + 0x10))
                                          (param_1[0xa0],param_1[0xb0] * 0xc,&stack0xfffffe8c),
                       cVar2 != '\0' &&
                       ((cVar2 = (**(code **)(*param_3 + 0x10))
                                           (param_1[0xa1],param_1[0xb0] << 2,&stack0xfffffe8c),
                        cVar2 != '\0' &&
                        (cVar2 = (**(code **)(*param_3 + 0x10))
                                           (param_1[0xa2],param_1[0xb0] << 2,&stack0xfffffe8c),
                        cVar2 != '\0')))))) {
              iVar8 = 0;
              iVar9 = 0;
              if (0 < param_1[0xb0]) {
                iVar7 = 0;
                puVar4 = (undefined4 *)(iVar3 + 8);
                do {
                  puVar5 = (undefined4 *)(param_1[0x9e] + iVar8);
                  *puVar5 = puVar4[-2];
                  puVar5[1] = puVar4[-1];
                  puVar5[2] = *puVar4;
                  *(undefined4 *)(iVar8 + 0x18 + param_1[0x9e]) = puVar4[1];
                  *(undefined4 *)(iVar8 + 0x1c + param_1[0x9e]) = puVar4[2];
                  *(undefined4 *)(iVar8 + 0x20 + param_1[0x9e]) = puVar4[3];
                  puVar6 = (undefined4 *)(param_1[0xa0] + iVar7);
                  puVar5 = (undefined4 *)(iVar8 + 0xc + param_1[0x9e]);
                  iVar8 = iVar8 + 0x24;
                  *puVar5 = *puVar6;
                  puVar5[1] = puVar6[1];
                  puVar5[2] = puVar6[2];
                  iVar7 = iVar7 + 0xc;
                  iVar9 = iVar9 + 1;
                  puVar4 = puVar4 + 6;
                  iVar3 = iStack_168;
                } while (iVar9 < param_1[0xb0]);
              }
              func_0x00763260(iVar3);
              param_1[0xa3] = -0x40800000;
              cVar2 = (**(code **)(*param_3 + 0x10))(param_1 + 0xa4,0x30,&stack0xfffffe8c);
              if ((cVar2 != '\0') && (cVar2 = func_0x007b67b0(uStack_8,param_3), cVar2 != '\0')) {
                return 1;
              }
            }
          }
        }
        goto LAB_007baa30;
      }
      cVar2 = (**(code **)(*param_3 + 0x10))(auStack_14c,0x40,&stack0xfffffe8c);
      if (cVar2 == '\0') goto LAB_007baa30;
      (**(code **)(*param_1 + 4))(auStack_14c);
      cVar2 = (**(code **)(*param_3 + 0x10))(auStack_110,0x100,&stack0xfffffe88);
      if (((cVar2 == '\0') ||
          (cVar2 = (**(code **)(*param_3 + 0x10))(&uStack_160,4,&stack0xfffffe8c), cVar2 == '\0'))
         || (cVar2 = (**(code **)(*param_3 + 0x10))(&iStack_164,4,&stack0xfffffe8c), cVar2 == '\0'))
      goto LAB_007baa30;
      cVar2 = FUN_007b94c0(uStack_8,uStack_160,iStack_164,auStack_10c);
      if (cVar2 == '\0') {
LAB_007ba844:
        func_0x007647d0(0x9d2f20,0x98edec);
        return 0;
      }
      iVar3 = func_0x00763250(param_1[0xb0] * 0x18);
      cVar2 = (**(code **)(*param_3 + 0x10))(iVar3,param_1[0xb0] * 0x18,&puStack_184);
      if (((cVar2 == '\0') ||
          (cVar2 = (**(code **)(*param_3 + 0x10))(param_1[0x9f],param_1[0xb1] * 6,&stack0xfffffe8c),
          cVar2 == '\0')) ||
         ((cVar2 = (**(code **)(*param_3 + 0x10))
                             (param_1[0xa0],param_1[0xb0] * 0xc,&stack0xfffffe8c), cVar2 == '\0' ||
          ((cVar2 = (**(code **)(*param_3 + 0x10))
                              (param_1[0xa1],param_1[0xb0] << 2,&stack0xfffffe8c), cVar2 == '\0' ||
           (cVar2 = (**(code **)(*param_3 + 0x10))
                              (param_1[0xa2],param_1[0xb0] << 2,&stack0xfffffe8c), cVar2 == '\0'))))
         )) goto LAB_007baa30;
      iVar8 = 0;
      iVar9 = 0;
      if (0 < param_1[0xb0]) {
        iVar7 = 0;
        puVar4 = (undefined4 *)(iVar3 + 8);
        do {
          puVar5 = (undefined4 *)(param_1[0x9e] + iVar8);
          *puVar5 = puVar4[-2];
          puVar5[1] = puVar4[-1];
          puVar5[2] = *puVar4;
          *(undefined4 *)(iVar8 + 0x18 + param_1[0x9e]) = puVar4[1];
          *(undefined4 *)(iVar8 + 0x1c + param_1[0x9e]) = puVar4[2];
          *(undefined4 *)(iVar8 + 0x20 + param_1[0x9e]) = puVar4[3];
          puVar6 = (undefined4 *)(param_1[0xa0] + iVar7);
          puVar5 = (undefined4 *)(iVar8 + 0xc + param_1[0x9e]);
          iVar8 = iVar8 + 0x24;
          *puVar5 = *puVar6;
          puVar5[1] = puVar6[1];
          puVar5[2] = puVar6[2];
          iVar7 = iVar7 + 0xc;
          iVar9 = iVar9 + 1;
          puVar4 = puVar4 + 6;
          iVar3 = iStack_168;
        } while (iVar9 < param_1[0xb0]);
      }
      goto LAB_007ba2c3;
    }
    cVar2 = (**(code **)(*param_3 + 0x10))(auStack_14c,0x40,&stack0xfffffe8c);
    if (cVar2 == '\0') goto LAB_007baa30;
    (**(code **)(*param_1 + 4))(auStack_14c);
    cVar2 = (**(code **)(*param_3 + 0x10))(auStack_110,0x100,&stack0xfffffe88);
    if (((cVar2 == '\0') ||
        (cVar2 = (**(code **)(*param_3 + 0x10))(&uStack_160,4,&stack0xfffffe8c), cVar2 == '\0')) ||
       (cVar2 = (**(code **)(*param_3 + 0x10))(&iStack_164,4,&stack0xfffffe8c), cVar2 == '\0'))
    goto LAB_007baa30;
    cVar2 = FUN_007b94c0(uStack_8,uStack_160,iStack_164,auStack_10c);
    if (cVar2 == '\0') goto LAB_007ba844;
    iVar3 = func_0x00763250(param_1[0xb0] * 0x1c);
    cVar2 = (**(code **)(*param_3 + 0x10))(iVar3,param_1[0xb0] * 0x1c,&puStack_184);
    if (((cVar2 == '\0') ||
        (cVar2 = (**(code **)(*param_3 + 0x10))(param_1[0x9f],param_1[0xb1] * 6,&stack0xfffffe8c),
        cVar2 == '\0')) ||
       ((cVar2 = (**(code **)(*param_3 + 0x10))(param_1[0xa0],param_1[0xb0] * 0xc,&stack0xfffffe8c),
        cVar2 == '\0' ||
        ((cVar2 = (**(code **)(*param_3 + 0x10))(param_1[0xa1],param_1[0xb0] << 2,&stack0xfffffe8c),
         cVar2 == '\0' ||
         (cVar2 = (**(code **)(*param_3 + 0x10))(param_1[0xa2],param_1[0xb0] << 2,&stack0xfffffe8c),
         cVar2 == '\0')))))) goto LAB_007baa30;
    iVar8 = 0;
    if (0 < param_1[0xb0]) {
      iVar7 = 0;
      puVar4 = (undefined4 *)(iVar3 + 8);
      iVar9 = 0;
      do {
        uVar1 = puVar4[-1];
        uStack_150 = *puVar4;
        puVar5 = (undefined4 *)(param_1[0x9e] + iVar9);
        *puVar5 = puVar4[-2];
        puVar5[2] = uStack_150;
        puVar5[1] = uVar1;
        puVar6 = (undefined4 *)(param_1[0xa0] + iVar7);
        puVar5 = (undefined4 *)(iVar9 + 0xc + param_1[0x9e]);
        *puVar5 = *puVar6;
        puVar5[1] = puVar6[1];
        puVar5[2] = puVar6[2];
        *(undefined4 *)(iVar9 + 0x1c + param_1[0x9e]) = puVar4[3];
        iVar7 = iVar7 + 0xc;
        *(undefined4 *)(iVar9 + 0x20 + param_1[0x9e]) = puVar4[4];
        iVar8 = iVar8 + 1;
        puVar4 = puVar4 + 7;
        iVar9 = iVar9 + 0x24;
        iVar3 = iStack_168;
      } while (iVar8 < param_1[0xb0]);
    }
    func_0x00763260(iVar3);
    param_1[0xa3] = -0x40800000;
    cVar2 = (**(code **)(*param_3 + 0x10))(param_1 + 0xa4,0x30,&stack0xfffffe8c);
  }
  if (cVar2 != '\0') {
    return 1;
  }
LAB_007baa30:
  func_0x007647d0(0x9d2f20,0x98edbc);
  return 0;
}


/* ==================================================================== */
/* Address: 0x007baa80 | Classified: Angelica3D::proc_7baa80 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_007baa80(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008cdf06;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1[1] = 0;
  param_1[2] = _DAT_009858e4;
  param_1[0x11] = 0x3f800000;
  param_1[0x12] = 0x3f800000;
  param_1[0x13] = 0x3f800000;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0x3f800000;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0x3f800000;
  param_1[0x1c] = 0;
  param_1[0x40] = &UNK_008d5a30;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0x10;
  param_1[0x3f] = &UNK_008f19ac;
  param_1[3] = 0;
  *param_1 = &UNK_008f29b8;
  *(undefined1 *)(param_1 + 0x45) = 1;
  param_1[10] = 0x497423f0;
  param_1[0xb] = 0x497423f0;
  param_1[0xc] = 0x497423f0;
  uStack_4 = 1;
  param_1[0xd] = 0xc97423f0;
  param_1[0xe] = 0xc97423f0;
  param_1[0xf] = 0xc97423f0;
  func_0x00787460();
  func_0x00787460();
  *(undefined1 *)(param_1 + 0x10) = 1;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007bab70 | Classified: Angelica3D::proc_7bab70 */
/* ==================================================================== */

undefined4 __thiscall FUN_007bab70(undefined4 param_1,byte param_2)

{
  FUN_007bab90();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007bab90 | Classified: Angelica3D::proc_7bab90 */
/* ==================================================================== */

void __fastcall FUN_007bab90(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  uint uStack_4;
  
  puStack_8 = &UNK_008cdf26;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f29b8;
  uStack_4 = 1;
  FUN_007bac70();
  param_1[0x3f] = &UNK_008f19ac;
  param_1[0x40] = &UNK_008d5a30;
  uStack_4 = uStack_4 & 0xffffff00;
  if (param_1[0x41] != 0) {
    func_0x00763260(param_1[0x41]);
    param_1[0x41] = 0;
  }
  param_1[0x43] = 0;
  param_1[0x42] = 0;
  uStack_4 = 0xffffffff;
  *param_1 = &UNK_008d6410;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x007bac30 | Classified: Angelica3D::proc_7bac30 */
/* ==================================================================== */

void __thiscall FUN_007bac30(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0x44) = param_2;
  *(undefined4 *)(param_1 + 0x48) = param_3;
  *(undefined4 *)(param_1 + 0x4c) = param_4;
  FUN_007bb0e0();
  return;
}


/* ==================================================================== */
/* Address: 0x007bac50 | Classified: Angelica3D::proc_7bac50 */
/* ==================================================================== */

undefined4 __thiscall FUN_007bac50(int param_1,undefined4 param_2)

{
  FUN_007bac70();
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007bac70 | Classified: Angelica3D::proc_7bac70 */
/* ==================================================================== */

undefined4 __fastcall FUN_007bac70(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = *(int *)(param_1 + 0x108);
  if (0 < iVar1) {
    do {
      puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x104) + iVar3 * 4);
      FUN_007b95e0();
      if (puVar2 != (undefined4 *)0x0) {
        (**(code **)*puVar2)(1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  if (*(int *)(param_1 + 0x104) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x104));
    *(undefined4 *)(param_1 + 0x104) = 0;
  }
  *(undefined4 *)(param_1 + 0x10c) = 0;
  *(undefined4 *)(param_1 + 0x108) = 0;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007bace0 | Classified: Angelica3D::proc_7bace0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007bace0(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  int iStack_4;
  
  cVar2 = (**(code **)(**(int **)(param_2 + 0x30) + 0x10))(param_1 + 0x28,param_1 + 0x34);
  if ((cVar2 != '\0') && (*(char *)(param_1 + 0x114) != '\0')) {
    iVar4 = *(int *)(param_1 + 0x108);
    iVar3 = 0;
    if (0 < iVar4) {
      do {
        iVar1 = *(int *)(*(int *)(param_1 + 0x104) + iVar3 * 4);
        uStack_20 = *(undefined4 *)(iVar1 + 0x2a8);
        uStack_1c = *(undefined4 *)(iVar1 + 0x2ac);
        uStack_18 = *(undefined4 *)(iVar1 + 0x2b0);
        uStack_14 = *(undefined4 *)(iVar1 + 0x2b4);
        uStack_10 = *(undefined4 *)(iVar1 + 0x2b8);
        uStack_c = *(undefined4 *)(iVar1 + 700);
        if ((*(char *)(param_1 + 0x40) == '\0') ||
           (cVar2 = (**(code **)(**(int **)(iStack_4 + 0x30) + 0x10))(&uStack_20,&uStack_14),
           cVar2 != '\0')) {
          FUN_007b9ff0(iStack_4);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar4);
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007badf0 | Classified: Angelica3D::proc_7badf0 */
/* ==================================================================== */

void __thiscall FUN_007badf0(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x114) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x007bae00 | Classified: Angelica3D::proc_7bae00 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_007bae00(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  float10 fVar6;
  int iStack_98;
  int iStack_94;
  undefined4 uStack_90;
  int iStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined1 auStack_80 [4];
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 auStack_70 [2];
  undefined1 auStack_68 [16];
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_3c;
  float fStack_38;
  float afStack_34 [10];
  undefined1 auStack_c [12];
  
  if (*(char *)(param_1 + 0x40) == '\0') {
    iVar4 = *(int *)(param_1 + 0x108);
    iStack_94 = 0;
    iStack_8c = iVar4;
    if (0 < iVar4) {
      do {
        iStack_98 = 0;
        iVar1 = *(int *)(*(int *)(param_1 + 0x104) + iStack_94 * 4);
        fStack_58 = 999999.0;
        fStack_54 = 999999.0;
        fStack_50 = 999999.0;
        fStack_4c = -999999.0;
        fStack_48 = -999999.0;
        fStack_44 = -999999.0;
        if (0 < *(int *)(iVar1 + 0x2c0)) {
          puVar3 = (undefined4 *)(*(int *)(iVar1 + 0x280) + 8);
          puVar5 = (undefined4 *)(*(int *)(iVar1 + 0x278) + 0x14);
          do {
            func_0x00787290(&uStack_7c,puVar5 + -5,param_1 + 0xb4);
            puVar5[-5] = uStack_7c;
            puVar5[-4] = uStack_78;
            puVar5[-3] = uStack_74;
            uStack_90 = func_0x007892c0(auStack_c,puVar3 + -2,param_1 + 0xb4);
            fVar6 = (float10)func_0x0040a5f0();
            if (((float10)_DAT_008f07a8 <= fVar6) || ((float)fVar6 <= (float)_DAT_008f07a0)) {
              func_0x00408020(&uStack_88,uStack_90,(float)fVar6);
            }
            else {
              func_0x0040af10(0);
            }
            puVar3[-2] = iStack_8c;
            puVar3[-1] = uStack_88;
            *puVar3 = uStack_84;
            puVar5[-2] = iStack_8c;
            puVar5[-1] = puVar3[-1];
            *puVar5 = *puVar3;
            func_0x00774a10(auStack_80);
            iStack_98 = iStack_98 + 1;
            puVar3 = puVar3 + 3;
            puVar5 = puVar5 + 9;
            iVar4 = iStack_8c;
          } while (iStack_98 < *(int *)(iVar1 + 0x2c0));
        }
        func_0x00401ca0(fStack_4c + fStack_58,fStack_48 + fStack_54,fStack_44 + fStack_50);
        func_0x00401ca0(fStack_3c * _DAT_008eff98,fStack_38 * _DAT_008eff98,
                        afStack_34[0] * _DAT_008eff98);
        func_0x00401cc0(&fStack_3c);
        uVar2 = func_0x00407220(afStack_34,auStack_68,&iStack_8c);
        func_0x00401cc0(uVar2);
        *(undefined4 *)(iVar1 + 0x290) = uStack_90;
        *(int *)(iVar1 + 0x294) = iStack_8c;
        *(undefined4 *)(iVar1 + 0x298) = uStack_88;
        func_0x00401cc0(&uStack_84);
        func_0x00401cc0(&uStack_7c);
        func_0x00401cc0(&uStack_74);
        iStack_94 = iStack_94 + 1;
      } while (iStack_94 < iVar4);
    }
    puVar3 = (undefined4 *)
             func_0x007873a0(auStack_70,(undefined4 *)(param_1 + 0x74),
                             (undefined4 *)(param_1 + 0xb4));
    puVar5 = (undefined4 *)(param_1 + 0x74);
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
    }
    func_0x00787fa0(auStack_70);
    puVar3 = auStack_70;
    puVar5 = (undefined4 *)(param_1 + 0xb4);
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
    }
    *(undefined1 *)(param_1 + 0x40) = 1;
    return 1;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007bb0e0 | Classified: Angelica3D::proc_7bb0e0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_007bb0e0(int param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  float unaff_EBX;
  float unaff_EBP;
  float *pfVar10;
  undefined4 unaff_ESI;
  float *pfVar11;
  undefined4 unaff_EDI;
  float *pfVar12;
  undefined4 *puStack_188;
  float fStack_174;
  undefined1 auStack_170 [12];
  int iStack_164;
  undefined1 auStack_160 [64];
  undefined4 auStack_120 [16];
  undefined4 auStack_e0 [24];
  undefined1 auStack_80 [64];
  undefined1 auStack_40 [64];
  
  puStack_188 = (undefined4 *)(param_1 + 0x50);
  func_0x00788960(auStack_120,param_1 + 0x5c,param_1 + 0x68);
  puStack_188 = *(undefined4 **)(param_1 + 0x4c);
  func_0x00788ff0(auStack_80,*(undefined4 *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x48));
  func_0x00788570(auStack_160,param_1 + 0x74);
  puStack_188 = auStack_120;
  uVar3 = func_0x007873a0(auStack_40,auStack_160,auStack_80);
  puVar4 = (undefined4 *)func_0x007873a0(auStack_e0,uVar3);
  iStack_164 = *(int *)(param_1 + 0x108);
  puVar5 = (undefined4 *)(param_1 + 0xb4);
  for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  *(undefined4 *)(param_1 + 0x28) = 0x497423f0;
  *(undefined4 *)(param_1 + 0x2c) = 0x497423f0;
  *(undefined4 *)(param_1 + 0x30) = 0x497423f0;
  *(undefined4 *)(param_1 + 0x34) = 0xc97423f0;
  *(undefined4 *)(param_1 + 0x38) = 0xc97423f0;
  *(undefined4 *)(param_1 + 0x3c) = 0xc97423f0;
  fStack_174 = 0.0;
  if (0 < iStack_164) {
    do {
      puStack_188 = (undefined4 *)0x0;
      func_0x00774c20(auStack_e0,0);
      puVar4 = auStack_e0;
      iVar7 = 8;
      do {
        puStack_188 = (undefined4 *)(param_1 + 0xb4);
        puVar5 = (undefined4 *)func_0x00787290(auStack_170,puVar4);
        *puVar4 = *puVar5;
        puVar4[1] = puVar5[1];
        puVar4[2] = puVar5[2];
        puStack_188 = puVar4;
        func_0x00774a10();
        puVar4 = puVar4 + 3;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      fStack_174 = (float)((int)fStack_174 + 1);
    } while ((int)fStack_174 < iStack_164);
  }
  puStack_188 = (undefined4 *)(*(float *)(param_1 + 0x30) + *(float *)(param_1 + 0x3c));
  func_0x00401ca0(*(float *)(param_1 + 0x34) + *(float *)(param_1 + 0x28),
                  *(float *)(param_1 + 0x2c) + *(float *)(param_1 + 0x38));
  func_0x00401ca0(unaff_EBP * _DAT_008eff98,unaff_EBX * _DAT_008eff98,fStack_174 * _DAT_008eff98);
  *(float *)(param_1 + 0x10) = (float)puStack_188;
  *(undefined4 *)(param_1 + 0x14) = unaff_EDI;
  *(undefined4 *)(param_1 + 0x18) = unaff_ESI;
  uVar3 = func_0x00407220(&puStack_188,(float *)(param_1 + 0x34),(float *)(param_1 + 0x10));
  func_0x00401cc0(uVar3);
  iVar6 = func_0x00787fa0(&stack0xfffffe84);
  pfVar12 = (float *)&stack0xfffffe84;
  pfVar10 = (float *)(param_1 + 0xb4);
  iVar7 = 0;
  do {
    iVar8 = 0;
    pfVar9 = pfVar10;
    pfVar11 = pfVar12;
    do {
      fVar1 = *pfVar9;
      fVar2 = *pfVar11;
      iVar6 = CONCAT22((short)((uint)iVar6 >> 0x10),
                       (ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                       (ushort)(fVar1 == fVar2) << 0xe);
      if (fVar1 != fVar2) {
        *(undefined1 *)(param_1 + 0x40) = 0;
        return CONCAT31((int3)((uint)iVar6 >> 8),1);
      }
      iVar8 = iVar8 + 1;
      pfVar9 = pfVar9 + 1;
      pfVar11 = pfVar11 + 1;
    } while (iVar8 < 4);
    pfVar12 = pfVar12 + 4;
    iVar6 = iVar7 + 1;
    pfVar10 = pfVar10 + 4;
    iVar7 = iVar6;
  } while (iVar6 < 4);
  *(undefined1 *)(param_1 + 0x40) = 1;
  return CONCAT31((int3)((uint)iVar6 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007bb320 | Classified: Angelica3D::proc_7bb320 */
/* ==================================================================== */

void __thiscall FUN_007bb320(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x50) = *param_2;
  *(undefined4 *)(param_1 + 0x54) = param_2[1];
  *(undefined4 *)(param_1 + 0x58) = param_2[2];
  FUN_007bb0e0();
  return;
}


/* ==================================================================== */
/* Address: 0x007bb340 | Classified: Angelica3D::proc_7bb340 */
/* ==================================================================== */

void __thiscall FUN_007bb340(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  *(undefined4 *)(param_1 + 0x5c) = *param_2;
  *(undefined4 *)(param_1 + 0x60) = param_2[1];
  *(undefined4 *)(param_1 + 100) = param_2[2];
  *(undefined4 *)(param_1 + 0x68) = *param_3;
  *(undefined4 *)(param_1 + 0x6c) = param_3[1];
  *(undefined4 *)(param_1 + 0x70) = param_3[2];
  FUN_007bb0e0();
  return;
}


/* ==================================================================== */
/* Address: 0x007bb380 | Classified: elementclient::A3DLitModel__Load____Wrong_versi@0x7bb380 */
/* ==================================================================== */

undefined4 __thiscall FUN_007bb380(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int unaff_EBX;
  int unaff_EBP;
  int iVar5;
  int unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar6;
  int iVar7;
  undefined1 auStack_18 [4];
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  int *piStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  piStack_8 = (int *)&UNK_008cdf46;
  *unaff_FS_OFFSET = &uStack_c;
  cVar1 = FUN_007bac50(param_2);
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(*param_2 + 0x10))(auStack_18,4,&stack0xffffffdc);
    if (cVar1 == '\0') {
LAB_007bb5fa:
      uVar6 = 0x98ee44;
    }
    else {
      if (unaff_EBX == 0x10000001) {
        cVar1 = (**(code **)(*param_2 + 0x10))(param_1 + 0x44,0xc,&stack0xffffffd0);
        if ((((cVar1 != '\0') &&
             (cVar1 = (**(code **)(*param_2 + 0x10))(param_1 + 0x5c,0xc,&stack0xffffffd0),
             cVar1 != '\0')) &&
            (cVar1 = (**(code **)(*param_2 + 0x10))(param_1 + 0x68,0xc,&stack0xffffffd0),
            cVar1 != '\0')) &&
           ((cVar1 = (**(code **)(*param_2 + 0x10))(param_1 + 0x50,0xc,&stack0xffffffd0),
            cVar1 != '\0' &&
            (cVar1 = (**(code **)(*param_2 + 0x10))(&stack0xffffffd8,4,&stack0xffffffd0),
            cVar1 != '\0')))) {
          iVar7 = 0;
          if (0 < unaff_EBP) {
            do {
              iVar2 = func_0x00763250(0x2d0);
              iVar5 = 0;
              uStack_14 = 0;
              if (iVar2 == 0) {
                puVar3 = (undefined4 *)0x0;
              }
              else {
                puVar3 = (undefined4 *)func_0x007b9360(param_1);
              }
              uStack_14 = 0xffffffff;
              FUN_007ba070(uStack_c,param_2);
              if (0 < *(int *)(param_1 + 0x108)) {
                do {
                  iVar2 = *(int *)(*(int *)(param_1 + 0x104) + iVar5 * 4);
                  if (((puVar3[0x45] == *(int *)(iVar2 + 0x114)) &&
                      (iVar2 = iVar2 + 0x21c, iVar2 != 0)) &&
                     (cVar1 = func_0x007b64a0(puVar3 + 0x87,iVar2), param_2 = piStack_8,
                     cVar1 != '\0')) break;
                  iVar5 = iVar5 + 1;
                } while (iVar5 < *(int *)(param_1 + 0x108));
              }
              if (iVar5 == *(int *)(param_1 + 0x108)) {
                if (*(int *)(param_1 + 0x10c) <= *(int *)(param_1 + 0x108)) {
                  func_0x0068e120(*(undefined4 *)(param_1 + 0x110));
                }
                *(undefined4 **)(*(int *)(param_1 + 0x104) + *(int *)(param_1 + 0x108) * 4) = puVar3
                ;
                *(int *)(param_1 + 0x108) = *(int *)(param_1 + 0x108) + 1;
              }
              else {
                FUN_007b9600(puVar3);
                FUN_007b95e0();
                if (puVar3 != (undefined4 *)0x0) {
                  (**(code **)*puVar3)(1);
                }
              }
              iVar7 = iVar7 + 1;
            } while (iVar7 < unaff_EBP);
            FUN_007bb0e0();
            uVar6 = 1;
            goto LAB_007bb7b2;
          }
LAB_007bb793:
          FUN_007bb0e0();
          uVar6 = 1;
          goto LAB_007bb7b2;
        }
        goto LAB_007bb5fa;
      }
      if (unaff_EBX == 0x10000002) {
        cVar1 = (**(code **)(*param_2 + 0x10))(param_1 + 0x44,0xc,&stack0xffffffd0);
        if ((((cVar1 != '\0') &&
             (cVar1 = (**(code **)(*param_2 + 0x10))(param_1 + 0x5c,0xc,&stack0xffffffd0),
             cVar1 != '\0')) &&
            (cVar1 = (**(code **)(*param_2 + 0x10))(param_1 + 0x68,0xc,&stack0xffffffd0),
            cVar1 != '\0')) &&
           ((cVar1 = (**(code **)(*param_2 + 0x10))(param_1 + 0x50,0xc,&stack0xffffffd0),
            cVar1 != '\0' &&
            (cVar1 = (**(code **)(*param_2 + 0x10))(&stack0xffffffd4,4,&stack0xffffffd0),
            cVar1 != '\0')))) {
          iVar7 = 0;
          if (0 < unaff_ESI) {
            do {
              iVar2 = func_0x00763250(0x2d0);
              uStack_14 = 1;
              if (iVar2 == 0) {
                puVar3 = (undefined4 *)0x0;
              }
              else {
                puVar3 = (undefined4 *)func_0x007b9360(param_1);
              }
              uStack_14 = 0xffffffff;
              FUN_007ba070(uStack_c,param_2);
              iVar2 = 0;
              if (0 < *(int *)(param_1 + 0x108)) {
                do {
                  iVar5 = *(int *)(*(int *)(param_1 + 0x104) + iVar2 * 4);
                  if (((puVar3[0x45] == *(int *)(iVar5 + 0x114)) &&
                      (iVar5 = iVar5 + 0x21c, iVar5 != 0)) &&
                     (cVar1 = func_0x007b64a0(puVar3 + 0x87,iVar5), param_2 = piStack_8,
                     cVar1 != '\0')) break;
                  iVar2 = iVar2 + 1;
                } while (iVar2 < *(int *)(param_1 + 0x108));
              }
              if (iVar2 == *(int *)(param_1 + 0x108)) {
                if ((*(int *)(param_1 + 0x10c) <= *(int *)(param_1 + 0x108)) &&
                   (param_2 = piStack_8, *(int *)(param_1 + 0x110) != 0)) {
                  iVar5 = *(int *)(param_1 + 0x110) + *(int *)(param_1 + 0x10c);
                  iVar2 = func_0x00763250(iVar5 * 4);
                  if (iVar2 == 0) {
                    func_0x00764590(1,0x94e51c);
                    param_2 = piStack_8;
                  }
                  else {
                    iVar4 = 0;
                    if (0 < *(int *)(param_1 + 0x108)) {
                      do {
                        iVar4 = iVar4 + 1;
                        *(undefined4 *)(iVar2 + -4 + iVar4 * 4) =
                             *(undefined4 *)(*(int *)(param_1 + 0x104) + -4 + iVar4 * 4);
                      } while (iVar4 < *(int *)(param_1 + 0x108));
                    }
                    if (*(int *)(param_1 + 0x104) != 0) {
                      func_0x00763260(*(int *)(param_1 + 0x104));
                    }
                    *(int *)(param_1 + 0x104) = iVar2;
                    *(int *)(param_1 + 0x10c) = iVar5;
                    param_2 = piStack_8;
                  }
                }
                *(undefined4 **)(*(int *)(param_1 + 0x104) + *(int *)(param_1 + 0x108) * 4) = puVar3
                ;
                *(int *)(param_1 + 0x108) = *(int *)(param_1 + 0x108) + 1;
              }
              else {
                FUN_007b9600(puVar3);
                FUN_007b95e0();
                if (puVar3 != (undefined4 *)0x0) {
                  (**(code **)*puVar3)(1);
                }
              }
              iVar7 = iVar7 + 1;
            } while (iVar7 < unaff_ESI);
          }
          goto LAB_007bb793;
        }
        goto LAB_007bb5fa;
      }
      uVar6 = 0x98ee20;
    }
    func_0x007647d0(0x9d2f20,uVar6);
  }
  uVar6 = 0;
LAB_007bb7b2:
  *unaff_FS_OFFSET = uStack_10;
  return uVar6;
}


/* ==================================================================== */
/* Address: 0x007bb7d0 | Classified: elementclient::A3DLitModel__LoadFromMox____fail@0x7bb7d0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007bb7d0(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint *unaff_FS_OFFSET;
  undefined4 uVar5;
  uint uStack_10;
  uint uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cdf69;
  *unaff_FS_OFFSET = (uint)&uStack_c;
  cVar1 = FUN_007bac50(param_2);
  if (cVar1 != '\0') {
    func_0x0076d760();
    uVar5 = 0x11;
    puStack_8 = (undefined *)0x0;
    uVar4 = param_2;
    cVar1 = func_0x0076da20(param_2,0x11);
    if (cVar1 == '\0') {
      func_0x007647d0(0x9d2f20,0x98eeb0,param_2);
    }
    else {
      iVar2 = func_0x00763250(0xb4);
      if (iVar2 == 0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = (int *)FUN_007bbe40(uVar4,uVar5,iVar2);
      }
      uStack_10 = uStack_10 & 0xffffff00;
      cVar1 = func_0x007bc6d0(*(undefined4 *)(param_1 + 0xc),&stack0xfffffdb8);
      if (cVar1 != '\0') {
        func_0x0076db10();
        FUN_007bb910(piVar3);
        (**(code **)(*piVar3 + 0x2c))();
        (**(code **)*piVar3)(1);
        func_0x0076db10();
        FUN_007bb0e0();
        func_0x0076d7c0();
        uVar4 = 1;
        goto LAB_007bb8f7;
      }
      func_0x007647d0(0x9d2f20,0x98ee78);
    }
    uStack_10 = 0xffffffff;
    func_0x0076d7c0();
  }
  uVar4 = 0;
LAB_007bb8f7:
  *unaff_FS_OFFSET = uStack_10;
  return uVar4;
}


/* ==================================================================== */
/* Address: 0x007bb910 | Classified: elementclient::_s__d@0x7bb910 */
/* ==================================================================== */

undefined4 __fastcall FUN_007bb910(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  undefined4 unaff_EBX;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *unaff_ESI;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *unaff_EDI;
  undefined4 *puVar13;
  int iStack_148;
  int iStack_130;
  undefined4 uStack_12c;
  int iStack_124;
  int iStack_120;
  int iStack_114;
  undefined4 uStack_110;
  int iStack_10c;
  undefined4 uStack_108;
  int iStack_104;
  undefined4 uStack_100;
  undefined4 *puStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined1 auStack_dc [4];
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float afStack_c4 [4];
  undefined1 auStack_b4 [24];
  undefined1 auStack_9c [28];
  undefined4 auStack_80 [13];
  undefined1 auStack_4c [68];
  int iStack_8;
  
  iVar2 = func_0x007bc280();
  iVar3 = func_0x007bc2c0();
  iStack_130 = 4;
  puVar6 = auStack_80;
  do {
    iVar8 = 4;
    do {
      *puVar6 = *(undefined4 *)((iVar3 - (int)auStack_80) + (int)puVar6);
      puVar6 = puVar6 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    iStack_130 = iStack_130 + -1;
  } while (iStack_130 != 0);
  while (iVar2 != 0) {
    puVar13 = (undefined4 *)(*(int *)(iVar2 + 0x28) / 3);
    iVar8 = *(int *)(iVar2 + 0x24);
    iVar3 = iVar2 + 0xf1;
    iStack_104 = iVar8;
    puStack_fc = puVar13;
    piVar4 = (int *)FUN_007bbcf0(iVar8);
    iVar1 = piVar4[0xa1];
    iStack_114 = piVar4[0x9e];
    iStack_10c = piVar4[0xa0];
    puVar6 = (undefined4 *)piVar4[0x9f];
    if (unaff_ESI == (undefined4 *)0x0) {
      strncpy(auStack_4c,*(undefined4 *)(iStack_8 + 8),0x40);
    }
    else {
      sprintf(auStack_4c,0x98eee8,*(undefined4 *)(iStack_8 + 8),unaff_ESI);
    }
    (**(code **)(*piVar4 + 4))(auStack_4c);
    fStack_cc = 999999.0;
    fStack_c8 = 999999.0;
    afStack_c4[0] = 999999.0;
    func_0x005ca8a0(0xc97423f0,0xc97423f0,0xc97423f0);
    puVar12 = puVar13;
    if (0 < iVar8) {
      unaff_EDI = (undefined4 *)((int)unaff_EDI - (int)puVar13);
      puVar11 = (undefined4 *)(iStack_124 + 0x14);
      iStack_148 = iStack_120;
      puVar9 = (undefined4 *)(param_1 + 8);
      puVar10 = (undefined4 *)(**(int **)(iVar2 + 0x14) + 8);
      iVar2 = iVar3;
      do {
        puStack_fc = (undefined4 *)puVar10[-2];
        uStack_f8 = puVar10[-1];
        uStack_f4 = *puVar10;
        func_0x00787290(&iStack_114,&puStack_fc,auStack_9c);
        uStack_108 = puVar10[1];
        iStack_104 = puVar10[2];
        uStack_100 = puVar10[3];
        func_0x007892c0(&stack0xfffffecc,&uStack_108,auStack_9c);
        func_0x00774a10(&iStack_114);
        puVar11[-5] = iStack_114;
        puVar11[-4] = uStack_110;
        puVar11[-3] = iStack_10c;
        puVar11[-2] = unaff_EBX;
        puVar11[-1] = iVar1;
        *puVar11 = uStack_12c;
        puVar11[1] = 0xff808080;
        puVar11[2] = puVar10[4];
        puVar11[3] = puVar10[5];
        puVar11 = puVar11 + 9;
        *(undefined4 *)((int)puVar13 + (int)unaff_EDI) = 0xff808080;
        *puVar13 = 0xff808080;
        puVar9[-2] = unaff_EBX;
        puVar13 = puVar13 + 1;
        puVar9[-1] = iVar1;
        *puVar9 = uStack_12c;
        iStack_148 = iStack_148 + -1;
        puVar9 = puVar9 + 3;
        puVar10 = puVar10 + 8;
        puVar12 = puVar6;
        unaff_ESI = puVar13;
      } while (iStack_148 != 0);
    }
    func_0x00401ca0(fStack_cc + fStack_d8,fStack_c8 + fStack_d4,afStack_c4[0] + fStack_d0);
    uVar5 = func_0x00401ce0(auStack_b4,&fStack_cc,0x3f000000);
    func_0x00401cc0(uVar5);
    uVar5 = func_0x00407220(afStack_c4,auStack_dc,&uStack_100);
    func_0x00401cc0(uVar5);
    func_0x004072f0(&iStack_104);
    piVar4[0x96] = *(int *)(iVar2 + 0x74);
    piVar4[0x97] = *(int *)(iVar2 + 0x78);
    piVar4[0x98] = *(int *)(iVar2 + 0x7c);
    piVar4[0x99] = *(int *)(iVar2 + 0x80);
    if (*(char *)(iVar2 + 0x88) != '\0') {
      *(undefined1 *)(piVar4 + 0x9b) = 1;
    }
    puVar6 = *(undefined4 **)(iVar2 + 0x18);
    puVar13 = unaff_EDI;
    for (uVar7 = (uint)((int)puVar12 * 6) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar13 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar13 = puVar13 + 1;
    }
    for (uVar7 = (int)puVar12 * 6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined1 *)puVar13 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      puVar13 = (undefined4 *)((int)puVar13 + 1);
    }
    iVar2 = func_0x007bc2a0();
  }
  iVar2 = FUN_007bc1c0();
  while (iVar2 != 0) {
    FUN_007bb910(iVar2);
    iVar2 = FUN_007bc1e0();
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007bbcf0 | Classified: elementclient::AArray__Allocate__Not_enough_mem@0x7bbcf0 */
/* ==================================================================== */

undefined4 * __thiscall
FUN_007bbcf0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cdf8b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar2 = func_0x00763250(0x2d0);
  uStack_4 = 0;
  if (iVar2 == 0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)func_0x007b9360(param_1);
  }
  uStack_4 = 0xffffffff;
  cVar1 = FUN_007b94c0(*(undefined4 *)(param_1 + 0xc),param_2,param_3);
  if (cVar1 == '\0') {
    if (puVar3 != (undefined4 *)0x0) {
      (**(code **)*puVar3)(1);
    }
    *unaff_FS_OFFSET = param_4;
    return (undefined4 *)0x0;
  }
  if ((*(int *)(param_1 + 0x10c) <= *(int *)(param_1 + 0x108)) && (*(int *)(param_1 + 0x110) != 0))
  {
    iVar5 = *(int *)(param_1 + 0x110) + *(int *)(param_1 + 0x10c);
    iVar2 = func_0x00763250(iVar5 * 4);
    if (iVar2 == 0) {
      func_0x00764590(1,0x94e51c);
    }
    else {
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x108)) {
        do {
          iVar4 = iVar4 + 1;
          *(undefined4 *)(iVar2 + -4 + iVar4 * 4) =
               *(undefined4 *)(*(int *)(param_1 + 0x104) + -4 + iVar4 * 4);
        } while (iVar4 < *(int *)(param_1 + 0x108));
      }
      if (*(int *)(param_1 + 0x104) != 0) {
        func_0x00763260(*(int *)(param_1 + 0x104));
      }
      *(int *)(param_1 + 0x104) = iVar2;
      *(int *)(param_1 + 0x10c) = iVar5;
    }
  }
  *(undefined4 **)(*(int *)(param_1 + 0x104) + *(int *)(param_1 + 0x108) * 4) = puVar3;
  *(int *)(param_1 + 0x108) = *(int *)(param_1 + 0x108) + 1;
  *unaff_FS_OFFSET = param_4;
  return puVar3;
}


/* ==================================================================== */
/* Address: 0x007bbe40 | Classified: Angelica3D::proc_7bbe40 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_007bbe40(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008cdfb3;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1[1] = 0;
  param_1[2] = _DAT_009858e4;
  *param_1 = &UNK_008d6410;
  uStack_4 = 0;
  func_0x007ced50();
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  func_0x007ced50();
  *param_1 = &UNK_008f2a30;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[0xd] = 0;
  param_1[0x25] = 0;
  param_1[0x24] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  *(undefined1 *)(param_1 + 0x2c) = 0;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007bbf00 | Classified: Angelica3D::proc_7bbf00 */
/* ==================================================================== */

undefined4 __thiscall FUN_007bbf00(undefined4 param_1,byte param_2)

{
  FUN_007bbf20();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007bbf20 | Classified: Angelica3D::proc_7bbf20 */
/* ==================================================================== */

void __fastcall FUN_007bbf20(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  uint uStack_4;
  
  puStack_8 = &UNK_008cdfd3;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f2a30;
  uStack_4 = 1;
  func_0x00430860();
  uStack_4 = uStack_4 & 0xffffff00;
  func_0x00430860();
  uStack_4 = 0xffffffff;
  *param_1 = &UNK_008d6410;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x007bbf90 | Classified: Angelica3D::proc_7bbf90 */
/* ==================================================================== */

undefined1 __thiscall FUN_007bbf90(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  
  cVar1 = func_0x007ced60();
  if (cVar1 == '\0') {
    return 0;
  }
  cVar1 = func_0x007ced60();
  if (cVar1 == '\0') {
    return 0;
  }
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(int *)(param_1 + 0x84) = param_3;
  *(int *)(param_1 + 0x80) = param_3;
  puVar2 = (undefined4 *)func_0x007631a0(param_3 << 6);
  *(undefined4 **)(param_1 + 0x34) = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    return 0;
  }
  for (iVar3 = (*(uint *)(param_1 + 0x84) & 0x3ffffff) << 4; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar2 = 0;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  func_0x00787460();
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007bc040 | Classified: Angelica3D::proc_7bc040 */
/* ==================================================================== */

undefined4 __fastcall FUN_007bc040(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (*(char *)(param_1 + 0xb0) == '\0') {
    if (*(int *)(param_1 + 0x94) != 0) {
      func_0x007631b0(*(int *)(param_1 + 0x94));
      *(undefined4 *)(param_1 + 0x94) = 0;
    }
    if (*(int *)(param_1 + 0x90) != 0) {
      func_0x007631b0(*(int *)(param_1 + 0x90));
      *(undefined4 *)(param_1 + 0x90) = 0;
    }
    if (*(int *)(param_1 + 0x34) != 0) {
      func_0x007631b0(*(int *)(param_1 + 0x34));
      *(undefined4 *)(param_1 + 0x34) = 0;
    }
    if (*(int *)(param_1 + 0x9c) != 0) {
      func_0x007631b0(*(int *)(param_1 + 0x9c));
      *(undefined4 *)(param_1 + 0x9c) = 0;
    }
    piVar2 = *(int **)(*(int *)(param_1 + 0x20) + 4);
    if (piVar2 != *(int **)(param_1 + 0x24)) {
      do {
        puVar1 = (undefined4 *)*piVar2;
        func_0x007be890();
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
        }
        piVar2 = (int *)piVar2[1];
      } while (piVar2 != *(int **)(param_1 + 0x24));
    }
  }
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x14) + 4);
  if (puVar1 != *(undefined4 **)(param_1 + 0x18)) {
    do {
      piVar2 = (int *)*puVar1;
      (**(code **)(*piVar2 + 0x2c))();
      (**(code **)*piVar2)(1);
      puVar1 = (undefined4 *)puVar1[1];
    } while (puVar1 != *(undefined4 **)(param_1 + 0x18));
  }
  func_0x007cedd0();
  func_0x007cedd0();
  return 1;
}


/* ==================================================================== */
/* Address: 0x007bc130 | Classified: Angelica3D::proc_7bc130 */
/* ==================================================================== */

undefined4 __thiscall FUN_007bc130(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = func_0x007cee10(param_2,0);
  if ((char)uVar1 == '\0') {
    return uVar1;
  }
  *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + *(int *)(param_2 + 0x78);
  *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + *(int *)(param_2 + 0x7c);
  iVar2 = *(int *)(param_1 + 0xa0) + *(int *)(param_2 + 0xa0);
  *(int *)(param_1 + 0xa0) = iVar2;
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007bc180 | Classified: Angelica3D::proc_7bc180 */
/* ==================================================================== */

undefined4 __thiscall FUN_007bc180(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = func_0x007cee10(param_2,0);
  if ((char)uVar1 == '\0') {
    return uVar1;
  }
  *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + *(int *)(param_2 + 0x24);
  iVar2 = *(int *)(param_1 + 0x7c) + *(int *)(param_2 + 0x28);
  *(int *)(param_1 + 0x7c) = iVar2;
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007bc1c0 | Classified: Angelica3D::proc_7bc1c0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007bc1c0(int param_1)

{
  undefined4 *puVar1;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    return 0;
  }
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x14) + 4);
  *(undefined4 **)(param_1 + 0x2c) = puVar1;
  return *puVar1;
}


/* ==================================================================== */
/* Address: 0x007bc1e0 | Classified: Angelica3D::proc_7bc1e0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007bc1e0(int param_1)

{
  undefined4 *puVar1;
  
  if (*(int *)(param_1 + 0x2c) != 0) {
    puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x2c) + 4);
    *(undefined4 **)(param_1 + 0x2c) = puVar1;
    if (*(undefined4 **)(param_1 + 0x18) != puVar1) {
      return *puVar1;
    }
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x007bc200 | Classified: Angelica3D::proc_7bc200 */
/* ==================================================================== */

undefined4 __thiscall FUN_007bc200(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = *(int **)(*(int *)(param_1 + 0x14) + 4);
  if (piVar4 != *(int **)(param_1 + 0x18)) {
    do {
      iVar1 = *piVar4;
      iVar3 = _stricmp(param_2,*(undefined4 *)(iVar1 + 8));
      if (iVar3 == 0) {
        *param_3 = iVar1;
        return 1;
      }
      cVar2 = FUN_007bc200(param_2,param_3);
      if (cVar2 != '\0') {
        return 1;
      }
      piVar4 = (int *)piVar4[1];
    } while (piVar4 != *(int **)(param_1 + 0x18));
  }
  *param_3 = 0;
  return 0;
}


