undefined4 __fastcall FUN_00467c20(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)**(int **)(param_1 + 8);
  if (piVar1 != *(int **)(param_1 + 8)) {
    do {
      if (*(int *)(param_1 + 0x38) != 0) {
        FUN_00469760(piVar1[2]);
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(param_1 + 8));
  }
  return 1;
}


