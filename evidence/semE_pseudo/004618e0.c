void __thiscall FUN_004618e0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x18) == 0) && (*(int *)(param_1 + 0xc) != 0)) {
    iVar1 = FUN_004621a0();
    if (iVar1 == 0) {
      iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x28))(param_2,0);
      if (iVar1 != 0) {
        (**(code **)(**(int **)(param_1 + 0xc) + 0x54))(param_2,0);
      }
    }
  }
  return;
}


