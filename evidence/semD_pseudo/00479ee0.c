undefined4 FUN_00479ee0(uint param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_1 < 2000) {
    if ((param_1 != 0) && (param_1 < 0x401)) {
      iVar2 = -1;
      pcVar3 = (char *)(&DAT_005e0d20 + param_1 * 0xc);
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      if (iVar2 != -2) {
        FUN_00478bc0();
        return 1;
      }
    }
  }
  else if (param_1 < 0x8d1) {
    iVar2 = -1;
    pcVar3 = &DAT_005ecd50 + (param_1 * 5 + -0x2715) * 8;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (iVar2 != -2) {
      FUN_00478c20();
      return 1;
    }
  }
  return 0;
}


