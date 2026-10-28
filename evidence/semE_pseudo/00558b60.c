void __thiscall FUN_00558b60(int param_1,int param_2)

{
  if (param_2 < 50000) {
    *(undefined4 *)(param_1 + 0xf4) = 0;
    *(undefined4 *)(param_1 + 300) = 0;
    *(int *)(param_1 + 0x130) = *(int *)(param_1 + 0x28) + -1;
    return;
  }
  *(undefined4 *)(param_1 + 0xf4) = 1;
  *(undefined4 *)(param_1 + 300) = 50000;
  *(int *)(param_1 + 0x130) = *(int *)(param_1 + 0x2c) + 49999;
  return;
}


