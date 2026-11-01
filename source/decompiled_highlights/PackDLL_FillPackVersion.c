// rea decompile_all
// name: FillPackVersion
// address: 0x10002110
// body: available
// range: 0x10002110-0x10002262 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e763201e522a4b123fb330eede09834c44ddf2bb90702e50eea219801be95539
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FillPackVersion(LPCWSTR param_1)

{
  char cVar1;
  FILE *_File;
  void *_DstBuf;
  void *this;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined **ppuVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  CHAR local_43d;
  size_t local_43c;
  undefined4 local_438;
  char local_434 [400];
  CHAR local_2a4 [400];
  undefined4 local_114 [69];
  
                    /* 0x2110  5  FillPackVersion */
  local_43d = ' ';
  WideCharToMultiByte(0x3a8,0,param_1,-1,local_2a4,400,&local_43d,(LPBOOL)0x0);
  _File = fopen(local_2a4,&DAT_1000f2f4);
  if (_File != (FILE *)0x0) {
    _DstBuf = (void *)FUN_10002990(100);
    local_43c = fread(_DstBuf,1,100,_File);
    fclose(_File);
    ppuVar6 = &PTR_s_configs_1000f030;
    do {
      pcVar8 = *ppuVar6;
      uVar3 = 0xffffffff;
      pcVar7 = pcVar8;
      do {
        pcVar9 = pcVar7;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar9 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar9;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      local_438 = local_434;
      pcVar7 = pcVar9 + -uVar3;
      pcVar9 = local_438;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar9 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar9 = pcVar9 + 1;
      }
      uVar3 = 0xffffffff;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      uVar4 = 0xffffffff;
      pcVar8 = s__version_sw_1000f368;
      do {
        pcVar7 = pcVar8;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar7 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar7;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      pcVar8 = pcVar7 + -uVar4;
      pcVar7 = local_434 + (~uVar3 - 1);
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar7 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar7 = pcVar7 + 1;
      }
      this = (void *)FUN_10005080(&DAT_100118d0,local_434);
      uVar2 = FUN_10003f10(this,local_434,local_114,(int *)0x0);
      if ((char)uVar2 == '\0') {
        FUN_100042a0(this,local_434,_DstBuf,local_43c,'\x01');
      }
      else {
        FUN_100047e0(this,local_434,_DstBuf,local_43c,'\x01');
      }
      ppuVar6 = ppuVar6 + 1;
    } while (ppuVar6 < &PTR_s_cursors_1000f06c);
    FUN_100029a0((int)_DstBuf);
  }
  return;
}

