undefined4 __fastcall FUN_00567870(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = iVar1 + -1;
  if (iVar1 + -1 < 1) {
    FUN_00567500();
    FUN_00507850(param_1);
    return 1;
  }
  return 0;
}


