int FUN_00530ae0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  
  piVar2 = param_1;
  iVar10 = 0;
  if (param_1 == (int *)0x0) {
    FUN_00530d00(0x509);
    return 0;
  }
  if (param_1[10] == 0x601) {
    iVar3 = param_1[5];
  }
  else {
    iVar3 = FUN_0052cf80(param_1);
  }
  if ((param_1[8] == 0x1907) || (iVar5 = iVar3, param_1[8] == 0x1908)) {
    iVar5 = FUN_00530d80(param_1[6]);
    if (iVar5 == 0) {
      return 0;
    }
    uVar4 = 0;
    if (param_1[6] != 0) {
      do {
        *(undefined1 *)(uVar4 + iVar5) = *(undefined1 *)(iVar3 + 2 + uVar4);
        *(undefined1 *)(iVar5 + 1 + uVar4) = *(undefined1 *)(iVar3 + 1 + uVar4);
        *(undefined1 *)(iVar5 + 2 + uVar4) = *(undefined1 *)(uVar4 + iVar3);
        uVar4 = uVar4 + *(byte *)(param_1 + 3);
      } while (uVar4 < (uint)param_1[6]);
    }
  }
  param_1 = (int *)iVar5;
  uVar4 = -piVar2[4] & 3;
  iVar5 = FUN_00530d80((*piVar2 + uVar4) * (uint)*(byte *)(piVar2 + 3) * piVar2[1]);
  if (iVar5 != 0) {
    uVar9 = 0;
    if (piVar2[1] != 0) {
      do {
        uVar7 = piVar2[4];
        puVar11 = (undefined4 *)(uVar7 * uVar9 + (int)param_1);
        puVar12 = (undefined4 *)(iVar5 + iVar10);
        for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar12 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar12 = puVar12 + 1;
        }
        for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined1 *)puVar12 = *(undefined1 *)puVar11;
          puVar11 = (undefined4 *)((int)puVar11 + 1);
          puVar12 = (undefined4 *)((int)puVar12 + 1);
        }
        iVar1 = piVar2[4];
        puVar11 = (undefined4 *)(iVar5 + iVar10 + iVar1);
        for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar11 = 0;
          puVar11 = puVar11 + 1;
        }
        iVar10 = iVar10 + iVar1 + uVar4;
        uVar9 = uVar9 + 1;
        for (uVar7 = uVar4; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined1 *)puVar11 = 0;
          puVar11 = (undefined4 *)((int)puVar11 + 1);
        }
      } while (uVar9 < (uint)piVar2[1]);
    }
    if (((int *)iVar3 != param_1) && (iVar3 != piVar2[5])) {
      FUN_00530db0(iVar3);
    }
    if (param_1 != (int *)piVar2[5]) {
      FUN_00530db0(param_1);
    }
    return iVar5;
  }
  return 0;
}


