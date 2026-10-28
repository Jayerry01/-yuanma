undefined1 __thiscall FUN_0047f4b0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined **local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined **local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  uVar5 = param_2;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059d4c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  uVar3 = FUN_0047f3d0(param_2);
  *(undefined4 *)(param_1 + 0xb8) = uVar3;
  if (*(int *)(param_1 + 0xbc) == 0) {
    cVar2 = FUN_0047f800(uVar5);
    if (cVar2 == '\0') {
      ExceptionList = local_c;
      return 0;
    }
    if (param_3 == 0) {
      ExceptionList = local_c;
      return 1;
    }
    cVar2 = FUN_0047f870(param_3);
    if (cVar2 != '\0') {
      ExceptionList = local_c;
      return 1;
    }
    ExceptionList = local_c;
    return 0;
  }
  uVar3 = FUN_0047f3d0(uVar5);
  uVar4 = FUN_00480c10(uVar5);
  if (uVar4 == 0xffffffff) {
    ExceptionList = local_c;
    return 0;
  }
  local_38 = 0;
  local_34 = 0;
  FUN_00402b70(&param_2,8);
  local_4 = 0;
  FUN_00402a70();
  local_3c = &PTR_LAB_005a8fd0;
  local_4 = 1;
  if ((-1 < (int)uVar4) &&
     (uVar4 < (uint)(((*(int **)(param_1 + 0xbc))[1] - **(int **)(param_1 + 0xbc)) / 0x18))) {
    FUN_00480b00(uVar4,&local_3c);
  }
  cVar2 = FUN_0047f8e0(uVar3,local_34,local_38);
  iVar1 = param_3;
  if (cVar2 == '\0') {
    local_4 = 2;
  }
  else {
    if (param_3 == 0) {
LAB_0047f736:
      local_3c = &PTR_LAB_005a8fd0;
      local_4 = 8;
      FUN_00481850();
      local_4 = 0xffffffff;
      FUN_004026e0();
      ExceptionList = local_c;
      return 1;
    }
    uVar5 = FUN_0047f3d0(param_3);
    uVar4 = FUN_00480c10(iVar1);
    if (uVar4 == 0xffffffff) {
      local_4 = 3;
    }
    else {
      local_20 = 0;
      local_1c = 0;
      FUN_004024a0(&param_3);
      local_24 = &PTR_LAB_005a8fd0;
      local_4._0_1_ = 4;
      if ((-1 < (int)uVar4) &&
         (uVar4 < (uint)(((*(int **)(param_1 + 0xbc))[1] - **(int **)(param_1 + 0xbc)) / 0x18))) {
        FUN_00480b00(uVar4,&local_24);
      }
      cVar2 = FUN_0047f960(uVar5,local_1c,local_20);
      if (cVar2 != '\0') {
        local_24 = &PTR_LAB_005a8fd0;
        local_4._0_1_ = 7;
        FUN_00481850();
        local_4 = CONCAT31(local_4._1_3_,1);
        FUN_00402bd0();
        goto LAB_0047f736;
      }
      local_24 = &PTR_LAB_005a8fd0;
      local_4._0_1_ = 5;
      FUN_00481850();
      local_4 = CONCAT31(local_4._1_3_,1);
      if ((local_18 != 0) && (local_10 - local_18 != 0)) {
        FUN_00402e90(local_18,local_10 - local_18);
      }
      local_4 = 6;
    }
  }
  local_3c = &PTR_LAB_005a8fd0;
  FUN_00481850();
  local_4 = 0xffffffff;
  FUN_00402bd0();
  ExceptionList = local_c;
  return 0;
}



undefined4 __thiscall