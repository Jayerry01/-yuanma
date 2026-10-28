void __thiscall FUN_005644a0(int param_1,int param_2)

{
  int iVar1;
  
  FUN_00562dd0(param_2 + 0x48,param_2 + 0x54);
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x29c)) {
    do {
      if (*(int *)(*(int *)(param_1 + 0x2a0) + iVar1 * 4) != 0) {
        FUN_0057e0a0(param_2);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x29c));
  }
  return;
}



int __thiscall