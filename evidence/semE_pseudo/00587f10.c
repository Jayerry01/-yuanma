int __thiscall FUN_00587f10(int param_1,int param_2)

{
  int iVar1;
  
  if (-1 < param_2) {
    iVar1 = FUN_0056b1d0();
    if (param_2 < iVar1) {
      return param_2 * 0x40 + *(int *)(param_1 + 0x2f0);
    }
  }
  return 0;
}


