undefined4 FUN_00410be0(uint param_1)

{
  if (param_1 == 0) {
    return 0;
  }
  if ((param_1 & 0xff000000) != 0x11000000) {
    return 0;
  }
  if (0xff < (param_1 & 0xffffff)) {
    return 0;
  }
  return (&DAT_007f0200)[param_1 & 0xffffff];
}


