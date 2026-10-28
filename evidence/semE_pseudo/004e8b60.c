int __fastcall FUN_004e8b60(int param_1)

{
  int iVar1;
  
  if (*(int **)(param_1 + 4) == (int *)0x0) {
    return 0;
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 4) + 8))(param_1);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return iVar1;
}


