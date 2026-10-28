undefined4 __thiscall FUN_0046ad70(int param_1,int param_2)

{
  FUN_00429de0(*(undefined4 *)(param_1 + 0x10),param_2);
  FUN_00429de0(*(undefined4 *)(param_1 + 0xc),param_2);
  if (param_2 == 0) {
    (**(code **)(**(int **)(param_1 + 8) + 0xc))(0);
    return 1;
  }
  if (*(int *)(param_1 + 0x3c) != 0) {
    (**(code **)(**(int **)(param_1 + 8) + 0xc))(param_2);
  }
  return 1;
}


