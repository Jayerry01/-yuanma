void __thiscall FUN_00477ff0(float *param_1,float param_2)

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
  *param_1 = (float)((float10)fVar1 * (float10)*param_1 - fVar5 * (float10)param_1[8]);
  param_1[1] = (float)((float10)fVar1 * (float10)param_1[1] - fVar5 * (float10)param_1[9]);
  fVar4 = param_1[10];
  param_1[10] = (float)(fVar5 * (float10)param_1[2] + (float10)fVar1 * (float10)param_1[10]);
  param_1[2] = (float)((float10)fVar1 * (float10)param_1[2] - fVar5 * (float10)fVar4);
  fVar4 = param_1[0xb];
  param_1[0xb] = (float)(fVar5 * (float10)param_1[3] + (float10)fVar1 * (float10)param_1[0xb]);
  param_1[3] = (float)((float10)fVar1 * (float10)param_1[3] - fVar5 * (float10)fVar4);
  param_1[8] = (float)(fVar5 * (float10)fVar2 + fVar6 * (float10)param_1[8]);
  param_1[9] = (float)(fVar5 * (float10)fVar3 + (float10)fVar1 * (float10)param_1[9]);
  return;
}


