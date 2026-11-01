// rea decompile_all
// name: FUN_00467920
// address: 0x467920
// body: available
// range: 0x467920-0x467b65 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e1ad533d4cc0333c2136fe0894217de2d61feea098240326e78633f9e4ddcbf9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_00467920(void *this,char *param_1)

{
  void *pvVar1;
  FILE *_File;
  uint uVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int local_14;
  int local_10;
  int local_c;
  void *local_8;
  FILE *local_4;
  
  _File = fopen(param_1,&DAT_0048fa64);
  if (_File == (FILE *)0x0) {
    return 0;
  }
  local_4 = _File;
  fread(&local_c,4,1,_File);
  if (local_c != 0) {
    uVar2 = fclose(_File);
    return uVar2 & 0xffffff00;
  }
  fread(&param_1,4,1,_File);
  local_10 = 0;
  if (0 < (int)param_1) {
    do {
      pvVar3 = operator_new(0x14);
      local_8 = pvVar3;
      if (pvVar3 == (void *)0x0) {
LAB_00467aa0:
        fclose(_File);
        param_1 = *(char **)((int)this + 0xc);
        iVar7 = 0;
        if (0 < (int)param_1) {
          do {
            FUN_00467860(*(int *)(*(int *)this + iVar7 * 4));
            pvVar3 = *(void **)(*(int *)this + iVar7 * 4);
            if (pvVar3 != (void *)0x0) {
              FUN_00467cb0((undefined4 *)((int)pvVar3 + 4),*(undefined4 **)((int)pvVar3 + 4),
                           *(undefined4 **)((int)pvVar3 + 4) + *(int *)((int)pvVar3 + 0x10));
              pvVar1 = *(void **)((int)pvVar3 + 4);
              if (pvVar1 != (void *)0x0) {
                operator_delete(pvVar1);
              }
              operator_delete(pvVar3);
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < (int)param_1);
        }
        puVar8 = *(undefined4 **)this;
        puVar9 = puVar8 + *(int *)((int)this + 0xc);
        if (puVar8 != puVar9) {
          puVar5 = puVar9;
          puVar10 = puVar8;
          if (puVar9 < *(undefined4 **)((int)this + 4)) {
            do {
              puVar6 = puVar5 + 1;
              *puVar10 = *puVar5;
              puVar5 = puVar6;
              puVar10 = puVar10 + 1;
            } while (puVar6 < *(undefined4 **)((int)this + 4));
          }
          iVar7 = (int)puVar9 - (int)puVar8 >> 2;
          *(int *)((int)this + 4) = *(int *)((int)this + 4) + iVar7 * -4;
          param_1 = (char *)(*(int *)((int)this + 0xc) - iVar7);
          *(char **)((int)this + 0xc) = param_1;
        }
        return (uint)param_1 & 0xffffff00;
      }
      *(undefined4 *)((int)pvVar3 + 0xc) = 0;
      *(undefined4 *)((int)pvVar3 + 0x10) = 0;
      *(undefined4 *)((int)pvVar3 + 4) = 0;
      *(undefined4 *)((int)pvVar3 + 8) = 0;
      uVar4 = FUN_004676d0(pvVar3,_File);
      if ((char)uVar4 == '\0') goto LAB_00467aa0;
      uVar2 = *(uint *)((int)this + 0xc);
      if (uVar2 == *(uint *)((int)this + 8)) {
        if (uVar2 + 1 < 5) {
          local_14 = 5;
        }
        else {
          local_14 = uVar2 + 3 + (uVar2 >> 1);
        }
        puVar5 = operator_new(local_14 * 4);
        puVar9 = *(undefined4 **)this;
        uVar2 = 0;
        puVar8 = puVar5;
        if (*(int *)((int)this + 0xc) != 0) {
          do {
            if (puVar8 != (undefined4 *)0x0) {
              uVar4 = *puVar9;
              puVar9 = puVar9 + 1;
              *puVar8 = uVar4;
              pvVar3 = local_8;
            }
            uVar2 = uVar2 + 1;
            puVar8 = puVar8 + 1;
          } while (uVar2 < *(uint *)((int)this + 0xc));
        }
        if (*(void **)this != (void *)0x0) {
          operator_delete(*(void **)this);
        }
        *(undefined4 **)this = puVar5;
        *(int *)((int)this + 8) = local_14;
        *(undefined4 **)((int)this + 4) = puVar5 + *(int *)((int)this + 0xc);
        _File = local_4;
      }
      if (*(undefined4 **)((int)this + 4) != (undefined4 *)0x0) {
        **(undefined4 **)((int)this + 4) = pvVar3;
      }
      local_10 = local_10 + 1;
      *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
      *(int *)((int)this + 4) = *(int *)((int)this + 4) + 4;
    } while (local_10 < (int)param_1);
  }
  iVar7 = fclose(_File);
  return CONCAT31((int3)((uint)iVar7 >> 8),1);
}

