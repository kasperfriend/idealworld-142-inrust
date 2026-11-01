/* Authentic Ghidra 12.1.4 Decompilation — elementclient.exe (PW 1.4.2 Build 2305) */
/* Module: 16_a3dtrn2loaderb_t2bk_t2mk_t2lm.c */

/* ==================================================================== */
/* Address: 0x007a0c10 | Classified: Angelica3D::proc_7a0c10 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a0c10(undefined4 param_1,byte param_2)

{
  FUN_007a0c30();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007a0c30 | Classified: Angelica3D::proc_7a0c30 */
/* ==================================================================== */

void __fastcall FUN_007a0c30(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  puStack_8 = &UNK_008cd358;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f1860;
  iStack_4 = 8;
  param_1[0x23e] = &UNK_008f1864;
  if (param_1[0x23f] != 0) {
    func_0x00763260(param_1[0x23f]);
    param_1[0x23f] = 0;
  }
  param_1[0x241] = 0;
  param_1[0x240] = 0;
  iStack_4._0_1_ = 7;
  param_1[0x239] = &UNK_008d651c;
  if (param_1[0x23a] != 0) {
    func_0x00763260(param_1[0x23a]);
    param_1[0x23a] = 0;
  }
  param_1[0x23c] = 0;
  param_1[0x23b] = 0;
  iStack_4._0_1_ = 6;
  param_1[0x234] = &UNK_008d651c;
  if (param_1[0x235] != 0) {
    func_0x00763260(param_1[0x235]);
    param_1[0x235] = 0;
  }
  param_1[0x237] = 0;
  param_1[0x236] = 0;
  iStack_4._0_1_ = 5;
  param_1[0x22f] = &UNK_008d651c;
  if (param_1[0x230] != 0) {
    func_0x00763260(param_1[0x230]);
    param_1[0x230] = 0;
  }
  param_1[0x232] = 0;
  param_1[0x231] = 0;
  param_1[0x22a] = &UNK_008d651c;
  iStack_4._0_1_ = 4;
  if (param_1[0x22b] != 0) {
    func_0x00763260(param_1[0x22b]);
    param_1[0x22b] = 0;
  }
  param_1[0x22d] = 0;
  param_1[0x22c] = 0;
  iStack_4._0_1_ = 3;
  func_0x0076e460();
  iStack_4._0_1_ = 2;
  func_0x0076e460();
  iStack_4._0_1_ = 1;
  func_0x0076e460();
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  func_0x0076e460();
  iStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x007a0dc0 | Classified: elementclient::_t2bk@0x7a0dc0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a0dc0(int param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 unaff_EBX;
  undefined4 *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd388;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar1 = param_1 + 0xc;
  func_0x007638a0(param_2);
  func_0x005117a0(&stack0x00000000,iVar1,0x98c9b8);
  puStack_8 = (undefined *)0x0;
  cVar2 = FUN_007a1250(unaff_retaddr);
  if (cVar2 != '\0') {
    uVar3 = func_0x005117a0(&stack0xffffffe8,iVar1,0x98c9b0);
    uStack_c._0_1_ = 1;
    func_0x00763940(uVar3);
    func_0x007637f0();
    cVar2 = FUN_007a1520(puStack_8);
    if (cVar2 != '\0') {
      *(undefined1 *)(param_1 + 0x880) = 0;
      uVar3 = func_0x005117a0(&stack0xffffffe8,iVar1,0x98c9a8);
      uStack_c = CONCAT31(uStack_c._1_3_,2);
      func_0x00763940(uVar3);
      func_0x007637f0();
      uVar3 = 1;
      cVar2 = FUN_007a18c0(puStack_8);
      if (cVar2 != '\0') {
        *(undefined1 *)(param_1 + 0x880) = 1;
      }
      *(undefined1 *)(param_1 + 0x881) = 0;
      func_0x00763aa0(0x96391c);
      cVar2 = FUN_007a18c0(unaff_EBX,0);
      if (cVar2 != '\0') {
        *(undefined1 *)(param_1 + 0x881) = 1;
      }
      *(undefined1 *)(param_1 + 0x89c) = 1;
      func_0x007637f0();
      *unaff_FS_OFFSET = uVar3;
      return 1;
    }
  }
  uStack_c = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = unaff_EBX;
  return 0;
}


/* ==================================================================== */
/* Address: 0x007a0f30 | Classified: Angelica3D::proc_7a0f30 */
/* ==================================================================== */

void __fastcall FUN_007a0f30(int param_1)

{
  if (*(int *)(param_1 + 0x8ac) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x8ac));
    *(undefined4 *)(param_1 + 0x8ac) = 0;
  }
  *(undefined4 *)(param_1 + 0x8b4) = 0;
  *(undefined4 *)(param_1 + 0x8b0) = 0;
  if (*(int *)(param_1 + 0x8c0) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x8c0));
    *(undefined4 *)(param_1 + 0x8c0) = 0;
  }
  *(undefined4 *)(param_1 + 0x8c8) = 0;
  *(undefined4 *)(param_1 + 0x8c4) = 0;
  if (*(int *)(param_1 + 0x8d4) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x8d4));
    *(undefined4 *)(param_1 + 0x8d4) = 0;
  }
  *(undefined4 *)(param_1 + 0x8dc) = 0;
  *(undefined4 *)(param_1 + 0x8d8) = 0;
  if (*(int *)(param_1 + 0x8fc) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x8fc));
    *(undefined4 *)(param_1 + 0x8fc) = 0;
  }
  *(undefined4 *)(param_1 + 0x904) = 0;
  *(undefined4 *)(param_1 + 0x900) = 0;
  (**(code **)(*(int *)(param_1 + 0x10) + 0xc))();
  (**(code **)(*(int *)(param_1 + 0x22c) + 0xc))();
  (**(code **)(*(int *)(param_1 + 0x448) + 0xc))();
                    /* WARNING: Could not recover jumptable at 0x007a0ffe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 0x664) + 0xc))();
  return;
}


/* ==================================================================== */
/* Address: 0x007a1010 | Classified: elementclient::_t2bk@0x7a1010 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a1010(int param_1,char param_2)

{
  int iVar1;
  char cVar2;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar3;
  undefined4 uStack_14;
  undefined1 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd3b8;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 == '\0') {
    (**(code **)(*(int *)(param_1 + 0x10) + 0xc))();
    (**(code **)(*(int *)(param_1 + 0x22c) + 0xc))();
    (**(code **)(*(int *)(param_1 + 0x448) + 0xc))();
    (**(code **)(*(int *)(param_1 + 0x664) + 0xc))();
    *(undefined4 *)(param_1 + 0x8a0) = 0;
LAB_007a121c:
    *(undefined4 *)(param_1 + 0x8a4) = 0;
    *(undefined1 *)(param_1 + 0x89c) = (undefined1)uStack_4;
    *unaff_FS_OFFSET = uStack_14;
    return 1;
  }
  iVar1 = param_1 + 0xc;
  func_0x005117a0(&uStack_14,iVar1,0x98c9b8);
  uStack_4 = 0;
  cVar2 = (**(code **)(*(int *)(param_1 + 0x10) + 8))(uStack_14,0x11);
  if (cVar2 == '\0') {
    uVar3 = 0x98ca40;
  }
  else {
    uVar3 = func_0x005117a0(&stack0xffffffe8,iVar1,0x98c9b0);
    uStack_c = CONCAT31(uStack_c._1_3_,1);
    func_0x00763940(uVar3);
    uStack_10 = 0;
    func_0x007637f0();
    cVar2 = (**(code **)(*(int *)(param_1 + 0x22c) + 8))(unaff_EDI,0x11);
    if (cVar2 != '\0') {
      uVar3 = func_0x005117a0(&stack0xffffffe8,iVar1,0x98c9a8);
      uStack_c = CONCAT31(uStack_c._1_3_,2);
      func_0x00763940(uVar3);
      uStack_10 = 0;
      func_0x007637f0();
      if (*(char *)(param_1 + 0x880) != '\0') {
        cVar2 = (**(code **)(*(int *)(param_1 + 0x448) + 8))(unaff_ESI,0x11);
        if (cVar2 == '\0') {
          func_0x007647d0(0x9d2f20,0x98c9c0,unaff_ESI);
          uStack_c = 0xffffffff;
          func_0x007637f0();
          *unaff_FS_OFFSET = uStack_14;
          return 0;
        }
      }
      if (*(char *)(param_1 + 0x881) != '\0') {
        func_0x00763aa0(0x96391c);
        cVar2 = (**(code **)(*(int *)(param_1 + 0x664) + 8))(unaff_EDI,0x11);
        if (cVar2 == '\0') {
          uVar3 = 0x98c9c0;
          goto LAB_007a1199;
        }
      }
      uStack_c = 0xffffffff;
      func_0x007637f0();
      goto LAB_007a121c;
    }
    uVar3 = 0x98ca00;
  }
LAB_007a1199:
  func_0x007647d0(0x9d2f20,uVar3,unaff_ESI);
  uStack_c = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_14;
  return 0;
}


/* ==================================================================== */
/* Address: 0x007a1250 | Classified: elementclient::A3DTrn2SubLoaderB__LoadBlockData@0x7a1250 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a1250(int param_1,undefined4 param_2)

{
  int *piVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint unaff_EBP;
  int unaff_ESI;
  int iVar7;
  undefined4 uStack_24;
  undefined1 auStack_10 [12];
  undefined1 auStack_4 [4];
  
  piVar1 = (int *)(param_1 + 0x10);
  uStack_24 = 0x11;
  cVar2 = (**(code **)(*(int *)(param_1 + 0x10) + 8))(param_2);
  if (cVar2 == '\0') {
    func_0x007647d0(0x9d2f20,0x98cbf0,param_2);
    return 0;
  }
  cVar2 = (char)auStack_4;
  iVar7 = 8;
  cVar3 = (**(code **)(*piVar1 + 0x10))(auStack_10);
  if (cVar3 == '\0') {
    func_0x007647d0(0x9d2f20,0x98cba8);
    return 0;
  }
  if (unaff_ESI != 0x54424b42) {
    func_0x007647d0(0x9d2f20,0x98cb6c);
    return 0;
  }
  if (5 < unaff_EBP) {
    func_0x007647d0(0x9d2f20,0x98cb18,5,unaff_EBP);
    return 0;
  }
  *(uint *)(param_1 + 0x894) = unaff_EBP;
  if (unaff_EBP < 2) {
    cVar2 = (**(code **)(*piVar1 + 0x10))(&uStack_24,4,auStack_10);
    if (cVar2 == '\0') {
      func_0x007647d0(0x9d2f20,0x98cac8);
      return 0;
    }
    *(undefined1 *)(param_1 + 0x890) = 0;
  }
  else if (unaff_EBP < 5) {
    cVar3 = (**(code **)(*piVar1 + 0x10))(&uStack_24,8,auStack_10);
    if (cVar3 == '\0') {
      func_0x007647d0(0x9d2f20,0x98cac8);
      return 0;
    }
    *(byte *)(param_1 + 0x890) = -(cVar2 != '\0') & 0x15;
  }
  else {
    cVar3 = (**(code **)(*piVar1 + 0x10))(&uStack_24,8,auStack_10);
    if (cVar3 == '\0') {
      func_0x007647d0(0x9d2f20,0x98cac8);
      return 0;
    }
    *(char *)(param_1 + 0x890) = cVar2;
  }
  *(undefined4 *)(param_1 + 0x8b8) = 100;
  if (iVar7 == 0) {
    if (*(int *)(param_1 + 0x8ac) != 0) {
      func_0x00763260(*(int *)(param_1 + 0x8ac));
      *(undefined4 *)(param_1 + 0x8ac) = 0;
    }
    *(undefined4 *)(param_1 + 0x8b4) = 0;
    *(undefined4 *)(param_1 + 0x8b0) = 0;
  }
  else {
    if (*(int *)(param_1 + 0x8b4) < iVar7) {
      iVar4 = func_0x00763250(iVar7 * 4);
      if (iVar4 == 0) {
        func_0x00764590(1,0x9505a4);
        goto LAB_007a14ac;
      }
      if (*(int *)(param_1 + 0x8ac) != 0) {
        iVar6 = *(int *)(param_1 + 0x8b0);
        if (iVar7 <= *(int *)(param_1 + 0x8b0)) {
          iVar6 = iVar7;
        }
        iVar5 = 0;
        if (0 < iVar6) {
          do {
            iVar5 = iVar5 + 1;
            *(undefined4 *)(iVar4 + -4 + iVar5 * 4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x8ac) + -4 + iVar5 * 4);
          } while (iVar5 < iVar6);
        }
        func_0x00763260(*(undefined4 *)(param_1 + 0x8ac));
      }
      *(int *)(param_1 + 0x8ac) = iVar4;
      *(int *)(param_1 + 0x8b4) = iVar7;
    }
    *(int *)(param_1 + 0x8b0) = iVar7;
  }
LAB_007a14ac:
  cVar2 = (**(code **)(*piVar1 + 0x10))(*(undefined4 *)(param_1 + 0x8ac),iVar7 * 4,&stack0xffffffe4)
  ;
  if (cVar2 == '\0') {
    if (*(int *)(param_1 + 0x8ac) != 0) {
      func_0x00763260(*(int *)(param_1 + 0x8ac));
      *(undefined4 *)(param_1 + 0x8ac) = 0;
    }
    *(undefined4 *)(param_1 + 0x8b4) = 0;
    *(undefined4 *)(param_1 + 0x8b0) = 0;
    func_0x007647d0(0x9d2f20,0x98ca80);
    return 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a1520 | Classified: elementclient::A3DTrn2SubLoaderB__LoadMaskDataF@0x7a1520 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a1520(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  int unaff_EBX;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined1 *puVar10;
  undefined4 uStack_64;
  uint uStack_50;
  undefined4 uStack_48;
  undefined1 auStack_28 [12];
  undefined1 auStack_1c [12];
  undefined1 auStack_10 [12];
  undefined1 auStack_4 [4];
  
  uStack_64 = 0x11;
  cVar1 = (**(code **)(*(int *)(param_1 + 0x22c) + 8))();
  if (cVar1 == '\0') {
    func_0x007647d0(0x9d2f20,0x98cdb0,param_2);
    return 0;
  }
  puVar10 = auStack_4;
  cVar1 = (**(code **)(*(int *)(param_1 + 0x22c) + 0x10))(&uStack_48,8);
  if (cVar1 == '\0') {
    func_0x007647d0(0x9d2f20,0x98cd68);
    return 0;
  }
  if (unaff_EBX != 0x544d4b42) {
    func_0x007647d0(0x9d2f20,0x98cd2c);
    return 0;
  }
  if (2 < uStack_50) {
    func_0x007647d0(0x9d2f20,0x98ccd8,2,uStack_50);
    return 0;
  }
  iVar7 = *(int *)(param_1 + 0x22c);
  *(uint *)(param_1 + 0x898) = uStack_50;
  if (uStack_50 < 2) {
    cVar1 = (**(code **)(iVar7 + 0x10))(&stack0xffffffa0,8);
    if (cVar1 == '\0') {
      func_0x007647d0(0x9d2f20,0x98cc88);
      return 0;
    }
    *(undefined1 *)(param_1 + 0x891) = 0;
  }
  else {
    cVar1 = (**(code **)(iVar7 + 0x10))(&stack0xffffffa0,0xc,auStack_10);
    if (cVar1 == '\0') {
      func_0x007647d0(0x9d2f20,0x98cc88);
      return 0;
    }
    *(undefined1 *)(param_1 + 0x891) = (undefined1)uStack_64;
  }
  *(undefined4 *)(param_1 + 0x8cc) = 100;
  if (puVar10 == (undefined1 *)0x0) {
    if (*(int *)(param_1 + 0x8c0) != 0) {
      func_0x00763260(*(int *)(param_1 + 0x8c0));
      *(undefined4 *)(param_1 + 0x8c0) = 0;
    }
    *(undefined4 *)(param_1 + 0x8c8) = 0;
    *(undefined4 *)(param_1 + 0x8c4) = 0;
  }
  else {
    if (*(int *)(param_1 + 0x8c8) < (int)puVar10) {
      iVar7 = func_0x00763250((int)puVar10 * 4);
      if (iVar7 == 0) {
        func_0x00764590(1,0x9505a4);
        goto LAB_007a172a;
      }
      if (*(int *)(param_1 + 0x8c0) != 0) {
        puVar5 = *(undefined1 **)(param_1 + 0x8c4);
        if ((int)puVar10 <= (int)*(undefined1 **)(param_1 + 0x8c4)) {
          puVar5 = puVar10;
        }
        iVar2 = 0;
        if (0 < (int)puVar5) {
          do {
            iVar2 = iVar2 + 1;
            *(undefined4 *)(iVar7 + -4 + iVar2 * 4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x8c0) + -4 + iVar2 * 4);
          } while (iVar2 < (int)puVar5);
        }
        func_0x00763260(*(undefined4 *)(param_1 + 0x8c0));
      }
      *(undefined1 **)(param_1 + 0x8c8) = puVar10;
      *(int *)(param_1 + 0x8c0) = iVar7;
    }
    *(undefined1 **)(param_1 + 0x8c4) = puVar10;
  }
LAB_007a172a:
  cVar1 = (**(code **)(*(int *)(param_1 + 0x22c) + 0x10))
                    (*(undefined4 *)(param_1 + 0x8c0),(int)puVar10 << 2,auStack_1c);
  if (cVar1 != '\0') {
    if (0 < param_2) {
      do {
        (**(code **)(*(int *)(param_1 + 0x22c) + 0x10))(&uStack_64,0x1c,auStack_28);
        uStack_48 = uStack_64;
        if ((*(int *)(param_1 + 0x904) <= *(int *)(param_1 + 0x900)) &&
           (*(int *)(param_1 + 0x908) != 0)) {
          iVar7 = *(int *)(param_1 + 0x908) + *(int *)(param_1 + 0x904);
          iVar2 = iVar7;
          iVar3 = func_0x00763250(iVar7 * 0x1c);
          if (iVar3 == 0) {
            func_0x00764590(1,0x94e51c);
          }
          else {
            iVar6 = 0;
            if (0 < *(int *)(param_1 + 0x900)) {
              iVar4 = 0;
              do {
                puVar8 = (undefined4 *)(*(int *)(param_1 + 0x8fc) + iVar4);
                puVar9 = (undefined4 *)(iVar4 + iVar3);
                for (iVar7 = 7; iVar7 != 0; iVar7 = iVar7 + -1) {
                  *puVar9 = *puVar8;
                  puVar8 = puVar8 + 1;
                  puVar9 = puVar9 + 1;
                }
                iVar6 = iVar6 + 1;
                iVar4 = iVar4 + 0x1c;
                iVar7 = iVar2;
              } while (iVar6 < *(int *)(param_1 + 0x900));
            }
            if (*(int *)(param_1 + 0x8fc) != 0) {
              func_0x00763260(*(int *)(param_1 + 0x8fc));
            }
            *(int *)(param_1 + 0x8fc) = iVar3;
            *(int *)(param_1 + 0x904) = iVar7;
          }
        }
        puVar8 = &uStack_48;
        puVar9 = (undefined4 *)(*(int *)(param_1 + 0x8fc) + *(int *)(param_1 + 0x900) * 0x1c);
        for (iVar7 = 7; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar9 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar9 = puVar9 + 1;
        }
        param_2 = param_2 + -1;
        *(int *)(param_1 + 0x900) = *(int *)(param_1 + 0x900) + 1;
      } while (param_2 != 0);
    }
    return 1;
  }
  func_0x007647d0(0x9d2f20,0x98cc40);
  return 0;
}


/* ==================================================================== */
/* Address: 0x007a18c0 | Classified: elementclient::A3DTrn2SubLoaderB__LoadLightMapF@0x7a18c0 */
/* ==================================================================== */

