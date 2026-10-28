float10 __thiscall FUN_0047ecc0(float *param_1,float *param_2)

{
  return SQRT(((float10)*param_2 - (float10)*param_1) * ((float10)*param_2 - (float10)*param_1) +
              ((float10)param_2[1] - (float10)param_1[1]) *
              ((float10)param_2[1] - (float10)param_1[1]) +
              ((float10)param_2[2] - (float10)param_1[2]) *
              ((float10)param_2[2] - (float10)param_1[2]));
}


