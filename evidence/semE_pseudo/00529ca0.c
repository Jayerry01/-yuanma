void FUN_00529ca0(undefined4 param_1)

{
  float *extraout_EDX;
  float10 fVar1;
  
  fVar1 = (float10)FUN_00529c80(param_1,param_1);
  if (SQRT(fVar1) != (float10)0.0) {
    fVar1 = (float10)1.0 / SQRT(fVar1);
    *extraout_EDX = (float)(fVar1 * (float10)*extraout_EDX);
    extraout_EDX[1] = (float)(fVar1 * (float10)extraout_EDX[1]);
    extraout_EDX[2] = (float)(fVar1 * (float10)extraout_EDX[2]);
    return;
  }
  return;
}


