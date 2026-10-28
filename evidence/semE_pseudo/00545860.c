int * FUN_00545860(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar1 = (int *)0x0;
  if (0 < param_2) {
    piVar2 = (int *)(param_1 + 0x1c);
    do {
      if ((iVar3 < *piVar2) && (0 < piVar2[-1])) {
        piVar1 = piVar2 + -7;
        iVar3 = *piVar2;
      }
      piVar2 = piVar2 + 8;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return piVar1;
}


