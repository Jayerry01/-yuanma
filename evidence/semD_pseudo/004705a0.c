undefined4 __fastcall FUN_004705a0(int param_1)

{
  if (*(int *)(param_1 + 0x78) == 0) {
    FUN_00463070(DAT_005c7b60);
    (**(code **)(**(int **)(param_1 + 0x40) + 0x58))(1);
    FUN_00461e50(*(undefined4 *)(param_1 + 0x40));
    FUN_004618c0(*(undefined4 *)(param_1 + 0x40));
    FUN_0046bc80(1);
    FUN_0046b560(3);
    FUN_0046b860(&DAT_005dd374);
    *(undefined4 *)(param_1 + 0x78) = 1;
  }
  return 1;
}


