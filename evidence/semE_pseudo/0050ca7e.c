undefined4 FUN_0050ca7e(int param_1)

{
  int iVar1;
  
  DAT_007f1d6c = HeapCreate((uint)(param_1 == 0),0x1000,0);
  if (DAT_007f1d6c != (HANDLE)0x0) {
    DAT_007f1d70 = FUN_0050c936();
    if (DAT_007f1d70 == 3) {
      iVar1 = FUN_0050cadb(0x3f8);
    }
    else {
      if (DAT_007f1d70 != 2) {
        return 1;
      }
      iVar1 = FUN_0050d622();
    }
    if (iVar1 != 0) {
      return 1;
    }
    HeapDestroy(DAT_007f1d6c);
  }
  return 0;
}


