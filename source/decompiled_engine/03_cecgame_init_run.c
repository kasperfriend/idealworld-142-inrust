/* Authentic Ghidra 12.1.4 Decompilation — elementclient.exe (PW 1.4.2 Build 2305) */
/* Module: 03_cecgame_init_run.c */

/* ==================================================================== */
/* Address: 0x0042ccb0 | Classified: ElementClient::proc_42ccb0 */
/* ==================================================================== */

void __fastcall FUN_0042ccb0(int param_1)

{
  char cVar1;
  undefined4 unaff_retaddr;
  
  cVar1 = *(char *)(*(int *)(param_1 + 0x18) + 0x5b9);
  while (cVar1 != '\0') {
    Sleep(10);
    cVar1 = *(char *)(*(int *)(param_1 + 0x18) + 0x5b9);
  }
  FUN_0079b150(0x7fffffff);
  *(undefined1 *)(param_1 + 0x78) = 1;
  func_0x004b6030(unaff_retaddr);
  return;
}


/* ==================================================================== */
/* Address: 0x0042cd00 | Classified: ElementClient::proc_42cd00 */
/* ==================================================================== */

uint __thiscall FUN_0042cd00(int param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x90);
  if ((((*(uint *)(param_1 + 0x90) == param_2) && (uVar1 = 0, *(int *)(param_1 + 100) != 0)) &&
      (uVar1 = param_3, *(uint *)(*(int *)(param_1 + 100) + 4) == param_3)) &&
     ((*(int *)(param_1 + 0x5c) != 0 &&
      (uVar1 = *(uint *)(*(int *)(param_1 + 0x5c) + 4), uVar1 == param_4)))) {
    return CONCAT31((int3)(uVar1 >> 8),1);
  }
  return uVar1 & 0xffffff00;
}


/* ==================================================================== */
/* Address: 0x0042cd80 | Classified: ElementClient::proc_42cd80 */
/* ==================================================================== */

undefined4 FUN_0042cd80(void)

{
  func_0x0087b600();
  return 0x9b3ee4;
}


/* ==================================================================== */
/* Address: 0x0042cd90 | Classified: ElementClient::proc_42cd90 */
/* ==================================================================== */

void FUN_0042cd90(void)

{
  func_0x00892e60(&UNK_0042cda0);
  return;
}


/* ==================================================================== */
/* Address: 0x0042cdb0 | Classified: ElementClient::proc_42cdb0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_0042cdb0(int param_1,byte param_2)

{
  if ((param_2 & 2) != 0) {
    func_0x00892d40(param_1,0x11,*(undefined4 *)(param_1 + -4),&UNK_0042ce20);
    if ((param_2 & 1) != 0) {
      func_0x00763260(param_1 + -4);
    }
    return param_1 + -4;
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    func_0x00763260(*(int *)(param_1 + 0xc));
    _DAT_009bf3cc = _DAT_009bf3cc + 1;
  }
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0042ce40 | Classified: ElementClient::proc_42ce40 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0042ce40(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x58);
  if (iVar1 != 0) {
    func_0x00892d40(iVar1,0x11,*(undefined4 *)(iVar1 + -4),&UNK_0042ce20);
    func_0x00763260(iVar1 + -4);
    _DAT_009bf3cc = _DAT_009bf3cc + 1;
  }
  iVar1 = *(int *)(param_1 + 0x60);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 10) != 0) {
      func_0x00763260(*(int *)(iVar1 + 10));
      _DAT_009bf3cc = _DAT_009bf3cc + 1;
    }
    func_0x00763260(iVar1);
    _DAT_009bf3cc = _DAT_009bf3cc + 1;
  }
  iVar1 = *(int *)(param_1 + 0x82);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 5) != 0) {
      func_0x00763260(*(int *)(iVar1 + 5));
      _DAT_009bf3cc = _DAT_009bf3cc + 1;
    }
    func_0x00763260(iVar1);
    _DAT_009bf3cc = _DAT_009bf3cc + 1;
  }
  if (*(int *)(param_1 + 0x8a) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x8a));
    _DAT_009bf3cc = _DAT_009bf3cc + 1;
  }
  if (*(int *)(param_1 + 0x8e) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x8e));
    _DAT_009bf3cc = _DAT_009bf3cc + 1;
  }
  if (*(int *)(param_1 + 0x92) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x92));
    _DAT_009bf3cc = _DAT_009bf3cc + 1;
  }
  if (*(int *)(param_1 + 0xa3) != 0) {
    func_0x00763260(*(int *)(param_1 + 0xa3));
    _DAT_009bf3cc = _DAT_009bf3cc + 1;
  }
  if (*(int *)(param_1 + 0xab) != 0) {
    func_0x00763260(*(int *)(param_1 + 0xab));
    _DAT_009bf3cc = _DAT_009bf3cc + 1;
  }
  if (*(int *)(param_1 + 0xaf) != 0) {
    func_0x00763260(*(int *)(param_1 + 0xaf));
    _DAT_009bf3cc = _DAT_009bf3cc + 1;
  }
  if (*(int *)(param_1 + 0xb7) != 0) {
    func_0x00763260(*(int *)(param_1 + 0xb7));
    _DAT_009bf3cc = _DAT_009bf3cc + 1;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0042cfe0 | Classified: ElementClient::proc_42cfe0 */
/* ==================================================================== */

undefined4 FUN_0042cfe0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  return param_3;
}


/* ==================================================================== */
/* Address: 0x0042cff0 | Classified: ElementClient::proc_42cff0 */
/* ==================================================================== */

void FUN_0042cff0(int param_1)

{
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) * 100;
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) * 100;
  return;
}


/* ==================================================================== */
/* Address: 0x0042d020 | Classified: ElementClient::proc_42d020 */
/* ==================================================================== */

void FUN_0042d020(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  *param_2 = 0;
  *param_3 = 1;
  return;
}


/* ==================================================================== */
/* Address: 0x0042d040 | Classified: ElementClient::proc_42d040 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_0042d040(undefined4 *param_1)

{
  uint *puVar1;
  int iVar2;
  undefined1 uVar4;
  undefined4 uVar3;
  undefined4 *puVar5;
  int *unaff_FS_OFFSET;
  undefined4 uStack_2c;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_14;
  undefined4 *puStack_10;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a7b2a;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  uStack_2c = (undefined4 *)0x42d069;
  puStack_10 = param_1;
  func_0x00419230();
  uStack_4 = 0;
  uStack_2c = (undefined4 *)0x42d077;
  func_0x00419230();
  uStack_4._0_1_ = 1;
  uStack_2c = (undefined4 *)0x42d087;
  func_0x00419230();
  uStack_4._0_1_ = 2;
  uStack_2c = (undefined4 *)0x42d097;
  func_0x00419230();
  uStack_4._0_1_ = 3;
  uStack_2c = (undefined4 *)0x42d0a7;
  func_0x00419230();
  uStack_4 = CONCAT31(uStack_4._1_3_,4);
  param_1[0x56] = 0;
  uStack_18 = 0;
  iVar2 = 0;
  puVar1 = (uint *)&UNK_008d6aac;
  do {
    if (0x400 < *puVar1) {
      uVar4 = (undefined1)((uint)*(undefined4 *)(&UNK_008d6aac + iVar2 * 4) >> 0x18);
      goto LAB_0042d0d3;
    }
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + 1;
  } while ((int)puVar1 < 0x8d6b1c);
  uVar4 = 0xff;
LAB_0042d0d3:
  uStack_2c = &uStack_18;
  func_0x005b0ea0();
  iStack_c = CONCAT31(iStack_c._1_3_,5);
  param_1[0x5c] = 0;
  uStack_1c = 0;
  iVar2 = 0;
  puVar1 = (uint *)&UNK_008d6aac;
  do {
    if (0x40 < *puVar1) {
      uVar3 = *(undefined4 *)(&UNK_008d6aac + iVar2 * 4);
      goto LAB_0042d121;
    }
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + 1;
  } while ((int)puVar1 < 0x8d6b1c);
  uVar3 = 0xffffffff;
LAB_0042d121:
  func_0x005b0ea0(uVar3,&uStack_1c);
  uStack_14 = 7;
  func_0x00431ab0((int)&uStack_2c + 3);
  uStack_18._0_1_ = 8;
  *(undefined1 *)(param_1 + 99) = uVar4;
  param_1[0x62] = 0;
  func_0x005ca880();
  uStack_18 = CONCAT31(uStack_18._1_3_,9);
  param_1[0x89] = 0;
  iVar2 = 0;
  puVar1 = (uint *)&UNK_008d6aac;
  do {
    if (0x200 < *puVar1) {
      uVar3 = *(undefined4 *)(&UNK_008d6aac + iVar2 * 4);
      goto LAB_0042d193;
    }
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + 1;
  } while ((int)puVar1 < 0x8d6b1c);
  uVar3 = 0xffffffff;
LAB_0042d193:
  func_0x005b0ea0(uVar3,&stack0xffffffd8);
  param_1[0x95] = &UNK_008d6b5c;
  param_1[0x96] = 0;
  param_1[0x97] = 0;
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  param_1[0x9a] = 10;
  param_1[0x9b] = 0;
  param_1[0x134] = &UNK_008d5a30;
  param_1[0x135] = 0;
  param_1[0x136] = 0;
  param_1[0x137] = 0;
  param_1[0x138] = 0x10;
  param_1[0x133] = &UNK_008d6b54;
  param_1[0x13a] = &UNK_008d5a30;
  param_1[0x13b] = 0;
  param_1[0x13c] = 0;
  param_1[0x13d] = 0;
  param_1[0x13e] = 0x10;
  param_1[0x139] = &UNK_008d6b4c;
  param_1[0x13f] = _DAT_009858e4;
  *param_1 = &UNK_008d6b44;
  _DAT_009b3eec = param_1;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[5] = 0;
  *(undefined1 *)(param_1 + 0x123) = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[6] = 0;
  param_1[0x124] = 0;
  param_1[0x125] = 0;
  *(undefined1 *)(param_1 + 0x126) = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[0x127] = 0x41f00000;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0x7f] = 0;
  param_1[0x80] = 0;
  param_1[0x128] = 0xffffffff;
  param_1[0x129] = 0;
  param_1[0x12a] = 0xfffffe20;
  param_1[0x81] = 0;
  param_1[0x82] = 0;
  param_1[0x83] = 0;
  param_1[0x84] = 0;
  param_1[0x85] = 0;
  param_1[0x86] = 0;
  param_1[0x87] = 0;
  param_1[0x8e] = 0;
  puVar5 = param_1 + 0x9c;
  for (iVar2 = 0x87; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  puVar5 = param_1 + 299;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  param_1[0x7d] = 0;
  param_1[0x7e] = 0;
  InitializeCriticalSection(param_1 + 0x8f);
  *unaff_FS_OFFSET = (int)uStack_2c;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0042d340 | Classified: CECGame::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0042d340(undefined4 param_1,byte param_2)

{
  FUN_0042d410();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0042d360 | Classified: ElementClient::proc_42d360 */
/* ==================================================================== */

