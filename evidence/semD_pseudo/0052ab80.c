void FUN_0052ab80(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00525980();
  FUN_00525610(iVar1);
  if (param_2 == (undefined4 *)0x0) {
    FUN_005255b0(0xa003);
    FUN_00525620(iVar1);
    return;
  }
  *param_2 = 0;
  if (param_1 == 0xc000) {
    uVar2 = __ftol();
    *param_2 = uVar2;
    FUN_00525620(iVar1);
    return;
  }
  if (param_1 == 0xc001) {
    uVar2 = __ftol();
    *param_2 = uVar2;
    FUN_00525620(iVar1);
    return;
  }
  if (param_1 != 0xd000) {
    FUN_005255b0(0xa002);
    FUN_00525620(iVar1);
    return;
  }
  *param_2 = *(undefined4 *)(iVar1 + 0x54);
  FUN_00525620(iVar1);
  return;
}



void RtlUnwind(PVOID TargetFrame,PVOID TargetIp,PEXCEPTION_RECORD ExceptionRecord,PVOID ReturnValue)

{
                    // WARNING: Could not recover jumptable at 0x0052af80. Too many branches
                    // WARNING: Treating indirect jump as call
  RtlUnwind(TargetFrame,TargetIp,ExceptionRecord,ReturnValue);
  return;
}


