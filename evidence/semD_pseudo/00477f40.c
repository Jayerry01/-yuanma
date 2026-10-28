void __thiscall FUN_00477f40(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float10 fVar5;
  float10 fVar6;
  
  fVar5 = (float10)fsin((float10)param_2);
  fVar6 = (float10)fcos((float10)param_2);
  fVar1 = (float)fVar6;
  fVar2 = *(float *)(param_1 + 0x10);
  fVar3 = *(float *)(param_1 + 0x14);
  *(float *)(param_1 + 0x10) =
       (float)(fVar5 * (float10)*(float *)(param_1 + 0x20) +
              (float10)fVar1 * (float10)*(float *)(param_1 + 0x10));
  *(float *)(param_1 + 0x14) =
       (float)(fVar5 * (float10)*(float *)(param_1 + 0x24) +
              (float10)fVar1 * (float10)*(float *)(param_1 + 0x14));
  fVar4 = *(float *)(param_1 + 0x28);
  *(float *)(param_1 + 0x28) =
       (float)((float10)fVar1 * (float10)*(float *)(param_1 + 0x28) -
              fVar5 * (float10)*(float *)(param_1 + 0x18));
  *(float *)(param_1 + 0x18) =
       (float)(fVar5 * (float10)fVar4 + (float10)fVar1 * (float10)*(float *)(param_1 + 0x18));
  fVar4 = *(float *)(param_1 + 0x2c);
  *(float *)(param_1 + 0x2c) =
       (float)((float10)fVar1 * (float10)*(float *)(param_1 + 0x2c) -
              fVar5 * (float10)*(float *)(param_1 + 0x1c));
  *(float *)(param_1 + 0x1c) =
       (float)(fVar5 * (float10)fVar4 + (float10)fVar1 * (float10)*(float *)(param_1 + 0x1c));
  *(float *)(param_1 + 0x20) =
       (float)(fVar6 * (float10)*(float *)(param_1 + 0x20) - fVar5 * (float10)fVar2);
  *(float *)(param_1 + 0x24) =
       (float)((float10)fVar1 * (float10)*(float *)(param_1 + 0x24) - fVar5 * (float10)fVar3);
  return;
}


