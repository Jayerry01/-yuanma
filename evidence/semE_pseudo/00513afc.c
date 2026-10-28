undefined4 FUN_00513afc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  bool bVar2;
  
  InterlockedIncrement((LONG *)&DAT_007f1d4c);
  bVar2 = DAT_007f1d48 != 0;
  if (bVar2) {
    InterlockedDecrement((LONG *)&DAT_007f1d4c);
    FUN_0050dd18(0x13);
  }
  uVar1 = FUN_00513b59(param_1,param_2,param_3);
  if (bVar2) {
    FUN_0050dd79(0x13);
  }
  else {
    InterlockedDecrement((LONG *)&DAT_007f1d4c);
  }
  return uVar1;
}


