/* Authentic Ghidra 12.1.4 Decompilation — elementclient.exe (PW 1.4.2 Build 2305) */
/* Module: 02_cecworld_load_render.c */

/* ==================================================================== */
/* Address: 0x00428aa0 | Classified: CECWorld::vfunc_slot_0 */
/* ==================================================================== */

undefined4 __thiscall FUN_00428aa0(undefined4 param_1,byte param_2)

{
  FUN_00428ac0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00428ac0 | Classified: ElementClient::proc_428ac0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00428ac0(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &UNK_008d6a88;
  piVar1 = (int *)(param_1[0x1d] + -0xc);
  if (*piVar1 == -1) {
    *piVar1 = 1;
  }
  func_0x00763450(piVar1);
  param_1[0x1d] = _DAT_009858e4;
  return;
}


/* ==================================================================== */
/* Address: 0x00428ad0 | Classified: elementclient::CECWorld__Init__Failed_to_create@0x428ad0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00428ad0(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar3;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a7827;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined4 *)(param_1 + 0x90) = param_2;
  cVar1 = FUN_0042aca0();
  if (cVar1 == '\0') {
    func_0x00764590(1,0x951740);
  }
  else {
    iVar2 = func_0x00763250(0x4c);
    uStack_4 = 0;
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = func_0x0040bd40();
    }
    *(int *)(param_1 + 0x1c) = iVar2;
    uStack_4 = 0xffffffff;
    if (iVar2 == 0) {
      uVar3 = 0xa0;
    }
    else {
      *(int *)(*(int *)(_DAT_009b3eec + 4) + 0xa0) = iVar2;
      cVar1 = FUN_00428ee0();
      if (cVar1 == '\0') {
        func_0x00764590(1,0x951710);
        goto LAB_00428caa;
      }
      iVar2 = func_0x00763250(0x18);
      uStack_4 = 1;
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = func_0x00654bb0();
      }
      uStack_4 = 0xffffffff;
      *(int *)(param_1 + 0x5c) = iVar2;
      if (iVar2 == 0) {
        uVar3 = 0xb0;
      }
      else {
        iVar2 = func_0x00763250(0x48);
        uStack_4 = 2;
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = func_0x00655800();
        }
        uStack_4 = 0xffffffff;
        *(int *)(param_1 + 100) = iVar2;
        if (iVar2 == 0) {
          uVar3 = 0xb7;
        }
        else {
          iVar2 = func_0x00763250(0x58);
          uStack_4 = 3;
          if (iVar2 == 0) {
            iVar2 = 0;
          }
          else {
            iVar2 = func_0x00424cf0();
          }
          uStack_4 = 0xffffffff;
          *(int *)(param_1 + 0x6c) = iVar2;
          if (iVar2 != 0) {
            cVar1 = func_0x00424d40(*(undefined4 *)(_DAT_009b3eec + 8),0x41400000,10);
            if (cVar1 != '\0') {
              iVar2 = func_0x00763250(0xc0);
              uStack_4 = 4;
              if (iVar2 == 0) {
                uVar3 = 0;
              }
              else {
                uVar3 = func_0x004065a0();
              }
              *(undefined4 *)(param_1 + 0x70) = uVar3;
              uStack_4 = 0xffffffff;
              func_0x00417f90(*(undefined1 *)(*(int *)(_DAT_009b3eec + 0x18) + 0x9a));
              *unaff_FS_OFFSET = unaff_ESI;
              return 1;
            }
          }
          uVar3 = 0xbe;
        }
      }
    }
    func_0x0043c590(2,0x951700,uVar3);
  }
LAB_00428caa:
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}


/* ==================================================================== */
/* Address: 0x00428cc0 | Classified: elementclient::CECWorld__InitTerrainWater@0x428cc0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00428cc0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 extraout_EDX;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar3;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a784b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar2 = func_0x00763250(0x1c);
  uStack_4 = 0;
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0077fd30();
  }
  uStack_4 = 0xffffffff;
  *(int *)(param_1 + 0x10) = iVar2;
  if (iVar2 == 0) {
    func_0x0043c590(2,0x95176c,0xd0);
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  uVar3 = 0;
  cVar1 = FUN_0077fdd0(*(undefined4 *)(_DAT_009b3eec + 8),
                       *(undefined4 *)(*(int *)(_DAT_009b3eec + 0x14) + 4),
                       *(undefined4 *)(*(int *)(_DAT_009b3eec + 0x14) + 8),0,4000,4000);
  if (cVar1 == '\0') {
    func_0x0043c590(4,0x95176c,0xd6);
    *unaff_FS_OFFSET = uVar3;
    return 0;
  }
  uVar3 = CONCAT31((int3)((uint)extraout_EDX >> 8),
                   *(char *)(*(int *)(_DAT_009b3eec + 0x18) + 0x95) == '\0');
  FUN_00780a10();
  FUN_00780a00(*(undefined1 *)(*(int *)(_DAT_009b3eec + 0x18) + 0x9f));
  FUN_007809f0(*(undefined4 *)(_DAT_009b3eec + 0xc));
  *unaff_FS_OFFSET = uVar3;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00428de0 | Classified: elementclient::CECWorld__InitPlantsObjects@0x428de0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00428de0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar4;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a7876;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar2 = func_0x00763250(0x284);
  uStack_4 = 0;
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = func_0x0064fb30();
  }
  *(undefined4 *)(param_1 + 0x3c) = uVar3;
  uVar4 = 0x9b41d0;
  uStack_4 = 0xffffffff;
  uVar3 = *(undefined4 *)(_DAT_009b3eec + 8);
  cVar1 = func_0x0064fc90(uVar3,*(undefined4 *)(_DAT_009b3eec + 0xc));
  if (cVar1 == '\0') {
    uVar3 = 0xe8;
  }
  else {
    iVar2 = func_0x00763250(0x6ac);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = func_0x00650b40(uVar3,iVar2);
    }
    *(undefined4 *)(param_1 + 0x40) = uVar3;
    cVar1 = func_0x00650cb0(*(undefined4 *)(_DAT_009b3eec + 8),*(undefined4 *)(param_1 + 0xc),
                            0x9b41d0);
    if (cVar1 != '\0') {
      *unaff_FS_OFFSET = uVar4;
      return 1;
    }
    uVar3 = 0xef;
  }
  func_0x0043c590(4,0x951788,uVar3);
  *unaff_FS_OFFSET = uVar4;
  return 0;
}


/* ==================================================================== */
/* Address: 0x00428ee0 | Classified: elementclient::rain_tga@0x428ee0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00428ee0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *unaff_FS_OFFSET;
  int iStack_30;
  int iStack_2c;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a78a1;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar2 = func_0x00763250(0x88);
  uStack_4 = 0;
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = func_0x004b2cd0();
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x50) = uVar3;
  cVar1 = func_0x004b2d40();
  if (cVar1 == '\0') {
    uVar3 = 0xfd;
  }
  else {
    FUN_00430800(&iStack_30);
    func_0x004b6030((float)(iVar2 + (iStack_30 + iStack_2c * 0x3c) * 0x3c) * _DAT_008d6a8c);
    iVar2 = func_0x00763250(0x1860);
    uStack_c = 1;
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = func_0x0079fe30();
    }
    *(undefined4 *)(param_1 + 0x54) = uVar3;
    uStack_c = 0xffffffff;
    cVar1 = func_0x007a0660(*(undefined4 *)(_DAT_009b3eec + 8),0x3f800000);
    if (cVar1 == '\0') {
      uVar3 = 0x108;
    }
    else {
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x1798) =
           *(undefined4 *)(*(int *)(_DAT_009b3eec + 0x14) + 8);
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x178c) = 0x41a00000;
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x1790) = 0x41a00000;
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x1794) = 0x41000000;
      iVar2 = *(int *)(param_1 + 0x54);
      *(undefined1 *)(iVar2 + 0x15d8) = 1;
      *(undefined1 *)(iVar2 + 0x15e0) = 0;
      *(undefined4 *)(iVar2 + 0x15dc) = 0x14;
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x160c) = 0x3d23d70a;
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x1610) = 0x41f00000;
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x1600) = 0x3f000000;
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x1604) = 0x42480000;
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x1620) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x15f8) = 0x14;
      strncpy(*(int *)(param_1 + 0x54) + 0x14c,0x9517cc,0x104);
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x250) = 5;
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x254) = 6;
      func_0x007a0710();
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x1560) = 1;
      iVar2 = *(int *)(param_1 + 0x54);
      if (-1 < *(int *)(iVar2 + 0x1560)) {
        *(undefined4 *)(iVar2 + 0x1564) = 0xa0ffffff;
        func_0x00789ad0(0xa0ffffff,iVar2 + 0x1578);
      }
      iVar2 = func_0x00763250(0x1798);
      uStack_4 = 2;
      if (iVar2 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = FUN_0079b450();
      }
      *(undefined4 *)(param_1 + 0x58) = uVar3;
      uStack_4 = 0xffffffff;
      cVar1 = func_0x0079b9e0(*(undefined4 *)(_DAT_009b3eec + 8),0x3fe66666);
      if (cVar1 != '\0') {
        *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x1794) =
             *(undefined4 *)(*(int *)(_DAT_009b3eec + 0x14) + 8);
        *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x1788) = 0x42a00000;
        *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x178c) = 0x42a00000;
        *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x1790) = 0x42200000;
        iVar2 = *(int *)(param_1 + 0x58);
        *(undefined1 *)(iVar2 + 0x15d8) = 1;
        *(undefined1 *)(iVar2 + 0x15e0) = 0;
        *(undefined4 *)(iVar2 + 0x15dc) = 0x14;
        *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x160c) = 0x3e99999a;
        *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x1610) = 0x41a00000;
        *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x1600) = 0x3f000000;
        *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x1604) = 0x41a00000;
        *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x15f8) = 100;
        strncpy(*(int *)(param_1 + 0x58) + 0x14c,0x9517a4,0x104);
        *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x250) = 2;
        *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x254) = 4;
        *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x165c) = 100;
        *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x1660) = 0x42480000;
        func_0x007a0710();
        iVar2 = *(int *)(param_1 + 0x58);
        if (-1 < *(int *)(iVar2 + 0x1560)) {
          *(undefined4 *)(iVar2 + 0x1564) = 0xa0a0a0a0;
          func_0x00789ad0(0xa0a0a0a0,iVar2 + 0x1578);
        }
        *unaff_FS_OFFSET = uStack_c;
        return 1;
      }
      uVar3 = 0x121;
    }
  }
  func_0x0043c590(2,0x9517b0,uVar3);
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}


/* ==================================================================== */
/* Address: 0x00429280 | Classified: ElementClient::proc_429280 */
/* ==================================================================== */

void __fastcall FUN_00429280(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x50) != 0) {
    func_0x004b3580();
    iVar1 = *(int *)(param_1 + 0x50);
    if (iVar1 != 0) {
      func_0x004b2d30();
      func_0x00763260(iVar1);
    }
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  if (*(int **)(param_1 + 0x54) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x54) + 0x2c))();
    if (*(undefined4 **)(param_1 + 0x54) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x54))(1);
    }
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  if (*(int **)(param_1 + 0x58) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x58) + 0x2c))();
    if (*(undefined4 **)(param_1 + 0x58) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x58))(1);
    }
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00429300 | Classified: ElementClient::proc_429300 */
/* ==================================================================== */

