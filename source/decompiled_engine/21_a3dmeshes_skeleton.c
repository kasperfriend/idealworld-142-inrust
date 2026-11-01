/* Authentic Ghidra 12.1.4 Decompilation — elementclient.exe (PW 1.4.2 Build 2305) */
/* Module: 21_a3dmeshes_skeleton.c */

/* ==================================================================== */
/* Address: 0x0078c020 | Classified: Angelica3D::proc_78c020 */
/* ==================================================================== */

void FUN_0078c020(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  func_0x0078bf50(param_1,param_2,0,0,param_3,0,0);
  return;
}


/* ==================================================================== */
/* Address: 0x0078c040 | Classified: Angelica3D::proc_78c040 */
/* ==================================================================== */

undefined4 __fastcall FUN_0078c040(int param_1)

{
  int *piVar1;
  undefined4 in_EAX;
  undefined3 uVar2;
  undefined3 extraout_var;
  
  uVar2 = (undefined3)((uint)in_EAX >> 8);
  if (*(char *)(param_1 + 0x10) == '\0') {
    if (*(int *)(param_1 + 0xc) != 0) {
      piVar1 = (int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x164) + 0x87c);
      *piVar1 = *piVar1 + -1;
    }
    if (*(int *)(param_1 + 0x14) != 0) {
      func_0x007d0e70((undefined4 *)(param_1 + 0x14));
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
    if (*(int *)(param_1 + 0x88) != 0) {
      *(undefined4 *)(param_1 + 0x88) = 0;
    }
    FUN_0078c2d0();
    uVar2 = extraout_var;
  }
  return CONCAT31(uVar2,1);
}


/* ==================================================================== */
/* Address: 0x0078c0a0 | Classified: Angelica3D::proc_78c0a0 */
/* ==================================================================== */

undefined4 __thiscall
FUN_0078c0a0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 in_EAX;
  undefined3 uVar1;
  undefined3 extraout_var;
  
  uVar1 = (undefined3)((uint)in_EAX >> 8);
  if (*(char *)(param_1 + 0x10) == '\0') {
    func_0x007d8fb0(param_2,param_3,param_4);
    uVar1 = extraout_var;
  }
  return CONCAT31(uVar1,1);
}


/* ==================================================================== */
/* Address: 0x0078c0d0 | Classified: elementclient::A2DSprite__BuildItems_one_of_the@0x78c0d0 */
/* ==================================================================== */

uint __fastcall FUN_0078c0d0(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  int iStack_28;
  int iStack_24;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ccc1b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar3 = *(int *)(param_1 + 0x80);
  iStack_24 = 0;
  if (0 < iVar3) {
    iStack_28 = 0;
    do {
      piVar2 = (int *)(*(int *)(param_1 + 0x18) + iStack_28);
      iStack_1c = *piVar2;
      iStack_18 = piVar2[1];
      iStack_14 = piVar2[2];
      iStack_10 = piVar2[3];
      if ((((iStack_1c < 0) || (iStack_18 < 0)) || (*(int *)(param_1 + 0x34) < iStack_14)) ||
         (*(int *)(param_1 + 0x38) < iStack_10)) {
        uVar6 = func_0x007647d0(0x9d2f20,0x98a9d0);
        *unaff_FS_OFFSET = uStack_c;
        return uVar6 & 0xffffff00;
      }
      iVar3 = func_0x00763250(0x24);
      uStack_4 = 0;
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = func_0x007d9260();
      }
      uStack_4 = 0xffffffff;
      if (iVar3 == 0) {
        uVar6 = func_0x007647d0(0x9d2f20,0x98aa30);
        *unaff_FS_OFFSET = uStack_c;
        return uVar6 & 0xffffff00;
      }
      cVar1 = func_0x007d9290(*(undefined4 *)(param_1 + 0xc),param_1,&iStack_1c);
      if (cVar1 == '\0') {
        uVar6 = func_0x007647d0(0x9d2f20,0x98aa08);
        *unaff_FS_OFFSET = uStack_c;
        return uVar6 & 0xffffff00;
      }
      if ((*(int *)(param_1 + 0x2c) <= *(int *)(param_1 + 0x28)) && (*(int *)(param_1 + 0x30) != 0))
      {
        iVar7 = *(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x2c);
        iVar4 = func_0x00763250(iVar7 * 4);
        if (iVar4 == 0) {
          func_0x00764590(1,0x94e51c);
        }
        else {
          iVar5 = 0;
          if (0 < *(int *)(param_1 + 0x28)) {
            do {
              iVar5 = iVar5 + 1;
              *(undefined4 *)(iVar4 + -4 + iVar5 * 4) =
                   *(undefined4 *)(*(int *)(param_1 + 0x24) + -4 + iVar5 * 4);
            } while (iVar5 < *(int *)(param_1 + 0x28));
          }
          if (*(int *)(param_1 + 0x24) != 0) {
            func_0x00763260(*(int *)(param_1 + 0x24));
          }
          *(int *)(param_1 + 0x24) = iVar4;
          *(int *)(param_1 + 0x2c) = iVar7;
        }
      }
      *(int *)(*(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x28) * 4) = iVar3;
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
      iVar3 = iStack_24 + 1;
      iStack_28 = iStack_28 + 0x10;
      iStack_24 = iVar3;
    } while (iVar3 < *(int *)(param_1 + 0x80));
  }
  *unaff_FS_OFFSET = uStack_c;
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x0078c2d0 | Classified: Angelica3D::proc_78c2d0 */
/* ==================================================================== */

undefined4 __fastcall FUN_0078c2d0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x18) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x28);
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x24) + iVar2 * 4);
      func_0x007d9410();
      if (iVar1 != 0) {
        func_0x007d9280();
        func_0x00763260(iVar1);
      }
      iVar1 = *(int *)(param_1 + 0x28);
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  *(undefined4 *)(param_1 + 0x28) = 0;
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x0078c330 | Classified: Angelica3D::proc_78c330 */
/* ==================================================================== */

undefined1 __thiscall
FUN_0078c330(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  char cVar2;
  
  if (*(char *)(param_1 + 0x10) == '\0') {
    if (*(int *)(param_1 + 0x88) != 0) {
      uVar1 = FUN_0078c710(param_3,param_4);
      return uVar1;
    }
    if (*(int *)(param_1 + 0x84) != 0) {
      cVar2 = func_0x007d9bf0(param_2,param_3,param_4,*(undefined4 *)(param_1 + 0x44),
                              *(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x6c),
                              *(undefined4 *)(param_1 + 0x50),param_1 + 0x54,param_1 + 0x5c,
                              *(undefined4 *)(param_1 + 0x70),*(undefined4 *)(param_1 + 0x74));
      if (cVar2 == '\0') {
        return 0;
      }
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0078c3a0 | Classified: Angelica3D::proc_78c3a0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0078c3a0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 in_EAX;
  undefined3 uVar2;
  undefined4 uVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined4 unaff_ESI;
  
  uVar2 = (undefined3)((uint)in_EAX >> 8);
  if (*(char *)(param_1 + 0x10) == '\0') {
    if (*(int *)(param_1 + 0x88) != 0) {
      uVar1 = FUN_0078c710(param_2,param_3);
      return uVar1;
    }
    uVar2 = 0;
    if (*(int *)(param_1 + 0x84) != 0) {
      if (*(int *)(param_1 + 100) != 5) {
        func_0x0077a2c0(*(int *)(param_1 + 100));
      }
      if (*(int *)(param_1 + 0x68) != 6) {
        func_0x0077a2f0(*(int *)(param_1 + 0x68));
      }
      uVar1 = 3;
      func_0x0077a0e0(0,3,3);
      uVar1 = func_0x007d9450(uVar1,unaff_ESI,*(undefined4 *)(param_1 + 0x44),
                              *(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x6c),
                              *(undefined4 *)(param_1 + 0x50),param_1 + 0x54,param_1 + 0x5c,
                              *(undefined1 *)(param_1 + 0x78),*(undefined4 *)(param_1 + 0x70),
                              *(undefined4 *)(param_1 + 0x74));
      if ((char)uVar1 == '\0') {
        return uVar1;
      }
      func_0x0077a0e0(0,1,1);
      uVar2 = extraout_var;
      if (*(int *)(param_1 + 100) != 5) {
        func_0x0077a2c0(5);
        uVar2 = extraout_var_00;
      }
      if (*(int *)(param_1 + 0x68) != 6) {
        func_0x0077a2f0(6);
        uVar2 = extraout_var_01;
      }
    }
  }
  return CONCAT31(uVar2,1);
}


/* ==================================================================== */
/* Address: 0x0078c480 | Classified: Angelica3D::proc_78c480 */
/* ==================================================================== */

void __fastcall FUN_0078c480(int param_1)

{
  FUN_0078c3a0(*(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x40));
  return;
}


/* ==================================================================== */
/* Address: 0x0078c490 | Classified: Angelica3D::proc_78c490 */
/* ==================================================================== */

void __thiscall FUN_0078c490(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 unaff_retaddr;
  
  if (*(int *)(*(int *)(param_1 + 0x14) + 0x3c) != 0) {
    func_0x007d1060(*(int *)(param_1 + 0x14));
    FUN_0078c330(*(undefined4 *)(*(int *)(param_1 + 0x14) + 0x3c),unaff_retaddr,param_2);
    return;
  }
  FUN_0078c3a0(param_2,param_3);
  return;
}


/* ==================================================================== */
/* Address: 0x0078c4e0 | Classified: Angelica3D::proc_78c4e0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0078c4e0(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x10) == '\0') {
    if (param_2 < *(int *)(param_1 + 0x80)) {
      if (param_2 < 0) {
        *(int *)(param_1 + 0x7c) = param_2;
        *(undefined4 *)(param_1 + 0x84) = 0;
        return 1;
      }
    }
    else {
      param_2 = 0;
    }
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x24) + param_2 * 4);
    *(int *)(param_1 + 0x7c) = param_2;
    *(undefined4 *)(param_1 + 0x84) = uVar1;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0078c530 | Classified: Angelica3D::proc_78c530 */
/* ==================================================================== */

undefined4 __thiscall FUN_0078c530(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  int *unaff_retaddr;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 auStack_10 [4];
  
  piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 0x14) + 0x24) + (int)param_2 * 4);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  uStack_20 = *param_3;
  uStack_1c = param_3[1];
  uStack_18 = param_3[2];
  uStack_14 = param_3[3];
  iStack_30 = *piVar1;
  iStack_2c = piVar1[1];
  iStack_28 = piVar1[2];
  iStack_24 = piVar1[3];
  iVar2 = IntersectRect(auStack_10,&uStack_20,&iStack_30);
  if (iVar2 == 0) {
    return 0;
  }
  *unaff_retaddr = *piVar1;
  unaff_retaddr[1] = piVar1[1];
  unaff_retaddr[2] = piVar1[4] + *unaff_retaddr;
  unaff_retaddr[3] = piVar1[5] + unaff_retaddr[1];
  *param_2 = uStack_1c;
  param_2[1] = uStack_18;
  param_2[2] = uStack_14;
  param_2[3] = auStack_10[0];
  return 1;
}


/* ==================================================================== */
/* Address: 0x0078c600 | Classified: elementclient::A2DSprite__Init___Not_enough_mem@0x78c600 */
/* ==================================================================== */

undefined4 __thiscall FUN_0078c600(int param_1,int param_2,undefined4 *param_3)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  
  FUN_0078c2d0();
  if ((param_2 < 1) || (param_3 == (undefined4 *)0x0)) {
    *(undefined4 *)(param_1 + 0x80) = 1;
    puVar2 = (undefined4 *)func_0x00763250(0x10);
    *(undefined4 **)(param_1 + 0x18) = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      func_0x007647d0(0x9d2f20,0x98aa88);
      return 0;
    }
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = *(undefined4 *)(param_1 + 0x34);
    puVar2[3] = *(undefined4 *)(param_1 + 0x38);
  }
  else {
    *(int *)(param_1 + 0x80) = param_2;
    puVar2 = (undefined4 *)func_0x00763250(param_2 << 4);
    *(undefined4 **)(param_1 + 0x18) = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      func_0x007647d0(0x9d2f20,0x98aab0);
      return 0;
    }
    for (iVar3 = (*(uint *)(param_1 + 0x80) & 0xfffffff) << 2; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar2 = *param_3;
      param_3 = param_3 + 1;
      puVar2 = puVar2 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar2 = *(undefined1 *)param_3;
      param_3 = (undefined4 *)((int)param_3 + 1);
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
  }
  cVar1 = FUN_0078c0d0();
  if (cVar1 != '\0') {
    if (*(int *)(param_1 + 0x80) != 0) {
      FUN_0078c4e0(0);
      return 1;
    }
    FUN_0078c4e0(0xffffffff);
    return 1;
  }
  func_0x007647d0(0x9d2f20,0x98aa5c);
  return 0;
}


/* ==================================================================== */
/* Address: 0x0078c710 | Classified: Angelica3D::proc_78c710 */
/* ==================================================================== */

undefined4 __fastcall FUN_0078c710(int param_1)

{
  undefined4 in_EAX;
  undefined3 uVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = (undefined3)((uint)in_EAX >> 8);
  if (((*(char *)(param_1 + 0x10) == '\0') && (uVar1 = 0, *(int *)(param_1 + 0x88) != 0)) &&
     (uVar1 = 0, *(int *)(param_1 + 0x84) != 0)) {
    if (*(int *)(param_1 + 100) != 5) {
      func_0x0077a2c0(*(int *)(param_1 + 100));
    }
    if (*(int *)(param_1 + 0x68) != 6) {
      func_0x0077a2f0(*(int *)(param_1 + 0x68));
    }
    func_0x0077a0e0(0,3,3);
    func_0x0077a0e0(1,3,3);
    func_0x00779fe0(1,2,1);
    func_0x00779fc0(1,4);
    uVar3 = 1;
    func_0x0077a040(1,2,1);
    uVar2 = 4;
    func_0x0077a020(1,4);
    (**(code **)(**(int **)(param_1 + 0x88) + 0x18))(1);
    uVar2 = func_0x007da1c0(uVar2,uVar3,*(undefined4 *)(param_1 + 0x44),
                            *(undefined4 *)(param_1 + 0x6c),*(undefined4 *)(param_1 + 0x50),
                            param_1 + 0x54,param_1 + 0x5c,*(undefined1 *)(param_1 + 0x78),
                            *(undefined4 *)(param_1 + 0x70),*(undefined4 *)(param_1 + 0x74));
    if ((char)uVar2 == '\0') {
      return uVar2;
    }
    (**(code **)(**(int **)(param_1 + 0x88) + 0x1c))(1);
    func_0x00779fc0(1,1);
    func_0x0077a020(1,1);
    func_0x0077a0e0(0,1,1);
    func_0x0077a0e0(1,1,1);
    uVar1 = extraout_var;
    if (*(int *)(param_1 + 100) != 5) {
      func_0x0077a2c0(5);
      uVar1 = extraout_var_00;
    }
    if (*(int *)(param_1 + 0x68) != 6) {
      func_0x0077a2f0(6);
      uVar1 = extraout_var_01;
    }
  }
  return CONCAT31(uVar1,1);
}


/* ==================================================================== */
/* Address: 0x0078c860 | Classified: Angelica3D::proc_78c860 */
/* ==================================================================== */

undefined4 __thiscall FUN_0078c860(undefined4 param_1,byte param_2)

{
  FUN_0078c880();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0078c880 | Classified: Angelica3D::proc_78c880 */
/* ==================================================================== */

void __fastcall FUN_0078c880(undefined4 *param_1)

{
  *param_1 = &UNK_008f0f30;
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
/* Address: 0x0078c8b0 | Classified: Angelica3D::proc_78c8b0 */
/* ==================================================================== */

undefined4 * __fastcall FUN_0078c8b0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = 0;
  param_1[4] = 0;
  do {
    if (100 < *(uint *)(&UNK_008f0f38 + iVar2 * 4)) {
      iVar2 = *(int *)(&UNK_008f0f38 + iVar2 * 4);
      goto LAB_0078c8d3;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x1c);
  iVar2 = -1;
LAB_0078c8d3:
  param_1[7] = iVar2;
  if (iVar2 == 0) {
    param_1[5] = 0;
  }
  else {
    uVar3 = func_0x00763250(iVar2 * 4);
    param_1[5] = uVar3;
  }
  param_1[6] = param_1[5];
  param_1[8] = iVar2;
  for (; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = (undefined4 *)param_1[6];
    param_1[6] = puVar1 + 1;
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = 0;
    }
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0078c930 | Classified: Angelica3D::proc_78c930 */
/* ==================================================================== */

void __fastcall FUN_0078c930(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  uVar7 = 0;
  if (*(int *)(param_1 + 0x20) != 0) {
    do {
      puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x14) + uVar7 * 4);
      while (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar2;
        func_0x00763260(puVar2);
        puVar2 = puVar1;
      }
      uVar7 = uVar7 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x14) + -4 + uVar7 * 4) = 0;
    } while (uVar7 < *(uint *)(param_1 + 0x20));
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  puVar1 = *(undefined4 **)(param_1 + 0x14);
  puVar2 = puVar1 + *(int *)(param_1 + 0x20);
  if (puVar1 != puVar2) {
    puVar3 = puVar2;
    puVar6 = puVar1;
    if (puVar2 < *(undefined4 **)(param_1 + 0x18)) {
      do {
        puVar4 = puVar3 + 1;
        *puVar6 = *puVar3;
        puVar3 = puVar4;
        puVar6 = puVar6 + 1;
      } while (puVar4 < *(undefined4 **)(param_1 + 0x18));
    }
    iVar5 = (int)puVar2 - (int)puVar1 >> 2;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + iVar5 * -4;
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) - iVar5;
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x14));
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0078c9d0 | Classified: elementclient::A2DSpriteBuffer__Init____Not_eno@0x78c9d0 */
/* ==================================================================== */

