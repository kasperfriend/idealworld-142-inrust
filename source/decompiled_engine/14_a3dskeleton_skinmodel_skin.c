/* Authentic Ghidra 12.1.4 Decompilation — elementclient.exe (PW 1.4.2 Build 2305) */
/* Module: 14_a3dskeleton_skinmodel_skin.c */

/* ==================================================================== */
/* Address: 0x0078e870 | Classified: Angelica3D::proc_78e870 */
/* ==================================================================== */

/* WARNING: Type propagation algorithm not settling */

undefined4 __thiscall FUN_0078e870(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int unaff_EBX;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int unaff_retaddr;
  int aiStack_34 [4];
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined4 uStack_20;
  undefined4 *puStack_14;
  int *piStack_10;
  int *piStack_c;
  
  iVar7 = *(int *)(param_2 + 0xc);
  iVar6 = 0;
  iVar4 = 0;
  aiStack_34[0] = param_1;
  func_0x0078d7a0(*(undefined4 *)(param_1 + 0xc));
  if (0 < iVar7) {
    piVar5 = *(int **)(unaff_retaddr + 8);
    do {
      iVar3 = *piVar5;
      iVar2 = *(int *)(iVar3 + 0x20) - *(int *)(iVar3 + 0x18);
      iVar3 = *(int *)(iVar3 + 0x24) - *(int *)(iVar3 + 0x1c);
      if (iVar6 < iVar2) {
        iVar6 = iVar2;
      }
      if (iVar4 < iVar3) {
        iVar4 = iVar3;
      }
      piVar5 = piVar5 + 1;
      iVar7 = iVar7 + -1;
      param_1 = unaff_EBX;
    } while (iVar7 != 0);
  }
  func_0x0078d7e0();
  piVar5 = aiStack_34;
  for (iVar7 = 10; piVar5 = (int *)((int)piVar5 + 4), iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar5 = 0;
  }
  aiStack_34[3] = -(iVar4 + 1);
  aiStack_34[1] = 0x28;
  uStack_24 = 1;
  uStack_20 = 0;
  uStack_22 = 0x20;
  aiStack_34[2] = iVar6 + 1;
  uVar1 = CreateDIBSection(*(undefined4 *)(*(int *)(param_1 + 8) + 8),aiStack_34 + 1,0,aiStack_34,0)
  ;
  *puStack_14 = uVar1;
  *piStack_10 = (iVar6 + 1) * 4;
  *piStack_c = iVar4 + 1;
  return 0;
}


/* ==================================================================== */
/* Address: 0x0078e950 | Classified: Angelica3D::proc_78e950 */
/* ==================================================================== */

void FUN_0078e950(int param_1,int *param_2,int param_3,byte *param_4,int param_5,int param_6,
                 int param_7)

