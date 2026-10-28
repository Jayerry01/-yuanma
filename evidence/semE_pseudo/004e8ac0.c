void __fastcall FUN_004e8ac0(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_005ab150;
  if (param_1[1] != 0) {
    FUN_004e8b60();
  }
  FUN_00507850(param_1[10]);
  piVar1 = (int *)param_1[2];
  param_1[10] = 0;
  if (*piVar1 == 0) {
    FUN_00507850(piVar1);
    param_1[2] = 0;
    return;
  }
  *piVar1 = *piVar1 + -1;
  return;
}


