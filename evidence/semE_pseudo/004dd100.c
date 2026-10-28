undefined4 __thiscall FUN_004dd100(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x28);
  while( true ) {
    if (piVar1 == *(int **)(param_1 + 0x2c)) {
      return 0;
    }
    if (*piVar1 == param_2) break;
    piVar1 = piVar1 + 1;
  }
  return 1;
}


