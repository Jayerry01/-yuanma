undefined4 FUN_00505160(int param_1)

{
  char *pcVar1;
  
  if (DAT_006675dc == '\0') {
    if (param_1 == 1) {
      pcVar1 = s_DirectSound3D_005ca5ac;
    }
    else {
      pcVar1 = &DAT_005ca5a0;
    }
    DAT_006675e0 = FUN_005273f0(pcVar1);
    if (DAT_006675e0 == 0) {
      return 0;
    }
    DAT_006675e4 = FUN_00525820(DAT_006675e0,0);
    if (DAT_006675e4 == 0) {
      return 0;
    }
    FUN_005259e0(DAT_006675e4);
    FUN_00525570();
    DAT_00667594 = 0x3f800000;
    DAT_006675d8 = 0x47c35000;
    _DAT_006675a0 = 0;
    _DAT_0066759c = 0;
    _DAT_00667598 = 0;
    DAT_00667584 = 200;
    DAT_0066757c = 0;
    DAT_00667580 = 0;
  }
  DAT_006675dc = 1;
  return 1;
}


