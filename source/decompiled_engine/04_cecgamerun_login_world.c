/* Authentic Ghidra 12.1.4 Decompilation — elementclient.exe (PW 1.4.2 Build 2305) */
/* Module: 04_cecgamerun_login_world.c */

/* ==================================================================== */
/* Address: 0x00433d70 | Classified: CECGameRun::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_00433d70(undefined4 param_1,byte param_2)

{
  FUN_00433d90();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00433d90 | Classified: ElementClient::proc_433d90 */
/* ==================================================================== */

void __fastcall FUN_00433d90(undefined4 *param_1)

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
  
  puStack_8 = &UNK_008a8295;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008d6c4c;
  uStack_4 = 4;
  FUN_00765200();
  uVar4 = 0;
  uStack_4 = CONCAT31(uStack_4._1_3_,3);
  if (param_1[0x39] != 0) {
    do {
      puVar3 = *(undefined4 **)(param_1[0x36] + uVar4 * 4);
      while (puVar3 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar3;
        func_0x00763260(puVar3);
        puVar3 = puVar1;
      }
      uVar4 = uVar4 + 1;
      *(undefined4 *)(param_1[0x36] + -4 + uVar4 * 4) = 0;
    } while (uVar4 < (uint)param_1[0x39]);
  }
  param_1[0x35] = 0;
  iVar2 = param_1[0x36];
  func_0x006e04e0(iVar2,iVar2 + param_1[0x39] * 4);
  iVar2 = param_1[0x36];
  if (iVar2 != 0) {
    func_0x00763260(iVar2);
  }
  uVar4 = 0;
  uStack_c = CONCAT31(uStack_c._1_3_,2);
  if (param_1[0x1d] != 0) {
    do {
      puVar3 = *(undefined4 **)(param_1[0x1a] + uVar4 * 4);
      while (puVar3 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar3;
        func_0x00763260(puVar3);
        puVar3 = puVar1;
      }
      uVar4 = uVar4 + 1;
      *(undefined4 *)(param_1[0x1a] + -4 + uVar4 * 4) = 0;
    } while (uVar4 < (uint)param_1[0x1d]);
  }
  param_1[0x19] = 0;
  iVar2 = param_1[0x1a];
  func_0x006e04e0(iVar2,iVar2 + param_1[0x1d] * 4);
  iVar2 = param_1[0x1a];
  if (iVar2 != 0) {
    func_0x00763260(iVar2);
  }
  FUN_00765200();
  uVar4 = 0;
  if (param_1[0x14] != 0) {
    do {
      puVar3 = *(undefined4 **)(param_1[0x11] + uVar4 * 4);
      while (puVar3 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar3;
        func_0x0043c330(0);
        func_0x00763260(puVar3);
        puVar3 = puVar1;
      }
      uVar4 = uVar4 + 1;
      *(undefined4 *)(param_1[0x11] + -4 + uVar4 * 4) = 0;
    } while (uVar4 < (uint)param_1[0x14]);
  }
  param_1[0x10] = 0;
  func_0x005b5c40();
  if (param_1[0x11] != 0) {
    func_0x00763260(param_1[0x11]);
  }
  uVar4 = 0;
  if (param_1[0xe] != 0) {
    do {
      puVar3 = *(undefined4 **)(param_1[0xb] + uVar4 * 4);
      while (puVar3 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar3;
        func_0x00763260(puVar3);
        puVar3 = puVar1;
      }
      uVar4 = uVar4 + 1;
      *(undefined4 *)(param_1[0xb] + -4 + uVar4 * 4) = 0;
    } while (uVar4 < (uint)param_1[0xe]);
  }
  param_1[10] = 0;
  func_0x004060e0();
  *unaff_FS_OFFSET = unaff_EBX;
  return;
}


/* ==================================================================== */
/* Address: 0x00433f80 | Classified: elementclient::CECGameRun__Init@0x433f80 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00433f80(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_ESI;
  int *unaff_FS_OFFSET;
  int iVar4;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a82e2;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  iVar2 = func_0x00763250(0x2dc);
  uStack_4 = 0;
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = func_0x0040e620();
  }
  *(undefined4 *)(param_1 + 0x1c) = uVar3;
  iVar4 = *(int *)(_DAT_009b3eec + 8);
  uStack_4 = 0xffffffff;
  cVar1 = func_0x0040e6c0();
  if (cVar1 == '\0') {
    func_0x0043c590(2,0x9524e8,0xfc);
    func_0x0040e770();
    *unaff_FS_OFFSET = iVar2;
    return 0;
  }
  if (*(char *)(*(int *)(param_1 + 0x1c) + 1) != '\0') {
    func_0x00410d90(CONCAT31((int3)((uint)*(int *)(_DAT_009b3eec + 0x18) >> 8),
                             *(undefined1 *)(*(int *)(_DAT_009b3eec + 0x18) + 0x9c)));
    func_0x00410e00(*(undefined1 *)(*(int *)(_DAT_009b3eec + 0x18) + 0x9d));
    func_0x00410e70(*(undefined1 *)(*(int *)(_DAT_009b3eec + 0x18) + 0x9e));
  }
  uVar3 = 0x9524d0;
  cVar1 = func_0x00438690(0x9524d0);
  if (cVar1 == '\0') {
    func_0x0043c590(4,0x9524e8,0x10b);
    *unaff_FS_OFFSET = unaff_ESI;
    return 0;
  }
  iVar2 = func_0x00763250(0x24);
  iStack_c = 1;
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = func_0x005aa920(uVar3,iVar4,iVar2);
  }
  iStack_c = -1;
  *(int *)(param_1 + 4) = iVar2;
  if (iVar2 == 0) {
    uVar3 = 0x112;
  }
  else {
    cVar1 = func_0x005aaa00(*(undefined4 *)(_DAT_009b3eec + 4),0xffffffff);
    if (cVar1 == '\0') {
      func_0x00764590(1,0x95249c);
      *unaff_FS_OFFSET = iVar4;
      return 0;
    }
    iVar2 = func_0x00763250(0x17c);
    iStack_c = 2;
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = func_0x00404730(uVar3,iVar4,iVar2);
    }
    iStack_c = -1;
    *(int *)(param_1 + 0xc) = iVar2;
    if (iVar2 == 0) {
      uVar3 = 0x11f;
    }
    else {
      iVar2 = func_0x00763250(0x94);
      iStack_c = 3;
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = func_0x00401e80(*(undefined4 *)(param_1 + 0xc),uVar3,iVar4,iVar2);
      }
      iStack_c = -1;
      *(int *)(param_1 + 0x10) = iVar2;
      if (iVar2 == 0) {
        uVar3 = 0x126;
      }
      else {
        iVar2 = func_0x00763250(0x30);
        iStack_c = 4;
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = func_0x00401000(*(undefined4 *)(param_1 + 0xc),uVar3,iVar4,iVar2);
        }
        iStack_c = -1;
        *(int *)(param_1 + 0x14) = iVar2;
        if (iVar2 == 0) {
          uVar3 = 0x12d;
        }
        else {
          iVar2 = func_0x00763250(0xc);
          iStack_c = 5;
          if (iVar2 == 0) {
            iVar2 = 0;
          }
          else {
            iVar2 = func_0x0040c3b0(uVar3,iVar4,iVar2);
          }
          iStack_c = -1;
          *(int *)(param_1 + 0x5c) = iVar2;
          if (iVar2 != 0) {
            func_0x006cde00();
            FUN_00430690(0);
            FUN_00430680(1);
            *unaff_FS_OFFSET = iVar4;
            return 1;
          }
          uVar3 = 0x134;
        }
      }
    }
  }
  iStack_c = -1;
  func_0x0043c590(2,0x9524e8,uVar3);
  *unaff_FS_OFFSET = unaff_ESI;
  return 0;
}


/* ==================================================================== */
/* Address: 0x00434250 | Classified: ElementClient::proc_434250 */
/* ==================================================================== */

