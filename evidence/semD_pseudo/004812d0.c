int * FUN_004812d0(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int *piVar6;
  
  iVar1 = ((int)param_2 - param_1) / 0x18;
  piVar5 = param_2;
  param_2 = (int *)iVar1;
  if (iVar1 < 1) {
    return param_3;
  }
  do {
    piVar6 = piVar5 + -6;
    piVar4 = param_3 + -6;
    if (piVar6 != piVar4) {
      iVar1 = piVar5[-5];
      puVar7 = (undefined4 *)*piVar6;
      puVar10 = (undefined4 *)*piVar4;
      uVar3 = iVar1 - (int)puVar7;
      uVar2 = param_3[-5] - (int)puVar10;
      if (uVar2 < uVar3) {
        puVar9 = puVar7;
        for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar10 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        }
        for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
          puVar9 = (undefined4 *)((int)puVar9 + 1);
          puVar10 = (undefined4 *)((int)puVar10 + 1);
        }
        FUN_00403490((undefined1 *)((int)puVar7 + (param_3[-5] - *piVar4)),iVar1);
      }
      else {
        for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar10 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar10 = puVar10 + 1;
        }
        for (uVar2 = uVar3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined1 *)puVar10 = *(undefined1 *)puVar7;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
          puVar10 = (undefined4 *)((int)puVar10 + 1);
        }
        iVar1 = param_3[-5];
        iVar8 = *piVar4 + uVar3;
        if (iVar8 != iVar1) {
          FUN_005092c0(iVar8,iVar1,1);
          param_3[-5] = param_3[-5] + (iVar8 - iVar1);
        }
      }
    }
    param_3[-3] = piVar5[-3];
    param_3[-2] = piVar5[-2];
    param_2 = (int *)((int)param_2 + -1);
    param_3[-1] = piVar5[-1];
    param_3 = piVar4;
    piVar5 = piVar6;
  } while (param_2 != (int *)0x0);
  return piVar4;
}


