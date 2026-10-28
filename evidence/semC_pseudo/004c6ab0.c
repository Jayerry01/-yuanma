int FUN_004c6ab0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  int *piVar8;
  int iVar10;
  uint uVar11;
  int *piVar12;
  int *piVar13;
  int *piVar9;
  
  param_1 = (param_2 - param_1) / 0x24;
  iVar3 = param_3;
  if (0 < param_1) {
    iVar3 = param_3 + param_1 * -0x24;
    piVar8 = (int *)(param_2 + 0x1c);
    piVar12 = (int *)(param_3 + 0x1c);
    do {
      piVar9 = piVar8 + -9;
      piVar13 = piVar12 + -9;
      piVar1 = piVar12 + -10;
      piVar12[-0xf] = piVar8[-0xf];
      piVar12[-0xe] = piVar8[-0xe];
      piVar12[-0xd] = piVar8[-0xd];
      *(char *)(piVar12 + -0xc) = (char)piVar8[-0xc];
      *(undefined2 *)((int)piVar12 + -0x2e) = *(undefined2 *)((int)piVar8 + -0x2e);
      *(short *)(piVar12 + -0xb) = (short)piVar8[-0xb];
      *(undefined1 *)((int)piVar12 + -0x2a) = *(undefined1 *)((int)piVar8 + -0x2a);
      if (piVar8 + -10 != piVar12 + -10) {
        iVar10 = *piVar9;
        puVar5 = (undefined4 *)piVar8[-10];
        puVar6 = (undefined4 *)*piVar1;
        uVar7 = iVar10 - (int)puVar5 >> 3;
        if ((uint)(piVar12[-8] - (int)puVar6 >> 3) < uVar7) {
          iVar2 = FUN_004c4300(uVar7,puVar5,iVar10);
          iVar4 = *piVar13;
          for (iVar10 = *piVar1; iVar10 != iVar4; iVar10 = iVar10 + 8) {
            FUN_004c68d0(0);
          }
          iVar10 = piVar12[-8] - *piVar1 >> 3;
          if (iVar10 != 0) {
            FUN_00402e90(*piVar1,iVar10 * 8);
          }
          *piVar1 = iVar2;
          piVar12[-8] = iVar2 + uVar7 * 8;
        }
        else {
          uVar11 = *piVar13 - (int)puVar6 >> 3;
          if (uVar11 < uVar7) {
            iVar10 = (int)(uVar11 * 8) >> 3;
            if (0 < iVar10) {
              do {
                *puVar6 = *puVar5;
                puVar6[1] = puVar5[1];
                puVar6 = puVar6 + 2;
                iVar10 = iVar10 + -1;
                puVar5 = puVar5 + 2;
              } while (iVar10 != 0);
            }
            FUN_004c6f20(piVar8[-10] + (piVar12[-9] - *piVar1 >> 3) * 8,*piVar9,piVar12[-9],iVar3);
          }
          else {
            iVar4 = FUN_004c6050(puVar5,iVar10,puVar6,iVar3,0);
            iVar10 = *piVar13;
            for (; iVar4 != iVar10; iVar4 = iVar4 + 8) {
              FUN_004c68d0(0);
            }
          }
        }
        piVar12[-9] = *piVar1 + uVar7 * 8;
      }
      param_1 = param_1 + -1;
      piVar8 = piVar9;
      piVar12 = piVar13;
    } while (param_1 != 0);
  }
  return iVar3;
}


