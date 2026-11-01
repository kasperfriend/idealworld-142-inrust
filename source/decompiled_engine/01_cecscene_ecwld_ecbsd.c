/* Authentic Ghidra 12.1.4 Decompilation — elementclient.exe (PW 1.4.2 Build 2305) */
/* Module: 01_cecscene_ecwld_ecbsd.c */

/* ==================================================================== */
/* Address: 0x0041b560 | Classified: CECScene::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0041b560(undefined4 param_1,byte param_2)

{
  FUN_0041b5c0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0041b580 | Classified: ElementClient::proc_41b580 */
/* ==================================================================== */

void __fastcall FUN_0041b580(int param_1)

{
  *(undefined **)(param_1 + 0x10) = &UNK_008d67ec;
  *(undefined **)(param_1 + 0x14) = &UNK_008d5a30;
  if (*(int *)(param_1 + 0x18) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x0041b5b0 | Classified: ElementClient::proc_41b5b0 */
/* ==================================================================== */

undefined4 __fastcall FUN_0041b5b0(undefined4 param_1)

{
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0041b5c0 | Classified: ElementClient::proc_41b5c0 */
/* ==================================================================== */

void __fastcall FUN_0041b5c0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008a72b7;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008d67c4;
  param_1[0x237] = &UNK_008d67cc;
  uStack_4 = 0xd;
  param_1[0x238] = &UNK_008d5a30;
  func_0x004acc40(1);
  param_1[0x231] = &UNK_008d67d4;
  puStack_8 = (undefined *)CONCAT31(puStack_8._1_3_,0xc);
  param_1[0x232] = &UNK_008d5a30;
  func_0x004acc40();
  param_1[0x22b] = &UNK_008d67dc;
  uStack_c._0_1_ = 0xb;
  param_1[0x22c] = &UNK_008d5a30;
  if (param_1[0x22d] != 0) {
    func_0x00763260(param_1[0x22d]);
    param_1[0x22d] = 0;
  }
  param_1[0x22f] = 0;
  param_1[0x22e] = 0;
  uStack_c = CONCAT31(uStack_c._1_3_,10);
  param_1[0x224] = &UNK_008d67e4;
  func_0x00421ca0();
  puVar1 = (undefined4 *)param_1[0x22a];
  while (puVar1 != (undefined4 *)0x0) {
    param_1[0x22a] = puVar1[1];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    puVar1 = (undefined4 *)param_1[0x22a];
  }
  uStack_c._1_3_ = (undefined3)((uint)uStack_c >> 8);
  uStack_c = CONCAT31(uStack_c._1_3_,9);
  param_1[0x21f] = &UNK_008d651c;
  func_0x004acc40(1);
  param_1[0x145] = &UNK_008d67ec;
  param_1[0x146] = &UNK_008d5a30;
  func_0x004acc40(1);
  param_1[0x13b] = &UNK_008d67ec;
  param_1[0x13c] = &UNK_008d5a30;
  func_0x004acc40(1);
  func_0x0076e460();
  func_0x0076e460();
  func_0x005b5b60();
  func_0x006e04e0(param_1[0x22],param_1[0x22] + param_1[0x25] * 4);
  if (param_1[0x22] != 0) {
    func_0x00763260(param_1[0x22]);
  }
  func_0x005b5b60();
  func_0x005b5c40();
  if (param_1[0x1c] != 0) {
    func_0x00763260(param_1[0x1c]);
  }
  func_0x005b5b60();
  func_0x005b5c40();
  if (param_1[0x16] != 0) {
    func_0x00763260(param_1[0x16]);
  }
  func_0x005b5b60();
  func_0x005b5c40();
  if (param_1[0x10] != 0) {
    func_0x00763260(param_1[0x10]);
  }
  func_0x005b5b60();
  func_0x005b5c40();
  if (param_1[10] != 0) {
    func_0x00763260(param_1[10]);
  }
  func_0x005b5b60();
  func_0x004060e0();
  *unaff_FS_OFFSET = 1;
  return;
}


/* ==================================================================== */
/* Address: 0x0041b860 | Classified: ElementClient::proc_41b860 */
/* ==================================================================== */

void __fastcall FUN_0041b860(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  
  FUN_0041cde0();
  iVar5 = 0;
  if (0 < *(int *)(param_1 + 0x8b8)) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x8b4) + iVar5 * 4);
      if (iVar1 != 0) {
        FUN_0041bad0();
        func_0x00763260(iVar1);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(param_1 + 0x8b8));
  }
  iVar5 = 0;
  if (0 < *(int *)(param_1 + 0x8d0)) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x8cc) + iVar5 * 4);
      if (iVar1 != 0) {
        FUN_0041bb20();
        func_0x00763260(iVar1);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(param_1 + 0x8d0));
  }
  func_0x004acc40(1);
  func_0x004acc40(1);
  iVar5 = 0;
  if (0 < *(int *)(param_1 + 0x8e8)) {
    do {
      piVar2 = *(int **)(*(int *)(param_1 + 0x8e4) + iVar5 * 4);
      if ((int *)*piVar2 != (int *)0x0) {
        (**(code **)(*(int *)*piVar2 + 0xc))();
        if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)*piVar2)(1);
        }
        func_0x00763260(piVar2[3]);
      }
      if (piVar2 != (int *)0x0) {
        func_0x00426660();
        func_0x00763260(piVar2);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(param_1 + 0x8e8));
  }
  if (*(int *)(param_1 + 0x8e4) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x8e4));
    *(undefined4 *)(param_1 + 0x8e4) = 0;
  }
  *(undefined4 *)(param_1 + 0x8ec) = 0;
  *(undefined4 *)(param_1 + 0x8e8) = 0;
  (**(code **)(*(int *)(param_1 + 0x98) + 0xc))();
  (**(code **)(*(int *)(param_1 + 0x2b4) + 0xc))();
  if (*(int *)(param_1 + 0x880) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x880));
    *(undefined4 *)(param_1 + 0x880) = 0;
  }
  *(undefined4 *)(param_1 + 0x888) = 0;
  *(undefined4 *)(param_1 + 0x884) = 0;
  uVar6 = 0;
  if (*(int *)(param_1 + 0x1c) != 0) {
    do {
      puVar4 = *(undefined4 **)(*(int *)(param_1 + 0x10) + uVar6 * 4);
      while (puVar4 != (undefined4 *)0x0) {
        puVar3 = (undefined4 *)*puVar4;
        func_0x00763260(puVar4);
        puVar4 = puVar3;
      }
      uVar6 = uVar6 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x10) + -4 + uVar6 * 4) = 0;
    } while (uVar6 < *(uint *)(param_1 + 0x1c));
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  uVar6 = 0;
  if (*(int *)(param_1 + 0x34) != 0) {
    do {
      puVar4 = *(undefined4 **)(*(int *)(param_1 + 0x28) + uVar6 * 4);
      while (puVar4 != (undefined4 *)0x0) {
        puVar3 = (undefined4 *)*puVar4;
        func_0x00763260(puVar4);
        puVar4 = puVar3;
      }
      uVar6 = uVar6 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x28) + -4 + uVar6 * 4) = 0;
    } while (uVar6 < *(uint *)(param_1 + 0x34));
  }
  *(undefined4 *)(param_1 + 0x24) = 0;
  uVar6 = 0;
  if (*(int *)(param_1 + 0x4c) != 0) {
    do {
      puVar4 = *(undefined4 **)(*(int *)(param_1 + 0x40) + uVar6 * 4);
      while (puVar4 != (undefined4 *)0x0) {
        puVar3 = (undefined4 *)*puVar4;
        func_0x00763260(puVar4);
        puVar4 = puVar3;
      }
      uVar6 = uVar6 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x40) + -4 + uVar6 * 4) = 0;
    } while (uVar6 < *(uint *)(param_1 + 0x4c));
  }
  *(undefined4 *)(param_1 + 0x3c) = 0;
  uVar6 = 0;
  if (*(int *)(param_1 + 100) != 0) {
    do {
      puVar4 = *(undefined4 **)(*(int *)(param_1 + 0x58) + uVar6 * 4);
      while (puVar4 != (undefined4 *)0x0) {
        puVar3 = (undefined4 *)*puVar4;
        func_0x00763260(puVar4);
        puVar4 = puVar3;
      }
      uVar6 = uVar6 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x58) + -4 + uVar6 * 4) = 0;
    } while (uVar6 < *(uint *)(param_1 + 100));
  }
  *(undefined4 *)(param_1 + 0x54) = 0;
  uVar6 = 0;
  if (*(int *)(param_1 + 0x7c) != 0) {
    do {
      puVar4 = *(undefined4 **)(*(int *)(param_1 + 0x70) + uVar6 * 4);
      while (puVar4 != (undefined4 *)0x0) {
        puVar3 = (undefined4 *)*puVar4;
        func_0x00763260(puVar4);
        puVar4 = puVar3;
      }
      uVar6 = uVar6 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x70) + -4 + uVar6 * 4) = 0;
    } while (uVar6 < *(uint *)(param_1 + 0x7c));
  }
  *(undefined4 *)(param_1 + 0x6c) = 0;
  func_0x005b5b60();
  return;
}


/* ==================================================================== */
/* Address: 0x0041bad0 | Classified: ElementClient::proc_41bad0 */
/* ==================================================================== */

void FUN_0041bad0(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008a72db;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  func_0x007637f0();
  uStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x0041bb20 | Classified: ElementClient::proc_41bb20 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0041bb20(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x1c) + -0xc);
  if (*piVar1 == -1) {
    *piVar1 = 1;
  }
  func_0x00763450(piVar1);
  *(int *)(param_1 + 0x1c) = _DAT_009858e4;
  return;
}


/* ==================================================================== */
/* Address: 0x0041bb30 | Classified: elementclient::CECScene__Load__Failed_to_open_s@0x41bb30 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0041bb30(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  char cVar2;
  int iVar3;
  float *unaff_FS_OFFSET;
  undefined4 uVar4;
  undefined1 auStack_80 [12];
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_1c;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  fStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a72fb;
  *unaff_FS_OFFSET = (float)&fStack_c;
  *(undefined4 *)(param_1 + 0x584) = param_4;
  *(undefined4 *)(param_1 + 0x580) = param_3;
  cVar2 = FUN_0041bd00(param_2,auStack_80);
  if (cVar2 == '\0') {
    (**(code **)(*(int *)(param_1 + 0x98) + 0xc))();
    func_0x00764590(1,0x950c30);
  }
  else {
    iVar3 = strrchr(param_2,0x2e);
    iVar3 = iVar3 - param_2;
    func_0x007636f0(param_2,iVar3);
    fStack_14 = 0.0;
    func_0x00763aa0(0x95059c);
    cVar2 = FUN_0041be00(iVar3);
    if (cVar2 == '\0') {
      (**(code **)(*(int *)(param_1 + 0x98) + 0xc))();
      (**(code **)(*(int *)(param_1 + 0x2b4) + 0xc))();
      uVar4 = 0x950c04;
    }
    else {
      cVar2 = FUN_0041c000(*(undefined4 *)(param_1 + 0x564));
      if (cVar2 == '\0') {
        uVar4 = 0x950bd4;
      }
      else {
        cVar2 = FUN_0041c100(uStack_6c,uStack_74);
        if (cVar2 != '\0') {
          cVar2 = FUN_0041c250(uStack_68,uStack_70);
          if (cVar2 != '\0') {
            uStack_1c = 0xffffffff;
            fStack_10 = fStack_10 - *(float *)(param_1 + 0x554) * _DAT_008d5894;
            *(float *)(param_1 + 0x570) = fStack_10;
            fVar1 = *(float *)(param_1 + 0x558) * _DAT_008d5894 + fStack_c;
            *(float *)(param_1 + 0x574) = fVar1;
            *(float *)(param_1 + 0x578) = fStack_10 + *(float *)(param_1 + 0x554);
            *(float *)(param_1 + 0x57c) = fVar1 - *(float *)(param_1 + 0x558);
            func_0x007637f0();
            uVar4 = 1;
            goto LAB_0041bce0;
          }
        }
        uVar4 = 0x950b98;
      }
    }
    func_0x00764590(1,uVar4);
    uStack_1c = 0xffffffff;
    func_0x007637f0();
  }
  uVar4 = 0;
LAB_0041bce0:
  *unaff_FS_OFFSET = fStack_14;
  return uVar4;
}


/* ==================================================================== */
/* Address: 0x0041bd00 | Classified: elementclient::CECScene__OpenSceneFile__Failed_t@0x41bd00 */
/* ==================================================================== */

uint __thiscall FUN_0041bd00(int param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int *unaff_EBX;
  
  cVar2 = (**(code **)(*(int *)(param_1 + 0x98) + 4))(&DAT_009b3c44,param_2,0x11);
  if (cVar2 == '\0') {
    uVar3 = func_0x00764590(1,0x950d04,param_2);
    return uVar3 & 0xffffff00;
  }
  cVar2 = (**(code **)(*(int *)(param_1 + 0x98) + 0x10))(unaff_EBX,0x74,&stack0xfffffff8);
  if (cVar2 == '\0') {
    uVar3 = func_0x00764590(1,0x950cd0);
    return uVar3 & 0xffffff00;
  }
  if (*unaff_EBX != 0x45435744) {
    uVar3 = func_0x00764590(1,0x950ca4);
    return uVar3 & 0xffffff00;
  }
  uVar3 = unaff_EBX[1];
  if (0xc < uVar3) {
    uVar3 = func_0x00764590(1,0x950c5c,0xc,uVar3);
    return uVar3 & 0xffffff00;
  }
  *(uint *)(param_1 + 0x4d0) = uVar3;
  *(int *)(param_1 + 0x568) = unaff_EBX[7];
  *(int *)(param_1 + 0x56c) = unaff_EBX[8];
  *(int *)(param_1 + 0x554) = unaff_EBX[2];
  *(int *)(param_1 + 0x558) = unaff_EBX[3];
  *(int *)(param_1 + 0x560) = unaff_EBX[4];
  iVar1 = unaff_EBX[6];
  *(int *)(param_1 + 0x564) = iVar1;
  *(int *)(param_1 + 0x4d8) = unaff_EBX[0xd];
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x0041be00 | Classified: elementclient::CECScene__OpenBSDFile__Failed_to@0x41be00 */
/* ==================================================================== */

/* WARNING: Removing unreachable block (ram,0x0041beca) */
/* WARNING: Removing unreachable block (ram,0x0041bf0e) */
/* WARNING: Removing unreachable block (ram,0x0041bf1e) */
/* WARNING: Removing unreachable block (ram,0x0041bf45) */
/* WARNING: Removing unreachable block (ram,0x0041bf4d) */
/* WARNING: Removing unreachable block (ram,0x0041bf57) */
/* WARNING: Removing unreachable block (ram,0x0041bf59) */
/* WARNING: Removing unreachable block (ram,0x0041bf5f) */
/* WARNING: Removing unreachable block (ram,0x0041bf72) */
/* WARNING: Removing unreachable block (ram,0x0041bf81) */
/* WARNING: Removing unreachable block (ram,0x0041bf34) */
/* WARNING: Removing unreachable block (ram,0x0041bf93) */
/* WARNING: Removing unreachable block (ram,0x0041bf16) */
/* WARNING: Removing unreachable block (ram,0x0041bee0) */
/* WARNING: Removing unreachable block (ram,0x0041beea) */
/* WARNING: Removing unreachable block (ram,0x0041befd) */
/* WARNING: Removing unreachable block (ram,0x0041bf97) */
/* WARNING: Removing unreachable block (ram,0x0041bf9d) */
/* WARNING: Removing unreachable block (ram,0x0041bfb8) */
/* WARNING: Removing unreachable block (ram,0x0041bfab) */
/* WARNING: Removing unreachable block (ram,0x0041bfba) */
/* WARNING: Removing unreachable block (ram,0x0041be9d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0041be00(int param_1,int param_2)

{
  char cVar1;
  undefined1 auStack_4 [4];
  
  cVar1 = (**(code **)(*(int *)(param_1 + 0x2b4) + 8))();
  if (cVar1 == '\0') {
    func_0x00764590(1,0x950dd8,param_2);
    return 0;
  }
  cVar1 = (**(code **)(*(int *)(param_1 + 0x2b4) + 0x10))(&stack0xffffffb0,0x48,auStack_4);
  if (cVar1 != '\0') {
    if (param_2 == 0x42534446) {
      *(undefined4 *)(param_1 + 0x4d4) = 1;
      return 1;
    }
    func_0x00764590(1,0x950d78);
    return 0;
  }
  func_0x00764590(1,0x950da4);
  return 0;
}


/* ==================================================================== */
/* Address: 0x0041c000 | Classified: elementclient::AArray__SetSize__Not_enough_memo@0x41c000 */
/* ==================================================================== */

bool __thiscall FUN_0041c000(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = param_2;
  *(undefined4 *)(param_1 + 0x88c) = 100;
  if (param_2 == 0) {
    if (*(int *)(param_1 + 0x880) != 0) {
      func_0x00763260(*(int *)(param_1 + 0x880));
      *(undefined4 *)(param_1 + 0x880) = 0;
    }
    *(undefined4 *)(param_1 + 0x888) = 0;
    *(undefined4 *)(param_1 + 0x884) = 0;
  }
  else if (*(int *)(param_1 + 0x888) < param_2) {
    iVar3 = func_0x00763250(param_2 * 4);
    if (iVar3 == 0) {
      func_0x00764590(1,0x9505a4);
    }
    else {
      if (*(int *)(param_1 + 0x880) != 0) {
        iVar5 = *(int *)(param_1 + 0x884);
        if (iVar1 <= *(int *)(param_1 + 0x884)) {
          iVar5 = iVar1;
        }
        iVar4 = 0;
        if (0 < iVar5) {
          do {
            iVar4 = iVar4 + 1;
            *(undefined4 *)(iVar3 + -4 + iVar4 * 4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x880) + -4 + iVar4 * 4);
          } while (iVar4 < iVar5);
        }
        func_0x00763260(*(undefined4 *)(param_1 + 0x880));
      }
      *(int *)(param_1 + 0x884) = iVar1;
      *(int *)(param_1 + 0x888) = iVar1;
      *(int *)(param_1 + 0x880) = iVar3;
    }
  }
  else {
    *(int *)(param_1 + 0x884) = param_2;
  }
  cVar2 = (**(code **)(*(int *)(param_1 + 0x98) + 0x10))
                    (*(undefined4 *)(param_1 + 0x880),iVar1 * 4,&param_2);
  return cVar2 != '\0';
}


/* ==================================================================== */
/* Address: 0x0041c100 | Classified: elementclient::AArray__Allocate__Not_enough_mem@0x41c100 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0041c100(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  (**(code **)(*(int *)(param_1 + 0x98) + 0x30))(param_3,0);
  iVar5 = 0;
  if (0 < param_1) {
    do {
      puVar1 = (undefined4 *)func_0x00763250(0x10);
      if (puVar1 == (undefined4 *)0x0) {
        return 0;
      }
      puVar1[1] = _DAT_009858e4;
      puVar1[2] = _DAT_009858e4;
      *puVar1 = 0;
      puVar1[3] = 0;
      (**(code **)(*(int *)(param_1 + 0x98) + 0x1c))(puVar1 + 1);
      (**(code **)(*(int *)(param_1 + 0x98) + 0x1c))(puVar1 + 2);
      if ((*(int *)(param_1 + 0x8bc) <= *(int *)(param_1 + 0x8b8)) &&
         (*(int *)(param_1 + 0x8c0) != 0)) {
        iVar4 = *(int *)(param_1 + 0x8c0) + *(int *)(param_1 + 0x8bc);
        iVar2 = func_0x00763250(iVar4 * 4);
        if (iVar2 == 0) {
          func_0x00764590(1,0x94e51c);
        }
        else {
          iVar3 = 0;
          if (0 < *(int *)(param_1 + 0x8b8)) {
            do {
              iVar3 = iVar3 + 1;
              *(undefined4 *)(iVar2 + -4 + iVar3 * 4) =
                   *(undefined4 *)(*(int *)(param_1 + 0x8b4) + -4 + iVar3 * 4);
            } while (iVar3 < *(int *)(param_1 + 0x8b8));
          }
          if (*(int *)(param_1 + 0x8b4) != 0) {
            func_0x00763260(*(int *)(param_1 + 0x8b4));
          }
          *(int *)(param_1 + 0x8b4) = iVar2;
          *(int *)(param_1 + 0x8bc) = iVar4;
        }
      }
      *(undefined4 **)(*(int *)(param_1 + 0x8b4) + *(int *)(param_1 + 0x8b8) * 4) = puVar1;
      iVar5 = iVar5 + 1;
      *(int *)(param_1 + 0x8b8) = *(int *)(param_1 + 0x8b8) + 1;
    } while (iVar5 < param_1);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0041c250 | Classified: elementclient::AArray__Allocate__Not_enough_mem@0x41c250 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0041c250(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iStack_4;
  
  (**(code **)(*(int *)(param_1 + 0x98) + 0x30))(param_3,0);
  iVar5 = 0;
  if (0 < iStack_4) {
    do {
      puVar1 = (undefined4 *)func_0x00763250(0x24);
      if (puVar1 == (undefined4 *)0x0) {
        return 0;
      }
      puVar1[7] = _DAT_009858e4;
      *puVar1 = 0;
      puVar1[8] = 0;
      (**(code **)(*(int *)(param_1 + 0x98) + 0x10))(puVar1 + 1,0x18,&stack0xfffffff4);
      (**(code **)(*(int *)(param_1 + 0x98) + 0x1c))(puVar1 + 7);
      if ((*(int *)(param_1 + 0x8d4) <= *(int *)(param_1 + 0x8d0)) &&
         (*(int *)(param_1 + 0x8d8) != 0)) {
        iVar4 = *(int *)(param_1 + 0x8d8) + *(int *)(param_1 + 0x8d4);
        iVar2 = func_0x00763250(iVar4 * 4);
        if (iVar2 == 0) {
          func_0x00764590(1,0x94e51c);
        }
        else {
          iVar3 = 0;
          if (0 < *(int *)(param_1 + 0x8d0)) {
            do {
              iVar3 = iVar3 + 1;
              *(undefined4 *)(iVar2 + -4 + iVar3 * 4) =
                   *(undefined4 *)(*(int *)(param_1 + 0x8cc) + -4 + iVar3 * 4);
            } while (iVar3 < *(int *)(param_1 + 0x8d0));
          }
          if (*(int *)(param_1 + 0x8cc) != 0) {
            func_0x00763260(*(int *)(param_1 + 0x8cc));
          }
          *(int *)(param_1 + 0x8cc) = iVar2;
          *(int *)(param_1 + 0x8d4) = iVar4;
        }
      }
      *(undefined4 **)(*(int *)(param_1 + 0x8cc) + *(int *)(param_1 + 0x8d0) * 4) = puVar1;
      iVar5 = iVar5 + 1;
      *(int *)(param_1 + 0x8d0) = *(int *)(param_1 + 0x8d0) + 1;
    } while (iVar5 < iStack_4);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0041c3b0 | Classified: ElementClient::proc_41c3b0 */
/* ==================================================================== */

void __fastcall FUN_0041c3b0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 *unaff_retaddr;
  
  iVar1 = *(int *)(param_1 + 0x52c);
  FUN_0041ca80();
  puVar2 = *(undefined4 **)(param_1 + 0x894);
  while (puVar2 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x894) = *puVar2;
    *puVar2 = *(undefined4 *)(param_1 + 0x89c);
    *(undefined4 **)(param_1 + 0x89c) = puVar2;
    puVar2 = *(undefined4 **)(param_1 + 0x894);
    *(int *)(param_1 + 0x8a0) = *(int *)(param_1 + 0x8a0) + -1;
  }
  *(undefined4 *)(param_1 + 0x898) = 0;
  *(undefined4 *)(param_1 + 0x8a0) = 0;
  FUN_0041c480(unaff_retaddr,*(undefined4 *)(param_1 + 0x55c));
  *(undefined4 *)(param_1 + 0x538) = *unaff_retaddr;
  *(undefined4 *)(param_1 + 0x53c) = unaff_retaddr[1];
  *(undefined4 *)(param_1 + 0x540) = unaff_retaddr[2];
  piVar3 = *(int **)(param_1 + 0x52c);
  *piVar3 = (int)&stack0xffffffec;
  piVar3[1] = iVar1;
  piVar3[2] = unaff_EDI;
  piVar3[3] = unaff_ESI;
  FUN_0041c900(*(undefined4 *)(param_1 + 0x52c));
  return;
}


