bool FUN_00505a10(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_005056a0(param_1);
  if (iVar1 == 0) {
    return false;
  }
  if (param_2 == 0) {
    return false;
  }
  if (-1 < *(int *)(iVar1 + 4)) {
    FUN_00505430(*(int *)(iVar1 + 4));
  }
  iVar2 = FUN_00505a60(param_2);
  *(int *)(iVar1 + 4) = iVar2;
  return -1 < iVar2;
}


