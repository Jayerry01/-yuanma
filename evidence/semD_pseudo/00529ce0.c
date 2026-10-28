void FUN_00529ce0(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  fVar1 = param_1[5];
  fVar2 = param_1[3];
  fVar3 = *param_2;
  fVar4 = param_1[4];
  fVar5 = param_1[8];
  fVar6 = param_1[6];
  fVar7 = *param_2;
  fVar8 = param_1[7];
  fVar9 = param_2[1];
  *param_2 = *param_1 * *param_2 + param_1[1] * param_2[1] + param_1[2] * param_2[2];
  param_2[1] = fVar4 * param_2[1] + fVar2 * fVar3 + fVar1 * param_2[2];
  param_2[2] = fVar8 * fVar9 + fVar6 * fVar7 + fVar5 * param_2[2];
  return;
}


