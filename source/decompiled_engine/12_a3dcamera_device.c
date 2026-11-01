/* Authentic Ghidra 12.1.4 Decompilation — elementclient.exe (PW 1.4.2 Build 2305) */
/* Module: 12_a3dcamera_device.c */

/* ==================================================================== */
/* Address: 0x00765000 | Classified: AngelicaFile::proc_765000 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __thiscall FUN_00765000(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  if (iVar1 == _DAT_00985a98) {
    *param_1 = _DAT_00985a98;
    return param_1;
  }
  if (*(int *)(iVar1 + -0xc) == -1) {
    iVar1 = func_0x00764ed0(iVar1,*(undefined4 *)(iVar1 + -8));
    *param_1 = iVar1;
    return param_1;
  }
  *(int *)(iVar1 + -0xc) = *(int *)(iVar1 + -0xc) + 1;
  *param_1 = *param_2;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00765050 | Classified: AngelicaFile::proc_765050 */
/* ==================================================================== */

undefined4 * __thiscall FUN_00765050(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = wcslen(param_2);
    uVar1 = func_0x00764ed0(param_2,uVar1);
    *param_1 = uVar1;
    return param_1;
  }
  uVar1 = func_0x00764ed0(0,0);
  *param_1 = uVar1;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00765090 | Classified: AngelicaFile::proc_765090 */
/* ==================================================================== */