undefined4 __thiscall FUN_00429300(int param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  puVar2 = (undefined4 *)func_0x007744f0();
  uStack_c = *puVar2;
  uStack_8 = puVar2[1];
  uStack_4 = puVar2[2];
  cVar1 = FUN_00780790(&uStack_c);
  if (cVar1 == '\0') {
    if (*(int **)(param_1 + 0x54) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x54) + 0x4c))(*(undefined4 *)(param_2 + 4));
    }
    if (*(int **)(param_1 + 0x58) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x58) + 0x4c))(*(undefined4 *)(param_2 + 4));
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00429370 | Classified: ElementClient::proc_429370 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00429370(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x50) != 0) {
    iVar1 = param_2;
    if (*(int *)(param_1 + 0x90) == 0) {
      iVar1 = 0;
    }
    func_0x004b5f10(iVar1);
  }
  for (_DAT_009b3ed4 = _DAT_009b3ed4 + param_2; 0x21 < _DAT_009b3ed4;
      _DAT_009b3ed4 = _DAT_009b3ed4 - 0x21) {
    if (*(int **)(param_1 + 0x54) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x54) + 0x48))();
    }
    if (*(int **)(param_1 + 0x58) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x58) + 0x48))();
    }
  }
  return CONCAT31((int3)(_DAT_009b3ed4 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x004293e0 | Classified: ElementClient::proc_4293e0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004293e0(int param_1)

{
  int iVar1;
  
  FUN_00429f10();
  if (*(int *)(param_1 + 0x1c) != 0) {
    *(undefined4 *)(*(int *)(_DAT_009b3eec + 4) + 0xa0) = 0;
    if (*(int **)(param_1 + 0x1c) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x20))(1);
    }
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  FUN_00429280();
  FUN_00429fa0();
  FUN_0042ae30();
  func_0x004283d0();
  if (*(undefined4 **)(param_1 + 0x5c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x5c))(1);
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  if (*(undefined4 **)(param_1 + 100) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 100))(1);
    *(undefined4 *)(param_1 + 100) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x6c);
  if (iVar1 != 0) {
    func_0x00424d30();
    func_0x00763260(iVar1);
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  if (*(int *)(param_1 + 0x70) != 0) {
    func_0x004066d0();
    iVar1 = *(int *)(param_1 + 0x70);
    if (iVar1 != 0) {
      func_0x00406610();
      func_0x00763260(iVar1);
    }
    *(undefined4 *)(param_1 + 0x70) = 0;
  }
  *(undefined4 *)(param_1 + 0x8c) = 1;
  return;
}


