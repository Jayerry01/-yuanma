void FUN_004b95a0(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  DAT_0066619c = param_1;
  iVar1 = 0;
  do {
    if (DAT_0066619c == 0) {
      puVar2 = (undefined1 *)0x0;
    }
    else {
      puVar2 = &LAB_004b9520;
    }
    FUN_0040e970(iVar1,puVar2,0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x100);
  return;
}


