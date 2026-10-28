undefined4 __thiscall FUN_00469840(int param_1,float param_2)

{
  if ((param_2 < 0.0) && (1.0 < param_2)) {
    return 0;
  }
  if (*(int *)(param_1 + 0x38) == 2) {
    FUN_00469f50(*(undefined4 *)(param_1 + 0x10),
                 (*(float *)(param_1 + 0x1c) - *(float *)(param_1 + 0x18)) * param_2 +
                 *(float *)(param_1 + 0x14));
    return 1;
  }
  FUN_00469f50((*(float *)(param_1 + 0x18) - *(float *)(param_1 + 0x1c)) * param_2 +
               *(float *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14));
  return 1;
}


