int FUN_0050a722(int param_1)

{
  bool bVar1;
  
  if (DAT_00667844 == 0) {
    if ((0x40 < param_1) && (param_1 < 0x5b)) {
      return param_1 + 0x20;
    }
  }
  else {
    InterlockedIncrement((LONG *)&DAT_007f1d4c);
    bVar1 = DAT_007f1d48 != 0;
    if (bVar1) {
      InterlockedDecrement((LONG *)&DAT_007f1d4c);
      FUN_0050dd18(0x13);
    }
    param_1 = FUN_0050a791(param_1);
    if (bVar1) {
      FUN_0050dd79(0x13);
    }
    else {
      InterlockedDecrement((LONG *)&DAT_007f1d4c);
    }
  }
  return param_1;
}


