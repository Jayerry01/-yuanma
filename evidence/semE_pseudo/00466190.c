undefined4 __thiscall FUN_00466190(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x2c) != 0) {
    if (*(int *)(param_1 + 0x40) == 1) {
      FUN_0040c770(*(undefined4 *)(param_1 + 0x34),param_2);
    }
    if (*(int *)(param_1 + 0x40) == 2) {
      FUN_00429de0(*(undefined4 *)(param_1 + 0x34),param_2);
    }
    *(undefined4 *)(param_1 + 0x30) = param_2;
    return 1;
  }
  *(undefined4 *)(param_1 + 0x30) = param_2;
  return 1;
}


