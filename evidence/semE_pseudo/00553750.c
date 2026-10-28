bool __thiscall FUN_00553750(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 8) == 0) {
    return false;
  }
  iVar1 = FUN_00556030(param_2);
  if (iVar1 < 0) {
    *(undefined1 *)(param_1 + 0xc) = 1;
    *(undefined4 *)(param_1 + 0x10) = 0;
    return false;
  }
  return iVar1 != 0;
}


