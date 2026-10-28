int __thiscall FUN_0055c4f0(int param_1,int param_2)

{
  if (((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x28))) && (*(int *)(param_1 + 0x618) != 0))
  {
    return param_2 * 0x10 + *(int *)(param_1 + 0x618);
  }
  if (((49999 < param_2) && (param_2 < *(int *)(param_1 + 0x2c) + 50000)) &&
     (*(int *)(param_1 + 0x61c) != 0)) {
    return (param_2 + -50000) * 0x10 + *(int *)(param_1 + 0x61c);
  }
  return *(int *)(param_1 + 0x618);
}


