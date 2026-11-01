/* Authentic Ghidra 12.1.4 Decompilation — elementclient.exe (PW 1.4.2 Build 2305) */
/* Module: 17_a3dskinrender_litmodelrender.c */

/* ==================================================================== */
/* Address: 0x007a4c20 | Classified: Angelica3D::proc_7a4c20 */
/* ==================================================================== */

undefined4 * __fastcall FUN_007a4c20(undefined4 *param_1)

{
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008cd576;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1[5] = &UNK_008d5a30;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0x10;
  param_1[4] = &UNK_008f192c;
  uStack_4 = 0;
  param_1[0xb] = &UNK_008d5a30;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 200;
  func_0x0068e120(0);
  param_1[10] = &UNK_008f1928;
  puStack_8 = (undefined *)CONCAT31(puStack_8._1_3_,1);
  param_1[0x11] = &UNK_008d5a30;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 200;
  func_0x0068e120(0);
  param_1[0x10] = &UNK_008f1928;
  param_1[0x17] = &UNK_008d649c;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 10;
  param_1[0x1d] = 0;
  param_1[0x16] = &UNK_008f1924;
  param_1[0x22] = 0x3f800000;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0x443f40a4;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  *param_1 = &UNK_008f1920;
  param_1[0x21] = 4;
  *unaff_FS_OFFSET = unaff_ESI;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007a4d30 | Classified: Angelica3D::proc_7a4d30 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a4d30(undefined4 param_1,byte param_2)

{
  FUN_007a4d50();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007a4d50 | Classified: Angelica3D::proc_7a4d50 */
/* ==================================================================== */

void __fastcall FUN_007a4d50(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  puStack_8 = &UNK_008cd5a1;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f1920;
  param_1[0x16] = &UNK_008f1924;
  puVar1 = (undefined4 *)param_1[0x18];
  iStack_4 = 2;
  param_1[0x17] = &UNK_008d649c;
  while (puVar1 != (undefined4 *)0x0) {
    param_1[0x18] = *puVar1;
    *puVar1 = param_1[0x1a];
    param_1[0x1a] = puVar1;
    puVar1 = (undefined4 *)param_1[0x18];
    param_1[0x1b] = param_1[0x1b] + -1;
  }
  puVar1 = (undefined4 *)param_1[0x1d];
  param_1[0x19] = 0;
  param_1[0x1b] = 0;
  while (puVar1 != (undefined4 *)0x0) {
    param_1[0x1d] = puVar1[1];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    puVar1 = (undefined4 *)param_1[0x1d];
  }
  param_1[0x10] = &UNK_008f1928;
  iStack_4._1_3_ = (uint3)((uint)iStack_4 >> 8);
  iStack_4._0_1_ = 1;
  param_1[0x11] = &UNK_008d5a30;
  if (param_1[0x12] != 0) {
    func_0x00763260(param_1[0x12]);
    param_1[0x12] = 0;
  }
  param_1[0x14] = 0;
  param_1[0x13] = 0;
  param_1[10] = &UNK_008f1928;
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  param_1[0xb] = &UNK_008d5a30;
  if (param_1[0xc] != 0) {
    func_0x00763260(param_1[0xc]);
    param_1[0xc] = 0;
  }
  param_1[0xe] = 0;
  param_1[0xd] = 0;
  param_1[4] = &UNK_008f192c;
  iStack_4 = 0xffffffff;
  param_1[5] = &UNK_008d5a30;
  if (param_1[6] != 0) {
    func_0x00763260(param_1[6]);
    param_1[6] = 0;
  }
  param_1[8] = 0;
  param_1[7] = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x007a4e70 | Classified: Angelica3D::proc_7a4e70 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a4e70(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 0x50);
  uVar1 = *(undefined4 *)(param_2 + 0x88);
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  return CONCAT31((int3)((uint)uVar1 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007a4e90 | Classified: Angelica3D::proc_7a4e90 */
/* ==================================================================== */

void __fastcall FUN_007a4e90(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x1c)) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x18) + iVar2 * 4);
      if (iVar1 != 0) {
        FUN_007a4f70();
        func_0x00763260(iVar1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x1c));
  }
  if (*(int *)(param_1 + 0x18) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x34)) {
    do {
      func_0x00763260(*(undefined4 *)(*(int *)(param_1 + 0x30) + iVar2 * 4));
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x34));
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x30));
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x4c)) {
    do {
      func_0x00763260(*(undefined4 *)(*(int *)(param_1 + 0x48) + iVar2 * 4));
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x4c));
  }
  if (*(int *)(param_1 + 0x48) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x48));
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007a4f70 | Classified: Angelica3D::proc_7a4f70 */
/* ==================================================================== */

void __fastcall FUN_007a4f70(int param_1)

{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  uint uStack_4;
  
  puStack_8 = &UNK_008cd5ea;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined **)(param_1 + 0xa4) = &UNK_008f1924;
  uStack_4 = 4;
  *(undefined **)(param_1 + 0xa8) = &UNK_008d649c;
  func_0x00421ca0();
  puVar1 = *(undefined4 **)(param_1 + 0xc0);
  while (puVar1 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0xc0) = puVar1[1];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    puVar1 = *(undefined4 **)(param_1 + 0xc0);
  }
  *(undefined **)(param_1 + 0x84) = &UNK_008f1924;
  uStack_4._1_3_ = (undefined3)(uStack_4 >> 8);
  uStack_4 = CONCAT31(uStack_4._1_3_,3);
  *(undefined **)(param_1 + 0x88) = &UNK_008d649c;
  func_0x00421ca0();
  puVar1 = *(undefined4 **)(param_1 + 0xa0);
  while (puVar1 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0xa0) = puVar1[1];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    puVar1 = *(undefined4 **)(param_1 + 0xa0);
  }
  *(undefined **)(param_1 + 100) = &UNK_008f1924;
  uStack_4._1_3_ = (undefined3)(uStack_4 >> 8);
  uStack_4 = CONCAT31(uStack_4._1_3_,2);
  *(undefined **)(param_1 + 0x68) = &UNK_008d649c;
  func_0x00421ca0();
  puVar1 = *(undefined4 **)(param_1 + 0x80);
  while (puVar1 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x80) = puVar1[1];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    puVar1 = *(undefined4 **)(param_1 + 0x80);
  }
  *(undefined **)(param_1 + 0x44) = &UNK_008f1924;
  uStack_4._1_3_ = (undefined3)(uStack_4 >> 8);
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  puVar1 = *(undefined4 **)(param_1 + 0x4c);
  *(undefined **)(param_1 + 0x48) = &UNK_008d649c;
  while (puVar1 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x4c) = *puVar1;
    FUN_0077fd10(puVar1);
    puVar1 = *(undefined4 **)(param_1 + 0x4c);
  }
  puVar1 = *(undefined4 **)(param_1 + 0x60);
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  while (puVar1 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x60) = puVar1[1];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    puVar1 = *(undefined4 **)(param_1 + 0x60);
  }
  *(undefined **)(param_1 + 0x24) = &UNK_008f1924;
  uStack_4 = uStack_4 & 0xffffff00;
  *(undefined **)(param_1 + 0x28) = &UNK_008d649c;
  func_0x00421ca0();
  puVar1 = *(undefined4 **)(param_1 + 0x40);
  while (puVar1 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x40) = puVar1[1];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    puVar1 = *(undefined4 **)(param_1 + 0x40);
  }
  *(undefined **)(param_1 + 4) = &UNK_008f1924;
  uStack_4 = 0xffffffff;
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  *(undefined **)(param_1 + 8) = &UNK_008d649c;
  while (puVar1 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0xc) = *puVar1;
    FUN_0077fd10(puVar1);
    puVar1 = *(undefined4 **)(param_1 + 0xc);
  }
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  while (puVar1 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x20) = puVar1[1];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    puVar1 = *(undefined4 **)(param_1 + 0x20);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x007a5140 | Classified: elementclient::A3DSkinRender__AllocMeshNode__No@0x7a5140 */
/* ==================================================================== */

int __thiscall FUN_007a5140(int param_1,char param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 == '\0') {
    if (*(int *)(param_1 + 0x7c) < *(int *)(param_1 + 0x34)) {
      iVar1 = *(int *)(*(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x7c) * 4);
      *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + 1;
      return iVar1;
    }
    iVar1 = func_0x00763250(0x10);
    if (iVar1 == 0) {
      func_0x007647d0(0x9d2f20,0x98d810);
      return 0;
    }
    if ((*(int *)(param_1 + 0x38) <= *(int *)(param_1 + 0x34)) && (*(int *)(param_1 + 0x3c) != 0)) {
      iVar4 = *(int *)(param_1 + 0x3c) + *(int *)(param_1 + 0x38);
      iVar2 = func_0x00763250(iVar4 * 4);
      if (iVar2 == 0) {
        func_0x00764590(1,0x94e51c);
      }
      else {
        iVar3 = 0;
        if (0 < *(int *)(param_1 + 0x34)) {
          do {
            iVar3 = iVar3 + 1;
            *(undefined4 *)(iVar2 + -4 + iVar3 * 4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x30) + -4 + iVar3 * 4);
          } while (iVar3 < *(int *)(param_1 + 0x34));
        }
        if (*(int *)(param_1 + 0x30) != 0) {
          func_0x00763260(*(int *)(param_1 + 0x30));
        }
        *(int *)(param_1 + 0x30) = iVar2;
        *(int *)(param_1 + 0x38) = iVar4;
      }
    }
    *(int *)(*(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x34) * 4) = iVar1;
    *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
    *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + 1;
    return iVar1;
  }
  if (*(int *)(param_1 + 0x80) < *(int *)(param_1 + 0x4c)) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x48) + *(int *)(param_1 + 0x80) * 4);
    *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + 1;
    return iVar1;
  }
  iVar1 = func_0x00763250(0x10);
  if (iVar1 == 0) {
    func_0x007647d0(0x9d2f20,0x98d810);
    return 0;
  }
  if (*(int *)(param_1 + 0x50) <= *(int *)(param_1 + 0x4c)) {
    func_0x0068e120(*(undefined4 *)(param_1 + 0x54));
  }
  *(int *)(*(int *)(param_1 + 0x48) + *(int *)(param_1 + 0x4c) * 4) = iVar1;
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + 1;
  return iVar1;
}


/* ==================================================================== */
/* Address: 0x007a52c0 | Classified: Angelica3D::proc_7a52c0 */
/* ==================================================================== */

void __thiscall FUN_007a52c0(int param_1,char param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == '\0') {
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0x78)) {
      do {
        iVar2 = *(int *)(*(int *)(param_1 + 0x18) + iVar3 * 4);
        puVar1 = *(undefined4 **)(iVar2 + 0x6c);
        while (puVar1 != (undefined4 *)0x0) {
          *(undefined4 *)(iVar2 + 0x6c) = *puVar1;
          *puVar1 = *(undefined4 *)(iVar2 + 0x74);
          *(undefined4 **)(iVar2 + 0x74) = puVar1;
          *(int *)(iVar2 + 0x78) = *(int *)(iVar2 + 0x78) + -1;
          puVar1 = *(undefined4 **)(iVar2 + 0x6c);
        }
        *(undefined4 *)(iVar2 + 0x70) = 0;
        *(undefined4 *)(iVar2 + 0x78) = 0;
        puVar1 = *(undefined4 **)(iVar2 + 0x2c);
        while (puVar1 != (undefined4 *)0x0) {
          *(undefined4 *)(iVar2 + 0x2c) = *puVar1;
          *puVar1 = *(undefined4 *)(iVar2 + 0x34);
          *(undefined4 **)(iVar2 + 0x34) = puVar1;
          *(int *)(iVar2 + 0x38) = *(int *)(iVar2 + 0x38) + -1;
          puVar1 = *(undefined4 **)(iVar2 + 0x2c);
        }
        *(undefined4 *)(iVar2 + 0x30) = 0;
        *(undefined4 *)(iVar2 + 0x38) = 0;
        puVar1 = *(undefined4 **)(iVar2 + 0x4c);
        while (puVar1 != (undefined4 *)0x0) {
          *(undefined4 *)(iVar2 + 0x4c) = *puVar1;
          *puVar1 = *(undefined4 *)(iVar2 + 0x54);
          *(undefined4 **)(iVar2 + 0x54) = puVar1;
          *(int *)(iVar2 + 0x58) = *(int *)(iVar2 + 0x58) + -1;
          puVar1 = *(undefined4 **)(iVar2 + 0x4c);
        }
        *(undefined4 *)(iVar2 + 0x50) = 0;
        *(undefined4 *)(iVar2 + 0x58) = 0;
        puVar1 = *(undefined4 **)(iVar2 + 0xc);
        while (puVar1 != (undefined4 *)0x0) {
          *(undefined4 *)(iVar2 + 0xc) = *puVar1;
          *puVar1 = *(undefined4 *)(iVar2 + 0x14);
          *(undefined4 **)(iVar2 + 0x14) = puVar1;
          *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + -1;
          puVar1 = *(undefined4 **)(iVar2 + 0xc);
        }
        *(undefined4 *)(iVar2 + 0x10) = 0;
        *(undefined4 *)(iVar2 + 0x18) = 0;
        puVar1 = *(undefined4 **)(iVar2 + 0x8c);
        while (puVar1 != (undefined4 *)0x0) {
          *(undefined4 *)(iVar2 + 0x8c) = *puVar1;
          *puVar1 = *(undefined4 *)(iVar2 + 0x94);
          *(undefined4 **)(iVar2 + 0x94) = puVar1;
          *(int *)(iVar2 + 0x98) = *(int *)(iVar2 + 0x98) + -1;
          puVar1 = *(undefined4 **)(iVar2 + 0x8c);
        }
        *(undefined4 *)(iVar2 + 0x90) = 0;
        *(undefined4 *)(iVar2 + 0x98) = 0;
        puVar1 = *(undefined4 **)(iVar2 + 0xac);
        while (puVar1 != (undefined4 *)0x0) {
          *(undefined4 *)(iVar2 + 0xac) = *puVar1;
          *puVar1 = *(undefined4 *)(iVar2 + 0xb4);
          *(undefined4 **)(iVar2 + 0xb4) = puVar1;
          *(int *)(iVar2 + 0xb8) = *(int *)(iVar2 + 0xb8) + -1;
          puVar1 = *(undefined4 **)(iVar2 + 0xac);
        }
        *(undefined4 *)(iVar2 + 0xb0) = 0;
        *(undefined4 *)(iVar2 + 0xb8) = 0;
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1 + 0x78));
    }
    *(undefined4 *)(param_1 + 0x78) = 0;
    *(undefined4 *)(param_1 + 0x7c) = 0;
    return;
  }
  puVar1 = *(undefined4 **)(param_1 + 0x60);
  while (puVar1 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x60) = *puVar1;
    *puVar1 = *(undefined4 *)(param_1 + 0x68);
    *(undefined4 **)(param_1 + 0x68) = puVar1;
    puVar1 = *(undefined4 **)(param_1 + 0x60);
    *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + -1;
  }
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007a5460 | Classified: Angelica3D::proc_7a5460 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_007a5460(int param_1,undefined4 param_2,float *param_3)

