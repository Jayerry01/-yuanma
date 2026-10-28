void FUN_00403ee0(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(DAT_005d5a0c + 0x45c)) {
    do {
      FUN_00412150(iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(DAT_005d5a0c + 0x45c));
  }
  return;
}