/* ==================================================================== */
/* Address: 0x004294a0 | Classified: elementclient::world@0x4294a0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004294a0(int param_1,int param_2,undefined4 *param_3)

{
  float fVar1;
  bool bVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  float *pfVar10;
  char *pcVar11;
  int *piVar12;
  float *pfVar13;
  char *pcVar14;
  char *pcVar15;
  undefined4 *unaff_FS_OFFSET;
  float10 fVar16;
  int iVar17;
  undefined1 *puVar18;
  undefined4 uVar19;
  char cStack_379;
  char cStack_375;
  float afStack_350 [61];
  char acStack_25c [24];
  undefined1 auStack_244 [260];
  undefined1 auStack_140 [188];
  undefined4 uStack_84;
  undefined4 *puStack_64;
  undefined1 uStack_48;
  undefined1 uStack_44;
  undefined4 uStack_34;
  undefined4 uStack_18;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a78c6;
  *unaff_FS_OFFSET = &uStack_c;
  if (*(char *)(param_1 + 0x79) != '\0') {
    func_0x00764590();
    uVar19 = 0;
    goto LAB_00429aea;
  }
  afStack_350[0] = *(float *)(_DAT_009b3eec + 0x1c);
  *(undefined4 *)(param_1 + 0x7c) = *param_3;
  *(undefined4 *)(param_1 + 0x80) = param_3[1];
  *(undefined4 *)(param_1 + 0x84) = param_3[2];
  func_0x0076ef80();
  iVar5 = strrchr();
  func_0x007636f0();
  uStack_c = 0;
  func_0x00763aa0();
  cVar3 = FUN_0042a110();
  if (cVar3 == '\0') {
LAB_0042972b:
    func_0x0043c590();
  }
  else {
    func_0x0076eb80();
    iVar6 = _stricmp();
    if ((iVar6 == 0) || (iVar6 = _stricmp(), iVar6 == 0)) {
LAB_004295bf:
      bVar2 = false;
    }
    else {
      iVar6 = _stricmp();
      bVar2 = true;
      if (iVar6 == 0) goto LAB_004295bf;
    }
    iVar6 = *(int *)(param_1 + 0xc);
    afStack_350[1] = 0.0;
    afStack_350[0] = (float)*(int *)(iVar6 + 0x188) * *(float *)(iVar6 + 0x1c4) * _DAT_008d6a94;
    afStack_350[2] = (float)*(int *)(iVar6 + 0x184) * *(float *)(iVar6 + 0x1c4) * _DAT_008d5894;
    if ((*(int *)(param_1 + 0x70) != 0) && (bVar2)) {
      func_0x00401cc0(afStack_350);
      func_0x004066c0(param_2);
      FUN_005b2ca0(0);
    }
    func_0x00438260();
    cVar3 = FUN_00428cc0();
    if (cVar3 == '\0') {
      func_0x00764590();
    }
    else {
      if ((*(int *)(param_1 + 0x70) != 0) &&
         (cStack_375 = (char)((uint)(iVar5 - param_2) >> 0x18), cStack_375 != '\0')) {
        FUN_005b2ca0();
      }
      func_0x00438260();
      cVar3 = FUN_00428de0();
      if (cVar3 != '\0') {
        if ((*(int *)(param_1 + 0x70) != 0) &&
           (cStack_379 = (char)((uint)param_2 >> 0x18), cStack_379 != '\0')) {
          FUN_005b2ca0();
        }
        func_0x00438260();
        cVar3 = FUN_0042a9d0();
        if (cVar3 != '\0') {
          if ((*(int *)(param_1 + 0x70) != 0) && (bVar2)) {
            FUN_005b2ca0();
          }
          func_0x00438260();
          cVar3 = FUN_0042a8e0();
          if (cVar3 != '\0') {
            if ((*(int *)(param_1 + 0x70) != 0) && (bVar2)) {
              FUN_005b2ca0();
            }
            func_0x00438260();
            sprintf();
            iVar5 = *(int *)(*(int *)(_DAT_009b3eec + 8) + 0x164);
            pfVar10 = (float *)(*(int *)(_DAT_009b3eec + 8) + 0x10);
            pfVar13 = afStack_350 + 2;
            for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
              *pfVar13 = *pfVar10;
              pfVar10 = pfVar10 + 1;
              pfVar13 = pfVar13 + 1;
            }
            piVar12 = *(int **)(iVar5 + 0x4c);
            iVar5 = (**(code **)(*piVar12 + 0x28))(piVar12,0);
            if (iVar5 == 0) {
              uVar19 = 0x951844;
            }
            else {
              uVar19 = 0x951828;
            }
            sprintf(auStack_244,uVar19,afStack_350 + 2);
            puVar18 = auStack_244;
            cVar3 = FUN_0042a310(auStack_140,puVar18);
            if (cVar3 == '\0') {
              func_0x0043c590(3,0x951870,0x220);
            }
            uVar19 = func_0x007636f0(uStack_34,0x31545844);
            cVar3 = (char)((uint)uStack_34 >> 0x18);
            uStack_44 = 1;
            func_0x00763940(uVar19);
            uStack_48 = 0;
            func_0x007637f0();
            uVar19 = 0x951820;
            func_0x00763aa0(0x951820);
            uVar7 = 0xffffffff;
            pcVar11 = (char *)0x951808;
            do {
              pcVar15 = pcVar11;
              if (uVar7 == 0) break;
              uVar7 = uVar7 - 1;
              pcVar15 = pcVar11 + 1;
              cVar4 = *pcVar11;
              pcVar11 = pcVar15;
            } while (cVar4 != '\0');
            uVar7 = ~uVar7;
            iVar5 = -1;
            pcVar11 = acStack_25c;
            do {
              pcVar14 = pcVar11;
              if (iVar5 == 0) break;
              iVar5 = iVar5 + -1;
              pcVar14 = pcVar11 + 1;
              cVar4 = *pcVar11;
              pcVar11 = pcVar14;
            } while (cVar4 != '\0');
            pcVar11 = pcVar15 + -uVar7;
            pcVar15 = pcVar14 + -1;
            for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
              *(undefined4 *)pcVar15 = *(undefined4 *)pcVar11;
              pcVar11 = pcVar11 + 4;
              pcVar15 = pcVar15 + 4;
            }
            for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
              *pcVar15 = *pcVar11;
              pcVar11 = pcVar11 + 1;
              pcVar15 = pcVar15 + 1;
            }
            cVar4 = FUN_0042a820(puVar18,acStack_25c);
            if (cVar4 == '\0') {
              func_0x0043c590(3,0x951870,0x227);
            }
            if ((*(int *)(param_1 + 0x70) != 0) && (cVar3 != '\0')) {
              FUN_005b2ca0(5);
            }
            iVar17 = 2;
            func_0x00438260();
            iVar5 = param_1 + 0x74;
            iVar6 = iVar5;
            func_0x00763940();
            func_0x00763aa0(0x9517f8);
            cVar3 = func_0x0041a040(uVar19);
            if ((cVar3 != '\0') && (cVar3 = func_0x00654d10(uVar19), cVar3 == '\0')) {
              func_0x0043c590(3,0x951870,0x231);
            }
            func_0x00763940(iVar5);
            func_0x00763aa0(0x9517ec);
            cVar3 = func_0x0041a040(puVar18);
            if ((cVar3 != '\0') && (cVar3 = func_0x00655ad0(puVar18), cVar3 == '\0')) {
              func_0x0043c590(3,0x951870,0x237);
            }
            func_0x00763940();
            func_0x00763aa0(0x9517d8);
            cVar3 = func_0x0041a040(iVar6);
            if ((cVar3 != '\0') && (cVar3 = func_0x00424ec0(iVar6), cVar3 == '\0')) {
              func_0x0043c590(3,0x951870,0x23c);
            }
            FUN_0042aad0(puStack_64);
            piVar12 = (int *)(param_1 + 0x20);
            iVar9 = 7;
            do {
              if ((int *)*piVar12 != (int *)0x0) {
                (**(code **)(*(int *)*piVar12 + 0x20))();
              }
              cVar3 = (char)((uint)iVar5 >> 0x18);
              piVar12 = piVar12 + 1;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
            cVar4 = func_0x004283c0();
            if (cVar4 == '\0') {
              func_0x00427e60(1);
            }
            func_0x006450d0();
            func_0x006485e0(puStack_64,1);
            if ((*(int *)(param_1 + 0x70) != 0) && (cVar3 != '\0')) {
              FUN_005b2ca0(6);
            }
            *(undefined1 *)(param_1 + 0x79) = 1;
            if ((*(int *)(_DAT_009b3eec + 0x30) != 0) &&
               (*(char *)(*(int *)(_DAT_009b3eec + 0x30) + 1) != '\0')) {
              func_0x006450d0(puStack_64);
              FUN_005b2420();
            }
            if (*(int *)(iVar17 + 0x90) == 2) {
              uVar19 = *puStack_64;
              fVar16 = (float10)func_0x0042c150(puStack_64,0);
              fVar1 = (float)fVar16 + _DAT_008d6a90;
              iVar5 = *(int *)(*(int *)(_DAT_009b3eec + 0x14) + 8);
              *(int *)(iVar5 + 0x14) = iVar6;
              *(float *)(iVar5 + 0x18) = fVar1;
              *(undefined4 *)(iVar5 + 0x1c) = uVar19;
              func_0x00774140();
              func_0x00427370();
              func_0x00427560();
            }
            else {
              func_0x004b6030(0x3f000000);
            }
            uStack_84 = 0xffffffff;
            func_0x007637f0();
            uVar19 = 1;
            goto LAB_00429aea;
          }
        }
        goto LAB_0042972b;
      }
      func_0x00764590();
    }
  }
  uStack_18 = 0xffffffff;
  func_0x007637f0();
  uVar19 = 0;
LAB_00429aea:
  *unaff_FS_OFFSET = uStack_c;
  return uVar19;
}


/* ==================================================================== */
/* Address: 0x00429b10 | Classified: ElementClient::proc_429b10 */
/* ==================================================================== */