void __fastcall FUN_0042d360(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008a7b50;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  if (param_1[1] != 0) {
    iVar1 = *(int *)(*param_1 + 4);
    while (iVar2 = iVar1, iVar2 != 0) {
      func_0x00431dc0(*(undefined4 *)(iVar2 + 0xc));
      iVar1 = *(int *)(iVar2 + 8);
      func_0x004323f0(0);
      if (iVar2 != 0) {
        func_0x00431b00(iVar2,0x24);
      }
    }
    *(int *)(*param_1 + 8) = *param_1;
    *(undefined4 *)(*param_1 + 4) = 0;
    *(int *)(*param_1 + 0xc) = *param_1;
    param_1[1] = 0;
  }
  uStack_4 = 1;
  if (*param_1 != 0) {
    func_0x008876b0(*param_1,0x24);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x0042d410 | Classified: ElementClient::proc_42d410 */
/* ==================================================================== */

void __fastcall FUN_0042d410(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar2;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008a7c33;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008d6b44;
  uStack_4 = 0xb;
  LeaveCriticalSection(param_1 + 0x8f);
  func_0x007637f0();
  param_1[0x139] = &UNK_008d6b4c;
  puStack_8._0_1_ = 10;
  param_1[0x13a] = &UNK_008d5a30;
  if (param_1[0x13b] != 0) {
    func_0x00763260(param_1[0x13b]);
    param_1[0x13b] = 0;
  }
  param_1[0x13d] = 0;
  param_1[0x13c] = 0;
  param_1[0x133] = &UNK_008d6b54;
  puStack_8._0_1_ = 9;
  param_1[0x134] = &UNK_008d5a30;
  if (param_1[0x135] != 0) {
    func_0x00763260(param_1[0x135]);
    param_1[0x135] = 0;
  }
  param_1[0x137] = 0;
  param_1[0x136] = 0;
  puVar1 = (undefined4 *)param_1[0x96];
  puStack_8._0_1_ = 8;
  param_1[0x95] = &UNK_008d6b5c;
  while (puVar1 != (undefined4 *)0x0) {
    param_1[0x96] = *puVar1;
    *puVar1 = param_1[0x98];
    param_1[0x98] = puVar1;
    puVar1 = (undefined4 *)param_1[0x96];
    param_1[0x99] = param_1[0x99] + -1;
  }
  puVar1 = (undefined4 *)param_1[0x9b];
  param_1[0x97] = 0;
  param_1[0x99] = 0;
  while (puVar1 != (undefined4 *)0x0) {
    param_1[0x9b] = puVar1[1];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    puVar1 = (undefined4 *)param_1[0x9b];
  }
  puStack_8._0_1_ = 0xc;
  func_0x005b5b60();
  puStack_8 = (undefined *)CONCAT31(puStack_8._1_3_,7);
  func_0x006e04e0(param_1[0x8a],param_1[0x8a] + param_1[0x8d] * 4);
  if (param_1[0x8a] != 0) {
    func_0x00763260(param_1[0x8a]);
  }
  func_0x00431860();
  uVar2 = 1;
  func_0x006b06b0(param_1[0x61]);
  func_0x005b5b60();
  func_0x006e04e0(param_1[0x5d],param_1[0x5d] + param_1[0x60] * 4);
  if (param_1[0x5d] != 0) {
    func_0x00763260(param_1[0x5d]);
  }
  func_0x005b5b60();
  func_0x006e04e0(param_1[0x57],param_1[0x57] + param_1[0x5a] * 4);
  if (param_1[0x57] != 0) {
    func_0x00763260(param_1[0x57]);
  }
  func_0x00419370();
  func_0x00419370();
  func_0x00419370();
  func_0x00419370();
  func_0x00419370();
  *unaff_FS_OFFSET = uVar2;
  return;
}


/* ==================================================================== */
/* Address: 0x0042d700 | Classified: elementclient::Build_version__d@0x42d700 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0042d700(int param_1,undefined4 *param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *unaff_FS_OFFSET;
  undefined1 uStack_64;
  undefined1 uStack_63;
  undefined1 uStack_62;
  undefined1 uStack_61;
  undefined1 uStack_60;
  undefined1 uStack_5f;
  undefined1 uStack_5e;
  undefined1 uStack_5d;
  undefined1 uStack_5c;
  undefined1 uStack_5b;
  undefined1 uStack_5a;
  undefined1 uStack_59;
  undefined1 uStack_58;
  undefined1 uStack_57;
  undefined1 uStack_56;
  undefined1 uStack_55;
  undefined1 uStack_54;
  undefined1 uStack_53;
  undefined1 uStack_52;
  undefined1 uStack_51;
  undefined1 uStack_50;
  undefined1 uStack_4f;
  undefined1 uStack_4e;
  undefined1 uStack_4d;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_4a;
  undefined1 uStack_49;
  int *piStack_48;
  int iStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  int iStack_1c;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  iStack_38 = _DAT_00951a7c;
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a7d37;
  *unaff_FS_OFFSET = (int)&iStack_c;
  uStack_3c = 0x951ef0;
  iStack_40 = 1;
  iStack_44 = 0x42d730;
  func_0x00764590();
  iStack_38 = 0x42d739;
  _DAT_009b3ee8 = GetCurrentThreadId();
  iStack_38 = 0x42d743;
  FUN_0042e300();
  iStack_38 = 0x42d748;
  FUN_0042e310();
  iStack_38 = 0x42d74e;
  iVar3 = _GetVersion_ElementSkill_GNET__SAHXZ();
  if (iVar3 == 0xf) {
    puVar5 = (undefined4 *)(param_1 + 0x270);
    for (iVar3 = 0x87; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *param_2;
      param_2 = param_2 + 1;
      puVar5 = puVar5 + 1;
    }
    iStack_38 = 0x42d788;
    func_0x00764c80();
    *(undefined4 *)(param_1 + 0x18) = 0x9b4d48;
    iStack_38 = 0x42d796;
    cVar2 = FUN_0042fe30();
    if (cVar2 == '\0') {
      iStack_38 = 0x15d;
      uStack_3c = 0x951eb0;
      iStack_40 = 4;
      iStack_44 = 0x42d7ab;
      func_0x0043c590();
    }
    else {
      iStack_38 = 0x42d7ba;
      cVar2 = FUN_0042ec80();
      if (cVar2 == '\0') {
        iStack_38 = 0x951e88;
        uStack_3c = 1;
        iStack_40 = 0x42d7ca;
        func_0x00764590();
      }
      iStack_38 = 0x248;
      uStack_3c = 0x42d7d7;
      iVar3 = func_0x00763250();
      uStack_4 = 0;
      if (iVar3 == 0) {
        uVar4 = 0;
      }
      else {
        iStack_38 = 0x42d7ef;
        uVar4 = func_0x006e69e0();
      }
      iStack_38 = *(int *)(param_1 + 8);
      uStack_4 = 0xffffffff;
      *(undefined4 *)(param_1 + 0x28) = uVar4;
      uStack_3c = 0x42d808;
      cVar2 = func_0x006e7050();
      if (cVar2 == '\0') {
        uStack_3c = 0x169;
        iStack_40 = 0x951eb0;
        iStack_44 = 4;
        piStack_48 = (int *)0x42d81d;
        func_0x0043c590();
      }
      else {
        uStack_3c = 0x7c;
        iStack_40 = 0x42d82c;
        iVar3 = func_0x00763250();
        puStack_8 = (undefined *)0x1;
        if (iVar3 == 0) {
          uVar4 = 0;
        }
        else {
          uStack_3c = 0x42d846;
          uVar4 = FUN_007a8850();
        }
        iStack_44 = *(int *)(param_1 + 4);
        uStack_3c = 120000;
        iStack_40 = 60000;
        puStack_8 = (undefined *)0xffffffff;
        *(undefined4 *)(param_1 + 0x238) = uVar4;
        piStack_48 = (int *)0x42d869;
        cVar2 = FUN_007a8b00();
        if (cVar2 == '\0') {
          piStack_48 = (int *)0x951e5c;
LAB_0042e2d2:
          uStack_4c = 1;
          uStack_4b = 0;
          uStack_4a = 0;
          uStack_49 = 0;
          uStack_50 = 0xd9;
          uStack_4f = 0xe2;
          uStack_4e = 0x42;
          uStack_4d = 0;
          func_0x00764590();
        }
        else {
          piStack_48 = (int *)0x6c;
          uStack_4c = 0x7e;
          uStack_4b = 0xd8;
          uStack_4a = 0x42;
          uStack_49 = 0;
          iVar3 = func_0x00763250();
          iStack_c = iVar3;
          if (iVar3 == 0) {
            iVar3 = 0;
          }
          else {
            piStack_48 = (int *)0x64;
            uStack_4c = 0x9c;
            uStack_4b = 0xd8;
            uStack_4a = 0x42;
            uStack_49 = 0;
            func_0x00431910();
            uStack_4c = 10;
            uStack_4b = 0;
            uStack_4a = 0;
            uStack_49 = 0;
            uStack_50 = 0xab;
            uStack_4f = 0xd8;
            uStack_4e = 0x42;
            uStack_4d = 0;
            func_0x00431c00();
            *(undefined **)(iVar3 + 0x18) = &UNK_008d6b64;
            *(undefined4 *)(iVar3 + 0x40) = 0;
            *(undefined4 *)(iVar3 + 0x44) = 0;
            *(undefined4 *)(iVar3 + 0x38) = 0;
            *(undefined4 *)(iVar3 + 0x3c) = 0;
            uStack_50 = 0;
            uStack_4f = 1;
            uStack_4e = 0;
            uStack_4d = 0;
            iStack_1c = CONCAT31(iStack_1c._1_3_,5);
            uStack_54 = 0xd2;
            uStack_53 = 0xd8;
            uStack_52 = 0x42;
            uStack_51 = 0;
            func_0x00431990();
            *(undefined1 *)(iVar3 + 0x60) = 0;
            *(undefined4 *)(iVar3 + 100) = 0;
            *(undefined4 *)(iVar3 + 0x68) = _DAT_00985a98;
            uStack_54 = 0;
            uStack_53 = 1;
            uStack_52 = 0;
            uStack_51 = 0;
            uStack_58 = 0xf1;
            uStack_57 = 0xd8;
            uStack_56 = 0x42;
            uStack_55 = 0;
            func_0x00431770();
          }
          piStack_48 = (int *)0x54;
          *(int *)(param_1 + 0x218) = iVar3;
          uStack_4c = 9;
          uStack_4b = 0xd9;
          uStack_4a = 0x42;
          uStack_49 = 0;
          iVar3 = func_0x00763250();
          if (iVar3 == 0) {
            iVar3 = 0;
          }
          else {
            piStack_48 = &iStack_c;
            *(undefined4 *)(iVar3 + 4) = 0;
            uStack_4c = 100;
            uStack_4b = 0;
            uStack_4a = 0;
            uStack_49 = 0;
            iStack_c = 0;
            uStack_50 = 0x31;
            uStack_4f = 0xd9;
            uStack_4e = 0x42;
            uStack_4d = 0;
            uVar4 = func_0x00404700();
            uStack_4c = (undefined1)uVar4;
            uStack_4b = (undefined1)((uint)uVar4 >> 8);
            uStack_4a = (undefined1)((uint)uVar4 >> 0x10);
            uStack_49 = (undefined1)((uint)uVar4 >> 0x18);
            uStack_50 = 0x3d;
            uStack_4f = 0xd9;
            uStack_4e = 0x42;
            uStack_4d = 0;
            func_0x005b0ea0();
            iStack_1c = CONCAT31(iStack_1c._1_3_,9);
            uStack_50 = 0x4a;
            uStack_4f = 0xd9;
            uStack_4e = 0x42;
            uStack_4d = 0;
            func_0x0085fb90();
            iVar1 = iVar3 + 0x3c;
            *(undefined1 *)(iVar3 + 0x38) = 0;
            uStack_50 = (undefined1)iVar1;
            uStack_4f = (undefined1)((uint)iVar1 >> 8);
            uStack_4e = (undefined1)((uint)iVar1 >> 0x10);
            uStack_4d = (undefined1)((uint)iVar1 >> 0x18);
            uStack_54 = 0x57;
            uStack_53 = 0xd9;
            uStack_52 = 0x42;
            uStack_51 = 0;
            InitializeCriticalSection();
          }
          *(int *)(param_1 + 0x2c) = iVar3;
          piStack_48 = (int *)0xc0;
          *(undefined4 *)(param_1 + 0x204) =
               *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 0x88) + 0x10);
          uStack_4c = 0x7e;
          uStack_4b = 0xd9;
          uStack_4a = 0x42;
          uStack_49 = 0;
          iStack_c = func_0x00763250();
          if (iStack_c == 0) {
            uVar4 = 0;
          }
          else {
            piStack_48 = (int *)0x42d998;
            uVar4 = FUN_007a4c20();
          }
          piStack_48 = *(int **)(param_1 + 4);
          *(undefined4 *)(param_1 + 0x208) = uVar4;
          uStack_4c = 0xb1;
          uStack_4b = 0xd9;
          uStack_4a = 0x42;
          uStack_49 = 0;
          FUN_007a4e70();
          uStack_4c = 0x5c;
          uStack_4b = 0;
          uStack_4a = 0;
          uStack_49 = 0;
          uStack_50 = 0xb8;
          uStack_4f = 0xd9;
          uStack_4e = 0x42;
          uStack_4d = 0;
          iVar3 = func_0x00763250();
          if (iVar3 == 0) {
            iVar3 = 0;
          }
          else {
            uStack_4c = 0xd2;
            uStack_4b = 0xd9;
            uStack_4a = 0x42;
            uStack_49 = 0;
            iVar3 = func_0x00418380();
          }
          *(int *)(param_1 + 0x210) = iVar3;
          if (iVar3 == 0) {
            uStack_4c = 0x81;
            uStack_4b = 1;
            uStack_4a = 0;
            uStack_49 = 0;
            uStack_50 = 0xb0;
            uStack_4f = 0x1e;
            uStack_4e = 0x95;
            uStack_4d = 0;
            uStack_54 = 2;
            uStack_53 = 0;
            uStack_52 = 0;
            uStack_51 = 0;
            uStack_58 = 0xf5;
            uStack_57 = 0xd9;
            uStack_56 = 0x42;
            uStack_55 = 0;
            func_0x0043c590();
          }
          else {
            *(undefined4 *)(iVar3 + 8) = 0xa00000;
            *(undefined4 *)(*(int *)(param_1 + 0x210) + 4) = 0x64000;
            uVar4 = *(undefined4 *)(param_1 + 0x210);
            uStack_4c = 0x1e;
            uStack_4b = 0xda;
            uStack_4a = 0x42;
            uStack_49 = 0;
            iVar3 = func_0x00430890();
            *(undefined4 *)(iVar3 + 0xc) = uVar4;
            uStack_4c = 0x28;
            uStack_4b = 0xda;
            uStack_4a = 0x42;
            uStack_49 = 0;
            cVar2 = FUN_0042eab0();
            if (cVar2 == '\0') {
              uStack_4c = 0x8c;
              uStack_4b = 1;
              uStack_4a = 0;
              uStack_49 = 0;
              uStack_50 = 0xb0;
              uStack_4f = 0x1e;
              uStack_4e = 0x95;
              uStack_4d = 0;
              uStack_54 = 4;
              uStack_53 = 0;
              uStack_52 = 0;
              uStack_51 = 0;
              uStack_58 = 0x3d;
              uStack_57 = 0xda;
              uStack_56 = 0x42;
              uStack_55 = 0;
              func_0x0043c590();
            }
            else {
              uStack_4c = 0x54;
              uStack_4b = 0;
              uStack_4a = 0;
              uStack_49 = 0;
              uStack_50 = 0x4c;
              uStack_4f = 0xda;
              uStack_4e = 0x42;
              uStack_4d = 0;
              iVar3 = func_0x00763250();
              if (iVar3 == 0) {
                iVar3 = 0;
              }
              else {
                uStack_4c = 0x66;
                uStack_4b = 0xda;
                uStack_4a = 0x42;
                uStack_49 = 0;
                iVar3 = func_0x00416570();
              }
              *(int *)(param_1 + 0x30) = iVar3;
              if (iVar3 == 0) {
                uStack_4c = 0x93;
                uStack_4b = 1;
                uStack_4a = 0;
                uStack_49 = 0;
                uStack_50 = 0xb0;
                uStack_4f = 0x1e;
                uStack_4e = 0x95;
                uStack_4d = 0;
                uStack_54 = 2;
                uStack_53 = 0;
                uStack_52 = 0;
                uStack_51 = 0;
                uStack_58 = 0x86;
                uStack_57 = 0xda;
                uStack_56 = 0x42;
                uStack_55 = 0;
                func_0x0043c590();
              }
              else {
                uStack_4c = 0;
                uStack_4b = 2;
                uStack_4a = 0;
                uStack_49 = 0;
                uStack_50 = 0x9a;
                uStack_4f = 0xda;
                uStack_4e = 0x42;
                uStack_4d = 0;
                cVar2 = func_0x00416910();
                if (cVar2 == '\0') {
                  uStack_50 = 0x28;
                  uStack_4f = 0x1e;
                  uStack_4e = 0x95;
                  uStack_4d = 0;
                  uStack_54 = 1;
                  uStack_53 = 0;
                  uStack_52 = 0;
                  uStack_51 = 0;
                  uStack_58 = 0xaa;
                  uStack_57 = 0xda;
                  uStack_56 = 0x42;
                  uStack_55 = 0;
                  func_0x00764590();
                  uStack_50 = 0xb5;
                  uStack_4f = 0xda;
                  uStack_4e = 0x42;
                  uStack_4d = 0;
                  func_0x00416940();
                }
                uStack_50 = 0x24;
                uStack_4f = 0;
                uStack_4e = 0;
                uStack_4d = 0;
                uStack_54 = 0xbc;
                uStack_53 = 0xda;
                uStack_52 = 0x42;
                uStack_51 = 0;
                iVar3 = func_0x00763250();
                if (iVar3 == 0) {
                  iVar3 = 0;
                }
                else {
                  uStack_50 = 0xd6;
                  uStack_4f = 0xda;
                  uStack_4e = 0x42;
                  uStack_4d = 0;
                  iVar3 = func_0x00415990();
                }
                iStack_1c = -1;
                *(int *)(param_1 + 0x34) = iVar3;
                if (iVar3 == 0) {
                  uStack_50 = 0xa0;
                  uStack_4f = 1;
                  uStack_4e = 0;
                  uStack_4d = 0;
                  uStack_54 = 0xb0;
                  uStack_53 = 0x1e;
                  uStack_52 = 0x95;
                  uStack_51 = 0;
                  uStack_58 = 2;
                  uStack_57 = 0;
                  uStack_56 = 0;
                  uStack_55 = 0;
                  uStack_5c = 0xf6;
                  uStack_5b = 0xda;
                  uStack_5a = 0x42;
                  uStack_59 = 0;
                  func_0x0043c590();
                }
                else {
                  uStack_50 = 0x40;
                  uStack_4f = 0;
                  uStack_4e = 0;
                  uStack_4d = 0;
                  uStack_54 = 7;
                  uStack_53 = 0xdb;
                  uStack_52 = 0x42;
                  uStack_51 = 0;
                  cVar2 = func_0x00415a40();
                  if (cVar2 == '\0') {
                    piStack_48 = (int *)0x951df0;
                    goto LAB_0042e2d2;
                  }
                  piStack_48 = (int *)0x38;
                  uStack_4c = 0x1c;
                  uStack_4b = 0xdb;
                  uStack_4a = 0x42;
                  uStack_49 = 0;
                  iStack_c = func_0x00763250();
                  if (iStack_c == 0) {
                    iVar3 = 0;
                  }
                  else {
                    piStack_48 = (int *)0x42db36;
                    iVar3 = func_0x00415cc0();
                  }
                  *(int *)(param_1 + 0x24) = iVar3;
                  if (iVar3 == 0) {
                    piStack_48 = (int *)0x1ad;
                    uStack_4c = 0xb0;
                    uStack_4b = 0x1e;
                    uStack_4a = 0x95;
                    uStack_49 = 0;
                    uStack_50 = 2;
                    uStack_4f = 0;
                    uStack_4e = 0;
                    uStack_4d = 0;
                    uStack_54 = 0x56;
                    uStack_53 = 0xdb;
                    uStack_52 = 0x42;
                    uStack_51 = 0;
                    func_0x0043c590();
                  }
                  else {
                    piStack_48 = (int *)0xd;
                    uStack_4c = 0x67;
                    uStack_4b = 0xdb;
                    uStack_4a = 0x42;
                    uStack_49 = 0;
                    cVar2 = func_0x00415da0();
                    if (cVar2 == '\0') {
                      uStack_4c = 0xb3;
                      uStack_4b = 1;
                      uStack_4a = 0;
                      uStack_49 = 0;
                      uStack_50 = 0xb0;
                      uStack_4f = 0x1e;
                      uStack_4e = 0x95;
                      uStack_4d = 0;
                      uStack_54 = 4;
                      uStack_53 = 0;
                      uStack_52 = 0;
                      uStack_51 = 0;
                      uStack_58 = 0x7c;
                      uStack_57 = 0xdb;
                      uStack_56 = 0x42;
                      uStack_55 = 0;
                      func_0x0043c590();
                    }
                    else {
                      uStack_4c = 100;
                      uStack_4b = 0;
                      uStack_4a = 0;
                      uStack_49 = 0;
                      uStack_50 = 0x8b;
                      uStack_4f = 0xdb;
                      uStack_4e = 0x42;
                      uStack_4d = 0;
                      iVar3 = func_0x00763250();
                      if (iVar3 == 0) {
                        iVar3 = 0;
                      }
                      else {
                        uVar4 = *(undefined4 *)(param_1 + 0x28);
                        uStack_4c = (undefined1)uVar4;
                        uStack_4b = (undefined1)((uint)uVar4 >> 8);
                        uStack_4a = (undefined1)((uint)uVar4 >> 0x10);
                        uStack_49 = (undefined1)((uint)uVar4 >> 0x18);
                        uStack_50 = 0xa9;
                        uStack_4f = 0xdb;
                        uStack_4e = 0x42;
                        uStack_4d = 0;
                        iVar3 = func_0x00411520();
                      }
                      *(int *)(param_1 + 0x38) = iVar3;
                      if (iVar3 == 0) {
                        uStack_4c = 0xba;
                        uStack_4b = 1;
                        uStack_4a = 0;
                        uStack_49 = 0;
                        uStack_50 = 0xb0;
                        uStack_4f = 0x1e;
                        uStack_4e = 0x95;
                        uStack_4d = 0;
                        uStack_54 = 2;
                        uStack_53 = 0;
                        uStack_52 = 0;
                        uStack_51 = 0;
                        uStack_58 = 0xc9;
                        uStack_57 = 0xdb;
                        uStack_56 = 0x42;
                        uStack_55 = 0;
                        func_0x0043c590();
                      }
                      else {
                        uStack_4c = 0xec;
                        uStack_4b = 0;
                        uStack_4a = 0;
                        uStack_49 = 0;
                        uStack_50 = 0xdb;
                        uStack_4f = 0xdb;
                        uStack_4e = 0x42;
                        uStack_4d = 0;
                        iVar3 = func_0x00763250();
                        if (iVar3 == 0) {
                          iVar3 = 0;
                        }
                        else {
                          uStack_4c = 0xf5;
                          uStack_4b = 0xdb;
                          uStack_4a = 0x42;
                          uStack_49 = 0;
                          iVar3 = func_0x00433b70();
                        }
                        *(int *)(param_1 + 0x1c) = iVar3;
                        if (iVar3 == 0) {
                          uStack_4c = 0xc1;
                          uStack_4b = 1;
                          uStack_4a = 0;
                          uStack_49 = 0;
                          uStack_50 = 0xb0;
                          uStack_4f = 0x1e;
                          uStack_4e = 0x95;
                          uStack_4d = 0;
                          uStack_54 = 2;
                          uStack_53 = 0;
                          uStack_52 = 0;
                          uStack_51 = 0;
                          uStack_58 = 0x15;
                          uStack_57 = 0xdc;
                          uStack_56 = 0x42;
                          uStack_55 = 0;
                          func_0x0043c590();
                        }
                        else {
                          uStack_4c = 0x24;
                          uStack_4b = 0xdc;
                          uStack_4a = 0x42;
                          uStack_49 = 0;
                          cVar2 = FUN_00433f80();
                          if (cVar2 == '\0') {
                            uStack_4c = 199;
                            uStack_4b = 1;
                            uStack_4a = 0;
                            uStack_49 = 0;
                            uStack_50 = 0xb0;
                            uStack_4f = 0x1e;
                            uStack_4e = 0x95;
                            uStack_4d = 0;
                            uStack_54 = 4;
                            uStack_53 = 0;
                            uStack_52 = 0;
                            uStack_51 = 0;
                            uStack_58 = 0x39;
                            uStack_57 = 0xdc;
                            uStack_56 = 0x42;
                            uStack_55 = 0;
                            func_0x0043c590();
                          }
                          else {
                            uStack_4c = 0x90;
                            uStack_4b = 1;
                            uStack_4a = 0;
                            uStack_49 = 0;
                            uStack_50 = 0x4b;
                            uStack_4f = 0xdc;
                            uStack_4e = 0x42;
                            uStack_4d = 0;
                            iVar3 = func_0x00763250();
                            if (iVar3 == 0) {
                              iVar3 = 0;
                            }
                            else {
                              uStack_4c = 0x65;
                              uStack_4b = 0xdc;
                              uStack_4a = 0x42;
                              uStack_49 = 0;
                              iVar3 = func_0x005cef00();
                            }
                            *(int *)(param_1 + 0x20) = iVar3;
                            if (iVar3 == 0) {
                              uStack_4c = 0xce;
                              uStack_4b = 1;
                              uStack_4a = 0;
                              uStack_49 = 0;
                              uStack_50 = 0xb0;
                              uStack_4f = 0x1e;
                              uStack_4e = 0x95;
                              uStack_4d = 0;
                              uStack_54 = 2;
                              uStack_53 = 0;
                              uStack_52 = 0;
                              uStack_51 = 0;
                              uStack_58 = 0x85;
                              uStack_57 = 0xdc;
                              uStack_56 = 0x42;
                              uStack_55 = 0;
                              func_0x0043c590();
                            }
                            else {
                              uStack_4c = 1;
                              uStack_4b = 0;
                              uStack_4a = 0;
                              uStack_49 = 0;
                              uStack_50 = 0xd8;
                              uStack_4f = 0x1d;
                              uStack_4e = 0x95;
                              uStack_4d = 0;
                              uStack_54 = 0x9c;
                              uStack_53 = 0xdc;
                              uStack_52 = 0x42;
                              uStack_51 = 0;
                              cVar2 = func_0x004194b0();
                              if (cVar2 == '\0') {
                                uStack_54 = 0xd4;
                                uStack_53 = 1;
                                uStack_52 = 0;
                                uStack_51 = 0;
                                uStack_58 = 0xb0;
                                uStack_57 = 0x1e;
                                uStack_56 = 0x95;
                                uStack_55 = 0;
                                uStack_5c = 4;
                                uStack_5b = 0;
                                uStack_5a = 0;
                                uStack_59 = 0;
                                uStack_60 = 0xb1;
                                uStack_5f = 0xdc;
                                uStack_5e = 0x42;
                                uStack_5d = 0;
                                func_0x0043c590();
                              }
                              uStack_54 = 1;
                              uStack_53 = 0;
                              uStack_52 = 0;
                              uStack_51 = 0;
                              uStack_58 = 0xc0;
                              uStack_57 = 0x1d;
                              uStack_56 = 0x95;
                              uStack_55 = 0;
                              uStack_5c = 0xc3;
                              uStack_5b = 0xdc;
                              uStack_5a = 0x42;
                              uStack_59 = 0;
                              cVar2 = func_0x004194b0();
                              if (cVar2 == '\0') {
                                uStack_5c = 0xd8;
                                uStack_5b = 1;
                                uStack_5a = 0;
                                uStack_59 = 0;
                                uStack_60 = 0xb0;
                                uStack_5f = 0x1e;
                                uStack_5e = 0x95;
                                uStack_5d = 0;
                                uStack_64 = 4;
                                uStack_63 = 0;
                                uStack_62 = 0;
                                uStack_61 = 0;
                                func_0x0043c590();
                              }
                              uStack_5c = 1;
                              uStack_5b = 0;
                              uStack_5a = 0;
                              uStack_59 = 0;
                              uStack_60 = 0xa4;
                              uStack_5f = 0x1d;
                              uStack_5e = 0x95;
                              uStack_5d = 0;
                              uStack_64 = 0xed;
                              uStack_63 = 0xdc;
                              uStack_62 = 0x42;
                              uStack_61 = 0;
                              cVar2 = func_0x004194b0();
                              if (cVar2 == '\0') {
                                uStack_64 = 0xdc;
                                uStack_63 = 1;
                                uStack_62 = 0;
                                uStack_61 = 0;
                                func_0x0043c590(4,0x951eb0);
                              }
                              uStack_64 = 1;
                              uStack_63 = 0;
                              uStack_62 = 0;
                              uStack_61 = 0;
                              cVar2 = func_0x004194b0(0x951d8c);
                              if (cVar2 == '\0') {
                                func_0x0043c590(4,0x951eb0,0x1e0);
                              }
                              cVar2 = func_0x004194b0(0x951d74,1);
                              if (cVar2 == '\0') {
                                func_0x0043c590(4,0x951eb0,0x1e4);
                              }
                              cVar2 = func_0x00430920();
                              if (cVar2 == '\0') {
                                func_0x0043c590(4,0x951eb0,0x1e8);
                              }
                              cVar2 = func_0x00430c90();
                              if (cVar2 == '\0') {
                                func_0x0043c590(4,0x951eb0,0x1ec);
                              }
                              cVar2 = func_0x00431070();
                              if (cVar2 == '\0') {
                                func_0x0043c590(4,0x951eb0,0x1f0);
                              }
                              cVar2 = func_0x0043c5e0(0x951d60,&uStack_5c);
                              if (cVar2 == '\0') {
                                func_0x00764590(1,0x951d3c);
                              }
                              else {
                                func_0x00764590(1,0x951ce4,uStack_5c,uStack_5b,uStack_5a,uStack_59,
                                                uStack_58,uStack_57,uStack_56,uStack_55,uStack_54,
                                                uStack_53,uStack_52,uStack_51,uStack_50,uStack_4f,
                                                uStack_4e,uStack_4d);
                              }
                              iStack_38 = func_0x00763250(0x3c);
                              iStack_40 = 0x12;
                              if (iStack_38 == 0) {
                                uVar4 = 0;
                              }
                              else {
                                uVar4 = func_0x00677440();
                              }
                              iStack_40 = 0xffffffff;
                              *(undefined4 *)(param_1 + 500) = uVar4;
                              iVar3 = func_0x006776a0(0x951d60,0);
                              if (iVar3 == 0) {
                                *(undefined4 *)(param_1 + 0x1f8) = **(undefined4 **)(param_1 + 500);
                                cVar2 = func_0x00673d50();
                                if (cVar2 == '\0') {
                                  func_0x0043c590(4,0x951eb0,0x205);
                                }
                                else {
                                  cVar2 = func_0x0043c5e0(0x951c78,&uStack_64);
                                  if (cVar2 == '\0') {
                                    func_0x00764590(1,0x951c58);
                                  }
                                  else {
                                    func_0x00764590(1,0x951c00,uStack_64,uStack_63,uStack_62,
                                                    uStack_61,uStack_60,uStack_5f,uStack_5e,
                                                    uStack_5d,uStack_5c,uStack_5b,uStack_5a,
                                                    uStack_59,uStack_58,uStack_57,uStack_56,
                                                    uStack_55);
                                  }
                                  iStack_40 = func_0x00763250(0x2f8);
                                  piStack_48 = (int *)0x13;
                                  if (iStack_40 == 0) {
                                    iVar3 = 0;
                                  }
                                  else {
                                    iVar3 = func_0x006885b0();
                                  }
                                  piStack_48 = (int *)0xffffffff;
                                  *(int *)(param_1 + 0x1fc) = iVar3;
                                  if (iVar3 == 0) {
                                    func_0x0043c590(2,0x951eb0,0x211);
                                  }
                                  else {
                                    FUN_0074c2a0(*(undefined4 *)(param_1 + 0x1f8));
                                    iStack_44 = func_0x00763250(0x25c);
                                    uStack_4c = 0x14;
                                    uStack_4b = 0;
                                    uStack_4a = 0;
                                    uStack_49 = 0;
                                    if (iStack_44 == 0) {
                                      iVar3 = 0;
                                    }
                                    else {
                                      iVar3 = func_0x004133d0();
                                    }
                                    uStack_4c = 0xff;
                                    uStack_4b = 0xff;
                                    uStack_4a = 0xff;
                                    uStack_49 = 0xff;
                                    *(int *)(param_1 + 0x200) = iVar3;
                                    if (iVar3 != 0) {
                                      func_0x00413490();
                                      iStack_c = func_0x00763250(0x34);
                                      if (iStack_c == 0) {
                                        iVar3 = 0;
                                      }
                                      else {
                                        piStack_48 = (int *)0x42e0ee;
                                        iVar3 = func_0x00405810();
                                      }
                                      *(int *)(param_1 + 0x21c) = iVar3;
                                      if (iVar3 != 0) {
                                        piStack_48 = (int *)0x951be4;
                                        uStack_4c = 0x10;
                                        uStack_4b = 0xe1;
                                        uStack_4a = 0x42;
                                        uStack_49 = 0;
                                        iVar3 = func_0x00405d00();
                                        if (iVar3 != 0) {
                                          piStack_48 = (int *)0x42e11f;
                                          func_0x00431260();
                                          piStack_48 = (int *)0x270;
                                          uStack_4c = 0x29;
                                          uStack_4b = 0xe1;
                                          uStack_4a = 0x42;
                                          uStack_49 = 0;
                                          iStack_c = func_0x00763250();
                                          if (iStack_c == 0) {
                                            uVar4 = 0;
                                          }
                                          else {
                                            piStack_48 = (int *)0x42e143;
                                            uVar4 = func_0x0064ca80();
                                          }
                                          *(undefined4 *)(param_1 + 0x20c) = uVar4;
                                          piStack_48 = (int *)0x2bf20;
                                          uVar4 = *(undefined4 *)
                                                   (*(int *)(_DAT_009b3eec + 4) + 0xa1c);
                                          uStack_4c = (undefined1)uVar4;
                                          uStack_4b = (undefined1)((uint)uVar4 >> 8);
                                          uStack_4a = (undefined1)((uint)uVar4 >> 0x10);
                                          uStack_49 = (undefined1)((uint)uVar4 >> 0x18);
                                          uStack_50 = 0x6d;
                                          uStack_4f = 0xe1;
                                          uStack_4e = 0x42;
                                          uStack_4d = 0;
                                          cVar2 = func_0x0064cbc0();
                                          if (cVar2 != '\0') {
                                            uStack_50 = *(undefined1 *)
                                                         (*(int *)(param_1 + 0x18) + 0xa0);
                                            uStack_4f = 0;
                                            uStack_4e = 0;
                                            uStack_4d = 0;
                                            uStack_54 = 0xca;
                                            uStack_53 = 0xe1;
                                            uStack_52 = 0x42;
                                            uStack_51 = 0;
                                            FUN_00767fe0();
                                            uStack_54 = *(undefined1 *)
                                                         (*(int *)(param_1 + 0x18) + 0xa1);
                                            uStack_53 = 0;
                                            uStack_52 = 0;
                                            uStack_51 = 0;
                                            uStack_58 = 0xe1;
                                            uStack_57 = 0xe1;
                                            uStack_56 = 0x42;
                                            uStack_55 = 0;
                                            func_0x0064d3d0();
                                            uStack_58 = *(undefined1 *)
                                                         (*(int *)(param_1 + 0x18) + 0xa0);
                                            uStack_57 = 0;
                                            uStack_56 = 0;
                                            uStack_55 = 0;
                                            uStack_5c = 0xf8;
                                            uStack_5b = 0xe1;
                                            uStack_5a = 0x42;
                                            uStack_59 = 0;
                                            func_0x0064d530();
                                            uStack_5c = *(undefined1 *)
                                                         (*(int *)(param_1 + 0x18) + 0xa0);
                                            uStack_5b = 0;
                                            uStack_5a = 0;
                                            uStack_59 = 0;
                                            uStack_60 = 0xf;
                                            uStack_5f = 0xe2;
                                            uStack_5e = 0x42;
                                            uStack_5d = 0;
                                            func_0x0064d760();
                                            uStack_60 = 0x14;
                                            uStack_5f = 0xe2;
                                            uStack_5e = 0x42;
                                            uStack_5d = 0;
                                            func_0x00471350();
                                            uStack_60 = 0x19;
                                            uStack_5f = 0xe2;
                                            uStack_5e = 0x42;
                                            uStack_5d = 0;
                                            func_0x00482060();
                                            uStack_60 = 0x1e;
                                            uStack_5f = 0xe2;
                                            uStack_5e = 0x42;
                                            uStack_5d = 0;
                                            uVar4 = func_0x00673d30();
                                            uStack_60 = (undefined1)uVar4;
                                            uStack_5f = (undefined1)((uint)uVar4 >> 8);
                                            uStack_5e = (undefined1)((uint)uVar4 >> 0x10);
                                            uStack_5d = (undefined1)((uint)uVar4 >> 0x18);
                                            uStack_64 = 0x24;
                                            uStack_63 = 0xe2;
                                            uStack_62 = 0x42;
                                            uStack_61 = 0;
                                            uVar4 = func_0x00673d00();
                                            uStack_64 = (undefined1)uVar4;
                                            uStack_63 = (undefined1)((uint)uVar4 >> 8);
                                            uStack_62 = (undefined1)((uint)uVar4 >> 0x10);
                                            uStack_61 = (undefined1)((uint)uVar4 >> 0x18);
                                            func_0x00763d30(param_1 + 0x4fc,0x951bd8,0x3000001b,
                                                            _DAT_00978974);
                                            uVar4 = *(undefined4 *)(param_1 + 0x270);
                                            *(undefined4 *)(param_1 + 0x500) = 0x98;
                                            *(undefined4 *)(param_1 + 0x504) =
                                                 *(undefined4 *)(param_1 + 0x274);
                                            *(undefined4 *)(param_1 + 0x508) = 0x65;
                                            uStack_60 = 0x65;
                                            uStack_5f = 0;
                                            uStack_5e = 0;
                                            uStack_5d = 0;
                                            uStack_64 = (undefined1)uVar4;
                                            uStack_63 = (undefined1)((uint)uVar4 >> 8);
                                            uStack_62 = (undefined1)((uint)uVar4 >> 0x10);
                                            uStack_61 = (undefined1)((uint)uVar4 >> 0x18);
                                            *(undefined4 *)(param_1 + 0x50c) = 7;
                                            *(undefined4 *)(param_1 + 0x510) = 0x466;
                                            uVar4 = (*_DAT_009b3ba8)();
                                            *(undefined4 *)(param_1 + 0x514) = uVar4;
                                            for (puVar5 = *(undefined4 **)
                                                           (*(int *)(param_1 + 0x60) +
                                                           (int)(0xde % (ulonglong)
                                                                        *(uint *)(param_1 + 0x6c)) *
                                                           4); puVar5 != (undefined4 *)0x0;
                                                puVar5 = (undefined4 *)*puVar5) {
                                              if (puVar5[2] == 0xde) {
                                                uVar4 = *(undefined4 *)puVar5[1];
                                                goto LAB_0042e2b1;
                                              }
                                            }
                                            uVar4 = 0;
LAB_0042e2b1:
                                            wcscpy(param_1 + 0x518,uVar4);
                                            uVar4 = 1;
                                            goto LAB_0042e2de;
                                          }
                                          iVar3 = *(int *)(param_1 + 0x20c);
                                          if (iVar3 != 0) {
                                            uStack_50 = 0x82;
                                            uStack_4f = 0xe1;
                                            uStack_4e = 0x42;
                                            uStack_4d = 0;
                                            func_0x0064cb00();
                                            uStack_50 = (undefined1)iVar3;
                                            uStack_4f = (undefined1)((uint)iVar3 >> 8);
                                            uStack_4e = (undefined1)((uint)iVar3 >> 0x10);
                                            uStack_4d = (undefined1)((uint)iVar3 >> 0x18);
                                            uStack_54 = 0x88;
                                            uStack_53 = 0xe1;
                                            uStack_52 = 0x42;
                                            uStack_51 = 0;
                                            func_0x00763260();
                                          }
                                          uStack_50 = 0x31;
                                          uStack_4f = 2;
                                          uStack_4e = 0;
                                          uStack_4d = 0;
                                          uStack_54 = 0xb0;
                                          uStack_53 = 0x1e;
                                          uStack_52 = 0x95;
                                          uStack_51 = 0;
                                          uStack_58 = 4;
                                          uStack_57 = 0;
                                          uStack_56 = 0;
                                          uStack_55 = 0;
                                          *(undefined4 *)(param_1 + 0x20c) = 0;
                                          uStack_5c = 0xa2;
                                          uStack_5b = 0xe1;
                                          uStack_5a = 0x42;
                                          uStack_59 = 0;
                                          func_0x0043c590();
                                          goto LAB_0042e2dc;
                                        }
                                      }
                                      piStack_48 = (int *)0x951ba0;
                                      goto LAB_0042e2d2;
                                    }
                                    func_0x0043c590(2,0x951eb0,0x21a);
                                  }
                                }
                              }
                              else {
                                MessageBoxA(0,0x951c88,0x951cdc,0x10);
                                func_0x0043c590(4,0x951eb0,0x1fe);
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
      }
    }
  }
  else {
    iStack_38 = 0x10;
    uStack_3c = 0x951ee8;
    iStack_40 = 0x951ec0;
    iStack_44 = param_2[1];
    piStack_48 = (int *)0x42d76d;
    MessageBoxA();
  }
LAB_0042e2dc:
  uVar4 = 0;
LAB_0042e2de:
  *unaff_FS_OFFSET = iStack_1c;
  return uVar4;
}


/* ==================================================================== */
/* Address: 0x0042e300 | Classified: ElementClient::proc_42e300 */
/* ==================================================================== */

void FUN_0042e300(void)

{
  return;
}


/* ==================================================================== */
/* Address: 0x0042e310 | Classified: elementclient::Kernel32_dll@0x42e310 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042e310(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0x951f10;
  uStack_10 = 0x42e31d;
  uVar1 = LoadLibraryA();
  uStack_10 = 0x951f04;
  _DAT_009b3f20 = (undefined4 *)(*_DAT_009b3b40)(uVar1);
  iVar2 = VirtualProtect(_DAT_009b3f20,0x10,0x40,&uStack_10);
  if (iVar2 != 0) {
    _DAT_009b3f28 = *_DAT_009b3f20;
    _DAT_009b3f2c = _DAT_009b3f20[1];
    _DAT_009b3f30 = CONCAT31((int3)(0x42d68b - (int)_DAT_009b3f20),0xe9);
    DAT_009b3f34_1 = (undefined3)((uint)_DAT_009b3f2c >> 8);
    DAT_009b3f34 = (undefined1)((uint)(0x42d68b - (int)_DAT_009b3f20) >> 0x18);
    *_DAT_009b3f20 = _DAT_009b3f30;
    _DAT_009b3f20[1] = _DAT_009b3f34;
  }
  FreeLibrary(uVar1);
  return;
}


/* ==================================================================== */
/* Address: 0x0042e3a0 | Classified: ElementClient::proc_42e3a0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0042e3a0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uStack_4;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    FUN_00434250();
    if (*(undefined4 **)(param_1 + 0x1c) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x1c))(1);
    }
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  func_0x004713a0();
  func_0x00482080();
  if (*(int *)(param_1 + 0x20c) != 0) {
    func_0x0064cda0();
    iVar1 = *(int *)(param_1 + 0x20c);
    if (iVar1 != 0) {
      func_0x0064cb00();
      func_0x00763260(iVar1);
    }
    *(undefined4 *)(param_1 + 0x20c) = 0;
  }
  func_0x00675b20();
  iVar1 = *(int *)(param_1 + 500);
  if (iVar1 != 0) {
    func_0x00677540();
    func_0x00763260(iVar1);
    *(undefined4 *)(param_1 + 500) = 0;
  }
  func_0x00419510();
  func_0x00419510();
  func_0x00419510();
  func_0x00419510();
  func_0x00419510();
  uVar4 = 0;
  if (*(int *)(param_1 + 0x168) != 0) {
    do {
      puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x15c) + uVar4 * 4);
      while (puVar3 != (undefined4 *)0x0) {
        puVar2 = (undefined4 *)*puVar3;
        func_0x00763260(puVar3);
        puVar3 = puVar2;
      }
      uVar4 = uVar4 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x15c) + -4 + uVar4 * 4) = 0;
    } while (uVar4 < *(uint *)(param_1 + 0x168));
  }
  *(undefined4 *)(param_1 + 0x158) = 0;
  uVar4 = 0;
  if (*(int *)(param_1 + 0x234) != 0) {
    do {
      puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x228) + uVar4 * 4);
      while (puVar3 != (undefined4 *)0x0) {
        puVar2 = (undefined4 *)*puVar3;
        func_0x00763260(puVar3);
        puVar3 = puVar2;
      }
      uVar4 = uVar4 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x228) + -4 + uVar4 * 4) = 0;
    } while (uVar4 < *(uint *)(param_1 + 0x234));
  }
  *(undefined4 *)(param_1 + 0x224) = 0;
  uVar4 = 0;
  if (*(int *)(param_1 + 0x180) != 0) {
    do {
      puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x174) + uVar4 * 4);
      while (puVar3 != (undefined4 *)0x0) {
        puVar2 = (undefined4 *)*puVar3;
        func_0x00763260(puVar3);
        puVar3 = puVar2;
      }
      uVar4 = uVar4 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x174) + -4 + uVar4 * 4) = 0;
    } while (uVar4 < *(uint *)(param_1 + 0x180));
  }
  *(undefined4 *)(param_1 + 0x170) = 0;
  if (*(int *)(param_1 + 0x20) != 0) {
    func_0x005cf710();
    if (*(undefined4 **)(param_1 + 0x20) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x20))(1);
    }
    *(undefined4 *)(param_1 + 0x20) = 0;
    Sleep(500);
  }
  iVar1 = *(int *)(param_1 + 0x21c);
  if (iVar1 != 0) {
    uStack_4 = 0;
    if (*(int *)(iVar1 + 0x18) != 0) {
      do {
        puVar3 = *(undefined4 **)(*(int *)(iVar1 + 0xc) + uStack_4 * 4);
        while (puVar3 != (undefined4 *)0x0) {
          puVar2 = (undefined4 *)*puVar3;
          func_0x00406530(0);
          func_0x00763260(puVar3);
          puVar3 = puVar2;
        }
        uStack_4 = uStack_4 + 1;
        *(undefined4 *)(*(int *)(iVar1 + 0xc) + -4 + uStack_4 * 4) = 0;
      } while (uStack_4 < *(uint *)(iVar1 + 0x18));
    }
    *(undefined4 *)(iVar1 + 8) = 0;
    uStack_4 = 0;
    if (*(int *)(iVar1 + 0x30) != 0) {
      do {
        puVar3 = *(undefined4 **)(*(int *)(iVar1 + 0x24) + uStack_4 * 4);
        while (puVar3 != (undefined4 *)0x0) {
          puVar2 = (undefined4 *)*puVar3;
          func_0x00739480(0);
          func_0x00763260(puVar3);
          puVar3 = puVar2;
        }
        uStack_4 = uStack_4 + 1;
        *(undefined4 *)(*(int *)(iVar1 + 0x24) + -4 + uStack_4 * 4) = 0;
      } while (uStack_4 < *(uint *)(iVar1 + 0x30));
    }
    *(undefined4 *)(iVar1 + 0x20) = 0;
    if (*(undefined4 **)(param_1 + 0x21c) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x21c))(1);
    }
    *(undefined4 *)(param_1 + 0x21c) = 0;
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    func_0x00415de0();
    if (*(undefined4 **)(param_1 + 0x24) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x24))(1);
    }
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    func_0x00416940();
    iVar1 = *(int *)(param_1 + 0x30);
    if (iVar1 != 0) {
      func_0x004165b0();
      func_0x00763260(iVar1);
    }
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  if (*(int *)(param_1 + 0x34) != 0) {
    func_0x00415b70();
    if (*(undefined4 **)(param_1 + 0x34) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x34))(1);
    }
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  if (*(int *)(param_1 + 0x1fc) != 0) {
    func_0x00689080();
    iVar1 = *(int *)(param_1 + 0x1fc);
    if (iVar1 != 0) {
      func_0x00688740();
      func_0x00763260(iVar1);
    }
    *(undefined4 *)(param_1 + 0x1fc) = 0;
  }
  if (*(int *)(param_1 + 0x200) != 0) {
    func_0x00413910();
    if (*(undefined4 **)(param_1 + 0x200) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x200))(1);
    }
    *(undefined4 *)(param_1 + 0x200) = 0;
  }
  if (*(int *)(param_1 + 0x214) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x214));
    *(undefined4 *)(param_1 + 0x214) = 0;
  }
  if (*(undefined4 **)(param_1 + 0x38) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x38))(1);
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x218);
  if (iVar1 != 0) {
    FUN_0042e920();
    func_0x00763260(iVar1);
    *(undefined4 *)(param_1 + 0x218) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x2c);
  if (iVar1 != 0) {
    FUN_0042e7f0();
    func_0x00763260(iVar1);
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  if (*(int *)(param_1 + 0x238) != 0) {
    FUN_007a8cb0();
    if (*(undefined4 **)(param_1 + 0x238) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x238))(1);
    }
    *(undefined4 *)(param_1 + 0x238) = 0;
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    func_0x006e8050();
    iVar1 = *(int *)(param_1 + 0x28);
    if (iVar1 != 0) {
      func_0x006e6dc0();
      func_0x00763260(iVar1);
    }
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  if (*(int *)(param_1 + 0x208) != 0) {
    FUN_007a4e90();
    if (*(undefined4 **)(param_1 + 0x208) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x208))(1);
    }
    *(undefined4 *)(param_1 + 0x208) = 0;
  }
  *(undefined4 *)(param_1 + 0x204) = 0;
  if (*(int *)(param_1 + 0x210) != 0) {
    func_0x004185b0();
    if (*(int **)(param_1 + 0x210) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x210) + 8))(1);
    }
    *(undefined4 *)(param_1 + 0x210) = 0;
  }
  FUN_0042ec10();
  FUN_0042f010();
  FUN_004302e0();
  *(undefined4 *)(param_1 + 0x18) = 0;
  _DAT_009b3eec = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x0042e7f0 | Classified: ElementClient::proc_42e7f0 */
/* ==================================================================== */

void __fastcall FUN_0042e7f0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 unaff_EBX;
  uint uVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008a7d79;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar5 = param_1 + 0x3c;
  uStack_4 = 1;
  EnterCriticalSection(iVar5);
  func_0x006e9e10();
  LeaveCriticalSection(iVar5);
  DeleteCriticalSection(iVar5);
  func_0x0085fbe0();
  uVar7 = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    do {
      puVar2 = *(undefined4 **)(*(int *)(param_1 + 8) + uVar7 * 4);
      while (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar2;
        func_0x007637f0();
        func_0x007637f0();
        func_0x00763260(puVar2);
        puVar2 = puVar1;
      }
      uVar7 = uVar7 + 1;
      *(undefined4 *)(*(int *)(param_1 + 8) + -4 + uVar7 * 4) = 0;
    } while (uVar7 < *(uint *)(param_1 + 0x14));
  }
  *(undefined4 *)(param_1 + 4) = 0;
  puVar1 = *(undefined4 **)(param_1 + 8);
  puVar2 = puVar1 + *(int *)(param_1 + 0x14);
  if (puVar1 != puVar2) {
    puVar3 = puVar2;
    puVar6 = puVar1;
    if (puVar2 < *(undefined4 **)(param_1 + 0xc)) {
      do {
        puVar4 = puVar3 + 1;
        *puVar6 = *puVar3;
        puVar3 = puVar4;
        puVar6 = puVar6 + 1;
      } while (puVar4 < *(undefined4 **)(param_1 + 0xc));
    }
    iVar5 = (int)puVar2 - (int)puVar1 >> 2;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + iVar5 * -4;
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - iVar5;
  }
  if (*(int *)(param_1 + 8) != 0) {
    func_0x00763260(*(int *)(param_1 + 8));
  }
  *unaff_FS_OFFSET = unaff_EBX;
  return;
}