uint __thiscall FUN_0078c9d0(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  undefined4 *unaff_FS_OFFSET;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  int aiStack_24 [2];
  int iStack_1c;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ccc43;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = param_2;
  iVar6 = *(int *)(param_3 + 0x18);
  param_1[1] = iVar6;
  piVar2 = (int *)func_0x00763250(iVar6 * 0x28 + 4);
  uStack_4 = 0;
  if (piVar2 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = piVar2 + 1;
    *piVar2 = iVar6;
    func_0x00892e84(piVar3,0x28,iVar6,&UNK_0078cc00,FUN_0078cc20);
  }
  uStack_4 = 0xffffffff;
  param_1[2] = piVar3;
  if (piVar3 == (int *)0x0) {
    uVar4 = func_0x007647d0(0x9d2f20,0x98aadc);
    uVar4 = uVar4 & 0xffffff00;
  }
  else {
    iVar6 = param_1[1];
    param_2 = 0;
    if (0 < iVar6) {
      uStack_34 = 0;
      do {
        *(undefined4 *)(param_1[2] + 4 + uStack_34) = 0;
        *(undefined4 *)(param_1[2] + uStack_34) =
             *(undefined4 *)(*(int *)(*(int *)(param_3 + 0x24) + param_2 * 4) + 0x18);
        uVar4 = param_1[8];
        aiStack_24[0] = *(int *)(param_1[2] + uStack_34);
        puVar7 = (uint *)(param_1[2] + uStack_34);
        if ((uVar4 < param_1[4] + 1) &&
           (uStack_28 = uVar4, uStack_2c = func_0x00404700(param_1[4] + 1), uVar4 < uStack_2c)) {
          uVar8 = 0;
          uStack_30 = 0;
          func_0x007ab5e0(uStack_2c,&uStack_30);
          uStack_c = 1;
          if (uVar4 != 0) {
            iVar6 = param_1[5];
            do {
              puVar1 = *(undefined4 **)(iVar6 + uVar8 * 4);
              while (puVar1 != (undefined4 *)0x0) {
                uVar4 = puVar1[3];
                *(undefined4 *)(iVar6 + uVar8 * 4) = *puVar1;
                *puVar1 = *(undefined4 *)(aiStack_24[0] + (uVar4 % uStack_34) * 4);
                *(undefined4 **)(aiStack_24[0] + (uVar4 % uStack_34) * 4) = puVar1;
                iVar6 = param_1[5];
                puVar1 = *(undefined4 **)(iVar6 + uVar8 * 4);
              }
              uVar8 = uVar8 + 1;
            } while (uVar8 < uStack_30);
          }
          func_0x004bb3b0(aiStack_24);
          uStack_10 = 0xffffffff;
          FUN_0078d1e0();
          if (iStack_1c != 0) {
            func_0x00763260(iStack_1c);
          }
        }
        uVar4 = *puVar7;
        uStack_28 = uVar4 % (uint)param_1[8];
        puVar1 = *(undefined4 **)(param_1[5] + uStack_28 * 4);
        for (puVar5 = puVar1; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {
          if (puVar5[3] == uVar4) goto LAB_0078cbb7;
        }
        puVar5 = (undefined4 *)func_0x00763250(0x10);
        if (puVar5 == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          puVar5[1] = aiStack_24[0];
          puVar5[2] = 0;
          puVar5[3] = *puVar7;
          *puVar5 = puVar1;
        }
        *(undefined4 **)(param_1[5] + uStack_28 * 4) = puVar5;
        param_1[4] = param_1[4] + 1;
LAB_0078cbb7:
        iVar6 = param_1[2] + uStack_34;
        uStack_34 = uStack_34 + 0x28;
        puVar5[2] = iVar6;
        iVar6 = param_2 + 1;
        param_2 = iVar6;
      } while (iVar6 < (int)param_1[1]);
    }
    uVar4 = CONCAT31((int3)((uint)iVar6 >> 8),1);
  }
  *unaff_FS_OFFSET = uStack_c;
  return uVar4;
}


/* ==================================================================== */
/* Address: 0x0078cc20 | Classified: Angelica3D::proc_78cc20 */
/* ==================================================================== */

void __fastcall FUN_0078cc20(int param_1)

{
  *(undefined **)(param_1 + 8) = &UNK_008f0fa8;
  if (*(int *)(param_1 + 0xc) != 0) {
    func_0x00763260(*(int *)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x0078cc50 | Classified: Angelica3D::proc_78cc50 */
/* ==================================================================== */

undefined4 __fastcall FUN_0078cc50(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  uVar5 = 0;
  if (*(int *)(param_1 + 0x20) != 0) {
    do {
      puVar4 = *(undefined4 **)(*(int *)(param_1 + 0x14) + uVar5 * 4);
      while (puVar4 != (undefined4 *)0x0) {
        puVar2 = (undefined4 *)*puVar4;
        func_0x00763260(puVar4);
        puVar4 = puVar2;
      }
      uVar5 = uVar5 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x14) + -4 + uVar5 * 4) = 0;
    } while (uVar5 < *(uint *)(param_1 + 0x20));
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (*(int *)(param_1 + 8) != 0) {
    iVar7 = 0;
    if (0 < *(int *)(param_1 + 4)) {
      iVar6 = 0;
      do {
        iVar3 = *(int *)(iVar6 + 0xc + *(int *)(param_1 + 8));
        iVar1 = iVar6 + 8 + *(int *)(param_1 + 8);
        if (iVar3 != 0) {
          func_0x00763260(iVar3);
          *(undefined4 *)(iVar1 + 4) = 0;
        }
        iVar7 = iVar7 + 1;
        *(undefined4 *)(iVar1 + 0xc) = 0;
        *(undefined4 *)(iVar1 + 8) = 0;
        iVar6 = iVar6 + 0x28;
      } while (iVar7 < *(int *)(param_1 + 4));
    }
    iVar7 = *(int *)(param_1 + 8);
    if (iVar7 != 0) {
      func_0x00892d40(iVar7,0x28,*(undefined4 *)(iVar7 + -4),FUN_0078cc20);
      func_0x00763260(iVar7 + -4);
    }
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0078cd10 | Classified: Angelica3D::proc_78cd10 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0078cd10(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  int iVar8;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  iVar3 = 0;
  func_0x0077a0e0(0,3,3);
  iVar8 = 0;
  if (0 < param_1[1]) {
    do {
      if (0 < *(int *)(param_1[2] + iVar3 + 4)) {
        if (*(char *)(param_1[2] + iVar3 + 0x24) == '\0') {
          func_0x00779f60(0,1);
        }
        iVar2 = *(int *)(param_1[2] + 0x1c + iVar3);
        if (iVar2 != 5) {
          func_0x0077a2c0(iVar2);
        }
        iVar2 = *(int *)(param_1[2] + 0x20 + iVar3);
        if (iVar2 != 6) {
          func_0x0077a2f0(iVar2);
        }
        uVar7 = 0;
        (**(code **)(**(int **)(iVar3 + param_1[2]) + 0x18))(0);
        puVar4 = (undefined4 *)(*(int *)(param_1[2] + 4 + iVar3) / 6);
        puVar5 = *(undefined4 **)(*(int *)(*(int *)(*param_1 + 0x164) + 0x54) + 0x2c);
        if ((int)puVar5 < (int)puVar4) {
          puVar4 = puVar5;
        }
        puVar6 = &stack0xffffffa4;
        cVar1 = func_0x007d0ff0(&stack0xffffffac,(int)puVar4 * 6,puVar6);
        if (cVar1 == '\0') {
          func_0x0077a0e0(0,1,1);
          return 0;
        }
        iVar2 = ((int)puVar4 * 3 & 0x3ffffffU) << 4;
        puVar5 = *(undefined4 **)(param_1[2] + 0xc + iVar3);
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar4 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar4 = puVar4 + 1;
        }
        for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
          *(undefined1 *)puVar4 = *(undefined1 *)puVar5;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
        func_0x007d1050();
        func_0x00785550(0,1);
        if ((*(char *)(param_1[2] + 0x25 + iVar3) != '\0') &&
           (*(int *)(*(int *)(*(int *)(*param_1 + 0x164) + 0x54) + 0x40) != 0)) {
          iVar2 = *(int *)(*(int *)(*param_1 + 0x164) + 0xa8);
          FUN_00790930();
          fStack_40 = _DAT_008f0d7c / (float)*(uint *)(iVar2 + 0x20);
          fStack_3c = 1.0;
          uStack_38 = 0;
          fStack_44 = _DAT_008f0d90 / (float)*(uint *)(iVar2 + 0x1c);
          func_0x0077ba40(0,&fStack_44,1);
          fStack_3c = (float)*(uint *)(iVar2 + 0x18);
          iVar8 = 0;
          fStack_40 = (float)*(uint *)(iVar2 + 0x14);
          uStack_38 = 0;
          uStack_34 = 0;
          func_0x0077ba40(1,&fStack_40,1);
        }
        func_0x0077a690(4,uVar7,(int)puVar6 * 2);
        (**(code **)(**(int **)(iVar3 + param_1[2]) + 0x1c))(0);
        *(undefined4 *)(param_1[2] + 4 + iVar3) = 0;
        *(undefined4 *)(param_1[2] + 0x10 + iVar3) = 0;
        if (*(int *)(param_1[2] + 0x1c + iVar3) != 5) {
          func_0x0077a2c0(5);
        }
        if (*(int *)(param_1[2] + 0x20 + iVar3) != 6) {
          func_0x0077a2f0(6);
        }
        if (*(char *)(param_1[2] + 0x24 + iVar3) == '\0') {
          func_0x00779f60(0,2);
        }
      }
      iVar8 = iVar8 + 1;
      iVar3 = iVar3 + 0x28;
    } while (iVar8 < param_1[1]);
  }
  func_0x0077a0e0(0,1,1);
  return 1;
}


/* ==================================================================== */
/* Address: 0x0078cfc0 | Classified: Angelica3D::proc_78cfc0 */
/* ==================================================================== */

undefined4 __thiscall
FUN_0078cfc0(int param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,undefined1 param_5
            )

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *unaff_retaddr;
  int iStack_10;
  int aiStack_c [3];
  
  func_0x0044cb70(aiStack_c,&param_2);
  if (((unaff_ESI == 0) || (param_1 == -0xc)) || (unaff_ESI == param_1 + 0xc)) {
    if (iStack_10 != 0) goto LAB_0078d00b;
    if (aiStack_c[0] == 0) {
      return 0;
    }
  }
  else if (iStack_10 != 0) {
LAB_0078d00b:
    aiStack_c[0] = aiStack_c[0] + 4;
    goto LAB_0078d016;
  }
  aiStack_c[0] = 0;
LAB_0078d016:
  iVar1 = *(int *)(aiStack_c[0] + 4);
  if (*(int *)(iVar1 + 0x14) <= *(int *)(iVar1 + 0x10)) {
    FUN_0078d230(*(undefined4 *)(iVar1 + 0x18));
  }
  puVar4 = unaff_retaddr;
  puVar3 = (undefined4 *)(*(int *)(iVar1 + 0xc) + *(int *)(iVar1 + 0x10) * 0x20);
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar2 = *(int *)(iVar1 + 0x10) + 1;
  *(int *)(iVar1 + 0x10) = iVar2;
  if (*(int *)(iVar1 + 0x14) <= iVar2) {
    FUN_0078d230(*(undefined4 *)(iVar1 + 0x18));
  }
  puVar4 = unaff_retaddr + 8;
  puVar3 = (undefined4 *)(*(int *)(iVar1 + 0x10) * 0x20 + *(int *)(iVar1 + 0xc));
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar2 = *(int *)(iVar1 + 0x10) + 1;
  *(int *)(iVar1 + 0x10) = iVar2;
  if (*(int *)(iVar1 + 0x14) <= iVar2) {
    FUN_0078d230(*(undefined4 *)(iVar1 + 0x18));
  }
  puVar4 = unaff_retaddr + 0x10;
  puVar3 = puVar4;
  puVar5 = (undefined4 *)(*(int *)(iVar1 + 0x10) * 0x20 + *(int *)(iVar1 + 0xc));
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  iVar2 = *(int *)(iVar1 + 0x10) + 1;
  *(int *)(iVar1 + 0x10) = iVar2;
  if (*(int *)(iVar1 + 0x14) <= iVar2) {
    FUN_0078d230(*(undefined4 *)(iVar1 + 0x18));
  }
  puVar3 = unaff_retaddr + 8;
  puVar5 = (undefined4 *)(*(int *)(iVar1 + 0x10) * 0x20 + *(int *)(iVar1 + 0xc));
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  iVar2 = *(int *)(iVar1 + 0x10) + 1;
  *(int *)(iVar1 + 0x10) = iVar2;
  if (*(int *)(iVar1 + 0x14) <= iVar2) {
    FUN_0078d230(*(undefined4 *)(iVar1 + 0x18));
  }
  puVar3 = unaff_retaddr + 0x18;
  puVar5 = (undefined4 *)(*(int *)(iVar1 + 0xc) + *(int *)(iVar1 + 0x10) * 0x20);
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  iVar2 = *(int *)(iVar1 + 0x10) + 1;
  *(int *)(iVar1 + 0x10) = iVar2;
  if (*(int *)(iVar1 + 0x14) <= iVar2) {
    FUN_0078d230(*(undefined4 *)(iVar1 + 0x18));
  }
  puVar3 = (undefined4 *)(*(int *)(iVar1 + 0xc) + *(int *)(iVar1 + 0x10) * 0x20);
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 1;
  }
  *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1;
  *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 6;
  *(undefined1 *)(iVar1 + 0x24) = param_4;
  *(undefined1 *)(iVar1 + 0x25) = param_5;
  *(undefined4 *)(iVar1 + 0x1c) = param_2;
  *(undefined4 *)(iVar1 + 0x20) = param_3;
  return 1;
}


/* ==================================================================== */
/* Address: 0x0078d190 | Classified: Angelica3D::proc_78d190 */
/* ==================================================================== */

undefined4 * __thiscall FUN_0078d190(undefined4 *param_1,byte param_2)

{
  *param_1 = &UNK_008f0fa8;
  if (param_1[1] != 0) {
    func_0x00763260(param_1[1]);
    param_1[1] = 0;
  }
  param_1[3] = 0;
  param_1[2] = 0;
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0078d1e0 | Classified: Angelica3D::proc_78d1e0 */
/* ==================================================================== */

void __fastcall FUN_0078d1e0(uint *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  puVar2 = (undefined4 *)*param_1;
  puVar1 = puVar2 + param_1[3];
  if (puVar2 != puVar1) {
    puVar3 = puVar1;
    puVar6 = puVar2;
    if (puVar1 < (undefined4 *)param_1[1]) {
      do {
        puVar4 = puVar3 + 1;
        *puVar6 = *puVar3;
        puVar3 = puVar4;
        puVar6 = puVar6 + 1;
      } while (puVar4 < (undefined4 *)param_1[1]);
    }
    iVar5 = (int)puVar1 - (int)puVar2 >> 2;
    param_1[1] = param_1[1] + iVar5 * -4;
    param_1[3] = param_1[3] - iVar5;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0078d230 | Classified: elementclient::AArray__Allocate__Not_enough_mem@0x78d230 */
/* ==================================================================== */

undefined4 __thiscall FUN_0078d230(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (param_2 != 0) {
    param_2 = param_2 + *(int *)(param_1 + 0xc);
    iVar1 = func_0x00763250(param_2 * 0x20);
    if (iVar1 == 0) {
      func_0x00764590(1,0x94e51c);
      return 0;
    }
    iVar4 = 0;
    if (0 < *(int *)(param_1 + 8)) {
      iVar2 = 0;
      do {
        puVar5 = (undefined4 *)(*(int *)(param_1 + 4) + iVar2);
        puVar6 = (undefined4 *)(iVar2 + iVar1);
        for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        iVar4 = iVar4 + 1;
        iVar2 = iVar2 + 0x20;
      } while (iVar4 < *(int *)(param_1 + 8));
    }
    if (*(int *)(param_1 + 4) != 0) {
      func_0x00763260(*(int *)(param_1 + 4));
    }
    *(int *)(param_1 + 4) = iVar1;
    *(int *)(param_1 + 0xc) = param_2;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0078d2c0 | Classified: Angelica3D::proc_78d2c0 */
/* ==================================================================== */

void __fastcall FUN_0078d2c0(undefined4 *param_1)

{
  param_1[7] = &UNK_008d5a30;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0x10;
  param_1[6] = &UNK_008f1024;
  param_1[0xd] = &UNK_008d5a30;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0x10;
  param_1[0xc] = &UNK_008d6b4c;
  *param_1 = &UNK_008f1020;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x0078d310 | Classified: Angelica3D::proc_78d310 */
/* ==================================================================== */

undefined4 __thiscall FUN_0078d310(undefined4 param_1,byte param_2)

{
  FUN_0078d330();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0078d330 | Classified: Angelica3D::proc_78d330 */
/* ==================================================================== */

void __fastcall FUN_0078d330(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008ccc5b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f1020;
  param_1[0xc] = &UNK_008d6b4c;
  param_1[0xd] = &UNK_008d5a30;
  uStack_4 = 0;
  if (param_1[0xe] != 0) {
    func_0x00763260(param_1[0xe]);
    param_1[0xe] = 0;
  }
  param_1[0x10] = 0;
  param_1[0xf] = 0;
  param_1[6] = &UNK_008f1024;
  uStack_4 = 0xffffffff;
  param_1[7] = &UNK_008d5a30;
  if (param_1[8] != 0) {
    func_0x00763260(param_1[8]);
    param_1[8] = 0;
  }
  param_1[10] = 0;
  param_1[9] = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x0078d3d0 | Classified: elementclient::A3DFontMan__Init__Failed_to_crea@0x78d3d0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0078d3d0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uStack_34;
  
  uStack_34 = 0;
  *(undefined4 *)(param_1 + 4) = param_2;
  puVar3 = &uStack_34;
  iVar1 = CreateCompatibleDC();
  *(int *)(param_1 + 8) = iVar1;
  if (iVar1 == 0) {
    func_0x007647d0(0x9d2f20,0x98ab34);
    return 0;
  }
  for (iVar2 = 10; puVar3 = puVar3 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
  }
  iVar1 = CreateDIBSection(iVar1,&stack0xffffffd0,0,&stack0x00000000,0,0);
  *(int *)(param_1 + 0xc) = iVar1;
  if (iVar1 == 0) {
    func_0x007647d0(0x9d2f20,0x98ab08);
    return 0;
  }
  SetMapMode(*(undefined4 *)(param_1 + 8),1);
  return 1;
}


/* ==================================================================== */
/* Address: 0x0078d490 | Classified: elementclient::A3DFontMan__Release___d_A3DFont_o@0x78d490 */
/* ==================================================================== */

void __fastcall FUN_0078d490(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    do {
      iVar1 = **(int **)(*(int *)(param_1 + 0x20) + iVar3 * 4);
      if (iVar1 != 0) {
        DeleteObject(iVar1);
      }
      func_0x00763260(*(undefined4 *)(*(int *)(param_1 + 0x20) + iVar3 * 4));
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x24));
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  if (*(int *)(param_1 + 0x3c) != 0) {
    func_0x007647d0(0x9d2f20,0x98ab64,*(int *)(param_1 + 0x3c));
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0x3c)) {
      do {
        FUN_0078f6c0();
        puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x38) + iVar3 * 4);
        if (puVar2 != (undefined4 *)0x0) {
          (**(code **)*puVar2)(1);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1 + 0x3c));
    }
    if (*(int *)(param_1 + 0x38) != 0) {
      func_0x00763260(*(int *)(param_1 + 0x38));
      *(undefined4 *)(param_1 + 0x38) = 0;
    }
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  if (*(int *)(param_1 + 8) != 0) {
    DeleteDC(*(int *)(param_1 + 8));
    *(undefined4 *)(param_1 + 8) = 0;
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    DeleteObject(*(int *)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x0078d570 | Classified: elementclient::A3DFontMan__RegisterFontType__No@0x78d570 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_0078d570(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_EBP;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar4 = param_4 & 0xfffffeff;
  iVar1 = FUN_0078d6e0(param_2,param_3,uVar4);
  if (iVar1 == 0) {
    piVar2 = (int *)func_0x00763250(0x114);
    if (piVar2 == (int *)0x0) {
      func_0x007647d0(0x9d2f20,0x98abd8);
      return 0;
    }
    uVar7 = 1;
    uVar6 = 0;
    iVar1 = (*_DAT_009b3af0)(-param_3,0,0,0,(-(uint)((param_4 & 1) != 0) & 300) + 400,uVar4 >> 1 & 1
                             ,0,0,1,0,0,4,2,unaff_EBP);
    if (iVar1 == 0) {
      func_0x007647d0(0x9d2f20,0x98aba0);
      return 0;
    }
    piVar2[0x44] = uVar4;
    *piVar2 = iVar1;
    piVar2[0x42] = param_3;
    iVar1 = FUN_0078d850(iVar1,uVar7);
    piVar2[0x43] = iVar1;
    *(short *)(piVar2 + 0x41) = (short)uVar7;
    wcscpy(piVar2 + 1,uVar6);
    if ((*(int *)(param_1 + 0x28) <= *(int *)(param_1 + 0x24)) && (*(int *)(param_1 + 0x2c) != 0)) {
      iVar5 = *(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x28);
      iVar1 = func_0x00763250(iVar5 * 4);
      if (iVar1 == 0) {
        func_0x00764590(1,0x94e51c);
      }
      else {
        iVar3 = 0;
        if (0 < *(int *)(param_1 + 0x24)) {
          do {
            iVar3 = iVar3 + 1;
            *(undefined4 *)(iVar1 + -4 + iVar3 * 4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x20) + -4 + iVar3 * 4);
          } while (iVar3 < *(int *)(param_1 + 0x24));
        }
        if (*(int *)(param_1 + 0x20) != 0) {
          func_0x00763260(*(int *)(param_1 + 0x20));
        }
        *(int *)(param_1 + 0x20) = iVar1;
        *(int *)(param_1 + 0x28) = iVar5;
      }
    }
    *(int **)(*(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x24) * 4) = piVar2;
    iVar1 = *(int *)(param_1 + 0x24) + 1;
    *(int *)(param_1 + 0x24) = iVar1;
  }
  return iVar1;
}


/* ==================================================================== */
/* Address: 0x0078d6e0 | Classified: Angelica3D::proc_78d6e0 */
/* ==================================================================== */

int __thiscall FUN_0078d6e0(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x20) + iVar2 * 4);
      if (((param_3 == *(int *)(iVar1 + 0x108)) && (param_4 == *(int *)(iVar1 + 0x110))) &&
         (iVar1 = wcscmp(param_2,iVar1 + 4), iVar1 == 0)) {
        return iVar2 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x24));
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x0078d740 | Classified: Angelica3D::proc_78d740 */
/* ==================================================================== */

undefined4 __thiscall FUN_0078d740(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_retaddr;
  
  uVar1 = SelectObject(*(undefined4 *)(param_1 + 8),
                       **(undefined4 **)(*(int *)(param_1 + 0x20) + -4 + param_2 * 4));
  uVar2 = SelectObject(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
  FUN_0078d810(unaff_EBP,unaff_EBX,unaff_retaddr,param_2);
  SelectObject(*(undefined4 *)(param_1 + 8),uVar2);
  SelectObject(*(undefined4 *)(param_1 + 8),uVar1);
  return 1;
}


/* ==================================================================== */
/* Address: 0x0078d7a0 | Classified: Angelica3D::proc_78d7a0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0078d7a0(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = SelectObject(*(undefined4 *)(param_1 + 8),
                       **(undefined4 **)(*(int *)(param_1 + 0x20) + -4 + param_2 * 4));
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  uVar1 = SelectObject(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  return 1;
}


/* ==================================================================== */
/* Address: 0x0078d7e0 | Classified: Angelica3D::proc_78d7e0 */
/* ==================================================================== */

undefined4 __fastcall FUN_0078d7e0(int param_1)

{
  SelectObject(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x10));
  SelectObject(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x14));
  return 1;
}


/* ==================================================================== */
/* Address: 0x0078d810 | Classified: Angelica3D::proc_78d810 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0078d810(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *unaff_retaddr;
  undefined4 uVar1;
  undefined1 auStack_8 [4];
  undefined4 *puStack_4;
  
  uVar1 = *(undefined4 *)(param_1 + 8);
  (*_DAT_009b3b04)(uVar1,param_2,param_3,auStack_8);
  if (puStack_4 != (undefined4 *)0x0) {
    *puStack_4 = uVar1;
  }
  if (unaff_retaddr != (undefined4 *)0x0) {
    *unaff_retaddr = param_2;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0078d850 | Classified: Angelica3D::proc_78d850 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * __thiscall FUN_0078d850(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 auStack_8 [8];
  
  uVar1 = SelectObject(*(undefined4 *)(param_1 + 8),param_2);
  uVar2 = SelectObject(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
  puVar3 = auStack_8;
  (*_DAT_009b3b04)(*(undefined4 *)(param_1 + 8),puVar3,1,&stack0xffffffe8);
  SelectObject(*(undefined4 *)(param_1 + 8),uVar2);
  SelectObject(*(undefined4 *)(param_1 + 8),uVar1);
  return puVar3;
}


/* ==================================================================== */
/* Address: 0x0078d8b0 | Classified: elementclient::A3DFontMan__CreateA3DFont__Not_e@0x78d8b0 */
/* ==================================================================== */

int __thiscall
FUN_0078d8b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ccc7b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar2 = func_0x00763250(0x68);
  uStack_4 = 0;
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0078daf0();
  }
  uStack_4 = 0xffffffff;
  if (iVar2 == 0) {
    func_0x007647d0(0x9d2f20,0x98ac48);
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  cVar1 = FUN_0078dcd0(*(undefined4 *)(param_1 + 4),param_2,param_3,param_4,param_5);
  if (cVar1 == '\0') {
    func_0x007647d0(0x9d2f20,0x98ac0c);
    *unaff_FS_OFFSET = param_4;
    return 0;
  }
  if ((*(int *)(param_1 + 0x40) <= *(int *)(param_1 + 0x3c)) && (*(int *)(param_1 + 0x44) != 0)) {
    iVar5 = *(int *)(param_1 + 0x44) + *(int *)(param_1 + 0x40);
    iVar3 = func_0x00763250(iVar5 * 4);
    if (iVar3 == 0) {
      func_0x00764590(1,0x94e51c);
    }
    else {
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x3c)) {
        do {
          iVar4 = iVar4 + 1;
          *(undefined4 *)(iVar3 + -4 + iVar4 * 4) =
               *(undefined4 *)(*(int *)(param_1 + 0x38) + -4 + iVar4 * 4);
        } while (iVar4 < *(int *)(param_1 + 0x3c));
      }
      if (*(int *)(param_1 + 0x38) != 0) {
        func_0x00763260(*(int *)(param_1 + 0x38));
      }
      *(int *)(param_1 + 0x38) = iVar3;
      *(int *)(param_1 + 0x40) = iVar5;
    }
  }
  *(int *)(*(int *)(param_1 + 0x38) + *(int *)(param_1 + 0x3c) * 4) = iVar2;
  *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
  *unaff_FS_OFFSET = param_4;
  return iVar2;
}


/* ==================================================================== */
/* Address: 0x0078da10 | Classified: Angelica3D::proc_78da10 */
/* ==================================================================== */

void __thiscall FUN_0078da10(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x3c)) {
    piVar1 = *(int **)(param_1 + 0x38);
    while ((undefined4 *)*piVar1 != param_2) {
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
      if (*(int *)(param_1 + 0x3c) <= iVar2) {
        return;
      }
    }
    FUN_0078dda0();
    if (param_2 != (undefined4 *)0x0) {
      (**(code **)*param_2)(1);
    }
    if (iVar2 != *(int *)(param_1 + 0x3c) + -1) {
      *(undefined4 *)(*(int *)(param_1 + 0x38) + iVar2 * 4) =
           *(undefined4 *)(*(int *)(param_1 + 0x38) + -4 + *(int *)(param_1 + 0x3c) * 4);
    }
    *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + -1;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0078da70 | Classified: Angelica3D::proc_78da70 */
/* ==================================================================== */

void __fastcall FUN_0078da70(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x3c)) {
    do {
      FUN_0078f6c0();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x3c));
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0078daa0 | Classified: Angelica3D::proc_78daa0 */
/* ==================================================================== */

