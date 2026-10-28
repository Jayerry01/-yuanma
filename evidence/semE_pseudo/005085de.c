void __thiscall FUN_005085de(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if ((*(int *)(param_1 + 4) != 0) && (*(int *)(param_1 + 0x10) != 0)) {
    FUN_00507850(*(int *)(param_1 + 0x10));
  }
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 4) = param_4;
  *(undefined4 *)(param_1 + 0x14) = param_3;
  return;
}


