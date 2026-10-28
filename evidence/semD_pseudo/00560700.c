undefined4 __thiscall FUN_00560700(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 local_50 [20];
  undefined1 local_3c [8];
  undefined4 local_34;
  undefined1 local_24 [8];
  undefined4 local_1c;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a551b;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 0x40) != 0) {
    ExceptionList = &local_c;
    FUN_005783a0();
    local_4 = 0;
    FUN_0050ac61(local_3c,0x18,2,FUN_00565a40,FUN_004fa4f0);
    local_34 = *(undefined4 *)(param_1 + 0x20);
    local_4._0_1_ = 1;
    local_1c = param_2;
    FUN_005785c0(local_3c);
    FUN_005785c0(local_24);
    FUN_00570fc0(local_50);
    (**(code **)(**(int **)(param_1 + 0x40) + 4))();
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x40) + 8);
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0050ace3(local_3c,0x18,2,FUN_004fa4f0);
    local_4 = 0xffffffff;
    FUN_005783c0();
    ExceptionList = local_c;
    return uVar1;
  }
  return 0;
}


