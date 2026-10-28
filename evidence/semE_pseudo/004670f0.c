undefined4 __thiscall FUN_004670f0(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x44) == 0) {
    iVar1 = *(int *)(param_1 + 0x1c);
    if (param_2 != 0) {
      if (iVar1 != 0) {
        FUN_00429de0(iVar1,1);
      }
      FUN_00429de0(*(undefined4 *)(param_1 + 0x20),1);
      return 1;
    }
    if (iVar1 != 0) {
      FUN_00429de0(iVar1,0);
    }
    FUN_00429de0(*(undefined4 *)(param_1 + 0x20),0);
  }
  return 1;
}


