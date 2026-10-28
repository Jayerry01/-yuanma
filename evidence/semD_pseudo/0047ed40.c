void __fastcall FUN_0047ed40(float *param_1)

{
  float fVar1;
  
  fVar1 = param_1[3] * param_1[3] +
          param_1[2] * param_1[2] + param_1[1] * param_1[1] + *param_1 * *param_1;
  if ((fVar1 != 1.0) && (fVar1 != 0.0)) {
    fVar1 = 1.0 / SQRT(fVar1);
    *param_1 = fVar1 * *param_1;
    param_1[1] = fVar1 * param_1[1];
    param_1[2] = fVar1 * param_1[2];
    param_1[3] = fVar1 * param_1[3];
  }
  return;
}


