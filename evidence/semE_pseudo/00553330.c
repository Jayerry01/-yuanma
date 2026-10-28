void __fastcall FUN_00553330(undefined4 *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_005a4dbc;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_005ae158;
  local_4 = 3;
  FUN_00553480();
  local_4._0_1_ = 2;
  FUN_00555af0();
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_005546b0();
  ExceptionList = pvStack_c;
  return;
}


