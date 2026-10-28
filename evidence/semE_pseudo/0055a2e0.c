void __thiscall FUN_0055a2e0(int param_1,int param_2,int param_3)

{
  if ((-1 < param_2) && (param_2 < 3)) {
    if ((-1 < param_3) && (param_3 < 0xd)) {
      *(int *)(param_1 + 0x120 + param_2 * 4) = param_3;
      return;
    }
    *(undefined4 *)(param_1 + 0x120 + param_2 * 4) = 0;
  }
  return;
}


