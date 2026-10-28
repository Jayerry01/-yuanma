undefined4 FUN_00430650(uint param_1)

{
  if (param_1 == 0) {
    return 0;
  }
  if ((param_1 & 0xff000000) != 0xa000000) {
    return 0;
  }
  if (7 < (param_1 & 0xffffff)) {
    return 0;
  }
  return (&DAT_007efdc0)[param_1 & 0xffffff];
}


