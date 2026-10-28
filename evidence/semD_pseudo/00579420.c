int __fastcall FUN_00579420(int param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a627e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0047bfd0();
  local_4 = 0;
  FUN_00477200();
  *(undefined4 *)(param_1 + 0x14c) = 0x10;
  *(undefined4 *)(param_1 + 0x148) = 0x10;
  *(undefined4 *)(param_1 + 0x154) = 0x3cf5c28f;
  *(undefined4 *)(param_1 + 0x150) = 0x3cf5c28f;
  FUN_0047c3a0(0x3f800000,0x3f800000);
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x144) = 0;
  *(undefined4 *)(param_1 + 0x134) = 0;
  *(undefined4 *)(param_1 + 0x13c) = 1;
  *(undefined4 *)(param_1 + 0x140) = 1;
  *(undefined4 *)(param_1 + 0x130) = 0xffff;
  ExceptionList = local_c;
  return param_1;
}


