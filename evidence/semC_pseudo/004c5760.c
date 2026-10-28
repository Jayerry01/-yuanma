int FUN_004c5760(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  int *piVar10;
  int *piVar11;
  
  param_2 = (param_2 - param_1) / 0x24;
  iVar5 = param_3;
  if (0 < param_2) {
    iVar1 = param_3 - param_1;
    iVar5 = param_3 + param_2 * 0x24;
    piVar11 = (int *)(param_3 + 0x18);
    piVar10 = (int *)(param_1 + 0x1c);
    do {
      piVar11[-5] = piVar10[-6];
      piVar11[-4] = piVar10[-5];
      piVar11[-3] = piVar10[-4];
      *(char *)(piVar11 + -2) = (char)piVar10[-3];
      *(undefined2 *)((int)piVar11 + -6) = *(undefined2 *)((int)piVar10 + -10);
      *(short *)(piVar11 + -1) = (short)piVar10[-2];
      *(undefined1 *)((int)piVar11 + -2) = *(undefined1 *)((int)piVar10 + -6);
      if (piVar10 + -1 != piVar11) {
        iVar7 = *piVar10;
        puVar4 = (undefined4 *)piVar10[-1];
        puVar8 = (undefined4 *)*piVar11;
        uVar9 = iVar7 - (int)puVar4 >> 3;
        if ((uint)(piVar11[2] - (int)puVar8 >> 3) < uVar9) {
          iVar2 = FUN_004c4300(uVar9,puVar4,iVar7);
          iVar3 = *(int *)(iVar1 + (int)piVar10);
          for (iVar7 = *piVar11; iVar7 != iVar3; iVar7 = iVar7 + 8) {
            FUN_004c6090(iVar7);
          }
          iVar7 = piVar11[2] - *piVar11 >> 3;
          if (iVar7 != 0) {
            FUN_00402e90(*piVar11,iVar7 * 8);
          }
          *piVar11 = iVar2;
          piVar11[2] = iVar2 + uVar9 * 8;
        }
        else {
          uVar6 = *(int *)(iVar1 + (int)piVar10) - (int)puVar8 >> 3;
          if (uVar6 < uVar9) {
            iVar7 = (int)(uVar6 * 8) >> 3;
            if (0 < iVar7) {
              do {
                *puVar8 = *puVar4;
                puVar8[1] = puVar4[1];
                puVar8 = puVar8 + 2;
                iVar7 = iVar7 + -1;
                puVar4 = puVar4 + 2;
              } while (iVar7 != 0);
            }
            FUN_004c6f20(piVar10[-1] + (piVar11[1] - *piVar11 >> 3) * 8,*piVar10,piVar11[1],iVar1);
          }
          else {
            iVar3 = FUN_004c6050(puVar4,iVar7,puVar8,iVar1,0);
            iVar7 = *(int *)(iVar1 + (int)piVar10);
            for (; iVar3 != iVar7; iVar3 = iVar3 + 8) {
              FUN_004c6090(iVar3);
            }
          }
        }
        piVar11[1] = *piVar11 + uVar9 * 8;
      }
      piVar10 = piVar10 + 9;
      piVar11 = piVar11 + 9;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return iVar5;
}


