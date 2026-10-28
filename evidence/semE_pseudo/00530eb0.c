undefined4 FUN_00530eb0(uint param_1)

{
  bool bVar1;
  
  if (param_1 < 0x190a) {
    if ((param_1 == 0x1909) || (param_1 == 0x1900)) {
      return 1;
    }
    if (param_1 == 0x1907) {
      return 3;
    }
    bVar1 = param_1 != 0x1908;
  }
  else {
    if (param_1 == 0x190a) {
      return 2;
    }
    if (param_1 == 0x80e0) {
      return 3;
    }
    bVar1 = param_1 != 0x80e1;
  }
  if (bVar1) {
    return 0;
  }
  return 4;
}


