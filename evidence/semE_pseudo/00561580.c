undefined4 __thiscall FUN_00561580(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_005716d0(param_2);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x6c4) = 0;
    return 0;
  }
  FUN_0057db10(*(undefined4 *)(param_1 + 0x1e8));
  FUN_0057db40(*(undefined4 *)(param_1 + 500));
  FUN_0057d990(*(undefined4 *)(param_1 + 0x62c));
  return 1;
}


