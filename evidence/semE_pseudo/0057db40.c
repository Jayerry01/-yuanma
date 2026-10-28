void __thiscall FUN_0057db40(int param_1,float param_2)

{
  float fVar1;
  
  fVar1 = param_2 - *(float *)(param_1 + 0x168);
  *(float *)(param_1 + 0x30) = fVar1;
  fVar1 = fVar1 * 0.5;
  *(float *)(param_1 + 0x24) = param_2;
  *(float *)(param_1 + 0x164) = param_2;
  *(float *)(param_1 + 0x3c) = fVar1;
  *(float *)(param_1 + 0xc) = fVar1 + *(float *)(param_1 + 0x18);
  return;
}


