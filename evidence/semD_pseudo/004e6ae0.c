void FUN_004e6ae0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4,
                 int param_5,int param_6,int param_7,undefined4 param_8,int param_9,
                 undefined4 param_10,undefined4 param_11)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  undefined4 *local_4;
  
  FUN_004e6050(&param_10);
  iVar1 = (param_6 - param_7) / 0xc +
          ((int)param_4 - (int)param_2) / 0xc + (param_9 - param_5 >> 2) * 0x2a + -0x2a;
  if (0 < iVar1) {
    do {
      puVar2 = param_2 + 3;
      *local_10 = *param_2;
      local_10[1] = param_2[1];
      local_10[2] = param_2[2];
      if (puVar2 == param_4) {
        puVar2 = *(undefined4 **)(param_5 + 4);
        param_5 = param_5 + 4;
        param_4 = puVar2 + 0x7e;
      }
      local_10 = local_10 + 3;
      if (local_10 == local_8) {
        local_4 = local_4 + 1;
        local_10 = (undefined4 *)*local_4;
        local_8 = local_10 + 0x7e;
        local_c = local_10;
      }
      iVar1 = iVar1 + -1;
      param_2 = puVar2;
    } while (iVar1 != 0);
  }
  *param_1 = local_10;
  param_1[1] = local_c;
  param_1[2] = local_8;
  param_1[3] = local_4;
  return;
}


