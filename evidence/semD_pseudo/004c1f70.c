int __thiscall FUN_004c1f70(int param_1,int param_2,int param_3)

{
  float fVar1;
  uint3 uVar2;
  float10 fVar3;
  
  fVar1 = ABS(*(float *)(*(int *)(param_1 + 0x4fc) + param_3 * 0x24 + 0xc) -
              *(float *)(*(int *)(param_1 + 0x4fc) + param_2 * 0x24 + 0xc));
  if (fVar1 >= 75.0 && (fVar1 == 75.0) == 0) {
    return (uint)(byte)(fVar1 < 75.0 | (byte)((ushort)((ushort)(fVar1 == 75.0) << 0xe) >> 8)) << 8;
  }
  fVar3 = (float10)FUN_0047ecf0();
  uVar2 = (uint3)(fVar3 < (float10)120.0);
  if ((float10)120.0 < fVar3) {
    return (uint)uVar2 << 8;
  }
  return CONCAT31(uVar2,1);
}