/* ==================================================================== */
/* Address: 0x0042e920 | Classified: ElementClient::proc_42e920 */
/* ==================================================================== */

void __fastcall FUN_0042e920(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008a7dc4;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 4;
  func_0x00449c20(0);
  puStack_8._0_1_ = 3;
  FUN_00765200();
  uVar3 = 0;
  puStack_8 = (undefined *)CONCAT31(puStack_8._1_3_,2);
  if (*(int *)(param_1 + 0x5c) != 0) {
    do {
      puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x50) + uVar3 * 4);
      while (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar2;
        func_0x00763260(puVar2);
        puVar2 = puVar1;
      }
      uVar3 = uVar3 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x50) + -4 + uVar3 * 4) = 0;
    } while (uVar3 < *(uint *)(param_1 + 0x5c));
  }
  *(undefined4 *)(param_1 + 0x4c) = 0;
  func_0x005b5c40();
  if (*(int *)(param_1 + 0x50) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x50));
  }
  puStack_8 = (undefined *)CONCAT31(puStack_8._1_3_,1);
  func_0x006e04e0(*(int *)(param_1 + 0x38),*(int *)(param_1 + 0x38) + *(int *)(param_1 + 0x44) * 4);
  if (*(int *)(param_1 + 0x38) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x38));
  }
  *(undefined **)(param_1 + 0x18) = &UNK_008d6b64;
  puVar2 = *(undefined4 **)(param_1 + 0x20);
  *(undefined **)(param_1 + 0x1c) = &UNK_008d649c;
  while (puVar2 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x20) = *puVar2;
    *puVar2 = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 **)(param_1 + 0x28) = puVar2;
    puVar2 = *(undefined4 **)(param_1 + 0x20);
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + -1;
  }
  puVar2 = *(undefined4 **)(param_1 + 0x34);
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  while (puVar2 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x34) = puVar2[1];
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
    puVar2 = *(undefined4 **)(param_1 + 0x34);
  }
  uVar3 = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    do {
      puVar2 = *(undefined4 **)(*(int *)(param_1 + 8) + uVar3 * 4);
      while (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar2;
        func_0x00763260(puVar2);
        puVar2 = puVar1;
      }
      uVar3 = uVar3 + 1;
      *(undefined4 *)(*(int *)(param_1 + 8) + -4 + uVar3 * 4) = 0;
    } while (uVar3 < *(uint *)(param_1 + 0x14));
  }
  *(undefined4 *)(param_1 + 4) = 0;
  func_0x006e04e0(*(int *)(param_1 + 8),*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14) * 4);
  if (*(int *)(param_1 + 8) != 0) {
    func_0x00763260(*(int *)(param_1 + 8));
  }
  *unaff_FS_OFFSET = unaff_EDI;
  return;
}


