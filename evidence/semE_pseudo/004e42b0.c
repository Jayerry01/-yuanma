void FUN_004e42b0(int param_1)

{
  int iVar1;
  
  while (param_1 != 0) {
    FUN_004e42b0(*(undefined4 *)(param_1 + 0xc));
    iVar1 = *(int *)(param_1 + 8);
    FUN_00402e90(param_1,0x14);
    param_1 = iVar1;
  }
  return;
}


