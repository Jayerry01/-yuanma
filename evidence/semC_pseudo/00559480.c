void __fastcall FUN_00559480(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  float *pfVar9;
  undefined4 *puVar10;
  float *pfVar11;
  int local_30;
  int local_2c;
  int local_28;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if ((*(int *)(param_1 + 0x50) != 0) && (*(int *)(param_1 + 0xc) != 0)) {
    iVar8 = *(int *)(param_1 + 8);
    if (iVar8 < *(int *)(param_1 + 4)) {
      piVar4 = (int *)(*(int *)(param_1 + 0x380) + iVar8 * 0x3c + 0x10);
      do {
        iVar5 = 0;
        iVar2 = *(int *)(param_1 + 0xfc);
        iVar3 = piVar4[9];
        if (0 < *piVar4) {
          local_2c = 0;
          iVar6 = 0;
          do {
            puVar10 = (undefined4 *)(piVar4[4] + local_2c);
            puVar7 = (undefined4 *)(*(int *)(iVar3 + iVar2 * 4) + iVar6);
            iVar5 = iVar5 + 1;
            iVar6 = iVar6 + 0xc;
            *puVar10 = *puVar7;
            puVar10[1] = puVar7[1];
            puVar10[2] = puVar7[2];
            local_2c = local_2c + 0x2c;
          } while (iVar5 < *piVar4);
        }
        iVar8 = iVar8 + 1;
        piVar4 = piVar4 + 0xf;
      } while (iVar8 < *(int *)(param_1 + 4));
    }
  }
  local_30 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    piVar4 = (int *)(*(int *)(param_1 + 0x380) + 0x10);
    do {
      pfVar9 = (float *)piVar4[4];
      pfVar11 = (float *)piVar4[5];
      local_28 = 0;
      if (0 < *piVar4) {
        do {
          if ((pfVar9[8] == 1.4013e-45) || (*(int *)(param_1 + 0x348) == 0)) {
            FUN_00476e20(pfVar11,pfVar9,
                         *(int *)(param_1 + 0x350) + 0x244 + *(int *)pfVar9[9] * 0x334);
          }
          else if ((int)pfVar9[8] < 2) {
            *pfVar11 = *pfVar9;
            pfVar11[1] = pfVar9[1];
            pfVar11[2] = pfVar9[2];
          }
          else {
            pfVar11[2] = 0.0;
            pfVar11[1] = 0.0;
            *pfVar11 = 0.0;
            iVar8 = 0;
            if (0 < (int)pfVar9[8]) {
              do {
                FUN_00476e20(&local_18,pfVar9,
                             *(int *)(param_1 + 0x350) + 0x244 +
                             *(int *)((int)pfVar9[9] + iVar8 * 4) * 0x334);
                fVar1 = *(float *)((int)pfVar9[10] + iVar8 * 4);
                local_18 = local_18 * fVar1;
                iVar8 = iVar8 + 1;
                local_14 = local_14 * fVar1;
                local_10 = local_10 * fVar1;
                local_c = local_18 + *pfVar11;
                local_8 = local_14 + pfVar11[1];
                local_4 = local_10 + pfVar11[2];
                *pfVar11 = local_c;
                pfVar11[1] = local_8;
                pfVar11[2] = local_4;
              } while (iVar8 < (int)pfVar9[8]);
            }
          }
          pfVar9 = pfVar9 + 0xb;
          pfVar11 = pfVar11 + 6;
          local_28 = local_28 + 1;
        } while (local_28 < *piVar4);
      }
      local_30 = local_30 + 1;
      piVar4 = piVar4 + 0xf;
    } while (local_30 < *(int *)(param_1 + 4));
  }
  return;
}


