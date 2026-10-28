void FUN_00550a50(char *param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (param_1 != (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar5 = param_1;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar4 = (int)DAT_00725b04 - (int)DAT_00725b00;
    uVar2 = (int)(param_1 + (~uVar3 - 1)) - (int)param_1;
    if (uVar4 < uVar2) {
      pcVar5 = param_1;
      pcVar6 = DAT_00725b00;
      for (uVar2 = uVar4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar6 = pcVar6 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar6 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar6 = pcVar6 + 1;
      }
      FUN_00403490(param_1 + ((int)DAT_00725b04 - (int)DAT_00725b00),param_1 + (~uVar3 - 1));
    }
    else {
      pcVar5 = DAT_00725b00;
      for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined4 *)pcVar5 = *(undefined4 *)param_1;
        param_1 = param_1 + 4;
        pcVar5 = pcVar5 + 4;
      }
      for (uVar3 = uVar2 & 3; pcVar6 = DAT_00725b04, uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar5 = *param_1;
        param_1 = param_1 + 1;
        pcVar5 = pcVar5 + 1;
      }
      pcVar5 = DAT_00725b00 + uVar2;
      if (pcVar5 != DAT_00725b04) {
        FUN_005092c0(pcVar5,DAT_00725b04,1);
        DAT_00725b04 = DAT_00725b04 + ((int)pcVar5 - (int)pcVar6);
        return;
      }
    }
  }
  return;
}


