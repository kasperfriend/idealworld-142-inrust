// rea decompile_all
// name: FUN_005d9700
// address: 0x5d9700
// body: available
// range: 0x5d9700-0x5d9796 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e1ad533d4cc0333c2136fe0894217de2d61feea098240326e78633f9e4ddcbf9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_005d9700(int param_1)

{
  char cVar1;
  char *pcVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  
  FUN_00430620(DAT_009b3eec,0xff00ff00,u_NET___protocol_keyexchange_0097315c);
  FUN_005d97a0(*(undefined4 *)(in_ECX + 0xac),*(undefined4 *)(in_ECX + 0xb0),
               *(undefined4 *)(in_ECX + 0x134),*(char *)(in_ECX + 0x144) != '\0');
  pcVar2 = (char *)FUN_00763ef0();
  uVar3 = 0xffffffff;
  pcVar5 = pcVar2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  for (uVar4 = ~uVar3 - 1 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    pcVar2[0] = '\0';
    pcVar2[1] = '\0';
    pcVar2[2] = '\0';
    pcVar2[3] = '\0';
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = ~uVar3 - 1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar2 = '\0';
    pcVar2 = pcVar2 + 1;
  }
  FUN_00763f40();
  if (param_1 != 0) {
    FUN_005cfb00(param_1,0);
  }
  return;
}

