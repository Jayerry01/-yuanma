LPVOID FUN_0041fe00(UINT param_1,void *param_2,DWORD param_3,LONG *param_4,LONG *param_5,
                   UINT *param_6,UINT *param_7,int *param_8)

{
  DWORD _Size;
  MAT2 MStack_24;
  _GLYPHMETRICS _Stack_14;
  
  if (DAT_005d5a60 == 0) {
    return (LPVOID)0x0;
  }
  MStack_24.eM11 = (FIXED)FUN_0041ff00((float)DAT_007eac60 * 0.03125);
  MStack_24.eM22 = (FIXED)FUN_0041ff00((float)DAT_00724300 * 0.03125);
  MStack_24.eM12 = (FIXED)FUN_0041ff00(0);
  MStack_24.eM21 = MStack_24.eM12;
  _Size = GetGlyphOutlineA(DAT_005d5a68,param_1,1,&_Stack_14,0,(LPVOID)0x0,&MStack_24);
  if (param_2 == (LPVOID)0x0) {
    param_2 = _malloc(_Size);
  }
  else if ((int)param_3 < (int)_Size) {
    _Size = param_3;
  }
  GetGlyphOutlineA(DAT_005d5a68,param_1,1,&_Stack_14,_Size,param_2,&MStack_24);
  *param_6 = _Stack_14.gmBlackBoxX;
  *param_7 = _Stack_14.gmBlackBoxY;
  *param_4 = _Stack_14.gmptGlyphOrigin.x;
  *param_5 = _Stack_14.gmptGlyphOrigin.y;
  *param_8 = (int)_Stack_14.gmCellIncX;
  return param_2;
}


