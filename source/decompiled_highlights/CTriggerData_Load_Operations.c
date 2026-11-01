// rea decompile_all
// name: FUN_00466f00
// address: 0x466f00
// body: available
// range: 0x466f00-0x46749f inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e1ad533d4cc0333c2136fe0894217de2d61feea098240326e78633f9e4ddcbf9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_00466f00(void *this,FILE *param_1)

{
  uint uVar1;
  FILE *_File;
  undefined4 *puVar2;
  void *pvVar3;
  undefined4 *puVar4;
  int local_1c;
  int local_18;
  undefined4 *local_14;
  uint local_10;
  undefined4 *local_c;
  int local_8;
  undefined4 *local_4;
  
  _File = param_1;
  fread(&local_8,4,1,param_1);
  if (local_8 == 0) {
    fread((void *)((int)this + 0x84),4,1,param_1);
    fread((void *)((int)this + 0x80),1,1,param_1);
    fread((void *)((int)this + 0x81),1,1,param_1);
    fread((void *)((int)this + 0x82),1,1,param_1);
    fread(this,0x80,1,param_1);
    local_18 = 0;
    puVar2 = operator_new(0x10);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
    }
    *(undefined4 **)((int)this + 0x88) = puVar2;
    FUN_00466c10(param_1,puVar2);
    fread(&local_18,4,1,param_1);
    local_10 = 0;
    local_8 = local_18;
    if (0 < local_18) {
      do {
        puVar2 = operator_new(0x10);
        fread(puVar2,4,1,_File);
        switch(*puVar2) {
        case 0:
        case 4:
        case 6:
        case 8:
          pvVar3 = malloc(4);
          puVar2[1] = pvVar3;
          fread(pvVar3,4,1,_File);
          break;
        case 1:
          pvVar3 = malloc(8);
          puVar2[1] = pvVar3;
          fread(pvVar3,8,1,_File);
          break;
        case 2:
          pvVar3 = malloc(8);
          puVar2[1] = pvVar3;
          fread(pvVar3,4,1,_File);
          pvVar3 = operator_new(*(uint *)puVar2[1] & 0xfffffffe);
          *(void **)(puVar2[1] + 4) = pvVar3;
          fread((void *)((size_t *)puVar2[1])[1],*(size_t *)puVar2[1],1,_File);
          break;
        default:
          puVar2[1] = 0;
          break;
        case 5:
          pvVar3 = malloc(4);
          puVar2[1] = pvVar3;
          fread(pvVar3,4,1,_File);
          break;
        case 7:
          pvVar3 = malloc(0xc);
          puVar2[1] = pvVar3;
          fread(pvVar3,0xc,1,_File);
          break;
        case 0xe:
          pvVar3 = malloc(8);
          puVar2[1] = pvVar3;
          fread(pvVar3,4,1,_File);
          *(undefined1 *)(puVar2[1] + 4) = 0;
        }
        fread(puVar2 + 2,4,1,_File);
        if (puVar2[2] == 6) {
          pvVar3 = malloc(4);
          puVar2[3] = pvVar3;
          fread(pvVar3,4,1,_File);
        }
        else {
          puVar2[3] = 0;
        }
        uVar1 = *(uint *)((int)this + 0x98);
        if (uVar1 == *(uint *)((int)this + 0x94)) {
          if (uVar1 + 1 < 5) {
            local_1c = 5;
          }
          else {
            local_1c = uVar1 + 3 + (uVar1 >> 1);
          }
          local_4 = operator_new(local_1c * 4);
          param_1 = *(FILE **)((int)this + 0x8c);
          local_14 = (undefined4 *)0x0;
          puVar4 = local_4;
          if (*(int *)((int)this + 0x98) != 0) {
            do {
              local_c = puVar4 + 1;
              if (puVar4 != (undefined4 *)0x0) {
                *puVar4 = param_1->_ptr;
                param_1 = (FILE *)&param_1->_cnt;
              }
              local_14 = (undefined4 *)((int)local_14 + 1);
              puVar4 = local_c;
            } while (local_14 < *(undefined4 **)((int)this + 0x98));
          }
          if (*(void **)((int)this + 0x8c) != (void *)0x0) {
            operator_delete(*(void **)((int)this + 0x8c));
          }
          *(int *)((int)this + 0x94) = local_1c;
          *(undefined4 **)((int)this + 0x8c) = local_4;
          *(undefined4 **)((int)this + 0x90) = local_4 + *(int *)((int)this + 0x98);
        }
        if (*(undefined4 **)((int)this + 0x90) != (undefined4 *)0x0) {
          **(undefined4 **)((int)this + 0x90) = puVar2;
        }
        *(int *)((int)this + 0x98) = *(int *)((int)this + 0x98) + 1;
        *(int *)((int)this + 0x90) = *(int *)((int)this + 0x90) + 4;
        local_10 = local_10 + 1;
      } while ((int)local_10 < local_18);
      return CONCAT31((int3)(local_10 >> 8),1);
    }
  }
  else if (local_8 == 1) {
    fread((void *)((int)this + 0x84),4,1,param_1);
    fread((void *)((int)this + 0x80),1,1,param_1);
    fread((void *)((int)this + 0x81),1,1,param_1);
    fread((void *)((int)this + 0x82),1,1,param_1);
    fread(this,0x80,1,param_1);
    local_1c = 0;
    puVar2 = operator_new(0x10);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
    }
    *(undefined4 **)((int)this + 0x88) = puVar2;
    FUN_00466c10(param_1,puVar2);
    fread(&local_1c,4,1,param_1);
    local_c = (undefined4 *)0x0;
    local_8 = local_1c;
    if (0 < local_1c) {
      do {
        puVar2 = operator_new(0x10);
        fread(puVar2,4,1,_File);
        switch(*puVar2) {
        case 0:
        case 4:
        case 5:
        case 6:
        case 8:
          pvVar3 = malloc(4);
          puVar2[1] = pvVar3;
          fread(pvVar3,4,1,_File);
          break;
        case 1:
        case 0xe:
          pvVar3 = malloc(8);
          puVar2[1] = pvVar3;
          fread(pvVar3,8,1,_File);
          break;
        case 2:
          pvVar3 = malloc(8);
          puVar2[1] = pvVar3;
          fread(pvVar3,4,1,_File);
          pvVar3 = operator_new(*(uint *)puVar2[1] & 0xfffffffe);
          *(void **)(puVar2[1] + 4) = pvVar3;
          fread((void *)((size_t *)puVar2[1])[1],*(size_t *)puVar2[1],1,_File);
          break;
        default:
          puVar2[1] = 0;
          break;
        case 7:
          pvVar3 = malloc(0xc);
          puVar2[1] = pvVar3;
          fread(pvVar3,0xc,1,_File);
        }
        fread(puVar2 + 2,4,1,_File);
        if (puVar2[2] == 6) {
          pvVar3 = malloc(4);
          puVar2[3] = pvVar3;
          fread(pvVar3,4,1,_File);
        }
        else {
          puVar2[3] = 0;
        }
        uVar1 = *(uint *)((int)this + 0x98);
        if (uVar1 == *(uint *)((int)this + 0x94)) {
          if (uVar1 + 1 < 5) {
            local_18 = 5;
          }
          else {
            local_18 = uVar1 + 3 + (uVar1 >> 1);
          }
          local_14 = operator_new(local_18 * 4);
          param_1 = *(FILE **)((int)this + 0x8c);
          local_10 = 0;
          puVar4 = local_14;
          if (*(int *)((int)this + 0x98) != 0) {
            do {
              if (puVar4 != (undefined4 *)0x0) {
                *puVar4 = param_1->_ptr;
                param_1 = (FILE *)&param_1->_cnt;
              }
              local_10 = local_10 + 1;
              puVar4 = puVar4 + 1;
            } while (local_10 < *(uint *)((int)this + 0x98));
          }
          if (*(void **)((int)this + 0x8c) != (void *)0x0) {
            operator_delete(*(void **)((int)this + 0x8c));
          }
          *(int *)((int)this + 0x94) = local_18;
          *(undefined4 **)((int)this + 0x8c) = local_14;
          *(undefined4 **)((int)this + 0x90) = local_14 + *(int *)((int)this + 0x98);
        }
        if (*(undefined4 **)((int)this + 0x90) != (undefined4 *)0x0) {
          **(undefined4 **)((int)this + 0x90) = puVar2;
        }
        *(int *)((int)this + 0x98) = *(int *)((int)this + 0x98) + 1;
        local_8 = (int)local_c + 1;
        *(int *)((int)this + 0x90) = *(int *)((int)this + 0x90) + 4;
        local_c = (undefined4 *)local_8;
      } while (local_8 < local_1c);
    }
  }
  return CONCAT31((int3)((uint)local_8 >> 8),1);
}

