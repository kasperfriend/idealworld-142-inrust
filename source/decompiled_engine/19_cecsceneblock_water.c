/* Authentic Ghidra 12.1.4 Decompilation — elementclient.exe (PW 1.4.2 Build 2305) */
/* Module: 19_cecsceneblock_water.c */

/* ==================================================================== */
/* Address: 0x00421d50 | Classified: elementclient::AList2__AllocNode__Not_enough_me@0x421d50 */
/* ==================================================================== */

undefined4 * __fastcall FUN_00421d50(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a740b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (*(int *)(param_1 + 0xc) == 0) {
    puVar2 = (undefined4 *)func_0x00763250(0x10);
    uStack_4 = 0;
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x14);
      *puVar2 = &UNK_008d6810;
      puVar2[3] = iVar1;
      uVar3 = func_0x00763250(iVar1 * 0xc);
      iVar5 = iVar1 + -1;
      puVar2[2] = uVar3;
      if (0 < iVar5) {
        iVar4 = 0;
        do {
          *(int *)(iVar4 + puVar2[2]) = iVar4 + 0xc + puVar2[2];
          iVar4 = iVar4 + 0xc;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      *(undefined4 *)(iVar1 * 0xc + -0xc + puVar2[2]) = 0;
      puVar2[1] = 0;
    }
    uStack_4 = 0xffffffff;
    if (puVar2 == (undefined4 *)0x0) {
      func_0x00764590(1,0x950554);
      *unaff_FS_OFFSET = uStack_c;
      return (undefined4 *)0x0;
    }
    *(undefined4 *)(param_1 + 0xc) = puVar2[2];
    puVar2[1] = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 **)(param_1 + 0x18) = puVar2;
  }
  puVar2 = *(undefined4 **)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0xc) = *puVar2;
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  *puVar2 = 0;
  puVar2[1] = 0;
  *unaff_FS_OFFSET = uStack_c;
  return puVar2;
}


/* ==================================================================== */
/* Address: 0x00421e50 | Classified: HH::?$AList2::c_NodePool::vfunc_slot_0 */
/* ==================================================================== */

undefined4 * __thiscall FUN_00421e50(undefined4 *param_1,byte param_2)

