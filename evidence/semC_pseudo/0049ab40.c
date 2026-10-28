undefined4 * __thiscall FUN_0049ab40(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar4 = param_2;
  puStack_8 = &LAB_0059f121;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  piVar1 = param_1 + 1;
  *piVar1 = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  iVar2 = *(int *)(param_2 + 8);
  iVar3 = *(int *)(param_2 + 4);
  local_4 = 0;
  param_2 = (iVar2 - iVar3) + 1;
  if (param_2 == -1) {
    FUN_004030f0();
  }
  else if (param_2 == 0) {
    *piVar1 = 0;
    param_1[2] = 0;
    param_1[3] = 0;
  }
  else {
    iVar6 = FUN_00402bf0(param_2);
    *piVar1 = iVar6;
    param_1[2] = iVar6;
    param_1[3] = iVar6 + param_2;
  }
  uVar5 = FUN_004da870(iVar3,iVar2,*piVar1);
  param_1[2] = uVar5;
  FUN_00402a70();
  piVar1 = param_1 + 4;
  *piVar1 = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  iVar2 = *(int *)(iVar4 + 0x14);
  iVar3 = *(int *)(iVar4 + 0x10);
  local_4._0_1_ = 2;
  local_4._1_3_ = 0;
  param_2 = (iVar2 - iVar3) + 1;
  if (param_2 == -1) {
    FUN_004030f0();
  }
  else if (param_2 == 0) {
    *piVar1 = 0;
    param_1[5] = 0;
    param_1[6] = 0;
  }
  else {
    iVar6 = FUN_00402bf0(param_2);
    *piVar1 = iVar6;
    param_1[5] = iVar6;
    param_1[6] = iVar6 + param_2;
  }
  uVar5 = FUN_004da870(iVar3,iVar2,*piVar1);
  param_1[5] = uVar5;
  FUN_00402a70();
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  iVar2 = *(int *)(iVar4 + 0x20);
  param_2 = *(int *)(iVar4 + 0x1c);
  iVar6 = iVar2 - param_2;
  local_4._0_1_ = 4;
  FUN_004608a0(iVar6 + 1);
  iVar3 = param_1[7];
  FUN_005092c0(iVar3,param_2,iVar6);
  param_1[8] = (iVar3 - param_2) + iVar2;
  FUN_00402a70();
  param_1[10] = *(undefined4 *)(iVar4 + 0x28);
  param_1[0xb] = *(undefined4 *)(iVar4 + 0x2c);
  local_4._0_1_ = 5;
  FUN_00560170((*(int *)(iVar4 + 0x34) - *(int *)(iVar4 + 0x30)) / 0xc,&param_2);
  local_4 = CONCAT31(local_4._1_3_,6);
  uVar5 = FUN_004f4800(*(undefined4 *)(iVar4 + 0x30),*(undefined4 *)(iVar4 + 0x34),param_1[0xc],
                       param_2);
  param_1[0xd] = uVar5;
  *param_1 = &PTR_FUN_005a94e4;
  *unaff_FS_OFFSET = local_c;
  return param_1;
}


