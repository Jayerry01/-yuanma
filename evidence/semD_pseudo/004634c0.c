void FUN_004634c0(char *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  
  iVar2 = FUN_0050aba0(param_1,&DAT_005c4418);
  while (iVar2 != 0) {
    uVar3 = iVar2 - (int)param_1;
    uVar4 = 0xffffffff;
    pcVar5 = param_1;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    if (uVar3 < ~uVar4 - 2) {
      do {
        param_1[uVar3] = param_1[uVar3 + 1];
        uVar4 = 0xffffffff;
        uVar3 = uVar3 + 1;
        pcVar5 = param_1;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
      } while (uVar3 < ~uVar4 - 2);
    }
    param_1[uVar3] = '\0';
    iVar2 = FUN_0050aba0(param_1,&DAT_005c4418);
  }
  iVar2 = FUN_0050aba0(param_1,&DAT_005c462c);
  do {
    if (iVar2 == 0) {
      return;
    }
    uVar3 = iVar2 - (int)param_1;
    uVar4 = 0xffffffff;
    pcVar5 = param_1;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    if (uVar3 < ~uVar4 - 2) {
      do {
        param_1[uVar3] = param_1[uVar3 + 1];
        uVar4 = 0xffffffff;
        uVar3 = uVar3 + 1;
        pcVar5 = param_1;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
      } while (uVar3 < ~uVar4 - 2);
    }
    param_1[uVar3] = '\0';
    iVar2 = FUN_0050aba0(param_1,&DAT_005c462c);
  } while( true );
}


