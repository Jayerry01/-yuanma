void __thiscall FUN_0054b500(int param_1,float param_2,undefined4 param_3)

{
  *(undefined1 *)(param_1 + 0xf8) = 1;
  if (0.0 <= param_2) {
    if (1.0 < param_2) {
      param_2 = 1.0;
    }
  }
  else {
    param_2 = 0.0;
  }
  *(undefined4 *)(param_1 + 0xf4) = param_3;
  *(float *)(param_1 + 0xf0) = param_2;
  FUN_00554650(param_2);
  return;
}


