void FUN_0052c660(void)

{
  char cVar1;
  int iVar2;
  
  if (DAT_00723270 == (int *)0x0) {
    cVar1 = FUN_0052c520();
    if (cVar1 == '\0') {
      return;
    }
  }
  DAT_00723268 = 1;
  DAT_0072326c = 0;
  DAT_005cfddc = 1;
  if (*DAT_00723270 == 0) {
    iVar2 = FUN_0052c740(1,1,1,1,1);
    *DAT_00723270 = iVar2;
  }
  DAT_0072329c = *DAT_00723270;
  FUN_0052d980();
  return;
}


