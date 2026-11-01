// rea decompile_all
// name: FUN_00675e10
// address: 0x675e10
// body: available
// range: 0x675e10-0x67657f inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e1ad533d4cc0333c2136fe0894217de2d61feea098240326e78633f9e4ddcbf9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00675e10(void)

{
  undefined4 uVar1;
  char cVar2;
  FILE *pFVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  code *pcVar13;
  uint uVar14;
  uint uVar15;
  undefined4 *puVar16;
  char *pcVar17;
  int local_d28;
  undefined4 *local_d24;
  uint local_d20;
  uint local_d1c;
  int local_d18;
  int local_d14;
  undefined1 local_d10 [4];
  undefined4 *local_d0c;
  undefined1 local_d08 [4];
  undefined1 local_d04 [4];
  undefined1 local_d00 [4];
  undefined4 *local_cfc;
  undefined4 *local_cf8;
  uint local_cf4;
  uint local_cf0;
  FILE *local_cec;
  uint local_ce8;
  undefined4 local_ab4 [341];
  undefined1 local_560 [1364];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_008c2169;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pFVar3 = fopen(s_world_targets_sev_0097841c,&DAT_00950990);
  pcVar13 = fread_exref;
  if (pFVar3 != (FILE *)0x0) {
    local_cec = pFVar3;
    fread(&local_d18,1,4,pFVar3);
    local_d28 = 0;
    if (0 < local_d18) {
      do {
        (*pcVar13)(local_d08,1,4,pFVar3);
        (*pcVar13)(local_d04,1,4,pFVar3);
        (*pcVar13)(local_d00,1,0xc,pFVar3);
        (*pcVar13)(&local_cf4,1,4,pFVar3);
        uVar10 = DAT_009bf38c;
        if (DAT_009bf38c == DAT_009bf388) {
          if (DAT_009bf38c + 1 < 5) {
            uVar14 = 5;
          }
          else {
            uVar14 = DAT_009bf38c + 3 + (DAT_009bf38c >> 1);
          }
          local_d1c = uVar14;
          local_d24 = (undefined4 *)thunk_FUN_007631a0(uVar14 * 0x18);
          local_d20 = 0;
          uVar10 = DAT_009bf38c;
          puVar7 = local_d24;
          puVar9 = DAT_009bf380;
          if (DAT_009bf38c != 0) {
            do {
              puVar4 = puVar9;
              if (puVar7 != (undefined4 *)0x0) {
                puVar4 = puVar9 + 6;
                *puVar7 = *puVar9;
                puVar7[1] = puVar9[1];
                FUN_00401cc0(puVar9 + 2);
                puVar7[5] = puVar9[5];
                uVar10 = DAT_009bf38c;
                uVar14 = local_d1c;
              }
              local_d20 = local_d20 + 1;
              puVar7 = puVar7 + 6;
              puVar9 = puVar4;
            } while (local_d20 < uVar10);
          }
          if (DAT_009bf380 != (undefined4 *)0x0) {
            thunk_FUN_007631b0(DAT_009bf380);
            uVar10 = DAT_009bf38c;
          }
          DAT_009bf380 = local_d24;
          DAT_009bf384 = local_d24 + uVar10 * 6;
          pcVar13 = fread_exref;
          pFVar3 = local_cec;
          DAT_009bf388 = uVar14;
        }
        local_4 = 0;
        local_d0c = DAT_009bf384;
        if (DAT_009bf384 != (undefined4 *)0x0) {
          FUN_00676e40(local_d08);
          uVar10 = DAT_009bf38c;
        }
        DAT_009bf38c = uVar10 + 1;
        DAT_009bf384 = DAT_009bf384 + 6;
        local_d28 = local_d28 + 1;
        local_4 = 0xffffffff;
      } while (local_d28 < local_d18);
    }
    fclose(pFVar3);
    pFVar3 = fopen(s_domain_sev_00978410,&DAT_00950990);
    if (pFVar3 != (FILE *)0x0) {
      local_cec = pFVar3;
      (*pcVar13)(&local_d18,1,4,pFVar3);
      local_d28 = 0;
      if (0 < local_d18) {
        do {
          local_cf4 = 0;
          local_cf0 = 0;
          local_cfc = (undefined4 *)0x0;
          local_cf8 = (undefined4 *)0x0;
          local_4._0_1_ = 1;
          local_4._1_3_ = 0;
          (*pcVar13)(local_d08,1,4,pFVar3);
          (*pcVar13)(local_d04,1,4,pFVar3);
          (*pcVar13)(local_d00,1,4,pFVar3);
          (*pcVar13)(&local_d24,1,4,pFVar3);
          local_d20 = 0;
          if (0 < (int)local_d24) {
            do {
              (*pcVar13)(&local_d0c,1,4,pFVar3);
              if (local_cf0 == local_cf4) {
                if (local_cf0 + 1 < 5) {
                  uVar10 = 5;
                }
                else {
                  uVar10 = local_cf0 + 3 + (local_cf0 >> 1);
                }
                puVar4 = (undefined4 *)thunk_FUN_007631a0(uVar10 * 4);
                uVar14 = 0;
                puVar7 = local_cfc;
                puVar9 = puVar4;
                if (local_cf0 != 0) {
                  do {
                    if (puVar9 != (undefined4 *)0x0) {
                      uVar1 = *puVar7;
                      puVar7 = puVar7 + 1;
                      *puVar9 = uVar1;
                    }
                    uVar14 = uVar14 + 1;
                    puVar9 = puVar9 + 1;
                  } while (uVar14 < local_cf0);
                }
                if (local_cfc != (undefined4 *)0x0) {
                  thunk_FUN_007631b0(local_cfc);
                }
                local_cf8 = puVar4 + local_cf0;
                pcVar13 = fread_exref;
                pFVar3 = local_cec;
                local_cfc = puVar4;
                local_cf4 = uVar10;
              }
              if (local_cf8 != (undefined4 *)0x0) {
                *local_cf8 = local_d0c;
              }
              local_cf8 = local_cf8 + 1;
              local_cf0 = local_cf0 + 1;
              local_d20 = local_d20 + 1;
            } while ((int)local_d20 < (int)local_d24);
          }
          uVar10 = DAT_009bf36c;
          if (DAT_009bf36c == DAT_009bf368) {
            if (DAT_009bf36c + 1 < 5) {
              local_d1c = 5;
            }
            else {
              local_d1c = DAT_009bf36c + 3 + (DAT_009bf36c >> 1);
            }
            uVar5 = thunk_FUN_007631a0(local_d1c * 0x1c);
            uVar11 = 0;
            uVar14 = DAT_009bf36c;
            uVar10 = DAT_009bf360;
            uVar15 = uVar5;
            if (DAT_009bf36c != 0) {
              do {
                local_4._0_1_ = 2;
                uVar12 = uVar10;
                local_d20 = uVar15;
                local_ce8 = uVar15;
                if (uVar15 != 0) {
                  uVar12 = uVar10 + 0x1c;
                  FUN_00676f30(uVar10);
                  uVar14 = DAT_009bf36c;
                }
                uVar11 = uVar11 + 1;
                local_4._0_1_ = 1;
                uVar10 = uVar12;
                uVar15 = uVar15 + 0x1c;
              } while (uVar11 < uVar14);
            }
            uVar15 = 0;
            uVar10 = 0;
            if (uVar14 != 0) {
              do {
                FUN_004060e0();
                uVar15 = uVar15 + 1;
                uVar10 = DAT_009bf36c;
              } while (uVar15 < DAT_009bf36c);
            }
            if (DAT_009bf360 != 0) {
              thunk_FUN_007631b0(DAT_009bf360);
              uVar10 = DAT_009bf36c;
            }
            DAT_009bf368 = local_d1c;
            DAT_009bf364 = uVar5 + uVar10 * 0x1c;
            pcVar13 = fread_exref;
            pFVar3 = local_cec;
            DAT_009bf360 = uVar5;
          }
          local_4 = CONCAT31(local_4._1_3_,3);
          local_ce8 = DAT_009bf364;
          if (DAT_009bf364 != 0) {
            FUN_00676f30(local_d08);
            uVar10 = DAT_009bf36c;
          }
          DAT_009bf364 = DAT_009bf364 + 0x1c;
          DAT_009bf36c = uVar10 + 1;
          local_4 = 0xffffffff;
          FUN_006e04e0(local_cfc,local_cfc + local_cf0);
          if (local_cfc != (undefined4 *)0x0) {
            thunk_FUN_007631b0(local_cfc);
          }
          local_d28 = local_d28 + 1;
        } while (local_d28 < local_d18);
      }
      FUN_0076d760();
      local_4 = 4;
      cVar2 = FUN_0076da20(s_gshopsev_data_00978614,0x11);
      if (cVar2 == '\0') {
        pcVar17 = s_GlobalData_Load____Failed_to_ope_00978518;
      }
      else {
        cVar2 = FUN_0076ddc0(&DAT_009bf318,4,local_d10);
        if (cVar2 == '\0') {
LAB_00676333:
          pcVar17 = s_GlobalData_Load____corrupted_gsh_00978468;
        }
        else {
          cVar2 = FUN_0076ddc0(&local_d14,4,local_d10);
          if (cVar2 == '\0') {
            pcVar17 = s_GlobalData_Load____corrupted_gsh_00978468;
          }
          else {
            local_d28 = 0;
            if (0 < local_d14) {
              do {
                cVar2 = FUN_0076ddc0(local_ab4,0x554,local_d10);
                if (cVar2 == '\0') goto LAB_00676333;
                puVar7 = DAT_009bf33c;
                if (DAT_009bf33c == DAT_009bf338) {
                  puVar6 = (undefined4 *)FUN_00677180((int)DAT_009bf33c + 1,&local_d0c);
                  local_d24 = (undefined4 *)0x0;
                  puVar7 = DAT_009bf33c;
                  puVar9 = DAT_009bf330;
                  puVar4 = puVar6;
                  if (DAT_009bf33c != (undefined4 *)0x0) {
                    do {
                      if (puVar4 != (undefined4 *)0x0) {
                        puVar7 = puVar9;
                        puVar16 = puVar4;
                        for (iVar8 = 0x155; iVar8 != 0; iVar8 = iVar8 + -1) {
                          *puVar16 = *puVar7;
                          puVar7 = puVar7 + 1;
                          puVar16 = puVar16 + 1;
                        }
                        puVar9 = puVar9 + 0x155;
                        puVar7 = DAT_009bf33c;
                      }
                      local_d24 = (undefined4 *)((int)local_d24 + 1);
                      puVar4 = puVar4 + 0x155;
                    } while (local_d24 < puVar7);
                  }
                  if (DAT_009bf330 != (undefined4 *)0x0) {
                    thunk_FUN_007631b0(DAT_009bf330);
                    puVar7 = DAT_009bf33c;
                  }
                  DAT_009bf338 = local_d0c;
                  DAT_009bf334 = puVar6 + (int)puVar7 * 0x155;
                  DAT_009bf330 = puVar6;
                }
                if (DAT_009bf334 != (undefined4 *)0x0) {
                  puVar9 = local_ab4;
                  puVar4 = DAT_009bf334;
                  for (iVar8 = 0x155; puVar7 = DAT_009bf33c, iVar8 != 0; iVar8 = iVar8 + -1) {
                    *puVar4 = *puVar9;
                    puVar9 = puVar9 + 1;
                    puVar4 = puVar4 + 1;
                  }
                }
                DAT_009bf33c = (undefined4 *)((int)puVar7 + 1);
                DAT_009bf334 = DAT_009bf334 + 0x155;
                local_d28 = local_d28 + 1;
              } while (local_d28 < local_d14);
            }
            FUN_0076db10();
            cVar2 = FUN_0076da20(s_gshopsev1_data_00978604,0x11);
            if (cVar2 == '\0') {
              pcVar17 = s_GlobalData_Load____Failed_to_ope_009785cc;
            }
            else {
              cVar2 = FUN_0076ddc0(&DAT_009bf3a0,4,local_d10);
              if ((cVar2 != '\0') && (cVar2 = FUN_0076ddc0(&local_d14,4,local_d10), cVar2 != '\0'))
              {
                iVar8 = 0;
                if (0 < local_d14) {
                  do {
                    cVar2 = FUN_0076ddc0(local_560,0x554,local_d10);
                    if (cVar2 == '\0') goto LAB_006764e5;
                    FUN_00676a10(local_560);
                    iVar8 = iVar8 + 1;
                  } while (iVar8 < local_d14);
                }
                FUN_0076db10();
                local_4 = 0xffffffff;
                FUN_0076d7c0();
                ExceptionList = local_c;
                return 1;
              }
LAB_006764e5:
              pcVar17 = s_GlobalData_Load____corrupted_gsh_0097843c;
            }
          }
        }
      }
      FUN_00764590(1,pcVar17);
      local_4 = 0xffffffff;
      FUN_0076d7c0();
    }
  }
  ExceptionList = local_c;
  return 0;
}

