undefined4 FUN_00432970(int param_1)

{
  int *piVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 4) != 0) {
    FUN_005089fd(*(int *)(param_1 + 4));
  }
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_005089fd(param_1);
  return 1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
