undefined4 FUN_0050b724(uint param_1)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  undefined4 uVar5;
  
  iVar1 = FUN_00511575(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = FUN_00511575(2);
      iVar2 = FUN_00511575(1);
      if (iVar2 == iVar1) goto LAB_0050b772;
    }
    hObject = (HANDLE)FUN_00511575(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_0050b774;
    }
  }
LAB_0050b772:
  DVar4 = 0;
LAB_0050b774:
  FUN_005114f6(param_1);
  *(undefined1 *)((&DAT_007f2dc0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = 0;
  if (DVar4 == 0) {
    uVar5 = 0;
  }
  else {
    FUN_005107f2(DVar4);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}