/* WARNING: Removing unreachable block (ram,0x007a198e) */
/* WARNING: Removing unreachable block (ram,0x007a1997) */
/* WARNING: Removing unreachable block (ram,0x007a19c4) */
/* WARNING: Removing unreachable block (ram,0x007a19fe) */
/* WARNING: Removing unreachable block (ram,0x007a1a34) */
/* WARNING: Removing unreachable block (ram,0x007a19ce) */
/* WARNING: Removing unreachable block (ram,0x007a1a0e) */
/* WARNING: Removing unreachable block (ram,0x007a19de) */
/* WARNING: Removing unreachable block (ram,0x007a1a54) */
/* WARNING: Removing unreachable block (ram,0x007a1a68) */
/* WARNING: Removing unreachable block (ram,0x007a1a60) */
/* WARNING: Removing unreachable block (ram,0x007a1a6e) */
/* WARNING: Removing unreachable block (ram,0x007a1a94) */
/* WARNING: Removing unreachable block (ram,0x007a1a99) */
/* WARNING: Removing unreachable block (ram,0x007a1aaf) */
/* WARNING: Removing unreachable block (ram,0x007a1ac0) */
/* WARNING: Removing unreachable block (ram,0x007a1ac7) */
/* WARNING: Removing unreachable block (ram,0x007a1ace) */
/* WARNING: Removing unreachable block (ram,0x007a1ad0) */
/* WARNING: Removing unreachable block (ram,0x007a1ad6) */
/* WARNING: Removing unreachable block (ram,0x007a1ae6) */
/* WARNING: Removing unreachable block (ram,0x007a1af2) */
/* WARNING: Removing unreachable block (ram,0x007a1afa) */
/* WARNING: Removing unreachable block (ram,0x007a1a79) */
/* WARNING: Removing unreachable block (ram,0x007a1a80) */
/* WARNING: Removing unreachable block (ram,0x007a1a8c) */
/* WARNING: Removing unreachable block (ram,0x007a1afd) */
/* WARNING: Removing unreachable block (ram,0x007a1b1a) */
/* WARNING: Removing unreachable block (ram,0x007a1b29) */
/* WARNING: Removing unreachable block (ram,0x007a1b35) */

uint __thiscall FUN_007a18c0(int param_1,undefined4 param_2,char param_3)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  undefined1 auStack_4 [4];
  
  if (*(char *)(*(int *)(param_1 + 4) + 0x178) != '\0') {
    return CONCAT31((int3)((uint)*(int *)(param_1 + 4) >> 8),1);
  }
  piVar3 = (int *)(param_1 + 0x448);
  if (param_3 == '\0') {
    piVar3 = (int *)(param_1 + 0x664);
  }
  cVar1 = (**(code **)(*piVar3 + 8))();
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(*piVar3 + 0x10))(&stack0xffffffe0,8,auStack_4);
    if (cVar1 != '\0') {
      (**(code **)(*piVar3 + 0xc))();
      uVar2 = func_0x007647d0(0x9d2f20,0x98ceec);
      return uVar2 & 0xffffff00;
    }
    (**(code **)(*piVar3 + 0xc))();
    uVar2 = func_0x007647d0(0x9d2f20,0x98cf28);
    return uVar2 & 0xffffff00;
  }
  uVar2 = func_0x007647d0(0x9d2f20,0x98cf78,param_2);
  return uVar2 & 0xffffff00;
}


