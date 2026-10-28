undefined4 __fastcall FUN_004f7ec0(int param_1)

{
  int *piVar1;
  float fVar2;
  short sVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  ushort *puVar13;
  int iVar14;
  undefined4 *puVar15;
  float10 fVar16;
  undefined2 *local_1c;
  ushort *local_18;
  float local_14;
  int local_10;
  int local_c;
  int local_8;
  uint local_4;
  
  piVar1 = (int *)(param_1 + 4);
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    return 1;
  }
  puVar4 = (undefined4 *)*piVar1;
  local_18 = (ushort *)*puVar4;
  puVar7 = (undefined4 *)(*(int *)(param_1 + 8) + -4);
  puVar13 = local_18;
  puVar15 = (undefined4 *)(param_1 + 0x1c);
  for (iVar10 = 5; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar15 = *(undefined4 *)puVar13;
    puVar13 = puVar13 + 2;
    puVar15 = puVar15 + 1;
  }
  local_10 = param_1;
  FUN_004f8770(puVar4,puVar7,puVar7,*puVar7);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -4;
  if ((uint)*local_18 == *(uint *)(param_1 + 0x30)) {
    FUN_00507850(local_18);
    return 0;
  }
  iVar8 = FUN_004f8330((uint)*local_18);
  local_4 = 0;
  iVar10 = param_1;
  local_8 = iVar8;
  if (*(int *)(iVar8 + 0x1c) - *(int *)(iVar8 + 0x18) >> 3 != 0) {
    do {
      uVar6 = local_4;
      sVar3 = *(short *)(*(int *)(iVar8 + 0x18) + local_4 * 8);
      if (((*(short **)(local_18 + 8) == (short *)0x0) || (**(short **)(local_18 + 8) != sVar3)) &&
         (local_c = FUN_004f8330(sVar3), *(char *)(local_c + 0x16) != '\0')) {
        iVar12 = *(int *)(iVar8 + 0x18);
        local_14 = *(float *)(local_18 + 2) + *(float *)(iVar12 + 4 + uVar6 * 8);
        if (*(char *)(iVar12 + 2 + uVar6 * 8) == '\x01') {
          local_14 = local_14 + *(float *)(iVar12 + uVar6 * 8 + 4);
        }
        piVar9 = (int *)FUN_004f8260((int)*(short *)(local_c + 0x12),piVar1);
        if (piVar9 != *(int **)(iVar10 + 8)) {
          fVar2 = *(float *)(*piVar9 + 4);
          if (fVar2 < local_14 != (fVar2 == local_14)) goto LAB_004f817a;
          FUN_00507850(*piVar9);
          if (piVar9 + 1 != *(int **)(param_1 + 8)) {
            FUN_0049f3d0(piVar9 + 1,*(int **)(param_1 + 8),piVar9,local_4,0);
          }
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -4;
          iVar8 = *piVar1;
          iVar12 = *(int *)(iVar10 + 8) - iVar8 >> 2;
          iVar10 = local_10;
          if (1 < iVar12) {
            for (iVar14 = (iVar12 + -2) / 2;
                FUN_004f8820(iVar8,iVar14,iVar12,*(undefined4 *)(iVar8 + iVar14 * 4),local_4),
                iVar10 = local_10, iVar14 != 0; iVar14 = iVar14 + -1) {
            }
          }
        }
        piVar9 = (int *)FUN_004f8260((int)*(short *)(local_c + 0x12),iVar10 + 0x10);
        if (piVar9 != *(int **)(iVar10 + 0x14)) {
          fVar2 = *(float *)(*piVar9 + 4);
          iVar8 = local_8;
          if (fVar2 < local_14 != (fVar2 == local_14)) goto LAB_004f817a;
          FUN_00507850(*piVar9);
          if (piVar9 + 1 != *(int **)(iVar10 + 0x14)) {
            FUN_0049f3d0(piVar9 + 1,*(int **)(iVar10 + 0x14),piVar9,local_4,0);
          }
          *(int *)(iVar10 + 0x14) = *(int *)(iVar10 + 0x14) + -4;
        }
        local_1c = operator_new(0x14);
        *local_1c = *(undefined2 *)(local_c + 0x12);
        *(float *)(local_1c + 2) = local_14;
        fVar16 = (float10)FUN_004f81e0(local_1c);
        *(float *)(local_1c + 4) = (float)fVar16;
        *(float *)(local_1c + 6) = *(float *)(local_1c + 4) + *(float *)(local_1c + 2);
        *(ushort **)(local_1c + 8) = local_18;
        puVar4 = *(undefined4 **)(param_1 + 8);
        if (puVar4 == *(undefined4 **)(param_1 + 0xc)) {
          FUN_004f84b0(puVar4,&local_1c);
        }
        else {
          if (puVar4 != (undefined4 *)0x0) {
            *puVar4 = local_1c;
          }
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 4;
        }
        iVar12 = *piVar1;
        local_c = *(int *)(*(int *)(iVar10 + 8) + -4);
        iVar14 = *(int *)(iVar10 + 8) - iVar12 >> 2;
        iVar8 = iVar14 + -2;
        iVar14 = iVar14 + -1;
        while (0 < iVar14) {
          iVar11 = iVar8 / 2;
          iVar5 = *(int *)(iVar12 + iVar11 * 4);
          if (*(float *)(iVar5 + 0xc) <= *(float *)(local_c + 0xc)) break;
          iVar8 = iVar11 + -1;
          *(int *)(iVar12 + iVar14 * 4) = iVar5;
          iVar14 = iVar11;
        }
        *(int *)(iVar12 + iVar14 * 4) = local_c;
        iVar8 = local_8;
      }
LAB_004f817a:
      local_4 = local_4 + 1;
    } while (local_4 < (uint)(*(int *)(iVar8 + 0x1c) - *(int *)(iVar8 + 0x18) >> 3));
  }
  puVar4 = *(undefined4 **)(iVar10 + 0x14);
  if (puVar4 != *(undefined4 **)(iVar10 + 0x18)) {
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = local_18;
    }
    *(int *)(iVar10 + 0x14) = *(int *)(iVar10 + 0x14) + 4;
    return 2;
  }
  FUN_004f84b0(puVar4,&local_18);
  return 2;
}


