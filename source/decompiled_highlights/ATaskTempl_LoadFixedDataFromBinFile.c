// rea decompile_all
// name: FUN_00683ce0
// address: 0x683ce0
// body: available
// range: 0x683ce0-0x6857ac inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e1ad533d4cc0333c2136fe0894217de2d61feea098240326e78633f9e4ddcbf9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00683ce0(FILE *param_1)

{
  ushort uVar1;
  int iVar2;
  void *pvVar3;
  FILE *_File;
  undefined4 *puVar4;
  undefined4 uVar5;
  ushort *puVar6;
  int *piVar7;
  uint *puVar8;
  ushort *in_ECX;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  uint *puVar12;
  int local_20;
  int local_1c;
  uint local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  _File = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_008c2397;
  local_c = ExceptionList;
  iVar9 = *(int *)((int)in_ECX + 0x339);
  ExceptionList = &local_c;
  if (iVar9 != 0) {
    ExceptionList = &local_c;
    FUN_0042ce40();
    thunk_FUN_007631b0(iVar9);
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  iVar9 = *(int *)((int)in_ECX + 0x33d);
  if (iVar9 != 0) {
    FUN_0042ce40();
    thunk_FUN_007631b0(iVar9);
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  iVar9 = *(int *)((int)in_ECX + 0x341);
  if (iVar9 != 0) {
    iVar2 = *(int *)(iVar9 + 0x18);
    if (iVar2 != 0) {
      FUN_00892d40(iVar2,0xbb,*(undefined4 *)(iVar2 + -4),FUN_0042ce40);
      thunk_FUN_007631b0(iVar2 + -4);
      DAT_009bf3cc = DAT_009bf3cc + 1;
    }
    thunk_FUN_007631b0(iVar9);
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  iVar9 = *(int *)((int)in_ECX + 0x345);
  if (iVar9 != 0) {
    iVar2 = *(int *)(iVar9 + 0x18);
    if (iVar2 != 0) {
      FUN_00892d40(iVar2,0xbb,*(undefined4 *)(iVar2 + -4),FUN_0042ce40);
      thunk_FUN_007631b0(iVar2 + -4);
      DAT_009bf3cc = DAT_009bf3cc + 1;
    }
    thunk_FUN_007631b0(iVar9);
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  iVar9 = *(int *)((int)in_ECX + 0x349);
  if (iVar9 != 0) {
    iVar2 = *(int *)(iVar9 + 0x1c);
    if (iVar2 != 0) {
      FUN_00892d40(iVar2,0xbb,*(undefined4 *)(iVar2 + -4),FUN_0042ce40);
      thunk_FUN_007631b0(iVar2 + -4);
      DAT_009bf3cc = DAT_009bf3cc + 1;
    }
    thunk_FUN_007631b0(iVar9);
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  iVar9 = *(int *)((int)in_ECX + 0x34d);
  if (iVar9 != 0) {
    iVar2 = *(int *)(iVar9 + 0x1c);
    if (iVar2 != 0) {
      FUN_00892d40(iVar2,0xbb,*(undefined4 *)(iVar2 + -4),FUN_0042ce40);
      thunk_FUN_007631b0(iVar2 + -4);
      DAT_009bf3cc = DAT_009bf3cc + 1;
    }
    thunk_FUN_007631b0(iVar9);
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  if (*(int *)((int)in_ECX + 0x85) != 0) {
    thunk_FUN_007631b0(*(int *)((int)in_ECX + 0x85));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  if (*(int *)((int)in_ECX + 0x89) != 0) {
    thunk_FUN_007631b0(*(int *)((int)in_ECX + 0x89));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  if (*(int *)(in_ECX + 0x93) != 0) {
    thunk_FUN_007631b0(*(int *)(in_ECX + 0x93));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  if (*(int *)(in_ECX + 0x95) != 0) {
    thunk_FUN_007631b0(*(int *)(in_ECX + 0x95));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  if (*(int *)(in_ECX + 0x97) != 0) {
    thunk_FUN_007631b0(*(int *)(in_ECX + 0x97));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  if (*(int *)((int)in_ECX + 0x15d) != 0) {
    thunk_FUN_007631b0(*(int *)((int)in_ECX + 0x15d));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  if (*(int *)(in_ECX + 0xb7) != 0) {
    thunk_FUN_007631b0(*(int *)(in_ECX + 0xb7));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  if (*(int *)(in_ECX + 299) != 0) {
    thunk_FUN_007631b0(*(int *)(in_ECX + 299));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  if (*(int *)(in_ECX + 0x14e) != 0) {
    thunk_FUN_007631b0(*(int *)(in_ECX + 0x14e));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  if (*(int *)(in_ECX + 0x14a) != 0) {
    thunk_FUN_007631b0(*(int *)(in_ECX + 0x14a));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  if (*(int *)((int)in_ECX + 0x41) != 0) {
    thunk_FUN_007631b0(*(int *)((int)in_ECX + 0x41));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  if (*(int *)((int)in_ECX + 0x321) != 0) {
    thunk_FUN_007631b0(*(int *)((int)in_ECX + 0x321));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  if (*(int *)((int)in_ECX + 0x325) != 0) {
    thunk_FUN_007631b0(*(int *)((int)in_ECX + 0x325));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  if (*(int *)((int)in_ECX + 0x32d) != 0) {
    thunk_FUN_007631b0(*(int *)((int)in_ECX + 0x32d));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  if (*(int *)((int)in_ECX + 0x139) != 0) {
    thunk_FUN_007631b0(*(int *)((int)in_ECX + 0x139));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  if (*(int *)((int)in_ECX + 0x13d) != 0) {
    thunk_FUN_007631b0(*(int *)((int)in_ECX + 0x13d));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  if (*(int *)((int)in_ECX + 0x147) != 0) {
    thunk_FUN_007631b0(*(int *)((int)in_ECX + 0x147));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  fread(in_ECX,0x361,1,param_1);
  uVar1 = *in_ECX;
  puVar6 = in_ECX + 2;
  iVar9 = 0x1e;
  do {
    *puVar6 = *puVar6 ^ uVar1;
    puVar6 = puVar6 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  puVar4 = (undefined4 *)thunk_FUN_007631a0(0xbb);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar10 = puVar4;
    for (iVar9 = 0x2e; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined2 *)puVar10 = 0;
    *(undefined1 *)((int)puVar10 + 2) = 0;
  }
  *(undefined4 **)((int)in_ECX + 0x339) = puVar4;
  DAT_009bf3c8 = DAT_009bf3c8 + 1;
  puVar4 = (undefined4 *)thunk_FUN_007631a0(0xbb);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar10 = puVar4;
    for (iVar9 = 0x2e; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined2 *)puVar10 = 0;
    *(undefined1 *)((int)puVar10 + 2) = 0;
  }
  *(undefined4 **)((int)in_ECX + 0x33d) = puVar4;
  DAT_009bf3c8 = DAT_009bf3c8 + 1;
  puVar4 = (undefined4 *)thunk_FUN_007631a0(0x1c);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar10 = puVar4;
    for (iVar9 = 7; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
  }
  *(undefined4 **)((int)in_ECX + 0x341) = puVar4;
  DAT_009bf3c8 = DAT_009bf3c8 + 1;
  puVar4 = (undefined4 *)thunk_FUN_007631a0(0x1c);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar10 = puVar4;
    for (iVar9 = 7; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
  }
  *(undefined4 **)((int)in_ECX + 0x345) = puVar4;
  DAT_009bf3c8 = DAT_009bf3c8 + 1;
  puVar4 = (undefined4 *)thunk_FUN_007631a0(0x20);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar10 = puVar4;
    for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
  }
  *(undefined4 **)((int)in_ECX + 0x349) = puVar4;
  DAT_009bf3c8 = DAT_009bf3c8 + 1;
  puVar4 = (undefined4 *)thunk_FUN_007631a0(0x20);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar10 = puVar4;
    for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
  }
  *(undefined4 **)((int)in_ECX + 0x34d) = puVar4;
  DAT_009bf3c8 = DAT_009bf3c8 + 1;
  *(undefined4 *)((int)in_ECX + 0x85) = 0;
  *(undefined4 *)((int)in_ECX + 0x89) = 0;
  in_ECX[0x93] = 0;
  in_ECX[0x94] = 0;
  in_ECX[0x95] = 0;
  in_ECX[0x96] = 0;
  in_ECX[0x97] = 0;
  in_ECX[0x98] = 0;
  *(undefined4 *)((int)in_ECX + 0x15d) = 0;
  in_ECX[0xb7] = 0;
  in_ECX[0xb8] = 0;
  in_ECX[299] = 0;
  in_ECX[300] = 0;
  in_ECX[0x14e] = 0;
  in_ECX[0x14f] = 0;
  in_ECX[0x14a] = 0;
  in_ECX[0x14b] = 0;
  *(undefined4 *)((int)in_ECX + 0x41) = 0;
  *(undefined4 *)((int)in_ECX + 0x321) = 0;
  *(undefined4 *)((int)in_ECX + 0x325) = 0;
  *(undefined4 *)((int)in_ECX + 0x32d) = 0;
  *(undefined4 *)((int)in_ECX + 0x139) = 0;
  *(undefined4 *)((int)in_ECX + 0x13d) = 0;
  *(undefined4 *)((int)in_ECX + 0x147) = 0;
  if ((char)in_ECX[0x20] != '\0') {
    uVar5 = thunk_FUN_007631a0(0x3c);
    *(undefined4 *)((int)in_ECX + 0x41) = uVar5;
    DAT_009bf3c8 = DAT_009bf3c8 + 1;
    fread(*(void **)((int)in_ECX + 0x41),2,0x1e,param_1);
    uVar1 = *in_ECX;
    puVar6 = *(ushort **)((int)in_ECX + 0x41);
    iVar9 = 0x1e;
    do {
      *puVar6 = *puVar6 ^ uVar1;
      puVar6 = puVar6 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  if (*(int *)((int)in_ECX + 0x69) != 0) {
    uVar5 = thunk_FUN_007631a0(*(int *)((int)in_ECX + 0x69) * 0x18);
    *(undefined4 *)((int)in_ECX + 0x85) = uVar5;
    DAT_009bf3c8 = DAT_009bf3c8 + 1;
    uVar5 = thunk_FUN_007631a0(*(int *)((int)in_ECX + 0x69) * 0x18);
    *(undefined4 *)((int)in_ECX + 0x89) = uVar5;
    DAT_009bf3c8 = DAT_009bf3c8 + 1;
  }
  iVar9 = 0;
  param_1 = (FILE *)0x0;
  if (*(int *)((int)in_ECX + 0x69) != 0) {
    do {
      fread((void *)(*(int *)((int)in_ECX + 0x85) + iVar9),0x18,1,_File);
      fread((void *)(*(int *)((int)in_ECX + 0x89) + iVar9),0x18,1,_File);
      param_1 = (FILE *)((int)param_1 + 1);
      iVar9 = iVar9 + 0x18;
    } while (param_1 < *(uint *)((int)in_ECX + 0x69));
  }
  if (*(int *)(in_ECX + 0x91) != 0) {
    uVar5 = thunk_FUN_007631a0(*(int *)(in_ECX + 0x91) * 4);
    *(undefined4 *)(in_ECX + 0x93) = uVar5;
    uVar5 = thunk_FUN_007631a0(*(int *)(in_ECX + 0x91) << 2);
    *(undefined4 *)(in_ECX + 0x95) = uVar5;
    uVar5 = thunk_FUN_007631a0(*(undefined4 *)(in_ECX + 0x91));
    *(undefined4 *)(in_ECX + 0x97) = uVar5;
  }
  uVar11 = 0;
  if (*(int *)(in_ECX + 0x91) != 0) {
    do {
      fread((void *)(*(int *)(in_ECX + 0x93) + uVar11 * 4),4,1,_File);
      fread((void *)(*(int *)(in_ECX + 0x95) + uVar11 * 4),4,1,_File);
      fread((void *)(*(int *)(in_ECX + 0x97) + uVar11),1,1,_File);
      uVar11 = uVar11 + 1;
    } while (uVar11 < *(uint *)(in_ECX + 0x91));
  }
  if (*(int *)((int)in_ECX + 0x135) != 0) {
    puVar4 = (undefined4 *)thunk_FUN_007631a0(*(int *)((int)in_ECX + 0x135) << 6);
    *(undefined4 **)((int)in_ECX + 0x139) = puVar4;
    for (iVar9 = (*(uint *)((int)in_ECX + 0x135) & 0x3ffffff) << 4; iVar9 != 0; iVar9 = iVar9 + -1)
    {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    puVar4 = (undefined4 *)thunk_FUN_007631a0(*(int *)((int)in_ECX + 0x135) << 9);
    *(undefined4 **)((int)in_ECX + 0x13d) = puVar4;
    for (iVar9 = (*(uint *)((int)in_ECX + 0x135) & 0x7fffff) << 7; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    uVar11 = 0;
    if (*(int *)((int)in_ECX + 0x135) != 0) {
      local_20 = 0;
      param_1 = (FILE *)0x0;
      do {
        fread((void *)(*(int *)((int)in_ECX + 0x139) + (int)param_1),1,0x40,_File);
        fread((void *)(*(int *)((int)in_ECX + 0x13d) + local_20),8,0x40,_File);
        uVar11 = uVar11 + 1;
        param_1 = (FILE *)((int)param_1 + 0x40);
        local_20 = local_20 + 0x200;
      } while (uVar11 < *(uint *)((int)in_ECX + 0x135));
    }
  }
  if (*(int *)((int)in_ECX + 0x143) != 0) {
    uVar5 = thunk_FUN_007631a0(*(int *)((int)in_ECX + 0x143) * 0xc);
    *(undefined4 *)((int)in_ECX + 0x147) = uVar5;
    DAT_009bf3c8 = DAT_009bf3c8 + 1;
  }
  uVar11 = 0;
  if (*(int *)((int)in_ECX + 0x143) != 0) {
    param_1 = (FILE *)0x0;
    do {
      fread((void *)(*(int *)((int)in_ECX + 0x147) + (int)param_1),0xc,1,_File);
      uVar11 = uVar11 + 1;
      param_1 = (FILE *)((int)param_1 + 0xc);
    } while (uVar11 < *(uint *)((int)in_ECX + 0x143));
  }
  if (*(int *)((int)in_ECX + 0x159) != 0) {
    uVar5 = thunk_FUN_007631a0(*(int *)((int)in_ECX + 0x159) * 0x11);
    *(undefined4 *)((int)in_ECX + 0x15d) = uVar5;
    DAT_009bf3c8 = DAT_009bf3c8 + 1;
  }
  uVar11 = 0;
  if (*(int *)((int)in_ECX + 0x159) != 0) {
    param_1 = (FILE *)0x0;
    do {
      fread((void *)(*(int *)((int)in_ECX + 0x15d) + (int)param_1),0x11,1,_File);
      uVar11 = uVar11 + 1;
      param_1 = (FILE *)((int)param_1 + 0x11);
    } while (uVar11 < *(uint *)((int)in_ECX + 0x159));
  }
  in_ECX[0xb3] = 0;
  in_ECX[0xb4] = 0;
  in_ECX[0xb5] = 0;
  in_ECX[0xb6] = 0;
  if (*(int *)(in_ECX + 0xb1) != 0) {
    uVar5 = thunk_FUN_007631a0(*(int *)(in_ECX + 0xb1) * 0x11);
    *(undefined4 *)(in_ECX + 0xb7) = uVar5;
    DAT_009bf3c8 = DAT_009bf3c8 + 1;
  }
  param_1 = (FILE *)0x0;
  if (*(int *)(in_ECX + 0xb1) != 0) {
    local_20 = 0;
    do {
      iVar9 = *(int *)(in_ECX + 0xb7);
      fread((void *)(iVar9 + local_20),0x11,1,_File);
      if (*(char *)(iVar9 + local_20 + 4) == '\0') {
        *(int *)(in_ECX + 0xb5) = *(int *)(in_ECX + 0xb5) + 1;
      }
      else {
        *(int *)(in_ECX + 0xb3) = *(int *)(in_ECX + 0xb3) + 1;
      }
      param_1 = (FILE *)((int)param_1 + 1);
      local_20 = local_20 + 0x11;
    } while (param_1 < *(uint *)(in_ECX + 0xb1));
  }
  if (*(char *)((int)in_ECX + 0x235) != '\0') {
    if (*(int *)(in_ECX + 0x129) != 0) {
      uVar5 = thunk_FUN_007631a0(*(int *)(in_ECX + 0x129) << 5);
      *(undefined4 *)(in_ECX + 299) = uVar5;
      DAT_009bf3c8 = DAT_009bf3c8 + 1;
    }
    uVar11 = 0;
    if (*(int *)(in_ECX + 0x129) != 0) {
      param_1 = (FILE *)0x0;
      do {
        fread((void *)(*(int *)(in_ECX + 299) + (int)param_1),0x20,1,_File);
        uVar11 = uVar11 + 1;
        param_1 = (FILE *)((int)param_1 + 0x20);
      } while (uVar11 < *(uint *)(in_ECX + 0x129));
    }
  }
  if (*(int *)(in_ECX + 0x148) != 0) {
    uVar5 = thunk_FUN_007631a0(*(int *)(in_ECX + 0x148) * 0x16);
    *(undefined4 *)(in_ECX + 0x14a) = uVar5;
    DAT_009bf3c8 = DAT_009bf3c8 + 1;
  }
  uVar11 = 0;
  if (*(int *)(in_ECX + 0x148) != 0) {
    param_1 = (FILE *)0x0;
    do {
      fread((void *)(*(int *)(in_ECX + 0x14a) + (int)param_1),0x16,1,_File);
      uVar11 = uVar11 + 1;
      param_1 = (FILE *)((int)param_1 + 0x16);
    } while (uVar11 < *(uint *)(in_ECX + 0x148));
  }
  if (*(int *)(in_ECX + 0x14c) != 0) {
    uVar5 = thunk_FUN_007631a0(*(int *)(in_ECX + 0x14c) * 0x11);
    *(undefined4 *)(in_ECX + 0x14e) = uVar5;
    DAT_009bf3c8 = DAT_009bf3c8 + 1;
  }
  uVar11 = 0;
  if (*(int *)(in_ECX + 0x14c) != 0) {
    param_1 = (FILE *)0x0;
    do {
      fread((void *)(*(int *)(in_ECX + 0x14e) + (int)param_1),0x11,1,_File);
      uVar11 = uVar11 + 1;
      param_1 = (FILE *)((int)param_1 + 0x11);
    } while (uVar11 < *(uint *)(in_ECX + 0x14c));
  }
  if (*(int *)((int)in_ECX + 0x31d) != 0) {
    puVar4 = (undefined4 *)thunk_FUN_007631a0(*(int *)((int)in_ECX + 0x31d) << 6);
    *(undefined4 **)((int)in_ECX + 0x321) = puVar4;
    for (iVar9 = (*(uint *)((int)in_ECX + 0x31d) & 0x3ffffff) << 4; iVar9 != 0; iVar9 = iVar9 + -1)
    {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    puVar4 = (undefined4 *)thunk_FUN_007631a0(*(int *)((int)in_ECX + 0x31d) << 9);
    *(undefined4 **)((int)in_ECX + 0x325) = puVar4;
    for (iVar9 = (*(uint *)((int)in_ECX + 0x31d) & 0x7fffff) << 7; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    uVar11 = 0;
    if (*(int *)((int)in_ECX + 0x31d) != 0) {
      local_20 = 0;
      param_1 = (FILE *)0x0;
      do {
        fread((void *)(*(int *)((int)in_ECX + 0x321) + (int)param_1),1,0x40,_File);
        fread((void *)(*(int *)((int)in_ECX + 0x325) + local_20),8,0x40,_File);
        uVar11 = uVar11 + 1;
        param_1 = (FILE *)((int)param_1 + 0x40);
        local_20 = local_20 + 0x200;
      } while (uVar11 < *(uint *)((int)in_ECX + 0x31d));
    }
  }
  if (*(int *)((int)in_ECX + 0x329) != 0) {
    puVar4 = (undefined4 *)thunk_FUN_007631a0(*(int *)((int)in_ECX + 0x329) << 7);
    *(undefined4 **)((int)in_ECX + 0x32d) = puVar4;
    for (iVar9 = (*(uint *)((int)in_ECX + 0x329) & 0x1ffffff) << 5; iVar9 != 0; iVar9 = iVar9 + -1)
    {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    uVar11 = 0;
    if (*(int *)((int)in_ECX + 0x329) != 0) {
      param_1 = (FILE *)0x0;
      do {
        fread((void *)(*(int *)((int)in_ECX + 0x32d) + (int)param_1),2,0x40,_File);
        uVar11 = uVar11 + 1;
        param_1 = (FILE *)((int)param_1 + 0x80);
      } while (uVar11 < *(uint *)((int)in_ECX + 0x329));
    }
  }
  uVar5 = DAT_00978974;
  pvVar3 = *(void **)((int)in_ECX + 0x339);
  iVar9 = *(int *)((int)pvVar3 + 0x58);
  if (iVar9 != 0) {
    FUN_00892d40(iVar9,0x11,*(undefined4 *)(iVar9 + -4),&LAB_0042ce20);
    thunk_FUN_007631b0(iVar9 + -4);
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  iVar9 = *(int *)((int)pvVar3 + 0x60);
  *(undefined4 *)((int)pvVar3 + 0x58) = 0;
  if (iVar9 != 0) {
    if (*(int *)(iVar9 + 10) != 0) {
      thunk_FUN_007631b0(*(int *)(iVar9 + 10));
      DAT_009bf3cc = DAT_009bf3cc + 1;
    }
    thunk_FUN_007631b0(iVar9);
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  iVar9 = *(int *)((int)pvVar3 + 0x82);
  *(undefined4 *)((int)pvVar3 + 0x60) = 0;
  if (iVar9 != 0) {
    FUN_006857b0();
    thunk_FUN_007631b0(iVar9);
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  *(undefined4 *)((int)pvVar3 + 0x82) = 0;
  if (*(int *)((int)pvVar3 + 0x8a) != 0) {
    thunk_FUN_007631b0(*(int *)((int)pvVar3 + 0x8a));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  *(undefined4 *)((int)pvVar3 + 0x8a) = 0;
  if (*(int *)((int)pvVar3 + 0x8e) != 0) {
    thunk_FUN_007631b0(*(int *)((int)pvVar3 + 0x8e));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  *(undefined4 *)((int)pvVar3 + 0x8e) = 0;
  if (*(int *)((int)pvVar3 + 0x92) != 0) {
    thunk_FUN_007631b0(*(int *)((int)pvVar3 + 0x92));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  *(undefined4 *)((int)pvVar3 + 0x92) = 0;
  if (*(int *)((int)pvVar3 + 0xa3) != 0) {
    thunk_FUN_007631b0(*(int *)((int)pvVar3 + 0xa3));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  *(undefined4 *)((int)pvVar3 + 0xa3) = 0;
  if (*(int *)((int)pvVar3 + 0xab) != 0) {
    thunk_FUN_007631b0(*(int *)((int)pvVar3 + 0xab));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  *(undefined4 *)((int)pvVar3 + 0xab) = 0;
  if (*(int *)((int)pvVar3 + 0xaf) != 0) {
    thunk_FUN_007631b0(*(int *)((int)pvVar3 + 0xaf));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  *(undefined4 *)((int)pvVar3 + 0xaf) = 0;
  if (*(int *)((int)pvVar3 + 0xb7) != 0) {
    thunk_FUN_007631b0(*(int *)((int)pvVar3 + 0xb7));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  *(undefined4 *)((int)pvVar3 + 0xb7) = 0;
  fread(pvVar3,0xbb,1,_File);
  iVar9 = *(int *)((int)pvVar3 + 0x54);
  if (iVar9 == 0) {
    *(undefined4 *)((int)pvVar3 + 0x58) = 0;
  }
  else {
    piVar7 = (int *)thunk_FUN_007631a0(iVar9 * 0x11 + 4);
    local_4 = 0;
    if (piVar7 == (int *)0x0) {
      piVar7 = (int *)0x0;
    }
    else {
      *piVar7 = iVar9;
      piVar7 = piVar7 + 1;
      FUN_00892e84(piVar7,0x11,iVar9,&LAB_006805c0,&LAB_0042ce20);
    }
    *(int **)((int)pvVar3 + 0x58) = piVar7;
    DAT_009bf3c8 = DAT_009bf3c8 + 1;
    local_4 = 0xffffffff;
  }
  if (*(int *)((int)pvVar3 + 0x5c) == 0) {
    *(undefined4 *)((int)pvVar3 + 0x60) = 0;
  }
  else {
    puVar4 = (undefined4 *)thunk_FUN_007631a0(0xe);
    if (puVar4 == (undefined4 *)0x0) {
      *(undefined4 *)((int)pvVar3 + 0x60) = 0;
      DAT_009bf3c8 = DAT_009bf3c8 + 1;
    }
    else {
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
      *(undefined2 *)(puVar4 + 3) = 0;
      *(undefined4 **)((int)pvVar3 + 0x60) = puVar4;
      DAT_009bf3c8 = DAT_009bf3c8 + 1;
    }
  }
  if (*(int *)((int)pvVar3 + 0x7e) == 0) {
    *(undefined4 *)((int)pvVar3 + 0x82) = 0;
  }
  else {
    puVar4 = (undefined4 *)thunk_FUN_007631a0(9);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      *puVar4 = 0;
      puVar4[1] = 0;
      *(undefined1 *)(puVar4 + 2) = 0;
    }
    *(undefined4 **)((int)pvVar3 + 0x82) = puVar4;
    DAT_009bf3c8 = DAT_009bf3c8 + 1;
  }
  param_1 = (FILE *)0x0;
  if (*(int *)((int)pvVar3 + 0x54) != 0) {
    local_1c = 0;
    do {
      puVar12 = (uint *)(*(int *)((int)pvVar3 + 0x58) + local_1c);
      *puVar12 = 0;
      puVar12[1] = 0;
      puVar12[2] = 0;
      fread(puVar12 + 4,1,1,_File);
      fread(puVar12,4,1,_File);
      if (puVar12[3] != 0) {
        thunk_FUN_007631b0(puVar12[3]);
        DAT_009bf3cc = DAT_009bf3cc + 1;
      }
      puVar12[3] = 0;
      if (*puVar12 != 0) {
        uVar11 = thunk_FUN_007631a0(*puVar12 * 0x11);
        puVar12[3] = uVar11;
        DAT_009bf3c8 = DAT_009bf3c8 + 1;
      }
      local_18 = 0;
      if (*puVar12 != 0) {
        local_20 = 0;
        do {
          uVar11 = puVar12[3];
          fread((void *)(local_20 + uVar11),0x11,1,_File);
          if (*(char *)((int)(local_20 + uVar11) + 4) == '\0') {
            puVar12[2] = puVar12[2] + 1;
          }
          else {
            puVar12[1] = puVar12[1] + 1;
          }
          local_18 = local_18 + 1;
          local_20 = local_20 + 0x11;
        } while (local_18 < *puVar12);
      }
      param_1 = (FILE *)((int)param_1 + 1);
      local_1c = local_1c + 0x11;
    } while (param_1 < *(uint *)((int)pvVar3 + 0x54));
  }
  if (*(int *)((int)pvVar3 + 0x5c) != 0) {
    **(int **)((int)pvVar3 + 0x60) = *(int *)((int)pvVar3 + 0x5c);
    FUN_00685890(_File,*(undefined4 *)((int)pvVar3 + 0x60),uVar5);
  }
  if (*(int *)((int)pvVar3 + 0x7e) != 0) {
    *(int *)(*(int *)((int)pvVar3 + 0x82) + 1) = *(int *)((int)pvVar3 + 0x7e);
    FUN_00685940(_File,*(undefined4 *)((int)pvVar3 + 0x82),uVar5);
  }
  if (*(int *)((int)pvVar3 + 0x86) != 0) {
    uVar5 = thunk_FUN_007631a0(*(int *)((int)pvVar3 + 0x86) * 4);
    *(undefined4 *)((int)pvVar3 + 0x8a) = uVar5;
    uVar5 = thunk_FUN_007631a0(*(int *)((int)pvVar3 + 0x86) << 2);
    *(undefined4 *)((int)pvVar3 + 0x8e) = uVar5;
    uVar5 = thunk_FUN_007631a0(*(undefined4 *)((int)pvVar3 + 0x86));
    *(undefined4 *)((int)pvVar3 + 0x92) = uVar5;
  }
  param_1 = (FILE *)0x0;
  if (*(int *)((int)pvVar3 + 0x86) != 0) {
    do {
      fread((void *)((int)param_1 * 4 + *(int *)((int)pvVar3 + 0x8a)),4,1,_File);
      fread((void *)((int)param_1 * 4 + *(int *)((int)pvVar3 + 0x8e)),4,1,_File);
      fread((void *)((int)param_1 + *(int *)((int)pvVar3 + 0x92)),1,1,_File);
      param_1 = (FILE *)((int)param_1 + 1);
    } while (param_1 < *(uint *)((int)pvVar3 + 0x86));
  }
  if (*(int *)((int)pvVar3 + 0x9f) != 0) {
    uVar5 = thunk_FUN_007631a0(*(int *)((int)pvVar3 + 0x9f) * 4);
    *(undefined4 *)((int)pvVar3 + 0xa3) = uVar5;
    uVar11 = 0;
    if (*(int *)((int)pvVar3 + 0x9f) != 0) {
      do {
        fread((void *)(*(int *)((int)pvVar3 + 0xa3) + uVar11 * 4),4,1,_File);
        uVar11 = uVar11 + 1;
      } while (uVar11 < *(uint *)((int)pvVar3 + 0x9f));
    }
  }
  if (*(int *)((int)pvVar3 + 0xa7) != 0) {
    puVar4 = (undefined4 *)thunk_FUN_007631a0(*(int *)((int)pvVar3 + 0xa7) << 6);
    *(undefined4 **)((int)pvVar3 + 0xab) = puVar4;
    for (iVar9 = (*(uint *)((int)pvVar3 + 0xa7) & 0x3ffffff) << 4; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    puVar4 = (undefined4 *)thunk_FUN_007631a0(*(int *)((int)pvVar3 + 0xa7) << 9);
    *(undefined4 **)((int)pvVar3 + 0xaf) = puVar4;
    for (iVar9 = (*(uint *)((int)pvVar3 + 0xa7) & 0x7fffff) << 7; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    uVar11 = 0;
    if (*(int *)((int)pvVar3 + 0xa7) != 0) {
      local_1c = 0;
      param_1 = (FILE *)0x0;
      do {
        fread((void *)((int)param_1 + *(int *)((int)pvVar3 + 0xab)),1,0x40,_File);
        fread((void *)(local_1c + *(int *)((int)pvVar3 + 0xaf)),8,0x40,_File);
        uVar11 = uVar11 + 1;
        param_1 = (FILE *)((int)param_1 + 0x40);
        local_1c = local_1c + 0x200;
      } while (uVar11 < *(uint *)((int)pvVar3 + 0xa7));
    }
  }
  if (*(int *)((int)pvVar3 + 0xb3) != 0) {
    puVar4 = (undefined4 *)thunk_FUN_007631a0(*(int *)((int)pvVar3 + 0xb3) << 7);
    *(undefined4 **)((int)pvVar3 + 0xb7) = puVar4;
    for (iVar9 = (*(uint *)((int)pvVar3 + 0xb3) & 0x1ffffff) << 5; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    uVar11 = 0;
    if (*(int *)((int)pvVar3 + 0xb3) != 0) {
      param_1 = (FILE *)0x0;
      do {
        fread((void *)((int)param_1 + *(int *)((int)pvVar3 + 0xb7)),2,0x40,_File);
        uVar11 = uVar11 + 1;
        param_1 = (FILE *)((int)param_1 + 0x80);
      } while (uVar11 < *(uint *)((int)pvVar3 + 0xb3));
    }
  }
  uVar5 = DAT_00978974;
  pvVar3 = *(void **)((int)in_ECX + 0x33d);
  iVar9 = *(int *)((int)pvVar3 + 0x58);
  if (iVar9 != 0) {
    FUN_00892d40(iVar9,0x11,*(undefined4 *)(iVar9 + -4),&LAB_0042ce20);
    thunk_FUN_007631b0(iVar9 + -4);
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  iVar9 = *(int *)((int)pvVar3 + 0x60);
  *(undefined4 *)((int)pvVar3 + 0x58) = 0;
  if (iVar9 != 0) {
    FUN_006800a0();
    thunk_FUN_007631b0(iVar9);
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  iVar9 = *(int *)((int)pvVar3 + 0x82);
  *(undefined4 *)((int)pvVar3 + 0x60) = 0;
  if (iVar9 != 0) {
    FUN_006857b0();
    thunk_FUN_007631b0(iVar9);
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  *(undefined4 *)((int)pvVar3 + 0x82) = 0;
  if (*(int *)((int)pvVar3 + 0x8a) != 0) {
    thunk_FUN_007631b0(*(int *)((int)pvVar3 + 0x8a));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  *(undefined4 *)((int)pvVar3 + 0x8a) = 0;
  if (*(int *)((int)pvVar3 + 0x8e) != 0) {
    thunk_FUN_007631b0(*(int *)((int)pvVar3 + 0x8e));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  *(undefined4 *)((int)pvVar3 + 0x8e) = 0;
  if (*(int *)((int)pvVar3 + 0x92) != 0) {
    thunk_FUN_007631b0(*(int *)((int)pvVar3 + 0x92));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  *(undefined4 *)((int)pvVar3 + 0x92) = 0;
  if (*(int *)((int)pvVar3 + 0xa3) != 0) {
    thunk_FUN_007631b0(*(int *)((int)pvVar3 + 0xa3));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  *(undefined4 *)((int)pvVar3 + 0xa3) = 0;
  if (*(int *)((int)pvVar3 + 0xab) != 0) {
    thunk_FUN_007631b0(*(int *)((int)pvVar3 + 0xab));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  *(undefined4 *)((int)pvVar3 + 0xab) = 0;
  if (*(int *)((int)pvVar3 + 0xaf) != 0) {
    thunk_FUN_007631b0(*(int *)((int)pvVar3 + 0xaf));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  *(undefined4 *)((int)pvVar3 + 0xaf) = 0;
  if (*(int *)((int)pvVar3 + 0xb7) != 0) {
    thunk_FUN_007631b0(*(int *)((int)pvVar3 + 0xb7));
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  *(undefined4 *)((int)pvVar3 + 0xb7) = 0;
  fread(pvVar3,0xbb,1,_File);
  iVar9 = *(int *)((int)pvVar3 + 0x54);
  if (iVar9 == 0) {
    *(undefined4 *)((int)pvVar3 + 0x58) = 0;
  }
  else {
    piVar7 = (int *)thunk_FUN_007631a0(iVar9 * 0x11 + 4);
    local_4 = 1;
    if (piVar7 == (int *)0x0) {
      piVar7 = (int *)0x0;
    }
    else {
      *piVar7 = iVar9;
      piVar7 = piVar7 + 1;
      FUN_00892e84(piVar7,0x11,iVar9,&LAB_006805c0,&LAB_0042ce20);
    }
    *(int **)((int)pvVar3 + 0x58) = piVar7;
    DAT_009bf3c8 = DAT_009bf3c8 + 1;
    local_4 = 0xffffffff;
  }
  if (*(int *)((int)pvVar3 + 0x5c) == 0) {
    *(undefined4 *)((int)pvVar3 + 0x60) = 0;
  }
  else {
    puVar4 = (undefined4 *)thunk_FUN_007631a0(0xe);
    if (puVar4 == (undefined4 *)0x0) {
      *(undefined4 *)((int)pvVar3 + 0x60) = 0;
      DAT_009bf3c8 = DAT_009bf3c8 + 1;
    }
    else {
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
      *(undefined2 *)(puVar4 + 3) = 0;
      *(undefined4 **)((int)pvVar3 + 0x60) = puVar4;
      DAT_009bf3c8 = DAT_009bf3c8 + 1;
    }
  }
  if (*(int *)((int)pvVar3 + 0x7e) == 0) {
    *(undefined4 *)((int)pvVar3 + 0x82) = 0;
  }
  else {
    puVar4 = (undefined4 *)thunk_FUN_007631a0(9);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      *puVar4 = 0;
      puVar4[1] = 0;
      *(undefined1 *)(puVar4 + 2) = 0;
    }
    *(undefined4 **)((int)pvVar3 + 0x82) = puVar4;
    DAT_009bf3c8 = DAT_009bf3c8 + 1;
  }
  uVar11 = 0;
  if (*(int *)((int)pvVar3 + 0x54) != 0) {
    param_1 = (FILE *)0x0;
    do {
      FUN_006857d0(_File,*(int *)((int)pvVar3 + 0x58) + (int)param_1,uVar5);
      uVar11 = uVar11 + 1;
      param_1 = (FILE *)((int)param_1 + 0x11);
    } while (uVar11 < *(uint *)((int)pvVar3 + 0x54));
  }
  if (*(int *)((int)pvVar3 + 0x5c) != 0) {
    **(int **)((int)pvVar3 + 0x60) = *(int *)((int)pvVar3 + 0x5c);
    FUN_00685890(_File,*(undefined4 *)((int)pvVar3 + 0x60),uVar5);
  }
  if (*(int *)((int)pvVar3 + 0x7e) != 0) {
    *(int *)(*(int *)((int)pvVar3 + 0x82) + 1) = *(int *)((int)pvVar3 + 0x7e);
    FUN_00685940(_File,*(undefined4 *)((int)pvVar3 + 0x82),uVar5);
  }
  if (*(int *)((int)pvVar3 + 0x86) != 0) {
    uVar5 = thunk_FUN_007631a0(*(int *)((int)pvVar3 + 0x86) * 4);
    *(undefined4 *)((int)pvVar3 + 0x8a) = uVar5;
    uVar5 = thunk_FUN_007631a0(*(int *)((int)pvVar3 + 0x86) << 2);
    *(undefined4 *)((int)pvVar3 + 0x8e) = uVar5;
    uVar5 = thunk_FUN_007631a0(*(undefined4 *)((int)pvVar3 + 0x86));
    *(undefined4 *)((int)pvVar3 + 0x92) = uVar5;
  }
  uVar11 = 0;
  if (*(int *)((int)pvVar3 + 0x86) != 0) {
    do {
      fread((void *)(*(int *)((int)pvVar3 + 0x8a) + uVar11 * 4),4,1,_File);
      fread((void *)(*(int *)((int)pvVar3 + 0x8e) + uVar11 * 4),4,1,_File);
      fread((void *)(*(int *)((int)pvVar3 + 0x92) + uVar11),1,1,_File);
      uVar11 = uVar11 + 1;
    } while (uVar11 < *(uint *)((int)pvVar3 + 0x86));
  }
  if (*(int *)((int)pvVar3 + 0x9f) != 0) {
    uVar5 = thunk_FUN_007631a0(*(int *)((int)pvVar3 + 0x9f) * 4);
    *(undefined4 *)((int)pvVar3 + 0xa3) = uVar5;
    uVar11 = 0;
    if (*(int *)((int)pvVar3 + 0x9f) != 0) {
      do {
        fread((void *)(*(int *)((int)pvVar3 + 0xa3) + uVar11 * 4),4,1,_File);
        uVar11 = uVar11 + 1;
      } while (uVar11 < *(uint *)((int)pvVar3 + 0x9f));
    }
  }
  if (*(int *)((int)pvVar3 + 0xa7) != 0) {
    puVar4 = (undefined4 *)thunk_FUN_007631a0(*(int *)((int)pvVar3 + 0xa7) << 6);
    *(undefined4 **)((int)pvVar3 + 0xab) = puVar4;
    for (iVar9 = (*(uint *)((int)pvVar3 + 0xa7) & 0x3ffffff) << 4; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    puVar4 = (undefined4 *)thunk_FUN_007631a0(*(int *)((int)pvVar3 + 0xa7) << 9);
    *(undefined4 **)((int)pvVar3 + 0xaf) = puVar4;
    for (iVar9 = (*(uint *)((int)pvVar3 + 0xa7) & 0x7fffff) << 7; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    uVar11 = 0;
    if (*(int *)((int)pvVar3 + 0xa7) != 0) {
      local_1c = 0;
      param_1 = (FILE *)0x0;
      do {
        fread((void *)(*(int *)((int)pvVar3 + 0xab) + (int)param_1),1,0x40,_File);
        fread((void *)(*(int *)((int)pvVar3 + 0xaf) + local_1c),8,0x40,_File);
        uVar11 = uVar11 + 1;
        param_1 = (FILE *)((int)param_1 + 0x40);
        local_1c = local_1c + 0x200;
      } while (uVar11 < *(uint *)((int)pvVar3 + 0xa7));
    }
  }
  if (*(int *)((int)pvVar3 + 0xb3) != 0) {
    puVar4 = (undefined4 *)thunk_FUN_007631a0(*(int *)((int)pvVar3 + 0xb3) << 7);
    *(undefined4 **)((int)pvVar3 + 0xb7) = puVar4;
    for (iVar9 = (*(uint *)((int)pvVar3 + 0xb3) & 0x1ffffff) << 5; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    uVar11 = 0;
    if (*(int *)((int)pvVar3 + 0xb3) != 0) {
      param_1 = (FILE *)0x0;
      do {
        fread((void *)(*(int *)((int)pvVar3 + 0xb7) + (int)param_1),2,0x40,_File);
        uVar11 = uVar11 + 1;
        param_1 = (FILE *)((int)param_1 + 0x80);
      } while (uVar11 < *(uint *)((int)pvVar3 + 0xb3));
    }
  }
  uVar5 = DAT_00978974;
  puVar12 = *(uint **)((int)in_ECX + 0x341);
  fread(puVar12,4,1,_File);
  fread(puVar12 + 1,0x14,1,_File);
  uVar11 = puVar12[6];
  if (uVar11 != 0) {
    FUN_00892d40(uVar11,0xbb,*(undefined4 *)(uVar11 - 4),FUN_0042ce40);
    thunk_FUN_007631b0(uVar11 - 4);
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  uVar11 = *puVar12;
  puVar12[6] = 0;
  if (uVar11 != 0) {
    puVar8 = (uint *)thunk_FUN_007631a0(uVar11 * 0xbb + 4);
    local_4 = 2;
    if (puVar8 == (uint *)0x0) {
      puVar8 = (uint *)0x0;
    }
    else {
      *puVar8 = uVar11;
      puVar8 = puVar8 + 1;
      FUN_00892e84(puVar8,0xbb,uVar11,&LAB_00683cc0,FUN_0042ce40);
    }
    puVar12[6] = (uint)puVar8;
    DAT_009bf3c8 = DAT_009bf3c8 + 1;
    local_4 = 0xffffffff;
  }
  uVar11 = 0;
  if (*puVar12 != 0) {
    param_1 = (FILE *)0x0;
    do {
      FUN_006859e0(_File,puVar12[6] + (int)param_1,uVar5);
      uVar11 = uVar11 + 1;
      param_1 = (FILE *)((int)param_1 + 0xbb);
    } while (uVar11 < *puVar12);
  }
  uVar5 = DAT_00978974;
  puVar12 = *(uint **)((int)in_ECX + 0x345);
  fread(puVar12,4,1,_File);
  fread(puVar12 + 1,0x14,1,_File);
  uVar11 = puVar12[6];
  if (uVar11 != 0) {
    FUN_00892d40(uVar11,0xbb,*(undefined4 *)(uVar11 - 4),FUN_0042ce40);
    thunk_FUN_007631b0(uVar11 - 4);
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  uVar11 = *puVar12;
  puVar12[6] = 0;
  if (uVar11 != 0) {
    puVar8 = (uint *)thunk_FUN_007631a0(uVar11 * 0xbb + 4);
    local_4 = 3;
    if (puVar8 == (uint *)0x0) {
      puVar8 = (uint *)0x0;
    }
    else {
      *puVar8 = uVar11;
      puVar8 = puVar8 + 1;
      FUN_00892e84(puVar8,0xbb,uVar11,&LAB_00683cc0,FUN_0042ce40);
    }
    puVar12[6] = (uint)puVar8;
    DAT_009bf3c8 = DAT_009bf3c8 + 1;
    local_4 = 0xffffffff;
  }
  uVar11 = 0;
  if (*puVar12 != 0) {
    param_1 = (FILE *)0x0;
    do {
      FUN_006859e0(_File,(int)param_1 + puVar12[6],uVar5);
      uVar11 = uVar11 + 1;
      param_1 = (FILE *)((int)param_1 + 0xbb);
    } while (uVar11 < *puVar12);
  }
  uVar5 = DAT_00978974;
  puVar12 = *(uint **)((int)in_ECX + 0x349);
  fread(puVar12,4,1,_File);
  fread(puVar12 + 1,4,1,_File);
  fread(puVar12 + 2,0x14,1,_File);
  uVar11 = puVar12[7];
  if (uVar11 != 0) {
    FUN_00892d40(uVar11,0xbb,*(undefined4 *)(uVar11 - 4),FUN_0042ce40);
    thunk_FUN_007631b0(uVar11 - 4);
    DAT_009bf3cc = DAT_009bf3cc + 1;
  }
  uVar11 = *puVar12;
  puVar12[7] = 0;
  if (uVar11 != 0) {
    puVar8 = (uint *)thunk_FUN_007631a0(uVar11 * 0xbb + 4);
    local_4 = 4;
    if (puVar8 == (uint *)0x0) {
      puVar8 = (uint *)0x0;
    }
    else {
      *puVar8 = uVar11;
      puVar8 = puVar8 + 1;
      FUN_00892e84(puVar8,0xbb,uVar11,&LAB_00683cc0,FUN_0042ce40);
    }
    puVar12[7] = (uint)puVar8;
    DAT_009bf3c8 = DAT_009bf3c8 + 1;
    local_4 = 0xffffffff;
  }
  uVar11 = 0;
  if (*puVar12 != 0) {
    param_1 = (FILE *)0x0;
    do {
      FUN_006859e0(_File,(int)param_1 + puVar12[7],uVar5);
      uVar11 = uVar11 + 1;
      param_1 = (FILE *)((int)param_1 + 0xbb);
    } while (uVar11 < *puVar12);
  }
  FUN_00686180(_File,*(undefined4 *)((int)in_ECX + 0x34d),DAT_00978974);
  ExceptionList = local_c;
  return 1;
}

