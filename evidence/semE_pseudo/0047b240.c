int FUN_0047b240(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = &DAT_005ef6c8;
  do {
    if (*piVar1 == 0) {
      FUN_0047b1f0(iVar2 + 1);
      return iVar2 + 1;
    }
    piVar1 = piVar1 + 4;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x5f16c8);
  return 0;
}


