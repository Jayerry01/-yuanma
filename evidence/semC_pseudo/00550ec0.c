undefined1 FUN_00550ec0(char *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  char *pcVar6;
  bool bVar7;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  char *local_24;
  int local_20;
  char *local_18;
  int local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a4b30;
  local_c = ExceptionList;
  uVar4 = 0;
  if (param_1 == (char *)0x0) {
    return 0;
  }
  uVar2 = 0xffffffff;
  pcVar6 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  iVar3 = ~uVar2 - 1;
  if (iVar3 < 0xe) {
    return 0;
  }
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  ExceptionList = &local_c;
  FUN_004608a0(8);
  local_4 = 0;
  FUN_00402a70();
  local_4 = 1;
  iVar5 = iVar3 / 2;
  FUN_0054ff00(param_1,iVar5,&local_48);
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  uVar2 = 0xffffffff;
  local_4._0_1_ = 2;
  pcVar6 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_00402ac0(param_1,param_1 + (~uVar2 - 1));
  local_4._0_1_ = 3;
  FUN_004fb240(&local_18,iVar5,iVar3 - iVar5);
  local_4._0_1_ = 5;
  if ((local_3c != 0) && (local_34 - local_3c != 0)) {
    FUN_00402e90(local_3c,local_34 - local_3c);
  }
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_4._0_1_ = 6;
  FUN_00402ac0(local_48,local_44);
  local_4._0_1_ = 7;
  FUN_004fb240(&local_24,iVar5,iVar3 - iVar5);
  local_4._0_1_ = 9;
  if ((local_30 != 0) && (local_28 - local_30 != 0)) {
    FUN_00402e90(local_30,local_28 - local_30);
  }
  local_14 = local_14 - (int)local_18;
  if (local_14 == local_20 - (int)local_24) {
    bVar7 = true;
    do {
      if (local_14 == 0) break;
      local_14 = local_14 + -1;
      bVar7 = *local_18 == *local_24;
      local_18 = local_18 + 1;
      local_24 = local_24 + 1;
    } while (bVar7);
    if (bVar7) {
      uVar4 = 1;
    }
  }
  local_4._0_1_ = 5;
  FUN_00402bd0();
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00402bd0();
  local_4 = 0xffffffff;
  FUN_004026e0();
  ExceptionList = local_c;
  return uVar4;
}


