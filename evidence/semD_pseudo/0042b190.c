void FUN_0042b190(undefined1 *param_1,char *param_2,char *param_3,char *param_4,char *param_5)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if (param_1 != (undefined1 *)0x0) {
    if ((((param_3 == (char *)0x0) && (param_2 == (char *)0x0)) && (param_4 == (char *)0x0)) &&
       (param_5 == (char *)0x0)) {
      *param_1 = 0;
      return;
    }
    iVar5 = 0;
    if (param_2 != (char *)0x0) {
      iVar3 = -1;
      pcVar2 = param_2;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      if (iVar3 != -2) {
        pcVar2 = param_2;
        do {
          cVar1 = *pcVar2;
          pcVar2[(int)param_1 - (int)param_2] = cVar1;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        uVar4 = 0xffffffff;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *param_2;
          param_2 = param_2 + 1;
        } while (cVar1 != '\0');
        iVar5 = ~uVar4 - 1;
      }
    }
    if (param_3 != (char *)0x0) {
      iVar3 = -1;
      pcVar2 = param_3;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      if (iVar3 != -2) {
        pcVar2 = param_3;
        do {
          cVar1 = *pcVar2;
          pcVar2[(int)(param_1 + (iVar5 - (int)param_3))] = cVar1;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        uVar4 = 0xffffffff;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *param_3;
          param_3 = param_3 + 1;
        } while (cVar1 != '\0');
        iVar5 = iVar5 + (~uVar4 - 1);
      }
    }
    if (param_4 != (char *)0x0) {
      pcVar2 = param_4;
      do {
        cVar1 = *pcVar2;
        pcVar2[(int)(param_1 + (iVar5 - (int)param_4))] = cVar1;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      uVar4 = 0xffffffff;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *param_4;
        param_4 = param_4 + 1;
      } while (cVar1 != '\0');
      iVar5 = iVar5 + (~uVar4 - 1);
    }
    if (param_5 != (char *)0x0) {
      iVar5 = iVar5 - (int)param_5;
      do {
        cVar1 = *param_5;
        param_5[(int)(param_1 + iVar5)] = cVar1;
        param_5 = param_5 + 1;
      } while (cVar1 != '\0');
    }
  }
  return;
}


