void FUN_00423440(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  _DAT_007e2ba4 = param_2;
  iVar5 = 0;
  param_2 = param_1 + 0x74;
  _DAT_007e2ba0 = 3;
  _DAT_007e2ba8 = param_3;
  _DAT_007e2bac = param_4;
  piVar6 = (int *)&DAT_007e2ba0;
  uVar2 = 0;
  do {
    uVar7 = uVar2;
    piVar1 = &DAT_007e2720 + uVar7 * 9;
    iVar3 = FUN_00423680(piVar6,param_2,piVar1);
    if (iVar3 == 0) {
      return;
    }
    iVar5 = iVar5 + 1;
    param_2 = param_2 + 0x10;
    piVar6 = piVar1;
    uVar2 = uVar7 ^ 1;
  } while (iVar5 < 6);
  iVar5 = *piVar1;
  if ((2 < iVar5) && (*(int *)(DAT_007e32ac + 0x34) != 0)) {
    iVar4 = 1;
    iVar3 = *(int *)(*(int *)(DAT_007e32ac + 0x34) + 0x2c);
    if (DAT_007e2700 == 0) {
      iVar5 = iVar5 + -1;
      if (iVar3 == -1) {
        if (DAT_007e0410 == 0) {
          if (1 < iVar5) {
            puVar8 = &DAT_007e2728 + uVar7 * 9;
            do {
              FUN_00425970((&DAT_007e2724)[uVar7 * 9],*puVar8,puVar8[1]);
              iVar4 = iVar4 + 1;
              puVar8 = puVar8 + 1;
            } while (iVar4 < *piVar1 + -1);
          }
        }
        else if (1 < iVar5) {
          puVar8 = &DAT_007e2728 + uVar7 * 9;
          do {
            FUN_004261e0((&DAT_007e2724)[uVar7 * 9],*puVar8,puVar8[1]);
            iVar4 = iVar4 + 1;
            puVar8 = puVar8 + 1;
          } while (iVar4 < *piVar1 + -1);
          return;
        }
      }
      else if (DAT_007e0410 == 0) {
        if (1 < iVar5) {
          puVar8 = &DAT_007e2728 + uVar7 * 9;
          do {
            FUN_00426a80((&DAT_007e2724)[uVar7 * 9],*puVar8,puVar8[1]);
            iVar4 = iVar4 + 1;
            puVar8 = puVar8 + 1;
          } while (iVar4 < *piVar1 + -1);
          return;
        }
      }
      else if (1 < iVar5) {
        puVar8 = &DAT_007e2728 + uVar7 * 9;
        do {
          FUN_00427300((&DAT_007e2724)[uVar7 * 9],*puVar8,puVar8[1]);
          iVar4 = iVar4 + 1;
          puVar8 = puVar8 + 1;
        } while (iVar4 < *piVar1 + -1);
        return;
      }
    }
    else {
      iVar5 = iVar5 + -1;
      if (iVar3 == -1) {
        if (DAT_007e0410 == 0) {
          if (1 < iVar5) {
            puVar8 = &DAT_007e2728 + uVar7 * 9;
            do {
              FUN_00423c30((&DAT_007e2724)[uVar7 * 9],*puVar8,puVar8[1]);
              iVar4 = iVar4 + 1;
              puVar8 = puVar8 + 1;
            } while (iVar4 < *piVar1 + -1);
            return;
          }
        }
        else if (1 < iVar5) {
          puVar8 = &DAT_007e2728 + uVar7 * 9;
          do {
            FUN_00424360((&DAT_007e2724)[uVar7 * 9],*puVar8,puVar8[1]);
            iVar4 = iVar4 + 1;
            puVar8 = puVar8 + 1;
          } while (iVar4 < *piVar1 + -1);
          return;
        }
      }
      else if (DAT_007e0410 == 0) {
        if (1 < iVar5) {
          puVar8 = &DAT_007e2728 + uVar7 * 9;
          do {
            FUN_00424ac0((&DAT_007e2724)[uVar7 * 9],*puVar8,puVar8[1]);
            iVar4 = iVar4 + 1;
            puVar8 = puVar8 + 1;
          } while (iVar4 < *piVar1 + -1);
          return;
        }
      }
      else if (1 < iVar5) {
        puVar8 = &DAT_007e2728 + uVar7 * 9;
        do {
          FUN_00425200((&DAT_007e2724)[uVar7 * 9],*puVar8,puVar8[1]);
          iVar4 = iVar4 + 1;
          puVar8 = puVar8 + 1;
        } while (iVar4 < *piVar1 + -1);
        return;
      }
    }
  }
  return;
}


