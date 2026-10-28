undefined4 FUN_004239f0(int *param_1,float *param_2,int *param_3)

{
  float fVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int *piVar5;
  float fVar6;
  int iVar7;
  float *pfVar8;
  float *pfVar9;
  float *pfVar10;
  float10 fVar11;
  float10 extraout_ST1;
  float local_c;
  int local_4;
  
  piVar5 = param_1;
  pfVar8 = (float *)param_1[1];
  *param_3 = 0;
  fVar1 = *param_2;
  local_c = param_2[1] * *pfVar8 + pfVar8[1] * param_2[2] + pfVar8[2] * param_2[3];
  iVar7 = *param_1;
  if (0 < iVar7) {
    local_4 = 1;
    bVar4 = fVar1 <= local_c;
    do {
      param_1 = (int *)local_4;
      if (iVar7 <= local_4) {
        param_1 = (int *)0x0;
      }
      if (bVar4 != false) {
        pfVar9 = pfVar8;
        pfVar10 = (float *)param_3[*param_3 + 1];
        for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
          *pfVar10 = *pfVar9;
          pfVar9 = pfVar9 + 1;
          pfVar10 = pfVar10 + 1;
        }
        *param_3 = *param_3 + 1;
      }
      pfVar9 = (float *)piVar5[(int)param_1 + 1];
      fVar11 = (float10)param_2[1] * (float10)*pfVar9 +
               (float10)pfVar9[1] * (float10)param_2[2] + (float10)pfVar9[2] * (float10)param_2[3];
      bVar3 = (float10)fVar1 <= fVar11;
      if (bVar4 != bVar3) {
        fVar11 = ((float10)fVar1 - (float10)local_c) / (fVar11 - (float10)local_c);
        pfVar10 = (float *)param_3[*param_3 + 1];
        *pfVar10 = (float)(((float10)*pfVar9 - (float10)*pfVar8) * fVar11 + (float10)*pfVar8);
        pfVar10[1] = (float)(((float10)*(float *)(piVar5[(int)param_1 + 1] + 4) - (float10)pfVar8[1]
                             ) * fVar11 + (float10)pfVar8[1]);
        pfVar10[2] = (float)(((float10)*(float *)(piVar5[(int)param_1 + 1] + 8) - (float10)pfVar8[2]
                             ) * fVar11 + (float10)pfVar8[2]);
        fVar6 = pfVar8[10];
        iVar7 = __ftol();
        pfVar10[10] = (float)(iVar7 + (int)fVar6);
        fVar6 = (float)__ftol();
        pfVar10[3] = fVar6;
        fVar6 = (float)__ftol();
        pfVar10[4] = fVar6;
        fVar6 = (float)__ftol();
        pfVar10[5] = fVar6;
        *param_3 = *param_3 + 1;
        fVar11 = extraout_ST1;
      }
      iVar7 = *piVar5;
      local_c = (float)fVar11;
      pfVar8 = (float *)piVar5[(int)param_1 + 1];
      bVar2 = local_4 < iVar7;
      local_4 = local_4 + 1;
      bVar4 = bVar3;
    } while (bVar2);
    if (2 < *param_3) {
      return 1;
    }
  }
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
