// rea decompile_all
// name: CalcCompressFile
// address: 0x10001120
// body: available
// range: 0x10001120-0x1000123b inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e763201e522a4b123fb330eede09834c44ddf2bb90702e50eea219801be95539
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __cdecl CalcCompressFile(LPCWSTR param_1,int *param_2,int *param_3)

{
  DWORD _Count;
  FILE *_File;
  undefined4 *_DstBuf;
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  CHAR local_195;
  uint local_194;
  CHAR local_190 [400];
  
                    /* 0x1120  2  CalcCompressFile */
  *param_3 = 0;
  local_195 = ' ';
  WideCharToMultiByte(0x3a8,0,param_1,-1,local_190,400,&local_195,(LPBOOL)0x0);
  _Count = FUN_10001050(local_190);
  _File = fopen(local_190,&DAT_1000f2f4);
  if (_File != (FILE *)0x0) {
    _DstBuf = (undefined4 *)FUN_10002990(_Count + 1);
    fread(_DstBuf,1,_Count,_File);
    fclose(_File);
    local_194 = _Count + 1;
    iVar1 = FUN_10002990(_Count + 5);
    *param_3 = iVar1;
    iVar1 = FUN_10005140((int)_DstBuf,_Count,iVar1 + 4,&local_194);
    if ((iVar1 != 0) || (_Count <= local_194)) {
      puVar4 = (undefined4 *)*param_3;
      puVar3 = _DstBuf;
      for (uVar2 = _Count >> 2; puVar4 = puVar4 + 1, uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
      }
      for (uVar2 = _Count & 3; local_194 = _Count, uVar2 != 0; uVar2 = uVar2 - 1) {
        *(undefined1 *)puVar4 = *(undefined1 *)puVar3;
        puVar3 = (undefined4 *)((int)puVar3 + 1);
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
    }
    FUN_100029a0((int)_DstBuf);
    iVar1 = 0;
    do {
      *(char *)(*param_3 + iVar1) = (char)_Count;
      _Count = _Count >> 8;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 4);
    *param_2 = local_194 + 4;
    return CONCAT31((int3)((uint)param_2 >> 8),1);
  }
  return 0;
}

