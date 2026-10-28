void FUN_005016d0(float *param_1,float *param_2,float *param_3)

{
  float10 fVar1;
  
  fVar1 = (float10)fpatan((float10)param_1[1],(float10)*param_1);
  *param_2 = (float)(fVar1 * (float10)57.29577791868205 + (float10)90.0);
  FUN_00501730(param_2);
  fVar1 = (float10)fpatan((float10)param_1[2],
                          SQRT((float10)param_1[1] * (float10)param_1[1] +
                               (float10)*param_1 * (float10)*param_1));
  *param_3 = (float)(fVar1 * (float10)57.29577791868205);
  return;
}