void __fastcall FUN_00429b10(int param_1)

{
  if (*(int *)(param_1 + 8) == 0) {
    FUN_00429fa0();
    FUN_00429b30();
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00429b30 | Classified: elementclient::Configs_AutoFamilyConfigs_AutoSc@0x429b30 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00429b30(int param_1)

{
  float10 fVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *unaff_FS_OFFSET;
  float10 fVar6;
  undefined4 uVar7;
  float fVar8;
  int iStack_4c;
  undefined4 uStack_48;
  int iStack_40;
  undefined4 uStack_3c;
  int iStack_14;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a790f;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  uStack_3c = 0xdc;
  iStack_40 = 0x429b57;
  iVar3 = func_0x00763250();
  uStack_4 = 0;
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uStack_3c = *(undefined4 *)(_DAT_009b3eec + 4);
    iStack_40 = param_1;
    uVar4 = func_0x006be790();
  }
  uStack_3c = 0x951968;
  uStack_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 8) = uVar4;
  iStack_40 = 0x429b96;
  func_0x007636b0();
  puStack_8 = (undefined *)0x1;
  cVar2 = func_0x006bf2a0();
  if (cVar2 == '\0') {
    if (*(int *)(param_1 + 8) != 0) {
      func_0x006bea20();
      if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
        uStack_48 = 0x429bc8;
        (**(code **)**(undefined4 **)(param_1 + 8))();
      }
      *(undefined4 *)(param_1 + 8) = 0;
    }
    iStack_c = -1;
    func_0x007637f0();
    *unaff_FS_OFFSET = iStack_14;
    return 0;
  }
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(*(int *)(param_1 + 8) + 0xc);
  uStack_48 = 0x429bfc;
  iVar5 = func_0x00763250();
  iStack_c._0_1_ = 2;
  if (iVar5 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = func_0x00799610();
  }
  *(undefined4 *)(param_1 + 0x18) = uVar4;
  iStack_c = CONCAT31(iStack_c._1_3_,1);
  iVar5 = *(int *)(_DAT_009b3eec + 0x18);
  uStack_48 = *(undefined4 *)(iVar5 + 0x1c);
  iStack_4c = *(int *)(iVar5 + 0x18);
  cVar2 = func_0x007997a0(*(undefined4 *)(_DAT_009b3eec + 8),0,*(undefined4 *)(iVar5 + 0x14));
  if (cVar2 == '\0') {
    uVar7 = 0x28d;
    uVar4 = 3;
  }
  else {
    if (*(int *)(param_1 + 0x18) != 0) {
      func_0x00784830(*(int *)(param_1 + 0x18));
    }
    iVar5 = func_0x00763250(0x284);
    if (iVar5 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = func_0x0064fb30();
    }
    *(undefined4 *)(param_1 + 0x3c) = uVar4;
    cVar2 = func_0x0064fc90(*(undefined4 *)(_DAT_009b3eec + 8),*(undefined4 *)(_DAT_009b3eec + 0xc),
                            0x9b41d0);
    if (cVar2 == '\0') {
      uVar7 = 0x297;
      uVar4 = 3;
    }
    else {
      iVar5 = func_0x00763250(0x6ac);
      if (iVar5 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = func_0x00650b40();
      }
      *(undefined4 *)(param_1 + 0x40) = uVar4;
      cVar2 = func_0x00650cb0(*(undefined4 *)(_DAT_009b3eec + 8),*(undefined4 *)(param_1 + 0xc),
                              0x9b41d0);
      if (cVar2 == '\0') {
        uVar7 = 0x29f;
        uVar4 = 3;
      }
      else {
        iVar5 = func_0x00763250(0x1c);
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = FUN_0077fd30();
        }
        *(undefined4 *)(param_1 + 0x10) = uVar4;
        cVar2 = FUN_0077fdd0(*(undefined4 *)(_DAT_009b3eec + 8),
                             *(undefined4 *)(*(int *)(_DAT_009b3eec + 0x14) + 4),
                             *(undefined4 *)(*(int *)(_DAT_009b3eec + 0x14) + 8),0,4000,4000);
        if (cVar2 != '\0') {
          FUN_00780a10(*(char *)(*(int *)(_DAT_009b3eec + 0x18) + 0x95) == '\0');
          FUN_00780a00(CONCAT31((int3)((uint)*(int *)(_DAT_009b3eec + 0x18) >> 8),
                                *(undefined1 *)(*(int *)(_DAT_009b3eec + 0x18) + 0x9f)));
          FUN_007809f0(*(undefined4 *)(_DAT_009b3eec + 0xc));
          fVar8 = 300.0;
          iVar3 = *(int *)(*(int *)(_DAT_009b3eec + 0x14) + 8);
          iVar5 = func_0x00641440();
          if (iVar5 == 0) {
            fVar6 = (float10)fVar8;
          }
          else {
            iStack_4c = 0;
            uStack_48 = 0;
            func_0x00641440(&iStack_4c,0);
            fVar6 = (float10)func_0x007776f0();
          }
          fVar1 = (float10)_DAT_008d6a98;
          *(undefined4 *)(iVar3 + 0x14) = 0;
          *(undefined4 *)(iVar3 + 0x1c) = 0;
          *(float *)(iVar3 + 0x18) = (float)(fVar6 + fVar1);
          func_0x00774140();
          iStack_4c = 0;
          uStack_48 = 0x3f800000;
          iStack_40 = 0;
          uStack_3c = 0;
          func_0x00773d00(&iStack_40,&iStack_4c);
          iVar3 = *(int *)(*(int *)(_DAT_009b3eec + 0x1c) + 0x20);
          uVar4 = *(undefined4 *)(iVar3 + 0x44);
          uVar7 = *(undefined4 *)(iVar3 + 0x3c);
          *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(iVar3 + 0x40);
          *(undefined4 *)(param_1 + 0xa8) = uVar7;
          *(undefined4 *)(param_1 + 0xb0) = uVar4;
          FUN_0042af70(0,*(undefined4 *)(_DAT_009b3eec + 0x14));
          func_0x006bb5d0(3,3);
          func_0x007637f0();
          *unaff_FS_OFFSET = iStack_4c;
          return 1;
        }
        uVar7 = 0x2a7;
        uVar4 = 4;
      }
    }
  }
  func_0x0043c590(uVar4,0x95194c,uVar7);
  func_0x007637f0();
  *unaff_FS_OFFSET = iVar3;
  return 0;
}


