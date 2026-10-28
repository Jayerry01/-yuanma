int FUN_00434e00(int param_1,uint param_2)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  MAT2 MStack_24;
  _GLYPHMETRICS _Stack_14;
  
  iVar2 = param_2;
  iVar5 = 0;
  iVar4 = 0;
  if (0 < param_1) {
    do {
      param_2 = (uint)*(byte *)(iVar4 + iVar2);
      if (((char)*(byte *)(iVar4 + iVar2) < '\0') &&
         ((DAT_005e021c == (code *)0x0 || (iVar3 = (*DAT_005e021c)(), iVar3 == 0)))) {
        puVar1 = (undefined1 *)(iVar4 + iVar2);
        iVar3 = iVar4 + 1;
        iVar4 = iVar4 + 1;
        param_2 = (uint)CONCAT11(*puVar1,*(undefined1 *)(iVar3 + iVar2));
      }
      MStack_24.eM11.value = 1;
      MStack_24.eM22.value = 1;
      MStack_24.eM22.fract = 0;
      MStack_24.eM11.fract = 0;
      MStack_24.eM21.fract = 0;
      MStack_24.eM12.fract = 0;
      MStack_24.eM21.value = 0;
      MStack_24.eM12.value = 0;
      GetGlyphOutlineA(DAT_005d9b8c,param_2,1,&_Stack_14,0,(LPVOID)0x0,&MStack_24);
      iVar5 = iVar5 + _Stack_14.gmCellIncX;
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_1);
  }
  return iVar5;
}


