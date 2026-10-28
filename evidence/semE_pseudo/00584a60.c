undefined4 __thiscall FUN_00584a60(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((-1 < param_2) && (param_2 <= *(int *)(param_1 + 0x91c))) {
    iVar1 = FUN_005598c0(*(undefined4 *)(param_1 + 0x28c + param_2 * 4));
    *(int *)(param_1 + 0x278 + param_2 * 4) = iVar1;
    if (iVar1 != 0) {
      uVar2 = FUN_0056b1d0();
      return uVar2;
    }
  }
  return 0;
}


