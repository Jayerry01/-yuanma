void __thiscall FUN_00581d00(int *param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1[0x7b] + 0x10) = param_2;
  *(int **)(*(int *)(param_1[0x7b] + 0x10) + 8) = param_1;
  (**(code **)(*param_1 + 0x38))();
  return;
}


