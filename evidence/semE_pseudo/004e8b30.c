int __thiscall FUN_004e8b30(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    return 0;
  }
  iVar1 = (**(code **)(*param_2 + 4))(param_1);
  if (iVar1 != 0) {
    *(int **)(param_1 + 4) = param_2;
  }
  return iVar1;
}