{
  *param_1 = &UNK_008d6810;
  if (param_1[2] != 0) {
    func_0x00763260(param_1[2]);
  }
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00421e80 | Classified: ElementClient::proc_421e80 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00421e80(float *param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  
  if ((param_3 != _DAT_008d58a0) && (*param_1 != param_2)) {
    fVar1 = param_3 * param_4 + *param_1;
    *param_1 = fVar1;
    if ((_DAT_008d58a0 < param_3) && (param_2 < fVar1)) {
      *param_1 = param_2;
      return;
    }
    if ((param_3 < _DAT_008d58a0) && (fVar1 < param_2)) {
      *param_1 = param_2;
      return;
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00421f00 | Classified: ElementClient::proc_421f00 */
/* ==================================================================== */

void __thiscall FUN_00421f00(undefined4 *param_1,undefined4 *param_2)

{
  param_1[4] = *param_2;
  param_1[5] = param_2[1];
  param_1[6] = param_2[2];
  param_1[7] = param_2[3];
  *param_1 = param_1[4];
  param_1[1] = param_1[5];
  param_1[2] = param_1[6];
  param_1[3] = param_1[7];
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00421f50 | Classified: ElementClient::proc_421f50 */
/* ==================================================================== */

undefined4 * __thiscall FUN_00421f50(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  param_1[0x14] = &UNK_008d651c;
  param_1[0x18] = 0x10;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x1a] = &UNK_008d6890;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0x10;
  param_1[0x1f] = &UNK_008d651c;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0x10;
  param_1[0x24] = &UNK_008d651c;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0x10;
  param_1[0x29] = &UNK_008d651c;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0x10;
  param_1[0x2e] = &UNK_008d651c;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0x10;
  param_1[0x33] = &UNK_008d651c;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0x10;
  param_1[0x38] = &UNK_008d651c;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0x10;
  param_1[0x3d] = &UNK_008d651c;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0x10;
  param_1[0x42] = &UNK_008d651c;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0x10;
  param_1[0x4b] = 0x10;
  param_1[0x47] = &UNK_008d651c;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  *param_1 = &UNK_008d6888;
  param_1[1] = param_2;
  param_1[4] = *(undefined4 *)(param_2 + 0x560);
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[0x19] = 0;
  param_1[8] = 0;
  param_1[7] = 0;
  param_1[6] = 0;
  param_1[5] = 0;
  puVar2 = param_1 + 9;
  for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x004220d0 | Classified: CECSceneBlock::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_004220d0(undefined4 param_1,byte param_2)

{
  FUN_004220f0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x004220f0 | Classified: ElementClient::proc_4220f0 */
/* ==================================================================== */

void __fastcall FUN_004220f0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  puStack_8 = &UNK_008a74a3;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008d6888;
  iStack_4 = 9;
  param_1[0x47] = &UNK_008d651c;
  if (param_1[0x48] != 0) {
    func_0x00763260(param_1[0x48]);
    param_1[0x48] = 0;
  }
  param_1[0x4a] = 0;
  param_1[0x49] = 0;
  iStack_4._0_1_ = 8;
  param_1[0x42] = &UNK_008d651c;
  if (param_1[0x43] != 0) {
    func_0x00763260(param_1[0x43]);
    param_1[0x43] = 0;
  }
  param_1[0x45] = 0;
  param_1[0x44] = 0;
  iStack_4._0_1_ = 7;
  param_1[0x3d] = &UNK_008d651c;
  if (param_1[0x3e] != 0) {
    func_0x00763260(param_1[0x3e]);
    param_1[0x3e] = 0;
  }
  param_1[0x40] = 0;
  param_1[0x3f] = 0;
  iStack_4._0_1_ = 6;
  param_1[0x38] = &UNK_008d651c;
  if (param_1[0x39] != 0) {
    func_0x00763260(param_1[0x39]);
    param_1[0x39] = 0;
  }
  param_1[0x3b] = 0;
  param_1[0x3a] = 0;
  iStack_4._0_1_ = 5;
  param_1[0x33] = &UNK_008d651c;
  if (param_1[0x34] != 0) {
    func_0x00763260(param_1[0x34]);
    param_1[0x34] = 0;
  }
  param_1[0x36] = 0;
  param_1[0x35] = 0;
  iStack_4._0_1_ = 4;
  param_1[0x2e] = &UNK_008d651c;
  if (param_1[0x2f] != 0) {
    func_0x00763260(param_1[0x2f]);
    param_1[0x2f] = 0;
  }
  param_1[0x31] = 0;
  param_1[0x30] = 0;
  iStack_4._0_1_ = 3;
  param_1[0x29] = &UNK_008d651c;
  if (param_1[0x2a] != 0) {
    func_0x00763260(param_1[0x2a]);
    param_1[0x2a] = 0;
  }
  param_1[0x2c] = 0;
  param_1[0x2b] = 0;
  iStack_4._0_1_ = 2;
  param_1[0x24] = &UNK_008d651c;
  if (param_1[0x25] != 0) {
    func_0x00763260(param_1[0x25]);
    param_1[0x25] = 0;
  }
  param_1[0x27] = 0;
  param_1[0x26] = 0;
  iStack_4._0_1_ = 1;
  param_1[0x1f] = &UNK_008d651c;
  if (param_1[0x20] != 0) {
    func_0x00763260(param_1[0x20]);
    param_1[0x20] = 0;
  }
  param_1[0x22] = 0;
  param_1[0x21] = 0;
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  param_1[0x1a] = &UNK_008d6890;
  if (param_1[0x1b] != 0) {
    func_0x00763260(param_1[0x1b]);
    param_1[0x1b] = 0;
  }
  param_1[0x1d] = 0;
  param_1[0x1c] = 0;
  iStack_4 = 0xffffffff;
  param_1[0x14] = &UNK_008d651c;
  if (param_1[0x15] != 0) {
    func_0x00763260(param_1[0x15]);
    param_1[0x15] = 0;
  }
  param_1[0x17] = 0;
  param_1[0x16] = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x00422330 | Classified: ElementClient::proc_422330 */
/* ==================================================================== */

void __fastcall FUN_00422330(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    FUN_00423c50();
    FUN_00423ca0();
    FUN_00423cf0();
    FUN_00423d40();
    FUN_00423da0();
    FUN_00423df0();
    FUN_00423e50();
    FUN_00423eb0();
    FUN_00423f20();
    FUN_00423f90();
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00422390 | Classified: elementclient::AArray__SetSize__Not_enough_memo@0x422390 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __thiscall FUN_00422390(int param_1,int *param_2,float param_3)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  float unaff_retaddr;
  float fVar7;
  float fStack_38;
  undefined4 uStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  float fStack_20;
  undefined4 uStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  float fStack_10;
  float fStack_8;
  uint3 uVar8;
  
  *(int **)(param_1 + 8) = param_2;
  *(float *)(param_1 + 0xc) = param_3;
  iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x4d0);
  if (iVar3 < 4) {
    cVar2 = (**(code **)(*param_2 + 0x10))(&uStack_2c);
    if (cVar2 == '\0') {
      return 0;
    }
    *(int ***)(param_1 + 0x28) = &param_2;
    *(undefined4 *)(param_1 + 0x2c) = unaff_ESI;
    *(float *)(param_1 + 0x34) = fStack_28;
    *(undefined4 *)(param_1 + 0x38) = uStack_24;
    *(undefined4 *)(param_1 + 0x30) = uStack_2c;
    *(undefined2 *)(param_1 + 0x24) = 0x18;
    *(undefined2 *)(param_1 + 0x26) = 0;
  }
  else if (iVar3 < 7) {
    cVar2 = (**(code **)(*param_2 + 0x10))(&uStack_2c);
    if (cVar2 == '\0') {
      return 0;
    }
    *(int ***)(param_1 + 0x28) = &param_2;
    *(undefined4 *)(param_1 + 0x2c) = unaff_ESI;
    *(float *)(param_1 + 0x34) = fStack_28;
    *(undefined4 *)(param_1 + 0x38) = uStack_24;
    *(undefined4 *)(param_1 + 0x30) = uStack_2c;
    *(float *)(param_1 + 0x3c) = fStack_20;
    *(undefined4 *)(param_1 + 0x40) = uStack_1c;
    *(float *)(param_1 + 0x44) = fStack_18;
    *(undefined2 *)(param_1 + 0x24) = 0x24;
    *(undefined2 *)(param_1 + 0x26) = 0;
  }
  else {
    if (iVar3 < 9) {
      cVar2 = (**(code **)(*param_2 + 0x10))(&uStack_2c);
      if (cVar2 == '\0') {
        return 0;
      }
      *(int ***)(param_1 + 0x28) = &param_2;
      *(undefined4 *)(param_1 + 0x2c) = unaff_ESI;
      *(float *)(param_1 + 0x34) = fStack_28;
      *(undefined4 *)(param_1 + 0x38) = uStack_24;
      *(undefined4 *)(param_1 + 0x30) = uStack_2c;
      *(float *)(param_1 + 0x3c) = fStack_20;
      *(undefined4 *)(param_1 + 0x40) = uStack_1c;
      *(float *)(param_1 + 0x44) = fStack_18;
      *(undefined4 *)(param_1 + 0x48) = uStack_14;
      *(undefined2 *)(param_1 + 0x24) = 0x28;
    }
    else {
      cVar2 = (**(code **)(*param_2 + 0x10))(&uStack_2c);
      if (cVar2 == '\0') {
        return 0;
      }
      *(int ***)(param_1 + 0x28) = &param_2;
      *(undefined4 *)(param_1 + 0x2c) = unaff_ESI;
      *(float *)(param_1 + 0x34) = fStack_28;
      *(undefined4 *)(param_1 + 0x38) = uStack_24;
      *(undefined4 *)(param_1 + 0x30) = uStack_2c;
      *(float *)(param_1 + 0x3c) = fStack_20;
      *(undefined4 *)(param_1 + 0x40) = uStack_1c;
      *(float *)(param_1 + 0x44) = fStack_18;
      *(undefined4 *)(param_1 + 0x48) = uStack_14;
      *(float *)(param_1 + 0x4c) = fStack_10;
      *(undefined2 *)(param_1 + 0x24) = 0x2c;
    }
    *(undefined2 *)(param_1 + 0x26) = 0;
  }
  *(float *)(param_1 + 0x14) = unaff_retaddr;
  *(int **)(param_1 + 0x18) = param_2;
  *(float *)(param_1 + 0x1c) = unaff_retaddr + *(float *)(param_1 + 0x10);
  *(float *)(param_1 + 0x20) = (float)param_2 - *(float *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x60) = 10;
  if (*(int *)(param_1 + 0x5c) < 10) {
    iVar3 = func_0x00763250(0x28);
    if (iVar3 == 0) {
      func_0x00764590(1,0x9505a4);
    }
    else {
      if (*(int *)(param_1 + 0x54) != 0) {
        iVar6 = *(int *)(param_1 + 0x58);
        if (9 < iVar6) {
          iVar6 = 10;
        }
        iVar4 = 0;
        if (0 < iVar6) {
          do {
            iVar4 = iVar4 + 1;
            *(undefined4 *)(iVar3 + -4 + iVar4 * 4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x54) + -4 + iVar4 * 4);
          } while (iVar4 < iVar6);
        }
        func_0x00763260(*(undefined4 *)(param_1 + 0x54));
      }
      *(undefined4 *)(param_1 + 0x58) = 10;
      *(undefined4 *)(param_1 + 0x5c) = 10;
      *(int *)(param_1 + 0x54) = iVar3;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x58) = 10;
  }
  puVar1 = *(undefined4 **)(param_1 + 0x54);
  uVar5 = (**(code **)(**(int **)(param_1 + 8) + 0x2c))();
  *puVar1 = uVar5;
  uVar8 = (uint3)((uint)unaff_retaddr >> 8);
  fVar7 = (float)CONCAT31(uVar8,1);
  if (param_3 <= _DAT_00951158) {
    fVar7 = (float)((uint)uVar8 << 8);
  }
  cVar2 = FUN_00422900(*(undefined4 *)(param_1 + 0x28),fVar7);
  if (cVar2 == '\0') {
    func_0x00764590(1,0x951400);
  }
  iVar3 = *(int *)(param_1 + 0x54);
  uVar5 = (**(code **)(**(int **)(param_1 + 8) + 0x2c))();
  *(undefined4 *)(iVar3 + 4) = uVar5;
  fStack_8 = (float)CONCAT31(fStack_8._1_3_,1);
  if (fVar7 <= _DAT_0095115c) {
    fStack_8 = (float)((uint)fStack_8._1_3_ << 8);
  }
  cVar2 = FUN_00422d70(*(undefined4 *)(param_1 + 0x2c),fStack_8);
  if (cVar2 == '\0') {
    func_0x00764590(1,0x9513c8);
  }
  iVar3 = *(int *)(param_1 + 0x54);
  uVar5 = (**(code **)(**(int **)(param_1 + 8) + 0x2c))();
  *(undefined4 *)(iVar3 + 8) = uVar5;
  fStack_10 = (float)CONCAT31(fStack_10._1_3_,1);
  if (fStack_8 <= _DAT_00951160) {
    fStack_10 = (float)((uint)fStack_10._1_3_ << 8);
  }
  cVar2 = FUN_00422f00(*(undefined4 *)(param_1 + 0x34),fStack_10);
  if (cVar2 == '\0') {
    func_0x00764590(1,0x95138c);
  }
  iVar3 = *(int *)(param_1 + 0x54);
  uVar5 = (**(code **)(**(int **)(param_1 + 8) + 0x2c))();
  *(undefined4 *)(iVar3 + 0xc) = uVar5;
  fStack_18 = (float)CONCAT31(fStack_18._1_3_,1);
  if (fStack_10 <= _DAT_00951164) {
    fStack_18 = (float)((uint)fStack_18._1_3_ << 8);
  }
  cVar2 = FUN_00423170(*(undefined4 *)(param_1 + 0x38),fStack_18);
  if (cVar2 == '\0') {
    func_0x00764590(1,0x951350);
  }
  iVar3 = *(int *)(param_1 + 0x54);
  uVar5 = (**(code **)(**(int **)(param_1 + 8) + 0x2c))();
  *(undefined4 *)(iVar3 + 0x10) = uVar5;
  fStack_20 = (float)CONCAT31(fStack_20._1_3_,1);
  if (fStack_18 <= _DAT_00951168) {
    fStack_20 = (float)((uint)fStack_20._1_3_ << 8);
  }
  cVar2 = FUN_00422be0(*(undefined4 *)(param_1 + 0x30),fStack_20);
  if (cVar2 == '\0') {
    func_0x00764590(1,0x951310);
  }
  iVar3 = *(int *)(param_1 + 0x54);
  uVar5 = (**(code **)(**(int **)(param_1 + 8) + 0x2c))();
  *(undefined4 *)(iVar3 + 0x14) = uVar5;
  fStack_28 = (float)CONCAT31(fStack_28._1_3_,1);
  if (fStack_20 <= _DAT_0095116c) {
    fStack_28 = (float)((uint)fStack_28._1_3_ << 8);
  }
  cVar2 = FUN_00423300(*(undefined4 *)(param_1 + 0x3c),fStack_28);
  if (cVar2 == '\0') {
    func_0x00764590(1,0x9512d4);
  }
  iVar3 = *(int *)(param_1 + 0x54);
  uVar5 = (**(code **)(**(int **)(param_1 + 8) + 0x2c))();
  *(undefined4 *)(iVar3 + 0x18) = uVar5;
  uVar8 = (uint3)((uint)unaff_ESI >> 8);
  fVar7 = (float)CONCAT31(uVar8,1);
  if (fStack_28 <= _DAT_00951170) {
    fVar7 = (float)((uint)uVar8 << 8);
  }
  cVar2 = FUN_00423550(*(undefined4 *)(param_1 + 0x40),fVar7);
  if (cVar2 == '\0') {
    func_0x00764590(1,0x951298);
  }
  iVar3 = *(int *)(param_1 + 0x54);
  uVar5 = (**(code **)(**(int **)(param_1 + 8) + 0x2c))();
  *(undefined4 *)(iVar3 + 0x1c) = uVar5;
  fStack_38 = (float)(uint)(_DAT_00951174 < fVar7);
  cVar2 = FUN_00423730(*(undefined4 *)(param_1 + 0x44),fStack_38);
  if (cVar2 == '\0') {
    func_0x00764590(1,0x951258);
  }
  iVar3 = *(int *)(param_1 + 0x54);
  uVar5 = (**(code **)(**(int **)(param_1 + 8) + 0x2c))();
  *(undefined4 *)(iVar3 + 0x20) = uVar5;
  uVar8 = (uint3)((uint)unaff_EBX >> 8);
  fVar7 = (float)CONCAT31(uVar8,1);
  if (fStack_38 <= _DAT_00951178) {
    fVar7 = (float)((uint)uVar8 << 8);
  }
  cVar2 = FUN_004238c0(*(undefined4 *)(param_1 + 0x48),fVar7);
  if (cVar2 == '\0') {
    func_0x00764590(1,0x95121c);
  }
  iVar3 = *(int *)(param_1 + 0x54);
  uVar5 = (**(code **)(**(int **)(param_1 + 8) + 0x2c))();
  *(undefined4 *)(iVar3 + 0x24) = uVar5;
  cVar2 = FUN_00423a50(*(undefined4 *)(param_1 + 0x4c),_DAT_0095117c < fVar7);
  if (cVar2 == '\0') {
    func_0x00764590(1,0x9511e0);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00422900 | Classified: elementclient::AArray__Allocate__Not_enough_mem@0x422900 */
/* ==================================================================== */

undefined4 __thiscall FUN_00422900(int param_1,int param_2,char param_3)

{
  int iVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float fStack_24;
  float fStack_20;
  undefined4 auStack_1c [2];
  float fStack_14;
  float afStack_10 [4];
  
  iVar6 = 0;
  if (param_2 != 0) {
    if (*(int *)(*(int *)(param_1 + 4) + 0x4d0) < 5) {
      if (param_3 != '\0') {
        (**(code **)(**(int **)(param_1 + 8) + 0x30))(param_2 * 0xc,1);
        return 1;
      }
      *(undefined4 *)(param_1 + 0x70) = 0;
      if (0 < param_2) {
        do {
          cVar3 = (**(code **)(**(int **)(param_1 + 8) + 0x10))(afStack_10,0xc,&param_3);
          if (cVar3 == '\0') {
            return 0;
          }
          fStack_20 = *(float *)(*(int *)(param_1 + 4) + 0x584) + fStack_14;
          func_0x0042c150(&stack0xffffffd8,0);
          iVar4 = func_0x00421580(fStack_24);
          fVar2 = afStack_10[0];
          if (iVar4 != 0) {
            fStack_24 = afStack_10[0];
            func_0x006565d0(auStack_1c,&fStack_20);
            if ((*(int *)(param_1 + 0x74) <= *(int *)(param_1 + 0x70)) &&
               (*(int *)(param_1 + 0x78) != 0)) {
              iVar7 = *(int *)(param_1 + 0x78) + *(int *)(param_1 + 0x74);
              iVar4 = func_0x00763250(iVar7 * 8);
              if (iVar4 == 0) {
                func_0x00764590(1,0x94e51c);
              }
              else {
                iVar5 = 0;
                if (0 < *(int *)(param_1 + 0x70)) {
                  do {
                    iVar1 = *(int *)(param_1 + 0x6c);
                    iVar5 = iVar5 + 1;
                    *(undefined4 *)(iVar4 + -8 + iVar5 * 8) =
                         *(undefined4 *)(iVar1 + -8 + iVar5 * 8);
                    *(undefined4 *)(iVar4 + -4 + iVar5 * 8) =
                         *(undefined4 *)(iVar1 + -4 + iVar5 * 8);
                  } while (iVar5 < *(int *)(param_1 + 0x70));
                }
                if (*(int *)(param_1 + 0x6c) != 0) {
                  func_0x00763260(*(int *)(param_1 + 0x6c));
                }
                *(int *)(param_1 + 0x6c) = iVar4;
                *(int *)(param_1 + 0x74) = iVar7;
              }
            }
            iVar4 = *(int *)(param_1 + 0x70);
            iVar7 = *(int *)(param_1 + 0x6c);
            *(float *)(iVar7 + iVar4 * 8) = fVar2;
            *(float *)(iVar7 + 4 + iVar4 * 8) = fStack_20;
            *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < param_2);
      }
    }
    else {
      if (param_3 != '\0') {
        (**(code **)(**(int **)(param_1 + 8) + 0x30))(param_2 << 4,1);
        return 1;
      }
      *(undefined4 *)(param_1 + 0x70) = 0;
      if (0 < param_2) {
        do {
          cVar3 = (**(code **)(**(int **)(param_1 + 8) + 0x10))(afStack_10,0x10,&param_3);
          if (cVar3 == '\0') {
            return 0;
          }
          fStack_20 = *(float *)(*(int *)(param_1 + 4) + 0x584) + afStack_10[0];
          iVar4 = func_0x00421580(auStack_1c[0]);
          fVar2 = afStack_10[0];
          if (iVar4 != 0) {
            func_0x006565d0(auStack_1c,&fStack_20);
            if ((*(int *)(param_1 + 0x74) <= *(int *)(param_1 + 0x70)) &&
               (*(int *)(param_1 + 0x78) != 0)) {
              iVar7 = *(int *)(param_1 + 0x78) + *(int *)(param_1 + 0x74);
              iVar4 = func_0x00763250(iVar7 * 8);
              if (iVar4 == 0) {
                func_0x00764590(1,0x94e51c);
              }
              else {
                iVar5 = 0;
                if (0 < *(int *)(param_1 + 0x70)) {
                  do {
                    iVar1 = *(int *)(param_1 + 0x6c);
                    iVar5 = iVar5 + 1;
                    *(undefined4 *)(iVar4 + -8 + iVar5 * 8) =
                         *(undefined4 *)(iVar1 + -8 + iVar5 * 8);
                    *(undefined4 *)(iVar4 + -4 + iVar5 * 8) =
                         *(undefined4 *)(iVar1 + -4 + iVar5 * 8);
                  } while (iVar5 < *(int *)(param_1 + 0x70));
                }
                if (*(int *)(param_1 + 0x6c) != 0) {
                  func_0x00763260(*(int *)(param_1 + 0x6c));
                }
                *(int *)(param_1 + 0x6c) = iVar4;
                *(int *)(param_1 + 0x74) = iVar7;
              }
            }
            iVar4 = *(int *)(param_1 + 0x70);
            iVar7 = *(int *)(param_1 + 0x6c);
            *(float *)(iVar7 + iVar4 * 8) = fVar2;
            *(float *)(iVar7 + 4 + iVar4 * 8) = fStack_20;
            *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < param_2);
        *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 1;
        return 1;
      }
    }
  }
  *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 1;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00422be0 | Classified: elementclient::AArray__SetSize__Not_enough_memo@0x422be0 */
/* ==================================================================== */

undefined4 __thiscall FUN_00422be0(int param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 *puStack_1c;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  iVar1 = param_2;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a74b8;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 == 0) {
    *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 0x10;
  }
  else if ((char)param_3 == '\0') {
    puStack_1c = (undefined4 *)0x0;
    uStack_4 = 0;
    puVar3 = puStack_1c;
    if ((0 < param_2) &&
       (puVar3 = (undefined4 *)func_0x00763250(param_2 * 8), puVar3 == (undefined4 *)0x0)) {
      func_0x00764590(1,0x9505a4);
      puVar3 = puStack_1c;
    }
    puStack_1c = puVar3;
    cVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x10))(puStack_1c,iVar1 * 8,&param_2);
    if (cVar2 == '\0') {
      uStack_4 = 0xffffffff;
      if (puStack_1c != (undefined4 *)0x0) {
        func_0x00763260(puStack_1c);
      }
      uVar4 = 0;
      goto LAB_00422d51;
    }
    *(int *)(param_1 + 200) = iVar1;
    func_0x004acc40(1);
    if (0 < iVar1) {
      param_3 = iVar1;
      puVar3 = puStack_1c;
      do {
        cVar2 = FUN_0041dcb0(*puVar3,puVar3[1]);
        if (cVar2 != '\0') {
          uVar4 = *puVar3;
          if (*(int *)(param_1 + 0xc4) <= *(int *)(param_1 + 0xc0)) {
            func_0x0068e120(*(undefined4 *)(param_1 + 200));
          }
          *(undefined4 *)(*(int *)(param_1 + 0xbc) + *(int *)(param_1 + 0xc0) * 4) = uVar4;
          *(int *)(param_1 + 0xc0) = *(int *)(param_1 + 0xc0) + 1;
        }
        puVar3 = puVar3 + 2;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
      param_3 = 0;
    }
    uStack_4 = 0xffffffff;
    *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 0x10;
    if (puStack_1c != (undefined4 *)0x0) {
      func_0x00763260(puStack_1c);
    }
  }
  else {
    (**(code **)(**(int **)(param_1 + 8) + 0x30))(param_2 * 8,1);
  }
  uVar4 = 1;
LAB_00422d51:
  *unaff_FS_OFFSET = uStack_c;
  return uVar4;
}


/* ==================================================================== */
/* Address: 0x00422d70 | Classified: elementclient::AArray__SetSize__Not_enough_memo@0x422d70 */
/* ==================================================================== */

undefined4 __thiscall FUN_00422d70(int param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 *puStack_1c;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  iVar1 = param_2;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a74d8;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 == 0) {
    *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 2;
  }
  else if ((char)param_3 == '\0') {
    puStack_1c = (undefined4 *)0x0;
    uStack_4 = 0;
    puVar3 = puStack_1c;
    if ((0 < param_2) &&
       (puVar3 = (undefined4 *)func_0x00763250(param_2 * 8), puVar3 == (undefined4 *)0x0)) {
      func_0x00764590(1,0x9505a4);
      puVar3 = puStack_1c;
    }
    puStack_1c = puVar3;
    cVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x10))(puStack_1c,iVar1 * 8,&param_2);
    if (cVar2 == '\0') {
      uStack_4 = 0xffffffff;
      if (puStack_1c != (undefined4 *)0x0) {
        func_0x00763260(puStack_1c);
      }
      uVar4 = 0;
      goto LAB_00422ede;
    }
    *(int *)(param_1 + 0x8c) = iVar1;
    func_0x004acc40(1);
    if (0 < iVar1) {
      param_3 = iVar1;
      puVar3 = puStack_1c;
      do {
        cVar2 = FUN_0041d740(*puVar3,puVar3[1]);
        if (cVar2 != '\0') {
          uVar4 = *puVar3;
          if (*(int *)(param_1 + 0x88) <= *(int *)(param_1 + 0x84)) {
            func_0x0068e120(*(undefined4 *)(param_1 + 0x8c));
          }
          *(undefined4 *)(*(int *)(param_1 + 0x80) + *(int *)(param_1 + 0x84) * 4) = uVar4;
          *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
        }
        puVar3 = puVar3 + 2;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
      param_3 = 0;
    }
    uStack_4 = 0xffffffff;
    *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 2;
    if (puStack_1c != (undefined4 *)0x0) {
      func_0x00763260(puStack_1c);
    }
  }
  else {
    (**(code **)(**(int **)(param_1 + 8) + 0x30))(param_2 * 8,1);
  }
  uVar4 = 1;
LAB_00422ede:
  *unaff_FS_OFFSET = uStack_c;
  return uVar4;
}


/* ==================================================================== */
/* Address: 0x00422f00 | Classified: elementclient::AArray__SetSize__Not_enough_memo@0x422f00 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00422f00(int param_1,int param_2,char param_3)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined *puStack_24;
  undefined *puStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  iVar7 = param_2;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a7500;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 == 0) {
LAB_00423151:
    *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 4;
  }
  else if (*(int *)(*(int *)(param_1 + 4) + 0x4d0) < 4) {
    if (param_3 == '\0') {
      *(int *)(param_1 + 0xa0) = param_2;
      func_0x004acc40(1);
      if (0 < iVar7) {
        do {
          cVar2 = FUN_0041e3a0(0,0,&param_2);
          if (cVar2 != '\0') {
            func_0x00459590(param_2);
          }
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      goto LAB_00423151;
    }
    if (0 < param_2) {
      do {
        (**(code **)(**(int **)(param_1 + 8) + 0x30))(0x2c,1);
        uStack_c = 1;
        (**(code **)(**(int **)(param_1 + 8) + 0x1c))(&stack0x00000000);
        uStack_10 = 0xffffffff;
        func_0x007637f0();
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
  }
  else {
    if (param_3 == '\0') {
      puStack_20 = &UNK_008d6524;
      iStack_1c = 0;
      iStack_18 = 0;
      iStack_14 = 0;
      uStack_4 = 0;
      uStack_10 = 10;
      if (param_2 < 1) {
        iStack_18 = param_2;
      }
      else {
        iVar3 = func_0x00763250(param_2 * 8);
        if (iVar3 == 0) {
          func_0x00764590(1,0x9505a4);
        }
        else {
          if (iStack_1c != 0) {
            iVar6 = iStack_18;
            if (iVar7 <= iStack_18) {
              iVar6 = iVar7;
            }
            iVar4 = 0;
            if (0 < iVar6) {
              do {
                puVar1 = (undefined4 *)(iStack_1c + iVar4 * 8);
                iVar4 = iVar4 + 1;
                *(undefined4 *)(iVar3 + -8 + iVar4 * 8) = *puVar1;
                *(undefined4 *)(iVar3 + -4 + iVar4 * 8) = puVar1[1];
              } while (iVar4 < iVar6);
            }
            func_0x00763260(iStack_1c);
          }
          iStack_18 = iVar7;
          iStack_14 = iVar7;
          iStack_1c = iVar3;
        }
      }
      cVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x10))(iStack_1c,iVar7 * 8,&puStack_24);
      if (cVar2 == '\0') {
        uStack_4 = 0xffffffff;
        puStack_20 = &UNK_008d6524;
        if (iStack_1c != 0) {
          func_0x00763260(iStack_1c);
        }
        uVar5 = 0;
        goto LAB_0042315b;
      }
      *(int *)(param_1 + 0xa0) = iVar7;
      func_0x004acc40(1);
      param_2 = 0;
      if (0 < iVar7) {
        do {
          puVar1 = (undefined4 *)(puStack_20 + param_2 * 8);
          cVar2 = FUN_0041e3a0(*puVar1,*(undefined4 *)(puStack_20 + param_2 * 8 + 4),0);
          if (cVar2 != '\0') {
            uVar5 = *puVar1;
            if (*(int *)(param_1 + 0x9c) <= *(int *)(param_1 + 0x98)) {
              func_0x0068e120(*(undefined4 *)(param_1 + 0xa0));
            }
            *(undefined4 *)(*(int *)(param_1 + 0x94) + *(int *)(param_1 + 0x98) * 4) = uVar5;
            *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 1;
          }
          param_2 = param_2 + 1;
        } while (param_2 < iVar7);
      }
      puStack_8 = (undefined *)0xffffffff;
      puStack_24 = &UNK_008d6524;
      func_0x004acc40(1);
      goto LAB_00423151;
    }
    (**(code **)(**(int **)(param_1 + 8) + 0x30))(param_2 * 8,1);
  }
  uVar5 = 1;
LAB_0042315b:
  *unaff_FS_OFFSET = uStack_c;
  return uVar5;
}


/* ==================================================================== */
/* Address: 0x00423170 | Classified: elementclient::AArray__SetSize__Not_enough_memo@0x423170 */
/* ==================================================================== */

undefined4 __thiscall FUN_00423170(int param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 *puStack_1c;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  iVar1 = param_2;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a7518;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 == 0) {
    *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 8;
  }
  else if ((char)param_3 == '\0') {
    puStack_1c = (undefined4 *)0x0;
    uStack_4 = 0;
    puVar3 = puStack_1c;
    if ((0 < param_2) &&
       (puVar3 = (undefined4 *)func_0x00763250(param_2 * 8), puVar3 == (undefined4 *)0x0)) {
      func_0x00764590(1,0x9505a4);
      puVar3 = puStack_1c;
    }
    puStack_1c = puVar3;
    cVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x10))(puStack_1c,iVar1 * 8,&param_2);
    if (cVar2 == '\0') {
      uStack_4 = 0xffffffff;
      if (puStack_1c != (undefined4 *)0x0) {
        func_0x00763260(puStack_1c);
      }
      uVar4 = 0;
      goto LAB_004232e1;
    }
    *(int *)(param_1 + 0xb4) = iVar1;
    func_0x004acc40(1);
    if (0 < iVar1) {
      param_3 = iVar1;
      puVar3 = puStack_1c;
      do {
        cVar2 = FUN_0041da70(*puVar3,puVar3[1]);
        if (cVar2 != '\0') {
          uVar4 = *puVar3;
          if (*(int *)(param_1 + 0xb0) <= *(int *)(param_1 + 0xac)) {
            func_0x0068e120(*(undefined4 *)(param_1 + 0xb4));
          }
          *(undefined4 *)(*(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0xac) * 4) = uVar4;
          *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + 1;
        }
        puVar3 = puVar3 + 2;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
      param_3 = 0;
    }
    uStack_4 = 0xffffffff;
    *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 8;
    if (puStack_1c != (undefined4 *)0x0) {
      func_0x00763260(puStack_1c);
    }
  }
  else {
    (**(code **)(**(int **)(param_1 + 8) + 0x30))(param_2 * 8,1);
  }
  uVar4 = 1;
LAB_004232e1:
  *unaff_FS_OFFSET = uStack_c;
  return uVar4;
}


/* ==================================================================== */
/* Address: 0x00423300 | Classified: elementclient::AArray__Allocate__Not_enough_mem@0x423300 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00423300(int param_1,int param_2,char param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a7538;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 != 0) {
    if (param_3 != '\0') {
      uStack_4 = 0;
      iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x4d0);
      if (iVar1 < 6) {
        if (0 < param_2) {
          do {
            (**(code **)(**(int **)(param_1 + 8) + 0x30))(0x2c,1);
            (**(code **)(**(int **)(param_1 + 8) + 0x1c))(&stack0x00000000);
            param_2 = param_2 + -1;
          } while (param_2 != 0);
        }
      }
      else if (iVar1 < 8) {
        if (0 < param_2) {
          do {
            (**(code **)(**(int **)(param_1 + 8) + 0x30))(0x30,1);
            (**(code **)(**(int **)(param_1 + 8) + 0x1c))(&stack0x00000000);
            param_2 = param_2 + -1;
          } while (param_2 != 0);
        }
      }
      else if (iVar1 < 0xc) {
        if (0 < param_2) {
          do {
            (**(code **)(**(int **)(param_1 + 8) + 0x30))(0x34,1);
            (**(code **)(**(int **)(param_1 + 8) + 0x1c))(&stack0x00000000);
            param_2 = param_2 + -1;
          } while (param_2 != 0);
        }
      }
      else if (0 < param_2) {
        do {
          (**(code **)(**(int **)(param_1 + 8) + 0x30))(0x3c,1);
          (**(code **)(**(int **)(param_1 + 8) + 0x1c))(&stack0x00000000);
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
      uStack_4 = 0xffffffff;
      func_0x007637f0();
      goto LAB_00423531;
    }
    func_0x006450d0();
    *(int *)(param_1 + 0xdc) = param_2;
    if (*(int *)(param_1 + 0xd0) != 0) {
      func_0x00763260(*(int *)(param_1 + 0xd0));
      *(undefined4 *)(param_1 + 0xd0) = 0;
    }
    *(undefined4 *)(param_1 + 0xd8) = 0;
    *(undefined4 *)(param_1 + 0xd4) = 0;
    if (0 < param_2) {
      _param_3 = param_2;
      do {
        iVar1 = *(int *)(param_1 + 4);
        iVar1 = FUN_005b32b0(iVar1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(iVar1 + 0x580),
                             *(undefined4 *)(iVar1 + 0x584));
        if (iVar1 != 0) {
          if ((*(int *)(param_1 + 0xd8) <= *(int *)(param_1 + 0xd4)) &&
             (*(int *)(param_1 + 0xdc) != 0)) {
            iVar4 = *(int *)(param_1 + 0xdc) + *(int *)(param_1 + 0xd8);
            iVar2 = func_0x00763250(iVar4 * 4);
            if (iVar2 == 0) {
              func_0x00764590(1,0x94e51c);
            }
            else {
              iVar3 = 0;
              if (0 < *(int *)(param_1 + 0xd4)) {
                do {
                  iVar3 = iVar3 + 1;
                  *(undefined4 *)(iVar2 + -4 + iVar3 * 4) =
                       *(undefined4 *)(*(int *)(param_1 + 0xd0) + -4 + iVar3 * 4);
                } while (iVar3 < *(int *)(param_1 + 0xd4));
              }
              if (*(int *)(param_1 + 0xd0) != 0) {
                func_0x00763260(*(int *)(param_1 + 0xd0));
              }
              *(int *)(param_1 + 0xd0) = iVar2;
              *(int *)(param_1 + 0xd8) = iVar4;
            }
          }
          *(int *)(*(int *)(param_1 + 0xd0) + *(int *)(param_1 + 0xd4) * 4) = iVar1;
          *(int *)(param_1 + 0xd4) = *(int *)(param_1 + 0xd4) + 1;
        }
        _param_3 = _param_3 + -1;
      } while (_param_3 != 0);
    }
  }
  *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 0x20;
LAB_00423531:
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00423550 | Classified: elementclient::AArray__Allocate__Not_enough_mem@0x423550 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00423550(int param_1,int param_2,char param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a7558;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 != 0) {
    if (param_3 != '\0') {
      uStack_4 = 0;
      if (0 < param_2) {
        do {
          (**(code **)(**(int **)(param_1 + 8) + 0x30))(0x28,1);
          (**(code **)(**(int **)(param_1 + 8) + 0x1c))(&stack0x00000000);
          (**(code **)(**(int **)(param_1 + 8) + 0x1c))(&uStack_4);
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
      uStack_4 = 0xffffffff;
      func_0x007637f0();
      goto LAB_0042370b;
    }
    func_0x006450d0();
    *(int *)(param_1 + 0xf0) = param_2;
    if (*(int *)(param_1 + 0xe4) != 0) {
      func_0x00763260(*(int *)(param_1 + 0xe4));
      *(undefined4 *)(param_1 + 0xe4) = 0;
    }
    *(undefined4 *)(param_1 + 0xec) = 0;
    *(undefined4 *)(param_1 + 0xe8) = 0;
    if (0 < param_2) {
      _param_3 = param_2;
      do {
        iVar1 = FUN_005b38f0(*(undefined4 *)(param_1 + 8),
                             *(undefined4 *)(*(int *)(param_1 + 4) + 0x580),
                             *(undefined4 *)(*(int *)(param_1 + 4) + 0x584));
        if (iVar1 != 0) {
          if ((*(int *)(param_1 + 0xec) <= *(int *)(param_1 + 0xe8)) &&
             (*(int *)(param_1 + 0xf0) != 0)) {
            iVar4 = *(int *)(param_1 + 0xf0) + *(int *)(param_1 + 0xec);
            iVar2 = func_0x00763250(iVar4 * 4);
            if (iVar2 == 0) {
              func_0x00764590(1,0x94e51c);
            }
            else {
              iVar3 = 0;
              if (0 < *(int *)(param_1 + 0xe8)) {
                do {
                  iVar3 = iVar3 + 1;
                  *(undefined4 *)(iVar2 + -4 + iVar3 * 4) =
                       *(undefined4 *)(*(int *)(param_1 + 0xe4) + -4 + iVar3 * 4);
                } while (iVar3 < *(int *)(param_1 + 0xe8));
              }
              if (*(int *)(param_1 + 0xe4) != 0) {
                func_0x00763260(*(int *)(param_1 + 0xe4));
              }
              *(int *)(param_1 + 0xe4) = iVar2;
              *(int *)(param_1 + 0xec) = iVar4;
            }
          }
          *(int *)(*(int *)(param_1 + 0xe4) + *(int *)(param_1 + 0xe8) * 4) = iVar1;
          *(int *)(param_1 + 0xe8) = *(int *)(param_1 + 0xe8) + 1;
        }
        _param_3 = _param_3 + -1;
      } while (_param_3 != 0);
    }
  }
  *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 0x40;
LAB_0042370b:
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00423730 | Classified: elementclient::AArray__SetSize__Not_enough_memo@0x423730 */
/* ==================================================================== */

undefined4 __thiscall FUN_00423730(int param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 *puStack_1c;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  iVar1 = param_2;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a7578;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 == 0) {
    *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 0x80;
  }
  else if ((char)param_3 == '\0') {
    puStack_1c = (undefined4 *)0x0;
    uStack_4 = 0;
    puVar3 = puStack_1c;
    if ((0 < param_2) &&
       (puVar3 = (undefined4 *)func_0x00763250(param_2 * 8), puVar3 == (undefined4 *)0x0)) {
      func_0x00764590(1,0x9505a4);
      puVar3 = puStack_1c;
    }
    puStack_1c = puVar3;
    cVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x10))(puStack_1c,iVar1 * 8,&param_2);
    if (cVar2 == '\0') {
      uStack_4 = 0xffffffff;
      if (puStack_1c != (undefined4 *)0x0) {
        func_0x00763260(puStack_1c);
      }
      uVar4 = 0;
      goto LAB_004238a1;
    }
    *(int *)(param_1 + 0x104) = iVar1;
    func_0x004acc40(1);
    if (0 < iVar1) {
      param_3 = iVar1;
      puVar3 = puStack_1c;
      do {
        cVar2 = FUN_0041e160(*puVar3,puVar3[1]);
        if (cVar2 != '\0') {
          uVar4 = *puVar3;
          if (*(int *)(param_1 + 0x100) <= *(int *)(param_1 + 0xfc)) {
            func_0x0068e120(*(undefined4 *)(param_1 + 0x104));
          }
          *(undefined4 *)(*(int *)(param_1 + 0xf8) + *(int *)(param_1 + 0xfc) * 4) = uVar4;
          *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
        }
        puVar3 = puVar3 + 2;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
      param_3 = 0;
    }
    uStack_4 = 0xffffffff;
    *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 0x80;
    if (puStack_1c != (undefined4 *)0x0) {
      func_0x00763260(puStack_1c);
    }
  }
  else {
    (**(code **)(**(int **)(param_1 + 8) + 0x30))(param_2 * 8,1);
  }
  uVar4 = 1;
LAB_004238a1:
  *unaff_FS_OFFSET = uStack_c;
  return uVar4;
}


/* ==================================================================== */
/* Address: 0x004238c0 | Classified: elementclient::AArray__SetSize__Not_enough_memo@0x4238c0 */
/* ==================================================================== */

undefined4 __thiscall FUN_004238c0(int param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 *puStack_1c;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  iVar1 = param_2;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a7598;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 == 0) {
    *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 0x100;
  }
  else if ((char)param_3 == '\0') {
    puStack_1c = (undefined4 *)0x0;
    uStack_4 = 0;
    puVar3 = puStack_1c;
    if ((0 < param_2) &&
       (puVar3 = (undefined4 *)func_0x00763250(param_2 * 8), puVar3 == (undefined4 *)0x0)) {
      func_0x00764590(1,0x9505a4);
      puVar3 = puStack_1c;
    }
    puStack_1c = puVar3;
    cVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x10))(puStack_1c,iVar1 * 8,&param_2);
    if (cVar2 == '\0') {
      uStack_4 = 0xffffffff;
      if (puStack_1c != (undefined4 *)0x0) {
        func_0x00763260(puStack_1c);
      }
      uVar4 = 0;
      goto LAB_00423a32;
    }
    *(int *)(param_1 + 0x118) = iVar1;
    func_0x004acc40(1);
    if (0 < iVar1) {
      param_3 = iVar1;
      puVar3 = puStack_1c;
      do {
        cVar2 = FUN_0041e4d0(*puVar3,puVar3[1]);
        if (cVar2 != '\0') {
          uVar4 = *puVar3;
          if (*(int *)(param_1 + 0x114) <= *(int *)(param_1 + 0x110)) {
            func_0x0068e120(*(undefined4 *)(param_1 + 0x118));
          }
          *(undefined4 *)(*(int *)(param_1 + 0x10c) + *(int *)(param_1 + 0x110) * 4) = uVar4;
          *(int *)(param_1 + 0x110) = *(int *)(param_1 + 0x110) + 1;
        }
        puVar3 = puVar3 + 2;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
      param_3 = 0;
    }
    uStack_4 = 0xffffffff;
    *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 0x100;
    if (puStack_1c != (undefined4 *)0x0) {
      func_0x00763260(puStack_1c);
    }
  }
  else {
    (**(code **)(**(int **)(param_1 + 8) + 0x30))(param_2 * 8,1);
  }
  uVar4 = 1;
