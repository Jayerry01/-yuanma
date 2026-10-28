int __thiscall FUN_00572db0(int param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 < *(int *)(*(int *)(param_1 + 0x20) + 0x28))) {
    return *(int *)(param_1 + 0x7c) + param_2 * 0x24;
  }
  if ((49999 < param_2) && (param_2 < *(int *)(*(int *)(param_1 + 0x20) + 0x2c) + 50000)) {
    return *(int *)(param_1 + 0x80) + (param_2 * 9 + -450000) * 4;
  }
  return param_1 + 0x84;
}


