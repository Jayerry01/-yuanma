bool FUN_005060d0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_005056a0(param_1);
  if (iVar1 == 0) {
    return false;
  }
  if (*(int *)(iVar1 + 8) == 0) {
    return false;
  }
  FUN_00529530(*(int *)(iVar1 + 8),0x1010,&param_1);
  return param_1 == 0x1012;
}


