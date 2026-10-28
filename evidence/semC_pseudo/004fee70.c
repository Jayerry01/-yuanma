undefined4 * FUN_004fee70(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  
  param_1 = ((int)param_2 - param_1) / 0x30;
  if (0 < param_1) {
    piVar5 = param_3 + 8;
    piVar7 = param_2 + 8;
    do {
      puVar2 = param_3 + -0xc;
      *puVar2 = param_2[-0xc];
      piVar6 = piVar5 + -0xc;
      param_3[-0xb] = param_2[-0xb];
      param_3[-10] = param_2[-10];
      piVar5[-0x11] = piVar7[-0x11];
      if (piVar7 + -0x10 != piVar5 + -0x10) {
        iVar1 = piVar7[-0xf];
        puVar9 = (undefined4 *)piVar7[-0x10];
        puVar11 = (undefined4 *)piVar5[-0x10];
        uVar4 = iVar1 - (int)puVar9;
        uVar3 = piVar5[-0xf] - (int)puVar11;
        if (uVar3 < uVar4) {
          puVar10 = puVar9;
          for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar11 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar11 = puVar11 + 1;
          }
          for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          FUN_00403490((undefined1 *)((int)puVar9 + (piVar5[-0xf] - piVar5[-0x10])),iVar1);
        }
        else {
          for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar11 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar11 = puVar11 + 1;
          }
          for (uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
            puVar9 = (undefined4 *)((int)puVar9 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          iVar1 = piVar5[-0xf];
          iVar8 = piVar5[-0x10] + uVar4;
          if (iVar8 != iVar1) {
            FUN_005092c0(iVar8,iVar1,1);
            piVar5[-0xf] = piVar5[-0xf] + (iVar8 - iVar1);
          }
        }
      }
      if (piVar7 + -0xd != piVar5 + -0xd) {
        iVar1 = piVar7[-0xc];
        puVar9 = (undefined4 *)piVar7[-0xd];
        puVar11 = (undefined4 *)piVar5[-0xd];
        uVar3 = iVar1 - (int)puVar9;
        uVar4 = *piVar6 - (int)puVar11;
        if (uVar4 < uVar3) {
          puVar10 = puVar9;
          for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar11 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar11 = puVar11 + 1;
          }
          for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          FUN_00403490((undefined1 *)((*piVar6 - piVar5[-0xd]) + (int)puVar9),iVar1);
        }
        else {
          for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar11 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar11 = puVar11 + 1;
          }
          for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
            puVar9 = (undefined4 *)((int)puVar9 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          iVar1 = *piVar6;
          iVar8 = piVar5[-0xd] + uVar3;
          if (iVar8 != iVar1) {
            FUN_005092c0(iVar8,iVar1,1);
            *piVar6 = *piVar6 + (iVar8 - iVar1);
          }
        }
      }
      piVar5[-10] = piVar7[-10];
      param_1 = param_1 + -1;
      piVar5[-9] = piVar7[-9];
      piVar5 = piVar6;
      piVar7 = piVar7 + -0xc;
      param_2 = param_2 + -0xc;
      param_3 = puVar2;
    } while (param_1 != 0);
  }
  return param_3;
}