{
  ushort *puVar1;
  byte *pbVar2;
  int iVar3;
  ushort *puVar4;
  
  puVar4 = (ushort *)(param_2[1] * param_3 + param_1 + *param_2 * 2);
  if (0 < param_6) {
    param_2 = (int *)param_6;
    do {
      puVar1 = puVar4;
      pbVar2 = param_4;
      iVar3 = param_5;
      if (0 < param_5) {
        do {
          if (*pbVar2 >> 4 == 0) {
            *puVar1 = 0;
          }
          else {
            *puVar1 = (ushort)(*pbVar2 >> 4) << 0xc | 0xfff;
          }
          iVar3 = iVar3 + -1;
          puVar1 = puVar1 + 1;
          pbVar2 = pbVar2 + 4;
        } while (iVar3 != 0);
      }
      puVar4 = (ushort *)((int)puVar4 + param_3);
      param_4 = param_4 + param_7;
      param_2 = (int *)((int)param_2 + -1);
    } while (param_2 != (int *)0x0);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0078e9d0 | Classified: Angelica3D::proc_78e9d0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_0078e9d0(int param_1,int param_2,uint param_3,int param_4,undefined4 param_5,char param_6)

{
  ushort uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  int unaff_retaddr;
  float fStack_14c;
  float fStack_148;
  float fStack_144;
  float fStack_140;
  int *piStack_13c;
  char cStack_138;
  float fStack_134;
  int iStack_130;
  float fStack_12c;
  float fStack_128;
  float fStack_124;
  float fStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  uint uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  int *piStack_104;
  float fStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  uint uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  float fStack_e4;
  float fStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  uint uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  int *piStack_c4;
  float fStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  uint uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  int *piStack_a4;
  char cStack_a0;
  undefined4 uStack_94;
  undefined4 uStack_90;
  uint auStack_8c [4];
  undefined4 uStack_7c;
  undefined4 uStack_78;
  uint uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  uint uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  uint uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  uint uStack_2c;
  int *piStack_28;
  int *piStack_18;
  int iStack_4;
  
  if ((*(int *)(param_1 + 4) != 0) && (*(char *)(param_1 + 0x14) == '\0')) {
    iVar3 = wcslen(param_4);
    fStack_128 = (float)iVar3;
    func_0x0078e230(param_4,iVar3);
    if (param_4 == 0) {
      param_4 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x20) + -4 +
                                 *(int *)(param_1 + 0xc) * 4) + 0x10c);
    }
    fStack_12c = (float)param_4;
    fStack_14c = (float)iStack_4;
    fStack_134 = (float)unaff_retaddr;
    fStack_128 = fStack_12c / (float)*(int *)(param_1 + 0x2c);
    if (param_6 == '\0') {
      iVar5 = 0;
      if (0 < iVar3) {
        do {
          uVar1 = *(ushort *)(param_2 + iVar5 * 2);
          for (puVar2 = *(undefined4 **)
                         (*(int *)(param_1 + 0x58) + ((uint)uVar1 % *(uint *)(param_1 + 100)) * 4);
              puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
            if (*(ushort *)(puVar2 + 2) == uVar1) {
              piStack_13c = puVar2 + 1;
              cStack_138 = '\x01';
              goto LAB_0078eada;
            }
          }
          func_0x004445b0(&stack0xfffffeac,&stack0xfffffeb3);
          if (cStack_138 != '\0') {
LAB_0078eada:
            iVar3 = *piStack_13c;
            fStack_124 = fStack_14c - _DAT_008eff98;
            fStack_120 = fStack_134 - _DAT_008eff98;
            uStack_108 = *(undefined4 *)(iVar3 + 0xc);
            uStack_10c = *(undefined4 *)(iVar3 + 8);
            fStack_144 = (float)(*(int *)(iVar3 + 0x20) - *(int *)(iVar3 + 0x18)) * fStack_128 +
                         fStack_14c;
            uStack_11c = param_5;
            uStack_118 = 0x3f800000;
            uStack_114 = param_3;
            uStack_110 = 0xff000000;
            piStack_104 = (int *)(fStack_144 - _DAT_008eff98);
            uStack_e8 = *(undefined4 *)(iVar3 + 0xc);
            uStack_ec = *(undefined4 *)(iVar3 + 0x10);
            uStack_f8 = 0x3f800000;
            uStack_fc = param_5;
            uStack_f4 = param_3;
            fStack_e0 = (fStack_134 + fStack_12c) - _DAT_008eff98;
            uStack_f0 = 0xff000000;
            uStack_c8 = *(undefined4 *)(iVar3 + 0x14);
            uStack_cc = *(undefined4 *)(iVar3 + 8);
            uStack_dc = param_5;
            uStack_d8 = 0x3f800000;
            uStack_d4 = param_3;
            uStack_d0 = 0xff000000;
            uStack_a8 = *(undefined4 *)(iVar3 + 0x14);
            uStack_ac = *(undefined4 *)(iVar3 + 0x10);
            uStack_bc = param_5;
            uStack_b8 = 0x3f800000;
            uStack_b4 = param_3;
            uStack_b0 = 0xff000000;
            fStack_100 = fStack_120;
            fStack_e4 = fStack_124;
            piStack_c4 = piStack_104;
            fStack_c0 = fStack_e0;
            piStack_a4 = piStack_104;
            piStack_28 = piStack_104;
            FUN_0078f480(*(undefined4 *)(iVar3 + 4),&fStack_124,1);
            fStack_14c = fStack_144;
          }
          iVar5 = iVar5 + 1;
          if (iStack_130 <= iVar5) {
            return 1;
          }
        } while( true );
      }
    }
    else {
      iVar3 = func_0x00892e78();
      uStack_2c = param_3;
      auStack_8c[0] = (100 < iVar3) - 1 & 0xff;
      auStack_8c[1] = 0xffffffff;
      auStack_8c[2] = 0xffffffff;
      auStack_8c[0] = ((auStack_8c[0] | 0xffffff00) << 8 | auStack_8c[0]) << 8 | auStack_8c[0];
      uStack_94 = 1;
      uStack_90 = 1;
      uStack_7c = 1;
      uStack_78 = 0xffffffff;
      uStack_70 = 0xffffffff;
      uStack_6c = 1;
      uStack_64 = 1;
      uStack_60 = 0;
      uStack_58 = 0xffffffff;
      uStack_54 = 0;
      uStack_4c = 0;
      uStack_48 = 0xffffffff;
      uStack_40 = 0;
      uStack_3c = 1;
      uStack_34 = 0;
      uStack_30 = 0;
      iVar3 = 0;
      auStack_8c[3] = auStack_8c[0];
      uStack_74 = auStack_8c[0];
      uStack_68 = auStack_8c[0];
      uStack_5c = auStack_8c[0];
      uStack_50 = auStack_8c[0];
      uStack_44 = auStack_8c[0];
      uStack_38 = auStack_8c[0];
      if (0 < iStack_130) {
        do {
          uVar1 = *(ushort *)(param_2 + iVar3 * 2);
          for (puVar2 = *(undefined4 **)
                         (*(int *)(param_1 + 0x58) + ((uint)uVar1 % *(uint *)(param_1 + 100)) * 4);
              puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
            if (*(ushort *)(puVar2 + 2) == uVar1) {
              piStack_a4 = puVar2 + 1;
              cStack_a0 = '\x01';
              goto LAB_0078ee4d;
            }
          }
          fStack_148 = 0.0;
          func_0x004445b0(&fStack_148,&stack0xfffffeb3);
          if (cStack_a0 != '\0') {
LAB_0078ee4d:
            puVar7 = auStack_8c;
            iVar6 = 9;
            iVar5 = *piStack_a4;
            fStack_148 = (float)(*(int *)(iVar5 + 0x20) - *(int *)(iVar5 + 0x18)) * fStack_128;
            do {
              fStack_140 = (float)func_0x00892e78();
              iVar4 = func_0x00892e78();
              uStack_114 = *puVar7;
              fStack_144 = (float)(int)fStack_140;
              fStack_124 = (float)(int)fStack_140 - _DAT_008eff98;
              fStack_140 = (float)iVar4;
              fStack_120 = (float)iVar4 - _DAT_008eff98;
              uStack_108 = *(undefined4 *)(iVar5 + 0xc);
              uStack_10c = *(undefined4 *)(iVar5 + 8);
              uStack_11c = param_5;
              uStack_118 = 0x3f800000;
              uStack_110 = 0xff000000;
              piStack_13c = (int *)((fStack_144 + fStack_148) - _DAT_008eff98);
              uStack_e8 = *(undefined4 *)(iVar5 + 0xc);
              uStack_ec = *(undefined4 *)(iVar5 + 0x10);
              uStack_f8 = 0x3f800000;
              uStack_fc = param_5;
              fStack_e0 = (fStack_140 + fStack_12c) - _DAT_008eff98;
              uStack_f0 = 0xff000000;
              uStack_c8 = *(undefined4 *)(iVar5 + 0x14);
              uStack_cc = *(undefined4 *)(iVar5 + 8);
              uStack_dc = param_5;
              uStack_d8 = 0x3f800000;
              uStack_d0 = 0xff000000;
              uStack_a8 = *(undefined4 *)(iVar5 + 0x14);
              uStack_ac = *(undefined4 *)(iVar5 + 0x10);
              uStack_bc = param_5;
              uStack_b8 = 0x3f800000;
              uStack_b0 = 0xff000000;
              piStack_104 = piStack_13c;
              fStack_100 = fStack_120;
              uStack_f4 = uStack_114;
              fStack_e4 = fStack_124;
              uStack_d4 = uStack_114;
              piStack_c4 = piStack_13c;
              fStack_c0 = fStack_e0;
              uStack_b4 = uStack_114;
              piStack_28 = piStack_13c;
              piStack_18 = piStack_13c;
              FUN_0078f480(*(undefined4 *)(iVar5 + 4),&fStack_124,1);
              puVar7 = puVar7 + 3;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < iStack_130);
      }
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0078f070 | Classified: Angelica3D::proc_78f070 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0078f070(int param_1,undefined4 param_2,int param_3,float param_4)

{
  ushort uVar1;
  float fVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  float fVar6;
  int iVar7;
  float10 fVar8;
  float fStack_120;
  undefined4 uStack_11c;
  undefined4 *puStack_118;
  float fStack_114;
  float *pfStack_110;
  float fVar9;
  int iStack_fc;
  float fStack_f8;
  float fStack_f4;
  undefined4 uStack_e8;
  int iStack_e4;
  undefined4 uStack_e0;
  float fStack_dc;
  float fStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_cc;
  float fStack_c8;
  float fStack_c4;
  float fStack_c0;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  float fStack_84;
  float fStack_80;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  float fStack_64;
  float fStack_60;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  float fStack_4c;
  undefined4 uStack_48;
  float fStack_44;
  float fStack_34;
  undefined4 uStack_10;
  int iStack_c;
  int iStack_4;
  
  if ((*(int *)(param_1 + 4) != 0) && (*(char *)(param_1 + 0x14) == '\0')) {
    pfStack_110 = &fStack_dc;
    fStack_114 = param_4;
    puStack_118 = (undefined4 *)0x78f0ad;
    func_0x00787000();
    if ((_DAT_008effc4 <= fStack_dc) && (fStack_dc <= _DAT_008effa0)) {
      puStack_118 = (undefined4 *)iStack_4;
      uStack_11c = (undefined4 *)0x78f0e7;
      fVar6 = (float)wcslen();
      puStack_118 = &uStack_e8;
      uStack_11c = &uStack_b4;
      fStack_120 = fVar6;
      fStack_c8 = fVar6;
      func_0x0078d740(*(undefined4 *)(param_1 + 0xc),iStack_4);
      if (iStack_c == 0) {
        iStack_c = iStack_fc;
      }
      pfStack_110 = (float *)(float)iStack_c;
      puStack_118 = (undefined4 *)((float)(int)fStack_c8 * ((float)pfStack_110 / (float)iStack_fc));
      fVar8 = (float10)floor((double)(fStack_f8 - (float)puStack_118 * _DAT_008eff98));
      fVar9 = (float)fVar8;
      fVar8 = (float10)floor((double)(fStack_f4 - (float)pfStack_110 * _DAT_008eff98));
      if (_DAT_008effc4 <= fVar9 + (float)puStack_118) {
        if (_DAT_008effc4 <= (float)pfStack_110 + (float)fVar8) {
          if (fVar9 <= (float)*(uint *)(param_3 + 0x1c)) {
            fVar2 = *(float *)(param_3 + 0x20);
            if ((float)fVar8 <= (float)(uint)fVar2) {
              func_0x0078e230(iStack_4,fVar6);
              puVar5 = puStack_118;
              iVar7 = 0;
              if (0 < (int)fVar6) {
                do {
                  uVar1 = *(ushort *)(iStack_4 + iVar7 * 2);
                  for (puVar3 = *(undefined4 **)
                                 (*(int *)(param_1 + 0x58) +
                                 ((uint)uVar1 % *(uint *)(param_1 + 100)) * 4);
                      puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
                    if (*(ushort *)(puVar3 + 2) == uVar1) {
                      pfStack_110 = (float *)(puVar3 + 1);
                      fVar9 = 1.4013e-45;
                      goto LAB_0078f261;
                    }
                  }
                  uStack_11c = (undefined4 *)((uint)uStack_11c & 0xffffff);
                  fStack_120 = 0.0;
                  func_0x004445b0(&fStack_120,(int)&uStack_11c + 3);
                  if (SUB41(fVar9,0) != '\0') {
LAB_0078f261:
                    iVar4 = (int)*pfStack_110;
                    fStack_dc = *(float *)(iVar4 + 0xc);
                    puStack_118 = *(undefined4 **)(iVar4 + 8);
                    uStack_b8 = 0x3f800000;
                    uStack_b4 = uStack_10;
                    uStack_b0 = 0xff000000;
                    fStack_c4 = fStack_114 - _DAT_008eff98;
                    fStack_c0 = fVar2 - _DAT_008eff98;
                    fStack_120 = (float)(*(int *)(iVar4 + 0x20) - *(int *)(iVar4 + 0x18)) *
                                 fStack_f4 + fStack_114;
                    uStack_e8 = *(undefined4 *)(iVar4 + 0xc);
                    uStack_d4 = *(undefined4 *)(iVar4 + 0x10);
                    uStack_98 = 0x3f800000;
                    fStack_d8 = fStack_120 - _DAT_008eff98;
                    uStack_94 = uStack_10;
                    uStack_90 = 0xff000000;
                    fStack_80 = ((float)puVar5 + fVar2) - _DAT_008eff98;
                    uStack_cc = *(undefined4 *)(iVar4 + 0x14);
                    uStack_e0 = *(undefined4 *)(iVar4 + 8);
                    uStack_78 = 0x3f800000;
                    uStack_74 = uStack_10;
                    uStack_70 = 0xff000000;
                    uStack_48 = *(undefined4 *)(iVar4 + 0x14);
                    fStack_c8 = *(float *)(iVar4 + 0x10);
                    uStack_50 = 0xff000000;
                    uStack_58 = 0x3f800000;
                    uStack_54 = uStack_10;
                    fStack_ac = (float)puStack_118;
                    fStack_a8 = fStack_dc;
                    fStack_a4 = fStack_d8;
                    fStack_a0 = fStack_c0;
                    uStack_8c = uStack_d4;
                    uStack_88 = uStack_e8;
                    fStack_84 = fStack_c4;
                    uStack_6c = uStack_e0;
                    uStack_68 = uStack_cc;
                    fStack_64 = fStack_d8;
                    fStack_60 = fStack_80;
                    fStack_4c = fStack_c8;
                    fStack_44 = fStack_d8;
                    fStack_34 = fStack_d8;
                    FUN_0078f480(*(undefined4 *)(iVar4 + 4),&fStack_c4,1);
                    fStack_114 = fStack_120;
                  }
                  iVar7 = iVar7 + 1;
                } while (iVar7 < iStack_e4);
              }
            }
          }
        }
      }
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0078f480 | Classified: Angelica3D::proc_78f480 */
/* ==================================================================== */

undefined4 __thiscall FUN_0078f480(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x40) + param_2 * 4);
  uVar1 = param_4 * 4;
  if ((*(int *)(param_1 + 0x1c) < (int)(*(int *)(iVar2 + 8) + uVar1)) ||
     (*(int *)(param_1 + 0x20) < *(int *)(iVar2 + 0xc) + param_4 * 6)) {
    FUN_0078f500(param_2);
  }
  puVar4 = (undefined4 *)(*(int *)(iVar2 + 8) * 0x20 + *(int *)(iVar2 + 4));
  for (iVar3 = (uVar1 & 0x7ffffff) << 3; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *param_3;
    param_3 = param_3 + 1;
    puVar4 = puVar4 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar4 = *(undefined1 *)param_3;
    param_3 = (undefined4 *)((int)param_3 + 1);
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  iVar3 = *(int *)(iVar2 + 0xc) + param_4 * 6;
  *(uint *)(iVar2 + 8) = *(int *)(iVar2 + 8) + uVar1;
  *(int *)(iVar2 + 0xc) = iVar3;
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x0078f500 | Classified: elementclient::A3DFont__FlushOutputBuf__failed_t@0x78f500 */
/* ==================================================================== */

uint __thiscall FUN_0078f500(int param_1,int param_2)

{
  undefined4 *puVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  undefined1 auStack_8 [4];
  uint uStack_4;
  
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 0x164);
  uVar8 = FUN_00766250();
  iVar4 = (int)uVar8;
  *(undefined8 *)(iVar5 + 0x6c0) = uVar8;
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x40) + param_2 * 4);
  uVar3 = puVar1[2];
  if (uVar3 != 0) {
    iVar4 = 0;
    if (puVar1[3] != 0) {
      puVar1[2] = 0;
      puVar1[3] = 0;
      uStack_4 = uVar3;
      cVar2 = func_0x007855c0(0,uVar3 << 5,auStack_8);
      if (cVar2 == '\0') {
        uVar3 = func_0x007647d0(0x9d2f20,0x98ae84);
        return uVar3 & 0xffffff00;
      }
      puVar6 = (undefined4 *)puVar1[1];
      puVar7 = (undefined4 *)0x0;
      for (iVar5 = (uVar3 & 0x7ffffff) << 3; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
      func_0x007856d0();
      if (*(char *)(param_1 + 0x15) == '\0') {
        uVar9 = 1;
      }
      else {
        uVar9 = 2;
      }
      func_0x00779f60(0,uVar9);
      func_0x0077a2c0(5);
      iVar5 = 6;
      func_0x0077a2f0(6);
      uVar9 = 3;
      func_0x0077a0e0(0,3,3);
      (**(code **)(*(int *)*puVar1 + 0x18))(0);
      func_0x00785550(0,1);
      uVar3 = func_0x0077a590(4,0,uVar9,0,iVar5 / 3);
      if ((char)uVar3 == '\0') {
        return uVar3;
      }
      (**(code **)(*(int *)*puVar1 + 0x1c))(0);
      func_0x0077a210(1);
      func_0x00779f60(0,2);
      func_0x0077a0e0(0,1,1);
      iVar5 = *(int *)(*(int *)(param_1 + 4) + 0x164);
      iVar4 = FUN_00766250();
      iVar4 = iVar4 - *(int *)(iVar5 + 0x6c0);
      *(int *)(iVar5 + 0x6c8) = *(int *)(iVar5 + 0x6c8) + iVar4;
    }
  }
  return CONCAT31((int3)((uint)iVar4 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x0078f690 | Classified: Angelica3D::proc_78f690 */
/* ==================================================================== */

undefined4 __fastcall FUN_0078f690(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if ((*(int *)(param_1 + 4) != 0) &&
     (iVar1 = CONCAT31((int3)((uint)*(int *)(param_1 + 4) >> 8),*(char *)(param_1 + 0x14)),
     *(char *)(param_1 + 0x14) == '\0')) {
    iVar1 = *(int *)(param_1 + 0x44);
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        FUN_0078f500(iVar2);
        iVar1 = *(int *)(param_1 + 0x44);
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x0078f6c0 | Classified: Angelica3D::proc_78f6c0 */
/* ==================================================================== */

undefined4 __fastcall FUN_0078f6c0(int param_1)

{
  int iVar1;
  undefined4 in_EAX;
  int iVar2;
  
  iVar2 = CONCAT31((int3)((uint)in_EAX >> 8),*(char *)(param_1 + 0x14));
  if ((*(char *)(param_1 + 0x14) == '\0') && (iVar2 = 0, 0 < *(int *)(param_1 + 0x44))) {
    do {
      iVar2 = iVar2 + 1;
      iVar1 = *(int *)(*(int *)(param_1 + 0x40) + -4 + iVar2 * 4);
      *(undefined4 *)(iVar1 + 8) = 0;
      *(undefined4 *)(iVar1 + 0xc) = 0;
    } while (iVar2 < *(int *)(param_1 + 0x44));
  }
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x0078f6f0 | Classified: Angelica3D::proc_78f6f0 */
/* ==================================================================== */

void __fastcall FUN_0078f6f0(undefined4 *param_1)

{
  *param_1 = &UNK_008f109c;
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
/* Address: 0x0078f720 | Classified: Angelica3D::proc_78f720 */
/* ==================================================================== */

void __fastcall FUN_0078f720(undefined4 *param_1)

{
  *param_1 = &UNK_008f10a0;
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
/* Address: 0x0078f750 | Classified: Angelica3D::proc_78f750 */
/* ==================================================================== */

undefined4 __thiscall FUN_0078f750(undefined4 param_1,byte param_2)

{
  FUN_0078f6f0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0078f770 | Classified: Angelica3D::proc_78f770 */
/* ==================================================================== */

undefined4 __thiscall FUN_0078f770(undefined4 param_1,byte param_2)

{
  FUN_0078f720();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0078f790 | Classified: Angelica3D::proc_78f790 */
/* ==================================================================== */

void __thiscall FUN_0078f790(int param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  uVar2 = *(uint *)(param_1 + 0x14);
  if (uVar2 < param_2) {
    iVar4 = 0;
    do {
      if (param_2 < *(uint *)(&UNK_008f1028 + iVar4 * 4)) {
        param_2 = *(uint *)(&UNK_008f1028 + iVar4 * 4);
        goto LAB_0078f7c7;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x1c);
    param_2 = 0xffffffff;
LAB_0078f7c7:
    if (uVar2 < param_2) {
      if (param_2 == 0) {
        puVar8 = (undefined4 *)0x0;
        puVar5 = puVar8;
      }
      else {
        puVar5 = (undefined4 *)func_0x00763250(param_2 * 4);
        uVar6 = param_2;
        puVar7 = puVar5;
        do {
          puVar8 = puVar7 + 1;
          if (puVar7 != (undefined4 *)0x0) {
            *puVar7 = 0;
          }
          uVar6 = uVar6 - 1;
          puVar7 = puVar8;
        } while (uVar6 != 0);
      }
      uVar6 = 0;
      if (uVar2 != 0) {
        iVar4 = *(int *)(param_1 + 8);
        do {
          puVar7 = *(undefined4 **)(iVar4 + uVar6 * 4);
          while (puVar7 != (undefined4 *)0x0) {
            uVar1 = *(ushort *)(puVar7 + 2);
            *(undefined4 *)(iVar4 + uVar6 * 4) = *puVar7;
            *puVar7 = puVar5[(uint)uVar1 % param_2];
            puVar5[(uint)uVar1 % param_2] = puVar7;
            iVar4 = *(int *)(param_1 + 8);
            puVar7 = *(undefined4 **)(iVar4 + uVar6 * 4);
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar2);
      }
      puVar7 = *(undefined4 **)(param_1 + 8);
      *(undefined4 **)(param_1 + 8) = puVar5;
      puVar3 = *(undefined4 **)(param_1 + 0xc);
      *(undefined4 **)(param_1 + 0xc) = puVar8;
      iVar4 = *(int *)(param_1 + 0x14);
      *(uint *)(param_1 + 0x14) = param_2;
      *(uint *)(param_1 + 0x10) = param_2;
      puVar5 = puVar7 + iVar4;
      puVar8 = puVar7;
      if (puVar7 != puVar5) {
        for (; puVar5 < puVar3; puVar5 = puVar5 + 1) {
          *puVar8 = *puVar5;
          puVar8 = puVar8 + 1;
        }
      }
      if (puVar7 != (undefined4 *)0x0) {
        func_0x00763260(puVar7);
      }
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0078f8b0 | Classified: Angelica3D::proc_78f8b0 */
/* ==================================================================== */

uint __thiscall FUN_0078f8b0(int param_1,ushort *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (uint)*param_2 % *(uint *)(param_1 + 0x14);
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 8) + uVar4 * 4);
  puVar2 = puVar1;
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)func_0x00763250(0xc);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2[1] = *param_3;
        *(ushort *)(puVar2 + 2) = *param_2;
        *puVar2 = puVar1;
      }
      *(undefined4 **)(*(int *)(param_1 + 8) + uVar4 * 4) = puVar2;
      iVar3 = *(int *)(param_1 + 4) + 1;
      *(int *)(param_1 + 4) = iVar3;
      return CONCAT31((int3)((uint)iVar3 >> 8),1);
    }
    if (*(ushort *)(puVar2 + 2) == *param_2) break;
    puVar2 = (undefined4 *)*puVar2;
  }
  return (uint)puVar2 & 0xffffff00;
}


/* ==================================================================== */
/* Address: 0x0078f930 | Classified: Angelica3D::proc_78f930 */
/* ==================================================================== */

undefined4 * __fastcall FUN_0078f930(undefined4 *param_1)

{
  func_0x00773b00();
  *param_1 = &UNK_008f1118;
  param_1[1] = 0x27;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0078f950 | Classified: Angelica3D::proc_78f950 */
/* ==================================================================== */

undefined1 __thiscall
FUN_0078f950(int *param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int aiStack_60 [4];
  undefined4 uStack_50;
  int iStack_4;
  
  uStack_50 = param_5;
  aiStack_60[3] = param_4;
  aiStack_60[2] = param_2;
  aiStack_60[1] = 0x78f96c;
  cVar1 = func_0x00773c80();
  if (cVar1 == '\0') {
    return 0;
  }
  param_1[0x9c] = iStack_4;
  aiStack_60[1] = param_5;
  param_1[0x9e] = param_3;
  aiStack_60[0] = param_4;
  param_1[0x9d] = iStack_4;
  func_0x007f5a8d(&stack0xffffffb4,iStack_4,param_3);
  piVar3 = aiStack_60;
  piVar4 = param_1 + 0x2a;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar4 = *piVar3;
    piVar3 = piVar3 + 1;
    piVar4 = piVar4 + 1;
  }
  func_0x007885a0(param_1 + 0x2a,param_1 + 0x5a);
  func_0x00787460();
  func_0x007c72c0(6);
  func_0x007c72c0(6);
  (**(code **)(*param_1 + 0x2c))();
  return 1;
}


/* ==================================================================== */
/* Address: 0x0078fac0 | Classified: Angelica3D::proc_78fac0 */
/* ==================================================================== */

undefined4 __fastcall FUN_0078fac0(int param_1)

{
  undefined4 uVar1;
  undefined4 auStack_48 [16];
  undefined4 uStack_8;
  
  uStack_8 = 0x78fac8;
  FUN_0078fad0();
  if (*(int *)(param_1 + 0xc) != 0) {
    if (*(char *)(param_1 + 0x22c) == '\0') {
      auStack_48[0] = 3;
    }
    else {
      auStack_48[0] = 2;
    }
    func_0x0077a540();
    func_0x00779d00(param_1 + 0x68);
    uVar1 = func_0x007873a0(auStack_48,param_1 + 0xa8,param_1 + 0x128);
    func_0x00779d50(uVar1);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0078fad0 | Classified: Angelica3D::proc_78fad0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0078fad0(int *param_1)

{
  float fVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iStack_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  int iStack_f0;
  int iStack_ec;
  int iStack_e8;
  int iStack_e4;
  int iStack_e0;
  int iStack_dc;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  undefined1 uStack_c8;
  undefined1 uStack_c4;
  int aiStack_c0 [12];
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined1 auStack_80 [64];
  undefined1 auStack_40 [60];
  undefined4 uStack_4;
  
  if ((char)param_1[0x8b] != '\0') {
    piVar2 = (int *)func_0x007873a0(auStack_80,param_1 + 0x7b,param_1[0x7a] + 0x68);
    piVar4 = param_1 + 0x1a;
    piVar8 = piVar4;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *piVar8 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar8 = piVar8 + 1;
    }
    uVar3 = func_0x007873a0(auStack_80,piVar4,param_1 + 0x2a,param_1 + 0x4a);
    piVar2 = (int *)func_0x007873a0(auStack_40,uVar3);
    piVar8 = param_1 + 0x3a;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *piVar8 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar8 = piVar8 + 1;
    }
    func_0x007885a0(param_1 + 0x3a,param_1 + 0x6a);
    fStack_fc = (float)param_1[0x26];
    iStack_e4 = param_1[0x1c];
    iStack_e0 = param_1[0x20];
    iStack_dc = param_1[0x24];
    iStack_f0 = param_1[0x1b];
    iStack_ec = param_1[0x1f];
    iStack_e8 = param_1[0x23];
    fStack_f8 = (float)param_1[0x27];
    fStack_f4 = (float)param_1[0x28];
    piVar2 = aiStack_c0;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *piVar2 = *piVar4;
      piVar4 = piVar4 + 1;
      piVar2 = piVar2 + 1;
    }
    uStack_88 = 0;
    uStack_8c = 0;
    uStack_90 = 0;
    piVar4 = (int *)func_0x00788330(auStack_40,aiStack_c0);
    fStack_d8 = fStack_fc * _DAT_008f01f4;
    piVar2 = aiStack_c0;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *piVar2 = *piVar4;
      piVar4 = piVar4 + 1;
      piVar2 = piVar2 + 1;
    }
    fStack_d4 = fStack_f8 * _DAT_008f01f4;
    fStack_d0 = fStack_f4 * _DAT_008f01f4;
    piVar4 = (int *)func_0x007872d0(&fStack_fc,aiStack_c0,&fStack_d8);
    iVar5 = *piVar4;
    iVar6 = piVar4[2];
    iVar7 = piVar4[1];
    param_1[8] = iStack_e4;
    param_1[9] = iStack_e0;
    param_1[10] = iStack_dc;
    param_1[0xb] = iStack_f0;
    param_1[0xc] = iStack_ec;
    param_1[0xd] = iStack_e8;
    param_1[7] = iVar6;
    param_1[5] = iVar5;
    iVar6 = 0;
    param_1[6] = iVar7;
    iStack_100 = 0;
    fStack_d0 = (float)param_1[0xc] * (float)param_1[8] - (float)param_1[9] * (float)param_1[0xb];
    param_1[0x11] =
         (int)((float)param_1[9] * (float)param_1[0xd] - (float)param_1[0xc] * (float)param_1[10]);
    param_1[0x13] = (int)fStack_d0;
    param_1[0x12] =
         (int)((float)param_1[10] * (float)param_1[0xb] - (float)param_1[8] * (float)param_1[0xd]);
    iVar5 = param_1[0x7a];
    if (0 < param_1[0x93]) {
      do {
        iVar7 = *(int *)(iVar5 + 0x248) + iVar6;
        func_0x00774930(iVar7);
        uStack_c8 = *(undefined1 *)(iVar7 + 0x14);
        iVar7 = param_1[0x92] + iVar6;
        func_0x00774930(&iStack_dc);
        iVar6 = iVar6 + 0x18;
        *(undefined1 *)(iVar7 + 0x14) = uStack_c4;
        iStack_100 = iStack_100 + 1;
      } while (iStack_100 < param_1[0x93]);
    }
    (**(code **)(*param_1 + 0x30))();
    return 1;
  }
  if ((float)param_1[0x9d] != (float)param_1[0x9c]) {
    if ((float)param_1[0x9c] <= (float)param_1[0x9d]) {
      fVar1 = (float)param_1[0x9c] + _DAT_008f092c;
      param_1[0x9c] = (int)fVar1;
      if ((float)param_1[0x9d] < fVar1) {
        param_1[0x9c] = param_1[0x9d];
      }
    }
    else {
      fVar1 = (float)param_1[0x9c] - _DAT_008f092c;
      param_1[0x9c] = (int)fVar1;
      if (fVar1 < (float)param_1[0x9d]) {
        param_1[0x9c] = param_1[0x9d];
        uStack_4 = 0x78fb37;
        (**(code **)(*param_1 + 0x28))();
        return 1;
      }
    }
    uStack_4 = 0x78fb66;
    (**(code **)(*param_1 + 0x28))();
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0078fea0 | Classified: Angelica3D::proc_78fea0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_0078fea0(int param_1,float param_2,undefined4 param_3,undefined4 param_4,float param_5)

{
  if (_DAT_008effc4 < param_2) {
    *(float *)(param_1 + 0x270) = param_2;
    *(float *)(param_1 + 0x274) = param_2;
  }
  if (_DAT_008effc4 < param_5) {
    *(float *)(param_1 + 0x278) = param_5;
  }
  func_0x00774860(param_3,param_4,1);
  return;
}


/* ==================================================================== */
/* Address: 0x0078ff00 | Classified: Angelica3D::proc_78ff00 */
/* ==================================================================== */

undefined4 __thiscall FUN_0078ff00(undefined4 param_1,byte param_2)

{
  FUN_0078ff20();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0078ff20 | Classified: Angelica3D::proc_78ff20 */
/* ==================================================================== */

void __fastcall FUN_0078ff20(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  uint uStack_4;
  
  *param_1 = &UNK_008f1118;
  puStack_8 = &UNK_008cc346;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f0750;
  param_1[0x96] = &UNK_008f0788;
  uStack_4 = 1;
  param_1[0x97] = &UNK_008f0784;
  if (param_1[0x98] != 0) {
    func_0x00763260(param_1[0x98]);
    param_1[0x98] = 0;
  }
  param_1[0x9a] = 0;
  param_1[0x99] = 0;
  param_1[0x90] = &UNK_008f0788;
  uStack_4 = uStack_4 & 0xffffff00;
  param_1[0x91] = &UNK_008f0784;
  if (param_1[0x92] != 0) {
    func_0x00763260(param_1[0x92]);
    param_1[0x92] = 0;
  }
  param_1[0x94] = 0;
  param_1[0x93] = 0;
  uStack_4 = 0xffffffff;
  *param_1 = &UNK_008d6410;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x0078ff30 | Classified: Angelica3D::proc_78ff30 */
/* ==================================================================== */

undefined4 * __fastcall FUN_0078ff30(undefined4 *param_1)

{
  func_0x00773b00();
  *param_1 = &UNK_008f11c0;
  param_1[1] = 0x28;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0078ff50 | Classified: Angelica3D::proc_78ff50 */
/* ==================================================================== */

undefined1 __thiscall FUN_0078ff50(int *param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int unaff_retaddr;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  int aiStack_68 [5];
  undefined4 uStack_54;
  undefined4 uStack_50;
  int iStack_4;
  
  uStack_50 = in_stack_0000001c;
  uStack_54 = in_stack_00000018;
  aiStack_68[4] = param_2;
  aiStack_68[3] = 0x78ff6c;
  cVar1 = func_0x00773c80();
  if (cVar1 == '\0') {
    return 0;
  }
  param_1[0x9c] = iStack_4;
  param_1[0x9d] = unaff_retaddr;
  param_1[0x9e] = param_3;
  aiStack_68[3] = in_stack_0000001c;
  param_1[0x9f] = param_2;
  aiStack_68[2] = in_stack_00000018;
  aiStack_68[1] = param_3;
  aiStack_68[0] = param_2;
  func_0x007f5b21(&stack0xffffffb4,iStack_4,unaff_retaddr);
  piVar3 = aiStack_68;
  piVar4 = param_1 + 0x2a;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar4 = *piVar3;
    piVar3 = piVar3 + 1;
    piVar4 = piVar4 + 1;
  }
  func_0x007885a0(param_1 + 0x2a,param_1 + 0x5a);
  func_0x00787460();
  func_0x007c72c0(6);
  func_0x007c72c0(6);
  (**(code **)(*param_1 + 0x2c))();
  return 1;
}


/* ==================================================================== */
/* Address: 0x00790510 | Classified: Angelica3D::proc_790510 */
/* ==================================================================== */

undefined4 __thiscall
FUN_00790510(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  param_1[0x9c] = param_2;
  param_1[0x9d] = param_3;
  param_1[0x9e] = param_5;
  param_1[0x9f] = param_4;
  param_1[0x8e] = param_6;
  param_1[0x8f] = param_7;
  (**(code **)(*param_1 + 0x28))();
  return 1;
}


/* ==================================================================== */
/* Address: 0x00790560 | Classified: Angelica3D::proc_790560 */
/* ==================================================================== */

undefined4 __thiscall FUN_00790560(undefined4 param_1,byte param_2)

{
  FUN_00790580();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00790580 | Classified: Angelica3D::proc_790580 */
/* ==================================================================== */

void __fastcall FUN_00790580(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  uint uStack_4;
  
  *param_1 = &UNK_008f11c0;
  puStack_8 = &UNK_008cc346;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f0750;
  param_1[0x96] = &UNK_008f0788;
  uStack_4 = 1;
  param_1[0x97] = &UNK_008f0784;
  if (param_1[0x98] != 0) {
    func_0x00763260(param_1[0x98]);
    param_1[0x98] = 0;
  }
  param_1[0x9a] = 0;
  param_1[0x99] = 0;
  param_1[0x90] = &UNK_008f0788;
  uStack_4 = uStack_4 & 0xffffff00;
  param_1[0x91] = &UNK_008f0784;
  if (param_1[0x92] != 0) {
    func_0x00763260(param_1[0x92]);
    param_1[0x92] = 0;
  }
  param_1[0x94] = 0;
  param_1[0x93] = 0;
  uStack_4 = 0xffffffff;
  *param_1 = &UNK_008d6410;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x00790590 | Classified: Angelica3D::proc_790590 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00790590(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = _DAT_009858e4;
  *param_1 = &UNK_008f0a48;
  param_1[4] = _DAT_009858e4;
  *param_1 = &UNK_008f1268;
  param_1[1] = 0x1a;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007905d0 | Classified: Angelica3D::proc_7905d0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007905d0(undefined4 param_1,byte param_2)

{
  FUN_007905f0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007905f0 | Classified: Angelica3D::proc_7905f0 */
/* ==================================================================== */

void __fastcall FUN_007905f0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008ccd38;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f1268;
  uStack_4 = 0;
  func_0x007637f0();
  uStack_4 = 0xffffffff;
  *param_1 = &UNK_008d6410;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x00790650 | Classified: Angelica3D::proc_790650 */
/* ==================================================================== */

void __fastcall FUN_00790650(int param_1)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    piVar1 = *(int **)(*(int *)(param_1 + 0xc) + 0x2c);
    if (*(int *)(param_1 + 0x18) != 0) {
      (**(code **)(*piVar1 + 0x138))(piVar1,*(int *)(param_1 + 0x18));
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    piVar1 = *(int **)(param_1 + 0x14);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00790690 | Classified: elementclient::A3DVertexShader__Load__Cannot_op@0x790690 */
/* ==================================================================== */

undefined4 __thiscall FUN_00790690(int param_1,undefined4 param_2,char param_3)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_59c;
  int *piStack_598;
  int iStack_594;
  undefined4 *puStack_590;
  undefined1 *puStack_58c;
  uint uStack_588;
  undefined1 auStack_570 [788];
  undefined4 *puStack_25c;
  int iStack_24c;
  undefined4 uStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ccd66;
  *unaff_FS_OFFSET = &uStack_c;
  puStack_58c = auStack_570;
  uStack_588 = param_2;
  puStack_590 = (undefined4 *)0x7906c0;
  func_0x0076edb0();
  if (param_3 != '\0') {
    uStack_588 = 0x7906de;
    func_0x0076d760();
    puStack_58c = auStack_570;
    uStack_588 = 0x11;
    uStack_4 = 0;
    puStack_590 = (undefined4 *)0x7906fc;
    cVar2 = func_0x0076da20();
    if (cVar2 == '\0') {
      puStack_590 = (undefined4 *)0x79070c;
      func_0x0076db10();
      puStack_590 = (undefined4 *)&stack0xfffffa88;
      iStack_594 = 0x98aeec;
      piStack_598 = (int *)0x9d2f20;
      uStack_59c = 0x790720;
      func_0x007647d0();
    }
    else {
      iStack_594 = iStack_24c;
      piStack_598 = (int *)0x790736;
      puStack_590 = (undefined4 *)(param_1 + 0x14);
      iVar3 = func_0x007f8f28();
      if (iVar3 == 0) {
        piStack_598 = *(int **)(param_1 + 0x14);
        uStack_59c = 0x79077f;
        puVar4 = (undefined4 *)(**(code **)(*piStack_598 + 0xc))();
        for (uVar6 = uStack_588 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar4 = *puStack_25c;
          puStack_25c = puStack_25c + 1;
          puVar4 = puVar4 + 1;
        }
        for (uVar6 = uStack_588 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined1 *)puVar4 = *(undefined1 *)puStack_25c;
          puStack_25c = (undefined4 *)((int)puStack_25c + 1);
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
        uStack_59c = 0x79079f;
        func_0x0076db10();
        goto LAB_00790867;
      }
      piStack_598 = (int *)0x790746;
      func_0x0076db10();
    }
    uStack_c = 0xffffffff;
    puStack_590 = (undefined4 *)0x79075d;
    func_0x0076d7c0();
    uVar5 = 0;
    goto LAB_0079090f;
  }
  uStack_588 = 0x7907b7;
  func_0x0076d760();
  puStack_58c = auStack_570;
  uStack_588 = 0x11;
  uStack_4 = 1;
  puStack_590 = (undefined4 *)0x7907d5;
  cVar2 = func_0x0076da20();
  if (cVar2 == '\0') {
    puStack_590 = (undefined4 *)0x7907e5;
    func_0x0076db10();
    puStack_590 = (undefined4 *)&stack0xfffffa88;
    iStack_594 = 0x98aeec;
    piStack_598 = (int *)0x9d2f20;
    uStack_59c = 0x7907f9;
    func_0x007647d0();
    uStack_c = 0xffffffff;
    puStack_590 = (undefined4 *)0x790813;
    func_0x0076d7c0();
    uVar5 = 0;
    goto LAB_0079090f;
  }
  iStack_594 = param_1 + 0x14;
  puStack_590 = (undefined4 *)0x0;
  piStack_598 = (int *)0x0;
  uStack_59c = 0;
  iVar3 = func_0x007f8c55(uStack_24,uStack_1c);
  if (iVar3 != 0) {
    uStack_24 = 0xffffffff;
    func_0x0076d7c0();
    uVar5 = 0;
    goto LAB_0079090f;
  }
  func_0x0076db10();
LAB_00790867:
  puVar4 = (undefined4 *)(param_1 + 0x14);
  uStack_18 = 0xffffffff;
  uStack_59c = 0x790877;
  func_0x0076d7c0();
  uStack_588 = 0;
  piVar1 = *(int **)(*(int *)(param_1 + 0xc) + 0x2c);
  if (*(char *)(*(int *)(param_1 + 0xc) + 0x288) == '\0') {
LAB_0079089c:
    uStack_59c = 0x10;
  }
  else {
    uStack_59c = 1;
    cVar2 = func_0x0077bab0(1);
    uStack_59c = uStack_588;
    if (cVar2 == '\0') goto LAB_0079089c;
  }
  iVar3 = *piVar1;
  uVar5 = (**(code **)(*(int *)*puVar4 + 0xc))((int *)*puVar4,param_1 + 0x18);
  iVar3 = (**(code **)(iVar3 + 300))(piVar1,uStack_c,uVar5);
  if (iVar3 == 0) {
    func_0x0076ee60(&uStack_59c,(undefined4 *)(param_1 + 0x10));
    uVar5 = func_0x007648c0(*(undefined4 *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x1c) = uVar5;
    (**(code **)(*(int *)*puVar4 + 8))((int *)*puVar4);
    *puVar4 = 0;
    uVar5 = 1;
  }
  else {
    func_0x007647d0(0x9d2f20,0x98aeb4);
    uVar5 = 0;
  }
LAB_0079090f:
  *unaff_FS_OFFSET = uStack_14;
  return uVar5;
}


/* ==================================================================== */
/* Address: 0x00790930 | Classified: elementclient::A3DVertexShader__Appear__Failed_t@0x790930 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00790930(int param_1)

{
  int iVar1;
  char cVar2;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    return 0;
  }
  iVar1 = _DAT_009d2d78;
  if ((_DAT_009d2d78 != param_1) &&
     (cVar2 = func_0x0077be90(*(int *)(param_1 + 0x18)), iVar1 = param_1, cVar2 == '\0')) {
    func_0x007647d0(0x9d2f20,0x98af18);
    return 0;
  }
  _DAT_009d2d78 = iVar1;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00790980 | Classified: Angelica3D::proc_790980 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __fastcall FUN_00790980(int param_1)

{
  if (_DAT_009d2d78 == param_1) {
    func_0x0077bad0();
    _DAT_009d2d78 = 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007909a0 | Classified: Angelica3D::proc_7909a0 */
/* ==================================================================== */

void __fastcall FUN_007909a0(int param_1)

{
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007909b0 | Classified: elementclient::A3DMathUtility__Init_Not_enough_m@0x7909b0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_007909b0(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  float10 fVar4;
  float10 fVar5;
  
  fVar1 = _DAT_008f0d88 / (float)param_2;
  *param_1 = param_2;
  param_1[1] = (int)fVar1;
  iVar2 = malloc(param_2 << 2);
  param_1[2] = iVar2;
  if (iVar2 == 0) {
    uVar3 = func_0x007647d0(0x9d2f20,0x98af50);
    return uVar3 & 0xffffff00;
  }
  iVar2 = malloc(*param_1 << 2);
  param_1[3] = iVar2;
  if (iVar2 == 0) {
    uVar3 = func_0x007647d0(0x9d2f20,0x98af50);
    return uVar3 & 0xffffff00;
  }
  iVar2 = 0;
  param_2 = 0;
  if (0 < *param_1) {
    do {
      iVar2 = param_2 + 1;
      fVar4 = (float10)param_2 * (float10)(float)param_1[1] * (float10)_DAT_008f07b0;
      fVar5 = (float10)fsin(fVar4);
      *(float *)(param_1[2] + -4 + iVar2 * 4) = (float)fVar5;
      fVar4 = (float10)fcos(fVar4);
      *(float *)(param_1[3] + -4 + iVar2 * 4) = (float)fVar4;
      param_2 = iVar2;
    } while (iVar2 < *param_1);
  }
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x00790a60 | Classified: Angelica3D::proc_790a60 */
/* ==================================================================== */

undefined4 __fastcall FUN_00790a60(int param_1)

{
  if (*(int *)(param_1 + 8) != 0) {
    free(*(int *)(param_1 + 8));
    *(undefined4 *)(param_1 + 8) = 0;
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    free(*(int *)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00790aa0 | Classified: Angelica3D::proc_790aa0 */
/* ==================================================================== */

void __fastcall FUN_00790aa0(undefined4 *param_1)

{
  *param_1 = 0x3e99999a;
  param_1[1] = 0x3e99999a;
  param_1[2] = 0x3e99999a;
  param_1[3] = 0x3f800000;
  param_1[4] = 0x3f800000;
  param_1[5] = 0xbf800000;
  param_1[6] = 0;
  param_1[7] = 0x3f333333;
  param_1[8] = 0x3f333333;
  param_1[9] = 0x3f333333;
  param_1[10] = 0x3f800000;
  param_1[0xb] = 0x3ecccccd;
  param_1[0xc] = 0x3ecccccd;
  param_1[0xd] = 0x3ecccccd;
  param_1[0xe] = 0x3f800000;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  *(undefined1 *)(param_1 + 0xf) = 0;
  param_1[0x1e] = 0x42480000;
  return;
}


/* ==================================================================== */
/* Address: 0x00790b20 | Classified: Angelica3D::proc_790b20 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_00790b20(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  undefined4 *puStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cce58;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  puStack_10 = param_1;
  func_0x007b0af0();
  param_1[0x30] = _DAT_009858e4;
  param_1[0x31] = _DAT_009858e4;
  param_1[0x36] = _DAT_009858e4;
  param_1[0x39] = &UNK_008d5a30;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0x10;
  param_1[0x38] = &UNK_008dac44;
  param_1[0x3f] = &UNK_008d5a30;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0x10;
  param_1[0x3e] = &UNK_008dac4c;
  param_1[0x45] = &UNK_008d5a30;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0x10;
  param_1[0x44] = &UNK_008dac54;
  param_1[0x5a] = &UNK_008d7440;
  param_1[0x5b] = 0;
  param_1[0x5c] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0x10;
  param_1[0x60] = &UNK_008d649c;
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  param_1[99] = 0;
  param_1[100] = 0;
  param_1[0x65] = 10;
  param_1[0x66] = 0;
  param_1[0x5f] = &UNK_008dac5c;
  uStack_4._0_1_ = 8;
  uStack_4._1_3_ = 0;
  FUN_00790aa0();
  func_0x007b65a0();
  uStack_4 = CONCAT31(uStack_4._1_3_,9);
  param_1[0x9f] = 0x3f800000;
  param_1[0xa0] = 0x3f800000;
  param_1[0xa1] = 0x3f800000;
  param_1[0xa2] = 0x3f800000;
  param_1[0xa3] = 0;
  param_1[0xa4] = 0;
  param_1[0xa5] = 0;
  param_1[0xa6] = 0;
  param_1[0xda] = 0;
  uStack_14 = 0;
  uVar1 = func_0x00404700(0x10,&uStack_14);
  func_0x007ab5e0(uVar1);
  param_1[0xe1] = 0;
  param_1[0xe0] = &UNK_008dac64;
  param_1[0xe2] = 0;
  param_1[0xe3] = 0;
  param_1[0xe4] = 0x10;
  param_1[0xe5] = &UNK_008dac64;
  param_1[0xe6] = 0;
  param_1[0xe7] = 0;
  param_1[0xe8] = 0;
  param_1[0xe9] = 0x10;
  param_1[0xea] = &UNK_008dac64;
  param_1[0xeb] = 0;
  param_1[0xec] = 0;
  param_1[0xed] = 0;
  param_1[0xee] = 0x10;
  param_1[0xf1] = 0;
  param_1[0xf0] = &UNK_008d5a30;
  param_1[0xf2] = 0;
  param_1[0xf3] = 0;
  param_1[0xf4] = 0x10;
  param_1[0xef] = &UNK_008dac6c;
  param_1[0xf5] = &UNK_008dac74;
  param_1[0xf6] = 0;
  param_1[0xf7] = 0;
  param_1[0xf8] = 0;
  param_1[0xf9] = 0x10;
  param_1[0xfb] = &UNK_008d5a30;
  param_1[0xfc] = 0;
  param_1[0xfd] = 0;
  param_1[0xfe] = 0;
  param_1[0xff] = 0x10;
  param_1[0xfa] = &UNK_008dac7c;
  uStack_c = CONCAT31(uStack_c._1_3_,0x10);
  *param_1 = &UNK_008dac84;
  param_1[1] = 0x13;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x67] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  *(undefined1 *)((int)param_1 + 0x1a1) = 0;
  *(undefined1 *)(param_1 + 0xd8) = 0;
  param_1[0xd3] = 3;
  param_1[0x88] = 0;
  *(undefined1 *)(param_1 + 0x34) = 0;
  param_1[0xba] = 0;
  param_1[0xa7] = 0xbf800000;
  *(undefined1 *)(param_1 + 0xa8) = 1;
  *(undefined1 *)((int)param_1 + 0xd1) = 0;
  param_1[0xa9] = 5;
  param_1[0xaa] = 6;
  *(undefined1 *)(param_1 + 0xab) = 0;
  param_1[0x35] = 8;
  *(undefined1 *)((int)param_1 + 0x2ad) = 1;
  *(undefined1 *)((int)param_1 + 0x2ae) = 0;
  param_1[0x37] = 0;
  param_1[0xac] = 0;
  param_1[0xad] = 0;
  *(undefined1 *)(param_1 + 0xdf) = 0;
  func_0x00774e10();
  puVar3 = param_1 + 0x69;
  for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  param_1[0x69] = 0x3f800000;
  param_1[0x6a] = 0x3f800000;
  param_1[0x6b] = 0x3f800000;
  param_1[0x6c] = 0x3f800000;
  puVar3 = param_1 + 0x4a;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *unaff_FS_OFFSET = uStack_14;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00790eb0 | Classified: Angelica3D::proc_790eb0 */
/* ==================================================================== */

undefined4 __thiscall FUN_00790eb0(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  *(int *)(param_1 + 0xb4) = param_2;
  *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_2 + 0x50);
  puVar2 = (undefined4 *)(param_1 + 0x2b8);
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  func_0x007b6680(*(undefined4 *)(param_1 + 0xb8));
  iVar1 = *(int *)(*(int *)(param_1 + 0xb4) + 0x948) + 1;
  *(int *)(*(int *)(param_1 + 0xb4) + 0x948) = iVar1;
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x00790f10 | Classified: Angelica3D::proc_790f10 */
/* ==================================================================== */

undefined4 __fastcall FUN_00790f10(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  
  piVar5 = (int *)0x0;
  if (*(int *)(param_1 + 0xb4) != 0) {
    piVar6 = (int *)(*(int *)(param_1 + 0xb4) + 0x948);
    *piVar6 = *piVar6 + -1;
  }
  if (*(int *)(param_1 + 0x118) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x118));
    *(undefined4 *)(param_1 + 0x118) = 0;
  }
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  FUN_00792450(0);
  piVar6 = (int *)(param_1 + 0x128);
  iVar3 = 0x10;
  do {
    if ((undefined4 *)*piVar6 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar6)(1);
      *piVar6 = 0;
    }
    piVar6 = piVar6 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (*(char *)(param_1 + 0xd1) != '\0') {
    func_0x007d0240(param_1);
  }
  FUN_00793330();
  func_0x007b1340();
  FUN_007910d0(0);
  FUN_00791120();
  FUN_00791d30();
  puVar1 = *(undefined4 **)(param_1 + 0x184);
  while (puVar1 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x184) = *puVar1;
    *puVar1 = *(undefined4 *)(param_1 + 0x18c);
    *(undefined4 **)(param_1 + 0x18c) = puVar1;
    puVar1 = *(undefined4 **)(param_1 + 0x184);
    *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + -1;
  }
  *(undefined4 *)(param_1 + 0x188) = 0;
  *(undefined4 *)(param_1 + 400) = 0;
  if (*(int *)(param_1 + 900) != 0) {
    func_0x00763260(*(int *)(param_1 + 900));
    *(undefined4 *)(param_1 + 900) = 0;
  }
  *(undefined4 *)(param_1 + 0x38c) = 0;
  *(undefined4 *)(param_1 + 0x388) = 0;
  if (*(int *)(param_1 + 0x398) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x398));
    *(undefined4 *)(param_1 + 0x398) = 0;
  }
  *(undefined4 *)(param_1 + 0x3a0) = 0;
  *(undefined4 *)(param_1 + 0x39c) = 0;
  if (*(int *)(param_1 + 0x3ac) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x3ac));
    *(undefined4 *)(param_1 + 0x3ac) = 0;
  }
  *(undefined4 *)(param_1 + 0x3b4) = 0;
  *(undefined4 *)(param_1 + 0x3b0) = 0;
  uVar4 = 0;
  uVar2 = 0;
  if (*(int *)(param_1 + 0x378) != 0) {
    do {
      piVar6 = *(int **)(*(int *)(param_1 + 0x36c) + uVar4 * 4);
      if (piVar6 != piVar5) {
        do {
          piVar5 = (int *)*piVar6;
          func_0x004acbf0();
          func_0x00763260(piVar6);
          piVar6 = piVar5;
        } while (piVar5 != (int *)0x0);
      }
      uVar4 = uVar4 + 1;
      *(int **)(*(int *)(param_1 + 0x36c) + -4 + uVar4 * 4) = piVar5;
      uVar2 = *(uint *)(param_1 + 0x378);
    } while (uVar4 < uVar2);
  }
  *(int **)(param_1 + 0x368) = piVar5;
  return CONCAT31((int3)(uVar2 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007910d0 | Classified: Angelica3D::proc_7910d0 */
/* ==================================================================== */

void __thiscall FUN_007910d0(int param_1,char param_2)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 0xbc);
  if (*(int *)(param_1 + 0xbc) != 0) {
    if (param_2 != '\0') {
      func_0x007b12d0(*(int *)(param_1 + 0xbc));
    }
    *(undefined4 *)(*piVar1 + 0xb4) = 0;
    func_0x007ab050(piVar1);
    *piVar1 = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00791120 | Classified: Angelica3D::proc_791120 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00791120(int param_1)

{
  undefined4 uVar1;
  bool bVar2;
  bool bVar3;
  float *pfVar4;
  undefined4 unaff_EDI;
  int iVar5;
  undefined1 auStack_7c [4];
  float fStack_78;
  float fStack_74;
  undefined1 auStack_70 [12];
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  undefined1 auStack_30 [20];
  undefined1 auStack_1c [4];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  iVar5 = 0;
  if (0 < *(int *)(param_1 + 0xec)) {
    do {
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xe8) + iVar5 * 4);
      uStack_14 = 0x791142;
      uStack_10 = uVar1;
      FUN_00791d00();
      uStack_18 = 0x791148;
      uStack_14 = uVar1;
      func_0x00763260();
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(param_1 + 0xec));
  }
  if (*(int *)(param_1 + 0xe8) != 0) {
    uStack_10 = 0x791167;
    func_0x00763260();
    *(undefined4 *)(param_1 + 0xe8) = 0;
  }
  *(undefined4 *)(param_1 + 0xf0) = 0;
  *(undefined4 *)(param_1 + 0xec) = 0;
  if (*(int *)(param_1 + 0x2e8) == 1) {
    bVar2 = false;
    iVar5 = 0;
    fStack_48 = 999999.0;
    fStack_44 = 999999.0;
    fStack_40 = 999999.0;
    fStack_3c = -999999.0;
    fStack_38 = -999999.0;
    fStack_34 = -999999.0;
    bVar3 = false;
    if (0 < *(int *)(param_1 + 0xec)) {
      do {
        bVar2 = bVar3;
        if (**(int **)(*(int *)(param_1 + 0xe8) + iVar5 * 4) != 0) {
          FUN_00795770(auStack_30,unaff_EDI);
          pfVar4 = (float *)func_0x00787e10(auStack_70,&fStack_4c,auStack_1c);
          fStack_4c = *pfVar4;
          fStack_48 = pfVar4[1];
          fStack_44 = pfVar4[2];
          pfVar4 = (float *)func_0x00787e80(auStack_7c,&fStack_40,&uStack_10);
          fStack_3c = *pfVar4;
          fStack_38 = pfVar4[1];
          fStack_34 = pfVar4[2];
          bVar2 = true;
        }
        iVar5 = iVar5 + 1;
        bVar3 = bVar2;
      } while (iVar5 < *(int *)(param_1 + 0xec));
    }
    fStack_78 = (fStack_3c + fStack_48) * _DAT_008eff98;
    fStack_74 = (fStack_38 + fStack_44) * _DAT_008eff98;
    fStack_58 = (fStack_34 + fStack_40) * _DAT_008eff98;
    fStack_54 = fStack_3c - fStack_78;
    fStack_50 = fStack_38 - fStack_74;
    fStack_64 = fStack_34 - fStack_58;
    fStack_60 = fStack_78;
    fStack_5c = fStack_74;
    fStack_4c = fStack_64;
    if (!bVar2) {
      func_0x00774e10();
      return;
    }
    func_0x00775a40(&fStack_60);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007911a0 | Classified: Angelica3D::proc_7911a0 */
/* ==================================================================== */

void __thiscall FUN_007911a0(int param_1,int param_2,undefined1 param_3)

{
  *(undefined1 *)(*(int *)(*(int *)(param_1 + 0xe8) + param_2 * 4) + 5) = param_3;
  return;
}


/* ==================================================================== */
/* Address: 0x00791210 | Classified: elementclient::A3DSkinModel__Load__Cannot_open_f@0x791210 */
/* ==================================================================== */

undefined4 __thiscall FUN_00791210(int *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_248;
  undefined4 uStack_18;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cce7b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_248 = 0x791238;
  func_0x0076d760();
  uStack_248 = 0x11;
  uStack_4 = 0;
  cVar1 = func_0x007737f0(&DAT_009b3c44,param_2);
  if (cVar1 == '\0') {
    func_0x0076db10();
    func_0x007647d0(0x9d2f20,0x98afa8,param_2);
  }
  else {
    cVar1 = (**(code **)(*param_1 + 0x40))(&uStack_248,uStack_4);
    if (cVar1 != '\0') {
      func_0x0076db10();
      uStack_18 = 0xffffffff;
      func_0x0076d7c0();
      uVar2 = 1;
      goto LAB_007912d1;
    }
    func_0x0076db10();
  }
  func_0x0076d7c0();
  uVar2 = 0;
LAB_007912d1:
  *unaff_FS_OFFSET = uStack_18;
  return uVar2;
}


/* ==================================================================== */
/* Address: 0x007916c0 | Classified: elementclient::A3DSkinModel__BindSkeletonFile__F@0x7916c0 */
/* ==================================================================== */

undefined * FUN_007916c0(void)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  int extraout_ECX;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *unaff_FS_OFFSET;
  undefined4 in_stack_00000ff8;
  undefined4 in_stack_0000100c;
  undefined *puStack_c;
  undefined *apuStack_8 [2];
  
  puStack_c = (undefined *)*unaff_FS_OFFSET;
  apuStack_8[1] = (undefined *)0xffffffff;
  apuStack_8[0] = &UNK_008cceea;
  *unaff_FS_OFFSET = &puStack_c;
  func_0x00892f20();
  puStack_c = (undefined *)func_0x007aaab0(in_stack_0000100c);
  if (puStack_c == (undefined *)0x0) {
    func_0x007647d0(0x9d2f20,0x98b060);
    puVar3 = (undefined *)0x0;
    goto LAB_007919dc;
  }
  *(undefined **)(extraout_ECX + 0xbc) = puStack_c;
  *(int *)(puStack_c + 0xb4) = extraout_ECX;
  iVar6 = *(int *)(*(int *)(extraout_ECX + 0xbc) + 0xf0);
  *(undefined4 *)(extraout_ECX + 0x390) = 4;
  iVar6 = iVar6 + 1;
  if (iVar6 == 0) {
    if (*(int *)(extraout_ECX + 900) != 0) {
      func_0x00763260(*(int *)(extraout_ECX + 900));
      *(undefined4 *)(extraout_ECX + 900) = 0;
    }
    *(undefined4 *)(extraout_ECX + 0x38c) = 0;
    *(undefined4 *)(extraout_ECX + 0x388) = 0;
  }
  else {
    if (*(int *)(extraout_ECX + 0x38c) < iVar6) {
      iVar1 = func_0x00763250(iVar6 * 0x40);
      if (iVar1 == 0) {
        iVar1 = 0;
      }
      else {
        func_0x00401e10(iVar1,0x40,iVar6,FUN_0041b5b0);
      }
      if (iVar1 == 0) {
        func_0x00764590(1,0x9505a4);
        goto LAB_00791836;
      }
      if (*(int *)(extraout_ECX + 900) != 0) {
        iVar5 = *(int *)(extraout_ECX + 0x388);
        if (iVar6 <= *(int *)(extraout_ECX + 0x388)) {
          iVar5 = iVar6;
        }
        if (0 < iVar5) {
          iVar2 = 0;
          do {
            puVar7 = (undefined4 *)(*(int *)(extraout_ECX + 900) + iVar2);
            puVar8 = (undefined4 *)(iVar2 + iVar1);
            iVar2 = iVar2 + 0x40;
            iVar5 = iVar5 + -1;
            for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar8 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar8 = puVar8 + 1;
            }
          } while (iVar5 != 0);
        }
        func_0x00763260(*(undefined4 *)(extraout_ECX + 900));
      }
      *(int *)(extraout_ECX + 0x38c) = iVar6;
      *(int *)(extraout_ECX + 900) = iVar1;
    }
    *(int *)(extraout_ECX + 0x388) = iVar6;
  }
LAB_00791836:
  iVar6 = *(int *)(*(int *)(extraout_ECX + 0xbc) + 0xf0);
  *(undefined4 *)(extraout_ECX + 0x3a4) = 4;
  iVar6 = iVar6 + 1;
  if (iVar6 == 0) {
    if (*(int *)(extraout_ECX + 0x398) != 0) {
      func_0x00763260(*(int *)(extraout_ECX + 0x398));
      *(undefined4 *)(extraout_ECX + 0x398) = 0;
    }
    *(undefined4 *)(extraout_ECX + 0x3a0) = 0;
    *(undefined4 *)(extraout_ECX + 0x39c) = 0;
  }
  else {
    if (*(int *)(extraout_ECX + 0x3a0) < iVar6) {
      iVar1 = func_0x00763250(iVar6 * 0x40);
      if (iVar1 == 0) {
        iVar1 = 0;
      }
      else {
        func_0x00401e10(iVar1,0x40,iVar6,FUN_0041b5b0);
      }
      if (iVar1 == 0) {
        func_0x00764590(1,0x9505a4);
        goto LAB_00791945;
      }
      if (*(int *)(extraout_ECX + 0x398) != 0) {
        iVar5 = *(int *)(extraout_ECX + 0x39c);
        if (iVar6 <= *(int *)(extraout_ECX + 0x39c)) {
          iVar5 = iVar6;
        }
        if (0 < iVar5) {
          iVar2 = 0;
          do {
            puVar7 = (undefined4 *)(*(int *)(extraout_ECX + 0x398) + iVar2);
            puVar8 = (undefined4 *)(iVar2 + iVar1);
            iVar2 = iVar2 + 0x40;
            iVar5 = iVar5 + -1;
            for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar8 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar8 = puVar8 + 1;
            }
          } while (iVar5 != 0);
        }
        func_0x00763260(*(undefined4 *)(extraout_ECX + 0x398));
      }
      *(int *)(extraout_ECX + 0x3a0) = iVar6;
      *(int *)(extraout_ECX + 0x398) = iVar1;
    }
    *(int *)(extraout_ECX + 0x39c) = iVar6;
  }
LAB_00791945:
  FUN_00794040(*(int *)(*(int *)(extraout_ECX + 0xbc) + 0xf0) + 1,4);
  func_0x007b1280(*(undefined4 *)(extraout_ECX + 0xbc));
  iVar6 = func_0x00763250(0x48);
  if (iVar6 == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = func_0x007c6190(extraout_ECX,0);
  }
  puVar3 = (undefined *)0x0;
  if (iVar6 != 0) {
    iVar1 = *(int *)(*(int *)(extraout_ECX + 0xbc) + 0xf0);
    if (0 < iVar1) {
      do {
        apuStack_8[(int)puVar3] = puVar3;
        puVar3 = puVar3 + 1;
      } while ((int)puVar3 < iVar1);
    }
    func_0x007c62e0(iVar1,apuStack_8);
    *(int *)(extraout_ECX + 0x128) = iVar6;
    puVar3 = puStack_c;
  }
LAB_007919dc:
  *unaff_FS_OFFSET = in_stack_00000ff8;
  return puVar3;
}


/* ==================================================================== */
/* Address: 0x00791a00 | Classified: elementclient::A3DSkinModel__AddSkin__Skin_does@0x791a00 */
/* ==================================================================== */

int __thiscall FUN_00791a00(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_retaddr;
  undefined4 uVar6;
  
  if (param_2 != 0) {
    cVar1 = FUN_00795cd0(*(undefined4 *)(param_1 + 0xbc));
    if (cVar1 == '\0') {
      if ((char)param_2 != '\0') {
        func_0x007aa7b0(&stack0x00000000);
      }
      uVar6 = 0x98b0d0;
      goto LAB_00791b48;
    }
    *(undefined1 *)(unaff_retaddr + 0x29) = 0;
    FUN_00795ba0(*(undefined4 *)(param_1 + 0x29c));
  }
  iVar2 = func_0x00763250(8);
  if (iVar2 != 0) {
    cVar1 = FUN_00791ce0(iVar2,unaff_retaddr,param_2);
    if (cVar1 != '\0') {
      if ((*(int *)(param_1 + 0xf0) <= *(int *)(param_1 + 0xec)) && (*(int *)(param_1 + 0xf4) != 0))
      {
        iVar5 = *(int *)(param_1 + 0xf4) + *(int *)(param_1 + 0xf0);
        iVar3 = func_0x00763250(iVar5 * 4);
        if (iVar3 == 0) {
          func_0x00764590(1,0x94e51c);
        }
        else {
          iVar4 = 0;
          if (0 < *(int *)(param_1 + 0xec)) {
            do {
              iVar4 = iVar4 + 1;
              *(undefined4 *)(iVar3 + -4 + iVar4 * 4) =
                   *(undefined4 *)(*(int *)(param_1 + 0xe8) + -4 + iVar4 * 4);
            } while (iVar4 < *(int *)(param_1 + 0xec));
          }
          if (*(int *)(param_1 + 0xe8) != 0) {
            func_0x00763260(*(int *)(param_1 + 0xe8));
          }
          *(int *)(param_1 + 0xe8) = iVar3;
          *(int *)(param_1 + 0xf0) = iVar5;
        }
      }
      *(int *)(*(int *)(param_1 + 0xe8) + *(int *)(param_1 + 0xec) * 4) = iVar2;
      iVar2 = *(int *)(param_1 + 0xec);
      *(int *)(param_1 + 0xec) = iVar2 + 1;
      FUN_007939e0();
      return iVar2;
    }
  }
  uVar6 = 0x98b09c;
LAB_00791b48:
  func_0x007647d0(0x9d2f20,uVar6);
  return -1;
}


/* ==================================================================== */
/* Address: 0x00791b60 | Classified: elementclient::A3DSkinModel__AddSkinFile__Faile@0x791b60 */
/* ==================================================================== */

undefined4 FUN_00791b60(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = func_0x007aa660(param_1);
  if (iVar1 == 0) {
    func_0x007647d0(0x9d2f20,0x98b104);
    return 0;
  }
  uVar2 = FUN_00791a00(iVar1,param_1);
  return uVar2;
}


/* ==================================================================== */
/* Address: 0x00791bb0 | Classified: Angelica3D::proc_791bb0 */
/* ==================================================================== */

void FUN_00791bb0(undefined4 param_1)

{
  FUN_00791b60(param_1,1);
  return;
}


/* ==================================================================== */
/* Address: 0x00791bc0 | Classified: elementclient::A3DSkinModel__ReplaceSkin__Skin_d@0x791bc0 */
/* ==================================================================== */

undefined4 __thiscall FUN_00791bc0(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  char cVar3;
  
  if (param_3 != 0) {
    cVar3 = FUN_00795cd0(*(undefined4 *)(param_1 + 0xbc));
    if (cVar3 == '\0') {
      if ((char)param_3 != '\0') {
        func_0x007aa7b0(&param_2);
      }
      func_0x007647d0(0x9d2f20,0x98b170);
      return 0;
    }
    *(undefined1 *)(param_2 + 0x29) = 0;
    FUN_00795ba0(*(undefined4 *)(param_1 + 0x29c));
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0xe8) + param_2 * 4);
  uVar1 = *(undefined1 *)(iVar2 + 5);
  FUN_00791d00(iVar2);
  if (param_2 != 0) {
    cVar3 = FUN_00791ce0(iVar2,param_2,param_3);
    if (cVar3 == '\0') {
      func_0x007647d0(0x9d2f20,0x98b138);
      return 0;
    }
    *(undefined1 *)(iVar2 + 5) = uVar1;
  }
  FUN_007939e0();
  return 1;
}


/* ==================================================================== */
/* Address: 0x00791c90 | Classified: elementclient::A3DSkinModel__ReplaceSkinFile__F@0x791c90 */
/* ==================================================================== */

uint FUN_00791c90(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_retaddr;
  
  iVar1 = func_0x007aa660(param_2);
  if (iVar1 == 0) {
    uVar2 = func_0x007647d0(0x9d2f20,0x98b1a8);
    return uVar2 & 0xffffff00;
  }
  uVar2 = FUN_00791bc0(unaff_retaddr,iVar1,param_2);
  return uVar2;
}


/* ==================================================================== */
/* Address: 0x00791ce0 | Classified: Angelica3D::proc_791ce0 */
/* ==================================================================== */

undefined4 FUN_00791ce0(undefined4 *param_1,undefined4 param_2,undefined1 param_3)

{
  *(undefined1 *)(param_1 + 1) = param_3;
  *param_1 = param_2;
  *(undefined1 *)((int)param_1 + 5) = 1;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00791d00 | Classified: Angelica3D::proc_791d00 */
/* ==================================================================== */

void FUN_00791d00(int *param_1)

{
  if (((char)param_1[1] != '\0') && (*param_1 != 0)) {
    func_0x007aa7b0(param_1);
  }
  *param_1 = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00791d30 | Classified: Angelica3D::proc_791d30 */
/* ==================================================================== */

void __fastcall FUN_00791d30(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x3c8)) {
    do {
      puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x3c4) + iVar2 * 4);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x3c8));
  }
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x3f4)) {
    do {
      puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x3f0) + iVar2 * 4);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x3f4));
  }
  if (*(int *)(param_1 + 0x3c4) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x3c4));
    *(undefined4 *)(param_1 + 0x3c4) = 0;
  }
  *(undefined4 *)(param_1 + 0x3cc) = 0;
  *(undefined4 *)(param_1 + 0x3c8) = 0;
  if (*(int *)(param_1 + 0x3f0) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x3f0));
    *(undefined4 *)(param_1 + 0x3f0) = 0;
  }
  *(undefined4 *)(param_1 + 0x3f8) = 0;
  *(undefined4 *)(param_1 + 0x3f4) = 0;
  if (*(int *)(param_1 + 0x3d8) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x3d8));
    *(undefined4 *)(param_1 + 0x3d8) = 0;
  }
  *(undefined4 *)(param_1 + 0x3e0) = 0;
  *(undefined4 *)(param_1 + 0x3dc) = 0;
  func_0x007638a0(&DAT_009b3c44);
  return;
}


/* ==================================================================== */
/* Address: 0x00791e10 | Classified: elementclient::A3DSkinModel__LoadHanger__Not_en@0x791e10 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00791e10(int param_1,int *param_2)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 unaff_EBX;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar8;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  piVar1 = param_2;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ccf16;
  *unaff_FS_OFFSET = &uStack_c;
  (**(code **)(*param_2 + 0x10))(&param_2,4,&uStack_10);
  if (puStack_8 == (undefined *)0x0) {
    piVar3 = (int *)func_0x00763250(0xb0);
    uStack_10 = 0;
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      func_0x007da920(param_1);
      piVar3[0x2a] = _DAT_009858e4;
      *piVar3 = (int)&UNK_008f12f0;
      piVar3[4] = 0;
      piVar3[1] = 0x21;
      piVar3[0x2b] = 0;
    }
LAB_00791eca:
    uStack_10 = 0xffffffff;
    if (piVar3 == (int *)0x0) {
      uVar8 = 0x98b25c;
    }
    else {
      cVar2 = (**(code **)(*piVar3 + 8))(piVar1);
      if (cVar2 != '\0') {
        if (puStack_8 == (undefined *)0x1) {
          iVar4 = func_0x00763c10(piVar3[0x2a]);
          if (iVar4 == 0) {
            (**(code **)*piVar3)(1);
            func_0x007647d0(0x9d2f20,0x98b1e0,*(undefined4 *)(param_1 + 0xc0));
            goto LAB_00791ee8;
          }
        }
        cVar2 = (**(code **)(*piVar3 + 0x10))();
        if (cVar2 != '\0') {
          if (puStack_8 == (undefined *)0x1) {
            iVar4 = piVar3[0x2c];
            func_0x007b1280(iVar4);
            if ((*(int *)(param_1 + 0x120) <= *(int *)(param_1 + 0x11c)) &&
               (*(int *)(param_1 + 0x124) != 0)) {
              iVar7 = *(int *)(param_1 + 0x124) + *(int *)(param_1 + 0x120);
              iVar5 = func_0x00763250(iVar7 * 4);
              if (iVar5 == 0) {
                func_0x00764590(1,0x94e51c);
              }
              else {
                iVar6 = 0;
                if (0 < *(int *)(param_1 + 0x11c)) {
                  do {
                    iVar6 = iVar6 + 1;
                    *(undefined4 *)(iVar5 + -4 + iVar6 * 4) =
                         *(undefined4 *)(*(int *)(param_1 + 0x118) + -4 + iVar6 * 4);
                  } while (iVar6 < *(int *)(param_1 + 0x11c));
                }
                if (*(int *)(param_1 + 0x118) != 0) {
                  func_0x00763260(*(int *)(param_1 + 0x118));
                }
                *(int *)(param_1 + 0x118) = iVar5;
                *(int *)(param_1 + 0x120) = iVar7;
              }
            }
            *(int *)(*(int *)(param_1 + 0x118) + *(int *)(param_1 + 0x11c) * 4) = iVar4;
            *(int *)(param_1 + 0x11c) = *(int *)(param_1 + 0x11c) + 1;
            *(int *)(iVar4 + 0xdc) = param_1;
            *(undefined1 *)(iVar4 + 0x2ae) = 1;
          }
          FUN_00793160(piVar3);
          uVar8 = 1;
          goto LAB_00791eea;
        }
        (**(code **)*piVar3)(1);
        goto LAB_00791ee8;
      }
      uVar8 = 0x98b224;
    }
    func_0x007647d0(0x9d2f20,uVar8);
  }
  else if (puStack_8 == (undefined *)0x1) {
    iVar4 = func_0x00763250(0xb8);
    uStack_10 = 1;
    if (iVar4 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)func_0x007dae80(param_1);
    }
    goto LAB_00791eca;
  }
LAB_00791ee8:
  uVar8 = 0;
LAB_00791eea:
  *unaff_FS_OFFSET = unaff_EBX;
  return uVar8;
}


/* ==================================================================== */
/* Address: 0x00792050 | Classified: Angelica3D::proc_792050 */
/* ==================================================================== */

undefined4 __thiscall FUN_00792050(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar1 = *(int *)(param_1 + 0xb4);
  uVar3 = FUN_00766250();
  *(undefined8 *)(iVar1 + 0x350) = uVar3;
  if ((*(int *)(param_1 + 0xdc) == 0) || (*(char *)(*(int *)(param_1 + 0xdc) + 0x2ad) != '\0')) {
    FUN_007920d0(param_2,param_3);
  }
  else {
    FUN_007921f0(param_2);
  }
  iVar1 = *(int *)(param_1 + 0xb4);
  iVar2 = FUN_00766250();
  iVar2 = iVar2 - *(int *)(iVar1 + 0x350);
  *(int *)(iVar1 + 0x358) = *(int *)(iVar1 + 0x358) + iVar2;
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007920d0 | Classified: Angelica3D::proc_7920d0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007920d0(int param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 0xbc) == 0) {
    return 1;
  }
  *(char *)(param_1 + 0x1a0) = param_3;
  if (param_3 == '\0') {
    piVar2 = (int *)(param_1 + 0x128);
    iVar1 = 0x10;
    do {
      if (*piVar2 != 0) {
        func_0x007c6790(param_2);
      }
      piVar2 = piVar2 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  func_0x007b3580(param_2);
  iVar1 = 0;
  *(undefined1 *)(param_1 + 0x37c) = 0;
  if (0 < *(int *)(param_1 + 0x104)) {
    do {
      piVar2 = *(int **)(*(int *)(param_1 + 0x100) + iVar1 * 4);
      if ((*(char *)(param_1 + 0x2ad) == '\0') && (piVar2[4] == 1)) {
        if ((piVar2[0x2c] != 0) && (*(char *)(piVar2[0x2c] + 0x2ae) != '\0')) {
          (**(code **)(*piVar2 + 0x18))(param_2);
        }
      }
      else {
        (**(code **)(*piVar2 + 0x18))(param_2);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x104));
  }
  FUN_00793360(param_2);
  *(undefined4 *)(param_1 + 0xcc) = param_2;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007921a0 | Classified: Angelica3D::proc_7921a0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007921a0(int param_1,undefined4 param_2,char param_3)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0xbc) != 0) {
    if (param_3 == '\0') {
      piVar1 = (int *)(param_1 + 0x128);
      iVar2 = 0x10;
      do {
        if (*piVar1 != 0) {
          func_0x007c6790(param_2);
        }
        piVar1 = piVar1 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    func_0x007b3580(param_2);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007921f0 | Classified: Angelica3D::proc_7921f0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007921f0(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0xdc) + 0x104);
  iVar3 = 0;
  if (0 < iVar1) {
    piVar4 = *(int **)(*(int *)(param_1 + 0xdc) + 0x100);
    do {
      piVar2 = (int *)*piVar4;
      if ((piVar2[4] == 1) && (piVar2[0x2c] == param_1)) {
        (**(code **)(*piVar2 + 0x18))(param_2);
        return 1;
      }
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar3 < iVar1);
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x00792240 | Classified: Angelica3D::proc_792240 */
/* ==================================================================== */

undefined4 FUN_00792240(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00792260(param_1,0);
  if (iVar1 == 0) {
    return 0;
  }
  return *(undefined4 *)(iVar1 + 8);
}


/* ==================================================================== */
/* Address: 0x00792260 | Classified: Angelica3D::proc_792260 */
/* ==================================================================== */

int * __thiscall FUN_00792260(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 == 0) {
    piVar2 = *(int **)(param_1 + 0x184);
    if (piVar2 != (int *)0x0) {
      while ((piVar2[2] == 0 ||
             (iVar1 = _stricmp(*(undefined4 *)(piVar2[2] + 8),param_2), iVar1 != 0))) {
        piVar2 = (int *)*piVar2;
        if (piVar2 == (int *)0x0) {
          return (int *)0x0;
        }
      }
      return piVar2;
    }
  }
  else {
    for (piVar2 = *(int **)(param_1 + 0x184); piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      if ((piVar2[2] != 0) && (*(int *)(piVar2[2] + 0x1c) == param_3)) {
        return piVar2;
      }
    }
  }
  return (int *)0x0;
}


/* ==================================================================== */
/* Address: 0x007922d0 | Classified: Angelica3D::proc_7922d0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007922d0(int param_1)

{
  undefined4 *puVar1;
  
  *(int *)(param_1 + 0x19c) = *(int *)(param_1 + 0x184);
  if (*(int *)(param_1 + 0x184) == 0) {
    return 0;
  }
  puVar1 = *(undefined4 **)(param_1 + 0x19c);
  *(undefined4 *)(param_1 + 0x19c) = *puVar1;
  return puVar1[2];
}


/* ==================================================================== */
/* Address: 0x00792300 | Classified: Angelica3D::proc_792300 */
/* ==================================================================== */

uint __thiscall
FUN_00792300(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  int iVar3;
  undefined4 unaff_EDI;
  
  if (((-1 < (int)param_3) && ((int)param_3 < 0x10)) &&
     (*(int *)(param_1 + 0x128 + param_3 * 4) != 0)) {
    uVar1 = func_0x007c6550(param_2,param_4,param_5,param_6,param_8);
    iVar2 = CONCAT31((int3)((uint)uVar1 >> 8),(char)param_2);
    if ((char)param_2 != '\0') {
      iVar2 = *(int *)(param_1 + 0x11c);
      iVar3 = 0;
      if (0 < iVar2) {
        do {
          FUN_00792300(unaff_ESI,unaff_EBP,unaff_EBX,unaff_EDI,param_6,param_2,param_8);
          iVar2 = *(int *)(param_1 + 0x11c);
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar2);
      }
    }
    return CONCAT31((int3)((uint)iVar2 >> 8),1);
  }
  return param_3 & 0xffffff00;
}


/* ==================================================================== */
/* Address: 0x007923a0 | Classified: Angelica3D::proc_7923a0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall
FUN_007923a0(int param_1,undefined4 param_2,float param_3,undefined4 param_4,undefined4 param_5)

{
  uint in_EAX;
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  int iVar3;
  undefined4 unaff_retaddr;
  
  iVar3 = 0;
  iVar2 = *(int *)(param_1 + 0x128);
  if (iVar2 == 0) {
    return in_EAX & 0xffffff00;
  }
  if (_DAT_008effc4 <= param_3) {
    *(undefined4 *)(iVar2 + 0x10) = 0;
    *(float *)(iVar2 + 0xc) = param_3;
  }
  else {
    *(float *)(iVar2 + 0xc) = -param_3;
    *(undefined4 *)(iVar2 + 0x10) = 1;
  }
  uVar1 = func_0x007c6550(param_2,1,param_4,param_5,0);
  iVar2 = CONCAT31((int3)((uint)uVar1 >> 8),(char)unaff_retaddr);
  if (((char)unaff_retaddr != '\0') && (iVar2 = *(int *)(param_1 + 0x11c), 0 < iVar2)) {
    do {
      FUN_007923a0(unaff_EBP,unaff_EBX,param_4,param_5,unaff_retaddr);
      iVar2 = *(int *)(param_1 + 0x11c);
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x00792450 | Classified: Angelica3D::proc_792450 */
/* ==================================================================== */

void __thiscall FUN_00792450(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0x10;
  piVar2 = (int *)(param_1 + 0x128);
  do {
    if (*piVar2 != 0) {
      func_0x007c66a0(0xffffffff);
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if (((char)param_2 != '\0') && (iVar1 = 0, 0 < *(int *)(param_1 + 0x11c))) {
    do {
      FUN_00792450(param_2);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x11c));
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007924b0 | Classified: Angelica3D::proc_7924b0 */
/* ==================================================================== */

void __thiscall FUN_007924b0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = 0;
  *(char *)(param_1 + 0x1a1) = (char)param_2;
  if (0 < *(int *)(param_1 + 0x11c)) {
    do {
      FUN_007924b0(param_2);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x11c));
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007924f0 | Classified: Angelica3D::proc_7924f0 */
/* ==================================================================== */

void __thiscall FUN_007924f0(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x1a4) = *param_2;
  *(undefined4 *)(param_1 + 0x1a8) = param_2[1];
  *(undefined4 *)(param_1 + 0x1ac) = param_2[2];
  *(undefined4 *)(param_1 + 0x1b0) = param_2[3];
  *(undefined4 *)(param_1 + 0x1b4) = param_2[4];
  *(undefined4 *)(param_1 + 0x1b8) = param_2[5];
  *(undefined4 *)(param_1 + 0x1bc) = param_2[6];
  *(undefined4 *)(param_1 + 0x1c0) = param_2[7];
  *(undefined4 *)(param_1 + 0x1c4) = param_2[8];
  *(undefined4 *)(param_1 + 0x1c8) = param_2[9];
  *(undefined4 *)(param_1 + 0x1cc) = param_2[10];
  *(undefined4 *)(param_1 + 0x1d0) = param_2[0xb];
  *(undefined4 *)(param_1 + 0x1d4) = param_2[0xc];
  *(undefined4 *)(param_1 + 0x1d8) = param_2[0xd];
  *(undefined4 *)(param_1 + 0x1dc) = param_2[0xe];
  *(undefined1 *)(param_1 + 0x1e0) = *(undefined1 *)(param_2 + 0xf);
  func_0x00401cc0(param_2 + 0x10);
  func_0x00410950(param_2 + 0x13);
  func_0x00410950(param_2 + 0x17);
  func_0x00401cc0(param_2 + 0x1b);
  iVar1 = 0;
  *(undefined4 *)(param_1 + 0x21c) = param_2[0x1e];
  if (0 < *(int *)(param_1 + 0x11c)) {
    do {
      FUN_007924f0(param_2);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x11c));
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00792600 | Classified: Angelica3D::proc_792600 */
/* ==================================================================== */

undefined4 __fastcall FUN_00792600(int param_1)

{
  float *pfVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  char cStack_14d;
  int iStack_14c;
  int iStack_148;
  undefined4 auStack_140 [12];
  float fStack_110;
  float fStack_10c;
  float fStack_108;
  undefined4 auStack_100 [13];
  float fStack_cc;
  undefined1 auStack_c0 [64];
  undefined1 auStack_80 [64];
  undefined1 auStack_40 [64];
  
  iVar7 = *(int *)(*(int *)(param_1 + 0xb4) + 0x88);
  puVar2 = (undefined4 *)(param_1 + 0xc);
  puVar8 = auStack_140;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar8 = puVar8 + 1;
  }
  fStack_110 = fStack_110 - *(float *)(iVar7 + 0x128);
  fStack_10c = fStack_10c - *(float *)(iVar7 + 300);
  iStack_148 = 0;
  fStack_108 = fStack_108 - *(float *)(iVar7 + 0x130);
  iVar7 = *(int *)(*(int *)(param_1 + 0xbc) + 0xf0);
  if (0 < iVar7) {
    iStack_14c = 0;
    do {
      if ((iStack_148 < 0) || (*(int *)(*(int *)(param_1 + 0xbc) + 0xf0) <= iStack_148)) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 0xbc) + 0xec) + iStack_148 * 4);
      }
      iVar6 = *(int *)(param_1 + 900);
      puVar2 = (undefined4 *)func_0x007873a0(auStack_100,iVar4 + 0x114,iVar4 + 0x194);
      puVar8 = (undefined4 *)(iVar6 + iStack_14c);
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar8 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar8 = puVar8 + 1;
      }
      iVar6 = *(int *)(param_1 + 0x398);
      uVar3 = func_0x007873a0(auStack_c0,iVar4 + 0x114,iVar4 + 0xd4,iVar4 + 0x224,auStack_140);
      uVar3 = func_0x007873a0(auStack_80,uVar3);
      puVar2 = (undefined4 *)func_0x007873a0(auStack_40,uVar3);
      puVar8 = (undefined4 *)(iVar6 + iStack_14c);
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar8 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar8 = puVar8 + 1;
      }
      if (*(char *)(iVar4 + 0x31) != '\0') {
        pfVar1 = (float *)(iStack_14c + 0x34 + *(int *)(param_1 + 0x398));
        *pfVar1 = *pfVar1 - *(float *)(*(int *)(param_1 + 0xbc) + 0xd4);
      }
      func_0x00788380(*(int *)(param_1 + 0x398) + iStack_14c,*(int *)(param_1 + 0x3ac) + iStack_14c)
      ;
      iStack_148 = iStack_148 + 1;
      iStack_14c = iStack_14c + 0x40;
    } while (iStack_148 < iVar7);
  }
  iVar4 = *(int *)(param_1 + 0xbc);
  cStack_14d = '\x01';
  iVar6 = *(int *)(iVar4 + 0xdc);
  if (-1 < iVar6) {
    if (iVar6 < *(int *)(iVar4 + 0xf0)) {
      iVar6 = *(int *)(*(int *)(iVar4 + 0xec) + iVar6 * 4);
    }
    else {
      iVar6 = 0;
    }
    cStack_14d = *(char *)(iVar6 + 0x31);
  }
  puVar2 = (undefined4 *)(param_1 + 0xc);
  puVar8 = auStack_100;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar8 = puVar8 + 1;
  }
  if (cStack_14d != '\0') {
    fStack_cc = fStack_cc - *(float *)(iVar4 + 0xd4);
    fStack_10c = fStack_10c - *(float *)(iVar4 + 0xd4);
  }
  iVar7 = iVar7 * 0x40;
  puVar2 = auStack_100;
  puVar8 = (undefined4 *)(*(int *)(param_1 + 900) + iVar7);
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar8 = puVar8 + 1;
  }
  puVar2 = auStack_140;
  puVar8 = (undefined4 *)(*(int *)(param_1 + 0x398) + iVar7);
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar8 = puVar8 + 1;
  }
  func_0x00788380(auStack_140,*(int *)(param_1 + 0x3ac) + iVar7);
  *(undefined1 *)(param_1 + 0x37c) = 1;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00792840 | Classified: Angelica3D::proc_792840 */
