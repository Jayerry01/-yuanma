void FUN_004e7b40(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4,
                 int param_5,int param_6,int param_7,undefined4 param_8,int param_9,
                 undefined4 *param_10,undefined4 *param_11,undefined4 *param_12,int param_13)

{
  undefined4 *puVar1;
  
  param_6 = ((int)param_4 - (int)param_2) / 0xc +
            (param_6 - param_7) / 0xc + (param_9 - param_5 >> 2) * 0x2a + -0x2a;
  if (0 < param_6) {
    do {
      puVar1 = param_2 + 3;
      *param_10 = *param_2;
      param_10[1] = param_2[1];
      param_10[2] = param_2[2];
      if (puVar1 == param_4) {
        puVar1 = *(undefined4 **)(param_5 + 4);
        param_5 = param_5 + 4;
        param_4 = puVar1 + 0x7e;
      }
      param_10 = param_10 + 3;
      if (param_10 == param_12) {
        param_10 = *(undefined4 **)(param_13 + 4);
        param_13 = param_13 + 4;
        param_12 = param_10 + 0x7e;
        param_11 = param_10;
      }
      param_6 = param_6 + -1;
      param_2 = puVar1;
    } while (param_6 != 0);
  }
  *param_1 = param_10;
  param_1[1] = param_11;
  param_1[2] = param_12;
  param_1[3] = param_13;
  return;
}


