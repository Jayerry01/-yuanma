uint FUN_00484590(int param_1)

{
  uint uVar1;
  int extraout_EDX;
  
  uVar1 = DAT_00665904 & 0xff;
  if (param_1 <= (int)uVar1) {
LAB_00484634:
    return *(uint *)(&DAT_005c8c90 + param_1 * 4) & DAT_006658f8;
  }
  do {
    if (DAT_006658ec < 1) {
      if (DAT_006658fc != 0) {
        if (0 < DAT_006658fc) {
          DAT_006658fc = DAT_006658fc + -1;
          return 0xffffffff;
        }
        DAT_006658fc = DAT_006658fc + 1;
        goto LAB_00484634;
      }
      FUN_00484460();
      param_1 = extraout_EDX;
    }
    else {
      DAT_006658f8 = DAT_006658f8 | (uint)*DAT_00665900 << ((byte)uVar1 & 0x1f);
      DAT_00665900 = DAT_00665900 + 1;
      DAT_006658ec = DAT_006658ec + -1;
      DAT_00665904 = CONCAT31(DAT_00665904._1_3_,(char)DAT_00665904 + '\b');
    }
    uVar1 = DAT_00665904 & 0xff;
    if (param_1 <= (int)uVar1) {
      return *(uint *)(&DAT_005c8c90 + param_1 * 4) & DAT_006658f8;
    }
  } while( true );
}


