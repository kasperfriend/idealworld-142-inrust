/* Authentic Ghidra 12.1.4 Decompilation — elementclient.exe (PW 1.4.2 Build 2305) */
/* Module: 10_auimanager_auidialog.c */

/* ==================================================================== */
/* Address: 0x0072e3c0 | Classified: AUIManager::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0072e3c0(undefined4 param_1,byte param_2)

{
  FUN_0072e4e0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0072e3e0 | Classified: ElementClient::proc_72e3e0 */
/* ==================================================================== */

void __fastcall FUN_0072e3e0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  puStack_8 = &UNK_008c96f6;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uVar7 = 0;
  iStack_4 = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    do {
      puVar2 = *(undefined4 **)(*(int *)(param_1 + 8) + uVar7 * 4);
      while (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar2;
        iStack_4._1_3_ = (uint3)((uint)iStack_4 >> 8);
        iStack_4._0_1_ = 1;
        func_0x007637f0();
        iStack_4 = (uint)iStack_4._1_3_ << 8;
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
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x0072e4e0 | Classified: ElementClient::proc_72e4e0 */
/* ==================================================================== */

void __fastcall FUN_0072e4e0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int *unaff_FS_OFFSET;
  int iVar2;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008c9774;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  *param_1 = &UNK_008ee9d4;
  uStack_4._0_1_ = 6;
  uStack_4._1_3_ = 0;
  FUN_007315b0();
  uStack_4 = CONCAT31(uStack_4._1_3_,5);
  func_0x006e04e0(param_1[0x30],param_1[0x30] + param_1[0x33] * 4);
  if (param_1[0x30] != 0) {
    func_0x00763260(param_1[0x30]);
  }
  iStack_c._0_1_ = 7;
  func_0x005b5b60();
  iStack_c = CONCAT31(iStack_c._1_3_,4);
  func_0x006e04e0(param_1[0x2a],param_1[0x2a] + param_1[0x2d] * 4);
  if (param_1[0x2a] != 0) {
    func_0x00763260(param_1[0x2a]);
  }
  func_0x005b5b60();
  iVar2 = param_1[0x24];
  func_0x006e04e0(iVar2,iVar2 + param_1[0x27] * 4);
  if (param_1[0x24] != 0) {
    func_0x00763260(param_1[0x24]);
  }
  FUN_007314b0();
  func_0x006e04e0(param_1[0x1e],param_1[0x1e] + param_1[0x21] * 4);
  if (param_1[0x1e] != 0) {
    func_0x00763260(param_1[0x1e]);
  }
  func_0x006e04e0(param_1[0x18],param_1[0x18] + param_1[0x1b] * 4);
  if (param_1[0x18] != 0) {
    func_0x00763260(param_1[0x18]);
  }
  param_1[0x10] = &UNK_008eea04;
  param_1[0x11] = &UNK_008d649c;
  func_0x00421ca0();
  puVar1 = (undefined4 *)param_1[0x17];
  while (puVar1 != (undefined4 *)0x0) {
    param_1[0x17] = puVar1[1];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    puVar1 = (undefined4 *)param_1[0x17];
  }
  param_1[8] = &UNK_008eea04;
  param_1[9] = &UNK_008d649c;
  func_0x00421ca0();
  puVar1 = (undefined4 *)param_1[0xf];
  while (puVar1 != (undefined4 *)0x0) {
    param_1[0xf] = puVar1[1];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    puVar1 = (undefined4 *)param_1[0xf];
  }
  *unaff_FS_OFFSET = iVar2;
  return;
}


/* ==================================================================== */
/* Address: 0x0072e6c0 | Classified: AUIManager::vfunc_slot_1 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0072e6c0(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  char *pcVar8;
  char *pcVar9;
  int *unaff_FS_OFFSET;
  char acStack_12c [264];
  int iStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008c97aa;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  *(undefined4 *)(param_1 + 4) = param_2;
  *(int *)(param_1 + 8) = param_3;
  puVar7 = (undefined4 *)(param_3 + 0x10);
  pcVar3 = acStack_12c;
  for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined4 *)pcVar3 = *puVar7;
    puVar7 = puVar7 + 1;
    pcVar3 = pcVar3 + 4;
  }
  FUN_00731100(acStack_12c[0] == '\0');
  CreateCaret(*(undefined4 *)(*(int *)(param_1 + 8) + 4),0,1,10);
  iVar4 = func_0x00763250(0x40);
  uStack_14 = 0;
  if (iVar4 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x0075de80();
  }
  uStack_14 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1c) = uVar2;
  cVar1 = func_0x0075e430(*(undefined4 *)(param_1 + 8),0x97f744);
  iVar4 = iStack_c;
  if (cVar1 == '\0') {
    uVar2 = func_0x00739700(0x74,1,0x97f70c);
    goto LAB_0072e975;
  }
  if (iStack_c != 0) {
    cVar1 = FUN_0072f160(iStack_c);
    if (cVar1 == '\0') {
      uVar2 = func_0x00739700(0x79,1,0x97f6d4);
      goto LAB_0072e975;
    }
    func_0x0076ee80(iVar4,acStack_12c,0x104);
    pcVar3 = (char *)strrchr(acStack_12c,0x2e);
    if (pcVar3 != (char *)0x0) {
      uVar5 = 0xffffffff;
      pcVar8 = (char *)0x97f6c4;
      do {
        pcVar9 = pcVar8;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar9 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar9;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      pcVar8 = pcVar9 + -uVar5;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar3 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar3 = pcVar3 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar3 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar3 = pcVar3 + 1;
      }
    }
    iVar4 = func_0x00763250(0x14);
    uStack_20 = 1;
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_00752d70();
    }
    uStack_20 = 0xffffffff;
    *(int *)(param_1 + 0xec) = iVar4;
    if (iVar4 == 0) {
      uVar2 = func_0x00739700(0x81,1,0x97f69c);
      goto LAB_0072e975;
    }
    cVar1 = FUN_00752dc0(uStack_18,param_3,acStack_12c);
    if ((cVar1 == '\0') && (*(int *)(param_1 + 0xec) != 0)) {
      FUN_00753080();
      if (*(undefined4 **)(param_1 + 0xec) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(param_1 + 0xec))(1);
      }
      *(undefined4 *)(param_1 + 0xec) = 0;
    }
  }
  uVar2 = FUN_0072ef30(1,0,0);
  uVar2 = FUN_0072ef30(2,uVar2);
  iVar4 = _wtoi(uVar2);
  iVar4 = func_0x0075e6e0((float)iVar4);
  *(int *)(param_1 + 0x10) = iVar4;
  if (iVar4 == 0) {
    uVar2 = func_0x00739700(0x89,1,0x97f658);
  }
  else {
    if (_DAT_009c1328 != 0) {
      iVar4 = func_0x0075e6e0(_DAT_008ee9cc,&DAT_009c1328,0,0);
      *(int *)(param_1 + 0x14) = iVar4;
      if (iVar4 == 0) {
        uVar2 = func_0x00739700(0x8e,1,0x97f658);
        goto LAB_0072e975;
      }
    }
    iVar4 = func_0x00763250(0x7c);
    uStack_1c = 2;
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = func_0x0075b750();
    }
    uStack_1c = 0xffffffff;
    *(int *)(param_1 + 0xc) = iVar4;
    if (iVar4 == 0) {
      uVar2 = func_0x00739700(0x92,1,0x97f69c);
    }
    else {
      uVar2 = 1;
    }
  }
LAB_0072e975:
  *unaff_FS_OFFSET = iStack_24;
  return uVar2;
}


/* ==================================================================== */
/* Address: 0x0072e990 | Classified: AUIManager::vfunc_slot_2 */
/* ==================================================================== */

undefined4 __fastcall FUN_0072e990(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  
  piVar7 = (int *)0x0;
  FUN_00731100(0);
  puVar1 = *(undefined4 **)(param_1 + 0x28);
  while (puVar1 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x28) = *puVar1;
    FUN_0077fd10(puVar1);
    puVar1 = *(undefined4 **)(param_1 + 0x28);
  }
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  puVar1 = *(undefined4 **)(param_1 + 0x48);
  while (puVar1 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x48) = *puVar1;
    FUN_0077fd10(puVar1);
    puVar1 = *(undefined4 **)(param_1 + 0x48);
  }
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  iVar9 = 0;
  if (0 < *(int *)(param_1 + 0x6c)) {
    do {
      piVar10 = *(int **)(*(int *)(param_1 + 0x60) + iVar9 * 4);
      if (piVar10 != (int *)0x0) {
        (**(code **)(*piVar10 + 0xc))();
        piVar10 = *(int **)(*(int *)(param_1 + 0x60) + iVar9 * 4);
        if (piVar10 != (int *)0x0) {
          (**(code **)(*piVar10 + 0x18))(1);
        }
        *(undefined4 *)(*(int *)(param_1 + 0x60) + iVar9 * 4) = 0;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < *(int *)(param_1 + 0x6c));
  }
  puVar2 = *(undefined4 **)(param_1 + 0x60);
  puVar1 = puVar2 + *(int *)(param_1 + 0x6c);
  if (puVar2 != puVar1) {
    puVar4 = puVar1;
    puVar6 = puVar2;
    if (puVar1 < *(undefined4 **)(param_1 + 100)) {
      do {
        puVar5 = puVar4 + 1;
        *puVar6 = *puVar4;
        puVar4 = puVar5;
        puVar6 = puVar6 + 1;
      } while (puVar5 < *(undefined4 **)(param_1 + 100));
    }
    iVar9 = (int)puVar1 - (int)puVar2 >> 2;
    *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + iVar9 * -4;
    *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) - iVar9;
  }
  uVar8 = 0;
  if (*(int *)(param_1 + 0x84) != 0) {
    do {
      piVar10 = *(int **)(*(int *)(param_1 + 0x78) + uVar8 * 4);
      if (piVar10 != piVar7) {
        do {
          piVar7 = (int *)*piVar10;
          FUN_00731680(0);
          func_0x00763260(piVar10);
          piVar10 = piVar7;
        } while (piVar7 != (int *)0x0);
      }
      uVar8 = uVar8 + 1;
      *(int **)(*(int *)(param_1 + 0x78) + -4 + uVar8 * 4) = piVar7;
    } while (uVar8 < *(uint *)(param_1 + 0x84));
  }
  *(int **)(param_1 + 0x74) = piVar7;
  uVar8 = 0;
  if (piVar7 < *(int **)(param_1 + 0x9c)) {
    do {
      piVar10 = *(int **)(*(int *)(param_1 + 0x90) + uVar8 * 4);
      while (piVar10 != piVar7) {
        piVar3 = (int *)*piVar10;
        func_0x00763260(piVar10);
        piVar10 = piVar3;
      }
      uVar8 = uVar8 + 1;
      *(int **)(*(int *)(param_1 + 0x90) + -4 + uVar8 * 4) = piVar7;
    } while (uVar8 < *(uint *)(param_1 + 0x9c));
  }
  *(int **)(param_1 + 0x8c) = piVar7;
  uVar8 = 0;
  if (piVar7 < *(int **)(param_1 + 0xb4)) {
    do {
      piVar10 = *(int **)(*(int *)(param_1 + 0xa8) + uVar8 * 4);
      while (piVar10 != piVar7) {
        piVar3 = (int *)*piVar10;
        func_0x00763260(piVar10);
        piVar10 = piVar3;
      }
      uVar8 = uVar8 + 1;
      *(int **)(*(int *)(param_1 + 0xa8) + -4 + uVar8 * 4) = piVar7;
    } while (uVar8 < *(uint *)(param_1 + 0xb4));
  }
  *(int **)(param_1 + 0xa4) = piVar7;
  uVar8 = 0;
  if (piVar7 < *(int **)(param_1 + 0xcc)) {
    do {
      piVar10 = *(int **)(*(int *)(param_1 + 0xc0) + uVar8 * 4);
      if (piVar10 != piVar7) {
        do {
          piVar7 = (int *)*piVar10;
          func_0x0043c330(0);
          func_0x00763260(piVar10);
          piVar10 = piVar7;
        } while (piVar7 != (int *)0x0);
      }
      uVar8 = uVar8 + 1;
      *(int **)(*(int *)(param_1 + 0xc0) + -4 + uVar8 * 4) = piVar7;
    } while (uVar8 < *(uint *)(param_1 + 0xcc));
  }
  *(int **)(param_1 + 0xbc) = piVar7;
  if (*(int **)(param_1 + 0xec) != piVar7) {
    FUN_00753080();
    if (*(int **)(param_1 + 0xec) != piVar7) {
      (**(code **)**(int **)(param_1 + 0xec))(1);
    }
    *(int **)(param_1 + 0xec) = piVar7;
  }
  if (*(int **)(param_1 + 0x1c) != piVar7) {
    func_0x0075e510();
    piVar10 = *(int **)(param_1 + 0x1c);
    if (piVar10 != piVar7) {
      FUN_007316f0();
      func_0x00763260(piVar10);
    }
    *(int **)(param_1 + 0x1c) = piVar7;
  }
  if (*(int **)(param_1 + 0xc) != piVar7) {
    (**(code **)**(int **)(param_1 + 0xc))(1);
  }
  *(int **)(param_1 + 0xc) = piVar7;
  return 1;
}


/* ==================================================================== */
/* Address: 0x0072ebf0 | Classified: elementclient::Interfaces__s@0x72ebf0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0072ebf0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int extraout_ECX;
  uint uVar8;
  uint uVar9;
  undefined *unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  uint in_stack_00001138;
  uint in_stack_0000113c;
  undefined4 in_stack_00001144;
  undefined1 *puStack_20;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  uStack_c = *unaff_FS_OFFSET;
  puStack_8 = &UNK_008c9819;
  *unaff_FS_OFFSET = &uStack_c;
  func_0x00892f20();
  puStack_20 = (undefined1 *)0x72ec21;
  func_0x0076ded0();
  sprintf(&stack0x0000002c,0x97f798);
  puStack_20 = &stack0x0000002c;
  cVar3 = func_0x0076e030();
  if (cVar3 == '\0') {
    func_0x0076df10();
    uVar4 = 0;
  }
  else {
    if (in_stack_0000113c < in_stack_00001138) {
      do {
        cVar3 = func_0x0076e120(1);
        if (cVar3 == '\0') break;
        _wtoi(&stack0x00000130);
        cVar3 = func_0x0076e120(1);
        if (cVar3 == '\0') {
          uVar4 = func_0x00739700(0xd0,1,0x97f75c);
          func_0x0076df10();
          goto LAB_0072eee1;
        }
        FUN_00743ef0();
        uVar5 = FUN_00743f60(&stack0x0000012c);
        FUN_00765050(uVar5);
        puStack_8 = unaff_EDI;
        FUN_00765000(&stack0xffffffe8);
        uVar8 = *(uint *)(extraout_ECX + 0xcc);
        uVar6 = *(int *)(extraout_ECX + 0xbc) + 1;
        if ((uVar8 < uVar6) && (uVar6 = func_0x00404700(uVar6), uVar8 < uVar6)) {
          uVar9 = 0;
          func_0x005b0ea0(uVar6,&stack0xfffffff0);
          if (uVar8 != 0) {
            do {
              puVar1 = (undefined4 *)(*(int *)(extraout_ECX + 0xc0) + uVar9 * 4);
              puVar2 = *(undefined4 **)(*(int *)(extraout_ECX + 0xc0) + uVar9 * 4);
              while (puVar2 != (undefined4 *)0x0) {
                uVar6 = puVar2[3];
                *puVar1 = *puVar2;
                *puVar2 = *(undefined4 *)(iStack_4 + (uVar6 % (uint)unaff_EDI) * 4);
                *(undefined4 **)(iStack_4 + (uVar6 % (uint)unaff_EDI) * 4) = puVar2;
                puVar1 = (undefined4 *)(*(int *)(extraout_ECX + 0xc0) + uVar9 * 4);
                puVar2 = *(undefined4 **)(*(int *)(extraout_ECX + 0xc0) + uVar9 * 4);
              }
              uVar9 = uVar9 + 1;
            } while (uVar9 < uVar8);
          }
          func_0x004bb3b0(&iStack_4);
          func_0x004060e0();
        }
        uVar8 = (uint)puStack_20 % *(uint *)(extraout_ECX + 0xcc);
        puVar1 = *(undefined4 **)(*(int *)(extraout_ECX + 0xc0) + uVar8 * 4);
        for (puVar2 = puVar1; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
          if ((undefined1 *)puVar2[3] == puStack_20) goto LAB_0072ee50;
        }
        iVar7 = func_0x00763250(0x10);
        if (iVar7 == 0) {
          uVar5 = 0;
        }
        else {
          uVar5 = func_0x004c2040(&puStack_20,&uStack_c,puVar1);
        }
        *(undefined4 *)(*(int *)(extraout_ECX + 0xc0) + uVar8 * 4) = uVar5;
        *(int *)(extraout_ECX + 0xbc) = *(int *)(extraout_ECX + 0xbc) + 1;
LAB_0072ee50:
        FUN_00765200();
        in_stack_0000113c = CONCAT31((int3)(in_stack_0000113c >> 8),2);
        FUN_00765200();
        FUN_007652d0(&stack0xffffffe8);
        FUN_00765200();
        in_stack_00001138 = in_stack_00001138 & 0xffffff00;
        FUN_00743f10();
      } while (in_stack_0000113c < in_stack_00001138);
    }
    func_0x0076e0f0();
    func_0x0076df10();
    uVar4 = 1;
  }
LAB_0072eee1:
  *unaff_FS_OFFSET = in_stack_00001144;
  return uVar4;
}


/* ==================================================================== */
/* Address: 0x0072ef30 | Classified: ElementClient::proc_72ef30 */
/* ==================================================================== */

undefined4 FUN_0072ef30(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_007312e0(&stack0x00000004);
  return *puVar1;
}


/* ==================================================================== */
/* Address: 0x0072ef50 | Classified: elementclient::AList2__AllocNode__Not_enough_me@0x72ef50 */
/* ==================================================================== */

int __thiscall FUN_0072ef50(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 unaff_EBX;
  uint uVar9;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008c983b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  func_0x007636b0(param_4);
  iVar3 = (**(code **)(*param_1 + 0x28))();
  uVar9 = 0;
  if (iVar3 == 0) {
    iVar3 = -1;
    goto LAB_0072f0e0;
  }
  if (param_1[0xc] == 0) {
    iVar4 = func_0x00763250(0x10);
    uStack_c = 0;
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = func_0x006c9840(param_1[0xe]);
    }
    uStack_c = 0xffffffff;
    if (iVar4 != 0) {
      param_1[0xc] = *(int *)(iVar4 + 8);
      *(int *)(iVar4 + 4) = param_1[0xf];
      param_1[0xf] = iVar4;
      goto LAB_0072eff0;
    }
    func_0x00764590(1,0x950554);
    piVar5 = (int *)0x0;
  }
  else {
LAB_0072eff0:
    piVar5 = (int *)param_1[0xc];
    iVar4 = *piVar5;
    param_1[0xd] = param_1[0xd] + 1;
    param_1[0xc] = iVar4;
    *piVar5 = 0;
    piVar5[1] = 0;
  }
  piVar5[2] = iVar3;
  piVar5[1] = param_1[0xb];
  if ((undefined4 *)param_1[0xb] == (undefined4 *)0x0) {
    param_1[10] = (int)piVar5;
  }
  else {
    *(undefined4 *)param_1[0xb] = piVar5;
  }
  param_1[0xb] = (int)piVar5;
  uVar1 = param_1[0x1b];
  if (uVar1 == param_1[0x1a]) {
    if (uVar1 + 1 < 5) {
      param_2 = 5;
    }
    else {
      param_2 = uVar1 + 3 + (uVar1 >> 1);
    }
    puVar6 = (undefined4 *)func_0x00763250(param_2 * 4);
    puVar8 = (undefined4 *)param_1[0x18];
    puVar7 = puVar6;
    if (param_1[0x1b] != 0) {
      do {
        if (puVar7 != (undefined4 *)0x0) {
          uVar2 = *puVar8;
          puVar8 = puVar8 + 1;
          *puVar7 = uVar2;
        }
        uVar9 = uVar9 + 1;
        puVar7 = puVar7 + 1;
      } while (uVar9 < (uint)param_1[0x1b]);
    }
    if (param_1[0x18] != 0) {
      func_0x00763260(param_1[0x18]);
    }
    param_1[0x1a] = param_2;
    param_1[0x18] = (int)puVar6;
    param_1[0x19] = (int)(puVar6 + param_1[0x1b]);
  }
  if ((int *)param_1[0x19] != (int *)0x0) {
    *(int *)param_1[0x19] = iVar3;
  }
  param_1[0x1b] = param_1[0x1b] + 1;
  param_1[0x19] = param_1[0x19] + 4;
  func_0x0075c360(uStack_4);
  func_0x00699630(uStack_4);
  FUN_00737fe0(param_1);
  iVar3 = param_1[0x1b] + -1;
LAB_0072f0e0:
  *unaff_FS_OFFSET = unaff_EBX;
  return iVar3;
}


/* ==================================================================== */
/* Address: 0x0072f100 | Classified: ElementClient::proc_72f100 */
/* ==================================================================== */

int __thiscall FUN_0072f100(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 unaff_EBP;
  
  iVar2 = FUN_0072ef50(param_2,param_3,param_4);
  if (iVar2 == -1) {
    return -1;
  }
  cVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 0x60) + iVar2 * 4) + 8))
                    (unaff_EBP,param_3,param_4);
  if (cVar1 == '\0') {
    return -1;
  }
  return iVar2;
}


/* ==================================================================== */
/* Address: 0x0072f160 | Classified: elementclient::AUIManager__LoadDialogLayout____f@0x72f160 */
/* ==================================================================== */

undefined1 __thiscall FUN_0072f160(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined1 uVar4;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 unaff_EBX;
  uint uVar9;
  char *pcVar10;
  char *pcVar11;
  uint *unaff_FS_OFFSET;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined4 uStack_948;
  undefined4 uStack_944;
  undefined1 auStack_92c [2052];
  uint uStack_128;
  uint uStack_124;
  undefined1 auStack_118 [252];
  uint uStack_1c;
  uint uStack_10;
  uint uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  puStack_8 = &UNK_008c9866;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (uint)&uStack_c;
  uStack_944 = param_2;
  uStack_948 = 0x72f192;
  func_0x007636b0();
  puStack_8 = (undefined *)0x0;
  uStack_948 = 0x72f1a4;
  cVar3 = FUN_0072f4f0();
  if (cVar3 == '\0') {
    uStack_948 = 0x97f82c;
    uVar4 = func_0x00739700(0x104,1);
    puStack_8 = (undefined *)0xffffffff;
    uStack_948 = 0x72f1d2;
    func_0x007637f0();
  }
  else {
    uVar9 = 0;
    if (*(int *)(param_1 + 0xcc) != 0) {
      do {
        puVar2 = *(undefined4 **)(*(int *)(param_1 + 0xc0) + uVar9 * 4);
        while (puVar2 != (undefined4 *)0x0) {
          puVar1 = (undefined4 *)*puVar2;
          uStack_948 = 0;
          func_0x0043c330();
          func_0x00763260(puVar2);
          puVar2 = puVar1;
        }
        uVar9 = uVar9 + 1;
        *(undefined4 *)(*(int *)(param_1 + 0xc0) + -4 + uVar9 * 4) = 0;
      } while (uVar9 < *(uint *)(param_1 + 0xcc));
    }
    *(undefined4 *)(param_1 + 0xbc) = 0;
    uStack_948 = 0x72f238;
    func_0x00763cf0();
    uStack_948 = 0x950994;
    pcVar5 = (char *)strstr(unaff_EBX);
    uVar9 = 0xffffffff;
    pcVar10 = (char *)0x97f824;
    do {
      pcVar11 = pcVar10;
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      pcVar11 = pcVar10 + 1;
      cVar3 = *pcVar10;
      pcVar10 = pcVar11;
    } while (cVar3 != '\0');
    uVar9 = ~uVar9;
    pcVar10 = pcVar11 + -uVar9;
    for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *pcVar5 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar5 = pcVar5 + 1;
    }
    uStack_948 = unaff_EBX;
    FUN_0072ebf0();
    iVar6 = iStack_4;
    if (iStack_4 != 0) {
      func_0x0076f270();
      uStack_c = CONCAT31(uStack_c._1_3_,1);
      sprintf(auStack_118,0x97f798,iVar6);
      puVar13 = auStack_118;
      cVar3 = func_0x0076f390(puVar13);
      if (cVar3 == '\0') {
        uVar4 = func_0x00739700(0x116,1,0x97f7e4,iVar6);
        uStack_10 = uStack_10 & 0xffffff00;
        func_0x0076f2b0();
        uStack_10 = 0xffffffff;
        func_0x007637f0();
        goto LAB_0072f4aa;
      }
      if (uStack_124 < uStack_128) {
        do {
          cVar3 = func_0x0076f4a0(1);
          if (cVar3 == '\0') break;
          iVar6 = _strcmpi(auStack_92c,0x952284);
          if ((iVar6 == 0) || (iVar6 = _strcmpi(auStack_92c,0x952280), iVar6 == 0)) {
            func_0x0076f760();
          }
          else {
            puVar12 = auStack_92c;
            iVar6 = FUN_0072f100(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),puVar12);
            if (iVar6 == -1) {
              uStack_1c = uStack_1c & 0xffffff00;
              func_0x0076f2b0();
              uStack_1c = 0xffffffff;
              func_0x007637f0();
              uVar4 = 0;
              goto LAB_0072f4aa;
            }
            cVar3 = func_0x0076f4a0(1);
            if (cVar3 == '\0') {
              uVar7 = 0x129;
            }
            else {
              uStack_948 = atoi(&stack0xfffff6c4);
              cVar3 = func_0x0076f4a0(1);
              if (cVar3 == '\0') {
                uVar7 = 300;
              }
              else {
                uStack_944 = atoi(&stack0xfffff6c4);
                FUN_00735630(&uStack_948,&uStack_944);
                FUN_007354f0(puVar12,puVar13,0,0,0);
                cVar3 = func_0x0076f4a0(1);
                if (cVar3 != '\0') {
                  iVar6 = atoi(&stack0xfffff6c4,0,1);
                  FUN_00735c50(iVar6 != 0);
                  goto LAB_0072f464;
                }
                uVar7 = 0x133;
              }
            }
            func_0x00739700(uVar7,1,0x97f7a8);
          }
LAB_0072f464:
        } while (uStack_124 < uStack_128);
      }
      func_0x0076f450();
      uStack_10 = uStack_10 & 0xffffff00;
      func_0x0076f2b0();
    }
    uStack_c = 0xffffffff;
    func_0x007637f0();
    uVar4 = 1;
  }
LAB_0072f4aa:
  *unaff_FS_OFFSET = uStack_10;
  return uVar4;
}


/* ==================================================================== */
/* Address: 0x0072f4f0 | Classified: ElementClient::proc_72f4f0 */
/* ==================================================================== */

