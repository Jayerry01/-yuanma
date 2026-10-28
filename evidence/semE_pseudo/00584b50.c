undefined4 __thiscall FUN_00584b50(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if ((-1 < param_2) && (param_2 <= *(int *)(param_1 + 0x91c))) {
    uVar1 = FUN_005598c0(*(undefined4 *)(param_1 + 0x28c + param_2 * 4));
    *(undefined4 *)(param_1 + 0x278 + param_2 * 4) = uVar1;
    uVar1 = FUN_0056b310(param_3);
    return uVar1;
  }
  return 0;
}


