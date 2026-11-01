// rea decompile_all
// name: GNET::ElementSkill::Create
// address: 0x10001007
// body: available
// range: 0x10001007-0x10001016 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e763201e522a4b123fb330eede09834c44ddf2bb90702e50eea219801be95539
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* public: static class GNET::ElementSkill * __cdecl GNET::ElementSkill::Create(unsigned int,int) */

ElementSkill * __cdecl GNET::ElementSkill::Create(uint param_1,int param_2)

{
  ElementSkill *pEVar1;
  
                    /* 0x1007  20  ?Create@ElementSkill@GNET@@SAPAV12@IH@Z */
  pEVar1 = (ElementSkill *)FUN_10001ad4(param_1,param_2);
  return pEVar1;
}