/* ==================================================================== */
/* Address: 0x007a1b70 | Classified: Angelica3D::proc_7a1b70 */
/* ==================================================================== */

int * __thiscall FUN_007a1b70(int param_1,int param_2)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd3db;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (*(char *)(param_1 + 0x89c) == '\0') {
    cVar2 = FUN_007a1010(1);
    if (cVar2 == '\0') {
      *unaff_FS_OFFSET = uStack_c;
      return (int *)0x0;
    }
  }
  iVar3 = func_0x00763250(0xd4);
  uStack_4 = 0;
  if (iVar3 == 0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)func_0x007c3920(*(undefined4 *)(param_1 + 4));
  }
  uStack_4 = 0xffffffff;
  if (piVar4 == (int *)0x0) {
    *unaff_FS_OFFSET = uStack_c;
    return (int *)0x0;
  }
  cVar2 = (**(code **)(*piVar4 + 4))();
  if (cVar2 == '\0') {
    *unaff_FS_OFFSET = uStack_c;
    return (int *)0x0;
  }
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x8ac) + param_2 * 4);
  (**(code **)(*(int *)(param_1 + 0x10) + 0x30))();
  cVar2 = FUN_007a1ce0(piVar4,unaff_retaddr,param_2);
  if (cVar2 == '\0') {
    (**(code **)(*piVar4 + 8))();
    (**(code **)*piVar4)(1);
    *unaff_FS_OFFSET = uVar1;
    return (int *)0x0;
  }
  *(int *)(param_1 + 0x8a0) = *(int *)(param_1 + 0x8a0) + 1;
  *unaff_FS_OFFSET = 0;
  return piVar4;
}


