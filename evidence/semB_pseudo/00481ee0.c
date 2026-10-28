undefined4 __thiscall FUN_00481ee0(int param_1,int param_2,undefined2 param_3)

{
  if (((*(int *)(param_1 + 0xc) != 0) && (-1 < param_2)) && (param_2 < *(int *)(param_1 + 0x4c))) {
    *(undefined2 *)(*(int *)(param_1 + 0xc) + param_2 * 2) = param_3;
    return 1;
  }
  return 0;
}


