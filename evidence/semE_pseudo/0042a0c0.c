void FUN_0042a0c0(int param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  FUN_0042a080(param_1,param_2,param_3);
  if (param_2 != (int *)0x0) {
    *param_2 = *param_2 + *(int *)(param_1 + 0x20);
  }
  if (param_3 != (int *)0x0) {
    *param_3 = *param_3 + *(int *)(param_1 + 0x24);
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = *(undefined4 *)(param_1 + 0x28);
  }
  return;
}


