int * __thiscall FUN_004fa650(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined1 local_135;
  int local_134;
  int local_130;
  undefined1 local_12c [12];
  int *local_120;
  int *local_11c;
  undefined **local_118 [67];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_005a3b17;
  local_c = ExceptionList;
  iVar4 = 0;
  ExceptionList = &local_c;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  local_4 = 0;
  local_130 = param_2[1];
  iVar3 = *param_2;
  local_134 = local_130 - iVar3;
  iVar1 = local_134 + 1;
  local_120 = param_1;
  if (iVar1 == -1) {
    FUN_00402570(s_basic_string_005c42c8,&local_135);
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_00402850(local_12c);
    local_118[0] = &PTR_FUN_005a83c0;
                    // WARNING: Subroutine does not return
    __CxxThrowException_8(local_118,&DAT_005b3c50);
  }
  if (iVar1 != 0) {
    iVar4 = FUN_00402bf0(iVar1);
  }
  *param_1 = iVar4;
  param_1[1] = iVar4;
  param_1[2] = iVar4 + 1 + local_134;
  FUN_005092c0(iVar4,iVar3,local_134);
  param_1[1] = (iVar4 - iVar3) + local_130;
  FUN_00402a70();
  piVar2 = param_1 + 3;
  iVar3 = 0;
  *piVar2 = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  local_130 = param_2[4];
  local_134 = param_2[3];
  iVar4 = local_130 - local_134;
  local_4._0_1_ = 3;
  local_4._1_3_ = 0;
  iVar1 = iVar4 + 1;
  local_11c = piVar2;
  if (iVar1 != -1) {
    if (iVar1 != 0) {
      iVar3 = FUN_00402bf0(iVar1);
    }
    *piVar2 = iVar3;
    param_1[4] = iVar3;
    param_1[5] = iVar3 + 1 + iVar4;
    FUN_005092c0(iVar3,local_134,iVar4);
    param_1[4] = (iVar3 - local_134) + local_130;
    FUN_00402a70();
    param_1[6] = param_2[6];
    ExceptionList = local_c;
    return param_1;
  }
  FUN_00402570(s_basic_string_005c42c8,&local_135);
  local_4 = CONCAT31(local_4._1_3_,4);
  FUN_00402850(local_12c);
  local_118[0] = &PTR_FUN_005a83c0;
                    // WARNING: Subroutine does not return
  __CxxThrowException_8(local_118,&DAT_005b3c50);
}


