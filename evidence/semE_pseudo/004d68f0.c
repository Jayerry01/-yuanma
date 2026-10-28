undefined4 __thiscall FUN_004d68f0(int param_1,undefined4 param_2,uint param_3,undefined4 *param_4)

{
  int local_4;
  
  local_4 = param_1;
  FUN_0049d3c0(&local_4,&param_2);
  if (local_4 != *(int *)(param_1 + 0x10)) {
    if (param_3 < (uint)(*(int *)(local_4 + 0x18) - *(int *)(local_4 + 0x14) >> 2)) {
      *param_4 = *(undefined4 *)(*(int *)(local_4 + 0x14) + param_3 * 4);
      return 1;
    }
  }
  return 0;
}


