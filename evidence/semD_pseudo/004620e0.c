FUN_004620e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  
  iVar1 = FUN_00463450();
  FUN_0044ef10();
  if (iVar1 != 0) {
    iVar1 = FUN_0044f0a0();
    if (iVar1 == 0) {
      iVar1 = FUN_00452af0(param_2,param_3,param_4,param_5);
      if (iVar1 == 0) {
        return 0;
      }
    }
    else {
      iVar1 = FUN_00473280();
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = FUN_00471940(param_2,param_3,param_4,param_5);
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  if (*(code **)(param_1 + 8) != (code *)0x0) {
    (**(code **)(param_1 + 8))(param_2,param_3,param_4,param_5);
  }
  return 1;
}


