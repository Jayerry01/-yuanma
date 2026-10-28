int * FUN_0047a590(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  param_1 = ((int)param_2 - param_1) / 0xc;
  if (param_1 < 1) {
    return param_3;
  }
  do {
    piVar5 = param_2 + -3;
    piVar4 = param_3 + -3;
    if (piVar5 != piVar4) {
      iVar1 = param_2[-2];
      puVar6 = (undefined4 *)*piVar5;
      puVar9 = (undefined4 *)*piVar4;
      uVar2 = param_3[-2] - (int)puVar9;
      uVar3 = iVar1 - (int)puVar6;
      if (uVar2 < uVar3) {
        puVar8 = puVar6;
        for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar9 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar9 = puVar9 + 1;
        }
        for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
          puVar8 = (undefined4 *)((int)puVar8 + 1);
          puVar9 = (undefined4 *)((int)puVar9 + 1);
        }
        FUN_00403490((undefined1 *)((int)puVar6 + (param_3[-2] - *piVar4)),iVar1);
      }
      else {
        for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar9 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar9 = puVar9 + 1;
        }
        for (uVar2 = uVar3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined1 *)puVar9 = *(undefined1 *)puVar6;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
          puVar9 = (undefined4 *)((int)puVar9 + 1);
        }
        iVar1 = param_3[-2];
        iVar7 = *piVar4 + uVar3;
        if (iVar7 != iVar1) {
          FUN_005092c0(iVar7,iVar1,1);
          param_3[-2] = param_3[-2] + (iVar7 - iVar1);
        }
      }
    }
    param_1 = param_1 + -1;
    param_3 = piVar4;
    param_2 = piVar5;
  } while (param_1 != 0);
  return piVar4;
}