undefined4 __fastcall FUN_0072f4f0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  
  piVar6 = (int *)0x0;
  iVar8 = 0;
  if (0 < *(int *)(param_1 + 0x6c)) {
    do {
      piVar9 = *(int **)(*(int *)(param_1 + 0x60) + iVar8 * 4);
      if (piVar9 != (int *)0x0) {
        (**(code **)(*piVar9 + 0xc))();
        piVar9 = *(int **)(*(int *)(param_1 + 0x60) + iVar8 * 4);
        if (piVar9 != (int *)0x0) {
          (**(code **)(*piVar9 + 0x18))(1);
        }
        *(undefined4 *)(*(int *)(param_1 + 0x60) + iVar8 * 4) = 0;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(param_1 + 0x6c));
  }
  puVar2 = *(undefined4 **)(param_1 + 0x60);
  puVar1 = puVar2 + *(int *)(param_1 + 0x6c);
  if (puVar2 != puVar1) {
    puVar3 = puVar1;
    puVar5 = puVar2;
    if (puVar1 < *(undefined4 **)(param_1 + 100)) {
      do {
        puVar4 = puVar3 + 1;
        *puVar5 = *puVar3;
        puVar3 = puVar4;
        puVar5 = puVar5 + 1;
      } while (puVar4 < *(undefined4 **)(param_1 + 100));
    }
    iVar8 = (int)puVar1 - (int)puVar2 >> 2;
    *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + iVar8 * -4;
    *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) - iVar8;
  }
  uVar7 = 0;
  if (*(int *)(param_1 + 0x84) != 0) {
    do {
      piVar9 = *(int **)(*(int *)(param_1 + 0x78) + uVar7 * 4);
      if (piVar9 != piVar6) {
        do {
          piVar6 = (int *)*piVar9;
          FUN_00731680(0);
          func_0x00763260(piVar9);
          piVar9 = piVar6;
        } while (piVar6 != (int *)0x0);
      }
      uVar7 = uVar7 + 1;
      *(int **)(*(int *)(param_1 + 0x78) + -4 + uVar7 * 4) = piVar6;
    } while (uVar7 < *(uint *)(param_1 + 0x84));
  }
  *(int **)(param_1 + 0x74) = piVar6;
  piVar9 = *(int **)(param_1 + 0x28);
  while (piVar9 != piVar6) {
    *(int *)(param_1 + 0x28) = *piVar9;
    *piVar9 = *(int *)(param_1 + 0x30);
    *(int **)(param_1 + 0x30) = piVar9;
    piVar9 = *(int **)(param_1 + 0x28);
    *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + -1;
  }
  *(int **)(param_1 + 0x2c) = piVar6;
  *(int **)(param_1 + 0x34) = piVar6;
  piVar9 = *(int **)(param_1 + 0x48);
  while (piVar9 != piVar6) {
    *(int *)(param_1 + 0x48) = *piVar9;
    *piVar9 = *(int *)(param_1 + 0x50);
    *(int **)(param_1 + 0x50) = piVar9;
    piVar9 = *(int **)(param_1 + 0x48);
    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + -1;
  }
  *(int **)(param_1 + 0x4c) = piVar6;
  *(int **)(param_1 + 0x54) = piVar6;
  return CONCAT31((int3)((uint)piVar9 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x0072f610 | Classified: ElementClient::proc_72f610 */
/* ==================================================================== */

undefined4 __thiscall FUN_0072f610(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar5;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008c9878;
  *unaff_FS_OFFSET = &uStack_c;
  if ((param_2 < 0) || (*(int *)(param_1 + 0x6c) <= param_2)) {
    uVar3 = 0;
  }
  else {
    param_2 = param_2 * 4;
    FUN_00735c50(0,0,1);
    iVar1 = FUN_00737ec0();
    if (iVar1 < 1) {
      piVar2 = *(int **)(param_1 + 0x48);
      if (piVar2 != (int *)0x0) {
        do {
          if (piVar2[2] == *(int *)(param_2 + *(int *)(param_1 + 0x60))) break;
          piVar2 = (int *)*piVar2;
        } while (piVar2 != (int *)0x0);
      }
    }
    else {
      piVar2 = (int *)FUN_00731480(*(undefined4 *)(param_2 + *(int *)(param_1 + 0x60)),0);
    }
    func_0x006c97a0(piVar2);
    if (*(int *)(param_1 + 0x18) == *(int *)(param_2 + *(int *)(param_1 + 0x60))) {
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    if (*(int *)(param_1 + 0xd4) == *(int *)(param_2 + *(int *)(param_1 + 0x60))) {
      *(undefined4 *)(param_1 + 0xd4) = 0;
      *(undefined4 *)(param_1 + 0xd8) = 0;
    }
    uVar3 = FUN_007359b0();
    func_0x007636b0(uVar3);
    uVar5 = 0;
    FUN_00731510(&stack0xfffffff0);
    uVar3 = 0xffffffff;
    func_0x007637f0();
    piVar2 = *(int **)(param_2 + *(int *)(param_1 + 0x60));
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0xc))(uVar3,uVar5);
      piVar2 = *(int **)(param_2 + *(int *)(param_1 + 0x60));
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x18))(1);
      }
      *(undefined4 *)(param_2 + *(int *)(param_1 + 0x60)) = 0;
    }
    if (*(int *)(param_1 + 0x6c) != 0) {
      puVar4 = (undefined4 *)(param_2 + *(int *)(param_1 + 0x60));
      if (puVar4 < (undefined4 *)(*(int *)(param_1 + 100) + -4)) {
        do {
          *puVar4 = puVar4[1];
          puVar4 = puVar4 + 1;
        } while (puVar4 < (undefined4 *)(*(int *)(param_1 + 100) + -4));
      }
      *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + -1;
      *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + -4;
    }
    uVar3 = 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return uVar3;
}


/* ==================================================================== */
/* Address: 0x0072f780 | Classified: ElementClient::proc_72f780 */
/* ==================================================================== */

uint __thiscall FUN_0072f780(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  uVar3 = *(uint *)(param_1 + 0x6c);
  if (0 < (int)uVar3) {
    do {
      uVar1 = FUN_007359b0();
      iVar2 = _strcmpi(param_2,uVar1);
      if (iVar2 == 0) {
        uVar3 = FUN_0072f610(iVar4);
        return uVar3;
      }
      uVar3 = *(uint *)(param_1 + 0x6c);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)uVar3);
  }
  return uVar3 & 0xffffff00;
}


/* ==================================================================== */
/* Address: 0x0072f7d0 | Classified: ElementClient::proc_72f7d0 */
/* ==================================================================== */

void __thiscall FUN_0072f7d0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  if (param_2 != *(int *)(param_1 + 0x18)) {
    iVar3 = FUN_00737ec0();
    if (iVar3 < 1) {
      for (piVar4 = *(int **)(param_1 + 0x48); (piVar4 != (int *)0x0 && (piVar4[2] != param_2));
          piVar4 = (int *)*piVar4) {
      }
      iVar3 = param_1 + 0x44;
    }
    else {
      for (piVar4 = *(int **)(param_1 + 0x28); (piVar4 != (int *)0x0 && (piVar4[2] != param_2));
          piVar4 = (int *)*piVar4) {
      }
      iVar3 = param_1 + 0x24;
    }
    iVar1 = *piVar4;
    piVar2 = (int *)piVar4[1];
    if (iVar1 == 0) {
      *(int **)(iVar3 + 8) = piVar2;
    }
    else {
      *(int **)(iVar1 + 4) = piVar2;
    }
    if (piVar2 == (int *)0x0) {
      *(int *)(iVar3 + 4) = iVar1;
    }
    else {
      *piVar2 = iVar1;
    }
    *piVar4 = *(int *)(iVar3 + 0xc);
    *(int **)(iVar3 + 0xc) = piVar4;
    *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + -1;
    puVar5 = (undefined4 *)func_0x00419130();
    puVar5[2] = param_2;
    *puVar5 = *(undefined4 *)(iVar3 + 4);
    if (*(int *)(iVar3 + 4) != 0) {
      *(undefined4 **)(*(int *)(iVar3 + 4) + 4) = puVar5;
      *(undefined4 **)(iVar3 + 4) = puVar5;
      *(int *)(param_1 + 0x18) = param_2;
      return;
    }
    *(undefined4 **)(iVar3 + 8) = puVar5;
    *(undefined4 **)(iVar3 + 4) = puVar5;
    *(int *)(param_1 + 0x18) = param_2;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0072f880 | Classified: ElementClient::proc_72f880 */
/* ==================================================================== */

void __thiscall FUN_0072f880(int param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x6c)) {
    do {
      iVar1 = iVar1 + 1;
      *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x60) + -4 + iVar1 * 4) + 0x6c) = param_2;
    } while (iVar1 < *(int *)(param_1 + 0x6c));
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0072f8b0 | Classified: AUIManager::vfunc_slot_3 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0072f8b0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_ESI;
  int iVar4;
  undefined1 **ppuVar5;
  undefined1 *puVar6;
  undefined1 *puStack_1c;
  int iStack_10;
  undefined1 auStack_c [4];
  undefined1 auStack_8 [8];
  
  puStack_1c = auStack_8;
  iVar3 = *(int *)(*(int *)(param_1 + 4) + 0xa8);
  GetCursorPos();
  ScreenToClient(*(undefined4 *)(*(int *)(param_1 + 8) + 4),auStack_c);
  puVar6 = &stack0xffffffe8;
  ppuVar5 = &puStack_1c;
  cVar1 = FUN_00730ce0(unaff_ESI - *(int *)(iVar3 + 0x14),iStack_10 - *(int *)(iVar3 + 0x18),ppuVar5
                       ,puVar6,0);
  if (cVar1 == '\0') {
    uVar2 = func_0x00739700(0x1b3,1,0x97f8e4);
    return uVar2;
  }
  if ((ppuVar5 != *(undefined1 ***)(param_1 + 0xd4)) || (puVar6 != *(undefined1 **)(param_1 + 0xd8))
     ) {
    *(undefined1 ***)(param_1 + 0xd4) = ppuVar5;
    *(undefined1 **)(param_1 + 0xd8) = puVar6;
    uVar2 = GetTickCount();
    *(undefined4 *)(param_1 + 0xd0) = uVar2;
  }
  _DAT_009c1528 = _DAT_009c1528 + 1;
  if (1 < _DAT_009c1528) {
    func_0x0075bb90();
    _DAT_009c1528 = 0;
  }
  iVar3 = *(int *)(param_1 + 0x6c);
  iVar4 = 0;
  if (0 < iVar3) {
    do {
      cVar1 = FUN_007382e0();
      if (cVar1 == '\0') {
        cVar1 = FUN_00735df0();
        if (cVar1 != '\0') {
          cVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 0x60) + iVar4 * 4) + 0x10))();
          if (cVar1 == '\0') {
            uVar2 = func_0x00739700(0x1cf,1,0x97f870,iVar4);
            return uVar2;
          }
        }
      }
      else {
        cVar1 = FUN_0072f610(iVar4);
        if (cVar1 == '\0') {
          uVar2 = func_0x00739700(0x1c8,1,0x97f8ac,iVar4);
          return uVar2;
        }
        iVar4 = iVar4 + -1;
      }
      iVar3 = *(int *)(param_1 + 0x6c);
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x0072fa10 | Classified: AUIManager::vfunc_slot_4 */
/* ==================================================================== */

undefined4 __fastcall FUN_0072fa10(int param_1)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)(param_1 + 0x4c);
  while (iVar1 != 0) {
    piVar2 = *(int **)(iVar1 + 8);
    iVar1 = *(int *)(iVar1 + 4);
    if (((piVar2 != (int *)0x0) && (cVar3 = FUN_00735df0(), cVar3 != '\0')) &&
       (cVar3 = (**(code **)(*piVar2 + 0x14))(), cVar3 == '\0')) {
      uVar4 = func_0x00739700(0x1e3,1,0x97f998);
      return uVar4;
    }
  }
  iVar1 = *(int *)(param_1 + 0x2c);
  while (iVar1 != 0) {
    piVar2 = *(int **)(iVar1 + 8);
    iVar1 = *(int *)(iVar1 + 4);
    if (((piVar2 != (int *)0x0) && (cVar3 = FUN_00735df0(), cVar3 != '\0')) &&
       (cVar3 = (**(code **)(*piVar2 + 0x14))(), cVar3 == '\0')) {
      uVar4 = func_0x00739700(0x1ee,1,0x97f998);
      return uVar4;
    }
  }
  cVar3 = FUN_007308a0();
  if (cVar3 == '\0') {
    uVar4 = func_0x00739700(499,1,0x97f964);
    return uVar4;
  }
  cVar3 = func_0x00784480();
  if (cVar3 == '\0') {
    uVar4 = func_0x00739700(0x1f6,1,0x97f914);
    return uVar4;
  }
  func_0x0075ec80();
  return 1;
}


/* ==================================================================== */
/* Address: 0x0072fb00 | Classified: ElementClient::proc_72fb00 */
/* ==================================================================== */

undefined4 __fastcall FUN_0072fb00(int param_1)

{
  return *(undefined4 *)(param_1 + 0x6c);
}


/* ==================================================================== */
/* Address: 0x0072fb10 | Classified: ElementClient::proc_72fb10 */
/* ==================================================================== */

undefined4 __thiscall FUN_0072fb10(int param_1,int param_2)

{
  return *(undefined4 *)(*(int *)(param_1 + 0x60) + param_2 * 4);
}


/* ==================================================================== */
/* Address: 0x0072fb20 | Classified: ElementClient::proc_72fb20 */
/* ==================================================================== */

undefined4 __thiscall FUN_0072fb20(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_30 [4];
  int iStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_18;
  undefined1 uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008c98b9;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  func_0x007636b0(param_2);
  uVar8 = 0;
  puStack_8 = (undefined *)0x0;
  func_0x00763660(&stack0x00000000);
  uStack_28 = 0;
  uVar5 = *(uint *)(param_1 + 0x84);
  uVar4 = *(int *)(param_1 + 0x74) + 1;
  uStack_c = CONCAT31(uStack_c._1_3_,1);
  if ((uVar5 < uVar4) && (uVar4 = func_0x00404700(uVar4), uVar5 < uVar4)) {
    func_0x005b0ea0(uVar4,&stack0xffffffc8);
    uStack_14 = 2;
    if (uVar5 != 0) {
      do {
        puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x78) + uVar8 * 4);
        while (puVar1 != (undefined4 *)0x0) {
          uVar5 = func_0x004130f0(puVar1[3]);
          *(undefined4 *)(*(int *)(param_1 + 0x78) + uVar8 * 4) = *puVar1;
          *puVar1 = *(undefined4 *)(iStack_2c + (uVar5 % uVar4) * 4);
          *(undefined4 **)(iStack_2c + (uVar5 % uVar4) * 4) = puVar1;
          puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x78) + uVar8 * 4);
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < unaff_ESI);
    }
    func_0x004bb3b0(&iStack_2c);
    uStack_18 = CONCAT31(uStack_18._1_3_,1);
    func_0x004060e0();
  }
  uVar5 = *(uint *)(param_1 + 0x84);
  uVar4 = func_0x004130f0(uStack_4);
  uVar4 = uVar4 % uVar5;
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x78) + uVar4 * 4);
  for (puVar7 = puVar1; puVar7 != (undefined4 *)0x0; puVar7 = (undefined4 *)*puVar7) {
    cVar3 = func_0x00763c50(&puStack_8);
    if (cVar3 != '\0') goto LAB_0072fc87;
  }
  iVar6 = func_0x00763250(0x10);
  uStack_10 = CONCAT31(uStack_10._1_3_,3);
  if (iVar6 == 0) {
    puVar7 = (undefined4 *)0x0;
  }
  else {
    puVar7 = (undefined4 *)FUN_00731610(&puStack_8,auStack_30,puVar1);
  }
  *(undefined4 **)(*(int *)(param_1 + 0x78) + uVar4 * 4) = puVar7;
  *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + 1;
LAB_0072fc87:
  uStack_10 = uStack_10 & 0xffffff00;
  func_0x007637f0();
  uVar2 = puVar7[2];
  uStack_10 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_18;
  return uVar2;
}


/* ==================================================================== */
/* Address: 0x0072fcc0 | Classified: ElementClient::proc_72fcc0 */
/* ==================================================================== */

undefined4 __fastcall FUN_0072fcc0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x18);
}


/* ==================================================================== */
/* Address: 0x0072fcd0 | Classified: AUIManager::vfunc_slot_5 */
/* ==================================================================== */

void FUN_0072fcd0(undefined4 param_1)

{
  func_0x00738890(param_1);
  return;
}


/* ==================================================================== */
/* Address: 0x0072fcf0 | Classified: AUIManager::vfunc_slot_6 */
/* ==================================================================== */

undefined1 FUN_0072fcf0(void)

{
  FUN_007382f0(1);
  return 1;
}


/* ==================================================================== */
/* Address: 0x0072fd00 | Classified: AUIManager::vfunc_slot_8 */
/* ==================================================================== */

void FUN_0072fd00(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_00738750(param_1,param_2,param_3,param_5);
  return;
}


/* ==================================================================== */
/* Address: 0x0072fd20 | Classified: AUIManager::vfunc_slot_7 */
/* ==================================================================== */

undefined1 __thiscall FUN_0072fd20(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  char cVar4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  undefined4 *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  undefined4 uStack_40;
  undefined *puStack_34;
  undefined *puStack_30;
  undefined4 *puStack_2c;
  undefined4 *puStack_28;
  undefined4 *puStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 *puStack_18;
  undefined4 uStack_14;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  puStack_8 = &UNK_008c98d8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined1 *)(param_1 + 0xf0) = 0;
  iStack_48 = param_2;
  iStack_44 = param_2;
  uStack_40 = 0;
  iVar6 = func_0x004fcb10(&iStack_48,&iStack_44);
  if (*(int *)(iVar6 + 4) == 0) {
    iStack_50 = param_2;
    iStack_4c = param_2;
    iStack_48 = 0;
    iVar6 = func_0x004fcb10(&iStack_50,&iStack_4c);
    if (*(int *)(iVar6 + 4) != 0) {
      iVar6 = *(int *)(*(int *)(param_1 + 4) + 0xa8);
      iVar11 = (int)(short)param_2 - *(int *)(iVar6 + 0x14);
      iVar6 = (int)(short)((uint)param_2 >> 0x10) - *(int *)(iVar6 + 0x18);
      if (param_2 == 0x20a) {
        iStack_4c = 0;
        iStack_48 = 0;
        iStack_50 = iVar6;
        ClientToScreen(*(undefined4 *)(*(int *)(param_1 + 8) + 4),&iStack_4c);
        iVar11 = iVar11 - iStack_4c;
        iVar6 = iVar6 - iStack_48;
      }
      iStack_50 = iVar6;
      if ((*(int *)(param_1 + 0x18) == 0) ||
         (((iVar7 = FUN_00738330(), iVar7 == 0 && (cVar4 = FUN_00735e10(), cVar4 == '\0')) &&
          (cVar4 = FUN_00735e20(), cVar4 == '\0')))) {
        puStack_30 = &UNK_008d649c;
        puStack_2c = (undefined4 *)0x0;
        puStack_28 = (undefined4 *)0x0;
        puStack_24 = (undefined4 *)0x0;
        uStack_20 = 0;
        uStack_1c = 10;
        puStack_18 = (undefined4 *)0x0;
        puStack_34 = &UNK_008eea04;
        puVar1 = *(undefined4 **)(param_1 + 0x28);
        iStack_4c = *(int *)(param_1 + 0x18);
        uStack_c = 0;
        puVar3 = puStack_2c;
        puVar8 = puStack_28;
        while (puStack_28 = puVar8, puStack_2c = puVar3, puVar1 != (undefined4 *)0x0) {
          uVar2 = puVar1[2];
          puVar1 = (undefined4 *)*puVar1;
          puVar8 = (undefined4 *)func_0x00419130();
          puVar8[2] = uVar2;
          puVar8[1] = puStack_28;
          puVar3 = puVar8;
          if (puStack_28 != (undefined4 *)0x0) {
            *puStack_28 = puVar8;
            puVar3 = puStack_2c;
          }
        }
        puVar1 = *(undefined4 **)(param_1 + 0x48);
        puVar3 = puStack_2c;
        puVar8 = puStack_28;
        while (puStack_28 = puVar8, puStack_2c = puVar3, puVar3 = puStack_2c,
              puVar1 != (undefined4 *)0x0) {
          uVar2 = puVar1[2];
          puVar1 = (undefined4 *)*puVar1;
          puVar8 = (undefined4 *)func_0x00419130();
          puVar8[2] = uVar2;
          puVar8[1] = puStack_28;
          puVar3 = puVar8;
          if (puStack_28 != (undefined4 *)0x0) {
            *puStack_28 = puVar8;
            puVar3 = puStack_2c;
          }
        }
        do {
          do {
            iVar7 = 0;
            if (puVar3 == (undefined4 *)0x0) goto LAB_0072ffd3;
            iVar7 = puVar3[2];
            puVar3 = (undefined4 *)*puVar3;
          } while (iVar7 == 0);
          piVar9 = (int *)FUN_00737360(&iStack_44);
        } while ((((iVar11 < *piVar9) || (piVar9[2] <= iVar11)) ||
                 ((iStack_50 < piVar9[1] ||
                  ((piVar9[3] <= iStack_50 || (cVar4 = FUN_00735df0(), cVar4 == '\0')))))) ||
                (cVar4 = FUN_007385a0(), cVar4 == '\0'));
        if ((((iStack_4 != 0x200) && (iStack_4 != 0x20a)) && (iStack_4 != 0x202)) &&
           ((iStack_4 != 0x205 && (iStack_4 != 0x208)))) {
          FUN_0072f7d0(iVar7);
        }
LAB_0072ffd3:
        if ((iStack_4c != 0) && (iStack_4c != *(int *)(param_1 + 0x18))) {
          iVar6 = FUN_007354b0();
          if (iVar6 == 2) {
            FUN_00735c50(0,0,1);
            FUN_00734940(0x95baec);
          }
          else {
            FUN_007373a0(0);
          }
        }
        uStack_c = 0xffffffff;
        puStack_34 = &UNK_008eea04;
        puStack_30 = &UNK_008d649c;
        while (puVar1 = puStack_2c, puVar1 != (undefined4 *)0x0) {
          puStack_2c = (undefined4 *)*puVar1;
          *puVar1 = puStack_24;
          puStack_24 = puVar1;
        }
        puStack_28 = (undefined4 *)0x0;
        uStack_20 = 0;
        puStack_2c = (undefined4 *)0x0;
        iVar6 = iStack_50;
        iVar10 = iStack_4;
        while (puVar1 = puStack_18, iStack_50 = iVar6, iStack_4 = iVar10,
              puVar1 != (undefined4 *)0x0) {
          puStack_18 = (undefined4 *)puVar1[1];
          if (puVar1 != (undefined4 *)0x0) {
            (**(code **)*puVar1)(1);
            iVar6 = iStack_50;
            iVar10 = iStack_4;
          }
        }
        puStack_18 = (undefined4 *)0x0;
      }
      else {
        iVar7 = *(int *)(param_1 + 0x18);
        iVar10 = param_2;
      }
      if ((iVar7 != 0) &&
         (((cVar4 = FUN_00735e20(), cVar4 != '\0' ||
           (((((piVar9 = (int *)FUN_00737360(&iStack_44), *piVar9 <= iVar11 && (iVar11 < piVar9[2]))
              && (piVar9[1] <= iVar6)) && (iVar6 < piVar9[3])) ||
            (iVar6 = FUN_00738330(), iVar6 != 0)))) && (cVar4 = FUN_007385a0(), cVar4 != '\0')))) {
        uVar5 = FUN_00734a00(iVar10,unaff_retaddr,param_2,0);
        FUN_007373f0(&DAT_009b3c44);
        goto LAB_007300f9;
      }
    }
  }
  else if (((*(int *)(param_1 + 0x18) != 0) && (cVar4 = FUN_00735df0(), cVar4 != '\0')) &&
          ((cVar4 = FUN_007385a0(), cVar4 != '\0' &&
           ((cVar4 = FUN_00734a00(param_2,unaff_retaddr,param_2,1),
            *(char *)(param_1 + 0xf0) == '\0' && (cVar4 != '\0')))))) {
    uVar5 = 1;
    goto LAB_007300f9;
  }
  uVar5 = 0;
LAB_007300f9:
  *unaff_FS_OFFSET = uStack_14;
  return uVar5;
}


/* ==================================================================== */
/* Address: 0x00730110 | Classified: elementclient::AUIManager__MessageBox____failed@0x730110 */
/* ==================================================================== */

