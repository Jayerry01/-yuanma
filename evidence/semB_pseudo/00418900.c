void FUN_00418900(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int *piVar12;
  int *local_1c;
  int local_18;
  int iStack_10;
  short local_8;
  short local_6;
  
  iVar3 = *(int *)(param_2 + 0x38) * 6;
  if (DAT_007e0eac < iVar3) {
    DAT_007e0eac = iVar3;
    DAT_005d5adc = FUN_005099a7(DAT_005d5adc,*(int *)(param_2 + 0x38) * 0xc);
  }
  if (*(int *)(param_2 + 0x48) == 0) {
    pvVar2 = _malloc(*(int *)(param_2 + 0x18) * 2);
    *(void **)(param_2 + 0x48) = pvVar2;
  }
  uVar7 = *(uint *)(param_2 + 0x18);
  puVar10 = *(undefined4 **)(param_2 + 0x48);
  for (uVar6 = (uVar7 & 0x7fffffff) >> 1; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  for (uVar7 = uVar7 * 2 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined1 *)puVar10 = 0;
    puVar10 = (undefined4 *)((int)puVar10 + 1);
  }
  iVar3 = *(int *)(param_2 + 0x18) * 0x20;
  if (DAT_007e0eb8 < iVar3) {
    DAT_007e0eb8 = iVar3;
    DAT_007e2808 = (undefined4 *)FUN_005099a7(DAT_007e2808,iVar3);
  }
  iVar1 = DAT_007eac64;
  puVar10 = DAT_007e2808;
  DAT_007e2300 = 0;
  DAT_007e2bdc = 0;
  local_1c = *(int **)(param_2 + 0x40);
  iVar3 = *(int *)(param_2 + 0x1c);
  local_18 = *local_1c;
  DAT_005c4618 = local_1c[1];
  FUN_0041a490(param_1,param_3);
  for (iVar4 = *(int *)(param_2 + 0x38); iVar4 != 0; iVar4 = iVar4 + -1) {
    if (*local_1c != local_18) {
      if ((local_18 == 1) && (DAT_007e2bdc != 0)) {
        (**(code **)(*param_1 + 0x74))
                  (param_1,4,0x112,DAT_007e2808,DAT_007e2300,DAT_005d5adc,DAT_007e2bdc,param_4);
        uVar7 = *(uint *)(param_2 + 0x18);
        puVar9 = *(undefined4 **)(param_2 + 0x48);
        for (uVar6 = (uVar7 & 0x7fffffff) >> 1; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar9 = 0;
          puVar9 = puVar9 + 1;
        }
        for (uVar7 = uVar7 * 2 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined1 *)puVar9 = 0;
          puVar9 = (undefined4 *)((int)puVar9 + 1);
        }
        DAT_007e2300 = 0;
        DAT_007e2bdc = 0;
      }
      local_18 = *local_1c;
    }
    if (local_1c[1] != DAT_005c4618) {
      if ((local_18 == 1) && (DAT_007e2bdc != 0)) {
        (**(code **)(*param_1 + 0x74))
                  (param_1,4,0x112,DAT_007e2808,DAT_007e2300,DAT_005d5adc,DAT_007e2bdc,param_4);
        uVar7 = *(uint *)(param_2 + 0x18);
        puVar9 = *(undefined4 **)(param_2 + 0x48);
        for (uVar6 = (uVar7 & 0x7fffffff) >> 1; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar9 = 0;
          puVar9 = puVar9 + 1;
        }
        for (uVar7 = uVar7 * 2 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined1 *)puVar9 = 0;
          puVar9 = (undefined4 *)((int)puVar9 + 1);
        }
        DAT_007e2300 = 0;
        DAT_007e2bdc = 0;
      }
      DAT_005c4618 = local_1c[1];
      FUN_0041a490(param_1,param_3);
    }
    if (local_18 == 1) {
      local_8 = *(short *)(*(int *)(param_2 + 0x48) + local_1c[3] * 2);
      if (local_8 == 0) {
        puVar9 = (undefined4 *)(iVar3 + local_1c[3] * iVar1 * 4);
        puVar11 = DAT_007e2808 + DAT_007e2300 * 8;
        for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar11 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar11 = puVar11 + 1;
        }
        local_8 = (short)DAT_007e2300;
        DAT_007e2300 = DAT_007e2300 + 1;
        *(short *)(*(int *)(param_2 + 0x48) + local_1c[3] * 2) = (short)DAT_007e2300;
      }
      else {
        local_8 = local_8 + -1;
      }
      local_6 = *(short *)(*(int *)(param_2 + 0x48) + local_1c[4] * 2);
      if (local_6 == 0) {
        puVar9 = (undefined4 *)(iVar3 + local_1c[4] * iVar1 * 4);
        puVar11 = DAT_007e2808 + DAT_007e2300 * 8;
        for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar11 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar11 = puVar11 + 1;
        }
        local_6 = (short)DAT_007e2300;
        DAT_007e2300 = DAT_007e2300 + 1;
        *(short *)(*(int *)(param_2 + 0x48) + local_1c[4] * 2) = (short)DAT_007e2300;
      }
      else {
        local_6 = local_6 + -1;
      }
      sVar5 = *(short *)(*(int *)(param_2 + 0x48) + local_1c[5] * 2);
      if (sVar5 == 0) {
        puVar9 = (undefined4 *)(iVar3 + local_1c[5] * iVar1 * 4);
        puVar11 = DAT_007e2808 + DAT_007e2300 * 8;
        for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar11 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar11 = puVar11 + 1;
        }
        sVar5 = (short)DAT_007e2300;
        DAT_007e2300 = DAT_007e2300 + 1;
        *(short *)(*(int *)(param_2 + 0x48) + local_1c[5] * 2) = (short)DAT_007e2300;
      }
      else {
        sVar5 = sVar5 + -1;
      }
      *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = sVar5;
      DAT_007e2bdc = DAT_007e2bdc + 1;
      *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = local_6;
      DAT_007e2bdc = DAT_007e2bdc + 1;
      *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = local_8;
      DAT_007e2bdc = DAT_007e2bdc + 1;
      iVar8 = DAT_005c4314;
      if (local_1c[2] != 0) {
        *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = local_8;
        DAT_007e2bdc = DAT_007e2bdc + 1;
        *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = local_6;
        DAT_007e2bdc = DAT_007e2bdc + 1;
        *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = sVar5;
        DAT_007e2bdc = DAT_007e2bdc + 1;
        iVar8 = DAT_005c4314;
      }
    }
    else {
      iStack_10 = 0;
      if (0 < local_1c[2]) {
        piVar12 = local_1c + 4;
        do {
          iVar8 = piVar12[-1] * iVar1;
          *puVar10 = *(undefined4 *)(iVar3 + iVar8 * 4);
          puVar10[1] = *(undefined4 *)(iVar3 + 4 + iVar8 * 4);
          puVar10[2] = *(undefined4 *)(iVar3 + 8 + iVar8 * 4);
          puVar10[4] = DAT_005d5ae0;
          puVar10[5] = DAT_005d5ae4;
          puVar10[6] = *(undefined4 *)(iVar3 + 0x18 + iVar8 * 4);
          puVar10[7] = *(undefined4 *)(iVar3 + 0x1c + iVar8 * 4);
          iVar8 = *piVar12 * iVar1;
          puVar10[8] = *(undefined4 *)(iVar3 + iVar8 * 4);
          puVar10[9] = *(undefined4 *)(iVar3 + 4 + iVar8 * 4);
          puVar10[10] = *(undefined4 *)(iVar3 + 8 + iVar8 * 4);
          puVar10[0xc] = DAT_005d5ae0;
          puVar10[0xd] = DAT_005d5ae4;
          puVar10[0xe] = *(undefined4 *)(iVar3 + 0x18 + iVar8 * 4);
          puVar10[0xf] = *(undefined4 *)(iVar3 + 0x1c + iVar8 * 4);
          (**(code **)(*param_1 + 0x70))(param_1,2,0x1e2,DAT_007e2808,2,param_4);
          iStack_10 = iStack_10 + 1;
          piVar12 = piVar12 + 2;
        } while (iStack_10 < local_1c[2]);
      }
      iVar8 = local_1c[2] * 2 + 3;
    }
    local_1c = local_1c + iVar8;
  }
  if ((local_18 == 1) && (DAT_007e2bdc != 0)) {
    (**(code **)(*param_1 + 0x74))
              (param_1,4,0x112,DAT_007e2808,DAT_007e2300,DAT_005d5adc,DAT_007e2bdc,param_4);
  }
  return;
}