/* ==================================================================== */
/* Address: 0x00429f10 | Classified: ElementClient::proc_429f10 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00429f10(int param_1)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 8) != 0) {
    func_0x006bea20();
    if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 8))(1);
    }
    *(undefined4 *)(param_1 + 8) = 0;
    FUN_00429f60();
    piVar1 = *(int **)(*(int *)(_DAT_009b3eec + 0x1c) + 0x20);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x10))(param_1 + 0xa8);
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00429f60 | Classified: ElementClient::proc_429f60 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00429f60(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0xa4) != '\0') {
    *(undefined1 *)(param_1 + 0xa4) = 0;
    iVar1 = *(int *)(*(int *)(_DAT_009b3eec + 0x1c) + 0x20);
    if (iVar1 != 0) {
      *(undefined1 *)(iVar1 + 0x8b8) = 0;
    }
    iVar1 = *(int *)(_DAT_009b3eec + 0x1c);
    iVar2 = *(int *)(iVar1 + 0xc);
    *(undefined4 *)(iVar2 + 0x158) = 0;
    if (*(int *)(iVar2 + 0x148) != 0) {
      func_0x00763260(*(int *)(iVar2 + 0x148));
      *(undefined4 *)(iVar2 + 0x148) = 0;
    }
    *(undefined4 *)(iVar2 + 0x150) = 0;
    *(undefined4 *)(iVar2 + 0x14c) = 0;
    iVar2 = *(int *)(iVar1 + 0xc);
    *(undefined4 *)(iVar2 + 0x178) = 0;
    if (*(int *)(iVar2 + 0x168) != 0) {
      func_0x00763260(*(int *)(iVar2 + 0x168));
      *(undefined4 *)(iVar2 + 0x168) = 0;
    }
    *(undefined4 *)(iVar2 + 0x170) = 0;
    *(undefined4 *)(iVar2 + 0x16c) = 0;
    func_0x00404dd0(*(undefined4 *)(iVar1 + 0x14));
    func_0x00404ec0(*(undefined4 *)(iVar1 + 0x14));
    return;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00429fa0 | Classified: ElementClient::proc_429fa0 */
/* ==================================================================== */

void __fastcall FUN_00429fa0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  func_0x00784830(0);
  if (*(int *)(param_1 + 0x4c) != 0) {
    FUN_0041b860();
    if (*(undefined4 **)(param_1 + 0x4c) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x4c))(1);
    }
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  if (*(int *)(param_1 + 0x40) != 0) {
    func_0x00650f10();
    iVar1 = *(int *)(param_1 + 0x40);
    if (iVar1 != 0) {
      func_0x00650c20();
      func_0x00763260(iVar1);
    }
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  if (*(int *)(param_1 + 0x3c) != 0) {
    func_0x00650010();
    iVar1 = *(int *)(param_1 + 0x3c);
    if (iVar1 != 0) {
      func_0x0064fbf0();
      func_0x00763260(iVar1);
    }
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x18) + 8))();
    if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x18))(1);
    }
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  func_0x004275c0();
  piVar2 = (int *)(param_1 + 0x20);
  iVar1 = 7;
  do {
    if ((int *)*piVar2 != (int *)0x0) {
      (**(code **)(*(int *)*piVar2 + 0x24))();
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  func_0x004283d0();
  if (*(int *)(param_1 + 0x14) != 0) {
    FUN_007a44d0();
    if (*(int **)(param_1 + 0x14) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x14) + 0x14))(1);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_0077fea0();
    iVar1 = *(int *)(param_1 + 0x10);
    if (iVar1 != 0) {
      FUN_0077fd60();
      func_0x00763260(iVar1);
    }
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  if (*(int **)(param_1 + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
    if (*(undefined4 **)(param_1 + 0xc) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0xc))(1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  if (*(int *)(param_1 + 0x44) != 0) {
    func_0x006727f0();
    if (*(undefined4 **)(param_1 + 0x44) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x44))(1);
    }
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  if (*(int *)(param_1 + 0x48) != 0) {
    func_0x00645eb0();
    iVar1 = *(int *)(param_1 + 0x48);
    if (iVar1 != 0) {
      func_0x00645a80();
      func_0x00763260(iVar1);
    }
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  *(undefined1 *)(param_1 + 0x79) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x0042a110 | Classified: elementclient::CECWorld__LoadTerrain@0x42a110 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0042a110(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 *unaff_FS_OFFSET;
  float10 fVar8;
  char acStack_110 [256];
  char *pcStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a793c;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar2 = func_0x00763250(0x3f8);
  uStack_4 = 0;
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = func_0x0077ce50();
  }
  *(int *)(param_1 + 0xc) = iVar2;
  uStack_4 = 0xffffffff;
  if (iVar2 == 0) {
    func_0x0043c590(2,0x9519cc,0x316);
    uVar3 = 0;
  }
  else {
    fVar8 = (float10)func_0x0040d470();
    cVar1 = FUN_0077d410(*(undefined4 *)(_DAT_009b3eec + 4),(float)fVar8,(float)fVar8,0,0);
    if (cVar1 == '\0') {
      func_0x0043c590(4,0x9519cc,0x31d);
      uVar3 = 0;
    }
    else {
      cVar1 = FUN_0077d780(pcStack_10,0,0,1);
      if (cVar1 == '\0') {
        func_0x00764590(1,0x951998);
        uVar3 = 0;
      }
      else {
        iVar2 = *(int *)(_DAT_009b3eec + 0x18);
        *(undefined4 *)(*(int *)(param_1 + 0xc) + 600) = 4;
        *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x268) = 2;
        FUN_0077f450(*(undefined4 *)(iVar2 + 0x60),*(undefined4 *)(iVar2 + 100));
        iVar2 = func_0x00763250(0x4c);
        uStack_4 = 1;
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = FUN_007a3fd0();
        }
        uStack_4 = 0xffffffff;
        *(int *)(param_1 + 0x14) = iVar2;
        if (iVar2 != 0) {
          uVar4 = 0xffffffff;
          do {
            pcVar6 = pcStack_10;
            if (uVar4 == 0) break;
            uVar4 = uVar4 - 1;
            pcVar6 = pcStack_10 + 1;
            cVar1 = *pcStack_10;
            pcStack_10 = pcVar6;
          } while (cVar1 != '\0');
          uVar4 = ~uVar4;
          pcVar6 = pcVar6 + -uVar4;
          pcVar7 = acStack_110;
          for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
            pcVar6 = pcVar6 + 4;
            pcVar7 = pcVar7 + 4;
          }
          for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *pcVar7 = *pcVar6;
            pcVar6 = pcVar6 + 1;
            pcVar7 = pcVar7 + 1;
          }
          func_0x0076f070(acStack_110,0x104,0x951990);
          cVar1 = FUN_007a40e0(acStack_110);
          if (cVar1 == '\0') {
            if (*(int *)(param_1 + 0x14) != 0) {
              FUN_007a44d0();
              if (*(int **)(param_1 + 0x14) != (int *)0x0) {
                (**(code **)(**(int **)(param_1 + 0x14) + 0x14))(1);
              }
              *(undefined4 *)(param_1 + 0x14) = 0;
            }
          }
          else {
            FUN_0077fb60(*(undefined4 *)(param_1 + 0x14));
          }
        }
        uVar3 = 1;
      }
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return uVar3;
}