undefined4 FUN_00730110(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int extraout_ECX;
  uint uVar7;
  uint uVar8;
  undefined1 *puVar9;
  int *piVar10;
  char *pcVar11;
  int iVar12;
  char *pcVar13;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000028;
  char *in_stack_000010ac;
  undefined4 *in_stack_000010b8;
  int in_stack_000010c0;
  uint in_stack_000010cc;
  int in_stack_000010e8;
  int in_stack_000010f0;
  int in_stack_00001114;
  uint in_stack_00001118;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  uint uStack_64;
  int iStack_60;
  int *piStack_5c;
  int iStack_58;
  int *piStack_54;
  int iStack_50;
  undefined1 *puStack_4c;
  undefined4 uStack_48;
  int *piStack_44;
  int aiStack_40 [4];
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined4 uStack_24;
  undefined *puStack_20;
  undefined1 *puStack_1c;
  undefined4 uStack_14;
  
  func_0x00892f20();
  piVar10 = (int *)0x0;
  in_stack_00000020 = 0;
  uStack_14 = 0x730137;
  FUN_007537e0();
  uStack_14 = 0xffffffff;
  puStack_1c = &stack0x00000030;
  puStack_20 = (undefined *)0x73014d;
  iVar2 = func_0x0073c830();
  in_stack_00000028 = *(undefined4 *)(iVar2 + 4);
  puStack_20 = (undefined *)0x0;
  puStack_28 = &stack0x00000030;
  uStack_24 = 3;
  puStack_2c = &stack0x0000002c;
  aiStack_40[2] = *(undefined4 *)(extraout_ECX + 0x10);
  puStack_30 = &stack0x0000000c;
  aiStack_40[1] = 0x730170;
  cVar1 = func_0x007397b0();
  if (cVar1 == '\0') {
    puStack_20 = (undefined *)0x97fda4;
    uStack_24 = 1;
    puStack_28 = (undefined1 *)0x294;
    puStack_2c = (undefined1 *)0x730188;
    uVar3 = func_0x00739700();
    return uVar3;
  }
  uStack_24 = *(undefined4 *)(extraout_ECX + 8);
  puStack_28 = *(undefined1 **)(extraout_ECX + 4);
  puStack_20 = &DAT_009b3c44;
  puStack_2c = (undefined1 *)0x7301ac;
  iVar2 = FUN_0072ef50();
  if (iVar2 == -1) {
    puStack_2c = (undefined1 *)0x97fd5c;
    puStack_30 = (undefined1 *)0x1;
    aiStack_40[3] = 0x299;
    aiStack_40[2] = 0x7301c2;
    uVar3 = func_0x00739700();
    return uVar3;
  }
  puStack_2c = (undefined1 *)0x97fd44;
  puStack_30 = (undefined1 *)0x7301e8;
  cVar1 = FUN_00737500();
  if (cVar1 == '\0') {
    puStack_30 = (undefined1 *)0x97fcf4;
    aiStack_40[3] = 1;
    aiStack_40[2] = 0x29d;
    aiStack_40[1] = 0x7301fd;
    uVar3 = func_0x00739700();
    return uVar3;
  }
  uVar7 = 0xffffffff;
  pcVar11 = (char *)0x97fce4;
  do {
    pcVar13 = pcVar11;
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    pcVar13 = pcVar11 + 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar13;
  } while (cVar1 != '\0');
  uVar7 = ~uVar7;
  pcVar11 = pcVar13 + -uVar7;
  pcVar13 = &stack0x00000124;
  for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pcVar13 = *(undefined4 *)pcVar11;
    pcVar11 = pcVar11 + 4;
    pcVar13 = pcVar13 + 4;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *pcVar13 = *pcVar11;
    pcVar11 = pcVar11 + 1;
    pcVar13 = pcVar13 + 1;
  }
  puStack_30 = &stack0x00000124;
  aiStack_40[3] = 0x95d238;
  aiStack_40[2] = 0x73024e;
  cVar1 = FUN_00737a70();
  if (cVar1 == '\0') {
    aiStack_40[2] = 0x97fc84;
    aiStack_40[1] = 1;
    aiStack_40[0] = 0x2a1;
    piStack_44 = (int *)0x730263;
    uVar3 = func_0x00739700();
    return uVar3;
  }
  aiStack_40[0] = *(int *)(extraout_ECX + 8);
  piStack_44 = *(int **)(extraout_ECX + 4);
  aiStack_40[2] = 1;
  aiStack_40[1] = 6;
  uStack_48 = 0x730286;
  piVar4 = (int *)FUN_00736d50();
  if (piVar4 == (int *)0x0) {
    uStack_48 = 0x97fc4c;
    puStack_4c = (undefined1 *)0x1;
    iStack_50 = 0x2a6;
    piStack_54 = (int *)0x7302a1;
    uVar3 = func_0x00739700();
    return uVar3;
  }
  uStack_48 = 0;
  puStack_4c = puStack_1c;
  iStack_50 = 0x7302c2;
  FUN_00742050();
  piStack_54 = (int *)0x7302d1;
  iStack_50 = in_stack_00001114;
  (**(code **)(*piVar4 + 0x34))();
  piStack_54 = (int *)0x0;
  iStack_58 = 1;
  uStack_64 = in_stack_00001118 | 0xff000000;
  piStack_5c = (int *)0x0;
  iStack_60 = 0;
  puStack_30 = (undefined1 *)uStack_64;
  uVar3 = FUN_0072ef30();
  iVar2 = _wtoi(uVar3);
  iVar5 = FUN_0072ef30(1,iVar2);
  FUN_00742530(iVar5);
  if (in_stack_000010f0 != -1) {
    piVar10 = (int *)FUN_00736d50(*(undefined4 *)(extraout_ECX + 4),
                                  *(undefined4 *)(extraout_ECX + 8),0xd,1);
    if (piVar10 == (int *)0x0) {
      func_0x00739700(0x2b1,1,0x97fc14);
    }
    uVar7 = 0xffffffff;
    pcVar11 = (char *)0x97fc00;
    do {
      pcVar13 = pcVar11;
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      pcVar13 = pcVar11 + 1;
      cVar1 = *pcVar11;
      pcVar11 = pcVar13;
    } while (cVar1 != '\0');
    uVar7 = ~uVar7;
    pcVar11 = pcVar13 + -uVar7;
    pcVar13 = &stack0x000000cc;
    for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined4 *)pcVar13 = *(undefined4 *)pcVar11;
      pcVar11 = pcVar11 + 4;
      pcVar13 = pcVar13 + 4;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar13 = *pcVar11;
      pcVar11 = pcVar11 + 1;
      pcVar13 = pcVar13 + 1;
    }
    cVar1 = (**(code **)(*piVar10 + 0x28))(0x95d208,&stack0x000000cc);
    if (cVar1 == '\0') {
      uVar3 = func_0x00739700(0x2b5,1,0x97fb94);
      return uVar3;
    }
    uVar7 = 0xffffffff;
    pcVar11 = (char *)0x97fb80;
    do {
      pcVar13 = pcVar11;
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      pcVar13 = pcVar11 + 1;
      cVar1 = *pcVar11;
      pcVar11 = pcVar13;
    } while (cVar1 != '\0');
    uVar7 = ~uVar7;
    pcVar11 = pcVar13 + -uVar7;
    pcVar13 = &stack0x000000c4;
    for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined4 *)pcVar13 = *(undefined4 *)pcVar11;
      pcVar11 = pcVar11 + 4;
      pcVar13 = pcVar13 + 4;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar13 = *pcVar11;
      pcVar11 = pcVar11 + 1;
      pcVar13 = pcVar13 + 1;
    }
    cVar1 = (**(code **)(*piVar10 + 0x28))(0x95d1e0,&stack0x000000c4);
    if (cVar1 == '\0') {
      uVar3 = func_0x00739700(0x2b9,1,0x97fb10);
      return uVar3;
    }
    uVar3 = FUN_0072ef30(2,iVar5,0,0,1,0);
    uVar3 = _wtoi(uVar3);
    uVar3 = FUN_0072ef30(1,uVar3);
    FUN_00742530(uVar3);
    uStack_64 = 1;
  }
  piVar4 = piStack_44;
  if (in_stack_000010f0 == 0) {
LAB_00730611:
    FUN_00742600(0x969e98);
    FUN_00741e10(0x95c83c);
    iVar12 = *piVar10;
    if (in_stack_000010e8 == 1) {
      uVar3 = FUN_00737a30(1);
      (**(code **)(iVar12 + 0x34))(uVar3);
      FUN_00742600(0x95baec);
      FUN_00741e10(0x9654b8);
      iVar12 = *piVar4;
      uVar3 = FUN_00737a30(2);
    }
    else {
      uVar3 = FUN_00737a30(0);
    }
  }
  else {
    if (in_stack_000010f0 != -1) {
      piStack_54 = (int *)FUN_00736d50(*(undefined4 *)(extraout_ECX + 4),
                                       *(undefined4 *)(extraout_ECX + 8),0xd,1);
      if (piStack_54 == (int *)0x0) {
        func_0x00739700(0x2c6,1,0x97fad4);
      }
      uVar7 = 0xffffffff;
      pcVar11 = (char *)0x97fc00;
      do {
        pcVar13 = pcVar11;
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        pcVar13 = pcVar11 + 1;
        cVar1 = *pcVar11;
        pcVar11 = pcVar13;
      } while (cVar1 != '\0');
      uVar7 = ~uVar7;
      pcVar11 = pcVar13 + -uVar7;
      pcVar13 = &stack0x000000cc;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar11;
        pcVar11 = pcVar11 + 4;
        pcVar13 = pcVar13 + 4;
      }
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar13 = *pcVar11;
        pcVar11 = pcVar11 + 1;
        pcVar13 = pcVar13 + 1;
      }
      cVar1 = (**(code **)(*piStack_54 + 0x28))(0x95d208,&stack0x000000cc);
      piVar4 = piStack_5c;
      if (cVar1 == '\0') {
        uVar3 = func_0x00739700(0x2ca,1,0x97fa68);
        return uVar3;
      }
      uVar7 = 0xffffffff;
      pcVar11 = (char *)0x97fb80;
      do {
        pcVar13 = pcVar11;
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        pcVar13 = pcVar11 + 1;
        cVar1 = *pcVar11;
        pcVar11 = pcVar13;
      } while (cVar1 != '\0');
      uVar7 = ~uVar7;
      pcVar11 = pcVar13 + -uVar7;
      pcVar13 = &stack0x000000c4;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar11;
        pcVar11 = pcVar11 + 4;
        pcVar13 = pcVar13 + 4;
      }
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar13 = *pcVar11;
        pcVar11 = pcVar11 + 1;
        pcVar13 = pcVar13 + 1;
      }
      cVar1 = (**(code **)(*piStack_5c + 0x28))(0x95d1e0,&stack0x000000c4);
      if (cVar1 == '\0') {
        uVar3 = func_0x00739700(0x2ce,1,0x97f9f8);
        return uVar3;
      }
      uVar3 = FUN_0072ef30(2,iVar5,0,0,1,0);
      uVar3 = _wtoi(uVar3);
      uVar3 = FUN_0072ef30(1,uVar3);
      FUN_00742530(uVar3);
      uStack_64 = uStack_64 + 1;
    }
    if (in_stack_000010f0 == 1) goto LAB_00730611;
    if (in_stack_000010f0 != 4) goto LAB_0073067e;
    FUN_00742600(0x97f9f0);
    FUN_00741e10(0x96fd70);
    iVar12 = *piVar10;
    uVar3 = FUN_00737a30(6);
    (**(code **)(iVar12 + 0x34))(uVar3);
    FUN_00742600(0x97f9e8);
    FUN_00741e10(0x97f9e0);
    iVar12 = *piVar4;
    uVar3 = FUN_00737a30(7);
  }
  (**(code **)(iVar12 + 0x34))(uVar3);
LAB_0073067e:
  puVar9 = puStack_30;
  if (0 < (int)uStack_64) {
    FUN_0074f500(1,&piStack_54);
    piVar6 = (int *)FUN_007537a0();
    puVar9 = puStack_30;
    iStack_60 = *piVar6 + (int)puStack_30 * 4;
    piStack_5c = (int *)(piVar6[1] + (int)puStack_30);
    if (piVar10 != (int *)0x0) {
      FUN_00742050(iStack_60,piStack_5c);
    }
    if (piVar4 != (int *)0x0) {
      FUN_00742050(iStack_60,piStack_5c);
    }
  }
  FUN_007537a0(aiStack_40);
  iVar12 = ((int)puStack_2c + 2) * (int)puVar9 + aiStack_40[0];
  if (0 < iStack_60) {
    iVar12 = iVar12 + iStack_60 + (int)puVar9 * 2;
  }
  iStack_50 = iStack_50 + (int)puVar9 * 2;
  iStack_58 = uStack_64 * 3;
  if ((int)(uStack_64 * 3) < iStack_50) {
    iStack_58 = iStack_50;
  }
  iStack_58 = iStack_58 + (int)piStack_44;
  iVar17 = iVar12;
  FUN_00737340(iStack_58,iVar12);
  iVar16 = 0;
  iVar15 = 3;
  iVar14 = 3;
  uVar3 = 0;
  FUN_007354f0(0,0,3,3,0);
  FUN_00741df0((iVar5 - iVar2) / 2,(int)piStack_5c / 2 + (int)puVar9);
  if (0 < iVar14) {
    iVar16 = ((iVar12 - (int)uStack_64 / 2) - (int)puVar9) - iVar16;
    if (iVar14 == 1) {
      iVar2 = (iVar17 - iVar15) / 2;
    }
    else {
      FUN_00741df0((iVar17 / 2 - (int)puVar9 / 2) - iVar15,iVar16);
      iVar2 = (int)puVar9 / 2 + iVar17 / 2;
    }
    FUN_00741df0(iVar2,iVar16);
  }
  FUN_00737ed0(in_stack_000010cc >> 0x18);
  FUN_007354c0(1);
  FUN_00735c50(1,in_stack_000010c0 != -1,1);
  iVar2 = -1;
  pcVar11 = in_stack_000010ac;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar11 + 1;
  } while (cVar1 != '\0');
  if ((iVar2 == -2) || (iVar2 = _strcmpi(in_stack_000010ac,0x97f9d8), iVar2 == 0)) {
    iVar2 = rand();
    iVar5 = rand();
    sprintf(&iStack_60,0x97f9cc,iVar2 * iVar5);
  }
  else {
    strncpy(&iStack_60,in_stack_000010ac,0xff);
  }
  FUN_007359c0(&iStack_60);
  if (in_stack_000010b8 != (undefined4 *)0x0) {
    *in_stack_000010b8 = uVar3;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007308a0 | Classified: elementclient::AUIManager__RenderHint____failed@0x7308a0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __fastcall FUN_007308a0(int param_1)

{
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int unaff_EBX;
  int unaff_ESI;
  undefined4 unaff_EDI;
  uint *unaff_FS_OFFSET;
  undefined4 uVar9;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 *puStack_60;
  int iStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  uint uStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  undefined1 auStack_24 [8];
  uint uStack_1c;
  undefined1 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  uint uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008c9900;
  *unaff_FS_OFFSET = (uint)&uStack_c;
  if (*(int *)(param_1 + 0xd8) == 0) {
    *(undefined4 *)(param_1 + 0xdc) = 0;
  }
  if (((*(int *)(param_1 + 0xec) == 0) || (*(int *)(param_1 + 0xd4) == 0)) ||
     (*(int *)(param_1 + 0xd8) == 0)) goto LAB_00730a0f;
  uVar8 = *(uint *)(*(int *)(param_1 + 0xd4) + 0x8c);
  puStack_60 = (undefined1 *)0x7308fe;
  iVar4 = GetTickCount();
  if ((uint)(iVar4 - *(int *)(param_1 + 0xd0)) < uVar8) goto LAB_00730a0f;
  if ((*(int *)(param_1 + 0x18) != 0) && (*(int *)(param_1 + 0xd4) != *(int *)(param_1 + 0x18))) {
    puStack_60 = (undefined1 *)0x730920;
    cVar2 = FUN_00735e10();
    if (cVar2 != '\0') goto LAB_00730a0f;
    puStack_60 = (undefined1 *)0x730930;
    iVar4 = FUN_00738330();
    if (iVar4 != 0) goto LAB_00730a0f;
  }
  puStack_60 = auStack_24;
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 0xa8);
  uStack_64 = (int *)0x73094c;
  GetCursorPos();
  uStack_64 = &iStack_28;
  uStack_68 = *(undefined4 *)(*(int *)(param_1 + 8) + 4);
  uStack_6c = 0x73095e;
  ScreenToClient();
  iStack_30 = iStack_30 - *(int *)(iVar4 + 0x14);
  iStack_2c = iStack_2c - *(int *)(iVar4 + 0x18);
  uStack_10 = 0;
  uStack_6c = 0x730993;
  uStack_6c = FUN_00742830();
  FUN_00765230();
  if (*(int *)(unaff_ESI + -8) < 1) {
    iVar5 = FUN_00741f50();
    if (iVar5 == 7) {
      iVar5 = FUN_0074b4e0();
      if (iVar5 != *(int *)(param_1 + 0xe8)) {
        *(undefined4 *)(param_1 + 0xdc) = 0;
      }
      uVar6 = FUN_0074b4e0();
      *(undefined4 *)(param_1 + 0xe8) = uVar6;
      uVar6 = FUN_0074b4e0();
      uVar6 = FUN_0074b460(uVar6);
      FUN_00765230(uVar6);
      iVar5 = *(int *)(unaff_ESI + -8);
LAB_007309f8:
      if (0 < iVar5) goto LAB_00730a99;
    }
    else {
      iVar5 = FUN_00741f50();
      if (iVar5 == 0xf) {
        FUN_00741db0(&uStack_48,0);
        iVar5 = FUN_00751e00(iStack_3c - unaff_EBX,uStack_38 - iStack_4c,(int)&uStack_64 + 3);
        if ((iVar5 != 0) && ((char)((uint)unaff_EDI >> 0x18) == '\0')) {
          if (iVar5 != *(int *)(param_1 + 0xe8)) {
            *(undefined4 *)(param_1 + 0xdc) = 0;
          }
          *(int *)(param_1 + 0xe8) = iVar5;
          uVar6 = FUN_007521a0(iVar5);
          FUN_00765230(uVar6);
          iVar5 = *(int *)(unaff_ESI + -8);
          goto LAB_007309f8;
        }
      }
    }
  }
  else {
LAB_00730a99:
    uVar9 = 0;
    uVar6 = FUN_0072ef30(1,1,0);
    uVar6 = FUN_0072ef30(2,uVar6);
    iVar5 = _wtoi(uVar6);
    puStack_60 = (undefined1 *)func_0x0075e6e0((float)iVar5);
    cVar2 = func_0x007397b0(puStack_60,uVar9,&stack0xffffffa8,&uStack_6c,&stack0xffffffb0,3,0);
    if (cVar2 == '\0') {
      uVar9 = 0x97fe64;
      uVar6 = 0x377;
LAB_00730ca8:
      uVar3 = func_0x00739700(uVar6,1,uVar9);
      uStack_14 = 0xffffffff;
      FUN_00765200();
      *unaff_FS_OFFSET = uStack_1c;
      return uVar3;
    }
    FUN_007537a0(&iStack_2c);
    iVar5 = iStack_30 + 2 + iStack_44;
    iVar1 = iStack_2c + 1 + unaff_ESI;
    if (*(int *)(param_1 + 0xd8) == *(int *)(param_1 + 0xdc)) {
      uVar8 = *(uint *)(param_1 + 0xe0);
      iVar7 = *(int *)(param_1 + 0xe4);
    }
    else {
      uStack_40 = _DAT_00985a98;
      uStack_18 = 1;
      uVar8 = ((int)uStack_38 < 0) - 1 & uStack_38;
      iVar7 = FUN_00741f50();
      if (iVar7 == 0xc) {
        iVar7 = FUN_00742030(&iStack_28);
        iVar7 = *(int *)(iVar7 + 4) + iStack_34;
      }
      else {
        iVar7 = iStack_34 + 0x20;
      }
      if (*(uint *)(iVar4 + 0x1c) < iVar5 + uVar8) {
        uVar8 = *(uint *)(iVar4 + 0x1c) - iVar5;
      }
      if ((*(uint *)(iVar4 + 0x20) < (uint)(iVar7 + iVar1)) &&
         (iVar7 = (iStack_34 - iStack_2c) - unaff_ESI, iVar7 < 0)) {
        iVar7 = *(uint *)(iVar4 + 0x20) - iVar1;
      }
      *(undefined4 *)(param_1 + 0xdc) = *(undefined4 *)(param_1 + 0xd8);
      *(uint *)(param_1 + 0xe0) = uVar8;
      *(int *)(param_1 + 0xe4) = iVar7;
      uStack_18 = 0;
      FUN_00765200();
    }
    cVar2 = FUN_007530d0(*(int *)(iVar4 + 0x14) + uVar8,*(int *)(iVar4 + 0x18) + iVar7,iVar5,iVar1,
                         iStack_4c,0,0,0,0,0,0xff,0,0);
    if (cVar2 == '\0') {
      uVar9 = 0x97fe20;
      uVar6 = 0x3a4;
      goto LAB_00730ca8;
    }
    cVar2 = func_0x007398e0(uStack_48,*(int *)(iVar4 + 0x14) + uVar8 + iStack_2c / 2,
                            *(int *)(iVar4 + 0x18) + iVar7 + iStack_28 / 2,unaff_ESI,0,0,0,3,0,0,0,0
                            ,0,1,0,0,0,1);
    if (cVar2 == '\0') {
      uVar9 = 0x97fde0;
      uVar6 = 0x3a9;
      goto LAB_00730ca8;
    }
  }
  uStack_14 = 0xffffffff;
  FUN_00765200();
LAB_00730a0f:
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00730ce0 | Classified: ElementClient::proc_730ce0 */
/* ==================================================================== */

undefined4 __thiscall
FUN_00730ce0(int param_1,int param_2,undefined4 param_3,undefined4 *param_4,undefined4 *param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  char cVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  undefined4 *unaff_FS_OFFSET;
  int unaff_retaddr;
  int iStack_44;
  undefined1 auStack_40 [16];
  undefined *puStack_30;
  undefined *puStack_2c;
  undefined4 *puStack_28;
  undefined4 uStack_24;
  undefined4 *puStack_20;
  undefined4 uStack_1c;
  undefined4 *puStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  iStack_4 = -1;
  puStack_8 = &UNK_008c9918;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 4) + 0xa8);
  func_0x00431c00(10);
  puStack_30 = &UNK_008eea04;
  puVar2 = *(undefined4 **)(param_1 + 0x28);
  puStack_8 = (undefined *)0x0;
  while (puVar2 != (undefined4 *)0x0) {
    puVar3 = puVar2 + 2;
    puVar2 = (undefined4 *)*puVar2;
    func_0x004287c0(*puVar3);
  }
  puVar2 = *(undefined4 **)(param_1 + 0x48);
  while (puVar3 = puStack_28, puVar12 = puStack_28, puVar2 != (undefined4 *)0x0) {
    puVar3 = puVar2 + 2;
    puVar2 = (undefined4 *)*puVar2;
    func_0x004287c0(*puVar3);
  }
  do {
    if (puVar3 == (undefined4 *)0x0) goto LAB_00730ee7;
    puVar2 = (undefined4 *)puVar3[2];
    puVar3 = (undefined4 *)*puVar3;
  } while ((((puVar2 == (undefined4 *)0x0) ||
            (cVar7 = FUN_00735df0(), puVar12 = puStack_28, cVar7 == '\0')) || (puVar2 == param_5))
          || (((piVar8 = (int *)FUN_00737360(&stack0xffffffb0), puVar12 = puStack_28,
               unaff_retaddr < *piVar8 || (piVar8[2] <= unaff_retaddr)) ||
              ((param_2 < piVar8[1] || (piVar8[3] <= param_2))))));
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = puVar2;
  }
  if (puVar1 != (undefined4 *)0x0) {
    for (iVar9 = FUN_007374f0(); puVar12 = puStack_28, iVar9 != 0; iVar9 = *(int *)(iVar9 + 4)) {
      piVar8 = *(int **)(iVar9 + 8);
      bVar6 = false;
      iVar10 = (**(code **)(*piVar8 + 0x20))(auStack_40);
      iVar4 = *(int *)(iVar10 + 4);
      iVar5 = *(int *)(iVar10 + 8);
      iVar10 = *(int *)(iVar10 + 0xc);
      iVar11 = FUN_007537e0();
      if (iVar11 != 0) {
        iVar11 = FUN_007537e0();
        iVar13 = *(int *)(iVar11 + 0x14) - *(int *)(param_2 + 0x14);
        iVar14 = *(int *)(iVar11 + 0x18) - *(int *)(param_2 + 0x18);
        if (((iStack_4 < iVar13) || (*(int *)(iVar11 + 0x1c) + iVar13 <= iStack_4)) ||
           ((unaff_retaddr < iVar14 || (*(int *)(iVar11 + 0x20) + iVar14 <= unaff_retaddr)))) {
          bVar6 = true;
        }
        else {
          bVar6 = false;
        }
      }
      cVar7 = FUN_00741f00();
      if (((((cVar7 != '\0') && (cVar7 = FUN_00742610(), cVar7 == '\0')) && (iVar4 <= unaff_retaddr)
           ) && ((unaff_retaddr < iVar10 && (iVar5 <= unaff_retaddr)))) &&
         ((unaff_retaddr < iStack_44 && (!bVar6)))) {
        *puVar1 = piVar8;
        puVar12 = puStack_28;
        break;
      }
    }
  }
LAB_00730ee7:
  puStack_8 = (undefined *)0xffffffff;
  puStack_30 = &UNK_008eea04;
  puStack_2c = &UNK_008d649c;
  while (puVar1 = puVar12, puVar1 != (undefined4 *)0x0) {
    puStack_28 = (undefined4 *)*puVar1;
    *puVar1 = puStack_20;
    puVar12 = puStack_28;
    puStack_20 = puVar1;
  }
  uStack_24 = 0;
  uStack_1c = 0;
  while (puVar1 = puStack_14, puVar1 != (undefined4 *)0x0) {
    puStack_14 = (undefined4 *)puVar1[1];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
  }
  *unaff_FS_OFFSET = uStack_10;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00730f70 | Classified: AUIManager::vfunc_slot_9 */
/* ==================================================================== */

void __thiscall
FUN_00730f70(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int unaff_retaddr;
  int iVar6;
  int iStack_38;
  int aiStack_28 [2];
  undefined1 auStack_20 [24];
  int iStack_8;
  
  param_8 = param_8 - param_6;
  if (((param_8 != param_4 - param_2) || (param_9 - param_7 != param_5 - param_3)) &&
     (iStack_38 = 0, 0 < *(int *)(param_1 + 0x6c))) {
    do {
      piVar3 = (int *)FUN_00737360(auStack_20);
      iVar4 = *piVar3;
      iVar5 = piVar3[1];
      aiStack_28[0] = piVar3[3];
      if (5 < iVar4) {
        if ((-piVar3[2] - unaff_retaddr) + param_3 < 6) {
          iVar4 = param_8 + -piVar3[2] + iVar4;
        }
        else {
          iVar4 = (param_8 * iVar4) / iStack_38;
        }
      }
      if (5 < iVar5) {
        if ((param_4 - param_2) - aiStack_28[0] < 6) {
          iVar5 = (iVar5 - aiStack_28[0]) + param_5;
        }
        else {
          iVar5 = (iVar5 * param_5) / (param_4 - param_2);
        }
      }
      iVar6 = 0;
      FUN_007354f0(iVar4,iVar5,0,0,0);
      piVar3 = (int *)FUN_00737360(aiStack_28);
      iVar1 = *piVar3;
      iVar2 = piVar3[1];
      if (iVar1 < 0) {
        iVar4 = 0;
      }
      else if (iVar6 < iVar1) {
        iVar4 = (iVar6 - piVar3[2]) + iVar1;
      }
      if (iVar2 < 0) {
        iVar5 = 0;
      }
      else if (iStack_8 < iVar2) {
        iVar5 = (iVar2 - piVar3[3]) + iStack_8;
      }
      FUN_007354f0(iVar4,iVar5,0,0,0);
      FUN_007373a0(0);
      iStack_38 = iStack_38 + 1;
    } while (iStack_38 < *(int *)(param_1 + 0x6c));
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007310f0 | Classified: ElementClient::proc_7310f0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007310f0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x1c);
}


/* ==================================================================== */
/* Address: 0x00731100 | Classified: ElementClient::proc_731100 */
/* ==================================================================== */

void FUN_00731100(char param_1)

