undefined4 FUN_00423680(int *param_1,float *param_2,int *param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int *piVar4;
  float fVar5;
  int iVar6;
  float *pfVar7;
  float *pfVar8;
  float *pfVar9;
  float10 extraout_ST0;
  float10 fVar10;
  float10 extraout_ST1;
  float local_c;
  int local_4;
  
  piVar4 = param_1;
  pfVar7 = (float *)param_1[1];
  *param_3 = 0;
  local_c = param_2[1] * *pfVar7 + pfVar7[1] * param_2[2] + pfVar7[2] * param_2[3];
  iVar6 = *param_1;
  if (0 < iVar6) {
    local_4 = 1;
    bVar3 = *param_2 <= local_c;
    do {
      param_1 = (int *)local_4;
      if (iVar6 <= local_4) {
        param_1 = (int *)0x0;
      }
      if (bVar3 != false) {
        pfVar8 = pfVar7;
        pfVar9 = (float *)param_3[*param_3 + 1];
        for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
          *pfVar9 = *pfVar8;
          pfVar8 = pfVar8 + 1;
          pfVar9 = pfVar9 + 1;
        }
        *param_3 = *param_3 + 1;
      }
      pfVar8 = (float *)piVar4[(int)param_1 + 1];
      fVar10 = (float10)param_2[1] * (float10)*pfVar8 +
               (float10)pfVar8[1] * (float10)param_2[2] + (float10)pfVar8[2] * (float10)param_2[3];
      bVar2 = (float10)*param_2 <= fVar10;
      if (bVar3 != bVar2) {
        fVar10 = ((float10)*param_2 - (float10)local_c) / (fVar10 - (float10)local_c);
        pfVar9 = (float *)param_3[*param_3 + 1];
        *pfVar9 = (float)(((float10)*pfVar8 - (float10)*pfVar7) * fVar10 + (float10)*pfVar7);
        pfVar9[1] = (float)(((float10)*(float *)(piVar4[(int)param_1 + 1] + 4) - (float10)pfVar7[1])
                            * fVar10 + (float10)pfVar7[1]);
        pfVar9[2] = (float)(((float10)*(float *)(piVar4[(int)param_1 + 1] + 8) - (float10)pfVar7[2])
                            * fVar10 + (float10)pfVar7[2]);
        fVar5 = pfVar7[10];
        iVar6 = __ftol();
        pfVar9[10] = (float)(iVar6 + (int)fVar5);
        pfVar9[6] = (float)(((float10)*(float *)(piVar4[(int)param_1 + 1] + 0x18) -
                            (float10)pfVar7[6]) * extraout_ST0 + (float10)pfVar7[6]);
        pfVar9[7] = (float)(((float10)*(float *)(piVar4[(int)param_1 + 1] + 0x1c) -
                            (float10)pfVar7[7]) * extraout_ST0 + (float10)pfVar7[7]);
        iVar6 = __ftol();
        pfVar9[8] = (float)(iVar6 + (int)pfVar7[8]);
        fVar5 = pfVar7[9];
        iVar6 = __ftol();
        pfVar9[9] = (float)(iVar6 + (int)fVar5);
        fVar5 = (float)__ftol();
        pfVar9[3] = fVar5;
        fVar5 = (float)__ftol();
        pfVar9[4] = fVar5;
        fVar5 = (float)__ftol();
        pfVar9[5] = fVar5;
        *param_3 = *param_3 + 1;
        fVar10 = extraout_ST1;
      }
      iVar6 = *piVar4;
      local_c = (float)fVar10;
      pfVar7 = (float *)piVar4[(int)param_1 + 1];
      bVar1 = local_4 < iVar6;
      local_4 = local_4 + 1;
      bVar3 = bVar2;
    } while (bVar1);
    if (2 < *param_3) {
      return 1;
    }
  }
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
