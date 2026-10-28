undefined4 __fastcall FUN_00463dd0(int param_1)

{
  if (*(int **)(param_1 + 8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 8) + 0x80))(1,1,0x10,0);
  }
  if (*(int *)(*(int *)(param_1 + 4) + 8) != 2) {
    *(undefined4 *)(*(int *)(param_1 + 4) + 8) = 0;
  }
  return 1;
}


