void FUN_0042a130(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    DAT_005c679c = 1;
    DAT_005c67a0 = 1;
    if (*(int *)(DAT_005d5a0c + 0x6d0) == 0) {
      *(int *)(DAT_005d5a0c + 0x6d0) = param_1;
      *(int *)(DAT_005d5a0c + 0x6cc) = param_1;
      *(undefined4 *)(param_1 + 0x5c) = 0;
      *(undefined4 *)(param_1 + 0x58) = 0;
      return;
    }
    *(int *)(*(int *)(DAT_005d5a0c + 0x6d0) + 0x5c) = param_1;
    uVar1 = *(undefined4 *)(DAT_005d5a0c + 0x6d0);
    *(undefined4 *)(param_1 + 0x5c) = 0;
    *(undefined4 *)(param_1 + 0x58) = uVar1;
    *(int *)(DAT_005d5a0c + 0x6d0) = param_1;
  }
  return;
}