LAB_00423a32:
  *unaff_FS_OFFSET = uStack_c;
  return uVar4;
}


/* ==================================================================== */
/* Address: 0x00423a50 | Classified: elementclient::AArray__Allocate__Not_enough_mem@0x423a50 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00423a50(int param_1,int param_2,char param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a75b8;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 != 0) {
    if (param_3 != '\0') {
      uStack_4 = 0;
      if (*(int *)(*(int *)(param_1 + 4) + 0x4d0) < 10) {
        if (0 < param_2) {
          do {
            (**(code **)(**(int **)(param_1 + 8) + 0x30))(0x1c,1);
            (**(code **)(**(int **)(param_1 + 8) + 0x1c))(&stack0x00000000);
            param_2 = param_2 + -1;
          } while (param_2 != 0);
        }
      }
      else if (0 < param_2) {
        do {
          (**(code **)(**(int **)(param_1 + 8) + 0x30))(0x20,1);
          (**(code **)(**(int **)(param_1 + 8) + 0x1c))(&stack0x00000000);
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
      uStack_4 = 0xffffffff;
      func_0x007637f0();
      goto LAB_00423c2c;
    }
    func_0x006450d0();
    *(int *)(param_1 + 300) = param_2;
    if (*(int *)(param_1 + 0x120) != 0) {
      func_0x00763260(*(int *)(param_1 + 0x120));
      *(undefined4 *)(param_1 + 0x120) = 0;
    }
    *(undefined4 *)(param_1 + 0x128) = 0;
    *(undefined4 *)(param_1 + 0x124) = 0;
    if (0 < param_2) {
      _param_3 = param_2;
      do {
        iVar1 = *(int *)(param_1 + 4);
        iVar1 = FUN_005b40d0(iVar1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(iVar1 + 0x580),
                             *(undefined4 *)(iVar1 + 0x584));
        if (iVar1 != 0) {
          if ((*(int *)(param_1 + 0x128) <= *(int *)(param_1 + 0x124)) &&
             (*(int *)(param_1 + 300) != 0)) {
            iVar4 = *(int *)(param_1 + 300) + *(int *)(param_1 + 0x128);
            iVar2 = func_0x00763250(iVar4 * 4);
            if (iVar2 == 0) {
              func_0x00764590(1,0x94e51c);
            }
            else {
              iVar3 = 0;
              if (0 < *(int *)(param_1 + 0x124)) {
                do {
                  iVar3 = iVar3 + 1;
                  *(undefined4 *)(iVar2 + -4 + iVar3 * 4) =
                       *(undefined4 *)(*(int *)(param_1 + 0x120) + -4 + iVar3 * 4);
                } while (iVar3 < *(int *)(param_1 + 0x124));
              }
              if (*(int *)(param_1 + 0x120) != 0) {
                func_0x00763260(*(int *)(param_1 + 0x120));
              }
              *(int *)(param_1 + 0x120) = iVar2;
              *(int *)(param_1 + 0x128) = iVar4;
            }
          }
          *(int *)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x124) * 4) = iVar1;
          *(int *)(param_1 + 0x124) = *(int *)(param_1 + 0x124) + 1;
        }
        _param_3 = _param_3 + -1;
      } while (_param_3 != 0);
    }
  }
  *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 0x200;
LAB_00423c2c:
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00423c50 | Classified: ElementClient::proc_423c50 */
/* ==================================================================== */

