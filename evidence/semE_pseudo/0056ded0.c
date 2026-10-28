void __fastcall FUN_0056ded0(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x40)) {
    do {
      (**(code **)(**(int **)(*(int *)(param_1 + 0x4c) + iVar1 * 4) + 0x38))();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x40));
  }
  return;
}