void __fastcall FUN_00434250(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  int *unaff_EBX;
  int unaff_EBP;
  uint uVar7;
  int *piVar8;
  int *piStack_c;
  
  FUN_00434800(0);
  if (*(int *)(param_1 + 0xa8) != 0) {
    func_0x007631b0(*(int *)(param_1 + 0xa8));
    *(undefined4 *)(param_1 + 0xa8) = 0;
  }
  if (*(int *)(param_1 + 4) != 0) {
    func_0x005aaa60();
    if (*(undefined4 **)(param_1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 4))(1);
    }
    *(undefined4 *)(param_1 + 4) = 0;
  }
  if (*(undefined4 **)(param_1 + 0x10) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x10))(1);
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (*(undefined4 **)(param_1 + 0x14) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x14))(1);
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    func_0x00430860();
    if (*(undefined4 **)(param_1 + 0xc) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0xc))(1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x5c);
  if (iVar1 != 0) {
    func_0x0040c3c0();
    func_0x00763260(iVar1);
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    func_0x0040e770();
    iVar1 = *(int *)(param_1 + 0x1c);
    if (iVar1 != 0) {
      func_0x0040e6b0();
      func_0x00763260(iVar1);
    }
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  iVar1 = param_1 + 0x60;
  func_0x00413170(iVar1);
  piVar5 = piStack_c;
  piVar8 = unaff_EBX;
LAB_0043432b:
  do {
    if (((unaff_EBP == 0) || (iVar1 == 0)) || (unaff_EBP == iVar1)) {
      if (unaff_EBX == (int *)0x0) {
        if (piVar5 == (int *)0x0) {
          uVar7 = 0;
          if (*(int *)(param_1 + 0x74) != 0) {
            do {
              puVar4 = *(undefined4 **)(*(int *)(param_1 + 0x68) + uVar7 * 4);
              while (puVar4 != (undefined4 *)0x0) {
                puVar3 = (undefined4 *)*puVar4;
                func_0x00763260(puVar4);
                puVar4 = puVar3;
              }
              uVar7 = uVar7 + 1;
              *(undefined4 *)(*(int *)(param_1 + 0x68) + -4 + uVar7 * 4) = 0;
            } while (uVar7 < *(uint *)(param_1 + 0x74));
          }
          *(undefined4 *)(param_1 + 100) = 0;
          return;
        }
        goto LAB_0043433f;
      }
LAB_0043438f:
      piVar6 = piVar5 + 1;
    }
    else {
      if (unaff_EBX != (int *)0x0) goto LAB_0043438f;
LAB_0043433f:
      piVar6 = (int *)0x0;
    }
    iVar2 = *piVar6;
    if (iVar2 != 0) {
      FUN_004343f0();
      func_0x00763260(iVar2);
      piVar5 = piStack_c;
      unaff_EBX = piVar8;
    }
    if (unaff_EBX != (int *)0x0) {
      do {
        while (piVar5 == (int *)0x0) {
          unaff_EBX = unaff_EBX + 1;
          if (unaff_EBX == (int *)(*(int *)(unaff_EBP + 8) + *(int *)(unaff_EBP + 0x14) * 4)) {
            unaff_EBX = (int *)0x0;
            piVar8 = (int *)0x0;
            goto LAB_0043432b;
          }
          piVar5 = (int *)*unaff_EBX;
          piVar8 = unaff_EBX;
          piStack_c = piVar5;
          if (piVar5 != (int *)0x0) goto LAB_0043432b;
        }
        piVar5 = (int *)*piVar5;
        piStack_c = piVar5;
      } while (piVar5 == (int *)0x0);
    }
  } while( true );
}


/* ==================================================================== */
/* Address: 0x004343f0 | Classified: ElementClient::proc_4343f0 */
/* ==================================================================== */

void FUN_004343f0(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008a82fb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  func_0x007637f0();
  uStack_4 = 0xffffffff;
  FUN_00765200();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x00434440 | Classified: elementclient::CECGameRun__StartGame__Failed_to@0x434440 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00434440(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  int *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  undefined4 uVar4;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a8326;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  FUN_00434800();
  *(undefined4 *)(param_1 + 0xb9) = 0;
  *(undefined4 *)(param_1 + 0xbd) = 0;
  *(undefined4 *)(param_1 + 0xc1) = 0;
  *(undefined2 *)(param_1 + 0xc5) = 0;
  *(undefined4 *)(param_1 + 0x90) = 2;
  cVar1 = FUN_00430850();
  if (cVar1 == '\0') {
    func_0x00764590(1,0x9525e8);
    *unaff_FS_OFFSET = param_1;
    return 0;
  }
  iVar2 = func_0x00763250(0x24);
  puStack_8 = (undefined *)0x0;
  if (iVar2 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = func_0x005aec60(param_1);
  }
  puStack_8 = (undefined *)0xffffffff;
  *(int *)(param_1 + 0x58) = iVar3;
  if (iVar3 == 0) {
    uVar4 = 0x18a;
  }
  else {
    cVar1 = func_0x00438900(unaff_retaddr,param_2);
    if (cVar1 == '\0') {
      func_0x00764590(1,0x9525b4);
      *unaff_FS_OFFSET = unaff_ESI;
      return 0;
    }
    cVar1 = FUN_00434de0();
    if (cVar1 == '\0') {
      func_0x00764590(1,0x95257c);
      *unaff_FS_OFFSET = unaff_ESI;
      return 0;
    }
    iVar3 = func_0x00763250(0x1c);
    puStack_8 = (undefined *)0x1;
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = func_0x004811c0();
    }
    puStack_8 = (undefined *)0xffffffff;
    *(int *)(param_1 + 0x78) = iVar3;
    if (iVar3 != 0) {
      func_0x00449c20(0);
      cVar1 = FUN_00434ea0();
      if (cVar1 == '\0') {
        func_0x00764590(1,0x952530);
        *unaff_FS_OFFSET = iVar2;
        return 0;
      }
      cVar1 = func_0x005aad00(1);
      if (cVar1 == '\0') {
        func_0x00764590(1,0x9524fc);
        *unaff_FS_OFFSET = unaff_ESI;
        return 0;
      }
      func_0x00402150();
      iVar2 = func_0x005aafe0();
      if (iVar2 != 0) {
        func_0x0059a660(unaff_retaddr);
      }
      _DAT_009b3f68 = 0;
      FUN_00430690(0);
      *(undefined1 *)(_DAT_009b3eec + 0x498) = 1;
      _DAT_009b3f50 = 0;
      _DAT_009b3f54 = 0;
      *unaff_FS_OFFSET = 1;
      _DAT_009b3f58 = 0;
      _DAT_009b3f5c = 0;
      _DAT_009b3f60 = 0;
      return 1;
    }
    uVar4 = 0x19f;
  }
  puStack_8 = (undefined *)0xffffffff;
  func_0x0043c590(2,0x952564,uVar4);
  *unaff_FS_OFFSET = param_1;
  return 0;
}


/* ==================================================================== */
/* Address: 0x004346a0 | Classified: ElementClient::proc_4346a0 */
/* ==================================================================== */

void __fastcall FUN_004346a0(int param_1)

{
  func_0x005aad00(0xffffffff);
  FUN_004352f0();
  if (*(int *)(param_1 + 0x78) != 0) {
    func_0x00481320();
    if (*(undefined4 **)(param_1 + 0x78) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x78))(1);
    }
    *(undefined4 *)(param_1 + 0x78) = 0;
  }
  FUN_00434e70();
  FUN_00434af0();
  if (*(int *)(param_1 + 0x58) != 0) {
    func_0x005aed20();
    if (*(undefined4 **)(param_1 + 0x58) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x58))(1);
    }
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  func_0x00430860();
  FUN_004353b0();
  return;
}


/* ==================================================================== */
/* Address: 0x00434720 | Classified: elementclient::CECGameRun__StartLogin__Failed_t@0x434720 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00434720(int param_1)

{
  char cVar1;
  
  FUN_00434800(1);
  *(undefined4 *)(param_1 + 0x90) = 1;
  cVar1 = FUN_00434b80(&stack0xfffffff0);
  if (cVar1 == '\0') {
    func_0x00764590(1,0x952658);
    return 0;
  }
  cVar1 = func_0x005aad00(0);
  if (cVar1 != '\0') {
    func_0x005aafc0();
    FUN_005a6e70();
    FUN_00430690(0);
    *(undefined1 *)(_DAT_009b3eec + 0x498) = 1;
    return 1;
  }
  func_0x00764590(1,0x952620);
  return 0;
}


/* ==================================================================== */
/* Address: 0x004347e0 | Classified: ElementClient::proc_4347e0 */
/* ==================================================================== */

void FUN_004347e0(void)

{
  func_0x005aad00(0xffffffff);
  FUN_00434db0();
  return;
}


