int * FUN_0055e8b0(int param_1,int param_2,int *param_3)

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
  
  iVar1 = (param_2 - param_1) / 0xc;
  piVar5 = param_3;
  if (0 < iVar1) {
    param_1 = param_1 - (int)param_3;
    param_3 = (int *)iVar1;
    do {
      piVar2 = (int *)(param_1 + (int)piVar5);
      if (piVar2 != piVar5) {
        iVar1 = piVar2[1];
        puVar6 = (undefined4 *)*piVar2;
        puVar9 = (undefined4 *)*piVar5;
        uVar4 = piVar5[1] - (int)puVar9;
        uVar3 = iVar1 - (int)puVar6;
        if (uVar4 < uVar3) {
          puVar8 = puVar6;
          for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          }
          for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar9 = (undefined4 *)((int)puVar9 + 1);
          }
          FUN_00403490((undefined1 *)((piVar5[1] - *piVar5) + (int)puVar6),iVar1);
        }
        else {
          for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar9 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar9 = puVar9 + 1;
          }
          for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar9 = *(undefined1 *)puVar6;
            puVar6 = (undefined4 *)((int)puVar6 + 1);
            puVar9 = (undefined4 *)((int)puVar9 + 1);
          }
          iVar1 = piVar5[1];
          iVar7 = *piVar5 + uVar3;
          if (iVar7 != iVar1) {
            FUN_005092c0(iVar7,iVar1,1);
            piVar5[1] = piVar5[1] + (iVar7 - iVar1);
          }
        }
      }
      piVar5 = piVar5 + 3;
      param_3 = (int *)((int)param_3 + -1);
    } while (param_3 != (int *)0x0);
  }
  return piVar5;
}


