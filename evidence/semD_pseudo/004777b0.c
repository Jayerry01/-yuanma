float10 FUN_004777b0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                    int param_7)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  
  iVar1 = param_6 + param_3 * 4;
  pfVar2 = (float *)(param_1 + (param_7 + param_4 * 4) * 4);
  pfVar3 = (float *)(param_1 + (param_6 + param_4 * 4) * 4);
  pfVar4 = (float *)(param_1 + (param_7 + param_3 * 4) * 4);
  pfVar5 = (float *)(param_1 + (param_5 + param_3 * 4) * 4);
  pfVar6 = (float *)(param_1 + (param_5 + param_4 * 4) * 4);
  return ((float10)*pfVar3 * (float10)*pfVar5 -
         (float10)*pfVar6 * (float10)*(float *)(param_1 + iVar1 * 4)) *
         (float10)*(float *)(param_1 + (param_7 + param_2 * 4) * 4) +
         (((float10)*(float *)(param_1 + iVar1 * 4) * (float10)*pfVar2 -
          (float10)*pfVar4 * (float10)*pfVar3) *
          (float10)*(float *)(param_1 + (param_5 + param_2 * 4) * 4) -
         ((float10)*pfVar2 * (float10)*pfVar5 - (float10)*pfVar6 * (float10)*pfVar4) *
         (float10)*(float *)(param_1 + (param_6 + param_2 * 4) * 4));
}


