undefined4 __fastcall FUN_0043c710(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int iVar4;
  undefined1 **ppuVar5;
  undefined1 *apuStackY_90 [8];
  undefined1 local_3c [36];
  float local_18;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059acde;
  pvStack_c = ExceptionList;
  apuStackY_90[7] = (undefined1 *)0x43c735;
  ExceptionList = &pvStack_c;
  puVar2 = operator_new(0x6c);
  local_4 = 0;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    FUN_00462d50();
    *puVar2 = &PTR_FUN_005a8580;
  }
  local_4 = 0xffffffff;
  puVar2[1] = s_Con_Forward_005c7354;
  apuStackY_90[7] = (undefined1 *)0x43c777;
  puVar2 = operator_new(0xc);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = 0;
    *puVar2 = &PTR_FUN_005a8528;
  }
  apuStackY_90[7] = (undefined1 *)0x43c799;
  FUN_00463cb0();
  apuStackY_90[4] = (undefined1 *)DAT_005dbb70;
  apuStackY_90[5] = (undefined1 *)DAT_005dbb74;
  apuStackY_90[6] = (undefined1 *)DAT_005dbb78;
  apuStackY_90[7] = (undefined1 *)DAT_005dbb7c;
  apuStackY_90[3] = (undefined1 *)0x43c7c9;
  FUN_00462e50();
  apuStackY_90[7] = (undefined1 *)0x43c7d2;
  FUN_00463050();
  apuStackY_90[7] = (undefined1 *)0x43c7d9;
  puVar2 = operator_new(0x6c);
  local_4 = 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    FUN_00462d50();
    *puVar2 = &PTR_FUN_005a8580;
  }
  local_4 = 0xffffffff;
  puVar2[1] = s_Con_Forward_005c7354;
  apuStackY_90[7] = (undefined1 *)0x43c81d;
  puVar2 = operator_new(0xc);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = 0;
    *puVar2 = &PTR_FUN_005a8528;
  }
  apuStackY_90[7] = (undefined1 *)0x43c83f;
  FUN_00463cb0();
  apuStackY_90[4] = (undefined1 *)DAT_005dbb70;
  apuStackY_90[5] = (undefined1 *)DAT_005dbb74;
  apuStackY_90[6] = (undefined1 *)DAT_005dbb78;
  apuStackY_90[7] = (undefined1 *)DAT_005dbb7c;
  apuStackY_90[3] = (undefined1 *)0x43c86f;
  FUN_00462e50();
  apuStackY_90[7] = (undefined1 *)0x43c878;
  FUN_00463050();
  apuStackY_90[7] = (undefined1 *)0x43c87f;
  puVar2 = operator_new(0x6c);
  local_4 = 2;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    FUN_00462d50();
    *puVar2 = &PTR_FUN_005a8580;
  }
  local_4 = 0xffffffff;
  puVar2[1] = s_Con_Forward_005c7354;
  apuStackY_90[7] = (undefined1 *)0x43c8c3;
  puVar2 = operator_new(0xc);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = 0;
    *puVar2 = &PTR_FUN_005a8528;
  }
  apuStackY_90[7] = (undefined1 *)0x43c8e5;
  FUN_00463cb0();
  apuStackY_90[4] = (undefined1 *)DAT_005dbb70;
  apuStackY_90[5] = (undefined1 *)DAT_005dbb74;
  apuStackY_90[6] = (undefined1 *)DAT_005dbb78;
  apuStackY_90[7] = (undefined1 *)DAT_005dbb7c;
  apuStackY_90[3] = (undefined1 *)0x43c915;
  FUN_00462e50();
  apuStackY_90[7] = (undefined1 *)0x43c91e;
  FUN_00463050();
  apuStackY_90[7] = (undefined1 *)0x43c925;
  puVar2 = operator_new(0x6c);
  local_4 = 3;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    FUN_00462d50();
    *puVar2 = &PTR_FUN_005a8580;
  }
  local_4 = 0xffffffff;
  puVar2[1] = s_Con_Forward_005c7354;
  apuStackY_90[7] = (undefined1 *)0x43c969;
  puVar2 = operator_new(0xc);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2[1] = 0;
    *puVar2 = &PTR_FUN_005a8528;
  }
  apuStackY_90[7] = (undefined1 *)0x43c98b;
  FUN_00463cb0();
  apuStackY_90[4] = (undefined1 *)DAT_005dbb70;
  apuStackY_90[5] = (undefined1 *)DAT_005dbb74;
  apuStackY_90[6] = (undefined1 *)DAT_005dbb78;
  apuStackY_90[7] = (undefined1 *)DAT_005dbb7c;
  apuStackY_90[3] = (undefined1 *)0x43c9bb;
  FUN_00462e50();
  apuStackY_90[7] = local_3c;
  apuStackY_90[6] = *(undefined1 **)(puVar2[2] + 0x474);
  apuStackY_90[5] = (undefined1 *)0x43c9d1;
  thunk_FUN_0040c6f0();
  local_18 = local_18 + 12.0;
  apuStackY_90[4] = local_3c;
  apuStackY_90[5] = (undefined1 *)0x0;
  apuStackY_90[3] = *(undefined1 **)(puVar2[2] + 0x474);
  apuStackY_90[2] = (undefined1 *)0x43c9f4;
  thunk_FUN_0040c620();
  apuStackY_90[7] = (undefined1 *)0x43ca00;
  FUN_00463050();
  uVar1 = DAT_005dbb74;
  DAT_005dbb74 = 0;
  apuStackY_90[7] = (undefined1 *)0x43ca16;
  puVar2 = operator_new(0x6c);
  local_4 = 4;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    FUN_00462d50();
    *puVar2 = &PTR_FUN_005a8580;
  }
  local_4 = 0xffffffff;
  puVar2[1] = &DAT_005c73d8;
  apuStackY_90[7] = (undefined1 *)0x43ca5a;
  puVar2 = operator_new(0xc);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = 0;
    *puVar2 = &PTR_FUN_005a8528;
  }
  apuStackY_90[7] = (undefined1 *)0x43ca7c;
  FUN_00463cb0();
  apuStackY_90[4] = (undefined1 *)DAT_005dbb70;
  apuStackY_90[5] = (undefined1 *)DAT_005dbb74;
  apuStackY_90[6] = (undefined1 *)DAT_005dbb78;
  apuStackY_90[7] = (undefined1 *)DAT_005dbb7c;
  apuStackY_90[3] = (undefined1 *)0x43caaa;
  FUN_00462e50();
  apuStackY_90[7] = (undefined1 *)0x43cabb;
  DAT_005dbb74 = uVar1;
  puVar2 = operator_new(0x6c);
  local_4 = 5;
  if (puVar2 != (undefined4 *)0x0) {
    FUN_00462d50();
    *puVar2 = &PTR_FUN_005a8868;
  }
  local_4 = 0xffffffff;
  apuStackY_90[7] = (undefined1 *)0x43caf6;
  pvVar3 = operator_new(0x78);
  local_4 = 6;
  if (pvVar3 != (void *)0x0) {
    FUN_00467160();
  }
  DAT_005dbb74 = 0;
  local_4 = 0xffffffff;
  apuStackY_90[4] = (undefined1 *)DAT_005dbb70;
  apuStackY_90[5] = (undefined1 *)0x0;
  apuStackY_90[6] = (undefined1 *)DAT_005dbb78;
  apuStackY_90[7] = (undefined1 *)DAT_005dbb7c;
  apuStackY_90[3] = (undefined1 *)0x43cb56;
  FUN_00462e50();
  apuStackY_90[7] = (undefined1 *)0x0;
  apuStackY_90[6] = (undefined1 *)0x0;
  apuStackY_90[5] = (undefined1 *)0x1;
  DAT_005ddd68 = 0x43330000;
  DAT_005ddd6c = 0x42b20000;
  _DAT_005ddd70 = 0x43780000;
  _DAT_005ddd74 = 0x41e00000;
  puVar2 = &DAT_005ddd68;
  ppuVar5 = apuStackY_90;
  for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
    *ppuVar5 = (undefined1 *)*puVar2;
    puVar2 = puVar2 + 1;
    ppuVar5 = ppuVar5 + 1;
  }
  FUN_00467840();
  apuStackY_90[7] = (undefined1 *)0x43cba5;
  pvVar3 = operator_new(0x50);
  local_4 = 7;
  if (pvVar3 != (void *)0x0) {
    FUN_00465610();
  }
  local_4 = 0xffffffff;
  puVar2 = &DAT_005ddd68;
  ppuVar5 = apuStackY_90 + 3;
  for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
    *ppuVar5 = (undefined1 *)*puVar2;
    puVar2 = puVar2 + 1;
    ppuVar5 = ppuVar5 + 1;
  }
  apuStackY_90[2] = (undefined1 *)0x0;
  apuStackY_90[1] = (undefined1 *)0x1;
  apuStackY_90[0] = (undefined1 *)0x43cbee;
  FUN_00466720();
  apuStackY_90[7] = (undefined1 *)0x0;
  apuStackY_90[6] = (undefined1 *)0x0;
  puVar2 = &DAT_005ddd68;
  ppuVar5 = apuStackY_90 + 1;
  for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
    *ppuVar5 = (undefined1 *)*puVar2;
    puVar2 = puVar2 + 1;
    ppuVar5 = ppuVar5 + 1;
  }
  apuStackY_90[0] = (undefined1 *)0x43cc0c;
  FUN_00466a10();
  apuStackY_90[7] = (undefined1 *)0xff;
  apuStackY_90[6] = (undefined1 *)0xff;
  apuStackY_90[5] = (undefined1 *)0x0;
  apuStackY_90[4] = (undefined1 *)&DAT_005dbc84;
  apuStackY_90[3] = (undefined1 *)0x43cc29;
  FUN_00466340();
  apuStackY_90[7] = (undefined1 *)0x43cc33;
  FUN_00467950();
  apuStackY_90[7] = (undefined1 *)0x43cc3a;
  pvVar3 = operator_new(0x7c);
  local_4 = 8;
  if (pvVar3 != (void *)0x0) {
    FUN_00463fb0();
  }
  apuStackY_90[7] = (undefined1 *)0x0;
  apuStackY_90[6] = (undefined1 *)0x0;
  apuStackY_90[5] = (undefined1 *)0x0;
  _DAT_005ddd70 = 0x430d0000;
  _DAT_005ddd74 = 0x41900000;
  DAT_005ddd68 = 0x43808000;
  DAT_005ddd6c = 0x42c00000;
  puVar2 = &DAT_005ddd68;
  ppuVar5 = apuStackY_90;
  for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
    *ppuVar5 = (undefined1 *)*puVar2;
    puVar2 = puVar2 + 1;
    ppuVar5 = ppuVar5 + 1;
  }
  local_4 = 0xffffffff;
  FUN_004642f0();
  apuStackY_90[7] = (undefined1 *)0x43ccb4;
  pvVar3 = operator_new(0x6c);
  local_4 = 9;
  if (pvVar3 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_00462d50();
  }
  DAT_005dbb74 = 1;
  local_4 = 0xffffffff;
  apuStackY_90[4] = (undefined1 *)DAT_005dbb70;
  apuStackY_90[5] = (undefined1 *)0x1;
  apuStackY_90[6] = (undefined1 *)DAT_005dbb78;
  apuStackY_90[7] = (undefined1 *)DAT_005dbb7c;
  apuStackY_90[3] = (undefined1 *)0x43cd11;
  FUN_00462e50();
  *(char **)(iVar4 + 4) = s_user_name_005c756c;
  apuStackY_90[7] = (undefined1 *)0x43cd21;
  FUN_00463050();
  apuStackY_90[7] = (undefined1 *)0x43cd2f;
  FUN_00464240();
  DAT_005dbb74 = 1;
  apuStackY_90[7] = (undefined1 *)0x43cd40;
  puVar2 = operator_new(0xc);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = 0;
    puVar2[2] = 0;
    *puVar2 = &PTR_FUN_005a84d0;
  }
  apuStackY_90[7] = (undefined1 *)0x43cd61;
  FUN_0046a510();
  apuStackY_90[4] = (undefined1 *)DAT_005dbb70;
  apuStackY_90[5] = (undefined1 *)DAT_005dbb74;
  apuStackY_90[6] = (undefined1 *)DAT_005dbb78;
  apuStackY_90[7] = (undefined1 *)DAT_005dbb7c;
  apuStackY_90[3] = (undefined1 *)0x43cd95;
  FUN_00462e50();
  apuStackY_90[7] = (undefined1 *)0x43cda5;
  FUN_00462bf0();
  apuStackY_90[7] = (undefined1 *)0x43cdb5;
  FUN_00462bf0();
  apuStackY_90[7] = (undefined1 *)0x43cdc5;
  FUN_00462bf0();
  apuStackY_90[7] = (undefined1 *)0x43cdd5;
  FUN_00462bf0();
  apuStackY_90[7] = (undefined1 *)0x43cde5;
  FUN_00462bf0();
  apuStackY_90[7] = (undefined1 *)0x43cdf5;
  FUN_00462bf0();
  apuStackY_90[7] = (undefined1 *)0x43ce01;
  FUN_00462bf0();
  apuStackY_90[7] = (undefined1 *)0x43ce0e;
  (**(code **)(**(int **)(param_1 + 0x288) + 0x58))();
  apuStackY_90[7] = *(undefined1 **)(param_1 + 0x288);
  apuStackY_90[6] = (undefined1 *)0x43ce20;
  FUN_00461e50();
  apuStackY_90[7] = *(undefined1 **)(param_1 + 0x28c);
  apuStackY_90[6] = (undefined1 *)0x43ce30;
  FUN_00570fc0();
  apuStackY_90[7] = *(undefined1 **)(param_1 + 0x290);
  apuStackY_90[6] = (undefined1 *)0x43ce40;
  FUN_00570fc0();
  apuStackY_90[7] = *(undefined1 **)(param_1 + 0x294);
  apuStackY_90[6] = (undefined1 *)0x43ce4e;
  FUN_00570fc0();
  apuStackY_90[7] = *(undefined1 **)(param_1 + 0x27c);
  apuStackY_90[6] = (undefined1 *)0x43ce5c;
  FUN_00570fc0();
  ExceptionList = pvStack_10;
  return 1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
