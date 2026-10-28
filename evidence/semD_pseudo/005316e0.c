undefined4 FUN_005316e0(int param_1)

{
  if (DAT_007dc850 != (code *)&LAB_00531650) {
    if (DAT_007232dc != 0) {
      FUN_00530db0(DAT_007232dc);
    }
    if (param_1 == 0) {
      param_1 = 1;
    }
    DAT_007232dc = FUN_00530d80(param_1);
    if (DAT_007232dc == 0) {
      return 0;
    }
    DAT_007232d8 = 0;
    DAT_007dc838 = (*DAT_007dc860)();
    DAT_007dc830 = (*DAT_007dc850)(DAT_007232dc,1,param_1);
    if (DAT_007dc830 != param_1) {
      FUN_00530d50();
    }
    DAT_007dc864 = 0;
    DAT_007232d8 = 1;
    DAT_007dc85c = 0;
  }
  return 1;
}


