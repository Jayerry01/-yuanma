void __fastcall FUN_005603f0(int param_1)

{
  float local_c;
  float local_8;
  float local_4;
  
  local_c = (*(float *)(param_1 + 0x48) + *(float *)(param_1 + 0x54)) * 0.5;
  local_8 = (*(float *)(param_1 + 0x4c) + *(float *)(param_1 + 0x58)) * 0.5;
  local_4 = (*(float *)(param_1 + 0x50) + *(float *)(param_1 + 0x5c)) * 0.5;
  *(float *)(param_1 + 0x60) = *(float *)(param_1 + 0x54) - local_c;
  *(float *)(param_1 + 100) = *(float *)(param_1 + 0x58) - local_8;
  *(float *)(param_1 + 0x68) = *(float *)(param_1 + 0x5c) - local_4;
  FUN_00477200();
  FUN_00477b90(3,&local_c);
  return;
}