/* ==================================================================== */
/* Address: 0x00434800 | Classified: ElementClient::proc_434800 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00434800(int param_1,char param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x90);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x90) = 0;
    if (iVar1 == 1) {
      FUN_004347e0();
    }
    else if (iVar1 == 2) {
      FUN_004346a0();
    }
    if (*(int *)(_DAT_009b3eec + 0x20c) != 0) {
      func_0x0064d1c0(1,1);
      func_0x0064d5b0(1);
    }
    if (param_2 != '\0') {
      FUN_00430410();
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00434870 | Classified: elementclient::CECGameRun__CreateWorld__wrong_i@0x434870 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __thiscall FUN_00434870(int param_1,int param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  int iStack_148;
  undefined1 auStack_124 [276];
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a833e;
  *unaff_FS_OFFSET = &uStack_c;
  iStack_148 = param_2;
  iVar3 = func_0x00438660();
  if (iVar3 == 0) {
    func_0x00764590(1,0x952724,param_2);
    uVar2 = 0;
  }
  else {
    iVar4 = func_0x00763250(0xb4);
    puStack_8 = (undefined *)0x0;
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = func_0x004289f0(param_1);
    }
    puStack_8 = (undefined *)0xffffffff;
    *(int *)(param_1 + 8) = iVar4;
    if (iVar4 == 0) {
      func_0x0043c590(2,0x95270c,0x231);
      uVar2 = 0;
    }
    else {
      cVar1 = FUN_00428ad0(param_2);
      if (cVar1 == '\0') {
        func_0x00764590(1,0x9526d4);
        uVar2 = 0;
      }
      else {
        func_0x00424230(*(byte *)(*(int *)(_DAT_009b3eec + 0x18) + 0x94) + 1);
        func_0x00438150(2,0,100);
        sprintf(auStack_124,0x9526c0,*(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 8));
        cVar1 = FUN_004294a0(auStack_124,uStack_c);
        if (cVar1 == '\0') {
          func_0x00764590(1,0x952690);
          uVar2 = 0;
        }
        else {
          func_0x00438230();
          cVar1 = func_0x0043e760(*(undefined4 *)(iVar3 + 8));
          uVar2 = 0;
          if (cVar1 != '\0') {
            iVar3 = *(int *)(_DAT_009b3eec + 0x18);
            uVar5 = *(uint *)(iVar3 + 4);
            func_0x0077ac40(uVar5);
            func_0x0077ac60(*(undefined4 *)(iVar3 + 8));
            func_0x0077ac80(*(undefined4 *)(iVar3 + 0xc));
            func_0x0077ac20(*(undefined4 *)(iVar3 + 0x10));
            if (*(int *)(*(int *)(param_1 + 8) + 0x3c) != 0) {
              uVar5 = (uint)*(byte *)(iVar3 + 0x97);
              func_0x006508e0((float)uVar5 * _DAT_008d609c);
            }
            if (*(int *)(*(int *)(param_1 + 8) + 0x40) != 0) {
              uVar5 = (uint)*(byte *)(iVar3 + 0x98);
              func_0x00651780((float)uVar5 * _DAT_008d609c);
            }
            if (*(int *)(*(int *)(param_1 + 8) + 0x48) != 0) {
              func_0x006461f0(((uint)*(byte *)(iVar3 + 0x99) * 0x19) / 10);
            }
            FUN_00430800(&iStack_148);
            func_0x004b6030((float)(int)(uVar5 + (iStack_148 + unaff_EDI * 0x3c) * 0x3c) *
                            _DAT_008d6a8c);
            uVar2 = 1;
          }
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_10;
  return uVar2;
}


/* ==================================================================== */
/* Address: 0x00434af0 | Classified: ElementClient::proc_434af0 */
/* ==================================================================== */

void __fastcall FUN_00434af0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  *(undefined4 *)(iVar1 + 0x158) = 0;
  if (*(int *)(iVar1 + 0x148) != 0) {
    func_0x00763260(*(int *)(iVar1 + 0x148));
    *(undefined4 *)(iVar1 + 0x148) = 0;
  }
  *(undefined4 *)(iVar1 + 0x150) = 0;
  *(undefined4 *)(iVar1 + 0x14c) = 0;
  iVar1 = *(int *)(param_1 + 0xc);
  *(undefined4 *)(iVar1 + 0x178) = 0;
  if (*(int *)(iVar1 + 0x168) != 0) {
    func_0x00763260(*(int *)(iVar1 + 0x168));
    *(undefined4 *)(iVar1 + 0x168) = 0;
  }
  *(undefined4 *)(iVar1 + 0x170) = 0;
  *(undefined4 *)(iVar1 + 0x16c) = 0;
  func_0x0043da50(0);
  if (*(int *)(param_1 + 8) != 0) {
    FUN_004293e0();
    if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 8))(1);
    }
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00434b80 | Classified: elementclient::CECGameRun__CreateLoginWorld__Fa@0x434b80 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00434b80(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  int iStack_120;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a835e;
  *unaff_FS_OFFSET = &uStack_c;
  iStack_120 = 0x434baa;
  cVar1 = FUN_00430850();
  if (cVar1 == '\0') {
    iStack_120 = 0x952810;
    uStack_124 = 1;
    uStack_128 = 0x434bba;
    func_0x00764590();
    uVar2 = 0;
  }
  else {
    iStack_120 = 0xb4;
    uStack_124 = 0x434bce;
    iVar3 = func_0x00763250();
    uStack_4 = 0;
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      uStack_124 = 0x434bec;
      iStack_120 = param_1;
      iVar3 = func_0x004289f0();
    }
    uStack_4 = 0xffffffff;
    *(int *)(param_1 + 8) = iVar3;
    if (iVar3 == 0) {
      iStack_120 = 0x284;
      uStack_124 = 0x9527f0;
      uStack_128 = 2;
      uStack_12c = 0x434c13;
      func_0x0043c590();
      uVar2 = 0;
    }
    else {
      iStack_120 = 0;
      uStack_124 = 0x434c26;
      cVar1 = FUN_00428ad0();
      if (cVar1 == '\0') {
        uStack_124 = 0x9527b4;
        uStack_128 = 1;
        uStack_12c = 0x434c36;
        func_0x00764590();
        uVar2 = 0;
      }
      else {
        uStack_124 = 0;
        uStack_128 = 0x434c47;
        func_0x00424230();
        uStack_124 = 100;
        uStack_128 = 0;
        uStack_12c = 2;
        uStack_130 = 0x434c57;
        func_0x00438150();
        uVar2 = uStack_c;
        uStack_130 = uStack_c;
        uStack_134 = 0x95279c;
        uStack_138 = 0x434c6c;
        cVar1 = FUN_004294a0();
        if (cVar1 == '\0') {
          uStack_138 = 0x952768;
          uStack_13c = 1;
          func_0x00764590();
          uVar2 = 0;
        }
        else {
          uStack_138 = 0x434c8d;
          func_0x00438230();
          uStack_138 = uVar2;
          uStack_13c = 0x434ca1;
          func_0x00401cc0();
          uStack_13c = 0x434ca8;
          func_0x00774140();
          iVar3 = *(int *)(_DAT_009b3eec + 0x18);
          uStack_13c = *(undefined4 *)(iVar3 + 4);
          func_0x0077ac40();
          func_0x0077ac60(*(undefined4 *)(iVar3 + 8));
          func_0x0077ac80(*(undefined4 *)(iVar3 + 0xc));
          func_0x0077ac20(*(undefined4 *)(iVar3 + 0x10));
          uVar4 = GetTickCount();
          sprintf(&uStack_13c,0x952754,(int)(((ulonglong)uVar4 / 100) % 3) + 0x61);
          func_0x0064cf70(&uStack_13c,0,1);
          if (*(int *)(*(int *)(*(int *)(_DAT_009b3eec + 0x1c) + 8) + 0x3c) != 0) {
            iStack_120 = 0x3f800000;
            uStack_124 = 0x434d53;
            func_0x006508e0();
          }
          if (*(int *)(*(int *)(*(int *)(_DAT_009b3eec + 0x1c) + 8) + 0x40) != 0) {
            iStack_120 = 0x3f800000;
            uStack_124 = 0x434d70;
            func_0x00651780();
          }
          if (*(int *)(*(int *)(*(int *)(_DAT_009b3eec + 0x1c) + 8) + 0x48) != 0) {
            iStack_120 = 10;
            uStack_124 = 0x434d8a;
            func_0x006461f0();
          }
          uVar2 = 1;
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return uVar2;
}


/* ==================================================================== */
/* Address: 0x00434db0 | Classified: ElementClient::proc_434db0 */
/* ==================================================================== */

void __fastcall FUN_00434db0(int param_1)

{
  if (*(int *)(param_1 + 8) != 0) {
    FUN_004293e0();
    if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 8))(1);
    }
    *(undefined4 *)(param_1 + 8) = 0;
  }
  func_0x00430860();
  return;
}


/* ==================================================================== */
/* Address: 0x00434de0 | Classified: elementclient::CECGameRun__CreateHostPlayer@0x434de0 */
/* ==================================================================== */

