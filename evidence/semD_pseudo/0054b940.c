FUN_0054b940(int param_1,uint param_2,undefined4 *param_3,undefined4 *param_4,int *param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  if ((-1 < (int)param_2) &&
     (param_2 < (uint)((*(int *)(param_1 + 0x150) - *(int *)(param_1 + 0x14c)) / 0x18))) {
    iVar2 = *(int *)(param_1 + 0x14c);
    iVar5 = param_2 * 0x18;
    *param_3 = *(undefined4 *)(iVar2 + iVar5);
    param_3[1] = *(undefined4 *)(iVar2 + 4 + iVar5);
    piVar1 = (int *)(*(int *)(param_1 + 0x14c) + 0xc + iVar5);
    if (piVar1 != param_5) {
      iVar2 = piVar1[1];
      puVar6 = (undefined4 *)*piVar1;
      puVar9 = (undefined4 *)*param_5;
      uVar4 = iVar2 - (int)puVar6;
      uVar3 = param_5[1] - (int)puVar9;
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
        FUN_00403490((undefined1 *)((int)puVar6 + (param_5[1] - *param_5)),iVar2);
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
        iVar2 = param_5[1];
        iVar7 = *param_5 + uVar4;
        if (iVar7 != iVar2) {
          FUN_005092c0(iVar7,iVar2,1);
          param_5[1] = param_5[1] + (iVar7 - iVar2);
        }
      }
    }
    *param_4 = *(undefined4 *)(*(int *)(param_1 + 0x14c) + 8 + iVar5);
  }
  return;
}


