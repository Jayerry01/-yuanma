void FUN_0042a3f0(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_005c679c != 0) {
    iVar1 = *(int *)(DAT_005d5a0c + 0x6cc);
    *(undefined4 *)(DAT_005d5a0c + 0x6d0) = 0;
    *(undefined4 *)(DAT_005d5a0c + 0x6cc) = 0;
    while (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 0x5c);
      *(undefined4 *)(iVar1 + 0x5c) = 0;
      *(undefined4 *)(iVar1 + 0x58) = 0;
      FUN_0042a1a0(iVar1);
      iVar1 = iVar2;
    }
    DAT_005c679c = 0;
  }
  return;
}


