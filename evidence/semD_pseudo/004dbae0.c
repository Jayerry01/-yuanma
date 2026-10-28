void __fastcall FUN_004dbae0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_005a2778;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_005aa970;
  param_1[-0x197] = &PTR_LAB_005aa9f8;
  local_4 = 1;
  FUN_004dbb60(0xf);
  local_4 = 0xffffffff;
  *(undefined ***)(-(uint)(param_1 != (undefined4 *)0x65c) & (uint)param_1) = &PTR_LAB_005a9a98;
  FUN_0055beb0();
  ExceptionList = local_c;
  return;
}


