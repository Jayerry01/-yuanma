void FUN_00475220(float *param_1,undefined4 param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  int iVar7;
  float local_c;
  float local_8;
  float local_4;
  
  fVar1 = *param_1;
  local_8 = param_1[1] + param_1[1];
  fVar2 = param_1[2];
  *param_3 = *param_1;
  fVar2 = fVar2 + fVar2;
  param_3[1] = param_1[1];
  param_3[2] = param_1[2];
  pfVar6 = param_3 + 3;
  fVar3 = -*param_3;
  *param_3 = fVar3;
  fVar4 = -param_3[1];
  param_3[1] = fVar4;
  fVar5 = -param_3[2];
  param_3[2] = fVar5;
  *pfVar6 = fVar3 + fVar1 + fVar1;
  param_3[4] = fVar4;
  param_3[5] = fVar5;
  param_3[6] = *pfVar6;
  param_3[7] = param_3[4];
  param_3[8] = fVar2 + param_3[5];
  param_3[9] = fVar3;
  param_3[10] = fVar4;
  param_3[0xb] = fVar5 + fVar2;
  param_3[0xc] = fVar3;
  param_3[0xd] = fVar4 + local_8;
  param_3[0xe] = fVar5;
  param_3[0xf] = *pfVar6;
  param_3[0x10] = local_8 + param_3[4];
  param_3[0x11] = param_3[5];
  iVar7 = 8;
  param_3[0x12] = param_3[6];
  param_3[0x13] = local_8 + param_3[7];
  param_3[0x14] = param_3[8];
  local_c = param_3[9];
  local_8 = local_8 + param_3[10];
  local_4 = param_3[0xb];
  param_3[0x15] = local_c;
  param_3[0x16] = local_8;
  param_3[0x17] = local_4;
  do {
    pfVar6 = (float *)FUN_00476e80(&local_c,param_3,param_2);
    *param_3 = *pfVar6;
    iVar7 = iVar7 + -1;
    param_3[1] = pfVar6[1];
    param_3[2] = pfVar6[2];
    param_3 = param_3 + 3;
  } while (iVar7 != 0);
  return;
}


