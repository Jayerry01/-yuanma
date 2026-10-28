int * FUN_005764e0(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  
  param_2 = (param_2 - param_1) / 0x68;
  if (0 < param_2) {
    iVar4 = (int)param_3 - param_1;
    piVar9 = param_3 + 5;
    piVar8 = (int *)(param_1 + 0x10);
    do {
      piVar1 = (int *)((int)piVar8 + iVar4);
      *param_3 = piVar8[-4];
      piVar9[-4] = piVar8[-3];
      piVar9[-3] = piVar8[-2];
      piVar9[-2] = piVar8[-1];
      if (piVar8 != piVar1) {
        iVar7 = *piVar8;
        uVar2 = (piVar8[1] - iVar7) / 0xc;
        iVar6 = *piVar1;
        if ((uint)((piVar9[1] - iVar6) / 0xc) < uVar2) {
          iVar5 = FUN_0055f1e0(uVar2,iVar7,piVar8[1]);
          iVar6 = *piVar9;
          for (iVar7 = *piVar1; iVar7 != iVar6; iVar7 = iVar7 + 0xc) {
            FUN_00577850(iVar7);
          }
          iVar7 = (piVar1[2] - *piVar1) / 0xc;
          if (iVar7 != 0) {
            FUN_00402e90(*piVar1,iVar7 * 0xc);
          }
          *piVar1 = iVar5;
          piVar1[2] = iVar5 + uVar2 * 0xc;
        }
        else {
          uVar3 = (*piVar9 - iVar6) / 0xc;
          if (uVar3 < uVar2) {
            FUN_00552510(iVar7,iVar7 + uVar3 * 0xc,iVar6,uVar2,0);
            FUN_0055fe10(*piVar8 + ((*piVar9 - *piVar1) / 0xc) * 0xc,piVar8[1],*piVar9,uVar2);
          }
          else {
            iVar6 = FUN_00552510(iVar7,piVar8[1],iVar6,uVar2,0);
            iVar7 = *piVar9;
            for (; iVar6 != iVar7; iVar6 = iVar6 + 0xc) {
              FUN_00577850(iVar6);
            }
          }
        }
        piVar1[1] = *piVar1 + uVar2 * 0xc;
      }
      FUN_004c7210(piVar8 + 3);
      param_3 = param_3 + 0x1a;
      piVar9[5] = piVar8[6];
      piVar9[6] = piVar8[7];
      piVar9[7] = piVar8[8];
      piVar9[8] = piVar8[9];
      piVar9[9] = piVar8[10];
      piVar9[10] = piVar8[0xb];
      piVar9[0xb] = piVar8[0xc];
      piVar9[0xc] = piVar8[0xd];
      piVar9[0xd] = piVar8[0xe];
      piVar9[0xe] = piVar8[0xf];
      piVar9[0xf] = piVar8[0x10];
      piVar9[0x10] = piVar8[0x11];
      piVar9[0x11] = piVar8[0x12];
      piVar9[0x12] = piVar8[0x13];
      piVar9[0x13] = piVar8[0x14];
      piVar1 = piVar8 + 0x15;
      piVar8 = piVar8 + 0x1a;
      piVar9[0x14] = *piVar1;
      piVar9 = piVar9 + 0x1a;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return param_3;
}