{
  if (DAT_009c1570 != param_1) {
    if (param_1 != '\0') {
      func_0x00760f60();
      DAT_009c1570 = 1;
      return;
    }
    func_0x007616a0();
    DAT_009c1570 = '\0';
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00731130 | Classified: ElementClient::proc_731130 */
/* ==================================================================== */

void __thiscall FUN_00731130(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 0xd4);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(param_1 + 0xd8);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00731160 | Classified: ElementClient::proc_731160 */
/* ==================================================================== */

int FUN_00731160(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uVar1 = param_1;
  uStack_8 = param_1;
  uStack_4 = 0;
  iVar2 = func_0x004fcb10(&param_1,&uStack_8);
  if (*(int *)(iVar2 + 4) != 0) {
    return 1;
  }
  uStack_4 = uVar1;
  iVar2 = func_0x004fcb10(&uStack_4,&stack0xfffffff0);
  return (-(uint)(*(int *)(iVar2 + 4) != 0) & 0xfffffffe) + 2;
}


/* ==================================================================== */
/* Address: 0x007311e0 | Classified: ElementClient::proc_7311e0 */
/* ==================================================================== */

bool FUN_007311e0(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = func_0x0075b8e0(param_1);
    return iVar1 != 0;
  }
  iVar1 = func_0x0075bb10();
  return iVar1 != 0;
}


/* ==================================================================== */
/* Address: 0x00731210 | Classified: AUIManager::vfunc_slot_10 */
/* ==================================================================== */

undefined4 FUN_00731210(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008c9943;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uVar2 = 0;
  uStack_4 = 0;
  iVar1 = func_0x00763250(0x164);
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  if (iVar1 != 0) {
    uVar2 = FUN_00731800();
  }
  uStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return uVar2;
}


/* ==================================================================== */
/* Address: 0x00731280 | Classified: ElementClient::proc_731280 */
/* ==================================================================== */

void __fastcall FUN_00731280(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  *param_1 = &UNK_008eea04;
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
/* Address: 0x007312e0 | Classified: ElementClient::proc_7312e0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall FUN_007312e0(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint unaff_EBX;
  uint uVar5;
  undefined4 *unaff_FS_OFFSET;
  uint *unaff_retaddr;
  undefined4 uStack_34;
  uint uStack_30;
  uint uStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  undefined1 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008c9979;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_34 = _DAT_00985a98;
  uVar5 = 0;
  uStack_24 = *param_2;
  uStack_4 = 0;
  FUN_00765000(&uStack_34);
  uVar4 = *(uint *)(param_1 + 0x14);
  uVar2 = *(int *)(param_1 + 4) + 1;
  puStack_8._0_1_ = 1;
  if ((uVar4 < uVar2) && (uStack_30 = func_0x00404700(uVar2), uVar4 < uStack_30)) {
    uStack_34 = 0;
    func_0x005b0ea0(uStack_30,&uStack_34);
    uStack_10 = CONCAT31(uStack_10._1_3_,2);
    if (uVar4 != 0) {
      do {
        puVar1 = (undefined4 *)(*(int *)(param_1 + 8) + uVar5 * 4);
        puVar3 = *(undefined4 **)(*(int *)(param_1 + 8) + uVar5 * 4);
        while (puVar3 != (undefined4 *)0x0) {
          uVar2 = puVar3[3];
          *puVar1 = *puVar3;
          *puVar3 = *(undefined4 *)(iStack_28 + (uVar2 % unaff_EBX) * 4);
          *(undefined4 **)(iStack_28 + (uVar2 % unaff_EBX) * 4) = puVar3;
          puVar1 = (undefined4 *)(*(int *)(param_1 + 8) + uVar5 * 4);
          puVar3 = *(undefined4 **)(*(int *)(param_1 + 8) + uVar5 * 4);
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar4);
    }
    func_0x004bb3b0(&iStack_28);
    uStack_14 = 1;
    func_0x004060e0();
  }
  uVar4 = *unaff_retaddr % *(uint *)(param_1 + 0x14);
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 8) + uVar4 * 4);
  for (puVar3 = puVar1; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
    if (puVar3[3] == *unaff_retaddr) goto LAB_00731423;
  }
  uStack_30 = func_0x00763250(0x10);
  puStack_8._0_1_ = 3;
  uStack_2c = uStack_30;
  if (uStack_30 == 0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)func_0x004c2040(unaff_retaddr,&iStack_28,puVar1);
  }
  *(undefined4 **)(*(int *)(param_1 + 8) + uVar4 * 4) = puVar3;
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
LAB_00731423:
  puStack_8 = (undefined *)((uint)puStack_8._1_3_ << 8);
  FUN_00765200();
  puStack_8 = (undefined *)0xffffffff;
  FUN_00765200();
  *unaff_FS_OFFSET = uStack_10;
  return puVar3 + 2;
}


/* ==================================================================== */
/* Address: 0x00731460 | Classified: PAVAUIDialog::?$APtrList::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_00731460(undefined4 param_1,byte param_2)

{
  FUN_00731280();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00731480 | Classified: ElementClient::proc_731480 */
/* ==================================================================== */

void __thiscall FUN_00731480(int param_1,int param_2,undefined4 *param_3)

{
  if (param_3 != (undefined4 *)0x0) goto LAB_00731493;
  param_3 = *(undefined4 **)(param_1 + 4);
  while( true ) {
    if (param_3 == (undefined4 *)0x0) {
      return;
    }
LAB_00731493:
    if (param_3[2] == param_2) break;
    param_3 = (undefined4 *)*param_3;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007314b0 | Classified: ElementClient::proc_7314b0 */
/* ==================================================================== */

void __fastcall FUN_007314b0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    do {
      puVar2 = *(undefined4 **)(*(int *)(param_1 + 8) + uVar3 * 4);
      while (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar2;
        FUN_007316a0();
        func_0x00763260(puVar2);
        puVar2 = puVar1;
      }
      uVar3 = uVar3 + 1;
      *(undefined4 *)(*(int *)(param_1 + 8) + -4 + uVar3 * 4) = 0;
    } while (uVar3 < *(uint *)(param_1 + 0x14));
    *(undefined4 *)(param_1 + 4) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00731510 | Classified: ElementClient::proc_731510 */
/* ==================================================================== */

uint __thiscall FUN_00731510(int param_1,undefined4 *param_2)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  
  pbVar9 = (byte *)*param_2;
  uVar6 = 0;
  bVar2 = *pbVar9;
  while (bVar2 != 0) {
    uVar6 = uVar6 * 0x1f + (uint)bVar2;
    pbVar1 = pbVar9 + 1;
    pbVar9 = pbVar9 + 1;
    bVar2 = *pbVar1;
  }
  uVar7 = uVar6 / *(uint *)(param_1 + 0x14);
  uVar6 = uVar6 % *(uint *)(param_1 + 0x14);
  puVar3 = *(undefined4 **)(*(int *)(param_1 + 8) + uVar6 * 4);
  puVar4 = (undefined4 *)0x0;
  puVar5 = puVar3;
  while( true ) {
    if (puVar5 == (undefined4 *)0x0) {
      return uVar7 & 0xffffff00;
    }
    uVar7 = func_0x00763c50(param_2);
    if ((char)uVar7 != '\0') break;
    puVar4 = puVar5;
    puVar5 = (undefined4 *)*puVar5;
  }
  if (puVar5 == puVar3) {
    *(undefined4 *)(*(int *)(param_1 + 8) + uVar6 * 4) = *puVar5;
  }
  else {
    *puVar4 = *puVar5;
  }
  FUN_007316a0();
  func_0x00763260(puVar5);
  iVar8 = *(int *)(param_1 + 4) + -1;
  *(int *)(param_1 + 4) = iVar8;
  return CONCAT31((int3)((uint)iVar8 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007315b0 | Classified: ElementClient::proc_7315b0 */
/* ==================================================================== */

void __fastcall FUN_007315b0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    do {
      puVar2 = *(undefined4 **)(*(int *)(param_1 + 8) + uVar3 * 4);
      while (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar2;
        func_0x00827140();
        func_0x00763260(puVar2);
        puVar2 = puVar1;
      }
      uVar3 = uVar3 + 1;
      *(undefined4 *)(*(int *)(param_1 + 8) + -4 + uVar3 * 4) = 0;
    } while (uVar3 < *(uint *)(param_1 + 0x14));
    *(undefined4 *)(param_1 + 4) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00731610 | Classified: ElementClient::proc_731610 */
/* ==================================================================== */

undefined4 * __thiscall FUN_00731610(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 unaff_EBX;
  undefined4 *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008c999b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  func_0x00763660(param_3);
  param_1[2] = *(undefined4 *)(param_3 + 4);
  puStack_8 = (undefined *)0x0;
  func_0x00763660(unaff_retaddr);
  *param_1 = param_2;
  *unaff_FS_OFFSET = unaff_EBX;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00731680 | Classified: ElementClient::proc_731680 */
/* ==================================================================== */

undefined4 __thiscall FUN_00731680(undefined4 param_1,byte param_2)

{
  FUN_007316a0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007316a0 | Classified: ElementClient::proc_7316a0 */
/* ==================================================================== */

void FUN_007316a0(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008c99bb;
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
/* Address: 0x007316f0 | Classified: ElementClient::proc_7316f0 */
/* ==================================================================== */

void __fastcall FUN_007316f0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  DeleteCriticalSection(param_1 + 0x28);
  puVar2 = *(undefined4 **)(param_1 + 0x14);
  puVar1 = puVar2 + *(int *)(param_1 + 0x20);
  if (puVar2 != puVar1) {
    puVar3 = puVar1;
    puVar6 = puVar2;
    if (puVar1 < *(undefined4 **)(param_1 + 0x18)) {
      do {
        puVar4 = puVar3 + 1;
        *puVar6 = *puVar3;
        puVar3 = puVar4;
        puVar6 = puVar6 + 1;
      } while (puVar4 < *(undefined4 **)(param_1 + 0x18));
    }
    iVar5 = (int)puVar1 - (int)puVar2 >> 2;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + iVar5 * -4;
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) - iVar5;
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x14));
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00731800 | Classified: elementclient::Dialog__d@0x731800 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_00731800(undefined4 *param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_5c [72];
  undefined4 uStack_14;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined1 uStack_4;
  undefined3 uStack_3;
  
  puStack_8 = &UNK_008c9a58;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[10] = _DAT_009858e4;
  param_1[0xb] = _DAT_009858e4;
  param_1[0xc] = _DAT_00985a98;
  param_1[0xe] = _DAT_00985a98;
  param_1[0x1e] = _DAT_009858e4;
  param_1[0x29] = _DAT_009858e4;
  param_1[0x2a] = _DAT_009858e4;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  uStack_4 = 8;
  uStack_3 = 0;
  param_1[0x4c] = 0;
  iVar5 = 0;
  puVar1 = (uint *)&UNK_008eea08;
  do {
    if (0x10 < *puVar1) {
      iVar5 = *(int *)(&UNK_008eea08 + iVar5 * 4);
      goto LAB_007318b7;
    }
    puVar1 = puVar1 + 1;
    iVar5 = iVar5 + 1;
  } while ((int)puVar1 < 0x8eea78);
  iVar5 = -1;
LAB_007318b7:
  param_1[0x4f] = iVar5;
  if (iVar5 == 0) {
    param_1[0x4d] = 0;
  }
  else {
    uVar2 = func_0x00763250(iVar5 * 4);
    param_1[0x4d] = uVar2;
  }
  param_1[0x4e] = param_1[0x4d];
  param_1[0x50] = iVar5;
  for (; iVar5 != 0; iVar5 = iVar5 + -1) {
    puVar3 = (undefined4 *)param_1[0x4e];
    param_1[0x4e] = puVar3 + 1;
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = 0;
    }
  }
  uStack_4 = 9;
  param_1[0x54] = 0;
  iVar5 = 0;
  puVar1 = (uint *)&UNK_008eea08;
  do {
    if (0x40 < *puVar1) {
      iVar5 = *(int *)(&UNK_008eea08 + iVar5 * 4);
      goto LAB_0073193c;
    }
    puVar1 = puVar1 + 1;
    iVar5 = iVar5 + 1;
  } while ((int)puVar1 < 0x8eea78);
  iVar5 = -1;
LAB_0073193c:
  param_1[0x57] = iVar5;
  if (iVar5 == 0) {
    param_1[0x55] = 0;
  }
  else {
    uVar2 = func_0x00763250(iVar5 * 4);
    param_1[0x55] = uVar2;
  }
  param_1[0x56] = param_1[0x55];
  param_1[0x58] = iVar5;
  for (; iVar5 != 0; iVar5 = iVar5 + -1) {
    puVar3 = (undefined4 *)param_1[0x56];
    param_1[0x56] = puVar3 + 1;
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = 0;
    }
  }
  *param_1 = &UNK_008eea8c;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 1;
  param_1[0x14] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[0x33] = 0xff;
  param_1[0x34] = 0;
  _uStack_4 = CONCAT31(uStack_3,10);
  param_1[0x35] = 0;
  puVar3 = param_1 + 0x36;
  puVar6 = param_1 + 0x46;
  iVar5 = 4;
  do {
    *puVar6 = 0;
    puVar3[1] = 0;
    *puVar3 = 0;
    puVar3[9] = 0xffffffff;
    puVar3[8] = 0xffffffff;
    puVar6 = puVar6 + 1;
    puVar3 = puVar3 + 2;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  param_1[0x4a] = 0;
  param_1[0x52] = 0;
  param_1[0x51] = 0;
  *(undefined1 *)((int)param_1 + 0x6d) = 0;
  *(undefined1 *)(param_1 + 0x1b) = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  *(undefined1 *)((int)param_1 + 0x61) = 1;
  *(undefined1 *)(param_1 + 0x18) = 0;
  *(undefined1 *)((int)param_1 + 0x62) = 0;
  *(undefined1 *)((int)param_1 + 99) = 0;
  param_1[0x19] = 0xffff0001;
  param_1[0x1a] = 0xffff0001;
  param_1[0x17] = 0;
  *(undefined1 *)(param_1 + 0x1f) = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0xffffffff;
  uVar2 = GetTickCount();
  param_1[0x22] = uVar2;
  param_1[0x23] = 500;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  *(undefined1 *)(param_1 + 0x13) = 0;
  *(undefined1 *)((int)param_1 + 0x4d) = 0;
  param_1[0xd] = 0;
  param_1[0xf] = 10;
  param_1[0x10] = 0xff606060;
  iVar5 = rand();
  iVar4 = rand();
  sprintf(auStack_5c,0x97fea0,iVar5 * iVar4);
  func_0x007638a0(auStack_5c);
  func_0x007638a0(&DAT_009b3c44);
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  *unaff_FS_OFFSET = uStack_14;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00731b10 | Classified: AUIDialog::vfunc_slot_6 */
/* ==================================================================== */

undefined4 __thiscall FUN_00731b10(undefined4 param_1,byte param_2)

{
  FUN_00731b30();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00731b30 | Classified: ElementClient::proc_731b30 */
/* ==================================================================== */

void __fastcall FUN_00731b30(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  uint uVar6;
  uint uStack_18;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008c9b00;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008eea8c;
  uStack_4._0_1_ = 10;
  uStack_4._1_3_ = 0;
  uStack_18 = 0;
  if (param_1[0x58] != 0) {
    do {
      puVar4 = *(undefined4 **)(param_1[0x55] + uStack_18 * 4);
      while (puVar4 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar4;
        func_0x00516560(0);
        func_0x00763260(puVar4);
        puVar4 = puVar1;
      }
      uStack_18 = uStack_18 + 1;
      *(undefined4 *)(param_1[0x55] + -4 + uStack_18 * 4) = 0;
    } while (uStack_18 < (uint)param_1[0x58]);
  }
  param_1[0x54] = 0;
  uStack_4 = CONCAT31(uStack_4._1_3_,9);
  func_0x006e04e0(param_1[0x55],param_1[0x55] + param_1[0x58] * 4);
  if (param_1[0x55] != 0) {
    func_0x00763260(param_1[0x55]);
  }
  uStack_c._0_1_ = 0xb;
  uVar6 = 0;
  if (param_1[0x50] != 0) {
    do {
      puVar4 = *(undefined4 **)(param_1[0x4d] + uVar6 * 4);
      while (puVar4 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar4;
        func_0x00739480(0);
        func_0x00763260(puVar4);
        puVar4 = puVar1;
      }
      uVar6 = uVar6 + 1;
      *(undefined4 *)(param_1[0x4d] + -4 + uVar6 * 4) = 0;
    } while (uVar6 < (uint)param_1[0x50]);
  }
  param_1[0x4c] = 0;
  uStack_c = CONCAT31(uStack_c._1_3_,8);
  func_0x006e04e0(param_1[0x4d],param_1[0x4d] + param_1[0x50] * 4);
  if (param_1[0x4d] != 0) {
    func_0x00763260(param_1[0x4d]);
  }
  func_0x007394b0(param_1[0x2f],param_1[0x2f] + param_1[0x32] * 0xc);
  if (param_1[0x2f] != 0) {
    func_0x00763260(param_1[0x2f]);
  }
  func_0x007637f0();
  func_0x007637f0();
  func_0x007637f0();
  FUN_00765200();
  FUN_00765200();
  func_0x007637f0();
  func_0x007637f0();
  uVar2 = param_1[6];
  uVar6 = uVar2 + param_1[9] * 0x14;
  if (uVar2 != uVar6) {
    uVar5 = uVar6;
    if (uVar6 < (uint)param_1[7]) {
      do {
        func_0x007393b0(uVar5);
        uVar5 = uVar5 + 0x14;
      } while (uVar5 < (uint)param_1[7]);
    }
    iVar3 = (int)(uVar6 - uVar2) / 0x14;
    param_1[7] = param_1[7] + iVar3 * -0x14;
    param_1[9] = param_1[9] - iVar3;
  }
  if (param_1[6] != 0) {
    func_0x00763260(param_1[6]);
  }
  *unaff_FS_OFFSET = unaff_ESI;
  return;
}


/* ==================================================================== */
/* Address: 0x00733770 | Classified: elementclient::AUIDialog__InitFrame____Dialog_n@0x733770 */
/* ==================================================================== */

undefined1 __thiscall FUN_00733770(int param_1,int param_2)

{
  char *pcVar1;
  char cVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint unaff_EBX;
  int unaff_EBP;
  undefined4 unaff_ESI;
  uint unaff_EDI;
  char *pcVar11;
  undefined4 *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  uint uStack_64;
  undefined4 uStack_2c;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008c9c48;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_64 = 1;
  cVar2 = func_0x0076f4a0();
  if (cVar2 == '\0') {
    unaff_retaddr = 0x1b7;
    goto LAB_00734031;
  }
  pcVar1 = (char *)(param_2 + 4);
  cVar2 = FUN_007359c0(pcVar1);
  if (cVar2 == '\0') {
    uVar3 = func_0x00739700(0x1b9,1,0x980434);
    goto LAB_00734049;
  }
  cVar2 = func_0x0076f4a0(1);
  if (cVar2 == '\0') {
    unaff_retaddr = 0x1bb;
  }
  else {
    uVar4 = atoi(pcVar1);
    *(undefined4 *)(param_1 + 0x54) = uVar4;
    cVar2 = func_0x0076f4a0(1);
    if (cVar2 == '\0') {
      unaff_retaddr = 0x1be;
    }
    else {
      uVar4 = atoi(pcVar1);
      *(undefined4 *)(param_1 + 0x58) = uVar4;
      cVar2 = func_0x0076f4a0(1);
      if (cVar2 == '\0') {
        unaff_retaddr = 0x1c1;
      }
      else {
        uVar4 = atoi(pcVar1);
        *(undefined4 *)(param_1 + 0x70) = uVar4;
        cVar2 = func_0x0076f4a0(1);
        if (cVar2 == '\0') {
          unaff_retaddr = 0x1c4;
        }
        else {
          uVar4 = atoi(pcVar1);
          *(undefined4 *)(param_1 + 0x74) = uVar4;
          cVar2 = func_0x0076f4a0(1);
          if (cVar2 == '\0') {
            unaff_retaddr = 0x1c7;
          }
          else {
            iVar5 = atoi(pcVar1);
            if (-1 < iVar5) {
              uVar4 = FUN_00737a30(iVar5);
              FUN_00765230(uVar4);
            }
            cVar2 = func_0x0076f4a0(1);
            if (cVar2 == '\0') {
              unaff_retaddr = 0x1cc;
            }
            else {
              uVar4 = atoi(pcVar1);
              uVar4 = FUN_00737a30(uVar4);
              FUN_00765050(uVar4);
              if (*(int *)(unaff_EBP + -8) == 0) {
                FUN_00765230(0x95b0d4);
              }
              FUN_00744150();
              FUN_00744590(&stack0xffffffac,0x980464);
              FUN_007652d0(unaff_ESI);
              if (1 < unaff_EBX) {
                uVar6 = _wtoi(*(undefined4 *)(unaff_EDI + 4));
                *(undefined4 *)(param_1 + 0x44) = uVar6;
              }
              if (2 < unaff_EBX) {
                uVar6 = _wtoi(*(undefined4 *)(unaff_EDI + 8));
                *(undefined4 *)(param_1 + 0x48) = uVar6;
              }
              if (3 < unaff_EBX) {
                iVar5 = _wtoi(*(undefined4 *)(unaff_EDI + 0xc));
                *(bool *)(param_1 + 0x4c) = iVar5 != 0;
              }
              if (4 < unaff_EBX) {
                iVar5 = _wtoi(*(undefined4 *)(unaff_EDI + 0x10));
                *(bool *)(param_1 + 0x4d) = iVar5 != 0;
              }
              cVar2 = func_0x0076f4a0(1);
              if (cVar2 == '\0') {
LAB_00733ced:
                func_0x004bfa20(1,unaff_EBP * 4 + 1);
              }
              else {
                atoi(pcVar1);
                cVar2 = FUN_00737e30(uVar4,*(undefined4 *)(param_1 + 0x3c),
                                     *(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x44)
                                     ,*(undefined4 *)(param_1 + 0x48),
                                     *(undefined1 *)(param_1 + 0x4c),*(undefined1 *)(param_1 + 0x4d)
                                    );
                if (cVar2 == '\0') goto LAB_00733ced;
                iVar5 = 0;
                do {
                  cVar2 = func_0x0076f4a0(1);
                  if (cVar2 == '\0') goto LAB_00733a8b;
                  iVar10 = -1;
                  pcVar11 = pcVar1;
                  do {
                    if (iVar10 == 0) break;
                    iVar10 = iVar10 + -1;
                    cVar2 = *pcVar11;
                    pcVar11 = pcVar11 + 1;
                  } while (cVar2 != '\0');
                  if ((iVar10 != -2) && (cVar2 = FUN_00734500(pcVar1,iVar5), cVar2 == '\0')) {
                    uVar3 = func_0x00739700(0x1ed,1,0x980400);
                    uVar7 = unaff_EBP * 4 + 1;
                    if (uVar7 != 1) {
                      for (; uVar7 < unaff_EDI; uVar7 = uVar7 + 4) {
                        FUN_007652d0(uVar7);
                        uStack_64 = uStack_64 + 4;
                      }
                      for (; uStack_64 < unaff_EDI; uStack_64 = uStack_64 + 4) {
                        func_0x004bfa90(0);
                      }
                    }
                    func_0x00763260(1);
                    FUN_007441c0();
                    FUN_00765200();
                    goto LAB_00734049;
                  }
                  if ((iVar5 != 2) && (iVar5 != 3)) goto LAB_00733a6c;
                  cVar2 = func_0x0076f4a0(1);
                  if (cVar2 == '\0') {
LAB_00733a8b:
                    uVar7 = unaff_EBP * 4 + 1;
                    if (uVar7 != 1) {
                      for (; uVar7 < unaff_EDI; uVar7 = uVar7 + 4) {
                        FUN_007652d0(uVar7);
                        uStack_64 = uStack_64 + 4;
                      }
                      for (; uStack_64 < unaff_EDI; uStack_64 = uStack_64 + 4) {
                        func_0x004bfa90(0);
                      }
                    }
                    goto LAB_0073400a;
                  }
                  uVar4 = atoi(pcVar1);
                  *(undefined4 *)(param_1 + 0xd8 + iVar5 * 8) = uVar4;
                  cVar2 = func_0x0076f4a0(1);
                  if (cVar2 == '\0') goto LAB_00733a8b;
                  uVar4 = atoi(pcVar1);
                  *(undefined4 *)(param_1 + 0xdc + iVar5 * 8) = uVar4;
                  if (iVar5 == 2) {
                    cVar2 = func_0x0076f4a0(1);
                    if (cVar2 != '\0') {
                      uVar4 = atoi(pcVar1);
                      *(undefined4 *)(param_1 + 0x108) = uVar4;
                      cVar2 = func_0x0076f4a0(1);
                      if (cVar2 != '\0') {
                        uVar4 = atoi(pcVar1);
                        *(undefined4 *)(param_1 + 0x10c) = uVar4;
                        goto LAB_00733a6c;
                      }
                    }
                    goto LAB_00733a8b;
                  }
LAB_00733a6c:
                  iVar5 = iVar5 + 1;
                } while (iVar5 < 4);
                cVar2 = func_0x0076f4a0(1);
                if (cVar2 == '\0') {
                  uVar7 = unaff_EBP * 4 + 1;
                  if (uVar7 != 1) {
                    for (; uVar7 < unaff_EDI; uVar7 = uVar7 + 4) {
                      FUN_007652d0(uVar7);
                      uStack_64 = uStack_64 + 4;
                    }
                    for (; uStack_64 < unaff_EDI; uStack_64 = uStack_64 + 4) {
                      func_0x004bfa90(0);
                    }
                  }
                }
                else {
                  uVar7 = atoi(pcVar1);
                  cVar2 = func_0x0076f4a0(1);
                  if (cVar2 == '\0') {
                    uVar7 = unaff_EBP * 4 + 1;
                    if (uVar7 != 1) {
                      for (; uVar7 < unaff_EDI; uVar7 = uVar7 + 4) {
                        FUN_007652d0(uVar7);
                        uStack_64 = uStack_64 + 4;
                      }
                      for (; uStack_64 < unaff_EDI; uStack_64 = uStack_64 + 4) {
                        func_0x004bfa90(0);
                      }
                    }
                  }
                  else {
                    uVar8 = atoi(pcVar1);
                    cVar2 = func_0x0076f4a0(1);
                    if (cVar2 == '\0') {
                      uVar7 = unaff_EBP * 4 + 1;
                      if (uVar7 != 1) {
                        for (; uVar7 < unaff_EDI; uVar7 = uVar7 + 4) {
                          FUN_007652d0(uVar7);
                          uStack_64 = uStack_64 + 4;
                        }
                        for (; uStack_64 < unaff_EDI; uStack_64 = uStack_64 + 4) {
                          FUN_00765200();
                        }
                      }
                    }
                    else {
                      uVar9 = atoi(pcVar1);
                      *(uint *)(param_1 + 0x40) = ((uVar7 | 0xffffff00) << 8 | uVar8) << 8 | uVar9;
                      cVar2 = func_0x0076f4a0(1);
                      if (cVar2 == '\0') {
                        uVar7 = unaff_EBP * 4 + 1;
                        if (uVar7 != 1) {
                          for (; uVar7 < unaff_EDI; uVar7 = uVar7 + 4) {
                            FUN_007652d0(uVar7);
                            uStack_64 = uStack_64 + 4;
                          }
                          for (; uStack_64 < unaff_EDI; uStack_64 = uStack_64 + 4) {
                            FUN_00765200();
                          }
                        }
                      }
                      else {
                        uVar4 = atoi(pcVar1);
                        FUN_00737ed0(uVar4);
                        cVar2 = func_0x0076f4a0(1);
                        if (cVar2 != '\0') {
                          iVar5 = atoi(pcVar1);
                          *(bool *)(param_1 + 0x6c) = iVar5 != 0;
                          uVar4 = 0x1000000;
                          uVar3 = 1;
                          uVar7 = unaff_EBP * 4 + 1;
                          if (uVar7 != 1) {
                            for (; uVar7 < unaff_EDI; uVar7 = uVar7 + 4) {
                              FUN_007652d0(uVar7);
                              uStack_64 = uStack_64 + 4;
                            }
                            uVar3 = (undefined1)((uint)uVar4 >> 0x18);
                            for (; uStack_64 < unaff_EDI; uStack_64 = uStack_64 + 4) {
                              FUN_00765200();
                              uVar3 = (undefined1)((uint)uVar4 >> 0x18);
                            }
                          }
                          func_0x00763260(1);
                          FUN_007441c0();
                          FUN_00765200();
                          goto LAB_00734049;
                        }
                        uVar7 = unaff_EBP * 4 + 1;
                        if (uVar7 != 1) {
                          for (; uVar7 < unaff_EDI; uVar7 = uVar7 + 4) {
                            FUN_007652d0(uVar7);
                            uStack_64 = uStack_64 + 4;
                          }
                          for (; uStack_64 < unaff_EDI; uStack_64 = uStack_64 + 4) {
                            FUN_00765200();
                          }
                        }
                      }
                    }
                  }
                }
              }
LAB_0073400a:
              func_0x00763260(1);
              FUN_007441c0();
              FUN_00765200();
            }
          }
        }
      }
    }
  }
LAB_00734031:
  func_0x00739700(unaff_retaddr,1,0x9803cc);
  uVar3 = (undefined1)((uint)unaff_retaddr >> 0x18);
LAB_00734049:
  *unaff_FS_OFFSET = uStack_2c;
  return uVar3;
}


/* ==================================================================== */
/* Address: 0x00734060 | Classified: elementclient::MENUITEM@0x734060 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __thiscall FUN_00734060(int param_1,int param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined4 *unaff_FS_OFFSET;
  int iStack_3c;
  uint uStack_38;
  int *piStack_2c;
  int iStack_28;
  int iStack_24;
  undefined1 auStack_20 [4];
  undefined1 uStack_1c;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008c9cb8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_14 = _DAT_009858e4;
  uStack_10 = _DAT_00985a98;
  uStack_4._0_1_ = 0;
  uStack_4._1_3_ = 0;
  if (*(uint *)(param_2 + 0x808) <= *(uint *)(param_2 + 0x80c)) {
LAB_007343e0:
    iVar7 = *(int *)(param_1 + 0xb0) + *(int *)(param_1 + 0x3c);
    iVar3 = *(int *)(param_1 + 0xb8);
    *(undefined4 *)(param_1 + 0x50) = 2;
    *(int *)(param_1 + 0xb0) = iVar7;
    iVar8 = *(int *)(param_1 + 0xb4);
    *(float *)(iVar3 + 0x70) = (float)iVar7 / (float)*(int *)(iVar3 + 0x34);
    *(float *)(*(int *)(param_1 + 0xb8) + 0x74) = (float)iVar8 / (float)*(int *)(iVar3 + 0x38);
    iVar8 = 0;
    iVar3 = 0;
    if (*(int *)(param_1 + 0xd0) != 0) {
      piVar6 = (int *)FUN_007537a0(auStack_20);
      iVar8 = *piVar6;
      iVar3 = piVar6[1];
    }
    *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0xb0) + iVar8;
    *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0xb4) * *(int *)(param_1 + 200) + iVar3;
    uStack_4 = 7;
    FUN_00765200();
    uStack_4 = 0xffffffff;
    func_0x007637f0();
    uVar2 = 1;
LAB_0073449a:
    *unaff_FS_OFFSET = uStack_c;
    return uVar2;
  }
LAB_007340b1:
  cVar1 = func_0x0076f4a0(1);
  if (cVar1 == '\0') goto LAB_007343e0;
  iVar8 = param_2 + 4;
  iVar3 = _strcmpi(iVar8,0x9804dc);
  if (iVar3 == 0) {
    cVar1 = func_0x0076f4a0(1);
    if (cVar1 == '\0') {
      uVar4 = 0x238;
    }
    else {
      uVar4 = atoi(iVar8);
      uVar4 = FUN_00737a30(uVar4);
      FUN_00765230(uVar4);
      if (*(int *)(param_1 + 0x34) == 0) {
        FUN_007537e0();
      }
      uVar4 = FUN_00737a30(2,&uStack_18);
      puVar5 = (undefined4 *)func_0x004cd770(&stack0xffffffc0,uVar4);
      uStack_10 = CONCAT31(uStack_10._1_3_,1);
      piVar6 = (int *)func_0x0073c830(&piStack_2c,*puVar5,0xffffffff);
      iVar3 = *piVar6;
      iVar7 = piVar6[1];
      uStack_1c = 0;
      FUN_00765200();
      iVar10 = *(int *)(param_1 + 0xb0);
      if (*(int *)(param_1 + 0xb0) <= iVar3) {
        iVar10 = iVar3;
      }
      *(int *)(param_1 + 0xb0) = iVar10;
      if (iVar7 < *(int *)(param_1 + 0xb4)) {
        iVar7 = *(int *)(param_1 + 0xb4);
      }
      *(int *)(param_1 + 0xb4) = iVar7;
      cVar1 = func_0x0076f4a0(1);
      if (cVar1 != '\0') {
        func_0x007638a0(iVar8);
        uVar9 = *(uint *)(param_1 + 200);
        piVar6 = (int *)(param_1 + 0xbc);
        uStack_18 = 0;
        uStack_17 = 1;
        piStack_2c = piVar6;
        if (uVar9 == *(uint *)(param_1 + 0xc4)) {
          if (uVar9 + 1 < 5) {
            iStack_3c = 5;
          }
          else {
            iStack_3c = uVar9 + 3 + (uVar9 >> 1);
          }
          iVar7 = func_0x00763250(iStack_3c * 0xc);
          uStack_38 = 0;
          iVar8 = iVar7;
          iVar3 = *piVar6;
          if (*(int *)(param_1 + 200) != 0) {
            do {
              uStack_4._0_1_ = 2;
              iVar10 = iVar3;
              iStack_28 = iVar8;
              iStack_24 = iVar8;
              if (iVar8 != 0) {
                iVar10 = iVar3 + 0xc;
                func_0x007393e0(iVar3);
              }
              uStack_38 = uStack_38 + 1;
              uStack_4._0_1_ = 0;
              iVar8 = iVar8 + 0xc;
              iVar3 = iVar10;
            } while (uStack_38 < *(uint *)(param_1 + 200));
          }
          uVar9 = 0;
          if (*(int *)(param_1 + 200) != 0) {
            do {
              FUN_007344b0();
              uVar9 = uVar9 + 1;
            } while (uVar9 < *(uint *)(param_1 + 200));
          }
          if (*piVar6 != 0) {
            func_0x00763260(*piVar6);
          }
          *piVar6 = iVar7;
          *(int *)(param_1 + 0xc4) = iStack_3c;
          *(int *)(param_1 + 0xc0) = iVar7 + *(int *)(param_1 + 200) * 0xc;
        }
        iStack_24 = *(int *)(param_1 + 0xc0);
        uStack_4._0_1_ = 3;
        if (iStack_24 != 0) {
          func_0x007393e0(&uStack_18);
        }
        uStack_4._0_1_ = 0;
        *(int *)(param_1 + 200) = *(int *)(param_1 + 200) + 1;
        *(int *)(param_1 + 0xc0) = *(int *)(param_1 + 0xc0) + 0xc;
        goto LAB_00734333;
      }
      uVar4 = 0x246;
    }
  }
  else {
    iVar3 = _strcmpi(iVar8,0x9804d4);
    if (iVar3 != 0) {
      func_0x0076f760();
LAB_00734333:
      if (*(uint *)(param_2 + 0x808) <= *(uint *)(param_2 + 0x80c)) goto LAB_007343e0;
      goto LAB_007340b1;
    }
    cVar1 = func_0x0076f4a0(1);
    if (cVar1 == '\0') {
      uVar4 = 0x24f;
      goto LAB_00734351;
    }
    iStack_24 = func_0x00763250(0x8c);
    uStack_4._0_1_ = 4;
    if (iStack_24 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = func_0x0078bd00();
    }
    uStack_4._0_1_ = 0;
    *(int *)(param_1 + 0xb8) = iVar3;
    if (iVar3 == 0) {
      uVar2 = func_0x00739700(0x253,1,0x98046c);
      uStack_4 = 5;
      FUN_00765200();
      uStack_4 = 0xffffffff;
      func_0x007637f0();
      goto LAB_0073449a;
    }
    cVar1 = func_0x0078c020(*(undefined4 *)(param_1 + 0x10),iVar8,0xffff00ff);
    if (cVar1 != '\0') goto LAB_00734333;
    uVar4 = 0x255;
  }
LAB_00734351:
  uVar2 = func_0x00739700(uVar4,1,0x98049c);
  uStack_4 = 6;
  FUN_00765200();
  uStack_4 = 0xffffffff;
  func_0x007637f0();
  goto LAB_0073449a;
}


/* ==================================================================== */
/* Address: 0x007344b0 | Classified: AngelicaUI::proc_7344b0 */
/* ==================================================================== */

void FUN_007344b0(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008c9cdb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  FUN_00765200();
  uStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x00734500 | Classified: elementclient::AUIDialog__InitIndirect____Faile@0x734500 */
/* ==================================================================== */

undefined4 __thiscall FUN_00734500(int param_1,char *param_2,int param_3)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *unaff_FS_OFFSET;
  int aiStack_3c [12];
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008c9d06;
  *unaff_FS_OFFSET = &uStack_c;
  iVar5 = -1;
  pcVar7 = param_2;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  if (iVar5 != -2) {
    if (param_3 == 0) {
      puVar9 = *(undefined4 **)(param_1 + 0xd0);
    }
    else {
      if (param_3 != 2) {
        if (*(int *)(param_1 + 0x118 + param_3 * 4) != 0) {
          func_0x0078c040();
          puVar9 = *(undefined4 **)(param_1 + 0x118 + param_3 * 4);
          if (puVar9 != (undefined4 *)0x0) {
            (**(code **)*puVar9)(1);
          }
          *(undefined4 *)(param_1 + 0x118 + param_3 * 4) = 0;
        }
        iVar5 = func_0x00763250(0x8c);
        uStack_4 = 1;
        if (iVar5 == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = func_0x0078bd00();
        }
        uStack_4 = 0xffffffff;
        *(int *)(param_1 + 0x118 + param_3 * 4) = iVar5;
        if (iVar5 == 0) {
          uVar3 = 0;
          goto LAB_007346ee;
        }
        cVar2 = func_0x0078c020(*(undefined4 *)(param_1 + 0x10),param_2,0xffff00ff);
        if (cVar2 == '\0') {
          uVar3 = func_0x00739700(0x29b,1,0x980570,param_3);
          goto LAB_007346ee;
        }
        if (param_3 == 3) {
          iVar8 = 3;
          iVar5 = *(int *)(*(int *)(param_1 + 0x124) + 0x38);
          iVar1 = *(int *)(*(int *)(param_1 + 0x124) + 0x34);
          piVar4 = aiStack_3c + 2;
          iVar6 = 0;
          do {
            piVar4[-1] = iVar6;
            iVar6 = iVar6 + iVar5 / 3;
            piVar4[-2] = 0;
            *piVar4 = iVar1;
            piVar4[1] = iVar6;
            piVar4 = piVar4 + 4;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
          cVar2 = func_0x0078c600(3,aiStack_3c);
          if (cVar2 == '\0') {
            uVar3 = func_0x00739700(0x2a5,1,0x980524,3);
            goto LAB_007346ee;
          }
        }
        goto LAB_007346ec;
      }
      puVar9 = *(undefined4 **)(param_1 + 0xd4);
    }
    if (puVar9 != (undefined4 *)0x0) {
      FUN_00753080();
      (**(code **)*puVar9)(1);
    }
    iVar5 = func_0x00763250(0x14);
    uStack_4 = 0;
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_00752d70();
    }
    uStack_4 = 0xffffffff;
    if (iVar5 == 0) {
      uVar3 = 0;
      goto LAB_007346ee;
    }
    cVar2 = FUN_00752dc0(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10),param_2);
    if (cVar2 == '\0') {
      uVar3 = func_0x00739700(0x28c,1,0x9804e8);
      goto LAB_007346ee;
    }
    if (param_3 == 0) {
      *(int *)(param_1 + 0xd0) = iVar5;
    }
    else {
      *(int *)(param_1 + 0xd4) = iVar5;
    }
  }
LAB_007346ec:
  uVar3 = 1;
LAB_007346ee:
  *unaff_FS_OFFSET = uStack_c;
  return uVar3;
}


/* ==================================================================== */
/* Address: 0x00734710 | Classified: AUIDialog::vfunc_slot_3 */
/* ==================================================================== */

undefined4 __fastcall FUN_00734710(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  undefined4 *puStack_8;
  
  iVar6 = *(int *)(param_1 + 0x144);
  while (iVar6 != 0) {
    if (*(int **)(iVar6 + 8) != (int *)0x0) {
      (**(code **)(**(int **)(iVar6 + 8) + 0xc))();
      if (*(undefined4 **)(iVar6 + 8) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(iVar6 + 8))(1);
      }
      *(undefined4 *)(iVar6 + 8) = 0;
    }
    iVar8 = *(int *)(iVar6 + 0xc);
    func_0x00763260(iVar6);
    iVar6 = iVar8;
  }
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(undefined4 *)(param_1 + 0x144) = 0;
  if (*(int *)(param_1 + 0xd0) != 0) {
    FUN_00753080();
    if (*(undefined4 **)(param_1 + 0xd0) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0xd0))(1);
    }
    *(undefined4 *)(param_1 + 0xd0) = 0;
  }
  if (*(int *)(param_1 + 0xd4) != 0) {
    FUN_00753080();
    if (*(undefined4 **)(param_1 + 0xd4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0xd4))(1);
    }
    *(undefined4 *)(param_1 + 0xd4) = 0;
  }
  piVar7 = (int *)(param_1 + 0x118);
  iVar6 = 4;
  do {
    if (*piVar7 != 0) {
      func_0x0078c040();
      if ((undefined4 *)*piVar7 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar7)(1);
      }
      *piVar7 = 0;
    }
    piVar7 = piVar7 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  if (*(int *)(param_1 + 0xb8) != 0) {
    func_0x0078c040();
    if (*(undefined4 **)(param_1 + 0xb8) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0xb8))(1);
    }
    *(undefined4 *)(param_1 + 0xb8) = 0;
  }
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    iVar8 = 0;
    do {
      if (*(int *)(iVar8 + *(int *)(param_1 + 0x18)) != 0) {
        FUN_00430850();
        puVar2 = *(undefined4 **)(iVar8 + *(int *)(param_1 + 0x18));
        if (puVar2 != (undefined4 *)0x0) {
          (**(code **)*puVar2)(1);
        }
        *(undefined4 *)(iVar8 + *(int *)(param_1 + 0x18)) = 0;
      }
      iVar6 = iVar6 + 1;
      iVar8 = iVar8 + 0x14;
    } while (iVar6 < *(int *)(param_1 + 0x24));
  }
  iVar6 = *(int *)(param_1 + 0x24);
  puVar3 = *(undefined4 **)(param_1 + 0x18);
  puVar2 = puVar3 + iVar6 * 5;
  if (puVar3 != puVar2) {
    if (puVar2 < *(undefined4 **)(param_1 + 0x1c)) {
      puVar4 = puVar2 + 3;
      puVar5 = puVar3 + 4;
      puStack_8 = puVar3;
      do {
        *puStack_8 = puVar4[-3];
        puVar5[-3] = puVar4[-2];
        puVar5[-2] = puVar4[-1];
        *(undefined4 *)((int)puVar4 + ((int)puVar3 - (int)puVar2)) = *puVar4;
        *puVar5 = puVar4[1];
        puStack_8 = puStack_8 + 5;
        puVar1 = puVar4 + 2;
        puVar4 = puVar4 + 5;
        puVar5 = puVar5 + 5;
      } while (puVar1 < *(undefined4 **)(param_1 + 0x1c));
    }
    iVar8 = ((int)puVar2 - (int)puVar3) / 0x14;
    iVar6 = *(int *)(param_1 + 0x24) - iVar8;
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + iVar8 * -0x14;
    *(int *)(param_1 + 0x24) = iVar6;
  }
  return CONCAT31((int3)((uint)iVar6 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007348e0 | Classified: AngelicaUI::proc_7348e0 */
/* ==================================================================== */

void __thiscall FUN_007348e0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  for (iVar1 = *(int *)(param_1 + 0x144); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
    iVar2 = FUN_00741f50();
    if ((iVar2 == 10) && (iVar2 = FUN_0074db00(), iVar2 == param_2)) {
      iVar2 = FUN_0074c2b0();
      FUN_0074c290(iVar2 == param_3);
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00734940 | Classified: elementclient::IDCANCEL@0x734940 */
/* ==================================================================== */

undefined4 __thiscall FUN_00734940(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  iVar2 = -1;
  pcVar3 = param_2;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (iVar2 == -2) {
    return 1;
  }
  uVar4 = 1;
  if (*(int *)(param_1 + 0x50) != 1) {
    uVar4 = (**(code **)(**(int **)(param_1 + 0x14) + 0x14))(param_2,param_1);
    return uVar4;
  }
  iVar2 = _strcmpi(param_2,0x95baec);
  if (iVar2 == 0) {
    uVar4 = (**(code **)(**(int **)(param_1 + 0x14) + 0x18))(2,param_1);
    return uVar4;
  }
  iVar2 = _strcmpi(param_2,0x97f9f0);
  if (iVar2 == 0) {
    uVar4 = (**(code **)(**(int **)(param_1 + 0x14) + 0x18))(6,param_1);
    return uVar4;
  }
  iVar2 = _strcmpi(param_2,0x97f9e8);
  if (iVar2 == 0) {
    uVar4 = 7;
  }
  uVar4 = (**(code **)(**(int **)(param_1 + 0x14) + 0x18))(uVar4,param_1);
  return uVar4;
}


/* ==================================================================== */
/* Address: 0x00734a00 | Classified: elementclient::IDCANCEL@0x734a00 */
/* ==================================================================== */

undefined1 __thiscall
FUN_00734a00(int param_1,int param_2,uint param_3,undefined4 param_4,char param_5)

{
  bool bVar1;
  undefined1 uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int unaff_retaddr;
  undefined1 uVar12;
  int iStack_2c;
  int iStack_28;
  int *piStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  undefined1 auStack_10 [4];
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(int *)(param_1 + 0x50) == 2) {
    uVar2 = FUN_00735390(param_2,param_3,param_4);
    return uVar2;
  }
  if (param_5 == '\0') {
    if (*(char *)(param_1 + 0x60) != '\0') {
      FUN_00735130(param_2,param_3,param_4);
      iVar5 = *(int *)(param_1 + 0x94);
      if (iVar5 == 0) {
        iVar5 = *(int *)(param_1 + 0x98);
      }
      uVar2 = (undefined1)((uint)iVar5 >> 0x18);
      (**(code **)(**(int **)(param_1 + 0x14) + 0x20))(param_2,param_3,param_4,param_1);
      return uVar2;
    }
    iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 0xa8);
    piStack_24 = (int *)(iVar5 + 0x14);
    iVar11 = (int)(short)param_4 - *piStack_24;
    iVar5 = (int)(short)((uint)param_4 >> 0x10) - *(int *)(iVar5 + 0x18);
    if (param_2 == 0x20a) {
      iStack_2c = 0;
      iStack_28 = 0;
      ClientToScreen(*(undefined4 *)(*(int *)(param_1 + 0x10) + 4),&iStack_2c);
      iVar11 = iVar11 - iStack_2c;
      iVar5 = iVar5 - iStack_28;
    }
    if (((((*(int *)(param_1 + 0x90) != 0) && (cVar3 = FUN_00741f00(), cVar3 != '\0')) &&
         (cVar3 = FUN_00741f30(), cVar3 != '\0')) ||
        (((*(int *)(param_1 + 0x98) != 0 && (cVar3 = FUN_00741f00(), cVar3 != '\0')) &&
         (cVar3 = FUN_00741f30(), cVar3 != '\0')))) &&
       ((*(int *)(param_1 + 0x98) != 0 ||
        (((piVar6 = (int *)(**(code **)(**(int **)(param_1 + 0x90) + 0x20))(&iStack_20),
          *piVar6 <= iVar11 && (iVar11 < piVar6[2])) &&
         ((piVar6[1] <= iVar5 && (iVar5 < piVar6[3])))))))) {
      piVar6 = *(int **)(param_1 + 0x98);
      if (piVar6 == (int *)0x0) {
        piVar6 = *(int **)(param_1 + 0x90);
      }
      cVar3 = FUN_00742610();
      if (cVar3 != '\0') {
        return 0;
      }
      cVar3 = FUN_00742630();
      if (cVar3 != '\0') {
        func_0x007638a0(&DAT_009b3c44);
        (**(code **)(*piVar6 + 0x1c))(unaff_retaddr,param_2,param_4);
        if (0 < *(int *)(*(int *)(param_1 + 0x78) + -8)) {
          FUN_00734940(*(int *)(param_1 + 0x78));
        }
        (**(code **)(**(int **)(param_1 + 0x14) + 0x20))(uStack_c,uStack_8,param_4,param_1,piVar6);
        return 1;
      }
    }
    iStack_2c = *(int *)(param_1 + 0x148);
    *(undefined4 *)(param_1 + 0x94) = 0;
    if (iStack_2c != 0) {
      do {
        piVar6 = *(int **)(iStack_2c + 8);
        cVar3 = FUN_00741f00();
        if (((cVar3 != '\0') && (cVar3 = FUN_00741f30(), cVar3 != '\0')) &&
           (piVar6 != *(int **)(param_1 + 0x90))) {
          bVar1 = false;
          puVar7 = (undefined4 *)(**(code **)(*piVar6 + 0x20))(auStack_10);
          piStack_24 = (int *)*puVar7;
          iStack_20 = puVar7[1];
          iStack_1c = puVar7[2];
          iStack_18 = puVar7[3];
          iVar8 = FUN_007537e0();
          if (iVar8 != 0) {
            iVar8 = FUN_007537e0();
            iVar9 = *(int *)(iVar8 + 0x14) - *piStack_24;
            iVar10 = *(int *)(iVar8 + 0x18) - piStack_24[1];
            if (((iVar11 < iVar9) || (*(int *)(iVar8 + 0x1c) + iVar9 <= iVar11)) ||
               ((iVar5 < iVar10 || (*(int *)(iVar8 + 0x20) + iVar10 <= iVar5)))) {
              bVar1 = false;
            }
            else {
              bVar1 = true;
            }
            bVar1 = !bVar1;
          }
          if (((iStack_20 <= iVar11) && (iVar11 < iStack_18)) &&
             ((iStack_1c <= iVar5 &&
              (((iVar5 < iStack_14 && (!bVar1)) && (cVar3 = FUN_00742610(), cVar3 == '\0')))))) {
            cVar3 = FUN_00742630();
            if (cVar3 != '\0') {
              if (((*(int **)(param_1 + 0x90) != piVar6) && (param_2 != 0x200)) &&
                 (((param_2 != 0x20a && ((param_2 != 0x202 && (param_2 != 0x205)))) &&
                  (param_2 != 0x208)))) {
                FUN_007373a0(piVar6);
              }
              *(undefined4 *)(param_1 + 0x68) = 0xffff0001;
              *(undefined4 *)(param_1 + 100) = 0xffff0001;
              func_0x007638a0(&DAT_009b3c44);
              (**(code **)(*piVar6 + 0x1c))(unaff_retaddr,param_2,param_3);
              if (0 < *(int *)(*(int *)(param_1 + 0x78) + -8)) {
                FUN_00734940(*(int *)(param_1 + 0x78));
              }
              (**(code **)(**(int **)(param_1 + 0x14) + 0x20))
                        (uStack_c,param_2,uStack_4,param_1,piVar6);
              return 1;
            }
            if (*(int *)(param_1 + 0x94) == 0) {
              *(int **)(param_1 + 0x94) = piVar6;
            }
          }
        }
        iStack_2c = *(int *)(iStack_2c + 4);
      } while (iStack_2c != 0);
      iStack_2c = 0;
    }
    if (((param_2 == 0x201) || (param_2 == 0x202)) || ((param_2 == 0x200 && ((param_3 & 1) != 0))))
    {
      FUN_007373a0(0);
    }
    FUN_00735130(param_2,param_3,param_4);
    uVar2 = (undefined1)(param_3 >> 0x18);
    (**(code **)(**(int **)(param_1 + 0x14) + 0x20))
              (param_2,uStack_4,param_4,param_1,*(undefined4 *)(param_1 + 0x94));
  }
  else {
    func_0x007638a0(&DAT_009b3c44);
    if ((*(int *)(param_1 + 0x90) != 0) && (cVar3 = FUN_00741f30(), cVar3 != '\0')) {
      (**(code **)(**(int **)(param_1 + 0x90) + 0x1c))(unaff_retaddr,param_2,param_3);
    }
    uVar2 = (undefined1)((uint)*(undefined4 *)(param_1 + 0x90) >> 0x18);
    iVar5 = param_2;
    (**(code **)(**(int **)(param_1 + 0x14) + 0x20))(unaff_retaddr,param_2,param_3,param_1);
    uVar12 = (undefined1)((uint)iVar5 >> 0x18);
    if (0 < *(int *)(*(int *)(param_1 + 0x78) + -8)) {
      uVar2 = FUN_00734940(*(int *)(param_1 + 0x78));
      return uVar2;
    }
    if (unaff_retaddr == 0x100) {
      if (param_2 == 9) {
        uVar4 = GetAsyncKeyState(0x10);
        if ((uVar4 & 0x8000) == 0) {
          FUN_00735020(*(undefined4 *)(param_1 + 0x90),1);
          return uVar12;
        }
        FUN_00735020(*(undefined4 *)(param_1 + 0x90),0xffffffff);
        return uVar12;
      }
      if (param_2 == 0x1b) {
        uVar2 = FUN_00734940(0x95baec);
        return uVar2;
      }
      if (param_2 == 0xd) {
LAB_00734bfe:
        uVar2 = FUN_00734940(0x969e98);
        return uVar2;
      }
    }
    else if ((*(int *)(param_1 + 0x50) == 1) && (unaff_retaddr == 0x102)) {
      if ((param_2 == 0x59) || (param_2 == 0x79)) {
        iVar5 = FUN_00737400(0x97f9e0);
        if (iVar5 != 0) {
          uVar2 = FUN_00734940(0x97f9f0);
          return uVar2;
        }
        iVar5 = FUN_00737400(0x9654b8);
        if (iVar5 != 0) goto LAB_00734bfe;
      }
      else if ((param_2 == 0x4e) || (param_2 == 0x6e)) {
        iVar5 = FUN_00737400(0x97f9e0);
        if (iVar5 != 0) {
          uVar2 = FUN_00734940(0x97f9e8);
          return uVar2;
        }
        iVar5 = FUN_00737400(0x9654b8);
        if (iVar5 != 0) {
          uVar2 = FUN_00734940(0x95baec);
          return uVar2;
        }
      }
    }
  }
  return uVar2;
}


/* ==================================================================== */
/* Address: 0x00735020 | Classified: AngelicaUI::proc_735020 */
/* ==================================================================== */

undefined4 __thiscall FUN_00735020(int param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x144);
  if ((iVar3 == 0) || (iVar4 = *(int *)(param_1 + 0x148), iVar4 == 0)) {
    return 1;
  }
  iVar1 = iVar3;
  if (param_2 == 0) {
    param_2 = *(int *)(iVar3 + 8);
  }
  for (; (iVar1 != 0 && (param_2 != *(int *)(iVar1 + 8))); iVar1 = *(int *)(iVar1 + 0xc)) {
  }
  if (param_3 < 1) {
    if ((param_3 < 0) &&
       ((iVar3 = *(int *)(iVar1 + 4), *(int *)(iVar1 + 4) != 0 || (iVar3 = iVar4, iVar4 != 0)))) {
      while (*(int *)(iVar3 + 8) != param_2) {
        cVar2 = FUN_00742630();
        if ((cVar2 != '\0') && (iVar4 = FUN_00741f50(), iVar4 == 4)) {
          FUN_007373a0(*(undefined4 *)(iVar3 + 8));
          return 1;
        }
        iVar3 = *(int *)(iVar3 + 4);
        if ((iVar3 == 0) && (iVar3 = *(int *)(param_1 + 0x148), iVar3 == 0)) {
          return 1;
        }
      }
    }
  }
  else {
    iVar4 = *(int *)(iVar1 + 0xc);
    if ((*(int *)(iVar1 + 0xc) != 0) || (iVar4 = iVar3, iVar3 != 0)) {
      while (*(int *)(iVar4 + 8) != param_2) {
        cVar2 = FUN_00742630();
        if ((cVar2 != '\0') && (iVar3 = FUN_00741f50(), iVar3 == 4)) {
          FUN_007373a0(*(undefined4 *)(iVar4 + 8));
          return 1;
        }
        iVar4 = *(int *)(iVar4 + 0xc);
        if ((iVar4 == 0) && (iVar4 = *(int *)(param_1 + 0x144), iVar4 == 0)) {
          return 1;
        }
      }
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00735130 | Classified: elementclient::IDCANCEL@0x735130 */
/* ==================================================================== */

undefined4 __thiscall FUN_00735130(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iStack_10;
  int iStack_c;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 0xa8);
  iVar5 = (int)(short)param_4 - *(int *)(iVar3 + 0x14);
  iVar1 = (int)(short)((uint)param_4 >> 0x10) - *(int *)(iVar3 + 0x18);
  iVar2 = 0;
  iVar4 = 0;
  iStack_10 = 0;
  iStack_c = 0;
  if (*(int *)(param_1 + 0x124) != 0) {
    iVar4 = **(int **)(*(int *)(param_1 + 0x124) + 0x24);
    iStack_c = *(int *)(iVar4 + 0xc);
    iStack_10 = *(int *)(iVar4 + 8);
    iVar2 = *(int *)(iVar4 + 0x10);
    iVar4 = *(int *)(iVar4 + 0x14);
  }
  iVar7 = (*(int *)(param_1 + 0x54) - *(int *)(param_1 + 0xf0)) + *(int *)(param_1 + 0x70);
  iVar6 = *(int *)(param_1 + 0xf4) + *(int *)(param_1 + 0x58);
  iVar2 = (iVar2 - iStack_10) + iVar7;
  iVar4 = (iVar4 - iStack_c) + iVar6;
  if (param_2 == 0x201) {
    if ((((iVar5 < iVar7) || (iVar2 <= iVar5)) || (iVar1 < iVar6)) || (iVar4 <= iVar1)) {
      if ((0 < *(int *)(param_1 + 0xcc)) && (*(char *)(param_1 + 0x61) != '\0')) {
        FUN_00735e30(1,iVar5,iVar1);
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x5c) = 2;
    }
    goto LAB_00735357;
  }
  if (param_2 == 0x200) {
    if ((-0xffff < *(int *)(param_1 + 100)) && (-0xffff < *(int *)(param_1 + 0x68))) {
      if (*(char *)(param_1 + 0x61) != '\0') {
        iVar4 = (*(int *)(param_1 + 0x54) - *(int *)(param_1 + 100)) + iVar5;
        iVar2 = iVar1 + (*(int *)(param_1 + 0x58) - *(int *)(param_1 + 0x68));
        *(int *)(param_1 + 0x54) = iVar4;
        *(int *)(param_1 + 0x58) = iVar2;
        if (*(char *)(param_1 + 99) == '\0') {
          if (iVar4 < 0) {
            *(undefined4 *)(param_1 + 0x54) = 0;
          }
          else if (*(int *)(iVar3 + 0x1c) <= iVar4 + *(int *)(param_1 + 0x70)) {
            *(int *)(param_1 + 0x54) = (*(int *)(iVar3 + 0x1c) - *(int *)(param_1 + 0x70)) + -1;
          }
          if (iVar2 < 0) {
            *(undefined4 *)(param_1 + 0x58) = 0;
            *(int *)(param_1 + 100) = iVar5;
            *(int *)(param_1 + 0x68) = iVar1;
            goto LAB_00735357;
          }
          if (*(int *)(iVar3 + 0x20) <= iVar2 + *(int *)(param_1 + 0x74)) {
            *(int *)(param_1 + 0x58) = (*(int *)(iVar3 + 0x20) - *(int *)(param_1 + 0x74)) + -1;
          }
        }
      }
      *(int *)(param_1 + 100) = iVar5;
      *(int *)(param_1 + 0x68) = iVar1;
      goto LAB_00735357;
    }
    if ((((iVar7 <= iVar5) && (iVar5 < iVar2)) && (iVar6 <= iVar1)) && (iVar1 < iVar4)) {
      if (*(int *)(param_1 + 0x5c) != 2) {
        *(undefined4 *)(param_1 + 0x5c) = 1;
      }
      goto LAB_00735357;
    }
  }
  else {
    if (param_2 != 0x202) goto LAB_00735357;
    if (0 < *(int *)(param_1 + 0xcc)) {
      FUN_00735e30(0,0xffffffff,0xffffffff);
    }
    if (((iVar7 <= iVar5) && (iVar5 < iVar2)) &&
       ((iVar6 <= iVar1 && ((iVar1 < iVar4 && (*(int *)(param_1 + 0x5c) == 2)))))) {
      FUN_00734940(0x95baec);
    }
  }
  *(undefined4 *)(param_1 + 0x5c) = 0;
LAB_00735357:
  iVar3 = *(int *)(param_1 + 0xcc);
  if ((iVar3 < 1) && (iVar3 = *(int *)(param_1 + 0x94), iVar3 == 0)) {
    return 0;
  }
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x00735390 | Classified: AngelicaUI::proc_735390 */
/* ==================================================================== */

undefined4 __thiscall FUN_00735390(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_2 != 0x201) {
    if ((param_2 == 0x200) || (param_2 == 0x202)) {
      iVar1 = 0;
      iVar2 = 0;
      if (*(int *)(param_1 + 0xd0) != 0) {
        iVar2 = FUN_007537e0();
        iVar1 = *(int *)(**(int **)(iVar2 + 0x24) + 0xc);
        iVar2 = *(int *)(**(int **)(iVar2 + 0x24) + 0x14);
      }
      iVar1 = (((((int)(short)((uint)param_4 >> 0x10) -
                 *(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0xa8) + 0x18)) -
                *(int *)(param_1 + 0x58)) - iVar2) + iVar1) / *(int *)(param_1 + 0xb4);
      if (iVar1 < 0) {
        iVar1 = 0;
      }
      else {
        iVar2 = *(int *)(param_1 + 200) + -1;
        if (iVar2 < iVar1) {
          iVar1 = iVar2;
        }
      }
      if (param_2 == 0x200) {
        if (0 < *(int *)(*(int *)(*(int *)(param_1 + 0xbc) + 4 + iVar1 * 0xc) + -8)) {
          *(int *)(param_1 + 0xac) = iVar1;
          return 1;
        }
      }
      else if (param_2 == 0x202) {
        if (*(char *)(iVar1 * 0xc + 1 + *(int *)(param_1 + 0xbc)) != '\0') {
          FUN_00735c50(0,0,1);
          FUN_00734940(*(undefined4 *)(iVar1 * 0xc + 4 + *(int *)(param_1 + 0xbc)));
        }
      }
      return 1;
    }
    if ((param_2 != 0x100) || (param_3 != 0x1b)) {
      return 0;
    }
    FUN_00735c50(0,0,1);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007354b0 | Classified: AngelicaUI::proc_7354b0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007354b0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x50);
}


/* ==================================================================== */
/* Address: 0x007354c0 | Classified: AngelicaUI::proc_7354c0 */
/* ==================================================================== */

void __thiscall FUN_007354c0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x50) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x007354d0 | Classified: AngelicaUI::proc_7354d0 */
/* ==================================================================== */

void __thiscall FUN_007354d0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x58);
  *param_2 = *(undefined4 *)(param_1 + 0x54);
  param_2[1] = uVar1;
  return;
}


