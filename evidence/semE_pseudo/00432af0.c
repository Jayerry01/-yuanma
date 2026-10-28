undefined4 FUN_00432af0(void)

{
  int iVar1;
  
  if (DAT_005d5b40 == 0) {
    return 0;
  }
  iVar1 = FUN_00432b40();
  if (iVar1 != 0) {
    mciSendCommandA(DAT_005d5b40,0x808,0,0);
  }
  mciSendCommandA(DAT_005d5b40,0x804,0,0);
  DAT_005d5b40 = 0;
  return 1;
}


