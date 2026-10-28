void FUN_00531770(void)

{
  if (DAT_007dc850 != &LAB_00531650) {
    DAT_007dc830 = 0;
    DAT_007dc864 = 0;
    if (DAT_007232dc != 0) {
      FUN_00530db0(DAT_007232dc);
      DAT_007232dc = 0;
    }
    DAT_007232d8 = 0;
    (*DAT_007dc854)(DAT_007dc85c + DAT_007dc838,0);
  }
  return;
}


