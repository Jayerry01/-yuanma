int __thiscall FUN_0056ae80(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (-1 < param_2) {
    iVar1 = *(int *)(param_1 + 0x120);
    iVar2 = *(int *)(iVar1 + 0x38);
    if (param_2 < *(int *)(iVar1 + 0x40) + iVar2) {
      if (param_2 < iVar2) {
        return param_2 * 0x2b0 + *(int *)(iVar1 + 0x3c);
      }
      return (param_2 - iVar2) * 0x2b0 + *(int *)(iVar1 + 0x44);
    }
  }
  return 0;
}


