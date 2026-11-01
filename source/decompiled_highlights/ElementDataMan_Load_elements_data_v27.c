// rea decompile_all
// name: FUN_006618f0
// address: 0x6618f0
// body: available
// range: 0x6618f0-0x66398e inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e1ad533d4cc0333c2136fe0894217de2d61feea098240326e78633f9e4ddcbf9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_006618f0(char *param_1)

{
  FILE *_File;
  size_t sVar1;
  int iVar2;
  uint uVar3;
  uint local_c44;
  uint local_c40;
  uint local_c3c;
  size_t local_c38 [2];
  int local_c30;
  undefined1 local_c2c [84];
  undefined1 local_bd8 [4];
  undefined1 local_bd4 [4];
  undefined1 local_bd0 [1528];
  undefined1 local_5d8 [460];
  undefined1 local_40c [1024];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_008c1d3e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  _File = fopen(param_1,&DAT_00950990);
  uVar3 = 0;
  if (_File != (FILE *)0x0) {
    local_c30 = 0;
    fread(&local_c30,4,1,_File);
    if (local_c30 == 0x3000001b) {
      fread(local_bd4,4,1,_File);
      sVar1 = fread(&local_c44,4,1,_File);
      if (sVar1 == 1) {
        if ((local_c44 != 0) && (FUN_0066a330(local_c44), local_c44 != 0)) {
          do {
            sVar1 = fread(local_c2c,0x54,1,_File);
            if (sVar1 != 1) {
              ExceptionList = local_c;
              return 0xffffffff;
            }
            FUN_0066ab90(local_c2c);
            uVar3 = uVar3 + 1;
          } while (uVar3 < local_c44);
        }
        sVar1 = fread(&local_c44,4,1,_File);
        if (sVar1 == 1) {
          if (local_c44 != 0) {
            FUN_00669ae0(local_c44);
            local_c40 = 0;
            if (local_c44 != 0) {
              do {
                sVar1 = fread(local_c2c,0x44,1,_File);
                if (sVar1 != 1) {
                  ExceptionList = local_c;
                  return 0xffffffff;
                }
                FUN_0066b3b0(local_c2c);
                local_c40 = local_c40 + 1;
              } while (local_c40 < local_c44);
            }
          }
          sVar1 = fread(&local_c44,4,1,_File);
          if (sVar1 == 1) {
            if (local_c44 != 0) {
              FUN_00669570(local_c44);
              local_c40 = 0;
              if (local_c44 != 0) {
                do {
                  sVar1 = fread(local_bd0,0x164,1,_File);
                  if (sVar1 != 1) {
                    ExceptionList = local_c;
                    return 0xffffffff;
                  }
                  FUN_0066ac80(local_bd0);
                  local_c40 = local_c40 + 1;
                } while (local_c40 < local_c44);
              }
            }
            sVar1 = fread(&local_c44,4,1,_File);
            if (sVar1 == 1) {
              if (local_c44 != 0) {
                FUN_00669630(local_c44);
                local_c40 = 0;
                if (local_c44 != 0) {
                  do {
                    sVar1 = fread(local_bd0,0x584,1,_File);
                    if (sVar1 != 1) {
                      ExceptionList = local_c;
                      return 0xffffffff;
                    }
                    FUN_0066ad60(local_bd0);
                    local_c40 = local_c40 + 1;
                  } while (local_c40 < local_c44);
                }
              }
              sVar1 = fread(&local_c44,4,1,_File);
              if (sVar1 == 1) {
                if (local_c44 != 0) {
                  FUN_00669ae0(local_c44);
                  local_c40 = 0;
                  if (local_c44 != 0) {
                    do {
                      sVar1 = fread(local_c2c,0x44,1,_File);
                      if (sVar1 != 1) {
                        ExceptionList = local_c;
                        return 0xffffffff;
                      }
                      FUN_0066b3b0(local_c2c);
                      local_c40 = local_c40 + 1;
                    } while (local_c40 < local_c44);
                  }
                }
                sVar1 = fread(&local_c44,4,1,_File);
                if (sVar1 == 1) {
                  if (local_c44 != 0) {
                    FUN_0066a630(local_c44);
                    local_c40 = 0;
                    if (local_c44 != 0) {
                      do {
                        sVar1 = fread(local_c2c,0x48,1,_File);
                        if (sVar1 != 1) {
                          ExceptionList = local_c;
                          return 0xffffffff;
                        }
                        FUN_0066be60(local_c2c);
                        local_c40 = local_c40 + 1;
                      } while (local_c40 < local_c44);
                    }
                  }
                  sVar1 = fread(&local_c44,4,1,_File);
                  if (sVar1 == 1) {
                    if (local_c44 != 0) {
                      FUN_00669700(local_c44);
                      local_c40 = 0;
                      if (local_c44 != 0) {
                        do {
                          sVar1 = fread(local_bd0,0x460,1,_File);
                          if (sVar1 != 1) {
                            ExceptionList = local_c;
                            return 0xffffffff;
                          }
                          FUN_0066ae50(local_bd0);
                          local_c40 = local_c40 + 1;
                        } while (local_c40 < local_c44);
                      }
                    }
                    sVar1 = fread(&local_c44,4,1,_File);
                    if (sVar1 == 1) {
                      if (local_c44 != 0) {
                        FUN_00669ae0(local_c44);
                        local_c40 = 0;
                        if (local_c44 != 0) {
                          do {
                            sVar1 = fread(local_c2c,0x44,1,_File);
                            if (sVar1 != 1) {
                              ExceptionList = local_c;
                              return 0xffffffff;
                            }
                            FUN_0066b3b0(local_c2c);
                            local_c40 = local_c40 + 1;
                          } while (local_c40 < local_c44);
                        }
                      }
                      sVar1 = fread(&local_c44,4,1,_File);
                      if (sVar1 == 1) {
                        if (local_c44 != 0) {
                          FUN_0066a630(local_c44);
                          local_c40 = 0;
                          if (local_c44 != 0) {
                            do {
                              sVar1 = fread(local_c2c,0x48,1,_File);
                              if (sVar1 != 1) {
                                ExceptionList = local_c;
                                return 0xffffffff;
                              }
                              FUN_0066be60(local_c2c);
                              local_c40 = local_c40 + 1;
                            } while (local_c40 < local_c44);
                          }
                        }
                        sVar1 = fread(&local_c44,4,1,_File);
                        if (sVar1 == 1) {
                          if (local_c44 != 0) {
                            FUN_006697d0(local_c44);
                            local_c40 = 0;
                            if (local_c44 != 0) {
                              do {
                                sVar1 = fread(local_bd0,0x48c,1,_File);
                                if (sVar1 != 1) {
                                  ExceptionList = local_c;
                                  return 0xffffffff;
                                }
                                FUN_0066af40(local_bd0);
                                local_c40 = local_c40 + 1;
                              } while (local_c40 < local_c44);
                            }
                          }
                          sVar1 = fread(&local_c44,4,1,_File);
                          if (sVar1 == 1) {
                            if (local_c44 != 0) {
                              FUN_00669ae0(local_c44);
                              local_c40 = 0;
                              if (local_c44 != 0) {
                                do {
                                  sVar1 = fread(local_c2c,0x44,1,_File);
                                  if (sVar1 != 1) {
                                    ExceptionList = local_c;
                                    return 0xffffffff;
                                  }
                                  FUN_0066b3b0(local_c2c);
                                  local_c40 = local_c40 + 1;
                                } while (local_c40 < local_c44);
                              }
                            }
                            sVar1 = fread(&local_c44,4,1,_File);
                            if (sVar1 == 1) {
                              if (local_c44 != 0) {
                                FUN_00669ae0(local_c44);
                                local_c40 = 0;
                                if (local_c44 != 0) {
                                  do {
                                    sVar1 = fread(local_c2c,0x44,1,_File);
                                    if (sVar1 != 1) {
                                      ExceptionList = local_c;
                                      return 0xffffffff;
                                    }
                                    FUN_0066b3b0(local_c2c);
                                    local_c40 = local_c40 + 1;
                                  } while (local_c40 < local_c44);
                                }
                              }
                              sVar1 = fread(&local_c44,4,1,_File);
                              if (sVar1 == 1) {
                                if (local_c44 != 0) {
                                  FUN_006698a0(local_c44);
                                  local_c40 = 0;
                                  if (local_c44 != 0) {
                                    do {
                                      sVar1 = fread(local_bd0,0x178,1,_File);
                                      if (sVar1 != 1) {
                                        ExceptionList = local_c;
                                        return 0xffffffff;
                                      }
                                      FUN_0066b030(local_bd0);
                                      local_c40 = local_c40 + 1;
                                    } while (local_c40 < local_c44);
                                  }
                                }
                                sVar1 = fread(&local_c44,4,1,_File);
                                if (sVar1 == 1) {
                                  if (local_c44 != 0) {
                                    FUN_00669ae0(local_c44);
                                    local_c40 = 0;
                                    if (local_c44 != 0) {
                                      do {
                                        sVar1 = fread(local_c2c,0x44,1,_File);
                                        if (sVar1 != 1) {
                                          ExceptionList = local_c;
                                          return 0xffffffff;
                                        }
                                        FUN_0066b3b0(local_c2c);
                                        local_c40 = local_c40 + 1;
                                      } while (local_c40 < local_c44);
                                    }
                                  }
                                  sVar1 = fread(&local_c44,4,1,_File);
                                  if (sVar1 == 1) {
                                    if (local_c44 != 0) {
                                      FUN_00669ae0(local_c44);
                                      local_c40 = 0;
                                      if (local_c44 != 0) {
                                        do {
                                          sVar1 = fread(local_c2c,0x44,1,_File);
                                          if (sVar1 != 1) {
                                            ExceptionList = local_c;
                                            return 0xffffffff;
                                          }
                                          FUN_0066b3b0(local_c2c);
                                          local_c40 = local_c40 + 1;
                                        } while (local_c40 < local_c44);
                                      }
                                    }
                                    sVar1 = fread(&local_c44,4,1,_File);
                                    if (sVar1 == 1) {
                                      if (local_c44 != 0) {
                                        FUN_00669960(local_c44);
                                        local_c40 = 0;
                                        if (local_c44 != 0) {
                                          do {
                                            sVar1 = fread(local_bd0,0x170,1,_File);
                                            if (sVar1 != 1) {
                                              ExceptionList = local_c;
                                              return 0xffffffff;
                                            }
                                            FUN_0066b110(local_bd0);
                                            local_c40 = local_c40 + 1;
                                          } while (local_c40 < local_c44);
                                        }
                                      }
                                      sVar1 = fread(&local_c44,4,1,_File);
                                      if (sVar1 == 1) {
                                        if (local_c44 != 0) {
                                          FUN_00669ae0(local_c44);
                                          local_c40 = 0;
                                          if (local_c44 != 0) {
                                            do {
                                              sVar1 = fread(local_c2c,0x44,1,_File);
                                              if (sVar1 != 1) {
                                                ExceptionList = local_c;
                                                return 0xffffffff;
                                              }
                                              FUN_0066b3b0(local_c2c);
                                              local_c40 = local_c40 + 1;
                                            } while (local_c40 < local_c44);
                                          }
                                        }
                                        sVar1 = fread(&local_c44,4,1,_File);
                                        if (sVar1 == 1) {
                                          if (local_c44 != 0) {
                                            FUN_00669a20(local_c44);
                                            local_c40 = 0;
                                            if (local_c44 != 0) {
                                              do {
                                                sVar1 = fread(local_bd0,0x16c,1,_File);
                                                if (sVar1 != 1) {
                                                  ExceptionList = local_c;
                                                  return 0xffffffff;
                                                }
                                                FUN_0066b1f0(local_bd0);
                                                local_c40 = local_c40 + 1;
                                              } while (local_c40 < local_c44);
                                            }
                                          }
                                          sVar1 = fread(&local_c44,4,1,_File);
                                          if (sVar1 == 1) {
                                            if (local_c44 != 0) {
                                              FUN_00669ae0(local_c44);
                                              local_c40 = 0;
                                              if (local_c44 != 0) {
                                                do {
                                                  sVar1 = fread(local_c2c,0x44,1,_File);
                                                  if (sVar1 != 1) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  FUN_0066b3b0(local_c2c);
                                                  local_c40 = local_c40 + 1;
                                                } while (local_c40 < local_c44);
                                              }
                                            }
                                            sVar1 = fread(&local_c44,4,1,_File);
                                            if (sVar1 == 1) {
                                              if (local_c44 != 0) {
                                                FUN_00669b90(local_c44);
                                                local_c40 = 0;
                                                if (local_c44 != 0) {
                                                  do {
                                                    sVar1 = fread(local_bd0,0x270,1,_File);
                                                    if (sVar1 != 1) {
                                                      ExceptionList = local_c;
                                                      return 0xffffffff;
                                                    }
                                                    FUN_0066b2d0(local_bd0);
                                                    local_c40 = local_c40 + 1;
                                                  } while (local_c40 < local_c44);
                                                }
                                              }
                                              fread(local_bd8,4,1,_File);
                                              fread(local_c38,4,1,_File);
                                              fread(local_40c,local_c38[0],1,_File);
                                              fread(local_bd4,4,1,_File);
                                              sVar1 = fread(&local_c44,4,1,_File);
                                              if (sVar1 == 1) {
                                                if (local_c44 != 0) {
                                                  FUN_00669ae0(local_c44);
                                                  local_c40 = 0;
                                                  if (local_c44 != 0) {
                                                    do {
                                                      sVar1 = fread(local_c2c,0x44,1,_File);
                                                      if (sVar1 != 1) {
                                                        ExceptionList = local_c;
                                                        return 0xffffffff;
                                                      }
                                                      FUN_0066b3b0(local_c2c);
                                                      local_c40 = local_c40 + 1;
                                                    } while (local_c40 < local_c44);
                                                  }
                                                }
                                                sVar1 = fread(&local_c44,4,1,_File);
                                                if (sVar1 == 1) {
                                                  if (local_c44 != 0) {
                                                    FUN_00669c50(local_c44);
                                                    local_c40 = 0;
                                                    if (local_c44 != 0) {
                                                      do {
                                                        sVar1 = fread(local_bd0,0x15c,1,_File);
                                                        if (sVar1 != 1) {
                                                          ExceptionList = local_c;
                                                          return 0xffffffff;
                                                        }
                                                        FUN_0066b490(local_bd0);
                                                        local_c40 = local_c40 + 1;
                                                      } while (local_c40 < local_c44);
                                                    }
                                                  }
                                                  sVar1 = fread(&local_c44,4,1,_File);
                                                  if (sVar1 == 1) {
                                                    if (local_c44 != 0) {
                                                      FUN_00669d20(local_c44);
                                                      local_c40 = 0;
                                                      if (local_c44 != 0) {
                                                        do {
                                                          sVar1 = fread(local_bd0,0x20c,1,_File);
                                                          if (sVar1 != 1) {
                                                            ExceptionList = local_c;
                                                            return 0xffffffff;
                                                          }
                                                          FUN_0066b580(local_bd0);
                                                          local_c40 = local_c40 + 1;
                                                        } while (local_c40 < local_c44);
                                                      }
                                                    }
                                                    sVar1 = fread(&local_c44,4,1,_File);
                                                    if (sVar1 == 1) {
                                                      if (local_c44 != 0) {
                                                        FUN_00669de0(local_c44);
                                                        local_c40 = 0;
                                                        if (local_c44 != 0) {
                                                          do {
                                                            sVar1 = fread(local_bd0,0x1e8,1,_File);
                                                            if (sVar1 != 1) {
                                                              ExceptionList = local_c;
                                                              return 0xffffffff;
                                                            }
                                                            FUN_0066b660(local_bd0);
                                                            local_c40 = local_c40 + 1;
                                                          } while (local_c40 < local_c44);
                                                        }
                                                      }
                                                      sVar1 = fread(&local_c44,4,1,_File);
                                                      if (sVar1 == 1) {
                                                        if (local_c44 != 0) {
                                                          FUN_00669c50(local_c44);
                                                          local_c40 = 0;
                                                          if (local_c44 != 0) {
                                                            do {
                                                              sVar1 = fread(local_bd0,0x15c,1,_File)
                                                              ;
                                                              if (sVar1 != 1) {
                                                                ExceptionList = local_c;
                                                                return 0xffffffff;
                                                              }
                                                              FUN_0066b490(local_bd0);
                                                              local_c40 = local_c40 + 1;
                                                            } while (local_c40 < local_c44);
                                                          }
                                                        }
                                                        sVar1 = fread(&local_c44,4,1,_File);
                                                        if (sVar1 == 1) {
                                                          if (local_c44 != 0) {
                                                            FUN_00669c50(local_c44);
                                                            local_c40 = 0;
                                                            if (local_c44 != 0) {
                                                              do {
                                                                sVar1 = fread(local_bd0,0x15c,1,
                                                                              _File);
                                                                if (sVar1 != 1) {
                                                                  ExceptionList = local_c;
                                                                  return 0xffffffff;
                                                                }
                                                                FUN_0066b490(local_bd0);
                                                                local_c40 = local_c40 + 1;
                                                              } while (local_c40 < local_c44);
                                                            }
                                                          }
                                                          sVar1 = fread(&local_c44,4,1,_File);
                                                          if (sVar1 == 1) {
                                                            if (local_c44 != 0) {
                                                              FUN_00669ea0(local_c44);
                                                              local_c40 = 0;
                                                              if (local_c44 != 0) {
                                                                do {
                                                                  sVar1 = fread(local_bd0,0x160,1,
                                                                                _File);
                                                                  if (sVar1 != 1) {
                                                                    ExceptionList = local_c;
                                                                    return 0xffffffff;
                                                                  }
                                                                  FUN_0066b740(local_bd0);
                                                                  local_c40 = local_c40 + 1;
                                                                } while (local_c40 < local_c44);
                                                              }
                                                            }
                                                            sVar1 = fread(&local_c44,4,1,_File);
                                                            if (sVar1 == 1) {
                                                              if (local_c44 != 0) {
                                                                FUN_00669c50(local_c44);
                                                                local_c40 = 0;
                                                                if (local_c44 != 0) {
                                                                  do {
                                                                    sVar1 = fread(local_bd0,0x15c,1,
                                                                                  _File);
                                                                    if (sVar1 != 1) {
                                                                      ExceptionList = local_c;
                                                                      return 0xffffffff;
                                                                    }
                                                                    FUN_0066b490(local_bd0);
                                                                    local_c40 = local_c40 + 1;
                                                                  } while (local_c40 < local_c44);
                                                                }
                                                              }
                                                              sVar1 = fread(&local_c44,4,1,_File);
                                                              if (sVar1 == 1) {
                                                                if (local_c44 != 0) {
                                                                  FUN_00669f60(local_c44);
                                                                  local_c40 = 0;
                                                                  if (local_c44 != 0) {
                                                                    do {
                                                                      sVar1 = fread(local_bd0,0xd0,1
                                                                                    ,_File);
                                                                      if (sVar1 != 1) {
                                                                        ExceptionList = local_c;
                                                                        return 0xffffffff;
                                                                      }
                                                                      FUN_0066b820(local_bd0);
                                                                      local_c40 = local_c40 + 1;
                                                                    } while (local_c40 < local_c44);
                                                                  }
                                                                }
                                                                sVar1 = fread(&local_c44,4,1,_File);
                                                                if (sVar1 == 1) {
                                                                  if (local_c44 != 0) {
                                                                    FUN_0066a020(local_c44);
                                                                    local_c40 = 0;
                                                                    if (local_c44 != 0) {
                                                                      do {
                                                                        sVar1 = fread(local_bd0,
                                                                                      0x378,1,_File)
                                                                        ;
                                                                        if (sVar1 != 1) {
                                                                          ExceptionList = local_c;
                                                                          return 0xffffffff;
                                                                        }
                                                                        FUN_0066b900(local_bd0);
                                                                        local_c40 = local_c40 + 1;
                                                                      } while (local_c40 < local_c44
                                                                              );
                                                                    }
                                                                  }
                                                                  sVar1 = fread(&local_c44,4,1,_File
                                                                               );
                                                                  if (sVar1 == 1) {
                                                                    if (local_c44 != 0) {
                                                                      FUN_00669ae0(local_c44);
                                                                      local_c40 = 0;
                                                                      if (local_c44 != 0) {
                                                                        do {
                                                                          sVar1 = fread(local_c2c,
                                                                                        0x44,1,_File
                                                                                       );
                                                                          if (sVar1 != 1) {
                                                                            ExceptionList = local_c;
                                                                            return 0xffffffff;
                                                                          }
                                                                          FUN_0066b3b0(local_c2c);
                                                                          local_c40 = local_c40 + 1;
                                                                        } while (local_c40 <
                                                                                 local_c44);
                                                                      }
                                                                    }
                                                                    sVar1 = fread(&local_c44,4,1,
                                                                                  _File);
                                                                    if (sVar1 == 1) {
                                                                      if (local_c44 != 0) {
                                                                        FUN_0066a0e0(local_c44);
                                                                        local_c40 = 0;
                                                                        if (local_c44 != 0) {
                                                                          do {
                                                                            sVar1 = fread(local_bd0,
                                                                                          0x37c,1,
                                                  _File);
                                                  if (sVar1 != 1) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  FUN_0066b9e0(local_bd0);
                                                  local_c40 = local_c40 + 1;
                                                  } while (local_c40 < local_c44);
                                                  }
                                                  }
                                                  sVar1 = fread(&local_c44,4,1,_File);
                                                  if (sVar1 == 1) {
                                                    if (local_c44 != 0) {
                                                      FUN_00669ae0(local_c44);
                                                      local_c40 = 0;
                                                      if (local_c44 != 0) {
                                                        do {
                                                          sVar1 = fread(local_c2c,0x44,1,_File);
                                                          if (sVar1 != 1) {
                                                            ExceptionList = local_c;
                                                            return 0xffffffff;
                                                          }
                                                          FUN_0066b3b0(local_c2c);
                                                          local_c40 = local_c40 + 1;
                                                        } while (local_c40 < local_c44);
                                                      }
                                                    }
                                                    sVar1 = fread(&local_c44,4,1,_File);
                                                    if (sVar1 == 1) {
                                                      if (local_c44 != 0) {
                                                        FUN_0066a1b0(local_c44);
                                                        local_c40 = 0;
                                                        if (local_c44 != 0) {
                                                          do {
                                                            sVar1 = fread(local_bd0,0x154,1,_File);
                                                            if (sVar1 != 1) {
                                                              ExceptionList = local_c;
                                                              return 0xffffffff;
                                                            }
                                                            FUN_0066bad0(local_bd0);
                                                            local_c40 = local_c40 + 1;
                                                          } while (local_c40 < local_c44);
                                                        }
                                                      }
                                                      sVar1 = fread(&local_c44,4,1,_File);
                                                      if (sVar1 == 1) {
                                                        if (local_c44 != 0) {
                                                          FUN_00669ae0(local_c44);
                                                          local_c40 = 0;
                                                          if (local_c44 != 0) {
                                                            do {
                                                              sVar1 = fread(local_c2c,0x44,1,_File);
                                                              if (sVar1 != 1) {
                                                                ExceptionList = local_c;
                                                                return 0xffffffff;
                                                              }
                                                              FUN_0066b3b0(local_c2c);
                                                              local_c40 = local_c40 + 1;
                                                            } while (local_c40 < local_c44);
                                                          }
                                                        }
                                                        sVar1 = fread(&local_c44,4,1,_File);
                                                        if (sVar1 == 1) {
                                                          if (local_c44 != 0) {
                                                            FUN_0066a270(local_c44);
                                                            local_c40 = 0;
                                                            if (local_c44 != 0) {
                                                              do {
                                                                sVar1 = fread(local_bd0,0x1b4,1,
                                                                              _File);
                                                                if (sVar1 != 1) {
                                                                  ExceptionList = local_c;
                                                                  return 0xffffffff;
                                                                }
                                                                FUN_0066bbc0(local_bd0);
                                                                local_c40 = local_c40 + 1;
                                                              } while (local_c40 < local_c44);
                                                            }
                                                          }
                                                          sVar1 = fread(&local_c44,4,1,_File);
                                                          if (sVar1 == 1) {
                                                            if (local_c44 != 0) {
                                                              FUN_0066a330(local_c44);
                                                              local_c40 = 0;
                                                              if (local_c44 != 0) {
                                                                do {
                                                                  sVar1 = fread(local_c2c,0x54,1,
                                                                                _File);
                                                                  if (sVar1 != 1) {
                                                                    ExceptionList = local_c;
                                                                    return 0xffffffff;
                                                                  }
                                                                  FUN_0066ab90(local_c2c);
                                                                  local_c40 = local_c40 + 1;
                                                                } while (local_c40 < local_c44);
                                                              }
                                                            }
                                                            sVar1 = fread(&local_c44,4,1,_File);
                                                            if (sVar1 == 1) {
                                                              if (local_c44 != 0) {
                                                                FUN_0066a3f0(local_c44);
                                                                local_c40 = 0;
                                                                if (local_c44 != 0) {
                                                                  do {
                                                                    sVar1 = fread(local_bd0,0xc4,1,
                                                                                  _File);
                                                                    if (sVar1 != 1) {
                                                                      ExceptionList = local_c;
                                                                      return 0xffffffff;
                                                                    }
                                                                    FUN_0066bca0(local_bd0);
                                                                    local_c40 = local_c40 + 1;
                                                                  } while (local_c40 < local_c44);
                                                                }
                                                              }
                                                              sVar1 = fread(&local_c44,4,1,_File);
                                                              if (sVar1 == 1) {
                                                                if (local_c44 != 0) {
                                                                  FUN_0066a4b0(local_c44);
                                                                  local_c40 = 0;
                                                                  if (local_c44 != 0) {
                                                                    do {
                                                                      sVar1 = fread(local_bd0,0x5f8,
                                                                                    1,_File);
                                                                      if (sVar1 != 1) {
                                                                        ExceptionList = local_c;
                                                                        return 0xffffffff;
                                                                      }
                                                                      FUN_0066bd80(local_bd0);
                                                                      local_c40 = local_c40 + 1;
                                                                    } while (local_c40 < local_c44);
                                                                  }
                                                                }
                                                                sVar1 = fread(&local_c44,4,1,_File);
                                                                if (sVar1 == 1) {
                                                                  if (local_c44 != 0) {
                                                                    FUN_0066a630(local_c44);
                                                                    local_c40 = 0;
                                                                    if (local_c44 != 0) {
                                                                      do {
                                                                        sVar1 = fread(local_c2c,0x48
                                                                                      ,1,_File);
                                                                        if (sVar1 != 1) {
                                                                          ExceptionList = local_c;
                                                                          return 0xffffffff;
                                                                        }
                                                                        FUN_0066be60(local_c2c);
                                                                        local_c40 = local_c40 + 1;
                                                                      } while (local_c40 < local_c44
                                                                              );
                                                                    }
                                                                  }
                                                                  sVar1 = fread(&local_c44,4,1,_File
                                                                               );
                                                                  if (sVar1 == 1) {
                                                                    if (local_c44 != 0) {
                                                                      FUN_0066a570(local_c44);
                                                                      local_c40 = 0;
                                                                      if (local_c44 != 0) {
                                                                        do {
                                                                          sVar1 = fread(local_bd0,
                                                                                        0x4c8,1,
                                                  _File);
                                                  if (sVar1 != 1) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  FUN_0066bf30(local_bd0);
                                                  local_c40 = local_c40 + 1;
                                                  } while (local_c40 < local_c44);
                                                  }
                                                  }
                                                  sVar1 = fread(&local_c44,4,1,_File);
                                                  if (sVar1 == 1) {
                                                    if (local_c44 != 0) {
                                                      FUN_0066a630(local_c44);
                                                      local_c40 = 0;
                                                      if (local_c44 != 0) {
                                                        do {
                                                          sVar1 = fread(local_c2c,0x48,1,_File);
                                                          if (sVar1 != 1) {
                                                            ExceptionList = local_c;
                                                            return 0xffffffff;
                                                          }
                                                          FUN_0066be60(local_c2c);
                                                          local_c40 = local_c40 + 1;
                                                        } while (local_c40 < local_c44);
                                                      }
                                                    }
                                                    sVar1 = fread(&local_c44,4,1,_File);
                                                    if (sVar1 == 1) {
                                                      if (local_c44 != 0) {
                                                        FUN_0066a630(local_c44);
                                                        local_c40 = 0;
                                                        if (local_c44 != 0) {
                                                          do {
                                                            sVar1 = fread(local_c2c,0x48,1,_File);
                                                            if (sVar1 != 1) {
                                                              ExceptionList = local_c;
                                                              return 0xffffffff;
                                                            }
                                                            FUN_0066be60(local_c2c);
                                                            local_c40 = local_c40 + 1;
                                                          } while (local_c40 < local_c44);
                                                        }
                                                      }
                                                      sVar1 = fread(&local_c44,4,1,_File);
                                                      if (sVar1 == 1) {
                                                        if (local_c44 != 0) {
                                                          FUN_0066a6e0(local_c44);
                                                          local_c40 = 0;
                                                          if (local_c44 != 0) {
                                                            do {
                                                              sVar1 = fread(local_bd0,200,1,_File);
                                                              if (sVar1 != 1) {
                                                                ExceptionList = local_c;
                                                                return 0xffffffff;
                                                              }
                                                              FUN_0066c020(local_bd0);
                                                              local_c40 = local_c40 + 1;
                                                            } while (local_c40 < local_c44);
                                                          }
                                                        }
                                                        sVar1 = fread(&local_c44,4,1,_File);
                                                        if (sVar1 == 1) {
                                                          if (local_c44 != 0) {
                                                            FUN_0066a6e0(local_c44);
                                                            local_c40 = 0;
                                                            if (local_c44 != 0) {
                                                              do {
                                                                sVar1 = fread(local_bd0,200,1,_File)
                                                                ;
                                                                if (sVar1 != 1) {
                                                                  ExceptionList = local_c;
                                                                  return 0xffffffff;
                                                                }
                                                                FUN_0066c020(local_bd0);
                                                                local_c40 = local_c40 + 1;
                                                              } while (local_c40 < local_c44);
                                                            }
                                                          }
                                                          sVar1 = fread(&local_c44,4,1,_File);
                                                          if (sVar1 == 1) {
                                                            if (local_c44 != 0) {
                                                              FUN_0066a7a0(local_c44);
                                                              local_c40 = 0;
                                                              if (local_c44 != 0) {
                                                                do {
                                                                  sVar1 = fread(local_bd0,0x444,1,
                                                                                _File);
                                                                  if (sVar1 != 1) {
                                                                    ExceptionList = local_c;
                                                                    return 0xffffffff;
                                                                  }
                                                                  FUN_0066c100(local_bd0);
                                                                  local_c40 = local_c40 + 1;
                                                                } while (local_c40 < local_c44);
                                                              }
                                                            }
                                                            sVar1 = fread(&local_c44,4,1,_File);
                                                            if (sVar1 == 1) {
                                                              if (local_c44 != 0) {
                                                                FUN_0066a7a0(local_c44);
                                                                local_c40 = 0;
                                                                if (local_c44 != 0) {
                                                                  do {
                                                                    sVar1 = fread(local_bd0,0x444,1,
                                                                                  _File);
                                                                    if (sVar1 != 1) {
                                                                      ExceptionList = local_c;
                                                                      return 0xffffffff;
                                                                    }
                                                                    FUN_0066c100(local_bd0);
                                                                    local_c40 = local_c40 + 1;
                                                                  } while (local_c40 < local_c44);
                                                                }
                                                              }
                                                              sVar1 = fread(&local_c44,4,1,_File);
                                                              if (sVar1 == 1) {
                                                                if (local_c44 != 0) {
                                                                  FUN_0066a870(local_c44);
                                                                  local_c40 = 0;
                                                                  if (local_c44 != 0) {
                                                                    do {
                                                                      sVar1 = fread(local_bd0,0x284,
                                                                                    1,_File);
                                                                      if (sVar1 != 1) {
                                                                        ExceptionList = local_c;
                                                                        return 0xffffffff;
                                                                      }
                                                                      FUN_0066c1f0(local_bd0);
                                                                      local_c40 = local_c40 + 1;
                                                                    } while (local_c40 < local_c44);
                                                                  }
                                                                }
                                                                sVar1 = fread(&local_c44,4,1,_File);
                                                                if (sVar1 == 1) {
                                                                  if (local_c44 != 0) {
                                                                    FUN_0066a930(local_c44);
                                                                    local_c40 = 0;
                                                                    if (local_c44 != 0) {
                                                                      do {
                                                                        sVar1 = fread(local_bd0,
                                                                                      0x248,1,_File)
                                                                        ;
                                                                        if (sVar1 != 1) {
                                                                          ExceptionList = local_c;
                                                                          return 0xffffffff;
                                                                        }
                                                                        FUN_0066c2d0(local_bd0);
                                                                        local_c40 = local_c40 + 1;
                                                                      } while (local_c40 < local_c44
                                                                              );
                                                                    }
                                                                  }
                                                                  sVar1 = fread(&local_c44,4,1,_File
                                                                               );
                                                                  if (sVar1 == 1) {
                                                                    if (local_c44 != 0) {
                                                                      FUN_0066a630(local_c44);
                                                                      local_c40 = 0;
                                                                      if (local_c44 != 0) {
                                                                        do {
                                                                          sVar1 = fread(local_c2c,
                                                                                        0x48,1,_File
                                                                                       );
                                                                          if (sVar1 != 1) {
                                                                            ExceptionList = local_c;
                                                                            return 0xffffffff;
                                                                          }
                                                                          FUN_0066be60(local_c2c);
                                                                          local_c40 = local_c40 + 1;
                                                                        } while (local_c40 <
                                                                                 local_c44);
                                                                      }
                                                                    }
                                                                    sVar1 = fread(&local_c40,4,1,
                                                                                  _File);
                                                                    if (sVar1 == 1) {
                                                                      if (local_c40 != 0) {
                                                                        FUN_0066a9f0(local_c40);
                                                                        local_c44 = 0;
                                                                        if (local_c40 != 0) {
                                                                          do {
                                                                            sVar1 = fread(local_5d8,
                                                                                          0x1cc,1,
                                                  _File);
                                                  if (sVar1 != 1) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  FUN_0066c3b0(local_5d8);
                                                  local_c44 = local_c44 + 1;
                                                  } while (local_c44 < local_c40);
                                                  }
                                                  }
                                                  iVar2 = FUN_00663b40(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00663d50(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666da0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00663f30(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00663d50(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666da0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00664160(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  local_c3c = 0;
                                                  sVar1 = fread(&local_c3c,4,1,_File);
                                                  if (sVar1 != 1) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  uVar3 = 0;
                                                  if (local_c3c != 0) {
                                                    do {
                                                      local_c44 = thunk_FUN_007631a0(0x8c);
                                                      local_4 = 0;
                                                      if (local_c44 == 0) {
                                                        iVar2 = 0;
                                                      }
                                                      else {
                                                        iVar2 = FUN_00663990();
                                                      }
                                                      local_4 = 0xffffffff;
                                                      FUN_006639b0(_File);
                                                      FUN_0065d1d0(*(undefined4 *)(iVar2 + 0x80),
                                                                   iVar2);
                                                      uVar3 = uVar3 + 1;
                                                    } while (uVar3 < local_c3c);
                                                  }
                                                  iVar2 = FUN_00664380(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_006645c0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_006654a0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_006647f0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00664a20(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00664c40(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00664e60(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00665070(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666da0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666da0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00665290(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_006654a0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_006656d0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_006658f0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00665b30(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00665d70(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666f90(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00664c40(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00665ff0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666da0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666250(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00663d50(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666da0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00663d50(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_006664b0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666da0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666da0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666700(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666da0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666da0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666940(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666b90(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666da0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666f90(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666da0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_006671e0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00667410(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00668a50(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666f90(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_006671e0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666f90(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  fread(local_bd8,4,1,_File);
                                                  fread(local_c38,4,1,_File);
                                                  fread(local_40c,local_c38[0],1,_File);
                                                  iVar2 = FUN_00667670(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00669310(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_006678a0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00668170(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00667b00(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00668170(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00667d10(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00667f50(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666f90(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00668170(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00668170(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00668170(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00668360(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_006645c0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00667d10(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00667d10(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_006645c0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666f90(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_006678a0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_006685d0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666da0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00668360(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00668840(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00668a50(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00668c80(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00666f90(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00668ea0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_006690d0(_File);
                                                  if (iVar2 != 0) {
                                                    ExceptionList = local_c;
                                                    return 0xffffffff;
                                                  }
                                                  iVar2 = FUN_00669310(_File);
                                                  if (iVar2 == 0) {
                                                    FUN_0065e710();
                                                    fclose(_File);
                                                    ExceptionList = local_c;
                                                    return 0;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  ExceptionList = local_c;
  return 0xffffffff;
}

