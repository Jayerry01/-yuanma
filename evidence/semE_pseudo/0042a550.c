int FUN_0042a550(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  if (param_6 < param_3) {
    return 1;
  }
  if (param_3 < param_6) {
    return -1;
  }
  if (param_5 < param_2) {
    return 1;
  }
  if (param_2 < param_5) {
    return -1;
  }
  if (param_4 < param_1) {
    return 1;
  }
  return (param_4 <= param_1) - 1;
}