/* ==================================================================== */

bool __thiscall FUN_00792840(int param_1,int param_2,int param_3,undefined4 param_4)

{
  float fVar1;
  char cVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  float afStack_100 [4];
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  undefined1 auStack_c0 [64];
  undefined1 auStack_80 [64];
  undefined1 auStack_40 [64];
  
  if (*(int *)(param_1 + 0x3b0) == 0) {
    return false;
  }
  iVar5 = *(int *)(*(int *)(param_1 + 0xb4) + 0x88);
  pfVar6 = (float *)(iVar5 + 0x128);
  pfVar4 = afStack_100;
  pfVar3 = (float *)(*(int *)(param_2 + 0x30) + 0x68);
  iVar8 = 4;
  do {
    iVar7 = 4;
    do {
      fVar1 = *pfVar3;
      pfVar3 = pfVar3 + 1;
      *pfVar4 = fVar1;
      pfVar4 = pfVar4 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  func_0x007891a0(auStack_80,
                  fStack_f0 * *(float *)(iVar5 + 300) +
                  fStack_e0 * *(float *)(iVar5 + 0x130) + afStack_100[0] * *pfVar6,
                  fStack_ec * *(float *)(iVar5 + 300) +
                  fStack_dc * *(float *)(iVar5 + 0x130) + afStack_100[1] * *pfVar6,
                  fStack_e8 * *(float *)(iVar5 + 300) +
                  fStack_d8 * *(float *)(iVar5 + 0x130) + afStack_100[2] * *pfVar6);
  pfVar4 = (float *)func_0x007873a0(auStack_40,afStack_100,auStack_80);
  pfVar3 = afStack_100;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pfVar3 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pfVar3 = pfVar3 + 1;
  }
  func_0x007874a0();
  func_0x007873a0(auStack_c0,afStack_100,param_3 * 0x40 + *(int *)(param_1 + 0x3ac));
  cVar2 = func_0x0077ba40(param_4,auStack_c0,3);
  return cVar2 != '\0';
}


/* ==================================================================== */
/* Address: 0x007929c0 | Classified: Angelica3D::proc_7929c0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007929c0(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 **ppuVar6;
  undefined4 *puStack_78;
  undefined4 *puStack_74;
  undefined4 *puStack_70;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 auStack_40 [16];
  
  puVar2 = auStack_40;
  puVar1 = (undefined4 *)(*(int *)(param_2 + 0x30) + 0x68);
  iVar4 = 4;
  do {
    iVar3 = 4;
    do {
      uVar5 = *puVar1;
      puVar1 = puVar1 + 1;
      *puVar2 = uVar5;
      puVar2 = puVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  puStack_70 = auStack_40;
  puStack_74 = (undefined4 *)(param_1 + 0x1b4);
  puStack_78 = &uStack_60;
  puVar2 = (undefined4 *)func_0x007892c0();
  uStack_50 = *puVar2;
  uStack_4c = puVar2[1];
  puStack_74 = &uStack_50;
  uStack_48 = puVar2[2];
  puStack_70 = (undefined4 *)0x1;
  puStack_78 = (undefined4 *)0x1;
  uStack_44 = 0x3f000000;
  func_0x0077ba40();
  if (*(char *)(param_1 + 0x1e0) == '\0') {
    puStack_78 = (undefined4 *)0x1;
    uStack_60 = 0x3f800000;
    func_0x0077ba40(0xc,&stack0xffffff94);
    ppuVar6 = &puStack_78;
    uVar5 = 0xb;
  }
  else {
    puStack_78 = &uStack_4c;
    puVar2 = (undefined4 *)func_0x00787290(&stack0xffffff94,param_1 + 0x1e4);
    uStack_5c = *puVar2;
    uStack_58 = puVar2[1];
    uStack_54 = puVar2[2];
    puStack_78 = (undefined4 *)0x1;
    uStack_50 = 0x3f800000;
    func_0x0077ba40(10,&uStack_5c);
    uStack_60 = *(undefined4 *)(param_1 + 0x218);
    ppuVar6 = (undefined4 **)&stack0xffffff98;
    uStack_5c = 0x3f800000;
    uVar5 = 0xd;
  }
  func_0x0077ba40(uVar5,ppuVar6,1);
  return 1;
}


/* ==================================================================== */
/* Address: 0x00792b10 | Classified: Angelica3D::proc_792b10 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00792b10(int param_1,int param_2,int param_3)

{
  int iStack_78;
  
  if (param_2 != 0) {
    iStack_78 = 0x792b53;
    func_0x00410950();
    iStack_78 = param_2 + 0x34;
    func_0x00410950();
    func_0x00401cc0(param_2 + 0x44);
    func_0x00401cc0(param_2 + 0x50);
    FUN_0079b390(&iStack_78);
  }
  if (param_3 != 0) {
    if (*(char *)(param_1 + 0x1e0) == '\0') {
      if (*(char *)(param_3 + 0x78) != '\0') {
        iStack_78 = 0x792d8d;
        FUN_0079b370();
      }
    }
    else {
      if (*(char *)(param_3 + 0x78) == '\0') {
        iStack_78 = 0x792c4e;
        FUN_0079b340();
      }
      iStack_78 = param_3 + 0x14;
      func_0x00410950();
      func_0x00410950(param_3 + 0x24);
      func_0x00410950(param_3 + 0x34);
      func_0x00401cc0(param_3 + 0x50);
      if (*(float *)(param_1 + 0x21c) <= _DAT_008f092c) {
        FUN_0079b390(&iStack_78);
      }
      else {
        FUN_0079b390(&iStack_78);
      }
    }
  }
  if ((param_2 != 0) && (*(int *)(param_1 + 0xb8) != 0)) {
    func_0x00799540();
    iStack_78 = 0x792db3;
    func_0x0077a450();
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00792dc0 | Classified: Angelica3D::proc_792dc0 */
/* ==================================================================== */

undefined1 __thiscall FUN_00792dc0(int param_1,int *param_2)

{
  char cVar1;
  
  if (*(char *)(param_1 + 0xd0) != '\0') {
    return 0;
  }
  if (param_2 != (int *)0x0) {
    cVar1 = (**(code **)(*param_2 + 0x14))(param_1 + 0x2b8);
    if (cVar1 == '\0') {
      return 0;
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00792e00 | Classified: Angelica3D::proc_792e00 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00792e00(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
  if (((((*(int *)(param_1 + 0xb8) != 0) && (*(int *)(param_1 + 0xec) != 0)) &&
       (*(int *)(*(int *)(*(int *)(param_1 + 0xb4) + 0x88) + 0xc) != 0)) &&
      (*(char *)(param_1 + 0xd0) == '\0')) &&
     (((char)param_3 == '\0' ||
      (cVar2 = FUN_00792dc0(*(undefined4 *)(param_2 + 0x30)), cVar2 != '\0')))) {
    iVar4 = *(int *)(param_1 + 0xb4);
    uVar5 = FUN_00766250();
    *(undefined8 *)(iVar4 + 0x580) = uVar5;
    if (*(char *)(param_1 + 0x37c) == '\0') {
      FUN_00792600();
    }
    iVar4 = 0;
    if (0 < *(int *)(param_1 + 0xec)) {
      do {
        piVar1 = *(int **)(*(int *)(param_1 + 0xe8) + iVar4 * 4);
        if ((*(char *)((int)piVar1 + 5) != '\0') && (iVar3 = *piVar1, iVar3 != 0)) {
          FUN_007a5bb0(param_2,iVar3,param_1);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(param_1 + 0xec));
    }
    if (*(char *)(_DAT_009d2d64 + 0x18) != '\0') {
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x3c8)) {
        do {
          func_0x007ad070(*(int *)(*(int *)(param_1 + 0x3c4) + iVar4 * 4) + 0x74,0xff00a000,0);
          iVar4 = iVar4 + 1;
        } while (iVar4 < *(int *)(param_1 + 0x3c8));
      }
      func_0x007ad040(param_1 + 0x2b8,0xff00ff00,0);
    }
    if ((*(char *)(_DAT_009d2d64 + 0x1a) != '\0') && (iVar4 = 0, 0 < *(int *)(param_1 + 0x3f4))) {
      do {
        func_0x007ad0a0(*(int *)(*(int *)(param_1 + 0x3f0) + iVar4 * 4) + 0x4c,0xff800080,0);
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(param_1 + 0x3f4));
    }
    iVar4 = *(int *)(param_1 + 0xb4);
    iVar3 = FUN_00766250();
    *(int *)(iVar4 + 0x588) = *(int *)(iVar4 + 0x588) + (iVar3 - *(int *)(iVar4 + 0x580));
    iVar4 = 0;
    if (0 < *(int *)(param_1 + 0x11c)) {
      do {
        FUN_00792e00(param_2,param_3);
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(param_1 + 0x11c));
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00792fc0 | Classified: Angelica3D::proc_792fc0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00792fc0(int param_1,int param_2,undefined4 param_3,char param_4)

{
  char cVar1;
  int iVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  int iVar3;
  undefined8 uVar4;
  undefined4 unaff_retaddr;
  
  if (((((*(int *)(param_1 + 0xb8) != 0) && (*(int *)(param_1 + 0xec) != 0)) &&
       (*(int *)(*(int *)(*(int *)(param_1 + 0xb4) + 0x88) + 0xc) != 0)) &&
      (*(char *)(param_1 + 0xd0) == '\0')) &&
     ((param_4 == '\0' || (cVar1 = FUN_00792dc0(*(undefined4 *)(param_2 + 0x30)), cVar1 != '\0'))))
  {
    iVar3 = *(int *)(param_1 + 0xb4);
    uVar4 = FUN_00766250();
    *(undefined8 *)(iVar3 + 0x580) = uVar4;
    if (*(char *)(param_1 + 0x37c) == '\0') {
      FUN_00792600();
    }
    FUN_007a7b30(param_2,param_1,param_3);
    if (*(char *)(_DAT_009d2d64 + 0x18) != '\0') {
      iVar3 = 0;
      if (0 < *(int *)(param_1 + 0x3c8)) {
        do {
          func_0x007ad070(*(int *)(*(int *)(param_1 + 0x3c4) + iVar3 * 4) + 0x74,0xff00a000,0);
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(int *)(param_1 + 0x3c8));
      }
      func_0x007ad040(param_1 + 0x2b8,0xff00ff00,0);
    }
    if ((*(char *)(_DAT_009d2d64 + 0x1a) != '\0') && (iVar3 = 0, 0 < *(int *)(param_1 + 0x3f4))) {
      do {
        func_0x007ad0a0(*(int *)(*(int *)(param_1 + 0x3f0) + iVar3 * 4) + 0x4c,0xff800080,0);
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1 + 0x3f4));
    }
    iVar3 = *(int *)(param_1 + 0xb4);
    iVar2 = FUN_00766250();
    *(int *)(iVar3 + 0x588) = *(int *)(iVar3 + 0x588) + (iVar2 - *(int *)(iVar3 + 0x580));
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0x11c)) {
      do {
        FUN_00792fc0(unaff_ESI,unaff_EBX,unaff_retaddr);
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1 + 0x11c));
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00793160 | Classified: elementclient::AArray__Allocate__Not_enough_mem@0x793160 */
/* ==================================================================== */

undefined4 __thiscall FUN_00793160(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 0x108) <= *(int *)(param_1 + 0x104)) && (*(int *)(param_1 + 0x10c) != 0))
  {
    iVar3 = *(int *)(param_1 + 0x10c) + *(int *)(param_1 + 0x108);
    iVar1 = func_0x00763250(iVar3 * 4);
    if (iVar1 == 0) {
      func_0x00764590(1,0x94e51c);
    }
    else {
      iVar2 = 0;
      if (0 < *(int *)(param_1 + 0x104)) {
        do {
          iVar2 = iVar2 + 1;
          *(undefined4 *)(iVar1 + -4 + iVar2 * 4) =
               *(undefined4 *)(*(int *)(param_1 + 0x100) + -4 + iVar2 * 4);
        } while (iVar2 < *(int *)(param_1 + 0x104));
      }
      if (*(int *)(param_1 + 0x100) != 0) {
        func_0x00763260(*(int *)(param_1 + 0x100));
      }
      *(int *)(param_1 + 0x100) = iVar1;
      *(int *)(param_1 + 0x108) = iVar3;
    }
  }
  *(undefined4 *)(*(int *)(param_1 + 0x100) + *(int *)(param_1 + 0x104) * 4) = param_2;
  iVar1 = *(int *)(param_1 + 0x104) + 1;
  *(int *)(param_1 + 0x104) = iVar1;
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x00793220 | Classified: Angelica3D::proc_793220 */
/* ==================================================================== */

int __thiscall FUN_00793220(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x104)) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x100) + iVar3 * 4);
      if ((*(int *)(iVar1 + 4) == param_3) &&
         (iVar2 = _stricmp(*(undefined4 *)(iVar1 + 8),param_2), iVar2 == 0)) {
        return iVar1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x104));
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x00793280 | Classified: Angelica3D::proc_793280 */
/* ==================================================================== */

