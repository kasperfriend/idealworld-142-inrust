/* Authentic Ghidra 12.1.4 Decompilation — elementclient.exe (PW 1.4.2 Build 2305) */
/* Module: 13_a3dterrain2.c */

/* ==================================================================== */
/* Address: 0x0077d180 | Classified: Angelica3D::proc_77d180 */
/* ==================================================================== */

undefined4 __thiscall FUN_0077d180(undefined4 param_1,byte param_2)

{
  FUN_0077d1d0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0077d1a0 | Classified: Angelica3D::proc_77d1a0 */
/* ==================================================================== */

void __fastcall FUN_0077d1a0(int param_1)

{
  *(undefined **)(param_1 + 0x10) = &UNK_008f0a44;
  *(undefined **)(param_1 + 0x14) = &UNK_008d5a30;
  if (*(int *)(param_1 + 0x18) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x0077d1d0 | Classified: Angelica3D::proc_77d1d0 */
/* ==================================================================== */

void __fastcall FUN_0077d1d0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008cc5f3;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f0a1c;
  uStack_4 = 9;
  DeleteCriticalSection(param_1 + 0xca);
  DeleteCriticalSection(param_1 + 0xd0);
  DeleteCriticalSection(param_1 + 0xd6);
  param_1[0xf9] = &UNK_008f0a38;
  if (param_1[0xfa] != 0) {
    func_0x00763260(param_1[0xfa]);
    param_1[0xfa] = 0;
  }
  param_1[0xfc] = 0;
  param_1[0xfb] = 0;
  param_1[0xf3] = &UNK_008f0a3c;
  param_1[0xf4] = &UNK_008d5a30;
  if (param_1[0xf5] != 0) {
    func_0x00763260(param_1[0xf5]);
    param_1[0xf5] = 0;
  }
  param_1[0xf7] = 0;
  param_1[0xf6] = 0;
  puVar1 = (undefined4 *)param_1[0xed];
  param_1[0xec] = &UNK_008d67e4;
  while (puVar1 != (undefined4 *)0x0) {
    param_1[0xed] = *puVar1;
    FUN_0077fd10(puVar1);
    puVar1 = (undefined4 *)param_1[0xed];
  }
  puVar1 = (undefined4 *)param_1[0xf2];
  param_1[0xee] = 0;
  param_1[0xf0] = 0;
  while (puVar1 != (undefined4 *)0x0) {
    param_1[0xf2] = puVar1[1];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    puVar1 = (undefined4 *)param_1[0xf2];
  }
  param_1[0xe4] = &UNK_008f0a40;
  param_1[0xe5] = &UNK_008d649c;
  func_0x00421ca0();
  puVar1 = (undefined4 *)param_1[0xeb];
  while (puVar1 != (undefined4 *)0x0) {
    param_1[0xeb] = puVar1[1];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    puVar1 = (undefined4 *)param_1[0xeb];
  }
  param_1[0xdc] = &UNK_008f0a40;
  param_1[0xdd] = &UNK_008d649c;
  func_0x00421ca0();
  puVar1 = (undefined4 *)param_1[0xe3];
  while (puVar1 != (undefined4 *)0x0) {
    param_1[0xe3] = puVar1[1];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    puVar1 = (undefined4 *)param_1[0xe3];
  }
  param_1[0x8e] = &UNK_008f0a44;
  param_1[0x8f] = &UNK_008d5a30;
  func_0x004acc40(1);
  param_1[0x84] = &UNK_008f0a44;
  param_1[0x85] = &UNK_008d5a30;
  if (param_1[0x86] != 0) {
    func_0x00763260(param_1[0x86]);
    param_1[0x86] = 0;
  }
  param_1[0x88] = 0;
  param_1[0x87] = 0;
  func_0x007dc680();
  func_0x007c2b70();
  func_0x007c0a00();
  *param_1 = &UNK_008d6410;
  func_0x007637f0();
  *unaff_FS_OFFSET = unaff_EDI;
  return;
}


/* ==================================================================== */
/* Address: 0x0077d410 | Classified: elementclient::A3DTerrain2__Init__Failed_to_cre@0x77d410 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_0077d410(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined1 param_5)

{
  undefined4 uVar1;
  undefined1 uVar2;
  char cVar3;
  
  uVar2 = 1;
  if (_DAT_00988334 != 4) {
    uVar2 = param_5;
  }
  *(undefined1 *)(param_1 + 0x178) = uVar2;
  *(int *)(param_1 + 0xc) = param_2;
  uVar1 = *(undefined4 *)(param_2 + 0x50);
  *(undefined4 *)(param_1 + 0x1bc) = param_3;
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  *(undefined4 *)(param_1 + 0x1c0) = param_4;
  func_0x007b6680(uVar1);
  *(undefined4 *)(param_1 + 0x158) = 0x41f00000;
  *(undefined4 *)(param_1 + 0x148) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x14c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x150) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x154) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x138) = 0x3f4ccccd;
  *(undefined4 *)(param_1 + 0x13c) = 0x3f4ccccd;
  *(undefined4 *)(param_1 + 0x140) = 0x3f4ccccd;
  *(undefined4 *)(param_1 + 0x144) = 0x3f4ccccd;
  cVar3 = func_0x007c46c0(param_2);
  if (cVar3 == '\0') {
    func_0x007647d0(0x9d2f20,0x988480);
    return 0;
  }
  if (*(char *)(_DAT_009d30fc + 0xc) == '\0') {
    param_5 = 1;
  }
  *(undefined1 *)(param_1 + 0x1b5) = param_5;
  if (*(float *)(param_1 + 0x1c0) < *(float *)(param_1 + 0x1bc)) {
    *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(param_1 + 0x1c0);
  }
  *(undefined4 *)(param_1 + 0x20c) = 0;
  *(undefined4 *)(param_1 + 0x208) = 0;
  *(undefined4 *)(param_1 + 0x204) = 0;
  *(undefined4 *)(param_1 + 0x200) = 0;
  *(undefined4 *)(param_1 + 0x234) = 0;
  *(undefined4 *)(param_1 + 0x230) = 0;
  *(undefined4 *)(param_1 + 0x22c) = 0;
  *(undefined4 *)(param_1 + 0x228) = 0;
  *(undefined4 **)(param_1 + 0x254) = (undefined4 *)(param_1 + 0x228);
  *(undefined4 **)(param_1 + 0x250) = (undefined4 *)(param_1 + 0x200);
  cVar3 = func_0x007c2b80(param_1);
  if (cVar3 == '\0') {
    func_0x007647d0(0x9d2f20,0x98844c);
    return 0;
  }
  cVar3 = func_0x007c0aa0(param_1);
  if (cVar3 == '\0') {
    func_0x007647d0(0x9d2f20,0x988420);
    return 0;
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    func_0x0077b5b0(param_1);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0077d5a0 | Classified: Angelica3D::proc_77d5a0 */
/* ==================================================================== */

void __fastcall FUN_0077d5a0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    func_0x0077b720(param_1);
  }
  FUN_00430850();
  FUN_0077ead0();
  FUN_0077f3a0();
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x3d8)) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x3d4) + iVar3 * 4);
      if (*(int *)(iVar1 + 4) != 0) {
        func_0x0077c560(iVar1 + 4);
      }
      func_0x006e5870();
      func_0x00763260(iVar1);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x3d8));
  }
  if (*(int *)(param_1 + 0x3d4) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x3d4));
    *(undefined4 *)(param_1 + 0x3d4) = 0;
  }
  *(undefined4 *)(param_1 + 0x3dc) = 0;
  *(undefined4 *)(param_1 + 0x3d8) = 0;
  puVar2 = *(undefined4 **)(param_1 + 0x3b4);
  while (puVar2 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x3b4) = *puVar2;
    *puVar2 = *(undefined4 *)(param_1 + 0x3bc);
    *(undefined4 **)(param_1 + 0x3bc) = puVar2;
    puVar2 = *(undefined4 **)(param_1 + 0x3b4);
    *(int *)(param_1 + 0x3c0) = *(int *)(param_1 + 0x3c0) + -1;
  }
  *(undefined4 *)(param_1 + 0x3b8) = 0;
  *(undefined4 *)(param_1 + 0x3c0) = 0;
  if (*(int **)(param_1 + 0x100) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x100) + 8))();
    if (*(undefined4 **)(param_1 + 0x100) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x100))(1);
    }
    *(undefined4 *)(param_1 + 0x100) = 0;
  }
  func_0x007c2fe0();
  func_0x007c0ac0();
  FUN_0077faf0();
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined1 *)(param_1 + 0x17a) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x0077d720 | Classified: Angelica3D::proc_77d720 */
/* ==================================================================== */

