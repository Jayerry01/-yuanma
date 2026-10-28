undefined1 FUN_004ace50(undefined4 *param_1)

{
  char cVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  
  uVar3 = 0xffffffff;
  pcVar5 = s_Agent_005c9190;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  iVar4 = ~uVar3 - 1;
  if (param_1[1] - (int)*param_1 == iVar4) {
    bVar7 = true;
    pcVar5 = (char *)*param_1;
    pcVar6 = s_Agent_005c9190;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar7 = *pcVar5 == *pcVar6;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (bVar7) {
      return 1;
    }
  }
  FUN_004b3420();
  uVar2 = FUN_00550ec0(*param_1);
  return uVar2;
}


