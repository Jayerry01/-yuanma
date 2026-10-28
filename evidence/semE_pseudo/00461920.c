void __thiscall FUN_00461920(int param_1,undefined1 param_2,int param_3)

{
  int iVar1;
  
  if (((*(int *)(param_1 + 0x18) != 0) && (param_3 != 0)) && (*(int *)(param_1 + 0xc) != 0)) {
    iVar1 = FUN_004621a0();
    if (iVar1 == 0) {
      iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x28))(param_2,param_3);
      if (iVar1 != 0) {
        (**(code **)(**(int **)(param_1 + 0xc) + 0x54))(param_2,param_3);
      }
    }
  }
  return;
}