/* ==================================================================== */
/* Address: 0x0042eab0 | Classified: elementclient::CECGame__LoadCursors__failed_to_c@0x42eab0 */
/* ==================================================================== */

undefined4 __fastcall FUN_0042eab0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 *puStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a7ddb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar6 = 0;
  do {
    iVar2 = func_0x00763250(8);
    uStack_4 = 0;
    if (iVar2 == 0) {
      puStack_10 = (undefined4 *)0x0;
    }
    else {
      puStack_10 = (undefined4 *)FUN_007a9cb0();
    }
    uStack_4 = 0xffffffff;
    uVar3 = func_0x00415c70(iVar6);
    cVar1 = FUN_007a9d10(*(undefined4 *)(param_1 + 8),uVar3);
    if (cVar1 == '\0') {
      uVar3 = func_0x00415c70(iVar6);
      func_0x00764590(1,0x951f20,uVar3);
      if (puStack_10 != (undefined4 *)0x0) {
        (**(code **)*puStack_10)(1);
      }
      puStack_10 = (undefined4 *)0x0;
    }
    if ((*(int *)(param_1 + 0x4dc) <= *(int *)(param_1 + 0x4d8)) && (*(int *)(param_1 + 0x4e0) != 0)
       ) {
      iVar5 = *(int *)(param_1 + 0x4e0) + *(int *)(param_1 + 0x4dc);
      iVar2 = func_0x00763250(iVar5 * 4);
      if (iVar2 == 0) {
        func_0x00764590(1,0x94e51c);
      }
      else {
        iVar4 = 0;
        if (0 < *(int *)(param_1 + 0x4d8)) {
          do {
            iVar4 = iVar4 + 1;
            *(undefined4 *)(iVar2 + -4 + iVar4 * 4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x4d4) + -4 + iVar4 * 4);
          } while (iVar4 < *(int *)(param_1 + 0x4d8));
        }
        if (*(int *)(param_1 + 0x4d4) != 0) {
          func_0x00763260(*(int *)(param_1 + 0x4d4));
        }
        *(int *)(param_1 + 0x4d4) = iVar2;
        *(int *)(param_1 + 0x4dc) = iVar5;
      }
    }
    iVar2 = *(int *)(param_1 + 0x4d8);
    *(undefined4 **)(*(int *)(param_1 + 0x4d4) + iVar2 * 4) = puStack_10;
    iVar6 = iVar6 + 1;
    *(int *)(param_1 + 0x4d8) = *(int *)(param_1 + 0x4d8) + 1;
  } while (iVar6 < 8);
  *unaff_FS_OFFSET = uStack_c;
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x0042ec10 | Classified: ElementClient::proc_42ec10 */
/* ==================================================================== */

