void __fastcall FUN_00555af0(undefined4 *param_1)

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
  
  puStack_8 = &LAB_005a4e91;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_005ae180;
  local_4 = 1;
  FUN_00555c10();
  local_20 = param_1[0x16e];
  local_24 = param_1[0x16d];
  uVar1 = param_1[0x16b];
  uVar2 = param_1[0x16c];
  local_4._0_1_ = 2;
  FUN_004e6050(param_1 + 0x167);
  local_30 = local_20;
  local_34 = local_24;
  local_3c = uVar1;
  local_38 = uVar2;
  FUN_004e6050(local_1c);
  FUN_004e6050(&local_3c);
  FUN_004e6050(local_2c);
  FUN_00556260();
  local_4 = (uint)local_4._1_3_ << 8;
  if (param_1[0x165] != 0) {
    iVar3 = param_1[0x16e];
    for (puVar4 = (undefined4 *)param_1[0x16a]; puVar4 < (undefined4 *)(iVar3 + 4);
        puVar4 = puVar4 + 1) {
      FUN_00402e90(*puVar4,0x1f8);
    }
    if (param_1[0x166] != 0) {
      FUN_00402e90(param_1[0x165],param_1[0x166] << 2);
    }
  }
  local_4 = 0xffffffff;
  FUN_00553830();
  ExceptionList = local_c;
  return;
}


