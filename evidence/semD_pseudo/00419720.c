void FUN_00419720(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  iVar4 = DAT_007eac64;
  puVar3 = DAT_007e2808;
  iVar1 = *(int *)(param_2 + 0x40);
  iVar2 = *(int *)(param_2 + 0x1c);
  DAT_005c4618 = *(int *)(iVar1 + 4);
  FUN_0041a490(param_1,1);
  iVar8 = DAT_005c4618;
  for (iVar5 = *(int *)(param_2 + 0x38); iVar5 != 0; iVar5 = iVar5 + -1) {
    DAT_005c4618 = *(int *)(iVar1 + 4);
    if (DAT_005c4618 != iVar8) {
      FUN_0041a490(param_1,1);
      iVar8 = DAT_005c4618;
    }
    DAT_005c4618 = iVar8;
    iVar8 = 0;
    if (0 < *(int *)(iVar1 + 8)) {
      piVar7 = (int *)(iVar1 + 0x10);
      do {
        puVar9 = (undefined4 *)(iVar2 + piVar7[-1] * iVar4 * 4);
        puVar10 = puVar3;
        for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar10 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        }
        puVar9 = (undefined4 *)(iVar2 + *piVar7 * iVar4 * 4);
        puVar10 = puVar3 + 8;
        for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar10 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        }
        (**(code **)(*param_1 + 0x70))(param_1,2,0x1e2,DAT_007e2808,2,param_3);
        iVar8 = iVar8 + 1;
        piVar7 = piVar7 + 2;
      } while (iVar8 < *(int *)(iVar1 + 8));
    }
    iVar1 = iVar1 + 0xc + *(int *)(iVar1 + 8) * 8;
    iVar8 = DAT_005c4618;
  }
  DAT_005c4618 = iVar8;
  return;
}


