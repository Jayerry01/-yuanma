void FUN_00431180(float *param_1,float *param_2,float *param_3)

{
  int iVar1;
  float *pfVar2;
  float local_30 [4];
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_30[0] = param_3[6] * param_2[2] + *param_2 * *param_3 + param_2[1] * param_3[3];
  local_30[1] = param_3[1] * *param_2 + param_2[1] * param_3[4] + param_3[7] * param_2[2];
  local_30[2] = *param_2 * param_3[2] + param_2[1] * param_3[5] + param_3[8] * param_2[2];
  local_30[3] = param_2[4] * param_3[3] + param_2[3] * *param_3 + param_2[5] * param_3[6];
  local_20 = param_2[3] * param_3[1] + param_2[4] * param_3[4] + param_2[5] * param_3[7];
  local_1c = param_3[5] * param_2[4] + param_3[8] * param_2[5] + param_2[3] * param_3[2];
  local_18 = param_2[7] * param_3[3] + param_2[6] * *param_3 + param_2[8] * param_3[6];
  local_14 = param_2[6] * param_3[1] + param_2[7] * param_3[4] + param_2[8] * param_3[7];
  local_10 = param_3[5] * param_2[7] + param_3[8] * param_2[8] + param_2[6] * param_3[2];
  local_c = param_2[10] * param_3[3] + param_2[9] * *param_3 + param_2[0xb] * param_3[6] +
            param_3[9];
  local_8 = param_2[9] * param_3[1] + param_2[10] * param_3[4] + param_2[0xb] * param_3[7] +
            param_3[10];
  local_4 = param_3[5] * param_2[10] + param_3[8] * param_2[0xb] + param_2[9] * param_3[2] +
            param_3[0xb];
  pfVar2 = local_30;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