void __thiscall FUN_0077d720(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1bc) = param_2;
  if (*(float *)(param_1 + 0x1c0) < *(float *)(param_1 + 0x1bc)) {
    *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(param_1 + 0x1c0);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0077d750 | Classified: Angelica3D::proc_77d750 */
/* ==================================================================== */

void __thiscall FUN_0077d750(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1c0) = param_2;
  if (*(float *)(param_1 + 0x1c0) < *(float *)(param_1 + 0x1bc)) {
    *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(param_1 + 0x1c0);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0077d780 | Classified: elementclient::A3DTerrain2__Load__Failed_to_ope@0x77d780 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0077d780(int param_1,int param_2,char param_3)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 unaff_EBP;
  float unaff_ESI;
  int unaff_EDI;
  int *unaff_FS_OFFSET;
  undefined1 unaff_retaddr;
  undefined4 uVar7;
  int iStack_2d0;
  undefined4 uStack_2cc;
  undefined4 uStack_2bc;
  undefined4 uStack_2b8;
  undefined4 uStack_2b4;
  undefined4 uStack_2ac;
  int iStack_2a8;
  int iStack_2a4;
  undefined4 uStack_2a0;
  undefined4 uStack_294;
  undefined4 uStack_290;
  int iStack_270;
  undefined1 auStack_264 [16];
  undefined1 auStack_254 [576];
  undefined4 uStack_14;
  undefined1 uStack_10;
  int iStack_c;
  undefined *puStack_8;
  float fStack_4;
  
  iStack_c = *unaff_FS_OFFSET;
  fStack_4 = -NAN;
  puStack_8 = &UNK_008cc627;
  *unaff_FS_OFFSET = (int)&iStack_c;
  if (*(char *)(param_1 + 0x17a) == '\0') {
    uStack_2cc = 0x77d7ba;
    func_0x0076e410();
    uStack_2cc = 0x11;
    iStack_2d0 = param_2;
    fStack_4 = 0.0;
    cVar3 = func_0x0076e470();
    if (cVar3 == '\0') {
      uVar7 = 0x9886e8;
LAB_0077db98:
      func_0x007647d0(0x9d2f20,uVar7,param_2);
    }
    else {
      cVar3 = func_0x0076e6a0(&uStack_2bc,8,&stack0xfffffd3c);
      if (cVar3 == '\0') {
        func_0x007647d0(0x9d2f20,0x9886b8);
      }
      else if (unaff_EDI == 0x54524e32) {
        if ((uint)unaff_ESI < 2) {
          cVar3 = func_0x0076e6a0(&stack0xfffffd40,0x84,&iStack_2d0);
          if (cVar3 == '\0') {
            func_0x007647d0(0x9d2f20,0x988620);
          }
          else {
            *(undefined4 *)(param_1 + 0x184) = uStack_2b8;
            *(undefined4 *)(param_1 + 0x188) = uStack_2b4;
            *(undefined4 *)(param_1 + 0x18c) = uStack_2cc;
            *(undefined4 *)(param_1 + 400) = 0x54524e32;
            *(float *)(param_1 + 0x1c4) = unaff_ESI;
            *(undefined4 *)(param_1 + 0x1cc) = uStack_290;
            fVar1 = unaff_ESI * _DAT_008f0a5c;
            *(int *)(param_1 + 0x1d4) = iStack_2a4;
            *(undefined4 *)(param_1 + 0x1d8) = uStack_294;
            *(undefined4 *)(param_1 + 0x1d0) = unaff_EBP;
            *(float *)(param_1 + 0x1c8) = fVar1;
            *(undefined4 *)(param_1 + 0x1dc) = uStack_2bc;
            *(undefined4 *)(param_1 + 0x1e0) = uStack_2ac;
            iVar4 = func_0x007c4a30(unaff_EBP);
            *(int *)(param_1 + 0x104) = iVar4;
            if (iVar4 == 0) {
              func_0x007647d0(0x9d2f20,0x9885f0);
            }
            else {
              FUN_0077f450(*(undefined4 *)(param_1 + 0x26c),*(undefined4 *)(param_1 + 0x270));
              cVar3 = FUN_0077dbe0(auStack_254,iStack_2a4 * iStack_2a8);
              if (cVar3 == '\0') {
                func_0x007647d0(0x9d2f20,0x9885bc);
              }
              else {
                func_0x0076e950(uStack_2a0,0);
                cVar3 = FUN_0077dd40(auStack_264,uStack_2cc);
                if (cVar3 == '\0') {
                  func_0x007647d0(0x9d2f20,0x988584);
                }
                else {
                  func_0x0076e670();
                  puVar5 = (undefined4 *)func_0x00763250(*(int *)(param_1 + 0x1e0) << 3);
                  *(undefined4 **)(param_1 + 0x1fc) = puVar5;
                  if (puVar5 == (undefined4 *)0x0) {
                    func_0x007647d0(0x9d2f20,0x98855c);
                  }
                  else {
                    for (iVar4 = (*(uint *)(param_1 + 0x1e0) & 0x1fffffff) << 1; iVar4 != 0;
                        iVar4 = iVar4 + -1) {
                      *puVar5 = 0;
                      puVar5 = puVar5 + 1;
                    }
                    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
                      *(undefined1 *)puVar5 = 0;
                      puVar5 = (undefined4 *)((int)puVar5 + 1);
                    }
                    if (iStack_270 == 0) {
                      if (param_3 != '\0') goto LAB_0077dba5;
                      iVar4 = func_0x00763250(0x6e4);
                      iStack_c = CONCAT31(iStack_c._1_3_,1);
                      if (iVar4 == 0) {
                        piVar6 = (int *)0x0;
                        iStack_c = (uint)iStack_c._1_3_ << 8;
                        cVar3 = (**(code **)(iRam00000000 + 4))(param_2);
                      }
                      else {
                        piVar6 = (int *)func_0x007c74d0(param_1);
                        uStack_10 = 0;
                        cVar3 = (**(code **)(*piVar6 + 4))(param_2);
                      }
                    }
                    else {
                      if (iStack_270 != 1) {
                        uVar7 = 0x9884bc;
                        param_2 = iStack_270;
                        goto LAB_0077db98;
                      }
                      iVar4 = func_0x00763250(0x78);
                      iStack_c._0_1_ = 2;
                      if (iVar4 == 0) {
                        piVar6 = (int *)0x0;
                      }
                      else {
                        piVar6 = (int *)FUN_007a33a0(param_1);
                      }
                      iStack_c = (uint)iStack_c._1_3_ << 8;
                      cVar3 = (**(code **)(*piVar6 + 4))(param_2);
                    }
                    if (cVar3 == '\0') {
                      func_0x007647d0(0x9d2f20,0x988524);
                    }
                    else {
                      *(int **)(param_1 + 0x100) = piVar6;
                      cVar3 = FUN_0077fa10();
                      if (cVar3 != '\0') {
                        fVar1 = *(float *)(param_1 + 0x18c) * _DAT_008eff98;
                        *(undefined1 *)(param_1 + 0x179) = unaff_retaddr;
                        *(undefined1 *)(param_1 + 0x17a) = 1;
                        fVar1 = (float)puStack_8 - fVar1;
                        *(float *)(param_1 + 0x1e4) = fVar1;
                        fVar2 = *(float *)(param_1 + 400) * _DAT_008eff98 + fStack_4;
                        *(float *)(param_1 + 0x1e8) = fVar2;
                        *(float *)(param_1 + 0x1ec) = fVar1 + *(float *)(param_1 + 0x18c);
                        *(float *)(param_1 + 0x1f0) = fVar2 - *(float *)(param_1 + 400);
                        func_0x007c0b60();
                        uStack_14 = 0xffffffff;
                        func_0x0076e460();
                        uVar7 = 1;
                        goto LAB_0077dbbe;
                      }
                      func_0x007647d0(0x9d2f20,0x9884ec);
                    }
                  }
                }
              }
            }
          }
        }
        else {
          func_0x007647d0(0x9d2f20,0x988658,1,unaff_ESI);
        }
      }
      else {
        func_0x007647d0(0x9d2f20,0x988690);
      }
    }
LAB_0077dba5:
    iStack_c = -1;
    func_0x0076e460();
  }
  uVar7 = 0;
LAB_0077dbbe:
  *unaff_FS_OFFSET = iStack_c;
  return uVar7;
}


/* ==================================================================== */
/* Address: 0x0077dbe0 | Classified: elementclient::AArray__SetSize__Not_enough_memo@0x77dbe0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0077dbe0(int param_1,int *param_2,int param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iStack_4;
  
  iStack_4 = param_1;
  iVar3 = func_0x00763250(param_3 * 8);
  if (iVar3 == 0) {
    return 0;
  }
  *(undefined4 *)(param_1 + 0x3f4) = 100;
  if (param_3 == 0) {
    if (*(int *)(param_1 + 1000) != 0) {
      func_0x00763260(*(int *)(param_1 + 1000));
      *(undefined4 *)(param_1 + 1000) = 0;
    }
    *(undefined4 *)(param_1 + 0x3f0) = 0;
    *(undefined4 *)(param_1 + 0x3ec) = 0;
  }
  else {
    if (*(int *)(param_1 + 0x3f0) < param_3) {
      iVar5 = func_0x00763250(param_3 * 8);
      if (iVar5 == 0) {
        func_0x00764590(1,0x9505a4);
        goto LAB_0077dccd;
      }
      if (*(int *)(param_1 + 1000) != 0) {
        iVar6 = *(int *)(param_1 + 0x3ec);
        if (param_3 <= *(int *)(param_1 + 0x3ec)) {
          iVar6 = param_3;
        }
        iVar4 = 0;
        if (0 < iVar6) {
          do {
            iVar1 = *(int *)(param_1 + 1000);
            iVar4 = iVar4 + 1;
            *(undefined4 *)(iVar5 + -8 + iVar4 * 8) = *(undefined4 *)(iVar1 + -8 + iVar4 * 8);
            *(undefined4 *)(iVar5 + -4 + iVar4 * 8) = *(undefined4 *)(iVar1 + -4 + iVar4 * 8);
          } while (iVar4 < iVar6);
        }
        func_0x00763260(*(undefined4 *)(param_1 + 1000));
      }
      *(int *)(param_1 + 0x3f0) = param_3;
      *(int *)(param_1 + 1000) = iVar5;
    }
    *(int *)(param_1 + 0x3ec) = param_3;
  }
LAB_0077dccd:
  cVar2 = (**(code **)(*param_2 + 0x10))(iVar3,param_3 * 8,&iStack_4);
  if (cVar2 != '\0') {
    iVar5 = 0;
    if (0 < param_3) {
      do {
        *(undefined4 *)(*(int *)(param_1 + 1000) + iVar5 * 8) = *(undefined4 *)(iVar3 + iVar5 * 8);
        *(undefined4 *)(*(int *)(param_1 + 1000) + 4 + iVar5 * 8) =
             *(undefined4 *)(iVar3 + 4 + iVar5 * 8);
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_3);
    }
    func_0x00763260(iVar3);
    return 1;
  }
  func_0x00763260(iVar3);
  return 0;
}


/* ==================================================================== */
/* Address: 0x0077dd40 | Classified: elementclient::AArray__SetSize__Not_enough_memo@0x77dd40 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0077dd40(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  if (*(char *)(param_1 + 0x178) != '\0') {
    return 1;
  }
  iVar5 = 0;
  *(undefined4 *)(param_1 + 0x3e0) = 100;
  if (param_3 == 0) {
    if (*(int *)(param_1 + 0x3d4) != 0) {
      func_0x00763260(*(int *)(param_1 + 0x3d4));
      *(undefined4 *)(param_1 + 0x3d4) = 0;
    }
    *(undefined4 *)(param_1 + 0x3dc) = 0;
    *(undefined4 *)(param_1 + 0x3d8) = 0;
  }
  else {
    if (*(int *)(param_1 + 0x3dc) < param_3) {
      iVar1 = func_0x00763250(param_3 * 4);
      if (iVar1 == 0) {
        func_0x00764590(1,0x9505a4);
        goto LAB_0077de0c;
      }
      if (*(int *)(param_1 + 0x3d4) != 0) {
        iVar4 = *(int *)(param_1 + 0x3d8);
        if (param_3 <= *(int *)(param_1 + 0x3d8)) {
          iVar4 = param_3;
        }
        iVar2 = 0;
        if (0 < iVar4) {
          do {
            iVar2 = iVar2 + 1;
            *(undefined4 *)(iVar1 + -4 + iVar2 * 4) =
                 *(undefined4 *)(*(int *)(param_1 + 0x3d4) + -4 + iVar2 * 4);
          } while (iVar2 < iVar4);
        }
        func_0x00763260(*(undefined4 *)(param_1 + 0x3d4));
      }
      *(int *)(param_1 + 0x3dc) = param_3;
      *(int *)(param_1 + 0x3d4) = iVar1;
    }
    *(int *)(param_1 + 0x3d8) = param_3;
  }
LAB_0077de0c:
  if (0 < param_3) {
    do {
      puVar3 = (undefined4 *)func_0x00763250(0xc);
      if (puVar3 == (undefined4 *)0x0) {
        return 0;
      }
      *puVar3 = _DAT_009858e4;
      puVar3[1] = 0;
      puVar3[2] = 0;
      *(undefined4 **)(*(int *)(param_1 + 0x3d4) + iVar5 * 4) = puVar3;
      (**(code **)(*param_2 + 0x1c))(puVar3);
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_3);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0077de60 | Classified: Angelica3D::proc_77de60 */
/* ==================================================================== */

