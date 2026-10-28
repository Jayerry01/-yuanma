undefined4 FUN_0041fd10(char *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  DWORD iCharSet;
  
  if (*param_1 < '\0') {
    iCharSet = 0x88;
  }
  else {
    iCharSet = 0;
  }
  DAT_005d5a60 = CreateFontA(0x20,0,0,0,400,0,0,0,iCharSet,0,0,2,0,param_1);
  if (DAT_005d5a60 == (HFONT)0x0) {
    return 0;
  }
  DAT_005d5a68 = GetDC((HWND)0x0);
  DAT_005d5a64 = SelectObject(DAT_005d5a68,DAT_005d5a60);
  puVar3 = &DAT_007e2780;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  iVar2 = (int)&DAT_007e2780 - (int)param_1;
  do {
    cVar1 = *param_1;
    param_1[iVar2] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return 1;
}