undefined4 __fastcall FUN_00434de0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a837b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x20);
  iVar2 = func_0x00763250(0xfa4);
  uStack_4 = 0;
  if (iVar2 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = func_0x00459840(uVar1);
  }
  *(int *)(param_1 + 0x20) = iVar3;
  uStack_4 = 0xffffffff;
  if (iVar3 == 0) {
    func_0x0043c590(2,0x952850,0x2cd,iVar2);
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00434e70 | Classified: ElementClient::proc_434e70 */
/* ==================================================================== */

void __fastcall FUN_00434e70(int param_1)

{
  if (*(int **)(param_1 + 0x20) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x20) + 0x40))();
    if (*(undefined4 **)(param_1 + 0x20) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x20))(1);
    }
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00434ea0 | Classified: ElementClient::proc_434ea0 */
/* ==================================================================== */

undefined4 __fastcall FUN_00434ea0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar4;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a8461;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar1 = func_0x00763250(0x1c);
  iVar3 = 0;
  uStack_4 = 0;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x004a4db0();
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x7c) = uVar2;
  func_0x004a4e40(8);
  iVar1 = func_0x00763250(0x10);
  puStack_8 = (undefined *)0x1;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x004a3ba0(0);
  }
  puStack_8 = (undefined *)0xffffffff;
  func_0x0048ba70(0,uVar2);
  iVar1 = func_0x00763250(0x10);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x004a3ba0(1);
  }
  func_0x0048ba70(1,uVar2);
  iVar1 = func_0x00763250(0x10);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x004a3ba0(2);
  }
  func_0x0048ba70(2,uVar2);
  iVar1 = func_0x00763250(0x10);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x004a3ba0(4);
  }
  func_0x0048ba70(3,uVar2);
  iVar1 = func_0x00763250(0x10);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x004a3ba0(0xe);
  }
  func_0x0048ba70(4,uVar2);
  iVar1 = func_0x00763250(0x10);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x004a3ba0(0xf);
  }
  func_0x0048ba70(5,uVar2);
  iVar1 = func_0x00763250(0x10);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x004a3ba0(0x11);
  }
  func_0x0048ba70(6,uVar2);
  iVar1 = func_0x00763250(0x10);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x004a3ba0(0x12);
  }
  func_0x0048ba70(7,uVar2);
  iVar1 = func_0x00763250(0x1c);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x004a4db0();
  }
  *(undefined4 *)(param_1 + 0x80) = uVar2;
  func_0x004a4e40(2);
  iVar1 = func_0x00763250(0x10);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x004a3ba0(5);
  }
  func_0x0048ba70(0,uVar2);
  iVar1 = func_0x00763250(0x10);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x004a3ba0(6);
  }
  func_0x0048ba70(1,uVar2);
  iVar1 = func_0x00763250(0x1c);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x004a4db0();
  }
  *(undefined4 *)(param_1 + 0x84) = uVar2;
  func_0x004a4e40(2);
  iVar1 = func_0x00763250(0x10);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x004a3ba0(9);
  }
  func_0x0048ba70(0,uVar2);
  iVar1 = func_0x00763250(0x10);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x004a3ba0(10);
  }
  uVar4 = 1;
  func_0x0048ba70(1,uVar2);
  iVar1 = func_0x00763250(0x1c);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x004a4db0();
  }
  *(undefined4 *)(param_1 + 0x88) = uVar2;
  func_0x004a4e40(0x1b);
  do {
    iVar1 = func_0x00763250(0x10);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = func_0x004a3ba0(0xc);
    }
    *(int *)(iVar1 + 0xc) = iVar3;
    func_0x0048ba70(iVar3,iVar1);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x1b);
  iVar1 = func_0x00763250(0x1c);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x004a4db0();
  }
  *(undefined4 *)(param_1 + 0x8c) = uVar2;
  func_0x004a4e40(1);
  iVar1 = func_0x00763250(0x10);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x004a3ba0(0xd);
  }
  func_0x0048ba70(0,uVar2);
  *unaff_FS_OFFSET = uVar4;
  return 1;
}


/* ==================================================================== */
/* Address: 0x004352f0 | Classified: ElementClient::proc_4352f0 */
/* ==================================================================== */

void __fastcall FUN_004352f0(int param_1)

{
  if (*(int *)(param_1 + 0x7c) != 0) {
    func_0x0048b920();
    if (*(undefined4 **)(param_1 + 0x7c) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x7c))(1);
    }
    *(undefined4 *)(param_1 + 0x7c) = 0;
  }
  if (*(int *)(param_1 + 0x80) != 0) {
    func_0x0048b920();
    if (*(undefined4 **)(param_1 + 0x80) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x80))(1);
    }
    *(undefined4 *)(param_1 + 0x80) = 0;
  }
  if (*(int *)(param_1 + 0x84) != 0) {
    func_0x0048b920();
    if (*(undefined4 **)(param_1 + 0x84) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x84))(1);
    }
    *(undefined4 *)(param_1 + 0x84) = 0;
  }
  if (*(int *)(param_1 + 0x88) != 0) {
    func_0x0048b920();
    if (*(undefined4 **)(param_1 + 0x88) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x88))(1);
    }
    *(undefined4 *)(param_1 + 0x88) = 0;
  }
  if (*(int *)(param_1 + 0x8c) != 0) {
    func_0x0048b920();
    if (*(undefined4 **)(param_1 + 0x8c) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x8c))(1);
    }
    *(undefined4 *)(param_1 + 0x8c) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x004353b0 | Classified: ElementClient::proc_4353b0 */
/* ==================================================================== */

void __fastcall FUN_004353b0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  int iStack_c;
  int *piStack_8;
  int *piStack_4;
  
  if (*(int *)(param_1 + 0x28) == 0) {
LAB_00435498:
    uVar8 = 0;
    if (*(int *)(param_1 + 0x50) != 0) {
      do {
        puVar4 = *(undefined4 **)(*(int *)(param_1 + 0x44) + uVar8 * 4);
        while (puVar4 != (undefined4 *)0x0) {
          puVar3 = (undefined4 *)*puVar4;
          func_0x00827140();
          func_0x00763260(puVar4);
          puVar4 = puVar3;
        }
        uVar8 = uVar8 + 1;
        *(undefined4 *)(*(int *)(param_1 + 0x44) + -4 + uVar8 * 4) = 0;
      } while (uVar8 < *(uint *)(param_1 + 0x50));
      *(undefined4 *)(param_1 + 0x40) = 0;
      return;
    }
    *(undefined4 *)(param_1 + 0x40) = 0;
    return;
  }
  iVar1 = param_1 + 0x24;
  func_0x00413170(iVar1);
  piVar5 = piStack_4;
  piVar6 = piStack_8;
LAB_004353e1:
  if (((iStack_c == 0) || (iVar1 == 0)) || (iStack_c == iVar1)) {
    if (piVar6 == (int *)0x0) {
      if (piVar5 != (int *)0x0) goto LAB_004353f5;
      uVar8 = 0;
      if (*(int *)(param_1 + 0x38) != 0) {
        do {
          puVar4 = *(undefined4 **)(*(int *)(param_1 + 0x2c) + uVar8 * 4);
          while (puVar4 != (undefined4 *)0x0) {
            puVar3 = (undefined4 *)*puVar4;
            func_0x00763260(puVar4);
            puVar4 = puVar3;
          }
          uVar8 = uVar8 + 1;
          *(undefined4 *)(*(int *)(param_1 + 0x2c) + -4 + uVar8 * 4) = 0;
        } while (uVar8 < *(uint *)(param_1 + 0x38));
      }
      *(undefined4 *)(param_1 + 0x28) = 0;
      goto LAB_00435498;
    }
LAB_00435445:
    piVar7 = piVar5 + 1;
  }
  else {
    if (piVar6 != (int *)0x0) goto LAB_00435445;
LAB_004353f5:
    piVar7 = (int *)0x0;
  }
  iVar2 = *piVar7;
  if (iVar2 != 0) {
    FUN_00765200();
    func_0x00763260(iVar2);
    piVar5 = piStack_4;
    piVar6 = piStack_8;
  }
  if (piVar6 != (int *)0x0) {
    do {
      while (piVar5 == (int *)0x0) {
        piVar6 = piVar6 + 1;
        if (piVar6 == (int *)(*(int *)(iStack_c + 8) + *(int *)(iStack_c + 0x14) * 4)) {
          piVar6 = (int *)0x0;
          piStack_8 = (int *)0x0;
          goto LAB_004353e1;
        }
        piVar5 = (int *)*piVar6;
        piStack_8 = piVar6;
        piStack_4 = piVar5;
        if (piVar5 != (int *)0x0) goto LAB_004353e1;
      }
      piVar5 = (int *)*piVar5;
      piStack_4 = piVar5;
    } while (piVar5 == (int *)0x0);
  }
  goto LAB_004353e1;
}


