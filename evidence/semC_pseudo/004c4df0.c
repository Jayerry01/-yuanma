int * __thiscall FUN_004c4df0(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  if (param_2 != param_1) {
    iVar2 = param_2[1];
    puVar4 = (undefined4 *)*param_2;
    puVar3 = (undefined4 *)*param_1;
    uVar6 = iVar2 - (int)puVar4 >> 3;
    if ((uint)(param_1[2] - (int)puVar3 >> 3) < uVar6) {
      iVar1 = FUN_004c4300(uVar6,puVar4,iVar2);
      iVar2 = param_1[1];
      for (iVar7 = *param_1; iVar7 != iVar2; iVar7 = iVar7 + 8) {
        FUN_004e8500();
      }
      iVar2 = param_1[2] - *param_1 >> 3;
      if (iVar2 != 0) {
        FUN_00402e90(*param_1,iVar2 << 3);
      }
      *param_1 = iVar1;
      param_1[2] = iVar1 + uVar6 * 8;
      param_1[1] = iVar1 + uVar6 * 8;
      return param_1;
    }
    uVar5 = param_1[1] - (int)puVar3 >> 3;
    if (uVar5 < uVar6) {
      iVar2 = (int)(uVar5 * 8) >> 3;
      if (0 < iVar2) {
        do {
          *puVar3 = *puVar4;
          puVar3[1] = puVar4[1];
          puVar3 = puVar3 + 2;
          iVar2 = iVar2 + -1;
          puVar4 = puVar4 + 2;
        } while (iVar2 != 0);
      }
      FUN_004c6f20(*param_2 + (param_1[1] - *param_1 >> 3) * 8,param_2[1],param_1[1],param_2);
    }
    else {
      iVar2 = iVar2 - (int)puVar4 >> 3;
      if (0 < iVar2) {
        do {
          *puVar3 = *puVar4;
          puVar3[1] = puVar4[1];
          puVar3 = puVar3 + 2;
          iVar2 = iVar2 + -1;
          puVar4 = puVar4 + 2;
        } while (iVar2 != 0);
      }
      puVar4 = (undefined4 *)param_1[1];
      if (puVar3 != puVar4) {
        do {
          FUN_004e8500();
          puVar3 = puVar3 + 2;
        } while (puVar3 != puVar4);
        param_1[1] = *param_1 + uVar6 * 8;
        return param_1;
      }
    }
    param_1[1] = *param_1 + uVar6 * 8;
  }
  return param_1;
}