uint __thiscall FUN_0077de60(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined4 unaff_retaddr;
  
  iVar1 = *(int *)(param_1 + 0xc);
  uVar6 = FUN_00766250();
  *(undefined8 *)(iVar1 + 0x210) = uVar6;
  cVar3 = FUN_0077ee10(param_4);
  if (cVar3 != '\0') {
    if (*(char *)(param_1 + 0x179) == '\0') {
      cVar3 = FUN_0077e790();
      if (cVar3 == '\0') goto LAB_0077de9d;
    }
    else {
      FUN_0077f5e0();
    }
    piVar2 = *(int **)(param_1 + 0x250);
    if (((piVar2[2] != *piVar2) && (piVar2[3] != piVar2[1])) &&
       (*(int **)(param_1 + 0x100) != (int *)0x0)) {
      (**(code **)(**(int **)(param_1 + 0x100) + 0xc))(unaff_retaddr);
      if ((*(char *)(param_1 + 0x179) == '\0') && (*(int *)(*(int *)(param_1 + 0x100) + 8) == 1)) {
        FUN_007a3ef0();
      }
    }
    iVar1 = *(int *)(param_1 + 0xc);
    iVar4 = FUN_00766250();
    iVar4 = iVar4 - *(int *)(iVar1 + 0x210);
    *(int *)(iVar1 + 0x218) = *(int *)(iVar1 + 0x218) + iVar4;
    return CONCAT31((int3)((uint)iVar4 >> 8),1);
  }
LAB_0077de9d:
  iVar1 = *(int *)(param_1 + 0xc);
  iVar4 = FUN_00766250();
  uVar5 = iVar4 - *(int *)(iVar1 + 0x210);
  *(uint *)(iVar1 + 0x218) = *(int *)(iVar1 + 0x218) + uVar5;
  return uVar5 & 0xffffff00;
}


/* ==================================================================== */
/* Address: 0x0077df40 | Classified: Angelica3D::proc_77df40 */
/* ==================================================================== */

