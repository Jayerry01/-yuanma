void __thiscall FUN_00461cc0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    iVar1 = FUN_004621a0();
    if (iVar1 == 0) {
      iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x20))(param_2,param_3);
      if (iVar1 != 0) {
        (**(code **)(**(int **)(param_1 + 0xc) + 0x4c))(param_2,param_3);
      }
    }
  }
  return;
}


