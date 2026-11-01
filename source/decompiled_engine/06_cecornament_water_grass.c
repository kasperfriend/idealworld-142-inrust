/* Authentic Ghidra 12.1.4 Decompilation — elementclient.exe (PW 1.4.2 Build 2305) */
/* Module: 06_cecornament_water_grass.c */

/* ==================================================================== */
/* Address: 0x00488e60 | Classified: ElementClient::proc_488e60 */
/* ==================================================================== */

undefined4 * __thiscall FUN_00488e60(int param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  float fStack_8;
  
  if (*(int *)(param_1 + 4) == 0) {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    return param_2;
  }
  if ((*(char *)(param_1 + 0x25) == '\0') && (*(char *)(param_1 + 0x26) == '\0')) {
    uVar1 = 1;
    if (*(char *)(param_1 + 0x27) == '\0') {
      fStack_8 = 0.0;
    }
    else {
      fStack_8 = 1.0;
    }
  }
  else {
    uVar1 = *(undefined1 *)(param_1 + 8);
    fStack_8 = (float)(*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x20)) /
               (float)*(int *)(param_1 + 0x1c);
  }
  func_0x00488420(param_2,fStack_8,uVar1);
  return param_2;
}


/* ==================================================================== */
/* Address: 0x00488f60 | Classified: A3DAutoBriskFish::vfunc_slot_2 */
/* ==================================================================== */

void __thiscall FUN_00488f60(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_3;
  *(undefined4 *)(param_1 + 0xc) = param_4;
  return;
}


/* ==================================================================== */
/* Address: 0x00488f80 | Classified: ElementClient::proc_488f80 */
/* ==================================================================== */

void __thiscall FUN_00488f80(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 0x18) = param_4;
  return;
}


/* ==================================================================== */
/* Address: 0x00488fa0 | Classified: ElementClient::proc_488fa0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00488fa0(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = &UNK_008d8ab4;
  param_1[3] = 3;
  param_1[4] = 1;
  param_1[0x10] = _DAT_009858e4;
  *param_1 = &UNK_008d8b5c;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0x3c23d70a;
  param_1[0xb] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0xc] = 0;
  param_1[0x13] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00489000 | Classified: CECCritterGroup::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_00489000(undefined4 param_1,byte param_2)

{
  FUN_00489020();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00489020 | Classified: ElementClient::proc_489020 */
/* ==================================================================== */

