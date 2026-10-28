void FUN_0052c070(uint param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  if ((DAT_00723270 != 0) && (DAT_00723264 != 0)) goto joined_r0x0052c097;
  cVar1 = FUN_0052c520();
  while( true ) {
    if (cVar1 == '\0') {
      return;
    }
joined_r0x0052c097:
    if (param_1 < DAT_00723264) break;
    cVar1 = FUN_0052c520();
  }
  if (*(int *)(DAT_00723270 + param_1 * 4) == 0) {
    uVar2 = FUN_0052c740(1,1,1,1,1);
    *(undefined4 *)(DAT_00723270 + param_1 * 4) = uVar2;
    if (DAT_00723268 <= param_1) {
      DAT_00723268 = param_1 + 1;
    }
  }
  DAT_005cfddc = 1;
  DAT_0072326c = param_1;
  DAT_0072329c = *(undefined4 *)(DAT_00723270 + param_1 * 4);
  return;
}