undefined4 * __thiscall FUN_00765090(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = func_0x00764ed0(param_2,param_3);
  *param_1 = uVar1;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007650b0 | Classified: AngelicaFile::proc_7650b0 */
/* ==================================================================== */

int * __thiscall FUN_007650b0(int *param_1,undefined2 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = func_0x00764d60(param_3);
  *param_1 = iVar1;
  iVar1 = 0;
  if (0 < param_3) {
    do {
      iVar1 = iVar1 + 1;
      *(undefined2 *)(*param_1 + -2 + iVar1 * 2) = param_2;
    } while (iVar1 < param_3);
  }
  *(undefined2 *)(*param_1 + param_3 * 2) = 0;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007650f0 | Classified: AngelicaFile::proc_7650f0 */
/* ==================================================================== */

undefined4 * __thiscall FUN_007650f0(undefined4 *param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  
  uVar1 = func_0x00764fa0(*param_2,*param_3,*(undefined4 *)(*param_2 + -8),
                          *(undefined4 *)(*param_3 + -8));
  *param_1 = uVar1;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00765120 | Classified: AngelicaFile::proc_765120 */
/* ==================================================================== */

undefined4 * __thiscall FUN_00765120(undefined4 *param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  
  uVar1 = func_0x00764f60(param_2,*param_3,*(int *)(*param_3 + -8) + 1);
  *param_1 = uVar1;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00765150 | Classified: AngelicaFile::proc_765150 */
/* ==================================================================== */

undefined4 * __thiscall FUN_00765150(undefined4 *param_1,int *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = func_0x00764f00(*param_2,param_3,*(int *)(*param_2 + -8) + 1);
  *param_1 = uVar1;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00765180 | Classified: AngelicaFile::proc_765180 */
/* ==================================================================== */

undefined4 * __thiscall FUN_00765180(undefined4 *param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(*param_3 + -8);
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = wcslen(param_2);
  }
  uVar2 = func_0x00764fa0(param_2,*param_3,uVar1,uVar2);
  *param_1 = uVar2;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007651c0 | Classified: AngelicaFile::proc_7651c0 */
/* ==================================================================== */

undefined4 * __thiscall FUN_007651c0(undefined4 *param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = wcslen(param_3);
  }
  uVar1 = func_0x00764fa0(*param_2,param_3,*(undefined4 *)(*param_2 + -8),uVar1);
  *param_1 = uVar1;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00765200 | Classified: AngelicaFile::proc_765200 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00765200(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(*param_1 + -0xc);
  if (*piVar1 == -1) {
    *piVar1 = 1;
  }
  func_0x00764e30(piVar1);
  *param_1 = _DAT_00985a98;
  return;
}


/* ==================================================================== */
/* Address: 0x00765230 | Classified: AngelicaFile::proc_765230 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __thiscall FUN_00765230(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 != 0) {
    iVar2 = wcslen(param_2);
    if (iVar2 != 0) {
      iVar1 = *param_1;
      if (1 < *(int *)(iVar1 + -0xc)) {
        *(int *)(iVar1 + -0xc) = *(int *)(iVar1 + -0xc) + -1;
        iVar2 = func_0x00764ed0(param_2,iVar2);
        *param_1 = iVar2;
        return param_1;
      }
      if (iVar2 <= *(int *)(iVar1 + -4)) {
        func_0x00764e50(iVar1,param_2,iVar2);
        *(int *)(iVar1 + -8) = iVar2;
        return param_1;
      }
      func_0x00764e30((int *)(iVar1 + -0xc));
      iVar2 = func_0x00764ed0(param_2,iVar2);
      *param_1 = iVar2;
      return param_1;
    }
  }
  func_0x00764e30(*param_1 + -0xc);
  *param_1 = _DAT_00985a98;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007652d0 | Classified: AngelicaFile::proc_7652d0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __thiscall FUN_007652d0(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  iVar1 = *param_2;
  if (iVar2 != iVar1) {
    if (iVar1 == _DAT_00985a98) {
      func_0x00764e30(iVar2 + -0xc);
      *param_1 = _DAT_00985a98;
      return param_1;
    }
    if (*(int *)(iVar1 + -0xc) == -1) {
      if (1 < *(int *)(iVar2 + -0xc)) {
        *(int *)(iVar2 + -0xc) = *(int *)(iVar2 + -0xc) + -1;
        iVar2 = func_0x00764ed0(*param_2,*(undefined4 *)(iVar1 + -8));
        *param_1 = iVar2;
        return param_1;
      }
      if (*(int *)(iVar1 + -8) <= *(int *)(iVar2 + -4)) {
        func_0x00764e50(iVar2,iVar1,*(int *)(iVar1 + -8));
        *(undefined4 *)(iVar2 + -8) = *(undefined4 *)(iVar1 + -8);
        return param_1;
      }
      func_0x00764e30((int *)(iVar2 + -0xc));
      iVar2 = func_0x00764ed0(*param_2,*(undefined4 *)(iVar1 + -8));
      *param_1 = iVar2;
      return param_1;
    }
    func_0x00764e30(iVar2 + -0xc);
    *(int *)(iVar1 + -0xc) = *(int *)(iVar1 + -0xc) + 1;
    *param_1 = *param_2;
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007653b0 | Classified: AngelicaFile::proc_7653b0 */
/* ==================================================================== */

int * __thiscall FUN_007653b0(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  if ((short)param_2 != 0) {
    iVar1 = *param_1;
    if (1 < *(int *)(iVar1 + -0xc)) {
      *(int *)(iVar1 + -0xc) = *(int *)(iVar1 + -0xc) + -1;
      iVar1 = func_0x00764f00(*param_1,param_2,*(int *)(iVar1 + -8) + 1);
      *param_1 = iVar1;
      return param_1;
    }
    iVar2 = *(int *)(iVar1 + -8) + 1;
    if (iVar2 <= *(int *)(iVar1 + -4)) {
      *(short *)(iVar1 + -2 + iVar2 * 2) = (short)param_2;
      *(undefined2 *)(*param_1 + iVar2 * 2) = 0;
      *(int *)(iVar1 + -8) = *(int *)(iVar1 + -8) + 1;
      return param_1;
    }
    iVar2 = func_0x00764f00(iVar1,param_2,iVar2);
    *param_1 = iVar2;
    func_0x00764e30((int *)(iVar1 + -0xc));
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00765430 | Classified: AngelicaFile::proc_765430 */
/* ==================================================================== */

int * __thiscall FUN_00765430(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 != 0) {
    iVar3 = wcslen(param_2);
    if (iVar3 != 0) {
      iVar1 = *param_1;
      if (1 < *(int *)(iVar1 + -0xc)) {
        *(int *)(iVar1 + -0xc) = *(int *)(iVar1 + -0xc) + -1;
        iVar3 = func_0x00764fa0(*param_1,param_2,*(undefined4 *)(iVar1 + -8),iVar3);
        *param_1 = iVar3;
        return param_1;
      }
      iVar2 = *(int *)(iVar1 + -8);
      if (iVar2 + iVar3 <= iVar2) {
        func_0x00764e50(iVar1 + iVar2 * 2,param_2);
        *(int *)(iVar1 + -8) = iVar2 + iVar3;
        return param_1;
      }
      iVar3 = func_0x00764fa0(iVar1,param_2,iVar2,iVar3);
      *param_1 = iVar3;
      func_0x00764e30((int *)(iVar1 + -0xc));
    }
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007654c0 | Classified: AngelicaFile::proc_7654c0 */
/* ==================================================================== */

int * __thiscall FUN_007654c0(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *param_2;
  iVar1 = *(int *)(iVar4 + -8);
  if (iVar1 != 0) {
    iVar2 = *param_1;
    if (1 < *(int *)(iVar2 + -0xc)) {
      *(int *)(iVar2 + -0xc) = *(int *)(iVar2 + -0xc) + -1;
      iVar4 = func_0x00764fa0(*param_1,*param_2,*(undefined4 *)(iVar2 + -8),iVar1);
      *param_1 = iVar4;
      return param_1;
    }
    iVar3 = *(int *)(iVar2 + -8);
    if (iVar3 + iVar1 <= *(int *)(iVar2 + -4)) {
      func_0x00764e50(iVar2 + iVar3 * 2,iVar4);
      *(int *)(iVar2 + -8) = iVar3 + iVar1;
      return param_1;
    }
    iVar4 = func_0x00764fa0(iVar2,iVar4,iVar3,iVar1);
    *param_1 = iVar4;
    func_0x00764e30((int *)(iVar2 + -0xc));
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00765550 | Classified: AngelicaFile::proc_765550 */
/* ==================================================================== */

undefined4 __thiscall FUN_00765550(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*param_1 == param_2) {
    return 0;
  }
  uVar1 = wcscmp(*param_1,param_2);
  return uVar1;
}


/* ==================================================================== */
/* Address: 0x00765570 | Classified: AngelicaFile::proc_765570 */
/* ==================================================================== */

undefined4 __thiscall FUN_00765570(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*param_1 == param_2) {
    return 0;
  }
  uVar1 = _wcsicmp(*param_1,param_2);
  return uVar1;
}


/* ==================================================================== */
/* Address: 0x00765590 | Classified: AngelicaFile::proc_765590 */
/* ==================================================================== */

void __thiscall FUN_00765590(int *param_1,undefined4 param_2)

{
  func_0x00764e90(*param_1,param_2,*(int *)(*param_1 + -8) + 1);
  return;
}


/* ==================================================================== */
/* Address: 0x007655b0 | Classified: AngelicaFile::proc_7655b0 */
/* ==================================================================== */

int __thiscall FUN_007655b0(int *param_1,int *param_2)

{
  int iVar1;
  uint3 uVar3;
  int iVar2;
  
  iVar2 = *param_1;
  iVar1 = *param_2;
  uVar3 = (uint3)((uint)iVar2 >> 8);
  if (iVar2 == iVar1) {
    return CONCAT31(uVar3,1);
  }
  if (*(int *)(iVar2 + -8) != *(int *)(iVar1 + -8)) {
    return (uint)uVar3 << 8;
  }
  iVar2 = func_0x00764e90(iVar2,iVar1,*(int *)(iVar2 + -8));
  return iVar2;
}


/* ==================================================================== */
/* Address: 0x007655e0 | Classified: AngelicaFile::proc_7655e0 */
/* ==================================================================== */

int __thiscall FUN_007655e0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*param_1 + -0xc);
  if (1 < iVar1) {
    *(int *)(*param_1 + -0xc) = iVar1 + -1;
    iVar1 = func_0x00764ed0(*param_1,*(undefined4 *)(*param_1 + -8));
    *param_1 = iVar1;
  }
  return *param_1 + param_2 * 2;
}


/* ==================================================================== */
/* Address: 0x00765610 | Classified: AngelicaFile::proc_765610 */
/* ==================================================================== */

void __fastcall FUN_00765610(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + -8) != 0) {
    if (1 < *(int *)(iVar1 + -0xc)) {
      *(int *)(iVar1 + -0xc) = *(int *)(iVar1 + -0xc) + -1;
      iVar1 = func_0x00764ed0(*param_1,*(int *)(iVar1 + -8));
      *param_1 = iVar1;
    }
    _wcsupr(*param_1);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00765650 | Classified: AngelicaFile::proc_765650 */
/* ==================================================================== */

void __fastcall FUN_00765650(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + -8) != 0) {
    if (1 < *(int *)(iVar1 + -0xc)) {
      *(int *)(iVar1 + -0xc) = *(int *)(iVar1 + -0xc) + -1;
      iVar1 = func_0x00764ed0(*param_1,*(int *)(iVar1 + -8));
      *param_1 = iVar1;
    }
    _wcslwr(*param_1);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00765690 | Classified: AngelicaFile::proc_765690 */
/* ==================================================================== */

int * FUN_00765690(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_00765850(param_2,&stack0x0000000c);
  iVar2 = *param_1;
  if (*(int *)(iVar2 + -0xc) < 2) {
    if (iVar1 + 1 <= *(int *)(iVar2 + -4)) {
      vswprintf(iVar2,param_2,&stack0x0000000c);
      if (*param_1 != 0) {
        uVar3 = wcslen(*param_1);
        *(undefined4 *)(iVar2 + -8) = uVar3;
        return param_1;
      }
      *(undefined4 *)(iVar2 + -8) = 0;
      return param_1;
    }
    func_0x00764e30((int *)(iVar2 + -0xc));
  }
  else {
    *(int *)(iVar2 + -0xc) = *(int *)(iVar2 + -0xc) + -1;
  }
  iVar2 = func_0x00764d60(iVar1 + 1);
  *param_1 = iVar2;
  vswprintf(iVar2,param_2,&stack0x0000000c);
  if (*param_1 != 0) {
    uVar3 = wcslen(*param_1);
    *(undefined4 *)(*param_1 + -8) = uVar3;
    return param_1;
  }
  *(undefined4 *)(*param_1 + -8) = 0;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00765750 | Classified: AngelicaFile::proc_765750 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_00765750(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 < 0) {
    return 0;
  }
  if (param_2 == 0) {
    param_2 = 1;
  }
  iVar2 = *param_1;
  piVar1 = (int *)(iVar2 + -0xc);
  if (iVar2 == _DAT_00985a98) {
    iVar2 = func_0x00764d60(param_2);
    *param_1 = iVar2;
    return iVar2;
  }
  if (*piVar1 < 2) {
    if (*(int *)(iVar2 + -4) < param_2) {
      iVar4 = func_0x00764d60(param_2);
      *param_1 = iVar4;
      func_0x00764e50(iVar4,iVar2,*(undefined4 *)(iVar2 + -8));
      *(undefined4 *)(*param_1 + -8) = *(undefined4 *)(iVar2 + -8);
      func_0x00764e30(piVar1);
    }
    return *param_1;
  }
  *piVar1 = *piVar1 + -1;
  if (param_2 <= *(int *)(iVar2 + -8)) {
    iVar2 = func_0x00764ed0(*param_1,*(int *)(iVar2 + -8));
    *param_1 = iVar2;
    return iVar2;
  }
  iVar4 = *param_1;
  iVar3 = func_0x00764d60(param_2);
  *param_1 = iVar3;
  func_0x00764e50(iVar3,iVar4,*(undefined4 *)(iVar2 + -8));
  *(undefined4 *)(*param_1 + -8) = *(undefined4 *)(iVar2 + -8);
  return *param_1;
}


/* ==================================================================== */
/* Address: 0x00765810 | Classified: AngelicaFile::proc_765810 */
/* ==================================================================== */

void __thiscall FUN_00765810(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + -0xc) == 1) {
    if (param_2 == -1) {
      if (iVar1 == 0) {
        param_2 = 0;
      }
      else {
        param_2 = wcslen(iVar1);
      }
    }
    if (param_2 <= *(int *)(iVar1 + -4)) {
      *(int *)(iVar1 + -8) = param_2;
      *(undefined2 *)(*param_1 + param_2 * 2) = 0;
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00765850 | Classified: AngelicaFile::proc_765850 */
/* ==================================================================== */

int FUN_00765850(ushort *param_1,int *param_2)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  ushort *puVar7;
  ushort *puVar8;
  int iVar9;
  char *pcVar10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  if ((param_1 == (ushort *)0x0) || (*param_1 == 0)) {
    return 0;
  }
  iStack_8 = 0;
  iStack_c = 0;
  iStack_4 = 0;
  do {
    puVar8 = param_1;
    if (*param_1 != 0x25) {
LAB_00765b53:
      iStack_c = iStack_c + 1;
      goto LAB_00765b58;
    }
    uVar2 = param_1[1];
    puVar8 = param_1 + 1;
    if (uVar2 == 0x25) goto LAB_00765b53;
    iVar9 = 0;
    iVar4 = 0;
    param_1 = (ushort *)0x0;
    if (uVar2 == 0) {
LAB_007658f6:
      iVar4 = _wtoi();
      uVar2 = *puVar8;
      while (((piVar6 = param_2, param_1 = (ushort *)iVar4, uVar2 != 0 && (0x2f < uVar2)) &&
             (uVar2 < 0x3a))) {
        puVar7 = puVar8 + 1;
        puVar8 = puVar8 + 1;
        uVar2 = *puVar7;
      }
    }
    else {
      do {
        if (uVar2 == 0x23) {
          iStack_c = iStack_c + 2;
        }
        else if (uVar2 == 0x2a) {
          iVar4 = *param_2;
          param_2 = param_2 + 1;
          param_1 = (ushort *)iVar4;
        }
        else if ((((uVar2 != 0x2d) && (uVar2 != 0x2b)) && (uVar2 != 0x30)) && (uVar2 != 0x20))
        break;
        uVar2 = puVar8[1];
        puVar8 = puVar8 + 1;
      } while (uVar2 != 0);
      piVar6 = param_2;
      if (iVar4 == 0) goto LAB_007658f6;
    }
    iVar5 = 0;
    if (*puVar8 == 0x2e) {
      puVar7 = puVar8 + 1;
      if (*puVar7 == 0x2a) {
        iVar5 = *piVar6;
        piVar6 = piVar6 + 1;
        puVar8 = puVar8 + 2;
      }
      else {
        iVar5 = _wtoi();
        uVar2 = *puVar7;
        puVar8 = puVar7;
        while (((iVar4 = (int)param_1, uVar2 != 0 && (0x2f < uVar2)) && (uVar2 < 0x3a))) {
          puVar7 = puVar8 + 1;
          puVar8 = puVar8 + 1;
          uVar2 = *puVar7;
        }
      }
    }
    switch(*puVar8) {
    case 0x46:
    case 0x4c:
    case 0x4e:
    case 0x68:
    case 0x6c:
      puVar8 = puVar8 + 1;
    }
    param_2 = piVar6;
    switch(*puVar8) {
    case 0x43:
    case 99:
      iVar9 = 2;
      break;
    default:
LAB_00765a3f:
      switch(*puVar8) {
      case 0x47:
      case 0x65:
      case 0x67:
        param_2 = param_2 + 2;
        if (iVar5 + iVar4 < 0x81) {
          iStack_c = iStack_c + 0x80;
        }
        else {
          iStack_c = iStack_c + iVar5 + iVar4;
        }
        break;
      default:
        goto LAB_00765b45;
      case 0x58:
      case 100:
      case 0x69:
      case 0x6f:
      case 0x70:
      case 0x75:
      case 0x78:
        param_2 = param_2 + 1;
        if (iVar5 + iVar4 < 0x21) {
          iStack_c = iStack_c + 0x20;
        }
        else {
          iStack_c = iStack_c + iVar5 + iVar4;
        }
        break;
      case 0x66:
        iVar9 = iVar5 + 0x13e;
        if (iVar5 + 0x13e < iVar4) {
          iVar9 = iVar4;
        }
        if (iStack_4 < iVar9) {
          iStack_4 = iVar9;
          if (iStack_8 == 0) {
            iStack_8 = func_0x007631a0();
            iVar4 = (int)param_1;
          }
          else {
            iStack_8 = func_0x007631c0(iStack_8,iVar9);
            iVar4 = (int)param_1;
          }
        }
        param_2 = param_2 + 2;
        swprintf(iStack_8,0x985a9c,iVar4,iVar5 + 6);
        iVar4 = wcslen(iStack_8);
        iStack_c = iStack_c + iVar4;
        break;
      case 0x6e:
        param_2 = param_2 + 1;
        goto LAB_00765b45;
      }
      goto LAB_00765b58;
    case 0x53:
      pcVar10 = (char *)*piVar6;
      if (pcVar10 == (char *)0x0) {
        iVar9 = 6;
      }
      else if (*pcVar10 == '\0') {
        iVar9 = 1;
      }
      else {
        uVar3 = 0xffffffff;
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar1 != '\0');
        iVar9 = ~uVar3 - 1;
code_r0x00765a16:
        param_2 = piVar6 + 1;
        if (iVar9 == 0) goto LAB_00765a3f;
      }
      break;
    case 0x73:
      if ((short *)*piVar6 == (short *)0x0) {
        iVar9 = 6;
      }
      else {
        if (*(short *)*piVar6 != 0) {
          iVar9 = wcslen();
          iVar4 = (int)param_1;
          goto code_r0x00765a16;
        }
        iVar9 = 1;
      }
    }
    param_2 = piVar6 + 1;
    if ((iVar5 != 0) && (iVar5 < iVar9)) {
      iVar9 = iVar5;
    }
    if (iVar9 < iVar4) {
      iStack_c = iStack_c + iVar4;
    }
    else {
LAB_00765b45:
      iStack_c = iStack_c + iVar9;
    }
LAB_00765b58:
    param_1 = puVar8 + 1;
    if (*param_1 == 0) {
      if (iStack_8 != 0) {
        func_0x007631b0(iStack_8);
      }
      return iStack_c;
    }
  } while( true );
}


/* ==================================================================== */
/* Address: 0x00765c50 | Classified: AngelicaFile::proc_765c50 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00765c50(int *param_1,int param_2)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  iVar2 = *param_1;
  if ((*(int *)(iVar2 + -8) != 0) && (0 < param_2)) {
    piVar5 = (int *)(iVar2 + -0xc);
    if (*(int *)(iVar2 + -8) <= param_2) {
      func_0x00764e30(piVar5);
      *param_1 = _DAT_00985a98;
      return;
    }
    iVar4 = *(int *)(iVar2 + -8) - param_2;
    if (1 < *piVar5) {
      *piVar5 = *piVar5 + -1;
      iVar2 = func_0x00764ed0(*param_1 + param_2 * 2,iVar4);
      *param_1 = iVar2;
      return;
    }
    iVar3 = 0;
    if (0 < iVar4) {
      param_2 = param_2 * 2;
      do {
        iVar3 = iVar3 + 1;
        puVar1 = (undefined2 *)(param_2 + *param_1);
        param_2 = param_2 + 2;
        *(undefined2 *)(*param_1 + -2 + iVar3 * 2) = *puVar1;
      } while (iVar3 < iVar4);
    }
    *(undefined2 *)(*param_1 + iVar4 * 2) = 0;
    *(int *)(iVar2 + -8) = iVar4;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00765ce0 | Classified: AngelicaFile::proc_765ce0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00765ce0(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if ((*(int *)(iVar2 + -8) != 0) && (0 < param_2)) {
    piVar1 = (int *)(iVar2 + -0xc);
    if (*(int *)(iVar2 + -8) <= param_2) {
      func_0x00764e30(piVar1);
      *param_1 = _DAT_00985a98;
      return;
    }
    param_2 = *(int *)(iVar2 + -8) - param_2;
    if (1 < *piVar1) {
      *piVar1 = *piVar1 + -1;
      iVar2 = func_0x00764ed0(*param_1,param_2);
      *param_1 = iVar2;
      return;
    }
    *(undefined2 *)(iVar2 + param_2 * 2) = 0;
    *(int *)(iVar2 + -8) = param_2;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00765d50 | Classified: AngelicaFile::proc_765d50 */
/* ==================================================================== */

void __fastcall FUN_00765d50(undefined4 *param_1)

{
  ushort *puVar1;
  ushort uVar2;
  ushort *puVar3;
  int iVar4;
  
  puVar3 = (ushort *)*param_1;
  if (*(int *)(puVar3 + -4) != 0) {
    iVar4 = 0;
    uVar2 = *puVar3;
    while ((uVar2 != 0 && (uVar2 < 0x21))) {
      puVar1 = puVar3 + 1;
      puVar3 = puVar3 + 1;
      iVar4 = iVar4 + 1;
      uVar2 = *puVar1;
    }
    FUN_00765c50(iVar4);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00765d80 | Classified: AngelicaFile::proc_765d80 */
/* ==================================================================== */

void __fastcall FUN_00765d80(int *param_1)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  
  iVar1 = *(int *)(*param_1 + -8);
  if (iVar1 != 0) {
    iVar2 = iVar1 + -1;
    if (-1 < iVar2) {
      puVar3 = (ushort *)(*param_1 + iVar2 * 2);
      do {
        if (0x20 < *puVar3) break;
        iVar2 = iVar2 + -1;
        puVar3 = puVar3 + -1;
      } while (-1 < iVar2);
    }
    FUN_00765ce0((iVar1 - iVar2) + -1);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00765db0 | Classified: AngelicaFile::proc_765db0 */
/* ==================================================================== */

void __thiscall FUN_00765db0(int *param_1,short *param_2)

{
  int iVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  
  iVar1 = *(int *)(*param_1 + -8);
  if (iVar1 != 0) {
    iVar4 = iVar1 + -1;
    if (-1 < iVar4) {
      psVar5 = (short *)(*param_1 + iVar4 * 2);
      do {
        iVar3 = 0;
        if (*param_2 != 0) {
          sVar2 = *param_2;
          do {
            if (*psVar5 == sVar2) break;
            sVar2 = param_2[iVar3 + 1];
            iVar3 = iVar3 + 1;
          } while (sVar2 != 0);
        }
        if (param_2[iVar3] == 0) break;
        iVar4 = iVar4 + -1;
        psVar5 = psVar5 + -1;
      } while (-1 < iVar4);
    }
    FUN_00765ce0((iVar1 - iVar4) + -1);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00765e20 | Classified: AngelicaFile::proc_765e20 */
/* ==================================================================== */

int __thiscall FUN_00765e20(int *param_1,short param_2,int param_3)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = *(int *)(*param_1 + -8);
  if (((iVar1 != 0) && (-1 < param_3)) && (param_3 < iVar1)) {
    psVar2 = (short *)(*param_1 + param_3 * 2);
    do {
      if (*psVar2 == param_2) {
        return param_3;
      }
      param_3 = param_3 + 1;
      psVar2 = psVar2 + 1;
    } while (param_3 < iVar1);
  }
  return -1;
}


/* ==================================================================== */
/* Address: 0x00765e60 | Classified: AngelicaFile::proc_765e60 */
/* ==================================================================== */

int __thiscall FUN_00765e60(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(*param_1 + -8);
  if (((iVar1 != 0) && (-1 < param_3)) && (param_3 < iVar1)) {
    iVar1 = wcsstr(*param_1 + param_3 * 2,param_2);
    if (iVar1 != 0) {
      return iVar1 - *param_1 >> 1;
    }
  }
  return -1;
}


/* ==================================================================== */
/* Address: 0x00765ea0 | Classified: AngelicaFile::proc_765ea0 */
/* ==================================================================== */

int __thiscall FUN_00765ea0(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(int *)(*param_1 + -8) == 0) {
    return -1;
  }
  iVar1 = wcsrchr(*param_1,param_2);
  if (iVar1 == 0) {
    return -1;
  }
  return iVar1 - *param_1 >> 1;
}


/* ==================================================================== */
/* Address: 0x00765ee0 | Classified: AngelicaFile::proc_765ee0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ** __fastcall FUN_00765ee0(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  undefined8 uVar7;
  longlong lVar8;
  undefined4 **ppuVar9;
  int iVar10;
  int iVar11;
  undefined4 uStack_80;
  undefined8 uStack_7c;
  undefined8 uStack_74;
  uint uStack_6c;
  int iStack_68;
  undefined4 *puStack_54;
  undefined1 auStack_50 [12];
  int iStack_44;
  longlong lStack_40;
  
  *param_1 = &UNK_008eff90;
  param_1[1] = 0;
  param_1[3] = 0x42700000;
  param_1[2] = 0;
  puStack_54 = param_1;
  lVar6 = FUN_00766140();
  iVar3 = (int)((ulonglong)lVar6 >> 0x20);
  lStack_40 = FUN_00766250();
  do {
    do {
      uVar7 = FUN_00766140();
      iVar11 = (int)((ulonglong)uVar7 >> 0x20);
      uVar4 = (uint)((uint)uVar7 < (uint)lVar6);
      iVar10 = iVar11 - iVar3;
      iStack_44 = iVar10 - uVar4;
    } while (iStack_44 < 0);
  } while ((iStack_44 == 0 || SBORROW4(iVar11,iVar3) != SBORROW4(iVar10,uVar4)) &&
          ((uint)uVar7 - (uint)lVar6 < 1000));
  iStack_68 = 0x765f33;
  lVar8 = FUN_00766140();
  iStack_68 = 0x765f3c;
  uStack_74 = FUN_00766250();
  iStack_68 = 0;
  uStack_74 = uStack_74 - lStack_40;
  uStack_6c = 1000000;
  uStack_7c._4_4_ = 0x765f56;
  uVar7 = func_0x00892fa0();
  uStack_80 = (undefined4)((ulonglong)uVar7 >> 0x20);
  uStack_7c = lVar8 - lVar6;
  _DAT_00985aa8 = func_0x00892fe0((int)uVar7);
  timeGetTime();
  uVar7 = FUN_00766140();
  iVar10 = (int)uVar7;
  iVar11 = 1000;
  uVar1 = func_0x00892fe0(uVar7,1000,0);
  uStack_7c._0_4_ = uVar1;
  GetLocalTime();
  ppuVar9 = &puStack_54;
  SystemTimeToFileTime(ppuVar9,&uStack_6c);
  iVar3 = uStack_74._4_4_;
  uVar4 = (uint)uStack_74;
  do {
    timeGetTime();
    uVar7 = FUN_00766140();
    iVar2 = func_0x00892fe0(uVar7,1000,0);
    GetLocalTime(&stack0xffffffa4);
    SystemTimeToFileTime(&stack0xffffffa0,&uStack_80);
    if (iStack_68 - iVar3 != (uint)(uStack_6c < uVar4)) break;
  } while ((undefined *)(uStack_6c - uVar4) < &UNK_004c4b41);
  iVar3 = func_0x00893160(uStack_6c - uVar4,(iStack_68 - iVar3) - (uint)(uStack_6c < uVar4),10000,0)
  ;
  uVar4 = (iVar2 - iVar3) - (int)auStack_50;
  uVar5 = (int)uVar4 >> 0x1f;
  if (200 < (int)((uVar4 ^ uVar5) - uVar5)) {
    DAT_009d2c00 = 1;
  }
  uVar4 = (iVar10 - iVar3) - iVar11;
  uVar5 = (int)uVar4 >> 0x1f;
  if (200 < (int)((uVar4 ^ uVar5) - uVar5)) {
    DAT_009d2c01 = 1;
  }
  return ppuVar9;
}


/* ==================================================================== */
/* Address: 0x00766070 | Classified: AngelicaFile::proc_766070 */
/* ==================================================================== */

undefined4 __thiscall FUN_00766070(undefined4 param_1,byte param_2)

{
  FUN_00766090();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00766090 | Classified: AngelicaFile::proc_766090 */
/* ==================================================================== */

void __fastcall FUN_00766090(undefined4 *param_1)

{
  *param_1 = &UNK_008eff90;
  return;
}


/* ==================================================================== */
/* Address: 0x007660a0 | Classified: AngelicaFile::proc_7660a0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007660a0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = func_0x00763330();
  *(undefined4 *)(param_1 + 4) = uVar1;
  *(undefined4 *)(param_1 + 0xc) = 0x42700000;
  *(undefined4 *)(param_1 + 8) = 0;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007660c0 | Classified: AngelicaFile::proc_7660c0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_007660c0(int param_1,undefined1 *param_2)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = func_0x00763330();
  uVar4 = *(int *)(param_1 + 8) + 1;
  *(uint *)(param_1 + 8) = uVar4;
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 + 1000U < uVar3) {
    *(uint *)(param_1 + 4) = uVar3;
    fVar2 = (float)uVar4 * _DAT_008eff94;
    *(undefined4 *)(param_1 + 8) = 0;
    *(float *)(param_1 + 0xc) = fVar2 / (float)(int)(uVar3 - iVar1);
    if (param_2 != (undefined1 *)0x0) {
      *param_2 = 1;
      return 1;
    }
  }
  else if (param_2 != (undefined1 *)0x0) {
    *param_2 = 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00766140 | Classified: AngelicaFile::proc_766140 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_00766140(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  undefined4 uStack_20;
  undefined1 auStack_1c [8];
  undefined1 auStack_14 [4];
  undefined1 auStack_10 [16];
  
  if (DAT_009d2c01 != '\0') {
    puVar3 = auStack_10;
    GetLocalTime(puVar3);
    SystemTimeToFileTime(auStack_14,auStack_1c);
    puVar3 = (undefined1 *)func_0x00892fa0(puVar3,uStack_20,1000,0);
    return puVar3;
  }
  if (DAT_009d2c00 != '\0') {
    iVar4 = timeGetTime();
    return (undefined1 *)(iVar4 * 1000);
  }
  if (DAT_00985ab0 != '\0') {
    iVar4 = QueryPerformanceFrequency(&DAT_009d2bf8);
    if (iVar4 == 0) {
      return (undefined1 *)0x0;
    }
    DAT_00985ab0 = '\0';
  }
  puVar6 = &uStack_20;
  iVar4 = QueryPerformanceCounter();
  uVar2 = _DAT_009d2bfc;
  uVar1 = _DAT_009d2bf8;
  if (iVar4 == 0) {
    return (undefined1 *)0x0;
  }
  uVar5 = func_0x00893090(puVar6,uStack_20,_DAT_009d2bf8,_DAT_009d2bfc);
  uVar5 = func_0x00892fa0(uVar5,1000000,0);
  func_0x00892fe0(uVar5,uVar1,uVar2);
  uVar5 = func_0x00892fe0(puVar6,uStack_20,uVar1,uVar2);
  iVar4 = func_0x00892fa0(uVar5,1000000,0);
  return (undefined1 *)((int)puVar6 + iVar4);
}


/* ==================================================================== */
/* Address: 0x00766250 | Classified: AngelicaFile::proc_766250 */
/* ==================================================================== */

longlong FUN_00766250(void)

{
  undefined8 uVar1;
  longlong lVar2;
  uint uVar3;
  
  uVar1 = rdtsc();
  uVar3 = 0;
  lVar2 = func_0x00892fa0((int)((ulonglong)uVar1 >> 0x20),0,0,1);
  return lVar2 + (ulonglong)uVar3;
}


/* ==================================================================== */
/* Address: 0x00766280 | Classified: AngelicaFile::proc_766280 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00766280(void)

{
  return CONCAT44(_DAT_00985aac,_DAT_00985aa8);
}


/* ==================================================================== */
/* Address: 0x00766290 | Classified: AngelicaFile::proc_766290 */
/* ==================================================================== */

uint FUN_00766290(void)

{
  uint uVar1;
  
  uVar1 = FUN_00766140();
  return uVar1 / 1000;
}


/* ==================================================================== */
/* Address: 0x007662b0 | Classified: AngelicaFile::proc_7662b0 */
/* ==================================================================== */

int __fastcall FUN_007662b0(int param_1)

{
  FUN_007668e0();
  *(undefined4 *)(param_1 + 0xe0) = 0;
  *(undefined4 *)(param_1 + 0xdc) = 0;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007662d0 | Classified: AngelicaFile::proc_7662d0 */
/* ==================================================================== */

void FUN_007662d0(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008cbce8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  uStack_4 = 0;
  FUN_00766460();
  uStack_4 = 0xffffffff;
  func_0x00430860();
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x00766320 | Classified: AngelicaFile::proc_766320 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall
FUN_00766320(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,int param_7)

{
  bool bVar1;
  float *pfVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  float10 fVar9;
  
  FUN_00766460();
  *(int *)(param_1 + 4) = param_7;
  if ((int)param_2 < 1) {
    return param_2 & 0xffffff00;
  }
  *(uint *)(param_1 + 0xdc) = param_2;
  pfVar2 = (float *)func_0x007631a0(param_2 * 4);
  if (pfVar2 != (float *)0x0) {
    iVar3 = func_0x007631a0(*(int *)(param_1 + 0xdc) * 0xc);
    *(int *)(param_1 + 0xe0) = iVar3;
    if (iVar3 != 0) {
      iVar3 = *(int *)(param_1 + 0xdc);
      param_2 = 0;
      do {
        iVar6 = 0;
        if (0 < iVar3) {
          do {
            fVar9 = (float10)FUN_00766910();
            pfVar2[iVar6] = (float)fVar9;
            iVar6 = iVar6 + 1;
          } while (iVar6 < *(int *)(param_1 + 0xdc));
        }
        iVar3 = *(int *)(param_1 + 0xdc);
        if (0 < iVar3) {
          iVar6 = 1;
          pfVar7 = pfVar2;
          iVar8 = param_2;
          do {
            param_7 = iVar6 + -2;
            if (param_7 < 0) {
              param_7 = param_7 + iVar3;
            }
            iVar5 = iVar6;
            if (iVar3 <= iVar6) {
              iVar5 = iVar6 - iVar3;
            }
            iVar8 = iVar8 + 0xc;
            *(float *)(*(int *)(param_1 + 0xe0) + -0xc + iVar8) =
                 *pfVar7 * _DAT_008eff98 + (pfVar2[iVar5] + pfVar2[param_7]) * _DAT_008eff9c;
            iVar3 = *(int *)(param_1 + 0xdc);
            bVar1 = iVar6 < iVar3;
            iVar6 = iVar6 + 1;
            pfVar7 = pfVar7 + 1;
          } while (bVar1);
        }
        param_2 = param_2 + 4;
      } while ((int)param_2 < 0xc);
      func_0x007631b0(pfVar2);
      uVar4 = FUN_00766940(param_3,param_4,param_5,param_6);
      return uVar4;
    }
    return 0;
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x00766460 | Classified: AngelicaFile::proc_766460 */
/* ==================================================================== */

undefined4 __fastcall FUN_00766460(int param_1)

{
  if (*(int *)(param_1 + 0xe0) != 0) {
    func_0x007631b0(*(int *)(param_1 + 0xe0));
    *(undefined4 *)(param_1 + 0xe0) = 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00766490 | Classified: AngelicaFile::proc_766490 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00766490(char *param_1,undefined4 param_2,float *param_3,int param_4)

{
  float fVar1;
  float fVar2;
  char cVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  float *pfVar10;
  float10 extraout_ST0;
  float *pfStack_44;
  float afStack_34 [13];
  
  pfVar9 = afStack_34;
  for (iVar7 = param_4; pfVar9 = pfVar9 + 1, iVar7 != 0; iVar7 = iVar7 + -1) {
    *pfVar9 = 0.0;
  }
  afStack_34[0] = *(float *)(param_1 + 0x18);
  if (0 < (int)afStack_34[0]) {
    cVar3 = *param_1;
    iVar7 = *(int *)(param_1 + 0xdc);
    pfStack_44 = (float *)(param_1 + 0x9c);
    do {
      iVar5 = func_0x00892e78();
      iVar6 = iVar5 + 1;
      fVar1 = (float)(extraout_ST0 - (float10)iVar5);
      for (; iVar5 < 0; iVar5 = iVar5 + iVar7) {
      }
      if (param_4 < 4) {
        iVar8 = param_4;
        if (0 < param_4) goto LAB_0076651b;
      }
      else {
        iVar8 = 3;
LAB_0076651b:
        pfVar9 = (float *)(*(int *)(param_1 + 0xe0) + (iVar5 % iVar7) * 0xc);
        pfVar10 = afStack_34 + 4;
        for (; iVar8 != 0; iVar8 = iVar8 + -1) {
          *pfVar10 = *pfVar9;
          pfVar9 = pfVar9 + 1;
          pfVar10 = pfVar10 + 1;
        }
      }
      for (; iVar6 < 0; iVar6 = iVar6 + iVar7) {
      }
      if (param_4 < 4) {
        iVar5 = param_4;
        if (0 < param_4) goto LAB_00766554;
      }
      else {
        iVar5 = 3;
LAB_00766554:
        pfVar9 = (float *)(*(int *)(param_1 + 0xe0) + (iVar6 % iVar7) * 0xc);
        pfVar10 = afStack_34 + 7;
        for (; iVar5 != 0; iVar5 = iVar5 + -1) {
          *pfVar10 = *pfVar9;
          pfVar9 = pfVar9 + 1;
          pfVar10 = pfVar10 + 1;
        }
      }
      if (cVar3 == '\0') {
        if (0 < param_4) {
          fVar2 = *pfStack_44;
          iVar6 = 0;
          do {
            iVar5 = iVar6 + 1;
            fVar4 = afStack_34[iVar6 + 7] * fVar1 + afStack_34[iVar6 + 4] * (_DAT_008effa0 - fVar1);
            afStack_34[iVar6 + 10] = fVar4;
            afStack_34[iVar5] = fVar2 * fVar4 + afStack_34[iVar5];
            iVar6 = iVar5;
          } while (iVar5 < param_4);
        }
      }
      else if (0 < param_4) {
        fVar2 = *pfStack_44;
        iVar6 = 0;
        do {
          iVar5 = iVar6 + 1;
          fVar4 = ABS(afStack_34[iVar6 + 7] * fVar1 +
                      afStack_34[iVar6 + 4] * (_DAT_008effa0 - fVar1));
          afStack_34[iVar6 + 10] = fVar4;
          afStack_34[iVar5] = fVar4 * fVar2 + afStack_34[iVar5];
          iVar6 = iVar5;
        } while (iVar5 < param_4);
      }
      pfStack_44 = pfStack_44 + 1;
      afStack_34[0] = (float)((int)afStack_34[0] + -1);
    } while (afStack_34[0] != 0.0);
  }
  if (0 < param_4) {
    pfVar9 = afStack_34;
    for (; pfVar9 = pfVar9 + 1, param_4 != 0; param_4 = param_4 + -1) {
      *param_3 = *pfVar9;
      param_3 = param_3 + 1;
    }
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00766630 | Classified: AngelicaFile::proc_766630 */
/* ==================================================================== */

void __fastcall FUN_00766630(undefined4 *param_1)

{
  *param_1 = &UNK_008e7a64;
  param_1[0xc4] = 0;
  param_1[0xc5] = 0;
  param_1[0xc6] = 0;
  param_1[199] = 0;
  param_1[200] = 0;
  param_1[0xc9] = 0;
  param_1[0xca] = 0;
  param_1[0xcb] = 0;
  param_1[0xcc] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00766680 | Classified: AngelicaFile::proc_766680 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00766680(double *param_1,int param_2,double *param_3)

{
  double dVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iStack_8;
  
  if ((((param_2 < 0) || (0x7a60 < param_2)) || ((int)param_3 < 0)) || (0x7581 < (int)param_3)) {
    param_2 = 0x70a;
    param_3 = (double *)0x249d;
  }
  iStack_8 = 0x61;
  iVar7 = param_2 % 0xb1 + 2;
  iVar5 = (int)param_3 % 0xa9;
  iVar3 = (param_2 / 0xb1) % 0xb1 + 2;
  iVar6 = ((int)param_3 / 0xa9) % 0xb2 + 1;
  param_3 = param_1;
  do {
    param_3 = param_3 + 1;
    param_2 = 0x18;
    iVar4 = iVar3;
    dVar1 = _DAT_008effb0;
    dVar2 = _DAT_008effa8;
    do {
      iVar3 = iVar7;
      iVar7 = iVar6;
      iVar6 = (((iVar3 * iVar4) % 0xb3) * iVar7) % 0xb3;
      iVar5 = (iVar5 * 0x35 + 1) % 0xa9;
      uVar8 = iVar6 * iVar5 & 0x8000003f;
      if ((int)uVar8 < 0) {
        uVar8 = (uVar8 - 1 | 0xffffffc0) + 1;
      }
      if (0x1f < (int)uVar8) {
        dVar1 = dVar2 + dVar1;
      }
      dVar2 = dVar2 * _DAT_008effa8;
      param_2 = param_2 + -1;
      iVar4 = iVar3;
    } while (param_2 != 0);
    *param_3 = dVar1;
    iStack_8 = iStack_8 + -1;
  } while (iStack_8 != 0);
  *(undefined4 *)(param_1 + 0x62) = 0;
  *(undefined4 *)((int)param_1 + 0x314) = 0x3f961f10;
  *(undefined4 *)(param_1 + 99) = 0x40000000;
  *(undefined4 *)((int)param_1 + 0x31c) = 0x3fdd32ec;
  *(undefined4 *)(param_1 + 100) = 0xa0000000;
  *(undefined4 *)((int)param_1 + 0x324) = 0x3fefffff;
  *(undefined4 *)(param_1 + 0x65) = 0x61;
  *(undefined4 *)((int)param_1 + 0x32c) = 0x21;
  *(undefined4 *)(param_1 + 0x66) = 1;
  return;
}


/* ==================================================================== */
/* Address: 0x007667f0 | Classified: AngelicaFile::proc_7667f0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_007667f0(int param_1)

{
  bool bVar1;
  double dVar2;
  int iVar3;
  float10 fVar4;
  
  if (*(int *)(param_1 + 0x330) == 0) {
    FUN_00766680(0x70a,0x249d);
  }
  fVar4 = (float10)*(double *)(param_1 + *(int *)(param_1 + 0x328) * 8) -
          (float10)*(double *)(param_1 + *(int *)(param_1 + 0x32c) * 8);
  if (fVar4 < (float10)_DAT_008effb0 != (fVar4 == (float10)_DAT_008effb0)) {
    fVar4 = fVar4 + (float10)_DAT_008effb8;
  }
  *(double *)(param_1 + *(int *)(param_1 + 0x328) * 8) = (double)fVar4;
  iVar3 = *(int *)(param_1 + 0x328) + -1;
  *(int *)(param_1 + 0x328) = iVar3;
  if (iVar3 == 0) {
    *(undefined4 *)(param_1 + 0x328) = 0x61;
  }
  iVar3 = *(int *)(param_1 + 0x32c) + -1;
  *(int *)(param_1 + 0x32c) = iVar3;
  if (iVar3 == 0) {
    *(undefined4 *)(param_1 + 0x32c) = 0x61;
  }
  dVar2 = *(double *)(param_1 + 0x310) - *(double *)(param_1 + 0x318);
  bVar1 = dVar2 < _DAT_008effb0;
  *(double *)(param_1 + 0x310) = dVar2;
  if (bVar1) {
    *(double *)(param_1 + 0x310) = dVar2 + *(double *)(param_1 + 800);
  }
  fVar4 = fVar4 - (float10)*(double *)(param_1 + 0x310);
  if (fVar4 < (float10)_DAT_008effb0) {
    fVar4 = fVar4 + (float10)_DAT_008effb8;
  }
  return fVar4;
}


/* ==================================================================== */
/* Address: 0x007668c0 | Classified: AngelicaFile::proc_7668c0 */
/* ==================================================================== */

float10 FUN_007668c0(float param_1,float param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_007667f0();
  return ((float10)param_2 - (float10)param_1) * fVar1 + (float10)param_1;
}


/* ==================================================================== */
/* Address: 0x007668e0 | Classified: AngelicaFile::proc_7668e0 */
/* ==================================================================== */

void __fastcall FUN_007668e0(undefined1 *param_1)

{
  *param_1 = 1;
  *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
  return;
}


/* ==================================================================== */
/* Address: 0x007668f0 | Classified: AngelicaFile::proc_7668f0 */
/* ==================================================================== */

void __fastcall FUN_007668f0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = func_0x00893090((ulonglong)*(uint *)(param_1 + 4) * 0x41a7,0x7fffffff,0);
  *(undefined4 *)(param_1 + 4) = uVar1;
  return;
}


/* ==================================================================== */
/* Address: 0x00766910 | Classified: AngelicaFile::proc_766910 */
/* ==================================================================== */

uint __fastcall FUN_00766910(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = FUN_007668f0(param_1);
  return uVar1 / 0x7d1;
}


/* ==================================================================== */
/* Address: 0x00766940 | Classified: AngelicaFile::proc_766940 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_00766940(int param_1,float param_2,int param_3,float param_4,float param_5)

{
  bool bVar1;
  uint in_EAX;
  uint uVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  iVar5 = (int)param_5;
  if (0x10 < (int)param_5) {
    return in_EAX & 0xffffff00;
  }
  bVar1 = param_2 < _DAT_008effc4;
  *(float *)(param_1 + 0xc) = param_2;
  *(float *)(param_1 + 0x10) = param_4;
  *(int *)(param_1 + 8) = param_3;
  *(float *)(param_1 + 0x18) = param_5;
  if (bVar1) {
    *(float *)(param_1 + 0xc) = -param_2;
  }
  if (param_3 < 0) {
    *(int *)(param_1 + 8) = -param_3;
  }
  if (param_4 < _DAT_008effc4) {
    *(float *)(param_1 + 0x10) = -param_4;
  }
  iVar7 = 0;
  param_5 = 0.0;
  param_2 = 1.0;
  if (0 < iVar5) {
    piVar6 = (int *)(param_1 + 0x5c);
    do {
      param_5 = param_2 + param_5;
      *piVar6 = param_3;
      piVar6[0x10] = (int)param_2;
      uVar2 = FUN_007668f0();
      param_2 = param_2 * param_4;
      piVar6[-0x10] = uVar2 % 0x3ff;
      param_3 = param_3 / 2;
      iVar7 = iVar7 + 1;
      if (param_3 < 1) {
        *(int *)(param_1 + 0x18) = iVar7;
        break;
      }
      piVar6 = piVar6 + 1;
    } while (iVar7 < *(int *)(param_1 + 0x18));
  }
  pfVar4 = *(float **)(param_1 + 0x18);
  iVar5 = 0;
  if (0 < (int)pfVar4) {
    param_5 = _DAT_008effa0 / param_5;
    pfVar3 = (float *)(param_1 + 0x9c);
    do {
      iVar5 = iVar5 + 1;
      pfVar4 = pfVar3 + 1;
      *pfVar3 = param_5 * *(float *)(param_1 + 0xc) * *pfVar3;
      pfVar3 = pfVar4;
    } while (iVar5 < *(int *)(param_1 + 0x18));
  }
  return CONCAT31((int3)((uint)pfVar4 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x00766a50 | Classified: AMSoundFileCache::vfunc_slot_0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_00766a50(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar4;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cbd0b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar2 = func_0x00763250(0x230);
  uStack_4 = 0;
  if (iVar2 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)func_0x0076d760();
  }
  uStack_4 = 0xffffffff;
  if (piVar3 == (int *)0x0) {
    if (_DAT_009d2c04 != 0) {
      func_0x007647d0(_DAT_009d2c04,0x985aec);
    }
    *unaff_FS_OFFSET = uStack_c;
    return (int *)0x0;
  }
  uVar4 = 1;
  cVar1 = (**(code **)(*piVar3 + 4))(&DAT_009b3c44,param_1);
  if (cVar1 == '\0') {
    (**(code **)*piVar3)(1);
    if (_DAT_009d2c04 != 0) {
      func_0x007647d0(_DAT_009d2c04,0x985ab4,param_1);
    }
    *unaff_FS_OFFSET = uVar4;
    return (int *)0x0;
  }
  *unaff_FS_OFFSET = unaff_EDI;
  return piVar3;
}


/* ==================================================================== */
/* Address: 0x00766b50 | Classified: AngelicaFile::proc_766b50 */
/* ==================================================================== */

void __fastcall FUN_00766b50(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_c [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = auStack_c;
  param_1[4] = &UNK_008d6650;
  param_1[7] = &UNK_008d649c;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 10;
  param_1[0xd] = 0;
  param_1[6] = &UNK_008f004c;
  param_1[0xf] = &UNK_008d649c;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 10;
  param_1[0x15] = 0;
  param_1[0xe] = &UNK_008f0048;
  param_1[0x16] = &UNK_008f0044;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0x10;
  param_1[0x1b] = &UNK_008f0040;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0x10;
  param_1[0x21] = &UNK_008d5a30;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0x32;
  param_1[0x20] = &UNK_008f003c;
  param_1[1] = 0;
  param_1[5] = 0;
  param_1[3] = 0;
  *param_1 = &UNK_008f0038;
  *unaff_FS_OFFSET = uVar1;
  return;
}


/* ==================================================================== */
/* Address: 0x00766c30 | Classified: AngelicaFile::proc_766c30 */
/* ==================================================================== */

undefined4 __thiscall FUN_00766c30(undefined4 param_1,byte param_2)

{
  FUN_00766c50();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00766c50 | Classified: AngelicaFile::proc_766c50 */
/* ==================================================================== */

void __fastcall FUN_00766c50(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  int iStack_4;
  
  puStack_8 = &UNK_008cbd8c;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  *param_1 = &UNK_008f0038;
  param_1[0x20] = &UNK_008f003c;
  iStack_4 = 3;
  param_1[0x21] = &UNK_008d5a30;
  if (param_1[0x22] != 0) {
    func_0x00763260(param_1[0x22]);
    param_1[0x22] = 0;
  }
  param_1[0x24] = 0;
  param_1[0x23] = 0;
  iStack_4._0_1_ = 2;
  param_1[0x1b] = &UNK_008f0040;
  if (param_1[0x1c] != 0) {
    func_0x00763260(param_1[0x1c]);
    param_1[0x1c] = 0;
  }
  param_1[0x1e] = 0;
  param_1[0x1d] = 0;
  iStack_4._0_1_ = 1;
  param_1[0x16] = &UNK_008f0044;
  if (param_1[0x17] != 0) {
    func_0x00763260(param_1[0x17]);
    param_1[0x17] = 0;
  }
  param_1[0x19] = 0;
  param_1[0x18] = 0;
  param_1[0xe] = &UNK_008f0048;
  puVar1 = (undefined4 *)param_1[0x10];
  iStack_4 = (uint)iStack_4._1_3_ << 8;
  param_1[0xf] = &UNK_008d649c;
  while (puVar1 != (undefined4 *)0x0) {
    param_1[0x10] = *puVar1;
    *puVar1 = param_1[0x12];
    param_1[0x12] = puVar1;
    puVar1 = (undefined4 *)param_1[0x10];
    param_1[0x13] = param_1[0x13] + -1;
  }
  puVar1 = (undefined4 *)param_1[0x15];
  param_1[0x11] = 0;
  param_1[0x13] = 0;
  while (puVar1 != (undefined4 *)0x0) {
    param_1[0x15] = puVar1[1];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    puVar1 = (undefined4 *)param_1[0x15];
  }
  param_1[6] = &UNK_008f004c;
  puVar1 = (undefined4 *)param_1[8];
  iStack_4 = 0xffffffff;
  param_1[7] = &UNK_008d649c;
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
  *unaff_FS_OFFSET = uStack_c;
  return;
}


/* ==================================================================== */
/* Address: 0x00766dd0 | Classified: elementclient::AArray__SetSize__Not_enough_memo@0x766dd0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00766dd0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  
  *(int *)(param_1 + 4) = param_2;
  iVar1 = *(int *)(*(int *)(param_2 + 0x18) + 0x14);
  iVar5 = *(int *)(iVar1 + 0x24);
  *(undefined4 *)(param_1 + 0x68) = 10;
  if (iVar5 == 0) {
    func_0x004acc40(1);
  }
  else {
    if (*(int *)(param_1 + 100) < iVar5) {
      iVar8 = func_0x00763250(iVar5 * 8);
      if (iVar8 == 0) {
        func_0x00764590(1,0x9505a4);
        goto LAB_00766e7d;
      }
      if (*(int *)(param_1 + 0x5c) != 0) {
        iVar7 = *(int *)(param_1 + 0x60);
        if (iVar5 <= *(int *)(param_1 + 0x60)) {
          iVar7 = iVar5;
        }
        iVar4 = 0;
        if (0 < iVar7) {
          do {
            iVar2 = *(int *)(param_1 + 0x5c);
            iVar4 = iVar4 + 1;
            *(undefined4 *)(iVar8 + -8 + iVar4 * 8) = *(undefined4 *)(iVar2 + -8 + iVar4 * 8);
            *(undefined4 *)(iVar8 + -4 + iVar4 * 8) = *(undefined4 *)(iVar2 + -4 + iVar4 * 8);
          } while (iVar4 < iVar7);
        }
        func_0x00763260(*(undefined4 *)(param_1 + 0x5c));
      }
      *(int *)(param_1 + 100) = iVar5;
      *(int *)(param_1 + 0x5c) = iVar8;
    }
    *(int *)(param_1 + 0x60) = iVar5;
  }
LAB_00766e7d:
  iVar5 = *(int *)(iVar1 + 0x18);
  *(undefined4 *)(param_1 + 0x7c) = 10;
  if (iVar5 == 0) {
    func_0x004acc40(1);
  }
  else {
    if (*(int *)(param_1 + 0x78) < iVar5) {
      iVar8 = func_0x00763250(iVar5 * 8);
      if (iVar8 == 0) {
        func_0x00764590(1,0x9505a4);
        goto LAB_00766f16;
      }
      if (*(int *)(param_1 + 0x70) != 0) {
        iVar7 = *(int *)(param_1 + 0x74);
        if (iVar5 <= *(int *)(param_1 + 0x74)) {
          iVar7 = iVar5;
        }
        iVar4 = 0;
        if (0 < iVar7) {
          do {
            iVar2 = *(int *)(param_1 + 0x70);
            iVar4 = iVar4 + 1;
            *(undefined4 *)(iVar8 + -8 + iVar4 * 8) = *(undefined4 *)(iVar2 + -8 + iVar4 * 8);
            *(undefined4 *)(iVar8 + -4 + iVar4 * 8) = *(undefined4 *)(iVar2 + -4 + iVar4 * 8);
          } while (iVar4 < iVar7);
        }
        func_0x00763260(*(undefined4 *)(param_1 + 0x70));
      }
      *(int *)(param_1 + 0x78) = iVar5;
      *(int *)(param_1 + 0x70) = iVar8;
    }
    *(int *)(param_1 + 0x74) = iVar5;
  }
LAB_00766f16:
  iVar8 = 0;
  iVar1 = *(int *)(iVar1 + 0x14);
  iVar5 = 0;
  if (0 < *(int *)(param_1 + 0x60)) {
    do {
      iVar5 = iVar5 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x5c) + -8 + iVar5 * 8) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x5c) + -4 + iVar5 * 8) = 0;
    } while (iVar5 < *(int *)(param_1 + 0x60));
  }
  if (0 < *(int *)(param_1 + 0x74)) {
    do {
      uVar3 = *(uint *)(iVar1 + iVar8 * 4);
      uVar6 = func_0x00763250(uVar3 * 8);
      *(undefined4 *)(*(int *)(param_1 + 0x70) + iVar8 * 8) = uVar6;
      puVar9 = *(undefined4 **)(*(int *)(param_1 + 0x70) + iVar8 * 8);
      if (puVar9 == (undefined4 *)0x0) {
        if (_DAT_009d2c04 != 0) {
          func_0x007647d0(_DAT_009d2c04,0x985b1c);
        }
        return 0;
      }
      for (iVar5 = (uVar3 & 0x1fffffff) << 1; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      }
      iVar8 = iVar8 + 1;
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined1 *)puVar9 = 0;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      *(uint *)(*(int *)(param_1 + 0x70) + -4 + iVar8 * 8) = uVar3;
    } while (iVar8 < *(int *)(param_1 + 0x74));
  }
  uVar6 = func_0x00763330();
  *(undefined4 *)(param_1 + 8) = uVar6;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00766fd0 | Classified: AngelicaFile::proc_766fd0 */
/* ==================================================================== */

void __fastcall FUN_00766fd0(int param_1)

{
  int iVar1;
  
  FUN_00767060();
  FUN_00767500();
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x74)) {
    do {
      func_0x00763260(*(undefined4 *)(*(int *)(param_1 + 0x70) + iVar1 * 8));
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x74));
  }
  if (*(int *)(param_1 + 0x5c) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x5c));
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  if (*(int *)(param_1 + 0x70) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x70));
    *(undefined4 *)(param_1 + 0x70) = 0;
  }
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00767040 | Classified: AngelicaFile::proc_767040 */
/* ==================================================================== */

undefined1 FUN_00767040(void)

{
  FUN_00767060();
  FUN_00767500();
  return 1;
}


/* ==================================================================== */
/* Address: 0x00767060 | Classified: AngelicaFile::proc_767060 */
/* ==================================================================== */

void __fastcall FUN_00767060(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iStack_4;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x60)) {
    do {
      FUN_00767640(*(undefined4 *)(*(int *)(param_1 + 0x5c) + iVar3 * 8));
      iVar3 = iVar3 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x5c) + -8 + iVar3 * 8) = 0;
    } while (iVar3 < *(int *)(param_1 + 0x60));
  }
  iStack_4 = 0;
  if (0 < *(int *)(param_1 + 0x74)) {
    do {
      piVar1 = (int *)(*(int *)(param_1 + 0x70) + iStack_4 * 8);
      if ((*(int *)(*(int *)(param_1 + 0x70) + iStack_4 * 8) != 0) && (iVar3 = 0, 0 < piVar1[1])) {
        do {
          iVar2 = *(int *)(*piVar1 + iVar3 * 8);
          if (iVar2 != 0) {
            FUN_00767640(iVar2);
          }
          iVar3 = iVar3 + 1;
          *(undefined4 *)(*piVar1 + -8 + iVar3 * 8) = 0;
          *(undefined4 *)(*piVar1 + -4 + iVar3 * 8) = 0;
        } while (iVar3 < piVar1[1]);
      }
      iStack_4 = iStack_4 + 1;
    } while (iStack_4 < *(int *)(param_1 + 0x74));
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007670f0 | Classified: AngelicaFile::proc_7670f0 */
/* ==================================================================== */

int __thiscall FUN_007670f0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00767290(param_2,0);
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = func_0x00419130();
  *(int *)(iVar2 + 8) = iVar1;
  *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(param_1 + 0x24);
  if (*(int **)(param_1 + 0x24) != (int *)0x0) {
    **(int **)(param_1 + 0x24) = iVar2;
    *(int *)(param_1 + 0x24) = iVar2;
    *(int *)(iVar1 + 0x6c) = iVar2;
    return iVar1;
  }
  *(int *)(param_1 + 0x20) = iVar2;
  *(int *)(param_1 + 0x24) = iVar2;
  *(int *)(iVar1 + 0x6c) = iVar2;
  return iVar1;
}


/* ==================================================================== */
/* Address: 0x00767150 | Classified: AngelicaFile::proc_767150 */
/* ==================================================================== */

void __thiscall FUN_00767150(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar1 = (int *)*param_2;
  if ((piVar1 != (int *)0x0) && (piVar2 = (int *)piVar1[0x1b], piVar2 != (int *)0x0)) {
    iVar3 = *piVar2;
    piVar4 = (int *)piVar2[1];
    if (iVar3 == 0) {
      *(int **)(param_1 + 0x24) = piVar4;
    }
    else {
      *(int **)(iVar3 + 4) = piVar4;
    }
    if (piVar4 == (int *)0x0) {
      *(int *)(param_1 + 0x20) = iVar3;
    }
    else {
      *piVar4 = iVar3;
    }
    *piVar2 = *(int *)(param_1 + 0x28);
    *(int **)(param_1 + 0x28) = piVar2;
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + -1;
    (**(code **)(*piVar1 + 8))();
    (**(code **)*piVar1)(1);
    *param_2 = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x007671b0 | Classified: AngelicaFile::proc_7671b0 */
/* ==================================================================== */

int __thiscall FUN_007671b0(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined1 unaff_retaddr;
  
  iVar1 = FUN_00767290(param_2,1);
  if (iVar1 == 0) {
    return 0;
  }
  piVar2 = (int *)func_0x00763250(8);
  *(undefined1 *)(piVar2 + 1) = unaff_retaddr;
  *piVar2 = iVar1;
  iVar3 = func_0x00419130();
  *(int **)(iVar3 + 8) = piVar2;
  *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(param_1 + 0x44);
  if (*(int **)(param_1 + 0x44) != (int *)0x0) {
    **(int **)(param_1 + 0x44) = iVar3;
    *(int *)(param_1 + 0x44) = iVar3;
    *(int *)(iVar1 + 0x6c) = iVar3;
    return iVar1;
  }
  *(int *)(param_1 + 0x40) = iVar3;
  *(int *)(param_1 + 0x44) = iVar3;
  *(int *)(iVar1 + 0x6c) = iVar3;
  return iVar1;
}


/* ==================================================================== */
/* Address: 0x00767220 | Classified: AngelicaFile::proc_767220 */
/* ==================================================================== */

void __thiscall FUN_00767220(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar1 = (int *)*param_2;
  if ((piVar1 != (int *)0x0) && (piVar2 = (int *)piVar1[0x1b], piVar2 != (int *)0x0)) {
    func_0x00763260(piVar2[2]);
    iVar3 = *piVar2;
    piVar4 = (int *)piVar2[1];
    if (iVar3 == 0) {
      *(int **)(param_1 + 0x44) = piVar4;
    }
    else {
      *(int **)(iVar3 + 4) = piVar4;
    }
    if (piVar4 == (int *)0x0) {
      *(int *)(param_1 + 0x40) = iVar3;
    }
    else {
      *piVar4 = iVar3;
    }
    *piVar2 = *(int *)(param_1 + 0x48);
    *(int **)(param_1 + 0x48) = piVar2;
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + -1;
    (**(code **)(*piVar1 + 8))();
    (**(code **)*piVar1)(1);
    *param_2 = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00767290 | Classified: elementclient::AMSoundBufferMan__LoadSoundFromF@0x767290 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __thiscall FUN_00767290(int param_1,undefined4 param_2,char param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int unaff_EBX;
  int *piVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cbdb6;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if (param_3 == '\0') {
    iVar2 = func_0x00763250(0x70);
    uStack_4 = 1;
    if (iVar2 == 0) goto LAB_00767301;
    piVar3 = (int *)FUN_007682b0();
  }
  else {
    iVar2 = func_0x00763250(0xb4);
    uStack_4 = 0;
    if (iVar2 == 0) {
LAB_00767301:
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_00769400();
    }
  }
  uStack_4 = 0xffffffff;
  if (piVar3 == (int *)0x0) {
    if (_DAT_009d2c04 != 0) {
      func_0x007647d0(_DAT_009d2c04,0x985bc8);
      piVar3 = (int *)0x0;
      goto LAB_007673f4;
    }
  }
  else {
    if (_DAT_00986a1c == 4) {
      cVar1 = (**(code **)(*piVar3 + 0xc))(*(undefined4 *)(param_1 + 4),0,param_2);
      if (cVar1 != '\0') goto LAB_007673f4;
      (**(code **)*piVar3)(1);
    }
    else {
      piVar4 = *(int **)(param_1 + 0xc);
      if (piVar4 == (int *)0x0) {
        piVar4 = (int *)(param_1 + 0x10);
      }
      iVar2 = (**(code **)*piVar4)(param_2);
      if (iVar2 == 0) {
        (**(code **)*piVar3)(1);
        if (_DAT_009d2c04 != 0) {
          func_0x007647d0(_DAT_009d2c04,0x985b8c,param_2);
          piVar3 = (int *)0x0;
          goto LAB_007673f4;
        }
        goto LAB_007673e6;
      }
      cVar1 = (**(code **)(*piVar3 + 0xc))(*(undefined4 *)(unaff_EBX + 4),iVar2,param_2);
      if (cVar1 != '\0') {
        (**(code **)(*piVar4 + 4))(iVar2);
        goto LAB_007673f4;
      }
      (**(code **)*piVar3)(1);
    }
    if (_DAT_009d2c04 != 0) {
      func_0x007647d0(_DAT_009d2c04,0x985b48,param_2);
    }
  }
LAB_007673e6:
  piVar3 = (int *)0x0;
LAB_007673f4:
  *unaff_FS_OFFSET = uStack_c;
  return piVar3;
}


/* ==================================================================== */
/* Address: 0x00767410 | Classified: AngelicaFile::proc_767410 */
/* ==================================================================== */

undefined4 __thiscall FUN_00767410(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char unaff_retaddr;
  
  iVar4 = 0;
  uVar3 = 0xffffffff;
  iVar1 = 0;
  iVar5 = iVar4;
  if (0 < *(int *)(param_1 + 0x60)) {
    piVar2 = *(int **)(param_1 + 0x5c);
    do {
      iVar5 = iVar1;
      if (*piVar2 == 0) break;
      if ((uint)piVar2[1] < uVar3) {
        uVar3 = piVar2[1];
        iVar4 = iVar1;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 2;
      iVar5 = iVar4;
    } while (iVar1 < *(int *)(param_1 + 0x60));
  }
  piVar2 = (int *)(*(int *)(param_1 + 0x5c) + iVar5 * 8);
  iVar4 = *(int *)(*(int *)(param_1 + 0x5c) + iVar5 * 8);
  if (iVar4 != 0) {
    FUN_00767640(iVar4);
  }
  iVar4 = FUN_00767560(param_2,0);
  *piVar2 = iVar4;
  if (iVar4 != 0) {
    iVar4 = func_0x00763330();
    piVar2[1] = iVar4;
    if (unaff_retaddr != '\0') {
      (**(code **)(*(int *)*piVar2 + 0x18))();
    }
    (**(code **)(*(int *)*piVar2 + 0x24))(0);
    return 1;
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x007674a0 | Classified: AngelicaFile::proc_7674a0 */
/* ==================================================================== */

void __thiscall FUN_007674a0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 != 0) {
    iVar2 = 0;
    if (0 < *(int *)(param_2 + 0x10)) {
      do {
        piVar1 = *(int **)(*(int *)(param_2 + 8) + iVar2 * 4);
        if (piVar1 != (int *)0x0) {
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - piVar1[3];
          (**(code **)(*piVar1 + 8))();
          (**(code **)*piVar1)(1);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(param_2 + 0x10));
    }
    func_0x00763260(*(undefined4 *)(param_2 + 8));
    func_0x00763260(param_2);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00767500 | Classified: AngelicaFile::proc_767500 */
/* ==================================================================== */

void __fastcall FUN_00767500(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x8c)) {
    do {
      FUN_007674a0(*(undefined4 *)(*(int *)(param_1 + 0x88) + iVar1 * 4));
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x8c));
  }
  if (*(int *)(param_1 + 0x88) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x88));
    *(undefined4 *)(param_1 + 0x88) = 0;
  }
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00767560 | Classified: AngelicaFile::proc_767560 */
/* ==================================================================== */

void __thiscall FUN_00767560(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = func_0x007648c0(param_2);
  iVar1 = *(int *)(param_1 + 0x8c);
  iVar3 = 0;
  if (0 < iVar1) {
    piVar4 = *(int **)(param_1 + 0x88);
    do {
      if ((*(int *)*piVar4 == iVar2) && ((char)((int *)*piVar4)[1] == (char)param_3)) break;
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar3 < iVar1);
  }
  if (iVar1 <= iVar3) {
    FUN_00767290(param_2,param_3);
    return;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x88) + iVar3 * 4);
  iVar2 = 0;
  if (0 < *(int *)(iVar1 + 0x10)) {
    piVar4 = *(int **)(iVar1 + 8);
    do {
      if (*(int *)(*piVar4 + 0x6c) == 0) {
        *(int *)(*piVar4 + 0x6c) = iVar3 + 1;
        return;
      }
      iVar2 = iVar2 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar2 < *(int *)(iVar1 + 0x10));
  }
  iVar2 = FUN_00767290(param_2,param_3);
  if (iVar2 == 0) {
    return;
  }
  if (*(int *)(iVar1 + 0x10) < *(int *)(iVar1 + 0xc)) {
    *(int *)(iVar2 + 0x6c) = iVar3 + 1;
    *(int *)(*(int *)(iVar1 + 8) + *(int *)(iVar1 + 0x10) * 4) = iVar2;
    *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1;
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + *(int *)(iVar2 + 0xc);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00767640 | Classified: AngelicaFile::proc_767640 */
/* ==================================================================== */

void FUN_00767640(int *param_1)

{
  if (param_1 != (int *)0x0) {
    if (param_1[0x1b] == 0) {
      (**(code **)(*param_1 + 8))();
      (**(code **)*param_1)(1);
      return;
    }
    (**(code **)(*param_1 + 0x28))();
    param_1[0x1b] = 0;
  }
  return;
}


/* ==================================================================== */
/* Address: 0x00767680 | Classified: elementclient::AMSoundBufferMan__Tick____Error_c@0x767680 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00767680(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  int iStack_c;
  int iStack_8;
  
  iVar8 = 0;
  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 0x18) + 0x14);
  if (0 < *(int *)(param_1 + 0x60)) {
    do {
      piVar3 = *(int **)(*(int *)(param_1 + 0x5c) + iVar8 * 8);
      piVar1 = (int *)(*(int *)(param_1 + 0x5c) + iVar8 * 8);
      if (piVar3 != (int *)0x0) {
        cVar6 = (**(code **)(*piVar3 + 0x34))();
        if (cVar6 == '\0') {
LAB_00767791:
          if (_DAT_009d2c04 != 0) {
            func_0x007647d0(_DAT_009d2c04,0x985c00);
          }
          return 0;
        }
        iVar4 = *piVar1;
        if (*(int *)(iVar4 + 0x50) == 0) {
          FUN_00767640(iVar4);
          *piVar1 = 0;
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(param_1 + 0x60));
  }
  iStack_8 = 0;
  if (0 < *(int *)(param_1 + 0x74)) {
    do {
      piVar1 = (int *)(*(int *)(param_1 + 0x70) + iStack_8 * 8);
      if ((*(int *)(*(int *)(param_1 + 0x70) + iStack_8 * 8) != 0) && (iStack_c = 0, 0 < piVar1[1]))
      {
        do {
          piVar3 = *(int **)(*piVar1 + iStack_c * 8);
          if (piVar3 != (int *)0x0) {
            cVar6 = (**(code **)(*piVar3 + 0x34))();
            if (cVar6 == '\0') goto LAB_00767791;
            if (piVar3[0x14] == 0) {
              FUN_00767640(piVar3);
              *(undefined4 *)(*piVar1 + iStack_c * 8) = 0;
            }
          }
          iStack_c = iStack_c + 1;
        } while (iStack_c < piVar1[1]);
      }
      iStack_8 = iStack_8 + 1;
    } while (iStack_8 < *(int *)(param_1 + 0x74));
  }
  uVar7 = func_0x00763330();
  if ((uint)(*(int *)(iVar2 + 0xc) + *(int *)(param_1 + 8)) <= uVar7) {
    *(uint *)(param_1 + 8) = uVar7;
    puVar5 = *(undefined4 **)(param_1 + 0x40);
    while (puVar5 != (undefined4 *)0x0) {
      piVar1 = puVar5 + 2;
      puVar5 = (undefined4 *)*puVar5;
      if (*(char *)(*piVar1 + 4) != '\0') {
        FUN_00769580();
      }
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007677c0 | Classified: AngelicaFile::proc_7677c0 */
/* ==================================================================== */

undefined4 __thiscall FUN_007677c0(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  
  puVar2 = *(undefined4 **)(param_1 + 0x20);
  while (puVar2 != (undefined4 *)0x0) {
    piVar4 = puVar2 + 2;
    puVar2 = (undefined4 *)*puVar2;
    iVar3 = *piVar4;
    if ((*(char *)(iVar3 + 0x58) == '\0') && (*(char *)(iVar3 + 0x59) == '\0')) {
      piVar4 = *(int **)(iVar3 + 0x30);
      *(int *)(iVar3 + 0x54) = param_2;
      if (piVar4 != (int *)0x0) {
        if (param_2 == 0) {
          (**(code **)(*piVar4 + 0x3c))(piVar4,0xffffd8f0);
        }
        else {
          (**(code **)(*piVar4 + 0x3c))(piVar4,(uint)(param_2 * 3000) / 100 - 3000);
        }
      }
    }
  }
  puVar2 = *(undefined4 **)(param_1 + 0x40);
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = puVar2 + 2;
    puVar2 = (undefined4 *)*puVar2;
    iVar3 = *(int *)*puVar1;
    if ((*(char *)(iVar3 + 0x58) == '\0') && (*(char *)(iVar3 + 0x59) == '\0')) {
      piVar4 = *(int **)(iVar3 + 0x30);
      *(int *)(iVar3 + 0x54) = param_2;
      if (piVar4 != (int *)0x0) {
        if (param_2 == 0) {
          (**(code **)(*piVar4 + 0x3c))(piVar4,0xffffd8f0);
        }
        else {
          (**(code **)(*piVar4 + 0x3c))(piVar4,(uint)(param_2 * 3000) / 100 - 3000);
        }
      }
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007678a0 | Classified: AngelicaFile::proc_7678a0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007678a0(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iStack_8;
  
  piVar7 = *(int **)(param_1 + 0xc);
  if (piVar7 == (int *)0x0) {
    piVar7 = (int *)(param_1 + 0x10);
  }
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  while (puVar1 != (undefined4 *)0x0) {
    piVar2 = (int *)puVar1[2];
    puVar1 = (undefined4 *)*puVar1;
    iVar4 = (**(code **)*piVar7)(piVar2[0xf]);
    if (iVar4 != 0) {
      (**(code **)(*piVar2 + 0x14))(iVar4);
      (**(code **)(*piVar7 + 4))(iVar4);
    }
  }
  puVar1 = *(undefined4 **)(param_1 + 0x40);
  while (puVar1 != (undefined4 *)0x0) {
    piVar2 = (int *)puVar1[2];
    puVar1 = (undefined4 *)*puVar1;
    iVar4 = (**(code **)*piVar7)(*(undefined4 *)(*piVar2 + 0x3c));
    if (iVar4 != 0) {
      (**(code **)(*(int *)*piVar2 + 0x14))(iVar4);
      (**(code **)(*piVar7 + 4))(iVar4);
    }
  }
  iVar4 = *(int *)(param_1 + 0x8c);
  iStack_8 = 0;
  if (0 < iVar4) {
    do {
      iVar6 = 0;
      iVar3 = *(int *)(*(int *)(param_1 + 0x88) + iStack_8 * 4);
      iVar4 = *(int *)(iVar3 + 0x10);
      if (0 < iVar4) {
        do {
          if ((*(int *)(*(int *)(iVar3 + 8) + iVar6 * 4) != 0) &&
             (iVar5 = (**(code **)*piVar7)
                                (*(undefined4 *)
                                  (*(int *)(*(int *)(iVar3 + 8) + iStack_8 * 4) + 0x3c)), iVar5 != 0
             )) {
            (**(code **)(**(int **)(*(int *)(iVar3 + 8) + iVar6 * 4) + 0x14))(iVar5);
            (**(code **)(*piVar7 + 4))(iVar5);
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar4);
      }
      iStack_8 = iStack_8 + 1;
    } while (iStack_8 < *(int *)(param_1 + 0x8c));
  }
  return CONCAT31((int3)((uint)iVar4 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007679b0 | Classified: AngelicaFile::proc_7679b0 */
/* ==================================================================== */

void __fastcall FUN_007679b0(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  *param_1 = &UNK_008f004c;
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
/* Address: 0x00767a10 | Classified: AngelicaFile::proc_767a10 */
/* ==================================================================== */

void __fastcall FUN_00767a10(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  *param_1 = &UNK_008f0048;
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
/* Address: 0x00767a70 | Classified: AngelicaFile::proc_767a70 */
/* ==================================================================== */

undefined4 __thiscall FUN_00767a70(undefined4 param_1,byte param_2)

{
  FUN_007679b0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00767a90 | Classified: AngelicaFile::proc_767a90 */
/* ==================================================================== */

undefined4 __thiscall FUN_00767a90(undefined4 param_1,byte param_2)

{
  FUN_00767a10();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00767ab0 | Classified: AngelicaFile::proc_767ab0 */
/* ==================================================================== */

undefined4 __thiscall FUN_00767ab0(undefined4 param_1,byte param_2)

{
  FUN_00767ad0();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00767ad0 | Classified: AngelicaFile::proc_767ad0 */
/* ==================================================================== */

void __fastcall FUN_00767ad0(undefined4 *param_1)

{
  *param_1 = &UNK_008f003c;
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
/* Address: 0x00767b00 | Classified: AngelicaFile::proc_767b00 */
/* ==================================================================== */

void __fastcall FUN_00767b00(undefined4 *param_1)

{
  *param_1 = &UNK_008f0044;
  if (param_1[1] != 0) {
    func_0x00763260(param_1[1]);
    param_1[1] = 0;
  }
  param_1[3] = 0;
  param_1[2] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00767b30 | Classified: AngelicaFile::proc_767b30 */
/* ==================================================================== */

void __fastcall FUN_00767b30(undefined4 *param_1)

{
  *param_1 = &UNK_008f0040;
  if (param_1[1] != 0) {
    func_0x00763260(param_1[1]);
    param_1[1] = 0;
  }
  param_1[3] = 0;
  param_1[2] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00767b60 | Classified: AngelicaFile::proc_767b60 */
/* ==================================================================== */

undefined4 * __thiscall FUN_00767b60(undefined4 *param_1,byte param_2)

{
  *param_1 = &UNK_008f0044;
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
/* Address: 0x00767bb0 | Classified: AngelicaFile::proc_767bb0 */
/* ==================================================================== */

undefined4 * __thiscall FUN_00767bb0(undefined4 *param_1,byte param_2)

{
  *param_1 = &UNK_008f0040;
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
/* Address: 0x00767c00 | Classified: AngelicaFile::proc_767c00 */
/* ==================================================================== */

void __fastcall FUN_00767c00(undefined4 *param_1)

{
  *param_1 = &UNK_008f0054;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[6] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[7] = 100;
  param_1[8] = 0x3f800000;
  return;
}


/* ==================================================================== */
/* Address: 0x00767c30 | Classified: AngelicaFile::proc_767c30 */
/* ==================================================================== */

undefined4 __thiscall FUN_00767c30(undefined4 param_1,byte param_2)

{
  FUN_00767c50();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00767c50 | Classified: AngelicaFile::proc_767c50 */
/* ==================================================================== */

void __fastcall FUN_00767c50(undefined4 *param_1)

{
  *param_1 = &UNK_008f0054;
  return;
}


/* ==================================================================== */
/* Address: 0x00767c60 | Classified: elementclient::AMSoundEngine__Init____Init_as_a@0x767c60 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_00767c60(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cbde1;
  *unaff_FS_OFFSET = &uStack_c;
  *(undefined4 *)(param_1 + 0x18) = param_2;
  *(undefined4 *)(param_1 + 4) = param_3;
  if (_DAT_00986a1c == 4) {
    if (_DAT_009d2c04 != 0) {
      func_0x007647d0(_DAT_009d2c04,0x985d78);
    }
LAB_00767cd5:
    *(undefined4 *)(param_1 + 8) = 0;
  }
  else {
    iVar4 = func_0x008248da(0,param_1 + 8,0);
    if (iVar4 != 0) {
      if (_DAT_009d2c04 != 0) {
        func_0x007647d0(_DAT_009d2c04,0x985d40);
      }
      goto LAB_00767cd5;
    }
  }
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    uVar3 = param_5;
    switch(*(undefined4 *)(param_4 + 0xc)) {
    case 0:
      uVar3 = 3;
      break;
    case 1:
      uVar3 = 1;
      break;
    case 2:
      uVar3 = 2;
      break;
    case 3:
      uVar3 = 4;
    }
    iVar4 = (**(code **)(*piVar1 + 0x18))(piVar1,*(undefined4 *)(param_1 + 4),uVar3);
    if (iVar4 != 0) {
      if (_DAT_009d2c04 != 0) {
        func_0x007647d0(_DAT_009d2c04,0x985d10);
        *unaff_FS_OFFSET = uStack_c;
        return 0;
      }
      goto LAB_00767f09;
    }
  }
  if ((char)param_5 == '\0') {
    iVar4 = func_0x00763250(0x28);
    uStack_4 = 1;
    if (iVar4 == 0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar5 = (undefined4 *)func_0x0076b320();
    }
    *(undefined4 **)(param_1 + 0xc) = puVar5;
    uStack_4 = 0xffffffff;
    if (puVar5 == (undefined4 *)0x0) goto LAB_00767e3a;
    cVar2 = (**(code **)*puVar5)(param_1,param_4);
    if (cVar2 == '\0') {
      if (_DAT_009d2c04 != 0) {
        func_0x007647d0(_DAT_009d2c04,0x985c88);
        *unaff_FS_OFFSET = uStack_c;
        return 0;
      }
      goto LAB_00767f09;
    }
  }
  else {
    iVar4 = func_0x00763250(0x6c);
    uStack_4 = 0;
    if (iVar4 == 0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar5 = (undefined4 *)FUN_00768000();
    }
    *(undefined4 **)(param_1 + 0x10) = puVar5;
    uStack_4 = 0xffffffff;
    if (puVar5 == (undefined4 *)0x0) {
LAB_00767e3a:
      uStack_4 = 0xffffffff;
      if (_DAT_009d2c04 != 0) {
        func_0x007647d0(_DAT_009d2c04,0x985cb8);
        *unaff_FS_OFFSET = uStack_c;
        return 0;
      }
      goto LAB_00767f09;
    }
    cVar2 = (**(code **)*puVar5)(param_1,param_4);
    if (cVar2 == '\0') {
      if (_DAT_009d2c04 != 0) {
        func_0x007647d0(_DAT_009d2c04,0x985ce0);
        *unaff_FS_OFFSET = uStack_c;
        return 0;
      }
      goto LAB_00767f09;
    }
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x10);
  }
  iVar4 = func_0x00763250(0x98);
  uStack_4 = 2;
  if (iVar4 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_00766b50();
  }
  uStack_4 = 0xffffffff;
  *(int *)(param_1 + 0x14) = iVar4;
  if (iVar4 == 0) {
    if (_DAT_009d2c04 != 0) {
      func_0x007647d0(_DAT_009d2c04,0x985c64);
      *unaff_FS_OFFSET = uStack_c;
      return 0;
    }
  }
  else {
    cVar2 = FUN_00766dd0(param_1);
    if (cVar2 != '\0') {
      *unaff_FS_OFFSET = uStack_c;
      return 1;
    }
    if (_DAT_009d2c04 != 0) {
      func_0x007647d0(_DAT_009d2c04,0x985c38);
    }
  }
LAB_00767f09:
  *unaff_FS_OFFSET = uStack_c;
  return 0;
}


/* ==================================================================== */
/* Address: 0x00767f50 | Classified: AngelicaFile::proc_767f50 */
/* ==================================================================== */

undefined4 __fastcall FUN_00767f50(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 0x14) != 0) {
    FUN_00766fd0();
    if (*(undefined4 **)(param_1 + 0x14) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x14))(1);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  if (*(int **)(param_1 + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xc) + 4))();
    iVar1 = *(int *)(param_1 + 0xc);
    if (iVar1 != 0) {
      func_0x0076b340();
      func_0x00763260(iVar1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  piVar2 = *(int **)(param_1 + 8);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00767fc0 | Classified: AngelicaFile::proc_767fc0 */
/* ==================================================================== */

undefined1 __fastcall FUN_00767fc0(int param_1)

{
  if (*(int *)(param_1 + 0x14) != 0) {
    FUN_00767040();
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00767fd0 | Classified: AngelicaFile::proc_767fd0 */
/* ==================================================================== */

undefined1 __fastcall FUN_00767fd0(int param_1)

{
  if (*(int *)(param_1 + 0x14) != 0) {
    FUN_00767680();
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00767fe0 | Classified: AngelicaFile::proc_767fe0 */
/* ==================================================================== */

undefined4 __thiscall FUN_00767fe0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  FUN_007677c0(param_2);
  return 1;
}


/* ==================================================================== */
/* Address: 0x00768000 | Classified: AngelicaFile::proc_768000 */
/* ==================================================================== */

undefined4 * __fastcall FUN_00768000(undefined4 *param_1)

{
  func_0x0076b320();
  *param_1 = &UNK_008f0058;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[9] = 0x11;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x007680e0 | Classified: AngelicaFile::proc_7680e0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007680e0(int param_1)

{
  int *piVar1;
  undefined4 unaff_ESI;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x48))(piVar1,unaff_ESI);
    (**(code **)(**(int **)(param_1 + 8) + 8))(*(int **)(param_1 + 8));
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00768100 | Classified: elementclient::AM3DSoundDevice__UpdateChanges__C@0x768100 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __fastcall FUN_00768100(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 auStack_40 [4];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar4 = *(int *)(param_1 + 0x28);
  if (*(int *)(iVar4 + 8) != 0) {
    puVar1 = auStack_40;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
    }
    auStack_40[0] = 0x40;
    auStack_40[1] = *(undefined4 *)(param_1 + 0x30);
    auStack_40[2] = *(undefined4 *)(param_1 + 0x34);
    auStack_40[3] = *(undefined4 *)(param_1 + 0x38);
    uStack_30 = *(undefined4 *)(param_1 + 0x3c);
    uStack_2c = *(undefined4 *)(param_1 + 0x40);
    uStack_28 = *(undefined4 *)(param_1 + 0x44);
    uStack_24 = *(undefined4 *)(param_1 + 0x48);
    uStack_20 = *(undefined4 *)(param_1 + 0x4c);
    uStack_1c = *(undefined4 *)(param_1 + 0x50);
    uStack_18 = *(undefined4 *)(param_1 + 0x54);
    uStack_14 = *(undefined4 *)(param_1 + 0x58);
    uStack_c = *(undefined4 *)(param_1 + 0x60);
    uStack_10 = *(undefined4 *)(param_1 + 0x5c);
    uStack_4 = *(undefined4 *)(param_1 + 0x68);
    uStack_8 = *(undefined4 *)(param_1 + 100);
    iVar2 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x28))(*(int **)(param_1 + 0x2c),auStack_40,0)
    ;
    iVar4 = 0;
    if (iVar2 != 0) {
      uVar3 = 0;
      if (_DAT_009d2c04 != 0) {
        uVar3 = func_0x007647d0(_DAT_009d2c04,0x985e78);
      }
      return uVar3 & 0xffffff00;
    }
  }
  return CONCAT31((int3)((uint)iVar4 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x007681e0 | Classified: elementclient::AM3DSoundDevice__RetrieveParamet@0x7681e0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_007681e0(int param_1)

{
  int iVar1;
  undefined4 unaff_ESI;
  undefined4 *puVar2;
  undefined4 auStack_40 [4];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (*(int *)(*(int *)(param_1 + 0x28) + 8) != 0) {
    puVar2 = auStack_40;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    auStack_40[0] = 0x40;
    iVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0xc))(*(int **)(param_1 + 0x2c),auStack_40);
    if (iVar1 != 0) {
      if (_DAT_009d2c04 != 0) {
        func_0x007647d0(_DAT_009d2c04,0x985ec8);
      }
      return 0;
    }
    *(undefined4 *)(param_1 + 0x30) = unaff_ESI;
    *(undefined4 *)(param_1 + 0x34) = auStack_40[0];
    *(undefined4 *)(param_1 + 0x38) = auStack_40[1];
    *(undefined4 *)(param_1 + 0x3c) = auStack_40[2];
    *(undefined4 *)(param_1 + 0x40) = auStack_40[3];
    *(undefined4 *)(param_1 + 0x44) = uStack_30;
    *(undefined4 *)(param_1 + 0x48) = uStack_2c;
    *(undefined4 *)(param_1 + 0x4c) = uStack_28;
    *(undefined4 *)(param_1 + 0x50) = uStack_24;
    *(undefined4 *)(param_1 + 0x54) = uStack_20;
    *(undefined4 *)(param_1 + 0x58) = uStack_1c;
    *(undefined4 *)(param_1 + 0x5c) = uStack_18;
    *(undefined4 *)(param_1 + 0x60) = uStack_14;
    *(undefined4 *)(param_1 + 100) = uStack_10;
    *(undefined4 *)(param_1 + 0x68) = uStack_c;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007682b0 | Classified: AngelicaFile::proc_7682b0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_007682b0(undefined4 *param_1)

{
  param_1[0xf] = _DAT_009858e4;
  *param_1 = &UNK_008f00d0;
  param_1[0xd] = 0;
  param_1[1] = 0;
  param_1[10] = 0;
  param_1[0xc] = 0;
  param_1[0xb] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x14] = 0;
  *(undefined1 *)(param_1 + 0x13) = 0;
  *(undefined1 *)(param_1 + 0x1a) = 0;
  param_1[0x19] = 0;
  param_1[0x18] = 0;
  param_1[0x15] = 100;
  *(undefined1 *)(param_1 + 0x16) = 0;
  *(undefined1 *)((int)param_1 + 0x59) = 0;
  param_1[0x1b] = 0;
  param_1[0xe] = 0;
  return;
}


/* ==================================================================== */
/* Address: 0x00768300 | Classified: AngelicaFile::proc_768300 */
/* ==================================================================== */

undefined4 __thiscall FUN_00768300(undefined4 param_1,byte param_2)

{
  FUN_00768320();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00768320 | Classified: AngelicaFile::proc_768320 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00768320(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &UNK_008f00d0;
  piVar1 = (int *)(param_1[0xf] + -0xc);
  if (*piVar1 == -1) {
    *piVar1 = 1;
  }
  func_0x00763450(piVar1);
  param_1[0xf] = _DAT_009858e4;
  return;
}


/* ==================================================================== */
/* Address: 0x00768330 | Classified: elementclient::AMSoundBuffer__Init__CreateSound@0x768330 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00768330(int param_1,int param_2,uint *param_3)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  undefined4 *puStack_6c;
  undefined *puStack_68;
  undefined4 *puStack_64;
  undefined4 *puStack_60;
  undefined *puStack_5c;
  int *piStack_58;
  int *piStack_54;
  uint *puStack_50;
  undefined4 *puStack_4c;
  undefined4 uStack_48;
  uint auStack_24 [4];
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  *(int *)(param_1 + 4) = param_2;
  puVar5 = (uint *)(param_1 + 8);
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *param_3;
    param_3 = param_3 + 1;
    puVar5 = puVar5 + 1;
  }
  if (*(int *)(param_2 + 8) != 0) {
    puVar5 = auStack_24;
    for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    auStack_24[2] = *(undefined4 *)(param_1 + 0xc);
    iStack_14 = param_1 + 0x10;
    uVar3 = *(uint *)(param_1 + 8);
    auStack_24[1] = uVar3 | 0x101a0;
    auStack_24[0] = 0x24;
    if (*(char *)(*(int *)(param_2 + 0xc) + 0x20) != '\0') {
      auStack_24[1] = uVar3 | 0x181a0;
    }
    switch(*(undefined4 *)(param_1 + 0x24)) {
    case 0:
      uStack_10 = _UNK_008f9750;
      uStack_c = _UNK_008f9754;
      uStack_8 = _UNK_008f9758;
      uStack_4 = _UNK_008f975c;
      break;
    case 1:
      uStack_10 = _UNK_008f5340;
      uStack_c = _UNK_008f5344;
      uStack_8 = _UNK_008f5348;
      uStack_4 = _UNK_008f534c;
      break;
    case 2:
      uStack_10 = _UNK_008f5330;
      uStack_c = _UNK_008f5334;
      uStack_8 = _UNK_008f5338;
      uStack_4 = _UNK_008f533c;
      break;
    case 3:
      uStack_10 = _UNK_008f5320;
      uStack_c = _UNK_008f5324;
      uStack_8 = _UNK_008f5328;
      uStack_4 = _UNK_008f532c;
    }
    piStack_54 = *(int **)(param_2 + 8);
    uStack_48 = 0;
    puStack_50 = auStack_24;
    piStack_58 = (int *)0x768448;
    puStack_4c = (undefined4 *)(param_1 + 0x28);
    iVar4 = (**(code **)(*piStack_54 + 0xc))();
    if (iVar4 < 0) {
      if (_DAT_009d2c04 != 0) {
        piStack_58 = (int *)0x985fd0;
        puStack_5c = (undefined *)_DAT_009d2c04;
        puStack_60 = (undefined4 *)0x768464;
        func_0x007647d0();
        return 0;
      }
    }
    else {
      puStack_60 = *(undefined4 **)(param_1 + 0x28);
      piVar1 = (int *)(param_1 + 0x30);
      puStack_5c = &UNK_008f5380;
      puStack_64 = (undefined4 *)0x768483;
      piStack_58 = piVar1;
      iVar4 = (**(code **)*puStack_60)();
      if (iVar4 == 0) {
        puStack_6c = (undefined4 *)*piVar1;
        puStack_68 = &UNK_008f5350;
        puStack_64 = (undefined4 *)(param_1 + 0x2c);
        iVar4 = (**(code **)*puStack_6c)();
        if (iVar4 == 0) {
          iVar4 = (*_DAT_009b3b0c)(0,0,0,0);
          *(int *)(param_1 + 0x44) = iVar4;
          if (iVar4 == 0) {
            if (_DAT_009d2c04 != 0) {
              func_0x007647d0(_DAT_009d2c04,0x985f48);
              return 0;
            }
          }
          else {
            piVar2 = *(int **)(param_1 + 0x2c);
            puStack_6c = (undefined4 *)0xffffffff;
            puStack_68 = (undefined *)iVar4;
            iVar4 = (**(code **)(*piVar2 + 0xc))(piVar2,1,&puStack_6c);
            if (-1 < iVar4) {
              piVar2 = (int *)*piVar1;
              iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x1c);
              *(int *)(param_1 + 0x54) = iVar4;
              if (piVar2 != (int *)0x0) {
                if (iVar4 == 0) {
                  (**(code **)(*piVar2 + 0x3c))(piVar2,0xffffd8f0);
                }
                else {
                  (**(code **)(*piVar2 + 0x3c))(piVar2,(uint)(iVar4 * 3000) / 100 - 3000);
                }
              }
              piVar1 = (int *)*piVar1;
              if (piVar1 != (int *)0x0) {
                if (*(float *)(*(int *)(param_1 + 4) + 0x20) == _DAT_008effa0) {
                  (**(code **)(*piVar1 + 0x44))(piVar1,0);
                  *(undefined4 *)(param_1 + 0x50) = 0;
                  *(undefined1 *)(param_1 + 0x4c) = 0;
                  return 1;
                }
                puStack_6c = (undefined4 *)0x0;
                uVar3 = func_0x00892e78();
                if (uVar3 < 100) {
                  uVar3 = 100;
                }
                else if (99999 < uVar3) {
                  uVar3 = 100000;
                }
                (**(code **)(*piVar1 + 0x44))(piVar1,uVar3);
              }
              *(undefined4 *)(param_1 + 0x50) = 0;
              *(undefined1 *)(param_1 + 0x4c) = 0;
              return 1;
            }
            if (_DAT_009d2c04 != 0) {
              func_0x007647d0(_DAT_009d2c04,0x985f10);
            }
          }
        }
        else if (_DAT_009d2c04 != 0) {
          func_0x007647d0(_DAT_009d2c04,0x985f74);
          return 0;
        }
      }
      else if (_DAT_009d2c04 != 0) {
        puStack_64 = (undefined4 *)0x985fa0;
        puStack_68 = (undefined *)_DAT_009d2c04;
        puStack_6c = (undefined4 *)0x76849f;
        func_0x007647d0();
        return 0;
      }
    }
    return 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00768640 | Classified: AngelicaFile::proc_768640 */
/* ==================================================================== */

undefined4 __fastcall FUN_00768640(int *param_1)

{
  (**(code **)(*param_1 + 0x20))();
  if (param_1[0x12] != 0) {
    (**(code **)(*param_1 + 0x1c))();
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00768660 | Classified: AngelicaFile::proc_768660 */
/* ==================================================================== */

undefined4 __fastcall FUN_00768660(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x48))(piVar1);
    (**(code **)(**(int **)(param_1 + 0x30) + 8))(*(int **)(param_1 + 0x30));
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x28);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x48))(piVar1);
    (**(code **)(**(int **)(param_1 + 0x28) + 8))(*(int **)(param_1 + 0x28));
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  if (*(int *)(param_1 + 0x44) != 0) {
    CloseHandle(*(int *)(param_1 + 0x44));
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  *(undefined1 *)(param_1 + 0x68) = 0;
  return 1;
}


/* ==================================================================== */
/* Address: 0x007686d0 | Classified: elementclient::AMSoundBuffer__Play__Call_IDirec@0x7686d0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_007686d0(int param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(char *)(param_1 + 0x68) == '\0') {
    return 1;
  }
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    if (*(int *)(param_1 + 0x50) != 2) {
      (**(code **)(*piVar1 + 0x34))(piVar1,0);
    }
    ResetEvent(*(undefined4 *)(param_1 + 0x44));
    iVar2 = (**(code **)(**(int **)(param_1 + 0x30) + 0x30))
                      (*(int **)(param_1 + 0x30),0,0,param_2 != '\0');
    if (iVar2 < 0) {
      if (_DAT_009d2c04 != 0) {
        func_0x007647d0(_DAT_009d2c04,0x986000);
      }
      return 0;
    }
    uVar3 = FUN_00766290();
    *(undefined4 *)(param_1 + 0x40) = uVar3;
  }
  if (((*(int *)(param_1 + 0x50) != 2) && (*(int *)(param_1 + 0x48) != 0)) &&
     (*(char *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 0x18) + 0x14) + 4) != '\0')) {
    _Start_AMImmEffect__QAE_NXZ();
  }
  *(char *)(param_1 + 0x4c) = param_2;
  *(undefined4 *)(param_1 + 0x50) = 1;
  *(undefined1 *)(param_1 + 0x58) = 0;
  *(undefined1 *)(param_1 + 0x59) = 0;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00768790 | Classified: AngelicaFile::proc_768790 */
/* ==================================================================== */

undefined4 __fastcall FUN_00768790(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x48))(piVar1);
    (**(code **)(**(int **)(param_1 + 0x30) + 0x34))(*(int **)(param_1 + 0x30),0);
  }
  if (*(int *)(param_1 + 0x48) != 0) {
    _Stop_AMImmEffect__QAE_NXZ();
  }
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined1 *)(param_1 + 0x4c) = 0;
  if ((*(char *)(param_1 + 0x58) != '\0') || (*(char *)(param_1 + 0x59) != '\0')) {
    piVar1 = *(int **)(param_1 + 0x30);
    iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x1c);
    *(int *)(param_1 + 0x54) = iVar2;
    if (piVar1 != (int *)0x0) {
      if (iVar2 == 0) {
        (**(code **)(*piVar1 + 0x3c))(piVar1,0xffffd8f0);
        *(undefined1 *)(param_1 + 0x58) = 0;
        *(undefined1 *)(param_1 + 0x59) = 0;
        return 1;
      }
      (**(code **)(*piVar1 + 0x3c))(piVar1,(uint)(iVar2 * 3000) / 100 - 3000);
    }
  }
  *(undefined1 *)(param_1 + 0x58) = 0;
  *(undefined1 *)(param_1 + 0x59) = 0;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00768830 | Classified: AngelicaFile::proc_768830 */
/* ==================================================================== */

undefined4 __fastcall FUN_00768830(int param_1)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 0x50) == 1) {
    piVar1 = *(int **)(param_1 + 0x30);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x48))(piVar1);
    }
    if (*(int *)(param_1 + 0x48) != 0) {
      _Stop_AMImmEffect__QAE_NXZ();
    }
    *(undefined4 *)(param_1 + 0x50) = 2;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00768860 | Classified: AngelicaFile::proc_768860 */
/* ==================================================================== */

undefined4 FUN_00768860(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint in_stack_00000018;
  int in_stack_00000020;
  int in_stack_00000024;
  int iStack_4;
  
  iVar4 = 0;
  iVar3 = 0;
  iStack_4 = 0;
  if (0 < in_stack_00000020) {
    uVar1 = in_stack_00000018 & 0xffff;
    do {
      puVar5 = (undefined4 *)(param_2 + iVar4);
      puVar6 = (undefined4 *)(param_1 + iVar3);
      for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      iVar3 = iVar3 + uVar1;
      for (uVar2 = in_stack_00000018 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
      iStack_4 = iStack_4 + in_stack_00000024;
      iVar4 = iVar4 + uVar1 * in_stack_00000024;
    } while (iStack_4 < in_stack_00000020);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007688d0 | Classified: elementclient::AMSoundBuffer__Load__File___s__U@0x7688d0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_007688d0(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  ulonglong uVar1;
  undefined2 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_EBX;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  undefined4 *unaff_FS_OFFSET;
  bool bVar9;
  undefined4 uVar10;
  undefined4 uStack_2f0;
  int iStack_2ec;
  int iStack_2e8;
  int iStack_2e4;
  int iStack_2e0;
  undefined1 auStack_2dc [4];
  undefined1 auStack_2d8 [4];
  undefined4 uStack_2d4;
  undefined4 uStack_2d0;
  int aiStack_2cc [4];
  uint uStack_2bc;
  uint uStack_2b8;
  undefined2 uStack_2b4;
  undefined4 uStack_2b0;
  int aiStack_2ac [4];
  uint uStack_29c;
  uint uStack_298;
  undefined2 uStack_294;
  undefined4 uStack_290;
  undefined4 uStack_288;
  uint uStack_284;
  uint uStack_280;
  uint uStack_27c;
  undefined2 uStack_278;
  uint uStack_270;
  uint uStack_15c;
  undefined4 uStack_154;
  uint uStack_150;
  uint uStack_14c;
  uint uStack_148;
  undefined2 uStack_144;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cbe06;
  *unaff_FS_OFFSET = &uStack_c;
  param_1[1] = param_2;
  piVar7 = param_1 + 0xf;
  iVar5 = *(int *)(*(int *)(param_2 + 0x18) + 0x14);
  func_0x007638a0(param_4);
  func_0x00763cf0();
  iVar4 = func_0x00764880(*piVar7);
  param_1[0xe] = iVar4;
  if (*(int *)(param_2 + 8) == 0) {
    uVar10 = 1;
    goto LAB_00768f76;
  }
  iVar4 = strstr(*piVar7,0x951a70);
  if (iVar4 == 0) {
    iVar4 = strstr(*piVar7,0x9860b0);
    if (iVar4 == 0) {
      if (_DAT_009d2c04 != 0) {
        func_0x007647d0(_DAT_009d2c04,0x98603c,param_2 + 8);
      }
    }
    else {
      func_0x0076b4f0();
      puStack_8 = (undefined *)0x1;
      cVar3 = func_0x0076b530(param_2 + 8);
      uVar2 = uStack_278;
      uVar6 = uStack_284;
      if (cVar3 == '\0') {
        if (_DAT_009d2c04 != 0) {
          uVar10 = 0x986078;
LAB_00768f33:
          func_0x007647d0(_DAT_009d2c04,uVar10);
        }
      }
      else {
        iVar5 = *(int *)(iVar5 + 8);
        piVar7 = aiStack_2ac;
        for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
          *piVar7 = 0;
          piVar7 = piVar7 + 1;
        }
        uVar8 = 1;
        aiStack_2ac[2] = uStack_288;
        uStack_298 = uStack_27c;
        uStack_294 = uVar2;
        aiStack_2ac[0] = 0;
        uStack_290 = 0;
        if (iVar5 == 1) {
          bVar9 = uVar6 < 0x5654;
LAB_00768d15:
          if (!bVar9) {
            uVar8 = 2;
          }
        }
        else if (iVar5 == 2) {
          if (uVar6 < 0xac44) {
            bVar9 = uVar6 < 0x5622;
            goto LAB_00768d15;
          }
          uVar8 = 4;
        }
        uVar1 = (ulonglong)uStack_270 / (ulonglong)(uStack_27c & 0xffff);
        aiStack_2ac[1] = (int)(uVar1 / uVar8);
        if (aiStack_2ac[1] * uVar8 < (uint)uVar1) {
          aiStack_2ac[1] = aiStack_2ac[1] + 1;
        }
        aiStack_2ac[1] = (uStack_27c & 0xffff) * aiStack_2ac[1];
        aiStack_2ac[3] = uVar6 / uVar8;
        uStack_29c = uStack_280 / uVar8;
        cVar3 = (**(code **)(*param_1 + 4))(uStack_4,aiStack_2ac);
        if (cVar3 == '\0') {
          if (_DAT_009d2c04 != 0) {
            uVar10 = 0x98618c;
            goto LAB_00768f33;
          }
        }
        else {
          iVar5 = (**(code **)(*(int *)param_1[0xc] + 0x2c))
                            ((int *)param_1[0xc],0,0,&uStack_2f0,&iStack_2ec,&iStack_2e8,&uStack_2d0
                             ,2);
          if (iVar5 == 0) {
            if ((iStack_2e8 == 0) && (iStack_2ec == aiStack_2ac[1])) {
              if (uVar8 == 1) {
                cVar3 = func_0x0076b610(uStack_2f0,uStack_270,auStack_2dc,&stack0xfffffd0a);
                if (cVar3 == '\0') {
LAB_00768e16:
                  if (_DAT_009d2c04 != 0) {
                    uVar10 = 0x98612c;
                    goto LAB_00768f33;
                  }
                }
                else {
LAB_00768ecf:
                  iVar5 = (**(code **)(*(int *)param_1[0xc] + 0x4c))
                                    ((int *)param_1[0xc],uStack_2f0,iStack_2ec,iStack_2e8,uStack_2d0
                                    );
                  if (iVar5 == 0) {
                    func_0x0076b5a0();
                    uStack_c = 0xffffffff;
                    func_0x0076b520();
                    *(undefined1 *)(param_1 + 0x1a) = 1;
                    uVar10 = 1;
                    goto LAB_00768f76;
                  }
                  if (_DAT_009d2c04 != 0) {
                    uVar10 = 0x986100;
                    goto LAB_00768f33;
                  }
                }
              }
              else {
                iVar5 = malloc(uStack_270);
                if (iVar5 != 0) {
                  cVar3 = func_0x0076b610(iVar5,uStack_270,auStack_2dc,&stack0xfffffd0a);
                  if (cVar3 != '\0') {
                    FUN_00768860(uStack_2f0,iVar5,uStack_288,uStack_284,uStack_280,uStack_27c,
                                 uStack_278,uStack_270 / (uStack_27c & 0xffff),uVar8);
                    free(iVar5);
                    goto LAB_00768ecf;
                  }
                  goto LAB_00768e16;
                }
              }
            }
            else if (_DAT_009d2c04 != 0) {
              uVar10 = 0x9860b8;
              goto LAB_00768f33;
            }
          }
          else if (_DAT_009d2c04 != 0) {
            uVar10 = 0x986160;
            goto LAB_00768f33;
          }
        }
      }
      uStack_c = 0xffffffff;
      func_0x0076b520();
    }
  }
  else {
    func_0x0076b700();
    puStack_8 = (undefined *)0x0;
    cVar3 = func_0x0076b720(param_2);
    uVar10 = uStack_154;
    if (cVar3 == '\0') {
      if (_DAT_009d2c04 != 0) {
        uVar10 = 0x9861b4;
LAB_00768c23:
        func_0x007647d0(_DAT_009d2c04,uVar10);
      }
    }
    else {
      iVar5 = *(int *)(iVar5 + 8);
      piVar7 = aiStack_2cc;
      for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar7 = 0;
        piVar7 = piVar7 + 1;
      }
      aiStack_2cc[2] = uVar10;
      uStack_2b4 = uStack_144;
      uVar6 = 1;
      uStack_2b8 = uStack_148;
      aiStack_2cc[0] = 0;
      uStack_2b0 = 0;
      if (iVar5 == 1) {
LAB_007689f9:
        if (0x5621 < uStack_150) {
          uVar6 = 2;
        }
      }
      else if (iVar5 == 2) {
        if (uStack_150 < 0xac44) goto LAB_007689f9;
        uVar6 = 4;
      }
      uVar1 = (ulonglong)uStack_15c / (ulonglong)(uStack_148 & 0xffff);
      aiStack_2cc[1] = (int)(uVar1 / uVar6);
      if (aiStack_2cc[1] * uVar6 < (uint)uVar1) {
        aiStack_2cc[1] = aiStack_2cc[1] + 1;
      }
      aiStack_2cc[1] = (uStack_148 & 0xffff) * aiStack_2cc[1];
      aiStack_2cc[3] = uStack_150 / uVar6;
      uStack_2bc = uStack_14c / uVar6;
      cVar3 = (**(code **)(*param_1 + 4))(param_2,aiStack_2cc);
      if (cVar3 == '\0') {
        if (_DAT_009d2c04 != 0) {
          uVar10 = 0x98618c;
          goto LAB_00768c23;
        }
      }
      else {
        iVar5 = (**(code **)(*(int *)param_1[0xc] + 0x2c))
                          ((int *)param_1[0xc],0,0,&stack0xfffffd0c,&iStack_2e4,&iStack_2e0,
                           &uStack_2d4,2);
        if (iVar5 == 0) {
          if ((iStack_2e0 == 0) && (iStack_2e4 == aiStack_2cc[1])) {
            if (uVar6 == 1) {
              cVar3 = func_0x0076b960(unaff_EBX,uStack_15c,auStack_2d8,&stack0xfffffd0b);
              if (cVar3 == '\0') {
LAB_00768afd:
                if (_DAT_009d2c04 != 0) {
                  uVar10 = 0x98612c;
                  goto LAB_00768c23;
                }
              }
              else {
LAB_00768bb6:
                iVar5 = (**(code **)(*(int *)param_1[0xc] + 0x4c))
                                  ((int *)param_1[0xc],unaff_EBX,iStack_2e4,iStack_2e0,uStack_2d4);
                if (iVar5 == 0) {
                  func_0x0076b8f0();
                  uStack_c = 0xffffffff;
                  func_0x00430860();
                  *(undefined1 *)(param_1 + 0x1a) = 1;
                  uVar10 = 1;
                  goto LAB_00768f76;
                }
                if (_DAT_009d2c04 != 0) {
                  uVar10 = 0x986100;
                  goto LAB_00768c23;
                }
              }
            }
            else {
              iVar5 = malloc(uStack_15c);
              if (iVar5 != 0) {
                cVar3 = func_0x0076b960(iVar5,uStack_15c,auStack_2d8,&stack0xfffffd0b);
                if (cVar3 != '\0') {
                  FUN_00768860(unaff_EBX,iVar5,uStack_154,uStack_150,uStack_14c,uStack_148,
                               uStack_144,uStack_15c / (uStack_148 & 0xffff),uVar6);
                  free(iVar5);
                  goto LAB_00768bb6;
                }
                goto LAB_00768afd;
              }
            }
          }
          else if (_DAT_009d2c04 != 0) {
            uVar10 = 0x9860b8;
            goto LAB_00768c23;
          }
        }
        else if (_DAT_009d2c04 != 0) {
          uVar10 = 0x986160;
          goto LAB_00768c23;
        }
      }
    }
    uStack_c = 0xffffffff;
    func_0x00430860();
  }
  uVar10 = 0;
LAB_00768f76:
  *unaff_FS_OFFSET = uStack_10;
  return uVar10;
}


/* ==================================================================== */
/* Address: 0x00768fa0 | Classified: AngelicaFile::proc_768fa0 */
/* ==================================================================== */

undefined4 __fastcall FUN_00768fa0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  float10 extraout_ST0;
  
  iVar2 = param_1[0x16];
  if (((char)iVar2 != '\0') || (*(char *)((int)param_1 + 0x59) != '\0')) {
    iVar3 = func_0x00892e78();
    param_1[0x19] = (int)(float)(extraout_ST0 - (float10)iVar3);
    if (iVar3 != 0) {
      if ((char)iVar2 == '\0') {
        if (*(char *)((int)param_1 + 0x59) != '\0') {
          if ((uint)(param_1[0x17] + iVar3) < (uint)param_1[0x15]) {
            param_1[0x15] = param_1[0x15] - iVar3;
          }
          else {
            param_1[0x15] = param_1[0x17];
          }
          piVar1 = (int *)param_1[0xc];
          if (piVar1 != (int *)0x0) {
            if (param_1[0x15] == 0) {
              (**(code **)(*piVar1 + 0x3c))(piVar1,0xffffd8f0);
            }
            else {
              (**(code **)(*piVar1 + 0x3c))(piVar1,(uint)(param_1[0x15] * 3000) / 100 - 3000);
            }
          }
          if ((uint)param_1[0x15] <= (uint)param_1[0x17]) {
            *(undefined1 *)((int)param_1 + 0x59) = 0;
            (**(code **)(*param_1 + 0x28))();
          }
        }
      }
      else {
        iVar2 = param_1[0x15];
        param_1[0x15] = iVar2 + iVar3;
        if ((uint)param_1[0x17] < (uint)(iVar2 + iVar3)) {
          param_1[0x15] = param_1[0x17];
        }
        piVar1 = (int *)param_1[0xc];
        if (piVar1 != (int *)0x0) {
          if (param_1[0x15] == 0) {
            (**(code **)(*piVar1 + 0x3c))(piVar1,0xffffd8f0);
          }
          else {
            (**(code **)(*piVar1 + 0x3c))(piVar1,(uint)(param_1[0x15] * 3000) / 100 - 3000);
          }
        }
        if (param_1[0x17] == param_1[0x15]) {
          *(undefined1 *)(param_1 + 0x16) = 0;
          return 1;
        }
      }
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007690e0 | Classified: AngelicaFile::proc_7690e0 */
/* ==================================================================== */

undefined4 __fastcall FUN_007690e0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1[1] + 8) != 0) {
    if (param_1[0x14] != 1) {
      return 1;
    }
    if ((char)param_1[0x13] != '\0') {
      return 1;
    }
    iVar1 = WaitForSingleObject(param_1[0x11],0);
    if (iVar1 != 0) {
      iVar2 = FUN_00766290();
      iVar1 = param_1[0x10];
      iVar3 = func_0x00892fe0((ulonglong)(uint)param_1[3] * 1000,param_1[6],0);
      if ((uint)(iVar2 - iVar1) <= iVar3 + 100U) {
        return 1;
      }
    }
  }
  (**(code **)(*param_1 + 0x28))();
  return 1;
}


/* ==================================================================== */
/* Address: 0x00769230 | Classified: AngelicaFile::proc_769230 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00769230(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  float fVar3;
  
  *(undefined1 *)(param_1 + 0x58) = 1;
  *(undefined1 *)(param_1 + 0x59) = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x1c);
  *(int *)(param_1 + 0x5c) = iVar1;
  *(undefined4 *)(param_1 + 100) = 0;
  fVar3 = ((float)(iVar1 - *(int *)(param_1 + 0x54)) * _DAT_008eff94) / (float)param_2;
  *(float *)(param_1 + 0x60) = fVar3;
  if (fVar3 < _DAT_008effc4 != (fVar3 == _DAT_008effc4)) {
    *(undefined1 *)(param_1 + 0x58) = 0;
    *(undefined4 *)(param_1 + 0x60) = 0;
    *(int *)(param_1 + 0x54) = iVar1;
    piVar2 = *(int **)(param_1 + 0x30);
    if (piVar2 != (int *)0x0) {
      if (iVar1 == 0) {
        (**(code **)(*piVar2 + 0x3c))(piVar2,0xffffd8f0);
        return 1;
      }
      (**(code **)(*piVar2 + 0x3c))(piVar2,(uint)(iVar1 * 3000) / 100 - 3000);
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007692d0 | Classified: AngelicaFile::proc_7692d0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_007692d0(int *param_1,int param_2)

{
  float fVar1;
  
  *(undefined1 *)((int)param_1 + 0x59) = 1;
  *(undefined1 *)(param_1 + 0x16) = 0;
  param_1[0x17] = 0;
  param_1[0x19] = 0;
  fVar1 = ((float)(uint)param_1[0x15] * _DAT_008eff94) / (float)param_2;
  param_1[0x18] = (int)fVar1;
  if (fVar1 < _DAT_008effc4 != (fVar1 == _DAT_008effc4)) {
    *(undefined1 *)((int)param_1 + 0x59) = 0;
    (**(code **)(*param_1 + 0x28))();
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00769320 | Classified: AngelicaFile::proc_769320 */
/* ==================================================================== */

undefined1 __fastcall FUN_00769320(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  undefined1 uVar6;
  undefined1 *puVar7;
  undefined1 auStack_8 [4];
  undefined1 auStack_4 [4];
  
  puVar7 = auStack_8;
  iVar3 = param_1[0x13];
  iVar1 = param_1[0x14];
  (**(code **)(*(int *)param_1[0xc] + 0x10))((int *)param_1[0xc],puVar7,auStack_4);
  uVar6 = SUB41(puVar7,0);
  (**(code **)(*(int *)param_1[0xc] + 0x48))((int *)param_1[0xc]);
  (**(code **)(*param_1 + 0x20))();
  iVar5 = param_1[0xf];
  cVar4 = (**(code **)(*param_1 + 0xc))(param_1[1],(char)iVar3,iVar5);
  if (cVar4 == '\0') {
    return 0;
  }
  if (iVar1 == 1) {
    iVar1 = param_1[0x16];
    (**(code **)(*param_1 + 0x24))(iVar5);
    *(undefined1 *)((int)param_1 + 0x59) = uVar6;
    *(char *)(param_1 + 0x16) = (char)iVar1;
    (**(code **)(*(int *)param_1[0xc] + 0x34))((int *)param_1[0xc],iVar5);
  }
  piVar2 = (int *)param_1[0xc];
  if (piVar2 != (int *)0x0) {
    if (param_1[0x15] == 0) {
      (**(code **)(*piVar2 + 0x3c))(piVar2,0xffffd8f0);
      return 1;
    }
    (**(code **)(*piVar2 + 0x3c))(piVar2,(uint)(param_1[0x15] * 3000) / 100 - 3000);
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00769400 | Classified: AngelicaFile::proc_769400 */
/* ==================================================================== */

undefined4 * __fastcall FUN_00769400(undefined4 *param_1)

{
  FUN_007682b0();
  *param_1 = &UNK_008f0108;
  param_1[0x2b] = 0;
  *(undefined1 *)(param_1 + 0x2c) = 0;
  param_1[0xd] = 1;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00769430 | Classified: AngelicaFile::proc_769430 */
/* ==================================================================== */

undefined4 __thiscall FUN_00769430(undefined4 param_1,byte param_2)

{
  FUN_00769450();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00769450 | Classified: AngelicaFile::proc_769450 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00769450(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &UNK_008f0108;
  *param_1 = &UNK_008f00d0;
  piVar1 = (int *)(param_1[0xf] + -0xc);
  if (*piVar1 == -1) {
    *piVar1 = 1;
  }
  func_0x00763450(piVar1);
  param_1[0xf] = _DAT_009858e4;
  return;
}


/* ==================================================================== */
/* Address: 0x00769520 | Classified: AngelicaFile::proc_769520 */
/* ==================================================================== */

undefined4 __fastcall FUN_00769520(int *param_1)

{
  int *piVar1;
  undefined4 unaff_ESI;
  
  piVar1 = (int *)param_1[0x2b];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    param_1[0x2b] = 0;
  }
  (**(code **)(*param_1 + 0x20))(unaff_ESI);
  if (param_1[0x12] != 0) {
    (**(code **)(*param_1 + 0x1c))();
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00769550 | Classified: AngelicaFile::proc_769550 */
/* ==================================================================== */

undefined4 __fastcall FUN_00769550(int param_1)

{
  int *piVar1;
  undefined4 unaff_ESI;
  
  piVar1 = *(int **)(param_1 + 0xac);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0xac) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x2c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,unaff_ESI);
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x48))(piVar1);
    (**(code **)(**(int **)(param_1 + 0x30) + 8))(*(int **)(param_1 + 0x30));
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x28);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x48))(piVar1);
    (**(code **)(**(int **)(param_1 + 0x28) + 8))(*(int **)(param_1 + 0x28));
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  if (*(int *)(param_1 + 0x44) != 0) {
    CloseHandle(*(int *)(param_1 + 0x44));
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  *(undefined1 *)(param_1 + 0x68) = 0;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00769580 | Classified: elementclient::AM3DSoundBuffer__UpdateChanges__@0x769580 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __fastcall FUN_00769580(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 auStack_40 [4];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar4 = *(int *)(param_1 + 4);
  if (((*(int *)(iVar4 + 8) != 0) &&
      (iVar4 = CONCAT31((int3)((uint)iVar4 >> 8),*(char *)(param_1 + 0xb0)),
      *(char *)(param_1 + 0xb0) == '\0')) &&
     (piVar1 = *(int **)(param_1 + 0xac), piVar1 != (int *)0x0)) {
    puVar5 = auStack_40;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    auStack_40[0] = 0x40;
    auStack_40[1] = *(undefined4 *)(param_1 + 0x70);
    auStack_40[2] = *(undefined4 *)(param_1 + 0x74);
    auStack_40[3] = *(undefined4 *)(param_1 + 0x78);
    uStack_30 = *(undefined4 *)(param_1 + 0x7c);
    uStack_2c = *(undefined4 *)(param_1 + 0x80);
    uStack_24 = *(undefined4 *)(param_1 + 0x88);
    uStack_28 = *(undefined4 *)(param_1 + 0x84);
    uStack_20 = *(undefined4 *)(param_1 + 0x8c);
    uStack_1c = *(undefined4 *)(param_1 + 0x90);
    uStack_18 = *(undefined4 *)(param_1 + 0x94);
    uStack_10 = *(undefined4 *)(param_1 + 0x9c);
    uStack_14 = *(undefined4 *)(param_1 + 0x98);
    uStack_8 = *(undefined4 *)(param_1 + 0xa4);
    uStack_c = *(undefined4 *)(param_1 + 0xa0);
    uStack_4 = *(undefined4 *)(param_1 + 0xa8);
    iVar2 = (**(code **)(*piVar1 + 0x30))(piVar1,auStack_40,0);
    iVar4 = 0;
    if (iVar2 != 0) {
      uVar3 = 0;
      if (_DAT_009d2c04 != 0) {
        uVar3 = func_0x007647d0(_DAT_009d2c04,0x9862a8);
      }
      return uVar3 & 0xffffff00;
    }
  }
  return CONCAT31((int3)((uint)iVar4 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x00769690 | Classified: elementclient::AM3DSoundBuffer__RetrieveParamsF@0x769690 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00769690(int param_1)

{
  int iVar1;
  undefined4 unaff_ESI;
  undefined4 *puVar2;
  undefined4 auStack_40 [4];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (*(int *)(*(int *)(param_1 + 4) + 8) != 0) {
    puVar2 = auStack_40;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    auStack_40[0] = 0x40;
    iVar1 = (**(code **)(**(int **)(param_1 + 0xac) + 0xc))(*(int **)(param_1 + 0xac),auStack_40);
    if (iVar1 != 0) {
      if (_DAT_009d2c04 != 0) {
        func_0x007647d0(_DAT_009d2c04,0x9862f0);
      }
      return 0;
    }
    *(undefined4 *)(param_1 + 0x70) = unaff_ESI;
    *(undefined4 *)(param_1 + 0x74) = auStack_40[0];
    *(undefined4 *)(param_1 + 0x78) = auStack_40[1];
    *(undefined4 *)(param_1 + 0x7c) = auStack_40[2];
    *(undefined4 *)(param_1 + 0x80) = auStack_40[3];
    *(undefined4 *)(param_1 + 0x84) = uStack_30;
    *(undefined4 *)(param_1 + 0x88) = uStack_2c;
    *(undefined4 *)(param_1 + 0x8c) = uStack_28;
    *(undefined4 *)(param_1 + 0x90) = uStack_24;
    *(undefined4 *)(param_1 + 0x94) = uStack_20;
    *(undefined4 *)(param_1 + 0x98) = uStack_1c;
    *(undefined4 *)(param_1 + 0x9c) = uStack_18;
    *(undefined4 *)(param_1 + 0xa0) = uStack_14;
    *(undefined4 *)(param_1 + 0xa4) = uStack_10;
    *(undefined4 *)(param_1 + 0xa8) = uStack_c;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x007697b0 | Classified: elementclient::AM3DSoundBuffer__SetForce2D____S@0x7697b0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_007697b0(int param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0xb0) == param_2) {
    return 1;
  }
  if (*(int *)(*(int *)(param_1 + 4) + 8) == 0) {
    *(char *)(param_1 + 0xb0) = param_2;
    return 1;
  }
  piVar1 = *(int **)(param_1 + 0xac);
  if (param_2 == '\0') {
    iVar2 = (**(code **)(*piVar1 + 0x48))(piVar1,0);
    if (-1 < iVar2) {
      *(undefined1 *)(param_1 + 0xb0) = 0;
      FUN_00769580();
      return 1;
    }
    if (_DAT_009d2c04 != 0) {
      func_0x007647d0(_DAT_009d2c04,0x98637c);
      return 0;
    }
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 0x48))(piVar1,2,0);
    if (-1 < iVar2) {
      *(undefined1 *)(param_1 + 0xb0) = 1;
      return 1;
    }
    if (_DAT_009d2c04 != 0) {
      func_0x007647d0(_DAT_009d2c04,0x986344);
    }
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x00769a30 | Classified: AngelicaFile::proc_769a30 */
/* ==================================================================== */

undefined4 * __fastcall FUN_00769a30(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  func_0x0076b9c0();
  *param_1 = &UNK_008f01b8;
  param_1[1] = 0;
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  param_1[0x15a] = 0;
  param_1[0x15b] = 0;
  param_1[0x15c] = 0;
  param_1[0x15d] = 0;
  param_1[0x159] = 0xffffffff;
  param_1[0x15e] = 0;
  *(undefined1 *)(param_1 + 0x15f) = 1;
  param_1[0x160] = 3000;
  param_1[0x161] = 0;
  *(undefined1 *)((int)param_1 + 0x3d) = 0;
  *(undefined1 *)(param_1 + 0xf) = 0;
  puVar2 = param_1 + 2;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = param_1 + 0x59;
  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)((int)param_1 + 0x3e) = 0;
  param_1[0x164] = 0;
  param_1[0x165] = 0;
  param_1[0x166] = 0;
  *(undefined1 *)(param_1 + 0x167) = 0;
  param_1[0x169] = 0;
  puVar2 = param_1 + 0x16a;
  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = param_1 + 0x26a;
  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = param_1 + 0x36a;
  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x163] = 100;
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00769b10 | Classified: AngelicaFile::proc_769b10 */
/* ==================================================================== */

undefined4 __thiscall FUN_00769b10(undefined4 param_1,byte param_2)

{
  FUN_00769b30();
  if ((param_2 & 1) != 0) {
    func_0x00763260(param_1);
  }
  return param_1;
}


/* ==================================================================== */
/* Address: 0x00769b30 | Classified: AngelicaFile::proc_769b30 */
/* ==================================================================== */

void __fastcall FUN_00769b30(undefined4 *param_1)

{
  *param_1 = &UNK_008f01b8;
  param_1[0x46a] = &UNK_008f01ec;
  return;
}


/* ==================================================================== */
/* Address: 0x00769b50 | Classified: elementclient::AMSoundStream__Init____failed_to@0x769b50 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00769b50(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int unaff_retaddr;
  
  cVar1 = FUN_00769bc0(param_1,param_3);
  if (cVar1 == '\0') {
    if (_DAT_009d2c04 == 0) {
      return 0;
    }
    func_0x007647d0(_DAT_009d2c04,0x9863e0);
    return 0;
  }
  if ((unaff_retaddr != 0) && (cVar1 = FUN_0076a540(unaff_retaddr), cVar1 == '\0')) {
    if (_DAT_009d2c04 == 0) {
      return 0;
    }
    func_0x007647d0(_DAT_009d2c04,0x9863b0);
    return 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00769bc0 | Classified: elementclient::AMSoundStream__Init_Internal____b@0x769bc0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00769bc0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  *(undefined4 *)(param_1 + 4) = param_2;
  if (param_3 == 0) {
    *(undefined4 *)(param_1 + 0x1c) = 0x3c;
    *(undefined4 *)(param_1 + 0x20) = 10;
  }
  else {
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_3 + 0x14);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_3 + 0x18);
  }
  *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(param_1 + 0x1c);
  iVar1 = *(int *)(param_1 + 0x20);
  *(int *)(param_1 + 0x150) = iVar1;
  if (0x100 < iVar1) {
    if (_DAT_009d2c04 != 0) {
      func_0x007647d0(_DAT_009d2c04,0x986450,0x100);
    }
    return 0;
  }
  iVar4 = 0;
  if (0 < iVar1) {
    puVar5 = (undefined4 *)(param_1 + 0x164);
    do {
      uVar3 = (*_DAT_009b3b0c)(0,0,0,0);
      *puVar5 = uVar3;
      ResetEvent(*(undefined4 *)(param_1 + 0x164));
      iVar4 = iVar4 + 1;
      puVar5 = puVar5 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x150));
  }
  InitializeCriticalSection(param_1 + 0x24);
  if (*(int *)(*(int *)(param_1 + 4) + 8) != 0) {
    cVar2 = func_0x0076ba10(0x400);
    if (cVar2 != '\0') {
      return 1;
    }
    if (_DAT_009d2c04 != 0) {
      func_0x007647d0(_DAT_009d2c04,0x986418);
    }
    return 0;
  }
  *(undefined1 *)(param_1 + 0x3d) = 0;
  *(undefined4 *)(param_1 + 0x578) = 1;
  return 1;
}


/* ==================================================================== */
/* Address: 0x00769cd0 | Classified: AngelicaFile::proc_769cd0 */
/* ==================================================================== */

undefined4 __fastcall FUN_00769cd0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  func_0x0076bd00();
  if (*(int *)(param_1 + 0x5a4) != 0) {
    func_0x00763260(*(int *)(param_1 + 0x5a4));
    *(undefined4 *)(param_1 + 0x5a4) = 0;
  }
  FUN_0076aba0();
  DeleteCriticalSection(param_1 + 0x24);
  iVar1 = *(int *)(param_1 + 0x150);
  iVar2 = 0;
  if (0 < iVar1) {
    piVar3 = (int *)(param_1 + 0x5a8);
    do {
      if (piVar3[-0x111] != 0) {
        CloseHandle(piVar3[-0x111]);
        piVar3[-0x111] = 0;
      }
      if (*piVar3 != 0) {
        func_0x00763260(*piVar3);
        *piVar3 = 0;
      }
      iVar1 = *(int *)(param_1 + 0x150);
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < iVar1);
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x00769d70 | Classified: elementclient::AMSoundStream__Play____Call_Load@0x769d70 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00769d70(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  if (param_2 != 0) {
    iVar2 = _stricmp(param_1 + 0x3e,param_2);
    if (iVar2 != 0) {
      FUN_0076aba0();
      cVar1 = FUN_0076a540(param_2);
      if (cVar1 == '\0') {
        if (_DAT_009d2c04 != 0) {
          func_0x007647d0(_DAT_009d2c04,0x9864c0,param_2);
        }
        return 0;
      }
      goto LAB_00769dc7;
    }
  }
  FUN_00769f10();
LAB_00769dc7:
  cVar1 = FUN_00769e00();
  if (cVar1 == '\0') {
    if (_DAT_009d2c04 != 0) {
      func_0x007647d0(_DAT_009d2c04,0x986494);
    }
    return 0;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00769e00 | Classified: elementclient::AMSoundStream__Play_Internal____F@0x769e00 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00769e00(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iStack_4;
  
  if (*(char *)(param_1 + 0x3d) != '\0') {
    iVar3 = *(int *)(param_1 + 0x564);
    iStack_4 = param_1;
    if (iVar3 == 0) {
      func_0x0076b900(0);
    }
    else if (iVar3 == 1) {
      func_0x0076b5d0(0);
    }
    else if (iVar3 == 2) {
      func_0x0076c3e0(0);
    }
    iVar3 = 0;
    *(undefined4 *)(param_1 + 0x158) = 0;
    *(undefined4 *)(param_1 + 0x154) = 0;
    *(undefined4 *)(param_1 + 0x598) = 0;
    *(undefined1 *)(param_1 + 0x160) = 0;
    if (0 < *(int *)(param_1 + 0x150)) {
      do {
        cVar1 = FUN_0076a030(iVar3);
        if (cVar1 == '\0') {
          if (_DAT_009d2c04 != 0) {
            func_0x007647d0(_DAT_009d2c04,0x986500,iVar3);
          }
          return 0;
        }
        ResetEvent(*(undefined4 *)(param_1 + 0x164));
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1 + 0x150));
    }
    *(undefined1 *)(param_1 + 0x3c) = 0;
    uVar2 = CreateThread(0,0,&UNK_00769fe0,param_1,0,&iStack_4);
    SetThreadPriority(uVar2,0xf);
    (**(code **)(**(int **)(param_1 + 0x144) + 0x34))(*(int **)(param_1 + 0x144),0);
    (**(code **)(**(int **)(param_1 + 0x144) + 0x30))(*(int **)(param_1 + 0x144),0,0,1);
    *(undefined4 *)(param_1 + 0x578) = 1;
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x00769f10 | Classified: AngelicaFile::proc_769f10 */
/* ==================================================================== */

undefined4 __fastcall FUN_00769f10(int param_1)

{
  undefined4 in_EAX;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = CONCAT31((int3)((uint)in_EAX >> 8),*(char *)(param_1 + 0x3d));
  if (*(char *)(param_1 + 0x3d) != '\0') {
    (**(code **)(**(int **)(param_1 + 0x144) + 0x48))(*(int **)(param_1 + 0x144));
    (**(code **)(**(int **)(param_1 + 0x144) + 0x34))(*(int **)(param_1 + 0x144),0);
    *(undefined1 *)(param_1 + 0x3c) = 1;
    EnterCriticalSection(param_1 + 0x24);
    LeaveCriticalSection(param_1 + 0x24);
    iVar1 = *(int *)(param_1 + 0x564);
    if (iVar1 == 0) {
      func_0x0076b900(0);
    }
    else if (iVar1 == 1) {
      func_0x0076b5d0(0);
    }
    else if (iVar1 == 2) {
      func_0x0076c3e0(0);
    }
    iVar1 = *(int *)(param_1 + 0x150);
    iVar3 = 0;
    if (0 < iVar1) {
      puVar2 = (undefined4 *)(param_1 + 0x164);
      do {
        ResetEvent(*puVar2);
        iVar1 = *(int *)(param_1 + 0x150);
        iVar3 = iVar3 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar3 < iVar1);
    }
    *(undefined4 *)(param_1 + 0x158) = 0;
    *(undefined4 *)(param_1 + 0x154) = 0;
    *(undefined4 *)(param_1 + 0x598) = 0;
    *(undefined4 *)(param_1 + 0x584) = 0;
    *(undefined4 *)(param_1 + 0x578) = 0;
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


/* ==================================================================== */
/* Address: 0x0076a030 | Classified: elementclient::AMSoundStream__FillBuffer____Loc@0x76a030 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0076a030(int param_1,int param_2)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 unaff_ESI;
  undefined1 *puVar6;
  undefined1 *puStack_30;
  undefined4 *puStack_2c;
  undefined1 *puStack_28;
  undefined4 uStack_24;
  undefined4 auStack_14 [3];
  undefined1 auStack_8 [4];
  undefined1 auStack_4 [4];
  
  puStack_28 = auStack_4;
  uStack_24 = 0;
  puVar6 = *(undefined1 **)(param_1 + 0x15c);
  puStack_30 = auStack_8;
  puStack_2c = (undefined4 *)0x0;
  iVar3 = (**(code **)(**(int **)(param_1 + 0x144) + 0x2c))
                    (*(int **)(param_1 + 0x144),(int)puVar6 * param_2,puVar6);
  if (iVar3 < 0) {
    if (_DAT_009d2c04 != 0) {
      func_0x007647d0(_DAT_009d2c04,0x986708);
      return 0;
    }
  }
  else if (puStack_28 < puVar6) {
    if (_DAT_009d2c04 != 0) {
      func_0x007647d0(_DAT_009d2c04,0x9866d8);
      return 0;
    }
  }
  else {
    pcVar1 = (char *)(param_1 + 0x160);
    puVar5 = auStack_14;
    if ((*(char *)(param_1 + 0x160) == '\0') || (*(char *)(param_1 + 0x57c) != '\0')) {
      while( true ) {
        iVar3 = *(int *)(param_1 + 0x564);
        puStack_2c = puVar5;
        if (iVar3 == 0) {
          cVar2 = func_0x0076b960(puVar5,puVar6,&puStack_30,pcVar1);
          if (cVar2 == '\0') {
            if (_DAT_009d2c04 == 0) {
              return 0;
            }
            func_0x007647d0(_DAT_009d2c04,0x9866a0);
            return 0;
          }
        }
        else if (iVar3 == 1) {
          cVar2 = func_0x0076b610(puVar5,puVar6,&puStack_30,pcVar1);
          if (cVar2 == '\0') {
            if (_DAT_009d2c04 == 0) {
              return 0;
            }
            func_0x007647d0(_DAT_009d2c04,0x986668);
            return 0;
          }
        }
        else if ((iVar3 == 2) &&
                (cVar2 = func_0x0076c430(puVar5,puVar6,&puStack_30,pcVar1), cVar2 == '\0')) {
          if (_DAT_009d2c04 == 0) {
            return 0;
          }
          func_0x007647d0(_DAT_009d2c04,0x9865b0);
          return 0;
        }
        if (*pcVar1 == '\0') goto LAB_0076a2f1;
        if (*(char *)(param_1 + 0x57c) == '\0') break;
        iVar3 = *(int *)(param_1 + 0x564);
        if (iVar3 == 0) {
          cVar2 = func_0x0076b900(0);
          if (cVar2 == '\0') {
            FUN_00769f10();
            if (_DAT_009d2c04 == 0) {
              return 0;
            }
            func_0x007647d0(_DAT_009d2c04,0x986628);
            return 0;
          }
        }
        else if (iVar3 == 1) {
          cVar2 = func_0x0076b5d0(0);
          if (cVar2 == '\0') {
            FUN_00769f10();
            if (_DAT_009d2c04 == 0) {
              return 0;
            }
            func_0x007647d0(_DAT_009d2c04,0x9865e8);
            return 0;
          }
        }
        else if ((iVar3 == 2) && (cVar2 = func_0x0076c3e0(0), cVar2 == '\0')) {
          FUN_00769f10();
          if (_DAT_009d2c04 == 0) {
            return 0;
          }
          func_0x007647d0(_DAT_009d2c04,0x986570);
          return 0;
        }
        if (puVar6 <= puStack_30) goto LAB_0076a2f1;
        puVar6 = puVar6 + -(int)puStack_30;
        puVar5 = (undefined4 *)((int)puStack_2c + (int)puStack_30);
      }
      if (puStack_30 < puVar6) {
        puVar5 = (undefined4 *)((int)auStack_14 + (int)puStack_30);
        for (uVar4 = (uint)((int)puVar6 - (int)puStack_30) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar5 = 0;
          puVar5 = puVar5 + 1;
        }
        for (uVar4 = (int)puVar6 - (int)puStack_30 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)puVar5 = 0;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
        }
      }
LAB_0076a2f1:
      *(int *)(param_1 + 0x158) = *(int *)(param_1 + 0x158) + 1;
      if (*(char *)(param_1 + 0x59c) != '\0') {
        FUN_0076ad90(unaff_ESI,auStack_14);
      }
    }
    else {
      for (uVar4 = (uint)puVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
      for (uVar4 = (uint)puVar6 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar5 = 0;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
    }
    iVar3 = (**(code **)(**(int **)(param_1 + 0x144) + 0x4c))
                      (*(int **)(param_1 + 0x144),auStack_14,puStack_28,0,0);
    if (-1 < iVar3) {
      return 1;
    }
    if (_DAT_009d2c04 != 0) {
      func_0x007647d0(_DAT_009d2c04,0x986538);
    }
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x0076a370 | Classified: elementclient::AMSoundStream__HandleNotifyMessa@0x76a370 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0076a370(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint unaff_EDI;
  uint uVar5;
  undefined4 uStack_20;
  uint uStack_1c;
  
  uStack_1c = 0;
  iVar4 = *(int *)(param_1 + 0x154) % *(int *)(param_1 + 0x150);
  uStack_20 = *(undefined4 *)(param_1 + 0x164);
  iVar2 = WaitForSingleObject();
  if (iVar2 != 0x102) {
    iVar2 = *(int *)(param_1 + 0x15c);
    uVar5 = iVar2 * iVar4;
    iVar3 = (**(code **)(**(int **)(param_1 + 0x144) + 0x10))
                      (*(int **)(param_1 + 0x144),&stack0xfffffff4,&stack0xfffffff0);
    while (iVar3 == 0) {
      if (uStack_1c < unaff_EDI) {
        uStack_1c = uStack_1c + *(int *)(param_1 + 0x15c) * *(int *)(param_1 + 0x150);
      }
      if ((uStack_1c <= uVar5) || (iVar2 + uVar5 <= unaff_EDI)) break;
      Sleep(*(int *)(param_1 + 0x14c) >> 1);
      iVar3 = (**(code **)(**(int **)(param_1 + 0x144) + 0x10))
                        (*(int **)(param_1 + 0x144),&uStack_1c,&uStack_20);
    }
    *(int *)(param_1 + 0x154) = *(int *)(param_1 + 0x154) + 1;
    *(int *)(param_1 + 0x598) = *(int *)(param_1 + 0x598) + *(int *)(param_1 + 0x15c);
    ResetEvent(*(undefined4 *)(param_1 + 0x164));
    iVar2 = *(int *)(param_1 + 0x158) + -1;
    *(int *)(param_1 + 0x158) = iVar2;
    if (iVar2 == 0) {
      (**(code **)(**(int **)(param_1 + 0x144) + 0x48))(*(int **)(param_1 + 0x144));
      (**(code **)(**(int **)(param_1 + 0x144) + 0x34))(*(int **)(param_1 + 0x144),0);
      iVar2 = *(int *)(param_1 + 0x564);
      if (iVar2 == 0) {
        func_0x0076b900(0);
      }
      else if (iVar2 == 1) {
        func_0x0076b5d0(0);
      }
      else if (iVar2 == 2) {
        func_0x0076c3e0(0);
      }
      iVar2 = 0;
      if (0 < *(int *)(param_1 + 0x150)) {
        do {
          ResetEvent(*(undefined4 *)(param_1 + 0x164));
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(param_1 + 0x150));
      }
      *(undefined4 *)(param_1 + 0x158) = 0;
      *(undefined4 *)(param_1 + 0x154) = 0;
      *(undefined4 *)(param_1 + 0x598) = 0;
      *(undefined4 *)(param_1 + 0x578) = 3;
      return 0;
    }
    cVar1 = FUN_0076a030(iVar4);
    if (cVar1 == '\0') {
      if (_DAT_009d2c04 != 0) {
        func_0x007647d0(_DAT_009d2c04,0x986740);
      }
      return 0;
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0076a540 | Classified: elementclient::AMSoundStream__LoadStreamFromFil@0x76a540 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0076a540(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_110 [260];
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &UNK_008cbe64;
  *unaff_FS_OFFSET = &uStack_c;
  strncpy(param_1 + 0x3e,param_2,0x104);
  if (*(int *)(*(int *)(param_1 + 4) + 8) == 0) {
LAB_0076a9d6:
    uVar5 = 1;
    goto LAB_0076a9d8;
  }
  strncpy(auStack_110,param_2,0x104);
  _strlwr(auStack_110);
  iVar3 = strstr(auStack_110,0x951a70);
  if (iVar3 == 0) {
    iVar3 = strstr(auStack_110,0x9860b0);
    if (iVar3 != 0) {
      *(undefined4 *)(param_1 + 0x564) = 1;
      iVar3 = func_0x00763250(0x124);
      uStack_4 = 4;
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = func_0x0076b4f0();
      }
      uStack_4 = 0xffffffff;
      *(int *)(param_1 + 0x56c) = iVar3;
      if (iVar3 != 0) {
        cVar2 = func_0x0076b530(param_2);
        if (cVar2 != '\0') {
          iVar3 = *(int *)(param_1 + 0x56c);
LAB_0076a97a:
          *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar3 + 4);
          *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar3 + 8);
          *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar3 + 0xc);
          *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iVar3 + 0x10);
          *(undefined2 *)(param_1 + 0x18) = *(undefined2 *)(iVar3 + 0x14);
          *(undefined4 *)(param_1 + 0x590) = *(undefined4 *)(iVar3 + 0x18);
          *(undefined4 *)(param_1 + 0x594) = *(undefined4 *)(iVar3 + 0x1c);
          goto LAB_0076a9b0;
        }
        if (*(undefined4 **)(param_1 + 0x56c) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(param_1 + 0x56c))(1);
        }
        *(undefined4 *)(param_1 + 0x56c) = 0;
        if (_DAT_009d2c04 != 0) {
          func_0x007647d0(_DAT_009d2c04,0x986838,param_2);
          uVar5 = 0;
          goto LAB_0076a9d8;
        }
        goto LAB_0076a970;
      }
      goto LAB_0076a909;
    }
    iVar3 = strstr(auStack_110,0x976940);
    if (iVar3 != 0) {
      *(undefined4 *)(param_1 + 0x564) = 2;
      iVar3 = func_0x00763250(0x130);
      uStack_4 = 5;
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = func_0x0076bfb0();
      }
      uStack_4 = 0xffffffff;
      *(int *)(param_1 + 0x570) = iVar3;
      if (iVar3 != 0) {
        cVar2 = func_0x0076c0f0(param_2);
        if (cVar2 != '\0') {
          iVar3 = *(int *)(param_1 + 0x570);
          goto LAB_0076a97a;
        }
        func_0x0076c330();
        if (*(undefined4 **)(param_1 + 0x570) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(param_1 + 0x570))(1);
        }
        *(undefined4 *)(param_1 + 0x570) = 0;
        if (_DAT_009d2c04 != 0) {
          func_0x007647d0(_DAT_009d2c04,0x9867b8,param_2);
        }
        goto LAB_0076a970;
      }
      goto LAB_0076a909;
    }
LAB_0076a9b0:
    cVar2 = FUN_0076aa00();
    if (cVar2 != '\0') goto LAB_0076a9d6;
    if (_DAT_009d2c04 != 0) {
      func_0x007647d0(_DAT_009d2c04,0x986778);
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x564) = 0;
    iVar3 = _access(param_2,0);
    if (iVar3 == 0) {
      iVar3 = func_0x00763250(0x21c);
      uStack_4 = 0;
      if (iVar3 == 0) goto LAB_0076a65b;
      piVar4 = (int *)func_0x0076e410();
    }
    else {
      cVar2 = func_0x00773a80(param_2);
      if (cVar2 == '\0') {
        iVar3 = func_0x00763250(0x230);
        uStack_4 = 2;
        if (iVar3 == 0) goto LAB_0076a65b;
        piVar4 = (int *)func_0x0076d760();
      }
      else {
        iVar3 = func_0x00763250(0x220);
        uStack_4 = 1;
        if (iVar3 == 0) {
LAB_0076a65b:
          piVar4 = (int *)0x0;
        }
        else {
          piVar4 = (int *)func_0x00773760();
        }
      }
    }
    uStack_4 = 0xffffffff;
    *(int **)(param_1 + 0x574) = piVar4;
    if (piVar4 != (int *)0x0) {
      cVar2 = (**(code **)(*piVar4 + 8))(param_2,1);
      if (cVar2 == '\0') {
        (**(code **)(**(int **)(param_1 + 0x574) + 0xc))();
        if (*(undefined4 **)(param_1 + 0x574) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(param_1 + 0x574))(1);
        }
        *(undefined4 *)(param_1 + 0x574) = 0;
        if (_DAT_009d2c04 != 0) {
          func_0x007647d0(_DAT_009d2c04,0x9868c8,param_2);
          uVar5 = 0;
          goto LAB_0076a9d8;
        }
      }
      else {
        iVar3 = func_0x00763250(0x154);
        uStack_c = 3;
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = func_0x0076b700();
        }
        uStack_c = 0xffffffff;
        *(int *)(param_1 + 0x568) = iVar3;
        if (iVar3 == 0) {
          (**(code **)(**(int **)(param_1 + 0x574) + 0xc))();
          if (*(undefined4 **)(param_1 + 0x574) != (undefined4 *)0x0) {
            (**(code **)**(undefined4 **)(param_1 + 0x574))(1);
          }
          *(undefined4 *)(param_1 + 0x574) = 0;
          goto LAB_0076a909;
        }
        cVar2 = func_0x0076b720(*(int **)(param_1 + 0x574));
        if (cVar2 != '\0') {
          puVar1 = *(undefined4 **)(param_1 + 0x568);
          *(undefined4 *)(param_1 + 8) = puVar1[5];
          *(undefined4 *)(param_1 + 0xc) = puVar1[6];
          *(undefined4 *)(param_1 + 0x10) = puVar1[7];
          *(undefined4 *)(param_1 + 0x14) = puVar1[8];
          *(undefined2 *)(param_1 + 0x18) = *(undefined2 *)(puVar1 + 9);
          *(undefined4 *)(param_1 + 0x590) = *puVar1;
          *(undefined4 *)(param_1 + 0x594) = puVar1[3];
          goto LAB_0076a9b0;
        }
        (**(code **)(**(int **)(param_1 + 0x574) + 0xc))();
        if (*(undefined4 **)(param_1 + 0x574) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(param_1 + 0x574))(1);
        }
        *(undefined4 *)(param_1 + 0x574) = 0;
        func_0x0076b8f0();
        iVar3 = *(int *)(param_1 + 0x568);
        if (iVar3 != 0) {
          func_0x00430860();
          func_0x00763260(iVar3);
        }
        *(undefined4 *)(param_1 + 0x568) = 0;
        if (_DAT_009d2c04 != 0) {
          func_0x007647d0(_DAT_009d2c04,0x986880,param_2);
          uVar5 = 0;
          goto LAB_0076a9d8;
        }
      }
LAB_0076a970:
      uVar5 = 0;
      goto LAB_0076a9d8;
    }
LAB_0076a909:
    if (_DAT_009d2c04 != 0) {
      func_0x007647d0(_DAT_009d2c04,0x986800);
      uVar5 = 0;
      goto LAB_0076a9d8;
    }
  }
  uVar5 = 0;
LAB_0076a9d8:
  *unaff_FS_OFFSET = uStack_c;
  return uVar5;
}


/* ==================================================================== */
/* Address: 0x0076aa00 | Classified: elementclient::AMSoundStream__CreateStreamBuffe@0x76aa00 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0076aa00(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int aiStack_824 [521];
  
  iVar2 = *(int *)(param_1 + 0x14c);
  iVar6 = *(int *)(param_1 + 0x10);
  piVar5 = aiStack_824;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar5 = 0;
    piVar5 = piVar5 + 1;
  }
  aiStack_824[0] = 0x24;
  uVar4 = (uint)(iVar2 * iVar6) / 1000;
  *(uint *)(param_1 + 0x15c) = uVar4;
  aiStack_824[1] = 0x101a8;
  if (*(char *)(*(int *)(*(int *)(param_1 + 4) + 0xc) + 0x20) != '\0') {
    aiStack_824[1] = 0x181a8;
  }
  aiStack_824[2] = *(int *)(param_1 + 0x150) * uVar4;
  aiStack_824[4] = param_1 + 8;
  piVar5 = *(int **)(*(int *)(param_1 + 4) + 8);
  iVar2 = (**(code **)(*piVar5 + 0xc))(piVar5,aiStack_824,(undefined4 *)(param_1 + 0x144),0);
  if (iVar2 == 0) {
    puVar1 = *(undefined4 **)(param_1 + 0x144);
    iVar2 = (**(code **)*puVar1)(puVar1,&UNK_008f5350,(undefined4 *)(param_1 + 0x148));
    if (iVar2 == 0) {
      if (0 < *(int *)(param_1 + 0x150)) {
        iVar2 = *(int *)(param_1 + 0x164);
        iVar6 = 0;
        do {
          ResetEvent(iVar2);
          iVar3 = iVar6 + 1;
          iVar2 = *(int *)(param_1 + 0x164);
          aiStack_824[iVar6 * 2 + 2] = *(int *)(param_1 + 0x15c) * iVar3 + -1;
          aiStack_824[iVar6 * 2 + 3] = iVar2;
          iVar6 = iVar3;
        } while (iVar3 < *(int *)(param_1 + 0x150));
      }
      piVar5 = *(int **)(param_1 + 0x148);
      iVar2 = (**(code **)(*piVar5 + 0xc))(piVar5,*(undefined4 *)(param_1 + 0x150),aiStack_824 + 2);
      if (iVar2 == 0) {
        *(undefined4 *)(param_1 + 0x578) = 0;
        *(undefined1 *)(param_1 + 0x3d) = 1;
        FUN_0076ad30(*(undefined4 *)(param_1 + 0x58c));
        return 1;
      }
      if (_DAT_009d2c04 != 0) {
        func_0x007647d0(_DAT_009d2c04,0x986908);
      }
    }
    else if (_DAT_009d2c04 != 0) {
      func_0x007647d0(_DAT_009d2c04,0x98694c);
      return 0;
    }
  }
  else if (_DAT_009d2c04 != 0) {
    func_0x007647d0(_DAT_009d2c04,0x986988);
    return 0;
  }
  return 0;
}


/* ==================================================================== */
/* Address: 0x0076aba0 | Classified: AngelicaFile::proc_76aba0 */
/* ==================================================================== */

undefined4 __fastcall FUN_0076aba0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  FUN_00769f10();
  if (*(int *)(param_1 + 0x568) != 0) {
    func_0x0076b8f0();
    iVar1 = *(int *)(param_1 + 0x568);
    if (iVar1 != 0) {
      func_0x00430860();
      func_0x00763260(iVar1);
    }
    *(undefined4 *)(param_1 + 0x568) = 0;
  }
  if (*(int **)(param_1 + 0x574) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x574) + 0xc))();
    if (*(undefined4 **)(param_1 + 0x574) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x574))(1);
    }
    *(undefined4 *)(param_1 + 0x574) = 0;
  }
  if (*(int *)(param_1 + 0x56c) != 0) {
    func_0x0076b5a0();
    if (*(undefined4 **)(param_1 + 0x56c) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x56c))(1);
    }
    *(undefined4 *)(param_1 + 0x56c) = 0;
  }
  if (*(int *)(param_1 + 0x570) != 0) {
    func_0x0076c330();
    if (*(undefined4 **)(param_1 + 0x570) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x570))(1);
    }
    *(undefined4 *)(param_1 + 0x570) = 0;
  }
  piVar2 = *(int **)(param_1 + 0x148);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    *(undefined4 *)(param_1 + 0x148) = 0;
  }
  piVar2 = *(int **)(param_1 + 0x144);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x48))(piVar2);
    (**(code **)(**(int **)(param_1 + 0x144) + 8))(*(int **)(param_1 + 0x144));
    *(undefined4 *)(param_1 + 0x144) = 0;
  }
  *(undefined4 *)(param_1 + 0x564) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x578) = 0;
  *(undefined1 *)(param_1 + 0x3d) = 0;
  return 1;
}


/* ==================================================================== */
/* Address: 0x0076aca0 | Classified: elementclient::AMSoundStream__Tick___Replay_the@0x76aca0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0076aca0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x578) == 3) {
    if (*(char *)(param_1 + 0x57c) == '\0') {
      if (*(char *)(param_1 + 0x3d) != '\0') {
        (**(code **)(**(int **)(param_1 + 0x144) + 0x48))(*(int **)(param_1 + 0x144));
        (**(code **)(**(int **)(param_1 + 0x144) + 0x34))(*(int **)(param_1 + 0x144),0);
        *(undefined1 *)(param_1 + 0x3c) = 1;
        EnterCriticalSection(param_1 + 0x24);
        LeaveCriticalSection(param_1 + 0x24);
        iVar4 = *(int *)(param_1 + 0x564);
        if (iVar4 == 0) {
          func_0x0076b900(0);
        }
        else if (iVar4 == 1) {
          func_0x0076b5d0(0);
        }
        else if (iVar4 == 2) {
          func_0x0076c3e0(0);
        }
        iVar4 = 0;
        if (0 < *(int *)(param_1 + 0x150)) {
          puVar3 = (undefined4 *)(param_1 + 0x164);
          do {
            ResetEvent(*puVar3);
            iVar4 = iVar4 + 1;
            puVar3 = puVar3 + 1;
          } while (iVar4 < *(int *)(param_1 + 0x150));
        }
        *(undefined4 *)(param_1 + 0x158) = 0;
        *(undefined4 *)(param_1 + 0x154) = 0;
        *(undefined4 *)(param_1 + 0x598) = 0;
        *(undefined4 *)(param_1 + 0x584) = 0;
        *(undefined4 *)(param_1 + 0x578) = 0;
      }
      return 1;
    }
  }
  else if (*(int *)(param_1 + 0x578) == 4) {
    iVar4 = GetTickCount();
    *(int *)(param_1 + 0x584) = *(int *)(param_1 + 0x584) + (*(int *)(param_1 + 0x588) - iVar4);
    uVar2 = GetTickCount();
    *(undefined4 *)(param_1 + 0x588) = uVar2;
    if ((*(int *)(param_1 + 0x584) < 1) && (cVar1 = FUN_00769d70(0), cVar1 == '\0')) {
      if (_DAT_009d2c04 != 0) {
        func_0x007647d0(_DAT_009d2c04,0x9869c8);
      }
      return 0;
    }
  }
  return 1;
}


/* ==================================================================== */
/* Address: 0x0076ad30 | Classified: AngelicaFile::proc_76ad30 */
/* ==================================================================== */

void __thiscall FUN_0076ad30(int param_1,int param_2)

{
  int *piVar1;
  
  *(int *)(param_1 + 0x58c) = param_2;
  piVar1 = *(int **)(param_1 + 0x144);
  if (piVar1 != (int *)0x0) {
    if (param_2 == 0) {
      (**(code **)(*piVar1 + 0x3c))(piVar1,0xffffd8f0);
      return;
    }
    (**(code **)(*piVar1 + 0x3c))(piVar1,(uint)(param_2 * 3000) / 100 - 3000);
  }
  return;
}


/* ==================================================================== */
/* Address: 0x0076ad90 | Classified: AngelicaFile::proc_76ad90 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __thiscall FUN_0076ad90(int param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  short *psVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined4 *puVar11;
  uint uVar12;
  bool bVar13;
  bool bVar14;
  uint uStack_20;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  
  fVar1 = _DAT_008effc4;
  bVar13 = *(short *)(param_1 + 10) == 2;
  bVar14 = *(short *)(param_1 + 0x16) == 8;
  uVar7 = (uint)(*(int *)(param_1 + 0x14c) * *(int *)(param_1 + 0xc)) / 1000;
  iStack_10 = 0;
  if ((int)uVar7 < *(int *)(param_1 + 0x5a0)) {
    iStack_10 = *(int *)(param_1 + 0x5a0) - uVar7;
    puVar9 = *(undefined4 **)(param_1 + 0x5a4) + uVar7;
    puVar11 = *(undefined4 **)(param_1 + 0x5a4);
    for (iVar6 = iStack_10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar11 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar11 = puVar11 + 1;
    }
  }
  iVar6 = 0;
  iStack_c = 0;
  fVar3 = fVar1;
  if (uVar7 != 0) {
    iStack_14 = iStack_10 * 4;
    psVar8 = (short *)(param_3 + 2);
    do {
      if (bVar14) {
        if (bVar13) {
          uVar12 = (uint)*(byte *)(iVar6 + param_3);
          uVar10 = (uint)*(byte *)(iVar6 + 1 + param_3);
          goto LAB_0076ae53;
        }
        uVar10 = (uint)*(byte *)(iVar6 + param_3);
LAB_0076ae79:
        iVar6 = iVar6 + 1;
        psVar8 = psVar8 + 1;
        uVar12 = uVar10;
        uStack_20 = uVar10;
      }
      else {
        if (!bVar13) {
          uVar10 = (uint)*(short *)(param_3 + iVar6 * 2);
          goto LAB_0076ae79;
        }
        uVar12 = (uint)*(short *)(param_3 + iVar6 * 2);
        uVar10 = (uint)*psVar8;
LAB_0076ae53:
        iVar6 = iVar6 + 2;
        psVar8 = psVar8 + 2;
        uStack_20 = (int)uVar10 / 2 + (int)uVar12 / 2;
      }
      if (iStack_c + iStack_10 < *(int *)(param_1 + 0x5a0)) {
        if (bVar14) {
          *(float *)(iStack_14 + *(int *)(param_1 + 0x5a4)) =
               ((float)(int)uStack_20 - _DAT_008f01cc) * _DAT_008f01c8;
          fVar4 = ABS((float)(int)(uVar12 - 0x80)) * (float)_DAT_008f01c0;
          fVar2 = ABS((float)(int)(uVar10 - 0x80)) * (float)_DAT_008f01c0;
        }
        else {
          *(float *)(iStack_14 + *(int *)(param_1 + 0x5a4)) = (float)(int)uStack_20 * _DAT_008f01d8;
          fVar4 = ABS((float)(int)uVar12) * (float)_DAT_008f01d0;
          fVar2 = ABS((float)(int)uVar10) * (float)_DAT_008f01d0;
        }
        fVar1 = fVar4 + fVar1;
        fVar3 = fVar2 + fVar3;
      }
      iStack_c = iStack_c + 1;
      iStack_14 = iStack_14 + 4;
    } while (iStack_c < (int)uVar7);
  }
  fVar2 = _DAT_008effa0 / (float)uVar7;
  *(float *)(param_1 + 0x9a8 + param_2 * 4) = fVar2 * fVar1;
  *(float *)(param_1 + 0xda8 + param_2 * 4) = fVar2 * fVar3;
  cVar5 = func_0x0076bf00(*(undefined4 *)(param_1 + 0x5a4),*(undefined4 *)(param_1 + 0x5a0));
  if (cVar5 == '\0') {
    return false;
  }
  cVar5 = func_0x0076bd60();
  if (cVar5 == '\0') {
    return false;
  }
  cVar5 = func_0x0076bf40(*(undefined4 *)(param_1 + 0x5a8 + param_2 * 4),
                          *(undefined4 *)(param_1 + 0x5a0));
  return cVar5 != '\0';
}


/* ==================================================================== */
/* Address: 0x0076afd0 | Classified: elementclient::Configs_angelica_cfg@0x76afd0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_0076afd0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &UNK_008cbe7b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1[4] = &UNK_008d7440;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0x10;
  *param_1 = &UNK_008f01dc;
  uStack_4 = 0;
  if (_DAT_00986a1c == -1) {
    _DAT_00986a1c = 0;
  }
  *(undefined1 *)(param_1 + 1) = 1;
  param_1[2] = 0;
  param_1[3] = 100;
  param_1[9] = 0x40;
  param_1[10] = 0x3e800;
  param_1[0xb] = 0xa00000;
  func_0x0076b0c0(0x986ac8);
  *unaff_FS_OFFSET = param_1;
  return param_1;
}