void __fastcall FUN_00423c50(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) & 0xfffffffe;
  if (*(int *)(param_1 + 0x70) != 0) {
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0x70)) {
      do {
        iVar1 = *(int *)(param_1 + 0x6c);
        iVar2 = func_0x00421580(*(undefined4 *)(iVar1 + iVar3 * 8));
        if (iVar2 != 0) {
          func_0x006567e0(*(undefined4 *)(iVar1 + iVar3 * 8 + 4));
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1 + 0x70));
    }
    *(undefined4 *)(param_1 + 0x70) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00423ca0 | Classified: ElementClient::proc_423ca0 */
/* ==================================================================== */

void __fastcall FUN_00423ca0(int param_1)

{
  int iVar1;
  
  *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) & 0xffffffef;
  if (*(int *)(param_1 + 0xc0) != 0) {
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0xc0)) {
      do {
        FUN_0041d4b0(*(undefined4 *)(*(int *)(param_1 + 0xbc) + iVar1 * 4));
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0xc0));
    }
    *(undefined4 *)(param_1 + 0xc0) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00423cf0 | Classified: ElementClient::proc_423cf0 */
/* ==================================================================== */

void __fastcall FUN_00423cf0(int param_1)

{
  int iVar1;
  
  *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) & 0xfffffffd;
  if (*(int *)(param_1 + 0x84) != 0) {
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0x84)) {
      do {
        FUN_0041d4b0(*(undefined4 *)(*(int *)(param_1 + 0x80) + iVar1 * 4));
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0x84));
    }
    *(undefined4 *)(param_1 + 0x84) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00423d40 | Classified: ElementClient::proc_423d40 */
/* ==================================================================== */

void __fastcall FUN_00423d40(int param_1)

{
  int iVar1;
  
  *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) & 0xfffffffb;
  if (*(int *)(param_1 + 0x98) != 0) {
    func_0x006450d0();
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0x98)) {
      do {
        FUN_0041d4b0(*(undefined4 *)(*(int *)(param_1 + 0x94) + iVar1 * 4));
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0x98));
    }
    *(undefined4 *)(param_1 + 0x98) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00423da0 | Classified: ElementClient::proc_423da0 */
/* ==================================================================== */

void __fastcall FUN_00423da0(int param_1)

{
  int iVar1;
  
  *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) & 0xfffffff7;
  if (*(int *)(param_1 + 0xac) != 0) {
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0xac)) {
      do {
        FUN_0041d4b0(*(undefined4 *)(*(int *)(param_1 + 0xa8) + iVar1 * 4));
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0xac));
    }
    *(undefined4 *)(param_1 + 0xac) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00423df0 | Classified: ElementClient::proc_423df0 */
/* ==================================================================== */

void __fastcall FUN_00423df0(int param_1)

{
  int iVar1;
  
  *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) & 0xffffffdf;
  if (*(int *)(param_1 + 0xd4) != 0) {
    func_0x006450d0();
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0xd4)) {
      do {
        FUN_005b3660(*(undefined4 *)(*(int *)(param_1 + 0xd0) + iVar1 * 4));
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0xd4));
    }
    *(undefined4 *)(param_1 + 0xd4) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00423e50 | Classified: ElementClient::proc_423e50 */
/* ==================================================================== */

void __fastcall FUN_00423e50(int param_1)

{
  int iVar1;
  
  *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) & 0xffffffbf;
  if (*(int *)(param_1 + 0xe8) != 0) {
    func_0x006450d0();
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0xe8)) {
      do {
        FUN_005b3e50(*(undefined4 *)(*(int *)(param_1 + 0xe4) + iVar1 * 4));
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0xe8));
    }
    *(undefined4 *)(param_1 + 0xe8) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00423eb0 | Classified: ElementClient::proc_423eb0 */
/* ==================================================================== */

void __fastcall FUN_00423eb0(int param_1)

{
  int iVar1;
  
  *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) & 0xffffff7f;
  if (*(int *)(param_1 + 0xfc) != 0) {
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0xfc)) {
      do {
        FUN_0041d4b0(*(undefined4 *)(*(int *)(param_1 + 0xf8) + iVar1 * 4));
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0xfc));
    }
    if (*(int *)(param_1 + 0xf8) != 0) {
      func_0x00763260(*(int *)(param_1 + 0xf8));
      *(undefined4 *)(param_1 + 0xf8) = 0;
    }
    *(undefined4 *)(param_1 + 0x100) = 0;
    *(undefined4 *)(param_1 + 0xfc) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00423f20 | Classified: ElementClient::proc_423f20 */
/* ==================================================================== */

void __fastcall FUN_00423f20(int param_1)

{
  int iVar1;
  
  *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) & 0xfffffeff;
  if (*(int *)(param_1 + 0x110) != 0) {
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0x110)) {
      do {
        FUN_0041d4b0(*(undefined4 *)(*(int *)(param_1 + 0x10c) + iVar1 * 4));
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0x110));
    }
    if (*(int *)(param_1 + 0x10c) != 0) {
      func_0x00763260(*(int *)(param_1 + 0x10c));
      *(undefined4 *)(param_1 + 0x10c) = 0;
    }
    *(undefined4 *)(param_1 + 0x114) = 0;
    *(undefined4 *)(param_1 + 0x110) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00423f90 | Classified: ElementClient::proc_423f90 */
/* ==================================================================== */

void __fastcall FUN_00423f90(int param_1)

{
  int iVar1;
  
  *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) & 0xfffffdff;
  if (*(int *)(param_1 + 0x124) != 0) {
    func_0x006450d0();
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0x124)) {
      do {
        FUN_005b43c0(*(undefined4 *)(*(int *)(param_1 + 0x120) + iVar1 * 4));
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0x124));
    }
    if (*(int *)(param_1 + 0x120) != 0) {
      func_0x00763260(*(int *)(param_1 + 0x120));
      *(undefined4 *)(param_1 + 0x120) = 0;
    }
    *(undefined4 *)(param_1 + 0x128) = 0;
    *(undefined4 *)(param_1 + 0x124) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00780050 | Classified: elementclient::A3DTerrainWater__LoadWaterAreas_@0x780050 */
/* ==================================================================== */

undefined4 __thiscall FUN_00780050(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar4;
  int iVar5;
  undefined4 uStack_20;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cc6f9;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  func_0x0076e410();
  iVar3 = 0;
  uStack_4 = 0;
  iVar5 = param_2;
  cVar1 = func_0x0076e470(param_2,1);
  if (cVar1 == '\0') {
    func_0x007647d0(0x9d2f20,0x988838,param_2);
  }
  else {
    cVar1 = func_0x0076e6a0(&stack0xfffffdc4,4,&stack0xfffffdc8);
    if (cVar1 != '\0') {
      if (0 < iVar5) {
        do {
          iVar2 = func_0x00763250(0xb0);
          if (iVar2 == 0) {
            uVar4 = 0;
          }
          else {
            uVar4 = FUN_00780ba0();
          }
          cVar1 = FUN_00780d30(param_1,&stack0xfffffdc4);
          if (cVar1 == '\0') {
            uVar4 = 0x9887b8;
            goto LAB_0078016c;
          }
          FUN_00780300(uVar4);
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar5);
      }
      func_0x0076e670();
      func_0x0076e460();
      uVar4 = 1;
      goto LAB_0078014d;
    }
    uVar4 = 0x9887fc;
LAB_0078016c:
    func_0x007647d0(0x9d2f20,uVar4);
  }
  uStack_c = 0xffffffff;
  func_0x0076e460();
  uVar4 = 0;
LAB_0078014d:
  *unaff_FS_OFFSET = uStack_20;
  return uVar4;
}


/* ==================================================================== */
/* Address: 0x007801a0 | Classified: elementclient::A3DTerrainWater__SaveWaterAreas_@0x7801a0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007801a0(int param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar5;
  int iStack_248;
  int aiStack_234 [133];
  undefined4 uStack_20;
  undefined4 uStack_18;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cc71b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  aiStack_234[0] = param_1;
  func_0x0076e410();
  iVar3 = 0;
  iStack_248 = 0x12;
  uStack_4 = 0;
  cVar2 = func_0x0076e470(param_2);
  if (cVar2 == '\0') {
    func_0x007647d0(0x9d2f20,0x9888f4,param_2);
  }
  else {
    FUN_007802e0();
    cVar2 = func_0x0076e6d0(&stack0xfffffdc8,4,aiStack_234);
    if (cVar2 != '\0') {
      if (0 < *(int *)(param_1 + 0x10)) {
        do {
          iVar4 = 0;
          iVar1 = *(int *)(*(int *)(param_1 + 0xc) + iVar3 * 4);
          if (0 < *(int *)(iVar1 + 0x10)) {
            do {
              cVar2 = FUN_00781350(&stack0xfffffdc4);
              if (cVar2 == '\0') {
                uVar5 = 0x988878;
                goto LAB_007802ac;
              }
              iVar4 = iVar4 + 1;
              param_1 = iStack_248;
            } while (iVar4 < *(int *)(iVar1 + 0x10));
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(int *)(param_1 + 0x10));
      }
      func_0x0076e670();
      uStack_18 = 0xffffffff;
      func_0x0076e460();
      uVar5 = 1;
      goto LAB_0078028c;
    }
    uVar5 = 0x9888bc;
LAB_007802ac:
    func_0x007647d0(0x9d2f20,uVar5);
  }
  uStack_c = 0xffffffff;
  func_0x0076e460();
  uVar5 = 0;
LAB_0078028c:
  *unaff_FS_OFFSET = uStack_20;
  return uVar5;
}


/* ==================================================================== */
/* Address: 0x007802e0 | Classified: Angelica3D::proc_7802e0 */
/* ==================================================================== */

