void FUN_004b4c80(int param_1)

{
  int iVar1;
  
  while (param_1 != 0) {
    FUN_004b4c80(*(undefined4 *)(param_1 + 0xc));
    iVar1 = *(int *)(param_1 + 8);
    FUN_004026e0();
    FUN_00402e90(param_1,0x1c);
    param_1 = iVar1;
  }
  return;
}


