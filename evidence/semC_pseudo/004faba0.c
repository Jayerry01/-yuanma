bool __thiscall FUN_004faba0(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int local_30 [2];
  int local_28;
  undefined **local_24;
  int local_20;
  undefined4 *local_1c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar3 = param_2;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a3ba8;
  local_c = ExceptionList;
  if (param_2 != 0) {
    if (DAT_006669f8 == '\0') {
      ExceptionList = &local_c;
      puVar4 = (undefined4 *)FUN_0049dc30(local_30,&DAT_006669ec,param_2);
      iVar3 = FUN_00509f8f(*puVar4,&DAT_005c4580);
      if ((local_30[0] != 0) && (local_28 - local_30[0] != 0)) {
        FUN_00402e90(local_30[0],local_28 - local_30[0]);
      }
      if (iVar3 == 0) {
        ExceptionList = local_c;
        return false;
      }
      FUN_0050a2d3(iVar3,0,2);
      iVar5 = FUN_0050a38c(iVar3);
      if (iVar5 < 1) {
        FUN_00509e57(iVar3);
        ExceptionList = local_c;
        return false;
      }
      iVar5 = FUN_004fade0(iVar5);
      if (iVar5 == 0) {
        FUN_00509e57(iVar3);
        ExceptionList = local_c;
        return false;
      }
      FUN_0050a2d3(iVar3,0,0);
      iVar5 = FUN_0050a118(*(undefined4 *)(param_1 + 0xc),1,*(undefined4 *)(param_1 + 8),iVar3);
      FUN_00509e57(iVar3);
      ExceptionList = local_c;
      return iVar5 == *(int *)(param_1 + 8);
    }
    local_20 = 0;
    local_1c = (undefined4 *)0x0;
    ExceptionList = &local_c;
    FUN_00402b70(&param_2,8);
    local_4 = 0;
    FUN_00402a70();
    local_24 = &PTR_LAB_005a8fd0;
    local_4 = 1;
    uVar2 = FUN_00480c10(iVar3);
    if ((int)uVar2 < 0) {
      local_4 = 2;
    }
    else if ((uVar2 < (uint)((DAT_006669d4 - DAT_006669d0) / 0x18)) &&
            (cVar1 = FUN_00480b00(uVar2,&local_24), cVar1 != '\0')) {
      if (local_20 < 1) {
        local_4 = 4;
      }
      else {
        iVar3 = FUN_004fade0(local_20);
        if (iVar3 != 0) {
          uVar2 = *(uint *)(param_1 + 8);
          puVar4 = local_1c;
          puVar7 = *(undefined4 **)(param_1 + 0xc);
          for (uVar6 = uVar2 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar7 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar7 = puVar7 + 1;
          }
          for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
            *(undefined1 *)puVar7 = *(undefined1 *)puVar4;
            puVar4 = (undefined4 *)((int)puVar4 + 1);
            puVar7 = (undefined4 *)((int)puVar7 + 1);
          }
          local_24 = &PTR_LAB_005a8fd0;
          local_4 = 6;
          FUN_00481850();
          local_4 = 0xffffffff;
          FUN_00402bd0();
          ExceptionList = local_c;
          return true;
        }
        local_4 = 5;
      }
    }
    else {
      local_4 = 3;
    }
    local_24 = &PTR_LAB_005a8fd0;
    FUN_00481850();
    local_4 = 0xffffffff;
    FUN_00402bd0();
  }
  ExceptionList = local_c;
  return false;
}


