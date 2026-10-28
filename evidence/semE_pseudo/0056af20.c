int __thiscall FUN_0056af20(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x120);
  if (((iVar1 != 0) && (-1 < param_2)) && (param_2 < *(int *)(iVar1 + 0xe4))) {
    return *(int *)(iVar1 + 0xd8) + param_2 * 0x24;
  }
  return 0;
}