void __fastcall FUN_0042ec10(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x4d8)) {
    do {
      puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x4d4) + iVar2 * 4);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x4d8));
  }
  if (*(int *)(param_1 + 0x4d4) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x4d4));
    *(undefined4 *)(param_1 + 0x4d4) = 0;
  }
  *(undefined4 *)(param_1 + 0x4dc) = 0;
  *(undefined4 *)(param_1 + 0x4d8) = 0;
  if (*(int *)(param_1 + 8) != 0) {
    func_0x0077b8c0(0);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0042ec80 | Classified: ElementClient::proc_42ec80 */
/* ==================================================================== */

/* WARNING: Removing unreachable block (ram,0x0042edf2) */

undefined4 FUN_0042ec80(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int extraout_ECX;
  undefined4 *unaff_FS_OFFSET;
  undefined4 in_stack_00001308;
  undefined4 in_stack_0000130c;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a7dfb;
  *unaff_FS_OFFSET = &uStack_c;
  func_0x00892f20();
  func_0x0076ded0();
  cVar2 = func_0x0076e030();
  if (cVar2 == '\0') {
    func_0x00431b30();
    iVar3 = 0;
    do {
      iVar3 = iVar3 + 4;
      *(undefined4 *)(*(int *)(extraout_ECX + 0x4ec) + -4 + iVar3) = 0;
    } while (iVar3 < 8);
    func_0x00764590();
    func_0x0076df10();
    *unaff_FS_OFFSET = in_stack_00001308;
    return 0;
  }
  uStack_c = *(undefined4 *)(*(int *)(extraout_ECX + 4) + 0x58);
  cVar2 = func_0x0076e120();
  do {
    if (cVar2 == '\0') {
LAB_0042efd0:
      func_0x0076e0f0();
      func_0x0076df10();
      *unaff_FS_OFFSET = in_stack_0000130c;
      return 1;
    }
    wcscpy();
    func_0x0076e120();
    _wtoi();
    func_0x0076e120();
    _wtoi();
    func_0x0076e120();
    _wtoi();
    func_0x0076e120();
    iVar3 = wcscmp();
    if (iVar3 == 0) {
      wcscpy();
      goto LAB_0042efd0;
    }
    iVar3 = func_0x0078d570();
    if (iVar3 == 0) {
      iVar3 = *(int *)(extraout_ECX + 0x4f4);
      if ((iVar3 <= *(int *)(extraout_ECX + 0x4f0)) &&
         (iVar1 = *(int *)(extraout_ECX + 0x4f8), iVar1 != 0)) {
        iVar4 = func_0x00763250();
        if (iVar4 == 0) {
          func_0x00764590();
        }
        else {
          iVar5 = 0;
          if (0 < *(int *)(extraout_ECX + 0x4f0)) {
            do {
              iVar5 = iVar5 + 1;
              *(undefined4 *)(iVar4 + -4 + iVar5 * 4) =
                   *(undefined4 *)(*(int *)(extraout_ECX + 0x4ec) + -4 + iVar5 * 4);
            } while (iVar5 < *(int *)(extraout_ECX + 0x4f0));
          }
          if (*(int *)(extraout_ECX + 0x4ec) != 0) {
            func_0x00763260();
          }
          *(int *)(extraout_ECX + 0x4ec) = iVar4;
          *(int *)(extraout_ECX + 0x4f4) = iVar1 + iVar3;
        }
      }
      *(undefined4 *)(*(int *)(extraout_ECX + 0x4ec) + *(int *)(extraout_ECX + 0x4f0) * 4) = 0;
    }
    else {
      uVar6 = func_0x0078d8b0();
      iVar3 = *(int *)(extraout_ECX + 0x4f4);
      if ((iVar3 <= *(int *)(extraout_ECX + 0x4f0)) &&
         (iVar1 = *(int *)(extraout_ECX + 0x4f8), iVar1 != 0)) {
        iVar4 = func_0x00763250();
        if (iVar4 == 0) {
          func_0x00764590();
        }
        else {
          iVar5 = 0;
          if (0 < *(int *)(extraout_ECX + 0x4f0)) {
            do {
              iVar5 = iVar5 + 1;
              *(undefined4 *)(iVar4 + -4 + iVar5 * 4) =
                   *(undefined4 *)(*(int *)(extraout_ECX + 0x4ec) + -4 + iVar5 * 4);
            } while (iVar5 < *(int *)(extraout_ECX + 0x4f0));
          }
          if (*(int *)(extraout_ECX + 0x4ec) != 0) {
            func_0x00763260();
          }
          *(int *)(extraout_ECX + 0x4ec) = iVar4;
          *(int *)(extraout_ECX + 0x4f4) = iVar1 + iVar3;
        }
      }
      *(undefined4 *)(*(int *)(extraout_ECX + 0x4ec) + *(int *)(extraout_ECX + 0x4f0) * 4) = uVar6;
    }
    *(int *)(extraout_ECX + 0x4f0) = *(int *)(extraout_ECX + 0x4f0) + 1;
    cVar2 = func_0x0076e120();
  } while( true );
}


/* ==================================================================== */
/* Address: 0x0042f010 | Classified: ElementClient::proc_42f010 */
/* ==================================================================== */

void __fastcall FUN_0042f010(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 0x4f0)) {
      do {
        iVar1 = *(int *)(*(int *)(param_1 + 0x4ec) + iVar2 * 4);
        if (iVar1 != 0) {
          func_0x0078da10(iVar1);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(param_1 + 0x4f0));
    }
    if (*(int *)(param_1 + 0x4ec) != 0) {
      func_0x00763260(*(int *)(param_1 + 0x4ec));
      *(undefined4 *)(param_1 + 0x4ec) = 0;
    }
    *(undefined4 *)(param_1 + 0x4f4) = 0;
    *(undefined4 *)(param_1 + 0x4f0) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0042f080 | Classified: ElementClient::proc_42f080 */
/* ==================================================================== */

int __thiscall FUN_0042f080(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x4ec) + param_2 * 4);
  if (iVar1 == 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 0xd8);
  }
  return iVar1;
}