void __fastcall FUN_00489020(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  uint uStack_4;
  
  puStack_8 = &UNK_008aa433;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008d8b5c;
  uStack_4 = 1;
  if (param_1[0x11] != 0) {
    func_0x00641150();
    piVar1 = (int *)param_1[0x11];
    if (piVar1 != (int *)0x0) {
      func_0x006e04e0(*piVar1,*piVar1 + piVar1[3] * 4);
      if (*piVar1 != 0) {
        func_0x00763260(*piVar1);
      }
      func_0x00763260(piVar1);
    }
    param_1[0x11] = 0;
  }
  if (param_1[0x12] != 0) {
    func_0x00763260(param_1[0x12]);
    param_1[0x12] = 0;
  }
  if ((undefined4 *)param_1[0x13] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x13])(1);
    param_1[0x13] = 0;
  }
  uStack_4 = uStack_4 & 0xffffff00;
  func_0x007637f0();
  *param_1 = &UNK_008d8ac8;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x004890e0 | Classified: ElementClient::proc_4890e0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004890e0(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  char cVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *unaff_FS_OFFSET;
  uint uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 auStack_94 [4];
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 uStack_58;
  undefined4 uStack_18;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008aa516;
  *unaff_FS_OFFSET = &uStack_c;
  *(int *)(param_1 + 0x14) = param_2;
  if (*(int *)(param_2 + 0x4d4) < 5) {
    cVar4 = (**(code **)(*param_3 + 0x10))();
    if (cVar4 != '\0') {
      *(undefined4 *)(param_1 + 0x1c) = uStack_bc;
      *(undefined4 *)(param_1 + 0x20) = uStack_a4;
      *(undefined4 *)(param_1 + 0x24) = uStack_ac;
      *(undefined4 *)(param_1 + 0x2c) = uStack_a8;
      *(undefined4 *)(param_1 + 0x30) = 0;
      *(undefined4 *)(param_1 + 0x34) = uStack_b8;
      *(undefined4 *)(param_1 + 0x38) = uStack_b4;
LAB_004891c1:
      *(undefined4 *)(param_1 + 0x3c) = uStack_b0;
      cVar4 = (**(code **)(*param_3 + 0x1c))();
      if (cVar4 != '\0') {
        puVar5 = (undefined4 *)func_0x00763250();
        if (puVar5 == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          puVar5[2] = 0;
          puVar5[3] = 0;
          *puVar5 = 0;
          puVar5[1] = 0;
          uStack_10 = 1;
          puVar5[4] = 0;
          func_0x00401ca0();
          puVar5[8] = 0x41a00000;
        }
        uStack_10 = 0xffffffff;
        *(undefined4 **)(param_1 + 0x44) = puVar5;
        if (puVar5 != (undefined4 *)0x0) {
          switch(*(undefined4 *)(param_1 + 0x20)) {
          case 0:
            puVar5 = (undefined4 *)func_0x00763250();
            if (puVar5 == (undefined4 *)0x0) {
code_r0x00489315:
              *(undefined4 *)(param_1 + 0x48) = 0;
            }
            else {
              *puVar5 = &UNK_008d8dc4;
              *(undefined4 **)(param_1 + 0x48) = puVar5;
            }
            break;
          case 1:
            puVar5 = (undefined4 *)func_0x00763250();
            if (puVar5 == (undefined4 *)0x0) {
              puVar5 = (undefined4 *)0x0;
            }
            else {
              puVar5[1] = 0;
              puVar5[2] = 0;
              puVar5[3] = 0;
              *puVar5 = &UNK_008d8db4;
            }
            *(undefined4 **)(param_1 + 0x48) = puVar5;
            FUN_00488f60();
            break;
          case 2:
            puVar5 = (undefined4 *)func_0x00763250();
            if (puVar5 == (undefined4 *)0x0) {
              puVar5 = (undefined4 *)0x0;
            }
            else {
              *puVar5 = &UNK_008d8d94;
            }
            *(undefined4 **)(param_1 + 0x48) = puVar5;
            puVar5[1] = *(undefined4 *)(param_1 + 0x34);
            puVar5[2] = *(undefined4 *)(param_1 + 0x38);
            puVar5[3] = *(undefined4 *)(param_1 + 0x3c);
            break;
          case 3:
            puVar5 = (undefined4 *)func_0x00763250();
            if (puVar5 == (undefined4 *)0x0) goto code_r0x00489315;
            *puVar5 = &UNK_008d8d84;
            *(undefined4 **)(param_1 + 0x48) = puVar5;
            break;
          case 4:
            puVar5 = (undefined4 *)func_0x00763250();
            if (puVar5 == (undefined4 *)0x0) goto code_r0x00489315;
            *puVar5 = &UNK_008d8da4;
            *(undefined4 **)(param_1 + 0x48) = puVar5;
            break;
          case 5:
            iVar6 = func_0x00763250();
            uStack_10 = 2;
            if (iVar6 == 0) {
              iVar6 = 0;
            }
            else {
              iVar6 = func_0x00640710();
            }
            *(int *)(param_1 + 0x48) = iVar6;
            *(undefined4 *)(iVar6 + 4) = *(undefined4 *)(param_1 + 0x34);
            *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(param_1 + 0x38);
            uStack_10 = 0xffffffff;
            *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(param_1 + 0x3c);
            break;
          default:
            goto LAB_004897a7;
          }
          *(undefined4 *)(*(int *)(param_1 + 0x44) + 0x10) = *(undefined4 *)(param_1 + 0x48);
          func_0x00641130();
          FUN_00489a20();
          iVar6 = 0;
          *(undefined4 *)(*(int *)(param_1 + 0x44) + 0x20) = *(undefined4 *)(param_1 + 0x24);
          if (0 < *(int *)(param_1 + 0x2c)) {
            do {
              switch(*(undefined4 *)(param_1 + 0x1c)) {
              case 0:
                piVar7 = (int *)func_0x00763250();
                uStack_10 = 3;
                if (piVar7 == (int *)0x0) {
code_r0x0048959c:
                  piVar7 = (int *)0x0;
                }
                else {
                  func_0x0063e6a0();
                  uStack_10 = CONCAT31(uStack_10._1_3_,4);
                  *piVar7 = (int)&UNK_008d8d38;
                  func_0x00637b40();
                }
                break;
              case 1:
                piVar7 = (int *)func_0x00763250();
                uStack_10 = 9;
                if (piVar7 == (int *)0x0) goto code_r0x0048959c;
                func_0x0063e6a0();
                uStack_10 = CONCAT31(uStack_10._1_3_,10);
                *piVar7 = (int)&UNK_008d8c54;
                func_0x0063b160();
                break;
              case 2:
                piVar7 = (int *)func_0x00763250();
                uStack_10 = 7;
                if (piVar7 == (int *)0x0) goto code_r0x0048959c;
                func_0x0063e6a0();
                uStack_10 = CONCAT31(uStack_10._1_3_,8);
                *piVar7 = (int)&UNK_008d8ca0;
                func_0x0063d3a0();
                break;
              case 3:
                piVar7 = (int *)func_0x00763250();
                uStack_10 = 0xb;
                if (piVar7 == (int *)0x0) goto code_r0x0048959c;
                func_0x0063e6a0();
                uStack_10 = CONCAT31(uStack_10._1_3_,0xc);
                *piVar7 = (int)&UNK_008d8c08;
                func_0x0063c1b0();
                break;
              case 4:
                piVar7 = (int *)func_0x00763250();
                uStack_10 = 5;
                if (piVar7 == (int *)0x0) goto code_r0x0048959c;
                func_0x0063e6a0();
                uStack_10 = CONCAT31(uStack_10._1_3_,6);
                *piVar7 = (int)&UNK_008d8cec;
                func_0x006393a0();
                break;
              case 5:
                piVar7 = (int *)func_0x00763250();
                uStack_10 = 0xd;
                if (piVar7 == (int *)0x0) goto code_r0x0048959c;
                func_0x0063e6a0();
                uStack_10 = CONCAT31(uStack_10._1_3_,0xe);
                *piVar7 = (int)&UNK_008d8bbc;
                func_0x0063a0a0();
                break;
              case 6:
                piVar7 = (int *)func_0x00763250();
                uStack_10 = 0xf;
                if (piVar7 == (int *)0x0) goto code_r0x0048959c;
                func_0x0063e6a0();
                uStack_10 = CONCAT31(uStack_10._1_3_,0x10);
                *piVar7 = (int)&UNK_008d8b70;
                func_0x006393a0();
                break;
              default:
                goto LAB_004897a7;
              }
              uStack_10 = 0xffffffff;
              cVar4 = (**(code **)(*piVar7 + 0x30))();
              if (cVar4 == '\0') {
                if (piVar7 != (int *)0x0) {
                  (**(code **)*piVar7)();
                }
              }
              else {
                piVar7[10] = *(int *)(param_1 + 0x34);
                piVar7[0xb] = *(int *)(param_1 + 0x38);
                piVar7[0xc] = *(int *)(param_1 + 0x3c);
                cVar4 = func_0x0063e8f0();
                if (cVar4 == '\0') {
                  if (piVar7 != (int *)0x0) {
                    (**(code **)*piVar7)();
                  }
                }
                else {
                  FUN_00790aa0();
                  puVar5 = auStack_94;
                  for (iVar10 = 0x1f; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *puVar5 = 0;
                    puVar5 = puVar5 + 1;
                  }
                  iVar10 = *(int *)(_DAT_009b3eec + 0xc);
                  iVar1 = *(int *)(_DAT_009b3eec + 8);
                  auStack_94[1] = *(undefined4 *)(iVar1 + 0x260);
                  auStack_94[0] = *(undefined4 *)(iVar1 + 0x25c);
                  auStack_94[2] = *(undefined4 *)(iVar1 + 0x264);
                  auStack_94[3] = *(undefined4 *)(iVar1 + 0x268);
                  uStack_84 = *(undefined4 *)(iVar10 + 0x50);
                  uStack_80 = *(undefined4 *)(iVar10 + 0x54);
                  uStack_7c = *(undefined4 *)(iVar10 + 0x58);
                  uStack_78 = *(undefined4 *)(iVar10 + 0x14);
                  uStack_74 = *(undefined4 *)(iVar10 + 0x18);
                  uStack_70 = *(undefined4 *)(iVar10 + 0x1c);
                  uStack_6c = *(undefined4 *)(iVar10 + 0x20);
                  uStack_68 = *(undefined4 *)(iVar10 + 0x24);
                  uStack_64 = *(undefined4 *)(iVar10 + 0x28);
                  uStack_60 = *(undefined4 *)(iVar10 + 0x2c);
                  uStack_5c = *(undefined4 *)(iVar10 + 0x30);
                  uStack_58 = 0;
                  func_0x0063e8c0();
                  piVar2 = *(int **)(param_1 + 0x44);
                  uVar3 = piVar2[3];
                  if (uVar3 == piVar2[2]) {
                    if (uVar3 + 1 < 5) {
                      iVar10 = 5;
                    }
                    else {
                      iVar10 = uVar3 + 3 + (uVar3 >> 1);
                    }
                    puVar8 = (undefined4 *)func_0x00763250();
                    puVar5 = (undefined4 *)*piVar2;
                    uStack_c0 = 0;
                    puVar11 = puVar8;
                    if (piVar2[3] != 0) {
                      do {
                        if (puVar11 != (undefined4 *)0x0) {
                          uVar9 = *puVar5;
                          puVar5 = puVar5 + 1;
                          *puVar11 = uVar9;
                        }
                        uStack_c0 = uStack_c0 + 1;
                        puVar11 = puVar11 + 1;
                      } while (uStack_c0 < (uint)piVar2[3]);
                    }
                    if (*piVar2 != 0) {
                      func_0x00763260();
                    }
                    piVar2[2] = iVar10;
                    *piVar2 = (int)puVar8;
                    piVar2[1] = (int)(puVar8 + piVar2[3]);
                  }
                  if ((undefined4 *)piVar2[1] != (undefined4 *)0x0) {
                    *(undefined4 *)piVar2[1] = piVar7;
                  }
                  piVar2[3] = piVar2[3] + 1;
                  piVar2[1] = piVar2[1] + 4;
                }
              }
              iVar6 = iVar6 + 1;
            } while (iVar6 < *(int *)(param_1 + 0x2c));
          }
          func_0x00640fc0();
          uVar9 = 1;
          goto code_r0x004897a9;
        }
      }
    }
  }
  else {
    cVar4 = (**(code **)(*param_3 + 0x10))();
    if (cVar4 != '\0') {
      *(undefined4 *)(param_1 + 0x1c) = uStack_bc;
      *(undefined4 *)(param_1 + 0x20) = uStack_a4;
      *(undefined4 *)(param_1 + 0x24) = uStack_ac;
      *(undefined4 *)(param_1 + 0x2c) = uStack_a8;
      *(undefined4 *)(param_1 + 0x30) = uStack_a0;
      *(undefined4 *)(param_1 + 0x28) = uStack_9c;
      *(undefined4 *)(param_1 + 0x34) = uStack_b8;
      *(undefined4 *)(param_1 + 0x38) = uStack_b4;
      goto LAB_004891c1;
    }
  }
LAB_004897a7:
  uVar9 = 0;
code_r0x004897a9:
  *unaff_FS_OFFSET = uStack_18;
  return uVar9;
}


