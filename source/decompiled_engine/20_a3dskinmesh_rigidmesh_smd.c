/* Authentic Ghidra 12.1.4 Decompilation — elementclient.exe (PW 1.4.2 Build 2305) */
/* Module: 20_a3dskinmesh_rigidmesh_smd.c */

/* ==================================================================== */
/* Address: 0x007ae0d0 | Classified: elementclient::A3DSklTrackSet__Load__Failed_to_l@0x7ae0d0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007ae0d0(int param_1,int *param_2)

{
  int *piVar1;
  char cVar2;
  undefined4 unaff_EBX;
  int iVar3;
  undefined4 unaff_ESI;
  undefined4 uVar4;
  int *piVar5;
  undefined1 *puStack_38;
  undefined1 *puStack_34;
  int iStack_30;
  undefined4 *puStack_2c;
  undefined4 uStack_1c;
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [12];
  undefined1 auStack_8 [8];
  
  piVar1 = param_2;
  puStack_34 = auStack_18;
  puStack_2c = &param_2;
  iStack_30 = 4;
  puStack_38 = (undefined1 *)0x7ae0ef;
  cVar2 = (**(code **)(*param_2 + 0x10))();
  if (cVar2 != '\0') {
    puStack_38 = auStack_8;
    cVar2 = (**(code **)(*piVar1 + 0x10))(&stack0xffffffe0,4);
    if (cVar2 != '\0') {
      if ((iStack_30 == 0x5354434b) && (puStack_2c == (undefined4 *)0x1)) {
        cVar2 = (**(code **)(*piVar1 + 0x10))(&stack0xffffffd8,0x10,auStack_14);
        if (cVar2 != '\0') {
          *(undefined4 *)(param_1 + 0x18) = unaff_ESI;
          piVar5 = piVar1 + 0x43;
          *(undefined4 *)(param_1 + 0x1c) = unaff_EBX;
          *(undefined4 *)(param_1 + 0x20) = uStack_1c;
          func_0x007adf90(piVar5);
          iVar3 = 0;
          if (0 < (int)puStack_2c) {
            do {
              cVar2 = (**(code **)(*piVar1 + 0x10))(&puStack_38,4,auStack_18);
              if (cVar2 == '\0') {
                return 0;
              }
              cVar2 = FUN_007ae200(piVar1,piVar5);
              if (cVar2 == '\0') {
                func_0x007647d0(0x9d2f20,0x98df34,puStack_38);
                return 0;
              }
              iVar3 = iVar3 + 1;
            } while (iVar3 < (int)puStack_2c);
          }
          return 1;
        }
        uVar4 = 0x98df70;
      }
      else {
        uVar4 = 0x98df00;
      }
      func_0x007647d0(0x9d2f20,uVar4);
    }
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x007ae200 | Classified: elementclient::A3DSklTrackSet__LoadBoneTrack__F@0x7ae200 */
/* ==================================================================== */

undefined4 FUN_007ae200(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int unaff_ESI;
  undefined4 *unaff_FS_OFFSET;
  int *unaff_retaddr;
  undefined4 uVar7;
  undefined4 uStack_3c;
  int iStack_28;
  int iStack_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [8];
  undefined4 uStack_14;
  undefined4 uStack_10;
  int *piStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cda2b;
  piStack_c = (int *)*unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &piStack_c;
  uStack_3c = param_2;
  iVar2 = func_0x007adfc0();
  if (iVar2 == 0) {
    puVar3 = (undefined4 *)func_0x00763250(0x2c);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      *puVar3 = &UNK_008f1c80;
      puVar3[1] = 2;
      puVar3[6] = 0x1e;
      puVar3[5] = 0;
      puVar3[7] = 0;
      puVar3[4] = 1;
      puVar3[2] = 0;
      puVar3[3] = 0;
      puVar3[8] = 0;
      puVar3[9] = 0;
      puVar3[10] = 0;
    }
    puVar4 = (undefined4 *)func_0x00763250(0x2c);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4[4] = 1;
      *puVar4 = &UNK_008f1c7c;
      puVar4[1] = 2;
      puVar4[6] = 0x1e;
      puVar4[5] = 0;
      puVar4[7] = 0;
      puVar4[2] = 0;
      puVar4[3] = 0;
      puVar4[8] = 0;
      puVar4[9] = 0;
      puVar4[10] = 0;
    }
    cVar1 = (**(code **)(*unaff_retaddr + 0x10))(auStack_1c,0xc,&iStack_28);
    if ((cVar1 == '\0') || (unaff_ESI != 0xc)) {
      uVar7 = 0x98e0c0;
      goto LAB_007ae501;
    }
    if (puVar3 == (undefined4 *)0x0) {
LAB_007ae4fc:
      uVar7 = 0x98dfa4;
    }
    else {
      puVar3[5] = iStack_28;
      puVar3[9] = iStack_24;
      iVar2 = iStack_24 * 0x10;
      puVar3[6] = uStack_20;
      puVar3[10] = iVar2 + iStack_28 * 0xc;
      iVar5 = func_0x00763250(iStack_28 * 0xc);
      puVar3[7] = iVar5;
      if (iVar5 == 0) goto LAB_007ae4fc;
      iVar2 = func_0x00763250(iVar2);
      puVar3[8] = iVar2;
      if (iVar2 == 0) goto LAB_007ae4fc;
      cVar1 = (**(code **)(*piStack_c + 0x10))(puVar3[7],puVar3[5] * 0xc,&stack0xffffffcc);
      if ((cVar1 == '\0') ||
         (cVar1 = (**(code **)(*piStack_c + 0x10))(puVar3[8],puVar3[9] << 4,&stack0xffffffcc),
         cVar1 == '\0')) {
        uVar7 = 0x98e078;
      }
      else {
        cVar1 = (**(code **)(*piStack_c + 0x10))(&iStack_28,0xc,&stack0xffffffcc);
        if (cVar1 == '\0') {
          uVar7 = 0x98e028;
        }
        else {
          if (puVar4 != (undefined4 *)0x0) {
            puVar4[6] = uStack_20;
            puVar4[5] = iStack_28;
            puVar4[9] = iStack_24;
            puVar4[10] = (iStack_28 + iStack_24) * 0x10;
            iVar2 = func_0x00763250(iStack_28 << 4);
            uStack_14 = 0;
            if (iVar2 == 0) {
              iVar2 = 0;
            }
            else {
              func_0x00401e10(iVar2,0x10,iStack_28,FUN_0041b5b0);
            }
            uStack_14 = 0xffffffff;
            puVar4[7] = iVar2;
            if (iVar2 != 0) {
              iVar2 = func_0x00763250(iStack_24 << 4);
              puVar4[8] = iVar2;
              if (iVar2 != 0) {
                puVar4[1] = 3;
                cVar1 = (**(code **)(*piStack_c + 0x10))(puVar4[7],puVar4[5] << 4,&stack0xffffffd0);
                if ((cVar1 != '\0') &&
                   (cVar1 = (**(code **)(*piStack_c + 0x10))
                                      (puVar4[8],puVar4[9] << 4,&stack0xffffffd0), cVar1 != '\0')) {
                  puVar6 = (undefined4 *)func_0x00763250(0x10);
                  if (puVar6 != (undefined4 *)0x0) {
                    *puVar6 = 0;
                    puVar6[1] = 0;
                    puVar6[2] = 0;
                    puVar6[3] = 0;
                    iRam00000014 = puVar4[10] + iRam00000014 + puVar3[10];
                    *puVar6 = puVar3;
                    puVar6[1] = puVar4;
                    FUN_007aefc0(iRam00000028 + 1);
                    func_0x0064c9f0(&piStack_c,&uStack_3c);
                    uVar7 = 1;
                    goto LAB_007ae510;
                  }
                  (**(code **)*puVar3)(1);
                  (**(code **)*puVar4)(1);
                  goto LAB_007ae50e;
                }
                uVar7 = 0x98e078;
                goto LAB_007ae501;
              }
            }
          }
          uVar7 = 0x98dfe4;
        }
      }
    }
LAB_007ae501:
    func_0x007647d0(0x9d2f20,uVar7);
  }
LAB_007ae50e:
  uVar7 = 0;
LAB_007ae510:
  *unaff_FS_OFFSET = uStack_10;
  return uVar7;
}


/* ==================================================================== */
/* Address: 0x007ae530 | Classified: Angelica3D::proc_7ae530 */
/* ==================================================================== */