/* ==================================================================== */
/* Address: 0x007354f0 | Classified: AngelicaUI::proc_7354f0 */
/* ==================================================================== */

/* WARNING: Type propagation algorithm not settling */

void __thiscall
FUN_007354f0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,int param_6)

{
  int *piVar1;
  int unaff_EBX;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_retaddr;
  int aiStack_18 [2];
  int aiStack_10 [4];
  
  iVar3 = 0;
  if (param_6 == 0) {
    aiStack_10[1] = 0;
    iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 0xa8);
    iVar4 = *(int *)(iVar2 + 0x1c);
    iVar2 = *(int *)(iVar2 + 0x20);
  }
  else {
    piVar1 = (int *)FUN_007354d0(aiStack_10);
    iVar3 = *piVar1;
    aiStack_10[0] = piVar1[1];
    piVar1 = (int *)FUN_00737320(aiStack_10 + 1);
    iVar4 = *piVar1;
    iVar2 = piVar1[1];
  }
  FUN_00737320(aiStack_18);
  switch(param_3) {
  case 0:
    *(undefined4 *)(param_1 + 0x54) = unaff_retaddr;
    break;
  case 1:
    *(int *)(param_1 + 0x54) = iVar3;
    break;
  case 2:
    *(int *)(param_1 + 0x54) = (iVar4 - unaff_EBX) + iVar3;
    break;
  case 3:
    *(int *)(param_1 + 0x54) = (iVar4 / 2 - unaff_EBX / 2) + iVar3;
  }
  switch(param_4) {
  case 0:
    *(undefined4 *)(param_1 + 0x58) = param_2;
    return;
  case 1:
    *(int *)(param_1 + 0x58) = aiStack_10[0];
    return;
  case 2:
    *(int *)(param_1 + 0x58) = (iVar2 - aiStack_18[0]) + aiStack_10[0];
    return;
  case 3:
    *(int *)(param_1 + 0x58) = (iVar2 / 2 - aiStack_18[0] / 2) + aiStack_10[0];
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00735630 | Classified: AngelicaUI::proc_735630 */
/* ==================================================================== */

void __thiscall FUN_00735630(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  int *unaff_retaddr;
  int aiStack_8 [2];
  
  FUN_00737320(aiStack_8);
  iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 0xa8);
  iVar2 = *unaff_retaddr;
  if (iVar2 == -1) {
    *unaff_retaddr = (*(int *)(iVar1 + 0x1c) - unaff_ESI) / 2;
  }
  else if (iVar2 < -1) {
    *unaff_retaddr = (*(int *)(iVar1 + 0x1c) - unaff_ESI) + 2 + iVar2;
  }
  iVar2 = *param_2;
  if (iVar2 == -1) {
    *param_2 = (*(int *)(iVar1 + 0x20) - aiStack_8[0]) / 2;
    return;
  }
  if (iVar2 < -1) {
    *param_2 = (*(int *)(iVar1 + 0x20) - aiStack_8[0]) + 2 + iVar2;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007356c0 | Classified: AngelicaUI::proc_7356c0 */
/* ==================================================================== */

undefined1 __thiscall FUN_007356c0(int param_1,int param_2)

{
  byte *pbVar1;
  undefined4 *puVar2;
  byte bVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  char cVar7;
  undefined4 *puVar8;
  int *piVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  undefined4 *puVar13;
  undefined1 uVar14;
  undefined4 unaff_ESI;
  byte *pbVar15;
  undefined4 *unaff_FS_OFFSET;
  uint uStack_2c;
  undefined4 uStack_14;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008c9d29;
  *unaff_FS_OFFSET = &uStack_c;
  if ((*(int *)(param_1 + 0x144) == 0) && (*(int *)(param_1 + 0x148) == 0)) {
    puVar8 = (undefined4 *)func_0x00763250(0x10);
    *(undefined4 **)(param_1 + 0x144) = puVar8;
    if (puVar8 == (undefined4 *)0x0) {
      *unaff_FS_OFFSET = uStack_c;
      return 0;
    }
    *puVar8 = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x144) + 4) = 0;
    *(int *)(*(int *)(param_1 + 0x144) + 8) = param_2;
    *(undefined4 *)(*(int *)(param_1 + 0x144) + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(param_1 + 0x144);
  }
  else {
    piVar9 = (int *)func_0x00763250(0x10);
    if (piVar9 == (int *)0x0) {
      *unaff_FS_OFFSET = uStack_c;
      return 0;
    }
    *(int **)(*(int *)(param_1 + 0x148) + 0xc) = piVar9;
    *piVar9 = **(int **)(param_1 + 0x148) + 1;
    piVar9[1] = *(int *)(param_1 + 0x148);
    piVar9[2] = param_2;
    piVar9[3] = 0;
    *(int **)(param_1 + 0x148) = piVar9;
  }
  *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) + 1;
  uVar10 = func_0x00868610();
  func_0x007636b0(uVar10);
  uVar4 = *(uint *)(param_1 + 0x140);
  uVar11 = *(int *)(param_1 + 0x130) + 1;
  puStack_8 = (undefined *)0x0;
  if ((uVar4 < uVar11) && (uVar11 = func_0x00404700(uVar11), uVar4 < uVar11)) {
    uVar12 = uVar11;
    if (uVar11 == 0) {
      puVar8 = (undefined4 *)0x0;
      puVar13 = puVar8;
    }
    else {
      puVar8 = (undefined4 *)func_0x00763250(uVar11 * 4);
      puVar13 = puVar8;
    }
    for (; uVar12 != 0; uVar12 = uVar12 - 1) {
      if (puVar8 != (undefined4 *)0x0) {
        *puVar8 = 0;
      }
      puVar8 = puVar8 + 1;
    }
    uStack_2c = 0;
    if (uVar4 != 0) {
      do {
        puVar2 = (undefined4 *)(*(int *)(param_1 + 0x134) + uStack_2c * 4);
        puVar5 = *(undefined4 **)(*(int *)(param_1 + 0x134) + uStack_2c * 4);
        while (puVar5 != (undefined4 *)0x0) {
          pbVar15 = (byte *)puVar5[2];
          uVar12 = 0;
          bVar3 = *pbVar15;
          while (bVar3 != 0) {
            uVar12 = uVar12 * 0x1f + (uint)bVar3;
            pbVar1 = pbVar15 + 1;
            pbVar15 = pbVar15 + 1;
            bVar3 = *pbVar1;
          }
          *puVar2 = *puVar5;
          *puVar5 = puVar13[uVar12 % uVar11];
          puVar13[uVar12 % uVar11] = puVar5;
          puVar2 = (undefined4 *)(*(int *)(param_1 + 0x134) + uStack_2c * 4);
          puVar5 = *(undefined4 **)(*(int *)(param_1 + 0x134) + uStack_2c * 4);
        }
        uStack_2c = uStack_2c + 1;
      } while (uStack_2c < uVar4);
    }
    iVar6 = *(int *)(param_1 + 0x134);
    *(undefined4 **)(param_1 + 0x134) = puVar13;
    *(undefined4 **)(param_1 + 0x138) = puVar8;
    uStack_14 = *(undefined4 *)(param_1 + 0x140);
    *(uint *)(param_1 + 0x140) = uVar11;
    *(uint *)(param_1 + 0x13c) = uVar11;
    func_0x005b5c40();
    if (iVar6 != 0) {
      func_0x00763260(iVar6);
    }
  }
  uVar4 = *(uint *)(param_1 + 0x140);
  uVar11 = func_0x004130f0(unaff_ESI);
  uVar11 = uVar11 % uVar4;
  puVar8 = *(undefined4 **)(*(int *)(param_1 + 0x134) + uVar11 * 4);
  puVar13 = puVar8;
  do {
    if (puVar13 == (undefined4 *)0x0) {
      puVar13 = (undefined4 *)func_0x00763250(0xc);
      uStack_c = CONCAT31(uStack_c._1_3_,1);
      if (puVar13 == (undefined4 *)0x0) {
        puVar13 = (undefined4 *)0x0;
      }
      else {
        puVar13[1] = uStack_4;
        func_0x00763660(&stack0xffffffcc);
        *puVar13 = puVar8;
      }
      *(undefined4 **)(*(int *)(param_1 + 0x134) + uVar11 * 4) = puVar13;
      uVar14 = 1;
      *(int *)(param_1 + 0x130) = *(int *)(param_1 + 0x130) + 1;
LAB_0073597e:
      uStack_c = 0xffffffff;
      func_0x007637f0();
      *unaff_FS_OFFSET = uStack_14;
      return uVar14;
    }
    cVar7 = func_0x00763c50(&stack0xffffffcc);
    if (cVar7 != '\0') {
      uVar14 = 0;
      goto LAB_0073597e;
    }
    puVar13 = (undefined4 *)*puVar13;
  } while( true );
}


