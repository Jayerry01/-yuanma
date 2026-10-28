void FUN_004ebb40(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    FUN_004054e0(param_1,0x17,4);
    FUN_004054e0(param_1,0x16,1);
  }
  else {
    if (param_2 == 1) {
      FUN_004054e0(param_1,5,1);
      return;
    }
    if (param_2 == 3) {
      FUN_00405660(param_1,0x3f400000);
      FUN_004054e0(param_1,0x17,4);
      FUN_004054e0(param_1,0x16,2);
      return;
    }
  }
  return;
}