void __fastcall FUN_007ae530(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007ae540 | Classified: Angelica3D::proc_7ae540 */
/* ==================================================================== */

void __thiscall FUN_007ae540(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_3;
  FUN_007ae560(0);
  return;
}


/* ==================================================================== */
/* Address: 0x007ae560 | Classified: Angelica3D::proc_7ae560 */
/* ==================================================================== */

void __thiscall FUN_007ae560(int *param_1,int param_2)

{
  param_2 = *param_1 + param_2;
  *param_1 = param_2;
  if (param_1[1] <= param_2) {
    *(undefined1 *)(param_1 + 3) = 1;
  }
  if (param_2 < param_1[2]) {
    *(undefined1 *)(param_1 + 3) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007ae590 | Classified: Angelica3D::proc_7ae590 */
/* ==================================================================== */

undefined4 * __fastcall FUN_007ae590(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cda56;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1[2] = 0;
  iVar2 = 0;
  do {
    if (0x400 < *(uint *)(&UNK_008f1c08 + iVar2 * 4)) {
      iVar2 = *(int *)(&UNK_008f1c08 + iVar2 * 4);
      goto LAB_007ae5cd;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x1c);
  iVar2 = -1;
LAB_007ae5cd:
  param_1[5] = iVar2;
  if (iVar2 == 0) {
    param_1[3] = 0;
  }
  else {
    uVar3 = func_0x00763250(iVar2 * 4);
    param_1[3] = uVar3;
  }
  param_1[4] = param_1[3];
  param_1[6] = iVar2;
  for (; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = (undefined4 *)param_1[4];
    param_1[4] = puVar1 + 1;
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = 0;
    }
  }
  param_1[7] = &UNK_008f1c88;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 10;
  param_1[0xd] = 0;
  uStack_4 = 1;
  FUN_007ae530();
  *param_1 = &UNK_008f1c84;
  param_1[0x1a] = 0;
  FUN_007ae540(0x1000000,0xe00000);
  InitializeCriticalSection(param_1 + 0xe);
  InitializeCriticalSection(param_1 + 0x14);
  *unaff_FS_OFFSET = unaff_EDI;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007ae690 | Classified: Angelica3D::proc_7ae690 */
/* ==================================================================== */

undefined4 __thiscall FUN_007ae690(undefined4 param_1,byte param_2)

{
  FUN_007ae6b0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007ae6b0 | Classified: Angelica3D::proc_7ae6b0 */
/* ==================================================================== */

void __fastcall FUN_007ae6b0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint unaff_EBX;
  uint uVar7;
  uint *unaff_FS_OFFSET;
  uint uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008cda76;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (uint)&uStack_c;
  *param_1 = &UNK_008f1c84;
  uStack_4 = 1;
  FUN_007ae7f0();
  DeleteCriticalSection(param_1 + 0xe);
  DeleteCriticalSection(param_1 + 0x14);
  puVar1 = (undefined4 *)param_1[8];
  uStack_c = uStack_c & 0xffffff00;
  param_1[7] = &UNK_008f1c88;
  while (puVar1 != (undefined4 *)0x0) {
    param_1[8] = *puVar1;
    *puVar1 = param_1[10];
    param_1[10] = puVar1;
    puVar1 = (undefined4 *)param_1[8];
    param_1[0xb] = param_1[0xb] + -1;
  }
  puVar1 = (undefined4 *)param_1[0xd];
  param_1[9] = 0;
  param_1[0xb] = 0;
  while (puVar1 != (undefined4 *)0x0) {
    param_1[0xd] = puVar1[1];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    puVar1 = (undefined4 *)param_1[0xd];
  }
  uVar7 = 0;
  if (param_1[6] != 0) {
    do {
      puVar1 = *(undefined4 **)(param_1[3] + uVar7 * 4);
      while (puVar1 != (undefined4 *)0x0) {
        puVar2 = (undefined4 *)*puVar1;
        func_0x00763260(puVar1);
        puVar1 = puVar2;
      }
      uVar7 = uVar7 + 1;
      *(undefined4 *)(param_1[3] + -4 + uVar7 * 4) = 0;
    } while (uVar7 < (uint)param_1[6]);
  }
  param_1[2] = 0;
  puVar2 = (undefined4 *)param_1[3];
  puVar1 = puVar2 + param_1[6];
  if (puVar2 != puVar1) {
    puVar3 = puVar1;
    puVar6 = puVar2;
    if (puVar1 < (undefined4 *)param_1[4]) {
      do {
        puVar4 = puVar3 + 1;
        *puVar6 = *puVar3;
        puVar3 = puVar4;
        puVar6 = puVar6 + 1;
      } while (puVar4 < (undefined4 *)param_1[4]);
    }
    iVar5 = (int)puVar1 - (int)puVar2 >> 2;
    param_1[4] = param_1[4] + iVar5 * -4;
    param_1[6] = param_1[6] - iVar5;
  }
  if (param_1[3] != 0) {
    func_0x00763260(param_1[3]);
  }
  *unaff_FS_OFFSET = unaff_EBX;
  return;
}


/* ==================================================================== */
/* Address: 0x007ae7f0 | Classified: elementclient::A3DTrackMan__Release___d_skeleto@0x7ae7f0 */
/* ==================================================================== */

void __fastcall FUN_007ae7f0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  int *piVar4;
  int unaff_EBX;
  int iVar5;
  uint uVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 *puStack_24;
  int *piStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cda88;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  EnterCriticalSection(param_1 + 0x38);
  puStack_8 = (undefined *)0x0;
  iVar5 = param_1 + 0x38;
  if (*(int *)(param_1 + 8) != 0) {
    func_0x007647d0(0x9d2f20,0x98e168,*(int *)(param_1 + 8));
    func_0x0077bef0((int *)(param_1 + 4));
    iStack_1c = 0;
    uStack_18 = 0;
    piStack_20 = (int *)(param_1 + 4);
    cVar3 = FUN_007aef80(&piStack_20);
    while (cVar3 == '\0') {
      if (puStack_24 == (undefined4 *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = piStack_20 + 1;
      }
      if ((undefined4 *)*piVar4 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar4)(1);
      }
      if (puStack_24 != (undefined4 *)0x0) {
        if (piStack_20 == (int *)0x0) goto LAB_007ae8a2;
        piStack_20 = (int *)*piStack_20;
        while (piStack_20 == (int *)0x0) {
LAB_007ae8a2:
          puStack_24 = puStack_24 + 1;
          if (puStack_24 == (undefined4 *)(*(int *)(param_1 + 0x40) + *(int *)(param_1 + 0x4c) * 4))
          {
            puStack_24 = (undefined4 *)0x0;
            break;
          }
          piStack_20 = (int *)*puStack_24;
        }
      }
      iStack_1c = param_1 + 4;
      uStack_18 = 0;
      uStack_14 = 0;
      cVar3 = FUN_007aef80(&iStack_1c);
    }
    uVar6 = 0;
    if (*(int *)(param_1 + 0x18) != 0) {
      do {
        puVar2 = *(undefined4 **)(*(int *)(param_1 + 0xc) + uVar6 * 4);
        while (puVar2 != (undefined4 *)0x0) {
          puVar1 = (undefined4 *)*puVar2;
          func_0x00763260(puVar2);
          puVar2 = puVar1;
        }
        *(undefined4 *)(*(int *)(param_1 + 0xc) + uVar6 * 4) = 0;
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(param_1 + 0x18));
    }
    *(undefined4 *)(param_1 + 8) = 0;
    iVar5 = unaff_EBX;
  }
  if (iVar5 != 0) {
    LeaveCriticalSection(iVar5);
  }
  iVar5 = param_1 + 0x50;
  EnterCriticalSection(iVar5);
  if (*(int *)(param_1 + 0x2c) != 0) {
    func_0x007647d0(0x9d2f20,0x98e110,*(int *)(param_1 + 0x2c));
    puVar2 = *(undefined4 **)(param_1 + 0x20);
    while (puVar2 != (undefined4 *)0x0) {
      *(undefined4 *)(param_1 + 0x20) = *puVar2;
      *puVar2 = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 **)(param_1 + 0x28) = puVar2;
      puVar2 = *(undefined4 **)(param_1 + 0x20);
      *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + -1;
    }
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  if (iVar5 != 0) {
    LeaveCriticalSection(iVar5);
  }
  *unaff_FS_OFFSET = uStack_14;
  return;
}


/* ==================================================================== */
/* Address: 0x007ae9b0 | Classified: elementclient::A3DTrackMan__CreateTrackSet__Fai@0x7ae9b0 */
/* ==================================================================== */

undefined4 * __thiscall FUN_007ae9b0(int param_1,undefined1 *param_2)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *unaff_EDI;
  undefined4 *puVar7;
  uint *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  uint uStack_18;
  uint uStack_c;
  undefined *puStack_8;
  uint uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cdabb;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (uint)&uStack_c;
  puVar7 = (undefined4 *)(param_1 + 0x38);
  EnterCriticalSection(puVar7);
  puStack_8 = (undefined *)0x0;
  puVar4 = (undefined4 *)FUN_007aeb90(unaff_retaddr,param_2);
  if (puVar4 == (undefined4 *)0x0) {
    uStack_4 = func_0x00763250(0x3c);
    if (uStack_4 == 0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = (undefined4 *)func_0x007adcb0(unaff_retaddr);
    }
    if (puVar4 != (undefined4 *)0x0) {
      if ((char)unaff_retaddr == '\0') {
        cVar3 = func_0x007adff0(param_2);
        if (cVar3 == '\0') {
          if (unaff_EDI != (undefined4 *)0x0) {
            (**(code **)*unaff_EDI)(1);
          }
          func_0x007647d0(0x9d2f20,0x98e1b0,param_2);
          goto LAB_007aeb4f;
        }
        FUN_007ae560(unaff_EDI[5]);
      }
      else {
        func_0x007adf90();
      }
      uVar1 = *(uint *)(param_1 + 0x18);
      uVar5 = *(int *)(param_1 + 8) + 1;
      if ((uVar1 < uVar5) && (uStack_4 = func_0x00404700(uVar5), uVar1 < uStack_4)) {
        uVar5 = 0;
        puStack_8 = (undefined *)0x0;
        func_0x007ab5e0(uStack_4,&puStack_8);
        if (uVar1 != 0) {
          iVar6 = *(int *)(param_1 + 0xc);
          do {
            puVar7 = *(undefined4 **)(iVar6 + uVar5 * 4);
            while (puVar7 != (undefined4 *)0x0) {
              uVar2 = puVar7[2];
              *(undefined4 *)(iVar6 + uVar5 * 4) = *puVar7;
              *puVar7 = unaff_EDI[uVar2 % uStack_c];
              unaff_EDI[uVar2 % uStack_c] = puVar7;
              iVar6 = *(int *)(param_1 + 0xc);
              puVar7 = *(undefined4 **)(iVar6 + uVar5 * 4);
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < uVar1);
        }
        func_0x004bb3b0(&stack0xffffffcc);
        func_0x007ab460();
        puVar7 = puVar4;
      }
      cVar3 = func_0x0064c9f0(&uStack_c,&stack0xffffffcc);
      if (cVar3 != '\0') {
        *param_2 = 1;
        goto LAB_007aeb65;
      }
      if (puVar4 != (undefined4 *)0x0) {
        (**(code **)*puVar4)(1);
      }
    }
LAB_007aeb4f:
    if (puVar7 != (undefined4 *)0x0) {
      LeaveCriticalSection(puVar7);
    }
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4[4] = puVar4[4] + 1;
    *param_2 = 0;
LAB_007aeb65:
    if (puVar7 != (undefined4 *)0x0) {
      LeaveCriticalSection(puVar7);
    }
  }
  *unaff_FS_OFFSET = uStack_18;
  return puVar4;
}


/* ==================================================================== */
/* Address: 0x007aeb90 | Classified: Angelica3D::proc_7aeb90 */
/* ==================================================================== */

int __thiscall FUN_007aeb90(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint unaff_retaddr;
  
  iVar1 = param_1 + 0x38;
  EnterCriticalSection(iVar1);
  puVar2 = *(undefined4 **)
            (*(int *)(param_1 + 0xc) + (unaff_retaddr % *(uint *)(param_1 + 0x18)) * 4);
  do {
    if (puVar2 == (undefined4 *)0x0) {
LAB_007aebd9:
      if (iVar1 != 0) {
        LeaveCriticalSection(iVar1);
      }
      return 0;
    }
    if (puVar2[2] == unaff_retaddr) {
      iVar3 = puVar2[1];
      iVar4 = _stricmp(*(undefined4 *)(iVar3 + 4),param_2);
      if (iVar4 == 0) {
        if (iVar1 != 0) {
          LeaveCriticalSection(iVar1);
        }
        return iVar3;
      }
      goto LAB_007aebd9;
    }
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}


/* ==================================================================== */
/* Address: 0x007aec00 | Classified: Angelica3D::proc_7aec00 */
/* ==================================================================== */

void __thiscall FUN_007aec00(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  int unaff_EBP;
  int iVar8;
  int unaff_EDI;
  int *unaff_FS_OFFSET;
  uint unaff_retaddr;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cdad8;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  iVar8 = param_1 + 0x38;
  EnterCriticalSection(iVar8);
  puStack_8 = (undefined *)0x0;
  puVar6 = (undefined4 *)FUN_007aeb90(unaff_retaddr,param_2);
  if ((puVar6 != (undefined4 *)0x0) && (iVar1 = puVar6[4], puVar6[4] = iVar1 + -1, iVar1 + -1 < 1))
  {
    FUN_007ae560(-puVar6[5]);
    uVar7 = unaff_retaddr % *(uint *)(param_1 + 0x18);
    puVar2 = *(undefined4 **)(*(int *)(param_1 + 0xc) + uVar7 * 4);
    puVar5 = puVar2;
    puVar4 = (undefined4 *)0x0;
    while (puVar3 = puVar5, puVar3 != (undefined4 *)0x0) {
      iVar8 = unaff_EDI;
      if (puVar3[2] == iStack_c) {
        if (puVar3 == puVar2) {
          *(undefined4 *)(*(int *)(param_1 + 0xc) + uVar7 * 4) = *puVar3;
        }
        else {
          *puVar4 = *puVar3;
        }
        func_0x00763260(puVar3);
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
        break;
      }
      puVar4 = puVar3;
      puVar5 = (undefined4 *)*puVar3;
    }
    (**(code **)*puVar6)(1);
  }
  if (iVar8 != 0) {
    LeaveCriticalSection(iVar8);
  }
  *unaff_FS_OFFSET = unaff_EBP;
  return;
}


/* ==================================================================== */
/* Address: 0x007aece0 | Classified: elementclient::A3DTrackMan__CreateMorphChannelW@0x7aece0 */
/* ==================================================================== */

undefined4 * __thiscall
FUN_007aece0(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int unaff_EBX;
  int *unaff_FS_OFFSET;
  int unaff_retaddr;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cdb03;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  iVar1 = param_1 + 0x50;
  EnterCriticalSection(iVar1);
  puStack_8 = (undefined *)0x0;
  puVar3 = *(undefined4 **)(param_1 + 0x20);
  do {
    puVar6 = puVar3;
    if (puVar6 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)func_0x00763250(0x2c);
      iVar5 = iVar1;
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = &UNK_008f1c8c;
        puVar3[1] = 2;
        puVar3[6] = 0x1e;
        puVar3[5] = 0;
        puVar3[7] = 0;
        puVar3[4] = 1;
        puVar3[2] = 0;
        puVar3[3] = 0;
        puVar3[8] = 0;
        puVar3[9] = 0;
        puVar3[10] = 0;
        puVar3[5] = param_3;
        puVar3[9] = param_5;
        puVar3[6] = param_4;
        puVar3[10] = (param_3 + param_5 * 4) * 4;
        iVar4 = func_0x00763250(param_3 << 2);
        puVar3[7] = iVar4;
        iVar5 = unaff_EBX;
        if (iVar4 != 0) {
          iVar4 = func_0x00763250(param_5 << 4);
          puVar3[8] = iVar4;
          if (iVar4 != 0) {
            if (*(int *)(param_1 + 0x28) == 0) {
              iVar5 = func_0x00763250(0x10);
              puStack_8._0_1_ = 1;
              if (iVar5 == 0) {
                iVar5 = 0;
              }
              else {
                iVar5 = FUN_007af2a0(*(undefined4 *)(param_1 + 0x30));
              }
              puStack_8 = (undefined *)((uint)puStack_8._1_3_ << 8);
              if (iVar5 != 0) {
                *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(iVar5 + 8);
                *(undefined4 *)(iVar5 + 4) = *(undefined4 *)(param_1 + 0x34);
                *(int *)(param_1 + 0x34) = iVar5;
                goto LAB_007aee3b;
              }
              func_0x00764590(1,0x950554);
              puVar6 = (undefined4 *)0x0;
            }
            else {
LAB_007aee3b:
              puVar6 = *(undefined4 **)(param_1 + 0x28);
              uVar2 = *puVar6;
              *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
              *(undefined4 *)(param_1 + 0x28) = uVar2;
              *puVar6 = 0;
              puVar6[1] = 0;
            }
            puVar6[2] = unaff_retaddr;
            puVar6[3] = param_2;
            puVar6[4] = puVar3;
            puVar6[1] = *(undefined4 *)(param_1 + 0x24);
            if (*(undefined4 **)(param_1 + 0x24) == (undefined4 *)0x0) {
              *(undefined4 **)(param_1 + 0x20) = puVar6;
            }
            else {
              **(undefined4 **)(param_1 + 0x24) = puVar6;
            }
            *(undefined4 **)(param_1 + 0x24) = puVar6;
            puVar3[2] = puVar6;
            *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + puVar3[10];
            if (unaff_EBX != 0) {
              LeaveCriticalSection(unaff_EBX);
            }
            goto LAB_007aeebe;
          }
        }
      }
      func_0x007647d0(0x9d2f20,0x98e1f0);
      if (iVar5 != 0) {
        LeaveCriticalSection(iVar5);
      }
      puVar3 = (undefined4 *)0x0;
      goto LAB_007aeebe;
    }
    puVar3 = (undefined4 *)*puVar6;
  } while ((puVar6[2] != unaff_retaddr) || (puVar6[3] != param_2));
  puVar3 = (undefined4 *)puVar6[4];
  puVar3[4] = puVar3[4] + 1;
  if (iVar1 != 0) {
    LeaveCriticalSection(iVar1);
  }
LAB_007aeebe:
  *unaff_FS_OFFSET = iVar1;
  return puVar3;
}


/* ==================================================================== */
/* Address: 0x007aeee0 | Classified: Angelica3D::proc_7aeee0 */
/* ==================================================================== */

void __fastcall FUN_007aeee0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  uVar7 = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    do {
      puVar2 = *(undefined4 **)(*(int *)(param_1 + 8) + uVar7 * 4);
      while (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar2;
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
  return;
}


/* ==================================================================== */
/* Address: 0x007aef80 | Classified: Angelica3D::proc_7aef80 */
/* ==================================================================== */

undefined4 __thiscall FUN_007aef80(int *param_1,int *param_2)

{
  if ((((*param_1 == 0) || (*param_2 == 0)) || (*param_1 == *param_2)) &&
     ((param_1[1] == param_2[1] && (param_1[2] == param_2[2])))) {
    return 1;
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x007aefc0 | Classified: Angelica3D::proc_7aefc0 */
/* ==================================================================== */

void __thiscall FUN_007aefc0(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  if (uVar1 < param_2) {
    iVar4 = 0;
    do {
      if (param_2 < *(uint *)(&UNK_008f1c08 + iVar4 * 4)) {
        param_2 = *(uint *)(&UNK_008f1c08 + iVar4 * 4);
        goto LAB_007aeff7;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x1c);
    param_2 = 0xffffffff;
LAB_007aeff7:
    if (uVar1 < param_2) {
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
      if (uVar1 != 0) {
        iVar4 = *(int *)(param_1 + 8);
        do {
          puVar7 = *(undefined4 **)(iVar4 + uVar6 * 4);
          while (puVar7 != (undefined4 *)0x0) {
            uVar2 = puVar7[2];
            *(undefined4 *)(iVar4 + uVar6 * 4) = *puVar7;
            *puVar7 = puVar5[uVar2 % param_2];
            puVar5[uVar2 % param_2] = puVar7;
            iVar4 = *(int *)(param_1 + 8);
            puVar7 = *(undefined4 **)(iVar4 + uVar6 * 4);
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar1);
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
/* Address: 0x007af0e0 | Classified: Angelica3D::proc_7af0e0 */
/* ==================================================================== */

void __fastcall FUN_007af0e0(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[1];
  *param_1 = &UNK_008f1c88;
  while (puVar1 != (undefined4 *)0x0) {
    param_1[1] = *puVar1;
    *puVar1 = param_1[3];
    param_1[3] = puVar1;
    puVar1 = (undefined4 *)param_1[1];
    param_1[4] = param_1[4] + -1;
  }
  puVar1 = (undefined4 *)param_1[6];
  param_1[2] = 0;
  param_1[4] = 0;
  while (puVar1 != (undefined4 *)0x0) {
    param_1[6] = puVar1[1];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    puVar1 = (undefined4 *)param_1[6];
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007af140 | Classified: Angelica3D::proc_7af140 */
/* ==================================================================== */

undefined4 * __thiscall FUN_007af140(undefined4 *param_1,byte param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[1];
  *param_1 = &UNK_008f1c88;
  while (puVar1 != (undefined4 *)0x0) {
    param_1[1] = *puVar1;
    *puVar1 = param_1[3];
    param_1[3] = puVar1;
    puVar1 = (undefined4 *)param_1[1];
    param_1[4] = param_1[4] + -1;
  }
  puVar1 = (undefined4 *)param_1[6];
  param_1[2] = 0;
  param_1[4] = 0;
  while (puVar1 != (undefined4 *)0x0) {
    param_1[6] = puVar1[1];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    puVar1 = (undefined4 *)param_1[6];
  }
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007af1b0 | Classified: Angelica3D::proc_7af1b0 */
/* ==================================================================== */

undefined4 * __thiscall FUN_007af1b0(undefined4 *param_1,byte param_2)

{
  *param_1 = &UNK_008f1c80;
  if (param_1[7] != 0) {
    func_0x00763260(param_1[7]);
    param_1[7] = 0;
  }
  if (param_1[8] != 0) {
    func_0x00763260(param_1[8]);
    param_1[8] = 0;
  }
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007af200 | Classified: Angelica3D::proc_7af200 */
/* ==================================================================== */

undefined4 * __thiscall FUN_007af200(undefined4 *param_1,byte param_2)

{
  *param_1 = &UNK_008f1c7c;
  if (param_1[7] != 0) {
    func_0x00763260(param_1[7]);
    param_1[7] = 0;
  }
  if (param_1[8] != 0) {
    func_0x00763260(param_1[8]);
    param_1[8] = 0;
  }
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007af250 | Classified: Angelica3D::proc_7af250 */
/* ==================================================================== */

undefined4 * __thiscall FUN_007af250(undefined4 *param_1,byte param_2)

{
  *param_1 = &UNK_008f1c8c;
  if (param_1[7] != 0) {
    func_0x00763260(param_1[7]);
    param_1[7] = 0;
  }
  if (param_1[8] != 0) {
    func_0x00763260(param_1[8]);
    param_1[8] = 0;
  }
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007af2a0 | Classified: Angelica3D::proc_7af2a0 */
/* ==================================================================== */

undefined4 * __thiscall FUN_007af2a0(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  *param_1 = &UNK_008f1c90;
  param_1[3] = param_2;
  uVar1 = func_0x00763250(param_2 * 0x14);
  iVar3 = param_2 + -1;
  param_1[2] = uVar1;
  if (0 < iVar3) {
    iVar2 = 0;
    do {
      *(int *)(iVar2 + param_1[2]) = iVar2 + 0x14 + param_1[2];
      iVar2 = iVar2 + 0x14;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  *(undefined4 *)(param_2 * 0x14 + -0x14 + param_1[2]) = 0;
  param_1[1] = 0;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007af300 | Classified: Angelica3D::proc_7af300 */
/* ==================================================================== */

undefined4 * __thiscall FUN_007af300(undefined4 *param_1,byte param_2)

{
  *param_1 = &UNK_008f1c90;
  if (param_1[2] != 0) {
    func_0x00763260(param_1[2]);
  }
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007af330 | Classified: Angelica3D::proc_7af330 */
/* ==================================================================== */

undefined4 * __fastcall FUN_007af330(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = 0;
  param_1[4] = 0;
  do {
    if (0x100 < *(uint *)(&UNK_008f1c98 + iVar2 * 4)) {
      iVar2 = *(int *)(&UNK_008f1c98 + iVar2 * 4);
      goto LAB_007af353;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x1c);
  iVar2 = -1;
LAB_007af353:
  param_1[7] = iVar2;
  if (iVar2 == 0) {
    param_1[5] = 0;
  }
  else {
    uVar3 = func_0x00763250(iVar2 * 4);
    param_1[5] = uVar3;
  }
  param_1[6] = param_1[5];
  param_1[8] = iVar2;
  for (; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = (undefined4 *)param_1[6];
    param_1[6] = puVar1 + 1;
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = 0;
    }
  }
  *param_1 = &UNK_008f1d08;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  InitializeCriticalSection(param_1 + 9);
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007af3c0 | Classified: Angelica3D::proc_7af3c0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007af3c0(undefined4 param_1,byte param_2)

{
  FUN_007af3e0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007af3e0 | Classified: Angelica3D::proc_7af3e0 */
/* ==================================================================== */

void __fastcall FUN_007af3e0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  *param_1 = &UNK_008f1d08;
  DeleteCriticalSection(param_1 + 9);
  uVar7 = 0;
  if (param_1[8] != 0) {
    do {
      puVar2 = *(undefined4 **)(param_1[5] + uVar7 * 4);
      while (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar2;
        func_0x00763260(puVar2);
        puVar2 = puVar1;
      }
      uVar7 = uVar7 + 1;
      *(undefined4 *)(param_1[5] + -4 + uVar7 * 4) = 0;
    } while (uVar7 < (uint)param_1[8]);
  }
  param_1[4] = 0;
  puVar1 = (undefined4 *)param_1[5];
  puVar2 = puVar1 + param_1[8];
  if (puVar1 != puVar2) {
    puVar3 = puVar2;
    puVar6 = puVar1;
    if (puVar2 < (undefined4 *)param_1[6]) {
      do {
        puVar4 = puVar3 + 1;
        *puVar6 = *puVar3;
        puVar3 = puVar4;
        puVar6 = puVar6 + 1;
      } while (puVar4 < (undefined4 *)param_1[6]);
    }
    iVar5 = (int)puVar2 - (int)puVar1 >> 2;
    param_1[6] = param_1[6] + iVar5 * -4;
    param_1[8] = param_1[8] - iVar5;
  }
  if (param_1[5] != 0) {
    func_0x00763260(param_1[5]);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007af490 | Classified: Angelica3D::proc_7af490 */
/* ==================================================================== */

undefined4 __thiscall FUN_007af490(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 4) = param_2;
  uVar1 = *(undefined4 *)(param_2 + 0x50);
  *(undefined4 *)(param_1 + 8) = uVar1;
  return CONCAT31((int3)((uint)uVar1 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007af4b0 | Classified: Angelica3D::proc_7af4b0 */
/* ==================================================================== */

/* WARNING: Removing unreachable block (ram,0x007af597) */

void __fastcall FUN_007af4b0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int unaff_EBX;
  uint uVar8;
  undefined4 *unaff_FS_OFFSET;
  int *piStack_18;
  int *piStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cdb18;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  EnterCriticalSection(param_1 + 0x24);
  piVar6 = (int *)0x0;
  piStack_14 = (int *)0x0;
  piVar7 = *(int **)(param_1 + 0x14);
  puStack_8 = (undefined *)0x0;
  if (piVar7 == (int *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x20) * 4)) goto LAB_007af52e;
  piVar6 = (int *)*piVar7;
  piStack_18 = piVar7;
  piStack_14 = piVar6;
  if (piVar6 == (int *)0x0) {
    FUN_00793ff0();
  }
LAB_007af534:
  do {
    do {
      if (piVar7 == (int *)0x0) {
        if (piVar6 == (int *)0x0) {
          uVar8 = 0;
          if (*(int *)(param_1 + 0x20) != 0) {
            do {
              puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x14) + uVar8 * 4);
              while (puVar3 != (undefined4 *)0x0) {
                puVar2 = (undefined4 *)*puVar3;
                func_0x00763260(puVar3);
                puVar3 = puVar2;
              }
              uVar8 = uVar8 + 1;
              *(undefined4 *)(*(int *)(param_1 + 0x14) + -4 + uVar8 * 4) = 0;
            } while (uVar8 < *(uint *)(param_1 + 0x20));
          }
          *(undefined4 *)(param_1 + 0x10) = 0;
          if (*(int *)(unaff_EBX + 0x40) != 0) {
            func_0x00785220();
            if (*(undefined4 **)(unaff_EBX + 0x40) != (undefined4 *)0x0) {
              (**(code **)**(undefined4 **)(unaff_EBX + 0x40))(1);
            }
            *(undefined4 *)(unaff_EBX + 0x40) = 0;
          }
          if (param_1 != 0) {
            LeaveCriticalSection(param_1);
          }
          *unaff_FS_OFFSET = uStack_10;
          return;
        }
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = piVar6 + 1;
      }
      iVar4 = *piVar5;
      while (iVar4 != 0) {
        iVar1 = *(int *)(iVar4 + 4);
        FUN_007afe20(iVar4);
        iVar4 = iVar1;
        piVar6 = piStack_14;
        piVar7 = piStack_18;
      }
    } while ((piVar7 == (int *)0x0) ||
            ((piVar6 != (int *)0x0 &&
             (piVar6 = (int *)*piVar6, piStack_14 = piVar6, piVar6 != (int *)0x0))));
    do {
      piVar7 = piVar7 + 1;
      if (piVar7 == (int *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x20) * 4))
      goto LAB_007af52e;
      piVar6 = (int *)*piVar7;
      piStack_18 = piVar7;
      piStack_14 = piVar6;
    } while (piVar6 == (int *)0x0);
  } while( true );
LAB_007af52e:
  piVar7 = (int *)0x0;
  piStack_18 = (int *)0x0;
  goto LAB_007af534;
}


/* ==================================================================== */
/* Address: 0x007af630 | Classified: elementclient::A3DSkinMeshMan__LoadMeshObject__d@0x7af630 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_007af630(int param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int unaff_ESI;
  uint *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  char cStack_2c;
  int *piStack_20;
  uint uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  puStack_8 = &UNK_008cdb82;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (uint)&uStack_c;
  uVar1 = param_1 + 0x24;
  uStack_44 = 0x7af660;
  uStack_40 = uVar1;
  EnterCriticalSection();
  puStack_8 = (undefined *)0x0;
  uStack_48 = *(undefined4 *)(param_2 + 0x130);
  uStack_44 = *(undefined4 *)(param_2 + 0x18);
  puVar3 = (undefined4 *)FUN_007afd60();
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)func_0x00763250(0x98);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      *puVar3 = _DAT_009858e4;
      FUN_007b0510();
      FUN_007b0570();
      FUN_007b05d0();
      FUN_007b0630();
      FUN_007b0690();
      FUN_007b06f0();
    }
    if (puVar3 != (undefined4 *)0x0) {
      func_0x007638a0(*(undefined4 *)(iStack_4 + 0x18));
      *(undefined4 *)(unaff_ESI + 4) = 0;
      iVar4 = func_0x004322c0(&stack0xffffffd0);
      puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x14) + iVar4 * 4);
      for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
        if ((undefined4 *)puVar2[2] == puVar3) {
          uStack_40 = CONCAT13(1,(undefined3)uStack_40);
          goto LAB_007af75f;
        }
      }
      uStack_40 = uStack_40 & 0xffffff;
LAB_007af75f:
      func_0x004445b0(&stack0xffffffd0,(int)&uStack_40 + 3);
      if (cStack_2c == '\0') {
        FUN_007b0810(*(int *)(param_1 + 0x10) + 1);
        func_0x0064c9f0(&uStack_40,&uStack_48);
      }
      else {
        func_0x007647d0(0x9d2f20,0x98e250);
        iVar4 = *piStack_20;
        for (iVar5 = *(int *)(*piStack_20 + 4); iVar5 != 0; iVar5 = *(int *)(iVar5 + 4)) {
          iVar4 = iVar5;
        }
        *(undefined4 **)(iVar4 + 4) = puVar3;
      }
      goto LAB_007af7d8;
    }
    goto LAB_007afb41;
  }
LAB_007af7d8:
  switch(unaff_retaddr) {
  case 0x1c:
    if (puVar3[5] == 0) {
      func_0x00431b30(param_3,10);
      iVar4 = 0;
      if (0 < param_3) {
        do {
          iVar4 = iVar4 + 1;
          *(undefined4 *)(puVar3[4] + -4 + iVar4 * 4) = 0;
        } while (iVar4 < param_3);
      }
code_r0x007af827:
      iVar4 = FUN_007afb90(puStack_8,iStack_4,unaff_retaddr);
      if (iVar4 == 0) break;
      *(int *)(puVar3[4] + param_2 * 4) = iVar4;
    }
    else {
      if (puVar3[5] != param_3) break;
      iVar4 = *(int *)(puVar3[4] + param_2 * 4);
      if (iVar4 == 0) goto code_r0x007af827;
      *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
      iVar4 = *(int *)(puVar3[4] + param_2 * 4);
    }
    goto code_r0x007afb09;
  case 0x1d:
    if (puVar3[0xb] == 0) {
      func_0x00431b30(param_3,10);
      iVar4 = 0;
      if (0 < param_3) {
        do {
          iVar4 = iVar4 + 1;
          *(undefined4 *)(puVar3[10] + -4 + iVar4 * 4) = 0;
        } while (iVar4 < param_3);
      }
    }
    else {
      if (puVar3[0xb] != param_3) break;
      iVar4 = *(int *)(puVar3[10] + param_2 * 4);
      if (iVar4 != 0) {
        *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
        iVar4 = *(int *)(puVar3[10] + param_2 * 4);
        goto code_r0x007afb09;
      }
    }
    iVar4 = FUN_007afb90(puStack_8,iStack_4,unaff_retaddr);
    if (iVar4 == 0) break;
    iVar5 = puVar3[10];
code_r0x007afb06:
    *(int *)(iVar5 + param_2 * 4) = iVar4;
code_r0x007afb09:
    if (uVar1 != 0) {
      LeaveCriticalSection(uVar1);
    }
    goto code_r0x007afb4e;
  case 0x1e:
    if (puVar3[0x11] == 0) {
      func_0x00431b30(param_3,10);
      iVar4 = 0;
      if (0 < param_3) {
        do {
          iVar4 = iVar4 + 1;
          *(undefined4 *)(puVar3[0x10] + -4 + iVar4 * 4) = 0;
        } while (iVar4 < param_3);
      }
    }
    else {
      if (puVar3[0x11] != param_3) break;
      iVar4 = *(int *)(puVar3[0x10] + param_2 * 4);
      if (iVar4 != 0) {
        *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
        iVar4 = *(int *)(puVar3[0x10] + param_2 * 4);
        goto code_r0x007afb09;
      }
    }
    iVar4 = FUN_007afb90(puStack_8,iStack_4,unaff_retaddr);
    if (iVar4 != 0) {
      *(int *)(puVar3[0x10] + param_2 * 4) = iVar4;
      goto code_r0x007afb09;
    }
    break;
  case 0x1f:
    if (puVar3[0x17] == 0) {
      func_0x00431b30(param_3,10);
      iVar4 = 0;
      if (0 < param_3) {
        do {
          iVar4 = iVar4 + 1;
          *(undefined4 *)(puVar3[0x16] + -4 + iVar4 * 4) = 0;
        } while (iVar4 < param_3);
      }
    }
    else {
      if (puVar3[0x17] != param_3) break;
      iVar4 = *(int *)(puVar3[0x16] + param_2 * 4);
      if (iVar4 != 0) {
        *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
        iVar4 = *(int *)(puVar3[0x16] + param_2 * 4);
        goto code_r0x007afb09;
      }
    }
    iVar4 = FUN_007afb90(puStack_8,iStack_4,unaff_retaddr);
    if (iVar4 != 0) {
      iVar5 = puVar3[0x16];
      goto code_r0x007afb06;
    }
    break;
  case 0x23:
    if (puVar3[0x1d] == 0) {
      func_0x00431b30(param_3,10);
      iVar4 = 0;
      if (0 < param_3) {
        do {
          iVar4 = iVar4 + 1;
          *(undefined4 *)(puVar3[0x1c] + -4 + iVar4 * 4) = 0;
        } while (iVar4 < param_3);
      }
    }
    else {
      if (puVar3[0x1d] != param_3) break;
      iVar4 = *(int *)(puVar3[0x1c] + param_2 * 4);
      if (iVar4 != 0) {
        *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
        iVar4 = *(int *)(puVar3[0x1c] + param_2 * 4);
        goto code_r0x007afb09;
      }
    }
    iVar4 = FUN_007afb90(puStack_8,iStack_4,unaff_retaddr);
    if (iVar4 != 0) {
      *(int *)(puVar3[0x1c] + param_2 * 4) = iVar4;
      goto code_r0x007afb09;
    }
    break;
  case 0x29:
    if (puVar3[0x23] == 0) {
      func_0x00431b30(param_3,10);
      iVar4 = 0;
      if (0 < param_3) {
        do {
          iVar4 = iVar4 + 1;
          *(undefined4 *)(puVar3[0x22] + -4 + iVar4 * 4) = 0;
        } while (iVar4 < param_3);
      }
    }
    else {
      if (puVar3[0x23] != param_3) break;
      iVar4 = *(int *)(puVar3[0x22] + param_2 * 4);
      if (iVar4 != 0) {
        *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
        iVar4 = *(int *)(puVar3[0x22] + param_2 * 4);
        goto code_r0x007afb09;
      }
    }
    iVar4 = FUN_007afb90(puStack_8,iStack_4,unaff_retaddr);
    if (iVar4 != 0) {
      iVar5 = puVar3[0x22];
      goto code_r0x007afb06;
    }
  }
LAB_007afb41:
  if (uVar1 != 0) {
    LeaveCriticalSection(uVar1);
  }
  iVar4 = 0;
code_r0x007afb4e:
  *unaff_FS_OFFSET = uVar1;
  return iVar4;
}


/* ==================================================================== */
/* Address: 0x007afb90 | Classified: elementclient::A3DSkinMeshMan__LoadMeshObject__F@0x7afb90 */
/* ==================================================================== */

int * __thiscall FUN_007afb90(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 unaff_retaddr;
  undefined4 uVar4;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cdbd2;
  *unaff_FS_OFFSET = &uStack_c;
  switch(param_4) {
  case 0x1c:
    iVar2 = func_0x00763250(0x88);
    uStack_4 = 0;
    if (iVar2 == 0) {
code_r0x007afcb1:
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)func_0x007e2fa0();
    }
    break;
  case 0x1d:
    iVar2 = func_0x00763250(0x68);
    uStack_4 = 1;
    if (iVar2 == 0) goto code_r0x007afcb1;
    piVar3 = (int *)func_0x007e2880();
    break;
  case 0x1e:
    iVar2 = func_0x00763250(0xcc);
    uStack_4 = 2;
    if (iVar2 == 0) goto code_r0x007afcb1;
    piVar3 = (int *)func_0x007e1dd0();
    break;
  case 0x1f:
    iVar2 = func_0x00763250(0xac);
    uStack_4 = 3;
    if (iVar2 == 0) goto code_r0x007afcb1;
    piVar3 = (int *)func_0x007e1830();
    break;
  default:
    goto LAB_007afce6;
  case 0x23:
    iVar2 = func_0x00763250(0x78);
    uStack_4 = 4;
    if (iVar2 == 0) goto code_r0x007afcb1;
    piVar3 = (int *)func_0x007e1220();
    break;
  case 0x29:
    iVar2 = func_0x00763250(0x5c);
    uStack_4 = 5;
    if (iVar2 == 0) goto code_r0x007afcb1;
    piVar3 = (int *)func_0x007e0ed0();
  }
  uVar4 = *(undefined4 *)(param_1 + 4);
  uStack_4 = 0xffffffff;
  cVar1 = (**(code **)(*piVar3 + 8))();
  if (cVar1 == '\0') {
    (**(code **)*piVar3)(1);
    uVar4 = 0x98e2cc;
  }
  else {
    cVar1 = (**(code **)(*piVar3 + 0x10))(unaff_retaddr,param_2);
    if (cVar1 != '\0') {
      *unaff_FS_OFFSET = uVar4;
      return piVar3;
    }
    (**(code **)*piVar3)(1);
    uVar4 = 0x98e294;
  }
  func_0x007647d0(0x9d2f20,uVar4);
LAB_007afce6:
  *unaff_FS_OFFSET = uStack_c;
  return (int *)0x0;
}


/* ==================================================================== */
/* Address: 0x007afd60 | Classified: Angelica3D::proc_7afd60 */
/* ==================================================================== */

int __thiscall FUN_007afd60(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *unaff_FS_OFFSET;
  uint unaff_retaddr;
  int iStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cdbe8;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  iVar1 = param_1 + 0x24;
  EnterCriticalSection(iVar1);
  puStack_8 = (undefined *)0x0;
  puVar2 = *(undefined4 **)
            (*(int *)(param_1 + 0x14) + (unaff_retaddr % *(uint *)(param_1 + 0x20)) * 4);
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) goto LAB_007afdb1;
    if (puVar2[2] == unaff_retaddr) break;
    puVar2 = (undefined4 *)*puVar2;
  }
  for (iVar3 = puVar2[1]; iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
    iVar4 = func_0x00763c10(param_2);
    if (iVar4 == 0) {
      if (iVar1 != 0) {
        LeaveCriticalSection(iVar1);
      }
      *unaff_FS_OFFSET = iVar1;
      return iVar3;
    }
  }
LAB_007afdb1:
  if (iVar1 != 0) {
    LeaveCriticalSection(iVar1);
  }
  *unaff_FS_OFFSET = iVar1;
  return 0;
}


/* ==================================================================== */
/* Address: 0x007afe20 | Classified: elementclient::A3DSkinMeshMan__ReleaseSkinNode_@0x7afe20 */
/* ==================================================================== */

void FUN_007afe20(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  if (0 < (int)param_1[5]) {
    do {
      piVar1 = *(int **)(param_1[4] + iVar2 * 4);
      if (piVar1 != (int *)0x0) {
        if (0 < piVar1[4]) {
          iVar3 = iVar3 + 1;
        }
        (**(code **)(*piVar1 + 0xc))();
        (**(code **)*piVar1)(1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1[5]);
  }
  iVar2 = 0;
  if (0 < (int)param_1[0xb]) {
    do {
      piVar1 = *(int **)(param_1[10] + iVar2 * 4);
      if (piVar1 != (int *)0x0) {
        if (0 < piVar1[4]) {
          iVar3 = iVar3 + 1;
        }
        (**(code **)(*piVar1 + 0xc))();
        (**(code **)*piVar1)(1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1[0xb]);
  }
  iVar2 = 0;
  if (0 < (int)param_1[0x11]) {
    do {
      piVar1 = *(int **)(param_1[0x10] + iVar2 * 4);
      if (piVar1 != (int *)0x0) {
        if (0 < piVar1[4]) {
          iVar3 = iVar3 + 1;
        }
        (**(code **)(*piVar1 + 0xc))();
        (**(code **)*piVar1)(1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1[0x11]);
  }
  iVar2 = 0;
  if (0 < (int)param_1[0x17]) {
    do {
      piVar1 = *(int **)(param_1[0x16] + iVar2 * 4);
      if (piVar1 != (int *)0x0) {
        if (0 < piVar1[4]) {
          iVar3 = iVar3 + 1;
        }
        (**(code **)(*piVar1 + 0xc))();
        (**(code **)*piVar1)(1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1[0x17]);
  }
  iVar2 = 0;
  if (0 < (int)param_1[0x1d]) {
    do {
      piVar1 = *(int **)(param_1[0x1c] + iVar2 * 4);
      if (piVar1 != (int *)0x0) {
        if (0 < piVar1[4]) {
          iVar3 = iVar3 + 1;
        }
        (**(code **)(*piVar1 + 0xc))();
        (**(code **)*piVar1)(1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1[0x1d]);
  }
  iVar2 = 0;
  if (0 < (int)param_1[0x23]) {
    do {
      piVar1 = *(int **)(param_1[0x22] + iVar2 * 4);
      if (piVar1 != (int *)0x0) {
        if (0 < piVar1[4]) {
          iVar3 = iVar3 + 1;
        }
        (**(code **)(*piVar1 + 0xc))();
        (**(code **)*piVar1)(1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1[0x23]);
  }
  if (iVar3 != 0) {
    func_0x007647d0(0x9d2f20,0x98e308,*param_1);
  }
  FUN_007aff90();
  func_0x00763260(param_1);
  return;
}


/* ==================================================================== */
/* Address: 0x007aff90 | Classified: Angelica3D::proc_7aff90 */
/* ==================================================================== */

void __fastcall FUN_007aff90(int param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  puStack_8 = &UNK_008cdc3f;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined **)(param_1 + 0x80) = &UNK_008f1d20;
  iStack_4 = 5;
  *(undefined **)(param_1 + 0x84) = &UNK_008d5a30;
  if (*(int *)(param_1 + 0x88) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x88));
    *(undefined4 *)(param_1 + 0x88) = 0;
  }
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined **)(param_1 + 0x68) = &UNK_008f1d1c;
  iStack_4._0_1_ = 4;
  *(undefined **)(param_1 + 0x6c) = &UNK_008d5a30;
  if (*(int *)(param_1 + 0x70) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x70));
    *(undefined4 *)(param_1 + 0x70) = 0;
  }
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined **)(param_1 + 0x50) = &UNK_008f1d18;
  iStack_4._0_1_ = 3;
  *(undefined **)(param_1 + 0x54) = &UNK_008d5a30;
  if (*(int *)(param_1 + 0x58) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x58));
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined **)(param_1 + 0x38) = &UNK_008f1d14;
  iStack_4._0_1_ = 2;
  *(undefined **)(param_1 + 0x3c) = &UNK_008d5a30;
  if (*(int *)(param_1 + 0x40) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x40));
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined **)(param_1 + 0x20) = &UNK_008f1d10;
  iStack_4._0_1_ = 1;
  *(undefined **)(param_1 + 0x24) = &UNK_008d5a30;
  if (*(int *)(param_1 + 0x28) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x28));
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined **)(param_1 + 8) = &UNK_008f1d0c;
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  *(undefined **)(param_1 + 0xc) = &UNK_008d5a30;
  if (*(int *)(param_1 + 0x10) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  iStack_4 = 0xffffffff;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x007b00e0 | Classified: Angelica3D::proc_7b00e0 */
/* ==================================================================== */

void __thiscall FUN_007b00e0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cdc58;
  *unaff_FS_OFFSET = &uStack_c;
  iVar4 = 0;
  if (*(int *)(param_2 + 0x130) != 0) {
    param_1 = param_1 + 0x24;
    EnterCriticalSection(param_1);
    puStack_8 = (undefined *)0x0;
    iVar3 = FUN_007afd60(*(undefined4 *)(param_2 + 0x130),*(undefined4 *)(param_2 + 0x18));
    if (iVar3 != 0) {
      if (0 < *(int *)(iVar3 + 0x14)) {
        do {
          piVar1 = *(int **)(*(int *)(iVar3 + 0x10) + iVar4 * 4);
          if ((piVar1 != (int *)0x0) && (iVar2 = piVar1[4], piVar1[4] = iVar2 + -1, iVar2 + -1 == 0)
             ) {
            (**(code **)(*piVar1 + 0xc))();
            (**(code **)*piVar1)(1);
            *(undefined4 *)(*(int *)(iVar3 + 0x10) + iVar4 * 4) = 0;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < *(int *)(iVar3 + 0x14));
      }
      iVar4 = 0;
      if (0 < *(int *)(iVar3 + 0x2c)) {
        do {
          piVar1 = *(int **)(*(int *)(iVar3 + 0x28) + iVar4 * 4);
          if ((piVar1 != (int *)0x0) && (iVar2 = piVar1[4], piVar1[4] = iVar2 + -1, iVar2 + -1 == 0)
             ) {
            (**(code **)(*piVar1 + 0xc))();
            (**(code **)*piVar1)(1);
            *(undefined4 *)(*(int *)(iVar3 + 0x28) + iVar4 * 4) = 0;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < *(int *)(iVar3 + 0x2c));
      }
      iVar4 = 0;
      if (0 < *(int *)(iVar3 + 0x44)) {
        do {
          piVar1 = *(int **)(*(int *)(iVar3 + 0x40) + iVar4 * 4);
          if ((piVar1 != (int *)0x0) && (iVar2 = piVar1[4], piVar1[4] = iVar2 + -1, iVar2 + -1 == 0)
             ) {
            (**(code **)(*piVar1 + 0xc))();
            (**(code **)*piVar1)(1);
            *(undefined4 *)(*(int *)(iVar3 + 0x40) + iVar4 * 4) = 0;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < *(int *)(iVar3 + 0x44));
      }
      iVar4 = 0;
      if (0 < *(int *)(iVar3 + 0x5c)) {
        do {
          piVar1 = *(int **)(*(int *)(iVar3 + 0x58) + iVar4 * 4);
          if ((piVar1 != (int *)0x0) && (iVar2 = piVar1[4], piVar1[4] = iVar2 + -1, iVar2 + -1 == 0)
             ) {
            (**(code **)(*piVar1 + 0xc))();
            (**(code **)*piVar1)(1);
            *(undefined4 *)(*(int *)(iVar3 + 0x58) + iVar4 * 4) = 0;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < *(int *)(iVar3 + 0x5c));
      }
      iVar4 = 0;
      if (0 < *(int *)(iVar3 + 0x74)) {
        do {
          piVar1 = *(int **)(*(int *)(iVar3 + 0x70) + iVar4 * 4);
          if ((piVar1 != (int *)0x0) && (iVar2 = piVar1[4], piVar1[4] = iVar2 + -1, iVar2 + -1 == 0)
             ) {
            (**(code **)(*piVar1 + 0xc))();
            (**(code **)*piVar1)(1);
            *(undefined4 *)(*(int *)(iVar3 + 0x70) + iVar4 * 4) = 0;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < *(int *)(iVar3 + 0x74));
      }
      iVar4 = 0;
      if (0 < *(int *)(iVar3 + 0x8c)) {
        do {
          piVar1 = *(int **)(*(int *)(iVar3 + 0x88) + iVar4 * 4);
          if ((piVar1 != (int *)0x0) && (iVar2 = piVar1[4], piVar1[4] = iVar2 + -1, iVar2 + -1 == 0)
             ) {
            (**(code **)(*piVar1 + 0xc))();
            (**(code **)*piVar1)(1);
            *(undefined4 *)(*(int *)(iVar3 + 0x88) + iVar4 * 4) = 0;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < *(int *)(iVar3 + 0x8c));
      }
    }
    if (param_1 != 0) {
      LeaveCriticalSection(param_1);
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x007b02e0 | Classified: Angelica3D::proc_7b02e0 */
/* ==================================================================== */

/* WARNING: Removing unreachable block (ram,0x007b03d9) */
/* WARNING: Removing unreachable block (ram,0x007b03fc) */

int __fastcall FUN_007b02e0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int unaff_EBX;
  int *piVar5;
  undefined4 *unaff_FS_OFFSET;
  int *piStack_18;
  int *piStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cdc78;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  EnterCriticalSection(param_1 + 0x24);
  piVar2 = (int *)0x0;
  piStack_14 = (int *)0x0;
  piVar4 = *(int **)(param_1 + 0x14);
  puStack_8 = (undefined *)0x0;
  if (piVar4 == (int *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x20) * 4)) goto LAB_007b0366;
  piVar2 = (int *)*piVar4;
  piStack_18 = piVar4;
  piStack_14 = piVar2;
  if (piVar2 == (int *)0x0) {
    FUN_00793ff0();
  }
LAB_007b036c:
  do {
    do {
      if (piVar4 == (int *)0x0) {
        if (piVar2 == (int *)0x0) {
          *unaff_FS_OFFSET = uStack_10;
          return unaff_EBX;
        }
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = piVar2 + 1;
      }
      for (iVar1 = *piVar5; iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
        iVar3 = FUN_007b0420(iVar1);
        unaff_EBX = unaff_EBX + iVar3;
        piVar2 = piStack_14;
        piVar4 = piStack_18;
      }
    } while ((piVar4 == (int *)0x0) ||
            ((piVar2 != (int *)0x0 &&
             (piVar2 = (int *)*piVar2, piStack_14 = piVar2, piVar2 != (int *)0x0))));
    do {
      piVar4 = piVar4 + 1;
      if (piVar4 == (int *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x20) * 4))
      goto LAB_007b0366;
      piVar2 = (int *)*piVar4;
      piStack_18 = piVar4;
      piStack_14 = piVar2;
    } while (piVar2 == (int *)0x0);
  } while( true );
LAB_007b0366:
  piVar4 = (int *)0x0;
  piStack_18 = (int *)0x0;
  goto LAB_007b036c;
}


/* ==================================================================== */
/* Address: 0x007b0420 | Classified: Angelica3D::proc_7b0420 */
/* ==================================================================== */

int FUN_007b0420(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x14)) {
    do {
      piVar1 = *(int **)(*(int *)(param_1 + 0x10) + iVar4 * 4);
      if (piVar1 != (int *)0x0) {
        iVar2 = (**(code **)(*piVar1 + 0x30))();
        iVar3 = iVar3 + iVar2;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x14));
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x2c)) {
    do {
      piVar1 = *(int **)(*(int *)(param_1 + 0x28) + iVar4 * 4);
      if (piVar1 != (int *)0x0) {
        iVar2 = (**(code **)(*piVar1 + 0x30))();
        iVar3 = iVar3 + iVar2;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x2c));
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x44)) {
    do {
      piVar1 = *(int **)(*(int *)(param_1 + 0x40) + iVar4 * 4);
      if (piVar1 != (int *)0x0) {
        iVar2 = (**(code **)(*piVar1 + 0x30))();
        iVar3 = iVar3 + iVar2;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x44));
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x5c)) {
    do {
      piVar1 = *(int **)(*(int *)(param_1 + 0x58) + iVar4 * 4);
      if (piVar1 != (int *)0x0) {
        iVar2 = (**(code **)(*piVar1 + 0x30))();
        iVar3 = iVar3 + iVar2;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x5c));
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x74)) {
    do {
      piVar1 = *(int **)(*(int *)(param_1 + 0x70) + iVar4 * 4);
      if (piVar1 != (int *)0x0) {
        iVar2 = (**(code **)(*piVar1 + 0x30))();
        iVar3 = iVar3 + iVar2;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x74));
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x8c)) {
    do {
      piVar1 = *(int **)(*(int *)(param_1 + 0x88) + iVar4 * 4);
      if (piVar1 != (int *)0x0) {
        iVar2 = (**(code **)(*piVar1 + 0x30))();
        iVar3 = iVar3 + iVar2;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x8c));
  }
  return iVar3;
}


/* ==================================================================== */
/* Address: 0x007b0510 | Classified: Angelica3D::proc_7b0510 */
/* ==================================================================== */

void __fastcall FUN_007b0510(undefined4 *param_1)

{
  param_1[1] = &UNK_008d5a30;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0x10;
  *param_1 = &UNK_008f1d0c;
  return;
}


/* ==================================================================== */
/* Address: 0x007b0540 | Classified: Angelica3D::proc_7b0540 */
/* ==================================================================== */

void __fastcall FUN_007b0540(undefined4 *param_1)

{
  *param_1 = &UNK_008f1d0c;
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
/* Address: 0x007b0570 | Classified: Angelica3D::proc_7b0570 */
/* ==================================================================== */

void __fastcall FUN_007b0570(undefined4 *param_1)

{
  param_1[1] = &UNK_008d5a30;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0x10;
  *param_1 = &UNK_008f1d10;
  return;
}


/* ==================================================================== */
/* Address: 0x007b05a0 | Classified: Angelica3D::proc_7b05a0 */
/* ==================================================================== */

void __fastcall FUN_007b05a0(undefined4 *param_1)

{
  *param_1 = &UNK_008f1d10;
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
/* Address: 0x007b05d0 | Classified: Angelica3D::proc_7b05d0 */
/* ==================================================================== */

void __fastcall FUN_007b05d0(undefined4 *param_1)

{
  param_1[1] = &UNK_008d5a30;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0x10;
  *param_1 = &UNK_008f1d14;
  return;
}


/* ==================================================================== */
/* Address: 0x007b0600 | Classified: Angelica3D::proc_7b0600 */
/* ==================================================================== */

void __fastcall FUN_007b0600(undefined4 *param_1)

{
  *param_1 = &UNK_008f1d14;
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
/* Address: 0x007b0630 | Classified: Angelica3D::proc_7b0630 */
/* ==================================================================== */

void __fastcall FUN_007b0630(undefined4 *param_1)

{
  param_1[1] = &UNK_008d5a30;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0x10;
  *param_1 = &UNK_008f1d18;
  return;
}


/* ==================================================================== */
/* Address: 0x007b0660 | Classified: Angelica3D::proc_7b0660 */
/* ==================================================================== */

void __fastcall FUN_007b0660(undefined4 *param_1)

{
  *param_1 = &UNK_008f1d18;
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
/* Address: 0x007b0690 | Classified: Angelica3D::proc_7b0690 */
/* ==================================================================== */

void __fastcall FUN_007b0690(undefined4 *param_1)

{
  param_1[1] = &UNK_008d5a30;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0x10;
  *param_1 = &UNK_008f1d1c;
  return;
}


/* ==================================================================== */
/* Address: 0x007b06c0 | Classified: Angelica3D::proc_7b06c0 */
/* ==================================================================== */

void __fastcall FUN_007b06c0(undefined4 *param_1)

{
  *param_1 = &UNK_008f1d1c;
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
/* Address: 0x007b06f0 | Classified: Angelica3D::proc_7b06f0 */
/* ==================================================================== */

void __fastcall FUN_007b06f0(undefined4 *param_1)

{
  param_1[1] = &UNK_008d5a30;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0x10;
  *param_1 = &UNK_008f1d20;
  return;
}


/* ==================================================================== */
/* Address: 0x007b0720 | Classified: Angelica3D::proc_7b0720 */
/* ==================================================================== */

undefined4 __thiscall FUN_007b0720(undefined4 param_1,byte param_2)

{
  FUN_007b0540();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007b0740 | Classified: Angelica3D::proc_7b0740 */
/* ==================================================================== */

undefined4 __thiscall FUN_007b0740(undefined4 param_1,byte param_2)

{
  FUN_007b05a0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007b0760 | Classified: Angelica3D::proc_7b0760 */
/* ==================================================================== */

undefined4 __thiscall FUN_007b0760(undefined4 param_1,byte param_2)

{
  FUN_007b0600();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007b0780 | Classified: Angelica3D::proc_7b0780 */
/* ==================================================================== */

undefined4 __thiscall FUN_007b0780(undefined4 param_1,byte param_2)

{
  FUN_007b0660();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007b07a0 | Classified: Angelica3D::proc_7b07a0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007b07a0(undefined4 param_1,byte param_2)

{
  FUN_007b06c0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007b07c0 | Classified: Angelica3D::proc_7b07c0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007b07c0(undefined4 param_1,byte param_2)

{
  FUN_007b07e0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007b07e0 | Classified: Angelica3D::proc_7b07e0 */
/* ==================================================================== */

void __fastcall FUN_007b07e0(undefined4 *param_1)

{
  *param_1 = &UNK_008f1d20;
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
/* Address: 0x007b0810 | Classified: Angelica3D::proc_7b0810 */
/* ==================================================================== */

void __thiscall FUN_007b0810(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  if (uVar1 < param_2) {
    iVar4 = 0;
    do {
      if (param_2 < *(uint *)(&UNK_008f1c98 + iVar4 * 4)) {
        param_2 = *(uint *)(&UNK_008f1c98 + iVar4 * 4);
        goto LAB_007b0847;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x1c);
    param_2 = 0xffffffff;
LAB_007b0847:
    if (uVar1 < param_2) {
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
      if (uVar1 != 0) {
        iVar4 = *(int *)(param_1 + 8);
        do {
          puVar7 = *(undefined4 **)(iVar4 + uVar6 * 4);
          while (puVar7 != (undefined4 *)0x0) {
            uVar2 = puVar7[2];
            *(undefined4 *)(iVar4 + uVar6 * 4) = *puVar7;
            *puVar7 = puVar5[uVar2 % param_2];
            puVar5[uVar2 % param_2] = puVar7;
            iVar4 = *(int *)(param_1 + 8);
            puVar7 = *(undefined4 **)(iVar4 + uVar6 * 4);
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar1);
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
/* Address: 0x007b0930 | Classified: Angelica3D::proc_7b0930 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_007b0930(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = _DAT_009858e4;
  *param_1 = &UNK_008f1d98;
  param_1[3] = 0;
  param_1[0x46] = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  *(undefined1 *)(param_1 + 0x45) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007b0960 | Classified: Angelica3D::proc_7b0960 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_007b0960(int param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  undefined4 unaff_EDI;
  undefined1 auStack_20 [16];
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(int **)(param_1 + 0x118) = param_3;
  strncpy(param_1 + 0x10,param_4,0x104);
  if (_DAT_00988334 == 4) {
    *(undefined1 *)(param_1 + 0x114) = 1;
    return 1;
  }
  (**(code **)(*param_3 + 0x20))(param_3,auStack_20);
  *(undefined4 *)(param_1 + 0x120) = uStack_10;
  *(undefined4 *)(param_1 + 0x124) = uStack_c;
  *(undefined4 *)(param_1 + 0x11c) = unaff_EDI;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007b09e0 | Classified: Angelica3D::proc_7b09e0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007b09e0(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x118);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x118) = 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007b0a10 | Classified: elementclient::A3DSurface__Create____This_surfa@0x7b0a10 */
/* ==================================================================== */

bool __thiscall
FUN_007b0a10(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = param_2;
  if (*(int *)(param_1 + 0x118) != 0) {
    func_0x007647d0(0x9d2f20,0x98e350);
    return false;
  }
  uVar4 = param_5;
  iVar3 = (**(code **)(**(int **)(param_2 + 0x2c) + 0x6c))
                    (*(int **)(param_2 + 0x2c),param_3,param_4,param_5,&param_2);
  if (iVar3 < 0) {
    return false;
  }
  cVar2 = FUN_007b0960(iVar1,uVar4,0x98e340);
  return cVar2 != '\0';
}


/* ==================================================================== */
/* Address: 0x007b0a80 | Classified: Angelica3D::proc_7b0a80 */
/* ==================================================================== */

undefined4 __thiscall FUN_007b0a80(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int **ppiVar3;
  int *piStack_8;
  int *piStack_4;
  
  piVar2 = *(int **)(param_1 + 0x118);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  ppiVar3 = &piStack_8;
  iVar1 = (**(code **)(*piVar2 + 0x24))(piVar2,ppiVar3,param_2,0);
  if (iVar1 < 0) {
    return 0;
  }
  *piStack_8 = (int)ppiVar3;
  *piStack_4 = (int)piVar2;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007b0ad0 | Classified: Angelica3D::proc_7b0ad0 */
/* ==================================================================== */

bool __fastcall FUN_007b0ad0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x118);
  if (piVar1 == (int *)0x0) {
    return false;
  }
  iVar2 = (**(code **)(*piVar1 + 0x28))(piVar1);
  return -1 < iVar2;
}


/* ==================================================================== */
/* Address: 0x007b0af0 | Classified: Angelica3D::proc_7b0af0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_007b0af0(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = _DAT_009858e4;
  param_1[6] = 0;
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[10] = 0;
  param_1[9] = 0;
  param_1[7] = 0;
  param_1[0xe] = 0;
  param_1[0xc] = 0;
  param_1[0xb] = 0;
  param_1[0x11] = 0;
  param_1[0x10] = 0;
  param_1[0xf] = 0;
  param_1[0x12] = 0x3f800000;
  param_1[0xd] = 0x3f800000;
  param_1[8] = 0x3f800000;
  param_1[3] = 0x3f800000;
  param_1[0x16] = 0;
  param_1[0x15] = 0;
  param_1[0x14] = 0;
  param_1[0x1a] = 0;
  param_1[0x19] = 0;
  param_1[0x17] = 0;
  param_1[0x1e] = 0;
  param_1[0x1c] = 0;
  param_1[0x1b] = 0;
  param_1[0x21] = 0;
  param_1[0x20] = 0;
  param_1[0x1f] = 0;
  param_1[0x22] = 0x3f800000;
  param_1[0x1d] = 0x3f800000;
  param_1[0x18] = 0x3f800000;
  param_1[0x13] = 0x3f800000;
  param_1[0x26] = &UNK_008d649c;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 10;
  param_1[0x2c] = 0;
  param_1[0x25] = &UNK_008f1de0;
  *param_1 = &UNK_008f1da0;
  param_1[1] = 0x12;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007b0bd0 | Classified: Angelica3D::proc_7b0bd0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007b0bd0(undefined4 param_1,byte param_2)

{
  FUN_007b0bf0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007b0bf0 | Classified: Angelica3D::proc_7b0bf0 */
/* ==================================================================== */

void __fastcall FUN_007b0bf0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  uint uStack_4;
  
  puStack_8 = &UNK_008cdca6;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f1da0;
  uStack_4 = 1;
  if ((param_1[0x23] != 0) && (param_1[0x24] != 0)) {
    FUN_007b12d0(param_1);
  }
  FUN_007b1340();
  param_1[0x25] = &UNK_008f1de0;
  puVar1 = (undefined4 *)param_1[0x27];
  uStack_4 = uStack_4 & 0xffffff00;
  param_1[0x26] = &UNK_008d649c;
  while (puVar1 != (undefined4 *)0x0) {
    param_1[0x27] = *puVar1;
    *puVar1 = param_1[0x29];
    param_1[0x29] = puVar1;
    puVar1 = (undefined4 *)param_1[0x27];
    param_1[0x2a] = param_1[0x2a] + -1;
  }
  puVar1 = (undefined4 *)param_1[0x2c];
  param_1[0x28] = 0;
  param_1[0x2a] = 0;
  while (puVar1 != (undefined4 *)0x0) {
    param_1[0x2c] = puVar1[1];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    puVar1 = (undefined4 *)param_1[0x2c];
  }
  uStack_4 = 0xffffffff;
  *param_1 = &UNK_008d6410;
  func_0x007637f0();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x007b0cf0 | Classified: CECObject::vfunc_slot_4 */
/* ==================================================================== */

void __thiscall FUN_007b0cf0(int param_1,float *param_2)

{
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_4;
  
  fStack_4 = *(float *)(param_1 + 0x44);
  fStack_18 = *param_2 - *(float *)(param_1 + 0x3c);
  fStack_14 = param_2[1] - *(float *)(param_1 + 0x40);
  fStack_10 = param_2[2] - fStack_4;
  *(float *)(param_1 + 0x3c) = *param_2;
  *(float *)(param_1 + 0x40) = param_2[1];
  *(float *)(param_1 + 0x44) = param_2[2];
  FUN_007b0f40();
  FUN_007b1170(&fStack_18);
  return;
}


/* ==================================================================== */
/* Address: 0x007b0d60 | Classified: A3DSkinModel::vfunc_slot_5 */
/* ==================================================================== */

void __thiscall FUN_007b0d60(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  undefined1 auStack_40 [64];
  
  iStack_4c = param_1[0xf];
  iStack_48 = param_1[0x10];
  iStack_44 = param_1[0x11];
  iVar1 = *param_1;
  uVar2 = func_0x00788960(auStack_40,param_2,param_3,&iStack_4c);
  (**(code **)(iVar1 + 8))(uVar2);
  return;
}


/* ==================================================================== */
/* Address: 0x007b0f40 | Classified: Angelica3D::proc_7b0f40 */
/* ==================================================================== */

void __fastcall FUN_007b0f40(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 auStack_80 [64];
  undefined1 auStack_40 [64];
  
  if (*(int *)(param_1 + 0x8c) == 0) {
    puVar2 = (undefined4 *)(param_1 + 0xc);
    puVar4 = (undefined4 *)(param_1 + 0x4c);
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar4 = puVar4 + 1;
    }
    return;
  }
  uVar1 = func_0x00788570(auStack_80,*(int *)(param_1 + 0x8c) + 0xc);
  puVar2 = (undefined4 *)func_0x007873a0(auStack_40,param_1 + 0xc,uVar1);
  puVar4 = (undefined4 *)(param_1 + 0x4c);
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007b1170 | Classified: Angelica3D::proc_7b1170 */
/* ==================================================================== */

void __thiscall FUN_007b1170(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x9c);
  while (puVar1 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar1;
    FUN_007b1210(param_2);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007b11a0 | Classified: Angelica3D::proc_7b11a0 */
/* ==================================================================== */

void __fastcall FUN_007b11a0(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 auStack_80 [16];
  undefined1 auStack_40 [64];
  
  piVar4 = *(int **)(param_1 + 0x9c);
  if (piVar4 != (int *)0x0) {
    do {
      piVar1 = piVar4 + 2;
      piVar4 = (int *)*piVar4;
      puVar2 = (undefined4 *)func_0x007873a0(auStack_40,*piVar1 + 0x4c,param_1 + 0xc);
      puVar5 = auStack_80;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar5 = puVar5 + 1;
      }
      FUN_007b1260(auStack_80);
    } while (piVar4 != (int *)0x0);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007b1210 | Classified: Angelica3D::proc_7b1210 */
/* ==================================================================== */

void __thiscall FUN_007b1210(int param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  undefined4 *puVar3;
  
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  *(float *)(param_1 + 0x3c) = *(float *)(param_1 + 0x3c) + *param_2;
  *(float *)(param_1 + 0x44) = *(float *)(param_1 + 0x44) + fVar2;
  *(float *)(param_1 + 0x40) = *(float *)(param_1 + 0x40) + fVar1;
  puVar3 = *(undefined4 **)(param_1 + 0x9c);
  while (puVar3 != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)*puVar3;
    FUN_007b1210(param_2);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007b1260 | Classified: Angelica3D::proc_7b1260 */
/* ==================================================================== */

void __thiscall FUN_007b1260(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0xc);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  FUN_007b11a0();
  return;
}


/* ==================================================================== */
/* Address: 0x007b1280 | Classified: Angelica3D::proc_7b1280 */
/* ==================================================================== */

undefined4 __thiscall FUN_007b1280(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = func_0x00419130();
  *(int *)(iVar1 + 8) = param_2;
  *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(param_1 + 0xa0);
  if (*(int **)(param_1 + 0xa0) == (int *)0x0) {
    *(int *)(param_1 + 0x9c) = iVar1;
  }
  else {
    **(int **)(param_1 + 0xa0) = iVar1;
  }
  *(int *)(param_1 + 0xa0) = iVar1;
  *(int *)(param_2 + 0x90) = iVar1;
  *(int *)(param_2 + 0x8c) = param_1;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007b12d0 | Classified: Angelica3D::proc_7b12d0 */
/* ==================================================================== */

void __thiscall FUN_007b12d0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  if ((param_2 != 0) && (piVar1 = *(int **)(param_2 + 0x90), piVar1 != (int *)0x0)) {
    iVar2 = *piVar1;
    piVar3 = (int *)piVar1[1];
    if (iVar2 == 0) {
      *(int **)(param_1 + 0xa0) = piVar3;
    }
    else {
      *(int **)(iVar2 + 4) = piVar3;
    }
    if (piVar3 == (int *)0x0) {
      *(int *)(param_1 + 0x9c) = iVar2;
    }
    else {
      *piVar3 = iVar2;
    }
    *piVar1 = *(int *)(param_1 + 0xa4);
    *(int **)(param_1 + 0xa4) = piVar1;
    *(int *)(param_1 + 0xa8) = *(int *)(param_1 + 0xa8) + -1;
    *(undefined4 *)(param_2 + 0x90) = 0;
    *(undefined4 *)(param_2 + 0x8c) = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007b1340 | Classified: Angelica3D::proc_7b1340 */
/* ==================================================================== */

void __fastcall FUN_007b1340(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = *(undefined4 **)(param_1 + 0x9c);
  while (puVar2 != (undefined4 *)0x0) {
    piVar1 = puVar2 + 2;
    puVar2 = (undefined4 *)*puVar2;
    iVar3 = *piVar1;
    *(undefined4 *)(iVar3 + 0x8c) = 0;
    *(undefined4 *)(iVar3 + 0x90) = 0;
  }
  puVar2 = *(undefined4 **)(param_1 + 0x9c);
  while (puVar2 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x9c) = *puVar2;
    *puVar2 = *(undefined4 *)(param_1 + 0xa4);
    *(undefined4 **)(param_1 + 0xa4) = puVar2;
    *(int *)(param_1 + 0xa8) = *(int *)(param_1 + 0xa8) + -1;
    puVar2 = *(undefined4 **)(param_1 + 0x9c);
  }
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007b13b0 | Classified: Angelica3D::proc_7b13b0 */
/* ==================================================================== */

void __fastcall FUN_007b13b0(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  *param_1 = &UNK_008f1de0;
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
/* Address: 0x007b1410 | Classified: Angelica3D::proc_7b1410 */
/* ==================================================================== */

undefined4 __thiscall FUN_007b1410(undefined4 param_1,byte param_2)

{
  FUN_007b13b0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007b1430 | Classified: Angelica3D::proc_7b1430 */
/* ==================================================================== */

/* WARNING: Removing unreachable block (ram,0x007b159b) */
/* WARNING: Removing unreachable block (ram,0x007b15ce) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffdc : 0x007b15f2 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined2
FUN_007b1430(float *param_1,int param_2,float *param_3,int param_4,float *param_5,
            undefined4 *param_6,float *param_7)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iStack_28;
  float afStack_24 [6];
  float afStack_c [3];
  
  iVar6 = param_4 - (int)param_3;
  iVar5 = (int)param_1 - (int)param_3;
  iVar7 = param_2 - (int)param_3;
  afStack_24[0] = -1.0;
  afStack_24[1] = -1.0;
  afStack_24[2] = -1.0;
  bVar3 = true;
  iStack_28 = 3;
  pfVar4 = param_3;
  do {
    if (*pfVar4 <= *(float *)(iVar5 + (int)pfVar4)) {
      if (*(float *)((int)pfVar4 + iVar6) < *(float *)(iVar5 + (int)pfVar4)) {
        *(undefined4 *)(((int)param_5 - (int)param_3) + (int)pfVar4) =
             *(undefined4 *)((int)pfVar4 + iVar6);
        fVar1 = *(float *)(iVar7 + (int)pfVar4);
        *(undefined4 *)(((int)afStack_c - (int)param_3) + (int)pfVar4) = 0xbf800000;
        if (fVar1 == _DAT_008effc4) goto LAB_007b1520;
        fVar1 = *(float *)((int)pfVar4 + iVar6);
        goto LAB_007b150d;
      }
    }
    else {
      *(float *)(((int)param_5 - (int)param_3) + (int)pfVar4) = *pfVar4;
      fVar1 = *(float *)(iVar7 + (int)pfVar4);
      *(undefined4 *)(((int)afStack_c - (int)param_3) + (int)pfVar4) = 0x3f800000;
      if (fVar1 == _DAT_008effc4) {
LAB_007b1520:
        bVar3 = false;
      }
      else {
        fVar1 = *pfVar4;
LAB_007b150d:
        bVar3 = false;
        *(float *)(((int)afStack_24 - (int)param_3) + (int)pfVar4) =
             (fVar1 - *(float *)(iVar5 + (int)pfVar4)) / *(float *)(iVar7 + (int)pfVar4);
      }
    }
    fVar1 = _DAT_008effc4;
    pfVar4 = pfVar4 + 1;
    iStack_28 = iStack_28 + -1;
    if (iStack_28 == 0) {
      if (bVar3) {
        *param_5 = *param_1;
        param_5[1] = param_1[1];
        param_5[2] = param_1[2];
        *param_6 = 0;
        *param_7 = 0.0;
        param_7[2] = 0.0;
        param_7[1] = 0.0;
        return 1;
      }
      iVar5 = 0;
      if (-1.0 < _DAT_008effc4) {
        return 0;
      }
      param_2 = param_2 - (int)param_1;
      iVar7 = (int)param_5 - (int)param_1;
      iVar6 = (int)param_3 - (int)param_1;
      param_4 = param_4 - (int)param_1;
      do {
        if (iVar5 != 0) {
          fVar2 = *(float *)(param_2 + (int)param_1) * -1.0 + *param_1;
          *(float *)(iVar7 + (int)param_1) = fVar2;
          if (fVar2 < *(float *)(iVar6 + (int)param_1) - _DAT_008f1de4) {
            return 0;
          }
          if (*(float *)(param_4 + (int)param_1) + _DAT_008f1de4 < fVar2) {
            return 0;
          }
        }
        iVar5 = iVar5 + 1;
        param_1 = param_1 + 1;
        if (2 < iVar5) {
          *param_6 = 0xbf800000;
          *param_7 = -afStack_c[0];
          param_7[1] = 0.0;
          param_7[2] = fVar1;
          return 1;
        }
      } while( true );
    }
  } while( true );
}


/* ==================================================================== */
/* Address: 0x007b16b0 | Classified: Angelica3D::proc_7b16b0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007b16b0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  byte bVar2;
  float fVar3;
  float *pfVar4;
  
  bVar2 = *(byte *)(param_1 + 4);
  if (bVar2 < 3) {
    if (param_1[3] < param_2[bVar2]) {
      return 1;
    }
    if (param_1[3] <= param_3[bVar2]) {
      return 0;
    }
    return 0xffffffff;
  }
  if (bVar2 < 6) {
    if (param_1[3] < -param_3[bVar2 - 3]) {
      return 1;
    }
    if (param_1[3] <= -param_2[bVar2 - 3]) {
      return 0;
    }
    return 0xffffffff;
  }
  switch(*(undefined1 *)((int)param_1 + 0x11)) {
  case 0:
    fVar1 = param_3[1] * param_1[1] + param_3[2] * param_1[2];
    fVar3 = *param_1 * *param_3;
    param_3 = param_2;
    goto code_r0x007b1897;
  case 1:
    fVar3 = *param_1 * *param_2 + param_3[1] * param_1[1] + param_3[2] * param_1[2];
    param_2 = (float *)(*param_1 * *param_3 + param_2[1] * param_1[1] + param_2[2] * param_1[2]);
    break;
  case 2:
    fVar3 = *param_1 * *param_3 + param_2[1] * param_1[1] + param_3[2] * param_1[2];
    param_2 = (float *)(*param_1 * *param_2 + param_3[1] * param_1[1] + param_2[2] * param_1[2]);
    break;
  case 3:
    pfVar4 = param_3;
    goto code_r0x007b17eb;
  case 4:
    pfVar4 = param_2;
    param_2 = param_3;
code_r0x007b17eb:
    param_3 = pfVar4;
    fVar3 = *param_1 * *param_2 + param_2[1] * param_1[1] + param_3[2] * param_1[2];
    fVar1 = param_2[2];
    goto code_r0x007b189c;
  case 5:
    fVar3 = *param_1 * *param_2 + param_3[1] * param_1[1] + param_2[2] * param_1[2];
    param_2 = (float *)(*param_1 * *param_3 + param_2[1] * param_1[1] + param_3[2] * param_1[2]);
    break;
  case 6:
    fVar3 = *param_1 * *param_3 + param_2[1] * param_1[1] + param_2[2] * param_1[2];
    param_2 = (float *)(*param_1 * *param_2 + param_3[1] * param_1[1] + param_3[2] * param_1[2]);
    break;
  case 7:
    fVar1 = param_2[1] * param_1[1] + param_2[2] * param_1[2];
    fVar3 = *param_1 * *param_2;
code_r0x007b1897:
    fVar3 = fVar3 + fVar1;
    fVar1 = param_3[2];
code_r0x007b189c:
    param_2 = (float *)(*param_1 * *param_3 + param_3[1] * param_1[1] + fVar1 * param_1[2]);
    break;
  default:
    param_2 = (float *)0x0;
    fVar3 = _DAT_008effc4;
  }
  if (fVar3 - param_1[3] < _DAT_008f1de4) {
    return 0xffffffff;
  }
  if ((float)param_2 - param_1[3] <= _DAT_008f1de8) {
    return 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007b1920 | Classified: Angelica3D::proc_7b1920 */
/* ==================================================================== */

undefined4 FUN_007b1920(float *param_1,float *param_2,float param_3)

{
  float fVar1;
  byte bVar2;
  
  bVar2 = *(byte *)(param_1 + 4);
  if (bVar2 < 3) {
    fVar1 = param_2[bVar2];
  }
  else {
    if (bVar2 < 6) {
      if (param_2[bVar2 - 3] + param_1[3] < -param_3) {
        return 1;
      }
      if (param_3 < param_2[bVar2 - 3] + param_1[3]) {
        return 0xffffffff;
      }
      return 0;
    }
    fVar1 = *param_1 * *param_2 + param_1[1] * param_2[1] + param_1[2] * param_2[2];
  }
  if (param_3 < fVar1 - param_1[3]) {
    return 1;
  }
  if (fVar1 - param_1[3] < -param_3) {
    return 0xffffffff;
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x007b19c0 | Classified: Angelica3D::proc_7b19c0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_007b19c0(undefined4 param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float *pfVar2;
  undefined4 *puVar3;
  float unaff_EBX;
  float unaff_ESI;
  float unaff_EDI;
  float10 fVar4;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  undefined4 *puStack_30;
  float fStack_2c;
  float *pfStack_28;
  float *pfStack_20;
  char cStack_8;
  
  pfVar2 = param_2;
  fStack_44 = param_2[1];
  fStack_48 = *param_2;
  fStack_40 = param_2[2];
  fStack_58 = 1.1305058e-38;
  fVar4 = (float10)func_0x0040a5f0();
  param_2 = (float *)(float)fVar4;
  if (((float10)_DAT_008f07d0 <= fVar4) || ((float)param_2 <= (float)_DAT_008f07c8)) {
    fVar1 = _DAT_008effa0 / (float)param_2;
    fStack_48 = fStack_48 * fVar1;
    fStack_44 = fStack_44 * fVar1;
    fStack_40 = fStack_40 * fVar1;
  }
  else {
    fStack_40 = 0.0;
    fStack_44 = 0.0;
    fStack_48 = 0.0;
    param_2 = (float *)0x0;
  }
  fStack_58 = param_4[2] - param_3[2];
  fStack_5c = param_4[1] - param_3[1];
  fStack_60 = *param_4 - *param_3;
  fStack_64 = 1.1305281e-38;
  func_0x00401ca0();
  fStack_64 = param_2[2] - param_3[2];
  fStack_68 = param_2[1] - param_3[1];
  fStack_6c = *param_2 - *param_3;
  fStack_70 = 1.1305341e-38;
  func_0x00401ca0();
  fStack_70 = fStack_38 * fStack_60 - fStack_5c * fStack_3c;
  fStack_74 = fStack_58 * fStack_3c - fStack_34 * fStack_60;
  fStack_78 = fStack_34 * fStack_5c - fStack_38 * fStack_58;
  fStack_7c = 1.1305449e-38;
  func_0x00401ca0();
  fVar1 = fStack_3c * unaff_EDI + fStack_38 * unaff_ESI + fStack_34 * unaff_EBX;
  if (cStack_8 == '\0') {
    if (fVar1 < _DAT_008f1df4) {
      return 0;
    }
  }
  else if ((fVar1 < _DAT_008f1df4) && (_DAT_008f1df0 < fVar1)) {
    return 0;
  }
  fStack_7c = pfStack_20[2] - param_3[2];
  fStack_80 = pfStack_20[1] - param_3[1];
  fStack_84 = *pfStack_20 - *param_3;
  func_0x00401ca0();
  fVar1 = fStack_6c * fStack_48 + fStack_68 * fStack_44 + fStack_64 * fStack_40;
  if ((_DAT_008f1df0 <= fVar1) && (fVar1 <= (float)pfStack_20 + _DAT_008f1df4)) {
    func_0x00401ca0(fStack_68 * fStack_58 - fStack_64 * fStack_5c,
                    fStack_64 * fStack_60 - fStack_58 * fStack_6c,
                    fStack_5c * fStack_6c - fStack_68 * fStack_60);
    fVar1 = fStack_78 * fStack_84 + fStack_74 * fStack_80 + fStack_70 * fStack_7c;
    if ((_DAT_008f1df0 <= fVar1) &&
       ((((float)pfStack_20 + fVar1 <= (float)puStack_30 &&
         (fVar1 = (fStack_78 * fStack_60 + fStack_70 * fStack_58 + fStack_74 * fStack_5c) /
                  fStack_2c, _DAT_008f1dec <= fVar1)) && (fVar1 <= fStack_34)))) {
      if (fVar1 < _DAT_008effc0) {
        fVar1 = _DAT_008effc0;
      }
      fVar1 = (fVar1 - _DAT_008effc0) / fStack_34;
      func_0x00401ca0(fVar1 * *pfVar2,fVar1 * pfVar2[1],fVar1 * pfVar2[2]);
      puVar3 = (undefined4 *)func_0x004071f0(&stack0xffffffac,pfStack_20,&fStack_84);
      *puStack_30 = *puVar3;
      puStack_30[1] = puVar3[1];
      puStack_30[2] = puVar3[2];
      if (pfStack_28 != (float *)0x0) {
        *pfStack_28 = fStack_2c;
      }
      return 1;
    }
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x007b1d50 | Classified: Angelica3D::proc_7b1d50 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_007b1d50(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  ushort uVar3;
  
  fVar1 = *param_1 - *param_3;
  if (fVar1 < _DAT_008effc4) {
    fVar1 = -fVar1;
  }
  fVar2 = *param_2 + *param_4;
  if (fVar2 < fVar1) {
    return (ushort)(byte)(fVar2 < fVar1 |
                          (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) << 8;
  }
  fVar1 = param_1[1] - param_3[1];
  if (fVar1 < _DAT_008effc4) {
    fVar1 = -fVar1;
  }
  fVar2 = param_2[1] + param_4[1];
  if (fVar2 < fVar1) {
    return (ushort)(byte)(fVar2 < fVar1 |
                          (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) << 8;
  }
  fVar1 = param_1[2] - param_3[2];
  if (fVar1 < _DAT_008effc4) {
    fVar1 = -fVar1;
  }
  fVar2 = param_2[2] + param_4[2];
  uVar3 = (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
          (ushort)(fVar2 == fVar1) << 0xe;
  if (fVar2 < fVar1) {
    return uVar3;
  }
  return CONCAT11((char)(uVar3 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007b1de0 | Classified: Angelica3D::proc_7b1de0 */
/* ==================================================================== */

ushort FUN_007b1de0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  ushort uVar15;
  
  fVar4 = ABS(*param_3);
  fVar5 = ABS(param_3[1]);
  fVar6 = ABS(param_3[2]);
  fVar7 = ABS(param_3[4]);
  fVar8 = ABS(param_3[5]);
  fVar9 = ABS(param_3[6]);
  fVar10 = ABS(param_3[8]);
  fVar11 = ABS(param_3[9]);
  fVar12 = ABS(param_3[10]);
  fVar1 = param_3[0xc];
  fVar2 = param_3[0xd];
  fVar3 = param_3[0xe];
  fVar13 = ABS(fVar1);
  fVar14 = fVar4 * *param_2 + fVar7 * param_2[1] + fVar10 * param_2[2] + *param_1;
  if (fVar14 < fVar13) {
    return (ushort)(byte)(fVar14 < fVar13 |
                          (byte)((ushort)((ushort)(NAN(fVar14) || NAN(fVar13)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar14 == fVar13) << 0xe) >> 8)) << 8;
  }
  fVar13 = ABS(fVar1 * *param_3 + fVar2 * param_3[1] + fVar3 * param_3[2]);
  fVar14 = fVar5 * param_1[1] + fVar6 * param_1[2] + fVar4 * *param_1 + *param_2;
  if (fVar14 < fVar13) {
    return (ushort)(byte)(fVar14 < fVar13 |
                          (byte)((ushort)((ushort)(NAN(fVar14) || NAN(fVar13)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar14 == fVar13) << 0xe) >> 8)) << 8;
  }
  fVar13 = ABS(fVar2);
  fVar14 = fVar5 * *param_2 + fVar8 * param_2[1] + fVar11 * param_2[2] + param_1[1];
  if (fVar14 < fVar13) {
    return (ushort)(byte)(fVar14 < fVar13 |
                          (byte)((ushort)((ushort)(NAN(fVar14) || NAN(fVar13)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar14 == fVar13) << 0xe) >> 8)) << 8;
  }
  fVar13 = ABS(fVar3);
  fVar14 = fVar6 * *param_2 + fVar9 * param_2[1] + fVar12 * param_2[2] + param_1[2];
  if (fVar14 < fVar13) {
    return (ushort)(byte)(fVar14 < fVar13 |
                          (byte)((ushort)((ushort)(NAN(fVar14) || NAN(fVar13)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar14 == fVar13) << 0xe) >> 8)) << 8;
  }
  fVar13 = ABS(fVar1 * param_3[4] + fVar3 * param_3[6] + fVar2 * param_3[5]);
  fVar14 = fVar8 * param_1[1] + fVar9 * param_1[2] + fVar7 * *param_1 + param_2[1];
  if (fVar14 < fVar13) {
    return (ushort)(byte)(fVar14 < fVar13 |
                          (byte)((ushort)((ushort)(NAN(fVar14) || NAN(fVar13)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar14 == fVar13) << 0xe) >> 8)) << 8;
  }
  fVar13 = ABS(fVar2 * param_3[9] + fVar1 * param_3[8] + fVar3 * param_3[10]);
  fVar14 = fVar11 * param_1[1] + fVar12 * param_1[2] + fVar10 * *param_1 + param_2[2];
  if (fVar14 < fVar13) {
    return (ushort)(byte)(fVar14 < fVar13 |
                          (byte)((ushort)((ushort)(NAN(fVar14) || NAN(fVar13)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar14 == fVar13) << 0xe) >> 8)) << 8;
  }
  fVar13 = ABS(fVar3 * param_3[1] - fVar2 * param_3[2]);
  fVar14 = fVar5 * param_1[2] + fVar6 * param_1[1] + fVar7 * param_2[2] + fVar10 * param_2[1];
  if (fVar14 < fVar13) {
    return (ushort)(byte)(fVar14 < fVar13 |
                          (byte)((ushort)((ushort)(NAN(fVar14) || NAN(fVar13)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar14 == fVar13) << 0xe) >> 8)) << 8;
  }
  fVar13 = ABS(fVar3 * param_3[5] - fVar2 * param_3[6]);
  fVar14 = fVar8 * param_1[2] + fVar9 * param_1[1] + fVar4 * param_2[2] + fVar10 * *param_2;
  if (fVar14 < fVar13) {
    return (ushort)(byte)(fVar14 < fVar13 |
                          (byte)((ushort)((ushort)(NAN(fVar14) || NAN(fVar13)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar14 == fVar13) << 0xe) >> 8)) << 8;
  }
  fVar13 = ABS(fVar3 * param_3[9] - fVar2 * param_3[10]);
  fVar14 = fVar11 * param_1[2] + fVar12 * param_1[1] + fVar4 * param_2[1] + fVar7 * *param_2;
  if (fVar14 < fVar13) {
    return (ushort)(byte)(fVar14 < fVar13 |
                          (byte)((ushort)((ushort)(NAN(fVar14) || NAN(fVar13)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar14 == fVar13) << 0xe) >> 8)) << 8;
  }
  fVar13 = ABS(fVar1 * param_3[2] - fVar3 * *param_3);
  fVar14 = fVar4 * param_1[2] + fVar8 * param_2[2] + fVar11 * param_2[1] + fVar6 * *param_1;
  if (fVar14 < fVar13) {
    return (ushort)(byte)(fVar14 < fVar13 |
                          (byte)((ushort)((ushort)(NAN(fVar14) || NAN(fVar13)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar14 == fVar13) << 0xe) >> 8)) << 8;
  }
  fVar13 = ABS(fVar1 * param_3[6] - fVar3 * param_3[4]);
  fVar14 = fVar7 * param_1[2] + fVar5 * param_2[2] + fVar11 * *param_2 + fVar9 * *param_1;
  if (fVar14 < fVar13) {
    return (ushort)(byte)(fVar14 < fVar13 |
                          (byte)((ushort)((ushort)(NAN(fVar14) || NAN(fVar13)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar14 == fVar13) << 0xe) >> 8)) << 8;
  }
  fVar3 = ABS(fVar1 * param_3[10] - fVar3 * param_3[8]);
  fVar13 = fVar10 * param_1[2] + fVar5 * param_2[1] + fVar8 * *param_2 + fVar12 * *param_1;
  if (fVar13 < fVar3) {
    return (ushort)(byte)(fVar13 < fVar3 |
                          (byte)((ushort)((ushort)(NAN(fVar13) || NAN(fVar3)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar13 == fVar3) << 0xe) >> 8)) << 8;
  }
  fVar3 = ABS(fVar2 * *param_3 - fVar1 * param_3[1]);
  fVar4 = fVar4 * param_1[1] + fVar9 * param_2[2] + fVar12 * param_2[1] + fVar5 * *param_1;
  if (fVar4 < fVar3) {
    return (ushort)(byte)(fVar4 < fVar3 |
                          (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar3)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar4 == fVar3) << 0xe) >> 8)) << 8;
  }
  fVar3 = ABS(fVar2 * param_3[4] - fVar1 * param_3[5]);
  fVar4 = fVar7 * param_1[1] + fVar6 * param_2[2] + fVar12 * *param_2 + fVar8 * *param_1;
  if (fVar4 < fVar3) {
    return (ushort)(byte)(fVar4 < fVar3 |
                          (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar3)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar4 == fVar3) << 0xe) >> 8)) << 8;
  }
  fVar1 = ABS(fVar2 * param_3[8] - fVar1 * param_3[9]);
  fVar2 = fVar10 * param_1[1] + fVar6 * param_2[1] + fVar9 * *param_2 + fVar11 * *param_1;
  uVar15 = (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
           (ushort)(fVar2 == fVar1) << 0xe;
  if (fVar2 < fVar1) {
    return uVar15;
  }
  return CONCAT11((char)(uVar15 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007b2220 | Classified: Angelica3D::proc_7b2220 */
/* ==================================================================== */

void FUN_007b2220(float *param_1,undefined4 param_2,float *param_3)

{
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  undefined4 uStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  undefined4 uStack_4;
  
  uStack_14 = 0;
  uStack_24 = 0;
  uStack_34 = 0;
  fStack_40 = param_3[3];
  fStack_3c = param_3[4];
  fStack_38 = param_3[5];
  fStack_2c = param_3[7];
  fStack_20 = param_3[9];
  fStack_18 = param_3[0xb];
  fStack_30 = param_3[6];
  fStack_10 = *param_3 - *param_1;
  fStack_28 = param_3[8];
  fStack_1c = param_3[10];
  fStack_c = param_3[1] - param_1[1];
  uStack_4 = 0x3f800000;
  fStack_8 = param_3[2] - param_1[2];
  FUN_007b1de0(param_2,param_3 + 0x15,&fStack_40);
  return;
}


/* ==================================================================== */
/* Address: 0x007b22c0 | Classified: Angelica3D::proc_7b22c0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_007b22c0(undefined4 *param_1,undefined4 param_2)

{
  param_1[1] = 0;
  param_1[2] = _DAT_009858e4;
  param_1[8] = 0;
  param_1[7] = 0;
  param_1[6] = 0;
  param_1[0xc] = 0;
  param_1[0xb] = 0;
  param_1[9] = 0;
  param_1[0x10] = 0;
  param_1[0xe] = 0;
  param_1[0xd] = 0;
  param_1[0x13] = 0;
  param_1[0x12] = 0;
  param_1[0x11] = 0;
  param_1[0x14] = 0x3f800000;
  param_1[0xf] = 0x3f800000;
  param_1[10] = 0x3f800000;
  param_1[5] = 0x3f800000;
  param_1[0x24] = 0x3f800000;
  param_1[0x1f] = 0x3f800000;
  param_1[0x1a] = 0x3f800000;
  param_1[0x15] = 0x3f800000;
  param_1[0x18] = 0;
  param_1[0x17] = 0;
  param_1[0x16] = 0;
  param_1[0x1c] = 0;
  param_1[0x1b] = 0;
  param_1[0x19] = 0;
  param_1[0x20] = 0;
  param_1[0x1e] = 0;
  param_1[0x1d] = 0;
  param_1[0x23] = 0;
  param_1[0x22] = 0;
  param_1[0x21] = 0;
  *param_1 = &UNK_008f1e68;
  param_1[1] = 0x15;
  param_1[3] = param_2;
  param_1[4] = 0xffffffff;
  param_1[0x47] = 0;
  *(undefined1 *)(param_1 + 0x26) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x007b2370 | Classified: elementclient::A3DSkeletonHook__Duplicate__Not_e@0x7b2370 */
/* ==================================================================== */

int * __thiscall FUN_007b2370(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  iVar1 = func_0x00763250(0x120);
  if (iVar1 != 0) {
    piVar2 = (int *)FUN_007b22c0(param_2);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(*(undefined4 *)(param_1 + 8));
      piVar2[4] = *(int *)(param_1 + 0x10);
      piVar3 = (int *)(param_1 + 0x14);
      piVar4 = piVar2 + 5;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *piVar4 = *piVar3;
        piVar3 = piVar3 + 1;
        piVar4 = piVar4 + 1;
      }
      piVar3 = (int *)(param_1 + 0x14);
      piVar4 = piVar2 + 0x15;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *piVar4 = *piVar3;
        piVar3 = piVar3 + 1;
        piVar4 = piVar4 + 1;
      }
      piVar2[0x25] = *(int *)(param_1 + 0x94);
      return piVar2;
    }
  }
  func_0x007647d0(0x9d2f20,0x98e398);
  return (int *)0x0;
}


/* ==================================================================== */
/* Address: 0x007b2520 | Classified: Angelica3D::proc_7b2520 */
/* ==================================================================== */

void __thiscall FUN_007b2520(int param_1,char param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined1 auStack_8c [12];
  undefined1 auStack_80 [52];
  undefined1 auStack_4c [76];
  
  iVar8 = *(int *)(param_1 + 0x10);
  if (iVar8 < 0) {
    puVar6 = (undefined4 *)func_0x007873a0(auStack_80,param_1 + 0x54,*(int *)(param_1 + 0xc) + 0xc);
    puVar7 = puVar6;
    puVar9 = (undefined4 *)(param_1 + 0x9c);
    for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    puVar7 = (undefined4 *)(param_1 + 0xdc);
    for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    return;
  }
  if ((param_2 != '\0') || (*(int *)(param_1 + 0x11c) != *(int *)(*(int *)(param_1 + 0xc) + 0xc0)))
  {
    iVar4 = *(int *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)(iVar4 + 0xc0);
    if ((iVar8 < 0) || (*(int *)(iVar4 + 0xf0) <= iVar8)) {
      iVar8 = 0;
    }
    else {
      iVar8 = *(int *)(*(int *)(iVar4 + 0xec) + iVar8 * 4);
    }
    uVar5 = *(undefined4 *)(iVar8 + 0x90);
    func_0x00787de0(uVar5,uVar5,uVar5);
    puVar7 = (undefined4 *)func_0x007873a0(auStack_4c,param_1 + 0x54,iVar8 + 0x2a4);
    puVar6 = (undefined4 *)(param_1 + 0xdc);
    puVar9 = puVar6;
    for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    puVar7 = (undefined4 *)func_0x007873a0(auStack_4c,auStack_8c,puVar6);
    cVar3 = *(char *)(param_1 + 0x98);
    puVar9 = (undefined4 *)(param_1 + 0x9c);
    for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    if (cVar3 != '\0') {
      uVar5 = *(undefined4 *)(param_1 + 0xcc);
      uVar1 = *(undefined4 *)(param_1 + 0xd0);
      uVar2 = *(undefined4 *)(param_1 + 0xd4);
      puVar7 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0xc);
      puVar9 = (undefined4 *)(param_1 + 0x9c);
      for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
      }
      *(undefined4 *)(param_1 + 0xcc) = uVar5;
      *(undefined4 *)(param_1 + 0xd0) = uVar1;
      *(undefined4 *)(param_1 + 0xd4) = uVar2;
      uVar5 = *(undefined4 *)(param_1 + 0x10c);
      uVar1 = *(undefined4 *)(param_1 + 0x110);
      uVar2 = *(undefined4 *)(param_1 + 0x114);
      puVar7 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0xc);
      for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar6 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar6 = puVar6 + 1;
      }
      *(undefined4 *)(param_1 + 0x10c) = uVar5;
      *(undefined4 *)(param_1 + 0x110) = uVar1;
      *(undefined4 *)(param_1 + 0x114) = uVar2;
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007b2690 | Classified: Angelica3D::proc_7b2690 */
/* ==================================================================== */

int __fastcall FUN_007b2690(int param_1)

{
  FUN_007b2520(0);
  return param_1 + 0x9c;
}


/* ==================================================================== */
/* Address: 0x007b26b0 | Classified: Angelica3D::proc_7b26b0 */
/* ==================================================================== */

int __fastcall FUN_007b26b0(int param_1)

{
  FUN_007b2520(0);
  return param_1 + 0xdc;
}


/* ==================================================================== */
/* Address: 0x007b26d0 | Classified: Angelica3D::proc_7b26d0 */
/* ==================================================================== */

/* WARNING: Removing unreachable block (ram,0x007b2581) */

void __thiscall FUN_007b26d0(int param_1,undefined1 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined1 auStack_8c [12];
  undefined1 auStack_80 [52];
  undefined1 auStack_4c [76];
  
  *(undefined1 *)(param_1 + 0x98) = param_2;
  iVar8 = *(int *)(param_1 + 0x10);
  if (-1 < iVar8) {
    iVar4 = *(int *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)(iVar4 + 0xc0);
    if ((iVar8 < 0) || (*(int *)(iVar4 + 0xf0) <= iVar8)) {
      iVar8 = 0;
    }
    else {
      iVar8 = *(int *)(*(int *)(iVar4 + 0xec) + iVar8 * 4);
    }
    uVar5 = *(undefined4 *)(iVar8 + 0x90);
    func_0x00787de0(uVar5,uVar5,uVar5);
    puVar7 = (undefined4 *)func_0x007873a0(auStack_4c,param_1 + 0x54,iVar8 + 0x2a4);
    puVar6 = (undefined4 *)(param_1 + 0xdc);
    puVar9 = puVar6;
    for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    puVar7 = (undefined4 *)func_0x007873a0(auStack_4c,auStack_8c,puVar6);
    cVar3 = *(char *)(param_1 + 0x98);
    puVar9 = (undefined4 *)(param_1 + 0x9c);
    for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    if (cVar3 != '\0') {
      uVar5 = *(undefined4 *)(param_1 + 0xcc);
      uVar1 = *(undefined4 *)(param_1 + 0xd0);
      uVar2 = *(undefined4 *)(param_1 + 0xd4);
      puVar7 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0xc);
      puVar9 = (undefined4 *)(param_1 + 0x9c);
      for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
      }
      *(undefined4 *)(param_1 + 0xcc) = uVar5;
      *(undefined4 *)(param_1 + 0xd0) = uVar1;
      *(undefined4 *)(param_1 + 0xd4) = uVar2;
      uVar5 = *(undefined4 *)(param_1 + 0x10c);
      uVar1 = *(undefined4 *)(param_1 + 0x110);
      uVar2 = *(undefined4 *)(param_1 + 0x114);
      puVar7 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0xc);
      for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar6 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar6 = puVar6 + 1;
      }
      *(undefined4 *)(param_1 + 0x10c) = uVar5;
      *(undefined4 *)(param_1 + 0x110) = uVar1;
      *(undefined4 *)(param_1 + 0x114) = uVar2;
    }
    return;
  }
  puVar6 = (undefined4 *)func_0x007873a0(auStack_80,param_1 + 0x54,*(int *)(param_1 + 0xc) + 0xc);
  puVar7 = puVar6;
  puVar9 = (undefined4 *)(param_1 + 0x9c);
  for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar9 = puVar9 + 1;
  }
  puVar7 = (undefined4 *)(param_1 + 0xdc);
  for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007b26f0 | Classified: Angelica3D::proc_7b26f0 */
/* ==================================================================== */

void __fastcall FUN_007b26f0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined1 auStack_c [12];
  
  iVar6 = *(int *)(param_1 + 0xc);
  if ((iVar6 != 0) && (iVar3 = *(int *)(param_1 + 0x10), -1 < iVar3)) {
    if (iVar3 < *(int *)(iVar6 + 0xf0)) {
      iVar6 = *(int *)(*(int *)(iVar6 + 0xec) + iVar3 * 4);
    }
    else {
      iVar6 = 0;
    }
    uStack_18 = *(undefined4 *)(param_1 + 0x44);
    uStack_14 = *(undefined4 *)(param_1 + 0x48);
    uStack_10 = *(undefined4 *)(param_1 + 0x4c);
    puVar5 = (undefined4 *)func_0x00787290(auStack_c,&uStack_18,iVar6 + 0xd4);
    uVar1 = *puVar5;
    uVar4 = puVar5[1];
    uVar2 = puVar5[2];
    puVar5 = (undefined4 *)(param_1 + 0x14);
    puVar7 = (undefined4 *)(param_1 + 0x54);
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
    *(undefined4 *)(param_1 + 0x84) = uVar1;
    *(undefined4 *)(param_1 + 0x8c) = uVar2;
    *(undefined4 *)(param_1 + 0x88) = uVar4;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007b2780 | Classified: Angelica3D::proc_7b2780 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_007b2780(undefined4 *param_1)

{
  FUN_007b0af0();
  param_1[0x2e] = _DAT_009858e4;
  param_1[0x3a] = &UNK_008d5a30;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0x10;
  param_1[0x39] = &UNK_008f1ec0;
  param_1[0x40] = &UNK_008d5a30;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0x10;
  param_1[0x3f] = &UNK_008f1ebc;
  param_1[0x46] = &UNK_008d5a30;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0x10;
  param_1[0x45] = &UNK_008f1eb8;
  param_1[0x4f] = 0x10;
  param_1[0x4b] = &UNK_008d7440;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x2f] = 0;
  param_1[0x2d] = 0;
  param_1[0x30] = 0;
  param_1[0x35] = 0;
  *(undefined1 *)(param_1 + 0x36) = 0;
  *param_1 = &UNK_008f1e78;
  param_1[1] = 0x17;
  param_1[0x31] = 0xffffffff;
  param_1[0x32] = 0xffffffff;
  param_1[0x34] = 0xf;
  param_1[0x33] = 6;
  param_1[0x37] = 0xffffffff;
  param_1[0x38] = 0x3f800000;
  return param_1;
}


