undefined4 FUN_00483ae0(int param_1)

{
  int *piVar1;
  
  if ((param_1 != 0) && (piVar1 = *(int **)(param_1 + 0x2c), piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x2c) = 0;
    return 1;
  }
  return 0;
}


