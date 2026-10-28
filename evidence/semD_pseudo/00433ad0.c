void FUN_00433ad0(void)

{
  if (DAT_005d9b74 != (undefined4 *)0x0) {
    FUN_005089fd(DAT_005d9b74);
    DAT_005d9b74 = (undefined4 *)0x0;
  }
  DAT_005d9b74 = _malloc(0x3c);
  *DAT_005d9b74 = 0xffffffff;
  DAT_005d9b74[1] = 0;
  DAT_005d9b74[2] = 0;
  DAT_005d9b74[3] = 0;
  SetRectEmpty((LPRECT)(DAT_005d9b74 + 4));
  SetRectEmpty((LPRECT)(DAT_005d9b74 + 8));
  DAT_005d9b74[0xc] = 0;
  DAT_005d9b74[0xd] = 0;
  DAT_005d9b74[0xe] = 0;
  return;
}