{
  float *pfVar1;
  float10 fVar2;
  float fVar3;
  undefined4 ***pppuStack_6c;
  undefined1 **ppuStack_68;
  undefined1 *puStack_64;
  undefined1 **ppuStack_60;
  undefined4 **ppuStack_5c;
  undefined4 *puStack_58;
  undefined4 **ppuStack_54;
  undefined1 *puStack_50;
  undefined1 *puStack_4c;
  undefined1 *puStack_48;
  undefined4 *puStack_44;
  undefined1 *puStack_40;
  undefined4 *puStack_3c;
  float fStack_38;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined1 auStack_18 [8];
  undefined4 uStack_10;
  undefined1 auStack_c [12];
  
  puStack_3c = &uStack_24;
  uStack_24 = *(undefined4 *)(param_1 + 0x18);
  uStack_20 = *(undefined4 *)(param_1 + 0x1c);
  uStack_1c = *(undefined4 *)(param_1 + 0x20);
  fStack_38 = (float)param_2;
  puStack_40 = auStack_c;
  puStack_44 = (undefined4 *)0x7a54a5;
  uStack_10 = uStack_1c;
  pfVar1 = (float *)func_0x00787290();
  fStack_38 = pfVar1[2] - param_3[2];
  puStack_3c = (undefined4 *)(pfVar1[1] - param_3[1]);
  puStack_40 = (undefined1 *)(*pfVar1 - *param_3);
  puStack_44 = (undefined4 *)0x7a54cd;
  func_0x00401ca0();
  puStack_44 = &uStack_24;
  puStack_48 = (undefined1 *)0x7a54d7;
  func_0x0044fc90();
  uStack_1c = *(undefined4 *)(param_1 + 0x2c);
  puStack_48 = &stack0xffffffd0;
  puStack_44 = (undefined4 *)param_2;
  puStack_4c = auStack_18;
  puStack_50 = (undefined1 *)0x7a5522;
  pfVar1 = (float *)func_0x00787290();
  puStack_44 = (undefined4 *)(pfVar1[2] - param_3[2]);
  puStack_48 = (undefined1 *)(pfVar1[1] - param_3[1]);
  puStack_4c = (undefined1 *)(*pfVar1 - *param_3);
  puStack_50 = (undefined1 *)0x7a5546;
  func_0x00401ca0();
  puStack_50 = &stack0xffffffd0;
  ppuStack_54 = (undefined4 **)0x7a5550;
  fVar2 = (float10)func_0x0044fc90();
  if (fVar2 < (float10)(float)puStack_40) {
    puStack_40 = (undefined1 *)(float)fVar2;
  }
  puStack_3c = *(undefined4 **)(param_1 + 0x18);
  fStack_38 = *(float *)(param_1 + 0x28);
  ppuStack_54 = &puStack_3c;
  puStack_50 = (undefined1 *)param_2;
  puStack_58 = &uStack_24;
  ppuStack_5c = (undefined4 **)0x7a5599;
  pfVar1 = (float *)func_0x00787290();
  puStack_50 = (undefined1 *)(pfVar1[2] - param_3[2]);
  ppuStack_54 = (undefined4 **)(pfVar1[1] - param_3[1]);
  puStack_58 = (undefined4 *)(*pfVar1 - *param_3);
  ppuStack_5c = (undefined4 **)0x7a55bd;
  func_0x00401ca0();
  ppuStack_5c = &puStack_3c;
  ppuStack_60 = (undefined1 **)0x7a55c7;
  fVar2 = (float10)func_0x0044fc90();
  if (fVar2 < (float10)(float)puStack_4c) {
    puStack_4c = (undefined1 *)(float)fVar2;
  }
  puStack_48 = *(undefined1 **)(param_1 + 0x18);
  puStack_44 = *(undefined4 **)(param_1 + 0x28);
  puStack_40 = *(undefined1 **)(param_1 + 0x2c);
  ppuStack_60 = &puStack_48;
  ppuStack_5c = (undefined4 **)param_2;
  puStack_64 = &stack0xffffffd0;
  ppuStack_68 = (undefined1 **)0x7a5610;
  pfVar1 = (float *)func_0x00787290();
  ppuStack_5c = (undefined4 **)(pfVar1[2] - param_3[2]);
  ppuStack_60 = (undefined1 **)(pfVar1[1] - param_3[1]);
  puStack_64 = (undefined1 *)(*pfVar1 - *param_3);
  ppuStack_68 = (undefined1 **)0x7a5634;
  func_0x00401ca0();
  ppuStack_68 = &puStack_48;
  pppuStack_6c = (undefined4 ***)0x7a563e;
  fVar2 = (float10)func_0x0044fc90();
  if (fVar2 < (float10)(float)puStack_58) {
    puStack_58 = (undefined4 *)(float)fVar2;
  }
  ppuStack_54 = *(undefined4 ***)(param_1 + 0x24);
  puStack_50 = *(undefined1 **)(param_1 + 0x1c);
  puStack_4c = *(undefined1 **)(param_1 + 0x20);
  pppuStack_6c = &ppuStack_54;
  ppuStack_68 = (undefined1 **)param_2;
  puStack_40 = puStack_4c;
  pfVar1 = (float *)func_0x00787290(&puStack_3c);
  ppuStack_68 = (undefined1 **)(pfVar1[2] - param_3[2]);
  pppuStack_6c = (undefined4 ***)(pfVar1[1] - param_3[1]);
  fVar3 = *pfVar1 - *param_3;
  func_0x00401ca0();
  fVar2 = (float10)func_0x0044fc90(&ppuStack_54);
  if (fVar2 < (float10)(float)puStack_64) {
    puStack_64 = (undefined1 *)(float)fVar2;
  }
  ppuStack_60 = *(undefined1 ***)(param_1 + 0x24);
  ppuStack_5c = *(undefined4 ***)(param_1 + 0x1c);
  puStack_58 = *(undefined4 **)(param_1 + 0x2c);
  puStack_4c = (undefined1 *)puStack_58;
  pfVar1 = (float *)func_0x00787290(&puStack_48,&ppuStack_60,param_2);
  puStack_4c = (undefined1 *)(pfVar1[2] - param_3[2]);
  puStack_50 = (undefined1 *)(pfVar1[1] - param_3[1]);
  ppuStack_54 = (undefined4 **)(*pfVar1 - *param_3);
  fVar2 = (float10)func_0x0044fc90(&ppuStack_54);
  if (fVar2 < (float10)(float)puStack_64) {
    puStack_64 = (undefined1 *)(float)fVar2;
  }
  ppuStack_60 = *(undefined1 ***)(param_1 + 0x24);
  ppuStack_5c = *(undefined4 ***)(param_1 + 0x28);
  puStack_58 = *(undefined4 **)(param_1 + 0x20);
  puStack_4c = (undefined1 *)puStack_58;
  pfVar1 = (float *)func_0x00787290(&puStack_48,&ppuStack_60,param_2);
  func_0x00401ca0(*pfVar1 - *param_3,pfVar1[1] - param_3[1],pfVar1[2] - param_3[2]);
  fVar2 = (float10)func_0x0044fc90(&ppuStack_60);
  if (fVar2 < (float10)fVar3) {
    fVar3 = (float)fVar2;
  }
  pppuStack_6c = *(undefined4 ****)(param_1 + 0x24);
  ppuStack_68 = *(undefined1 ***)(param_1 + 0x28);
  puStack_64 = *(undefined1 **)(param_1 + 0x2c);
  puStack_58 = (undefined4 *)puStack_64;
  pfVar1 = (float *)func_0x00787290(&ppuStack_54,&pppuStack_6c,param_2);
  puStack_58 = (undefined4 *)(pfVar1[2] - param_3[2]);
  ppuStack_5c = (undefined4 **)(pfVar1[1] - param_3[1]);
  ppuStack_60 = (undefined1 **)(*pfVar1 - *param_3);
  fVar2 = (float10)func_0x0044fc90(&ppuStack_60);
  if ((float10)fVar3 <= fVar2) {
    fVar2 = (float10)fVar3;
  }
  return fVar2;
}


/* ==================================================================== */
/* Address: 0x007a5830 | Classified: Angelica3D::proc_7a5830 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007a5830(int param_1,undefined4 param_2,int param_3,int *param_4)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  char cVar8;
  int iVar9;
  int unaff_EBP;
  undefined4 *puVar10;
  float10 fVar11;
  
  if ((_DAT_008effa0 <= (float)param_4[3]) || (*(char *)((int)param_4 + 9) != '\0')) {
    return 1;
  }
  iVar3 = (**(code **)(*(int *)*param_4 + 0x1c))(param_3);
  if (((iVar3 == 0) || (*(char *)(iVar3 + 0x36) == '\0')) ||
     (cVar8 = '\x01', *(char *)(iVar3 + 0x35) == '\0')) {
    cVar8 = (char)param_3;
  }
  if (((_DAT_008effc4 <= (float)param_4[3]) || (*(int *)(param_1 + 0x2a4) != 5)) ||
     ((*(int *)(param_1 + 0x2a8) != 6 || (cVar8 != '\0')))) {
    piVar4 = (int *)FUN_007a5140(1);
    if (piVar4 == (int *)0x0) {
      return 0;
    }
    piVar4[1] = param_3;
    *piVar4 = param_1;
    piVar4[3] = (int)param_4;
    iVar3 = *param_4;
    puVar10 = (undefined4 *)(param_1 + 0xc);
    puVar7 = (undefined4 *)&stack0xffffffb8;
    for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar7 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar7 = puVar7 + 1;
    }
    uVar6 = func_0x007744f0();
    fVar11 = (float10)FUN_007a5460(iVar3 + 0x24,&stack0xffffffb8,uVar6);
    fVar1 = (float)fVar11;
    piVar4[2] = (int)fVar1;
    puVar10 = *(undefined4 **)(unaff_EBP + 0x60);
    do {
      if (puVar10 == (undefined4 *)0x0) {
        iVar3 = func_0x00419130();
        *(int **)(iVar3 + 8) = piVar4;
        *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(unaff_EBP + 100);
        if (*(int **)(unaff_EBP + 100) == (int *)0x0) {
          *(int *)(unaff_EBP + 0x60) = iVar3;
          *(int *)(unaff_EBP + 100) = iVar3;
          return 1;
        }
        **(int **)(unaff_EBP + 100) = iVar3;
        *(int *)(unaff_EBP + 100) = iVar3;
        return 1;
      }
      piVar2 = (int *)puVar10[2];
      iVar3 = *piVar4;
      iVar9 = *piVar2;
      if (iVar9 == iVar3) {
        iVar3 = ((int *)piVar2[3])[4];
        if (iVar3 == 0) {
          iVar3 = *(int *)(piVar2[1] + 0x2c);
        }
        iVar9 = ((int *)piVar4[3])[4];
        if (iVar9 == 0) {
          iVar9 = *(int *)(piVar4[1] + 0x2c);
        }
        if (iVar9 < iVar3) {
LAB_007a5a7e:
          func_0x004287f0(puVar10,piVar4);
          return 1;
        }
        iVar3 = *(int *)piVar2[3];
        iVar9 = *(int *)piVar4[3];
        if (((*(float *)(iVar9 + 0x4c) < *(float *)(iVar3 + 0x4c)) ||
            (*(float *)(iVar9 + 0x50) < *(float *)(iVar3 + 0x50))) ||
           (*(float *)(iVar3 + 0x44) < *(float *)(iVar9 + 0x44))) goto LAB_007a5a7e;
      }
      else if ((*(int *)(iVar9 + 0x2b0) == 0) ||
              (*(int *)(iVar9 + 0x2b0) != *(int *)(iVar3 + 0x2b0))) {
        if ((float)piVar2[2] < fVar1 != ((float)piVar2[2] == fVar1)) {
          puVar7 = (undefined4 *)func_0x00419130();
          puVar7[2] = piVar4;
          *puVar7 = puVar10;
          puVar7[1] = puVar10[1];
          if ((undefined4 *)puVar10[1] != (undefined4 *)0x0) {
            *(undefined4 *)puVar10[1] = puVar7;
            puVar10[1] = puVar7;
            return 1;
          }
          goto LAB_007a5b26;
        }
      }
      else if (*(int *)(iVar3 + 0x2b4) < *(int *)(iVar9 + 0x2b4)) {
        puVar7 = (undefined4 *)func_0x00419130();
        puVar7[2] = piVar4;
        *puVar7 = puVar10;
        puVar7[1] = puVar10[1];
        if ((undefined4 *)puVar10[1] != (undefined4 *)0x0) {
          *(undefined4 *)puVar10[1] = puVar7;
          puVar10[1] = puVar7;
          return 1;
        }
LAB_007a5b26:
        *(undefined4 **)(unaff_EBP + 0x60) = puVar7;
        puVar10[1] = puVar7;
        return 1;
      }
      puVar10 = (undefined4 *)*puVar10;
    } while( true );
  }
  piVar4 = (int *)FUN_007a5140(0);
  if (piVar4 == (int *)0x0) {
LAB_007a58d7:
    return 0;
  }
  *piVar4 = param_1;
  piVar4[1] = param_1;
  piVar4[3] = (int)param_4;
  iVar3 = FUN_007a5d00(param_1,*param_4);
  switch(*(undefined4 *)(*param_4 + 4)) {
  case 0x1c:
    iVar9 = iVar3 + 8;
    break;
  case 0x1d:
    iVar9 = iVar3 + 0x28;
    goto code_r0x007a5986;
  case 0x1e:
  case 0x1f:
    iVar9 = iVar3 + 0x68;
    iVar5 = func_0x00419130();
    *(int **)(iVar5 + 8) = piVar4;
    *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(iVar3 + 0x70);
    if (*(int **)(iVar3 + 0x70) != (int *)0x0) {
      **(int **)(iVar3 + 0x70) = iVar5;
      *(int *)(iVar3 + 0x70) = iVar5;
      return 1;
    }
    goto code_r0x007a5998;
  default:
    goto LAB_007a58d7;
  case 0x24:
    iVar9 = iVar3 + 0x48;
    break;
  case 0x2a:
    iVar9 = iVar3 + 0x88;
    break;
  case 0x2b:
    iVar9 = iVar3 + 0xa8;
code_r0x007a5986:
    iVar5 = func_0x00419130();
    *(int **)(iVar5 + 8) = piVar4;
    *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(iVar9 + 8);
    goto code_r0x007a5968;
  }
  iVar5 = func_0x00419130();
  *(int **)(iVar5 + 8) = piVar4;
  *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(iVar9 + 8);
code_r0x007a5968:
  if (*(int **)(iVar9 + 8) != (int *)0x0) {
    **(int **)(iVar9 + 8) = iVar5;
    *(int *)(iVar9 + 8) = iVar5;
    return 1;
  }
code_r0x007a5998:
  *(int *)(iVar9 + 4) = iVar5;
  *(int *)(iVar9 + 8) = iVar5;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a5bb0 | Classified: Angelica3D::proc_7a5bb0 */
/* ==================================================================== */

