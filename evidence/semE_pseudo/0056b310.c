int __thiscall FUN_0056b310(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x120);
  if (((iVar1 != 0) && (-1 < param_2)) && (param_2 < *(int *)(iVar1 + 0x40))) {
    return *(int *)(iVar1 + 0x44) + 8 + param_2 * 0x2b0;
  }
  return 0;
}



int __thiscall