/* ==================================================================== */
/* Address: 0x00435500 | Classified: ElementClient::proc_435500 */
/* ==================================================================== */

int __thiscall FUN_00435500(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 0x7c) + 0x10)) {
    do {
      iVar1 = func_0x0048baa0(iVar2,0);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 8) == param_2)) {
        return iVar1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(*(int *)(param_1 + 0x7c) + 0x10));
  }
  iVar2 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 0x80) + 0x10)) {
    do {
      iVar1 = func_0x0048baa0(iVar2,0);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 8) == param_2)) {
        return iVar1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(*(int *)(param_1 + 0x80) + 0x10));
  }
  iVar2 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 0x84) + 0x10)) {
    do {
      iVar1 = func_0x0048baa0(iVar2,0);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 8) == param_2)) {
        return iVar1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(*(int *)(param_1 + 0x84) + 0x10));
  }
  iVar2 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 0x8c) + 0x10)) {
    do {
      iVar1 = func_0x0048baa0(iVar2,0);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 8) == param_2)) {
        return iVar1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(*(int *)(param_1 + 0x8c) + 0x10));
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x004355c0 | Classified: ElementClient::proc_4355c0 */
/* ==================================================================== */

int __thiscall FUN_004355c0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 0x88) + 0x10)) {
    do {
      iVar1 = func_0x0048baa0(iVar2,0);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) == param_2)) {
        return iVar1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(*(int *)(param_1 + 0x88) + 0x10));
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x00435600 | Classified: elementclient::Win_Camera@0x435600 */
/* ==================================================================== */

undefined4 __thiscall FUN_00435600(int param_1,uint param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 4) != 0) && (*(int *)(param_1 + 0xc) != 0)) {
    cVar1 = func_0x005aaf50(param_2,param_3,param_4);
    if (cVar1 != '\0') {
      return 1;
    }
    if (param_2 < 0x207) {
      if (param_2 < 0x200) {
        switch(param_2 - 0x100) {
        case 0:
        case 1:
        case 4:
        case 5:
          goto code_r0x00435667;
        default:
          return 0;
        }
      }
    }
    else if (param_2 != 0x20a) {
      return 0;
    }
    cVar1 = func_0x00404c50(param_2,param_3,param_4);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
code_r0x00435667:
  if ((param_2 == 0x101) && (param_3 == 0x2c)) {
    if (*(int *)(param_1 + 8) == 0) {
      return 0;
    }
    iVar2 = func_0x005aafe0();
    if (iVar2 != 0) {
      FUN_0072fb20(0x952870);
      cVar1 = FUN_00735df0();
      if (cVar1 != '\0') {
        func_0x004ceba0();
      }
    }
    func_0x004396e0(1);
    return 0;
  }
  cVar1 = func_0x00404a80(param_2,param_3,param_4);
  if (cVar1 == '\0') {
    return 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00435710 | Classified: ElementClient::proc_435710 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00435710(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 unaff_ESI;
  int unaff_EDI;
  int iVar8;
  undefined1 auStack_28 [12];
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  func_0x00763330();
  func_0x005d07a0();
  if (-1 < *(int *)(param_1 + 0xa0)) {
    func_0x00436cc0(*(int *)(param_1 + 0xa0));
    *(undefined4 *)(param_1 + 0xa0) = 0xffffffff;
  }
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined1 *)(param_1 + 0x9c) = 0;
  }
  else {
    uVar5 = func_0x005aaff0();
    *(undefined1 *)(param_1 + 0x9c) = uVar5;
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    func_0x00404970();
  }
  iVar8 = *(int *)(_DAT_009b3eec + 0x14);
  uVar6 = FUN_004365a0();
  if ((char)uVar6 != '\0') {
    if (*(int *)(param_1 + 4) != 0) {
      func_0x005aaf80();
    }
    func_0x00412090(param_2);
    func_0x006e7ee0(param_2);
    _DAT_009b4198 = _DAT_009b4198 + param_2;
    while (0x1d < _DAT_009b4198) {
      _DAT_009b4198 = _DAT_009b4198 - 0x1e;
      func_0x007846e0();
    }
    _DAT_009b419c = _DAT_009b419c + param_2;
    if (99 < _DAT_009b419c) {
      iVar7 = 0;
      _DAT_009b419c = _DAT_009b419c - 100;
      if (*(int *)(param_1 + 8) != 0) {
        iVar7 = func_0x0042c140();
      }
      if (((*(int *)(param_1 + 0x90) == 2) && (iVar7 != 0)) && (*(char *)(iVar7 + 0x91c) != '\0')) {
        iVar1 = *(int *)(*(int *)(_DAT_009b3eec + 0x14) + 8);
        iVar2 = *(int *)(*(int *)(*(int *)(_DAT_009b3eec + 4) + 0xa1c) + 0x10);
        uStack_1c = 0;
        uVar6 = *(undefined4 *)(iVar1 + 0x50);
        uStack_18 = 0x3f800000;
        fVar3 = *(float *)(iVar1 + 0x54);
        uVar4 = *(undefined4 *)(iVar1 + 0x58);
        uStack_14 = 0;
        if (iVar2 != 0) {
          func_0x00401ca0(*(undefined4 *)(iVar7 + 0x3c),*(undefined4 *)(iVar7 + 0x40),
                          *(undefined4 *)(iVar7 + 0x44));
          *(float *)(iVar2 + 0x34) = fVar3 + _DAT_008d62dc;
          *(undefined4 *)(iVar2 + 0x30) = uVar6;
          *(undefined4 *)(iVar2 + 0x38) = uVar4;
          *(int *)(iVar2 + 0x48) = param_2;
          *(undefined4 *)(iVar2 + 0x50) = unaff_ESI;
          *(int *)(iVar2 + 0x4c) = iVar8;
          func_0x00401cc0(auStack_28);
          FUN_00768100();
        }
      }
      else {
        func_0x00774800();
      }
    }
    func_0x004161e0(param_2);
    if ((*(int *)(param_1 + 0x90) == 2) &&
       (_DAT_009b3f68 = _DAT_009b3f68 + unaff_EDI, _DAT_009b3f6c <= _DAT_009b3f68)) {
      _DAT_009b3f68 = 0;
      func_0x00436d60();
    }
    _DAT_009b3f70 = _DAT_009b3f70 + param_2;
    func_0x005d1a30();
    _DAT_009b4050 = func_0x00763330();
    _DAT_009b4050 = _DAT_009b4050 - iVar8;
    if ((*(int *)(param_1 + 0x90) == 2) && (_DAT_009b3f5c != 0)) {
      _DAT_009b3f50 = _DAT_009b3f50 + 1;
      _DAT_009b3f58 = _DAT_009b3f58 + _DAT_009b4050;
    }
    return CONCAT31((int3)((uint)_DAT_009b4050 >> 8),1);
  }
  return uVar6;
}


/* ==================================================================== */
/* Address: 0x00435a30 | Classified: ElementClient::proc_435a30 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00435a30(void)

{
  _DAT_009b4020 = 0;
  _DAT_009b4024 = 0;
  _DAT_009b4018 = 0;
  _DAT_009b401c = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00435a50 | Classified: ElementClient::proc_435a50 */
/* ==================================================================== */

void FUN_00435a50(void)

{
  func_0x00892e60(&UNK_00435a60);
  return;
}


/* ==================================================================== */
/* Address: 0x00435ad0 | Classified: ElementClient::proc_435ad0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00435ad0(int param_1)

{
  int iVar1;
  
  while( true ) {
    if (DAT_009b3c64 != '\0') {
      return;
    }
    iVar1 = WaitForSingleObject(_DAT_009b4fe8,0);
    if (iVar1 == 0) break;
    if ((*(int *)(param_1 + 0x20) == 0) || (*(char *)(*(int *)(param_1 + 0x20) + 0x91c) == '\0')) {
      DAT_009b41ac = '\0';
    }
    else {
      DAT_009b41ac = '\x01';
    }
    if (DAT_009b41ac == '\0') {
      _DAT_009b41a0 = 0;
      _DAT_009b41a4 = 0;
      _DAT_009b41a8 = 0;
      Sleep(1000);
    }
    else {
      FUN_00435b50();
      Sleep(2000);
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00435b50 | Classified: ElementClient::proc_435b50 */
/* ==================================================================== */

