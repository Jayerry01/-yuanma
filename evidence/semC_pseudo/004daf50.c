void FUN_004daf50(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 local_4;
  undefined3 uStack_3;
  
  puStack_8 = &LAB_005a261f;
  local_c = ExceptionList;
  if (param_1 != (undefined4 *)0x0) {
    piVar1 = param_1 + 4;
    ExceptionList = &local_c;
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    *(undefined1 *)(param_1 + 3) = *(undefined1 *)(param_2 + 3);
    *(undefined1 *)((int)param_1 + 0xd) = *(undefined1 *)((int)param_2 + 0xd);
    *(undefined1 *)((int)param_1 + 0xe) = *(undefined1 *)((int)param_2 + 0xe);
    *piVar1 = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    iVar3 = param_2[5];
    iVar4 = param_2[4];
    local_4 = 1;
    uStack_3 = 0;
    iVar2 = (iVar3 - iVar4) + 1;
    if (iVar2 == -1) {
      FUN_004030f0();
    }
    else if (iVar2 == 0) {
      *piVar1 = 0;
      param_1[5] = 0;
      param_1[6] = 0;
    }
    else {
      iVar6 = FUN_00402bf0(iVar2);
      *piVar1 = iVar6;
      param_1[5] = iVar6;
      param_1[6] = iVar6 + iVar2;
    }
    uVar5 = FUN_004da870(iVar4,iVar3,*piVar1);
    param_1[5] = uVar5;
    FUN_00402a70();
    piVar1 = param_1 + 7;
    *piVar1 = 0;
    param_1[8] = 0;
    param_1[9] = 0;
    iVar3 = param_2[8];
    iVar4 = param_2[7];
    local_4 = 3;
    iVar2 = (iVar3 - iVar4) + 1;
    if (iVar2 == -1) {
      FUN_004030f0();
    }
    else if (iVar2 == 0) {
      *piVar1 = 0;
      param_1[8] = 0;
      param_1[9] = 0;
    }
    else {
      iVar6 = FUN_00402bf0(iVar2);
      *piVar1 = iVar6;
      param_1[8] = iVar6;
      param_1[9] = iVar6 + iVar2;
    }
    uVar5 = FUN_004da870(iVar4,iVar3,*piVar1);
    param_1[8] = uVar5;
    FUN_00402a70();
    param_1[10] = 0;
    param_1[0xb] = 0;
    param_1[0xc] = 0;
    iVar2 = param_2[0xb];
    iVar3 = param_2[10];
    _local_4 = CONCAT31(uStack_3,5);
    FUN_004608a0((iVar2 - iVar3) + 1);
    uVar5 = FUN_004da870(iVar3,iVar2,param_1[10]);
    param_1[0xb] = uVar5;
    FUN_00402a70();
  }
  ExceptionList = local_c;
  return;
}


