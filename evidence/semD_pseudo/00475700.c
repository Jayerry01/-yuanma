char * FUN_00475700(char *param_1)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  bool bVar4;
  
  iVar2 = 2;
  bVar4 = true;
  pcVar1 = param_1;
  pcVar3 = &DAT_005c7de0;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar4 = *pcVar1 == *pcVar3;
    pcVar1 = pcVar1 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return (char *)0x0;
  }
  iVar2 = 2;
  bVar4 = true;
  pcVar1 = param_1;
  pcVar3 = &DAT_005c7ddc;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar4 = *pcVar1 == *pcVar3;
    pcVar1 = pcVar1 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return (char *)0x1;
  }
  iVar2 = 3;
  bVar4 = true;
  pcVar1 = param_1;
  pcVar3 = &DAT_005c7dd8;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar4 = *pcVar1 == *pcVar3;
    pcVar1 = pcVar1 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return (char *)0x2;
  }
  iVar2 = 3;
  bVar4 = true;
  pcVar1 = param_1;
  pcVar3 = &DAT_005c7dd4;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar4 = *pcVar1 == *pcVar3;
    pcVar1 = pcVar1 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return (char *)0x3;
  }
  iVar2 = 2;
  bVar4 = true;
  pcVar1 = param_1;
  pcVar3 = &DAT_005c7dd0;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar4 = *pcVar1 == *pcVar3;
    pcVar1 = pcVar1 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return (char *)0x4;
  }
  iVar2 = 3;
  bVar4 = true;
  pcVar1 = param_1;
  pcVar3 = &DAT_005c7dcc;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar4 = *pcVar1 == *pcVar3;
    pcVar1 = pcVar1 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return (char *)0x5;
  }
  iVar2 = 3;
  bVar4 = true;
  pcVar1 = param_1;
  pcVar3 = &DAT_005c7dc8;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar4 = *pcVar1 == *pcVar3;
    pcVar1 = pcVar1 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return (char *)0x6;
  }
  iVar2 = 2;
  bVar4 = true;
  pcVar1 = param_1;
  pcVar3 = &DAT_005c7dc4;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar4 = *pcVar1 == *pcVar3;
    pcVar1 = pcVar1 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  pcVar1 = (char *)0x7;
  if (!bVar4) {
    pcVar1 = param_1;
  }
  return pcVar1;
}