/* ==================================================================== */
/* Address: 0x007359b0 | Classified: AngelicaUI::proc_7359b0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007359b0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x28);
}


/* ==================================================================== */
/* Address: 0x007359c0 | Classified: AngelicaUI::proc_7359c0 */
/* ==================================================================== */

uint __thiscall FUN_007359c0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *unaff_FS_OFFSET;
  int iStack_48;
  undefined1 *puStack_44;
  undefined4 *puStack_40;
  undefined1 auStack_24 [4];
  int iStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008c9d7a;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  puStack_40 = (undefined4 *)param_2;
  puStack_44 = (undefined1 *)0x7359f0;
  func_0x007636b0();
  iVar1 = *(int *)(param_1 + 0x14);
  puStack_44 = &stack0xffffffd0;
  puStack_8 = (undefined *)0x0;
  iStack_48 = 0x735a0a;
  func_0x00763660();
  uStack_18 = 0;
  iStack_48 = *(int *)(iVar1 + 0x74) + 1;
  uStack_c = CONCAT31(uStack_c._1_3_,1);
  func_0x00739580();
  iVar5 = func_0x004cdad0(&stack0xffffffc8);
  puVar2 = *(undefined4 **)(*(int *)(iVar1 + 0x78) + iVar5 * 4);
  for (puVar7 = puVar2; puVar7 != (undefined4 *)0x0; puVar7 = (undefined4 *)*puVar7) {
    cVar4 = func_0x00763c50(&stack0xffffffc4);
    if (cVar4 != '\0') goto LAB_00735a9d;
  }
  iVar6 = func_0x00763250(0x10);
  uStack_14 = CONCAT31(uStack_14._1_3_,2);
  if (iVar6 == 0) {
    puVar7 = (undefined4 *)0x0;
  }
  else {
    puVar7 = (undefined4 *)FUN_00731610(&stack0xffffffc4,auStack_24,puVar2);
  }
  *(undefined4 **)(*(int *)(iVar1 + 0x78) + iVar5 * 4) = puVar7;
  *(int *)(iVar1 + 0x74) = *(int *)(iVar1 + 0x74) + 1;
LAB_00735a9d:
  uStack_14 = uStack_14 & 0xffffff00;
  func_0x007637f0();
  iVar1 = puVar7[2];
  uStack_14 = 0xffffffff;
  uVar8 = func_0x007637f0();
  if (iVar1 == 0) {
    iVar5 = *(int *)(param_1 + 0x14);
    iVar1 = param_1 + 0x28;
    uVar8 = *(uint *)(iVar5 + 0x84);
    uVar9 = func_0x004130f0(*(undefined4 *)(param_1 + 0x28));
    puStack_40 = (undefined4 *)0x0;
    uVar9 = uVar9 % uVar8;
    puVar2 = *(undefined4 **)(*(int *)(iVar5 + 0x78) + uVar9 * 4);
    puVar7 = puVar2;
    while (puVar3 = puVar7, puVar3 != (undefined4 *)0x0) {
      cVar4 = func_0x00763c50(iVar1);
      if (cVar4 != '\0') {
        if (puVar3 == puVar2) {
          *(undefined4 *)(*(int *)(iVar5 + 0x78) + uVar9 * 4) = *puVar3;
        }
        else {
          *puStack_40 = *puVar3;
        }
        FUN_007316a0();
        func_0x00763260(puVar3);
        *(int *)(iVar5 + 0x74) = *(int *)(iVar5 + 0x74) + -1;
        break;
      }
      puStack_40 = puVar3;
      puVar7 = (undefined4 *)*puVar3;
    }
    func_0x007638a0(uStack_10);
    iVar5 = puStack_40[5];
    func_0x00763660(iVar1);
    iStack_20 = 3;
    func_0x00739580(*(int *)(iVar5 + 0x74) + 1);
    iStack_20 = func_0x004cdad0(iVar1);
    puVar2 = *(undefined4 **)(*(int *)(iVar5 + 0x78) + iStack_20 * 4);
    for (puVar7 = puVar2; puVar7 != (undefined4 *)0x0; puVar7 = (undefined4 *)*puVar7) {
      cVar4 = func_0x00763c50(iVar1);
      if (cVar4 != '\0') goto LAB_00735bf7;
    }
    puStack_40 = (undefined4 *)func_0x00763250(0x10);
    if (puStack_40 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      puVar7 = (undefined4 *)FUN_00731610(iVar1,&iStack_48,puVar2);
    }
    *(undefined4 **)(*(int *)(iVar5 + 0x78) + iStack_20 * 4) = puVar7;
    *(int *)(iVar5 + 0x74) = *(int *)(iVar5 + 0x74) + 1;
LAB_00735bf7:
    func_0x007637f0();
    puVar7[2] = uVar9;
    uVar8 = CONCAT31((int3)(uVar9 >> 8),1);
  }
  else {
    uVar8 = uVar8 & 0xffffff00;
  }
  *unaff_FS_OFFSET = uStack_1c;
  return uVar8;
}


/* ==================================================================== */
/* Address: 0x00735c30 | Classified: AngelicaUI::proc_735c30 */
/* ==================================================================== */

undefined4 __fastcall FUN_00735c30(int param_1)

{
  return *(undefined4 *)(param_1 + 0x30);
}


/* ==================================================================== */
/* Address: 0x00735c40 | Classified: AngelicaUI::proc_735c40 */
/* ==================================================================== */

void FUN_00735c40(undefined4 param_1)

{
  FUN_00765230(param_1);
  return;
}


/* ==================================================================== */
/* Address: 0x00735c50 | Classified: elementclient::DEFAULT_@0x735c50 */
/* ==================================================================== */

void __thiscall FUN_00735c50(int *param_1,char param_2,undefined1 param_3,char param_4)

{
  int *piVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  if (param_2 != '\0') {
    (**(code **)(*param_1 + 0x24))();
  }
  param_1[0x2b] = 0;
  *(undefined1 *)((int)param_1 + 0x6d) = param_3;
  if ((char)param_1[0x1b] != param_2) {
    *(char *)(param_1 + 0x1b) = param_2;
    if (param_2 == '\0') {
      iVar6 = param_1[5];
      piVar4 = *(int **)(iVar6 + 0x28);
      if (piVar4 != (int *)0x0) {
        while ((int *)piVar4[2] != param_1) {
          piVar4 = (int *)*piVar4;
          if (piVar4 == (int *)0x0) {
            return;
          }
        }
        if (piVar4 != (int *)0x0) {
          iVar5 = *piVar4;
          piVar1 = (int *)piVar4[1];
          if (iVar5 == 0) {
            *(int **)(iVar6 + 0x2c) = piVar1;
          }
          else {
            *(int **)(iVar5 + 4) = piVar1;
          }
          if (piVar1 == (int *)0x0) {
            *(int *)(iVar6 + 0x28) = iVar5;
          }
          else {
            *piVar1 = iVar5;
          }
          *piVar4 = *(int *)(iVar6 + 0x30);
          *(int **)(iVar6 + 0x30) = piVar4;
          *(int *)(iVar6 + 0x34) = *(int *)(iVar6 + 0x34) + -1;
          iVar6 = param_1[5];
          iVar5 = func_0x00419130();
          *(int **)(iVar5 + 8) = param_1;
          *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(iVar6 + 0x2c);
          if (*(int **)(iVar6 + 0x2c) == (int *)0x0) {
            *(int *)(iVar6 + 0x28) = iVar5;
          }
          else {
            **(int **)(iVar6 + 0x2c) = iVar5;
          }
          *(int *)(iVar6 + 0x2c) = iVar5;
          if ((0 < *(int *)(param_1[5] + 0x34)) &&
             (iVar6 = *(int *)(*(int *)(param_1[5] + 0x28) + 8), iVar6 != 0)) {
            FUN_0072f7d0(iVar6);
          }
          *(undefined1 *)((int)param_1 + 0x61) = 1;
          FUN_007373a0(0);
        }
      }
    }
    else if (param_4 != '\0') {
      if (*(int *)(param_1[5] + 0x18) != 0) {
        FUN_00735e30(0,0xffffffff,0xffffffff);
      }
      FUN_0072f7d0(param_1);
      iVar6 = param_1[0x51];
      if (iVar6 != 0) {
        do {
          uVar2 = func_0x00868610(0x7ff);
          strncpy(&stack0xfffff7fc,uVar2);
          puVar3 = (undefined1 *)strstr(&stack0xfffff7fc,0x980600);
          if (puVar3 == &stack0xfffff7fc) {
            FUN_007373a0(*(undefined4 *)(iVar6 + 8));
            return;
          }
          iVar6 = *(int *)(iVar6 + 0xc);
        } while (iVar6 != 0);
        return;
      }
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00735df0 | Classified: AngelicaUI::proc_735df0 */
/* ==================================================================== */

undefined1 __fastcall FUN_00735df0(int param_1)

{
  return *(undefined1 *)(param_1 + 0x6c);
}


/* ==================================================================== */
/* Address: 0x00735e00 | Classified: AngelicaUI::proc_735e00 */
/* ==================================================================== */

void __thiscall FUN_00735e00(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x6d) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00735e10 | Classified: AngelicaUI::proc_735e10 */
/* ==================================================================== */

undefined1 __fastcall FUN_00735e10(int param_1)

{
  return *(undefined1 *)(param_1 + 0x6d);
}


/* ==================================================================== */
/* Address: 0x00735e20 | Classified: AngelicaUI::proc_735e20 */
/* ==================================================================== */

undefined1 __fastcall FUN_00735e20(int param_1)

{
  return *(undefined1 *)(param_1 + 0x60);
}


/* ==================================================================== */
/* Address: 0x00735e30 | Classified: AngelicaUI::proc_735e30 */
/* ==================================================================== */

void __thiscall FUN_00735e30(int param_1,char param_2,int param_3,int param_4)

{
  int iStack_8;
  int iStack_4;
  
  if (param_2 != '\0') {
    iStack_8 = param_3;
    iStack_4 = param_4;
    if ((param_3 == -1) || (param_4 == -1)) {
      GetCursorPos(&iStack_8);
      ScreenToClient(*(undefined4 *)(*(int *)(param_1 + 0x10) + 4),&stack0xfffffff4);
    }
    *(undefined1 *)(param_1 + 0x60) = 1;
    *(int *)(param_1 + 100) = iStack_8;
    *(int *)(param_1 + 0x68) = iStack_4;
    SetCapture(*(undefined4 *)(*(int *)(param_1 + 0x10) + 4));
    return;
  }
  *(undefined1 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0xffff0001;
  *(undefined4 *)(param_1 + 0x68) = 0xffff0001;
  ReleaseCapture();
  return;
}


/* ==================================================================== */
/* Address: 0x00735ec0 | Classified: AUIDialog::vfunc_slot_4 */
/* ==================================================================== */

undefined4 __fastcall FUN_00735ec0(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = param_1[0x51];
  while( true ) {
    if (iVar2 == 0) {
      iVar2 = GetTickCount();
      if ((uint)param_1[0x21] <= (uint)(iVar2 - param_1[0x22]) / 1000) {
        FUN_007382f0(1);
      }
      (**(code **)(*param_1 + 0x20))();
      return 1;
    }
    cVar1 = FUN_00741f00();
    if ((cVar1 != '\0') && (cVar1 = (**(code **)(**(int **)(iVar2 + 8) + 0x14))(), cVar1 == '\0'))
    break;
    iVar2 = *(int *)(iVar2 + 0xc);
  }
  uVar3 = func_0x00739700(0x588,1,0x98060c);
  return uVar3;
}


/* ==================================================================== */
/* Address: 0x00735f40 | Classified: AUIDialog::vfunc_slot_5 */
/* ==================================================================== */

undefined4 __fastcall FUN_00735f40(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  
  if ((0 < *(int *)(param_1 + 0x80)) &&
     (uVar4 = GetTickCount(), ((ulonglong)uVar4 / (ulonglong)*(uint *)(param_1 + 0x80) & 1) != 0)) {
    return 1;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 0xa8);
  iVar5 = *(int *)(param_1 + 0x34);
  piVar10 = (int *)(iVar1 + 0x14);
  if (iVar5 == 0) {
    iVar5 = FUN_007537e0();
  }
  *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + *piVar10;
  iVar9 = *(int *)(param_1 + 0x58) + *(int *)(iVar1 + 0x18);
  *(int *)(param_1 + 0x58) = iVar9;
  if ((*(int *)(param_1 + 0xd0) != 0) &&
     (cVar3 = FUN_007530d0(*(undefined4 *)(param_1 + 0x54),iVar9,*(undefined4 *)(param_1 + 0x70),
                           *(undefined4 *)(param_1 + 0x74),iVar5,*(undefined4 *)(param_1 + 0x40),
                           0x9b3c40,0,0,0,*(undefined4 *)(param_1 + 0xcc),1,
                           *(undefined4 *)(param_1 + 0x44)), cVar3 == '\0')) {
    uVar6 = func_0x00739700(0x5a7,1,0x98087c);
    return uVar6;
  }
  if (((*(int *)(param_1 + 0x50) == 2) && (*(int *)(param_1 + 0xd0) != 0)) &&
     (*(int *)(param_1 + 0x34) != 0)) {
    FUN_007537e0();
    func_0x0078cd10();
    uVar6 = FUN_00736b20();
    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) - *piVar10;
    *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) - *(int *)(iVar1 + 0x18);
    return uVar6;
  }
  if ((*(int *)(param_1 + 0xd0) != 0) && (*(int *)(param_1 + 0xd4) != 0)) {
    iVar7 = FUN_007537e0();
    iVar9 = *(int *)(param_1 + 0x108);
    iVar7 = **(int **)(iVar7 + 0x24);
    iStack_10 = *(int *)(iVar7 + 8);
    iStack_c = *(int *)(iVar7 + 0xc);
    iVar2 = *(int *)(iVar7 + 0x10);
    iVar7 = *(int *)(iVar7 + 0x14);
    if (iVar9 == -1) {
      iVar9 = (*(int *)(param_1 + 0x70) - *(int *)(param_1 + 0xf0)) - *(int *)(param_1 + 0xe8);
    }
    iVar8 = *(int *)(param_1 + 0x10c);
    if (iVar8 == -1) {
      iVar8 = FUN_007537e0();
      iVar8 = *(int *)(iVar8 + 0x38);
    }
    if (*(int *)(param_1 + 0xe8) == -1) {
      *(int *)(param_1 + 0xe8) = iVar2 - iStack_10;
    }
    if (*(int *)(param_1 + 0xec) == -1) {
      *(int *)(param_1 + 0xec) = (iVar7 - iStack_c) - iVar8;
    }
    cVar3 = FUN_007530d0(*(int *)(param_1 + 0xe8) + *(int *)(param_1 + 0x54),
                         *(int *)(param_1 + 0xec) + *(int *)(param_1 + 0x58),iVar9,iVar8,iVar5,
                         *(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x30),1,0,0,
                         *(undefined4 *)(param_1 + 0xcc),0,*(undefined4 *)(param_1 + 0x44));
    if (cVar3 == '\0') {
      uVar6 = func_0x00739700(0x5cc,1,0x980840);
      return uVar6;
    }
  }
  iVar5 = *(int *)(param_1 + 0x124);
  if (iVar5 != 0) {
    *(uint *)(iVar5 + 0x6c) = *(int *)(param_1 + 0xcc) << 0x18 | *(uint *)(iVar5 + 0x6c) & 0xffffff;
    func_0x0078c4e0(*(undefined4 *)(param_1 + 0x5c));
    if (*(char *)(param_1 + 0x62) == '\0') {
      cVar3 = func_0x0078c490((float)((*(int *)(param_1 + 0x70) - *(int *)(param_1 + 0xf0)) +
                                     *(int *)(param_1 + 0x54)),
                              (float)(*(int *)(param_1 + 0xf4) + *(int *)(param_1 + 0x58)));
    }
    else {
      cVar3 = func_0x0078c3a0();
    }
    if (cVar3 == '\0') {
      uVar6 = func_0x00739700(0x5dc,1,0x9807a8);
      return uVar6;
    }
  }
  if (*(int *)(param_1 + 0x11c) != 0) {
    iStack_24 = *(int *)(param_1 + 0x58);
    iStack_20 = *(int *)(param_1 + 0x54);
    iStack_14 = *(int *)(param_1 + 0x70);
    iStack_1c = *(int *)(param_1 + 0x74);
    if (*(int *)(param_1 + 0xd0) != 0) {
      iVar5 = FUN_007537e0();
      iVar5 = **(int **)(iVar5 + 0x24);
      iStack_20 = iStack_20 + *(int *)(iVar5 + 0x10);
      iStack_24 = iStack_24 + *(int *)(iVar5 + 0x14);
      iStack_14 = iStack_14 + (*(int *)(iVar5 + 8) - *(int *)(iVar5 + 0x10)) * 2;
      iStack_1c = iStack_1c + (*(int *)(iVar5 + 0xc) - *(int *)(iVar5 + 0x14)) * 2;
    }
    iVar5 = *(int *)(param_1 + 0x11c);
    *(float *)(iVar5 + 0x70) = (float)iStack_14 / (float)*(int *)(iVar5 + 0x34);
    *(float *)(*(int *)(param_1 + 0x11c) + 0x74) = (float)iStack_1c / (float)*(int *)(iVar5 + 0x38);
    if (*(char *)(param_1 + 0x62) == '\0') {
      cVar3 = func_0x0078c490((float)iStack_20,(float)iStack_24);
    }
    else {
      cVar3 = func_0x0078c3a0();
    }
    if (cVar3 == '\0') {
      uVar6 = func_0x00739700(0x5f8,1,0x980714);
      return uVar6;
    }
  }
  if (((*(int *)(param_1 + 0xd0) == 0) && (*(int *)(param_1 + 0xd4) == 0)) &&
     (*(int *)(param_1 + 0x124) == 0)) {
    uVar6 = FUN_00737360(&iStack_10,
                         *(uint *)(param_1 + 0x40) & 0xffffff | *(int *)(param_1 + 0xcc) << 0x18);
    cVar3 = func_0x007b7920(uVar6);
    if (cVar3 == '\0') {
      uVar6 = func_0x00739700(0x602,1,0x9806d0);
      return uVar6;
    }
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    cVar3 = func_0x00784480();
    if (cVar3 == '\0') {
      uVar6 = func_0x00739700(0x608,1,0x980680);
      return uVar6;
    }
    FUN_007310f0();
    func_0x0075ec80();
  }
  *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) - *piVar10;
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) - *(int *)(iVar1 + 0x18);
  cVar3 = FUN_007363e0();
  if (cVar3 != '\0') {
    func_0x00778da0();
    return 1;
  }
  uVar6 = func_0x00739700(0x611,1,0x980648);
  return uVar6;
}


