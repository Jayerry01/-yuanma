undefined4 __thiscall FUN_00583280(int param_1,int param_2)

{
  while( true ) {
    if (param_2 == 0) {
      return 1;
    }
    if (param_2 == param_1) break;
    param_2 = *(int *)(param_2 + 0x1e4);
  }
  return 0;
}


