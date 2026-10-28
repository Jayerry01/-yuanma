void __fastcall FUN_00478c20(undefined1 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  *(int *)(param_1 + 0x10) = iVar1 + -1;
  if (iVar1 + -1 < 1) {
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0x14)) {
      do {
        FUN_00479ee0(*(undefined4 *)(*(int *)(param_1 + 0x18) + iVar1 * 4));
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0x14));
    }
    if (*(int *)(param_1 + 0x18) != 0) {
      FUN_00507850(*(int *)(param_1 + 0x18));
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    *param_1 = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0x3d072b02;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
