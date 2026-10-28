void FUN_00596780(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (DAT_0072c1ec == (code *)0x0) {
    FUN_0059a0a0(s_ERROR_005d3d44,param_2,param_3,param_1);
    FUN_0051274a();
  }
  else {
    (*DAT_0072c1ec)(param_1,param_2,param_3,param_4);
  }
  return;
}


