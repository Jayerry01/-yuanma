undefined4 __thiscall FUN_00462960(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(code **)(param_1 + 0x60) != (code *)0x0) {
    (**(code **)(param_1 + 0x60))(param_2,param_3);
  }
  if (*(int **)(param_1 + 0x1c) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x1c) + 0x20))(param_2,param_3);
    if (iVar1 != 0) {
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x4c))(param_2,param_3);
      FUN_00462190();
    }
  }
  return 1;
}


