void __thiscall FUN_0047c2e0(int param_1,undefined4 param_2)

{
  FUN_00474e60(param_1 + 0xb0);
  if (*(int *)(param_1 + 0xec) == 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_00475520(param_2,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 4),
                   *(undefined4 *)(param_1 + 0x68),*(int *)(param_1 + 0xc),
                   *(undefined4 *)(param_1 + 8));
      return;
    }
    FUN_004754f0(param_2,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 4),
                 *(undefined4 *)(param_1 + 8));
  }
  else if (*(int *)(param_1 + 0xec) == 1) {
    if (*(int *)(param_1 + 0xc) != 0) {
      thunk_FUN_004e8500(param_2,*(undefined4 *)(param_1 + 0x18),0,*(undefined4 *)(param_1 + 4),
                         *(undefined4 *)(param_1 + 0x68),0,*(int *)(param_1 + 0xc),
                         *(undefined4 *)(param_1 + 8));
      return;
    }
    thunk_FUN_004e8500(param_2,*(undefined4 *)(param_1 + 0x18),0,*(undefined4 *)(param_1 + 4),
                       *(undefined4 *)(param_1 + 8));
    return;
  }
  return;
}