/* ==================================================================== */
/* Address: 0x007a1ce0 | Classified: elementclient::A3DTrn2SubLoaderB__ReadBlockData@0x7a1ce0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_007a1ce0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 unaff_ESI;
  int *piVar9;
  uint *puVar10;
  undefined4 unaff_EDI;
  int *piVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  undefined4 *puStack_84;
  undefined4 *puStack_80;
  int **ppiStack_7c;
  undefined4 uStack_78;
  undefined4 *puStack_74;
  undefined4 uStack_60;
  undefined4 auStack_5c [5];
  int aiStack_48 [3];
  int *piStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  ushort uStack_28;
  ushort uStack_26;
  undefined2 uStack_24;
  undefined2 uStack_22;
  int *piStack_20;
  undefined4 *puStack_1c;
  int iStack_18;
  int *piStack_14;
  undefined4 uStack_10;
  int *piStack_8;
  
  uVar6 = *(uint *)(param_1 + 0x894);
  puStack_74 = &uStack_60;
  piVar9 = (int *)(param_1 + 0x10);
  if (uVar6 < 2) {
    ppiStack_7c = &piStack_3c;
    uStack_78 = 0x10;
    puStack_80 = (undefined4 *)0x7a1d14;
    cVar5 = (**(code **)(*piVar9 + 0x10))();
    if (cVar5 == '\0') {
      puStack_80 = (undefined4 *)0x98d110;
      puStack_84 = (undefined4 *)0x9d2f20;
      uVar6 = func_0x007647d0();
      return uVar6 & 0xffffff00;
    }
    iStack_2c = aiStack_48[0];
    uStack_24 = (undefined2)aiStack_48[2];
    uStack_22 = (undefined2)((uint)aiStack_48[2] >> 0x10);
    piStack_20 = piStack_3c;
    uStack_28 = (ushort)aiStack_48[1];
    uStack_26 = (ushort)((uint)aiStack_48[1] >> 0x10);
    puStack_1c = (undefined4 *)(*(int *)(param_2 + 0x6c) * 4);
    iStack_18 = *(int *)(param_2 + 0x6c) * 0xc;
  }
  else {
    if (2 < uVar6) {
      if (uVar6 < 4) {
        ppiStack_7c = &piStack_3c;
        uStack_78 = 0x1c;
        puStack_80 = (undefined4 *)0x7a1e30;
        cVar5 = (**(code **)(*piVar9 + 0x10))();
        if (cVar5 == '\0') {
          puStack_80 = (undefined4 *)0x98d110;
          puStack_84 = (undefined4 *)0x9d2f20;
          uVar6 = func_0x007647d0();
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
        ppiStack_7c = &piStack_20;
        uStack_78 = 0x20;
        puStack_80 = (undefined4 *)0x7a1e78;
        cVar5 = (**(code **)(*piVar9 + 0x10))();
        if (cVar5 == '\0') {
          puStack_80 = (undefined4 *)0x98d110;
          puStack_84 = (undefined4 *)0x9d2f20;
          uVar6 = func_0x007647d0();
          return uVar6 & 0xffffff00;
        }
      }
      goto LAB_007a1d76;
    }
    ppiStack_7c = &piStack_3c;
    uStack_78 = 0x18;
    puStack_80 = (undefined4 *)0x7a1de9;
    cVar5 = (**(code **)(*piVar9 + 0x10))();
    if (cVar5 == '\0') {
      puStack_80 = (undefined4 *)0x98d110;
      puStack_84 = (undefined4 *)0x9d2f20;
      uVar6 = func_0x007647d0();
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
  *(int **)(param_2 + 0x80) = piStack_20;
  iVar8 = 0;
  *(int *)(param_2 + 0x20) = iStack_2c;
  *(uint *)(param_2 + 0x28) = uVar6;
  *(uint *)(param_2 + 0x2c) = uVar4;
  *(undefined4 *)(param_2 + 0x7c) = 0x3f800000;
  *(undefined4 *)(param_2 + 0x70) = 3;
  *(undefined4 *)(param_2 + 0x78) = 0;
  *(undefined4 *)(param_2 + 0x84) = 0;
  do {
    if (((uint)piStack_20 & 1 << ((byte)iVar8 & 0x1f)) != 0) {
      *(int *)(param_2 + 0x84) = iVar8;
      break;
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 < 0x20);
  iVar8 = *(int *)(*(int *)(param_1 + 4) + 0x1d4) / *(int *)(*(int *)(param_1 + 4) + 0x1d0);
  *(int *)(param_2 + 0x30) = (int)((longlong)(ulonglong)uVar6 % (longlong)iVar8);
  *(int *)(param_2 + 0x34) = (int)((longlong)(ulonglong)uVar4 % (longlong)iVar8);
  iVar8 = *(int *)(param_1 + 4);
  iVar7 = *(int *)(iVar8 + 0x1d8) / *(int *)(iVar8 + 0x1d0);
  *(int *)(param_2 + 0x1c) =
       (*(int *)(iVar8 + 0x188) / iVar7) * (int)((longlong)(ulonglong)uVar6 / (longlong)iVar7) +
       (int)((longlong)(ulonglong)uVar4 / (longlong)iVar7);
  iVar8 = *(int *)(param_1 + 4);
  puVar10 = (uint *)(iVar8 + 0x310);
  uStack_60 = 0;
  auStack_5c[0] = 0;
  if (*(char *)(param_1 + 0x890) != '\0') {
    puStack_80 = auStack_5c;
    puStack_84 = &uStack_60;
    cVar5 = FUN_007a39f0(&stack0xffffff98,&stack0xffffff9c,0);
    if (cVar5 == '\0') {
      puStack_80 = (undefined4 *)0x98d0d4;
      puStack_84 = (undefined4 *)0x9d2f20;
      uVar6 = func_0x007647d0();
      return uVar6 & 0xffffff00;
    }
  }
  puStack_80 = (undefined4 *)&stack0xffffff94;
  puStack_84 = puStack_1c;
  if ((*(byte *)(param_1 + 0x890) & 0xc) == 0) {
    uVar13 = *(undefined4 *)(iVar8 + 0x314);
    cVar5 = (**(code **)(*piStack_8 + 0x10))(uVar13);
    if (cVar5 == '\0') {
      uVar6 = func_0x007647d0(0x9d2f20,0x98d090);
      return uVar6 & 0xffffff00;
    }
  }
  else {
    uVar13 = 0;
    cVar5 = (**(code **)(*piStack_8 + 0x10))(0);
    if (cVar5 == '\0') {
      uVar6 = func_0x007647d0(0x9d2f20,0x98d090);
      return uVar6 & 0xffffff00;
    }
    if ((*(byte *)(param_1 + 0x890) & 8) == 0) {
      func_0x00771a40(puStack_74,CONCAT22(uStack_26,uStack_28),*(undefined4 *)(iVar8 + 0x314),
                      &stack0xffffff9c);
    }
    else if ((*(byte *)(param_1 + 0x890) & 4) == 0) {
      FUN_0077f920(puStack_74,*(undefined4 *)(iVar8 + 0x314));
    }
    else {
      func_0x00771a40(puStack_74,CONCAT22(uStack_26,uStack_28),unaff_ESI,&stack0xffffff9c);
      FUN_0077f920(unaff_ESI,*(undefined4 *)(iVar8 + 0x314));
    }
  }
  if ((*(byte *)(param_1 + 0x890) & 0x30) == 0) {
    cVar5 = (**(code **)(*piStack_14 + 0x10))(*(undefined4 *)(iVar8 + 0x318));
    if (cVar5 == '\0') {
      uVar6 = func_0x007647d0(0x9d2f20,0x98d048);
      return uVar6 & 0xffffff00;
    }
  }
  else {
    cVar5 = (**(code **)(*piStack_14 + 0x10))(unaff_EDI,CONCAT22(uStack_22,uStack_24),&uStack_78);
    if (cVar5 == '\0') {
      uVar6 = func_0x007647d0(0x9d2f20,0x98d048);
      return uVar6 & 0xffffff00;
    }
    if ((*(byte *)(param_1 + 0x890) & 0x20) == 0) {
      func_0x00771a40(ppiStack_7c,uStack_30,*(undefined4 *)(iVar8 + 0x318),&stack0xffffff90);
    }
    else if ((*(byte *)(param_1 + 0x890) & 0x10) == 0) {
      FUN_0077f990(ppiStack_7c,*(undefined4 *)(iVar8 + 0x318));
    }
    else {
      func_0x00771a40(ppiStack_7c,uStack_30,puStack_74,&stack0xffffff90);
      FUN_0077f990(puStack_74,*(undefined4 *)(iVar8 + 0x318));
    }
  }
  if (*(char *)(*(int *)(param_1 + 4) + 0x1b5) != '\0') {
    if ((*(byte *)(param_1 + 0x890) & 1) == 0) {
      if ((*(uint *)(param_1 + 0x894) < 3) || (iStack_2c == 0)) {
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
        cVar5 = (**(code **)(*piStack_20 + 0x10))
                          (*(undefined4 *)(iVar8 + 0x31c),iStack_2c,&puStack_84);
        if (cVar5 == '\0') {
          uVar6 = func_0x007647d0(0x9d2f20,0x98d000);
          return uVar6 & 0xffffff00;
        }
      }
      if ((*(uint *)(param_1 + 0x894) < 4) || (CONCAT22(uStack_26,uStack_28) == 0)) {
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
        cVar5 = (**(code **)(*piStack_20 + 0x10))
                          (*(undefined4 *)(iVar8 + 800),CONCAT22(uStack_26,uStack_28),&puStack_84);
        if (cVar5 == '\0') {
          uVar6 = func_0x007647d0(0x9d2f20,0x98d000);
          return uVar6 & 0xffffff00;
        }
      }
    }
    else {
      ppiStack_7c = (int **)0x0;
      if (((iStack_2c != 0) || (CONCAT22(uStack_26,uStack_28) != 0)) &&
         (cVar5 = FUN_007a39f0(0,0,&ppiStack_7c,0,0), cVar5 == '\0')) {
        uVar6 = func_0x007647d0(0x9d2f20,0x98d0d4);
        return uVar6 & 0xffffff00;
      }
      if ((2 < *(uint *)(param_1 + 0x894)) && (iStack_2c != 0)) {
        cVar5 = (**(code **)(*piStack_20 + 0x10))(ppiStack_7c,iStack_2c,&puStack_84);
        if (cVar5 == '\0') {
          uVar6 = func_0x007647d0(0x9d2f20,0x98d000);
          return uVar6 & 0xffffff00;
        }
        ppiStack_7c = (int **)(*puVar10 << 2);
        func_0x00771a40(uVar13,uStack_38,*(undefined4 *)(iVar8 + 0x31c),&ppiStack_7c);
      }
      if ((3 < *(uint *)(param_1 + 0x894)) && (CONCAT22(uStack_26,uStack_28) != 0)) {
        cVar5 = (**(code **)(*piStack_20 + 0x10))
                          (ppiStack_7c,CONCAT22(uStack_26,uStack_28),&puStack_84);
        if (cVar5 == '\0') {
          uVar6 = func_0x007647d0(0x9d2f20,0x98d000);
          return uVar6 & 0xffffff00;
        }
        iStack_2c = *puVar10 << 2;
        func_0x00771a40(uVar13,uStack_34,*(undefined4 *)(iVar8 + 800),&iStack_2c);
      }
    }
  }
  cVar5 = func_0x007c3ad0(puStack_1c,iStack_18);
  if (cVar5 != '\0') {
    fVar1 = (*(float *)(param_2 + 0x54) + *(float *)(param_2 + 0x60)) * _DAT_008eff98;
    fVar2 = (*(float *)(param_2 + 0x58) + *(float *)(param_2 + 100)) * _DAT_008eff98;
    *(float *)(param_2 + 0x3c) = fVar1;
    fVar3 = (*(float *)(param_2 + 0x5c) + *(float *)(param_2 + 0x68)) * _DAT_008eff98;
    *(float *)(param_2 + 0x44) = fVar3;
    *(float *)(param_2 + 0x40) = fVar2;
    *(float *)(param_2 + 0x48) = *(float *)(param_2 + 0x60) - fVar1;
    *(float *)(param_2 + 0x50) = *(float *)(param_2 + 0x68) - fVar3;
    *(float *)(param_2 + 0x4c) = *(float *)(param_2 + 100) - fVar2;
    *(undefined1 *)(param_2 + 0x18) = 1;
    return CONCAT31((int3)((uint)fVar2 >> 8),1);
  }
  uVar6 = func_0x007647d0(0x9d2f20,0x98cfc0);
  return uVar6 & 0xffffff00;
}


/* ==================================================================== */
/* Address: 0x007a2410 | Classified: elementclient::A3DTrn2SubLoaderB__LoadMask__not@0x7a2410 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __thiscall FUN_007a2410(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 *unaff_FS_OFFSET;
  int *piStack_54;
  int *piStack_48;
  int aiStack_30 [4];
  int iStack_20;
  int aiStack_18 [3];
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd3fb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  piStack_48 = (int *)0x7c;
  aiStack_30[1] = func_0x00763250();
  uStack_4 = 0;
  if (aiStack_30[1] == 0) {
    piVar5 = (int *)0x0;
  }
  else {
    piStack_48 = param_2;
    piVar5 = (int *)func_0x007c3580(*(undefined4 *)(param_1 + 4));
  }
  uStack_4 = 0xffffffff;
  if (piVar5 == (int *)0x0) {
    piStack_48 = (int *)0x98d1bc;
    func_0x007647d0(0x9d2f20);
    piVar5 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(param_1 + 0x22c);
    iVar10 = *(int *)(*(int *)(param_1 + 0x8c0) + param_3 * 4);
    piStack_48 = (int *)0x0;
    (**(code **)(*(int *)(param_1 + 0x22c) + 0x30))(iVar10);
    piStack_54 = (int *)0x4;
    cVar4 = (**(code **)(*piVar1 + 0x10))();
    if (cVar4 == '\0') {
      func_0x007647d0(0x9d2f20,0x98d180);
      piVar5 = (int *)0x0;
    }
    else {
      (**(code **)(*piVar5 + 4))(piStack_48);
      if (*(uint *)(param_1 + 0x898) < 2) {
        piVar6 = (int *)func_0x00763250(iVar10 * 8);
        piStack_48 = piVar6;
        if (piVar6 == (int *)0x0) {
          func_0x007647d0(0x9d2f20,0x98d150);
          piVar5 = (int *)0x0;
          goto LAB_007a2b51;
        }
        (**(code **)(*piVar1 + 0x10))(piVar6,iVar10 * 8,&stack0xffffffc0);
        iVar10 = 0;
        piStack_48 = (int *)0x0;
        if (0 < (int)&stack0xffffffc4) {
          do {
            puVar2 = (undefined4 *)(*(int *)(param_1 + 0x8fc) + *(int *)(iVar10 * 8 + 4) * 0x1c);
            puVar3 = (undefined4 *)(piVar5[0x1b] + iVar10 * 0x24);
            *puVar3 = *puVar2;
            puVar3[1] = puVar2[1];
            puVar3[2] = puVar2[2];
            *(undefined1 *)(puVar3 + 3) = *(undefined1 *)(puVar2 + 3);
            puVar3[4] = puVar2[4];
            puVar3[5] = puVar2[5];
            *(undefined1 *)(puVar3 + 6) = *(undefined1 *)(puVar2 + 6);
            puVar3[7] = *(undefined4 *)(iVar10 * 8 + 8);
            puVar3[8] = 0;
            iStack_20 = FUN_0077f180(*puVar3);
            if (piVar5[0xc] <= piVar5[0xb]) {
              func_0x0068e120(piVar5[0xd]);
            }
            *(int *)(piVar5[10] + piVar5[0xb] * 4) = iStack_20;
            piVar5[0xb] = piVar5[0xb] + 1;
            if (*(char *)(_DAT_009d30fc + 0xc) == '\0') {
              if (iVar10 != 0) {
                iStack_20 = FUN_007a2e60(piVar5,iVar10);
                goto LAB_007a265b;
              }
              if (piVar5[0x18] <= piVar5[0x17]) {
                func_0x0068e120(piVar5[0x19]);
              }
              *(undefined4 *)(piVar5[0x16] + piVar5[0x17] * 4) = 0;
LAB_007a2684:
              piVar5[0x17] = piVar5[0x17] + 1;
            }
            else {
              FUN_007a2b90(piVar5,iVar10,&piStack_48);
              if (iVar10 % 3 == 2) {
                iStack_20 = FUN_007a2ce0(3,&piStack_48);
LAB_007a265b:
                if (piVar5[0x18] <= piVar5[0x17]) {
                  func_0x0068e120(piVar5[0x19]);
                }
                *(int *)(piVar5[0x16] + piVar5[0x17] * 4) = iStack_20;
                goto LAB_007a2684;
              }
            }
            iVar10 = iVar10 + 1;
            piVar6 = piStack_54;
          } while (iVar10 < (int)&stack0xffffffc4);
        }
        func_0x00763260(piVar6);
        if ((*(char *)(_DAT_009d30fc + 0xc) != '\0') && (iVar10 % 3 != 0)) {
          piStack_48 = aiStack_30 + 3;
          uVar7 = FUN_007a2ce0(iVar10 % 3);
          if (piVar5[0x18] <= piVar5[0x17]) {
            piStack_48 = (int *)piVar5[0x19];
            func_0x0068e120();
          }
          *(undefined4 *)(piVar5[0x16] + piVar5[0x17] * 4) = uVar7;
          piVar5[0x17] = piVar5[0x17] + 1;
        }
      }
      else {
        iVar8 = func_0x00763250(iVar10 * 0xc);
        iVar9 = 0;
        if (iVar8 == 0) {
          func_0x007647d0(0x9d2f20,0x98d150);
          piVar5 = (int *)0x0;
          goto LAB_007a2b51;
        }
        (**(code **)(*piVar1 + 0x10))(iVar8,iVar10 * 0xc,&stack0xffffffc0);
        if (0 < (int)&stack0xffffffc4) {
          do {
            puVar2 = (undefined4 *)(*(int *)(param_1 + 0x8fc) + aiStack_30[iVar9 * 3] * 0x1c);
            puVar3 = (undefined4 *)(piVar5[0x1b] + iVar9 * 0x24);
            *puVar3 = *puVar2;
            puVar3[1] = puVar2[1];
            puVar3[2] = puVar2[2];
            *(undefined1 *)(puVar3 + 3) = *(undefined1 *)(puVar2 + 3);
            puVar3[4] = puVar2[4];
            puVar3[5] = puVar2[5];
            *(undefined1 *)(puVar3 + 6) = *(undefined1 *)(puVar2 + 6);
            puVar3[7] = aiStack_30[iVar9 * 3 + 1];
            puVar3[8] = aiStack_30[iVar9 * 3 + 2];
            uVar7 = FUN_0077f180(*puVar3);
            if (piVar5[0xc] <= piVar5[0xb]) {
              func_0x0068e120(piVar5[0xd]);
            }
            *(undefined4 *)(piVar5[10] + piVar5[0xb] * 4) = uVar7;
            piVar5[0xb] = piVar5[0xb] + 1;
            if (*(char *)(_DAT_009d30fc + 0xc) == '\0') {
              if (iVar9 != 0) {
                iStack_20 = FUN_007a2e60(piVar5,iVar9);
                if ((piVar5[0x18] <= piVar5[0x17]) && (piVar5[0x19] != 0)) {
                  piStack_54 = (int *)(piVar5[0x19] + piVar5[0x18]);
                  iVar10 = func_0x00763250((int)piStack_54 * 4);
                  if (iVar10 != 0) {
                    iVar8 = 0;
                    if (0 < piVar5[0x17]) {
                      do {
                        iVar8 = iVar8 + 1;
                        *(undefined4 *)(iVar10 + -4 + iVar8 * 4) =
                             *(undefined4 *)(piVar5[0x16] + -4 + iVar8 * 4);
                      } while (iVar8 < piVar5[0x17]);
                    }
                    goto LAB_007a29b3;
                  }
                  func_0x00764590(1,0x94e51c);
                }
                goto LAB_007a29cd;
              }
              if ((piVar5[0x18] <= piVar5[0x17]) && (piVar5[0x19] != 0)) {
                iStack_20 = piVar5[0x19] + piVar5[0x18];
                iVar10 = func_0x00763250(iStack_20 * 4);
                if (iVar10 == 0) {
                  func_0x00764590(1,0x94e51c);
                  *(undefined4 *)(piVar5[0x16] + piVar5[0x17] * 4) = 0;
                  goto LAB_007a29da;
                }
                iVar8 = 0;
                if (0 < piVar5[0x17]) {
                  do {
                    iVar8 = iVar8 + 1;
                    *(undefined4 *)(iVar10 + -4 + iVar8 * 4) =
                         *(undefined4 *)(piVar5[0x16] + -4 + iVar8 * 4);
                  } while (iVar8 < piVar5[0x17]);
                }
                if (piVar5[0x16] != 0) {
                  func_0x00763260(piVar5[0x16]);
                }
                piVar5[0x16] = iVar10;
                piVar5[0x18] = iStack_20;
              }
              *(undefined4 *)(piVar5[0x16] + piVar5[0x17] * 4) = 0;
LAB_007a29da:
              piVar5[0x17] = piVar5[0x17] + 1;
            }
            else {
              FUN_007a2b90(piVar5,iVar9,&stack0xffffffc4);
              if (iVar9 % 3 == 2) {
                iStack_20 = FUN_007a2ce0(3,&stack0xffffffc4);
                if ((piVar5[0x18] <= piVar5[0x17]) && (piVar5[0x19] != 0)) {
                  piStack_54 = (int *)(piVar5[0x19] + piVar5[0x18]);
                  iVar10 = func_0x00763250((int)piStack_54 * 4);
                  if (iVar10 == 0) {
                    func_0x00764590(1,0x94e51c);
                  }
                  else {
                    iVar8 = 0;
                    if (0 < piVar5[0x17]) {
                      do {
                        iVar8 = iVar8 + 1;
                        *(undefined4 *)(iVar10 + -4 + iVar8 * 4) =
                             *(undefined4 *)(piVar5[0x16] + -4 + iVar8 * 4);
                      } while (iVar8 < piVar5[0x17]);
                    }
LAB_007a29b3:
                    if (piVar5[0x16] != 0) {
                      func_0x00763260(piVar5[0x16]);
                    }
                    piVar5[0x18] = (int)piStack_54;
                    piVar5[0x16] = iVar10;
                  }
                }
LAB_007a29cd:
                *(int *)(piVar5[0x16] + piVar5[0x17] * 4) = iStack_20;
                goto LAB_007a29da;
              }
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)&stack0xffffffc4);
        }
        func_0x00763260(aiStack_30);
        if ((*(char *)(_DAT_009d30fc + 0xc) != '\0') && (iVar9 % 3 != 0)) {
          piStack_48 = aiStack_18;
          uVar7 = FUN_007a2ce0(iVar9 % 3);
          if ((piVar5[0x18] <= piVar5[0x17]) && (piVar5[0x19] != 0)) {
            iVar8 = piVar5[0x19] + piVar5[0x18];
            piStack_48 = (int *)(iVar8 * 4);
            iVar10 = func_0x00763250();
            if (iVar10 == 0) {
              piStack_48 = (int *)0x94e51c;
              func_0x00764590(1);
            }
            else {
              iVar9 = 0;
              if (0 < piVar5[0x17]) {
                do {
                  iVar9 = iVar9 + 1;
                  *(undefined4 *)(iVar10 + -4 + iVar9 * 4) =
                       *(undefined4 *)(piVar5[0x16] + -4 + iVar9 * 4);
                } while (iVar9 < piVar5[0x17]);
              }
              piStack_48 = (int *)piVar5[0x16];
              if (piStack_48 != (int *)0x0) {
                func_0x00763260();
              }
              piVar5[0x16] = iVar10;
              piVar5[0x18] = iVar8;
            }
          }
          *(undefined4 *)(piVar5[0x16] + piVar5[0x17] * 4) = uVar7;
          piVar5[0x17] = piVar5[0x17] + 1;
        }
      }
      if (*(char *)(param_1 + 0x880) == '\0') {
        iVar10 = *(int *)(_DAT_009d30fc + 0x18);
        *(undefined1 *)(piVar5 + 6) = 0;
      }
      else {
        piStack_48 = (int *)0x1;
        if ((*(byte *)(param_1 + 0x88c) & 1) == 0) {
          iVar10 = FUN_007a3040(param_3);
          *(undefined1 *)(piVar5 + 6) = 1;
        }
        else {
          iVar10 = FUN_007a31e0();
          *(undefined1 *)(piVar5 + 6) = 1;
        }
      }
      piVar5[3] = iVar10;
      if (*(char *)(param_1 + 0x881) == '\0') {
        iVar10 = *(int *)(_DAT_009d30fc + 0x18);
        *(undefined1 *)((int)piVar5 + 0x19) = 0;
        piVar5[4] = iVar10;
      }
      else {
        piStack_48 = (int *)0x0;
        if ((*(byte *)(param_1 + 0x88c) & 1) == 0) {
          iVar10 = FUN_007a3040(param_3);
          piVar5[4] = iVar10;
          *(undefined1 *)((int)piVar5 + 0x19) = 1;
        }
        else {
          iVar10 = FUN_007a31e0();
          piVar5[4] = iVar10;
          *(undefined1 *)((int)piVar5 + 0x19) = 1;
        }
      }
      if (*(char *)(*(int *)(param_1 + 4) + 0x1b6) != '\0') {
        piStack_48 = piVar5;
        iVar10 = func_0x007c3040();
        piVar5[5] = iVar10;
      }
    }
  }
LAB_007a2b51:
  *unaff_FS_OFFSET = uStack_c;
  return piVar5;
}


/* ==================================================================== */
/* Address: 0x007a2b70 | Classified: Angelica3D::proc_7a2b70 */
/* ==================================================================== */