/* ==================================================================== */
/* Address: 0x0041c480 | Classified: ElementClient::proc_41c480 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0041c480(int param_1,undefined4 param_2,float param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  ceil((double)((_DAT_008d5c28 / *(float *)(param_1 + 0x560)) * param_3));
  iVar4 = func_0x00892e78();
  iVar2 = *(int *)(param_1 + 0x568);
  iVar3 = *(int *)(param_1 + 0x56c);
  iVar1 = iVar4 * 2 + 1;
  iVar5 = func_0x00892e78();
  iVar5 = iVar5 - iVar4;
  iVar6 = func_0x00892e78();
  iVar6 = -(iVar6 + iVar4);
  iVar4 = iVar5 + iVar1;
  if ((iVar5 < 0) && (iVar5 = 0, iVar4 = iVar3, iVar1 < iVar3)) {
    iVar4 = iVar1;
  }
  iVar7 = iVar6 + iVar1;
  if ((iVar6 < 0) && (iVar6 = 0, iVar7 = iVar2, iVar1 < iVar2)) {
    iVar7 = iVar1;
  }
  if (iVar3 < iVar4) {
    if (iVar1 < iVar3) {
      iVar5 = iVar3 - iVar1;
      iVar4 = iVar3;
    }
    else {
      iVar5 = 0;
      iVar4 = iVar3;
    }
  }
  if (iVar2 < iVar7) {
    if (iVar1 < iVar2) {
      iVar6 = iVar2 - iVar1;
      iVar7 = iVar2;
    }
    else {
      iVar6 = 0;
      iVar7 = iVar2;
    }
  }
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  if (iVar6 < 0) {
    iVar6 = 0;
  }
  if (iVar3 < iVar4) {
    iVar4 = iVar3;
  }
  if (iVar2 < iVar7) {
    iVar7 = iVar2;
  }
  if ((((iVar5 <= iVar3) && (iVar6 <= iVar2)) && (-1 < iVar4)) &&
     (((-1 < iVar7 && (iVar5 <= iVar4)) && (iVar6 <= iVar7)))) {
    *param_4 = iVar5;
    param_4[1] = iVar6;
    param_4[2] = iVar4;
    param_4[3] = iVar7;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0041c5b0 | Classified: ElementClient::proc_41c5b0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0041c5b0(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int unaff_EBX;
  int *piVar7;
  int unaff_EBP;
  int iVar8;
  int unaff_EDI;
  int *piVar9;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int aiStack_20 [2];
  int iStack_18;
  int aiStack_8 [2];
  
  FUN_0041c480(param_2,*(undefined4 *)(param_1 + 0x55c),aiStack_20);
  *(undefined4 *)(param_1 + 0x538) = *param_2;
  *(undefined4 *)(param_1 + 0x53c) = param_2[1];
  *(undefined4 *)(param_1 + 0x540) = param_2[2];
  piVar9 = *(int **)(param_1 + 0x52c);
  if (piVar9[7] == 0) {
    *piVar9 = iStack_2c;
    piVar9[1] = iStack_28;
    piVar9[2] = iStack_24;
    piVar9[3] = aiStack_20[0];
    uVar2 = FUN_0041c900(*(undefined4 *)(param_1 + 0x52c));
    return uVar2;
  }
  if ((((iStack_2c == *piVar9) && (iStack_28 == piVar9[1])) && (iStack_24 == piVar9[2])) &&
     (aiStack_20[0] == piVar9[3])) {
    return 1;
  }
  uVar2 = *(undefined4 *)(param_1 + 0x52c);
  *(undefined4 *)(param_1 + 0x52c) = *(undefined4 *)(param_1 + 0x530);
  *(undefined4 *)(param_1 + 0x530) = uVar2;
  piVar9 = *(int **)(param_1 + 0x52c);
  *piVar9 = iStack_2c;
  piVar9[1] = iStack_28;
  piVar9[2] = iStack_24;
  piVar9[3] = aiStack_20[0];
  piVar9 = *(int **)(param_1 + 0x530);
  if (((iStack_24 != iStack_2c) && (aiStack_20[0] != iStack_28)) &&
     (aiStack_8[0] = piVar9[2], aiStack_8[0] != *piVar9)) {
    iVar3 = piVar9[3];
    iVar1 = piVar9[1];
    piVar6 = piVar9 + 3;
    if (iVar3 != iVar1) {
      if (((iStack_2c < aiStack_8[0]) && (iVar8 = *piVar9, iVar8 < iStack_24)) &&
         ((iStack_28 < iVar3 && (iVar1 < aiStack_20[0])))) {
        if (aiStack_20[0] < iVar3) {
          piVar6 = aiStack_20;
        }
        if (iStack_24 < aiStack_8[0]) {
          piVar7 = &iStack_24;
        }
        else {
          piVar7 = piVar9 + 2;
        }
        piVar5 = &iStack_28;
        if (iStack_28 <= iVar1) {
          piVar5 = piVar9 + 1;
        }
        if (iVar8 < iStack_2c) {
          piVar9 = &iStack_2c;
        }
      }
      else {
        piVar6 = aiStack_8;
        aiStack_8[0] = 0;
        iVar8 = 0;
        unaff_EBP = 0;
        unaff_EBX = 0;
        piVar7 = (int *)&stack0xffffffc8;
        piVar5 = (int *)&stack0xffffffcc;
        piVar9 = (int *)&stack0xffffffd0;
      }
      goto LAB_0041c788;
    }
  }
  piVar6 = aiStack_8;
  aiStack_8[0] = 0;
  unaff_EBX = 0;
  unaff_EBP = 0;
  iVar8 = 0;
  piVar7 = (int *)&stack0xffffffd0;
  piVar5 = (int *)&stack0xffffffcc;
  piVar9 = (int *)&stack0xffffffc8;
LAB_0041c788:
  func_0x006484f0(piVar9,piVar5,piVar7,piVar6);
  if ((iStack_24 != iStack_2c) && (aiStack_20[0] != iStack_28)) {
    iVar3 = iVar8 * *(int *)(param_1 + 0x56c) + unaff_EDI;
    for (; iVar4 = iVar3, iVar1 = unaff_EDI, iVar8 < unaff_EBX; iVar8 = iVar8 + 1) {
      for (; iStack_18 = iVar4, iVar1 < unaff_EBP; iVar1 = iVar1 + 1) {
        piVar9 = *(int **)(param_1 + 0x530);
        if ((((iVar1 < *piVar9) || (piVar9[2] <= iVar1)) || (iVar8 < piVar9[1])) ||
           (piVar9[3] <= iVar8)) {
          iVar4 = func_0x00421d50();
          *(int *)(iVar4 + 8) = iStack_18;
          *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(param_1 + 0x898);
          if (*(int **)(param_1 + 0x898) == (int *)0x0) {
            *(int *)(param_1 + 0x894) = iVar4;
          }
          else {
            **(int **)(param_1 + 0x898) = iVar4;
          }
          *(int *)(param_1 + 0x898) = iVar4;
          iVar4 = *(int *)(param_1 + 0x52c);
          if (*(int *)(iVar4 + 0x20) <= *(int *)(iVar4 + 0x1c)) {
            func_0x0068e120(*(undefined4 *)(iVar4 + 0x24));
          }
          *(undefined4 *)(*(int *)(iVar4 + 0x18) + *(int *)(iVar4 + 0x1c) * 4) = 0;
          *(int *)(iVar4 + 0x1c) = *(int *)(iVar4 + 0x1c) + 1;
        }
        else {
          iVar4 = ((iVar8 - piVar9[1]) * (piVar9[2] - *piVar9) - *piVar9) + iVar1;
          uVar2 = *(undefined4 *)(piVar9[6] + iVar4 * 4);
          *(undefined4 *)(piVar9[6] + iVar4 * 4) = 0;
          func_0x00459590(uVar2);
        }
        iVar4 = iStack_18 + 1;
      }
      iVar3 = iVar3 + *(int *)(param_1 + 0x56c);
    }
    FUN_0041ca80(*(undefined4 *)(param_1 + 0x530));
    return 1;
  }
  FUN_0041ca80(*(undefined4 *)(param_1 + 0x530));
  uVar2 = FUN_0041c900(*(undefined4 *)(param_1 + 0x52c));
  return uVar2;
}


/* ==================================================================== */
/* Address: 0x0041c900 | Classified: elementclient::AArray__Allocate__Not_enough_mem@0x41c900 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0041c900(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iStack_18;
  int iStack_14;
  
  iVar1 = param_2[2];
  iVar3 = param_2[1];
  iVar4 = iVar3 * *(int *)(param_1 + 0x56c) + *param_2;
  iStack_14 = param_1;
  if (iVar3 < param_2[3]) {
    do {
      iVar6 = *param_2;
      iStack_18 = iVar4;
      if (iVar6 < iVar1) {
        do {
          iStack_14 = FUN_0041cc30(iVar3,iVar6,iStack_18);
          if ((param_2[8] <= param_2[7]) && (param_2[9] != 0)) {
            iVar5 = param_2[9] + param_2[8];
            iVar1 = func_0x00763250(iVar5 * 4);
            if (iVar1 == 0) {
              func_0x00764590(1,0x94e51c);
            }
            else {
              iVar2 = 0;
              if (0 < param_2[7]) {
                do {
                  iVar2 = iVar2 + 1;
                  *(undefined4 *)(iVar1 + -4 + iVar2 * 4) =
                       *(undefined4 *)(param_2[6] + -4 + iVar2 * 4);
                } while (iVar2 < param_2[7]);
              }
              if (param_2[6] != 0) {
                func_0x00763260(param_2[6]);
              }
              param_2[6] = iVar1;
              param_2[8] = iVar5;
            }
          }
          *(int *)(param_2[6] + param_2[7] * 4) = iStack_14;
          param_2[7] = param_2[7] + 1;
          iVar1 = func_0x00892e78();
          if (iVar1 != 0) {
            func_0x00438260(iVar1);
          }
          iVar1 = param_2[2];
          iVar6 = iVar6 + 1;
          iStack_18 = iStack_18 + 1;
        } while (iVar6 < iVar1);
      }
      iVar4 = iVar4 + *(int *)(iStack_14 + 0x56c);
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_2[3]);
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x0041ca80 | Classified: ElementClient::proc_41ca80 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041ca80(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_c [12];
  
  iVar1 = param_1[7];
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      iVar1 = *(int *)(param_1[6] + iVar2 * 4);
      if (iVar1 != 0) {
        FUN_0041cdc0(iVar1);
      }
      iVar1 = param_1[7];
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  if (iVar1 != 0) {
    func_0x00438290(auStack_c,*(undefined4 *)(_DAT_009b3eec + 0x14));
    func_0x006450d0();
    func_0x006485e0(&stack0xffffffec,0);
    func_0x006450d0();
    func_0x00649a40(&stack0xffffffe4,0);
  }
  param_1[7] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x0041cb20 | Classified: ElementClient::proc_41cb20 */
/* ==================================================================== */

undefined4 __fastcall FUN_0041cb20(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iStack_8;
  
  iStack_8 = *(int *)(param_1 + 0x8a0);
  if (*(int *)(param_1 + 0x534) < *(int *)(param_1 + 0x8a0)) {
    iStack_8 = *(int *)(param_1 + 0x534);
  }
  if ((iStack_8 != 0) && (0 < iStack_8)) {
    do {
      piVar1 = *(int **)(param_1 + 0x894);
      iVar3 = *piVar1;
      iVar2 = piVar1[2];
      *(int *)(param_1 + 0x894) = iVar3;
      if (iVar3 == 0) {
        *(undefined4 *)(param_1 + 0x898) = 0;
      }
      else {
        *(undefined4 *)(iVar3 + 4) = 0;
      }
      *piVar1 = *(int *)(param_1 + 0x89c);
      *(int **)(param_1 + 0x89c) = piVar1;
      *(int *)(param_1 + 0x8a0) = *(int *)(param_1 + 0x8a0) + -1;
      iVar3 = iVar2 / *(int *)(param_1 + 0x56c);
      piVar1 = *(int **)(param_1 + 0x52c);
      iVar5 = iVar2 - *(int *)(param_1 + 0x56c) * iVar3;
      if ((((*piVar1 <= iVar5) && (iVar5 < piVar1[2])) && (piVar1[1] <= iVar3)) &&
         ((iVar3 < piVar1[3] &&
          (*(int *)(piVar1[6] +
                   (((iVar3 - piVar1[1]) * (piVar1[2] - *piVar1) - *piVar1) + iVar5) * 4) == 0)))) {
        uVar4 = FUN_0041cc30(iVar3,iVar5,iVar2);
        piVar1 = *(int **)(param_1 + 0x52c);
        *(undefined4 *)
         (piVar1[6] + (((iVar3 - piVar1[1]) * (piVar1[2] - *piVar1) - *piVar1) + iVar5) * 4) = uVar4
        ;
      }
      iStack_8 = iStack_8 + -1;
    } while (iStack_8 != 0);
    iStack_8 = 0;
  }
  return CONCAT31((int3)((uint)iStack_8 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x0041cc30 | Classified: ElementClient::proc_41cc30 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall FUN_0041cc30(int param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  int unaff_retaddr;
  undefined4 uStack_c;
  undefined *puStack_8;
  float fStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  fStack_4 = -NAN;
  puStack_8 = &UNK_008a731b;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_4 < 0) {
    param_4 = *(int *)(param_1 + 0x56c) * param_2 + param_3;
  }
  iVar6 = func_0x00763250(0x130);
  fStack_4 = 0.0;
  if (iVar6 == 0) {
    puVar7 = (undefined4 *)0x0;
  }
  else {
    puVar7 = (undefined4 *)func_0x00421f50(param_1);
  }
  fStack_4 = -NAN;
  if (puVar7 == (undefined4 *)0x0) {
    *unaff_FS_OFFSET = uStack_c;
    return (undefined4 *)0x0;
  }
  cVar5 = FUN_00430850();
  if (cVar5 == '\0') {
    *unaff_FS_OFFSET = uStack_c;
    return (undefined4 *)0x0;
  }
  (**(code **)(*(int *)(param_1 + 0x98) + 0x30))
            (*(undefined4 *)(*(int *)(param_1 + 0x880) + param_4 * 4));
  fVar1 = (float)unaff_retaddr * *(float *)(param_1 + 0x560) + *(float *)(param_1 + 0x570);
  fVar2 = *(float *)(param_1 + 0x574) - (float)(int)fStack_4 * *(float *)(param_1 + 0x560);
  fStack_4 = *(float *)(param_1 + 0x560) * _DAT_008d5894;
  fVar4 = (fStack_4 + fVar1) - *(float *)(param_1 + 0x538);
  fVar3 = (fVar2 - fStack_4) - *(float *)(param_1 + 0x540);
  fStack_4 = SQRT(fVar4 * fVar4 + fVar3 * fVar3) - fStack_4;
  cVar5 = func_0x00422390(param_1 + 0x98,param_1 + 0x2b4,fVar1,fVar2,fStack_4);
  if (cVar5 == '\0') {
    func_0x00422330();
    (**(code **)*puVar7)(1);
    *unaff_FS_OFFSET = 0;
    return (undefined4 *)0x0;
  }
  *unaff_FS_OFFSET = unaff_EDI;
  return puVar7;
}


/* ==================================================================== */
/* Address: 0x0041cdc0 | Classified: ElementClient::proc_41cdc0 */
/* ==================================================================== */

void FUN_0041cdc0(undefined4 *param_1)

{
  func_0x00422330();
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(1);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0041cde0 | Classified: ElementClient::proc_41cde0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0041cde0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 auStack_c [12];
  
  iVar3 = 0;
  iVar1 = *(int *)(param_1 + 0x52c);
  if (0 < *(int *)(iVar1 + 0x1c)) {
    do {
      puVar2 = *(undefined4 **)(*(int *)(iVar1 + 0x18) + iVar3 * 4);
      if (puVar2 != (undefined4 *)0x0) {
        func_0x00422330();
        (**(code **)*puVar2)(1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(iVar1 + 0x1c));
  }
  func_0x00438290(auStack_c);
  func_0x006450d0();
  func_0x006485e0(&stack0xffffffec,0);
  func_0x006450d0();
  func_0x00649a40(&stack0xffffffe4,0);
  if (*(int *)(param_1 + 0x4f4) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x4f4));
    *(undefined4 *)(param_1 + 0x4f4) = 0;
  }
  *(undefined4 *)(param_1 + 0x4fc) = 0;
  *(undefined4 *)(param_1 + 0x4f8) = 0;
  if (*(int *)(param_1 + 0x51c) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x51c));
    *(undefined4 *)(param_1 + 0x51c) = 0;
  }
  *(undefined4 *)(param_1 + 0x524) = 0;
  *(undefined4 *)(param_1 + 0x520) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x0041cec0 | Classified: ElementClient::proc_41cec0 */
/* ==================================================================== */

/* WARNING: Removing unreachable block (ram,0x0041d057) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __thiscall
FUN_0041cec0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  int unaff_retaddr;
  int *piStack_18;
  int *piStack_14;
  undefined1 auStack_10 [16];
  
  cVar1 = FUN_0041c5b0(param_4);
  if (cVar1 == '\0') {
    return 0;
  }
  cVar1 = FUN_0041cb20();
  if (cVar1 == '\0') {
    return 0;
  }
  uVar3 = *(int *)(param_1 + 0x54c) + unaff_retaddr;
  *(uint *)(param_1 + 0x54c) = uVar3;
  if (*(uint *)(param_1 + 0x550) <= uVar3) {
    *(undefined4 *)(param_1 + 0x54c) = 0;
    func_0x00438290(auStack_10,*(undefined4 *)(_DAT_009b3eec + 0x14));
    func_0x006450d0();
    func_0x006485e0(&piStack_18,0);
    func_0x006450d0();
    func_0x00649a40(&stack0xffffffe0,0);
  }
  piVar2 = *(int **)(param_1 + 0x52c);
  if ((piVar2[2] != *piVar2) && (piVar2[3] != piVar2[1])) {
    uVar3 = *(int *)(param_1 + 0x544) + unaff_retaddr;
    *(uint *)(param_1 + 0x544) = uVar3;
    if (*(uint *)(param_1 + 0x548) <= uVar3) {
      *(undefined4 *)(param_1 + 0x544) = 0;
      func_0x00421760();
    }
    piStack_14 = (int *)0x0;
    piStack_18 = *(int **)(param_1 + 0x58);
    if (piStack_18 == (int *)(*(int *)(param_1 + 0x58) + *(int *)(param_1 + 100) * 4))
    goto LAB_0041cfed;
    piStack_14 = (int *)*piStack_18;
    piVar2 = piStack_18;
    if (piStack_14 == (int *)0x0) {
      func_0x007031f0();
      piVar2 = piStack_18;
    }
LAB_0041cffd:
    if ((piVar2 != (int *)0x0) || (piStack_14 != (int *)0x0)) {
      FUN_00489800(unaff_retaddr);
      piVar2 = piStack_18;
      if (piStack_18 != (int *)0x0) {
        do {
          while (piStack_14 == (int *)0x0) {
            piVar2 = piVar2 + 1;
            if (piVar2 == (int *)(*(int *)(param_1 + 0x58) + *(int *)(param_1 + 100) * 4))
            goto LAB_0041cfed;
            piStack_14 = (int *)*piVar2;
            piStack_18 = piVar2;
            if (piStack_14 != (int *)0x0) goto LAB_0041cffd;
          }
          piStack_14 = (int *)*piStack_14;
        } while (piStack_14 == (int *)0x0);
      }
      goto LAB_0041cffd;
    }
    func_0x00421690(unaff_retaddr);
    if ((6 < *(int *)(param_1 + 0x4d4)) &&
       (uVar3 = *(int *)(param_1 + 0x588) + unaff_retaddr, *(uint *)(param_1 + 0x588) = uVar3,
       4999 < uVar3)) {
      *(undefined4 *)(param_1 + 0x588) = 0;
      FUN_0041ea20();
    }
  }
  return 1;
LAB_0041cfed:
  piStack_18 = (int *)0x0;
  piVar2 = (int *)0x0;
  goto LAB_0041cffd;
}


/* ==================================================================== */
/* Address: 0x0041d0c0 | Classified: ElementClient::proc_41d0c0 */
/* ==================================================================== */

/* WARNING: Removing unreachable block (ram,0x0041d17e) */

undefined4 __thiscall FUN_0041d0c0(int param_1,undefined4 param_2)

{
  int *piVar1;
  int *piStack_8;
  int *piStack_4;
  
  piStack_4 = (int *)0x0;
  piStack_8 = *(int **)(param_1 + 0x58);
  if (piStack_8 == (int *)(*(int *)(param_1 + 0x58) + *(int *)(param_1 + 100) * 4)) {
    piStack_8 = (int *)0x0;
    piVar1 = piStack_8;
  }
  else {
    piStack_4 = (int *)*piStack_8;
    piVar1 = piStack_8;
    if (piStack_4 == (int *)0x0) {
      func_0x007031f0();
    }
  }
LAB_0041d12b:
  do {
    do {
      if ((piVar1 == (int *)0x0) && (piStack_4 == (int *)0x0)) {
        return 1;
      }
      FUN_00489910(param_2);
      piVar1 = piStack_8;
    } while (piStack_8 == (int *)0x0);
    do {
      while (piStack_4 == (int *)0x0) {
        piVar1 = piVar1 + 1;
        if (piVar1 == (int *)(*(int *)(param_1 + 0x58) + *(int *)(param_1 + 100) * 4)) {
          piStack_8 = (int *)0x0;
          piVar1 = (int *)0x0;
          goto LAB_0041d12b;
        }
        piStack_4 = (int *)*piVar1;
        piStack_8 = piVar1;
        if (piStack_4 != (int *)0x0) goto LAB_0041d12b;
      }
      piStack_4 = (int *)*piStack_4;
    } while (piStack_4 == (int *)0x0);
  } while( true );
}


/* ==================================================================== */
/* Address: 0x0041d1b0 | Classified: ElementClient::proc_41d1b0 */
/* ==================================================================== */

/* WARNING: Removing unreachable block (ram,0x0041d2f5) */

int __thiscall FUN_0041d1b0(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *unaff_EBX;
  undefined1 *puStack_2c;
  int **ppiStack_28;
  undefined4 *puStack_24;
  undefined4 uStack_14;
  int *piStack_10;
  char cStack_c;
  undefined1 auStack_4 [4];
  
  uVar1 = param_2;
  for (puVar3 = *(undefined4 **)
                 (*(int *)(param_1 + 0x10) + (param_2 % *(uint *)(param_1 + 0x1c)) * 4);
      puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
    if (puVar3[2] == param_2) {
      return puVar3[1];
    }
  }
  for (puVar3 = *(undefined4 **)
                 (*(int *)(param_1 + 0x70) + (param_2 % *(uint *)(param_1 + 0x7c)) * 4);
      puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
    if (puVar3[2] == param_2) {
      return puVar3[1];
    }
  }
  puStack_24 = &param_2;
  ppiStack_28 = &piStack_10;
  param_2 = param_2 & 0xffffff00;
  piStack_10 = (int *)0x0;
  puStack_2c = (undefined1 *)0x41d22d;
  func_0x004445b0();
  if (cStack_c != '\0') {
    return *piStack_10;
  }
  puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x28) + (uVar1 % *(uint *)(param_1 + 0x34)) * 4);
  do {
    if (puVar3 == (undefined4 *)0x0) {
      puStack_2c = &stack0xffffffe7;
      puVar3 = &uStack_14;
      uStack_14 = 0;
LAB_0041d270:
      func_0x004445b0(puVar3);
      if ((char)uStack_14 != '\0') {
        return *unaff_EBX;
      }
      iVar2 = func_0x004322c0(&stack0xffffffe0);
      for (puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x40) + iVar2 * 4);
          puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
        if ((undefined4 *)puVar3[2] == puStack_24) {
          return puVar3[1];
        }
      }
      piStack_10 = (int *)((uint)piStack_10 & 0xffffff00);
      func_0x004445b0(&stack0xffffffe0,&piStack_10);
      puVar3 = (undefined4 *)func_0x006496d0(&puStack_24,&stack0xffffffe8);
      if (*(char *)(puVar3 + 1) == '\0') {
        puVar3 = (undefined4 *)func_0x006496d0(&puStack_2c,&stack0xffffffe0);
        if (*(char *)(puVar3 + 1) == '\0') {
          return 0;
        }
        return *(undefined4 *)*puVar3;
      }
      return *(undefined4 *)*puVar3;
    }
    if (puVar3[2] == uVar1) {
      unaff_EBX = puVar3 + 1;
      puVar3 = (undefined4 *)&stack0xffffffe8;
      puStack_2c = auStack_4;
      auStack_4[0] = 1;
      goto LAB_0041d270;
    }
    puVar3 = (undefined4 *)*puVar3;
  } while( true );
}


