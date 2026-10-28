int FUN_00579790(char *param_1)

{
  char cVar1;
  int iVar2;
  HDC hdc;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  MAT2 local_24;
  _GLYPHMETRICS local_14;
  
  uVar3 = 0xffffffff;
  pcVar5 = param_1;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  iVar4 = ~uVar3 - 1;
  if ((param_1 == (char *)0x0) || (~uVar3 == 1)) {
    return 0;
  }
  iVar2 = FUN_00593d6d(param_1);
  if (iVar2 != 1) {
    return 2;
  }
  hdc = GetDC((HWND)0x0);
  SelectObject(hdc,DAT_005e092c);
  local_24.eM11 = (FIXED)FUN_00579870(0x3f800000);
  local_24.eM22 = local_24.eM11;
  local_24.eM12 = (FIXED)FUN_00579870(0);
  iVar2 = 1;
  local_24.eM21 = local_24.eM12;
  if (1 < iVar4) {
    do {
      GetGlyphOutlineA(hdc,(uint)(byte)param_1[iVar2],0,&local_14,0,(LPVOID)0x0,&local_24);
      if (local_14.gmCellIncX != 0) break;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar4);
  }
  ReleaseDC((HWND)0x0,hdc);
  return iVar2;
}


