// rea decompile_all
// name: DecompressFile
// address: 0x10001240
// body: available
// range: 0x10001240-0x10001403 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e763201e522a4b123fb330eede09834c44ddf2bb90702e50eea219801be95539
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __cdecl DecompressFile(LPCWSTR param_1,LPCWSTR param_2)

{
  DWORD _Count;
  FILE *pFVar1;
  void *_DstBuf;
  uint uVar2;
  void *_Str;
  undefined4 uVar3;
  int iVar4;
  CHAR local_325;
  size_t local_324;
  CHAR local_320 [400];
  CHAR local_190 [400];
  
                    /* 0x1240  4  DecompressFile */
  local_325 = ' ';
  WideCharToMultiByte(0x3a8,0,param_1,-1,local_320,400,&local_325,(LPBOOL)0x0);
  WideCharToMultiByte(0x3a8,0,param_2,-1,local_190,400,&local_325,(LPBOOL)0x0);
  _Count = FUN_10001050(local_320);
  pFVar1 = fopen(local_320,&DAT_1000f2f4);
  if (pFVar1 == (FILE *)0x0) {
    return 0;
  }
  _DstBuf = (void *)FUN_10002990(_Count + 1);
  fread(_DstBuf,1,_Count,pFVar1);
  fclose(pFVar1);
  local_324 = 0;
  iVar4 = 3;
  do {
    local_324 = local_324 * 0x100 + (uint)*(byte *)(iVar4 + (int)_DstBuf);
    iVar4 = iVar4 + -1;
  } while (-1 < iVar4);
  if (local_324 + 4 == _Count) {
    pFVar1 = fopen(local_190,&DAT_1000f2f8);
    if (pFVar1 == (FILE *)0x0) {
      uVar2 = FUN_100029a0((int)_DstBuf);
      return uVar2 & 0xffffff00;
    }
    fwrite((void *)((int)_DstBuf + 4),1,local_324,pFVar1);
    fclose(pFVar1);
    _Str = _DstBuf;
  }
  else {
    _Str = (void *)FUN_10002990(local_324 + 1);
    iVar4 = FUN_10005180((int)_DstBuf + 4,_Count - 4,_Str,&local_324);
    if (iVar4 != 0) {
      FUN_100029a0((int)_DstBuf);
      uVar2 = FUN_100029a0((int)_Str);
      return uVar2 & 0xffffff00;
    }
    FUN_100029a0((int)_DstBuf);
    pFVar1 = fopen(local_190,&DAT_1000f2f8);
    if (pFVar1 == (FILE *)0x0) {
      uVar2 = FUN_100029a0((int)_Str);
      return uVar2 & 0xffffff00;
    }
    fwrite(_Str,1,local_324,pFVar1);
    fclose(pFVar1);
  }
  uVar3 = FUN_100029a0((int)_Str);
  return CONCAT31((int3)((uint)uVar3 >> 8),1);
}