void __fastcall FUN_0078daa0(undefined4 *param_1)

{
  *param_1 = &UNK_008f1024;
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
/* Address: 0x0078dad0 | Classified: Angelica3D::proc_78dad0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0078dad0(undefined4 param_1,byte param_2)

{
  FUN_0078daa0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0078daf0 | Classified: Angelica3D::proc_78daf0 */
/* ==================================================================== */

undefined4 * __fastcall FUN_0078daf0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008ccc9b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1[0xf] = &UNK_008d5a30;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0x10;
  param_1[0xe] = &UNK_008f109c;
  uStack_4 = 0;
  param_1[0x15] = 0;
  iVar2 = 0;
  do {
    if (0x400 < *(uint *)(&UNK_008f1028 + iVar2 * 4)) {
      iVar2 = *(int *)(&UNK_008f1028 + iVar2 * 4);
      goto LAB_0078db4f;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x1c);
  iVar2 = -1;
LAB_0078db4f:
  param_1[0x18] = iVar2;
  if (iVar2 == 0) {
    param_1[0x16] = 0;
  }
  else {
    uVar3 = func_0x00763250(iVar2 * 4);
    param_1[0x16] = uVar3;
  }
  param_1[0x17] = param_1[0x16];
  param_1[0x19] = iVar2;
  for (; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = (undefined4 *)param_1[0x17];
    param_1[0x17] = puVar1 + 1;
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = 0;
    }
  }
  *param_1 = &UNK_008f1098;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  *(undefined1 *)((int)param_1 + 0x15) = 1;
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[8] = 0;
  param_1[7] = 0;
  param_1[6] = 0x100;
  param_1[9] = 0;
  param_1[10] = 0;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0078dbe0 | Classified: Angelica3D::proc_78dbe0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0078dbe0(undefined4 param_1,byte param_2)

{
  FUN_0078dc00();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0078dc00 | Classified: Angelica3D::proc_78dc00 */
/* ==================================================================== */

void __fastcall FUN_0078dc00(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 unaff_EBX;
  uint uVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008cccbb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f1098;
  uVar4 = 0;
  uStack_4 = 0;
  if (param_1[0x19] != 0) {
    do {
      puVar3 = *(undefined4 **)(param_1[0x16] + uVar4 * 4);
      while (puVar3 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar3;
        func_0x00763260(puVar3);
        puVar3 = puVar1;
      }
      uVar4 = uVar4 + 1;
      *(undefined4 *)(param_1[0x16] + -4 + uVar4 * 4) = 0;
    } while (uVar4 < (uint)param_1[0x19]);
  }
  param_1[0x15] = 0;
  iVar2 = param_1[0x16];
  func_0x007d05c0(iVar2,iVar2 + param_1[0x19] * 4);
  iVar2 = param_1[0x16];
  if (iVar2 != 0) {
    func_0x00763260(iVar2);
  }
  param_1[0xe] = &UNK_008f109c;
  uStack_c = 0xffffffff;
  param_1[0xf] = &UNK_008d5a30;
  if (param_1[0x10] != 0) {
    func_0x00763260(param_1[0x10]);
    param_1[0x10] = 0;
  }
  param_1[0x12] = 0;
  param_1[0x11] = 0;
  *unaff_FS_OFFSET = unaff_EBX;
  return;
}


/* ==================================================================== */
/* Address: 0x0078dcd0 | Classified: elementclient::A3DFont__Init__Failed_to_create_s@0x78dcd0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_0078dcd0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  
  if ((param_2 != 0) && (param_3 != 0)) {
    if (_DAT_00988334 == 4) {
      *(undefined1 *)(param_1 + 0x14) = 1;
      return 1;
    }
    *(int *)(param_1 + 4) = param_2;
    *(int *)(param_1 + 0xc) = param_3;
    if (param_4 < 0x21) {
      param_4 = 0x20;
    }
    *(int *)(param_1 + 0x18) = param_4;
    *(int *)(param_1 + 0x1c) = param_4 * 4;
    *(int *)(param_1 + 0x20) = param_4 * 6;
    if (param_5 < 0x41) {
      param_5 = 0x40;
    }
    *(int *)(param_1 + 0x24) = param_5;
    if (param_6 < 0x41) {
      param_6 = 0x40;
    }
    *(int *)(param_1 + 0x28) = param_6;
    iVar1 = *(int *)(*(int *)(param_2 + 0x164) + 0x58);
    *(int *)(param_1 + 8) = iVar1;
    uVar2 = *(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x20) + -4 + param_3 * 4) + 0x10c);
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x2c) = uVar2;
    *(undefined4 *)(param_1 + 0x34) = 0;
    cVar3 = FUN_0078df10();
    if (cVar3 != '\0') {
      return 1;
    }
    func_0x007647d0(0x9d2f20,0x98ac78);
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x0078dda0 | Classified: Angelica3D::proc_78dda0 */
/* ==================================================================== */

/* WARNING: Removing unreachable block (ram,0x0078de54) */

void __fastcall FUN_0078dda0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int *piStack_8;
  undefined4 *puStack_4;
  
  if (*(char *)(param_1 + 0x14) != '\0') {
    return;
  }
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x44)) {
    do {
      FUN_0078e1f0(*(undefined4 *)(*(int *)(param_1 + 0x40) + iVar3 * 4));
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x44));
  }
  if (*(int *)(param_1 + 0x40) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x40));
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  puStack_4 = (undefined4 *)0x0;
  piStack_8 = *(int **)(param_1 + 0x58);
  if (piStack_8 == (int *)(*(int *)(param_1 + 0x58) + *(int *)(param_1 + 100) * 4))
  goto LAB_0078de4c;
  puStack_4 = (undefined4 *)*piStack_8;
  if (puStack_4 == (undefined4 *)0x0) {
    FUN_00793ff0();
  }
