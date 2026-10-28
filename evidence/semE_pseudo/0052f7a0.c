void FUN_0052f7a0(int param_1,uint param_2)

{
  if (param_1 == 0x700) {
    if ((0x700 < param_2) && (param_2 < 0x706)) {
      _DAT_005cfe1c = param_2;
      return;
    }
  }
  else if (((param_1 == 0x2600) && (0x2600 < param_2)) && (param_2 < 0x260a)) {
    DAT_005cfe18 = param_2;
    return;
  }
  FUN_00530d00(0x501);
  return;
}


