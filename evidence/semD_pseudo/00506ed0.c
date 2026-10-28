int * FUN_00506ed0(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  param_1 = ((int)param_2 - param_1) / 0x14;
  if (param_1 < 1) {
    return param_3;
  }
  do {
    piVar2 = param_2 + -5;
    piVar5 = param_3 + -5;
    if (piVar2 != piVar5) {
      iVar1 = param_2[-4];
      puVar6 = (undefined4 *)*piVar2;
      puVar9 = (undefined4 *)*piVar5;
      uVar3 = param_3[-4] - (int)puVar9;
      uVar4 = iVar1 - (int)puVar6;
      if (uVar3 < uVar4) {
        puVar8 = puVar6;
        for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar9 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar9 = puVar9 + 1;
        }
        for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
          puVar8 = (undefined4 *)((int)puVar8 + 1);
          puVar9 = (undefined4 *)((int)puVar9 + 1);
        }
        FUN_00403490((undefined1 *)((int)puVar6 + (param_3[-4] - *piVar5)),iVar1);
      }
      else {
        for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar9 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar9 = puVar9 + 1;
        }
        for (uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined1 *)puVar9 = *(undefined1 *)puVar6;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
          puVar9 = (undefined4 *)((int)puVar9 + 1);
        }
        iVar1 = param_3[-4];
        iVar7 = *piVar5 + uVar4;
        if (iVar7 != iVar1) {
          FUN_005092c0(iVar7,iVar1,1);
          param_3[-4] = param_3[-4] + (iVar7 - iVar1);
        }
      }
    }
    param_3[-2] = param_2[-2];
    param_1 = param_1 + -1;
    param_3[-1] = param_2[-1];
    param_2 = piVar2;
    param_3 = piVar5;
  } while (param_1 != 0);
  return piVar5;
}


