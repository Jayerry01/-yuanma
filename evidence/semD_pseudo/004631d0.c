undefined4 __thiscall FUN_004631d0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)**(int **)(param_1 + 0x30);
  if (piVar2 != *(int **)(param_1 + 0x30)) {
    do {
      if ((int *)piVar2[2] != (int *)0x0) {
        (**(code **)(*(int *)piVar2[2] + 0x58))(param_2);
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)*(int *)(param_1 + 0x30));
  }
  if (*(int **)(param_1 + 0x20) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x20) + 0xc))(param_2);
  }
  iVar1 = *(int *)(param_1 + 8);
  if (param_2 == 0) {
    if ((iVar1 != 2) && (iVar1 != 3)) {
      *(undefined4 *)(param_1 + 8) = 1;
      return 1;
    }
  }
  else if ((iVar1 != 2) && (iVar1 != 3)) {
    *(undefined4 *)(param_1 + 8) = 0;
    return 1;
  }
  return 1;
}


