
undefined4 __fastcall FUN_004cbe10(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x130))();
  if ((iVar1 != 1) && (iVar1 != 0)) {
    return 0;
  }
  iVar1 = (**(code **)(*param_1 + 0x18c))();
  if (iVar1 != 0) {
    return 0;
  }
  if (param_1[0xd8] != 0) {
    (**(code **)(*param_1 + 0x74))(0x18);
    (**(code **)(*param_1 + 300))(8);
    return 1;
  }
  param_1[0xee] = param_1[0xe4];
  param_1[0xef] = param_1[0xe5];
  param_1[0xf0] = param_1[0xe6];
  (**(code **)(*param_1 + 0x74))(0x24,1,1,0xbf800000);
  (**(code **)(*param_1 + 300))(8);
  return 1;
}

