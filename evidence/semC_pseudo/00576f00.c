int * FUN_00576f00(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  int *piVar9;
  
  param_2 = (param_2 - param_1) / 0x14;
  if (0 < param_2) {
    iVar3 = (int)param_3 - param_1;
    piVar7 = param_3 + 3;
    piVar9 = (int *)(param_1 + 8);
    do {
      piVar1 = (int *)(iVar3 + (int)piVar9);
      *param_3 = piVar9[-2];
      piVar7[-2] = piVar9[-1];
      if (piVar9 != piVar1) {
        iVar4 = piVar9[1];
        iVar5 = *piVar9;
        iVar2 = *piVar1;
        uVar8 = iVar4 - iVar5 >> 2;
        if ((uint)(piVar7[1] - iVar2 >> 2) < uVar8) {
          iVar4 = FUN_004c7640(uVar8,iVar5,iVar4);
          iVar5 = piVar7[1] - *piVar1 >> 2;
          if (iVar5 != 0) {
            FUN_00402e90(*piVar1,iVar5 * 4);
          }
          *piVar1 = iVar4;
          piVar7[1] = iVar4 + uVar8 * 4;
        }
        else {
          uVar6 = *piVar7 - iVar2 >> 2;
          if (uVar6 < uVar8) {
            FUN_005092c0(iVar2,iVar5,((int)(uVar6 << 2) >> 2) << 2);
            iVar4 = *piVar9 + (*piVar7 - *piVar1 >> 2) * 4;
            FUN_005092c0(*piVar7,iVar4,(piVar9[1] - iVar4 >> 2) << 2);
          }
          else {
            FUN_005092c0(iVar2,iVar5,(iVar4 - iVar5 >> 2) << 2);
          }
        }
        *piVar7 = *piVar1 + uVar8 * 4;
      }
      param_3 = param_3 + 5;
      piVar9 = piVar9 + 5;
      piVar7 = piVar7 + 5;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return param_3;
}