/* ==================================================================== */
/* Address: 0x0041d380 | Classified: ElementClient::proc_41d380 */
/* ==================================================================== */

undefined4 __thiscall FUN_0041d380(int param_1,uint param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x10) + (param_2 % *(uint *)(param_1 + 0x1c)) * 4);
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    if (puVar1[2] == param_2) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1[1];
}


/* ==================================================================== */
/* Address: 0x0041d3b0 | Classified: ElementClient::proc_41d3b0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0041d3b0(int param_1,uint param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x70) + (param_2 % *(uint *)(param_1 + 0x7c)) * 4);
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    if (puVar1[2] == param_2) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1[1];
}


/* ==================================================================== */
/* Address: 0x0041d3e0 | Classified: ElementClient::proc_41d3e0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0041d3e0(int param_1,uint param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x28) + (param_2 % *(uint *)(param_1 + 0x34)) * 4);
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    if (puVar1[2] == param_2) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1[1];
}


/* ==================================================================== */
/* Address: 0x0041d410 | Classified: ElementClient::proc_41d410 */
/* ==================================================================== */

undefined4 __thiscall FUN_0041d410(int param_1,uint param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x40) + (param_2 % *(uint *)(param_1 + 0x4c)) * 4);
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    if (puVar1[2] == param_2) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1[1];
}


/* ==================================================================== */
/* Address: 0x0041d440 | Classified: ElementClient::proc_41d440 */
/* ==================================================================== */

undefined4 __thiscall FUN_0041d440(int param_1,uint param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x58) + (param_2 % *(uint *)(param_1 + 100)) * 4);
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    if (puVar1[2] == param_2) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1[1];
}


/* ==================================================================== */
/* Address: 0x0041d470 | Classified: ElementClient::proc_41d470 */
/* ==================================================================== */

undefined4 __thiscall FUN_0041d470(int param_1,uint param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x88) + (param_2 % *(uint *)(param_1 + 0x94)) * 4);
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    if (puVar1[2] == param_2) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1[1];
}


/* ==================================================================== */
/* Address: 0x0041d4b0 | Classified: ElementClient::proc_41d4b0 */
/* ==================================================================== */

void __thiscall FUN_0041d4b0(uint param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  uint uStack_4;
  
  uStack_4 = param_1;
  puVar3 = (undefined4 *)FUN_0041d1b0(param_2);
  if (puVar3 != (undefined4 *)0x0) {
    if (1 < (int)puVar3[4]) {
      puVar3[4] = puVar3[4] + -1;
      return;
    }
    switch(puVar3[3]) {
    case 0:
      FUN_0041e9e0(puVar3[5]);
      FUN_007804b0(param_2);
      uVar7 = param_2 % *(uint *)(param_1 + 0x1c);
      piVar1 = *(int **)(*(int *)(param_1 + 0x10) + uVar7 * 4);
      piVar2 = piVar1;
      piVar6 = (int *)0x0;
      if (piVar1 != (int *)0x0) {
        do {
          piVar5 = piVar2;
          if (piVar5[2] == param_2) {
            if (piVar5 == piVar1) {
              *(int *)(*(int *)(param_1 + 0x10) + uVar7 * 4) = *piVar5;
            }
            else {
              *piVar6 = *piVar5;
            }
            func_0x00763260(piVar5);
            *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;
            (**(code **)*puVar3)(1);
            return;
          }
          piVar2 = (int *)*piVar5;
          piVar6 = piVar5;
        } while ((int *)*piVar5 != (int *)0x0);
        (**(code **)*puVar3)(1);
        return;
      }
      break;
    case 1:
      FUN_0041e9e0(puVar3[7]);
      iVar4 = func_0x00651560(puVar3[6]);
      if (iVar4 != 0) {
        func_0x00652590(puVar3[5]);
      }
      uVar7 = param_2 % *(uint *)(param_1 + 0x4c);
      piVar1 = *(int **)(*(int *)(param_1 + 0x40) + uVar7 * 4);
      piVar2 = piVar1;
      piVar6 = (int *)0x0;
      if (piVar1 != (int *)0x0) {
        do {
          piVar5 = piVar2;
          if (piVar5[2] == param_2) {
            if (piVar5 == piVar1) {
              *(int *)(*(int *)(param_1 + 0x40) + uVar7 * 4) = *piVar5;
            }
            else {
              *piVar6 = *piVar5;
            }
            func_0x00763260(piVar5);
            *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + -1;
            (**(code **)*puVar3)(1);
            return;
          }
          piVar2 = (int *)*piVar5;
          piVar6 = piVar5;
        } while ((int *)*piVar5 != (int *)0x0);
        (**(code **)*puVar3)(1);
        return;
      }
      break;
    case 2:
      uVar7 = param_2 % *(uint *)(param_1 + 0x34);
      piVar1 = *(int **)(*(int *)(param_1 + 0x28) + uVar7 * 4);
      piVar2 = piVar1;
      piVar6 = (int *)0x0;
      if (piVar1 != (int *)0x0) {
        do {
          piVar5 = piVar2;
          if (piVar5[2] == param_2) {
            if (piVar5 == piVar1) {
              *(int *)(*(int *)(param_1 + 0x28) + uVar7 * 4) = *piVar5;
            }
            else {
              *piVar6 = *piVar5;
            }
            func_0x00763260(piVar5);
            *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
            (**(code **)*puVar3)(1);
            return;
          }
          piVar2 = (int *)*piVar5;
          piVar6 = piVar5;
        } while ((int *)*piVar5 != (int *)0x0);
        (**(code **)*puVar3)(1);
        return;
      }
      break;
    case 3:
      uVar7 = param_2 % *(uint *)(param_1 + 100);
      piVar1 = *(int **)(*(int *)(param_1 + 0x58) + uVar7 * 4);
      piVar2 = piVar1;
      piVar6 = (int *)0x0;
      if (piVar1 != (int *)0x0) {
        do {
          piVar5 = piVar2;
          if (piVar5[2] == param_2) {
            if (piVar5 == piVar1) {
              *(int *)(*(int *)(param_1 + 0x58) + uVar7 * 4) = *piVar5;
            }
            else {
              *piVar6 = *piVar5;
            }
            func_0x00763260(piVar5);
            *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + -1;
            (**(code **)*puVar3)(1);
            return;
          }
          piVar2 = (int *)*piVar5;
          piVar6 = piVar5;
        } while ((int *)*piVar5 != (int *)0x0);
        (**(code **)*puVar3)(1);
        return;
      }
      break;
    case 4:
      func_0x006450d0(param_2);
      FUN_005b2ee0();
      uStack_4 = param_2;
      func_0x00421be0(&uStack_4);
      return;
    case 5:
      func_0x00488660();
      func_0x00421be0(&stack0xfffffff8);
    }
    (**(code **)*puVar3)(1);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0041d740 | Classified: elementclient::CECScene__LoadWaterArea__failed_t@0x41d740 */
/* ==================================================================== */

undefined4 __thiscall FUN_0041d740(int param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  uint uVar12;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  int iVar13;
  undefined4 *unaff_FS_OFFSET;
  uint unaff_retaddr;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a7346;
  *unaff_FS_OFFSET = &uStack_c;
  iVar6 = FUN_0041d380(param_2);
  iVar13 = 0;
  if (iVar6 == 0) {
    (**(code **)(*(int *)(param_1 + 0x2b4) + 0x30))(param_2,0);
    param_2 = func_0x00763250(0xb0);
    puStack_8 = (undefined *)0x0;
    if (param_2 != 0) {
      iVar13 = FUN_00780ba0();
    }
    puStack_8 = (undefined *)0xffffffff;
    if (iVar13 == 0) {
      uVar7 = 0;
      goto LAB_0041da59;
    }
    if (*(int *)(param_1 + 0x4d4) < 7) {
      cVar5 = FUN_00780d30(*(undefined4 *)(*(int *)(param_1 + 4) + 0x10),(int *)(param_1 + 0x2b4));
      unaff_EDI = 0xffffffff;
      if (cVar5 == '\0') {
        func_0x00764590(1,0x950e88);
        uVar7 = 0;
        goto LAB_0041da59;
      }
    }
    else {
      (**(code **)(*(int *)(param_1 + 0x2b4) + 0x10))(&stack0xffffffcc,8,&param_2);
      piVar8 = (int *)FUN_0041e750(unaff_EDI,unaff_ESI);
      if (piVar8 == (int *)0x0) {
        func_0x00764590(1,0x950e48);
        uVar7 = 0;
        goto LAB_0041da59;
      }
      cVar5 = FUN_00780d30(*(undefined4 *)(*(int *)(param_1 + 4) + 0x10),*piVar8);
      if (cVar5 == '\0') {
        func_0x00764590(1,0x950e08,*piVar8 + 0x10c);
        uVar7 = 0;
        goto LAB_0041da59;
      }
    }
    *(undefined **)(iVar13 + 4) = puStack_8;
    func_0x007819f0(&stack0xffffffcc);
    FUN_00781620();
    FUN_00780300(iVar13);
    param_2 = func_0x00763250(0x18);
    uVar12 = 0;
    puStack_8 = (undefined *)0x1;
    if (param_2 == 0) {
      param_2 = 0;
    }
    else {
      param_2 = FUN_00489aa0();
    }
    puStack_8 = (undefined *)0xffffffff;
    if (param_2 == 0) {
      uVar7 = 0;
      goto LAB_0041da59;
    }
    *(undefined4 *)(param_2 + 0x14) = unaff_EDI;
    uVar2 = *(uint *)(param_1 + 0x1c);
    uVar9 = *(int *)(param_1 + 0xc) + 1;
    if ((uVar2 < uVar9) && (uVar9 = func_0x00404700(uVar9), uVar2 < uVar9)) {
      uVar4 = uVar9;
      if (uVar9 == 0) {
        puVar10 = (undefined4 *)0x0;
        puVar11 = puVar10;
      }
      else {
        puVar10 = (undefined4 *)func_0x00763250(uVar9 * 4);
        puVar11 = puVar10;
      }
      for (; uVar4 != 0; uVar4 = uVar4 - 1) {
        if (puVar10 != (undefined4 *)0x0) {
          *puVar10 = 0;
        }
        puVar10 = puVar10 + 1;
      }
      if (uVar2 != 0) {
        do {
          puVar1 = (undefined4 *)(*(int *)(param_1 + 0x10) + uVar12 * 4);
          puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x10) + uVar12 * 4);
          while (puVar3 != (undefined4 *)0x0) {
            uVar4 = puVar3[2];
            *puVar1 = *puVar3;
            *puVar3 = puVar11[uVar4 % uVar9];
            puVar11[uVar4 % uVar9] = puVar3;
            puVar1 = (undefined4 *)(*(int *)(param_1 + 0x10) + uVar12 * 4);
            puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x10) + uVar12 * 4);
          }
          uVar12 = uVar12 + 1;
        } while (uVar12 < uVar2);
      }
      iVar6 = *(int *)(param_1 + 0x10);
      *(undefined4 **)(param_1 + 0x10) = puVar11;
      *(undefined4 **)(param_1 + 0x14) = puVar10;
      iVar13 = *(int *)(param_1 + 0x1c);
      *(uint *)(param_1 + 0x1c) = uVar9;
      *(uint *)(param_1 + 0x18) = uVar9;
      func_0x006e04e0(iVar6,iVar6 + iVar13 * 4);
      if (iVar6 != 0) {
        func_0x00763260(iVar6);
      }
    }
    uVar12 = unaff_retaddr % *(uint *)(param_1 + 0x1c);
    puVar10 = *(undefined4 **)(*(int *)(param_1 + 0x10) + uVar12 * 4);
    for (puVar11 = puVar10; puVar11 != (undefined4 *)0x0; puVar11 = (undefined4 *)*puVar11) {
      if (puVar11[2] == unaff_retaddr) goto LAB_0041da57;
    }
    puVar11 = (undefined4 *)func_0x00763250(0xc);
    if (puVar11 == (undefined4 *)0x0) {
      puVar11 = (undefined4 *)0x0;
    }
    else {
      puVar11[1] = param_2;
      puVar11[2] = unaff_retaddr;
      *puVar11 = puVar10;
    }
    *(undefined4 **)(*(int *)(param_1 + 0x10) + uVar12 * 4) = puVar11;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  }
  else {
    *(int *)(iVar6 + 0x10) = *(int *)(iVar6 + 0x10) + 1;
  }
LAB_0041da57:
  uVar7 = 1;
LAB_0041da59:
  *unaff_FS_OFFSET = uStack_10;
  return uVar7;
}


/* ==================================================================== */
/* Address: 0x0041da70 | Classified: elementclient::CECScene__LoadBoxArea__failed_to@0x41da70 */
/* ==================================================================== */

undefined4 __thiscall FUN_0041da70(int param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *unaff_FS_OFFSET;
  uint unaff_retaddr;
  undefined4 *puStack_1c;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a735b;
  *unaff_FS_OFFSET = &uStack_c;
  iVar5 = FUN_0041d3e0(param_2);
  uVar11 = 0;
  if (iVar5 == 0) {
    (**(code **)(*(int *)(param_1 + 0x2b4) + 0x30))(param_2,0);
    iVar5 = func_0x00763250(0x134);
    puStack_8 = (undefined *)0x0;
    if (iVar5 == 0) {
      param_2 = (undefined4 *)0x0;
    }
    else {
      param_2 = (undefined4 *)FUN_0048a3c0();
    }
    puStack_8 = (undefined *)0xffffffff;
    if (param_2 == (undefined4 *)0x0) {
      uVar6 = 0;
      goto LAB_0041dc99;
    }
    cVar4 = FUN_0048a510(param_1,param_1 + 0x2b4,*(undefined4 *)(param_1 + 0x580),
                         *(undefined4 *)(param_1 + 0x584));
    if (cVar4 == '\0') {
      (**(code **)*param_2)(1);
      func_0x00764590(1,0x950ebc);
      uVar6 = 0;
      goto LAB_0041dc99;
    }
    param_2[5] = unaff_retaddr;
    uVar1 = *(uint *)(param_1 + 0x34);
    uVar7 = *(int *)(param_1 + 0x24) + 1;
    if ((uVar1 < uVar7) && (uVar7 = func_0x00404700(uVar7), uVar1 < uVar7)) {
      if (uVar7 == 0) {
        puVar8 = (undefined4 *)0x0;
        puStack_1c = puVar8;
      }
      else {
        puVar8 = (undefined4 *)func_0x00763250(uVar7 * 4);
        uVar10 = uVar7;
        puStack_1c = puVar8;
        do {
          puVar9 = puStack_1c + 1;
          if (puStack_1c != (undefined4 *)0x0) {
            *puStack_1c = 0;
          }
          uVar10 = uVar10 - 1;
          puStack_1c = puVar9;
        } while (uVar10 != 0);
      }
      if (uVar1 != 0) {
        do {
          puVar9 = (undefined4 *)(*(int *)(param_1 + 0x28) + uVar11 * 4);
          puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x28) + uVar11 * 4);
          while (puVar2 != (undefined4 *)0x0) {
            uVar10 = puVar2[2];
            *puVar9 = *puVar2;
            *puVar2 = puVar8[uVar10 % uVar7];
            puVar8[uVar10 % uVar7] = puVar2;
            puVar9 = (undefined4 *)(*(int *)(param_1 + 0x28) + uVar11 * 4);
            puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x28) + uVar11 * 4);
          }
          uVar11 = uVar11 + 1;
        } while (uVar11 < uVar1);
      }
      iVar5 = *(int *)(param_1 + 0x28);
      *(undefined4 **)(param_1 + 0x28) = puVar8;
      *(undefined4 **)(param_1 + 0x2c) = puStack_1c;
      iVar3 = *(int *)(param_1 + 0x34);
      *(uint *)(param_1 + 0x34) = uVar7;
      *(uint *)(param_1 + 0x30) = uVar7;
      func_0x006e04e0(iVar5,iVar5 + iVar3 * 4);
      if (iVar5 != 0) {
        func_0x00763260(iVar5);
      }
    }
    uVar11 = unaff_retaddr % *(uint *)(param_1 + 0x34);
    puVar8 = *(undefined4 **)(*(int *)(param_1 + 0x28) + uVar11 * 4);
    for (puVar9 = puVar8; puVar9 != (undefined4 *)0x0; puVar9 = (undefined4 *)*puVar9) {
      if (puVar9[2] == unaff_retaddr) goto LAB_0041dc97;
    }
    puVar9 = (undefined4 *)func_0x00763250(0xc);
    if (puVar9 == (undefined4 *)0x0) {
      puVar9 = (undefined4 *)0x0;
    }
    else {
      puVar9[1] = param_2;
      puVar9[2] = unaff_retaddr;
      *puVar9 = puVar8;
    }
    *(undefined4 **)(*(int *)(param_1 + 0x28) + uVar11 * 4) = puVar9;
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
  }
  else {
    *(int *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x10) + 1;
  }
LAB_0041dc97:
  uVar6 = 1;
LAB_0041dc99:
  *unaff_FS_OFFSET = uStack_10;
  return uVar6;
}


/* ==================================================================== */
/* Address: 0x0041dcb0 | Classified: elementclient::CECScene__LoadGrassArea@0x41dcb0 */
/* ==================================================================== */

undefined1 __thiscall FUN_0041dcb0(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined4 unaff_EBX;
  int unaff_ESI;
  undefined4 **ppuVar11;
  undefined4 *puVar12;
  undefined4 **ppuVar13;
  undefined4 *unaff_FS_OFFSET;
  uint unaff_retaddr;
  undefined4 *puStack_88;
  undefined4 uStack_84;
  int iStack_70;
  undefined4 *puStack_6c;
  undefined4 uStack_68;
  int iStack_64;
  undefined4 uStack_60;
  undefined4 *apuStack_5c [4];
  float fStack_4c;
  undefined4 uStack_48;
  float fStack_44;
  float fStack_3c;
  undefined4 uStack_38;
  undefined4 *apuStack_34 [5];
  int iStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 *puStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a737b;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_84 = param_2;
  puStack_88 = (undefined4 *)0x41dcd8;
  iVar4 = FUN_0041d410();
  if (iVar4 == 0) {
    puStack_88 = (undefined4 *)0x20;
    iStack_64 = func_0x00763250();
    puStack_8 = (undefined *)0x0;
    if (iStack_64 == 0) {
      iStack_70 = 0;
    }
    else {
      puStack_88 = (undefined4 *)0x41dd03;
      iStack_70 = FUN_00489a70();
    }
    puStack_8 = (undefined *)0xffffffff;
    if (iStack_70 == 0) {
      uVar3 = 0;
      goto LAB_0041e144;
    }
    puStack_88 = (undefined4 *)0x0;
    (**(code **)(*(int *)(param_1 + 0x2b4) + 0x30))(param_2);
    if (*(int *)(param_1 + 0x4d4) < 7) {
      cVar2 = (**(code **)(*(int *)(param_1 + 0x2b4) + 0x10))(&iStack_64,0x1c);
      uVar3 = 0;
      if (cVar2 == '\0') goto LAB_0041e144;
      ppuVar11 = apuStack_5c;
      ppuVar13 = apuStack_34;
      for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
        *ppuVar13 = *ppuVar11;
        ppuVar11 = ppuVar11 + 1;
        ppuVar13 = ppuVar13 + 1;
      }
      uStack_18 = 0xffffffff;
      puStack_14 = (undefined4 *)0xffffffff;
    }
    else {
      cVar2 = (**(code **)(*(int *)(param_1 + 0x2b4) + 0x10))(&fStack_3c,0x24,&stack0xffffff84);
      uVar3 = 0;
      if (cVar2 == '\0') goto LAB_0041e144;
    }
    puStack_88 = apuStack_34[0];
    iStack_64 = func_0x004215d0();
    if (iStack_64 == 0) {
      uVar3 = 0;
      goto LAB_0041e144;
    }
    puVar12 = (undefined4 *)(iStack_1c * iStack_20 >> 3);
    puStack_88 = puVar12;
    iVar4 = func_0x00763250();
    if (iVar4 == 0) {
      puStack_88 = (undefined4 *)0x43d;
      func_0x0043c590(2,0x950fa8);
      uVar3 = 0;
      goto LAB_0041e144;
    }
    *(undefined4 *)(iStack_70 + 0x1c) = uStack_18;
    if (6 < *(int *)(param_1 + 0x4d4)) {
      puStack_88 = puStack_14;
      piVar5 = (int *)FUN_0041e750(uStack_18);
      if (piVar5 == (int *)0x0) {
        func_0x00764590(1,0x950f68);
        uVar3 = 0;
        goto LAB_0041e144;
      }
      uStack_4 = CONCAT31(uStack_4._1_3_,1);
      if ((uint)piVar5[6] < 2) {
        cVar2 = (**(code **)(*(int *)*piVar5 + 0x10))(iVar4,puVar12);
        goto joined_r0x0041df4c;
      }
      (**(code **)(*(int *)*piVar5 + 0x10))(&iStack_64,8,&stack0xffffff84);
      if (puStack_6c != puVar12) {
        func_0x00763260(iVar4);
        uVar3 = 0;
        goto LAB_0041e144;
      }
      if ((char)piVar5[7] == '\0') {
        cVar2 = (**(code **)(*(int *)*piVar5 + 0x10))(iVar4,puVar12,&puStack_88);
joined_r0x0041df4c:
        if (cVar2 != '\0') goto LAB_0041df54;
      }
      else {
        iVar6 = func_0x00763250(iStack_70);
        if (iVar6 != 0) {
          cVar2 = (**(code **)(*(int *)*piVar5 + 0x10))(iVar6,uStack_68,&stack0xffffff80);
          if (cVar2 == '\0') {
            puStack_14 = (undefined4 *)((uint)puStack_14 & 0xffffff00);
          }
          else {
            func_0x00771a40(uStack_84,unaff_EBX,iVar4,&stack0xffffff80);
          }
          func_0x00763260(uStack_84);
          cVar2 = (char)puStack_8;
          goto joined_r0x0041df4c;
        }
      }
      func_0x00763260(iVar4);
      func_0x00764590(1,0x950f24,*piVar5 + 0x10c);
      uVar3 = 0;
      goto LAB_0041e144;
    }
    puStack_88 = (undefined4 *)&stack0xffffff8c;
    cVar2 = (**(code **)(*(int *)(param_1 + 0x2b4) + 0x10))(iVar4,puVar12);
    unaff_ESI = iStack_70;
    if (cVar2 == '\0') {
      func_0x00763260(iVar4);
      uVar3 = 0;
      goto LAB_0041e144;
    }
LAB_0041df54:
    fStack_4c = fStack_3c + *(float *)(param_1 + 0x580);
    uStack_48 = uStack_38;
    fStack_44 = (float)apuStack_34[0] + *(float *)(param_1 + 0x584);
    cVar2 = func_0x006523f0(iVar4,&fStack_4c,apuStack_34[1],apuStack_34[2],apuStack_34[3],
                            &puStack_6c);
    if (cVar2 == '\0') {
      func_0x00763260(iVar4);
      func_0x00764590(1,0x950eec);
      uVar3 = 0;
      goto LAB_0041e144;
    }
    func_0x00763260(iVar4);
    *(undefined4 *)(unaff_ESI + 0x14) = uStack_60;
    *(undefined4 **)(unaff_ESI + 0x18) = apuStack_34[0];
    puStack_6c = *(undefined4 **)(param_1 + 0x4c);
    puVar12 = (undefined4 *)(*(int *)(param_1 + 0x3c) + 1);
    if (puStack_6c < puVar12) {
      iVar4 = 0;
      puVar7 = (uint *)&UNK_008d6750;
      do {
        if (puVar12 < (undefined4 *)*puVar7) {
          param_2 = *(undefined4 **)(&UNK_008d6750 + iVar4 * 4);
          goto LAB_0041e00f;
        }
        puVar7 = puVar7 + 1;
        iVar4 = iVar4 + 1;
      } while ((int)puVar7 < 0x8d67c0);
      param_2 = (undefined4 *)0xffffffff;
LAB_0041e00f:
      if (puStack_6c < param_2) {
        if (param_2 == (undefined4 *)0x0) {
          apuStack_5c[1] = (undefined4 *)0x0;
          puVar12 = apuStack_5c[1];
        }
        else {
          puStack_88 = (undefined4 *)((int)param_2 * 4);
          puVar12 = (undefined4 *)func_0x00763250();
          puVar8 = param_2;
          puVar9 = puVar12;
          do {
            apuStack_5c[1] = puVar9 + 1;
            if (puVar9 != (undefined4 *)0x0) {
              *puVar9 = 0;
            }
            puVar8 = (undefined4 *)((int)puVar8 - 1);
            puVar9 = apuStack_5c[1];
          } while (puVar8 != (undefined4 *)0x0);
        }
        puVar8 = (undefined4 *)0x0;
        if (puStack_6c != (undefined4 *)0x0) {
          do {
            puVar9 = (undefined4 *)(*(int *)(param_1 + 0x40) + (int)puVar8 * 4);
            puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x40) + (int)puVar8 * 4);
            while (puVar1 != (undefined4 *)0x0) {
              uVar10 = puVar1[2];
              *puVar9 = *puVar1;
              *puVar1 = puVar12[uVar10 % (uint)param_2];
              puVar12[uVar10 % (uint)param_2] = puVar1;
              puVar9 = (undefined4 *)(*(int *)(param_1 + 0x40) + (int)puVar8 * 4);
              puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x40) + (int)puVar8 * 4);
            }
            puVar8 = (undefined4 *)((int)puVar8 + 1);
          } while (puVar8 < puStack_6c);
        }
        puStack_88 = *(undefined4 **)(param_1 + 0x40);
        *(undefined4 **)(param_1 + 0x40) = puVar12;
        puVar8 = *(undefined4 **)(param_1 + 0x44);
        *(undefined4 **)(param_1 + 0x44) = apuStack_5c[1];
        iVar4 = *(int *)(param_1 + 0x4c);
        *(undefined4 **)(param_1 + 0x4c) = param_2;
        *(undefined4 **)(param_1 + 0x48) = param_2;
        puVar12 = puStack_88 + iVar4;
        puVar9 = puStack_88;
        if (puStack_88 != puVar12) {
          for (; puVar12 < puVar8; puVar12 = puVar12 + 1) {
            *puVar9 = *puVar12;
            puVar9 = puVar9 + 1;
          }
        }
        if (puStack_88 != (undefined4 *)0x0) {
          func_0x00763260();
        }
      }
    }
    uVar10 = unaff_retaddr % *(uint *)(param_1 + 0x4c);
    puVar12 = *(undefined4 **)(*(int *)(param_1 + 0x40) + uVar10 * 4);
    for (puVar8 = puVar12; puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {
      if (puVar8[2] == unaff_retaddr) goto LAB_0041e142;
    }
    puStack_88 = (undefined4 *)0xc;
    puVar8 = (undefined4 *)func_0x00763250();
    if (puVar8 == (undefined4 *)0x0) {
      puVar8 = (undefined4 *)0x0;
    }
    else {
      puVar8[2] = unaff_retaddr;
      puVar8[1] = iStack_70;
      *puVar8 = puVar12;
    }
    *(undefined4 **)(*(int *)(param_1 + 0x40) + uVar10 * 4) = puVar8;
    *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
  }
  else {
    *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
  }
