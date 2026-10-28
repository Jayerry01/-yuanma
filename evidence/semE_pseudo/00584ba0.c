int __thiscall FUN_00584ba0(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((-1 < param_2) && (param_2 <= *(int *)(param_1 + 0x91c))) {
    uVar1 = FUN_005598c0(*(undefined4 *)(param_1 + 0x28c + param_2 * 4));
    *(undefined4 *)(param_1 + 0x278 + param_2 * 4) = uVar1;
    if (-1 < param_3) {
      iVar2 = FUN_0056b1d0();
      if (param_3 <= iVar2) {
        return param_3 * 0x40 + param_2 * 0x140 + 0x2a0 + param_1;
      }
    }
  }
  return 0;
}