void __thiscall FUN_00793280(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x104)) {
    piVar2 = *(int **)(param_1 + 0x100);
    do {
      if (*piVar2 == param_2) {
        FUN_00793310(*(undefined4 *)(*(int *)(param_1 + 0x100) + iVar1 * 4));
        if (iVar1 != *(int *)(param_1 + 0x104) + -1) {
          *(undefined4 *)(*(int *)(param_1 + 0x100) + iVar1 * 4) =
               *(undefined4 *)(*(int *)(param_1 + 0x100) + -4 + *(int *)(param_1 + 0x104) * 4);
        }
        *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + -1;
        return;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x104));
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007932c0 | Classified: Angelica3D::proc_7932c0 */
/* ==================================================================== */

void __thiscall FUN_007932c0(int param_1,int param_2)

{
  FUN_00793310(*(undefined4 *)(*(int *)(param_1 + 0x100) + param_2 * 4));
  if (param_2 != *(int *)(param_1 + 0x104) + -1) {
    *(undefined4 *)(*(int *)(param_1 + 0x100) + param_2 * 4) =
         *(undefined4 *)(*(int *)(param_1 + 0x100) + -4 + *(int *)(param_1 + 0x104) * 4);
  }
  *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + -1;
  return;
}


/* ==================================================================== */
/* Address: 0x00793310 | Classified: Angelica3D::proc_793310 */
/* ==================================================================== */

void FUN_00793310(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x14))();
    (**(code **)*param_1)(1);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00793330 | Classified: Angelica3D::proc_793330 */
/* ==================================================================== */

void __fastcall FUN_00793330(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x104)) {
    do {
      FUN_00793310(*(undefined4 *)(*(int *)(param_1 + 0x100) + iVar1 * 4));
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x104));
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00793360 | Classified: Angelica3D::proc_793360 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00793360(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_b8 [12];
  undefined1 auStack_ac [64];
  undefined1 auStack_6c [100];
  undefined4 uStack_8;
  
  if (*(int *)(param_1 + 0x3c8) == 0) {
    if (*(int *)(param_1 + 0xbc) == 0) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x2d0) = 0x497423f0;
    *(undefined4 *)(param_1 + 0x2d4) = 0x497423f0;
    *(undefined4 *)(param_1 + 0x2d8) = 0x497423f0;
    func_0x005ca8a0(0xc97423f0,0xc97423f0,0xc97423f0);
    iVar7 = 0;
    iVar6 = *(int *)(*(int *)(param_1 + 0xbc) + 0xf0);
    if (0 < iVar6) {
      do {
        func_0x00774a10(&stack0xffffff3c);
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar6);
    }
    iVar6 = *(int *)(param_1 + 0xbc);
    iVar7 = *(int *)(iVar6 + 0xc4);
    if (iVar7 < 0) {
      iVar7 = 0;
    }
    if (*(int *)(param_1 + 0x2e8) == 1) {
      if ((iVar7 < 0) || (*(int *)(iVar6 + 0xf0) <= iVar7)) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(*(int *)(iVar6 + 0xec) + iVar7 * 4);
      }
      func_0x007873a0(auStack_ac,iVar6 + 0x114,iVar6 + 0x194);
      func_0x00775b30(auStack_6c,0,1);
      puVar5 = auStack_6c;
      iVar6 = 8;
      do {
        uVar4 = func_0x007872d0(auStack_b8,auStack_ac,puVar5);
        func_0x00774a10(uVar4);
        puVar5 = puVar5 + 0xc;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x2d0) = 0x497423f0;
    *(undefined4 *)(param_1 + 0x2d4) = 0x497423f0;
    *(undefined4 *)(param_1 + 0x2d8) = 0x497423f0;
    func_0x005ca8a0(0xc97423f0,0xc97423f0,0xc97423f0);
    iVar6 = 0;
    if (0 < *(int *)(param_1 + 0x3c8)) {
      do {
        iVar7 = *(int *)(*(int *)(param_1 + 0x3c4) + iVar6 * 4);
        func_0x007db440(uStack_8);
        func_0x00789550(param_1 + 0x2d0,param_1 + 0x2dc,iVar7 + 0x74);
        iVar6 = iVar6 + 1;
      } while (iVar6 < *(int *)(param_1 + 0x3c8));
    }
  }
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 0x11c)) {
    do {
      iVar7 = *(int *)(*(int *)(param_1 + 0x118) + iVar6 * 4);
      if ((*(char *)(iVar7 + 0xd0) == '\0') &&
         ((*(char *)(param_1 + 0x2ad) != '\0' || (*(char *)(iVar7 + 0x2ae) != '\0')))) {
        func_0x007898a0(param_1 + 0x2d0,param_1 + 0x2dc,iVar7 + 0x2b8);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(param_1 + 0x11c));
  }
  fVar1 = (*(float *)(param_1 + 0x2d0) + *(float *)(param_1 + 0x2dc)) * _DAT_008eff98;
  fVar2 = (*(float *)(param_1 + 0x2d4) + *(float *)(param_1 + 0x2e0)) * _DAT_008eff98;
  *(float *)(param_1 + 0x2b8) = fVar1;
  fVar3 = (*(float *)(param_1 + 0x2d8) + *(float *)(param_1 + 0x2e4)) * _DAT_008eff98;
  *(float *)(param_1 + 0x2c0) = fVar3;
  *(float *)(param_1 + 700) = fVar2;
  *(float *)(param_1 + 0x2c4) = *(float *)(param_1 + 0x2dc) - fVar1;
  *(float *)(param_1 + 0x2cc) = *(float *)(param_1 + 0x2e4) - fVar3;
  *(float *)(param_1 + 0x2c8) = *(float *)(param_1 + 0x2e0) - fVar2;
  *(undefined1 *)(param_1 + 0x360) = 1;
  return CONCAT31((int3)((uint)fVar1 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x00793610 | Classified: elementclient::AArray__Allocate__Not_enough_mem@0x793610 */
/* ==================================================================== */

int * __thiscall FUN_00793610(int param_1,undefined4 param_2,undefined *param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  int *unaff_FS_OFFSET;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ccf2b;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  iVar2 = func_0x00763250(0xb8);
  uStack_4 = 0;
  if (iVar2 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)func_0x007dae80(param_1);
  }
  uStack_4 = 0xffffffff;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 4))(param_2);
    *(undefined1 *)(piVar3 + 5) = (undefined1)param_2;
    func_0x007638a0();
    func_0x007638a0(*(undefined4 *)(param_3 + 0xc0));
    func_0x007638a0();
    cVar1 = func_0x007db170(param_3);
    if (cVar1 != '\0') {
      func_0x007b1280(param_3);
      puVar5 = param_3;
      if ((*(int *)(param_1 + 0x120) <= *(int *)(param_1 + 0x11c)) &&
         (*(int *)(param_1 + 0x124) != 0)) {
        iVar6 = *(int *)(param_1 + 0x124) + *(int *)(param_1 + 0x120);
        iVar2 = func_0x00763250(iVar6 * 4);
        if (iVar2 == 0) {
          func_0x00764590(1,0x94e51c);
          puVar5 = puStack_8;
        }
        else {
          iVar4 = 0;
          if (0 < *(int *)(param_1 + 0x11c)) {
            do {
              iVar4 = iVar4 + 1;
              *(undefined4 *)(iVar2 + -4 + iVar4 * 4) =
                   *(undefined4 *)(*(int *)(param_1 + 0x118) + -4 + iVar4 * 4);
            } while (iVar4 < *(int *)(param_1 + 0x11c));
          }
          if (*(int *)(param_1 + 0x118) != 0) {
            func_0x00763260(*(int *)(param_1 + 0x118));
          }
          *(int *)(param_1 + 0x118) = iVar2;
          *(int *)(param_1 + 0x120) = iVar6;
          puVar5 = puStack_8;
        }
      }
      *(undefined **)(*(int *)(param_1 + 0x118) + *(int *)(param_1 + 0x11c) * 4) = puVar5;
      *(int *)(param_1 + 0x11c) = *(int *)(param_1 + 0x11c) + 1;
      *(int *)(puVar5 + 0xdc) = param_1;
      FUN_00793f70(piVar3);
      FUN_00793160(piVar3);
      *unaff_FS_OFFSET = (int)param_3;
      return piVar3;
    }
    (**(code **)*piVar3)(1);
    func_0x007647d0(0x9d2f20,0x98b290);
    *unaff_FS_OFFSET = (int)param_3;
    return (int *)0x0;
  }
  *unaff_FS_OFFSET = iStack_c;
  return (int *)0x0;
}


/* ==================================================================== */
/* Address: 0x007937e0 | Classified: Angelica3D::proc_7937e0 */
/* ==================================================================== */

int __thiscall FUN_007937e0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = FUN_00793220(param_2,0x22);
  if (iVar2 == 0) {
    return 0;
  }
  iVar1 = *(int *)(iVar2 + 0xb0);
  if ((iVar1 != 0) && (*(char *)(iVar1 + 0x2ae) != '\0')) {
    return 0;
  }
  func_0x007db1f0();
  if (iVar1 != 0) {
    func_0x007b12d0(iVar1);
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0x11c)) {
      piVar4 = *(int **)(param_1 + 0x118);
      do {
        if (*piVar4 == iVar1) {
          if (iVar3 != *(int *)(param_1 + 0x11c) + -1) {
            *(undefined4 *)(*(int *)(param_1 + 0x118) + iVar3 * 4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x118) + -4 + *(int *)(param_1 + 0x11c) * 4);
          }
          *(int *)(param_1 + 0x11c) = *(int *)(param_1 + 0x11c) + -1;
          *(undefined4 *)(iVar1 + 0xdc) = 0;
          break;
        }
        iVar3 = iVar3 + 1;
        piVar4 = piVar4 + 1;
      } while (iVar3 < *(int *)(param_1 + 0x11c));
    }
  }
  func_0x007b3c00(0x3f800000);
  FUN_00793280(iVar2);
  return iVar1;
}


/* ==================================================================== */
/* Address: 0x007938a0 | Classified: Angelica3D::proc_7938a0 */
/* ==================================================================== */

void __thiscall FUN_007938a0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = FUN_00793220(param_2,0x22);
  if (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0xb0);
    if (iVar1 != 0) {
      func_0x007b12d0(iVar1);
      iVar3 = 0;
      if (0 < *(int *)(param_1 + 0x11c)) {
        piVar4 = *(int **)(param_1 + 0x118);
        while (*piVar4 != iVar1) {
          iVar3 = iVar3 + 1;
          piVar4 = piVar4 + 1;
          if (*(int *)(param_1 + 0x11c) <= iVar3) {
            FUN_00793280(iVar2);
            return;
          }
        }
        if (iVar3 != *(int *)(param_1 + 0x11c) + -1) {
          *(undefined4 *)(*(int *)(param_1 + 0x118) + iVar3 * 4) =
               *(undefined4 *)(*(int *)(param_1 + 0x118) + -4 + *(int *)(param_1 + 0x11c) * 4);
        }
        *(int *)(param_1 + 0x11c) = *(int *)(param_1 + 0x11c) + -1;
        *(undefined4 *)(iVar1 + 0xdc) = 0;
      }
    }
    FUN_00793280(iVar2);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00793940 | Classified: CECSCSkillGrp::vfunc_slot_5 */
/* ==================================================================== */

undefined4 FUN_00793940(void)

{
  return 0;
}


/* ==================================================================== */
/* Address: 0x00793950 | Classified: Angelica3D::proc_793950 */
/* ==================================================================== */

int __thiscall FUN_00793950(int param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0xbc) != 0) && (iVar1 = func_0x007b38c0(param_2,0), iVar1 != 0)) {
    return iVar1;
  }
  if ((param_3 == '\0') && (iVar1 = 0, 0 < *(int *)(param_1 + 0x11c))) {
    do {
      iVar2 = FUN_00793950(param_2,0);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x11c));
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x007939b0 | Classified: Angelica3D::proc_7939b0 */
/* ==================================================================== */

void __thiscall FUN_007939b0(int param_1,int param_2)

