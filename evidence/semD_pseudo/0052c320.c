undefined4 FUN_0052c320(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  if (DAT_0072329c == 0) {
    FUN_00530d00(0x506);
    return 0;
  }
  if (param_1 == 0) {
    iVar1 = FUN_0052c460();
    DAT_0072329c = *(undefined4 *)(DAT_00723270 + iVar1 * 4);
    return 1;
  }
  if (*(uint *)(DAT_0072329c + 0x4c) < param_1) {
    FUN_00530d00(0x506);
    return 0;
  }
  DAT_0072329c = *(int *)(DAT_0072329c + 0x44);
  uVar2 = 0;
  if (param_1 != 1) {
    do {
      DAT_0072329c = *(int *)(DAT_0072329c + 0x44);
      if (DAT_0072329c == 0) {
        FUN_00530d00(0x504);
        iVar1 = FUN_0052c460();
        DAT_0072329c = *(undefined4 *)(DAT_00723270 + iVar1 * 4);
        return 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_1 - 1);
  }
  DAT_005cfddc = 0;
  return 1;
}


