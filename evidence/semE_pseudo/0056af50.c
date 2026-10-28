undefined4 __thiscall FUN_0056af50(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x120) != 0) {
    iVar1 = FUN_0056aee0(param_2);
    if (((iVar1 != 0) && (-1 < param_3)) && (param_3 < 3)) {
      uVar2 = FUN_0056af20(*(undefined4 *)(iVar1 + 0x10 + param_3 * 4));
      return uVar2;
    }
  }
  return 0;
}


