void FUN_0058d560(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  
  param_1 = (param_2 - param_1) / 0x14;
  if (0 < param_1) {
    piVar6 = (int *)(param_2 + 8);
    piVar8 = param_3 + 2;
    do {
      puVar1 = (undefined4 *)(param_2 + -0x14);
      param_2 = param_2 + -0x14;
      param_3 = param_3 + -5;
      piVar7 = piVar6 + -5;
      piVar9 = piVar8 + -5;
      *param_3 = *puVar1;
      piVar8[-6] = piVar6[-6];
      if (piVar7 != piVar9) {
        iVar3 = piVar6[-4];
        iVar4 = *piVar7;
        iVar2 = *piVar9;
        uVar10 = iVar3 - iVar4 >> 2;
        if ((uint)(piVar8[-3] - iVar2 >> 2) < uVar10) {
          iVar3 = FUN_004c7640(uVar10,iVar4,iVar3);
          iVar4 = piVar8[-3] - *piVar9 >> 2;
          if (iVar4 != 0) {
            FUN_00402e90(*piVar9,iVar4 << 2);
          }
          *piVar9 = iVar3;
          piVar8[-3] = iVar3 + uVar10 * 4;
        }
        else {
          uVar5 = piVar8[-4] - iVar2 >> 2;
          if (uVar5 < uVar10) {
            FUN_005092c0(iVar2,iVar4,((int)(uVar5 << 2) >> 2) << 2);
            iVar3 = *piVar7 + (piVar8[-4] - *piVar9 >> 2) * 4;
            FUN_005092c0(piVar8[-4],iVar3,(piVar6[-4] - iVar3 >> 2) << 2);
          }
          else {
            FUN_005092c0(iVar2,iVar4,(iVar3 - iVar4 >> 2) << 2);
          }
        }
        piVar8[-4] = *piVar9 + uVar10 * 4;
      }
      param_1 = param_1 + -1;
      piVar6 = piVar7;
      piVar8 = piVar9;
    } while (param_1 != 0);
  }
  return;
}


