undefined4 __thiscall FUN_00469eb0(int param_1,int param_2,int param_3)

{
  if (*(int *)(param_1 + 0x3c) != 0) {
    if ((*(byte *)(param_1 + 8) & 1) != 0) {
      FUN_0046a090(param_2 - *(int *)(param_1 + 0xc),0);
    }
    if ((*(byte *)(param_1 + 8) & 2) != 0) {
      FUN_0046a090(0,param_3 - *(int *)(param_1 + 0x10));
    }
    *(int *)(param_1 + 0x10) = param_3;
    *(int *)(param_1 + 0xc) = param_2;
  }
  return 1;
}


