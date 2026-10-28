undefined4 __thiscall FUN_004fc610(int param_1,float *param_2)

{
  if (0.0 < (*param_2 - *(float *)(param_1 + 0x18)) * *(float *)(param_1 + 0x24) +
            (param_2[1] - *(float *)(param_1 + 0x1c)) * *(float *)(param_1 + 0x28) +
            (param_2[2] - *(float *)(param_1 + 0x20)) * *(float *)(param_1 + 0x2c)) {
    return 1;
  }
  return 0;
}


