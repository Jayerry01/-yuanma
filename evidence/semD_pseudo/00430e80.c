void FUN_00430e80(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  
  *param_1 = param_3[2] * param_2[1] - param_2[2] * param_3[1];
  param_1[1] = param_2[2] * *param_3 - param_3[2] * *param_2;
  fVar1 = *param_2 * param_3[1] - *param_3 * param_2[1];
  param_1[2] = fVar1;
  fVar1 = fVar1 * fVar1 + param_1[1] * param_1[1] + *param_1 * *param_1;
  fVar2 = fVar1;
  if (fVar1 <= 0.0) {
    fVar2 = -fVar1;
  }
  if (fVar2 < 1e-06) {
    *param_1 = 0.0;
    param_1[1] = 0.0;
    param_1[2] = 0.0;
    return;
  }
  fVar1 = 1.0 / SQRT(fVar1);
  *param_1 = *param_1 * fVar1;
  param_1[1] = param_1[1] * fVar1;
  param_1[2] = param_1[2] * fVar1;
  return;
}


