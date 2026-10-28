void FUN_00474610(void)

{
  DAT_005e0914 = CreateDCA(s_DISPLAY_005c7d30,(LPCSTR)0x0,(LPCSTR)0x0,(DEVMODEA *)0x0);
  DAT_005e0918 = CreateCompatibleDC(DAT_005e0914);
  DAT_005e091c = CreateCompatibleBitmap(DAT_005e0914,0x10,0x10);
  DAT_005e0920 = CreateSolidBrush(0);
  DAT_005e0924 = CreateFontA(0x10,8,0,0,400,0,0,0,1,0,0,0,0,(LPCSTR)0x0);
  DAT_005e0928 = CreateFontA(0x10,0x10,0,0,400,0,0,0,1,0,0,0,0,(LPCSTR)0x0);
  DAT_005e092c = CreateFontA(0x18,0xc,0,0,400,0,0,0,1,0,0,0,0,(LPCSTR)0x0);
  SelectObject(DAT_005e0918,DAT_005e091c);
  SelectObject(DAT_005e0918,DAT_005e0920);
  return;
}


