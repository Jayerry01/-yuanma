int * FUN_004fa810(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  
  param_1 = ((int)param_2 - param_1) / 0x1c;
  if (param_1 < 1) {
    return param_3;
  }
  piVar3 = param_2 + 3;
  do {
    param_2 = param_2 + -7;
    piVar7 = param_3 + -7;
    piVar4 = piVar3 + -7;
    if (param_2 != piVar7) {
      iVar2 = piVar3[-9];
      puVar9 = (undefined4 *)*param_2;
      puVar11 = (undefined4 *)*piVar7;
      uVar5 = param_3[-6] - (int)puVar11;
      uVar6 = iVar2 - (int)puVar9;
      if (uVar5 < uVar6) {
        puVar10 = puVar9;
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar11 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar11 = puVar11 + 1;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
          puVar10 = (undefined4 *)((int)puVar10 + 1);
          puVar11 = (undefined4 *)((int)puVar11 + 1);
        }
        FUN_00403490((undefined1 *)((int)puVar9 + (param_3[-6] - *piVar7)),iVar2);
      }
      else {
        for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar11 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar11 = puVar11 + 1;
        }
        for (uVar5 = uVar6 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
          puVar9 = (undefined4 *)((int)puVar9 + 1);
          puVar11 = (undefined4 *)((int)puVar11 + 1);
        }
        iVar2 = param_3[-6];
        iVar8 = *piVar7 + uVar6;
        if (iVar8 != iVar2) {
          FUN_005092c0(iVar8,iVar2,1);
          param_3[-6] = param_3[-6] + (iVar8 - iVar2);
        }
      }
    }
    piVar1 = param_3 + -4;
    if (piVar4 != piVar1) {
      iVar2 = piVar3[-6];
      puVar9 = (undefined4 *)*piVar4;
      puVar11 = (undefined4 *)*piVar1;
      uVar5 = iVar2 - (int)puVar9;
      uVar6 = param_3[-3] - (int)puVar11;
      if (uVar6 < uVar5) {
        puVar10 = puVar9;
        for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar11 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar11 = puVar11 + 1;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
          puVar10 = (undefined4 *)((int)puVar10 + 1);
          puVar11 = (undefined4 *)((int)puVar11 + 1);
        }
        FUN_00403490((undefined1 *)((param_3[-3] - *piVar1) + (int)puVar9),iVar2);
      }
      else {
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar11 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar11 = puVar11 + 1;
        }
        for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
          puVar9 = (undefined4 *)((int)puVar9 + 1);
          puVar11 = (undefined4 *)((int)puVar11 + 1);
        }
        iVar2 = param_3[-3];
        iVar8 = *piVar1 + uVar5;
        if (iVar8 != iVar2) {
          FUN_005092c0(iVar8,iVar2,1);
          param_3[-3] = param_3[-3] + (iVar8 - iVar2);
        }
      }
    }
    param_3[-1] = piVar3[-4];
    param_1 = param_1 + -1;
    piVar3 = piVar4;
    param_3 = piVar7;
  } while (param_1 != 0);
  return piVar7;
}


