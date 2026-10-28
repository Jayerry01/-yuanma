undefined4 FUN_0050893e(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  
  FUN_0050c7ef();
  uVar1 = FUN_0050c81b(DAT_007f1d80);
  if (uVar1 < (uint)((int)DAT_007f1d7c + (4 - DAT_007f1d80))) {
    iVar2 = FUN_0050c81b(DAT_007f1d80);
    iVar2 = FUN_005099a7(DAT_007f1d80,iVar2 + 0x10);
    if (iVar2 == 0) {
      param_1 = 0;
      goto LAB_005089b3;
    }
    DAT_007f1d7c = (undefined4 *)(iVar2 + ((int)DAT_007f1d7c - DAT_007f1d80 >> 2) * 4);
    DAT_007f1d80 = iVar2;
  }
  *DAT_007f1d7c = param_1;
  DAT_007f1d7c = DAT_007f1d7c + 1;
LAB_005089b3:
  FUN_0050c7f8();
  return param_1;
}


