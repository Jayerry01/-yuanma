undefined4 __thiscall FUN_00557260(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  *(undefined4 *)(param_2 + 0x20) = param_3;
  iVar1 = 0;
  *(int *)(param_1 + 0x5d8) = *(int *)(param_1 + 0x5d8) + 1;
  if (0 < *(int *)(param_2 + 0x34)) {
    do {
      *(int *)(*(int *)(param_2 + 0x38) + iVar1 * 4) =
           *(int *)(param_1 + 0x350) + *(int *)(param_1 + 0x5d8) * 0x334;
      FUN_00557260(*(undefined4 *)(*(int *)(param_2 + 0x38) + iVar1 * 4),param_2);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_2 + 0x34));
  }
  return 1;
}