LAB_0078de36:
  do {
    do {
      if (piStack_8 == (int *)0x0) {
        if (puStack_4 == (undefined4 *)0x0) {
          uVar4 = 0;
          if (*(int *)(param_1 + 100) != 0) {
            do {
              puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x58) + uVar4 * 4);
              while (puVar2 != (undefined4 *)0x0) {
                puVar1 = (undefined4 *)*puVar2;
                func_0x00763260(puVar2);
                puVar2 = puVar1;
              }
              uVar4 = uVar4 + 1;
              *(undefined4 *)(*(int *)(param_1 + 0x58) + -4 + uVar4 * 4) = 0;
            } while (uVar4 < *(uint *)(param_1 + 100));
          }
          *(undefined4 *)(param_1 + 0x54) = 0;
          if (*(int *)(param_1 + 0x10) != 0) {
            func_0x00785220();
            if (*(undefined4 **)(param_1 + 0x10) != (undefined4 *)0x0) {
              (**(code **)**(undefined4 **)(param_1 + 0x10))(1);
            }
            *(undefined4 *)(param_1 + 0x10) = 0;
          }
          *(undefined4 *)(param_1 + 4) = 0;
          return;
        }
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = puStack_4 + 1;
      }
      func_0x00763260(*puVar2);
    } while (piStack_8 == (int *)0x0);
    if (puStack_4 == (undefined4 *)0x0) goto LAB_0078de7e;
    puStack_4 = (undefined4 *)*puStack_4;
    while (puStack_4 == (undefined4 *)0x0) {
LAB_0078de7e:
      piStack_8 = piStack_8 + 1;
      if (piStack_8 == (int *)(*(int *)(param_1 + 0x58) + *(int *)(param_1 + 100) * 4))
      goto LAB_0078de4c;
      puStack_4 = (undefined4 *)*piStack_8;
    }
  } while( true );
LAB_0078de4c:
  piStack_8 = (int *)0x0;
  goto LAB_0078de36;
}


/* ==================================================================== */
/* Address: 0x0078df10 | Classified: elementclient::A3DFont__CreateStream_Not_Enough@0x78df10 */
/* ==================================================================== */

undefined4 __fastcall FUN_0078df10(int param_1)

{
  short sVar1;
  char cVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cccdb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_20 = 0x48;
  uStack_24 = 0x78df33;
  iVar3 = func_0x00763250();
  iVar5 = 0;
  uStack_4 = 0;
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    uStack_20 = 0x78df4b;
    iVar3 = func_0x00784d70();
  }
  uStack_4 = 0xffffffff;
  *(int *)(param_1 + 0x10) = iVar3;
  if (iVar3 == 0) {
    uStack_20 = 0x98ad3c;
    uStack_24 = 0x9d2f20;
    uStack_28 = 0x78df6d;
    func_0x007647d0();
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  uStack_28 = *(undefined4 *)(param_1 + 0x20);
  uStack_2c = *(undefined4 *)(param_1 + 0x1c);
  uStack_20 = 1;
  uStack_24 = 2;
  uVar7 = *(undefined4 *)(param_1 + 4);
  cVar2 = func_0x00784dd0(uVar7,2);
  if (cVar2 == '\0') {
    func_0x007647d0(0x9d2f20,0x98ad0c);
    *unaff_FS_OFFSET = uStack_24;
    return 0;
  }
  puVar6 = &uStack_2c;
  cVar2 = func_0x00785700(0,0,puVar6,0);
  if (cVar2 != '\0') {
    sVar4 = 0;
    if (0 < *(int *)(param_1 + 0x18)) {
      iVar3 = 4;
      do {
        iVar5 = iVar5 + 1;
        *(short *)(iVar3 + -4 + (int)puVar6) = sVar4;
        *(short *)(iVar3 + -2 + (int)puVar6) = sVar4 + 1;
        *(short *)(iVar3 + (int)puVar6) = sVar4 + 2;
        *(short *)(iVar3 + 2 + (int)puVar6) = sVar4 + 2;
        *(short *)(iVar3 + 4 + (int)puVar6) = sVar4 + 1;
        sVar1 = sVar4 + 3;
        sVar4 = sVar4 + 4;
        *(short *)(iVar3 + 6 + (int)puVar6) = sVar1;
        iVar3 = iVar3 + 0xc;
      } while (iVar5 < *(int *)(param_1 + 0x18));
    }
    cVar2 = func_0x00785810();
    if (cVar2 != '\0') {
      *unaff_FS_OFFSET = uVar7;
      return 1;
    }
    func_0x007647d0(0x9d2f20,0x98aca4);
    *unaff_FS_OFFSET = uVar7;
    return 0;
  }
  func_0x007647d0(0x9d2f20,0x98acd8);
  *unaff_FS_OFFSET = uVar7;
  return 0;
}


/* ==================================================================== */
/* Address: 0x0078e0a0 | Classified: elementclient::A3DFont__AllocTextureSlot__Faile@0x78e0a0 */
/* ==================================================================== */

int * __fastcall FUN_0078e0a0(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *unaff_FS_OFFSET;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cccfb;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  piVar2 = (int *)func_0x00763250(0x10);
  if (piVar2 == (int *)0x0) {
    *unaff_FS_OFFSET = iStack_c;
    return (int *)0x0;
  }
  iVar3 = func_0x00763250(0x3c);
  uStack_4 = 0;
  if (iVar3 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = func_0x0078a330();
  }
  uStack_4 = 0xffffffff;
  *piVar2 = iVar4;
  if (iVar4 == 0) {
    FUN_0078e1f0(piVar2);
    func_0x007647d0(0x9d2f20,0x98add4);
    *unaff_FS_OFFSET = iVar3;
    return (int *)0x0;
  }
  iVar3 = *(int *)(param_1 + 0x28);
  iVar4 = 0x1a;
  cVar1 = func_0x0078a710(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x24),iVar3,0x1a,1)
  ;
  if (cVar1 == '\0') {
    FUN_0078e1f0(piVar2);
    func_0x007647d0(0x9d2f20,0x98ad9c);
    *unaff_FS_OFFSET = iVar3;
    return (int *)0x0;
  }
  iVar5 = func_0x007631a0(*(int *)(param_1 + 0x1c) << 5);
  piVar2[1] = iVar5;
  if (iVar5 == 0) {
    FUN_0078e1f0(piVar2);
    func_0x007647d0(0x9d2f20,0x98ad68);
    *unaff_FS_OFFSET = iVar3;
    return (int *)0x0;
  }
  piVar2[2] = 0;
  piVar2[3] = 0;
  *unaff_FS_OFFSET = iVar4;
  return piVar2;
}


/* ==================================================================== */
/* Address: 0x0078e1f0 | Classified: Angelica3D::proc_78e1f0 */
/* ==================================================================== */

void FUN_0078e1f0(int *param_1)

{
  if (param_1 != (int *)0x0) {
    if ((int *)*param_1 != (int *)0x0) {
      (**(code **)(*(int *)*param_1 + 0xc))();
      if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*param_1)(1);
      }
    }
    if (param_1[1] != 0) {
      func_0x007631b0(param_1[1]);
    }
    func_0x00763260(param_1);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0078e230 | Classified: Angelica3D::proc_78e230 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0078e230(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 *puVar2;
  char cVar3;
  ushort *puVar4;
  undefined4 uVar5;
  float fVar6;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  int unaff_retaddr;
  float fStack_40;
  float fStack_34;
  undefined4 *puStack_30;
  char cStack_2c;
  undefined *puStack_24;
  undefined *puStack_20;
  int iStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_8 = &UNK_008ccd18;
  *unaff_FS_OFFSET = &uStack_c;
  if (*(char *)(param_1 + 0x14) == '\0') {
    puStack_20 = &UNK_008d5a30;
    iStack_1c = 0;
    iStack_18 = 0;
    uStack_14 = 0;
    uStack_10 = 0x10;
    puStack_24 = &UNK_008f10a0;
    uStack_4 = 0;
    fStack_34 = _DAT_008effa0 / (float)*(int *)(param_1 + 0x28);
    FUN_0078d7a0(*(undefined4 *)(param_1 + 0xc));
    fStack_40 = 0.0;
    if (0 < param_2) {
      do {
        uVar1 = *(ushort *)(unaff_retaddr + (int)fStack_40 * 2);
        fVar6 = (float)CONCAT22((short)((uint)unaff_retaddr >> 0x10),uVar1);
        if (uVar1 == 0) break;
        for (puVar2 = *(undefined4 **)
                       (*(int *)(param_1 + 0x58) + ((uint)uVar1 % *(uint *)(param_1 + 100)) * 4);
            puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
          if (*(ushort *)(puVar2 + 2) == uVar1) {
            puStack_30 = puVar2 + 1;
            cStack_2c = '\x01';
            goto LAB_0078e3de;
          }
        }
        fStack_34 = 0.0;
        func_0x004445b0(&fStack_34,&stack0xffffffb7);
        if (cStack_2c == '\0') {
          puVar4 = (ushort *)func_0x00763250(0x28);
          if (puVar4 == (ushort *)0x0) {
            FUN_0078d7e0();
            goto LAB_0078e45c;
          }
          *puVar4 = uVar1;
          cVar3 = FUN_0078e4a0(puVar4,fVar6);
          if (cVar3 == '\0') {
            FUN_0078d7e0();
            uStack_4 = 0xffffffff;
            puStack_24 = &UNK_008f10a0;
            puStack_20 = &UNK_008d5a30;
            if (iStack_1c != 0) {
              func_0x00763260(iStack_1c);
            }
            uVar5 = 0;
            goto LAB_0078e487;
          }
          *(float *)(unaff_EBP + 8) = (float)*(int *)(unaff_EBP + 0x18) * fVar6;
          *(float *)(unaff_EBP + 0xc) = (float)*(int *)(unaff_EBP + 0x1c) * fStack_40;
          *(float *)(unaff_EBP + 0x10) = (float)*(int *)(unaff_EBP + 0x20) * fVar6;
          *(float *)(unaff_EBP + 0x14) = (float)*(int *)(unaff_EBP + 0x24) * fStack_40;
          FUN_0078f790(*(int *)(param_1 + 0x54) + 1);
          FUN_0078f8b0(&stack0xffffffb0,&stack0xffffffac);
          if (iStack_18 <= iStack_1c) {
            func_0x0068e120(uStack_14);
          }
          *(ushort **)(puStack_20 + iStack_1c * 4) = puVar4;
          iStack_1c = iStack_1c + 1;
        }
LAB_0078e3de:
        fStack_40 = (float)((int)fStack_40 + 1);
      } while ((int)fStack_40 < param_2);
    }
    FUN_0078d7e0();
    if (iStack_18 != 0) {
      FUN_0078e670(&puStack_24);
    }
LAB_0078e45c:
    uStack_4 = 0xffffffff;
    puStack_24 = &UNK_008f10a0;
    puStack_20 = &UNK_008d5a30;
    if (iStack_1c != 0) {
      func_0x00763260(iStack_1c);
    }
  }
  uVar5 = 1;
LAB_0078e487:
  *unaff_FS_OFFSET = uStack_c;
  return uVar5;
}


/* ==================================================================== */
/* Address: 0x0078e4a0 | Classified: elementclient::A3DFont__CalculateCharPos__Faile@0x78e4a0 */
/* ==================================================================== */

uint __fastcall FUN_0078e4a0(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int aiStack_c [2];
  undefined1 auStack_4 [4];
  
  FUN_0078d810(&stack0x00000008,1,aiStack_c);
  if (*(int *)(param_1 + 0x44) != 0) {
    iVar1 = *(int *)(param_1 + 0x44) + -1;
    if ((int)(auStack_4 + *(int *)(param_1 + 0x34) + 1) <= *(int *)(param_1 + 0x24)) {
      *(int *)(aiStack_c[0] + 4) = iVar1;
      iVar1 = *(int *)(param_1 + 0x2c);
      iVar4 = *(int *)(param_1 + 0x30);
      iVar5 = *(int *)(param_1 + 0x34);
      *(int *)(aiStack_c[0] + 0x18) = iVar5;
      *(undefined4 *)(aiStack_c[0] + 0x1c) = *(undefined4 *)(param_1 + 0x30);
      *(undefined1 **)(aiStack_c[0] + 0x20) = auStack_4 + iVar5;
      *(int *)(aiStack_c[0] + 0x24) = iVar1 + iVar4;
      iVar1 = *(int *)(param_1 + 0x34);
      *(undefined1 **)(param_1 + 0x34) = auStack_4 + iVar1 + 1;
      return CONCAT31((int3)((uint)(auStack_4 + iVar1 + 1) >> 8),1);
    }
    *(undefined4 *)(param_1 + 0x34) = 0;
    iVar4 = *(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x2c) + 1;
    *(int *)(param_1 + 0x30) = iVar4;
    if (iVar4 + 1 + *(int *)(param_1 + 0x2c) <= *(int *)(param_1 + 0x28)) {
      *(int *)(aiStack_c[0] + 4) = iVar1;
      iVar1 = *(int *)(param_1 + 0x30);
      iVar4 = *(int *)(param_1 + 0x2c);
      iVar5 = *(int *)(param_1 + 0x34);
      *(int *)(aiStack_c[0] + 0x18) = iVar5;
      *(undefined4 *)(aiStack_c[0] + 0x1c) = *(undefined4 *)(param_1 + 0x30);
      *(undefined1 **)(aiStack_c[0] + 0x20) = auStack_4 + iVar5;
      *(int *)(aiStack_c[0] + 0x24) = iVar1 + iVar4;
      iVar1 = *(int *)(param_1 + 0x34);
      *(undefined1 **)(param_1 + 0x34) = auStack_4 + iVar1 + 1;
      return CONCAT31((int3)((uint)(auStack_4 + iVar1 + 1) >> 8),1);
    }
  }
  iVar1 = FUN_0078e0a0();
  if (iVar1 == 0) {
    uVar2 = func_0x007647d0(0x9d2f20,0x98ae10);
    return uVar2 & 0xffffff00;
  }
  if ((*(int *)(param_1 + 0x48) <= *(int *)(param_1 + 0x44)) && (*(int *)(param_1 + 0x4c) != 0)) {
    iVar5 = *(int *)(param_1 + 0x4c) + *(int *)(param_1 + 0x48);
    iVar4 = func_0x00763250(iVar5 * 4);
    if (iVar4 == 0) {
      func_0x00764590(1,0x94e51c);
    }
    else {
      iVar3 = 0;
      if (0 < *(int *)(param_1 + 0x44)) {
        do {
          iVar3 = iVar3 + 1;
          *(undefined4 *)(iVar4 + -4 + iVar3 * 4) =
               *(undefined4 *)(*(int *)(param_1 + 0x40) + -4 + iVar3 * 4);
        } while (iVar3 < *(int *)(param_1 + 0x44));
      }
      if (*(int *)(param_1 + 0x40) != 0) {
        func_0x00763260(*(int *)(param_1 + 0x40));
      }
      *(int *)(param_1 + 0x40) = iVar4;
      *(int *)(param_1 + 0x48) = iVar5;
    }
  }
  *(int *)(*(int *)(param_1 + 0x40) + *(int *)(param_1 + 0x44) * 4) = iVar1;
  *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(int *)(aiStack_c[0] + 4) = *(int *)(param_1 + 0x44) + -1;
  iVar1 = *(int *)(param_1 + 0x2c);
  iVar4 = *(int *)(param_1 + 0x30);
  iVar5 = *(int *)(param_1 + 0x34);
  *(int *)(aiStack_c[0] + 0x18) = iVar5;
  *(undefined4 *)(aiStack_c[0] + 0x1c) = *(undefined4 *)(param_1 + 0x30);
  *(undefined1 **)(aiStack_c[0] + 0x20) = auStack_4 + iVar5;
  *(int *)(aiStack_c[0] + 0x24) = iVar1 + iVar4;
  iVar1 = *(int *)(param_1 + 0x34);
  *(undefined1 **)(param_1 + 0x34) = auStack_4 + iVar1 + 1;
  return CONCAT31((int3)((uint)(auStack_4 + iVar1 + 1) >> 8),1);
}


