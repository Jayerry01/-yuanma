void FUN_005061e0(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_005056a0(param_1);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x18) = *param_2;
    *(undefined4 *)(iVar1 + 0x1c) = param_2[1];
    *(undefined4 *)(iVar1 + 0x20) = param_2[2];
    if (*(int *)(iVar1 + 8) != 0) {
      FUN_00529160(*(int *)(iVar1 + 8),0x1006,param_2);
    }
  }
  return;
}


