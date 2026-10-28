void __fastcall FUN_005926b0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x18) + 4))();
  (**(code **)(**(int **)(param_1 + 0x1c) + 4))();
  if ((*(int *)(*(int *)(param_1 + 0x18) + 8) == 1) && (*(int *)(*(int *)(param_1 + 0x1c) + 8) == 1)
     ) {
    *(undefined4 *)(param_1 + 8) = 1;
    return;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}


