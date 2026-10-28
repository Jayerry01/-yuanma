undefined4 FUN_00430680(uint param_1)

{
  if (param_1 == 0) {
    return 0;
  }
  if ((param_1 & 0xff000000) != 0xb000000) {
    return 0;
  }
  if (0xf < (param_1 & 0xffffff)) {
    return 0;
  }
  return (&DAT_007efd80)[param_1 & 0xffffff];
}


