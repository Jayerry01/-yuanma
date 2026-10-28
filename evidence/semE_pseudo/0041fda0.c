void FUN_0041fda0(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (DAT_005d5a60 != (HGDIOBJ)0x0) {
    SelectObject(DAT_005d5a68,DAT_005d5a64);
    ReleaseDC((HWND)0x0,DAT_005d5a68);
    DeleteObject(DAT_005d5a60);
    DAT_005d5a64 = (HGDIOBJ)0x0;
    puVar2 = &DAT_007e2780;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    DAT_005d5a60 = (HGDIOBJ)0x0;
  }
  return;
}