/* ==================================================================== */
/* Address: 0x0042f0a0 | Classified: ElementClient::proc_42f0a0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0042f0a0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x21c) != 0) {
    uVar1 = FUN_0042f0c0(param_2);
    return uVar1;
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x0042f0c0 | Classified: ElementClient::proc_42f0c0 */
/* ==================================================================== */

/* WARNING: Removing unreachable block (ram,0x0042f144) */

undefined4 __thiscall FUN_0042f0c0(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  bool bVar4;
  int unaff_EBX;
  int iStack_c;
  
  iVar1 = param_1 + 0x1c;
  bVar4 = false;
  for (puVar3 = *(undefined4 **)
                 (*(int *)(param_1 + 0x24) + (param_2 % *(uint *)(param_1 + 0x30)) * 4);
      (puVar3 != (undefined4 *)0x0 && (puVar3[3] != param_2)); puVar3 = (undefined4 *)*puVar3) {
  }
  func_0x004046d0(puVar3,iVar1);
  if ((((unaff_EBX == 0) || (iVar1 == 0)) || (unaff_EBX == iVar1)) && (iStack_c == 0)) {
    puVar3 = (undefined4 *)func_0x007636b0(&DAT_009b3c44);
    bVar4 = true;
  }
  else {
    puVar3 = (undefined4 *)0x4;
  }
  uVar2 = *puVar3;
  if (bVar4) {
    func_0x007637f0();
  }
  return uVar2;
}


/* ==================================================================== */
/* Address: 0x0042f170 | Classified: ElementClient::proc_42f170 */
/* ==================================================================== */

int FUN_0042f170(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBX;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *unaff_FS_OFFSET;
  int *unaff_retaddr;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  undefined1 auStack_20 [4];
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008a7e3d;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  uVar4 = 0;
  uStack_4 = 0;
  func_0x004322d0(&iStack_1c,&stack0x00000004);
  iVar1 = func_0x004324c0(&iStack_24,auStack_20,&stack0xffffffc7);
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      iStack_2c = func_0x00432390(&uStack_4);
      iStack_2c = iStack_2c + 0x14;
      if (unaff_retaddr[3] == unaff_retaddr[2]) {
        iVar3 = func_0x00432340(unaff_retaddr[3] + 1,&stack0xffffffc8);
        iVar5 = *unaff_retaddr;
        iVar7 = iVar3;
        if (unaff_retaddr[3] != 0) {
          do {
            iStack_c._0_1_ = 1;
            iVar6 = iVar5;
            iStack_28 = iVar7;
            iStack_24 = iVar7;
            if (iVar7 != 0) {
              iVar6 = iVar5 + 0x10;
              func_0x00432290(iVar5);
            }
            uVar4 = uVar4 + 1;
            iStack_c = (uint)iStack_c._1_3_ << 8;
            iVar5 = iVar6;
            iVar7 = iVar7 + 0x10;
          } while (uVar4 < (uint)unaff_retaddr[3]);
        }
        uVar4 = 0;
        if (unaff_retaddr[3] != 0) {
          do {
            FUN_00765200();
            uVar4 = uVar4 + 1;
          } while (uVar4 < (uint)unaff_retaddr[3]);
        }
        if (*unaff_retaddr != 0) {
          func_0x00763260(*unaff_retaddr);
        }
        unaff_retaddr[2] = unaff_EBX;
        *unaff_retaddr = iVar3;
        unaff_retaddr[1] = unaff_retaddr[3] * 0x10 + iVar3;
      }
      iStack_24 = unaff_retaddr[1];
      iStack_c = CONCAT31(iStack_c._1_3_,2);
      if (iStack_24 != 0) {
        func_0x00432290(iStack_2c);
      }
      unaff_retaddr[3] = unaff_retaddr[3] + 1;
      unaff_retaddr[1] = unaff_retaddr[1] + 0x10;
    }
    else {
      uVar2 = func_0x00431a60(&iStack_2c,&uStack_4);
      uVar2 = func_0x00431a10(&stack0xffffffc8,&iStack_c,uVar2);
      func_0x005caba0(uVar2);
      iStack_24 = iStack_1c;
      for (; iStack_1c != iStack_18; iStack_1c = func_0x0088caa0(iStack_1c)) {
        func_0x00432040(iStack_1c + 0x14);
      }
    }
  }
  iStack_c = -1;
  FUN_00765200();
  *unaff_FS_OFFSET = iStack_14;
  return iVar1;
}


