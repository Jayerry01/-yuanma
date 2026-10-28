byte FUN_0051260f(uint param_1)

{
  if (DAT_007f2ec0 <= param_1) {
    return 0;
  }
  return *(byte *)((&DAT_007f2dc0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 0x40;
}


