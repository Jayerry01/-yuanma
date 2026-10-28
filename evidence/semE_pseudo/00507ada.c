void FUN_00507ada(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_0050b6a8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_005ac378;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((int)extraout_ECX[0xc] < 0) {
    FUN_00508015(extraout_ECX + 0xd);
  }
  if (extraout_ECX[0x14] == 0) {
    FUN_00507d0b();
  }
  else {
    FUN_00507b31();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0050842b();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}


