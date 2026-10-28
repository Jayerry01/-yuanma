void __thiscall FUN_0047ba50(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0xd4) != param_2) {
    if (*(int *)(param_1 + 0xd4) != 0) {
      FUN_0047ba10(param_1);
    }
    *(int *)(param_1 + 0xd4) = param_2;
    if (param_2 != 0) {
      FUN_0047b9c0(param_1);
    }
    *(undefined4 *)(param_1 + 0xe0) = 1;
  }
  return;
}


