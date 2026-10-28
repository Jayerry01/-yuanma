undefined4 __fastcall FUN_00591f00(int param_1)

{
  int iVar1;
  
  (**(code **)(**(int **)(param_1 + 0x18) + 4))();
  iVar1 = *(int *)(*(int *)(param_1 + 0x18) + 8);
  while( true ) {
    if (iVar1 == 0) {
      return 1;
    }
    iVar1 = (**(code **)(**(int **)(param_1 + 0x1c) + 4))();
    if (iVar1 == 3) break;
    if (iVar1 == 4) {
      return 1;
    }
    (**(code **)(**(int **)(param_1 + 0x18) + 4))();
    iVar1 = *(int *)(*(int *)(param_1 + 0x18) + 8);
  }
  return 3;
}



undefined4 * __thiscall