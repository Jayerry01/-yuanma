undefined4 __thiscall FUN_0047c1e0(int param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_0047c1c0();
  *(int *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_3;
  *(int *)(param_1 + 0xc) = param_4;
  if (param_2 != 0) {
    FUN_004819b0(param_2);
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_004819b0(param_4);
  }
  if (param_2 == 0) {
    if (param_4 == 0) {
      return 1;
    }
    *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_1 + 0x60);
    return 1;
  }
  if (param_4 == 0) {
    *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_1 + 0x10);
    return 1;
  }
  if (*(int *)(param_1 + 0x10) == 1) {
    if (*(int *)(param_1 + 0x60) == 1) {
      *(undefined4 *)(param_1 + 0xec) = 1;
      return 1;
    }
    if (*(int *)(param_1 + 0x60) != 0) goto LAB_0047c265;
    FUN_004819a0(0,0);
  }
  else {
LAB_0047c265:
    if (*(int *)(param_1 + 0x10) != 0) {
      return 1;
    }
    if (*(int *)(param_1 + 0x60) != 1) {
      if (*(int *)(param_1 + 0x60) != 0) {
        return 1;
      }
      goto LAB_0047c284;
    }
    FUN_004819a0(0,1);
    param_2 = param_4;
  }
  FUN_004819b0(param_2);
LAB_0047c284:
  *(undefined4 *)(param_1 + 0xec) = 0;
  return 1;
}


