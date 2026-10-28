undefined4 __fastcall FUN_00469a60(int param_1)

{
  int *piVar1;
  
  if (0 < *(int *)(param_1 + 0xc)) {
    piVar1 = (int *)**(int **)(param_1 + 0x2c);
    if (piVar1 != *(int **)(param_1 + 0x2c)) {
      do {
        FUN_00466320();
        piVar1 = (int *)*piVar1;
      } while (piVar1 != (int *)*(int *)(param_1 + 0x2c));
    }
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;
    return 1;
  }
  return 0;
}


