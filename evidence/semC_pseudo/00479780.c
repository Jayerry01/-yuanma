undefined4 FUN_00479780(char *param_1,int param_2)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  char *pcVar7;
  char local_18c [64];
  char local_14c [64];
  char local_10c [248];
  void *pvStack_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059d21e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (DAT_005ef684 == 0) {
    ExceptionList = &local_c;
    pvVar2 = operator_new(0xc0);
    local_4 = 0;
    if (pvVar2 == (void *)0x0) {
      DAT_005ef684 = 0;
    }
    else {
      DAT_005ef684 = FUN_0047f190();
    }
  }
  local_4 = 0xffffffff;
  iVar3 = FUN_0050aba0();
  if (iVar3 == 0) {
    FUN_00508ae6();
    FUN_00508ae6();
  }
  else {
    pcVar4 = param_1;
    do {
      cVar1 = *pcVar4;
      pcVar4[(int)(local_18c + -(int)param_1)] = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar4 = param_1;
    do {
      cVar1 = *pcVar4;
      pcVar4[(int)(local_14c + -(int)param_1)] = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar6 = 0xffffffff;
    pcVar7 = &DAT_005c4530;
    pcVar4 = param_1;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    do {
      cVar1 = *pcVar7;
      (&stack0xffa3b93f + ~uVar6)[(int)pcVar7] = cVar1;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    uVar6 = 0xffffffff;
    pcVar7 = &DAT_005c80d8;
    pcVar4 = param_1;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    do {
      cVar1 = *pcVar7;
      (&stack0xffa37dd7 + ~uVar6)[(int)pcVar7] = cVar1;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
  }
  if (DAT_005ef67c == 0) {
    iVar3 = 0;
    *(undefined4 *)(DAT_005ef684 + 0xbc) = 0;
    do {
      cVar1 = *(char *)((int)&DAT_005ef550 + iVar3);
      local_10c[iVar3] = cVar1;
      iVar3 = iVar3 + 1;
    } while (cVar1 != '\0');
  }
  else {
    *(undefined **)(DAT_005ef684 + 0xbc) = &DAT_005ef5d0;
    local_10c[0] = '\0';
  }
  iVar3 = 0;
  do {
    FUN_00508ae6();
    cVar1 = FUN_0047f4b0();
    if (cVar1 != '\0') {
      uVar5 = FUN_0047f290();
      *(undefined4 *)param_1 = uVar5;
      uVar5 = FUN_0047f2c0();
      *(undefined4 *)param_1 = uVar5;
      if (param_2 == 0) {
        uVar5 = FUN_0047f2f0();
        ExceptionList = pvStack_14;
        return uVar5;
      }
      uVar5 = FUN_00480040();
      ExceptionList = pvStack_14;
      return uVar5;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  ExceptionList = local_c;
  return 0;
}


