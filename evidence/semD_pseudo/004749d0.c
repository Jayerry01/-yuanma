void FUN_004749d0(float *param_1,int param_2,float *param_3,float *param_4)

{
  param_3[2] = 1e+10;
  param_3[1] = 1e+10;
  *param_3 = 1e+10;
  param_4[2] = -1e+10;
  param_4[1] = -1e+10;
  *param_4 = -1e+10;
  if (0 < param_2) {
    do {
      if (*param_1 < *param_3) {
        *param_3 = *param_1;
      }
      if (param_1[1] < param_3[1]) {
        param_3[1] = param_1[1];
      }
      if (param_1[2] < param_3[2]) {
        param_3[2] = param_1[2];
      }
      if (*param_4 < *param_1) {
        *param_4 = *param_1;
      }
      if (param_4[1] < param_1[1]) {
        param_4[1] = param_1[1];
      }
      if (param_4[2] < param_1[2]) {
        param_4[2] = param_1[2];
      }
      param_1 = param_1 + 3;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


