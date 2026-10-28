void FUN_0041bd00(int param_1,short *param_2,int param_3,short param_4)

{
  if (0 < param_3) {
    param_1 = param_1 - (int)param_2;
    do {
      if (*param_2 != param_4) {
        *(short *)(param_1 + (int)param_2) = *param_2;
      }
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}


