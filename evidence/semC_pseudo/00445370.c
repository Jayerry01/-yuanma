undefined4 __fastcall FUN_00445370(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *local_18;
  undefined4 *local_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059b68c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  local_18 = operator_new(0x6c);
  local_4 = 0;
  if (local_18 == (undefined4 *)0x0) {
    local_18 = (undefined4 *)0x0;
  }
  else {
    FUN_00462d50();
    *local_18 = &PTR_FUN_005a8580;
  }
  local_4 = 0xffffffff;
  local_18[1] = s_Con_Back_005c7734;
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[1] = 0;
    *puVar1 = &PTR_FUN_005a8528;
  }
  FUN_00463cb0(s_muc003_MCb_005c76bc);
  FUN_00462e50(DAT_005dbb70,DAT_005dbb74,DAT_005dbb78,DAT_005dbb7c,puVar1);
  FUN_00463050(0x4e);
  local_14 = operator_new(0x6c);
  local_4 = 1;
  if (local_14 == (undefined4 *)0x0) {
    local_14 = (undefined4 *)0x0;
  }
  else {
    FUN_00462d50();
    *local_14 = &PTR_FUN_005a8580;
  }
  local_4 = 0xffffffff;
  local_14[1] = s_Con_Forward_005c7354;
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[1] = 0;
    *puVar1 = &PTR_FUN_005a8528;
  }
  FUN_00463cb0(s_mub017_MCb_005c7728);
  FUN_00462e50(DAT_005dbb70,DAT_005dbb74,DAT_005dbb78,DAT_005dbb7c,puVar1);
  FUN_00463050(0x41);
  puVar1 = operator_new(0x6c);
  local_4 = 2;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    FUN_00462d50();
    *puVar1 = &PTR_FUN_005a8580;
  }
  local_4 = 0xffffffff;
  puVar1[1] = s_Con_Forward_005c7354;
  puVar2 = operator_new(0xc);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2[1] = 0;
    *puVar2 = &PTR_FUN_005a8528;
  }
  FUN_00463cb0(s_mub018_MCb_005c771c);
  FUN_00462e50(DAT_005dbb70,DAT_005dbb74,DAT_005dbb78,DAT_005dbb7c,puVar2);
  FUN_00463050(0x40);
  DAT_005dbb74 = 0;
  puVar3 = operator_new(0x6c);
  local_4 = 3;
  puVar2 = (undefined4 *)0x0;
  if (puVar3 != (undefined4 *)0x0) {
    FUN_00462d50();
    *puVar3 = &PTR_FUN_005a8580;
    puVar2 = puVar3;
  }
  local_4 = 0xffffffff;
  puVar2[1] = &DAT_005c73d8;
  puVar4 = operator_new(0xc);
  puVar5 = (undefined4 *)0x0;
  if (puVar4 != (undefined4 *)0x0) {
    puVar4[1] = 0;
    *puVar4 = &PTR_FUN_005a8528;
    puVar5 = puVar4;
  }
  FUN_00463cb0(s_MUa001c_MCb_005c7710);
  FUN_00462e50(DAT_005dbb70,DAT_005dbb74,DAT_005dbb78,DAT_005dbb7c,puVar5);
  DAT_005dbb74 = 1;
  puVar4 = operator_new(0xc);
  puVar5 = (undefined4 *)0x0;
  if (puVar4 != (undefined4 *)0x0) {
    puVar4[1] = 0;
    puVar4[2] = 0;
    *puVar4 = &PTR_FUN_005a84d0;
    puVar5 = puVar4;
  }
  FUN_0046a510(s_mua009_mcb_005c7704);
  FUN_00462e50(DAT_005dbb70,DAT_005dbb74,DAT_005dbb78,DAT_005dbb7c,puVar5);
  FUN_00462bf0(local_18);
  FUN_00462bf0(puVar1);
  FUN_00462bf0(local_14);
  FUN_00462bf0(puVar2);
  (**(code **)(**(int **)(param_1 + 0x2a0) + 0x58))(0);
  FUN_00461e50(*(undefined4 *)(param_1 + 0x2a0));
  FUN_00570fc0(*(undefined4 *)(param_1 + 0x2a4));
  FUN_00570fc0(*(undefined4 *)(param_1 + 0x2a4));
  ExceptionList = puVar3;
  return 1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
