char * FUN_00530e70(char *param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 0xffffffff;
  pcVar2 = param_1;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar4 = ~uVar3 - 1;
  if (((param_1 != (char *)0x0) && (iVar4 != 0)) && (pcVar2 = param_1 + iVar4, -1 < iVar4)) {
    iVar4 = (int)pcVar2 - (int)param_1;
    do {
      if (*pcVar2 == '.') {
        return pcVar2 + 1;
      }
      pcVar2 = pcVar2 + -1;
      iVar4 = iVar4 + -1;
    } while (-1 < iVar4);
  }
  return (char *)0x0;
}


