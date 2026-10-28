void FUN_00460a20(int param_1)

{
  int iVar1;
  
  while (param_1 != 0) {
    FUN_00460a20(*(undefined4 *)(param_1 + 0xc));
    iVar1 = *(int *)(param_1 + 8);
    FUN_00402e90(param_1,0x18);
    param_1 = iVar1;
  }
  return;
}


