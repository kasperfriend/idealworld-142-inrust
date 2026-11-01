// rea decompile_all
// name: FUN_006639b0
// address: 0x6639b0
// body: available
// range: 0x6639b0-0x663b2c inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e1ad533d4cc0333c2136fe0894217de2d61feea098240326e78633f9e4ddcbf9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_006639b0(FILE *param_1)

{
  size_t *psVar1;
  int iVar2;
  FILE *_File;
  int *piVar3;
  void *pvVar4;
  void *in_ECX;
  void *_DstBuf;
  int local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  _File = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_008c1d5b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  fread((void *)((int)in_ECX + 0x80),4,1,param_1);
  fread(in_ECX,0x80,1,param_1);
  fread((int *)((int)in_ECX + 0x84),4,1,param_1);
  iVar2 = *(int *)((int)in_ECX + 0x84);
  piVar3 = (int *)thunk_FUN_007631a0(iVar2 * 0x18 + 4);
  local_4 = 0;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    *piVar3 = iVar2;
    piVar3 = piVar3 + 1;
    FUN_00892e84(piVar3,0x18,iVar2,&LAB_00663b30,FUN_00401dc0);
  }
  *(int **)((int)in_ECX + 0x88) = piVar3;
  local_4 = 0xffffffff;
  local_14 = 0;
  if (0 < *(int *)((int)in_ECX + 0x84)) {
    param_1 = (FILE *)0x0;
    do {
      _DstBuf = (void *)(*(int *)((int)in_ECX + 0x88) + (int)param_1);
      fread(_DstBuf,4,1,_File);
      fread((void *)((int)_DstBuf + 4),4,1,_File);
      psVar1 = (size_t *)((int)_DstBuf + 8);
      fread(psVar1,4,1,_File);
      pvVar4 = (void *)thunk_FUN_007631a0(*psVar1 << 1);
      *(void **)((int)_DstBuf + 0xc) = pvVar4;
      fread(pvVar4,2,*psVar1,_File);
      psVar1 = (size_t *)((int)_DstBuf + 0x10);
      fread(psVar1,4,1,_File);
      pvVar4 = (void *)thunk_FUN_007631a0(*psVar1 * 0x88);
      *(void **)((int)_DstBuf + 0x14) = pvVar4;
      fread(pvVar4,0x88,*psVar1,_File);
      local_14 = local_14 + 1;
      param_1 = (FILE *)((int)param_1 + 0x18);
    } while (local_14 < *(int *)((int)in_ECX + 0x84));
  }
  ExceptionList = local_c;
  return 0;
}

