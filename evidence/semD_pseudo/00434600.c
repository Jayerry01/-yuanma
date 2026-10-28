void FUN_00434600(void)

{
  if (DAT_005d9b78 != (undefined4 *)0x0) {
    FUN_005089fd(DAT_005d9b78);
    DAT_005d9b78 = (undefined4 *)0x0;
  }
  DAT_005d9b78 = _malloc(0x34);
  *DAT_005d9b78 = 0;
  DAT_005d9b78[5] = 0;
  DAT_005d9b78[6] = 0;
  DAT_005d9b78[7] = 0;
  DAT_005d9b78[8] = 0;
  DAT_005d9b78[9] = 0;
  DAT_005d9b78[10] = 0;
  DAT_005d9b78[0xb] = 0;
  DAT_005d9b78[0xc] = 0;
  SetRectEmpty((LPRECT)(DAT_005d9b78 + 1));
  return;
}


