void FUN_00501630(float param_1,float param_2,float *param_3)

{
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = ((float10)param_1 - (float10)90.0) * (float10)0.017453292;
  fVar2 = (float10)fcos(fVar1);
  *param_3 = (float)fVar2;
  fVar1 = (float10)fsin(fVar1);
  param_3[1] = (float)fVar1;
  fVar1 = (float10)fptan((float10)param_2 * (float10)0.017453292);
  param_3[2] = (float)fVar1;
  FUN_0047ec40();
  return;
}


