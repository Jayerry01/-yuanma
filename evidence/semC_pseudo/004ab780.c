void __thiscall FUN_004ab780(char *param_1,char *param_2)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  byte *pbVar5;
  int local_20;
  int local_1c;
  int local_18;
  byte *local_14;
  byte *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059fe40;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = *param_2 + -1;
  param_1[1] = param_2[1] + -1;
  pbVar5 = (byte *)(param_2 + 3);
  param_1[2] = param_2[2] + -1;
  iVar2 = *pbVar5 - 1;
  if (0 < iVar2) {
    do {
      bVar1 = pbVar5[1];
      pbVar5 = pbVar5 + 1;
      if (*(int *)(param_1 + 8) + 1 == *(int *)(param_1 + 0xc)) {
        param_2 = (char *)0x1;
        local_20 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);
        piVar3 = (int *)&param_2;
        if (local_20 != 0) {
          piVar3 = &local_20;
        }
        FUN_0049be40(*piVar3 + local_20);
      }
      FUN_00402bc0(*(int *)(param_1 + 8) + 1);
      **(byte **)(param_1 + 8) = bVar1;
      iVar2 = iVar2 + -1;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    } while (iVar2 != 0);
  }
  pbVar5 = pbVar5 + 1;
  iVar2 = *pbVar5 - 1;
  if (0 < iVar2) {
    do {
      bVar1 = pbVar5[1];
      pbVar5 = pbVar5 + 1;
      if (*(int *)(param_1 + 0x14) + 1 == *(int *)(param_1 + 0x18)) {
        param_2 = (char *)0x1;
        local_20 = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10);
        piVar3 = (int *)&param_2;
        if (local_20 != 0) {
          piVar3 = &local_20;
        }
        FUN_0049be40(*piVar3 + local_20);
      }
      FUN_00402bc0(*(int *)(param_1 + 0x14) + 1);
      **(byte **)(param_1 + 0x14) = bVar1;
      iVar2 = iVar2 + -1;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    } while (iVar2 != 0);
  }
  pbVar5 = pbVar5 + 1;
  iVar2 = *pbVar5 - 1;
  if (0 < iVar2) {
    do {
      bVar1 = pbVar5[1];
      pbVar5 = pbVar5 + 1;
      if (*(int *)(param_1 + 0x20) + 1 == *(int *)(param_1 + 0x24)) {
        param_2 = (char *)0x1;
        local_20 = *(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x1c);
        piVar3 = (int *)&param_2;
        if (local_20 != 0) {
          piVar3 = &local_20;
        }
        FUN_0049be40(*piVar3 + local_20);
      }
      FUN_00402bc0(*(int *)(param_1 + 0x20) + 1);
      **(byte **)(param_1 + 0x20) = bVar1;
      iVar2 = iVar2 + -1;
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    } while (iVar2 != 0);
  }
  pbVar5 = pbVar5 + 1;
  iVar2 = *pbVar5 - 1;
  if (0 < iVar2) {
    do {
      bVar1 = pbVar5[1];
      pbVar5 = pbVar5 + 1;
      if (*(int *)(param_1 + 0x2c) + 1 == *(int *)(param_1 + 0x30)) {
        param_2 = (char *)0x1;
        local_20 = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28);
        piVar3 = (int *)&param_2;
        if (local_20 != 0) {
          piVar3 = &local_20;
        }
        FUN_0049be40(*piVar3 + local_20);
      }
      FUN_00402bc0(*(int *)(param_1 + 0x2c) + 1);
      **(byte **)(param_1 + 0x2c) = bVar1;
      iVar2 = iVar2 + -1;
      *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
    } while (iVar2 != 0);
  }
  pbVar5 = pbVar5 + 1;
  iVar2 = *pbVar5 - 1;
  if (0 < iVar2) {
    do {
      bVar1 = pbVar5[1];
      pbVar5 = pbVar5 + 1;
      if (*(int *)(param_1 + 0x38) + 1 == *(int *)(param_1 + 0x3c)) {
        param_2 = (char *)0x1;
        local_20 = *(int *)(param_1 + 0x38) - *(int *)(param_1 + 0x34);
        piVar3 = (int *)&param_2;
        if (local_20 != 0) {
          piVar3 = &local_20;
        }
        FUN_0049be40(*piVar3 + local_20);
      }
      FUN_00402bc0(*(int *)(param_1 + 0x38) + 1);
      **(byte **)(param_1 + 0x38) = bVar1;
      iVar2 = iVar2 + -1;
      *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
    } while (iVar2 != 0);
  }
  pbVar5 = pbVar5 + 1;
  iVar2 = *pbVar5 - 1;
  FUN_00402b70(&param_2,8);
  local_4 = 0;
  FUN_00402a70();
  local_4 = 1;
  if (0 < iVar2) {
    do {
      bVar1 = pbVar5[1];
      pbVar5 = pbVar5 + 1;
      if (local_14 + 1 == local_10) {
        local_1c = (int)local_14 - local_18;
        local_20 = 1;
        piVar3 = (int *)FUN_0049c0d0(&local_1c,&local_20);
        FUN_0049be40(local_14 + (*piVar3 - local_18));
      }
      FUN_00402bc0(local_14 + 1);
      *local_14 = bVar1;
      local_14 = local_14 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  uVar4 = FUN_0050915b(local_18);
  local_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x44) = uVar4;
  FUN_004026e0();
  ExceptionList = local_c;
  return;
}


