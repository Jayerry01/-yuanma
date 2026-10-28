undefined4 __thiscall FUN_00463070(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  if (*(int **)(param_1 + 0x20) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x20) + 0x54))(param_2);
  }
  piVar1 = (int *)**(int **)(param_1 + 0x30);
  if (piVar1 != *(int **)(param_1 + 0x30)) {
    do {
      FUN_00463070(param_2);
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(param_1 + 0x30));
  }
  return 1;
}


