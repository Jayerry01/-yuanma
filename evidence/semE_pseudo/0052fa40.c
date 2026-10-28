uint FUN_0052fa40(void)

{
  uint uVar1;
  
  DAT_007232a4 = FUN_0052c490();
  if (DAT_007232a4 == 0) {
    uVar1 = FUN_00530d00(0x506);
    return uVar1 & 0xffffff00;
  }
  if (1 < *(uint *)(DAT_007232a4 + 8)) {
    uVar1 = FUN_0052f910();
    return uVar1;
  }
  uVar1 = FUN_0052f800();
  return uVar1;
}