undefined4 FUN_007a5bb0(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2;
  iVar3 = *(int *)(param_2 + 0x124);
  if (((iVar3 != 0) && (*(char *)(param_2 + 0x29) != '\0')) && (0 < iVar3)) {
    iVar2 = 0;
    param_2 = iVar3;
    do {
      FUN_007a5830(param_1,param_3,iVar1,*(int *)(iVar1 + 0x120) + iVar2);
      iVar2 = iVar2 + 0x1c;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  param_2 = *(int *)(iVar1 + 0xac);
  if (0 < param_2) {
    iVar3 = 0;
    do {
      iVar2 = *(int *)(iVar1 + 0xa8) + iVar3;
      if ((*(int *)(iVar2 + 4) == 0) || (*(char *)(iVar1 + 0x29) == '\0')) {
        FUN_007a5830(param_1,param_3,iVar1,iVar2);
      }
      iVar3 = iVar3 + 0x1c;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  param_2 = *(int *)(iVar1 + 0xc0);
  if (0 < param_2) {
    iVar3 = 0;
    do {
      iVar2 = *(int *)(iVar1 + 0xbc) + iVar3;
      if ((*(int *)(iVar2 + 4) == 0) || (*(char *)(iVar1 + 0x29) == '\0')) {
        FUN_007a5830(param_1,param_3,iVar1,iVar2);
      }
      iVar3 = iVar3 + 0x1c;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  param_2 = *(int *)(iVar1 + 0xd4);
  if (0 < param_2) {
    iVar3 = 0;
    do {
      FUN_007a5830(param_1,param_3,iVar1,*(int *)(iVar1 + 0xd0) + iVar3);
      iVar3 = iVar3 + 0x1c;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  iVar3 = *(int *)(iVar1 + 0xe8);
  if (0 < iVar3) {
    iVar2 = 0;
    param_2 = iVar3;
    do {
      FUN_007a5830(param_1,param_3,iVar1,*(int *)(iVar1 + 0xe4) + iVar2);
      iVar2 = iVar2 + 0x1c;
      param_2 = param_2 + -1;
      iVar3 = 0;
    } while (param_2 != 0);
  }
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007a5d00 | Classified: elementclient::A3DSkinRender__SelectRenderSlot_@0x7a5d00 */
/* ==================================================================== */

int * __thiscall FUN_007a5d00(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd645;
  *unaff_FS_OFFSET = &uStack_c;
  iVar4 = 0;
  if ((-1 < *(int *)(param_3 + 0x14)) &&
     (iVar5 = *(int *)(*(int *)(param_2 + 0x38) + *(int *)(param_3 + 0x14) * 4), iVar5 != 0)) {
    iVar4 = *(int *)(iVar5 + 0x28);
  }
  iVar5 = *(int *)(param_1 + 0x78);
  piVar3 = (int *)0x0;
  iVar1 = 0;
  if (0 < iVar5) {
    puVar2 = *(undefined4 **)(param_1 + 0x18);
    do {
      piVar3 = (int *)*puVar2;
      if (*piVar3 == iVar4) break;
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar1 < iVar5);
  }
  if (iVar1 == iVar5) {
    if (iVar5 < *(int *)(param_1 + 0x1c)) {
      piVar3 = *(int **)(*(int *)(param_1 + 0x18) + iVar5 * 4);
    }
    else {
      piVar3 = (int *)func_0x00763250(0xc4);
      uStack_4 = 0;
      if (piVar3 == (int *)0x0) {
        piVar3 = (int *)0x0;
      }
      else {
        func_0x00431c00(10);
        piVar3[1] = (int)&UNK_008f1924;
        puStack_8 = (undefined *)CONCAT31(puStack_8._1_3_,1);
        func_0x00431c00(10);
        piVar3[9] = (int)&UNK_008f1924;
        uStack_c = CONCAT31(uStack_c._1_3_,2);
        func_0x00431c00(10);
        piVar3[0x11] = (int)&UNK_008f1924;
        FUN_007a8700(10);
        FUN_007a8700(10);
        FUN_007a8700(10);
      }
      uStack_4 = 0xffffffff;
      if (piVar3 == (int *)0x0) {
        func_0x007647d0(0x9d2f20,0x98d844);
        piVar3 = (int *)0x0;
        goto LAB_007a5eac;
      }
    }
    uStack_4 = 0xffffffff;
    *piVar3 = iVar4;
    if (*(int *)(param_1 + 0x1c) <= *(int *)(param_1 + 0x78)) {
      if ((*(int *)(param_1 + 0x20) <= *(int *)(param_1 + 0x1c)) && (*(int *)(param_1 + 0x24) != 0))
      {
        iVar5 = *(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x20);
        iVar4 = func_0x00763250(iVar5 * 4);
        if (iVar4 == 0) {
          func_0x00764590(1,0x94e51c);
        }
        else {
          iVar1 = 0;
          if (0 < *(int *)(param_1 + 0x1c)) {
            do {
              iVar1 = iVar1 + 1;
              *(undefined4 *)(iVar4 + -4 + iVar1 * 4) =
                   *(undefined4 *)(*(int *)(param_1 + 0x18) + -4 + iVar1 * 4);
            } while (iVar1 < *(int *)(param_1 + 0x1c));
          }
          if (*(int *)(param_1 + 0x18) != 0) {
            func_0x00763260(*(int *)(param_1 + 0x18));
          }
          *(int *)(param_1 + 0x18) = iVar4;
          *(int *)(param_1 + 0x20) = iVar5;
        }
      }
      *(int **)(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x1c) * 4) = piVar3;
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
    }
    *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + 1;
  }
LAB_007a5eac:
  *unaff_FS_OFFSET = uStack_c;
  return piVar3;
}


/* ==================================================================== */
/* Address: 0x007a5ed0 | Classified: Angelica3D::proc_7a5ed0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_007a5ed0(int param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  float unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  float fStack_d4;
  float fStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  float fStack_c4;
  float fStack_c0;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  undefined4 uStack_14;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd663;
  *unaff_FS_OFFSET = &uStack_c;
  if (*(int *)(param_1 + 8) != 0) {
    puVar1 = (undefined4 *)param_2[3];
    iVar3 = *param_2;
    fStack_d4 = (float)puVar1[3];
    fStack_d0 = _DAT_008effa0 - fStack_d4;
    if (*(int *)(iVar3 + 0x220) == 2) {
      uStack_cc = *(undefined4 *)(iVar3 + 0x27c);
      uStack_c8 = *(undefined4 *)(iVar3 + 0x280);
      fStack_c4 = *(float *)(iVar3 + 0x284);
      fStack_c0 = *(float *)(iVar3 + 0x288);
      if (_DAT_008effc4 < fStack_d4) {
        fStack_c0 = fStack_d0;
      }
      uVar2 = (**(code **)(*(int *)*puVar1 + 0x24))(param_2[1]);
      func_0x007b65e0(uVar2);
      uStack_c = 0;
      func_0x007b6b70(&fStack_d4,1);
      iVar3 = *param_2;
      fStack_84 = fStack_84 + *(float *)(iVar3 + 0x298);
      fStack_88 = fStack_88 + *(float *)(iVar3 + 0x294);
      fStack_8c = fStack_8c + *(float *)(iVar3 + 0x290);
      fStack_90 = fStack_90 + *(float *)(iVar3 + 0x28c);
      func_0x007b6790();
    }
    else {
      if (*(int *)(iVar3 + 0x220) == 0) {
        iVar3 = (**(code **)(*(int *)*puVar1 + 0x24))(param_2[1]);
      }
      else {
        iVar3 = iVar3 + 0x224;
      }
      func_0x007b65e0(iVar3);
      puStack_8 = (undefined *)0x1;
      if (_DAT_008effc4 < unaff_EDI) {
        fStack_c4 = fStack_d4;
        fStack_d0 = 1.0;
        uStack_cc = 0x3f800000;
        uStack_c8 = 0x3f800000;
        func_0x007b6b70(&fStack_d0,1);
      }
      iVar3 = *param_2;
      fStack_20 = fStack_20 + *(float *)(iVar3 + 0x298);
      fStack_24 = fStack_24 + *(float *)(iVar3 + 0x294);
      fStack_28 = fStack_28 + *(float *)(iVar3 + 0x290);
      fStack_2c = fStack_2c + *(float *)(iVar3 + 0x28c);
      func_0x007b6790();
    }
    uStack_14 = 0xffffffff;
    func_0x007dc680();
    iVar3 = (**(code **)(**(int **)param_2[3] + 0x24))(param_2[1]);
    if (*(char *)(iVar3 + 0x50) == '\0') {
      uVar2 = *(undefined4 *)(param_1 + 0x98);
    }
    else {
      uVar2 = 1;
    }
    func_0x0077a540(uVar2);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x007a6110 | Classified: Angelica3D::proc_7a6110 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_007a6110(int param_1,int *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *unaff_FS_OFFSET;
  float fStack_ec;
  float **ppfStack_e8;
  float fStack_e4;
  undefined4 uStack_e0;
  undefined1 **ppuStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  float *pfStack_d0;
  float fStack_cc;
  float fStack_c8;
  undefined1 *puStack_c4;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  undefined1 auStack_64 [44];
  undefined4 uStack_38;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd678;
  *unaff_FS_OFFSET = &uStack_c;
  if (*(int *)(param_1 + 8) != 0) {
    fStack_b4 = 1.1238824e-38;
    func_0x007b65a0();
    uStack_4 = 0;
    puVar2 = *(undefined1 **)(*param_2 + 0x220);
    if (puVar2 == (undefined1 *)0x2) {
      fStack_b4 = (float)param_2[1];
      fStack_b8 = 1.1238927e-38;
      fStack_b8 = (float)(**(code **)(**(int **)param_2[3] + 0x24))();
      fStack_bc = 1.123894e-38;
      func_0x007b6ae0();
      fStack_bc = 1.4013e-45;
      fStack_c0 = (float)(*param_2 + 0x27c);
      puStack_c4 = (undefined1 *)0x7a61ad;
      func_0x007b6b70();
      puVar2 = auStack_64;
    }
    else if (puVar2 == (undefined1 *)0x0) {
      fStack_b4 = (float)param_2[1];
      fStack_b8 = 1.1239002e-38;
      puVar2 = (undefined1 *)(**(code **)(**(int **)param_2[3] + 0x24))();
    }
    else if (puVar2 == (undefined1 *)0x1) {
      puVar2 = (undefined1 *)(*param_2 + 0x224);
    }
    iVar1 = *param_2;
    fStack_b8 = (float)(param_1 + 0x88);
    fStack_b4 = 1.4013e-45;
    fStack_bc = 0.0;
    *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(puVar2 + 0x4c);
    fStack_c0 = 1.1239084e-38;
    func_0x0077ba40();
    puStack_c4 = &stack0xffffff54;
    fStack_c0 = 1.4013e-45;
    fStack_c8 = 9.80909e-45;
    fStack_cc = 1.1239275e-38;
    func_0x0077ba40();
    fStack_b4 = *(float *)(iVar1 + 0x1c4) * *(float *)(puVar2 + 0x10);
    fStack_b8 = *(float *)(puVar2 + 0xc) * *(float *)(iVar1 + 0x1c0);
    pfStack_d0 = &fStack_b8;
    fStack_cc = 1.4013e-45;
    uStack_d4 = 8;
    uStack_d8 = 0x7a62db;
    func_0x0077ba40();
    fStack_b8 = *(float *)(iVar1 + 0x1dc) * *(float *)(puVar2 + 0x38);
    fStack_bc = *(float *)(iVar1 + 0x1d8) * *(float *)(puVar2 + 0x34);
    fStack_c0 = *(float *)(iVar1 + 0x1d4) * *(float *)(puVar2 + 0x30);
    puStack_c4 = (undefined1 *)(*(float *)(puVar2 + 0x2c) * *(float *)(iVar1 + 0x1d0));
    ppuStack_dc = &puStack_c4;
    uStack_d8 = 1;
    uStack_e0 = 9;
    fStack_e4 = 1.1239473e-38;
    func_0x0077ba40();
    if (*(char *)(iVar1 + 0x1e0) != '\0') {
      puStack_c4 = (undefined1 *)(*(float *)(iVar1 + 0x1fc) * *(float *)(puVar2 + 0x28));
      fStack_c8 = *(float *)(iVar1 + 0x1f8) * *(float *)(puVar2 + 0x24);
      fStack_cc = *(float *)(iVar1 + 500) * *(float *)(puVar2 + 0x20);
      pfStack_d0 = (float *)(*(float *)(puVar2 + 0x1c) * *(float *)(iVar1 + 0x1f0));
      ppfStack_e8 = &pfStack_d0;
      fStack_e4 = 1.4013e-45;
      fStack_ec = 1.68156e-44;
      func_0x0077ba40();
      func_0x004217f0(*(float *)(iVar1 + 0x200) * *(float *)(puVar2 + 0xc),
                      *(float *)(iVar1 + 0x204) * *(float *)(puVar2 + 0x10),
                      *(float *)(iVar1 + 0x208) * *(float *)(puVar2 + 0x14),
                      *(float *)(iVar1 + 0x20c) * *(float *)(puVar2 + 0x18));
      fStack_ec = fStack_c0;
      ppfStack_e8 = (float **)fStack_bc;
      fStack_e4 = fStack_b8;
      uStack_e0 = 0;
      func_0x0077ba40(0xb,&fStack_ec,1);
    }
    if (puVar2[0x50] == '\0') {
      uStack_d8 = *(undefined4 *)(param_1 + 0x98);
    }
    else {
      uStack_d8 = 1;
    }
    ppuStack_dc = (undefined1 **)0x7a63d9;
    func_0x0077a540();
    if (fStack_b8 == 2.8026e-45) {
      ppuStack_dc = (undefined1 **)0x7a63e9;
      FUN_00430850();
    }
    uStack_38 = 0xffffffff;
    ppuStack_dc = (undefined1 **)0x7a63fd;
    func_0x007dc680();
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x007a6420 | Classified: Angelica3D::proc_7a6420 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_007a6420(int param_1,float param_2)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd698;
  *unaff_FS_OFFSET = &uStack_c;
  if (*(int *)(param_1 + 8) != 0) {
    if ((DAT_009d2fb1 & 1) == 0) {
      DAT_009d2fb1 = DAT_009d2fb1 | 1;
      func_0x007b65a0();
      func_0x00892e60(&UNK_007a6510);
    }
    if (DAT_009d3068 == '\0') {
      func_0x007b6680(*(undefined4 *)(param_1 + 8));
      DAT_009d3068 = '\x01';
    }
    if (_DAT_008effc4 < param_2) {
      func_0x007b65e0(0x9d2fb8);
      puStack_8 = (undefined *)0x0;
      func_0x007b6790();
      puStack_8 = (undefined *)0xffffffff;
      func_0x007dc680();
      *unaff_FS_OFFSET = uStack_10;
      return;
    }
    func_0x007b6790();
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x007a6520 | Classified: Angelica3D::proc_7a6520 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_007a6520(int param_1)

{
  undefined4 uStack_50;
  undefined *puStack_4c;
  undefined4 uStack_48;
  float fStack_44;
  undefined4 uStack_40;
  float fStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  undefined *puStack_18;
  
  if (*(int *)(param_1 + 8) != 0) {
    if ((DAT_009d2fb0 & 1) == 0) {
      DAT_009d2fb0 = DAT_009d2fb0 | 1;
      puStack_18 = (undefined *)0x7a654f;
      func_0x007b65a0();
      puStack_18 = &UNK_007a6660;
      iStack_1c = 0x7a6559;
      func_0x00892e60();
    }
    if (DAT_009d3069 == '\0') {
      puStack_18 = *(undefined **)(param_1 + 8);
      iStack_1c = 0x7a6573;
      func_0x007b6680();
      DAT_009d3069 = '\x01';
    }
    iStack_1c = param_1 + 0x88;
    puStack_18 = (undefined *)0x1;
    *(undefined4 *)(param_1 + 0x8c) = _DAT_009d305c;
    uStack_20 = 0;
    uStack_24 = 0x7a6599;
    func_0x0077ba40();
    uStack_24 = 1;
    uStack_28 = 0x9d302c;
    uStack_2c = 7;
    uStack_30 = 0x7a65aa;
    func_0x0077ba40();
    uStack_30 = 1;
    uStack_34 = 0x9d303c;
    uStack_38 = 9;
    fStack_3c = 1.1240425e-38;
    func_0x0077ba40();
    fStack_3c = 1.4013e-45;
    uStack_40 = 0x9d302c;
    fStack_44 = 1.68156e-44;
    uStack_48 = 0x7a65cc;
    func_0x0077ba40();
    uStack_48 = 1;
    puStack_4c = &DAT_009d301c;
    uStack_50 = 0xb;
    func_0x0077ba40();
    func_0x0077a540(1);
    if (_DAT_008effc4 < fStack_3c) {
      fStack_44 = _DAT_008effa0 - fStack_3c;
      uStack_50 = _DAT_009d301c;
      puStack_4c = (undefined *)_DAT_009d3020;
      uStack_48 = _DAT_009d3024;
      func_0x0077ba40(8,&uStack_50,1);
      return;
    }
    func_0x0077ba40(8,&DAT_009d301c,1);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007a6670 | Classified: Angelica3D::proc_7a6670 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a6670(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int unaff_EBX;
  undefined8 uVar7;
  int iStack_100;
  undefined1 auStack_f0 [8];
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 auStack_94 [5];
  undefined1 auStack_80 [48];
  undefined1 auStack_50 [80];
  
  iVar3 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    iVar3 = *(int *)(param_1 + 4);
    uVar7 = FUN_00766250();
    *(undefined8 *)(iVar3 + 0x580) = uVar7;
    iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 0xd8);
    if (iVar3 != 0) {
      uStack_e8 = *(undefined4 *)(iVar3 + 0x10);
      uStack_e4 = *(undefined4 *)(iVar3 + 0x14);
      uStack_e0 = *(undefined4 *)(iVar3 + 0x18);
      uStack_dc = *(undefined4 *)(iVar3 + 0x1c);
      uStack_d8 = *(undefined4 *)(iVar3 + 0x20);
      func_0x00410950(iVar3 + 0x24);
      func_0x00410950(iVar3 + 0x34);
      func_0x00401cc0(iVar3 + 0x44);
      func_0x00401cc0(iVar3 + 0x50);
      uStack_9c = *(undefined4 *)(iVar3 + 0x5c);
      uStack_98 = *(undefined4 *)(iVar3 + 0x60);
      auStack_94[0] = *(undefined4 *)(iVar3 + 100);
      auStack_94[1] = *(undefined4 *)(iVar3 + 0x68);
      auStack_94[2] = *(undefined4 *)(iVar3 + 0x6c);
      auStack_94[3] = *(undefined4 *)(iVar3 + 0x70);
      auStack_94[4] = *(undefined4 *)(iVar3 + 0x74);
    }
    if (*(int *)(*(int *)(param_1 + 0xc) + 0xdc) != 0) {
      FUN_0079b340();
    }
    if (*(int *)(param_1 + 0x84) != 4) {
      func_0x00779fc0(0,*(int *)(param_1 + 0x84));
    }
    iStack_100 = *(int *)(*(int *)(param_1 + 8) + 0x28c);
    if (iStack_100 == 0) {
      func_0x007873a0(auStack_80,*(int *)(param_2 + 0x30) + 0xa8,*(int *)(param_2 + 0x30) + 0x128);
      func_0x007874a0();
      func_0x0077ba40(2,auStack_80,4);
      unaff_EBX = 0;
      iStack_100 = 0;
      func_0x0077ba40(6,&stack0xfffffefc,1);
    }
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x168);
    *(undefined1 *)(param_1 + 0x9c) = 0;
    *(undefined4 *)(param_1 + 0x98) = uVar1;
    iVar3 = func_0x0077bd50(0x98);
    if (iVar3 == 1) {
      *(undefined1 *)(param_1 + 0x9c) = 1;
      piVar2 = *(int **)(*(int *)(param_1 + 8) + 0x2c);
      (**(code **)(*piVar2 + 0xc4))(piVar2,0,param_1 + 0xa0);
      puVar5 = auStack_94 + 1;
      puVar4 = (undefined4 *)(*(int *)(param_2 + 0x30) + 0xe8);
      iVar3 = 4;
      do {
        iVar6 = 4;
        do {
          uVar1 = *puVar4;
          puVar4 = puVar4 + 1;
          *puVar5 = uVar1;
          puVar5 = puVar5 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      puVar5 = (undefined4 *)func_0x00787610(auStack_50);
      puVar4 = auStack_94;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar4 = puVar4 + 1;
      }
      func_0x007874a0();
      func_0x007f6774(param_1 + 0xb0,param_1 + 0xa0,auStack_94);
    }
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0x78)) {
      do {
        iVar6 = *(int *)(*(int *)(param_1 + 0x18) + iVar3 * 4);
        if (*(int *)(iVar6 + 0x18) != 0) {
          if (unaff_EBX == 0) {
            FUN_007a6e00(param_2,iVar6);
          }
          else if (unaff_EBX == 1) {
            FUN_007a6d10(param_2,iVar6);
          }
          else if (unaff_EBX == 2) {
            FUN_007a6f90(param_2,iVar6);
          }
        }
        if (*(int *)(iVar6 + 0x38) != 0) {
          FUN_007a7070(param_2,iVar6);
        }
        if (*(int *)(iVar6 + 0x58) != 0) {
          FUN_007a7230(param_2,iVar6);
        }
        if (*(int *)(iVar6 + 0x78) != 0) {
          if (unaff_EBX == 0) {
            FUN_007a73e0();
          }
          else {
            FUN_007a74f0(param_2,iVar6);
          }
        }
        if (*(int *)(iVar6 + 0x98) != 0) {
          FUN_007a75c0(param_2,iVar6);
        }
        if (*(int *)(iVar6 + 0xb8) != 0) {
          FUN_007a7300(param_2,iVar6);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1 + 0x78));
    }
    if (((char)param_2 != '\0') && (*(int *)(param_1 + 0x6c) != 0)) {
      FUN_007a76a0(param_2);
    }
    iVar3 = 0;
    do {
      func_0x0077b9c0(iVar3);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 5);
    func_0x0077a450(iStack_100);
    if (*(int *)(*(int *)(param_1 + 0xc) + 0xd8) != 0) {
      FUN_0079b390(auStack_f0);
    }
    if (*(int *)(*(int *)(param_1 + 0xc) + 0xdc) != 0) {
      FUN_0079b370();
    }
    if (*(int *)(param_1 + 0x84) != 4) {
      func_0x00779fc0(0,4);
    }
    func_0x0077a540(*(undefined4 *)(param_1 + 0x98));
    iVar6 = *(int *)(param_1 + 4);
    iVar3 = FUN_00766250();
    iVar3 = iVar3 - *(int *)(iVar6 + 0x580);
    *(int *)(iVar6 + 0x588) = *(int *)(iVar6 + 0x588) + iVar3;
  }
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007a6a20 | Classified: Angelica3D::proc_7a6a20 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a6a20(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 unaff_ESI;
  undefined8 uVar7;
  undefined4 unaff_retaddr;
  undefined1 auStack_f4 [12];
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 auStack_94 [5];
  undefined1 auStack_80 [48];
  undefined1 auStack_50 [68];
  int iStack_c;
  
  iVar3 = 0;
  if ((*(int *)(param_1 + 8) != 0) && (iVar3 = 0, *(int *)(param_1 + 0x6c) != 0)) {
    iVar3 = *(int *)(param_1 + 4);
    uVar7 = FUN_00766250();
    *(undefined8 *)(iVar3 + 0x580) = uVar7;
    iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 0xd8);
    if (iVar3 != 0) {
      uStack_e8 = *(undefined4 *)(iVar3 + 0x10);
      uStack_e4 = *(undefined4 *)(iVar3 + 0x14);
      uStack_e0 = *(undefined4 *)(iVar3 + 0x18);
      uStack_dc = *(undefined4 *)(iVar3 + 0x1c);
      uStack_d8 = *(undefined4 *)(iVar3 + 0x20);
      func_0x00410950(iVar3 + 0x24);
      func_0x00410950(iVar3 + 0x34);
      func_0x00401cc0(iVar3 + 0x44);
      func_0x00401cc0(iVar3 + 0x50);
      uStack_9c = *(undefined4 *)(iVar3 + 0x5c);
      uStack_98 = *(undefined4 *)(iVar3 + 0x60);
      auStack_94[0] = *(undefined4 *)(iVar3 + 100);
      auStack_94[1] = *(undefined4 *)(iVar3 + 0x68);
      auStack_94[2] = *(undefined4 *)(iVar3 + 0x6c);
      auStack_94[3] = *(undefined4 *)(iVar3 + 0x70);
      auStack_94[4] = *(undefined4 *)(iVar3 + 0x74);
    }
    if (*(int *)(*(int *)(param_1 + 0xc) + 0xdc) != 0) {
      FUN_0079b340();
    }
    if (*(int *)(param_1 + 0x84) != 4) {
      func_0x00779fc0(0,*(int *)(param_1 + 0x84));
    }
    if (*(int *)(*(int *)(param_1 + 8) + 0x28c) == 0) {
      func_0x007873a0(auStack_80,*(int *)(param_2 + 0x30) + 0xa8,*(int *)(param_2 + 0x30) + 0x128);
      func_0x007874a0();
      func_0x0077ba40(2,auStack_80,4);
      unaff_ESI = 0;
      func_0x0077ba40(6,&stack0xfffffefc,1);
    }
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x168);
    *(undefined1 *)(param_1 + 0x9c) = 0;
    *(undefined4 *)(param_1 + 0x98) = uVar1;
    iVar3 = func_0x0077bd50(0x98);
    if (iVar3 == 1) {
      *(undefined1 *)(param_1 + 0x9c) = 1;
      piVar2 = *(int **)(*(int *)(param_1 + 8) + 0x2c);
      (**(code **)(*piVar2 + 0xc4))(piVar2,0,param_1 + 0xa0);
      puVar5 = auStack_94 + 1;
      iVar3 = 4;
      puVar4 = (undefined4 *)(*(int *)(iStack_c + 0x30) + 0xe8);
      do {
        iVar6 = 4;
        do {
          uVar1 = *puVar4;
          puVar4 = puVar4 + 1;
          *puVar5 = uVar1;
          puVar5 = puVar5 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      puVar5 = (undefined4 *)func_0x00787610(auStack_50);
      puVar4 = auStack_94;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar4 = puVar4 + 1;
      }
      func_0x007874a0();
      func_0x007f6774(param_1 + 0xb0,param_1 + 0xa0,auStack_94);
    }
    FUN_007a76a0(unaff_retaddr);
    iVar3 = 0;
    do {
      func_0x0077b9c0(iVar3);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 5);
    func_0x0077a450(unaff_ESI);
    if (*(int *)(*(int *)(param_1 + 0xc) + 0xd8) != 0) {
      FUN_0079b390(auStack_f4);
    }
    if (*(int *)(*(int *)(param_1 + 0xc) + 0xdc) != 0) {
      FUN_0079b370();
    }
    if (*(int *)(param_1 + 0x84) != 4) {
      func_0x00779fc0(0,4);
    }
    func_0x0077a540(*(undefined4 *)(param_1 + 0x98));
    iVar6 = *(int *)(param_1 + 4);
    iVar3 = FUN_00766250();
    iVar3 = iVar3 - *(int *)(iVar6 + 0x580);
    *(int *)(iVar6 + 0x588) = *(int *)(iVar6 + 0x588) + iVar3;
  }
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007a6d10 | Classified: Angelica3D::proc_7a6d10 */
/* ==================================================================== */

undefined4 __fastcall FUN_007a6d10(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *unaff_EDI;
  int *piVar3;
  int unaff_retaddr;
  undefined4 uVar4;
  undefined4 uVar5;
  
  func_0x0077b920(1);
  func_0x0077b9a0(3);
  piVar3 = *(int **)(unaff_retaddr + 0xc);
  piVar2 = (int *)(**(code **)(*(int *)**(undefined4 **)(piVar3[2] + 0xc) + 0x1c))
                            (*(undefined4 *)(piVar3[2] + 4));
  uVar4 = 0;
  if (piVar2 == (int *)0x0) {
    func_0x0077aab0();
  }
  else {
    (**(code **)(*piVar2 + 0x18))(0);
  }
  do {
    puVar1 = (undefined4 *)piVar3[2];
    piVar3 = (int *)*piVar3;
    uVar5 = *puVar1;
    piVar2 = *(int **)puVar1[3];
    FUN_00792b10(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0xd8),
                 *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xdc));
    FUN_007a5ed0(puVar1);
    (**(code **)(*piVar2 + 0x18))(uVar5,uVar4,unaff_EDI);
  } while (piVar3 != (int *)0x0);
  if (((unaff_EDI != (int *)0x0) &&
      ((**(code **)(*unaff_EDI + 0x1c))(0), *(char *)((int)unaff_EDI + 0x36) != '\0')) &&
     (*(int *)(param_1 + 0x84) != 4)) {
    func_0x00779fc0(0,*(int *)(param_1 + 0x84));
  }
  func_0x0077b920(0);
  func_0x0077b9a0(0);
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a6e00 | Classified: Angelica3D::proc_7a6e00 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a6e00(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  int *unaff_ESI;
  int *piVar7;
  undefined4 uStack_4;
  
  piVar7 = *(int **)(param_3 + 0xc);
  piVar5 = (int *)(**(code **)(*(int *)**(undefined4 **)(piVar7[2] + 0xc) + 0x1c))
                            (*(undefined4 *)(piVar7[2] + 4));
  if (piVar5 == (int *)0x0) {
    func_0x0077aab0();
  }
  else {
    (**(code **)(*piVar5 + 0x18))(0);
  }
  do {
    piVar1 = (int *)*piVar7;
    piVar7 = (int *)piVar7[2];
    iVar2 = *piVar7;
    piVar3 = *(int **)piVar7[3];
    if (*(char *)((undefined4 *)piVar7[3] + 2) == '\0') {
      if (*(char *)(param_1 + 0x9c) != '\0') {
        piVar4 = *(int **)(*(int *)(param_1 + 8) + 0x2c);
        (**(code **)(*piVar4 + 0xc0))(piVar4,0,param_1 + 0xb0);
      }
      if (*(int *)(piVar7[3] + 0x14) == 0) {
        uVar6 = (uint)(*(char *)(iVar2 + 0x1a1) == '\0');
        if (*(char *)(iVar2 + 0x1e0) != '\0') {
          uVar6 = uVar6 + 2;
        }
        if (*(int *)(uVar6 * 0x30 + 0x18 + *(int *)(param_1 + 0xc)) == 0) goto LAB_007a6f41;
      }
      FUN_00790930();
      FUN_007929c0(uStack_4);
      FUN_007a6110(piVar7);
      (**(code **)(*piVar3 + 0x18))(unaff_ESI,iVar2,piVar5);
      if (*(char *)(param_1 + 0x9c) != '\0') {
        piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x2c);
        (**(code **)(*piVar7 + 0xc0))(piVar7,0,param_1 + 0xa0);
      }
    }
    else {
      FUN_00792b10(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0xd8),
                   *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xdc));
      FUN_007a5ed0(piVar7);
      (**(code **)(*piVar3 + 0x34))(piVar1,iVar2,unaff_ESI);
    }
LAB_007a6f41:
    piVar7 = piVar1;
    if (piVar1 == (int *)0x0) {
      if (((unaff_ESI != (int *)0x0) &&
          ((**(code **)(*unaff_ESI + 0x1c))(0), *(char *)((int)unaff_ESI + 0x36) != '\0')) &&
         (*(int *)(param_1 + 0x84) != 4)) {
        func_0x00779fc0(0,*(int *)(param_1 + 0x84));
      }
      func_0x0077bad0();
      return 1;
    }
  } while( true );
}


/* ==================================================================== */
/* Address: 0x007a6f90 | Classified: Angelica3D::proc_7a6f90 */
/* ==================================================================== */

undefined4 FUN_007a6f90(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  int *unaff_EDI;
  int *piVar5;
  
  func_0x00779ca0();
  piVar5 = *(int **)(param_1 + 0xc);
  iVar1 = *(int *)(piVar5[2] + 4);
  piVar4 = (int *)(**(code **)(*(int *)**(undefined4 **)(piVar5[2] + 0xc) + 0x1c))();
  if (piVar4 == (int *)0x0) {
    func_0x0077aab0();
  }
  else {
    (**(code **)(*piVar4 + 0x18))(0);
  }
  do {
    puVar2 = (undefined4 *)piVar5[2];
    piVar5 = (int *)*piVar5;
    uVar3 = *puVar2;
    piVar4 = *(int **)puVar2[3];
    FUN_00792b10(*(undefined4 *)(iRam009d2f34 + 0xd8),*(undefined4 *)(iRam009d2f34 + 0xdc));
    FUN_007a5ed0(puVar2);
    (**(code **)(*piVar4 + 0x18))(0x9d2f28,uVar3,unaff_EDI);
  } while (piVar5 != (int *)0x0);
  if (unaff_EDI != (int *)0x0) {
    (**(code **)(*unaff_EDI + 0x1c))(0);
    if ((*(char *)((int)unaff_EDI + 0x36) != '\0') && (iVar1 = *(int *)(iVar1 + 0x84), iVar1 != 4))
    {
      func_0x00779fc0(0,iVar1);
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a7070 | Classified: Angelica3D::proc_7a7070 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a7070(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  undefined4 unaff_EBX;
  int *unaff_ESI;
  int *piVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uStack_4;
  
  piVar6 = *(int **)(param_3 + 0x2c);
  uVar9 = *(undefined4 *)(piVar6[2] + 4);
  piVar4 = (int *)(**(code **)(*(int *)**(undefined4 **)(piVar6[2] + 0xc) + 0x1c))(uVar9);
  uVar8 = 0;
  if (piVar4 == (int *)0x0) {
    func_0x0077aab0();
  }
  else {
    (**(code **)(*piVar4 + 0x18))(0);
  }
  if (*(int *)(*(int *)(param_1 + 8) + 0x28c) == 0) {
    do {
      piVar1 = (int *)piVar6[2];
      piVar6 = (int *)*piVar6;
      iVar10 = piVar1[1];
      iVar2 = *piVar1;
      if (*(char *)(param_1 + 0x9c) != '\0') {
        piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x2c);
        (**(code **)(*piVar3 + 0xc0))(piVar3,0,param_1 + 0xb0);
      }
      if (*(int *)(piVar1[3] + 0x14) == 0) {
        uVar5 = (uint)(*(char *)(iVar2 + 0x1a1) == '\0');
        if (*(char *)(iVar2 + 0x1e0) != '\0') {
          uVar5 = uVar5 + 2;
        }
        if (*(int *)(uVar5 * 0x30 + 0x1c + *(int *)(param_1 + 0xc)) != 0) goto LAB_007a712e;
      }
      else {
LAB_007a712e:
        FUN_00790930();
        uVar7 = uStack_4;
        FUN_007929c0(uStack_4);
        FUN_007a6110(piVar1);
        FUN_00792840(unaff_ESI,piVar4[0x19],0xe);
        (**(code **)(*piVar4 + 0x18))(uVar8,iVar2,uVar7);
        if (*(char *)(param_1 + 0x9c) != '\0') {
          piVar1 = *(int **)(*(int *)(param_1 + 8) + 0x2c);
          (**(code **)(*piVar1 + 0xc0))(piVar1,0,param_1 + 0xa0);
        }
      }
    } while (piVar6 != (int *)0x0);
  }
  else {
    do {
      piVar4 = (int *)piVar6[2];
      piVar6 = (int *)*piVar6;
      iVar10 = *piVar4;
      piVar1 = *(int **)piVar4[3];
      FUN_00792b10(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0xd8),
                   *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xdc));
      FUN_007a5ed0(piVar4);
      (**(code **)(*piVar1 + 0x18))(iVar10,unaff_EBX,unaff_ESI);
    } while (piVar6 != (int *)0x0);
  }
  if (unaff_ESI != (int *)0x0) {
    (**(code **)(*unaff_ESI + 0x1c))(0,uVar8,uVar9,iVar10);
    if ((*(char *)((int)unaff_ESI + 0x36) != '\0') && (*(int *)(param_1 + 0x84) != 4)) {
      func_0x00779fc0(0,*(int *)(param_1 + 0x84));
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a7230 | Classified: Angelica3D::proc_7a7230 */
/* ==================================================================== */

undefined4 FUN_007a7230(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  int *unaff_ESI;
  int unaff_EDI;
  int *piVar5;
  
  piVar5 = *(int **)(param_2 + 0x4c);
  iVar1 = *(int *)(piVar5[2] + 4);
  piVar4 = (int *)(**(code **)(*(int *)**(undefined4 **)(piVar5[2] + 0xc) + 0x1c))();
  if (piVar4 == (int *)0x0) {
    func_0x0077aab0();
  }
  else {
    (**(code **)(*piVar4 + 0x18))(0);
  }
  do {
    puVar2 = (undefined4 *)piVar5[2];
    piVar5 = (int *)*piVar5;
    uVar3 = *puVar2;
    piVar4 = *(int **)puVar2[3];
    FUN_00792b10(*(undefined4 *)(*(int *)(unaff_EDI + 0xc) + 0xd8),
                 *(undefined4 *)(*(int *)(unaff_EDI + 0xc) + 0xdc));
    FUN_007a5ed0(puVar2);
    (**(code **)(*piVar4 + 0x18))(unaff_EDI,uVar3,unaff_ESI);
  } while (piVar5 != (int *)0x0);
  if (unaff_ESI != (int *)0x0) {
    (**(code **)(*unaff_ESI + 0x1c))(0);
    if ((*(char *)((int)unaff_ESI + 0x36) != '\0') && (iVar1 = *(int *)(iVar1 + 0x84), iVar1 != 4))
    {
      func_0x00779fc0(0,iVar1);
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a7300 | Classified: Angelica3D::proc_7a7300 */
/* ==================================================================== */

undefined4 FUN_007a7300(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  int *unaff_ESI;
  int unaff_EDI;
  int *piVar5;
  
  piVar5 = *(int **)(param_2 + 0xac);
  iVar1 = *(int *)(piVar5[2] + 4);
  piVar4 = (int *)(**(code **)(*(int *)**(undefined4 **)(piVar5[2] + 0xc) + 0x1c))();
  if (piVar4 == (int *)0x0) {
    func_0x0077aab0();
  }
  else {
    (**(code **)(*piVar4 + 0x18))(0);
  }
  do {
    puVar2 = (undefined4 *)piVar5[2];
    piVar5 = (int *)*piVar5;
    uVar3 = *puVar2;
    piVar4 = *(int **)puVar2[3];
    FUN_00792b10(*(undefined4 *)(*(int *)(unaff_EDI + 0xc) + 0xd8),
                 *(undefined4 *)(*(int *)(unaff_EDI + 0xc) + 0xdc));
    FUN_007a5ed0(puVar2);
    (**(code **)(*piVar4 + 0x18))(unaff_EDI,uVar3,unaff_ESI);
  } while (piVar5 != (int *)0x0);
  if (unaff_ESI != (int *)0x0) {
    (**(code **)(*unaff_ESI + 0x1c))(0);
    if ((*(char *)((int)unaff_ESI + 0x36) != '\0') && (iVar1 = *(int *)(iVar1 + 0x84), iVar1 != 4))
    {
      func_0x00779fc0(0,iVar1);
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a73e0 | Classified: Angelica3D::proc_7a73e0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a73e0(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *unaff_EBP;
  
  piVar6 = *(int **)(param_3 + 0x6c);
  piVar3 = (int *)(**(code **)(*(int *)**(undefined4 **)(piVar6[2] + 0xc) + 0x1c))
                            (*(undefined4 *)(piVar6[2] + 4));
  if (piVar3 == (int *)0x0) {
    func_0x0077aab0();
  }
  else {
    (**(code **)(*piVar3 + 0x18))(0);
  }
  do {
    piVar1 = (int *)piVar6[2];
    piVar6 = (int *)*piVar6;
    iVar2 = *piVar1;
    uVar5 = (uint)(*(char *)(iVar2 + 0x1a1) == '\0');
    if (*(char *)(iVar2 + 0x1e0) != '\0') {
      uVar5 = uVar5 + 2;
    }
    iVar4 = *(int *)piVar1[3];
    if (*(int *)(iVar4 + 4) == 0x1e) {
      iVar4 = *(int *)(iVar4 + 0xb4) + 2;
    }
    else {
      iVar4 = *(int *)(iVar4 + 0x94) + 7;
    }
    if (*(int *)(*(int *)(param_1 + 0xc) + 0x18 + (iVar4 + uVar5 * 0xc) * 4) != 0) {
      FUN_00790930();
      FUN_007929c0(param_1);
      FUN_007a6110(piVar1);
      (**(code **)(**(int **)piVar1[3] + 0x18))(unaff_EBP,iVar2,piVar3);
    }
  } while (piVar6 != (int *)0x0);
  if (unaff_EBP != (int *)0x0) {
    (**(code **)(*unaff_EBP + 0x1c))(0);
    if ((*(char *)((int)unaff_EBP + 0x36) != '\0') && (*(int *)(param_1 + 0x84) != 4)) {
      func_0x00779fc0(0,*(int *)(param_1 + 0x84));
    }
  }
  func_0x0077bad0();
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a74f0 | Classified: Angelica3D::proc_7a74f0 */
/* ==================================================================== */

undefined4 FUN_007a74f0(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  int *unaff_ESI;
  int unaff_EDI;
  int *piVar5;
  
  piVar5 = *(int **)(param_2 + 0x6c);
  iVar1 = *(int *)(piVar5[2] + 4);
  piVar4 = (int *)(**(code **)(*(int *)**(undefined4 **)(piVar5[2] + 0xc) + 0x1c))();
  if (piVar4 == (int *)0x0) {
    func_0x0077aab0();
  }
  else {
    (**(code **)(*piVar4 + 0x18))(0);
  }
  do {
    puVar2 = (undefined4 *)piVar5[2];
    piVar5 = (int *)*piVar5;
    uVar3 = *puVar2;
    piVar4 = *(int **)puVar2[3];
    FUN_00792b10(*(undefined4 *)(*(int *)(unaff_EDI + 0xc) + 0xd8),
                 *(undefined4 *)(*(int *)(unaff_EDI + 0xc) + 0xdc));
    FUN_007a5ed0(puVar2);
    (**(code **)(*piVar4 + 0x18))(unaff_EDI,uVar3,unaff_ESI);
  } while (piVar5 != (int *)0x0);
  if (unaff_ESI != (int *)0x0) {
    (**(code **)(*unaff_ESI + 0x1c))(0);
    if ((*(char *)((int)unaff_ESI + 0x36) != '\0') && (iVar1 = *(int *)(iVar1 + 0x84), iVar1 != 4))
    {
      func_0x00779fc0(0,iVar1);
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a75c0 | Classified: Angelica3D::proc_7a75c0 */
/* ==================================================================== */

undefined4 FUN_007a75c0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  int *unaff_EDI;
  int *piVar5;
  
  func_0x00779ca0();
  piVar5 = *(int **)(param_1 + 0x8c);
  iVar1 = *(int *)(piVar5[2] + 4);
  piVar4 = (int *)(**(code **)(*(int *)**(undefined4 **)(piVar5[2] + 0xc) + 0x1c))();
  if (piVar4 == (int *)0x0) {
    func_0x0077aab0();
  }
  else {
    (**(code **)(*piVar4 + 0x18))(0);
  }
  do {
    puVar2 = (undefined4 *)piVar5[2];
    piVar5 = (int *)*piVar5;
    uVar3 = *puVar2;
    piVar4 = *(int **)puVar2[3];
    FUN_00792b10(*(undefined4 *)(iRam009d2f34 + 0xd8),*(undefined4 *)(iRam009d2f34 + 0xdc));
    FUN_007a5ed0(puVar2);
    (**(code **)(*piVar4 + 0x18))(0x9d2f28,uVar3,unaff_EDI);
  } while (piVar5 != (int *)0x0);
  if (unaff_EDI != (int *)0x0) {
    (**(code **)(*unaff_EDI + 0x1c))(0);
    if ((*(char *)((int)unaff_EDI + 0x36) != '\0') && (iVar1 = *(int *)(iVar1 + 0x84), iVar1 != 4))
    {
      func_0x00779fc0(0,iVar1);
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a76a0 | Classified: Angelica3D::proc_7a76a0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a76a0(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined1 uVar7;
  int iVar8;
  uint uVar9;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  undefined4 uVar10;
  undefined4 uVar11;
  int *piStack_10;
  undefined4 *puStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  piStack_10 = (int *)0x0;
  uStack_8 = 0xffffffff;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x28c);
  uVar7 = func_0x0077a340();
  uStack_4 = CONCAT31(uStack_4._1_3_,uVar7);
  puVar6 = *(undefined4 **)(param_1 + 0x60);
  do {
    if (puVar6 == (undefined4 *)0x0) {
      if (((piStack_10 != (int *)0x0) &&
          ((**(code **)(*piStack_10 + 0x1c))(0), *(char *)((int)piStack_10 + 0x36) != '\0')) &&
         (*(int *)(param_1 + 0x84) != 4)) {
        func_0x00779fc0(0,*(int *)(param_1 + 0x84));
      }
      func_0x0077bad0();
      func_0x0077a2c0(5);
      func_0x0077a2f0(6);
      func_0x0077a320(puStack_c);
      return 1;
    }
    piVar2 = (int *)puVar6[2];
    puStack_c = (undefined4 *)*puVar6;
    iVar3 = *piVar2;
    FUN_007a85d0(&piStack_10,&uStack_8,piVar2);
    func_0x0077a2c0(*(undefined4 *)(iVar3 + 0x2a4));
    func_0x0077a2f0(*(undefined4 *)(iVar3 + 0x2a8));
    if (*(char *)(iVar3 + 0x2ac) != '\0') {
      func_0x0077a320(1);
    }
    piVar4 = *(int **)piVar2[3];
    switch(piVar4[1]) {
    case 0x1c:
      if (iVar1 == 0) {
        if ((char)((int *)piVar2[3])[2] == '\0') {
          if (*(char *)(param_1 + 0x9c) != '\0') {
            piVar5 = *(int **)(*(int *)(param_1 + 8) + 0x2c);
            (**(code **)(*piVar5 + 0xc0))(piVar5,0,param_1 + 0xb0);
          }
          if (*(int *)(piVar2[3] + 0x14) == 0) {
            uVar9 = (uint)(*(char *)(iVar3 + 0x1a1) == '\0');
            if (*(char *)(iVar3 + 0x1e0) != '\0') {
              uVar9 = uVar9 + 2;
            }
            if (*(int *)(uVar9 * 0x30 + 0x18 + *(int *)(param_1 + 0xc)) == 0) break;
          }
          FUN_00790930();
          FUN_007929c0(param_2);
          FUN_007a6110(piVar2);
          (**(code **)(*piVar4 + 0x18))(uStack_4,iVar3,unaff_EBX);
          if (*(char *)(param_1 + 0x9c) != '\0') {
            piVar2 = *(int **)(*(int *)(param_1 + 8) + 0x2c);
            (**(code **)(*piVar2 + 0xc0))(piVar2,0,param_1 + 0xa0);
          }
        }
        else {
          FUN_00792b10(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0xd8),
                       *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xdc));
          FUN_007a5ed0(piVar2);
          (**(code **)(*piVar4 + 0x34))(uStack_8,iVar3,unaff_EBP);
        }
      }
      else if (iVar1 == 1) {
        uVar10 = 1;
        func_0x0077b920(1);
        func_0x0077b9a0(3);
        FUN_00792b10(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0xd8),
                     *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xdc));
        FUN_007a5ed0(piVar2);
        (**(code **)(*piVar4 + 0x18))(piStack_10,iVar3,uVar10);
        func_0x0077b920(0);
        func_0x0077b9a0(0);
      }
      else if (iVar1 == 2) {
        func_0x00779ca0(0x9d2f28);
        goto code_r0x007a777d;
      }
      break;
    case 0x1d:
      if (iVar1 != 0) goto code_r0x007a7a39;
      if (*(char *)(param_1 + 0x9c) != '\0') {
        piVar5 = *(int **)(*(int *)(param_1 + 8) + 0x2c);
        (**(code **)(*piVar5 + 0xc0))(piVar5,0,param_1 + 0xb0);
      }
      if (*(int *)(piVar2[3] + 0x14) == 0) {
        uVar9 = (uint)(*(char *)(iVar3 + 0x1a1) == '\0');
        if (*(char *)(iVar3 + 0x1e0) != '\0') {
          uVar9 = uVar9 + 2;
        }
        if (*(int *)(uVar9 * 0x30 + 0x1c + *(int *)(param_1 + 0xc)) == 0) break;
      }
      FUN_00790930();
      uVar11 = param_2;
      FUN_007929c0(param_2);
      FUN_007a6110(piVar2);
      uVar10 = uStack_4;
      FUN_00792840(uStack_4,piVar4[0x19],0xe);
      (**(code **)(*piVar4 + 0x18))(uVar10,iVar3,uVar11);
      if (*(char *)(param_1 + 0x9c) != '\0') {
        piVar2 = *(int **)(*(int *)(param_1 + 8) + 0x2c);
        (**(code **)(*piVar2 + 0xc0))(piVar2,0,param_1 + 0xa0);
      }
      break;
    case 0x1e:
    case 0x1f:
      if (iVar1 == 0) {
        FUN_007929c0(param_2);
        uVar9 = (uint)(*(char *)(iVar3 + 0x1a1) == '\0');
        if (*(char *)(iVar3 + 0x1e0) != '\0') {
          uVar9 = uVar9 + 2;
        }
        iVar8 = *(int *)piVar2[3];
        if (*(int *)(iVar8 + 4) == 0x1e) {
          iVar8 = *(int *)(iVar8 + 0xb4) + 2;
        }
        else {
          iVar8 = *(int *)(iVar8 + 0x94) + 7;
        }
        if (*(int *)(*(int *)(param_1 + 0xc) + 0x18 + (iVar8 + uVar9 * 0xc) * 4) != 0) {
          FUN_00790930();
          FUN_007a6110(piVar2);
          (**(code **)(**(int **)piVar2[3] + 0x18))(unaff_retaddr,iVar3,unaff_ESI);
        }
      }
      else {
code_r0x007a777d:
        FUN_00792b10(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0xd8),
                     *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xdc));
        FUN_007a5ed0(piVar2);
        (**(code **)(*piVar4 + 0x18))(uStack_8,iVar3,unaff_EBP);
      }
      break;
    case 0x24:
    case 0x2a:
    case 0x2b:
code_r0x007a7a39:
      FUN_00792b10(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0xd8),
                   *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xdc));
      FUN_007a5ed0(piVar2);
      (**(code **)(*piVar4 + 0x18))(uStack_8,iVar3,unaff_EBP);
    }
    puVar6 = puStack_c;
  } while( true );
}


/* ==================================================================== */
/* Address: 0x007a7b30 | Classified: Angelica3D::proc_7a7b30 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a7b30(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined3 uVar6;
  undefined3 extraout_var;
  int iVar7;
  undefined4 unaff_ESI;
  uint unaff_retaddr;
  undefined4 uVar8;
  char cVar9;
  undefined4 auStack_f8 [4];
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 auStack_94 [5];
  undefined1 auStack_80 [48];
  undefined1 auStack_50 [80];
  
  uVar6 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 0xd8);
    if (iVar2 != 0) {
      uStack_e8 = *(undefined4 *)(iVar2 + 0x10);
      uStack_e4 = *(undefined4 *)(iVar2 + 0x14);
      uStack_e0 = *(undefined4 *)(iVar2 + 0x18);
      uStack_dc = *(undefined4 *)(iVar2 + 0x1c);
      uStack_d8 = *(undefined4 *)(iVar2 + 0x20);
      func_0x00410950(iVar2 + 0x24);
      func_0x00410950(iVar2 + 0x34);
      func_0x00401cc0(iVar2 + 0x44);
      func_0x00401cc0(iVar2 + 0x50);
      uStack_9c = *(undefined4 *)(iVar2 + 0x5c);
      uStack_98 = *(undefined4 *)(iVar2 + 0x60);
      auStack_94[0] = *(undefined4 *)(iVar2 + 100);
      auStack_94[1] = *(undefined4 *)(iVar2 + 0x68);
      auStack_94[2] = *(undefined4 *)(iVar2 + 0x6c);
      auStack_94[3] = *(undefined4 *)(iVar2 + 0x70);
      auStack_94[4] = *(undefined4 *)(iVar2 + 0x74);
    }
    if (*(int *)(*(int *)(param_1 + 0xc) + 0xdc) != 0) {
      FUN_0079b340();
    }
    if (*(int *)(param_1 + 0x84) != 4) {
      func_0x00779fc0(0,*(int *)(param_1 + 0x84));
    }
    if (*(int *)(*(int *)(param_1 + 8) + 0x28c) == 0) {
      func_0x007873a0(auStack_80,*(int *)(param_2 + 0x30) + 0xa8,*(int *)(param_2 + 0x30) + 0x128);
      func_0x007874a0();
      func_0x0077ba40(2,auStack_80,4);
      auStack_f8[0] = 0;
      func_0x0077ba40(6,&stack0xfffffefc,1);
      FUN_007929c0(param_2);
    }
    if ((*(int *)(param_3 + 0x2a4) != 5) || (*(int *)(param_3 + 0x2a8) != 6)) {
      func_0x0077a2c0(*(int *)(param_3 + 0x2a4));
      func_0x0077a2f0(*(undefined4 *)(param_3 + 0x2a8));
      func_0x0077a290(1);
    }
    uVar8 = 0;
    uVar5 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x168);
    *(undefined1 *)(param_1 + 0x9c) = 0;
    *(undefined4 *)(param_1 + 0x98) = uVar5;
    iVar2 = func_0x0077bd50();
    if (iVar2 == 1) {
      *(undefined1 *)(param_1 + 0x9c) = 1;
      piVar1 = *(int **)(*(int *)(param_1 + 8) + 0x2c);
      (**(code **)(*piVar1 + 0xc4))(piVar1,0,param_1 + 0xa0);
      puVar4 = auStack_94 + 1;
      puVar3 = (undefined4 *)(*(int *)(param_2 + 0x30) + 0xe8);
      iVar2 = 4;
      do {
        iVar7 = 4;
        do {
          uVar5 = *puVar3;
          puVar3 = puVar3 + 1;
          *puVar4 = uVar5;
          puVar4 = puVar4 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      puVar4 = (undefined4 *)func_0x00787610(auStack_50);
      puVar3 = auStack_94;
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
      func_0x007874a0();
      func_0x007f6774(param_1 + 0xb0,param_1 + 0xa0,auStack_94);
      param_2 = unaff_retaddr;
    }
    FUN_00792b10(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0xd8),
                 *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xdc));
    if ((unaff_retaddr & 1) != 0) {
      func_0x0077aab0(0);
    }
    iVar2 = 0;
    if (0 < *(int *)(param_3 + 0xec)) {
      do {
        FUN_007a7eb0(param_2,param_3,iVar2,unaff_retaddr);
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(param_3 + 0xec));
    }
    iVar2 = 0;
    do {
      func_0x0077b9c0(iVar2);
      cVar9 = (char)((uint)uVar8 >> 0x18);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 5);
    func_0x0077a450(unaff_ESI);
    if (*(int *)(*(int *)(param_1 + 0xc) + 0xd8) != 0) {
      FUN_0079b390(auStack_f8);
    }
    if (*(int *)(*(int *)(param_1 + 0xc) + 0xdc) != 0) {
      FUN_0079b370();
    }
    if (*(int *)(param_1 + 0x84) != 4) {
      func_0x00779fc0(0,4);
    }
    uVar5 = func_0x0077a540(*(undefined4 *)(param_1 + 0x98));
    uVar6 = (undefined3)((uint)uVar5 >> 8);
    if (cVar9 != '\0') {
      func_0x0077a2c0(5);
      func_0x0077a2f0(6);
      func_0x0077a290(0);
      uVar6 = extraout_var;
    }
  }
  return CONCAT31(uVar6,1);
}


/* ==================================================================== */
/* Address: 0x007a7eb0 | Classified: Angelica3D::proc_7a7eb0 */
/* ==================================================================== */

/* WARNING: Type propagation algorithm not settling */

undefined4 __thiscall FUN_007a7eb0(int param_1,uint param_2,int param_3,int param_4,uint param_5)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int **ppiVar8;
  undefined4 *puVar9;
  undefined8 uVar10;
  int iVar11;
  int iStack_244;
  int iStack_240;
  int iStack_23c;
  int *piStack_238;
  int *piStack_234;
  int iStack_230;
  int *piStack_22c;
  int *apiStack_228 [2];
  char cStack_21f;
  int *piStack_220;
  uint uStack_21c;
  char cStack_218;
  char cStack_217;
  undefined4 uStack_214;
  int iStack_210;
  undefined4 uStack_20c;
  uint auStack_208 [126];
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  uint uStack_4;
  
  piVar1 = *(int **)(*(int *)(param_3 + 0xe8) + param_4 * 4);
  iVar5 = CONCAT31((int3)((uint)param_3 >> 8),*(char *)((int)piVar1 + 5));
  if ((*(char *)((int)piVar1 + 5) != '\0') && (*piVar1 != 0)) {
    iVar5 = *(int *)(param_1 + 4);
    uVar10 = FUN_00766250();
    *(undefined8 *)(iVar5 + 0x580) = uVar10;
    piVar1 = (int *)*piVar1;
    iStack_23c = 0;
    auStack_208[1] = *(uint *)(*(int *)(param_1 + 8) + 0x28c);
    iStack_230 = param_3;
    apiStack_228[1] = (int *)&stack0xfffffde0;
    piStack_238 = (int *)0x0;
    piStack_234 = (int *)0xffffffff;
    piStack_220 = (int *)0x0;
    uStack_21c = 0;
    cStack_218 = '\0';
    cStack_217 = '\0';
    iStack_210 = 0;
    uStack_214 = 0xbf800000;
    uStack_20c = 0;
    auStack_208[0] = 0;
    iVar5 = piVar1[0x2b];
    piStack_22c = piVar1;
    if (iVar5 != 0) {
      if (auStack_208[1] == 0) {
        if (0 < iVar5) {
          iStack_240 = 0;
          iStack_244 = iVar5;
          do {
            puVar7 = (undefined4 *)(piVar1[0x2a] + iStack_240);
            puVar9 = &stack0xfffffde0;
            for (iVar5 = 7; piVar3 = piStack_220, iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar9 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar9 = puVar9 + 1;
            }
            if (cStack_217 == '\0') {
              if ((uStack_21c == 0) || (*(char *)((int)piVar1 + 0x29) == '\0')) {
                if ((param_5 & 1) == 0) {
                  FUN_007a85d0(&piStack_238,&piStack_234,&iStack_230);
                }
                if (cStack_218 == '\0') {
                  FUN_007a86a0(&iStack_230,param_5,1);
                  if (*(char *)(param_1 + 0x9c) != '\0') {
                    piVar2 = *(int **)(*(int *)(param_1 + 8) + 0x2c);
                    (**(code **)(*piVar2 + 0xc0))(piVar2,0,param_1 + 0xb0);
                  }
                  if (apiStack_228[1][5] == 0) {
                    uVar4 = (uint)(*(char *)(param_3 + 0x1a1) == '\0');
                    if (*(char *)(param_3 + 0x1e0) != '\0') {
                      uVar4 = uVar4 + 2;
                    }
                    if (*(int *)(uVar4 * 0x30 + 0x18 + *(int *)(param_1 + 0xc)) == 0)
                    goto LAB_007a80c2;
                  }
                  FUN_00790930();
                  (**(code **)(*piVar3 + 0x18))(param_2,param_3,piVar1);
                  if (*(char *)(param_1 + 0x9c) != '\0') {
                    piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x2c);
                    (**(code **)(*piVar3 + 0xc0))(piVar3,0,param_1 + 0xa0);
                  }
                }
                else {
                  FUN_007a86a0(&iStack_230,param_5,0);
                  (**(code **)(*piVar3 + 0x34))(uStack_8,uStack_4,piVar1);
                }
              }
              else {
                auStack_208[iStack_23c + 2] = uStack_21c;
                iStack_23c = iStack_23c + 1;
              }
            }
LAB_007a80c2:
            iStack_240 = iStack_240 + 0x1c;
            iStack_244 = iStack_244 + -1;
          } while (iStack_244 != 0);
          iStack_244 = 0;
        }
      }
      else if (auStack_208[1] == 1) {
        func_0x0077b920(1);
        func_0x0077b9a0(3);
        iVar5 = 0;
        if (0 < piVar1[0x2b]) {
          iVar11 = 0;
          do {
            puVar7 = (undefined4 *)(piVar1[0x2a] + iVar11);
            ppiVar8 = apiStack_228;
            for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
              *ppiVar8 = (int *)*puVar7;
              puVar7 = puVar7 + 1;
              ppiVar8 = ppiVar8 + 1;
            }
            if (cStack_21f == '\0') {
              if ((apiStack_228[1] == (undefined4 *)0x0) || (*(char *)((int)piVar1 + 0x29) == '\0'))
              {
                FUN_007a86a0(&piStack_238,param_3,0);
                if ((uStack_4 & 1) == 0) {
                  FUN_007a85d0(&stack0xfffffdb4,&stack0xfffffdb8,&iStack_244);
                }
                (**(code **)(*piStack_234 + 0x18))(uStack_10,uStack_c,piVar1);
              }
              else {
                auStack_208[iStack_244] = (uint)apiStack_228[1];
                iStack_244 = iStack_244 + 1;
              }
            }
            iVar5 = iVar5 + 1;
            iVar11 = iVar11 + 0x1c;
          } while (iVar5 < piVar1[0x2b]);
        }
        func_0x0077b920(0);
        func_0x0077b9a0(0);
      }
      else if (auStack_208[1] == 2) {
        func_0x00779ca0(0x9d2f28);
        iStack_240 = 0;
        if (0 < piVar1[0x2b]) {
          iStack_244 = 0;
          do {
            puVar7 = (undefined4 *)(piVar1[0x2a] + iStack_244);
            puVar9 = &stack0xfffffde0;
            for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar9 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar9 = puVar9 + 1;
            }
            if (cStack_217 == '\0') {
              if ((uStack_21c == 0) || (*(char *)((int)piVar1 + 0x29) == '\0')) {
                FUN_007a86a0(&iStack_230,param_5,0);
                if ((param_2 & 1) == 0) {
                  FUN_007a85d0(&iStack_244,&iStack_240,&iStack_23c);
                }
                (**(code **)(*piStack_22c + 0x18))(uStack_8,uStack_4,piVar1);
              }
              else {
                auStack_208[iStack_23c + 2] = uStack_21c;
                iStack_23c = iStack_23c + 1;
              }
            }
            iStack_240 = iStack_240 + 1;
            iStack_244 = iStack_244 + 0x1c;
          } while (iStack_240 < piVar1[0x2b]);
        }
      }
    }
    iVar5 = piVar1[0x30];
    if (iVar5 != 0) {
      if (auStack_208[1] == 0) {
        if (0 < iVar5) {
          iStack_244 = 0;
          iStack_240 = iVar5;
          do {
            puVar7 = (undefined4 *)(piVar1[0x2f] + iStack_244);
            puVar9 = &stack0xfffffde0;
            for (iVar5 = 7; piVar3 = piStack_220, iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar9 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar9 = puVar9 + 1;
            }
            if (cStack_217 == '\0') {
              if ((uStack_21c == 0) || (*(char *)((int)piVar1 + 0x29) == '\0')) {
                FUN_007a86a0(&iStack_230,param_5,1);
                if ((param_5 & 1) == 0) {
                  FUN_007a85d0(&piStack_238,&piStack_234,&iStack_230);
                }
                if (*(char *)(param_1 + 0x9c) != '\0') {
                  piVar2 = *(int **)(*(int *)(param_1 + 8) + 0x2c);
                  (**(code **)(*piVar2 + 0xc0))(piVar2,0,param_1 + 0xb0);
                }
                if (apiStack_228[1][5] == 0) {
                  uVar4 = (uint)(*(char *)(param_3 + 0x1a1) == '\0');
                  if (*(char *)(param_3 + 0x1e0) != '\0') {
                    uVar4 = uVar4 + 2;
                  }
                  if (*(int *)(uVar4 * 0x30 + 0x1c + *(int *)(param_1 + 0xc)) == 0)
                  goto LAB_007a840a;
                }
                FUN_00790930();
                FUN_00792840(param_2,piVar3[0x19],0xe);
                (**(code **)(*piVar3 + 0x18))(uStack_8,param_3,piVar1);
                if (*(char *)(param_1 + 0x9c) != '\0') {
                  piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x2c);
                  (**(code **)(*piVar3 + 0xc0))(piVar3,0,param_1 + 0xa0);
                }
              }
              else {
                auStack_208[iStack_23c + 2] = uStack_21c;
                iStack_23c = iStack_23c + 1;
              }
            }
LAB_007a840a:
            iStack_244 = iStack_244 + 0x1c;
            iStack_240 = iStack_240 + -1;
          } while (iStack_240 != 0);
          iStack_240 = 0;
        }
      }
      else if (0 < iVar5) {
        iStack_244 = 0;
        iStack_240 = iVar5;
        do {
          puVar7 = (undefined4 *)(piVar1[0x2f] + iStack_244);
          puVar9 = &stack0xfffffde0;
          for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar9 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar9 = puVar9 + 1;
          }
          if (cStack_217 == '\0') {
            if ((uStack_21c == 0) || (*(char *)((int)piVar1 + 0x29) == '\0')) {
              FUN_007a86a0(&iStack_230,param_5,0);
              if ((param_2 & 1) == 0) {
                FUN_007a85d0(&iStack_244,&iStack_240,&iStack_23c);
              }
              (**(code **)(*piStack_22c + 0x18))(uStack_8,uStack_4,piVar1);
            }
            else {
              auStack_208[iStack_23c + 2] = uStack_21c;
              iStack_23c = iStack_23c + 1;
            }
          }
          iStack_244 = iStack_244 + 0x1c;
          iStack_240 = iStack_240 + -1;
        } while (iStack_240 != 0);
      }
    }
    iVar5 = 0;
    if (0 < iStack_23c) {
      auStack_208[1] = param_5 & 1;
      do {
        piVar3 = (int *)auStack_208[iVar5 + 2];
        FUN_00792b10(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0xd8),
                     *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xdc));
        FUN_007a5ed0(&piStack_238);
        if (iStack_210 == 0) {
          FUN_007a85d0(&iStack_244,&iStack_240,&iStack_23c);
        }
        (**(code **)(*piVar3 + 0x18))(uStack_8,uStack_4,piVar1);
        iVar5 = iVar5 + 1;
      } while (iVar5 < iStack_23c);
    }
    if (((piStack_238 != (int *)0x0) &&
        ((**(code **)(*piStack_238 + 0x1c))(0), *(char *)((int)piStack_238 + 0x36) != '\0')) &&
       (*(int *)(param_1 + 0x84) != 4)) {
      func_0x00779fc0(0,*(int *)(param_1 + 0x84));
    }
    iVar11 = *(int *)(param_1 + 4);
    iVar5 = FUN_00766250();
    iVar5 = iVar5 - *(int *)(iVar11 + 0x580);
    *(int *)(iVar11 + 0x588) = *(int *)(iVar11 + 0x588) + iVar5;
  }
  return CONCAT31((int3)((uint)iVar5 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007a85d0 | Classified: Angelica3D::proc_7a85d0 */
/* ==================================================================== */

void __thiscall FUN_007a85d0(int param_1,int *param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  int *unaff_retaddr;
  
  piVar1 = (int *)*param_2;
  piVar2 = (int *)(**(code **)(*(int *)**(undefined4 **)(param_4 + 0xc) + 0x1c))
                            (*(undefined4 *)(param_4 + 4));
  if (piVar2 == (int *)0x0) {
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x1c))(0);
      if ((*(char *)((int)piVar1 + 0x36) != '\0') && (*(int *)(param_1 + 0x84) != 4)) {
        func_0x00779fc0(0,*(int *)(param_1 + 0x84));
      }
    }
    func_0x0077aab0(0);
    *param_2 = 0;
    *unaff_retaddr = -1;
    return;
  }
  if (*param_2 != piVar2[10]) {
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x1c))(0);
      if ((*(char *)((int)piVar1 + 0x36) != '\0') && (*(int *)(param_1 + 0x84) != 4)) {
        func_0x00779fc0(0,*(int *)(param_1 + 0x84));
      }
    }
    (**(code **)(*piVar2 + 0x18))(0);
    *param_2 = (int)piVar2;
    *unaff_retaddr = piVar2[10];
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007a86a0 | Classified: Angelica3D::proc_7a86a0 */
/* ==================================================================== */

void FUN_007a86a0(int param_1,byte param_2,char param_3)

{
  if ((param_2 & 4) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xc) = 0xbf800000;
  }
  if ((param_2 & 2) != 0) {
    if (param_3 != '\0') {
      FUN_007a6520();
      return;
    }
    FUN_007a6420(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0xc));
    return;
  }
  if (param_3 != '\0') {
    FUN_007a6110();
    return;
  }
  FUN_007a5ed0(param_1);
  return;
}


