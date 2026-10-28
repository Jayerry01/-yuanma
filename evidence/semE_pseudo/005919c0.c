undefined4 __fastcall FUN_005919c0(int param_1)

{
  int iVar1;
  
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x18) + 4))();
  }
  (**(code **)(**(int **)(param_1 + 0x1c) + 4))();
  iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + 8);
  while( true ) {
    if (iVar1 == 0) {
      return 1;
    }
    iVar1 = (**(code **)(**(int **)(param_1 + 0x24) + 4))();
    if (iVar1 == 3) break;
    if (iVar1 == 4) {
      return 1;
    }
    if (*(int **)(param_1 + 0x20) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x20) + 4))();
    }
    (**(code **)(**(int **)(param_1 + 0x1c) + 4))();
    iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + 8);
  }
  return 3;
}


