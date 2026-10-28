uint FUN_00475c50(uint param_1,uint param_2,uint param_3,int param_4)

{
  if ((int)param_1 < 0) {
    param_1 = 0;
  }
  else if (0xff < (int)param_1) {
    param_1 = 0xff;
  }
  if ((int)param_2 < 0) {
    param_2 = 0;
  }
  else if (0xff < (int)param_2) {
    param_2 = 0xff;
  }
  if ((int)param_3 < 0) {
    param_3 = 0;
  }
  else if (0xff < (int)param_3) {
    param_3 = 0xff;
  }
  if (param_4 < 0) {
    param_4 = 0;
  }
  else if (0xff < param_4) {
    param_4 = 0xff;
  }
  if (DAT_005e03a0 != 0) {
    return ((param_4 << 8 | param_1) << 8 | param_2) << 8 | param_3;
  }
  return ((param_4 << 8 | param_3) << 8 | param_2) << 8 | param_1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
