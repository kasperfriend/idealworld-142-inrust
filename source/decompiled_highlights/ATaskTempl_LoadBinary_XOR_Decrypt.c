// rea decompile_all
// name: FUN_00687d60
// address: 0x687d60
// body: available
// range: 0x687d60-0x688231 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e1ad533d4cc0333c2136fe0894217de2d61feea098240326e78633f9e4ddcbf9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00687d60(FILE *param_1)

{
  ushort uVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  ushort *_DstBuf;
  int iVar4;
  int iVar5;
  int iVar6;
  int iStack_1c;
  int local_18;
  int iStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_008c24bc;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00683ce0(param_1);
  FUN_00688300(param_1);
  FUN_00688480(param_1);
  uVar1 = *(ushort *)(in_ECX + 4);
  _DstBuf = (ushort *)(in_ECX + 0x49c);
  fread((void *)(in_ECX + 0x51c),4,1,param_1);
  fread(_DstBuf,0x80,1,param_1);
  fread((void *)(in_ECX + 0x520),4,1,param_1);
  iVar4 = *(int *)(in_ECX + 0x520);
  piVar2 = (int *)thunk_FUN_007631a0(iVar4 * 0x18 + 4);
  puStack_8 = (undefined1 *)0x0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    *piVar2 = iVar4;
    piVar2 = piVar2 + 1;
    FUN_00892e84(piVar2,0x18,iVar4,&LAB_00663b30,FUN_00401dc0);
  }
  *(int **)(in_ECX + 0x524) = piVar2;
  iVar4 = 0;
  puStack_8 = (undefined1 *)0xffffffff;
  if (0 < *(int *)(in_ECX + 0x520)) {
    do {
      FUN_00687a10(param_1);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0x520));
  }
  iVar4 = 0x40;
  do {
    *_DstBuf = *_DstBuf ^ uVar1;
    _DstBuf = _DstBuf + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iStack_14 = 0;
  if (0 < *(int *)(in_ECX + 0x520)) {
    iVar4 = 0;
    do {
      iVar5 = iVar4 + *(int *)(in_ECX + 0x524);
      FUN_00688240(*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 8),uVar1);
      local_18 = 0;
      if (0 < *(int *)(iVar5 + 0x10)) {
        iVar6 = 0;
        do {
          FUN_00688240(iVar6 + *(int *)(iVar5 + 0x14) + 4,0x40,uVar1);
          local_18 = local_18 + 1;
          iVar6 = iVar6 + 0x88;
        } while (local_18 < *(int *)(iVar5 + 0x10));
      }
      iStack_14 = iStack_14 + 1;
      iVar4 = iVar4 + 0x18;
    } while (iStack_14 < *(int *)(in_ECX + 0x520));
  }
  fread((void *)(iStack_1c + 0x5a8),4,1,param_1);
  fread((void *)(iStack_1c + 0x528),0x80,1,param_1);
  fread((void *)(iStack_1c + 0x5ac),4,1,param_1);
  iVar4 = *(int *)(iStack_1c + 0x5ac);
  piVar2 = (int *)thunk_FUN_007631a0(iVar4 * 0x18 + 4);
  puStack_8 = (undefined1 *)0x1;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    *piVar2 = iVar4;
    piVar2 = piVar2 + 1;
    FUN_00892e84(piVar2,0x18,iVar4,&LAB_00663b30,FUN_00401dc0);
  }
  *(int **)(iStack_1c + 0x5b0) = piVar2;
  iVar4 = 0;
  puStack_8 = (undefined1 *)0xffffffff;
  if (0 < *(int *)(iStack_1c + 0x5ac)) {
    do {
      FUN_00687a10(param_1);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(iStack_1c + 0x5ac));
  }
  FUN_00688240((void *)(iStack_1c + 0x528),0x40,uVar1);
  local_18 = 0;
  if (0 < *(int *)(iStack_1c + 0x5ac)) {
    iVar4 = 0;
    do {
      iVar5 = iVar4 + *(int *)(iStack_1c + 0x5b0);
      FUN_00688240(*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 8),uVar1);
      iStack_14 = 0;
      if (0 < *(int *)(iVar5 + 0x10)) {
        iVar6 = 0;
        do {
          FUN_00688240(iVar6 + *(int *)(iVar5 + 0x14) + 4,0x40,uVar1);
          iStack_14 = iStack_14 + 1;
          iVar6 = iVar6 + 0x88;
        } while (iStack_14 < *(int *)(iVar5 + 0x10));
      }
      local_18 = local_18 + 1;
      iVar4 = iVar4 + 0x18;
    } while (local_18 < *(int *)(iStack_1c + 0x5ac));
  }
  fread((void *)(iStack_1c + 0x634),4,1,param_1);
  fread((void *)(iStack_1c + 0x5b4),0x80,1,param_1);
  fread((int *)(iStack_1c + 0x638),4,1,param_1);
  iVar4 = *(int *)(iStack_1c + 0x638);
  piVar2 = (int *)thunk_FUN_007631a0(iVar4 * 0x18 + 4);
  puStack_8 = (undefined1 *)0x2;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    *piVar2 = iVar4;
    piVar2 = piVar2 + 1;
    FUN_00892e84(piVar2,0x18,iVar4,&LAB_00663b30,FUN_00401dc0);
  }
  *(int **)(iStack_1c + 0x63c) = piVar2;
  iVar4 = 0;
  puStack_8 = (undefined1 *)0xffffffff;
  if (0 < *(int *)(iStack_1c + 0x638)) {
    do {
      FUN_00687a10(param_1);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(iStack_1c + 0x638));
  }
  FUN_00688260((void *)(iStack_1c + 0x5b4),uVar1);
  FUN_006639b0(param_1);
  FUN_00688260(iStack_1c + 0x640,uVar1);
  FUN_006639b0(param_1);
  FUN_00688260(iStack_1c + 0x6cc,uVar1);
  piVar2 = (int *)(iStack_1c + 0x494);
  fread(piVar2,4,1,param_1);
  iVar4 = 0;
  if (0 < *piVar2) {
    do {
      iVar5 = thunk_FUN_007631a0(0x758);
      puStack_8 = (undefined1 *)0x3;
      if (iVar5 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = FUN_00687aa0();
      }
      DAT_009bf3c8 = DAT_009bf3c8 + 1;
      puStack_8 = (undefined1 *)0xffffffff;
      FUN_006868b0(uVar3);
      FUN_00687d60(param_1);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *piVar2);
  }
  FUN_00687cf0();
  ExceptionList = pvStack_10;
  return 1;
}

