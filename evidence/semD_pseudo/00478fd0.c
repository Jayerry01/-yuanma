undefined4 FUN_00478fd0(char *param_1)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  
  uVar5 = 0xffffffff;
  pcVar7 = param_1;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  iVar6 = (int)&DAT_005ef550 - (int)param_1;
  do {
    cVar2 = *param_1;
    param_1[iVar6] = cVar2;
    param_1 = param_1 + 1;
  } while (cVar2 != '\0');
  FUN_00593634(&DAT_005ef550);
  iVar6 = FUN_0050aba0(&DAT_005ef550,&DAT_005c80cc);
  if (iVar6 == 0) {
    iVar6 = FUN_0050aba0(&DAT_005ef550,&DAT_005c80c4);
    cVar2 = DAT_005c80d0;
    if (iVar6 == 0) {
      iVar6 = -1;
      if ((&DAT_005ef54e)[~uVar5] == '\\') {
        (&DAT_005ef54e)[~uVar5] = 0;
        cVar2 = DAT_005c80d0;
        pcVar7 = (char *)&DAT_005ef550;
        do {
          pcVar8 = pcVar7;
          if (iVar6 == 0) break;
          iVar6 = iVar6 + -1;
          pcVar8 = pcVar7 + 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar8;
        } while (cVar1 != '\0');
        *(undefined4 *)(pcVar8 + -1) = DAT_005c80cc;
        pcVar8[3] = cVar2;
      }
      else {
        pcVar7 = (char *)&DAT_005ef550;
        do {
          pcVar8 = pcVar7;
          if (iVar6 == 0) break;
          iVar6 = iVar6 + -1;
          pcVar8 = pcVar7 + 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar8;
        } while (cVar1 != '\0');
        *(undefined4 *)(pcVar8 + -1) = DAT_005c80cc;
        pcVar8[3] = cVar2;
      }
    }
  }
  cVar2 = FUN_00480860(&DAT_005ef550);
  if (cVar2 != '\0') {
    DAT_005ef67c = 1;
    return 1;
  }
  DAT_005ef67c = 0;
  uVar3 = FUN_004807f0(&DAT_005ef550);
  uVar4 = FUN_004807d0(&DAT_005ef550);
  FUN_00508ae6(&DAT_005ef550,s__s_s__005c80bc,uVar3,uVar4);
  return 1;
}