/* ==================================================================== */
/* Address: 0x007363e0 | Classified: elementclient::AUIDialog__RenderControls____Fai@0x7363e0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007363e0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar7 = *(int *)(*(int *)(param_1 + 0xc) + 0xa8);
  uVar6 = *(undefined4 *)(iVar7 + 0x14);
  uVar1 = *(undefined4 *)(iVar7 + 0x18);
  uVar2 = *(undefined4 *)(iVar7 + 0x1c);
  uVar3 = *(undefined4 *)(iVar7 + 0x20);
  if ((*(int *)(param_1 + 0x24) != 0) && (iVar7 = 0, 0 < *(int *)(param_1 + 0x24))) {
    do {
      cVar4 = FUN_00736560(iVar7);
      if (cVar4 == '\0') {
        uVar6 = func_0x00739700(0x624,1,0x9809a0);
        return uVar6;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)(param_1 + 0x24));
  }
  for (iVar7 = *(int *)(param_1 + 0x144); iVar7 != 0; iVar7 = *(int *)(iVar7 + 0xc)) {
    cVar4 = FUN_00741f00();
    if (((cVar4 != '\0') && (*(int *)(iVar7 + 8) != *(int *)(param_1 + 0x90))) &&
       (iVar5 = FUN_007537e0(), iVar5 == 0)) {
      FUN_007428d0(uVar6,uVar1,uVar2,uVar3);
      cVar4 = (**(code **)(**(int **)(iVar7 + 8) + 0x18))();
      if (cVar4 == '\0') {
        uVar6 = func_0x00739700(0x632,1,0x980958);
        return uVar6;
      }
    }
  }
  if (((*(int *)(param_1 + 0x90) != 0) && (cVar4 = FUN_00741f00(), cVar4 != '\0')) &&
     (iVar7 = FUN_007537e0(), iVar7 == 0)) {
    FUN_007428d0(uVar6,uVar1,uVar2,uVar3);
    cVar4 = (**(code **)(**(int **)(param_1 + 0x90) + 0x18))();
    if (cVar4 == '\0') {
      uVar6 = func_0x00739700(0x63c,1,0x980914);
      return uVar6;
    }
  }
  cVar4 = func_0x00784480();
  if (cVar4 == '\0') {
    uVar6 = func_0x00739700(0x640,1,0x9808bc);
    return uVar6;
  }
  FUN_007310f0();
  func_0x0075ec80();
  return 1;
}


/* ==================================================================== */
/* Address: 0x00736560 | Classified: elementclient::AUIDialog__RenderControlsInViewp@0x736560 */
/* ==================================================================== */

undefined4 __thiscall FUN_00736560(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  int iVar10;
  int unaff_EBX;
  int *piVar11;
  int iVar12;
  int iStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  int aiStack_38 [2];
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int aiStack_14 [5];
  
  iStack_54 = *(int *)(*(int *)(param_1 + 0xc) + 0xa8);
  iStack_30 = *(int *)(iStack_54 + 0x14);
  iVar1 = *(int *)(iStack_54 + 0x18);
  iStack_68 = *(int *)(iStack_54 + 0x1c);
  iVar2 = *(int *)(iStack_54 + 0x20);
  iStack_28 = iStack_68 + iStack_30;
  iStack_24 = iVar2 + iVar1;
  param_2 = param_2 * 0x14;
  piVar4 = (int *)(param_2 + *(int *)(param_1 + 0x18));
  iVar7 = *piVar4;
  iStack_50 = *(int *)(param_1 + 0x54) + piVar4[1] + iStack_30;
  iStack_4c = piVar4[2] + *(int *)(param_1 + 0x58) + iVar1;
  iStack_44 = (piVar4[4] - piVar4[2]) + iStack_4c;
  iStack_48 = (piVar4[3] - piVar4[1]) + iStack_50;
  iStack_2c = iVar1;
  if ((((iStack_48 == iStack_50) || (iStack_44 == iStack_4c)) || (iStack_28 == iStack_30)) ||
     (iStack_24 == iVar1)) {
    iVar5 = 0;
    iVar12 = 0;
    iVar10 = 0;
    aiStack_14[0] = 0;
  }
  else if (((iStack_50 < iStack_28) && (iStack_30 < iStack_48)) &&
          ((iStack_4c < iStack_24 && (iVar1 < iStack_44)))) {
    piVar4 = &iStack_44;
    if (iStack_24 <= iStack_44) {
      piVar4 = &iStack_24;
    }
    piVar11 = &iStack_48;
    if (iStack_28 <= iStack_48) {
      piVar11 = &iStack_28;
    }
    piVar9 = &iStack_4c;
    if (iStack_4c <= iVar1) {
      piVar9 = &iStack_2c;
    }
    piVar6 = &iStack_50;
    if (iStack_50 <= iStack_30) {
      piVar6 = &iStack_30;
    }
    func_0x006484f0(piVar6,piVar9,piVar11,piVar4);
    iVar10 = iStack_18;
    iVar5 = iStack_20;
    iVar12 = iStack_1c;
  }
  else {
    uStack_64 = 0;
    uStack_60 = 0;
    uStack_5c = 0;
    uStack_58 = 0;
    func_0x006484f0(&uStack_58,&uStack_5c,&uStack_60,&uStack_64);
    iVar10 = iStack_18;
    iVar5 = iStack_20;
    iVar12 = iStack_1c;
  }
  *(int *)(iVar7 + 0x14) = iVar5;
  *(int *)(iVar7 + 0x18) = iVar12;
  *(int *)(iVar7 + 0x1c) = iVar10 - iVar5;
  *(int *)(iVar7 + 0x20) = aiStack_14[0] - iVar12;
  func_0x00786eb0((int *)(iVar7 + 0x14));
  func_0x00786f70();
  iVar10 = param_2;
  for (iVar7 = *(int *)(param_1 + 0x144); iVar7 != 0; iVar7 = *(int *)(iVar7 + 0xc)) {
    cVar3 = FUN_00741f00();
    if (((cVar3 != '\0') && (*(int *)(iVar7 + 8) != *(int *)(param_1 + 0x90))) &&
       (iVar10 = *(int *)(param_1 + 0x18), iVar5 = FUN_007537e0(),
       iVar5 == *(int *)(iVar10 + param_1))) {
      piVar4 = (int *)(**(code **)(**(int **)(iVar7 + 8) + 0x20))(aiStack_14);
      iStack_44 = *piVar4 + iVar1;
      iStack_40 = piVar4[1] + unaff_EBX;
      iStack_3c = piVar4[2] + iVar1;
      aiStack_38[0] = piVar4[3] + unaff_EBX;
      if ((((iStack_4c == iStack_54) || (iStack_48 == iStack_50)) || (iStack_3c == iStack_44)) ||
         (aiStack_38[0] == iStack_40)) {
        iStack_24 = 0;
        iStack_20 = 0;
        iStack_1c = 0;
        iStack_18 = 0;
      }
      else if (((iStack_54 < iStack_3c) && (iStack_44 < iStack_4c)) &&
              ((iStack_50 < aiStack_38[0] && (iStack_40 < iStack_48)))) {
        piVar4 = &iStack_48;
        if (aiStack_38[0] <= iStack_48) {
          piVar4 = aiStack_38;
        }
        piVar11 = &iStack_4c;
        if (iStack_3c <= iStack_4c) {
          piVar11 = &iStack_3c;
        }
        piVar9 = &iStack_50;
        if (iStack_50 <= iStack_40) {
          piVar9 = &iStack_40;
        }
        piVar6 = &iStack_54;
        if (iStack_54 <= iStack_44) {
          piVar6 = &iStack_44;
        }
        func_0x006484f0(piVar6,piVar9,piVar11,piVar4);
      }
      else {
        uStack_5c = 0;
        uStack_60 = 0;
        uStack_64 = 0;
        iStack_68 = 0;
        func_0x006484f0(&iStack_68,&uStack_64,&uStack_60,&uStack_5c);
      }
      if ((iStack_1c != iStack_24) && (iStack_18 != iStack_20)) {
        FUN_007428d0(iVar1,unaff_EBX,iVar2,param_2);
        cVar3 = (**(code **)(**(int **)(iVar7 + 8) + 0x18))();
        if (cVar3 == '\0') {
          uVar8 = func_0x00739700(0x66e,1,0x980a94);
          return uVar8;
        }
      }
    }
    iVar10 = param_1;
  }
  if (((*(int *)(param_1 + 0x90) != 0) && (cVar3 = FUN_00741f00(), cVar3 != '\0')) &&
     (iVar7 = *(int *)(param_1 + 0x18), iVar5 = FUN_007537e0(), iVar5 == *(int *)(iVar7 + iVar10)))
  {
    piVar4 = (int *)(**(code **)(**(int **)(param_1 + 0x90) + 0x20))(aiStack_14);
    iStack_44 = *piVar4 + iVar1;
    iStack_40 = piVar4[1] + unaff_EBX;
    iStack_3c = piVar4[2] + iVar1;
    aiStack_38[0] = piVar4[3] + unaff_EBX;
    if (((iStack_4c == iStack_54) || (iStack_48 == iStack_50)) ||
       ((iStack_3c == iStack_44 || (aiStack_38[0] == iStack_40)))) {
      iVar7 = 0;
      iVar10 = 0;
      iStack_24 = 0;
      iStack_20 = 0;
    }
    else if (((iStack_54 < iStack_3c) && (iStack_44 < iStack_4c)) &&
            ((iStack_50 < aiStack_38[0] && (iStack_40 < iStack_48)))) {
      piVar4 = &iStack_48;
      if (aiStack_38[0] <= iStack_48) {
        piVar4 = aiStack_38;
      }
      piVar11 = &iStack_4c;
      if (iStack_3c <= iStack_4c) {
        piVar11 = &iStack_3c;
      }
      piVar9 = &iStack_50;
      if (iStack_50 <= iStack_40) {
        piVar9 = &iStack_40;
      }
      piVar6 = &iStack_54;
      if (iStack_54 <= iStack_44) {
        piVar6 = &iStack_44;
      }
      func_0x006484f0(piVar6,piVar9,piVar11,piVar4);
      iVar7 = iStack_1c;
      iVar10 = iStack_18;
    }
    else {
      uStack_5c = 0;
      uStack_60 = 0;
      uStack_64 = 0;
      iStack_68 = 0;
      func_0x006484f0(&iStack_68,&uStack_64,&uStack_60,&uStack_5c);
      iVar7 = iStack_1c;
      iVar10 = iStack_18;
    }
    if ((iVar7 != iStack_24) && (iVar10 != iStack_20)) {
      FUN_007428d0(iVar1,unaff_EBX,iVar2,param_2);
      cVar3 = (**(code **)(**(int **)(param_1 + 0x90) + 0x18))();
      if (cVar3 == '\0') {
        uVar8 = func_0x00739700(0x680,1,0x980a48);
        return uVar8;
      }
    }
  }
  cVar3 = func_0x00784480();
  if (cVar3 == '\0') {
    uVar8 = func_0x00739700(0x685,1,0x9809e8);
    return uVar8;
  }
  FUN_007310f0();
  func_0x0075ec80();
  func_0x00786f70();
  return 1;
}


/* ==================================================================== */
/* Address: 0x00736b20 | Classified: elementclient::AUIDialog__RenderMenuItems____Fa@0x736b20 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00736b20(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  uint unaff_EBP;
  int iVar8;
  int *unaff_FS_OFFSET;
  float fStack_44;
  int iStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  int iStack_20;
  int iStack_1c;
  undefined1 auStack_18 [4];
  undefined4 uStack_14;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008c9da0;
  *unaff_FS_OFFSET = (int)&iStack_c;
  iVar6 = 0;
  iVar7 = 0;
  iStack_2c = 0;
  iStack_1c = 0;
  if (*(int *)(param_1 + 0xd0) != 0) {
    fStack_44 = 1.0599588e-38;
    iVar6 = FUN_007537e0();
    iVar8 = **(int **)(iVar6 + 0x24);
    iVar6 = *(int *)(iVar8 + 8);
    iVar7 = *(int *)(iVar8 + 0xc);
    iStack_2c = *(int *)(iVar8 + 0x10);
    iStack_1c = *(int *)(iVar8 + 0x14);
  }
  iStack_1c = (*(int *)(param_1 + 0x58) - iVar7) + iStack_1c;
  iVar7 = 0;
  iStack_2c = (*(int *)(param_1 + 0x54) - iVar6) + iStack_2c;
  if (-1 < *(int *)(param_1 + 0xac)) {
    iStack_20 = *(int *)(param_1 + 0xb4) * *(int *)(param_1 + 0xac) + iStack_1c;
    fStack_44 = (float)iStack_20;
    cVar1 = func_0x0078c3a0((float)iStack_2c);
    if (cVar1 == '\0') {
      fStack_44 = 1.3962902e-38;
      uVar2 = func_0x00739700(0x6a0,1);
      *unaff_FS_OFFSET = iStack_c;
      return uVar2;
    }
  }
  iStack_28 = *(int *)(param_1 + 0x34);
  uStack_4 = 0;
  if (iStack_28 == 0) {
    fStack_44 = 1.0599818e-38;
    iStack_28 = FUN_007537e0();
  }
  fStack_44 = -NAN;
  uVar2 = FUN_00737a30(2);
  puVar3 = (undefined4 *)func_0x0073c830(auStack_18,uVar2);
  uStack_24 = *puVar3;
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 200)) {
    do {
      pcVar5 = (char *)(*(int *)(param_1 + 0xbc) + iVar7);
      iVar8 = iVar6 * *(int *)(param_1 + 0xb4) + iStack_2c;
      uVar4 = *(uint *)(param_1 + 0x40);
      if (pcVar5[1] == '\0') {
        uVar4 = (uVar4 >> 0x10 & 0xff) >> 1;
        uVar4 = ((uVar4 | 0xffffff00) << 8 | uVar4) << 8 | uVar4;
      }
      if (*pcVar5 == '\0') {
        uVar2 = 0x9b3c40;
      }
      else {
        uVar2 = FUN_00737a30(2);
      }
      FUN_00765230(uVar2);
      puVar3 = (undefined4 *)
               func_0x00403ba0(&iStack_2c,&fStack_44,*(int *)(param_1 + 0xbc) + 8 + iVar7);
      auStack_18[0] = 1;
      func_0x0073bab0(uVar4,iVar8,*puVar3,unaff_EBP,0,0xff000000,0,0xffffffff);
      unaff_EBP = unaff_EBP & 0xffffff00;
      FUN_00765200();
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 0xc;
    } while (iVar6 < *(int *)(param_1 + 200));
  }
  FUN_007310f0();
  func_0x0075ec80();
  uStack_14 = 0xffffffff;
  FUN_00765200();
  *unaff_FS_OFFSET = iStack_1c;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00736d50 | Classified: AngelicaUI::proc_736d50 */
/* ==================================================================== */

int * __thiscall
FUN_00736d50(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            char param_5)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008c9e60;
  *unaff_FS_OFFSET = &uStack_c;
  piVar3 = (int *)0x0;
  switch(param_4) {
  case 1:
    iVar2 = func_0x00763250(0xa0);
    uStack_4 = 0;
    if (iVar2 == 0) {
code_r0x00737034:
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_0074b7e0();
    }
    break;
  case 2:
    iVar2 = func_0x00763250(200);
    uStack_4 = 1;
    if (iVar2 == 0) goto code_r0x00737034;
    piVar3 = (int *)FUN_0074c410();
    break;
  case 3:
    iVar2 = func_0x00763250(0x440);
    uStack_4 = 2;
    if (iVar2 == 0) goto code_r0x00737034;
    piVar3 = (int *)func_0x00759970();
    break;
  case 4:
    iVar2 = func_0x00763250(0x249c);
    uStack_4 = 3;
    if (iVar2 == 0) goto code_r0x00737034;
    piVar3 = (int *)func_0x0073d260();
    break;
  case 5:
    iVar2 = func_0x00763250(0x184);
    uStack_4 = 4;
    if (iVar2 == 0) goto code_r0x00737034;
    piVar3 = (int *)FUN_00742ff0();
    break;
  case 6:
    iVar2 = func_0x00763250(0xb0);
    uStack_4 = 5;
    if (iVar2 == 0) goto code_r0x00737034;
    piVar3 = (int *)FUN_007447f0();
    break;
  case 7:
    iVar2 = func_0x00763250(0x154);
    uStack_4 = 6;
    if (iVar2 == 0) goto code_r0x00737034;
    piVar3 = (int *)FUN_00745250();
    break;
  case 8:
    iVar2 = func_0x00763250(0xb0);
    uStack_4 = 7;
    if (iVar2 == 0) goto code_r0x00737034;
    piVar3 = (int *)func_0x00761a60();
    break;
  case 9:
    iVar2 = func_0x00763250(0xcc);
    uStack_4 = 8;
    if (iVar2 == 0) goto code_r0x00737034;
    piVar3 = (int *)func_0x0075ca60();
    break;
  case 10:
    iVar2 = func_0x00763250(0xa8);
    uStack_4 = 9;
    if (iVar2 == 0) goto code_r0x00737034;
    piVar3 = (int *)FUN_0074bd20();
    break;
  case 0xb:
    iVar2 = func_0x00763250(0xf4);
    uStack_4 = 10;
    if (iVar2 == 0) goto code_r0x00737034;
    piVar3 = (int *)FUN_007537f0();
    break;
  case 0xc:
    iVar2 = func_0x00763250(200);
    uStack_4 = 0xb;
    if (iVar2 == 0) goto code_r0x00737034;
    piVar3 = (int *)FUN_007521d0();
    break;
  case 0xd:
    iVar2 = func_0x00763250(0xbc);
    uStack_4 = 0xc;
    if (iVar2 == 0) goto code_r0x00737034;
    piVar3 = (int *)FUN_0074e580();
    break;
  case 0xe:
    iVar2 = func_0x00763250(0x1138);
    uStack_4 = 0xd;
    if (iVar2 == 0) goto code_r0x00737034;
    piVar3 = (int *)func_0x00754e10();
    break;
  case 0xf:
    iVar2 = func_0x00763250(0x148);
    uStack_4 = 0xe;
    if (iVar2 == 0) goto code_r0x00737034;
    piVar3 = (int *)FUN_0074f550();
    break;
  case 0x10:
    iVar2 = func_0x00763250(0x24b8);
    uStack_4 = 0xf;
    if (iVar2 == 0) goto code_r0x00737034;
    piVar3 = (int *)func_0x0075abd0();
    break;
  default:
    goto LAB_007370cc;
  }
  uStack_4 = 0xffffffff;
  if (piVar3 == (int *)0x0) {
    *unaff_FS_OFFSET = uStack_c;
    return (int *)0x0;
  }
  func_0x0075c360(param_1);
  cVar1 = (**(code **)(*piVar3 + 4))(unaff_retaddr,param_2,0);
  if (cVar1 == '\0') {
    if (piVar3 != (int *)0x0) {
      (**(code **)*piVar3)(1);
    }
    *unaff_FS_OFFSET = uStack_c;
    return (int *)0x0;
  }
  if ((param_5 != '\0') && (cVar1 = FUN_007356c0(piVar3), cVar1 == '\0')) {
    if (piVar3 != (int *)0x0) {
      (**(code **)*piVar3)(1);
    }
    *unaff_FS_OFFSET = uStack_c;
    return (int *)0x0;
  }
LAB_007370cc:
  *unaff_FS_OFFSET = uStack_c;
  return piVar3;
}


/* ==================================================================== */
/* Address: 0x00737130 | Classified: AngelicaUI::proc_737130 */
/* ==================================================================== */

undefined4 __thiscall FUN_00737130(int param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  char cVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  int *unaff_FS_OFFSET;
  byte *unaff_retaddr;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  iVar9 = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008c9e78;
  *unaff_FS_OFFSET = (int)&iStack_c;
  iVar3 = *(int *)(param_1 + 0x144);
  while( true ) {
    iStack_c = iVar9;
    if (iVar3 == 0) goto LAB_00737301;
    if (*(int *)(iVar3 + 8) == param_2) break;
    iVar3 = *(int *)(iVar3 + 0xc);
  }
  iVar9 = func_0x00868610();
  if (param_2 == *(int *)(iVar9 + 0xd8)) {
    iVar9 = func_0x00868610();
    *(undefined4 *)(iVar9 + 0xd8) = 0;
  }
  if (param_2 == *(int *)(param_1 + 0x90)) {
    FUN_007373a0(0);
  }
  if (param_2 == *(int *)(param_1 + 0x98)) {
    *(undefined4 *)(param_1 + 0x98) = 0;
  }
  if (param_2 == *(int *)(param_1 + 0x94)) {
    *(undefined4 *)(param_1 + 0x94) = 0;
  }
  if (*(int *)(iVar3 + 4) != 0) {
    *(undefined4 *)(*(int *)(iVar3 + 4) + 0xc) = *(undefined4 *)(iVar3 + 0xc);
  }
  if (*(int *)(iVar3 + 0xc) != 0) {
    *(undefined4 *)(*(int *)(iVar3 + 0xc) + 4) = *(undefined4 *)(iVar3 + 4);
  }
  if (iVar3 == *(int *)(param_1 + 0x144)) {
    *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(iVar3 + 0xc);
  }
  if (iVar3 == *(int *)(param_1 + 0x148)) {
    *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(iVar3 + 4);
  }
  uVar10 = func_0x00868610();
  func_0x007636b0(uVar10);
  uVar11 = 0;
  puStack_8 = (undefined *)0x0;
  bVar2 = *unaff_retaddr;
  while (bVar2 != 0) {
    uVar11 = uVar11 * 0x1f + (uint)bVar2;
    pbVar1 = unaff_retaddr + 1;
    unaff_retaddr = unaff_retaddr + 1;
    bVar2 = *pbVar1;
  }
  uVar11 = uVar11 % *(uint *)(param_1 + 0x140);
  puVar4 = *(undefined4 **)(*(int *)(param_1 + 0x134) + uVar11 * 4);
  puVar7 = puVar4;
  puVar6 = (undefined4 *)0x0;
  do {
    puVar5 = puVar7;
    if (puVar5 == (undefined4 *)0x0) {
LAB_007372aa:
      puStack_8 = (undefined *)0xffffffff;
      func_0x007637f0();
      if (*(int **)(iVar3 + 8) != (int *)0x0) {
        (**(code **)(**(int **)(iVar3 + 8) + 0xc))();
        if (*(undefined4 **)(iVar3 + 8) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(iVar3 + 8))(1);
        }
        *(undefined4 *)(iVar3 + 8) = 0;
      }
      func_0x00763260(iVar3);
      iVar9 = *(int *)(param_1 + 0x128) + -1;
      *(int *)(param_1 + 0x128) = iVar9;
      if (iVar9 < 1) {
        *(undefined4 *)(param_1 + 0x144) = 0;
        *(undefined4 *)(param_1 + 0x148) = 0;
      }
LAB_00737301:
      *unaff_FS_OFFSET = iStack_c;
      return CONCAT31((int3)((uint)iVar9 >> 8),1);
    }
    cVar8 = func_0x00763c50(&stack0x00000000);
    if (cVar8 != '\0') {
      if (puVar5 == puVar4) {
        *(undefined4 *)(*(int *)(param_1 + 0x134) + uVar11 * 4) = *puVar5;
      }
      else {
        *puVar6 = *puVar5;
      }
      func_0x007637f0();
      func_0x00763260(puVar5);
      *(int *)(param_1 + 0x130) = *(int *)(param_1 + 0x130) + -1;
      goto LAB_007372aa;
    }
    puVar7 = (undefined4 *)*puVar5;
    puVar6 = puVar5;
  } while( true );
}


/* ==================================================================== */
/* Address: 0x00737320 | Classified: AngelicaUI::proc_737320 */
/* ==================================================================== */

void __thiscall FUN_00737320(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x74);
  *param_2 = *(undefined4 *)(param_1 + 0x70);
  param_2[1] = uVar1;
  return;
}


/* ==================================================================== */
/* Address: 0x00737340 | Classified: AngelicaUI::proc_737340 */
/* ==================================================================== */

void __thiscall FUN_00737340(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x70) = param_2;
  *(undefined4 *)(param_1 + 0x74) = param_3;
  return;
}


/* ==================================================================== */
/* Address: 0x00737360 | Classified: AngelicaUI::proc_737360 */
/* ==================================================================== */

void __thiscall FUN_00737360(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x70);
  iVar2 = *(int *)(param_1 + 0x54);
  iVar3 = *(int *)(param_1 + 0x58);
  iVar4 = *(int *)(param_1 + 0x74);
  param_2[1] = iVar3;
  *param_2 = iVar2;
  param_2[2] = iVar1 + iVar2;
  param_2[3] = iVar4 + iVar3;
  return;
}


/* ==================================================================== */
/* Address: 0x00737390 | Classified: AngelicaUI::proc_737390 */
/* ==================================================================== */

undefined4 __fastcall FUN_00737390(int param_1)

{
  return *(undefined4 *)(param_1 + 0x90);
}


/* ==================================================================== */
/* Address: 0x007373a0 | Classified: AngelicaUI::proc_7373a0 */
/* ==================================================================== */

void __thiscall FUN_007373a0(int param_1,int *param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x90);
  if (piVar1 != param_2) {
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x1c))(8,param_2,0);
      (**(code **)(**(int **)(param_1 + 0x90) + 0x38))(0);
    }
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 0x38))(1);
    }
    *(int **)(param_1 + 0x90) = param_2;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007373f0 | Classified: AngelicaUI::proc_7373f0 */
/* ==================================================================== */

void FUN_007373f0(undefined4 param_1)

{
  func_0x007638a0(param_1);
  return;
}


/* ==================================================================== */
/* Address: 0x00737400 | Classified: AngelicaUI::proc_737400 */
/* ==================================================================== */

undefined4 __thiscall FUN_00737400(int param_1,undefined4 param_2)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 uVar3;
  bool bVar4;
  char cVar5;
  uint uVar6;
  undefined4 unaff_EBX;
  undefined4 *puVar7;
  undefined4 *unaff_FS_OFFSET;
  byte *unaff_retaddr;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008c9e98;
  *unaff_FS_OFFSET = &uStack_c;
  func_0x007636b0(param_2);
  uVar6 = 0;
  puStack_8 = (undefined *)0x0;
  bVar2 = *unaff_retaddr;
  while (bVar2 != 0) {
    uVar6 = uVar6 * 0x1f + (uint)bVar2;
    pbVar1 = unaff_retaddr + 1;
    unaff_retaddr = unaff_retaddr + 1;
    bVar2 = *pbVar1;
  }
  puVar7 = *(undefined4 **)(*(int *)(param_1 + 0x134) + (uVar6 % *(uint *)(param_1 + 0x140)) * 4);
  do {
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)0x0;
      bVar4 = false;
LAB_00737487:
      puStack_8 = (undefined *)0xffffffff;
      func_0x007637f0();
      if (!bVar4) {
        *unaff_FS_OFFSET = unaff_EBX;
        return 0;
      }
      uVar3 = *puVar7;
      *unaff_FS_OFFSET = unaff_EBX;
      return uVar3;
    }
    cVar5 = func_0x00763c50(&stack0x00000000);
    if (cVar5 != '\0') {
      puVar7 = puVar7 + 1;
      bVar4 = true;
      goto LAB_00737487;
    }
    puVar7 = (undefined4 *)*puVar7;
  } while( true );
}


/* ==================================================================== */
/* Address: 0x007374d0 | Classified: AngelicaUI::proc_7374d0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007374d0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x144);
}


/* ==================================================================== */
/* Address: 0x007374e0 | Classified: AngelicaUI::proc_7374e0 */
/* ==================================================================== */