/* ==================================================================== */
/* Address: 0x0078e670 | Classified: elementclient::A3DFont__PrintCharsOnTextures_fa@0x78e670 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __thiscall FUN_0078e670(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 unaff_EDI;
  undefined4 *puVar10;
  code *pcVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined1 uVar14;
  undefined4 uVar15;
  undefined4 *puStack_88;
  int iVar16;
  undefined4 uStack_60;
  undefined4 uStack_38;
  
  uVar14 = (undefined1)((uint)unaff_EDI >> 0x18);
  iVar5 = FUN_0078e870();
  pcVar11 = SelectObject_exref;
  if (iVar5 == 0) {
    return 0;
  }
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 8) + 8);
  uStack_60 = uStack_38;
  SelectObject(uVar1);
  uVar2 = **(undefined4 **)
            (*(int *)(*(int *)(param_1 + 8) + 0x20) + -4 + *(int *)(param_1 + 0xc) * 4);
  SelectObject(uVar1,uVar2);
  SetTextColor(uVar1);
  SetBkColor(uVar1);
  SetTextAlign(uVar1,0);
  puStack_88 = (undefined4 *)0x0;
  iVar6 = GetDC();
  iVar7 = SelectObject();
  iVar9 = 0;
  iVar16 = *(int *)(iVar5 + 0xc);
  if (0 < iVar16) {
    do {
      uVar15 = 0;
      iVar8 = *(int *)(*(int *)(iVar5 + 8) + iVar9 * 4);
      cVar4 = func_0x0078a7e0(0,&stack0xffffffa4,&uStack_60,0,0);
      if (cVar4 == '\0') {
        func_0x007647d0(0x9d2f20,0x98ae4c);
        pcVar11 = SelectObject_exref;
        break;
      }
      while ((iVar9 < iVar6 &&
             (iVar3 = *(int *)(*(int *)(iVar7 + 8) + iVar9 * 4),
             *(int *)(iVar3 + 4) == *(int *)(iVar8 + 4)))) {
        puVar10 = puStack_88;
        for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar10 = 0;
          puVar10 = puVar10 + 1;
        }
        uVar13 = 0;
        uVar12 = 1;
        for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
          *(undefined1 *)puVar10 = 0;
          puVar10 = (undefined4 *)((int)puVar10 + 1);
        }
        (*_DAT_009b3af8)(uVar1,0,0,2,0,iVar3,1,0);
        FUN_0078e950(iVar6,(int *)(iVar3 + 0x18),uVar15,uVar13,
                     (*(int *)(iVar3 + 0x20) - *(int *)(iVar3 + 0x18)) + 1,
                     (*(int *)(iVar3 + 0x24) - *(int *)(iVar3 + 0x1c)) + 1,uVar12);
        iVar9 = iVar9 + 1;
        iVar8 = iVar16;
      }
      func_0x0078a850();
      pcVar11 = SelectObject_exref;
    } while (iVar9 < iVar16);
  }
  (*pcVar11)(param_2,iVar7);
  ReleaseDC(0,param_2);
  (*pcVar11)(uVar1);
  (*pcVar11)(uVar1,uStack_60);
  DeleteObject(uVar2);
  return uVar14;
}


/* ==================================================================== */
/* Address: 0x007e0ed0 | Classified: Angelica3D::proc_7e0ed0 */
/* ==================================================================== */

undefined4 * __fastcall FUN_007e0ed0(undefined4 *param_1)

{
  func_0x007e8680();
  *param_1 = &UNK_008f3968;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[1] = 0x29;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007e0f00 | Classified: Angelica3D::proc_7e0f00 */
/* ==================================================================== */

bool FUN_007e0f00(undefined4 param_1)

{
  char cVar1;
  
  cVar1 = func_0x007b4540(param_1);
  return cVar1 != '\0';
}


/* ==================================================================== */
/* Address: 0x007e0f20 | Classified: Angelica3D::proc_7e0f20 */
/* ==================================================================== */

void __fastcall FUN_007e0f20(int param_1)

{
  FUN_007e3620();
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007e1180 | Classified: elementclient::A3DMuscleMesh__CreateOriginalBuf@0x7e1180 */
/* ==================================================================== */

undefined4 __thiscall FUN_007e1180(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  FUN_007e3620();
  if (0 < param_2) {
    iVar1 = func_0x00763250(param_2 * 0x30);
    *(int *)(param_1 + 0x54) = iVar1;
    if (iVar1 == 0) {
      func_0x007647d0(0x9d2f20,0x9933bc);
      return 0;
    }
  }
  if (0 < param_3) {
    iVar1 = func_0x00763250(param_3 * 2);
    *(int *)(param_1 + 0x58) = iVar1;
    if (iVar1 == 0) {
      func_0x007647d0(0x9d2f20,0x9933bc);
      return 0;
    }
  }
  *(int *)(param_1 + 0x1c) = param_2;
  *(int *)(param_1 + 0x20) = param_3;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007e1220 | Classified: Angelica3D::proc_7e1220 */
/* ==================================================================== */

undefined4 * __fastcall FUN_007e1220(undefined4 *param_1)

{
  func_0x007e8680();
  *param_1 = &UNK_008f3a10;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[1] = 0x23;
  param_1[0x1b] = 0x3f800000;
  param_1[0x1d] = 0x3f800000;
  param_1[0x1c] = 0x3e99999a;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007e1260 | Classified: Angelica3D::proc_7e1260 */
/* ==================================================================== */

void FUN_007e1260(void)

{
  FUN_007e13c0();
  return;
}


/* ==================================================================== */
/* Address: 0x007e12b0 | Classified: elementclient::A3DSuppleMesh__CreateOriginalBuf@0x7e12b0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007e12b0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  
  FUN_007e13c0();
  if (0 < param_2) {
    iVar1 = func_0x00763250(param_2 << 5);
    *(int *)(param_1 + 0x54) = iVar1;
    if (iVar1 == 0) {
      func_0x007647d0(0x9d2f20,0x9933f8);
      return 0;
    }
  }
  if (0 < param_3) {
    iVar1 = func_0x00763250(param_3 * 0x18);
    *(int *)(param_1 + 0x58) = iVar1;
    if (iVar1 == 0) {
      func_0x007647d0(0x9d2f20,0x9933f8);
      return 0;
    }
  }
  if (0 < param_4) {
    iVar1 = func_0x00763250(param_4 * 2);
    *(int *)(param_1 + 0x5c) = iVar1;
    if (iVar1 == 0) {
      func_0x007647d0(0x9d2f20,0x9933f8);
      return 0;
    }
  }
  if (0 < param_5) {
    iVar1 = func_0x00763250(param_5 << 4);
    *(int *)(param_1 + 0x60) = iVar1;
    if (iVar1 == 0) {
      func_0x007647d0(0x9d2f20,0x9933f8);
      return 0;
    }
  }
  *(int *)(param_1 + 0x68) = param_5;
  *(int *)(param_1 + 100) = param_2;
  *(int *)(param_1 + 0x1c) = param_3;
  *(int *)(param_1 + 0x20) = param_4;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007e13c0 | Classified: Angelica3D::proc_7e13c0 */
/* ==================================================================== */

void __fastcall FUN_007e13c0(int param_1)

{
  if (*(int *)(param_1 + 0x54) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x54));
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  if (*(int *)(param_1 + 0x58) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x58));
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  if (*(int *)(param_1 + 0x5c) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x5c));
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  if (*(int *)(param_1 + 0x60) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x60));
    *(undefined4 *)(param_1 + 0x60) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007e1740 | Classified: Angelica3D::proc_7e1740 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_007e1740(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  
  if ((*(int *)(param_1 + 100) != 0) && (*(int *)(param_1 + 0x54) != 0)) {
    iVar4 = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0x497423f0;
    *(undefined4 *)(param_1 + 0x40) = 0x497423f0;
    *(undefined4 *)(param_1 + 0x44) = 0x497423f0;
    *(undefined4 *)(param_1 + 0x48) = 0xc97423f0;
    *(undefined4 *)(param_1 + 0x4c) = 0xc97423f0;
    *(undefined4 *)(param_1 + 0x50) = 0xc97423f0;
    if (0 < *(int *)(param_1 + 100)) {
      iVar5 = 0;
      do {
        func_0x00774a10(*(int *)(param_1 + 0x54) + iVar5);
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 0x20;
      } while (iVar4 < *(int *)(param_1 + 100));
    }
    fVar1 = (*(float *)(param_1 + 0x3c) + *(float *)(param_1 + 0x48)) * _DAT_008eff98;
    fVar2 = (*(float *)(param_1 + 0x40) + *(float *)(param_1 + 0x4c)) * _DAT_008eff98;
    *(float *)(param_1 + 0x24) = fVar1;
    fVar3 = (*(float *)(param_1 + 0x44) + *(float *)(param_1 + 0x50)) * _DAT_008eff98;
    *(float *)(param_1 + 0x2c) = fVar3;
    *(float *)(param_1 + 0x28) = fVar2;
    *(float *)(param_1 + 0x30) = *(float *)(param_1 + 0x48) - fVar1;
    *(float *)(param_1 + 0x38) = *(float *)(param_1 + 0x50) - fVar3;
    *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x4c) - fVar2;
    return;
  }
  puVar6 = (undefined4 *)(param_1 + 0x24);
  for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007e1830 | Classified: Angelica3D::proc_7e1830 */
/* ==================================================================== */

undefined4 * __fastcall FUN_007e1830(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ceeb8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_007e2880();
  uStack_4 = 0;
  func_0x007db810();
  *param_1 = &UNK_008f3ab8;
  param_1[1] = 0x1f;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007e1890 | Classified: Angelica3D::proc_7e1890 */
/* ==================================================================== */

undefined4 __thiscall FUN_007e1890(undefined4 param_1,byte param_2)

{
  FUN_007e18b0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007e18b0 | Classified: Angelica3D::proc_7e18b0 */
/* ==================================================================== */

void __fastcall FUN_007e18b0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008ceed8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f3ab8;
  uStack_4 = 0;
  func_0x007db880();
  uStack_4 = 0xffffffff;
  func_0x007dc680();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x007e1950 | Classified: Angelica3D::proc_7e1950 */
/* ==================================================================== */

void __fastcall FUN_007e1950(int param_1)

{
  undefined4 unaff_ESI;
  
  func_0x007db8c0();
  if (*(int *)(param_1 + 0x5c) != 0) {
    func_0x00785220(unaff_ESI);
    if (*(undefined4 **)(param_1 + 0x5c) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x5c))(1);
    }
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  FUN_007e28f0();
  return;
}


/* ==================================================================== */
/* Address: 0x007e1970 | Classified: elementclient::A3DMorphRigidMesh__Load__Failed_t@0x7e1970 */
/* ==================================================================== */

undefined1 __thiscall FUN_007e1970(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 0x50);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x28c) != 0)) {
    *(undefined1 *)(param_1 + 0x60) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x60) = 1;
  }
  cVar2 = FUN_007e2930(param_2,param_3);
  if (cVar2 == '\0') {
    return 0;
  }
  cVar2 = func_0x007db940(param_2,param_3);
  if (cVar2 == '\0') {
    func_0x007647d0(0x9d2f20,0x993724);
    return 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007e1db0 | Classified: Angelica3D::proc_7e1db0 */
/* ==================================================================== */

int __fastcall FUN_007e1db0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_007e2f70();
  return *(int *)(param_1 + 0xa8) + iVar1;
}


/* ==================================================================== */
/* Address: 0x007e1dd0 | Classified: Angelica3D::proc_7e1dd0 */
/* ==================================================================== */

undefined4 * __fastcall FUN_007e1dd0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ceef8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_007e2fa0();
  uStack_4 = 0;
  func_0x007db810();
  *param_1 = &UNK_008f3b68;
  param_1[1] = 0x1e;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007e1e30 | Classified: Angelica3D::proc_7e1e30 */
/* ==================================================================== */

undefined4 __thiscall FUN_007e1e30(undefined4 param_1,byte param_2)

{
  FUN_007e1e50();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007e1e50 | Classified: Angelica3D::proc_7e1e50 */
/* ==================================================================== */

void __fastcall FUN_007e1e50(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008cef18;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f3b68;
  uStack_4 = 0;
  func_0x007db880();
  uStack_4 = 0xffffffff;
  FUN_007e3020();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x007e1f00 | Classified: Angelica3D::proc_7e1f00 */
/* ==================================================================== */

void __fastcall FUN_007e1f00(int param_1)

{
  undefined4 unaff_ESI;
  
  func_0x007db8c0();
  if (*(int *)(param_1 + 0x5c) != 0) {
    func_0x00785220(unaff_ESI);
    if (*(undefined4 **)(param_1 + 0x5c) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x5c))(1);
    }
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  if (*(int *)(param_1 + 0x60) != 0) {
    func_0x00785220(unaff_ESI);
    if (*(undefined4 **)(param_1 + 0x60) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x60))(1);
    }
    *(undefined4 *)(param_1 + 0x60) = 0;
  }
  func_0x007e4510();
  FUN_007e3620();
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined1 *)(param_1 + 0x68) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007e2010 | Classified: Angelica3D::proc_7e2010 */
/* ==================================================================== */

undefined4 __thiscall FUN_007e2010(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1[3] + 0x50);
  if (((iVar1 != 0) && (param_1[7] != 0)) && (param_1[8] != 0)) {
    if (*(int *)(iVar1 + 0x28c) == 1) {
      (**(code **)(*param_1 + 0x38))();
      uVar2 = func_0x007e4410();
      return uVar2;
    }
    uVar2 = FUN_007e3660(param_2);
    return uVar2;
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007e2860 | Classified: Angelica3D::proc_7e2860 */
/* ==================================================================== */

int __fastcall FUN_007e2860(int param_1)

{
  int iVar1;
  
  iVar1 = func_0x007e5220();
  return *(int *)(param_1 + 200) + iVar1;
}


/* ==================================================================== */
/* Address: 0x007e2880 | Classified: Angelica3D::proc_7e2880 */
/* ==================================================================== */

undefined4 * __fastcall FUN_007e2880(undefined4 *param_1)

{
  func_0x007e8680();
  *param_1 = &UNK_008f3c20;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[1] = 0x1d;
  *(undefined1 *)(param_1 + 0x18) = 1;
  param_1[0x19] = 0xffffffff;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007e28b0 | Classified: Angelica3D::proc_7e28b0 */
/* ==================================================================== */

void __fastcall FUN_007e28b0(int param_1)

{
  if (*(int *)(param_1 + 0x5c) != 0) {
    func_0x00785220();
    if (*(undefined4 **)(param_1 + 0x5c) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x5c))(1);
    }
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  FUN_007e28f0();
  return;
}


/* ==================================================================== */
/* Address: 0x007e28f0 | Classified: Angelica3D::proc_7e28f0 */
/* ==================================================================== */

void __fastcall FUN_007e28f0(int param_1)

{
  if (*(int *)(param_1 + 0x54) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x54));
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  if (*(int *)(param_1 + 0x58) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x58));
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007e2930 | Classified: elementclient::A3DRigidMesh__Load____Failed_to_r@0x7e2930 */
/* ==================================================================== */