/* WARNING: Removing unreachable block (ram,0x00436036) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00435b50(void)

{
  int *piVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int unaff_EBX;
  uint uVar7;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 uStack_6c;
  undefined4 *puStack_68;
  undefined4 *puStack_64;
  undefined *puStack_60;
  undefined *puStack_5c;
  undefined *puStack_58;
  undefined4 *puStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined *puStack_44;
  undefined *puStack_40;
  undefined *puStack_3c;
  undefined4 *puStack_38;
  undefined4 uStack_34;
  undefined1 uStack_28;
  undefined4 uStack_24;
  undefined1 uStack_20;
  undefined1 uStack_1c;
  undefined1 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a84a8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (_DAT_009b41a4 == 0) {
    _DAT_009b41a4 = GetTickCount();
    iVar5 = 0;
  }
  else {
    iVar4 = GetTickCount();
    iVar5 = iVar4 - _DAT_009b41a4;
    _DAT_009b41a4 = iVar4;
  }
  _DAT_009b41a0 = _DAT_009b41a0 + iVar5;
  if (_DAT_009b3f84 <= _DAT_009b41a0) {
    _DAT_009b41a8 = GetTickCount();
    uVar9 = 0;
    puVar6 = &uStack_6c;
    uStack_6c = 0;
    uVar3 = func_0x006a7430(puVar6,0,0);
    iVar4 = func_0x006a7110(uVar3);
    puStack_60 = (undefined *)0x0;
    puStack_5c = (undefined *)0x0;
    puStack_58 = (undefined *)0x0;
    puStack_64 = (undefined4 *)&UNK_008d6c34;
    uStack_14 = 0;
    if ((unaff_ESI != 0) && (0 < iVar4)) {
      func_0x004327b0(iVar4);
      memmove(puStack_64,unaff_ESI,iVar4);
      puStack_60 = (undefined *)((int)puStack_64 + iVar4);
      FUN_00436050();
      uStack_34 = uVar9;
      func_0x00432800(&puStack_68);
      puStack_40 = &UNK_008d6c80;
      puStack_3c = (undefined *)0x1389;
      uStack_1c = 1;
      func_0x005cfb00(&puStack_40,1);
      func_0x00763260(puVar6);
      puStack_3c = &UNK_008d6c34;
      free(puStack_38);
    }
    _DAT_009b41a0 = 0;
    iVar4 = rand();
    uStack_14 = 0xffffffff;
    puStack_64 = (undefined4 *)&UNK_008d6c34;
    _DAT_009b3f84 = (iVar4 * 30000) / 0x7fff + 30000;
    free(puStack_60);
  }
  func_0x006a28a0();
  EnterCriticalSection(0x9b4558);
  puStack_60 = _DAT_009b4020;
  puStack_5c = _DAT_009b4024;
  if (_DAT_009b4018 == (undefined4 *)0x0) {
    puStack_68 = (undefined4 *)0x0;
    puVar6 = _DAT_009b4018;
    puStack_64 = puStack_68;
    puVar2 = _DAT_009b4024;
  }
  else {
    puStack_64 = (undefined4 *)func_0x00763250((int)_DAT_009b4020 << 2);
    puVar6 = _DAT_009b4018;
    puVar2 = puStack_5c;
    puStack_68 = puStack_64;
  }
  for (; puVar2 != (undefined *)0x0; puVar2 = puVar2 + -1) {
    if (puStack_64 != (undefined4 *)0x0) {
      uVar3 = *puVar6;
      puVar6 = puVar6 + 1;
      *puStack_64 = uVar3;
    }
    puStack_64 = puStack_64 + 1;
  }
  puStack_8 = (undefined *)0x2;
  puVar6 = _DAT_009b4018 + (int)_DAT_009b4024;
  puVar8 = _DAT_009b4018;
  func_0x006e04e0(_DAT_009b4018,puVar6);
  uVar3 = 0x9b4558;
  LeaveCriticalSection(0x9b4558);
  puVar10 = (undefined4 *)0x0;
  if (puStack_68 != (undefined4 *)0x0) {
    do {
      piVar1 = *(int **)(unaff_EBX + (int)puVar10 * 4);
      if (piVar1[2] == unaff_EDI) {
        uVar7 = 0;
        if (piVar1[5] - piVar1[4] >> 4 != 0) {
          iVar4 = 0;
          do {
            iVar5 = *(int *)(iVar4 + 4 + piVar1[4]);
            func_0x0069fea0(iVar5,*(int *)(iVar4 + 8 + piVar1[4]) - iVar5);
            uVar7 = uVar7 + 1;
            iVar4 = iVar4 + 0x10;
          } while (uVar7 < (uint)(piVar1[5] - piVar1[4] >> 4));
        }
        iVar4 = func_0x006a6ec0(&stack0xffffff84);
        puStack_64 = (undefined4 *)0x0;
        puStack_60 = (undefined *)0x0;
        puStack_5c = (undefined *)0x0;
        puStack_68 = (undefined4 *)&UNK_008d6c34;
        uStack_18 = 3;
        if ((unaff_EDI != 0) && (0 < iVar4)) {
          func_0x004327b0(iVar4);
          memmove(puStack_68,unaff_EDI,iVar4);
          puStack_64 = (undefined4 *)((int)puStack_68 + iVar4);
          puStack_5c = &UNK_008d6c54;
          puStack_54 = puVar6;
          func_0x00432800(&uStack_6c);
          puStack_60 = &UNK_008d6c80;
          puStack_5c = (undefined *)0x1389;
          uStack_20 = 4;
          func_0x005cfb00(&puStack_60,1);
          func_0x00763260(uVar3);
          uStack_28 = 3;
          puStack_5c = &UNK_008d6c34;
          free(puStack_58);
          puStack_58 = &UNK_008d6c3c;
        }
        (**(code **)(*piVar1 + 0x18))();
        uStack_18 = 2;
        puStack_68 = (undefined4 *)&UNK_008d6c34;
        free(puStack_64);
      }
      else {
        (**(code **)(*piVar1 + 0x18))();
      }
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    } while (puVar10 < puStack_68);
  }
  iVar4 = 2;
  do {
    iVar5 = func_0x006a6fd0(&stack0xffffff88);
    puStack_54 = (undefined4 *)0x0;
    uStack_50 = 0;
    uStack_4c = 0;
    puStack_58 = &UNK_008d6c34;
    if ((iVar4 != 0) && (0 < iVar5)) {
      func_0x004327b0(iVar5);
      memmove(puStack_58,iVar4,iVar5);
      puStack_54 = (undefined4 *)(puStack_58 + iVar5);
      puStack_40 = &UNK_008d6c54;
      puStack_38 = puVar6;
      func_0x00432800(&puStack_5c);
      puStack_44 = &UNK_008d6c80;
      puStack_40 = (undefined *)0x1389;
      uStack_20 = 6;
      func_0x005cfb00(&puStack_44,1);
      func_0x00763260(puVar8);
      puStack_40 = &UNK_008d6c34;
      free(puStack_3c);
      puStack_3c = &UNK_008d6c3c;
    }
    uStack_18 = 2;
    puStack_58 = &UNK_008d6c34;
    free(puStack_54);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  func_0x006a7ee0();
  uStack_14 = 0xffffffff;
  func_0x006e04e0(unaff_EBX,unaff_EBX + (int)puStack_68 * 4);
  *unaff_FS_OFFSET = uStack_24;
  return;
}


/* ==================================================================== */
/* Address: 0x00436050 | Classified: ElementClient::proc_436050 */
/* ==================================================================== */

void __fastcall FUN_00436050(undefined4 *param_1)

{
  *param_1 = &UNK_008d6c54;
  return;
}


/* ==================================================================== */
/* Address: 0x00436080 | Classified: GNET::Protocol::vfunc_slot_7 */
/* ==================================================================== */

undefined4 FUN_00436080(void)

{
  return 0;
}


/* ==================================================================== */
/* Address: 0x004360a0 | Classified: GNET::ACReport::vfunc_slot_9 */
/* ==================================================================== */

undefined4 __fastcall FUN_004360a0(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}


/* ==================================================================== */
/* Address: 0x004360b0 | Classified: GNET::ACReport::vfunc_slot_5 */
/* ==================================================================== */

