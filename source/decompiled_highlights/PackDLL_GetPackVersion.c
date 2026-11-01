// rea decompile_all
// name: GetPackVersion
// address: 0x10002270
// body: available
// range: 0x10002270-0x1000235c inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e763201e522a4b123fb330eede09834c44ddf2bb90702e50eea219801be95539
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int GetPackVersion(void)

{
  char cVar1;
  void *this;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined **ppuVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  uint local_19c;
  int local_198;
  undefined4 local_194;
  char local_190 [400];
  
                    /* 0x2270  8  GetPackVersion */
  iVar7 = 99999999;
  ppuVar6 = &PTR_s_configs_1000f030;
  do {
    pcVar2 = *ppuVar6;
    uVar3 = 0xffffffff;
    pcVar8 = pcVar2;
    do {
      pcVar9 = pcVar8;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar9 = pcVar8 + 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar9;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    local_194 = local_190;
    pcVar8 = pcVar9 + -uVar3;
    pcVar9 = local_194;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar9 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar9 = pcVar9 + 1;
    }
    uVar3 = 0xffffffff;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    uVar4 = 0xffffffff;
    pcVar2 = s__version_sw_1000f368;
    do {
      pcVar8 = pcVar2;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar8 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar8;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar2 = pcVar8 + -uVar4;
    pcVar8 = local_190 + (~uVar3 - 1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar8 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      pcVar8 = pcVar8 + 1;
    }
    this = (void *)FUN_10005080(&DAT_100118d0,local_190);
    pcVar2 = (char *)FUN_10002990(100);
    local_19c = 100;
    uVar3 = FUN_10003fa0(this,local_190,pcVar2,&local_19c);
    if ((char)uVar3 != '\0') {
      sscanf(pcVar2,&DAT_1000f374,&local_198);
      if (local_198 < iVar7) {
        iVar7 = local_198;
      }
      FUN_100029a0((int)pcVar2);
    }
    ppuVar6 = ppuVar6 + 1;
    if ((undefined **)((int)&PTR_s_loddata_1000f068 + 3) < ppuVar6) {
      return iVar7;
    }
  } while( true );
}

