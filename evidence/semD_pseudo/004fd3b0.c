void __thiscall FUN_004fd3b0(int param_1,float param_2)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  char cVar4;
  uint uVar5;
  
  cVar4 = FUN_00500fd0();
  if (cVar4 == '\0') {
    pfVar2 = (float *)(param_1 + 0xe0);
    FUN_00501730(pfVar2);
    pfVar1 = (float *)(param_1 + 0x3c);
    uVar5 = __ftol();
    fVar3 = (float)(int)((uVar5 ^ (int)uVar5 >> 0x1f) - ((int)uVar5 >> 0x1f));
    if (0.5 <= fVar3) {
      if (180.0 < fVar3) {
        if (*pfVar2 <= 180.0) {
          *pfVar1 = *pfVar1 - 360.0;
        }
        else {
          *pfVar2 = *pfVar2 - 360.0;
        }
      }
      if (3.0 <= fVar3) {
        param_2 = param_2 * 500.0;
        if (fVar3 < param_2) {
          param_2 = fVar3;
        }
        if (*pfVar2 <= *pfVar1) {
          param_2 = -param_2;
        }
      }
      else {
        param_2 = *pfVar2 - *pfVar1;
      }
      FUN_00500c00(param_2);
      FUN_00501730(pfVar2);
      FUN_00501730(pfVar1);
    }
  }
  return;
}


