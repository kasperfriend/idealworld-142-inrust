/* Authentic Ghidra 12.1.4 Decompilation — elementclient.exe (PW 1.4.2 Build 2305) */
/* Module: 11_auicontrols_frame.c */

/* ==================================================================== */
/* Address: 0x0073d4a0 | Classified: AUIEditBox::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0073d4a0(undefined4 param_1,byte param_2)

{
  FUN_0073d4c0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0073d4c0 | Classified: AngelicaUI::proc_73d4c0 */
/* ==================================================================== */

void __fastcall FUN_0073d4c0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  puStack_8 = &UNK_008ca352;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008eec1c;
  piVar3 = param_1 + 0x522;
  iStack_4 = 3;
  iVar1 = 0x400;
  do {
    if ((undefined4 *)*piVar3 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar3)(1);
    }
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iStack_4._0_1_ = 2;
  param_1[0x922] = 0;
  param_1[0x923] = 0;
  param_1[0x924] = 0;
  param_1[0x925] = 0;
  param_1[0x926] = 0;
  FUN_00765200();
  iStack_4._0_1_ = 1;
  FUN_00765200();
  iVar1 = 0;
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  param_1[0x82] = &UNK_008eec68;
  if (0 < (int)param_1[0x8e]) {
    puVar2 = param_1 + 0x84;
    do {
      func_0x00763260(*puVar2);
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar1 < (int)param_1[0x8e]);
  }
  param_1[0x8e] = 0;
  func_0x00763260(param_1[0x83]);
  param_1[0x83] = 0;
  param_1[0x8f] = 0;
  param_1[0x90] = 0;
  iStack_4 = 0xffffffff;
  FUN_00741b50();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x0073dd30 | Classified: AngelicaUI::proc_73dd30 */
/* ==================================================================== */

void __fastcall FUN_0073dd30(int param_1)

{
  int unaff_ESI;
  int aiStack_8 [2];
  
  if (*(int *)(param_1 + 0xbc) != 0) {
    FUN_007537a0(aiStack_8);
    *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0x58) - unaff_ESI / 2;
    *(int *)(param_1 + 0xac) = unaff_ESI / 2;
    *(int *)(param_1 + 0xb0) = aiStack_8[0] / 2;
    *(int *)(param_1 + 0xb8) = *(int *)(param_1 + 0x5c) - aiStack_8[0] / 2;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0073dd90 | Classified: AUIEditBox::vfunc_slot_3 */
/* ==================================================================== */

void __fastcall FUN_0073dd90(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (*(char *)(param_1 + 0x45) != '\0') {
    DAT_009812c0 = 0;
  }
  if (*(int *)(param_1 + 0xbc) != 0) {
    FUN_00753080();
    if (*(undefined4 **)(param_1 + 0xbc) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0xbc))(1);
    }
    *(undefined4 *)(param_1 + 0xbc) = 0;
  }
  piVar2 = (int *)(param_1 + 0x1488);
  iVar1 = 0x400;
  do {
    if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar2)(1);
    }
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *(undefined4 *)(param_1 + 0x2488) = 0;
  *(undefined4 *)(param_1 + 0x248c) = 0;
  *(undefined4 *)(param_1 + 0x2490) = 0;
  *(undefined4 *)(param_1 + 0x2494) = 0;
  *(undefined4 *)(param_1 + 0x2498) = 0;
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0xa0);
  FUN_00430850();
  return;
}


/* ==================================================================== */
/* Address: 0x0073df40 | Classified: AUIEditBox::vfunc_slot_12 */
/* ==================================================================== */

int __fastcall FUN_0073df40(int param_1)

{
  int *piVar1;
  short *psVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  int iStack_2c;
  undefined1 auStack_1c [4];
  undefined1 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ca3d8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iStack_2c = param_1 + 0x1488;
  iStack_2c = func_0x0073a9b0();
  piVar1 = (int *)(param_1 + 0x74);
  uStack_4 = 0;
  FUN_007652d0();
  puStack_8 = (undefined *)0xffffffff;
  FUN_00765200();
  FUN_00765050();
  uStack_c = 1;
  if ((*(char *)(param_1 + 0xa8) != '\0') && (1 < *(int *)(*piVar1 + -8))) {
    iVar5 = 0;
    do {
      psVar2 = (short *)FUN_007655e0(iVar5);
      if ((*psVar2 == 0xd) && (psVar2 = (short *)FUN_007655e0(iVar5 + 1), *psVar2 == 10)) {
        uVar3 = func_0x004cb7f0(auStack_1c,iVar5 + 2,0xffffffff);
        uStack_18 = 2;
        uVar4 = func_0x004cb780(&iStack_2c,iVar5);
        uVar3 = func_0x00403ba0(&stack0xffffffc8,uVar4,uVar3);
        FUN_007652d0(uVar3);
        FUN_00765200();
        FUN_00765200();
        FUN_00765200();
      }
      else {
        iVar5 = iVar5 + 1;
      }
    } while (iVar5 + 1 < *(int *)(*piVar1 + -8));
  }
  iVar5 = *piVar1;
  uStack_c = 0xffffffff;
  FUN_00765200();
  *unaff_FS_OFFSET = uStack_14;
  return iVar5;
}


/* ==================================================================== */
/* Address: 0x0073e0a0 | Classified: AUIEditBox::vfunc_slot_13 */
/* ==================================================================== */

void __thiscall FUN_0073e0a0(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  int iVar4;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ca3f8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_00742520(param_2);
  iVar4 = 0x400;
  piVar3 = param_1 + 0x522;
  do {
    if ((undefined4 *)*piVar3 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar3)(1);
    }
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  param_1[0x922] = 0;
  param_1[0x923] = 0;
  param_1[0x924] = 0;
  param_1[0x925] = 0;
  param_1[0x926] = 0;
  uVar2 = func_0x0073ab00(&stack0x00000000,unaff_retaddr,param_1 + 0x522);
  puStack_8 = (undefined *)0x0;
  FUN_007652d0(uVar2);
  uStack_c = 0xffffffff;
  FUN_00765200();
  iVar4 = *(int *)(param_1[0x491] + -8);
  iVar1 = *(int *)(param_1[0x1d] + -8);
  param_1[0x35] = iVar4;
  param_1[0x37] = iVar4;
  param_1[0x36] = iVar4;
  param_1[0x27] = (param_1[0x28] - iVar1) + iVar4;
  param_1[0x51b] = 0;
  param_1[0x51c] = 0;
  (**(code **)(*param_1 + 0x3c))();
  if (*(char *)((int)param_1 + 0x45) != '\0') {
    FUN_0073f410(0);
  }
  *unaff_FS_OFFSET = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x0073e1b0 | Classified: AngelicaUI::proc_73e1b0 */
/* ==================================================================== */

char __thiscall
FUN_0073e1b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_00742530(param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  if (cVar1 != '\0') {
    iVar2 = func_0x0075bc90();
    *(char *)(param_1 + 0x1478) = (char)*(undefined4 *)(iVar2 + 0x24);
  }
  return cVar1;
}


/* ==================================================================== */
/* Address: 0x0073e830 | Classified: AngelicaUI::proc_73e830 */
/* ==================================================================== */

void __thiscall FUN_0073e830(int param_1,int param_2,short *param_3)

{
  short sVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  ushort *puVar5;
  
  param_2 = param_2 - (*(int *)(param_1 + 0x146c) + *(int *)(param_1 + 0xac));
  iVar4 = (int)param_3 - (*(int *)(param_1 + 0x1470) + *(int *)(param_1 + 0xb0));
  iVar2 = 0;
  puVar5 = (ushort *)(param_1 + 0x244);
  puVar3 = (ushort *)(param_1 + 0x246);
  param_3 = *(short **)(param_1 + 0x1244);
  do {
    sVar1 = *param_3;
    if ((sVar1 == 0xd) || (sVar1 == 0)) {
      iVar4 = iVar4 - (uint)*(byte *)(param_1 + 0x1478);
      if ((iVar4 < 0) || (sVar1 == 0)) goto LAB_0073e8ed;
    }
    else if ((iVar4 <= (int)(uint)*(byte *)(param_1 + 0x1478)) && (sVar1 != 10)) {
      param_2 = param_2 - ((uint)*puVar3 - (uint)*puVar5);
      if (param_2 < 0) break;
    }
    puVar3 = puVar3 + 1;
    param_3 = param_3 + 1;
    iVar2 = iVar2 + 1;
    puVar5 = puVar5 + 1;
  } while( true );
  if (-((int)((uint)*puVar3 - (uint)*puVar5) / 2) <= param_2) {
    iVar2 = iVar2 + 1;
  }
LAB_0073e8ed:
  if (*(int *)(param_1 + 0xf0) == 0) {
    *(int *)(param_1 + 0xdc) = iVar2;
    *(int *)(param_1 + 0xd8) = iVar2;
    FUN_0073f410(0);
    return;
  }
  if (iVar2 < *(int *)(param_1 + 0xd8)) {
    *(int *)(param_1 + 0xe4) = iVar2;
  }
  else {
    if (iVar2 <= *(int *)(param_1 + 0xdc)) goto LAB_0073e948;
    *(int *)(param_1 + 0xe4) = *(int *)(param_1 + 0xe4) + (iVar2 - *(int *)(param_1 + 0xdc));
  }
  FUN_0073f5f0(0,8);
LAB_0073e948:
  FUN_0073f410(0);
  return;
}


/* ==================================================================== */
/* Address: 0x0073e960 | Classified: AUIEditBox::vfunc_slot_7 */
/* ==================================================================== */

undefined4 __thiscall FUN_0073e960(int *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBX;
  int unaff_EBP;
  int *piVar4;
  undefined1 auStack_8 [8];
  
  if (*(char *)((int)param_1 + 0xa5) != '\0') {
    return 0;
  }
  uVar3 = *(undefined4 *)(param_1[2] + 4);
  if (param_2 < 0x110) {
    if (param_2 == 0x10f) {
      if (((param_1[0x3f] & 0x10000U) != 0) && (DAT_009c1570 != '\0')) {
        func_0x00763260(param_1[0x83]);
        param_1[0x83] = 0;
        param_1[0x8f] = 0;
      }
      iVar2 = FUN_0073f5f0(param_3,param_4);
      if (iVar2 != 0) {
        return 1;
      }
    }
    else {
      switch(param_2) {
      case 0x51:
        if (DAT_009c1570 != '\0') {
          iVar2 = 0;
          if (0 < param_1[0x8e]) {
            piVar4 = param_1 + 0x84;
            do {
              func_0x00763260(*piVar4);
              iVar2 = iVar2 + 1;
              piVar4 = piVar4 + 1;
            } while (iVar2 < param_1[0x8e]);
          }
          param_1[0x8e] = 0;
          func_0x00763260(param_1[0x83]);
          param_1[0x83] = 0;
          param_1[0x8f] = 0;
          param_1[0x90] = 0;
          func_0x00760f10(uVar3);
        }
        FUN_0073fc30(param_4);
        break;
      default:
        goto LAB_0073ec8e;
      case 0x100:
        FUN_007407f0(param_3);
        return 1;
      case 0x102:
        param_1[0x30] = -1;
        FUN_007402a0(param_3);
        if ((param_3 < 0x20) && (param_3 != 0xd)) {
          return 0;
        }
        return 1;
      case 0x10d:
        param_1[0x40] = 1;
        if ((param_1[0x3f] & 0x10000U) != 0) {
          FUN_0073f5a0(param_3,param_4);
          return 1;
        }
        break;
      case 0x10e:
        param_1[0x40] = 0;
        if ((param_1[0x3f] & 0x10000U) != 0) {
          FUN_0073fa50(param_3,param_4);
        }
      }
    }
    goto LAB_0073ebfb;
  }
  if (0x282 < param_2) {
    if (param_2 == 0x286) {
      return 1;
    }
    if (param_2 == 0x9c77) {
      return 1;
    }
LAB_0073ec8e:
    return 0;
  }
  if (param_2 != 0x282) {
    if (param_2 == 0x201) {
      FUN_00741db0(auStack_8,0);
      iVar2 = *(int *)(*(int *)(param_1[1] + 0xa8) + 0x14);
      iVar1 = *(int *)(*(int *)(param_1[1] + 0xa8) + 0x18);
      param_1[0x30] = -1;
      (**(code **)(*param_1 + 0x3c))();
      FUN_0073e830((0x201 - iVar2) - unaff_EBP,-unaff_EBX - iVar1);
      return 1;
    }
    if (param_2 != 0x281) {
      return 0;
    }
    goto LAB_0073ebfb;
  }
  if (param_3 != 3) {
    if (param_3 == 4) {
      if (DAT_009c1570 != '\0') {
        iVar2 = 0;
        if (0 < param_1[0x8e]) {
          piVar4 = param_1 + 0x84;
          do {
            func_0x00763260(*piVar4);
            iVar2 = iVar2 + 1;
            piVar4 = piVar4 + 1;
          } while (iVar2 < param_1[0x8e]);
        }
        param_1[0x8e] = 0;
        param_1[0x90] = 0;
      }
      if ((param_1[0x3f] & 0x10000U) == 0) {
        param_1[0x40] = 0;
      }
      goto LAB_0073ebfb;
    }
    if (param_3 != 5) goto LAB_0073ebfb;
    if (param_1[0x31] == 2) {
      FUN_0073fdb0();
    }
  }
  if (DAT_009c1570 != '\0') {
    func_0x0075f980(param_1 + 0x82,1);
  }
LAB_0073ebfb:
  uVar3 = func_0x00773a20(param_2,param_3,param_4);
  return uVar3;
}


/* ==================================================================== */
/* Address: 0x0073ed80 | Classified: AUILabel::vfunc_slot_5 */
/* ==================================================================== */

undefined4 __fastcall thunk_FUN_00741fa0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = GetTickCount();
  if ((*(char *)(param_1 + 0x81) != '\0') && (499 < iVar1 - *(int *)(param_1 + 0x7c))) {
    *(int *)(param_1 + 0x7c) = iVar1;
    *(bool *)(param_1 + 0x80) = *(char *)(param_1 + 0x80) == '\0';
  }
  if ((*(char *)(param_1 + 0x49) != '\0') && (499 < iVar1 - *(int *)(param_1 + 0x4c))) {
    iVar2 = *(int *)(param_1 + 0x88);
    if (*(int *)(param_1 + 0x84) == iVar2) {
      if (0x9f < iVar2) {
        *(int *)(param_1 + 0x4c) = iVar1;
        *(int *)(param_1 + 0x84) = iVar2 + -0x60;
        return 1;
      }
      iVar2 = iVar2 + 0x60;
    }
    *(int *)(param_1 + 0x84) = iVar2;
    *(int *)(param_1 + 0x4c) = iVar1;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0073ed90 | Classified: AUIEditBox::vfunc_slot_6 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0073ed90(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *unaff_FS_OFFSET;
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  undefined4 uStack_50;
  uint uStack_4c;
  int iStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined4 uStack_28;
  int iStack_1c;
  int iStack_18;
  undefined1 auStack_14 [8];
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ca420;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  puStack_2c = auStack_14;
  uStack_28 = 0;
  uStack_30 = 0x73edb8;
  FUN_00741db0();
  if (param_1[0x2f] == 0) {
    uStack_30 = 0x73ee35;
    FUN_00430850();
  }
  else {
    iStack_38 = param_1[0x21];
    uStack_30 = 0;
    uStack_34 = 0;
    iStack_54 = param_1[0x17];
    uStack_3c = 0;
    uStack_40 = 0;
    uStack_44 = 0;
    iStack_48 = 0x9b3c40;
    uStack_4c = 0;
    uStack_50 = 0;
    iStack_58 = param_1[0x16];
    iStack_5c = iStack_18 + param_1[0x19];
    cVar1 = FUN_007530d0(iStack_1c + param_1[0x18]);
    if (cVar1 == '\0') {
      uVar2 = func_0x00739700(0x279,1,0x98142c);
      *unaff_FS_OFFSET = iStack_48;
      return uVar2;
    }
  }
  iStack_58 = _DAT_00985a98;
  uStack_40 = 0;
  if (*(char *)((int)param_1 + 0xa6) == '\0') {
    piVar3 = param_1 + 0x491;
    FUN_007652d0(piVar3);
  }
  else {
    piVar3 = (int *)wcslen(param_1[0x491]);
    FUN_007650b0(0x2a,piVar3);
    iStack_48 = CONCAT31(iStack_48._1_3_,1);
    FUN_007652d0(&iStack_5c);
    uStack_4c = uStack_4c & 0xffffff00;
    FUN_00765200();
  }
  iVar4 = wcslen(piVar3);
  if (iVar4 != 0) {
    iVar4 = param_1[0xd];
    if (iVar4 == 0) {
      func_0x00868610();
      iVar4 = FUN_007537e0();
    }
    (**(code **)(*param_1 + 0x40))(iVar4,piVar3);
  }
  if (((param_1[0x40] != 0) && ((param_1[0x3f] & 0x10000U) != 0)) && (param_1[0x31] != 3)) {
    FUN_0073ef40();
  }
  if (DAT_009c1570 != '\0') {
    FUN_00741220();
  }
  cVar1 = FUN_007424f0();
  if (cVar1 != '\0') {
    FUN_0073ff60();
  }
  uStack_4c = 0xffffffff;
  FUN_00765200();
  *unaff_FS_OFFSET = iStack_54;
  return 1;
}


/* ==================================================================== */
/* Address: 0x0073ef40 | Classified: AngelicaUI::proc_73ef40 */
/* ==================================================================== */

void __fastcall FUN_0073ef40(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  undefined1 auStack_8 [8];
  
  FUN_00741db0(auStack_8,0);
  iVar1 = *(int *)(param_1 + 0xac) + iStack_10;
  iVar6 = *(int *)(param_1 + 0xb4) + iStack_10;
  iVar2 = *(int *)(param_1 + 0xb0) + iStack_c;
  iVar7 = *(int *)(param_1 + 0xb8) + iStack_c;
  iStack_10 = iStack_10 + *(int *)(param_1 + 0x146c) + *(int *)(param_1 + 0xac);
  iStack_c = iStack_c + -1 +
             (uint)*(byte *)(param_1 + 0x1478) + *(int *)(param_1 + 0x1470) +
             *(int *)(param_1 + 0xb0);
  *(undefined2 *)(param_1 + 0x124c + (*(int *)(param_1 + 0xf0) / 2) * 2) = 0;
  iVar9 = *(int *)(param_1 + 0xd8);
  iVar8 = *(int *)(param_1 + 0xf0) / 2;
  while (0 < iVar8) {
    psVar4 = (short *)FUN_007655e0(iVar9);
    iVar5 = iVar9;
    if (*psVar4 == 10) {
      iVar9 = iVar9 + 1;
      iVar5 = iVar9;
    }
    while (((0 < iVar8 && (psVar4 = (short *)FUN_007655e0(iVar9), *psVar4 != 0xd)) &&
           (psVar4 = (short *)FUN_007655e0(iVar9), *psVar4 != 0))) {
      iVar8 = iVar8 + -1;
      iVar9 = iVar9 + 1;
    }
    *(uint *)(param_1 + 0x1464) = (uint)*(ushort *)(param_1 + 0x244 + iVar5 * 2) + iStack_10;
    *(uint *)(param_1 + 0x1468) = (uint)*(ushort *)(param_1 + 0xa44 + iVar5 * 2) + iStack_c;
    iVar5 = (uint)*(ushort *)(param_1 + 0x244 + iVar9 * 2) + iStack_10;
    if (*(int *)(param_1 + 0x1464) < iVar1) {
      *(int *)(param_1 + 0x1464) = iVar1;
    }
    if (iVar6 < *(int *)(param_1 + 0x1464)) {
      *(int *)(param_1 + 0x1464) = iVar6;
    }
    if (iVar5 < iVar1) {
      iVar5 = iVar1;
    }
    if (iVar6 < iVar5) {
      iVar5 = iVar6;
    }
    iVar3 = *(int *)(param_1 + 0x1468);
    *(int *)(param_1 + 0x1474) = iVar5 - *(int *)(param_1 + 0x1464);
    if ((iVar2 <= iVar3) && (iVar3 <= iVar7)) {
      iStack_18 = *(int *)(param_1 + 100) + iVar3;
      iStack_14 = *(int *)(param_1 + 0x60) + *(int *)(param_1 + 0x1464);
      func_0x005caba0(&iStack_14,&iStack_18);
      FUN_007400d0();
    }
    iVar9 = iVar9 + 1;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0073f3b0 | Classified: AngelicaUI::proc_73f3b0 */
/* ==================================================================== */

void __thiscall FUN_0073f3b0(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0xa8) = param_2;
  if (*(char *)(param_1 + 0xa7) == '\0') {
    *(undefined1 *)(param_1 + 0xa8) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0073f3d0 | Classified: AngelicaUI::proc_73f3d0 */
/* ==================================================================== */

void __thiscall FUN_0073f3d0(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0xa6) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x0073f3e0 | Classified: AngelicaUI::proc_73f3e0 */
/* ==================================================================== */

void __thiscall FUN_0073f3e0(int param_1,char param_2)

{
  *(char *)(param_1 + 0xa5) = param_2;
  FUN_00742640(param_2 == '\0');
  return;
}


/* ==================================================================== */
/* Address: 0x0073f400 | Classified: AngelicaUI::proc_73f400 */
/* ==================================================================== */

void __thiscall FUN_0073f400(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0xa7) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x0073f410 | Classified: AngelicaUI::proc_73f410 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0073f410(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 0xa5) == '\0') {
    *(int *)(param_1 + 0x1458) = *(int *)(param_1 + 0x1458) + -1;
    uVar1 = (uint)*(ushort *)(param_1 + 0x244 + *(int *)(param_1 + 0xdc) * 2);
    iVar3 = uVar1 + *(int *)(param_1 + 0x146c);
    if (iVar3 < 0) {
      iVar3 = 0;
      *(uint *)(param_1 + 0x146c) = -uVar1;
    }
    else if (*(int *)(param_1 + 0xb4) - *(int *)(param_1 + 0xac) < iVar3) {
      iVar3 = *(int *)(param_1 + 0xb4) - *(int *)(param_1 + 0xac);
      *(uint *)(param_1 + 0x146c) = iVar3 - uVar1;
    }
    uVar1 = (uint)*(ushort *)(param_1 + 0xa44 + *(int *)(param_1 + 0xdc) * 2);
    iVar2 = *(int *)(param_1 + 0x1470) + uVar1;
    if (*(char *)(param_1 + 0xa7) != '\0') {
      if (iVar2 < 0) {
        iVar2 = 0;
        *(uint *)(param_1 + 0x1470) = -uVar1;
      }
      else if (*(int *)(param_1 + 0xb8) - *(int *)(param_1 + 0xb0) <
               (int)((uint)*(byte *)(param_1 + 0x1478) + iVar2)) {
        iVar2 = (*(int *)(param_1 + 0xb8) - *(int *)(param_1 + 0xb0)) -
                (uint)*(byte *)(param_1 + 0x1478);
        *(uint *)(param_1 + 0x1470) = iVar2 - uVar1;
      }
    }
    FUN_00740050(*(int *)(param_1 + 0xac) + iVar3,*(int *)(param_1 + 0xb0) + iVar2);
    *(int *)(param_1 + 0x1458) = *(int *)(param_1 + 0x1458) + 1;
    *(undefined4 *)(param_1 + 0x1450) = 0;
    *(undefined1 *)(param_1 + 0x1454) = 0;
    if (((*(uint *)(param_1 + 0xfc) & 0x10000) == 0) && (DAT_009c1570 == '\0')) {
      iVar3 = GetCurrentThreadId();
      if (_DAT_009c1578 == iVar3) {
        FUN_0073fec0();
      }
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0073f550 | Classified: AngelicaUI::proc_73f550 */
/* ==================================================================== */

undefined4 __thiscall FUN_0073f550(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined1 auStack_8 [4];
  undefined4 *puStack_4;
  
  if ((param_4 == 0) && (*(int *)(param_1 + 0x34) == 0)) {
    func_0x00868610();
    FUN_007537e0();
  }
  puVar2 = (undefined4 *)func_0x0073c830(auStack_8,param_2,0xffffffff);
  uVar1 = *puVar2;
  if (puStack_4 != (undefined4 *)0x0) {
    *puStack_4 = puVar2[1];
  }
  return uVar1;
}


/* ==================================================================== */
/* Address: 0x0073f5a0 | Classified: AngelicaUI::proc_73f5a0 */
/* ==================================================================== */

void __fastcall FUN_0073f5a0(int param_1)

{
  if (0xfe < *(int *)(param_1 + 0xd4)) {
    FUN_0073fd80();
  }
  *(int *)(param_1 + 0x1458) = *(int *)(param_1 + 0x1458) + 1;
  FUN_007652d0(param_1 + 0x1244);
  *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_1 + 0xd8);
  *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_1 + 0xd4);
  return;
}


/* ==================================================================== */
/* Address: 0x0073f5f0 | Classified: AngelicaUI::proc_73f5f0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0073f5f0(int *param_1,uint param_2)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  int unaff_EDI;
  int iVar8;
  int *piVar9;
  undefined4 uStack_808;
  uint uStack_c;
  
  iVar6 = *(int *)(param_1[2] + 4);
  iVar2 = func_0x007ee490(iVar6);
  if (iVar2 != 0) {
    if ((param_1[0x40] != 0) && ((param_1[0x3f] & 0x10000U) != 0)) {
      FUN_007652d0(param_1 + 0x492);
      param_1[0x37] = param_1[0x39];
      param_1[0x36] = param_1[0x39];
      param_1[0x35] = param_1[0x38];
      (**(code **)(*param_1 + 0x3c))();
    }
    param_1[0x3c] = 0;
    if ((param_2 & 0x800) != 0) {
      piVar9 = param_1 + 0x493;
      for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
        *piVar9 = 0;
        piVar9 = piVar9 + 1;
      }
      *(undefined2 *)piVar9 = 0;
      iVar5 = func_0x007ee48a(iVar2,0x800,param_1 + 0x493,0x202);
      param_1[0x3c] = iVar5;
      if (-1 < iVar5) {
        iVar5 = FUN_0073fa60(1);
        if ((char)param_1[0x2a] == '\0') {
          param_1[0x35] = param_1[0x35] + iVar5;
        }
        else {
          iVar8 = param_1[0x36];
          if (iVar8 < iVar8 + iVar5) {
            do {
              iVar2 = iVar6;
              psVar3 = (short *)FUN_007655e0(iVar8);
              if ((*psVar3 != 0xd) && (psVar3 = (short *)FUN_007655e0(iVar8), *psVar3 != 10)) {
                param_1[0x35] = param_1[0x35] + 1;
              }
              iVar8 = iVar8 + 1;
              iVar6 = iVar2;
            } while (iVar8 < param_1[0x36] + iVar5);
          }
        }
        param_1[0x36] = param_1[0x36] + iVar5;
        if (((param_1[0x3f] & 0x10000U) != 0) && (param_1[0x3c] == 0)) {
          param_1[0x36] = param_1[0x39];
        }
        piVar9 = param_1 + 0x491;
        param_1[0x38] = param_1[0x35];
        param_1[0x37] = param_1[0x36];
        param_1[0x3c] = 0;
        param_1[0x39] = param_1[0x36];
        FUN_007652d0(piVar9);
        param_2 = uStack_c;
        if ((char)param_1[0x2a] == '\0') {
          FUN_00742520(*piVar9);
        }
        else {
          iVar5 = 0;
          iVar2 = 0;
          iVar6 = *(int *)(*piVar9 + -8);
          if (0 < iVar6) {
            puVar7 = (undefined2 *)&stack0xfffff7e4;
            do {
              psVar3 = (short *)FUN_007655e0(iVar5);
              if (((*psVar3 != 0xd) || (iVar5 + 1 == *(int *)(*piVar9 + -8))) ||
                 (psVar3 = (short *)FUN_007655e0(iVar5 + 1), *psVar3 != 10)) {
                puVar4 = (undefined2 *)FUN_007655e0(iVar5);
                iVar2 = iVar2 + 1;
                *puVar7 = *puVar4;
                puVar7 = puVar7 + 1;
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 < iVar6);
          }
          *(undefined2 *)(&stack0xfffff7e4 + iVar2 * 2) = 0;
          FUN_00742520(&stack0xfffff7e4);
          iVar2 = unaff_EDI;
        }
      }
      (**(code **)(*param_1 + 0x3c))();
      FUN_0073f410(0);
    }
    if ((param_2 & 8) != 0) {
      if ((param_1[0x3f] & 0x10000U) == 0) {
        return 0;
      }
      piVar9 = param_1 + 0x493;
      for (iVar6 = 0x80; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar9 = 0;
        piVar9 = piVar9 + 1;
      }
      *(undefined2 *)piVar9 = 0;
      iVar6 = func_0x007ee48a(iVar2,8,param_1 + 0x493,0x202);
      param_1[0x3c] = iVar6;
      if (param_1[0x31] != 3) {
        if ((param_2 & 0x10) != 0) {
          iVar6 = func_0x007ee48a(iVar2,0x10,param_1 + 0x41,0x101);
          param_1[0x3e] = iVar6;
        }
        if ((param_2 & 0x80) != 0) {
          iVar6 = func_0x007ee48a(iVar2,0x80,0,0);
          param_1[0x3d] = iVar6;
        }
        if ((param_1[0x31] == 1) || (param_1[0x31] == 4)) {
          for (iVar6 = param_1[0x3d];
              (iVar6 < param_1[0x3e] && (*(char *)((int)param_1 + iVar6 + 0x104) == '\x01'));
              iVar6 = iVar6 + 1) {
          }
        }
      }
      if (-1 < param_1[0x3c]) {
        FUN_0073fa60(0);
        if (param_1[0x31] != 3) {
          if (param_1[0x31] == 2) {
            param_1[0x37] = param_1[0x36] + param_1[0x3c] / 2;
          }
          else if ((char)param_1[0x2a] == '\0') {
            param_1[0x37] = param_1[0x3d] + param_1[0x36];
          }
          else {
            psVar3 = (short *)FUN_007655e0(param_1[0x36]);
            if (((*psVar3 == 0xd) && (param_1[0x36] + 1 < *(int *)(param_1[0x491] + -8))) &&
               (psVar3 = (short *)FUN_007655e0(param_1[0x36] + 1), *psVar3 == 10)) {
              param_1[0x36] = param_1[0x36] + 2;
            }
            iVar6 = 0;
            param_1[0x37] = param_1[0x36];
            iVar2 = unaff_EDI;
            if (0 < param_1[0x3d]) {
              do {
                iVar2 = param_1[0x37];
                param_1[0x37] = iVar2 + 1;
                psVar3 = (short *)FUN_007655e0(iVar2 + 1);
                sVar1 = *psVar3;
                while (((sVar1 == 0xd && (param_1[0x37] + 1 < *(int *)(param_1[0x491] + -8))) &&
                       (psVar3 = (short *)FUN_007655e0(param_1[0x37] + 1), *psVar3 == 10))) {
                  iVar2 = param_1[0x37];
                  param_1[0x37] = iVar2 + 2;
                  psVar3 = (short *)FUN_007655e0(iVar2 + 2);
                  sVar1 = *psVar3;
                }
                iVar6 = iVar6 + 1;
                iVar2 = unaff_EDI;
              } while (iVar6 < param_1[0x3d]);
            }
          }
        }
      }
      (**(code **)(*param_1 + 0x3c))();
      FUN_0073f410(0);
    }
    func_0x007ee484(uStack_808,iVar2);
    FUN_0073f410(0);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0073fa50 | Classified: AngelicaUI::proc_73fa50 */
/* ==================================================================== */

void __fastcall FUN_0073fa50(int param_1)

{
  *(int *)(param_1 + 0x1458) = *(int *)(param_1 + 0x1458) + 1;
  return;
}


/* ==================================================================== */
/* Address: 0x0073fa60 | Classified: AngelicaUI::proc_73fa60 */
/* ==================================================================== */

int __fastcall FUN_0073fa60(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined4 *unaff_FS_OFFSET;
  bool bVar8;
  undefined1 auStack_21c [8];
  undefined2 auStack_214 [248];
  undefined4 uStack_24;
  int iStack_1c;
  undefined1 uStack_18;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ca45c;
  *unaff_FS_OFFSET = &uStack_c;
  iVar3 = param_1[0x36];
  iVar1 = param_1[0x35];
  FUN_007655e0(iVar3);
  iVar6 = param_1[0x27];
  iVar2 = *(int *)(param_1[0x491] + -8);
  auStack_214[iVar1 - iVar3] = 0;
  iVar6 = iVar6 - iVar2;
  if (iVar6 < 0) {
    iVar6 = 0;
  }
  iVar3 = (param_1[0x3c] + 1) / 2;
  if (iVar6 < iVar3) {
    iVar3 = iVar6;
  }
  *(undefined2 *)((int)param_1 + iVar3 * 2 + 0x124c) = 0;
  wcslen(param_1 + 0x493);
  uVar7 = param_1[0x3c] & 0x80000001;
  bVar8 = uVar7 == 0;
  if ((int)uVar7 < 0) {
    bVar8 = (uVar7 - 1 | 0xfffffffe) == 0xffffffff;
  }
  if (!bVar8) {
    param_1[0x3c] = param_1[0x3c] + 1;
  }
  iVar3 = param_1[0x35] - param_1[0x36];
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  else {
    iVar1 = *(int *)(param_1[0x491] + -8);
    if (iVar1 < iVar3) {
      iVar3 = iVar1;
    }
  }
  uVar4 = func_0x004cb7b0(auStack_21c);
  uStack_10 = 0;
  uVar5 = func_0x004cb780(&stack0xfffffdd8,param_1[0x36]);
  uStack_18 = 1;
  uVar5 = func_0x004bcb50(&stack0xfffffdcc,uVar5,param_1 + 0x493);
  uStack_18 = 2;
  uVar4 = func_0x00403ba0(&stack0xfffffdd8,uVar5,uVar4);
  uStack_18 = 3;
  FUN_007652d0(uVar4);
  iStack_1c._0_1_ = 2;
  FUN_00765200();
  iStack_1c._0_1_ = 1;
  FUN_00765200();
  iStack_1c = (uint)iStack_1c._1_3_ << 8;
  FUN_00765200();
  iStack_1c = 0xffffffff;
  FUN_00765200();
  if ((char)param_1[0x2a] == '\0') {
    (**(code **)(*param_1 + 0x3c))();
  }
  else {
    param_1[0x37] = iVar3 + param_1[0x36];
    (**(code **)(*param_1 + 0x3c))();
    iVar3 = param_1[0x37] - param_1[0x36];
  }
  *unaff_FS_OFFSET = uStack_24;
  return iVar3;
}


/* ==================================================================== */
/* Address: 0x0073fc30 | Classified: AngelicaUI::proc_73fc30 */
/* ==================================================================== */

void __thiscall FUN_0073fc30(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = param_2 & 0xffff;
  if (uVar1 < 0x413) {
    if (uVar1 == 0x412) {
      *(undefined4 *)(param_1 + 0xc4) = 3;
      goto LAB_0073fc95;
    }
    if (uVar1 == 0x404) {
      *(undefined4 *)(param_1 + 0xc4) = 1;
      goto LAB_0073fc95;
    }
    if (uVar1 == 0x411) {
      *(undefined4 *)(param_1 + 0xc4) = 2;
      goto LAB_0073fc95;
    }
  }
  else if (uVar1 == 0x804) {
    *(undefined4 *)(param_1 + 0xc4) = 4;
    goto LAB_0073fc95;
  }
  *(undefined4 *)(param_1 + 0xc4) = 0;
LAB_0073fc95:
  iVar2 = func_0x007ee47e(param_2);
  if (iVar2 == 0) {
    FUN_0073fce0();
  }
  else {
    FUN_0073fd00(param_2);
  }
  uVar3 = func_0x007ee496(param_2,4);
  *(undefined4 *)(param_1 + 0xfc) = uVar3;
  *(undefined4 *)(param_1 + 0x100) = 0;
  *(undefined4 *)(param_1 + 0xf0) = 0;
  FUN_0073f410(0);
  return;
}


/* ==================================================================== */
/* Address: 0x0073fce0 | Classified: AngelicaUI::proc_73fce0 */
/* ==================================================================== */

void FUN_0073fce0(void)

{
  wcscpy(0x9810c0,0x981484);
  return;
}


/* ==================================================================== */
/* Address: 0x0073fd00 | Classified: AngelicaUI::proc_73fd00 */
/* ==================================================================== */

void FUN_0073fd00(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)0x9810c0;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  func_0x007ee49c(param_1,0x9810c0,0x200);
  return;
}


/* ==================================================================== */
/* Address: 0x0073fd30 | Classified: AngelicaUI::proc_73fd30 */
/* ==================================================================== */

undefined4 FUN_0073fd30(int param_1)

{
  undefined4 uVar1;
  ushort *puVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar1 = 1;
  if (-1 < param_1) {
    do {
      puVar2 = (ushort *)FUN_007655e0(iVar3);
      if ((*puVar2 < 0xd800) || (puVar2 = (ushort *)FUN_007655e0(iVar3), 0xdbff < *puVar2)) {
        uVar1 = 1;
      }
      else {
        uVar1 = 2;
        iVar3 = iVar3 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= param_1);
  }
  return uVar1;
}


/* ==================================================================== */
/* Address: 0x0073fd80 | Classified: AngelicaUI::proc_73fd80 */
/* ==================================================================== */

void __fastcall FUN_0073fd80(int param_1)

{
  FUN_00765230(0x9b3c40);
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x0073fdb0 | Classified: AngelicaUI::proc_73fdb0 */
/* ==================================================================== */

void __fastcall FUN_0073fdb0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int aiStack_2c [2];
  int iStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  
  iVar6 = *(int *)(*(int *)(param_1 + 8) + 4);
  aiStack_2c[0] = iVar6;
  iVar1 = func_0x007ee490(iVar6);
  if (iVar1 != 0) {
    iStack_24 = 0;
    iStack_20 = 2;
    if (*(int *)(param_1 + 0xc4) == 2) {
      puVar2 = (undefined4 *)
               func_0x00763250((*(int *)(param_1 + 0xf4) + *(int *)(param_1 + 0xd8)) * 2 + 2);
      uVar3 = *(int *)(param_1 + 0xf4) + *(int *)(param_1 + 0xd8);
      puVar5 = *(undefined4 **)(param_1 + 0x1244);
      puVar7 = puVar2;
      for (uVar4 = (uVar3 & 0x7fffffff) >> 1; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
      for (uVar3 = uVar3 * 2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar7 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
      *(undefined2 *)((int)puVar2 + (*(int *)(param_1 + 0xf4) + *(int *)(param_1 + 0xd8)) * 2) = 0;
      uStack_1c = FUN_0073f550(puVar2,0,0);
      iVar6 = unaff_EBX;
    }
    else {
      uStack_1c = *(undefined4 *)(param_1 + 0x145c);
    }
    iStack_18 = *(byte *)(param_1 + 0x1478) + 1;
    FUN_00741db0(aiStack_2c,0);
    iStack_24 = iStack_24 + unaff_EBP;
    iStack_20 = iStack_20 + unaff_EBX;
    func_0x007ee4a2(iVar1,aiStack_2c);
    func_0x007ee484(iVar6,iVar1);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0073fec0 | Classified: AngelicaUI::proc_73fec0 */
/* ==================================================================== */

void __fastcall FUN_0073fec0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 8) + 4);
  iVar2 = func_0x007ee490(uVar1);
  if (iVar2 != 0) {
    FUN_00741db0(&stack0xffffffd8,0);
    func_0x007ee4a8(iVar2,&stack0xffffffd8);
    func_0x007ee484(uVar1,iVar2);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0073ff60 | Classified: AngelicaUI::proc_73ff60 */
/* ==================================================================== */

void __fastcall FUN_0073ff60(int param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int unaff_ESI;
  int iVar5;
  int unaff_EDI;
  undefined1 auStack_8 [8];
  
  if ((0 < *(int *)(param_1 + 0x1458)) && (*(char *)(param_1 + 0x45) != '\0')) {
    cVar2 = FUN_00737ff0();
    if (cVar2 != '\0') {
      iVar3 = GetTickCount();
      if (499 < (uint)(iVar3 - *(int *)(param_1 + 0x1450))) {
        *(int *)(param_1 + 0x1450) = iVar3;
        *(bool *)(param_1 + 0x1454) = *(char *)(param_1 + 0x1454) == '\0';
      }
      if (*(char *)(param_1 + 0x1454) != '\0') {
        FUN_00741db0(auStack_8,0);
        bVar1 = *(byte *)(param_1 + 0x1478);
        uVar4 = (uint)bVar1;
        if (bVar1 == 0) {
          uVar4 = 0xc;
        }
        iVar3 = *(int *)(param_1 + 0x1460) + *(int *)(param_1 + 100);
        iVar5 = unaff_EDI + *(int *)(param_1 + 0x145c) + *(int *)(param_1 + 0x60);
        func_0x00778b70(iVar5,iVar3 + unaff_ESI + (uint)(bVar1 >> 3),iVar5 + 1,
                        (iVar3 - (uint)(bVar1 >> 3)) + uVar4 + unaff_ESI,0xffffffff,0);
      }
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00740050 | Classified: AngelicaUI::proc_740050 */
/* ==================================================================== */

void __thiscall FUN_00740050(int param_1,int param_2,int param_3)

{
  int unaff_EBX;
  int unaff_EBP;
  undefined1 auStack_8 [8];
  
  *(int *)(param_1 + 0x145c) = param_2;
  *(int *)(param_1 + 0x1460) = param_3;
  FUN_00741db0(auStack_8,0);
  SetCaretPos(unaff_EBP + *(int *)(param_1 + 0xac) + *(int *)(param_1 + 0x60) + param_2,
              (uint)*(byte *)(param_1 + 0x1478) +
              unaff_EBX + *(int *)(param_1 + 0xb0) + *(int *)(param_1 + 100) + param_3);
  return;
}


/* ==================================================================== */
/* Address: 0x007400d0 | Classified: AngelicaUI::proc_7400d0 */
/* ==================================================================== */

void FUN_007400d0(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (0 < param_3) {
    iVar1 = param_1 + 3;
    do {
      if (param_3 < 7) {
        if (2 < param_3) {
          param_3 = 3;
        }
        func_0x00778b70(param_1,param_2,param_3 + param_1,param_2 + 1,0xff00ff00,0);
        return;
      }
      func_0x00778b70(param_1,param_2,iVar1,param_2 + 1,0xff00ff00,0);
      param_3 = param_3 + -6;
      param_1 = param_1 + 6;
      iVar1 = iVar1 + 6;
    } while (0 < param_3);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00740150 | Classified: AUIEditBox::vfunc_slot_14 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00740150(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((char)param_2 != *(char *)(param_1 + 0x45)) {
    FUN_00742500(param_2);
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 8) + 4);
    if ((char)param_2 != '\0') {
      uVar1 = GetKeyboardLayout(_DAT_009c1578);
      FUN_0073fc30(uVar1);
      FUN_0073f410(0);
      *(int *)(param_1 + 0x1458) = *(int *)(param_1 + 0x1458) + 1;
      if ((*(char *)(param_1 + 0xa6) == '\0') && (*(char *)(param_1 + 0xa4) == '\0')) {
        DAT_009812c0 = 1;
        return;
      }
      DAT_009812c0 = 0;
      return;
    }
    iVar2 = GetCurrentThreadId();
    if ((((_DAT_009c1578 == iVar2) && (*(int *)(param_1 + 0x100) != 0)) &&
        (*(int *)(param_1 + 0xc4) != 3)) && (iVar2 = func_0x007ee490(uVar1), iVar2 != 0)) {
      func_0x007ee4ae(iVar2,0x15,1,0);
      func_0x007ee484(uVar1,iVar2);
    }
    *(undefined4 *)(param_1 + 0x100) = 0;
    if (DAT_009c1570 != '\0') {
      iVar2 = 0;
      if (0 < *(int *)(param_1 + 0x238)) {
        puVar3 = (undefined4 *)(param_1 + 0x210);
        do {
          func_0x00763260(*puVar3);
          iVar2 = iVar2 + 1;
          puVar3 = puVar3 + 1;
        } while (iVar2 < *(int *)(param_1 + 0x238));
      }
      *(undefined4 *)(param_1 + 0x238) = 0;
      func_0x00763260(*(undefined4 *)(param_1 + 0x20c));
      *(undefined4 *)(param_1 + 0x20c) = 0;
      *(undefined4 *)(param_1 + 0x23c) = 0;
      *(undefined4 *)(param_1 + 0x240) = 0;
    }
    *(int *)(param_1 + 0x1458) = *(int *)(param_1 + 0x1458) + -1;
    DAT_009812c0 = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007402a0 | Classified: AngelicaUI::proc_7402a0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_007402a0(int *param_1,uint param_2)

{
  ushort uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  short *psVar8;
  undefined2 *puVar9;
  ushort *puVar10;
  int *piVar11;
  int iVar12;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_44 [4];
  undefined1 auStack_40 [4];
  undefined4 uStack_3c;
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [8];
  undefined1 auStack_28 [4];
  int iStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ca4c8;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_2 == 8) {
    iVar6 = param_1[0x36];
    if ((iVar6 != 0) && (iVar6 <= param_1[0x35])) {
      if (((char)param_1[0x2a] == '\0') ||
         (psVar8 = (short *)FUN_007655e0(iVar6 + -1), *psVar8 != 10)) {
        iVar6 = FUN_0073fd30(param_1[0x36] + -1);
      }
      else {
        iVar6 = FUN_0073fd30(param_1[0x36] + -3);
        iVar6 = iVar6 + 2;
      }
      puVar10 = (ushort *)FUN_007655e0(param_1[0x36] + -1);
      if ((0xdfff < *puVar10) && (*puVar10 < 0xe400)) {
        puVar10 = (ushort *)FUN_007655e0(param_1[0x36] + -1);
        if (param_1[*puVar10 - 0xdade] != 0) {
          piVar11 = (int *)func_0x0073a740(auStack_28);
          param_1[0x27] = param_1[0x27] + *(int *)(*piVar11 + -8);
          FUN_00765200();
        }
        puVar10 = (ushort *)FUN_007655e0(param_1[0x36] + -1);
        uVar1 = *puVar10;
        puVar2 = (undefined4 *)param_1[uVar1 - 0xdade];
        if (puVar2 != (undefined4 *)0x0) {
          param_1[puVar2[1] + 0x922] = param_1[puVar2[1] + 0x922] + -1;
          param_1[0x926] = param_1[0x926] + -1;
          (**(code **)*puVar2)(1);
          param_1[uVar1 - 0xdade] = 0;
        }
      }
      uVar4 = func_0x004cb7b0(&uStack_18,param_1[0x35] - param_1[0x36]);
      uStack_14 = 4;
      uVar5 = func_0x004cb780(&iStack_24,param_1[0x36] - iVar6);
      iStack_1c._0_1_ = 5;
      uVar4 = func_0x00403ba0(auStack_30,uVar5,uVar4);
      iStack_1c = CONCAT31(iStack_1c._1_3_,6);
      FUN_007652d0(uVar4);
      uStack_20._0_1_ = 5;
      FUN_00765200();
      uStack_20 = CONCAT31(uStack_20._1_3_,4);
      FUN_00765200();
      uStack_20 = 0xffffffff;
      FUN_00765200();
      param_1[0x35] = param_1[0x35] - iVar6;
      param_1[0x36] = param_1[0x36] - iVar6;
      iVar6 = param_1[0x37] - iVar6;
LAB_007407bd:
      param_1[0x37] = iVar6;
    }
  }
  else if (param_2 == 0x16) {
    iVar6 = OpenClipboard(*(undefined4 *)(param_1[2] + 4));
    if (iVar6 != 0) {
      iStack_24 = (*_DAT_009b3b94)(0xd);
      if (iStack_24 != 0) {
        iVar6 = GlobalLock(iStack_24);
        iVar7 = wcslen(iVar6);
        if ((iVar6 != 0) &&
           ((param_1[0x27] < 0 || (*(int *)(param_1[0x491] + -8) + iVar7 <= param_1[0x27])))) {
          iVar7 = *(int *)(param_1[0x491] + -8) - param_1[0x36];
          uVar4 = func_0x004cb7b0(auStack_28);
          uStack_10 = 0;
          uVar5 = func_0x004cb780(auStack_34,param_1[0x36]);
          uStack_18._0_1_ = 1;
          uVar5 = func_0x004bcb50(auStack_40,uVar5,iVar6);
          uStack_18._0_1_ = 2;
          uVar4 = func_0x00403ba0(auStack_44,uVar5,uVar4);
          uStack_18 = CONCAT31(uStack_18._1_3_,3);
          FUN_007652d0(uVar4);
          iStack_1c._0_1_ = 2;
          FUN_00765200();
          iStack_1c._0_1_ = 1;
          FUN_00765200();
          iStack_1c = (uint)iStack_1c._1_3_ << 8;
          FUN_00765200();
          iStack_1c = 0xffffffff;
          FUN_00765200();
          if ((*(char *)((int)param_1 + 0xa7) == '\0') &&
             (iVar12 = param_1[0x36], iVar12 < iVar7 + iVar12)) {
            do {
              psVar8 = (short *)FUN_007655e0(iVar12);
              if ((*psVar8 == 0xd) || (psVar8 = (short *)FUN_007655e0(iVar12), *psVar8 == 10)) {
                puVar9 = (undefined2 *)FUN_007655e0(iVar12);
                *puVar9 = 0x20;
              }
              iVar12 = iVar12 + 1;
            } while (iVar12 < iVar7 + param_1[0x36]);
          }
          iVar7 = wcslen(iVar6);
          param_1[0x35] = param_1[0x35] + iVar7;
          iVar7 = wcslen(iVar6);
          param_1[0x36] = param_1[0x36] + iVar7;
          iVar6 = wcslen(iVar6);
          param_1[0x37] = param_1[0x37] + iVar6;
          FUN_007652d0(param_1 + 0x491);
          GlobalUnlock(uStack_3c);
        }
      }
      CloseClipboard();
    }
  }
  else {
    if (param_2 == 0xd) {
      if (*(char *)((int)param_1 + 0xa7) == '\0') goto LAB_007407d3;
    }
    else if (param_2 < 0x20) goto LAB_007407c3;
    if (((char)param_1[0x29] == '\0') || ((0x2f < param_2 && (param_2 < 0x3a)))) {
      uVar3 = wcslen(param_1[0x491]);
      if ((uint)param_1[0x27] <= uVar3) goto LAB_007407d3;
      if (0xff < param_1[0x35]) {
        FUN_0073fd80();
      }
      uVar4 = func_0x004cb7b0(auStack_34,*(int *)(param_1[0x491] + -8) - param_1[0x36]);
      uStack_c = 7;
      uVar5 = func_0x004cb780(auStack_40,param_1[0x36]);
      uStack_14._0_1_ = 8;
      uVar5 = func_0x004bcb50(&stack0xffffffb4,uVar5,&uStack_c);
      uStack_14._0_1_ = 9;
      uVar4 = func_0x00403ba0(&stack0xffffffb0,uVar5,uVar4);
      uStack_14 = CONCAT31(uStack_14._1_3_,10);
      FUN_007652d0(uVar4);
      uStack_18._0_1_ = 9;
      FUN_00765200();
      uStack_18._0_1_ = 8;
      FUN_00765200();
      uStack_18 = CONCAT31(uStack_18._1_3_,7);
      FUN_00765200();
      uStack_18 = 0xffffffff;
      FUN_00765200();
      param_1[0x35] = param_1[0x35] + 1;
      param_1[0x36] = param_1[0x36] + 1;
      iVar6 = param_1[0x37] + 1;
      goto LAB_007407bd;
    }
  }
LAB_007407c3:
  (**(code **)(*param_1 + 0x3c))();
  FUN_0073f410(0);
LAB_007407d3:
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x007407f0 | Classified: AngelicaUI::proc_7407f0 */
/* ==================================================================== */

void __thiscall FUN_007407f0(int *param_1,int param_2)

{
  if (DAT_009c1570 != '\0') {
    func_0x0075f980(param_1 + 0x82,0);
  }
  if (((param_1[0x3f] & 0x10000U) != 0) || (param_1[0x40] == 0)) {
    (**(code **)(*param_1 + 0x44))(param_2);
    if (param_2 == 0xd) {
      FUN_007373f0(param_1[6]);
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00741200 | Classified: AngelicaUI::proc_741200 */
/* ==================================================================== */

void __thiscall FUN_00741200(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x9c) = param_2;
  *(undefined4 *)(param_1 + 0xa0) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00741220 | Classified: AngelicaUI::proc_741220 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00741220(int param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *piVar9;
  int iVar10;
  uint uVar11;
  int unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  int *piStack_88;
  undefined4 uStack_84;
  undefined1 *puStack_80;
  undefined4 uStack_7c;
  undefined1 *puStack_78;
  uint uStack_74;
  int iStack_70;
  int iStack_6c;
  int iStack_68;
  int iStack_64;
  int *piStack_60;
  int iStack_5c;
  int iVar12;
  int iStack_44;
  int iStack_40;
  int *piStack_3c;
  int iStack_38;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ca520;
  *unaff_FS_OFFSET = &uStack_c;
  if ((*(int *)(param_1 + 0x20c) != 0) || (*(int *)(param_1 + 0x238) != 0)) {
    iStack_5c = 0x74125e;
    func_0x00784480();
    iStack_5c = 0x741266;
    func_0x00868610();
    iStack_5c = 0x74126d;
    FUN_007310f0();
    iStack_5c = 0x741274;
    func_0x0075ec80();
    iStack_5c = 0x74127c;
    func_0x00868610();
    iStack_5c = 0x741283;
    iVar2 = FUN_007537e0();
    piStack_60 = &iStack_44;
    iStack_64 = 0x9814a8;
    iStack_68 = 0x741297;
    iStack_5c = iVar2;
    FUN_0073f550();
    iStack_70 = *(int *)(param_1 + 0x20c);
    iStack_44 = ((iStack_70 != 0) + 1 + *(int *)(param_1 + 0x238)) * (unaff_EDI + 4);
    if (iStack_70 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      iStack_6c = 0;
      uStack_74 = 0x7412cd;
      iStack_68 = iVar2;
      piVar3 = (int *)FUN_0073f550();
    }
    iStack_6c = 0;
    iStack_70 = 0x9810c0;
    uStack_74 = 0x7412e9;
    iStack_68 = iVar2;
    piVar4 = (int *)FUN_0073f550();
    piVar9 = piVar3;
    if ((int)piVar3 < (int)piVar4) {
      piVar9 = piVar4;
      piStack_60 = piVar4;
    }
    iVar12 = 0;
    if (0 < *(int *)(param_1 + 0x238)) {
      puVar8 = (undefined4 *)(param_1 + 0x210);
      do {
        uStack_7c = *puVar8;
        puStack_78 = (undefined1 *)0x0;
        puStack_80 = (undefined1 *)0x741315;
        uStack_74 = iVar2;
        iVar5 = FUN_0073f550();
        piVar4 = (int *)(iVar5 + (int)piVar3);
        if ((int)piVar9 < (int)piVar4) {
          piVar9 = piVar4;
          piStack_60 = piVar4;
        }
        iVar12 = iVar12 + 1;
        puVar8 = puVar8 + 1;
      } while (iVar12 < *(int *)(param_1 + 0x238));
    }
    puStack_78 = &stack0xffffffb4;
    uStack_74 = 0;
    uStack_7c = 0x741347;
    FUN_00741db0();
    iVar5 = (int)piVar3 + *(int *)(param_1 + 0x145c) + *(int *)(param_1 + 0x60);
    if (*(int *)(param_1 + 0x68) + *(int *)(param_1 + 0x60) < (int)piVar9 + iVar5) {
      iVar5 = iVar5 - (int)piVar9;
    }
    iVar10 = *(int *)(param_1 + 0x1460) + unaff_EDI + *(int *)(param_1 + 100) + 4 + iStack_64;
    if (*(int *)(param_1 + 0x6c) + *(int *)(param_1 + 100) < iVar10 + iVar12) {
      iVar10 = iVar10 - (iVar12 + iStack_64);
    }
    iStack_40 = iVar12 + iVar10;
    puStack_80 = &stack0xffffffb4;
    iStack_44 = iStack_68 + 5 + iVar5;
    uStack_7c = 0xc4000000;
    uStack_84 = 0x7413d7;
    func_0x007b7920();
    uStack_84 = 0xc4000080;
    iStack_38 = iVar10 + iStack_6c;
    piStack_88 = &iStack_44;
    piStack_3c = piStack_60;
    uStack_8c = 0x741407;
    iStack_44 = iVar5;
    iStack_40 = iVar10;
    func_0x007b7920();
    uStack_8c = 0xffffffff;
    uStack_90 = 0;
    iVar12 = -0x1000000;
    iVar5 = iVar5 + 4;
    iStack_68 = iVar5;
    func_0x0073bab0(iVar5,iVar10,0x9810c0,0xffffffff,0,0xff000000);
    iVar10 = iVar10 + iVar12;
    if (*(int *)(param_1 + 0x20c) == 0) {
      iVar10 = iVar10 + (-4 - iVar12);
    }
    else {
      func_0x0073bab0(iVar5,iVar10,*(int *)(param_1 + 0x20c),0xffffffff,0,0xff000000,0,0xffffffff);
    }
    if (0 < *(int *)(param_1 + 0x238)) {
      puVar8 = (undefined4 *)(param_1 + 0x210);
      uVar11 = 1;
      do {
        iVar10 = iVar10 + 4 + iVar12;
        uStack_90 = _DAT_00985a98;
        uVar6 = FUN_00765690(&uStack_90,0x9814a0,(9 < (int)uVar11) - 1 & uVar11,*puVar8);
        puVar7 = (undefined4 *)func_0x004bcb50(&uStack_8c,uVar6);
        func_0x0073bab0(piStack_88,iVar10,*puVar7,0xffffffff,0,0xff000000,0,0xffffffff);
        uStack_74 = uStack_74 & 0xffffff00;
        FUN_00765200();
        uStack_74 = 0xffffffff;
        FUN_00765200();
        puVar8 = puVar8 + 1;
        bVar1 = (int)uVar11 < *(int *)(param_1 + 0x238);
        uVar11 = uVar11 + 1;
      } while (bVar1);
    }
    EnterCriticalSection(iVar2 + 0x148);
    uVar11 = 0;
    if (*(int *)(iVar2 + 0x34) != 0) {
      do {
        func_0x0073c8b0(*(undefined4 *)(*(int *)(iVar2 + 0x28) + uVar11 * 4));
        uVar11 = uVar11 + 1;
      } while (uVar11 < *(uint *)(iVar2 + 0x34));
    }
    LeaveCriticalSection(iVar2 + 0x148);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x00741570 | Classified: AngelicaUI::proc_741570 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00741570(undefined4 param_1)

{
  _DAT_009c1574 = param_1;
  _DAT_009c1578 = GetWindowThreadProcessId(param_1,0);
  return;
}


/* ==================================================================== */
/* Address: 0x00741590 | Classified: AngelicaUI::proc_741590 */
/* ==================================================================== */

undefined1 __fastcall FUN_00741590(int param_1)

{
  return *(undefined1 *)(param_1 + 0xa4);
}


/* ==================================================================== */
/* Address: 0x007415a0 | Classified: AngelicaUI::proc_7415a0 */
/* ==================================================================== */

void __thiscall FUN_007415a0(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0xa4) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x007415b0 | Classified: AngelicaUI::proc_7415b0 */
/* ==================================================================== */

undefined4 FUN_007415b0(void)

{
  return 0x9810c0;
}


/* ==================================================================== */
/* Address: 0x007415c0 | Classified: AngelicaUI::proc_7415c0 */
/* ==================================================================== */

bool FUN_007415c0(void)

{
  int iVar1;
  
  iVar1 = wcscmp(0x9810c0,0x981484);
  return iVar1 == 0;
}


/* ==================================================================== */
/* Address: 0x007415e0 | Classified: AngelicaUI::proc_7415e0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007415e0(void)

{
  int iVar1;
  
  if (DAT_009812c0 != DAT_009812c1) {
    DAT_009812c1 = DAT_009812c0;
    iVar1 = func_0x007ee490(_DAT_009c1574);
    if (DAT_009812c0 == '\0') {
      if (iVar1 == 0) {
        return;
      }
      _DAT_009c157c = iVar1;
      func_0x007ee4b4(_DAT_009c1574,0);
    }
    else if (iVar1 == 0) {
      if (_DAT_009c157c == 0) {
        return;
      }
      func_0x007ee4b4(_DAT_009c1574,_DAT_009c157c);
      return;
    }
    func_0x007ee484(_DAT_009c1574,iVar1);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00741660 | Classified: AngelicaUI::proc_741660 */
/* ==================================================================== */

void __thiscall FUN_00741660(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x147c) = param_2;
  *(undefined4 *)(param_1 + 0x1480) = param_3;
  return;
}


/* ==================================================================== */
/* Address: 0x00741680 | Classified: AngelicaUI::proc_741680 */
/* ==================================================================== */

undefined4 __thiscall
FUN_00741680(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  ushort uVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *unaff_FS_OFFSET;
  uint uStack_1c;
  int *piStack_18;
  undefined1 uStack_14;
  undefined1 auStack_10 [4];
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ca550;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_1c = *(uint *)(param_1[0x491] + -8);
  if ((int)uStack_1c < param_1[0x27]) {
    piStack_18 = param_1 + 0x522;
    uVar3 = func_0x0073a640(param_2,param_3,param_4);
    if (uVar3 == 0) {
      uVar5 = 0;
    }
    else {
      piVar4 = (int *)func_0x0073a740(&param_4);
      iVar1 = *(int *)(*piVar4 + -8);
      FUN_00765200();
      piVar4 = piStack_18;
      if ((int)(iVar1 + uStack_1c) < param_1[0x27]) {
        param_1[0x27] = param_1[0x27] - iVar1;
        uVar5 = func_0x004cb7b0(auStack_10,*(int *)(param_1[0x491] + -8) - param_1[0x36]);
        uStack_c = 0;
        uVar6 = func_0x004cb780(&uStack_1c,param_1[0x36]);
        uStack_14 = 1;
        uVar6 = FUN_00741870(&stack0xffffffd4,uVar6,puStack_8);
        uStack_14 = 2;
        uVar5 = func_0x00403ba0(&uStack_c,uVar6,uVar5);
        uStack_14 = 3;
        FUN_007652d0(uVar5);
        piStack_18._0_1_ = 2;
        FUN_00765200();
        piStack_18._0_1_ = 1;
        FUN_00765200();
        piStack_18 = (int *)((uint)piStack_18._1_3_ << 8);
        FUN_00765200();
        piStack_18 = (int *)0xffffffff;
        FUN_00765200();
        param_1[0x36] = param_1[0x36] + 1;
        param_1[0x37] = param_1[0x37] + 1;
        param_1[0x35] = param_1[0x35] + 1;
        (**(code **)(*param_1 + 0x3c))();
        FUN_0073f410(0);
        uVar5 = 1;
      }
      else {
        puVar2 = (undefined4 *)piStack_18[uVar3 - 0xe000];
        if (puVar2 != (undefined4 *)0x0) {
          piStack_18[puVar2[1] + 0x400] = piStack_18[puVar2[1] + 0x400] + -1;
          piStack_18[0x404] = piStack_18[0x404] + -1;
          (**(code **)*puVar2)(1);
          piVar4[uVar3 - 0xe000] = 0;
        }
        uVar5 = 0;
      }
    }
  }
  else {
    uVar5 = 0;
  }
  *unaff_FS_OFFSET = uStack_c;
  return uVar5;
}


/* ==================================================================== */
/* Address: 0x00741870 | Classified: AngelicaUI::proc_741870 */
/* ==================================================================== */

undefined4 FUN_00741870(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00765150(param_2,param_3);
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007418a0 | Classified: AngelicaUI::proc_7418a0 */
/* ==================================================================== */

void __fastcall FUN_007418a0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  *param_1 = &UNK_008eec68;
  if (0 < (int)param_1[0xc]) {
    puVar1 = param_1 + 2;
    do {
      func_0x00763260(*puVar1);
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar2 < (int)param_1[0xc]);
  }
  param_1[0xc] = 0;
  func_0x00763260(param_1[1]);
  param_1[1] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00741960 | Classified: elementclient::Control__d@0x741960 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_00741960(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_94 [4];
  undefined4 *puStack_90;
  undefined4 uStack_28;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008ca5d6;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1[5] = _DAT_009858e4;
  param_1[6] = _DAT_009858e4;
  param_1[7] = _DAT_009858e4;
  param_1[8] = _DAT_00985a98;
  param_1[0x1d] = _DAT_00985a98;
  param_1[0x1e] = _DAT_00985a98;
  param_1[0x25] = _DAT_009858e4;
  param_1[0x26] = _DAT_009858e4;
  *param_1 = &UNK_008eece0;
  param_1[0xf] = 0;
  *(undefined1 *)(param_1 + 0x11) = 1;
  *(undefined1 *)((int)param_1 + 0x45) = 0;
  *(undefined1 *)((int)param_1 + 0x46) = 1;
  uStack_4 = 7;
  *(undefined1 *)((int)param_1 + 0x47) = 0;
  *(undefined1 *)(param_1 + 0x12) = 1;
  *(undefined1 *)((int)param_1 + 0x49) = 0;
  param_1[0x10] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x16] = 0x28;
  param_1[0x17] = 0x28;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  param_1[4] = 0;
  puStack_90 = param_1;
  func_0x007638a0(&DAT_009b3c44);
  func_0x007638a0(&DAT_009b3c44);
  iVar1 = rand();
  iVar2 = rand();
  sprintf(auStack_94,0x9814b0,iVar1 * iVar2);
  func_0x007638a0(auStack_94);
  uVar3 = GetTickCount();
  param_1[0x1f] = uVar3;
  param_1[0x13] = uVar3;
  *(undefined1 *)(param_1 + 0x20) = 0;
  *(undefined1 *)((int)param_1 + 0x81) = 0;
  FUN_00765230(0x9b3c40);
  FUN_00765230(0x9b3c40);
  param_1[9] = 0xf;
  param_1[10] = 0;
  param_1[0xb] = 0;
  *(undefined1 *)(param_1 + 0xc) = 0;
  *(undefined1 *)((int)param_1 + 0x31) = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0xffffffff;
  param_1[0x1c] = 1;
  param_1[0x21] = 0xff;
  param_1[0x22] = 0xff;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  func_0x007638a0(&DAT_009b3c44);
  func_0x007638a0(&DAT_009b3c44);
  *unaff_FS_OFFSET = uStack_28;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00741b30 | Classified: AUIObject::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_00741b30(undefined4 param_1,byte param_2)

{
  FUN_00741b50();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00741b50 | Classified: AngelicaUI::proc_741b50 */
/* ==================================================================== */

void __fastcall FUN_00741b50(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  puStack_8 = &UNK_008ca630;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008eece0;
  iStack_4 = 6;
  func_0x007637f0();
  iStack_4._0_1_ = 5;
  func_0x007637f0();
  iStack_4._0_1_ = 4;
  FUN_00765200();
  iStack_4._0_1_ = 3;
  FUN_00765200();
  iStack_4._0_1_ = 2;
  FUN_00765200();
  iStack_4._0_1_ = 1;
  func_0x007637f0();
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  func_0x007637f0();
  iStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x00741c00 | Classified: AUIObject::vfunc_slot_1 */
/* ==================================================================== */

uint __thiscall FUN_00741c00(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint unaff_EBX;
  char *pcVar4;
  undefined1 auStack_808 [3];
  undefined1 uStack_805;
  
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_3;
  if (param_4 == 0) {
    return 1;
  }
  uStack_805 = 0;
  cVar1 = func_0x0076f4a0(1);
  if (cVar1 == '\0') {
    uVar2 = 0x5f;
    goto LAB_00741d83;
  }
  param_4 = param_4 + 4;
  func_0x007638a0(param_4);
  iVar3 = -1;
  pcVar4 = *(char **)(param_1 + 0x14);
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if (iVar3 == -2) {
LAB_00741c7c:
    unaff_EBX = rand();
    iVar3 = rand();
    sprintf(auStack_808,0x9814e8,unaff_EBX * iVar3);
    func_0x007638a0(auStack_808);
  }
  else {
    iVar3 = _strcmpi(*(char **)(param_1 + 0x14),0x97f9d8);
    if (iVar3 == 0) goto LAB_00741c7c;
  }
  cVar1 = func_0x0076f4a0(1);
  if (cVar1 == '\0') {
    uVar2 = 0x69;
  }
  else {
    FUN_00742600(param_4);
    cVar1 = func_0x0076f4a0(1);
    if (cVar1 == '\0') {
      uVar2 = 0x6c;
    }
    else {
      func_0x007638a0(param_4);
      cVar1 = func_0x0076f4a0(1);
      if (cVar1 == '\0') {
        uVar2 = 0x6f;
      }
      else {
        uVar2 = atoi(param_4);
        *(undefined4 *)(param_1 + 0x50) = uVar2;
        cVar1 = func_0x0076f4a0(1);
        if (cVar1 == '\0') {
          uVar2 = 0x72;
        }
        else {
          uVar2 = atoi(param_4);
          *(undefined4 *)(param_1 + 0x54) = uVar2;
          cVar1 = func_0x0076f4a0(1);
          if (cVar1 == '\0') {
            uVar2 = 0x75;
          }
          else {
            uVar2 = atoi(param_4);
            *(undefined4 *)(param_1 + 0x58) = uVar2;
            cVar1 = func_0x0076f4a0(1);
            if (cVar1 != '\0') {
              uVar2 = atoi(param_4);
              *(undefined4 *)(param_1 + 0x5c) = uVar2;
              return 1;
            }
            uVar2 = 0x78;
          }
        }
      }
    }
  }
LAB_00741d83:
  func_0x00739700(uVar2,1,0x9814bc);
  return unaff_EBX >> 0x18;
}


/* ==================================================================== */
/* Address: 0x00741db0 | Classified: AngelicaUI::proc_741db0 */
/* ==================================================================== */

void __thiscall FUN_00741db0(int param_1,int *param_2,char param_3)

{
  int iVar1;
  int iVar2;
  int iStack_8;
  int iStack_4;
  
  iVar1 = *(int *)(param_1 + 0x50);
  iVar2 = *(int *)(param_1 + 0x54);
  if (param_3 == '\0') {
    FUN_007354d0(&iStack_8);
    iVar1 = iVar1 + iStack_8;
    iVar2 = iVar2 + iStack_4;
  }
  *param_2 = iVar1;
  param_2[1] = iVar2;
  return;
}


/* ==================================================================== */
/* Address: 0x00741df0 | Classified: AngelicaUI::proc_741df0 */
/* ==================================================================== */

void __thiscall FUN_00741df0(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x50) = param_2;
  *(undefined4 *)(param_1 + 0x54) = param_3;
  return;
}


/* ==================================================================== */
/* Address: 0x00741e10 | Classified: AngelicaUI::proc_741e10 */
/* ==================================================================== */

void __thiscall FUN_00741e10(int param_1,undefined4 param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  char cVar7;
  byte *pbVar8;
  undefined4 *puStack_8;
  uint uStack_4;
  
  uStack_4 = 0;
  pbVar8 = *(byte **)(param_1 + 0x14);
  iVar3 = *(int *)(param_1 + 0xc);
  bVar2 = *pbVar8;
  while (bVar2 != 0) {
    uStack_4 = uStack_4 * 0x1f + (uint)bVar2;
    pbVar1 = pbVar8 + 1;
    pbVar8 = pbVar8 + 1;
    bVar2 = *pbVar1;
  }
  puStack_8 = (undefined4 *)0x0;
  uStack_4 = uStack_4 % *(uint *)(iVar3 + 0x140);
  puVar4 = *(undefined4 **)(*(int *)(iVar3 + 0x134) + uStack_4 * 4);
  puVar6 = puVar4;
  do {
    puVar5 = puVar6;
    if (puVar5 == (undefined4 *)0x0) {
LAB_00741eb0:
      func_0x007638a0(param_2);
      FUN_007428f0(*(int *)(*(int *)(param_1 + 0xc) + 0x130) + 1);
      FUN_00742a50(param_1 + 0x14,&uStack_4);
      return;
    }
    cVar7 = func_0x00763c50(param_1 + 0x14);
    if (cVar7 != '\0') {
      if (puVar5 == puVar4) {
        *(undefined4 *)(*(int *)(iVar3 + 0x134) + uStack_4 * 4) = *puVar5;
      }
      else {
        *puStack_8 = *puVar5;
      }
      func_0x007394a0();
      func_0x00763260(puVar5);
      *(int *)(iVar3 + 0x130) = *(int *)(iVar3 + 0x130) + -1;
      goto LAB_00741eb0;
    }
    puVar6 = (undefined4 *)*puVar5;
    puStack_8 = puVar5;
  } while( true );
}


/* ==================================================================== */
/* Address: 0x00741ef0 | Classified: AngelicaUI::proc_741ef0 */
/* ==================================================================== */

void __thiscall FUN_00741ef0(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x44) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00741f00 | Classified: AngelicaUI::proc_741f00 */
/* ==================================================================== */

undefined1 __fastcall FUN_00741f00(int param_1)

{
  return *(undefined1 *)(param_1 + 0x44);
}


/* ==================================================================== */
/* Address: 0x00741f10 | Classified: AngelicaUI::proc_741f10 */
/* ==================================================================== */

undefined4 __fastcall FUN_00741f10(int param_1)

{
  return *(undefined4 *)(param_1 + 0x40);
}


/* ==================================================================== */
/* Address: 0x00741f20 | Classified: AngelicaUI::proc_741f20 */
/* ==================================================================== */

void __thiscall FUN_00741f20(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x40) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00741f30 | Classified: AngelicaUI::proc_741f30 */
/* ==================================================================== */

undefined1 __fastcall FUN_00741f30(int param_1)

{
  return *(undefined1 *)(param_1 + 0x46);
}


/* ==================================================================== */
/* Address: 0x00741f40 | Classified: AngelicaUI::proc_741f40 */
/* ==================================================================== */

void __thiscall FUN_00741f40(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x46) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00741f50 | Classified: AngelicaUI::proc_741f50 */
/* ==================================================================== */

undefined4 __fastcall FUN_00741f50(int param_1)

{
  return *(undefined4 *)(param_1 + 0x3c);
}


/* ==================================================================== */
/* Address: 0x00741f60 | Classified: AUIObject::vfunc_slot_4 */
/* ==================================================================== */

undefined4 __thiscall FUN_00741f60(int param_1,undefined4 param_2)

{
  fprintf(param_2,0x9814f4,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),
          *(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x50),
          *(undefined4 *)(param_1 + 0x54),*(undefined4 *)(param_1 + 0x58),
          *(undefined4 *)(param_1 + 0x5c));
  return 1;
}


/* ==================================================================== */
/* Address: 0x00741fa0 | Classified: AUIObject::vfunc_slot_5 */
/* ==================================================================== */

undefined4 __fastcall FUN_00741fa0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = GetTickCount();
  if ((*(char *)(param_1 + 0x81) != '\0') && (499 < iVar1 - *(int *)(param_1 + 0x7c))) {
    *(int *)(param_1 + 0x7c) = iVar1;
    *(bool *)(param_1 + 0x80) = *(char *)(param_1 + 0x80) == '\0';
  }
  if ((*(char *)(param_1 + 0x49) != '\0') && (499 < iVar1 - *(int *)(param_1 + 0x4c))) {
    iVar2 = *(int *)(param_1 + 0x88);
    if (*(int *)(param_1 + 0x84) == iVar2) {
      if (0x9f < iVar2) {
        *(int *)(param_1 + 0x4c) = iVar1;
        *(int *)(param_1 + 0x84) = iVar2 + -0x60;
        return 1;
      }
      iVar2 = iVar2 + 0x60;
    }
    *(int *)(param_1 + 0x84) = iVar2;
    *(int *)(param_1 + 0x4c) = iVar1;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00742030 | Classified: AngelicaUI::proc_742030 */
/* ==================================================================== */

void __thiscall FUN_00742030(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x5c);
  *param_2 = *(undefined4 *)(param_1 + 0x58);
  param_2[1] = uVar1;
  return;
}


/* ==================================================================== */
/* Address: 0x00742050 | Classified: elementclient::Width@0x742050 */
/* ==================================================================== */

void FUN_00742050(void)

{
  int *extraout_ECX;
  
  func_0x00892f20();
  (**(code **)(*extraout_ECX + 0x28))(0x980c54);
  (**(code **)(*extraout_ECX + 0x28))(0x980c4c,&stack0xfffffff8);
  return;
}


/* ==================================================================== */
/* Address: 0x007420a0 | Classified: AUITextArea::vfunc_slot_8 */
/* ==================================================================== */

void __fastcall FUN_007420a0(int param_1)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  int unaff_EDI;
  undefined1 auStack_8 [4];
  int *piStack_4;
  
  FUN_00741db0(auStack_8,0);
  iVar1 = *(int *)(param_1 + 0x58);
  iVar2 = *(int *)(param_1 + 0x5c);
  piStack_4[1] = unaff_ESI;
  piStack_4[3] = iVar2 + unaff_ESI;
  *piStack_4 = unaff_EDI;
  piStack_4[2] = iVar1 + unaff_EDI;
  return;
}


/* ==================================================================== */
/* Address: 0x007420e0 | Classified: AUIObject::vfunc_slot_9 */
/* ==================================================================== */

undefined4 __thiscall FUN_007420e0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = _strcmpi(param_2,0x95b2b4);
  if (iVar1 == 0) {
    strncpy(param_3,*(undefined4 *)(param_1 + 0x14),0x7ff);
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x981044);
  if (iVar1 == 0) {
    strncpy(param_3,*(undefined4 *)(param_1 + 0x18),0x7ff);
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x981034);
  if (iVar1 == 0) {
    strncpy(param_3,*(undefined4 *)(param_1 + 0x1c),0x7ff);
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x980c60);
  if (iVar1 == 0) {
    *param_3 = *(undefined4 *)(param_1 + 0x50);
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x980c5c);
  if (iVar1 == 0) {
    *param_3 = *(undefined4 *)(param_1 + 0x54);
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x980c54);
  if (iVar1 == 0) {
    *param_3 = *(undefined4 *)(param_1 + 0x58);
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x980c4c);
  if (iVar1 == 0) {
    *param_3 = *(undefined4 *)(param_1 + 0x5c);
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x980c64);
  if (iVar1 == 0) {
    *param_3 = *(undefined4 *)(param_1 + 0x38);
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x96778c);
  if (iVar1 == 0) {
    wcsncpy(param_3,*(undefined4 *)(param_1 + 0x20),0x7ff);
    param_3[0x400] = *(undefined4 *)(param_1 + 0x24);
    *(undefined1 *)(param_3 + 0x401) = *(undefined1 *)(param_1 + 0x30);
    *(undefined1 *)((int)param_3 + 0x1005) = *(undefined1 *)(param_1 + 0x31);
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x94eb38);
  if (iVar1 == 0) {
    *param_3 = *(undefined4 *)(param_1 + 0x28);
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x980c3c);
  if (iVar1 == 0) {
    *param_3 = *(undefined4 *)(param_1 + 0x2c);
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x980fd8);
  if (iVar1 == 0) {
    wcsncpy(param_3,*(undefined4 *)(param_1 + 0x74),0x7ff);
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x981510);
  if (iVar1 == 0) {
    *param_3 = *(undefined4 *)(param_1 + 0x70);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007422f0 | Classified: AUIObject::vfunc_slot_10 */
/* ==================================================================== */

undefined4 __thiscall FUN_007422f0(int *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = _strcmpi(param_2,0x95b2b4);
  if (iVar1 == 0) {
    FUN_00741e10(param_3);
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x981044);
  if (iVar1 == 0) {
    func_0x007638a0(param_3);
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x981034);
  if (iVar1 == 0) {
    func_0x007638a0(param_3);
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x980c60);
  if (iVar1 == 0) {
    param_1[0x14] = *param_3;
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x980c5c);
  if (iVar1 == 0) {
    param_1[0x15] = *param_3;
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x980c54);
  if (iVar1 == 0) {
    param_1[0x16] = *param_3;
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x980c4c);
  if (iVar1 == 0) {
    param_1[0x17] = *param_3;
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x980c64);
  if (iVar1 == 0) {
    (**(code **)(*param_1 + 0x2c))(*param_3);
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x96778c);
  if (iVar1 == 0) {
    FUN_00742530(param_3,param_3[0x400],param_1[0xe],param_1[10],param_1[0xb],(char)param_3[0x401],
                 *(undefined1 *)((int)param_3 + 0x1005));
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x94eb38);
  if (iVar1 == 0) {
    param_1[10] = *param_3;
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x980c3c);
  if (iVar1 == 0) {
    FUN_00742530(param_1[8],param_1[9],param_1[0xe],param_1[10],*param_3,0,0);
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x980fd8);
  if (iVar1 == 0) {
    FUN_00765230(param_3);
    return 1;
  }
  iVar1 = _strcmpi(param_2,0x981510);
  if (iVar1 == 0) {
    param_1[0x1c] = *param_3;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007424f0 | Classified: AngelicaUI::proc_7424f0 */
/* ==================================================================== */

undefined1 __fastcall FUN_007424f0(int param_1)

{
  return *(undefined1 *)(param_1 + 0x45);
}


/* ==================================================================== */
/* Address: 0x00742500 | Classified: AUITextArea::vfunc_slot_14 */
/* ==================================================================== */

void __thiscall FUN_00742500(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x45) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00742520 | Classified: AUIListBox::vfunc_slot_13 */
/* ==================================================================== */

void FUN_00742520(undefined4 param_1)

{
  FUN_00765230(param_1);
  return;
}


/* ==================================================================== */
/* Address: 0x00742530 | Classified: elementclient::AUIObject__SetFontAndColor__Fail@0x742530 */
/* ==================================================================== */

undefined4 __thiscall
FUN_00742530(int *param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6,
            char param_7,char param_8)

{
  int iVar1;
  byte bVar2;
  
  if (param_2 != 0) {
    bVar2 = param_7 != '\0';
    if (param_8 != '\0') {
      bVar2 = bVar2 | 0x10;
    }
    func_0x00868610((float)param_3,param_2,bVar2,param_6);
    FUN_007310f0();
    iVar1 = func_0x0075e6e0();
    param_1[0xd] = iVar1;
    if (iVar1 == 0) {
      func_0x00764590(1,0x98151c);
      return 0;
    }
    FUN_00765230(param_2);
    param_1[9] = param_3;
    param_1[10] = param_5;
    param_1[0xb] = param_6;
    *(char *)(param_1 + 0xc) = param_7;
    *(char *)((int)param_1 + 0x31) = param_8;
  }
  (**(code **)(*param_1 + 0x2c))(param_4);
  return 1;
}


/* ==================================================================== */
/* Address: 0x007425e0 | Classified: AngelicaUI::proc_7425e0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007425e0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x38);
}


/* ==================================================================== */
/* Address: 0x007425f0 | Classified: AUITextArea::vfunc_slot_11 */
/* ==================================================================== */

void __thiscall FUN_007425f0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x38) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00742600 | Classified: AngelicaUI::proc_742600 */
/* ==================================================================== */

void FUN_00742600(undefined4 param_1)

{
  func_0x007638a0(param_1);
  return;
}


/* ==================================================================== */
/* Address: 0x00742610 | Classified: AngelicaUI::proc_742610 */
/* ==================================================================== */

undefined1 __fastcall FUN_00742610(int param_1)

{
  return *(undefined1 *)(param_1 + 0x47);
}


/* ==================================================================== */
/* Address: 0x00742620 | Classified: AngelicaUI::proc_742620 */
/* ==================================================================== */

void __thiscall FUN_00742620(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x47) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00742630 | Classified: AngelicaUI::proc_742630 */
/* ==================================================================== */

undefined1 __fastcall FUN_00742630(int param_1)

{
  return *(undefined1 *)(param_1 + 0x48);
}


/* ==================================================================== */
/* Address: 0x00742640 | Classified: AngelicaUI::proc_742640 */
/* ==================================================================== */

void __thiscall FUN_00742640(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x48) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00742650 | Classified: elementclient::AUIObject__GetData____data_name_n@0x742650 */
/* ==================================================================== */

undefined4 __fastcall FUN_00742650(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_8 = &UNK_008ca648;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  if (*(int *)(param_1 + 0x8c) != 0) {
    cVar2 = func_0x00763c50(param_1 + 0x94);
    if (cVar2 == '\0') {
      func_0x00739700(0x1e1,1,0x981550);
    }
  }
  uVar1 = *(undefined4 *)(param_1 + 0x8c);
  uStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return uVar1;
}


/* ==================================================================== */
/* Address: 0x007426d0 | Classified: AngelicaUI::proc_7426d0 */
/* ==================================================================== */

void __fastcall FUN_007426d0(int param_1)

{
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_8 = &UNK_008ca668;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  func_0x00763940(&stack0x00000008);
  puStack_8 = (undefined *)0xffffffff;
  *(undefined4 *)(param_1 + 0x8c) = unaff_retaddr;
  func_0x007637f0();
  *unaff_FS_OFFSET = unaff_ESI;
  return;
}


/* ==================================================================== */
/* Address: 0x00742730 | Classified: elementclient::AUIObject__GetDataPtr____data_na@0x742730 */
/* ==================================================================== */

undefined4 __fastcall FUN_00742730(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_8 = &UNK_008ca688;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  if (*(int *)(param_1 + 0x90) != 0) {
    cVar2 = func_0x00763c50(param_1 + 0x98);
    if (cVar2 == '\0') {
      func_0x00739700(0x1ee,1,0x98157c);
    }
  }
  uVar1 = *(undefined4 *)(param_1 + 0x90);
  uStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return uVar1;
}


/* ==================================================================== */
/* Address: 0x007427b0 | Classified: AngelicaUI::proc_7427b0 */
/* ==================================================================== */

void __fastcall FUN_007427b0(int param_1)

{
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_8 = &UNK_008ca6a8;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  func_0x00763940(&stack0x00000008);
  puStack_8 = (undefined *)0xffffffff;
  *(undefined4 *)(param_1 + 0x90) = unaff_retaddr;
  func_0x007637f0();
  *unaff_FS_OFFSET = unaff_ESI;
  return;
}


/* ==================================================================== */
/* Address: 0x00742810 | Classified: AngelicaUI::proc_742810 */
/* ==================================================================== */

void __thiscall FUN_00742810(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x90);
  func_0x00763940(param_1 + 0x98);
  return;
}


/* ==================================================================== */
/* Address: 0x00742830 | Classified: AngelicaUI::proc_742830 */
/* ==================================================================== */

undefined4 __fastcall FUN_00742830(int param_1)

{
  return *(undefined4 *)(param_1 + 0x78);
}


/* ==================================================================== */
/* Address: 0x00742840 | Classified: AngelicaUI::proc_742840 */
/* ==================================================================== */

void FUN_00742840(undefined4 param_1)

{
  FUN_00765230(param_1);
  return;
}


/* ==================================================================== */
/* Address: 0x00742850 | Classified: AngelicaUI::proc_742850 */
/* ==================================================================== */

void __thiscall FUN_00742850(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x81) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00742860 | Classified: AngelicaUI::proc_742860 */
/* ==================================================================== */

void __thiscall FUN_00742860(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x84) = param_2;
  *(undefined4 *)(param_1 + 0x88) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00742880 | Classified: AngelicaUI::proc_742880 */
/* ==================================================================== */

void __thiscall FUN_00742880(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x70) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00742890 | Classified: AngelicaUI::proc_742890 */
/* ==================================================================== */

void __thiscall FUN_00742890(int param_1,char param_2)

{
  if (param_2 != '\0') {
    *(char *)(param_1 + 0x49) = param_2;
    *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_1 + 0x84);
    return;
  }
  *(undefined1 *)(param_1 + 0x49) = 0;
  *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(param_1 + 0x88);
  return;
}


/* ==================================================================== */
/* Address: 0x007428c0 | Classified: AngelicaUI::proc_7428c0 */
/* ==================================================================== */

undefined1 __fastcall FUN_007428c0(int param_1)

{
  return *(undefined1 *)(param_1 + 0x49);
}


/* ==================================================================== */
/* Address: 0x007428d0 | Classified: AngelicaUI::proc_7428d0 */
/* ==================================================================== */

void __thiscall
FUN_007428d0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  *(undefined4 *)(param_1 + 0x60) = param_2;
  *(undefined4 *)(param_1 + 100) = param_3;
  *(undefined4 *)(param_1 + 0x68) = param_4;
  *(undefined4 *)(param_1 + 0x6c) = param_5;
  return;
}


/* ==================================================================== */
/* Address: 0x007428f0 | Classified: AngelicaUI::proc_7428f0 */
/* ==================================================================== */

void __thiscall FUN_007428f0(int param_1,uint param_2)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint *puVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  byte *pbVar11;
  uint uStack_18;
  
  uVar3 = *(uint *)(param_1 + 0x14);
  if (uVar3 < param_2) {
    iVar7 = 0;
    puVar5 = (uint *)&UNK_008eec6c;
    do {
      if (param_2 < *puVar5) {
        param_2 = *(uint *)(&UNK_008eec6c + iVar7 * 4);
        goto LAB_0074292d;
      }
      puVar5 = puVar5 + 1;
      iVar7 = iVar7 + 1;
    } while ((int)puVar5 < 0x8eecdc);
    param_2 = 0xffffffff;
LAB_0074292d:
    if (uVar3 < param_2) {
      if (param_2 == 0) {
        puVar10 = (undefined4 *)0x0;
        puVar6 = puVar10;
      }
      else {
        puVar6 = (undefined4 *)func_0x00763250(param_2 * 4);
        uVar8 = param_2;
        puVar9 = puVar6;
        do {
          puVar10 = puVar9 + 1;
          if (puVar9 != (undefined4 *)0x0) {
            *puVar9 = 0;
          }
          uVar8 = uVar8 - 1;
          puVar9 = puVar10;
        } while (uVar8 != 0);
      }
      uStack_18 = 0;
      if (uVar3 != 0) {
        do {
          puVar9 = (undefined4 *)(*(int *)(param_1 + 8) + uStack_18 * 4);
          puVar4 = *(undefined4 **)(*(int *)(param_1 + 8) + uStack_18 * 4);
          while (puVar4 != (undefined4 *)0x0) {
            pbVar11 = (byte *)puVar4[2];
            uVar8 = 0;
            bVar2 = *pbVar11;
            while (bVar2 != 0) {
              uVar8 = uVar8 * 0x1f + (uint)bVar2;
              pbVar1 = pbVar11 + 1;
              pbVar11 = pbVar11 + 1;
              bVar2 = *pbVar1;
            }
            *puVar9 = *puVar4;
            *puVar4 = puVar6[uVar8 % param_2];
            puVar6[uVar8 % param_2] = puVar4;
            puVar9 = (undefined4 *)(*(int *)(param_1 + 8) + uStack_18 * 4);
            puVar4 = *(undefined4 **)(*(int *)(param_1 + 8) + uStack_18 * 4);
          }
          uStack_18 = uStack_18 + 1;
        } while (uStack_18 < uVar3);
      }
      puVar9 = *(undefined4 **)(param_1 + 8);
      *(undefined4 **)(param_1 + 8) = puVar6;
      puVar4 = *(undefined4 **)(param_1 + 0xc);
      *(undefined4 **)(param_1 + 0xc) = puVar10;
      iVar7 = *(int *)(param_1 + 0x14);
      *(uint *)(param_1 + 0x14) = param_2;
      *(uint *)(param_1 + 0x10) = param_2;
      puVar6 = puVar9 + iVar7;
      puVar10 = puVar9;
      if (puVar9 != puVar6) {
        for (; puVar6 < puVar4; puVar6 = puVar6 + 1) {
          *puVar10 = *puVar6;
          puVar10 = puVar10 + 1;
        }
      }
      if (puVar9 != (undefined4 *)0x0) {
        func_0x00763260(puVar9);
      }
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00742a50 | Classified: AngelicaUI::proc_742a50 */
/* ==================================================================== */

uint __thiscall FUN_00742a50(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  byte *pbVar8;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ca6d1;
  *unaff_FS_OFFSET = &uStack_c;
  pbVar8 = (byte *)*param_2;
  uVar4 = 0;
  bVar2 = *pbVar8;
  while (bVar2 != 0) {
    uVar4 = uVar4 * 0x1f + (uint)bVar2;
    pbVar1 = pbVar8 + 1;
    pbVar8 = pbVar8 + 1;
    bVar2 = *pbVar1;
  }
  uVar4 = uVar4 % *(uint *)(param_1 + 0x14);
  puVar3 = *(undefined4 **)(*(int *)(param_1 + 8) + uVar4 * 4);
  puVar6 = puVar3;
  do {
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)func_0x00763250(0xc);
      uStack_4 = 0;
      if (puVar6 == (undefined4 *)0x0) {
        puVar6 = (undefined4 *)0x0;
      }
      else {
        puVar6[1] = *param_3;
        func_0x00763660(param_2);
        *puVar6 = puVar3;
      }
      *(undefined4 **)(*(int *)(param_1 + 8) + uVar4 * 4) = puVar6;
      iVar7 = *(int *)(param_1 + 4) + 1;
      *(int *)(param_1 + 4) = iVar7;
      uVar5 = CONCAT31((int3)((uint)iVar7 >> 8),1);
LAB_00742b10:
      *unaff_FS_OFFSET = uStack_c;
      return uVar5;
    }
    uVar5 = func_0x00763c50(param_2);
    if ((char)uVar5 != '\0') {
      uVar5 = uVar5 & 0xffffff00;
      goto LAB_00742b10;
    }
    puVar6 = (undefined4 *)*puVar6;
  } while( true );
}


/* ==================================================================== */
/* Address: 0x00742b30 | Classified: AngelicaUI::proc_742b30 */
/* ==================================================================== */

void __fastcall FUN_00742b30(undefined4 *param_1)

{
  param_1[4] = 0x10;
  param_1[5] = 0x10;
  *param_1 = &UNK_008eed9c;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[7] = 100;
  param_1[8] = 0;
  param_1[9] = 100;
  param_1[10] = 10;
  param_1[0xb] = 0x80ffffff;
  param_1[1] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00742b70 | Classified: AUIClockIcon::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_00742b70(undefined4 param_1,byte param_2)

{
  FUN_00742b90();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00742b90 | Classified: AngelicaUI::proc_742b90 */
/* ==================================================================== */

void __fastcall FUN_00742b90(undefined4 *param_1)

{
  *param_1 = &UNK_008eed9c;
  return;
}


/* ==================================================================== */
/* Address: 0x00742ba0 | Classified: AngelicaUI::proc_742ba0 */
/* ==================================================================== */

void __thiscall FUN_00742ba0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  if (*(int *)(param_1 + 0x1c) < *(int *)(param_1 + 0x20)) {
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x20);
  }
  if (*(int *)(param_1 + 0x24) < *(int *)(param_1 + 0x1c)) {
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x24);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00742bd0 | Classified: AngelicaUI::proc_742bd0 */
/* ==================================================================== */

void __thiscall FUN_00742bd0(int param_1,int param_2,undefined4 param_3)

{
  *(int *)(param_1 + 0x20) = param_2;
  *(undefined4 *)(param_1 + 0x24) = param_3;
  if (*(int *)(param_1 + 0x1c) < param_2) {
    *(int *)(param_1 + 0x1c) = param_2;
  }
  if (*(int *)(param_1 + 0x24) < *(int *)(param_1 + 0x1c)) {
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x24);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00742c00 | Classified: AngelicaUI::proc_742c00 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00742c00(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  iVar1 = *(int *)(param_1 + 8);
  uVar3 = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x38) = uVar3;
  iVar2 = *(int *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0x44) = uVar3;
  *(undefined4 *)(param_1 + 0x50) = uVar3;
  fVar4 = ((float)*(int *)(param_1 + 0x10) + (float)iVar1) - _DAT_008d5c28;
  fVar6 = ((float)*(int *)(param_1 + 0x14) + (float)iVar2) - _DAT_008d5c28;
  *(float *)(param_1 + 0x4c) = fVar6;
  *(float *)(param_1 + 0x58) = fVar6;
  *(float *)(param_1 + 100) = fVar6;
  fVar5 = (fVar4 + (float)iVar1) * _DAT_008d5894;
  *(float *)(param_1 + 0x54) = fVar5;
  uVar3 = *(undefined4 *)(param_1 + 0x18);
  fVar6 = (fVar6 + (float)iVar2) * _DAT_008d5894;
  *(undefined4 *)(param_1 + 0x5c) = uVar3;
  *(undefined4 *)(param_1 + 0x68) = uVar3;
  *(undefined4 *)(param_1 + 0x74) = uVar3;
  *(undefined4 *)(param_1 + 0x80) = uVar3;
  *(float *)(param_1 + 0x88) = (float)iVar2;
  *(float *)(param_1 + 0x70) = fVar6;
  *(float *)(param_1 + 0x30) = fVar4;
  *(float *)(param_1 + 0x90) = fVar5;
  *(float *)(param_1 + 0x34) = (float)iVar2;
  *(float *)(param_1 + 0x7c) = (float)iVar2;
  *(float *)(param_1 + 0x3c) = fVar4;
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x18);
  *(float *)(param_1 + 0x40) = fVar6;
  *(float *)(param_1 + 0x84) = fVar5;
  *(float *)(param_1 + 0x48) = fVar4;
  *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x18);
  *(float *)(param_1 + 0x60) = (float)iVar1;
  *(float *)(param_1 + 0x6c) = (float)iVar1;
  *(float *)(param_1 + 0x78) = (float)iVar1;
  *(float *)(param_1 + 0x94) = fVar6;
  return;
}


/* ==================================================================== */
/* Address: 0x00742d00 | Classified: AngelicaUI::proc_742d00 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00742d00(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  uint uVar11;
  float fVar12;
  uint uVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  float10 extraout_ST0;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined2 uStack_30;
  undefined2 uStack_2e;
  undefined2 uStack_2c;
  undefined4 auStack_2a [10];
  
  if (*(int *)(param_1 + 0x1c) == *(int *)(param_1 + 0x24)) {
    return;
  }
  if (*(int *)(param_1 + 0x1c) == *(int *)(param_1 + 0x20)) {
    uStack_60 = *(undefined4 *)(param_1 + 0x30);
    uStack_5c = *(undefined4 *)(param_1 + 0x34);
    uStack_58 = *(undefined4 *)(param_1 + 0x38);
    uStack_54 = *(undefined4 *)(param_1 + 0x48);
    uStack_50 = *(undefined4 *)(param_1 + 0x4c);
    uStack_48 = *(undefined4 *)(param_1 + 0x60);
    uStack_44 = *(undefined4 *)(param_1 + 100);
    uStack_3c = *(undefined4 *)(param_1 + 0x78);
    uStack_4c = *(undefined4 *)(param_1 + 0x50);
    uStack_38 = *(undefined4 *)(param_1 + 0x7c);
    uStack_40 = *(undefined4 *)(param_1 + 0x68);
    uStack_34 = *(undefined4 *)(param_1 + 0x80);
    func_0x00778a60(&uStack_60,4,&UNK_008eed8c,6,*(undefined4 *)(param_1 + 0x2c));
    return;
  }
  iVar10 = func_0x00892e78();
  if (iVar10 < 0) {
    iVar10 = 0;
  }
  else if (7 < iVar10) {
    iVar10 = 7;
  }
  fVar2 = (float)(extraout_ST0 - (float10)iVar10);
  fVar3 = (float)*(int *)(param_1 + 8);
  fVar4 = (float)*(int *)(param_1 + 0xc);
  fVar5 = ((float)*(int *)(param_1 + 0x10) + (float)*(int *)(param_1 + 8)) - _DAT_008d5c28;
  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_1 + 0x18);
  fVar12 = ((float)*(int *)(param_1 + 0x14) + fVar4) - _DAT_008d5c28;
  fVar7 = (fVar5 + fVar3) * _DAT_008d5894;
  fVar8 = (fVar12 + fVar4) * _DAT_008d5894;
  fVar9 = (float)*(int *)(param_1 + 0x10) * _DAT_008d5894;
  fVar6 = (float)*(int *)(param_1 + 0x14) * _DAT_008d5894;
  switch(iVar10) {
  case 0:
    *(float *)(param_1 + 0xa0) = fVar4;
    *(float *)(param_1 + 0x9c) = fVar9 * fVar2 + fVar7;
    break;
  case 1:
    *(float *)(param_1 + 0x9c) = fVar5;
    *(float *)(param_1 + 0xa0) = fVar6 * fVar2 + fVar4;
    break;
  case 2:
    *(float *)(param_1 + 0x9c) = fVar5;
    *(float *)(param_1 + 0xa0) = fVar6 * fVar2 + fVar8;
    break;
  case 3:
    *(float *)(param_1 + 0x9c) = fVar5 - fVar9 * fVar2;
    goto code_r0x00742f64;
  case 4:
    *(float *)(param_1 + 0xa0) = fVar12;
    *(float *)(param_1 + 0x9c) = fVar7 - fVar9 * fVar2;
    break;
  case 5:
    *(float *)(param_1 + 0x9c) = fVar3;
    *(float *)(param_1 + 0xa0) = fVar12 - fVar6 * fVar2;
    break;
  case 6:
    *(float *)(param_1 + 0x9c) = fVar3;
    *(float *)(param_1 + 0xa0) = fVar8 - fVar6 * fVar2;
    break;
  case 7:
    *(float *)(param_1 + 0x9c) = fVar9 * fVar2 + fVar3;
    fVar12 = fVar4;
code_r0x00742f64:
    *(float *)(param_1 + 0xa0) = fVar12;
  }
  iVar1 = iVar10 * 3 + 3;
  uStack_30 = 8;
  uStack_2e = 9;
  uStack_2c = (undefined2)iVar10;
  iVar10 = 3;
  if (iVar1 < 0x18) {
    uVar11 = -iVar1 + 0x18;
    iVar10 = -iVar1 + 0x1b;
    puVar14 = (undefined4 *)(iVar1 * 2 + 0x9815ac);
    puVar15 = auStack_2a;
    for (uVar13 = uVar11 >> 1; uVar13 != 0; uVar13 = uVar13 - 1) {
      *puVar15 = *puVar14;
      puVar14 = puVar14 + 1;
      puVar15 = puVar15 + 1;
    }
    for (uVar11 = (uint)((uVar11 & 1) != 0); uVar11 != 0; uVar11 = uVar11 - 1) {
      *(undefined2 *)puVar15 = *(undefined2 *)puVar14;
      puVar14 = (undefined4 *)((int)puVar14 + 2);
      puVar15 = (undefined4 *)((int)puVar15 + 2);
    }
  }
  func_0x00778a60(param_1 + 0x30,10,&uStack_30,iVar10,*(undefined4 *)(param_1 + 0x2c));
  return;
}


/* ==================================================================== */
/* Address: 0x00742ff0 | Classified: AngelicaUI::proc_742ff0 */
/* ==================================================================== */

undefined4 * __fastcall FUN_00742ff0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ca6e8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  func_0x007624b0();
  uStack_4 = 0;
  FUN_00742b30();
  *param_1 = &UNK_008eee14;
  param_1[0xf] = 5;
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  param_1[0x56] = 0xffffffff;
  param_1[0x27] = 0;
  param_1[0x57] = 0;
  param_1[0x58] = 0;
  param_1[0x59] = 0;
  param_1[0x5a] = 0;
  param_1[0x5b] = 0;
  *(undefined1 *)(param_1 + 0x12) = 0;
  param_1[0x5c] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  param_1[0x60] = 0;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007430b0 | Classified: AUIImagePicture::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007430b0(undefined4 param_1,byte param_2)

{
  FUN_007430d0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007430d0 | Classified: AngelicaUI::proc_7430d0 */
/* ==================================================================== */

void __fastcall FUN_007430d0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008ca708;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008eee14;
  uStack_4 = 0;
  FUN_00742b90();
  uStack_4 = 0xffffffff;
  func_0x007624f0();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x00743410 | Classified: AUIImagePicture::vfunc_slot_3 */
/* ==================================================================== */

void __fastcall FUN_00743410(int param_1)

{
  if (*(int *)(param_1 + 0x9c) != 0) {
    func_0x0078c040();
    if (*(undefined4 **)(param_1 + 0x9c) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x9c))(1);
    }
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  thunk_FUN_00430850();
  return;
}


/* ==================================================================== */
/* Address: 0x007434e0 | Classified: AUILabel::vfunc_slot_3 */
/* ==================================================================== */

undefined1 thunk_FUN_00430850(void)

{
  return 1;
}


/* ==================================================================== */
/* Address: 0x00743db0 | Classified: AngelicaUI::proc_743db0 */
/* ==================================================================== */

void __thiscall FUN_00743db0(int param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x154))) {
    *(int *)(param_1 + 0x158) = param_2;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00743dd0 | Classified: AngelicaUI::proc_743dd0 */
/* ==================================================================== */

void __fastcall FUN_00743dd0(int param_1)

{
  *(undefined4 *)(param_1 + 0x15c) = 0;
  *(undefined4 *)(param_1 + 0x160) = 0;
  *(undefined4 *)(param_1 + 0x164) = 0;
  *(undefined4 *)(param_1 + 0x168) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00743df0 | Classified: AngelicaUI::proc_743df0 */
/* ==================================================================== */

void __thiscall FUN_00743df0(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  if (param_4 == 0) {
    *(undefined4 *)(param_1 + 0x164) = param_2;
    *(undefined4 *)(param_1 + 0x15c) = param_3;
    return;
  }
  *(undefined4 *)(param_1 + 0x168) = param_2;
  *(undefined4 *)(param_1 + 0x160) = param_3;
  return;
}


/* ==================================================================== */
/* Address: 0x00743e30 | Classified: AngelicaUI::proc_743e30 */
/* ==================================================================== */

void __thiscall FUN_00743e30(int param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  if (param_4 == 0) {
    *param_2 = *(undefined4 *)(param_1 + 0x164);
    *param_3 = *(undefined4 *)(param_1 + 0x15c);
    return;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x168);
  *param_3 = *(undefined4 *)(param_1 + 0x160);
  return;
}


/* ==================================================================== */
/* Address: 0x00743e70 | Classified: AngelicaUI::proc_743e70 */
/* ==================================================================== */

undefined4 __fastcall FUN_00743e70(int param_1)

{
  return *(undefined4 *)(param_1 + 0x9c);
}


/* ==================================================================== */
/* Address: 0x00743e80 | Classified: AngelicaUI::proc_743e80 */
/* ==================================================================== */

void __thiscall FUN_00743e80(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x16c);
  return;
}


/* ==================================================================== */
/* Address: 0x00743e90 | Classified: AngelicaUI::proc_743e90 */
/* ==================================================================== */

void __thiscall FUN_00743e90(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x16c) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00743ea0 | Classified: AngelicaUI::proc_743ea0 */
/* ==================================================================== */

int __fastcall FUN_00743ea0(int param_1)

{
  return param_1 + 0xa0;
}


/* ==================================================================== */
/* Address: 0x00743eb0 | Classified: AngelicaUI::proc_743eb0 */
/* ==================================================================== */

void __thiscall
FUN_00743eb0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  *(undefined4 *)(param_1 + 0x170) = param_3;
  *(undefined4 *)(param_1 + 0x174) = param_4;
  *(undefined4 *)(param_1 + 0x178) = param_5;
  *(undefined4 *)(param_1 + 0x17c) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00743ee0 | Classified: AngelicaUI::proc_743ee0 */
/* ==================================================================== */

void __thiscall FUN_00743ee0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x180) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00743ef0 | Classified: AngelicaUI::proc_743ef0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00743ef0(undefined4 *param_1)

{
  *param_1 = _DAT_009858e4;
  param_1[1] = _DAT_00985a98;
  return;
}


/* ==================================================================== */
/* Address: 0x00743f10 | Classified: AngelicaUI::proc_743f10 */
/* ==================================================================== */

void FUN_00743f10(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008ca748;
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
/* Address: 0x00743f60 | Classified: AngelicaUI::proc_743f60 */
/* ==================================================================== */

undefined4 __thiscall FUN_00743f60(int param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  int iVar5;
  
  FUN_00765230(param_2);
  iVar2 = wcslen(param_2);
  puVar3 = (ushort *)func_0x00763250(iVar2 * 2 + 2);
  uVar1 = *param_2;
  puVar4 = puVar3;
  do {
    if (uVar1 == 0) {
      *puVar4 = 0;
      FUN_00765230(puVar3);
      func_0x00763260(puVar3);
      return *(undefined4 *)(param_1 + 4);
    }
    uVar1 = *param_2;
    if (uVar1 != 0x5c) {
code_r0x00743f9e:
      *puVar4 = uVar1;
      goto LAB_0074401f;
    }
    uVar1 = param_2[1];
    param_2 = param_2 + 1;
    switch(uVar1) {
    case 10:
      goto code_r0x00744022;
    default:
      goto LAB_00744025;
    case 0x22:
    case 0x27:
    case 0x5c:
      goto code_r0x00743f9e;
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
      iVar2 = 0;
      iVar5 = 3;
      if (uVar1 < 0x38) {
        do {
          if ((uVar1 < 0x30) || (iVar5 == 0)) break;
          param_2 = param_2 + 1;
          iVar5 = iVar5 + -1;
          iVar2 = (uVar1 - 0x30) + iVar2 * 8;
          uVar1 = *param_2;
        } while (uVar1 < 0x38);
        if (0xff < iVar2) goto LAB_00744025;
      }
      *puVar4 = (ushort)iVar2 & 0xff;
      puVar4 = puVar4 + 1;
      goto LAB_00744025;
    case 0x6e:
      *puVar4 = 10;
      break;
    case 0x72:
      *puVar4 = 0xd;
      break;
    case 0x74:
      *puVar4 = 9;
    }
LAB_0074401f:
    puVar4 = puVar4 + 1;
code_r0x00744022:
    param_2 = param_2 + 1;
LAB_00744025:
    uVar1 = *param_2;
  } while( true );
}


/* ==================================================================== */
/* Address: 0x007440e0 | Classified: AngelicaUI::proc_7440e0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall FUN_007440e0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008ca789;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = _DAT_009858e4;
  param_1[1] = _DAT_00985a98;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  uStack_4 = 3;
  func_0x007638a0(param_2);
  *unaff_FS_OFFSET = param_1;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00744150 | Classified: AngelicaUI::proc_744150 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall FUN_00744150(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008ca7c9;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = _DAT_009858e4;
  param_1[1] = _DAT_00985a98;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  uStack_4 = 3;
  FUN_00765230(param_2);
  *unaff_FS_OFFSET = param_1;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007441c0 | Classified: AngelicaUI::proc_7441c0 */
/* ==================================================================== */

void __fastcall FUN_007441c0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  uint uStack_4;
  
  puStack_8 = &UNK_008ca7fe;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uVar2 = *(uint *)(param_1 + 0x18);
  uStack_4 = 2;
  uVar1 = uVar2 + *(int *)(param_1 + 0x24) * 4;
  if (uVar2 != uVar1) {
    uVar3 = uVar1;
    uVar5 = uVar2;
    if (uVar1 < *(uint *)(param_1 + 0x1c)) {
      do {
        FUN_007652d0(uVar3);
        uVar3 = uVar3 + 4;
        uVar5 = uVar5 + 4;
      } while (uVar3 < *(uint *)(param_1 + 0x1c));
    }
    if (uVar5 < *(uint *)(param_1 + 0x1c)) {
      do {
        FUN_00765200();
        uVar5 = uVar5 + 4;
      } while (uVar5 < *(uint *)(param_1 + 0x1c));
    }
    iVar4 = (int)(uVar1 - uVar2) >> 2;
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + iVar4 * -4;
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) - iVar4;
  }
  if (*(int *)(param_1 + 0x18) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x18));
  }
  uVar2 = *(uint *)(param_1 + 8);
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  uVar1 = uVar2 + *(int *)(param_1 + 0x14) * 4;
  if (uVar2 != uVar1) {
    uVar3 = uVar1;
    uVar5 = uVar2;
    if (uVar1 < *(uint *)(param_1 + 0xc)) {
      do {
        func_0x00763940(uVar3);
        uVar3 = uVar3 + 4;
        uVar5 = uVar5 + 4;
      } while (uVar3 < *(uint *)(param_1 + 0xc));
    }
    if (uVar5 < *(uint *)(param_1 + 0xc)) {
      do {
        func_0x007637f0();
        uVar5 = uVar5 + 4;
      } while (uVar5 < *(uint *)(param_1 + 0xc));
    }
    iVar4 = (int)(uVar1 - uVar2) >> 2;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + iVar4 * -4;
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - iVar4;
  }
  if (*(int *)(param_1 + 8) != 0) {
    func_0x00763260(*(int *)(param_1 + 8));
  }
  uStack_4 = uStack_4 & 0xffffff00;
  FUN_00765200();
  uStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x00744320 | Classified: AngelicaUI::proc_744320 */
/* ==================================================================== */

undefined4 * __thiscall FUN_00744320(int *param_1,undefined4 *param_2,char *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  int iVar12;
  char *pcVar13;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_30 [4];
  int iStack_2c;
  int *piStack_28;
  int *piStack_24;
  int *piStack_20;
  int *piStack_1c;
  int iStack_18;
  int iStack_14;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ca84e;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  piStack_1c = (int *)0x0;
  piStack_24 = param_1;
  piVar2 = (int *)func_0x00763250(*(int *)(*param_1 + -8) + 1);
  uVar5 = 0xffffffff;
  pcVar13 = (char *)*param_1;
  do {
    pcVar11 = pcVar13;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar11 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar11;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  piVar3 = (int *)(pcVar11 + -uVar5);
  piVar8 = piVar2;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *piVar8 = *piVar3;
    piVar3 = piVar3 + 1;
    piVar8 = piVar8 + 1;
  }
  for (uVar5 = uVar5 & 3; piStack_1c = piVar2, uVar5 != 0; uVar5 = uVar5 - 1) {
    *(char *)piVar8 = (char)*piVar3;
    piVar3 = (int *)((int)piVar3 + 1);
    piVar8 = (int *)((int)piVar8 + 1);
  }
  do {
    piVar3 = (int *)strstr(piVar2,param_3);
    if (piVar3 != (int *)0x0) {
      *(undefined1 *)piVar3 = 0;
    }
    iVar7 = -1;
    piVar8 = piVar2;
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      iVar9 = *piVar8;
      piVar8 = (int *)((int)piVar8 + 1);
    } while ((char)iVar9 != '\0');
    piVar8 = param_1;
    piStack_20 = piVar3;
    if (iVar7 != -2) {
      func_0x007636b0(piVar2);
      uVar5 = param_1[5];
      piVar2 = param_1 + 2;
      puStack_8._0_1_ = 0;
      puStack_8._1_3_ = 0;
      piStack_1c = piVar2;
      if (uVar5 == param_1[4]) {
        if (uVar5 + 1 < 5) {
          iVar7 = 5;
        }
        else {
          iVar7 = uVar5 + 3 + (uVar5 >> 1);
        }
        iStack_2c = func_0x00763250(iVar7 * 4);
        uVar5 = 0;
        iVar9 = *piVar2;
        iVar12 = iStack_2c;
        if (param_1[5] != 0) {
          do {
            puStack_8._0_1_ = 1;
            iVar10 = iVar9;
            iStack_18 = iVar12;
            iStack_14 = iVar12;
            if (iVar12 != 0) {
              iVar10 = iVar9 + 4;
              func_0x00763660(iVar9);
            }
            uVar5 = uVar5 + 1;
            puStack_8._0_1_ = 0;
            iVar9 = iVar10;
            iVar12 = iVar12 + 4;
          } while (uVar5 < (uint)param_1[5]);
        }
        uVar5 = 0;
        if (param_1[5] != 0) {
          do {
            func_0x007637f0();
            uVar5 = uVar5 + 1;
          } while (uVar5 < (uint)param_1[5]);
        }
        if (*piVar2 != 0) {
          func_0x00763260(*piVar2);
        }
        param_1[4] = iVar7;
        *piVar2 = iStack_2c;
        param_1[3] = iStack_2c + param_1[5] * 4;
        piVar8 = piStack_28;
        piVar3 = piStack_24;
      }
      iStack_14 = param_1[3];
      puStack_8 = (undefined *)CONCAT31(puStack_8._1_3_,2);
      if (iStack_14 != 0) {
        func_0x00763660(auStack_30);
      }
      param_1[5] = param_1[5] + 1;
      param_1[3] = param_1[3] + 4;
      puStack_8 = (undefined *)0xffffffff;
      func_0x007637f0();
    }
    if (piVar3 == (int *)0x0) {
      func_0x00763260(piStack_1c);
      iVar7 = piVar8[4];
      param_2[2] = iVar7;
      param_2[3] = piVar8[5];
      if (piVar8[2] == 0) {
        *param_2 = 0;
      }
      else {
        uVar4 = func_0x00763250(iVar7 * 4);
        *param_2 = uVar4;
      }
      iVar7 = param_2[3];
      param_2[1] = *param_2;
      iVar9 = piVar8[2];
      for (; iVar7 != 0; iVar7 = iVar7 + -1) {
        iVar12 = param_2[1];
        param_2[1] = iVar12 + 4;
        uStack_4 = 3;
        iVar10 = iVar9;
        if (iVar12 != 0) {
          iVar10 = iVar9 + 4;
          func_0x00763660(iVar9);
        }
        iVar9 = iVar10;
      }
      *unaff_FS_OFFSET = uStack_c;
      return param_2;
    }
    uVar5 = 0xffffffff;
    pcVar13 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar13 + 1;
    } while (cVar1 != '\0');
    piVar2 = (int *)((~uVar5 - 1) + (int)piVar3);
    param_1 = piVar8;
  } while( true );
}


/* ==================================================================== */
/* Address: 0x00744590 | Classified: AngelicaUI::proc_744590 */
/* ==================================================================== */

undefined4 * __thiscall FUN_00744590(int *param_1,undefined4 *param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_30 [4];
  int iStack_2c;
  int *piStack_28;
  int *piStack_24;
  int *piStack_20;
  int *piStack_1c;
  int iStack_18;
  int iStack_14;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ca89e;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  piStack_1c = (int *)0x0;
  piStack_20 = param_1;
  piVar1 = (int *)func_0x00763250(*(int *)(param_1[1] + -8) * 2 + 2);
  piStack_24 = piVar1;
  wcscpy(piVar1,param_1[1]);
  piVar8 = piVar1;
  while( true ) {
    piVar2 = (int *)wcsstr(piVar8,param_3);
    if (piVar2 != (int *)0x0) {
      *(undefined2 *)piVar2 = 0;
    }
    piStack_1c = piVar2;
    iVar3 = wcslen(piVar8);
    piVar10 = param_1;
    if (iVar3 != 0) {
      FUN_00765050(piVar8);
      uVar5 = param_1[9];
      piVar8 = param_1 + 6;
      puStack_8._0_1_ = 0;
      puStack_8._1_3_ = 0;
      piStack_1c = piVar8;
      if (uVar5 == param_1[8]) {
        if (uVar5 + 1 < 5) {
          iVar3 = 5;
        }
        else {
          iVar3 = uVar5 + 3 + (uVar5 >> 1);
        }
        iStack_2c = func_0x00763250(iVar3 * 4);
        uVar5 = 0;
        iVar6 = *piVar8;
        iVar9 = iStack_2c;
        if (param_1[9] != 0) {
          do {
            puStack_8._0_1_ = 1;
            iVar7 = iVar6;
            iStack_18 = iVar9;
            iStack_14 = iVar9;
            if (iVar9 != 0) {
              iVar7 = iVar6 + 4;
              FUN_00765000(iVar6);
            }
            uVar5 = uVar5 + 1;
            puStack_8._0_1_ = 0;
            iVar6 = iVar7;
            iVar9 = iVar9 + 4;
          } while (uVar5 < (uint)param_1[9]);
        }
        uVar5 = 0;
        if (param_1[9] != 0) {
          do {
            FUN_00765200();
            uVar5 = uVar5 + 1;
          } while (uVar5 < (uint)param_1[9]);
        }
        if (*piVar8 != 0) {
          func_0x00763260(*piVar8);
        }
        param_1[8] = iVar3;
        *piVar8 = iStack_2c;
        param_1[7] = iStack_2c + param_1[9] * 4;
        piVar2 = piStack_20;
        piVar1 = piStack_28;
        piVar10 = piStack_24;
      }
      iStack_14 = param_1[7];
      puStack_8 = (undefined *)CONCAT31(puStack_8._1_3_,2);
      if (iStack_14 != 0) {
        FUN_00765000(auStack_30);
      }
      param_1[9] = param_1[9] + 1;
      param_1[7] = param_1[7] + 4;
      puStack_8 = (undefined *)0xffffffff;
      FUN_00765200();
    }
    if (piVar2 == (int *)0x0) break;
    iVar3 = wcslen(param_3);
    piVar8 = (int *)((int)piVar2 + iVar3 * 2);
    param_1 = piVar10;
  }
  func_0x00763260(piVar1);
  iVar3 = piVar10[8];
  param_2[2] = iVar3;
  param_2[3] = piVar10[9];
  if (piVar10[6] == 0) {
    *param_2 = 0;
  }
  else {
    uVar4 = func_0x00763250(iVar3 * 4);
    *param_2 = uVar4;
  }
  iVar3 = param_2[3];
  param_2[1] = *param_2;
  iVar6 = piVar10[6];
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    iVar9 = param_2[1];
    param_2[1] = iVar9 + 4;
    uStack_4 = 3;
    iVar7 = iVar6;
    if (iVar9 != 0) {
      iVar7 = iVar6 + 4;
      FUN_00765000(iVar6);
    }
    iVar6 = iVar7;
  }
  *unaff_FS_OFFSET = uStack_c;
  return param_2;
}


/* ==================================================================== */
/* Address: 0x007447f0 | Classified: AngelicaUI::proc_7447f0 */
/* ==================================================================== */

undefined4 * __fastcall FUN_007447f0(undefined4 *param_1)

{
  FUN_00741960();
  *param_1 = &UNK_008eeec4;
  *(undefined1 *)(param_1 + 0x12) = 0;
  param_1[0x1c] = 0;
  *(undefined1 *)(param_1 + 0x27) = 0;
  param_1[0x29] = 0;
  param_1[0x28] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0xf] = 6;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00744830 | Classified: AUILabel::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_00744830(undefined4 param_1,byte param_2)

{
  FUN_00744850();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00744850 | Classified: AngelicaUI::proc_744850 */
/* ==================================================================== */

void __fastcall FUN_00744850(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  *param_1 = &UNK_008eeec4;
  puStack_8 = &UNK_008ca630;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008eece0;
  iStack_4 = 6;
  func_0x007637f0();
  iStack_4._0_1_ = 5;
  func_0x007637f0();
  iStack_4._0_1_ = 4;
  FUN_00765200();
  iStack_4._0_1_ = 3;
  FUN_00765200();
  iStack_4._0_1_ = 2;
  FUN_00765200();
  iStack_4._0_1_ = 1;
  func_0x007637f0();
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  func_0x007637f0();
  iStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x00744e50 | Classified: AUILabel::vfunc_slot_7 */
/* ==================================================================== */

void FUN_00744e50(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  func_0x00773a20(param_1,param_2,param_3);
  return;
}


/* ==================================================================== */
/* Address: 0x00744e70 | Classified: AUILabel::vfunc_slot_6 */
/* ==================================================================== */

undefined4 __fastcall FUN_00744e70(int *param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  undefined4 *unaff_FS_OFFSET;
  uint uStack_70;
  undefined1 auStack_6c [4];
  undefined1 auStack_68 [4];
  int iStack_64;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  int iStack_50;
  undefined1 auStack_4c [16];
  undefined1 auStack_3c [40];
  undefined4 uStack_14;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ca8e8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_00741db0(&iStack_5c,0);
  uVar7 = param_1[0xe];
  iVar1 = param_1[0xe];
  uStack_70 = uVar7 >> 8 & 0xff;
  iVar3 = param_1[0xd];
  if (iVar3 == 0) {
    func_0x00868610();
    iVar3 = FUN_007537e0();
  }
  iStack_64 = iStack_64 + param_1[0x18];
  iStack_60 = iStack_60 + param_1[0x19];
  piVar8 = (int *)0x0;
  if ((0 < param_1[0x16]) && (0 < param_1[0x17])) {
    piVar8 = (int *)(**(code **)(*param_1 + 0x20))(auStack_4c);
    iStack_5c = *piVar8 + param_1[0x18];
    iStack_54 = piVar8[2] + param_1[0x18];
    iStack_58 = piVar8[1] + param_1[0x19];
    iStack_50 = piVar8[3] + param_1[0x19];
    piVar8 = &iStack_5c;
  }
  if ((char)param_1[0x27] == '\0') {
    if ((param_1[0x1c] == 2) || (param_1[0x1c] == 1)) {
      func_0x007397b0(iVar3,param_1[0x1d],&stack0xffffff88,auStack_68,auStack_6c,3,0);
      if (param_1[0x1c] == 1) {
        iVar6 = param_1[0x16] / 2 - iVar3 / 2;
      }
      else {
        iVar6 = param_1[0x16] - iVar3;
      }
      iStack_64 = iStack_64 + iVar6;
    }
    swprintf(auStack_3c,0x981468,uVar7 >> 0x10 & 0xff,uStack_70,(char)iVar1);
    puVar4 = (undefined4 *)func_0x004cd770(&uStack_70,auStack_3c,param_1 + 0x1d);
    uStack_c = 0;
    cVar2 = func_0x007398e0(iVar3,iStack_64,iStack_60,*puVar4,piVar8,0,0,3,0,0,0,0,0,1,param_1[10],0
                            ,0,1);
    uStack_c = 0xffffffff;
    FUN_00765200();
    if (cVar2 == '\0') {
      uVar5 = func_0x00739700(0xd5,1,0x981a00);
      *unaff_FS_OFFSET = uStack_14;
      return uVar5;
    }
  }
  else if (0 < param_1[0x2a]) {
    func_0x007397b0(iVar3,param_1[0x1d],&stack0xffffff88,auStack_6c,&stack0xffffff8c,0,0);
    if ((param_1[0x28] < -iVar3) &&
       (iVar3 = param_1[0x2a], param_1[0x2a] = iVar3 + -1, 0 < iVar3 + -1)) {
      param_1[0x28] = param_1[0x16];
    }
    iVar3 = GetTickCount();
    uVar7 = (uint)((iVar3 - param_1[0x29]) * param_1[0x2b]) / 1000;
    if (uVar7 != 0) {
      param_1[0x29] = iVar3;
      param_1[0x28] = param_1[0x28] - uVar7;
    }
    iStack_64 = iStack_64 + param_1[0x28];
    iVar3 = param_1[10];
    func_0x0073bcd0(iStack_64,iStack_60,param_1[0x1d],param_1[0xe],piVar8,
                    CONCAT31((int3)((uint)iVar3 >> 8),iVar3 != 0),iVar3 << 0x18,0,0xffffffff);
  }
  *unaff_FS_OFFSET = uStack_14;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00745200 | Classified: AngelicaUI::proc_745200 */
/* ==================================================================== */

undefined4 __fastcall FUN_00745200(int param_1)

{
  return CONCAT31((int3)((uint)*(int *)(param_1 + 0xa8) >> 8),0 < *(int *)(param_1 + 0xa8));
}


/* ==================================================================== */
/* Address: 0x00745210 | Classified: AngelicaUI::proc_745210 */
/* ==================================================================== */

void __thiscall FUN_00745210(int param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_1 + 0x9c) = param_2;
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(param_1 + 0xa8) = param_3;
  *(undefined4 *)(param_1 + 0xac) = param_4;
  uVar1 = GetTickCount();
  *(undefined4 *)(param_1 + 0xa4) = uVar1;
  return;
}


/* ==================================================================== */
/* Address: 0x00745250 | Classified: AngelicaUI::proc_745250 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_00745250(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ca924;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_00741960();
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x3a] = _DAT_009858e4;
  uStack_4 = 2;
  *param_1 = &UNK_008eef74;
  param_1[0xf] = 7;
  *(undefined1 *)((int)param_1 + 0x9d) = 0;
  *(undefined1 *)((int)param_1 + 0x9e) = 0;
  param_1[0x28] = 0;
  *(undefined1 *)(param_1 + 0x2f) = 0;
  param_1[0x2c] = 0;
  param_1[0x30] = 0;
  uVar1 = GetTickCount();
  param_1[0x31] = uVar1;
  param_1[0x33] = 1;
  param_1[0x32] = 1;
  param_1[0x2e] = 0;
  param_1[0x2b] = 0;
  param_1[0x2a] = 0;
  param_1[0x29] = 0;
  param_1[0xd] = 0;
  param_1[9] = 10;
  param_1[0xe] = 0xff000000;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  puVar3 = param_1 + 0x4f;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  func_0x007638a0(0x96ebb8);
  param_1[0x39] = 0;
  puVar3 = param_1 + 0x43;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  puVar3 = param_1 + 0x3b;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  param_1[0x4c] = 0;
  *(undefined1 *)(param_1 + 0x4b) = 0;
  param_1[0x10] = 0;
  *(undefined1 *)(param_1 + 0x27) = 0;
  *unaff_FS_OFFSET = param_1;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00745390 | Classified: AUIListBox::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_00745390(undefined4 param_1,byte param_2)

{
  FUN_007453b0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007453b0 | Classified: AngelicaUI::proc_7453b0 */
/* ==================================================================== */

void __fastcall FUN_007453b0(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *unaff_FS_OFFSET;
  uint uStack_14;
  undefined4 uStack_c;
  undefined *puStack_8;
  uint uStack_4;
  
  puStack_8 = &UNK_008ca96f;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008eef74;
  uStack_4 = 1;
  func_0x007637f0();
  uStack_14 = param_1[0x35];
  uStack_4 = uStack_4 & 0xffffff00;
  uVar1 = uStack_14 + param_1[0x38] * 0x98;
  if (uStack_14 != uVar1) {
    uVar3 = uVar1;
    uVar4 = uStack_14;
    if (uVar1 < (uint)param_1[0x36]) {
      do {
        FUN_00749440(uVar3);
        uVar3 = uVar3 + 0x98;
        uVar4 = uVar4 + 0x98;
      } while (uVar3 < (uint)param_1[0x36]);
    }
    if (uVar4 < (uint)param_1[0x36]) {
      do {
        uStack_4 = CONCAT31(uStack_4._1_3_,4);
        func_0x00892d40(uVar4 + 0x80,4,6,0x7637f0);
        uStack_14 = CONCAT31(uStack_14._1_3_,3);
        func_0x00892d40(uVar4 + 0x68,4,6,0x7637f0);
        FUN_00765200();
        FUN_00765200();
        uVar4 = uVar4 + 0x98;
      } while (uVar4 < (uint)param_1[0x36]);
    }
    iVar2 = (int)(uVar1 - uStack_14) / 0x98;
    param_1[0x36] = param_1[0x36] + iVar2 * -0x98;
    param_1[0x38] = param_1[0x38] - iVar2;
  }
  if (param_1[0x35] != 0) {
    func_0x00763260(param_1[0x35]);
  }
  uStack_4 = 0xffffffff;
  FUN_00741b50();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x00745f90 | Classified: elementclient::AUIListBox__BuildColumnsInfo____f@0x745f90 */
/* ==================================================================== */

undefined1 __thiscall FUN_00745f90(int param_1,char *param_2)

{
  char cVar1;
  undefined1 uVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 *unaff_FS_OFFSET;
  char acStack_82c [2052];
  uint uStack_28;
  uint uStack_24;
  undefined4 uStack_18;
  uint uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ca9e6;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  func_0x00773160();
  uVar3 = 0xffffffff;
  pcVar4 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uStack_4 = 0;
  cVar1 = func_0x00773220(param_2,~uVar3 - 1,0);
  if (cVar1 == '\0') {
    uVar2 = func_0x00739700(0x105,1,0x981cf4);
    uStack_10 = 0xffffffff;
    func_0x007731c0();
  }
  else {
    func_0x0076f270();
    uStack_10 = CONCAT31(uStack_10._1_3_,1);
    cVar1 = func_0x0076f2c0(&stack0xfffff5a4);
    if (cVar1 == '\0') {
      uVar2 = func_0x00739700(0x109,1,0x981c9c);
      uStack_14 = uStack_14 & 0xffffff00;
      func_0x0076f2b0();
      uStack_14 = 0xffffffff;
      func_0x007731c0();
    }
    else {
      *(undefined4 *)(param_1 + 0xe4) = 0;
      if (uStack_24 < uStack_28) {
        do {
          if ((7 < *(int *)(param_1 + 0xe4)) || (cVar1 = func_0x0076f4a0(1), cVar1 == '\0')) break;
          if (acStack_82c[0] == '+') {
            *(undefined4 *)(param_1 + 0xec + *(int *)(param_1 + 0xe4) * 4) = 1;
          }
          else if (acStack_82c[0] == '-') {
            *(undefined4 *)(param_1 + 0xec + *(int *)(param_1 + 0xe4) * 4) = 2;
          }
          uVar3 = atoi(acStack_82c);
          *(uint *)(param_1 + 0x10c + *(int *)(param_1 + 0xe4) * 4) =
               (uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f);
          *(int *)(param_1 + 0xe4) = *(int *)(param_1 + 0xe4) + 1;
        } while (uStack_24 < uStack_28);
      }
      func_0x0076f450();
      func_0x00773280();
      uStack_14 = uStack_14 & 0xffffff00;
      func_0x0076f2b0();
      uStack_14 = 0xffffffff;
      func_0x007731c0();
      uVar2 = 1;
    }
  }
  *unaff_FS_OFFSET = uStack_18;
  return uVar2;
}


/* ==================================================================== */
/* Address: 0x00746ea0 | Classified: AUIListBox::vfunc_slot_6 */
/* ==================================================================== */

undefined4 __fastcall FUN_00746ea0(int param_1)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  float fVar4;
  char cVar5;
  byte bVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  int iVar15;
  int iVar16;
  int unaff_EDI;
  int iVar17;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_100;
  int iStack_ec;
  int iStack_e8;
  int iStack_dc;
  int iStack_d4;
  int iStack_d0;
  int iStack_cc;
  int iStack_c8;
  int iStack_c4;
  int iStack_c0;
  uint uStack_bc;
  int iStack_b4;
  int iStack_b0;
  int iStack_ac;
  int iStack_a8;
  int iStack_a4;
  int iStack_a0;
  int iStack_9c;
  int iStack_98;
  int iStack_90;
  undefined4 uStack_8c;
  int iStack_88;
  undefined1 auStack_78 [4];
  int iStack_74;
  int iStack_70;
  int iStack_6c;
  int iStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined1 auStack_58 [16];
  undefined1 auStack_48 [28];
  undefined4 uStack_2c;
  undefined1 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008caa0b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_00741db0(&iStack_9c);
  iVar12 = 0;
  if (*(int *)(param_1 + 0x134) != 0) {
    FUN_007537a0(&iStack_74);
    iVar12 = iStack_70 / 2;
  }
  iStack_a4 = iStack_a4 + *(int *)(param_1 + 0x60);
  iStack_a8 = *(int *)(param_1 + 0x34);
  iStack_a0 = iStack_a0 + *(int *)(param_1 + 100);
  if (iStack_a8 == 0) {
    func_0x00868610();
    iStack_a8 = FUN_007537e0();
  }
  iVar7 = func_0x0073c830(&iStack_74,0x981774,0xffffffff);
  iVar15 = *(int *)(param_1 + 0xcc);
  iVar7 = *(int *)(iVar7 + 4);
  if (1 < iVar15) {
    iVar7 = iVar15;
  }
  iStack_d0 = 0;
  iStack_d4 = 0;
  iVar11 = *(int *)(param_1 + 0x5c);
  if (*(int *)(param_1 + 0xb8) == 0) {
    uStack_bc = (iVar11 + iVar12 * -2) / iVar7;
  }
  else {
    iStack_d0 = (iVar11 + iVar12 * -2) / iVar15 + 1;
    iStack_d4 = (*(int *)(param_1 + 0x58) + iStack_ec * -2) / *(int *)(param_1 + 200);
    uStack_bc = iStack_d4 * iStack_d0;
  }
  iStack_cc = 0;
  iStack_c8 = 0;
  iStack_c4 = 0;
  iStack_c0 = 0;
  iStack_98 = 0;
  iStack_90 = 0;
  iStack_88 = 0;
  if (*(int *)(param_1 + 0x14c) != 0) {
    iVar15 = 0;
    if ((*(char *)(param_1 + 0x9c) != '\0') || (uStack_bc < *(uint *)(param_1 + 0xe0))) {
      iVar15 = **(int **)(*(int *)(param_1 + 0x14c) + 0x24);
      iStack_98 = *(int *)(iVar15 + 8);
      iStack_90 = *(int *)(iVar15 + 0x10);
      iVar15 = iStack_90 - iStack_98;
    }
    iStack_c0 = (iVar11 - iVar12) + iStack_ac;
    iStack_c8 = iStack_ac + iVar12;
    iStack_cc = iStack_ec + iStack_b0;
    iStack_c4 = ((*(int *)(param_1 + 0x58) - iVar15) - iStack_ec) + iStack_b0;
    if (*(int *)(param_1 + 0xb8) == 1) {
      iStack_68 = iStack_c0 - iStack_c8;
      uStack_64 = 0;
      uStack_60 = 0x3f800000;
      iStack_74 = iStack_cc;
      iStack_70 = iStack_c8;
      iStack_6c = iStack_c4 - iStack_cc;
      func_0x00786eb0(&iStack_74);
      uStack_8c = *(undefined4 *)(*(int *)(param_1 + 4) + 0xa8);
      func_0x00786f70();
      if (0 < iVar15) {
        iStack_d4 = (iStack_c4 - iStack_cc) / *(int *)(param_1 + 200);
        uStack_bc = iStack_d4 * iStack_d0;
      }
    }
  }
  if (*(int *)(param_1 + 0x138) != 0) {
    cVar5 = func_0x00784480();
    if (cVar5 == '\0') {
      uVar8 = func_0x00739700(0x327,1,0x981eec);
      goto LAB_00747a19;
    }
    func_0x00868610();
    FUN_007310f0();
    func_0x0075ec80();
  }
  if (*(int *)(param_1 + 0x134) == 0) {
    bVar6 = FUN_00430850();
  }
  else {
    iVar12 = *(int *)(param_1 + 0x58);
    if ((int)uStack_bc < unaff_EDI) {
      iVar12 = (iVar12 - iStack_90) + iStack_98;
    }
    bVar6 = FUN_007530d0(iStack_b0,iStack_ac,iVar12,*(undefined4 *)(param_1 + 0x5c),0,0,0x9b3c40,0,0
                         ,0,*(undefined4 *)(param_1 + 0x84),
                         *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x62),
                         *(undefined4 *)(param_1 + 0x28));
  }
  uStack_100 = (uint)bVar6 << 0x18;
  if (bVar6 == 0) {
    uVar8 = func_0x00739700(0x335,1,0x981e94);
  }
  else {
    iVar12 = *(int *)(param_1 + 0x140);
    if ((*(int *)(param_1 + 0xe0) != 0) && (iVar12 != 0)) {
      fVar4 = (float)(iStack_c4 - iStack_cc) / (float)*(int *)(iVar12 + 0x34);
      if (*(int *)(param_1 + 0xb8) == 1) {
        fVar4 = (float)*(int *)(param_1 + 200) / (float)*(int *)(iVar12 + 0x34);
      }
      *(float *)(iVar12 + 0x70) = fVar4;
      *(float *)(iVar12 + 0x74) = (float)iVar7 / (float)*(int *)(iVar12 + 0x38);
      *(uint *)(iVar12 + 0x6c) =
           *(int *)(param_1 + 0x84) << 0x18 | *(uint *)(iVar12 + 0x6c) & 0xffffff;
    }
    iStack_ec = *(int *)(param_1 + 0xc0);
    iStack_dc = 0;
    iVar15 = iStack_ec + -1 + uStack_bc;
    iStack_e8 = iStack_c8;
    if ((*(int *)(param_1 + 0xe0) <= iVar15) &&
       (iVar15 = *(int *)(param_1 + 0xe0) + -1, *(int *)(param_1 + 0xb8) == 0)) {
      iVar11 = (iVar15 - uStack_bc) + 1;
      *(int *)(param_1 + 0xc0) = iVar11;
      if (iVar11 < 0) {
        *(undefined4 *)(param_1 + 0xc0) = 0;
      }
      iStack_ec = *(int *)(param_1 + 0xc0);
    }
    *(undefined4 *)(param_1 + 0xa0) = 0;
    if (iStack_ec <= iVar15) {
      iVar13 = iStack_ec * 0x98;
      iVar11 = iStack_ec;
      iVar16 = iStack_c8;
      do {
        if (*(int *)(param_1 + 0xb8) == 0) {
          if (iStack_ec < iVar11) {
            iVar16 = iVar16 + *(int *)(*(int *)(param_1 + 0xd4) + -0x94 + iVar13) * iVar7;
            iStack_e8 = iVar16;
          }
          if (*(char *)(param_1 + 300) == '\0') {
LAB_00747336:
            if (iVar11 == *(int *)(param_1 + 0xb0)) {
LAB_00747348:
              if (*(char *)(param_1 + 0x9e) != '\0') {
                fVar4 = (float)(*(int *)(*(int *)(param_1 + 0xd4) + 4 + iVar13) * iVar7);
                if ((float)(iStack_c0 - iVar16) <= fVar4) {
                  fVar4 = (float)(iStack_c0 - iVar16);
                }
                *(float *)(iVar12 + 0x74) = fVar4 / (float)*(int *)(iVar12 + 0x38);
              }
              if (iVar12 != 0) {
                if (*(char *)(*(int *)(param_1 + 0xc) + 0x62) == '\0') {
                  bVar6 = func_0x0078c490((float)iStack_cc,(float)iStack_e8);
                }
                else {
                  bVar6 = func_0x0078c3a0();
                }
                uStack_100 = (uint)bVar6 << 0x18;
                if (bVar6 == 0) {
                  uVar8 = func_0x00739700(0x374,1,0x981dfc);
                  goto LAB_00747a19;
                }
              }
            }
          }
          else {
            if (*(char *)(*(int *)(param_1 + 0xd4) + 8 + iVar13) != '\0') goto LAB_00747348;
            if (*(char *)(param_1 + 300) == '\0') goto LAB_00747336;
          }
          iVar17 = iStack_cc;
          if (*(int *)(iVar13 + 0x2c + *(int *)(param_1 + 0xd4)) != 0) {
            if (*(char *)(*(int *)(param_1 + 0xc) + 0x62) == '\0') {
              bVar6 = func_0x0078c490((float)(*(int *)(param_1 + 200) / 0x14 + iStack_cc),
                                      (float)(*(int *)(param_1 + 0xcc) / 0x14 + iVar16));
            }
            else {
              bVar6 = func_0x0078c3a0();
            }
            uStack_100 = (uint)bVar6 << 0x18;
            if (bVar6 == 0) {
              uVar8 = func_0x00739700(0x382,1,0x981d88,iVar11,iVar11);
              goto LAB_00747a19;
            }
            iVar17 = *(int *)(param_1 + 200) + iStack_cc;
          }
          *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + 1;
          if (*(int *)(param_1 + 0xe4) < 2) {
            iStack_a8 = iVar17;
            iStack_a4 = iVar16;
            if (*(char *)(param_1 + 0x9e) == '\0') {
              *(undefined4 *)(iVar13 + 4 + *(int *)(param_1 + 0xd4)) = 1;
              iStack_a0 = ((iStack_c4 - *(int *)(param_1 + 200)) - iStack_cc) + iVar17;
              iStack_9c = iVar7 + iVar16;
              iVar9 = *(int *)(param_1 + 0x28);
              puVar10 = (undefined4 *)(*(int *)(param_1 + 0xd4) + iVar13);
              func_0x0073bcd0(iVar17,iVar16,*puVar10,puVar10[3],&iStack_a8,
                              CONCAT31((int3)((uint)iVar9 >> 8),iVar9 != 0),iVar9 << 0x18,0,
                              0xffffffff);
            }
            else {
              iStack_a0 = iStack_c4;
              puVar2 = (uint *)(iVar13 + 0xc + *(int *)(param_1 + 0xd4));
              iStack_9c = iStack_c0;
              uVar3 = *puVar2;
              swprintf(auStack_48,0x981468,uVar3 >> 0x10 & 0xff,uVar3 >> 8 & 0xff,(char)*puVar2);
              puVar10 = (undefined4 *)
                        func_0x004cd770(auStack_78,auStack_48,iVar13 + *(int *)(param_1 + 0xd4));
              uStack_18 = 2;
              bVar6 = func_0x007398e0(iStack_b4,iVar17,iVar16,*puVar10,&iStack_a8,0,
                                      iVar13 + 4 + *(int *)(param_1 + 0xd4),0,1,0,0,0,0,1,
                                      *(undefined4 *)(param_1 + 0x28),0,0,1);
              uStack_100 = (uint)bVar6 << 0x18;
              uStack_18 = 0xffffffff;
              FUN_00765200();
              if (bVar6 == 0) {
                uVar8 = func_0x00739700(0x3b3,1,0x981d4c);
                goto LAB_00747a19;
              }
              iStack_dc = iStack_dc + *(int *)(iVar13 + 4 + *(int *)(param_1 + 0xd4));
              if ((iStack_c0 - iStack_c8) / iVar7 <= iStack_dc) break;
            }
          }
          else {
            FUN_00744150(*(undefined4 *)(iVar13 + *(int *)(param_1 + 0xd4)));
            uStack_1c = 0;
            FUN_00744590(&iStack_9c,0x95bc1c);
            uStack_24 = 1;
            iVar9 = *(int *)(param_1 + 0xe4);
            if (iStack_98 <= *(int *)(param_1 + 0xe4)) {
              iVar9 = iStack_98;
            }
            if (0 < iVar9) {
              uStack_100 = iStack_dc + 0xc;
              iStack_c4 = -0xec - param_1;
              piVar14 = (int *)(param_1 + 0xec);
              do {
                iVar11 = iVar17;
                iStack_ac = piVar14[8] + iVar11;
                iStack_a8 = iStack_ec + iVar16;
                iStack_b4 = iVar11;
                iStack_b0 = iVar16;
                if ((*piVar14 == 2) || (iVar13 = iVar11, *piVar14 == 1)) {
                  func_0x007397b0(iStack_c0,*(undefined4 *)((int)piVar14 + iStack_a4 + iStack_c4),
                                  &iStack_90,&uStack_8c,auStack_58,0,0);
                  if (*piVar14 == 1) {
                    iVar13 = iVar11 + ((iStack_ac - iStack_b4) / 2 - iStack_90 / 2);
                  }
                  else {
                    iVar13 = iVar11 + ((iStack_ac - iStack_90) - iStack_b4);
                  }
                }
                iVar17 = *(int *)(param_1 + 0x28);
                func_0x0073bcd0(iVar13,iVar16,*(undefined4 *)((int)piVar14 + iStack_a4 + iStack_c4),
                                *(undefined4 *)(uStack_100 + *(int *)(param_1 + 0xd4)),&iStack_b4,
                                CONCAT31((int3)((uint)iVar17 >> 8),iVar17 != 0),iVar17 << 0x18,0,
                                0xffffffff);
                piVar1 = piVar14 + 8;
                piVar14 = piVar14 + 1;
                uStack_100 = uStack_100 + 4;
                iVar9 = iVar9 + -1;
                iVar13 = iStack_dc;
                iVar17 = *piVar1 + iVar11;
              } while (iVar9 != 0);
            }
            uStack_24 = 0;
            *(undefined4 *)(iVar13 + 4 + *(int *)(param_1 + 0xd4)) = 1;
            func_0x004bfa20(iStack_a4,iStack_a4 + iStack_98 * 4);
            if (iStack_ac != 0) {
              func_0x00763260(iStack_ac);
            }
            uStack_2c = 0xffffffff;
            FUN_007441c0();
          }
        }
        else {
          if (*(char *)(param_1 + 300) == '\0') {
LAB_0074781d:
            if (iVar11 == *(int *)(param_1 + 0xb0)) {
LAB_00747825:
              iVar16 = ((iVar11 - iStack_ec) / iStack_d4) * *(int *)(param_1 + 0xcc) + iStack_c8;
              iStack_e8 = iVar16;
              if (iVar12 != 0) {
                bVar6 = func_0x0078c3a0((float)(((iVar11 - iStack_ec) % iStack_d4) *
                                                *(int *)(param_1 + 200) + iStack_cc),(float)iVar16);
                uStack_100 = (uint)bVar6 << 0x18;
                if (bVar6 == 0) {
                  uVar8 = func_0x00739700(0x3d1,1,0x981dfc);
                  goto LAB_00747a19;
                }
              }
            }
          }
          else {
            if (*(char *)(*(int *)(param_1 + 0xd4) + 8 + iVar13) != '\0') goto LAB_00747825;
            if (*(char *)(param_1 + 300) == '\0') goto LAB_0074781d;
          }
          if (*(int *)(*(int *)(param_1 + 0xd4) + 0x2c + iVar13) != 0) {
            iVar16 = *(int *)(param_1 + 0xcc) / 0x14 +
                     iStack_c8 + ((iVar11 - iStack_ec) / iStack_d4) * *(int *)(param_1 + 0xcc);
            bVar6 = func_0x0078c3a0((float)(*(int *)(param_1 + 200) / 0x14 +
                                           iStack_cc +
                                           ((iVar11 - iStack_ec) % iStack_d4) *
                                           *(int *)(param_1 + 200)),(float)iVar16);
            uStack_100 = (uint)bVar6 << 0x18;
            iStack_e8 = iVar16;
            if (bVar6 == 0) {
              uVar8 = func_0x00739700(0x3de,1,0x981d88,iVar11,iVar11);
              goto LAB_00747a19;
            }
          }
        }
        iVar11 = iVar11 + 1;
        iVar13 = iVar13 + 0x98;
        bVar6 = uStack_100._3_1_;
      } while (iVar11 <= iVar15);
    }
    uStack_100._3_1_ = bVar6;
    if (iStack_88 != 0) {
      func_0x00786f70();
    }
    if ((*(char *)(param_1 + 0x9c) != '\0') || (uStack_bc < *(uint *)(param_1 + 0xe0))) {
      uStack_100._3_1_ = FUN_00747a40();
    }
    if (uStack_100._3_1_ == 0) {
      uVar8 = func_0x00739700(999,1,0x981e60);
    }
    else {
      uVar8 = 1;
    }
  }
LAB_00747a19:
  *unaff_FS_OFFSET = uStack_20;
  return uVar8;
}


/* ==================================================================== */
/* Address: 0x00747a40 | Classified: elementclient::AUIListBox__RenderScroll____fail@0x747a40 */
/* ==================================================================== */

undefined4 __fastcall FUN_00747a40(int param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  char cVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int unaff_EBX;
  int iVar9;
  int iVar10;
  int unaff_ESI;
  float fVar11;
  undefined1 *puVar12;
  int iStack_64;
  int iStack_60;
  undefined1 auStack_58 [4];
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  undefined4 uStack_44;
  int iStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  undefined4 uStack_30;
  undefined4 uStack_24;
  undefined4 uStack_1c;
  int iStack_18;
  
  iVar9 = 0;
  if (((*(int *)(param_1 + 0x144) != 0) && (*(int *)(param_1 + 0x148) != 0)) &&
     (*(int *)(param_1 + 0x14c) != 0)) {
    FUN_00741db0(&iStack_48);
    iVar7 = *(int *)(param_1 + 0xe0);
    if (*(int *)(param_1 + 0x134) != 0) {
      iVar9 = FUN_007537e0();
      iVar9 = *(int *)(iVar9 + 0x34) / 3;
    }
    iVar10 = **(int **)(*(int *)(param_1 + 0x144) + 0x24);
    uStack_24 = *(undefined4 *)(iVar10 + 0xc);
    uStack_1c = *(undefined4 *)(iVar10 + 0x14);
    iVar10 = **(int **)(*(int *)(param_1 + 0x148) + 0x24);
    uStack_44 = *(undefined4 *)(iVar10 + 0xc);
    iStack_3c = *(int *)(iVar10 + 0x14);
    iVar10 = **(int **)(*(int *)(param_1 + 0x14c) + 0x24);
    iStack_34 = *(int *)(iVar10 + 0xc);
    uStack_38 = *(undefined4 *)(iVar10 + 8);
    uStack_30 = *(undefined4 *)(iVar10 + 0x10);
    iVar10 = *(int *)(iVar10 + 0x14);
    iStack_18 = iStack_50 + iVar9;
    iStack_50 = iStack_50 + *(int *)(param_1 + 0x60);
    iStack_4c = iStack_4c + *(int *)(param_1 + 100);
    if (*(int *)(param_1 + 0x34) == 0) {
      func_0x00868610();
      FUN_007537e0();
    }
    puVar12 = auStack_58;
    iVar9 = 0x981774;
    func_0x0073c830(puVar12,0x981774,0xffffffff);
    iStack_64 = 0;
    if (*(int *)(param_1 + 0xb8) != 0) {
      iStack_64 = *(int *)(param_1 + 0x5c) / *(int *)(param_1 + 0xcc);
    }
    uVar5 = (uint)(*(int *)(param_1 + 0x40) == 1);
    cVar4 = func_0x0078c4e0();
    if (cVar4 == '\0') {
      uVar6 = func_0x00739700(0x41e,1,0x982208);
      return uVar6;
    }
    iVar1 = **(int **)(*(int *)(param_1 + 0x14c) + 0x24);
    fVar3 = (float)((*(int *)(param_1 + 0x58) - *(int *)(iVar1 + 0x10)) + *(int *)(iVar1 + 8) +
                   iStack_60);
    *(uint *)(*(int *)(param_1 + 0x144) + 0x6c) =
         *(int *)(param_1 + 0x84) << 0x18 | *(uint *)(*(int *)(param_1 + 0x144) + 0x6c) & 0xffffff;
    fVar11 = fVar3;
    if (*(char *)(*(int *)(param_1 + 0xc) + 0x62) == '\0') {
      cVar4 = func_0x0078c490(fVar3,(float)iVar7);
    }
    else {
      cVar4 = func_0x0078c3a0();
    }
    iVar1 = iStack_3c;
    if (cVar4 == '\0') {
      uVar6 = func_0x00739700(0x428,1,0x982170);
      return uVar6;
    }
    iVar2 = **(int **)(*(int *)(param_1 + 0x144) + 0x24);
    iVar9 = iVar9 + (*(int *)(iVar2 + 0x14) - *(int *)(iVar2 + 0xc));
    iVar10 = iVar10 - iStack_4c;
    *(float *)(*(int *)(param_1 + 0x14c) + 0x74) =
         (float)(((iStack_3c - iStack_34) - iStack_54) + iVar7 + *(int *)(param_1 + 0x5c)) /
         (float)iVar10;
    *(uint *)(*(int *)(param_1 + 0x14c) + 0x6c) =
         *(uint *)(*(int *)(param_1 + 0x14c) + 0x6c) & 0xffffff | *(int *)(param_1 + 0x84) << 0x18;
    if (*(char *)(*(int *)(param_1 + 0xc) + 0x62) == '\0') {
      cVar4 = func_0x0078c490(fVar3,(float)iVar9);
    }
    else {
      cVar4 = func_0x0078c3a0();
    }
    if (cVar4 == '\0') {
      uVar6 = func_0x00739700(0x435,1,0x9820d0);
      return uVar6;
    }
    cVar4 = func_0x0078c4e0(*(int *)(param_1 + 0x40) == 2);
    if (cVar4 == '\0') {
      uVar6 = func_0x00739700(0x43a,1,0x982070);
      return uVar6;
    }
    iVar2 = *(int *)(param_1 + 0x5c);
    *(uint *)(*(int *)(param_1 + 0x148) + 0x6c) =
         *(uint *)(*(int *)(param_1 + 0x148) + 0x6c) & 0xffffff | *(int *)(param_1 + 0x84) << 0x18;
    if (*(char *)(*(int *)(param_1 + 0xc) + 0x62) == '\0') {
      cVar4 = func_0x0078c490(fVar3,(float)((iVar2 - iStack_60) + unaff_EBX + unaff_ESI));
    }
    else {
      cVar4 = func_0x0078c3a0();
    }
    if (cVar4 == '\0') {
      uVar6 = func_0x00739700(0x443,1,0x981fd4);
      return uVar6;
    }
    cVar4 = *(char *)(param_1 + 0x9e);
    if (((cVar4 == '\0') && ((int)uVar5 < (int)puVar12)) ||
       ((cVar4 != '\0' && (*(int *)(param_1 + 0xa0) < (int)puVar12)))) {
      iVar2 = *(int *)(param_1 + 0x150);
      iVar8 = (((*(int *)(**(int **)(iVar2 + 0x24) + 0xc) -
                *(int *)(**(int **)(iVar2 + 0x24) + 0x14)) - iStack_48) - unaff_EBX) + iVar1 +
              unaff_ESI + *(int *)(param_1 + 0x5c);
      if (0 < iVar8) {
        *(int *)(param_1 + 0xa4) = (*(int *)(param_1 + 0x58) - iVar7) + iStack_64;
        if (*(int *)(param_1 + 0xb8) == 0) {
          if (cVar4 == '\0') {
            iVar7 = *(int *)(param_1 + 0xc0);
            iVar9 = (int)puVar12 - uVar5;
          }
          else {
            iVar9 = (int)puVar12 - *(int *)(param_1 + 0xa0);
            iVar7 = *(int *)(param_1 + 0xc0);
          }
        }
        else {
          iVar9 = (int)(puVar12 + (int)fVar11 + -1) / (int)fVar11 - iVar9;
          iVar7 = *(int *)(param_1 + 0xc0) / (int)fVar11;
        }
        *(int *)(param_1 + 0xa8) = ((iVar7 * iVar8) / iVar9 - iVar1) + iStack_48;
        *(uint *)(iVar2 + 0x6c) =
             *(int *)(param_1 + 0x84) << 0x18 | *(uint *)(iVar2 + 0x6c) & 0xffffff;
        if (*(char *)(*(int *)(param_1 + 0xc) + 0x62) == '\0') {
          cVar4 = func_0x0078c490((float)(*(int *)(param_1 + 0xa4) + iVar10),
                                  (float)*(int *)(param_1 + 0xa8));
        }
        else {
          cVar4 = func_0x0078c3a0((float)(*(int *)(param_1 + 0xa4) + iVar10),
                                  (float)*(int *)(param_1 + 0xa8));
        }
        if (cVar4 == '\0') {
          uVar6 = func_0x00739700(0x461,1,0x981f3c);
          return uVar6;
        }
      }
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00747fb0 | Classified: AngelicaUI::proc_747fb0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00747fb0(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *unaff_FS_OFFSET;
  uint uVar9;
  undefined4 uStack_d0;
  undefined4 auStack_98 [6];
  undefined4 auStack_80 [2];
  undefined1 auStack_78 [8];
  undefined4 uStack_70;
  undefined4 uStack_58;
  undefined4 auStack_50 [4];
  undefined1 uStack_40;
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [8];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_24;
  undefined1 uStack_18;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008caaa8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_70 = _DAT_00985a98;
  uStack_d0 = 0x7637f0;
  uStack_4 = 1;
  func_0x00892e84(auStack_3c,4,6,&UNK_0057d7b0);
  uStack_18 = 2;
  func_0x00892e84(auStack_38,4,6,&UNK_0057d7b0,0x7637f0);
  uStack_2c = 3;
  FUN_00765230(uStack_24);
  uVar2 = *(undefined4 *)(param_1 + 0x38);
  piVar1 = (int *)(param_1 + 0xd4);
  puVar7 = (undefined4 *)&stack0xffffff3c;
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = uVar2;
    puVar7 = puVar7 + 1;
  }
  puVar7 = auStack_98;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  puVar7 = auStack_80;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  uVar9 = *(uint *)(param_1 + 0xe0);
  if (uVar9 == *(uint *)(param_1 + 0xdc)) {
    if (uVar9 + 1 < 5) {
      iVar4 = 5;
    }
    else {
      iVar4 = uVar9 + 3 + (uVar9 >> 1);
    }
    iVar3 = func_0x00763250(iVar4 * 0x98);
    uVar9 = 0;
    iVar5 = *piVar1;
    iVar8 = iVar3;
    if (*(int *)(param_1 + 0xe0) != 0) {
      do {
        uStack_30._0_1_ = 4;
        iVar6 = iVar5;
        if (iVar8 != 0) {
          iVar6 = iVar5 + 0x98;
          FUN_00749350(iVar5);
        }
        uVar9 = uVar9 + 1;
        uStack_30 = CONCAT31(uStack_30._1_3_,3);
        iVar5 = iVar6;
        iVar8 = iVar8 + 0x98;
      } while (uVar9 < *(uint *)(param_1 + 0xe0));
    }
    uVar9 = 0;
    if (*(int *)(param_1 + 0xe0) != 0) {
      do {
        FUN_00748230();
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(uint *)(param_1 + 0xe0));
    }
    if (*piVar1 != 0) {
      func_0x00763260(*piVar1);
    }
    *(int *)(param_1 + 0xdc) = iVar4;
    *piVar1 = iVar3;
    *(int *)(param_1 + 0xd8) = iVar3 + *(int *)(param_1 + 0xe0) * 0x98;
  }
  uStack_30 = CONCAT31(uStack_30._1_3_,5);
  if (*(int *)(param_1 + 0xd8) != 0) {
    FUN_00749350(&uStack_d0);
  }
  *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + 1;
  *(int *)(param_1 + 0xd8) = *(int *)(param_1 + 0xd8) + 0x98;
  uVar2 = *(undefined4 *)(param_1 + 0xe0);
  uStack_30 = 8;
  func_0x00892d40(auStack_50,4,6,0x7637f0);
  uStack_40 = 7;
  func_0x00892d40(auStack_78,4,6,0x7637f0);
  auStack_50[0] = CONCAT31(auStack_50[0]._1_3_,6);
  FUN_00765200();
  auStack_50[0] = 0xffffffff;
  FUN_00765200();
  *unaff_FS_OFFSET = uStack_58;
  return uVar2;
}


/* ==================================================================== */
/* Address: 0x00748230 | Classified: AngelicaUI::proc_748230 */
/* ==================================================================== */

void __fastcall FUN_00748230(int param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar1;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008caae9;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 2;
  func_0x00892d40(param_1 + 0x80,4,6,0x7637f0);
  uVar1 = 6;
  func_0x00892d40(param_1 + 0x68,4,6,0x7637f0);
  FUN_00765200();
  FUN_00765200();
  *unaff_FS_OFFSET = uVar1;
  return;
}


/* ==================================================================== */
/* Address: 0x007482b0 | Classified: AngelicaUI::proc_7482b0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_007482b0(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *unaff_FS_OFFSET;
  bool bVar10;
  undefined *puStack_d0;
  undefined4 uStack_cc;
  undefined4 auStack_98 [6];
  undefined4 auStack_80 [2];
  undefined1 auStack_78 [8];
  undefined4 uStack_70;
  undefined4 auStack_50 [4];
  undefined1 uStack_40;
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [8];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_20;
  undefined1 uStack_18;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008cabd0;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if ((param_2 < 0) || (*(int *)(param_1 + 0xe0) < param_2)) {
    uVar2 = 0xffffffff;
  }
  else {
    uStack_70 = _DAT_00985a98;
    uStack_cc = 0x7637f0;
    puStack_d0 = &UNK_0057d7b0;
    uStack_4 = 1;
    func_0x00892e84(auStack_3c,4);
    uStack_18 = 2;
    func_0x00892e84(auStack_38,4,6,&UNK_0057d7b0,0x7637f0);
    uStack_2c = 3;
    FUN_00765230(uStack_20);
    uVar2 = *(undefined4 *)(param_1 + 0x38);
    uStack_cc = 0;
    puVar6 = (uint *)(param_1 + 0xd4);
    puVar7 = (undefined4 *)&stack0xffffff3c;
    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar7 = uVar2;
      puVar7 = puVar7 + 1;
    }
    puVar7 = auStack_98;
    for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    puVar7 = auStack_80;
    for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    uVar8 = *puVar6 + param_2 * 0x98;
    uVar9 = *(uint *)(param_1 + 0xe0);
    if (uVar9 == *(uint *)(param_1 + 0xdc)) {
      if (uVar9 + 1 < 5) {
        iVar3 = 5;
      }
      else {
        iVar3 = uVar9 + 3 + (uVar9 >> 1);
      }
      uVar1 = func_0x00763250(iVar3 * 0x98);
      uVar9 = *puVar6;
      uVar5 = uVar1;
      while (uStack_30._1_3_ = (undefined3)((uint)uStack_30 >> 8), uVar9 < uVar8) {
        uVar4 = uVar5 + 0x98;
        bVar10 = uVar5 != 0;
        uStack_30 = CONCAT31(uStack_30._1_3_,4);
        uVar5 = uVar4;
        if (bVar10) {
          FUN_00749350(uVar9);
          uVar9 = uVar9 + 0x98;
        }
      }
      uStack_30._0_1_ = 5;
      if (uVar5 != 0) {
        FUN_00749350(&puStack_d0);
      }
      if (uVar9 < *(uint *)(param_1 + 0xd8)) {
        do {
          uVar5 = uVar5 + 0x98;
          uStack_30._0_1_ = 6;
          uVar8 = uVar9;
          if (uVar5 != 0) {
            uVar8 = uVar9 + 0x98;
            FUN_00749350(uVar9);
          }
          uVar9 = uVar8;
        } while (uVar8 < *(uint *)(param_1 + 0xd8));
      }
      uStack_30._0_1_ = 3;
      uVar8 = 0;
      if (*(int *)(param_1 + 0xe0) != 0) {
        do {
          FUN_0074b7c0(0);
          uVar8 = uVar8 + 1;
        } while (uVar8 < *(uint *)(param_1 + 0xe0));
      }
      if (*puVar6 != 0) {
        func_0x00763260(*puVar6);
      }
      *(int *)(param_1 + 0xdc) = iVar3;
      *puVar6 = uVar1;
      *(uint *)(param_1 + 0xd8) = uVar1 + *(int *)(param_1 + 0xe0) * 0x98;
    }
    else {
      uVar9 = *(uint *)(param_1 + 0xd8);
      if (uVar9 == uVar8) {
        uStack_30 = CONCAT31(uStack_30._1_3_,8);
        if (uVar9 != 0) {
          FUN_00749350(&puStack_d0);
        }
      }
      else {
        uStack_30._0_1_ = 7;
        if (uVar9 != 0) {
          FUN_00749350(uVar9 - 0x98);
        }
        uStack_30 = CONCAT31(uStack_30._1_3_,3);
        uVar9 = *(int *)(param_1 + 0xd8) - 0x98;
        if (uVar8 < uVar9) {
          iVar3 = *(int *)(param_1 + 0xd8) + -0x130;
          do {
            FUN_00749440(iVar3);
            uVar9 = uVar9 - 0x98;
            iVar3 = iVar3 + -0x98;
          } while (uVar8 < uVar9);
        }
        FUN_00749440(&puStack_d0);
      }
    }
    *(int *)(param_1 + 0xd8) = *(int *)(param_1 + 0xd8) + 0x98;
    *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + 1;
    uVar2 = uRam000000e6;
    uStack_30 = 0xb;
    func_0x00892d40(auStack_50,4,6,0x7637f0);
    uStack_40 = 10;
    func_0x00892d40(auStack_78,4,6,0x7637f0);
    auStack_50[0] = CONCAT31(auStack_50[0]._1_3_,9);
    FUN_00765200();
    auStack_50[0] = 0xffffffff;
    FUN_00765200();
  }
  *unaff_FS_OFFSET = uStack_c;
  return uVar2;
}


/* ==================================================================== */
/* Address: 0x00748620 | Classified: AngelicaUI::proc_748620 */
/* ==================================================================== */

undefined4 __thiscall FUN_00748620(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xe0))) {
    if (*(char *)(param_1 + 300) != '\0') {
      FUN_0074b4f0(param_2,0);
    }
    if (param_2 < *(int *)(param_1 + 0xb0)) {
      *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0xb0) + -1;
    }
    if (*(int *)(param_1 + 0xe0) != 0) {
      uVar2 = *(int *)(param_1 + 0xd4) + param_2 * 0x98;
      uVar1 = uVar2;
      if (uVar2 < *(int *)(param_1 + 0xd8) - 0x98U) {
        do {
          FUN_00749440(uVar1 + 0x98);
          uVar2 = uVar2 + 0x98;
          uVar1 = uVar1 + 0x98;
        } while (uVar2 < *(int *)(param_1 + 0xd8) - 0x98U);
      }
      *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + -1;
      *(int *)(param_1 + 0xd8) = *(int *)(param_1 + 0xd8) + -0x98;
      FUN_00748230();
    }
    if (*(uint *)(param_1 + 0xe0) <= *(uint *)(param_1 + 0xb0)) {
      *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xe0) - 1;
    }
    if (*(int *)(param_1 + 0xb0) < 0) {
      *(undefined4 *)(param_1 + 0xb0) = 0;
    }
    return *(undefined4 *)(param_1 + 0xe0);
  }
  return 0xffffffff;
}


/* ==================================================================== */
/* Address: 0x00748720 | Classified: AngelicaUI::proc_748720 */
/* ==================================================================== */

undefined4 __fastcall FUN_00748720(int param_1)

{
  return *(undefined4 *)(param_1 + 0xe0);
}


/* ==================================================================== */
/* Address: 0x00748730 | Classified: AngelicaUI::proc_748730 */
/* ==================================================================== */

undefined4 __fastcall FUN_00748730(int param_1)

{
  return *(undefined4 *)(param_1 + 0xb0);
}


/* ==================================================================== */
/* Address: 0x00748740 | Classified: AngelicaUI::proc_748740 */
/* ==================================================================== */

void __thiscall FUN_00748740(int param_1,int param_2)

{
  if ((-1 < param_2) || (param_2 < *(int *)(param_1 + 0xe0))) {
    *(int *)(param_1 + 0xb0) = param_2;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00748760 | Classified: AngelicaUI::proc_748760 */
/* ==================================================================== */

undefined4 __thiscall FUN_00748760(int param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xe0))) {
    return *(undefined4 *)(*(int *)(param_1 + 0xd4) + param_2 * 0x98);
  }
  return 0x9b3c40;
}


/* ==================================================================== */
/* Address: 0x00748790 | Classified: AngelicaUI::proc_748790 */
/* ==================================================================== */

int __thiscall FUN_00748790(int param_1,int param_2,undefined4 param_3)

{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xe0))) {
    FUN_00765230(param_3);
    return param_2;
  }
  return -1;
}


/* ==================================================================== */
/* Address: 0x007487d0 | Classified: AngelicaUI::proc_7487d0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007487d0(int param_1,int param_2,int param_3)

{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xe0))) {
    return *(undefined4 *)(*(int *)(param_1 + 0xd4) + 0xc + (param_3 + param_2 * 0x26) * 4);
  }
  return 0xff000000;
}


/* ==================================================================== */
/* Address: 0x00748810 | Classified: AngelicaUI::proc_748810 */
/* ==================================================================== */

int __thiscall FUN_00748810(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xe0))) {
    if (param_4 < 0) {
      iVar1 = 0;
      if (0 < *(int *)(param_1 + 0xe4)) {
        iVar2 = param_2 * 0x98 + 0xc;
        do {
          iVar1 = iVar1 + 1;
          *(undefined4 *)(*(int *)(param_1 + 0xd4) + iVar2) = param_3;
          iVar2 = iVar2 + 4;
        } while (iVar1 < *(int *)(param_1 + 0xe4));
      }
      return param_2;
    }
    *(undefined4 *)(*(int *)(param_1 + 0xd4) + 0xc + (param_4 + param_2 * 0x26) * 4) = param_3;
    return param_2;
  }
  return -1;
}


/* ==================================================================== */
/* Address: 0x00748890 | Classified: AngelicaUI::proc_748890 */
/* ==================================================================== */

void __fastcall FUN_00748890(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iStack_14;
  
  uVar2 = *(uint *)(param_1 + 0xd4);
  uVar1 = uVar2 + *(int *)(param_1 + 0xe0) * 0x98;
  if (uVar2 != uVar1) {
    uVar6 = uVar2;
    if (uVar1 < *(uint *)(param_1 + 0xd8)) {
      uVar5 = uVar1;
      do {
        FUN_007652d0(uVar5);
        *(undefined4 *)(uVar6 + 4) = *(undefined4 *)(uVar5 + 4);
        *(undefined1 *)(uVar5 + 8 + (uVar2 - uVar1)) = *(undefined1 *)(uVar5 + 8);
        puVar3 = (undefined4 *)(uVar6 + 0xc);
        iVar7 = uVar5 - uVar6;
        iVar4 = 8;
        do {
          *puVar3 = *(undefined4 *)(iVar7 + (int)puVar3);
          puVar3 = puVar3 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        *(undefined4 *)(uVar6 + 0x2c) = *(undefined4 *)(uVar5 + 0x2c);
        *(undefined4 *)(uVar6 + 0x30) = *(undefined4 *)(uVar5 + 0x30);
        FUN_007652d0(uVar5 + 0x34);
        puVar3 = (undefined4 *)(uVar6 + 0x38);
        iVar4 = 6;
        do {
          *puVar3 = *(undefined4 *)((int)puVar3 + iVar7);
          puVar3 = puVar3 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        puVar3 = (undefined4 *)(uVar6 + 0x50);
        iVar4 = 6;
        do {
          *puVar3 = *(undefined4 *)((int)puVar3 + iVar7);
          puVar3 = puVar3 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        iVar4 = uVar6 + 0x68;
        iStack_14 = 6;
        do {
          func_0x00763940(iVar7 + iVar4);
          iVar4 = iVar4 + 4;
          iStack_14 = iStack_14 + -1;
        } while (iStack_14 != 0);
        iVar4 = uVar6 + 0x80;
        iStack_14 = 6;
        do {
          func_0x00763940(iVar7 + iVar4);
          iVar4 = iVar4 + 4;
          iStack_14 = iStack_14 + -1;
        } while (iStack_14 != 0);
        uVar5 = uVar5 + 0x98;
        uVar6 = uVar6 + 0x98;
      } while (uVar5 < *(uint *)(param_1 + 0xd8));
    }
    if (uVar6 < *(uint *)(param_1 + 0xd8)) {
      do {
        FUN_00748230();
        uVar6 = uVar6 + 0x98;
      } while (uVar6 < *(uint *)(param_1 + 0xd8));
    }
    iVar4 = (int)(uVar1 - uVar2) / 0x98;
    *(int *)(param_1 + 0xd8) = *(int *)(param_1 + 0xd8) + iVar4 * -0x98;
    *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) - iVar4;
  }
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00748a40 | Classified: AngelicaUI::proc_748a40 */
/* ==================================================================== */

bool __thiscall FUN_00748a40(int param_1,int param_2)

{
  return *(char *)(*(int *)(param_1 + 0xd4) + 8 + param_2 * 0x98) != '\0';
}


/* ==================================================================== */
/* Address: 0x00748a70 | Classified: AngelicaUI::proc_748a70 */
/* ==================================================================== */

void __thiscall FUN_00748a70(int param_1,int param_2,int param_3,char param_4)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_2 <= param_3) {
    iVar3 = param_2 * 0x98;
    iVar5 = (param_3 - param_2) + 1;
    do {
      cVar2 = *(char *)(*(int *)(param_1 + 0xd4) + 8 + iVar3);
      pcVar1 = (char *)(*(int *)(param_1 + 0xd4) + 8 + iVar3);
      if (param_4 == '\0') {
        if (cVar2 != '\0') {
          iVar4 = *(int *)(param_1 + 0x130) + -1;
          goto LAB_00748abb;
        }
      }
      else if (cVar2 == '\0') {
        iVar4 = *(int *)(param_1 + 0x130) + 1;
LAB_00748abb:
        *(int *)(param_1 + 0x130) = iVar4;
      }
      iVar3 = iVar3 + 0x98;
      iVar5 = iVar5 + -1;
      *pcVar1 = param_4;
    } while (iVar5 != 0);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00748ae0 | Classified: AngelicaUI::proc_748ae0 */
/* ==================================================================== */

undefined1 __fastcall FUN_00748ae0(int param_1)

{
  return *(undefined1 *)(param_1 + 300);
}


/* ==================================================================== */
/* Address: 0x00748af0 | Classified: AngelicaUI::proc_748af0 */
/* ==================================================================== */

undefined4 __fastcall FUN_00748af0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x130);
}


/* ==================================================================== */
/* Address: 0x00748b00 | Classified: AngelicaUI::proc_748b00 */
/* ==================================================================== */

int __fastcall FUN_00748b00(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int unaff_EBP;
  int unaff_ESI;
  int iVar7;
  undefined1 auStack_2c [8];
  undefined4 uStack_24;
  int iStack_8;
  int iStack_4;
  
  if ((((*(int *)(param_1 + 0x134) == 0) || (*(int *)(param_1 + 0x144) == 0)) ||
      (*(int *)(param_1 + 0x148) == 0)) || (*(int *)(param_1 + 0x14c) == 0)) {
    return -1;
  }
  uStack_24 = *(undefined4 *)(param_1 + 0xe0);
  iVar3 = FUN_007537e0();
  iVar3 = *(int *)(iVar3 + 0x38) / 3;
  if (*(int *)(param_1 + 0x34) == 0) {
    func_0x00868610();
    FUN_007537e0();
  }
  iVar4 = func_0x0073c830(auStack_2c,0x981774,0xffffffff);
  iVar1 = *(int *)(param_1 + 0x5c);
  iVar5 = **(int **)(*(int *)(param_1 + 0x144) + 0x24);
  iVar2 = **(int **)(*(int *)(param_1 + 0x148) + 0x24);
  iVar6 = **(int **)(*(int *)(param_1 + 0x14c) + 0x24);
  iVar7 = *(int *)(param_1 + 0x58) - (*(int *)(iVar6 + 0x10) - *(int *)(iVar6 + 8));
  iVar6 = *(int *)(iVar5 + 0x14) - *(int *)(iVar5 + 0xc);
  iVar5 = (iVar1 - *(int *)(iVar2 + 0x14)) + *(int *)(iVar2 + 0xc);
  if (((unaff_ESI <= iStack_8) && (iStack_8 < iVar7 - unaff_ESI)) &&
     ((unaff_EBP <= iStack_4 && (iStack_4 < iVar1 - iVar3)))) {
    return 0;
  }
  if ((iVar7 <= iStack_8) && (iStack_8 < *(int *)(param_1 + 0x58))) {
    if (iStack_4 < iVar6) {
      return 2;
    }
    if (iStack_4 < iVar5) {
      iVar5 = **(int **)(*(int *)(param_1 + 0x150) + 0x24);
      if (((*(int *)(param_1 + 0xa8) <= iStack_4) &&
          (iStack_4 <= (*(int *)(iVar5 + 0x14) - *(int *)(iVar5 + 0xc)) + *(int *)(param_1 + 0xa8)))
         && (iVar3 <= (iVar1 + iVar3 * -2) / *(int *)(iVar4 + 4))) {
        return 5;
      }
      return 4;
    }
  }
  if (iStack_4 < iVar6) {
    return 2;
  }
  return ((iStack_4 <= iVar5) - 1 & 4) - 1;
}


/* ==================================================================== */
/* Address: 0x00748cf0 | Classified: elementclient::AUIListBox__GetItemDataPtr____da@0x748cf0 */
/* ==================================================================== */

undefined4 __thiscall FUN_00748cf0(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_8 = &UNK_008cabe8;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  if ((((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xe0))) && (-1 < param_3)) && (param_3 < 6))
  {
    param_3 = param_3 + param_2 * 0x26;
    if (*(int *)(*(int *)(param_1 + 0xd4) + 0x50 + param_3 * 4) != 0) {
      cVar2 = func_0x00763c50(*(int *)(param_1 + 0xd4) + 0x80 + param_3 * 4);
      if (cVar2 == '\0') {
        func_0x00739700(0x554,1,0x982264);
      }
    }
    uStack_4 = 0xffffffff;
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xd4) + 0x50 + param_3 * 4);
    func_0x007637f0();
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  uStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}


/* ==================================================================== */
/* Address: 0x00748dd0 | Classified: AngelicaUI::proc_748dd0 */
/* ==================================================================== */

int __thiscall FUN_00748dd0(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 unaff_EBX;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_8 = &UNK_008cac08;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  if ((((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xe0))) && (-1 < param_4)) && (param_4 < 6))
  {
    func_0x00763940(&stack0x00000010);
    puStack_8 = (undefined *)0xffffffff;
    *(int *)(*(int *)(param_1 + 0xd4) + 0x50 + (param_4 + param_2 * 0x26) * 4) = param_2;
    func_0x007637f0();
    *unaff_FS_OFFSET = unaff_EBX;
    return param_2;
  }
  uStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return -1;
}


/* ==================================================================== */
/* Address: 0x00748e90 | Classified: elementclient::AUIListBox__GetItemData____data_n@0x748e90 */
/* ==================================================================== */

undefined4 __thiscall FUN_00748e90(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_8 = &UNK_008cac28;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  if ((((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xe0))) && (-1 < param_3)) && (param_3 < 6))
  {
    param_3 = param_3 + param_2 * 0x26;
    if (*(int *)(*(int *)(param_1 + 0xd4) + 0x38 + param_3 * 4) != 0) {
      cVar2 = func_0x00763c50(*(int *)(param_1 + 0xd4) + 0x68 + param_3 * 4);
      if (cVar2 == '\0') {
        func_0x00739700(0x56c,1,0x982298);
      }
    }
    uStack_4 = 0xffffffff;
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xd4) + 0x38 + param_3 * 4);
    func_0x007637f0();
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  uStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return 0xffffffff;
}


/* ==================================================================== */
/* Address: 0x00748f70 | Classified: AngelicaUI::proc_748f70 */
/* ==================================================================== */

int __thiscall FUN_00748f70(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 unaff_EBX;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_8 = &UNK_008cac48;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  if ((((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xe0))) && (-1 < param_4)) && (param_4 < 6))
  {
    func_0x00763940(&stack0x00000010);
    puStack_8 = (undefined *)0xffffffff;
    *(int *)(*(int *)(param_1 + 0xd4) + 0x38 + (param_4 + param_2 * 0x26) * 4) = param_2;
    func_0x007637f0();
    *unaff_FS_OFFSET = unaff_EBX;
    return param_2;
  }
  uStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return -1;
}


/* ==================================================================== */
/* Address: 0x00749030 | Classified: AngelicaUI::proc_749030 */
/* ==================================================================== */

undefined4 __thiscall FUN_00749030(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  uint *unaff_FS_OFFSET;
  int iStack_b0;
  undefined4 uStack_ac;
  int iStack_a8;
  undefined4 uStack_a4;
  undefined1 uStack_a0;
  undefined4 auStack_9c [6];
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 auStack_7c [6];
  undefined4 auStack_64 [6];
  undefined1 auStack_4c [24];
  undefined1 auStack_34 [32];
  undefined4 uStack_14;
  uint uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  puStack_8 = &UNK_008cac89;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (uint)&uStack_c;
  if ((param_2 < 0) || (iStack_a8 = param_1, iVar1 = FUN_00748720(), iVar1 <= param_2)) {
    uVar4 = 0;
  }
  else {
    param_2 = param_2 * 0x98;
    iVar7 = *(int *)(param_1 + 0xd4) + param_2;
    FUN_00765000(iVar7);
    uStack_a4 = *(undefined4 *)(iVar7 + 4);
    uStack_a0 = *(undefined1 *)(iVar7 + 8);
    puVar2 = (undefined4 *)(iVar7 + 0xc);
    puVar3 = auStack_9c;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    auStack_7c[0] = *(undefined4 *)(iVar7 + 0x2c);
    auStack_7c[1] = *(undefined4 *)(iVar7 + 0x30);
    puStack_8 = (undefined *)0x0;
    FUN_00765000(iVar7 + 0x34);
    uStack_c._0_1_ = 1;
    puVar2 = (undefined4 *)(iVar7 + 0x38);
    puVar3 = auStack_7c + 2;
    for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    iVar1 = 6;
    puVar2 = (undefined4 *)(iVar7 + 0x50);
    puVar3 = auStack_64 + 2;
    for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    iVar5 = iVar7 + 0x68;
    do {
      func_0x00763660(iVar5);
      iVar5 = iVar5 + 4;
      iVar1 = iVar1 + -1;
      uStack_c._0_1_ = 2;
    } while (iVar1 != 0);
    iVar7 = iVar7 + 0x80;
    iVar1 = 6;
    do {
      func_0x00763660(iVar7);
      iVar7 = iVar7 + 4;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    uStack_c = 3;
    iVar1 = iStack_4;
    if (0 < iStack_4) {
      do {
        iVar7 = param_2 + *(int *)(iStack_b0 + 0xd4);
        FUN_007652d0(iVar7 + -0x98);
        *(undefined4 *)(iVar7 + 4) = *(undefined4 *)(iVar7 + -0x94);
        *(undefined1 *)(iVar7 + 8) = *(undefined1 *)(iVar7 + -0x90);
        puVar2 = (undefined4 *)(iVar7 + 0xc);
        iVar8 = (iVar7 + -0x98) - iVar7;
        iVar5 = 8;
        do {
          *puVar2 = *(undefined4 *)((int)puVar2 + iVar8);
          puVar2 = puVar2 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        *(undefined4 *)(iVar7 + 0x2c) = *(undefined4 *)(iVar7 + -0x6c);
        *(undefined4 *)(iVar7 + 0x30) = *(undefined4 *)(iVar7 + -0x68);
        FUN_007652d0(iVar7 + -100);
        puVar2 = (undefined4 *)(iVar7 + 0x38);
        iVar5 = 6;
        do {
          *puVar2 = *(undefined4 *)((int)puVar2 + iVar8);
          puVar2 = puVar2 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        puVar2 = (undefined4 *)(iVar7 + 0x50);
        iVar5 = 6;
        do {
          *puVar2 = *(undefined4 *)((int)puVar2 + iVar8);
          puVar2 = puVar2 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        iVar5 = iVar7 + 0x68;
        iVar6 = 6;
        do {
          func_0x00763940(iVar5 + iVar8);
          iVar5 = iVar5 + 4;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        iVar7 = iVar7 + 0x80;
        iVar5 = 6;
        do {
          func_0x00763940(iVar7 + iVar8);
          iVar7 = iVar7 + 4;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        param_2 = param_2 + -0x98;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    iVar1 = *(int *)(iStack_b0 + 0xd4);
    FUN_007652d0(&uStack_ac);
    puVar3 = &uStack_a4;
    *(undefined4 *)(iVar1 + 4) = uStack_ac;
    *(undefined1 *)(iVar1 + 8) = (undefined1)iStack_a8;
    puVar2 = (undefined4 *)(iVar1 + 0xc);
    iVar7 = 8;
    do {
      uVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      *puVar2 = uVar4;
      puVar2 = puVar2 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    *(undefined4 *)(iVar1 + 0x2c) = uStack_84;
    *(undefined4 *)(iVar1 + 0x30) = uStack_80;
    FUN_007652d0(auStack_7c);
    puVar3 = auStack_7c;
    puVar2 = (undefined4 *)(iVar1 + 0x38);
    iVar7 = 6;
    do {
      uVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      *puVar2 = uVar4;
      puVar2 = puVar2 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    puVar3 = auStack_64;
    puVar2 = (undefined4 *)(iVar1 + 0x50);
    iVar1 = 6;
    do {
      uVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      *puVar2 = uVar4;
      puVar2 = puVar2 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    puVar9 = auStack_4c;
    iVar1 = 6;
    do {
      func_0x00763940(puVar9);
      puVar9 = puVar9 + 4;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    puVar9 = auStack_34;
    iVar1 = 6;
    do {
      func_0x00763940(puVar9);
      puVar9 = puVar9 + 4;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    uStack_14 = 0xffffffff;
    FUN_00748230();
    uVar4 = 1;
  }
  *unaff_FS_OFFSET = uStack_c;
  return uVar4;
}


/* ==================================================================== */
/* Address: 0x00749350 | Classified: AngelicaUI::proc_749350 */
/* ==================================================================== */

int __thiscall FUN_00749350(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_EBX;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cacbb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_00765000(param_2);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined1 *)(param_1 + 8) = *(undefined1 *)(param_2 + 8);
  puStack_8 = (undefined *)0x0;
  puVar2 = (undefined4 *)(param_2 + 0xc);
  puVar4 = (undefined4 *)(param_1 + 0xc);
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_2 + 0x2c);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_2 + 0x30);
  FUN_00765000(param_2 + 0x34);
  uStack_c._0_1_ = 1;
  puVar2 = (undefined4 *)(param_2 + 0x38);
  puVar4 = (undefined4 *)(param_1 + 0x38);
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  iStack_4 = 6;
  puVar2 = (undefined4 *)(param_2 + 0x50);
  puVar4 = (undefined4 *)(param_1 + 0x50);
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  iVar1 = param_1 + 0x68;
  iVar3 = (iVar1 - param_1) + param_2;
  do {
    func_0x00763660(iVar3);
    iVar1 = iVar1 + 4;
    iVar3 = iVar3 + 4;
    iStack_4 = iStack_4 + -1;
    uStack_c._0_1_ = 2;
  } while (iStack_4 != 0);
  param_2 = param_2 + 0x80;
  iVar3 = 6;
  iStack_4 = iVar1;
  do {
    func_0x00763660(param_2);
    param_2 = param_2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *unaff_FS_OFFSET = unaff_EBX;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00749440 | Classified: AngelicaUI::proc_749440 */
/* ==================================================================== */

int __thiscall FUN_00749440(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  FUN_007652d0(param_2);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined1 *)(param_1 + 8) = *(undefined1 *)(param_2 + 8);
  puVar1 = (undefined4 *)(param_1 + 0xc);
  iVar4 = param_2 - param_1;
  iVar2 = 8;
  do {
    *puVar1 = *(undefined4 *)(iVar4 + (int)puVar1);
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_2 + 0x2c);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_2 + 0x30);
  FUN_007652d0(param_2 + 0x34);
  puVar1 = (undefined4 *)(param_1 + 0x38);
  iVar2 = 6;
  do {
    *puVar1 = *(undefined4 *)((int)puVar1 + iVar4);
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined4 *)(param_1 + 0x50);
  iVar2 = 6;
  do {
    *puVar1 = *(undefined4 *)((int)puVar1 + iVar4);
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = param_1 + 0x68;
  iVar3 = 6;
  do {
    func_0x00763940(iVar2 + iVar4);
    iVar2 = iVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar2 = param_1 + 0x80;
  iVar3 = 6;
  do {
    func_0x00763940(iVar2 + iVar4);
    iVar2 = iVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007494f0 | Classified: AngelicaUI::proc_7494f0 */
/* ==================================================================== */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_007494f0(undefined1 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined1 ***pppuVar7;
  undefined1 ***extraout_ECX;
  undefined1 ***extraout_ECX_00;
  undefined1 ***extraout_ECX_01;
  undefined1 ***extraout_ECX_02;
  undefined4 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined *puVar11;
  undefined1 **ppuVar12;
  undefined *puVar13;
  uint *unaff_FS_OFFSET;
  undefined1 ***pppuStack_108;
  undefined1 **ppuStack_104;
  undefined1 *puStack_100;
  undefined4 *puStack_fc;
  undefined4 *puStack_f8;
  undefined1 *puStack_f4;
  undefined4 uStack_f0;
  int iStack_ec;
  undefined *puStack_e8;
  undefined4 uStack_e4;
  undefined1 *puStack_e0;
  undefined1 **ppuStack_dc;
  undefined1 *puStack_d8;
  undefined1 **appuStack_d4 [2];
  undefined4 uStack_b4;
  undefined1 auStack_ac [8];
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 auStack_9c [6];
  undefined4 auStack_84 [4];
  undefined1 auStack_74 [4];
  undefined4 uStack_70;
  undefined1 auStack_6c [8];
  undefined4 auStack_64 [4];
  undefined1 auStack_54 [8];
  undefined4 auStack_4c [4];
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [12];
  undefined4 uStack_2c;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  undefined1 uStack_18;
  uint uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008cad27;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (uint)&uStack_c;
  if (param_4 < 6) {
    uStack_a4 = _DAT_00985a98;
    uStack_70 = _DAT_00985a98;
    appuStack_d4[1] = (undefined1 **)0x7637f0;
    appuStack_d4[0] = (undefined1 **)&UNK_0057d7b0;
    puStack_d8 = (undefined1 *)0x6;
    puStack_e0 = auStack_3c;
    ppuStack_dc = (undefined1 **)0x4;
    uStack_4 = 1;
    uStack_e4 = (undefined1 ****)0x749563;
    func_0x00892e84();
    uStack_e4 = (undefined1 ****)0x7637f0;
    puStack_e8 = &UNK_0057d7b0;
    iStack_ec = 6;
    puStack_f4 = auStack_38;
    uStack_f0 = 4;
    uStack_18 = 2;
    puStack_f8 = (undefined4 *)0x749586;
    func_0x00892e84();
    uStack_2c = 3;
    puVar9 = param_1;
    if (iStack_20 == 0) {
      do {
        uStack_e4 = (undefined1 ****)((uint)uStack_e4 & 0xffffff);
        appuStack_d4[1] = (undefined1 **)0x0;
        if (*(int *)(puVar9 + 0xe0) == 1 || *(int *)(puVar9 + 0xe0) + -1 < 0) break;
        puStack_e0 = (undefined1 *)0x0;
        do {
          ppuVar12 = appuStack_d4[1];
          if (iStack_24 == 0) {
            appuStack_d4[0] = (undefined1 **)&puStack_f8;
            puStack_fc = (undefined4 *)&DAT_009b3c44;
            puStack_100 = (undefined1 *)0x7497c6;
            func_0x007636b0();
            pppuStack_108 = (undefined1 ***)0x7497cf;
            ppuStack_104 = ppuVar12;
            puStack_100 = (undefined1 *)param_4;
            uVar4 = FUN_00748e90();
            uStack_e4 = &pppuStack_108;
            pppuStack_108 = extraout_ECX_01;
            func_0x007636b0(&DAT_009b3c44);
            uVar5 = FUN_00748e90((undefined *)((int)ppuVar12 + 1),param_4);
            if (uVar5 < uVar4) {
LAB_00749841:
              puVar8 = (undefined4 *)(puStack_e0 + *(int *)(puVar9 + 0xd4));
              puStack_fc = (undefined4 *)0x749857;
              puStack_f8 = puVar8;
              FUN_007652d0();
              puVar6 = (undefined4 *)&stack0xffffff3c;
              iVar3 = (int)puVar8 - (int)(appuStack_d4 + 1);
              iVar2 = 8;
              do {
                *puVar6 = *(undefined4 *)(iVar3 + (int)puVar6);
                puVar6 = puVar6 + 1;
                iVar2 = iVar2 + -1;
              } while (iVar2 != 0);
              uStack_a4 = puVar8[0xb];
              puStack_fc = puVar8 + 0xd;
              uStack_a0 = puVar8[0xc];
              puStack_100 = (undefined1 *)0x74989c;
              FUN_007652d0();
              puVar6 = auStack_9c;
              iVar2 = 6;
              do {
                *puVar6 = *(undefined4 *)((int)puVar6 + iVar3);
                puVar6 = puVar6 + 1;
                iVar2 = iVar2 + -1;
              } while (iVar2 != 0);
              puVar6 = auStack_84;
              iVar2 = 6;
              do {
                *puVar6 = *(undefined4 *)((int)puVar6 + iVar3);
                puVar6 = puVar6 + 1;
                iVar2 = iVar2 + -1;
              } while (iVar2 != 0);
              puVar10 = auStack_6c;
              iVar2 = 6;
              do {
                puStack_100 = puVar10 + iVar3;
                ppuStack_104 = (undefined1 **)0x7498db;
                func_0x00763940();
                puVar10 = puVar10 + 4;
                iVar2 = iVar2 + -1;
              } while (iVar2 != 0);
              puVar10 = auStack_54;
              iVar2 = 6;
              do {
                puStack_100 = puVar10 + iVar3;
                ppuStack_104 = (undefined1 **)0x7498f8;
                func_0x00763940();
                puVar10 = puVar10 + 4;
                iVar2 = iVar2 + -1;
              } while (iVar2 != 0);
              ppuStack_dc = (undefined1 **)(puStack_e8 + 0x98);
              puVar13 = (undefined *)(*(int *)(puVar9 + 0xd4) + (int)ppuStack_dc);
              puVar11 = puStack_e8 + *(int *)(puVar9 + 0xd4);
              ppuStack_104 = (undefined1 **)0x74991f;
              puStack_100 = puVar13;
              FUN_007652d0();
              *(undefined4 *)(puVar11 + 4) = *(undefined4 *)(puVar13 + 4);
              puVar11[8] = puVar13[8];
              puVar6 = (undefined4 *)(puVar11 + 0xc);
              iVar3 = (int)puVar13 - (int)puVar11;
              iVar2 = 8;
              do {
                *puVar6 = *(undefined4 *)(iVar3 + (int)puVar6);
                puVar6 = puVar6 + 1;
                iVar2 = iVar2 + -1;
              } while (iVar2 != 0);
              ppuStack_104 = (undefined1 **)(puVar13 + 0x34);
              *(undefined4 *)(puVar11 + 0x2c) = *(undefined4 *)(puVar13 + 0x2c);
              *(undefined4 *)(puVar11 + 0x30) = *(undefined4 *)(puVar13 + 0x30);
              pppuStack_108 = (undefined1 ***)0x74995a;
              FUN_007652d0();
              puVar6 = (undefined4 *)(puVar11 + 0x38);
              iVar2 = 6;
              do {
                *puVar6 = *(undefined4 *)((int)puVar6 + iVar3);
                puVar6 = puVar6 + 1;
                iVar2 = iVar2 + -1;
              } while (iVar2 != 0);
              puVar6 = (undefined4 *)(puVar11 + 0x50);
              iVar2 = 6;
              do {
                *puVar6 = *(undefined4 *)((int)puVar6 + iVar3);
                puVar6 = puVar6 + 1;
                iVar2 = iVar2 + -1;
              } while (iVar2 != 0);
              puVar13 = puVar11 + 0x68;
              iStack_ec = 6;
              do {
                pppuStack_108 = (undefined1 ***)(puVar13 + iVar3);
                func_0x00763940();
                puVar13 = puVar13 + 4;
                iStack_ec = iStack_ec + -1;
              } while (iStack_ec != 0);
              puVar11 = puVar11 + 0x80;
              iVar2 = 6;
              iStack_ec = 0;
              do {
                pppuStack_108 = (undefined1 ***)(puVar11 + iVar3);
                func_0x00763940();
                puVar10 = (undefined1 *)uStack_e4;
                puVar11 = puVar11 + 4;
                iVar2 = iVar2 + -1;
              } while (iVar2 != 0);
              iVar2 = *(int *)(puVar9 + 0xd4);
              pppuStack_108 = &ppuStack_dc;
              FUN_007652d0();
              iVar3 = 8;
              *(undefined1 ***)(puVar10 + iVar2 + 4) = ppuStack_dc;
              puVar10[iVar2 + 8] = puStack_d8._0_1_;
              pppuVar7 = appuStack_d4;
              puVar6 = (undefined4 *)(puVar10 + iVar2 + 0xc);
              do {
                ppuVar12 = *pppuVar7;
                pppuVar7 = pppuVar7 + 1;
                *puVar6 = ppuVar12;
                puVar6 = puVar6 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
              *(undefined4 *)(puVar10 + iVar2 + 0x2c) = uStack_b4;
              *(undefined1 **)(puVar10 + iVar2 + 0x30) = param_1;
              FUN_007652d0(auStack_ac);
              puVar8 = auStack_9c + 2;
              puVar6 = (undefined4 *)(puVar10 + iVar2 + 0x38);
              iVar3 = 6;
              do {
                uVar1 = *puVar8;
                puVar8 = puVar8 + 1;
                *puVar6 = uVar1;
                puVar6 = puVar6 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
              puVar8 = auStack_84 + 2;
              puVar6 = (undefined4 *)(puVar10 + iVar2 + 0x50);
              iVar2 = 6;
              do {
                uVar1 = *puVar8;
                puVar8 = puVar8 + 1;
                *puVar6 = uVar1;
                puVar6 = puVar6 + 1;
                iVar2 = iVar2 + -1;
              } while (iVar2 != 0);
              puVar6 = auStack_64;
              iVar2 = 6;
              do {
                puStack_fc = (undefined4 *)0x749a63;
                puStack_f8 = puVar6;
                func_0x00763940();
                puVar6 = puVar6 + 1;
                iVar2 = iVar2 + -1;
              } while (iVar2 != 0);
              puVar6 = auStack_4c;
              iVar2 = 6;
              do {
                puStack_fc = (undefined4 *)0x749a86;
                puStack_f8 = puVar6;
                func_0x00763940();
                puVar6 = puVar6 + 1;
                iVar2 = iVar2 + -1;
              } while (iVar2 != 0);
              uStack_e4 = (undefined1 ****)CONCAT13(1,(undefined3)uStack_e4);
              param_4 = iStack_1c;
              puVar9 = puStack_d8;
              ppuVar12 = appuStack_d4[1];
            }
          }
          else if (iStack_24 == 1) {
            appuStack_d4[0] = (undefined1 **)&puStack_f8;
            puStack_fc = (undefined4 *)&DAT_009b3c44;
            puStack_100 = (undefined1 *)0x749811;
            func_0x007636b0();
            pppuStack_108 = (undefined1 ***)0x74981a;
            ppuStack_104 = ppuVar12;
            puStack_100 = (undefined1 *)param_4;
            uVar4 = FUN_00748e90();
            uStack_e4 = &pppuStack_108;
            pppuStack_108 = extraout_ECX_02;
            func_0x007636b0(&DAT_009b3c44);
            uVar5 = FUN_00748e90((undefined *)((int)ppuVar12 + 1),param_4);
            if (uVar4 < uVar5) goto LAB_00749841;
          }
          appuStack_d4[1] = (undefined1 **)((int)ppuVar12 + 1);
          puStack_e0 = puStack_e0 + 0x98;
        } while ((int)appuStack_d4[1] < *(int *)(puVar9 + 0xe0) + -1);
      } while (uStack_e4._3_1_ != '\0');
    }
    else if (iStack_20 == 1) {
      do {
        uStack_e4 = (undefined1 ****)((uint)uStack_e4 & 0xffffff);
        ppuStack_dc = (undefined1 **)0x0;
        if (*(int *)(param_1 + 0xe0) == 1 || *(int *)(param_1 + 0xe0) + -1 < 0) break;
        puStack_e0 = (undefined1 *)0x0;
        do {
          ppuVar12 = ppuStack_dc;
          if (iStack_24 == 0) {
            puStack_d8 = (undefined1 *)&puStack_f8;
            puStack_fc = (undefined4 *)&DAT_009b3c44;
            puStack_100 = (undefined1 *)0x7495e2;
            func_0x007636b0();
            pppuStack_108 = (undefined1 ***)0x7495eb;
            ppuStack_104 = ppuVar12;
            puStack_100 = (undefined1 *)param_4;
            iVar2 = FUN_00748e90();
            puStack_e8 = (undefined *)&pppuStack_108;
            pppuStack_108 = extraout_ECX;
            func_0x007636b0(&DAT_009b3c44);
            iVar3 = FUN_00748e90((undefined *)((int)ppuVar12 + 1),param_4);
            if (iVar3 < iVar2) {
LAB_0074965d:
              puVar8 = (undefined4 *)(puStack_e0 + *(int *)(param_1 + 0xd4));
              puStack_fc = (undefined4 *)0x749673;
              puStack_f8 = puVar8;
              FUN_007652d0();
              iVar3 = (int)puVar8 - (int)(appuStack_d4 + 1);
              puVar6 = (undefined4 *)&stack0xffffff3c;
              iVar2 = 8;
              do {
                *puVar6 = *(undefined4 *)(iVar3 + (int)puVar6);
                puVar6 = puVar6 + 1;
                iVar2 = iVar2 + -1;
              } while (iVar2 != 0);
              uStack_a4 = puVar8[0xb];
              puStack_fc = puVar8 + 0xd;
              uStack_a0 = puVar8[0xc];
              puStack_100 = (undefined1 *)0x7496b8;
              FUN_007652d0();
              puVar6 = auStack_9c;
              iVar2 = 6;
              do {
                *puVar6 = *(undefined4 *)((int)puVar6 + iVar3);
                puVar6 = puVar6 + 1;
                iVar2 = iVar2 + -1;
              } while (iVar2 != 0);
              puVar6 = auStack_84;
              iVar2 = 6;
              do {
                *puVar6 = *(undefined4 *)((int)puVar6 + iVar3);
                puVar6 = puVar6 + 1;
                iVar2 = iVar2 + -1;
              } while (iVar2 != 0);
              puVar9 = auStack_6c;
              iVar2 = 6;
              do {
                puStack_100 = puVar9 + iVar3;
                ppuStack_104 = (undefined1 **)0x7496f7;
                func_0x00763940();
                puVar9 = puVar9 + 4;
                iVar2 = iVar2 + -1;
              } while (iVar2 != 0);
              puVar9 = auStack_54;
              iVar2 = 6;
              do {
                puStack_100 = puVar9 + iVar3;
                ppuStack_104 = (undefined1 **)0x749714;
                func_0x00763940();
                puVar9 = puVar9 + 4;
                iVar2 = iVar2 + -1;
              } while (iVar2 != 0);
              puStack_100 = puStack_e8 + *(int *)(param_1 + 0xd4) + 0x98;
              ppuStack_104 = (undefined1 **)0x749735;
              FUN_00749440();
              ppuStack_104 = &puStack_d8;
              pppuStack_108 = (undefined1 ***)0x749749;
              FUN_00749440();
              uStack_e4 = (undefined1 ****)CONCAT13(1,(undefined3)uStack_e4);
              param_4 = iStack_1c;
              ppuVar12 = ppuStack_dc;
            }
          }
          else if (iStack_24 == 1) {
            puStack_d8 = (undefined1 *)&puStack_f8;
            puStack_fc = (undefined4 *)&DAT_009b3c44;
            puStack_100 = (undefined1 *)0x74962d;
            func_0x007636b0();
            pppuStack_108 = (undefined1 ***)0x749636;
            ppuStack_104 = ppuVar12;
            puStack_100 = (undefined1 *)param_4;
            iVar2 = FUN_00748e90();
            puStack_e8 = (undefined *)&pppuStack_108;
            pppuStack_108 = extraout_ECX_00;
            func_0x007636b0(&DAT_009b3c44);
            iVar3 = FUN_00748e90((undefined *)((int)ppuVar12 + 1),param_4);
            if (iVar2 < iVar3) goto LAB_0074965d;
          }
          ppuStack_dc = (undefined1 **)((int)ppuVar12 + 1);
          puStack_e0 = puStack_e0 + 0x98;
        } while ((int)ppuStack_dc < *(int *)(param_1 + 0xe0) + -1);
      } while (uStack_e4._3_1_ != '\0');
    }
    puStack_f8 = (undefined4 *)0x7637f0;
    puStack_fc = (undefined4 *)0x6;
    ppuStack_104 = (undefined1 **)auStack_4c;
    puStack_100 = (undefined1 *)0x4;
    uStack_2c = 6;
    pppuStack_108 = (undefined1 ***)0x749af2;
    func_0x00892d40();
    pppuStack_108 = (undefined1 ***)0x7637f0;
    auStack_3c[0] = 5;
    func_0x00892d40(auStack_74,4,6);
    auStack_4c[0] = CONCAT31(auStack_4c[0]._1_3_,4);
    FUN_00765200();
    auStack_4c[0] = 0xffffffff;
    FUN_00765200();
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  *unaff_FS_OFFSET = uStack_c;
  return uVar1;
}


/* ==================================================================== */
/* Address: 0x00749b60 | Classified: AngelicaUI::proc_749b60 */
/* ==================================================================== */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00749b60(undefined *param_1)

{
  int *piVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int **ppiVar5;
  float **ppfVar6;
  undefined4 *puVar7;
  float fVar8;
  float *pfVar9;
  undefined2 *puVar10;
  int iVar11;
  short *psVar12;
  undefined *puVar13;
  undefined4 unaff_EBX;
  code *pcVar14;
  uint unaff_EBP;
  int iVar15;
  int iVar16;
  int unaff_ESI;
  int iVar17;
  float *pfVar18;
  undefined1 *puVar19;
  int iVar20;
  undefined4 *unaff_FS_OFFSET;
  float *pfStack_144;
  float *pfStack_140;
  float *pfStack_13c;
  float *pfStack_138;
  undefined4 uStack_134;
  undefined *puStack_130;
  float *pfStack_12c;
  undefined4 uStack_128;
  float *pfStack_124;
  float *pfStack_120;
  undefined *puStack_11c;
  int iStack_118;
  undefined1 uStack_104;
  int *apiStack_100 [2];
  float fStack_f8;
  undefined *puStack_f4;
  undefined4 auStack_f0 [4];
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  float *apfStack_d8 [3];
  float fStack_cc;
  undefined4 auStack_c8 [6];
  undefined4 auStack_b0 [4];
  undefined1 auStack_a0 [4];
  float *pfStack_9c;
  undefined1 auStack_98 [8];
  float afStack_90 [4];
  undefined1 auStack_80 [8];
  float afStack_78 [3];
  undefined1 auStack_6c [4];
  undefined1 auStack_68 [4];
  float afStack_64 [4];
  undefined4 uStack_54;
  undefined4 uStack_4c;
  undefined1 uStack_44;
  undefined1 uStack_3c;
  undefined1 uStack_38;
  undefined1 uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  int iStack_24;
  undefined4 uStack_20;
  undefined1 uStack_18;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008cae39;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  apfStack_d8[2] = _DAT_00985a98;
  pfStack_9c = _DAT_00985a98;
  iStack_118 = 0x7637f0;
  puStack_11c = &UNK_0057d7b0;
  pfStack_120 = (float *)0x6;
  uStack_128 = auStack_68;
  pfStack_124 = (float *)0x4;
  uStack_4 = 1;
  pfStack_12c = (float *)0x749bc0;
  puStack_f4 = param_1;
  func_0x00892e84();
  pfStack_12c = (float *)0x7637f0;
  puStack_130 = &UNK_0057d7b0;
  uStack_134 = 6;
  pfStack_13c = afStack_64;
  pfStack_138 = (float *)0x4;
  uStack_18 = 2;
  pfStack_140 = (float *)0x749be3;
  func_0x00892e84();
  uStack_2c = 3;
  switch(uStack_20) {
  case 0:
    iVar11 = *(int *)(param_1 + 0xe0);
    pfStack_140 = (float *)(iVar11 * 4 + 4);
    pfStack_144 = (float *)&UNK_00749c18;
    apiStack_100[1] = (int *)func_0x00763250();
    uStack_2c._0_1_ = 4;
    if (apiStack_100[1] == (int *)0x0) {
      pfStack_12c = (float *)0x0;
    }
    else {
      pfStack_140 = (float *)FUN_00765200;
      pfStack_144 = (float *)&UNK_0056c430;
      pfVar9 = (float *)(apiStack_100[1] + 1);
      *apiStack_100[1] = iVar11;
      func_0x00892e84(pfVar9,4,iVar11);
      pfStack_12c = pfVar9;
    }
    pfStack_120 = _DAT_00985a98;
    iVar11 = 0;
    uStack_2c = CONCAT31(uStack_2c._1_3_,5);
    pcVar14 = _wcsicmp_exref;
    if (0 < *(int *)(param_1 + 0xe0)) {
      iVar15 = 0;
      do {
        pfStack_140 = *(float **)(iVar15 + *(int *)(param_1 + 0xd4));
        pfStack_144 = (float *)&UNK_00749c8e;
        FUN_00744150();
        pfStack_144 = (float *)0x95bc1c;
        uStack_30 = 6;
        FUN_00744590(&stack0xfffffef0);
        uStack_38 = 7;
        if (uStack_28 < unaff_EBP) {
          FUN_007652d0(iStack_118 + uStack_28 * 4);
        }
        else {
          FUN_00765230(0x9b3c40);
        }
        uStack_3c = 6;
        func_0x004bfa20(puStack_11c,puStack_11c + unaff_ESI * 4);
        if (pfStack_124 != (float *)0x0) {
          func_0x00763260(pfStack_124);
        }
        uStack_44 = 5;
        FUN_007441c0();
        iVar11 = iVar11 + 1;
        iVar15 = iVar15 + 0x98;
        pcVar14 = _wcsicmp_exref;
      } while (iVar11 < *(int *)(param_1 + 0xe0));
    }
    do {
      uStack_128 = (undefined1 *)((uint)uStack_128 & 0xffffff);
      iVar11 = 0;
      if (*(int *)(param_1 + 0xe0) == 1 || *(int *)(param_1 + 0xe0) + -1 < 0) break;
      iStack_118 = 0;
      pfVar9 = pfStack_12c;
      do {
        iVar15 = iStack_118;
        pfStack_124 = pfVar9;
        if (iStack_24 == 0) {
          pfStack_140 = (float *)pfVar9[1];
          pfStack_144 = (float *)*pfVar9;
          iVar17 = (*pcVar14)();
          if (0 < iVar17) {
code_r0x00749da6:
            pfVar9 = (float *)(*(int *)(param_1 + 0xd4) + iVar15);
            pfStack_144 = (float *)&UNK_00749db8;
            pfStack_140 = pfVar9;
            FUN_007652d0();
            fStack_f8 = pfVar9[1];
            puStack_f4 = (undefined *)CONCAT31(puStack_f4._1_3_,*(undefined1 *)(pfVar9 + 2));
            puVar4 = auStack_f0;
            iVar16 = (int)pfVar9 - (int)(apiStack_100 + 1);
            iVar17 = 8;
            do {
              *puVar4 = *(undefined4 *)(iVar16 + (int)puVar4);
              puVar4 = puVar4 + 1;
              iVar17 = iVar17 + -1;
            } while (iVar17 != 0);
            apfStack_d8[2] = (float *)pfVar9[0xb];
            pfStack_144 = pfVar9 + 0xd;
            fStack_cc = pfVar9[0xc];
            FUN_007652d0();
            puVar4 = auStack_c8;
            iVar17 = 6;
            do {
              *puVar4 = *(undefined4 *)((int)puVar4 + iVar16);
              puVar4 = puVar4 + 1;
              iVar17 = iVar17 + -1;
            } while (iVar17 != 0);
            puVar4 = auStack_b0;
            iVar17 = 6;
            do {
              *puVar4 = *(undefined4 *)((int)puVar4 + iVar16);
              puVar4 = puVar4 + 1;
              iVar17 = iVar17 + -1;
            } while (iVar17 != 0);
            puVar19 = auStack_98;
            iVar17 = 6;
            do {
              func_0x00763940(puVar19 + iVar16);
              puVar19 = puVar19 + 4;
              iVar17 = iVar17 + -1;
            } while (iVar17 != 0);
            puVar19 = auStack_80;
            iVar17 = 6;
            do {
              func_0x00763940(puVar19 + iVar16);
              puVar19 = puVar19 + 4;
              iVar17 = iVar17 + -1;
            } while (iVar17 != 0);
            iStack_118 = iVar15 + 0x98;
            iVar20 = iStack_118 + (int)pfStack_124[0x35];
            iVar15 = (int)pfStack_124[0x35] + iVar15;
            FUN_007652d0(iVar20);
            *(undefined4 *)(iVar15 + 4) = *(undefined4 *)(iVar20 + 4);
            *(undefined1 *)(iVar15 + 8) = *(undefined1 *)(iVar20 + 8);
            puVar4 = (undefined4 *)(iVar15 + 0xc);
            iVar16 = iVar20 - iVar15;
            iVar17 = 8;
            do {
              *puVar4 = *(undefined4 *)((int)puVar4 + iVar16);
              puVar4 = puVar4 + 1;
              iVar17 = iVar17 + -1;
            } while (iVar17 != 0);
            *(undefined4 *)(iVar15 + 0x2c) = *(undefined4 *)(iVar20 + 0x2c);
            *(undefined4 *)(iVar15 + 0x30) = *(undefined4 *)(iVar20 + 0x30);
            FUN_007652d0(iVar20 + 0x34);
            puVar4 = (undefined4 *)(iVar15 + 0x38);
            iVar17 = 6;
            do {
              *puVar4 = *(undefined4 *)((int)puVar4 + iVar16);
              puVar4 = puVar4 + 1;
              iVar17 = iVar17 + -1;
            } while (iVar17 != 0);
            puVar4 = (undefined4 *)(iVar15 + 0x50);
            iVar17 = 6;
            do {
              *puVar4 = *(undefined4 *)((int)puVar4 + iVar16);
              puVar4 = puVar4 + 1;
              iVar17 = iVar17 + -1;
            } while (iVar17 != 0);
            iVar17 = iVar15 + 0x68;
            iVar20 = 6;
            do {
              func_0x00763940(iVar17 + iVar16);
              iVar17 = iVar17 + 4;
              iVar20 = iVar20 + -1;
            } while (iVar20 != 0);
            iVar15 = iVar15 + 0x80;
            iVar17 = 6;
            do {
              func_0x00763940(iVar15 + iVar16);
              pfVar9 = pfStack_120;
              iVar15 = iVar15 + 4;
              iVar17 = iVar17 + -1;
            } while (iVar17 != 0);
            fVar8 = pfStack_12c[0x35];
            FUN_007652d0(&stack0xfffffef8);
            ppiVar5 = apiStack_100;
            *(undefined4 *)((int)pfVar9 + (int)fVar8 + 4) = unaff_EBX;
            *(undefined1 *)((int)pfVar9 + (int)fVar8 + 8) = uStack_104;
            puVar4 = (undefined4 *)((int)pfVar9 + (int)fVar8 + 0xc);
            iVar15 = 8;
            do {
              piVar1 = *ppiVar5;
              ppiVar5 = ppiVar5 + 1;
              *puVar4 = piVar1;
              puVar4 = puVar4 + 1;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
            *(undefined4 *)((int)pfVar9 + (int)fVar8 + 0x2c) = uStack_e0;
            *(undefined4 *)((int)pfVar9 + (int)fVar8 + 0x30) = uStack_dc;
            FUN_007652d0(apfStack_d8);
            ppfVar6 = apfStack_d8;
            puVar4 = (undefined4 *)((int)pfVar9 + (int)fVar8 + 0x38);
            iVar15 = 6;
            do {
              pfVar18 = *ppfVar6;
              ppfVar6 = ppfVar6 + 1;
              *puVar4 = pfVar18;
              puVar4 = puVar4 + 1;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
            puVar7 = auStack_c8 + 2;
            puVar4 = (undefined4 *)((int)pfVar9 + (int)fVar8 + 0x50);
            iVar15 = 6;
            do {
              uVar3 = *puVar7;
              puVar7 = puVar7 + 1;
              *puVar4 = uVar3;
              puVar4 = puVar4 + 1;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
            puVar4 = auStack_b0 + 2;
            iVar15 = 6;
            do {
              func_0x00763940(puVar4);
              puVar4 = puVar4 + 1;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
            pfVar18 = afStack_90;
            iVar15 = 6;
            do {
              func_0x00763940(pfVar18);
              pfVar9 = pfStack_13c;
              pfVar18 = pfVar18 + 1;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
            FUN_007652d0(pfStack_13c);
            FUN_007652d0(pfVar9 + 1);
            FUN_007652d0(&pfStack_140);
            uStack_128 = (undefined1 *)CONCAT13(1,(undefined3)uStack_128);
            pcVar14 = _wcsicmp_exref;
            iVar15 = iStack_118;
            param_1 = puStack_11c;
          }
        }
        else if (iStack_24 == 1) {
          pfStack_140 = (float *)pfVar9[1];
          pfStack_144 = (float *)*pfVar9;
          iVar17 = (*pcVar14)();
          if (iVar17 < 0) goto code_r0x00749da6;
        }
        iVar11 = iVar11 + 1;
        iStack_118 = iVar15 + 0x98;
        pfVar9 = pfVar9 + 1;
      } while (iVar11 < *(int *)(param_1 + 0xe0) + -1);
      pfStack_124 = pfVar9;
    } while (uStack_128._3_1_ != '\0');
    if (pfStack_12c != (float *)0x0) {
      pfStack_144 = (float *)pfStack_12c[-1];
      pfVar9 = pfStack_12c + -1;
      pfStack_140 = (float *)FUN_00765200;
      func_0x00892d40(pfStack_12c,4);
      func_0x00763260(pfVar9);
    }
    uStack_2c = CONCAT31(uStack_2c._1_3_,3);
    pfStack_140 = (float *)&UNK_0074a092;
    FUN_00765200();
    break;
  case 1:
    iVar11 = *(int *)(param_1 + 0xe0);
    pfStack_140 = (float *)(iVar11 * 4 + 4);
    pfStack_144 = (float *)&UNK_0074a0aa;
    apiStack_100[1] = (int *)func_0x00763250();
    uStack_2c._0_1_ = 8;
    if (apiStack_100[1] == (int *)0x0) {
      pfStack_12c = (float *)0x0;
    }
    else {
      pfStack_140 = (float *)0x7637f0;
      pfStack_144 = (float *)&UNK_0057d7b0;
      pfVar9 = (float *)(apiStack_100[1] + 1);
      *apiStack_100[1] = iVar11;
      func_0x00892e84(pfVar9,4,iVar11);
      pfStack_12c = pfVar9;
    }
    pfStack_124 = _DAT_009858e4;
    iVar11 = 0;
    uStack_2c = CONCAT31(uStack_2c._1_3_,9);
    pcVar14 = _stricmp_exref;
    if (0 < *(int *)(param_1 + 0xe0)) {
      iVar15 = 0;
      do {
        pfStack_140 = *(float **)(*(int *)(param_1 + 0xd4) + iVar15);
        pfStack_144 = (float *)&UNK_0074a120;
        FUN_00744150();
        pfStack_144 = (float *)0x95bc1c;
        uStack_30 = 10;
        FUN_00744590(&stack0xfffffef0);
        uStack_38 = 0xb;
        if (uStack_28 < unaff_EBP) {
          uVar3 = func_0x00764aa0(auStack_6c,*(undefined4 *)(iStack_118 + uStack_28 * 4));
          uStack_38 = 0xc;
          func_0x00763940(uVar3);
          uStack_3c = 0xb;
          func_0x007637f0();
        }
        else {
          func_0x007638a0(&DAT_009b3c44);
        }
        uStack_3c = 10;
        func_0x004bfa20(puStack_11c,puStack_11c + unaff_ESI * 4);
        if (pfStack_124 != (float *)0x0) {
          func_0x00763260(pfStack_124);
        }
        uStack_44 = 9;
        FUN_007441c0();
        iVar11 = iVar11 + 1;
        iVar15 = iVar15 + 0x98;
        pcVar14 = _stricmp_exref;
      } while (iVar11 < *(int *)(param_1 + 0xe0));
    }
    do {
      uStack_128 = (undefined1 *)((uint)uStack_128 & 0xffffff);
      iStack_118 = 0;
      if (*(int *)(param_1 + 0xe0) == 1 || *(int *)(param_1 + 0xe0) + -1 < 0) break;
      iVar11 = 0;
      pfVar9 = pfStack_12c;
      do {
        pfStack_120 = pfVar9;
        if (iStack_24 == 0) {
          pfStack_140 = (float *)pfVar9[1];
          pfStack_144 = (float *)*pfVar9;
          iVar15 = (*pcVar14)();
          if (0 < iVar15) {
code_r0x0074a265:
            pfVar9 = (float *)(*(int *)(param_1 + 0xd4) + iVar11);
            pfStack_144 = (float *)&UNK_0074a277;
            pfStack_140 = pfVar9;
            FUN_007652d0();
            fStack_f8 = pfVar9[1];
            puStack_f4 = (undefined *)CONCAT31(puStack_f4._1_3_,*(undefined1 *)(pfVar9 + 2));
            puVar4 = auStack_f0;
            iVar17 = (int)pfVar9 - (int)(apiStack_100 + 1);
            iVar15 = 8;
            do {
              *puVar4 = *(undefined4 *)(iVar17 + (int)puVar4);
              puVar4 = puVar4 + 1;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
            apfStack_d8[2] = (float *)pfVar9[0xb];
            pfStack_144 = pfVar9 + 0xd;
            fStack_cc = pfVar9[0xc];
            FUN_007652d0();
            puVar4 = auStack_c8;
            iVar15 = 6;
            do {
              *puVar4 = *(undefined4 *)((int)puVar4 + iVar17);
              puVar4 = puVar4 + 1;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
            puVar4 = auStack_b0;
            iVar15 = 6;
            do {
              *puVar4 = *(undefined4 *)((int)puVar4 + iVar17);
              puVar4 = puVar4 + 1;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
            puVar19 = auStack_98;
            iVar15 = 6;
            do {
              func_0x00763940(puVar19 + iVar17);
              puVar19 = puVar19 + 4;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
            puVar19 = auStack_80;
            iVar15 = 6;
            do {
              func_0x00763940(puVar19 + iVar17);
              puVar19 = puVar19 + 4;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
            iStack_118 = iVar11 + 0x98;
            iVar15 = (int)pfStack_124[0x35] + iStack_118;
            iVar17 = (int)pfStack_124[0x35] + iVar11;
            FUN_007652d0(iVar15);
            *(undefined4 *)(iVar17 + 4) = *(undefined4 *)(iVar15 + 4);
            *(undefined1 *)(iVar17 + 8) = *(undefined1 *)(iVar15 + 8);
            puVar4 = (undefined4 *)(iVar17 + 0xc);
            iVar20 = iVar15 - iVar17;
            iVar16 = 8;
            do {
              *puVar4 = *(undefined4 *)((int)puVar4 + iVar20);
              puVar4 = puVar4 + 1;
              iVar16 = iVar16 + -1;
            } while (iVar16 != 0);
            *(undefined4 *)(iVar17 + 0x2c) = *(undefined4 *)(iVar15 + 0x2c);
            *(undefined4 *)(iVar17 + 0x30) = *(undefined4 *)(iVar15 + 0x30);
            FUN_007652d0(iVar15 + 0x34);
            puVar4 = (undefined4 *)(iVar17 + 0x38);
            iVar15 = 6;
            do {
              *puVar4 = *(undefined4 *)((int)puVar4 + iVar20);
              puVar4 = puVar4 + 1;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
            puVar4 = (undefined4 *)(iVar17 + 0x50);
            iVar15 = 6;
            do {
              *puVar4 = *(undefined4 *)((int)puVar4 + iVar20);
              puVar4 = puVar4 + 1;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
            iVar15 = iVar17 + 0x68;
            iVar16 = 6;
            do {
              func_0x00763940(iVar15 + iVar20);
              iVar15 = iVar15 + 4;
              iVar16 = iVar16 + -1;
            } while (iVar16 != 0);
            iVar17 = iVar17 + 0x80;
            iVar15 = 6;
            do {
              func_0x00763940(iVar17 + iVar20);
              pfVar9 = pfStack_120;
              iVar17 = iVar17 + 4;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
            fVar8 = pfStack_12c[0x35];
            FUN_007652d0(&stack0xfffffef8);
            ppiVar5 = apiStack_100;
            *(undefined4 *)((int)pfVar9 + (int)fVar8 + 4) = unaff_EBX;
            *(undefined1 *)((int)pfVar9 + (int)fVar8 + 8) = uStack_104;
            puVar4 = (undefined4 *)((int)pfVar9 + (int)fVar8 + 0xc);
            iVar15 = 8;
            do {
              piVar1 = *ppiVar5;
              ppiVar5 = ppiVar5 + 1;
              *puVar4 = piVar1;
              puVar4 = puVar4 + 1;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
            *(undefined4 *)((int)pfVar9 + (int)fVar8 + 0x2c) = uStack_e0;
            *(undefined4 *)((int)pfVar9 + (int)fVar8 + 0x30) = uStack_dc;
            FUN_007652d0(apfStack_d8);
            ppfVar6 = apfStack_d8;
            puVar4 = (undefined4 *)((int)pfVar9 + (int)fVar8 + 0x38);
            iVar15 = 6;
            do {
              pfVar18 = *ppfVar6;
              ppfVar6 = ppfVar6 + 1;
              *puVar4 = pfVar18;
              puVar4 = puVar4 + 1;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
            puVar7 = auStack_c8 + 2;
            puVar4 = (undefined4 *)((int)pfVar9 + (int)fVar8 + 0x50);
            iVar15 = 6;
            do {
              uVar3 = *puVar7;
              puVar7 = puVar7 + 1;
              *puVar4 = uVar3;
              puVar4 = puVar4 + 1;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
            puVar4 = auStack_b0 + 2;
            iVar15 = 6;
            do {
              func_0x00763940(puVar4);
              puVar4 = puVar4 + 1;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
            pfVar18 = afStack_90;
            iVar15 = 6;
            do {
              func_0x00763940(pfVar18);
              pfVar9 = pfStack_138;
              pfVar18 = pfVar18 + 1;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
            func_0x00763940(pfStack_138);
            func_0x00763940(pfVar9 + 1);
            func_0x00763940(&pfStack_144);
            uStack_128 = (undefined1 *)CONCAT13(1,(undefined3)uStack_128);
            pcVar14 = _stricmp_exref;
            param_1 = puStack_11c;
          }
        }
        else if (iStack_24 == 1) {
          pfStack_140 = (float *)pfVar9[1];
          pfStack_144 = (float *)*pfVar9;
          iVar15 = (*pcVar14)();
          if (iVar15 < 0) goto code_r0x0074a265;
        }
        iStack_118 = iStack_118 + 1;
        iVar11 = iVar11 + 0x98;
        pfVar9 = pfVar9 + 1;
      } while (iStack_118 < *(int *)(param_1 + 0xe0) + -1);
      pfStack_120 = pfVar9;
    } while (uStack_128._3_1_ != '\0');
    if (pfStack_12c != (float *)0x0) {
      pfStack_144 = (float *)pfStack_12c[-1];
      pfVar9 = pfStack_12c + -1;
      pfStack_140 = (float *)0x7637f0;
      func_0x00892d40(pfStack_12c,4);
      func_0x00763260(pfVar9);
    }
    uStack_2c = CONCAT31(uStack_2c._1_3_,3);
    pfStack_140 = (float *)&UNK_0074a552;
    func_0x007637f0();
    break;
  case 2:
    pfStack_140 = (float *)(*(int *)(param_1 + 0xe0) * 4);
    pfStack_144 = (float *)&UNK_0074a56a;
    pfVar9 = (float *)func_0x00763250();
    iVar15 = 0;
    iVar11 = iStack_24;
    pfStack_124 = pfVar9;
    if (0 < *(int *)(param_1 + 0xe0)) {
      iVar17 = 0;
      do {
        pfStack_140 = *(float **)(*(int *)(param_1 + 0xd4) + iVar17);
        pfStack_144 = (float *)&UNK_0074a59d;
        FUN_00744150();
        pfStack_144 = (float *)0x95bc1c;
        uStack_30 = 0xd;
        FUN_00744590(&stack0xfffffef0);
        pfStack_138 = _DAT_00985a98;
        uStack_38 = 0xf;
        if (uStack_28 < unaff_EBP) {
          FUN_007652d0(iStack_118 + uStack_28 * 4);
        }
        else {
          FUN_00765230(0x9b3c40);
        }
        if ((int)pfStack_13c[-2] < 1) {
code_r0x0074a628:
          if (1 < (int)pfStack_13c[-2]) {
            psVar12 = (short *)FUN_007655e0(0);
            if (*psVar12 == 0x2b) goto code_r0x0074a672;
            psVar12 = (short *)FUN_007655e0(0);
            if (*psVar12 == 0x2d) {
              puVar10 = (undefined2 *)FUN_007655e0(1);
              iVar11 = isdigit(*puVar10);
              if (iVar11 != 0) goto code_r0x0074a672;
            }
          }
          *pfVar9 = NAN;
        }
        else {
          puVar10 = (undefined2 *)FUN_007655e0(0);
          iVar11 = isdigit(*puVar10);
          if (iVar11 == 0) goto code_r0x0074a628;
code_r0x0074a672:
          if (pfStack_13c == _DAT_00985a98) {
            *pfVar9 = 0.0;
          }
          else {
            fVar8 = (float)_wtoi(pfStack_13c);
            *pfVar9 = fVar8;
          }
        }
        uStack_3c = 0xe;
        FUN_00765200();
        uStack_3c = 0xd;
        func_0x004bfa20(puStack_11c,puStack_11c + unaff_ESI * 4);
        if (pfStack_124 != (float *)0x0) {
          func_0x00763260(pfStack_124);
        }
        uStack_44 = 3;
        FUN_007441c0();
        iVar15 = iVar15 + 1;
        iVar17 = iVar17 + 0x98;
        pfVar9 = pfVar9 + 1;
        iVar11 = iStack_24;
      } while (iVar15 < *(int *)(param_1 + 0xe0));
    }
    do {
      bVar2 = false;
      iStack_118 = 0;
      if (*(int *)(param_1 + 0xe0) == 1 || *(int *)(param_1 + 0xe0) + -1 < 0) break;
      iVar15 = 0;
      pfStack_120 = pfStack_124;
      do {
        if (iVar11 == 0) {
          if ((int)pfStack_120[1] < (int)*pfStack_120) {
code_r0x0074a75c:
            pfVar9 = (float *)(*(int *)(param_1 + 0xd4) + iVar15);
            pfStack_144 = (float *)&UNK_0074a76e;
            pfStack_140 = pfVar9;
            FUN_007652d0();
            fStack_f8 = pfVar9[1];
            puStack_f4 = (undefined *)CONCAT31(puStack_f4._1_3_,*(undefined1 *)(pfVar9 + 2));
            iVar17 = (int)pfVar9 - (int)(apiStack_100 + 1);
            puVar4 = auStack_f0;
            iVar11 = 8;
            do {
              *puVar4 = *(undefined4 *)(iVar17 + (int)puVar4);
              puVar4 = puVar4 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            apfStack_d8[2] = (float *)pfVar9[0xb];
            pfStack_144 = pfVar9 + 0xd;
            fStack_cc = pfVar9[0xc];
            FUN_007652d0();
            puVar4 = auStack_c8;
            iVar11 = 6;
            do {
              *puVar4 = *(undefined4 *)((int)puVar4 + iVar17);
              puVar4 = puVar4 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            puVar4 = auStack_b0;
            iVar11 = 6;
            do {
              *puVar4 = *(undefined4 *)((int)puVar4 + iVar17);
              puVar4 = puVar4 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            puVar19 = auStack_98;
            iVar11 = 6;
            do {
              func_0x00763940(puVar19 + iVar17);
              puVar19 = puVar19 + 4;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            puVar19 = auStack_80;
            iVar11 = 6;
            do {
              func_0x00763940(puVar19 + iVar17);
              puVar19 = puVar19 + 4;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            iStack_118 = iVar15 + 0x98;
            iVar11 = (int)pfStack_124[0x35] + iStack_118;
            iVar17 = (int)pfStack_124[0x35] + iVar15;
            FUN_007652d0(iVar11);
            *(undefined4 *)(iVar17 + 4) = *(undefined4 *)(iVar11 + 4);
            *(undefined1 *)(iVar17 + 8) = *(undefined1 *)(iVar11 + 8);
            puVar4 = (undefined4 *)(iVar17 + 0xc);
            iVar20 = iVar11 - iVar17;
            iVar16 = 8;
            do {
              *puVar4 = *(undefined4 *)((int)puVar4 + iVar20);
              puVar4 = puVar4 + 1;
              iVar16 = iVar16 + -1;
            } while (iVar16 != 0);
            *(undefined4 *)(iVar17 + 0x2c) = *(undefined4 *)(iVar11 + 0x2c);
            *(undefined4 *)(iVar17 + 0x30) = *(undefined4 *)(iVar11 + 0x30);
            FUN_007652d0(iVar11 + 0x34);
            puVar4 = (undefined4 *)(iVar17 + 0x38);
            iVar11 = 6;
            do {
              *puVar4 = *(undefined4 *)((int)puVar4 + iVar20);
              puVar4 = puVar4 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            puVar4 = (undefined4 *)(iVar17 + 0x50);
            iVar11 = 6;
            do {
              *puVar4 = *(undefined4 *)((int)puVar4 + iVar20);
              puVar4 = puVar4 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            iVar11 = iVar17 + 0x68;
            iVar16 = 6;
            do {
              func_0x00763940(iVar11 + iVar20);
              iVar11 = iVar11 + 4;
              iVar16 = iVar16 + -1;
            } while (iVar16 != 0);
            iVar17 = iVar17 + 0x80;
            iVar11 = 6;
            do {
              func_0x00763940(iVar17 + iVar20);
              pfVar9 = pfStack_120;
              iVar17 = iVar17 + 4;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            fVar8 = pfStack_12c[0x35];
            FUN_007652d0(&stack0xfffffef8);
            ppiVar5 = apiStack_100;
            *(undefined4 *)((int)pfVar9 + (int)fVar8 + 4) = unaff_EBX;
            *(undefined1 *)((int)pfVar9 + (int)fVar8 + 8) = uStack_104;
            puVar4 = (undefined4 *)((int)pfVar9 + (int)fVar8 + 0xc);
            iVar11 = 8;
            do {
              piVar1 = *ppiVar5;
              ppiVar5 = ppiVar5 + 1;
              *puVar4 = piVar1;
              puVar4 = puVar4 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            *(undefined4 *)((int)pfVar9 + (int)fVar8 + 0x2c) = uStack_e0;
            *(undefined4 *)((int)pfVar9 + (int)fVar8 + 0x30) = uStack_dc;
            FUN_007652d0(apfStack_d8);
            puVar7 = auStack_c8 + 2;
            puVar4 = (undefined4 *)((int)pfVar9 + (int)fVar8 + 0x38);
            iVar11 = 6;
            do {
              uVar3 = *puVar7;
              puVar7 = puVar7 + 1;
              *puVar4 = uVar3;
              puVar4 = puVar4 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            puVar7 = auStack_b0 + 2;
            puVar4 = (undefined4 *)((int)pfVar9 + (int)fVar8 + 0x50);
            iVar11 = 6;
            do {
              uVar3 = *puVar7;
              puVar7 = puVar7 + 1;
              *puVar4 = uVar3;
              puVar4 = puVar4 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            pfVar9 = afStack_90;
            iVar11 = 6;
            do {
              pfStack_144 = (float *)&UNK_0074a97a;
              pfStack_140 = pfVar9;
              func_0x00763940();
              pfVar9 = pfVar9 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            pfVar9 = afStack_78;
            iVar11 = 6;
            do {
              pfStack_144 = (float *)&UNK_0074a99d;
              pfStack_140 = pfVar9;
              func_0x00763940();
              pfVar9 = pfVar9 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            fVar8 = *pfStack_120;
            *pfStack_120 = pfStack_120[1];
            pfStack_120[1] = fVar8;
            bVar2 = true;
            iVar11 = iStack_24;
            param_1 = puStack_11c;
          }
        }
        else if ((iVar11 == 1) && ((int)*pfStack_120 < (int)pfStack_120[1])) goto code_r0x0074a75c;
        iStack_118 = iStack_118 + 1;
        iVar15 = iVar15 + 0x98;
        pfStack_120 = pfStack_120 + 1;
      } while (iStack_118 < *(int *)(param_1 + 0xe0) + -1);
    } while (bVar2);
    pfStack_140 = pfStack_124;
    goto code_r0x0074aeec;
  case 3:
    pfStack_140 = (float *)(*(int *)(param_1 + 0xe0) * 4);
    pfStack_144 = (float *)&UNK_0074aa15;
    pfVar9 = (float *)func_0x00763250();
    iVar15 = 0;
    iVar11 = iStack_24;
    if (0 < *(int *)(param_1 + 0xe0)) {
      iVar17 = 0;
      pfVar18 = pfVar9;
      do {
        pfStack_140 = *(float **)(*(int *)(param_1 + 0xd4) + iVar17);
        pfStack_144 = (float *)&UNK_0074aa46;
        FUN_00744150();
        pfStack_144 = (float *)0x95bc1c;
        uStack_30 = 0x10;
        FUN_00744590(&stack0xfffffef0);
        pfStack_138 = _DAT_00985a98;
        uStack_38 = 0x12;
        if (uStack_28 < unaff_EBP) {
          FUN_007652d0(iStack_118 + uStack_28 * 4);
        }
        else {
          FUN_00765230(0x9b3c40);
        }
        if ((int)pfStack_13c[-2] < 1) {
code_r0x0074aae1:
          if (1 < (int)pfStack_13c[-2]) {
            psVar12 = (short *)FUN_007655e0(0);
            if (*psVar12 != 0x2b) {
              psVar12 = (short *)FUN_007655e0(0);
              if (*psVar12 == 0x2d) {
                puVar10 = (undefined2 *)FUN_007655e0(1);
                iVar11 = isdigit(*puVar10);
                if (iVar11 != 0) goto code_r0x0074ab40;
              }
              psVar12 = (short *)FUN_007655e0(1);
              if (*psVar12 != 0x2e) goto code_r0x0074ab74;
            }
            goto code_r0x0074ab40;
          }
code_r0x0074ab74:
          *pfVar18 = 3.4028235e+38;
        }
        else {
          puVar10 = (undefined2 *)FUN_007655e0(0);
          iVar11 = isdigit(*puVar10);
          if ((iVar11 == 0) && (psVar12 = (short *)FUN_007655e0(0), *psVar12 != 0x2e))
          goto code_r0x0074aae1;
code_r0x0074ab40:
          if (pfStack_13c == _DAT_00985a98) {
            *pfVar18 = _DAT_008d58a0;
          }
          else {
            swscanf(pfStack_13c,0x976de0,&pfStack_120);
            *pfVar18 = (float)pfStack_120;
          }
        }
        uStack_3c = 0x11;
        FUN_00765200();
        uStack_3c = 0x10;
        func_0x004bfa20(puStack_11c,puStack_11c + unaff_ESI * 4);
        if (pfStack_124 != (float *)0x0) {
          func_0x00763260(pfStack_124);
        }
        uStack_44 = 3;
        FUN_007441c0();
        iVar15 = iVar15 + 1;
        iVar17 = iVar17 + 0x98;
        pfVar18 = pfVar18 + 1;
        iVar11 = iStack_24;
      } while (iVar15 < *(int *)(param_1 + 0xe0));
    }
    do {
      bVar2 = false;
      pfStack_124 = (float *)0x0;
      pfStack_140 = pfVar9;
      if (*(int *)(param_1 + 0xe0) == 1 || *(int *)(param_1 + 0xe0) + -1 < 0) break;
      iStack_118 = 0;
      pfStack_120 = pfVar9;
      puVar13 = puStack_11c;
      do {
        iVar15 = iStack_118;
        if (iVar11 == 0) {
          if (pfStack_120[1] < *pfStack_120) {
code_r0x0074ac48:
            pfVar18 = (float *)(*(int *)(puVar13 + 0xd4) + iStack_118);
            pfStack_144 = (float *)&UNK_0074ac5a;
            pfStack_140 = pfVar18;
            FUN_007652d0();
            fStack_f8 = pfVar18[1];
            puStack_f4 = (undefined *)CONCAT31(puStack_f4._1_3_,*(undefined1 *)(pfVar18 + 2));
            puVar4 = auStack_f0;
            iVar17 = (int)pfVar18 - (int)(apiStack_100 + 1);
            iVar11 = 8;
            do {
              *puVar4 = *(undefined4 *)(iVar17 + (int)puVar4);
              puVar4 = puVar4 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            apfStack_d8[2] = (float *)pfVar18[0xb];
            pfStack_144 = pfVar18 + 0xd;
            fStack_cc = pfVar18[0xc];
            FUN_007652d0();
            puVar4 = auStack_c8;
            iVar11 = 6;
            do {
              *puVar4 = *(undefined4 *)((int)puVar4 + iVar17);
              puVar4 = puVar4 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            puVar4 = auStack_b0;
            iVar11 = 6;
            do {
              *puVar4 = *(undefined4 *)((int)puVar4 + iVar17);
              puVar4 = puVar4 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            puVar19 = auStack_98;
            iVar11 = 6;
            do {
              func_0x00763940(puVar19 + iVar17);
              puVar19 = puVar19 + 4;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            puVar19 = auStack_80;
            iVar11 = 6;
            do {
              func_0x00763940(puVar19 + iVar17);
              puVar19 = puVar19 + 4;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            iVar11 = iVar15 + 0x98;
            iVar20 = iVar11 + (int)pfStack_124[0x35];
            iVar15 = (int)pfStack_124[0x35] + iVar15;
            FUN_007652d0(iVar20);
            *(undefined4 *)(iVar15 + 4) = *(undefined4 *)(iVar20 + 4);
            *(undefined1 *)(iVar15 + 8) = *(undefined1 *)(iVar20 + 8);
            puVar4 = (undefined4 *)(iVar15 + 0xc);
            iVar16 = iVar20 - iVar15;
            iVar17 = 8;
            do {
              *puVar4 = *(undefined4 *)((int)puVar4 + iVar16);
              puVar4 = puVar4 + 1;
              iVar17 = iVar17 + -1;
            } while (iVar17 != 0);
            *(undefined4 *)(iVar15 + 0x2c) = *(undefined4 *)(iVar20 + 0x2c);
            *(undefined4 *)(iVar15 + 0x30) = *(undefined4 *)(iVar20 + 0x30);
            FUN_007652d0(iVar20 + 0x34);
            puVar4 = (undefined4 *)(iVar15 + 0x38);
            iVar17 = 6;
            do {
              *puVar4 = *(undefined4 *)((int)puVar4 + iVar16);
              puVar4 = puVar4 + 1;
              iVar17 = iVar17 + -1;
            } while (iVar17 != 0);
            puVar4 = (undefined4 *)(iVar15 + 0x50);
            iVar17 = 6;
            do {
              *puVar4 = *(undefined4 *)((int)puVar4 + iVar16);
              puVar4 = puVar4 + 1;
              iVar17 = iVar17 + -1;
            } while (iVar17 != 0);
            iVar17 = iVar15 + 0x68;
            iVar20 = 6;
            do {
              func_0x00763940(iVar17 + iVar16);
              iVar17 = iVar17 + 4;
              iVar20 = iVar20 + -1;
            } while (iVar20 != 0);
            iVar15 = iVar15 + 0x80;
            iVar17 = 6;
            do {
              func_0x00763940(iVar15 + iVar16);
              iVar15 = iVar15 + 4;
              iVar17 = iVar17 + -1;
            } while (iVar17 != 0);
            iVar15 = (int)pfStack_12c[0x35] + unaff_EBP;
            FUN_007652d0(&stack0xfffffef8);
            ppiVar5 = apiStack_100;
            *(undefined4 *)(iVar15 + 4) = unaff_EBX;
            uStack_104 = (undefined1)iVar11;
            *(undefined1 *)(iVar15 + 8) = uStack_104;
            puVar4 = (undefined4 *)(iVar15 + 0xc);
            iVar11 = 8;
            do {
              piVar1 = *ppiVar5;
              ppiVar5 = ppiVar5 + 1;
              *puVar4 = piVar1;
              puVar4 = puVar4 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            *(undefined4 *)(iVar15 + 0x2c) = uStack_e0;
            *(undefined4 *)(iVar15 + 0x30) = uStack_dc;
            FUN_007652d0(apfStack_d8);
            puVar7 = auStack_c8 + 2;
            puVar4 = (undefined4 *)(iVar15 + 0x38);
            iVar11 = 6;
            do {
              uVar3 = *puVar7;
              puVar7 = puVar7 + 1;
              *puVar4 = uVar3;
              puVar4 = puVar4 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            puVar7 = auStack_b0 + 2;
            puVar4 = (undefined4 *)(iVar15 + 0x50);
            iVar11 = 6;
            do {
              uVar3 = *puVar7;
              puVar7 = puVar7 + 1;
              *puVar4 = uVar3;
              puVar4 = puVar4 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            pfVar18 = afStack_90;
            iVar11 = 6;
            do {
              pfStack_144 = (float *)&UNK_0074ae65;
              pfStack_140 = pfVar18;
              func_0x00763940();
              pfVar18 = pfVar18 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            pfVar18 = afStack_78;
            iVar11 = 6;
            do {
              pfStack_144 = (float *)&UNK_0074ae88;
              pfStack_140 = pfVar18;
              func_0x00763940();
              pfVar18 = pfVar18 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            fVar8 = *pfStack_120;
            bVar2 = true;
            *pfStack_120 = pfStack_120[1];
            pfStack_120[1] = fVar8;
            puVar13 = puStack_11c;
            iVar11 = iStack_24;
          }
        }
        else if ((iVar11 == 1) && (*pfStack_120 < pfStack_120[1])) goto code_r0x0074ac48;
        iStack_118 = iStack_118 + 0x98;
        pfStack_124 = (float *)((int)pfStack_124 + 1);
        pfStack_120 = pfStack_120 + 1;
      } while ((int)pfStack_124 < *(int *)(puVar13 + 0xe0) + -1);
      param_1 = puStack_11c;
      pfStack_140 = pfVar9;
    } while (bVar2);
code_r0x0074aeec:
    pfStack_144 = (float *)&UNK_0074aef1;
    func_0x00763260();
  }
  pfStack_140 = (float *)0x7637f0;
  pfStack_144 = (float *)0x6;
  uStack_2c = 0x15;
  func_0x00892d40(afStack_78,4);
  uStack_3c = 0x14;
  func_0x00892d40(auStack_a0,4,6,0x7637f0);
  uStack_4c = CONCAT31(uStack_4c._1_3_,0x13);
  FUN_00765200();
  uStack_4c = 0xffffffff;
  FUN_00765200();
  *unaff_FS_OFFSET = uStack_54;
  return 1;
}


/* ==================================================================== */
/* Address: 0x0074b380 | Classified: AngelicaUI::proc_74b380 */
/* ==================================================================== */

void __thiscall FUN_0074b380(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x9d) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x0074b390 | Classified: AngelicaUI::proc_74b390 */
/* ==================================================================== */

int __thiscall FUN_0074b390(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xe0))) {
    *(int *)(*(int *)(param_1 + 0xd4) + 0x2c + param_2 * 0x98) = param_3;
    *(int *)(*(int *)(param_1 + 0xd4) + 0x30 + param_2 * 0x98) = param_4;
    iVar1 = *(int *)(*(int *)(param_3 + 0x24) + param_4 * 4);
    iVar4 = *(int *)(iVar1 + 0x14);
    iVar2 = *(int *)(iVar1 + 0xc);
    iVar1 = ((*(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 8)) * 0xb) / 10;
    iVar3 = *(int *)(param_1 + 200);
    if (*(int *)(param_1 + 200) < iVar1) {
      iVar3 = iVar1;
    }
    *(int *)(param_1 + 200) = iVar3;
    iVar1 = ((iVar4 - iVar2) * 0xb) / 10;
    iVar4 = *(int *)(param_1 + 0xcc);
    if (*(int *)(param_1 + 0xcc) < iVar1) {
      iVar4 = iVar1;
    }
    *(int *)(param_1 + 0xcc) = iVar4;
    return param_2;
  }
  return -1;
}


/* ==================================================================== */
/* Address: 0x0074b450 | Classified: AngelicaUI::proc_74b450 */
/* ==================================================================== */

void __thiscall FUN_0074b450(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xb8) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x0074b460 | Classified: AngelicaUI::proc_74b460 */
/* ==================================================================== */

undefined4 __thiscall FUN_0074b460(int param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xe0))) {
    return *(undefined4 *)(*(int *)(param_1 + 0xd4) + 0x34 + param_2 * 0x98);
  }
  return 0x9b3c40;
}


/* ==================================================================== */
/* Address: 0x0074b490 | Classified: AngelicaUI::proc_74b490 */
/* ==================================================================== */

int __thiscall FUN_0074b490(int param_1,int param_2,undefined4 param_3)

{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xe0))) {
    FUN_00765230(param_3);
    return param_2;
  }
  return -1;
}


/* ==================================================================== */
/* Address: 0x0074b4d0 | Classified: AngelicaUI::proc_74b4d0 */
/* ==================================================================== */

void __thiscall FUN_0074b4d0(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x9e) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x0074b4e0 | Classified: AngelicaUI::proc_74b4e0 */
/* ==================================================================== */

undefined4 __fastcall FUN_0074b4e0(int param_1)

{
  return *(undefined4 *)(param_1 + 0xb4);
}


/* ==================================================================== */
/* Address: 0x0074b4f0 | Classified: AngelicaUI::proc_74b4f0 */
/* ==================================================================== */

void __thiscall FUN_0074b4f0(int param_1,int param_2,char param_3)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_00748ae0();
  if (cVar1 != '\0') {
    cVar1 = *(char *)(*(int *)(param_1 + 0xd4) + 8 + param_2 * 0x98);
    if (param_3 == '\0') {
      if (cVar1 == '\0') goto LAB_0074b538;
      iVar2 = *(int *)(param_1 + 0x130) + -1;
    }
    else {
      if (cVar1 != '\0') goto LAB_0074b538;
      iVar2 = *(int *)(param_1 + 0x130) + 1;
    }
    *(int *)(param_1 + 0x130) = iVar2;
  }
LAB_0074b538:
  *(char *)(*(int *)(param_1 + 0xd4) + 8 + param_2 * 0x98) = param_3;
  return;
}


/* ==================================================================== */
/* Address: 0x0074b550 | Classified: AngelicaUI::proc_74b550 */
/* ==================================================================== */

void __thiscall FUN_0074b550(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x138) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x0074b560 | Classified: AngelicaUI::proc_74b560 */
/* ==================================================================== */

void __thiscall FUN_0074b560(int param_1,int param_2)

{
  int iVar1;
  int iStack_10;
  undefined1 auStack_c [12];
  
  if ((((*(int *)(param_1 + 0xb8) == 0) && (*(char *)(param_1 + 0x9e) == '\0')) && (-1 < param_2))
     && (param_2 < *(int *)(param_1 + 0xe0))) {
    FUN_007537a0(&iStack_10);
    if (*(int *)(param_1 + 0x34) == 0) {
      func_0x00868610();
      FUN_007537e0();
    }
    iVar1 = func_0x0073c830(auStack_c,0x981774,0xffffffff);
    iVar1 = *(int *)(iVar1 + 4);
    if (1 < *(int *)(param_1 + 0xcc)) {
      iVar1 = *(int *)(param_1 + 0xcc);
    }
    *(int *)(param_1 + 0xc0) = param_2;
    iVar1 = (*(int *)(param_1 + 0x5c) + (iStack_10 / 2) * -2) / iVar1;
    if (*(int *)(param_1 + 0xe0) <= iVar1 + param_2) {
      *(int *)(param_1 + 0xc0) = *(int *)(param_1 + 0xe0) - iVar1;
    }
    if (*(int *)(param_1 + 0xc0) < 0) {
      *(undefined4 *)(param_1 + 0xc0) = 0;
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0074b640 | Classified: AngelicaUI::proc_74b640 */
/* ==================================================================== */

void __fastcall FUN_0074b640(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iStack_14;
  
  uVar2 = *param_1;
  uVar1 = uVar2 + param_1[3] * 0x98;
  if (uVar2 != uVar1) {
    uVar6 = uVar2;
    if (uVar1 < param_1[1]) {
      uVar5 = uVar1;
      do {
        FUN_007652d0(uVar5);
        *(undefined4 *)(uVar6 + 4) = *(undefined4 *)(uVar5 + 4);
        *(undefined1 *)(uVar5 + 8 + (uVar2 - uVar1)) = *(undefined1 *)(uVar5 + 8);
        puVar3 = (undefined4 *)(uVar6 + 0xc);
        iVar7 = uVar5 - uVar6;
        iVar4 = 8;
        do {
          *puVar3 = *(undefined4 *)(iVar7 + (int)puVar3);
          puVar3 = puVar3 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        *(undefined4 *)(uVar6 + 0x2c) = *(undefined4 *)(uVar5 + 0x2c);
        *(undefined4 *)(uVar6 + 0x30) = *(undefined4 *)(uVar5 + 0x30);
        FUN_007652d0(uVar5 + 0x34);
        puVar3 = (undefined4 *)(uVar6 + 0x38);
        iVar4 = 6;
        do {
          *puVar3 = *(undefined4 *)((int)puVar3 + iVar7);
          puVar3 = puVar3 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        puVar3 = (undefined4 *)(uVar6 + 0x50);
        iVar4 = 6;
        do {
          *puVar3 = *(undefined4 *)((int)puVar3 + iVar7);
          puVar3 = puVar3 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        iVar4 = uVar6 + 0x68;
        iStack_14 = 6;
        do {
          func_0x00763940(iVar7 + iVar4);
          iVar4 = iVar4 + 4;
          iStack_14 = iStack_14 + -1;
        } while (iStack_14 != 0);
        iVar4 = uVar6 + 0x80;
        iStack_14 = 6;
        do {
          func_0x00763940(iVar7 + iVar4);
          iVar4 = iVar4 + 4;
          iStack_14 = iStack_14 + -1;
        } while (iStack_14 != 0);
        uVar5 = uVar5 + 0x98;
        uVar6 = uVar6 + 0x98;
      } while (uVar5 < param_1[1]);
    }
    if (uVar6 < param_1[1]) {
      do {
        FUN_0074b7c0(0);
        uVar6 = uVar6 + 0x98;
      } while (uVar6 < param_1[1]);
    }
    iVar4 = (int)(uVar1 - uVar2) / 0x98;
    param_1[1] = param_1[1] + iVar4 * -0x98;
    param_1[3] = param_1[3] - iVar4;
  }
  if (*param_1 != 0) {
    func_0x00763260(*param_1);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0074b7c0 | Classified: AngelicaUI::proc_74b7c0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0074b7c0(undefined4 param_1,byte param_2)

{
  FUN_00748230();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0074b7e0 | Classified: AngelicaUI::proc_74b7e0 */
/* ==================================================================== */

undefined4 * __fastcall FUN_0074b7e0(undefined4 *param_1)

{
  FUN_00741960();
  *param_1 = &UNK_008ef024;
  param_1[0x27] = 0;
  param_1[0x10] = 0;
  param_1[0xf] = 1;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0074b810 | Classified: AUICheckBox::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0074b810(undefined4 param_1,byte param_2)

{
  FUN_0074b830();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0074b830 | Classified: AngelicaUI::proc_74b830 */
/* ==================================================================== */

void __fastcall FUN_0074b830(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  *param_1 = &UNK_008ef024;
  puStack_8 = &UNK_008ca630;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008eece0;
  iStack_4 = 6;
  func_0x007637f0();
  iStack_4._0_1_ = 5;
  func_0x007637f0();
  iStack_4._0_1_ = 4;
  FUN_00765200();
  iStack_4._0_1_ = 3;
  FUN_00765200();
  iStack_4._0_1_ = 2;
  FUN_00765200();
  iStack_4._0_1_ = 1;
  func_0x007637f0();
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  func_0x007637f0();
  iStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x0074bb20 | Classified: AUICheckBox::vfunc_slot_6 */
/* ==================================================================== */

undefined4 __fastcall FUN_0074bb20(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined1 auStack_c [12];
  
  if (*(int *)(param_1 + 0x9c) == 0) {
    uVar5 = FUN_00430850();
    return uVar5;
  }
  cVar4 = FUN_0074c280();
  uVar8 = (uint)(cVar4 != '\0');
  func_0x0078c4e0(uVar8);
  if (*(int *)(param_1 + 0x58) < 1) {
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(*(int *)(param_1 + 0x9c) + 0x34);
  }
  if (*(int *)(param_1 + 0x5c) < 1) {
    *(int *)(param_1 + 0x5c) = *(int *)(*(int *)(param_1 + 0x9c) + 0x38) / 3;
  }
  iVar1 = *(int *)(param_1 + 0x9c);
  iVar3 = *(int *)(param_1 + 0x5c) * 3;
  *(float *)(iVar1 + 0x70) = (float)*(int *)(param_1 + 0x58) / (float)*(int *)(iVar1 + 0x34);
  *(float *)(*(int *)(param_1 + 0x9c) + 0x74) = (float)iVar3 / (float)*(int *)(iVar1 + 0x38);
  FUN_00741db0(auStack_c,0);
  iVar1 = *(int *)(param_1 + 0x60);
  iVar2 = *(int *)(param_1 + 100);
  uVar6 = *(uint *)(param_1 + 0x38);
  if (*(char *)(param_1 + 0x46) == '\0') {
    uVar7 = uVar6 >> 0x10 & 0xfe;
    uVar6 = (uVar6 >> 0x10 & 0xff) >> 1 | ((uVar7 | 0xfffffe00) << 8 | uVar7) << 7;
  }
  *(uint *)(*(int *)(param_1 + 0x9c) + 0x6c) = uVar6;
  *(uint *)(*(int *)(param_1 + 0x9c) + 0x6c) =
       *(int *)(param_1 + 0x84) << 0x18 | *(uint *)(*(int *)(param_1 + 0x9c) + 0x6c) & 0xffffff;
  if (*(char *)(*(int *)(param_1 + 0xc) + 0x62) == '\0') {
    cVar4 = func_0x0078c490((float)(int)(uVar8 + iVar1),(float)(iVar3 + iVar2));
  }
  else {
    cVar4 = func_0x0078c3a0();
  }
  if (cVar4 == '\0') {
    uVar5 = func_0x00739700(0xa8,1,0x98243c);
    return uVar5;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0074bc80 | Classified: AUICheckBox::vfunc_slot_9 */
/* ==================================================================== */

undefined4 __thiscall FUN_0074bc80(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = param_3;
  for (iVar2 = 0x402; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  iVar2 = _strcmpi(param_2,0x9664d8);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x9c) != 0) {
      strncpy(param_3,*(undefined4 *)(*(int *)(param_1 + 0x9c) + 8),0x7ff);
    }
    return 1;
  }
  uVar1 = FUN_007420e0(param_2,param_3);
  return uVar1;
}


/* ==================================================================== */
/* Address: 0x0074bd20 | Classified: AngelicaUI::proc_74bd20 */
/* ==================================================================== */

undefined4 * __fastcall FUN_0074bd20(undefined4 *param_1)

{
  FUN_00741960();
  *param_1 = &UNK_008ef0d4;
  param_1[0x28] = 0xffffffff;
  param_1[0x29] = 0xffffffff;
  param_1[0xf] = 10;
  param_1[0x27] = 0;
  param_1[0x10] = 0;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0074bd60 | Classified: AUIRadioButton::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0074bd60(undefined4 param_1,byte param_2)

{
  FUN_0074bd80();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0074bd80 | Classified: AngelicaUI::proc_74bd80 */
/* ==================================================================== */

void __fastcall FUN_0074bd80(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  *param_1 = &UNK_008ef0d4;
  puStack_8 = &UNK_008ca630;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008eece0;
  iStack_4 = 6;
  func_0x007637f0();
  iStack_4._0_1_ = 5;
  func_0x007637f0();
  iStack_4._0_1_ = 4;
  FUN_00765200();
  iStack_4._0_1_ = 3;
  FUN_00765200();
  iStack_4._0_1_ = 2;
  FUN_00765200();
  iStack_4._0_1_ = 1;
  func_0x007637f0();
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  func_0x007637f0();
  iStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x0074bff0 | Classified: AUIRadioButton::vfunc_slot_3 */
/* ==================================================================== */

void __fastcall FUN_0074bff0(int param_1)

{
  if (*(int *)(param_1 + 0x9c) != 0) {
    func_0x0078c040();
    if (*(undefined4 **)(param_1 + 0x9c) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x9c))(1);
    }
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  FUN_00430850();
  return;
}


/* ==================================================================== */
/* Address: 0x0074c280 | Classified: AngelicaUI::proc_74c280 */
/* ==================================================================== */

undefined4 __fastcall FUN_0074c280(int param_1)

{
  return CONCAT31((int3)((uint)*(int *)(param_1 + 0x40) >> 8),*(int *)(param_1 + 0x40) != 0);
}


/* ==================================================================== */
/* Address: 0x0074c290 | Classified: AngelicaUI::proc_74c290 */
/* ==================================================================== */

void __thiscall FUN_0074c290(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x40) = param_2 & 0xff;
  return;
}


/* ==================================================================== */
/* Address: 0x0074c2a0 | Classified: AngelicaUI::proc_74c2a0 */
/* ==================================================================== */

void __thiscall FUN_0074c2a0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xa0) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x0074c2b0 | Classified: AngelicaUI::proc_74c2b0 */
/* ==================================================================== */

undefined4 __fastcall FUN_0074c2b0(int param_1)

{
  return *(undefined4 *)(param_1 + 0xa4);
}


/* ==================================================================== */
/* Address: 0x0074c2c0 | Classified: AngelicaUI::proc_74c2c0 */
/* ==================================================================== */

void __thiscall FUN_0074c2c0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xa4) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x0074c2d0 | Classified: AUIRadioButton::vfunc_slot_9 */
/* ==================================================================== */

undefined4 __thiscall FUN_0074c2d0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = param_3;
  for (iVar2 = 0x402; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  iVar2 = _strcmpi(param_2,0x9664d8);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x9c) != 0) {
      strncpy(param_3,*(undefined4 *)(*(int *)(param_1 + 0x9c) + 8),0x7ff);
      return 1;
    }
  }
  else {
    iVar2 = _strcmpi(param_2,0x980f10);
    if (iVar2 == 0) {
      *param_3 = *(undefined4 *)(param_1 + 0xa0);
      return 1;
    }
    iVar2 = _strcmpi(param_2,0x980f04);
    if (iVar2 != 0) {
      uVar1 = FUN_007420e0(param_2,param_3);
      return uVar1;
    }
    *param_3 = *(undefined4 *)(param_1 + 0xa4);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0074c410 | Classified: AngelicaUI::proc_74c410 */
/* ==================================================================== */

undefined4 * __fastcall FUN_0074c410(undefined4 *param_1)

{
  FUN_00741960();
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x28] = 0;
  param_1[0x10] = 0;
  param_1[0x2b] = 0;
  param_1[0x2d] = 0;
  param_1[0x2c] = 0;
  *(undefined1 *)(param_1 + 0x2a) = 0;
  *param_1 = &UNK_008ef184;
  param_1[0xf] = 2;
  param_1[0x29] = 0xffffffff;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0074c470 | Classified: AUIComboBox::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0074c470(undefined4 param_1,byte param_2)

{
  FUN_0074c490();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0074c490 | Classified: AngelicaUI::proc_74c490 */
/* ==================================================================== */

void __fastcall FUN_0074c490(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int unaff_EBX;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  puStack_8 = &UNK_008caeab;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008ef184;
  uVar3 = param_1[0x2e];
  iStack_4 = 0;
  uVar2 = uVar3 + param_1[0x31] * 0x18;
  if (uVar3 != uVar2) {
    uVar5 = uVar3;
    if (uVar2 < (uint)param_1[0x2f]) {
      puVar6 = (undefined4 *)(uVar2 + 8);
      do {
        FUN_007652d0(puVar6 + -2);
        *(undefined4 *)(uVar5 + 4) = puVar6[-1];
        *(undefined4 *)(unaff_EBX + (int)puVar6) = *puVar6;
        *(undefined4 *)(uVar5 + 0xc) = puVar6[1];
        func_0x00763940(puVar6 + 2);
        func_0x00763940(puVar6 + 3);
        uVar5 = uVar5 + 0x18;
        puVar1 = puVar6 + 4;
        puVar6 = puVar6 + 6;
      } while (puVar1 < (undefined4 *)param_1[0x2f]);
    }
    if (uVar5 < (uint)param_1[0x2f]) {
      do {
        iStack_4._0_1_ = 2;
        func_0x007637f0();
        iStack_4._0_1_ = 1;
        func_0x007637f0();
        iStack_4 = (uint)iStack_4._1_3_ << 8;
        FUN_00765200();
        uVar5 = uVar5 + 0x18;
      } while (uVar5 < (uint)param_1[0x2f]);
    }
    iVar4 = (int)(uVar2 - uVar3) / 0x18;
    param_1[0x2f] = param_1[0x2f] + iVar4 * -0x18;
    param_1[0x31] = param_1[0x31] - iVar4;
  }
  if (param_1[0x2e] != 0) {
    func_0x00763260(param_1[0x2e]);
  }
  iStack_4 = 0xffffffff;
  FUN_00741b50();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x0074cea0 | Classified: AUIComboBox::vfunc_slot_3 */
/* ==================================================================== */

void __fastcall FUN_0074cea0(int param_1)

{
  FUN_0074db90();
  if (*(int *)(param_1 + 0xac) != 0) {
    FUN_00753080();
    if (*(undefined4 **)(param_1 + 0xac) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0xac))(1);
    }
    *(undefined4 *)(param_1 + 0xac) = 0;
  }
  if (*(int *)(param_1 + 0xb4) != 0) {
    func_0x0078c040();
    if (*(undefined4 **)(param_1 + 0xb4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0xb4))(1);
    }
    *(undefined4 *)(param_1 + 0xb4) = 0;
  }
  FUN_00430850();
  return;
}


/* ==================================================================== */
/* Address: 0x0074d8e0 | Classified: AngelicaUI::proc_74d8e0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0074d8e0(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 *unaff_FS_OFFSET;
  int iVar9;
  int iStack_38;
  undefined1 auStack_28 [4];
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8._0_1_ = 0x6d;
  uStack_8._1_3_ = 0x8caf;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_24 = _DAT_00985a98;
  uStack_14 = _DAT_009858e4;
  uStack_10 = _DAT_009858e4;
  uVar4 = 0;
  uStack_4 = 0;
  FUN_00765230(param_2);
  uVar7 = *(uint *)(param_1 + 0xc4);
  uStack_1c = *(undefined4 *)(param_1 + 0x38);
  piVar1 = (int *)(param_1 + 0xb8);
  uStack_20 = 0;
  uStack_24 = 0;
  iVar9 = param_1;
  if (uVar7 == *(uint *)(param_1 + 0xc0)) {
    if (uVar7 + 1 < 5) {
      iVar9 = 5;
    }
    else {
      iVar9 = uVar7 + 3 + (uVar7 >> 1);
    }
    iVar3 = func_0x00763250(iVar9 * 0x18);
    iVar5 = *piVar1;
    iVar8 = iVar3;
    if (*(int *)(param_1 + 0xc4) != 0) {
      do {
        uStack_8._0_1_ = 1;
        iVar6 = iVar5;
        if (iVar8 != 0) {
          iVar6 = iVar5 + 0x18;
          FUN_0074e500(iVar5);
        }
        uVar4 = uVar4 + 1;
        uStack_8._0_1_ = 0;
        iVar5 = iVar6;
        iVar8 = iVar8 + 0x18;
      } while (uVar4 < *(uint *)(param_1 + 0xc4));
    }
    uVar7 = 0;
    if (*(int *)(param_1 + 0xc4) != 0) {
      do {
        FUN_0074da90();
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(uint *)(param_1 + 0xc4));
    }
    if (*piVar1 != 0) {
      func_0x00763260(*piVar1);
    }
    *piVar1 = iVar3;
    *(int *)(param_1 + 0xc0) = iVar9;
    *(int *)(param_1 + 0xbc) = iVar3 + *(int *)(param_1 + 0xc4) * 0x18;
    iVar9 = iStack_38;
  }
  uStack_8 = CONCAT31(uStack_8._1_3_,2);
  if (*(int *)(param_1 + 0xbc) != 0) {
    FUN_0074e500(auStack_28);
  }
  *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + 1;
  *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + 0x18;
  uVar2 = *(undefined4 *)(iVar9 + 0xc4);
  uStack_8 = 4;
  func_0x007637f0();
  uStack_8 = CONCAT31(uStack_8._1_3_,3);
  func_0x007637f0();
  uStack_8 = 0xffffffff;
  FUN_00765200();
  *unaff_FS_OFFSET = uStack_10;
  return uVar2;
}


/* ==================================================================== */
/* Address: 0x0074da90 | Classified: AngelicaUI::proc_74da90 */
/* ==================================================================== */

void FUN_0074da90(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  uint uStack_4;
  
  puStack_8 = &UNK_008caf93;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 1;
  func_0x007637f0();
  uStack_4 = uStack_4 & 0xffffff00;
  func_0x007637f0();
  uStack_4 = 0xffffffff;
  FUN_00765200();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x0074daf0 | Classified: AngelicaUI::proc_74daf0 */
/* ==================================================================== */

undefined4 __fastcall FUN_0074daf0(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc4);
}


/* ==================================================================== */
/* Address: 0x0074db00 | Classified: AngelicaUI::proc_74db00 */
/* ==================================================================== */

undefined4 __fastcall FUN_0074db00(int param_1)

{
  return *(undefined4 *)(param_1 + 0xa0);
}


/* ==================================================================== */
/* Address: 0x0074db10 | Classified: AngelicaUI::proc_74db10 */
/* ==================================================================== */

int __thiscall FUN_0074db10(int param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xc4))) {
    *(int *)(param_1 + 0xa0) = param_2;
    return param_2;
  }
  return -1;
}


/* ==================================================================== */
/* Address: 0x0074db30 | Classified: AngelicaUI::proc_74db30 */
/* ==================================================================== */

undefined4 __thiscall FUN_0074db30(int param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xc4))) {
    return *(undefined4 *)(*(int *)(param_1 + 0xb8) + param_2 * 0x18);
  }
  return 0x9b3c40;
}


/* ==================================================================== */
/* Address: 0x0074db60 | Classified: AngelicaUI::proc_74db60 */
/* ==================================================================== */

int __thiscall FUN_0074db60(int param_1,int param_2,undefined4 param_3)

{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xc4))) {
    *(undefined4 *)(*(int *)(param_1 + 0xb8) + 0xc + param_2 * 0x18) = param_3;
    return param_2;
  }
  return -1;
}


/* ==================================================================== */
/* Address: 0x0074db90 | Classified: AngelicaUI::proc_74db90 */
/* ==================================================================== */

void __fastcall FUN_0074db90(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  *(undefined4 *)(param_1 + 0xa0) = 0;
  uVar3 = *(uint *)(param_1 + 0xb8);
  uVar2 = uVar3 + *(int *)(param_1 + 0xc4) * 0x18;
  if (uVar3 != uVar2) {
    uVar6 = uVar3;
    if (uVar2 < *(uint *)(param_1 + 0xbc)) {
      puVar5 = (undefined4 *)(uVar2 + 8);
      do {
        FUN_007652d0(puVar5 + -2);
        *(undefined4 *)(uVar6 + 4) = puVar5[-1];
        *(undefined4 *)(uVar3 + (int)puVar5) = *puVar5;
        *(undefined4 *)(uVar6 + 0xc) = puVar5[1];
        func_0x00763940(puVar5 + 2);
        func_0x00763940(puVar5 + 3);
        uVar6 = uVar6 + 0x18;
        puVar1 = puVar5 + 4;
        puVar5 = puVar5 + 6;
      } while (puVar1 < *(undefined4 **)(param_1 + 0xbc));
    }
    if (uVar6 < *(uint *)(param_1 + 0xbc)) {
      do {
        FUN_0074da90();
        uVar6 = uVar6 + 0x18;
      } while (uVar6 < *(uint *)(param_1 + 0xbc));
    }
    iVar4 = (int)(uVar2 - uVar3) / 0x18;
    *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + iVar4 * -0x18;
    *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) - iVar4;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0074dc90 | Classified: AUIComboBox::vfunc_slot_9 */
/* ==================================================================== */

undefined4 __thiscall FUN_0074dc90(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = param_3;
  for (iVar2 = 0x402; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  iVar2 = _strcmpi(param_2,0x95d238);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0xac) != 0) {
      iVar2 = FUN_007537e0();
      strncpy(param_3,*(undefined4 *)(iVar2 + 8),0x7ff);
      return 1;
    }
  }
  else {
    iVar2 = _strcmpi(param_2,0x95d108);
    if (iVar2 != 0) {
      uVar1 = FUN_007420e0(param_2,param_3);
      return uVar1;
    }
    if (*(int *)(param_1 + 0xb4) != 0) {
      strncpy(param_3,*(undefined4 *)(*(int *)(param_1 + 0xb4) + 8),0x7ff);
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0074dfc0 | Classified: elementclient::AUIComboBox__GetItemDataPtr____d@0x74dfc0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0074dfc0(int param_1,int param_2)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_8 = &UNK_008cafa8;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xc4))) {
    iVar3 = *(int *)(param_1 + 0xb8) + param_2 * 0x18;
    if (*(int *)(iVar3 + 8) != 0) {
      cVar2 = func_0x00763c50(iVar3 + 0x14);
      if (cVar2 == '\0') {
        func_0x00739700(0x27b,1,0x982888);
      }
    }
    uStack_4 = 0xffffffff;
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xb8) + 8 + param_2 * 0x18);
    func_0x007637f0();
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  uStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}


/* ==================================================================== */
/* Address: 0x0074e090 | Classified: AngelicaUI::proc_74e090 */
/* ==================================================================== */

int __thiscall FUN_0074e090(int param_1,int param_2)

{
  undefined4 unaff_EBX;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_8 = &UNK_008cafc8;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xc4))) {
    func_0x00763940(&stack0x0000000c);
    puStack_8 = (undefined *)0xffffffff;
    *(int *)(*(int *)(param_1 + 0xb8) + 8 + param_2 * 0x18) = param_2;
    func_0x007637f0();
    *unaff_FS_OFFSET = unaff_EBX;
    return param_2;
  }
  uStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return -1;
}


/* ==================================================================== */
/* Address: 0x0074e140 | Classified: elementclient::AUIComboBox__GetItemData____data@0x74e140 */
/* ==================================================================== */

undefined4 __thiscall FUN_0074e140(int param_1,int param_2)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_8 = &UNK_008cafe8;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xc4))) {
    iVar3 = *(int *)(param_1 + 0xb8) + param_2 * 0x18;
    if (*(int *)(iVar3 + 4) != 0) {
      cVar2 = func_0x00763c50(iVar3 + 0x10);
      if (cVar2 == '\0') {
        func_0x00739700(0x293,1,0x9828bc);
      }
    }
    uStack_4 = 0xffffffff;
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xb8) + 4 + param_2 * 0x18);
    func_0x007637f0();
    *unaff_FS_OFFSET = uStack_c;
    return uVar1;
  }
  uStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return 0xffffffff;
}


/* ==================================================================== */
/* Address: 0x0074e210 | Classified: AngelicaUI::proc_74e210 */
/* ==================================================================== */

int __thiscall FUN_0074e210(int param_1,int param_2)

{
  undefined4 unaff_EBX;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_8 = &UNK_008cb008;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xc4))) {
    func_0x00763940(&stack0x0000000c);
    puStack_8 = (undefined *)0xffffffff;
    *(int *)(*(int *)(param_1 + 0xb8) + 4 + param_2 * 0x18) = param_2;
    func_0x007637f0();
    *unaff_FS_OFFSET = unaff_EBX;
    return param_2;
  }
  uStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return -1;
}


/* ==================================================================== */
/* Address: 0x0074e2c0 | Classified: AngelicaUI::proc_74e2c0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0074e2c0(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_EBX;
  int iVar2;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  int iVar4;
  undefined1 auStack_30 [3];
  char cStack_2d;
  int iStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008cb038;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_24 = _DAT_00985a98;
  uStack_14 = _DAT_009858e4;
  uStack_10 = _DAT_009858e4;
  uStack_4 = 0;
  iStack_2c = param_1;
  do {
    iVar2 = 0;
    cStack_2d = '\0';
    iStack_28 = 0;
    if (*(int *)(param_1 + 0xc4) == 1 || *(int *)(param_1 + 0xc4) + -1 < 0) break;
    do {
      if (param_2 == 0) {
        iVar1 = _wcsicmp(*(undefined4 *)(iVar2 + *(int *)(param_1 + 0xb8)),
                         *(undefined4 *)(*(int *)(param_1 + 0xb8) + iVar2 + 0x18));
        if (0 < iVar1) {
LAB_0074e370:
          iVar1 = iVar2 + *(int *)(param_1 + 0xb8);
          iVar4 = iVar1;
          FUN_007652d0();
          uStack_24 = *(undefined4 *)(iVar1 + 4);
          uStack_20 = *(undefined4 *)(iVar1 + 8);
          uStack_1c = *(undefined4 *)(iVar1 + 0xc);
          func_0x00763940(iVar1 + 0x10);
          func_0x00763940(iVar1 + 0x14);
          iVar1 = *(int *)(param_1 + 0xb8) + iVar2 + 0x18;
          iVar3 = *(int *)(param_1 + 0xb8) + iVar2;
          FUN_007652d0(iVar1);
          *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar1 + 4);
          *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar1 + 8);
          *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
          func_0x00763940(iVar1 + 0x10);
          func_0x00763940(iVar1 + 0x14);
          iVar1 = iVar2 + 0x18 + *(int *)(iVar4 + 0xb8);
          FUN_007652d0(&stack0xffffffc4);
          *(undefined4 *)(iVar1 + 4) = unaff_ESI;
          *(undefined4 *)(iVar1 + 8) = unaff_EBP;
          *(undefined4 *)(iVar1 + 0xc) = unaff_EBX;
          func_0x00763940(auStack_30);
          func_0x00763940(auStack_30);
          cStack_2d = '\x01';
          param_1 = iStack_2c;
        }
      }
      else if ((param_2 == 1) &&
              (iVar1 = _wcsicmp(*(undefined4 *)(iVar2 + *(int *)(param_1 + 0xb8)),
                                *(undefined4 *)(*(int *)(param_1 + 0xb8) + iVar2 + 0x18)), iVar1 < 0
              )) goto LAB_0074e370;
      iStack_28 = iStack_28 + 1;
      iVar2 = iVar2 + 0x18;
    } while (iStack_28 < *(int *)(param_1 + 0xc4) + -1);
  } while (cStack_2d != '\0');
  uStack_4 = 2;
  func_0x007637f0();
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  func_0x007637f0();
  uStack_4 = 0xffffffff;
  FUN_00765200();
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}


/* ==================================================================== */
/* Address: 0x0074e4b0 | Classified: AngelicaUI::proc_74e4b0 */
/* ==================================================================== */

void __fastcall FUN_0074e4b0(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  *(int *)(*(int *)(param_1 + 0xc) + 4) = param_1;
  FUN_007373f0(*(undefined4 *)(param_1 + 0x18));
  iVar2 = -1;
  pcVar3 = *(char **)(param_1 + 0x1c);
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (iVar2 != -2) {
    FUN_00767410(*(char **)(param_1 + 0x1c),0);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0074e4f0 | Classified: AngelicaUI::proc_74e4f0 */
/* ==================================================================== */

int __thiscall FUN_0074e4f0(int *param_1,int param_2)

{
  return *param_1 + param_2 * 0x18;
}


/* ==================================================================== */
/* Address: 0x0074e500 | Classified: AngelicaUI::proc_74e500 */
/* ==================================================================== */

int __thiscall FUN_0074e500(int param_1,int param_2)

{
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cb063;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_00765000(param_2);
  puStack_8 = (undefined *)0x0;
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  func_0x00763660(param_2 + 0x10);
  uStack_c = CONCAT31(uStack_c._1_3_,1);
  func_0x00763660(param_2 + 0x14);
  *unaff_FS_OFFSET = unaff_EDI;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0074e580 | Classified: AngelicaUI::proc_74e580 */
/* ==================================================================== */

undefined4 * __fastcall FUN_0074e580(undefined4 *param_1)

{
  func_0x00762560();
  *param_1 = &UNK_008ef234;
  param_1[0x10] = 0;
  *(undefined1 *)(param_1 + 0x2b) = 0;
  *(undefined1 *)((int)param_1 + 0xad) = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0xf] = 0xd;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0074e5c0 | Classified: AUIStillImageButton::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0074e5c0(undefined4 param_1,byte param_2)

{
  FUN_0074e5e0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0074e5e0 | Classified: AngelicaUI::proc_74e5e0 */
/* ==================================================================== */

void __fastcall FUN_0074e5e0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  *param_1 = &UNK_008ef234;
  *param_1 = &UNK_008efa7c;
  puStack_8 = &UNK_008ca630;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008eece0;
  iStack_4 = 6;
  func_0x007637f0();
  iStack_4._0_1_ = 5;
  func_0x007637f0();
  iStack_4._0_1_ = 4;
  FUN_00765200();
  iStack_4._0_1_ = 3;
  FUN_00765200();
  iStack_4._0_1_ = 2;
  FUN_00765200();
  iStack_4._0_1_ = 1;
  func_0x007637f0();
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  func_0x007637f0();
  iStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x0074ed70 | Classified: AUIStillImageButton::vfunc_slot_3 */
/* ==================================================================== */

void __fastcall FUN_0074ed70(int param_1)

{
  if (*(int *)(param_1 + 0xb0) != 0) {
    func_0x0078c040();
    if (*(undefined4 **)(param_1 + 0xb0) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0xb0))(1);
    }
    *(undefined4 *)(param_1 + 0xb0) = 0;
  }
  if (*(int *)(param_1 + 0xb4) != 0) {
    FUN_00753080();
    if (*(undefined4 **)(param_1 + 0xb4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0xb4))(1);
    }
    *(undefined4 *)(param_1 + 0xb4) = 0;
  }
  if (*(int *)(param_1 + 0xb8) != 0) {
    FUN_00753080();
    if (*(undefined4 **)(param_1 + 0xb8) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0xb8))(1);
    }
    *(undefined4 *)(param_1 + 0xb8) = 0;
  }
  thunk_FUN_00430850();
  return;
}


/* ==================================================================== */
/* Address: 0x0074f050 | Classified: AUIStillImageButton::vfunc_slot_6 */
/* ==================================================================== */

undefined4 __fastcall FUN_0074f050(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  undefined4 uVar10;
  undefined4 *unaff_FS_OFFSET;
  int iVar11;
  uint uVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cb0d7;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if ((*(int *)(param_1 + 0xb4) == 0) || (*(int *)(param_1 + 0xb8) == 0)) {
    uVar10 = FUN_00430850();
    *unaff_FS_OFFSET = uStack_c;
    return uVar10;
  }
  FUN_00741db0(&iStack_1c,0);
  uVar10 = *(undefined4 *)(param_1 + 0x60);
  iVar1 = *(int *)(param_1 + 100);
  iVar14 = 0;
  iVar15 = 0;
  iVar7 = FUN_00741f10();
  if ((iVar7 != 0) || (*(char *)(param_1 + 0xac) != '\0')) {
    iVar15 = 1;
    iVar14 = 1;
  }
  if (*(int *)(param_1 + 0xb0) != 0) {
    FUN_007537a0(&iStack_1c);
    *(int *)(param_1 + 0x58) = (iStack_1c * 2) / 3 + 2 + *(int *)(*(int *)(param_1 + 0xb0) + 0x34);
    *(int *)(param_1 + 0x5c) = (iStack_18 * 2) / 3 + 2 + *(int *)(*(int *)(param_1 + 0xb0) + 0x38);
  }
  if (*(char *)(param_1 + 0x46) == '\0') {
    iVar7 = -0x7f7f80;
    iVar8 = FUN_007537e0();
    *(undefined4 *)(iVar8 + 0x6c) = 0xffa0a0a0;
  }
  else {
    iVar7 = *(int *)(param_1 + 0x38);
    iVar8 = FUN_007537e0();
    *(undefined4 *)(iVar8 + 0x6c) = 0xffffffff;
  }
  iVar8 = *(int *)(param_1 + 0x34);
  if (iVar8 == 0) {
    func_0x00868610();
    iVar8 = FUN_007537e0();
  }
  if ((*(int *)(param_1 + 0xb0) == 0) &&
     ((*(char *)(param_1 + 0x81) == '\0' || (*(char *)(param_1 + 0x80) == '\0')))) {
    puVar9 = (uint *)(param_1 + 0x74);
  }
  else {
    puVar9 = (uint *)FUN_00765050(0x9b3c40);
    uStack_c = 0;
  }
  uVar12 = *puVar9;
  uVar13 = 0;
  iVar11 = iVar7;
  cVar6 = FUN_007530d0(uVar10,iStack_20 + iVar1,*(undefined4 *)(param_1 + 0x58),
                       *(undefined4 *)(param_1 + 0x5c),iVar8,iVar7,uVar12,
                       *(undefined4 *)(param_1 + 0x70),iVar14,iVar15,*(undefined4 *)(param_1 + 0x84)
                       ,0);
  if ((uVar12 & 1) != 0) {
    FUN_00765200();
  }
  if (cVar6 != '\0') {
    iVar1 = *(int *)(param_1 + 0xb0);
    if (iVar1 != 0) {
      iVar2 = *(int *)(param_1 + 0x58);
      iVar3 = *(int *)(iVar1 + 0x34);
      iVar4 = *(int *)(iVar1 + 0x38);
      iVar5 = *(int *)(param_1 + 0x5c);
      *(int *)(iVar1 + 0x6c) = iVar7;
      *(uint *)(*(int *)(param_1 + 0xb0) + 0x6c) =
           *(uint *)(*(int *)(param_1 + 0xb0) + 0x6c) & 0xffffff | *(int *)(param_1 + 0x84) << 0x18;
      if (*(char *)(*(int *)(param_1 + 0xc) + 0x62) == '\0') {
        cVar6 = func_0x0078c490((float)((iVar2 - iVar3) / 2 + iVar14 + iVar8),
                                (float)((iVar5 - iVar4) / 2 + iVar15 + iVar11));
      }
      else {
        cVar6 = func_0x0078c3a0();
      }
      if (cVar6 == '\0') {
        uVar10 = func_0x00739700(0x13d,1,0x982ac8);
        *unaff_FS_OFFSET = uVar13;
        return uVar10;
      }
    }
    *unaff_FS_OFFSET = uVar13;
    return 1;
  }
  uVar10 = func_0x00739700(0x12f,1,0x982b3c);
  *unaff_FS_OFFSET = uVar13;
  return uVar10;
}


/* ==================================================================== */
/* Address: 0x0074f340 | Classified: AUIStillImageButton::vfunc_slot_9 */
/* ==================================================================== */

undefined4 __thiscall FUN_0074f340(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = param_3;
  for (iVar2 = 0x402; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  iVar2 = _strcmpi(param_2,0x95d208);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0xb4) != 0) {
      iVar2 = FUN_007537e0();
      strncpy(param_3,*(undefined4 *)(iVar2 + 8),0x7ff);
      return 1;
    }
  }
  else {
    iVar2 = _strcmpi(param_2,0x95d1e0);
    if (iVar2 != 0) {
      uVar1 = func_0x00762710(param_2,param_3);
      return uVar1;
    }
    if (*(int *)(param_1 + 0xb8) != 0) {
      iVar2 = FUN_007537e0();
      strncpy(param_3,*(undefined4 *)(iVar2 + 8),0x7ff);
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0074f500 | Classified: AngelicaUI::proc_74f500 */
/* ==================================================================== */

undefined4 __thiscall FUN_0074f500(int param_1,char param_2)

{
  if (param_2 != '\0') {
    return *(undefined4 *)(param_1 + 0xb4);
  }
  return *(undefined4 *)(param_1 + 0xb8);
}


/* ==================================================================== */
/* Address: 0x0074f520 | Classified: AngelicaUI::proc_74f520 */
/* ==================================================================== */

void __thiscall FUN_0074f520(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0xad) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x0074f530 | Classified: AngelicaUI::proc_74f530 */
/* ==================================================================== */

undefined1 __fastcall FUN_0074f530(int param_1)

{
  return *(undefined1 *)(param_1 + 0xac);
}


/* ==================================================================== */
/* Address: 0x0074f540 | Classified: AngelicaUI::proc_74f540 */
/* ==================================================================== */

void __thiscall FUN_0074f540(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0xac) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x0074f550 | Classified: AngelicaUI::proc_74f550 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_0074f550(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cb12f;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_00741960();
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x35] = _DAT_00985a98;
  param_1[0x3d] = _DAT_00985a98;
  param_1[0x3e] = _DAT_009858e4;
  param_1[0x3f] = _DAT_009858e4;
  uStack_4 = 5;
  FUN_00765230(0x9b3c40);
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0xffffffff;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  *param_1 = &UNK_008ef2e4;
  param_1[0xf] = 0xf;
  param_1[0x27] = 0;
  param_1[0x34] = 0;
  param_1[0x2c] = 0;
  *(undefined1 *)(param_1 + 0x2a) = 0;
  uVar1 = GetTickCount();
  param_1[0x2d] = uVar1;
  param_1[0x2b] = 0;
  param_1[0x29] = 0;
  param_1[0x28] = 0;
  param_1[0x2f] = 0;
  param_1[0x2e] = 0;
  param_1[0x47] = 0;
  param_1[0x46] = 1;
  param_1[0x48] = 0;
  puVar3 = param_1 + 0x49;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *unaff_FS_OFFSET = param_1 + 0x35;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0074f680 | Classified: AUITreeView::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0074f680(undefined4 param_1,byte param_2)

{
  FUN_0074f6a0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0074f6a0 | Classified: AngelicaUI::proc_74f6a0 */
/* ==================================================================== */

void __fastcall FUN_0074f6a0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008cb174;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008ef2e4;
  uStack_4._0_1_ = 4;
  uStack_4._1_3_ = 0;
  func_0x007637f0();
  uStack_4._0_1_ = 3;
  func_0x007637f0();
  uStack_4._0_1_ = 2;
  FUN_00765200();
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  FUN_00765200();
  puVar2 = (undefined4 *)param_1[0x30];
  puVar1 = puVar2 + param_1[0x33];
  if (puVar2 != puVar1) {
    puVar4 = puVar1;
    puVar6 = puVar2;
    if (puVar1 < (undefined4 *)param_1[0x31]) {
      do {
        puVar5 = puVar4 + 1;
        *puVar6 = *puVar4;
        puVar4 = puVar5;
        puVar6 = puVar6 + 1;
      } while (puVar5 < (undefined4 *)param_1[0x31]);
    }
    iVar3 = (int)puVar1 - (int)puVar2 >> 2;
    param_1[0x31] = param_1[0x31] + iVar3 * -4;
    param_1[0x33] = param_1[0x33] - iVar3;
  }
  if (param_1[0x30] != 0) {
    func_0x00763260(param_1[0x30]);
  }
  uStack_4 = 0xffffffff;
  FUN_00741b50();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x00750020 | Classified: AUITreeView::vfunc_slot_3 */
/* ==================================================================== */

void __fastcall FUN_00750020(int param_1)

{
  int iVar1;
  int *piVar2;
  
  FUN_00751a80();
  if (*(int *)(param_1 + 0x120) != 0) {
    FUN_00753080();
    if (*(undefined4 **)(param_1 + 0x120) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x120))(1);
    }
    *(undefined4 *)(param_1 + 0x120) = 0;
  }
  piVar2 = (int *)(param_1 + 0x124);
  iVar1 = 9;
  do {
    if (*piVar2 != 0) {
      func_0x0078c040();
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_00430850();
  return;
}


/* ==================================================================== */
/* Address: 0x007501b0 | Classified: AUITreeView::vfunc_slot_7 */
/* ==================================================================== */

undefined4 __thiscall FUN_007501b0(int param_1,int param_2,undefined4 param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int unaff_EBX;
  int iVar10;
  int unaff_EBP;
  int iVar11;
  uint uVar12;
  int unaff_retaddr;
  char cVar13;
  int aiStack_64 [2];
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  int iStack_50;
  int iStack_48;
  int iStack_40;
  int iStack_38;
  int iStack_34;
  int iStack_2c;
  int iStack_20;
  int iStack_18;
  int iStack_10;
  byte bStack_4;
  
  if (*(int *)(param_1 + 0x120) == 0) {
    return 1;
  }
  if (*(int *)(param_1 + 300) == 0) {
    return 1;
  }
  if (*(int *)(param_1 + 0x130) == 0) {
    return 1;
  }
  if (*(int *)(param_1 + 0x134) == 0) {
    return 1;
  }
  FUN_007537a0();
  uVar8 = *(uint *)(param_1 + 0xcc);
  iVar3 = iStack_5c / 2;
  iVar5 = *(int *)(param_1 + 0x5c);
  iVar10 = iStack_58 / 2;
  iVar4 = (iVar5 + iVar10 * -2) / (*(int *)(param_1 + 0xbc) + 3);
  iVar2 = **(int **)(*(int *)(param_1 + 300) + 0x24);
  iStack_10 = *(int *)(iVar2 + 0xc);
  iVar9 = **(int **)(*(int *)(param_1 + 0x130) + 0x24);
  iStack_40 = *(int *)(iVar9 + 0xc);
  iStack_38 = *(int *)(iVar9 + 0x14);
  iVar9 = **(int **)(*(int *)(param_1 + 0x134) + 0x24);
  iStack_34 = *(int *)(iVar9 + 8);
  iStack_2c = *(int *)(iVar9 + 0x10);
  iVar9 = *(int *)(param_1 + 0x58);
  iVar11 = ((iVar9 - iStack_2c) - iVar3) + iStack_34;
  aiStack_64[0] = iVar5 - iVar10;
  iStack_54 = (iVar9 - iStack_2c) + iStack_34;
  iStack_50 = *(int *)(iVar2 + 0x14) - iStack_10;
  iStack_48 = (iVar5 - iStack_38) + iStack_40;
  if (*(int *)(param_1 + 0x134) != 0) {
    if (iVar4 < (int)uVar8) {
      iVar5 = iStack_2c - iStack_34;
    }
    else {
      iVar5 = 0;
    }
    iVar11 = (iVar9 - iVar5) - iVar3;
  }
  iStack_18 = aiStack_64[0];
  if ((((unaff_retaddr != 0x201) && (unaff_retaddr != 0x204)) && (unaff_retaddr != 0x203)) &&
     ((unaff_retaddr != 0x200 && (unaff_retaddr != 0x202)))) {
    if (unaff_retaddr == 8) {
      *(undefined1 *)(param_1 + 0xa8) = 0;
      *(undefined4 *)(param_1 + 0x9c) = 0;
    }
    else {
      if (unaff_retaddr == 0x20a) {
        if ((0 < (short)((uint)param_2 >> 0x10)) && (0 < *(int *)(param_1 + 0xb0))) {
          *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0xb0) + -1;
          return 1;
        }
        if (-1 < param_2) {
          return 1;
        }
        if ((int)uVar8 <= iVar4 + *(int *)(param_1 + 0xb0)) {
          return 1;
        }
        *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0xb0) + 1;
        return 1;
      }
      if ((unaff_retaddr == 0x100) && (iVar5 = *(int *)(param_1 + 0x11c), iVar5 != 0)) {
        if (param_2 == 0x26) {
          uVar12 = 1;
          if (uVar8 < 2) {
            return 1;
          }
          piVar7 = *(int **)(param_1 + 0xc0);
          while (piVar7 = piVar7 + 1, (*(byte *)(*piVar7 + 0x44) & 2) == 0) {
            uVar12 = uVar12 + 1;
            if (uVar8 <= uVar12) {
              return 1;
            }
          }
          FUN_00752110((*(int **)(param_1 + 0xc0))[uVar12 - 1]);
          uVar12 = uVar12 - 1;
LAB_00750444:
          if (*(int *)(param_1 + 0xb0) <= (int)uVar12) {
            return 1;
          }
          *(uint *)(param_1 + 0xb0) = uVar12;
          return 1;
        }
        if (param_2 == 0x28) {
          uVar12 = 0;
          if (uVar8 == 1) {
            return 1;
          }
          piVar7 = *(int **)(param_1 + 0xc0);
          while ((*(byte *)(*piVar7 + 0x44) & 2) == 0) {
            uVar12 = uVar12 + 1;
            piVar7 = piVar7 + 1;
            if (uVar8 - 1 <= uVar12) {
              return 1;
            }
          }
          FUN_00752110((*(int **)(param_1 + 0xc0))[uVar12 + 1]);
          if ((int)(uVar12 + 1) < *(int *)(param_1 + 0xb0) + unaff_EBX) {
            return 1;
          }
          *(uint *)(param_1 + 0xb0) = (uVar12 - unaff_EBX) + 2;
          return 1;
        }
        if (param_2 == 0x25) {
          if ((*(byte *)(iVar5 + 0x44) & 1) == 0) {
            if (*(int *)(iVar5 + 0x2c) == param_1 + 0xd4) {
              return 1;
            }
            FUN_00752110(*(int *)(iVar5 + 0x2c));
            uVar12 = 0;
            if (*(uint *)(param_1 + 0xcc) == 0) {
              return 1;
            }
            piVar7 = *(int **)(param_1 + 0xc0);
            while ((*(byte *)(*piVar7 + 0x44) & 2) == 0) {
              uVar12 = uVar12 + 1;
              piVar7 = piVar7 + 1;
              if (*(uint *)(param_1 + 0xcc) <= uVar12) {
                return 1;
              }
            }
            goto LAB_00750444;
          }
        }
        else {
          if (param_2 != 0x27) goto LAB_00750360;
          if (*(int *)(iVar5 + 0x30) == 0) {
            return 1;
          }
          if ((*(byte *)(iVar5 + 0x44) & 1) != 0) {
            FUN_00752110(*(int *)(iVar5 + 0x30));
            uVar8 = 0;
            if (*(uint *)(param_1 + 0xcc) == 0) {
              return 1;
            }
            piVar7 = *(int **)(param_1 + 0xc0);
            while ((*(byte *)(*piVar7 + 0x44) & 2) == 0) {
              uVar8 = uVar8 + 1;
              piVar7 = piVar7 + 1;
              if (*(uint *)(param_1 + 0xcc) <= uVar8) {
                return 1;
              }
            }
            if ((int)uVar8 < *(int *)(param_1 + 0xb0) + unaff_EBX) {
              return 1;
            }
            *(uint *)(param_1 + 0xb0) = (uVar8 - unaff_EBX) + 1;
            return 1;
          }
        }
        FUN_007520a0(iVar5,2);
        return 1;
      }
    }
LAB_00750360:
    uVar6 = func_0x00773a20(unaff_retaddr,param_2,param_3);
    return uVar6;
  }
  cVar13 = '\0';
  FUN_00741db0(aiStack_64);
  iVar3 = ((int)(short)unaff_retaddr - *(int *)(param_1 + 0x60)) - iVar3;
  iVar9 = ((int)(short)((uint)unaff_retaddr >> 0x10) - *(int *)(param_1 + 100)) - iVar9;
  if (unaff_retaddr == 0x202) {
    *(undefined1 *)(param_1 + 0xa8) = 0;
    FUN_00738340(0);
    *(undefined4 *)(param_1 + 0x9c) = 0;
    return 1;
  }
  if ((*(char *)(param_1 + 0xa8) != '\0') ||
     ((((iStack_5c <= iVar3 && (iVar3 < (int)uVar8)) && (iStack_58 <= iVar9)) && (iVar9 < iStack_50)
      ))) {
    iVar5 = **(int **)(*(int *)(param_1 + 0x138) + 0x24);
    iVar5 = *(int *)(iVar5 + 0x14) - *(int *)(iVar5 + 0xc);
    if (unaff_retaddr != 0x200) {
      iVar2 = *(int *)(param_1 + 0xa4);
      if (iVar9 < iVar2) {
        if ((unaff_retaddr != 0x201) && (unaff_retaddr != 0x203)) {
          return 1;
        }
        *(undefined4 *)(param_1 + 0x9c) = 1;
        *(undefined4 *)(param_1 + 0xb4) = 0xffffffff;
        return 1;
      }
      if (iVar5 + iVar2 < iVar9) {
        if ((unaff_retaddr != 0x201) && (unaff_retaddr != 0x203)) {
          return 1;
        }
        *(undefined4 *)(param_1 + 0x9c) = 2;
        *(undefined4 *)(param_1 + 0xb4) = 0xffffffff;
        return 1;
      }
      if (unaff_EBX <= unaff_EBP) {
        return 1;
      }
      if (unaff_retaddr != 0x201) {
        return 1;
      }
      *(undefined1 *)(param_1 + 0xa8) = 1;
      *(int *)(param_1 + 0xac) = iVar9 - iVar2;
      FUN_00738340(param_1);
      *(undefined4 *)(param_1 + 0x9c) = 3;
      return 1;
    }
    if ((bStack_4 & 1) == 0) {
      *(undefined1 *)(param_1 + 0xa8) = 0;
      FUN_00738340(0);
      return 1;
    }
    if (*(int *)(param_1 + 0x9c) != 3) {
      return 1;
    }
    if (unaff_EBX <= unaff_EBP) {
      return 1;
    }
    iVar5 = (iStack_50 - iStack_58) - iVar5;
    if (iVar5 < 1) {
      return 1;
    }
    *(int *)(param_1 + 0xb0) =
         (((iVar9 - *(int *)(param_1 + 0xac)) - iStack_58) * ((unaff_EBX - unaff_EBP) + 1)) / iVar5;
    iVar5 = *(int *)(param_1 + 0xcc) - unaff_EBP;
    if (*(int *)(param_1 + 0xb0) < 0) {
      *(undefined4 *)(param_1 + 0xb0) = 0;
    }
    if (*(int *)(param_1 + 0xb0) <= iVar5) {
      return 1;
    }
    *(int *)(param_1 + 0xb0) = iVar5;
    return 1;
  }
  if ((((iVar3 < iVar4) || (iVar11 <= iVar3)) || (iVar9 < iVar10)) || (iStack_20 <= iVar9)) {
    if (iVar3 < iStack_5c) {
      return 1;
    }
    if ((int)uVar8 < iVar3) {
      return 1;
    }
    if (iVar9 < iStack_58) {
      if ((unaff_retaddr != 0x201) && (unaff_retaddr != 0x203)) {
        return 1;
      }
      *(undefined4 *)(param_1 + 0x9c) = 1;
      return 1;
    }
    if (iVar9 <= iStack_50) {
      return 1;
    }
    if ((unaff_retaddr != 0x201) && (unaff_retaddr != 0x203)) {
      return 1;
    }
    *(undefined4 *)(param_1 + 0x9c) = 2;
    return 1;
  }
  if (((unaff_retaddr != 0x201) && (unaff_retaddr != 0x204)) && (unaff_retaddr != 0x203)) {
    return 1;
  }
  iVar5 = FUN_00751e00(iVar3,iVar9,&stack0xffffff83);
  if (iVar5 == 0) {
    return 1;
  }
  if (cVar13 == '\0') {
    if (*(int *)(param_1 + 0x11c) != 0) {
      puVar1 = (uint *)(*(int *)(param_1 + 0x11c) + 0x44);
      *puVar1 = *puVar1 & 0xfffffffd;
    }
    *(int *)(param_1 + 0x11c) = iVar5;
    *(uint *)(iVar5 + 0x44) = *(uint *)(iVar5 + 0x44) | 2;
    if (unaff_retaddr != 0x203) goto LAB_00750700;
  }
  else if (*(int *)(iVar5 + 0x30) == 0) goto LAB_00750700;
  FUN_007520a0(iVar5,2);
LAB_00750700:
  iVar5 = *(int *)(param_1 + 0xcc) - (int)&iStack_58;
  if ((0 < iVar5) && (iVar5 < *(int *)(param_1 + 0xb0))) {
    *(int *)(param_1 + 0xb0) = iVar5;
    return 1;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00750f30 | Classified: elementclient::AUITreeView__RenderScroll____fai@0x750f30 */
/* ==================================================================== */

undefined4 __fastcall FUN_00750f30(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  int *unaff_EDI;
  int iVar12;
  int *piVar13;
  int iVar14;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  if (((*(int *)(param_1 + 300) != 0) && (*(int *)(param_1 + 0x130) != 0)) &&
     (*(int *)(param_1 + 0x134) != 0)) {
    piVar13 = &iStack_28;
    iVar14 = 0;
    FUN_00741db0(piVar13,0);
    iVar8 = 0;
    if (*(int *)(param_1 + 0x120) != 0) {
      FUN_007537a0(&iStack_38);
      iVar8 = iStack_34 / 2;
    }
    iVar9 = (*(int *)(param_1 + 0x5c) + iVar8 * -2) / (*(int *)(param_1 + 0xbc) + 3);
    iVar8 = **(int **)(*(int *)(param_1 + 300) + 0x24);
    iVar1 = *(int *)(iVar8 + 0xc);
    iVar8 = *(int *)(iVar8 + 0x14);
    iVar2 = **(int **)(*(int *)(param_1 + 0x130) + 0x24);
    uStack_24 = *(undefined4 *)(iVar2 + 0xc);
    uStack_1c = *(undefined4 *)(iVar2 + 0x14);
    iVar2 = **(int **)(*(int *)(param_1 + 0x134) + 0x24);
    uStack_18 = *(undefined4 *)(iVar2 + 8);
    iVar12 = *(int *)(iVar2 + 0x14);
    uStack_14 = *(undefined4 *)(iVar2 + 0xc);
    uStack_10 = *(undefined4 *)(iVar2 + 0x10);
    iStack_30 = iStack_30 + *(int *)(param_1 + 0x60);
    iStack_2c = iStack_2c + *(int *)(param_1 + 100);
    uVar10 = (uint)(*(int *)(param_1 + 0x9c) == 1);
    cVar7 = func_0x0078c4e0();
    iVar2 = iStack_30;
    if (cVar7 == '\0') {
      uVar11 = func_0x00739700(0x2c4,1,0x983140);
      return uVar11;
    }
    iVar3 = **(int **)(*(int *)(param_1 + 0x134) + 0x24);
    fVar6 = (float)((*(int *)(iVar3 + 8) - *(int *)(iVar3 + 0x10)) + *(int *)(param_1 + 0x58) +
                   iStack_34);
    *(uint *)(*(int *)(param_1 + 300) + 0x6c) =
         *(int *)(param_1 + 0x84) << 0x18 | *(uint *)(*(int *)(param_1 + 300) + 0x6c) & 0xffffff;
    if (*(char *)(*(int *)(param_1 + 0xc) + 0x62) == '\0') {
      cVar7 = func_0x0078c490(fVar6,(float)iStack_30);
    }
    else {
      cVar7 = func_0x0078c3a0(fVar6);
    }
    if (cVar7 == '\0') {
      uVar11 = func_0x00739700(0x2ce,1,0x9830a4);
      return uVar11;
    }
    iVar3 = **(int **)(*(int *)(param_1 + 300) + 0x24);
    iVar4 = *(int *)(iVar3 + 0xc);
    iVar3 = *(int *)(iVar3 + 0x14);
    iVar12 = iVar12 - iStack_20;
    *(float *)(*(int *)(param_1 + 0x134) + 0x74) =
         (float)(((iVar1 - iVar8) - iStack_28) + iStack_30 + *(int *)(param_1 + 0x5c)) /
         (float)iVar12;
    *(uint *)(*(int *)(param_1 + 0x134) + 0x6c) =
         *(int *)(param_1 + 0x84) << 0x18 | *(uint *)(*(int *)(param_1 + 0x134) + 0x6c) & 0xffffff;
    if (*(char *)(*(int *)(param_1 + 0xc) + 0x62) == '\0') {
      cVar7 = func_0x0078c490(unaff_EDI,(float)(iVar14 + (iVar3 - iVar4)));
    }
    else {
      cVar7 = func_0x0078c3a0(unaff_EDI);
      piVar13 = unaff_EDI;
    }
    if (cVar7 == '\0') {
      uVar11 = func_0x00739700(0x2db,1,0x983000);
      return uVar11;
    }
    cVar7 = func_0x0078c4e0(*(int *)(param_1 + 0x9c) == 2);
    if (cVar7 == '\0') {
      uVar11 = func_0x00739700(0x2e0,1,0x982f9c);
      return uVar11;
    }
    iVar14 = (iVar9 - iStack_34) + iVar12 + *(int *)(param_1 + 0x5c);
    *(uint *)(*(int *)(param_1 + 0x130) + 0x6c) =
         *(int *)(param_1 + 0x84) << 0x18 | *(uint *)(*(int *)(param_1 + 0x130) + 0x6c) & 0xffffff;
    if (*(char *)(*(int *)(param_1 + 0xc) + 0x62) == '\0') {
      cVar7 = func_0x0078c490(piVar13,(float)iVar14);
    }
    else {
      cVar7 = func_0x0078c3a0();
    }
    if (cVar7 == '\0') {
      uVar11 = func_0x00739700(0x2e9,1,0x982efc);
      return uVar11;
    }
    if ((int)uVar10 < iVar14) {
      iVar3 = *(int *)(param_1 + 0x138);
      iVar4 = *(int *)(**(int **)(iVar3 + 0x24) + 0x14);
      iVar5 = *(int *)(**(int **)(iVar3 + 0x24) + 0xc);
      *(int *)(param_1 + 0xa0) = (*(int *)(param_1 + 0x58) - iStack_30) + iStack_38;
      *(int *)(param_1 + 0xa4) =
           ((*(int *)(param_1 + 0xb0) *
            ((((iVar5 - iVar4) - iVar8) - iVar9) + iVar1 + iVar12 + *(int *)(param_1 + 0x5c))) /
            (int)(iVar14 - uVar10) - iVar1) + iVar8;
      *(uint *)(iVar3 + 0x6c) =
           *(uint *)(iVar3 + 0x6c) & 0xffffff | *(int *)(param_1 + 0x84) << 0x18;
      if (*(char *)(*(int *)(param_1 + 0xc) + 0x62) == '\0') {
        cVar7 = func_0x0078c490((float)(*(int *)(param_1 + 0xa0) + (int)unaff_EDI),
                                (float)(*(int *)(param_1 + 0xa4) + iVar2));
      }
      else {
        cVar7 = func_0x0078c3a0((float)(*(int *)(param_1 + 0xa0) + (int)unaff_EDI),
                                (float)(*(int *)(param_1 + 0xa4) + iVar2));
      }
      if (cVar7 == '\0') {
        uVar11 = func_0x00739700(0x2f8,1,0x982e60);
        return uVar11;
      }
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00751840 | Classified: AngelicaUI::proc_751840 */
/* ==================================================================== */

int __fastcall FUN_00751840(int param_1)

{
  return param_1 + 0xd4;
}


/* ==================================================================== */
/* Address: 0x00751850 | Classified: AngelicaUI::proc_751850 */
/* ==================================================================== */

undefined4 FUN_00751850(int param_1)

{
  return *(undefined4 *)(param_1 + 0x2c);
}


/* ==================================================================== */
/* Address: 0x00751860 | Classified: AngelicaUI::proc_751860 */
/* ==================================================================== */

undefined4 FUN_00751860(int param_1)

{
  return *(undefined4 *)(param_1 + 0x30);
}


/* ==================================================================== */
/* Address: 0x00751870 | Classified: AngelicaUI::proc_751870 */
/* ==================================================================== */

undefined4 FUN_00751870(int param_1)

{
  return *(undefined4 *)(param_1 + 0x3c);
}


/* ==================================================================== */
/* Address: 0x00751880 | Classified: AngelicaUI::proc_751880 */
/* ==================================================================== */

undefined4 FUN_00751880(undefined4 *param_1)

{
  return *param_1;
}


/* ==================================================================== */
/* Address: 0x00751890 | Classified: AngelicaUI::proc_751890 */
/* ==================================================================== */

undefined4 FUN_00751890(undefined4 param_1,undefined4 param_2)

{
  FUN_00765230(param_2);
  return 1;
}


/* ==================================================================== */
/* Address: 0x007518b0 | Classified: elementclient::AUITreeView__GetItemData____data@0x7518b0 */
/* ==================================================================== */

undefined4 FUN_007518b0(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_8 = &UNK_008cb1f8;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    cVar2 = func_0x00763c50(param_1 + 0x24);
    if (cVar2 == '\0') {
      func_0x00739700(0x3a6,1,0x9831e8);
    }
  }
  uVar1 = *(undefined4 *)(param_1 + 4);
  uStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return uVar1;
}


/* ==================================================================== */
/* Address: 0x00751930 | Classified: AngelicaUI::proc_751930 */
/* ==================================================================== */

void FUN_00751930(int param_1)

{
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_8 = &UNK_008cb218;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  func_0x00763940(&stack0x0000000c);
  puStack_8 = (undefined *)0xffffffff;
  *(int *)(param_1 + 4) = param_1;
  func_0x007637f0();
  *unaff_FS_OFFSET = unaff_ESI;
  return;
}


/* ==================================================================== */
/* Address: 0x00751990 | Classified: elementclient::AUITreeView__GetItemDataPtr____d@0x751990 */
/* ==================================================================== */

undefined4 FUN_00751990(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_8 = &UNK_008cb238;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    cVar2 = func_0x00763c50(param_1 + 0x28);
    if (cVar2 == '\0') {
      func_0x00739700(0x3b3,1,0x983218);
    }
  }
  uVar1 = *(undefined4 *)(param_1 + 8);
  uStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return uVar1;
}


/* ==================================================================== */
/* Address: 0x00751a10 | Classified: AngelicaUI::proc_751a10 */
/* ==================================================================== */

void FUN_00751a10(int param_1)

{
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  puStack_8 = &UNK_008cb258;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  func_0x00763940(&stack0x0000000c);
  puStack_8 = (undefined *)0xffffffff;
  *(int *)(param_1 + 8) = param_1;
  func_0x007637f0();
  *unaff_FS_OFFSET = unaff_ESI;
  return;
}


/* ==================================================================== */
/* Address: 0x00751a70 | Classified: AngelicaUI::proc_751a70 */
/* ==================================================================== */

void FUN_00751a70(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00751a80 | Classified: elementclient::AUITreeView__DeleteAllItems____f@0x751a80 */
/* ==================================================================== */

undefined4 __fastcall FUN_00751a80(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  
  iVar2 = *(int *)(param_1 + 0x104);
  while (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x3c);
    cVar3 = FUN_00751b00(iVar2);
    iVar2 = iVar1;
    if (cVar3 == '\0') {
      uVar4 = func_0x00739700(0x3d3,1,0x98324c);
      return uVar4;
    }
  }
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  cVar3 = FUN_00751ee0();
  if (cVar3 == '\0') {
    uVar4 = func_0x00739700(0x3da,1,0x983288);
    return uVar4;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00751b00 | Classified: elementclient::AUITreeView__DeleteItem____faile@0x751b00 */
/* ==================================================================== */

undefined4 __thiscall FUN_00751b00(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  
  if (param_2 == param_1 + 0xd4) {
    return 0;
  }
  iVar2 = *(int *)(param_2 + 0x30);
  while (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x3c);
    cVar3 = FUN_00751b00(iVar2);
    iVar2 = iVar1;
    if (cVar3 == '\0') {
      uVar4 = func_0x00739700(0x3ed,1,0x9832cc);
      return uVar4;
    }
  }
  if (*(int *)(param_2 + 0x38) == 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x2c) + 0x30) = *(undefined4 *)(param_2 + 0x3c);
  }
  if (*(int *)(param_2 + 0x3c) == 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x2c) + 0x34) = *(undefined4 *)(param_2 + 0x38);
  }
  if (*(int *)(param_2 + 0x38) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x38) + 0x3c) = *(undefined4 *)(param_2 + 0x3c);
  }
  if (*(int *)(param_2 + 0x3c) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x3c) + 0x38) = *(undefined4 *)(param_2 + 0x38);
  }
  *(int *)(param_1 + 0xd0) = *(int *)(param_1 + 0xd0) + -1;
  if (*(int *)(param_1 + 0x11c) == param_2) {
    *(undefined4 *)(param_1 + 0x11c) = 0;
  }
  if (param_2 != 0) {
    FUN_00751c00();
    func_0x00763260(param_2);
  }
  cVar3 = FUN_00751ee0();
  if (cVar3 == '\0') {
    uVar4 = func_0x00739700(0x402,1,0x983304);
    return uVar4;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00751c00 | Classified: AngelicaUI::proc_751c00 */
/* ==================================================================== */

void FUN_00751c00(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  puStack_8 = &UNK_008cb28e;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iStack_4 = 2;
  func_0x007637f0();
  iStack_4._0_1_ = 1;
  func_0x007637f0();
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  FUN_00765200();
  iStack_4 = 0xffffffff;
  FUN_00765200();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x00751c70 | Classified: AngelicaUI::proc_751c70 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall FUN_00751c70(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cb2d4;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  puVar2 = (undefined4 *)func_0x00763250(0x48);
  if (puVar2 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = _DAT_00985a98;
    puVar2[8] = _DAT_00985a98;
    puVar2[9] = _DAT_009858e4;
    puVar2[10] = _DAT_009858e4;
    uStack_4 = 4;
    FUN_00765230(0x9b3c40);
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0xffffffff;
    puVar2[0xb] = 0;
    puVar2[0xc] = 0;
    puVar2[0xd] = 0;
    puVar2[0xe] = 0;
    puVar2[0xf] = 0;
    puVar2[0x10] = 0;
    puVar2[0x11] = 0;
    puVar3 = puVar2;
  }
  uStack_4 = 0xffffffff;
  if (puVar3 == (undefined4 *)0x0) {
    *unaff_FS_OFFSET = uStack_c;
    return (undefined4 *)0x0;
  }
  FUN_00765230(param_2);
  puVar3[3] = *(undefined4 *)(param_1 + 0x38);
  if (((param_2 == -0x10000) || (param_2 == 0)) || (param_2 == param_1 + 0xd4)) {
    puVar3[0x10] = 0;
    puVar3[0xb] = param_1 + 0xd4;
  }
  else {
    puVar3[0xb] = param_2;
    puVar3[0x10] = *(int *)(param_2 + 0x40) + 1;
  }
  if (param_3 == -0xffff) {
    iVar1 = *(int *)(puVar3[0xb] + 0x30);
    puVar3[0xf] = iVar1;
    if (iVar1 != 0) {
      *(undefined4 **)(iVar1 + 0x38) = puVar3;
    }
    *(undefined4 **)(puVar3[0xb] + 0x30) = puVar3;
    if (*(int *)(puVar3[0xb] + 0x34) == 0) {
      *(undefined4 **)(puVar3[0xb] + 0x34) = puVar3;
    }
  }
  else if (((param_3 == -0xfffe) || (param_3 == 0)) || (*(int *)(param_3 + 0x3c) == 0)) {
    iVar1 = *(int *)(puVar3[0xb] + 0x34);
    puVar3[0xe] = iVar1;
    if (iVar1 != 0) {
      *(undefined4 **)(iVar1 + 0x3c) = puVar3;
    }
    *(undefined4 **)(puVar3[0xb] + 0x34) = puVar3;
    if (*(int *)(puVar3[0xb] + 0x30) == 0) {
      *(undefined4 **)(puVar3[0xb] + 0x30) = puVar3;
    }
  }
  else {
    puVar3[0xe] = param_3;
    puVar3[0xf] = *(undefined4 *)(param_3 + 0x3c);
    *(undefined4 **)(*(int *)(param_3 + 0x3c) + 0x38) = puVar3;
    *(undefined4 **)(param_3 + 0x3c) = puVar3;
  }
  *(int *)(param_1 + 0xd0) = *(int *)(param_1 + 0xd0) + 1;
  FUN_00751ee0();
  *unaff_FS_OFFSET = puVar2;
  return puVar3;
}


/* ==================================================================== */
/* Address: 0x00751e00 | Classified: AngelicaUI::proc_751e00 */
/* ==================================================================== */

undefined4 * __thiscall FUN_00751e00(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int unaff_EBX;
  int iVar4;
  int iVar5;
  int unaff_retaddr;
  int iStack_10;
  undefined1 auStack_c [8];
  int iStack_4;
  
  if (*(int *)(param_1 + 0x120) != 0) {
    iVar2 = *(int *)(param_1 + 0xbc);
    iVar5 = *(int *)(param_1 + 0xb8) + 8;
    FUN_007537a0(&iStack_10);
    iVar4 = unaff_retaddr - unaff_EBX / 2;
    iVar2 = (param_2 - iStack_10 / 2) / (iVar2 + 3) + *(int *)(param_1 + 0xb0);
    if (((-1 < iVar2) && (iVar2 < *(int *)(param_1 + 0xcc))) &&
       (puVar1 = *(undefined4 **)(*(int *)(param_1 + 0xc0) + iVar2 * 4),
       puVar1[0x10] * iVar5 <= iVar4)) {
      if (*(int *)(param_1 + 0x34) == 0) {
        func_0x00868610();
        FUN_007537e0();
      }
      piVar3 = (int *)func_0x0073c830(auStack_c,*puVar1,0xffffffff);
      iVar5 = (puVar1[0x10] + 1) * iVar5;
      if (iVar4 <= iVar5 + *piVar3) {
        if (iStack_4 != 0) {
          *(bool *)iStack_4 = iVar4 < iVar5;
        }
        return puVar1;
      }
    }
  }
  return (undefined4 *)0x0;
}


/* ==================================================================== */
/* Address: 0x00751ee0 | Classified: elementclient::AUITreeView__RebuildVisibleItems@0x751ee0 */
/* ==================================================================== */

undefined4 __fastcall FUN_00751ee0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  
  puVar2 = *(undefined4 **)(param_1 + 0xc0);
  puVar1 = puVar2 + *(int *)(param_1 + 0xcc);
  if (puVar2 != puVar1) {
    puVar4 = puVar1;
    puVar8 = puVar2;
    if (puVar1 < *(undefined4 **)(param_1 + 0xc4)) {
      do {
        puVar5 = puVar4 + 1;
        *puVar8 = *puVar4;
        puVar4 = puVar5;
        puVar8 = puVar8 + 1;
      } while (puVar5 < *(undefined4 **)(param_1 + 0xc4));
    }
    iVar7 = (int)puVar1 - (int)puVar2 >> 2;
    *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + iVar7 * -4;
    *(int *)(param_1 + 0xcc) = *(int *)(param_1 + 0xcc) - iVar7;
  }
  iVar7 = *(int *)(param_1 + 0x104);
  while( true ) {
    if (iVar7 == 0) {
      return 1;
    }
    cVar3 = FUN_00751f80(iVar7);
    if (cVar3 == '\0') break;
    iVar7 = *(int *)(iVar7 + 0x3c);
  }
  uVar6 = func_0x00739700(0x472,1,0x983344);
  return uVar6;
}


/* ==================================================================== */
/* Address: 0x00751f80 | Classified: elementclient::AUITreeView__RebuildVisibleItems@0x751f80 */
/* ==================================================================== */

undefined4 __thiscall FUN_00751f80(int param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  
  uVar6 = *(uint *)(param_1 + 0xcc);
  if (uVar6 == *(uint *)(param_1 + 200)) {
    if (uVar6 + 1 < 5) {
      iVar7 = 5;
    }
    else {
      iVar7 = uVar6 + 3 + (uVar6 >> 1);
    }
    puVar2 = (undefined4 *)func_0x00763250(iVar7 * 4);
    puVar5 = *(undefined4 **)(param_1 + 0xc0);
    uVar6 = 0;
    puVar4 = puVar2;
    if (*(int *)(param_1 + 0xcc) != 0) {
      do {
        if (puVar4 != (undefined4 *)0x0) {
          uVar3 = *puVar5;
          puVar5 = puVar5 + 1;
          *puVar4 = uVar3;
        }
        uVar6 = uVar6 + 1;
        puVar4 = puVar4 + 1;
      } while (uVar6 < *(uint *)(param_1 + 0xcc));
    }
    if (*(int *)(param_1 + 0xc0) != 0) {
      func_0x00763260(*(int *)(param_1 + 0xc0));
    }
    *(int *)(param_1 + 200) = iVar7;
    *(undefined4 **)(param_1 + 0xc0) = puVar2;
    *(undefined4 **)(param_1 + 0xc4) = puVar2 + *(int *)(param_1 + 0xcc);
  }
  if (*(int **)(param_1 + 0xc4) != (int *)0x0) {
    **(int **)(param_1 + 0xc4) = param_2;
  }
  *(int *)(param_1 + 0xcc) = *(int *)(param_1 + 0xcc) + 1;
  *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + 4;
  if ((*(byte *)(param_2 + 0x44) & 1) != 0) {
    for (iVar7 = *(int *)(param_2 + 0x30); iVar7 != 0; iVar7 = *(int *)(iVar7 + 0x3c)) {
      cVar1 = FUN_00751f80(iVar7);
      if (cVar1 == '\0') {
        uVar3 = func_0x00739700(0x485,1,0x983344);
        return uVar3;
      }
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007520a0 | Classified: AngelicaUI::proc_7520a0 */
/* ==================================================================== */

void FUN_007520a0(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    uVar2 = *(uint *)(param_1 + 0x44);
LAB_007520af:
    uVar2 = uVar2 | 1;
  }
  else if (param_2 == 1) {
    uVar2 = *(uint *)(param_1 + 0x44) & 0xfffffffe;
  }
  else {
    if (param_2 != 2) goto LAB_007520b4;
    uVar2 = *(uint *)(param_1 + 0x44);
    if ((uVar2 & 1) == 0) goto LAB_007520af;
    uVar2 = uVar2 & 0xfffffffe;
  }
  *(uint *)(param_1 + 0x44) = uVar2;
LAB_007520b4:
  if ((*(byte *)(param_1 + 0x44) & 1) != 0) {
    for (iVar1 = *(int *)(param_1 + 0x2c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x2c)) {
      *(uint *)(iVar1 + 0x44) = *(uint *)(iVar1 + 0x44) | 1;
    }
  }
  FUN_00751ee0();
  return;
}


/* ==================================================================== */
/* Address: 0x00752100 | Classified: AngelicaUI::proc_752100 */
/* ==================================================================== */

undefined4 __fastcall FUN_00752100(int param_1)

{
  return *(undefined4 *)(param_1 + 0x11c);
}


/* ==================================================================== */
/* Address: 0x00752110 | Classified: AngelicaUI::proc_752110 */
/* ==================================================================== */

void __thiscall FUN_00752110(int param_1,int param_2)

{
  uint *puVar1;
  
  if (*(int *)(param_1 + 0x11c) != 0) {
    puVar1 = (uint *)(*(int *)(param_1 + 0x11c) + 0x44);
    *puVar1 = *puVar1 & 0xfffffffd;
  }
  *(int *)(param_1 + 0x11c) = param_2;
  if (param_2 != 0) {
    *(uint *)(param_2 + 0x44) = *(uint *)(param_2 + 0x44) | 2;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00752140 | Classified: AUITreeView::vfunc_slot_11 */
/* ==================================================================== */

void __thiscall FUN_00752140(int param_1,undefined4 param_2)

{
  FUN_00752170(param_1 + 0xd4,param_2);
  FUN_007425f0(param_2);
  return;
}


/* ==================================================================== */
/* Address: 0x00752170 | Classified: AngelicaUI::proc_752170 */
/* ==================================================================== */

void FUN_00752170(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x30);
  *(undefined4 *)(param_1 + 0xc) = param_2;
  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x3c)) {
    FUN_00752170(iVar1,param_2);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007521a0 | Classified: AngelicaUI::proc_7521a0 */
/* ==================================================================== */

undefined4 FUN_007521a0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x20);
}


/* ==================================================================== */
/* Address: 0x007521b0 | Classified: AngelicaUI::proc_7521b0 */
/* ==================================================================== */

void FUN_007521b0(undefined4 param_1,undefined4 param_2)

{
  FUN_00765230(param_2);
  return;
}


/* ==================================================================== */
/* Address: 0x007521d0 | Classified: AngelicaUI::proc_7521d0 */
/* ==================================================================== */

undefined4 * __fastcall FUN_007521d0(undefined4 *param_1)

{
  FUN_00741960();
  *param_1 = &UNK_008ef394;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x2a] = 0;
  *(undefined1 *)(param_1 + 0x2f) = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0xf] = 0xc;
  param_1[0x29] = 100;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00752220 | Classified: AUISlider::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_00752220(undefined4 param_1,byte param_2)

{
  FUN_00752240();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00752240 | Classified: AngelicaUI::proc_752240 */
/* ==================================================================== */

void __fastcall FUN_00752240(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  *param_1 = &UNK_008ef394;
  puStack_8 = &UNK_008ca630;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008eece0;
  iStack_4 = 6;
  func_0x007637f0();
  iStack_4._0_1_ = 5;
  func_0x007637f0();
  iStack_4._0_1_ = 4;
  FUN_00765200();
  iStack_4._0_1_ = 3;
  FUN_00765200();
  iStack_4._0_1_ = 2;
  FUN_00765200();
  iStack_4._0_1_ = 1;
  func_0x007637f0();
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  func_0x007637f0();
  iStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x007524f0 | Classified: AUISlider::vfunc_slot_3 */
/* ==================================================================== */

void __fastcall FUN_007524f0(int param_1)

{
  if (*(int *)(param_1 + 0xc0) != 0) {
    FUN_00753080();
    if (*(undefined4 **)(param_1 + 0xc0) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0xc0))(1);
    }
    *(undefined4 *)(param_1 + 0xc0) = 0;
  }
  if (*(int *)(param_1 + 0xc4) != 0) {
    func_0x0078c040();
    if (*(undefined4 **)(param_1 + 0xc4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0xc4))(1);
    }
    *(undefined4 *)(param_1 + 0xc4) = 0;
  }
  FUN_00430850();
  return;
}


/* ==================================================================== */
/* Address: 0x00752550 | Classified: AUISlider::vfunc_slot_4 */
/* ==================================================================== */

undefined1 __thiscall FUN_00752550(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  fprintf(param_2,0x9802cc);
  cVar1 = FUN_00741f60(param_2);
  if (cVar1 == '\0') {
    return 0;
  }
  if (*(int *)(param_1 + 0xc4) == 0) {
    puVar4 = &DAT_009b3c44;
  }
  else {
    puVar4 = *(undefined **)(*(int *)(param_1 + 0xc4) + 8);
  }
  if (*(int *)(param_1 + 0xc0) == 0) {
    puVar3 = &DAT_009b3c44;
  }
  else {
    iVar2 = FUN_007537e0();
    puVar3 = *(undefined **)(iVar2 + 8);
  }
  fprintf(param_2,0x983478,puVar3,puVar4,*(undefined4 *)(param_1 + 0xa4));
  return 1;
}


/* ==================================================================== */
/* Address: 0x00752c70 | Classified: AngelicaUI::proc_752c70 */
/* ==================================================================== */

void __thiscall FUN_00752c70(int param_1,int param_2)

{
  if (param_2 < *(int *)(param_1 + 0xa0)) {
    param_2 = *(int *)(param_1 + 0xa0);
  }
  if (*(int *)(param_1 + 0xa4) < param_2) {
    *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0xa4);
    return;
  }
  *(int *)(param_1 + 0x9c) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x00752ca0 | Classified: AngelicaUI::proc_752ca0 */
/* ==================================================================== */

void __thiscall FUN_00752ca0(int param_1,int param_2,int param_3)

{
  if (param_3 < param_2) {
    *(int *)(param_1 + 0xa4) = param_2;
    *(int *)(param_1 + 0xa0) = param_3;
    if (*(int *)(param_1 + 0x9c) < param_3) {
      *(int *)(param_1 + 0x9c) = param_3;
    }
    if (*(int *)(param_1 + 0xa4) < *(int *)(param_1 + 0x9c)) {
      *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0xa4);
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00752d70 | Classified: AngelicaUI::proc_752d70 */
/* ==================================================================== */

void __fastcall FUN_00752d70(undefined4 *param_1)

{
  *param_1 = &UNK_008ef444;
  param_1[1] = 3;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[4] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00752d90 | Classified: AUIFrame::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_00752d90(undefined4 param_1,byte param_2)

{
  FUN_00752db0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00752db0 | Classified: AngelicaUI::proc_752db0 */
/* ==================================================================== */

void __fastcall FUN_00752db0(undefined4 *param_1)

{
  *param_1 = &UNK_008ef444;
  return;
}


/* ==================================================================== */
/* Address: 0x00752dc0 | Classified: elementclient::AUIFrame__Init____Failed_to_call@0x752dc0 */
/* ==================================================================== */

undefined4 __thiscall
FUN_00752dc0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0xc) = param_3;
  cVar1 = FUN_00752e00(param_4);
  if (cVar1 == '\0') {
    uVar2 = func_0x00739700(0x2b,1,0x983560);
    return uVar2;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00752e00 | Classified: elementclient::AUIFrame__InitIndirect____failed@0x752e00 */
/* ==================================================================== */

undefined4 __thiscall FUN_00752e00(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  undefined4 *unaff_FS_OFFSET;
  int aiStack_a4 [6];
  int iStack_8c;
  int iStack_88;
  undefined4 uStack_84;
  int iStack_80;
  int iStack_7c;
  undefined4 uStack_78;
  int iStack_74;
  int iStack_70;
  int iStack_6c;
  int iStack_68;
  int iStack_64;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cb30e;
  *unaff_FS_OFFSET = &uStack_c;
  if (*(int *)(param_1 + 0x10) != 0) {
    func_0x0078c040();
    if (*(undefined4 **)(param_1 + 0x10) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x10))(1);
    }
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  iVar6 = -1;
  pcVar11 = param_2;
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    cVar3 = *pcVar11;
    pcVar11 = pcVar11 + 1;
  } while (cVar3 != '\0');
  if (iVar6 != -2) {
    iVar6 = func_0x00763250(0x8c);
    uStack_4 = 0;
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = func_0x0078bd00();
    }
    uStack_4 = 0xffffffff;
    *(int *)(param_1 + 0x10) = iVar6;
    if (iVar6 == 0) {
      uVar4 = 0;
      goto LAB_0075305f;
    }
    cVar3 = func_0x0078c020(*(undefined4 *)(param_1 + 0xc),param_2,0xffff00ff);
    if (cVar3 == '\0') {
      uVar4 = func_0x00739700(0x3e,1,0x9835d4);
      goto LAB_0075305f;
    }
    iVar6 = *(int *)(*(int *)(param_1 + 0x10) + 0x34);
    iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0x38);
    if (((iVar6 / 3) * 3 == iVar6) && ((iVar2 / 3) * 3 == iVar2)) {
      iVar9 = 3;
      piVar5 = aiStack_a4 + 1;
      *(undefined4 *)(param_1 + 4) = 3;
      iVar10 = 0;
      do {
        iVar1 = iVar10 + iVar2 / 3;
        iVar7 = 0;
        iVar8 = 3;
        do {
          piVar5[-2] = iVar7;
          iVar7 = iVar7 + iVar6 / 3;
          piVar5[-1] = iVar10;
          *piVar5 = iVar7;
          piVar5[1] = iVar1;
          piVar5 = piVar5 + 4;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        iVar9 = iVar9 + -1;
        iVar10 = iVar1;
      } while (iVar9 != 0);
    }
    else {
      iVar10 = (int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2;
      if ((iVar10 * 4 - iVar6 == 0) &&
         (iVar6 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2, iVar6 * 4 - iVar2 == 0)) {
        *(undefined4 *)(param_1 + 4) = 4;
        iStack_6c = iVar6 * 3;
        aiStack_a4[5] = iVar10 * 3;
        iStack_80 = iVar10 * 4;
        iStack_3c = iVar6 << 2;
        aiStack_a4[4] = 0;
        uStack_84 = 0;
        uStack_78 = 0;
        uStack_48 = 0;
        aiStack_a4[1] = iVar10;
        aiStack_a4[2] = iVar6;
        aiStack_a4[3] = iVar10;
        iStack_8c = iVar6;
        iStack_88 = aiStack_a4[5];
        iStack_7c = iVar6;
        iStack_74 = iVar6;
        iStack_70 = iVar10;
        iStack_68 = iVar10;
        iStack_64 = iVar6;
        iStack_60 = aiStack_a4[5];
        iStack_5c = iStack_6c;
        iStack_58 = aiStack_a4[5];
        iStack_54 = iVar6;
        iStack_50 = iStack_80;
        iStack_4c = iStack_6c;
        iStack_44 = iStack_6c;
        iStack_40 = iVar10;
        iStack_38 = iVar10;
        iStack_34 = iStack_6c;
        iStack_30 = aiStack_a4[5];
        iStack_2c = iStack_3c;
        iStack_28 = aiStack_a4[5];
        iStack_24 = iStack_6c;
        iStack_20 = iStack_80;
        iStack_1c = iStack_3c;
      }
    }
    cVar3 = func_0x0078c600(9,&stack0xffffff58);
    if (cVar3 == '\0') {
      uVar4 = func_0x00739700(0x68,1,0x983590);
      goto LAB_0075305f;
    }
  }
  uVar4 = 1;
LAB_0075305f:
  *unaff_FS_OFFSET = uStack_c;
  return uVar4;
}


/* ==================================================================== */
/* Address: 0x00753080 | Classified: AngelicaUI::proc_753080 */
/* ==================================================================== */

undefined4 __fastcall FUN_00753080(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    func_0x0078c040();
    if (*(undefined4 **)(param_1 + 0x10) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x10))(1);
    }
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007530b0 | Classified: elementclient::__s_@0x7530b0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007530b0(int param_1,undefined4 param_2)

{
  fprintf(param_2,0x9805b4,*(undefined4 *)(*(int *)(param_1 + 0x10) + 8));
  return 1;
}


/* ==================================================================== */
/* Address: 0x007530d0 | Classified: elementclient::AUIFrame__Render____failed_to_ca@0x7530d0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007530d0(int param_1,int param_2,int param_3)

{
  float fVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int unaff_EDI;
  int unaff_retaddr;
  char in_stack_00000020;
  byte in_stack_0000002c;
  float fVar8;
  float fStack_84;
  int iStack_80;
  float fStack_7c;
  float fStack_78;
  undefined4 uStack_74;
  float fStack_70;
  float fStack_6c;
  int iStack_68;
  float fStack_64;
  float fStack_60;
  undefined4 uStack_5c;
  float fStack_58;
  float fStack_54;
  int iStack_50;
  float fStack_4c;
  float fStack_48;
  int iStack_44;
  float fStack_40;
  float fStack_3c;
  int iStack_38;
  int iStack_20;
  char cStack_1c;
  char cStack_10;
  
  iVar7 = *(int *)(param_1 + 0x10);
  iStack_38 = 0;
  iVar3 = *(int *)(iVar7 + 0x34) / *(int *)(param_1 + 4);
  iVar4 = *(int *)(iVar7 + 0x38) / *(int *)(param_1 + 4);
  *(uint *)(iVar7 + 0x6c) = *(uint *)(iVar7 + 0x6c) & 0xffffff | (uint)in_stack_0000002c << 0x18;
  fStack_3c = 1.0762381e-38;
  cVar2 = func_0x0078c4e0();
  if (cVar2 == '\0') {
    fStack_3c = 1.3981074e-38;
    fStack_40 = 1.4013e-45;
    iStack_44 = 0x8e;
    fStack_48 = 1.0762411e-38;
    uVar5 = func_0x00739700();
    return uVar5;
  }
  fVar1 = (float)param_2;
  fStack_40 = (float)unaff_retaddr;
  fStack_3c = fVar1;
  if (in_stack_0000002c == 0) {
    iStack_44 = 0x753172;
    cVar2 = func_0x0078c490();
  }
  else {
    iStack_44 = 0x75316b;
    cVar2 = func_0x0078c3a0();
  }
  if (cVar2 == '\0') {
    iStack_44 = 0x983d10;
    fStack_48 = 1.4013e-45;
    fStack_4c = 2.10195e-43;
    iStack_50 = 0x753187;
    uVar5 = func_0x00739700();
    return uVar5;
  }
  iStack_44 = 1;
  fStack_48 = 1.0762552e-38;
  cVar2 = func_0x0078c4e0();
  if (cVar2 == '\0') {
    fStack_48 = 1.3980777e-38;
    fStack_4c = 1.4013e-45;
    iStack_50 = 0x9a;
    fStack_54 = 1.0762582e-38;
    uVar5 = func_0x00739700();
    return uVar5;
  }
  if (*(int *)(param_1 + 4) == 3) {
    fVar8 = (float)(param_3 + iVar3 * -2) / (float)iVar4;
  }
  else {
    fVar8 = (float)(param_3 + iVar3 * -2) / (float)(iVar3 * 2);
  }
  fStack_48 = 1.0762716e-38;
  func_0x00892e78();
  *(float *)(*(int *)(param_1 + 0x10) + 0x70) = fVar8;
  fStack_4c = (float)(iVar3 + param_2);
  fStack_48 = fVar1;
  if (in_stack_00000020 == '\0') {
    iStack_50 = 0x75324b;
    cVar2 = func_0x0078c490();
  }
  else {
    iStack_50 = 0x753244;
    cVar2 = func_0x0078c3a0();
  }
  if (cVar2 == '\0') {
    iStack_50 = 0x983c3c;
    fStack_54 = 1.4013e-45;
    fStack_58 = 2.42425e-43;
    uStack_5c = 0x753260;
    uVar5 = func_0x00739700();
    return uVar5;
  }
  iStack_50 = 2;
  *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x70) = 0x3f800000;
  fStack_54 = 1.076287e-38;
  cVar2 = func_0x0078c4e0();
  if (cVar2 == '\0') {
    fStack_54 = 1.3980475e-38;
    fStack_58 = 1.4013e-45;
    uStack_5c = 0xb3;
    fStack_60 = 1.07629e-38;
    uVar5 = func_0x00739700();
    return uVar5;
  }
  iVar7 = iVar3 + param_2 + unaff_EDI;
  fStack_58 = (float)iVar7;
  fStack_54 = fVar1;
  if (in_stack_00000020 == '\0') {
    uStack_5c = 0x7532cd;
    cVar2 = func_0x0078c490();
  }
  else {
    uStack_5c = 0x7532c6;
    cVar2 = func_0x0078c3a0();
  }
  if (cVar2 == '\0') {
    uStack_5c = 0x983b60;
    fStack_60 = 1.4013e-45;
    fStack_64 = 2.60642e-43;
    iStack_68 = 0x7532e2;
    uVar5 = func_0x00739700();
    return uVar5;
  }
  uStack_5c = 3;
  fStack_60 = 1.0763039e-38;
  cVar2 = func_0x0078c4e0();
  if (cVar2 == '\0') {
    fStack_60 = 1.3980166e-38;
    fStack_64 = 1.4013e-45;
    iStack_68 = 0xbe;
    fStack_6c = 1.0763068e-38;
    uVar5 = func_0x00739700();
    return uVar5;
  }
  if (*(int *)(param_1 + 4) == 3) {
    fStack_4c = (float)(iVar7 + iStack_44 * -2) / (float)iStack_44;
  }
  else {
    fStack_4c = (float)(iVar7 + iStack_44 * -2) / (float)(iStack_44 * 2);
  }
  fStack_60 = 1.0763212e-38;
  iVar7 = func_0x00892e78();
  *(float *)(*(int *)(param_1 + 0x10) + 0x74) = fStack_4c;
  fVar1 = (float)(iStack_20 + iStack_44);
  fVar8 = (float)iStack_38;
  fStack_64 = fVar8;
  fStack_60 = fVar1;
  if ((char)param_3 == '\0') {
    iStack_68 = 0x7533c0;
    cVar2 = func_0x0078c490();
  }
  else {
    iStack_68 = 0x7533b9;
    cVar2 = func_0x0078c3a0();
  }
  if (cVar2 == '\0') {
    iStack_68 = 0x983a84;
    fStack_6c = 1.4013e-45;
    fStack_70 = 2.94273e-43;
    uStack_74 = 0x7533d5;
    uVar5 = func_0x00739700();
    return uVar5;
  }
  iStack_68 = 4;
  *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x74) = 0x3f800000;
  fStack_6c = 1.0763393e-38;
  cVar2 = func_0x0078c4e0();
  if (cVar2 == '\0') {
    fStack_6c = 1.3979864e-38;
    fStack_70 = 1.4013e-45;
    uStack_74 = 0xd8;
    fStack_78 = 1.0763423e-38;
    uVar5 = func_0x00739700();
    return uVar5;
  }
  *(float *)(*(int *)(param_1 + 0x10) + 0x70) = fStack_54;
  *(float *)(*(int *)(param_1 + 0x10) + 0x74) = fStack_58;
  fStack_70 = (float)(int)fStack_3c;
  fStack_6c = fVar1;
  if ((char)param_3 == '\0') {
    uStack_74 = 0x753454;
    cVar2 = func_0x0078c490();
  }
  else {
    uStack_74 = 0x75344d;
    cVar2 = func_0x0078c3a0();
  }
  if (cVar2 == '\0') {
    uStack_74 = 0x9839b0;
    fStack_78 = 1.4013e-45;
    fStack_7c = 3.18095e-43;
    iStack_80 = 0x753469;
    uVar5 = func_0x00739700();
    return uVar5;
  }
  uStack_74 = 5;
  *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x70) = 0x3f800000;
  *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x74) = 0x3f800000;
  fStack_78 = 1.076361e-38;
  cVar2 = func_0x0078c4e0();
  if (cVar2 == '\0') {
    fStack_78 = 1.3979561e-38;
    fStack_7c = 1.4013e-45;
    iStack_80 = 0xeb;
    fStack_84 = 1.076364e-38;
    uVar5 = func_0x00739700();
    return uVar5;
  }
  *(float *)(*(int *)(param_1 + 0x10) + 0x74) = fStack_64;
  cStack_10 = (char)param_2;
  fStack_3c = (float)((int)fStack_3c + (int)fStack_58);
  fStack_7c = (float)(int)fStack_3c;
  fStack_78 = fVar1;
  if (cStack_10 == '\0') {
    iStack_80 = 0x7534eb;
    cVar2 = func_0x0078c490();
  }
  else {
    iStack_80 = 0x7534e4;
    cVar2 = func_0x0078c3a0();
  }
  if (cVar2 == '\0') {
    iStack_80 = 0x9838d4;
    fStack_84 = 1.4013e-45;
    uVar5 = func_0x00739700(0xf4);
    return uVar5;
  }
  iStack_80 = 6;
  *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x74) = 0x3f800000;
  fStack_84 = 1.0763812e-38;
  cVar2 = func_0x0078c4e0();
  if (cVar2 == '\0') {
    fStack_84 = 1.3981074e-38;
    uVar5 = func_0x00739700(0xfa,1);
    return uVar5;
  }
  iStack_44 = iStack_44 + iVar7;
  cStack_1c = (char)iVar4;
  fVar1 = (float)iStack_44;
  fStack_84 = fVar1;
  if (cStack_1c == '\0') {
    cVar2 = func_0x0078c490(fVar8);
  }
  else {
    cVar2 = func_0x0078c3a0();
  }
  if (cVar2 == '\0') {
    uVar5 = func_0x00739700(0x102,1,0x983854);
    return uVar5;
  }
  cVar2 = func_0x0078c4e0(7);
  if (cVar2 == '\0') {
    uVar5 = func_0x00739700(0x106,1,0x9837f8);
    return uVar5;
  }
  *(float *)(*(int *)(param_1 + 0x10) + 0x70) = fStack_78;
  fStack_54 = fStack_60;
  if (cStack_1c == '\0') {
    cVar2 = func_0x0078c490((float)(int)fStack_60,fVar1);
  }
  else {
    cVar2 = func_0x0078c3a0();
  }
  if (cVar2 != '\0') {
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x70) = 0x3f800000;
    cVar2 = func_0x0078c4e0(8);
    if (cVar2 == '\0') {
      uVar5 = func_0x00739700(0x115,1,0x983718);
      return uVar5;
    }
    fStack_60 = (float)((int)fStack_60 + (int)fStack_7c);
    if (cStack_1c == '\0') {
      cVar2 = func_0x0078c490((float)(int)fStack_60,fVar1);
    }
    else {
      cVar2 = func_0x0078c3a0();
    }
    if (cVar2 != '\0') {
      if ((cStack_1c != '\0') && (cVar2 = func_0x0078cd10(), cVar2 == '\0')) {
        uVar5 = func_0x00739700(0x121,1,0x983614);
        return uVar5;
      }
      iVar7 = iStack_50;
      if (iStack_50 != 0) {
        iVar3 = wcslen(iStack_50);
        if (iVar3 != 0) {
          piVar6 = (int *)func_0x0073c830(&fStack_84,iVar7,0xffffffff);
          if (fStack_58 == 2.8026e-45) {
            iVar3 = (((int)fVar8 - *piVar6) - (int)fStack_84) + (int)fStack_6c;
          }
          else {
            iVar3 = iStack_80;
            if (fStack_58 == 1.4013e-45) {
              iVar3 = ((int)fStack_6c / 2 - *piVar6 / 2) + (int)fVar8;
            }
          }
          func_0x0073bab0(iVar3 + (int)fStack_54,
                          (iStack_68 / 2 - piVar6[1] / 2) + (int)fStack_7c + iStack_50,iVar7,
                          fStack_60,iStack_44 != 0,iStack_44 << 0x18,0,0xffffffff);
        }
      }
      return 1;
    }
    uVar5 = func_0x00739700(0x11c,1,0x983694);
    return uVar5;
  }
  uVar5 = func_0x00739700(0x10f,1,0x983778);
  return uVar5;
}


/* ==================================================================== */
/* Address: 0x007537a0 | Classified: AngelicaUI::proc_7537a0 */
/* ==================================================================== */

int * __thiscall FUN_007537a0(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x10);
  iVar3 = 0;
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar3 = *(int *)(iVar1 + 0x34) / *(int *)(param_1 + 4) << 1;
    iVar2 = *(int *)(iVar1 + 0x38) / *(int *)(param_1 + 4) << 1;
  }
  *param_2 = iVar3;
  param_2[1] = iVar2;
  return param_2;
}


/* ==================================================================== */
/* Address: 0x007537e0 | Classified: CECTaskInterface::vfunc_slot_4 */
/* ==================================================================== */

undefined4 __fastcall FUN_007537e0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}


/* ==================================================================== */
/* Address: 0x007537f0 | Classified: AngelicaUI::proc_7537f0 */
/* ==================================================================== */

undefined4 * __fastcall FUN_007537f0(undefined4 *param_1)

{
  FUN_00741960();
  *param_1 = &UNK_008ef4bc;
  param_1[0xf] = 0xb;
  param_1[0x27] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  *(undefined1 *)(param_1 + 0x38) = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x33] = 0;
  param_1[0x29] = 0;
  param_1[0x28] = 0;
  param_1[0x2e] = 0;
  param_1[0x2c] = 0;
  param_1[0x32] = 100;
  param_1[0x2f] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x2d) = 1;
  return param_1;
}