undefined4 __thiscall FUN_007e2930(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 unaff_EBX;
  int unaff_retaddr;
  undefined4 uVar3;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  cVar1 = (**(code **)(*param_2 + 0x1c))(param_1 + 8);
  if (cVar1 == '\0') {
    uVar3 = 0x993968;
  }
  else {
    cVar1 = (**(code **)(*param_2 + 0x10))(&stack0xffffffe8,0x14,&stack0x00000000);
    if ((cVar1 == '\0') || (unaff_retaddr != 0x14)) {
      uVar3 = 0x99386c;
    }
    else {
      *(undefined4 *)(param_1 + 100) = unaff_EBX;
      *(undefined4 *)(param_1 + 0x20) = uStack_8;
      *(undefined4 *)(param_1 + 0x14) = uStack_14;
      *(undefined4 *)(param_1 + 0x1c) = uStack_c;
      *(undefined4 *)(param_1 + 0x18) = uStack_10;
      cVar1 = FUN_007e2b70(uStack_c,uStack_8);
      if (cVar1 != '\0') {
        if (0 < *(int *)(param_1 + 0x1c)) {
          iVar2 = *(int *)(param_1 + 0x1c) << 5;
          cVar1 = (**(code **)(*param_2 + 0x10))
                            (*(undefined4 *)(param_1 + 0x54),iVar2,&stack0x00000000);
          if ((cVar1 == '\0') || (iVar2 != 0x14)) {
            uVar3 = 0x993900;
            goto LAB_007e2a46;
          }
        }
        if (0 < *(int *)(param_1 + 0x20)) {
          iVar2 = *(int *)(param_1 + 0x20) * 2;
          cVar1 = (**(code **)(*param_2 + 0x10))
                            (*(undefined4 *)(param_1 + 0x58),iVar2,&stack0x00000000);
          if ((cVar1 == '\0') || (iVar2 != 0x14)) {
            uVar3 = 0x9938d0;
            goto LAB_007e2a46;
          }
        }
        if ((0 < *(int *)(param_1 + 0x1c)) && (0 < *(int *)(param_1 + 0x20))) {
          cVar1 = FUN_007e2c00();
          if (cVar1 == '\0') {
            uVar3 = 0x9938a0;
            goto LAB_007e2a46;
          }
        }
        FUN_007e2d90();
        return 1;
      }
      uVar3 = 0x993930;
    }
  }
LAB_007e2a46:
  func_0x007647d0(0x9d2f20,uVar3);
  return 0;
}


/* ==================================================================== */
/* Address: 0x007e2a60 | Classified: elementclient::A3DRigidMesh__Save____Failed_to_w@0x7e2a60 */
/* ==================================================================== */

undefined4 __thiscall FUN_007e2a60(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int unaff_retaddr;
  undefined4 uVar3;
  
  cVar1 = (**(code **)(*param_2 + 0x28))(param_1 + 8);
  if (cVar1 == '\0') {
    uVar3 = 0x993a30;
  }
  else {
    cVar1 = (**(code **)(*param_2 + 0x14))(&stack0xffffffe8,0x14,&stack0x00000000);
    if ((cVar1 != '\0') && (unaff_retaddr == 0x14)) {
      if ((*(int *)(param_1 + 0x54) != 0) && (*(int *)(param_1 + 0x1c) != 0)) {
        iVar2 = *(int *)(param_1 + 0x1c) << 5;
        cVar1 = (**(code **)(*param_2 + 0x14))(*(int *)(param_1 + 0x54),iVar2,&stack0x00000000);
        if ((cVar1 == '\0') || (iVar2 != 0x14)) {
          uVar3 = 0x9939fc;
          goto LAB_007e2b4d;
        }
      }
      if ((*(int *)(param_1 + 0x58) != 0) && (*(int *)(param_1 + 0x20) != 0)) {
        iVar2 = *(int *)(param_1 + 0x20) * 2;
        cVar1 = (**(code **)(*param_2 + 0x14))(*(int *)(param_1 + 0x58),iVar2,&stack0x00000000);
        if ((cVar1 == '\0') || (iVar2 != 0x14)) {
          uVar3 = 0x9939cc;
          goto LAB_007e2b4d;
        }
      }
      return 1;
    }
    uVar3 = 0x993998;
  }
LAB_007e2b4d:
  func_0x007647d0(0x9d2f20,uVar3);
  return 0;
}


/* ==================================================================== */
/* Address: 0x007e2b70 | Classified: elementclient::A3DRigidMesh__CreateOriginalBuff@0x7e2b70 */
/* ==================================================================== */

