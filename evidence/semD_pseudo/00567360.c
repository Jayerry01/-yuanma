float10 FUN_00567360(undefined4 param_1,float *param_2,byte param_3)

{
  float10 fVar1;
  
  if ((param_3 & 8) != 0) {
    fVar1 = (float10)FUN_0047ecf0();
    return fVar1;
  }
  if ((param_3 & 0x10) != 0) {
    fVar1 = (float10)FUN_0047ecf0();
    return fVar1;
  }
  fVar1 = (float10)0.0;
  if ((param_3 & 1) != 0) {
    fVar1 = (float10)*param_2;
  }
  if ((param_3 & 2) != 0) {
    fVar1 = fVar1 + (float10)param_2[1];
  }
  if ((param_3 & 4) != 0) {
    fVar1 = fVar1 + (float10)param_2[2];
  }
  return fVar1;
}


