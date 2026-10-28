
undefined4 * __thiscall FUN_0047a270(undefined4 *param_1,int *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  undefined1 local_135;
  int local_134;
  int local_130;
  int *local_12c;
  undefined4 *local_128;
  undefined1 local_124 [12];
  undefined **local_118 [67];
  void *local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = thunk_ilt_0059D2B9;
  local_c = ExceptionList;
  piVar4 = (void *)0x0;
  ExceptionList = &local_c;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  local_4 = 0;
  local_130 = param_2[1];
  local_134 = *param_2;
  iVar3 = local_130 - local_134;
  uVar2 = iVar3 + 1;
  local_128 = param_1;
  if (uVar2 != 0xffffffff) {
    if (uVar2 != 0) {
      if (uVar2 < 0x81) {
        local_12c = (int *)(&DAT_005d59a4 + (iVar3 + 8U >> 3) * 4);
        FUN_00402330();
        local_4._0_1_ = 1;
        piVar4 = (int *)*local_12c;
        if (piVar4 == (int *)0x0) {
          piVar4 = (int *)FUN_00403290(iVar3 + 8U & 0xfffffff8);
        }
        else {
          *local_12c = *piVar4;
        }
        local_4 = (uint)local_4._1_3_ << 8;
        DAT_005d59e8 = 0;
      }
      else {
        piVar4 = _malloc(uVar2);
        if (piVar4 == (void *)0x0) {
          piVar4 = (int *)FUN_00403440(uVar2);
        }
      }
    }
    *param_1 = piVar4;
    param_1[1] = piVar4;
    param_1[2] = (int)piVar4 + uVar2;
    FUN_005092c0(piVar4,local_134,iVar3);
    param_1[1] = (int)piVar4 + (local_130 - local_134);
    FUN_00402a70();
    ExceptionList = local_c;
    return param_1;
  }
  FUN_005005b0(&local_135);
  uVar2 = 0xffffffff;
  local_4._0_1_ = 2;
  pcVar5 = s_basic_string_005c42c8;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00402ac0(s_basic_string_005c42c8,s___AVlength_error_std___005c42b0 + ~uVar2 + 0x17);
  local_4 = CONCAT31(local_4._1_3_,3);
  FUN_00402850(local_124);
  local_118[0] = &PTR_FUN_005a83c0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_118,&DAT_005b3c50);
}

