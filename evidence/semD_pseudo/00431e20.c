void FUN_00431e20(int param_1,int param_2,float param_3)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float10 extraout_ST1;
  int local_c [3];
  
  local_c[0] = 1;
  local_c[1] = 2;
  fcos((float10)param_3 * (float10)0.01745328);
  local_c[2] = 0;
  iVar1 = local_c[param_2];
  iVar2 = local_c[iVar1];
  fsin((float10)(float)((float10)param_3 * (float10)0.01745328));
  fVar3 = (float10)FUN_00430c40(param_1);
  *(float *)(param_1 + iVar1 * 0x14) = (float)extraout_ST1;
  *(float *)(param_1 + iVar2 * 0x14) = (float)extraout_ST1;
  *(float *)(param_1 + (iVar2 + iVar1 * 4) * 4) = (float)fVar3;
  *(float *)(param_1 + (iVar1 + iVar2 * 4) * 4) = (float)-fVar3;
  return;
}


