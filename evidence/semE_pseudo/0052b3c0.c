int FUN_0052b3c0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (DAT_0072329c == 0) {
    FUN_00530d00(0x506);
  }
  else {
    iVar1 = FUN_0052c270();
    if (iVar1 != DAT_0072329c) {
      if (param_1 == 0xdf4) {
        iVar1 = *(int *)(iVar1 + 0x44);
      }
      else if (param_1 == 0xdf5) {
        iVar1 = *(int *)(iVar1 + 0x40);
      }
      else if (param_1 == 0xdf6) {
        iVar1 = *(int *)(iVar1 + 0x48);
      }
      if (iVar1 != 0) {
        do {
          iVar2 = iVar2 + 1;
          if (iVar1 == DAT_0072329c) {
            return iVar2;
          }
          iVar1 = *(int *)(iVar1 + 0x44);
        } while (iVar1 != 0);
        return 0;
      }
    }
  }
  return 0;
}


