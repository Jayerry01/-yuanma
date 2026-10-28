void FUN_00414f30(int param_1)

{
  if (*(int *)(param_1 + 0x6e4) != 0) {
    DAT_005d5a78 = 1;
    DestroyWindow(*(HWND *)(param_1 + 0x6e4));
    *(undefined4 *)(param_1 + 0x6e4) = 0;
  }
  if (DAT_005d5a6c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005d5a6c);
    DAT_005d5a6c = (HGDIOBJ)0x0;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
