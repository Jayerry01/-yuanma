undefined1 * FUN_0058a6d0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = &DAT_005d2f88;
  do {
    if (*piVar1 == param_1) {
      return &DAT_005d2f8c + iVar2 * 0x14;
    }
    piVar1 = piVar1 + 5;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x5d3078);
  return (undefined1 *)0x0;
}


