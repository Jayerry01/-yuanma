void FUN_00506190(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_005056a0(param_1);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0xc) = *param_2;
    *(undefined4 *)(iVar1 + 0x10) = param_2[1];
    *(undefined4 *)(iVar1 + 0x14) = param_2[2];
    if (*(int *)(iVar1 + 8) != 0) {
      FUN_00529160(*(int *)(iVar1 + 8),0x1004,param_2);
    }
  }
  return;
}


