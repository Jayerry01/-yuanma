void FUN_00432dc0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (-1 < param_1) {
    piVar1 = (int *)(&DAT_005d5b70)[param_1];
    if (piVar1 == (int *)0x0) {
      if (param_1 != 0) {
        return;
      }
    }
    else {
      iVar2 = (**(code **)(*piVar1 + 8))(piVar1);
      if (iVar2 != 0) {
        return;
      }
      (&DAT_005d5b70)[param_1] = 0;
    }
    piVar1 = (int *)(&DAT_005d7b70)[param_1];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      (&DAT_005d7b70)[param_1] = 0;
    }
    if (param_1 == DAT_005d9b70 + -1) {
      DAT_005d9b70 = DAT_005d9b70 + -1;
    }
  }
  return;
}


