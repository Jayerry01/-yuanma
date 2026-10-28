int FUN_00512209(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  HANDLE hFile;
  BOOL BVar4;
  DWORD DVar5;
  DWORD *pDVar6;
  int iVar7;
  undefined1 local_1008 [4064];
  undefined4 uStackY_28;
  undefined4 uStackY_24;
  undefined4 uStackY_20;
  
  FUN_00509ce0();
  iVar7 = 0;
  iVar1 = FUN_0050bc3a();
  if ((iVar1 == -1) || (iVar1 = FUN_0050bc3a(), iVar1 == -1)) {
    iVar7 = -1;
  }
  else {
    param_2 = param_2 - iVar1;
    if (param_2 < 1) {
      if (param_2 < 0) {
        uStackY_20 = 0x5122da;
        FUN_0050bc3a();
        uStackY_20 = param_1;
        uStackY_24 = 0x5122e2;
        hFile = (HANDLE)FUN_00511575();
        BVar4 = SetEndOfFile(hFile);
        iVar7 = (BVar4 != 0) - 1;
        if (iVar7 == -1) {
          puVar3 = (undefined4 *)FUN_00510865();
          *puVar3 = 0xd;
          DVar5 = GetLastError();
          pDVar6 = (DWORD *)FUN_0051086e();
          *pDVar6 = DVar5;
        }
      }
    }
    else {
      uStackY_20 = 0x512269;
      _memset(local_1008,0,0x1000);
      uStackY_20 = 0x8000;
      uStackY_24 = param_1;
      uStackY_28 = 0x512276;
      FUN_0050c177();
      do {
        uStackY_20 = 0x512294;
        iVar1 = FUN_0050b80c();
        if (iVar1 == -1) {
          piVar2 = (int *)FUN_0051086e();
          if (*piVar2 == 5) {
            puVar3 = (undefined4 *)FUN_00510865();
            *puVar3 = 0xd;
          }
          iVar7 = -1;
          break;
        }
        param_2 = param_2 - iVar1;
      } while (0 < param_2);
      FUN_0050c177();
    }
    uStackY_20 = 0x512320;
    FUN_0050bc3a();
  }
  return iVar7;
}


