undefined4 FUN_0052c520(void)

{
  if (DAT_00723278 == '\0') {
    FUN_005089bc(&LAB_0052c5c0);
    DAT_00723278 = '\x01';
  }
  DAT_00723270 = FUN_0052c4b0(DAT_00723270,DAT_00723264 * 4,DAT_00723264 * 4 + 0x1000);
  if (DAT_00723270 == 0) {
    return 0;
  }
  DAT_00723264 = DAT_00723264 + 0x400;
  return CONCAT31((int3)((uint)DAT_00723264 >> 8),1);
}


