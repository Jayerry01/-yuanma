undefined4 __fastcall FUN_00578050(int param_1)

{
  if (*(int **)(param_1 + 0x1c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x1c) + 4))();
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 8);
  }
  *(undefined4 *)(param_1 + 8) =
       *(undefined4 *)
        (*(int *)(*(int *)(param_1 + 0x18) + 0x24) + 8 + *(int *)(param_1 + 0x20) * 0x18);
  return 1;
}


