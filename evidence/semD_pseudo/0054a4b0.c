undefined4 __fastcall FUN_0054a4b0(int param_1)

{
  char cVar1;
  undefined1 local_14 [8];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a4548;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00554970();
  FUN_005546c0(1);
  FUN_00554b30(1);
  FUN_00554b60(1);
  FUN_004736a0();
  local_4 = 0;
  cVar1 = FUN_00554710(local_14);
  if (cVar1 == '\0') {
    FUN_0054a740();
    ExceptionList = local_c;
    return 0;
  }
  FUN_00553dc0(param_1 + 0x24);
  FUN_00554ae0(param_1 + 0xc);
  ExceptionList = local_c;
  return 1;
}