undefined4 * __fastcall FUN_004360b0(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  
  puVar3 = (undefined4 *)func_0x00763250(0x1c);
  if (puVar3 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar3 = &UNK_008d6c3c;
  puVar3[1] = *(undefined4 *)(param_1 + 4);
  *puVar3 = &UNK_008d6c54;
  puVar3[2] = *(undefined4 *)(param_1 + 8);
  puVar3[4] = 0;
  puVar3[5] = 0;
  puVar3[6] = 0;
  puVar3[3] = &UNK_008d6c34;
  iVar2 = *(int *)(param_1 + 0x10);
  iVar5 = *(int *)(param_1 + 0x14) - iVar2;
  if (iVar5 != 0) {
    if (iVar5 != 0) {
      uVar1 = iVar5 - 1;
      puVar3[6] = 2;
      while (uVar1 = uVar1 >> 1, uVar1 != 0) {
        puVar3[6] = puVar3[6] << 1;
      }
      uVar4 = realloc(0,puVar3[6]);
      puVar3[4] = uVar4;
      puVar3[5] = uVar4;
    }
    memmove(puVar3[4],iVar2,iVar5);
    puVar3[5] = puVar3[4] + iVar5;
  }
  *puVar3 = &UNK_008d6c80;
  return puVar3;
}


/* ==================================================================== */
/* Address: 0x00436160 | Classified: GNET::ACReport::vfunc_slot_0 */
/* ==================================================================== */

int __thiscall FUN_00436160(int param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uStack_8;
  
  iVar2 = param_2;
  uVar5 = *(uint *)(param_1 + 8);
  uStack_8 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
  iVar7 = *(int *)(param_2 + 8);
  iVar4 = *(int *)(param_2 + 4);
  iVar6 = iVar7 - iVar4;
  iVar3 = iVar7;
  if (*(uint *)(param_2 + 0xc) < iVar6 + 4U) {
    uVar5 = iVar6 + 3;
    *(undefined4 *)(param_2 + 0xc) = 2;
    while (uVar5 = uVar5 >> 1, uVar5 != 0) {
      *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) << 1;
    }
    puVar1 = (undefined4 *)(param_2 + 0xc);
    param_2 = iVar7;
    iVar3 = realloc(iVar4,*puVar1);
    *(int *)(iVar2 + 4) = iVar3;
    *(int *)(iVar2 + 8) = iVar3 + iVar6;
    iVar3 = param_2;
  }
  param_2 = iVar3;
  if (param_2 == 0) {
    memmove(*(undefined4 *)(iVar2 + 4),&uStack_8,4);
    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 4) + 4;
  }
  else {
    iVar7 = *(int *)(iVar2 + 4) + (iVar7 - iVar4);
    memmove(iVar7 + 4,iVar7,*(int *)(iVar2 + 8) - iVar7);
    memmove(iVar7,&uStack_8,4);
    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 4;
  }
  uVar5 = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10);
  if (uVar5 < 0x80) {
    param_2 = CONCAT13((char)uVar5,(undefined3)param_2);
    func_0x00433030(*(undefined4 *)(iVar2 + 8),(int)&param_2 + 3,1);
  }
  else if (uVar5 < 0x4000) {
    param_2._0_2_ = (ushort)uVar5 | 0x8000;
    param_2 = CONCAT22((short)(uVar5 >> 0x10),(ushort)param_2 >> 8 | (ushort)uVar5 << 8);
    func_0x0043ab10(param_2);
  }
  else {
    if (uVar5 < 0x20000000) {
      param_2 = (uVar5 | 0xc0000000) >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 |
                uVar5 * 0x1000000;
    }
    else {
      func_0x0043aa60(0xe0);
      param_2 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 * 0x1000000;
    }
    func_0x0043abc0(param_2);
  }
  iVar7 = *(int *)(param_1 + 0x10);
  param_2 = *(int *)(iVar2 + 8);
  iVar4 = *(int *)(iVar2 + 4);
  iVar6 = *(int *)(param_1 + 0x14) - iVar7;
  iVar3 = param_2 - iVar4;
  uStack_8 = param_2 - iVar4;
  uVar5 = iVar3 + iVar6;
  if (*(uint *)(iVar2 + 0xc) < uVar5) {
    uVar5 = uVar5 - 1;
    *(undefined4 *)(iVar2 + 0xc) = 2;
    while (uVar5 = uVar5 >> 1, uVar5 != 0) {
      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) << 1;
    }
    iVar4 = realloc(iVar4,*(undefined4 *)(iVar2 + 0xc));
    *(int *)(iVar2 + 4) = iVar4;
    *(int *)(iVar2 + 8) = iVar4 + iVar3;
  }
  if (param_2 == 0) {
    memmove(*(undefined4 *)(iVar2 + 4),iVar7,iVar6);
    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 4) + iVar6;
    return iVar2;
  }
  iVar4 = *(int *)(iVar2 + 4) + uStack_8;
  memmove(iVar4 + iVar6,iVar4,*(int *)(iVar2 + 8) - iVar4);
  memmove(iVar4,iVar7,iVar6);
  *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + iVar6;
  return iVar2;
}


/* ==================================================================== */
/* Address: 0x00436370 | Classified: GNET::ACReport::vfunc_slot_1 */
/* ==================================================================== */

uint __thiscall FUN_00436370(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int extraout_ECX;
  int extraout_ECX_00;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  ushort uStack_8;
  
  uVar2 = param_2;
  iVar3 = *(int *)(param_2 + 0x10);
  uVar7 = CONCAT44(iVar3 + 4U,*(int *)(param_2 + 4));
  if ((uint)(*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) < iVar3 + 4U) {
    uVar7 = func_0x00892f12((int)&param_2 + 3,&UNK_009164f8);
    iVar3 = extraout_ECX;
  }
  uVar6 = *(uint *)(iVar3 + (int)uVar7);
  *(int *)(uVar2 + 0x10) = (int)((ulonglong)uVar7 >> 0x20);
  *(uint *)(param_1 + 8) =
       uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18;
  iVar3 = *(int *)(uVar2 + 4);
  iVar5 = *(int *)(uVar2 + 0x10);
  if (iVar5 == *(int *)(uVar2 + 8) - iVar3) {
    iVar3 = func_0x00892f12((int)&param_2 + 3,&UNK_009164f8);
    iVar5 = extraout_ECX_00;
  }
  switch(*(byte *)(iVar5 + iVar3) & 0xe0) {
  case 0x80:
  case 0xa0:
    func_0x0043a9c0(&param_2);
    uStack_8 = (ushort)param_2;
    uVar6 = (uint)(ushort)(uStack_8 >> 8 | (uStack_8 & 0x7f) << 8);
    break;
  case 0xc0:
    func_0x0043aa10(&param_2);
    uVar6 = param_2 >> 0x18 | (param_2 & 0xff0000) >> 8 | (param_2 & 0xff00) << 8 |
            (param_2 & 0x3f) << 0x18;
    break;
  case 0xe0:
    func_0x0043a980((int)&param_2 + 3);
    func_0x0043aa10(&param_2);
    uVar6 = param_2 >> 0x18 | (param_2 & 0xff0000) >> 8 | (param_2 & 0xff00) << 8 | param_2 << 0x18;
    break;
  default:
    func_0x0043a980(&param_2);
    uVar6 = param_2 & 0xff;
  }
  iVar3 = *(int *)(uVar2 + 4);
  if ((uint)(*(int *)(uVar2 + 8) - iVar3) < *(int *)(uVar2 + 0x10) + uVar6) {
    iVar3 = func_0x00892f12((int)&param_2 + 3,&UNK_009164f8);
  }
  iVar5 = *(int *)(uVar2 + 0x10);
  if (*(uint *)(param_1 + 0x18) < uVar6) {
    uVar1 = uVar6 - 1;
    *(undefined4 *)(param_1 + 0x18) = 2;
    while (uVar1 = uVar1 >> 1, uVar1 != 0) {
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) << 1;
    }
    param_2 = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10);
    iVar4 = realloc(*(int *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x18));
    *(int *)(param_1 + 0x10) = iVar4;
    *(uint *)(param_1 + 0x14) = iVar4 + param_2;
  }
  memmove(*(undefined4 *)(param_1 + 0x10),iVar5 + iVar3,uVar6);
  *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x10) + uVar6;
  *(uint *)(uVar2 + 0x10) = *(int *)(uVar2 + 0x10) + uVar6;
  return uVar2;
}


