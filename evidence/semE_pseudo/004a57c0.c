undefined4 __thiscall FUN_004a57c0(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x80))(param_2,2,0,0);
  if (iVar1 == 0) {
    return 0;
  }
  param_1[100] = 1;
  FUN_00407c10(param_1[0x11d],param_1 + 0x5e,param_1 + 0x61,0);
  (**(code **)(*param_1 + 0x8c))(1,1);
  return 1;
}


