void __fastcall FUN_00593410(int param_1)

{
  int iVar1;
  
  FUN_0050ac20(s_List___d_items_005d36c4,*(undefined4 *)(param_1 + 0x24));
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    do {
      (**(code **)(**(int **)(*(int *)(param_1 + 0x18) + iVar1 * 4) + 8))();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x24));
  }
  return;
}


