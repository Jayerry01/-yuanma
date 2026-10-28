undefined4 __thiscall FUN_00507b94(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_00508593();
  if ((iVar1 != -1) && (iVar1 = FUN_00507d0b(), iVar1 != -1)) {
    if (*(int *)(param_1 + 8) == 0) {
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x10);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x10);
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x14);
    }
    if (param_2 != -1) {
      if ((*(int *)(param_1 + 8) == 0) && (*(uint *)(param_1 + 0x1c) < *(uint *)(param_1 + 0x20))) {
        FUN_00507c05(param_2);
      }
      else {
        iVar1 = FUN_0050b7a7(*(undefined4 *)(param_1 + 0x4c),&param_2,1);
        if (iVar1 != 1) {
          return 0xffffffff;
        }
      }
    }
    return 1;
  }
  return 0xffffffff;
}


