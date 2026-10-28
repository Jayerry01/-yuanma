void FUN_00420380(int *param_1,void *param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 int param_6)

{
  int *piVar1;
  void *pvVar2;
  void *pvVar3;
  void *pvVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  int iVar11;
  bool bVar12;
  int local_10;
  
  pvVar2 = param_2;
  piVar1 = param_1;
  if ((int)param_2 < 3) {
    if (param_2 != (void *)0x2) {
      return;
    }
    FUN_0041fa20(*param_1,param_1[1],param_1[2],param_1[3],param_3);
    return;
  }
  iVar11 = 0;
  if (param_4 == 0) goto LAB_0042063a;
  pvVar5 = (void *)param_1[1];
  param_1 = (int *)*param_1;
  iVar6 = 1;
  local_10 = 0;
  bVar10 = 1 < (int)param_2;
  param_2 = pvVar5;
  param_4 = (int)param_1;
  if (bVar10) {
    do {
      pvVar4 = (void *)piVar1[iVar6 * 2 + 1];
      if ((int)pvVar4 < (int)pvVar5) {
        pvVar5 = pvVar4;
        iVar11 = iVar6;
      }
      if ((int)param_2 < (int)pvVar4) {
        param_2 = pvVar4;
        local_10 = iVar6;
      }
      iVar9 = piVar1[iVar6 * 2];
      if (iVar9 < (int)param_1) {
        param_1 = (int *)iVar9;
      }
      if (param_4 < iVar9) {
        param_4 = iVar9;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)pvVar2);
  }
  if (*(int *)(DAT_005d5a0c + 0x68c) <= (int)pvVar5) {
    return;
  }
  if ((int)param_2 < 0) {
    return;
  }
  if (*(int *)(DAT_005d5a0c + 0x690) <= (int)param_1) {
    return;
  }
  if (param_4 < 0) {
    return;
  }
  if (pvVar5 == param_2) goto LAB_0042063a;
  pvVar4 = (void *)piVar1[iVar11 * 2 + 1];
  iVar6 = iVar11;
  while (pvVar4 == pvVar5) {
    iVar6 = (iVar6 + 1) % (int)pvVar2;
    pvVar4 = (void *)piVar1[iVar6 * 2 + 1];
  }
  param_1 = (int *)((iVar6 + -1 + (int)pvVar2) % (int)pvVar2);
  pvVar4 = (void *)piVar1[iVar11 * 2 + 1];
  while (pvVar4 == pvVar5) {
    iVar11 = ((int)pvVar2 + iVar11 + -1) % (int)pvVar2;
    pvVar4 = (void *)piVar1[iVar11 * 2 + 1];
  }
  param_4 = -1;
  iVar6 = (iVar11 + 1) % (int)pvVar2;
  uVar7 = (uint)(piVar1[iVar6 * 2] != piVar1[(int)param_1 * 2]);
  iVar11 = iVar6;
  if (uVar7 == 1) {
    if (piVar1[(int)param_1 * 2] < piVar1[iVar6 * 2]) {
LAB_00420528:
      param_4 = 1;
      iVar11 = (int)param_1;
      param_1 = (int *)iVar6;
    }
  }
  else {
    iVar9 = ((int)param_1 + 1) % (int)pvVar2;
    iVar8 = (iVar6 + -1 + (int)pvVar2) % (int)pvVar2;
    if ((piVar1[iVar8 * 2 + 1] - piVar1[iVar6 * 2 + 1]) * (piVar1[iVar9 * 2] - piVar1[iVar6 * 2]) -
        (piVar1[iVar9 * 2 + 1] - piVar1[iVar6 * 2 + 1]) * (piVar1[iVar8 * 2] - piVar1[iVar6 * 2]) <
        0) goto LAB_00420528;
  }
  iVar6 = (uVar7 - (int)pvVar5) + -1 + (int)param_2;
  if (0 < iVar6) {
    pvVar4 = _malloc(iVar6 * 8);
    bVar12 = uVar7 == 0;
    param_2 = pvVar4;
    bVar10 = bVar12;
    do {
      iVar9 = iVar11 + 1;
      if (param_4 < 1) {
        iVar9 = iVar11 + -1 + (int)pvVar2;
      }
      iVar9 = iVar9 % (int)pvVar2;
      FUN_00420730(piVar1[iVar11 * 2],piVar1[iVar11 * 2 + 1],piVar1[iVar9 * 2],piVar1[iVar9 * 2 + 1]
                   ,1,bVar10,&param_2);
      bVar10 = false;
      iVar11 = iVar9;
      pvVar3 = pvVar4;
    } while (iVar9 != local_10);
    do {
      param_2 = pvVar3;
      iVar11 = (int)param_1 + 1;
      if (-1 < param_4) {
        iVar11 = (int)param_1 + -1 + (int)pvVar2;
      }
      iVar11 = iVar11 % (int)pvVar2;
      FUN_00420730(piVar1[(int)param_1 * 2] + -1,piVar1[(int)param_1 * 2 + 1],
                   piVar1[iVar11 * 2] + -1,piVar1[iVar11 * 2 + 1],0,bVar12,&param_2);
      bVar12 = false;
      param_1 = (int *)iVar11;
      pvVar3 = param_2;
    } while (iVar11 != local_10);
    FUN_004206b0(pvVar4,(int)pvVar5 + (1 - uVar7),iVar6,param_3);
    FUN_005089fd(pvVar4);
  }
LAB_0042063a:
  if (param_6 != 0) {
    iVar11 = piVar1[1];
    iVar6 = *piVar1;
    FUN_0041fa20(piVar1[(int)pvVar2 * 2 + -2],piVar1[(int)pvVar2 * 2 + -1],iVar6,iVar11,param_5);
    param_1 = (int *)0x1;
    if (1 < (int)pvVar2) {
      do {
        iVar9 = piVar1[(int)param_1 * 2];
        iVar8 = piVar1[(int)param_1 * 2 + 1];
        FUN_0041fa20(iVar6,iVar11,iVar9,iVar8,param_5);
        param_1 = (int *)((int)param_1 + 1);
        iVar11 = iVar8;
        iVar6 = iVar9;
      } while ((int)param_1 < (int)pvVar2);
    }
  }
  return;
}


