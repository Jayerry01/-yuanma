void FUN_00506280(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_005056a0(param_1);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x38) = param_2;
    *(undefined4 *)(iVar1 + 0x3c) = param_3;
    if (*(int *)(iVar1 + 8) != 0) {
      FUN_00528ea0(*(int *)(iVar1 + 8),0x1020,param_2);
      FUN_00528ea0(*(undefined4 *)(iVar1 + 8),0x1023,param_3);
    }
  }
  return;
}


