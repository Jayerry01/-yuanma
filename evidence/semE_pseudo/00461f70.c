undefined4 __thiscall FUN_00461f70(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = *(int **)(param_1 + 0x14);
  piVar3 = (int *)*piVar1;
  if (piVar3 != piVar1) {
    while (piVar3[2] != param_2) {
      piVar3 = (int *)*piVar3;
      if (piVar3 == piVar1) {
        return 1;
      }
    }
    piVar1 = (int *)piVar3[1];
    iVar2 = *piVar3;
    *piVar1 = iVar2;
    *(int **)(iVar2 + 4) = piVar1;
    FUN_00402e90(piVar3,0xc);
  }
  return 1;
}


