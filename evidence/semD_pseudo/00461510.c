FUN_00461510(LPCSTR param_1,char *param_2,CHAR param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  char cVar1;
  HFONT h;
  int iVar2;
  LOGFONTA local_3c;
  
  param_1[0] = '\0';
  param_1[1] = '\0';
  param_1[2] = '\0';
  param_1[3] = '\0';
  param_1[4] = '\0';
  param_1[5] = '\0';
  param_1[6] = '\0';
  param_1[7] = '\0';
  param_1[8] = '\0';
  param_1[9] = '\0';
  param_1[10] = '\0';
  param_1[0xb] = '\0';
  param_1[0xc] = '\0';
  param_1[0xd] = '\0';
  param_1[0xe] = '\0';
  param_1[0xf] = '\0';
  param_1[0x10] = '\0';
  param_1[0x11] = '\0';
  param_1[0x12] = '\0';
  param_1[0x13] = '\0';
  iVar2 = (int)param_1 - (int)param_2;
  do {
    cVar1 = *param_2;
    param_2[iVar2] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  *(undefined4 *)(param_1 + 0x18) = param_4;
  param_1[0x14] = param_3;
  *(undefined4 *)(param_1 + 0x1c) = param_5;
  *(undefined4 *)(param_1 + 0x20) = param_6;
  if (*(HGDIOBJ *)(param_1 + 0x24) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)(param_1 + 0x24));
  }
  lstrcpyA(local_3c.lfFaceName,param_1);
  local_3c.lfHeight = *(LONG *)(param_1 + 0x18);
  local_3c.lfCharSet = param_1[0x14];
  local_3c.lfWidth = *(LONG *)(param_1 + 0x1c);
  local_3c.lfWeight = *(LONG *)(param_1 + 0x20);
  local_3c.lfEscapement = 0;
  local_3c.lfOrientation = 0;
  local_3c.lfItalic = '\0';
  local_3c.lfOutPrecision = '\0';
  local_3c.lfUnderline = '\0';
  local_3c.lfStrikeOut = '\0';
  local_3c.lfClipPrecision = '\0';
  local_3c.lfQuality = '\x02';
  local_3c.lfPitchAndFamily = '\0';
  h = CreateFontIndirectA(&local_3c);
  *(HFONT *)(param_1 + 0x24) = h;
  SelectObject(*(HDC *)(param_1 + 0x28),h);
  return 1;
}



undefined4 __thiscall