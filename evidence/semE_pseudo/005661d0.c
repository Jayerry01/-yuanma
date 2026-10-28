void __fastcall FUN_005661d0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 300);
  if (iVar1 != 0) {
    FUN_0056dc50();
    FUN_00507850(iVar1);
    *(undefined4 *)(param_1 + 300) = 0;
  }
  return;
}


