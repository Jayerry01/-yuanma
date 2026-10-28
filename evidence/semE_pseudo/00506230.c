void FUN_00506230(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_005056a0(param_1);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x24) = *param_2;
    *(undefined4 *)(iVar1 + 0x28) = param_2[1];
    *(undefined4 *)(iVar1 + 0x2c) = param_2[2];
    if (*(int *)(iVar1 + 8) != 0) {
      FUN_00529160(*(int *)(iVar1 + 8),0x1005,param_2);
    }
  }
  return;
}


