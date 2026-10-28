void __thiscall FUN_00566750(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  piVar4 = (int *)**(int **)(param_1 + 0x10);
  if (piVar4 != *(int **)(param_1 + 0x10)) {
    do {
      piVar1 = (int *)piVar4[2];
      iVar3 = FUN_0056f310();
      if (iVar3 == param_2) {
        piVar2 = (int *)piVar4[1];
        piVar5 = (int *)*piVar4;
        *piVar2 = (int)piVar5;
        piVar5[1] = (int)piVar2;
        FUN_00402e90(piVar4,0xc);
        (**(code **)(*piVar1 + 8))(1);
      }
      else {
        piVar5 = (int *)*piVar4;
      }
      piVar4 = piVar5;
    } while (piVar5 != *(int **)(param_1 + 0x10));
  }
  return;
}


