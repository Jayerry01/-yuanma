undefined4 * FUN_004db100(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  param_1 = (param_2 - param_1) / 0x34;
  if (0 < param_1) {
    piVar4 = param_3 + 8;
    piVar6 = (int *)(param_2 + 0x20);
    do {
      puVar8 = (undefined4 *)(param_2 + -0x34);
      param_2 = param_2 + -0x34;
      param_3 = param_3 + -0xd;
      piVar5 = piVar4 + -0xd;
      *param_3 = *puVar8;
      piVar4[-0x14] = piVar6[-0x14];
      piVar4[-0x13] = piVar6[-0x13];
      *(char *)(piVar4 + -0x12) = (char)piVar6[-0x12];
      *(undefined1 *)((int)piVar4 + -0x47) = *(undefined1 *)((int)piVar6 + -0x47);
      *(undefined1 *)((int)piVar4 + -0x46) = *(undefined1 *)((int)piVar6 + -0x46);
      if (piVar6 + -0x11 != piVar4 + -0x11) {
        iVar1 = piVar6[-0x10];
        puVar8 = (undefined4 *)piVar6[-0x11];
        puVar10 = (undefined4 *)piVar4[-0x11];
        uVar2 = iVar1 - (int)puVar8;
        uVar3 = piVar4[-0x10] - (int)puVar10;
        if (uVar3 < uVar2) {
          puVar9 = puVar8;
          for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
          for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
            puVar9 = (undefined4 *)((int)puVar9 + 1);
            puVar10 = (undefined4 *)((int)puVar10 + 1);
          }
          FUN_00403490((undefined1 *)((piVar4[-0x10] - piVar4[-0x11]) + (int)puVar8),iVar1);
        }
        else {
          for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar10 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar10 = puVar10 + 1;
          }
          for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar10 = (undefined4 *)((int)puVar10 + 1);
          }
          iVar1 = piVar4[-0x10];
          iVar7 = piVar4[-0x11] + uVar2;
          if (iVar7 != iVar1) {
            FUN_005092c0(iVar7,iVar1,1);
            piVar4[-0x10] = piVar4[-0x10] + (iVar7 - iVar1);
          }
        }
      }
      if (piVar6 + -0xe != piVar4 + -0xe) {
        iVar1 = piVar6[-0xd];
        puVar8 = (undefined4 *)piVar6[-0xe];
        puVar10 = (undefined4 *)piVar4[-0xe];
        uVar2 = iVar1 - (int)puVar8;
        uVar3 = *piVar5 - (int)puVar10;
        if (uVar3 < uVar2) {
          puVar9 = puVar8;
          for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
          for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
            puVar9 = (undefined4 *)((int)puVar9 + 1);
            puVar10 = (undefined4 *)((int)puVar10 + 1);
          }
          FUN_00403490((undefined1 *)((*piVar5 - piVar4[-0xe]) + (int)puVar8),iVar1);
        }
        else {
          for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar10 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar10 = puVar10 + 1;
          }
          for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar10 = (undefined4 *)((int)puVar10 + 1);
          }
          iVar1 = *piVar5;
          iVar7 = piVar4[-0xe] + uVar2;
          if (iVar7 != iVar1) {
            FUN_005092c0(iVar7,iVar1,1);
            *piVar5 = *piVar5 + (iVar7 - iVar1);
          }
        }
      }
      if (piVar6 + -0xb != piVar4 + -0xb) {
        iVar1 = piVar6[-10];
        puVar8 = (undefined4 *)piVar6[-0xb];
        puVar10 = (undefined4 *)piVar4[-0xb];
        uVar2 = iVar1 - (int)puVar8;
        uVar3 = piVar4[-10] - (int)puVar10;
        if (uVar3 < uVar2) {
          puVar9 = puVar8;
          for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
          for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
            puVar9 = (undefined4 *)((int)puVar9 + 1);
            puVar10 = (undefined4 *)((int)puVar10 + 1);
          }
          FUN_00403490((undefined1 *)((piVar4[-10] - piVar4[-0xb]) + (int)puVar8),iVar1);
        }
        else {
          for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar10 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar10 = puVar10 + 1;
          }
          for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar10 = (undefined4 *)((int)puVar10 + 1);
          }
          FUN_00402b30(piVar4[-0xb] + uVar2,piVar4[-10]);
        }
      }
      param_1 = param_1 + -1;
      piVar4 = piVar5;
      piVar6 = piVar6 + -0xd;
    } while (param_1 != 0);
  }
  return param_3;
}