/* ==================================================================== */
/* Address: 0x0042a310 | Classified: ElementClient::proc_42a310 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0042a310(int param_1,undefined4 param_2)

{
  bool bVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a795b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar4 = func_0x00438660(*(undefined4 *)(param_1 + 0x90));
  uVar7 = 1;
  uVar6 = 1;
  if (iVar4 != 0) {
    uVar7 = *(undefined4 *)(iVar4 + 0x10);
    uVar6 = *(undefined4 *)(iVar4 + 0xc);
  }
  iVar4 = func_0x00763250(200);
  puStack_8 = (undefined *)0x0;
  if (iVar4 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = func_0x00672300();
  }
  *(undefined4 *)(param_1 + 0x44) = uVar5;
  puStack_8 = (undefined *)0xffffffff;
  cVar3 = func_0x00672410(*(undefined4 *)(_DAT_009b3eec + 8),param_2,unaff_retaddr,
                          *(undefined4 *)(param_1 + 0xc),uVar7,uVar6);
  if (cVar3 == '\0') {
    if (*(undefined4 **)(param_1 + 0x44) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x44))(1);
    }
    *(undefined4 *)(param_1 + 0x44) = 0;
    *unaff_FS_OFFSET = uVar7;
    return 0;
  }
  switch(*(undefined1 *)(*(int *)(_DAT_009b3eec + 0x18) + 0x94)) {
  case 0:
    iVar4 = *(int *)(param_1 + 0x44);
    if (((*(char *)(iVar4 + 0xa0) != '\0') ||
        (fVar2 = *(float *)(iVar4 + 0x8c) - _DAT_008d689c, _DAT_008d5c28 < fVar2)) ||
       (fVar2 < _DAT_008d5f98)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    *(bool *)(iVar4 + 0xa0) = bVar1;
    if (bVar1) {
      *(undefined4 *)(iVar4 + 0x8c) = 0x43c80000;
    }
    iVar4 = *(int *)(param_1 + 0x44);
    if (((*(char *)(iVar4 + 0xa0) != '\0') ||
        (fVar2 = *(float *)(iVar4 + 0x90) - _DAT_008d60a4, _DAT_008d5c28 < fVar2)) ||
       (fVar2 < _DAT_008d5f98)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    *(bool *)(iVar4 + 0xa0) = bVar1;
    if (bVar1) {
      *(undefined4 *)(iVar4 + 0x90) = 0x43fa0000;
    }
    iVar4 = *(int *)(param_1 + 0x44);
    if (((*(char *)(iVar4 + 0xa0) != '\0') ||
        (fVar2 = *(float *)(iVar4 + 0x94) - _UNK_008d6898, _DAT_008d5c28 < fVar2)) ||
       (fVar2 < _DAT_008d5f98)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    *(bool *)(iVar4 + 0xa0) = bVar1;
    if (bVar1) {
      *(undefined4 *)(iVar4 + 0x94) = 0x44160000;
    }
    goto LAB_0042a729;
  case 1:
    iVar4 = *(int *)(param_1 + 0x44);
    if (((*(char *)(iVar4 + 0xa0) != '\0') ||
        (fVar2 = *(float *)(iVar4 + 0x8c) - _UNK_008d58a4, _DAT_008d5c28 < fVar2)) ||
       (fVar2 < _DAT_008d5f98)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    *(bool *)(iVar4 + 0xa0) = bVar1;
    if (bVar1) {
      *(undefined4 *)(iVar4 + 0x8c) = 0x44480000;
    }
    iVar4 = *(int *)(param_1 + 0x44);
    if (((*(char *)(iVar4 + 0xa0) != '\0') ||
        (fVar2 = *(float *)(iVar4 + 0x90) - _UNK_008d6894, _DAT_008d5c28 < fVar2)) ||
       (fVar2 < _DAT_008d5f98)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    *(bool *)(iVar4 + 0xa0) = bVar1;
    if (bVar1) {
code_r0x0042a62f:
      *(undefined4 *)(iVar4 + 0x90) = 0x44610000;
    }
    break;
  case 2:
    iVar4 = *(int *)(param_1 + 0x44);
    if (((*(char *)(iVar4 + 0xa0) != '\0') ||
        (fVar2 = *(float *)(iVar4 + 0x8c) - _UNK_008d58a4, _DAT_008d5c28 < fVar2)) ||
       (fVar2 < _DAT_008d5f98)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    *(bool *)(iVar4 + 0xa0) = bVar1;
    if (bVar1) {
      *(undefined4 *)(iVar4 + 0x8c) = 0x44480000;
    }
    iVar4 = *(int *)(param_1 + 0x44);
    if (((*(char *)(iVar4 + 0xa0) != '\0') ||
        (fVar2 = *(float *)(iVar4 + 0x90) - _UNK_008d6894, _DAT_008d5c28 < fVar2)) ||
       (fVar2 < _DAT_008d5f98)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    *(bool *)(iVar4 + 0xa0) = bVar1;
    if (bVar1) goto code_r0x0042a62f;
    break;
  case 3:
    iVar4 = *(int *)(param_1 + 0x44);
    if (((*(char *)(iVar4 + 0xa0) != '\0') ||
        (fVar2 = *(float *)(iVar4 + 0x8c) - _UNK_008d58a4, _DAT_008d5c28 < fVar2)) ||
       (fVar2 < _DAT_008d5f98)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    *(bool *)(iVar4 + 0xa0) = bVar1;
    if (bVar1) {
      *(undefined4 *)(iVar4 + 0x8c) = 0x44480000;
    }
    FUN_0042a7c0(1,0x44960000);
    uVar7 = 0x44af0000;
    goto code_r0x0042a71f;
  case 4:
    FUN_0042a7c0(0,0x44480000);
    FUN_0042a7c0(1,0x44960000);
    uVar7 = 0x44ed8000;
code_r0x0042a71f:
    FUN_0042a7c0(2,uVar7);
  default:
    goto LAB_0042a729;
  }
  iVar4 = *(int *)(param_1 + 0x44);
  if (((*(char *)(iVar4 + 0xa0) != '\0') ||
      (fVar2 = *(float *)(iVar4 + 0x94) - _DAT_008d589c, _DAT_008d5c28 < fVar2)) ||
     (fVar2 < _DAT_008d5f98)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  *(bool *)(iVar4 + 0xa0) = bVar1;
  if (bVar1) {
    *(undefined4 *)(iVar4 + 0x94) = 0x447a0000;
  }
LAB_0042a729:
  func_0x00672860(*(char *)(*(int *)(_DAT_009b3eec + 0x18) + 0x96) != '\0');
  FUN_0042a790(*(undefined1 *)(*(int *)(_DAT_009b3eec + 0x18) + 0x94));
  *unaff_FS_OFFSET = unaff_retaddr;
  return 1;
}


/* ==================================================================== */
/* Address: 0x0042a790 | Classified: ElementClient::proc_42a790 */
/* ==================================================================== */

void __thiscall FUN_0042a790(int param_1,int param_2)

{
  if (param_2 < 0) {
    *(undefined4 *)(param_1 + 0xc4) = 0;
    return;
  }
  if (4 < param_2) {
    param_2 = 4;
  }
  *(int *)(param_1 + 0xc4) = param_2;
  return;
}


