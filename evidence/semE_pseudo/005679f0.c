void __fastcall FUN_005679f0(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x120) != 0) {
    iVar1 = FUN_00567870();
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x120) = 0;
    }
  }
  if (*(int *)(param_1 + 0x154) != 0) {
    FUN_00507850(*(int *)(param_1 + 0x154));
    *(undefined4 *)(param_1 + 0x154) = 0;
  }
  if (*(int *)(param_1 + 0x158) != 0) {
    FUN_00507850(*(int *)(param_1 + 0x158));
    *(undefined4 *)(param_1 + 0x158) = 0;
  }
  return;
}


