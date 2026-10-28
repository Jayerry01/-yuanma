undefined4 * __thiscall FUN_004fea50(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined1 local_139;
  int local_138;
  int local_134;
  int local_130;
  int *local_12c;
  undefined1 local_128 [12];
  undefined4 *local_11c;
  undefined **local_118 [67];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_005a3e6a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = *param_2;
  piVar1 = param_1 + 4;
  iVar3 = 0;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  *piVar1 = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  local_134 = param_2[5];
  local_138 = param_2[4];
  local_130 = local_134 - local_138;
  local_4 = 0;
  iVar2 = local_130 + 1;
  local_12c = piVar1;
  local_11c = param_1;
  if (iVar2 == -1) {
    FUN_00402570(s_basic_string_005c42c8,&local_139);
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_00402850(local_128);
    local_118[0] = &PTR_FUN_005a83c0;
                    // WARNING: Subroutine does not return
    __CxxThrowException_8(local_118,&DAT_005b3c50);
  }
  if (iVar2 != 0) {
    iVar3 = FUN_00402bf0(iVar2);
  }
  *piVar1 = iVar3;
  param_1[5] = iVar3;
  param_1[6] = iVar3 + 1 + local_130;
  FUN_005092c0(iVar3,local_138,local_130);
  param_1[5] = (iVar3 - local_138) + local_134;
  FUN_00402a70();
  piVar1 = param_1 + 7;
  iVar3 = 0;
  *piVar1 = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  local_130 = param_2[8];
  local_138 = param_2[7];
  local_134 = local_130 - local_138;
  local_4._0_1_ = 3;
  local_4._1_3_ = 0;
  iVar2 = local_134 + 1;
  local_12c = piVar1;
  if (iVar2 != -1) {
    if (iVar2 != 0) {
      iVar3 = FUN_00402bf0(iVar2);
    }
    *piVar1 = iVar3;
    param_1[8] = iVar3;
    param_1[9] = iVar3 + 1 + local_134;
    FUN_005092c0(iVar3,local_138,local_134);
    param_1[8] = (iVar3 - local_138) + local_130;
    FUN_00402a70();
    param_1[10] = param_2[10];
    param_1[0xb] = param_2[0xb];
    ExceptionList = local_c;
    return param_1;
  }
  FUN_00402570(s_basic_string_005c42c8,&local_139);
  local_4 = CONCAT31(local_4._1_3_,4);
  FUN_00402850(local_128);
  local_118[0] = &PTR_FUN_005a83c0;
                    // WARNING: Subroutine does not return
  __CxxThrowException_8(local_118,&DAT_005b3c50);
}


