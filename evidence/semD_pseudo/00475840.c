char FUN_00475840(char *param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  iVar1 = 2;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = (char *)&DAT_005c7938;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\0';
  }
  iVar1 = 2;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = &DAT_005c7474;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\x01';
  }
  iVar1 = 2;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = &DAT_005c7e08;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\x02';
  }
  iVar1 = 4;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = &DAT_005c7e04;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\x04';
  }
  iVar1 = 2;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = &DAT_005c7e00;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\x03';
  }
  iVar1 = 4;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = &DAT_005c7dfc;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\x05';
  }
  iVar1 = 3;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = &DAT_005c7df8;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\x06';
  }
  iVar1 = 5;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = &DAT_005c7df0;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\a';
  }
  iVar1 = 3;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = &DAT_005c7dec;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\b';
  }
  iVar1 = 5;
  bVar4 = true;
  pcVar2 = &DAT_005c7de4;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *param_1 == *pcVar2;
    param_1 = param_1 + 1;
    pcVar2 = pcVar2 + 1;
  } while (bVar4);
  return bVar4 * '\b' + '\x01';
}


