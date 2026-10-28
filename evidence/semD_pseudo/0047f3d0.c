undefined4 FUN_0047f3d0(undefined4 param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  pcVar1 = (char *)FUN_0047f480(param_1);
  iVar3 = 4;
  bVar6 = true;
  pcVar4 = pcVar1;
  pcVar5 = &DAT_005c8184;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    return 0x425;
  }
  iVar3 = 4;
  bVar6 = true;
  pcVar4 = pcVar1;
  pcVar5 = &DAT_005c8180;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    return 0x420;
  }
  iVar3 = 4;
  bVar6 = true;
  pcVar4 = pcVar1;
  pcVar5 = &DAT_005c817c;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    return 0x42d;
  }
  iVar3 = 4;
  bVar6 = true;
  pcVar4 = pcVar1;
  pcVar5 = &DAT_005c8178;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    return 0x436;
  }
  iVar3 = 4;
  bVar6 = true;
  pcVar4 = &DAT_005c8174;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar1 == *pcVar4;
    pcVar1 = pcVar1 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar6);
  uVar2 = 0x428;
  if (!bVar6) {
    uVar2 = 0x420;
  }
  return uVar2;
}


