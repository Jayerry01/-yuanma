int __thiscall FUN_00573920(int param_1,int param_2,int param_3)

{
  if (param_3 == 0) {
    if ((-1 < param_2) && (param_2 < *(int *)(*(int *)(param_1 + 0x28) + 0x28))) {
      return param_2 * 0x10 + *(int *)(param_1 + 0x304);
    }
    if ((49999 < param_2) && (param_2 < *(int *)(*(int *)(param_1 + 0x28) + 0x2c) + 50000)) {
      return (param_2 + -50000) * 0x10 + *(int *)(param_1 + 0x308);
    }
  }
  else {
    if ((-1 < param_2) && (param_2 < *(int *)(*(int *)(param_1 + 0x28) + 0x28))) {
      return *(int *)(param_1 + 0x304) + param_2 * 0x1c;
    }
    if ((49999 < param_2) && (param_2 < *(int *)(*(int *)(param_1 + 0x28) + 0x2c) + 50000)) {
      return *(int *)(param_1 + 0x308) + (param_2 + -50000) * 0x1c;
    }
  }
  return param_1 + 0x30c;
}


