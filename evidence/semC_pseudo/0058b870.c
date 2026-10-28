undefined4 FUN_0058b870(char *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  
  DAT_0072c0fc = FUN_00509f8f(param_1,&DAT_005ca380);
  if (DAT_0072c0fc == 0) {
    return 0;
  }
  pcVar5 = param_1;
  do {
    cVar1 = *pcVar5;
    pcVar5[(int)&DAT_0072be08 - (int)param_1] = cVar1;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  pcVar5 = (char *)FUN_0058ba30(param_1);
  pcVar9 = &DAT_0072be30;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    *pcVar9 = cVar1;
    iVar4 = DAT_0072bedc;
    iVar10 = DAT_0072bed8;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  DAT_005d3080 = 1;
  DAT_0072c104 = 0;
  iVar2 = DAT_0072bec8;
  iVar3 = DAT_0072becc;
  for (iVar11 = DAT_0072bed8; DAT_0072bec8 = iVar2, DAT_0072becc = iVar3, iVar11 != iVar4;
      iVar11 = iVar11 + 0xc) {
    FUN_0047a7e0(0);
    iVar2 = DAT_0072bec8;
    iVar3 = DAT_0072becc;
  }
  iVar10 = (int)((ulonglong)((longlong)(iVar4 - iVar10) * -0x2aaaaaab) >> 0x20);
  DAT_0072bedc = DAT_0072bedc + ((iVar10 >> 1) - (iVar10 >> 0x1f)) * 0xc;
  for (iVar10 = iVar2; iVar10 != iVar3; iVar10 = iVar10 + 0x14) {
    FUN_004815f0(0);
  }
  iVar10 = (int)((ulonglong)((longlong)(iVar3 - iVar2) * -0x66666667) >> 0x20);
  DAT_0072becc = DAT_0072becc + ((iVar10 >> 3) - (iVar10 >> 0x1f)) * 0x14;
  uVar7 = 0xffffffff;
  pcVar5 = param_1;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar8 = (int)DAT_0072beb8 - (int)DAT_0072beb4;
  uVar6 = (int)(param_1 + (~uVar7 - 1)) - (int)param_1;
  if (uVar8 < uVar6) {
    pcVar5 = param_1;
    pcVar9 = DAT_0072beb4;
    for (uVar6 = uVar8 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *pcVar9 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar9 = pcVar9 + 1;
    }
    FUN_00403490(param_1 + ((int)DAT_0072beb8 - (int)DAT_0072beb4),param_1 + (~uVar7 - 1));
  }
  else {
    pcVar5 = DAT_0072beb4;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)param_1;
      param_1 = param_1 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar7 = uVar6 & 3; pcVar9 = DAT_0072beb8, uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar5 = *param_1;
      param_1 = param_1 + 1;
      pcVar5 = pcVar5 + 1;
    }
    pcVar5 = DAT_0072beb4 + uVar6;
    if (pcVar5 != DAT_0072beb8) {
      FUN_005092c0(pcVar5,DAT_0072beb8,1);
      DAT_0072beb8 = DAT_0072beb8 + ((int)pcVar5 - (int)pcVar9);
    }
  }
  DAT_0072bec0 = DAT_0072c0fc;
  DAT_0072bec4 = DAT_005d3080;
  FUN_005910e0(param_2);
  return 1;
}


