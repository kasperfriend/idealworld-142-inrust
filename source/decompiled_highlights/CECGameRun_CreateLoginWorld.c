// rea decompile_all
// name: FUN_00434b80
// address: 0x434b80
// body: available
// range: 0x434b80-0x434da4 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e1ad533d4cc0333c2136fe0894217de2d61feea098240326e78633f9e4ddcbf9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00434b80(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  DWORD DVar4;
  int in_ECX;
  char local_110 [260];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_008a835e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  cVar1 = FUN_00430850();
  if (cVar1 == '\0') {
    FUN_00764590(1,s_CECGameRun__CreateLoginWorld__Fa_00952810);
    uVar2 = 0;
  }
  else {
    iVar3 = thunk_FUN_007631a0(0xb4);
    local_4 = 0;
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_004289f0(in_ECX);
    }
    local_4 = 0xffffffff;
    *(int *)(in_ECX + 8) = iVar3;
    if (iVar3 == 0) {
      FUN_0043c590(2,s_CECGameRun__CreateLoginWorld_009527f0,0x284);
      uVar2 = 0;
    }
    else {
      cVar1 = FUN_00428ad0(0);
      if (cVar1 == '\0') {
        FUN_00764590(1,s_CECGameRun__CreateLoginWorld__Fa_009527b4);
        uVar2 = 0;
      }
      else {
        FUN_00424230(0);
        FUN_00438150(2,0,100);
        cVar1 = FUN_004294a0(s_Maps_Login_Login_ecwld_0095279c,param_1);
        if (cVar1 == '\0') {
          FUN_00764590(1,s_CECGameRun__CreateLoginWorld__Fa_00952768);
          uVar2 = 0;
        }
        else {
          FUN_00438230();
          FUN_00401cc0(param_1);
          FUN_00774140();
          iVar3 = *(int *)(DAT_009b3eec + 0x18);
          FUN_0077ac40(*(undefined4 *)(iVar3 + 4));
          FUN_0077ac60(*(undefined4 *)(iVar3 + 8));
          FUN_0077ac80(*(undefined4 *)(iVar3 + 0xc));
          FUN_0077ac20(*(undefined4 *)(iVar3 + 0x10));
          DVar4 = GetTickCount();
          sprintf(local_110,s_music_theme__c_mp3_00952754,(int)(((ulonglong)DVar4 / 100) % 3) + 0x61
                 );
          FUN_0064cf70(local_110,0,1);
          if (*(int *)(*(int *)(*(int *)(DAT_009b3eec + 0x1c) + 8) + 0x3c) != 0) {
            FUN_006508e0(0x3f800000);
          }
          if (*(int *)(*(int *)(*(int *)(DAT_009b3eec + 0x1c) + 8) + 0x40) != 0) {
            FUN_00651780(0x3f800000);
          }
          if (*(int *)(*(int *)(*(int *)(DAT_009b3eec + 0x1c) + 8) + 0x48) != 0) {
            FUN_006461f0(10);
          }
          uVar2 = 1;
        }
      }
    }
  }
  ExceptionList = local_c;
  return uVar2;
}

