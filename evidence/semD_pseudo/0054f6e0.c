int __fastcall FUN_0054f6e0(int param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a49c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004736a0();
  local_4 = 0;
  FUN_004736a0();
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00553b80();
  *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0x32;
  *(undefined1 *)(param_1 + 0x9c) = 1;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  ExceptionList = local_c;
  return param_1;
}


