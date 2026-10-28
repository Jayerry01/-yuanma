void FUN_0047ee00(float *param_1,float *param_2,float *param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  
  pfVar4 = param_2;
  param_2 = (float *)(param_3[3] * param_2[3] +
                     param_2[1] * param_3[1] + param_2[2] * param_3[2] + *param_2 * *param_3);
  if (0.0 <= (float)param_2) {
    local_20 = *param_3;
    local_1c = param_3[1];
    local_18 = param_3[2];
    local_14 = param_3[3];
  }
  else {
    param_2 = (float *)-(float)param_2;
    local_20 = -*param_3;
    local_1c = -param_3[1];
    local_18 = -param_3[2];
    local_14 = -param_3[3];
  }
  if (1.0 - (float)param_2 <= 0.0001) {
    fVar7 = (float10)1.0 - (float10)param_4;
    fVar5 = (float10)param_4;
  }
  else {
    fVar5 = (float10)FUN_00509d10();
    fVar6 = (float10)fsin(fVar5);
    fVar7 = (float10)fsin(((float10)1.0 - (float10)param_4) * (float10)(float)fVar5);
    fVar7 = fVar7 * (float10)(float)((float10)1.0 / fVar6);
    fVar5 = (float10)fsin((float10)(float)fVar5 * (float10)param_4);
    fVar5 = fVar5 * (float10)(float)((float10)1.0 / fVar6);
  }
  fVar1 = pfVar4[1];
  fVar2 = pfVar4[2];
  fVar3 = pfVar4[3];
  *param_1 = (float)(fVar5 * (float10)local_20 + fVar7 * (float10)*pfVar4);
  param_1[1] = (float)(fVar5 * (float10)local_1c + fVar7 * (float10)fVar1);
  param_1[2] = (float)(fVar5 * (float10)local_18 + fVar7 * (float10)fVar2);
  param_1[3] = (float)(fVar7 * (float10)fVar3 + fVar5 * (float10)local_14);
  return;
}


