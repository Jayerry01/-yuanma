int __fastcall FUN_0049ff70(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[5];
  iVar2 = iVar1 - param_1[4];
  if (iVar2 < 0x400) {
    if ((iVar1 < 0x2800) && (-1 < iVar1)) {
      return iVar2;
    }
    if (iVar2 != 0) {
      FUN_005092c0(param_1[1],param_1[4] + param_1[1],iVar2);
    }
    iVar1 = FUN_0050b997(*param_1,param_1[1] + iVar2,0x2800 - iVar2);
    param_1[3] = param_1[3] + param_1[4];
    param_1[4] = 0;
    param_1[2] = param_1[1];
    param_1[5] = iVar1 + iVar2;
  }
  return param_1[5];
}


