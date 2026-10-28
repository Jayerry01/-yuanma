int FUN_00415d80(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  puVar2 = (undefined4 *)(DAT_005d5a0c + 0x484);
  do {
    if (*(int *)*puVar2 == 0) {
      **(undefined4 **)(DAT_005d5a0c + 0x484 + iVar1 * 4) = 1;
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar1 < 0x40);
  return -1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
