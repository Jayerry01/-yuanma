void __fastcall FUN_004e86b0(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)**(int **)(param_1 + 600);
  if (piVar1 != *(int **)(param_1 + 600)) {
    do {
      FUN_0055e050();
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(param_1 + 600));
  }
  return;
}


