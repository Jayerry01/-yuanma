void FUN_0057cdb0(int param_1,int param_2,undefined1 *param_3)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  
  param_1 = (param_2 - param_1) / 0xac;
  if (0 < param_1) {
    piVar7 = (int *)(param_3 + 0x2c);
    piVar9 = (int *)(param_2 + 0x2c);
    do {
      param_2 = param_2 + -0xac;
      param_3 = param_3 + -0xac;
      piVar10 = piVar9 + -0x2b;
      piVar8 = piVar7 + -0x2b;
      iVar6 = 0x10;
      puVar2 = param_3;
      do {
        *puVar2 = puVar2[param_2 - (int)param_3];
        puVar2 = puVar2 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      piVar7[-0x32] = piVar9[-0x32];
      piVar7[-0x31] = piVar9[-0x31];
      piVar7[-0x30] = piVar9[-0x30];
      piVar7[-0x2f] = piVar9[-0x2f];
      piVar7[-0x2e] = piVar9[-0x2e];
      piVar7[-0x2d] = piVar9[-0x2d];
      if (piVar9 + -0x2c != piVar7 + -0x2c) {
        iVar6 = piVar9[-0x2c];
        iVar3 = piVar7[-0x2c];
        piVar1 = piVar7 + -0x2c;
        uVar5 = *piVar10 - iVar6 >> 2;
        if ((uint)(piVar7[-0x2a] - iVar3 >> 2) < uVar5) {
          iVar6 = FUN_004c7640(uVar5,iVar6,*piVar10);
          iVar3 = piVar7[-0x2a] - *piVar1 >> 2;
          if (iVar3 != 0) {
            FUN_00402e90(*piVar1,iVar3 * 4);
          }
          *piVar1 = iVar6;
          piVar7[-0x2a] = iVar6 + uVar5 * 4;
        }
        else {
          uVar4 = *piVar8 - iVar3 >> 2;
          if (uVar4 < uVar5) {
            FUN_0049e5e0(iVar6,iVar6 + uVar4 * 4,iVar3);
            FUN_0049e5e0(piVar9[-0x2c] + (*piVar8 - *piVar1 >> 2) * 4,*piVar10,*piVar8);
          }
          else {
            FUN_0049e5e0(iVar6,*piVar10,iVar3);
          }
        }
        *piVar8 = *piVar1 + uVar5 * 4;
      }
      FUN_0055eb70(piVar9 + -0x29);
      piVar7[-0x26] = piVar9[-0x26];
      piVar7[-0x25] = piVar9[-0x25];
      piVar7[-0x24] = piVar9[-0x24];
      piVar7[-0x23] = piVar9[-0x23];
      piVar7[-0x22] = piVar9[-0x22];
      piVar7[-0x21] = piVar9[-0x21];
      piVar7[-0x20] = piVar9[-0x20];
      piVar7[-0x1f] = piVar9[-0x1f];
      piVar7[-0x1e] = piVar9[-0x1e];
      piVar7[-0x1d] = piVar9[-0x1d];
      piVar7[-0x1c] = piVar9[-0x1c];
      piVar7[-0x1b] = piVar9[-0x1b];
      FUN_004c7210(piVar9 + -0x1a);
      FUN_0055ed10(piVar9 + -0x17);
      FUN_0055ed10(piVar9 + -0x14);
      FUN_0055ee90(piVar9 + -0x11);
      FUN_0055f040(piVar9 + -0xe);
      param_1 = param_1 + -1;
      piVar7 = piVar8;
      piVar9 = piVar10;
    } while (param_1 != 0);
  }
  return;
}