int __fastcall FUN_007802e0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x10);
  iVar2 = 0;
  if (0 < iVar4) {
    piVar3 = *(int **)(param_1 + 0xc);
    do {
      iVar1 = *piVar3;
      piVar3 = piVar3 + 1;
      iVar2 = iVar2 + *(int *)(iVar1 + 0x10);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return iVar2;
}


/* ==================================================================== */
/* Address: 0x00780300 | Classified: elementclient::AArray__Allocate__Not_enough_mem@0x780300 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00780300(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    puVar1 = *(undefined4 **)(param_1 + 0xc);
    do {
      if (ABS(*(float *)*puVar1 - *(float *)(param_2 + 0xc)) < (float)_DAT_008f0ad8) {
        iVar3 = (*(undefined4 **)(param_1 + 0xc))[iVar3];
        if (*(int *)(iVar3 + 0x14) <= *(int *)(iVar3 + 0x10)) {
          func_0x0068e120(*(undefined4 *)(iVar3 + 0x18));
        }
        *(int *)(*(int *)(iVar3 + 0xc) + *(int *)(iVar3 + 0x10) * 4) = param_2;
        iVar4 = *(int *)(iVar3 + 0x10) + 1;
        *(int *)(iVar3 + 0x10) = iVar4;
        return CONCAT31((int3)((uint)iVar4 >> 8),1);
      }
      iVar3 = iVar3 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x10));
  }
  puVar1 = (undefined4 *)func_0x00763250(0x1c);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[2] = &UNK_008d5a30;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0x10;
    puVar1[1] = &UNK_008eb3a0;
  }
  *puVar1 = *(undefined4 *)(param_2 + 0xc);
  if (((int)puVar1[5] <= (int)puVar1[4]) && (puVar1[6] != 0)) {
    iVar4 = puVar1[6] + puVar1[5];
    iVar3 = func_0x00763250(iVar4 * 4);
    if (iVar3 == 0) {
      func_0x00764590(1,0x94e51c);
    }
    else {
      iVar2 = 0;
      if (0 < (int)puVar1[4]) {
        do {
          iVar2 = iVar2 + 1;
          *(undefined4 *)(iVar3 + -4 + iVar2 * 4) = *(undefined4 *)(puVar1[3] + -4 + iVar2 * 4);
        } while (iVar2 < (int)puVar1[4]);
      }
      if (puVar1[3] != 0) {
        func_0x00763260(puVar1[3]);
      }
      puVar1[3] = iVar3;
      puVar1[5] = iVar4;
    }
  }
  *(int *)(puVar1[3] + puVar1[4] * 4) = param_2;
  puVar1[4] = puVar1[4] + 1;
  if ((*(int *)(param_1 + 0x14) <= *(int *)(param_1 + 0x10)) && (*(int *)(param_1 + 0x18) != 0)) {
    iVar4 = *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x14);
    iVar3 = func_0x00763250(iVar4 * 4);
    if (iVar3 == 0) {
      func_0x00764590(1,0x94e51c);
    }
    else {
      iVar2 = 0;
      if (0 < *(int *)(param_1 + 0x10)) {
        do {
          iVar2 = iVar2 + 1;
          *(undefined4 *)(iVar3 + -4 + iVar2 * 4) =
               *(undefined4 *)(*(int *)(param_1 + 0xc) + -4 + iVar2 * 4);
        } while (iVar2 < *(int *)(param_1 + 0x10));
      }
      if (*(int *)(param_1 + 0xc) != 0) {
        func_0x00763260(*(int *)(param_1 + 0xc));
      }
      *(int *)(param_1 + 0xc) = iVar3;
      *(int *)(param_1 + 0x14) = iVar4;
    }
  }
  *(undefined4 **)(*(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x10) * 4) = puVar1;
  iVar3 = *(int *)(param_1 + 0x10) + 1;
  *(int *)(param_1 + 0x10) = iVar3;
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007804b0 | Classified: Angelica3D::proc_7804b0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007804b0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iStack_4;
  
  iStack_4 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    piVar5 = *(int **)(param_1 + 0xc);
    do {
      iVar6 = 0;
      iVar3 = *(int *)(*piVar5 + 0x10);
      if (0 < iVar3) {
        piVar2 = *(int **)(*piVar5 + 0xc);
        do {
          iVar1 = *piVar2;
          if (*(int *)(iVar1 + 4) == param_2) {
            FUN_00780d00();
            FUN_00780bf0();
            func_0x00763260(iVar1);
            iVar3 = iStack_4 * 4;
            iVar1 = *(int *)(iVar3 + *(int *)(param_1 + 0xc));
            iVar4 = (*(int *)(iVar1 + 0x10) - iVar6) + -1;
            if (0 < iVar4) {
              iVar6 = iVar6 * 4;
              do {
                iVar4 = iVar4 + -1;
                *(undefined4 *)(iVar6 + *(int *)(iVar1 + 0xc)) =
                     *(undefined4 *)(iVar6 + 4 + *(int *)(iVar1 + 0xc));
                iVar6 = iVar6 + 4;
              } while (iVar4 != 0);
            }
            *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + -1;
            iVar6 = *(int *)(iVar3 + *(int *)(param_1 + 0xc));
            if (*(int *)(iVar6 + 0x10) == 0) {
              if (iVar6 != 0) {
                FUN_007805b0();
                func_0x00763260(iVar6);
              }
              iVar6 = (*(int *)(param_1 + 0x10) - iStack_4) + -1;
              if (0 < iVar6) {
                do {
                  iVar6 = iVar6 + -1;
                  *(undefined4 *)(iVar3 + *(int *)(param_1 + 0xc)) =
                       *(undefined4 *)(iVar3 + 4 + *(int *)(param_1 + 0xc));
                  iVar3 = iVar3 + 4;
                } while (iVar6 != 0);
              }
              *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
            }
            return 1;
          }
          iVar6 = iVar6 + 1;
          piVar2 = piVar2 + 1;
        } while (iVar6 < iVar3);
      }
      iStack_4 = iStack_4 + 1;
      piVar5 = piVar5 + 1;
    } while (iStack_4 < *(int *)(param_1 + 0x10));
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x007805b0 | Classified: Angelica3D::proc_7805b0 */
/* ==================================================================== */

void __fastcall FUN_007805b0(int param_1)

{
  *(undefined **)(param_1 + 4) = &UNK_008eb3a0;
  *(undefined **)(param_1 + 8) = &UNK_008d5a30;
  if (*(int *)(param_1 + 0xc) != 0) {
    func_0x00763260(*(int *)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007805e0 | Classified: Angelica3D::proc_7805e0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007805e0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    piVar7 = *(int **)(param_1 + 0xc);
    do {
      iVar2 = 0;
      iVar3 = *(int *)(*piVar7 + 0x10);
      if (0 < iVar3) {
        piVar4 = *(int **)(*piVar7 + 0xc);
        do {
          if (*(int *)(*piVar4 + 4) == param_2) {
            iVar3 = iVar6 * 4;
            iVar1 = *(int *)(iVar3 + *(int *)(param_1 + 0xc));
            iVar5 = (*(int *)(iVar1 + 0x10) - iVar2) + -1;
            if (0 < iVar5) {
              iVar2 = iVar2 << 2;
              do {
                iVar5 = iVar5 + -1;
                *(undefined4 *)(iVar2 + *(int *)(iVar1 + 0xc)) =
                     *(undefined4 *)(iVar2 + 4 + *(int *)(iVar1 + 0xc));
                iVar2 = iVar2 + 4;
              } while (iVar5 != 0);
            }
            *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + -1;
            iVar2 = *(int *)(iVar3 + *(int *)(param_1 + 0xc));
            if (*(int *)(iVar2 + 0x10) == 0) {
              if (iVar2 != 0) {
                FUN_007805b0();
                func_0x00763260(iVar2);
              }
              iVar6 = (*(int *)(param_1 + 0x10) - iVar6) + -1;
              if (0 < iVar6) {
                do {
                  iVar6 = iVar6 + -1;
                  *(undefined4 *)(iVar3 + *(int *)(param_1 + 0xc)) =
                       *(undefined4 *)(iVar3 + 4 + *(int *)(param_1 + 0xc));
                  iVar3 = iVar3 + 4;
                } while (iVar6 != 0);
              }
              *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
            }
            return 1;
          }
          iVar2 = iVar2 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar2 < iVar3);
      }
      iVar6 = iVar6 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar6 < *(int *)(param_1 + 0x10));
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x007806c0 | Classified: Angelica3D::proc_7806c0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007806c0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  iVar1 = *(int *)(param_1 + 0x10);
  if (0 < iVar1) {
    do {
      iVar5 = 0;
      iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0xc) + iVar4 * 4) + 0x10);
      if (0 < iVar2) {
        do {
          iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xc) + iVar4 * 4) + 0xc) + iVar5 * 4
                          );
          FUN_00780d00();
          if (iVar3 != 0) {
            FUN_00780bf0();
            func_0x00763260(iVar3);
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar2);
      }
      iVar2 = *(int *)(*(int *)(param_1 + 0xc) + iVar4 * 4);
      if (*(int *)(iVar2 + 0xc) != 0) {
        func_0x00763260(*(int *)(iVar2 + 0xc));
        *(undefined4 *)(iVar2 + 0xc) = 0;
      }
      *(undefined4 *)(iVar2 + 0x14) = 0;
      *(undefined4 *)(iVar2 + 0x10) = 0;
      iVar2 = *(int *)(*(int *)(param_1 + 0xc) + iVar4 * 4);
      if (iVar2 != 0) {
        FUN_007805b0();
        func_0x00763260(iVar2);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    func_0x00763260(*(int *)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00780790 | Classified: Angelica3D::proc_780790 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_00780790(int param_1,float *param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  uint in_EAX;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  uint uStack_14;
  
  uStack_14 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    piVar6 = *(int **)(param_1 + 0xc);
    do {
      iVar5 = 0;
      iVar1 = *(int *)(*piVar6 + 0x10);
      if (0 < iVar1) {
        piVar7 = *(int **)(*piVar6 + 0xc);
        do {
          iVar2 = *piVar7;
          fVar3 = param_2[1] - *(float *)(iVar2 + 0x28);
          if ((ABS(*param_2 - *(float *)(iVar2 + 0x24)) <
               (float)*(int *)(iVar2 + 0x18) * *(float *)(iVar2 + 0x20) * _DAT_008eff98) &&
             (ABS(param_2[2] - *(float *)(iVar2 + 0x2c)) <
              (float)*(int *)(iVar2 + 0x1c) * *(float *)(iVar2 + 0x20) * _DAT_008eff98)) {
            in_EAX = (uint)(ushort)((ushort)(fVar3 < _DAT_008effc4) << 8 |
                                    (ushort)(NAN(fVar3) || NAN(_DAT_008effc4)) << 10 |
                                   (ushort)(fVar3 == _DAT_008effc4) << 0xe);
            if (fVar3 < _DAT_008effc4) {
              uVar4 = FUN_00781c50(param_2);
              return uVar4;
            }
            goto LAB_00780831;
          }
          iVar5 = iVar5 + 1;
          piVar7 = piVar7 + 1;
        } while (iVar5 < iVar1);
      }
      piVar6 = piVar6 + 1;
      in_EAX = uStack_14 + 1;
      uStack_14 = in_EAX;
    } while ((int)in_EAX < *(int *)(param_1 + 0x10));
  }
LAB_00780831:
  return in_EAX & 0xffffff00;
}


/* ==================================================================== */
/* Address: 0x00780860 | Classified: Angelica3D::proc_780860 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_00780860(int param_1,float *param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iStack_14;
  
  iStack_14 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    piVar6 = *(int **)(param_1 + 0xc);
    do {
      iVar4 = 0;
      iVar1 = *(int *)(*piVar6 + 0x10);
      if (0 < iVar1) {
        piVar5 = *(int **)(*piVar6 + 0xc);
        do {
          iVar2 = *piVar5;
          if ((ABS(*param_2 - *(float *)(iVar2 + 0x24)) <
               (float)*(int *)(iVar2 + 0x18) * *(float *)(iVar2 + 0x20) * _DAT_008eff98) &&
             (ABS(param_2[2] - *(float *)(iVar2 + 0x2c)) <
              (float)*(int *)(iVar2 + 0x1c) * *(float *)(iVar2 + 0x20) * _DAT_008eff98)) {
            cVar3 = FUN_00781c50(param_2);
            if (cVar3 != '\0') {
              return (float10)*(float *)(iVar2 + 0x28);
            }
            goto LAB_007808f3;
          }
          iVar4 = iVar4 + 1;
          piVar5 = piVar5 + 1;
        } while (iVar4 < iVar1);
      }
      piVar6 = piVar6 + 1;
      iStack_14 = iStack_14 + 1;
    } while (iStack_14 < *(int *)(param_1 + 0x10));
  }
LAB_007808f3:
  return (float10)_DAT_008effc4;
}


/* ==================================================================== */
/* Address: 0x00780920 | Classified: Angelica3D::proc_780920 */
/* ==================================================================== */

float10 __fastcall FUN_00780920(int *param_1)

{
  return (float10)*(float *)(*param_1 + 0x24);
}


/* ==================================================================== */
/* Address: 0x00780930 | Classified: Angelica3D::proc_780930 */
/* ==================================================================== */

float10 __fastcall FUN_00780930(int *param_1)

{
  return (float10)*(float *)(*param_1 + 0x69c);
}


/* ==================================================================== */
/* Address: 0x00780940 | Classified: Angelica3D::proc_780940 */
/* ==================================================================== */

float10 __fastcall FUN_00780940(int *param_1)

{
  return (float10)*(float *)(*param_1 + 0x6a0);
}


/* ==================================================================== */
/* Address: 0x00780950 | Classified: Angelica3D::proc_780950 */
/* ==================================================================== */

undefined4 __fastcall FUN_00780950(int *param_1)

{
  return CONCAT31((int3)((uint)*param_1 >> 8),*(undefined1 *)(*param_1 + 0x18));
}


/* ==================================================================== */
/* Address: 0x00780960 | Classified: Angelica3D::proc_780960 */
/* ==================================================================== */

float10 __fastcall FUN_00780960(int *param_1)

{
  return (float10)*(float *)(*param_1 + 0xc4);
}


/* ==================================================================== */
/* Address: 0x00780970 | Classified: Angelica3D::proc_780970 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00780970(int *param_1,float param_2)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = *param_1;
  bVar2 = param_2 < _DAT_008effc4;
  *(float *)(iVar1 + 0xc4) = param_2;
  if (bVar2) {
    *(undefined4 *)(iVar1 + 0xc4) = 0;
  }
  if (_DAT_008effa0 < *(float *)(iVar1 + 0xc4)) {
    *(undefined4 *)(iVar1 + 0xc4) = 0x3f800000;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00780980 | Classified: Angelica3D::proc_780980 */
/* ==================================================================== */

undefined4 __fastcall FUN_00780980(int *param_1)

{
  return *(undefined4 *)(*param_1 + 0x2e4 + *(int *)(*param_1 + 0x2e0) * 4);
}


/* ==================================================================== */
/* Address: 0x00780990 | Classified: Angelica3D::proc_780990 */
/* ==================================================================== */

void __thiscall FUN_00780990(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x6bc) = param_2;
  *(undefined4 *)(iVar1 + 0x6c0) = param_3;
  *(undefined4 *)(iVar1 + 0x6c4) = param_4;
  return;
}


/* ==================================================================== */
/* Address: 0x007809c0 | Classified: Angelica3D::proc_7809c0 */
/* ==================================================================== */

void __thiscall FUN_007809c0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x6c8) = param_2;
  *(undefined4 *)(iVar1 + 0x6cc) = param_3;
  *(undefined4 *)(iVar1 + 0x6d0) = param_4;
  return;
}


/* ==================================================================== */
/* Address: 0x007809f0 | Classified: Angelica3D::proc_7809f0 */
/* ==================================================================== */

void __thiscall FUN_007809f0(int *param_1,undefined4 param_2)

