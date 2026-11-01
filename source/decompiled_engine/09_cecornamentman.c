/* Authentic Ghidra 12.1.4 Decompilation — elementclient.exe (PW 1.4.2 Build 2305) */
/* Module: 09_cecornamentman.c */

/* ==================================================================== */
/* Address: 0x005b11f0 | Classified: CECOrnamentMan::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_005b11f0(undefined4 param_1,byte param_2)

{
  FUN_005b1210();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x005b1210 | Classified: ElementClient::proc_5b1210 */
/* ==================================================================== */

void __fastcall FUN_005b1210(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 unaff_EBP;
  uint uVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008b7ece;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008e37c8;
  uStack_4 = 6;
  func_0x006485b0();
  if ((undefined4 *)param_1[0x24] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x24])(1);
  }
  if ((undefined4 *)param_1[0x25] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x25])(1);
  }
  DeleteCriticalSection(param_1 + 0x2c);
  puStack_8._0_1_ = 5;
  param_1[0x27] = &UNK_008e3800;
  if (param_1[0x28] != 0) {
    func_0x00763260(param_1[0x28]);
    param_1[0x28] = 0;
  }
  param_1[0x2a] = 0;
  param_1[0x29] = 0;
  uVar3 = 0;
  puStack_8._0_1_ = 4;
  if (param_1[0x21] != 0) {
    do {
      puVar2 = *(undefined4 **)(param_1[0x1e] + uVar3 * 4);
      while (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar2;
        func_0x00763260(puVar2);
        puVar2 = puVar1;
      }
      uVar3 = uVar3 + 1;
      *(undefined4 *)(param_1[0x1e] + -4 + uVar3 * 4) = 0;
    } while (uVar3 < (uint)param_1[0x21]);
  }
  param_1[0x1d] = 0;
  func_0x004060e0();
  uVar3 = 0;
  puStack_8._0_1_ = 3;
  if (param_1[0x1b] != 0) {
    do {
      puVar2 = *(undefined4 **)(param_1[0x18] + uVar3 * 4);
      while (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar2;
        func_0x00763260(puVar2);
        puVar2 = puVar1;
      }
      uVar3 = uVar3 + 1;
      *(undefined4 *)(param_1[0x18] + -4 + uVar3 * 4) = 0;
    } while (uVar3 < (uint)param_1[0x1b]);
  }
  param_1[0x17] = 0;
  func_0x004060e0();
  puStack_8._0_1_ = 7;
  func_0x005b5b60();
  puStack_8 = (undefined *)CONCAT31(puStack_8._1_3_,2);
  func_0x006e04e0(param_1[0x12],param_1[0x12] + param_1[0x15] * 4);
  if (param_1[0x12] != 0) {
    func_0x00763260(param_1[0x12]);
  }
  func_0x005b5b60();
  func_0x006e04e0(param_1[0xc],param_1[0xc] + param_1[0xf] * 4);
  if (param_1[0xc] != 0) {
    func_0x00763260(param_1[0xc]);
  }
  func_0x005b5b60();
  func_0x006e04e0(param_1[6],param_1[6] + param_1[9] * 4);
  if (param_1[6] != 0) {
    func_0x00763260(param_1[6]);
  }
  *param_1 = &UNK_008e33f0;
  *unaff_FS_OFFSET = unaff_EBP;
  return;
}


/* ==================================================================== */
/* Address: 0x005b1e00 | Classified: ElementClient::proc_5b1e00 */
/* ==================================================================== */

float10 FUN_005b1e00(float *param_1)

{
  return SQRT((float10)param_1[2] * (float10)param_1[2] + (float10)*param_1 * (float10)*param_1);
}


/* ==================================================================== */
/* Address: 0x005b2420 | Classified: ElementClient::proc_5b2420 */
/* ==================================================================== */

void __fastcall FUN_005b2420(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int unaff_EBP;
  undefined4 unaff_retaddr;
  int *piStack_c;
  int *piStack_8;
  
  if (*(char *)(param_1 + 0x98) != '\0') {
    return;
  }
  iVar1 = param_1 + 0x10;
  *(undefined1 *)(param_1 + 0x98) = 1;
  func_0x00413170(iVar1);
  piVar3 = piStack_8;
  piVar4 = piStack_c;
LAB_005b2457:
  do {
    if (((unaff_EBP == 0) || (iVar1 == 0)) || (unaff_EBP == iVar1)) {
      if (piVar4 == (int *)0x0) {
        if (piVar3 == (int *)0x0) {
          func_0x00649a40(unaff_retaddr,1);
          return;
        }
        goto LAB_005b246b;
      }
LAB_005b24c5:
      piVar5 = piVar3 + 1;
    }
    else {
      if (piVar4 != (int *)0x0) goto LAB_005b24c5;
LAB_005b246b:
      piVar5 = (int *)0x0;
    }
    iVar2 = *piVar5;
    if ((*(char *)(iVar2 + 0x49) == '\0') && (*(int *)(iVar2 + 0x18) != 0)) {
      func_0x00648610(*(int *)(iVar2 + 0x18));
      *(undefined1 *)(iVar2 + 0x49) = 1;
      piVar3 = piStack_8;
      piVar4 = piStack_c;
    }
    if (piVar4 != (int *)0x0) {
      do {
        while (piVar3 != (int *)0x0) {
          piVar3 = (int *)*piVar3;
          piStack_8 = piVar3;
          if (piVar3 != (int *)0x0) goto LAB_005b2457;
        }
        piVar4 = piVar4 + 1;
        if (piVar4 == (int *)(*(int *)(unaff_EBP + 8) + *(int *)(unaff_EBP + 0x14) * 4)) {
          piVar4 = (int *)0x0;
          piStack_c = (int *)0x0;
          break;
        }
        piVar3 = (int *)*piVar4;
        piStack_c = piVar4;
        piStack_8 = piVar3;
      } while (piVar3 == (int *)0x0);
    }
  } while( true );
}


/* ==================================================================== */
/* Address: 0x005b2500 | Classified: ElementClient::proc_5b2500 */
/* ==================================================================== */

void __fastcall FUN_005b2500(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int unaff_EBP;
  undefined4 unaff_retaddr;
  int *piStack_c;
  int *piStack_8;
  
  if (*(char *)(param_1 + 0x98) == '\0') {
    return;
  }
  *(undefined1 *)(param_1 + 0x98) = 0;
  func_0x00413170(param_1 + 0x10);
  piVar2 = piStack_8;
  piVar3 = piStack_c;
LAB_005b2536:
  do {
    if (((unaff_EBP == 0) || (param_1 == -0x10)) || (unaff_EBP == param_1 + 0x10)) {
      if (piVar3 == (int *)0x0) {
        if (piVar2 == (int *)0x0) {
          func_0x00649a40(unaff_retaddr,1);
          return;
        }
        goto LAB_005b254d;
      }
LAB_005b25a3:
      piVar4 = piVar2 + 1;
    }
    else {
      if (piVar3 != (int *)0x0) goto LAB_005b25a3;
LAB_005b254d:
      piVar4 = (int *)0x0;
    }
    iVar1 = *piVar4;
    if (*(char *)(iVar1 + 0x49) != '\0') {
      func_0x00649a30(*(undefined4 *)(iVar1 + 0x18));
      *(undefined1 *)(iVar1 + 0x49) = 0;
      piVar2 = piStack_8;
      piVar3 = piStack_c;
    }
    if (piVar3 != (int *)0x0) {
      do {
        while (piVar2 != (int *)0x0) {
          piVar2 = (int *)*piVar2;
          piStack_8 = piVar2;
          if (piVar2 != (int *)0x0) goto LAB_005b2536;
        }
        piVar3 = piVar3 + 1;
        if (piVar3 == (int *)(*(int *)(unaff_EBP + 8) + *(int *)(unaff_EBP + 0x14) * 4)) {
          piVar3 = (int *)0x0;
          piStack_c = (int *)0x0;
          break;
        }
        piVar2 = (int *)*piVar3;
        piStack_c = piVar3;
        piStack_8 = piVar2;
      } while (piVar2 == (int *)0x0);
    }
  } while( true );
}


/* ==================================================================== */
/* Address: 0x005b25e0 | Classified: CECOrnamentMan::vfunc_slot_9 */
/* ==================================================================== */

