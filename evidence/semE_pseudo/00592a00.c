undefined4 __fastcall FUN_00592a00(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x18) + 4))();
  (**(code **)(**(int **)(param_1 + 0x1c) + 4))();
  *(int *)(param_1 + 8) =
       *(int *)(*(int *)(param_1 + 0x18) + 8) - *(int *)(*(int *)(param_1 + 0x1c) + 8);
  return 1;
}


