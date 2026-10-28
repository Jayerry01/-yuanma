void FUN_004349e0(int param_1,int param_2)

{
  if ((param_1 != 0) || (param_1 = DAT_005d9b78, DAT_005d9b78 != 0)) {
    if (param_2 < 0) {
      param_2 = 0;
    }
    if (*(int *)(param_1 + 0x20) <= param_2) {
      param_2 = *(int *)(param_1 + 0x20) + -1;
    }
    *(int *)(param_1 + 0x2c) = param_2;
    FUN_004345a0(param_1);
  }
  return;
}


