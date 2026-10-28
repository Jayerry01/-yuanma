undefined4 __thiscall FUN_00470890(int param_1,undefined4 param_2)

{
  if (*(int **)(param_1 + 0x1c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x1c) + 0x54))(param_2);
  }
  if (*(int **)(param_1 + 0x20) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x20) + 0x54))(param_2);
  }
  if (*(int **)(param_1 + 0x24) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x24) + 0x54))(param_2);
  }
  FUN_00429dc0(*(undefined4 *)(param_1 + 0x84),param_2,param_2);
  return 1;
}