void FUN_007a2b70(int *param_1)

{
  (**(code **)(*param_1 + 8))();
  (**(code **)*param_1)(1);
  return;
}


/* ==================================================================== */
/* Address: 0x007a2b90 | Classified: elementclient::A3DTrn2SubLoaderB__LoadMaskMapDa@0x7a2b90 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a2b90(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_retaddr;
  undefined4 uStack_1c;
  int iStack_8;
  
  if (param_3 == 0) {
    *param_4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x20);
    return 1;
  }
  piVar1 = (int *)(param_1 + 0x22c);
  uStack_1c = 0;
  iVar4 = *(int *)(*(int *)(param_2 + 0x6c) + 8 + param_3 * 0x24);
  iVar2 = *(int *)(param_2 + 0x6c) + param_3 * 0x24;
  (**(code **)(*piVar1 + 0x30))(*(undefined4 *)(iVar2 + 0x1c));
  if (*(char *)(param_1 + 0x891) == '\0') {
    cVar3 = (**(code **)(*piVar1 + 0x10))
                      (*(undefined4 *)(*(int *)(param_1 + 8) + 0x10 + unaff_retaddr * 4),
                       iVar4 * iVar4,&stack0xfffffff4);
    if (cVar3 == '\0') {
      func_0x007647d0(0x9d2f20,0x98d1f0);
      return 0;
    }
  }
  else {
    unaff_EBP = iVar4 * iVar4;
    iVar4 = FUN_007a3b70();
    if (iVar4 == 0) {
      func_0x007647d0(0x9d2f20,0x98d230);
      return 0;
    }
    cVar3 = (**(code **)(*piVar1 + 0x10))(iVar4,*(undefined4 *)(iVar2 + 0x20),&stack0xfffffff4);
    if (cVar3 == '\0') {
      func_0x007647d0(0x9d2f20,0x98d1f0);
      return 0;
    }
    func_0x00771a40(iVar4,*(undefined4 *)(iVar2 + 0x20),unaff_EBP,&uStack_1c);
  }
  *(int *)(iStack_8 + unaff_EBX * 4) = unaff_EBP;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a2ce0 | Classified: elementclient::A3DTrn2SubLoaderB__BuildMaskText@0x7a2ce0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007a2ce0(int param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined4 *unaff_FS_OFFSET;
  int iVar13;
  int iStack_10;
  undefined4 *puStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd41b;
  puStack_c = (undefined4 *)*unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &puStack_c;
  iVar3 = func_0x00763250(0x3c);
  uStack_4 = 0;
  if (iVar3 == 0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)func_0x0078a330();
  }
  uStack_4 = 0xffffffff;
  if (puVar4 == (undefined4 *)0x0) {
    uVar5 = 0;
  }
  else {
    puVar6 = *(undefined1 **)(*(int *)(param_1 + 4) + 0x10);
    iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x24);
    cVar2 = func_0x0078a710(puVar6,iVar3,iVar3,0x15,1);
    puVar1 = puStack_c;
    if (cVar2 == '\0') {
      (**(code **)*puVar4)(1);
      func_0x007647d0(0x9d2f20,0x98d2b0);
      uVar5 = 0;
    }
    else {
      for (; iStack_10 < 3; iStack_10 = iStack_10 + 1) {
        puStack_c[iStack_10] = *(undefined4 *)(*(int *)(param_1 + 8) + 0x1c);
      }
      uVar5 = 0;
      cVar2 = func_0x0078a7e0(0,&stack0xffffffd8,&stack0xffffffdc,0);
      if (cVar2 == '\0') {
        (**(code **)*puVar4)(1);
        func_0x007647d0(0x9d2f20,0x98d270);
        uVar5 = 0;
      }
      else {
        puVar11 = (undefined1 *)*puVar1;
        puVar12 = (undefined1 *)puVar1[1];
        puVar10 = (undefined1 *)puVar1[2];
        iVar9 = *(int *)(*(int *)(param_1 + 8) + 0x24);
        iVar13 = 0;
        if (0 < iVar9) {
          do {
            puVar7 = puVar6 + iVar3;
            iVar8 = 0;
            if (0 < iVar9) {
              do {
                *puVar6 = *puVar11;
                puVar11 = puVar11 + 1;
                puVar6[1] = *puVar12;
                puVar12 = puVar12 + 1;
                puVar6[2] = *puVar10;
                puVar10 = puVar10 + 1;
                puVar6[3] = 0xff;
                puVar6 = puVar6 + 4;
                iVar8 = iVar8 + 1;
              } while (iVar8 < *(int *)(*(int *)(param_1 + 8) + 0x24));
            }
            iVar13 = iVar13 + 1;
            iVar9 = *(int *)(*(int *)(param_1 + 8) + 0x24);
            puVar6 = puVar7;
          } while (iVar13 < iVar9);
        }
        func_0x0078a850();
      }
    }
  }
  *unaff_FS_OFFSET = puStack_c;
  return uVar5;
}


/* ==================================================================== */
/* Address: 0x007a2e60 | Classified: elementclient::A3DTrn2SubLoaderB__LoadMaskMap__F@0x7a2e60 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __thiscall FUN_007a2e60(int param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar6;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  iStack_4 = -1;
  puStack_8 = &UNK_008cd43b;
  *unaff_FS_OFFSET = &uStack_c;
  piVar4 = (int *)0x0;
  if (param_3 == 0) goto LAB_007a302a;
  piVar4 = (int *)(param_1 + 0x22c);
  uVar6 = 0;
  iVar3 = *(int *)(param_2 + 0x6c);
  iVar1 = *(int *)(iVar3 + 8 + param_3 * 0x24);
  iVar5 = iVar3 + param_3 * 0x24;
  (**(code **)(*piVar4 + 0x30))(*(undefined4 *)(iVar3 + 0x1c + param_3 * 0x24),0);
  if (*(char *)(param_1 + 0x891) == '\0') {
    cVar2 = (**(code **)(*piVar4 + 0x10))
                      (*(undefined4 *)(*(int *)(param_1 + 8) + 0x10),iVar1 * iVar1,&stack0xffffffe4)
    ;
    if (cVar2 == '\0') {
      func_0x007647d0(0x9d2f20,0x98d370);
      piVar4 = (int *)0x0;
      goto LAB_007a302a;
    }
  }
  else {
    iStack_4 = iVar1 * iVar1;
    iVar3 = FUN_007a3b70();
    if (iVar3 == 0) {
      func_0x007647d0(0x9d2f20,0x98d3ac);
      piVar4 = (int *)0x0;
      goto LAB_007a302a;
    }
    cVar2 = (**(code **)(*piVar4 + 0x10))(iVar3,*(undefined4 *)(iVar5 + 0x20),&stack0xffffffe8);
    if (cVar2 == '\0') {
      func_0x007647d0(0x9d2f20,0x98d370);
      piVar4 = (int *)0x0;
      goto LAB_007a302a;
    }
    func_0x00771a40(uVar6,*(undefined4 *)(iVar5 + 0x20),uStack_c,&uStack_10);
  }
  iVar5 = func_0x00763250(0x3c);
  iStack_4 = 0;
  if (iVar5 == 0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)func_0x0078a330();
  }
  iStack_4 = 0xffffffff;
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    cVar2 = func_0x0078a710(*(undefined4 *)(*(int *)(param_1 + 4) + 0x10),iVar1,iVar1,
                            *(undefined4 *)(_DAT_009d30fc + 0x10),1);
    if (cVar2 == '\0') {
      (**(code **)*piVar4)(1);
      func_0x007647d0(0x9d2f20,0x98d330);
      piVar4 = (int *)0x0;
    }
    else {
      cVar2 = func_0x007dfaf0(iVar1,uStack_c,uStack_10,piVar4);
      if (cVar2 == '\0') {
        (**(code **)(*piVar4 + 0xc))();
        (**(code **)*piVar4)(1);
        func_0x007647d0(0x9d2f20,0x98d2f4);
        piVar4 = (int *)0x0;
      }
    }
  }
LAB_007a302a:
  *unaff_FS_OFFSET = uStack_c;
  return piVar4;
}


/* ==================================================================== */
/* Address: 0x007a3040 | Classified: elementclient::A3DTrn2SubLoaderB__LoadMaskLight@0x7a3040 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __thiscall FUN_007a3040(int param_1,int param_2,char param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd45b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_3 == '\0') {
    cVar1 = *(char *)(param_1 + 0x881);
  }
  else {
    cVar1 = *(char *)(param_1 + 0x880);
  }
  if (cVar1 == '\0') {
    piVar4 = (int *)0x0;
  }
  else {
    iVar2 = FUN_007a3e60(*(undefined4 *)(param_1 + 0x884),*(undefined4 *)(param_1 + 0x888));
    if (iVar2 == 0) {
      piVar4 = (int *)0x0;
    }
    else {
      if (param_3 == '\0') {
        piVar4 = (int *)(param_1 + 0x664);
        uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x8e8) + param_2 * 4);
      }
      else {
        piVar4 = (int *)(param_1 + 0x448);
        uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x8d4) + param_2 * 4);
      }
      (**(code **)(*piVar4 + 0x30))(uVar3,0);
      cVar1 = (**(code **)(*piVar4 + 0x10))(iVar2,*(undefined4 *)(param_1 + 0x888),&stack0xffffffe8)
      ;
      if (cVar1 == '\0') {
        func_0x007647d0(0x9d2f20,0x98d480);
        piVar4 = (int *)0x0;
      }
      else {
        iVar2 = func_0x00763250(0x3c);
        uStack_4 = 0;
        if (iVar2 == 0) {
          piVar4 = (int *)0x0;
        }
        else {
          piVar4 = (int *)func_0x0078a330();
        }
        uStack_4 = 0xffffffff;
        if (piVar4 == (int *)0x0) {
          piVar4 = (int *)0x0;
        }
        else {
          uVar3 = *(undefined4 *)(_DAT_009d30fc + 0x14);
          cVar1 = func_0x0078a710(*(undefined4 *)(*(int *)(param_1 + 4) + 0x10),
                                  *(undefined4 *)(param_1 + 0x884),*(undefined4 *)(param_1 + 0x884),
                                  uVar3,1);
          if (cVar1 == '\0') {
            (**(code **)*piVar4)(1);
            func_0x007647d0(0x9d2f20,0x98d430);
            piVar4 = (int *)0x0;
          }
          else {
            cVar1 = func_0x007df8b0(*(undefined4 *)(param_1 + 0x884),uStack_c,uVar3,piVar4);
            if (cVar1 == '\0') {
              (**(code **)(*piVar4 + 0xc))();
              (**(code **)*piVar4)(1);
              func_0x007647d0(0x9d2f20,0x98d3e8);
              piVar4 = (int *)0x0;
            }
          }
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return piVar4;
}


/* ==================================================================== */
/* Address: 0x007a31e0 | Classified: elementclient::A3DTrn2SubLoaderB__LoadMaskLight@0x7a31e0 */
/* ==================================================================== */

