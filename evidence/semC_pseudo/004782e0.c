FUN_004782e0(float *param_1,float param_2,float param_3,float param_4,float param_5,char param_6)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  float *pfVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  float local_80 [4];
  float local_70;
  float local_6c;
  float local_68;
  float local_60;
  float local_5c;
  float local_58;
  undefined1 local_40 [64];
  
  fcos((float10)param_2);
  fVar6 = (float10)fsin((float10)param_2);
  fVar1 = (float)fVar6;
  fVar2 = param_5 * param_5 + param_4 * param_4 + param_3 * param_3;
  if (ABS(fVar2) < 1e-07) {
    return 0;
  }
  if (fVar2 != 1.0) {
    fVar2 = 1.0 / SQRT(fVar2);
    param_3 = param_3 * fVar2;
    param_4 = param_4 * fVar2;
    param_5 = fVar2 * param_5;
  }
  fVar6 = (float10)FUN_00477200();
  fVar7 = (float10)1.0 - fVar6;
  local_80[0] = (float)((float10)param_3 * (float10)param_3 * fVar7 + fVar6);
  fVar8 = (float10)param_3 * (float10)param_4 * fVar7;
  local_80[1] = (float)((float10)fVar1 * (float10)param_5 + fVar8);
  local_60 = (float)((float10)param_3 * (float10)param_5 * fVar7);
  local_80[2] = local_60 - fVar1 * param_4;
  local_70 = (float)(fVar8 - (float10)fVar1 * (float10)param_5);
  local_6c = (float)((float10)param_4 * (float10)param_4 * fVar7 + fVar6);
  fVar8 = (float10)param_4 * (float10)param_5 * fVar7;
  local_68 = (float)((float10)fVar1 * (float10)param_3 + fVar8);
  local_60 = fVar1 * param_4 + local_60;
  local_5c = (float)(fVar8 - (float10)fVar1 * (float10)param_3);
  local_58 = (float)((float10)param_5 * (float10)param_5 * fVar7 + fVar6);
  if (param_6 == '\0') {
    pfVar3 = local_80;
    pfVar5 = param_1;
  }
  else {
    pfVar3 = param_1;
    pfVar5 = local_80;
  }
  pfVar3 = (float *)FUN_00476f00(local_40,pfVar3,pfVar5);
  pfVar5 = local_80;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar5 = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pfVar5 = pfVar5 + 1;
  }
  pfVar3 = local_80;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *param_1 = *pfVar3;
    pfVar3 = pfVar3 + 1;
    param_1 = param_1 + 1;
  }
  return 1;
}



void __thiscall