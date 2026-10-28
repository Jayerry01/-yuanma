int __thiscall FUN_0056aee0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x120);
  if (((iVar1 != 0) && (-1 < param_2)) && (param_2 < *(int *)(iVar1 + 0xec))) {
    return *(int *)(iVar1 + 0xd4) + param_2 * 0x54;
  }
  return 0;
}