/* ==================================================================== */
/* Address: 0x00489800 | Classified: ElementClient::proc_489800 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00489800(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_3c [8];
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008aa52b;
  *unaff_FS_OFFSET = &uStack_c;
  if (*(int *)(param_1 + 0x44) != 0) {
    iVar1 = *(int *)(*(int *)(_DAT_009b3eec + 0x1c) + 8);
    iStack_20 = *(int *)(param_1 + 0x30);
    if (iStack_20 != 0) {
      uStack_24 = 0x489849;
      iVar2 = FUN_0041d470();
      if (iVar2 != 0) {
        if (*(int *)(param_1 + 0x4c) == 0) {
          iStack_20 = 0x28;
          uStack_24 = 0x489861;
          iVar3 = func_0x00763250();
          uStack_4 = 0;
          if (iVar3 == 0) {
            uVar4 = 0;
          }
          else {
            iStack_20 = 0x48987b;
            uVar4 = func_0x00488b80();
          }
          uStack_4 = 0xffffffff;
          *(undefined4 *)(param_1 + 0x4c) = uVar4;
          uStack_24 = 0x489892;
          iStack_20 = iVar2;
          func_0x00488bf0();
          uStack_24 = *(undefined4 *)(param_1 + 0x28);
          uStack_28 = 0x48989e;
          func_0x00488c80();
          uStack_28 = 1;
          uStack_2c = 1;
          uStack_30 = 0x4898aa;
          func_0x00488c10();
        }
        else {
          uStack_24 = 0x4898b2;
          iStack_20 = iVar2;
          func_0x00488bf0();
        }
        uStack_30 = param_2;
        uStack_34 = 0x4898bb;
        func_0x00488ce0();
        FUN_00488e60(auStack_3c);
        FUN_00489a20();
      }
    }
    uStack_24 = *(undefined4 *)(iVar1 + 0x10);
    iStack_20 = param_2;
    uStack_28 = 0x4898e1;
    uStack_28 = func_0x00641440();
    uStack_2c = 0x4898ea;
    func_0x006411e0();
  }
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00489910 | Classified: ElementClient::proc_489910 */
/* ==================================================================== */

undefined4 __thiscall FUN_00489910(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x44) != 0) {
    func_0x00641210(param_2,1);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00489a20 | Classified: ElementClient::proc_489a20 */
/* ==================================================================== */

void __thiscall FUN_00489a20(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  *(undefined4 *)(param_1 + 0x18) = param_3;
  *(undefined4 *)(param_1 + 0x1c) = param_4;
  return;
}


/* ==================================================================== */
/* Address: 0x00489a40 | Classified: A3DAutoBriskFish::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_00489a40(undefined4 param_1,byte param_2)

{
  FUN_00489a60();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00489a60 | Classified: ElementClient::proc_489a60 */
/* ==================================================================== */

void __fastcall FUN_00489a60(undefined4 *param_1)

{
  *param_1 = &UNK_008d8dd4;
  return;
}


/* ==================================================================== */
/* Address: 0x00489a70 | Classified: ElementClient::proc_489a70 */
/* ==================================================================== */

void __fastcall FUN_00489a70(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 1;
  param_1[4] = 1;
  *param_1 = &UNK_008d8e20;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0xffffffff;
  return;
}


/* ==================================================================== */
/* Address: 0x00489aa0 | Classified: ElementClient::proc_489aa0 */
/* ==================================================================== */

void __fastcall FUN_00489aa0(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 1;
  *param_1 = &UNK_008d8e34;
  param_1[5] = 0xffffffff;
  return;
}


/* ==================================================================== */
/* Address: 0x00489ad0 | Classified: CECSceneObject::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_00489ad0(undefined4 param_1,byte param_2)

{
  FUN_00489af0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00489af0 | Classified: ElementClient::proc_489af0 */
/* ==================================================================== */

void __fastcall FUN_00489af0(undefined4 *param_1)

{
  *param_1 = &UNK_008d8ac8;
  return;
}


/* ==================================================================== */
/* Address: 0x00489b00 | Classified: ElementClient::proc_489b00 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall FUN_00489b00(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 auStack_4c [16];
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008aa55e;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = &UNK_008d8ab4;
  param_1[3] = 4;
  param_1[4] = 1;
  param_1[7] = _DAT_009858e4;
  param_1[8] = _DAT_009858e4;
  uStack_4 = 2;
  *param_1 = &UNK_008d8eb8;
  param_1[5] = param_2;
  param_1[0x19] = 0;
  func_0x00787fa0(auStack_4c);
  puVar2 = auStack_4c;
  puVar3 = param_1 + 9;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  param_1[6] = 0;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00489ba0 | Classified: CECHomeOrnament::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_00489ba0(undefined4 param_1,byte param_2)

{
  FUN_00489bc0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00489bc0 | Classified: ElementClient::proc_489bc0 */
/* ==================================================================== */

void __fastcall FUN_00489bc0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  uint uStack_4;
  
  puStack_8 = &UNK_008aa583;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008d8eb8;
  uStack_4 = 1;
  func_0x007637f0();
  uStack_4 = uStack_4 & 0xffffff00;
  func_0x007637f0();
  *param_1 = &UNK_008d8ac8;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x00489c20 | Classified: ElementClient::proc_489c20 */
/* ==================================================================== */

undefined4 __thiscall
FUN_00489c20(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0x24);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_5;
    param_5 = param_5 + 1;
    puVar2 = puVar2 + 1;
  }
  func_0x007638a0(param_3);
  func_0x007638a0(param_3);
  func_0x00427700(param_1);
  return 1;
}


