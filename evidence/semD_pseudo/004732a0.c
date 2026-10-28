void __thiscall FUN_004732a0(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  
  pcVar6 = *(char **)(param_1 + 0x8c);
  uVar4 = 0xffffffff;
  pcVar9 = pcVar6;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  pcVar9 = (char *)*param_2;
  uVar5 = param_2[1] - (int)pcVar9;
  uVar3 = (int)(pcVar6 + (~uVar4 - 1)) - (int)pcVar6;
  if (uVar5 < uVar3) {
    pcVar8 = pcVar6;
    for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar9 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar9 = pcVar9 + 1;
    }
    FUN_00403490(pcVar6 + (param_2[1] - *param_2),pcVar6 + (~uVar4 - 1));
  }
  else {
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar9 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    }
    iVar2 = param_2[1];
    iVar7 = *param_2 + uVar3;
    if (iVar7 != iVar2) {
      FUN_005092c0(iVar7,iVar2,1);
      param_2[1] = param_2[1] + (iVar7 - iVar2);
      return;
    }
  }
  return;
}