undefined4 __thiscall FUN_007e2b70(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  FUN_007e28f0();
  if (0 < param_2) {
    iVar1 = func_0x00763250(param_2 << 5);
    *(int *)(param_1 + 0x54) = iVar1;
    if (iVar1 == 0) {
      func_0x007647d0(0x9d2f20,0x993a64);
      return 0;
    }
  }
  if (0 < param_3) {
    iVar1 = func_0x00763250(param_3 * 2);
    *(int *)(param_1 + 0x58) = iVar1;
    if (iVar1 == 0) {
      func_0x007647d0(0x9d2f20,0x993a64);
      return 0;
    }
  }
  *(int *)(param_1 + 0x20) = param_3;
  *(int *)(param_1 + 0x1c) = param_2;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007e2c00 | Classified: elementclient::A3DRigidMesh__CreateStream__Not_E@0x7e2c00 */
/* ==================================================================== */

undefined4 __fastcall FUN_007e2c00(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cef3b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 0x50);
  if (iVar1 != 0) {
    if (*(int *)(param_1 + 0x5c) != 0) {
      func_0x00785220();
      if (*(undefined4 **)(param_1 + 0x5c) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(param_1 + 0x5c))(1);
      }
    }
    iVar3 = func_0x00763250(0x48);
    uStack_4 = 0;
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = func_0x00784d70();
    }
    uStack_4 = 0xffffffff;
    *(int *)(param_1 + 0x5c) = iVar3;
    if (iVar3 == 0) {
      func_0x007647d0(0x9d2f20,0x993b60);
      *unaff_FS_OFFSET = uStack_c;
      return 0;
    }
    uVar4 = 2;
    if (*(char *)(param_1 + 0x60) != '\0') {
      uVar4 = 3;
    }
    uVar6 = *(undefined4 *)(param_1 + 0x20);
    uVar5 = 0;
    cVar2 = func_0x00784dd0(iVar1,0,*(undefined4 *)(param_1 + 0x1c),uVar6,uVar4,uVar4);
    if (cVar2 == '\0') {
      func_0x007647d0(0x9d2f20,0x993b20);
      *unaff_FS_OFFSET = uVar6;
      return 0;
    }
    if (*(char *)(param_1 + 0x60) != '\0') {
      cVar2 = func_0x007852e0(*(undefined4 *)(param_1 + 0x54),*(undefined4 *)(param_1 + 0x1c));
      if (cVar2 == '\0') {
        func_0x007647d0(0x9d2f20,0x993ae0);
        *unaff_FS_OFFSET = uVar5;
        return 0;
      }
      func_0x007859c0(*(undefined4 *)(param_1 + 0x54));
      func_0x007859e0(*(undefined4 *)(param_1 + 0x58));
    }
    cVar2 = func_0x00785420(*(undefined4 *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x20));
    if (cVar2 == '\0') {
      func_0x007647d0(0x9d2f20,0x993aa0);
      *unaff_FS_OFFSET = uStack_c;
      return 0;
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007e2d90 | Classified: Angelica3D::proc_7e2d90 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_007e2d90(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  if ((*(int *)(param_1 + 0x1c) != 0) && (*(int *)(param_1 + 0x54) != 0)) {
    iVar5 = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0x497423f0;
    *(undefined4 *)(param_1 + 0x40) = 0x497423f0;
    *(undefined4 *)(param_1 + 0x44) = 0x497423f0;
    *(undefined4 *)(param_1 + 0x48) = 0xc97423f0;
    *(undefined4 *)(param_1 + 0x4c) = 0xc97423f0;
    *(undefined4 *)(param_1 + 0x50) = 0xc97423f0;
    if (0 < *(int *)(param_1 + 0x1c)) {
      iVar6 = 0;
      do {
        puVar4 = (undefined4 *)(*(int *)(param_1 + 0x54) + iVar6);
        uStack_10 = puVar4[2];
        uStack_14 = puVar4[1];
        uStack_18 = *puVar4;
        func_0x00774a10(&uStack_18);
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + 0x20;
      } while (iVar5 < *(int *)(param_1 + 0x1c));
    }
    fVar1 = (*(float *)(param_1 + 0x3c) + *(float *)(param_1 + 0x48)) * _DAT_008eff98;
    fVar2 = (*(float *)(param_1 + 0x40) + *(float *)(param_1 + 0x4c)) * _DAT_008eff98;
    *(float *)(param_1 + 0x24) = fVar1;
    fVar3 = (*(float *)(param_1 + 0x44) + *(float *)(param_1 + 0x50)) * _DAT_008eff98;
    *(float *)(param_1 + 0x2c) = fVar3;
    *(float *)(param_1 + 0x28) = fVar2;
    *(float *)(param_1 + 0x30) = *(float *)(param_1 + 0x48) - fVar1;
    *(float *)(param_1 + 0x38) = *(float *)(param_1 + 0x50) - fVar3;
    *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x4c) - fVar2;
    return;
  }
  puVar4 = (undefined4 *)(param_1 + 0x24);
  for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007e2e90 | Classified: Angelica3D::proc_7e2e90 */
/* ==================================================================== */

undefined1 __thiscall FUN_007e2e90(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  if ((((*(int *)(param_1[3] + 0x50) != 0) && (param_1[0x17] != 0)) && (param_1[7] != 0)) &&
     (param_1[8] != 0)) {
    if (*(int *)(*(int *)(param_1[3] + 0x50) + 0x28c) == 0) {
      func_0x00785550(0,0);
      iVar1 = param_1[8];
      iVar3 = param_1[7];
    }
    else {
      if ((char)param_1[0x18] == '\0') {
        cVar2 = (**(code **)(*param_1 + 0x34))(param_2,param_3);
        if (cVar2 != '\0') {
          return 1;
        }
        return 0;
      }
      func_0x00779ca0(param_1[0x19] * 0x40 + *(int *)(param_3 + 900));
      func_0x00785550(0,1);
      iVar1 = param_1[8];
      iVar3 = param_1[7];
    }
    cVar2 = func_0x0077a590(4,0,iVar3,0,iVar1 / 3);
    if (cVar2 == '\0') {
      return 0;
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007e2f70 | Classified: Angelica3D::proc_7e2f70 */
/* ==================================================================== */

int __fastcall FUN_007e2f70(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0x54) != 0) {
    iVar1 = *(int *)(param_1 + 0x1c) << 5;
  }
  if (*(int *)(param_1 + 0x58) != 0) {
    iVar1 = iVar1 + *(int *)(param_1 + 0x20) * 2;
  }
  return iVar1 * 2;
}


/* ==================================================================== */
/* Address: 0x007e2fa0 | Classified: Angelica3D::proc_7e2fa0 */
/* ==================================================================== */

undefined4 * __fastcall FUN_007e2fa0(undefined4 *param_1)

{
  func_0x007e8680();
  param_1[0x1d] = &UNK_008d5a30;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0x10;
  param_1[0x1c] = &UNK_008f3d0c;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  *(undefined1 *)(param_1 + 0x1a) = 0;
  param_1[0x1b] = 0;
  *param_1 = &UNK_008f3cc8;
  param_1[1] = 0x1c;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007e3000 | Classified: Angelica3D::proc_7e3000 */
/* ==================================================================== */

undefined4 __thiscall FUN_007e3000(undefined4 param_1,byte param_2)

{
  FUN_007e3020();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007e3020 | Classified: Angelica3D::proc_7e3020 */
/* ==================================================================== */

void __fastcall FUN_007e3020(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008cef58;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f3cc8;
  param_1[0x1c] = &UNK_008f3d0c;
  param_1[0x1d] = &UNK_008d5a30;
  uStack_4 = 0;
  if (param_1[0x1e] != 0) {
    func_0x00763260(param_1[0x1e]);
    param_1[0x1e] = 0;
  }
  param_1[0x20] = 0;
  param_1[0x1f] = 0;
  uStack_4 = 0xffffffff;
  *param_1 = &UNK_008d6410;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x007e30a0 | Classified: Angelica3D::proc_7e30a0 */
/* ==================================================================== */

void __fastcall FUN_007e30a0(int param_1)

{
  if (*(int *)(param_1 + 0x5c) != 0) {
    func_0x00785220();
    if (*(undefined4 **)(param_1 + 0x5c) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x5c))(1);
    }
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  if (*(int *)(param_1 + 0x60) != 0) {
    func_0x00785220();
    if (*(undefined4 **)(param_1 + 0x60) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x60))(1);
    }
    *(undefined4 *)(param_1 + 0x60) = 0;
  }
  func_0x007e4510();
  FUN_007e3620();
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined1 *)(param_1 + 0x68) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007e3100 | Classified: elementclient::A3DSkinMesh__Load__Failed_to_loa@0x7e3100 */
/* ==================================================================== */

undefined4 __thiscall FUN_007e3100(int *param_1,undefined4 param_2)

{
  char cVar1;
  
  if (*(int *)(param_1[3] + 0x50) == 0) {
    param_1[0x1b] = 2;
  }
  else {
    param_1[0x1b] = *(int *)(*(int *)(param_1[3] + 0x50) + 0x28c);
  }
  cVar1 = (**(code **)(*param_1 + 0x3c))(param_2);
  if (cVar1 == '\0') {
    func_0x007647d0(0x9d2f20,0x993bc0);
    return 0;
  }
  cVar1 = (**(code **)(*param_1 + 0x40))(param_2);
  if (cVar1 == '\0') {
    func_0x007647d0(0x9d2f20,0x993b90);
    return 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007e3180 | Classified: elementclient::A3DSkinMesh__LoadData__Failed_to@0x7e3180 */
/* ==================================================================== */

undefined4 __thiscall FUN_007e3180(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_EBX;
  int iVar5;
  undefined4 *puVar6;
  int unaff_EDI;
  undefined4 *puVar7;
  int *unaff_retaddr;
  undefined4 uVar8;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  cVar1 = (**(code **)(*param_2 + 0x1c))(param_1 + 8);
  if (cVar1 == '\0') {
    uVar8 = 0x993cbc;
  }
  else {
    cVar1 = (**(code **)(*param_2 + 0x10))(&uStack_14,0x10,&stack0xffffffe8);
    if ((cVar1 == '\0') || (unaff_EBX != 0x10)) {
      uVar8 = 0x993be8;
    }
    else {
      *(undefined4 *)(param_1 + 0x14) = uStack_14;
      *(undefined4 *)(param_1 + 0x20) = uStack_8;
      *(undefined4 *)(param_1 + 0x1c) = uStack_c;
      *(undefined4 *)(param_1 + 0x18) = uStack_10;
      cVar1 = FUN_007e3590(uStack_c,uStack_8);
      if (cVar1 != '\0') {
        if (0 < *(int *)(param_1 + 0x1c)) {
          iVar5 = *(int *)(param_1 + 0x1c) * 0x30;
          iVar2 = func_0x00763250(iVar5);
          cVar1 = (**(code **)(*param_2 + 0x10))(iVar2,iVar5,&stack0xffffffe8);
          if ((cVar1 == '\0') || (unaff_EDI != iVar5)) {
            func_0x00763260(iVar2);
            func_0x007647d0(0x9d2f20,0x993c20);
            return 0;
          }
          iVar5 = 0;
          if (0 < *(int *)(param_1 + 0x1c)) {
            iVar3 = 0;
            do {
              puVar6 = (undefined4 *)(iVar3 + iVar2);
              puVar7 = (undefined4 *)(*(int *)(param_1 + 0x54) + iVar3);
              for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
                *puVar7 = *puVar6;
                puVar6 = puVar6 + 1;
                puVar7 = puVar7 + 1;
              }
              iVar5 = iVar5 + 1;
              iVar3 = iVar3 + 0x30;
            } while (iVar5 < *(int *)(param_1 + 0x1c));
          }
          func_0x00763260(iVar2);
          param_2 = unaff_retaddr;
        }
        if (0 < *(int *)(param_1 + 0x20)) {
          iVar2 = *(int *)(param_1 + 0x20) * 2;
          cVar1 = (**(code **)(*param_2 + 0x10))
                            (*(undefined4 *)(param_1 + 0x58),iVar2,&stack0xffffffe8);
          if ((cVar1 == '\0') || (iVar2 != 0x10)) {
            uVar8 = 0x993c54;
            goto LAB_007e32c9;
          }
        }
        FUN_007e3490();
        return 1;
      }
      uVar8 = 0x993c88;
    }
  }
LAB_007e32c9:
  func_0x007647d0(0x9d2f20,uVar8);
  return 0;
}


/* ==================================================================== */
/* Address: 0x007e32f0 | Classified: elementclient::A3DSkinMesh__Save____Failed_to_w@0x7e32f0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007e32f0(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_EBX;
  int iVar6;
  undefined4 *puVar7;
  int unaff_EDI;
  undefined4 *puVar8;
  int *unaff_retaddr;
  undefined4 uVar9;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  cVar1 = (**(code **)(*param_2 + 0x28))(param_1 + 8);
  if (cVar1 == '\0') {
    uVar9 = 0x993d84;
  }
  else {
    uStack_c = *(undefined4 *)(param_1 + 0x1c);
    uStack_8 = *(undefined4 *)(param_1 + 0x20);
    uStack_10 = *(undefined4 *)(param_1 + 0x18);
    uStack_14 = *(undefined4 *)(param_1 + 0x14);
    cVar1 = (**(code **)(*param_2 + 0x14))(&uStack_14,0x10,&stack0xffffffe4);
    if ((cVar1 != '\0') && (unaff_EBX == 0x10)) {
      if ((*(int *)(param_1 + 0x54) != 0) && (*(int *)(param_1 + 0x1c) != 0)) {
        iVar6 = *(int *)(param_1 + 0x1c) * 0x30;
        iVar2 = func_0x00763250(iVar6);
        iVar5 = 0;
        if (0 < *(int *)(param_1 + 0x1c)) {
          iVar3 = 0;
          do {
            puVar7 = (undefined4 *)(*(int *)(param_1 + 0x54) + iVar3);
            puVar8 = (undefined4 *)(iVar3 + iVar2);
            for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar8 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar8 = puVar8 + 1;
            }
            iVar5 = iVar5 + 1;
            iVar3 = iVar3 + 0x30;
            param_2 = unaff_retaddr;
          } while (iVar5 < *(int *)(param_1 + 0x1c));
        }
        cVar1 = (**(code **)(*param_2 + 0x14))(iVar2,iVar6,&stack0xffffffe4);
        if ((cVar1 == '\0') || (unaff_EDI != iVar6)) {
          func_0x00763260(iVar2);
          func_0x007647d0(0x9d2f20,0x993d24);
          return 0;
        }
        func_0x00763260(iVar2);
        param_2 = unaff_retaddr;
      }
      if ((*(int *)(param_1 + 0x58) != 0) && (*(int *)(param_1 + 0x20) != 0)) {
        iVar2 = *(int *)(param_1 + 0x20) * 2;
        cVar1 = (**(code **)(*param_2 + 0x14))(*(int *)(param_1 + 0x58),iVar2,&stack0xffffffe4);
        if ((cVar1 == '\0') || (iVar2 != 0x10)) {
          uVar9 = 0x993d54;
          goto LAB_007e3444;
        }
      }
      return 1;
    }
    uVar9 = 0x993cf0;
  }
LAB_007e3444:
  func_0x007647d0(0x9d2f20,uVar9);
  return 0;
}


/* ==================================================================== */
/* Address: 0x007e3490 | Classified: Angelica3D::proc_7e3490 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_007e3490(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  if ((*(int *)(param_1 + 0x1c) != 0) && (*(int *)(param_1 + 0x54) != 0)) {
    iVar5 = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0x497423f0;
    *(undefined4 *)(param_1 + 0x40) = 0x497423f0;
    *(undefined4 *)(param_1 + 0x44) = 0x497423f0;
    *(undefined4 *)(param_1 + 0x48) = 0xc97423f0;
    *(undefined4 *)(param_1 + 0x4c) = 0xc97423f0;
    *(undefined4 *)(param_1 + 0x50) = 0xc97423f0;
    if (0 < *(int *)(param_1 + 0x1c)) {
      iVar6 = 0;
      do {
        puVar4 = (undefined4 *)(*(int *)(param_1 + 0x54) + iVar6);
        uStack_10 = puVar4[2];
        uStack_14 = puVar4[1];
        uStack_18 = *puVar4;
        func_0x00774a10(&uStack_18);
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + 0x30;
      } while (iVar5 < *(int *)(param_1 + 0x1c));
    }
    fVar1 = (*(float *)(param_1 + 0x3c) + *(float *)(param_1 + 0x48)) * _DAT_008eff98;
    fVar2 = (*(float *)(param_1 + 0x40) + *(float *)(param_1 + 0x4c)) * _DAT_008eff98;
    *(float *)(param_1 + 0x24) = fVar1;
    fVar3 = (*(float *)(param_1 + 0x44) + *(float *)(param_1 + 0x50)) * _DAT_008eff98;
    *(float *)(param_1 + 0x2c) = fVar3;
    *(float *)(param_1 + 0x28) = fVar2;
    *(float *)(param_1 + 0x30) = *(float *)(param_1 + 0x48) - fVar1;
    *(float *)(param_1 + 0x38) = *(float *)(param_1 + 0x50) - fVar3;
    *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x4c) - fVar2;
    return;
  }
  puVar4 = (undefined4 *)(param_1 + 0x24);
  for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007e3590 | Classified: elementclient::A3DSkinMesh__CreateOriginalBuffe@0x7e3590 */
/* ==================================================================== */

undefined4 __thiscall FUN_007e3590(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  FUN_007e3620();
  if (0 < param_2) {
    iVar1 = func_0x00763250(param_2 * 0x30);
    *(int *)(param_1 + 0x54) = iVar1;
    if (iVar1 == 0) {
      func_0x007647d0(0x9d2f20,0x993db4);
      return 0;
    }
  }
  if (0 < param_3) {
    iVar1 = func_0x00763250(param_3 * 2);
    *(int *)(param_1 + 0x58) = iVar1;
    if (iVar1 == 0) {
      func_0x007647d0(0x9d2f20,0x993db4);
      return 0;
    }
  }
  *(int *)(param_1 + 0x1c) = param_2;
  *(int *)(param_1 + 0x20) = param_3;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007e3620 | Classified: Angelica3D::proc_7e3620 */
/* ==================================================================== */

void __fastcall FUN_007e3620(int param_1)

{
  if (*(int *)(param_1 + 0x54) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x54));
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  if (*(int *)(param_1 + 0x58) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x58));
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007e3660 | Classified: Angelica3D::proc_7e3660 */
/* ==================================================================== */

uint __thiscall FUN_007e3660(int *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = param_1[3];
  if (((*(int *)(iVar2 + 0x50) == 0) || (iVar2 = 0, param_1[7] == 0)) ||
     (iVar2 = 0, param_1[8] == 0)) {
    return CONCAT31((int3)((uint)iVar2 >> 8),1);
  }
  (**(code **)(*param_1 + 0x38))();
  iVar2 = param_1[0x1b];
  if (iVar2 == 0) {
    uVar1 = FUN_007e39e0(param_2);
    return uVar1;
  }
  if (iVar2 != 1) {
    if (iVar2 - 2U != 0) {
      return iVar2 - 2U & 0xffffff00;
    }
    uVar1 = func_0x007e4410();
    return uVar1;
  }
  uVar1 = FUN_007e36d0();
  return uVar1;
}


/* ==================================================================== */
/* Address: 0x007e36d0 | Classified: elementclient::A3DSkinMesh__CreateSoftwareSubMe@0x7e36d0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007e36d0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int *unaff_FS_OFFSET;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cef7b;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  iStack_24 = 0x48;
  iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 0x50);
  uStack_28 = 0x7e36fa;
  iVar2 = func_0x00763250();
  uStack_4 = 0;
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iStack_24 = 0x7e3712;
    iVar2 = func_0x00784d70();
  }
  uStack_4 = 0xffffffff;
  *(int *)(param_1 + 0x60) = iVar2;
  if (iVar2 == 0) {
    iStack_24 = 0x993ee0;
    uStack_28 = 0x9d2f20;
    uStack_2c = 0x7e3734;
    func_0x007647d0();
    *unaff_FS_OFFSET = iStack_c;
    return 0;
  }
  uStack_2c = *(undefined4 *)(param_1 + 0x20);
  uStack_30 = *(undefined4 *)(param_1 + 0x1c);
  iStack_24 = 3;
  uStack_28 = 1;
  cVar1 = func_0x00784dd0(iVar5,6);
  if (cVar1 == '\0') {
    if (*(undefined4 **)(param_1 + 0x60) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x60))(1);
    }
    func_0x007647d0(0x9d2f20,0x993e90);
    *unaff_FS_OFFSET = iStack_24;
    return 0;
  }
  func_0x007859e0(*(undefined4 *)(param_1 + 0x58));
  iVar2 = 0;
  uStack_30 = 0;
  cVar1 = func_0x007855c0(0,0,&uStack_30);
  if (cVar1 == '\0') {
    func_0x007647d0(0x9d2f20,0x993e40);
    *unaff_FS_OFFSET = iVar5;
    return 0;
  }
  iVar5 = 0;
  if (0 < *(int *)(param_1 + 0x1c)) {
    iVar3 = 0;
    do {
      iVar5 = iVar5 + 1;
      puVar6 = (undefined4 *)(*(int *)(param_1 + 0x54) + iVar3);
      puVar7 = (undefined4 *)(iVar3 + iVar2);
      for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      iVar3 = iVar3 + 0x30;
    } while (iVar5 < *(int *)(param_1 + 0x1c));
  }
  func_0x007856d0();
  cVar1 = func_0x00785420(*(undefined4 *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x20));
  if (cVar1 == '\0') {
    func_0x007647d0(0x9d2f20,0x993df0);
    *unaff_FS_OFFSET = iVar2;
    return 0;
  }
  *unaff_FS_OFFSET = iVar2;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007e3870 | Classified: elementclient::A3DSkinMesh__CreateStream____Not@0x7e3870 */
/* ==================================================================== */

undefined4 __fastcall FUN_007e3870(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cef9b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uVar3 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x50);
  iVar2 = func_0x00763250(0x48);
  uStack_4 = 0;
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = func_0x00784d70();
  }
  uStack_4 = 0xffffffff;
  *(int *)(param_1 + 0x5c) = iVar2;
  if (iVar2 == 0) {
    func_0x007647d0(0x9d2f20,0x993fd4);
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  uVar4 = *(undefined4 *)(param_1 + 0x1c);
  cVar1 = func_0x00784f10(uVar3,0x30,0x111c,uVar4,*(undefined4 *)(param_1 + 0x20),3,3);
  if (cVar1 == '\0') {
    if (*(undefined4 **)(param_1 + 0x5c) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x5c))(1);
    }
    func_0x007647d0(0x9d2f20,0x993f94);
    *unaff_FS_OFFSET = uVar4;
    return 0;
  }
  uVar3 = *(undefined4 *)(param_1 + 0x54);
  func_0x007859c0();
  func_0x007859e0(*(undefined4 *)(param_1 + 0x58));
  uVar4 = *(undefined4 *)(param_1 + 0x1c);
  cVar1 = func_0x007852e0(*(undefined4 *)(param_1 + 0x54));
  if (cVar1 == '\0') {
    func_0x007647d0(0x9d2f20,0x993f58);
    *unaff_FS_OFFSET = uVar3;
    return 0;
  }
  cVar1 = func_0x00785420(*(undefined4 *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x20));
  if (cVar1 == '\0') {
    func_0x007647d0(0x9d2f20,0x993f1c);
    *unaff_FS_OFFSET = uVar4;
    return 0;
  }
  *unaff_FS_OFFSET = uVar4;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007e39e0 | Classified: elementclient::A3DSkinMesh__CreateVertexShaderS@0x7e39e0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007e39e0(int param_1)

{
  uint uVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  ushort *puVar9;
  undefined4 *unaff_FS_OFFSET;
  int iStack00000004;
  int iStack_5c;
  undefined *puStack_54;
  undefined *puStack_50;
  int iStack_4c;
  int iStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  uint auStack_3c [12];
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cefc3;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar4 = FUN_00795640();
  if (iVar4 < *(int *)(param_1 + 100)) {
    *(undefined1 *)(param_1 + 0x68) = 0;
    uVar5 = FUN_007e3870();
  }
  else {
    *(undefined1 *)(param_1 + 0x68) = 1;
    puStack_50 = &UNK_008d5a30;
    iStack_4c = 0;
    iStack_48 = 0;
    uStack_44 = 0;
    uStack_40 = 0x10;
    puStack_54 = &UNK_008f3d18;
    uStack_4 = 0;
    iStack00000004 = 0;
    if (0 < *(int *)(param_1 + 0x20)) {
      do {
        iVar4 = 0;
        iStack_5c = 3;
        puVar9 = (ushort *)(*(int *)(param_1 + 0x58) + iStack00000004 * 2);
        do {
          iVar7 = 0;
          uVar1 = *(uint *)((uint)*puVar9 * 0x30 + *(int *)(param_1 + 0x54) + 0x18);
          do {
            iVar8 = 0;
            uVar6 = uVar1 >> ((byte)iVar7 & 0x1f) & 0xff;
            if (0 < iVar4) {
              do {
                if (auStack_3c[iVar8] == uVar6) {
                  if (iVar8 < iVar4) goto LAB_007e3aac;
                  break;
                }
                iVar8 = iVar8 + 1;
              } while (iVar8 < iVar4);
            }
            auStack_3c[iVar4] = uVar6;
            iVar4 = iVar4 + 1;
LAB_007e3aac:
            iVar7 = iVar7 + 8;
          } while (iVar7 < 0x20);
          puVar9 = puVar9 + 1;
          iStack_5c = iStack_5c + -1;
        } while (iStack_5c != 0);
        FUN_007e3c20(&puStack_54,iStack00000004 / 3,auStack_3c,iVar4);
        iStack00000004 = iStack00000004 + 3;
      } while (iStack00000004 < *(int *)(param_1 + 0x20));
    }
    iVar4 = 0;
    if (0 < iStack_48) {
      do {
        piVar2 = *(int **)(iStack_4c + iVar4 * 4);
        cVar3 = FUN_007e4190(piVar2);
        if (cVar3 == '\0') {
          func_0x007647d0(0x9d2f20,0x994008);
          uStack_4 = 0xffffffff;
          puStack_54 = &UNK_008f3d18;
          puStack_50 = &UNK_008d5a30;
          if (iStack_4c != 0) {
            func_0x00763260(iStack_4c);
          }
          uVar5 = 0;
          goto LAB_007e3bc5;
        }
        if (*piVar2 != 0) {
          func_0x00763260(*piVar2);
        }
        puStack_8._0_1_ = 1;
        piVar2[7] = (int)&UNK_008f3d14;
        if (piVar2[8] != 0) {
          func_0x00763260(piVar2[8]);
          piVar2[8] = 0;
        }
        piVar2[10] = 0;
        piVar2[9] = 0;
        puStack_8 = (undefined *)((uint)puStack_8._1_3_ << 8);
        piVar2[2] = (int)&UNK_008f3d10;
        if (piVar2[3] != 0) {
          func_0x00763260(piVar2[3]);
          piVar2[3] = 0;
        }
        piVar2[5] = 0;
        piVar2[4] = 0;
        func_0x00763260(piVar2);
        iVar4 = iVar4 + 1;
      } while (iVar4 < iStack_48);
    }
    uStack_4 = 0xffffffff;
    puStack_54 = &UNK_008f3d18;
    puStack_50 = &UNK_008d5a30;
    if (iStack_4c != 0) {
      func_0x00763260(iStack_4c);
    }
    uVar5 = 1;
  }
LAB_007e3bc5:
  *unaff_FS_OFFSET = uStack_c;
  return uVar5;
}


/* ==================================================================== */
/* Address: 0x007e3c20 | Classified: elementclient::AArray__Allocate__Not_enough_mem@0x7e3c20 */
/* ==================================================================== */

undefined4 __thiscall FUN_007e3c20(int param_1,int param_2,int *param_3,int param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *unaff_FS_OFFSET;
  int iStack_54;
  undefined2 auStack_44 [2];
  undefined4 auStack_40 [13];
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ceff1;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar5 = *(int *)(param_1 + 0x58) + (int)param_3 * 6;
  auStack_44[0] = *(undefined2 *)(*(int *)(param_1 + 0x58) + (int)param_3 * 6);
  iStack_54 = 0;
  auStack_44[1] = *(undefined2 *)(iVar5 + 2);
  auStack_40[0]._0_2_ = *(undefined2 *)(iVar5 + 4);
  iVar5 = *(int *)(param_2 + 0xc);
  if (iVar5 < 1) {
LAB_007e3d21:
    piVar3 = (int *)func_0x00763250(0x30);
    uStack_4 = 0;
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3[2] = (int)&UNK_008f3d10;
      piVar3[3] = 0;
      piVar3[4] = 0;
      piVar3[5] = 0;
      piVar3[6] = 500;
      func_0x007e53c0(0);
      piVar3[7] = (int)&UNK_008f3d14;
      piVar3[8] = 0;
      piVar3[9] = 0;
      piVar3[10] = 0;
      piVar3[0xb] = 500;
    }
    uStack_4 = 0xffffffff;
    if (piVar3 == (int *)0x0) {
      uVar4 = 0;
    }
    else {
      piVar3[1] = 0;
      iVar5 = func_0x00763250(*(int *)(param_1 + 100) << 2);
      *piVar3 = iVar5;
      if (iVar5 == 0) {
        uStack_4 = 2;
        piVar3[7] = (int)&UNK_008f3d14;
        if (piVar3[8] != 0) {
          func_0x00763260(piVar3[8]);
          piVar3[8] = 0;
        }
        piVar3[10] = 0;
        piVar3[9] = 0;
        uStack_4 = 0xffffffff;
        piVar3[2] = (int)&UNK_008f3d10;
        if (piVar3[3] != 0) {
          func_0x00763260(piVar3[3]);
          piVar3[3] = 0;
        }
        piVar3[5] = 0;
        piVar3[4] = 0;
        func_0x00763260(piVar3);
        uVar4 = 0;
      }
      else {
        iVar5 = 0;
        if (0 < param_5) {
          do {
            *(undefined4 *)(*piVar3 + iVar5 * 4) = *(undefined4 *)(param_4 + iVar5 * 4);
            iVar5 = iVar5 + 1;
          } while (iVar5 < param_5);
        }
        piVar3[1] = param_5;
        iVar5 = 0;
        do {
          FUN_007e3f10(piVar3,auStack_44[iVar5]);
          iVar5 = iVar5 + 1;
        } while (iVar5 < 3);
        if ((*(int *)(param_2 + 0x10) <= *(int *)(param_2 + 0xc)) && (*(int *)(param_2 + 0x14) != 0)
           ) {
          iVar7 = *(int *)(param_2 + 0x14) + *(int *)(param_2 + 0x10);
          iVar5 = func_0x00763250(iVar7 * 4);
          if (iVar5 == 0) {
            func_0x00764590(1,0x94e51c);
          }
          else {
            iVar8 = 0;
            if (0 < *(int *)(param_2 + 0xc)) {
              do {
                iVar8 = iVar8 + 1;
                *(undefined4 *)(iVar5 + -4 + iVar8 * 4) =
                     *(undefined4 *)(*(int *)(param_2 + 8) + -4 + iVar8 * 4);
              } while (iVar8 < *(int *)(param_2 + 0xc));
            }
            if (*(int *)(param_2 + 8) != 0) {
              func_0x00763260(*(int *)(param_2 + 8));
            }
            *(int *)(param_2 + 8) = iVar5;
            *(int *)(param_2 + 0x10) = iVar7;
          }
        }
        *(int **)(*(int *)(param_2 + 8) + *(int *)(param_2 + 0xc) * 4) = piVar3;
        *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;
LAB_007e3ef5:
        uVar4 = 1;
      }
    }
    *unaff_FS_OFFSET = uStack_c;
    return uVar4;
  }
  iVar7 = *(int *)(param_1 + 100);
  param_3 = *(int **)(param_2 + 8);
LAB_007e3c91:
  iVar8 = 0;
  iVar9 = 0;
  piVar3 = (int *)*param_3;
  if (0 < param_5) {
    iVar1 = piVar3[1];
    do {
      iVar6 = 0;
      if (iVar1 < 1) {
LAB_007e3cd7:
        iVar8 = iVar8 + 1;
        auStack_40[iVar8] = *(undefined4 *)(param_4 + iVar9 * 4);
      }
      else {
        piVar2 = (int *)*piVar3;
        do {
          if (*piVar2 == *(int *)(param_4 + iVar9 * 4)) {
            if (iVar6 < iVar1) goto LAB_007e3ce7;
            goto LAB_007e3cd7;
          }
          iVar6 = iVar6 + 1;
          piVar2 = piVar2 + 1;
        } while (iVar6 < iVar1);
        iVar8 = iVar8 + 1;
        auStack_40[iVar8] = *(undefined4 *)(param_4 + iVar9 * 4);
      }
LAB_007e3ce7:
      iVar9 = iVar9 + 1;
    } while (iVar9 < param_5);
  }
  if (iVar7 < piVar3[1] + iVar8) goto code_r0x007e3d01;
  iVar5 = 0;
  if (0 < iVar8) {
    do {
      *(undefined4 *)(*piVar3 + piVar3[1] * 4) = auStack_40[iVar5 + 1];
      iVar5 = iVar5 + 1;
      piVar3[1] = piVar3[1] + 1;
    } while (iVar5 < iVar8);
  }
  iVar5 = 0;
  do {
    FUN_007e3f10(piVar3,auStack_44[iVar5]);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  goto LAB_007e3ef5;
code_r0x007e3d01:
  iStack_54 = iStack_54 + 1;
  param_3 = param_3 + 1;
  if (iVar5 <= iStack_54) goto LAB_007e3d21;
  goto LAB_007e3c91;
}


/* ==================================================================== */
/* Address: 0x007e3f10 | Classified: elementclient::AArray__Allocate__Not_enough_mem@0x7e3f10 */
/* ==================================================================== */

undefined4 __thiscall FUN_007e3f10(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  byte bVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  uint *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  uint auStack_40 [4];
  undefined4 auStack_30 [6];
  uint uStack_18;
  
  iVar1 = 0;
  iVar2 = param_2[9];
  auStack_40[0] = 0;
  if (0 < iVar2) {
    piVar11 = (int *)(param_2[8] + 4);
    do {
      if (*piVar11 == param_3) {
        auStack_40[0] = *(uint *)(param_2[8] + iVar1 * 8);
        break;
      }
      iVar1 = iVar1 + 1;
      piVar11 = piVar11 + 2;
    } while (iVar1 < iVar2);
  }
  if (iVar1 < iVar2) {
    if (((int)param_2[10] <= (int)param_2[9]) && (param_2[0xb] != 0)) {
      iVar1 = param_2[0xb] + param_2[10];
      iVar2 = func_0x00763250(iVar1 * 8);
      if (iVar2 == 0) {
        func_0x00764590(1,0x94e51c);
      }
      else {
        iVar3 = 0;
        if (0 < (int)param_2[9]) {
          do {
            iVar7 = param_2[8];
            iVar3 = iVar3 + 1;
            *(undefined4 *)(iVar2 + -8 + iVar3 * 8) = *(undefined4 *)(iVar7 + -8 + iVar3 * 8);
            *(undefined4 *)(iVar2 + -4 + iVar3 * 8) = *(undefined4 *)(iVar7 + -4 + iVar3 * 8);
          } while (iVar3 < (int)param_2[9]);
        }
        if (param_2[8] != 0) {
          func_0x00763260(param_2[8]);
        }
        param_2[8] = iVar2;
        param_2[10] = iVar1;
      }
    }
    iVar2 = param_2[9];
    iVar1 = param_2[8];
    *(uint *)(iVar1 + iVar2 * 8) = auStack_40[0];
    *(int *)(iVar1 + 4 + iVar2 * 8) = param_3;
    iVar2 = param_2[9];
    param_2[9] = iVar2 + 1;
    return CONCAT31((int3)((uint)(iVar2 + 1) >> 8),1);
  }
  puVar6 = auStack_40;
  puVar13 = (undefined4 *)(*(int *)(param_1 + 0x54) + param_3 * 0x30);
  puVar14 = auStack_30;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar14 = *puVar13;
    puVar13 = puVar13 + 1;
    puVar14 = puVar14 + 1;
  }
  iVar2 = param_2[1];
  iVar1 = 0;
  do {
    uVar10 = 0;
    uVar4 = uStack_18 >> ((byte)iVar1 & 0x1f) & 0xff;
    uVar5 = uVar4;
    if (0 < iVar2) {
      puVar12 = (uint *)*param_2;
      do {
        uVar5 = uVar10;
        if (uVar4 == *puVar12) break;
        uVar10 = uVar10 + 1;
        puVar12 = puVar12 + 1;
        uVar5 = uVar4;
      } while ((int)uVar10 < iVar2);
    }
    *puVar6 = uVar5;
    iVar1 = iVar1 + 8;
    puVar6 = puVar6 + 1;
    if (0x1f < iVar1) {
      uStack_18 = 0;
      iVar2 = 0;
      puVar6 = auStack_40;
      do {
        uVar5 = *puVar6;
        puVar6 = puVar6 + 1;
        bVar8 = (byte)iVar2;
        iVar2 = iVar2 + 8;
        uStack_18 = uStack_18 | uVar5 << (bVar8 & 0x1f);
      } while (iVar2 < 0x20);
      if (((int)param_2[5] <= (int)param_2[4]) && (param_2[6] != 0)) {
        iVar1 = param_2[6] + param_2[5];
        iVar2 = func_0x00763250(iVar1 * 0x30);
        if (iVar2 == 0) {
          func_0x00764590(1,0x94e51c);
        }
        else {
          iVar3 = 0;
          if (0 < (int)param_2[4]) {
            iVar7 = 0;
            do {
              puVar13 = (undefined4 *)(param_2[3] + iVar7);
              puVar14 = (undefined4 *)(iVar7 + iVar2);
              for (iVar9 = 0xc; iVar9 != 0; iVar9 = iVar9 + -1) {
                *puVar14 = *puVar13;
                puVar13 = puVar13 + 1;
                puVar14 = puVar14 + 1;
              }
              iVar3 = iVar3 + 1;
              iVar7 = iVar7 + 0x30;
            } while (iVar3 < (int)param_2[4]);
          }
          if (param_2[3] != 0) {
            func_0x00763260(param_2[3]);
          }
          param_2[3] = iVar2;
          param_2[5] = iVar1;
        }
      }
      puVar13 = auStack_30;
      puVar14 = (undefined4 *)(param_2[4] * 0x30 + param_2[3]);
      for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar14 = *puVar13;
        puVar13 = puVar13 + 1;
        puVar14 = puVar14 + 1;
      }
      iVar2 = param_2[4];
      param_2[4] = iVar2 + 1;
      if (((int)param_2[10] <= (int)param_2[9]) && (param_2[0xb] != 0)) {
        iVar3 = param_2[0xb] + param_2[10];
        iVar1 = func_0x00763250(iVar3 * 8);
        if (iVar1 == 0) {
          func_0x00764590(1,0x94e51c);
        }
        else {
          iVar7 = 0;
          if (0 < (int)param_2[9]) {
            do {
              iVar9 = param_2[8];
              iVar7 = iVar7 + 1;
              *(undefined4 *)(iVar1 + -8 + iVar7 * 8) = *(undefined4 *)(iVar9 + -8 + iVar7 * 8);
              *(undefined4 *)(iVar1 + -4 + iVar7 * 8) = *(undefined4 *)(iVar9 + -4 + iVar7 * 8);
            } while (iVar7 < (int)param_2[9]);
          }
          if (param_2[8] != 0) {
            func_0x00763260(param_2[8]);
          }
          param_2[8] = iVar1;
          param_2[10] = iVar3;
        }
      }
      iVar1 = param_2[9];
      iVar3 = param_2[8];
      *(int *)(iVar3 + iVar1 * 8) = iVar2;
      *(int *)(iVar3 + 4 + iVar1 * 8) = param_3;
      iVar2 = param_2[9];
      param_2[9] = iVar2 + 1;
      return CONCAT31((int3)((uint)(iVar2 + 1) >> 8),1);
    }
  } while( true );
}


