void __thiscall FUN_0055a180(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  
  *(int *)(param_1 + 0x1678) = param_2;
  if (param_2 != 0) {
    if (*(float *)(param_2 + 0x1f8) <= *(float *)(param_2 + 0x1fc)) {
      fVar1 = *(float *)(param_2 + 0x1fc);
      fVar2 = *(float *)(param_2 + 0x1f8);
      *(undefined4 *)(param_1 + 0xaac) = *(undefined4 *)(param_1 + 0x3c);
      *(float *)(param_1 + 0xaa8) = (*(float *)(param_1 + 0x38) / fVar1) * fVar2;
    }
    else {
      *(undefined4 *)(param_1 + 0xaa8) = *(undefined4 *)(param_1 + 0x38);
      *(float *)(param_1 + 0xaac) =
           (*(float *)(param_1 + 0x3c) / *(float *)(param_2 + 0x1f8)) * *(float *)(param_2 + 0x1fc);
    }
    FUN_0047c3a0(*(undefined4 *)(param_1 + 0xaa8),*(undefined4 *)(param_1 + 0xaac));
    FUN_0047dd50(0x3e4ccccd,0x3e4ccccd,0x3e4ccccd,0x3f000000);
    *(float *)(param_1 + 0xab0) =
         *(float *)(param_1 + 0xaa8) / *(float *)(*(int *)(param_1 + 0x1678) + 0x1f8);
    *(float *)(param_1 + 0xab4) =
         *(float *)(param_1 + 0xaac) / *(float *)(*(int *)(param_1 + 0x1678) + 0x1fc);
    *(float *)(param_1 + 0xaa0) = (*(float *)(param_1 + 0x40) - 2.0) - *(float *)(param_1 + 0xaa8);
    *(float *)(param_1 + 0xaa4) = (*(float *)(param_1 + 0x44) - 2.0) - *(float *)(param_1 + 0xaac);
  }
  return;
}


