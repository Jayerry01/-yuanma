undefined4 * __thiscall FUN_00570c80(undefined4 *param_1,undefined4 param_2,char *param_3)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a5c9e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  iVar3 = FUN_00402bf0(8);
  param_1[3] = iVar3;
  param_1[4] = iVar3;
  param_1[5] = iVar3 + 8;
  local_4 = 0;
  FUN_00402a70();
  *param_1 = &PTR_LAB_005ab82c;
  param_1[1] = 0;
  param_1[2] = 0;
  piVar1 = param_1 + 6;
  local_4 = 1;
  *piVar1 = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  iVar3 = FUN_00402bf0(8);
  *piVar1 = iVar3;
  param_1[7] = iVar3;
  param_1[8] = iVar3 + 8;
  local_4._0_1_ = 3;
  FUN_00402a70();
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  uVar5 = 0xffffffff;
  *param_1 = &PTR_FUN_005ae244;
  param_1[1] = 0x26;
  pcVar9 = param_3;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar2 != '\0');
  pcVar9 = (char *)*piVar1;
  uVar6 = param_1[7] - (int)pcVar9;
  local_4 = CONCAT31(local_4._1_3_,5);
  uVar4 = (int)(param_3 + (~uVar5 - 1)) - (int)param_3;
  if (uVar6 < uVar4) {
    pcVar8 = param_3;
    for (uVar4 = uVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar9 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar9 = pcVar9 + 1;
    }
    FUN_00403490(param_3 + (param_1[7] - *piVar1),param_3 + (~uVar5 - 1));
  }
  else {
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)param_3;
      param_3 = param_3 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar9 = *param_3;
      param_3 = param_3 + 1;
      pcVar9 = pcVar9 + 1;
    }
    iVar3 = param_1[7];
    iVar7 = *piVar1 + uVar4;
    if (iVar7 != iVar3) {
      FUN_005092c0(iVar7,iVar3,1);
      param_1[7] = param_1[7] + (iVar7 - iVar3);
    }
  }
  param_1[10] = 0;
  param_1[9] = 0;
  param_1[0xc] = 0;
  param_1[0xb] = param_2;
  ExceptionList = local_c;
  return param_1;
}


