uint FUN_004738c0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00410b30(param_1);
  if ((iVar1 != 0) && (*(uint **)(iVar1 + 0x14) != (uint *)0x0)) {
    return **(uint **)(iVar1 + 0x14) | 0x2000000;
  }
  return 0;
}