/* ==================================================================== */
/* Address: 0x0042a7c0 | Classified: ElementClient::proc_42a7c0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0042a7c0(int param_1,int param_2,float param_3)

{
  bool bVar1;
  float fVar2;
  
  if ((-1 < param_2) && (param_2 < 5)) {
    if ((*(char *)(param_1 + 0xa0) != '\0') ||
       ((fVar2 = *(float *)(param_1 + 0x8c + param_2 * 4) - param_3, _DAT_008d5c28 < fVar2 ||
        (fVar2 < _DAT_008d5f98)))) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    *(bool *)(param_1 + 0xa0) = bVar1;
    if (bVar1) {
      *(float *)(param_1 + 0x8c + param_2 * 4) = param_3;
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0042a820 | Classified: ElementClient::proc_42a820 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0042a820(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a797b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar2 = func_0x00763250(0x48);
  uStack_4 = 0;
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = func_0x00645a20();
  }
  *(undefined4 *)(param_1 + 0x48) = uVar3;
  uStack_4 = 0xffffffff;
  cVar1 = func_0x00645c00(*(undefined4 *)(_DAT_009b3eec + 8),param_2);
  if (cVar1 == '\0') {
    func_0x00645eb0();
    iVar2 = *(int *)(param_1 + 0x48);
    if (iVar2 != 0) {
      func_0x00645a80();
      func_0x00763260(iVar2);
    }
    *(undefined4 *)(param_1 + 0x48) = 0;
    *unaff_FS_OFFSET = unaff_ESI;
    return 0;
  }
  *unaff_FS_OFFSET = unaff_ESI;
  return 1;
}


/* ==================================================================== */
/* Address: 0x0042a8e0 | Classified: elementclient::CECWorld__LoadSky__Failed_to_cre@0x42a8e0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0042a8e0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a799b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar5 = func_0x00763250(0x8d4);
  uStack_4 = 0;
  if (iVar5 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = func_0x00799610();
  }
  uStack_4 = 0xffffffff;
  if (iVar5 == 0) {
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  iVar1 = *(int *)(_DAT_009b3eec + 0x18);
  uVar2 = *(undefined4 *)(iVar1 + 0x1c);
  uVar3 = *(undefined4 *)(iVar1 + 0x18);
  cVar4 = func_0x007997a0(*(undefined4 *)(_DAT_009b3eec + 8),0,*(undefined4 *)(iVar1 + 0x14));
  if (cVar4 == '\0') {
    func_0x00764590(1,0x9519e4);
    *unaff_FS_OFFSET = uVar2;
    return 0;
  }
  *(undefined4 *)(iVar5 + 0x4d0) = 0x3b449ba6;
  *(undefined4 *)(iVar5 + 0x4d4) = 0x3b449ba6;
  *(int *)(param_1 + 0x18) = iVar5;
  func_0x00784830(iVar5);
  *unaff_FS_OFFSET = uVar3;
  return 1;
}


/* ==================================================================== */
/* Address: 0x0042a9d0 | Classified: elementclient::CECWorld__LoadSceneObjects@0x42a9d0 */
/* ==================================================================== */

undefined4 __thiscall FUN_0042a9d0(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a79bb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar2 = func_0x00763250(0x8f4);
  uStack_4 = 0;
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = func_0x0041b1f0(param_1);
  }
  uStack_4 = 0xffffffff;
  *(int *)(param_1 + 0x4c) = iVar2;
  if (iVar2 == 0) {
    func_0x0043c590(2,0x951a54,0x3d4);
    *unaff_FS_OFFSET = uStack_c;
    return 0;
  }
  cVar1 = FUN_0041bb30(param_2,0,0);
  if (cVar1 == '\0') {
    func_0x00764590(1,0x951a18,param_2);
    *unaff_FS_OFFSET = unaff_EDI;
    return 0;
  }
  func_0x0040d470();
  *(undefined4 *)(*(int *)(param_1 + 0x4c) + 0x55c) = 0x44fa0000;
  *(undefined4 *)(*(int *)(param_1 + 0x4c) + 0x534) = 2;
  *unaff_FS_OFFSET = unaff_EDI;
  return 1;
}


/* ==================================================================== */
/* Address: 0x0042aad0 | Classified: ElementClient::proc_42aad0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0042aad0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  
  cVar4 = func_0x004283c0();
  if (cVar4 != '\0') {
    func_0x00427e00();
    func_0x004283d0();
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_0077ec10(param_2);
  }
  if (*(int *)(param_1 + 0x4c) != 0) {
    FUN_0041c3b0(param_2);
  }
  cVar4 = func_0x004283c0();
  if (cVar4 != '\0') {
    func_0x00427e60(1);
    func_0x006450d0();
    func_0x006485e0(param_2,1);
    func_0x006450d0();
    func_0x00649a40(param_2,1);
    func_0x00427560();
  }
  if (*(int *)(param_1 + 0x40) != 0) {
    *(undefined1 *)(*(int *)(param_1 + 0x40) + 0xd) = 0;
    func_0x00651040(param_2,0);
    *(undefined1 *)(*(int *)(param_1 + 0x40) + 0xd) = 1;
  }
  uVar1 = *param_2;
  uVar2 = param_2[2];
  iVar3 = *(int *)(*(int *)(_DAT_009b3eec + 0x14) + 8);
  *(float *)(iVar3 + 0x18) = (float)param_2[1] + _DAT_008d6a98;
  *(undefined4 *)(iVar3 + 0x14) = uVar1;
  *(undefined4 *)(iVar3 + 0x1c) = uVar2;
  func_0x00774140();
  *(undefined1 *)(param_1 + 0x78) = 1;
  *(undefined1 *)(param_1 + 0x88) = 1;
  func_0x005b8da0();
  func_0x005b08b0();
  func_0x00430860();
  cVar4 = *(char *)(*(int *)(param_1 + 0x18) + 0x5b9);
  while (cVar4 != '\0') {
    Sleep(10);
    cVar4 = *(char *)(*(int *)(param_1 + 0x18) + 0x5b9);
  }
  FUN_0079b150(0x7fffffff);
  *(undefined1 *)(_DAT_009b3eec + 0x498) = 1;
  return;
}


/* ==================================================================== */
/* Address: 0x0042ac10 | Classified: ElementClient::proc_42ac10 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0042ac10(int param_1,float param_2)

{
  float fVar1;
  int iVar2;
  
  fVar1 = *(float *)(*(int *)(_DAT_009b3eec + 0x18) + 0x48);
  if (param_2 < fVar1) {
    param_2 = fVar1;
  }
  iVar2 = func_0x0042c140();
  if (((iVar2 != 0) && (*(int *)(param_1 + 0xc) != 0)) && (*(int *)(param_1 + 0x4c) != 0)) {
    FUN_0077d750(param_2);
    FUN_0077d720(param_2);
    *(undefined4 *)(*(int *)(param_1 + 0x4c) + 0x55c) = 0x44fa0000;
    FUN_0042aad0(&stack0xffffffec);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0042aca0 | Classified: ElementClient::proc_42aca0 */
/* ==================================================================== */

