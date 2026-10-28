void FUN_00429b80(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  
  if (DAT_005d5b04 != (int *)0x0) {
    DAT_005d5b04[4] = param_4;
    DAT_005d5b04[5] = param_5;
    if ((((0 < param_1) && (0 < param_2)) && (0 < param_3)) && ((0 < param_4 && (0 < param_5)))) {
      if (DAT_005d5b04[1] != 0) {
        FUN_005089fd(DAT_005d5b04);
        DAT_005d5b04[1] = 0;
      }
      if (*DAT_005d5b04 != 0) {
        FUN_00434ac0(*DAT_005d5b04);
      }
      FUN_00434600();
      FUN_00434690(0,0,param_1,param_2,param_3,param_4,param_5,DAT_005d5b04[0x12]);
      iVar1 = FUN_00434ab0();
      *DAT_005d5b04 = iVar1;
    }
  }
  return;
}


