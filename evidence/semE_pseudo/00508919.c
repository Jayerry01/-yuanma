int __fastcall FUN_00508919(int *param_1)

{
  int iVar1;
  
  if (param_1[2] != 0) {
    if (param_1[3] == -1) {
      iVar1 = (**(code **)(*param_1 + 0x20))();
      param_1[3] = iVar1;
    }
    return param_1[3];
  }
  iVar1 = (**(code **)(*param_1 + 0x20))();
  return iVar1;
}


