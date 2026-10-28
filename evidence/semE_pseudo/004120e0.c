void FUN_004120e0(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(DAT_005d5a0c + 0x460 + param_1 * 4) + 0x128);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x20))(piVar1);
    piVar1 = *(int **)(*(int *)(DAT_005d5a0c + 0x460 + param_1 * 4) + 0x128);
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}