{
  *(undefined4 *)(*param_1 + 0x6d4) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00780a00 | Classified: Angelica3D::proc_780a00 */
/* ==================================================================== */

undefined4 __thiscall FUN_00780a00(int *param_1,undefined4 param_2)

{
  int iVar1;
  char extraout_AL;
  undefined3 uVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  
  iVar1 = *param_1;
  uVar2 = (undefined3)((uint)param_2 >> 8);
  if (((*(char *)(iVar1 + 0x19) != '\0') && (*(char *)(iVar1 + 0x2d) == '\0')) &&
     (*(char *)(iVar1 + 0x2c) != (char)param_2)) {
    *(char *)(iVar1 + 0x2c) = (char)param_2;
    func_0x007c9d10();
    func_0x007c9690();
    uVar2 = extraout_var;
    if (extraout_AL == '\0') {
      func_0x007c9d10();
      *(undefined1 *)(iVar1 + 0x2d) = 1;
      uVar2 = extraout_var_00;
    }
  }
  return CONCAT31(uVar2,1);
}


/* ==================================================================== */
/* Address: 0x00780a10 | Classified: Angelica3D::proc_780a10 */
/* ==================================================================== */

undefined4 __thiscall FUN_00780a10(int *param_1,char param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined1 auStack_104 [260];
  
  iVar1 = *param_1;
  if (*(char *)(iVar1 + 0x18) != '\0') {
    if (*(char *)(iVar1 + 0x2d) != param_2) {
      *(char *)(iVar1 + 0x2d) = param_2;
      if (param_2 == '\0') {
        cVar2 = func_0x007c9690();
        if (cVar2 == '\0') {
          func_0x007c9d10();
          *(undefined1 *)(iVar1 + 0x2d) = 1;
          return 0;
        }
        iVar3 = 0;
        if (0 < *(int *)(iVar1 + 0x1d4)) {
          piVar4 = (int *)(iVar1 + 0x1dc);
          do {
            if (*piVar4 == 0) {
              sprintf(auStack_104,0x990c7c,iVar3);
              cVar2 = func_0x0077c230(auStack_104,piVar4,0,0);
              if (cVar2 == '\0') {
                func_0x007647d0(0x9d2f20,0x990c38,auStack_104);
                return 0;
              }
            }
            iVar3 = iVar3 + 1;
            piVar4 = piVar4 + 1;
          } while (iVar3 < *(int *)(iVar1 + 0x1d4));
          return 1;
        }
      }
      else {
        func_0x007c9d10();
        iVar3 = 0;
        if (0 < *(int *)(iVar1 + 0x1d4)) {
          piVar4 = (int *)(iVar1 + 0x1dc);
          do {
            if (*piVar4 != 0) {
              func_0x0077c560(piVar4);
              *piVar4 = 0;
            }
            iVar3 = iVar3 + 1;
            piVar4 = piVar4 + 1;
          } while (iVar3 < *(int *)(iVar1 + 0x1d4));
        }
      }
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00780a20 | Classified: Angelica3D::proc_780a20 */
/* ==================================================================== */

undefined4 __fastcall FUN_00780a20(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *param_1;
  uVar2 = func_0x007744f0(0);
  iVar3 = FUN_0077fed0(uVar2);
  if (iVar3 != 0) {
    *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar3 + 0xc);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00780a30 | Classified: Angelica3D::proc_780a30 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00780a30(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  float10 fVar12;
  float10 extraout_ST0;
  undefined4 uStack_58;
  undefined4 uStack_54;
  int iStack_50;
  undefined1 auStack_4c [12];
  undefined1 auStack_40 [64];
  
  iVar2 = *param_1;
  iVar8 = *(int *)(iVar2 + 0x1c);
  fVar3 = (float)param_2 * _DAT_008f2e28 * _DAT_008f07b0;
  if (iVar8 == 0) {
    uStack_58 = *(undefined4 *)(iVar2 + 0x67c);
    uStack_54 = *(undefined4 *)(iVar2 + 0x680);
    iStack_50 = iVar8;
    func_0x00788c00(auStack_40,fVar3);
    puVar7 = (undefined4 *)func_0x00787290(auStack_4c,&uStack_58,auStack_40);
    uStack_58 = *puVar7;
    uVar1 = puVar7[1];
    *(undefined4 *)(iVar2 + 0x67c) = uStack_58;
    *(undefined4 *)(iVar2 + 0x680) = uVar1;
  }
  else if (iVar8 == 1) {
    fVar4 = (float)param_2 * _DAT_008f2e24;
    fVar5 = fVar4 + *(float *)(iVar2 + 0x63c);
    *(float *)(iVar2 + 0x63c) = fVar5;
    fVar6 = fVar4 + *(float *)(iVar2 + 0x640);
    *(float *)(iVar2 + 0x640) = fVar6;
    if (_DAT_008effa0 < fVar5) {
      *(float *)(iVar2 + 0x63c) = fVar5 - _DAT_008effa0;
    }
    if (_DAT_008effa0 < fVar6) {
      *(float *)(iVar2 + 0x640) = fVar6 - _DAT_008effa0;
    }
    fVar5 = *(float *)(iVar2 + 0x67c) - fVar4;
    *(float *)(iVar2 + 0x67c) = fVar5;
    fVar4 = fVar4 + *(float *)(iVar2 + 0x680);
    *(float *)(iVar2 + 0x680) = fVar4;
    if (fVar5 < _DAT_008f01f4) {
      *(float *)(iVar2 + 0x67c) = fVar5 + _DAT_008effa0;
    }
    if (_DAT_008effa0 < fVar4) {
      *(float *)(iVar2 + 0x680) = fVar4 - _DAT_008effa0;
    }
  }
  fVar3 = fVar3 * _DAT_008f2e20;
  iVar8 = *(int *)(iVar2 + 200) + param_2;
  *(int *)(iVar2 + 200) = iVar8;
  *(float *)(iVar2 + 0x69c) = fVar3 + *(float *)(iVar2 + 0x69c);
  *(float *)(iVar2 + 0x6a0) = fVar3 + *(float *)(iVar2 + 0x6a0);
  if (0x20 < iVar8) {
    iVar9 = *(int *)(iVar2 + 0xd0);
    iVar10 = *(int *)(iVar2 + 0x1d8);
    iVar11 = *(int *)(iVar2 + 0x2e0);
    do {
      iVar8 = iVar8 + -0x21;
      iVar9 = (iVar9 + 1) % *(int *)(iVar2 + 0xcc);
      iVar10 = (iVar10 + 1) % *(int *)(iVar2 + 0x1d4);
      iVar11 = (iVar11 + 1) % *(int *)(iVar2 + 0x2dc);
    } while (0x20 < iVar8);
    *(int *)(iVar2 + 0x2e0) = iVar11;
    *(int *)(iVar2 + 200) = iVar8;
    *(int *)(iVar2 + 0xd0) = iVar9;
    *(int *)(iVar2 + 0x1d8) = iVar10;
  }
  iVar8 = *(int *)(iVar2 + 0x20) - param_2;
  *(int *)(iVar2 + 0x20) = iVar8;
  if (iVar8 < 1) {
    *(undefined4 *)(iVar2 + 0x20) = 1000;
    func_0x007ca440();
  }
  fVar3 = (float)param_2 * _DAT_008effc0;
  fVar12 = (float10)func_0x007cd430(fVar3);
  *(float *)(iVar2 + 0x420) = (float)(fVar12 * (float10)_DAT_008f0d78);
  fVar12 = (float10)func_0x007cd430(fVar3);
  *(float *)(iVar2 + 0x460) = (float)(fVar12 * (float10)_DAT_008f0d78);
  func_0x007cd430(fVar3);
  *(float *)(iVar2 + 0x4a0) = (float)(extraout_ST0 * (float10)_DAT_008f0d78);
  return 1;
}


/* ==================================================================== */
/* Address: 0x00780a40 | Classified: Angelica3D::proc_780a40 */
/* ==================================================================== */

undefined1 __fastcall FUN_00780a40(int *param_1)

{
  int iVar1;
  char cVar2;
  
  iVar1 = *param_1;
  if (*(char *)(iVar1 + 0x2d) == '\0') {
    func_0x007c9d10();
    cVar2 = func_0x007c9690();
    if (cVar2 == '\0') {
      func_0x007c9d10();
      *(undefined1 *)(iVar1 + 0x2d) = 1;
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00780a50 | Classified: elementclient::A3DTerrainWaterSimpleAlphaRender@0x780a50 */
/* ==================================================================== */

bool __thiscall
FUN_00780a50(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  char cVar1;
  int iVar2;
  undefined4 unaff_retaddr;
  
  cVar1 = func_0x00763c30(0x988934);
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(*(int *)*param_1 + 0xc))
                      (0,unaff_retaddr,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                       param_9,param_10,param_11,param_12);
    return cVar1 != '\0';
  }
  iVar2 = 0;
  if (0 < (int)param_1[4]) {
    do {
      cVar1 = (**(code **)(*(int *)*param_1 + 0xc))
                        (iVar2,unaff_retaddr,param_2,param_3,param_4,param_5,param_6,param_7,param_8
                         ,param_9,param_10,param_11,param_12);
      if (cVar1 == '\0') {
        return false;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1[4]);
  }
  return true;
}


/* ==================================================================== */
/* Address: 0x00780b30 | Classified: Angelica3D::proc_780b30 */
/* ==================================================================== */

uint __thiscall
FUN_00780b30(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10,undefined4 param_11)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = param_1[4];
  if (0 < iVar2) {
    do {
      uVar1 = (**(code **)(*(int *)*param_1 + 0x10))
                        (iVar3,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                         param_10,param_11);
      if ((char)uVar1 == '\0') {
        return uVar1 & 0xffffff00;
      }
      iVar2 = param_1[4];
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x00780ba0 | Classified: Angelica3D::proc_780ba0 */
/* ==================================================================== */

void __fastcall FUN_00780ba0(undefined4 *param_1)

{
  param_1[0x27] = &UNK_008d5a30;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0x10;
  param_1[0x26] = &UNK_008f0ae0;
  *param_1 = 0;
  param_1[0x25] = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  *(undefined1 *)(param_1 + 0x24) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00780bf0 | Classified: Angelica3D::proc_780bf0 */
/* ==================================================================== */

void __fastcall FUN_00780bf0(int param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008cc73e;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  FUN_00780d00();
  *(undefined **)(param_1 + 0x98) = &UNK_008f0ae0;
  uStack_4 = 0xffffffff;
  *(undefined **)(param_1 + 0x9c) = &UNK_008d5a30;
  if (*(int *)(param_1 + 0xa0) != 0) {
    func_0x00763260(*(int *)(param_1 + 0xa0));
    *(undefined4 *)(param_1 + 0xa0) = 0;
  }
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x00780c70 | Classified: Angelica3D::proc_780c70 */
/* ==================================================================== */

undefined4 __thiscall
FUN_00780c70(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 *param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[7] = param_5;
  param_1[2] = 0xffcccccc;
  param_1[6] = param_4;
  param_1[8] = param_6;
  param_1[9] = *param_7;
  param_1[10] = param_7[1];
  param_1[0xb] = param_7[2];
  param_1[3] = param_8;
  param_1[4] = 0x41200000;
  puVar3 = (undefined4 *)func_0x00763250(param_1[7] * param_1[6]);
  iVar1 = param_1[7];
  iVar2 = param_1[6];
  param_1[0x25] = puVar3;
  for (uVar4 = (uint)(iVar1 * iVar2) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  for (uVar4 = iVar1 * iVar2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)puVar3 = 0;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00780d00 | Classified: Angelica3D::proc_780d00 */
/* ==================================================================== */

undefined4 __fastcall FUN_00780d00(int param_1)

{
  FUN_00781be0();
  if (*(int *)(param_1 + 0x94) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x94));
    *(undefined4 *)(param_1 + 0x94) = 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00780d30 | Classified: elementclient::A3DWaterArea__Load____version___@0x780d30 */
/* ==================================================================== */

/* WARNING: Removing unreachable block (ram,0x00780ed8) */
/* WARNING: Removing unreachable block (ram,0x00780efb) */
/* WARNING: Removing unreachable block (ram,0x00780eee) */
/* WARNING: Removing unreachable block (ram,0x00780eff) */
/* WARNING: Removing unreachable block (ram,0x00780f1a) */
/* WARNING: Removing unreachable block (ram,0x00780f2a) */
/* WARNING: Removing unreachable block (ram,0x00780f34) */
/* WARNING: Removing unreachable block (ram,0x00780f5d) */
/* WARNING: Removing unreachable block (ram,0x00780f69) */
/* WARNING: Removing unreachable block (ram,0x00780f82) */
/* WARNING: Removing unreachable block (ram,0x00780f8c) */
/* WARNING: Removing unreachable block (ram,0x00780f95) */
/* WARNING: Removing unreachable block (ram,0x00780f4c) */
/* WARNING: Removing unreachable block (ram,0x00780fa1) */
/* WARNING: Removing unreachable block (ram,0x00780fa3) */
/* WARNING: Removing unreachable block (ram,0x00781109) */
/* WARNING: Removing unreachable block (ram,0x0078110d) */
/* WARNING: Removing unreachable block (ram,0x00781134) */
/* WARNING: Removing unreachable block (ram,0x00781127) */
/* WARNING: Removing unreachable block (ram,0x00781138) */
/* WARNING: Removing unreachable block (ram,0x0078121d) */
/* WARNING: Removing unreachable block (ram,0x00781153) */
/* WARNING: Removing unreachable block (ram,0x00781163) */
/* WARNING: Removing unreachable block (ram,0x0078116d) */
/* WARNING: Removing unreachable block (ram,0x00781196) */
/* WARNING: Removing unreachable block (ram,0x007811a2) */
/* WARNING: Removing unreachable block (ram,0x007811bb) */
/* WARNING: Removing unreachable block (ram,0x007811c5) */
/* WARNING: Removing unreachable block (ram,0x007811ce) */
/* WARNING: Removing unreachable block (ram,0x00781185) */
/* WARNING: Removing unreachable block (ram,0x007811da) */
/* WARNING: Removing unreachable block (ram,0x0078120f) */
/* WARNING: Removing unreachable block (ram,0x0078110b) */

undefined4 __thiscall FUN_00780d30(undefined4 *param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  uint unaff_EBX;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 auStack_10 [4];
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  piVar2 = param_3;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cc766;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = param_2;
  cVar3 = (**(code **)(*param_3 + 0x10))(auStack_10,4,&param_2);
  if (cVar3 == '\0') {
LAB_00781303:
    func_0x007647d0(0x9d2f20,0x988994);
  }
  else {
    if (0x10001fff < unaff_EBX) {
      cVar3 = (**(code **)(*piVar2 + 0x10))(param_1 + 1,4,&puStack_8);
      if ((((cVar3 != '\0') &&
           (cVar3 = (**(code **)(*piVar2 + 0x10))(param_1 + 2,4,&puStack_8), cVar3 != '\0')) &&
          (cVar3 = (**(code **)(*piVar2 + 0x10))(param_1 + 3,4,&puStack_8), cVar3 != '\0')) &&
         ((cVar3 = (**(code **)(*piVar2 + 0x10))(param_1 + 4,4,&puStack_8), cVar3 != '\0' &&
          (cVar3 = (**(code **)(*piVar2 + 0x10))(param_1 + 6,4,&puStack_8), cVar3 != '\0')))) {
        piVar1 = param_1 + 7;
        cVar3 = (**(code **)(*piVar2 + 0x10))(piVar1,4,&puStack_8);
        if (((cVar3 != '\0') &&
            ((cVar3 = (**(code **)(*piVar2 + 0x10))(param_1 + 8,4,&puStack_8), cVar3 != '\0' &&
             (cVar3 = (**(code **)(*piVar2 + 0x10))(param_1 + 9,0xc,&puStack_8), cVar3 != '\0'))))
           && ((unaff_EBX < 0x10003000 ||
               (cVar3 = (**(code **)(*piVar2 + 0x10))(param_1 + 5,1,&puStack_8), cVar3 != '\0')))) {
          uVar4 = func_0x00763250(*piVar1 * param_1[6]);
          param_1[0x25] = uVar4;
          cVar3 = (**(code **)(*piVar2 + 0x10))(uVar4,*piVar1 * param_1[6],&puStack_8);
          if (cVar3 != '\0') {
            cVar3 = (**(code **)(*piVar2 + 0x10))(&stack0xffffffdc,4,&puStack_8);
joined_r0x007810f3:
            if (cVar3 != '\0') {
              FUN_00781620();
              uVar4 = 1;
              goto LAB_0078132c;
            }
          }
        }
      }
      goto LAB_00781303;
    }
    if (unaff_EBX == 0x10001000) {
      cVar3 = (**(code **)(*piVar2 + 0x10))(param_1 + 1,4,&puStack_8);
      if ((((cVar3 != '\0') &&
           (cVar3 = (**(code **)(*piVar2 + 0x10))(param_1 + 2,4,&puStack_8), cVar3 != '\0')) &&
          (cVar3 = (**(code **)(*piVar2 + 0x10))(param_1 + 3,4,&puStack_8), cVar3 != '\0')) &&
         (cVar3 = (**(code **)(*piVar2 + 0x10))(param_1 + 6,4,&puStack_8), cVar3 != '\0')) {
        piVar1 = param_1 + 7;
        cVar3 = (**(code **)(*piVar2 + 0x10))(piVar1,4,&puStack_8);
        if (((cVar3 != '\0') &&
            (cVar3 = (**(code **)(*piVar2 + 0x10))(param_1 + 8,4,&puStack_8), cVar3 != '\0')) &&
           (cVar3 = (**(code **)(*piVar2 + 0x10))(param_1 + 9,0xc,&puStack_8), cVar3 != '\0')) {
          uVar4 = func_0x00763250(*piVar1 * param_1[6]);
          param_1[0x25] = uVar4;
          cVar3 = (**(code **)(*piVar2 + 0x10))(uVar4,*piVar1 * param_1[6],&puStack_8);
          if (cVar3 != '\0') {
            cVar3 = (**(code **)(*piVar2 + 0x10))(&stack0xffffffe0,4,&puStack_8);
            goto joined_r0x007810f3;
          }
        }
      }
      goto LAB_00781303;
    }
    if (unaff_EBX == 0x10000000) {
      cVar3 = (**(code **)(*piVar2 + 0x10))(param_1 + 1,4,&puStack_8);
      if (cVar3 != '\0') {
        param_1[2] = 0xffcccccc;
        cVar3 = (**(code **)(*piVar2 + 0x10))(param_1 + 3,4,&puStack_8);
        if ((cVar3 != '\0') &&
           (cVar3 = (**(code **)(*piVar2 + 0x10))(param_1 + 6,4,&puStack_8), cVar3 != '\0')) {
          piVar1 = param_1 + 7;
          cVar3 = (**(code **)(*piVar2 + 0x10))(piVar1,4,&puStack_8);
          if ((cVar3 != '\0') &&
             ((cVar3 = (**(code **)(*piVar2 + 0x10))(param_1 + 8,4,&puStack_8), cVar3 != '\0' &&
              (cVar3 = (**(code **)(*piVar2 + 0x10))(param_1 + 9,0xc,&puStack_8), cVar3 != '\0'))))
          {
            uVar4 = func_0x00763250(*piVar1 * param_1[6]);
            param_1[0x25] = uVar4;
            cVar3 = (**(code **)(*piVar2 + 0x10))(uVar4,*piVar1 * param_1[6],&puStack_8);
            goto joined_r0x007810f3;
          }
        }
      }
      goto LAB_00781303;
    }
    func_0x007647d0(0x9d2f20,0x988958,unaff_EBX);
  }
  uVar4 = 0;
LAB_0078132c:
  *unaff_FS_OFFSET = uStack_18;
  return uVar4;
}


/* ==================================================================== */
/* Address: 0x00781350 | Classified: elementclient::A3DWaterArea__Save____failed_to_s@0x781350 */
/* ==================================================================== */

uint __thiscall FUN_00781350(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined1 auStack_8 [4];
  undefined4 uStack_4;
  
  piVar2 = param_2;
  uStack_4 = 0x10003000;
  cVar3 = (**(code **)(*param_2 + 0x14))(&uStack_4,4,&param_2);
  if (cVar3 != '\0') {
    cVar3 = (**(code **)(*piVar2 + 0x14))(param_1 + 4,4,auStack_8);
    if (cVar3 != '\0') {
      cVar3 = (**(code **)(*piVar2 + 0x14))(param_1 + 8,4,auStack_8);
      if (cVar3 != '\0') {
        cVar3 = (**(code **)(*piVar2 + 0x14))(param_1 + 0xc,4,auStack_8);
        if (cVar3 != '\0') {
          cVar3 = (**(code **)(*piVar2 + 0x14))(param_1 + 0x10,4,auStack_8);
          if (cVar3 != '\0') {
            cVar3 = (**(code **)(*piVar2 + 0x14))(param_1 + 0x18,4,auStack_8);
            if (cVar3 != '\0') {
              cVar3 = (**(code **)(*piVar2 + 0x14))((int *)(param_1 + 0x1c),4,auStack_8);
              if (cVar3 != '\0') {
                cVar3 = (**(code **)(*piVar2 + 0x14))(param_1 + 0x20,4,auStack_8);
                if (cVar3 != '\0') {
                  cVar3 = (**(code **)(*piVar2 + 0x14))(param_1 + 0x24,0xc,auStack_8);
                  if (cVar3 != '\0') {
                    cVar3 = (**(code **)(*piVar2 + 0x14))(param_1 + 0x14,1,auStack_8);
                    if (cVar3 != '\0') {
                      cVar3 = (**(code **)(*piVar2 + 0x14))
                                        (*(undefined4 *)(param_1 + 0x94),
                                         *(int *)(param_1 + 0x18) * *(int *)(param_1 + 0x1c),
                                         auStack_8);
                      if (cVar3 != '\0') {
                        iVar1 = *(int *)(param_1 + 0xa4);
                        cVar3 = (**(code **)(*piVar2 + 0x14))(&stack0xffffffec,4,auStack_8);
                        if (cVar3 != '\0') {
                          iVar5 = 0;
                          if (0 < iVar1) {
                            do {
                              cVar3 = func_0x007829c0(piVar2);
                              if (cVar3 == '\0') {
                                uVar4 = func_0x007647d0(0x9d2f20,0x9889f8);
                                return uVar4 & 0xffffff00;
                              }
                              iVar5 = iVar5 + 1;
                            } while (iVar5 < iVar1);
                          }
                          return CONCAT31((int3)((uint)iVar1 >> 8),1);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  uVar4 = func_0x007647d0(0x9d2f20,0x988a28);
  return uVar4 & 0xffffff00;
}


/* ==================================================================== */
/* Address: 0x00781510 | Classified: elementclient::A3DWaterArea__CopyWaveToBuffer__@0x781510 */
/* ==================================================================== */

uint __thiscall FUN_00781510(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iStack_c;
  
  iVar1 = *(int *)(param_1 + 0xa4);
  iVar5 = 0;
  iVar6 = 0;
  iStack_c = 0;
  if (iVar1 < 1) {
    return 1;
  }
  do {
    iVar2 = *(int *)(*(int *)(param_1 + 0xa0) + iStack_c * 4);
    cVar3 = FUN_00781eb0(param_2 + iVar5 * 0x18,param_3 + iVar6 * 6,iVar5 + param_4);
    if (cVar3 == '\0') {
      uVar4 = func_0x007647d0(0x9d2f20,0x988a58);
      return uVar4 & 0xffffff00;
    }
    iVar6 = iVar6 + *(int *)(iVar2 + 0x20);
    iVar5 = iVar5 + *(int *)(iVar2 + 0x1c);
    iStack_c = iStack_c + 1;
  } while (iStack_c < iVar1);
  return CONCAT31((int3)((uint)iStack_c >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007815c0 | Classified: Angelica3D::proc_7815c0 */
/* ==================================================================== */

int __fastcall FUN_007815c0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0xa4);
  iVar2 = 0;
  if (0 < iVar4) {
    piVar3 = *(int **)(param_1 + 0xa0);
    do {
      iVar1 = *piVar3;
      piVar3 = piVar3 + 1;
      iVar2 = iVar2 + *(int *)(iVar1 + 0x1c);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return iVar2;
}


/* ==================================================================== */
/* Address: 0x007815f0 | Classified: Angelica3D::proc_7815f0 */
/* ==================================================================== */

int __fastcall FUN_007815f0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0xa4);
  iVar2 = 0;
  if (0 < iVar4) {
    piVar3 = *(int **)(param_1 + 0xa0);
    do {
      iVar1 = *piVar3;
      piVar3 = piVar3 + 1;
      iVar2 = iVar2 + *(int *)(iVar1 + 0x20);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return iVar2;
}


/* ==================================================================== */
/* Address: 0x00781620 | Classified: elementclient::A3DWaterArea__UpdateAll____faile@0x781620 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00781620(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  int iVar6;
  
  iVar6 = 0;
  iVar1 = *(int *)(param_1 + 0xa4);
  if (0 < iVar1) {
    do {
      cVar5 = FUN_00782020();
      if (cVar5 == '\0') {
        func_0x007647d0(0x9d2f20,0x988aa8);
        return 0;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar1);
  }
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0x447a0000;
  fVar2 = (float)*(int *)(param_1 + 0x18) * *(float *)(param_1 + 0x20) * _DAT_008eff98;
  *(float *)(param_1 + 0x48) = *(float *)(param_1 + 0x24) - fVar2;
  fVar3 = (float)*(int *)(param_1 + 0x1c) * *(float *)(param_1 + 0x20) * _DAT_008eff98;
  *(float *)(param_1 + 0x50) = *(float *)(param_1 + 0x2c) - fVar3;
  *(float *)(param_1 + 0x54) = fVar2 + *(float *)(param_1 + 0x24);
  *(float *)(param_1 + 0x5c) = fVar3 + *(float *)(param_1 + 0x2c);
  fVar2 = (*(float *)(param_1 + 0x48) + *(float *)(param_1 + 0x54)) * _DAT_008eff98;
  fVar3 = (*(float *)(param_1 + 0x4c) + *(float *)(param_1 + 0x58)) * _DAT_008eff98;
  *(float *)(param_1 + 0x30) = fVar2;
  fVar4 = (*(float *)(param_1 + 0x50) + *(float *)(param_1 + 0x5c)) * _DAT_008eff98;
  *(float *)(param_1 + 0x38) = fVar4;
  *(float *)(param_1 + 0x34) = fVar3;
  *(float *)(param_1 + 0x3c) = *(float *)(param_1 + 0x54) - fVar2;
  *(float *)(param_1 + 0x40) = *(float *)(param_1 + 0x58) - fVar3;
  *(float *)(param_1 + 0x44) = *(float *)(param_1 + 0x5c) - fVar4;
  FUN_00781760();
  return 1;
}


/* ==================================================================== */
/* Address: 0x00781730 | Classified: Angelica3D::proc_781730 */
/* ==================================================================== */

void __thiscall FUN_00781730(int param_1,int param_2,int param_3,byte param_4)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(*(int *)(param_1 + 0x18) * param_3 + *(int *)(param_1 + 0x94) + param_2);
  *pbVar1 = *pbVar1 | param_4;
  FUN_00781760();
  return;
}


/* ==================================================================== */
/* Address: 0x00781760 | Classified: Angelica3D::proc_781760 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00781760(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  float unaff_ESI;
  float unaff_EDI;
  float fStack_64;
  float fStack_60;
  undefined4 uStack_5c;
  float fStack_58;
  float fStack_54;
  undefined4 uStack_50;
  float fStack_4c;
  float fStack_48;
  undefined4 uStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_28;
  undefined4 auStack_24 [2];
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  
  *(undefined4 *)(param_1 + 0x78) = 0x497423f0;
  *(undefined4 *)(param_1 + 0x7c) = 0x497423f0;
  *(undefined4 *)(param_1 + 0x80) = 0x497423f0;
  *(undefined4 *)(param_1 + 0x84) = 0xc97423f0;
  *(undefined4 *)(param_1 + 0x88) = 0xc97423f0;
  *(undefined4 *)(param_1 + 0x8c) = 0xc97423f0;
  iVar1 = *(int *)(param_1 + 0x18);
  fStack_54 = *(float *)(param_1 + 0x24) - (float)iVar1 * *(float *)(param_1 + 0x20) * _DAT_008eff98
  ;
  fStack_64 = 0.0;
  fStack_4c = (float)*(int *)(param_1 + 0x1c) * *(float *)(param_1 + 0x20) * _DAT_008eff98 +
              *(float *)(param_1 + 0x2c);
  auStack_24[0] = *(undefined4 *)(param_1 + 0x20);
  fStack_10 = -*(float *)(param_1 + 0x20);
  if (0 < *(int *)(param_1 + 0x1c)) {
    do {
      fStack_60 = fStack_54;
      uStack_5c = *(undefined4 *)(param_1 + 0x28);
      iVar4 = iVar1 * (int)fStack_64;
      fStack_58 = fStack_4c - (float)(int)fStack_64 * *(float *)(param_1 + 0x20);
      iVar3 = 0;
      if (0 < iVar1) {
        do {
          if ((*(byte *)(*(int *)(param_1 + 0x94) + iVar3 + iVar4) & 1) != 0) {
            func_0x00774a10(&fStack_60);
            fStack_4c = fStack_28 + fStack_64;
            fStack_48 = fStack_60;
            uStack_44 = uStack_5c;
            func_0x00774a10(&fStack_4c);
            fStack_40 = fStack_64;
            fStack_3c = fStack_18 + fStack_60;
            func_0x00774a10(&uStack_44);
            fStack_3c = fStack_30 + unaff_EDI;
            fStack_10 = fStack_64;
            fStack_34 = fStack_64 + fStack_1c;
            fStack_38 = unaff_ESI;
            func_0x00774a10(&fStack_3c);
          }
          fStack_60 = fStack_60 + *(float *)(param_1 + 0x20);
          iVar1 = *(int *)(param_1 + 0x18);
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar1);
      }
      fStack_64 = (float)((int)fStack_64 + 1);
    } while ((int)fStack_64 < *(int *)(param_1 + 0x1c));
  }
  func_0x00401ca0(*(float *)(param_1 + 0x78) + *(float *)(param_1 + 0x84),
                  *(float *)(param_1 + 0x7c) + *(float *)(param_1 + 0x88),
                  *(float *)(param_1 + 0x80) + *(float *)(param_1 + 0x8c));
  func_0x00401ca0(fStack_3c * _DAT_008eff98,fStack_38 * _DAT_008eff98,fStack_34 * _DAT_008eff98);
  *(float *)(param_1 + 0x60) = fStack_54;
  *(undefined4 *)(param_1 + 100) = uStack_50;
  *(float *)(param_1 + 0x68) = fStack_4c;
  puVar2 = (undefined4 *)
           func_0x00407220(auStack_24,(float *)(param_1 + 0x84),(float *)(param_1 + 0x60));
  *(undefined4 *)(param_1 + 0x6c) = *puVar2;
  *(undefined4 *)(param_1 + 0x70) = puVar2[1];
  *(undefined4 *)(param_1 + 0x74) = puVar2[2];
  return 1;
}


/* ==================================================================== */
/* Address: 0x00781980 | Classified: Angelica3D::proc_781980 */
/* ==================================================================== */

undefined4 __thiscall FUN_00781980(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x94) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x94));
    *(undefined4 *)(param_1 + 0x94) = 0;
  }
  *(int *)(param_1 + 0x18) = param_2;
  *(int *)(param_1 + 0x1c) = param_3;
  puVar1 = (undefined4 *)func_0x00763250(param_2 * param_3);
  uVar2 = *(int *)(param_1 + 0x1c) * *(int *)(param_1 + 0x18);
  *(undefined4 **)(param_1 + 0x94) = puVar1;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar1 = 0;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007819f0 | Classified: elementclient::A3DWaterArea__ShiftTo____failed_t@0x7819f0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007819f0(int param_1,float *param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  fStack_c = *param_2 - *(float *)(param_1 + 0x24);
  iVar3 = 0;
  fStack_8 = param_2[1] - *(float *)(param_1 + 0x28);
  fStack_4 = param_2[2] - *(float *)(param_1 + 0x2c);
  *(float *)(param_1 + 0x24) = *param_2;
  *(float *)(param_1 + 0x28) = param_2[1];
  *(float *)(param_1 + 0x2c) = param_2[2];
  iVar1 = *(int *)(param_1 + 0xa4);
  if (0 < iVar1) {
    do {
      cVar2 = func_0x00782620(&fStack_c);
      if (cVar2 == '\0') {
        func_0x007647d0(0x9d2f20,0x988ae0);
        return 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  FUN_00781620();
  return 1;
}


/* ==================================================================== */
/* Address: 0x00781a90 | Classified: elementclient::A3DWaterArea__AddWave____failed_t@0x781a90 */
/* ==================================================================== */

undefined4 __thiscall FUN_00781a90(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 *unaff_retaddr;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cc77b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar2 = func_0x00763250(0x30);
  uStack_4 = 0;
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00781cf0();
  }
  uStack_4 = 0xffffffff;
  cVar1 = FUN_00781d30(param_1,param_2,param_3);
  if (cVar1 == '\0') {
    func_0x007647d0(0x9d2f20,0x988b1c);
    *unaff_FS_OFFSET = unaff_ESI;
    return 0;
  }
  if ((*(int *)(param_1 + 0xa8) <= *(int *)(param_1 + 0xa4)) && (*(int *)(param_1 + 0xac) != 0)) {
    iVar5 = *(int *)(param_1 + 0xac) + *(int *)(param_1 + 0xa8);
    iVar2 = func_0x00763250(iVar5 * 4);
    if (iVar2 == 0) {
      func_0x00764590(1,0x94e51c);
    }
    else {
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0xa4)) {
        do {
          iVar4 = iVar4 + 1;
          *(undefined4 *)(iVar2 + -4 + iVar4 * 4) =
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + -4 + iVar4 * 4);
        } while (iVar4 < *(int *)(param_1 + 0xa4));
      }
      if (*(int *)(param_1 + 0xa0) != 0) {
        func_0x00763260(*(int *)(param_1 + 0xa0));
      }
      *(int *)(param_1 + 0xa0) = iVar2;
      *(int *)(param_1 + 0xa8) = iVar5;
    }
  }
  *(undefined4 *)(*(int *)(param_1 + 0xa0) + *(int *)(param_1 + 0xa4) * 4) = uVar3;
  *(int *)(param_1 + 0xa4) = *(int *)(param_1 + 0xa4) + 1;
  *(undefined **)(param_1 + 0x10) = puStack_8;
  *unaff_retaddr = uVar3;
  *unaff_FS_OFFSET = unaff_ESI;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00781be0 | Classified: Angelica3D::proc_781be0 */
/* ==================================================================== */

undefined4 __fastcall FUN_00781be0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = *(int *)(param_1 + 0xa4);
  if (0 < iVar1) {
    do {
      iVar2 = *(int *)(*(int *)(param_1 + 0xa0) + iVar3 * 4);
      FUN_00781e00();
      if (iVar2 != 0) {
        thunk_FUN_00781e00();
        func_0x00763260(iVar2);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  if (*(int *)(param_1 + 0xa0) != 0) {
    func_0x00763260(*(int *)(param_1 + 0xa0));
    *(undefined4 *)(param_1 + 0xa0) = 0;
  }
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00781c50 | Classified: Angelica3D::proc_781c50 */
/* ==================================================================== */

bool __fastcall FUN_00781c50(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar3 = func_0x00892e78();
  iVar2 = *(int *)(param_1 + 0x1c);
  iVar4 = func_0x00892e78();
  if (iVar3 < iVar1) {
    if (iVar3 < 0) {
      iVar3 = 0;
    }
  }
  else {
    iVar3 = iVar1 + -1;
  }
  if (iVar4 < iVar2) {
    if (iVar4 < 0) {
      iVar4 = 0;
    }
  }
  else {
    iVar4 = iVar2 + -1;
  }
  return *(char *)(iVar1 * iVar4 + *(int *)(param_1 + 0x94) + iVar3) != '\0';
}


/* ==================================================================== */
/* Address: 0x00781cf0 | Classified: Angelica3D::proc_781cf0 */
/* ==================================================================== */

void __fastcall FUN_00781cf0(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0xbf800000;
  param_1[9] = 0x3f800000;
  return;
}


/* ==================================================================== */
/* Address: 0x00781d20 | Classified: thunk_FUN_00781e00 */
/* ==================================================================== */

undefined4 __fastcall thunk_FUN_00781e00(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x14));
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    func_0x00763260(*(int *)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x28));
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  if (*(int *)(param_1 + 0x2c) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x2c));
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00781d30 | Classified: Angelica3D::proc_781d30 */
/* ==================================================================== */

undefined4 __thiscall
FUN_00781d30(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  *param_1 = param_2;
  param_1[9] = param_3;
  param_1[1] = param_4;
  uVar1 = func_0x00763250(param_4 * 0xc);
  param_1[3] = uVar1;
  uVar1 = func_0x00763250(param_1[1] * 0xc);
  param_1[4] = uVar1;
  uVar1 = func_0x00763250(param_1[1] * 0xc);
  param_1[5] = uVar1;
  puVar4 = (undefined4 *)param_1[4];
  for (uVar2 = param_1[1] * 3 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar4 = 0x80808080;
    puVar4 = puVar4 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar4 = 0x80;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  puVar4 = (undefined4 *)param_1[5];
  for (uVar2 = param_1[1] * 3 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar4 = 0x80808080;
    puVar4 = puVar4 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar4 = 0x80;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  uVar1 = func_0x00763250(param_1[1] * 0x48);
  param_1[10] = uVar1;
  uVar1 = func_0x00763250(param_1[1] * 0x18 + -0x18);
  param_1[0xb] = uVar1;
  param_1[2] = 0;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00781e00 | Classified: Angelica3D::proc_781e00 */
/* ==================================================================== */

undefined4 __fastcall FUN_00781e00(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x14));
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    func_0x00763260(*(int *)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x28));
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  if (*(int *)(param_1 + 0x2c) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x2c));
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00781e70 | Classified: Angelica3D::proc_781e70 */
/* ==================================================================== */

uint __thiscall FUN_00781e70(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 == *(uint *)(param_1 + 4)) {
    return uVar2 & 0xffffff00;
  }
  puVar1 = (undefined4 *)(*(int *)(param_1 + 0xc) + uVar2 * 0xc);
  *puVar1 = *param_2;
  puVar1[1] = param_2[1];
  puVar1[2] = param_2[2];
  iVar3 = *(int *)(param_1 + 8) + 1;
  *(int *)(param_1 + 8) = iVar3;
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x00781eb0 | Classified: Angelica3D::proc_781eb0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00781eb0(int param_1,undefined4 *param_2,int param_3,short param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  float10 fVar4;
  
  fVar4 = (float10)FUN_00780960();
  if ((float10)_DAT_008f0ae4 < ABS((float10)*(float *)(param_1 + 0x18) - fVar4)) {
    *(float *)(param_1 + 0x18) = (float)fVar4;
    FUN_00781f40();
  }
  iVar1 = 0;
  puVar3 = *(undefined4 **)(param_1 + 0x28);
  for (iVar2 = (*(int *)(param_1 + 0x1c) * 3 & 0x1fffffffU) << 1; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_2 = *puVar3;
    puVar3 = puVar3 + 1;
    param_2 = param_2 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)param_2 = *(undefined1 *)puVar3;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  if (0 < *(int *)(param_1 + 0x20) * 3) {
    do {
      *(short *)(param_3 + iVar1 * 2) = *(short *)(*(int *)(param_1 + 0x2c) + iVar1 * 2) + param_4;
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x20) * 3);
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x00781f40 | Classified: Angelica3D::proc_781f40 */
/* ==================================================================== */

undefined4 __fastcall FUN_00781f40(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uStack_c;
  
  iVar4 = func_0x00892e78();
  iVar6 = 0xff - iVar4;
  iVar5 = *(int *)(param_1 + 0x1c);
  iVar7 = 0;
  if (0 < iVar5) {
    uStack_c = 0;
    do {
      uVar2 = *(uint *)(*(int *)(param_1 + 0x10) + iVar7 * 4);
      uVar3 = *(uint *)(*(int *)(param_1 + 0x14) + iVar7 * 4);
      puVar1 = (uint *)(*(int *)(param_1 + 0x28) + 0xc + uStack_c);
      *puVar1 = (((uVar3 & 0xff00) * iVar4 + (uVar2 & 0xff00) * iVar6 ^
                 CONCAT22((short)(uVar3 >> 0x10),(ushort)(byte)uVar3) * iVar4 +
                 CONCAT22((short)(uVar2 >> 0x10),(ushort)(byte)uVar2) * iVar6) & 0xff0000 ^
                (uVar3 & 0xff00ff) * iVar4 + (uVar2 & 0xff00ff) * iVar6) >> 8 | *puVar1 & 0xff000000
      ;
      iVar5 = *(int *)(param_1 + 0x1c);
      iVar7 = iVar7 + 1;
      uStack_c = uStack_c + 0x18;
    } while (iVar7 < iVar5);
  }
  return CONCAT31((int3)((uint)iVar5 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x00782020 | Classified: Angelica3D::proc_782020 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00782020(int param_1)

{
  float *pfVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  undefined4 *puVar9;
  float *pfVar10;
  short sVar11;
  int iVar12;
  int iVar13;
  int unaff_EBP;
  float unaff_ESI;
  float unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  unkbyte10 Var14;
  float10 fVar15;
  float10 extraout_ST1;
  float fVar16;
  float fVar17;
  int iVar18;
  float fStack_220;
  float fStack_21c;
  float fStack_218;
  float fStack_214;
  float fStack_204;
  float fStack_1ec;
  float fStack_1e8;
  float fStack_1e4;
  float fStack_1e0;
  float fStack_1dc;
  float fStack_1d8;
  float fStack_1d4;
  float fStack_1d0;
  float fStack_1cc;
  float fStack_1c8;
  float fStack_1c4;
  float fStack_1c0;
  undefined4 uStack_1bc;
  float fStack_1b0;
  float fStack_1ac;
  float fStack_1a8;
  undefined1 auStack_198 [4];
  float fStack_194;
  undefined1 auStack_18c [4];
  float fStack_188;
  undefined4 uStack_184;
  float fStack_180;
  float fStack_17c;
  float fStack_178;
  float fStack_174;
  float fStack_170;
  float fStack_16c;
  undefined1 auStack_168 [4];
  float fStack_164;
  undefined1 auStack_158 [4];
  undefined1 auStack_154 [8];
  undefined4 uStack_14c;
  undefined4 uStack_148;
  float fStack_144;
  int iStack_140;
  float fStack_11c;
  undefined4 uStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cc79b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  fStack_1e0 = 0.0;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 8) * 3;
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 8) * 4 + -4;
  fStack_214 = 1.1031882e-38;
  FUN_007662b0();
  fStack_214 = 8.45824e-42;
  fStack_218 = 7.00649e-45;
  fStack_21c = 0.995;
  fStack_220 = 3.22299e-44;
  uStack_4 = 0;
  FUN_00766320(0x40,0x3f800000);
  iVar8 = *(int *)(param_1 + 8);
  fStack_21c = 0.0;
  if (0 < iVar8) {
    do {
      fVar7 = fStack_21c;
      iVar12 = unaff_EBP;
      if (fStack_21c != (float)(iVar8 + -1)) {
        iVar12 = *(int *)(param_1 + 0xc);
        iVar8 = (int)fStack_21c * 3 + 3;
        pfVar10 = (float *)(iVar12 + (int)fStack_21c * 0xc);
        fStack_214 = *(float *)(iVar12 + 8 + iVar8 * 4) - pfVar10[2];
        pfVar1 = (float *)(iVar12 + iVar8 * 4);
        fStack_1dc = pfVar1[1] - pfVar10[1];
        unaff_ESI = *pfVar1 - *pfVar10;
        fStack_218 = fStack_1dc * _DAT_008effc4;
        fStack_16c = fStack_218 - unaff_ESI;
        fStack_170 = unaff_ESI * _DAT_008effc4 - fStack_214 * _DAT_008effc4;
        fStack_174 = fStack_214 - fStack_218;
        fStack_1e0 = unaff_ESI;
        fStack_1d8 = fStack_214;
        func_0x00450b30(&fStack_1b0,&fStack_174);
        fStack_1ec = fStack_1b0;
        fStack_1e8 = fStack_1ac;
        fStack_1e4 = fStack_1a8;
        iVar12 = unaff_EBP;
      }
      if (fVar7 == 0.0) {
        func_0x00450b30(auStack_18c,&fStack_1ec);
        fStack_204 = fStack_188;
      }
      else if (fVar7 == (float)(*(int *)(param_1 + 8) + -1)) {
        func_0x00450b30(auStack_198,&fStack_1d4);
        fStack_204 = fStack_194;
      }
      else {
        fStack_178 = fStack_1cc + fStack_1e4;
        fStack_17c = fStack_1d0 + fStack_1e8;
        fStack_180 = fStack_1d4 + fStack_1ec;
        func_0x00450b30(auStack_168,&fStack_180);
        fStack_204 = fStack_164;
      }
      fVar17 = (float)(int)fStack_21c;
      iVar18 = 1;
      FUN_00766490(fVar17,&stack0xfffffdf0);
      fStack_21c = (fStack_21c - _DAT_008eff98) * _DAT_008f0050;
      iVar8 = rand();
      fVar5 = (float)(iVar8 % 0xb) * _DAT_008f092c;
      func_0x00450b30(&fStack_1d4,&fStack_1ec);
      Var14 = func_0x00892f06();
      fVar15 = (float10)fsin(Var14);
      iVar13 = (int)fVar7 * 0xc;
      puVar9 = (undefined4 *)(*(int *)(param_1 + 0xc) + iVar13);
      iVar8 = (int)fVar7 * 0x48;
      fVar15 = extraout_ST1 / ABS(fVar15);
      fStack_218 = (float)((float10)unaff_ESI * fVar15);
      fStack_220 = (float)((float10)unaff_EDI * fVar15);
      uVar2 = puVar9[2];
      fVar16 = (float)puVar9[1];
      uVar3 = *puVar9;
      fVar6 = fStack_21c + _DAT_008effa0;
      iVar4 = *(int *)(param_1 + 0x28);
      *(undefined4 *)(iVar4 + 0xc + iVar8) = 0xffffff;
      puVar9 = (undefined4 *)(iVar4 + iVar8);
      fStack_204 = fStack_204 * _DAT_008f0af4;
      puVar9[5] = fVar6;
      *puVar9 = uVar3;
      puVar9[4] = fStack_204;
      puVar9[1] = fVar5 + fVar16;
      puVar9[2] = uVar2;
      pfVar10 = (float *)(*(int *)(param_1 + 0xc) + iVar13);
      fStack_1c0 = pfVar10[2] - fStack_218 * _DAT_008f0af0;
      fStack_1c4 = pfVar10[1] - fStack_220 * _DAT_008f0af0;
      fStack_1c8 = *pfVar10 - (float)(fVar15 * (float10)fStack_214) * _DAT_008f0af0;
      fVar16 = fStack_21c + _DAT_008f0aec;
      fStack_11c = fStack_204;
      func_0x00401cc0(&fStack_1c8);
      unaff_EBP = *(int *)(param_1 + 0x28) + 0x18 + iVar8;
      uStack_148 = 0xffffffff;
      fStack_144 = fVar16;
      iStack_140 = iVar12;
      func_0x00401cc0(auStack_154);
      *(undefined4 *)(iVar18 + 0xc) = uStack_14c;
      *(undefined4 *)(iVar18 + 0x10) = uStack_148;
      *(float *)(iVar18 + 0x14) = fStack_144;
      pfVar10 = (float *)(*(int *)(param_1 + 0xc) + iVar13);
      fVar16 = *pfVar10 - fVar16;
      func_0x00401ca0(fVar16,pfVar10[1] - fStack_204,pfVar10[2] - fStack_220);
      func_0x00401ca0(fStack_1c4,fStack_1c0 - unaff_EDI,uStack_1bc);
      fVar17 = fVar17 + _DAT_008eff98;
      func_0x00401cc0(auStack_158);
      iVar8 = *(int *)(param_1 + 0x28) + 0x30 + iVar8;
      fStack_180 = 2.3509886e-38;
      fStack_17c = fVar17;
      fStack_178 = fVar16;
      func_0x00401cc0(auStack_18c);
      *(undefined4 *)(iVar8 + 0xc) = uStack_184;
      *(float *)(iVar8 + 0x10) = fStack_180;
      *(float *)(iVar8 + 0x14) = fStack_17c;
      if (fVar7 != (float)(*(int *)(param_1 + 8) + -1)) {
        iVar8 = (int)fVar7 * 0x18;
        sVar11 = SUB42(fVar7,0) * 3;
        *(short *)(iVar8 + *(int *)(param_1 + 0x2c)) = sVar11;
        *(short *)(iVar8 + 2 + *(int *)(param_1 + 0x2c)) = sVar11 + 1;
        *(short *)(iVar8 + 4 + *(int *)(param_1 + 0x2c)) = SUB42(fVar7,0) * 3 + 3;
        iVar12 = *(int *)(param_1 + 0x2c) + iVar8;
        *(undefined2 *)(iVar12 + 6) = *(undefined2 *)(iVar12 + 4);
        iVar12 = *(int *)(param_1 + 0x2c) + iVar8;
        *(undefined2 *)(iVar12 + 8) = *(undefined2 *)(iVar12 + 2);
        *(short *)(iVar8 + 10 + *(int *)(param_1 + 0x2c)) = sVar11 + 4;
        iVar12 = *(int *)(param_1 + 0x2c) + iVar8;
        *(undefined2 *)(iVar12 + 0xc) = *(undefined2 *)(iVar12 + 10);
        iVar12 = *(int *)(param_1 + 0x2c) + iVar8;
        *(undefined2 *)(iVar12 + 0xe) = *(undefined2 *)(iVar12 + 8);
        *(short *)(iVar8 + 0x10 + *(int *)(param_1 + 0x2c)) = sVar11 + 2;
        iVar12 = *(int *)(param_1 + 0x2c) + iVar8;
        *(undefined2 *)(iVar12 + 0x12) = *(undefined2 *)(iVar12 + 0xc);
        iVar12 = *(int *)(param_1 + 0x2c) + iVar8;
        *(undefined2 *)(iVar12 + 0x14) = *(undefined2 *)(iVar12 + 0x10);
        *(short *)(iVar8 + 0x16 + *(int *)(param_1 + 0x2c)) = sVar11 + 5;
      }
      func_0x00401cc0(&fStack_220);
      func_0x0044fc90(&fStack_218);
      iVar8 = *(int *)(param_1 + 8);
      fStack_21c = (float)((int)fVar7 + 1);
    } while ((int)fStack_21c < iVar8);
  }
  uStack_1c = 0xffffffff;
  FUN_007662d0();
  *unaff_FS_OFFSET = uStack_24;
  return 1;
}


