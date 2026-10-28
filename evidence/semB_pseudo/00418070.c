void FUN_00418070(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  short sVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  short local_8;
  
  iVar3 = *(int *)(param_2 + 0x38) * 6;
  if (DAT_007e0eac < iVar3) {
    DAT_007e0eac = iVar3;
    DAT_005d5adc = FUN_005099a7(DAT_005d5adc,*(int *)(param_2 + 0x38) * 0xc);
  }
  if (*(int *)(param_2 + 0xc) != 1) {
    if (*(int *)(param_2 + 0x48) == 0) {
      pvVar2 = _malloc(*(int *)(param_2 + 0x18) * 2);
      *(void **)(param_2 + 0x48) = pvVar2;
    }
    uVar8 = *(uint *)(param_2 + 0x18);
    puVar11 = *(undefined4 **)(param_2 + 0x48);
    for (uVar7 = (uVar8 & 0x7fffffff) >> 1; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar11 = 0;
      puVar11 = puVar11 + 1;
    }
    for (uVar8 = uVar8 * 2 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined1 *)puVar11 = 0;
      puVar11 = (undefined4 *)((int)puVar11 + 1);
    }
    iVar3 = *(int *)(param_2 + 0x18) * 0x20;
    if (DAT_007e0eb8 < iVar3) {
      DAT_007e0eb8 = iVar3;
      DAT_007e2808 = FUN_005099a7(DAT_007e2808,iVar3);
    }
    iVar1 = DAT_007eac64;
    DAT_007e2300 = 0;
    DAT_007e2bdc = 0;
    iVar3 = *(int *)(param_2 + 0x40);
    iVar6 = *(int *)(param_2 + 0x1c);
    DAT_005c4618 = *(int *)(iVar3 + 4);
    FUN_0041a490(param_1,param_3);
    for (iVar4 = *(int *)(param_2 + 0x38); iVar4 != 0; iVar4 = iVar4 + -1) {
      if (*(int *)(iVar3 + 4) != DAT_005c4618) {
        if (DAT_007e2bdc != 0) {
          (**(code **)(*param_1 + 0x74))
                    (param_1,4,0x112,DAT_007e2808,DAT_007e2300,DAT_005d5adc,DAT_007e2bdc,param_4);
          uVar8 = *(uint *)(param_2 + 0x18);
          puVar11 = *(undefined4 **)(param_2 + 0x48);
          for (uVar7 = (uVar8 & 0x7fffffff) >> 1; uVar7 != 0; uVar7 = uVar7 - 1) {
            *puVar11 = 0;
            puVar11 = puVar11 + 1;
          }
          for (uVar8 = uVar8 * 2 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined1 *)puVar11 = 0;
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          DAT_007e2300 = 0;
          DAT_007e2bdc = 0;
        }
        DAT_005c4618 = *(int *)(iVar3 + 4);
        FUN_0041a490(param_1,param_3);
      }
      local_8 = *(short *)(*(int *)(param_2 + 0x48) + *(int *)(iVar3 + 0xc) * 2);
      if (local_8 == 0) {
        puVar11 = (undefined4 *)(iVar6 + *(int *)(iVar3 + 0xc) * iVar1 * 4);
        puVar12 = (undefined4 *)(DAT_007e2300 * 0x20 + DAT_007e2808);
        for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar12 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar12 = puVar12 + 1;
        }
        local_8 = (short)DAT_007e2300;
        DAT_007e2300 = DAT_007e2300 + 1;
        *(short *)(*(int *)(param_2 + 0x48) + *(int *)(iVar3 + 0xc) * 2) = (short)DAT_007e2300;
      }
      else {
        local_8 = local_8 + -1;
      }
      sVar10 = *(short *)(*(int *)(param_2 + 0x48) + *(int *)(iVar3 + 0x10) * 2);
      if (sVar10 == 0) {
        puVar11 = (undefined4 *)(iVar6 + *(int *)(iVar3 + 0x10) * iVar1 * 4);
        puVar12 = (undefined4 *)(DAT_007e2300 * 0x20 + DAT_007e2808);
        for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar12 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar12 = puVar12 + 1;
        }
        sVar10 = (short)DAT_007e2300;
        DAT_007e2300 = DAT_007e2300 + 1;
        *(short *)(*(int *)(param_2 + 0x48) + *(int *)(iVar3 + 0x10) * 2) = (short)DAT_007e2300;
      }
      else {
        sVar10 = sVar10 + -1;
      }
      sVar5 = *(short *)(*(int *)(param_2 + 0x48) + *(int *)(iVar3 + 0x14) * 2);
      if (sVar5 == 0) {
        puVar11 = (undefined4 *)(iVar6 + *(int *)(iVar3 + 0x14) * iVar1 * 4);
        puVar12 = (undefined4 *)(DAT_007e2300 * 0x20 + DAT_007e2808);
        for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar12 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar12 = puVar12 + 1;
        }
        sVar5 = (short)DAT_007e2300;
        DAT_007e2300 = DAT_007e2300 + 1;
        *(short *)(*(int *)(param_2 + 0x48) + *(int *)(iVar3 + 0x14) * 2) = (short)DAT_007e2300;
      }
      else {
        sVar5 = sVar5 + -1;
      }
      *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = sVar5;
      DAT_007e2bdc = DAT_007e2bdc + 1;
      *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = sVar10;
      DAT_007e2bdc = DAT_007e2bdc + 1;
      *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = local_8;
      DAT_007e2bdc = DAT_007e2bdc + 1;
      if (*(int *)(iVar3 + 8) != 0) {
        *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = local_8;
        DAT_007e2bdc = DAT_007e2bdc + 1;
        *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = sVar10;
        DAT_007e2bdc = DAT_007e2bdc + 1;
        *(short *)(DAT_005d5adc + DAT_007e2bdc * 2) = sVar5;
        DAT_007e2bdc = DAT_007e2bdc + 1;
      }
      iVar3 = iVar3 + DAT_005c4314 * 4;
    }
    if (DAT_007e2bdc != 0) {
      (**(code **)(*param_1 + 0x74))
                (param_1,4,0x112,DAT_007e2808,DAT_007e2300,DAT_005d5adc,DAT_007e2bdc,param_4);
    }
    return;
  }
  iVar3 = *(int *)(param_2 + 0x40);
  DAT_005c4618 = *(undefined4 *)(iVar3 + 4);
  FUN_0041a490(param_1,param_3);
  DAT_007e2bdc = 0;
  for (iVar6 = *(int *)(param_2 + 0x38); iVar6 != 0; iVar6 = iVar6 + -1) {
    *(undefined2 *)(DAT_005d5adc + DAT_007e2bdc * 2) = *(undefined2 *)(iVar3 + 0x14);
    DAT_007e2bdc = DAT_007e2bdc + 1;
    *(undefined2 *)(DAT_005d5adc + DAT_007e2bdc * 2) = *(undefined2 *)(iVar3 + 0x10);
    DAT_007e2bdc = DAT_007e2bdc + 1;
    *(undefined2 *)(DAT_005d5adc + DAT_007e2bdc * 2) = *(undefined2 *)(iVar3 + 0xc);
    DAT_007e2bdc = DAT_007e2bdc + 1;
    if (*(int *)(iVar3 + 8) != 0) {
      *(undefined2 *)(DAT_005d5adc + DAT_007e2bdc * 2) = *(undefined2 *)(iVar3 + 0xc);
      DAT_007e2bdc = DAT_007e2bdc + 1;
      *(undefined2 *)(DAT_005d5adc + DAT_007e2bdc * 2) = *(undefined2 *)(iVar3 + 0x10);
      DAT_007e2bdc = DAT_007e2bdc + 1;
      *(undefined2 *)(DAT_005d5adc + DAT_007e2bdc * 2) = *(undefined2 *)(iVar3 + 0x14);
      DAT_007e2bdc = DAT_007e2bdc + 1;
      DAT_007e3340 = DAT_007e3340 + 1;
    }
    iVar3 = iVar3 + DAT_005c4314 * 4;
  }
  (**(code **)(*param_1 + 0x74))
            (param_1,4,0x112,*(undefined4 *)(param_2 + 0x1c),*(undefined4 *)(param_2 + 0x18),
             DAT_005d5adc,DAT_007e2bdc,param_4);
  return;
}