undefined4 FUN_007374e0(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}


/* ==================================================================== */
/* Address: 0x007374f0 | Classified: AngelicaUI::proc_7374f0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007374f0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x148);
}


/* ==================================================================== */
/* Address: 0x00737500 | Classified: elementclient::AUIDialog__ImportStringTable____f@0x737500 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_00737500(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  char cVar5;
  undefined1 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  uint unaff_EBP;
  uint uVar10;
  undefined4 *unaff_FS_OFFSET;
  uint in_stack_00001020;
  uint in_stack_00001024;
  undefined4 in_stack_0000102c;
  undefined4 in_stack_00001040;
  undefined4 *puStack_c;
  undefined4 *puStack_8;
  uint uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_c = (undefined4 *)*unaff_FS_OFFSET;
  puStack_8 = (undefined4 *)&UNK_008c9ee8;
  *unaff_FS_OFFSET = &puStack_c;
  func_0x00892f20();
  puStack_c = _DAT_00985a98;
  func_0x0076ded0();
  cVar5 = func_0x0076e030(in_stack_00001040);
  if (cVar5 != '\0') {
joined_r0x00737575:
    do {
      if ((in_stack_00001020 <= in_stack_00001024) || (cVar5 = func_0x0076e120(1), cVar5 == '\0'))
      goto LAB_0073776f;
      puStack_c = (undefined4 *)_wtoi(&stack0x00000018);
      cVar5 = func_0x0076e120(1);
      if (cVar5 == '\0') {
        uVar6 = func_0x00739700(0x7e7,1,0x980b64);
        func_0x0076df10();
        FUN_00765200();
        goto LAB_0073779f;
      }
      FUN_00765230(&stack0x00000014);
      for (puVar1 = *(undefined4 **)
                     (*(int *)(param_1 + 0x154) + (unaff_EBP % *(uint *)(param_1 + 0x160)) * 4);
          puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
        if (puVar1[2] == unaff_EBP) {
          FUN_007652d0(&stack0xffffffe8);
          goto joined_r0x00737575;
        }
      }
      uVar2 = *(uint *)(param_1 + 0x160);
      uVar7 = *(int *)(param_1 + 0x150) + 1;
      if ((uVar2 < uVar7) && (uVar7 = func_0x00404700(uVar7), uVar2 < uVar7)) {
        uStack_4 = uVar7;
        uVar10 = uVar7;
        if (uVar7 == 0) {
          puStack_8 = (undefined4 *)0x0;
          puStack_c = puStack_8;
        }
        else {
          puStack_8 = (undefined4 *)func_0x00763250(uVar7 * 4);
          puStack_c = puStack_8;
        }
        for (; uVar10 != 0; uVar10 = uVar10 - 1) {
          if (puStack_8 != (undefined4 *)0x0) {
            *puStack_8 = 0;
          }
          puStack_8 = puStack_8 + 1;
        }
        uVar10 = 0;
        in_stack_0000102c = CONCAT31((int3)((uint)in_stack_0000102c >> 8),2);
        if (uVar2 != 0) {
          do {
            puVar1 = (undefined4 *)(*(int *)(param_1 + 0x154) + uVar10 * 4);
            puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x154) + uVar10 * 4);
            while (puVar3 != (undefined4 *)0x0) {
              uVar4 = puVar3[2];
              *puVar1 = *puVar3;
              *puVar3 = puStack_c[uVar4 % uVar7];
              puStack_c[uVar4 % uVar7] = puVar3;
              puVar1 = (undefined4 *)(*(int *)(param_1 + 0x154) + uVar10 * 4);
              puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x154) + uVar10 * 4);
            }
            uVar10 = uVar10 + 1;
          } while (uVar10 < uVar2);
        }
        func_0x004bb3b0(&puStack_c);
        func_0x005b5c40();
        if (puStack_c != (undefined4 *)0x0) {
          func_0x00763260(puStack_c);
        }
      }
      iVar8 = func_0x004322c0(&stack0xffffffec);
      puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x154) + iVar8 * 4);
      for (puVar3 = puVar1; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
        if ((undefined4 *)puVar3[2] == puStack_c) goto joined_r0x00737575;
      }
      puStack_8 = (undefined4 *)func_0x00763250(0xc);
      if (puStack_8 == (undefined4 *)0x0) {
        uVar9 = 0;
      }
      else {
        uVar9 = func_0x00739450(&puStack_c,&stack0xfffffff0,puVar1);
      }
      *(undefined4 *)(*(int *)(param_1 + 0x154) + iVar8 * 4) = uVar9;
      *(int *)(param_1 + 0x150) = *(int *)(param_1 + 0x150) + 1;
    } while( true );
  }
LAB_00737778:
  func_0x0076df10();
  FUN_00765200();
  uVar6 = 1;
LAB_0073779f:
  *unaff_FS_OFFSET = in_stack_0000102c;
  return uVar6;
LAB_0073776f:
  func_0x0076e0f0();
  goto LAB_00737778;
}


/* ==================================================================== */
/* Address: 0x00737800 | Classified: AngelicaUI::proc_737800 */
/* ==================================================================== */

uint __thiscall FUN_00737800(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint unaff_EBX;
  uint uVar11;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008c9f19;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_00765050(param_2);
  uVar10 = *(uint *)(param_1 + 0x160);
  uVar11 = 0;
  uVar7 = *(int *)(param_1 + 0x150) + 1;
  puStack_8 = (undefined *)0x0;
  if ((uVar10 < uVar7) && (uVar7 = func_0x00404700(uVar7), uVar10 < uVar7)) {
    uVar3 = uVar7;
    if (uVar7 == 0) {
      puVar8 = (undefined4 *)0x0;
      puVar9 = puVar8;
    }
    else {
      puVar8 = (undefined4 *)func_0x00763250(uVar7 * 4);
      puVar9 = puVar8;
    }
    for (; uVar3 != 0; uVar3 = uVar3 - 1) {
      if (puVar8 != (undefined4 *)0x0) {
        *puVar8 = 0;
      }
      puVar8 = puVar8 + 1;
    }
    if (uVar10 != 0) {
      do {
        puVar1 = (undefined4 *)(*(int *)(param_1 + 0x154) + uVar11 * 4);
        puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x154) + uVar11 * 4);
        while (puVar2 != (undefined4 *)0x0) {
          uVar3 = puVar2[2];
          *puVar1 = *puVar2;
          *puVar2 = puVar9[uVar3 % uVar7];
          puVar9[uVar3 % uVar7] = puVar2;
          puVar1 = (undefined4 *)(*(int *)(param_1 + 0x154) + uVar11 * 4);
          puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x154) + uVar11 * 4);
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < uVar10);
    }
    iVar4 = *(int *)(param_1 + 0x154);
    *(undefined4 **)(param_1 + 0x154) = puVar9;
    *(undefined4 **)(param_1 + 0x158) = puVar8;
    iVar5 = *(int *)(param_1 + 0x160);
    *(uint *)(param_1 + 0x160) = uVar7;
    *(uint *)(param_1 + 0x15c) = uVar7;
    func_0x006e04e0(iVar4,iVar4 + iVar5 * 4);
    if (iVar4 != 0) {
      func_0x00763260(iVar4);
    }
  }
  uVar10 = unaff_EBX % *(uint *)(param_1 + 0x160);
  puVar8 = *(undefined4 **)(*(int *)(param_1 + 0x154) + uVar10 * 4);
  puVar9 = puVar8;
  do {
    if (puVar9 == (undefined4 *)0x0) {
      puVar9 = (undefined4 *)func_0x00763250(0xc);
      puStack_8 = (undefined *)CONCAT31(puStack_8._1_3_,1);
      if (puVar9 == (undefined4 *)0x0) {
        puVar9 = (undefined4 *)0x0;
      }
      else {
        FUN_00765000(&stack0x00000000);
        *puVar9 = puVar8;
        puVar9[2] = unaff_EBX;
      }
      bVar6 = true;
      *(undefined4 **)(*(int *)(param_1 + 0x154) + uVar10 * 4) = puVar9;
      *(int *)(param_1 + 0x150) = *(int *)(param_1 + 0x150) + 1;
LAB_007379e2:
      puStack_8 = (undefined *)0xffffffff;
      FUN_00765200();
      if (bVar6) {
        *unaff_FS_OFFSET = uStack_10;
        return unaff_EBX;
      }
      *unaff_FS_OFFSET = uStack_10;
      return 0xffffffff;
    }
    if (puVar9[2] == unaff_EBX) {
      bVar6 = false;
      goto LAB_007379e2;
    }
    puVar9 = (undefined4 *)*puVar9;
  } while( true );
}


/* ==================================================================== */
/* Address: 0x00737a30 | Classified: AngelicaUI::proc_737a30 */
/* ==================================================================== */

undefined4 __thiscall FUN_00737a30(int param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x154) + (param_2 % *(uint *)(param_1 + 0x160)) * 4);
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = FUN_0072ef30(param_2);
      return uVar2;
    }
    if (puVar1[2] == param_2) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1[1];
}


/* ==================================================================== */
/* Address: 0x00737a70 | Classified: elementclient::Text_Color@0x737a70 */
/* ==================================================================== */

undefined4 __thiscall FUN_00737a70(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBX;
  int aiStack_8 [2];
  
  iVar1 = _strcmpi(param_2,0x95b2b4);
  if (iVar1 == 0) {
    func_0x007638a0(param_3);
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x980c64);
  if (iVar1 == 0) {
    FUN_00737e30(0,0,*param_3,0,0,0,0);
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x96778c);
  if (iVar1 == 0) {
    FUN_00737e30(param_3,param_3[0x400],*(undefined4 *)(param_1 + 0x40),
                 *(undefined4 *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x48),
                 *(undefined1 *)(param_3 + 0x401),*(undefined1 *)((int)param_3 + 0x1005));
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x980c60);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x54) = *param_3;
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x980c5c);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x58) = *param_3;
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x980c54);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x70) = *param_3;
    if (*(int *)(param_1 + 0xd0) != 0) {
      FUN_007537a0(aiStack_8);
      iVar1 = *(int *)(param_1 + 0x70);
      if (*(int *)(param_1 + 0x70) <= unaff_EBX) {
        iVar1 = unaff_EBX;
      }
      *(int *)(param_1 + 0x70) = iVar1;
      return 1;
    }
  }
  else {
    iVar1 = _strcmpi(param_2,0x980c4c);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x74) = *param_3;
      if (*(int *)(param_1 + 0xd0) != 0) {
        FUN_007537a0(aiStack_8);
        iVar1 = *(int *)(param_1 + 0x74);
        if (*(int *)(param_1 + 0x74) <= aiStack_8[0]) {
          iVar1 = aiStack_8[0];
        }
        *(int *)(param_1 + 0x74) = iVar1;
        return 1;
      }
    }
    else {
      iVar1 = _strcmpi(param_2,0x94eb38);
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x44) = *param_3;
        return 1;
      }
      iVar1 = _strcmpi(param_2,0x980c3c);
      if (iVar1 == 0) {
        FUN_00737e30(*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x3c),
                     *(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x44),*param_3,0,0);
        return 1;
      }
      iVar1 = _strcmpi(param_2,0x980ba0);
      if (iVar1 == 0) {
        FUN_00737ed0(*param_3);
        return 1;
      }
      iVar1 = _strcmpi(param_2,0x95d238);
      if (iVar1 == 0) {
        uVar2 = FUN_00734500(param_3,0);
        return uVar2;
      }
      iVar1 = _strcmpi(param_2,0x980c28);
      if (iVar1 == 0) {
        uVar2 = FUN_00734500(param_3,1);
        return uVar2;
      }
      iVar1 = _strcmpi(param_2,0x980c44);
      if (iVar1 == 0) {
        FUN_00765230(param_3);
        return 1;
      }
      iVar1 = _strcmpi(param_2,0x980c18);
      if (iVar1 == 0) {
        uVar2 = FUN_00734500(param_3,2);
        return uVar2;
      }
      iVar1 = _strcmpi(param_2,0x980c0c);
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0xe8) = *param_3;
        return 1;
      }
      iVar1 = _strcmpi(param_2,0x980c00);
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0xec) = *param_3;
        return 1;
      }
      iVar1 = _strcmpi(param_2,0x980bf0);
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x108) = *param_3;
        return 1;
      }
      iVar1 = _strcmpi(param_2,0x980bdc);
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x10c) = *param_3;
        return 1;
      }
      iVar1 = _strcmpi(param_2,0x980bc8);
      if (iVar1 == 0) {
        uVar2 = FUN_00734500(param_3,3);
        return uVar2;
      }
      iVar1 = _strcmpi(param_2,0x980bb8);
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0xf0) = *param_3;
        return 1;
      }
      iVar1 = _strcmpi(param_2,0x980ba8);
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0xf4) = *param_3;
      }
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00737e30 | Classified: elementclient::AUIDialog__SetFontAndColor____fa@0x737e30 */
/* ==================================================================== */

undefined4 __thiscall
FUN_00737e30(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,char param_7,char param_8)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  
  if (param_2 != 0) {
    bVar3 = param_7 != '\0';
    if (param_8 != '\0') {
      bVar3 = bVar3 | 0x10;
    }
    FUN_007310f0((float)param_3,param_2,bVar3,param_6);
    iVar1 = func_0x0075e6e0();
    *(int *)(param_1 + 0x34) = iVar1;
    if (iVar1 == 0) {
      uVar2 = func_0x00739700(0x8cb,1,0x980c70);
      return uVar2;
    }
    FUN_00765230(param_2);
    *(int *)(param_1 + 0x3c) = param_3;
    *(undefined4 *)(param_1 + 0x44) = param_5;
  }
  *(undefined4 *)(param_1 + 0x40) = param_4;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00737ec0 | Classified: AngelicaUI::proc_737ec0 */
/* ==================================================================== */

undefined4 __fastcall FUN_00737ec0(int param_1)

{
  return *(undefined4 *)(param_1 + 0xcc);
}


/* ==================================================================== */
/* Address: 0x00737ed0 | Classified: AngelicaUI::proc_737ed0 */
/* ==================================================================== */

void __thiscall FUN_00737ed0(int param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  *(int *)(param_1 + 0xcc) = param_2;
  if (param_2 < 1) {
    iVar5 = *(int *)(param_1 + 0x14);
    for (piVar3 = *(int **)(iVar5 + 0x28); piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
      if (piVar3[2] == param_1) {
        if (piVar3 != (int *)0x0) {
          iVar4 = *piVar3;
          piVar1 = (int *)piVar3[1];
          if (iVar4 == 0) {
            *(int **)(iVar5 + 0x2c) = piVar1;
          }
          else {
            *(int **)(iVar4 + 4) = piVar1;
          }
          if (piVar1 == (int *)0x0) {
            *(int *)(iVar5 + 0x28) = iVar4;
          }
          else {
            *piVar1 = iVar4;
          }
          *piVar3 = *(int *)(iVar5 + 0x30);
          *(int **)(iVar5 + 0x30) = piVar3;
          *(int *)(iVar5 + 0x34) = *(int *)(iVar5 + 0x34) + -1;
        }
        break;
      }
    }
    for (puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x14) + 0x48); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      if (puVar2[2] == param_1) {
        if (puVar2 != (undefined4 *)0x0) {
          return;
        }
        break;
      }
    }
    iVar5 = *(int *)(param_1 + 0x14) + 0x44;
  }
  else {
    iVar5 = *(int *)(param_1 + 0x14);
    for (piVar3 = *(int **)(iVar5 + 0x48); piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
      if (piVar3[2] == param_1) {
        if (piVar3 != (int *)0x0) {
          iVar4 = *piVar3;
          piVar1 = (int *)piVar3[1];
          if (iVar4 == 0) {
            *(int **)(iVar5 + 0x4c) = piVar1;
          }
          else {
            *(int **)(iVar4 + 4) = piVar1;
          }
          if (piVar1 == (int *)0x0) {
            *(int *)(iVar5 + 0x48) = iVar4;
          }
          else {
            *piVar1 = iVar4;
          }
          FUN_0077fd10(piVar3);
        }
        break;
      }
    }
    iVar5 = *(int *)(param_1 + 0x14);
    piVar3 = *(int **)(iVar5 + 0x28);
    if (piVar3 == (int *)0x0) {
LAB_00737f44:
      iVar5 = iVar5 + 0x24;
    }
    else {
      do {
        if (piVar3[2] == param_1) {
          if (piVar3 != (int *)0x0) {
            return;
          }
          goto LAB_00737f44;
        }
        piVar3 = (int *)*piVar3;
      } while (piVar3 != (int *)0x0);
      iVar5 = iVar5 + 0x24;
    }
  }
  iVar4 = func_0x00419130();
  *(int *)(iVar4 + 8) = param_1;
  *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar5 + 8);
  if (*(int **)(iVar5 + 8) == (int *)0x0) {
    *(int *)(iVar5 + 4) = iVar4;
    *(int *)(iVar5 + 8) = iVar4;
    return;
  }
  **(int **)(iVar5 + 8) = iVar4;
  *(int *)(iVar5 + 8) = iVar4;
  return;
}


/* ==================================================================== */
/* Address: 0x00737fe0 | Classified: AngelicaUI::proc_737fe0 */
/* ==================================================================== */

void __thiscall FUN_00737fe0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00737ff0 | Classified: AngelicaUI::proc_737ff0 */
/* ==================================================================== */

bool __fastcall FUN_00737ff0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0072fcc0();
  return iVar1 == param_1;
}


/* ==================================================================== */
/* Address: 0x00738010 | Classified: elementclient::AUIDialog__GetData____data_name_n@0x738010 */
/* ==================================================================== */

undefined4 __fastcall FUN_00738010(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_8 = &UNK_008c9f38;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  if (*(int *)(param_1 + 0x9c) != 0) {
    cVar2 = func_0x00763c50(param_1 + 0xa4);
    if (cVar2 == '\0') {
      func_0x00739700(0x918,1,0x980ca4);
    }
  }
  uVar1 = *(undefined4 *)(param_1 + 0x9c);
  uStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return uVar1;
}


/* ==================================================================== */
/* Address: 0x00738090 | Classified: AngelicaUI::proc_738090 */
/* ==================================================================== */

void __fastcall FUN_00738090(int param_1)

{
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_8 = &UNK_008c9f58;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  func_0x00763940(&stack0x00000008);
  puStack_8 = (undefined *)0xffffffff;
  *(undefined4 *)(param_1 + 0x9c) = unaff_retaddr;
  func_0x007637f0();
  *unaff_FS_OFFSET = unaff_ESI;
  return;
}


/* ==================================================================== */
/* Address: 0x007380f0 | Classified: elementclient::AUIDialog__GetDataPtr____data_na@0x7380f0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007380f0(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_8 = &UNK_008c9f78;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  if (*(int *)(param_1 + 0xa0) != 0) {
    cVar2 = func_0x00763c50(param_1 + 0xa8);
    if (cVar2 == '\0') {
      func_0x00739700(0x92b,1,0x980cd0);
    }
  }
  uVar1 = *(undefined4 *)(param_1 + 0xa0);
  uStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return uVar1;
}


/* ==================================================================== */
/* Address: 0x00738170 | Classified: AngelicaUI::proc_738170 */
/* ==================================================================== */

void __fastcall FUN_00738170(int param_1)

{
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_8 = &UNK_008c9f98;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  func_0x00763940(&stack0x00000008);
  puStack_8 = (undefined *)0xffffffff;
  *(undefined4 *)(param_1 + 0xa0) = unaff_retaddr;
  func_0x007637f0();
  *unaff_FS_OFFSET = unaff_ESI;
  return;
}


/* ==================================================================== */
/* Address: 0x007381d0 | Classified: AngelicaUI::proc_7381d0 */
/* ==================================================================== */

void __thiscall
FUN_007381d0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  int unaff_retaddr;
  int iStack_10;
  int iStack_c;
  undefined1 auStack_8 [8];
  
  FUN_00737320(auStack_8);
  FUN_007354d0(&stack0xffffffec);
  if (unaff_retaddr == 0) {
    if (param_2 == 2) {
      *(int *)(param_1 + 0x54) = unaff_EDI;
    }
    else {
      if (param_2 == 3) {
        iStack_10 = iStack_10 - *(int *)(param_1 + 0x70);
      }
      else {
LAB_00738243:
        iStack_10 = (iStack_10 - *(int *)(param_1 + 0x70)) / 2;
      }
LAB_0073824f:
      *(int *)(param_1 + 0x54) = iStack_10 + unaff_EDI;
    }
  }
  else {
    if (param_2 != 2) {
      if (param_2 != 3) goto LAB_00738243;
      goto LAB_0073824f;
    }
    *(int *)(param_1 + 0x54) = unaff_EDI - *(int *)(param_1 + 0x70);
  }
  if (param_3 == 0) {
    if (param_4 == 4) {
      *(int *)(param_1 + 0x58) = unaff_ESI;
      goto LAB_007382c0;
    }
    if (param_4 == 5) {
      *(int *)(param_1 + 0x58) = (iStack_c - *(int *)(param_1 + 0x74)) + unaff_ESI;
      goto LAB_007382c0;
    }
LAB_007382a9:
    iVar1 = (iStack_c - *(int *)(param_1 + 0x74)) / 2;
  }
  else {
    if (param_4 != 4) {
      if (param_4 == 5) {
        *(int *)(param_1 + 0x58) = iStack_c + unaff_ESI;
        goto LAB_007382c0;
      }
      goto LAB_007382a9;
    }
    iVar1 = -*(int *)(param_1 + 0x74);
  }
  *(int *)(param_1 + 0x58) = iVar1 + unaff_ESI;
LAB_007382c0:
  *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + param_5;
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + param_6;
  return;
}


/* ==================================================================== */
/* Address: 0x007382e0 | Classified: AngelicaUI::proc_7382e0 */
/* ==================================================================== */

undefined1 __fastcall FUN_007382e0(int param_1)

{
  return *(undefined1 *)(param_1 + 0x7c);
}


/* ==================================================================== */
/* Address: 0x007382f0 | Classified: AngelicaUI::proc_7382f0 */
/* ==================================================================== */

void __thiscall FUN_007382f0(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x7c) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00738300 | Classified: AngelicaUI::proc_738300 */
/* ==================================================================== */

void __thiscall FUN_00738300(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x84) = param_2;
  uVar1 = GetTickCount();
  *(undefined4 *)(param_1 + 0x88) = uVar1;
  return;
}


/* ==================================================================== */
/* Address: 0x00738320 | Classified: AngelicaUI::proc_738320 */
/* ==================================================================== */

void __thiscall FUN_00738320(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x61) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00738330 | Classified: AngelicaUI::proc_738330 */
/* ==================================================================== */

undefined4 __fastcall FUN_00738330(int param_1)

{
  return *(undefined4 *)(param_1 + 0x98);
}


/* ==================================================================== */
/* Address: 0x00738340 | Classified: AngelicaUI::proc_738340 */
/* ==================================================================== */

void __thiscall FUN_00738340(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x98) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00738350 | Classified: AngelicaUI::proc_738350 */
/* ==================================================================== */

void __thiscall FUN_00738350(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 99) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00738570 | Classified: AngelicaUI::proc_738570 */
/* ==================================================================== */

void __thiscall FUN_00738570(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x62) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00738580 | Classified: AngelicaUI::proc_738580 */
/* ==================================================================== */

undefined4 __fastcall FUN_00738580(int param_1)

{
  return *(undefined4 *)(param_1 + 0xd0);
}


/* ==================================================================== */
/* Address: 0x00738590 | Classified: AngelicaUI::proc_738590 */
/* ==================================================================== */

void __thiscall FUN_00738590(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x80) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x007385a0 | Classified: AngelicaUI::proc_7385a0 */
/* ==================================================================== */

undefined1 __fastcall FUN_007385a0(int param_1)

{
  return *(undefined1 *)(param_1 + 8);
}


/* ==================================================================== */
/* Address: 0x007385b0 | Classified: AngelicaUI::proc_7385b0 */
/* ==================================================================== */

void __thiscall FUN_007385b0(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 8) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x007385c0 | Classified: AngelicaUI::proc_7385c0 */
/* ==================================================================== */

void FUN_007385c0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_14 = param_1;
  uStack_10 = *param_2;
  uStack_c = param_2[1];
  uStack_8 = param_2[2];
  uStack_4 = param_2[3];
  func_0x007391d0(&uStack_14);
  return;
}


/* ==================================================================== */
/* Address: 0x00738600 | Classified: AngelicaUI::proc_738600 */
/* ==================================================================== */

void __thiscall FUN_00738600(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    piVar3 = *(int **)(param_1 + 0x18);
    while (param_2 != *piVar3) {
      iVar1 = iVar1 + 1;
      piVar3 = piVar3 + 5;
      if (*(int *)(param_1 + 0x24) <= iVar1) {
        return;
      }
    }
    if (*(int *)(param_1 + 0x24) != 0) {
      piVar3 = *(int **)(param_1 + 0x18) + iVar1 * 5;
      if (piVar3 < (int *)(*(int *)(param_1 + 0x1c) + -0x14)) {
        piVar2 = piVar3 + 8;
        do {
          *piVar3 = piVar2[-3];
          piVar2[-7] = piVar2[-2];
          piVar2[-6] = piVar2[-1];
          piVar2[-5] = *piVar2;
          piVar2[-4] = piVar2[1];
          piVar3 = piVar3 + 5;
          piVar2 = piVar2 + 5;
        } while (piVar3 < (int *)(*(int *)(param_1 + 0x1c) + -0x14));
      }
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -0x14;
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00738690 | Classified: AngelicaUI::proc_738690 */
/* ==================================================================== */

void __thiscall FUN_00738690(int param_1,undefined4 param_2,undefined1 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 200)) {
    iVar3 = 0;
    while( true ) {
      iVar1 = _stricmp(*(undefined4 *)(iVar3 + 4 + *(int *)(param_1 + 0xbc)),param_2);
      if (iVar1 == 0) break;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0xc;
      if (*(int *)(param_1 + 200) <= iVar2) {
        return;
      }
    }
    *(undefined1 *)(*(int *)(param_1 + 0xbc) + 1 + iVar2 * 0xc) = param_3;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007386f0 | Classified: AngelicaUI::proc_7386f0 */
/* ==================================================================== */

void __thiscall FUN_007386f0(int param_1,undefined4 param_2,undefined1 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 200)) {
    iVar3 = 0;
    while( true ) {
      iVar1 = _stricmp(*(undefined4 *)(iVar3 + 4 + *(int *)(param_1 + 0xbc)),param_2);
      if (iVar1 == 0) break;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0xc;
      if (*(int *)(param_1 + 200) <= iVar2) {
        return;
      }
    }
    *(undefined1 *)(*(int *)(param_1 + 0xbc) + iVar2 * 0xc) = param_3;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00738750 | Classified: AngelicaUI::proc_738750 */
/* ==================================================================== */

undefined4 __thiscall
FUN_00738750(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  char cVar1;
  int *piVar2;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  piVar2 = (int *)(**(code **)*param_1)();
  cVar1 = FUN_007387c0(piVar2[1],param_2,param_3,param_4,param_5);
  while( true ) {
    if (cVar1 != '\0') {
      return 1;
    }
    piVar2 = (int *)*piVar2;
    if (piVar2 == (int *)0x0) break;
    cVar1 = FUN_007387c0(piVar2[1],unaff_EDI,unaff_ESI,param_4,param_5);
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x007387c0 | Classified: AngelicaUI::proc_7387c0 */
/* ==================================================================== */

undefined4 FUN_007387c0(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ca008;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
LAB_007387e4:
  do {
    if (param_1[4] == 0) {
      *unaff_FS_OFFSET = uStack_c;
      return 0;
    }
    if (param_2 == param_1[1]) {
      if (param_5 == 0) {
        if (*param_1 == 0) {
LAB_0073884e:
          (*(code *)param_1[4])();
          *unaff_FS_OFFSET = unaff_EDI;
          return 1;
        }
        param_1 = param_1 + 8;
        goto LAB_007387e4;
      }
      func_0x007636b0();
      puStack_8 = (undefined *)0x0;
      uVar2 = func_0x00868610();
      func_0x007636b0(uVar2);
      uStack_c = 0xffffffff;
      cVar1 = func_0x0075d700();
      if (cVar1 != '\0') goto LAB_0073884e;
    }
    param_1 = param_1 + 8;
  } while( true );
}


