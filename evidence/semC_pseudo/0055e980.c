undefined1 * FUN_0055e980(int param_1,int param_2,undefined1 *param_3)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  
  param_2 = (param_2 - param_1) / 0xac;
  if (0 < param_2) {
    iVar2 = (int)param_3 - param_1;
    piVar8 = (int *)(param_3 + 0x28);
    piVar9 = (int *)(param_1 + 0x2c);
    do {
      iVar7 = 0x10;
      puVar3 = param_3;
      do {
        *puVar3 = puVar3[(int)piVar9 + (-0x2c - (int)param_3)];
        puVar3 = puVar3 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      piVar8[-6] = piVar9[-7];
      piVar8[-5] = piVar9[-6];
      piVar8[-4] = piVar9[-5];
      piVar8[-3] = piVar9[-4];
      piVar8[-2] = piVar9[-3];
      piVar8[-1] = piVar9[-2];
      if (piVar9 + -1 != piVar8) {
        iVar7 = *piVar9;
        iVar4 = piVar9[-1];
        iVar1 = *piVar8;
        uVar6 = iVar7 - iVar4 >> 2;
        if ((uint)(piVar8[2] - iVar1 >> 2) < uVar6) {
          iVar7 = FUN_004c7640(uVar6,iVar4,iVar7);
          iVar4 = piVar8[2] - *piVar8 >> 2;
          if (iVar4 != 0) {
            FUN_00402e90(*piVar8,iVar4 * 4);
          }
          *piVar8 = iVar7;
          piVar8[2] = iVar7 + uVar6 * 4;
        }
        else {
          uVar5 = *(int *)(iVar2 + (int)piVar9) - iVar1 >> 2;
          if (uVar5 < uVar6) {
            FUN_0049e5e0(iVar4,iVar4 + uVar5 * 4,iVar1);
            FUN_0049e5e0(piVar9[-1] + (*(int *)(iVar2 + (int)piVar9) - *piVar8 >> 2) * 4,*piVar9,
                         *(int *)(iVar2 + (int)piVar9));
          }
          else {
            FUN_0049e5e0(iVar4,iVar7,iVar1);
          }
        }
        *(uint *)(iVar2 + (int)piVar9) = *piVar8 + uVar6 * 4;
      }
      FUN_0055eb70(piVar9 + 2);
      piVar8[6] = piVar9[5];
      piVar8[7] = piVar9[6];
      piVar8[8] = piVar9[7];
      piVar8[9] = piVar9[8];
      piVar8[10] = piVar9[9];
      piVar8[0xb] = piVar9[10];
      piVar8[0xc] = piVar9[0xb];
      piVar8[0xd] = piVar9[0xc];
      piVar8[0xe] = piVar9[0xd];
      piVar8[0xf] = piVar9[0xe];
      piVar8[0x10] = piVar9[0xf];
      piVar8[0x11] = piVar9[0x10];
      FUN_004c7210(piVar9 + 0x11);
      FUN_0055ed10(piVar9 + 0x14);
      FUN_0055ed10(piVar9 + 0x17);
      FUN_0055ee90(piVar9 + 0x1a);
      FUN_0055f040(piVar9 + 0x1d);
      param_3 = param_3 + 0xac;
      piVar8 = piVar8 + 0x2b;
      piVar9 = piVar9 + 0x2b;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return param_3;
}


