float * __thiscall FUN_0058f8a0(int param_1,float *param_2,float param_3,int param_4)

{
  float fVar1;
  double local_20;
  float local_14;
  float local_10;
  float local_c;
  
  local_14 = 0.0;
  local_10 = 0.0;
  local_c = 1.0;
  fVar1 = param_3 * *(float *)(param_4 + 0x20) + *(float *)(param_4 + 0x18);
  if (*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x1ec) + 0xe4) < 3) {
    FUN_0058f0f0();
    return param_2;
  }
  FUN_0059546e(*(undefined4 *)(param_1 + 0x8c),*(undefined4 *)(param_1 + 0xa4),
               *(undefined4 *)(param_1 + 0xa8),(double)fVar1,*(undefined4 *)(param_1 + 0x98),
               &local_20);
  local_14 = (float)local_20;
  FUN_0059546e(*(undefined4 *)(param_1 + 0x90),*(undefined4 *)(param_1 + 0xa4),
               *(undefined4 *)(param_1 + 0xac),(double)fVar1,*(undefined4 *)(param_1 + 0x9c),
               &local_20);
  local_10 = (float)local_20;
  FUN_0059546e(*(undefined4 *)(param_1 + 0x94),*(undefined4 *)(param_1 + 0xa4),
               *(undefined4 *)(param_1 + 0xb0),(double)fVar1,*(undefined4 *)(param_1 + 0xa0),
               &local_20);
  local_c = (float)local_20;
  FUN_0047ec40();
  *param_2 = local_14;
  param_2[1] = local_10;
  param_2[2] = local_c;
  return param_2;
}