undefined4 __fastcall FUN_005b25e0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  char cVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int unaff_EBX;
  int iVar9;
  uint uVar10;
  undefined4 *unaff_FS_OFFSET;
  int iStack_3c;
  int *piStack_38;
  int *piStack_34;
  int iStack_30;
  int *piStack_2c;
  int *piStack_28;
  int *piStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008b7ee8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (*(int *)(param_1 + 0x14) != 0) {
    iVar1 = param_1 + 0x10;
    func_0x00413170(iVar1);
    func_0x0069d760(iVar1,0);
    cVar5 = func_0x005763f0(&iStack_30);
    piVar8 = piStack_38;
    while (piStack_38 = piVar8, cVar5 == '\0') {
      if (piVar8 == (int *)0x0) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = piStack_34 + 1;
      }
      iVar9 = *piVar7;
      if (*(char *)(iVar9 + 0x48) != '\0') {
        func_0x00648600(*(undefined4 *)(iVar9 + 0x18));
      }
      if (*(char *)(iVar9 + 0x49) != '\0') {
        func_0x00649a30(*(undefined4 *)(iVar9 + 0x18));
      }
      func_0x00427760(iVar9);
      if (piVar8 != (int *)0x0) {
        do {
          while (piStack_34 == (int *)0x0) {
            piVar8 = piVar8 + 1;
            if (piVar8 == (int *)(*(int *)(iStack_3c + 8) + *(int *)(iStack_3c + 0x14) * 4)) {
              piStack_38 = (int *)0x0;
              goto LAB_005b26c9;
            }
            piStack_34 = (int *)*piVar8;
            piStack_38 = piVar8;
            if (piStack_34 != (int *)0x0) goto LAB_005b26c9;
          }
          piStack_34 = (int *)*piStack_34;
        } while (piStack_34 == (int *)0x0);
      }
LAB_005b26c9:
      func_0x0069d760(iVar1,0);
      cVar5 = func_0x005763f0(&piStack_2c);
      piVar8 = piStack_38;
    }
    uVar10 = 0;
    if (*(int *)(param_1 + 0x24) != 0) {
      do {
        puVar4 = *(undefined4 **)(*(int *)(param_1 + 0x18) + uVar10 * 4);
        while (puVar4 != (undefined4 *)0x0) {
          puVar2 = (undefined4 *)*puVar4;
          func_0x00763260(puVar4);
          puVar4 = puVar2;
        }
        uVar10 = uVar10 + 1;
        *(undefined4 *)(*(int *)(param_1 + 0x18) + -4 + uVar10 * 4) = 0;
      } while (uVar10 < *(uint *)(param_1 + 0x24));
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  if (*(int *)(param_1 + 0x2c) != 0) {
    piVar8 = (int *)(param_1 + 0x28);
    func_0x00413170(piVar8);
    piStack_24 = (int *)0x0;
    uStack_20 = 0;
    piStack_28 = piVar8;
    cVar5 = func_0x005763f0(&piStack_28);
    piVar7 = piStack_38;
    while (piStack_38 = piVar7, cVar5 == '\0') {
      if (piVar7 == (int *)0x0) {
        piVar6 = (int *)0x0;
      }
      else {
        piVar6 = piStack_34 + 1;
      }
      func_0x00427760(*piVar6);
      if (piVar7 != (int *)0x0) {
        do {
          while (piStack_34 == (int *)0x0) {
            piVar7 = piVar7 + 1;
            if (piVar7 == (int *)(*(int *)(iStack_3c + 8) + *(int *)(iStack_3c + 0x14) * 4)) {
              piStack_38 = (int *)0x0;
              goto LAB_005b27b8;
            }
            piStack_34 = (int *)*piVar7;
            piStack_38 = piVar7;
            if (piStack_34 != (int *)0x0) goto LAB_005b27b8;
          }
          piStack_34 = (int *)*piStack_34;
        } while (piStack_34 == (int *)0x0);
      }
LAB_005b27b8:
      uStack_20 = 0;
      uStack_1c = 0;
      piStack_24 = piVar8;
      cVar5 = func_0x005763f0(&piStack_24);
      piVar7 = piStack_38;
    }
    uVar10 = 0;
    if (*(int *)(param_1 + 0x3c) != 0) {
      do {
        puVar4 = *(undefined4 **)(*(int *)(param_1 + 0x30) + uVar10 * 4);
        while (puVar4 != (undefined4 *)0x0) {
          puVar2 = (undefined4 *)*puVar4;
          func_0x00763260(puVar4);
          puVar4 = puVar2;
        }
        uVar10 = uVar10 + 1;
        *(undefined4 *)(*(int *)(param_1 + 0x30) + -4 + uVar10 * 4) = 0;
      } while (uVar10 < *(uint *)(param_1 + 0x3c));
    }
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  if (*(int *)(param_1 + 0x5c) != 0) {
    iVar1 = param_1 + 0x58;
    func_0x00413170(iVar1);
    func_0x0069d760(iVar1,0);
    cVar5 = func_0x005763f0(&iStack_30);
    piVar8 = piStack_38;
    while (piStack_38 = piVar8, cVar5 == '\0') {
      if (piVar8 == (int *)0x0) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = piStack_34 + 1;
      }
      piVar7 = (int *)*piVar7;
      if (*piVar7 != 0) {
        func_0x006cff10();
        if ((undefined4 *)*piVar7 != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)*piVar7)(1);
        }
      }
      iVar9 = 0;
      if (0 < piVar7[1]) {
        do {
          iVar3 = *(int *)(piVar7[2] + iVar9 * 4);
          if (iVar3 != 0) {
            FUN_005b2c60();
            func_0x00763260(iVar3);
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < piVar7[1]);
      }
      func_0x00763260(piVar7[2]);
      if (piVar7 != (int *)0x0) {
        func_0x007637f0();
        func_0x00763260(piVar7);
      }
      if (piVar8 != (int *)0x0) {
        do {
          while (piStack_34 == (int *)0x0) {
            piVar8 = piVar8 + 1;
            if (piVar8 == (int *)(*(int *)(iStack_3c + 8) + *(int *)(iStack_3c + 0x14) * 4)) {
              piStack_38 = (int *)0x0;
              goto LAB_005b290e;
            }
            piStack_34 = (int *)*piVar8;
            piStack_38 = piVar8;
            if (piStack_34 != (int *)0x0) goto LAB_005b290e;
          }
          piStack_34 = (int *)*piStack_34;
        } while (piStack_34 == (int *)0x0);
      }
LAB_005b290e:
      func_0x0069d760(iVar1,0);
      cVar5 = func_0x005763f0(&piStack_2c);
      piVar8 = piStack_38;
    }
    uVar10 = 0;
    if (*(int *)(param_1 + 0x6c) != 0) {
      do {
        puVar4 = *(undefined4 **)(*(int *)(param_1 + 0x60) + uVar10 * 4);
        while (puVar4 != (undefined4 *)0x0) {
          puVar2 = (undefined4 *)*puVar4;
          func_0x00763260(puVar4);
          puVar4 = puVar2;
        }
        uVar10 = uVar10 + 1;
        *(undefined4 *)(*(int *)(param_1 + 0x60) + -4 + uVar10 * 4) = 0;
      } while (uVar10 < *(uint *)(param_1 + 0x6c));
    }
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  if (*(int *)(param_1 + 0x44) != 0) {
    iVar1 = param_1 + 0x40;
    func_0x00413170(iVar1);
    func_0x0069d760(iVar1,0);
    cVar5 = func_0x005763f0(&iStack_30);
    piVar8 = piStack_38;
    while (cVar5 == '\0') {
      if (piVar8 == (int *)0x0) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = piStack_34 + 1;
      }
      iVar9 = *piVar7;
      if (*(int *)(iVar9 + 0x44) != 0) {
        func_0x006e33a0();
        if (*(undefined4 **)(iVar9 + 0x44) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(iVar9 + 0x44))(1);
        }
        *(undefined4 *)(iVar9 + 0x44) = 0;
      }
      if (iVar9 != 0) {
        func_0x007637f0();
        func_0x00763260(iVar9);
      }
      piStack_38 = piVar8;
      if (piVar8 != (int *)0x0) {
        do {
          while (piStack_34 == (int *)0x0) {
            piVar8 = piVar8 + 1;
            if (piVar8 == (int *)(*(int *)(iStack_3c + 8) + *(int *)(iStack_3c + 0x14) * 4)) {
              piStack_38 = (int *)0x0;
              goto LAB_005b2a3c;
            }
            piStack_34 = (int *)*piVar8;
            piStack_38 = piVar8;
            if (piStack_34 != (int *)0x0) goto LAB_005b2a3c;
          }
          piStack_34 = (int *)*piStack_34;
        } while (piStack_34 == (int *)0x0);
      }
LAB_005b2a3c:
      func_0x0069d760(iVar1,0);
      cVar5 = func_0x005763f0(&piStack_2c);
      piVar8 = piStack_38;
    }
    uVar10 = 0;
    if (*(int *)(param_1 + 0x54) != 0) {
      do {
        puVar4 = *(undefined4 **)(*(int *)(param_1 + 0x48) + uVar10 * 4);
        while (puVar4 != (undefined4 *)0x0) {
          puVar2 = (undefined4 *)*puVar4;
          func_0x00763260(puVar4);
          puVar4 = puVar2;
        }
        uVar10 = uVar10 + 1;
        *(undefined4 *)(*(int *)(param_1 + 0x48) + -4 + uVar10 * 4) = 0;
      } while (uVar10 < *(uint *)(param_1 + 0x54));
    }
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  if (*(int *)(param_1 + 0x74) != 0) {
    func_0x00430890();
    iVar1 = param_1 + 0x70;
    func_0x00413170(iVar1);
    func_0x0069d760(iVar1,0);
    cVar5 = func_0x005763f0(&piStack_24);
    while (cVar5 == '\0') {
      if (piStack_2c == (int *)0x0) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = piStack_28 + 1;
      }
      iVar9 = *piVar8;
      if (*(int *)(iVar9 + 0x20) != 0) {
        FUN_00767220(iVar9 + 0x20);
      }
      if (iVar9 != 0) {
        func_0x007637f0();
        func_0x00763260(iVar9);
      }
      piVar8 = piStack_2c;
      if (piStack_2c != (int *)0x0) {
        do {
          while (piStack_28 == (int *)0x0) {
            piVar8 = piVar8 + 1;
            if (piVar8 == (int *)(*(int *)(iStack_30 + 8) + *(int *)(iStack_30 + 0x14) * 4)) {
              piStack_2c = (int *)0x0;
              goto LAB_005b2b64;
            }
            piStack_28 = (int *)*piVar8;
            piStack_2c = piVar8;
            if (piStack_28 != (int *)0x0) goto LAB_005b2b64;
          }
          piStack_28 = (int *)*piStack_28;
        } while (piStack_28 == (int *)0x0);
      }
LAB_005b2b64:
      func_0x0069d760(iVar1,0);
      cVar5 = func_0x005763f0(&uStack_20);
    }
    uVar10 = 0;
    if (*(int *)(param_1 + 0x84) != 0) {
      do {
        puVar4 = *(undefined4 **)(*(int *)(param_1 + 0x78) + uVar10 * 4);
        while (puVar4 != (undefined4 *)0x0) {
          puVar2 = (undefined4 *)*puVar4;
          func_0x00763260(puVar4);
          puVar4 = puVar2;
        }
        uVar10 = uVar10 + 1;
        *(undefined4 *)(*(int *)(param_1 + 0x78) + -4 + uVar10 * 4) = 0;
      } while (uVar10 < *(uint *)(param_1 + 0x84));
    }
    *(undefined4 *)(param_1 + 0x74) = 0;
  }
  iVar1 = param_1 + 0xb0;
  EnterCriticalSection(iVar1);
  iVar9 = 0;
  puStack_8 = (undefined *)0x0;
  if (0 < *(int *)(param_1 + 0xa4)) {
    do {
      iVar3 = *(int *)(unaff_EBX + 0xa0);
      if (*(int *)(iVar3 + 4 + iVar9 * 8) != 0) {
        func_0x006cff10();
        puVar4 = *(undefined4 **)(iVar3 + iVar9 * 8 + 4);
        if (puVar4 != (undefined4 *)0x0) {
          (**(code **)*puVar4)(1);
        }
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < *(int *)(unaff_EBX + 0xa4));
  }
  if (*(int *)(unaff_EBX + 0xa0) != 0) {
    func_0x00763260(*(int *)(unaff_EBX + 0xa0));
    *(undefined4 *)(unaff_EBX + 0xa0) = 0;
  }
  *(undefined4 *)(unaff_EBX + 0xa8) = 0;
  *(undefined4 *)(unaff_EBX + 0xa4) = 0;
  if (iVar1 != 0) {
    LeaveCriticalSection(iVar1);
  }
  *unaff_FS_OFFSET = uStack_10;
  return 1;
}


