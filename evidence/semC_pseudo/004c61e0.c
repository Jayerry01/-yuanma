int * FUN_004c61e0(int *param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int local_4;
  
  local_4 = (param_2 - (int)param_1) / 0x1c;
  if (0 < local_4) {
    piVar3 = param_1 + 3;
    do {
      if (param_1 != param_3) {
        iVar2 = piVar3[-2];
        puVar8 = (undefined4 *)*param_1;
        puVar10 = (undefined4 *)*param_3;
        uVar5 = param_3[1] - (int)puVar10;
        uVar4 = iVar2 - (int)puVar8;
        if (uVar5 < uVar4) {
          puVar9 = puVar8;
          for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
            puVar9 = (undefined4 *)((int)puVar9 + 1);
            puVar10 = (undefined4 *)((int)puVar10 + 1);
          }
          FUN_00403490((undefined1 *)((param_3[1] - *param_3) + (int)puVar8),iVar2);
        }
        else {
          for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar10 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar10 = puVar10 + 1;
          }
          for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar10 = (undefined4 *)((int)puVar10 + 1);
          }
          iVar2 = param_3[1];
          iVar7 = *param_3 + uVar4;
          if (iVar7 != iVar2) {
            FUN_005092c0(iVar7,iVar2,1);
            param_3[1] = param_3[1] + (iVar7 - iVar2);
          }
        }
      }
      piVar1 = param_3 + 3;
      if (piVar3 != piVar1) {
        iVar2 = piVar3[1];
        puVar8 = (undefined4 *)*piVar3;
        puVar10 = (undefined4 *)*piVar1;
        uVar4 = iVar2 - (int)puVar8;
        uVar5 = param_3[4] - (int)puVar10;
        if (uVar5 < uVar4) {
          puVar9 = puVar8;
          for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
            puVar9 = (undefined4 *)((int)puVar9 + 1);
            puVar10 = (undefined4 *)((int)puVar10 + 1);
          }
          FUN_00403490((undefined1 *)((param_3[4] - *piVar1) + (int)puVar8),iVar2);
        }
        else {
          for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar10 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar10 = puVar10 + 1;
          }
          for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar10 = (undefined4 *)((int)puVar10 + 1);
          }
          iVar2 = param_3[4];
          iVar7 = *piVar1 + uVar4;
          if (iVar7 != iVar2) {
            FUN_005092c0(iVar7,iVar2,1);
            param_3[4] = param_3[4] + (iVar7 - iVar2);
          }
        }
      }
      param_1 = param_1 + 7;
      piVar6 = param_3 + 7;
      piVar1 = piVar3 + 3;
      piVar3 = piVar3 + 7;
      param_3[6] = *piVar1;
      local_4 = local_4 + -1;
      param_3 = piVar6;
    } while (local_4 != 0);
    return piVar6;
  }
  return param_3;
}


