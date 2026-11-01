// rea decompile_all
// name: FUN_0042d700
// address: 0x42d700
// body: available
// range: 0x42d700-0x42e2f2 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: e1ad533d4cc0333c2136fe0894217de2d61feea098240326e78633f9e4ddcbf9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; The imported Program and temporary project are ephemeral and deleted on close. Annotation operations edit session database metadata; original executable bytes are never written.; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0042d700(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  wchar_t *_Source;
  int in_ECX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined1 local_20;
  undefined1 uStack_1f;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined1 local_15;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined1 local_11;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_008a7d37;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00764590(1,s_Build_version__d_00951ef0,DAT_00951a7c);
  DAT_009b3ee8 = GetCurrentThreadId();
  FUN_0042e300();
  FUN_0042e310();
  iVar2 = GNET::ElementSkill::GetVersion();
  if (iVar2 == 0xf) {
    puVar4 = param_1;
    puVar5 = (undefined4 *)(in_ECX + 0x270);
    for (iVar2 = 0x87; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    FUN_00764c80();
    *(undefined **)(in_ECX + 0x18) = &DAT_009b4d48;
    cVar1 = FUN_0042fe30();
    if (cVar1 == '\0') {
      FUN_0043c590(4,s_CECGame__Init_00951eb0,0x15d);
    }
    else {
      cVar1 = FUN_0042ec80();
      if (cVar1 == '\0') {
        FUN_00764590(1,s_CECGame__Init__failed_to_create_f_00951e88);
      }
      param_1 = (undefined4 *)thunk_FUN_007631a0(0x248);
      local_4 = 0;
      if (param_1 == (undefined4 *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = FUN_006e69e0();
      }
      local_4 = 0xffffffff;
      *(undefined4 *)(in_ECX + 0x28) = uVar3;
      cVar1 = FUN_006e7050(*(undefined4 *)(in_ECX + 8));
      if (cVar1 == '\0') {
        FUN_0043c590(4,s_CECGame__Init_00951eb0,0x169);
      }
      else {
        param_1 = (undefined4 *)thunk_FUN_007631a0(0x7c);
        local_4 = 1;
        if (param_1 == (undefined4 *)0x0) {
          uVar3 = 0;
        }
        else {
          uVar3 = FUN_007a8850();
        }
        local_4 = 0xffffffff;
        *(undefined4 *)(in_ECX + 0x238) = uVar3;
        cVar1 = FUN_007a8b00(*(undefined4 *)(in_ECX + 4),60000,120000);
        if (cVar1 == '\0') {
          pcVar6 = s_CECGame__Init__lit_model_render_i_00951e5c;
        }
        else {
          iVar2 = thunk_FUN_007631a0(0x6c);
          local_4 = 2;
          param_1 = (undefined4 *)iVar2;
          if (iVar2 == 0) {
            iVar2 = 0;
          }
          else {
            FUN_00431910(100);
            local_4._0_1_ = 3;
            FUN_00431c00(10);
            *(undefined ***)(iVar2 + 0x18) = &PTR_FUN_008d6b64;
            *(undefined4 *)(iVar2 + 0x40) = 0;
            *(undefined4 *)(iVar2 + 0x44) = 0;
            *(undefined4 *)(iVar2 + 0x38) = 0;
            *(undefined4 *)(iVar2 + 0x3c) = 0;
            local_4._0_1_ = 5;
            FUN_00431990(0x100);
            *(undefined1 *)(iVar2 + 0x60) = 0;
            *(undefined4 *)(iVar2 + 100) = 0;
            *(undefined **)(iVar2 + 0x68) = PTR_DAT_00985a98;
            local_4 = CONCAT31(local_4._1_3_,7);
            FUN_00431770(0x100);
          }
          local_4 = 0xffffffff;
          *(int *)(in_ECX + 0x218) = iVar2;
          iVar2 = thunk_FUN_007631a0(0x54);
          local_4 = 8;
          if (iVar2 == 0) {
            iVar2 = 0;
          }
          else {
            puVar4 = &param_1;
            *(undefined4 *)(iVar2 + 4) = 0;
            param_1 = (undefined4 *)0x0;
            uVar3 = FUN_00404700(100,puVar4);
            FUN_005b0ea0(uVar3,puVar4);
            local_4 = CONCAT31(local_4._1_3_,9);
            FUN_0085fb90();
            *(undefined1 *)(iVar2 + 0x38) = 0;
            InitializeCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x3c));
          }
          *(int *)(in_ECX + 0x2c) = iVar2;
          local_4 = 0xffffffff;
          *(undefined4 *)(in_ECX + 0x204) =
               *(undefined4 *)(*(int *)(*(int *)(in_ECX + 4) + 0x88) + 0x10);
          param_1 = (undefined4 *)thunk_FUN_007631a0(0xc0);
          local_4 = 10;
          if (param_1 == (undefined4 *)0x0) {
            uVar3 = 0;
          }
          else {
            uVar3 = FUN_007a4c20();
          }
          local_4 = 0xffffffff;
          *(undefined4 *)(in_ECX + 0x208) = uVar3;
          FUN_007a4e70(*(undefined4 *)(in_ECX + 4));
          param_1 = (undefined4 *)thunk_FUN_007631a0(0x5c);
          local_4 = 0xb;
          if (param_1 == (undefined4 *)0x0) {
            iVar2 = 0;
          }
          else {
            iVar2 = FUN_00418380();
          }
          local_4 = 0xffffffff;
          *(int *)(in_ECX + 0x210) = iVar2;
          if (iVar2 == 0) {
            FUN_0043c590(2,s_CECGame__Init_00951eb0,0x181);
            ExceptionList = local_c;
            return 0;
          }
          *(undefined4 *)(iVar2 + 8) = 0xa00000;
          *(undefined4 *)(*(int *)(in_ECX + 0x210) + 4) = 0x64000;
          uVar3 = *(undefined4 *)(in_ECX + 0x210);
          iVar2 = FUN_00430890();
          *(undefined4 *)(iVar2 + 0xc) = uVar3;
          cVar1 = FUN_0042eab0();
          if (cVar1 == '\0') {
            FUN_0043c590(4,s_CECGame__Init_00951eb0,0x18c);
            ExceptionList = local_c;
            return 0;
          }
          param_1 = (undefined4 *)thunk_FUN_007631a0(0x54);
          local_4 = 0xc;
          if (param_1 == (undefined4 *)0x0) {
            iVar2 = 0;
          }
          else {
            iVar2 = FUN_00416570();
          }
          local_4 = 0xffffffff;
          *(int *)(in_ECX + 0x30) = iVar2;
          if (iVar2 == 0) {
            FUN_0043c590(2,s_CECGame__Init_00951eb0,0x193);
            ExceptionList = local_c;
            return 0;
          }
          cVar1 = FUN_00416910(0x200);
          if (cVar1 == '\0') {
            FUN_00764590(1,s_CECGame__Init__failed_to_initali_00951e28);
            FUN_00416940();
          }
          param_1 = (undefined4 *)thunk_FUN_007631a0(0x24);
          local_4 = 0xd;
          if (param_1 == (undefined4 *)0x0) {
            iVar2 = 0;
          }
          else {
            iVar2 = FUN_00415990();
          }
          local_4 = 0xffffffff;
          *(int *)(in_ECX + 0x34) = iVar2;
          if (iVar2 == 0) {
            FUN_0043c590(2,s_CECGame__Init_00951eb0,0x1a0);
            ExceptionList = local_c;
            return 0;
          }
          cVar1 = FUN_00415a40(0x40);
          if (cVar1 == '\0') {
            pcVar6 = s_CECGame__Init__failed_to_initali_00951df0;
          }
          else {
            param_1 = (undefined4 *)thunk_FUN_007631a0(0x38);
            local_4 = 0xe;
            if (param_1 == (undefined4 *)0x0) {
              iVar2 = 0;
            }
            else {
              iVar2 = FUN_00415cc0();
            }
            local_4 = 0xffffffff;
            *(int *)(in_ECX + 0x24) = iVar2;
            if (iVar2 == 0) {
              FUN_0043c590(2,s_CECGame__Init_00951eb0,0x1ad);
              ExceptionList = local_c;
              return 0;
            }
            cVar1 = FUN_00415da0(0xd);
            if (cVar1 == '\0') {
              FUN_0043c590(4,s_CECGame__Init_00951eb0,0x1b3);
              ExceptionList = local_c;
              return 0;
            }
            param_1 = (undefined4 *)thunk_FUN_007631a0(100);
            local_4 = 0xf;
            if (param_1 == (undefined4 *)0x0) {
              iVar2 = 0;
            }
            else {
              iVar2 = FUN_00411520(*(undefined4 *)(in_ECX + 0x28));
            }
            local_4 = 0xffffffff;
            *(int *)(in_ECX + 0x38) = iVar2;
            if (iVar2 == 0) {
              FUN_0043c590(2,s_CECGame__Init_00951eb0,0x1ba);
              ExceptionList = local_c;
              return 0;
            }
            param_1 = (undefined4 *)thunk_FUN_007631a0(0xec);
            local_4 = 0x10;
            if (param_1 == (undefined4 *)0x0) {
              iVar2 = 0;
            }
            else {
              iVar2 = FUN_00433b70();
            }
            local_4 = 0xffffffff;
            *(int *)(in_ECX + 0x1c) = iVar2;
            if (iVar2 == 0) {
              FUN_0043c590(2,s_CECGame__Init_00951eb0,0x1c1);
              ExceptionList = local_c;
              return 0;
            }
            cVar1 = FUN_00433f80();
            if (cVar1 == '\0') {
              FUN_0043c590(4,s_CECGame__Init_00951eb0,0x1c7);
              ExceptionList = local_c;
              return 0;
            }
            param_1 = (undefined4 *)thunk_FUN_007631a0(400);
            local_4 = 0x11;
            if (param_1 == (undefined4 *)0x0) {
              iVar2 = 0;
            }
            else {
              iVar2 = FUN_005cef00();
            }
            local_4 = 0xffffffff;
            *(int *)(in_ECX + 0x20) = iVar2;
            if (iVar2 == 0) {
              FUN_0043c590(2,s_CECGame__Init_00951eb0,0x1ce);
              ExceptionList = local_c;
              return 0;
            }
            cVar1 = FUN_004194b0(s_Configs_fixed_msg_txt_00951dd8,1);
            if (cVar1 == '\0') {
              FUN_0043c590(4,s_CECGame__Init_00951eb0,0x1d4);
            }
            cVar1 = FUN_004194b0(s_Configs_item_desc_txt_00951dc0,1);
            if (cVar1 == '\0') {
              FUN_0043c590(4,s_CECGame__Init_00951eb0,0x1d8);
            }
            cVar1 = FUN_004194b0(s_Configs_item_ext_desc_txt_00951da4,1);
            if (cVar1 == '\0') {
              FUN_0043c590(4,s_CECGame__Init_00951eb0,0x1dc);
            }
            cVar1 = FUN_004194b0(s_Configs_skillstr_txt_00951d8c,1);
            if (cVar1 == '\0') {
              FUN_0043c590(4,s_CECGame__Init_00951eb0,0x1e0);
            }
            cVar1 = FUN_004194b0(s_Configs_buff_str_txt_00951d74,1);
            if (cVar1 == '\0') {
              FUN_0043c590(4,s_CECGame__Init_00951eb0,0x1e4);
            }
            cVar1 = FUN_00430920();
            if (cVar1 == '\0') {
              FUN_0043c590(4,s_CECGame__Init_00951eb0,0x1e8);
            }
            cVar1 = FUN_00430c90();
            if (cVar1 == '\0') {
              FUN_0043c590(4,s_CECGame__Init_00951eb0,0x1ec);
            }
            cVar1 = FUN_00431070();
            if (cVar1 == '\0') {
              FUN_0043c590(4,s_CECGame__Init_00951eb0,0x1f0);
            }
            cVar1 = FUN_0043c5e0(s_data_elements_data_00951d60,&local_20);
            if (cVar1 == '\0') {
              FUN_00764590(1,s_data_elements_data_is_missing____00951d3c);
            }
            else {
              FUN_00764590(1,s_elements_data_s_md5____02x_02x_0_00951ce4,local_20,uStack_1f,
                           uStack_1e,uStack_1d,uStack_1c,uStack_1b,uStack_1a,uStack_19,uStack_18,
                           uStack_17,uStack_16,local_15,uStack_14,uStack_13,uStack_12,local_11);
            }
            param_1 = (undefined4 *)thunk_FUN_007631a0(0x3c);
            local_4 = 0x12;
            if (param_1 == (undefined4 *)0x0) {
              uVar3 = 0;
            }
            else {
              uVar3 = FUN_00677440();
            }
            local_4 = 0xffffffff;
            *(undefined4 *)(in_ECX + 500) = uVar3;
            iVar2 = FUN_006776a0(s_data_elements_data_00951d60,0);
            if (iVar2 != 0) {
              MessageBoxA((HWND)0x0,&DAT_00951c88,&DAT_00951cdc,0x10);
              FUN_0043c590(4,s_CECGame__Init_00951eb0,0x1fe);
              ExceptionList = local_c;
              return 0;
            }
            *(undefined4 *)(in_ECX + 0x1f8) = **(undefined4 **)(in_ECX + 500);
            cVar1 = FUN_00673d50();
            if (cVar1 == '\0') {
              FUN_0043c590(4,s_CECGame__Init_00951eb0,0x205);
              ExceptionList = local_c;
              return 0;
            }
            cVar1 = FUN_0043c5e0(s_data_tasks_data_00951c78,&local_20);
            if (cVar1 == '\0') {
              FUN_00764590(1,s_data_tasks_data_is_missing____00951c58);
            }
            else {
              FUN_00764590(1,s_tasks_data_s_md5____02x_02x_02x__00951c00,local_20,uStack_1f,
                           uStack_1e,uStack_1d,uStack_1c,uStack_1b,uStack_1a,uStack_19,uStack_18,
                           uStack_17,uStack_16,local_15,uStack_14,uStack_13,uStack_12,local_11);
            }
            param_1 = (undefined4 *)thunk_FUN_007631a0(0x2f8);
            local_4 = 0x13;
            if (param_1 == (undefined4 *)0x0) {
              iVar2 = 0;
            }
            else {
              iVar2 = FUN_006885b0();
            }
            local_4 = 0xffffffff;
            *(int *)(in_ECX + 0x1fc) = iVar2;
            if (iVar2 == 0) {
              FUN_0043c590(2,s_CECGame__Init_00951eb0,0x211);
              ExceptionList = local_c;
              return 0;
            }
            FUN_0074c2a0(*(undefined4 *)(in_ECX + 0x1f8));
            param_1 = (undefined4 *)thunk_FUN_007631a0(0x25c);
            local_4 = 0x14;
            if (param_1 == (undefined4 *)0x0) {
              iVar2 = 0;
            }
            else {
              iVar2 = FUN_004133d0();
            }
            local_4 = 0xffffffff;
            *(int *)(in_ECX + 0x200) = iVar2;
            if (iVar2 == 0) {
              FUN_0043c590(2,s_CECGame__Init_00951eb0,0x21a);
              ExceptionList = local_c;
              return 0;
            }
            FUN_00413490();
            param_1 = (undefined4 *)thunk_FUN_007631a0(0x34);
            local_4 = 0x15;
            if (param_1 == (undefined4 *)0x0) {
              iVar2 = 0;
            }
            else {
              iVar2 = FUN_00405810();
            }
            local_4 = 0xffffffff;
            *(int *)(in_ECX + 0x21c) = iVar2;
            if ((iVar2 != 0) &&
               (iVar2 = FUN_00405d00(s_configs_DynamicObjects_data_00951be4), iVar2 != 0)) {
              FUN_00431260();
              param_1 = (undefined4 *)thunk_FUN_007631a0(0x270);
              local_4 = 0x16;
              if (param_1 == (undefined4 *)0x0) {
                uVar3 = 0;
              }
              else {
                uVar3 = FUN_0064ca80();
              }
              *(undefined4 *)(in_ECX + 0x20c) = uVar3;
              local_4 = 0xffffffff;
              cVar1 = FUN_0064cbc0(*(undefined4 *)(*(int *)(DAT_009b3eec + 4) + 0xa1c),180000);
              if (cVar1 == '\0') {
                iVar2 = *(int *)(in_ECX + 0x20c);
                if (iVar2 != 0) {
                  FUN_0064cb00();
                  thunk_FUN_007631b0(iVar2);
                }
                *(undefined4 *)(in_ECX + 0x20c) = 0;
                FUN_0043c590(4,s_CECGame__Init_00951eb0,0x231);
                ExceptionList = local_c;
                return 0;
              }
              FUN_00767fe0(*(undefined1 *)(*(int *)(in_ECX + 0x18) + 0xa0));
              FUN_0064d3d0(*(undefined1 *)(*(int *)(in_ECX + 0x18) + 0xa1));
              FUN_0064d530(*(undefined1 *)(*(int *)(in_ECX + 0x18) + 0xa0));
              FUN_0064d760(*(undefined1 *)(*(int *)(in_ECX + 0x18) + 0xa0));
              FUN_00471350();
              FUN_00482060();
              uVar3 = FUN_00673d30();
              uVar3 = FUN_00673d00(uVar3);
              FUN_00763d30(in_ECX + 0x4fc,s__x_x_x_x_00951bd8,0x3000001b,DAT_00978974,uVar3);
              *(undefined4 *)(in_ECX + 0x500) = 0x98;
              *(undefined4 *)(in_ECX + 0x504) = *(undefined4 *)(in_ECX + 0x274);
              *(undefined4 *)(in_ECX + 0x508) = 0x65;
              *(undefined4 *)(in_ECX + 0x50c) = 7;
              *(undefined4 *)(in_ECX + 0x510) = 0x466;
              uVar3 = (*(code *)PTR_FUN_009b3ba8)(*(undefined4 *)(in_ECX + 0x270),0x65);
              *(undefined4 *)(in_ECX + 0x514) = uVar3;
              puVar4 = *(undefined4 **)
                        (*(int *)(in_ECX + 0x60) +
                        (int)(0xde % (ulonglong)*(uint *)(in_ECX + 0x6c)) * 4);
              do {
                if (puVar4 == (undefined4 *)0x0) {
                  _Source = (wchar_t *)0x0;
LAB_0042e2b1:
                  wcscpy((wchar_t *)(in_ECX + 0x518),_Source);
                  ExceptionList = local_c;
                  return 1;
                }
                if (puVar4[2] == 0xde) {
                  _Source = *(wchar_t **)puVar4[1];
                  goto LAB_0042e2b1;
                }
                puVar4 = (undefined4 *)*puVar4;
              } while( true );
            }
            pcVar6 = s_CECGame__Init__Failed_to_load_da_00951ba0;
          }
        }
        FUN_00764590(1,pcVar6);
      }
    }
  }
  else {
    MessageBoxA((HWND)param_1[1],s_ElementSkill_s_version_is_incorr_00951ec0,s_ERROR_00951ee8,0x10);
  }
  ExceptionList = local_c;
  return 0;
}

