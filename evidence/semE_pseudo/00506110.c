void FUN_00506110(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_005056a0(param_1);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x34) = param_2;
    if (*(int *)(iVar1 + 8) != 0) {
      FUN_00528ea0(*(int *)(iVar1 + 8),0x1003,param_2);
    }
  }
  return;
}


