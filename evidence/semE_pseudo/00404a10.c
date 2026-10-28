void FUN_00404a10(int *param_1,int param_2)

{
  if (param_1[1] == 0) {
    param_1[1] = param_2;
    *param_1 = param_2;
    return;
  }
  *(int *)(param_1[1] + 0x130) = param_2;
  *(int *)(param_2 + 0x134) = param_1[1];
  param_1[1] = param_2;
  *(undefined4 *)(param_2 + 0x130) = 0;
  return;
}


