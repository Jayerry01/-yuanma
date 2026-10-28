void __thiscall FUN_004bb4d0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_00487830();
  iVar2 = (**(code **)(*piVar1 + 0x364))();
  if (iVar2 == 0) {
    FUN_004a95a0(param_2,param_3,param_4);
    (**(code **)(**(int **)(param_1 + 0x3b8) + 0xc))(param_1,param_2,param_3,param_4);
  }
  return;
}


