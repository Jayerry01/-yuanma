void FUN_00577220(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  
  param_2 = (param_2 - (int)param_1) / 0x14;
  if (0 < param_2) {
    piVar6 = param_3 + 2;
    piVar5 = param_1 + 2;
    do {
      *param_3 = *param_1;
      piVar6[-1] = piVar5[-1];
      if (piVar5 != piVar6) {
        iVar2 = piVar5[1];
        iVar3 = *piVar5;
        iVar1 = *piVar6;
        uVar7 = iVar2 - iVar3 >> 2;
        if ((uint)(piVar6[2] - iVar1 >> 2) < uVar7) {
          iVar2 = FUN_004c7640(uVar7,iVar3,iVar2);
          iVar3 = piVar6[2] - *piVar6 >> 2;
          if (iVar3 != 0) {
            FUN_00402e90(*piVar6,iVar3 << 2);
          }
          *piVar6 = iVar2;
          piVar6[2] = iVar2 + uVar7 * 4;
        }
        else {
          uVar4 = piVar6[1] - iVar1 >> 2;
          if (uVar4 < uVar7) {
            FUN_005092c0(iVar1,iVar3,((int)(uVar4 << 2) >> 2) << 2);
            iVar2 = *piVar5 + (piVar6[1] - *piVar6 >> 2) * 4;
            FUN_005092c0(piVar6[1],iVar2,(piVar5[1] - iVar2 >> 2) << 2);
          }
          else {
            FUN_005092c0(iVar1,iVar3,(iVar2 - iVar3 >> 2) << 2);
          }
        }
        piVar6[1] = *piVar6 + uVar7 * 4;
      }
      param_1 = param_1 + 5;
      piVar5 = piVar5 + 5;
      param_3 = param_3 + 5;
      piVar6 = piVar6 + 5;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


