
undefined4 __thiscall FUN_004dc720(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x8b4) != param_2) {
    *(int *)(param_1 + 0x8b4) = param_2;
    return 1;
  }
  return 0;
}

