FUN_00461770(int param_1,UINT param_2,LPVOID param_3,DWORD param_4,LONG *param_5,LONG *param_6,
            UINT *param_7,UINT *param_8,int *param_9)

{
  DWORD _Size;
  MAT2 local_24;
  _GLYPHMETRICS local_14;
  
  local_24.eM11.value = 1;
  local_24.eM22.value = 1;
  local_24.eM22.fract = 0;
  local_24.eM11.fract = 0;
  local_24.eM21.fract = 0;
  local_24.eM12.fract = 0;
  local_24.eM21.value = 0;
  local_24.eM12.value = 0;
  _Size = GetGlyphOutlineA(*(HDC *)(param_1 + 0x28),param_2,1,&local_14,0,(LPVOID)0x0,&local_24);
  GetLastError();
  if (param_3 == (LPVOID)0x0) {
    param_3 = _malloc(_Size);
  }
  else if ((int)param_4 < (int)_Size) {
    _Size = param_4;
  }
  GetGlyphOutlineA(*(HDC *)(param_1 + 0x28),param_2,1,&local_14,_Size,param_3,&local_24);
  *param_7 = local_14.gmBlackBoxX;
  *param_8 = local_14.gmBlackBoxY;
  *param_5 = local_14.gmptGlyphOrigin.x;
  *param_6 = local_14.gmptGlyphOrigin.y;
  *param_9 = (int)local_14.gmCellIncX;
  return 1;
}


