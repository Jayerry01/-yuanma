void FUN_004d28b0(undefined4 param_1,int *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *param_2;
  if (iVar1 != 0) {
    FUN_005092c0(param_3,iVar1 + param_3,0x2800 - iVar1);
    FUN_0050b997(param_1,(param_3 - *param_2) + 0x2800,*param_2);
    *param_2 = 0;
  }
  return;
}