{
  if ((*(int *)(param_1 + 0x2e8) != param_2) && (*(int *)(param_1 + 0x2e8) = param_2, param_2 == 1))
  {
    FUN_007939e0();
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007939e0 | Classified: Angelica3D::proc_7939e0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_007939e0(int param_1)

{
  bool bVar1;
  bool bVar2;
  float *pfVar3;
  int iVar4;
  undefined1 auStack_70 [12];
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  undefined1 auStack_30 [20];
  undefined1 auStack_1c [12];
  undefined1 auStack_10 [16];
  
  if (*(int *)(param_1 + 0x2e8) == 1) {
    bVar1 = false;
    iVar4 = 0;
    fStack_48 = 999999.0;
    fStack_44 = 999999.0;
    fStack_40 = 999999.0;
    fStack_3c = -999999.0;
    fStack_38 = -999999.0;
    fStack_34 = -999999.0;
    bVar2 = false;
    if (0 < *(int *)(param_1 + 0xec)) {
      do {
        bVar1 = bVar2;
        if (**(int **)(*(int *)(param_1 + 0xe8) + iVar4 * 4) != 0) {
          FUN_00795770(auStack_30);
          pfVar3 = (float *)func_0x00787e10(auStack_70,&fStack_4c,auStack_1c);
          fStack_4c = *pfVar3;
          fStack_48 = pfVar3[1];
          fStack_44 = pfVar3[2];
          pfVar3 = (float *)func_0x00787e80(&stack0xffffff84,&fStack_40,auStack_10);
          fStack_3c = *pfVar3;
          fStack_38 = pfVar3[1];
          fStack_34 = pfVar3[2];
          bVar1 = true;
        }
        iVar4 = iVar4 + 1;
        bVar2 = bVar1;
      } while (iVar4 < *(int *)(param_1 + 0xec));
    }
    fStack_60 = (fStack_3c + fStack_48) * _DAT_008eff98;
    fStack_5c = (fStack_38 + fStack_44) * _DAT_008eff98;
    fStack_58 = (fStack_34 + fStack_40) * _DAT_008eff98;
    fStack_54 = fStack_3c - fStack_60;
    fStack_50 = fStack_38 - fStack_5c;
    fStack_64 = fStack_34 - fStack_58;
    fStack_4c = fStack_64;
    if (!bVar1) {
      func_0x00774e10();
      return;
    }
    func_0x00775a40(&fStack_60);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00793b50 | Classified: Angelica3D::proc_793b50 */
/* ==================================================================== */

void __thiscall FUN_00793b50(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = 0;
  *(undefined4 *)(param_1 + 0x29c) = param_2;
  if (0 < *(int *)(param_1 + 0xec)) {
    do {
      if (**(int **)(*(int *)(param_1 + 0xe8) + iVar1 * 4) != 0) {
        FUN_00795ba0(param_2);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0xec));
  }
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x11c)) {
    do {
      if (*(char *)(*(int *)(*(int *)(param_1 + 0x118) + iVar1 * 4) + 0x2a0) != '\0') {
        FUN_00793b50(param_2);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x11c));
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00793bd0 | Classified: Angelica3D::proc_793bd0 */
/* ==================================================================== */

/* WARNING: Removing unreachable block (ram,0x00793d67) */

int __thiscall FUN_00793bd0(int param_1,int param_2,int param_3,int param_4,char param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 *unaff_FS_OFFSET;
  int iStack_418;
  char acStack_40c [1024];
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  puStack_8 = &UNK_008ccf59;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (((param_2 < 1) || (0xf < param_2)) || ((param_5 != '\0' && (*(int *)(param_1 + 0xbc) == 0))))
  {
LAB_00793d8a:
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x128 + param_2 * 4);
    if (iVar2 == 0) {
      iVar1 = func_0x00763250(0x48);
      if (iVar1 == 0) {
        iVar2 = 0;
      }
      else {
        iStack_4 = iVar2;
        iVar2 = func_0x007c6190(param_1,param_2);
      }
      if (iVar2 == 0) goto LAB_00793d8a;
    }
    iStack_4 = 0xffffffff;
    if (param_5 == '\0') {
      func_0x007c62e0(param_3,param_4);
      *(int *)(param_1 + 0x128 + param_2 * 4) = iVar2;
    }
    else {
      iVar3 = 0;
      iVar1 = *(int *)(*(int *)(param_1 + 0xbc) + 0x108);
      iVar5 = 0;
      pcVar6 = acStack_40c;
      for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
        pcVar6[0] = '\0';
        pcVar6[1] = '\0';
        pcVar6[2] = '\0';
        pcVar6[3] = '\0';
        pcVar6 = pcVar6 + 4;
      }
      if (0 < param_3) {
        do {
          iVar4 = iVar3 * 4;
          iVar3 = iVar3 + 1;
          acStack_40c[*(int *)(param_4 + iVar4)] = '\x01';
        } while (iVar3 < param_3);
      }
      iVar3 = 0;
      iStack_418 = 0;
      iVar4 = iVar1;
      if (iVar1 == 0) {
        iVar4 = 0x10;
      }
      iStack_4 = 1;
      if (0 < iVar1) {
        do {
          if (acStack_40c[iVar5] == '\0') {
            if (-1 < iVar3) {
              func_0x0068e120(iVar4);
              iVar3 = iStack_418;
            }
            *(int *)(iVar3 * 4) = iVar5;
            iVar3 = iStack_418 + 1;
            iStack_418 = iVar3;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar1);
      }
      func_0x007c62e0(iVar3,0);
      *(int *)(param_1 + 0x128 + param_2 * 4) = iVar2;
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return iVar2;
}


/* ==================================================================== */
/* Address: 0x00793db0 | Classified: Angelica3D::proc_793db0 */
/* ==================================================================== */

undefined4 __thiscall FUN_00793db0(int param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 < 0x10)) {
    return *(undefined4 *)(param_1 + 0x128 + param_2 * 4);
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x00793dd0 | Classified: elementclient::AArray__Allocate__Not_enough_mem@0x793dd0 */
/* ==================================================================== */

uint __thiscall FUN_00793dd0(int param_1,undefined4 param_2)

{
  uint in_EAX;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  
  if (*(int *)(param_1 + 0xbc) != 0) {
    iVar1 = func_0x007b3690(param_2,0);
    in_EAX = 0;
    if (iVar1 != 0) {
      iVar1 = func_0x007b5620();
      in_EAX = 0;
      if (iVar1 != 0) {
        uVar2 = func_0x007b5620();
        in_EAX = func_0x007b37d0(uVar2);
        if (-1 < (int)in_EAX) {
          iVar1 = *(int *)(param_1 + 0x170);
          iVar3 = 0;
          if (0 < iVar1) {
            puVar5 = *(uint **)(param_1 + 0x16c);
            do {
              if (*puVar5 == in_EAX) goto LAB_00793ee6;
              iVar3 = iVar3 + 1;
              puVar5 = puVar5 + 1;
            } while (iVar3 < iVar1);
          }
          if ((*(int *)(param_1 + 0x174) <= iVar1) && (*(int *)(param_1 + 0x178) != 0)) {
            iVar3 = *(int *)(param_1 + 0x178) + *(int *)(param_1 + 0x174);
            iVar1 = func_0x00763250(iVar3 * 4);
            if (iVar1 == 0) {
              func_0x00764590(1,0x94e51c);
            }
            else {
              iVar4 = 0;
              if (0 < *(int *)(param_1 + 0x170)) {
                do {
                  iVar4 = iVar4 + 1;
                  *(undefined4 *)(iVar1 + -4 + iVar4 * 4) =
                       *(undefined4 *)(*(int *)(param_1 + 0x16c) + -4 + iVar4 * 4);
                } while (iVar4 < *(int *)(param_1 + 0x170));
              }
              if (*(int *)(param_1 + 0x16c) != 0) {
                func_0x00763260(*(int *)(param_1 + 0x16c));
              }
              *(int *)(param_1 + 0x16c) = iVar1;
              *(int *)(param_1 + 0x174) = iVar3;
            }
          }
          *(uint *)(*(int *)(param_1 + 0x16c) + *(int *)(param_1 + 0x170) * 4) = in_EAX;
          iVar3 = *(int *)(param_1 + 0x170) + 1;
          *(int *)(param_1 + 0x170) = iVar3;
LAB_00793ee6:
          return CONCAT31((int3)((uint)iVar3 >> 8),1);
        }
      }
    }
  }
  return in_EAX & 0xffffff00;
}


/* ==================================================================== */
/* Address: 0x00793f00 | Classified: Angelica3D::proc_793f00 */
/* ==================================================================== */

void __fastcall FUN_00793f00(int param_1)

{
  FUN_00792450(1);
  if (*(int *)(param_1 + 0xbc) != 0) {
    func_0x007b3960();
  }
  FUN_00792050(0,0);
  return;
}


/* ==================================================================== */
/* Address: 0x00793f30 | Classified: Angelica3D::proc_793f30 */
/* ==================================================================== */

void __fastcall FUN_00793f30(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x104)) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x100) + iVar2 * 4);
      if (*(int *)(iVar1 + 0x10) == 1) {
        FUN_00793f70(iVar1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x104));
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00793f70 | Classified: Angelica3D::proc_793f70 */
/* ==================================================================== */

void __thiscall FUN_00793f70(int param_1,int param_2)

{
  int iVar1;
  
  if (*(char *)(param_2 + 0xa0) != '\0') {
    if (*(char *)(param_2 + 0x14) == '\0') {
      iVar1 = func_0x007b38c0(*(undefined4 *)(param_2 + 0x18),0);
      if (iVar1 == 0) {
        return;
      }
      iVar1 = *(int *)(iVar1 + 0x10);
      if (iVar1 < 0) {
        return;
      }
      if (*(int *)(*(int *)(param_1 + 0xbc) + 0xf0) <= iVar1) {
        return;
      }
      iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0xbc) + 0xec) + iVar1 * 4);
    }
    else {
      iVar1 = func_0x007b3690();
    }
    if ((iVar1 != 0) && (*(int *)(param_2 + 0xb0) != 0)) {
      func_0x007b3c00(*(undefined4 *)(iVar1 + 0x90));
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00793ff0 | Classified: Angelica3D::proc_793ff0 */
/* ==================================================================== */

void __fastcall FUN_00793ff0(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1[1] != 0) {
    while( true ) {
      while ((int *)param_1[2] != (int *)0x0) {
        iVar1 = *(int *)param_1[2];
        param_1[2] = iVar1;
        if (iVar1 != 0) {
          return;
        }
      }
      piVar2 = (int *)(param_1[1] + 4);
      param_1[1] = (int)piVar2;
      if (piVar2 == (int *)(*(int *)(*param_1 + 8) + *(int *)(*param_1 + 0x14) * 4)) break;
      iVar1 = *piVar2;
      param_1[2] = iVar1;
      if (iVar1 != 0) {
        return;
      }
    }
    param_1[1] = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00794040 | Classified: elementclient::AArray__SetSize__Not_enough_memo@0x794040 */
/* ==================================================================== */

undefined4 __thiscall FUN_00794040(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (param_3 != 0) {
    *(int *)(param_1 + 0x10) = param_3;
  }
  if (param_2 != 0) {
    if (*(int *)(param_1 + 0xc) < param_2) {
      iVar1 = func_0x00763250(param_2 << 6);
      if (iVar1 == 0) {
        func_0x00764590(1,0x9505a4);
        return 0;
      }
      if (*(int *)(param_1 + 4) != 0) {
        iVar4 = *(int *)(param_1 + 8);
        if (param_2 <= *(int *)(param_1 + 8)) {
          iVar4 = param_2;
        }
        if (0 < iVar4) {
          iVar2 = 0;
          do {
            puVar6 = (undefined4 *)(iVar2 + iVar1);
            puVar5 = (undefined4 *)(*(int *)(param_1 + 4) + iVar2);
            iVar2 = iVar2 + 0x40;
            iVar4 = iVar4 + -1;
            for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar6 = *puVar5;
              puVar5 = puVar5 + 1;
              puVar6 = puVar6 + 1;
            }
          } while (iVar4 != 0);
        }
        func_0x00763260(*(undefined4 *)(param_1 + 4));
      }
      *(int *)(param_1 + 0xc) = param_2;
      *(int *)(param_1 + 4) = iVar1;
    }
    *(int *)(param_1 + 8) = param_2;
    return 1;
  }
  if (*(int *)(param_1 + 4) != 0) {
    func_0x00763260(*(int *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00794100 | Classified: Angelica3D::proc_794100 */
/* ==================================================================== */

undefined4 __thiscall FUN_00794100(undefined4 param_1,byte param_2)

{
  func_0x007dac30();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00794120 | Classified: Angelica3D::proc_794120 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00794120(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = _DAT_009858e4;
  *param_1 = &UNK_008d6410;
  param_1[6] = _DAT_009858e4;
  param_1[0xd] = &UNK_008d5a30;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0x10;
  param_1[0xc] = &UNK_008eb208;
  param_1[0x13] = &UNK_008d5a30;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0x10;
  param_1[0x12] = &UNK_008eb208;
  param_1[0x19] = &UNK_008d5a30;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0x10;
  param_1[0x18] = &UNK_008f138c;
  param_1[0x1f] = &UNK_008d5a30;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0x10;
  param_1[0x1e] = &UNK_008e7a74;
  param_1[0x24] = &UNK_008d7440;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0x10;
  param_1[0x29] = &UNK_008f1388;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0x10;
  param_1[0x2e] = &UNK_008f1388;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0x10;
  param_1[0x33] = &UNK_008f1388;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0x10;
  param_1[0x38] = &UNK_008f1388;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0x10;
  param_1[0x3d] = &UNK_008f1388;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0x10;
  param_1[0x42] = &UNK_008f1388;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0x10;
  param_1[0x47] = &UNK_008f1388;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0x10;
  *param_1 = &UNK_008f1380;
  param_1[1] = 0x16;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[0x4c] = 0;
  param_1[9] = 0;
  *(undefined1 *)(param_1 + 10) = 0;
  param_1[0x4d] = 9;
  *(undefined1 *)((int)param_1 + 0x29) = 0;
  param_1[0xb] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007942e0 | Classified: Angelica3D::proc_7942e0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007942e0(undefined4 param_1,byte param_2)

{
  FUN_00794300();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00794300 | Classified: Angelica3D::proc_794300 */
/* ==================================================================== */

void __fastcall FUN_00794300(undefined4 *param_1)

{
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008cd011;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f1380;
  uStack_4 = 0xc;
  param_1[0x47] = &UNK_008f1388;
  func_0x004acc40(1);
  puStack_8._0_1_ = 0xb;
  param_1[0x42] = &UNK_008f1388;
  if (param_1[0x43] != 0) {
    func_0x00763260(param_1[0x43]);
    param_1[0x43] = 0;
  }
  param_1[0x45] = 0;
  param_1[0x44] = 0;
  puStack_8._0_1_ = 10;
  param_1[0x3d] = &UNK_008f1388;
  if (param_1[0x3e] != 0) {
    func_0x00763260(param_1[0x3e]);
    param_1[0x3e] = 0;
  }
  param_1[0x40] = 0;
  param_1[0x3f] = 0;
  puStack_8._0_1_ = 9;
  param_1[0x38] = &UNK_008f1388;
  if (param_1[0x39] != 0) {
    func_0x00763260(param_1[0x39]);
    param_1[0x39] = 0;
  }
  param_1[0x3b] = 0;
  param_1[0x3a] = 0;
  puStack_8._0_1_ = 8;
  param_1[0x33] = &UNK_008f1388;
  if (param_1[0x34] != 0) {
    func_0x00763260(param_1[0x34]);
    param_1[0x34] = 0;
  }
  param_1[0x36] = 0;
  param_1[0x35] = 0;
  puStack_8._0_1_ = 7;
  param_1[0x2e] = &UNK_008f1388;
  if (param_1[0x2f] != 0) {
    func_0x00763260(param_1[0x2f]);
    param_1[0x2f] = 0;
  }
  param_1[0x31] = 0;
  param_1[0x30] = 0;
  puStack_8._0_1_ = 6;
  param_1[0x29] = &UNK_008f1388;
  if (param_1[0x2a] != 0) {
    func_0x00763260(param_1[0x2a]);
    param_1[0x2a] = 0;
  }
  param_1[0x2c] = 0;
  param_1[0x2b] = 0;
  puStack_8._0_1_ = 5;
  param_1[0x24] = &UNK_008d7440;
  if (param_1[0x25] != 0) {
    func_0x00763260(param_1[0x25]);
    param_1[0x25] = 0;
  }
  param_1[0x27] = 0;
  param_1[0x26] = 0;
  param_1[0x1e] = &UNK_008e7a74;
  puStack_8._0_1_ = 4;
  param_1[0x1f] = &UNK_008d5a30;
  if (param_1[0x20] != 0) {
    func_0x00763260(param_1[0x20]);
    param_1[0x20] = 0;
  }
  param_1[0x22] = 0;
  param_1[0x21] = 0;
  param_1[0x18] = &UNK_008f138c;
  puStack_8 = (undefined *)CONCAT31(puStack_8._1_3_,3);
  param_1[0x19] = &UNK_008d5a30;
  func_0x004acc40(1);
  uStack_c._0_1_ = 2;
  param_1[0x12] = &UNK_008eb208;
  param_1[0x13] = &UNK_008d5a30;
  if (param_1[0x14] != 0) {
    func_0x00763260(param_1[0x14]);
    param_1[0x14] = 0;
  }
  param_1[0x16] = 0;
  param_1[0x15] = 0;
  param_1[0xc] = &UNK_008eb208;
  uStack_c = CONCAT31(uStack_c._1_3_,1);
  param_1[0xd] = &UNK_008d5a30;
  func_0x004acc40(1);
  func_0x007637f0();
  *param_1 = &UNK_008d6410;
  func_0x007637f0();
  *unaff_FS_OFFSET = unaff_ESI;
  return;
}


/* ==================================================================== */
/* Address: 0x00794570 | Classified: Angelica3D::proc_794570 */
/* ==================================================================== */

undefined4 __thiscall FUN_00794570(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x50);
  if (*(int *)(param_2 + 0x88) != 0) {
    uVar1 = *(undefined4 *)(*(int *)(param_2 + 0x88) + 0x14);
    *(undefined4 *)(param_1 + 0x14) = uVar1;
    return CONCAT31((int3)((uint)uVar1 >> 8),1);
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007945a0 | Classified: Angelica3D::proc_7945a0 */
/* ==================================================================== */

void __fastcall FUN_007945a0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iStack_4;
  
  iStack_4 = param_1;
  if (*(int *)(param_1 + 0x14) != 0) {
    func_0x007b00e0(param_1);
  }
  if (*(int *)(param_1 + 0xa8) != 0) {
    func_0x00763260(*(int *)(param_1 + 0xa8));
    *(undefined4 *)(param_1 + 0xa8) = 0;
  }
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xac) = 0;
  if (*(int *)(param_1 + 0xbc) != 0) {
    func_0x00763260(*(int *)(param_1 + 0xbc));
    *(undefined4 *)(param_1 + 0xbc) = 0;
  }
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  if (*(int *)(param_1 + 0xd0) != 0) {
    func_0x00763260(*(int *)(param_1 + 0xd0));
    *(undefined4 *)(param_1 + 0xd0) = 0;
  }
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  if (*(int *)(param_1 + 0xe4) != 0) {
    func_0x00763260(*(int *)(param_1 + 0xe4));
    *(undefined4 *)(param_1 + 0xe4) = 0;
  }
  *(undefined4 *)(param_1 + 0xec) = 0;
  *(undefined4 *)(param_1 + 0xe8) = 0;
  if (*(int *)(param_1 + 0xf8) != 0) {
    func_0x00763260(*(int *)(param_1 + 0xf8));
    *(undefined4 *)(param_1 + 0xf8) = 0;
  }
  *(undefined4 *)(param_1 + 0x100) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  if (*(int *)(param_1 + 0x10c) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x10c));
    *(undefined4 *)(param_1 + 0x10c) = 0;
  }
  *(undefined4 *)(param_1 + 0x114) = 0;
  *(undefined4 *)(param_1 + 0x110) = 0;
  FUN_00795ef0();
  if ((*(int *)(param_1 + 0x10) != 0) && (iVar3 = 0, 0 < *(int *)(param_1 + 0x3c))) {
    do {
      iStack_4 = *(int *)(*(int *)(param_1 + 0x38) + iVar3 * 4);
      if (iStack_4 != 0) {
        func_0x0077c560(&iStack_4);
      }
      if ((iVar3 < *(int *)(param_1 + 0x54)) &&
         (iStack_4 = *(int *)(*(int *)(param_1 + 0x50) + iVar3 * 4), iStack_4 != 0)) {
        func_0x0077c560(&iStack_4);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x3c));
  }
  func_0x004acc40(1);
  func_0x004acc40(1);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x6c)) {
    do {
      puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x68) + iVar3 * 4);
      FUN_00430850();
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x6c));
  }
  if (*(int *)(param_1 + 0x68) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x68));
    *(undefined4 *)(param_1 + 0x68) = 0;
  }
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x84)) {
    do {
      iVar2 = *(int *)(*(int *)(param_1 + 0x80) + iVar3 * 4);
      if (iVar2 != 0) {
        func_0x007637f0();
        func_0x00763260(iVar2);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x84));
  }
  if (*(int *)(param_1 + 0x80) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x80));
    *(undefined4 *)(param_1 + 0x80) = 0;
  }
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007947b0 | Classified: elementclient::A3DSkin__Load__Failed_to_read_fi@0x7947b0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_007947b0(int param_1,int *param_2)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *unaff_FS_OFFSET;
  int iVar13;
  int iStack_1c0;
  int iStack_1bc;
  int iStack_1b8;
  int iStack_1b4;
  undefined1 auStack_1b0 [4];
  uint auStack_1ac [2];
  undefined1 auStack_1a4 [4];
  undefined1 auStack_1a0 [8];
  int iStack_198;
  int iStack_194;
  uint uStack_190;
  int iStack_18c;
  int iStack_188;
  int iStack_184;
  int iStack_180;
  int iStack_17c;
  int iStack_178;
  int iStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  int iStack_168;
  int iStack_164;
  undefined4 uStack_124;
  undefined1 auStack_11c [256];
  undefined1 uStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  undefined4 uStack_10;
  int *piStack_c;
  int *piStack_8;
  undefined4 uStack_4;
  
  piStack_c = (int *)*unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  piStack_8 = (int *)&UNK_008cd0f0;
  *unaff_FS_OFFSET = &piStack_c;
  cVar2 = (**(code **)(*param_2 + 0x10))(&iStack_188,0x68,&iStack_18c);
  if ((cVar2 == '\0') || (iStack_198 != 0x68)) {
    uVar3 = 0x98b2d0;
  }
  else {
    if ((iStack_194 == 0x41534b49) && (uStack_190 < 10)) {
      puVar12 = (undefined4 *)(param_1 + 0x18);
      *(undefined4 *)(param_1 + 0x20) = uStack_16c;
      *(undefined4 *)(param_1 + 0x1c) = uStack_170;
      func_0x007638a0(param_2 + 0x43);
      uVar3 = func_0x007648c0(*puVar12);
      *(undefined4 *)(param_1 + 0x130) = uVar3;
      *(uint *)(param_1 + 0x134) = uStack_190;
      if ((8 < uStack_190) && (iStack_174 != 0)) {
        func_0x00431b30(0,iStack_174);
        iVar13 = 0;
        if (0 < iStack_174) {
          do {
            piVar4 = (int *)func_0x00763250(4);
            if (piVar4 == (int *)0x0) {
              piVar4 = (int *)0x0;
            }
            else {
              *piVar4 = _DAT_009858e4;
            }
            (**(code **)(*piStack_8 + 0x1c))(piVar4);
            if (*(int *)(param_1 + 0x88) <= *(int *)(param_1 + 0x84)) {
              func_0x0068e120(*(undefined4 *)(param_1 + 0x8c));
            }
            *(int **)(*(int *)(param_1 + 0x80) + *(int *)(param_1 + 0x84) * 4) = piVar4;
            iVar13 = iVar13 + 1;
            *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
          } while (iVar13 < iStack_174);
        }
      }
      if (iStack_17c != 0) {
        if (*(int *)(param_1 + 0x10) == 0) {
          iVar13 = 0;
          if (0 < iStack_17c) {
            do {
              if (*(int *)(param_1 + 0x40) <= *(int *)(param_1 + 0x3c)) {
                func_0x0068e120(*(undefined4 *)(param_1 + 0x44));
              }
              *(undefined4 *)(*(int *)(param_1 + 0x38) + *(int *)(param_1 + 0x3c) * 4) = 0;
              iVar13 = iVar13 + 1;
              *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
            } while (iVar13 < iStack_17c);
          }
        }
        else {
          iStack_1c0 = _DAT_009858e4;
          iStack_1b8 = _DAT_009858e4;
          uStack_10 = 1;
          func_0x0076ef80(*puVar12,&iStack_1c0);
          func_0x0076eee0(*puVar12,&iStack_1b8);
          iVar13 = func_0x00764540(0x2e);
          if (-1 < iVar13) {
            func_0x00764410(*(int *)(iStack_1bc + -8) - iVar13);
          }
          uVar3 = func_0x005117a0(auStack_1a0,&stack0xfffffe3c,0x98b470);
          iStack_14._0_1_ = 2;
          uVar3 = func_0x005145b0(auStack_1a4,uVar3,&iStack_1bc);
          iStack_14._0_1_ = 3;
          func_0x005117a0(&stack0xfffffe30,uVar3,0x9510b0);
          iStack_14._0_1_ = 6;
          func_0x007637f0();
          iStack_14._0_1_ = 5;
          func_0x007637f0();
          func_0x005117a0(auStack_1ac,&stack0xfffffe3c,0x98b464);
          iStack_1b8 = _DAT_009858e4;
          iStack_1b4 = _DAT_009858e4;
          iStack_14._0_1_ = 9;
          iVar13 = 0;
          if (0 < iStack_180) {
            do {
              iStack_1c0 = 0;
              (**(code **)(*piStack_c + 0x1c))(&iStack_1b4);
              uVar3 = func_0x005145b0(auStack_1ac,auStack_1b0,&iStack_1b8);
              uStack_18 = CONCAT31(uStack_18._1_3_,10);
              func_0x00763940(uVar3);
              uStack_1c = 9;
              func_0x007637f0();
              cVar2 = func_0x0077c230(iStack_1c0,&stack0xfffffe38,0,0);
              if ((cVar2 == '\0') || (*(int *)(iStack_1c0 + 0xc) == 0)) {
                if (iStack_1c0 != 0) {
                  func_0x0077c560(&iStack_1c0);
                  iStack_1c0 = 0;
                }
                uVar3 = func_0x005145b0(&stack0xfffffe34,&stack0xfffffe30,&iStack_1b4);
                iStack_14._0_1_ = 0xb;
                func_0x00763940(uVar3);
                uStack_18 = CONCAT31(uStack_18._1_3_,9);
                func_0x007637f0();
                cVar2 = func_0x0077c230(iStack_1bc,&stack0xfffffe3c,0,0);
                if (cVar2 == '\0') {
                  iStack_1c0 = 0;
                }
              }
              iVar5 = iStack_1c0;
              if (*(int *)(param_1 + 0x40) <= *(int *)(param_1 + 0x3c)) {
                func_0x0068e120(*(undefined4 *)(param_1 + 0x44));
              }
              *(int *)(*(int *)(param_1 + 0x38) + *(int *)(param_1 + 0x3c) * 4) = iVar5;
              iVar13 = iVar13 + 1;
              *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
            } while (iVar13 < iStack_180);
          }
          iStack_14._0_1_ = 8;
          func_0x007637f0();
          iStack_14._0_1_ = 7;
          func_0x007637f0();
          iStack_14._0_1_ = 5;
          func_0x007637f0();
          iStack_14._0_1_ = 1;
          func_0x007637f0();
          iStack_14 = (uint)iStack_14._1_3_ << 8;
          func_0x007637f0();
          iStack_14 = 0xffffffff;
          func_0x007637f0();
        }
      }
      iVar13 = 0;
      if (0 < iStack_178) {
        do {
          iVar5 = func_0x00763250(0x58);
          uStack_10 = 0xc;
          if (iVar5 == 0) {
            iVar5 = 0;
          }
          else {
            iVar5 = func_0x007b65a0();
          }
          uStack_10 = 0xffffffff;
          if (iVar5 == 0) {
            uVar3 = 0x98b440;
            goto LAB_00795532;
          }
          cVar2 = func_0x007b67b0(*(undefined4 *)(param_1 + 0x10),piStack_8);
          if (cVar2 == '\0') goto LAB_0079553f;
          *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar5 + 0x1c);
          *(undefined4 *)(iVar5 + 0x28) = 0;
          *(undefined4 *)(iVar5 + 0x20) = *(undefined4 *)(iVar5 + 0x20);
          *(undefined4 *)(iVar5 + 0x24) = *(undefined4 *)(iVar5 + 0x24);
          uStack_124 = *(undefined4 *)(iVar5 + 0x44);
          *(undefined4 *)(iVar5 + 0x3c) = *(undefined4 *)(iVar5 + 0x3c);
          *(undefined4 *)(iVar5 + 0x40) = *(undefined4 *)(iVar5 + 0x40);
          *(undefined4 *)(iVar5 + 0x44) = uStack_124;
          *(undefined4 *)(iVar5 + 0x48) = 0;
          if (*(int *)(param_1 + 0x70) <= *(int *)(param_1 + 0x6c)) {
            func_0x0068e120(*(undefined4 *)(param_1 + 0x74));
          }
          *(int *)(*(int *)(param_1 + 0x68) + *(int *)(param_1 + 0x6c) * 4) = iVar5;
          iVar13 = iVar13 + 1;
          *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + 1;
        } while (iVar13 < iStack_178);
      }
      iVar13 = iStack_18c;
      if (iStack_18c != 0) {
        *(undefined4 *)(param_1 + 0xb4) = 4;
        if (*(int *)(param_1 + 0xb0) < iStack_18c) {
          iVar5 = func_0x00763250(iStack_18c * 0x1c);
          uStack_10 = 0xd;
          if (iVar5 == 0) {
            iVar5 = 0;
          }
          else {
            iVar6 = iVar13;
            if (-1 < iVar13 + -1) {
              do {
                FUN_00795fc0();
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
            }
          }
          uStack_10 = 0xffffffff;
          if (iVar5 == 0) {
            func_0x00764590(1,0x9505a4);
          }
          else {
            if (*(int *)(param_1 + 0xa8) != 0) {
              iVar6 = *(int *)(param_1 + 0xac);
              if (iVar13 <= *(int *)(param_1 + 0xac)) {
                iVar6 = iVar13;
              }
              if (0 < iVar6) {
                iVar9 = 0;
                do {
                  puVar12 = (undefined4 *)(iVar5 + iVar9);
                  puVar11 = (undefined4 *)(*(int *)(param_1 + 0xa8) + iVar9);
                  iVar9 = iVar9 + 0x1c;
                  iVar6 = iVar6 + -1;
                  for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *puVar12 = *puVar11;
                    puVar11 = puVar11 + 1;
                    puVar12 = puVar12 + 1;
                  }
                } while (iVar6 != 0);
              }
              func_0x00763260(*(undefined4 *)(param_1 + 0xa8));
            }
            *(int *)(param_1 + 0xac) = iVar13;
            *(int *)(param_1 + 0xb0) = iVar13;
            *(int *)(param_1 + 0xa8) = iVar5;
          }
        }
        else {
          *(int *)(param_1 + 0xac) = iStack_18c;
        }
        piVar4 = piStack_8;
        iVar13 = 0;
        if (0 < iStack_18c) {
          iVar5 = 0;
          do {
            iVar6 = func_0x007af630(piVar4,param_1,0x1c,iVar13,iStack_18c);
            if (iVar6 == 0) {
              uVar3 = 0x98b414;
              goto LAB_00795532;
            }
            iVar9 = *(int *)(param_1 + 0xa8);
            *(int *)(iVar9 + iVar5) = iVar6;
            iVar9 = iVar9 + iVar5;
            iVar13 = iVar13 + 1;
            iVar5 = iVar5 + 0x1c;
            *(undefined1 *)(iVar9 + 8) = *(undefined1 *)(param_1 + 0x28);
          } while (iVar13 < iStack_18c);
        }
      }
      iVar13 = iStack_188;
      if (iStack_188 != 0) {
        *(undefined4 *)(param_1 + 200) = 4;
        if (*(int *)(param_1 + 0xc4) < iStack_188) {
          iVar5 = func_0x00763250(iStack_188 * 0x1c);
          uStack_10 = 0xe;
          if (iVar5 == 0) {
            iVar5 = 0;
          }
          else {
            iVar6 = iVar13;
            if (-1 < iVar13 + -1) {
              do {
                FUN_00795fc0();
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
            }
          }
          uStack_10 = 0xffffffff;
          if (iVar5 == 0) {
            func_0x00764590(1,0x9505a4);
          }
          else {
            if (*(int *)(param_1 + 0xbc) != 0) {
              iVar6 = iVar13;
              if (*(int *)(param_1 + 0xc0) < iVar13) {
                iVar6 = *(int *)(param_1 + 0xc0);
              }
              if (0 < iVar6) {
                iVar9 = 0;
                do {
                  puVar12 = (undefined4 *)(iVar5 + iVar9);
                  puVar11 = (undefined4 *)(*(int *)(param_1 + 0xbc) + iVar9);
                  iVar9 = iVar9 + 0x1c;
                  iVar6 = iVar6 + -1;
                  for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *puVar12 = *puVar11;
                    puVar11 = puVar11 + 1;
                    puVar12 = puVar12 + 1;
                  }
                } while (iVar6 != 0);
              }
              func_0x00763260(*(undefined4 *)(param_1 + 0xbc));
            }
            *(int *)(param_1 + 0xbc) = iVar5;
            *(int *)(param_1 + 0xc0) = iVar13;
            *(int *)(param_1 + 0xc4) = iVar13;
          }
        }
        else {
          *(int *)(param_1 + 0xc0) = iStack_188;
        }
        piVar4 = piStack_8;
        iVar13 = 0;
        if (0 < iStack_188) {
          iVar5 = 0;
          do {
            iVar6 = func_0x007af630(piVar4,param_1,0x1d,iVar13,iStack_188);
            if (iVar6 == 0) {
              uVar3 = 0x98b3e8;
              goto LAB_00795532;
            }
            *(int *)(*(int *)(param_1 + 0xbc) + iVar5) = iVar6;
            iVar13 = iVar13 + 1;
            iVar5 = iVar5 + 0x1c;
          } while (iVar13 < iStack_188);
        }
      }
      iVar13 = iStack_184;
      if (iStack_184 != 0) {
        *(undefined4 *)(param_1 + 0xdc) = 4;
        if (*(int *)(param_1 + 0xd8) < iStack_184) {
          iVar5 = func_0x00763250(iStack_184 * 0x1c);
          uStack_10 = 0xf;
          if (iVar5 == 0) {
            iVar5 = 0;
          }
          else {
            iVar6 = iVar13;
            if (-1 < iVar13 + -1) {
              do {
                FUN_00795fc0();
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
            }
          }
          uStack_10 = 0xffffffff;
          if (iVar5 == 0) {
            func_0x00764590(1,0x9505a4);
          }
          else {
            if (*(int *)(param_1 + 0xd0) != 0) {
              iVar6 = iVar13;
              if (*(int *)(param_1 + 0xd4) < iVar13) {
                iVar6 = *(int *)(param_1 + 0xd4);
              }
              if (0 < iVar6) {
                iVar9 = 0;
                do {
                  puVar12 = (undefined4 *)(iVar5 + iVar9);
                  puVar11 = (undefined4 *)(*(int *)(param_1 + 0xd0) + iVar9);
                  iVar9 = iVar9 + 0x1c;
                  iVar6 = iVar6 + -1;
                  for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *puVar12 = *puVar11;
                    puVar11 = puVar11 + 1;
                    puVar12 = puVar12 + 1;
                  }
                } while (iVar6 != 0);
              }
              func_0x00763260(*(undefined4 *)(param_1 + 0xd0));
            }
            *(int *)(param_1 + 0xd0) = iVar5;
            *(int *)(param_1 + 0xd4) = iVar13;
            *(int *)(param_1 + 0xd8) = iVar13;
          }
        }
        else {
          *(int *)(param_1 + 0xd4) = iStack_184;
        }
        piVar4 = piStack_8;
        iVar13 = 0;
        if (0 < iStack_184) {
          iVar5 = 0;
          do {
            iVar6 = func_0x007af630(piVar4,param_1,0x1e,iVar13,iStack_184);
            if (iVar6 == 0) {
              uVar3 = 0x98b3b8;
              goto LAB_00795532;
            }
            *(int *)(*(int *)(param_1 + 0xd0) + iVar5) = iVar6;
            iVar13 = iVar13 + 1;
            iVar5 = iVar5 + 0x1c;
          } while (iVar13 < iStack_184);
        }
      }
      iVar13 = iStack_180;
      if (iStack_180 != 0) {
        *(undefined4 *)(param_1 + 0xf0) = 4;
        if (*(int *)(param_1 + 0xec) < iStack_180) {
          iVar5 = func_0x00763250(iStack_180 * 0x1c);
          uStack_10 = 0x10;
          if (iVar5 == 0) {
            iVar5 = 0;
          }
          else {
            iVar6 = iVar13;
            if (-1 < iVar13 + -1) {
              do {
                FUN_00795fc0();
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
            }
          }
          uStack_10 = 0xffffffff;
          if (iVar5 == 0) {
            func_0x00764590(1,0x9505a4);
          }
          else {
            if (*(int *)(param_1 + 0xe4) != 0) {
              iVar6 = iVar13;
              if (*(int *)(param_1 + 0xe8) < iVar13) {
                iVar6 = *(int *)(param_1 + 0xe8);
              }
              if (0 < iVar6) {
                iVar9 = 0;
                do {
                  puVar12 = (undefined4 *)(iVar5 + iVar9);
                  puVar11 = (undefined4 *)(*(int *)(param_1 + 0xe4) + iVar9);
                  iVar9 = iVar9 + 0x1c;
                  iVar6 = iVar6 + -1;
                  for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *puVar12 = *puVar11;
                    puVar11 = puVar11 + 1;
                    puVar12 = puVar12 + 1;
                  }
                } while (iVar6 != 0);
              }
              func_0x00763260(*(undefined4 *)(param_1 + 0xe4));
            }
            *(int *)(param_1 + 0xe4) = iVar5;
            *(int *)(param_1 + 0xe8) = iVar13;
            *(int *)(param_1 + 0xec) = iVar13;
          }
        }
        else {
          *(int *)(param_1 + 0xe8) = iStack_180;
        }
        piVar4 = piStack_8;
        iVar13 = 0;
        if (0 < iStack_180) {
          iVar5 = 0;
          do {
            iVar6 = func_0x007af630(piVar4,param_1,0x1f,iVar13,iStack_180);
            if (iVar6 == 0) {
              uVar3 = 0x98b384;
              goto LAB_00795532;
            }
            *(int *)(*(int *)(param_1 + 0xe4) + iVar5) = iVar6;
            iVar13 = iVar13 + 1;
            iVar5 = iVar5 + 0x1c;
          } while (iVar13 < iStack_180);
        }
      }
      iVar13 = iStack_168;
      if (iStack_168 != 0) {
        *(undefined4 *)(param_1 + 0x104) = 4;
        if (*(int *)(param_1 + 0x100) < iStack_168) {
          iVar5 = func_0x00763250(iStack_168 * 0x1c);
          uStack_10 = 0x11;
          if (iVar5 == 0) {
            iVar5 = 0;
          }
          else {
            iVar6 = iVar13;
            if (-1 < iVar13 + -1) {
              do {
                FUN_00795fc0();
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
            }
          }
          uStack_10 = 0xffffffff;
          if (iVar5 == 0) {
            func_0x00764590(1,0x9505a4);
          }
          else {
            if (*(int *)(param_1 + 0xf8) != 0) {
              iVar6 = iVar13;
              if (*(int *)(param_1 + 0xfc) < iVar13) {
                iVar6 = *(int *)(param_1 + 0xfc);
              }
              if (0 < iVar6) {
                iVar9 = 0;
                do {
                  puVar12 = (undefined4 *)(iVar5 + iVar9);
                  puVar11 = (undefined4 *)(*(int *)(param_1 + 0xf8) + iVar9);
                  iVar9 = iVar9 + 0x1c;
                  iVar6 = iVar6 + -1;
                  for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *puVar12 = *puVar11;
                    puVar11 = puVar11 + 1;
                    puVar12 = puVar12 + 1;
                  }
                } while (iVar6 != 0);
              }
              func_0x00763260(*(undefined4 *)(param_1 + 0xf8));
            }
            *(int *)(param_1 + 0xf8) = iVar5;
            *(int *)(param_1 + 0xfc) = iVar13;
            *(int *)(param_1 + 0x100) = iVar13;
          }
        }
        else {
          *(int *)(param_1 + 0xfc) = iStack_168;
        }
        piVar4 = piStack_8;
        iVar13 = 0;
        if (0 < iStack_168) {
          iVar5 = 0;
          do {
            iVar6 = func_0x007af630(piVar4,param_1,0x23,iVar13,iStack_168);
            if (iVar6 == 0) {
              uVar3 = 0x98b358;
              goto LAB_00795532;
            }
            *(int *)(*(int *)(param_1 + 0xf8) + iVar5) = iVar6;
            iVar13 = iVar13 + 1;
            iVar5 = iVar5 + 0x1c;
          } while (iVar13 < iStack_168);
        }
      }
      iVar13 = iStack_164;
      if (iStack_164 != 0) {
        iStack_1c0 = iStack_164;
        *(undefined4 *)(param_1 + 0x118) = 4;
        if (*(int *)(param_1 + 0x114) < iStack_164) {
          iVar5 = func_0x00763250(iStack_164 * 0x1c);
          uStack_10 = 0x12;
          if (iVar5 == 0) {
            iVar5 = 0;
          }
          else {
            func_0x00401e10(iVar5,0x1c,iVar13,FUN_00795fc0);
          }
          iVar13 = iStack_1c0;
          uStack_10 = 0xffffffff;
          if (iVar5 == 0) {
            func_0x00764590(1,0x9505a4);
          }
          else {
            if (*(int *)(param_1 + 0x10c) != 0) {
              iVar6 = *(int *)(param_1 + 0x110);
              if (iStack_1c0 <= *(int *)(param_1 + 0x110)) {
                iVar6 = iStack_1c0;
              }
              if (0 < iVar6) {
                iVar9 = 0;
                do {
                  puVar12 = (undefined4 *)(iVar5 + iVar9);
                  puVar11 = (undefined4 *)(*(int *)(param_1 + 0x10c) + iVar9);
                  iVar9 = iVar9 + 0x1c;
                  iVar6 = iVar6 + -1;
                  for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
                    *puVar12 = *puVar11;
                    puVar11 = puVar11 + 1;
                    puVar12 = puVar12 + 1;
                  }
                } while (iVar6 != 0);
              }
              func_0x00763260(*(undefined4 *)(param_1 + 0x10c));
            }
            *(int *)(param_1 + 0x110) = iVar13;
            *(int *)(param_1 + 0x114) = iVar13;
            *(int *)(param_1 + 0x10c) = iVar5;
          }
        }
        else {
          *(int *)(param_1 + 0x110) = iStack_164;
        }
        piVar4 = piStack_8;
        iVar13 = 0;
        if (0 < iStack_164) {
          iVar5 = 0;
          do {
            iVar6 = func_0x007af630(piVar4,param_1,0x29,iVar13,iStack_164);
            if (iVar6 == 0) {
              uVar3 = 0x98b32c;
              goto LAB_00795532;
            }
            iVar13 = iVar13 + 1;
            *(int *)(iVar5 + *(int *)(param_1 + 0x10c)) = iVar6;
            iVar5 = iVar5 + 0x1c;
          } while (iVar13 < iStack_164);
        }
      }
      pcVar7 = (code *)func_0x007ab2f0(auStack_1ac);
      if (pcVar7 != (code *)0x0) {
        if (auStack_1ac[0] == 4) {
          (*pcVar7)(param_1);
          uVar3 = 1;
          goto LAB_00795541;
        }
        if (*pcVar7 != (code)0x0) {
          iVar13 = 0;
          if (0 < *(int *)(param_1 + 0x3c)) {
            do {
              pcVar1 = *(char **)(*(int *)(*(int *)(param_1 + 0x38) + iVar13 * 4) + 0x24);
              if ((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) {
                if ((auStack_1ac[0] & 2) != 0) {
                  func_0x0076ee80(pcVar1,auStack_11c,0x104);
                  _strlwr(auStack_11c);
                  puVar8 = (undefined1 *)strstr(auStack_11c,0x950a70);
                  if (puVar8 != auStack_11c) goto LAB_00795516;
                }
                iVar5 = func_0x00785d30(pcVar7);
                if (iVar5 != 0) {
                  FUN_00797020(0,1,pcVar1,0,1);
                  FUN_007956b0(iVar13,iVar5,1);
                  *(undefined1 *)(iVar5 + 0x3c) = 1;
                }
              }
LAB_00795516:
              iVar13 = iVar13 + 1;
            } while (iVar13 < *(int *)(param_1 + 0x3c));
          }
        }
      }
      uVar3 = 1;
      goto LAB_00795541;
    }
    uVar3 = 0x98b2fc;
  }
