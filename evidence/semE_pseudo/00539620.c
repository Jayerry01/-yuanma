void FUN_00539620(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  piVar2 = &DAT_00723304;
  do {
    iVar3 = 3;
    piVar1 = piVar2 + -3;
    do {
      *piVar1 = *piVar1 >> 4;
      iVar3 = iVar3 + -1;
      piVar1 = piVar1 + 1;
    } while (iVar3 != 0);
    *piVar2 = iVar4;
    piVar2 = piVar2 + 4;
    iVar4 = iVar4 + 1;
  } while ((int)piVar2 < 0x724304);
  return;
}


