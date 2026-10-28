void FUN_00527ef0(uint param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  BOOL BVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  uVar6 = 0;
  if (param_1 == 0) {
    return;
  }
  uVar2 = FUN_00525980();
  FUN_00525610(uVar2);
  BVar3 = IsBadWritePtr(param_2,param_1 * 4);
  if (BVar3 != 0) {
    FUN_005255b0(0xa003);
    FUN_00525620(uVar2);
    return;
  }
  if (DAT_00667a54 == (undefined4 *)0x0) {
    DAT_00667a54 = _malloc(0x28);
    if (DAT_00667a54 == (undefined4 *)0x0) goto LAB_00528006;
    uVar6 = 1;
    puVar7 = DAT_00667a54;
    for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    *param_2 = DAT_00667a54;
    DAT_00667a54[6] = 0;
    DAT_00667a58 = DAT_00667a58 + 1;
    puVar7 = DAT_00667a54;
  }
  else {
    puVar4 = (undefined4 *)DAT_00667a54[9];
    puVar7 = DAT_00667a54;
    while (puVar1 = puVar4, puVar1 != (undefined4 *)0x0) {
      puVar7 = puVar1;
      puVar4 = (undefined4 *)puVar1[9];
    }
  }
  for (; (puVar7 != (undefined4 *)0x0 && (uVar6 < param_1)); uVar6 = uVar6 + 1) {
    puVar4 = _malloc(0x28);
    puVar7[9] = puVar4;
    if (puVar4 == (undefined4 *)0x0) break;
    for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    param_2[uVar6] = puVar7[9];
    *(undefined4 **)(puVar7[9] + 0x20) = puVar7;
    *(undefined4 *)(puVar7[9] + 0x18) = 0;
    DAT_00667a58 = DAT_00667a58 + 1;
    puVar7 = (undefined4 *)puVar7[9];
  }
LAB_00528006:
  if (uVar6 != param_1) {
    FUN_005255b0(0xa005);
  }
  FUN_00525620(uVar2);
  return;
}


