int * __thiscall FUN_004fb240(int *param_1,int *param_2,uint param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  uint local_12c;
  undefined1 local_125;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined **local_118 [67];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a3c44;
  local_c = ExceptionList;
  iVar7 = 0;
  local_12c = 0;
  iVar2 = *param_1;
  if (param_3 <= (uint)(param_1[1] - iVar2)) {
    local_12c = (param_1[1] - iVar2) - param_3;
    puVar4 = &local_12c;
    if (param_4 <= local_12c) {
      puVar4 = &param_4;
    }
    iVar5 = *puVar4 + iVar2 + param_3;
    local_12c = param_3 + iVar2;
    ExceptionList = &local_c;
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    local_4 = 2;
    iVar6 = iVar5 - local_12c;
    iVar2 = iVar6 + 1;
    if (iVar2 != -1) {
      if (iVar2 != 0) {
        iVar7 = FUN_00402bf0(iVar2);
      }
      *param_2 = iVar7;
      param_2[1] = iVar7;
      param_2[2] = iVar7 + 1 + iVar6;
      FUN_005092c0(iVar7,local_12c,iVar6);
      param_2[1] = (iVar7 - local_12c) + iVar5;
      FUN_00402a70();
      ExceptionList = local_c;
      return param_2;
    }
    FUN_005005b0(&local_125);
    uVar3 = 0xffffffff;
    local_4._0_1_ = 3;
    pcVar8 = s_basic_string_005c42c8;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    FUN_00402ac0(s_basic_string_005c42c8,s___AVlength_error_std___005c42b0 + ~uVar3 + 0x17);
    local_4 = CONCAT31(local_4._1_3_,4);
    FUN_0047a7a0(&local_124);
                    // WARNING: Subroutine does not return
    __CxxThrowException_8(local_118,&DAT_005b3c50);
  }
  local_124 = 0;
  local_120 = 0;
  local_11c = 0;
  local_4 = 0;
  uVar3 = 0xffffffff;
  pcVar8 = s_basic_string_005c42c8;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &local_c;
  FUN_00402ac0(s_basic_string_005c42c8,s___AVlength_error_std___005c42b0 + ~uVar3 + 0x17);
  local_4 = 1;
  FUN_00402850(&local_124);
  local_118[0] = &PTR_FUN_005ab83c;
                    // WARNING: Subroutine does not return
  __CxxThrowException_8(local_118,&DAT_005be59c);
}


