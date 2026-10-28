void FUN_00511076(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_007f1c40;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_007f1b20 = 0;
  DAT_007f1b3c = 0;
  DAT_007f1d44 = 0;
  DAT_007f1b30 = 0;
  DAT_007f1b34 = 0;
  DAT_007f1b38 = 0;
  return;
}


