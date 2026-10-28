uint FUN_00429c30(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (DAT_005d5b04 == (int *)0x0) {
    return 0;
  }
  uVar1 = FUN_0042a110();
  if (uVar1 == 0) {
    return 0;
  }
  if (*DAT_005d5b04 == 0) {
    DAT_005d5b04[0xe] = 0;
  }
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0042a010(param_1);
  }
  FUN_0042a130(DAT_005d5b04);
  FUN_0042a500(DAT_005d5b04,uVar2);
  (&DAT_007ddf40)[uVar1] = DAT_005d5b04;
  DAT_005d5b04 = (int *)0x0;
  return uVar1 | 0x10000000;
}