/* ==================================================================== */
/* Address: 0x005b2c60 | Classified: ElementClient::proc_5b2c60 */
/* ==================================================================== */

void __fastcall FUN_005b2c60(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    func_0x00892d40(iVar1,0x18,*(undefined4 *)(iVar1 + -4),&UNK_00407370);
    func_0x00763260(iVar1 + -4);
    *param_1 = 0;
  }
  param_1[1] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x005b2ca0 | Classified: CECPlayer::vfunc_slot_20 */
/* ==================================================================== */

undefined1 FUN_005b2ca0(void)

{
  return 1;
}


/* ==================================================================== */
/* Address: 0x005b2cb0 | Classified: elementclient::CECOrnament__LoadOrnament@0x5b2cb0 */
/* ==================================================================== */

int __thiscall
FUN_005b2cb0(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *unaff_FS_OFFSET;
  int iStack_20;
  undefined4 *puStack_18;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008b7f0b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar6 = func_0x00763250(0x74);
  uVar11 = 0;
  uStack_4 = 0;
  if (iVar6 == 0) {
    iStack_20 = 0;
  }
  else {
    iStack_20 = FUN_00489db0(param_1);
  }
  uStack_4 = 0xffffffff;
  if (iStack_20 == 0) {
    func_0x0043c590(2,0x971b54,0x2e3);
    iStack_20 = 0;
  }
  else {
    cVar5 = FUN_00489e70(param_3,param_4,param_5,param_6);
    if (cVar5 == '\0') {
      func_0x00764590(1,0x971b20);
      iStack_20 = 0;
    }
    else {
      if (3 < *(int *)(param_3 + 0x4d0)) {
        *(undefined4 *)(iStack_20 + 0x40) = param_2;
      }
      uVar1 = *(uint *)(iStack_20 + 0x40);
      uVar2 = *(uint *)(param_1 + 0x24);
      uVar7 = *(int *)(param_1 + 0x14) + 1;
      if ((uVar2 < uVar7) && (uVar7 = func_0x00404700(uVar7), uVar2 < uVar7)) {
        if (uVar7 == 0) {
          puVar8 = (undefined4 *)0x0;
          puStack_18 = puVar8;
        }
        else {
          puVar8 = (undefined4 *)func_0x00763250(uVar7 * 4);
          uVar10 = uVar7;
          puStack_18 = puVar8;
          do {
            puVar9 = puStack_18 + 1;
            if (puStack_18 != (undefined4 *)0x0) {
              *puStack_18 = 0;
            }
            uVar10 = uVar10 - 1;
            puStack_18 = puVar9;
          } while (uVar10 != 0);
        }
        if (uVar2 != 0) {
          do {
            puVar9 = (undefined4 *)(*(int *)(param_1 + 0x18) + uVar11 * 4);
            puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x18) + uVar11 * 4);
            while (puVar3 != (undefined4 *)0x0) {
              uVar10 = puVar3[2];
              *puVar9 = *puVar3;
              *puVar3 = puVar8[uVar10 % uVar7];
              puVar8[uVar10 % uVar7] = puVar3;
              puVar9 = (undefined4 *)(*(int *)(param_1 + 0x18) + uVar11 * 4);
              puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x18) + uVar11 * 4);
            }
            uVar11 = uVar11 + 1;
          } while (uVar11 < uVar2);
        }
        iVar6 = *(int *)(param_1 + 0x18);
        *(undefined4 **)(param_1 + 0x18) = puVar8;
        *(undefined4 **)(param_1 + 0x1c) = puStack_18;
        iVar4 = *(int *)(param_1 + 0x24);
        *(uint *)(param_1 + 0x24) = uVar7;
        *(uint *)(param_1 + 0x20) = uVar7;
        func_0x006e04e0(iVar6,iVar6 + iVar4 * 4);
        if (iVar6 != 0) {
          func_0x00763260(iVar6);
        }
      }
      uVar11 = uVar1 % *(uint *)(param_1 + 0x24);
      puVar8 = *(undefined4 **)(*(int *)(param_1 + 0x18) + uVar11 * 4);
      for (puVar9 = puVar8; puVar9 != (undefined4 *)0x0; puVar9 = (undefined4 *)*puVar9) {
        if (puVar9[2] == uVar1) goto LAB_005b2ecb;
      }
      puVar9 = (undefined4 *)func_0x00763250(0xc);
      if (puVar9 == (undefined4 *)0x0) {
        puVar9 = (undefined4 *)0x0;
      }
      else {
        puVar9[1] = iStack_20;
        puVar9[2] = uVar1;
        *puVar9 = puVar8;
      }
      *(undefined4 **)(*(int *)(param_1 + 0x18) + uVar11 * 4) = puVar9;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    }
  }
LAB_005b2ecb:
  *unaff_FS_OFFSET = uStack_c;
  return iStack_20;
}


/* ==================================================================== */
/* Address: 0x005b2ee0 | Classified: ElementClient::proc_5b2ee0 */
/* ==================================================================== */

