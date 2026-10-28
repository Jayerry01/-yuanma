undefined4 FUN_00479a00(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  bool bVar7;
  char local_294 [8];
  char local_28c [216];
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined *local_190;
  char local_18c [128];
  char local_10c [128];
  char local_8c [128];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059d23b;
  local_c = ExceptionList;
  iVar4 = -(int)param_1;
  do {
    cVar1 = *param_1;
    param_1[(int)(local_28c + iVar4)] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &local_c;
  FUN_0050add7();
  FUN_00593634();
  iVar4 = 5;
  bVar7 = true;
  pcVar3 = local_294;
  pcVar6 = &DAT_005c810c;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar7 = *pcVar3 == *pcVar6;
    pcVar3 = pcVar3 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    uVar2 = FUN_00479170();
    ExceptionList = local_c;
    return uVar2;
  }
  if ((param_2 != (char *)0x0) && (param_2[0x26] != '\0')) {
    FUN_00508ae6();
  }
  iVar4 = FUN_00479e30();
  if (iVar4 == -1) {
    FUN_0050ac20();
    ExceptionList = local_c;
    return 0;
  }
  if (iVar4 == 0) {
    if (param_2 == (char *)0x0) {
      ExceptionList = local_c;
      return 0;
    }
    if (param_2[0x21] != '\0') {
      ExceptionList = local_c;
      return 0;
    }
  }
  FUN_0047f190();
  local_4 = 0;
  if (*(int *)(&DAT_005e0d38 + param_3 * 4) == 0) {
    local_190 = (undefined *)0x0;
    pcVar3 = &DAT_005c7e10 + param_3 * 0x80;
    iVar4 = -(int)pcVar3;
    do {
      cVar1 = *pcVar3;
      pcVar3[(int)(local_10c + iVar4)] = cVar1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
  }
  else {
    local_10c[0] = '\0';
    local_190 = &DAT_005ef5f0 + param_3 * 0x1c;
  }
  if (param_2 == (char *)0x0) {
    if ((local_28c[0] == 'a') || (local_28c[0] == 'A')) {
      FUN_00508ae6();
      uVar5 = 0xffffffff;
      iVar4 = 0;
      pcVar3 = local_18c;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      do {
        pcVar3 = local_18c + iVar4;
        local_8c[iVar4] = *pcVar3;
        iVar4 = iVar4 + 1;
      } while (*pcVar3 != '\0');
      pcVar3 = &DAT_005c4530;
      do {
        cVar1 = *pcVar3;
        (&stack0xffa3ba3f + ~uVar5)[(int)pcVar3] = cVar1;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      cVar1 = FUN_0047f4b0();
      if (cVar1 == '\0') goto LAB_00479d21;
      _DAT_005e0d3c = 2;
    }
    else {
      FUN_00508ae6();
      cVar1 = FUN_0047f4b0();
      if (cVar1 == '\0') {
LAB_00479d21:
        local_4 = 0xffffffff;
        FUN_0047f210();
        ExceptionList = local_c;
        return 0;
      }
      if ((local_28c[0] == 'k') || (local_28c[0] == 'K')) {
        _DAT_005e0d3c = 1;
        FUN_0047f370();
      }
      else {
        _DAT_005e0d3c = 0;
      }
    }
  }
  else {
    if (((*(int *)(param_2 + 0x34) == 0) || (*(int *)(param_2 + 0x28) == 0)) ||
       (*(int *)(param_2 + 0x2c) == 0)) {
      FUN_00508ae6();
      iVar4 = -1;
      pcVar3 = param_2;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      if (iVar4 == -2) {
        cVar1 = FUN_0047f4b0();
        if (cVar1 == '\0') goto LAB_00479d21;
      }
      else {
        FUN_00508ae6();
        cVar1 = FUN_0047f4b0();
        if (cVar1 == '\0') goto LAB_00479d21;
        _DAT_005e0d3c = 2;
      }
    }
    else {
      FUN_0047f780();
    }
    if (param_2[0x25] == '\0') {
      if (param_2[0x20] != '\0') {
        FUN_0047f260();
      }
    }
    else {
      FUN_0047f370();
    }
  }
  FUN_0047fa70();
  if ((param_2 != (char *)0x0) && (param_2[0x26] != '\0')) {
    FUN_0047fd60();
  }
  pcVar3 = local_28c;
  do {
    cVar1 = *pcVar3;
    pcVar3[(int)&DAT_005e0d20 - (int)local_28c] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  _DAT_005e0d30 = local_1b4;
  DAT_005e0d34 = local_1b0;
  if ((param_2 == (char *)0x0) || (uVar2 = 1, *(int *)(param_2 + 0x30) != 1)) {
    uVar2 = FUN_0047f320();
  }
  _DAT_005e0d40 = uVar2;
  FUN_00478bb0();
  (*(code *)PTR_FUN_005c80ac)();
  local_4 = 0xffffffff;
  FUN_0047f210();
  ExceptionList = local_c;
  return 0;
}


