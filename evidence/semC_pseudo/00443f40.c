undefined4 __fastcall FUN_00443f40(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059b456;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  puVar1 = operator_new(0x6c);
  local_4 = 0;
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
  FUN_00463cb0(s_muc002_MCb_005c75fc);
  FUN_00462e50(DAT_005dbb70,DAT_005dbb74,DAT_005dbb78,DAT_005dbb7c,puVar2);
  FUN_00463050(0x1a);
  puVar2 = operator_new(0x6c);
  local_4 = 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    FUN_00462d50();
    *puVar2 = &PTR_FUN_005a8580;
    puVar5 = puVar2;
  }
  local_4 = 0xffffffff;
  puVar5[1] = s_Con_Forward_005c7354;
  puVar3 = operator_new(0xc);
  puVar4 = (undefined4 *)0x0;
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[1] = 0;
    *puVar3 = &PTR_FUN_005a8528;
    puVar4 = puVar3;
  }
  FUN_00463cb0(s_muc003_MCb_005c76bc);
  FUN_00462e50(DAT_005dbb70,DAT_005dbb74,DAT_005dbb78,DAT_005dbb7c,puVar4);
  FUN_00463050(0x1b);
  puVar3 = operator_new(0xc);
  puVar4 = (undefined4 *)0x0;
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[1] = 0;
    puVar3[2] = 0;
    *puVar3 = &PTR_FUN_005a84d0;
    puVar4 = puVar3;
  }
  FUN_0046a510(s_mua008_mcb_005c76b0);
  FUN_00462e50(DAT_005dbb70,DAT_005dbb74,DAT_005dbb78,DAT_005dbb7c,puVar4);
  FUN_00462bf0(puVar1);
  FUN_00462bf0(puVar5);
  (**(code **)(**(int **)(param_1 + 0x298) + 0x58))(0);
  FUN_00461e50(*(undefined4 *)(param_1 + 0x298));
  FUN_00570fc0(*(undefined4 *)(param_1 + 0x27c));
  FUN_00570fc0(*(undefined4 *)(param_1 + 0x27c));
  ExceptionList = puVar2;
  return 1;
}


