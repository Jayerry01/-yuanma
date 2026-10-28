void FUN_004d6e60(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined1 local_4;
  undefined3 uStack_3;
  
  iVar4 = (int)param_2;
  puVar3 = param_1;
  puStack_8 = &LAB_005a1faa;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  if (param_1 != (undefined4 *)0x0) {
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    puVar1 = (undefined4 *)((int)param_2 + 8);
    puVar2 = (undefined4 *)((int)param_2 + 4);
    local_4 = 1;
    uStack_3 = 0;
    param_2 = param_1 + 1;
    FUN_00402ac0(*puVar2,*puVar1);
    param_2 = puVar3 + 4;
    *param_2 = 0;
    puVar3[5] = 0;
    puVar3[6] = 0;
    local_4 = 3;
    FUN_00402ac0(*(undefined4 *)(iVar4 + 0x10),*(undefined4 *)(iVar4 + 0x14));
    param_2 = puVar3 + 7;
    FUN_005005b0(&param_1);
    local_4 = 5;
    FUN_00402ac0(*(undefined4 *)(iVar4 + 0x1c),*(undefined4 *)(iVar4 + 0x20));
    puVar3[10] = *(undefined4 *)(iVar4 + 0x28);
    local_4 = 6;
    puVar3[0xb] = *(undefined4 *)(iVar4 + 0x2c);
    FUN_0049e380(iVar4 + 0x30);
    *puVar3 = &PTR_FUN_005a94e4;
    param_2 = (undefined4 *)((*(int *)(iVar4 + 0x40) - *(int *)(iVar4 + 0x3c)) / 0x28);
    local_4 = 7;
    puVar3[0xf] = 0;
    puVar3[0x10] = 0;
    puVar3[0x11] = 0;
    if (param_2 == (undefined4 *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_00402bf0((int)param_2 * 0x28);
    }
    puVar3[0xf] = iVar5;
    puVar3[0x10] = iVar5;
    puVar3[0x11] = iVar5 + (int)param_2 * 0x28;
    _local_4 = CONCAT31(uStack_3,8);
    uVar6 = FUN_0049fe20(*(undefined4 *)(iVar4 + 0x3c),*(undefined4 *)(iVar4 + 0x40),iVar5,param_1);
    puVar3[0x10] = uVar6;
    *puVar3 = &PTR_FUN_005a9488;
  }
  *unaff_FS_OFFSET = local_c;
  return;
}


