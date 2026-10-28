undefined4 __thiscall FUN_00558d40(int param_1,int param_2)

{
  if (param_2 < 50000) {
    if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x28))) {
      return 1;
    }
  }
  else if (param_2 < *(int *)(param_1 + 0x2c) + 50000) {
    return 1;
  }
  return 0;
}