uint __thiscall FUN_0077df40(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 in_EAX;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  
  iVar4 = CONCAT31((int3)((uint)in_EAX >> 8),*(char *)(param_1 + 0x17a));
  if (((*(char *)(param_1 + 0x17a) != '\0') && (iVar4 = 0, *(int *)(param_1 + 0x10) != 0)) &&
     (iVar4 = CONCAT31((int3)((uint)*(int *)(param_1 + 0x10) >> 8),*(char *)(param_1 + 0x178)),
     *(char *)(param_1 + 0x178) == '\0')) {
    iVar4 = *(int *)(param_1 + 0xc);
    uVar5 = FUN_00766250();
    *(undefined8 *)(iVar4 + 0x620) = uVar5;
    FUN_0077e1b0(param_2);
    *(undefined1 *)(param_1 + 0x1a4) = 0;
    cVar1 = func_0x007c1450(param_2);
    if (cVar1 == '\0') {
      iVar4 = *(int *)(param_1 + 0xc);
      iVar2 = FUN_00766250();
      uVar3 = iVar2 - *(int *)(iVar4 + 0x620);
      *(uint *)(iVar4 + 0x628) = *(int *)(iVar4 + 0x628) + uVar3;
      return uVar3 & 0xffffff00;
    }
    *(undefined1 *)(param_1 + 0x17c) = 0;
    iVar2 = *(int *)(param_1 + 0xc);
    iVar4 = FUN_00766250();
    iVar4 = iVar4 - *(int *)(iVar2 + 0x620);
    *(int *)(iVar2 + 0x628) = *(int *)(iVar2 + 0x628) + iVar4;
  }
  return CONCAT31((int3)((uint)iVar4 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x0077dff0 | Classified: Angelica3D::proc_77dff0 */
/* ==================================================================== */

uint __thiscall FUN_0077dff0(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 in_EAX;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_EDI;
  undefined8 uVar5;
  
  iVar4 = CONCAT31((int3)((uint)in_EAX >> 8),*(char *)(param_1 + 0x17a));
  if (((*(char *)(param_1 + 0x17a) != '\0') && (iVar4 = 0, *(int *)(param_1 + 0x10) != 0)) &&
     (iVar4 = CONCAT31((int3)((uint)*(int *)(param_1 + 0x10) >> 8),*(char *)(param_1 + 0x178)),
     *(char *)(param_1 + 0x178) == '\0')) {
    iVar4 = *(int *)(param_1 + 0xc);
    uVar5 = FUN_00766250();
    *(undefined8 *)(iVar4 + 0x620) = uVar5;
    FUN_0077e1b0(param_2);
    *(undefined1 *)(param_1 + 0x19c) = 1;
    *(undefined4 *)(param_1 + 0x1a0) = param_2;
    func_0x0077ab70(0);
    cVar1 = func_0x007c1450(param_2);
    if (cVar1 == '\0') {
      *(undefined1 *)(param_1 + 0x19c) = 0;
      func_0x0077ab70(unaff_EDI);
      iVar4 = *(int *)(param_1 + 0xc);
      iVar2 = FUN_00766250();
      uVar3 = iVar2 - *(int *)(iVar4 + 0x620);
      *(uint *)(iVar4 + 0x628) = *(int *)(iVar4 + 0x628) + uVar3;
      return uVar3 & 0xffffff00;
    }
    func_0x0077ab70(unaff_EDI);
    *(undefined1 *)(param_1 + 0x19c) = 0;
    *(undefined1 *)(param_1 + 0x17c) = 0;
    iVar2 = *(int *)(param_1 + 0xc);
    iVar4 = FUN_00766250();
    iVar4 = iVar4 - *(int *)(iVar2 + 0x620);
    *(int *)(iVar2 + 0x628) = *(int *)(iVar2 + 0x628) + iVar4;
  }
  return CONCAT31((int3)((uint)iVar4 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x0077e0f0 | Classified: Angelica3D::proc_77e0f0 */
/* ==================================================================== */

undefined4 __thiscall
FUN_0077e0f0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 in_EAX;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar3 = CONCAT31((int3)((uint)in_EAX >> 8),*(char *)(param_1 + 0x17a));
  if (((*(char *)(param_1 + 0x17a) != '\0') && (iVar3 = 0, *(int *)(param_1 + 0x10) != 0)) &&
     (iVar3 = CONCAT31((int3)((uint)*(int *)(param_1 + 0x10) >> 8),*(char *)(param_1 + 0x178)),
     *(char *)(param_1 + 0x178) == '\0')) {
    iVar3 = *(int *)(param_1 + 0xc);
    uVar4 = FUN_00766250();
    *(undefined8 *)(iVar3 + 0x620) = uVar4;
    FUN_0077e1b0(param_2);
    *(undefined4 *)(param_1 + 0x1ac) = param_3;
    *(undefined1 *)(param_1 + 0x1a4) = 1;
    *(undefined4 *)(param_1 + 0x1a8) = param_2;
    *(undefined4 *)(param_1 + 0x1b0) = param_4;
    uVar2 = func_0x007c1450(param_2);
    if ((char)uVar2 == '\0') {
      return uVar2;
    }
    *(undefined1 *)(param_1 + 0x17c) = 0;
    iVar1 = *(int *)(param_1 + 0xc);
    iVar3 = FUN_00766250();
    iVar3 = iVar3 - *(int *)(iVar1 + 0x620);
    *(int *)(iVar1 + 0x628) = *(int *)(iVar1 + 0x628) + iVar3;
  }
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x0077e1a0 | Classified: Angelica3D::proc_77e1a0 */
/* ==================================================================== */

void __fastcall FUN_0077e1a0(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    do {
      iVar1 = iVar1 + 1;
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x78) + -4 + iVar1 * 4) + 0x10) = 0;
    } while (iVar1 < *(int *)(param_1 + 0x24));
  }
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x0077e1b0 | Classified: Angelica3D::proc_77e1b0 */
/* ==================================================================== */

void __fastcall FUN_0077e1b0(int param_1)

{
  char cVar1;
  int unaff_ESI;
  int iStack_1c;
  undefined4 ***pppuStack_18;
  undefined4 ***apppuStack_10 [2];
  undefined4 uStack_8;
  
  if (*(char *)(param_1 + 0x178) != '\0') {
    return;
  }
  pppuStack_18 = (undefined4 ***)0x77e1c5;
  FUN_0077e1a0();
  iStack_1c = *(int *)(param_1 + 0x1bc);
  pppuStack_18 = apppuStack_10;
  FUN_0077ecf0();
  if (unaff_ESI != iStack_1c) {
    if (apppuStack_10[0] != pppuStack_18) {
      if ((*(int **)(param_1 + 0x108) == (int *)0x0) ||
         (cVar1 = (**(code **)(**(int **)(param_1 + 0x108) + 4))(uStack_8), cVar1 == '\0')) {
        FUN_0077e250(uStack_8,&iStack_1c);
      }
      else {
        (**(code **)(**(int **)(param_1 + 0x108) + 8))(uStack_8,&iStack_1c);
      }
      FUN_0077e360(uStack_8,&stack0xffffffdc);
      return;
    }
    return;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0077e250 | Classified: Angelica3D::proc_77e250 */
/* ==================================================================== */

void __thiscall FUN_0077e250(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  piVar7 = param_3;
  piVar1 = *(int **)(param_1 + 0x250);
  iVar9 = param_3[1];
  iVar11 = piVar1[1];
  iVar2 = *piVar1;
  iVar3 = piVar1[2];
  iVar4 = *piVar1;
  iVar5 = *param_3;
  iVar6 = piVar1[2];
  *(undefined4 *)(param_1 + 0x324) = 0;
  iVar10 = param_3[1];
  if (iVar10 < param_3[3]) {
    iVar9 = (((iVar9 - iVar11) * (iVar3 - iVar2) - iVar2) + iVar5) * 4;
    do {
      iVar11 = iVar9 + (iVar6 - iVar4) * 4;
      param_3 = (int *)*piVar7;
      if ((int)param_3 < piVar7[2]) {
        do {
          iVar2 = *(int *)(iVar9 + piVar1[6]);
          if ((iVar2 != 0) && (*(char *)(iVar2 + 0x18) != '\0')) {
            cVar8 = (**(code **)(**(int **)(param_2 + 0x30) + 0x10))(iVar2 + 0x54,iVar2 + 0x60);
            if (cVar8 == '\0') {
              *(undefined1 *)(iVar2 + 0x74) = 0;
            }
            else {
              *(undefined4 *)(iVar2 + 0x70) = 3;
              *(undefined1 *)(iVar2 + 0x74) = 1;
              func_0x007c1140(iVar2);
              *(int *)(param_1 + 0x324) = *(int *)(param_1 + 0x324) + 1;
            }
          }
          param_3 = (int *)((int)param_3 + 1);
          iVar9 = iVar9 + 4;
        } while ((int)param_3 < piVar7[2]);
      }
      iVar10 = iVar10 + 1;
      iVar9 = iVar11;
    } while (iVar10 < piVar7[3]);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0077e360 | Classified: Angelica3D::proc_77e360 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0077e360(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float *pfVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  
  if (*(int *)(param_1 + 0x268) != 0) {
    piVar2 = *(int **)(param_1 + 0x250);
    iVar16 = param_3[1];
    iVar17 = piVar2[1];
    iVar3 = *piVar2;
    iVar15 = piVar2[2];
    iVar4 = *param_3;
    iVar5 = piVar2[2];
    pfVar13 = (float *)func_0x007744f0();
    fVar6 = pfVar13[1];
    fVar7 = *pfVar13;
    fVar8 = pfVar13[2];
    iStack_20 = param_3[1];
    fVar12 = _DAT_008effc4;
    if (iStack_20 < param_3[3]) {
      iVar1 = (iVar5 - iVar3) * 4;
      iVar16 = (((iVar16 - iVar17) * (iVar15 - iVar3) - iVar3) + iVar4) * 4;
      do {
        iVar17 = *param_3;
        iVar15 = iVar16 + iVar1;
        if (iVar17 < param_3[2]) {
          iStack_18 = iVar1 + iVar16;
          iStack_1c = iVar16 + (iVar5 - iVar3) * -4;
          iVar4 = iVar17;
          do {
            param_2 = iVar4 + 1;
            iVar9 = *(int *)(iVar16 + piVar2[6]);
            if ((iVar9 != 0) && (*(char *)(iVar9 + 0x18) != '\0')) {
              if (*(char *)(iVar9 + 0x74) == '\0') {
                *(undefined4 *)(iVar9 + 0x70) = 0;
              }
              else {
                fVar10 = *(float *)(iVar9 + 0x3c) - fVar7;
                fVar11 = *(float *)(iVar9 + 0x44) - fVar8;
                fVar10 = SQRT(fVar10 * fVar10 + fVar11 * fVar11) - *(float *)(param_1 + 0x1c8);
                if (*(float *)(iVar9 + 0x7c) * *(float *)(param_1 + 0x26c) <= fVar10) {
                  if (*(float *)(iVar9 + 0x7c) * *(float *)(param_1 + 0x270) <= fVar10) {
                    *(undefined4 *)(iVar9 + 0x70) = 1;
                  }
                  else {
                    *(undefined4 *)(iVar9 + 0x70) = 2;
                  }
                }
                else {
                  *(undefined4 *)(iVar9 + 0x70) = 3;
                }
                fVar12 = fVar12 + *(float *)(iVar9 + 0x40);
                if (iVar4 + -1 < **(int **)(param_1 + 0x250)) {
                  uVar14 = 0;
                }
                else {
                  uVar14 = *(undefined4 *)(iVar16 + -4 + piVar2[6]);
                }
                *(undefined4 *)(iVar9 + 0xc4) = uVar14;
                if (iStack_20 + -1 < *(int *)(*(int *)(param_1 + 0x250) + 4)) {
                  uVar14 = 0;
                }
                else {
                  uVar14 = *(undefined4 *)(iStack_1c + piVar2[6]);
                }
                *(undefined4 *)(iVar9 + 200) = uVar14;
                if (param_2 < *(int *)(*(int *)(param_1 + 0x250) + 8)) {
                  uVar14 = *(undefined4 *)(iVar16 + 4 + piVar2[6]);
                }
                else {
                  uVar14 = 0;
                }
                *(undefined4 *)(iVar9 + 0xcc) = uVar14;
                if (iStack_20 + 1 < *(int *)(*(int *)(param_1 + 0x250) + 0xc)) {
                  uVar14 = *(undefined4 *)(iStack_18 + piVar2[6]);
                }
                else {
                  uVar14 = 0;
                }
                *(undefined4 *)(iVar9 + 0xd0) = uVar14;
              }
            }
            iVar17 = iVar17 + 1;
            iStack_1c = iStack_1c + 4;
            iVar16 = iVar16 + 4;
            iStack_18 = iStack_18 + 4;
            iVar4 = param_2;
          } while (iVar17 < param_3[2]);
        }
        iStack_20 = iStack_20 + 1;
        iVar16 = iVar15;
      } while (iStack_20 < param_3[3]);
    }
    if (*(int *)(param_1 + 0x324) != 0) {
      if (*(int *)(param_1 + 0x268) == 1) {
        fVar6 = fVar6 - fVar12 / (float)*(int *)(param_1 + 0x324);
        if (*(float *)(param_1 + 0x270) < fVar6) {
          func_0x007c13b0(2);
          func_0x007c1400();
          return;
        }
        if (*(float *)(param_1 + 0x26c) < fVar6) {
          func_0x007c13b0(1);
          func_0x007c1400();
          return;
        }
      }
      func_0x007c1400();
      return;
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0077e620 | Classified: Angelica3D::proc_77e620 */
/* ==================================================================== */

undefined4 __thiscall FUN_0077e620(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int unaff_EBX;
  int iVar4;
  int unaff_EBP;
  int iVar5;
  int iVar6;
  
  iVar2 = param_2[1];
  iVar5 = *(int *)(param_1 + 0x188) * iVar2 + *param_2;
  if (*(char *)(param_1 + 0x179) == '\0') {
    if (iVar2 < param_2[3]) {
      do {
        iVar4 = *param_2;
        iVar3 = iVar5;
        if (iVar4 < param_2[2]) {
          do {
            uVar1 = FUN_0077e990(iVar2,iVar4,iVar3);
            if (param_2[8] <= param_2[7]) {
              func_0x0068e120(param_2[9]);
            }
            *(undefined4 *)(param_2[6] + param_2[7] * 4) = uVar1;
            iVar4 = iVar4 + 1;
            param_2[7] = param_2[7] + 1;
            iVar3 = iVar3 + 1;
          } while (iVar4 < param_2[2]);
        }
        iVar5 = iVar5 + *(int *)(param_1 + 0x188);
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_2[3]);
      return CONCAT31((int3)((uint)iVar2 >> 8),1);
    }
  }
  else {
    func_0x00431b30((param_2[2] - *param_2) * (param_2[3] - iVar2),10);
    iVar2 = 0;
    if (0 < param_2[7]) {
      do {
        iVar2 = iVar2 + 1;
        *(undefined4 *)(param_2[6] + -4 + iVar2 * 4) = 0;
      } while (iVar2 < param_2[7]);
    }
    iVar2 = param_2[1];
    if (iVar2 < param_2[3]) {
      do {
        iVar4 = *param_2;
        iVar3 = iVar5;
        iVar6 = param_1;
        if (iVar4 < param_2[2]) {
          do {
            iVar3 = func_0x00421d50();
            *(int *)(iVar3 + 8) = iVar5;
            *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(param_1 + 0x3b8);
            if (*(int **)(param_1 + 0x3b8) == (int *)0x0) {
              *(int *)(param_1 + 0x3b4) = iVar3;
            }
            else {
              **(int **)(param_1 + 0x3b8) = iVar3;
            }
            *(int *)(param_1 + 0x3b8) = iVar3;
            iVar4 = iVar4 + 1;
            iVar5 = iVar5 + 1;
            iVar3 = unaff_EBP;
            iVar6 = unaff_EBX;
          } while (iVar4 < param_2[2]);
        }
        iVar5 = iVar3 + *(int *)(iVar6 + 0x188);
        iVar2 = iVar2 + 1;
        param_1 = iVar6;
        unaff_EBP = iVar5;
      } while (iVar2 < param_2[3]);
    }
  }
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x0077e790 | Classified: Angelica3D::proc_77e790 */
/* ==================================================================== */

undefined4 __fastcall FUN_0077e790(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iStack_8;
  
  iStack_8 = *(int *)(param_1 + 0x3c0);
  if (*(int *)(param_1 + 600) < *(int *)(param_1 + 0x3c0)) {
    iStack_8 = *(int *)(param_1 + 600);
  }
  if ((iStack_8 != 0) && (0 < iStack_8)) {
    do {
      piVar1 = *(int **)(param_1 + 0x3b4);
      iVar3 = *piVar1;
      iVar2 = piVar1[2];
      *(int *)(param_1 + 0x3b4) = iVar3;
      if (iVar3 == 0) {
        *(undefined4 *)(param_1 + 0x3b8) = 0;
      }
      else {
        *(undefined4 *)(iVar3 + 4) = 0;
      }
      *piVar1 = *(int *)(param_1 + 0x3bc);
      *(int **)(param_1 + 0x3bc) = piVar1;
      *(int *)(param_1 + 0x3c0) = *(int *)(param_1 + 0x3c0) + -1;
      iVar3 = iVar2 / *(int *)(param_1 + 0x188);
      piVar1 = *(int **)(param_1 + 0x250);
      iVar5 = iVar2 - *(int *)(param_1 + 0x188) * iVar3;
      if ((((*piVar1 <= iVar5) && (iVar5 < piVar1[2])) && (piVar1[1] <= iVar3)) &&
         ((iVar3 < piVar1[3] &&
          (*(int *)(piVar1[6] +
                   (((iVar3 - piVar1[1]) * (piVar1[2] - *piVar1) - *piVar1) + iVar5) * 4) == 0)))) {
        uVar4 = FUN_0077e990(iVar3,iVar5,iVar2);
        piVar1 = *(int **)(param_1 + 0x250);
        *(undefined4 *)
         (piVar1[6] + (((iVar3 - piVar1[1]) * (piVar1[2] - *piVar1) - *piVar1) + iVar5) * 4) = uVar4
        ;
      }
      iStack_8 = iStack_8 + -1;
    } while (iStack_8 != 0);
    iStack_8 = 0;
  }
  return CONCAT31((int3)((uint)iStack_8 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x0077e8a0 | Classified: Angelica3D::proc_77e8a0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0077e8a0(int param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iStack_c;
  
  iVar1 = *(int *)(param_1 + 0x3c0);
  iStack_c = 0;
  if (0 < iVar1) {
    do {
      piVar2 = *(int **)(param_1 + 0x3b4);
      iVar4 = *piVar2;
      iVar3 = piVar2[2];
      *(int *)(param_1 + 0x3b4) = iVar4;
      if (iVar4 == 0) {
        *(undefined4 *)(param_1 + 0x3b8) = 0;
      }
      else {
        *(undefined4 *)(iVar4 + 4) = 0;
      }
      *piVar2 = *(int *)(param_1 + 0x3bc);
      *(int **)(param_1 + 0x3bc) = piVar2;
      *(int *)(param_1 + 0x3c0) = *(int *)(param_1 + 0x3c0) + -1;
      iVar4 = iVar3 / *(int *)(param_1 + 0x188);
      piVar2 = *(int **)(param_1 + 0x250);
      iVar5 = iVar3 - *(int *)(param_1 + 0x188) * iVar4;
      if ((((*piVar2 <= iVar5) && (iVar5 < piVar2[2])) && (piVar2[1] <= iVar4)) &&
         ((iVar4 < piVar2[3] &&
          (*(int *)(piVar2[6] +
                   (((iVar4 - piVar2[1]) * (piVar2[2] - *piVar2) - *piVar2) + iVar5) * 4) == 0)))) {
        *param_2 = iVar4;
        *param_3 = iVar5;
        *param_4 = iVar3;
        return 1;
      }
      iStack_c = iStack_c + 1;
    } while (iStack_c < iVar1);
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x0077e990 | Classified: Angelica3D::proc_77e990 */
/* ==================================================================== */

int __thiscall FUN_0077e990(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_4 < 0) {
    param_4 = *(int *)(param_1 + 0x188) * param_2 + param_3;
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 0x100) + 0x10))(param_2,param_3,param_4);
  if (iVar1 == 0) {
    return 0;
  }
  FUN_0077f240(*(undefined4 *)(iVar1 + 0x20));
  return iVar1;
}


/* ==================================================================== */
/* Address: 0x0077e9e0 | Classified: Angelica3D::proc_77e9e0 */
/* ==================================================================== */

void __thiscall FUN_0077e9e0(int param_1,undefined4 *param_2)

{
  int iVar1;
  int unaff_EBX;
  int iVar2;
  int iVar3;
  int unaff_retaddr;
  
  if (*(char *)(param_1 + 0x179) == '\0') {
    iVar3 = 0;
    if (0 < (int)param_2[7]) {
      do {
        iVar2 = *(int *)(param_2[6] + iVar3 * 4);
        if (iVar2 != 0) {
          FUN_0077eaa0(iVar2);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)param_2[7]);
    }
  }
  else {
    EnterCriticalSection(param_1 + 0x340);
    iVar2 = 0;
    iVar3 = param_1 + 0x340;
    if (0 < (int)param_2[7]) {
      do {
        iVar3 = *(int *)(param_2[6] + iVar2 * 4);
        if (iVar3 != 0) {
          iVar1 = func_0x00419130();
          *(int *)(iVar1 + 8) = iVar3;
          *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(unaff_EBX + 0x39c);
          if (*(int **)(unaff_EBX + 0x39c) == (int *)0x0) {
            *(int *)(unaff_EBX + 0x398) = iVar1;
          }
          else {
            **(int **)(unaff_EBX + 0x39c) = iVar1;
          }
          *(int *)(unaff_EBX + 0x39c) = iVar1;
        }
        iVar2 = iVar2 + 1;
        iVar3 = unaff_retaddr;
      } while (iVar2 < (int)param_2[7]);
    }
    LeaveCriticalSection(iVar3);
  }
  param_2[7] = 0;
  param_2[3] = 0;
  param_2[2] = 0;
  param_2[1] = 0;
  *param_2 = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x0077eaa0 | Classified: Angelica3D::proc_77eaa0 */
/* ==================================================================== */

void __thiscall FUN_0077eaa0(int param_1,int param_2)

{
  FUN_0077f310(*(undefined4 *)(param_2 + 0x20));
  (**(code **)(**(int **)(param_1 + 0x100) + 0x14))(param_2);
  return;
}


/* ==================================================================== */
/* Address: 0x0077ead0 | Classified: Angelica3D::proc_77ead0 */
/* ==================================================================== */

void __fastcall FUN_0077ead0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar2 = *(int *)(param_1 + 0x250);
  iVar5 = 0;
  if (0 < *(int *)(iVar2 + 0x1c)) {
    do {
      iVar3 = *(int *)(*(int *)(iVar2 + 0x18) + iVar5 * 4);
      if (iVar3 != 0) {
        (**(code **)(**(int **)(param_1 + 0x100) + 0x14))(iVar3);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(iVar2 + 0x1c));
  }
  if (*(int *)(param_1 + 0x218) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x218));
    *(undefined4 *)(param_1 + 0x218) = 0;
  }
  *(undefined4 *)(param_1 + 0x220) = 0;
  *(undefined4 *)(param_1 + 0x21c) = 0;
  if (*(int *)(param_1 + 0x240) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x240));
    *(undefined4 *)(param_1 + 0x240) = 0;
  }
  *(undefined4 *)(param_1 + 0x248) = 0;
  *(undefined4 *)(param_1 + 0x244) = 0;
  EnterCriticalSection(param_1 + 0x328);
  puVar4 = *(undefined4 **)(param_1 + 0x378);
  while (puVar4 != (undefined4 *)0x0) {
    puVar1 = puVar4 + 2;
    puVar4 = (undefined4 *)*puVar4;
    (**(code **)(**(int **)(param_1 + 0x100) + 0x14))(*puVar1);
  }
  puVar4 = *(undefined4 **)(param_1 + 0x378);
  while (puVar4 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x378) = *puVar4;
    *puVar4 = *(undefined4 *)(param_1 + 0x380);
    *(undefined4 **)(param_1 + 0x380) = puVar4;
    puVar4 = *(undefined4 **)(param_1 + 0x378);
    *(int *)(param_1 + 900) = *(int *)(param_1 + 900) + -1;
  }
  *(undefined4 *)(param_1 + 0x37c) = 0;
  *(undefined4 *)(param_1 + 900) = 0;
  LeaveCriticalSection(param_1 + 0x328);
  EnterCriticalSection(param_1 + 0x340);
  puVar4 = *(undefined4 **)(param_1 + 0x398);
  while (puVar4 != (undefined4 *)0x0) {
    puVar1 = puVar4 + 2;
    puVar4 = (undefined4 *)*puVar4;
    (**(code **)(**(int **)(param_1 + 0x100) + 0x14))(*puVar1);
  }
  LeaveCriticalSection(param_1 + 0x340);
  return;
}


/* ==================================================================== */
/* Address: 0x0077ec10 | Classified: Angelica3D::proc_77ec10 */
/* ==================================================================== */

undefined4 __fastcall FUN_0077ec10(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 *unaff_retaddr;
  
  if (*(char *)(param_1 + 0x17a) != '\0') {
    iVar1 = *(int *)(param_1 + 0x250);
    FUN_0077e9e0();
    puVar2 = *(undefined4 **)(param_1 + 0x3b4);
    while (puVar2 != (undefined4 *)0x0) {
      *(undefined4 *)(param_1 + 0x3b4) = *puVar2;
      *puVar2 = *(undefined4 *)(param_1 + 0x3bc);
      *(undefined4 **)(param_1 + 0x3bc) = puVar2;
      puVar2 = *(undefined4 **)(param_1 + 0x3b4);
      *(int *)(param_1 + 0x3c0) = *(int *)(param_1 + 0x3c0) + -1;
    }
    *(undefined4 *)(param_1 + 0x3b8) = 0;
    *(undefined4 *)(param_1 + 0x3c0) = 0;
    FUN_0077ecf0(unaff_retaddr,*(undefined4 *)(param_1 + 0x1c0));
    *(undefined4 *)(param_1 + 0x25c) = *unaff_retaddr;
    *(undefined4 *)(param_1 + 0x260) = unaff_retaddr[1];
    *(undefined4 *)(param_1 + 0x264) = unaff_retaddr[2];
    piVar3 = *(int **)(param_1 + 0x250);
    *piVar3 = (int)&stack0xffffffec;
    piVar3[1] = unaff_EDI;
    piVar3[2] = iVar1;
    piVar3[3] = unaff_ESI;
    uVar4 = FUN_0077e620(*(undefined4 *)(param_1 + 0x250));
    return uVar4;
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x0077ecf0 | Classified: Angelica3D::proc_77ecf0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0077ecf0(int param_1,undefined4 param_2,float param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  ceil((double)((_DAT_008effa0 / *(float *)(param_1 + 0x1c4)) * param_3));
  iVar4 = func_0x00892e78();
  iVar2 = *(int *)(param_1 + 0x184);
  iVar3 = *(int *)(param_1 + 0x188);
  iVar1 = iVar4 * 2 + 1;
  iVar5 = func_0x00892e78();
  iVar5 = iVar5 - iVar4;
  iVar6 = func_0x00892e78();
  iVar6 = -(iVar6 + iVar4);
  iVar4 = iVar5 + iVar1;
  if ((iVar5 < 0) && (iVar5 = 0, iVar4 = iVar1, iVar3 <= iVar1)) {
    iVar4 = iVar3;
  }
  iVar7 = iVar6 + iVar1;
  if ((iVar6 < 0) && (iVar6 = 0, iVar7 = iVar1, iVar2 <= iVar1)) {
    iVar7 = iVar2;
  }
  if (iVar3 < iVar4) {
    if (iVar1 < iVar3) {
      iVar5 = iVar3 - iVar1;
      iVar4 = iVar3;
    }
    else {
      iVar5 = 0;
      iVar4 = iVar3;
    }
  }
  if (iVar2 < iVar7) {
    if (iVar1 < iVar2) {
      iVar6 = iVar2 - iVar1;
      iVar7 = iVar2;
    }
    else {
      iVar6 = 0;
      iVar7 = iVar2;
    }
  }
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  if (iVar6 < 0) {
    iVar6 = 0;
  }
  if (iVar3 < iVar4) {
    iVar4 = iVar3;
  }
  if (iVar2 < iVar7) {
    iVar7 = iVar2;
  }
  if ((((iVar5 <= iVar3) && (iVar6 <= iVar2)) && (-1 < iVar4)) &&
     (((-1 < iVar7 && (iVar5 <= iVar4)) && (iVar6 <= iVar7)))) {
    *param_4 = iVar5;
    param_4[1] = iVar6;
    param_4[2] = iVar4;
    param_4[3] = iVar7;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0077ee10 | Classified: Angelica3D::proc_77ee10 */
/* ==================================================================== */

undefined4 __thiscall FUN_0077ee10(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int unaff_EBX;
  int *piVar7;
  int iVar8;
  int unaff_EBP;
  int unaff_EDI;
  int *piVar9;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int aiStack_20 [2];
  int iStack_18;
  int aiStack_8 [2];
  
  if (*(char *)(param_1 + 0x17a) == '\0') {
    return 0;
  }
  FUN_0077ecf0(param_2,*(undefined4 *)(param_1 + 0x1c0),aiStack_20);
  *(undefined4 *)(param_1 + 0x25c) = *param_2;
  *(undefined4 *)(param_1 + 0x260) = param_2[1];
  *(undefined4 *)(param_1 + 0x264) = param_2[2];
  piVar9 = *(int **)(param_1 + 0x250);
  if (piVar9[7] == 0) {
    *piVar9 = iStack_2c;
    piVar9[1] = iStack_28;
    piVar9[2] = iStack_24;
    piVar9[3] = aiStack_20[0];
    uVar2 = FUN_0077e620(*(undefined4 *)(param_1 + 0x250));
    return uVar2;
  }
  if ((((iStack_2c == *piVar9) && (iStack_28 == piVar9[1])) && (iStack_24 == piVar9[2])) &&
     (aiStack_20[0] == piVar9[3])) {
    return 1;
  }
  uVar2 = *(undefined4 *)(param_1 + 0x250);
  *(undefined4 *)(param_1 + 0x250) = *(undefined4 *)(param_1 + 0x254);
  *(undefined4 *)(param_1 + 0x254) = uVar2;
  piVar9 = *(int **)(param_1 + 0x250);
  *piVar9 = iStack_2c;
  piVar9[1] = iStack_28;
  piVar9[2] = iStack_24;
  piVar9[3] = aiStack_20[0];
  piVar9 = *(int **)(param_1 + 0x254);
  if (((iStack_24 != iStack_2c) && (aiStack_20[0] != iStack_28)) &&
     (aiStack_8[0] = piVar9[2], aiStack_8[0] != *piVar9)) {
    iVar3 = piVar9[3];
    iVar1 = piVar9[1];
    piVar6 = piVar9 + 3;
    if (iVar3 != iVar1) {
      if (((iStack_2c < aiStack_8[0]) && (iVar8 = *piVar9, iVar8 < iStack_24)) &&
         ((iStack_28 < iVar3 && (iVar1 < aiStack_20[0])))) {
        if (aiStack_20[0] < iVar3) {
          piVar6 = aiStack_20;
        }
        if (iStack_24 < aiStack_8[0]) {
          piVar7 = &iStack_24;
        }
        else {
          piVar7 = piVar9 + 2;
        }
        piVar5 = &iStack_28;
        if (iStack_28 <= iVar1) {
          piVar5 = piVar9 + 1;
        }
        if (iVar8 < iStack_2c) {
          piVar9 = &iStack_2c;
        }
      }
      else {
        piVar6 = aiStack_8;
        aiStack_8[0] = 0;
        iVar8 = 0;
        unaff_EBP = 0;
        unaff_EBX = 0;
        piVar7 = (int *)&stack0xffffffc8;
        piVar5 = (int *)&stack0xffffffcc;
        piVar9 = (int *)&stack0xffffffd0;
      }
      goto LAB_0077effe;
    }
  }
  piVar6 = aiStack_8;
  aiStack_8[0] = 0;
  unaff_EBX = 0;
  unaff_EBP = 0;
  iVar8 = 0;
  piVar7 = (int *)&stack0xffffffd0;
  piVar5 = (int *)&stack0xffffffcc;
  piVar9 = (int *)&stack0xffffffc8;
LAB_0077effe:
  func_0x006484f0(piVar9,piVar5,piVar7,piVar6);
  if ((iStack_24 != iStack_2c) && (aiStack_20[0] != iStack_28)) {
    iVar3 = *(int *)(param_1 + 0x188) * iVar8 + unaff_EDI;
    for (; iVar4 = iVar3, iVar1 = unaff_EDI, iVar8 < unaff_EBX; iVar8 = iVar8 + 1) {
      for (; iStack_18 = iVar4, iVar1 < unaff_EBP; iVar1 = iVar1 + 1) {
        piVar9 = *(int **)(param_1 + 0x254);
        if ((((iVar1 < *piVar9) || (piVar9[2] <= iVar1)) || (iVar8 < piVar9[1])) ||
           (piVar9[3] <= iVar8)) {
          iVar4 = func_0x00421d50();
          *(int *)(iVar4 + 8) = iStack_18;
          *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(param_1 + 0x3b8);
          if (*(int **)(param_1 + 0x3b8) == (int *)0x0) {
            *(int *)(param_1 + 0x3b4) = iVar4;
          }
          else {
            **(int **)(param_1 + 0x3b8) = iVar4;
          }
          *(int *)(param_1 + 0x3b8) = iVar4;
          iVar4 = *(int *)(param_1 + 0x250);
          if (*(int *)(iVar4 + 0x20) <= *(int *)(iVar4 + 0x1c)) {
            func_0x0068e120(*(undefined4 *)(iVar4 + 0x24));
          }
          *(undefined4 *)(*(int *)(iVar4 + 0x18) + *(int *)(iVar4 + 0x1c) * 4) = 0;
          *(int *)(iVar4 + 0x1c) = *(int *)(iVar4 + 0x1c) + 1;
        }
        else {
          iVar4 = ((iVar8 - piVar9[1]) * (piVar9[2] - *piVar9) - *piVar9) + iVar1;
          uVar2 = *(undefined4 *)(piVar9[6] + iVar4 * 4);
          *(undefined4 *)(piVar9[6] + iVar4 * 4) = 0;
          func_0x00459590(uVar2);
        }
        iVar4 = iStack_18 + 1;
      }
      iVar3 = iVar3 + *(int *)(param_1 + 0x188);
    }
    FUN_0077e9e0(*(undefined4 *)(param_1 + 0x254));
    return 1;
  }
  FUN_0077e9e0(*(undefined4 *)(param_1 + 0x254));
  uVar2 = FUN_0077e620(*(undefined4 *)(param_1 + 0x250));
  return uVar2;
}


/* ==================================================================== */
/* Address: 0x0077f180 | Classified: Angelica3D::proc_77f180 */
/* ==================================================================== */

int __thiscall FUN_0077f180(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  
  if (*(char *)(param_1 + 0x178) != '\0') {
    return 0;
  }
  piVar1 = *(int **)(*(int *)(param_1 + 0x3d4) + param_2 * 4);
  if (*(int *)(*piVar1 + -8) == 0) {
    return 0;
  }
  if (piVar1[1] == 0) {
    piVar1[2] = 0;
    cVar2 = func_0x0077c230(*piVar1,piVar1 + 1,0,0);
    if (cVar2 == '\0') {
      return 0;
    }
  }
  piVar1[2] = piVar1[2] + 1;
  return piVar1[1];
}


/* ==================================================================== */
/* Address: 0x0077f1f0 | Classified: Angelica3D::proc_77f1f0 */
/* ==================================================================== */

void __thiscall FUN_0077f1f0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x178) == '\0') {
    iVar1 = *(int *)(*(int *)(param_1 + 0x3d4) + param_2 * 4);
    if ((*(int *)(iVar1 + 4) != 0) &&
       (iVar2 = *(int *)(iVar1 + 8) + -1, *(int *)(iVar1 + 8) = iVar2, iVar2 == 0)) {
      func_0x0077c560((undefined4 *)(iVar1 + 4));
      *(undefined4 *)(iVar1 + 4) = 0;
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0077f240 | Classified: elementclient::A3DTerrain2__LoadMask__Failed_to@0x77f240 */
/* ==================================================================== */

undefined4 __fastcall FUN_0077f240(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int unaff_retaddr;
  
  if (*(char *)(param_1 + 0x178) == '\0') {
    iVar1 = param_1 + 0x358;
    EnterCriticalSection(iVar1);
    piVar2 = (int *)(*(int *)(param_1 + 0x1fc) + unaff_retaddr * 8);
    if (*(int *)(*(int *)(param_1 + 0x1fc) + unaff_retaddr * 8) != 0) {
      piVar2[1] = piVar2[1] + 1;
      LeaveCriticalSection(iVar1);
      return 1;
    }
    LeaveCriticalSection(iVar1);
    iVar3 = (**(code **)(**(int **)(param_1 + 0x100) + 0x18))(unaff_retaddr);
    if (iVar3 == 0) {
      func_0x007647d0(0x9d2f20,0x988714);
      return 0;
    }
    EnterCriticalSection(iVar1);
    if (*piVar2 != 0) {
      piVar2[1] = piVar2[1] + 1;
      (**(code **)(**(int **)(param_1 + 0x100) + 0x1c))(iVar3);
      LeaveCriticalSection(iVar1);
      return 1;
    }
    *piVar2 = iVar3;
    piVar2[1] = 1;
    LeaveCriticalSection(iVar1);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0077f310 | Classified: Angelica3D::proc_77f310 */
/* ==================================================================== */

void __thiscall FUN_0077f310(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cc648;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (*(char *)(param_1 + 0x178) == '\0') {
    iVar1 = param_1 + 0x358;
    EnterCriticalSection(iVar1);
    uStack_4 = 0;
    puVar2 = (undefined4 *)(*(int *)(param_1 + 0x1fc) + param_2 * 8);
    iVar3 = *(int *)(*(int *)(param_1 + 0x1fc) + param_2 * 8);
    if ((iVar3 != 0) && (iVar4 = puVar2[1], puVar2[1] = iVar4 + -1, iVar4 + -1 == 0)) {
      (**(code **)(**(int **)(param_1 + 0x100) + 0x1c))(iVar3);
      *puVar2 = 0;
    }
    if (iVar1 != 0) {
      LeaveCriticalSection(iVar1);
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x0077f3a0 | Classified: Angelica3D::proc_77f3a0 */
/* ==================================================================== */

void __fastcall FUN_0077f3a0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cc668;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (*(int *)(param_1 + 0x1fc) != 0) {
    iVar1 = param_1 + 0x358;
    EnterCriticalSection(iVar1);
    iVar3 = 0;
    puStack_8 = (undefined *)0x0;
    if (0 < *(int *)(param_1 + 0x1e0)) {
      do {
        iVar2 = *(int *)(*(int *)(param_1 + 0x1fc) + iVar3 * 8);
        if (iVar2 != 0) {
          (**(code **)(**(int **)(param_1 + 0x100) + 0x1c))(iVar2);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1 + 0x1e0));
    }
    func_0x00763260(*(undefined4 *)(param_1 + 0x1fc));
    *(undefined4 *)(param_1 + 0x1fc) = 0;
    if (iVar1 != 0) {
      LeaveCriticalSection(iVar1);
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x0077f450 | Classified: Angelica3D::proc_77f450 */
/* ==================================================================== */

void __thiscall FUN_0077f450(int param_1,float param_2,float param_3)

{
  if (param_3 < param_2) {
    param_3 = param_2;
  }
  *(float *)(param_1 + 0x270) = param_3;
  *(float *)(param_1 + 0x26c) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x0077f480 | Classified: Angelica3D::proc_77f480 */
/* ==================================================================== */

uint __thiscall
FUN_0077f480(int param_1,undefined4 param_2,float *param_3,undefined4 *param_4,undefined4 *param_5)

{
  uint *puVar1;
  undefined4 uVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  *param_4 = 0;
  *param_5 = 0;
  puVar1 = *(uint **)(param_1 + 0x250);
  uVar7 = *puVar1;
  if ((puVar1[2] != uVar7) && (uVar7 = 0, puVar1[3] != puVar1[1])) {
    iVar4 = func_0x00892e78();
    iVar5 = func_0x00892e78();
    iVar6 = iVar4 / *(int *)(param_1 + 0x1d0);
    uVar7 = iVar5 / *(int *)(param_1 + 0x1d0);
    if ((((int)*puVar1 <= iVar6) &&
        (((iVar6 < (int)puVar1[2] && ((int)puVar1[1] <= (int)uVar7)) &&
         ((int)uVar7 < (int)puVar1[3])))) &&
       (iVar6 = *(int *)(puVar1[6] +
                        (((uVar7 - puVar1[1]) * (puVar1[2] - *puVar1) - *puVar1) + iVar6) * 4),
       uVar7 = 0, iVar6 != 0)) {
      uVar7 = *(uint *)(param_1 + 0x1fc);
      iVar6 = *(int *)(uVar7 + *(int *)(iVar6 + 0x20) * 8);
      if (iVar6 != 0) {
        if (param_3 != (float *)0x0) {
          fVar3 = (float)*(int *)(param_1 + 0x1d4) * *(float *)(param_1 + 0x1cc);
          *param_3 = (float)(iVar4 / *(int *)(param_1 + 0x1d4)) * fVar3 +
                     *(float *)(param_1 + 0x1e4);
          param_3[1] = *(float *)(param_1 + 0x1e8) -
                       (float)(iVar5 / *(int *)(param_1 + 0x1d4)) * fVar3;
          param_3[2] = fVar3 + *param_3;
          param_3[3] = param_3[1] - fVar3;
        }
        *param_4 = *(undefined4 *)(iVar6 + 0xc);
        uVar2 = *(undefined4 *)(iVar6 + 0x10);
        *param_5 = uVar2;
        return CONCAT31((int3)((uint)uVar2 >> 8),1);
      }
    }
  }
  return uVar7 & 0xffffff00;
}


/* ==================================================================== */
/* Address: 0x0077f5e0 | Classified: elementclient::AList2__AllocNode__Not_enough_me@0x77f5e0 */
/* ==================================================================== */

void __fastcall FUN_0077f5e0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int *unaff_FS_OFFSET;
  int iStack_18;
  int iStack_14;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cc693;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  iVar1 = param_1 + 0x328;
  EnterCriticalSection(iVar1);
  iStack_18 = *(int *)(param_1 + 900);
  puStack_8 = (undefined *)0x0;
  iVar5 = iVar1;
  if (0 < iStack_18) {
    do {
      piVar2 = *(int **)(param_1 + 0x378);
      iVar5 = *piVar2;
      iVar3 = piVar2[2];
      *(int *)(param_1 + 0x378) = iVar5;
      if (iVar5 == 0) {
        *(undefined4 *)(param_1 + 0x37c) = 0;
      }
      else {
        *(undefined4 *)(iVar5 + 4) = 0;
      }
      FUN_0077fd10(piVar2);
      piVar2 = *(int **)(param_1 + 0x250);
      iVar5 = *(int *)(iVar3 + 0x2c);
      iVar4 = *(int *)(iVar3 + 0x28);
      if ((((iVar5 < *piVar2) || (piVar2[2] <= iVar5)) || (iVar4 < piVar2[1])) ||
         ((piVar2[3] <= iVar4 ||
          (*(int *)(piVar2[6] +
                   (((iVar4 - piVar2[1]) * (piVar2[2] - *piVar2) - *piVar2) + iVar5) * 4) != 0)))) {
        EnterCriticalSection(param_1 + 0x340);
        if (*(int *)(param_1 + 0x3a0) == 0) {
          iVar5 = func_0x00763250(0x10);
          iStack_c._0_1_ = 1;
          if (iVar5 == 0) {
            iVar5 = 0;
          }
          else {
            iVar5 = func_0x006c9840(*(undefined4 *)(param_1 + 0x3a8));
          }
          iStack_c = (uint)iStack_c._1_3_ << 8;
          if (iVar5 != 0) {
            *(undefined4 *)(param_1 + 0x3a0) = *(undefined4 *)(iVar5 + 8);
            *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(param_1 + 0x3ac);
            *(int *)(param_1 + 0x3ac) = iVar5;
            goto LAB_0077f727;
          }
          func_0x00764590(1,0x950554);
          puVar6 = (undefined4 *)0x0;
        }
        else {
LAB_0077f727:
          puVar6 = *(undefined4 **)(param_1 + 0x3a0);
          *(undefined4 *)(param_1 + 0x3a0) = *puVar6;
          *(int *)(param_1 + 0x3a4) = *(int *)(param_1 + 0x3a4) + 1;
          *puVar6 = 0;
          puVar6[1] = 0;
        }
        puVar6[2] = iVar3;
        puVar6[1] = *(undefined4 *)(param_1 + 0x39c);
        if (*(undefined4 **)(param_1 + 0x39c) == (undefined4 *)0x0) {
          *(undefined4 **)(param_1 + 0x398) = puVar6;
        }
        else {
          **(undefined4 **)(param_1 + 0x39c) = puVar6;
        }
        *(undefined4 **)(param_1 + 0x39c) = puVar6;
        LeaveCriticalSection(param_1 + 0x340);
      }
      else {
        *(int *)(piVar2[6] + (((iVar4 - piVar2[1]) * (piVar2[2] - *piVar2) - *piVar2) + iVar5) * 4)
             = iVar3;
      }
      iStack_18 = iStack_18 + -1;
      iVar5 = iStack_14;
    } while (iStack_18 != 0);
  }
  if (iVar5 != 0) {
    LeaveCriticalSection(iVar5);
  }
  *unaff_FS_OFFSET = iVar1;
  return;
}


/* ==================================================================== */
/* Address: 0x0077f7b0 | Classified: Angelica3D::proc_77f7b0 */
/* ==================================================================== */

undefined4 __thiscall
FUN_0077f7b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_0077e990(param_2,param_3,param_4);
  if (iVar2 == 0) {
    return 0;
  }
  iVar1 = param_1 + 0x328;
  EnterCriticalSection(iVar1);
  iVar3 = func_0x00419130();
  *(int *)(iVar3 + 8) = iVar2;
  *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(param_1 + 0x37c);
  if (*(int **)(param_1 + 0x37c) != (int *)0x0) {
    **(int **)(param_1 + 0x37c) = iVar3;
    *(int *)(param_1 + 0x37c) = iVar3;
    LeaveCriticalSection(iVar1);
    return 1;
  }
  *(int *)(param_1 + 0x378) = iVar3;
  *(int *)(param_1 + 0x37c) = iVar3;
  LeaveCriticalSection(iVar1);
  return 1;
}


/* ==================================================================== */
/* Address: 0x0077f830 | Classified: thunk_FUN_0077eaa0 */
/* ==================================================================== */

void __thiscall thunk_FUN_0077eaa0(int param_1,int param_2)

{
  FUN_0077f310(*(undefined4 *)(param_2 + 0x20));
  (**(code **)(**(int **)(param_1 + 0x100) + 0x14))(param_2);
  return;
}


/* ==================================================================== */
/* Address: 0x0077f840 | Classified: Angelica3D::proc_77f840 */
/* ==================================================================== */

int __fastcall FUN_0077f840(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = param_1 + 0x340;
  EnterCriticalSection(iVar1);
  iVar4 = 0;
  if (*(int *)(param_1 + 0x3a4) != 0) {
    piVar2 = *(int **)(param_1 + 0x398);
    iVar3 = *piVar2;
    iVar4 = piVar2[2];
    *(int *)(param_1 + 0x398) = iVar3;
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0x39c) = 0;
    }
    else {
      *(undefined4 *)(iVar3 + 4) = 0;
    }
    *piVar2 = *(int *)(param_1 + 0x3a0);
    *(int **)(param_1 + 0x3a0) = piVar2;
    *(int *)(param_1 + 0x3a4) = *(int *)(param_1 + 0x3a4) + -1;
  }
  if (iVar1 != 0) {
    LeaveCriticalSection(iVar1);
  }
  return iVar4;
}


/* ==================================================================== */
/* Address: 0x0077f8b0 | Classified: Angelica3D::proc_77f8b0 */
/* ==================================================================== */

int __fastcall FUN_0077f8b0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x250);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  if (*(char *)(param_1 + 0x1b5) == '\0') {
    iVar2 = *(int *)(param_1 + 0x1d0) + 1;
    return (piVar1[3] - piVar1[1]) * (piVar1[2] - *piVar1) * iVar2 * iVar2 * 0x38;
  }
  iVar2 = *(int *)(param_1 + 0x1d0) + 1;
  return (piVar1[3] - piVar1[1]) * (piVar1[2] - *piVar1) * iVar2 * iVar2 * 0x48;
}


/* ==================================================================== */
/* Address: 0x0077f920 | Classified: Angelica3D::proc_77f920 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0077f920(int param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar3 = 0;
    iVar2 = 0;
    fVar1 = (*(float *)(param_1 + 8) - *(float *)(param_1 + 4)) * _DAT_008f01d8;
    psVar4 = (short *)(param_1 + 0x10);
    if (0 < *(int *)(param_1 + 0xc)) {
      do {
        iVar3 = *psVar4 + iVar3;
        iVar2 = iVar2 + 1;
        psVar4 = psVar4 + 1;
        *(float *)(param_2 + -4 + iVar2 * 4) = (float)iVar3 * fVar1 + *(float *)(param_1 + 4);
      } while (iVar2 < *(int *)(param_1 + 0xc));
    }
    return *(int *)(param_1 + 0xc) << 2;
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x0077f990 | Classified: Angelica3D::proc_77f990 */
/* ==================================================================== */

int FUN_0077f990(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = 0;
    puVar3 = (undefined1 *)(param_1 + 8);
    if (0 < *(int *)(param_1 + 4)) {
      puVar2 = (undefined4 *)(param_2 + 8);
      do {
        func_0x007b7130(&uStack_c,*puVar3,puVar3[1]);
        puVar2[-2] = uStack_c;
        puVar2[-1] = uStack_8;
        *puVar2 = uStack_4;
        puVar2 = puVar2 + 3;
        puVar3 = puVar3 + 2;
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 4));
    }
    return *(int *)(param_1 + 4) * 0xc;
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x0077fa10 | Classified: elementclient::A3DTerrain2__CreateTempBufs__Not@0x77fa10 */
/* ==================================================================== */

undefined4 __fastcall FUN_0077fa10(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x1d0) + 1;
  iVar3 = iVar3 * iVar3;
  iVar2 = iVar3 * 4;
  iVar1 = func_0x00763250(iVar2);
  *(int *)(param_1 + 0x314) = iVar1;
  if (iVar1 == 0) {
    func_0x007647d0(0x9d2f20,0x988748);
    return 0;
  }
  iVar1 = func_0x00763250(iVar3 * 0xc);
  *(int *)(param_1 + 0x318) = iVar1;
  if (iVar1 == 0) {
    func_0x007647d0(0x9d2f20,0x988748);
    return 0;
  }
  iVar1 = func_0x00763250(iVar2);
  *(int *)(param_1 + 0x31c) = iVar1;
  if (iVar1 == 0) {
    func_0x007647d0(0x9d2f20,0x988748);
    return 0;
  }
  iVar2 = func_0x00763250(iVar2);
  *(int *)(param_1 + 800) = iVar2;
  if (iVar2 == 0) {
    func_0x007647d0(0x9d2f20,0x988748);
    return 0;
  }
  *(int *)(param_1 + 0x310) = iVar3;
  return 1;
}


/* ==================================================================== */
/* Address: 0x0077faf0 | Classified: Angelica3D::proc_77faf0 */
/* ==================================================================== */

void __fastcall FUN_0077faf0(int param_1)

{
  if (*(int *)(param_1 + 0x314) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x314));
  }
  if (*(int *)(param_1 + 0x318) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x318));
  }
  if (*(int *)(param_1 + 0x31c) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x31c));
  }
  if (*(int *)(param_1 + 800) != 0) {
    func_0x00763260(*(int *)(param_1 + 800));
  }
  *(undefined4 *)(param_1 + 0x310) = 0;
  *(undefined4 *)(param_1 + 0x314) = 0;
  *(undefined4 *)(param_1 + 0x318) = 0;
  *(undefined4 *)(param_1 + 0x31c) = 0;
  *(undefined4 *)(param_1 + 800) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x0077fb60 | Classified: elementclient::A3DTerrain2__AttachTerrainCuller@0x77fb60 */
/* ==================================================================== */

undefined4 __thiscall FUN_0077fb60(int param_1,undefined4 *param_2)

{
  char cVar1;
  
  if (param_2 != (undefined4 *)0x0) {
    cVar1 = (**(code **)*param_2)(param_1);
    if (cVar1 == '\0') {
      func_0x007647d0(0x9d2f20,0x98877c);
      return 0;
    }
  }
  *(undefined4 **)(param_1 + 0x108) = param_2;
  return 1;
}


/* ==================================================================== */
/* Address: 0x0077fba0 | Classified: Angelica3D::proc_77fba0 */
/* ==================================================================== */

void __fastcall FUN_0077fba0(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  *param_1 = &UNK_008f0a40;
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
/* Address: 0x0077fc00 | Classified: Angelica3D::proc_77fc00 */
/* ==================================================================== */

void __fastcall FUN_0077fc00(undefined4 *param_1)

{
  *param_1 = &UNK_008f0a3c;
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
/* Address: 0x0077fc30 | Classified: Angelica3D::proc_77fc30 */
/* ==================================================================== */

undefined4 __thiscall FUN_0077fc30(undefined4 param_1,byte param_2)

{
  FUN_0077fc50();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0077fc50 | Classified: Angelica3D::proc_77fc50 */
/* ==================================================================== */

void __fastcall FUN_0077fc50(undefined4 *param_1)

{
  *param_1 = &UNK_008f0a44;
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
/* Address: 0x0077fc80 | Classified: Angelica3D::proc_77fc80 */
/* ==================================================================== */

undefined4 __thiscall FUN_0077fc80(undefined4 param_1,byte param_2)

{
  FUN_0077fba0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0077fca0 | Classified: Angelica3D::proc_77fca0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0077fca0(undefined4 param_1,byte param_2)

{
  FUN_0077fc00();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x0077fcc0 | Classified: Angelica3D::proc_77fcc0 */
/* ==================================================================== */

undefined4 * __thiscall FUN_0077fcc0(undefined4 *param_1,byte param_2)

{
  *param_1 = &UNK_008f0a38;
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
/* Address: 0x0077fd10 | Classified: Angelica3D::proc_77fd10 */
/* ==================================================================== */

void __thiscall FUN_0077fd10(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 **)(param_1 + 0xc) = param_2;
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
  return;
}


/* ==================================================================== */
/* Address: 0x0077fd30 | Classified: Angelica3D::proc_77fd30 */
/* ==================================================================== */

void __fastcall FUN_0077fd30(undefined4 *param_1)

{
  param_1[2] = &UNK_008d5a30;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0x10;
  param_1[1] = &UNK_008f0ad0;
  *param_1 = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x0077fd60 | Classified: Angelica3D::proc_77fd60 */
/* ==================================================================== */

void __fastcall FUN_0077fd60(int param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008cc6ab;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  FUN_0077fea0();
  *(undefined **)(param_1 + 4) = &UNK_008f0ad0;
  uStack_4 = 0xffffffff;
  *(undefined **)(param_1 + 8) = &UNK_008d5a30;
  if (*(int *)(param_1 + 0xc) != 0) {
    func_0x00763260(*(int *)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x0077fdd0 | Classified: Angelica3D::proc_77fdd0 */
/* ==================================================================== */

undefined4 __thiscall
FUN_0077fdd0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,char param_5,
            undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cc6d6;
  *unaff_FS_OFFSET = &uStack_c;
  if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*param_1)(1);
  }
  if (param_5 == '\0') {
    iVar1 = func_0x00763250(0x6d8);
    uStack_4 = 1;
    if (iVar1 != 0) {
      piVar2 = (int *)func_0x007c90b0();
      goto LAB_0077fe4a;
    }
  }
  else {
    iVar1 = func_0x00763250(0x6fc);
    uStack_4 = 0;
    if (iVar1 != 0) {
      piVar2 = (int *)func_0x007cd4a0();
      goto LAB_0077fe4a;
    }
  }
  piVar2 = (int *)0x0;
LAB_0077fe4a:
  uStack_4 = 0xffffffff;
  *param_1 = (int)piVar2;
  if (piVar2 == (int *)0x0) {
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  uVar3 = (**(code **)(*piVar2 + 4))(param_1,param_2,param_3,param_4,param_6,param_7);
  *unaff_FS_OFFSET = param_2;
  return uVar3;
}


/* ==================================================================== */
/* Address: 0x0077fea0 | Classified: Angelica3D::proc_77fea0 */
/* ==================================================================== */

undefined4 __fastcall FUN_0077fea0(int *param_1)

{
  FUN_007806c0();
  if ((int *)*param_1 != (int *)0x0) {
    (**(code **)(*(int *)*param_1 + 8))();
    if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*param_1)(1);
    }
    *param_1 = 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0077fed0 | Classified: Angelica3D::proc_77fed0 */
/* ==================================================================== */

int __thiscall FUN_0077fed0(int param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iStack_2c;
  uint uStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_18;
  int iStack_10;
  int iStack_c;
  
  iStack_10 = *(int *)(param_1 + 0x10);
  iStack_24 = 999999;
  iStack_c = 0;
  if (0 < iStack_10) {
    piVar5 = *(int **)(param_1 + 0xc);
    do {
      iStack_18 = *(int *)(*piVar5 + 0x10);
      if (0 < iStack_18) {
        piVar3 = *(int **)(*piVar5 + 0xc);
        do {
          iVar1 = *piVar3;
          if ((*(char *)(iVar1 + 0x14) == '\0') || (param_3 != '\0')) {
            iVar2 = *(int *)(iVar1 + 0x18);
            uVar4 = func_0x00892e78();
            iStack_20 = *(int *)(iVar1 + 0x1c);
            uStack_28 = func_0x00892e78();
            if (0 < iStack_20) {
              iStack_2c = 0;
              do {
                iVar7 = 0;
                if (0 < iVar2) {
                  uVar8 = uVar4;
                  do {
                    if ((*(char *)(*(int *)(iVar1 + 0x94) + iStack_2c + iVar7) != '\0') &&
                       (iVar6 = ((uStack_28 ^ (int)uStack_28 >> 0x1f) - ((int)uStack_28 >> 0x1f)) +
                                ((uVar8 ^ (int)uVar8 >> 0x1f) - ((int)uVar8 >> 0x1f)),
                       iVar6 < iStack_24)) {
                      iStack_24 = iVar6;
                      iStack_c = iVar1;
                    }
                    iVar7 = iVar7 + 1;
                    uVar8 = uVar8 - 1;
                  } while (iVar7 < iVar2);
                }
                iStack_2c = iStack_2c + iVar2;
                uStack_28 = uStack_28 - 1;
                iStack_20 = iStack_20 + -1;
              } while (iStack_20 != 0);
            }
          }
          piVar3 = piVar3 + 1;
          iStack_18 = iStack_18 + -1;
        } while (iStack_18 != 0);
      }
      piVar5 = piVar5 + 1;
      iStack_10 = iStack_10 + -1;
    } while (iStack_10 != 0);
    return iStack_c;
  }
  return 0;
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
              uVar4 = func_0x00781c50(param_2);
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
            cVar3 = func_0x00781c50(param_2);
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
  func_0x00781be0();
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
    cVar3 = func_0x00781eb0(param_2 + iVar5 * 0x18,param_3 + iVar6 * 6,iVar5 + param_4);
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
      cVar5 = func_0x00782020();
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