void __thiscall FUN_005b2ee0(int param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  
  iVar3 = FUN_005b2f90(param_2);
  if (iVar3 != 0) {
    if (*(char *)(iVar3 + 0x48) != '\0') {
      func_0x00648600(*(undefined4 *)(iVar3 + 0x18));
    }
    if (*(char *)(iVar3 + 0x49) != '\0') {
      func_0x00649a30(*(undefined4 *)(iVar3 + 0x18));
    }
    uVar5 = param_2 % *(uint *)(param_1 + 0x24);
    piVar1 = *(int **)(*(int *)(param_1 + 0x18) + uVar5 * 4);
    piVar2 = piVar1;
    piVar6 = (int *)0x0;
    if (piVar1 != (int *)0x0) {
      while (piVar4 = piVar2, piVar4[2] != param_2) {
        piVar2 = (int *)*piVar4;
        piVar6 = piVar4;
        if ((int *)*piVar4 == (int *)0x0) {
          func_0x00427760(iVar3);
          return;
        }
      }
      if (piVar4 == piVar1) {
        *(int *)(*(int *)(param_1 + 0x18) + uVar5 * 4) = *piVar4;
      }
      else {
        *piVar6 = *piVar4;
      }
      func_0x00763260(piVar4);
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
    }
    func_0x00427760(iVar3);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x005b2f90 | Classified: ElementClient::proc_5b2f90 */
/* ==================================================================== */

undefined4 __thiscall FUN_005b2f90(int param_1,uint param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x18) + (param_2 % *(uint *)(param_1 + 0x24)) * 4);
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
/* Address: 0x005b2fc0 | Classified: elementclient::CECOrnament__LoadHomeOrnament__f@0x5b2fc0 */
/* ==================================================================== */

undefined4 __thiscall
FUN_005b2fc0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  uint *unaff_FS_OFFSET;
  undefined4 *puVar11;
  uint uStack_1c;
  uint uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008b7f2b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (uint)&uStack_c;
  iVar5 = func_0x00763250(0x68);
  uVar10 = 0;
  uStack_4 = 0;
  if (iVar5 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = FUN_00489b00(param_1);
  }
  uStack_4 = 0xffffffff;
  if (iVar5 == 0) {
    func_0x0043c590(2,0x971bac,799);
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  cVar4 = FUN_00489c20(param_3,param_4,param_5);
  if (cVar4 == '\0') {
    func_0x00764590(1,0x971b70);
    *unaff_FS_OFFSET = uStack_1c;
    return 0;
  }
  *(uint *)(iVar5 + 100) = uStack_c;
  uVar1 = *(uint *)(param_1 + 0x3c);
  uVar6 = *(int *)(param_1 + 0x2c) + 1;
  if ((uVar1 < uVar6) && (uVar6 = func_0x00404700(uVar6), uVar1 < uVar6)) {
    if (uVar6 == 0) {
      puVar8 = (undefined4 *)0x0;
      puVar7 = puVar8;
    }
    else {
      puVar7 = (undefined4 *)func_0x00763250(uVar6 * 4);
      uVar9 = uVar6;
      puVar11 = puVar7;
      do {
        puVar8 = puVar11 + 1;
        if (puVar11 != (undefined4 *)0x0) {
          *puVar11 = 0;
        }
        uVar9 = uVar9 - 1;
        puVar11 = puVar8;
      } while (uVar9 != 0);
    }
    if (uVar1 != 0) {
      do {
        puVar11 = (undefined4 *)(*(int *)(param_1 + 0x30) + uVar10 * 4);
        puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x30) + uVar10 * 4);
        while (puVar2 != (undefined4 *)0x0) {
          uVar9 = puVar2[2];
          *puVar11 = *puVar2;
          *puVar2 = puVar7[uVar9 % uVar6];
          puVar7[uVar9 % uVar6] = puVar2;
          puVar11 = (undefined4 *)(*(int *)(param_1 + 0x30) + uVar10 * 4);
          puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x30) + uVar10 * 4);
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < uVar1);
    }
    iVar5 = *(int *)(param_1 + 0x30);
    *(undefined4 **)(param_1 + 0x30) = puVar7;
    *(undefined4 **)(param_1 + 0x34) = puVar8;
    iVar3 = *(int *)(param_1 + 0x3c);
    *(uint *)(param_1 + 0x3c) = uVar6;
    *(uint *)(param_1 + 0x38) = uVar6;
    func_0x006e04e0(iVar5,iVar5 + iVar3 * 4);
    if (iVar5 != 0) {
      func_0x00763260(iVar5);
    }
  }
  uVar10 = uStack_c % *(uint *)(param_1 + 0x3c);
  puVar7 = *(undefined4 **)(*(int *)(param_1 + 0x30) + uVar10 * 4);
  for (puVar8 = puVar7; puVar8 != (undefined4 *)0x0; puVar8 = (undefined4 *)*puVar8) {
    if (puVar8[2] == uStack_c) goto LAB_005b31e6;
  }
  puVar8 = (undefined4 *)func_0x00763250(0xc);
  if (puVar8 == (undefined4 *)0x0) {
    puVar8 = (undefined4 *)0x0;
  }
  else {
    puVar8[1] = param_6;
    puVar8[2] = uStack_c;
    *puVar8 = puVar7;
  }
  *(undefined4 **)(*(int *)(param_1 + 0x30) + uVar10 * 4) = puVar8;
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
LAB_005b31e6:
  *unaff_FS_OFFSET = uStack_1c;
  return param_6;
}


/* ==================================================================== */
/* Address: 0x005b3200 | Classified: ElementClient::proc_5b3200 */
/* ==================================================================== */

