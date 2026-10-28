undefined4 FUN_004df4f0(int *param_1)

{
  int iVar1;
  
  if ((((param_1[0xf3] != 0) && (iVar1 = param_1[0xf4], iVar1 != 99999)) && (iVar1 != 0x3a)) &&
     ((iVar1 != 0x8e && (iVar1 != 0x8f)))) {
    (**(code **)(*param_1 + 0xc0))(iVar1);
    param_1[0xf3] = 0;
    return 1;
  }
  return 0;
}


