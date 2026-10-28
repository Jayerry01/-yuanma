undefined4 FUN_00434ec0(ushort param_1,int param_2)

{
  int iVar1;
  
  if ((DAT_005e021c == (code *)0x0) || (iVar1 = (*DAT_005e021c)(), iVar1 == 0)) {
    if (param_2 != 0) {
      if (param_2 == 2) {
        return 3;
      }
      return 0;
    }
    if ((param_1 < 0xff) && (0x80 < param_1)) {
      return 2;
    }
  }
  return 1;
}



undefined4