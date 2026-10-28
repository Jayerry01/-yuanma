uint FUN_0051217d(uint param_1)

{
  uint uVar1;
  
  if (DAT_005ca8ec < 2) {
    uVar1 = (byte)PTR_DAT_005ca6e0[param_1 * 2] & 4;
  }
  else {
    uVar1 = FUN_0050a85c(param_1,4);
  }
  if (uVar1 == 0) {
    param_1 = (param_1 & 0xffffffdf) - 7;
  }
  return param_1;
}