/* ==================================================================== */
/* Address: 0x0042f350 | Classified: elementclient::WM_ACTIVATE@0x42f350 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_0042f350(int param_1,undefined4 param_2,uint param_3,int param_4,int *param_5)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iStack_b4;
  int iStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 auStack_9c [5];
  undefined4 auStack_88 [8];
  undefined4 auStack_68 [4];
  uint uStack_55;
  uint uStack_51;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [60];
  undefined4 uStack_4;
  
  if (param_3 < 0x11) {
    if (param_3 == 0x10) {
      if (DAT_009b4dfe != '\0') {
        ShowWindow(param_2,6);
      }
      ShowWindow(param_2,0);
      (*_DAT_009b3b70)(0,param_1 + 0x500);
      return 1;
    }
    switch(param_3) {
    case 2:
      return 1;
    case 5:
      iVar4 = *(int *)(param_1 + 0x18);
      if (iVar4 == 0) {
        return 0;
      }
      if (*(char *)(iVar4 + 0x92) != '\0') {
        return 0;
      }
      if (*(int *)(param_1 + 8) == 0) {
        return 0;
      }
      if (((uint)param_5 & 0xffff) == 0) {
        return 1;
      }
      if ((uint)param_5 >> 0x10 == 0) {
        return 1;
      }
      puVar5 = (undefined4 *)(iVar4 + 0x93);
      puVar6 = auStack_68;
      for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      puVar5 = (undefined4 *)(*(int *)(*(int *)(_DAT_009b3eec + 0x14) + 4) + 0x14);
      puVar6 = puVar5;
      puVar7 = auStack_9c;
      uStack_55 = (uint)param_5 & 0xffff;
      uStack_51 = (uint)param_5 >> 0x10;
      for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      func_0x0040ddc0(auStack_68,1);
      iVar4 = *(int *)(param_1 + 0x1c);
      puVar6 = auStack_88;
      for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      if (iVar4 == 0) {
        return 1;
      }
      iStack_b4 = 0;
      uStack_ac = auStack_9c[0];
      iStack_b0 = 0;
      uStack_a8 = auStack_9c[1];
      iVar4 = *(int *)(*(int *)(iVar4 + 4) + 0xc);
      if (iVar4 == 0) {
        FUN_004360a0(0,0,auStack_88[2],auStack_88[3]);
        piVar1 = (int *)func_0x005aafc0();
      }
      else {
        if (iVar4 != 1) {
          return 1;
        }
        FUN_004360a0(0,0,auStack_88[2],auStack_88[3]);
        piVar1 = (int *)func_0x005aafe0();
      }
      iVar4 = *piVar1;
      func_0x00410950(&iStack_b4);
      (**(code **)(iVar4 + 0x24))();
      return 1;
    case 6:
      if (((param_4 == 0) && (*(char *)(param_1 + 0x48c) != '\0')) && (*(int *)(param_1 + 8) != 0))
      {
        puVar5 = (undefined4 *)(*(int *)(param_1 + 8) + 0x10);
        puVar6 = auStack_9c;
        for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        if ((char)auStack_9c[0] == '\0') {
          (*_DAT_009b3b74)(0,0x40000000);
          ShowWindow(uStack_4,6);
          InvalidateRect(0,0,1);
          func_0x0077bcf0(1);
        }
      }
      OutputDebugStringA(0x951fc4);
      return 1;
    case 7:
      DAT_009b3ee5 = 1;
      OutputDebugStringA(0x951fd4);
      return 1;
    case 8:
      if ((*(char *)(param_1 + 0x48c) != '\0') && (*(int *)(param_1 + 8) != 0)) {
        puVar5 = (undefined4 *)(*(int *)(param_1 + 8) + 0x10);
        puVar6 = auStack_9c;
        for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        if ((char)auStack_9c[0] == '\0') {
          (*_DAT_009b3b74)(0,0x40000000);
          ShowWindow(uStack_4,6);
          InvalidateRect(0,0,1);
          func_0x0077bcf0(1);
        }
      }
      DAT_009b3ee5 = 0;
      OutputDebugStringA(0x951fe4);
      return 1;
    case 0xf:
      uVar2 = BeginPaint(param_2,auStack_40);
      iVar4 = *(int *)(param_1 + 0x18);
      if (iVar4 != 0) {
        BitBlt(uVar2,0,0,*(undefined4 *)(iVar4 + 0xa6),*(undefined4 *)(iVar4 + 0xaa),0,0,0,0x42);
      }
      EndPaint(param_2,auStack_48);
      return 1;
    }
  }
  else if (param_3 < 0x25) {
    if (param_3 == 0x24) {
      param_5[2] = 9999;
      param_5[3] = 9999;
      param_5[6] = 400;
      param_5[7] = 400;
      param_5[8] = 9999;
      param_5[9] = 9999;
      return 1;
    }
    if (param_3 == 0x12) {
      return 1;
    }
    if (param_3 == 0x1c) {
      *(bool *)(param_1 + 0x48c) = param_4 != 0;
      if (param_4 != 0) {
        if (*(int *)(param_1 + 0x20c) != 0) {
          func_0x0064d840();
          func_0x0064d3d0(*(undefined1 *)(*(int *)(param_1 + 0x18) + 0xa1));
        }
        if ((*(int *)(param_1 + 4) != 0) && (*(int *)(*(int *)(param_1 + 4) + 0xa1c) != 0)) {
          FUN_00767fe0(*(undefined1 *)(*(int *)(param_1 + 0x18) + 0xa0));
          OutputDebugStringA(0x951fb4);
          return 1;
        }
      }
      else if (*(int *)(param_1 + 8) != 0) {
        puVar5 = (undefined4 *)(*(int *)(param_1 + 8) + 0x10);
        puVar6 = auStack_9c;
        for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        if ((char)auStack_9c[0] == '\0') {
          (*_DAT_009b3b74)(0,0x40000000);
          ShowWindow(uStack_4,6);
          InvalidateRect(0,0,1);
          func_0x0077bcf0(1);
        }
      }
      OutputDebugStringA(0x951fb4);
      return 1;
    }
    if (param_3 == 0x20) {
      iVar4 = *(int *)(param_1 + 8);
      if ((iVar4 == 0) || (*(char *)(iVar4 + 0x30) == '\0')) {
        SetCursor(0);
        return 1;
      }
      if ((short)param_5 != 1) {
        return 0;
      }
      if (*(int **)(iVar4 + 0x34) == (int *)0x0) {
        return 1;
      }
      (**(code **)(**(int **)(iVar4 + 0x34) + 0xc))();
      return 1;
    }
  }
  else {
    if (param_3 == 0x214) {
      iStack_b0 = param_5[2];
      iStack_b4 = *param_5;
      iVar4 = iStack_b0 - iStack_b4;
      iVar3 = param_5[3] - param_5[1];
      switch(param_4) {
      case 1:
        goto code_r0x0042f98c;
      case 2:
        if ((float)iVar4 <= (float)iVar3 * _UNK_008d6b38) {
          return 1;
        }
        iVar4 = func_0x00892e78();
        param_5[2] = iVar4;
        return 1;
      case 3:
      case 4:
      case 5:
        if ((float)iVar4 <= (float)iVar3 * _UNK_008d6b38) {
          return 1;
        }
        iVar4 = func_0x00892e78();
        param_5[1] = iVar4;
        return 1;
      case 6:
      case 7:
      case 8:
        if ((float)iVar4 <= (float)iVar3 * _UNK_008d6b38) {
          return 1;
        }
        iVar4 = func_0x00892e78();
        param_5[3] = iVar4;
        return 1;
      default:
        return 1;
      }
    }
    if (param_3 == 0x466) {
      if (param_4 != 0x65) {
        return 1;
      }
      if (param_5 != (int *)0x202) {
        return 1;
      }
      if (DAT_009b4dfe != '\0') {
        ShowWindow(param_2,3);
      }
      ShowWindow(param_2,1);
      (*_DAT_009b3b70)(2,param_1 + 0x500);
      return 1;
    }
  }
  if (*(int *)(param_1 + 0x1c) == 0) {
    return 0;
  }
  uVar2 = FUN_00435600(param_3,param_4,param_5);
  return uVar2;
code_r0x0042f98c:
  if ((float)iVar4 <= (float)iVar3 * _UNK_008d6b38) {
    return 1;
  }
  iVar4 = func_0x00892e78();
  *param_5 = iVar4;
  return 1;
}


/* ==================================================================== */
/* Address: 0x0042fa60 | Classified: ElementClient::proc_42fa60 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0042fa60(void)

{
  char cVar1;
  int iVar2;
  
  do {
    if ((DAT_009b3c64 != '\0') || (iVar2 = WaitForSingleObject(_DAT_009b4fe8,0), iVar2 == 0)) {
      return 0;
    }
    if (DAT_009b4ff8 != '\0') {
      ResumeThread(_DAT_009b4fdc);
    }
    WaitForSingleObject(_DAT_009b4fec,0x14);
    cVar1 = FUN_0042fb90();
  } while (cVar1 != '\0');
  return 0xffffffff;
}


/* ==================================================================== */
/* Address: 0x0042fad0 | Classified: elementclient::CECGame__Run____break_because_Di@0x42fad0 */
/* ==================================================================== */

undefined4 __fastcall FUN_0042fad0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  cVar1 = FUN_0042fdc0();
  if (cVar1 == '\0') {
    func_0x00764590(1,0x952034);
    return 0;
  }
  if (DAT_009b4ff9 == '\0') {
    if ((*(char *)(*(int *)(param_1 + 8) + 10) == '\0') &&
       (*(char *)(*(int *)(param_1 + 8) + 0xb) != '\0')) {
      func_0x00427e00();
      cVar1 = func_0x0077b0c0();
      if (cVar1 == '\0') {
        func_0x00764590(1,0x951ff4);
      }
      if ((*(char *)(*(int *)(param_1 + 0x18) + 0x9b) != '\0') &&
         (iVar3 = 0, 0 < *(int *)(*(int *)(param_1 + 8) + 0x128))) {
        do {
          func_0x0077bdb0(iVar3,0x13,0xbf800000);
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(int *)(*(int *)(param_1 + 8) + 0x128));
      }
      func_0x00427560();
    }
    uVar2 = FUN_0042fb90();
    return uVar2;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0042fb90 | Classified: elementclient::CECGame__Run____break_because_CE@0x42fb90 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0042fb90(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint *unaff_FS_OFFSET;
  uint uStack_18;
  uint uStack_10;
  uint uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a7e58;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (uint)&uStack_c;
  uStack_18 = 0x9b4d28;
  EnterCriticalSection(0x9b4d28);
  puStack_8 = (undefined *)0x0;
  if (_DAT_009b3f38 == 0) {
    _DAT_009b3f38 = func_0x00763330();
  }
  else {
    iVar2 = func_0x00763330();
    *(int *)(param_1 + 0x494) = iVar2 - _DAT_009b3f38;
    _DAT_009b3f38 = iVar2;
    if ((*(char *)(param_1 + 0x498) == '\0') && (*(int *)(param_1 + 0x494) != 0)) {
      uVar3 = _DAT_009b3f40 + *(int *)(param_1 + 0x494);
      _DAT_009b3f3c = _DAT_009b3f3c + 1;
      _DAT_009b3f40 = uVar3;
      if (0xe < _DAT_009b3f3c) {
        *(float *)(param_1 + 0x49c) = _DAT_008d589c / ((float)uVar3 * _DAT_008d6b68);
        _DAT_009b3f3c = 0;
        _DAT_009b3f40 = 0;
        uStack_18 = uVar3;
      }
      func_0x005cfeb0(*(undefined4 *)(param_1 + 0x494));
      *(uint *)(param_1 + 0x490) = *(uint *)(param_1 + 0x494);
      if (0xfa < *(uint *)(param_1 + 0x494)) {
        *(undefined4 *)(param_1 + 0x490) = 0xfa;
      }
      cVar1 = FUN_00435710(*(undefined4 *)(param_1 + 0x490));
      if (cVar1 == '\0') {
        func_0x00764590(1,0x9520bc);
LAB_0042fcef:
        LeaveCriticalSection(0x9b4d28);
        *unaff_FS_OFFSET = uStack_18;
        return 0;
      }
      if (*(char *)(param_1 + 0x48c) == '\0') {
        Sleep(0xf);
      }
      else {
        cVar1 = FUN_00436720(1);
        if (cVar1 == '\0') {
          func_0x00764590(1,0x952078);
          goto LAB_0042fcef;
        }
        if (DAT_009b3ee5 != '\0') {
          func_0x0064ce30(*(undefined4 *)(param_1 + 0x490));
          func_0x0064d410(*(undefined4 *)(param_1 + 0x490));
          func_0x0064d600(*(undefined4 *)(param_1 + 0x490));
        }
      }
      _DAT_009b3f44 = _DAT_009b3f44 + *(int *)(param_1 + 0x494);
      if (3999 < _DAT_009b3f44) {
        _DAT_009b3f44 = 0;
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x498) = 0;
    }
  }
  LeaveCriticalSection(0x9b4d28);
  *unaff_FS_OFFSET = uStack_10;
  return 1;
}


/* ==================================================================== */
/* Address: 0x0042fdb0 | Classified: ElementClient::proc_42fdb0 */
/* ==================================================================== */

void __fastcall FUN_0042fdb0(int *param_1)

{
  if (*param_1 != 0) {
    LeaveCriticalSection(*param_1);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0042fdc0 | Classified: ElementClient::proc_42fdc0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0042fdc0(void)

{
  code *pcVar1;
  code *pcVar2;
  uint uVar3;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  undefined1 auStack_1c [28];
  
  pcVar2 = _DAT_009b3bb0;
  iStack_2c = 1;
  uStack_30 = 0;
  uStack_34 = 0;
  uStack_38 = 0;
  uVar3 = (*_DAT_009b3bb0)(auStack_1c);
  pcVar1 = _DAT_009b3b80;
  while( true ) {
    if (uVar3 == 0) {
      return 1;
    }
    if (iStack_2c == 0x12) break;
    TranslateMessage(&uStack_30);
    (*pcVar1)(&uStack_34);
    uVar3 = (*pcVar2)(&uStack_38,0,0,0,1);
  }
  return uVar3 & 0xffffff00;
}


/* ==================================================================== */
/* Address: 0x0042fe30 | Classified: elementclient::CECGame__InitA3DEngine@0x42fe30 */
/* ==================================================================== */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0042fe30(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *unaff_FS_OFFSET;
  int iStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined1 uStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined1 auStack_94 [8];
  undefined4 auStack_8c [6];
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_2c;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a7e8c;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar2 = func_0x00763250(0xab0);
  uStack_4 = 0;
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = func_0x00782b50();
  }
  uStack_4 = 0xffffffff;
  *(int *)(param_1 + 4) = iVar2;
  if (iVar2 == 0) {
    func_0x0043c590(2,0x952148,0x4fd);
    uVar3 = 0;
  }
  else {
    uStack_d4 = *(undefined4 *)(param_1 + 0x27c);
    uStack_cc = 0;
    iStack_d8 = CONCAT31(iStack_d8._1_3_,*(char *)(param_1 + 0x278) == '\0');
    uStack_d0 = *(undefined4 *)(param_1 + 0x280);
    uStack_c0 = (uint)uStack_c0._2_2_ << 0x10;
    uStack_c8 = 0;
    uStack_c4 = 0;
    uStack_c0 = CONCAT31(uStack_c0._1_3_,*(undefined1 *)(*(int *)(param_1 + 0x18) + 0xb8));
    uVar3 = 1;
    if (0xffff0103 < _DAT_009b454c) {
      uVar3 = 5;
    }
    cVar1 = func_0x00782f20(*(undefined4 *)(param_1 + 0x270),*(undefined4 *)(param_1 + 0x274),
                            &iStack_d8,uVar3,1);
    if (cVar1 == '\0') {
      uVar3 = 0x512;
    }
    else {
      *(undefined1 *)(_DAT_009d2d64 + 0x19) = 0;
      *(undefined4 *)(_DAT_009d2d64 + 0x14) = *(undefined4 *)(*(int *)(param_1 + 0x18) + 0xae);
      *(undefined4 *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 0xa18) + 0x14) + 8) =
           *(undefined4 *)(*(int *)(param_1 + 0x18) + 0xb2);
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)(param_1 + 4) + 0x50);
      func_0x0077bce0(0);
      func_0x00779e10();
      func_0x00779f10(1,0,0x3f800000,0);
      func_0x00779e70();
      func_0x00779ec0();
      iVar2 = func_0x00763250(0x14);
      uStack_2c = 1;
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = func_0x0043d670();
      }
      uStack_2c = 0xffffffff;
      *(int *)(param_1 + 0x14) = iVar2;
      if (iVar2 == 0) {
        func_0x0043c590(2,0x952148,0x52b);
        uVar3 = 0;
        goto LAB_004302bf;
      }
      iVar2 = *(int *)(param_1 + 0x18);
      puVar5 = (undefined4 *)&stack0xffffff1c;
      for (iVar4 = 0x12; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
      iVar4 = *(int *)(param_1 + 0x280);
      uStack_d4 = 0;
      uStack_d0 = 0x3f800000;
      uStack_cc = CONCAT22((short)((uint)uStack_cc >> 0x10),0x100);
      uStack_c8 = 0;
      uStack_c4 = 0x3f7a35dd;
      uStack_c0 = 0x3e4ccccd;
      uStack_bc = 0x44fa0000;
      iStack_d8 = iVar4;
      if ((*(char *)(iVar2 + 0xb7) != '\0') &&
         (iVar2 = *(int *)(param_1 + 0x27c) * 9, iVar2 < iVar4 * 0x10)) {
        iStack_d8 = (int)(iVar2 + (iVar2 >> 0x1f & 0xfU)) >> 4;
        iStack_d8 = iStack_d8 + (iVar4 - iStack_d8 >> 1);
      }
      fStack_ac = (float)*(int *)(param_1 + 0x27c);
      fStack_b0 = (float)iVar4;
      uStack_b8 = 1;
      uStack_a4 = 0xc4bb8000;
      fStack_b4 = -fStack_ac;
      uStack_a0 = 0x44bb8000;
      fStack_a8 = -fStack_b0;
      cVar1 = func_0x0043d730(&stack0xffffff1c);
      if (cVar1 == '\0') {
        uVar3 = 0x552;
      }
      else {
        func_0x0043da90(0);
        puVar5 = auStack_8c;
        for (iVar2 = 0x1a; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar5 = 0;
          puVar5 = puVar5 + 1;
        }
        iVar2 = *(int *)(param_1 + 0x18);
        auStack_8c[0] = 3;
        uStack_4c = *(undefined4 *)(iVar2 + 0x28);
        uStack_48 = *(undefined4 *)(iVar2 + 0x2c);
        uStack_44 = *(undefined4 *)(iVar2 + 0x30);
        func_0x007994d0(*(undefined4 *)(iVar2 + 0x20));
        func_0x007994d0(*(undefined4 *)(*(int *)(param_1 + 0x18) + 0x24));
        uStack_40 = 0x3f800000;
        iVar2 = FUN_00430330(auStack_94);
        *(int *)(param_1 + 0xc) = iVar2;
        if (iVar2 == 0) {
          uVar3 = 0x563;
        }
        else {
          FUN_0079b340();
          auStack_8c[1] = 1;
          uStack_74 = 0;
          uStack_70 = 0;
          uStack_6c = 0;
          uStack_68 = 0x3f800000;
          iVar2 = FUN_00430330(auStack_8c + 1);
          *(int *)(param_1 + 0x10) = iVar2;
          if (iVar2 != 0) {
            FUN_0079b370();
            func_0x0077a450(*(undefined4 *)(*(int *)(param_1 + 0x18) + 0x34));
            func_0x0077ab10(1);
            func_0x0077ac40(*(undefined4 *)(*(int *)(param_1 + 0x18) + 4));
            func_0x0077ac60(*(undefined4 *)(*(int *)(param_1 + 0x18) + 8));
            func_0x0077ac80(*(undefined4 *)(*(int *)(param_1 + 0x18) + 0xc));
            func_0x0077ac20(*(undefined4 *)(*(int *)(param_1 + 0x18) + 0x10));
            uVar3 = func_0x00892e78();
            func_0x0077b7c0(uVar3);
            iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x88);
            cVar1 = func_0x007aa7e0(0x952130);
            if (cVar1 == '\0') {
              func_0x00764590(1,0x9520f8);
              uVar3 = 0;
            }
            else {
              *(undefined4 *)(iVar2 + 0xd8) = *(undefined4 *)(param_1 + 0xc);
              *(undefined4 *)(iVar2 + 0xdc) = *(undefined4 *)(param_1 + 0x10);
              if ((*(char *)(*(int *)(param_1 + 0x18) + 0x9b) != '\0') &&
                 (iVar2 = 0, 0 < *(int *)(*(int *)(param_1 + 8) + 0x128))) {
                do {
                  func_0x0077bdb0(iVar2,0x13,0xbf800000);
                  iVar2 = iVar2 + 1;
                } while (iVar2 < *(int *)(*(int *)(param_1 + 8) + 0x128));
              }
              uVar3 = 1;
            }
            goto LAB_004302bf;
          }
          uVar3 = 0x56d;
        }
      }
    }
    func_0x0043c590(4,0x952148,uVar3);
    uVar3 = 0;
  }
