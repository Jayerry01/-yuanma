undefined4 __thiscall FUN_00568f80(int param_1,char *param_2,undefined1 param_3)

{
  char cVar1;
  bool bVar2;
  void *pvVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  bool bVar11;
  undefined *puVar12;
  char local_10 [16];
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  FUN_005679f0();
  pvVar3 = operator_new(0x124);
  if (pvVar3 == (void *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)FUN_00567440();
  }
  *(int **)(param_1 + 0x120) = piVar4;
  if (piVar4 == (int *)0x0) {
    return 0;
  }
  *piVar4 = *piVar4 + 1;
  *(undefined1 *)(*(int *)(param_1 + 0x120) + 0x1c) = param_3;
  uVar8 = 0xffffffff;
  pcVar9 = param_2;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  if (param_2[~uVar8 - 2] != 'b') {
    puVar12 = &DAT_005ca380;
  }
  else {
    puVar12 = &DAT_005c4580;
  }
  bVar2 = param_2[~uVar8 - 2] == 'b';
  iVar5 = FUN_00509f8f(param_2,puVar12);
  if (iVar5 == 0) {
    return 0;
  }
  uVar6 = FUN_005156ca(param_2);
  *(undefined4 *)(*(int *)(param_1 + 0x120) + 0x48) = uVar6;
  if (*(int *)(*(int *)(param_1 + 0x120) + 0x48) == 0) {
    FUN_00509e57(iVar5);
    return 0;
  }
  if (bVar2) {
    uVar8 = 0xffffffff;
    pcVar9 = &DAT_005d1734;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    FUN_0050a118(local_10,~uVar8 - 1,1,iVar5);
    (&stack0xffffffef)[~uVar8] = 0;
    iVar7 = 0xb;
    bVar11 = true;
    pcVar9 = local_10;
    pcVar10 = &DAT_005d1734;
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      bVar11 = *pcVar9 == *pcVar10;
      pcVar9 = pcVar9 + 1;
      pcVar10 = pcVar10 + 1;
    } while (bVar11);
    if (!bVar11) goto LAB_005690d7;
  }
  else {
    FUN_00480830(iVar5,2);
  }
  iVar7 = FUN_00567a50(iVar5,bVar2);
  if (iVar7 != 0) {
    iVar7 = FUN_00567cc0(iVar5,bVar2);
    if (iVar7 != 0) {
      iVar7 = FUN_00568ab0(iVar5,bVar2);
      if (iVar7 != 0) {
        FUN_00509e57(iVar5);
        *(undefined1 *)(*(int *)(param_1 + 0x120) + 0x1d) = 1;
        return 1;
      }
    }
  }
LAB_005690d7:
  FUN_00509e57(iVar5);
  FUN_005679f0();
  return 0;
}