LAB_00795532:
  func_0x007647d0(0x9d2f20,uVar3);
LAB_0079553f:
  uVar3 = 0;
LAB_00795541:
  *unaff_FS_OFFSET = uStack_18;
  return uVar3;
}


/* ==================================================================== */
/* Address: 0x00795560 | Classified: elementclient::A3DSkin__Load__Cannot_open_file__@0x795560 */
/* ==================================================================== */

undefined4 FUN_00795560(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_248;
  undefined4 uStack_18;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd10b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_248 = 0x795588;
  func_0x0076d760();
  uStack_248 = 0x11;
  uStack_4 = 0;
  cVar1 = func_0x007737f0(&DAT_009b3c44,param_1);
  if (cVar1 == '\0') {
    func_0x0076db10();
    func_0x007647d0(0x9d2f20,0x98b478,param_1);
  }
  else {
    cVar1 = FUN_007947b0(&uStack_248);
    if (cVar1 != '\0') {
      func_0x0076db10();
      func_0x0076d7c0();
      uVar2 = 1;
      goto LAB_00795619;
    }
    func_0x0076db10();
  }
  func_0x0076d7c0();
  uVar2 = 0;
LAB_00795619:
  *unaff_FS_OFFSET = uStack_18;
  return uVar2;
}


/* ==================================================================== */
/* Address: 0x00795640 | Classified: Angelica3D::proc_795640 */
/* ==================================================================== */

undefined4 __fastcall FUN_00795640(int param_1)

{
  if (8 < *(uint *)(param_1 + 0x134)) {
    return *(undefined4 *)(param_1 + 0x84);
  }
  return *(undefined4 *)(param_1 + 0x20);
}


/* ==================================================================== */
/* Address: 0x00795660 | Classified: Angelica3D::proc_795660 */
/* ==================================================================== */

void FUN_00795660(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uStack_4;
  
  uVar3 = 0;
  puVar2 = &uStack_4;
  uStack_4 = 0;
  cVar1 = func_0x0077c230(param_2,puVar2,0,0);
  if (cVar1 == '\0') {
    return;
  }
  FUN_007956b0(uVar3,puVar2,uStack_4);
  return;
}


/* ==================================================================== */
/* Address: 0x007956b0 | Classified: Angelica3D::proc_7956b0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007956b0(int param_1,int param_2,int param_3,char param_4)

{
  int *piVar1;
  undefined3 uVar2;
  undefined3 extraout_var;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x38) + param_2 * 4);
  param_2 = *piVar1;
  *piVar1 = param_3;
  uVar2 = (undefined3)((uint)piVar1 >> 8);
  if ((param_4 != '\0') && (uVar2 = 0, param_2 != 0)) {
    func_0x0077c560(&param_2);
    uVar2 = extraout_var;
  }
  return CONCAT31(uVar2,1);
}


/* ==================================================================== */
/* Address: 0x00795700 | Classified: Angelica3D::proc_795700 */
/* ==================================================================== */

int __thiscall FUN_00795700(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0xac)) {
    iVar3 = 0;
    do {
      iVar1 = _stricmp(*(undefined4 *)(*(int *)(iVar3 + *(int *)(param_1 + 0xa8)) + 8),param_2);
      if (iVar1 == 0) {
        return *(int *)(param_1 + 0xa8) + iVar2 * 0x1c;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x1c;
    } while (iVar2 < *(int *)(param_1 + 0xac));
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x00795770 | Classified: Angelica3D::proc_795770 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * __fastcall FUN_00795770(int param_1)

{
  int iVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  float unaff_EBP;
  int iVar5;
  float unaff_ESI;
  float unaff_EDI;
  float *pfStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  undefined4 *puStack_60;
  float fStack_5c;
  float *pfStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  
  fStack_5c = 999999.0;
  puStack_60 = (undefined4 *)0x497423f0;
  fStack_64 = 999999.0;
  fStack_68 = 1.1143508e-38;
  func_0x005ca8a0();
  fStack_68 = -999999.0;
  fStack_6c = -999999.0;
  fStack_70 = -999999.0;
  fStack_74 = 1.1143542e-38;
  func_0x005ca8a0();
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0xac)) {
    iVar5 = 0;
    do {
      pfStack_78 = &fStack_30;
      iVar1 = *(int *)(*(int *)(param_1 + 0xa8) + iVar5);
      fStack_74 = (float)(iVar1 + 0x3c);
      pfVar3 = (float *)func_0x00787e10(&stack0xffffffac);
      fStack_30 = *pfVar3;
      fStack_2c = pfVar3[1];
      fStack_28 = pfVar3[2];
      pfVar3 = (float *)func_0x00787e80(&puStack_60,&fStack_24,iVar1 + 0x48);
      fStack_24 = *pfVar3;
      fStack_20 = pfVar3[1];
      fStack_1c = pfVar3[2];
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x1c;
    } while (iVar4 < *(int *)(param_1 + 0xac));
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0xc0)) {
    iVar5 = 0;
    do {
      pfStack_78 = &fStack_30;
      iVar1 = *(int *)(*(int *)(param_1 + 0xbc) + iVar5);
      fStack_74 = (float)(iVar1 + 0x3c);
      pfVar3 = (float *)func_0x00787e10(&stack0xffffffac);
      fStack_30 = *pfVar3;
      fStack_2c = pfVar3[1];
      fStack_28 = pfVar3[2];
      pfVar3 = (float *)func_0x00787e80(&puStack_60,&fStack_24,iVar1 + 0x48);
      fStack_24 = *pfVar3;
      fStack_20 = pfVar3[1];
      fStack_1c = pfVar3[2];
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x1c;
    } while (iVar4 < *(int *)(param_1 + 0xc0));
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0xd4)) {
    iVar5 = 0;
    do {
      pfStack_78 = &fStack_30;
      iVar1 = *(int *)(*(int *)(param_1 + 0xd0) + iVar5);
      fStack_74 = (float)(iVar1 + 0x3c);
      pfVar3 = (float *)func_0x00787e10(&stack0xffffffac);
      fStack_30 = *pfVar3;
      fStack_2c = pfVar3[1];
      fStack_28 = pfVar3[2];
      pfVar3 = (float *)func_0x00787e80(&puStack_60,&fStack_24,iVar1 + 0x48);
      fStack_24 = *pfVar3;
      fStack_20 = pfVar3[1];
      fStack_1c = pfVar3[2];
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x1c;
    } while (iVar4 < *(int *)(param_1 + 0xd4));
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0xe8)) {
    iVar5 = 0;
    do {
      pfStack_78 = &fStack_30;
      iVar1 = *(int *)(*(int *)(param_1 + 0xe4) + iVar5);
      fStack_74 = (float)(iVar1 + 0x3c);
      pfVar3 = (float *)func_0x00787e10(&stack0xffffffac);
      fStack_30 = *pfVar3;
      fStack_2c = pfVar3[1];
      fStack_28 = pfVar3[2];
      pfVar3 = (float *)func_0x00787e80(&puStack_60,&fStack_24,iVar1 + 0x48);
      fStack_24 = *pfVar3;
      fStack_20 = pfVar3[1];
      fStack_1c = pfVar3[2];
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x1c;
    } while (iVar4 < *(int *)(param_1 + 0xe8));
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0xfc)) {
    iVar5 = 0;
    do {
      pfStack_78 = &fStack_30;
      iVar1 = *(int *)(*(int *)(param_1 + 0xf8) + iVar5);
      fStack_74 = (float)(iVar1 + 0x3c);
      pfVar3 = (float *)func_0x00787e10(&stack0xffffffac);
      fStack_30 = *pfVar3;
      fStack_2c = pfVar3[1];
      fStack_28 = pfVar3[2];
      pfVar3 = (float *)func_0x00787e80(&puStack_60,&fStack_24,iVar1 + 0x48);
      fStack_24 = *pfVar3;
      fStack_20 = pfVar3[1];
      fStack_1c = pfVar3[2];
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x1c;
    } while (iVar4 < *(int *)(param_1 + 0xfc));
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x110)) {
    iVar5 = 0;
    do {
      pfStack_78 = &fStack_30;
      iVar1 = *(int *)(*(int *)(param_1 + 0x10c) + iVar5);
      fStack_74 = (float)(iVar1 + 0x3c);
      pfVar3 = (float *)func_0x00787e10(&stack0xffffffac);
      fStack_30 = *pfVar3;
      fStack_2c = pfVar3[1];
      fStack_28 = pfVar3[2];
      pfVar3 = (float *)func_0x00787e80(&puStack_60,&fStack_24,iVar1 + 0x48);
      fStack_24 = *pfVar3;
      fStack_20 = pfVar3[1];
      fStack_1c = pfVar3[2];
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x1c;
    } while (iVar4 < *(int *)(param_1 + 0x110));
  }
  fStack_74 = fStack_1c + fStack_28;
  pfStack_78 = (float *)(fStack_20 + fStack_2c);
  func_0x00401ca0(fStack_24 + fStack_30);
  func_0x00401ca0((float)puStack_60 * _DAT_008eff98,fStack_5c * _DAT_008eff98,
                  unaff_EDI * _DAT_008eff98);
  fVar2 = fStack_70;
  fStack_5c = fStack_74;
  puStack_60 = pfStack_78;
  func_0x00401ca0((float)pfStack_3c - (float)pfStack_78,fStack_38 - fStack_74,fStack_34 - fStack_70)
  ;
  func_0x00401cc0(&pfStack_78);
  *pfStack_3c = fStack_70;
  pfStack_3c[1] = fStack_6c;
  pfStack_3c[2] = fStack_68;
  pfStack_3c[3] = fStack_64;
  pfStack_3c[4] = (float)puStack_60;
  pfStack_3c[5] = fStack_5c;
  pfStack_3c[6] = fVar2;
  pfStack_3c[7] = unaff_ESI;
  pfStack_3c[8] = unaff_EBP;
  func_0x00401cc0(&stack0xffffffb4);
  return pfStack_3c;
}


/* ==================================================================== */
/* Address: 0x00795ba0 | Classified: Angelica3D::proc_795ba0 */
/* ==================================================================== */

void __thiscall FUN_00795ba0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0xac)) {
    iVar2 = 0;
    do {
      iVar1 = iVar1 + 1;
      *(undefined4 *)(iVar2 + 0xc + *(int *)(param_1 + 0xa8)) = param_2;
      iVar2 = iVar2 + 0x1c;
    } while (iVar1 < *(int *)(param_1 + 0xac));
  }
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0xc0)) {
    iVar2 = 0;
    do {
      iVar1 = iVar1 + 1;
      *(undefined4 *)(iVar2 + 0xc + *(int *)(param_1 + 0xbc)) = param_2;
      iVar2 = iVar2 + 0x1c;
    } while (iVar1 < *(int *)(param_1 + 0xc0));
  }
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0xd4)) {
    iVar2 = 0;
    do {
      iVar1 = iVar1 + 1;
      *(undefined4 *)(iVar2 + 0xc + *(int *)(param_1 + 0xd0)) = param_2;
      iVar2 = iVar2 + 0x1c;
    } while (iVar1 < *(int *)(param_1 + 0xd4));
  }
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0xe8)) {
    iVar2 = 0;
    do {
      iVar1 = iVar1 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0xe4) + 0xc + iVar2) = param_2;
      iVar2 = iVar2 + 0x1c;
    } while (iVar1 < *(int *)(param_1 + 0xe8));
  }
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0xfc)) {
    iVar2 = 0;
    do {
      iVar1 = iVar1 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0xf8) + 0xc + iVar2) = param_2;
      iVar2 = iVar2 + 0x1c;
    } while (iVar1 < *(int *)(param_1 + 0xfc));
  }
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x110)) {
    iVar2 = 0;
    do {
      iVar1 = iVar1 + 1;
      *(undefined4 *)(iVar2 + 0xc + *(int *)(param_1 + 0x10c)) = param_2;
      iVar2 = iVar2 + 0x1c;
    } while (iVar1 < *(int *)(param_1 + 0x110));
  }
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x124)) {
    iVar2 = 0;
    do {
      iVar1 = iVar1 + 1;
      *(undefined4 *)(iVar2 + 0xc + *(int *)(param_1 + 0x120)) = param_2;
      iVar2 = iVar2 + 0x1c;
    } while (iVar1 < *(int *)(param_1 + 0x124));
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00795cd0 | Classified: elementclient::AArray__SetSize__Not_enough_memo@0x795cd0 */
/* ==================================================================== */

uint __thiscall FUN_00795cd0(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uStack_4;
  
  uVar2 = FUN_00795640();
  if (*(int *)(param_2 + 0xf0) < (int)uVar2) {
    return uVar2 & 0xffffff00;
  }
  if (8 < *(uint *)(param_1 + 0x134)) {
    iVar3 = *(int *)(param_1 + 0x84);
    *(undefined4 *)(param_1 + 0xa0) = 0x10;
    iVar7 = iVar3 + 1;
    if (iVar7 == 0) {
      func_0x004acc40(1);
    }
    else {
      if (*(int *)(param_1 + 0x9c) < iVar7) {
        iVar6 = func_0x00763250(iVar7 * 4);
        if (iVar6 == 0) {
          func_0x00764590(1,0x9505a4);
          goto LAB_00795e58;
        }
        if (*(int *)(param_1 + 0x94) != 0) {
          iVar4 = *(int *)(param_1 + 0x98);
          if (iVar7 <= *(int *)(param_1 + 0x98)) {
            iVar4 = iVar7;
          }
          iVar5 = 0;
          if (0 < iVar4) {
            do {
              iVar5 = iVar5 + 1;
              *(undefined4 *)(iVar6 + -4 + iVar5 * 4) =
                   *(undefined4 *)(*(int *)(param_1 + 0x94) + -4 + iVar5 * 4);
            } while (iVar5 < iVar4);
          }
          func_0x00763260(*(undefined4 *)(param_1 + 0x94));
        }
        *(int *)(param_1 + 0x94) = iVar6;
        *(int *)(param_1 + 0x9c) = iVar7;
      }
      *(int *)(param_1 + 0x98) = iVar7;
    }
LAB_00795e58:
    iVar7 = 0;
    if (0 < iVar3) {
      do {
        uStack_4 = 0xffffffff;
        iVar6 = func_0x007b3690(**(undefined4 **)(*(int *)(param_1 + 0x80) + iVar7 * 4),&uStack_4);
        if (iVar6 == 0) {
          uVar2 = func_0x007647d0(0x9d2f20,0x98b4a0,*(undefined4 *)(param_1 + 0x18),
                                  *(undefined4 *)(param_2 + 0xb8));
          return uVar2 & 0xffffff00;
        }
        *(undefined4 *)(*(int *)(param_1 + 0x94) + iVar7 * 4) = uStack_4;
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar3);
    }
    uVar1 = *(undefined4 *)(param_2 + 0xf0);
    *(undefined4 *)(*(int *)(param_1 + 0x94) + iVar3 * 4) = uVar1;
    return CONCAT31((int3)((uint)uVar1 >> 8),1);
  }
  *(undefined4 *)(param_1 + 0xa0) = 0x10;
  iVar7 = *(int *)(param_1 + 0x20) + 1;
  if (iVar7 == 0) {
    func_0x004acc40(1);
  }
  else {
    if (*(int *)(param_1 + 0x9c) < iVar7) {
      iVar3 = func_0x00763250(iVar7 * 4);
      if (iVar3 == 0) {
        func_0x00764590(1,0x9505a4);
        goto LAB_00795d8a;
      }
      if (*(int *)(param_1 + 0x94) != 0) {
        iVar6 = *(int *)(param_1 + 0x98);
        if (iVar7 <= *(int *)(param_1 + 0x98)) {
          iVar6 = iVar7;
        }
        iVar4 = 0;
        if (0 < iVar6) {
          do {
            iVar4 = iVar4 + 1;
            *(undefined4 *)(iVar3 + -4 + iVar4 * 4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x94) + -4 + iVar4 * 4);
          } while (iVar4 < iVar6);
        }
        func_0x00763260(*(undefined4 *)(param_1 + 0x94));
      }
      *(int *)(param_1 + 0x9c) = iVar7;
      *(int *)(param_1 + 0x94) = iVar3;
    }
    *(int *)(param_1 + 0x98) = iVar7;
  }
LAB_00795d8a:
  iVar7 = 0;
  if (0 < *(int *)(param_1 + 0x20)) {
    do {
      *(int *)(*(int *)(param_1 + 0x94) + iVar7 * 4) = iVar7;
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)(param_1 + 0x20));
  }
  iVar7 = *(int *)(param_1 + 0x94);
  *(undefined4 *)(iVar7 + *(int *)(param_1 + 0x20) * 4) = *(undefined4 *)(param_2 + 0xf0);
  return CONCAT31((int3)((uint)iVar7 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x00795ef0 | Classified: Angelica3D::proc_795ef0 */
/* ==================================================================== */

void __fastcall FUN_00795ef0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = 0;
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x124)) {
    do {
      piVar3 = (int *)(*(int *)(param_1 + 0x120) + iVar1);
      if ((int *)*piVar3 != (int *)0x0) {
        (**(code **)(*(int *)*piVar3 + 0xc))();
        if ((undefined4 *)*piVar3 != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)*piVar3)(1);
        }
        *piVar3 = 0;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x1c;
    } while (iVar2 < *(int *)(param_1 + 0x124));
  }
  if (*(int *)(param_1 + 0x120) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x120));
    *(undefined4 *)(param_1 + 0x120) = 0;
  }
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00795f70 | Classified: Angelica3D::proc_795f70 */
/* ==================================================================== */

void __fastcall FUN_00795f70(undefined4 *param_1)

