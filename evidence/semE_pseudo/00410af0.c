undefined4 FUN_00410af0(uint param_1)

{
  if (param_1 == 0) {
    return 0;
  }
  if ((param_1 & 0xff000000) != 0x3000000) {
    return 0;
  }
  if (0x13ff < (param_1 & 0xffffff)) {
    return 0;
  }
  return (&DAT_007e5be0)[param_1 & 0xffffff];
}


