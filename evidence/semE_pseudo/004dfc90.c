undefined4 FUN_004dfc90(int *param_1)

{
  int iVar1;
  
  if ((((param_1[0xf3] != 0) && (iVar1 = param_1[0xf4], iVar1 != 99999)) && (iVar1 != 0x3a)) &&
     ((iVar1 != 0x90 && (iVar1 != 0x91)))) {
    (**(code **)(*param_1 + 0xc4))(iVar1);
    param_1[0xf3] = 0;
    return 1;
  }
  return 0;
}


