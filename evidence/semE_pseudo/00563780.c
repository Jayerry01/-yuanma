void __fastcall FUN_00563780(int param_1)

{
  int iVar1;
  
  FUN_005642c0();
  if (*(int **)(param_1 + 0x6d0) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x6d0) + 4))();
  }
  if ((*(int *)(param_1 + 0x4b4) != 0) && (iVar1 = 0, 0 < *(int *)(param_1 + 0x4b0))) {
    do {
      FUN_005607f0();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x4b0));
  }
  return;
}


