void __fastcall FUN_00478c90(undefined4 param_1)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059d15b;
  local_c = ExceptionList;
  _DAT_005ef680 = 0;
  ExceptionList = &local_c;
  FUN_00478e70(DAT_005e04a0,param_1);
  if (DAT_005e03a0 == 1) {
    PTR_FUN_005c809c = &LAB_00480410;
    PTR_FUN_005c80a0 = FUN_0058e140;
    PTR_FUN_005c80a4 = FUN_00480600;
    PTR_FUN_005c80ac = &LAB_00480450;
    PTR_FUN_005c80b0 = FUN_004803d0;
    PTR_FUN_005c80b4 = &LAB_004800e0;
    PTR_FUN_005c80a8 = FUN_004e8500;
    FUN_00480240();
  }
  else if (DAT_005e03a0 == 2) {
    PTR_FUN_005c809c = &LAB_0047dfd0;
    PTR_FUN_005c80a0 = FUN_0058e140;
    PTR_FUN_005c80a4 = &LAB_0047dfe0;
    PTR_FUN_005c80ac = &LAB_0047dfa0;
    PTR_FUN_005c80b0 = &LAB_0047dfc0;
    PTR_FUN_005c80b4 = &LAB_0047df90;
    PTR_FUN_005c80b8 = &LAB_0047dff0;
    PTR_FUN_005c80a8 = FUN_0047e010;
    FUN_0047df50();
  }
  pvVar1 = operator_new(0xc0);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    DAT_005ef684 = 0;
  }
  else {
    DAT_005ef684 = FUN_0047f190(pvVar1);
  }
  DAT_005c8168 = DAT_005e03e4;
  DAT_005c816c = DAT_005e03e8;
  DAT_00628534 = DAT_005e03ec;
  ExceptionList = local_c;
  return;
}


