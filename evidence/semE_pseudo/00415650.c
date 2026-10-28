void FUN_00415650(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  if (DAT_005c4308 == 0) {
    if (*(int *)(param_1 + 0x34) != 0) {
      FUN_005089fd(*(int *)(param_1 + 0x34));
      *(undefined4 *)(param_1 + 0x34) = 0;
    }
  }
  else {
    piVar2 = *(int **)(param_1 + 0x30);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
  }
  piVar2 = (int *)(param_1 + 0x128);
  iVar3 = 0xc;
  do {
    piVar1 = (int *)*piVar2;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


