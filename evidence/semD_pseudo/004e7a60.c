void FUN_004e7a60(undefined4 *param_1,int param_2,undefined4 param_3,int param_4,int param_5,
                 undefined4 *param_6,undefined4 *param_7,undefined4 param_8,int *param_9,
                 undefined4 *param_10,undefined4 *param_11,undefined4 *param_12,int param_13)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  param_2 = (param_4 - param_2) / 0xc +
            ((int)param_6 - (int)param_7) / 0xc + ((int)param_9 - param_5 >> 2) * 0x2a + -0x2a;
  if (0 < param_2) {
    do {
      puVar2 = param_6;
      if (param_6 == param_7) {
        param_9 = param_9 + -1;
        param_7 = (undefined4 *)*param_9;
        puVar2 = param_7 + 0x7e;
      }
      param_6 = puVar2 + -3;
      puVar1 = param_10;
      if (param_10 == param_11) {
        param_11 = *(undefined4 **)(param_13 + -4);
        param_13 = param_13 + -4;
        puVar1 = param_11 + 0x7e;
        param_12 = puVar1;
      }
      param_10 = puVar1 + -3;
      *param_10 = *param_6;
      puVar1[-2] = puVar2[-2];
      puVar1[-1] = puVar2[-1];
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  *param_1 = param_10;
  param_1[3] = param_13;
  param_1[1] = param_11;
  param_1[2] = param_12;
  return;
}