/* ==================================================================== */
/* Address: 0x007e4190 | Classified: elementclient::A3DSkinMesh__ConvertProcessedSub@0x7e4190 */
/* ==================================================================== */

uint __thiscall FUN_007e4190(int param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *unaff_FS_OFFSET;
  int iVar8;
  undefined4 uStack_34;
  undefined4 *puStack_30;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cf00b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  puStack_30 = (undefined4 *)0xc;
  iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 0x50);
  uStack_34 = 0x7e41bf;
  puVar2 = (undefined4 *)func_0x00763250();
  if (puVar2 == (undefined4 *)0x0) {
    uVar4 = 0;
  }
  else {
    puVar2[1] = param_2[1];
    puStack_30 = (undefined4 *)(param_2[1] << 2);
    uStack_34 = 0x7e41e9;
    puVar3 = (undefined4 *)func_0x00763250();
    *puVar2 = puVar3;
    if (puVar3 == (undefined4 *)0x0) {
      uStack_34 = 0x7e41f8;
      puStack_30 = puVar2;
      func_0x00763260();
      uStack_34 = 0x994178;
      uVar4 = func_0x007647d0(0x9d2f20);
      uVar4 = uVar4 & 0xffffff00;
    }
    else {
      puVar7 = (undefined4 *)*param_2;
      for (uVar4 = param_2[1] & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar3 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar3 = puVar3 + 1;
      }
      puStack_30 = (undefined4 *)0x48;
      for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
        *(undefined1 *)puVar3 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar3 = (undefined4 *)((int)puVar3 + 1);
      }
      uStack_34 = 0x7e4230;
      iVar6 = func_0x00763250();
      uStack_4 = 0;
      if (iVar6 == 0) {
        iVar6 = 0;
      }
      else {
        puStack_30 = (undefined4 *)0x7e424a;
        iVar6 = func_0x00784d70();
      }
      uStack_4 = 0xffffffff;
      puVar2[2] = iVar6;
      if (iVar6 == 0) {
        uStack_34 = 0x7e4269;
        puStack_30 = puVar2;
        func_0x00763260();
        uStack_34 = 0x994178;
        uVar4 = func_0x007647d0(0x9d2f20);
        uVar4 = uVar4 & 0xffffff00;
      }
      else {
        puStack_30 = (undefined4 *)0x1;
        uStack_34 = 1;
        iVar8 = 0x30;
        iVar6 = iVar5;
        cVar1 = func_0x00784f10(iVar5,0x30,0x111c,param_2[4],param_2[9]);
        if (cVar1 == '\0') {
          uVar4 = func_0x007647d0(0x9d2f20,0x994130);
          uVar4 = uVar4 & 0xffffff00;
        }
        else {
          cVar1 = func_0x007852e0(param_2[3],iVar5);
          if (cVar1 == '\0') {
            uVar4 = func_0x007647d0(0x9d2f20,0x9940e8);
            uVar4 = uVar4 & 0xffffff00;
          }
          else {
            cVar1 = func_0x00785700(0,0,&uStack_34,0);
            if (cVar1 == '\0') {
              uVar4 = func_0x007647d0(0x9d2f20,0x9940a0);
              uVar4 = uVar4 & 0xffffff00;
            }
            else {
              iVar5 = 0;
              if (0 < iVar6) {
                do {
                  *(undefined2 *)(iVar8 + iVar5 * 2) = *(undefined2 *)(param_2[8] + iVar5 * 8);
                  iVar5 = iVar5 + 1;
                } while (iVar5 < iVar6);
              }
              cVar1 = func_0x00785810();
              if (cVar1 == '\0') {
                puStack_30 = (undefined4 *)0x994058;
                uStack_34 = 0x9d2f20;
                uVar4 = func_0x007647d0();
                uVar4 = uVar4 & 0xffffff00;
              }
              else {
                if ((*(int *)(param_1 + 0x80) <= *(int *)(param_1 + 0x7c)) &&
                   (*(int *)(param_1 + 0x84) != 0)) {
                  iVar6 = *(int *)(param_1 + 0x84) + *(int *)(param_1 + 0x80);
                  puStack_30 = (undefined4 *)(iVar6 * 4);
                  uStack_34 = 0x7e438a;
                  iVar5 = func_0x00763250();
                  if (iVar5 == 0) {
                    puStack_30 = (undefined4 *)0x94e51c;
                    uStack_34 = 1;
                    func_0x00764590();
                  }
                  else {
                    iVar8 = 0;
                    if (0 < *(int *)(param_1 + 0x7c)) {
                      do {
                        iVar8 = iVar8 + 1;
                        *(undefined4 *)(iVar5 + -4 + iVar8 * 4) =
                             *(undefined4 *)(*(int *)(param_1 + 0x78) + -4 + iVar8 * 4);
                      } while (iVar8 < *(int *)(param_1 + 0x7c));
                    }
                    puStack_30 = *(undefined4 **)(param_1 + 0x78);
                    if (puStack_30 != (undefined4 *)0x0) {
                      uStack_34 = 0x7e43cd;
                      func_0x00763260();
                    }
                    *(int *)(param_1 + 0x78) = iVar5;
                    *(int *)(param_1 + 0x80) = iVar6;
                  }
                }
                *(undefined4 **)(*(int *)(param_1 + 0x78) + *(int *)(param_1 + 0x7c) * 4) = puVar2;
                iVar5 = *(int *)(param_1 + 0x7c) + 1;
                *(int *)(param_1 + 0x7c) = iVar5;
                uVar4 = CONCAT31((int3)((uint)iVar5 >> 8),1);
              }
            }
          }
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return uVar4;
}


