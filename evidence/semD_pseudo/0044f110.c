undefined4 __fastcall FUN_0044f110(int param_1)

{
  int *piVar1;
  
  if (DAT_005e0324 != 0) {
    *(undefined4 *)(param_1 + 700) = 1;
    FUN_004620e0(*(undefined4 *)(param_1 + 0x2b4),*(undefined4 *)(param_1 + 0x2b8),1,
                 *(undefined4 *)(param_1 + 0x2c0));
    *(undefined4 *)(param_1 + 0x2b4) = 0;
    *(undefined4 *)(param_1 + 0x2b8) = 0;
    *(undefined4 *)(param_1 + 700) = 0;
    piVar1 = *(int **)(*(int *)(param_1 + 0x2c0) + 0x2c);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x5c))(*(int *)(param_1 + 0x2c0));
    }
    *(undefined4 *)(param_1 + 0x2c0) = 0;
  }
  return 1;
}


