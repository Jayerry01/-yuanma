void FUN_0042a6c0(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  
  FUN_00508ae6(&DAT_007ddba0,&DAT_005c67ac,param_1);
  uVar2 = 0xffffffff;
  pcVar4 = (char *)&DAT_007ddba0;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if ((&DAT_007ddb9e)[~uVar2] != '\\') {
    iVar3 = -1;
    pcVar4 = (char *)&DAT_007ddba0;
    do {
      pcVar5 = pcVar4;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar5 = pcVar4 + 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar5;
    } while (cVar1 != '\0');
    *(undefined2 *)(pcVar5 + -1) = DAT_005c67a8;
  }
  return;
}


