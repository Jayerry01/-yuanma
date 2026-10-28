void __thiscall FUN_004f4a80(int param_1,int *param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 4) = 1;
  FUN_00549a90(0,0);
  iVar1 = (**(code **)(*param_2 + 0x50))();
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x50) = 1;
  }
  return;
}


