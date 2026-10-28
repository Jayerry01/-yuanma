int __fastcall FUN_00591c80(int param_1)

{
  int iVar1;
  
  do {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 4))();
    if (iVar1 != 1) {
      return iVar1;
    }
    (**(code **)(**(int **)(param_1 + 0x1c) + 4))();
  } while (*(int *)(*(int *)(param_1 + 0x1c) + 8) != 0);
  return 1;
}


