void __thiscall FUN_0055a9f0(int param_1,int param_2,int param_3)

{
  float *pfVar1;
  
  if (param_3 < param_2) {
    param_2 = param_3;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  *(int *)(param_1 + 0x10) = param_3;
  *(int *)(param_1 + 8) = param_2;
  *(float *)(param_1 + 0x1664) = (float)param_2 / (float)param_3;
  pfVar1 = (float *)FUN_00481b30();
  *pfVar1 = *(float *)(param_1 + 0x1664) * *(float *)(param_1 + 0x28) * -0.5;
  pfVar1[1] = *(float *)(param_1 + 0x2c) * -0.5;
  pfVar1[6] = *(float *)(param_1 + 0x1664) * *(float *)(param_1 + 0x28) * 0.5;
  pfVar1[7] = *(float *)(param_1 + 0x2c) * -0.5;
  pfVar1[0xc] = *(float *)(param_1 + 0x1664) * *(float *)(param_1 + 0x28) * 0.5;
  pfVar1[0xd] = *(float *)(param_1 + 0x2c) * 0.5;
  pfVar1[0x12] = *(float *)(param_1 + 0x1664) * *(float *)(param_1 + 0x28) * -0.5;
  pfVar1[0x13] = *(float *)(param_1 + 0x2c) * 0.5;
  FUN_00481b90();
  return;
}



void __thiscall