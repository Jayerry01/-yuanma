FUN_004e62a0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            int param_6,undefined4 param_7,int param_8,int param_9,int param_10,int param_11,
            undefined4 param_12,int *param_13)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int local_a8;
  undefined4 local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  undefined1 *local_8c;
  int local_88;
  int local_84;
  undefined4 local_80;
  int local_7c;
  int *piStack_78;
  undefined1 local_68 [16];
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005a2f50;
  local_10 = ExceptionList;
  local_14 = &stack0xffffff8c;
  piVar1 = (int *)(param_1 + 8);
  uVar4 = ((param_8 - param_6) / 0xc +
          (param_10 - param_11) / 0xc + ((int)param_13 - param_9 >> 2) * 0x2a) - 0x2a;
  local_18 = param_1;
  if (param_2 == *piVar1) {
    uVar3 = (*piVar1 - *(int *)(param_1 + 0xc)) / 0xc;
    ExceptionList = &local_10;
    local_14 = &stack0xffffff8c;
    if (uVar3 < uVar4) {
      piStack_78 = (int *)(uVar4 - uVar3);
      local_7c = 0x4e6349;
      ExceptionList = &local_10;
      local_14 = &stack0xffffff8c;
      FUN_004e74e0();
    }
    local_7c = 0x4e6352;
    piStack_78 = piVar1;
    FUN_004e6050();
    piStack_78 = (int *)-uVar4;
    local_7c = 0x4e635d;
    piStack_78 = (int *)FUN_0049bd10();
    local_7c = 0x4e6366;
    FUN_004e6050();
    local_34 = param_3;
    local_38 = param_2;
    piStack_78 = &local_38;
    local_30 = param_4;
    local_8 = 0;
    local_2c = param_5;
    local_7c = 0x4e6391;
    FUN_004e6050();
    local_8c = local_48;
    piStack_78 = param_13;
    local_90 = 0x4e63a3;
    FUN_004e6050();
    local_98 = param_10;
    local_94 = param_11;
    local_90 = param_12;
    local_8c = (undefined1 *)param_13;
    local_a8 = param_6;
    local_a4 = param_7;
    local_a0 = param_8;
    local_9c = param_9;
    FUN_004e7cf0(&local_38);
    *piVar1 = param_2;
    *(undefined4 *)(param_1 + 0xc) = param_3;
    *(undefined4 *)(param_1 + 0x10) = param_4;
    *(undefined4 *)(param_1 + 0x14) = param_5;
    ExceptionList = local_10;
    return;
  }
  puVar2 = (undefined4 *)(param_1 + 0x18);
  if (param_2 == *(int *)(param_1 + 0x18)) {
    uVar3 = (*(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x18)) / 0xc - 1;
    ExceptionList = &local_10;
    local_14 = &stack0xffffff8c;
    if (uVar3 < uVar4) {
      piStack_78 = (int *)(uVar4 - uVar3);
      local_7c = 0x4e6473;
      ExceptionList = &local_10;
      local_14 = &stack0xffffff8c;
      FUN_004e75c0();
    }
    local_7c = 0x4e647c;
    piStack_78 = puVar2;
    FUN_004e6050();
    local_7c = 0x4e6485;
    piStack_78 = (int *)uVar4;
    piStack_78 = (int *)FUN_0049bd10();
    local_7c = 0x4e648e;
    FUN_004e6050();
    param_3 = *(undefined4 *)(param_1 + 0x1c);
    param_2 = *puVar2;
    param_4 = *(undefined4 *)(param_1 + 0x20);
    piStack_78 = &param_2;
    param_5 = *(undefined4 *)(param_1 + 0x24);
    local_8 = 2;
    local_7c = 0x4e64b8;
    FUN_004e6050();
    local_8c = local_58;
    piStack_78 = param_13;
    local_90 = 0x4e64ca;
    FUN_004e6050();
    local_98 = param_10;
    local_94 = param_11;
    local_90 = param_12;
    local_8c = (undefined1 *)param_13;
    local_a8 = param_6;
    local_a4 = param_7;
    local_a0 = param_8;
    local_9c = param_9;
    FUN_004e7cf0(local_68);
    *puVar2 = local_28;
    *(undefined4 *)(param_1 + 0x1c) = local_24;
    *(undefined4 *)(param_1 + 0x20) = local_20;
    *(undefined4 *)(param_1 + 0x24) = local_1c;
    ExceptionList = local_10;
    return;
  }
  local_88 = param_10;
  local_84 = param_11;
  local_80 = param_12;
  local_7c = (int)param_13;
  param_13 = &local_a8;
  local_98 = param_6;
  local_94 = param_7;
  local_90 = param_8;
  local_8c = (undefined1 *)param_9;
  ExceptionList = &local_10;
  piStack_78 = (int *)uVar4;
  FUN_004e6050(&param_2);
  FUN_004e6d50();
  ExceptionList = local_10;
  return;
}



void Catch_004e6411(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(*(int *)(unaff_EBP + -0x14) + 0x14);
  for (puVar2 = *(undefined4 **)(unaff_EBP + 0x14); puVar2 < puVar1; puVar2 = puVar2 + 1) {
    FUN_00402e90(*puVar2,0x1f8);
  }
                    // WARNING: Subroutine does not return
  __CxxThrowException_8(0,0);
}



void Catch_004e6538(void)

{
  int iVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x18);
  puVar2 = *(undefined4 **)(*(int *)(unaff_EBP + -0x14) + 0x24);
  while (puVar2 = puVar2 + 1, puVar2 < (undefined4 *)(iVar1 + 4U)) {
    FUN_00402e90(*puVar2,0x1f8);
  }
                    // WARNING: Subroutine does not return
  __CxxThrowException_8(0,0);
}



int * __thiscall