undefined4 __fastcall FUN_005780c0(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  
  (**(code **)(**(int **)(param_1 + 0x1c) + 4))();
  piVar2 = *(int **)(param_1 + 0x18);
  iVar4 = piVar2[1];
  if (iVar4 == 3) {
    piVar2[2] = *(int *)(*(int *)(param_1 + 0x1c) + 8);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)(param_1 + 0x18) + 8);
  }
  else if (iVar4 == 7) {
    piVar1 = piVar2 + 3;
    piVar7 = (int *)(*(int *)(param_1 + 0x1c) + 0xc);
    if (piVar7 != piVar1) {
      iVar4 = *(int *)(*(int *)(param_1 + 0x1c) + 0x10);
      puVar8 = (undefined4 *)*piVar7;
      puVar11 = (undefined4 *)*piVar1;
      uVar6 = piVar2[4] - (int)puVar11;
      uVar5 = iVar4 - (int)puVar8;
      if (uVar6 < uVar5) {
        puVar10 = puVar8;
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
        FUN_00403490((undefined1 *)((piVar2[4] - *piVar1) + (int)puVar8),iVar4);
        return 1;
      }
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar11 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar11 = puVar11 + 1;
      }
      for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar11 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      }
      iVar4 = piVar2[4];
      iVar9 = *piVar1 + uVar5;
      if (iVar9 != iVar4) {
        FUN_005092c0(iVar9,iVar4,1);
        piVar2[4] = piVar2[4] + (iVar9 - iVar4);
        return 1;
      }
    }
  }
  else if (iVar4 == 0xb) {
    (**(code **)(*piVar2 + 4))();
    iVar4 = FUN_00578030();
    uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 8);
    *(undefined4 *)(iVar4 + 8) = uVar3;
    *(undefined4 *)(param_1 + 8) = uVar3;
    return 1;
  }
  return 1;
}


