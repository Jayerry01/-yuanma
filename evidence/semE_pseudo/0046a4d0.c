undefined4 __fastcall FUN_0046a4d0(int param_1)

{
  int *piVar1;
  
  if (*(int **)(param_1 + 0x20) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x20) + 0x10))();
  }
  piVar1 = (int *)**(int **)(param_1 + 0x30);
  if (piVar1 != *(int **)(param_1 + 0x30)) {
    do {
      (**(code **)(*(int *)piVar1[2] + 0x30))();
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(param_1 + 0x30));
  }
  return 1;
}


