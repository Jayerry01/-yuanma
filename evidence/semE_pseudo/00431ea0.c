float10 FUN_00431ea0(float *param_1,float *param_2,float *param_3)

{
  return ((float10)param_1[1] - (float10)param_2[1]) * (float10)*param_3 +
         ((float10)param_3[1] - (float10)param_1[1]) * (float10)*param_2 +
         ((float10)param_2[1] - (float10)param_3[1]) * (float10)*param_1;
}


