void __thiscall FUN_0048f720(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 local_12c [3];
  undefined1 local_11d;
  undefined1 local_11c [12];
  int local_110;
  undefined1 local_10c [256];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059e5ed;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00402b70(&local_11d,8);
  local_4 = 0;
  FUN_00402a70();
  local_4 = 1;
  FUN_0049d3c0(&local_110,&param_2);
  if (local_110 != param_1[0x8bb]) {
    uVar1 = FUN_0050aaa9(param_2,local_10c,10);
    puVar2 = (undefined4 *)FUN_0049dc30(local_11c,local_12c,uVar1);
    local_4._0_1_ = 2;
    if (puVar2 != local_12c) {
      FUN_00403200(*puVar2,puVar2[1]);
    }
    local_4._0_1_ = 1;
    FUN_00402bd0();
    FUN_004ab200(local_12c);
    puVar2 = (undefined4 *)FUN_0049dc30(local_11c,local_12c,&DAT_005c462c);
    local_4._0_1_ = 3;
    if (puVar2 != local_12c) {
      FUN_00403200(*puVar2,puVar2[1]);
    }
    local_4._0_1_ = 1;
    FUN_00402bd0();
    puVar2 = (undefined4 *)FUN_0049dc30(local_11c,local_12c,param_3);
    local_4._0_1_ = 4;
    if (puVar2 != local_12c) {
      FUN_00403200(*puVar2,puVar2[1]);
    }
    local_4._0_1_ = 1;
    FUN_00402bd0();
    puVar2 = (undefined4 *)FUN_0049dc30(local_11c,local_12c,&DAT_005c462c);
    local_4._0_1_ = 5;
    if (puVar2 != local_12c) {
      FUN_00403200(*puVar2,puVar2[1]);
    }
    local_4._0_1_ = 1;
    FUN_00402bd0();
    uVar1 = FUN_0049de10(local_11c,local_12c,param_1[0x912] + 0x9c);
    local_4._0_1_ = 6;
    FUN_00473340(uVar1);
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_004026e0();
    (**(code **)(*param_1 + 0xfc))(local_12c[0],0);
  }
  local_4 = 0xffffffff;
  FUN_004026e0();
  ExceptionList = pvStack_c;
  return;
}



// WARNING: Removing unreachable block (ram,0x0048f995)
// WARNING: Removing unreachable block (ram,0x0048f99b)
// WARNING: Removing unreachable block (ram,0x0048f9a4)
