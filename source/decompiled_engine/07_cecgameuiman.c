/* Authentic Ghidra 12.1.4 Decompilation — elementclient.exe (PW 1.4.2 Build 2305) */
/* Module: 07_cecgameuiman.c */

/* ==================================================================== */
/* Address: 0x0058d2a0 | Classified: CECGameUIMan::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0058d2a0(undefined4 param_1,byte param_2)

{
  FUN_0058d4a0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0058d2c0 | Classified: ElementClient::proc_58d2c0 */
/* ==================================================================== */

void __fastcall FUN_0058d2c0(int param_1)

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
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008b543b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uVar7 = 0;
  uStack_4 = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    do {
      puVar2 = *(undefined4 **)(*(int *)(param_1 + 8) + uVar7 * 4);
      while (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar2;
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
/* Address: 0x0058d3a0 | Classified: ElementClient::proc_58d3a0 */
/* ==================================================================== */

void __fastcall FUN_0058d3a0(int param_1)

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
  
  puStack_8 = &UNK_008b5466;
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
/* Address: 0x0058d4a0 | Classified: ElementClient::proc_58d4a0 */
/* ==================================================================== */

void __fastcall FUN_0058d4a0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int *unaff_FS_OFFSET;
  int iVar8;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008b54d3;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  *param_1 = &UNK_008e31bc;
  uStack_4 = 5;
  func_0x0059b730(param_1[0x188],param_1[0x188] + param_1[0x18b] * 8);
  if (param_1[0x188] != 0) {
    func_0x00763260(param_1[0x188]);
  }
  iVar8 = param_1[0x184];
  iStack_c = CONCAT31(iStack_c._1_3_,4);
  func_0x006e04e0(iVar8,iVar8 + param_1[0x187] * 4);
  if (param_1[0x184] != 0) {
    func_0x00763260(param_1[0x184]);
  }
  FUN_00765200();
  func_0x00892d40(param_1 + 0x11f,0x18,0xb,FUN_0058d3a0);
  uVar7 = 0;
  if (param_1[0x11e] != 0) {
    do {
      puVar1 = *(undefined4 **)(param_1[0x11b] + uVar7 * 4);
      while (puVar1 != (undefined4 *)0x0) {
        puVar2 = (undefined4 *)*puVar1;
        func_0x007637f0();
        func_0x00763260(puVar1);
        puVar1 = puVar2;
      }
      uVar7 = uVar7 + 1;
      *(undefined4 *)(param_1[0x11b] + -4 + uVar7 * 4) = 0;
    } while (uVar7 < (uint)param_1[0x11e]);
  }
  param_1[0x11a] = 0;
  puVar2 = (undefined4 *)param_1[0x11b];
  puVar1 = puVar2 + param_1[0x11e];
  if (puVar2 != puVar1) {
    puVar3 = puVar1;
    puVar6 = puVar2;
    if (puVar1 < (undefined4 *)param_1[0x11c]) {
      do {
        puVar4 = puVar3 + 1;
        *puVar6 = *puVar3;
        puVar3 = puVar4;
        puVar6 = puVar6 + 1;
      } while (puVar4 < (undefined4 *)param_1[0x11c]);
    }
    iVar5 = (int)puVar1 - (int)puVar2 >> 2;
    param_1[0x11c] = param_1[0x11c] + iVar5 * -4;
    param_1[0x11e] = param_1[0x11e] - iVar5;
  }
  if (param_1[0x11b] != 0) {
    func_0x00763260(param_1[0x11b]);
  }
  func_0x00419370();
  FUN_0072e4e0();
  *unaff_FS_OFFSET = iVar8;
  return;
}


/* ==================================================================== */
/* Address: 0x0058e7e0 | Classified: elementclient::Action@0x58e7e0 */
/* ==================================================================== */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1
FUN_0058e7e0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,char param_5,
            undefined4 param_6,undefined4 param_7,undefined *param_8,int *param_9,int *param_10,
            int *param_11,int *param_12,int *param_13,undefined *param_14,undefined4 param_15,
            undefined4 param_16,undefined4 param_17,undefined *param_18,undefined4 param_19,
            undefined *param_20,undefined4 param_21,undefined *param_22,undefined4 param_23,
            undefined *param_24,undefined *param_25,undefined *param_26,undefined4 param_27,
            undefined *param_28,int *param_29,undefined *param_30,int *param_31,int *param_32,
            int *param_33,undefined4 param_34,undefined4 param_35,undefined4 param_36,int param_37,
            undefined4 param_38,undefined4 param_39)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  int *piVar8;
  int *extraout_ECX;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int *extraout_ECX_00;
  int iVar13;
  int *piVar14;
  int *piVar15;
  int iVar16;
  int *piVar17;
  code *pcVar18;
  char *pcVar19;
  char *pcVar20;
  char *pcVar21;
  int *piVar22;
  undefined4 *unaff_FS_OFFSET;
  undefined4 in_stack_00000100;
  undefined4 in_stack_00000118;
  undefined2 in_stack_0000011c;
  undefined1 uStack0000011e;
  undefined4 in_stack_00000140;
  undefined2 in_stack_00000144;
  undefined4 in_stack_00000168;
  undefined1 in_stack_0000016c;
  undefined4 in_stack_00000190;
  undefined2 in_stack_00000194;
  undefined4 in_stack_000001b8;
  undefined4 in_stack_000001bc;
  undefined1 in_stack_000001c0;
  undefined4 in_stack_000001e0;
  undefined2 in_stack_000001e4;
  undefined4 in_stack_000027b0;
  int iStack_48;
  int *piStack_40;
  int *piStack_3c;
  undefined **ppuStack_38;
  int *piStack_34;
  int *piStack_30;
  undefined1 *puStack_2c;
  undefined4 *puStack_28;
  int *piStack_24;
  undefined4 *puStack_20;
  undefined4 *puStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  puStack_c = (undefined4 *)*unaff_FS_OFFSET;
  puStack_8 = &UNK_008b59eb;
  *unaff_FS_OFFSET = &puStack_c;
  func_0x00892f20();
  puStack_20 = (undefined4 *)0x58e815;
  func_0x0076d760();
  piVar15 = (int *)0x0;
  puStack_20 = (undefined4 *)0x58e82b;
  iVar3 = func_0x00437450();
  param_8 = *(undefined **)(iVar3 + 4);
  param_9 = (int *)CONCAT13(param_9._3_1_,*(undefined3 *)(iVar3 + 8));
  param_10 = *(int **)(iVar3 + 0xc);
  param_11 = *(int **)(iVar3 + 0x10);
  param_13 = (int *)0x0;
  param_14 = (undefined *)0x0;
  param_15 = 0;
  param_12 = (int *)&UNK_008d6c34;
  piStack_24 = *(int **)(iVar3 + 0x18);
  puStack_20 = (undefined4 *)(*(int *)(iVar3 + 0x1c) - (int)piStack_24);
  if (puStack_20 != (undefined4 *)0x0) {
    puStack_28 = (undefined4 *)0x58e888;
    func_0x00432ad0();
  }
  puStack_20 = (undefined4 *)(iVar3 + 0x24);
  piStack_24 = (int *)0x58e895;
  func_0x00432800();
  piStack_24 = (int *)(iVar3 + 0x34);
  puStack_28 = (undefined4 *)0x58e8aa;
  func_0x00439ed0();
  param_22 = (undefined *)CONCAT31(param_22._1_3_,*(undefined1 *)(iVar3 + 0x44));
  param_23 = *(undefined4 *)(iVar3 + 0x48);
  param_24 = *(undefined **)(iVar3 + 0x4c);
  param_25 = *(undefined **)(iVar3 + 0x50);
  param_26 = *(undefined **)(iVar3 + 0x54);
  param_27 = *(undefined4 *)(iVar3 + 0x58);
  param_28 = *(undefined **)(iVar3 + 0x5c);
  param_29 = *(int **)(iVar3 + 0x60);
  puStack_28 = (undefined4 *)(iVar3 + 100);
  puStack_2c = (undefined1 *)0x58e907;
  func_0x00432800();
  puStack_2c = (undefined1 *)(iVar3 + 0x74);
  piStack_30 = (int *)0x58e917;
  func_0x00432800();
  param_36 = *(undefined4 *)(iVar3 + 0x84);
  param_37 = *(int *)(iVar3 + 0x88);
  in_stack_00000118 = _DAT_0096fc04;
  in_stack_0000011c = _DAT_0096fc08;
  uStack0000011e = DAT_0096fc0a;
  puVar5 = (undefined4 *)&stack0x0000011f;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined1 *)puVar5 = 0;
  in_stack_00000144 = _DAT_0096fbf8;
  in_stack_00000140 = _DAT_0096fbf4;
  puVar5 = (undefined4 *)&stack0x00000146;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = 0;
  in_stack_0000016c = DAT_0096fc00;
  in_stack_00000168 = _DAT_0096fbfc;
  puVar5 = (undefined4 *)&stack0x0000016d;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = 0;
  *(undefined1 *)((int)puVar5 + 2) = 0;
  in_stack_00000190 = _DAT_0096fbec;
  in_stack_00000194 = _DAT_0096fbf0;
  puVar5 = (undefined4 *)&stack0x00000196;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = 0;
  in_stack_000001b8 = _DAT_0096fbe0;
  in_stack_000001bc = _DAT_0096fbe4;
  in_stack_000001c0 = DAT_0096fbe8;
  puVar5 = (undefined4 *)&stack0x000001c1;
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = 0;
  *(undefined1 *)((int)puVar5 + 2) = 0;
  in_stack_000001e4 = _DAT_0096fbd8;
  in_stack_000001e0 = _DAT_0096fbd4;
  puVar5 = (undefined4 *)&stack0x000001e6;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = 0;
  puVar5 = (undefined4 *)&stack0x0000020c;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  puVar5 = (undefined4 *)&stack0x00000234;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  puVar5 = (undefined4 *)&stack0x0000025e;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = 0;
  puVar5 = (undefined4 *)&stack0x00000289;
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = 0;
  *(undefined1 *)((int)puVar5 + 2) = 0;
  puVar5 = (undefined4 *)&stack0x000002ab;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined1 *)puVar5 = 0;
  pcVar19 = (char *)0x96fbb4;
  if (param_5 != '\0') {
    pcVar19 = (char *)0x96fbb0;
  }
  uVar9 = 0xffffffff;
  do {
    pcVar21 = pcVar19;
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    pcVar21 = pcVar19 + 1;
    cVar1 = *pcVar19;
    pcVar19 = pcVar21;
  } while (cVar1 != '\0');
  uVar9 = ~uVar9;
  iVar3 = -1;
  pcVar19 = (char *)&stack0x00000168;
  do {
    pcVar20 = pcVar19;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar20 = pcVar19 + 1;
    cVar1 = *pcVar19;
    pcVar19 = pcVar20;
  } while (cVar1 != '\0');
  pcVar19 = pcVar21 + -uVar9;
  pcVar21 = pcVar20 + -1;
  for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined4 *)pcVar21 = *(undefined4 *)pcVar19;
    pcVar19 = pcVar19 + 4;
    pcVar21 = pcVar21 + 4;
  }
  puStack_c = &stack0x00000118;
  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *pcVar21 = *pcVar19;
    pcVar19 = pcVar19 + 1;
    pcVar21 = pcVar21 + 1;
  }
  do {
    piStack_30 = puStack_c;
    piStack_34 = (int *)0x58eb9c;
    piStack_34 = (int *)func_0x0076eb20();
    piStack_3c = (int *)&stack0x00000688;
    ppuStack_38 = (undefined **)0x96fb8c;
    piStack_40 = (int *)0x58ebb0;
    sprintf();
    piStack_34 = (int *)&stack0x00000688;
    piStack_30 = (int *)0x9;
    ppuStack_38 = (undefined **)0x58ebc9;
    cVar1 = func_0x0076da20();
    if (cVar1 == '\0') {
      ppuStack_38 = (undefined **)0x96f9e4;
      piStack_3c = (int *)0x1c4;
      piStack_40 = (int *)0x58ef91;
      uVar2 = func_0x007396e0();
      pcVar18 = free_exref;
      piStack_40 = param_31;
      param_30 = &UNK_008d6c34;
      free();
      param_26 = &UNK_008d6c34;
      free();
      goto LAB_0058efd3;
    }
    ppuStack_38 = &puStack_8;
    piStack_40 = (int *)&stack0x00000784;
    piStack_3c = (int *)0x800;
    func_0x0076dd10();
    param_39 = atoi();
    func_0x0076dd10();
    param_35 = atoi();
    func_0x0076dd10();
    iVar3 = atoi();
    *(int *)(&stack0x000002fc + (int)piVar15) = iVar3;
    func_0x0076dd10();
    puVar4 = (undefined *)atoi();
    *(undefined **)(&stack0x000002c4 + (int)piVar15) = puVar4;
    param_25 = puVar4;
    param_31 = (int *)func_0x00763250();
    if (param_31 == (int *)0x0) {
      param_31 = (int *)0x0;
    }
    else {
      param_28 = (undefined *)((int)puVar4 * iVar3 + -1);
    }
    *(int **)(&stack0x00000298 + (int)piVar15) = param_31;
    if (param_31 == (int *)0x0) {
      uVar2 = func_0x007396e0();
      param_18 = &UNK_008d6c34;
      free();
      param_14 = &UNK_008d6c34;
      free();
      func_0x0059b000();
      func_0x005ca820();
      puStack_8 = &UNK_008d6c34;
      free();
      free();
      goto LAB_0058fa0e;
    }
    piStack_3c = (int *)0x0;
    if (0 < iVar3) {
      iStack_48 = 0;
      do {
        param_24 = (undefined *)0x0;
        if (0 < (int)puVar4) {
          iVar16 = (int)param_25 * (int)piStack_3c;
          param_28 = (undefined *)(iStack_48 + (int)param_29);
          iVar3 = 0;
          piVar15 = param_31 + iVar16 * 4;
          do {
            piVar15[1] = iStack_48;
            piVar15[2] = iVar3 + (int)param_30;
            piVar15[3] = (int)param_28;
            *piVar15 = iVar3;
            func_0x0076dd10();
            if (ppuStack_38 != (undefined **)0x0) {
              iVar11 = -1;
              pcVar19 = &stack0x00000754;
              do {
                if (iVar11 == 0) break;
                iVar11 = iVar11 + -1;
                cVar1 = *pcVar19;
                pcVar19 = pcVar19 + 1;
              } while (cVar1 != '\0');
              if (iVar11 != -2) {
                func_0x007636b0();
                func_0x00763660();
                param_25 = (undefined *)0x0;
                iVar11 = func_0x004c4e00();
                func_0x007637f0();
                *(int *)(iVar11 + 4) = (int)param_20 + iVar16;
                func_0x007637f0();
              }
            }
            param_24 = (undefined *)((int)param_24 + 1);
            piVar15 = piVar15 + 4;
            iVar3 = iVar3 + (int)param_30;
          } while ((int)param_24 < (int)param_25);
        }
        piStack_3c = (int *)((int)piStack_3c + 1);
        iStack_48 = iStack_48 + (int)param_29;
        piVar15 = piStack_34;
        puVar4 = param_25;
      } while ((int)piStack_3c < 0x800);
    }
    func_0x0076db10();
    iVar3 = func_0x00763250();
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = func_0x0078bd00();
    }
    if (iVar3 == 0) {
      uVar2 = func_0x007396e0();
      param_18 = &UNK_008d6c34;
      free();
      param_14 = &UNK_008d6c34;
      free();
      func_0x0059b000();
      func_0x005ca820();
      puStack_8 = &UNK_008d6c34;
      free();
      free();
      goto LAB_0058fa0e;
    }
    sprintf();
    cVar1 = func_0x0078c020();
    if (cVar1 == '\0') {
      piStack_30 = (int *)0x96f9e4;
      piStack_34 = (int *)0x1e9;
      ppuStack_38 = (undefined **)0x58f10b;
      uVar2 = func_0x007396e0();
      pcVar18 = free_exref;
      ppuStack_38 = (undefined **)param_33;
      param_32 = (int *)&UNK_008d6c34;
      piStack_3c = (int *)0x58f129;
      free();
      param_28 = &UNK_008d6c34;
      piStack_3c = param_29;
      piStack_40 = (int *)0x58f13a;
      free();
      goto LAB_0058efd3;
    }
    piVar15 = piVar15 + 1;
    puStack_c = puStack_c + 10;
  } while ((int)piVar15 < 0x2c);
  iVar3 = 0;
  do {
    piVar15 = *(int **)(&stack0x000002d0 + iVar3);
    piStack_34 = (int *)(*(int *)(&stack0x000002fc + iVar3) * *(int *)(&stack0x00000328 + iVar3));
    ppuStack_38 = (undefined **)0x58ef61;
    piStack_30 = piVar15;
    cVar1 = func_0x0078c600();
    if (cVar1 == '\0') {
      ppuStack_38 = (undefined **)0x96f9e4;
      piStack_3c = (int *)0x1f0;
      piStack_40 = (int *)0x58f161;
      uVar2 = func_0x007396e0();
      pcVar18 = free_exref;
      piStack_40 = param_31;
      param_30 = &UNK_008d6c34;
      free();
      param_26 = &UNK_008d6c34;
      free();
      goto LAB_0058efd3;
    }
    piStack_3c = (int *)0x58ef6f;
    ppuStack_38 = (undefined **)piVar15;
    func_0x00763260();
    iVar3 = iVar3 + 4;
  } while (iVar3 < 0x2c);
  piStack_30 = (int *)0x8c;
  piStack_34 = (int *)0x58f1b2;
  iVar3 = func_0x00763250();
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    piStack_30 = (int *)0x58f1cc;
    iVar3 = func_0x0078bd00();
  }
  *(int *)(param_2 + 0x434) = iVar3;
  if (iVar3 == 0) {
    piStack_30 = (int *)0x96f9e4;
    piStack_34 = (int *)0x1f6;
    ppuStack_38 = (undefined **)0x58f1f1;
    uVar2 = func_0x007396e0();
    ppuStack_38 = (undefined **)param_33;
    param_32 = (int *)&UNK_008d6c34;
    piStack_3c = (int *)0x58f20f;
    free();
    param_28 = &UNK_008d6c34;
    piStack_3c = param_29;
    piStack_40 = (int *)0x58f220;
    free();
    piStack_30 = (int *)0x58f23c;
    func_0x0059b000();
    piStack_30 = (int *)0x58f245;
    func_0x005ca820();
    param_12 = (int *)&UNK_008d6c34;
    piStack_30 = param_13;
    piStack_34 = (int *)0x58f250;
    free();
    param_8 = &UNK_008d6c34;
    piStack_34 = param_9;
    ppuStack_38 = (undefined **)0x58f25b;
    free();
  }
  else {
    ppuStack_38 = *(undefined ***)(param_2 + 8);
    piStack_30 = (int *)0xffff00ff;
    piStack_34 = (int *)0x96fb58;
    piStack_3c = (int *)0x58f275;
    cVar1 = func_0x0078c020();
    if (cVar1 != '\0') {
      piVar15 = (int *)(param_2 + 0x588);
      iVar3 = 0;
LAB_0058f2e1:
      piStack_40 = (int *)0x96fb40;
      piStack_3c = (int *)iVar3;
      sprintf();
      puStack_28 = (undefined4 *)func_0x00763250();
      if (puStack_28 == (undefined4 *)0x0) {
        iVar16 = 0;
      }
      else {
        piStack_3c = (int *)0x58f31d;
        iVar16 = func_0x0078bd00();
      }
      *piVar15 = iVar16;
      if (iVar16 == 0) {
        piStack_3c = (int *)0x96f9e4;
        piStack_40 = (int *)0x202;
        uVar2 = func_0x007396e0();
        param_29 = (int *)&UNK_008d6c34;
        free();
        param_25 = &UNK_008d6c34;
        free();
        puStack_28 = &param_13;
        piStack_3c = (int *)0x58f8bd;
        func_0x0059b000();
        piStack_3c = (int *)0x58f8c6;
        func_0x005ca820();
        param_9 = (int *)&UNK_008d6c34;
        piStack_3c = param_10;
        piStack_40 = (int *)0x58f8d1;
        free();
        piStack_40 = extraout_ECX;
        free();
        goto LAB_0058fa0e;
      }
      piStack_40 = (int *)&stack0x00000578;
      piStack_3c = (int *)0xffff00ff;
      cVar1 = func_0x0078c020();
      if (cVar1 != '\0') {
        piStack_3c = (int *)0x10;
        piStack_40 = (int *)0x58f362;
        puVar5 = (undefined4 *)func_0x00763250();
        if (puVar5 == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          puVar5[2] = 0;
          puVar5[3] = 0;
          *puVar5 = 0;
          puVar5[1] = 0;
        }
        piVar15[10] = (int)puVar5;
        if (puVar5 != (undefined4 *)0x0) {
          iVar16 = *(int *)(*piVar15 + 0x34);
          iVar11 = *(int *)(*piVar15 + 0x38);
          iVar11 = (int)(iVar11 + (iVar11 >> 0x1f & 0x1fU)) >> 5;
          iVar16 = (int)(iVar16 + (iVar16 >> 0x1f & 0x1fU)) >> 5;
          piVar17 = (int *)(iVar11 * iVar16);
          piStack_3c = (int *)((int)piVar17 * 0x10);
          piStack_40 = (int *)0x58f3bb;
          piVar6 = (int *)func_0x00763250();
          piStack_3c = (int *)0x0;
          if (piVar6 != (int *)0x0) {
            puStack_28 = (undefined4 *)((int)piVar17 + -1);
            piStack_3c = piVar6;
          }
          if (0 < iVar11) {
            iVar13 = 0;
            puStack_28 = (undefined4 *)(iVar16 * 0x10);
            piVar6 = piStack_3c + 2;
            puStack_20 = (undefined4 *)iVar11;
            do {
              if (0 < iVar16) {
                iVar12 = 0;
                piVar8 = piVar6;
                iVar11 = iVar16;
                do {
                  piVar8[-2] = iVar12;
                  iVar12 = iVar12 + 0x20;
                  piVar8[-1] = iVar13;
                  *piVar8 = iVar12;
                  piVar8[1] = iVar13 + 0x20;
                  piVar8 = piVar8 + 4;
                  iVar11 = iVar11 + -1;
                } while (iVar11 != 0);
              }
              iVar13 = iVar13 + 0x20;
              piVar6 = piVar6 + iVar16 * 4;
              puStack_20 = (undefined4 *)((int)puStack_20 + -1);
            } while (puStack_20 != (undefined4 *)0x0);
            puStack_20 = (undefined4 *)0x0;
          }
          piStack_40 = piVar17;
          piStack_24 = piStack_3c;
          func_0x0078c600();
          func_0x00763260();
          func_0x0076ded0();
          in_stack_00000100 = _DAT_00985a98;
          sprintf();
          cVar1 = func_0x0076e030();
          if (cVar1 != '\0') goto code_r0x0058f491;
          uVar2 = func_0x007396e0();
          FUN_00765200();
          func_0x0076df10();
          param_26 = &UNK_008d6c34;
          free();
          param_22 = &UNK_008d6c34;
          free();
          piVar6 = param_12;
          piStack_34 = (int *)&param_10;
          puStack_20 = &param_11;
          for (piVar15 = param_11; piVar15 != piVar6; piVar15 = piVar15 + 0xe) {
            (**(code **)(*piVar15 + 8))();
          }
          func_0x0043a550();
          func_0x005ca820();
          free();
          free();
          goto LAB_0058fa0e;
        }
        piStack_3c = (int *)0x96f9e4;
        piStack_40 = (int *)0x206;
        uVar2 = func_0x007396e0();
        pcVar18 = free_exref;
        param_29 = (int *)&UNK_008d6c34;
        free();
        param_25 = &UNK_008d6c34;
        free();
        goto LAB_0058efd3;
      }
      goto LAB_0058f700;
    }
    piStack_3c = (int *)0x96f9e4;
    piStack_40 = (int *)0x1fa;
    uVar2 = func_0x007396e0();
    pcVar18 = free_exref;
    param_29 = (int *)&UNK_008d6c34;
    free();
    param_25 = &UNK_008d6c34;
    free();
LAB_0058efd3:
    piStack_24 = (int *)&param_14;
    ppuStack_38 = (undefined **)0x58efdc;
    func_0x0059b000();
    ppuStack_38 = (undefined **)0x58efe5;
    func_0x005ca820();
    param_10 = (int *)&UNK_008d6c34;
    ppuStack_38 = (undefined **)param_11;
    piStack_3c = (int *)0x58eff0;
    (*pcVar18)();
    piStack_3c = (int *)&UNK_008d6c18;
    piStack_40 = (int *)0x58effb;
    (*pcVar18)();
  }
