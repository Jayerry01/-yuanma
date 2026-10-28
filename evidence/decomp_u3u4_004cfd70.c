
undefined4 __thiscall FUN_004cfd70(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 **ppuVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 **ppuVar6;
  undefined4 *local_20;
  undefined4 *local_1c;
  int local_18;
  void *local_14;
  undefined4 local_10;
  void *pvStack_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = thunk_ilt_005A1A00;
  pvStack_c = ExceptionList;
  ppuVar1 = (undefined4 **)(param_1 + 0xba);
  local_18 = 0;
  local_14 = (void *)0x0;
  local_10 = 0;
  iVar3 = param_1[0xbb];
  puVar2 = *ppuVar1;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  FUN_004608a0((iVar3 - (int)puVar2) + 1);
  local_14 = (void *)FUN_004da870(puVar2,iVar3,local_18);
  FUN_00402a70();
  local_4 = 1;
  if (param_1[0xbb] + 1 == param_1[0xbc]) {
    local_20 = (undefined4 *)0x1;
    local_1c = (undefined4 *)(param_1[0xbb] - (int)*ppuVar1);
    ppuVar6 = &local_20;
    if (local_1c != (undefined4 *)0x0) {
      ppuVar6 = &local_1c;
    }
    FUN_0049be40((int)*ppuVar6 + (int)local_1c);
  }
  FUN_00402bc0(param_1[0xbb] + 1);
  *(undefined1 *)param_1[0xbb] = 0x6d;
  param_1[0xbb] = param_1[0xbb] + 1;
  iVar3 = (**(code **)(*param_1 + 0x130))();
  if ((iVar3 == 0) || (param_1[0xd8] == 0)) {
    if (param_1[0xbb] + 1 == param_1[0xbc]) {
      local_1c = (undefined4 *)0x1;
      local_20 = (undefined4 *)(param_1[0xbb] - (int)*ppuVar1);
      ppuVar6 = &local_1c;
      if (local_20 != (undefined4 *)0x0) {
        ppuVar6 = &local_20;
      }
      FUN_0049be40((int)*ppuVar6 + (int)local_20);
    }
    FUN_00402bc0(param_1[0xbb] + 1);
    *(undefined1 *)param_1[0xbb] = 0x61;
    param_1[0xbb] = param_1[0xbb] + 1;
  }
  uVar4 = (**(code **)(*(int *)param_1[0xd2] + 0x10))(param_1,param_3);
  if (local_4 == 0) {
    if (&local_20 != ppuVar1) {
      FUN_00403200(local_20,local_1c);
    }
  }
  else if (*ppuVar1 != (undefined4 *)param_1[0xbb]) {
    *(undefined1 *)*ppuVar1 = 0;
    param_1[0xbb] = (int)*ppuVar1;
  }
  puVar2 = local_20;
  uVar5 = local_18 - (int)local_20;
  if ((local_20 != (undefined4 *)0x0) && (uVar5 != 0)) {
    if (uVar5 < 0x81) {
      FUN_00402330();
      *puVar2 = *(undefined4 *)(&DAT_005d59a4 + (uVar5 + 7 >> 3) * 4);
      *(undefined4 **)(&DAT_005d59a4 + (uVar5 + 7 >> 3) * 4) = puVar2;
      DAT_005d59e8 = 0;
    }
    else {
      FUN_005089fd(local_20);
    }
  }
  ExceptionList = local_14;
  return uVar4;
}

