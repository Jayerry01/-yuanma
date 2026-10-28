void FUN_00525640(undefined4 *param_1)

{
  int iVar1;
  timecaps_tag local_8;
  
  if (param_1 != (undefined4 *)0x0) {
    FUN_00525610(param_1);
    iVar1 = param_1[0x18];
    param_1[0xc] = 0x3f800000;
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    param_1[8] = 0xbf800000;
    param_1[9] = 0;
    param_1[10] = 0x3f800000;
    param_1[0xb] = 0;
    param_1[0x10] = 0;
    *(undefined1 *)(param_1 + 0x11) = 0;
    *(undefined1 *)((int)param_1 + 0x45) = 1;
    param_1[0x12] = *(undefined4 *)(iVar1 + 8);
    param_1[0x13] = *(undefined4 *)(iVar1 + 0xc);
    param_1[0x14] = *(undefined4 *)(iVar1 + 0x10);
    param_1[0x15] = 0xd002;
    param_1[0x16] = 0x3f800000;
    param_1[0x17] = 0x43aba666;
    param_1[0xd] = 0x7e;
    FUN_005260b0(param_1,2,0);
    DAT_0072c1f8 = 100;
    DAT_0072c218 = 0;
    timeGetDevCaps(&local_8,8);
    if (DAT_0072c1f8 < local_8.wPeriodMin) {
      DAT_0072c1f8 = local_8.wPeriodMin;
    }
    timeBeginPeriod(DAT_0072c1f8);
    FUN_00525620(param_1);
  }
  return;
}