LAB_0041e142:
  uVar3 = 1;
LAB_0041e144:
  *unaff_FS_OFFSET = uStack_10;
  return uVar3;
}


/* ==================================================================== */
/* Address: 0x0041e160 | Classified: elementclient::CECScene__LoadCritterGroup__fail@0x41e160 */
/* ==================================================================== */

undefined4 __thiscall FUN_0041e160(int param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *unaff_FS_OFFSET;
  uint unaff_retaddr;
  undefined4 *puStack_1c;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a739b;
  *unaff_FS_OFFSET = &uStack_c;
  iVar5 = FUN_0041d440(param_2);
  uVar11 = 0;
  if (iVar5 == 0) {
    (**(code **)(*(int *)(param_1 + 0x2b4) + 0x30))(param_2,0);
    iVar5 = func_0x00763250(0x50);
    puStack_8 = (undefined *)0x0;
    if (iVar5 == 0) {
      param_2 = (undefined4 *)0x0;
    }
    else {
      param_2 = (undefined4 *)FUN_00488fa0();
    }
    puStack_8 = (undefined *)0xffffffff;
    if (param_2 == (undefined4 *)0x0) {
      uVar6 = 0;
      goto LAB_0041e386;
    }
    cVar4 = FUN_004890e0(param_1,param_1 + 0x2b4,*(undefined4 *)(param_1 + 0x580),
                         *(undefined4 *)(param_1 + 0x584));
    if (cVar4 == '\0') {
      (**(code **)*param_2)(1);
      func_0x00764590(1,0x950fc0);
      uVar6 = 0;
      goto LAB_0041e386;
    }
    param_2[6] = unaff_retaddr;
    uVar1 = *(uint *)(param_1 + 100);
    uVar7 = *(int *)(param_1 + 0x54) + 1;
    if ((uVar1 < uVar7) && (uVar7 = func_0x00404700(uVar7), uVar1 < uVar7)) {
      if (uVar7 == 0) {
        puVar8 = (undefined4 *)0x0;
        puStack_1c = puVar8;
      }
      else {
        puVar8 = (undefined4 *)func_0x00763250(uVar7 * 4);
        uVar10 = uVar7;
        puStack_1c = puVar8;
        do {
          puVar9 = puStack_1c + 1;
          if (puStack_1c != (undefined4 *)0x0) {
            *puStack_1c = 0;
          }
          uVar10 = uVar10 - 1;
          puStack_1c = puVar9;
        } while (uVar10 != 0);
      }
      if (uVar1 != 0) {
        do {
          puVar9 = (undefined4 *)(*(int *)(param_1 + 0x58) + uVar11 * 4);
          puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x58) + uVar11 * 4);
          while (puVar2 != (undefined4 *)0x0) {
            uVar10 = puVar2[2];
            *puVar9 = *puVar2;
            *puVar2 = puVar8[uVar10 % uVar7];
            puVar8[uVar10 % uVar7] = puVar2;
            puVar9 = (undefined4 *)(*(int *)(param_1 + 0x58) + uVar11 * 4);
            puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x58) + uVar11 * 4);
          }
          uVar11 = uVar11 + 1;
        } while (uVar11 < uVar1);
      }
      iVar5 = *(int *)(param_1 + 0x58);
      *(undefined4 **)(param_1 + 0x58) = puVar8;
      *(undefined4 **)(param_1 + 0x5c) = puStack_1c;
      iVar3 = *(int *)(param_1 + 100);
      *(uint *)(param_1 + 100) = uVar7;
      *(uint *)(param_1 + 0x60) = uVar7;
      func_0x006e04e0(iVar5,iVar5 + iVar3 * 4);
      if (iVar5 != 0) {
        func_0x00763260(iVar5);
      }
    }
    uVar11 = unaff_retaddr % *(uint *)(param_1 + 100);
    puVar8 = *(undefined4 **)(*(int *)(param_1 + 0x58) + uVar11 * 4);
    for (puVar9 = puVar8; puVar9 != (undefined4 *)0x0; puVar9 = (undefined4 *)*puVar9) {
      if (puVar9[2] == unaff_retaddr) goto LAB_0041e384;
    }
    puVar9 = (undefined4 *)func_0x00763250(0xc);
    if (puVar9 == (undefined4 *)0x0) {
      puVar9 = (undefined4 *)0x0;
    }
    else {
      puVar9[1] = param_2;
      puVar9[2] = unaff_retaddr;
      *puVar9 = puVar8;
    }
    *(undefined4 **)(*(int *)(param_1 + 0x58) + uVar11 * 4) = puVar9;
    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
  }
  else {
    *(int *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x10) + 1;
  }
LAB_0041e384:
  uVar6 = 1;
LAB_0041e386:
  *unaff_FS_OFFSET = uStack_10;
  return uVar6;
}


/* ==================================================================== */
/* Address: 0x0041e3a0 | Classified: elementclient::LitModels_Login@0x41e3a0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0041e3a0(undefined1 *param_1,undefined1 *param_2)

{
  int iVar1;
  undefined1 *puStack_124;
  undefined1 *puStack_120;
  undefined1 *puStack_11c;
  undefined1 *puStack_118;
  undefined1 auStack_108 [4];
  undefined1 auStack_104 [240];
  undefined4 *puStack_14;
  
  if (3 < *(int *)(param_1 + 0x4d0)) {
    puStack_118 = param_2;
    puStack_11c = (undefined1 *)0x41e3c0;
    iVar1 = FUN_0041d3b0();
    if (iVar1 != 0) {
      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1;
      return 1;
    }
    puStack_11c = (undefined1 *)0x0;
    puStack_120 = param_2;
    puStack_124 = (undefined1 *)0x41e3f1;
    (**(code **)(*(int *)(param_1 + 0x2b4) + 0x30))();
  }
  if (*(int *)(*(int *)(_DAT_009b3eec + 0x1c) + 0x90) == 1) {
    puStack_11c = auStack_104;
    puStack_118 = (undefined1 *)0x950ffc;
    puStack_120 = (undefined1 *)0x41e412;
    sprintf();
  }
  else {
    puStack_118 = *(undefined1 **)(*(int *)(param_1 + 4) + 0x90);
    puStack_11c = (undefined1 *)0x41e426;
    iVar1 = func_0x00438660();
    if (iVar1 == 0) {
      return 0;
    }
    puStack_11c = *(undefined1 **)(iVar1 + 8);
    puStack_124 = auStack_108;
    puStack_120 = (undefined1 *)0x950600;
    sprintf();
  }
  puStack_118 = (undefined1 *)0x41e456;
  func_0x006450d0();
  puStack_118 = *(undefined1 **)(param_1 + 0x584);
  puStack_11c = *(undefined1 **)(param_1 + 0x580);
  puStack_120 = auStack_104;
  puStack_124 = param_1;
  iVar1 = FUN_005b2cb0(param_2);
  if (iVar1 == 0) {
    return 0;
  }
  puStack_120 = *(undefined1 **)(iVar1 + 0x40);
  puStack_11c = (undefined1 *)iVar1;
  func_0x00421ac0(*(int *)(param_1 + 0x6c) + 1);
  func_0x0064c9f0(&puStack_124,&puStack_120);
  if (puStack_14 != (undefined4 *)0x0) {
    *puStack_14 = *(undefined4 *)(iVar1 + 0x40);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0041e4d0 | Classified: ElementClient::proc_41e4d0 */
/* ==================================================================== */

undefined4 __fastcall FUN_0041e4d0(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *unaff_FS_OFFSET;
  uint unaff_retaddr;
  undefined4 *puStack00000004;
  undefined4 *puStack_1c;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a73bb;
  *unaff_FS_OFFSET = &uStack_c;
  iVar4 = FUN_0041d470();
  uVar10 = 0;
  if (iVar4 == 0) {
    (**(code **)(*(int *)(param_1 + 0x2b4) + 0x30))();
    iVar4 = func_0x00763250();
    puStack_8 = (undefined *)0x0;
    if (iVar4 == 0) {
      puStack00000004 = (undefined4 *)0x0;
    }
    else {
      puStack00000004 = (undefined4 *)func_0x004885a0();
    }
    puStack_8 = (undefined *)0xffffffff;
    if (puStack00000004 == (undefined4 *)0x0) {
      uVar5 = 0;
      goto LAB_0041e737;
    }
    cVar3 = func_0x004886a0();
    if (cVar3 == '\0') {
      (**(code **)*puStack00000004)();
      func_0x00764590();
      uVar5 = 0;
      goto LAB_0041e737;
    }
    func_0x00488b10();
    uVar1 = *(uint *)(param_1 + 0x94);
    if ((uVar1 < *(int *)(param_1 + 0x84) + 1U) && (uVar6 = func_0x00404700(), uVar1 < uVar6)) {
      if (uVar6 == 0) {
        puVar7 = (undefined4 *)0x0;
        puStack_1c = puVar7;
      }
      else {
        puVar7 = (undefined4 *)func_0x00763250();
        uVar9 = uVar6;
        puStack_1c = puVar7;
        do {
          puVar8 = puStack_1c + 1;
          if (puStack_1c != (undefined4 *)0x0) {
            *puStack_1c = 0;
          }
          uVar9 = uVar9 - 1;
          puStack_1c = puVar8;
        } while (uVar9 != 0);
      }
      if (uVar1 != 0) {
        do {
          puVar8 = (undefined4 *)(*(int *)(param_1 + 0x88) + uVar10 * 4);
          puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x88) + uVar10 * 4);
          while (puVar2 != (undefined4 *)0x0) {
            uVar9 = puVar2[2];
            *puVar8 = *puVar2;
            *puVar2 = puVar7[uVar9 % uVar6];
            puVar7[uVar9 % uVar6] = puVar2;
            puVar8 = (undefined4 *)(*(int *)(param_1 + 0x88) + uVar10 * 4);
            puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x88) + uVar10 * 4);
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < uVar1);
      }
      iVar4 = *(int *)(param_1 + 0x88);
      *(undefined4 **)(param_1 + 0x88) = puVar7;
      *(undefined4 **)(param_1 + 0x8c) = puStack_1c;
      *(uint *)(param_1 + 0x94) = uVar6;
      *(uint *)(param_1 + 0x90) = uVar6;
      func_0x006e04e0();
      if (iVar4 != 0) {
        func_0x00763260();
      }
    }
    uVar10 = unaff_retaddr % *(uint *)(param_1 + 0x94);
    puVar7 = *(undefined4 **)(*(int *)(param_1 + 0x88) + uVar10 * 4);
    for (puVar8 = puVar7; puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {
      if (puVar8[2] == unaff_retaddr) goto LAB_0041e735;
    }
    puVar8 = (undefined4 *)func_0x00763250();
    if (puVar8 == (undefined4 *)0x0) {
      puVar8 = (undefined4 *)0x0;
    }
    else {
      puVar8[1] = puStack00000004;
      puVar8[2] = unaff_retaddr;
      *puVar8 = puVar7;
    }
    *(undefined4 **)(*(int *)(param_1 + 0x88) + uVar10 * 4) = puVar8;
    *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
  }
  else {
    *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
  }
LAB_0041e735:
  uVar5 = 1;
LAB_0041e737:
  *unaff_FS_OFFSET = uStack_10;
  return uVar5;
}


/* ==================================================================== */
/* Address: 0x0041e750 | Classified: elementclient::CECScene__PrepareSubTerrainData_@0x41e750 */
/* ==================================================================== */

int * __thiscall FUN_0041e750(int param_1,int param_2,int param_3)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  uint unaff_ESI;
  int *unaff_FS_OFFSET;
  int iVar5;
  uint **ppuStack_48;
  int iStack_44;
  undefined1 *puStack_40;
  undefined1 *puStack_3c;
  undefined4 uStack_38;
  uint *puStack_34;
  int iStack_30;
  undefined1 uStack_20;
  undefined1 auStack_18 [4];
  int iStack_14;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a73eb;
  *unaff_FS_OFFSET = (int)&iStack_c;
  piVar1 = *(int **)(*(int *)(param_1 + 0x8e4) + param_2 * 4);
  if ((int *)*piVar1 != (int *)0x0) {
    iStack_30 = 0;
    piVar1[1] = piVar1[1] + 1;
    puStack_34 = *(uint **)(piVar1[3] + param_3 * 4);
    uStack_38 = 0x41e799;
    (**(code **)(*(int *)*piVar1 + 0x30))();
LAB_0041e98e:
    *unaff_FS_OFFSET = iStack_14;
    return piVar1;
  }
  iStack_30 = 0x21c;
  puStack_34 = (uint *)0x41e7a8;
  iStack_14 = func_0x00763250();
  uStack_4 = 0;
  if (iStack_14 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    iStack_30 = 0x41e7c2;
    piVar3 = (int *)func_0x0076e410();
  }
  uStack_4 = 0xffffffff;
  if (piVar3 != (int *)0x0) {
    iStack_30 = *(int *)(*(int *)(param_1 + 4) + 0x74);
    puStack_34 = (uint *)0x41e7e8;
    func_0x007636b0();
    puStack_3c = auStack_18;
    uStack_38 = 0x9510b0;
    puStack_8 = (undefined *)0x1;
    puStack_40 = (undefined1 *)0x41e803;
    puStack_34 = (uint *)(piVar1 + 4);
    puStack_34 = (uint *)FUN_0041e9b0();
    puStack_8 = (undefined *)CONCAT31(puStack_8._1_3_,2);
    uStack_38 = 0x41e815;
    func_0x00763b30();
    iStack_c = CONCAT31(iStack_c._1_3_,1);
    uStack_38 = 0x41e823;
    func_0x007637f0();
    uStack_38 = 0x11;
    puStack_3c = (undefined1 *)uStack_4;
    puStack_40 = (undefined1 *)0x41e831;
    cVar2 = (**(code **)(*piVar3 + 8))();
    if (cVar2 == '\0') {
      puStack_40 = (undefined1 *)piVar1[4];
      iStack_44 = 0x951078;
    }
    else {
      puStack_40 = &stack0xffffffd4;
      ppuStack_48 = (uint **)&stack0xffffffd8;
      iStack_44 = 4;
      (**(code **)(*piVar3 + 0x10))();
      if (unaff_ESI < 3) {
        if (unaff_ESI < 2) {
          *(undefined1 *)(piVar1 + 7) = 0;
        }
        else {
          puStack_40 = (undefined1 *)0x0;
          iStack_44 = 4;
          ppuStack_48 = (uint **)0x41e8a6;
          (**(code **)(*piVar3 + 0x30))();
          ppuStack_48 = &puStack_34;
          (**(code **)(*piVar3 + 0x10))(&stack0xffffffd4,8);
          *(undefined1 *)(piVar1 + 7) = uStack_20;
        }
        *piVar1 = (int)piVar3;
        piVar1[6] = unaff_ESI;
        puStack_40 = (undefined1 *)0x2;
        iStack_44 = -4;
        ppuStack_48 = (uint **)0x41e8d4;
        (**(code **)(*piVar3 + 0x30))();
        ppuStack_48 = &puStack_34;
        iVar5 = 4;
        (**(code **)(*piVar3 + 0x10))(&uStack_38,4);
        iVar4 = func_0x00763250(iStack_44 * 4);
        piVar1[3] = iVar4;
        if (iVar4 == 0) {
          func_0x007637f0();
          *unaff_FS_OFFSET = iStack_30;
          return (int *)0x0;
        }
        iVar4 = (-1 - iStack_44) * 4;
        (**(code **)(*piVar3 + 0x30))(iVar4,2);
        (**(code **)(*piVar3 + 0x10))(piVar1[3],iVar5 * 4,&ppuStack_48);
        piVar1[1] = 1;
        piVar1[2] = iVar4;
        (**(code **)(*piVar3 + 0x30))(*(undefined4 *)(piVar1[3] + iStack_30 * 4),0);
        iStack_44 = 0xffffffff;
        func_0x007637f0();
        goto LAB_0041e98e;
      }
      iStack_44 = 0x951040;
      puStack_40 = (undefined1 *)unaff_ESI;
    }
    ppuStack_48 = (uint **)0x1;
    func_0x00764590();
    iStack_14 = 0xffffffff;
    puStack_40 = (undefined1 *)0x41e87d;
    func_0x007637f0();
  }
  *unaff_FS_OFFSET = iStack_c;
  return (int *)0x0;
}


/* ==================================================================== */
/* Address: 0x0041e9b0 | Classified: ElementClient::proc_41e9b0 */
/* ==================================================================== */

undefined4 FUN_0041e9b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  func_0x00763770(param_2,param_3);
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0041e9e0 | Classified: ElementClient::proc_41e9e0 */
/* ==================================================================== */

void __thiscall FUN_0041e9e0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if (((6 < *(int *)(param_1 + 0x4d4)) &&
      (piVar1 = *(int **)(*(int *)(param_1 + 0x8e4) + param_2 * 4), *piVar1 != 0)) &&
     (iVar2 = piVar1[1], piVar1[1] = iVar2 + -1, iVar2 + -1 == 0)) {
    iVar2 = func_0x00763330();
    piVar1[5] = iVar2;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0041ea20 | Classified: ElementClient::proc_41ea20 */
/* ==================================================================== */

void __fastcall FUN_0041ea20(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = func_0x00763330();
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x8e8)) {
    do {
      piVar1 = *(int **)(*(int *)(param_1 + 0x8e4) + iVar3 * 4);
      if ((((int *)*piVar1 != (int *)0x0) && (piVar1[1] == 0)) &&
         (19999 < (uint)(iVar2 - piVar1[5]))) {
        (**(code **)(*(int *)*piVar1 + 0xc))();
        if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)*piVar1)(1);
        }
        func_0x00763260(piVar1[3]);
        *piVar1 = 0;
        piVar1[3] = 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x8e8));
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0041eaa0 | Classified: ElementClient::proc_41eaa0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0041eaa0(int param_1)

