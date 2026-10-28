void FUN_00423910(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  _DAT_007e2ba4 = param_2;
  iVar4 = 0;
  param_2 = param_1 + 0x74;
  _DAT_007e2ba0 = 3;
  _DAT_007e2ba8 = param_3;
  _DAT_007e2bac = param_4;
  piVar5 = (int *)&DAT_007e2ba0;
  uVar2 = 0;
  do {
    uVar6 = uVar2;
    piVar1 = &DAT_007e2720 + uVar6 * 9;
    iVar3 = FUN_004239f0(piVar5,param_2,piVar1);
    if (iVar3 == 0) {
      return;
    }
    iVar4 = iVar4 + 1;
    param_2 = param_2 + 0x10;
    piVar5 = piVar1;
    uVar2 = uVar6 ^ 1;
  } while (iVar4 < 6);
  if (2 < *piVar1) {
    iVar4 = *piVar1 + -1;
    iVar3 = 1;
    if (DAT_007e0410 == 0) {
      if (1 < iVar4) {
        puVar7 = &DAT_007e2728 + uVar6 * 9;
        do {
          FUN_00427bb0((&DAT_007e2724)[uVar6 * 9],*puVar7,puVar7[1]);
          iVar3 = iVar3 + 1;
          puVar7 = puVar7 + 1;
        } while (iVar3 < *piVar1 + -1);
      }
    }
    else if (1 < iVar4) {
      puVar7 = &DAT_007e2728 + uVar6 * 9;
      do {
        FUN_00428240((&DAT_007e2724)[uVar6 * 9],*puVar7,puVar7[1]);
        iVar3 = iVar3 + 1;
        puVar7 = puVar7 + 1;
      } while (iVar3 < *piVar1 + -1);
      return;
    }
  }
  return;
}


