undefined4 FUN_00410b70(uint param_1)

{
  if (param_1 == 0) {
    return 0;
  }
  if ((param_1 & 0xff000000) != 0x6000000) {
    return 0;
  }
  if (0x17 < (param_1 & 0xffffff)) {
    return 0;
  }
  return (&DAT_007eac00)[param_1 & 0xffffff];
}