{
  undefined4 **ppuVar1;
  undefined4 uVar2;
  bool bVar3;
  undefined4 ****ppppuVar4;
  char cVar5;
  undefined4 *puVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  float fVar11;
  float fVar12;
  undefined4 uVar13;
  int *piVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fStack_3b0;
  float fStack_3ac;
  undefined4 uStack_3a8;
  float fStack_3a4;
  float fStack_3a0;
  float fStack_39c;
  float fStack_398;
  float fStack_394;
  float fStack_390;
  float fStack_38c;
  float fStack_388;
  float fStack_384;
  float fStack_380;
  float fStack_37c;
  float fStack_378;
  float fStack_374;
  float fStack_370;
  float fStack_36c;
  float fStack_368;
  float fStack_364;
  float fStack_360;
  float fStack_35c;
  float fStack_358;
  float fStack_354;
  undefined4 *puStack_350;
  float **ppfStack_34c;
  float fStack_348;
  float fStack_344;
  float fStack_340;
  float fStack_33c;
  float fStack_338;
  float fStack_334;
  float fStack_330;
  float fStack_32c;
  float fStack_328;
  float fStack_324;
  float fStack_320;
  undefined4 *puStack_31c;
  float fStack_318;
  float fStack_314;
  float fStack_310;
  float fStack_30c;
  undefined4 uStack_308;
  float fStack_304;
  undefined4 uStack_300;
  undefined4 uStack_2fc;
  float fStack_2f8;
  undefined4 uStack_2f4;
  float *pfStack_2f0;
  undefined4 uStack_2ec;
  int iStack_2e8;
  undefined4 uStack_2e4;
  int iStack_2e0;
  undefined4 uStack_2dc;
  undefined4 uStack_2d8;
  undefined4 *puStack_2d4;
  float fStack_2d0;
  float fStack_2cc;
  float fStack_2c8;
  float fStack_2c4;
  undefined4 uStack_2c0;
  undefined4 uStack_2bc;
  undefined4 uStack_2b8;
  undefined4 uStack_2b4;
  float fStack_2b0;
  undefined4 uStack_2ac;
  float *pfStack_2a8;
  undefined4 uStack_2a4;
  undefined4 uStack_2a0;
  undefined4 uStack_29c;
  undefined4 uStack_298;
  undefined4 uStack_294;
  undefined4 uStack_290;
  undefined4 *puStack_28c;
  float fStack_288;
  float fStack_284;
  float fStack_280;
  float fStack_27c;
  undefined4 uStack_278;
  undefined4 uStack_274;
  undefined4 uStack_270;
  undefined4 uStack_26c;
  float fStack_268;
  undefined4 uStack_264;
  undefined4 ****ppppuStack_260;
  undefined4 ***pppuStack_25c;
  int iStack_258;
  int iStack_254;
  float *pfStack_250;
  undefined4 ****ppppuStack_24c;
  int iStack_248;
  float *pfStack_244;
  undefined4 ****ppppuStack_240;
  float fStack_23c;
  undefined4 ***pppuStack_238;
  undefined4 ****ppppuStack_234;
  undefined4 **ppuStack_230;
  undefined4 ****ppppuStack_22c;
  undefined4 ****ppppuStack_228;
  float fStack_224;
  undefined4 ****ppppuStack_220;
  float fStack_21c;
  undefined4 ***pppuStack_218;
  undefined4 ****ppppuStack_214;
  undefined4 ****ppppuStack_210;
  undefined4 ****ppppuStack_20c;
  undefined1 ****ppppuStack_208;
  float fStack_204;
  undefined4 ****ppppuStack_200;
  float *pfStack_1fc;
  undefined4 ***pppuStack_1f8;
  undefined4 ****ppppuStack_1f4;
  undefined4 ****ppppuStack_1f0;
  undefined4 ****ppppuStack_1ec;
  undefined1 ***pppuStack_1e8;
  undefined4 **ppuStack_1e4;
  undefined4 ****ppppuStack_1e0;
  float fStack_1dc;
  undefined4 ***pppuStack_1d8;
  undefined4 ***pppuStack_1d4;
  undefined4 ****ppppuStack_1d0;
  undefined4 ****ppppuStack_1cc;
  undefined1 **ppuStack_1c8;
  undefined4 ****ppppuStack_1c4;
  undefined4 ****ppppuStack_1c0;
  undefined4 ****ppppuStack_1bc;
  undefined4 ***pppuStack_1b8;
  undefined4 ****ppppuStack_1b4;
  undefined4 ***pppuStack_1b0;
  undefined4 **ppuStack_1ac;
  undefined1 *puStack_1a8;
  undefined4 ***pppuStack_1a4;
  undefined4 ****ppppuStack_1a0;
  undefined4 **ppuStack_19c;
  undefined4 **ppuStack_198;
  undefined4 *puStack_194;
  undefined1 auStack_180 [4];
  undefined4 **ppuStack_17c;
  undefined4 *puStack_178;
  undefined4 ***pppuStack_174;
  undefined4 ****ppppuStack_170;
  undefined4 **ppuStack_16c;
  undefined1 *puStack_168;
  undefined4 uStack_164;
  undefined4 **ppuStack_160;
  undefined4 uStack_15c;
  undefined4 *puStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined1 uStack_141;
  float fStack_140;
  float fStack_13c;
  int iStack_12c;
  int *piStack_128;
  int *piStack_124;
  int iStack_120;
  undefined4 **ppuStack_110;
  undefined4 uStack_10c;
  undefined4 **ppuStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 **ppuStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  uint uStack_c;
  char cStack_4;
  
  uStack_f4 = *(undefined4 *)(_DAT_009b3eec + 8);
  puStack_194 = (undefined4 *)0x41eac7;
  puVar6 = (undefined4 *)func_0x007744f0();
  uStack_10c = *puVar6;
  ppuStack_108 = (undefined4 **)puVar6[1];
  uStack_104 = puVar6[2];
  uStack_100 = uStack_10c;
  ppuStack_fc = ppuStack_108;
  uStack_f8 = uStack_104;
  if (*(int *)(*(int *)(_DAT_009b3eec + 0x1c) + 0x90) != 1) {
    ppuStack_198 = (undefined4 **)&uStack_164;
    puStack_194 = (undefined4 *)0x3;
    ppuStack_19c = (undefined4 **)0x41eb36;
    func_0x00421500();
    uStack_100 = uStack_164;
    ppuStack_fc = ppuStack_160;
    uStack_f8 = uStack_15c;
  }
  if (*(int *)(*(int *)(param_1 + 4) + 0x10) == 0) {
    uStack_141 = 0;
  }
  else {
    puStack_194 = &uStack_10c;
    ppuStack_198 = (undefined4 **)0x41eb6e;
    uStack_141 = FUN_00780790();
  }
  ppuVar1 = (undefined4 **)(param_1 + 0x20);
  iStack_12c = 0;
  ppuStack_198 = (undefined4 **)0x41eb8e;
  puStack_194 = ppuVar1;
  func_0x00413170();
  ppuStack_198 = (undefined4 **)0x0;
  ppppuStack_1a0 = (undefined4 ****)0x41eb99;
  ppuStack_19c = ppuVar1;
  func_0x0069d760();
  ppppuStack_1a0 = &ppppuStack_170;
  pppuStack_1a4 = (undefined4 ***)0x41eba7;
  cVar5 = func_0x005763f0();
  fVar15 = 0.0;
  fVar23 = 0.0;
  if (cVar5 == '\0') {
    do {
      if (piStack_124 == (int *)0x0) {
        pfVar7 = (float *)0x0;
      }
      else {
        pfVar7 = (float *)(iStack_120 + 4);
      }
      fVar23 = *pfVar7;
      pppuStack_1a4 = &ppuStack_110;
      puStack_1a8 = (undefined1 *)0x41ebd7;
      cVar5 = func_0x00774d40();
      fVar16 = fVar15;
      if ((cVar5 != '\0') && (fVar16 = fVar23, *(char *)((int)fVar23 + 0x18) != '\0')) {
        fVar16 = fVar15;
        fStack_140 = fVar23;
      }
      piVar14 = piStack_128;
      if (piStack_128 != (int *)0x0) {
        do {
          while (piStack_124 != (int *)0x0) {
            piStack_124 = (int *)*piStack_124;
            if (piStack_124 != (int *)0x0) goto LAB_0041ec3b;
          }
          piVar14 = piVar14 + 1;
          if (piVar14 == (int *)(*(int *)(iStack_12c + 8) + *(int *)(iStack_12c + 0x14) * 4)) {
            piStack_128 = (int *)0x0;
            break;
          }
          piStack_124 = (int *)*piVar14;
          piStack_128 = piVar14;
        } while (piStack_124 == (int *)0x0);
      }
LAB_0041ec3b:
      puStack_1a8 = (undefined1 *)0x0;
      pppuStack_1b0 = (undefined4 ***)0x41ec47;
      ppuStack_1ac = ppuVar1;
      func_0x0069d760();
      pppuStack_1b0 = (undefined4 ***)auStack_180;
      ppppuStack_1b4 = (undefined4 ****)0x41ec55;
      cVar5 = func_0x005763f0();
      fVar15 = fVar16;
    } while (cVar5 == '\0');
    fVar23 = fStack_13c;
    if (fVar16 == 0.0) goto LAB_0041ec65;
  }
  else {
LAB_0041ec65:
    fVar16 = fVar23;
    if (fVar16 == 0.0) {
      return 0;
    }
  }
  fStack_140 = _DAT_008d5c28 - *(float *)(*(int *)(*(int *)(param_1 + 4) + 0x50) + 0x70);
  if (cStack_4 == '\0') {
    if (*(int *)(param_1 + 0x590) == *(int *)((int)fVar16 + 0x14)) {
      ppppuStack_170 = (undefined4 *****)0x0;
      puStack_1a8 = *(undefined1 **)(param_1 + 0x5b4);
      ppuStack_1ac = *(undefined4 ***)(param_1 + 0x5a4);
      pppuStack_1b0 = (undefined4 ***)(param_1 + 0x594);
      ppppuVar4 = (undefined4 ****)((float)uStack_c * _DAT_008d5ef8);
      ppppuStack_1b4 = (undefined4 ****)0x41fe03;
      pppuStack_1a4 = ppppuVar4;
      pppuStack_174 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1b8 = *(undefined4 ****)(param_1 + 0x5b8);
      ppppuStack_1bc = *(undefined4 *****)(param_1 + 0x5a8);
      ppppuStack_1c0 = (undefined4 ****)(param_1 + 0x598);
      ppppuStack_1c4 = (undefined4 ****)0x41fe15;
      ppppuStack_1b4 = ppppuVar4;
      func_0x00421e80();
      ppuStack_1c8 = *(undefined1 ***)(param_1 + 0x5bc);
      ppppuStack_1cc = *(undefined4 *****)(param_1 + 0x5ac);
      ppppuStack_1d0 = (undefined4 ****)(param_1 + 0x59c);
      pppuStack_1d4 = (undefined4 ***)0x41fe27;
      ppppuStack_1c4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1d8 = *(undefined4 ****)(param_1 + 0x5c0);
      fStack_1dc = *(float *)(param_1 + 0x5b0);
      ppppuStack_1e0 = (undefined4 ****)(param_1 + 0x5a0);
      ppuStack_1e4 = (undefined4 **)0x41fe39;
      pppuStack_1d4 = ppppuVar4;
      func_0x00421e80();
      puStack_1a8 = *(undefined1 **)(param_1 + 0x5cc);
      ppuStack_1ac = *(undefined4 ***)(param_1 + 0x5c8);
      pppuStack_1b0 = (undefined4 ***)(param_1 + 0x5c4);
      ppppuStack_1b4 = (undefined4 ****)0x41fe57;
      pppuStack_1a4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1b8 = *(undefined4 ****)(param_1 + 0x5d8);
      ppppuStack_1bc = *(undefined4 *****)(param_1 + 0x5d4);
      ppppuStack_1c0 = (undefined4 ****)(param_1 + 0x5d0);
      ppppuStack_1c4 = (undefined4 ****)0x41fe72;
      ppppuStack_1b4 = ppppuVar4;
      func_0x00421e80();
      ppuStack_1c8 = *(undefined1 ***)(param_1 + 0x5e4);
      ppppuStack_1cc = *(undefined4 *****)(param_1 + 0x5e0);
      ppppuStack_1d0 = (undefined4 ****)(param_1 + 0x5dc);
      pppuStack_1d4 = (undefined4 ***)0x41fe8d;
      ppppuStack_1c4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1d8 = *(undefined4 ****)(param_1 + 0x608);
      fStack_1dc = *(float *)(param_1 + 0x5f8);
      ppppuStack_1e0 = (undefined4 ****)(param_1 + 0x5e8);
      ppuStack_1e4 = (undefined4 **)0x41fea8;
      pppuStack_1d4 = ppppuVar4;
      func_0x00421e80();
      puStack_1a8 = *(undefined1 **)(param_1 + 0x60c);
      ppuStack_1ac = *(undefined4 ***)(param_1 + 0x5fc);
      pppuStack_1b0 = (undefined4 ***)(param_1 + 0x5ec);
      ppppuStack_1b4 = (undefined4 ****)0x41febd;
      pppuStack_1a4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1b8 = *(undefined4 ****)(param_1 + 0x610);
      ppppuStack_1bc = *(undefined4 *****)(param_1 + 0x600);
      ppppuStack_1c0 = (undefined4 ****)(param_1 + 0x5f0);
      ppppuStack_1c4 = (undefined4 ****)0x41fecf;
      ppppuStack_1b4 = ppppuVar4;
      func_0x00421e80();
      ppuStack_1c8 = *(undefined1 ***)(param_1 + 0x614);
      ppppuStack_1cc = *(undefined4 *****)(param_1 + 0x604);
      ppppuStack_1d0 = (undefined4 ****)(param_1 + 0x5f4);
      pppuStack_1d4 = (undefined4 ***)0x41fee1;
      ppppuStack_1c4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1d8 = *(undefined4 ****)(param_1 + 0x620);
      fStack_1dc = *(float *)(param_1 + 0x61c);
      ppppuStack_1e0 = (undefined4 ****)(param_1 + 0x618);
      ppuStack_1e4 = (undefined4 **)0x41fefc;
      pppuStack_1d4 = ppppuVar4;
      func_0x00421e80();
      puStack_1a8 = *(undefined1 **)(param_1 + 0x62c);
      ppuStack_1ac = *(undefined4 ***)(param_1 + 0x628);
      pppuStack_1b0 = (undefined4 ***)(param_1 + 0x624);
      ppppuStack_1b4 = (undefined4 ****)0x41ff1a;
      pppuStack_1a4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1b8 = *(undefined4 ****)(param_1 + 0x638);
      ppppuStack_1bc = *(undefined4 *****)(param_1 + 0x634);
      ppppuStack_1c0 = (undefined4 ****)(param_1 + 0x630);
      ppppuStack_1c4 = (undefined4 ****)0x41ff35;
      ppppuStack_1b4 = ppppuVar4;
      func_0x00421e80();
      ppuStack_1c8 = *(undefined1 ***)(param_1 + 0x65c);
      ppppuStack_1cc = *(undefined4 *****)(param_1 + 0x64c);
      ppppuStack_1d0 = (undefined4 ****)(param_1 + 0x63c);
      pppuStack_1d4 = (undefined4 ***)0x41ff50;
      ppppuStack_1c4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1d8 = *(undefined4 ****)(param_1 + 0x660);
      fStack_1dc = *(float *)(param_1 + 0x650);
      ppppuStack_1e0 = (undefined4 ****)(param_1 + 0x640);
      ppuStack_1e4 = (undefined4 **)0x41ff62;
      pppuStack_1d4 = ppppuVar4;
      func_0x00421e80();
      puStack_1a8 = *(undefined1 **)(param_1 + 0x664);
      ppuStack_1ac = *(undefined4 ***)(param_1 + 0x654);
      pppuStack_1b0 = (undefined4 ***)(param_1 + 0x644);
      ppppuStack_1b4 = (undefined4 ****)0x41ff77;
      pppuStack_1a4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1b8 = *(undefined4 ****)(param_1 + 0x668);
      ppppuStack_1bc = *(undefined4 *****)(param_1 + 0x658);
      ppppuStack_1c0 = (undefined4 ****)(param_1 + 0x648);
      ppppuStack_1c4 = (undefined4 ****)0x41ff89;
      ppppuStack_1b4 = ppppuVar4;
      func_0x00421e80();
      ppuStack_1c8 = *(undefined1 ***)(param_1 + 0x674);
      ppppuStack_1cc = *(undefined4 *****)(param_1 + 0x670);
      ppppuStack_1d0 = (undefined4 ****)(param_1 + 0x66c);
      pppuStack_1d4 = (undefined4 ***)0x41ffa4;
      ppppuStack_1c4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1d8 = *(undefined4 ****)(param_1 + 0x680);
      fStack_1dc = *(float *)(param_1 + 0x67c);
      ppppuStack_1e0 = (undefined4 ****)(param_1 + 0x678);
      ppuStack_1e4 = (undefined4 **)0x41ffbf;
      pppuStack_1d4 = ppppuVar4;
      func_0x00421e80();
      puStack_1a8 = *(undefined1 **)(param_1 + 0x68c);
      ppuStack_1ac = *(undefined4 ***)(param_1 + 0x688);
      pppuStack_1b0 = (undefined4 ***)(param_1 + 0x684);
      ppppuStack_1b4 = (undefined4 ****)0x41ffdd;
      pppuStack_1a4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1b8 = *(undefined4 ****)(param_1 + 0x6b0);
      ppppuStack_1bc = *(undefined4 *****)(param_1 + 0x6a0);
      ppppuStack_1c0 = (undefined4 ****)(param_1 + 0x690);
      ppppuStack_1c4 = (undefined4 ****)0x41fff8;
      ppppuStack_1b4 = ppppuVar4;
      func_0x00421e80();
      ppuStack_1c8 = *(undefined1 ***)(param_1 + 0x6b4);
      ppppuStack_1cc = *(undefined4 *****)(param_1 + 0x6a4);
      ppppuStack_1d0 = (undefined4 ****)(param_1 + 0x694);
      pppuStack_1d4 = (undefined4 ***)0x42000a;
      ppppuStack_1c4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1d8 = *(undefined4 ****)(param_1 + 0x6b8);
      fStack_1dc = *(float *)(param_1 + 0x6a8);
      ppppuStack_1e0 = (undefined4 ****)(param_1 + 0x698);
      ppuStack_1e4 = (undefined4 **)0x42001c;
      pppuStack_1d4 = ppppuVar4;
      func_0x00421e80();
      puStack_1a8 = *(undefined1 **)(param_1 + 0x6bc);
      ppuStack_1ac = *(undefined4 ***)(param_1 + 0x6ac);
      pppuStack_1b0 = (undefined4 ***)(param_1 + 0x69c);
      ppppuStack_1b4 = (undefined4 ****)0x420031;
      pppuStack_1a4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1b8 = *(undefined4 ****)(param_1 + 0x6c8);
      ppppuStack_1bc = *(undefined4 *****)(param_1 + 0x6c4);
      ppppuStack_1c0 = (undefined4 ****)(param_1 + 0x6c0);
      ppppuStack_1c4 = (undefined4 ****)0x42004c;
      ppppuStack_1b4 = ppppuVar4;
      func_0x00421e80();
      ppuStack_1c8 = *(undefined1 ***)(param_1 + 0x6d4);
      ppppuStack_1cc = *(undefined4 *****)(param_1 + 0x6d0);
      ppppuStack_1d0 = (undefined4 ****)(param_1 + 0x6cc);
      pppuStack_1d4 = (undefined4 ***)0x420067;
      ppppuStack_1c4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1d8 = *(undefined4 ****)(param_1 + 0x6e0);
      fStack_1dc = *(float *)(param_1 + 0x6dc);
      ppppuStack_1e0 = (undefined4 ****)(param_1 + 0x6d8);
      ppuStack_1e4 = (undefined4 **)0x420082;
      pppuStack_1d4 = ppppuVar4;
      func_0x00421e80();
      puStack_1a8 = *(undefined1 **)(param_1 + 0x6ec);
      ppuStack_1ac = *(undefined4 ***)(param_1 + 0x6e8);
      pppuStack_1b0 = (undefined4 ***)(param_1 + 0x6e4);
      ppppuStack_1b4 = (undefined4 ****)0x4200a0;
      pppuStack_1a4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1b8 = *(undefined4 ****)(param_1 + 0x6f8);
      ppppuStack_1bc = *(undefined4 *****)(param_1 + 0x6f4);
      ppppuStack_1c0 = (undefined4 ****)(param_1 + 0x6f0);
      ppppuStack_1c4 = (undefined4 ****)0x4200bb;
      ppppuStack_1b4 = ppppuVar4;
      func_0x00421e80();
      ppuStack_1c8 = *(undefined1 ***)(param_1 + 0x71c);
      ppppuStack_1cc = *(undefined4 *****)(param_1 + 0x70c);
      ppppuStack_1d0 = (undefined4 ****)(param_1 + 0x6fc);
      pppuStack_1d4 = (undefined4 ***)0x4200d6;
      ppppuStack_1c4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1d8 = *(undefined4 ****)(param_1 + 0x720);
      fStack_1dc = *(float *)(param_1 + 0x710);
      ppppuStack_1e0 = (undefined4 ****)(param_1 + 0x700);
      ppuStack_1e4 = (undefined4 **)0x4200e8;
      pppuStack_1d4 = ppppuVar4;
      func_0x00421e80();
      puStack_1a8 = *(undefined1 **)(param_1 + 0x724);
      ppuStack_1ac = *(undefined4 ***)(param_1 + 0x714);
      pppuStack_1b0 = (undefined4 ***)(param_1 + 0x704);
      ppppuStack_1b4 = (undefined4 ****)0x4200fd;
      pppuStack_1a4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1b8 = *(undefined4 ****)(param_1 + 0x728);
      ppppuStack_1bc = *(undefined4 *****)(param_1 + 0x718);
      ppppuStack_1c0 = (undefined4 ****)(param_1 + 0x708);
      ppppuStack_1c4 = (undefined4 ****)0x42010f;
      ppppuStack_1b4 = ppppuVar4;
      func_0x00421e80();
      ppuStack_1c8 = *(undefined1 ***)(param_1 + 0x74c);
      ppppuStack_1cc = *(undefined4 *****)(param_1 + 0x73c);
      ppppuStack_1d0 = (undefined4 ****)(param_1 + 0x72c);
      pppuStack_1d4 = (undefined4 ***)0x42012a;
      ppppuStack_1c4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1d8 = *(undefined4 ****)(param_1 + 0x750);
      fStack_1dc = *(float *)(param_1 + 0x740);
      ppppuStack_1e0 = (undefined4 ****)(param_1 + 0x730);
      ppuStack_1e4 = (undefined4 **)0x42013c;
      pppuStack_1d4 = ppppuVar4;
      func_0x00421e80();
      puStack_1a8 = *(undefined1 **)(param_1 + 0x754);
      ppuStack_1ac = *(undefined4 ***)(param_1 + 0x744);
      pppuStack_1b0 = (undefined4 ***)(param_1 + 0x734);
      ppppuStack_1b4 = (undefined4 ****)0x420151;
      pppuStack_1a4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1b8 = *(undefined4 ****)(param_1 + 0x758);
      ppppuStack_1bc = *(undefined4 *****)(param_1 + 0x748);
      ppppuStack_1c0 = (undefined4 ****)(param_1 + 0x738);
      ppppuStack_1c4 = (undefined4 ****)0x420163;
      ppppuStack_1b4 = ppppuVar4;
      func_0x00421e80();
      ppuStack_1c8 = *(undefined1 ***)(param_1 + 0x77c);
      ppppuStack_1d0 = (undefined4 ****)(param_1 + 0x75c);
      ppppuStack_1cc = *(undefined4 *****)(param_1 + 0x76c);
      pppuStack_1d4 = (undefined4 ***)0x42017b;
      ppppuStack_1c4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1d8 = *(undefined4 ****)(param_1 + 0x780);
      fStack_1dc = *(float *)(param_1 + 0x770);
      ppppuStack_1e0 = (undefined4 ****)(param_1 + 0x760);
      ppuStack_1e4 = (undefined4 **)0x420196;
      pppuStack_1d4 = ppppuVar4;
      func_0x00421e80();
      puStack_1a8 = *(undefined1 **)(param_1 + 0x784);
      ppuStack_1ac = *(undefined4 ***)(param_1 + 0x774);
      pppuStack_1b0 = (undefined4 ***)(param_1 + 0x764);
      ppppuStack_1b4 = (undefined4 ****)0x4201b4;
      pppuStack_1a4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1b8 = *(undefined4 ****)(param_1 + 0x788);
      ppppuStack_1bc = *(undefined4 *****)(param_1 + 0x778);
      ppppuStack_1c0 = (undefined4 ****)(param_1 + 0x768);
      ppppuStack_1c4 = (undefined4 ****)0x4201cf;
      ppppuStack_1b4 = ppppuVar4;
      func_0x00421e80();
      ppuStack_1c8 = *(undefined1 ***)(param_1 + 0x7ac);
      ppppuStack_1cc = *(undefined4 *****)(param_1 + 0x79c);
      ppppuStack_1d0 = (undefined4 ****)(param_1 + 0x78c);
      pppuStack_1d4 = (undefined4 ***)0x4201ea;
      ppppuStack_1c4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1d8 = *(undefined4 ****)(param_1 + 0x7b0);
      fStack_1dc = *(float *)(param_1 + 0x7a0);
      ppppuStack_1e0 = (undefined4 ****)(param_1 + 0x790);
      ppuStack_1e4 = (undefined4 **)0x420205;
      pppuStack_1d4 = ppppuVar4;
      func_0x00421e80();
      puStack_1a8 = *(undefined1 **)(param_1 + 0x7b4);
      ppuStack_1ac = *(undefined4 ***)(param_1 + 0x7a4);
      pppuStack_1b0 = (undefined4 ***)(param_1 + 0x794);
      ppppuStack_1b4 = (undefined4 ****)0x420223;
      pppuStack_1a4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1b8 = *(undefined4 ****)(param_1 + 0x7b8);
      ppppuStack_1bc = *(undefined4 *****)(param_1 + 0x7a8);
      ppppuStack_1c0 = (undefined4 ****)(param_1 + 0x798);
      ppppuStack_1c4 = (undefined4 ****)0x42023e;
      ppppuStack_1b4 = ppppuVar4;
      func_0x00421e80();
      ppuStack_1c8 = *(undefined1 ***)(param_1 + 0x7dc);
      ppppuStack_1cc = *(undefined4 *****)(param_1 + 0x7cc);
      ppppuStack_1d0 = (undefined4 ****)(param_1 + 0x7bc);
      pppuStack_1d4 = (undefined4 ***)0x420259;
      ppppuStack_1c4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1d8 = *(undefined4 ****)(param_1 + 0x7e0);
      fStack_1dc = *(float *)(param_1 + 2000);
      ppppuStack_1e0 = (undefined4 ****)(param_1 + 0x7c0);
      ppuStack_1e4 = (undefined4 **)0x420274;
      pppuStack_1d4 = ppppuVar4;
      func_0x00421e80();
      puStack_1a8 = *(undefined1 **)(param_1 + 0x7e4);
      ppuStack_1ac = *(undefined4 ***)(param_1 + 0x7d4);
      pppuStack_1b0 = (undefined4 ***)(param_1 + 0x7c4);
      ppppuStack_1b4 = (undefined4 ****)0x420292;
      pppuStack_1a4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1b8 = *(undefined4 ****)(param_1 + 0x7e8);
      ppppuStack_1bc = *(undefined4 *****)(param_1 + 0x7d8);
      ppppuStack_1c0 = (undefined4 ****)(param_1 + 0x7c8);
      ppppuStack_1c4 = (undefined4 ****)0x4202ad;
      ppppuStack_1b4 = ppppuVar4;
      func_0x00421e80();
      ppuStack_1c8 = *(undefined1 ***)(param_1 + 0x83c);
      ppppuStack_1cc = *(undefined4 *****)(param_1 + 0x82c);
      ppppuStack_1d0 = (undefined4 ****)(param_1 + 0x81c);
      pppuStack_1d4 = (undefined4 ***)0x4202c8;
      ppppuStack_1c4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1d8 = *(undefined4 ****)(param_1 + 0x840);
      fStack_1dc = *(float *)(param_1 + 0x830);
      ppppuStack_1e0 = (undefined4 ****)(param_1 + 0x820);
      ppuStack_1e4 = (undefined4 **)0x4202e3;
      pppuStack_1d4 = ppppuVar4;
      func_0x00421e80();
      puStack_1a8 = *(undefined1 **)(param_1 + 0x844);
      ppuStack_1ac = *(undefined4 ***)(param_1 + 0x834);
      pppuStack_1b0 = (undefined4 ***)(param_1 + 0x824);
      ppppuStack_1b4 = (undefined4 ****)0x420301;
      pppuStack_1a4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1b8 = *(undefined4 ****)(param_1 + 0x848);
      ppppuStack_1bc = *(undefined4 *****)(param_1 + 0x838);
      ppppuStack_1c0 = (undefined4 ****)(param_1 + 0x828);
      ppppuStack_1c4 = (undefined4 ****)0x42031c;
      ppppuStack_1b4 = ppppuVar4;
      func_0x00421e80();
      ppuStack_1c8 = *(undefined1 ***)(param_1 + 0x80c);
      ppppuStack_1cc = *(undefined4 *****)(param_1 + 0x7fc);
      ppppuStack_1d0 = (undefined4 ****)(param_1 + 0x7ec);
      pppuStack_1d4 = (undefined4 ***)0x420337;
      ppppuStack_1c4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1d8 = *(undefined4 ****)(param_1 + 0x810);
      fStack_1dc = *(float *)(param_1 + 0x800);
      ppppuStack_1e0 = (undefined4 ****)(param_1 + 0x7f0);
      ppuStack_1e4 = (undefined4 **)0x420352;
      pppuStack_1d4 = ppppuVar4;
      func_0x00421e80();
      puStack_1a8 = *(undefined1 **)(param_1 + 0x814);
      ppuStack_1ac = *(undefined4 ***)(param_1 + 0x804);
      pppuStack_1b0 = (undefined4 ***)(param_1 + 0x7f4);
      ppppuStack_1b4 = (undefined4 ****)0x420370;
      pppuStack_1a4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1b8 = *(undefined4 ****)(param_1 + 0x818);
      ppppuStack_1bc = *(undefined4 *****)(param_1 + 0x808);
      ppppuStack_1c0 = (undefined4 ****)(param_1 + 0x7f8);
      ppppuStack_1c4 = (undefined4 ****)0x42038b;
      ppppuStack_1b4 = ppppuVar4;
      func_0x00421e80();
      ppppuStack_1d0 = (undefined4 ****)(param_1 + 0x84c);
      ppuStack_1c8 = *(undefined1 ***)(param_1 + 0x86c);
      ppppuStack_1cc = *(undefined4 *****)(param_1 + 0x85c);
      pppuStack_1d4 = (undefined4 ***)0x4203a0;
      ppppuStack_1c4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1d8 = *(undefined4 ****)(param_1 + 0x870);
      fStack_1dc = *(float *)(param_1 + 0x860);
      ppppuStack_1e0 = (undefined4 ****)(param_1 + 0x850);
      ppuStack_1e4 = (undefined4 **)0x4203bb;
      pppuStack_1d4 = ppppuVar4;
      func_0x00421e80();
      puStack_1a8 = *(undefined1 **)(param_1 + 0x874);
      ppuStack_1ac = *(undefined4 ***)(param_1 + 0x864);
      pppuStack_1b0 = (undefined4 ***)(param_1 + 0x854);
      ppppuStack_1b4 = (undefined4 ****)0x4203d9;
      pppuStack_1a4 = ppppuVar4;
      func_0x00421e80();
      pppuStack_1b8 = *(undefined4 ****)(param_1 + 0x878);
      ppppuStack_1bc = *(undefined4 *****)(param_1 + 0x868);
      ppppuStack_1c0 = (undefined4 ****)(param_1 + 0x858);
      ppppuStack_1c4 = (undefined4 ****)0x4203f4;
      ppppuStack_1b4 = ppppuVar4;
      func_0x00421e80();
      fStack_324 = *(float *)((int)fVar16 + 0x7c);
    }
    else {
      *(int *)(param_1 + 0x590) = *(int *)((int)fVar16 + 0x14);
      if (*(undefined4 *****)((int)fVar16 + 0x7c) != (undefined4 ****)0x0) {
        ppppuStack_170 = (undefined4 *****)0x0;
        pppuStack_174 = *(undefined4 *****)((int)fVar16 + 0x7c);
      }
      pppuStack_1a4 = *(undefined4 ****)((int)fVar16 + 0x90);
      puStack_1a8 = (undefined1 *)0x41f348;
      func_0x00799460();
      if ((float)puStack_194 == _DAT_008d58a0) {
        puStack_1a8 = &stack0xfffffe78;
        ppuStack_1ac = (undefined4 **)0x41f36b;
        func_0x00421f00();
      }
      else {
        puStack_1a8 = &stack0xfffffe78;
        ppuStack_1ac = (undefined4 **)0x41f37a;
        func_0x00410950();
        ppppuStack_1b4 = (undefined4 ****)&stack0xfffffe74;
        ppuStack_1ac = ppuStack_198;
        pppuStack_1b8 = (undefined4 ***)&puStack_158;
        ppppuStack_1bc = (undefined4 ****)0x41f38f;
        pppuStack_1b0 = (undefined4 ***)(param_1 + 0x594);
        pppuStack_1b0 = (undefined4 ***)func_0x00421840();
        ppppuStack_1b4 = (undefined4 ****)&ppuStack_16c;
        pppuStack_1b8 = (undefined4 ***)0x41f39d;
        ppuStack_1ac = (undefined4 **)func_0x00421810();
        pppuStack_1b0 = (undefined4 ***)0x41f3a9;
        func_0x00410950();
      }
      fVar15 = *(float *)((int)fVar16 + 0x84);
      bVar3 = (float)ppuStack_198 == _DAT_008d58a0;
      *(float *)(param_1 + 0x5c8) = fVar15;
      if (bVar3) {
        *(float *)(param_1 + 0x5c4) = fVar15;
        *(undefined4 *)(param_1 + 0x5cc) = 0;
      }
      else {
        *(float *)(param_1 + 0x5cc) = (fVar15 - *(float *)(param_1 + 0x5c4)) * (float)ppuStack_198;
      }
      fVar15 = *(float *)((int)fVar16 + 0x88);
      bVar3 = (float)ppuStack_198 == _DAT_008d58a0;
      *(float *)(param_1 + 0x5d4) = fVar15;
      if (bVar3) {
        *(float *)(param_1 + 0x5d0) = fVar15;
        *(undefined4 *)(param_1 + 0x5d8) = 0;
      }
      else {
        *(float *)(param_1 + 0x5d8) = (fVar15 - *(float *)(param_1 + 0x5d0)) * (float)ppuStack_198;
      }
      fVar15 = *(float *)((int)fVar16 + 0x8c);
      bVar3 = (float)ppuStack_198 == _DAT_008d58a0;
      *(float *)(param_1 + 0x5e0) = fVar15;
      if (bVar3) {
        *(float *)(param_1 + 0x5dc) = fVar15;
        *(undefined4 *)(param_1 + 0x5e4) = 0;
      }
      else {
        *(float *)(param_1 + 0x5e4) = (fVar15 - *(float *)(param_1 + 0x5dc)) * (float)ppuStack_198;
      }
      ppuStack_1ac = *(undefined4 ***)((int)fVar16 + 0xb0);
      pppuStack_1b0 = (undefined4 ***)0x41f46e;
      func_0x00799460();
      if ((float)ppuStack_19c == _DAT_008d58a0) {
        pppuStack_1b0 = (undefined4 ***)&stack0xfffffe70;
        ppppuStack_1b4 = (undefined4 ****)0x41f491;
        func_0x00421f00();
      }
      else {
        pppuStack_1b0 = (undefined4 ***)&stack0xfffffe70;
        ppppuStack_1b4 = (undefined4 ****)0x41f4a0;
        func_0x00410950();
        ppppuStack_1bc = (undefined4 ****)&puStack_194;
        ppppuStack_1b4 = ppppuStack_1a0;
        ppppuStack_1c0 = (undefined4 ****)&ppuStack_160;
        ppppuStack_1c4 = (undefined4 ****)0x41f4b5;
        pppuStack_1b8 = (undefined4 ***)(param_1 + 0x5e8);
        pppuStack_1b8 = (undefined4 ***)func_0x00421840();
        ppppuStack_1bc = &pppuStack_174;
        ppppuStack_1c0 = (undefined4 ****)0x41f4c3;
        ppppuStack_1b4 = (undefined4 ****)func_0x00421810();
        pppuStack_1b8 = (undefined4 ***)0x41f4cf;
        func_0x00410950();
      }
      fVar15 = *(float *)((int)fVar16 + 0xa4);
      bVar3 = (float)ppppuStack_1a0 == _DAT_008d58a0;
      *(float *)(param_1 + 0x61c) = fVar15;
      if (bVar3) {
        *(float *)(param_1 + 0x618) = fVar15;
        *(undefined4 *)(param_1 + 0x620) = 0;
      }
      else {
        *(float *)(param_1 + 0x620) = (fVar15 - *(float *)(param_1 + 0x618)) * (float)ppppuStack_1a0
        ;
      }
      fVar15 = *(float *)((int)fVar16 + 0xa8);
      bVar3 = (float)ppppuStack_1a0 == _DAT_008d58a0;
      *(float *)(param_1 + 0x628) = fVar15;
      if (bVar3) {
        *(float *)(param_1 + 0x624) = fVar15;
        *(undefined4 *)(param_1 + 0x62c) = 0;
      }
      else {
        *(float *)(param_1 + 0x62c) = (fVar15 - *(float *)(param_1 + 0x624)) * (float)ppppuStack_1a0
        ;
      }
      fVar15 = *(float *)((int)fVar16 + 0xac);
      bVar3 = (float)ppppuStack_1a0 == _DAT_008d58a0;
      *(float *)(param_1 + 0x634) = fVar15;
      if (bVar3) {
        *(float *)(param_1 + 0x630) = fVar15;
        *(undefined4 *)(param_1 + 0x638) = 0;
      }
      else {
        *(float *)(param_1 + 0x638) = (fVar15 - *(float *)(param_1 + 0x630)) * (float)ppppuStack_1a0
        ;
      }
      ppppuStack_1b4 = *(undefined4 *****)((int)fVar16 + 0xa0);
      pppuStack_1b8 = (undefined4 ***)0x41f590;
      func_0x00799460();
      if ((float)pppuStack_1a4 == _DAT_008d58a0) {
        pppuStack_1b8 = &ppuStack_198;
        ppppuStack_1bc = (undefined4 ****)0x41f5b3;
        func_0x00421f00();
      }
      else {
        pppuStack_1b8 = &ppuStack_198;
        ppppuStack_1bc = (undefined4 ****)0x41f5c2;
        func_0x00410950();
        ppppuStack_1c4 = (undefined4 ****)&ppuStack_19c;
        ppppuStack_1bc = (undefined4 ****)puStack_1a8;
        ppuStack_1c8 = &puStack_168;
        ppppuStack_1cc = (undefined4 ****)0x41f5d7;
        ppppuStack_1c0 = (undefined4 ****)(param_1 + 0x63c);
        ppppuStack_1c0 = (undefined4 ****)func_0x00421840();
        ppppuStack_1c4 = (undefined4 ****)&ppuStack_17c;
        ppuStack_1c8 = (undefined1 **)0x41f5e5;
        ppppuStack_1bc = (undefined4 ****)func_0x00421810();
        ppppuStack_1c0 = (undefined4 ****)0x41f5f1;
        func_0x00410950();
      }
      fVar15 = *(float *)((int)fVar16 + 0x94);
      bVar3 = (float)puStack_1a8 == _DAT_008d58a0;
      *(float *)(param_1 + 0x670) = fVar15;
      if (bVar3) {
        *(float *)(param_1 + 0x66c) = fVar15;
        *(undefined4 *)(param_1 + 0x674) = 0;
      }
      else {
        *(float *)(param_1 + 0x674) = (fVar15 - *(float *)(param_1 + 0x66c)) * (float)puStack_1a8;
      }
      fVar15 = *(float *)((int)fVar16 + 0x98);
      bVar3 = (float)puStack_1a8 == _DAT_008d58a0;
      *(float *)(param_1 + 0x67c) = fVar15;
      if (bVar3) {
        *(float *)(param_1 + 0x678) = fVar15;
        *(undefined4 *)(param_1 + 0x680) = 0;
      }
      else {
        *(float *)(param_1 + 0x680) = (fVar15 - *(float *)(param_1 + 0x678)) * (float)puStack_1a8;
      }
      fVar15 = *(float *)((int)fVar16 + 0x9c);
      bVar3 = (float)puStack_1a8 == _DAT_008d58a0;
      *(float *)(param_1 + 0x688) = fVar15;
      if (bVar3) {
        *(float *)(param_1 + 0x684) = fVar15;
        *(undefined4 *)(param_1 + 0x68c) = 0;
      }
      else {
        *(float *)(param_1 + 0x68c) = (fVar15 - *(float *)(param_1 + 0x684)) * (float)puStack_1a8;
      }
      ppppuStack_1bc = *(undefined4 *****)((int)fVar16 + 0xc0);
      ppppuStack_1c0 = (undefined4 ****)0x41f6b2;
      func_0x00799460();
      if ((float)ppuStack_1ac == _DAT_008d58a0) {
        ppppuStack_1c0 = &ppppuStack_1a0;
        ppppuStack_1c4 = (undefined4 ****)0x41f6d5;
        func_0x00421f00();
      }
      else {
        ppppuStack_1c0 = &ppppuStack_1a0;
        ppppuStack_1c4 = (undefined4 ****)0x41f6e4;
        func_0x00410950();
        ppppuStack_1cc = &pppuStack_1a4;
        ppppuStack_1c4 = (undefined4 ****)pppuStack_1b0;
        ppppuStack_1d0 = &ppppuStack_170;
        pppuStack_1d4 = (undefined4 ***)0x41f6f9;
        ppuStack_1c8 = (undefined1 **)(param_1 + 0x690);
        ppuStack_1c8 = (undefined1 **)func_0x00421840();
        ppppuStack_1cc = (undefined4 ****)&stack0xfffffe7c;
        ppppuStack_1d0 = (undefined4 ****)0x41f707;
        ppppuStack_1c4 = (undefined4 ****)func_0x00421810();
        ppuStack_1c8 = (undefined1 **)0x41f713;
        func_0x00410950();
      }
      fVar15 = *(float *)((int)fVar16 + 0xb4);
      bVar3 = (float)pppuStack_1b0 == _DAT_008d58a0;
      *(float *)(param_1 + 0x6c4) = fVar15;
      if (bVar3) {
        *(float *)(param_1 + 0x6c0) = fVar15;
        *(undefined4 *)(param_1 + 0x6c8) = 0;
      }
      else {
        *(float *)(param_1 + 0x6c8) = (fVar15 - *(float *)(param_1 + 0x6c0)) * (float)pppuStack_1b0;
      }
      fVar15 = *(float *)((int)fVar16 + 0xb8);
      bVar3 = (float)pppuStack_1b0 == _DAT_008d58a0;
      *(float *)(param_1 + 0x6d0) = fVar15;
      if (bVar3) {
        *(float *)(param_1 + 0x6cc) = fVar15;
        *(undefined4 *)(param_1 + 0x6d4) = 0;
      }
      else {
        *(float *)(param_1 + 0x6d4) = (fVar15 - *(float *)(param_1 + 0x6cc)) * (float)pppuStack_1b0;
      }
      fVar15 = *(float *)((int)fVar16 + 0xbc);
      bVar3 = (float)pppuStack_1b0 == _DAT_008d58a0;
      *(float *)(param_1 + 0x6dc) = fVar15;
      if (bVar3) {
        *(float *)(param_1 + 0x6d8) = fVar15;
        *(undefined4 *)(param_1 + 0x6e0) = 0;
      }
      else {
        *(float *)(param_1 + 0x6e0) = (fVar15 - *(float *)(param_1 + 0x6d8)) * (float)pppuStack_1b0;
      }
      fVar15 = *(float *)((int)fVar16 + 0xf8);
      bVar3 = (float)pppuStack_1b0 == _DAT_008d58a0;
      *(float *)(param_1 + 0x6e8) = fVar15;
      if (bVar3) {
        *(float *)(param_1 + 0x6e4) = fVar15;
        *(undefined4 *)(param_1 + 0x6ec) = 0;
      }
      else {
        *(float *)(param_1 + 0x6ec) = (fVar15 - *(float *)(param_1 + 0x6e4)) * (float)pppuStack_1b0;
      }
      fVar15 = *(float *)((int)fVar16 + 0xfc);
      bVar3 = (float)pppuStack_1b0 == _DAT_008d58a0;
      *(float *)(param_1 + 0x6f4) = fVar15;
      if (bVar3) {
        *(float *)(param_1 + 0x6f0) = fVar15;
        *(undefined4 *)(param_1 + 0x6f8) = 0;
      }
      else {
        *(float *)(param_1 + 0x6f8) = (fVar15 - *(float *)(param_1 + 0x6f0)) * (float)pppuStack_1b0;
      }
      ppppuStack_1c4 = *(undefined4 *****)((int)fVar16 + 0xd0);
      ppuStack_1c8 = (undefined1 **)0x41f84a;
      func_0x00799460();
      if ((float)ppppuStack_1b4 == _DAT_008d58a0) {
        ppuStack_1c8 = &puStack_1a8;
        ppppuStack_1cc = (undefined4 ****)0x41f86d;
        func_0x00421f00();
      }
      else {
        ppuStack_1c8 = &puStack_1a8;
        ppppuStack_1cc = (undefined4 ****)0x41f87c;
        func_0x00410950();
        pppuStack_1d4 = &ppuStack_1ac;
        ppppuStack_1cc = (undefined4 ****)pppuStack_1b8;
        pppuStack_1d8 = (undefined4 ***)&puStack_178;
        fStack_1dc = 6.058476e-39;
        ppppuStack_1d0 = (undefined4 ****)(param_1 + 0x6fc);
        ppppuStack_1d0 = (undefined4 ****)func_0x00421840();
        pppuStack_1d4 = (undefined4 ***)&stack0xfffffe74;
        pppuStack_1d8 = (undefined4 ***)0x41f89f;
        ppppuStack_1cc = (undefined4 ****)func_0x00421810();
        ppppuStack_1d0 = (undefined4 ****)0x41f8ab;
        func_0x00410950();
      }
      ppuStack_19c = *(undefined4 ***)((int)fVar16 + 0xe0);
      ppppuStack_1cc = *(undefined4 *****)((int)fVar16 + 0xd4);
      ppppuStack_1d0 = (undefined4 ****)0x41f8c5;
      pfVar7 = (float *)func_0x00799460();
      ppppuStack_1d0 = (undefined4 ****)((float)ppppuStack_1a0 * pfVar7[3]);
      pppuStack_1d4 = (undefined4 ***)((float)ppppuStack_1a0 * pfVar7[2]);
      pppuStack_1d8 = (undefined4 ***)((float)ppppuStack_1a0 * pfVar7[1]);
      fStack_1dc = (float)ppppuStack_1a0 * *pfVar7;
      ppppuStack_1e0 = (undefined4 ****)0x41f8f9;
      func_0x004217f0();
      pppuStack_1e8 = (undefined1 ***)(param_1 + 0x72c);
      if ((float)ppppuStack_1cc == _DAT_008d58a0) {
        ppppuStack_1e0 = &ppppuStack_1c0;
        ppuStack_1e4 = (undefined4 **)0x41f91c;
        func_0x00421f00();
      }
      else {
        ppppuStack_1e0 = &ppppuStack_1c0;
        ppuStack_1e4 = (undefined4 **)0x41f92b;
        func_0x00410950();
        ppppuStack_1ec = &ppppuStack_1c4;
        ppuStack_1e4 = ppppuStack_1d0;
        ppppuStack_1f0 = &pppuStack_1a4;
        ppppuStack_1f4 = (undefined4 ****)0x41f940;
        pppuStack_1e8 = (undefined1 ***)func_0x00421840();
        ppppuStack_1ec = &ppppuStack_1b4;
        ppppuStack_1f0 = (undefined4 ****)0x41f94e;
        ppuStack_1e4 = (undefined4 **)func_0x00421810();
        pppuStack_1e8 = (undefined1 ***)0x41f95a;
        func_0x00410950();
      }
      ppuStack_1e4 = *(undefined4 ***)((int)fVar16 + 0xd8);
      pppuStack_1e8 = (undefined1 ***)0x41f96a;
      func_0x00799460();
      if ((float)pppuStack_1d4 == _DAT_008d58a0) {
        pppuStack_1e8 = &ppuStack_1c8;
        ppppuStack_1ec = (undefined4 ****)0x41f98d;
        func_0x00421f00();
      }
      else {
        pppuStack_1e8 = &ppuStack_1c8;
        ppppuStack_1ec = (undefined4 ****)0x41f99c;
        func_0x00410950();
        ppppuStack_1f4 = &ppppuStack_1cc;
        ppppuStack_1ec = (undefined4 ****)pppuStack_1d8;
        pppuStack_1f8 = &ppuStack_198;
        pfStack_1fc = (float *)0x41f9b1;
        ppppuStack_1f0 = (undefined4 ****)(param_1 + 0x75c);
        ppppuStack_1f0 = (undefined4 ****)func_0x00421840();
        ppppuStack_1f4 = (undefined4 ****)&ppuStack_1ac;
        pppuStack_1f8 = (undefined4 ****)0x41f9bf;
        ppppuStack_1ec = (undefined4 ****)func_0x00421810();
        ppppuStack_1f0 = (undefined4 ****)0x41f9cb;
        func_0x00410950();
      }
      ppppuStack_1ec = *(undefined4 *****)((int)fVar16 + 0xdc);
      ppppuStack_1bc = *(undefined4 *****)((int)fVar16 + 0xe4);
      ppppuStack_1f0 = (undefined4 ****)0x41f9e5;
      pfVar7 = (float *)func_0x00799460();
      ppppuStack_1f0 = (undefined4 ****)((float)ppppuStack_1c0 * pfVar7[3]);
      ppppuStack_1f4 = (undefined4 ****)((float)ppppuStack_1c0 * pfVar7[2]);
      pppuStack_1f8 = (undefined4 ***)((float)ppppuStack_1c0 * pfVar7[1]);
      pfStack_1fc = (float *)((float)ppppuStack_1c0 * *pfVar7);
      ppppuStack_200 = (undefined4 ****)0x41fa19;
      func_0x004217f0();
      ppppuStack_208 = (undefined1 ****)(param_1 + 0x78c);
      if ((float)ppppuStack_1ec == _DAT_008d58a0) {
        ppppuStack_200 = &ppppuStack_1e0;
        fStack_204 = 6.059074e-39;
        func_0x00421f00();
      }
      else {
        ppppuStack_200 = &ppppuStack_1e0;
        fStack_204 = 6.059095e-39;
        func_0x00410950();
        ppppuStack_20c = (undefined4 ****)&ppuStack_1e4;
        fStack_204 = (float)ppppuStack_1f0;
        ppppuStack_210 = &ppppuStack_1c4;
        ppppuStack_214 = (undefined4 *****)0x41fa60;
        ppppuStack_208 = (undefined1 ****)func_0x00421840();
        ppppuStack_20c = &pppuStack_1d4;
        ppppuStack_210 = (undefined4 ****)0x41fa6e;
        fStack_204 = (float)func_0x00421810();
        ppppuStack_208 = (undefined1 ****)0x41fa7a;
        func_0x00410950();
      }
      fStack_204 = *(float *)((int)fVar16 + 0xe8);
      ppppuStack_208 = (undefined1 ****)0x41fa8a;
      func_0x00799460();
      if ((float)ppppuStack_1f4 == _DAT_008d58a0) {
        ppppuStack_208 = &pppuStack_1e8;
        ppppuStack_20c = (undefined4 ****)0x41faad;
        func_0x00421f00();
      }
      else {
        ppppuStack_208 = &pppuStack_1e8;
        ppppuStack_20c = (undefined4 ****)0x41fabc;
        func_0x00410950();
        ppppuStack_214 = &ppppuStack_1ec;
        ppppuStack_20c = (undefined4 ****)pppuStack_1f8;
        pppuStack_218 = &pppuStack_1b8;
        fStack_21c = 6.059283e-39;
        ppppuStack_210 = (undefined4 ****)(param_1 + 0x7bc);
        ppppuStack_210 = (undefined4 ****)func_0x00421840();
        ppppuStack_214 = &ppppuStack_1cc;
        pppuStack_218 = (undefined4 ****)0x41fadf;
        ppppuStack_20c = (undefined4 ****)func_0x00421810();
        ppppuStack_210 = (undefined4 ****)0x41faeb;
        func_0x00410950();
      }
      fStack_1dc = *(float *)((int)fVar16 + 0xe0);
      ppppuStack_20c = *(undefined4 *****)((int)fVar16 + 0xf0);
      ppppuStack_210 = (undefined4 ****)0x41fb05;
      pfVar7 = (float *)func_0x00799460();
      ppppuStack_210 = (undefined4 ****)((float)ppppuStack_1e0 * pfVar7[3]);
      ppppuStack_214 = (undefined4 ****)((float)ppppuStack_1e0 * pfVar7[2]);
      pppuStack_218 = (undefined4 ***)((float)ppppuStack_1e0 * pfVar7[1]);
      fStack_21c = (float)ppppuStack_1e0 * *pfVar7;
      ppppuStack_220 = (undefined4 ****)0x41fb39;
      func_0x004217f0();
      ppppuStack_228 = (undefined4 ****)(param_1 + 0x81c);
      if ((float)ppppuStack_20c == _DAT_008d58a0) {
        ppppuStack_220 = &ppppuStack_200;
        fStack_224 = 6.059478e-39;
        func_0x00421f00();
      }
      else {
        ppppuStack_220 = &ppppuStack_200;
        fStack_224 = 6.059499e-39;
        func_0x00410950();
        ppppuStack_22c = (undefined4 ****)&fStack_204;
        fStack_224 = (float)ppppuStack_210;
        ppuStack_230 = &ppuStack_1e4;
        ppppuStack_234 = (undefined4 *****)0x41fb80;
        ppppuStack_228 = (undefined4 ****)func_0x00421840();
        ppppuStack_22c = &ppppuStack_1f4;
        ppuStack_230 = (undefined4 **)0x41fb8e;
        fStack_224 = (float)func_0x00421810();
        ppppuStack_228 = (undefined4 ****)0x41fb9a;
        func_0x00410950();
      }
      fStack_224 = *(float *)((int)fVar16 + 0xec);
      ppppuStack_228 = (undefined4 ****)0x41fbaa;
      func_0x00799460();
      if ((float)ppppuStack_214 == _DAT_008d58a0) {
        ppppuStack_228 = &ppppuStack_208;
        ppppuStack_22c = (undefined4 ****)0x41fbcd;
        func_0x00421f00();
      }
      else {
        ppppuStack_228 = &ppppuStack_208;
        ppppuStack_22c = (undefined4 ****)0x41fbdc;
        func_0x00410950();
        ppppuStack_234 = &ppppuStack_20c;
        ppppuStack_22c = (undefined4 ****)pppuStack_218;
        pppuStack_238 = &pppuStack_1d8;
        fStack_23c = 6.059687e-39;
        ppuStack_230 = (undefined4 **)(param_1 + 0x7ec);
        ppuStack_230 = (undefined4 **)func_0x00421840();
        ppppuStack_234 = &ppppuStack_1ec;
        pppuStack_238 = (undefined4 ***)0x41fbff;
        ppppuStack_22c = (undefined4 ****)func_0x00421810();
        ppuStack_230 = (undefined4 **)0x41fc0b;
        func_0x00410950();
      }
      pfStack_1fc = *(float **)((int)fVar16 + 0xe4);
      ppppuStack_22c = *(undefined4 *****)((int)fVar16 + 0xf4);
      ppuStack_230 = (undefined4 **)0x41fc25;
      pfVar7 = (float *)func_0x00799460();
      ppuStack_230 = (undefined4 **)((float)ppppuStack_200 * pfVar7[3]);
      ppppuStack_234 = (undefined4 ****)((float)ppppuStack_200 * pfVar7[2]);
      pppuStack_238 = (undefined4 ***)((float)ppppuStack_200 * pfVar7[1]);
      fStack_23c = (float)ppppuStack_200 * *pfVar7;
      ppppuStack_240 = (undefined4 ****)0x41fc59;
      func_0x004217f0();
      iStack_248 = param_1 + 0x84c;
      if ((float)ppppuStack_22c == _DAT_008d58a0) {
        ppppuStack_240 = &ppppuStack_220;
        pfStack_244 = (float *)0x41fc7c;
        func_0x00421f00();
      }
      else {
        ppppuStack_240 = &ppppuStack_220;
        pfStack_244 = (float *)0x41fc8b;
        func_0x00410950();
        ppppuStack_24c = (undefined4 ****)&fStack_224;
        pfStack_244 = (float *)ppuStack_230;
        pfStack_250 = &fStack_204;
        iStack_254 = 0x41fca0;
        iStack_248 = func_0x00421840();
        ppppuStack_24c = &ppppuStack_214;
        pfStack_250 = (float *)0x41fcae;
        pfStack_244 = (float *)func_0x00421810();
        iStack_248 = 0x41fcba;
        func_0x00410950();
      }
      ppppuStack_214 = *(undefined4 *****)((int)fVar16 + 0x7c);
      iVar8 = *(int *)(_DAT_009b3eec + 0xc);
      ppppuStack_1a0 = *(undefined4 *****)(iVar8 + 0x10);
      pfStack_244 = (float *)(iVar8 + 0x14);
      iStack_248 = 0x41fce6;
      func_0x00410950();
      iStack_248 = iVar8 + 0x24;
      ppppuStack_24c = (undefined4 ****)0x41fcf6;
      func_0x00410950();
      ppppuStack_24c = (undefined4 ****)(iVar8 + 0x34);
      pfStack_250 = (float *)0x41fd06;
      func_0x00410950();
      pfStack_250 = (float *)(iVar8 + 0x44);
      iStack_254 = 0x41fd16;
      func_0x00401cc0();
      iStack_254 = iVar8 + 0x50;
      iStack_258 = 0x41fd26;
      func_0x00401cc0();
      puStack_168 = *(undefined1 **)(iVar8 + 0x5c);
      uStack_164 = *(undefined4 *)(iVar8 + 0x60);
      ppuStack_160 = *(undefined4 ***)(iVar8 + 100);
      uStack_15c = *(undefined4 *)(iVar8 + 0x68);
      puStack_158 = *(undefined4 **)(iVar8 + 0x6c);
      uStack_154 = *(undefined4 *)(iVar8 + 0x70);
      iStack_258 = (int)ppppuStack_1f0 + 0xc4;
      uStack_150 = *(undefined4 *)(iVar8 + 0x74);
      pppuStack_25c = (undefined4 ***)0x41fd80;
      func_0x00401cc0();
      pppuStack_174 = pppuStack_218;
      puStack_178 = (undefined4 *)fStack_21c;
      pppuStack_25c = &pppuStack_1b8;
      ppppuStack_170 = ppppuStack_214;
      ppppuStack_260 = (undefined4 ****)0x41fdb6;
      FUN_0079b390();
      uStack_264 = 0x41fdbe;
      ppppuStack_260 = (undefined4 ****)fVar16;
      func_0x00421520();
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x590) = *(undefined4 *)((int)fVar16 + 0x14);
    pppuStack_1a4 = *(undefined4 ****)((int)fVar16 + 0x90);
    puStack_1a8 = (undefined1 *)0x41ecc1;
    func_0x00799460();
    puStack_1a8 = &stack0xfffffe78;
    ppuStack_1ac = (undefined4 **)0x41ecd4;
    ppuStack_1ac = (undefined4 **)func_0x00410950();
    pppuStack_1b0 = (undefined4 ***)0x41ecdc;
    func_0x00410950();
    pppuStack_1b0 = (undefined4 ****)0x0;
    ppppuStack_1b4 = (undefined4 ****)0x0;
    pppuStack_1b8 = (undefined4 ****)0x0;
    ppppuStack_1bc = (undefined4 ****)0x0;
    ppppuStack_1c0 = (undefined4 ****)0x41ecea;
    func_0x00421870();
    uVar13 = *(undefined4 *)((int)fVar16 + 0x84);
    *(undefined4 *)(param_1 + 0x5cc) = 0;
    *(undefined4 *)(param_1 + 0x5c8) = uVar13;
    *(undefined4 *)(param_1 + 0x5c4) = uVar13;
    uVar13 = *(undefined4 *)((int)fVar16 + 0x88);
    *(undefined4 *)(param_1 + 0x5d8) = 0;
    *(undefined4 *)(param_1 + 0x5d4) = uVar13;
    *(undefined4 *)(param_1 + 0x5d0) = uVar13;
    uVar13 = *(undefined4 *)((int)fVar16 + 0x8c);
    *(undefined4 *)(param_1 + 0x5e4) = 0;
    *(undefined4 *)(param_1 + 0x5e0) = uVar13;
    *(undefined4 *)(param_1 + 0x5dc) = uVar13;
    ppppuStack_1c0 = *(undefined4 *****)((int)fVar16 + 0xb0);
    ppppuStack_1c4 = (undefined4 ****)0x41ed42;
    func_0x00799460();
    ppppuStack_1c4 = &pppuStack_1a4;
    ppuStack_1c8 = (undefined1 **)0x41ed55;
    ppuStack_1c8 = (undefined1 **)func_0x00410950();
    ppppuStack_1cc = (undefined4 ****)0x41ed5d;
    func_0x00410950();
    ppppuStack_1cc = (undefined4 ****)0x0;
    ppppuStack_1d0 = (undefined4 ****)0x0;
    pppuStack_1d4 = (undefined4 ****)0x0;
    pppuStack_1d8 = (undefined4 ****)0x0;
    fStack_1dc = 6.054474e-39;
    func_0x00421870();
    uVar13 = *(undefined4 *)((int)fVar16 + 0xa4);
    *(undefined4 *)(param_1 + 0x620) = 0;
    *(undefined4 *)(param_1 + 0x61c) = uVar13;
    *(undefined4 *)(param_1 + 0x618) = uVar13;
    uVar13 = *(undefined4 *)((int)fVar16 + 0xa8);
    *(undefined4 *)(param_1 + 0x62c) = 0;
    *(undefined4 *)(param_1 + 0x628) = uVar13;
    *(undefined4 *)(param_1 + 0x624) = uVar13;
    uVar13 = *(undefined4 *)((int)fVar16 + 0xac);
    *(undefined4 *)(param_1 + 0x638) = 0;
    *(undefined4 *)(param_1 + 0x634) = uVar13;
    *(undefined4 *)(param_1 + 0x630) = uVar13;
    fStack_1dc = *(float *)((int)fVar16 + 0xa0);
    ppppuStack_1e0 = (undefined4 ****)0x41edc1;
    func_0x00799460();
    ppppuStack_1e0 = &ppppuStack_1c0;
    ppuStack_1e4 = (undefined4 **)0x41edd4;
    ppuStack_1e4 = (undefined4 **)func_0x00410950();
    pppuStack_1e8 = (undefined1 ***)0x41eddc;
    func_0x00410950();
    pppuStack_1e8 = (undefined1 ***)0x0;
    ppppuStack_1ec = (undefined4 *****)0x0;
    ppppuStack_1f0 = (undefined4 ****)0x0;
    ppppuStack_1f4 = (undefined4 ****)0x0;
    pppuStack_1f8 = (undefined4 ***)0x41ede8;
    func_0x00421870();
    uVar13 = *(undefined4 *)((int)fVar16 + 0x94);
    *(undefined4 *)(param_1 + 0x674) = 0;
    *(undefined4 *)(param_1 + 0x670) = uVar13;
    *(undefined4 *)(param_1 + 0x66c) = uVar13;
    uVar13 = *(undefined4 *)((int)fVar16 + 0x98);
    *(undefined4 *)(param_1 + 0x680) = 0;
    *(undefined4 *)(param_1 + 0x67c) = uVar13;
    *(undefined4 *)(param_1 + 0x678) = uVar13;
    uVar13 = *(undefined4 *)((int)fVar16 + 0x9c);
    *(undefined4 *)(param_1 + 0x68c) = 0;
    *(undefined4 *)(param_1 + 0x688) = uVar13;
    *(undefined4 *)(param_1 + 0x684) = uVar13;
    pppuStack_1f8 = *(undefined4 ****)((int)fVar16 + 0xc0);
    pfStack_1fc = (float *)0x41ee40;
    func_0x00799460();
    pfStack_1fc = &fStack_1dc;
    ppppuStack_200 = (undefined4 ****)0x41ee53;
    ppppuStack_200 = (undefined4 ****)func_0x00410950();
    fStack_204 = 6.054813e-39;
    func_0x00410950();
    fStack_204 = 0.0;
    ppppuStack_208 = (undefined1 ****)0x0;
    ppppuStack_20c = (undefined4 ****)0x0;
    ppppuStack_210 = (undefined4 ****)0x0;
    ppppuStack_214 = (undefined4 ****)0x41ee67;
    func_0x00421870();
    uVar13 = *(undefined4 *)((int)fVar16 + 0xb4);
    *(undefined4 *)(param_1 + 0x6c8) = 0;
    *(undefined4 *)(param_1 + 0x6c4) = uVar13;
    *(undefined4 *)(param_1 + 0x6c0) = uVar13;
    uVar13 = *(undefined4 *)((int)fVar16 + 0xb8);
    *(undefined4 *)(param_1 + 0x6d4) = 0;
    *(undefined4 *)(param_1 + 0x6d0) = uVar13;
    *(undefined4 *)(param_1 + 0x6cc) = uVar13;
    uVar13 = *(undefined4 *)((int)fVar16 + 0xbc);
    *(undefined4 *)(param_1 + 0x6e0) = 0;
    *(undefined4 *)(param_1 + 0x6dc) = uVar13;
    *(undefined4 *)(param_1 + 0x6d8) = uVar13;
    uVar13 = *(undefined4 *)((int)fVar16 + 0xf8);
    *(undefined4 *)(param_1 + 0x6ec) = 0;
    *(undefined4 *)(param_1 + 0x6e8) = uVar13;
    *(undefined4 *)(param_1 + 0x6e4) = uVar13;
    uVar13 = *(undefined4 *)((int)fVar16 + 0xfc);
    *(undefined4 *)(param_1 + 0x6f8) = 0;
    *(undefined4 *)(param_1 + 0x6f4) = uVar13;
    *(undefined4 *)(param_1 + 0x6f0) = uVar13;
    ppppuStack_214 = *(undefined4 *****)((int)fVar16 + 0xd0);
    pppuStack_218 = (undefined4 ***)0x41eeef;
    func_0x00799460();
    pppuStack_218 = &pppuStack_1f8;
    fStack_21c = 6.055047e-39;
    fStack_21c = (float)func_0x00410950();
    ppppuStack_220 = (undefined4 ****)0x41ef0a;
    func_0x00410950();
    ppppuStack_220 = (undefined4 *****)0x0;
    fStack_224 = 0.0;
    ppppuStack_228 = (undefined1 *****)0x0;
    ppppuStack_22c = (undefined4 *****)0x0;
    ppuStack_230 = (undefined4 **)0x41ef16;
    func_0x00421870();
    fStack_21c = *(float *)((int)fVar16 + 0xe0);
    ppuStack_230 = *(undefined4 ***)((int)fVar16 + 0xd4);
    ppppuStack_234 = (undefined4 ****)0x41ef30;
    pfVar7 = (float *)func_0x00799460();
    ppppuStack_234 = (undefined4 ****)((float)ppppuStack_220 * pfVar7[3]);
    pppuStack_238 = (undefined4 ***)((float)ppppuStack_220 * pfVar7[2]);
    fStack_23c = (float)ppppuStack_220 * pfVar7[1];
    ppppuStack_240 = (undefined4 ****)((float)ppppuStack_220 * *pfVar7);
    pfStack_244 = (float *)0x41ef64;
    func_0x004217f0();
    pfStack_244 = &fStack_224;
    iStack_248 = 0x41ef77;
    iStack_248 = func_0x00410950();
    ppppuStack_24c = (undefined4 ****)0x41ef7f;
    func_0x00410950();
    ppppuStack_24c = (undefined4 ****)0x0;
    pfStack_250 = (float *)0x0;
    iStack_254 = 0;
    iStack_258 = 0;
    pppuStack_25c = (undefined4 ***)0x41ef8b;
    func_0x00421870();
    pppuStack_25c = *(undefined4 ****)((int)fVar16 + 0xd8);
    ppppuStack_260 = (undefined4 ****)0x41ef9b;
    func_0x00799460();
    ppppuStack_260 = &ppppuStack_240;
    uStack_264 = 0x41efab;
    uStack_264 = func_0x00410950();
    fStack_268 = 6.055301e-39;
    func_0x00410950();
    fStack_268 = 0.0;
    uStack_26c = 0;
    uStack_270 = 0;
    uStack_274 = 0;
    uStack_278 = 0x41efc6;
    func_0x00421870();
    uStack_278 = *(undefined4 *)((int)fVar16 + 0xdc);
    uStack_264 = *(undefined4 *)((int)fVar16 + 0xe4);
    fStack_27c = 6.055358e-39;
    pfVar7 = (float *)func_0x00799460();
    fStack_27c = fStack_268 * pfVar7[3];
    fStack_280 = fStack_268 * pfVar7[2];
    fStack_284 = fStack_268 * pfVar7[1];
    fStack_288 = fStack_268 * *pfVar7;
    puStack_28c = (undefined4 *)0x41f014;
    func_0x004217f0();
    puStack_28c = &uStack_26c;
    uStack_290 = 0x41f024;
    uStack_290 = func_0x00410950();
    uStack_294 = 0x41f030;
    func_0x00410950();
    uStack_294 = 0;
    uStack_298 = 0;
    uStack_29c = 0;
    uStack_2a0 = 0;
    uStack_2a4 = 0x41f03f;
    func_0x00421870();
    uStack_2a4 = *(undefined4 *)((int)fVar16 + 0xe8);
    pfStack_2a8 = (float *)0x41f04f;
    func_0x00799460();
    pfStack_2a8 = &fStack_288;
    uStack_2ac = 0x41f05f;
    uStack_2ac = func_0x00410950();
    fStack_2b0 = 6.055553e-39;
    func_0x00410950();
    fStack_2b0 = 0.0;
    uStack_2b4 = 0;
    uStack_2b8 = 0;
    uStack_2bc = 0;
    uStack_2c0 = 0x41f07a;
    func_0x00421870();
    uStack_2ac = *(undefined4 *)((int)fVar16 + 0xe0);
    uStack_2c0 = *(undefined4 *)((int)fVar16 + 0xf0);
    fStack_2c4 = 6.05561e-39;
    pfVar7 = (float *)func_0x00799460();
    fStack_2c4 = fStack_2b0 * pfVar7[3];
    fStack_2c8 = fStack_2b0 * pfVar7[2];
    fStack_2cc = fStack_2b0 * pfVar7[1];
    fStack_2d0 = fStack_2b0 * *pfVar7;
    puStack_2d4 = (undefined4 *)0x41f0c8;
    func_0x004217f0();
    puStack_2d4 = &uStack_2b4;
    uStack_2d8 = 0x41f0d8;
    uStack_2d8 = func_0x00410950();
    uStack_2dc = 0x41f0e4;
    func_0x00410950();
    uStack_2dc = 0;
    iStack_2e0 = 0;
    uStack_2e4 = 0;
    iStack_2e8 = 0;
    uStack_2ec = 0x41f0f3;
    func_0x00421870();
    uStack_2ec = *(undefined4 *)((int)fVar16 + 0xec);
    pfStack_2f0 = (float *)0x41f103;
    func_0x00799460();
    pfStack_2f0 = &fStack_2d0;
    uStack_2f4 = 0x41f113;
    uStack_2f4 = func_0x00410950();
    fStack_2f8 = 6.055805e-39;
    func_0x00410950();
    fStack_2f8 = 0.0;
    uStack_2fc = 0;
    uStack_300 = 0;
    fStack_304 = 0.0;
    uStack_308 = 0x41f12e;
    func_0x00421870();
    uStack_2f4 = *(undefined4 *)((int)fVar16 + 0xe4);
    uStack_308 = *(undefined4 *)((int)fVar16 + 0xf4);
    fStack_30c = 6.055863e-39;
    pfVar7 = (float *)func_0x00799460();
    fStack_30c = fStack_2f8 * pfVar7[3];
    fStack_310 = fStack_2f8 * pfVar7[2];
    fStack_314 = fStack_2f8 * pfVar7[1];
    fStack_318 = fStack_2f8 * *pfVar7;
    puStack_31c = (undefined4 *)0x41f17c;
    func_0x004217f0();
    puStack_31c = &uStack_2fc;
    fStack_320 = 6.055958e-39;
    fStack_320 = (float)func_0x00410950();
    fStack_324 = 6.055975e-39;
    func_0x00410950();
    fStack_324 = 0.0;
    fStack_328 = 0.0;
    fStack_32c = 0.0;
    fStack_330 = 0.0;
    fStack_334 = 6.055996e-39;
    func_0x00421870();
    fStack_304 = 0.0;
    iVar8 = *(int *)(_DAT_009b3eec + 0xc);
    uStack_290 = *(undefined4 *)(iVar8 + 0x10);
    fStack_334 = (float)(iVar8 + 0x14);
    fStack_338 = 6.056052e-39;
    func_0x00410950();
    fStack_338 = (float)(iVar8 + 0x24);
    fStack_33c = 6.056074e-39;
    func_0x00410950();
    fStack_33c = (float)(iVar8 + 0x34);
    fStack_340 = 6.056097e-39;
    func_0x00410950();
    fStack_340 = (float)(iVar8 + 0x44);
    fStack_344 = 6.056119e-39;
    func_0x00401cc0();
    fStack_344 = (float)(iVar8 + 0x50);
    fStack_348 = 6.056142e-39;
    func_0x00401cc0();
    iStack_258 = *(int *)(iVar8 + 0x5c);
    iStack_254 = *(int *)(iVar8 + 0x60);
    pfStack_250 = *(float **)(iVar8 + 100);
    ppppuStack_24c = *(undefined4 *****)(iVar8 + 0x68);
    iStack_248 = *(int *)(iVar8 + 0x6c);
    pfStack_244 = *(float **)(iVar8 + 0x70);
    ppppuStack_240 = *(undefined4 *****)(iVar8 + 0x74);
    fStack_348 = (float)(iStack_2e0 + 0xc4);
    ppfStack_34c = (float **)0x41f269;
    func_0x00401cc0();
    uStack_264 = uStack_308;
    fStack_268 = fStack_30c;
    ppfStack_34c = &pfStack_2a8;
    ppppuStack_260 = (undefined4 ****)fStack_304;
    puStack_350 = (undefined4 *)0x41f2a0;
    FUN_0079b390();
    iVar8 = *(int *)(*(int *)(param_1 + 4) + 0x50);
    if (iVar8 != 0) {
      *(byte *)(iVar8 + 0x84) = (byte)(*(uint *)(iStack_2e8 + 0x80) >> 3) & 1;
      *(byte *)(*(int *)(*(int *)(param_1 + 4) + 0x50) + 0x85) =
           (byte)(*(uint *)(iStack_2e8 + 0x80) >> 4) & 1;
      puStack_350 = &uStack_26c;
      fStack_354 = 6.05645e-39;
      func_0x004b60b0();
    }
    fStack_354 = 6.056461e-39;
    puStack_350 = (undefined4 *)fVar16;
    func_0x00421520();
  }
  if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 0x18) + 0x5b4) != 0) goto LAB_00420807;
  iVar8 = *(int *)(*(int *)(param_1 + 4) + 0x50);
  fStack_340 = *(float *)(iVar8 + 0x70);
  if (fStack_340 == _DAT_008d58a0) {
    fStack_358 = *(float *)((int)fVar16 + 0x108);
    fStack_35c = *(float *)((int)fVar16 + 0x104);
    fStack_360 = *(float *)((int)fVar16 + 0x100);
    fStack_354 = 0.0;
    fStack_364 = 6.062687e-39;
    cVar5 = FUN_0079ac30();
    if (cVar5 == '\0') goto LAB_00420807;
    fStack_360 = *(float *)((int)fVar16 + 0x104);
    fStack_354 = 0.0;
    fStack_358 = fStack_324;
    fStack_364 = (float)*(undefined4 *)((int)fVar16 + 0x100);
    fStack_35c = (float)*(undefined4 *)((int)fVar16 + 0x108);
  }
  else if (fStack_340 == _DAT_008d5c28) {
    fStack_358 = *(float *)((int)fVar16 + 0x114);
    fStack_35c = *(float *)((int)fVar16 + 0x110);
    fStack_360 = *(float *)((int)fVar16 + 0x10c);
    fStack_354 = 0.0;
    fStack_364 = 6.06281e-39;
    cVar5 = FUN_0079ac30();
    if (cVar5 == '\0') goto LAB_00420807;
    fStack_360 = *(float *)((int)fVar16 + 0x110);
    fStack_354 = 0.0;
    fStack_358 = fStack_324;
    fStack_364 = (float)*(undefined4 *)((int)fVar16 + 0x10c);
    fStack_35c = (float)*(undefined4 *)((int)fVar16 + 0x114);
  }
  else {
    bVar3 = *(float *)(iVar8 + 0x74) != _DAT_008d58a0;
    if ((char)ppppuStack_1b4 != '\0') {
      if (bVar3) {
        fStack_358 = *(float *)((int)fVar16 + 0x108);
        fStack_35c = *(float *)((int)fVar16 + 0x104);
        fStack_360 = *(float *)((int)fVar16 + 0x100);
        fStack_354 = 0.0;
        fStack_364 = 6.063353e-39;
        cVar5 = FUN_0079ac30();
        if (cVar5 != '\0') {
          fStack_35c = *(float *)((int)fVar16 + 0x108);
          fStack_360 = *(float *)((int)fVar16 + 0x104);
          fStack_364 = *(float *)((int)fVar16 + 0x100);
          fStack_354 = 0.0;
          fStack_358 = 0.0;
          fStack_368 = 6.063409e-39;
          FUN_0079aeb0();
        }
        if (_DAT_008d5894 < fStack_340) {
          fStack_354 = 6.063453e-39;
          iVar8 = func_0x004b6250();
          fStack_324 = (float)(iVar8 / 2);
          fStack_354 = 6.063498e-39;
          iVar8 = func_0x00892e78();
          fStack_35c = *(float *)((int)fVar16 + 0x110);
          fStack_360 = *(float *)((int)fVar16 + 0x10c);
          fStack_358 = *(float *)((int)fVar16 + 0x114);
          fStack_354 = 0.0;
          fStack_364 = 6.063549e-39;
          cVar5 = FUN_0079ac30();
          if (cVar5 != '\0') {
            fStack_36c = *(float *)((int)fVar16 + 0x114);
            fStack_370 = *(float *)((int)fVar16 + 0x110);
            fStack_374 = *(float *)((int)fVar16 + 0x10c);
            fStack_364 = 0.0;
            fStack_378 = 6.063603e-39;
            fStack_368 = (float)iVar8;
            FUN_0079aeb0();
          }
          cVar5 = *(char *)(*(int *)(*(int *)(param_1 + 4) + 0x18) + 0x5b9);
          while (cVar5 != '\0') {
            fStack_364 = 1.4013e-44;
            fStack_368 = 6.06364e-39;
            Sleep();
            cVar5 = *(char *)(*(int *)(*(int *)(param_1 + 4) + 0x18) + 0x5b9);
          }
          fStack_364 = 6.063678e-39;
          iVar9 = func_0x004b6250();
          fStack_364 = (float)(iVar9 / 2 - iVar8);
          fStack_368 = 6.063704e-39;
          FUN_0079b150();
        }
      }
      else {
        fStack_358 = *(float *)((int)fVar16 + 0x114);
        fStack_35c = *(float *)((int)fVar16 + 0x110);
        fStack_360 = *(float *)((int)fVar16 + 0x10c);
        fStack_354 = 0.0;
        fStack_364 = 6.06296e-39;
        cVar5 = FUN_0079ac30();
        if (cVar5 != '\0') {
          fStack_35c = *(float *)((int)fVar16 + 0x114);
          fStack_360 = *(float *)((int)fVar16 + 0x110);
          fStack_364 = *(float *)((int)fVar16 + 0x10c);
          fStack_354 = 0.0;
          fStack_358 = 0.0;
          fStack_368 = 6.063016e-39;
          FUN_0079aeb0();
        }
        if (fStack_340 < _DAT_008d62dc) {
          fStack_354 = 6.063061e-39;
          iVar8 = func_0x004b6250();
          fStack_324 = (float)(iVar8 / 2);
          fStack_354 = 6.0631e-39;
          iVar8 = func_0x00892e78();
          fStack_35c = *(float *)((int)fVar16 + 0x104);
          fStack_360 = *(float *)((int)fVar16 + 0x100);
          fStack_358 = *(float *)((int)fVar16 + 0x108);
          fStack_354 = 0.0;
          fStack_364 = 6.063151e-39;
          cVar5 = FUN_0079ac30();
          if (cVar5 != '\0') {
            fStack_36c = *(float *)((int)fVar16 + 0x108);
            fStack_370 = *(float *)((int)fVar16 + 0x104);
            fStack_374 = *(float *)((int)fVar16 + 0x100);
            fStack_364 = 0.0;
            fStack_378 = 6.063205e-39;
            fStack_368 = (float)iVar8;
            FUN_0079aeb0();
          }
          cVar5 = *(char *)(*(int *)(*(int *)(param_1 + 4) + 0x18) + 0x5b9);
          while (cVar5 != '\0') {
            fStack_364 = 1.4013e-44;
            fStack_368 = 6.063242e-39;
            Sleep();
            cVar5 = *(char *)(*(int *)(*(int *)(param_1 + 4) + 0x18) + 0x5b9);
          }
          fStack_364 = 6.06328e-39;
          iVar9 = func_0x004b6250();
          fStack_364 = (float)(iVar9 / 2 - iVar8);
          fStack_368 = 6.063306e-39;
          FUN_0079b150();
        }
      }
      goto LAB_00420807;
    }
    if (bVar3) {
      if (fStack_340 <= _DAT_008d5894) goto LAB_00420807;
      fStack_358 = *(float *)((int)fVar16 + 0x114);
      fStack_35c = *(float *)((int)fVar16 + 0x110);
      fStack_360 = *(float *)((int)fVar16 + 0x10c);
      fStack_354 = 0.0;
      fStack_364 = 6.063934e-39;
      cVar5 = FUN_0079ac30();
      if (cVar5 == '\0') goto LAB_00420807;
      fStack_324 = *(float *)((int)fVar16 + 0x110);
      uVar13 = *(undefined4 *)((int)fVar16 + 0x114);
      uVar2 = *(undefined4 *)((int)fVar16 + 0x10c);
      fStack_354 = 0.0;
      fStack_358 = 6.063989e-39;
      iVar8 = func_0x004b6250();
      fStack_358 = (float)(iVar8 / 2);
      fStack_360 = fStack_324;
      fStack_364 = (float)uVar2;
      fStack_35c = (float)uVar13;
    }
    else {
      if (_DAT_008d62dc <= fStack_340) goto LAB_00420807;
      fStack_358 = *(float *)((int)fVar16 + 0x108);
      fStack_35c = *(float *)((int)fVar16 + 0x104);
      fStack_360 = *(float *)((int)fVar16 + 0x100);
      fStack_354 = 0.0;
      fStack_364 = 6.063787e-39;
      cVar5 = FUN_0079ac30();
      if (cVar5 == '\0') goto LAB_00420807;
      fStack_324 = *(float *)((int)fVar16 + 0x104);
      uVar13 = *(undefined4 *)((int)fVar16 + 0x108);
      uVar2 = *(undefined4 *)((int)fVar16 + 0x100);
      fStack_354 = 0.0;
      fStack_358 = 6.063847e-39;
      iVar8 = func_0x004b6250();
      fStack_358 = (float)(iVar8 / 2);
      fStack_360 = fStack_324;
      fStack_364 = (float)uVar2;
      fStack_35c = (float)uVar13;
    }
  }
  fStack_368 = 6.064022e-39;
  FUN_0079aeb0();