LAB_0058fa0e:
  ppuStack_38 = (undefined **)0x58fa30;
  func_0x0076d7c0();
LAB_0058fb78:
  *unaff_FS_OFFSET = in_stack_000027b0;
  return uVar2;
code_r0x0058f491:
  cVar1 = func_0x0076e120();
  while (cVar1 != '\0') {
    param_39 = _wtoi();
    func_0x0076e120();
    param_39 = _wtoi();
    func_0x0076e120();
    FUN_00765230();
    iVar16 = 0;
    if (0 < param_37) {
      puVar5 = &param_39;
      do {
        func_0x0076e120();
        uVar7 = _wtoi();
        *puVar5 = uVar7;
        iVar16 = iVar16 + 1;
        puVar5 = puVar5 + 1;
      } while (iVar16 < param_37);
    }
    piVar6 = *(int **)((int)ppuStack_38 + 0x28);
    uVar9 = piVar6[3];
    piStack_30 = piVar6;
    if (uVar9 == piVar6[2]) {
      if (uVar9 + 1 < 5) {
        piStack_40 = (int *)0x5;
      }
      else {
        piStack_40 = (int *)(uVar9 + 3 + (uVar9 >> 1));
      }
      piVar8 = (int *)func_0x00763250();
      piStack_24 = (int *)0x0;
      piVar17 = (int *)*piVar6;
      piStack_3c = piVar8;
      if (piVar6[3] != 0) {
        do {
          param_32 = piStack_3c;
          param_33 = piStack_3c;
          piVar14 = piVar17;
          piVar22 = piStack_3c + 0x18;
          if (piStack_3c != (int *)0x0) {
            piVar14 = piVar17 + 0x18;
            *piStack_3c = *piVar17;
            piStack_3c[1] = piVar17[1];
            piStack_3c[2] = piVar17[2];
            piVar17 = piVar17 + 3;
            piVar22 = piStack_3c + 3;
            for (iVar16 = 0x14; iVar16 != 0; iVar16 = iVar16 + -1) {
              *piVar22 = *piVar17;
              piVar17 = piVar17 + 1;
              piVar22 = piVar22 + 1;
            }
            piStack_3c = piStack_3c + 0x18;
            FUN_00765000();
            piVar22 = piStack_3c;
          }
          piStack_3c = piVar22;
          piStack_24 = (int *)((int)piStack_24 + 1);
          piVar17 = piVar14;
        } while (piStack_24 < (int *)piVar6[3]);
      }
      uVar9 = 0;
      if (piVar6[3] != 0) {
        do {
          FUN_00765200();
          uVar9 = uVar9 + 1;
        } while (uVar9 < (uint)piVar6[3]);
      }
      if (*piVar6 != 0) {
        func_0x00763260();
      }
      *piVar6 = (int)piVar8;
      piVar6[2] = (int)piStack_40;
      piVar6[1] = (int)(piVar8 + piVar6[3] * 0x18);
    }
    if (piVar6[1] != 0) {
      func_0x0059b530();
    }
    piVar6[3] = piVar6[3] + 1;
    piVar6[1] = piVar6[1] + 0x60;
    cVar1 = func_0x0076e120();
  }
  func_0x0076e0f0();
  FUN_00765200();
  func_0x0076df10();
  iVar3 = iVar3 + 1;
  piVar15 = piVar15 + 1;
  if (9 < iVar3) goto LAB_0058f700;
  goto LAB_0058f2e1;
LAB_0058f700:
  iVar3 = iStack_4;
  piStack_3c = (int *)0x95df94;
  piStack_40 = (int *)0x58f710;
  FUN_0072fb20();
  puStack_2c = (undefined1 *)&piStack_40;
  piStack_40 = extraout_ECX_00;
  func_0x007636b0();
  FUN_00738090();
  func_0x0076f270();
  cVar1 = func_0x0076f390();
  if (cVar1 != '\0') {
    piStack_24 = _DAT_009858e4;
    cVar1 = func_0x0076f4a0();
    while (cVar1 != '\0') {
      piStack_3c = (int *)atoi();
      func_0x0076f4a0();
      func_0x007638a0();
      piStack_40 = _DAT_009858e4;
      param_29 = (int *)&DAT_009b3c44;
      func_0x00763660();
      func_0x0059b610();
      uVar9 = 0x96fb08 % *(uint *)(iVar3 + 0x478);
      for (puVar5 = *(undefined4 **)(*(int *)(iVar3 + 0x46c) + uVar9 * 4);
          puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {
        if (puVar5[3] == 0x96fb08) goto LAB_0058fa46;
      }
      piStack_3c = (int *)func_0x00763250();
      if (piStack_3c == (int *)0x0) {
        uVar7 = 0;
      }
      else {
        uVar7 = func_0x0059b590();
      }
      *(undefined4 *)(*(int *)(iVar3 + 0x46c) + uVar9 * 4) = uVar7;
      *(int *)(iVar3 + 0x468) = *(int *)(iVar3 + 0x468) + 1;
LAB_0058fa46:
      func_0x007637f0();
      func_0x007637f0();
      func_0x00763940();
      cVar1 = func_0x0076f4a0();
    }
    func_0x0076f450();
    func_0x007637f0();
  }
  func_0x0076f2b0();
  param_24 = &UNK_008d6c34;
  free();
  param_20 = &UNK_008d6c34;
  free();
  piVar6 = param_10;
  piStack_3c = (int *)&param_8;
  puStack_28 = &param_9;
  for (piVar15 = param_9; piVar15 != piVar6; piVar15 = piVar15 + 0xe) {
    (**(code **)(*piVar15 + 8))();
  }
  func_0x0043a550();
  param_8 = &UNK_008d6c3c;
  free();
  free();
  func_0x0076d7c0();
  uVar2 = 1;
  goto LAB_0058fb78;
}


/* ==================================================================== */
/* Address: 0x0058fba0 | Classified: ElementClient::proc_58fba0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0058fba0(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x5c) + -0xc);
  if (*piVar1 == -1) {
    *piVar1 = 1;
  }
  func_0x00764e30(piVar1);
  *(int *)(param_1 + 0x5c) = _DAT_00985a98;
  return;
}


/* ==================================================================== */
/* Address: 0x00590c50 | Classified: ElementClient::proc_590c50 */
/* ==================================================================== */

uint __thiscall FUN_00590c50(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = FUN_00735df0();
  if (((char)uVar1 != '\0') &&
     ((uVar1 = *(uint *)(param_1 + 0x18), uVar1 == 0 || (uVar1 == *(uint *)(param_1 + 0x2ac))))) {
    uVar1 = func_0x0052eaf0(param_2,param_3,param_4);
    return uVar1;
  }
  return uVar1 & 0xffffff00;
}


/* ==================================================================== */
/* Address: 0x00590ca0 | Classified: CECGameUIMan::vfunc_slot_5 */
/* ==================================================================== */

