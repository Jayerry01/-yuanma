uint FUN_0050cb23(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_007f1d64;
  while( true ) {
    if (DAT_007f1d64 + DAT_007f1d60 * 0x14 <= uVar1) {
      return 0;
    }
    if ((uint)(param_1 - *(int *)(uVar1 + 0xc)) < 0x100000) break;
    uVar1 = uVar1 + 0x14;
  }
  return uVar1;
}


