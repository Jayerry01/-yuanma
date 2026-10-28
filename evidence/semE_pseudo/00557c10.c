undefined4 __thiscall FUN_00557c10(int param_1,int param_2)

{
  if (((-1 < param_2) && (param_2 < 10)) && (*(int *)(param_1 + 0x358 + param_2 * 4) != 0)) {
    FUN_00502f50(*(undefined4 *)(param_1 + 0x5c),0);
    *(int *)(param_1 + 0x5c) = param_2;
    FUN_00502f50(param_2,1);
    *(undefined4 *)(param_1 + 0x380) = *(undefined4 *)(param_1 + 0x358 + param_2 * 4);
    return 1;
  }
  return 0;
}


