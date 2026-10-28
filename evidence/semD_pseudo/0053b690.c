undefined1 FUN_0053b690(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 local_238 [18];
  undefined1 local_1f0;
  undefined1 local_1ef;
  undefined *local_88 [2];
  code *local_80;
  
  if (DAT_0072329c == 0) {
    FUN_00530d00(0x506);
    return 0;
  }
  local_238[0] = FUN_0053e110(local_88);
  local_88[0] = &DAT_0053b760;
  local_80 = FUN_004e8500;
  iVar2 = __setjmp3(&DAT_0072c220,0);
  uVar1 = 0;
  if (iVar2 == 0) {
    FUN_0053dca0(local_238,0x3e,0x1b0);
    local_1ef = 1;
    local_1f0 = 1;
    FUN_0053b570(local_238);
    FUN_0053dd90(local_238,1);
    uVar1 = FUN_0053b790(local_238);
    FUN_0053e050(local_238);
    thunk_FUN_0053e300(local_238);
  }
  return uVar1;
}


