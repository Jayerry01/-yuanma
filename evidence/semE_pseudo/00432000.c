float10 FUN_00432000(float param_1,float param_2)

{
  float10 fVar1;
  float10 fVar2;
  
  if (param_1 == 0.0) {
    return (float10)0.0;
  }
  fVar1 = (float10)log2((float10)param_1);
  fVar2 = (float10)1.4426950408889634 * (float10)0.6931471805599453 * fVar1 * (float10)param_2;
  fVar1 = ROUND(fVar2);
  fVar2 = (float10)f2xm1(fVar2 - fVar1);
  fVar1 = (float10)fscale((float10)1 + fVar2,fVar1);
  return fVar1;
}


