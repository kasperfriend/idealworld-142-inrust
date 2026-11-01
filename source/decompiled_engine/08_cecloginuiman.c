/* Authentic Ghidra 12.1.4 Decompilation — elementclient.exe (PW 1.4.2 Build 2305) */
/* Module: 08_cecloginuiman.c */

/* ==================================================================== */
/* Address: 0x005a2170 | Classified: CECLoginUIMan::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_005a2170(undefined4 param_1,byte param_2)

{
  FUN_005a2190();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x005a2190 | Classified: ElementClient::proc_5a2190 */
/* ==================================================================== */

void __fastcall FUN_005a2190(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008b723e;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008e3314;
  uStack_4 = 4;
  FUN_00765200();
  uStack_4 = CONCAT31(uStack_4._1_3_,3);
  func_0x00589ef0();
  puVar2 = (undefined4 *)param_1[0x192];
  puVar1 = puVar2 + param_1[0x195];
  if (puVar2 != puVar1) {
    puVar4 = puVar1;
    puVar7 = puVar2;
    if (puVar1 < (undefined4 *)param_1[0x193]) {
      do {
        puVar5 = puVar4 + 1;
        *puVar7 = *puVar4;
        puVar4 = puVar5;
        puVar7 = puVar7 + 1;
      } while (puVar5 < (undefined4 *)param_1[0x193]);
    }
    iVar6 = (int)puVar1 - (int)puVar2 >> 2;
    param_1[0x193] = param_1[0x193] + iVar6 * -4;
    param_1[0x195] = param_1[0x195] - iVar6;
  }
  if (param_1[0x192] != 0) {
    func_0x00763260(param_1[0x192]);
  }
  piVar8 = (int *)param_1[0x18e];
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  piVar3 = piVar8 + param_1[0x191] * 0x23;
  if (piVar8 != piVar3) {
    piVar9 = piVar3;
    piVar10 = piVar8;
    if (piVar3 < (int *)param_1[399]) {
      do {
        FUN_005a23e0(piVar9);
        piVar9 = piVar9 + 0x23;
        piVar10 = piVar10 + 0x23;
      } while (piVar9 < (int *)param_1[399]);
    }
    if (piVar10 < (int *)param_1[399]) {
      do {
        (**(code **)(*piVar10 + 8))(0);
        piVar10 = piVar10 + 0x23;
      } while (piVar10 < (int *)param_1[399]);
    }
    iVar6 = ((int)piVar3 - (int)piVar8) / 0x8c;
    param_1[399] = param_1[399] + iVar6 * -0x8c;
    param_1[0x191] = param_1[0x191] - iVar6;
  }
  if (param_1[0x18e] != 0) {
    func_0x00763260(param_1[0x18e]);
  }
  param_1[0x188] = &UNK_008d6c34;
  free(param_1[0x189]);
  param_1[0x184] = &UNK_008d6c34;
  free(param_1[0x185]);
  piVar3 = (int *)param_1[0x17a];
  piVar8 = (int *)param_1[0x179];
  uStack_4._0_1_ = 9;
  for (; piVar8 != piVar3; piVar8 = piVar8 + 0xe) {
    (**(code **)(*piVar8 + 8))(0);
  }
  uStack_4 = CONCAT31(uStack_4._1_3_,8);
  func_0x0043a550();
  func_0x005ca820();
  param_1[0x174] = &UNK_008d6c34;
  free(param_1[0x175]);
  param_1[0x170] = &UNK_008d6c34;
  free(param_1[0x171]);
  param_1[0x16b] = &UNK_008d6c3c;
  uStack_4 = 0xffffffff;
  FUN_0072e4e0();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x005a23e0 | Classified: ElementClient::proc_5a23e0 */
/* ==================================================================== */

int __thiscall FUN_005a23e0(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_retaddr;
  
  if ((param_2 != 0) && (param_2 != param_1)) {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
    *(undefined1 *)(param_1 + 8) = *(undefined1 *)(param_2 + 8);
    *(undefined1 *)(param_1 + 9) = *(undefined1 *)(param_2 + 9);
    *(undefined1 *)(param_1 + 10) = *(undefined1 *)(param_2 + 10);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
    iVar6 = *(int *)(param_2 + 0x18);
    uVar5 = *(int *)(param_2 + 0x1c) - iVar6;
    if (*(uint *)(param_1 + 0x20) < uVar5) {
      uVar1 = uVar5 - 1;
      *(undefined4 *)(param_1 + 0x20) = 2;
      while (uVar1 = uVar1 >> 1, uVar1 != 0) {
        *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) << 1;
      }
      iVar2 = *(int *)(param_1 + 0x18);
      iVar3 = *(int *)(param_1 + 0x1c);
      iVar4 = realloc(iVar2,*(undefined4 *)(param_1 + 0x20));
      *(int *)(param_1 + 0x18) = iVar4;
      *(int *)(param_1 + 0x1c) = iVar4 + (iVar3 - iVar2);
    }
    memmove(*(undefined4 *)(param_1 + 0x18),iVar6,uVar5);
    *(uint *)(param_1 + 0x1c) = uVar5 + *(int *)(param_1 + 0x18);
    iVar6 = *(int *)(param_2 + 0x2c) - *(int *)(param_2 + 0x28);
    func_0x004327b0(iVar6);
    memmove(*(undefined4 *)(param_1 + 0x28),unaff_retaddr,iVar6);
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x28) + iVar6;
    func_0x0043ac70(param_2 + 0x38);
    *(undefined1 *)(param_1 + 0x44) = *(undefined1 *)(param_2 + 0x44);
    *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_2 + 0x48);
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_2 + 0x4c);
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_2 + 0x50);
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_2 + 0x54);
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_2 + 0x58);
    *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_2 + 0x5c);
    *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_2 + 0x60);
    iVar6 = *(int *)(param_2 + 0x68);
    uVar5 = *(int *)(param_2 + 0x6c) - iVar6;
    if (*(uint *)(param_1 + 0x70) < uVar5) {
      uVar1 = uVar5 - 1;
      *(undefined4 *)(param_1 + 0x70) = 2;
      while (uVar1 = uVar1 >> 1, uVar1 != 0) {
        *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) << 1;
      }
      iVar2 = *(int *)(param_1 + 0x68);
      iVar3 = *(int *)(param_1 + 0x6c);
      iVar4 = realloc(iVar2,*(undefined4 *)(param_1 + 0x70));
      *(int *)(param_1 + 0x68) = iVar4;
      *(int *)(param_1 + 0x6c) = iVar4 + (iVar3 - iVar2);
    }
    memmove(*(undefined4 *)(param_1 + 0x68),iVar6,uVar5);
    *(uint *)(param_1 + 0x6c) = *(int *)(param_1 + 0x68) + uVar5;
    iVar6 = *(int *)(param_2 + 0x78);
    uVar5 = *(int *)(param_2 + 0x7c) - iVar6;
    if (*(uint *)(param_1 + 0x80) < uVar5) {
      uVar1 = uVar5 - 1;
      *(undefined4 *)(param_1 + 0x80) = 2;
      while (uVar1 = uVar1 >> 1, uVar1 != 0) {
        *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) << 1;
      }
      iVar2 = *(int *)(param_1 + 0x78);
      iVar3 = *(int *)(param_1 + 0x7c);
      iVar4 = realloc(iVar2,*(undefined4 *)(param_1 + 0x80));
      *(int *)(param_1 + 0x78) = iVar4;
      *(int *)(param_1 + 0x7c) = iVar4 + (iVar3 - iVar2);
    }
    memmove(*(undefined4 *)(param_1 + 0x78),iVar6,uVar5);
    *(uint *)(param_1 + 0x7c) = *(int *)(param_1 + 0x78) + uVar5;
    *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(param_2 + 0x84);
    *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_2 + 0x88);
    return param_1;
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x005a2600 | Classified: CECLoginUIMan::vfunc_slot_1 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __fastcall FUN_005a2600(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  float unaff_EBX;
  float *pfVar4;
  int iVar5;
  int *unaff_FS_OFFSET;
  float10 fVar6;
  undefined1 ***pppuStack_1c0;
  undefined1 ***pppuStack_1bc;
  undefined1 *puStack_1b8;
  undefined1 **ppuStack_1b4;
  undefined1 **ppuStack_1b0;
  undefined1 *puStack_1ac;
  undefined1 **ppuStack_1a8;
  undefined1 **ppuStack_1a4;
  int iStack_1a0;
  undefined1 **ppuStack_19c;
  undefined1 **ppuStack_198;
  undefined1 *puStack_194;
  undefined1 *puStack_190;
  undefined1 *puStack_18c;
  float fStack_188;
  undefined1 *puStack_184;
  undefined1 *puStack_180;
  int iStack_17c;
  undefined1 *puStack_178;
  float fStack_164;
  undefined1 auStack_160 [24];
  undefined1 auStack_148 [56];
  undefined1 auStack_110 [196];
  undefined4 uStack_4c;
  int iStack_38;
  undefined4 uStack_30;
  undefined4 uStack_1c;
  undefined1 **ppuStack_18;
  undefined4 uStack_14;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008b7277;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  puStack_178 = (undefined1 *)0x5a262a;
  func_0x0076c660();
  iVar5 = 0;
  uStack_4 = 0;
  puStack_178 = (undefined1 *)0x5a2638;
  puStack_178 = (undefined1 *)func_0x0076eb20();
  puStack_180 = auStack_110;
  iStack_17c = 0x971130;
  puStack_184 = (undefined1 *)0x5a264b;
  sprintf();
  puStack_178 = auStack_110;
  iStack_17c = 0x5a265c;
  func_0x0076c730();
  pfVar4 = (float *)(param_1 + 0x110);
  do {
    puStack_184 = auStack_160;
    puStack_180 = (undefined1 *)0x971128;
    fStack_188 = 8.278982e-39;
    iStack_17c = iVar5;
    sprintf();
    puStack_180 = auStack_160;
    iStack_17c = 0;
    puStack_184 = (undefined1 *)0x971120;
    fStack_188 = 8.279016e-39;
    func_0x0076d000();
    puStack_190 = &stack0xfffffe94;
    puStack_18c = (undefined1 *)0x971118;
    puStack_194 = (undefined1 *)0x5a2698;
    fStack_188 = (float)iVar5;
    sprintf();
    puStack_18c = &stack0xfffffe94;
    fStack_188 = 0.0;
    puStack_190 = (undefined1 *)0x971120;
    puStack_194 = (undefined1 *)0x5a26b0;
    fVar6 = (float10)func_0x0076d000();
    puStack_180 = (undefined1 *)(float)fVar6;
    ppuStack_19c = &puStack_178;
    ppuStack_198 = (undefined1 **)0x971110;
    iStack_1a0 = 0x5a26c1;
    puStack_194 = (undefined1 *)iVar5;
    sprintf();
    ppuStack_198 = &puStack_178;
    puStack_194 = (undefined1 *)0x0;
    ppuStack_19c = (undefined1 **)0x971120;
    iStack_1a0 = 0x5a26d9;
    fVar6 = (float10)func_0x0076d000();
    *pfVar4 = (float)fVar6;
    ppuStack_1a8 = &puStack_184;
    ppuStack_1a4 = (undefined1 **)0x971108;
    pfVar4[-2] = fStack_188;
    pfVar4[-1] = (float)puStack_18c;
    puStack_1ac = (undefined1 *)0x5a26f7;
    iStack_1a0 = iVar5;
    sprintf();
    ppuStack_1a4 = &puStack_184;
    iStack_1a0 = 0;
    ppuStack_1a8 = (undefined1 **)0x971120;
    puStack_1ac = (undefined1 *)0x5a270f;
    fVar6 = (float10)func_0x0076d000();
    puStack_194 = (undefined1 *)(float)fVar6;
    ppuStack_1b4 = &puStack_190;
    ppuStack_1b0 = (undefined1 **)0x971100;
    puStack_1b8 = (undefined1 *)0x5a2720;
    puStack_1ac = (undefined1 *)iVar5;
    sprintf();
    ppuStack_1b0 = &puStack_190;
    puStack_1ac = (undefined1 *)0x0;
    ppuStack_1b4 = (undefined1 **)0x971120;
    puStack_1b8 = (undefined1 *)0x5a2738;
    fVar6 = (float10)func_0x0076d000();
    ppuStack_1a4 = (undefined1 **)(float)fVar6;
    pppuStack_1c0 = &ppuStack_19c;
    pppuStack_1bc = (undefined1 ***)0x9710f8;
    puStack_1b8 = (undefined1 *)iVar5;
    sprintf();
    pppuStack_1bc = &ppuStack_19c;
    puStack_1b8 = (undefined1 *)0x0;
    pppuStack_1c0 = (undefined1 ***)0x971120;
    fVar6 = (float10)func_0x0076d000();
    pfVar4[0x4e] = (float)fVar6;
    pfVar4[0x4c] = (float)puStack_1ac;
    pfVar4[0x4d] = (float)ppuStack_1b0;
    sprintf(&ppuStack_1a8,0x9710f0,iVar5);
    fVar6 = (float10)func_0x0076d000(0x971120,&ppuStack_1a8,0);
    puStack_1b8 = (undefined1 *)(float)fVar6;
    sprintf(&ppuStack_1b4,0x9710e8,iVar5);
    func_0x0076d000(0x971120,&ppuStack_1b4,0);
    sprintf(&pppuStack_1c0,0x9710e0,iVar5);
    fVar6 = (float10)func_0x0076d000(0x971120,&pppuStack_1c0,0);
    pfVar4[0x9c] = (float)fVar6;
    pfVar4[0x9a] = fStack_164;
    pfVar4[0x9b] = unaff_EBX;
    iVar5 = iVar5 + 1;
    pfVar4 = pfVar4 + 3;
  } while (iVar5 < 0x1a);
  iVar5 = 0;
  pfVar4 = (float *)(param_1 + 0x4b8);
  do {
    puStack_184 = auStack_160;
    puStack_180 = (undefined1 *)0x971128;
    fStack_188 = 8.279608e-39;
    iStack_17c = iVar5;
    sprintf();
    puStack_180 = auStack_160;
    iStack_17c = 0;
    puStack_184 = (undefined1 *)0x9710d8;
    fStack_188 = 8.279642e-39;
    func_0x0076d000();
    puStack_190 = &stack0xfffffe94;
    puStack_18c = (undefined1 *)0x971118;
    puStack_194 = (undefined1 *)0x5a2857;
    fStack_188 = (float)iVar5;
    sprintf();
    puStack_18c = &stack0xfffffe94;
    fStack_188 = 0.0;
    puStack_190 = (undefined1 *)0x9710d8;
    puStack_194 = (undefined1 *)0x5a286f;
    fVar6 = (float10)func_0x0076d000();
    puStack_180 = (undefined1 *)(float)fVar6;
    ppuStack_19c = &puStack_178;
    ppuStack_198 = (undefined1 **)0x971110;
    iStack_1a0 = 0x5a2880;
    puStack_194 = (undefined1 *)iVar5;
    sprintf();
    ppuStack_198 = &puStack_178;
    puStack_194 = (undefined1 *)0x0;
    ppuStack_19c = (undefined1 **)0x9710d8;
    iStack_1a0 = 0x5a2898;
    fVar6 = (float10)func_0x0076d000();
    *pfVar4 = (float)fVar6;
    pfVar4[-2] = fStack_164;
    pfVar4[-1] = unaff_EBX;
    iVar5 = iVar5 + 1;
    pfVar4 = pfVar4 + 3;
  } while (iVar5 < 9);
  iVar5 = 0;
  pfVar4 = (float *)(param_1 + 0x524);
  do {
    puStack_184 = auStack_160;
    puStack_180 = (undefined1 *)0x971128;
    fStack_188 = 8.279828e-39;
    iStack_17c = iVar5;
    sprintf();
    puStack_180 = auStack_160;
    iStack_17c = 0;
    puStack_184 = (undefined1 *)0x9710d0;
    fStack_188 = 8.279862e-39;
    func_0x0076d000();
    puStack_190 = &stack0xfffffe94;
    puStack_18c = (undefined1 *)0x971118;
    puStack_194 = (undefined1 *)0x5a28f4;
    fStack_188 = (float)iVar5;
    sprintf();
    puStack_18c = &stack0xfffffe94;
    fStack_188 = 0.0;
    puStack_190 = (undefined1 *)0x9710d0;
    puStack_194 = (undefined1 *)0x5a290c;
    fVar6 = (float10)func_0x0076d000();
    puStack_180 = (undefined1 *)(float)fVar6;
    ppuStack_19c = &puStack_178;
    ppuStack_198 = (undefined1 **)0x971110;
    iStack_1a0 = 0x5a291d;
    puStack_194 = (undefined1 *)iVar5;
    sprintf();
    ppuStack_198 = &puStack_178;
    puStack_194 = (undefined1 *)0x0;
    ppuStack_19c = (undefined1 **)0x9710d0;
    iStack_1a0 = 0x5a2935;
    fVar6 = (float10)func_0x0076d000();
    *pfVar4 = (float)fVar6;
    pfVar4[-2] = fStack_164;
    pfVar4[-1] = unaff_EBX;
    iVar5 = iVar5 + 1;
    pfVar4 = pfVar4 + 3;
  } while (iVar5 < 8);
  iStack_17c = 0x5a295c;
  func_0x0076c930();
  iStack_17c = 0;
  puStack_180 = (undefined1 *)0x5a2966;
  func_0x005a83d0();
  puStack_180 = (undefined1 *)0x8c;
  puStack_184 = (undefined1 *)0x5a2970;
  iVar5 = func_0x00763250();
  iStack_c._0_1_ = 1;
  if (iVar5 == 0) {
    uVar3 = 0;
  }
  else {
    puStack_180 = (undefined1 *)0x5a298a;
    uVar3 = func_0x0078bd00();
  }
  *(undefined4 *)(param_1 + 0xf4) = uVar3;
  puStack_180 = (undefined1 *)0x0;
  puStack_184 = (undefined1 *)0x9710c4;
  fStack_188 = *(float *)(_DAT_009b3eec + 8);
  iStack_c = (uint)iStack_c._1_3_ << 8;
  puStack_18c = (undefined1 *)0x5a29b3;
  cVar1 = func_0x0078c020();
  if (cVar1 == '\0') {
    puStack_18c = (undefined1 *)0x5a29c2;
    func_0x0078c040();
    if (*(undefined4 **)(param_1 + 0xf4) != (undefined4 *)0x0) {
      puStack_18c = (undefined1 *)0x1;
      puStack_190 = (undefined1 *)0x5a29d2;
      (**(code **)**(undefined4 **)(param_1 + 0xf4))();
    }
    *(undefined4 *)(param_1 + 0xf4) = 0;
  }
  puStack_18c = (undefined1 *)0x8c;
  puStack_190 = (undefined1 *)0x5a29e2;
  puStack_178 = (undefined1 *)func_0x00763250();
  ppuStack_18._0_1_ = 2;
  if (puStack_178 == (undefined1 *)0x0) {
    uVar3 = 0;
  }
  else {
    puStack_18c = (undefined1 *)0x5a29fc;
    uVar3 = func_0x0078bd00();
  }
  *(undefined4 *)(param_1 + 0xf8) = uVar3;
  puStack_18c = (undefined1 *)0x0;
  puStack_190 = (undefined1 *)0x9710bc;
  puStack_194 = *(undefined1 **)(_DAT_009b3eec + 8);
  ppuStack_18 = (undefined1 **)((uint)ppuStack_18._1_3_ << 8);
  ppuStack_198 = (undefined1 **)0x5a2a25;
  cVar1 = func_0x0078c020();
  if (cVar1 == '\0') {
    ppuStack_198 = (undefined1 **)0x5a2a34;
    func_0x0078c040();
    if (*(undefined4 **)(param_1 + 0xf8) != (undefined4 *)0x0) {
      ppuStack_198 = (undefined1 **)0x1;
      ppuStack_19c = (undefined1 **)0x5a2a44;
      (**(code **)**(undefined4 **)(param_1 + 0xf8))();
    }
    *(undefined4 *)(param_1 + 0xf8) = 0;
  }
  ppuStack_198 = (undefined1 **)uStack_14;
  ppuStack_19c = ppuStack_18;
  iStack_1a0 = uStack_1c;
  ppuStack_1a4 = (undefined1 **)0x5a2a69;
  cVar1 = FUN_0072e6c0();
  if (cVar1 == '\0') {
    ppuStack_1a4 = (undefined1 **)0x97108c;
    ppuStack_1a8 = (undefined1 **)0xed;
    puStack_1ac = (undefined1 *)0x5a2a7c;
    uVar2 = func_0x007396e0();
    uStack_30 = 0xffffffff;
    ppuStack_1a4 = (undefined1 **)0x5a2a95;
    func_0x0076c6b0();
  }
  else {
    ppuStack_1a4 = (undefined1 **)0x96df38;
    ppuStack_1a8 = (undefined1 **)0x5a2aa8;
    FUN_0072fb20();
    puStack_194 = (undefined1 *)&ppuStack_1a8;
    puStack_1ac = (undefined1 *)&ppuStack_1a8;
    ppuStack_1b0 = (undefined1 **)0x5a2ab9;
    func_0x005a9580();
    ppuStack_1b0 = (undefined1 **)0x5a2ac0;
    func_0x0057a020();
    ppuStack_1b0 = (undefined1 **)0x5a2ac5;
    ppuStack_1b0 = (undefined1 **)func_0x0076eb20();
    puStack_1b8 = auStack_148;
    ppuStack_1b4 = (undefined1 **)0x971070;
    pppuStack_1bc = (undefined1 ***)0x5a2ad2;
    sprintf();
    ppuStack_1b0 = (undefined1 **)auStack_148;
    ppuStack_1b4 = (undefined1 **)0x5a2ae3;
    cVar1 = func_0x0076c730();
    if (cVar1 != '\0') {
      ppuStack_1b4 = (undefined1 **)0x0;
      puStack_1b8 = (undefined1 *)0x971068;
      pppuStack_1bc = (undefined1 ***)0x97105c;
      pppuStack_1c0 = (undefined1 ***)0x5a2afb;
      iVar5 = func_0x0076cf50();
      if (iVar5 == 0) {
        pppuStack_1c0 = (undefined1 ***)0x0;
        FUN_0072fb20(0x96e344,0x971050);
        FUN_00737400();
        FUN_00741ef0();
      }
      pppuStack_1c0 = (undefined1 ***)0x5a2b28;
      func_0x0076c930();
    }
    ppuStack_1b4 = *(undefined1 ***)(*(int *)(_DAT_009b3eec + 0x18) + 0x74);
    puStack_1b8 = (undefined1 *)0x97103c;
    pppuStack_1bc = (undefined1 ***)0x969f2c;
    pppuStack_1c0 = (undefined1 ***)0x5a2b45;
    FUN_0072fb20();
    pppuStack_1c0 = (undefined1 ***)0x5a2b4c;
    FUN_00737400();
    pppuStack_1c0 = (undefined1 ***)0x5a2b53;
    FUN_00741200();
    uStack_4c = 0xffffffff;
    pppuStack_1c0 = (undefined1 ***)0x5a2b67;
    func_0x0076c6b0();
    uVar2 = 1;
  }
  *unaff_FS_OFFSET = iStack_38;
  return uVar2;
}


