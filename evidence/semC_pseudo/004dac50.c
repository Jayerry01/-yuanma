undefined4 * __thiscall FUN_004dac50(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_005a25ae;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  *(undefined1 *)(param_1 + 3) = *(undefined1 *)(param_2 + 3);
  *(undefined1 *)((int)param_1 + 0xd) = *(undefined1 *)((int)param_2 + 0xd);
  *(undefined1 *)((int)param_1 + 0xe) = *(undefined1 *)((int)param_2 + 0xe);
  piVar1 = param_1 + 4;
  *piVar1 = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  iVar3 = param_2[5];
  iVar6 = param_2[4];
  iVar4 = iVar3 - iVar6;
  local_4 = 0;
  iVar2 = iVar4 + 1;
  if (iVar2 == -1) {
    FUN_004030f0();
  }
  else if (iVar2 == 0) {
    *piVar1 = 0;
    param_1[5] = 0;
    param_1[6] = 0;
  }
  else {
    iVar5 = FUN_00402bf0(iVar2);
    *piVar1 = iVar5;
    param_1[5] = iVar5;
    param_1[6] = iVar5 + iVar2;
  }
  iVar2 = *piVar1;
  FUN_005092c0(iVar2,iVar6,iVar4);
  param_1[5] = (iVar2 - iVar6) + iVar3;
  FUN_00402a70();
  piVar1 = param_1 + 7;
  *piVar1 = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  iVar3 = param_2[8];
  iVar6 = param_2[7];
  iVar4 = iVar3 - iVar6;
  local_4._0_1_ = 2;
  local_4._1_3_ = 0;
  iVar2 = iVar4 + 1;
  if (iVar2 == -1) {
    FUN_004030f0();
  }
  else if (iVar2 == 0) {
    *piVar1 = 0;
    param_1[8] = 0;
    param_1[9] = 0;
  }
  else {
    iVar5 = FUN_00402bf0(iVar2);
    *piVar1 = iVar5;
    param_1[8] = iVar5;
    param_1[9] = iVar5 + iVar2;
  }
  iVar2 = *piVar1;
  FUN_005092c0(iVar2,iVar6,iVar4);
  param_1[8] = (iVar2 - iVar6) + iVar3;
  FUN_00402a70();
  piVar1 = param_1 + 10;
  iVar6 = 0;
  *piVar1 = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  iVar2 = param_2[0xb];
  iVar3 = param_2[10];
  local_4 = CONCAT31(local_4._1_3_,4);
  iVar4 = (iVar2 - iVar3) + 1;
  if (iVar4 == -1) {
    FUN_004030f0();
  }
  else {
    if (iVar4 != 0) {
      iVar6 = FUN_00402bf0(iVar4);
    }
    *piVar1 = iVar6;
    param_1[0xb] = iVar6;
    param_1[0xc] = iVar6 + iVar4;
  }
  uVar7 = FUN_004da870(iVar3,iVar2,*piVar1);
  param_1[0xb] = uVar7;
  FUN_00402a70();
  *unaff_FS_OFFSET = local_c;
  return param_1;
}


