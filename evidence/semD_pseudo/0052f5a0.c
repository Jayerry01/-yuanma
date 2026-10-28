uint FUN_0052f5a0(uint param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_00530d00(0x509);
    return uVar1 & 0xffffff00;
  }
  if (param_1 == 0) {
    param_1 = FUN_0052f4b0(param_2,param_3);
  }
  if (param_1 < 0x426) {
    if (param_1 == 0x425) {
      uVar1 = FUN_0053b550(param_2,param_3);
      return uVar1;
    }
    uVar1 = 0;
    if (param_1 == 0) goto LAB_0052f614;
    if (param_1 == 0x420) {
      uVar1 = FUN_0053a370(param_2,param_3);
      return uVar1;
    }
  }
  else if (param_1 == 0x42d) {
    uVar1 = FUN_0053b9d0(param_2,param_3);
    return uVar1;
  }
  uVar1 = FUN_00530d00(0x501);
LAB_0052f614:
  return uVar1 & 0xffffff00;
}