void __thiscall FUN_005b3200(int param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  
  iVar3 = FUN_005b3280(param_2);
  if (iVar3 != 0) {
    uVar5 = param_2 % *(uint *)(param_1 + 0x3c);
    piVar1 = *(int **)(*(int *)(param_1 + 0x30) + uVar5 * 4);
    piVar2 = piVar1;
    piVar6 = (int *)0x0;
    if (piVar1 != (int *)0x0) {
      while (piVar4 = piVar2, piVar4[2] != param_2) {
        piVar2 = (int *)*piVar4;
        piVar6 = piVar4;
        if ((int *)*piVar4 == (int *)0x0) {
          func_0x00427760(iVar3);
          return;
        }
      }
      if (piVar4 == piVar1) {
        *(int *)(*(int *)(param_1 + 0x30) + uVar5 * 4) = *piVar4;
      }
      else {
        *piVar6 = *piVar4;
      }
      func_0x00763260(piVar4);
      *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + -1;
    }
    func_0x00427760(iVar3);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x005b3280 | Classified: ElementClient::proc_5b3280 */
/* ==================================================================== */

undefined4 __thiscall FUN_005b3280(int param_1,uint param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x30) + (param_2 % *(uint *)(param_1 + 0x3c)) * 4);
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
/* Address: 0x005b32b0 | Classified: ElementClient::proc_5b32b0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_005b32b0(int param_1,int param_2,int *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  float *pfVar13;
  float *pfVar14;
  undefined4 *unaff_FS_OFFSET;
  uint uStack_90;
  undefined4 uStack_8c;
  float afStack_88 [4];
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined1 uStack_50;
  float afStack_4c [3];
  undefined1 auStack_40 [40];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  float fStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  fStack_4 = -NAN;
  puStack_8 = &UNK_008b7f4b;
  *unaff_FS_OFFSET = &uStack_c;
  iVar10 = *(int *)(param_2 + 0x4d0);
  if (iVar10 < 6) {
    cVar5 = (**(code **)(*param_3 + 0x10))(auStack_40,0x2c,&uStack_8c);
    if (cVar5 == '\0') {
      uStack_90 = 0;
      goto LAB_005b3638;
    }
    pfVar13 = afStack_4c;
    pfVar14 = afStack_88;
    for (iVar10 = 0xb; iVar10 != 0; iVar10 = iVar10 + -1) {
      *pfVar14 = *pfVar13;
      pfVar13 = pfVar13 + 1;
      pfVar14 = pfVar14 + 1;
    }
    uStack_5c = 0x3f800000;
LAB_005b3320:
    uStack_58 = 2;
LAB_005b3328:
    uStack_54 = 0x3f800000;
    uStack_50 = 1;
  }
  else {
    if (iVar10 < 8) {
      cVar5 = (**(code **)(*param_3 + 0x10))(auStack_40,0x30,&uStack_8c);
      if (cVar5 == '\0') {
        uStack_90 = 0;
        goto LAB_005b3638;
      }
      pfVar13 = afStack_4c;
      pfVar14 = afStack_88;
      for (iVar10 = 0xc; iVar10 != 0; iVar10 = iVar10 + -1) {
        *pfVar14 = *pfVar13;
        pfVar13 = pfVar13 + 1;
        pfVar14 = pfVar14 + 1;
      }
      goto LAB_005b3320;
    }
    if (iVar10 < 0xc) {
      cVar5 = (**(code **)(*param_3 + 0x10))(auStack_40,0x34);
      if (cVar5 == '\0') {
        uStack_90 = 0;
        goto LAB_005b3638;
      }
      pfVar13 = afStack_4c;
      pfVar14 = afStack_88;
      for (iVar10 = 0xd; iVar10 != 0; iVar10 = iVar10 + -1) {
        *pfVar14 = *pfVar13;
        pfVar13 = pfVar13 + 1;
        pfVar14 = pfVar14 + 1;
      }
      goto LAB_005b3328;
    }
    cVar5 = (**(code **)(*param_3 + 0x10))(afStack_88 + 3,0x3c,&uStack_8c);
    if (cVar5 == '\0') {
      uStack_90 = 0;
      goto LAB_005b3638;
    }
  }
  uStack_10 = 0;
  cVar5 = (**(code **)(*param_3 + 0x1c))(&stack0xffffff54);
  if ((cVar5 == '\0') || (puVar6 = (undefined4 *)func_0x00763250(0x48), puVar6 == (undefined4 *)0x0)
     ) {
    uStack_14 = 0xffffffff;
    func_0x007637f0();
    uStack_90 = 0;
  }
  else {
    *puVar6 = _DAT_009858e4;
    func_0x00763940(&stack0xffffff50);
    puVar6[1] = afStack_88[0] + (float)puStack_8;
    puVar6[2] = afStack_88[1];
    puVar6[3] = afStack_88[2] + fStack_4;
    puVar6[4] = afStack_88[3];
    puVar6[5] = uStack_78;
    puVar6[6] = uStack_74;
    puVar6[7] = uStack_70;
    puVar6[8] = uStack_6c;
    puVar6[9] = uStack_68;
    puVar6[10] = uStack_8c;
    puVar6[0xb] = uStack_64;
    puVar6[0xc] = uStack_60;
    puVar6[0xd] = uStack_5c;
    *(undefined1 *)(puVar6 + 0xe) = (undefined1)uStack_58;
    puVar6[0xf] = 0x437f0000;
    puVar6[0x11] = 0;
    *(undefined1 *)(puVar6 + 0x10) = 0;
    uVar11 = *(uint *)(param_1 + 0x54);
    uVar7 = *(int *)(param_1 + 0x44) + 1;
    if ((uVar11 < uVar7) && (uVar7 = func_0x00404700(uVar7), uVar11 < uVar7)) {
      uVar12 = uVar7;
      if (uVar7 == 0) {
        puVar8 = (undefined4 *)0x0;
        puVar9 = puVar8;
      }
      else {
        puVar8 = (undefined4 *)func_0x00763250(uVar7 * 4);
        puVar9 = puVar8;
      }
      for (; uVar12 != 0; uVar12 = uVar12 - 1) {
        if (puVar8 != (undefined4 *)0x0) {
          *puVar8 = 0;
        }
        puVar8 = puVar8 + 1;
      }
      uVar12 = 0;
      if (uVar11 != 0) {
        do {
          puVar1 = (undefined4 *)(*(int *)(param_1 + 0x48) + uVar12 * 4);
          puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x48) + uVar12 * 4);
          while (puVar2 != (undefined4 *)0x0) {
            uVar3 = puVar2[2];
            *puVar1 = *puVar2;
            *puVar2 = puVar9[uVar3 % uVar7];
            puVar9[uVar3 % uVar7] = puVar2;
            puVar1 = (undefined4 *)(*(int *)(param_1 + 0x48) + uVar12 * 4);
            puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x48) + uVar12 * 4);
          }
          uVar12 = uVar12 + 1;
        } while (uVar12 < uVar11);
      }
      iVar10 = *(int *)(param_1 + 0x48);
      *(undefined4 **)(param_1 + 0x48) = puVar9;
      *(undefined4 **)(param_1 + 0x4c) = puVar8;
      iVar4 = *(int *)(param_1 + 0x54);
      *(uint *)(param_1 + 0x54) = uVar7;
      *(uint *)(param_1 + 0x50) = uVar7;
      func_0x006e04e0(iVar10,iVar10 + iVar4 * 4);
      if (iVar10 != 0) {
        func_0x00763260(iVar10);
      }
    }
    uVar11 = uStack_90 % *(uint *)(param_1 + 0x54);
    puVar8 = *(undefined4 **)(*(int *)(param_1 + 0x48) + uVar11 * 4);
    for (puVar9 = puVar8; puVar9 != (undefined4 *)0x0; puVar9 = (undefined4 *)*puVar9) {
      if (puVar9[2] == uStack_90) goto LAB_005b361e;
    }
    puVar9 = (undefined4 *)func_0x00763250(0xc);
    if (puVar9 == (undefined4 *)0x0) {
      puVar9 = (undefined4 *)0x0;
    }
    else {
      puVar9[1] = puVar6;
      puVar9[2] = uStack_90;
      *puVar9 = puVar8;
    }
    *(undefined4 **)(*(int *)(param_1 + 0x48) + uVar11 * 4) = puVar9;
    *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
LAB_005b361e:
    uStack_18 = 0xffffffff;
    func_0x007637f0();
  }
LAB_005b3638:
  *unaff_FS_OFFSET = uStack_18;
  return uStack_90;
}


/* ==================================================================== */
/* Address: 0x005b3660 | Classified: ElementClient::proc_5b3660 */
/* ==================================================================== */

void __thiscall FUN_005b3660(int param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  
  iVar4 = func_0x005b86c0(param_2);
  if (iVar4 != 0) {
    if (*(int *)(iVar4 + 0x44) != 0) {
      func_0x006e33a0();
      if (*(undefined4 **)(iVar4 + 0x44) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(iVar4 + 0x44))(1);
      }
      *(undefined4 *)(iVar4 + 0x44) = 0;
    }
    func_0x006e5870();
    func_0x00763260(iVar4);
    piVar1 = (int *)(*(int *)(param_1 + 0x48) + (param_2 % *(uint *)(param_1 + 0x54)) * 4);
    piVar2 = (int *)*piVar1;
    piVar3 = piVar2;
    piVar6 = (int *)0x0;
    if (piVar2 != (int *)0x0) {
      while (piVar5 = piVar3, piVar5[2] != param_2) {
        piVar3 = (int *)*piVar5;
        piVar6 = piVar5;
        if ((int *)*piVar5 == (int *)0x0) {
          return;
        }
      }
      if (piVar5 == piVar2) {
        *piVar1 = *piVar5;
      }
      else {
        *piVar6 = *piVar5;
      }
      func_0x00763260(piVar5);
      *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + -1;
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x005b3700 | Classified: ElementClient::proc_5b3700 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005b3700(int param_1)

{
  float fVar1;
  undefined4 in_EAX;
  undefined3 uVar3;
  int iVar2;
  undefined3 extraout_var;
  float fStack_58;
  undefined4 uStack_54;
  int iStack_50;
  undefined4 uStack_4c;
  
  uVar3 = (undefined3)((uint)in_EAX >> 8);
  if (*(char *)(param_1 + 0x40) == '\0') {
    *(undefined1 *)(param_1 + 0x40) = 1;
    uStack_4c = 0;
    iStack_50 = param_1;
    uStack_54 = *(undefined4 *)(_DAT_009b3eec + 8);
    fStack_58 = 8.376826e-39;
    iVar2 = func_0x006e7950();
    if (iVar2 == 0) {
      return 0;
    }
    fStack_58 = (float)(param_1 + 4);
    func_0x00788960(&uStack_4c,param_1 + 0x10,param_1 + 0x1c);
    fStack_58 = *(float *)(param_1 + 0x28);
    *(float *)(iVar2 + 0x1e0) = fStack_58;
    fStack_58 = fStack_58 * *(float *)(iVar2 + 0x1d4);
    *(float *)(iVar2 + 0x1ec) = fStack_58;
    func_0x00787de0(fStack_58,fStack_58);
    *(undefined1 *)(iVar2 + 0x1c4) = 1;
    fVar1 = *(float *)(param_1 + 0x2c);
    *(float *)(iVar2 + 0x1dc) = fVar1;
    *(float *)(iVar2 + 0x1e8) = fVar1 * *(float *)(iVar2 + 0x1d0);
    func_0x006e52c0(&fStack_58);
    *(undefined4 *)(param_1 + 0x3c) = 0x3f800000;
    *(int *)(param_1 + 0x44) = iVar2;
    uVar3 = extraout_var;
  }
  return CONCAT31(uVar3,1);
}


/* ==================================================================== */
/* Address: 0x005b37c0 | Classified: ElementClient::proc_5b37c0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b37c0(int param_1,char param_2)

{
  int *piVar1;
  float fVar2;
  float unaff_retaddr;
  
  fVar2 = *(float *)(param_1 + 0x3c) * *(float *)(param_1 + 0x34);
  piVar1 = *(int **)(param_1 + 0x44);
  if (piVar1 != (int *)0x0) {
    if (param_2 == '\0') {
      if (piVar1[0xe] == 1) {
        if ((float)piVar1[0x79] == _DAT_008d58a0) {
          (**(code **)(*piVar1 + 0x18))();
          return;
        }
        if ((piVar1[0xa4] == 0) || (_DAT_008d58a0 < (float)piVar1[0xa2])) {
          fVar2 = -(float)piVar1[0x79] * _DAT_008e3808;
          piVar1[0xa3] = 0;
          piVar1[0xa4] = 3000;
          piVar1[0xa2] = (int)fVar2;
        }
      }
    }
    else {
      if (piVar1[0xe] == 0) {
        (**(code **)(*piVar1 + 0x10))(1);
        piVar1[0x79] = 0;
        fVar2 = unaff_retaddr * _DAT_008e3808;
        piVar1[0x7c] = 0;
        piVar1[0xa3] = (int)unaff_retaddr;
        piVar1[0xa4] = 3000;
        piVar1[0xa2] = (int)fVar2;
        return;
      }
      if ((float)piVar1[0xa2] <= _DAT_008d58a0) {
        piVar1[0xa4] = 3000;
        piVar1[0xa3] = (int)fVar2;
        piVar1[0xa2] = (int)((fVar2 - (float)piVar1[0x79]) * _DAT_008e3808);
        return;
      }
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x005b38f0 | Classified: ElementClient::proc_5b38f0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_005b38f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,uint param_9)

{
  undefined4 *puVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int extraout_ECX;
  uint uVar11;
  int *piVar12;
  int iVar13;
  uint *unaff_FS_OFFSET;
  uint in_stack_00000034;
  undefined4 in_stack_00000038;
  undefined4 in_stack_0000003c;
  undefined4 in_stack_00000040;
  undefined4 in_stack_00000044;
  undefined4 in_stack_00000048;
  undefined4 in_stack_0000004c;
  uint in_stack_00000050;
  int in_stack_00000054;
  int in_stack_00000058;
  undefined4 in_stack_0000005c;
  undefined4 in_stack_000000fc;
  uint in_stack_000013d4;
  int *in_stack_000013f0;
  undefined1 *puVar14;
  undefined4 *puStack_24;
  undefined4 *puStack_20;
  undefined4 *puStack_1c;
  uint uStack_c;
  undefined *puStack_8;
  uint uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008b7f8c;
  *unaff_FS_OFFSET = (uint)&uStack_c;
  func_0x00892f20();
  puStack_24 = &stack0x00000048;
  puStack_1c = (undefined4 *)&stack0x00000070;
  puStack_20 = (undefined4 *)0x28;
  cVar3 = (**(code **)(*in_stack_000013f0 + 0x10))();
  uVar6 = _DAT_009858e4;
  if (cVar3 != '\0') {
    cVar3 = (**(code **)(*in_stack_000013f0 + 0x1c))();
    if ((cVar3 != '\0') && (cVar3 = (**(code **)(*in_stack_000013f0 + 0x1c))(), cVar3 != '\0')) {
      param_1 = in_stack_0000003c;
      param_2 = in_stack_00000040;
      param_3 = in_stack_00000044;
      param_7 = in_stack_00000048;
      param_8 = in_stack_0000004c;
      param_9 = in_stack_00000050;
      param_4 = in_stack_00000054;
      param_5 = in_stack_00000058;
      piVar12 = (int *)0x0;
      param_6 = in_stack_0000005c;
      cVar3 = func_0x004283c0();
      if (cVar3 == '\0') {
        piVar12 = (int *)FUN_005b3f70(uVar6);
        if (piVar12 != (int *)0x0) {
          (**(code **)(*piVar12 + 0x10))(&param_1);
          puVar9 = &param_6;
          (**(code **)(*piVar12 + 0x14))(puVar9,&param_3);
          iVar5 = piVar12[0x32];
          func_0x00703260(&param_8,&puStack_24);
          func_0x0069d760(iVar5 + 0x14,0);
          cVar3 = func_0x005763f0(&stack0xffffffd4);
          if (cVar3 == '\0') {
            if (param_4 == 0) {
              iVar5 = 0;
            }
            else {
              iVar5 = param_5 + 4;
            }
            if (*(int *)(iVar5 + 4) == 0) goto LAB_005b3ab3;
          }
          else {
LAB_005b3ab3:
            puVar9 = (undefined4 *)0x95a750;
          }
          func_0x006d1dc0(puVar9,0x3f800000,1,200,1,0,0);
          iVar5 = rand();
          func_0x006d0e30(iVar5 % 1000);
        }
      }
      else {
        func_0x004278c0(3,in_stack_00000038,0,&param_1,uVar6,0,0,0,0);
      }
      puStack_1c = (undefined4 *)func_0x00763250(0x34);
      if (puStack_1c == (undefined4 *)0x0) {
        puStack_1c = (undefined4 *)0x0;
      }
      else {
        puStack_1c[0xc] = _DAT_009858e4;
      }
      puVar9 = puStack_1c;
      *puStack_1c = piVar12;
      puStack_1c[1] = 0;
      puStack_1c[2] = 0;
      puStack_1c[3] = param_1;
      puStack_1c[4] = param_2;
      puStack_1c[5] = param_3;
      puStack_1c[6] = param_7;
      puStack_1c[7] = param_8;
      puStack_1c[8] = param_9;
      puStack_1c[9] = param_4;
      puStack_1c[10] = param_5;
      puVar14 = &stack0xffffffe8;
      puStack_1c[0xb] = param_6;
      func_0x00763940();
      if ((piVar12 != (int *)0x0) && (iVar5 = piVar12[0x32], *(int *)(iVar5 + 0xb4) != 0)) {
        func_0x00788960(&stack0x000000c4,&param_6,&param_3,&stack0x00000000);
        if (*(int *)(iVar5 + 0xb4) != puVar9[1]) {
          puVar9[1] = *(int *)(iVar5 + 0xb4);
          uVar6 = func_0x00763250(*(int *)(iVar5 + 0xb4) * 4);
          puVar9[2] = uVar6;
          iVar13 = 0;
          if (0 < (int)puVar9[1]) {
            do {
              func_0x0072c660(*(undefined4 *)(*(int *)(iVar5 + 0xa8) + iVar13 * 4));
              func_0x0072c5e0(&stack0x000000c0);
              in_stack_000000fc = 0;
              func_0x0072a330(&stack0x00000058);
              puVar7 = (undefined4 *)func_0x00763250(0x3c);
              puVar9 = (undefined4 *)0x0;
              if (puVar7 != (undefined4 *)0x0) {
                *puVar7 = 0;
                puVar7[1] = 0;
                puVar7[0xe] = 0;
                puVar9 = puVar7;
              }
              func_0x0072aeb0(puVar9);
              *(undefined4 **)(*(int *)(puVar14 + 8) + iVar13 * 4) = puVar9;
              func_0x0072a2c0();
              func_0x0072b620();
              iVar13 = iVar13 + 1;
              puVar9 = puStack_20;
            } while (iVar13 < (int)puStack_20[1]);
          }
        }
      }
      uVar4 = *(uint *)(extraout_ECX + 0x6c);
      uVar8 = *(int *)(extraout_ECX + 0x5c) + 1;
      uStack_4 = in_stack_00000034;
      if ((uVar4 < uVar8) && (uVar8 = func_0x00404700(uVar8), param_9 = uVar8, uVar4 < uVar8)) {
        uStack_c = uVar8;
        uVar11 = uVar8;
        if (uVar8 == 0) {
          puVar9 = (undefined4 *)0x0;
          puVar7 = puVar9;
        }
        else {
          puVar9 = (undefined4 *)func_0x00763250(uVar8 * 4);
          puVar7 = puVar9;
        }
        for (; uVar11 != 0; uVar11 = uVar11 - 1) {
          if (puVar9 != (undefined4 *)0x0) {
            *puVar9 = 0;
          }
          puVar9 = puVar9 + 1;
        }
        uVar11 = 0;
        if (uVar4 != 0) {
          do {
            puVar10 = (undefined4 *)(*(int *)(extraout_ECX + 0x60) + uVar11 * 4);
            puVar1 = *(undefined4 **)(*(int *)(extraout_ECX + 0x60) + uVar11 * 4);
            while (puVar1 != (undefined4 *)0x0) {
              uVar2 = puVar1[2];
              *puVar10 = *puVar1;
              *puVar1 = puVar7[uVar2 % param_9];
              puVar7[uVar2 % param_9] = puVar1;
              puVar10 = (undefined4 *)(*(int *)(extraout_ECX + 0x60) + uVar11 * 4);
              puVar1 = *(undefined4 **)(*(int *)(extraout_ECX + 0x60) + uVar11 * 4);
            }
            uVar11 = uVar11 + 1;
          } while (uVar11 < uVar4);
        }
        iVar5 = *(int *)(extraout_ECX + 0x60);
        *(undefined4 **)(extraout_ECX + 0x60) = puVar7;
        *(undefined4 **)(extraout_ECX + 100) = puVar9;
        puStack_8 = *(undefined **)(extraout_ECX + 0x6c);
        *(uint *)(extraout_ECX + 0x6c) = uVar8;
        uVar4 = *(uint *)(extraout_ECX + 0x68);
        *(uint *)(extraout_ECX + 0x68) = uStack_c;
        uStack_c = uVar4;
        func_0x006e04e0(iVar5,iVar5 + (int)puStack_8 * 4);
        puVar9 = puStack_20;
        if (iVar5 != 0) {
          func_0x00763260(iVar5);
          puVar9 = puStack_20;
        }
      }
      uVar4 = uStack_4 % *(uint *)(extraout_ECX + 0x6c);
      puVar7 = *(undefined4 **)(*(int *)(extraout_ECX + 0x60) + uVar4 * 4);
      for (puVar10 = puVar7; puVar10 != (undefined4 *)0x0; puVar10 = (undefined4 *)*puVar10) {
        if (puVar10[2] == uStack_4) goto LAB_005b3dff;
      }
      puVar10 = (undefined4 *)func_0x00763250(0xc);
      if (puVar10 == (undefined4 *)0x0) {
        puVar10 = (undefined4 *)0x0;
      }
      else {
        puVar10[1] = puVar9;
        puVar10[2] = uStack_4;
        *puVar10 = puVar7;
      }
      *(undefined4 **)(*(int *)(extraout_ECX + 0x60) + uVar4 * 4) = puVar10;
      *(int *)(extraout_ECX + 0x5c) = *(int *)(extraout_ECX + 0x5c) + 1;
LAB_005b3dff:
      uVar4 = in_stack_00000034;
      func_0x007637f0();
      in_stack_000013d4 = 0xffffffff;
      func_0x007637f0();
      goto LAB_005b3e2b;
    }
    func_0x007637f0();
    func_0x007637f0();
  }
  uVar4 = 0;
LAB_005b3e2b:
  *unaff_FS_OFFSET = in_stack_000013d4;
  return uVar4;
}


/* ==================================================================== */
/* Address: 0x005b3e50 | Classified: ElementClient::proc_5b3e50 */
/* ==================================================================== */

void __thiscall FUN_005b3e50(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  int unaff_EBX;
  int iVar7;
  uint unaff_retaddr;
  
  piVar3 = (int *)FUN_005b40a0(param_2);
  if (piVar3 != (int *)0x0) {
    if (*piVar3 != 0) {
      FUN_005b4060(*piVar3);
    }
    iVar7 = 0;
    if (0 < piVar3[1]) {
      do {
        piVar1 = *(int **)(piVar3[2] + iVar7 * 4);
        if (piVar1 != (int *)0x0) {
          iVar2 = *piVar1;
          if (iVar2 != 0) {
            func_0x00892d40(iVar2,0x18,*(undefined4 *)(iVar2 + -4),&UNK_00407370);
            func_0x00763260(iVar2 + -4);
            *piVar1 = 0;
            param_1 = unaff_EBX;
          }
          piVar1[1] = 0;
          func_0x00763260(piVar1);
          *(undefined4 *)(piVar3[2] + iVar7 * 4) = 0;
        }
        iVar7 = iVar7 + 1;
        param_2 = unaff_retaddr;
      } while (iVar7 < piVar3[1]);
    }
    if (piVar3[2] != 0) {
      func_0x00763260(piVar3[2]);
      piVar3[2] = 0;
    }
    FUN_005b3f60();
    func_0x00763260(piVar3);
    uVar5 = param_2 % *(uint *)(param_1 + 0x6c);
    piVar3 = *(int **)(*(int *)(param_1 + 0x60) + uVar5 * 4);
    piVar1 = piVar3;
    piVar6 = (int *)0x0;
    if (piVar3 != (int *)0x0) {
      while (piVar4 = piVar1, piVar4[2] != param_2) {
        piVar1 = (int *)*piVar4;
        piVar6 = piVar4;
        if ((int *)*piVar4 == (int *)0x0) {
          return;
        }
      }
      if (piVar4 == piVar3) {
        *(int *)(*(int *)(param_1 + 0x60) + uVar5 * 4) = *piVar4;
      }
      else {
        *piVar6 = *piVar4;
      }
      func_0x00763260(piVar4);
      *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + -1;
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x005b3f60 | Classified: ElementClient::proc_5b3f60 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_005b3f60(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x30) + -0xc);
  if (*piVar1 == -1) {
    *piVar1 = 1;
  }
  func_0x00763450(piVar1);
  *(int *)(param_1 + 0x30) = _DAT_009858e4;
  return;
}


/* ==================================================================== */
/* Address: 0x005b3f70 | Classified: elementclient::models_error_error_ecm@0x5b3f70 */
/* ==================================================================== */

undefined4 * FUN_005b3f70(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar4;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008b7fab;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar2 = func_0x00763250(0x3f4);
  uStack_4 = 0;
  if (iVar2 == 0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)func_0x006cef80();
  }
  uStack_4 = 0xffffffff;
  if (puVar3 == (undefined4 *)0x0) {
    *unaff_FS_OFFSET = uStack_c;
    return (undefined4 *)0x0;
  }
  uVar4 = 0;
  cVar1 = func_0x006cf5f0(param_1,1,0,1,1,1);
  if (cVar1 == '\0') {
    cVar1 = func_0x006cf5f0(0x957288,1,0,1,1,1);
    if (cVar1 == '\0') {
      func_0x00764590(1,0x971bcc,param_1);
      (**(code **)*puVar3)(1);
      *unaff_FS_OFFSET = uVar4;
      return (undefined4 *)0x0;
    }
  }
  func_0x006d4330(2);
  *(undefined1 *)((int)puVar3 + 0xb5) = 0;
  *unaff_FS_OFFSET = uVar4;
  return puVar3;
}


/* ==================================================================== */
/* Address: 0x005b4060 | Classified: ElementClient::proc_5b4060 */
/* ==================================================================== */

void FUN_005b4060(undefined4 *param_1)

{
  char cVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    cVar1 = func_0x004283c0();
    if (cVar1 != '\0') {
      func_0x00427d40(param_1);
      return;
    }
    func_0x006cff10();
    (**(code **)*param_1)(1);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x005b40a0 | Classified: ElementClient::proc_5b40a0 */
/* ==================================================================== */

undefined4 __thiscall FUN_005b40a0(int param_1,uint param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x60) + (param_2 % *(uint *)(param_1 + 0x6c)) * 4);
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
/* Address: 0x005b40d0 | Classified: ElementClient::proc_5b40d0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall FUN_005b40d0(int param_1,int param_2,int *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  char cVar4;
  float *pfVar5;
  undefined4 uVar6;
  undefined *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  float *pfVar11;
  undefined *puVar12;
  float fVar13;
  uint *unaff_FS_OFFSET;
  float unaff_retaddr;
  undefined1 auStack_5c [8];
  float afStack_54 [3];
  undefined1 auStack_48 [8];
  float fStack_40;
  float afStack_38 [5];
  float fStack_24;
  undefined4 uStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  undefined *puStack_10;
  uint uStack_c;
  undefined *puStack_8;
  float fStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  fStack_4 = -NAN;
  puStack_8 = &UNK_008b7fd0;
  *unaff_FS_OFFSET = (uint)&uStack_c;
  if (*(int *)(param_2 + 0x4d0) < 10) {
    cVar4 = (**(code **)(*param_3 + 0x10))(auStack_48,0x1c);
    if (cVar4 == '\0') {
      fStack_40 = 0.0;
      goto LAB_005b439f;
    }
    pfVar5 = afStack_54;
    pfVar11 = afStack_38;
    for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
      *pfVar11 = *pfVar5;
      pfVar5 = pfVar5 + 1;
      pfVar11 = pfVar11 + 1;
    }
    uStack_1c = 2;
  }
  else {
    cVar4 = (**(code **)(*param_3 + 0x10))(afStack_38 + 3,0x20,auStack_5c);
    if (cVar4 == '\0') {
      fStack_40 = 0.0;
      goto LAB_005b439f;
    }
  }
  fStack_4 = _DAT_009858e4;
  puStack_10 = (undefined *)0x0;
  cVar4 = (**(code **)(*param_3 + 0x1c))(&fStack_4);
  if ((cVar4 == '\0') || (pfVar5 = (float *)func_0x00763250(0x24), pfVar5 == (float *)0x0)) {
    uStack_14 = 0xffffffff;
    func_0x007637f0();
    fStack_40 = 0.0;
  }
  else {
    *pfVar5 = _DAT_009858e4;
    pfVar5[1] = afStack_38[0] + fStack_4;
    pfVar5[2] = afStack_38[1];
    pfVar5[3] = afStack_38[2] + unaff_retaddr;
    uVar6 = FUN_0041e9b0(&uStack_c,0x971c0c,&puStack_8);
    uStack_14 = CONCAT31(uStack_14._1_3_,1);
    func_0x00763940(uVar6);
    uStack_18 = uStack_18 & 0xffffff00;
    func_0x007637f0();
    fVar13 = fStack_40;
    pfVar5[4] = afStack_38[2];
    pfVar5[5] = afStack_38[3];
    pfVar5[6] = fStack_24;
    pfVar5[8] = 0.0;
    *(undefined1 *)(pfVar5 + 7) = 0;
    puStack_10 = *(undefined **)(param_1 + 0x84);
    puVar7 = (undefined *)(*(int *)(param_1 + 0x74) + 1);
    fStack_4 = fStack_40;
    if ((puStack_10 < puVar7) &&
       (puVar7 = (undefined *)func_0x00404700(puVar7), puStack_8 = puVar7, puStack_10 < puVar7)) {
      puVar12 = puVar7;
      if (puVar7 == (undefined *)0x0) {
        puVar8 = (undefined4 *)0x0;
        puVar9 = puVar8;
      }
      else {
        puVar8 = (undefined4 *)func_0x00763250((int)puVar7 * 4);
        puVar9 = puVar8;
      }
      for (; puVar12 != (undefined *)0x0; puVar12 = puVar12 + -1) {
        if (puVar8 != (undefined4 *)0x0) {
          *puVar8 = 0;
        }
        puVar8 = puVar8 + 1;
      }
      puVar12 = (undefined *)0x0;
      if (puStack_10 != (undefined *)0x0) {
        do {
          puVar1 = (undefined4 *)(*(int *)(param_1 + 0x78) + (int)puVar12 * 4);
          puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x78) + (int)puVar12 * 4);
          while (puVar2 != (undefined4 *)0x0) {
            uVar3 = puVar2[2];
            *puVar1 = *puVar2;
            *puVar2 = puVar9[uVar3 % (uint)puStack_8];
            puVar9[uVar3 % (uint)puStack_8] = puVar2;
            puVar1 = (undefined4 *)(*(int *)(param_1 + 0x78) + (int)puVar12 * 4);
            puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x78) + (int)puVar12 * 4);
          }
          puVar12 = puVar12 + 1;
        } while (puVar12 < puStack_10);
      }
      iVar10 = *(int *)(param_1 + 0x78);
      *(undefined4 **)(param_1 + 0x78) = puVar9;
      *(undefined4 **)(param_1 + 0x7c) = puVar8;
      *(undefined **)(param_1 + 0x84) = puVar7;
      *(undefined **)(param_1 + 0x80) = puVar7;
      func_0x005b5c40();
      fVar13 = fStack_4;
      if (iVar10 != 0) {
        func_0x00763260(iVar10);
        fVar13 = fStack_4;
      }
    }
    puStack_10 = (undefined *)((uint)fVar13 % *(uint *)(param_1 + 0x84));
    puVar8 = *(undefined4 **)(*(int *)(param_1 + 0x78) + (int)puStack_10 * 4);
    for (puVar9 = puVar8; puVar9 != (undefined4 *)0x0; puVar9 = (undefined4 *)*puVar9) {
      if ((float)puVar9[2] == fVar13) goto LAB_005b4388;
    }
    puVar9 = (undefined4 *)func_0x00763250(0xc);
    if (puVar9 == (undefined4 *)0x0) {
      puVar9 = (undefined4 *)0x0;
    }
    else {
      puVar9[1] = pfVar5;
      puVar9[2] = fVar13;
      *puVar9 = puVar8;
    }
    *(undefined4 **)(*(int *)(param_1 + 0x78) + (int)puStack_10 * 4) = puVar9;
    *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + 1;
LAB_005b4388:
    uStack_18 = 0xffffffff;
    func_0x007637f0();
  }
LAB_005b439f:
  *unaff_FS_OFFSET = uStack_18;
  return fStack_40;
}


/* ==================================================================== */
/* Address: 0x005b43c0 | Classified: ElementClient::proc_5b43c0 */
/* ==================================================================== */

void __thiscall FUN_005b43c0(int param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  
  iVar3 = FUN_005b4590(param_2);
  if (iVar3 != 0) {
    if (*(int *)(iVar3 + 0x20) != 0) {
      func_0x00430890(iVar3 + 0x20);
      FUN_00767220();
    }
    func_0x006e5870();
    func_0x00763260(iVar3);
    uVar5 = param_2 % *(uint *)(param_1 + 0x84);
    piVar1 = *(int **)(*(int *)(param_1 + 0x78) + uVar5 * 4);
    piVar2 = piVar1;
    piVar6 = (int *)0x0;
    if (piVar1 != (int *)0x0) {
      while (piVar4 = piVar2, piVar4[2] != param_2) {
        piVar2 = (int *)*piVar4;
        piVar6 = piVar4;
        if ((int *)*piVar4 == (int *)0x0) {
          return;
        }
      }
      if (piVar4 == piVar1) {
        *(int *)(*(int *)(param_1 + 0x78) + uVar5 * 4) = *piVar4;
      }
      else {
        *piVar6 = *piVar4;
      }
      func_0x00763260(piVar4);
      *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + -1;
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x005b4460 | Classified: elementclient::CECOrnamentMan__LoadSoundFromFil@0x5b4460 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005b4460(undefined4 *param_1)

{
  int iVar1;
  
  if ((param_1 != (undefined4 *)0x0) && (*(char *)(param_1 + 7) == '\0')) {
    *(undefined1 *)(param_1 + 7) = 1;
    func_0x00430890(*param_1,0);
    iVar1 = FUN_007671b0();
    if (iVar1 == 0) {
      func_0x00764590(1,0x971c14,*param_1);
      return 0;
    }
    *(undefined4 *)(iVar1 + 0x70) = param_1[1];
    *(undefined4 *)(iVar1 + 0x74) = param_1[2];
    *(undefined4 *)(iVar1 + 0x78) = param_1[3];
    *(undefined4 *)(iVar1 + 0x90) = _DAT_009b4340;
    *(undefined4 *)(iVar1 + 0x94) = _DAT_009b4344;
    *(undefined4 *)(iVar1 + 0x98) = _DAT_009b4348;
    *(undefined4 *)(iVar1 + 0xa4) = param_1[5];
    *(undefined4 *)(iVar1 + 0xa0) = param_1[4];
    FUN_00769580();
    param_1[8] = iVar1;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x005b4510 | Classified: ElementClient::proc_5b4510 */
/* ==================================================================== */

void FUN_005b4510(int *param_1,char param_2)

{
  int *piVar1;
  
  if (param_1 != (int *)0x0) {
    if (param_2 == '\0') {
      if ((param_1[0x14] == 1) && (*(char *)((int)param_1 + 0x59) == '\0')) {
        FUN_007692d0(3000);
      }
    }
    else {
      if (param_1[0x14] != 1) {
        piVar1 = (int *)param_1[0xc];
        param_1[0x15] = 0;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 0x3c))(piVar1,0xffffd8f0);
        }
        (**(code **)(*param_1 + 0x24))(1);
        FUN_00769230(3000);
        return;
      }
      if ((char)param_1[0x16] == '\0') {
        FUN_00769230(3000);
        return;
      }
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x005b4590 | Classified: ElementClient::proc_5b4590 */
/* ==================================================================== */

undefined4 __thiscall FUN_005b4590(int param_1,uint param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x78) + (param_2 % *(uint *)(param_1 + 0x84)) * 4);
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
/* Address: 0x005b45d0 | Classified: CECOrnamentMan::vfunc_slot_11 */
/* ==================================================================== */

char __thiscall FUN_005b45d0(int *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  float unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  float *unaff_retaddr;
  undefined4 uStack_94;
  undefined4 uStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  undefined4 uStack_40;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined1 uStack_3a;
  undefined1 auStack_38 [8];
  undefined *puStack_30;
  float fStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008b7feb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  puStack_30 = &UNK_008d5ba0;
  uStack_4 = 0;
  fStack_88 = param_2[1];
  fStack_8c = *param_2;
  fStack_84 = param_2[2];
  uStack_94 = 0;
  uStack_90 = 0;
  func_0x00401cc0(param_3);
  func_0x00401cc0(&stack0xffffff64);
  uStack_20 = 0x42c80000;
  uStack_3c = 1;
  uStack_3b = 0;
  uStack_3a = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_40 = 0x3727c5ac;
  cVar4 = (**(code **)(*param_1 + 0x30))(&uStack_94);
  if (cVar4 != '\0') {
    fVar1 = param_3[1];
    fVar2 = param_2[1];
    fVar3 = fStack_24 * param_3[2] + param_2[2];
    *unaff_retaddr = fStack_24 * *param_3 + *param_2;
    unaff_retaddr[2] = fVar3;
    unaff_retaddr[1] = fStack_24 * fVar1 + fVar2;
    *param_2 = fStack_24;
    func_0x00401cc0(auStack_38);
    *param_3 = unaff_EDI;
    param_3[1] = fStack_24 * fVar1;
    param_3[2] = fVar3;
  }
  *unaff_FS_OFFSET = uStack_18;
  return cVar4;
}


