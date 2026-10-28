void FUN_0042a300(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return;
  }
  if (param_1 == *(int *)(DAT_005d5a0c + 0x6d0)) {
    if (param_1 == *(int *)(DAT_005d5a0c + 0x6cc)) {
      *(undefined4 *)(DAT_005d5a0c + 0x6d0) = 0;
      *(undefined4 *)(DAT_005d5a0c + 0x6cc) = 0;
      FUN_0042a440();
      return;
    }
    *(undefined4 *)(DAT_005d5a0c + 0x6d0) = *(undefined4 *)(param_1 + 0x58);
    if (*(int *)(DAT_005d5a0c + 0x6d0) != 0) {
      *(undefined4 *)(*(int *)(DAT_005d5a0c + 0x6d0) + 0x5c) = 0;
      *(undefined4 *)(param_1 + 0x5c) = 0;
      *(undefined4 *)(param_1 + 0x58) = 0;
      FUN_0042a440();
      return;
    }
  }
  else if (param_1 == *(int *)(DAT_005d5a0c + 0x6cc)) {
    *(undefined4 *)(DAT_005d5a0c + 0x6cc) = *(undefined4 *)(param_1 + 0x5c);
    if (*(int *)(DAT_005d5a0c + 0x6cc) != 0) {
      *(undefined4 *)(*(int *)(DAT_005d5a0c + 0x6cc) + 0x58) = 0;
      *(undefined4 *)(param_1 + 0x5c) = 0;
      *(undefined4 *)(param_1 + 0x58) = 0;
      FUN_0042a440();
      return;
    }
  }
  else {
    iVar1 = *(int *)(*(int *)(DAT_005d5a0c + 0x6d0) + 0x58);
    if (iVar1 == 0) goto LAB_0042a3db;
    while (iVar1 != param_1) {
      iVar1 = *(int *)(iVar1 + 0x58);
      if (iVar1 == 0) {
        FUN_0042a440();
        return;
      }
    }
    *(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x58) = *(undefined4 *)(param_1 + 0x58);
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  }
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
LAB_0042a3db:
  FUN_0042a440();
  return;
}


