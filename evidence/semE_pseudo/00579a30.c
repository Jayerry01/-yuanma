void __fastcall FUN_00579a30(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x138)) {
    do {
      FUN_00479ee0(*(undefined4 *)(*(int *)(param_1 + 0x144) + iVar1 * 4));
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x138));
  }
  if (*(int *)(param_1 + 0x144) != 0) {
    FUN_00507850(*(int *)(param_1 + 0x144));
    *(undefined4 *)(param_1 + 0x144) = 0;
  }
  *(undefined4 *)(param_1 + 0x138) = 0;
  return;
}


