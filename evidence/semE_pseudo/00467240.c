void __fastcall FUN_00467240(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)**(int **)(param_1 + 8);
  if (piVar1 != *(int **)(param_1 + 8)) {
    do {
      FUN_004666a0(0xff,0xff,0xff);
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(param_1 + 8));
  }
  return;
}


