void FUN_00418e00(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  short sVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  short sVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  short sVar11;
  int *piVar12;
  int *piVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  int local_10;
  int iStack_c;
  
  iVar5 = *(int *)(param_2 + 0x38) * 6;
  if (DAT_007e0eac < iVar5) {
    DAT_007e0eac = iVar5;
    DAT_005d5adc = FUN_005099a7(DAT_005d5adc,*(int *)(param_2 + 0x38) * 0xc);
  }
  if (*(int *)(param_2 + 0x48) == 0) {
    pvVar4 = _malloc(*(int *)(param_2 + 0x18) * 2);
    *(void **)(param_2 + 0x48) = pvVar4;
  }
  uVar9 = *(uint *)(param_2 + 0x18);
  puVar15 = *(undefined4 **)(param_2 + 0x48);
  for (uVar8 = (uVar9 & 0x7fffffff) >> 1; uVar8 != 0; uVar8 = uVar8 - 1) {
    *puVar15 = 0;
    puVar15 = puVar15 + 1;
  }
  for (uVar9 = uVar9 * 2 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *(undefined1 *)puVar15 = 0;
    puVar15 = (undefined4 *)((int)puVar15 + 1);
  }
  iVar5 = *(int *)(param_2 + 0x18) * 0x20;
  if (DAT_007e0eb8 < iVar5) {
    DAT_007e0eb8 = iVar5;
    DAT_007e2808 = (undefined4 *)FUN_005099a7(DAT_007e2808,iVar5);
  }
  iVar2 = DAT_007eac64;
  puVar15 = DAT_007e2808;
  DAT_007e2300 = 0;
  DAT_007e2bdc = 0;
  piVar12 = *(int **)(param_2 + 0x40);
  iVar5 = *(int *)(param_2 + 0x1c);
  iVar10 = *piVar12;
  DAT_005c4618 = piVar12[1];
  FUN_0041a490(param_1,param_3);
  local_10 = iVar10;
  for (iVar6 = *(int *)(param_2 + 0x38); iVar6 != 0; iVar6 = iVar6 + -1) {
    if (*piVar12 != iVar10) {
      if ((iVar10 == 1) && (DAT_007e2bdc != 0)) {
        (**(code **)(*param_1 + 0x74))
                  (param_1,4,0x1e2,DAT_007e2808,DAT_007e2300,DAT_005d5adc,DAT_007e2bdc,param_4);
        uVar9 = *(uint *)(param_2 + 0x18);
        puVar14 = *(undefined4 **)(param_2 + 0x48);
        for (uVar8 = (uVar9 & 0x7fffffff) >> 1; uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar14 = 0;
          puVar14 = puVar14 + 1;
        }
        for (uVar9 = uVar9 * 2 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined1 *)puVar14 = 0;
          puVar14 = (undefined4 *)((int)puVar14 + 1);
        }
        DAT_007e2300 = 0;
        DAT_007e2bdc = 0;
      }
      iVar10 = *piVar12;
      local_10 = iVar10;
    }
    if (piVar12[1] != DAT_005c4618) {
      if ((iVar10 == 1) && (DAT_007e2bdc != 0)) {
        (**(code **)(*param_1 + 0x74))
                  (param_1,4,0x1e2,DAT_007e2808,DAT_007e2300,DAT_005d5adc,DAT_007e2bdc,param_4);
        uVar9 = *(uint *)(param_2 + 0x18);
        puVar14 = *(undefined4 **)(param_2 + 0x48);
        for (uVar8 = (uVar9 & 0x7fffffff) >> 1; uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar14 = 0;
          puVar14 = puVar14 + 1;
        }
        for (uVar9 = uVar9 * 2 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined1 *)puVar14 = 0;
          puVar14 = (undefined4 *)((int)puVar14 + 1);
        }
        DAT_007e2300 = 0;
        DAT_007e2bdc = 0;
        iVar10 = local_10;
      }
      DAT_005c4618 = piVar12[1];
      FUN_0041a490(param_1,param_3);
    }
    if (iVar10 == 1) {
      sVar3 = *(short *)(*(int *)(param_2 + 0x48) + piVar12[3] * 2);
      if (sVar3 == 0) {
        puVar14 = (undefined4 *)(iVar5 + piVar12[3] * iVar2 * 4);
        puVar16 = DAT_007e2808 + DAT_007e2300 * 8;
        for (iVar10 = 8; iVar10 != 0; iVar10 = iVar10 + -1) {
          *puVar16 = *puVar14;
          puVar14 = puVar14 + 1;
          puVar16 = puVar16 + 1;
        }
        sVar3 = (short)DAT_007e2300;
        DAT_007e2300 = DAT_007e2300 + 1;
        *(short *)(*(int *)(param_2 + 0x48) + piVar12[3] * 2) = (short)DAT_007e2300;
      }
      else {
        sVar3 = sVar3 + -1;
      }
      sVar11 = *(short *)(*(int *)(param_2 + 0x48) + piVar12[4] * 2);
      if (sVar11 == 0) {
        puVar14 = (undefined4 *)(iVar5 + piVar12[4] * iVar2 * 4);
        puVar16 = DAT_007e2808 + DAT_007e2300 * 8;
        for (iVar10 = 8; iVar10 != 0; iVar10 = iVar10 + -1) {
          *puVar16 = *puVar14;
          puVar14 = puVar14 + 1;
          puVar16 = puVar16 + 1;
        }
        sVar11 = (short)DAT_007e2300;
        DAT_007e2300 = DAT_007e2300 + 1;
        *(short *)(*(int *)(param_2 + 0x48) + piVar12[4] * 2) = (short)DAT_007e2300;
      }
      else {
        sVar11 = sVar11 + -1;
      }
      sVar7 = *(short *)(*(int *)(param_2 + 0x48) + piVar12[5] * 2);
      if (sVar7 == 0) {
        puVar14 = (undefined4 *)(iVar5 + piVar12[5] * iVar2 * 4);
        puVar16 = DAT_007e2808 + DAT_007e2300 * 8;
        for (iVar10 = 8; iVar10 != 0; iVar10 = iVar10 + -1) {
          *puVar16 = *puVar14;
          puVar14 = puVar14 + 1;
          puVar16 = puVar16 + 1;
        }
        sVar7 = (short)DAT_007e2300;
        DAT_007e2300 = DAT_007e2300 + 1;
        *(short *)(*(int *)(param_2 + 0x48) + piVar12[5] * 2) = (short)DAT_007e2300;
      }
      else {
        sVar7 = sVar7 + -1;
      }
      *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = sVar7;
      DAT_007e2bdc = DAT_007e2bdc + 1;
      *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = sVar11;
      DAT_007e2bdc = DAT_007e2bdc + 1;
      *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = sVar3;
      DAT_007e2bdc = DAT_007e2bdc + 1;
      iVar10 = local_10;
      iVar1 = DAT_005c4314;
      if (piVar12[2] != 0) {
        *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = sVar3;
        DAT_007e2bdc = DAT_007e2bdc + 1;
        *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = sVar11;
        DAT_007e2bdc = DAT_007e2bdc + 1;
        *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = sVar7;
        DAT_007e2bdc = DAT_007e2bdc + 1;
        iVar1 = DAT_005c4314;
      }
    }
    else {
      iStack_c = 0;
      if (0 < piVar12[2]) {
        piVar13 = piVar12 + 4;
        do {
          puVar14 = (undefined4 *)(iVar5 + piVar13[-1] * iVar2 * 4);
          puVar16 = puVar15;
          for (iVar10 = 8; iVar10 != 0; iVar10 = iVar10 + -1) {
            *puVar16 = *puVar14;
            puVar14 = puVar14 + 1;
            puVar16 = puVar16 + 1;
          }
          puVar14 = (undefined4 *)(iVar5 + *piVar13 * iVar2 * 4);
          puVar16 = puVar15 + 8;
          for (iVar10 = 8; iVar10 != 0; iVar10 = iVar10 + -1) {
            *puVar16 = *puVar14;
            puVar14 = puVar14 + 1;
            puVar16 = puVar16 + 1;
          }
          (**(code **)(*param_1 + 0x70))(param_1,2,0x1e2,DAT_007e2808,2,param_4);
          iStack_c = iStack_c + 1;
          piVar13 = piVar13 + 2;
          iVar10 = local_10;
        } while (iStack_c < piVar12[2]);
      }
      iVar1 = piVar12[2] * 2 + 3;
    }
    piVar12 = piVar12 + iVar1;
  }
  if ((iVar10 == 1) && (DAT_007e2bdc != 0)) {
    (**(code **)(*param_1 + 0x74))
              (param_1,4,0x1e2,DAT_007e2808,DAT_007e2300,DAT_005d5adc,DAT_007e2bdc,param_4);
  }
  return;
}


