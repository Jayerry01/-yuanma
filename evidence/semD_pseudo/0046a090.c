undefined4 __thiscall FUN_0046a090(int param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)param_2 + *(float *)(param_1 + 0x28);
  if ((((fVar1 <= (float)*(int *)(param_1 + 0x14)) && ((float)*(int *)(param_1 + 0x20) <= fVar1)) &&
      (fVar2 = (float)param_3 + *(float *)(param_1 + 0x2c), fVar2 <= (float)*(int *)(param_1 + 0x18)
      )) && ((float)*(int *)(param_1 + 0x1c) <= fVar2)) {
    *(float *)(param_1 + 0x2c) = fVar2;
    *(float *)(param_1 + 0x28) = fVar1;
    return 1;
  }
  return 1;
}