/* ==================================================================== */
/* Address: 0x007a8700 | Classified: Angelica3D::proc_7a8700 */
/* ==================================================================== */

void __thiscall FUN_007a8700(undefined4 *param_1,undefined4 param_2)

{
  param_1[1] = &UNK_008d649c;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = param_2;
  param_1[7] = 0;
  *param_1 = &UNK_008f1924;
  return;
}


/* ==================================================================== */
/* Address: 0x007a8730 | Classified: Angelica3D::proc_7a8730 */
/* ==================================================================== */

void __fastcall FUN_007a8730(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  *param_1 = &UNK_008f1924;
  puVar1 = (undefined4 *)param_1[2];
  param_1[1] = &UNK_008d649c;
  while (puVar1 != (undefined4 *)0x0) {
    param_1[2] = *puVar1;
    *puVar1 = param_1[4];
    param_1[4] = puVar1;
    puVar1 = (undefined4 *)param_1[2];
    param_1[5] = param_1[5] + -1;
  }
  puVar1 = (undefined4 *)param_1[7];
  param_1[3] = 0;
  param_1[5] = 0;
  while (puVar1 != (undefined4 *)0x0) {
    param_1[7] = puVar1[1];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    puVar1 = (undefined4 *)param_1[7];
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007a8790 | Classified: Angelica3D::proc_7a8790 */
/* ==================================================================== */

void __fastcall FUN_007a8790(undefined4 *param_1)

{
  *param_1 = &UNK_008f192c;
  param_1[1] = &UNK_008d5a30;
  if (param_1[2] != 0) {
    func_0x00763260(param_1[2]);
    param_1[2] = 0;
  }
  param_1[4] = 0;
  param_1[3] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007a87c0 | Classified: Angelica3D::proc_7a87c0 */
/* ==================================================================== */

void __fastcall FUN_007a87c0(undefined4 *param_1)

{
  *param_1 = &UNK_008f1928;
  param_1[1] = &UNK_008d5a30;
  if (param_1[2] != 0) {
    func_0x00763260(param_1[2]);
    param_1[2] = 0;
  }
  param_1[4] = 0;
  param_1[3] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007a87f0 | Classified: Angelica3D::proc_7a87f0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a87f0(undefined4 param_1,byte param_2)

{
  FUN_007a8730();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007a8810 | Classified: Angelica3D::proc_7a8810 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a8810(undefined4 param_1,byte param_2)

{
  FUN_007a8790();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007a8830 | Classified: Angelica3D::proc_7a8830 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a8830(undefined4 param_1,byte param_2)

{
  FUN_007a87c0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007a8850 | Classified: elementclient::AArray__Allocate__Not_enough_mem@0x7a8850 */
/* ==================================================================== */

undefined4 * __fastcall FUN_007a8850(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd6c6;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1[0xd] = &UNK_008d5a30;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0x20;
  iVar1 = func_0x00763250(0x200);
  if (iVar1 == 0) {
    func_0x00764590(1,0x94e51c);
  }
  else {
    iVar2 = 0;
    if (0 < (int)param_1[0xf]) {
      do {
        iVar2 = iVar2 + 1;
        *(undefined4 *)(iVar1 + -4 + iVar2 * 4) = *(undefined4 *)(param_1[0xe] + -4 + iVar2 * 4);
      } while (iVar2 < (int)param_1[0xf]);
    }
    if (param_1[0xe] != 0) {
      func_0x00763260(param_1[0xe]);
    }
    param_1[0xe] = iVar1;
    param_1[0x10] = 0x80;
  }
  param_1[0xc] = &UNK_008f19b0;
  uStack_4 = 0;
  param_1[0x13] = &UNK_008d5a30;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0x20;
  iVar1 = func_0x00763250(0x200);
  if (iVar1 == 0) {
    func_0x00764590(1,0x94e51c);
  }
  else {
    iVar2 = 0;
    if (0 < (int)param_1[0x15]) {
      do {
        iVar2 = iVar2 + 1;
        *(undefined4 *)(iVar1 + -4 + iVar2 * 4) = *(undefined4 *)(param_1[0x14] + -4 + iVar2 * 4);
      } while (iVar2 < (int)param_1[0x15]);
    }
    if (param_1[0x14] != 0) {
      func_0x00763260(param_1[0x14]);
    }
    param_1[0x14] = iVar1;
    param_1[0x16] = 0x80;
  }
  param_1[0x12] = &UNK_008f19ac;
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  param_1[0x19] = &UNK_008d5a30;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0x20;
  iVar1 = func_0x00763250(0x200);
  if (iVar1 == 0) {
    func_0x00764590(1,0x94e51c);
  }
  else {
    iVar2 = 0;
    if (0 < (int)param_1[0x1b]) {
      do {
        iVar2 = iVar2 + 1;
        *(undefined4 *)(iVar1 + -4 + iVar2 * 4) = *(undefined4 *)(param_1[0x1a] + -4 + iVar2 * 4);
      } while (iVar2 < (int)param_1[0x1b]);
    }
    if (param_1[0x1a] != 0) {
      func_0x00763260(param_1[0x1a]);
    }
    param_1[0x1a] = iVar1;
    param_1[0x1c] = 0x80;
  }
  param_1[0x18] = &UNK_008f19ac;
  *param_1 = &UNK_008f19a8;
  param_1[5] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[0x1e] = 0;
  param_1[0xb] = 0;
  *(undefined1 *)(param_1 + 6) = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007a8a20 | Classified: Angelica3D::proc_7a8a20 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a8a20(undefined4 param_1,byte param_2)

{
  FUN_007a8a40();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007a8a40 | Classified: Angelica3D::proc_7a8a40 */
/* ==================================================================== */

void __fastcall FUN_007a8a40(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  uint uStack_4;
  
  puStack_8 = &UNK_008cd6e6;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f19a8;
  param_1[0x18] = &UNK_008f19ac;
  uStack_4 = 1;
  param_1[0x19] = &UNK_008d5a30;
  if (param_1[0x1a] != 0) {
    func_0x00763260(param_1[0x1a]);
    param_1[0x1a] = 0;
  }
  param_1[0x1c] = 0;
  param_1[0x1b] = 0;
  param_1[0x12] = &UNK_008f19ac;
  uStack_4 = uStack_4 & 0xffffff00;
  param_1[0x13] = &UNK_008d5a30;
  if (param_1[0x14] != 0) {
    func_0x00763260(param_1[0x14]);
    param_1[0x14] = 0;
  }
  param_1[0x16] = 0;
  param_1[0x15] = 0;
  param_1[0xc] = &UNK_008f19b0;
  uStack_4 = 0xffffffff;
  param_1[0xd] = &UNK_008d5a30;
  if (param_1[0xe] != 0) {
    func_0x00763260(param_1[0xe]);
    param_1[0xe] = 0;
  }
  param_1[0x10] = 0;
  param_1[0xf] = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x007a8b00 | Classified: elementclient::A3DLitModelRender__Init____faile@0x7a8b00 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a8b00(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uStack_58;
  
  *(int *)(param_1 + 0x24) = param_2;
  uStack_58 = param_4;
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_2 + 0x50);
  cVar1 = FUN_007a8ba0(param_3);
  if (cVar1 == '\0') {
    func_0x007647d0(0x9d2f20,0x98d89c);
    return 0;
  }
  uStack_58 = 0x20000000;
  uVar2 = func_0x00786360(0x98d87c,0,&uStack_58);
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a8ba0 | Classified: elementclient::A3DLitModelRender__CreateStream_@0x7a8ba0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a8ba0(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar4;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd6fb;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_007a8c70();
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_3;
  iVar2 = func_0x00763250(0x48);
  uStack_4 = 0;
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = func_0x00784d70();
  }
  uVar4 = 0x24;
  uStack_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x14) = uVar3;
  cVar1 = func_0x00784f10(*(undefined4 *)(param_1 + 0x28),0x24,0x152,*(undefined4 *)(param_1 + 4),
                          *(undefined4 *)(param_1 + 8),2,2);
  if (cVar1 == '\0') {
    func_0x007647d0(0x9d2f20,0x98d8d0);
    *unaff_FS_OFFSET = uVar4;
    return 0;
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *unaff_FS_OFFSET = uVar4;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a8c70 | Classified: Angelica3D::proc_7a8c70 */
/* ==================================================================== */

undefined4 __fastcall FUN_007a8c70(int param_1)

{
  if (*(int *)(param_1 + 0x14) != 0) {
    func_0x00785220();
    if (*(undefined4 **)(param_1 + 0x14) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x14))(1);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a8cb0 | Classified: Angelica3D::proc_7a8cb0 */
/* ==================================================================== */

void __fastcall FUN_007a8cb0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x3c)) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x38) + iVar2 * 4);
      if (iVar1 != 0) {
        FUN_007a8d40();
        func_0x00763260(iVar1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x3c));
  }
  if (*(int *)(param_1 + 0x38) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x38));
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  FUN_007a8c70();
  if (*(int *)(param_1 + 0x20) != 0) {
    func_0x007866f0((undefined4 *)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007a8d40 | Classified: Angelica3D::proc_7a8d40 */
/* ==================================================================== */

void __fastcall FUN_007a8d40(int param_1)

{
  *(undefined **)(param_1 + 0xe8) = &UNK_008f19ac;
  *(undefined **)(param_1 + 0xec) = &UNK_008d5a30;
  if (*(int *)(param_1 + 0xf0) != 0) {
    func_0x00763260(*(int *)(param_1 + 0xf0));
    *(undefined4 *)(param_1 + 0xf0) = 0;
  }
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0xf4) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007a8d90 | Classified: elementclient::AArray__Allocate__Not_enough_mem@0x7a8d90 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a8d90(int param_1,undefined4 param_2,int param_3,char param_4)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd71b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar3 = *(int *)(param_3 + 0x114);
  if (((*(char *)(iVar3 + 0x36) == '\0') && (0xfe < *(int *)(param_3 + 0x2cc))) && (param_4 == '\0')
     ) {
    iVar5 = *(int *)(param_3 + 0x218);
    uVar1 = (uint)*(byte *)(param_3 + 0x26c);
    iVar7 = 0;
    if (0 < *(int *)(param_1 + 0x3c)) {
      _param_4 = *(undefined4 **)(param_1 + 0x38);
      do {
        piVar2 = (int *)*_param_4;
        if ((iVar3 == *piVar2) && (uVar1 == piVar2[2])) {
          iVar4 = piVar2[0x38] + *(int *)(param_3 + 0x2c0);
          iVar6 = *(int *)(param_3 + 0x2c4) * 3 + piVar2[0x39];
          if ((iVar4 <= *(int *)(param_1 + 4)) && (iVar6 <= *(int *)(param_1 + 8))) {
            *(int *)(*(int *)(*(int *)(param_1 + 0x38) + iVar7 * 4) + 0xe0) = iVar4;
            *(int *)(*(int *)(*(int *)(param_1 + 0x38) + iVar7 * 4) + 0xe4) = iVar6;
            iVar3 = *(int *)(*(int *)(param_1 + 0x38) + iVar7 * 4);
            piVar8 = (int *)(iVar3 + 0xec);
            if (*(int *)(iVar3 + 0xf4) < *(int *)(iVar3 + 0xf8)) {
LAB_007a8f3b:
              *(int *)(piVar8[1] + piVar8[2] * 4) = param_3;
              piVar8[2] = piVar8[2] + 1;
            }
            else {
              func_0x0068e120(*(undefined4 *)(iVar3 + 0xfc));
              *(int *)(*(int *)(iVar3 + 0xf0) + *(int *)(iVar3 + 0xf4) * 4) = param_3;
              *(int *)(iVar3 + 0xf4) = *(int *)(iVar3 + 0xf4) + 1;
            }
            goto LAB_007a90fc;
          }
        }
        else if (*piVar2 == 0) {
          *piVar2 = iVar3;
          piVar2[1] = iVar5;
          piVar2[2] = uVar1;
          piVar8 = piVar2 + 0x3b;
          piVar2[0x38] = *(int *)(param_3 + 0x2c0);
          piVar2[0x39] = *(int *)(param_3 + 0x2c4) * 3;
          if (piVar2[0x3e] <= piVar2[0x3d]) {
            func_0x0068e120(piVar2[0x3f]);
          }
          goto LAB_007a8f3b;
        }
        iVar7 = iVar7 + 1;
        _param_4 = _param_4 + 1;
      } while (iVar7 < *(int *)(param_1 + 0x3c));
    }
    piVar2 = (int *)func_0x00763250(0x100);
    uStack_4 = 0;
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      func_0x00421a80();
      piVar2[0x3a] = (int)&UNK_008f19ac;
    }
    *piVar2 = iVar3;
    piVar2[1] = iVar5;
    piVar2[2] = uVar1;
    piVar2[0x38] = *(int *)(param_3 + 0x2c0);
    uStack_4 = 0xffffffff;
    piVar2[0x39] = *(int *)(param_3 + 0x2c4) * 3;
    if ((piVar2[0x3e] <= piVar2[0x3d]) && (piVar2[0x3f] != 0)) {
      iVar5 = piVar2[0x3f] + piVar2[0x3e];
      iVar3 = func_0x00763250(iVar5 * 4);
      if (iVar3 == 0) {
        func_0x00764590(1,0x94e51c);
      }
      else {
        iVar7 = 0;
        if (0 < piVar2[0x3d]) {
          do {
            iVar7 = iVar7 + 1;
            *(undefined4 *)(iVar3 + -4 + iVar7 * 4) = *(undefined4 *)(piVar2[0x3c] + -4 + iVar7 * 4)
            ;
          } while (iVar7 < piVar2[0x3d]);
        }
        if (piVar2[0x3c] != 0) {
          func_0x00763260(piVar2[0x3c]);
        }
        piVar2[0x3c] = iVar3;
        piVar2[0x3e] = iVar5;
      }
    }
    *(int *)(piVar2[0x3c] + piVar2[0x3d] * 4) = param_3;
    piVar2[0x3d] = piVar2[0x3d] + 1;
    if ((*(int *)(param_1 + 0x40) <= *(int *)(param_1 + 0x3c)) && (*(int *)(param_1 + 0x44) != 0)) {
      iVar5 = *(int *)(param_1 + 0x44) + *(int *)(param_1 + 0x40);
      iVar3 = func_0x00763250(iVar5 * 4);
      if (iVar3 == 0) {
        func_0x00764590(1,0x94e51c);
      }
      else {
        iVar7 = 0;
        if (0 < *(int *)(param_1 + 0x3c)) {
          do {
            iVar7 = iVar7 + 1;
            *(undefined4 *)(iVar3 + -4 + iVar7 * 4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x38) + -4 + iVar7 * 4);
          } while (iVar7 < *(int *)(param_1 + 0x3c));
        }
        if (*(int *)(param_1 + 0x38) != 0) {
          func_0x00763260(*(int *)(param_1 + 0x38));
        }
        *(int *)(param_1 + 0x38) = iVar3;
        *(int *)(param_1 + 0x40) = iVar5;
      }
    }
    *(int **)(*(int *)(param_1 + 0x38) + *(int *)(param_1 + 0x3c) * 4) = piVar2;
    *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
  }
  else {
    if (*(int *)(param_1 + 0x78) == 0) {
      param_1 = param_1 + 0x48;
    }
    else {
      param_1 = param_1 + 0x60;
    }
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0xc)) {
      piVar2 = *(int **)(param_1 + 8);
      do {
        if (*(float *)(*piVar2 + 0x274) < *(float *)(param_3 + 0x274)) {
          func_0x00466420(iVar3,param_3,1);
          break;
        }
        iVar3 = iVar3 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar3 < *(int *)(param_1 + 0xc));
    }
    if (iVar3 == *(int *)(param_1 + 0xc)) {
      func_0x00459590(param_3);
    }
  }
LAB_007a90fc:
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a9120 | Classified: Angelica3D::proc_7a9120 */
/* ==================================================================== */

/* WARNING: Type propagation algorithm not settling */

undefined4 __fastcall FUN_007a9120(int param_1)

{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined1 **ppuVar8;
  int iVar9;
  int unaff_ESI;
  int iVar10;
  int *piVar11;
  undefined4 uVar12;
  int iVar13;
  int in_stack_fffffe58;
  int *in_stack_fffffe5c;
  undefined4 in_stack_fffffe60;
  int iStack_198;
  int iStack_194;
  int iStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  int *piStack_180;
  int iStack_17c;
  undefined4 uStack_178;
  undefined1 **ppuStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  int *piStack_168;
  int aiStack_164 [19];
  undefined1 *puStack_118;
  undefined1 auStack_cc [12];
  undefined1 auStack_c0 [56];
  int iStack_88;
  int iStack_54;
  int iStack_48;
  char cStack_44;
  
  puStack_118 = auStack_c0;
  aiStack_164[0x12] = 0x7a9136;
  func_0x00787fa0();
  puStack_118 = auStack_c0;
  aiStack_164[0x12] = 0x7a9146;
  func_0x00779ca0();
  aiStack_164[0x12] = 0;
  aiStack_164[0x11] = 0x7a9150;
  func_0x0077a3c0();
  aiStack_164[0x11] = 0;
  aiStack_164[0x10] = 0x7a915a;
  func_0x0077b570();
  aiStack_164[0x10] = 5;
  aiStack_164[0xf] = 0;
  aiStack_164[0xe] = 0x7a9166;
  func_0x00779fc0();
  aiStack_164[0xe] = 1;
  aiStack_164[0xd] = 2;
  aiStack_164[0xc] = 0;
  aiStack_164[0xb] = 0x7a9174;
  func_0x00779fe0();
  aiStack_164[0xb] = 2;
  aiStack_164[10] = 0;
  aiStack_164[9] = 0x7a9180;
  func_0x0077a020();
  aiStack_164[9] = 1;
  aiStack_164[8] = 2;
  aiStack_164[7] = 0;
  aiStack_164[6] = 0x7a918e;
  func_0x0077a040();
  aiStack_164[6] = 1;
  aiStack_164[5] = 1;
  aiStack_164[4] = 0x7a919a;
  func_0x00779fc0();
  aiStack_164[4] = 1;
  aiStack_164[3] = 1;
  aiStack_164[2] = 0x7a91a6;
  func_0x0077a020();
  aiStack_164[2] = 0x7a91ae;
  func_0x0077baf0();
  aiStack_164[2] = 0x7a91b6;
  func_0x0077bad0();
  aiStack_164[2] = 1;
  aiStack_164[1] = 0;
  aiStack_164[0] = 0x7a91c2;
  func_0x00785550();
  if ((*(char *)(param_1 + 0x18) != '\0') && (*(int *)(param_1 + 0x20) != 0)) {
    aiStack_164[0] = 0x7a91dd;
    FUN_00790930();
    aiStack_164[0x11] = *(undefined4 *)(param_1 + 0x1c);
    piStack_168 = aiStack_164 + 0x10;
    aiStack_164[0] = 1;
    uStack_16c = 0;
    aiStack_164[0x10] = 0x3f800000;
    aiStack_164[0x12] = 0x3d99999a;
    puStack_118 = (undefined1 *)0x0;
    uStack_170 = 0x7a920d;
    func_0x0077ba40();
    ppuVar8 = &puStack_118;
    iVar10 = 4;
    puVar6 = (undefined4 *)(*(int *)(iStack_54 + 0x30) + 0xe8);
    do {
      iVar9 = 4;
      do {
        puVar1 = (undefined1 *)*puVar6;
        puVar6 = puVar6 + 1;
        *ppuVar8 = puVar1;
        ppuVar8 = ppuVar8 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
    uStack_170 = 0x7a9243;
    func_0x007874a0();
    ppuStack_174 = &puStack_118;
    uStack_170 = 4;
    uStack_178 = 1;
    iStack_17c = 0x7a9254;
    func_0x0077ba40();
    iStack_17c = 0x7a925c;
    puVar6 = (undefined4 *)func_0x007744f0();
    aiStack_164[6] = *puVar6;
    iStack_17c = 1;
    aiStack_164[7] = puVar6[1];
    aiStack_164[8] = puVar6[2];
    piStack_180 = aiStack_164 + 6;
    uStack_184 = 5;
    aiStack_164[9] = 0x3f800000;
    uStack_188 = 0x7a9289;
    func_0x0077ba40();
  }
  aiStack_164[5] = 0;
  aiStack_164[6] = 0;
  aiStack_164[10] = 0;
  if (0 < *(int *)(param_1 + 0x3c)) {
    do {
      iVar10 = aiStack_164[5];
      piVar2 = *(int **)(*(int *)(param_1 + 0x38) + aiStack_164[10] * 4);
      if ((int *)*piVar2 == (int *)0x0) break;
      aiStack_164[0] = 0;
      piStack_168 = (int *)0x7a92bb;
      (**(code **)(*(int *)*piVar2 + 0x18))();
      if ((*(char *)(param_1 + 0x18) == '\0') && ((int *)piVar2[1] != (int *)0x0)) {
        piStack_168 = (int *)0x1;
        uStack_16c = 0x7a92d8;
        (**(code **)(*(int *)piVar2[1] + 0x18))();
        uStack_16c = 2;
        uStack_170 = 1;
        ppuStack_174 = (undefined1 **)0x1;
        uStack_178 = 0x7a92e6;
        func_0x00779fe0();
        uStack_178 = 0x12;
        iStack_17c = 1;
        piStack_180 = (int *)0x7a92f2;
        func_0x00779fc0();
        piStack_180 = (int *)0x2;
        uStack_184 = 1;
        uStack_188 = 1;
        uStack_18c = 0x7a9300;
        func_0x0077a040();
        uStack_18c = 3;
        iStack_190 = 1;
        iStack_194 = 0x7a930c;
        func_0x0077a020();
        iStack_194 = 0x30000;
        iStack_198 = 1;
        func_0x0077a120();
        in_stack_fffffe60 = 1;
        func_0x0077a1f0(1,0x104);
        ppuStack_174 = (undefined1 **)0x0;
        uStack_170 = 0;
        uStack_16c = 0;
        aiStack_164[0] = 0;
        aiStack_164[1] = 0x3f800000;
        aiStack_164[2] = 0;
        func_0x00788960(&stack0xfffffef4,*(int *)(iStack_88 + 0x30) + 0x50,aiStack_164,&ppuStack_174
                       );
        func_0x00787fa0(aiStack_164 + 6);
        aiStack_164[6] = 0x3f000000;
        aiStack_164[0xb] = -0x41000000;
        aiStack_164[0x12] = 0x3f000000;
        puStack_118 = (undefined1 *)0x3f000000;
        piVar7 = (int *)func_0x007873a0(auStack_cc,&stack0xfffffef4,aiStack_164 + 6);
        piVar11 = aiStack_164 + 6;
        for (iVar10 = 0x10; iVar10 != 0; iVar10 = iVar10 + -1) {
          *piVar11 = *piVar7;
          piVar7 = piVar7 + 1;
          piVar11 = piVar11 + 1;
        }
        in_stack_fffffe5c = aiStack_164 + 6;
        in_stack_fffffe58 = 1;
        func_0x00779da0(1,in_stack_fffffe5c);
        iVar10 = iStack_198;
      }
      else {
        piStack_168 = (int *)0x1;
        uStack_16c = 2;
        uStack_170 = 1;
        ppuStack_174 = (undefined1 **)0x7a93ff;
        func_0x00779fe0();
        ppuStack_174 = (undefined1 **)0x1;
        uStack_178 = 2;
        iStack_17c = 1;
        piStack_180 = (int *)0x7a940d;
        func_0x0077a040();
        piStack_180 = (int *)0x1;
        uStack_184 = 1;
        uStack_188 = 0x7a9419;
        func_0x00779fc0();
        uStack_188 = 1;
        uStack_18c = 1;
        iStack_190 = 0x7a9425;
        func_0x0077a020();
      }
      iStack_190 = *(int *)(*(int *)(param_1 + 0x28) + 0x168);
      if (piVar2[2] != 0) {
        func_0x0077a540(1);
      }
      aiStack_164[3] = piVar2[0x38];
      iVar9 = 0;
      uVar12 = 0;
      if (*(int *)(param_1 + 4) < aiStack_164[3] + iVar10) {
        iStack_198 = 0;
      }
      else if (0 < iVar10) {
        iVar9 = 0x1000;
      }
      piStack_180 = (int *)piVar2[0x39];
      if (*(int *)(param_1 + 8) < (int)piStack_180 + iStack_194) {
        iStack_194 = 0;
      }
      else if (0 < iStack_194) {
        uVar12 = 0x1000;
      }
      puVar6 = &uStack_18c;
      iVar10 = iStack_198 * 0x24;
      cVar5 = func_0x007855c0(iVar10,aiStack_164[3] * 0x24,puVar6,iVar9);
      if (cVar5 == '\0') {
LAB_007a9707:
        if (piVar2[2] != 0) {
          func_0x0077a540(in_stack_fffffe60);
        }
        return 0;
      }
      cVar5 = func_0x00785700((int)in_stack_fffffe5c * 2,iStack_190 * 2,&iStack_198,uVar12);
      if (cVar5 == '\0') {
        if (piVar2[2] != 0) {
          func_0x0077a540(puVar6);
        }
        return 0;
      }
      iVar13 = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 0x10) = 0;
      if (0 < piVar2[0x3d]) {
        do {
          iVar3 = *(int *)(piVar2[0x3c] + iVar13 * 4);
          iVar4 = *(int *)(iVar3 + 0x2c0);
          iStack_17c = *(int *)(iVar3 + 0x2c4) * 3;
          FUN_007b9ca0(iVar9,*(int *)(param_1 + 0xc) + iVar10,in_stack_fffffe58);
          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + iVar4;
          iVar13 = iVar13 + 1;
          *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + iStack_17c;
          iVar9 = iVar9 + iVar4 * 0x24;
          in_stack_fffffe58 = in_stack_fffffe58 + iStack_17c * 2;
        } while (iVar13 < piVar2[0x3d]);
      }
      if (*(int *)(param_1 + 0xc) != 0) {
        cVar5 = func_0x007856d0();
        if (cVar5 == '\0') {
          if (piVar2[2] != 0) {
            func_0x0077a540(puVar6);
          }
          return 0;
        }
        cVar5 = func_0x00785810();
        if (cVar5 == '\0') goto LAB_007a9707;
        func_0x0077a590(4,iVar10,*(undefined4 *)(param_1 + 0xc),in_stack_fffffe5c,
                        *(int *)(param_1 + 0x10) / 3);
        piVar2[0x38] = piVar2[0x38] - *(int *)(param_1 + 0xc);
        piVar2[0x39] = piVar2[0x39] - *(int *)(param_1 + 0x10);
      }
      (**(code **)(*(int *)*piVar2 + 0x1c))(0);
      if ((*(char *)(param_1 + 0x18) == '\0') && ((int *)piVar2[1] != (int *)0x0)) {
        aiStack_164[0] = 1;
        piStack_168 = (int *)0x7a95e9;
        (**(code **)(*(int *)piVar2[1] + 0x1c))();
        piStack_168 = (int *)0x1;
        uStack_16c = 1;
        uStack_170 = 0x7a95f5;
        func_0x00779fc0();
        uStack_170 = 1;
        ppuStack_174 = (undefined1 **)0x1;
        uStack_178 = 0x7a9601;
        func_0x0077a020();
        uStack_178 = 1;
        iStack_17c = 1;
        piStack_180 = (int *)0x7a960d;
        func_0x0077a120();
        piStack_180 = (int *)0x0;
        uStack_184 = 1;
        uStack_188 = 0x7a9619;
        func_0x0077a1f0();
      }
      if (piVar2[2] != 0) {
        aiStack_164[0] = aiStack_164[7];
        piStack_168 = (int *)0x7a962d;
        func_0x0077a540();
      }
      aiStack_164[5] = iVar10 + unaff_ESI;
      aiStack_164[6] = aiStack_164[6] + aiStack_164[0xb];
      aiStack_164[10] = aiStack_164[10] + 1;
    } while (aiStack_164[10] < *(int *)(param_1 + 0x3c));
  }
  if ((*(char *)(param_1 + 0x18) != '\0') && (*(int *)(param_1 + 0x20) != 0)) {
    aiStack_164[0] = 0x7a966c;
    FUN_00790980();
  }
  if (cStack_44 != '\0') {
    aiStack_164[0] = iStack_48;
    piStack_168 = (int *)0x7a9686;
    FUN_007a9730();
  }
  aiStack_164[0] = 4;
  piStack_168 = (int *)0x0;
  uStack_16c = 0x7a9692;
  func_0x00779fc0();
  uStack_16c = 4;
  uStack_170 = 0;
  ppuStack_174 = (undefined1 **)0x7a969e;
  func_0x0077a020();
  ppuStack_174 = (undefined1 **)0x1;
  uStack_178 = 0x7a96a8;
  func_0x0077a3c0();
  uStack_178 = 1;
  iStack_17c = 0x7a96b2;
  func_0x0077b570();
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a9730 | Classified: Angelica3D::proc_7a9730 */
/* ==================================================================== */

undefined4 __fastcall FUN_007a9730(int param_1)

{
  undefined1 uVar1;
  char extraout_AL;
  char extraout_AL_00;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iStack_b0;
  undefined4 uStack_ac;
  int iStack_a8;
  int iStack_a4;
  int iStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined1 *puStack_78;
  undefined1 auStack_40 [64];
  
  puStack_78 = auStack_40;
  uStack_7c = 0x7a9743;
  func_0x00787fa0();
  puStack_78 = auStack_40;
  uStack_7c = 0x7a9753;
  func_0x00779ca0();
  iVar4 = 0;
  uStack_7c = 0;
  uStack_80 = 0x7a975e;
  func_0x0077a3c0();
  uStack_80 = 0;
  uStack_84 = 0x7a9767;
  func_0x0077b570();
  uStack_84 = 5;
  uStack_88 = 0;
  uStack_8c = 0x7a9772;
  func_0x00779fc0();
  uStack_8c = 1;
  uStack_90 = 2;
  uStack_94 = 0;
  uStack_98 = 0x7a977f;
  func_0x00779fe0();
  uStack_98 = 4;
  uStack_9c = 0;
  iStack_a0 = 0x7a978a;
  func_0x0077a020();
  iStack_a0 = 1;
  iStack_a4 = 2;
  iStack_a8 = 0;
  uStack_ac = 0x7a9797;
  func_0x0077a040();
  uStack_ac = 1;
  iStack_b0 = 1;
  func_0x00779fc0();
  func_0x0077a020(1,1);
  func_0x0077baf0();
  func_0x0077bad0();
  uVar7 = 1;
  iVar6 = 0;
  iStack_a8 = 0;
  func_0x00785550(0,1);
  iVar5 = param_1 + 0x48;
  if (*(int *)(param_1 + 0x78) != 0) {
    iVar5 = param_1 + 0x60;
  }
  iStack_a4 = iVar5;
  uStack_94 = func_0x0077a3a0();
  uVar1 = func_0x0077a340();
  uStack_90 = CONCAT31(uStack_90._1_3_,uVar1);
  iStack_a8 = 0;
  if (0 < *(int *)(iVar5 + 0xc)) {
    do {
      iVar5 = *(int *)(*(int *)(iVar5 + 8) + iStack_a8 * 4);
      uVar3 = 0;
      uStack_ac = 0;
      if (*(int *)(param_1 + 4) < *(int *)(iVar5 + 0x2c0) + iVar4) {
        iVar4 = 0;
      }
      else if (0 < iVar4) {
        uVar3 = 0x1000;
      }
      iStack_a0 = *(int *)(iVar5 + 0x2c4) * 3;
      if (*(int *)(param_1 + 8) < iStack_a0 + iStack_b0) {
        iStack_b0 = 0;
      }
      else if (0 < iStack_b0) {
        uStack_ac = 0x1000;
      }
      func_0x007855c0(iVar4 * 0x24,*(int *)(iVar5 + 0x2c0) * 0x24,&uStack_98,uVar3);
      if ((extraout_AL == '\0') ||
         (func_0x00785700(iVar6 * 2,iStack_b0 * 2,&uStack_ac,uVar7), extraout_AL_00 == '\0')) {
        return 0;
      }
      uVar3 = 0;
      (**(code **)(**(int **)(iVar5 + 0x114) + 0x18))(0);
      iStack_b0 = iVar6;
      if (*(char *)(iVar5 + 0x26c) != '\0') {
        func_0x0077a540(1);
        iStack_b0 = iVar6;
      }
      iVar6 = iStack_b0;
      FUN_007b9ca0(uVar7,iVar4);
      if (*(int *)(iVar5 + 0x2cc) == 0xff) {
        func_0x0077a320(0);
      }
      else {
        func_0x0077a320(1);
        func_0x0077a380((*(int *)(iVar5 + 0x2cc) * 0x50) / 0xff + 1);
      }
      cVar2 = func_0x007856d0();
      if (cVar2 == '\0') {
        if (*(char *)(iVar5 + 0x26c) != '\0') {
          func_0x0077a540(uVar3);
        }
        return 0;
      }
      cVar2 = func_0x00785810();
      if (cVar2 == '\0') {
        if (*(char *)(iVar5 + 0x26c) == '\0') {
          return 0;
        }
        func_0x0077a540(uVar3);
        return 0;
      }
      func_0x0077a590(4,iVar4,*(undefined4 *)(iVar5 + 0x2c0),iStack_b0,
                      *(undefined4 *)(iVar5 + 0x2c4));
      (**(code **)(**(int **)(iVar5 + 0x114) + 0x1c))(0);
      if (*(char *)(iVar5 + 0x26c) != '\0') {
        func_0x0077a540(uStack_ac);
      }
      iVar4 = iVar4 + *(int *)(iVar5 + 0x2c0);
      iStack_b0 = *(int *)(iVar5 + 0x2c4) * 3 + iStack_b0;
      iStack_a8 = iStack_a8 + 1;
      iVar5 = iStack_a4;
    } while (iStack_a8 < *(int *)(iStack_a4 + 0xc));
  }
  func_0x0077a380(uStack_94);
  func_0x0077a320(uStack_94);
  func_0x00779fc0(0,4);
  func_0x0077a020(0,4);
  func_0x0077a3c0(1);
  func_0x0077b570(1);
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a9a60 | Classified: Angelica3D::proc_7a9a60 */
/* ==================================================================== */

void __thiscall FUN_007a9a60(int param_1,char param_2)

{
  int iVar1;
  
  if (param_2 == '\0') {
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0x3c)) {
      do {
        iVar1 = iVar1 + 1;
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x38) + -4 + iVar1 * 4) + 0xf4) = 0;
        **(undefined4 **)(*(int *)(param_1 + 0x38) + -4 + iVar1 * 4) = 0;
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x38) + -4 + iVar1 * 4) + 4) = 0;
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x38) + -4 + iVar1 * 4) + 0xe0) = 0;
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x38) + -4 + iVar1 * 4) + 0xe4) = 0;
      } while (iVar1 < *(int *)(param_1 + 0x3c));
      return;
    }
  }
  else {
    if (*(int *)(param_1 + 0x78) == 0) {
      *(undefined4 *)(param_1 + 0x54) = 0;
      return;
    }
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007a9ad0 | Classified: Angelica3D::proc_7a9ad0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_007a9ad0(int param_1,float param_2)

{
  bool bVar1;
  
  bVar1 = param_2 < _DAT_008effc4;
  *(float *)(param_1 + 0x2c) = param_2;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  if (_DAT_008effa0 < *(float *)(param_1 + 0x2c)) {
    *(undefined4 *)(param_1 + 0x2c) = 0x3f800000;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007a9b10 | Classified: Angelica3D::proc_7a9b10 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a9b10(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined1 *puStack_d8;
  undefined1 *puStack_d4;
  undefined1 *puStack_d0;
  undefined4 *puStack_cc;
  undefined1 *puStack_c8;
  int *piStack_c4;
  undefined4 uStack_c0;
  undefined1 *puStack_bc;
  undefined4 uStack_b8;
  undefined1 auStack_a4 [16];
  undefined4 auStack_94 [17];
  undefined1 auStack_50 [68];
  int iStack_c;
  
  uStack_b8 = 0;
  auStack_a4[0] = *(undefined1 *)(*(int *)(param_1 + 0x28) + 0x26d);
  puStack_bc = (undefined1 *)0x7a9b30;
  func_0x0077ab70();
  *(undefined1 *)(param_1 + 0x18) = 1;
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  piStack_c4 = *(int **)(*(int *)(param_1 + 0x28) + 0x2c);
  puStack_bc = auStack_a4;
  uStack_c0 = 0;
  puStack_c8 = (undefined1 *)0x7a9b54;
  (**(code **)(*piStack_c4 + 0xc4))();
  puVar4 = auStack_94 + 1;
  iVar6 = 4;
  puVar3 = (undefined4 *)(*(int *)(iStack_c + 0x30) + 0xe8);
  do {
    iVar5 = 4;
    do {
      uVar1 = *puVar3;
      puVar3 = puVar3 + 1;
      *puVar4 = uVar1;
      puVar4 = puVar4 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  puStack_c8 = auStack_50;
  puStack_cc = (undefined4 *)0x7a9b8f;
  puVar4 = (undefined4 *)func_0x00787610();
  puVar3 = auStack_94;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar3 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 1;
  }
  puStack_cc = (undefined4 *)0x7a9ba5;
  func_0x007874a0();
  puStack_cc = auStack_94;
  puStack_d0 = &stack0xffffff4c;
  puStack_d4 = auStack_a4;
  puStack_d8 = (undefined1 *)0x7a9bb9;
  func_0x007f6774();
  piVar2 = *(int **)(*(int *)(param_1 + 0x28) + 0x2c);
  puStack_d8 = &stack0xffffff50;
  (**(code **)(*piVar2 + 0xc0))(piVar2,0);
  FUN_007a9120(iStack_c,0);
  func_0x0077ab70(puStack_d8);
  piVar2 = *(int **)(*(int *)(param_1 + 0x28) + 0x2c);
  (**(code **)(*piVar2 + 0xc0))(piVar2,0,&puStack_d8);
  *(undefined1 *)(param_1 + 0x18) = 0;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a9c10 | Classified: Angelica3D::proc_7a9c10 */
/* ==================================================================== */

void __fastcall FUN_007a9c10(undefined4 *param_1)

{
  *param_1 = &UNK_008f19ac;
  param_1[1] = &UNK_008d5a30;
  if (param_1[2] != 0) {
    func_0x00763260(param_1[2]);
    param_1[2] = 0;
  }
  param_1[4] = 0;
  param_1[3] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007a9c40 | Classified: Angelica3D::proc_7a9c40 */
/* ==================================================================== */

void __fastcall FUN_007a9c40(undefined4 *param_1)

{
  *param_1 = &UNK_008f19b0;
  param_1[1] = &UNK_008d5a30;
  if (param_1[2] != 0) {
    func_0x00763260(param_1[2]);
    param_1[2] = 0;
  }
  param_1[4] = 0;
  param_1[3] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007a9c70 | Classified: Angelica3D::proc_7a9c70 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a9c70(undefined4 param_1,byte param_2)

{
  FUN_007a9c10();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007a9c90 | Classified: Angelica3D::proc_7a9c90 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a9c90(undefined4 param_1,byte param_2)

{
  FUN_007a9c40();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007a9cb0 | Classified: Angelica3D::proc_7a9cb0 */
/* ==================================================================== */

void __fastcall FUN_007a9cb0(undefined4 *param_1)

{
  *param_1 = &UNK_008f1a3c;
  param_1[1] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007a9cc0 | Classified: Angelica3D::proc_7a9cc0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a9cc0(undefined4 param_1,byte param_2)

{
  FUN_007a9ce0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007a9ce0 | Classified: Angelica3D::proc_7a9ce0 */
/* ==================================================================== */

void __fastcall FUN_007a9ce0(undefined4 *param_1)

{
  *param_1 = &UNK_008f1a3c;
  if (param_1[1] != 0) {
    DestroyCursor(param_1[1]);
    param_1[1] = 0;
  }
  *param_1 = &UNK_008f1a28;
  return;
}


/* ==================================================================== */
/* Address: 0x007a9d10 | Classified: elementclient::A3DSysCursor__Load____Can_not_lo@0x7a9d10 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a9d10(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = LoadCursorFromFileA(param_3);
  *(int *)(param_1 + 4) = iVar1;
  if (iVar1 == 0) {
    func_0x007647d0(0x9d2f20,0x98d918,param_3);
    return 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a9db0 | Classified: Angelica3D::proc_7a9db0 */
/* ==================================================================== */

undefined4 * __fastcall FUN_007a9db0(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_EBX;
  undefined4 *puVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  undefined4 *puStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd73e;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1[0x39] = 0;
  iVar1 = 0;
  do {
    if (0x10 < *(uint *)(&UNK_008f1a50 + iVar1 * 4)) {
      iVar1 = *(int *)(&UNK_008f1a50 + iVar1 * 4);
      goto LAB_007a9df2;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x1c);
  iVar1 = -1;
LAB_007a9df2:
  param_1[0x3c] = iVar1;
  puStack_10 = param_1;
  if (iVar1 == 0) {
    param_1[0x3a] = 0;
  }
  else {
    uVar2 = func_0x00763250(iVar1 * 4);
    param_1[0x3a] = uVar2;
  }
  param_1[0x3b] = param_1[0x3a];
  param_1[0x3d] = iVar1;
  for (; iVar1 != 0; iVar1 = iVar1 + -1) {
    puVar3 = (undefined4 *)param_1[0x3b];
    param_1[0x3b] = puVar3 + 1;
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = 0;
    }
  }
  uStack_4 = 0;
  param_1[0x3f] = 0;
  uStack_14 = 0;
  iVar1 = 0;
  do {
    if (0x100 < *(uint *)(&UNK_008f1a50 + iVar1 * 4)) {
      uVar2 = *(undefined4 *)(&UNK_008f1a50 + iVar1 * 4);
      goto LAB_007a9e7c;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x1c);
  uVar2 = 0xffffffff;
LAB_007a9e7c:
  func_0x007ab5e0(uVar2,&uStack_14);
  *param_1 = &UNK_008f1ac0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[5] = 0;
  param_1[0x4d] = 0;
  param_1[0x4c] = 0;
  param_1[0x4b] = 0;
  param_1[0x4a] = 0;
  puVar3 = param_1 + 6;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  InitializeCriticalSection(param_1 + 0x44);
  *unaff_FS_OFFSET = unaff_EBX;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007a9f00 | Classified: Angelica3D::proc_7a9f00 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a9f00(undefined4 param_1,byte param_2)

{
  FUN_007a9f20();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007a9f20 | Classified: Angelica3D::proc_7a9f20 */
/* ==================================================================== */

void __fastcall FUN_007a9f20(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 unaff_EBP;
  uint uVar8;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008cd769;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f1ac0;
  uVar8 = 0;
  uStack_4 = 0;
  DeleteCriticalSection(param_1 + 0x44);
  uVar7 = 0;
  if (param_1[0x43] != 0) {
    do {
      puVar2 = *(undefined4 **)(param_1[0x40] + uVar7 * 4);
      while (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar2;
        func_0x00763260(puVar2);
        puVar2 = puVar1;
      }
      uVar7 = uVar7 + 1;
      *(undefined4 *)(param_1[0x40] + -4 + uVar7 * 4) = 0;
    } while (uVar7 < (uint)param_1[0x43]);
  }
  param_1[0x3f] = 0;
  iVar5 = param_1[0x40];
  func_0x007d05c0(iVar5,iVar5 + param_1[0x43] * 4);
  iVar5 = param_1[0x40];
  if (iVar5 != 0) {
    func_0x00763260(iVar5);
  }
  if (param_1[0x3d] != 0) {
    do {
      puVar2 = *(undefined4 **)(param_1[0x3a] + uVar8 * 4);
      while (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar2;
        func_0x007637f0();
        func_0x00763260(puVar2);
        puVar2 = puVar1;
      }
      uVar8 = uVar8 + 1;
      *(undefined4 *)(param_1[0x3a] + -4 + uVar8 * 4) = 0;
    } while (uVar8 < (uint)param_1[0x3d]);
  }
  param_1[0x39] = 0;
  puVar1 = (undefined4 *)param_1[0x3a];
  puVar2 = puVar1 + param_1[0x3d];
  if (puVar1 != puVar2) {
    puVar3 = puVar2;
    puVar6 = puVar1;
    if (puVar2 < (undefined4 *)param_1[0x3b]) {
      do {
        puVar4 = puVar3 + 1;
        *puVar6 = *puVar3;
        puVar3 = puVar4;
        puVar6 = puVar6 + 1;
      } while (puVar4 < (undefined4 *)param_1[0x3b]);
    }
    iVar5 = (int)puVar2 - (int)puVar1 >> 2;
    param_1[0x3b] = param_1[0x3b] + iVar5 * -4;
    param_1[0x3d] = param_1[0x3d] - iVar5;
  }
  if (param_1[0x3a] != 0) {
    func_0x00763260(param_1[0x3a]);
  }
  *unaff_FS_OFFSET = unaff_EBP;
  return;
}


/* ==================================================================== */
/* Address: 0x007aa090 | Classified: elementclient::A3DSkinMan__Init__Not_enough_mem@0x7aa090 */
/* ==================================================================== */

undefined4 __thiscall FUN_007aa090(int param_1,int param_2)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 unaff_EBX;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar7;
  int iStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  int iStack_28;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd7a1;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iStack_28 = 0x44;
  *(int *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 0x50);
  iStack_2c = 0x7aa0c1;
  iVar4 = func_0x00763250();
  uStack_4 = 0;
  if (iVar4 == 0) {
    iVar4 = 0;
  }
  else {
    iStack_28 = 0x7aa0db;
    iVar4 = func_0x007af330();
  }
  uStack_4 = 0xffffffff;
  *(int *)(param_1 + 0x14) = iVar4;
  if (iVar4 == 0) {
    iStack_28 = 0x98da24;
    iStack_2c = 0x9d2f20;
    uStack_30 = 0x7aa0fd;
    func_0x007647d0();
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  iStack_28 = param_2;
  iStack_2c = 0x7aa11e;
  cVar2 = func_0x007af490();
  if (cVar2 == '\0') {
    iStack_2c = 0x98d9ec;
    uStack_30 = 0x9d2f20;
    iStack_34 = 0x7aa131;
    func_0x007647d0();
    *unaff_FS_OFFSET = uStack_10;
    return 0;
  }
  iStack_2c = 0xc0;
  uStack_30 = 0x7aa154;
  iVar4 = func_0x00763250();
  iVar6 = 0;
  puStack_8 = (undefined *)0x1;
  if (iVar4 == 0) {
    iVar4 = 0;
  }
  else {
    iStack_2c = 0x7aa170;
    iVar4 = FUN_007a4c20();
  }
  puStack_8 = (undefined *)0xffffffff;
  *(int *)(param_1 + 0x10) = iVar4;
  if (iVar4 != 0) {
    iStack_2c = param_2;
    uStack_30 = 0x7aa1b3;
    FUN_007a4e70();
    uStack_30 = 4;
    iStack_34 = 1;
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x10);
    cVar2 = func_0x0077ba90();
    if (cVar2 != '\0') {
      iVar4 = func_0x00763250(0x3c);
      if (iVar4 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = func_0x0078a330();
      }
      uVar7 = 0x100;
      *(undefined4 *)(param_1 + 0x134) = uVar5;
      cVar2 = func_0x0078a710(*(undefined4 *)(param_1 + 8),0x100,1,0x15,1);
      if (cVar2 == '\0') {
        func_0x007647d0(0x9d2f20,0x98d9b8);
        *unaff_FS_OFFSET = uStack_30;
        return 0;
      }
      cVar2 = func_0x0078a7e0(0,&stack0xffffffe0,&iStack_34,0,0);
      iVar4 = iStack_34;
      if (cVar2 == '\0') {
        func_0x007647d0(0x9d2f20,0x98d988);
        *unaff_FS_OFFSET = uVar7;
        return 0;
      }
      do {
        func_0x00892f74();
        bVar3 = func_0x00892e78();
        uVar1 = (uint)bVar3;
        *(uint *)(iVar4 + iVar6 * 4) = ((uVar1 | 0xffffff00) << 8 | uVar1) << 8 | uVar1;
        iVar6 = iVar6 + 1;
      } while (iVar6 < 0x100);
      func_0x0078a850();
    }
    *unaff_FS_OFFSET = unaff_EBX;
    return 1;
  }
  iStack_2c = 0x98da24;
  uStack_30 = 0x9d2f20;
  iStack_34 = 0x7aa192;
  func_0x007647d0();
  *unaff_FS_OFFSET = uStack_10;
  return 0;
}


