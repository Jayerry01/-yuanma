void FUN_004345a0(int *param_1)

{
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  local_10 = param_1[0xb] * param_1[5] + param_1[1];
  local_8 = (param_1[3] - param_1[1]) + local_10;
  local_c = param_1[10] * param_1[6] + param_1[2];
  local_4 = (param_1[4] - param_1[2]) + local_c;
  FUN_00433c80(*(undefined4 *)(*param_1 + param_1[0xc] * 4),&local_10);
  return;
}