undefined4 * __thiscall FUN_007a31e0(int param_1,int param_2,char param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd47b;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_3 == '\0') {
    cVar1 = *(char *)(param_1 + 0x881);
  }
  else {
    cVar1 = *(char *)(param_1 + 0x880);
  }
  if (cVar1 == '\0') {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    iVar2 = FUN_007a3e60(*(undefined4 *)(param_1 + 0x884),*(undefined4 *)(param_1 + 0x888));
    if (iVar2 == 0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      if (param_3 == '\0') {
        piVar6 = (int *)(param_1 + 0x664);
        uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x8e8) + param_2 * 4);
      }
      else {
        piVar6 = (int *)(param_1 + 0x448);
        uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x8d4) + param_2 * 4);
      }
      (**(code **)(*piVar6 + 0x30))(uVar3,0);
      cVar1 = (**(code **)(*piVar6 + 0x10))(iVar2,*(undefined4 *)(param_1 + 0x888),&stack0x00000000)
      ;
      if (cVar1 == '\0') {
        func_0x007647d0(0x9d2f20,0x98d518);
        puVar4 = (undefined4 *)0x0;
      }
      else {
        iVar5 = func_0x00763250(0x3c);
        uStack_4 = 0;
        if (iVar5 == 0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          puVar4 = (undefined4 *)func_0x0078a330();
        }
        uStack_4 = 0xffffffff;
        if (puVar4 == (undefined4 *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          cVar1 = func_0x0078b790(*(undefined4 *)(*(int *)(param_1 + 4) + 0x10),iVar2,
                                  *(undefined4 *)(param_1 + 0x888),0,0,0,1,0);
          if (cVar1 == '\0') {
            (**(code **)*puVar4)(1);
            func_0x007647d0(0x9d2f20,0x98d4c8);
            puVar4 = (undefined4 *)0x0;
          }
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return puVar4;
}


/* ==================================================================== */
/* Address: 0x007a3340 | Classified: Angelica3D::proc_7a3340 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a3340(int param_1,int param_2)

{
  if ((*(char *)(param_1 + 0x89c) != '\0') && (*(int *)(param_1 + 0x8a0) == 0)) {
    *(int *)(param_1 + 0x8a4) = *(int *)(param_1 + 0x8a4) + param_2;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a3370 | Classified: Angelica3D::proc_7a3370 */
/* ==================================================================== */

void __fastcall FUN_007a3370(int param_1)

{
  if (((*(char *)(param_1 + 0x89c) != '\0') && (*(int *)(param_1 + 0x8a0) == 0)) &&
     (9999 < *(uint *)(param_1 + 0x8a4))) {
    FUN_007a1010(0);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007a33a0 | Classified: Angelica3D::proc_7a33a0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_007a33a0(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = &UNK_008eb174;
  param_1[1] = param_2;
  param_1[2] = 1;
  param_1[0x11] = _DAT_009858e4;
  param_1[0x13] = &UNK_008d5a30;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0x10;
  param_1[0x12] = &UNK_008e7a74;
  param_1[0x1d] = 0x10;
  param_1[0x19] = &UNK_008d5a30;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x18] = &UNK_008f1888;
  *param_1 = &UNK_008f1868;
  param_1[3] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007a3430 | Classified: Angelica3D::proc_7a3430 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a3430(undefined4 param_1,byte param_2)

{
  FUN_007a3450();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007a3450 | Classified: Angelica3D::proc_7a3450 */
/* ==================================================================== */

void __fastcall FUN_007a3450(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  puStack_8 = &UNK_008cd4ae;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f1868;
  param_1[0x18] = &UNK_008f1888;
  iStack_4 = 2;
  param_1[0x19] = &UNK_008d5a30;
  if (param_1[0x1a] != 0) {
    func_0x00763260(param_1[0x1a]);
    param_1[0x1a] = 0;
  }
  param_1[0x1c] = 0;
  param_1[0x1b] = 0;
  param_1[0x12] = &UNK_008e7a74;
  iStack_4._0_1_ = 1;
  param_1[0x13] = &UNK_008d5a30;
  if (param_1[0x14] != 0) {
    func_0x00763260(param_1[0x14]);
    param_1[0x14] = 0;
  }
  param_1[0x16] = 0;
  param_1[0x15] = 0;
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  func_0x007637f0();
  *param_1 = &UNK_008eb174;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x007a3500 | Classified: elementclient::AArray__SetSize__Not_enough_memo@0x7a3500 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a3500(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  func_0x0076ef80(param_2,param_1 + 0x44);
  func_0x00763aa0(0x9510b0);
  uVar2 = FUN_007a3760(param_2);
  if ((char)uVar2 == '\0') {
    return uVar2;
  }
  uVar2 = FUN_007a3970();
  if ((char)uVar2 == '\0') {
    return uVar2;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x3ec);
  *(undefined4 *)(param_1 + 0x74) = 10;
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x68) != 0) {
      func_0x00763260(*(int *)(param_1 + 0x68));
      *(undefined4 *)(param_1 + 0x68) = 0;
    }
    *(undefined4 *)(param_1 + 0x70) = 0;
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  else {
    if (*(int *)(param_1 + 0x70) < iVar1) {
      iVar4 = func_0x00763250(iVar1 * 4);
      if (iVar4 == 0) {
        func_0x00764590(1,0x9505a4);
        goto LAB_007a35e3;
      }
      if (*(int *)(param_1 + 0x68) != 0) {
        iVar5 = *(int *)(param_1 + 0x6c);
        if (iVar1 <= *(int *)(param_1 + 0x6c)) {
          iVar5 = iVar1;
        }
        iVar3 = 0;
        if (0 < iVar5) {
          do {
            iVar3 = iVar3 + 1;
            *(undefined4 *)(iVar4 + -4 + iVar3 * 4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x68) + -4 + iVar3 * 4);
          } while (iVar3 < iVar5);
        }
        func_0x00763260(*(undefined4 *)(param_1 + 0x68));
      }
      *(int *)(param_1 + 0x70) = iVar1;
      *(int *)(param_1 + 0x68) = iVar4;
    }
    *(int *)(param_1 + 0x6c) = iVar1;
  }
LAB_007a35e3:
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      iVar4 = iVar4 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x68) + -4 + iVar4 * 4) = 0;
    } while (iVar4 < iVar1);
  }
  return CONCAT31((int3)((uint)iVar4 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007a3760 | Classified: elementclient::A3DTerrain2LoaderB__LoadDescript@0x7a3760 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_007a3760(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  int iVar7;
  undefined1 *puStack_2d8;
  undefined4 uStack_2d4;
  undefined4 uStack_2d0;
  undefined4 uStack_2cc;
  undefined4 uStack_2c8;
  int iStack_2b0;
  undefined4 uStack_280;
  undefined4 uStack_14;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd4cb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_2c8 = 0x7a378c;
  func_0x0076e410();
  uStack_2c8 = 0x11;
  uStack_2cc = param_2;
  uStack_4 = 0;
  uStack_2d0 = 0x7a37ab;
  cVar1 = func_0x0076e470();
  if (cVar1 == '\0') {
    uStack_2d0 = param_2;
    uStack_2d4 = 0x98d5b0;
    puStack_2d8 = (undefined1 *)0x9d2f20;
    func_0x007647d0();
  }
  else {
    uStack_2d0 = 0;
    uStack_2d4 = 8;
    puStack_2d8 = (undefined1 *)0x7a37d3;
    func_0x0076e950();
    puStack_2d8 = &stack0xfffffd40;
    func_0x0076e6a0(&stack0xfffffd44,0x84);
    func_0x0076e950(uStack_280);
    cVar1 = func_0x0076e6a0(&puStack_2d8,4,&uStack_2d4);
    if (cVar1 != '\0') {
      *(undefined4 *)(param_1 + 0x24) = 0;
      *(undefined4 *)(param_1 + 0x24) = 0x20;
      iVar7 = 0;
      if (0 < iStack_2b0) {
        do {
          puVar3 = (undefined4 *)func_0x00763250(4);
          if (puVar3 == (undefined4 *)0x0) {
            puVar3 = (undefined4 *)0x0;
          }
          else {
            *puVar3 = _DAT_009858e4;
          }
          func_0x0076e890(puVar3);
          if ((*(int *)(param_1 + 0x58) <= *(int *)(param_1 + 0x54)) &&
             (*(int *)(param_1 + 0x5c) != 0)) {
            iVar6 = *(int *)(param_1 + 0x5c) + *(int *)(param_1 + 0x58);
            iVar4 = func_0x00763250(iVar6 * 4);
            if (iVar4 == 0) {
              func_0x00764590(1,0x94e51c);
            }
            else {
              iVar5 = 0;
              if (0 < *(int *)(param_1 + 0x54)) {
                do {
                  iVar5 = iVar5 + 1;
                  *(undefined4 *)(iVar4 + -4 + iVar5 * 4) =
                       *(undefined4 *)(*(int *)(param_1 + 0x50) + -4 + iVar5 * 4);
                } while (iVar5 < *(int *)(param_1 + 0x54));
              }
              if (*(int *)(param_1 + 0x50) != 0) {
                func_0x00763260(*(int *)(param_1 + 0x50));
              }
              *(int *)(param_1 + 0x50) = iVar4;
              *(int *)(param_1 + 0x58) = iVar6;
            }
          }
          *(undefined4 **)(*(int *)(param_1 + 0x50) + *(int *)(param_1 + 0x54) * 4) = puVar3;
          iVar7 = iVar7 + 1;
          *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
        } while (iVar7 < iStack_2b0);
      }
      func_0x0076e670();
      func_0x0076e460();
      uVar2 = 1;
      goto LAB_007a394f;
    }
    func_0x007647d0(0x9d2f20,0x98d568);
  }
  uStack_c = 0xffffffff;
  uStack_2d0 = 0x7a3845;
  func_0x0076e460();
  uVar2 = 0;
LAB_007a394f:
  *unaff_FS_OFFSET = uStack_14;
  return uVar2;
}


/* ==================================================================== */
/* Address: 0x007a3970 | Classified: elementclient::A3DTerrain2LoaderB__CreateMaskBu@0x7a3970 */
/* ==================================================================== */

uint __fastcall FUN_007a3970(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  
  iVar4 = 0;
  piVar5 = (int *)(param_1 + 0x10);
  do {
    iVar1 = func_0x007631a0(*(int *)(param_1 + 0x24) * *(int *)(param_1 + 0x24));
    *piVar5 = iVar1;
    if (iVar1 == 0) {
      uVar3 = func_0x007647d0(0x9d2f20,0x98d5f0);
      return uVar3 & 0xffffff00;
    }
    iVar4 = iVar4 + 1;
    piVar5 = piVar5 + 1;
  } while (iVar4 < 5);
  uVar2 = *(int *)(param_1 + 0x24) * *(int *)(param_1 + 0x24);
  puVar6 = *(undefined4 **)(param_1 + 0x1c);
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar6 = 0;
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  uVar2 = *(int *)(param_1 + 0x24) * *(int *)(param_1 + 0x24);
  puVar6 = *(undefined4 **)(param_1 + 0x20);
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar6 = 0xffffffff;
    puVar6 = puVar6 + 1;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar6 = 0xff;
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  return 0xffffff01;
}


/* ==================================================================== */
/* Address: 0x007a39f0 | Classified: elementclient::A3DTerrain2LoaderB__GetBlockTemp@0x7a39f0 */
/* ==================================================================== */

undefined4 __thiscall
FUN_007a39f0(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5,undefined4 *param_6)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x1d0) + 1;
  iVar2 = iVar2 * iVar2;
  if (param_2 != (undefined4 *)0x0) {
    if (*(int *)(param_1 + 0x2c) == 0) {
      iVar1 = func_0x007631a0(iVar2 * 8);
      *(int *)(param_1 + 0x2c) = iVar1;
      if (iVar1 == 0) {
        func_0x007647d0(0x9d2f20,0x98d62c);
        return 0;
      }
    }
    *param_2 = *(undefined4 *)(param_1 + 0x2c);
  }
  if (param_3 != (undefined4 *)0x0) {
    if (*(int *)(param_1 + 0x30) == 0) {
      iVar1 = func_0x007631a0(iVar2 * 0x18);
      *(int *)(param_1 + 0x30) = iVar1;
      if (iVar1 == 0) {
        func_0x007647d0(0x9d2f20,0x98d62c);
        return 0;
      }
    }
    *param_3 = *(undefined4 *)(param_1 + 0x30);
  }
  if (param_4 != (undefined4 *)0x0) {
    if (*(int *)(param_1 + 0x3c) == 0) {
      iVar1 = func_0x007631a0(iVar2 * 8);
      *(int *)(param_1 + 0x3c) = iVar1;
      if (iVar1 == 0) {
        func_0x007647d0(0x9d2f20,0x98d62c);
        return 0;
      }
    }
    *param_4 = *(undefined4 *)(param_1 + 0x3c);
  }
  if (param_5 != (undefined4 *)0x0) {
    if (*(int *)(param_1 + 0x34) == 0) {
      iVar1 = func_0x007631a0(iVar2 * 4);
      *(int *)(param_1 + 0x34) = iVar1;
      if (iVar1 == 0) {
        func_0x007647d0(0x9d2f20,0x98d62c);
        return 0;
      }
    }
    *param_5 = *(undefined4 *)(param_1 + 0x34);
  }
  if (param_6 != (undefined4 *)0x0) {
    if (*(int *)(param_1 + 0x38) == 0) {
      iVar2 = func_0x007631a0(iVar2 * 0xc);
      *(int *)(param_1 + 0x38) = iVar2;
      if (iVar2 == 0) {
        func_0x007647d0(0x9d2f20,0x98d62c);
        return 0;
      }
    }
    *param_6 = *(undefined4 *)(param_1 + 0x38);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a3b70 | Classified: elementclient::A3DTerrain2LoaderB__GetMaskMapTe@0x7a3b70 */
/* ==================================================================== */

int __fastcall FUN_007a3b70(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  if (iVar1 == 0) {
    iVar1 = func_0x007631a0(*(int *)(param_1 + 0x24) * *(int *)(param_1 + 0x24) * 2);
    *(int *)(param_1 + 0x40) = iVar1;
    if (iVar1 == 0) {
      func_0x007647d0(0x9d2f20,0x98d66c);
      iVar1 = 0;
    }
  }
  return iVar1;
}


/* ==================================================================== */
/* Address: 0x007a3bb0 | Classified: Angelica3D::proc_7a3bb0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a3bb0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 unaff_EBX;
  undefined4 *puVar4;
  int iVar5;
  int *unaff_FS_OFFSET;
  int iStack_1c;
  int iStack_18;
  undefined4 *puStack_14;
  int iStack_10;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd4f3;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  iVar5 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(iVar5 + 0x1d8) / *(int *)(iVar5 + 0x1d0);
  iStack_1c = param_2 / iVar2;
  iStack_18 = param_2 % iVar2;
  iStack_10 = param_3 % iVar2;
  iVar5 = (*(int *)(iVar5 + 0x188) / iVar2) * iStack_1c + param_3 / iVar2;
  if (*(int *)(*(int *)(param_1 + 0x68) + iVar5 * 4) == 0) {
    puStack_14 = (undefined4 *)func_0x00763250(0x90c);
    puVar4 = (undefined4 *)0x0;
    uStack_4 = 0;
    if (puStack_14 != (undefined4 *)0x0) {
      puVar4 = (undefined4 *)func_0x007a0a90(param_1);
    }
    uStack_4 = 0xffffffff;
    puStack_14 = puVar4;
    func_0x005145b0(&iStack_1c,param_1 + 0x44,*(undefined4 *)(*(int *)(param_1 + 0x50) + iVar5 * 4))
    ;
    uStack_4 = 1;
    cVar1 = FUN_007a0dc0(iStack_1c);
    if (cVar1 == '\0') {
      if (puVar4 != (undefined4 *)0x0) {
        (**(code **)*puVar4)(1);
      }
      puStack_8 = (undefined *)0xffffffff;
      func_0x007637f0();
      uVar3 = 0;
      goto LAB_007a3d0f;
    }
    puStack_8 = (undefined *)0xffffffff;
    *(undefined4 *)(*(int *)(param_1 + 0x68) + iVar5 * 4) = unaff_EBX;
    func_0x007637f0();
  }
  iVar5 = *(int *)(param_1 + 4);
  puStack_14 = (undefined4 *)
               ((float)param_3 * *(float *)(iVar5 + 0x1c4) + *(float *)(iVar5 + 0x1e4));
  uVar3 = FUN_007a1b70(iStack_18 * iVar2 + iStack_10,puStack_14,
                       *(float *)(iVar5 + 0x1e8) - (float)param_2 * *(float *)(iVar5 + 0x1c4));
LAB_007a3d0f:
  *unaff_FS_OFFSET = iStack_10;
  return uVar3;
}


/* ==================================================================== */
/* Address: 0x007a3de0 | Classified: Angelica3D::proc_7a3de0 */
/* ==================================================================== */

void __thiscall FUN_007a3de0(int param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar4 = *(int *)(iVar1 + 0x1d0) * *(int *)(iVar1 + 0x188);
  iVar2 = iVar4 / *(int *)(iVar1 + 0x1d4);
  iVar3 = param_2 / iVar2;
  param_2 = param_2 % iVar2;
  iVar2 = *(int *)(iVar1 + 0x1d8) / *(int *)(iVar1 + 0x1d4);
  *param_3 = (iVar4 / *(int *)(iVar1 + 0x1d8)) * (iVar3 / iVar2) + param_2 / iVar2;
  *param_4 = (iVar3 % iVar2) * iVar2 + param_2 % iVar2;
  return;
}


/* ==================================================================== */
/* Address: 0x007a3e60 | Classified: elementclient::A3DTerrain2LoaderB__GetLMLoadBuf@0x7a3e60 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a3e60(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar1 = func_0x00763250(param_3);
    *(int *)(param_1 + 0xc) = iVar1;
    if (iVar1 == 0) {
      func_0x007647d0(0x9d2f20,0x98d6ac);
      return 0;
    }
    *(undefined4 *)(param_1 + 0x28) = param_2;
  }
  return *(undefined4 *)(param_1 + 0xc);
}


/* ==================================================================== */
/* Address: 0x007a3eb0 | Classified: Angelica3D::proc_7a3eb0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a3eb0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = *(int *)(param_1 + 0x6c);
  if (0 < iVar1) {
    do {
      if (*(int *)(*(int *)(param_1 + 0x68) + iVar2 * 4) != 0) {
        FUN_007a3340(param_2);
      }
      iVar1 = *(int *)(param_1 + 0x6c);
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007a3ef0 | Classified: Angelica3D::proc_7a3ef0 */
/* ==================================================================== */

void __fastcall FUN_007a3ef0(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x6c)) {
    do {
      if (*(int *)(*(int *)(param_1 + 0x68) + iVar1 * 4) != 0) {
        FUN_007a3370();
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x6c));
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007a3f20 | Classified: Angelica3D::proc_7a3f20 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a3f20(undefined4 param_1,byte param_2)

{
  FUN_007a3f40();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007a3f40 | Classified: Angelica3D::proc_7a3f40 */
/* ==================================================================== */

void __fastcall FUN_007a3f40(undefined4 *param_1)

{
  *param_1 = &UNK_008f1888;
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
/* Address: 0x007a3f70 | Classified: Angelica3D::proc_7a3f70 */
/* ==================================================================== */

void __fastcall FUN_007a3f70(undefined4 *param_1)

{
  *param_1 = &UNK_008eb174;
  return;
}


/* ==================================================================== */
/* Address: 0x007a3f80 | Classified: Angelica3D::proc_7a3f80 */
/* ==================================================================== */

undefined4 * __thiscall FUN_007a3f80(undefined4 *param_1,byte param_2)

{
  *param_1 = &UNK_008f1864;
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
/* Address: 0x007a3fd0 | Classified: Angelica3D::proc_7a3fd0 */
/* ==================================================================== */

void __fastcall FUN_007a3fd0(undefined4 *param_1)

{
  param_1[8] = &UNK_008f18a4;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0x10;
  param_1[0xe] = &UNK_008d5a30;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0x10;
  param_1[0xd] = &UNK_008f0a44;
  *param_1 = &UNK_008f188c;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 7) = 1;
  return;
}


/* ==================================================================== */
/* Address: 0x007a4030 | Classified: Angelica3D::proc_7a4030 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a4030(undefined4 param_1,byte param_2)

{
  FUN_007a4050();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007a4050 | Classified: Angelica3D::proc_7a4050 */
/* ==================================================================== */

void __fastcall FUN_007a4050(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008cd50b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f188c;
  param_1[0xd] = &UNK_008f0a44;
  param_1[0xe] = &UNK_008d5a30;
  uStack_4 = 0;
  if (param_1[0xf] != 0) {
    func_0x00763260(param_1[0xf]);
    param_1[0xf] = 0;
  }
  param_1[0x11] = 0;
  param_1[0x10] = 0;
  uStack_4 = 0xffffffff;
  param_1[8] = &UNK_008f18a4;
  if (param_1[9] != 0) {
    func_0x00763260(param_1[9]);
    param_1[9] = 0;
  }
  param_1[0xb] = 0;
  param_1[10] = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x007a40e0 | Classified: elementclient::A3DTerrain2CullHC__Init__Failed_t@0x7a40e0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a40e0(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd52b;
  *unaff_FS_OFFSET = &uStack_c;
  cVar1 = FUN_007a4280();
  if (cVar1 == '\0') {
    func_0x007647d0(0x9d2f20,0x98d75c,param_2);
    *unaff_FS_OFFSET = unaff_ESI;
    return 0;
  }
  iVar2 = func_0x00763250(0x28);
  puStack_8 = (undefined *)0x0;
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = func_0x007dfe50();
  }
  puStack_8 = (undefined *)0xffffffff;
  *(int *)(param_1 + 8) = iVar2;
  if (iVar2 == 0) {
    *unaff_FS_OFFSET = unaff_ESI;
    return 0;
  }
  cVar1 = func_0x007dfeb0(800,600);
  if (cVar1 == '\0') {
    if (*(int *)(param_1 + 0x24) != 0) {
      func_0x00763260(*(int *)(param_1 + 0x24));
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    if (*(int *)(param_1 + 8) != 0) {
      func_0x007dffb0();
      if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(param_1 + 8))(1);
      }
      *(undefined4 *)(param_1 + 8) = 0;
    }
    func_0x007647d0(0x9d2f20,0x98d71c);
    *unaff_FS_OFFSET = param_2;
    return 0;
  }
  iVar2 = *(int *)(param_1 + 0x28) + 7 >> 3;
  *(int *)(param_1 + 0x10) = iVar2;
  iVar2 = func_0x00763250(iVar2);
  *(int *)(param_1 + 0xc) = iVar2;
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x24) != 0) {
      func_0x00763260(*(int *)(param_1 + 0x24));
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    if (*(int *)(param_1 + 8) != 0) {
      func_0x007dffb0();
      if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(param_1 + 8))(1);
      }
      *(undefined4 *)(param_1 + 8) = 0;
    }
    func_0x007647d0(0x9d2f20,0x98d6e4);
    *unaff_FS_OFFSET = param_2;
    return 0;
  }
  *unaff_FS_OFFSET = param_2;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a4280 | Classified: elementclient::A3DTerrain2CullHC__LoadHorizonCu@0x7a4280 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a4280(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  int unaff_EDI;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined1 *puStack_274;
  undefined4 uStack_270;
  undefined4 *puStack_26c;
  undefined1 *puStack_268;
  undefined4 uStack_264;
  undefined1 *puStack_260;
  undefined4 uStack_25c;
  uint uStack_258;
  undefined1 auStack_23c [516];
  undefined4 uStack_38;
  undefined4 uStack_30;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd54b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_258 = 0x7a42a9;
  func_0x0076e410();
  uStack_258 = 0x11;
  uStack_25c = param_2;
  uStack_4 = 0;
  puStack_260 = (undefined1 *)0x7a42c5;
  cVar3 = func_0x0076e470();
  if (cVar3 == '\0') {
    puStack_260 = (undefined1 *)param_2;
    uStack_264 = 0x98d7d4;
    puStack_268 = (undefined1 *)0x9d2f20;
    puStack_26c = (undefined4 *)0x7a42d9;
    func_0x007647d0();
  }
  else {
    puStack_260 = &stack0xfffffdb0;
    puStack_268 = auStack_23c;
    uStack_264 = 4;
    puStack_26c = (undefined4 *)0x7a42f6;
    func_0x0076e6a0();
    puStack_26c = &uStack_25c;
    puStack_274 = &stack0xfffffdb4;
    uStack_270 = 4;
    func_0x0076e6a0();
    if ((unaff_EDI == 0x54324843) && (uStack_258 < 2)) {
      cVar3 = func_0x0076e6a0(&uStack_264,0xc,&puStack_268);
      puVar2 = puStack_268;
      if (cVar3 != '\0') {
        *(undefined4 *)(param_1 + 0x14) = uStack_270;
        *(undefined4 **)(param_1 + 0x18) = puStack_26c;
        *(undefined4 *)(param_1 + 0x30) = 10;
        if (puStack_268 == (undefined1 *)0x0) {
          if (*(int *)(param_1 + 0x24) != 0) {
            func_0x00763260(*(int *)(param_1 + 0x24));
            *(undefined4 *)(param_1 + 0x24) = 0;
          }
          *(undefined4 *)(param_1 + 0x2c) = 0;
          *(undefined4 *)(param_1 + 0x28) = 0;
        }
        else if (*(int *)(param_1 + 0x2c) < (int)puStack_268) {
          iVar7 = func_0x00763250((int)puStack_268 * 8);
          if (iVar7 == 0) {
            func_0x00764590(1,0x9505a4);
          }
          else {
            if (*(int *)(param_1 + 0x24) != 0) {
              puVar6 = *(undefined1 **)(param_1 + 0x28);
              if ((int)puVar2 <= (int)*(undefined1 **)(param_1 + 0x28)) {
                puVar6 = puVar2;
              }
              iVar4 = 0;
              if (0 < (int)puVar6) {
                do {
                  iVar1 = *(int *)(param_1 + 0x24);
                  iVar4 = iVar4 + 1;
                  *(undefined4 *)(iVar7 + -8 + iVar4 * 8) = *(undefined4 *)(iVar1 + -8 + iVar4 * 8);
                  *(undefined4 *)(iVar7 + -4 + iVar4 * 8) = *(undefined4 *)(iVar1 + -4 + iVar4 * 8);
                } while (iVar4 < (int)puVar6);
              }
              func_0x00763260(*(undefined4 *)(param_1 + 0x24));
            }
            *(undefined1 **)(param_1 + 0x28) = puVar2;
            *(undefined1 **)(param_1 + 0x2c) = puVar2;
            *(int *)(param_1 + 0x24) = iVar7;
          }
        }
        else {
          *(undefined1 **)(param_1 + 0x28) = puStack_268;
        }
        iVar7 = 0;
        if (0 < (int)puStack_268) {
          do {
            cVar3 = func_0x0076e6a0(&uStack_25c,8,&puStack_274);
            if (cVar3 == '\0') {
              if (*(int *)(param_1 + 0x24) != 0) {
                func_0x00763260(*(int *)(param_1 + 0x24));
                *(undefined4 *)(param_1 + 0x24) = 0;
              }
              *(undefined4 *)(param_1 + 0x2c) = 0;
              *(undefined4 *)(param_1 + 0x28) = 0;
              func_0x0076e670();
              goto LAB_007a449f;
            }
            iVar1 = *(int *)(param_1 + 0x24);
            *(undefined4 *)(iVar1 + iVar7 * 8) = uStack_25c;
            iVar4 = iVar7 * 8;
            iVar7 = iVar7 + 1;
            *(uint *)(iVar1 + iVar4 + 4) = uStack_258;
          } while (iVar7 < (int)puStack_268);
        }
        func_0x0076e670();
        uStack_30 = 0xffffffff;
        func_0x0076e460();
        uVar5 = 1;
        goto LAB_007a44b5;
      }
      func_0x0076e670();
    }
    else {
      func_0x0076e670();
      func_0x007647d0(0x9d2f20,0x98d790);
    }
  }
LAB_007a449f:
  uStack_c = 0xffffffff;
  puStack_260 = (undefined1 *)0x7a44b3;
  func_0x0076e460();
  uVar5 = 0;
LAB_007a44b5:
  *unaff_FS_OFFSET = uStack_38;
  return uVar5;
}


