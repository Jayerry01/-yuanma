undefined4 * __fastcall FUN_00555a50(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a4e5b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00553830();
  local_4 = 0;
  param_1[0x165] = 0;
  param_1[0x166] = 0;
  param_1[0x167] = 0;
  param_1[0x168] = 0;
  param_1[0x169] = 0;
  param_1[0x16a] = 0;
  param_1[0x16b] = 0;
  param_1[0x16c] = 0;
  param_1[0x16d] = 0;
  param_1[0x16e] = 0;
  FUN_0054c370(0);
  param_1[0x164] = 0;
  param_1[0x16f] = 0;
  *param_1 = &PTR_FUN_005ae180;
  ExceptionList = local_c;
  return param_1;
}


