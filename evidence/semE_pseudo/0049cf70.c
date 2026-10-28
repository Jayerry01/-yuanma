void FUN_0049cf70(int param_1)

{
  int iVar1;
  
  while (param_1 != 0) {
    FUN_0049cf70(*(undefined4 *)(param_1 + 0xc));
    iVar1 = *(int *)(param_1 + 8);
    FUN_0049fc80();
    FUN_00402e90(param_1,0x20);
    param_1 = iVar1;
  }
  return;
}