LAB_004302bf:
  *unaff_FS_OFFSET = uStack_c;
  return uVar3;
}


/* ==================================================================== */
/* Address: 0x004302e0 | Classified: ElementClient::proc_4302e0 */
/* ==================================================================== */

void __fastcall FUN_004302e0(int param_1)

{
  FUN_004303c0(*(undefined4 *)(param_1 + 0xc));
  FUN_004303c0(*(undefined4 *)(param_1 + 0x10));
  if (*(undefined4 **)(param_1 + 0x14) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x14))(1);
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  if (*(int *)(param_1 + 4) != 0) {
    func_0x00783d00();
    if (*(undefined4 **)(param_1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 4))(1);
    }
    *(undefined4 *)(param_1 + 4) = 0;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00430330 | Classified: elementclient::Failed_to_create_A3D_light@0x430330 */
/* ==================================================================== */

int * __fastcall FUN_00430330(int param_1)

{
  int *piVar1;
  int iVar2;
  int *unaff_EDI;
  int iStack_4;
  
  iVar2 = 0;
  piVar1 = (int *)(param_1 + 0x4ac);
  while (*piVar1 != 0) {
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 1;
    if (7 < iVar2) {
      return (int *)0x0;
    }
  }
  if (7 < iVar2) {
    return (int *)0x0;
  }
  iStack_4 = 0;
  func_0x007ab720(iVar2);
  if (unaff_EDI == (int *)0x0) {
    func_0x00764590(1,0x952160);
    return (int *)0x0;
  }
  if (iStack_4 != 0) {
    FUN_0079b390(iStack_4);
    unaff_EDI = &iStack_4;
  }
  *(int **)(param_1 + 0x4ac + iVar2 * 4) = unaff_EDI;
  return unaff_EDI;
}


/* ==================================================================== */
/* Address: 0x004303c0 | Classified: ElementClient::proc_4303c0 */
/* ==================================================================== */

void __thiscall FUN_004303c0(int param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_2 != (undefined4 *)0x0) {
    iVar1 = 0;
    piVar2 = (int *)(param_1 + 0x4ac);
    while ((undefined4 *)*piVar2 != param_2) {
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
      if (7 < iVar1) {
        FUN_0079b330();
        (**(code **)*param_2)(1);
        return;
      }
    }
    *(undefined4 *)(param_1 + 0x4ac + iVar1 * 4) = 0;
    FUN_0079b330();
    (**(code **)*param_2)(1);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00430410 | Classified: elementclient::Failed_to_reset_A3DEngine_resour@0x430410 */
/* ==================================================================== */

undefined4 __fastcall FUN_00430410(int param_1)

{
  char cVar1;
  
  if (*(int *)(param_1 + 0x204) != 0) {
    FUN_007a52c0(1);
    FUN_007a52c0(0);
  }
  if (*(int *)(param_1 + 0x208) != 0) {
    FUN_007a52c0(1);
    FUN_007a52c0(0);
  }
  if (*(int *)(param_1 + 0x38) != 0) {
    func_0x00411830();
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    func_0x006e8050();
    func_0x006e7050(*(undefined4 *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0x200) != 0) {
    func_0x00413910();
  }
  if (*(int *)(param_1 + 4) != 0) {
    cVar1 = func_0x00784bb0();
    if (cVar1 == '\0') {
      func_0x00764590(1,0x95217c);
      return 0;
    }
  }
  if (*(int *)(param_1 + 0x200) != 0) {
    func_0x00413490();
  }
  *(undefined1 *)(param_1 + 0x498) = 1;
  return 1;
}


/* ==================================================================== */
/* Address: 0x004304c0 | Classified: elementclient::CECGame__LoadA3DSkinModel@0x4304c0 */
/* ==================================================================== */

undefined4 * __thiscall FUN_004304c0(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  undefined4 uVar4;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a7eab;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar2 = func_0x00763250(0x400);
  uStack_4 = 0;
  if (iVar2 == 0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_00790b20();
  }
  uStack_4 = 0xffffffff;
  if (puVar3 == (undefined4 *)0x0) {
    func_0x0043c590(2,0x9521a4,0x612);
    *unaff_FS_OFFSET = uStack_c;
    return (undefined4 *)0x0;
  }
  cVar1 = FUN_00790eb0(*(undefined4 *)(param_1 + 4));
  if (cVar1 == '\0') {
    (**(code **)*puVar3)(1);
    uVar4 = 0x619;
  }
  else {
    cVar1 = FUN_00791210(unaff_retaddr,param_2);
    if (cVar1 != '\0') {
      *unaff_FS_OFFSET = unaff_EDI;
      return puVar3;
    }
    (**(code **)*puVar3)(1);
    uVar4 = 0x620;
  }
  func_0x0043c590(4,0x9521a4,uVar4);
  *unaff_FS_OFFSET = unaff_ESI;
  return (undefined4 *)0x0;
}


/* ==================================================================== */
/* Address: 0x004305c0 | Classified: ElementClient::proc_4305c0 */
/* ==================================================================== */

void FUN_004305c0(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    FUN_00790f10();
    (**(code **)*param_1)(1);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x004305e0 | Classified: ElementClient::proc_4305e0 */
/* ==================================================================== */

void FUN_004305e0(undefined4 param_1)

{
  func_0x007aa660(param_1);
  return;
}


/* ==================================================================== */
/* Address: 0x00430600 | Classified: ElementClient::proc_430600 */
/* ==================================================================== */

void FUN_00430600(void)

{
  func_0x007aa7b0(&stack0x00000004);
  return;
}


/* ==================================================================== */
/* Address: 0x00430620 | Classified: ElementClient::proc_430620 */
/* ==================================================================== */

void FUN_00430620(int param_1,undefined4 param_2,short *param_3)

{
  undefined1 auStack_400 [1024];
  
  if (((*(int *)(param_1 + 0x24) != 0) && (param_3 != (short *)0x0)) && (*param_3 != 0)) {
    vswprintf(auStack_400,param_3,&stack0x00000010);
    func_0x00415e60(param_2,auStack_400);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00430680 | Classified: ElementClient::proc_430680 */
/* ==================================================================== */

void FUN_00430680(undefined4 param_1)

{
  func_0x0077b8a0(param_1);
  return;
}


/* ==================================================================== */
/* Address: 0x00430690 | Classified: ElementClient::proc_430690 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_00430690(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == *(int *)(param_1 + 0x4a0)) {
    return param_2;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x4d4) + param_2 * 4);
  if (iVar1 != 0) {
    func_0x0077b8c0(iVar1);
  }
  FUN_00430680(*(undefined1 *)(*(int *)(_DAT_009b3eec + 8) + 0x30));
  iVar1 = GetCurrentThreadId();
  if (_DAT_009b3ee8 != iVar1) {
    (*_DAT_009b3bb4)(*(undefined4 *)(param_1 + 0x274),0x20,*(undefined4 *)(param_1 + 0x274),
                     0x2000001);
  }
  iVar1 = *(int *)(param_1 + 0x4a0);
  *(int *)(param_1 + 0x4a0) = param_2;
  return iVar1;
}


/* ==================================================================== */
/* Address: 0x00430710 | Classified: ElementClient::proc_430710 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00430710(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined2 uStack_3c;
  undefined2 uStack_3a;
  undefined2 uStack_38;
  undefined2 uStack_36;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  
  iVar3 = *(int *)(param_1 + 0x4a4);
  iVar2 = time(0);
  *(int *)(param_1 + 0x4a4) = param_2 - iVar2;
  *(undefined4 *)(param_1 + 0x4a8) = param_3;
  FUN_00430800(&iStack_24);
  func_0x004b6030((float)(iStack_28 + (iStack_24 + iStack_20 * 0x3c) * 0x3c) * _DAT_008d6a8c);
  iVar2 = *(int *)(param_1 + 0x1c);
  uVar1 = *(undefined4 *)(iVar2 + 0xb9);
  uStack_3c = (undefined2)uVar1;
  uStack_3a = (undefined2)((uint)uVar1 >> 0x10);
  uStack_38 = (undefined2)*(undefined4 *)(iVar2 + 0xbd);
  uStack_36 = (undefined2)((uint)*(undefined4 *)(iVar2 + 0xbd) >> 0x10);
  iVar3 = CONCAT22(uStack_38,uStack_3a) + (*(int *)(param_1 + 0x4a4) - iVar3);
  uStack_3a = (undefined2)iVar3;
  uStack_38 = (undefined2)((uint)iVar3 >> 0x10);
  *(undefined4 *)(iVar2 + 0xb9) = CONCAT22(uStack_3a,uStack_3c);
  *(uint *)(iVar2 + 0xbd) = CONCAT22(uStack_36,uStack_38);
  *(undefined4 *)(iVar2 + 0xc1) = *(undefined4 *)(iVar2 + 0xc1);
  *(undefined2 *)(iVar2 + 0xc5) = *(undefined2 *)(iVar2 + 0xc5);
  return;
}


/* ==================================================================== */
/* Address: 0x004307e0 | Classified: ElementClient::proc_4307e0 */
/* ==================================================================== */

int __fastcall FUN_004307e0(int param_1)

{
  int iVar1;
  
  iVar1 = time(0);
  return iVar1 + *(int *)(param_1 + 0x4a4);
}


/* ==================================================================== */
/* Address: 0x00430800 | Classified: ElementClient::proc_430800 */
/* ==================================================================== */

void __thiscall FUN_00430800(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iStack_4;
  
  iStack_4 = param_1;
  iStack_4 = FUN_004307e0();
  iStack_4 = iStack_4 + *(int *)(param_1 + 0x4a8) * -0x3c;
  puVar1 = (undefined4 *)gmtime(&iStack_4);
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_2 = *puVar1;
    puVar1 = puVar1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}


