int FUN_0052cf80(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  iVar2 = param_1;
  if (param_1 == 0) {
    FUN_00530d00(0x506);
    return 0;
  }
  iVar3 = FUN_00530d80(*(undefined4 *)(param_1 + 0x18));
  if (iVar3 != 0) {
    if (*(int *)(param_1 + 8) != 0) {
      uVar4 = *(uint *)(param_1 + 4);
      uVar5 = 0;
      do {
        uVar1 = uVar5 + 1;
        puVar7 = (undefined4 *)(*(int *)(iVar2 + 0x1c) * uVar5 + iVar3);
        param_1 = 0;
        puVar6 = (undefined4 *)(uVar1 * *(int *)(iVar2 + 0x1c) + *(int *)(iVar2 + 0x14));
        if (uVar4 != 0) {
          uVar5 = *(uint *)(iVar2 + 0x10);
          do {
            puVar6 = (undefined4 *)((int)puVar6 - uVar5);
            puVar8 = puVar6;
            puVar9 = puVar7;
            for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
              *puVar9 = *puVar8;
              puVar8 = puVar8 + 1;
              puVar9 = puVar9 + 1;
            }
            for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
              *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
              puVar8 = (undefined4 *)((int)puVar8 + 1);
              puVar9 = (undefined4 *)((int)puVar9 + 1);
            }
            uVar5 = *(uint *)(iVar2 + 0x10);
            uVar4 = *(uint *)(iVar2 + 4);
            puVar7 = (undefined4 *)((int)puVar7 + uVar5);
            param_1 = param_1 + 1;
          } while (param_1 < uVar4);
        }
        uVar5 = uVar1;
      } while (uVar1 < *(uint *)(iVar2 + 8));
    }
    return iVar3;
  }
  return 0;
}



// WARNING (jumptable): Unable to track spacebase fully for stack
