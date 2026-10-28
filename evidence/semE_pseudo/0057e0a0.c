void __thiscall FUN_0057e0a0(int param_1,int param_2)

{
  int *piVar1;
  
  if (param_2 != 0) {
    piVar1 = *(int **)(param_1 + 0x50);
    if (piVar1 != *(int **)(param_1 + 0x54)) {
      if (piVar1 != (int *)0x0) {
        *piVar1 = param_2;
      }
      *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 4;
      return;
    }
    FUN_0057e0e0(piVar1,&param_2);
  }
  return;
}


