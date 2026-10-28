void FUN_00506090(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_005056a0(param_1);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 8) != 0) {
      FUN_005297f0(*(int *)(iVar1 + 8));
      FUN_00528cf0(1,(undefined4 *)(iVar1 + 8));
      *(undefined4 *)(iVar1 + 8) = 0;
    }
  }
  return;
}