/* ==================================================================== */
/* Address: 0x004365a0 | Classified: ElementClient::proc_4365a0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004365a0(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  bool bVar5;
  undefined4 *puVar6;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(int *)(param_1 + 8) == 0) {
    return 1;
  }
  iVar2 = *(int *)(*(int *)(_DAT_009b3eec + 4) + 0x88);
  puVar6 = (undefined4 *)func_0x007744f0();
  *(undefined4 *)(iVar2 + 0x128) = *puVar6;
  *(undefined4 *)(iVar2 + 300) = puVar6[1];
  *(undefined4 *)(iVar2 + 0x130) = puVar6[2];
  piVar3 = *(int **)(param_1 + 0x20);
  if ((piVar3 == (int *)0x0) || ((char)piVar3[0x247] == '\0')) {
    bVar5 = false;
  }
  else {
    bVar5 = true;
    if ((*(int *)(*(int *)(param_1 + 8) + 8) == 0) ||
       (*(char *)(*(int *)(param_1 + 8) + 0xa4) != '\0')) {
      (**(code **)(*piVar3 + 0x44))(param_2);
    }
  }
  if (*(int *)(param_1 + 0x58) != 0) {
    func_0x005aed60(param_2);
  }
  if ((bVar5) &&
     (((*(int *)(*(int *)(param_1 + 8) + 8) == 0 ||
       (*(char *)(*(int *)(param_1 + 8) + 0xa4) != '\0')) &&
      (iVar2 = *(int *)(param_1 + 0x20), *(char *)(iVar2 + 0xb0f) == '\0')))) {
    uVar1 = *(undefined4 *)(iVar2 + 0x790);
    uStack_14 = *(undefined4 *)(iVar2 + 0x794);
    iVar4 = *(int *)(param_3 + 8);
    uStack_10 = *(undefined4 *)(iVar2 + 0x798);
    *(undefined4 *)(iVar4 + 0x18) = uStack_14;
    *(undefined4 *)(iVar4 + 0x14) = uVar1;
    *(undefined4 *)(iVar4 + 0x1c) = uStack_10;
    func_0x00774140();
    uStack_18 = *(undefined4 *)(iVar2 + 0x770);
    uStack_14 = *(undefined4 *)(iVar2 + 0x774);
    uStack_10 = *(undefined4 *)(iVar2 + 0x778);
    uStack_c = *(undefined4 *)(iVar2 + 0x780);
    uStack_8 = *(undefined4 *)(iVar2 + 0x784);
    uStack_4 = *(undefined4 *)(iVar2 + 0x788);
    func_0x00773d00(&uStack_c,&uStack_18);
  }
  FUN_0042af70(param_2,*(undefined4 *)(_DAT_009b3eec + 0x14));
  return 1;
}


/* ==================================================================== */
/* Address: 0x00436720 | Classified: elementclient::CECGameRun__Render____Failed_to_b@0x436720 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00436720(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iStack_3c;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 auStack_1c [7];
  
  if (*(int *)(param_1 + 8) == 0) {
    return 1;
  }
  iVar2 = func_0x0042c140();
  iStack_3c = *(int *)(_DAT_009b3eec + 0x14);
  iVar3 = *(int *)(_DAT_009b3eec + 8);
  if (((*(int *)(param_1 + 0x90) == 2) && (iVar2 != 0)) && (*(char *)(iVar2 + 0x91c) == '\0')) {
    cVar1 = func_0x00436c00();
    if (cVar1 != '\0') {
      puVar8 = (undefined4 *)(iVar3 + 0x10);
      puVar9 = auStack_1c;
      for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      iStack_28 = auStack_1c[2];
      uStack_34 = 0;
      uStack_30 = 0;
      uStack_2c = auStack_1c[1];
      uStack_24 = 0;
      uStack_20 = 0x3f800000;
      func_0x0077a500(&uStack_34);
      func_0x00779f10(1,0,0x3f800000,0);
      if (*(int *)(param_1 + 4) != 0) {
        func_0x005aafb0();
      }
      func_0x00436c30(auStack_1c[3]);
      return 1;
    }
  }
  else {
    if (((*(char *)(*(int *)(_DAT_009b3eec + 0x18) + 0x90) != '\0') &&
        (*(int *)(param_1 + 0x90) == 2)) && (_DAT_009b3f5c != 0)) {
      if ((_DAT_009b3f50 < 10) && (_DAT_009b3f50 * 0x96 < _DAT_009b3f58 + _DAT_009b3f5c)) {
        return 1;
      }
      _DAT_009b3f58 = 0;
      _DAT_009b3f50 = 0;
    }
    func_0x00763330();
    cVar1 = func_0x00436c00();
    if (cVar1 != '\0') {
      if (*(char *)(*(int *)(_DAT_009b3eec + 0x18) + 0xb7) != '\0') {
        iVar2 = *(int *)(_DAT_009b3eec + 0x14);
        puVar8 = (undefined4 *)(iVar3 + 0x10);
        puVar9 = auStack_1c;
        for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar9 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar9 = puVar9 + 1;
        }
        iVar3 = *(int *)(iVar2 + 4);
        iVar2 = *(int *)(iVar3 + 0x18);
        if (iVar2 != 0) {
          uStack_2c = auStack_1c[1];
          uStack_34 = 0;
          uStack_30 = 0;
          uStack_24 = 0;
          uStack_20 = 0x3f800000;
          iStack_28 = iVar2;
          func_0x0077a500(&uStack_34);
          func_0x00779f10(1,0,0x3f800000,0);
          iStack_3c = *(int *)(iVar3 + 0x18);
          func_0x0077a500(&stack0xffffffb8);
          func_0x00779f10(1,0,0x3f800000,0);
        }
      }
      if (*(int *)(param_1 + 0x1c) != 0) {
        func_0x0040fc80();
        func_0x0040fcc0(*(undefined4 *)(_DAT_009b3eec + 0x490));
      }
      func_0x0043da90(0);
      func_0x00779f10(2,0xff000000,0x3f800000,0);
      if (*(int *)(param_1 + 8) != 0) {
        func_0x0042b220(iStack_3c);
      }
      func_0x004125e0(iStack_3c);
      func_0x007844d0(*(undefined4 *)(iStack_3c + 4),0xffffffff);
      if (*(char *)(_DAT_009d2d64 + 0x18) != '\0') {
        func_0x006e8550();
      }
      FUN_007a6670(*(undefined4 *)(iStack_3c + 4),0);
      FUN_007a52c0();
      FUN_007a6a20(*(undefined4 *)(iStack_3c + 4));
      FUN_007a52c0(1);
      func_0x006e8480(*(undefined4 *)(iStack_3c + 4),0);
      func_0x007ac000();
      func_0x007ac0c0();
      func_0x00778ce0();
      func_0x00778da0();
      if (*(int *)(param_1 + 0x1c) != 0) {
        func_0x0040fce0(*(undefined4 *)(iStack_3c + 4));
      }
      if ((*(int *)(param_1 + 8) != 0) && (*(int *)(*(int *)(param_1 + 8) + 0x38) != 0)) {
        func_0x0077a290(0);
        func_0x0077a320(1);
        func_0x005ad120(iStack_3c);
        func_0x0077a290(1);
        func_0x0077a320(0);
      }
      func_0x00413c30();
      if ((*(int *)(*(int *)(param_1 + 4) + 0xc) == 1) && (iVar3 = func_0x005aafe0(), iVar3 != 0)) {
        func_0x0041a3c0();
        func_0x006e7490();
        func_0x0041a3c0(0,0);
        func_0x006e7580();
      }
      if (*(int *)(param_1 + 4) != 0) {
        func_0x00784480();
        func_0x005aafb0();
      }
      func_0x00416210(iStack_3c);
      if (*(char *)(*(int *)(_DAT_009b3eec + 0x18) + 0x8e) != '\0') {
        func_0x00437680();
      }
      func_0x00436c30(iStack_3c);
      iVar3 = func_0x00763330();
      if (*(int *)(param_1 + 0x90) == 2) {
        _DAT_009b3f60 = _DAT_009b3f60 + iVar3;
        _DAT_009b3f54 = _DAT_009b3f54 + 1;
        if ((int)((-(uint)(_DAT_009b3f5c != 0) & 0x14) + 10) <= _DAT_009b3f54) {
          _DAT_009b3f5c = func_0x00892e78();
          _DAT_009b3f54 = 0;
          _DAT_009b3f60 = 0;
        }
      }
      iVar3 = *(int *)(_DAT_009b3eec + 0x28);
      EnterCriticalSection(iVar3 + 0x200);
      puVar9 = *(undefined4 **)(iVar3 + 0x18c);
      puVar8 = puVar9 + *(int *)(iVar3 + 0x198);
      if (puVar9 != puVar8) {
        puVar4 = puVar8;
        puVar7 = puVar9;
        if (puVar8 < *(undefined4 **)(iVar3 + 400)) {
          do {
            puVar5 = puVar4 + 1;
            *puVar7 = *puVar4;
            puVar4 = puVar5;
            puVar7 = puVar7 + 1;
          } while (puVar5 < *(undefined4 **)(iVar3 + 400));
        }
        iVar2 = (int)puVar8 - (int)puVar9 >> 2;
        *(int *)(iVar3 + 400) = *(int *)(iVar3 + 400) + iVar2 * -4;
        *(int *)(iVar3 + 0x198) = *(int *)(iVar3 + 0x198) - iVar2;
      }
      LeaveCriticalSection(*(int *)(_DAT_009b3eec + 0x28) + 0x200);
      return 1;
    }
  }
  func_0x00764590(1,0x9528bc);
  return 0;
}


