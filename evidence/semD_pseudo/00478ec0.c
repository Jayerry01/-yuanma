undefined4 FUN_00478ec0(char *param_1,int param_2)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  
  if ((param_2 < 0) && (4 < param_2)) {
    return 0;
  }
  uVar5 = 0xffffffff;
  pcVar8 = param_1;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar2 != '\0');
  iVar7 = param_2 * 0x80;
  pcVar8 = &DAT_005c7e10 + iVar7;
  iVar6 = (int)pcVar8 - (int)param_1;
  do {
    cVar2 = *param_1;
    param_1[iVar6] = cVar2;
    param_1 = param_1 + 1;
  } while (cVar2 != '\0');
  FUN_00593634(pcVar8);
  iVar6 = FUN_0050aba0(pcVar8,&DAT_005c80cc);
  if ((iVar6 == 0) && (iVar6 = FUN_0050aba0(pcVar8,&DAT_005c80c4), cVar2 = DAT_005c80d0, iVar6 == 0)
     ) {
    iVar6 = -1;
    pcVar9 = pcVar8;
    if (*(char *)(iVar7 + 0x5c7e0f + (~uVar5 - 1)) == '\\') {
      *(undefined1 *)(iVar7 + 0x5c7e0f + (~uVar5 - 1)) = 0;
      cVar2 = DAT_005c80d0;
      do {
        pcVar10 = pcVar9;
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        pcVar10 = pcVar9 + 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar10;
      } while (cVar1 != '\0');
      *(undefined4 *)(pcVar10 + -1) = DAT_005c80cc;
      pcVar10[3] = cVar2;
    }
    else {
      do {
        pcVar10 = pcVar9;
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        pcVar10 = pcVar9 + 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar10;
      } while (cVar1 != '\0');
      *(undefined4 *)(pcVar10 + -1) = DAT_005c80cc;
      pcVar10[3] = cVar2;
    }
  }
  cVar2 = FUN_00480860(pcVar8);
  if (cVar2 == '\0') {
    *(undefined4 *)(&DAT_005e0d38 + param_2 * 4) = 0;
    uVar3 = FUN_004807f0(pcVar8);
    uVar4 = FUN_004807d0(pcVar8);
    FUN_00508ae6(pcVar8,s__s_s__005c80bc,uVar3,uVar4);
    return 1;
  }
  *(undefined4 *)(&DAT_005e0d38 + param_2 * 4) = 1;
  return 1;
}