/* ==================================================================== */
/* Address: 0x005a2b90 | Classified: CECLoginUIMan::vfunc_slot_2 */
/* ==================================================================== */

undefined1 __fastcall FUN_005a2b90(int param_1)

{
  uint uVar1;
  uint *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined1 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int *piVar10;
  undefined4 *puVar11;
  int *piVar12;
  int *piVar13;
  undefined4 *puVar14;
  int iVar15;
  int iVar16;
  int *piVar17;
  undefined4 *unaff_FS_OFFSET;
  int *piStack_1c0;
  undefined1 *puStack_1bc;
  undefined1 *puStack_1b8;
  int *piStack_1b4;
  undefined1 *puStack_1b0;
  undefined1 *puStack_1ac;
  int *piStack_1a8;
  int *piStack_1a4;
  int *piStack_1a0;
  int *piStack_19c;
  undefined4 *puStack_198;
  int *piStack_194;
  int *piStack_190;
  undefined1 auStack_178 [2];
  undefined1 uStack_176;
  undefined1 uStack_175;
  int *piStack_174;
  undefined1 uStack_16d;
  int iStack_16c;
  int *piStack_168;
  int *piStack_164;
  undefined1 auStack_160 [40];
  int *piStack_138;
  int aiStack_110 [64];
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008b729b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iStack_16c = param_1;
  if (*(int *)(param_1 + 0xf4) != 0) {
    piStack_190 = (int *)0x5a2bc6;
    func_0x0078c040();
    if (*(undefined4 **)(param_1 + 0xf4) != (undefined4 *)0x0) {
      piStack_190 = (int *)0x1;
      piStack_194 = (int *)0x5a2bd6;
      (**(code **)**(undefined4 **)(param_1 + 0xf4))();
    }
    *(undefined4 *)(param_1 + 0xf4) = 0;
  }
  if (*(int *)(param_1 + 0xf8) != 0) {
    piStack_190 = (int *)0x5a2beb;
    func_0x0078c040();
    if (*(undefined4 **)(param_1 + 0xf8) != (undefined4 *)0x0) {
      piStack_190 = (int *)0x1;
      piStack_194 = (int *)0x5a2bfb;
      (**(code **)**(undefined4 **)(param_1 + 0xf8))();
    }
    *(undefined4 *)(param_1 + 0xf8) = 0;
  }
  iVar16 = 0;
  if (0 < *(int *)(param_1 + 0x654)) {
    do {
      piVar12 = *(int **)(*(int *)(param_1 + 0x648) + iVar16 * 4);
      if (piVar12 != (int *)0x0) {
        piStack_190 = (int *)0x5a2c1f;
        (**(code **)(*piVar12 + 0x40))();
        puVar14 = *(undefined4 **)(*(int *)(param_1 + 0x648) + iVar16 * 4);
        if (puVar14 != (undefined4 *)0x0) {
          piStack_190 = (int *)0x1;
          piStack_194 = (int *)0x5a2c32;
          (**(code **)*puVar14)();
        }
        *(undefined4 *)(*(int *)(param_1 + 0x648) + iVar16 * 4) = 0;
      }
      iVar16 = iVar16 + 1;
    } while (iVar16 < *(int *)(param_1 + 0x654));
  }
  puVar4 = *(undefined4 **)(param_1 + 0x648);
  puVar14 = puVar4 + *(int *)(param_1 + 0x654);
  if (puVar4 != puVar14) {
    puVar7 = puVar14;
    puVar11 = puVar4;
    if (puVar14 < *(undefined4 **)(param_1 + 0x64c)) {
      do {
        puVar8 = puVar7 + 1;
        *puVar11 = *puVar7;
        puVar7 = puVar8;
        puVar11 = puVar11 + 1;
      } while (puVar8 < *(undefined4 **)(param_1 + 0x64c));
    }
    iVar16 = (int)puVar14 - (int)puVar4 >> 2;
    *(int *)(param_1 + 0x64c) = *(int *)(param_1 + 0x64c) + iVar16 * -4;
    *(int *)(param_1 + 0x654) = *(int *)(param_1 + 0x654) - iVar16;
  }
  piVar10 = *(int **)(param_1 + 0x638);
  piVar12 = piVar10 + *(int *)(param_1 + 0x644) * 0x23;
  piStack_164 = piVar12;
  piStack_138 = piVar10;
  if (piVar10 != piVar12) {
    piStack_168 = piVar10;
    if (piVar12 < *(int **)(param_1 + 0x63c)) {
      piVar13 = piVar10 + 0xf;
      piVar17 = piVar12 + 6;
      do {
        if ((piVar17 != (int *)0x18) && (piVar17 + -6 != piStack_168)) {
          piVar13[-0xe] = piVar17[-5];
          *(char *)(piVar13 + -0xd) = (char)piVar17[-4];
          *(undefined1 *)((int)piVar13 + -0x33) = *(undefined1 *)((int)piVar17 + -0xf);
          *(undefined1 *)((int)piVar13 + -0x32) = *(undefined1 *)((int)piVar17 + -0xe);
          piVar13[-0xc] = piVar17[-3];
          piVar13[-0xb] = piVar17[-2];
          iVar16 = *piVar17;
          piVar12 = (int *)(piVar17[1] - iVar16);
          if ((int *)piVar13[-7] < piVar12) {
            uVar1 = (int)piVar12 - 1;
            piVar13[-7] = 2;
            while (uVar1 = uVar1 >> 1, uVar1 != 0) {
              piVar13[-7] = piVar13[-7] << 1;
            }
            piStack_194 = (int *)piVar13[-9];
            piStack_174 = (int *)(piVar13[-8] - (int)piStack_194);
            piStack_190 = (int *)piVar13[-7];
            puStack_198 = (undefined4 *)0x5a2d62;
            iVar9 = realloc();
            piVar13[-9] = iVar9;
            piVar13[-8] = (int)piStack_174 + iVar9;
          }
          puStack_198 = (undefined4 *)piVar13[-9];
          piStack_19c = (int *)0x5a2d81;
          piStack_194 = (int *)iVar16;
          piStack_190 = piVar12;
          memmove();
          piVar13[-8] = (int)piVar12 + piVar13[-9];
          piStack_174 = (int *)piVar17[4];
          piVar12 = (int *)(piVar17[5] - (int)piStack_174);
          if ((int *)piVar13[-3] < piVar12) {
            uVar1 = (int)piVar12 - 1;
            piVar13[-3] = 2;
            while (uVar1 = uVar1 >> 1, uVar1 != 0) {
              piVar13[-3] = piVar13[-3] << 1;
            }
            piStack_194 = (int *)piVar13[-5];
            iVar9 = piVar13[-4] - (int)piStack_194;
            piStack_190 = (int *)piVar13[-3];
            puStack_198 = (undefined4 *)0x5a2dd0;
            iVar16 = realloc();
            piVar13[-5] = iVar16;
            piVar13[-4] = iVar16 + iVar9;
          }
          puStack_198 = (undefined4 *)piVar13[-5];
          piStack_19c = (int *)0x5a2def;
          piStack_194 = piStack_174;
          piStack_190 = piVar12;
          memmove();
          piVar13[-4] = (int)piVar12 + piVar13[-5];
          puVar2 = (uint *)(piVar13 + -1);
          if (piVar17 + 8 != piVar13 + -1) {
            piVar12 = (int *)piVar17[8];
            uVar1 = (piVar17[9] - (int)piVar12) / 0x38;
            if ((uint)((int)(piVar13[1] - *puVar2) / 0x38) < uVar1) {
              piStack_190 = (int *)piVar17[9];
              piStack_19c = (int *)0x5a2e58;
              puStack_198 = (undefined4 *)uVar1;
              piStack_194 = piVar12;
              func_0x0043c350();
              piStack_1a4 = (int *)*puVar2;
              piStack_1a0 = (int *)*piVar13;
              piStack_19c = (int *)&stack0xfffffe7f;
              piStack_1a8 = (int *)0x5a2e6c;
              func_0x005aa8a0();
              piStack_19c = (int *)((int)(piVar13[1] - *puVar2) / 0x38);
              piStack_1a0 = (int *)*puVar2;
              piStack_1a4 = (int *)0x5a2e95;
              func_0x0043a5e0();
              *puVar2 = uVar1;
              piVar13[1] = uVar1 * 0x39;
            }
            else {
              uVar5 = (int)(*piVar13 - *puVar2) / 0x38;
              piStack_1a0 = piVar12;
              if (uVar5 < uVar1) {
                piStack_190 = (int *)0x0;
                uStack_176 = uStack_175;
                piStack_194 = (int *)&uStack_176;
                puStack_198 = (undefined4 *)*puVar2;
                piStack_19c = piVar12 + uVar5 * 0xe;
                piStack_1a4 = (int *)0x5a2f4a;
                func_0x005aa780();
                piStack_1a8 = (int *)*piVar13;
                puStack_1ac = (undefined1 *)piVar17[9];
                piStack_1a4 = (int *)&uStack_16d;
                puStack_1b0 = (undefined1 *)
                              (piVar17[8] + ((int)((int)piStack_1a8 - *puVar2) / 0x38) * 0x38);
                piStack_1b4 = (int *)0x5a2f84;
                func_0x0043bf40();
              }
              else {
                piStack_194 = (int *)&uStack_176;
                piStack_190 = (int *)0x0;
                puStack_198 = (undefined4 *)*puVar2;
                uStack_176 = uStack_175;
                piStack_19c = (int *)piVar17[9];
                piStack_1a4 = (int *)0x5a2eee;
                piStack_190 = (int *)func_0x005aa780();
                piVar12 = (int *)*piVar13;
                while (piStack_174 = piStack_190, piStack_190 != piVar12) {
                  piStack_194 = (int *)0x5a2f0d;
                  func_0x005aa8d0();
                  piStack_190 = piStack_174 + 0xe;
                }
              }
            }
            *piVar13 = *puVar2 + uVar1 * 0x38;
            param_1 = iStack_16c;
          }
          *(char *)(piVar13 + 2) = (char)piVar17[0xb];
          piVar13[3] = piVar17[0xc];
          piVar13[4] = piVar17[0xd];
          piVar13[5] = piVar17[0xe];
          piVar13[6] = piVar17[0xf];
          piVar13[7] = piVar17[0x10];
          piVar13[8] = piVar17[0x11];
          piVar13[9] = piVar17[0x12];
          iVar16 = piVar17[0x14];
          piVar12 = (int *)(piVar17[0x15] - iVar16);
          if ((int *)piVar13[0xd] < piVar12) {
            uVar1 = (int)piVar12 - 1;
            piVar13[0xd] = 2;
            while (uVar1 = uVar1 >> 1, uVar1 != 0) {
              piVar13[0xd] = piVar13[0xd] << 1;
            }
            piStack_190 = (int *)piVar13[0xd];
            piStack_194 = (int *)piVar13[0xb];
            iVar15 = piVar13[0xc] - (int)piStack_194;
            puStack_198 = (undefined4 *)0x5a300c;
            iVar9 = realloc();
            piVar13[0xb] = iVar9;
            piVar13[0xc] = iVar9 + iVar15;
            param_1 = iStack_16c;
          }
          puStack_198 = (undefined4 *)piVar13[0xb];
          piStack_19c = (int *)0x5a302b;
          piStack_194 = (int *)iVar16;
          piStack_190 = piVar12;
          memmove();
          piVar13[0xc] = (int)piVar12 + piVar13[0xb];
          iVar16 = piVar17[0x18];
          piVar12 = (int *)(piVar17[0x19] - iVar16);
          if ((int *)piVar13[0x11] < piVar12) {
            uVar1 = (int)piVar12 - 1;
            piVar13[0x11] = 2;
            while (uVar1 = uVar1 >> 1, uVar1 != 0) {
              piVar13[0x11] = piVar13[0x11] << 1;
            }
            piStack_190 = (int *)piVar13[0x11];
            piStack_194 = (int *)piVar13[0xf];
            iVar15 = piVar13[0x10] - (int)piStack_194;
            puStack_198 = (undefined4 *)0x5a3076;
            iVar9 = realloc();
            piVar13[0xf] = iVar9;
            piVar13[0x10] = iVar9 + iVar15;
            param_1 = iStack_16c;
          }
          puStack_198 = (undefined4 *)piVar13[0xf];
          piStack_19c = (int *)0x5a3095;
          piStack_194 = (int *)iVar16;
          piStack_190 = piVar12;
          memmove();
          piVar13[0x10] = (int)piVar12 + piVar13[0xf];
          piVar13[0x12] = piVar17[0x1b];
          piVar13[0x13] = piVar17[0x1c];
          piVar12 = piStack_164;
          piVar10 = piStack_138;
        }
        piStack_168 = piStack_168 + 0x23;
        piVar13 = piVar13 + 0x23;
        piVar3 = piVar17 + 0x1d;
        piVar17 = piVar17 + 0x23;
      } while (piVar3 < *(int **)(param_1 + 0x63c));
    }
    piVar13 = piStack_168;
    if (piStack_168 < *(int **)(param_1 + 0x63c)) {
      do {
        piStack_190 = (int *)0x0;
        piStack_194 = (int *)0x5a30ee;
        (**(code **)(*piVar13 + 8))();
        piVar13 = piVar13 + 0x23;
        piVar12 = piStack_164;
        piVar10 = piStack_138;
      } while (piVar13 < *(int **)(param_1 + 0x63c));
    }
    iVar16 = ((int)piVar12 - (int)piVar10) / 0x8c;
    *(int *)(param_1 + 0x63c) = *(int *)(param_1 + 0x63c) + iVar16 * -0x8c;
    *(int *)(param_1 + 0x644) = *(int *)(param_1 + 0x644) - iVar16;
  }
  piVar12 = (int *)(param_1 + 0x660);
  iVar16 = 8;
  do {
    iVar9 = 2;
    do {
      if ((int *)*piVar12 != (int *)0x0) {
        piStack_190 = (int *)0x5a3165;
        (**(code **)(*(int *)*piVar12 + 0x40))();
        if ((undefined4 *)*piVar12 != (undefined4 *)0x0) {
          piStack_190 = (int *)0x1;
          piStack_194 = (int *)0x5a3171;
          (*(code *)**(undefined4 **)*piVar12)();
        }
        *piVar12 = 0;
      }
      piVar12 = piVar12 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    iVar16 = iVar16 + -1;
  } while (iVar16 != 0);
  piStack_190 = (int *)0x5a3189;
  func_0x0076c660();
  piVar12 = (int *)0x0;
  uStack_4 = 0;
  puVar14 = (undefined4 *)(param_1 + 0x10c);
  do {
    puStack_198 = (undefined4 *)auStack_160;
    piStack_194 = (int *)0x971128;
    piStack_19c = (int *)0x5a31ab;
    piStack_190 = piVar12;
    sprintf();
    piStack_190 = (int *)puVar14[-1];
    piStack_194 = (int *)auStack_160;
    puStack_198 = (undefined4 *)0x971120;
    piStack_19c = (int *)0x5a31c5;
    func_0x0076d240();
    piStack_1a4 = &iStack_16c;
    piStack_1a0 = (int *)0x971118;
    piStack_1a8 = (int *)0x5a31d2;
    piStack_19c = piVar12;
    sprintf();
    piStack_19c = (int *)*puVar14;
    piStack_1a0 = &iStack_16c;
    piStack_1a4 = (int *)0x971120;
    piStack_1a8 = (int *)0x5a31eb;
    func_0x0076d240();
    puStack_1b0 = auStack_178;
    puStack_1ac = (undefined1 *)0x971110;
    piStack_1b4 = (int *)0x5a31f8;
    piStack_1a8 = piVar12;
    sprintf();
    piStack_1a8 = (int *)puVar14[1];
    puStack_1ac = auStack_178;
    puStack_1b0 = (undefined1 *)0x971120;
    piStack_1b4 = (int *)0x5a3212;
    func_0x0076d240();
    puStack_1bc = &stack0xfffffe7c;
    puStack_1b8 = (undefined1 *)0x971108;
    piStack_1c0 = (int *)0x5a321f;
    piStack_1b4 = piVar12;
    sprintf();
    piStack_1b4 = (int *)puVar14[0x4d];
    puStack_1b8 = &stack0xfffffe7c;
    puStack_1bc = (undefined1 *)0x971120;
    piStack_1c0 = (int *)0x5a323c;
    func_0x0076d240();
    piStack_1c0 = piVar12;
    sprintf(&piStack_190,0x971100);
    piStack_1c0 = (int *)puVar14[0x4e];
    func_0x0076d240(0x971120,&piStack_190);
    sprintf(&piStack_19c,0x9710f8,piVar12);
    func_0x0076d240(0x971120,&piStack_19c,puVar14[0x4f]);
    sprintf(&piStack_1a8,0x9710f0,piVar12);
    func_0x0076d240(0x971120,&piStack_1a8,puVar14[0x9b]);
    sprintf(&piStack_1b4,0x9710e8,piVar12);
    func_0x0076d240(0x971120,&piStack_1b4,puVar14[0x9c]);
    sprintf(&piStack_1c0,0x9710e0,piVar12);
    func_0x0076d240(0x971120,&piStack_1c0,puVar14[0x9d]);
    piVar12 = (int *)((int)piVar12 + 1);
    puVar14 = puVar14 + 3;
  } while ((int)piVar12 < 0x1a);
  piVar12 = (int *)0x0;
  puVar14 = (undefined4 *)(param_1 + 0x4b4);
  do {
    puStack_198 = (undefined4 *)auStack_160;
    piStack_194 = (int *)0x971128;
    piStack_19c = (int *)0x5a3330;
    piStack_190 = piVar12;
    sprintf();
    piStack_190 = (int *)puVar14[-1];
    piStack_194 = (int *)auStack_160;
    puStack_198 = (undefined4 *)0x9710d8;
    piStack_19c = (int *)0x5a334a;
    func_0x0076d240();
    piStack_1a4 = &iStack_16c;
    piStack_1a0 = (int *)0x971118;
    piStack_1a8 = (int *)0x5a3357;
    piStack_19c = piVar12;
    sprintf();
    piStack_19c = (int *)*puVar14;
    piStack_1a0 = &iStack_16c;
    piStack_1a4 = (int *)0x9710d8;
    piStack_1a8 = (int *)0x5a3370;
    func_0x0076d240();
    puStack_1b0 = auStack_178;
    puStack_1ac = (undefined1 *)0x971110;
    piStack_1b4 = (int *)0x5a337d;
    piStack_1a8 = piVar12;
    sprintf();
    piStack_1a8 = (int *)puVar14[1];
    puStack_1ac = auStack_178;
    puStack_1b0 = (undefined1 *)0x9710d8;
    piStack_1b4 = (int *)0x5a3397;
    func_0x0076d240();
    piVar12 = (int *)((int)piVar12 + 1);
    puVar14 = puVar14 + 3;
  } while ((int)piVar12 < 9);
  piVar12 = (int *)0x0;
  puVar14 = (undefined4 *)(param_1 + 0x520);
  do {
    puStack_198 = (undefined4 *)auStack_160;
    piStack_194 = (int *)0x971128;
    piStack_19c = (int *)0x5a33b5;
    piStack_190 = piVar12;
    sprintf();
    piStack_190 = (int *)puVar14[-1];
    piStack_194 = (int *)auStack_160;
    puStack_198 = (undefined4 *)0x9710d0;
    piStack_19c = (int *)0x5a33cf;
    func_0x0076d240();
    piStack_1a4 = &iStack_16c;
    piStack_1a0 = (int *)0x971118;
    piStack_1a8 = (int *)0x5a33dc;
    piStack_19c = piVar12;
    sprintf();
    piStack_19c = (int *)*puVar14;
    piStack_1a0 = &iStack_16c;
    piStack_1a4 = (int *)0x9710d0;
    piStack_1a8 = (int *)0x5a33f5;
    func_0x0076d240();
    puStack_1b0 = auStack_178;
    puStack_1ac = (undefined1 *)0x971110;
    piStack_1b4 = (int *)0x5a3402;
    piStack_1a8 = piVar12;
    sprintf();
    piStack_1a8 = (int *)puVar14[1];
    puStack_1ac = auStack_178;
    puStack_1b0 = (undefined1 *)0x9710d0;
    piStack_1b4 = (int *)0x5a341c;
    func_0x0076d240();
    piVar12 = (int *)((int)piVar12 + 1);
    puVar14 = puVar14 + 3;
  } while ((int)piVar12 < 8);
  piStack_190 = (int *)0x5a342a;
  piStack_190 = (int *)func_0x0076eb20();
  puStack_198 = aiStack_110;
  piStack_194 = (int *)0x971130;
  piStack_19c = (int *)0x5a343a;
  sprintf();
  piStack_190 = aiStack_110;
  piStack_194 = (int *)0x5a344b;
  func_0x0076d4e0();
  piStack_194 = (int *)0x5a3454;
  func_0x0076c930();
  piStack_194 = *(int **)(param_1 + 0x8b4);
  if (piStack_194 != (int *)0x0) {
    puStack_198 = (undefined4 *)0x5a3466;
    func_0x0041a3c0();
    puStack_198 = (int *)0x5a346d;
    func_0x006e8850();
    *(undefined4 *)(param_1 + 0x8b4) = 0;
  }
  piStack_194 = *(int **)(param_1 + 0x8b8);
  if (piStack_194 != (int *)0x0) {
    puStack_198 = (undefined4 *)0x5a3483;
    func_0x0041a3c0();
    puStack_198 = (int *)0x5a348a;
    func_0x006e8850();
    *(undefined4 *)(param_1 + 0x8b4) = 0;
  }
  piStack_194 = (int *)0x5a3497;
  uVar6 = FUN_0072e990();
  puStack_8 = (undefined *)0xffffffff;
  piStack_194 = (int *)0x5a34ad;
  func_0x0076c6b0();
  *unaff_FS_OFFSET = uStack_10;
  return uVar6;
}


/* ==================================================================== */
/* Address: 0x005a36f0 | Classified: elementclient::Win_Agreement@0x5a36f0 */
/* ==================================================================== */

undefined4 FUN_005a36f0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  int iStack_18;
  int iStack_14;
  
  iStack_14 = 0x9711b4;
  iStack_18 = 0x5a3706;
  iStack_18 = FUN_007359b0();
  puStack_1c = (undefined1 *)0x5a370f;
  iVar2 = _stricmp();
  if (iVar2 == 0) {
    iStack_14 = 0x9711dc;
    iStack_18 = param_1;
    puStack_1c = (undefined1 *)0x5a3726;
    puStack_1c = (undefined1 *)_stricmp();
    if (puStack_1c == (undefined1 *)0x0) {
      iStack_14 = 1;
      uStack_20 = 0x9711b4;
      uStack_24 = 0x5a373d;
      iStack_18 = (int)puStack_1c;
      FUN_0072fb20();
      uStack_24 = 0x5a3744;
      FUN_00735c50();
      uStack_24 = 1;
      uStack_28 = 0;
      uStack_2c = 1;
      uStack_30 = 0x9711a4;
      uStack_34 = 0x5a3756;
      FUN_0072fb20();
      uStack_34 = 0x5a375d;
      FUN_00735c50();
      uStack_34 = 0;
      FUN_0072fb20(0x96e344);
      FUN_007385b0();
      return 1;
    }
    iStack_14 = 0x9711d4;
    iStack_18 = param_1;
    puStack_1c = (undefined1 *)0x5a3783;
    iStack_14 = _stricmp();
    if (iStack_14 == 0) {
      iStack_18 = 0x5a3795;
      PostQuitMessage();
      return 1;
    }
  }
  else {
    iStack_14 = 0x969e98;
    iStack_18 = param_1;
    puStack_1c = (undefined1 *)0x5a37aa;
    iVar2 = _stricmp();
    if (iVar2 != 0) {
      iStack_14 = 0x95b69c;
      iStack_18 = param_1;
      puStack_1c = (undefined1 *)0x5a37b9;
      iVar2 = _stricmp();
      if (iVar2 != 0) {
        return 1;
      }
    }
    iStack_14 = 1;
    iStack_18 = 0;
    puStack_1c = (undefined1 *)0x0;
    uStack_20 = 0x5a37cd;
    FUN_00735c50();
    uStack_20 = 0x96df38;
    uStack_24 = 0x5a37d9;
    FUN_0072fb20();
    uStack_24 = 0x96e344;
    uStack_28 = 0x5a37e7;
    FUN_0072fb20();
    uStack_28 = 1;
    uStack_2c = 0;
    uStack_30 = 1;
    uStack_34 = 0x5a37f6;
    FUN_00735c50();
    puStack_1c = (undefined1 *)&uStack_34;
    func_0x005a9580(&uStack_34);
    cVar1 = func_0x0057a020();
    if (cVar1 == '\0') {
      FUN_00735c50(1,0,1);
      FUN_007385b0(0);
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x005a3830 | Classified: elementclient::confirm@0x5a3830 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005a3830(undefined4 param_1)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_194;
  undefined *puStack_190;
  undefined1 *puStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  int iStack_174;
  int iStack_170;
  int iStack_16c;
  undefined1 *puStack_168;
  int iStack_164;
  undefined4 uStack_160;
  undefined1 *puStack_15c;
  undefined1 *puStack_158;
  undefined1 *puStack_154;
  undefined1 auStack_140 [4];
  undefined1 auStack_13c [40];
  undefined1 auStack_114 [4];
  undefined1 auStack_110 [136];
  uint uStack_88;
  undefined1 uStack_58;
  undefined1 uStack_54;
  undefined4 uStack_24;
  undefined1 uStack_20;
  undefined1 uStack_1c;
  undefined1 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008b72f2;
  *unaff_FS_OFFSET = &uStack_c;
  puStack_154 = (undefined1 *)0x95b69c;
  puStack_158 = (undefined1 *)param_1;
  puStack_15c = (undefined1 *)0x5a3865;
  iVar3 = _stricmp();
  if (iVar3 == 0) {
    puStack_154 = (undefined1 *)0x96e344;
    puStack_158 = (undefined1 *)0x5a3883;
    puStack_158 = (undefined1 *)FUN_007359b0();
    puStack_15c = (undefined1 *)0x5a3886;
    iVar3 = _stricmp();
    if (iVar3 == 0) {
      puStack_154 = (undefined1 *)0x96e330;
      puStack_158 = (undefined1 *)0x5a3899;
      piVar4 = (int *)FUN_00737400();
      puStack_158 = (undefined1 *)0x9b3c40;
      puStack_15c = (undefined1 *)0x5a38a5;
      puStack_15c = (undefined1 *)(**(code **)(*piVar4 + 0x30))();
      uStack_160 = 0x5a38ac;
      puStack_154 = (undefined1 *)_wcsicmp();
      if (puStack_154 == (undefined1 *)0x0) {
        puStack_158 = (undefined1 *)0xa0ffffff;
        uStack_160 = 0xca;
        iStack_164 = 0x5a38c6;
        puStack_15c = puStack_154;
        iStack_164 = FUN_0072ef30();
        puStack_168 = &DAT_009b3c44;
        iStack_16c = 0x5a38d3;
        FUN_00730110();
        goto LAB_005a3ca1;
      }
    }
    puStack_154 = (undefined1 *)0x97121c;
    puStack_158 = (undefined1 *)0x5a38e4;
    piVar4 = (int *)FUN_00737400();
    puStack_158 = (undefined1 *)0x5a38eb;
    puStack_158 = (undefined1 *)(**(code **)(*piVar4 + 0x30))();
    puStack_15c = (undefined1 *)0x5a38f5;
    FUN_00765050();
    puStack_15c = (undefined1 *)0x97120c;
    uStack_c = 0;
    uStack_160 = 0x5a390c;
    piVar4 = (int *)FUN_00737400();
    uStack_160 = 0x5a3913;
    uStack_160 = (**(code **)(*piVar4 + 0x30))();
    iStack_164 = 0x5a391d;
    FUN_00765050();
    uStack_14 = 1;
    iStack_164 = 0x5a392a;
    func_0x0043c740();
    iStack_164 = 0x97121c;
    puStack_168 = (undefined1 *)0x5a3936;
    piVar4 = (int *)FUN_00737400();
    puStack_168 = (undefined1 *)0x9b3c40;
    iStack_16c = 0x5a3942;
    (**(code **)(*piVar4 + 0x34))();
    iStack_16c = 0x97120c;
    iStack_170 = 0x5a394e;
    piVar4 = (int *)FUN_00737400();
    iStack_170 = 0x9b3c40;
    iStack_174 = 0x5a395a;
    (**(code **)(*piVar4 + 0x34))();
    iStack_174 = 0x97121c;
    uStack_178 = 0x5a3966;
    uStack_178 = FUN_00737400();
    uStack_17c = 0x5a396e;
    FUN_007373a0();
    uStack_17c = 0x5a3973;
    func_0x0043c740();
    if ((*(int *)((int)puStack_168 + -8) < 1) || (*(int *)(iStack_164 + -8) < 1)) {
      uStack_17c = 0;
      uStack_180 = 0xa0ffffff;
      uStack_184 = 0;
      uStack_188 = 0xcb;
      puStack_18c = (undefined1 *)0x5a3a9c;
      puStack_18c = (undefined1 *)FUN_0072ef30();
      puStack_190 = &DAT_009b3c44;
      uStack_194 = 0x5a3aa9;
      FUN_00730110();
    }
    else {
      uStack_17c = 0x9711fc;
      iVar3 = *(int *)(_DAT_009b3eec + 0x20);
      uStack_180 = 0x5a39a6;
      FUN_00737400();
      uStack_180 = 0x5a39ad;
      func_0x0043c740();
      uStack_180 = 0x5a39b6;
      FUN_00765650();
      uStack_180 = 0;
      uStack_184 = 0;
      puStack_18c = auStack_13c;
      uStack_188 = 0x100;
      puStack_190 = (undefined *)0xffffffff;
      uStack_194 = iStack_16c;
      (*_DAT_009b3b60)(0xfde9,0);
      func_0x007638a0(&puStack_15c);
      puVar5 = (undefined4 *)func_0x00764aa0(&uStack_194,puStack_18c);
      uStack_54 = 2;
      func_0x007638a0(*puVar5);
      uStack_58 = 1;
      func_0x007637f0();
      uVar1 = FUN_0074c280();
      *(undefined1 *)(iVar3 + 0x144) = uVar1;
      func_0x0043c740();
      func_0x005cf4a0();
      FUN_0072fb20(0x96e344,0,0,1);
      FUN_00735c50();
      FUN_0072fb20(0x971188,0,0,1);
      FUN_00735c50();
      FUN_0072fb20(0x971194,1,0,1);
      FUN_00735c50();
    }
    uStack_88 = uStack_88 & 0xffffff00;
    FUN_00765200();
    uStack_88 = 0xffffffff;
    FUN_00765200();
  }
  else {
    puStack_154 = (undefined1 *)0x9711ec;
    puStack_158 = (undefined1 *)param_1;
    puStack_15c = (undefined1 *)0x5a3adb;
    puStack_154 = (undefined1 *)_stricmp();
    if (puStack_154 == (undefined1 *)0x0) {
      puStack_158 = (undefined1 *)0x96e344;
      puStack_15c = (undefined1 *)0x5a3aef;
      FUN_0072fb20();
      puStack_15c = (undefined1 *)0x5a3af6;
      FUN_007385b0();
      puStack_15c = (undefined1 *)0x1;
      uStack_160 = 0;
      iStack_164 = 1;
      puStack_168 = (undefined1 *)0x96df38;
      iStack_16c = 0x5a3b08;
      FUN_0072fb20();
      iStack_16c = 0x5a3b0f;
      FUN_00735c50();
    }
    else {
      puStack_154 = (undefined1 *)0x95cab0;
      puStack_158 = (undefined1 *)param_1;
      puStack_15c = (undefined1 *)0x5a3b1c;
      iVar3 = _stricmp();
      if (iVar3 == 0) {
        puStack_154 = (undefined1 *)0x5a3b30;
        func_0x0076c660();
        uStack_4 = 3;
        puStack_154 = (undefined1 *)0x5a3b40;
        puStack_154 = (undefined1 *)func_0x0076eb20();
        puStack_15c = auStack_110;
        puStack_158 = (undefined1 *)0x971070;
        uStack_160 = 0x5a3b51;
        sprintf();
        puStack_154 = &DAT_009b3c44;
        puStack_158 = (undefined1 *)0x5a3b62;
        func_0x007636b0();
        puStack_158 = auStack_114;
        puStack_8 = (undefined *)CONCAT31(puStack_8._1_3_,4);
        puStack_15c = (undefined1 *)0x5a3b78;
        cVar2 = func_0x0076c730();
        if (cVar2 != '\0') {
          puStack_15c = &DAT_009b3c44;
          uStack_160 = 0x9711e4;
          puStack_168 = auStack_140;
          iStack_164 = 0x97105c;
          iStack_16c = 0x5a3b99;
          iStack_16c = func_0x0076cf90();
          uStack_1c = 5;
          iStack_170 = 0x5a3bab;
          func_0x00763940();
          uStack_20 = 4;
          iStack_170 = 0x5a3bbc;
          func_0x007637f0();
          iStack_170 = 0x5a3bc5;
          func_0x0076c930();
        }
        puStack_15c = &DAT_009b3c44;
        uStack_160 = 0x5a3bd3;
        cVar2 = func_0x00763c30();
        if (cVar2 == '\0') {
          uStack_160 = 1;
          iStack_164 = 0;
          puStack_168 = (undefined1 *)0x0;
          iStack_170 = 0x952318;
          iStack_174 = 0;
          uStack_178 = 0x5a3bef;
          iStack_16c = unaff_EDI;
          ShellExecuteA();
        }
        uStack_10 = CONCAT31(uStack_10._1_3_,3);
        uStack_160 = 0x5a3c00;
        func_0x007637f0();
        uStack_10 = 0xffffffff;
        uStack_160 = 0x5a3c14;
        func_0x0076c6b0();
      }
      else {
        puStack_154 = (undefined1 *)0x95baec;
        puStack_158 = (undefined1 *)param_1;
        puStack_15c = (undefined1 *)0x5a3c21;
        iVar3 = _stricmp();
        if (iVar3 == 0) {
          iStack_16c = 0x96e344;
          iStack_170 = 0x5a3c3b;
          iStack_170 = FUN_007359b0();
          iStack_174 = 0x5a3c3e;
          iStack_16c = _stricmp();
          if (iStack_16c == 0) {
            iStack_170 = 0x5a3c4c;
            PostQuitMessage();
          }
          else {
            iStack_16c = 0x971194;
            iStack_170 = 0x5a3c5a;
            iStack_170 = FUN_007359b0();
            iStack_174 = 0x5a3c5d;
            iStack_174 = _stricmp();
            if (iStack_174 == 0) {
              iStack_16c = 1;
              uStack_178 = 0x971194;
              uStack_17c = 0x5a3c74;
              iStack_170 = iStack_174;
              FUN_0072fb20();
              uStack_17c = 0x5a3c7b;
              FUN_00735c50();
              uStack_17c = 1;
              uStack_180 = 0;
              uStack_184 = 1;
              uStack_188 = 0x96e344;
              puStack_18c = (undefined1 *)0x5a3c8d;
              FUN_0072fb20();
              puStack_18c = (undefined1 *)0x5a3c94;
              FUN_00735c50();
              puStack_18c = (undefined1 *)0x5a3ca1;
              func_0x005cf710();
            }
          }
        }
      }
    }
  }
LAB_005a3ca1:
  *unaff_FS_OFFSET = uStack_24;
  return 1;
}


/* ==================================================================== */
/* Address: 0x005a3cc0 | Classified: elementclient::Char_@0x5a3cc0 */
/* ==================================================================== */

undefined4 FUN_005a3cc0(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 unaff_ESI;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined1 *puStack_d0;
  undefined *puStack_cc;
  int *piStack_c8;
  undefined4 uStack_c4;
  int *piStack_c0;
  undefined4 uStack_bc;
  undefined1 *puStack_b8;
  undefined1 *puStack_b4;
  undefined4 uStack_b0;
  int *piStack_ac;
  undefined1 auStack_84 [4];
  undefined1 auStack_80 [84];
  undefined4 uStack_2c;
  undefined4 uStack_1c;
  undefined4 uStack_14;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &UNK_008b730b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  piStack_ac = (int *)0x96e344;
  uStack_b0 = 0x5a3cef;
  uVar1 = FUN_0072fb20();
  uStack_b0 = 0x97120c;
  puStack_b4 = (undefined1 *)0x5a3d01;
  piVar2 = (int *)FUN_00737400();
  puVar6 = puStack_4;
  puStack_b4 = (undefined1 *)0x971240;
  puStack_b8 = puStack_4;
  uStack_bc = 0x5a3d1a;
  iVar3 = strstr();
  if (iVar3 == 0) {
    puStack_b4 = (undefined1 *)0x966c64;
    puStack_b8 = puVar6;
    uStack_bc = 0x5a3d8e;
    iVar3 = _stricmp();
    uStack_c4 = uVar1;
    if (iVar3 == 0) {
      uStack_c4 = 0x971238;
      piStack_c8 = (int *)0x5a3daa;
      puStack_b4 = (undefined1 *)FUN_00737400();
      piStack_ac = (int *)&piStack_c8;
      puStack_cc = &DAT_009b3c44;
      puStack_d0 = (undefined1 *)0x5a3dc1;
      func_0x007636b0();
      puStack_d0 = (undefined1 *)0x5a3dc8;
      iVar3 = FUN_00742650();
      puVar6 = (undefined1 *)0x61;
      iVar5 = 0x1a;
      puVar7 = (undefined1 *)(int)(char)((-(1 - iVar3 != 0) & 0xe0U) + 0x61);
      do {
        puStack_d0 = puVar6;
        sprintf(&stack0xffffff58,0x971230);
        puStack_d0 = puVar7;
        swprintf(auStack_80,0x94e424);
        puStack_d0 = &stack0xffffff58;
        piVar2 = (int *)FUN_00737400();
        (**(code **)(*piVar2 + 0x34))(auStack_84);
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      puStack_b4 = (undefined1 *)&puStack_d0;
      func_0x007636b0(&DAT_009b3c44);
      FUN_007426d0(1 - iVar3);
      piVar2 = piStack_ac;
      uStack_c4 = unaff_ESI;
    }
  }
  else {
    puStack_b4 = puVar6;
    puStack_b8 = (undefined1 *)0x5a3d2e;
    piVar4 = (int *)FUN_00737400();
    puStack_b8 = (undefined1 *)0x5a3d37;
    puStack_b8 = (undefined1 *)(**(code **)(*piVar2 + 0x30))();
    uStack_bc = 0x5a3d41;
    FUN_00765050();
    uStack_14 = 0;
    uStack_bc = 0x5a3d53;
    uStack_bc = (**(code **)(*piVar4 + 0x30))();
    piStack_c0 = (int *)0x5a3d5d;
    FUN_00765430();
    piStack_c0 = piStack_ac;
    uStack_c4 = 0x5a3d69;
    (**(code **)(*piVar2 + 0x34))();
    uStack_1c = 0xffffffff;
    uStack_c4 = 0x5a3d7d;
    FUN_00765200();
    uStack_c4 = uVar1;
  }
  piStack_c8 = (int *)0x5a3e5f;
  FUN_0072f7d0();
  puStack_cc = (undefined *)0x5a3e67;
  piStack_c8 = piVar2;
  FUN_007373a0();
  *unaff_FS_OFFSET = uStack_2c;
  return 1;
}


/* ==================================================================== */
/* Address: 0x005a3e90 | Classified: elementclient::IDCANCEL@0x5a3e90 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_005a3e90(int param_1,int param_2)

{
  float *pfVar1;
  float *pfVar2;
  undefined4 *puVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  char *pcVar12;
  int iVar13;
  undefined4 *unaff_FS_OFFSET;
  bool bVar14;
  undefined4 uVar15;
  int in_stack_fffffe28;
  int *piStack_1d4;
  int *piStack_1d0;
  undefined4 uStack_1cc;
  undefined *puStack_1c8;
  undefined4 uStack_1c4;
  undefined *puStack_1c0;
  float fStack_1bc;
  float fStack_1b8;
  undefined *puStack_1b4;
  undefined *puStack_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  undefined1 uStack_1a0;
  undefined2 uStack_19f;
  undefined1 uStack_19d;
  undefined *puStack_19c;
  undefined4 uStack_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  undefined1 uStack_18c;
  undefined2 uStack_18b;
  undefined1 uStack_189;
  undefined *puStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  undefined *puStack_17c;
  undefined *puStack_178;
  undefined *puStack_174;
  undefined *puStack_170;
  undefined *puStack_16c;
  undefined *puStack_168;
  undefined *puStack_164;
  undefined *puStack_160;
  int iStack_15c;
  undefined4 uStack_fc;
  undefined4 uStack_90;
  undefined4 uStack_7c;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008b73f9;
  *unaff_FS_OFFSET = &uStack_c;
  iStack_15c = 0x95baec;
  puStack_160 = (undefined *)param_2;
  puStack_164 = (undefined *)0x5a3ec6;
  iVar5 = _stricmp();
  if (iVar5 == 0) {
    *(undefined4 *)(param_1 + 0x5a4) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x5a0) = 0xffffffff;
    *(undefined1 *)(param_1 + 0x5a9) = 0;
    *(undefined1 *)(param_1 + 0x5a8) = 0;
    puStack_160 = *(undefined **)(param_1 + 0x638);
    iStack_15c = (int)puStack_160 + *(int *)(param_1 + 0x644) * 0x8c;
    puStack_164 = (undefined *)0x5a3f11;
    func_0x0054c2b0();
    iVar5 = 0;
    if (0 < *(int *)(param_1 + 0x654)) {
      do {
        piVar6 = *(int **)(*(int *)(param_1 + 0x648) + iVar5 * 4);
        if (piVar6 != (int *)0x0) {
          puStack_164 = (undefined *)0x5a3f2f;
          (**(code **)(*piVar6 + 0x40))();
          puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x648) + iVar5 * 4);
          if (puVar3 != (undefined4 *)0x0) {
            puStack_164 = (undefined *)0x1;
            puStack_168 = (undefined *)0x5a3f42;
            (**(code **)*puVar3)();
          }
          *(undefined4 *)(*(int *)(param_1 + 0x648) + iVar5 * 4) = 0;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(param_1 + 0x654));
    }
    puStack_168 = *(undefined **)(param_1 + 0x648);
    puStack_164 = (undefined *)((int)puStack_168 + *(int *)(param_1 + 0x654) * 4);
    puStack_16c = (undefined *)0x5a3f72;
    func_0x006e04e0();
    puStack_170 = *(undefined **)(param_1 + 0x638);
    puStack_16c = puStack_170 + *(int *)(param_1 + 0x644) * 0x8c;
    puStack_174 = (undefined *)0x5a3f8f;
    func_0x0054c2b0();
    puStack_174 = (undefined *)0x5a3f96;
    func_0x005a8e20();
    puStack_174 = (undefined *)0x0;
    puStack_178 = (undefined *)0x5a3f9e;
    func_0x005a83d0();
    puStack_178 = (undefined *)0x1;
    puStack_17c = (undefined *)0x0;
    uStack_180 = 0;
    uStack_184 = 0x969efc;
    puStack_188 = (undefined *)0x5a3fae;
    FUN_0072fb20();
    puStack_188 = (undefined *)0x5a3fb5;
    FUN_00735c50();
    puStack_188 = (undefined *)0x1;
    uStack_18c = 0;
    uStack_18b = 0;
    uStack_189 = 0;
    uStack_190 = 0;
    uStack_194 = 0x9712ec;
    uStack_198 = 0x5a3fc5;
    FUN_0072fb20();
    uStack_198 = 0x5a3fcc;
    FUN_00735c50();
    uStack_198 = 1;
    puStack_19c = (undefined *)0x0;
    uStack_1a0 = 0;
    uStack_19f = 0;
    uStack_19d = 0;
    uStack_1a4 = 0x969ef0;
    uStack_1a8 = 0x5a3fdc;
    FUN_0072fb20();
    uStack_1a8 = 0x5a3fe3;
    FUN_00735c50();
    uStack_1a8 = 1;
    uStack_1ac = 0;
    puStack_1b0 = (undefined *)0x0;
    puStack_1b4 = (undefined *)0x969ee4;
    fStack_1b8 = 8.288135e-39;
    FUN_0072fb20();
    fStack_1b8 = 8.288145e-39;
    FUN_00735c50();
    fStack_1b8 = 1.4013e-45;
    fStack_1bc = 0.0;
    puStack_1c0 = (undefined *)0x1;
    uStack_1c4 = (undefined *)0x96e344;
    puStack_1c8 = (undefined *)0x5a400b;
    FUN_0072fb20();
    puStack_1c8 = (undefined *)0x5a4012;
    FUN_00735c50();
    puStack_1c8 = (undefined *)0x97121c;
    uStack_1cc = 0x96e344;
    piStack_1d0 = (int *)0x5a4023;
    FUN_0072fb20();
    piStack_1d0 = (int *)0x5a402a;
    piVar6 = (int *)FUN_00737400();
    piStack_1d0 = (int *)0x9b3c40;
    piStack_1d4 = (int *)0x5a4036;
    (**(code **)(*piVar6 + 0x34))();
    piStack_1d4 = (int *)0x97120c;
    FUN_0072fb20(0x96e344);
    piVar6 = (int *)FUN_00737400();
    (**(code **)(*piVar6 + 0x34))(0x9b3c40);
    func_0x005cf710();
    goto LAB_005a4c39;
  }
  iStack_15c = 0x95b69c;
  puStack_160 = (undefined *)param_2;
  puStack_164 = (undefined *)0x5a4074;
  iVar5 = _stricmp();
  if ((iVar5 == 0) || (iVar5 = _stricmp(param_2,0x969e98), iVar5 == 0)) {
    if (-1 < *(int *)(param_1 + 0x5a0)) {
      FUN_0072fb20(0x969ef0,0x967538);
      FUN_00737400();
      cVar4 = FUN_00741f30();
      if (cVar4 != '\0') {
        if ((*(char *)(*(int *)(*(int *)(_DAT_009b3eec + 0x20) + 0xac) + 0x7c) == '\0') ||
           (cVar4 = func_0x005c24d0(), cVar4 == '\0')) {
          func_0x00437460(*(int *)(param_1 + 0x638) + *(int *)(param_1 + 0x5a0) * 0x8c);
          func_0x005d4780(*(undefined4 *)
                           (*(int *)(param_1 + 0x638) + 4 + *(int *)(param_1 + 0x5a0) * 0x8c));
          FUN_0072fb20(0x969ef0,0x967538,0);
          FUN_00737400();
          FUN_00741f40();
        }
        else {
          uVar7 = FUN_0072ef30(0xe4,0,0xa0ffffff,0);
          FUN_00730110(&DAT_009b3c44,uVar7);
        }
      }
    }
    goto LAB_005a4c39;
  }
  iVar5 = _stricmp(param_2,0x9712dc);
  if (iVar5 == 0) {
    uStack_1ac = 0;
    uStack_1a8 = 0;
    uStack_1a4 = 0;
    puStack_1b0 = &UNK_008d6c34;
    puStack_170 = (undefined *)0x0;
    puStack_16c = (undefined *)0x0;
    puStack_168 = (undefined *)0x0;
    puStack_174 = &UNK_008d6c34;
    puStack_1c0 = &UNK_008d6c18;
    func_0x005aa480((int)&uStack_1c4 + 3);
    uStack_1c4 = &UNK_008d6bfc;
    puStack_164 = (undefined *)0x0;
    puStack_160 = (undefined *)0x0;
    iStack_15c = 0;
    puStack_168 = &UNK_008d6c34;
    uStack_184 = 0;
    uStack_180 = 0;
    puStack_17c = (undefined *)0x0;
    puStack_188 = &UNK_008d6c34;
    func_0x00432800(&puStack_188);
    func_0x00432800(&puStack_16c);
    func_0x00439ed0(&uStack_1cc);
    func_0x00432800(&uStack_184);
    func_0x00432800(&uStack_1c4);
    puStack_19c = &UNK_008d6c34;
    free(uStack_198);
    puStack_17c = &UNK_008d6c34;
    free(puStack_178);
    uStack_1a0 = SUB41(&piStack_1d4,0);
    uStack_19f = (undefined2)((uint)&piStack_1d4 >> 8);
    uStack_19d = (undefined1)((uint)&piStack_1d4 >> 0x18);
    if (piStack_1d4 != piStack_1d0) {
      do {
        (**(code **)(*piStack_1d4 + 8))(0);
        piStack_1d4 = piStack_1d4 + 0xe;
      } while (piStack_1d4 != piStack_1d0);
    }
    func_0x0043a550();
    uStack_18c = 0x34;
    uStack_18b = 0x8d6c;
    uStack_189 = 0;
    free(puStack_188);
    puStack_1c8 = &UNK_008d6c34;
    free(uStack_1c4);
    iVar5 = 0x1a;
    do {
      puStack_1b0 = (undefined *)0x0;
      uStack_1ac = 0;
      uStack_1a8 = 0;
      puStack_1b4 = &UNK_008d6c34;
      puStack_16c = &UNK_008d6c18;
      puStack_168 = (undefined *)0x0;
      puStack_164 = (undefined *)0xffffffff;
      puStack_160 = (undefined *)0x0;
      iStack_15c = 0;
      func_0x00432800(&puStack_1b4);
      puStack_170 = &UNK_008d6ccc;
      func_0x005aa260(uStack_fc,&puStack_170);
      puStack_164 = &UNK_008d6c34;
      free(puStack_160);
      puStack_178 = &UNK_008d6c3c;
      puStack_1c0 = &UNK_008d6c34;
      free(fStack_1bc);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    FUN_0072fb20(0x969efc,0,0,1);
    FUN_00735c50();
    FUN_0072fb20(0x9712ec,0,0,1);
    FUN_00735c50();
    FUN_0072fb20(0x969ef0,0,0,1);
    FUN_00735c50();
    FUN_0072fb20(0x969ee4,0,0,1);
    FUN_00735c50();
    FUN_0072fb20(0x969f2c,1,0,1);
    FUN_00735c50();
    FUN_0072fb20(0x969f2c,0x9712d0);
    FUN_00737400();
    iVar5 = FUN_0074daf0();
    if (iVar5 < 1) {
      iVar5 = 0x137;
      do {
        uVar7 = FUN_0072ef30(iVar5);
        FUN_0074d8e0(uVar7);
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0x13b);
    }
    FUN_0074db10(3);
    uVar7 = FUN_0072fb20(0x969f2c);
    FUN_005a4c70(0x9712c8,uVar7);
    *(undefined4 *)(param_1 + 0x658) = 2;
    *(undefined4 *)(param_1 + 0x65c) = 0;
    FUN_0072fb20(0x969f2c,0x97103c);
    piVar6 = (int *)FUN_00737400();
    (**(code **)(*piVar6 + 0x34))(0x9b3c40);
    func_0x005a83d0(*(int *)(param_1 + 0x658) + 10);
    bVar14 = *(char *)(*(int *)(param_1 + 0x65c) + 0x971008 + *(int *)(param_1 + 0x658) * 2) == '\0'
    ;
    if (bVar14) {
      FUN_0072fb20(0x969f2c,0x9712b4,0);
      FUN_00737400();
      FUN_00741f40();
    }
    else {
      FUN_0072fb20(0x969f2c,0x9712b4,1);
      FUN_00737400();
      FUN_00741f40();
    }
    FUN_0072fb20(0x969f2c,0x95c8e8,!bVar14);
    FUN_00737400();
    FUN_00741f40();
    free(0);
    puStack_160 = &UNK_008d6c34;
    free(iStack_15c);
    func_0x0059b000();
    func_0x005ca820();
    uStack_1a0 = 0x34;
    uStack_19f = 0x8d6c;
    uStack_19d = 0;
    free(puStack_19c);
    puStack_1b0 = &UNK_008d6c34;
    free(uStack_1ac);
    goto LAB_005a4c39;
  }
  iVar5 = _stricmp(param_2,0x9712a4);
  if (iVar5 == 0) {
    uVar7 = FUN_0072ef30(0xce,4,0xa0ffffff,0);
    FUN_00730110(0x971294,uVar7);
    goto LAB_005a4c39;
  }
  iVar5 = _stricmp(param_2,0x97128c);
  if (iVar5 == 0) {
    func_0x005d49d0(*(undefined4 *)
                     (*(int *)(param_1 + 0x638) + 4 + *(int *)(param_1 + 0x5a0) * 0x8c));
    goto LAB_005a4c39;
  }
  iVar5 = _stricmp(param_2,0x971284);
  if (iVar5 == 0) {
    FUN_0072fb20(0x969efc,0,0,1);
    FUN_00735c50();
    FUN_0072fb20(0x9712ec,0,0,1);
    FUN_00735c50();
    FUN_0072fb20(0x969ef0,0,0,1);
    FUN_00735c50();
    FUN_0072fb20(0x969ee4,0,0,1);
    FUN_00735c50();
    FUN_0072fb20(0x969f08,1,0,1);
    FUN_00735c50();
    func_0x005a97c0(0);
    goto LAB_005a4c39;
  }
  iVar5 = strstr(param_2,0x97127c);
  if (iVar5 == 0) {
    iVar5 = strstr(param_2,0x971250);
    if (iVar5 == 0) {
      iVar5 = strstr(param_2,0x971248);
      if ((iVar5 != 0) && (*(int *)(param_1 + 0x654) != 0)) {
        iVar5 = *(int *)(param_1 + 0x5a0) + -1;
        if (iVar5 < 0) {
          iVar5 = *(int *)(param_1 + 0x654) + -1;
        }
        uStack_1ac = 0;
        uStack_1a8 = 0;
        uStack_1a4 = 0;
        uStack_1a0 = 0;
        uStack_19f = 0;
        puStack_1b0 = (undefined *)0x0;
        uStack_19d = 0;
        sprintf(&puStack_1b0,0x969edc,iVar5 + 1);
        FUN_005a3e90(&puStack_1b0,uStack_7c);
      }
    }
    else if (*(int *)(param_1 + 0x654) != 0) {
      iVar5 = *(int *)(param_1 + 0x5a0) + 1;
      if (*(int *)(param_1 + 0x654) == iVar5) {
        iVar5 = 0;
      }
      uStack_198 = 0;
      uStack_194 = 0;
      uStack_190 = 0;
      uStack_18c = 0;
      uStack_18b = 0;
      puStack_19c = (undefined *)0x0;
      uStack_189 = 0;
      sprintf(&puStack_19c,0x969edc,iVar5 + 1);
      FUN_005a3e90(&puStack_19c,uStack_7c);
    }
    goto LAB_005a4c39;
  }
  uVar10 = 0xffffffff;
  pcVar12 = (char *)0x97127c;
  do {
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    cVar4 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar4 != '\0');
  iVar5 = atoi((~uVar10 - 1) + param_2);
  iVar11 = iVar5 + -1;
  if ((*(int *)(param_1 + 0x654) <= iVar11) || (iVar11 == *(int *)(param_1 + 0x5a0)))
  goto LAB_005a4c39;
  if (*(int *)(*(int *)(param_1 + 0x648) + iVar11 * 4) == 0) {
    if ((DAT_009b7f0c & 1) == 0) {
      DAT_009b7f0c = DAT_009b7f0c | 1;
      func_0x005a8320(0x9b7f00);
      func_0x00892e60(&UNK_005a4c60);
    }
    puStack_188 = (undefined *)func_0x00763250(0x7b4);
    if (puStack_188 == (undefined *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = (int *)func_0x0046f840(0);
    }
    puStack_1c8 = (undefined *)(iVar11 * 0x8c);
    cVar4 = func_0x0046f8f0(puStack_1c8 + *(int *)(param_1 + 0x638));
    if (cVar4 == '\0') {
      func_0x007396e0(0x288,0x97108c);
    }
    (**(code **)(*piVar6 + 0x10))(0x9b7f00);
    puStack_1c8 = (undefined *)0x0;
    uStack_1c4 = (undefined *)0x0;
    puStack_1c0 = (undefined *)0xbf800000;
    (**(code **)(*piVar6 + 0x14))(&puStack_1c8,&DAT_009b4340);
    if (*(char *)(in_stack_fffffe28 + 0x44 + *(int *)(param_1 + 0x638)) == '\x01') {
      func_0x0046fcb0();
    }
    else {
      func_0x0046fd10();
    }
    *(int **)(*(int *)(param_1 + 0x648) + iVar11 * 4) = piVar6;
  }
  iVar13 = iVar11 * 0x8c;
  if (*(char *)(iVar13 + 0x44 + *(int *)(param_1 + 0x638)) == '\x01') {
    FUN_0072fb20(0x969ef0,0x967538,1);
    FUN_00737400();
    FUN_00741f40();
    FUN_0072fb20(0x969efc,0x971270,1);
    FUN_00737400();
    FUN_00741f40();
    FUN_0072fb20(0x969efc,0x971264,0);
    FUN_00737400();
    FUN_00741f40();
    cVar4 = func_0x0047f1b0(1);
    if (cVar4 == '\0') {
      iVar8 = iVar13 + *(int *)(param_1 + 0x638);
      iVar9 = time(0);
      if (iVar9 - *(int *)(iVar8 + 0x4c) < 0x2a300) {
        uVar15 = 1;
        uVar7 = 0x971258;
        goto LAB_005a4950;
      }
    }
    uVar15 = 0;
    uVar7 = 0x971258;
  }
  else {
    FUN_0072fb20(0x969ef0,0x967538,0);
    FUN_00737400();
    FUN_00741f40();
    FUN_0072fb20(0x969efc,0x971270,0);
    FUN_00737400();
    FUN_00741f40();
    FUN_0072fb20(0x969efc,0x971258,0);
    FUN_00737400();
    FUN_00741f40();
    uVar15 = 1;
    uVar7 = 0x971264;
  }
LAB_005a4950:
  FUN_0072fb20(0x969efc,uVar7,uVar15);
  FUN_00737400();
  FUN_00741f40();
  *(int *)(param_1 + 0x5a0) = iVar11;
  func_0x005a8750();
  FUN_007348e0(1,iVar5);
  uVar10 = (uint)*(byte *)(iVar13 + 10 + *(int *)(param_1 + 0x638));
  iVar8 = *(int *)(*(int *)(_DAT_009b3eec + 0x14) + 8);
  iVar5 = uVar10 * 3 + 0x60;
  iVar13 = uVar10 * 3 + 0x147;
  fStack_1b8 = *(float *)(param_1 + 8 + iVar5 * 4) - *(float *)(param_1 + 8 + iVar13 * 4);
  pfVar1 = (float *)(param_1 + iVar5 * 4);
  pfVar2 = (float *)(param_1 + iVar13 * 4);
  fStack_1bc = *(float *)(param_1 + 4 + iVar5 * 4) - pfVar2[1];
  puStack_1c0 = (undefined *)(*pfVar1 - *pfVar2);
  *(float *)(iVar8 + 0x14) = *pfVar1;
  *(float *)(iVar8 + 0x18) = pfVar1[1];
  *(float *)(iVar8 + 0x1c) = pfVar1[2];
  func_0x00774140();
  func_0x00773d00(param_1 + (uVar10 * 3 + 0xae) * 4,param_1 + (uVar10 * 3 + 0xfc) * 4);
  (**(code **)(**(int **)(*(int *)(param_1 + 0x648) + iVar11 * 4) + 0x10))(uVar7);
  puStack_1c8 = (undefined *)0x0;
  (**(code **)(**(int **)(*(int *)(param_1 + 0x648) + iVar11 * 4) + 0x14))
            (&uStack_1cc,&DAT_009b4340);
  FUN_00780a20();
LAB_005a4c39:
  *unaff_FS_OFFSET = uStack_90;
  return 1;
}


/* ==================================================================== */
/* Address: 0x005a4c70 | Classified: elementclient::IDCANCEL@0x5a4c70 */
/* ==================================================================== */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_005a4c70(int param_1,int ****param_2,int ****param_3)

{
  int iVar1;
  undefined *puVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int ****extraout_ECX;
  undefined1 **extraout_ECX_00;
  undefined1 **extraout_ECX_01;
  int ****extraout_ECX_02;
  int ****unaff_EBX;
  undefined **ppuVar9;
  uint unaff_ESI;
  undefined1 ****ppppuVar10;
  undefined4 *puVar11;
  int ****ppppiVar12;
  undefined4 *unaff_FS_OFFSET;
  bool bVar13;
  int ****unaff_retaddr;
  int **ppiStack_1ac;
  undefined1 *****pppppuStack_1a8;
  undefined1 ****ppppuStack_1a4;
  undefined *puStack_1a0;
  undefined **ppuStack_19c;
  int **ppiStack_198;
  int **ppiStack_194;
  undefined **ppuStack_190;
  undefined1 *****pppppuStack_18c;
  int ****ppppiStack_188;
  int ****ppppiStack_184;
  undefined1 ***pppuVar14;
  int ****ppppiStack_170;
  undefined1 *puStack_16c;
  float fStack_168;
  int aiStack_164 [4];
  undefined *puStack_154;
  undefined4 uStack_150;
  int iStack_14c;
  undefined1 *puStack_148;
  int ***pppiStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined *puStack_134;
  undefined *puStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined *puStack_120;
  undefined1 **ppuStack_11c;
  undefined *puStack_118;
  undefined *puStack_114;
  undefined *puStack_110;
  int **ppiStack_10c;
  int **ppiStack_108;
  undefined *puStack_104;
  undefined1 ****ppppuStack_100;
  undefined1 ****ppppuStack_fc;
  int iStack_f8;
  undefined1 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined *puStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined *puStack_d4;
  undefined1 **ppuStack_d0;
  undefined1 **ppuStack_cc;
  undefined4 uStack_c8;
  undefined *puStack_c4;
  undefined4 uStack_c0;
  undefined1 uStack_b8;
  undefined4 uStack_b7;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined *puStack_a8;
  undefined4 uStack_a4;
  undefined *puStack_a0;
  undefined4 uStack_9c;
  undefined *puStack_98;
  undefined4 uStack_94;
  undefined *puStack_90;
  undefined4 uStack_8c;
  undefined *puStack_88;
  undefined4 uStack_84;
  undefined *puStack_80;
  undefined1 *puStack_7c;
  undefined *puStack_78;
  undefined4 uStack_74;
  undefined1 *puStack_64;
  int ***apppiStack_60 [4];
  undefined4 uStack_50;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 *****pppppuStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined **ppuStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  ppuStack_4 = (undefined **)0xffffffff;
  puStack_8 = &UNK_008b7570;
  *unaff_FS_OFFSET = &uStack_c;
  ppppiStack_184 = (int ****)0x95baec;
  ppppiStack_188 = param_2;
  pppppuStack_18c = (undefined1 *****)0x5a4ca6;
  iVar4 = _stricmp();
  if (iVar4 == 0) {
    piVar5 = (int *)(param_1 + 0x660);
    ppppiStack_170 = (int ****)0x8;
    do {
      iVar4 = 2;
      do {
        if ((int *)*piVar5 != (int *)0x0) {
          ppppiStack_184 = (int ****)0x5a4cd1;
          (**(code **)(*(int *)*piVar5 + 0x40))();
          if ((undefined4 *)*piVar5 != (undefined4 *)0x0) {
            ppppiStack_184 = (int ****)0x1;
            ppppiStack_188 = (int ****)0x5a4cdd;
            (*(code *)**(undefined4 **)*piVar5)();
          }
          *piVar5 = 0;
        }
        piVar5 = piVar5 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      ppppiStack_170 = (int ****)((int)ppppiStack_170 + -1);
    } while (ppppiStack_170 != (int ****)0x0);
    ppppiStack_184 = *(int *****)(param_1 + 0x658);
    pppppuStack_18c = (undefined1 *****)&pppiStack_144;
    ppppiStack_188 = (int ****)0x969f18;
    ppuStack_190 = (undefined **)0x5a4d09;
    sprintf();
    ppppiStack_184 = &pppiStack_144;
    ppppiStack_188 = (int ****)0x5a4d18;
    iVar4 = FUN_0072fb20();
    if (iVar4 != 0) {
      ppppiStack_188 = (int ****)0x1;
      pppppuStack_18c = (undefined1 *****)0x0;
      ppiStack_194 = (int **)&puStack_148;
      ppuStack_190 = (undefined **)0x0;
      ppiStack_198 = (int **)0x5a4d2c;
      FUN_0072fb20();
      ppiStack_198 = (int **)0x5a4d33;
      FUN_00735c50();
    }
    ppppiStack_188 = (int ****)0x1;
    pppppuStack_18c = (undefined1 *****)0x0;
    ppuStack_190 = (undefined **)0x0;
    ppiStack_194 = (int **)0x969f2c;
    ppiStack_198 = (int **)0x5a4d43;
    FUN_0072fb20();
    ppiStack_198 = (int **)0x5a4d4a;
    FUN_00735c50();
    ppiStack_198 = (int **)0x1;
    ppuStack_19c = (undefined **)0x0;
    puStack_1a0 = (undefined *)0x1;
    ppppuStack_1a4 = (undefined1 ****)0x969efc;
    pppppuStack_1a8 = (undefined1 *****)0x5a4d5b;
    FUN_0072fb20();
    pppppuStack_1a8 = (undefined1 *****)0x5a4d62;
    FUN_00735c50();
    pppppuStack_1a8 = (undefined1 *****)0x1;
    ppiStack_1ac = (int **)0x0;
    FUN_0072fb20(0x9712ec,0);
    FUN_00735c50();
    FUN_0072fb20(0x969ef0,1,0,1);
    FUN_00735c50();
    FUN_0072fb20(0x969ee4,1,0,1);
    FUN_00735c50();
    func_0x005a83d0(1);
    uStack_b8 = DAT_009b3c44;
    iVar4 = *(int *)(param_1 + 0x5a0);
    puVar11 = &uStack_b7;
    for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar11 = 0;
      puVar11 = puVar11 + 1;
    }
    *(undefined2 *)puVar11 = 0;
    *(undefined1 *)((int)puVar11 + 2) = 0;
    sprintf(&uStack_b8,0x969edc,iVar4 + 1);
    *(undefined4 *)(param_1 + 0x5a0) = 0xffffffff;
    FUN_005a3e90(&uStack_b8,uStack_50);
LAB_005a5ae3:
    bVar13 = *(int *)(param_1 +
                     (*(int *)(param_1 + 0x65c) + 0x198 + *(int *)(param_1 + 0x658) * 2) * 4) == 0;
    if (bVar13) {
      FUN_0072fb20(0x969f2c,0x9712b4,0);
      FUN_00737400();
      FUN_00741f40();
    }
    else {
      FUN_0072fb20(0x969f2c,0x9712b4,1);
      FUN_00737400();
      FUN_00741f40();
    }
    FUN_0072fb20(0x969f2c,0x95c8e8,!bVar13);
    FUN_00737400();
    FUN_00741f40();
  }
  else {
    ppppiStack_184 = (int ****)0x95b69c;
    ppppiStack_188 = param_2;
    pppppuStack_18c = (undefined1 *****)0x5a4e1a;
    iVar4 = _stricmp();
    if (iVar4 != 0) {
      ppppiStack_184 = (int ****)0x9712c8;
      ppppiStack_188 = param_2;
      pppppuStack_18c = (undefined1 *****)0x5a4f1a;
      iVar4 = _stricmp();
      if (iVar4 == 0) {
        iStack_14c = 1;
        puStack_148 = (undefined1 *)0x1;
        uStack_138 = 1;
        puStack_134 = (undefined *)0x1;
        ppppiStack_184 = (int ****)0x9712d0;
        uStack_150 = 0;
        pppiStack_144 = (int ***)0x0;
        uStack_140 = 0;
        uStack_13c = 3;
        puStack_130 = (undefined *)0x3;
        uStack_12c = (undefined *)0x2;
        uStack_128 = 2;
        ppppiStack_188 = (int ****)0x5a4f73;
        FUN_00737400();
        ppppiStack_188 = (int ****)0x5a4f7a;
        ppppiStack_170 = (int ****)FUN_0074db00();
        ppppiStack_188 = (int ****)0x971378;
        pppppuStack_18c = (undefined1 *****)0x5a4f8a;
        FUN_00737400();
        pppppuStack_18c = (undefined1 *****)0x5a4f93;
        FUN_0074db90();
        pppuVar14 = (undefined1 ***)&iStack_14c;
        ppuVar9 = (undefined **)0x0;
        do {
          if (unaff_EBX == (int ****)*pppuVar14) {
            pppppuStack_18c = (undefined1 *****)((int)ppuVar9 + 0x12d);
            ppuStack_190 = (undefined **)0x5a4fb7;
            ppuStack_190 = (undefined **)FUN_0072ef30();
            ppiStack_194 = (int **)0x5a4fbf;
            FUN_0074d8e0();
            pppuVar14 = (undefined1 ***)&ppiStack_194;
            ppiStack_198 = (int **)&DAT_009b3c44;
            ppuStack_19c = (undefined **)0x5a4fd0;
            func_0x007636b0();
            uStack_18 = 0xffffffff;
            puStack_1a0 = (undefined *)0x5a4fe3;
            ppuStack_19c = ppuVar9;
            iVar4 = FUN_0074daf0();
            puStack_1a0 = (undefined *)(iVar4 + -1);
            ppppuStack_1a4 = (undefined1 ****)0x5a4fec;
            FUN_0074e210();
          }
          ppuVar9 = (undefined **)((int)ppuVar9 + 1);
          pppuVar14 = pppuVar14 + 1;
        } while (ppuVar9 < (undefined **)0x8);
        pppppuStack_18c = (undefined1 *****)aiStack_164[(int)((int)unaff_EBX + 3)];
        ppuStack_190 = (undefined **)0x5a500d;
        FUN_0074db10();
        ppuStack_190 = ppuStack_4;
        ppiStack_194 = (int **)0x971368;
        ppiStack_198 = (int **)0x5a5021;
        FUN_005a4c70();
      }
      else {
        ppppiStack_184 = (int ****)0x971360;
        ppppiStack_188 = param_2;
        pppppuStack_18c = (undefined1 *****)0x5a502e;
        iVar4 = _stricmp();
        if (iVar4 == 0) {
          ppppiStack_184 = (int ****)0x9712d0;
          ppppiStack_188 = (int ****)0x5a5048;
          FUN_00737400();
          ppppiStack_188 = (int ****)0x5a5051;
          iVar4 = FUN_0074db00();
          ppppiStack_188 = (int ****)(iVar4 + -1);
          if ((int)ppppiStack_188 < 0) {
            ppppiStack_188 = (int ****)0x5a505b;
            iVar4 = FUN_0074daf0();
            ppppiStack_188 = (int ****)(iVar4 + -1);
          }
          pppppuStack_18c = (undefined1 *****)0x5a5064;
          FUN_0074db10();
          pppppuStack_18c = (undefined1 *****)param_3;
          ppuStack_190 = (undefined **)0x9712c8;
          ppiStack_194 = (int **)0x5a5071;
          FUN_005a4c70();
        }
        else {
          ppppiStack_184 = (int ****)0x971358;
          ppppiStack_188 = param_2;
          pppppuStack_18c = (undefined1 *****)0x5a507e;
          iVar4 = _stricmp();
          if (iVar4 == 0) {
            ppppiStack_184 = (int ****)0x9712d0;
            ppppiStack_188 = (int ****)0x5a5096;
            FUN_00737400();
            ppppiStack_188 = (int ****)0x5a509f;
            iVar4 = FUN_0074db00();
            ppppiVar12 = (int ****)(iVar4 + 1);
            ppppiStack_188 = (int ****)0x5a50a9;
            iVar4 = FUN_0074daf0();
            if (iVar4 <= (int)ppppiVar12) {
              ppppiVar12 = (int ****)0x0;
            }
            pppppuStack_18c = (undefined1 *****)0x5a50b7;
            ppppiStack_188 = ppppiVar12;
            FUN_0074db10();
            ppuStack_190 = (undefined **)0x9712c8;
            ppiStack_194 = (int **)0x5a50cb;
            pppppuStack_18c = (undefined1 *****)unaff_retaddr;
            FUN_005a4c70();
          }
          else {
            ppppiStack_184 = (int ****)0x971368;
            ppppiStack_188 = param_2;
            pppppuStack_18c = (undefined1 *****)0x5a50d8;
            iVar4 = _stricmp();
            if (iVar4 == 0) {
              ppppiStack_184 = *(int *****)(param_1 + 0x658);
              pppppuStack_18c = (undefined1 *****)apppiStack_60;
              ppppiStack_188 = (int ****)0x969f18;
              ppuStack_190 = (undefined **)0x5a50ff;
              sprintf();
              ppppiStack_184 = apppiStack_60;
              ppppiStack_188 = (int ****)0x5a5111;
              iVar4 = FUN_0072fb20();
              if (iVar4 != 0) {
                ppppiStack_188 = (int ****)0x1;
                pppppuStack_18c = (undefined1 *****)0x0;
                ppiStack_194 = (int **)&puStack_64;
                ppuStack_190 = (undefined **)0x0;
                ppiStack_198 = (int **)0x5a5128;
                FUN_0072fb20();
                ppiStack_198 = (int **)0x5a512f;
                FUN_00735c50();
              }
              ppppiStack_188 = (int ****)0x971378;
              pppppuStack_18c = (undefined1 *****)0x5a5140;
              FUN_00737400();
              ppppiStack_170 = (int ****)&pppppuStack_18c;
              ppuStack_190 = (undefined **)&DAT_009b3c44;
              ppiStack_194 = (int **)0x5a5153;
              pppppuStack_18c = (undefined1 *****)extraout_ECX;
              func_0x007636b0();
              uStack_10 = 0xffffffff;
              ppiStack_194 = (int **)0x5a5165;
              ppiStack_194 = (int **)FUN_0074db00();
              ppiStack_198 = (int **)0x5a516d;
              iVar4 = FUN_0074e140();
              *(int *)(param_1 + 0x658) = iVar4;
              ppiStack_198 = (int **)(iVar4 + 10);
              ppuStack_19c = (undefined **)0x5a517e;
              func_0x005a83d0();
              ppuStack_19c = *(undefined ***)(param_1 + 0x658);
              ppppuStack_1a4 = (undefined1 ****)&puStack_78;
              puStack_1a0 = (undefined *)0x969f18;
              pppppuStack_1a8 = (undefined1 *****)0x5a5194;
              sprintf();
              ppuStack_19c = &puStack_78;
              puStack_1a0 = (undefined *)0x5a51a6;
              iVar4 = FUN_0072fb20();
              if (iVar4 != 0) {
                puStack_1a0 = (undefined *)0x1;
                ppppuStack_1a4 = (undefined1 ****)0x0;
                ppiStack_1ac = (int **)&puStack_7c;
                pppppuStack_1a8 = (undefined1 *****)0x1;
                FUN_0072fb20();
                FUN_00735c50();
              }
              puStack_1a0 = (undefined *)0x971348;
              ppppuStack_1a4 = (undefined1 ****)0x5a51d6;
              FUN_00737400();
              ppppuStack_1a4 = (undefined1 ****)0x5a51df;
              FUN_0074db90();
              if (*(int *)(param_1 + 0x658) != 3) {
                ppppuStack_1a4 = (undefined1 ****)0x141;
                pppppuStack_1a8 = (undefined1 *****)0x5a51fa;
                pppppuStack_1a8 = (undefined1 *****)FUN_0072ef30();
                ppiStack_1ac = (int **)0x5a5202;
                FUN_0074d8e0();
                ppuStack_190 = (undefined **)&ppiStack_1ac;
                ppiStack_1ac = (int **)extraout_ECX_00;
                func_0x007636b0(&DAT_009b3c44);
                uStack_30 = 0xffffffff;
                iVar4 = FUN_0074daf0(0);
                FUN_0074e210(iVar4 + -1);
              }
              if (*(int *)(param_1 + 0x658) != 4) {
                ppppuStack_1a4 = (undefined1 ****)0x142;
                pppppuStack_1a8 = (undefined1 *****)0x5a5244;
                pppppuStack_1a8 = (undefined1 *****)FUN_0072ef30();
                ppiStack_1ac = (int **)0x5a524c;
                FUN_0074d8e0();
                ppuStack_190 = (undefined **)&ppiStack_1ac;
                ppiStack_1ac = (int **)extraout_ECX_01;
                func_0x007636b0(&DAT_009b3c44);
                uStack_30 = 0xffffffff;
                iVar4 = FUN_0074daf0(1);
                FUN_0074e210(iVar4 + -1);
              }
              aiStack_164[0] = 0;
              aiStack_164[1] = 1;
              aiStack_164[2] = 3;
              aiStack_164[3] = 1;
              puStack_154 = (undefined *)0x0;
              uStack_150 = 3;
              iStack_14c = 0;
              puStack_148 = (undefined1 *)0x1;
              ppppuStack_1a4 = (undefined1 ****)aiStack_164[*(int *)(param_1 + 0x658)];
LAB_005a52ac:
              pppppuStack_1a8 = (undefined1 *****)0x5a52b1;
              FUN_0074db10();
              pppppuStack_1a8 = pppppuStack_1c;
              ppiStack_1ac = (int **)0x97133c;
              FUN_005a4c70();
            }
            else {
              ppppiStack_184 = (int ****)0x971330;
              ppppiStack_188 = param_2;
              pppppuStack_18c = (undefined1 *****)0x5a52d2;
              iVar4 = _stricmp();
              if (iVar4 == 0) {
                ppppiStack_184 = (int ****)0x971378;
                ppppiStack_188 = (int ****)0x5a52ec;
                FUN_00737400();
                ppppiStack_188 = (int ****)0x5a52f5;
                iVar4 = FUN_0074db00();
                ppppiStack_188 = (int ****)(iVar4 + -1);
                if ((int)ppppiStack_188 < 0) {
                  ppppiStack_188 = (int ****)0x5a52ff;
                  iVar4 = FUN_0074daf0();
                  ppppiStack_188 = (int ****)(iVar4 + -1);
                }
                pppppuStack_18c = (undefined1 *****)0x5a5308;
                FUN_0074db10();
                pppppuStack_18c = (undefined1 *****)param_3;
                ppuStack_190 = (undefined **)0x971368;
                ppiStack_194 = (int **)0x5a5315;
                FUN_005a4c70();
              }
              else {
                ppppiStack_184 = (int ****)0x971324;
                ppppiStack_188 = param_2;
                pppppuStack_18c = (undefined1 *****)0x5a5322;
                iVar4 = _stricmp();
                if (iVar4 == 0) {
                  ppppiStack_184 = (int ****)0x971378;
                  ppppiStack_188 = (int ****)0x5a533a;
                  FUN_00737400();
                  ppppiStack_188 = (int ****)0x5a5343;
                  iVar4 = FUN_0074db00();
                  ppppiVar12 = (int ****)(iVar4 + 1);
                  ppppiStack_188 = (int ****)0x5a534d;
                  iVar4 = FUN_0074daf0();
                  if (iVar4 <= (int)ppppiVar12) {
                    ppppiVar12 = (int ****)0x0;
                  }
                  pppppuStack_18c = (undefined1 *****)0x5a535b;
                  ppppiStack_188 = ppppiVar12;
                  FUN_0074db10();
                  ppuStack_190 = (undefined **)0x971368;
                  ppiStack_194 = (int **)0x5a536f;
                  pppppuStack_18c = (undefined1 *****)unaff_retaddr;
                  FUN_005a4c70();
                }
                else {
                  ppppiStack_184 = (int ****)0x97133c;
                  ppppiStack_188 = param_2;
                  pppppuStack_18c = (undefined1 *****)0x5a537c;
                  iVar4 = _stricmp();
                  if (iVar4 == 0) {
                    ppppiStack_184 = (int ****)0x971348;
                    ppppiStack_188 = (int ****)0x5a5398;
                    FUN_00737400();
                    puStack_16c = (undefined1 *)&ppppiStack_188;
                    pppppuStack_18c = (undefined1 *****)&DAT_009b3c44;
                    ppuStack_190 = (undefined **)0x5a53ab;
                    ppppiStack_188 = extraout_ECX_02;
                    func_0x007636b0();
                    uStack_c = 0xffffffff;
                    ppuStack_190 = (undefined **)0x5a53bc;
                    ppuStack_190 = (undefined **)FUN_0074db00();
                    ppiStack_194 = (int **)0x5a53c4;
                    iVar4 = FUN_0074e140();
                    *(int *)(param_1 + 0x65c) = iVar4;
                    if (*(char *)(iVar4 + 0x971008 + *(int *)(param_1 + 0x658) * 2) != '\0') {
                      ppiStack_194 = (int **)0x7b4;
                      ppiStack_198 = (int **)0x5a53e7;
                      iVar4 = func_0x00763250();
                      uStack_14 = 6;
                      if (iVar4 == 0) {
                        uVar6 = 0;
                      }
                      else {
                        ppiStack_194 = (int **)0x0;
                        ppiStack_198 = (int **)0x5a5405;
                        uVar6 = func_0x0046f840();
                      }
                      uStack_14 = 0xffffffff;
                      *(undefined4 *)
                       (param_1 +
                       (*(int *)(param_1 + 0x65c) + 0x198 + *(int *)(param_1 + 0x658) * 2) * 4) =
                           uVar6;
                      if (*(int *)(param_1 +
                                  (*(int *)(param_1 + 0x65c) + 0x198 + *(int *)(param_1 + 0x658) * 2
                                  ) * 4) == 0) {
                        ppiStack_194 = (int **)0x97108c;
                        ppiStack_198 = (int **)0x37a;
                        ppuStack_19c = (undefined **)0x5a544d;
                        uVar7 = func_0x007396e0();
                        goto LAB_005a5b62;
                      }
                      uStack_9c = 0;
                      puStack_98 = (undefined *)0x0;
                      uStack_94 = 0;
                      puStack_a0 = &UNK_008d6c34;
                      uStack_14 = 7;
                      uStack_150 = 0;
                      iStack_14c = 0;
                      puStack_148 = (undefined1 *)0x0;
                      puStack_154 = &UNK_008d6c34;
                      puStack_16c = (undefined1 *)0x0;
                      fStack_168 = 0.0;
                      aiStack_164[0] = 0;
                      ppppiStack_170 = (int ****)&UNK_008d6bfc;
                      uStack_8c = 0;
                      puStack_88 = (undefined *)0x0;
                      uStack_84 = 0;
                      puStack_90 = &UNK_008d6c34;
                      puStack_7c = (undefined1 *)0x0;
                      puStack_78 = (undefined *)0x0;
                      uStack_74 = 0;
                      puStack_80 = &UNK_008d6c34;
                      uStack_12c = &UNK_008d6c18;
                      uStack_128 = 0xffffffff;
                      uStack_124 = (undefined *)((uint)uStack_124._3_1_ << 0x18);
                      puStack_120 = (undefined *)0x1;
                      ppuStack_11c = (undefined1 **)0x0;
                      puStack_114 = (undefined *)0x0;
                      puStack_110 = (undefined *)0x0;
                      ppiStack_10c = (int **)0x0;
                      puStack_118 = &UNK_008d6c34;
                      puStack_104 = (undefined *)0x0;
                      ppppuStack_100 = (undefined1 ****)0x0;
                      ppppuStack_fc = (undefined1 ****)0x0;
                      ppiStack_108 = (int **)&UNK_008d6c34;
                      ppiStack_194 = (int **)0x5a554f;
                      func_0x004328e0();
                      ppiStack_194 = (int **)&puStack_16c;
                      uStack_14 = CONCAT31(uStack_14._1_3_,0xf);
                      ppiStack_198 = (int **)0x5a5568;
                      func_0x0043a460();
                      ppiStack_198 = (int **)&uStack_a4;
                      ppppuStack_fc = (undefined1 ****)&UNK_008d6bfc;
                      uStack_ec = 0;
                      uStack_e8 = 0;
                      uStack_e4 = 0;
                      puStack_e0 = (undefined *)0x0;
                      uStack_dc = 0;
                      uStack_d8 = 0;
                      puStack_d4 = (undefined *)0x0;
                      ppuStack_d0 = (undefined1 **)0x0;
                      uStack_c8 = 0;
                      puStack_c4 = (undefined *)0x0;
                      uStack_c0 = 0;
                      ppuStack_cc = (undefined1 **)&UNK_008d6c34;
                      ppuStack_19c = (undefined **)0x5a55e3;
                      func_0x00432800();
                      uStack_b0 = 0;
                      uStack_ac = 0;
                      puStack_134 = &UNK_008d6be0;
                      ppuStack_19c = (undefined **)0x0;
                      puStack_88 = &UNK_008d6c34;
                      puStack_1a0 = (undefined *)0x5a5609;
                      free();
                      puStack_1a0 = (undefined *)0x0;
                      puStack_98 = &UNK_008d6c34;
                      ppppuStack_1a4 = (undefined1 ****)0x5a5613;
                      free();
                      pppppuStack_1c._0_1_ = 0x17;
                      ppppiStack_184 = ppppiStack_170;
                      ppppiStack_188 = unaff_EBX;
                      if (unaff_EBX != ppppiStack_170) {
                        do {
                          ppuStack_19c = (undefined **)0x0;
                          puStack_1a0 = (undefined *)0x5a5644;
                          (*(code *)(*ppppiStack_188)[2])();
                          ppppiStack_188 = ppppiStack_188 + 0xe;
                        } while (ppppiStack_188 != ppppiStack_184);
                      }
                      pppppuStack_1c._0_1_ = 0x18;
                      if (unaff_EBX != (int ****)0x0) {
                        ppppiStack_184 = (int ****)(puStack_16c + -(int)unaff_EBX);
                        ppuStack_19c = (undefined **)(((int)ppppiStack_184 / 0x38) * 0x38);
                        ppppuStack_1a4 = (undefined1 ****)0x5a5699;
                        func_0x00431b00();
                      }
                      ppuStack_19c = (undefined **)0x0;
                      puStack_1a0 = (undefined *)0x5a56a7;
                      free();
                      pppppuStack_1c = (undefined1 *****)CONCAT31(pppppuStack_1c._1_3_,0x11);
                      puStack_1a0 = (undefined *)uStack_a4;
                      puStack_a8 = &UNK_008d6c34;
                      ppppuStack_1a4 = (undefined1 ****)0x5a56c0;
                      free();
                      puVar2 = uStack_12c;
                      uStack_12c = (undefined *)
                                   CONCAT31(uStack_12c._1_3_,*(undefined1 *)(param_1 + 0x65c));
                      uVar6 = uStack_12c;
                      uStack_12c._3_1_ = SUB41(puVar2,3);
                      uStack_12c._0_3_ = CONCAT12(*(undefined1 *)(param_1 + 0x658),(short)uVar6);
                      ppuStack_19c = &puStack_134;
                      puStack_1a0 = (undefined *)0x5a56f7;
                      cVar3 = func_0x0046f8f0();
                      if (cVar3 == '\0') {
                        puStack_1a0 = (undefined *)0x97108c;
                        ppppuStack_1a4 = (undefined1 ****)0x383;
                        pppppuStack_1a8 = (undefined1 *****)0x5a570e;
                        func_0x007396e0();
                        uStack_20 = 0x19;
                        puStack_c4 = &UNK_008d6c34;
                        pppppuStack_1a8 = (undefined1 *****)uStack_c0;
                        ppiStack_1ac = (int **)0x5a572e;
                        free();
                        puStack_d4 = &UNK_008d6c34;
                        ppiStack_1ac = (int **)ppuStack_d0;
                        free();
                        ppppiStack_184 = (int ****)&puStack_104;
                        pppppuStack_18c = &ppppuStack_100;
                        uStack_20._0_1_ = 0x1d;
                        ppppiStack_188 = (int ****)ppppuStack_fc;
                        ppppuVar10 = ppppuStack_100;
                        if (ppppuStack_100 != ppppuStack_fc) {
                          do {
                            puStack_1a0 = (undefined *)0x0;
                            ppppuStack_1a4 = (undefined1 ****)0x5a577e;
                            (*(code *)(*ppppuVar10)[2])();
                            ppppuVar10 = ppppuVar10 + 0xe;
                          } while ((int ****)ppppuVar10 != ppppiStack_188);
                        }
                        uStack_20 = CONCAT31(uStack_20._1_3_,0x1e);
                        if (ppppuStack_100 != (undefined1 ****)0x0) {
                          puStack_1a0 = (undefined *)((iStack_f8 - (int)ppppuStack_100) / 0x38);
                          ppppuStack_1a4 = ppppuStack_100;
                          pppppuStack_1a8 = (undefined1 *****)0x5a57c6;
                          func_0x0043a5e0();
                        }
                        puStack_104 = &UNK_008d6c3c;
                        puStack_1a0 = puStack_110;
                        puStack_114 = &UNK_008d6c34;
                        ppppuStack_1a4 = (undefined1 ****)0x5a57e2;
                        free();
                        uStack_124 = &UNK_008d6c34;
                        ppppuStack_1a4 = (undefined1 ****)puStack_120;
                        pppppuStack_1a8 = (undefined1 *****)0x5a57f0;
                        free();
                        uVar7 = unaff_ESI >> 0x18;
                        goto LAB_005a5b62;
                      }
                      puStack_1a0 = (undefined *)0x5a5817;
                      func_0x0047a460();
                      puStack_1a0 = (undefined *)
                                    (param_1 + (*(int *)(param_1 + 0x658) * 3 + 0x147) * 4);
                      ppppuStack_1a4 = (undefined1 ****)0x5a583d;
                      (**(code **)(**(int **)(param_1 +
                                             (*(int *)(param_1 + 0x65c) + 0x198 +
                                             *(int *)(param_1 + 0x658) * 2) * 4) + 0x10))();
                      iVar1 = *(int *)(param_1 + 0x658);
                      ppppuStack_1a4 = (undefined1 ****)&DAT_009b4340;
                      iVar4 = iVar1 * 3 + 0x60;
                      iVar8 = iVar1 * 3 + 0x147;
                      fStack_168 = *(float *)(param_1 + 8 + iVar4 * 4) -
                                   *(float *)(param_1 + 8 + iVar8 * 4);
                      ppppiStack_170 =
                           (int ****)
                           (*(float *)(param_1 + iVar4 * 4) - *(float *)(param_1 + iVar8 * 4));
                      puStack_16c = (undefined1 *)0x0;
                      pppppuStack_1a8 = (undefined1 *****)&ppppiStack_170;
                      ppiStack_1ac = (int **)0x5a5890;
                      (**(code **)(**(int **)(param_1 +
                                             (*(int *)(param_1 + 0x65c) + 0x198 + iVar1 * 2) * 4) +
                                  0x14))();
                      ppiStack_1ac = (int **)0x5a58ab;
                      func_0x0046fcd0();
                      uStack_2c = 0x1f;
                      ppuStack_d0 = (undefined1 **)&UNK_008d6c34;
                      ppiStack_1ac = (int **)ppuStack_cc;
                      free();
                      puStack_e0 = &UNK_008d6c34;
                      free(uStack_dc);
                      ppuStack_190 = &puStack_110;
                      apppiStack_60[0] = &ppiStack_10c;
                      uStack_2c._0_1_ = 0x23;
                      ppiStack_194 = ppiStack_108;
                      ppiStack_198 = ppiStack_10c;
                      if (ppiStack_10c != ppiStack_108) {
                        do {
                          ppiStack_1ac = (int **)0x0;
                          (*(code *)(*ppiStack_198)[2])();
                          ppiStack_198 = ppiStack_198 + 0xe;
                        } while (ppiStack_198 != ppiStack_194);
                      }
                      uStack_2c = CONCAT31(uStack_2c._1_3_,0x24);
                      if (ppiStack_10c != (int **)0x0) {
                        ppiStack_194 = (int **)(puStack_104 + -(int)ppiStack_10c);
                        ppiStack_1ac = (int **)(((int)ppiStack_194 / 0x38) * 0x38);
                        if (ppiStack_1ac < (undefined1 **)0x81) {
                          func_0x008876b0(ppiStack_10c);
                        }
                        else {
                          ppiStack_1ac = ppiStack_10c;
                          func_0x00763260();
                        }
                      }
                      puStack_110 = &UNK_008d6c3c;
                      ppiStack_1ac = (int **)ppuStack_11c;
                      puStack_120 = &UNK_008d6c34;
                      free();
                      puStack_130 = &UNK_008d6c34;
                      free(uStack_12c);
                      uStack_14 = 0xffffffff;
                    }
                    ppiStack_194 = (int **)0x5a59cf;
                    func_0x005a8750();
                  }
                  else {
                    ppppiStack_184 = (int ****)0x97131c;
                    ppppiStack_188 = param_2;
                    pppppuStack_18c = (undefined1 *****)0x5a59dc;
                    iVar4 = _stricmp();
                    if (iVar4 == 0) {
                      ppppiStack_184 = (int ****)0x971348;
                      ppppiStack_188 = (int ****)0x5a59f6;
                      FUN_00737400();
                      ppppiStack_188 = (int ****)0x5a59ff;
                      iVar4 = FUN_0074db00();
                      ppppiStack_188 = (int ****)(iVar4 + -1);
                      if ((int)ppppiStack_188 < 0) {
                        ppppiStack_188 = (int ****)0x5a5a09;
                        iVar4 = FUN_0074daf0();
                        ppppiStack_188 = (int ****)(iVar4 + -1);
                      }
                      pppppuStack_18c = (undefined1 *****)0x5a5a12;
                      FUN_0074db10();
                      pppppuStack_18c = (undefined1 *****)param_3;
                      ppuStack_190 = (undefined **)0x97133c;
                      ppiStack_194 = (int **)0x5a5a1f;
                      FUN_005a4c70();
                    }
                    else {
                      ppppiStack_184 = (int ****)0x971314;
                      ppppiStack_188 = param_2;
                      pppppuStack_18c = (undefined1 *****)0x5a5a2c;
                      iVar4 = _stricmp();
                      if (iVar4 == 0) {
                        ppppiStack_184 = (int ****)0x971348;
                        ppppiStack_188 = (int ****)0x5a5a44;
                        FUN_00737400();
                        ppppiStack_188 = (int ****)0x5a5a4d;
                        iVar4 = FUN_0074db00();
                        ppppiStack_188 = (int ****)0x5a5a57;
                        iVar8 = FUN_0074daf0();
                        ppppuStack_1a4 = (undefined1 ****)(iVar4 + 1);
                        if (iVar8 <= iVar4 + 1) {
                          ppppuStack_1a4 = (undefined1 ****)0x0;
                        }
                        goto LAB_005a52ac;
                      }
                      ppppiStack_184 = (int ****)0x971304;
                      ppppiStack_188 = param_2;
                      pppppuStack_18c = (undefined1 *****)0x5a5a6d;
                      iVar4 = _stricmp();
                      if (iVar4 == 0) {
                        FUN_0072fb20(0x969f2c,0,0,1);
                        FUN_00735c50();
                        FUN_0072fb20(0x969f08,1,0,1);
                        FUN_00735c50();
                        sprintf((int)&uStack_b7 + 3,0x969f18,*(undefined4 *)(param_1 + 0x658));
                        FUN_0072fb20((int)&uStack_b7 + 3,0,0,1);
                        FUN_00735c50();
                        func_0x005a97c0(1);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      goto LAB_005a5ae3;
    }
    if (*(int *)(param_1 + (*(int *)(param_1 + 0x65c) + 0x198 + *(int *)(param_1 + 0x658) * 2) * 4)
        == 0) {
      ppppiStack_184 = (int ****)0x0;
      ppppiStack_188 = (int ****)0xa0ffffff;
      pppppuStack_18c = (undefined1 *****)0x0;
      ppuStack_190 = (undefined **)0xd2;
      ppiStack_194 = (int **)0x5a4e50;
      ppiStack_194 = (int **)FUN_0072ef30();
      ppiStack_198 = (int **)&DAT_009b3c44;
      ppuStack_19c = (undefined **)0x5a4e5d;
      FUN_00730110();
    }
    else {
      ppppiStack_184 = (int ****)0x97103c;
      ppppiStack_188 = (int ****)0x969f2c;
      pppppuStack_18c = (undefined1 *****)0x5a4e73;
      FUN_0072fb20();
      pppppuStack_18c = (undefined1 *****)0x5a4e7a;
      piVar5 = (int *)FUN_00737400();
      pppppuStack_18c = (undefined1 *****)0x5a4e81;
      pppppuStack_18c = (undefined1 *****)(**(code **)(*piVar5 + 0x30))();
      ppuStack_190 = (undefined **)0x5a4e8b;
      FUN_00765050();
      uStack_10 = 0;
      if (0 < *(int *)(unaff_ESI - 8)) {
        ppuStack_190 = (undefined **)(*(int *)(param_1 + 0x8b0) + -0xc);
        ppiStack_194 = (int **)0x5a4ee3;
        func_0x00764e30();
        *(undefined4 *)(param_1 + 0x8b0) = _DAT_00985a98;
        ppuStack_190 = (undefined **)0x5a4ef9;
        func_0x005a9d80();
        uStack_10 = 0xffffffff;
        ppuStack_190 = (undefined **)0x5a4f0d;
        FUN_00765200();
        goto LAB_005a5ae3;
      }
      ppuStack_190 = (undefined **)0x0;
      ppiStack_194 = (int **)0xa0ffffff;
      ppiStack_198 = (int **)0x0;
      ppuStack_19c = (undefined **)0xcf;
      puStack_1a0 = (undefined *)0x5a4eae;
      puStack_1a0 = (undefined *)FUN_0072ef30();
      ppppuStack_1a4 = (undefined1 ****)&DAT_009b3c44;
      pppppuStack_1a8 = (undefined1 *****)0x5a4ebb;
      FUN_00730110();
      uStack_28 = 0xffffffff;
      pppppuStack_1a8 = (undefined1 *****)0x5a4ecf;
      FUN_00765200();
    }
  }
  uVar7 = 1;
LAB_005a5b62:
  *unaff_FS_OFFSET = uStack_24;
  return uVar7;
}


/* ==================================================================== */
/* Address: 0x005a5b80 | Classified: elementclient::Win_PwdProtect@0x5a5b80 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005a5b80(undefined4 param_1)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  undefined *puVar8;
  undefined1 auStack_144 [3];
  char cStack_141;
  undefined1 auStack_140 [44];
  undefined1 auStack_114 [4];
  undefined1 auStack_110 [240];
  undefined1 uStack_20;
  undefined4 uStack_1c;
  uint uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008b75ac;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uVar3 = FUN_007359b0(0x971168);
  iVar4 = _stricmp(uVar3);
  cStack_141 = iVar4 == 0;
  iVar4 = _stricmp(param_1,0x95ef38);
  cVar2 = (char)((uint)unaff_EBP >> 0x18);
  if (iVar4 == 0) {
    piVar5 = (int *)FUN_00737400(0x9713c0);
    (**(code **)(*piVar5 + 0x34))(0x9b3c40);
    if (cVar2 != '\0') {
      piVar5 = (int *)FUN_00737400(0x9713b8);
      (**(code **)(*piVar5 + 0x34))(0x9b3c40);
      piVar5 = (int *)FUN_00737400(0x9713b0);
      (**(code **)(*piVar5 + 0x34))(0x9b3c40);
    }
    uVar3 = FUN_00737400(0x9713c0);
    FUN_007373a0(uVar3);
    goto LAB_005a5eed;
  }
  iVar4 = _stricmp(param_1,0x95b69c);
  if (iVar4 == 0) {
    if (*(char *)(*(int *)(_DAT_009b3eec + 0x20) + 0x130) != '\0') {
      if (cStack_141 == '\0') {
        piVar5 = (int *)FUN_00737400(0x9713c0);
        uVar3 = (**(code **)(*piVar5 + 0x30))();
        iVar4 = _wtoi(uVar3);
      }
      else {
        piVar5 = (int *)FUN_00737400(0x9713c0);
        uVar3 = (**(code **)(*piVar5 + 0x30))();
        iVar6 = _wtoi(uVar3);
        piVar5 = (int *)FUN_00737400(0x9713b8);
        uVar3 = (**(code **)(*piVar5 + 0x30))();
        iVar7 = _wtoi(uVar3);
        piVar5 = (int *)FUN_00737400(0x9713b0);
        uVar3 = (**(code **)(*piVar5 + 0x30))();
        iVar4 = _wtoi(uVar3);
        iVar4 = iVar4 + (iVar7 + iVar6 * 100) * 100;
      }
      func_0x005ee9c0(iVar4);
      FUN_00735c50(0,0,1);
      FUN_0072fb20(0x971194,1,0,1);
      FUN_00735c50();
      goto LAB_005a5eed;
    }
    FUN_00735c50(0,0,1);
    FUN_0072fb20(0x96e344,1,0,1);
    FUN_00735c50();
    uVar3 = FUN_0072ef30(0xe1,0,0xa0ffffff,0);
    puVar8 = &DAT_009b3c44;
  }
  else {
    iVar4 = _stricmp(param_1,0x95cab0);
    if (iVar4 == 0) {
      func_0x0076c660();
      uStack_4 = 0;
      uVar3 = func_0x0076eb20();
      sprintf(auStack_110,0x971070,uVar3);
      func_0x007636b0(&DAT_009b3c44);
      puStack_8 = (undefined *)CONCAT31(puStack_8._1_3_,1);
      cVar1 = func_0x0076c730(auStack_114);
      if (cVar1 != '\0') {
        if (cVar2 == '\0') {
          uVar3 = func_0x0076cf90(auStack_140,0x97105c,0x9713a0,&DAT_009b3c44);
          uStack_1c = CONCAT31(uStack_1c._1_3_,3);
          func_0x00763940(uVar3);
        }
        else {
          uVar3 = func_0x0076cf90(auStack_144,0x97105c,0x9713a8,&DAT_009b3c44);
          uStack_1c = CONCAT31(uStack_1c._1_3_,2);
          func_0x00763940(uVar3);
        }
        uStack_20 = 1;
        func_0x007637f0();
        func_0x0076c930();
      }
      cVar2 = func_0x00763c30(&DAT_009b3c44);
      if (cVar2 == '\0') {
        ShellExecuteA(0,0x952318,unaff_EBP,0,0,1);
      }
      uStack_10 = uStack_10 & 0xffffff00;
      func_0x007637f0();
      uStack_10 = 0xffffffff;
      func_0x0076c6b0();
      goto LAB_005a5eed;
    }
    iVar4 = _stricmp(param_1,0x95baec);
    if (iVar4 != 0) goto LAB_005a5eed;
    uVar3 = FUN_0072ef30(0xe2,4,0xa0ffffff,0);
    puVar8 = (undefined *)0x97138c;
  }
  FUN_00730110(puVar8,uVar3);
LAB_005a5eed:
  *unaff_FS_OFFSET = uStack_1c;
  return 1;
}


/* ==================================================================== */
/* Address: 0x005a5f10 | Classified: elementclient::IDCANCEL@0x5a5f10 */
/* ==================================================================== */

undefined4 FUN_005a5f10(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  iVar1 = _stricmp(param_1,0x95baec);
  if (iVar1 == 0) {
    FUN_00735c50(0,0,1);
    return 1;
  }
  iVar1 = _stricmp(param_1,0x95b69c);
  if (iVar1 == 0) {
    piVar2 = (int *)FUN_00737400(0x9713c8);
    uVar3 = (**(code **)(*piVar2 + 0x30))();
    FUN_00765230(uVar3);
    FUN_00735c50(0,0,1);
    func_0x005a9d80();
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x005a5fa0 | Classified: CECLoginUIMan::vfunc_slot_6 */
/* ==================================================================== */

void __thiscall FUN_005a5fa0(int param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = FUN_007359b0(0x971294);
  iVar3 = _stricmp(uVar2);
  if ((iVar3 == 0) && (param_2 == 6)) {
    func_0x005d4910(*(undefined4 *)
                     (*(int *)(param_1 + 0x638) + 4 + *(int *)(param_1 + 0x5a0) * 0x8c));
    FUN_0072fcf0(6,param_3);
    return;
  }
  uVar2 = FUN_007359b0(0x97138c);
  iVar3 = _stricmp(uVar2);
  if ((iVar3 == 0) && (param_2 == 6)) {
    FUN_0072fb20(0x971168,0,0,1);
    FUN_00735c50();
    FUN_0072fb20(0x971158,0,0,1);
    FUN_00735c50();
    FUN_0072fb20(0x96e344,1,0,1);
    FUN_00735c50();
    func_0x005cf710();
    FUN_0072fcf0(6,param_3);
    return;
  }
  FUN_0072fb20(0x96e344);
  cVar1 = FUN_00735df0();
  if (cVar1 != '\0') {
    FUN_0072fb20(0x96e344,1,0,1);
    FUN_00735c50();
  }
  FUN_0072fcf0(param_2,param_3);
  return;
}


/* ==================================================================== */
/* Address: 0x005a6460 | Classified: elementclient::Win_Login@0x5a6460 */
/* ==================================================================== */

undefined4 FUN_005a6460(void)

{
  FUN_0072fb20(0x96e344,0,0,1);
  FUN_00735c50();
  FUN_0072fb20(0x971194,0,0,1);
  FUN_00735c50();
  FUN_0072fb20(0x969efc,1,0,1);
  FUN_00735c50();
  FUN_0072fb20(0x9712ec,0,0,1);
  FUN_00735c50();
  FUN_0072fb20(0x969ef0,1,0,1);
  FUN_00735c50();
  FUN_0072fb20(0x969ee4,1,0,1);
  FUN_00735c50();
  FUN_0072fb20(0x969ef0,0x967538,0);
  FUN_00737400();
  FUN_00741f40();
  FUN_0072fb20(0x969efc,0x971258,0);
  FUN_00737400();
  FUN_00741f40();
  FUN_0072fb20(0x969efc,0x95e158,0);
  FUN_00737400();
  FUN_00741f40();
  FUN_0072fb20(0x969efc,0x971270,0);
  FUN_00737400();
  FUN_00741f40();
  FUN_0072fb20(0x969efc,0x971264,0);
  FUN_00737400();
  FUN_00741f40();
  return 1;
}


/* ==================================================================== */
/* Address: 0x005a65a0 | Classified: elementclient::Win_Select@0x5a65a0 */
/* ==================================================================== */

undefined4 __fastcall FUN_005a65a0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined1 *puStack_7c;
  undefined4 uStack_78;
  undefined1 *puStack_74;
  undefined4 uStack_70;
  undefined1 *puStack_6c;
  undefined4 uStack_68;
  undefined1 auStack_54 [84];
  
  uStack_68 = 0x969efc;
  puStack_6c = (undefined1 *)0x5a65b3;
  uVar2 = FUN_0072fb20();
  piVar5 = (int *)(param_1 + 0x660);
  iVar4 = 8;
  do {
    iVar3 = 2;
    do {
      if ((int *)*piVar5 != (int *)0x0) {
        puStack_6c = (undefined1 *)0x5a65d2;
        (**(code **)(*(int *)*piVar5 + 0x40))();
        if ((undefined4 *)*piVar5 != (undefined4 *)0x0) {
          puStack_6c = (undefined1 *)0x1;
          uStack_70 = 0x5a65de;
          (*(code *)**(undefined4 **)*piVar5)();
        }
        *piVar5 = 0;
      }
      piVar5 = piVar5 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  puStack_6c = *(undefined1 **)(param_1 + 0x658);
  puStack_74 = auStack_54;
  uStack_70 = 0x969f18;
  uStack_78 = 0x5a6606;
  sprintf();
  puStack_6c = auStack_54;
  uStack_70 = 0x5a6615;
  iVar4 = FUN_0072fb20();
  if (iVar4 != 0) {
    uStack_70 = 1;
    puStack_74 = (undefined1 *)0x0;
    puStack_7c = &stack0xffffffa8;
    uStack_78 = 0;
    uStack_80 = 0x5a662b;
    FUN_0072fb20();
    uStack_80 = 0x5a6632;
    FUN_00735c50();
  }
  uStack_70 = 1;
  puStack_74 = (undefined1 *)0x0;
  uStack_78 = 0;
  puStack_7c = (undefined1 *)0x969f2c;
  uStack_80 = 0x5a6644;
  FUN_0072fb20();
  uStack_80 = 0x5a664b;
  FUN_00735c50();
  uStack_80 = 1;
  uStack_84 = 0;
  uStack_88 = 1;
  uStack_8c = 0x969efc;
  uStack_90 = 0x5a665d;
  FUN_0072fb20();
  uStack_90 = 0x5a6664;
  FUN_00735c50();
  uStack_90 = 1;
  FUN_0072fb20(0x9712ec,0,0);
  FUN_00735c50();
  FUN_0072fb20(0x969ef0,1,0,1);
  FUN_00735c50();
  uVar6 = 0x969ee4;
  FUN_0072fb20(0x969ee4,1,0,1);
  FUN_00735c50();
  func_0x005a83d0(1);
  cVar1 = FUN_005a6750(uVar2);
  if (cVar1 == '\0') {
    uVar2 = func_0x007396e0(0x4b4,0x97108c);
    return uVar2;
  }
  FUN_00737400(0x95e158,*(uint *)(param_1 + 0x644) < 8);
  FUN_00741f40();
  func_0x005a8e20();
  sprintf(&uStack_90,0x969edc,*(undefined4 *)(param_1 + 0x644));
  FUN_005a3e90(&uStack_90,uVar6);
  func_0x005a8750();
  return 1;
}


/* ==================================================================== */
/* Address: 0x005a6750 | Classified: elementclient::Win_Select@0x5a6750 */
/* ==================================================================== */

undefined4 __thiscall FUN_005a6750(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  char *pcVar12;
  uint uVar13;
  char *pcVar14;
  undefined4 uStack_27;
  undefined4 uStack_c;
  
  if (param_2 != 0) {
    func_0x005aa4a0(param_2);
    uVar13 = *(uint *)(param_1 + 0x654);
    if (uVar13 == *(uint *)(param_1 + 0x650)) {
      if (uVar13 + 1 < 5) {
        iVar9 = 5;
      }
      else {
        iVar9 = uVar13 + 3 + (uVar13 >> 1);
      }
      puVar3 = (undefined4 *)func_0x00763250(iVar9 * 4);
      puVar7 = *(undefined4 **)(param_1 + 0x648);
      uVar13 = 0;
      puVar5 = puVar3;
      if (*(int *)(param_1 + 0x654) != 0) {
        do {
          if (puVar5 != (undefined4 *)0x0) {
            uVar2 = *puVar7;
            puVar7 = puVar7 + 1;
            *puVar5 = uVar2;
          }
          uVar13 = uVar13 + 1;
          puVar5 = puVar5 + 1;
        } while (uVar13 < *(uint *)(param_1 + 0x654));
      }
      if (*(int *)(param_1 + 0x648) != 0) {
        func_0x00763260(*(int *)(param_1 + 0x648));
      }
      *(int *)(param_1 + 0x650) = iVar9;
      *(undefined4 **)(param_1 + 0x648) = puVar3;
      *(undefined4 **)(param_1 + 0x64c) = puVar3 + *(int *)(param_1 + 0x654);
    }
    if (*(undefined4 **)(param_1 + 0x64c) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0x64c) = 0;
    }
    *(int *)(param_1 + 0x654) = *(int *)(param_1 + 0x654) + 1;
    *(int *)(param_1 + 0x64c) = *(int *)(param_1 + 0x64c) + 4;
    return 1;
  }
  puVar7 = &uStack_27;
  for (iVar9 = 9; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)puVar7 = 0;
  iVar10 = -1;
  *(undefined1 *)((int)puVar7 + 2) = 0;
  iVar11 = 0;
  FUN_0072fb20(0x969efc);
  FUN_0072fb20(0x969efc,0x95e158,*(uint *)(param_1 + 0x644) < 8);
  FUN_00737400();
  FUN_00741f40();
  func_0x005a8e20();
  iVar9 = *(int *)(param_1 + 0x644);
  iVar4 = 0;
  if (0 < iVar9) {
    piVar8 = (int *)(*(int *)(param_1 + 0x638) + 0x50);
    do {
      if (iVar11 < *piVar8) {
        iVar10 = iVar4;
        iVar11 = *piVar8;
      }
      iVar4 = iVar4 + 1;
      piVar8 = piVar8 + 0x23;
    } while (iVar4 < iVar9);
    if (-1 < iVar10) {
      sprintf(&stack0xffffffc8,0x969edc,iVar10 + 1);
      goto LAB_005a691c;
    }
  }
  if (iVar9 != 0) {
    uVar13 = 0xffffffff;
    pcVar12 = (char *)0x9713dc;
    do {
      pcVar14 = pcVar12;
      if (uVar13 == 0) break;
      uVar13 = uVar13 - 1;
      pcVar14 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar14;
    } while (cVar1 != '\0');
    uVar13 = ~uVar13;
    pcVar12 = pcVar14 + -uVar13;
    pcVar14 = &stack0xffffffc8;
    for (uVar6 = uVar13 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar14 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar14 = pcVar14 + 4;
    }
    for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
      *pcVar14 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar14 = pcVar14 + 1;
    }
  }
LAB_005a691c:
  iVar9 = -1;
  *(undefined4 *)(param_1 + 0x104) = 1;
  pcVar12 = &stack0xffffffc8;
  do {
    if (iVar9 == 0) break;
    iVar9 = iVar9 + -1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar1 != '\0');
  if (iVar9 != -2) {
    FUN_005a3e90(&stack0xffffffc8,uStack_c);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x005a6960 | Classified: elementclient::Btn_Game@0x5a6960 */
/* ==================================================================== */

undefined4 __thiscall FUN_005a6960(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_2 != 0) {
    uVar3 = FUN_0072ef30(0xd0,0,0xa0ffffff,0);
    FUN_00730110(&DAT_009b3c44,uVar3);
    return 1;
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x644)) {
    piVar2 = (int *)(*(int *)(param_1 + 0x638) + 4);
    do {
      if (param_3 == *piVar2) {
        FUN_0072fb20(0x969ef0,0x967538,0);
        FUN_00737400();
        FUN_00741f40();
        FUN_0072fb20(0x969efc,0x971270,0);
        FUN_00737400();
        FUN_00741f40();
        FUN_0072fb20(0x969efc,0x971258,0);
        FUN_00737400();
        FUN_00741f40();
        FUN_0072fb20(0x969efc,0x971264,1);
        FUN_00737400();
        FUN_00741f40();
        *(undefined1 *)(*(int *)(param_1 + 0x638) + 0x44 + iVar4 * 0x8c) = 3;
        iVar1 = *(int *)(param_1 + 0x638);
        uVar3 = time(0);
        *(undefined4 *)(iVar1 + iVar4 * 0x8c + 0x48) = uVar3;
        func_0x0046fd10();
        break;
      }
      iVar4 = iVar4 + 1;
      piVar2 = piVar2 + 0x23;
    } while (iVar4 < *(int *)(param_1 + 0x644));
  }
  uVar3 = FUN_0072ef30(0xd1,0,0xa0ffffff,0);
  FUN_00730110(&DAT_009b3c44,uVar3);
  func_0x005a8e20();
  func_0x005a8750();
  return 1;
}


/* ==================================================================== */
/* Address: 0x005a6ad0 | Classified: elementclient::Btn_Game@0x5a6ad0 */
/* ==================================================================== */

undefined4 __thiscall FUN_005a6ad0(int param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  if (param_2 != 0) {
    uVar5 = FUN_0072ef30(0xd3,0,0xa0ffffff,0);
    FUN_00730110(&DAT_009b3c44,uVar5);
    return 1;
  }
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 0x644)) {
    piVar3 = (int *)(*(int *)(param_1 + 0x638) + 4);
    do {
      if (param_3 == *piVar3) {
        FUN_0072fb20(0x969ef0,0x967538,1);
        FUN_00737400();
        FUN_00741f40();
        cVar2 = func_0x0047f1b0(1);
        if ((cVar2 == '\0') &&
           (iVar1 = *(int *)(param_1 + 0x638), iVar4 = time(0),
           iVar4 - *(int *)(iVar1 + iVar6 * 0x8c + 0x4c) < 0x2a300)) {
          uVar5 = 1;
        }
        else {
          uVar5 = 0;
        }
        FUN_0072fb20(0x969efc,0x971258,uVar5);
        FUN_00737400();
        FUN_00741f40();
        FUN_0072fb20(0x969efc,0x971270,1);
        FUN_00737400();
        FUN_00741f40();
        FUN_0072fb20(0x969efc,0x971264,0);
        FUN_00737400();
        FUN_00741f40();
        *(undefined1 *)(*(int *)(param_1 + 0x638) + 0x44 + iVar6 * 0x8c) = 1;
        func_0x0046fcf0();
        break;
      }
      iVar6 = iVar6 + 1;
      piVar3 = piVar3 + 0x23;
    } while (iVar6 < *(int *)(param_1 + 0x644));
  }
  uVar5 = FUN_0072ef30(0xd4,0,0xa0ffffff,0);
  FUN_00730110(&DAT_009b3c44,uVar5);
  func_0x005a8e20();
  func_0x005a8750();
  return 1;
}


/* ==================================================================== */
/* Address: 0x005a6c60 | Classified: elementclient::Win_Customize@0x5a6c60 */
/* ==================================================================== */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_005a6c60(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 uStack_13c;
  undefined1 auStack_138 [3];
  undefined1 uStack_135;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined1 *puStack_100;
  undefined *puStack_fc;
  undefined4 *puStack_f8;
  float *pfStack_f4;
  float afStack_e0 [13];
  undefined4 auStack_ac [43];
  
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 0x644)) {
    iVar5 = *(int *)(param_1 + 0x638);
    piVar1 = (int *)(iVar5 + 4);
    do {
      if (param_2 == *piVar1) {
        puVar7 = (undefined4 *)(*(int *)(param_1 + 0xfc) + 0x108);
        puVar8 = auStack_ac;
        for (iVar4 = 0x2b; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        iVar4 = iVar5 + 0x24 + iVar6 * 0x8c;
        if (*(uint *)(iVar5 + 0x30 + iVar6 * 0x8c) < 0xac) {
          *(undefined4 *)(iVar4 + 0xc) = 2;
          pfStack_f4 = *(float **)(iVar4 + 0xc);
          uVar2 = 0x55;
          do {
            pfStack_f4 = (float *)((int)pfStack_f4 << 1);
            uVar2 = uVar2 >> 1;
          } while (uVar2 != 0);
          puStack_f8 = *(undefined4 **)(iVar4 + 4);
          *(float **)(iVar4 + 0xc) = pfStack_f4;
          iVar5 = *(int *)(iVar4 + 8) - (int)puStack_f8;
          puStack_fc = (undefined *)0x5a6cfb;
          iVar6 = realloc();
          *(int *)(iVar4 + 4) = iVar6;
          *(int *)(iVar4 + 8) = iVar6 + iVar5;
        }
        puStack_fc = *(undefined **)(iVar4 + 4);
        puStack_f8 = auStack_ac;
        pfStack_f4 = (float *)0xac;
        puStack_100 = (undefined1 *)0x5a6d1a;
        memmove();
        *(int *)(iVar4 + 8) = *(int *)(iVar4 + 4) + 0xac;
        break;
      }
      iVar6 = iVar6 + 1;
      piVar1 = piVar1 + 0x23;
    } while (iVar6 < *(int *)(param_1 + 0x644));
  }
  pfStack_f4 = afStack_e0;
  iVar6 = **(int **)(param_1 + 0xfc);
  puStack_f8 = (undefined4 *)0x5a6d3c;
  puStack_f8 = (undefined4 *)func_0x005a8320();
  puStack_fc = (undefined *)0x5a6d46;
  (**(code **)(iVar6 + 0x10))();
  puStack_fc = &DAT_009b4340;
  afStack_e0[0] = -*(float *)(*(int *)(*(int *)(_DAT_009b3eec + 0x14) + 8) + 0x58);
  puStack_100 = &stack0xffffff18;
  uStack_104 = 0x5a6d83;
  (**(code **)(**(int **)(param_1 + 0xfc) + 0x14))();
  uStack_104 = 1;
  uStack_108 = 0;
  uStack_10c = 0;
  uStack_110 = 0x969f08;
  uStack_114 = 0x5a6d95;
  FUN_0072fb20();
  uStack_114 = 0x5a6d9c;
  FUN_00735c50();
  uStack_114 = 1;
  uStack_118 = 0;
  uStack_11c = 1;
  uStack_120 = 0x969efc;
  uStack_124 = 0x5a6dae;
  FUN_0072fb20();
  uStack_124 = 0x5a6db5;
  FUN_00735c50();
  uStack_124 = 1;
  uStack_128 = 0;
  uStack_12c = 0;
  uStack_130 = 0x9712ec;
  uStack_134 = 0x5a6dc7;
  FUN_0072fb20();
  uStack_134 = 0x5a6dce;
  FUN_00735c50();
  uStack_134 = 1;
  _auStack_138 = 0;
  uStack_13c = 1;
  FUN_0072fb20(0x969ef0);
  FUN_00735c50();
  FUN_0072fb20(0x969ee4,1,0,1);
  FUN_00735c50();
  func_0x005a83d0(1);
  _auStack_138 = CONCAT31(stack0xfffffec9,DAT_009b3c44);
  iVar6 = *(int *)(param_1 + 0x5a0);
  puVar7 = (undefined4 *)((int)auStack_138 + 1);
  for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)puVar7 = 0;
  *(undefined1 *)((int)puVar7 + 2) = 0;
  sprintf(auStack_138,0x969edc,iVar6 + 1);
  *(undefined4 *)(param_1 + 0x5a0) = 0xffffffff;
  uVar3 = FUN_0072fb20(0x969f08);
  FUN_005a3e90(&uStack_13c,uVar3);
  return 1;
}


/* ==================================================================== */
/* Address: 0x005a6e70 | Classified: elementclient::_s_Info_Agreement_txt@0x5a6e70 */
/* ==================================================================== */

undefined4 FUN_005a6e70(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  char cStack_106;
  char cStack_105;
  undefined1 auStack_104 [260];
  
  uVar1 = func_0x0076eb20();
  sprintf(auStack_104,0x9713f4,uVar1);
  iVar2 = fopen(auStack_104,0x950990);
  if (iVar2 == 0) {
    FUN_0072fb20(0x96e344,0,0,1);
    FUN_00735c50();
    uVar1 = 0x9711a4;
  }
  else {
    cStack_106 = '\0';
    cStack_105 = '\0';
    fread(&cStack_106,1,2,iVar2);
    if ((cStack_106 == -1) && (cStack_105 == -2)) {
      fseek(iVar2,0,2);
      iVar3 = ftell(iVar2);
      if (0 < iVar3 + -2) {
        iVar5 = (iVar3 + -2) / 2;
        iVar3 = func_0x00763250(iVar5 * 2 + 2);
        fseek(iVar2,2,0);
        fread(iVar3,2,iVar5,iVar2);
        *(undefined2 *)(iVar3 + iVar5 * 2) = 0;
        FUN_0072fb20(0x9711b4,0x9713e4);
        piVar4 = (int *)FUN_00737400();
        (**(code **)(*piVar4 + 0x34))(iVar3);
        func_0x00763260(iVar3);
      }
    }
    fclose(iVar2);
    FUN_0072fb20(0x96e344,0,0,1);
    FUN_00735c50();
    uVar1 = 0x9711b4;
  }
  FUN_0072fb20(uVar1,1,0,1);
  FUN_00735c50();
  return 1;
}


/* ==================================================================== */
/* Address: 0x005a6fd0 | Classified: elementclient::Start_game_1___@0x5a6fd0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_005a6fd0(int param_1)

{
  char cVar1;
  
  OutputDebugStringA(0x971458);
  cVar1 = FUN_00434440(*(undefined4 *)
                        (*(int *)(param_1 + 0x638) + *(int *)(param_1 + 0x5a0) * 0x8c + 0x60),
                       &stack0xfffffff0);
  if (cVar1 == '\0') {
    func_0x00764590(1,0x971420);
    (*_DAT_009b3bb4)(*(undefined4 *)(_DAT_009b3eec + 0x274),0x12,0,0);
    return 0;
  }
  func_0x005d4a70();
  OutputDebugStringA(0x97140c);
  return 1;
}


/* ==================================================================== */
/* Address: 0x005a7080 | Classified: elementclient::Win_PwdProtect@0x5a7080 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_005a7080(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  puStack_8 = &UNK_008b75d0;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar2 = FUN_0072fb20(0x971168);
  iVar3 = FUN_0072fb20(0x971158);
  iVar1 = iStack_4;
  if ((iVar2 != 0) && (*(uint *)(iStack_4 + 8) >> 0x10 == 1)) {
    iStack_4 = _DAT_00985a98;
    uStack_c = 0;
    uVar6 = *(int *)(iVar1 + 0xc) % 0x50;
    iVar1 = *(int *)(iVar1 + 0xc) / 0x50;
    uVar7 = iVar1 % 0x50;
    uVar8 = (iVar1 / 0x50) % 0x50;
    FUN_00765690(&iStack_4,0x971484,(uVar6 >> 3) + 0x41,(uVar6 & 7) + 1);
    piVar4 = (int *)FUN_00737400(0x97147c);
    (**(code **)(*piVar4 + 0x34))(puStack_8);
    FUN_00765690(&uStack_c,0x971484,(uVar7 >> 3) + 0x41,(uVar7 & 7) + 1);
    piVar4 = (int *)FUN_00737400(0x971474);
    (**(code **)(*piVar4 + 0x34))(param_1);
    FUN_00765690(&stack0xffffffec,0x971484,(uVar8 >> 3) + 0x41,(uVar8 & 7) + 1);
    piVar4 = (int *)FUN_00737400(0x97146c);
    (**(code **)(*piVar4 + 0x34))(unaff_ESI);
    piVar4 = (int *)FUN_00737400(0x9713c0);
    (**(code **)(*piVar4 + 0x34))(0x9b3c40);
    piVar4 = (int *)FUN_00737400(0x9713b8);
    (**(code **)(*piVar4 + 0x34))(0x9b3c40);
    piVar4 = (int *)FUN_00737400(0x9713b0);
    (**(code **)(*piVar4 + 0x34))(0x9b3c40);
    FUN_00737400(0x9713c0,1);
    FUN_007415a0();
    FUN_00737400(0x9713b8,1);
    FUN_007415a0();
    FUN_00737400(0x9713b0,1);
    FUN_007415a0();
    FUN_00735c50(1,0,1);
    uVar5 = FUN_00737400();
    FUN_007373a0(uVar5);
    FUN_0072fb20(0x971194,0,0,1);
    FUN_00735c50();
    FUN_00765200();
    *unaff_FS_OFFSET = 0x9713c0;
    return 1;
  }
  if ((iVar3 != 0) && (*(uint *)(iStack_4 + 8) >> 0x10 == 2)) {
    uStack_c = 1;
    FUN_00765690(&stack0xffffffe8,0x958750,*(undefined4 *)(iStack_4 + 0xc));
    piVar4 = (int *)FUN_00737400(0x97147c);
    (**(code **)(*piVar4 + 0x34))(unaff_EDI);
    piVar4 = (int *)FUN_00737400(0x9713c0);
    (**(code **)(*piVar4 + 0x34))(0x9b3c40);
    FUN_00737400(0x97147c,1);
    FUN_00742880();
    FUN_00737400(0x9713c0,1);
    FUN_007415a0();
    FUN_00735c50(1,0,1);
    uVar5 = FUN_00737400(0x9713c0);
    FUN_007373a0(uVar5);
    FUN_0072fb20(0x971194,0,0,1);
    FUN_00735c50();
    FUN_00765200();
  }
  *unaff_FS_OFFSET = unaff_EBP;
  return 1;
}


