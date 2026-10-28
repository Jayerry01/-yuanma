void FUN_0052c6c0(void)

{
  char cVar1;
  undefined4 uVar2;
  
  if (((DAT_00723270 == 0) || (DAT_00723264 < 2)) && (cVar1 = FUN_0052c520(), cVar1 == '\0')) {
    return;
  }
  if (DAT_00723268 < 2) {
    DAT_00723268 = 2;
  }
  DAT_0072326c = 1;
  DAT_005cfddc = 1;
  if (*(int *)(DAT_00723270 + 4) == 0) {
    uVar2 = FUN_0052c740(1,1,1,1,1);
    *(undefined4 *)(DAT_00723270 + 4) = uVar2;
  }
  DAT_0072329c = *(undefined4 *)(DAT_00723270 + 4);
  return;
}