/* ==================================================================== */
/* Address: 0x00489c60 | Classified: CECHomeOrnament::vfunc_slot_1 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00489c60(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008aa59b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar2 = func_0x00763250(0xb0);
  uStack_4 = 0;
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = func_0x0064e5a0();
  }
  *(undefined4 *)(param_1 + 0x18) = uVar3;
  uStack_4 = 0xffffffff;
  cVar1 = func_0x0064ef00(*(undefined4 *)(_DAT_009b3eec + 8),*(undefined4 *)(param_1 + 0x1c),
                          *(undefined4 *)(param_1 + 0x20),param_1 + 0x24);
  if (cVar1 == '\0') {
    _DAT_009b3c68 = 1;
    *unaff_FS_OFFSET = unaff_EDI;
    return;
  }
  if ((char)uStack_c == '\0') {
    func_0x0064ea10(0x7d1);
  }
  *unaff_FS_OFFSET = unaff_EDI;
  return;
}


/* ==================================================================== */
/* Address: 0x00489d20 | Classified: CECHomeOrnament::vfunc_slot_4 */
/* ==================================================================== */

void __fastcall FUN_00489d20(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x18) != 0) {
    func_0x0064e7a0();
    iVar1 = *(int *)(param_1 + 0x18);
    if (iVar1 != 0) {
      func_0x0064e610();
      func_0x00763260(iVar1);
    }
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00489d60 | Classified: ElementClient::proc_489d60 */
/* ==================================================================== */

undefined4 __thiscall FUN_00489d60(int param_1,undefined4 param_2)

{
  if (((*(byte *)(param_1 + 4) & 1) != 0) && (*(int *)(param_1 + 0x18) != 0)) {
    func_0x0064ea10(param_2);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00489d80 | Classified: ElementClient::proc_489d80 */
/* ==================================================================== */

undefined4 __thiscall FUN_00489d80(int param_1,int param_2)

{
  if (((*(byte *)(param_1 + 4) & 1) != 0) && (*(int *)(param_1 + 0x18) != 0)) {
    func_0x0064eab0(*(undefined4 *)(param_2 + 4),1);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00489db0 | Classified: ElementClient::proc_489db0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00489db0(undefined4 *param_1,undefined4 param_2)

{
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = &UNK_008d8ab4;
  param_1[3] = 4;
  param_1[4] = 1;
  param_1[0x13] = _DAT_009858e4;
  *param_1 = &UNK_008d8f40;
  param_1[5] = param_2;
  param_1[0x10] = 0;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 0x11) = 0;
  *(undefined1 *)((int)param_1 + 0x45) = 0;
  *(undefined1 *)((int)param_1 + 0x46) = 0;
  *(undefined1 *)((int)param_1 + 0x47) = 0;
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined1 *)((int)param_1 + 0x49) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00489e00 | Classified: CECOrnament::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_00489e00(undefined4 param_1,byte param_2)

{
  FUN_00489e20();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00489e20 | Classified: ElementClient::proc_489e20 */
/* ==================================================================== */

void __fastcall FUN_00489e20(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008aa5b8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008d8f40;
  uStack_4 = 0;
  func_0x007637f0();
  *param_1 = &UNK_008d8ac8;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x00489e70 | Classified: elementclient::_s__s@0x489e70 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __thiscall FUN_00489e70(int param_1,int param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  float *pfVar4;
  int unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  float unaff_retaddr;
  undefined4 uStack_8c;
  float fStack_88;
  undefined4 uStack_84;
  float fStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  float fStack_70;
  undefined4 uStack_6c;
  float fStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined2 uStack_4c;
  float fStack_44;
  undefined4 uStack_40;
  float fStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  float fStack_2c;
  undefined4 uStack_28;
  undefined1 uStack_20;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  float fStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  fStack_4 = -NAN;
  puStack_8 = &UNK_008aa5f1;
  *unaff_FS_OFFSET = &uStack_c;
  if (*(int *)(param_2 + 0x4d0) < 4) {
    cVar1 = (**(code **)(*(int *)(param_2 + 0x98) + 0x10))(&uStack_38,0x2c,&uStack_7c);
    uVar2 = 0;
    if (cVar1 == '\0') goto LAB_0048a11c;
    uStack_10 = 1;
    cVar1 = (**(code **)(*(int *)(param_2 + 0x98) + 0x1c))(&stack0xffffff6c);
    if (cVar1 == '\0') {
      uStack_14 = 0xffffffff;
      func_0x007637f0();
      uVar2 = 0;
      goto LAB_0048a11c;
    }
    iVar3 = strrchr(unaff_EDI,0x5c);
    if (iVar3 != 0) {
      unaff_EDI = iVar3 + 1;
    }
    uStack_14 = CONCAT31(uStack_14._1_3_,2);
    func_0x00763d30(&stack0xffffff6c,0x9505f8,puStack_8,unaff_EDI);
    fStack_80 = fStack_3c + unaff_retaddr;
    fStack_88 = fStack_44 + fStack_4;
    uStack_84 = uStack_40;
    func_0x00646800(&fStack_88);
    uStack_8c = uStack_30;
    fStack_88 = fStack_2c;
    uStack_84 = uStack_28;
    fStack_80 = fStack_3c;
    uStack_7c = uStack_38;
    uStack_78 = uStack_34;
    FUN_0048a2d0(&fStack_80,&uStack_8c);
    uStack_20 = 1;
    func_0x007637f0();
  }
  else {
    pfVar4 = &fStack_80;
    cVar1 = (**(code **)(*(int *)(param_2 + 0x2b4) + 0x10))(&uStack_60,0x28,pfVar4);
    uVar2 = 0;
    if (cVar1 == '\0') goto LAB_0048a11c;
    uStack_10 = 0;
    cVar1 = (**(code **)(*(int *)(param_2 + 0x2b4) + 0x1c))(&stack0xffffff68);
    if (cVar1 == '\0') {
      uStack_14 = 0xffffffff;
      func_0x007637f0();
      uVar2 = 0;
      goto LAB_0048a11c;
    }
    *(char *)(param_1 + 0x44) = (char)uStack_4c;
    *(char *)(param_1 + 0x45) = (char)((ushort)uStack_4c >> 8);
    if (((*(int *)(param_2 + 0x4d8) == 0) && (*(int *)(param_2 + 0x4d4) < 0xc)) &&
       (iVar3 = strrchr(pfVar4,0x5c), iVar3 != 0)) {
      pfVar4 = (float *)(iVar3 + 1);
    }
    func_0x00763d30(param_1 + 0x4c,0x9505f8,puStack_8,pfVar4);
    *(float *)(param_1 + 0x50) = fStack_70 + fStack_4;
    *(undefined4 *)(param_1 + 0x54) = uStack_6c;
    *(float *)(param_1 + 0x58) = fStack_68 + unaff_retaddr;
    *(undefined4 *)(param_1 + 0x5c) = uStack_64;
    *(undefined4 *)(param_1 + 0x60) = uStack_60;
    *(undefined4 *)(param_1 + 100) = uStack_5c;
    *(undefined4 *)(param_1 + 0x68) = uStack_58;
    *(undefined4 *)(param_1 + 0x6c) = uStack_54;
    *(undefined4 *)(param_1 + 0x70) = uStack_50;
    func_0x00427700(param_1);
  }
  uStack_14 = 0xffffffff;
  func_0x007637f0();
  uVar2 = 1;
LAB_0048a11c:
  *unaff_FS_OFFSET = uStack_18;
  return uVar2;
}


/* ==================================================================== */
/* Address: 0x0048a140 | Classified: CECOrnament::vfunc_slot_1 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0048a140(int param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 *unaff_FS_OFFSET;
  float10 fVar7;
  undefined4 uStack_58;
  char *pcStack_54;
  undefined4 uStack_50;
  float fStack_40;
  float fStack_34;
  undefined4 uStack_2c;
  char cStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008aa60b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_50 = 0;
  pcStack_54 = (char *)0x48a167;
  pcVar2 = (char *)func_0x00763df0();
  uVar5 = 0xffffffff;
  pcVar6 = pcVar2;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  pcStack_54 = (char *)0x38;
  pcVar2[~uVar5 - 4] = 'b';
  uStack_58 = 0x48a181;
  iVar3 = func_0x00763250();
  puStack_8 = (undefined *)0x0;
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    pcStack_54 = (char *)0x48a19b;
    uVar4 = func_0x0064d8e0();
  }
  *(undefined4 *)(param_1 + 0x18) = uVar4;
  puStack_8 = (undefined *)0xffffffff;
  uStack_58 = *(undefined4 *)(_DAT_009b3eec + 8);
  pcStack_54 = pcVar2;
  cVar1 = func_0x0064e130();
  if (cVar1 == '\0') {
    _DAT_009b3c68 = 1;
    *unaff_FS_OFFSET = uStack_18;
    return;
  }
  if ((char)puStack_8 == '\0') {
    func_0x0064dc70(0x7d1);
  }
  func_0x00646800(param_1 + 0x50);
  FUN_0048a2d0(param_1 + 0x5c,param_1 + 0x68);
  func_0x0064e380(&pcStack_54);
  fVar7 = (float10)FUN_00780860(&uStack_58);
  if (fVar7 < (float10)fStack_34) {
    *(undefined1 *)(param_1 + 0x46) = 1;
  }
  if ((float10)fStack_40 < fVar7) {
    *(undefined1 *)(param_1 + 0x47) = 1;
  }
  if (cStack_1c == '\0') {
    func_0x00648610(*(undefined4 *)(param_1 + 0x18));
    *(undefined1 *)(param_1 + 0x48) = 1;
    if (*(char *)(*(int *)(param_1 + 0x14) + 0x98) != '\0') {
      func_0x00648610(*(undefined4 *)(param_1 + 0x18));
      *(undefined1 *)(param_1 + 0x49) = 1;
    }
  }
  *unaff_FS_OFFSET = uStack_2c;
  return;
}


/* ==================================================================== */
/* Address: 0x0048a2a0 | Classified: CECOrnament::vfunc_slot_4 */
/* ==================================================================== */

void __fastcall FUN_0048a2a0(int param_1)

{
  if (*(int *)(param_1 + 0x18) != 0) {
    func_0x0064daa0();
    if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x18))(1);
    }
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0048a2d0 | Classified: ElementClient::proc_48a2d0 */
/* ==================================================================== */

void __thiscall FUN_0048a2d0(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  *(undefined4 *)(param_1 + 0x28) = *param_2;
  *(undefined4 *)(param_1 + 0x2c) = param_2[1];
  *(undefined4 *)(param_1 + 0x30) = param_2[2];
  *(undefined4 *)(param_1 + 0x34) = *param_3;
  *(undefined4 *)(param_1 + 0x38) = param_3[1];
  *(undefined4 *)(param_1 + 0x3c) = param_3[2];
  return;
}


/* ==================================================================== */
/* Address: 0x0048a300 | Classified: ElementClient::proc_48a300 */
/* ==================================================================== */

undefined4 __thiscall FUN_0048a300(int param_1,undefined4 param_2)

{
  if (((*(byte *)(param_1 + 4) & 1) != 0) && (*(int *)(param_1 + 0x18) != 0)) {
    func_0x0064dc70(param_2);
    if (*(char *)(param_1 + 0x48) == '\0') {
      func_0x00648610(*(undefined4 *)(param_1 + 0x18));
      *(undefined1 *)(param_1 + 0x48) = 1;
    }
    if ((*(char *)(param_1 + 0x49) == '\0') && (*(char *)(*(int *)(param_1 + 0x14) + 0x98) != '\0'))
    {
      func_0x00648610(*(undefined4 *)(param_1 + 0x18));
      *(undefined1 *)(param_1 + 0x49) = 1;
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0048a370 | Classified: ElementClient::proc_48a370 */
/* ==================================================================== */

undefined4 __thiscall FUN_0048a370(int param_1,int param_2)

{
  if (((*(byte *)(param_1 + 4) & 1) != 0) && (*(int *)(param_1 + 0x18) != 0)) {
    func_0x0064dd10(*(undefined4 *)(param_2 + 4),1);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0048a3c0 | Classified: ElementClient::proc_48a3c0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0048a3c0(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = &UNK_008d8ab4;
  param_1[3] = 2;
  param_1[4] = 1;
  param_1[0x40] = _DAT_009858e4;
  param_1[0x41] = _DAT_009858e4;
  param_1[0x42] = _DAT_009858e4;
  param_1[0x43] = _DAT_009858e4;
  param_1[0x44] = _DAT_009858e4;
  param_1[0x45] = _DAT_009858e4;
  param_1[0x46] = _DAT_009858e4;
  *param_1 = &UNK_008d8fc8;
  param_1[5] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x0048a440 | Classified: CECScnBoxArea::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0048a440(undefined4 param_1,byte param_2)

{
  FUN_0048a460();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0048a460 | Classified: ElementClient::proc_48a460 */
/* ==================================================================== */

void __fastcall FUN_0048a460(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  puStack_8 = &UNK_008aa67c;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008d8fc8;
  iStack_4 = 6;
  func_0x007637f0();
  iStack_4._0_1_ = 5;
  func_0x007637f0();
  iStack_4._0_1_ = 4;
  func_0x007637f0();
  iStack_4._0_1_ = 3;
  func_0x007637f0();
  iStack_4._0_1_ = 2;
  func_0x007637f0();
  iStack_4._0_1_ = 1;
  func_0x007637f0();
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  func_0x007637f0();
  *param_1 = &UNK_008d8ac8;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x0048a510 | Classified: ElementClient::proc_48a510 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __thiscall FUN_0048a510(int param_1,float param_2,int *param_3)

{
  float fVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 unaff_EDI;
  int *piVar5;
  float unaff_retaddr;
  float fStack_1f0;
  float fStack_1ec;
  float fStack_1e8;
  float fStack_1e4;
  float fStack_1e0;
  float *pfStack_1dc;
  undefined4 uStack_1d8;
  float *pfStack_1d4;
  int aiStack_1bc [2];
  float fStack_1b4;
  float fStack_1b0;
  float fStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  int iStack_dc;
  float fStack_d8;
  undefined4 uStack_d4;
  float fStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_68;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  iVar3 = *(int *)((int)param_2 + 0x4d4);
  if (iVar3 < 6) {
    pfStack_1d4 = &fStack_1b4;
    pfStack_1dc = &fStack_d0;
    uStack_1d8 = 0x78;
    fStack_1e0 = 6.671453e-39;
    cVar2 = (**(code **)(*param_3 + 0x10))();
    if (cVar2 != '\0') {
      *(bool *)(param_1 + 0x18) = iStack_dc != 0;
      *(undefined4 *)(param_1 + 0x7c) = uStack_68;
      *(undefined4 *)(param_1 + 0x80) = 0;
      *(undefined4 *)(param_1 + 0x84) = uStack_9c;
      *(undefined4 *)(param_1 + 0x88) = uStack_98;
      *(undefined4 *)(param_1 + 0x8c) = uStack_94;
      *(undefined4 *)(param_1 + 0x90) = uStack_90;
      *(undefined4 *)(param_1 + 0x94) = uStack_8c;
      *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_1 + 0x84);
      *(undefined4 *)(param_1 + 0xb0) = uStack_90;
      *(undefined4 *)(param_1 + 0x98) = uStack_88;
      *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0x88);
      *(undefined4 *)(param_1 + 0xd0) = uStack_7c;
      *(undefined4 *)(param_1 + 0xd8) = uStack_7c;
      *(undefined4 *)(param_1 + 0x9c) = uStack_84;
      *(undefined4 *)(param_1 + 0xac) = uStack_94;
      *(undefined4 *)(param_1 + 0xf8) = uStack_74;
      *(undefined4 *)(param_1 + 0xa0) = uStack_80;
      *(undefined4 *)(param_1 + 0xd4) = uStack_78;
      *(undefined4 *)(param_1 + 0xdc) = uStack_78;
      *(undefined4 *)(param_1 + 0xfc) = uStack_70;
      iVar3 = *(int *)(_DAT_009b3eec + 0xc);
      *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(iVar3 + 0x50);
      *(undefined4 *)(param_1 + 200) = *(undefined4 *)(iVar3 + 0x54);
      *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(iVar3 + 0x58);
      *(undefined4 *)(param_1 + 0x11c) = 0;
      *(undefined4 *)(param_1 + 0x120) = 0;
      *(undefined4 *)(param_1 + 0x124) = 0;
      *(undefined4 *)(param_1 + 0x128) = 0;
      *(undefined4 *)(param_1 + 300) = 0;
      *(undefined4 *)(param_1 + 0x130) = 0;
      *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(param_1 + 0xd4);
      *(undefined4 *)(param_1 + 0xe0) = 0x3f800000;
      *(undefined4 *)(param_1 + 0xe4) = 0x3f800000;
      *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(param_1 + 0xd4);
      *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(param_1 + 0xd0);
      *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_1 + 0xd0);
      *(undefined4 *)(param_1 + 0xb4) = uStack_8c;
      *(undefined4 *)(param_1 + 0xb8) = uStack_88;
      *(undefined4 *)(param_1 + 0xbc) = uStack_84;
      *(undefined4 *)(param_1 + 0xc0) = uStack_80;
      *(float *)(param_1 + 0x1c) = fStack_d8 + unaff_retaddr;
      *(undefined4 *)(param_1 + 0x20) = uStack_d4;
      *(float *)(param_1 + 0x24) = fStack_d0 + param_2;
      *(undefined4 *)(param_1 + 0x70) = uStack_cc;
      *(undefined4 *)(param_1 + 0x74) = uStack_c8;
      *(undefined4 *)(param_1 + 0x78) = uStack_c4;
      *(undefined4 *)(param_1 + 0x28) = uStack_c0;
      *(undefined4 *)(param_1 + 0x2c) = uStack_bc;
      *(undefined4 *)(param_1 + 0x30) = uStack_b8;
      *(undefined4 *)(param_1 + 0x34) = uStack_b4;
      *(undefined4 *)(param_1 + 0x38) = uStack_b0;
      *(undefined4 *)(param_1 + 0x3c) = uStack_ac;
      *(undefined4 *)(param_1 + 0x40) = uStack_a8;
      *(undefined4 *)(param_1 + 0x44) = uStack_a4;
      *(undefined4 *)(param_1 + 0x48) = uStack_a0;
      fStack_1e8 = *(float *)(param_1 + 0x70);
      fStack_1e0 = fStack_1e8 * *(float *)(param_1 + 0x30);
      fStack_1e4 = fStack_1e8 * *(float *)(param_1 + 0x2c);
      fStack_1e8 = fStack_1e8 * *(float *)(param_1 + 0x28);
      fStack_1ec = 6.67234e-39;
      func_0x00401ca0();
      *(undefined4 *)(param_1 + 0x4c) = uStack_1d8;
      *(float **)(param_1 + 0x50) = pfStack_1d4;
      *(undefined4 *)(param_1 + 0x54) = unaff_EDI;
      fVar1 = *(float *)(param_1 + 0x74);
      fStack_1ec = fVar1 * *(float *)(param_1 + 0x3c);
      fStack_1f0 = fVar1 * *(float *)(param_1 + 0x38);
      func_0x00401ca0(fVar1 * *(float *)(param_1 + 0x34));
      *(float *)(param_1 + 0x58) = fStack_1e4;
      *(float *)(param_1 + 0x5c) = fStack_1e0;
      *(float **)(param_1 + 0x60) = pfStack_1dc;
      fVar1 = *(float *)(param_1 + 0x78);
      func_0x00401ca0(fVar1 * *(float *)(param_1 + 0x40),fVar1 * *(float *)(param_1 + 0x44),
                      fVar1 * *(float *)(param_1 + 0x48));
      func_0x00401cc0(&fStack_1f0);
      (**(code **)(*param_3 + 0x1c))(param_1 + 0x100);
      (**(code **)(*param_3 + 0x1c))(param_1 + 0x104);
      (**(code **)(*param_3 + 0x1c))(param_1 + 0x108);
      func_0x00763940(param_1 + 0x100);
      func_0x00763940(param_1 + 0x104);
      func_0x00763940(param_1 + 0x108);
      (**(code **)(*param_3 + 0x1c))(param_1 + 0x118);
      return 1;
    }
    return 0;
  }
  if (iVar3 < 8) {
    pfStack_1d4 = &fStack_1b4;
    pfStack_1dc = &fStack_d0;
    uStack_1d8 = 0xb8;
    fStack_1e0 = 6.672738e-39;
    cVar2 = (**(code **)(*param_3 + 0x10))();
    if (cVar2 == '\0') {
      return 0;
    }
    piVar4 = &iStack_dc;
    piVar5 = aiStack_1bc;
    for (iVar3 = 0x2e; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      piVar5 = piVar5 + 1;
    }
    uStack_fc = uStack_5c;
    uStack_f8 = uStack_58;
    uStack_ec = uStack_88;
    uStack_104 = 0x3f800000;
    uStack_100 = 0x3f800000;
    uStack_e8 = uStack_84;
    uStack_e4 = uStack_80;
    uStack_e0 = uStack_7c;
  }
  else if (iVar3 < 9) {
    pfStack_1d4 = &fStack_1b4;
    pfStack_1dc = &fStack_d0;
    uStack_1d8 = 0xc0;
    fStack_1e0 = 6.673775e-39;
    cVar2 = (**(code **)(*param_3 + 0x10))();
    if (cVar2 == '\0') {
      return 0;
    }
    piVar4 = &iStack_dc;
    piVar5 = aiStack_1bc;
    for (iVar3 = 0x30; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      piVar5 = piVar5 + 1;
    }
    uStack_ec = uStack_88;
    uStack_e8 = uStack_84;
    uStack_e4 = uStack_80;
    uStack_fc = uStack_5c;
    uStack_f8 = uStack_58;
    uStack_e0 = uStack_7c;
  }
  else if (iVar3 < 10) {
    pfStack_1d4 = &fStack_1b4;
    pfStack_1dc = &fStack_d0;
    uStack_1d8 = 200;
    fStack_1e0 = 6.673998e-39;
    cVar2 = (**(code **)(*param_3 + 0x10))();
    if (cVar2 == '\0') {
      return 0;
    }
    piVar4 = &iStack_dc;
    piVar5 = aiStack_1bc;
    for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      piVar5 = piVar5 + 1;
    }
    uStack_ec = uStack_88;
    uStack_e8 = uStack_84;
    uStack_e4 = uStack_80;
    uStack_f4 = uStack_1c;
    uStack_f0 = uStack_18;
    uStack_e0 = uStack_7c;
  }
  else if (iVar3 < 0xb) {
    pfStack_1d4 = &fStack_1b4;
    pfStack_1dc = &fStack_d0;
    uStack_1d8 = 0xd0;
    fStack_1e0 = 6.674215e-39;
    cVar2 = (**(code **)(*param_3 + 0x10))();
    if (cVar2 == '\0') {
      return 0;
    }
    piVar4 = &iStack_dc;
    piVar5 = aiStack_1bc;
    for (iVar3 = 0x34; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      piVar5 = piVar5 + 1;
    }
    uStack_e4 = uStack_80;
    uStack_e0 = uStack_7c;
    uStack_ec = uStack_88;
    uStack_e8 = uStack_84;
  }
  else {
    pfStack_1d4 = &fStack_1b4;
    pfStack_1dc = &fStack_1b0;
    uStack_1d8 = 0xe0;
    fStack_1e0 = 6.674382e-39;
    cVar2 = (**(code **)(*param_3 + 0x10))();
    if (cVar2 == '\0') {
      return 0;
    }
  }
  *(bool *)(param_1 + 0x18) = aiStack_1bc[0] != 0;
  *(undefined4 *)(param_1 + 0x7c) = uStack_120;
  *(int *)(param_1 + 0x80) = aiStack_1bc[1];
  *(undefined4 *)(param_1 + 0x84) = uStack_178;
  *(undefined4 *)(param_1 + 0x88) = uStack_174;
  *(undefined4 *)(param_1 + 0x8c) = uStack_170;
  *(undefined4 *)(param_1 + 0x90) = uStack_16c;
  *(undefined4 *)(param_1 + 0x94) = uStack_168;
  *(undefined4 *)(param_1 + 0x98) = uStack_164;
  *(undefined4 *)(param_1 + 0x9c) = uStack_160;
  *(undefined4 *)(param_1 + 0xa0) = uStack_15c;
  *(undefined4 *)(param_1 + 0xa4) = uStack_158;
  *(undefined4 *)(param_1 + 0xa8) = uStack_154;
  *(undefined4 *)(param_1 + 0xac) = uStack_150;
  *(undefined4 *)(param_1 + 0xb0) = uStack_14c;
  *(undefined4 *)(param_1 + 0xd0) = uStack_13c;
  *(undefined4 *)(param_1 + 0xd4) = uStack_138;
  *(undefined4 *)(param_1 + 0xd8) = uStack_134;
  *(undefined4 *)(param_1 + 0xdc) = uStack_130;
  *(undefined4 *)(param_1 + 0xe0) = uStack_104;
  *(undefined4 *)(param_1 + 0xe4) = uStack_100;
  *(undefined4 *)(param_1 + 0xe8) = uStack_fc;
  *(undefined4 *)(param_1 + 0xf0) = uStack_f8;
  *(undefined4 *)(param_1 + 0xec) = uStack_f4;
  *(undefined4 *)(param_1 + 0xf4) = uStack_f0;
  *(undefined4 *)(param_1 + 0xb4) = uStack_ec;
  *(undefined4 *)(param_1 + 0xb8) = uStack_e8;
  *(undefined4 *)(param_1 + 0xbc) = uStack_e4;
  *(undefined4 *)(param_1 + 0xc0) = uStack_e0;
  *(undefined4 *)(param_1 + 0xf8) = uStack_12c;
  *(undefined4 *)(param_1 + 0xfc) = uStack_128;
  *(undefined4 *)(param_1 + 0xc4) = uStack_148;
  *(undefined4 *)(param_1 + 200) = uStack_144;
  *(undefined4 *)(param_1 + 0xcc) = uStack_140;
  *(undefined4 *)(param_1 + 0x11c) = uStack_11c;
  *(undefined4 *)(param_1 + 0x120) = uStack_118;
  *(undefined4 *)(param_1 + 0x124) = uStack_114;
  *(undefined4 *)(param_1 + 0x128) = uStack_110;
  *(undefined4 *)(param_1 + 300) = uStack_10c;
  *(undefined4 *)(param_1 + 0x130) = uStack_108;
  *(float *)(param_1 + 0x1c) = fStack_1b4 + unaff_retaddr;
  *(float *)(param_1 + 0x20) = fStack_1b0;
  *(float *)(param_1 + 0x24) = fStack_1ac + param_2;
  if (*(char *)(param_1 + 0x18) == '\0') {
    *(undefined4 *)(param_1 + 0x70) = uStack_1a8;
    *(undefined4 *)(param_1 + 0x74) = uStack_1a4;
    *(undefined4 *)(param_1 + 0x78) = uStack_1a0;
  }
  else {
    *(undefined4 *)(param_1 + 0x70) = 0x447a0000;
    *(undefined4 *)(param_1 + 0x74) = 0x447a0000;
    *(undefined4 *)(param_1 + 0x78) = 0x447a0000;
  }
  *(undefined4 *)(param_1 + 0x28) = uStack_19c;
  *(undefined4 *)(param_1 + 0x2c) = uStack_198;
  *(undefined4 *)(param_1 + 0x30) = uStack_194;
  *(undefined4 *)(param_1 + 0x34) = uStack_190;
  *(undefined4 *)(param_1 + 0x38) = uStack_18c;
  *(undefined4 *)(param_1 + 0x3c) = uStack_188;
  *(undefined4 *)(param_1 + 0x40) = uStack_184;
  *(undefined4 *)(param_1 + 0x44) = uStack_180;
  *(undefined4 *)(param_1 + 0x48) = uStack_17c;
  fVar1 = *(float *)(param_1 + 0x70);
  *(float *)(param_1 + 0x50) = fVar1 * *(float *)(param_1 + 0x2c);
  *(float *)(param_1 + 0x4c) = fVar1 * *(float *)(param_1 + 0x28);
  *(float *)(param_1 + 0x54) = fVar1 * *(float *)(param_1 + 0x30);
  fVar1 = *(float *)(param_1 + 0x74);
  *(float *)(param_1 + 0x5c) = fVar1 * *(float *)(param_1 + 0x38);
  *(float *)(param_1 + 0x58) = fVar1 * *(float *)(param_1 + 0x34);
  *(float *)(param_1 + 0x60) = fVar1 * *(float *)(param_1 + 0x3c);
  fVar1 = *(float *)(param_1 + 0x78);
  *(float *)(param_1 + 0x68) = fVar1 * *(float *)(param_1 + 0x44);
  *(float *)(param_1 + 100) = fVar1 * *(float *)(param_1 + 0x40);
  *(float *)(param_1 + 0x6c) = fVar1 * *(float *)(param_1 + 0x48);
  fStack_1e0 = (float)(param_1 + 0x100);
  fStack_1e4 = 6.674731e-39;
  (**(code **)(*param_3 + 0x1c))();
  fStack_1e4 = (float)(param_1 + 0x104);
  fStack_1e8 = 6.674752e-39;
  (**(code **)(*param_3 + 0x1c))();
  fStack_1e8 = (float)(param_1 + 0x108);
  fStack_1ec = 6.674773e-39;
  (**(code **)(*param_3 + 0x1c))();
  fStack_1ec = (float)(param_1 + 0x10c);
  fStack_1f0 = 6.674794e-39;
  (**(code **)(*param_3 + 0x1c))();
  fStack_1f0 = (float)(param_1 + 0x110);
  (**(code **)(*param_3 + 0x1c))();
  (**(code **)(*param_3 + 0x1c))(param_1 + 0x114);
  (**(code **)(*param_3 + 0x1c))(param_1 + 0x118);
  fVar1 = *(float *)(param_1 + 0x84) + _DAT_008d5c28;
  if (*(float *)(param_1 + 0x88) < fVar1) {
    *(float *)(param_1 + 0x88) = fVar1;
  }
  fVar1 = *(float *)(param_1 + 0xa4) + _DAT_008d5c28;
  if (*(float *)(param_1 + 0xa8) < fVar1) {
    *(float *)(param_1 + 0xa8) = fVar1;
  }
  if (_DAT_008d689c < *(float *)(param_1 + 0x94)) {
    *(undefined4 *)(param_1 + 0x94) = 0x43c80000;
  }
  fVar1 = *(float *)(param_1 + 0x94) + _DAT_008d5c28;
  if (*(float *)(param_1 + 0x98) < fVar1) {
    *(float *)(param_1 + 0x98) = fVar1;
  }
  if (_DAT_008d689c < *(float *)(param_1 + 0xb4)) {
    *(undefined4 *)(param_1 + 0xb4) = 0x43c80000;
  }
  fVar1 = *(float *)(param_1 + 0xb4) + _DAT_008d5c28;
  if (fVar1 <= *(float *)(param_1 + 0xb8)) {
    return 1;
  }
  *(float *)(param_1 + 0xb8) = fVar1;
  return 1;
}


