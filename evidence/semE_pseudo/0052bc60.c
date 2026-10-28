uint FUN_0052bc60(uint param_1)

{
  uint uVar1;
  
  if ((0x600 < param_1) && (param_1 < 0x603)) {
    uVar1 = (uint)DAT_00723260 >> 8;
    *(uint *)(&DAT_007dcba4 + DAT_00723260 * 0x5c) = param_1;
    return CONCAT31((int3)uVar1,1);
  }
  uVar1 = FUN_00530d00(0x509);
  return uVar1 & 0xffffff00;
}