{
  *param_1 = &UNK_008f138c;
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
/* Address: 0x00795fa0 | Classified: Angelica3D::proc_795fa0 */
/* ==================================================================== */

undefined4 __thiscall FUN_00795fa0(undefined4 param_1,byte param_2)

{
  FUN_00795f70();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00795fc0 | Classified: Angelica3D::proc_795fc0 */
/* ==================================================================== */

void __fastcall FUN_00795fc0(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[4] = 0;
  param_1[3] = 0xbf800000;
  param_1[5] = 0;
  param_1[6] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00795fe0 | Classified: Angelica3D::proc_795fe0 */
/* ==================================================================== */

void __fastcall FUN_00795fe0(undefined4 *param_1)

{
  *param_1 = &UNK_008f1388;
  if (param_1[1] != 0) {
    func_0x00763260(param_1[1]);
    param_1[1] = 0;
  }
  param_1[3] = 0;
  param_1[2] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00796010 | Classified: Angelica3D::proc_796010 */
/* ==================================================================== */

undefined4 * __thiscall FUN_00796010(undefined4 *param_1,byte param_2)

{
  *param_1 = &UNK_008f1388;
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
/* Address: 0x00796090 | Classified: Angelica3D::proc_796090 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00796090(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puRam009d2d94 = &UNK_008d5a30;
  uRam009d2d98 = 0;
  uRam009d2d9c = 0;
  uRam009d2da0 = 0;
  uRam009d2da4 = 0x10;
  puRam009d2d90 = &UNK_008dacd0;
  uRam009d2d80 = 0;
  uRam009d2d84 = 0;
  uRam009d2d88 = 0;
  uRam009d2d8c = 0;
  uRam009d2da8 = 0;
  _DAT_009d2dac = 2;
  _DAT_009d2db0 = 1;
  uRam009d2db4 = 1;
  _DAT_009d2db8 = 2;
  _DAT_009d2dbc = 1;
  uRam009d2dc0 = 1;
  _DAT_009d2dc4 = 2;
  _DAT_009d2dc8 = 1;
  uRam009d2dd8 = 0;
  uRam009d2dd4 = 0;
  uRam009d2dd0 = 0;
  uRam009d2dcc = 0;
  uRam009d2ddc = 8;
  uRam009d2de0 = 0x80;
  uRam009d2de4 = 1;
  uRam009d2de8 = 0;
  _DAT_009d2dec = 0;
  puVar2 = (undefined4 *)0x9d2df0;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  _DAT_009d2e30 = 0;
  _DAT_009d2e34 = 0;
  _DAT_009d2e38 = 0;
  _DAT_009d2e3c = 0;
  _DAT_009d2e40 = 0;
  _DAT_009d2e44 = 0;
  uRam009d2e48 = 0;
  uRam009d2e4c = 0;
  uRam009d2e50 = 0;
  puVar2 = (undefined4 *)0x9d2e54;
  for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  uRam009d2eb4 = 2;
  uRam009d2eb8 = 1;
  return 0x9d2d80;
}


/* ==================================================================== */
/* Address: 0x007960a0 | Classified: Angelica3D::proc_7960a0 */
/* ==================================================================== */

void FUN_007960a0(void)

{
  func_0x00892e60(&UNK_007960b0);
  return;
}


/* ==================================================================== */
/* Address: 0x007960d0 | Classified: Angelica3D::proc_7960d0 */
/* ==================================================================== */

undefined4 * __fastcall FUN_007960d0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  *(undefined1 *)(param_1 + 2) = 1;
  *(undefined1 *)((int)param_1 + 9) = 1;
  *param_1 = 0;
  param_1[1] = 4;
  param_1[3] = 8;
  param_1[4] = 0x80;
  param_1[5] = 3;
  param_1[6] = 5;
  param_1[7] = 6;
  param_1[8] = 0;
  puVar2 = param_1 + 9;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = param_1 + 0xf;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x16] = 0;
  param_1[0x15] = 0xffffffff;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00796140 | Classified: Angelica3D::proc_796140 */
/* ==================================================================== */

undefined4 * __fastcall FUN_00796140(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  param_1[5] = &UNK_008d5a30;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0x10;
  param_1[4] = &UNK_008dacd0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[10] = 0;
  param_1[0xb] = 2;
  param_1[0xc] = 1;
  param_1[0xd] = 1;
  param_1[0xe] = 2;
  param_1[0xf] = 1;
  param_1[0x10] = 1;
  param_1[0x11] = 2;
  param_1[0x12] = 1;
  param_1[0x16] = 0;
  param_1[0x15] = 0;
  param_1[0x14] = 0;
  param_1[0x13] = 0;
  param_1[0x17] = 8;
  param_1[0x18] = 0x80;
  param_1[0x19] = 1;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  puVar2 = param_1 + 0x1c;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  puVar2 = param_1 + 0x35;
  for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x4d] = 2;
  param_1[0x4e] = 1;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00796220 | Classified: Angelica3D::proc_796220 */
/* ==================================================================== */

undefined4 __thiscall FUN_00796220(undefined4 param_1,undefined4 param_2)

{
  FUN_00796240(param_2);
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00796240 | Classified: elementclient::AArray__SetSize__Not_enough_memo@0x796240 */
/* ==================================================================== */

void __thiscall FUN_00796240(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  puVar1 = param_2;
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  iVar3 = param_2[7];
  param_1[9] = 4;
  if (iVar3 == 0) {
    func_0x004acc40(1);
  }
  else {
    if ((int)param_1[8] < iVar3) {
      iVar6 = func_0x00763250(iVar3 * 4);
      if (iVar6 == 0) {
        func_0x00764590(1,0x9505a4);
        goto LAB_007962f7;
      }
      if (param_1[6] != 0) {
        iVar5 = param_1[7];
        if (iVar3 <= (int)param_1[7]) {
          iVar5 = iVar3;
        }
        iVar2 = 0;
        if (0 < iVar5) {
          do {
            iVar2 = iVar2 + 1;
            *(undefined4 *)(iVar6 + -4 + iVar2 * 4) = *(undefined4 *)(param_1[6] + -4 + iVar2 * 4);
          } while (iVar2 < iVar5);
        }
        func_0x00763260(param_1[6]);
      }
      param_1[8] = iVar3;
      param_1[6] = iVar6;
    }
    param_1[7] = iVar3;
  }
LAB_007962f7:
  iVar3 = 0;
  if (0 < (int)param_2[7]) {
    do {
      *(undefined4 *)(param_1[6] + iVar3 * 4) = *(undefined4 *)(param_2[6] + iVar3 * 4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)param_2[7]);
  }
  param_1[10] = param_2[10];
  param_1[0xb] = param_2[0xb];
  param_1[0xc] = param_2[0xc];
  param_1[0xd] = param_2[0xd];
  param_1[0xe] = param_2[0xe];
  param_1[0xf] = param_2[0xf];
  param_1[0x10] = param_2[0x10];
  param_1[0x11] = param_2[0x11];
  param_1[0x12] = param_2[0x12];
  param_1[0x13] = param_2[0x13];
  param_1[0x14] = param_2[0x14];
  param_1[0x15] = param_2[0x15];
  param_1[0x16] = param_2[0x16];
  param_1[0x17] = param_2[0x17];
  param_1[0x18] = param_2[0x18];
  param_1[0x19] = param_2[0x19];
  param_1[0x1a] = param_2[0x1a];
  param_1[0x1b] = param_2[0x1b];
  puVar4 = param_1 + 0x1c;
  iVar6 = (int)param_2 - (int)param_1;
  iVar3 = 0x10;
  do {
    *puVar4 = *(undefined4 *)(iVar6 + (int)puVar4);
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar4 = param_2 + 0x2c;
  param_2 = (undefined4 *)0x4;
  param_1[0x2c] = *puVar4;
  param_1[0x2d] = puVar1[0x2d];
  param_1[0x2e] = puVar1[0x2e];
  param_1[0x2f] = puVar1[0x2f];
  param_1[0x30] = puVar1[0x30];
  param_1[0x31] = puVar1[0x31];
  param_1[0x32] = puVar1[0x32];
  param_1[0x33] = puVar1[0x33];
  param_1[0x34] = puVar1[0x34];
  puVar4 = param_1 + 0x35;
  do {
    puVar7 = (undefined4 *)((int)puVar4 + iVar6);
    puVar8 = puVar4;
    for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    param_2 = (undefined4 *)((int)param_2 + -1);
    puVar4 = puVar4 + 6;
  } while (param_2 != (undefined4 *)0x0);
  param_1[0x4d] = puVar1[0x4d];
  param_1[0x4e] = puVar1[0x4e];
  return;
}


/* ==================================================================== */
/* Address: 0x00796450 | Classified: Angelica3D::proc_796450 */
/* ==================================================================== */

undefined4 * __fastcall FUN_00796450(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd128;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  func_0x0078a330();
  uStack_4 = 0;
  FUN_007960d0();
  func_0x00892e84(param_1 + 0x2a,0x13c,8,FUN_00796140);
  *param_1 = &UNK_008f1400;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x2a2] = 0;
  param_1[0x2a4] = 0;
  param_1[0x2a3] = 0;
  *(undefined1 *)((int)param_1 + 0x35) = 0;
  *(undefined1 *)((int)param_1 + 0x36) = 1;
  *(undefined1 *)(param_1 + 0xf) = 0;
  puVar2 = param_1 + 0x2a5;
  for (iVar1 = 0x42; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = param_1 + 0x2e7;
  for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *unaff_FS_OFFSET = &UNK_004a7bd0;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00796500 | Classified: Angelica3D::proc_796500 */
/* ==================================================================== */

undefined4 __thiscall FUN_00796500(undefined4 param_1,byte param_2)

{
  FUN_00796520();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00796520 | Classified: Angelica3D::proc_796520 */
/* ==================================================================== */

void __fastcall FUN_00796520(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar1;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008cd148;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f1400;
  uVar1 = 8;
  uStack_4 = 0;
  func_0x00892d40(param_1 + 0x2a,0x13c,8,&UNK_004a7bd0);
  func_0x0078a3a0();
  *unaff_FS_OFFSET = uVar1;
  return;
}


/* ==================================================================== */
/* Address: 0x00796610 | Classified: Angelica3D::proc_796610 */
/* ==================================================================== */

undefined4 __fastcall FUN_00796610(int param_1)

{
  undefined4 in_EAX;
  int iVar1;
  int iVar2;
  
  iVar1 = CONCAT31((int3)((uint)in_EAX >> 8),*(char *)(param_1 + 0x34));
  if (*(char *)(param_1 + 0x34) == '\0') {
    FUN_00796ff0();
    iVar1 = *(int *)(param_1 + 0xa88);
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        FUN_00796f80(iVar2);
        iVar1 = *(int *)(param_1 + 0xa88);
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x00796650 | Classified: Angelica3D::proc_796650 */
/* ==================================================================== */

undefined4 __fastcall FUN_00796650(int param_1)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  
  if (*(char *)(param_1 + 0x34) == '\0') {
    FUN_00796740();
    if (*(int *)(param_1 + 0xa88) == 0) {
      func_0x0077aab0(0);
      return 1;
    }
    iVar1 = 0;
    iVar4 = 0;
    if (0 < *(int *)(param_1 + 0xa88)) {
      pbVar3 = (byte *)(param_1 + 0xac);
      iVar2 = iVar1;
      do {
        iVar1 = iVar2;
        if ((~*pbVar3 & 1) != 0) {
          iVar1 = iVar2 + 1;
          FUN_00796860(iVar2,iVar4);
        }
        if (*(int *)(param_1 + 0xa8c) <= iVar1) break;
        iVar4 = iVar4 + 1;
        pbVar3 = pbVar3 + 0x13c;
        iVar2 = iVar1;
      } while (iVar4 < *(int *)(param_1 + 0xa88));
    }
    if (((*(char *)(param_1 + 0x3c) == '\0') && (iVar1 != 0)) && (iVar1 < 8)) {
      func_0x00779fc0(iVar1,1);
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007966e0 | Classified: Angelica3D::proc_7966e0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007966e0(int param_1)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  
  if (*(char *)(param_1 + 0x34) == '\0') {
    FUN_00796cc0();
    iVar4 = 0;
    if (0 < *(int *)(param_1 + 0xa88)) {
      pbVar3 = (byte *)(param_1 + 0xac);
      iVar1 = 0;
      do {
        iVar2 = iVar1;
        if ((~*pbVar3 & 1) != 0) {
          iVar2 = iVar1 + 1;
          FUN_00796d70(iVar1,iVar4);
        }
        if (*(int *)(param_1 + 0xa8c) <= iVar2) {
          return 1;
        }
        iVar4 = iVar4 + 1;
        pbVar3 = pbVar3 + 0x13c;
        iVar1 = iVar2;
      } while (iVar4 < *(int *)(param_1 + 0xa88));
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00796740 | Classified: Angelica3D::proc_796740 */
/* ==================================================================== */

void __fastcall FUN_00796740(int param_1)

{
  if ((*(byte *)(param_1 + 0x4c) & 1) != 0) {
    func_0x0077a270(*(undefined4 *)(param_1 + 0x50));
  }
  if ((*(byte *)(param_1 + 0x4c) & 2) != 0) {
    func_0x0077a210(*(undefined1 *)(param_1 + 0x54));
  }
  if ((*(byte *)(param_1 + 0x4c) & 4) != 0) {
    func_0x0077a230(*(undefined1 *)(param_1 + 0x55));
  }
  if ((*(byte *)(param_1 + 0x4c) & 8) != 0) {
    func_0x0077a320(1);
    func_0x0077a360(*(undefined4 *)(param_1 + 0x58));
    func_0x0077a380(*(undefined4 *)(param_1 + 0x5c));
  }
  if ((*(byte *)(param_1 + 0x4c) & 0x10) != 0) {
    func_0x0077a540(*(undefined4 *)(param_1 + 0x60));
  }
  if ((*(byte *)(param_1 + 0x4c) & 0x20) != 0) {
    func_0x0077a290(1);
    func_0x0077a2c0(*(undefined4 *)(param_1 + 100));
    func_0x0077a2f0(*(undefined4 *)(param_1 + 0x68));
  }
  if ((*(uint *)(param_1 + 0x4c) & 0x100) != 0) {
    func_0x0077aaf0(*(undefined4 *)(param_1 + 0xa0));
  }
  if (*(int *)(param_1 + 0x6c) != 0) {
    if ((*(uint *)(param_1 + 0x4c) & 0x100) != 0) {
      func_0x00799460(*(undefined4 *)(param_1 + 0xa0));
      func_0x0077b9f0(0,&stack0xffffffec,1);
    }
    if ((*(uint *)(param_1 + 0x4c) & 0x200) != 0) {
      func_0x00799460(*(undefined4 *)(param_1 + 0xa4));
      func_0x0077b9f0(1,&stack0xffffffec,1);
    }
    func_0x0078a2c0();
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00796860 | Classified: Angelica3D::proc_796860 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00796860(int param_1,undefined4 param_2,int param_3)

{
  uint *puVar1;
  int *piVar2;
  uint *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  undefined4 *puVar8;
  int unaff_retaddr;
  uint uVar9;
  int iStack_4c;
  undefined1 auStack_48 [60];
  undefined4 uStack_c;
  undefined4 uStack_4;
  
  puVar1 = (uint *)(param_1 + 0xa8 + param_3 * 0x13c);
  func_0x0077a120(param_2,0);
  if (puVar1[7] != 0) {
    uVar5 = puVar1[2];
    if (uVar5 == 1) {
      if (*(int **)puVar1[6] != (int *)0x0) {
        (**(code **)(**(int **)puVar1[6] + 0x18))(param_2);
      }
    }
    else if (uVar5 == 6) {
      piVar2 = *(int **)(puVar1[6] + *(int *)(param_1 + 0xba0 + param_3 * 0x14) * 4);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x18))(param_2);
      }
    }
    else if ((uVar5 == 7) && (*(int *)puVar1[6] != 0)) {
      func_0x0078bcd0(param_2);
    }
  }
  if ((*puVar1 & 1) != 0) {
    func_0x00779f60(param_2,puVar1[0xb]);
  }
  if ((*puVar1 & 2) != 0) {
    func_0x0077a0e0(param_2,puVar1[0xc],puVar1[0xc]);
  }
  if ((char)(byte)*puVar1 < '\0') {
    func_0x0077a160(param_2,puVar1[0x2c],puVar1[0x2d],puVar1[0x2e],puVar1[0x2f]);
  }
  if ((*puVar1 & 0x100) != 0) {
    func_0x0077a1b0(param_2,puVar1[0x30]);
  }
  if ((*puVar1 & 0x200) != 0) {
    func_0x0077a1d0(param_2,puVar1[0x31]);
  }
  if ((*puVar1 & 0x800) != 0) {
    func_0x0077a1f0(param_2,puVar1[0x1b]);
    puVar3 = puVar1 + 0x1c;
    puVar7 = (uint *)&stack0xffffff6c;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar7 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar7 = puVar7 + 1;
    }
    func_0x00779da0(uStack_c,&stack0xffffff6c);
    param_2 = uStack_4;
    param_3 = unaff_retaddr;
  }
  if ((*puVar1 & 0x1000) != 0) {
    func_0x0077a120(param_2,puVar1[0x1a]);
  }
  if (puVar1[0x34] != 0) {
    func_0x00787fa0(&stack0xffffff74);
    iStack_4c = 0;
    if (0 < (int)puVar1[0x34]) {
      puVar3 = puVar1 + 0x38;
      do {
        switch(puVar3[-3]) {
        case 3:
          break;
        case 4:
          break;
        case 5:
          puVar4 = (undefined4 *)
                   func_0x00788c50(auStack_48,&stack0xffffff74,
                                   *(undefined4 *)(param_1 + 0xafc + param_3 * 4));
          puVar8 = (undefined4 *)&stack0xffffff74;
          for (iVar6 = 0x10; param_2 = uStack_4, param_3 = unaff_retaddr, iVar6 != 0;
              iVar6 = iVar6 + -1) {
            *puVar8 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar8 = puVar8 + 1;
          }
          break;
        case 6:
          break;
        case 7:
        }
        iStack_4c = iStack_4c + 1;
        puVar3 = puVar3 + 6;
      } while (iStack_4c < (int)puVar1[0x34]);
    }
    func_0x0077a1f0(param_2,2);
    func_0x00779da0(param_2,&stack0xffffff6c);
  }
  if (*(int *)(param_1 + 0x6c) == 0) {
    uVar5 = func_0x0077a0a0(param_2);
    puVar1[0x4d] = uVar5;
    if ((*puVar1 & 4) == 0) {
      func_0x00779fc0(param_2,4);
      uVar5 = 1;
      uVar9 = 2;
    }
    else {
      func_0x00779fc0(param_2,puVar1[0xd]);
      uVar5 = puVar1[0xf];
      uVar9 = puVar1[0xe];
    }
    func_0x00779fe0(param_2,uVar9,uVar5);
    uVar5 = func_0x0077a0c0(param_2);
    puVar1[0x4e] = uVar5;
    if ((*puVar1 & 8) == 0) {
      func_0x0077a020(param_2,1);
    }
    else {
      func_0x0077a020(param_2,puVar1[0x10]);
      func_0x0077a040(param_2,puVar1[0x11],puVar1[0x12]);
    }
    if ((*puVar1 & 0x400) != 0) {
      func_0x0077a080(param_2,puVar1[0x19]);
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00796cc0 | Classified: Angelica3D::proc_796cc0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00796cc0(int param_1)

{
  undefined4 in_EAX;
  
  if ((*(byte *)(param_1 + 0x4c) & 1) != 0) {
    in_EAX = func_0x0077a270(_DAT_009d2ec4);
  }
  if ((*(byte *)(param_1 + 0x4c) & 2) != 0) {
    in_EAX = func_0x0077a210(DAT_009d2ec8);
  }
  if ((*(byte *)(param_1 + 0x4c) & 4) != 0) {
    in_EAX = func_0x0077a230(DAT_009d2ec9);
  }
  if ((*(byte *)(param_1 + 0x4c) & 8) != 0) {
    in_EAX = func_0x0077a320(0);
  }
  if ((*(byte *)(param_1 + 0x4c) & 0x10) != 0) {
    in_EAX = func_0x0077a540(_DAT_009d2ed4);
  }
  if ((*(byte *)(param_1 + 0x4c) & 0x20) != 0) {
    func_0x0077a290(1);
    func_0x0077a2c0(_DAT_009d2ed8);
    in_EAX = func_0x0077a2f0(_DAT_009d2edc);
  }
  if (*(int *)(param_1 + 0x6c) != 0) {
    if (_DAT_009d2d74 == *(int *)(param_1 + 0x6c)) {
      func_0x0077bec0(0);
      _DAT_009d2d74 = 0;
    }
    return 1;
  }
  return in_EAX;
}


/* ==================================================================== */
/* Address: 0x00796d70 | Classified: Angelica3D::proc_796d70 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00796d70(int param_1,undefined4 param_2,int param_3)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 + 0xa8 + param_3 * 0x13c);
  if ((*(int *)(param_1 + 0xc4 + param_3 * 0x13c) != 0) && (*(int *)puVar1[6] != 0)) {
    func_0x0077aab0(param_2);
  }
  if ((*puVar1 & 1) != 0) {
    func_0x00779f60(param_2,_DAT_009d2dac);
  }
  if ((*puVar1 & 2) != 0) {
    func_0x0077a0e0(param_2,_DAT_009d2db0,_DAT_009d2db0);
  }
  if ((char)(byte)*puVar1 < '\0') {
    func_0x0077a160(param_2,_DAT_009d2e30,_DAT_009d2e34,_DAT_009d2e38,_DAT_009d2e3c);
  }
  if ((*puVar1 & 0x100) != 0) {
    func_0x0077a1b0(param_2,_DAT_009d2e40);
  }
  if ((*puVar1 & 0x200) != 0) {
    func_0x0077a1d0(param_2,_DAT_009d2e44);
  }
  if ((*puVar1 & 0x800) != 0) {
    func_0x0077a1f0(param_2,_DAT_009d2dec);
    func_0x00779da0(param_2,0x9d2f28);
  }
  func_0x0077a120(param_2,param_2);
  if (puVar1[0x34] != 0) {
    func_0x0077a1f0(param_2,0);
  }
  if (*(int *)(param_1 + 0x6c) == 0) {
    func_0x00779fc0(param_2,puVar1[0x4d]);
    if ((*puVar1 & 4) != 0) {
      func_0x00779fe0(param_2,_DAT_009d2db8,_DAT_009d2dbc);
    }
    func_0x0077a020(param_2,puVar1[0x4e]);
    if ((*puVar1 & 8) != 0) {
      func_0x0077a040(param_2,_DAT_009d2dc4,_DAT_009d2dc8);
    }
    if ((*puVar1 & 0x400) != 0) {
      func_0x0077a080(param_2,1);
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00796ee0 | Classified: Angelica3D::proc_796ee0 */
/* ==================================================================== */

uint __thiscall FUN_00796ee0(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = *(uint *)(param_1 + 0xa88);
  if (((int)uVar1 < 8) && (-2 < param_2)) {
    if ((param_2 != -1) && ((param_2 < (int)uVar1 && (iVar2 = uVar1 - 1, param_2 <= iVar2)))) {
      iVar3 = (iVar2 - param_2) + 1;
      iVar2 = param_1 + 0x1e4 + iVar2 * 0x13c;
      do {
        iVar2 = iVar2 + -0x13c;
        FUN_00796220(iVar2);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    FUN_00796220(param_3);
    iVar2 = *(int *)(param_1 + 0xa88) + 1;
    *(int *)(param_1 + 0xa88) = iVar2;
    return CONCAT31((int3)((uint)iVar2 >> 8),1);
  }
  return uVar1 & 0xffffff00;
}


/* ==================================================================== */
/* Address: 0x00796f80 | Classified: Angelica3D::proc_796f80 */
/* ==================================================================== */

void __thiscall FUN_00796f80(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x44) != 0) {
    iVar2 = *(int *)(param_1 + 0xc4 + param_2 * 0x13c);
    iVar1 = param_1 + 0xa8 + param_2 * 0x13c;
    if (iVar2 != 0) {
      if ((*(int *)(iVar1 + 8) != 7) && (iVar3 = 0, 0 < iVar2)) {
        do {
          param_2 = *(int *)(*(int *)(iVar1 + 0x18) + iVar3 * 4);
          if (param_2 != 0) {
            func_0x0077c560(&param_2);
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(int *)(iVar1 + 0x1c));
      }
      *(undefined4 *)(iVar1 + 0x1c) = 0;
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00796ff0 | Classified: Angelica3D::proc_796ff0 */
/* ==================================================================== */

void __fastcall FUN_00796ff0(int param_1)

{
  if ((*(int *)(param_1 + 0x6c) != 0) && (*(int *)(param_1 + 0x44) != 0)) {
    func_0x00786290((undefined4 *)(param_1 + 0x6c));
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00797020 | Classified: elementclient::AArray__Allocate__Not_enough_mem@0x797020 */
/* ==================================================================== */

undefined4 __thiscall FUN_00797020(int param_1,int param_2,char *param_3,int param_4)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int unaff_retaddr;
  undefined4 uVar9;
  int iStack_238;
  char acStack_21c [260];
  char acStack_118 [276];
  int iStack_4;
  
  iVar7 = 0;
  if (-1 < param_2) {
    iStack_238 = param_2;
    FUN_00796f80();
    iVar1 = param_1 + 0xa8 + param_2 * 0x13c;
    *(int *)(iVar1 + 8) = param_2;
    *(int *)(iVar1 + 0xc) = param_4;
    if (param_2 == 1) {
      if (param_4 == 0) {
        cVar2 = func_0x0077c230(param_3,&stack0xfffffdd8,0);
      }
      else {
        cVar2 = func_0x0077c710(param_3,0,0,param_4,0,&stack0xfffffdd8,0);
      }
      iVar7 = iStack_238;
      if (cVar2 != '\0') {
        if ((*(int *)(iVar1 + 0x20) <= *(int *)(iVar1 + 0x1c)) && (*(int *)(iVar1 + 0x24) != 0)) {
          iVar8 = *(int *)(iVar1 + 0x24) + *(int *)(iVar1 + 0x20);
          iVar3 = func_0x00763250(iVar8 * 4);
          if (iVar3 == 0) {
            func_0x00764590(1,0x94e51c);
          }
          else {
            iVar4 = 0;
            if (0 < *(int *)(iVar1 + 0x1c)) {
              do {
                iVar4 = iVar4 + 1;
                *(undefined4 *)(iVar3 + -4 + iVar4 * 4) =
                     *(undefined4 *)(*(int *)(iVar1 + 0x18) + -4 + iVar4 * 4);
              } while (iVar4 < *(int *)(iVar1 + 0x1c));
            }
            if (*(int *)(iVar1 + 0x18) != 0) {
              func_0x00763260(*(int *)(iVar1 + 0x18));
            }
            *(int *)(iVar1 + 0x18) = iVar3;
            *(int *)(iVar1 + 0x20) = iVar8;
          }
        }
        *(int *)(*(int *)(iVar1 + 0x18) + *(int *)(iVar1 + 0x1c) * 4) = iVar7;
        *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + 1;
        return 1;
      }
      uVar9 = 0x98b52c;
    }
    else {
      if (param_2 != 6) {
        return 0;
      }
      puVar5 = (undefined1 *)strrchr(param_3,0x2e);
      if (puVar5 == (undefined1 *)0x0) {
        uVar9 = 0x98b4f8;
      }
      else {
        *puVar5 = 0;
        iVar3 = -(int)param_3;
        do {
          cVar2 = *param_3;
          param_3[(int)(acStack_118 + iVar3)] = cVar2;
          param_3 = param_3 + 1;
        } while (cVar2 != '\0');
        sprintf(&stack0xfffffdd4,0x98b4f4,puVar5 + 1);
        iStack_238 = 0;
        if (unaff_retaddr < 1) {
          return 1;
        }
        while( true ) {
          sprintf(acStack_21c,0x98b4e8,acStack_118,iVar7,&stack0xfffffdd4);
          if (iStack_4 == 0) {
            cVar2 = func_0x0077c230(acStack_21c,&iStack_238,0);
          }
          else {
            cVar2 = func_0x0077c710(acStack_21c,0,0,iStack_4,0,&iStack_238,0);
          }
          iVar3 = iStack_238;
          if (cVar2 == '\0') break;
          if ((*(int *)(iVar1 + 0x20) <= *(int *)(iVar1 + 0x1c)) && (*(int *)(iVar1 + 0x24) != 0)) {
            iVar4 = *(int *)(iVar1 + 0x24) + *(int *)(iVar1 + 0x20);
            iVar8 = func_0x00763250(iVar4 * 4);
            if (iVar8 == 0) {
              func_0x00764590(1,0x94e51c);
            }
            else {
              iVar6 = 0;
              if (0 < *(int *)(iVar1 + 0x1c)) {
                do {
                  iVar6 = iVar6 + 1;
                  *(undefined4 *)(iVar8 + -4 + iVar6 * 4) =
                       *(undefined4 *)(*(int *)(iVar1 + 0x18) + -4 + iVar6 * 4);
                } while (iVar6 < *(int *)(iVar1 + 0x1c));
              }
              if (*(int *)(iVar1 + 0x18) != 0) {
                func_0x00763260(*(int *)(iVar1 + 0x18));
              }
              *(int *)(iVar1 + 0x18) = iVar8;
              *(int *)(iVar1 + 0x20) = iVar4;
            }
          }
          *(int *)(*(int *)(iVar1 + 0x18) + *(int *)(iVar1 + 0x1c) * 4) = iVar3;
          iVar7 = iVar7 + 1;
          *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + 1;
          if (unaff_retaddr <= iVar7) {
            return 1;
          }
        }
        param_3 = acStack_21c;
        uVar9 = 0x98b52c;
      }
    }
    func_0x007647d0(0x9d2f20,uVar9,param_3);
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x007972e0 | Classified: Angelica3D::proc_7972e0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007972e0(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x6c) != 0) {
    FUN_00796ff0();
  }
  if (param_2 != 0) {
    iVar1 = func_0x00785fa0(param_2,0);
    if (iVar1 == 0) {
      return 0;
    }
    *(int *)(param_1 + 0x6c) = iVar1;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00797320 | Classified: elementclient::A3DShader__Load__Failed_to_open_s@0x797320 */
/* ==================================================================== */

uint __thiscall FUN_00797320(int *param_1,int param_2)

{
  char cVar1;
  undefined3 uVar4;
  int iVar2;
  uint uVar3;
  undefined3 extraout_var;
  undefined4 *unaff_FS_OFFSET;
  int *piStack_83c;
  undefined1 *puStack_838;
  undefined4 uStack_834;
  int iStack_830;
  int iStack_82c;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cd16b;
  *unaff_FS_OFFSET = &uStack_c;
  uVar4 = (undefined3)((uint)uStack_c >> 8);
  if ((char)param_1[0xd] == '\0') {
    iStack_82c = 0x797353;
    func_0x0076f270();
    iStack_82c = param_2;
    uStack_4 = 0;
    iStack_830 = 0x79736f;
    cVar1 = func_0x0076f2c0();
    if (cVar1 == '\0') {
      iStack_830 = 0x98b620;
      uStack_834 = 0x9d2f20;
      puStack_838 = (undefined1 *)0x797382;
      func_0x007647d0();
    }
    else {
      iStack_830 = param_2 + 0x10c;
      uStack_834 = 0x797399;
      func_0x007638a0();
      param_1[10] = (int)param_1;
      if ((param_1[0x13] != 0) || (param_1[0x2a2] != 0)) {
        uStack_834 = 0x7973b4;
        (**(code **)(*param_1 + 0xc))();
      }
      param_1[0x2a2] = 0;
      uStack_834 = 0x7973c7;
      func_0x0076f480();
      uStack_834 = 1;
      puStack_838 = (undefined1 *)0x7973d2;
      cVar1 = func_0x0076f4a0();
      if (cVar1 == '\0') {
        puStack_838 = (undefined1 *)0x98b5ec;
        piStack_83c = (int *)0x9d2f20;
        func_0x007647d0();
      }
      else {
        piStack_83c = (int *)&stack0xfffff7d8;
        puStack_838 = (undefined1 *)0x94e2d8;
        puStack_838 = (undefined1 *)_stricmp();
        if (puStack_838 == (undefined1 *)0x0) {
          piStack_83c = (int *)0x797410;
          func_0x0076f4a0();
          piStack_83c = &iStack_82c;
          iVar2 = atoi();
          param_1[0x12] = iVar2;
          piStack_83c = (int *)0x1;
          cVar1 = func_0x0076f4a0();
          if (cVar1 == '\0') {
            puStack_838 = (undefined1 *)0x98b5bc;
            piStack_83c = (int *)0x9d2f20;
            func_0x007647d0();
            goto LAB_007974e8;
          }
        }
        else {
          param_1[0x12] = 1;
        }
        puStack_838 = &stack0xfffff7d8;
        piStack_83c = (int *)0x79745a;
        (**(code **)(*param_1 + 4))();
        piStack_83c = (int *)0x0;
        cVar1 = func_0x0076f6e0(0x95221c);
        if (cVar1 != '\0') {
          cVar1 = func_0x0076f6b0(1);
          while (cVar1 != '\0') {
            iVar2 = _stricmp(&puStack_838,0x952218);
            if (iVar2 == 0) {
              func_0x0076f4a0(1);
              break;
            }
            iVar2 = _stricmp(&puStack_838,0x95221c);
            if (iVar2 == 0) {
              cVar1 = FUN_00797580(&piStack_83c);
              if (cVar1 == '\0') {
                puStack_838 = (undefined1 *)param_1[0x2a2];
                piStack_83c = (int *)0x98b568;
                func_0x007647d0(0x9d2f20);
                goto LAB_007974e8;
              }
            }
            else {
              cVar1 = FUN_00798500(&piStack_83c);
              if (cVar1 == '\0') goto LAB_007974e8;
            }
            puStack_838 = (undefined1 *)0x1;
            piStack_83c = (int *)0x797524;
            cVar1 = func_0x0076f6b0();
          }
          func_0x0076f450();
          func_0x0076f2b0();
          uVar4 = extraout_var;
          goto LAB_00797549;
        }
        func_0x007647d0(0x9d2f20,0x98b590);
      }
LAB_007974e8:
      puStack_838 = (undefined1 *)0x7974f1;
      func_0x0076f450();
    }
    puStack_8 = (undefined *)0xffffffff;
    iStack_830 = 0x797505;
    uVar3 = func_0x0076f2b0();
    uVar3 = uVar3 & 0xffffff00;
  }
  else {
LAB_00797549:
    uVar3 = CONCAT31(uVar4,1);
  }
  *unaff_FS_OFFSET = uStack_c;
  return uVar3;
}


/* ==================================================================== */
/* Address: 0x00797580 | Classified: elementclient::A3DShader__LoadStage__Too_many_s@0x797580 */
/* ==================================================================== */

uint __thiscall FUN_00797580(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  if (7 < *(int *)(param_1 + 0xa88)) {
    uVar2 = func_0x007647d0(0x9d2f20,0x98b650);
    return uVar2 & 0xffffff00;
  }
  *(undefined4 *)(param_1 + 0xa8 + *(int *)(param_1 + 0xa88) * 0x13c) = 0;
  uVar2 = func_0x0076f6e0(0x95221c,0);
  if ((char)uVar2 == '\0') {
LAB_007975d3:
    return uVar2 & 0xffffff00;
  }
  cVar1 = func_0x0076f6b0(1);
  if (cVar1 != '\0') {
    do {
      iVar3 = _stricmp(param_2 + 4,0x952218);
      if (iVar3 == 0) {
        func_0x0076f4a0(1);
        break;
      }
      uVar2 = FUN_00797640(param_2);
      if ((char)uVar2 == '\0') goto LAB_007975d3;
      cVar1 = func_0x0076f6b0(1);
    } while (cVar1 != '\0');
  }
  iVar3 = *(int *)(param_1 + 0xa88) + 1;
  *(int *)(param_1 + 0xa88) = iVar3;
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x00797640 | Classified: elementclient::texture@0x797640 */
/* ==================================================================== */

undefined1 __thiscall FUN_00797640(int param_1,int param_2)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_EBX;
  uint *puVar7;
  uint *puVar8;
  char *pcVar9;
  float10 fVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iStack_174;
  undefined1 auStack_170 [3];
  undefined1 uStack_16d;
  int aiStack_16c [22];
  char acStack_114 [8];
  char acStack_10c [268];
  
  cVar2 = (char)((uint)unaff_EBX >> 0x18);
  uVar12 = 1;
  pcVar9 = (char *)(param_2 + 4);
  puVar8 = (uint *)(param_1 + 0xa8 + *(int *)(param_1 + 0xa88) * 0x13c);
  uStack_16d = 1;
  aiStack_16c[0] = param_1;
  cVar1 = func_0x0076f4a0(1);
  if (cVar1 == '\0') {
    return 0;
  }
  pcVar3 = pcVar9;
  do {
    cVar1 = *pcVar3;
    pcVar3[(int)aiStack_16c - (int)pcVar9] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  iVar4 = _stricmp(aiStack_16c,0x97b380);
  if (iVar4 == 0) {
    cVar2 = func_0x0076f4a0(0);
    if (cVar2 != '\0') {
      iVar4 = _stricmp(pcVar9,0x98bbf4);
      if (iVar4 == 0) {
        puVar8[2] = 1;
      }
      else {
        iVar4 = _stricmp(pcVar9,0x98bbe4);
        if (iVar4 == 0) {
          puVar8[2] = 2;
        }
        else {
          iVar4 = _stricmp(pcVar9,0x98bbd8);
          if (iVar4 == 0) {
            puVar8[2] = 3;
          }
          else {
            iVar4 = _stricmp(pcVar9,0x98bbcc);
            if (iVar4 == 0) {
              puVar8[2] = 4;
            }
            else {
              iVar4 = _stricmp(pcVar9,0x98bbc0);
              if (iVar4 == 0) {
                puVar8[2] = 5;
              }
              else {
                iVar4 = _stricmp(pcVar9,0x98bbb0);
                if (iVar4 == 0) {
                  puVar8[2] = 6;
                }
                else {
                  iVar4 = _stricmp(pcVar9,0x98bba4);
                  if (iVar4 != 0) goto LAB_007984c2;
                  puVar8[2] = 7;
                }
              }
            }
          }
        }
      }
      if (*(int *)(iStack_174 + 0x48) < 3) {
        puVar8[3] = 0;
      }
      else {
        func_0x0076f4a0(0);
        uVar5 = atoi(pcVar9);
        puVar8[3] = uVar5;
      }
      cVar2 = func_0x0076f4a0(0);
      if (cVar2 != '\0') {
        if (puVar8[2] == 1) {
          if (*(int *)(iStack_174 + 0x48) == 1) {
            sprintf(acStack_10c,0x98bb90,pcVar9);
          }
          else {
            iVar4 = -(int)pcVar9;
            do {
              cVar2 = *pcVar9;
              pcVar9[(int)(acStack_10c + iVar4)] = cVar2;
              pcVar9 = pcVar9 + 1;
            } while (cVar2 != '\0');
          }
          FUN_00797020(*(undefined4 *)(iStack_174 + 0xa88),puVar8[2],acStack_10c,puVar8[3],1);
        }
        else if (puVar8[2] == 6) {
          iVar4 = atoi(pcVar9);
          if (iVar4 < 0) {
            iVar4 = 0;
          }
          func_0x0076f4a0(0);
          uVar5 = atoi(pcVar9);
          puVar8[10] = uVar5;
          func_0x0076f4a0(0);
          if (*(int *)(iVar4 + 0x48) == 1) {
            sprintf(acStack_114,0x98bb90,pcVar9);
          }
          else {
            iVar6 = (int)acStack_114 - (int)pcVar9;
            do {
              cVar2 = *pcVar9;
              pcVar9[iVar6] = cVar2;
              pcVar9 = pcVar9 + 1;
            } while (cVar2 != '\0');
          }
          FUN_00797020(*(undefined4 *)(iVar4 + 0xa88),puVar8[2],acStack_114,puVar8[3],uVar12);
        }
        goto LAB_007984e1;
      }
    }
LAB_007984c2:
    uVar12 = *(undefined4 *)(iStack_174 + 8);
    uVar11 = 0x98b678;
  }
  else {
    iVar4 = _stricmp(aiStack_16c,0x98bb88);
    if (iVar4 == 0) {
      cVar2 = func_0x0076f4a0(0);
      if (cVar2 != '\0') {
        iVar4 = _stricmp(pcVar9,0x98bb7c);
        if (iVar4 == 0) {
          puVar8[0xb] = 0;
          *puVar8 = *puVar8 | 1;
          goto LAB_007984e1;
        }
        iVar4 = _stricmp(pcVar9,0x98bb70);
        if (iVar4 == 0) {
          puVar8[0xb] = 1;
          *puVar8 = *puVar8 | 1;
          goto LAB_007984e1;
        }
        iVar4 = _stricmp(pcVar9,0x98bb64);
        if (iVar4 == 0) {
          puVar8[0xb] = 2;
          *puVar8 = *puVar8 | 1;
          goto LAB_007984e1;
        }
        iVar4 = _stricmp(pcVar9,0x98bb50);
        if (iVar4 == 0) {
          puVar8[0xb] = 3;
          *puVar8 = *puVar8 | 1;
          goto LAB_007984e1;
        }
        iVar4 = _stricmp(pcVar9,0x98bb40);
        if (iVar4 == 0) {
          puVar8[0xb] = 4;
          *puVar8 = *puVar8 | 1;
          goto LAB_007984e1;
        }
        iVar4 = _stricmp(pcVar9,0x98bb2c);
        if (iVar4 == 0) {
          puVar8[0xb] = 5;
          *puVar8 = *puVar8 | 1;
          goto LAB_007984e1;
        }
      }
      goto LAB_007984c2;
    }
    iVar4 = _stricmp(aiStack_16c,0x972394);
    if (iVar4 == 0) {
      cVar2 = func_0x0076f4a0(0);
      if (cVar2 != '\0') {
        iVar4 = _stricmp(pcVar9,0x98bb20);
        if (iVar4 == 0) {
          puVar8[0xc] = 1;
          *puVar8 = *puVar8 | 2;
          goto LAB_007984e1;
        }
        iVar4 = _stricmp(pcVar9,0x98bb10);
        if (iVar4 == 0) {
          puVar8[0xc] = 2;
          *puVar8 = *puVar8 | 2;
          goto LAB_007984e1;
        }
        iVar4 = _stricmp(pcVar9,0x98bb04);
        if (iVar4 == 0) {
          puVar8[0xc] = 3;
          *puVar8 = *puVar8 | 2;
          goto LAB_007984e1;
        }
        iVar4 = _stricmp(pcVar9,0x98baf4);
        if (iVar4 == 0) {
          puVar8[0xc] = 4;
          *puVar8 = *puVar8 | 2;
          goto LAB_007984e1;
        }
        iVar4 = _stricmp(pcVar9,0x98bae0);
        if (iVar4 == 0) {
          puVar8[0xc] = 5;
          *puVar8 = *puVar8 | 2;
          goto LAB_007984e1;
        }
      }
      goto LAB_007984c2;
    }
    iVar4 = _stricmp(aiStack_16c,0x98bad8);
    if ((iVar4 == 0) || (iVar4 = _stricmp(aiStack_16c,0x98bad0), iVar4 == 0)) {
      cVar2 = func_0x0076f4a0(0);
      if (cVar2 != '\0') {
        iVar4 = _stricmp(auStack_170,0x98bad8);
        if (iVar4 == 0) {
          puVar7 = puVar8 + 0xd;
          uVar5 = 4;
        }
        else {
          puVar7 = puVar8 + 0x10;
          uVar5 = 8;
        }
        iVar4 = _stricmp(pcVar9,0x98b8b8);
        if (iVar4 == 0) {
          *puVar7 = 1;
        }
        else {
          iVar4 = _stricmp(pcVar9,0x98b8a8);
          if (iVar4 == 0) {
            *puVar7 = 2;
          }
          else {
            iVar4 = _stricmp(pcVar9,0x98b898);
            if (iVar4 == 0) {
              *puVar7 = 3;
            }
            else {
              iVar4 = _stricmp(pcVar9,0x98b888);
              if (iVar4 == 0) {
                *puVar7 = 4;
              }
              else {
                iVar4 = _stricmp(pcVar9,0x98b878);
                if (iVar4 == 0) {
                  *puVar7 = 5;
                }
                else {
                  iVar4 = _stricmp(pcVar9,0x98b868);
                  if (iVar4 == 0) {
                    *puVar7 = 6;
                  }
                  else {
                    iVar4 = _stricmp(pcVar9,0x98b860);
                    if (iVar4 == 0) {
                      *puVar7 = 7;
                    }
                    else {
                      iVar4 = _stricmp(pcVar9,0x98b850);
                      if (iVar4 == 0) {
                        *puVar7 = 8;
                      }
                      else {
                        iVar4 = _stricmp(pcVar9,0x98b840);
                        if (iVar4 == 0) {
                          *puVar7 = 9;
                        }
                        else {
                          iVar4 = _stricmp(pcVar9,0x98b830);
                          if (iVar4 == 0) {
                            *puVar7 = 10;
                          }
                          else {
                            iVar4 = _stricmp(pcVar9,0x98b820);
                            if (iVar4 == 0) {
                              *puVar7 = 0xb;
                            }
                            else {
                              iVar4 = _stricmp(pcVar9,0x98b808);
                              if (iVar4 == 0) {
                                *puVar7 = 0xc;
                              }
                              else {
                                iVar4 = _stricmp(pcVar9,0x98b7f0);
                                if (iVar4 == 0) {
                                  *puVar7 = 0xd;
                                }
                                else {
                                  iVar4 = _stricmp(pcVar9,0x98b7d8);
                                  if (iVar4 == 0) {
                                    *puVar7 = 0xe;
                                  }
                                  else {
                                    iVar4 = _stricmp(pcVar9,0x98b7c0);
                                    if (iVar4 == 0) {
                                      *puVar7 = 0xf;
                                    }
                                    else {
                                      iVar4 = _stricmp(pcVar9,0x98b7a8);
                                      if (iVar4 == 0) {
                                        *puVar7 = 0x10;
                                      }
                                      else {
                                        iVar4 = _stricmp(pcVar9,0x98b798);
                                        if (iVar4 == 0) {
                                          *puVar7 = 0x11;
                                        }
                                        else {
                                          iVar4 = _stricmp(pcVar9,0x98b77c);
                                          if (iVar4 == 0) {
                                            *puVar7 = 0x12;
                                          }
                                          else {
                                            iVar4 = _stricmp(pcVar9,0x98b760);
                                            if (iVar4 == 0) {
                                              *puVar7 = 0x13;
                                            }
                                            else {
                                              iVar4 = _stricmp(pcVar9,0x98b740);
                                              if (iVar4 == 0) {
                                                *puVar7 = 0x14;
                                              }
                                              else {
                                                iVar4 = _stricmp(pcVar9,0x98b720);
                                                if (iVar4 == 0) {
                                                  *puVar7 = 0x15;
                                                }
                                                else {
                                                  iVar4 = _stricmp(pcVar9,0x98b710);
                                                  if (iVar4 == 0) {
                                                    *puVar7 = 0x16;
                                                  }
                                                  else {
                                                    iVar4 = _stricmp(pcVar9,0x98b6f8);
                                                    if (iVar4 == 0) {
                                                      *puVar7 = 0x17;
                                                    }
                                                    else {
                                                      iVar4 = _stricmp(pcVar9,0x98b6e8);
                                                      if (iVar4 == 0) {
                                                        *puVar7 = 0x18;
                                                      }
                                                      else {
                                                        iVar4 = _stricmp(pcVar9,0x98b6d8);
                                                        if (iVar4 == 0) {
                                                          *puVar7 = 0x19;
                                                        }
                                                        else {
                                                          iVar4 = _stricmp(pcVar9,0x98b6cc);
                                                          if (iVar4 != 0) goto LAB_007984c2;
                                                          *puVar7 = 0x1a;
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
          }
        }
        *puVar8 = *puVar8 | uVar5;
        goto LAB_007984e1;
      }
      goto LAB_007984c2;
    }
    iVar4 = _stricmp(aiStack_16c,0x98bac4);
    if ((((iVar4 == 0) || (iVar4 = _stricmp(aiStack_16c,0x98bab8), iVar4 == 0)) ||
        (iVar4 = _stricmp(aiStack_16c,0x98baac), iVar4 == 0)) ||
       (iVar4 = _stricmp(aiStack_16c,0x98baa0), iVar4 == 0)) {
      cVar1 = func_0x0076f4a0(0);
      if (cVar1 == '\0') goto LAB_007984c2;
      iVar4 = _stricmp(auStack_170,0x98bac4);
      if (iVar4 == 0) {
        puVar8 = puVar8 + 0xe;
      }
      else {
        iVar4 = _stricmp(auStack_170,0x98bab8);
        if (iVar4 == 0) {
          puVar8 = puVar8 + 0xf;
        }
        else {
          iVar4 = _stricmp(auStack_170,0x98baac);
          if (iVar4 == 0) {
            puVar8 = puVar8 + 0x11;
          }
          else {
            puVar8 = puVar8 + 0x12;
          }
        }
      }
      iVar4 = _stricmp(pcVar9,0x98b9fc);
      if (iVar4 == 0) {
        *puVar8 = 1;
      }
      else {
        iVar4 = _stricmp(pcVar9,0x98b91c);
        if (iVar4 == 0) {
          *puVar8 = 0;
        }
        else {
          iVar4 = _stricmp(pcVar9,0x98b90c);
          if (iVar4 == 0) {
            *puVar8 = 0xf;
          }
          else {
            iVar4 = _stricmp(pcVar9,0x98b900);
            if (iVar4 == 0) {
              *puVar8 = 4;
            }
            else {
              iVar4 = _stricmp(pcVar9,0x98b9f4);
              if (iVar4 == 0) {
                *puVar8 = 5;
              }
              else {
                iVar4 = _stricmp(pcVar9,0x98b8f4);
                if (iVar4 == 0) {
                  *puVar8 = 2;
                }
                else {
                  iVar4 = _stricmp(pcVar9,0x98b8e8);
                  if (iVar4 == 0) {
                    *puVar8 = 3;
                  }
                  else {
                    cVar2 = '\0';
                  }
                }
              }
            }
          }
        }
      }
      cVar1 = func_0x0076f4a0(0);
      if (cVar1 != '\0') {
        iVar4 = _stricmp(pcVar9,0x98b8d8);
        if (iVar4 == 0) {
          uVar5 = *puVar8 | 0x10;
        }
        else {
          iVar4 = _stricmp(pcVar9,0x98b8c4);
          if (iVar4 != 0) goto joined_r0x007981b5;
          uVar5 = *puVar8 | 0x20;
        }
        *puVar8 = uVar5;
      }
joined_r0x007981b5:
      if (cVar2 != '\0') goto LAB_007984e1;
      goto LAB_007984c2;
    }
    iVar4 = _stricmp(aiStack_16c,0x98ba94);
    if (((iVar4 == 0) || (iVar4 = _stricmp(auStack_170,0x98ba88), iVar4 == 0)) ||
       (iVar4 = _stricmp(auStack_170,0x98ba7c), iVar4 == 0)) goto LAB_007984e1;
    iVar4 = _stricmp(auStack_170,0x98ba74);
    if (iVar4 == 0) {
      cVar2 = func_0x0076f4a0(0);
      if (cVar2 != '\0') {
        fVar10 = (float10)atof(pcVar9);
        puVar8[0x2c] = (uint)(float)fVar10;
        func_0x0076f4a0(0);
        fVar10 = (float10)atof(pcVar9);
        puVar8[0x2d] = (uint)(float)fVar10;
        func_0x0076f4a0(0);
        fVar10 = (float10)atof(pcVar9);
        puVar8[0x2e] = (uint)(float)fVar10;
        func_0x0076f4a0(0);
        fVar10 = (float10)atof(pcVar9);
        puVar8[0x2f] = (uint)(float)fVar10;
        *puVar8 = *puVar8 | 0x80;
        goto LAB_007984e1;
      }
      goto LAB_007984c2;
    }
    iVar4 = _stricmp(auStack_170,0x98ba68);
    if (iVar4 == 0) {
      cVar2 = func_0x0076f4a0(0);
      if (cVar2 != '\0') {
        fVar10 = (float10)atof(pcVar9);
        puVar8[0x30] = (uint)(float)fVar10;
        *puVar8 = *puVar8 | 0x100;
        goto LAB_007984e1;
      }
      goto LAB_007984c2;
    }
    iVar4 = _stricmp(auStack_170,0x98ba60);
    if (iVar4 == 0) {
      cVar2 = func_0x0076f4a0(0);
      if (cVar2 != '\0') {
        fVar10 = (float10)atof(pcVar9);
        puVar8[0x31] = (uint)(float)fVar10;
        *puVar8 = *puVar8 | 0x200;
        goto LAB_007984e1;
      }
      goto LAB_007984c2;
    }
    iVar4 = _stricmp(auStack_170,0x98ba54);
    if ((iVar4 == 0) || (iVar4 = _stricmp(auStack_170,0x98ba48), iVar4 == 0)) goto LAB_007984e1;
    iVar4 = _stricmp(auStack_170,0x98ba40);
    if (iVar4 == 0) {
      uVar12 = 3;
LAB_00797d54:
      cVar2 = func_0x00798b50(param_2,uVar12,puVar8);
      goto joined_r0x007981b5;
    }
    iVar4 = _stricmp(auStack_170,0x98ba34);
    if (iVar4 == 0) {
      uVar12 = 4;
      goto LAB_00797d54;
    }
    iVar4 = _stricmp(auStack_170,0x98ba28);
    if (iVar4 == 0) {
      uVar12 = 5;
      goto LAB_00797d54;
    }
    iVar4 = _stricmp(auStack_170,0x98ba1c);
    if (iVar4 == 0) {
      uVar12 = 6;
      goto LAB_00797d54;
    }
    iVar4 = _stricmp(auStack_170,0x98ba14);
    if (iVar4 == 0) {
      uVar12 = 7;
      goto LAB_00797d54;
    }
    iVar4 = _stricmp(auStack_170,0x98ba08);
    if (iVar4 == 0) {
      cVar2 = func_0x0076f4a0(0);
      if (cVar2 != '\0') {
        iVar4 = _stricmp(pcVar9,0x98b9fc);
        if (iVar4 == 0) {
          puVar8[0x19] = 1;
          *puVar8 = *puVar8 | 0x400;
          goto LAB_007984e1;
        }
        iVar4 = _stricmp(pcVar9,0x98b9f4);
        if (iVar4 == 0) {
          puVar8[0x19] = 5;
          *puVar8 = *puVar8 | 0x400;
          goto LAB_007984e1;
        }
      }
      goto LAB_007984c2;
    }
    iVar4 = _stricmp(auStack_170,0x98b9e8);
    if (iVar4 == 0) {
      func_0x0076f4a0(0);
      uVar5 = atoi(pcVar9);
      puVar8[0x1b] = uVar5;
      func_0x0076f4a0(0);
      fVar10 = (float10)atof(pcVar9);
      puVar8[0x1c] = (uint)(float)fVar10;
      func_0x0076f4a0(0);
      fVar10 = (float10)atof(pcVar9);
      puVar8[0x1d] = (uint)(float)fVar10;
      func_0x0076f4a0(0);
      fVar10 = (float10)atof(pcVar9);
      puVar8[0x1e] = (uint)(float)fVar10;
      func_0x0076f4a0(0);
      fVar10 = (float10)atof(pcVar9);
      puVar8[0x1f] = (uint)(float)fVar10;
      func_0x0076f4a0(0);
      fVar10 = (float10)atof(pcVar9);
      puVar8[0x20] = (uint)(float)fVar10;
      func_0x0076f4a0(0);
      fVar10 = (float10)atof(pcVar9);
      puVar8[0x21] = (uint)(float)fVar10;
      func_0x0076f4a0(0);
      fVar10 = (float10)atof(pcVar9);
      puVar8[0x22] = (uint)(float)fVar10;
      func_0x0076f4a0(0);
      fVar10 = (float10)atof(pcVar9);
      puVar8[0x23] = (uint)(float)fVar10;
      func_0x0076f4a0(0);
      fVar10 = (float10)atof(pcVar9);
      puVar8[0x24] = (uint)(float)fVar10;
      func_0x0076f4a0(0);
      fVar10 = (float10)atof(pcVar9);
      puVar8[0x25] = (uint)(float)fVar10;
      func_0x0076f4a0(0);
      fVar10 = (float10)atof(pcVar9);
      puVar8[0x26] = (uint)(float)fVar10;
      func_0x0076f4a0(0);
      fVar10 = (float10)atof(pcVar9);
      puVar8[0x27] = (uint)(float)fVar10;
      func_0x0076f4a0(0);
      fVar10 = (float10)atof(pcVar9);
      puVar8[0x28] = (uint)(float)fVar10;
      func_0x0076f4a0(0);
      fVar10 = (float10)atof(pcVar9);
      puVar8[0x29] = (uint)(float)fVar10;
      func_0x0076f4a0(0);
      fVar10 = (float10)atof(pcVar9);
      puVar8[0x2a] = (uint)(float)fVar10;
      func_0x0076f4a0(0);
      fVar10 = (float10)atof(pcVar9);
      puVar8[0x2b] = (uint)(float)fVar10;
      *puVar8 = *puVar8 | 0x800;
      goto LAB_007984e1;
    }
    iVar4 = _stricmp(auStack_170,0x98b9dc);
    if (iVar4 == 0) {
      func_0x0076f4a0(0);
      uVar5 = atoi(pcVar9);
      puVar8[0x1a] = uVar5;
      func_0x0076f4a0(0);
      iVar4 = _stricmp(pcVar9,0x98b9cc);
      if (iVar4 != 0) {
        iVar4 = _stricmp(pcVar9,0x98b9b4);
        if (iVar4 == 0) {
          puVar8[0x1a] = puVar8[0x1a] | 0x10000;
          *puVar8 = *puVar8 | 0x1000;
          goto LAB_007984e1;
        }
        iVar4 = _stricmp(pcVar9,0x98b99c);
        if (iVar4 == 0) {
          puVar8[0x1a] = puVar8[0x1a] | 0x20000;
          *puVar8 = *puVar8 | 0x1000;
          goto LAB_007984e1;
        }
        iVar4 = _stricmp(pcVar9,0x98b97c);
        if (iVar4 == 0) {
          puVar8[0x1a] = puVar8[0x1a] | 0x30000;
        }
      }
      *puVar8 = *puVar8 | 0x1000;
      goto LAB_007984e1;
    }
    uVar12 = *(undefined4 *)(iStack_174 + 8);
    uVar11 = 0x98b928;
  }
  func_0x007647d0(0x9d2f20,uVar11,uVar12,auStack_170);
LAB_007984e1:
  func_0x0076f760();
  return 1;
}


/* ==================================================================== */
/* Address: 0x00798500 | Classified: elementclient::depthfunc@0x798500 */
/* ==================================================================== */

undefined1 __thiscall FUN_00798500(int param_1,int param_2)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int unaff_EBX;
  uint uVar7;
  undefined4 unaff_EBP;
  char cVar9;
  undefined4 *puVar8;
  undefined4 uVar10;
  undefined1 auStack_6c [4];
  char acStack_68 [104];
  
  cVar9 = (char)((uint)unaff_EBP >> 0x18);
  pcVar1 = (char *)(param_2 + 4);
  cVar2 = func_0x0076f4a0(1);
  if (cVar2 == '\0') {
    return 0;
  }
  pcVar3 = pcVar1;
  do {
    cVar2 = *pcVar3;
    pcVar3[(int)(acStack_68 + -(int)pcVar1)] = cVar2;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  iVar4 = _stricmp(pcVar1,0x98be80);
  if ((iVar4 == 0) || (iVar4 = _stricmp(pcVar1,0x98ba7c), iVar4 == 0)) {
    cVar2 = func_0x0076f4a0(0);
    if (cVar2 != '\0') {
      iVar4 = _stricmp(auStack_6c,0x98be80);
      if (iVar4 == 0) {
        uVar7 = 1;
        puVar8 = (undefined4 *)(unaff_EBX + 0x50);
      }
      else {
        uVar7 = 8;
        puVar8 = (undefined4 *)(unaff_EBX + 0x58);
      }
      iVar4 = _stricmp(pcVar1,0x98bcbc);
      if (iVar4 == 0) {
        *puVar8 = 1;
      }
      else {
        iVar4 = _stricmp(pcVar1,0x98bcb0);
        if (iVar4 == 0) {
          *puVar8 = 2;
        }
        else {
          iVar4 = _stricmp(pcVar1,0x98bca4);
          if (iVar4 == 0) {
            *puVar8 = 3;
          }
          else {
            iVar4 = _stricmp(pcVar1,0x98bc94);
            if (iVar4 == 0) {
              *puVar8 = 4;
            }
            else {
              iVar4 = _stricmp(pcVar1,0x98bc88);
              if (iVar4 == 0) {
                *puVar8 = 5;
              }
              else {
                iVar4 = _stricmp(pcVar1,0x98bc78);
                if (iVar4 == 0) {
                  *puVar8 = 6;
                }
                else {
                  iVar4 = _stricmp(pcVar1,0x98bc64);
                  if (iVar4 == 0) {
                    *puVar8 = 7;
                  }
                  else {
                    iVar4 = _stricmp(pcVar1,0x98bc58);
                    if (iVar4 == 0) {
                      *puVar8 = 8;
                    }
                    else {
                      cVar9 = '\0';
                    }
                  }
                }
              }
            }
          }
        }
      }
      if (uVar7 == 8) {
        cVar2 = func_0x0076f4a0(0);
        if (cVar2 == '\0') {
          *(undefined4 *)(unaff_EBX + 0x5c) = 0x80;
        }
        else {
          uVar6 = atoi(pcVar1);
          *(undefined4 *)(unaff_EBX + 0x5c) = uVar6;
        }
      }
      if (cVar9 != '\0') {
        *(uint *)(unaff_EBX + 0x4c) = *(uint *)(unaff_EBX + 0x4c) | uVar7;
        goto LAB_00798b31;
      }
    }
LAB_00798b12:
    uVar6 = *(undefined4 *)(unaff_EBX + 8);
    uVar10 = 0x98bc00;
  }
  else {
    iVar4 = _stricmp(pcVar1,0x98be78);
    if (iVar4 == 0) {
      cVar2 = func_0x0076f4a0(0);
      if (cVar2 != '\0') {
        iVar4 = atoi(pcVar1);
        *(bool *)(unaff_EBX + 0x54) = iVar4 != 0;
        *(uint *)(unaff_EBX + 0x4c) = *(uint *)(unaff_EBX + 0x4c) | 2;
        goto LAB_00798b31;
      }
      goto LAB_00798b12;
    }
    iVar4 = _stricmp(pcVar1,0x98be68);
    if (iVar4 == 0) {
      cVar2 = func_0x0076f4a0(0);
      if (cVar2 != '\0') {
        iVar4 = atoi(pcVar1);
        *(bool *)(unaff_EBX + 0x55) = iVar4 != 0;
        *(uint *)(unaff_EBX + 0x4c) = *(uint *)(unaff_EBX + 0x4c) | 4;
        goto LAB_00798b31;
      }
      goto LAB_00798b12;
    }
    iVar4 = _stricmp(pcVar1,0x98be5c);
    if (iVar4 == 0) {
      cVar2 = func_0x0076f4a0(0);
      if (cVar2 != '\0') {
        iVar4 = _stricmp(pcVar1,0x98be50);
        if (iVar4 == 0) {
          *(undefined4 *)(unaff_EBX + 0x60) = 1;
          *(uint *)(unaff_EBX + 0x4c) = *(uint *)(unaff_EBX + 0x4c) | 0x10;
          goto LAB_00798b31;
        }
        iVar4 = _stricmp(pcVar1,0x98be48);
        if (iVar4 == 0) {
          *(undefined4 *)(unaff_EBX + 0x60) = 2;
          *(uint *)(unaff_EBX + 0x4c) = *(uint *)(unaff_EBX + 0x4c) | 0x10;
          goto LAB_00798b31;
        }
        iVar4 = _stricmp(pcVar1,0x98be3c);
        if (iVar4 == 0) {
          *(undefined4 *)(unaff_EBX + 0x60) = 3;
          *(uint *)(unaff_EBX + 0x4c) = *(uint *)(unaff_EBX + 0x4c) | 0x10;
          goto LAB_00798b31;
        }
      }
      goto LAB_00798b12;
    }
    iVar4 = _stricmp(pcVar1,0x98be34);
    if (iVar4 == 0) {
      iVar4 = 0;
      do {
        cVar2 = func_0x0076f4a0(0);
        if (cVar2 == '\0') goto LAB_00798b12;
        if (iVar4 == 0) {
          puVar8 = (undefined4 *)(unaff_EBX + 100);
        }
        else {
          puVar8 = (undefined4 *)(unaff_EBX + 0x68);
        }
        iVar5 = _stricmp(pcVar1,0x98be28);
        if (iVar5 == 0) {
          *puVar8 = 1;
        }
        else {
          iVar5 = _stricmp(pcVar1,0x98be1c);
          if (iVar5 == 0) {
            *puVar8 = 2;
          }
          else {
            iVar5 = _stricmp(pcVar1,0x98be0c);
            if (iVar5 == 0) {
              *puVar8 = 3;
            }
            else {
              iVar5 = _stricmp(pcVar1,0x98bdf8);
              if (iVar5 == 0) {
                *puVar8 = 4;
              }
              else {
                iVar5 = _stricmp(pcVar1,0x98bde8);
                if (iVar5 == 0) {
                  *puVar8 = 5;
                }
                else {
                  iVar5 = _stricmp(pcVar1,0x98bdd4);
                  if (iVar5 == 0) {
                    *puVar8 = 6;
                  }
                  else {
                    iVar5 = _stricmp(pcVar1,0x98bdc4);
                    if (iVar5 == 0) {
                      *puVar8 = 7;
                    }
                    else {
                      iVar5 = _stricmp(pcVar1,0x98bdb0);
                      if (iVar5 == 0) {
                        *puVar8 = 8;
                      }
                      else {
                        iVar5 = _stricmp(pcVar1,0x98bda0);
                        if (iVar5 == 0) {
                          *puVar8 = 9;
                        }
                        else {
                          iVar5 = _stricmp(pcVar1,0x98bd8c);
                          if (iVar5 == 0) {
                            *puVar8 = 10;
                          }
                          else {
                            iVar5 = _stricmp(pcVar1,0x98bd78);
                            if (iVar5 == 0) {
                              *puVar8 = 0xb;
                            }
                            else {
                              iVar5 = _stricmp(pcVar1,0x98bd64);
                              if (iVar5 == 0) {
                                *puVar8 = 0xc;
                              }
                              else {
                                iVar5 = _stricmp(pcVar1,0x98bd4c);
                                if (iVar5 == 0) {
                                  *puVar8 = 0xd;
                                }
                                else {
                                  unaff_EBP = 0;
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
        iVar4 = iVar4 + 1;
      } while (iVar4 < 2);
      if ((char)((uint)unaff_EBP >> 0x18) != '\0') {
        *(undefined1 *)(unaff_EBX + 0x35) = 1;
        *(uint *)(unaff_EBX + 0x4c) = *(uint *)(unaff_EBX + 0x4c) | 0x20;
        goto LAB_00798b31;
      }
      goto LAB_00798b12;
    }
    iVar4 = _stricmp(pcVar1,0x98ba94);
    if (iVar4 == 0) {
      cVar2 = func_0x00798d10(param_2,(undefined4 *)(param_1 + 0x70));
      if (cVar2 != '\0') {
        *(undefined4 *)(param_1 + 0x70) = 1;
        *(uint *)(unaff_EBX + 0x4c) = *(uint *)(unaff_EBX + 0x4c) | 0x40;
        goto LAB_00798b31;
      }
      goto LAB_00798b12;
    }
    iVar4 = _stricmp(pcVar1,0x98ba88);
    if (iVar4 == 0) {
      cVar2 = func_0x00798d10(param_2,param_1 + 0x88);
      if (cVar2 != '\0') {
        *(undefined4 *)(unaff_EBX + 0x70) = 2;
        *(uint *)(unaff_EBX + 0x4c) = *(uint *)(unaff_EBX + 0x4c) | 0x80;
        goto LAB_00798b31;
      }
      goto LAB_00798b12;
    }
    iVar4 = _stricmp(pcVar1,0x98bd3c);
    if (iVar4 == 0) {
      func_0x0076f4a0(0);
      atof(pcVar1);
      func_0x0076f4a0(0);
      atof(pcVar1);
      func_0x0076f4a0(0);
      atof(pcVar1);
      func_0x0076f4a0(0);
      atof(pcVar1);
      uVar6 = func_0x00799540();
      *(undefined4 *)(param_1 + 0xa0) = uVar6;
      *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x100;
      goto LAB_00798b31;
    }
    iVar4 = _stricmp(pcVar1,0x98bd30);
    if (iVar4 == 0) {
      cVar2 = func_0x0076f4a0(0);
      if (cVar2 != '\0') {
        FUN_007972e0(pcVar1);
        goto LAB_00798b31;
      }
      goto LAB_00798b12;
    }
    iVar4 = _stricmp(pcVar1,0x98bd20);
    if (iVar4 == 0) {
      func_0x0076f4a0(0);
      iVar4 = atoi(pcVar1);
      *(bool *)(param_1 + 0x35) = iVar4 != 0;
      goto LAB_00798b31;
    }
    uVar6 = *(undefined4 *)(param_1 + 8);
    uVar10 = 0x98bcc8;
  }
  func_0x007647d0(0x9d2f20,uVar10,uVar6,auStack_6c);
LAB_00798b31:
  func_0x0076f760();
  return 1;
}


