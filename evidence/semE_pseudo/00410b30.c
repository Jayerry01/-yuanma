undefined4 FUN_00410b30(uint param_1)

{
  if (param_1 == 0) {
    if (DAT_005d5a0c == 0) {
      return 0;
    }
    return *(undefined4 *)(DAT_005d5a0c + 0x6c8);
  }
  if ((param_1 & 0xff000000) != 0x4000000) {
    return 0;
  }
  if (0xf < (param_1 & 0xffffff)) {
    return 0;
  }
  return (&DAT_007f0620)[param_1 & 0xffffff];
}


