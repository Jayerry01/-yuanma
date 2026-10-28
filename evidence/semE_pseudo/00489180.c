undefined4 __fastcall FUN_00489180(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x3d0))();
  if (iVar1 != 0) {
    (**(code **)(*param_1 + 0x34c))(1);
    return 1;
  }
  iVar1 = (**(code **)(*param_1 + 0x364))();
  if (iVar1 == 0) {
    (**(code **)(*param_1 + 0x3d4))();
  }
  return 0;
}


