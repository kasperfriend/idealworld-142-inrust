// rea decompile_all
// name: FUN_0068a150
// address: 0x68a150
// body: available
// range: 0x68a150-0x68a227 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e1ad533d4cc0333c2136fe0894217de2d61feea098240326e78633f9e4ddcbf9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_0068a150(uint *param_1,uint param_2,char param_3)

{
  uint *puVar1;
  uint uVar2;
  undefined3 uVar5;
  int iVar3;
  uint *puVar4;
  int in_ECX;
  ushort uVar6;
  char *pcVar7;
  uint local_10;
  uint local_c;
  uint local_8;
  
  if (param_2 < 0xc) {
    pcVar7 = s_UnmarshalNPCInfo__wrong_size_00978b4c;
  }
  else if ((short)param_1[2] == 1) {
    if (*param_1 == param_2) {
      uVar2 = param_1[1];
      *(uint *)(in_ECX + 0x2dc) = uVar2;
      uVar5 = (undefined3)(uVar2 >> 8);
      puVar4 = (uint *)CONCAT31(uVar5,param_3);
      if (param_3 == '\0') {
        uVar6 = 0;
        if (*(short *)((int)param_1 + 10) != 0) {
          do {
            local_10 = param_1[(uint)uVar6 * 3 + 3];
            puVar1 = param_1 + (uint)uVar6 * 3 + 3;
            local_c = local_10;
            local_8 = local_10;
            iVar3 = FUN_0068a4a0(puVar1,&local_10);
            puVar4 = (uint *)(iVar3 + 4);
            uVar6 = uVar6 + 1;
            *puVar4 = *puVar1;
            *(uint *)(iVar3 + 8) = puVar1[1];
            *(uint *)(iVar3 + 0xc) = puVar1[2];
          } while (uVar6 < *(ushort *)((int)param_1 + 10));
        }
        return CONCAT31((int3)((uint)puVar4 >> 8),1);
      }
      return CONCAT31(uVar5,1);
    }
    pcVar7 = s_UnmarshalNPCInfo__wrong_header_00978b0c;
  }
  else {
    pcVar7 = s_UnmarshalNPCInfo__wrong_version_00978b2c;
  }
  uVar2 = FUN_00430860(0,0,0,pcVar7);
  return uVar2 & 0xffffff00;
}