undefined4 FUN_00590ca0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  cVar1 = FUN_0072fcd0(param_1,param_2);
  if (cVar1 != '\0') {
    return 1;
  }
  uVar2 = FUN_007359b0(0x96fcac);
  iVar3 = _stricmp(uVar2);
  if (iVar3 != 0) {
    uVar2 = FUN_007359b0(0x96fc9c);
    iVar3 = _stricmp(uVar2);
    if (iVar3 != 0) {
      uVar2 = FUN_007359b0(0x96edf0);
      iVar3 = _stricmp(uVar2);
      if (iVar3 != 0) {
        uVar2 = FUN_007359b0(0x96ee34);
        iVar3 = _stricmp(uVar2);
        if (iVar3 != 0) {
          uVar2 = FUN_007359b0(0x96ee20);
          iVar3 = _stricmp(uVar2);
          if (iVar3 != 0) {
            uVar2 = FUN_007359b0(0x96ee44);
            iVar3 = _stricmp(uVar2);
            if (iVar3 != 0) {
              uVar2 = FUN_007359b0(0x96edcc);
              iVar3 = _stricmp(uVar2);
              if (iVar3 != 0) {
                uVar2 = FUN_007359b0(0x96ee00);
                iVar3 = _stricmp(uVar2);
                if (iVar3 != 0) {
                  uVar2 = FUN_007359b0(0x96ee10);
                  iVar3 = _stricmp(uVar2);
                  if (iVar3 != 0) {
                    uVar2 = FUN_007359b0(0x96ecc8);
                    iVar3 = _stricmp(uVar2);
                    if (iVar3 != 0) {
                      uVar2 = FUN_007359b0(0x96eda0);
                      iVar3 = _stricmp(uVar2);
                      if (iVar3 != 0) {
                        uVar2 = FUN_007359b0(0x96edb8);
                        iVar3 = _stricmp(uVar2);
                        if (iVar3 != 0) {
                          uVar2 = FUN_007359b0(0x96eddc);
                          iVar3 = _stricmp(uVar2);
                          if (iVar3 != 0) {
                            uVar2 = FUN_007359b0(0x96c93c);
                            iVar3 = _stricmp(uVar2);
                            if (iVar3 != 0) {
                              uVar2 = FUN_007359b0(0x96fc8c);
                              iVar3 = _stricmp(uVar2);
                              if (iVar3 != 0) {
                                uVar2 = FUN_007359b0(0x96fc80);
                                iVar3 = _stricmp(uVar2);
                                if (iVar3 != 0) {
                                  uVar2 = FUN_007359b0(0x96fc6c);
                                  iVar3 = _stricmp(uVar2);
                                  if (iVar3 != 0) {
                                    uVar2 = FUN_007359b0(0x96fc5c);
                                    iVar3 = _stricmp(uVar2);
                                    if (iVar3 != 0) {
                                      uVar2 = FUN_007359b0(0x96fc50);
                                      iVar3 = _stricmp(uVar2);
                                      if (iVar3 != 0) {
                                        uVar2 = FUN_007359b0(0x96fc44);
                                        iVar3 = _stricmp(uVar2);
                                        if (iVar3 != 0) {
                                          uVar2 = FUN_007359b0(0x96fc38);
                                          iVar3 = _stricmp(uVar2);
                                          if (iVar3 != 0) {
                                            uVar2 = FUN_007359b0(0x96fc2c);
                                            iVar3 = _stricmp(uVar2);
                                            if (iVar3 != 0) {
                                              iVar3 = _stricmp(param_1,0x95baec);
                                              if (iVar3 == 0) {
                                                FUN_00735c50(0,0,1);
                                                return 1;
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
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x00590f20 | Classified: CECGameUIMan::vfunc_slot_6 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_00590f20(undefined4 *****param_1,undefined4 *****param_2,undefined4 ****param_3)

{
  undefined4 ****ppppuVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 *****pppppuVar5;
  uint uVar6;
  undefined4 *****pppppuVar7;
  undefined4 ****ppppuVar8;
  undefined4 *puVar9;
  undefined4 *****pppppuVar10;
  int *piVar11;
  undefined4 uVar12;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 *****extraout_ECX_02;
  undefined4 *****extraout_ECX_03;
  undefined4 *****extraout_ECX_04;
  undefined4 *****extraout_ECX_05;
  undefined4 *****extraout_ECX_06;
  undefined4 *****extraout_ECX_07;
  undefined4 *****extraout_ECX_08;
  undefined4 *****extraout_ECX_09;
  undefined4 *****extraout_ECX_10;
  undefined4 *****extraout_ECX_11;
  undefined4 *****extraout_ECX_12;
  undefined4 *****extraout_ECX_13;
  undefined4 *****extraout_ECX_14;
  undefined4 ****extraout_ECX_15;
  undefined4 *****extraout_ECX_16;
  undefined4 ****extraout_ECX_17;
  undefined4 *****extraout_ECX_18;
  undefined4 extraout_ECX_19;
  undefined4 *****extraout_ECX_20;
  uint *puVar13;
  undefined4 *****pppppuVar14;
  undefined4 *****pppppuVar15;
  int iVar16;
  undefined4 *****pppppuVar17;
  undefined4 *unaff_FS_OFFSET;
  undefined8 uVar18;
  undefined4 ***pppuStack_17c;
  undefined *puStack_178;
  undefined4 ****ppppuStack_174;
  undefined4 ***pppuStack_170;
  undefined4 ****ppppuStack_16c;
  undefined4 ****ppppuStack_168;
  undefined4 ****ppppuStack_164;
  undefined4 ****ppppuStack_160;
  undefined4 ****ppppuStack_15c;
  undefined4 ****ppppuStack_158;
  undefined4 ****ppppuStack_144;
  undefined4 uStack_140;
  undefined4 ****ppppuStack_13c;
  undefined4 ****ppppuStack_138;
  undefined4 ***pppuStack_134;
  undefined4 uStack_130;
  undefined4 ****ppppuStack_12c;
  undefined4 ****ppppuStack_128;
  undefined4 ****ppppuStack_124;
  undefined4 uStack_120;
  undefined4 ****ppppuStack_11c;
  undefined4 **appuStack_110 [56];
  int iStack_30;
  undefined4 uStack_2c;
  undefined1 uStack_24;
  undefined1 uStack_1c;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  puStack_8 = &UNK_008b5aa5;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_140 = *(undefined4 ******)(_DAT_009b3eec + 0x20);
  ppppuStack_13c = *(undefined4 *****)(*(int *)(_DAT_009b3eec + 0x1c) + 0x20);
  ppppuStack_158 = (undefined4 ****)0x968a5c;
  ppppuStack_15c = (undefined4 ****)0x590f6e;
  uStack_130 = param_1;
  ppppuStack_15c = (undefined4 ****)FUN_007359b0();
  ppppuStack_160 = (undefined4 ****)0x590f77;
  iVar4 = _stricmp();
  if ((iVar4 == 0) && (param_2 == (undefined4 *****)0x6)) {
    ppppuStack_158 = (undefined4 ****)0x590f95;
    cVar2 = FUN_00735df0();
    if (cVar2 != '\0') {
      ppppuStack_158 = (undefined4 ****)&DAT_009b3c44;
      ppppuStack_15c = (undefined4 ****)0x590fa9;
      func_0x0052ef60();
    }
    if (*(char *)(uStack_140 + 0x4c) == '\0') {
LAB_00591abc:
      ppppuStack_158 = (undefined4 ****)0x2;
      ppppuStack_15c = (undefined4 ****)0x591acc;
      FUN_0074c2a0();
      pppppuVar5 = (undefined4 *****)ppppuStack_168;
    }
    else {
      ppppuStack_158 = (undefined4 ****)0x590fc9;
      func_0x00436d60();
      ppppuStack_158 = (undefined4 ****)0x1;
      ppppuStack_15c = (undefined4 ****)0x590fd0;
      func_0x005f0a10();
      pppppuVar5 = (undefined4 *****)ppppuStack_168;
    }
  }
  else {
    ppppuStack_158 = (undefined4 ****)0x96fd40;
    ppppuStack_15c = (undefined4 ****)0x590fe4;
    ppppuStack_15c = (undefined4 ****)FUN_007359b0();
    ppppuStack_160 = (undefined4 ****)0x590fe7;
    iVar4 = _stricmp();
    if (iVar4 == 0) {
      ppppuStack_144 = &ppppuStack_158;
      ppppuStack_15c = (undefined4 ****)&DAT_009b3c44;
      ppppuStack_160 = (undefined4 ****)0x590fff;
      func_0x007636b0();
      ppppuStack_160 = (undefined4 ****)0x591006;
      pppppuVar5 = (undefined4 *****)FUN_00738010();
      ppppuStack_164 = (undefined4 *****)0x9622f8;
      ppppuStack_168 = (undefined4 ****)0x591019;
      func_0x007636b0();
      ppppuStack_168 = (undefined4 ****)0x591020;
      ppppuStack_168 = (undefined4 ****)FUN_007380f0();
      if (param_2 == (undefined4 *****)0x6) {
        pppuStack_170 = (undefined4 ****)0x59102c;
        ppppuStack_16c = pppppuVar5;
        func_0x005f19e0();
        pppppuVar5 = (undefined4 *****)ppppuStack_168;
      }
      else {
        ppppuStack_16c = (undefined4 *****)0x59103a;
        ppppuStack_168 = pppppuVar5;
        func_0x005f1a20();
        pppppuVar5 = (undefined4 *****)ppppuStack_168;
      }
    }
    else {
      ppppuStack_158 = (undefined4 ****)0x954654;
      ppppuStack_15c = (undefined4 ****)0x59104e;
      ppppuStack_15c = (undefined4 ****)FUN_007359b0();
      ppppuStack_160 = (undefined4 ****)0x591051;
      iVar4 = _stricmp();
      if (iVar4 == 0) {
        ppppuStack_144 = &ppppuStack_158;
        ppppuStack_15c = (undefined4 ****)&DAT_009b3c44;
        ppppuStack_160 = (undefined4 ****)0x591069;
        func_0x007636b0();
        ppppuStack_160 = (undefined4 ****)0x591070;
        ppppuStack_164 = (undefined4 ****)FUN_00738010();
        ppppuStack_160 =
             (undefined4 ****)
             CONCAT31((int3)((uint)extraout_ECX >> 8),param_2 == (undefined4 *****)0x6);
        ppppuStack_168 = (undefined4 *****)0x59107d;
        func_0x005f1c00();
        pppppuVar5 = (undefined4 *****)ppppuStack_168;
      }
      else {
        ppppuStack_158 = (undefined4 ****)0x96fd2c;
        ppppuStack_15c = (undefined4 ****)0x591091;
        ppppuStack_15c = (undefined4 ****)FUN_007359b0();
        ppppuStack_160 = (undefined4 ****)0x591094;
        iVar4 = _stricmp();
        if (iVar4 == 0) {
          ppppuStack_158 = (undefined4 ****)0x5910a6;
          cVar2 = FUN_00735df0();
          pppppuVar5 = (undefined4 *****)ppppuStack_168;
          if (cVar2 == '\0') {
            ppppuStack_144 = &ppppuStack_158;
            ppppuStack_15c = (undefined4 ****)0x9622f8;
            ppppuStack_160 = (undefined4 ****)0x5910bf;
            func_0x007636b0();
            ppppuStack_160 = (undefined4 ****)0x5910c6;
            uVar18 = FUN_007380f0();
            uStack_140 = (undefined4 *****)uVar18;
            ppppuStack_160 =
                 (undefined4 ****)CONCAT31((int3)((ulonglong)uVar18 >> 0x28),iStack_4 == 6);
            ppppuStack_164 = (undefined4 ****)&uStack_140;
            ppppuStack_168 = (undefined4 *****)0x5910e6;
            func_0x005e1070();
            pppppuVar5 = (undefined4 *****)ppppuStack_168;
          }
        }
        else {
          ppppuStack_158 = (undefined4 ****)0x96412c;
          ppppuStack_15c = (undefined4 ****)0x5910f7;
          ppppuStack_15c = (undefined4 ****)FUN_007359b0();
          ppppuStack_160 = (undefined4 ****)0x5910fa;
          iVar4 = _stricmp();
          if ((iVar4 == 0) && (param_2 == (undefined4 *****)0x1)) {
            ppppuStack_144 = &ppppuStack_158;
            ppppuStack_15c = (undefined4 ****)0x95ce0c;
            ppppuStack_160 = (undefined4 ****)0x59111f;
            func_0x007636b0();
            ppppuStack_160 = (undefined4 ****)0x591130;
            iVar4 = FUN_00742730();
            uVar12 = *(undefined4 *)(iVar4 + 8);
            ppppuStack_164 = (undefined4 ****)&DAT_009b3c44;
            ppppuStack_168 = (undefined4 ****)0x591144;
            func_0x007636b0();
            ppppuStack_168 = (undefined4 ****)0x591155;
            uVar6 = FUN_00742650();
            ppppuStack_16c = (undefined4 ****)(uVar6 & 0xffff);
            pppuStack_170 = (undefined4 ***)0x591161;
            ppppuStack_168 = (undefined4 ****)uVar12;
            func_0x005f2600();
            ppppuStack_168 = param_2;
            ppppuStack_16c = (undefined4 *****)0x0;
            pppuStack_170 = (undefined4 ****)0x0;
            ppppuStack_174 = (undefined4 ****)0x591174;
            FUN_00735c50();
            ppppuStack_174 = (undefined4 ****)0x59117f;
            func_0x00460c50();
            ppppuStack_174 = param_2;
            puStack_178 = (undefined *)0x0;
            pppuStack_17c = (undefined4 ****)0x0;
            param_1[0x178] = (undefined4 ****)0x0;
            FUN_00735c50();
            func_0x0045c1e0(0);
            func_0x0048c110();
            uVar12 = FUN_0072ef30(0xe4,0,0xa0ffffff,&ppppuStack_164);
            FUN_00730110(&DAT_009b3c44,uVar12);
            FUN_00738300(3);
            pppppuVar5 = (undefined4 *****)ppppuStack_168;
          }
          else {
            ppppuStack_158 = (undefined4 ****)0x9693ac;
            ppppuStack_15c = (undefined4 ****)0x5911ea;
            ppppuStack_15c = (undefined4 ****)FUN_007359b0();
            ppppuStack_160 = (undefined4 ****)0x5911ed;
            iVar4 = _stricmp();
            if ((iVar4 == 0) && (param_2 == (undefined4 *****)0x1)) {
              ppppuStack_144 = &ppppuStack_158;
              ppppuStack_15c = (undefined4 ****)0x95f96c;
              ppppuStack_160 = (undefined4 ****)0x591212;
              func_0x007636b0();
              ppppuStack_160 = (undefined4 ****)0x591219;
              iVar4 = FUN_007380f0();
              ppppuStack_160 = param_2;
              ppppuStack_164 = *(undefined4 *****)(iVar4 + 8);
              ppppuStack_168 = (undefined4 *****)0x591229;
              pppppuVar7 = (undefined4 *****)func_0x004618d0();
              if (pppppuVar7 == (undefined4 *****)0x0) {
                ppppuStack_158 = *(undefined4 *****)(iVar4 + 8);
                ppppuStack_15c = (undefined4 ****)0x591236;
                func_0x005f2650();
                pppppuVar5 = (undefined4 *****)ppppuStack_168;
              }
              else if (pppppuVar7 == (undefined4 *****)0x1) {
                ppppuStack_158 = (undefined4 ****)0x0;
                ppppuStack_15c = (undefined4 ****)0x0;
                ppppuStack_160 = (undefined4 ****)0x0;
                ppppuStack_164 = (undefined4 *****)0xffffffff;
                ppppuStack_168 = (undefined4 *****)0xa;
                ppppuStack_16c = (undefined4 *****)0x10e;
                pppuStack_170 = (undefined4 ***)0x591259;
                pppuStack_170 = (undefined4 ***)FUN_0072ef30();
                ppppuStack_174 = (undefined4 *****)0x591261;
                func_0x005941a0();
                pppppuVar5 = (undefined4 *****)ppppuStack_168;
              }
              else if (pppppuVar7 == (undefined4 *****)0x6) {
                ppppuStack_158 = (undefined4 ****)0x0;
                ppppuStack_15c = (undefined4 ****)0x0;
                ppppuStack_160 = (undefined4 ****)0x0;
                ppppuStack_164 = (undefined4 *****)0xffffffff;
                ppppuStack_168 = (undefined4 *****)0xa;
                ppppuStack_16c = (undefined4 *****)0x20f;
                pppuStack_170 = (undefined4 ***)0x591281;
                pppuStack_170 = (undefined4 ***)FUN_0072ef30();
                ppppuStack_174 = (undefined4 *****)0x591289;
                func_0x005941a0();
                pppppuVar5 = (undefined4 *****)ppppuStack_168;
              }
              else if (pppppuVar7 == (undefined4 *****)0x7) {
                ppppuStack_158 = (undefined4 ****)0x0;
                ppppuStack_15c = (undefined4 ****)0x0;
                ppppuStack_160 = (undefined4 ****)0x0;
                ppppuStack_164 = (undefined4 *****)0xffffffff;
                ppppuStack_168 = (undefined4 *****)0xa;
                ppppuStack_16c = (undefined4 *****)0x21d;
                pppuStack_170 = (undefined4 ***)0x5912a9;
                pppuStack_170 = (undefined4 ***)FUN_0072ef30();
                ppppuStack_174 = (undefined4 *****)0x5912b1;
                func_0x005941a0();
                pppppuVar5 = (undefined4 *****)ppppuStack_168;
              }
              else {
                pppppuVar5 = (undefined4 *****)ppppuStack_168;
                if (pppppuVar7 == (undefined4 *****)0x8) {
                  ppppuStack_158 = (undefined4 ****)0x0;
                  ppppuStack_15c = (undefined4 ****)0x0;
                  ppppuStack_160 = (undefined4 ****)0x0;
                  ppppuStack_164 = (undefined4 *****)0xffffffff;
                  ppppuStack_168 = (undefined4 *****)0xa;
                  ppppuStack_16c = (undefined4 *****)0x10f;
                  pppuStack_170 = (undefined4 ***)0x5912d1;
                  pppuStack_170 = (undefined4 ***)FUN_0072ef30();
                  ppppuStack_174 = (undefined4 *****)0x5912d9;
                  func_0x005941a0();
                  pppppuVar5 = (undefined4 *****)ppppuStack_168;
                }
                else {
joined_r0x00591419:
                  ppppuStack_168 = pppppuVar7;
                  if ((undefined4 *****)ppppuStack_168 == (undefined4 *****)0x9) {
                    ppppuStack_158 = (undefined4 ****)0x0;
                    ppppuStack_15c = (undefined4 ****)0x0;
                    ppppuStack_160 = (undefined4 ****)0x0;
                    ppppuStack_164 = (undefined4 *****)0xffffffff;
                    ppppuStack_168 = (undefined4 *****)0xa;
                    ppppuStack_16c = (undefined4 *****)0x22c;
                    pppuStack_170 = (undefined4 ***)0x591435;
                    pppuStack_170 = (undefined4 ***)FUN_0072ef30();
                    ppppuStack_174 = (undefined4 *****)0x59143d;
                    func_0x005941a0();
                    pppppuVar5 = (undefined4 *****)ppppuStack_168;
                  }
                  else if ((undefined4 *****)ppppuStack_168 == (undefined4 *****)0xa) {
                    ppppuStack_158 = (undefined4 ****)0x0;
                    ppppuStack_15c = (undefined4 ****)0x0;
                    ppppuStack_160 = (undefined4 ****)0x0;
                    ppppuStack_164 = (undefined4 *****)0xffffffff;
                    ppppuStack_16c = (undefined4 *****)0x22d;
                    pppuStack_170 = (undefined4 ***)0x591309;
                    pppuStack_170 = (undefined4 ***)FUN_0072ef30();
                    ppppuStack_174 = (undefined4 *****)0x591311;
                    func_0x005941a0();
                    pppppuVar5 = (undefined4 *****)ppppuStack_168;
                  }
                }
              }
            }
            else {
              ppppuStack_158 = (undefined4 ****)0x969398;
              ppppuStack_15c = (undefined4 ****)0x591322;
              ppppuStack_15c = (undefined4 ****)FUN_007359b0();
              ppppuStack_160 = (undefined4 ****)0x591325;
              iVar4 = _stricmp();
              if ((iVar4 == 0) && (param_2 == (undefined4 *****)0x1)) {
                ppppuStack_144 = &ppppuStack_158;
                ppppuStack_15c = (undefined4 ****)0x95f96c;
                ppppuStack_160 = (undefined4 ****)0x59134a;
                func_0x007636b0();
                ppppuStack_160 = (undefined4 ****)0x591351;
                iVar4 = FUN_007380f0();
                ppppuStack_160 = param_2;
                ppppuStack_164 = *(undefined4 *****)(iVar4 + 8);
                ppppuStack_168 = (undefined4 *****)0x591361;
                pppppuVar7 = (undefined4 *****)func_0x00461b30();
                if (pppppuVar7 == (undefined4 *****)0x0) {
                  ppppuStack_158 = *(undefined4 *****)(iVar4 + 8);
                  ppppuStack_15c = (undefined4 ****)0x59136e;
                  func_0x005f3030();
                  pppppuVar5 = (undefined4 *****)ppppuStack_168;
                }
                else if (pppppuVar7 == (undefined4 *****)0x1) {
                  ppppuStack_158 = (undefined4 ****)0x0;
                  ppppuStack_15c = (undefined4 ****)0x0;
                  ppppuStack_160 = (undefined4 ****)0x0;
                  ppppuStack_164 = (undefined4 *****)0xffffffff;
                  ppppuStack_168 = (undefined4 *****)0xa;
                  ppppuStack_16c = (undefined4 *****)0x10e;
                  pppuStack_170 = (undefined4 ***)0x591391;
                  pppuStack_170 = (undefined4 ***)FUN_0072ef30();
                  ppppuStack_174 = (undefined4 *****)0x591399;
                  func_0x005941a0();
                  pppppuVar5 = (undefined4 *****)ppppuStack_168;
                }
                else if (pppppuVar7 == (undefined4 *****)0x6) {
                  ppppuStack_158 = (undefined4 ****)0x0;
                  ppppuStack_15c = (undefined4 ****)0x0;
                  ppppuStack_160 = (undefined4 ****)0x0;
                  ppppuStack_164 = (undefined4 *****)0xffffffff;
                  ppppuStack_168 = (undefined4 *****)0xa;
                  ppppuStack_16c = (undefined4 *****)0x20f;
                  pppuStack_170 = (undefined4 ***)0x5913b9;
                  pppuStack_170 = (undefined4 ***)FUN_0072ef30();
                  ppppuStack_174 = (undefined4 *****)0x5913c1;
                  func_0x005941a0();
                  pppppuVar5 = (undefined4 *****)ppppuStack_168;
                }
                else if (pppppuVar7 == (undefined4 *****)0x7) {
                  ppppuStack_158 = (undefined4 ****)0x0;
                  ppppuStack_15c = (undefined4 ****)0x0;
                  ppppuStack_160 = (undefined4 ****)0x0;
                  ppppuStack_164 = (undefined4 *****)0xffffffff;
                  ppppuStack_168 = (undefined4 *****)0xa;
                  ppppuStack_16c = (undefined4 *****)0x21d;
                  pppuStack_170 = (undefined4 ***)0x5913e1;
                  pppuStack_170 = (undefined4 ***)FUN_0072ef30();
                  ppppuStack_174 = (undefined4 *****)0x5913e9;
                  func_0x005941a0();
                  pppppuVar5 = (undefined4 *****)ppppuStack_168;
                }
                else {
                  pppppuVar5 = (undefined4 *****)ppppuStack_168;
                  if (pppppuVar7 != (undefined4 *****)0x8) goto joined_r0x00591419;
                  ppppuStack_158 = (undefined4 ****)0x0;
                  ppppuStack_15c = (undefined4 ****)0x0;
                  ppppuStack_160 = (undefined4 ****)0x0;
                  ppppuStack_164 = (undefined4 *****)0xffffffff;
                  ppppuStack_168 = (undefined4 *****)0xa;
                  ppppuStack_16c = (undefined4 *****)0x10f;
                  pppuStack_170 = (undefined4 ***)0x591409;
                  pppuStack_170 = (undefined4 ***)FUN_0072ef30();
                  ppppuStack_174 = (undefined4 *****)0x591411;
                  func_0x005941a0();
                  pppppuVar5 = (undefined4 *****)ppppuStack_168;
                }
              }
              else {
                ppppuStack_158 = (undefined4 ****)0x960c1c;
                ppppuStack_15c = (undefined4 ****)0x59144e;
                ppppuStack_15c = (undefined4 ****)FUN_007359b0();
                ppppuStack_160 = (undefined4 ****)0x591451;
                ppppuStack_158 = (undefined4 ****)_stricmp();
                if ((ppppuStack_158 == (undefined4 ****)0x0) && (param_2 == (undefined4 *****)0x6))
                {
                  ppppuStack_15c = (undefined4 ****)0x591463;
                  func_0x005f21b0();
                  ppppuStack_158 = (undefined4 ****)0x1;
                  ppppuStack_15c = (undefined4 ****)0x0;
                  ppppuStack_160 = (undefined4 ****)0x0;
                  ppppuStack_164 = (undefined4 ****)0x591477;
                  FUN_00735c50();
                }
                else {
                  ppppuStack_158 = (undefined4 ****)0x960c30;
                  ppppuStack_15c = (undefined4 ****)0x591499;
                  ppppuStack_15c = (undefined4 ****)FUN_007359b0();
                  ppppuStack_160 = (undefined4 ****)0x59149c;
                  iVar4 = _stricmp();
                  if ((iVar4 != 0) || (param_2 != (undefined4 *****)0x6)) {
                    ppppuStack_158 = (undefined4 ****)0x95fc00;
                    ppppuStack_15c = (undefined4 ****)0x5914c0;
                    ppppuStack_15c = (undefined4 ****)FUN_007359b0();
                    ppppuStack_160 = (undefined4 ****)0x5914c3;
                    pppppuVar5 = (undefined4 *****)_stricmp();
                    if ((pppppuVar5 == (undefined4 *****)0x0) && (param_2 == (undefined4 *****)0x6))
                    {
                      ppppuStack_144 = &ppppuStack_158;
                      ppppuStack_15c = (undefined4 ****)&DAT_009b3c44;
                      ppppuStack_160 = (undefined4 ****)0x5914f4;
                      ppppuStack_12c = pppppuVar5;
                      ppppuStack_128 = pppppuVar5;
                      ppppuStack_124 = pppppuVar5;
                      uStack_120 = pppppuVar5;
                      ppppuStack_11c = pppppuVar5;
                      func_0x007636b0();
                      ppppuStack_160 = (undefined4 ****)0x5914fb;
                      iVar4 = FUN_00738010();
                      (&pppuStack_134)[iVar4] = (undefined4 ***)0x1;
                      ppppuStack_160 = ppppuStack_124;
                      ppppuStack_164 = ppppuStack_128;
                      ppppuStack_168 = ppppuStack_12c;
                      ppppuStack_16c = uStack_130;
                      pppuStack_170 = pppuStack_134;
                      ppppuStack_174 = (undefined4 *****)0x591521;
                      func_0x005f20d0();
                      pppppuVar5 = (undefined4 *****)ppppuStack_168;
                    }
                    else {
                      ppppuStack_158 = (undefined4 ****)0x96013c;
                      ppppuStack_15c = (undefined4 ****)0x591535;
                      ppppuStack_15c = (undefined4 ****)FUN_007359b0();
                      ppppuStack_160 = (undefined4 ****)0x591538;
                      iVar4 = _stricmp();
                      if ((iVar4 == 0) && (param_2 == (undefined4 *****)0x6)) {
                        ppppuStack_144 = &ppppuStack_158;
                        ppppuStack_15c = (undefined4 ****)0x95f96c;
                        ppppuStack_160 = (undefined4 ****)0x591555;
                        func_0x007636b0();
                        ppppuStack_160 = (undefined4 ****)0x59155c;
                        iVar4 = FUN_007380f0();
                        ppppuStack_164 = (undefined4 ****)&DAT_009b3c44;
                        ppppuStack_168 = (undefined4 ****)0x59156f;
                        func_0x007636b0();
                        ppppuStack_168 = (undefined4 ****)0x591576;
                        ppppuStack_16c = (undefined4 ****)FUN_00738010();
                        ppppuStack_168 = *(undefined4 *****)(iVar4 + 8);
                        pppuStack_170 = (undefined4 ****)0x591580;
                        func_0x005f3510();
                        pppppuVar5 = (undefined4 *****)ppppuStack_168;
                      }
                      else {
                        ppppuStack_158 = (undefined4 ****)0x9545e0;
                        ppppuStack_15c = (undefined4 ****)0x591594;
                        ppppuStack_15c = (undefined4 ****)FUN_007359b0();
                        ppppuStack_160 = (undefined4 ****)0x591597;
                        iVar4 = _stricmp();
                        if ((iVar4 == 0) && (param_2 == (undefined4 *****)0x1)) {
                          ppppuStack_158 = (undefined4 ****)0x5915a8;
                          func_0x005f1a60();
                          ppppuStack_158 = param_2;
                          ppppuStack_15c = (undefined4 ****)0x0;
                          ppppuStack_160 = (undefined4 ****)0x0;
                          ppppuStack_164 = (undefined4 *****)0x5915b8;
                          FUN_00735c50();
                          pppppuVar5 = (undefined4 *****)ppppuStack_168;
                        }
                        else {
                          ppppuStack_158 = (undefined4 ****)0x969120;
                          ppppuStack_15c = (undefined4 ****)0x5915c9;
                          ppppuStack_15c = (undefined4 ****)FUN_007359b0();
                          ppppuStack_160 = (undefined4 ****)0x5915cc;
                          iVar4 = _stricmp();
                          if ((iVar4 == 0) && (param_2 == (undefined4 *****)0x1)) {
                            ppppuStack_144 = &ppppuStack_158;
                            ppppuStack_15c = (undefined4 ****)&DAT_009b3c44;
                            ppppuStack_160 = (undefined4 ****)0x5915f3;
                            func_0x007636b0();
                            ppppuStack_160 = (undefined4 ****)0x5915fa;
                            ppppuStack_160 = (undefined4 ****)FUN_00738010();
                            ppppuStack_164 = (undefined4 *****)0x591602;
                            func_0x00682110();
                            pppppuVar5 = (undefined4 *****)ppppuStack_168;
                          }
                          else {
                            ppppuStack_158 = (undefined4 ****)0x967dd8;
                            ppppuStack_15c = (undefined4 ****)0x591613;
                            ppppuStack_15c = (undefined4 ****)FUN_007359b0();
                            ppppuStack_160 = (undefined4 ****)0x591616;
                            iVar4 = _stricmp();
                            if ((iVar4 == 0) && (param_2 == (undefined4 *****)0x1)) {
                              ppppuStack_158 = (undefined4 ****)0x591627;
                              func_0x005f24f0();
                              pppppuVar5 = (undefined4 *****)ppppuStack_168;
                            }
                            else {
                              ppppuStack_158 = (undefined4 ****)0x967dc8;
                              ppppuStack_15c = (undefined4 ****)0x591638;
                              ppppuStack_15c = (undefined4 ****)FUN_007359b0();
                              ppppuStack_160 = (undefined4 ****)0x59163b;
                              iVar4 = _stricmp();
                              ppppuVar1 = ppppuStack_13c;
                              if ((iVar4 == 0) && (param_2 == (undefined4 *****)0x1)) {
                                *(undefined1 *)(param_1 + 0x176) = 0;
                                ppppuStack_158 = (undefined4 ****)0x591658;
                                func_0x00460e50();
                                ppppuStack_158 = (undefined4 ****)0x591663;
                                (*(code *)(*ppppuVar1[0x310])[3])();
                              }
                              else {
                                ppppuStack_158 = (undefined4 ****)0x95d670;
                                ppppuStack_15c = (undefined4 ****)0x591684;
                                ppppuStack_15c = (undefined4 ****)FUN_007359b0();
                                ppppuStack_160 = (undefined4 ****)0x591687;
                                iVar4 = _stricmp();
                                ppppuVar1 = ppppuStack_13c;
                                if ((iVar4 != 0) || (param_2 != (undefined4 *****)0x1)) {
                                  ppppuStack_158 = (undefined4 ****)0x96518c;
                                  ppppuStack_15c = (undefined4 ****)0x5916b7;
                                  ppppuStack_15c = (undefined4 ****)FUN_007359b0();
                                  ppppuStack_160 = (undefined4 ****)0x5916ba;
                                  iVar4 = _stricmp();
                                  if ((iVar4 == 0) && (param_2 == (undefined4 *****)0x1)) {
                                    ppppuStack_158 = (undefined4 ****)0x963efc;
                                    ppppuStack_15c = (undefined4 ****)0x5916de;
                                    FUN_00737400();
                                    ppppuStack_15c = (undefined4 ****)0x5916e7;
                                    iVar4 = FUN_00748730();
                                    if (_DAT_009b73cc != 0) {
                                      if (_DAT_009b73c0 + iVar4 * 5 < _DAT_009b73c4 + -5) {
                                        pppppuVar5 = _DAT_009b73c0 + iVar4 * 5 + 9;
                                        do {
                                          ppppuStack_15c = pppppuVar5 + -3;
                                          pppppuVar5[-9] = pppppuVar5[-4];
                                          ppppuStack_160 = (undefined4 ****)0x59171d;
                                          FUN_007652d0();
                                          pppppuVar5[-7] = pppppuVar5[-2];
                                          pppppuVar5[-6] = pppppuVar5[-1];
                                          pppppuVar5[-5] = *pppppuVar5;
                                          pppppuVar7 = pppppuVar5 + -4;
                                          pppppuVar5 = pppppuVar5 + 5;
                                        } while (pppppuVar7 < _DAT_009b73c4 + -5);
                                      }
                                      _DAT_009b73c4 = _DAT_009b73c4 + -5;
                                      _DAT_009b73cc = _DAT_009b73cc + -1;
                                      ppppuStack_15c = (undefined4 ****)0x59175d;
                                      FUN_00765200();
                                    }
                                    ppppuStack_15c = (undefined4 ****)0x591764;
                                    ppppuStack_15c = (undefined4 ****)FUN_00748730();
                                    ppppuStack_160 = (undefined4 ****)0x59176c;
                                    FUN_00748620();
                                    pppppuVar5 = (undefined4 *****)ppppuStack_168;
                                  }
                                  else {
                                    ppppuStack_158 = (undefined4 ****)0x96519c;
                                    ppppuStack_15c = (undefined4 ****)0x59177d;
                                    ppppuStack_15c = (undefined4 ****)FUN_007359b0();
                                    ppppuStack_160 = (undefined4 ****)0x591780;
                                    iVar4 = _stricmp();
                                    if ((iVar4 == 0) && (param_2 == (undefined4 *****)0x1)) {
                                      ppppuStack_158 = (undefined4 ****)0x963efc;
                                      ppppuStack_15c = (undefined4 ****)0x5917a4;
                                      FUN_00737400();
                                      ppppuStack_15c = (undefined4 ****)0x5917ab;
                                      FUN_00748890();
                                      ppppuStack_13c = _DAT_009b73c0;
                                      ppppuStack_138 = _DAT_009b73c0 + _DAT_009b73cc * 5;
                                      pppppuVar5 = (undefined4 *****)ppppuStack_168;
                                      if (_DAT_009b73c0 != (undefined4 *****)ppppuStack_138) {
                                        pppppuVar5 = _DAT_009b73c0;
                                        if (ppppuStack_138 < _DAT_009b73c4) {
                                          pppppuVar7 = _DAT_009b73c0 + 1;
                                          uStack_140 = (undefined4 *****)
                                                       ((int)_DAT_009b73c0 - (int)ppppuStack_138);
                                          pppppuVar15 = (undefined4 *****)(ppppuStack_138 + 4);
                                          do {
                                            ppppuStack_158 = pppppuVar15 + -3;
                                            *pppppuVar5 = pppppuVar15[-4];
                                            ppppuStack_15c = (undefined4 ****)0x5917fa;
                                            FUN_007652d0();
                                            pppppuVar7[1] = pppppuVar15[-2];
                                            pppppuVar7[2] = pppppuVar15[-1];
                                            pppppuVar10 = pppppuVar15 + 1;
                                            *(undefined4 *****)
                                             ((int)(uStack_140 + -5) + (int)(pppppuVar15 + 5)) =
                                                 *pppppuVar15;
                                            pppppuVar5 = pppppuVar5 + 5;
                                            pppppuVar7 = pppppuVar7 + 5;
                                            pppppuVar15 = pppppuVar15 + 5;
                                          } while (pppppuVar10 < _DAT_009b73c4);
                                        }
                                        if (pppppuVar5 < _DAT_009b73c4) {
                                          do {
                                            ppppuStack_158 = (undefined4 ****)0x591835;
                                            FUN_00765200();
                                            pppppuVar5 = pppppuVar5 + 5;
                                          } while (pppppuVar5 < _DAT_009b73c4);
                                        }
                                        iVar4 = ((int)ppppuStack_138 - (int)ppppuStack_13c) / 0x14;
                                        _DAT_009b73c4 = _DAT_009b73c4 + iVar4 * -5;
                                        _DAT_009b73cc = _DAT_009b73cc - iVar4;
                                        pppppuVar5 = (undefined4 *****)ppppuStack_168;
                                      }
                                    }
                                    else {
                                      ppppuStack_158 = (undefined4 ****)0x969d6c;
                                      ppppuStack_15c = (undefined4 ****)0x591891;
                                      ppppuStack_15c = (undefined4 ****)FUN_007359b0();
                                      ppppuStack_160 = (undefined4 ****)0x591894;
                                      iVar4 = _stricmp();
                                      if ((iVar4 == 0) && (param_2 == (undefined4 *****)0x1)) {
                                        pppppuVar5 = (undefined4 *****)ppppuStack_168;
                                        if ((-1 < (int)_DAT_00969cc8) &&
                                           ((int)_DAT_00969cc8 < _DAT_009b73cc)) {
                                          ppppuStack_158 = (undefined4 ****)0x963efc;
                                          ppppuStack_15c = (undefined4 ****)0x5918d5;
                                          ppppuStack_13c = (undefined4 ****)FUN_00737400();
                                          if (_DAT_009b73cc != 0) {
                                            pppppuVar5 = _DAT_009b73c0 + (int)_DAT_00969cc8 * 5;
                                            if (pppppuVar5 < _DAT_009b73c4 + -5) {
                                              pppppuVar7 = pppppuVar5 + 9;
                                              do {
                                                ppppuStack_15c = pppppuVar7 + -3;
                                                *pppppuVar5 = pppppuVar7[-4];
                                                ppppuStack_160 = (undefined4 ****)0x591912;
                                                FUN_007652d0();
                                                pppppuVar5 = pppppuVar5 + 5;
                                                pppppuVar7[-7] = pppppuVar7[-2];
                                                pppppuVar7[-6] = pppppuVar7[-1];
                                                pppppuVar7[-5] = *pppppuVar7;
                                                pppppuVar7 = pppppuVar7 + 5;
                                              } while (pppppuVar5 < _DAT_009b73c4 + -5);
                                            }
                                            _DAT_009b73c4 = _DAT_009b73c4 + -5;
                                            _DAT_009b73cc = _DAT_009b73cc + -1;
                                            ppppuStack_15c = (undefined4 ****)0x591952;
                                            FUN_00765200();
                                          }
                                          ppppuStack_15c = _DAT_00969cc8;
                                          ppppuStack_160 = (undefined4 ****)0x591962;
                                          FUN_00748620();
                                          ppppuStack_160 = (undefined4 ****)0x0;
                                          ppppuStack_164 = (undefined4 *****)0x59196f;
                                          func_0x00548620();
                                          pppppuVar5 = (undefined4 *****)ppppuStack_168;
                                        }
                                      }
                                      else {
                                        ppppuStack_158 = (undefined4 ****)0x969d80;
                                        ppppuStack_15c = (undefined4 ****)0x591980;
                                        ppppuStack_15c = (undefined4 ****)FUN_007359b0();
                                        ppppuStack_160 = (undefined4 ****)0x591983;
                                        iVar4 = _stricmp();
                                        if ((iVar4 == 0) && (param_2 == (undefined4 *****)0x1)) {
                                          ppppuStack_158 = (undefined4 ****)0x963efc;
                                          ppppuStack_15c = (undefined4 ****)0x5919a7;
                                          FUN_00737400();
                                          ppppuStack_144 = _DAT_009b73c0;
                                          uStack_140 = _DAT_009b73c0 + _DAT_009b73cc * 5;
                                          if (_DAT_009b73c0 != uStack_140) {
                                            pppppuVar5 = _DAT_009b73c0;
                                            if (uStack_140 < _DAT_009b73c4) {
                                              pppppuVar7 = _DAT_009b73c0 + 1;
                                              ppppuStack_13c =
                                                   (undefined4 ****)
                                                   ((int)_DAT_009b73c0 - (int)uStack_140);
                                              pppppuVar15 = uStack_140 + 4;
                                              do {
                                                ppppuStack_15c = pppppuVar15 + -3;
                                                *pppppuVar5 = pppppuVar15[-4];
                                                ppppuStack_160 = (undefined4 ****)0x5919fc;
                                                FUN_007652d0();
                                                pppppuVar7[1] = pppppuVar15[-2];
                                                pppppuVar7[2] = pppppuVar15[-1];
                                                pppppuVar10 = pppppuVar15 + 1;
                                                *(undefined4 *****)
                                                 ((int)(ppppuStack_13c + -5) +
                                                 (int)(pppppuVar15 + 5)) = *pppppuVar15;
                                                pppppuVar5 = pppppuVar5 + 5;
                                                pppppuVar7 = pppppuVar7 + 5;
                                                pppppuVar15 = pppppuVar15 + 5;
                                              } while (pppppuVar10 < _DAT_009b73c4);
                                            }
                                            if (pppppuVar5 < _DAT_009b73c4) {
                                              do {
                                                ppppuStack_15c = (undefined4 ****)0x591a37;
                                                FUN_00765200();
                                                pppppuVar5 = pppppuVar5 + 5;
                                              } while (pppppuVar5 < _DAT_009b73c4);
                                            }
                                            iVar4 = ((int)uStack_140 - (int)ppppuStack_144) / 0x14;
                                            _DAT_009b73c4 = _DAT_009b73c4 + iVar4 * -5;
                                            _DAT_009b73cc = _DAT_009b73cc - iVar4;
                                          }
                                          ppppuStack_15c = (undefined4 ****)0x591a8f;
                                          FUN_00748890();
                                          ppppuStack_15c = (undefined4 ****)0x0;
                                          ppppuStack_160 = (undefined4 ****)0x591a9c;
                                          func_0x00548620();
                                          pppppuVar5 = (undefined4 *****)ppppuStack_168;
                                        }
                                        else {
                                          ppppuStack_158 = (undefined4 ****)0x96fc0c;
                                          ppppuStack_15c = (undefined4 ****)0x591aad;
                                          ppppuStack_15c = (undefined4 ****)FUN_007359b0();
                                          ppppuStack_160 = (undefined4 ****)0x591ab0;
                                          iVar4 = _stricmp();
                                          if ((iVar4 == 0) && (param_2 == (undefined4 *****)0x1))
                                          goto LAB_00591abc;
                                          ppppuStack_158 = (undefined4 ****)0x961d40;
                                          ppppuStack_15c = (undefined4 ****)0x591add;
                                          ppppuStack_15c = (undefined4 ****)FUN_007359b0();
                                          ppppuStack_160 = (undefined4 ****)0x591ae0;
                                          iVar4 = _stricmp();
                                          if ((iVar4 == 0) && (param_2 == (undefined4 *****)0x1)) {
                                            ppppuStack_158 = (undefined4 ****)0x961cf0;
                                            ppppuStack_15c = (undefined4 ****)0x591afc;
                                            FUN_00737400();
                                            ppppuStack_15c = (undefined4 ****)0x591b05;
                                            pppppuVar5 = (undefined4 *****)FUN_00752100();
                                            if (pppppuVar5 == (undefined4 *****)0x0) {
                                              uVar12 = 1;
                                              goto LAB_00592fde;
                                            }
                                            ppppuStack_160 = (undefined4 ****)&DAT_009b3c44;
                                            ppppuStack_164 = (undefined4 ****)0x591b23;
                                            func_0x007636b0();
                                            ppppuStack_168 = (undefined4 ****)0x591b2b;
                                            ppppuStack_164 = pppppuVar5;
                                            ppppuStack_168 = (undefined4 ****)FUN_007518b0();
                                            ppppuStack_16c = (undefined4 *****)0x591b35;
                                            func_0x005e3a20();
                                            pppppuVar5 = (undefined4 *****)ppppuStack_168;
                                          }
                                          else {
                                            ppppuStack_158 = (undefined4 ****)0x961eec;
                                            ppppuStack_15c = (undefined4 ****)0x591b46;
                                            ppppuStack_15c = (undefined4 ****)FUN_007359b0();
                                            ppppuStack_160 = (undefined4 ****)0x591b49;
                                            iVar4 = _stricmp();
                                            if ((iVar4 == 0) && (param_2 == (undefined4 *****)0x1))
                                            {
                                              ppppuStack_158 = (undefined4 ****)0x961cf0;
                                              ppppuStack_15c = (undefined4 ****)0x591b65;
                                              FUN_00737400();
                                              ppppuStack_15c = (undefined4 ****)0x591b6e;
                                              pppppuVar5 = (undefined4 *****)FUN_00752100();
                                              if (pppppuVar5 == (undefined4 *****)0x0) {
                                                uVar12 = 1;
                                                goto LAB_00592fde;
                                              }
                                              ppppuStack_160 = (undefined4 ****)&DAT_009b3c44;
                                              ppppuStack_164 = (undefined4 ****)0x591b8c;
                                              func_0x007636b0();
                                              ppppuStack_168 = (undefined4 ****)0x591b94;
                                              ppppuStack_164 = pppppuVar5;
                                              ppppuStack_16c = (undefined4 ****)FUN_007518b0();
                                              ppppuStack_168 = (undefined4 *****)0x9b3c40;
                                              pppuStack_170 = (undefined4 ****)0x591ba3;
                                              func_0x005e3010();
                                              pppppuVar5 = (undefined4 *****)ppppuStack_168;
                                            }
                                            else {
                                              ppppuStack_158 = (undefined4 ****)0x9651b0;
                                              ppppuStack_15c = (undefined4 ****)0x591bb4;
                                              ppppuStack_15c = (undefined4 ****)FUN_007359b0();
                                              ppppuStack_160 = (undefined4 ****)0x591bb7;
                                              iVar4 = _stricmp();
                                              if ((iVar4 == 0) && (param_2 == (undefined4 *****)0x1)
                                                 ) {
                                                ppppuStack_158 = (undefined4 ****)0x591bc8;
                                                func_0x005f1270();
                                                pppppuVar5 = (undefined4 *****)ppppuStack_168;
                                              }
                                              else {
                                                ppppuStack_158 = (undefined4 ****)0x9651c0;
                                                ppppuStack_15c = (undefined4 ****)0x591bd9;
                                                ppppuStack_15c = (undefined4 ****)FUN_007359b0();
                                                ppppuStack_160 = (undefined4 ****)0x591bdc;
                                                iVar4 = _stricmp();
                                                if ((iVar4 == 0) &&
                                                   (param_2 == (undefined4 *****)0x1)) {
                                                  ppppuStack_158 = (undefined4 ****)0x591bed;
                                                  func_0x005f12b0();
                                                  pppppuVar5 = (undefined4 *****)ppppuStack_168;
                                                }
                                                else {
                                                  ppppuStack_158 = (undefined4 ****)0x96553c;
                                                  ppppuStack_15c = (undefined4 ****)0x591bfe;
                                                  ppppuStack_15c = (undefined4 ****)FUN_007359b0();
                                                  ppppuStack_160 = (undefined4 ****)0x591c01;
                                                  iVar4 = _stricmp();
                                                  if ((iVar4 == 0) &&
                                                     (param_2 == (undefined4 *****)0x1)) {
                                                    ppppuStack_144 = &ppppuStack_158;
                                                    ppppuStack_15c = (undefined4 ****)0x95f96c;
                                                    ppppuStack_160 = (undefined4 ****)0x591c1e;
                                                    func_0x007636b0();
                                                    ppppuStack_160 = (undefined4 ****)0x591c25;
                                                    iVar4 = FUN_007380f0();
                                                    ppppuStack_160 = *(undefined4 *****)(iVar4 + 8);
                                                    ppppuStack_164 = (undefined4 ****)0x591c2e;
                                                    func_0x005f2c40();
                                                    ppppuStack_160 = param_2;
                                                    ppppuStack_164 = (undefined4 *****)0x0;
                                                    ppppuStack_168 = (undefined4 *****)0x0;
                                                    ppppuStack_16c = (undefined4 ****)0x591c41;
                                                    FUN_00735c50();
                                                    ppppuStack_16c = (undefined4 *****)0x591c48;
                                                    func_0x0059a640();
                                                    pppppuVar5 = (undefined4 *****)ppppuStack_168;
                                                  }
                                                  else {
                                                    ppppuStack_158 = (undefined4 ****)0x961958;
                                                    ppppuStack_15c = (undefined4 ****)0x591c59;
                                                    ppppuStack_15c = (undefined4 ****)FUN_007359b0()
                                                    ;
                                                    ppppuStack_160 = (undefined4 ****)0x591c5c;
                                                    pppppuVar5 = (undefined4 *****)_stricmp();
                                                    if ((pppppuVar5 == (undefined4 *****)0x0) &&
                                                       (param_2 == (undefined4 *****)0x1)) {
                                                      ppppuStack_158 =
                                                           (undefined4 ****)ppppuStack_13c[0x116];
                                                      ppppuStack_15c = (undefined4 ****)0x591c84;
                                                      uStack_140 = pppppuVar5;
                                                      ppppuStack_15c =
                                                           (undefined4 ****)func_0x0076eb20();
                                                      ppppuStack_164 =
                                                           (undefined4 ****)appuStack_110;
                                                      ppppuStack_160 = (undefined4 ****)0x96fd18;
                                                      ppppuStack_168 = (undefined4 ****)0x591c95;
                                                      sprintf();
                                                      ppppuStack_168 =
                                                           (undefined4 ****)appuStack_110;
                                                      ppppuStack_16c = (undefined4 ****)0x591c9f;
                                                      cVar2 = func_0x0059a680();
                                                      if (cVar2 == '\0') {
                                                        ppppuStack_164 = (undefined4 *****)0x238;
                                                      }
                                                      else {
                                                        ppppuStack_164 = (undefined4 *****)0x237;
                                                      }
                                                      ppppuStack_158 = (undefined4 ****)&uStack_140;
                                                      ppppuStack_15c = (undefined4 ****)0xa0ffffff;
                                                      ppppuStack_160 = (undefined4 ****)0x0;
                                                      ppppuStack_168 = (undefined4 ****)0x591cd1;
                                                      ppppuStack_168 =
                                                           (undefined4 ****)FUN_0072ef30();
                                                      ppppuStack_16c =
                                                           (undefined4 ****)&DAT_009b3c44;
                                                      pppuStack_170 = (undefined4 ****)0x591cde;
                                                      FUN_00730110();
                                                      pppppuVar5 = (undefined4 *****)ppppuStack_168;
                                                      if (uStack_140 != (undefined4 *****)0x0) {
                                                        ppppuStack_158 = (undefined4 ****)0x3;
                                                        ppppuStack_15c = (undefined4 ****)0x591cf1;
                                                        FUN_00738300();
                                                        pppppuVar5 = (undefined4 *****)
                                                                     ppppuStack_168;
                                                      }
                                                    }
                                                    else {
                                                      ppppuStack_158 = (undefined4 ****)0x962da4;
                                                      ppppuStack_15c = (undefined4 ****)0x591d02;
                                                      ppppuStack_15c =
                                                           (undefined4 ****)FUN_007359b0();
                                                      ppppuStack_160 = (undefined4 ****)0x591d05;
                                                      iVar4 = _stricmp();
                                                      if ((iVar4 == 0) &&
                                                         (param_2 == (undefined4 *****)0x1)) {
                                                        ppppuStack_158 = (undefined4 ****)0x591d1a;
                                                        func_0x005e5750();
                                                        pppppuVar5 = (undefined4 *****)
                                                                     ppppuStack_168;
                                                      }
                                                      else {
                                                        ppppuStack_158 = (undefined4 ****)0x962db4;
                                                        ppppuStack_15c = (undefined4 ****)0x591d2b;
                                                        ppppuStack_15c =
                                                             (undefined4 ****)FUN_007359b0();
                                                        ppppuStack_160 = (undefined4 ****)0x591d2e;
                                                        iVar4 = _stricmp();
                                                        if ((iVar4 == 0) &&
                                                           (param_2 == (undefined4 *****)0x1)) {
                                                          ppppuStack_144 = &ppppuStack_158;
                                                          ppppuStack_15c =
                                                               (undefined4 ****)&DAT_009b3c44;
                                                          ppppuStack_160 = (undefined4 ****)0x591d4b
                                                          ;
                                                          func_0x007636b0();
                                                          ppppuStack_160 = (undefined4 ****)0x591d52
                                                          ;
                                                          ppppuStack_160 =
                                                               (undefined4 ****)FUN_00738010();
                                                          ppppuStack_164 =
                                                               (undefined4 *****)0x591d5c;
                                                          func_0x005e53c0();
                                                          pppppuVar5 = (undefined4 *****)
                                                                       ppppuStack_168;
                                                        }
                                                        else {
                                                          ppppuStack_158 = (undefined4 ****)0x962dc4
                                                          ;
                                                          ppppuStack_15c = (undefined4 ****)0x591d6d
                                                          ;
                                                          ppppuStack_15c =
                                                               (undefined4 ****)FUN_007359b0();
                                                          ppppuStack_160 = (undefined4 ****)0x591d70
                                                          ;
                                                          iVar4 = _stricmp();
                                                          if (iVar4 == 0) {
                                                            if (param_2 == (undefined4 *****)0x1) {
                                                              ppppuStack_158 =
                                                                   (undefined4 ****)0x591d89;
                                                              func_0x005e5620();
                                                              pppppuVar5 = (undefined4 *****)
                                                                           ppppuStack_168;
                                                            }
                                                            else {
LAB_00591e79:
                                                              ppppuStack_158 =
                                                                   (undefined4 ****)0x962df4;
                                                              ppppuStack_15c =
                                                                   (undefined4 ****)0x591e85;
                                                              ppppuStack_15c =
                                                                   (undefined4 ****)FUN_007359b0();
                                                              ppppuStack_160 =
                                                                   (undefined4 ****)0x591e88;
                                                              iVar4 = _stricmp();
                                                              if ((iVar4 == 0) &&
                                                                 (param_2 == (undefined4 *****)0x1))
                                                              {
                                                                ppppuStack_144 = &ppppuStack_158;
                                                                ppppuStack_15c =
                                                                     (undefined4 ****)&DAT_009b3c44;
                                                                ppppuStack_160 =
                                                                     (undefined4 ****)0x591ea5;
                                                                func_0x007636b0();
                                                                ppppuStack_160 =
                                                                     (undefined4 ****)0x591eac;
                                                                ppppuStack_160 =
                                                                     (undefined4 ****)FUN_00738010()
                                                                ;
                                                                ppppuStack_164 =
                                                                     (undefined4 *****)0x591eb6;
                                                                func_0x005e4e10();
                                                                pppppuVar5 = (undefined4 *****)
                                                                             ppppuStack_168;
                                                              }
                                                              else {
                                                                ppppuStack_158 =
                                                                     (undefined4 ****)0x96552c;
                                                                ppppuStack_15c =
                                                                     (undefined4 ****)0x591ec7;
                                                                ppppuStack_15c =
                                                                     (undefined4 ****)FUN_007359b0()
                                                                ;
                                                                ppppuStack_160 =
                                                                     (undefined4 ****)0x591eca;
                                                                iVar4 = _stricmp();
                                                                if ((iVar4 == 0) &&
                                                                   (param_2 == (undefined4 *****)0x1
                                                                   )) {
                                                                  if ((int)ppppuStack_13c[0x14a] <
                                                                      2000000) {
                                                                    ppppuStack_158 =
                                                                         (undefined4 ****)0x0;
                                                                    ppppuStack_15c =
                                                                         (undefined4 ****)0xa0ffffff
                                                                    ;
                                                                    ppppuStack_160 =
                                                                         (undefined4 ****)0x0;
                                                                    ppppuStack_164 =
                                                                         (undefined4 *****)0x263;
                                                                    ppppuStack_168 =
                                                                         (undefined4 ****)0x591f09;
                                                                    ppppuStack_168 =
                                                                         (undefined4 ****)
                                                                         FUN_0072ef30();
                                                                    ppppuStack_16c =
                                                                         (undefined4 ****)
                                                                         &DAT_009b3c44;
                                                                    pppuStack_170 =
                                                                         (undefined4 ****)0x591f16;
                                                                    FUN_00730110();
                                                                    pppppuVar5 = (undefined4 *****)
                                                                                 ppppuStack_168;
                                                                  }
                                                                  else {
                                                                    ppppuStack_158 =
                                                                         (undefined4 ****)0x591eef;
                                                                    func_0x005e4690();
                                                                    pppppuVar5 = (undefined4 *****)
                                                                                 ppppuStack_168;
                                                                  }
                                                                }
                                                                else {
                                                                  ppppuStack_158 =
                                                                       (undefined4 ****)0x96551c;
                                                                  ppppuStack_15c =
                                                                       (undefined4 ****)0x591f27;
                                                                  ppppuStack_15c =
                                                                       (undefined4 ****)
                                                                       FUN_007359b0();
                                                                  ppppuStack_160 =
                                                                       (undefined4 ****)0x591f2a;
                                                                  iVar4 = _stricmp();
                                                                  if ((iVar4 == 0) &&
                                                                     (param_2 ==
                                                                      (undefined4 *****)0x1)) {
                                                                    ppppuStack_158 =
                                                                         (undefined4 ****)0x591f3f;
                                                                    func_0x005e45c0();
                                                                    pppppuVar5 = (undefined4 *****)
                                                                                 ppppuStack_168;
                                                                  }
                                                                  else {
                                                                    ppppuStack_158 =
                                                                         (undefined4 ****)0x96fd04;
                                                                    ppppuStack_15c =
                                                                         (undefined4 ****)0x591f50;
                                                                    ppppuStack_15c =
                                                                         (undefined4 ****)
                                                                         FUN_007359b0();
                                                                    ppppuStack_160 =
                                                                         (undefined4 ****)0x591f53;
                                                                    iVar4 = _stricmp();
                                                                    if ((iVar4 == 0) &&
                                                                       (ppppuStack_158 =
                                                                             (undefined4 ****)
                                                                             ppppuStack_13c[0x175],
                                                                       (int)ppppuStack_158 < 1)) {
                                                                      ppppuStack_144 =
                                                                           &ppppuStack_158;
                                                                      ppppuStack_15c =
                                                                           (undefined4 ****)0x9622f8
                                                                      ;
                                                                      ppppuStack_160 =
                                                                           (undefined4 ****)0x591f79
                                                                      ;
                                                                      func_0x007636b0();
                                                                      ppppuStack_160 =
                                                                           (undefined4 ****)0x591f80
                                                                      ;
                                                                      FUN_007380f0();
                                                                      uVar12 = extraout_ECX_00;
                                                                      if (param_2 ==
                                                                          (undefined4 *****)0x6) {
                                                                        ppppuStack_160 =
                                                                             (undefined4 ****)0x0;
                                                                        ppppuStack_164 =
                                                                             (undefined4 ****)
                                                                             0x591f96;
                                                                        func_0x004f8580();
                                                                        uVar12 = extraout_ECX_01;
                                                                      }
                                                                      ppppuStack_160 =
                                                                           (undefined4 ****)
                                                                           CONCAT31((int3)((uint)
                                                  uVar12 >> 8),param_2 == (undefined4 *****)0x6);
                                                  ppppuStack_164 = (undefined4 ****)&stack0xfffffeb4
                                                  ;
                                                  ppppuStack_168 = (undefined4 *****)0x591faa;
                                                  func_0x005e5e80();
                                                  pppppuVar5 = (undefined4 *****)ppppuStack_168;
                                                  }
                                                  else {
                                                    ppppuStack_158 = (undefined4 ****)0x963ddc;
                                                    ppppuStack_15c = (undefined4 ****)0x591fbb;
                                                    ppppuStack_15c = (undefined4 ****)FUN_007359b0()
                                                    ;
                                                    ppppuStack_160 = (undefined4 ****)0x591fbe;
                                                    iVar4 = _stricmp();
                                                    if (iVar4 == 0) {
                                                      if (param_2 == (undefined4 *****)0x6) {
                                                        ppppuStack_158 = (undefined4 ****)0x591fd1;
                                                        ppppuStack_158 =
                                                             (undefined4 ****)FUN_00735c30();
LAB_00591fd9:
                                                        ppppuStack_144 = &ppppuStack_15c;
                                                        ppppuStack_160 =
                                                             (undefined4 ****)&DAT_009b3c44;
                                                        ppppuStack_164 = (undefined4 ****)0x591fe3;
                                                        func_0x007636b0();
                                                        ppppuStack_164 = (undefined4 ****)0x591fea;
                                                        ppppuStack_164 =
                                                             (undefined4 ****)FUN_00738010();
                                                        ppppuStack_168 = (undefined4 *****)0x591ff4;
                                                        func_0x005e7a00();
                                                        pppppuVar5 = (undefined4 *****)
                                                                     ppppuStack_168;
                                                      }
                                                      else {
                                                        ppppuStack_144 = &ppppuStack_158;
                                                        ppppuStack_15c = (undefined4 ****)0x9622f8;
                                                        ppppuStack_160 = (undefined4 ****)0x59200a;
                                                        func_0x007636b0();
                                                        ppppuStack_160 = (undefined4 ****)0x592011;
                                                        ppppuStack_160 =
                                                             (undefined4 ****)FUN_007380f0();
                                                        ppppuStack_168 =
                                                             (undefined4 ****)&DAT_009b3c44;
                                                        ppppuStack_16c = (undefined4 ****)0x592023;
                                                        ppppuStack_164 = extraout_ECX_02;
                                                        func_0x007636b0();
                                                        ppppuStack_16c = (undefined4 ****)0x59202a;
                                                        ppppuStack_16c =
                                                             (undefined4 ****)FUN_00738010();
                                                        pppuStack_170 = (undefined4 ****)0x592034;
                                                        func_0x005e75c0();
                                                        pppppuVar5 = (undefined4 *****)
                                                                     ppppuStack_168;
                                                      }
                                                    }
                                                    else {
                                                      ppppuStack_158 = (undefined4 ****)0x95e35c;
                                                      ppppuStack_15c = (undefined4 ****)0x592045;
                                                      ppppuStack_15c =
                                                           (undefined4 ****)FUN_007359b0();
                                                      ppppuStack_160 = (undefined4 ****)0x592048;
                                                      iVar4 = _stricmp();
                                                      if ((iVar4 == 0) &&
                                                         (param_2 == (undefined4 *****)0x6)) {
                                                        ppppuStack_158 = (undefined4 ****)0x9b3c40;
                                                        ppppuStack_15c = (undefined4 ****)0x592060;
                                                        ppppuStack_15c =
                                                             (undefined4 ****)FUN_00735c30();
                                                        ppppuStack_160 = (undefined4 ****)0x59206a;
                                                        func_0x005e82d0();
                                                        pppppuVar5 = (undefined4 *****)
                                                                     ppppuStack_168;
                                                      }
                                                      else {
                                                        ppppuStack_158 = (undefined4 ****)0x95e378;
                                                        ppppuStack_15c = (undefined4 ****)0x59207b;
                                                        ppppuStack_15c =
                                                             (undefined4 ****)FUN_007359b0();
                                                        ppppuStack_160 = (undefined4 ****)0x59207e;
                                                        iVar4 = _stricmp();
                                                        if ((iVar4 == 0) &&
                                                           (param_2 == (undefined4 *****)0x6)) {
                                                          ppppuStack_158 = (undefined4 ****)0x9b3c40
                                                          ;
                                                          goto LAB_00591fd9;
                                                        }
                                                        ppppuStack_158 = (undefined4 ****)0x95e1a0;
                                                        ppppuStack_15c = (undefined4 ****)0x5920a7;
                                                        ppppuStack_15c =
                                                             (undefined4 ****)FUN_007359b0();
                                                        ppppuStack_160 = (undefined4 ****)0x5920aa;
                                                        iVar4 = _stricmp();
                                                        if ((iVar4 == 0) &&
                                                           (param_2 == (undefined4 *****)0x6)) {
                                                          ppppuStack_158 = (undefined4 ****)0x5920c5
                                                          ;
                                                          ppppuStack_158 =
                                                               (undefined4 ****)FUN_00735c30();
                                                          ppppuStack_15c = (undefined4 ****)0x5920cf
                                                          ;
                                                          FUN_00765050();
                                                          ppppuStack_15c = (undefined4 ****)0x0;
                                                          ppppuStack_160 = (undefined4 ****)0x95b34c
                                                          ;
                                                          puStack_8 = (undefined *)0x0;
                                                          ppppuStack_164 = (undefined4 ****)0x5920ea
                                                          ;
                                                          ppppuVar8 = (undefined4 ****)
                                                                      FUN_00765e60();
                                                          ppppuStack_164 =
                                                               (undefined4 *****)0xffffffff;
                                                          ppppuStack_16c = &ppppuStack_144;
                                                          ppppuStack_168 =
                                                               (undefined4 ****)((int)ppppuVar8 + 1)
                                                          ;
                                                          pppuStack_170 = (undefined4 ***)0x592100;
                                                          puVar9 = (undefined4 *)func_0x004cb7f0();
                                                          ppppuVar1 = (undefined4 ****)*puVar9;
                                                          ppppuStack_174 = &ppppuStack_15c;
                                                          uStack_1c = 1;
                                                          puStack_178 = (undefined *)0x592119;
                                                          pppuStack_170 = ppppuVar8;
                                                          puVar9 = (undefined4 *)func_0x004cb780();
                                                          puStack_178 = (undefined *)0x1e;
                                                          uStack_24 = 2;
                                                          pppuStack_17c = ppppuVar1;
                                                          func_0x005e5f10(*puVar9);
                                                          iStack_30._0_1_ = 1;
                                                          FUN_00765200();
                                                          iStack_30 = (uint)iStack_30._1_3_ << 8;
                                                          FUN_00765200();
                                                          iStack_30 = 0xffffffff;
                                                          FUN_00765200();
                                                          pppppuVar5 = (undefined4 *****)
                                                                       ppppuStack_168;
                                                        }
                                                        else {
                                                          ppppuStack_158 = (undefined4 ****)0x95df70
                                                          ;
                                                          ppppuStack_15c = (undefined4 ****)0x592177
                                                          ;
                                                          ppppuStack_15c =
                                                               (undefined4 ****)FUN_007359b0();
                                                          ppppuStack_160 = (undefined4 ****)0x59217a
                                                          ;
                                                          iVar4 = _stricmp();
                                                          if ((iVar4 == 0) &&
                                                             (param_2 == (undefined4 *****)0x6)) {
                                                            ppppuStack_144 = &ppppuStack_158;
                                                            ppppuStack_15c =
                                                                 (undefined4 ****)&DAT_009b3c44;
                                                            ppppuStack_160 =
                                                                 (undefined4 ****)0x592197;
                                                            func_0x007636b0();
                                                            ppppuStack_160 =
                                                                 (undefined4 ****)0x59219e;
                                                            ppppuStack_160 =
                                                                 (undefined4 ****)FUN_00738010();
                                                            ppppuStack_164 =
                                                                 (undefined4 *****)0x5921a8;
                                                            func_0x005e84a0();
                                                            pppppuVar5 = (undefined4 *****)
                                                                         ppppuStack_168;
                                                          }
                                                          else {
                                                            ppppuStack_158 =
                                                                 (undefined4 ****)0x964968;
                                                            ppppuStack_15c =
                                                                 (undefined4 ****)0x5921b9;
                                                            ppppuStack_15c =
                                                                 (undefined4 ****)FUN_007359b0();
                                                            ppppuStack_160 =
                                                                 (undefined4 ****)0x5921bc;
                                                            iVar4 = _stricmp();
                                                            if ((iVar4 == 0) &&
                                                               (param_2 == (undefined4 *****)0x1)) {
                                                              ppppuStack_144 = &ppppuStack_158;
                                                              ppppuStack_15c =
                                                                   (undefined4 ****)&DAT_009b3c44;
                                                              ppppuStack_160 =
                                                                   (undefined4 ****)0x5921d9;
                                                              func_0x007636b0();
                                                              ppppuStack_160 =
                                                                   (undefined4 ****)0x5921e0;
                                                              ppppuStack_160 =
                                                                   (undefined4 ****)FUN_00738010();
                                                              ppppuStack_164 =
                                                                   (undefined4 ****)0x5921ec;
                                                              func_0x0050b900();
                                                              ppppuStack_168 =
                                                                   (undefined4 ****)&DAT_009b3c44;
                                                              ppppuStack_16c =
                                                                   (undefined4 ****)0x5921fd;
                                                              ppppuStack_164 = extraout_ECX_03;
                                                              func_0x007636b0();
                                                              ppppuStack_16c =
                                                                   (undefined4 ****)0x592204;
                                                              ppppuStack_16c =
                                                                   (undefined4 ****)FUN_00738010();
                                                              pppuStack_170 =
                                                                   (undefined4 ****)0x59220e;
                                                              func_0x005e9d20();
                                                              pppppuVar5 = (undefined4 *****)
                                                                           ppppuStack_168;
                                                            }
                                                            else {
                                                              ppppuStack_158 =
                                                                   (undefined4 ****)0x95bc0c;
                                                              ppppuStack_15c =
                                                                   (undefined4 ****)0x59221f;
                                                              ppppuStack_15c =
                                                                   (undefined4 ****)FUN_007359b0();
                                                              ppppuStack_160 =
                                                                   (undefined4 ****)0x592222;
                                                              ppppuStack_158 =
                                                                   (undefined4 ****)_stricmp();
                                                              if ((ppppuStack_158 ==
                                                                   (undefined4 ****)0x0) &&
                                                                 (param_2 == (undefined4 *****)0x6))
                                                              {
                                                                ppppuStack_160 =
                                                                     (undefined4 ****)&DAT_009b3c44;
                                                                ppppuStack_164 =
                                                                     (undefined4 ****)0x592240;
                                                                ppppuStack_144 = &ppppuStack_15c;
                                                                func_0x007636b0();
                                                                ppppuStack_164 =
                                                                     (undefined4 ****)0x592247;
                                                                ppppuStack_164 =
                                                                     (undefined4 ****)FUN_007380f0()
                                                                ;
                                                                ppppuStack_168 = extraout_ECX_04;
                                                              }
                                                              else {
                                                                ppppuStack_158 =
                                                                     (undefined4 ****)0x95bc20;
                                                                ppppuStack_15c =
                                                                     (undefined4 ****)0x59227b;
                                                                ppppuStack_15c =
                                                                     (undefined4 ****)FUN_007359b0()
                                                                ;
                                                                ppppuStack_160 =
                                                                     (undefined4 ****)0x59227e;
                                                                iVar4 = _stricmp();
                                                                if ((iVar4 != 0) ||
                                                                   (param_2 != (undefined4 *****)0x6
                                                                   )) {
                                                                  ppppuStack_158 =
                                                                       (undefined4 ****)0x95c618;
                                                                  ppppuStack_15c =
                                                                       (undefined4 ****)0x5922ba;
                                                                  ppppuStack_15c =
                                                                       (undefined4 ****)
                                                                       FUN_007359b0();
                                                                  ppppuStack_160 =
                                                                       (undefined4 ****)0x5922bd;
                                                                  ppppuStack_158 =
                                                                       (undefined4 ****)_stricmp();
                                                                  if ((ppppuStack_158 ==
                                                                       (undefined4 ****)0x0) &&
                                                                     (param_2 ==
                                                                      (undefined4 *****)0x6)) {
                                                                    ppppuStack_160 =
                                                                         (undefined4 ****)
                                                                         &DAT_009b3c44;
                                                                    ppppuStack_164 =
                                                                         (undefined4 ****)0x5922db;
                                                                    ppppuStack_144 = &ppppuStack_15c
                                                                    ;
                                                                    func_0x007636b0();
                                                                    ppppuStack_164 =
                                                                         (undefined4 ****)0x5922e2;
                                                                    ppppuStack_164 =
                                                                         (undefined4 ****)
                                                                         FUN_00738010();
                                                                    ppppuStack_168 =
                                                                         (undefined4 *****)0x5922ec;
                                                                    func_0x005ec4c0();
                                                                    pppppuVar5 = (undefined4 *****)
                                                                                 ppppuStack_168;
                                                                  }
                                                                  else {
                                                                    ppppuStack_158 =
                                                                         (undefined4 ****)0x95c218;
                                                                    ppppuStack_15c =
                                                                         (undefined4 ****)0x5922fd;
                                                                    ppppuStack_15c =
                                                                         (undefined4 ****)
                                                                         FUN_007359b0();
                                                                    ppppuStack_160 =
                                                                         (undefined4 ****)0x592300;
                                                                    iVar4 = _stricmp();
                                                                    if ((iVar4 == 0) &&
                                                                       (param_2 ==
                                                                        (undefined4 *****)0x6)) {
                                                                      ppppuStack_144 =
                                                                           &ppppuStack_158;
                                                                      ppppuStack_15c =
                                                                           (undefined4 ****)
                                                                           &DAT_009b3c44;
                                                                      ppppuStack_160 =
                                                                           (undefined4 ****)0x59231d
                                                                      ;
                                                                      func_0x007636b0();
                                                                      ppppuStack_160 =
                                                                           (undefined4 ****)0x592324
                                                                      ;
                                                                      ppppuStack_160 =
                                                                           (undefined4 ****)
                                                                           FUN_00738010();
                                                                      ppppuStack_164 =
                                                                           (undefined4 *****)
                                                                           0x59232e;
                                                                      func_0x005ecc60();
                                                                      pppppuVar5 = (undefined4 *****
                                                                                   )ppppuStack_168;
                                                                    }
                                                                    else {
                                                                      ppppuStack_158 =
                                                                           (undefined4 ****)0x9548bc
                                                                      ;
                                                                      ppppuStack_15c =
                                                                           (undefined4 ****)0x59233f
                                                                      ;
                                                                      ppppuStack_15c =
                                                                           (undefined4 ****)
                                                                           FUN_007359b0();
                                                                      ppppuStack_160 =
                                                                           (undefined4 ****)0x592342
                                                                      ;
                                                                      iVar4 = _stricmp();
                                                                      if (iVar4 == 0) {
                                                                        ppppuStack_144 =
                                                                             &ppppuStack_158;
                                                                        ppppuStack_15c =
                                                                             (undefined4 ****)
                                                                             &DAT_009b3c44;
                                                                        ppppuStack_160 =
                                                                             (undefined4 ****)
                                                                             0x59235a;
                                                                        func_0x007636b0();
                                                                        ppppuStack_160 =
                                                                             (undefined4 ****)
                                                                             0x592361;
                                                                        ppppuStack_164 =
                                                                             (undefined4 ****)
                                                                             FUN_00738010();
                                                                        ppppuStack_160 =
                                                                             (undefined4 ****)
                                                                             (uint)(param_2 ==
                                                                                   (undefined4 *****
                                                                                   )0x7);
                                                                        ppppuStack_168 =
                                                                             (undefined4 *****)
                                                                             0x592370;
                                                                        func_0x005f15b0();
                                                                        pppppuVar5 = (undefined4
                                                                                      *****)
                                                  ppppuStack_168;
                                                  }
                                                  else {
                                                    ppppuStack_158 = (undefined4 ****)0x9548cc;
                                                    ppppuStack_15c = (undefined4 ****)0x592384;
                                                    ppppuStack_15c = (undefined4 ****)FUN_007359b0()
                                                    ;
                                                    ppppuStack_160 = (undefined4 ****)0x592387;
                                                    iVar4 = _stricmp();
                                                    if (iVar4 == 0) {
                                                      ppppuStack_144 = &ppppuStack_158;
                                                      ppppuStack_15c =
                                                           (undefined4 ****)&DAT_009b3c44;
                                                      ppppuStack_160 = (undefined4 ****)0x59239f;
                                                      func_0x007636b0();
                                                      ppppuStack_160 = (undefined4 ****)0x5923a6;
                                                      ppppuStack_164 =
                                                           (undefined4 ****)FUN_00738010();
                                                      ppppuStack_160 =
                                                           (undefined4 ****)
                                                           (uint)(param_2 == (undefined4 *****)0x7);
                                                      ppppuStack_168 = (undefined4 *****)0x5923b5;
                                                      func_0x005f1570();
                                                      pppppuVar5 = (undefined4 *****)ppppuStack_168;
                                                    }
                                                    else {
                                                      ppppuStack_158 = (undefined4 ****)0x9548e0;
                                                      ppppuStack_15c = (undefined4 ****)0x5923c9;
                                                      ppppuStack_15c =
                                                           (undefined4 ****)FUN_007359b0();
                                                      ppppuStack_160 = (undefined4 ****)0x5923cc;
                                                      iVar4 = _stricmp();
                                                      if (iVar4 == 0) {
                                                        ppppuStack_144 = &ppppuStack_158;
                                                        ppppuStack_15c =
                                                             (undefined4 ****)&DAT_009b3c44;
                                                        ppppuStack_160 = (undefined4 ****)0x5923e4;
                                                        func_0x007636b0();
                                                        ppppuStack_160 = (undefined4 ****)0x5923eb;
                                                        ppppuStack_164 =
                                                             (undefined4 ****)FUN_00738010();
                                                        ppppuStack_160 =
                                                             (undefined4 ****)
                                                             ((param_2 != (undefined4 *****)0x7) - 1
                                                             & 2);
                                                        ppppuStack_168 = (undefined4 *****)0x5923fe;
                                                        func_0x005f14b0();
                                                        pppppuVar5 = (undefined4 *****)
                                                                     ppppuStack_168;
                                                      }
                                                      else {
                                                        ppppuStack_158 = (undefined4 ****)0x965960;
                                                        ppppuStack_15c = (undefined4 ****)0x592412;
                                                        ppppuStack_15c =
                                                             (undefined4 ****)FUN_007359b0();
                                                        ppppuStack_160 = (undefined4 ****)0x592415;
                                                        iVar4 = _stricmp();
                                                        if ((iVar4 == 0) &&
                                                           (param_2 == (undefined4 *****)0x1)) {
                                                          ppppuStack_144 = &ppppuStack_158;
                                                          ppppuStack_15c =
                                                               (undefined4 ****)&DAT_009b3c44;
                                                          ppppuStack_160 = (undefined4 ****)0x592432
                                                          ;
                                                          func_0x007636b0();
                                                          ppppuStack_160 = (undefined4 ****)0x592439
                                                          ;
                                                          ppppuStack_160 =
                                                               (undefined4 ****)FUN_00738010();
                                                          ppppuStack_164 =
                                                               (undefined4 *****)0x59243f;
                                                          func_0x005f1fc0();
                                                          pppppuVar5 = (undefined4 *****)
                                                                       ppppuStack_168;
                                                        }
                                                        else {
                                                          ppppuStack_158 = (undefined4 ****)0x965508
                                                          ;
                                                          ppppuStack_15c = (undefined4 ****)0x592453
                                                          ;
                                                          ppppuStack_15c =
                                                               (undefined4 ****)FUN_007359b0();
                                                          ppppuStack_160 = (undefined4 ****)0x592456
                                                          ;
                                                          iVar4 = _stricmp();
                                                          if (iVar4 == 0) {
                                                            if (param_2 == (undefined4 *****)0x1) {
                                                              ppppuStack_158 =
                                                                   (undefined4 ****)0x592467;
                                                              func_0x005f2e80();
                                                            }
                                                            ppppuStack_158 =
                                                                 (undefined4 ****)0x59246e;
                                                            func_0x0059a640();
                                                            pppppuVar5 = (undefined4 *****)
                                                                         ppppuStack_168;
                                                          }
                                                          else {
                                                            ppppuStack_158 =
                                                                 (undefined4 ****)0x95ef9c;
                                                            ppppuStack_15c =
                                                                 (undefined4 ****)0x59247f;
                                                            ppppuStack_15c =
                                                                 (undefined4 ****)FUN_007359b0();
                                                            ppppuStack_160 =
                                                                 (undefined4 ****)0x592482;
                                                            iVar4 = _stricmp();
                                                            if (iVar4 == 0) {
                                                              ppppuStack_124 = _DAT_00985a98;
                                                              iStack_4 = 3;
                                                              if ((param_2 == (undefined4 *****)0x6)
                                                                 || (param_2 ==
                                                                     (undefined4 *****)0x1)) {
                                                                ppppuStack_158 =
                                                                     (undefined4 ****)0x5924b9;
                                                                ppppuStack_158 =
                                                                     (undefined4 ****)FUN_00735c30()
                                                                ;
                                                                ppppuStack_15c =
                                                                     (undefined4 ****)0x1;
                                                                ppppuStack_160 =
                                                                     (undefined4 ****)0x5924c5;
                                                                func_0x005d2870();
                                                                ppppuStack_160 =
                                                                     (undefined4 ****)0x5924cb;
                                                                _DAT_009b7000 =
                                                                     (undefined4 *****)
                                                                     GetTickCount();
                                                                ppppuStack_12c = _DAT_009b7000;
                                                              }
                                                              else {
                                                                ppppuStack_12c =
                                                                     (undefined4 *****)0x0;
                                                              }
                                                              ppppuStack_158 =
                                                                   (undefined4 ****)0x95ee54;
                                                              ppppuStack_128 =
                                                                   (undefined4 ****)
                                                                   CONCAT31(ppppuStack_128._1_3_,1);
                                                              ppppuStack_15c =
                                                                   (undefined4 ****)0x5924e7;
                                                              uVar12 = FUN_00765050();
                                                              puStack_8._0_1_ = 4;
                                                              ppppuStack_15c =
                                                                   (undefined4 ****)0x5924f8;
                                                              ppppuStack_15c =
                                                                   (undefined4 ****)FUN_00735c30();
                                                              ppppuStack_164 =
                                                                   (undefined4 ****)&stack0xfffffeb8
                                                              ;
                                                              ppppuStack_168 =
                                                                   (undefined4 *****)0x592504;
                                                              ppppuStack_160 =
                                                                   (undefined4 ****)uVar12;
                                                              ppppuStack_15c =
                                                                   (undefined4 ****)
                                                                   func_0x004bcb50();
                                                              puStack_8 = (undefined *)
                                                                          CONCAT31(puStack_8._1_3_,5
                                                                                  );
                                                              ppppuStack_160 =
                                                                   (undefined4 ****)0x59251d;
                                                              FUN_007652d0();
                                                              uStack_c._0_1_ = 4;
                                                              ppppuStack_160 =
                                                                   (undefined4 ****)0x59252e;
                                                              FUN_00765200();
                                                              uStack_c._0_1_ = 3;
                                                              ppppuStack_160 =
                                                                   (undefined4 ****)0x59253f;
                                                              FUN_00765200();
                                                              pppppuVar5 = _DAT_009b6fcc;
                                                              if (_DAT_009b6fcc == _DAT_009b6fc8) {
                                                                if ((int)_DAT_009b6fcc + 1U < 5) {
                                                                  uStack_140 = (undefined4 *****)0x5
                                                                  ;
                                                                }
                                                                else {
                                                                  uStack_140 = (undefined4 *****)
                                                                               ((int)_DAT_009b6fcc +
                                                                               ((uint)_DAT_009b6fcc
                                                                               >> 1) + 3);
                                                                }
                                                                ppppuStack_160 =
                                                                     (undefined4 ****)
                                                                     ((int)uStack_140 * 0xc);
                                                                ppppuStack_164 =
                                                                     (undefined4 *****)0x592579;
                                                                pppppuVar10 = (undefined4 *****)
                                                                              func_0x00763250();
                                                                pppppuVar14 = (undefined4 *****)0x0;
                                                                pppppuVar7 = _DAT_009b6fcc;
                                                                pppppuVar5 = pppppuVar10;
                                                                pppppuVar15 = _DAT_009b6fc0;
                                                                if (_DAT_009b6fcc !=
                                                                    (undefined4 *****)0x0) {
                                                                  do {
                                                                    uStack_c._0_1_ = 6;
                                                                    pppppuVar17 = pppppuVar15;
                                                                    ppppuStack_144 = pppppuVar5;
                                                                    if (pppppuVar5 !=
                                                                        (undefined4 *****)0x0) {
                                                                      pppppuVar17 = pppppuVar15 + 3;
                                                                      ppppuStack_160 =
                                                                           pppppuVar15 + 2;
                                                                      *pppppuVar5 = *pppppuVar15;
                                                                      *(undefined1 *)
                                                                       (pppppuVar5 + 1) =
                                                                           *(undefined1 *)
                                                                            (pppppuVar15 + 1);
                                                                      *(undefined1 *)
                                                                       ((int)pppppuVar5 + 5) =
                                                                           *(undefined1 *)
                                                                            ((int)pppppuVar15 + 5);
                                                                      ppppuStack_164 =
                                                                           (undefined4 *****)
                                                                           0x5925ce;
                                                                      FUN_00765000();
                                                                      pppppuVar7 = _DAT_009b6fcc;
                                                                    }
                                                                    pppppuVar14 = (undefined4 *****)
                                                                                  ((int)pppppuVar14
                                                                                  + 1);
                                                                    uStack_c._0_1_ = 3;
                                                                    pppppuVar5 = pppppuVar5 + 3;
                                                                    pppppuVar15 = pppppuVar17;
                                                                  } while (pppppuVar14 < pppppuVar7)
                                                                  ;
                                                                }
                                                                pppppuVar15 = (undefined4 *****)0x0;
                                                                pppppuVar5 = (undefined4 *****)0x0;
                                                                if (pppppuVar7 !=
                                                                    (undefined4 *****)0x0) {
                                                                  do {
                                                                    ppppuStack_160 =
                                                                         (undefined4 ****)0x5925fa;
                                                                    FUN_00765200();
                                                                    pppppuVar15 = (undefined4 *****)
                                                                                  ((int)pppppuVar15
                                                                                  + 1);
                                                                    pppppuVar5 = _DAT_009b6fcc;
                                                                  } while (pppppuVar15 <
                                                                           _DAT_009b6fcc);
                                                                }
                                                                if (_DAT_009b6fc0 !=
                                                                    (undefined4 *****)0x0) {
                                                                  ppppuStack_160 = _DAT_009b6fc0;
                                                                  ppppuStack_164 =
                                                                       (undefined4 *****)0x592614;
                                                                  func_0x00763260();
                                                                  pppppuVar5 = _DAT_009b6fcc;
                                                                }
                                                                _DAT_009b6fc8 = uStack_140;
                                                                _DAT_009b6fc4 =
                                                                     pppppuVar10 +
                                                                     (int)pppppuVar5 * 3;
                                                                _DAT_009b6fc0 = pppppuVar10;
                                                              }
                                                              pppppuVar7 = _DAT_009b6fc4;
                                                              uStack_c = CONCAT31(uStack_c._1_3_,7);
                                                              if (_DAT_009b6fc4 !=
                                                                  (undefined4 *****)0x0) {
                                                                *_DAT_009b6fc4 =
                                                                     (undefined4 ****)pppuStack_134;
                                                                *(undefined1 *)(pppppuVar7 + 1) =
                                                                     (undefined1)uStack_130;
                                                                ppppuStack_160 = &ppppuStack_12c;
                                                                *(undefined1 *)((int)pppppuVar7 + 5)
                                                                     = uStack_130._1_1_;
                                                                ppppuStack_164 =
                                                                     (undefined4 *****)0x592670;
                                                                FUN_00765000();
                                                                pppppuVar5 = _DAT_009b6fcc;
                                                              }
                                                              _DAT_0095eddc =
                                                                   (undefined4 *****)
                                                                   ((int)pppppuVar5 + 1);
                                                              _DAT_009b6fc4 = _DAT_009b6fc4 + 3;
                                                              uStack_c = 0xffffffff;
                                                              ppppuStack_160 =
                                                                   (undefined4 ****)0x5926a4;
                                                              _DAT_009b6fcc = _DAT_0095eddc;
                                                              FUN_00765200();
                                                              pppppuVar5 = (undefined4 *****)
                                                                           ppppuStack_168;
                                                            }
                                                            else {
                                                              ppppuStack_158 =
                                                                   (undefined4 ****)0x96fcf4;
                                                              ppppuStack_15c =
                                                                   (undefined4 ****)0x5926b5;
                                                              ppppuStack_15c =
                                                                   (undefined4 ****)FUN_007359b0();
                                                              ppppuStack_160 =
                                                                   (undefined4 ****)0x5926b8;
                                                              iVar4 = _stricmp();
                                                              if ((iVar4 == 0) &&
                                                                 (param_2 == (undefined4 *****)0x1))
                                                              {
                                                                ppppuStack_144 = &ppppuStack_158;
                                                                ppppuStack_15c =
                                                                     (undefined4 ****)&DAT_009b3c44;
                                                                ppppuStack_160 =
                                                                     (undefined4 ****)0x5926d5;
                                                                func_0x007636b0();
                                                                ppppuStack_160 =
                                                                     (undefined4 ****)0x5926dc;
                                                                ppppuStack_160 =
                                                                     (undefined4 ****)FUN_007380f0()
                                                                ;
                                                                ppppuStack_168 =
                                                                     (undefined4 ****)&DAT_009b3c44;
                                                                ppppuStack_16c =
                                                                     (undefined4 ****)0x5926ee;
                                                                ppppuStack_164 = extraout_ECX_06;
                                                                func_0x007636b0();
                                                                ppppuStack_16c =
                                                                     (undefined4 ****)0x5926f5;
                                                                ppppuStack_16c =
                                                                     (undefined4 ****)FUN_00738010()
                                                                ;
                                                                pppuStack_170 =
                                                                     (undefined4 ****)0x5926ff;
                                                                func_0x005ee4c0();
                                                                pppppuVar5 = (undefined4 *****)
                                                                             ppppuStack_168;
                                                              }
                                                              else {
                                                                ppppuStack_158 =
                                                                     (undefined4 ****)0x96fcdc;
                                                                ppppuStack_15c =
                                                                     (undefined4 ****)0x592710;
                                                                ppppuStack_15c =
                                                                     (undefined4 ****)FUN_007359b0()
                                                                ;
                                                                ppppuStack_160 =
                                                                     (undefined4 ****)0x592713;
                                                                iVar4 = _stricmp();
                                                                if ((iVar4 == 0) &&
                                                                   (param_2 == (undefined4 *****)0x1
                                                                   )) {
                                                                  ppppuStack_144 = &ppppuStack_158;
                                                                  ppppuStack_15c =
                                                                       (undefined4 ****)
                                                                       &DAT_009b3c44;
                                                                  ppppuStack_160 =
                                                                       (undefined4 ****)0x592730;
                                                                  func_0x007636b0();
                                                                  ppppuStack_160 =
                                                                       (undefined4 ****)0x592737;
                                                                  ppppuStack_160 =
                                                                       (undefined4 ****)
                                                                       FUN_00738010();
                                                                  ppppuStack_164 =
                                                                       (undefined4 *****)0x592741;
                                                                  func_0x005ee660();
                                                                  pppppuVar5 = (undefined4 *****)
                                                                               ppppuStack_168;
                                                                }
                                                                else {
                                                                  ppppuStack_158 =
                                                                       (undefined4 ****)0x96fccc;
                                                                  ppppuStack_15c =
                                                                       (undefined4 ****)0x592752;
                                                                  ppppuStack_15c =
                                                                       (undefined4 ****)
                                                                       FUN_007359b0();
                                                                  ppppuStack_160 =
                                                                       (undefined4 ****)0x592755;
                                                                  iVar4 = _stricmp();
                                                                  if ((iVar4 == 0) &&
                                                                     (param_2 ==
                                                                      (undefined4 *****)0x1)) {
                                                                    ppppuStack_144 = &ppppuStack_158
                                                                    ;
                                                                    ppppuStack_15c =
                                                                         (undefined4 ****)
                                                                         &DAT_009b3c44;
                                                                    ppppuStack_160 =
                                                                         (undefined4 ****)0x592772;
                                                                    func_0x007636b0();
                                                                    ppppuStack_160 =
                                                                         (undefined4 ****)0x592779;
                                                                    ppppuStack_160 =
                                                                         (undefined4 ****)
                                                                         FUN_007380f0();
                                                                    ppppuStack_168 =
                                                                         (undefined4 ****)
                                                                         &DAT_009b3c44;
                                                                    ppppuStack_16c =
                                                                         (undefined4 ****)0x59278b;
                                                                    ppppuStack_164 = extraout_ECX_07
                                                                    ;
                                                                    func_0x007636b0();
                                                                    ppppuStack_16c =
                                                                         (undefined4 ****)0x592792;
                                                                    ppppuStack_16c =
                                                                         (undefined4 ****)
                                                                         FUN_00738010();
                                                                    pppuStack_170 =
                                                                         (undefined4 ****)0x59279c;
                                                                    func_0x005ee7f0();
                                                                    pppppuVar5 = (undefined4 *****)
                                                                                 ppppuStack_168;
                                                                  }
                                                                  else {
                                                                    ppppuStack_158 =
                                                                         (undefined4 ****)0x95f854;
                                                                    ppppuStack_15c =
                                                                         (undefined4 ****)0x5927ad;
                                                                    ppppuStack_15c =
                                                                         (undefined4 ****)
                                                                         FUN_007359b0();
                                                                    ppppuStack_160 =
                                                                         (undefined4 ****)0x5927b0;
                                                                    iVar4 = _stricmp();
                                                                    if ((iVar4 == 0) &&
                                                                       (param_2 ==
                                                                        (undefined4 *****)0x6)) {
                                                                      ppppuStack_144 =
                                                                           &ppppuStack_158;
                                                                      ppppuStack_15c =
                                                                           (undefined4 ****)
                                                                           &DAT_009b3c44;
                                                                      ppppuStack_160 =
                                                                           (undefined4 ****)0x5927d1
                                                                      ;
                                                                      func_0x007636b0();
                                                                      ppppuStack_160 =
                                                                           (undefined4 ****)0x5927d8
                                                                      ;
                                                                      ppppuStack_160 =
                                                                           (undefined4 ****)
                                                                           FUN_007380f0();
                                                                      ppppuStack_168 =
                                                                           (undefined4 ****)
                                                                           &DAT_009b3c44;
                                                                      ppppuStack_16c =
                                                                           (undefined4 ****)0x5927ea
                                                                      ;
                                                                      ppppuStack_164 =
                                                                           extraout_ECX_08;
                                                                      func_0x007636b0();
                                                                      ppppuStack_16c =
                                                                           (undefined4 ****)0x5927f1
                                                                      ;
                                                                      ppppuStack_16c =
                                                                           (undefined4 ****)
                                                                           FUN_00738010();
                                                                      pppuStack_170 =
                                                                           (undefined4 ***)0x5927fb;
                                                                      func_0x005dd8e0();
                                                                      pppuStack_170 =
                                                                           (undefined4 ****)0x0;
                                                                      ppppuStack_15c =
                                                                           &ppppuStack_174;
                                                                      puStack_178 = &DAT_009b3c44;
                                                                      pppuStack_17c =
                                                                           (undefined4 ****)0x59280e
                                                                      ;
                                                                      ppppuStack_174 =
                                                                           extraout_ECX_09;
                                                                      func_0x007636b0();
                                                                      pppuStack_17c =
                                                                           (undefined4 ****)0x592815
                                                                      ;
                                                                      pppuStack_17c =
                                                                           (undefined4 ***)
                                                                           FUN_00738010();
                                                                      func_0x00593010();
                                                                      ppppuStack_15c =
                                                                           (undefined4 ****)
                                                                           func_0x0048baa0();
                                                                      pppppuVar5 = (undefined4 *****
                                                                                   )ppppuStack_168;
                                                                      if (ppppuStack_15c !=
                                                                          (undefined4 ****)0x0) {
                                                                        ppppuStack_158 =
                                                                             (undefined4 ****)0x1;
                                                                        ppppuStack_160 =
                                                                             (undefined4 ****)
                                                                             0x59283a;
                                                                        func_0x00599a90();
                                                                        pppppuVar5 = (undefined4
                                                                                      *****)
                                                  ppppuStack_168;
                                                  }
                                                  }
                                                  else {
                                                    ppppuStack_158 = (undefined4 ****)0x958b38;
                                                    ppppuStack_15c = (undefined4 ****)0x59284b;
                                                    ppppuStack_15c = (undefined4 ****)FUN_007359b0()
                                                    ;
                                                    ppppuStack_160 = (undefined4 ****)0x59284e;
                                                    iVar4 = _stricmp();
                                                    if ((iVar4 == 0) &&
                                                       (param_2 == (undefined4 *****)0x6)) {
                                                      ppppuStack_144 = &ppppuStack_158;
                                                      ppppuStack_15c =
                                                           (undefined4 ****)&DAT_009b3c44;
                                                      ppppuStack_160 = (undefined4 ****)0x59286b;
                                                      func_0x007636b0();
                                                      ppppuStack_160 = (undefined4 ****)0x592872;
                                                      ppppuStack_160 =
                                                           (undefined4 ****)FUN_00738010();
                                                      ppppuStack_164 = (undefined4 *****)0x0;
                                                      ppppuStack_168 = (undefined4 ****)0x592880;
                                                      func_0x0045c280();
                                                      ppppuStack_168 = (undefined4 *****)0x0;
                                                      pppuStack_170 = (undefined4 ***)&DAT_009b3c44;
                                                      ppppuStack_174 = (undefined4 ****)0x592893;
                                                      ppppuStack_16c = extraout_ECX_10;
                                                      func_0x007636b0();
                                                      ppppuStack_174 = (undefined4 ****)0x59289a;
                                                      ppppuStack_174 =
                                                           (undefined4 ****)FUN_00738010();
                                                      puStack_178 = (undefined *)0x5928a2;
                                                      func_0x00593010();
                                                      puStack_178 = (undefined *)0x5928a9;
                                                      ppppuStack_15c =
                                                           (undefined4 ****)func_0x0048baa0();
                                                      pppppuVar5 = (undefined4 *****)ppppuStack_168;
                                                      if (ppppuStack_15c != (undefined4 ****)0x0) {
                                                        ppppuStack_158 = (undefined4 ****)0x1;
                                                        ppppuStack_160 = (undefined4 ****)0x5928bd;
                                                        func_0x00599a90();
                                                        pppppuVar5 = (undefined4 *****)
                                                                     ppppuStack_168;
                                                      }
                                                    }
                                                    else {
                                                      ppppuStack_158 = (undefined4 ****)0x95f668;
                                                      ppppuStack_15c = (undefined4 ****)0x5928ce;
                                                      ppppuStack_15c =
                                                           (undefined4 ****)FUN_007359b0();
                                                      ppppuStack_160 = (undefined4 ****)0x5928d1;
                                                      iVar4 = _stricmp();
                                                      if ((iVar4 == 0) &&
                                                         (param_2 == (undefined4 *****)0x6)) {
                                                        ppppuStack_144 = &ppppuStack_158;
                                                        ppppuStack_15c =
                                                             (undefined4 ****)&DAT_009b3c44;
                                                        ppppuStack_160 = (undefined4 ****)0x5928ee;
                                                        func_0x007636b0();
                                                        ppppuStack_160 = (undefined4 ****)0x5928f5;
                                                        ppppuStack_160 =
                                                             (undefined4 ****)FUN_00738010();
                                                        ppppuStack_164 = (undefined4 *****)0x5928fb;
                                                        func_0x005f2170();
                                                        pppppuVar5 = (undefined4 *****)
                                                                     ppppuStack_168;
                                                      }
                                                      else {
                                                        ppppuStack_158 = (undefined4 ****)0x960960;
                                                        ppppuStack_15c = (undefined4 ****)0x59290f;
                                                        ppppuStack_15c =
                                                             (undefined4 ****)FUN_007359b0();
                                                        ppppuStack_160 = (undefined4 ****)0x592912;
                                                        iVar4 = _stricmp();
                                                        if ((iVar4 == 0) &&
                                                           (param_2 == (undefined4 *****)0x6)) {
                                                          ppppuStack_144 = &ppppuStack_158;
                                                          ppppuStack_15c =
                                                               (undefined4 ****)&DAT_009b3c44;
                                                          ppppuStack_160 = (undefined4 ****)0x59292f
                                                          ;
                                                          func_0x007636b0();
                                                          ppppuStack_160 = (undefined4 ****)0x592936
                                                          ;
                                                          uVar6 = FUN_00738010();
                                                          ppppuStack_164 =
                                                               (undefined4 ****)&DAT_009b3c44;
                                                          ppppuStack_168 = (undefined4 ****)0x592949
                                                          ;
                                                          func_0x007636b0();
                                                          ppppuStack_168 = (undefined4 ****)0x592950
                                                          ;
                                                          ppppuStack_16c =
                                                               (undefined4 ****)FUN_007380f0();
                                                          ppppuStack_168 =
                                                               (undefined4 ****)(uVar6 & 0xff);
                                                          pppuStack_170 =
                                                               (undefined4 ***)(uVar6 >> 0x10);
                                                          ppppuStack_174 =
                                                               (undefined4 *****)0x592963;
                                                          func_0x005f3560();
                                                          pppppuVar5 = (undefined4 *****)
                                                                       ppppuStack_168;
                                                        }
                                                        else {
                                                          ppppuStack_158 = (undefined4 ****)0x95fb00
                                                          ;
                                                          ppppuStack_15c = (undefined4 ****)0x592977
                                                          ;
                                                          ppppuStack_15c =
                                                               (undefined4 ****)FUN_007359b0();
                                                          ppppuStack_160 = (undefined4 ****)0x59297a
                                                          ;
                                                          uVar18 = _stricmp();
                                                          if ((int)uVar18 == 0) {
                                                            ppppuStack_158 =
                                                                 (undefined4 ****)
                                                                 CONCAT31((int3)((ulonglong)uVar18
                                                                                >> 0x28),
                                                                          param_2 ==
                                                                          (undefined4 *****)0x6);
                                                            ppppuStack_15c =
                                                                 (undefined4 ****)0x592993;
                                                            func_0x004e1810();
                                                            pppppuVar5 = (undefined4 *****)
                                                                         ppppuStack_168;
                                                          }
                                                          else {
                                                            ppppuStack_158 =
                                                                 (undefined4 ****)0x962ffc;
                                                            ppppuStack_15c =
                                                                 (undefined4 ****)0x5929a4;
                                                            ppppuStack_15c =
                                                                 (undefined4 ****)FUN_007359b0();
                                                            ppppuStack_160 =
                                                                 (undefined4 ****)0x5929a7;
                                                            iVar4 = _stricmp();
                                                            if ((iVar4 == 0) &&
                                                               (param_2 == (undefined4 *****)0x1)) {
                                                              ppppuStack_144 = &ppppuStack_158;
                                                              ppppuStack_15c =
                                                                   (undefined4 ****)&DAT_009b3c44;
                                                              ppppuStack_160 =
                                                                   (undefined4 ****)0x5929c4;
                                                              func_0x007636b0();
                                                              ppppuStack_160 =
                                                                   (undefined4 ****)0x5929cb;
                                                              ppppuStack_160 =
                                                                   (undefined4 ****)FUN_007380f0();
                                                              ppppuStack_164 =
                                                                   (undefined4 ****)0x5929d5;
                                                              ppppuStack_164 =
                                                                   (undefined4 ****)
                                                                   func_0x00593000();
                                                              ppppuStack_16c =
                                                                   (undefined4 ****)&DAT_009b3c44;
                                                              pppuStack_170 =
                                                                   (undefined4 ***)0x5929e7;
                                                              ppppuStack_168 = extraout_ECX_11;
                                                              func_0x007636b0();
                                                              pppuStack_170 =
                                                                   (undefined4 ***)0x5929ee;
                                                              pppuStack_170 =
                                                                   (undefined4 ***)FUN_00738010();
                                                              ppppuStack_174 =
                                                                   (undefined4 ****)0x5929f8;
                                                              func_0x005ed950();
                                                              ppppuStack_174 = param_2;
                                                              puStack_178 = (undefined *)0x0;
                                                              pppuStack_17c = (undefined4 ****)0x0;
                                                              FUN_00735c50();
                                                              pppppuVar5 = (undefined4 *****)
                                                                           ppppuStack_168;
                                                            }
                                                            else {
                                                              ppppuStack_158 =
                                                                   (undefined4 ****)0x96670c;
                                                              ppppuStack_15c =
                                                                   (undefined4 ****)0x592a19;
                                                              ppppuStack_15c =
                                                                   (undefined4 ****)FUN_007359b0();
                                                              ppppuStack_160 =
                                                                   (undefined4 ****)0x592a1c;
                                                              iVar4 = _stricmp();
                                                              if ((iVar4 == 0) &&
                                                                 (param_2 == (undefined4 *****)0x6))
                                                              {
                                                                ppppuStack_158 =
                                                                     (undefined4 ****)0x592a3b;
                                                                func_0x00527ff0();
                                                                ppppuStack_144 = &ppppuStack_158;
                                                                ppppuStack_15c =
                                                                     (undefined4 ****)&DAT_009b3c44;
                                                                ppppuStack_160 =
                                                                     (undefined4 ****)0x592a4c;
                                                                func_0x007636b0();
                                                                ppppuStack_160 =
                                                                     (undefined4 ****)0x592a53;
                                                                ppppuStack_160 =
                                                                     (undefined4 ****)FUN_00738010()
                                                                ;
                                                                ppppuStack_164 =
                                                                     (undefined4 ****)&DAT_009b3c44;
                                                                uStack_140 = (undefined4 *****)
                                                                             CONCAT22(((short)((int)
                                                  ppppuStack_160 / 10) +
                                                  (short)((int)ppppuStack_160 >> 0x1f)) -
                                                  (short)((longlong)(int)ppppuStack_160 * 0x66666667
                                                         >> 0x3f),(undefined2)uStack_140);
                                                  ppppuStack_168 = (undefined4 ****)0x592a7c;
                                                  func_0x007636b0();
                                                  ppppuStack_168 = (undefined4 ****)0x592a83;
                                                  FUN_007380f0();
                                                  ppppuStack_16c = (undefined4 ****)&DAT_009b3c44;
                                                  pppuStack_170 = (undefined4 ***)0x592a99;
                                                  ppppuStack_168 = extraout_ECX_12;
                                                  func_0x007636b0();
                                                  pppuStack_170 = (undefined4 ***)0x592aa0;
                                                  FUN_00738010();
                                                  pppuStack_170 = (undefined4 ***)&stack0xfffffeb0;
                                                  ppppuStack_174 = (undefined4 *****)0x1;
                                                  puStack_178 = (undefined *)0x592ab9;
                                                  func_0x005f1630();
                                                  pppppuVar5 = (undefined4 *****)ppppuStack_168;
                                                  }
                                                  else {
                                                    ppppuStack_158 = (undefined4 ****)0x9666f8;
                                                    ppppuStack_15c = (undefined4 ****)0x592acd;
                                                    ppppuStack_15c = (undefined4 ****)FUN_007359b0()
                                                    ;
                                                    ppppuStack_160 = (undefined4 ****)0x592ad0;
                                                    iVar4 = _stricmp();
                                                    if ((iVar4 == 0) &&
                                                       (param_2 == (undefined4 *****)0x6)) {
                                                      ppppuStack_158 = (undefined4 ****)0x592aef;
                                                      func_0x00527ff0();
                                                      ppppuStack_144 = &ppppuStack_158;
                                                      ppppuStack_15c =
                                                           (undefined4 ****)&DAT_009b3c44;
                                                      ppppuStack_160 = (undefined4 ****)0x592b00;
                                                      func_0x007636b0();
                                                      ppppuStack_160 = (undefined4 ****)0x592b07;
                                                      ppppuStack_160 =
                                                           (undefined4 ****)FUN_00738010();
                                                      ppppuStack_164 =
                                                           (undefined4 ****)&DAT_009b3c44;
                                                      uStack_120 = (undefined4 *****)
                                                                   CONCAT22(((short)((int)
                                                  ppppuStack_160 / 10) +
                                                  (short)((int)ppppuStack_160 >> 0x1f)) -
                                                  (short)((longlong)(int)ppppuStack_160 * 0x66666667
                                                         >> 0x3f),(undefined2)uStack_120);
                                                  ppppuStack_168 = (undefined4 ****)0x592b30;
                                                  func_0x007636b0();
                                                  ppppuStack_168 = (undefined4 ****)0x592b37;
                                                  uVar3 = FUN_007380f0();
                                                  ppppuStack_128 =
                                                       (undefined4 ****)
                                                       CONCAT22(ppppuStack_128._2_2_,uVar3);
                                                  ppppuStack_16c = (undefined4 ****)&DAT_009b3c44;
                                                  pppuStack_170 = (undefined4 ***)0x592b4d;
                                                  ppppuStack_168 = extraout_ECX_13;
                                                  func_0x007636b0();
                                                  pppuStack_170 = (undefined4 ***)0x592b54;
                                                  iVar4 = FUN_00738010();
                                                  ppppuStack_12c =
                                                       (undefined4 ****)
                                                       CONCAT22(ppppuStack_12c._2_2_,
                                                                (short)(iVar4 % 10));
                                                  pppuStack_170 = (undefined4 ***)&uStack_130;
                                                  ppppuStack_174 = (undefined4 *****)0x1;
                                                  puStack_178 = (undefined *)0x592b6d;
                                                  func_0x005f1820();
                                                  pppppuVar5 = (undefined4 *****)ppppuStack_168;
                                                  }
                                                  else {
                                                    ppppuStack_158 = (undefined4 ****)0x95f644;
                                                    ppppuStack_15c = (undefined4 ****)0x592b81;
                                                    ppppuStack_15c = (undefined4 ****)FUN_007359b0()
                                                    ;
                                                    ppppuStack_160 = (undefined4 ****)0x592b84;
                                                    iVar4 = _stricmp();
                                                    if ((iVar4 == 0) &&
                                                       (param_2 == (undefined4 *****)0x1)) {
                                                      ppppuStack_144 = &ppppuStack_158;
                                                      ppppuStack_15c =
                                                           (undefined4 ****)&DAT_009b3c44;
                                                      ppppuStack_160 = (undefined4 ****)0x592ba1;
                                                      func_0x007636b0();
                                                      ppppuStack_160 = (undefined4 ****)0x592ba8;
                                                      ppppuStack_160 =
                                                           (undefined4 ****)FUN_00738010();
                                                      ppppuStack_164 = param_2;
                                                      ppppuStack_168 = (undefined4 *****)0x592bb3;
                                                      func_0x0045c280();
                                                      pppppuVar5 = (undefined4 *****)ppppuStack_168;
                                                    }
                                                    else {
                                                      ppppuStack_158 = (undefined4 ****)0x95ce28;
                                                      ppppuStack_15c = (undefined4 ****)0x592bc4;
                                                      ppppuStack_15c =
                                                           (undefined4 ****)FUN_007359b0();
                                                      ppppuStack_160 = (undefined4 ****)0x592bc7;
                                                      iVar4 = _stricmp();
                                                      if ((iVar4 == 0) &&
                                                         (param_2 == (undefined4 *****)0x1)) {
                                                        ppppuStack_144 = &ppppuStack_158;
                                                        ppppuStack_15c =
                                                             (undefined4 ****)&DAT_009b3c44;
                                                        ppppuStack_160 = (undefined4 ****)0x592be4;
                                                        func_0x007636b0();
                                                        ppppuStack_160 = (undefined4 ****)0x592beb;
                                                        ppppuStack_160 =
                                                             (undefined4 ****)FUN_00738010();
                                                        ppppuStack_164 = (undefined4 *****)0x0;
                                                        ppppuStack_168 = (undefined4 *****)0x592bf7;
                                                        func_0x0045c280();
                                                        pppppuVar5 = (undefined4 *****)
                                                                     ppppuStack_168;
                                                      }
                                                      else {
                                                        ppppuStack_158 = (undefined4 ****)0x962768;
                                                        ppppuStack_15c = (undefined4 ****)0x592c08;
                                                        ppppuStack_15c =
                                                             (undefined4 ****)FUN_007359b0();
                                                        ppppuStack_160 = (undefined4 ****)0x592c0b;
                                                        iVar4 = _stricmp();
                                                        if ((iVar4 == 0) &&
                                                           (param_2 == (undefined4 *****)0x6)) {
                                                          ppppuStack_144 = &ppppuStack_158;
                                                          ppppuStack_15c =
                                                               (undefined4 ****)&DAT_009b3c44;
                                                          ppppuStack_160 = (undefined4 ****)0x592c30
                                                          ;
                                                          func_0x007636b0();
                                                          ppppuStack_160 = (undefined4 ****)0x592c37
                                                          ;
                                                          ppppuStack_160 =
                                                               (undefined4 ****)FUN_007380f0();
                                                          ppppuStack_168 =
                                                               (undefined4 ****)&DAT_009b3c44;
                                                          ppppuStack_16c = (undefined4 ****)0x592c49
                                                          ;
                                                          ppppuStack_164 = extraout_ECX_14;
                                                          func_0x007636b0();
                                                          ppppuStack_16c = (undefined4 ****)0x592c50
                                                          ;
                                                          ppppuStack_16c =
                                                               (undefined4 ****)FUN_00738010();
                                                          pppuStack_170 = (undefined4 ****)0x1;
                                                          ppppuStack_174 = (undefined4 ****)0x592c5c
                                                          ;
                                                          func_0x005e2410();
                                                          ppppuStack_174 =
                                                               (undefined4 *****)0x95f48c;
                                                          puStack_178 = (undefined *)0x592c6c;
                                                          piVar11 = (int *)FUN_00737400();
                                                          puStack_178 = (undefined *)0x9b3c40;
                                                          pppuStack_17c = (undefined4 ****)0x592c78;
                                                          (**(code **)(*piVar11 + 0x34))();
                                                          ppppuStack_168 = &pppuStack_17c;
                                                          pppuStack_17c = extraout_ECX_15;
                                                          func_0x007636b0(&DAT_009b3c44);
                                                        }
                                                        else {
                                                          ppppuStack_158 = (undefined4 ****)0x962758
                                                          ;
                                                          ppppuStack_15c = (undefined4 ****)0x592cbe
                                                          ;
                                                          ppppuStack_15c =
                                                               (undefined4 ****)FUN_007359b0();
                                                          ppppuStack_160 = (undefined4 ****)0x592cc1
                                                          ;
                                                          iVar4 = _stricmp();
                                                          if ((iVar4 != 0) ||
                                                             (param_2 != (undefined4 *****)0x6)) {
                                                            ppppuStack_158 =
                                                                 (undefined4 ****)0x9624d0;
                                                            ppppuStack_15c =
                                                                 (undefined4 ****)0x592d48;
                                                            ppppuStack_15c =
                                                                 (undefined4 ****)FUN_007359b0();
                                                            ppppuStack_160 =
                                                                 (undefined4 ****)0x592d4b;
                                                            iVar4 = _stricmp();
                                                            if ((iVar4 == 0) &&
                                                               (param_2 == (undefined4 *****)0x6)) {
                                                              ppppuStack_144 = &ppppuStack_158;
                                                              ppppuStack_15c =
                                                                   (undefined4 ****)&DAT_009b3c44;
                                                              ppppuStack_160 =
                                                                   (undefined4 ****)0x592d68;
                                                              func_0x007636b0();
                                                              ppppuStack_160 =
                                                                   (undefined4 ****)0x592d6f;
                                                              ppppuStack_160 =
                                                                   (undefined4 ****)FUN_007380f0();
                                                              ppppuStack_168 =
                                                                   (undefined4 ****)&DAT_009b3c44;
                                                              ppppuStack_16c =
                                                                   (undefined4 ****)0x592d81;
                                                              ppppuStack_164 = extraout_ECX_18;
                                                              func_0x007636b0();
                                                              ppppuStack_16c =
                                                                   (undefined4 ****)0x592d88;
                                                              ppppuStack_16c =
                                                                   (undefined4 ****)FUN_00738010();
                                                              pppuStack_170 =
                                                                   (undefined4 ****)0x592d92;
                                                              func_0x005e2700();
                                                              pppppuVar5 = (undefined4 *****)
                                                                           ppppuStack_168;
                                                            }
                                                            else {
                                                              ppppuStack_158 =
                                                                   (undefined4 ****)0x95c68c;
                                                              ppppuStack_15c =
                                                                   (undefined4 ****)0x592da3;
                                                              ppppuStack_15c =
                                                                   (undefined4 ****)FUN_007359b0();
                                                              ppppuStack_160 =
                                                                   (undefined4 ****)0x592da6;
                                                              iVar4 = _stricmp();
                                                              if ((iVar4 == 0) &&
                                                                 (param_2 == (undefined4 *****)0x1))
                                                              {
                                                                ppppuStack_144 = &ppppuStack_158;
                                                                ppppuStack_15c =
                                                                     (undefined4 ****)&DAT_009b3c44;
                                                                ppppuStack_160 =
                                                                     (undefined4 ****)0x592dc3;
                                                                func_0x007636b0();
                                                                ppppuStack_160 =
                                                                     (undefined4 ****)0x592dca;
                                                                ppppuStack_160 =
                                                                     (undefined4 ****)FUN_00738010()
                                                                ;
                                                                ppppuStack_164 =
                                                                     (undefined4 *****)0x592dd4;
                                                                func_0x005ef740();
                                                                pppppuVar5 = (undefined4 *****)
                                                                             ppppuStack_168;
                                                              }
                                                              else {
                                                                ppppuStack_158 =
                                                                     (undefined4 ****)0x960adc;
                                                                ppppuStack_15c =
                                                                     (undefined4 ****)0x592de5;
                                                                ppppuStack_15c =
                                                                     (undefined4 ****)FUN_007359b0()
                                                                ;
                                                                ppppuStack_160 =
                                                                     (undefined4 ****)0x592de8;
                                                                iVar4 = _stricmp();
                                                                if ((iVar4 == 0) &&
                                                                   (param_2 == (undefined4 *****)0x6
                                                                   )) {
                                                                  ppppuStack_144 = &ppppuStack_158;
                                                                  ppppuStack_15c =
                                                                       (undefined4 ****)
                                                                       &DAT_009b3c44;
                                                                  ppppuStack_160 =
                                                                       (undefined4 ****)0x592e05;
                                                                  func_0x007636b0();
                                                                  ppppuStack_160 =
                                                                       (undefined4 ****)0x592e0c;
                                                                  ppppuStack_160 =
                                                                       (undefined4 ****)
                                                                       FUN_00738010();
                                                                  ppppuStack_164 =
                                                                       (undefined4 ****)0x592e12;
                                                                  func_0x005f3650();
                                                                  ppppuStack_160 =
                                                                       (undefined4 ****)0x0;
                                                                  ppppuStack_164 =
                                                                       (undefined4 *****)0x0;
                                                                  ppppuStack_168 =
                                                                       (undefined4 *****)0x0;
                                                                  ppppuStack_16c =
                                                                       (undefined4 *****)0x592e26;
                                                                  func_0x004ea150();
                                                                  pppppuVar5 = (undefined4 *****)
                                                                               ppppuStack_168;
                                                                }
                                                                else {
                                                                  ppppuStack_158 =
                                                                       (undefined4 ****)0x960498;
                                                                  ppppuStack_15c =
                                                                       (undefined4 ****)0x592e37;
                                                                  ppppuStack_15c =
                                                                       (undefined4 ****)
                                                                       FUN_007359b0();
                                                                  ppppuStack_160 =
                                                                       (undefined4 ****)0x592e3a;
                                                                  iVar4 = _stricmp();
                                                                  if ((iVar4 == 0) &&
                                                                     (param_2 ==
                                                                      (undefined4 *****)0x6)) {
                                                                    ppppuStack_158 =
                                                                         (undefined4 ****)0x592e51;
                                                                    func_0x004e5c40();
                                                                    pppppuVar5 = (undefined4 *****)
                                                                                 ppppuStack_168;
                                                                  }
                                                                  else {
                                                                    ppppuStack_158 =
                                                                         (undefined4 ****)0x95d658;
                                                                    ppppuStack_15c =
                                                                         (undefined4 ****)0x592e62;
                                                                    ppppuStack_15c =
                                                                         (undefined4 ****)
                                                                         FUN_007359b0();
                                                                    ppppuStack_160 =
                                                                         (undefined4 ****)0x592e65;
                                                                    iVar4 = _stricmp();
                                                                    if ((iVar4 == 0) &&
                                                                       (param_2 ==
                                                                        (undefined4 *****)0x6)) {
                                                                      ppppuStack_144 =
                                                                           &ppppuStack_158;
                                                                      ppppuStack_15c =
                                                                           (undefined4 ****)
                                                                           &DAT_009b3c44;
                                                                      ppppuStack_160 =
                                                                           (undefined4 ****)0x592e82
                                                                      ;
                                                                      func_0x007636b0();
                                                                      ppppuStack_160 =
                                                                           (undefined4 ****)0x592e89
                                                                      ;
                                                                      ppppuStack_160 =
                                                                           (undefined4 ****)
                                                                           FUN_00738010();
                                                                      ppppuStack_164 =
                                                                           (undefined4 *****)
                                                                           0x592e9a;
                                                                      func_0x00460fa0();
                                                                      pppppuVar5 = (undefined4 *****
                                                                                   )ppppuStack_168;
                                                                    }
                                                                    else {
                                                                      ppppuStack_158 =
                                                                           (undefined4 ****)0x96fcb8
                                                                      ;
                                                                      ppppuStack_15c =
                                                                           (undefined4 ****)0x592eab
                                                                      ;
                                                                      ppppuStack_15c =
                                                                           (undefined4 ****)
                                                                           FUN_007359b0();
                                                                      ppppuStack_160 =
                                                                           (undefined4 ****)0x592eae
                                                                      ;
                                                                      iVar4 = _stricmp();
                                                                      if ((iVar4 == 0) &&
                                                                         (param_2 ==
                                                                          (undefined4 *****)0x6)) {
                                                                        ppppuStack_144 =
                                                                             &ppppuStack_158;
                                                                        ppppuStack_15c =
                                                                             (undefined4 ****)
                                                                             &DAT_009b3c44;
                                                                        ppppuStack_160 =
                                                                             (undefined4 ****)
                                                                             0x592ecb;
                                                                        func_0x007636b0();
                                                                        ppppuStack_160 =
                                                                             (undefined4 ****)
                                                                             0x592ed2;
                                                                        pppppuVar5 = (undefined4
                                                                                      *****)
                                                  FUN_00738010();
                                                  ppppuStack_160 = (undefined4 ****)0x0;
                                                  ppppuStack_168 = (undefined4 ****)0x592ee5;
                                                  ppppuStack_164 = pppppuVar5;
                                                  ppppuStack_168 =
                                                       (undefined4 ****)func_0x004382f0();
                                                  pppuStack_170 = (undefined4 ***)0x592ef4;
                                                  ppppuStack_16c = pppppuVar5;
                                                  func_0x005e28a0();
                                                  pppuStack_170 = (undefined4 ****)0x0;
                                                  ppppuStack_174 = (undefined4 *****)0x0;
                                                  puStack_178 = (undefined *)0x0;
                                                  pppuStack_17c = (undefined4 ****)0xffffffff;
                                                  uVar12 = FUN_0072ef30(0x215,10);
                                                  func_0x005941a0(uVar12);
                                                  FUN_00735c50(0,0,1);
                                                  pppppuVar5 = (undefined4 *****)ppppuStack_168;
                                                  }
                                                  else {
                                                    ppppuStack_158 = (undefined4 ****)0x967084;
                                                    ppppuStack_15c = (undefined4 ****)0x592f30;
                                                    ppppuStack_15c = (undefined4 ****)FUN_007359b0()
                                                    ;
                                                    ppppuStack_160 = (undefined4 ****)0x592f33;
                                                    iVar4 = _stricmp();
                                                    if ((iVar4 == 0) &&
                                                       (param_2 == (undefined4 *****)0x6)) {
                                                      ppppuStack_144 = &ppppuStack_158;
                                                      ppppuStack_15c =
                                                           (undefined4 ****)&DAT_009b3c44;
                                                      ppppuStack_160 = (undefined4 ****)0x592f50;
                                                      func_0x007636b0();
                                                      ppppuStack_160 = (undefined4 ****)0x592f57;
                                                      iVar4 = FUN_00738010();
                                                      ppppuStack_160 =
                                                           (undefined4 ****)
                                                           CONCAT31((int3)((uint)extraout_ECX_19 >>
                                                                          8),iVar4 == 2);
                                                      ppppuStack_164 = (undefined4 *****)0x592f69;
                                                      func_0x0052ed30();
                                                      pppppuVar5 = (undefined4 *****)ppppuStack_168;
                                                    }
                                                    else {
                                                      ppppuStack_158 = (undefined4 ****)0x967070;
                                                      ppppuStack_15c = (undefined4 ****)0x592f77;
                                                      ppppuStack_15c =
                                                           (undefined4 ****)FUN_007359b0();
                                                      ppppuStack_160 = (undefined4 ****)0x592f7a;
                                                      iVar4 = _stricmp();
                                                      pppppuVar5 = (undefined4 *****)ppppuStack_168;
                                                      if ((iVar4 == 0) &&
                                                         (param_2 == (undefined4 *****)0x6)) {
                                                        ppppuStack_144 = &ppppuStack_158;
                                                        ppppuStack_15c =
                                                             (undefined4 ****)&DAT_009b3c44;
                                                        ppppuStack_160 = (undefined4 ****)0x592f9c;
                                                        func_0x007636b0();
                                                        ppppuStack_160 = (undefined4 ****)0x592fa3;
                                                        ppppuStack_160 =
                                                             (undefined4 ****)FUN_007380f0();
                                                        ppppuStack_168 =
                                                             (undefined4 ****)&DAT_009b3c44;
                                                        ppppuStack_16c = (undefined4 ****)0x592fb5;
                                                        ppppuStack_164 = extraout_ECX_20;
                                                        func_0x007636b0();
                                                        ppppuStack_16c = (undefined4 ****)0x592fbc;
                                                        ppppuStack_16c =
                                                             (undefined4 ****)FUN_00738010();
                                                        pppuStack_170 = (undefined4 ****)0x592fcc;
                                                        func_0x0052ec90();
                                                        pppppuVar5 = (undefined4 *****)
                                                                     ppppuStack_168;
                                                      }
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_00592fcc;
                                                  }
                                                  ppppuStack_144 = &ppppuStack_158;
                                                  ppppuStack_15c = (undefined4 ****)&DAT_009b3c44;
                                                  ppppuStack_160 = (undefined4 ****)0x592cde;
                                                  func_0x007636b0();
                                                  ppppuStack_160 = (undefined4 ****)0x592ce5;
                                                  ppppuStack_160 = (undefined4 ****)FUN_007380f0();
                                                  ppppuStack_168 = (undefined4 ****)&DAT_009b3c44;
                                                  ppppuStack_16c = (undefined4 ****)0x592cf7;
                                                  ppppuStack_164 = extraout_ECX_16;
                                                  func_0x007636b0();
                                                  ppppuStack_16c = (undefined4 ****)0x592cfe;
                                                  ppppuStack_16c = (undefined4 ****)FUN_00738010();
                                                  pppuStack_170 = (undefined4 ****)0x0;
                                                  ppppuStack_174 = (undefined4 ****)0x592d0a;
                                                  func_0x005e2410();
                                                  ppppuStack_174 = (undefined4 *****)0x95f48c;
                                                  puStack_178 = (undefined *)0x592d1a;
                                                  piVar11 = (int *)FUN_00737400();
                                                  puStack_178 = (undefined *)0x9b3c40;
                                                  pppuStack_17c = (undefined4 ****)0x592d26;
                                                  (**(code **)(*piVar11 + 0x34))();
                                                  ppppuStack_168 = &pppuStack_17c;
                                                  pppuStack_17c = extraout_ECX_17;
                                                  func_0x007636b0(&DAT_009b3c44);
                                                  }
                                                  uStack_2c = 0xffffffff;
                                                  FUN_00737400(0x95f48c,0);
                                                  FUN_007426d0();
                                                  pppppuVar5 = (undefined4 *****)ppppuStack_168;
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
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_00592fcc;
                                                  }
                                                  ppppuStack_158 = (undefined4 ****)0x1;
                                                  ppppuStack_160 = (undefined4 ****)&DAT_009b3c44;
                                                  ppppuStack_164 = (undefined4 ****)0x59229d;
                                                  ppppuStack_144 = &ppppuStack_15c;
                                                  func_0x007636b0();
                                                  ppppuStack_164 = (undefined4 ****)0x5922a4;
                                                  ppppuStack_164 = (undefined4 ****)FUN_007380f0();
                                                  ppppuStack_168 = extraout_ECX_05;
                                                  }
                                                  ppppuStack_16c = (undefined4 ****)&DAT_009b3c44;
                                                  pppuStack_170 = (undefined4 ***)0x592259;
                                                  func_0x007636b0();
                                                  pppuStack_170 = (undefined4 ***)0x592260;
                                                  pppuStack_170 = (undefined4 ***)FUN_00738010();
                                                  ppppuStack_174 = (undefined4 *****)0x59226a;
                                                  func_0x005eb9d0();
                                                  pppppuVar5 = (undefined4 *****)ppppuStack_168;
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
                                                    if (param_2 != (undefined4 *****)0x1)
                                                    goto LAB_00591e79;
                                                    ppppuStack_158 = (undefined4 ****)0x962dd4;
                                                    ppppuStack_15c = (undefined4 ****)0x591da3;
                                                    ppppuStack_15c = (undefined4 ****)FUN_007359b0()
                                                    ;
                                                    ppppuStack_160 = (undefined4 ****)0x591da6;
                                                    iVar4 = _stricmp();
                                                    if (iVar4 != 0) {
                                                      ppppuStack_158 = (undefined4 ****)0x962de4;
                                                      ppppuStack_15c = (undefined4 ****)0x591db9;
                                                      ppppuStack_15c =
                                                           (undefined4 ****)FUN_007359b0();
                                                      ppppuStack_160 = (undefined4 ****)0x591dbc;
                                                      iVar4 = _stricmp();
                                                      if (iVar4 != 0) goto LAB_00591e79;
                                                    }
                                                    ppppuStack_144 = &ppppuStack_158;
                                                    ppppuStack_15c = (undefined4 ****)&DAT_009b3c44;
                                                    ppppuStack_160 = (undefined4 ****)0x591dd8;
                                                    func_0x007636b0();
                                                    ppppuStack_160 = (undefined4 ****)0x591ddf;
                                                    ppppuStack_138 = (undefined4 ****)FUN_00738010()
                                                    ;
                                                    iVar16 = 0;
                                                    iVar4 = *(int *)(*(int *)(_DAT_009b3eec + 0x218)
                                                                    + 0x44);
                                                    puVar13 = (uint *)(*(int *)(_DAT_009b3eec +
                                                                               0x218) + 0x38);
                                                    pppppuVar5 = (undefined4 *****)ppppuStack_168;
                                                    if (0 < iVar4) {
                                                      ppppuStack_13c = (undefined4 ****)*puVar13;
                                                      do {
                                                        if ((undefined4 ****)**ppppuStack_13c ==
                                                            ppppuStack_138) {
                                                          ppppuStack_158 = (undefined4 ****)0x962dd4
                                                          ;
                                                          ppppuStack_15c = (undefined4 ****)0x591e33
                                                          ;
                                                          ppppuStack_15c =
                                                               (undefined4 ****)FUN_007359b0();
                                                          ppppuStack_160 = (undefined4 ****)0x591e36
                                                          ;
                                                          iVar4 = _stricmp();
                                                          if (iVar4 == 0) {
                                                            uVar12 = *(undefined4 *)
                                                                      (*(int *)(*puVar13 +
                                                                               iVar16 * 4) + 4);
                                                            ppppuStack_158 =
                                                                 (undefined4 ****)
                                                                 CONCAT31((int3)((uint)uVar12 >> 8),
                                                                          (char)uVar12 + -1);
                                                            ppppuStack_15c = ppppuStack_138;
                                                            ppppuStack_160 =
                                                                 (undefined4 ****)0x591e56;
                                                            func_0x005e5160();
                                                            pppppuVar5 = (undefined4 *****)
                                                                         ppppuStack_168;
                                                          }
                                                          else {
                                                            uVar12 = *(undefined4 *)
                                                                      (*(int *)(*puVar13 +
                                                                               iVar16 * 4) + 4);
                                                            ppppuStack_158 =
                                                                 (undefined4 ****)
                                                                 CONCAT31((int3)((uint)uVar12 >> 8),
                                                                          (char)uVar12 + '\x01');
                                                            ppppuStack_15c = ppppuStack_138;
                                                            ppppuStack_160 =
                                                                 (undefined4 ****)0x591e74;
                                                            func_0x005e5160();
                                                            pppppuVar5 = (undefined4 *****)
                                                                         ppppuStack_168;
                                                          }
                                                          break;
                                                        }
                                                        iVar16 = iVar16 + 1;
                                                        ppppuStack_13c = ppppuStack_13c + 1;
                                                      } while (iVar16 < iVar4);
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
                                  goto LAB_00592fcc;
                                }
                                ppppuStack_158 = (undefined4 ****)0x59169e;
                                func_0x004611b0();
                                ppppuStack_158 = (undefined4 ****)0x5916a9;
                                (*(code *)(*ppppuVar1[0x310])[3])();
                              }
                              ppppuStack_158 = (undefined4 ****)0x0;
                              ppppuStack_15c = (undefined4 ****)0x59166c;
                              func_0x0045c1e0();
                              ppppuStack_15c = (undefined4 ****)0x591673;
                              func_0x0048c110();
                              pppppuVar5 = (undefined4 *****)ppppuStack_168;
                            }
                          }
                        }
                      }
                    }
                    goto LAB_00592fcc;
                  }
                  ppppuStack_158 = (undefined4 ****)0x1;
                  ppppuStack_15c = (undefined4 ****)0x5914af;
                  func_0x005f21b0();
                }
                ppppuStack_164 = (undefined4 *****)0x1;
                ppppuStack_168 = (undefined4 *****)0x0;
                ppppuStack_16c = (undefined4 *****)0x0;
                pppuStack_170 = (undefined4 ****)0x591488;
                FUN_00735c50();
                pppppuVar5 = (undefined4 *****)ppppuStack_168;
              }
            }
          }
        }
      }
    }
  }
LAB_00592fcc:
  ppppuStack_168 = pppppuVar5;
  ppppuStack_158 = param_3;
  ppppuStack_15c = param_2;
  ppppuStack_160 = (undefined4 ****)0x592fde;
  uVar12 = FUN_0072fcf0();
LAB_00592fde:
  *unaff_FS_OFFSET = uStack_10;
  return uVar12;
}


