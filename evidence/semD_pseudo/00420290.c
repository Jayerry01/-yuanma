void FUN_00420290(int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  param_3 = param_3 * 2;
  iVar2 = param_3 + param_4 * -2;
  iVar1 = param_3 - param_4;
  if (DAT_007eabe0 == 0x10) {
    param_1 = param_1 * 2;
    *(short *)(DAT_007e28b0 * param_2 + param_1 + DAT_007e2c88) = (short)param_6;
    if (param_4 != 0) {
      do {
        iVar3 = param_3;
        if (-1 < iVar1) {
          param_1 = param_1 + param_5 * 2;
          iVar3 = iVar2;
        }
        iVar1 = iVar1 + iVar3;
        param_2 = param_2 + 1;
        param_4 = param_4 + -1;
        *(short *)(DAT_007e28b0 * param_2 + param_1 + DAT_007e2c88) = (short)param_6;
      } while (param_4 != 0);
      return;
    }
  }
  else {
    param_1 = param_1 * 4;
    *(undefined4 *)(DAT_007e28b0 * param_2 + param_1 + DAT_007e2c88) = param_6;
    if (param_4 != 0) {
      do {
        iVar3 = param_3;
        if (-1 < iVar1) {
          param_1 = param_1 + param_5 * 4;
          iVar3 = iVar2;
        }
        iVar1 = iVar1 + iVar3;
        param_2 = param_2 + 1;
        param_4 = param_4 + -1;
        *(undefined4 *)(DAT_007e28b0 * param_2 + param_1 + DAT_007e2c88) = param_6;
      } while (param_4 != 0);
    }
  }
  return;
}


