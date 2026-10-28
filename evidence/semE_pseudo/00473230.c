undefined4 __thiscall FUN_00473230(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    (**(code **)(**(int **)(param_1 + 0x1c) + 4))(param_2);
    (**(code **)(**(int **)(param_1 + 0x20) + 4))(param_2);
  }
  if (*(int **)(param_1 + 0x48) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x48) + 0xc))(param_2);
  }
  return 1;
}


