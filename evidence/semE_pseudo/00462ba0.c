undefined4 __thiscall FUN_00462ba0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(code **)(param_1 + 0x68) != (code *)0x0) {
    (**(code **)(param_1 + 0x68))(param_2,param_3);
  }
  if (*(int **)(param_1 + 0x1c) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x1c) + 0x28))(param_2,param_3);
    if (iVar1 != 0) {
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x54))(param_2,param_3);
    }
  }
  return 1;
}


