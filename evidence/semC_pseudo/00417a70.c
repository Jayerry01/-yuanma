void FUN_00417a70(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iStack_8;
  
  iVar2 = DAT_007eac64;
  piVar6 = *(int **)(param_2 + 0x40);
  iVar1 = *(int *)(param_2 + 0x1c);
  DAT_005c4618 = piVar6[1];
  FUN_0041a490(param_1,1);
  iVar4 = DAT_005c4618;
  for (iVar3 = *(int *)(param_2 + 0x38); iVar3 != 0; iVar3 = iVar3 + -1) {
    DAT_005c4618 = piVar6[1];
    if (DAT_005c4618 != iVar4) {
      FUN_0041a490(param_1,1);
      iVar4 = DAT_005c4618;
    }
    DAT_005c4618 = iVar4;
    if (*piVar6 == 1) {
      puVar7 = (undefined4 *)(iVar1 + piVar6[3] * iVar2 * 4);
      puVar8 = DAT_007e2808;
      for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      puVar7 = (undefined4 *)(iVar1 + piVar6[4] * iVar2 * 4);
      puVar8 = DAT_007e2808 + 8;
      for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      puVar7 = (undefined4 *)(iVar1 + piVar6[5] * iVar2 * 4);
      puVar8 = DAT_007e2808 + 0x10;
      for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      puVar7 = (undefined4 *)(iVar1 + piVar6[3] * iVar2 * 4);
      puVar8 = DAT_007e2808 + 0x18;
      for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      (**(code **)(*param_1 + 0x70))(param_1,3,0x1c4,DAT_007e2808,4,param_4);
      iVar4 = DAT_005c4314;
    }
    else {
      iStack_8 = 0;
      if (0 < piVar6[2]) {
        piVar5 = piVar6 + 4;
        do {
          puVar7 = (undefined4 *)(iVar1 + piVar5[-1] * iVar2 * 4);
          puVar8 = DAT_007e2808;
          for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
          puVar7 = (undefined4 *)(iVar1 + *piVar5 * iVar2 * 4);
          puVar8 = DAT_007e2808 + 8;
          for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
          (**(code **)(*param_1 + 0x70))(param_1,2,0x1c4,DAT_007e2808,2,param_4);
          iStack_8 = iStack_8 + 1;
          piVar5 = piVar5 + 2;
        } while (iStack_8 < piVar6[2]);
      }
      iVar4 = piVar6[2] * 2 + 3;
    }
    piVar6 = piVar6 + iVar4;
    iVar4 = DAT_005c4618;
  }
  DAT_005c4618 = iVar4;
  return;
}


