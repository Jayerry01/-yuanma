void __fastcall FUN_004fdd10(int param_1)

{
  *(int *)(param_1 + 0xa8) =
       *(int *)(param_1 + 0xa8) + (*(int *)(param_1 + 0xa8) - *(int *)(param_1 + 0xa4) >> 2) * -4;
  *(undefined4 *)(param_1 + 0xc4) = 0xffffffff;
  return;
}