LAB_00420807:
  fStack_354 = fStack_33c * *(float *)(param_1 + 0x798);
  fStack_358 = fStack_33c * *(float *)(param_1 + 0x794);
  fStack_35c = fStack_33c * *(float *)(param_1 + 0x790);
  fStack_360 = fStack_33c * *(float *)(param_1 + 0x78c);
  fStack_364 = 6.064109e-39;
  func_0x004217f0();
  fStack_364 = fStack_348 * *(float *)(param_1 + 0x738);
  fStack_368 = fStack_348 * *(float *)(param_1 + 0x734);
  fStack_36c = fStack_348 * *(float *)(param_1 + 0x730);
  fStack_370 = fStack_348 * *(float *)(param_1 + 0x72c);
  fStack_374 = 6.064182e-39;
  func_0x004217f0();
  fStack_374 = fStack_328 + fStack_338;
  fStack_378 = fStack_32c + fStack_33c;
  fStack_37c = fStack_330 + fStack_340;
  fStack_380 = fStack_334 + fStack_344;
  fStack_384 = 6.064262e-39;
  func_0x004217f0();
  fStack_30c = 1.0;
  fStack_370 = 1.0;
  if (*(int *)(*(int *)(param_1 + 4) + 0x50) != 0) {
    fStack_38c = fStack_36c * _DAT_008d5894;
    fStack_384 = fStack_36c;
    fStack_388 = 0.0;
    fStack_354 = fStack_36c;
    fStack_390 = fStack_36c;
    fStack_394 = 6.064353e-39;
    func_0x004217f0();
    fStack_394 = fStack_378 * *(float *)(param_1 + 0x738);
    fStack_398 = fStack_378 * *(float *)(param_1 + 0x734);
    fStack_39c = fStack_378 * *(float *)(param_1 + 0x730);
    fStack_3a0 = fStack_378 * *(float *)(param_1 + 0x72c);
    fStack_3a4 = 6.064426e-39;
    func_0x004217f0();
    fStack_3a4 = fStack_358 + fStack_368;
    uStack_3a8 = (undefined4 *)(fStack_35c + fStack_36c);
    fStack_3ac = fStack_360 + fStack_370;
    fStack_3b0 = fStack_364 + fStack_374;
    func_0x004217f0();
    uVar10 = func_0x00799540();
    func_0x004b6090(uVar10 | 0xff000000);
    uVar10 = func_0x00799540();
    func_0x004b60a0(uVar10 | 0xff000000);
    *(byte *)(*(int *)(*(int *)(param_1 + 4) + 0x50) + 0x84) =
         (byte)(*(uint *)((int)fStack_354 + 0x80) >> 3) & 1;
    *(byte *)(*(int *)(*(int *)(param_1 + 4) + 0x50) + 0x85) =
         (byte)(*(uint *)((int)fStack_354 + 0x80) >> 4) & 1;
    iVar8 = *(int *)(param_1 + 4);
    iVar9 = *(int *)(iVar8 + 0x50);
    if (*(float *)(iVar9 + 0x4c) <= _DAT_008d58a0) {
      func_0x007994d0(*(undefined4 *)(iVar9 + 0x48));
      fStack_370 = *(float *)(*(int *)(*(int *)(param_1 + 4) + 0x50) + 0x50) * _DAT_008d67fc;
      if (_DAT_008d58a0 <= fStack_370) {
        if (_DAT_008d62dc < fStack_370) {
          fStack_370 = 0.8;
        }
      }
      else {
        fStack_370 = 0.0;
      }
    }
    else if (*(float *)(iVar9 + 0x74) == _DAT_008d5c28) {
      if (_DAT_008d5894 <= fStack_3a4) {
        fStack_38c = (fStack_3a4 - _DAT_008d5894) + (fStack_3a4 - _DAT_008d5894);
        pfVar7 = (float *)func_0x00799460(*(undefined4 *)(*(int *)(iVar8 + 0x50) + 0x48));
        func_0x004217f0(fStack_390 * *pfVar7,fStack_390 * pfVar7[1],fStack_390 * pfVar7[2],
                        fStack_390 * pfVar7[3]);
        pfVar7 = (float *)func_0x00799460(*(undefined4 *)
                                           (*(int *)(*(int *)(param_1 + 4) + 0x50) + 0x44));
        fStack_370 = fStack_370 + fStack_370;
        fStack_394 = fStack_370 * *pfVar7;
        fStack_390 = fStack_370 * pfVar7[1];
        fStack_38c = fStack_370 * pfVar7[2];
        func_0x004217f0(fStack_380 + fStack_394,fStack_37c + fStack_390,fStack_378 + fStack_38c,
                        fStack_374 + fStack_370 * pfVar7[3]);
        fStack_318 = fStack_364;
        fStack_314 = fStack_360;
        fStack_310 = fStack_35c;
        fStack_370 = fStack_320;
      }
      else {
        func_0x007994d0(*(undefined4 *)(iVar9 + 0x44));
      }
    }
    else if (_DAT_008d609c <= fStack_3a4) {
      fStack_38c = fStack_3a4 - _DAT_008d6804;
      pfVar7 = (float *)func_0x00799460(*(undefined4 *)(*(int *)(iVar8 + 0x50) + 0x48));
      fStack_380 = fStack_390 * *pfVar7;
      fStack_37c = fStack_390 * pfVar7[1];
      fStack_378 = fStack_390 * pfVar7[2];
      fStack_374 = fStack_390 * pfVar7[3];
      pfVar7 = (float *)func_0x00799460(*(undefined4 *)
                                         (*(int *)(*(int *)(param_1 + 4) + 0x50) + 0x44));
      fStack_360 = fStack_360 * _DAT_008d6800;
      fStack_394 = fStack_360 * *pfVar7;
      fStack_390 = fStack_360 * pfVar7[1];
      fStack_38c = fStack_360 * pfVar7[2];
      func_0x004217f0(fStack_394 + fStack_384,fStack_390 + fStack_380,fStack_38c + fStack_37c,
                      fStack_360 * pfVar7[3] + fStack_378);
      fStack_318 = fStack_364;
      fStack_314 = fStack_360;
      fStack_310 = fStack_35c;
      fStack_370 = fStack_320;
    }
    else {
      func_0x007994d0(*(undefined4 *)(iVar9 + 0x44));
    }
  }
  fStack_30c = 1.0;
  iVar8 = *(int *)(_DAT_009b3eec + 0xc);
  uStack_278 = *(undefined4 *)(iVar8 + 0x10);
  fStack_384 = (float)(iVar8 + 0x14);
  fStack_388 = 6.065638e-39;
  func_0x00410950();
  fStack_388 = (float)(iVar8 + 0x24);
  fStack_38c = 6.06566e-39;
  func_0x00410950();
  fStack_38c = (float)(iVar8 + 0x34);
  fStack_390 = 6.065683e-39;
  func_0x00410950();
  fStack_390 = (float)(iVar8 + 0x44);
  fStack_394 = 6.065705e-39;
  func_0x00401cc0();
  fStack_394 = (float)(iVar8 + 0x50);
  fStack_398 = 6.065728e-39;
  func_0x00401cc0();
  ppppuStack_240 = *(undefined4 *****)(iVar8 + 0x5c);
  fStack_23c = *(float *)(iVar8 + 0x60);
  pppuStack_238 = *(undefined4 ****)(iVar8 + 100);
  ppppuStack_234 = *(undefined4 *****)(iVar8 + 0x68);
  fStack_398 = fStack_384 * fStack_320;
  ppuStack_230 = *(undefined4 ***)(iVar8 + 0x6c);
  ppppuStack_22c = *(undefined4 *****)(iVar8 + 0x70);
  ppppuStack_228 = *(undefined4 *****)(iVar8 + 0x74);
  fStack_39c = fStack_324 * fStack_384;
  fStack_288 = fStack_32c;
  fStack_284 = fStack_328;
  fStack_280 = fStack_324;
  fStack_3a0 = fStack_328 * fStack_384;
  fStack_27c = fStack_320;
  fStack_3a4 = fStack_32c * fStack_384;
  uStack_3a8 = (undefined4 *)0x420d73;
  func_0x004217f0();
  fStack_288 = fStack_388;
  fStack_284 = fStack_384;
  uStack_3a8 = &uStack_29c;
  fStack_280 = fStack_380;
  fStack_27c = 1.0;
  fStack_3ac = 6.06606e-39;
  FUN_0079b390();
  iVar8 = *(int *)(*(int *)(_DAT_009b3eec + 0x1c) + 0x20);
  if ((iVar8 == 0) || (*(char *)(iVar8 + 0xb0f) == '\0')) {
    fStack_378 = fStack_394 * *(float *)(param_1 + 0x760);
    fStack_374 = fStack_394 * *(float *)(param_1 + 0x764);
    fStack_370 = fStack_394 * *(float *)(param_1 + 0x768);
    fStack_368 = fStack_390 * *(float *)(param_1 + 0x700);
    fStack_364 = fStack_390 * *(float *)(param_1 + 0x704);
    fStack_360 = fStack_390 * *(float *)(param_1 + 0x708);
    fStack_358 = fStack_390 * *(float *)(param_1 + 0x6fc) + fStack_394 * *(float *)(param_1 + 0x75c)
    ;
    fStack_354 = fStack_368 + fStack_378;
    puStack_350 = (undefined4 *)(fStack_364 + fStack_374);
    ppfStack_34c = (float **)(fStack_360 + fStack_370);
    fStack_3ac = 6.066339e-39;
    uVar10 = func_0x00799540();
    fStack_3ac = (float)(uVar10 | 0xff000000);
  }
  else {
    fStack_3ac = -NAN;
  }
  fStack_3b0 = 6.066357e-39;
  func_0x0077a450();
  if (*(int *)(*(int *)(param_1 + 4) + 0x48) != 0) {
    fStack_37c = fStack_398 * *(float *)(param_1 + 0x850);
    fStack_378 = fStack_398 * *(float *)(param_1 + 0x854);
    fStack_374 = fStack_398 * *(float *)(param_1 + 0x858);
    fStack_390 = fStack_394 * *(float *)(param_1 + 0x81c) + fStack_398 * *(float *)(param_1 + 0x84c)
    ;
    fStack_38c = fStack_394 * *(float *)(param_1 + 0x820) + fStack_37c;
    fStack_388 = fStack_394 * *(float *)(param_1 + 0x824) + fStack_378;
    fStack_384 = fStack_394 * *(float *)(param_1 + 0x828) + fStack_374;
    fStack_370 = fStack_398 * *(float *)(param_1 + 0x7ec);
    fStack_36c = fStack_398 * *(float *)(param_1 + 0x7f0);
    fStack_368 = fStack_398 * *(float *)(param_1 + 0x7f4);
    fStack_364 = fStack_398 * *(float *)(param_1 + 0x7f8);
    fStack_3b0 = fStack_394 * *(float *)(param_1 + 0x7c8);
    func_0x004217f0(fStack_394 * *(float *)(param_1 + 0x7bc),
                    fStack_394 * *(float *)(param_1 + 0x7c0),
                    fStack_394 * *(float *)(param_1 + 0x7c4));
    func_0x004217f0(fStack_36c + fStack_380,fStack_368 + fStack_37c,fStack_364 + fStack_378,
                    fStack_360 + fStack_374);
    func_0x006465e0(&fStack_3a0,&fStack_3b0);
  }
  fVar15 = _DAT_00951180;
  if (_DAT_008d5c28 < _DAT_00951180) {
    fVar15 = _DAT_008d5c28;
  }
  fStack_37c = fStack_398 * *(float *)(param_1 + 0x5ec);
  fStack_378 = fStack_398 * *(float *)(param_1 + 0x5f0);
  fStack_374 = fStack_398 * *(float *)(param_1 + 0x5f4);
  fStack_36c = fStack_394 * *(float *)(param_1 + 0x598);
  fStack_368 = fStack_394 * *(float *)(param_1 + 0x59c);
  fStack_364 = fStack_394 * *(float *)(param_1 + 0x5a0);
  fStack_390 = fStack_394 * *(float *)(param_1 + 0x594) + fStack_398 * *(float *)(param_1 + 0x5e8);
  fStack_38c = fStack_36c + fStack_37c;
  fStack_388 = fStack_368 + fStack_378;
  fStack_384 = fStack_364 + fStack_374;
  fStack_3b0 = (fStack_394 * *(float *)(param_1 + 0x5d0) + fStack_398 * *(float *)(param_1 + 0x624))
               * _DAT_00951180;
  fVar15 = (fStack_394 * *(float *)(param_1 + 0x5c4) + fStack_398 * *(float *)(param_1 + 0x618)) *
           fVar15;
  fVar11 = (float)func_0x00799540(fVar15);
  FUN_00780990(fVar11);
  fVar23 = fStack_3a4 * *(float *)(param_1 + 0x69c);
  fVar16 = fStack_3a4 * *(float *)(param_1 + 0x698);
  fVar22 = fStack_3a4 * *(float *)(param_1 + 0x694);
  func_0x004217f0(fStack_3a4 * *(float *)(param_1 + 0x690),fVar22,fVar16,fVar23);
  fVar19 = fStack_3b0 * *(float *)(param_1 + 0x644);
  fVar12 = fStack_3b0 * *(float *)(param_1 + 0x640);
  func_0x004217f0(fStack_3b0 * *(float *)(param_1 + 0x63c),fVar12,fVar19,
                  fStack_3b0 * *(float *)(param_1 + 0x648));
  fVar18 = fStack_3b0 + fStack_37c;
  fVar15 = fVar15 + fStack_380;
  func_0x004217f0(fVar23 + fStack_388,fVar11 + fStack_384,fVar15,fVar18);
  fVar20 = fVar12 * *(float *)(param_1 + 0x6cc) + fVar19 * *(float *)(param_1 + 0x678);
  fVar19 = fVar19 * *(float *)(param_1 + 0x66c) + fVar12 * *(float *)(param_1 + 0x6c0);
  fVar12 = (float)func_0x00799540(fVar19,fVar20);
  FUN_007809c0(fVar12);
  cVar5 = uStack_3a8._3_1_;
  if (uStack_3a8._3_1_ == '\0') {
    fStack_394 = _DAT_00951180;
    if (_DAT_008d5c28 < _DAT_00951180) {
      fStack_394 = _DAT_008d5c28;
    }
    fStack_394 = (fVar18 * *(float *)(param_1 + 0x5c4) + fVar15 * *(float *)(param_1 + 0x618)) *
                 fStack_394;
    fVar21 = (fVar18 * *(float *)(param_1 + 0x5d0) + fVar15 * *(float *)(param_1 + 0x624)) *
             _DAT_00951180;
    fStack_390 = fVar18 * *(float *)(param_1 + 0x5dc) + fVar15 * *(float *)(param_1 + 0x630);
    fStack_3b0 = fVar18 * *(float *)(param_1 + 0x59c);
    fVar17 = fStack_3b0 + fVar15 * *(float *)(param_1 + 0x5f0);
    func_0x004217f0(fVar18 * *(float *)(param_1 + 0x594) + fVar15 * *(float *)(param_1 + 0x5e8),
                    fVar18 * *(float *)(param_1 + 0x598) + fVar15 * *(float *)(param_1 + 0x5ec),
                    fVar17,fVar18 * *(float *)(param_1 + 0x5a0) +
                           fVar15 * *(float *)(param_1 + 0x5f4));
  }
  else {
    fStack_394 = fVar18 * *(float *)(param_1 + 0x66c) + fVar15 * *(float *)(param_1 + 0x6c0);
    fVar21 = fVar15 * *(float *)(param_1 + 0x6cc) + fVar18 * *(float *)(param_1 + 0x678);
    fStack_390 = fVar18 * *(float *)(param_1 + 0x684) + fVar15 * *(float *)(param_1 + 0x6d8);
    fVar18 = fVar15 * *(float *)(param_1 + 0x69c);
    fVar17 = fVar15 * *(float *)(param_1 + 0x698);
    func_0x004217f0(fVar15 * *(float *)(param_1 + 0x690),fVar15 * *(float *)(param_1 + 0x694),fVar17
                    ,fVar18);
    func_0x004217f0(fVar20 * *(float *)(param_1 + 0x63c),fVar20 * *(float *)(param_1 + 0x640),
                    fVar20 * *(float *)(param_1 + 0x644),fVar20 * *(float *)(param_1 + 0x648));
    func_0x004217f0(fVar18 + fVar22,fVar12 + fVar16,fVar19 + fVar23,fVar20 + fVar11);
  }
  uVar13 = func_0x00799540();
  func_0x0077ac40(fVar22);
  func_0x0077ac60(fVar17);
  func_0x0077ac80(fVar21);
  func_0x0077ac20(uVar13);
  *(undefined4 *)(*(int *)(*(int *)(_DAT_009b3eec + 0x14) + 4) + 0x10) = uVar13;
  iVar8 = *(int *)(_DAT_009b3eec + 0x1c);
  if (*(int *)(iVar8 + 0x1c) != 0) {
    if (*(int *)(iVar8 + 0x90) == 1) {
      uVar13 = 5;
    }
    else if ((*(int *)(iVar8 + 0x20) == 0) ||
            ((*(uint *)(*(int *)(iVar8 + 0x20) + 0x668) >> 7 & 1) == 0)) {
      if (cVar5 == '\0') {
        if (_DAT_008d5894 <= *(float *)(*(int *)(*(int *)(param_1 + 4) + 0x50) + 0x70)) {
          uVar13 = 2;
        }
        else {
          uVar13 = 1;
        }
      }
      else {
        uVar13 = 3;
      }
    }
    else {
      uVar13 = 4;
    }
    func_0x00410bb0(uVar13,0xffffffff);
    func_0x0040fcc0(pfStack_2a8);
  }
  *(char *)(param_1 + 0x58c) = cVar5;
  return 1;
}


