void FUN_0042a050(uint param_1,undefined4 param_2)

{
  if ((((param_1 & 0xff000000) == 0x10000000) && (param_1 = param_1 & 0xffffff, param_1 != 0)) &&
     (param_1 < 0x801)) {
    (&DAT_007ddf40)[param_1] = param_2;
  }
  return;
}


