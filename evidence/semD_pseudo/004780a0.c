void __thiscall FUN_004780a0(float *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float10 fVar5;
  float10 fVar6;
  
  fVar5 = (float10)fsin((float10)param_2);
  fVar6 = (float10)fcos((float10)param_2);
  fVar1 = (float)fVar6;
  fVar2 = *param_1;
  fVar3 = param_1[1];
  *param_1 = (float)((float10)fVar1 * (float10)*param_1 + fVar5 * (float10)param_1[4]);
  param_1[1] = (float)(fVar5 * (float10)param_1[5] + (float10)fVar1 * (float10)param_1[1]);
  fVar4 = param_1[6];
  param_1[6] = (float)((float10)fVar1 * (float10)param_1[6] - fVar5 * (float10)param_1[2]);
  param_1[2] = (float)(fVar5 * (float10)fVar4 + (float10)fVar1 * (float10)param_1[2]);
  fVar4 = param_1[7];
  param_1[7] = (float)((float10)fVar1 * (float10)param_1[7] - fVar5 * (float10)param_1[3]);
  param_1[3] = (float)(fVar5 * (float10)fVar4 + (float10)fVar1 * (float10)param_1[3]);
  param_1[4] = (float)(fVar6 * (float10)param_1[4] - fVar5 * (float10)fVar2);
  param_1[5] = (float)((float10)fVar1 * (float10)param_1[5] - fVar5 * (float10)fVar3);
  return;
}


