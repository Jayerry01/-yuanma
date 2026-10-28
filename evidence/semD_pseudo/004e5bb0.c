void __fastcall FUN_004e5bb0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 local_2c [8];
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_005a2ed0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_005ab06c;
  local_20 = param_1[0x2a];
  local_24 = param_1[0x29];
  uVar1 = param_1[0x27];
  uVar2 = param_1[0x28];
  local_4._0_1_ = 1;
  local_4._1_3_ = 0;
  FUN_004e6050(param_1 + 0x23);
  local_30 = local_20;
  local_34 = local_24;
  local_3c = uVar1;
  local_38 = uVar2;
  FUN_004e6050(local_1c);
  FUN_004e6050(&local_3c);
  FUN_004e6050(local_2c);
  FUN_004e7c30();
  local_4 = (uint)local_4._1_3_ << 8;
  if (param_1[0x21] != 0) {
    iVar3 = param_1[0x2a];
    for (puVar4 = (undefined4 *)param_1[0x26]; puVar4 < (undefined4 *)(iVar3 + 4);
        puVar4 = puVar4 + 1) {
      FUN_00402e90(*puVar4,0x1f8);
    }
    if (param_1[0x22] != 0) {
      FUN_00402e90(param_1[0x21],param_1[0x22] << 2);
    }
  }
  *param_1 = &PTR_FUN_005ab064;
  local_4 = 0xffffffff;
  if ((int *)param_1[0x14] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x14] + 8))(1);
  }
  ExceptionList = local_c;
  return;
}



undefined4 * __thiscall