undefined4 __fastcall FUN_0042aca0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008a7a1d;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar1 = func_0x00763250(0xf4);
  uStack_4 = 0;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x005b5cf0(*(undefined4 *)(param_1 + 4));
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  iVar1 = func_0x00763250(0xc0);
  uStack_4 = 1;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x005af020(*(undefined4 *)(param_1 + 4));
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x24) = uVar2;
  iVar1 = func_0x00763250(0x6c);
  uStack_4 = 2;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x005ad250(*(undefined4 *)(param_1 + 4));
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x28) = uVar2;
  iVar1 = func_0x00763250(200);
  uStack_4 = 3;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x005b1040(*(undefined4 *)(param_1 + 4));
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x2c) = uVar2;
  iVar1 = func_0x00763250(0x60);
  uStack_4 = 4;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x005acc30(*(undefined4 *)(param_1 + 4));
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x38) = uVar2;
  iVar1 = func_0x00763250(0x180);
  uStack_4 = 5;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x005bb430(*(undefined4 *)(param_1 + 4));
  }
  uStack_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x30) = uVar2;
  iVar1 = func_0x00763250(0x30);
  uStack_4 = 6;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x005ac0d0(*(undefined4 *)(param_1 + 4));
  }
  *(undefined4 *)(param_1 + 0x34) = uVar2;
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}


/* ==================================================================== */
/* Address: 0x0042ae30 | Classified: ElementClient::proc_42ae30 */
/* ==================================================================== */

void __fastcall FUN_0042ae30(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 0x20);
  iVar2 = 7;
  do {
    piVar1 = (int *)*piVar3;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))();
      (**(code **)*piVar1)(1);
    }
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


/* ==================================================================== */
/* Address: 0x0042ae60 | Classified: ElementClient::proc_42ae60 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0042ae60(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = func_0x0042c140();
  if (((*(char *)(param_1 + 0x88) == '\0') && (iVar3 != 0)) &&
     (((byte)*(undefined4 *)(iVar3 + 0x678) & 0xf) == 0xf)) {
    fVar1 = *(float *)(iVar3 + 0x8bc);
    if ((ABS(fVar1) <= (float)_DAT_008d6aa0) && (iVar3 = *(int *)(param_1 + 0x4c), iVar3 != 0)) {
      if (*(int *)(iVar3 + 0x8a0) != 0) {
        fVar2 = _DAT_008d6a9c;
        if ((fVar1 != _DAT_008d58a0) &&
           (fVar2 = (*(float *)(iVar3 + 0x560) * _DAT_008d62dc) / fVar1, _DAT_008d6a9c < fVar2)) {
          fVar2 = _DAT_008d6a9c;
        }
        *(float *)(param_1 + 0x9c) =
             (float)*(int *)(iVar3 + 0x8a0) / (fVar2 * *(float *)(_DAT_009b3eec + 0x49c));
      }
      *(float *)(param_1 + 0xa0) = *(float *)(param_1 + 0x9c) + *(float *)(param_1 + 0xa0);
      uVar4 = func_0x00892e78();
      *(undefined4 *)(iVar3 + 0x534) = uVar4;
      iVar3 = func_0x00892e78();
      *(float *)(param_1 + 0xa0) = *(float *)(param_1 + 0xa0) - (float)iVar3;
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0042af70 | Classified: ElementClient::proc_42af70 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0042af70(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  float fVar2;
  char cVar3;
  undefined4 uVar4;
  float *pfVar5;
  float unaff_EBX;
  float unaff_EBP;
  int iVar6;
  int *piVar7;
  undefined4 unaff_retaddr;
  float fStack_34;
  float fStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  undefined1 auStack_20 [8];
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_4;
  
  iVar6 = 7;
  piVar7 = (int *)(param_1 + 0x20);
  do {
    if ((int *)*piVar7 != (int *)0x0) {
      (**(code **)(*(int *)*piVar7 + 8))(param_2);
    }
    piVar7 = piVar7 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  FUN_0042ae60();
  func_0x00438290(&fStack_18,param_3);
  piVar7 = *(int **)(param_1 + 0xc);
  uVar1 = *(undefined4 *)(param_3 + 8);
  if (piVar7 != (int *)0x0) {
    if ((*(int *)(param_1 + 8) == 0) || (*(char *)(param_1 + 0xa4) != '\0')) {
      (**(code **)(*piVar7 + 0x18))(param_2,uVar1,auStack_20);
    }
    else {
      iVar6 = *piVar7;
      uVar4 = func_0x007744f0();
      (**(code **)(iVar6 + 0x18))(param_2,uVar1,uVar4);
    }
    if (*(int *)(param_1 + 0x44) != 0) {
      func_0x006729a0(uVar1,auStack_20);
    }
    if ((*(int *)(*(int *)(param_1 + 4) + 0x90) == 2) &&
       (*(char *)(*(int *)(param_1 + 0xc) + 0x179) != '\0')) {
      cVar3 = FUN_0077e8a0(&stack0xffffffc4,&stack0x00000000,&fStack_4);
      while (cVar3 != '\0') {
        func_0x004277d0(unaff_EBP,unaff_retaddr,fStack_4);
        cVar3 = FUN_0077e8a0(&stack0xffffffc4,&stack0x00000000,&fStack_4);
      }
    }
  }
  if (*(int *)(param_1 + 0x48) != 0) {
    fStack_2c = -1.0;
    fStack_28 = -1.0;
    uStack_24 = 0xbf800000;
    fStack_4 = (float)SQRT((float10)_DAT_008d6140);
    if (((float10)_DAT_008d5c38 <= SQRT((float10)_DAT_008d6140)) ||
       (fStack_4 <= (float)_DAT_008d5c30)) {
      func_0x00408020(&stack0xffffffc8,&fStack_2c,fStack_4);
    }
    else {
      func_0x0040af10(0);
    }
    iVar6 = *(int *)(param_1 + 0x50);
    if (iVar6 != 0) {
      unaff_EBP = *(float *)(iVar6 + 0x54);
      unaff_EBX = *(float *)(iVar6 + 0x58);
      fStack_34 = *(float *)(iVar6 + 0x5c);
    }
    fVar2 = unaff_EBP * _DAT_008d6aa8;
    fStack_2c = unaff_EBX * _DAT_008d6aa8;
    fStack_28 = fStack_34 * _DAT_008d6aa8;
    pfVar5 = (float *)func_0x007744f0();
    fStack_10 = pfVar5[2] - fStack_28;
    fStack_14 = pfVar5[1] - fStack_2c;
    fStack_18 = *pfVar5 - fVar2;
    func_0x00645ae0(param_2,&fStack_18);
  }
  if (*(int *)(param_1 + 0x4c) != 0) {
    FUN_0041cec0(param_2,uVar1,auStack_20);
  }
  if (*(int *)(param_1 + 0x6c) != 0) {
    func_0x00425470(param_2,*(undefined4 *)(*(int *)(param_1 + 0x50) + 0x70),auStack_20);
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00780a30(param_2);
  }
  if (*(int *)(param_1 + 0x3c) != 0) {
    func_0x00650080(param_2);
  }
  if ((*(int *)(param_1 + 0x40) != 0) && (*(char *)(*(int *)(_DAT_009b3eec + 0x18) + 0x39) != '\0'))
  {
    *(undefined1 *)(*(int *)(param_1 + 0x40) + 0xd) = 1;
    func_0x00651040(auStack_20,param_2);
  }
  FUN_00429370(param_2);
  if (*(int *)(*(int *)(param_1 + 4) + 0x90) == 2) {
    func_0x0042c8f0();
    func_0x0042cb80();
  }
  *(undefined1 *)(param_1 + 0x88) = 0;
  func_0x00427e60(0);
  if (*(int *)(param_1 + 8) != 0) {
    uVar4 = func_0x007744f0();
    func_0x006bf4a0(param_2,uVar1,uVar4);
  }
  return 1;
}


