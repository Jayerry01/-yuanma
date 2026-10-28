void FUN_00501730(float *param_1)

{
  float fVar1;
  int iVar2;
  
  iVar2 = __ftol();
  fVar1 = (*param_1 - (float)iVar2) + (float)(iVar2 % 0x168);
  *param_1 = fVar1;
  if (fVar1 < 0.0) {
    *param_1 = fVar1 + 360.0;
    return;
  }
  return;
}


