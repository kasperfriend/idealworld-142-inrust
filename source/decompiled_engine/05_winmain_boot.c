/* Authentic Ghidra 12.1.4 Decompilation — elementclient.exe (PW 1.4.2 Build 2305) */
/* Module: 05_winmain_boot.c */

/* ==================================================================== */
/* Address: 0x0043ea60 | Classified: elementclient::Patcher@0x43ea60 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0043ea60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  code *pcVar4;
  char cVar5;
  byte bVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *puVar12;
  char *pcVar13;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar14;
  uint uStack_ed0;
  undefined1 auStack_ebc [4];
  int iStack_eb8;
  int iStack_ea0;
  int iStack_e9c;
  undefined4 auStack_e98 [2];
  undefined4 uStack_e90;
  int iStack_e8c;
  int iStack_e88;
  undefined1 auStack_e84 [256];
  undefined4 uStack_d84;
  undefined *puStack_c7c;
  undefined *puStack_c78;
  undefined1 auStack_c74 [4];
  undefined1 auStack_c70 [512];
  char acStack_a70 [556];
  undefined1 auStack_844 [2004];
  undefined4 auStack_70 [17];
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined4 uStack_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &UNK_008d6ea0;
  puStack_10 = &UNK_00892f5c;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  puStack_1c = &stack0xfffff100;
  iVar8 = GetPrivateProfileIntA(0x953f1c,0x953f24,1,0x953f2c);
  if (iVar8 == 0) {
    (*_DAT_009b3b30)(1000,auStack_844);
    wcscat(auStack_844,0x953eec);
    (*_DAT_009b3b6c)(0,0x953ec8,auStack_844,0,0x953ed4,1);
LAB_0043eae8:
    *unaff_FS_OFFSET = uStack_14;
    return 0;
  }
  puVar12 = auStack_70;
  for (iVar8 = 0x11; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  auStack_70[0] = 0x44;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  (*_DAT_009b3b1c)(0x953e90,0,0,0,0,0,0,0,auStack_70,&uStack_2c);
  func_0x006afc20();
  func_0x006a7ec0();
  cVar5 = func_0x0043dd60();
  if (cVar5 == '\0') {
    *unaff_FS_OFFSET = uStack_14;
    return 0xffffffff;
  }
  DAT_009b4fd9 = 1;
  func_0x00892e60(&UNK_0043dd30);
  InitializeCriticalSection(0x9b41f8);
  InitializeCriticalSection(0x9b41b8);
  InitializeCriticalSection(0x9b41d8);
  InitializeCriticalSection(0x9b4d28);
  InitializeCriticalSection(0x9b4558);
  uStack_8 = 0;
  func_0x0043f740(param_3);
  cVar5 = func_0x0043f810();
  if (cVar5 == '\0') {
    uVar14 = 0x2f6;
  }
  else {
    puStack_c78 = &DAT_009b3c44;
    cVar5 = func_0x0043df30(&puStack_c78);
    if (cVar5 == '\0') {
      MessageBoxA(0,puStack_c78,0x953e54,0x10);
      DAT_009b4fd9 = 0;
      *unaff_FS_OFFSET = uStack_14;
      return 0xffffffff;
    }
    puStack_c7c = &DAT_009b3c44;
    cVar5 = func_0x0043e260(&puStack_c7c);
    if (cVar5 == '\0') {
      MessageBoxA(0,0x953df4,puStack_c7c,0x10);
      DAT_009b4fd9 = 0;
      *unaff_FS_OFFSET = uStack_14;
      return 0xffffffff;
    }
    puVar12 = auStack_e98;
    for (iVar8 = 0x87; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar12 = 0;
      puVar12 = puVar12 + 1;
    }
    uVar3 = DAT_009b4dfe;
    if (_DAT_009b4b10 != -1) {
      uVar3 = _DAT_009b4b10 != 0;
    }
    uStack_e90 = CONCAT31(uStack_e90._1_3_,uVar3);
    if (_DAT_009b4b14 == -1) {
      iStack_e8c = _DAT_009b4dee;
    }
    else {
      iStack_e8c = _DAT_009b4b18;
    }
    if (_DAT_009b4b18 == -1) {
      iStack_e88 = _DAT_009b4df2;
    }
    else {
      iStack_e88 = _DAT_009b4b18;
    }
    bVar6 = GetVersion();
    if (bVar6 < 5) {
      DAT_009b4ffa = 1;
    }
    uVar14 = GetCurrentProcess(&DAT_009b4fdc,0,0,2);
    uVar14 = GetCurrentThread(uVar14);
    uVar14 = GetCurrentProcess(uVar14);
    DuplicateHandle(uVar14);
    pcVar4 = _DAT_009b3b0c;
    _DAT_009b4ff0 = (*_DAT_009b3b0c)(0,0,0,0);
    _DAT_009b4ff4 = GetCurrentThreadId();
    func_0x0043e430((char)uStack_e90 == '\0');
    sVar7 = func_0x0043f9f0(param_1);
    if (sVar7 == 0) {
      uVar14 = 0x335;
    }
    else {
      cVar5 = func_0x0043fa70(param_1,param_4,uStack_e90);
      if (cVar5 != '\0') {
        auStack_e98[0] = _DAT_009b4fd0;
        auStack_e98[1] = _DAT_009b4fd4;
        func_0x0043c740();
        if (_DAT_009b4b1c != 0) {
          func_0x007649a0(&DAT_009b4b1c,0x100,auStack_e84,0x100);
          uStack_d84 = _DAT_009b4d1c;
        }
        func_0x006cee90();
        func_0x006df7c0(_DAT_009d3f10);
        func_0x0043e650(*(undefined4 *)(_DAT_009d3f10 + 4));
        cVar5 = FUN_0042d700(auStack_e98);
        if (cVar5 == '\0') {
          func_0x0043c590(4,0x953de8,0x35a);
          _DAT_0095344c = 0;
          *unaff_FS_OFFSET = uStack_14;
          return 0xffffffff;
        }
        func_0x0043c740();
        cVar5 = FUN_00434720(1);
        if (cVar5 == '\0') {
          _DAT_0095344c = 0;
          *unaff_FS_OFFSET = uStack_14;
          return 0xfffffffe;
        }
        _DAT_009b4fe0 = CreateThread(0,0,&UNK_0043f610,0,4,auStack_c74);
        _DAT_009b4fe4 = CreateThread(0,0,&UNK_0043f590,0,4,auStack_c74);
        _DAT_009b4fe8 = (*pcVar4)(0,1,0,0);
        _DAT_009b4fec = (*pcVar4)(0,0,0,0);
        func_0x0069fe40(0xffff,&UNK_0043f6b0);
        func_0x0069fe40(0xfffe,&UNK_0043f720);
        func_0x0069fe40(0xfffd,&UNK_006afb20);
        func_0x0069fe40(0xfffc,&UNK_006afbb0);
        func_0x0069fe40(0xfffb,&UNK_006afbd0);
        func_0x0069fe40(0xfffa,&UNK_006afbf0);
        func_0x0069fe40(0xfff9,&UNK_006afc00);
        func_0x0069fe40(0xfff8,&UNK_006af640);
        func_0x0069fe40(0xfff7,&UNK_006af670);
        func_0x0069fe40(0xfff6,&UNK_006af740);
        func_0x0069fe40(0xfff5,&UNK_006af830);
        func_0x0069fe40(0xfff4,&UNK_006af870);
        func_0x0069fe40(0xfff3,&UNK_006af940);
        func_0x0069fe40(0xfff2,&UNK_006afa30);
        func_0x0069fe40(0xfff1,&UNK_0043e450);
        func_0x0069fe40(0xfff0,&UNK_0043e500);
        func_0x0069fe40(0xffef,&UNK_0043e520);
        func_0x0069fe40(0xffee,&UNK_006a0210);
        func_0x0069fe40(0xffed,&UNK_006a2400);
        func_0x0069fe40(0xffec,&UNK_006afc80);
        func_0x0069fe40(0xffeb,&UNK_006afcb0);
        func_0x0069fe40(0xffea,&UNK_006a7f70);
        (**(code **)(**(int **)(_DAT_009b457c + 0x4c) + 0x14))
                  (*(int **)(_DAT_009b457c + 0x4c),0,2,auStack_c70);
        iVar8 = FUN_0043f4c0();
        uVar10 = 0xffffffff;
        pcVar13 = acStack_a70;
        do {
          if (uVar10 == 0) break;
          uVar10 = uVar10 - 1;
          cVar5 = *pcVar13;
          pcVar13 = pcVar13 + 1;
        } while (cVar5 != '\0');
        uVar11 = ~uVar10 - 1;
        if (*(uint *)(iVar8 + 0x5c) < uVar11) {
          uStack_ed0 = ~uVar10 - 2;
          *(undefined4 *)(iVar8 + 0x5c) = 2;
          while (uStack_ed0 = uStack_ed0 >> 1, uStack_ed0 != 0) {
            *(int *)(iVar8 + 0x5c) = *(int *)(iVar8 + 0x5c) << 1;
          }
          iVar1 = *(int *)(iVar8 + 0x54);
          iVar2 = *(int *)(iVar8 + 0x58);
          iVar9 = realloc(iVar1,*(undefined4 *)(iVar8 + 0x5c));
          *(int *)(iVar8 + 0x54) = iVar9;
          *(int *)(iVar8 + 0x58) = iVar9 + (iVar2 - iVar1);
        }
        memmove(*(undefined4 *)(iVar8 + 0x54),acStack_a70,uVar11);
        *(uint *)(iVar8 + 0x58) = uVar11 + *(int *)(iVar8 + 0x54);
        ResumeThread(_DAT_009b4fe4);
        DAT_009b4ffb = 1;
        do {
          while( true ) {
            iVar8 = _DAT_009b3c68;
            if (_DAT_009b3c68 == 1) {
              MessageBoxA(*(undefined4 *)(_DAT_009b3eec + 0x274),0x953dc8,0,0x10);
              func_0x00764590(1,0x953d98);
              _DAT_0095344c = 0;
              iVar8 = ExitProcess(0xfffffffe);
            }
            if (iVar8 == 2) {
              MessageBoxA(*(undefined4 *)(_DAT_009b3eec + 0x274),0x953d74,0,0x10);
              func_0x00764590(1,0x953d4c);
              _DAT_0095344c = 0;
              ExitProcess(0xfffffffd);
            }
            if (DAT_009b3c64 != '\0') {
              func_0x00764590(1,0x953ce8);
              ExitProcess(0xffffffff);
            }
            if ((_DAT_009b4fe0 != 0) && (DAT_00953450 == '\0')) {
              EnterCriticalSection(0x9b4d28);
              SuspendThread(_DAT_009b4fe0);
              DAT_00953450 = '\x01';
              LeaveCriticalSection(0x9b4d28);
            }
            FUN_007415e0();
            iVar8 = WaitForSingleObject(_DAT_009b4ff0,0);
            if (iVar8 == 0) {
              uVar14 = GetCurrentThread();
              SuspendThread(uVar14);
            }
            if (DAT_009b4fd8 != '\0') {
              iStack_e9c = *(int *)(*(int *)(_DAT_009b3eec + 0x1c) + 4);
              if ((iStack_e9c != 0) && (iStack_ea0 = func_0x005aafe0(), iStack_ea0 != 0)) {
                func_0x00595b80(_DAT_009b4570,&DAT_009b3c44);
              }
              DAT_009b4fd8 = '\0';
            }
            if (DAT_009b4ff9 == '\0') break;
            while (iVar8 = (*_DAT_009b3bb0)(auStack_ebc,0,0,0,1), iVar8 != 0) {
              if (iStack_eb8 == 0x12) goto LAB_0043f38a;
              TranslateMessage(auStack_ebc);
              (*_DAT_009b3b80)(auStack_ebc);
            }
            if ((*(char *)(*(int *)(_DAT_009b3eec + 8) + 10) == '\0') &&
               (*(char *)(*(int *)(_DAT_009b3eec + 8) + 0xb) != '\0')) {
              func_0x00427e00();
              if ((_DAT_009b4fe0 != 0) && (DAT_00953450 == '\0')) {
                EnterCriticalSection(0x9b4d28);
                SuspendThread(_DAT_009b4fe0);
                DAT_00953450 = '\x01';
                LeaveCriticalSection(0x9b4d28);
              }
              cVar5 = func_0x0077b0c0();
              if (cVar5 == '\0') {
                func_0x00764590(1,0x951ff4);
              }
              func_0x00427560();
            }
            if (DAT_009b4ff9 != '\0') {
              if (((_DAT_009b4fe0 != 0) && (DAT_009b4ff9 != '\0')) && (DAT_00953450 != '\0')) {
                DAT_00953450 = '\0';
                ResumeThread(_DAT_009b4fe0);
              }
              DAT_009b4ff8 = 1;
              SetEvent(_DAT_009b4fec);
              uVar14 = GetCurrentThread();
              SuspendThread(uVar14);
              DAT_009b4ff8 = 0;
            }
          }
          cVar5 = FUN_0042fad0();
        } while (cVar5 != '\0');
LAB_0043f38a:
        DAT_009b4ffb = 0;
        SetEvent(_DAT_009b4fe8);
        if (_DAT_009b4fe4 != 0) {
          WaitForSingleObject(_DAT_009b4fe4,0xffffffff);
        }
        if (_DAT_009b4fe0 != 0) {
          SetEvent(_DAT_009b4fec);
          DAT_009b4ff9 = '\x01';
          if ((_DAT_009b4fe0 != 0) && (DAT_00953450 != '\0')) {
            DAT_00953450 = '\0';
            ResumeThread(_DAT_009b4fe0);
          }
          WaitForSingleObject(_DAT_009b4fe0,0xffffffff);
        }
        FUN_0042e3a0();
        func_0x006ceeb0();
        func_0x0043f9e0();
        uStack_8 = 0xffffffff;
        DeleteCriticalSection(0x9b41f8);
        DeleteCriticalSection(0x9b41b8);
        DeleteCriticalSection(0x9b41d8);
        DeleteCriticalSection(0x9b4d28);
        DeleteCriticalSection(0x9b4558);
        CloseHandle(_DAT_009b4fdc);
        CloseHandle(_DAT_009b4fe8);
        CloseHandle(_DAT_009b4fec);
        CloseHandle(_DAT_009b4ff0);
        DAT_009b4fd9 = 0;
        _DAT_0095344c = 0;
        goto LAB_0043eae8;
      }
      uVar14 = 0x33c;
    }
  }
  func_0x0043c590(4,0x953de8,uVar14);
  *unaff_FS_OFFSET = uStack_14;
  return 0xffffffff;
}


/* ==================================================================== */
/* Address: 0x0043f4c0 | Classified: ElementClient::proc_43f4c0 */
/* ==================================================================== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0043f4c0(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &UNK_008d6eb0;
  puStack_10 = &UNK_00892f5c;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  if ((DAT_009f0f90 & 1) == 0) {
    DAT_009f0f90 = DAT_009f0f90 | 1;
    func_0x006a6610();
    func_0x00892e60(&UNK_0043f580);
  }
  if (DAT_009b5000 == '\0') {
    uStack_8 = 0;
    uVar1 = rdtsc();
    Sleep(100);
    uVar2 = rdtsc();
    _DAT_009f1138 =
         ((int)uVar2 - (int)uVar1) -
         (uint)((uint)((ulonglong)uVar2 >> 0x20) < (uint)((ulonglong)uVar1 >> 0x20));
    DAT_009b5000 = '\x01';
  }
  *unaff_FS_OFFSET = uStack_14;
  return 0x9f0fa0;
}


