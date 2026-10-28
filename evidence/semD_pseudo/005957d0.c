int FUN_005957d0(int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(double *)(param_2 + iVar1 * 8) <= (double)CONCAT44(param_5,param_4)) {
    if ((double)CONCAT44(param_5,param_4) <= *(double *)(param_2 + 8 + iVar1 * 8)) {
      param_1[2] = param_1[2] + 1;
    }
    else {
      param_1[1] = param_1[1] + 1;
      iVar1 = FUN_00595770(param_2,param_4,param_5,iVar1,param_3 + -1);
      *param_1 = iVar1;
    }
  }
  else {
    param_1[1] = param_1[1] + 1;
    iVar1 = FUN_00595770(param_2,param_4,param_5,0,iVar1);
    *param_1 = iVar1;
  }
  return *param_1;
}


