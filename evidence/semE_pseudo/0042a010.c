undefined4 FUN_0042a010(uint param_1)

{
  if (param_1 == 0) {
    return DAT_005d5b04;
  }
  if (((param_1 & 0xff000000) == 0x10000000) && ((param_1 & 0xffffff) < 0x801)) {
    return (&DAT_007ddf40)[param_1 & 0xffffff];
  }
  return 0;
}