/* ==================================================================== */
/* Address: 0x007a44d0 | Classified: Angelica3D::proc_7a44d0 */
/* ==================================================================== */

void __fastcall FUN_007a44d0(int param_1)

{
  if (*(int *)(param_1 + 8) != 0) {
    func_0x007dffb0();
    if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 8))(1);
    }
    *(undefined4 *)(param_1 + 8) = 0;
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x24));
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    func_0x00763260(*(int *)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007a4530 | Classified: Angelica3D::proc_7a4530 */
/* ==================================================================== */

undefined4 __thiscall FUN_007a4530(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007a4540 | Classified: Angelica3D::proc_7a4540 */
/* ==================================================================== */

uint __thiscall FUN_007a4540(int param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar1 = CONCAT31((int3)((uint)in_EAX >> 8),*(char *)(param_1 + 0x1c));
  if ((((*(char *)(param_1 + 0x1c) != '\0') && (uVar1 = *(uint *)(param_1 + 4), uVar1 != 0)) &&
      (*(int *)(param_1 + 8) != 0)) &&
     ((*(int *)(param_1 + 0x18) == *(int *)(uVar1 + 0x188) &&
      (*(int *)(param_1 + 0x14) == *(int *)(uVar1 + 0x184))))) {
    uVar1 = func_0x007e0010(param_2);
    if ((char)uVar1 != '\0') {
      uVar1 = *(uint *)(param_1 + 0x10);
      puVar3 = *(undefined4 **)(param_1 + 0xc);
      for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
      }
      for (uVar1 = uVar1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
        *(undefined1 *)puVar3 = 0;
        puVar3 = (undefined4 *)((int)puVar3 + 1);
      }
      return 1;
    }
  }
  return uVar1 & 0xffffff00;
}


