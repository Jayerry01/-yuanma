void __thiscall FUN_0055a280(int param_1,float param_2)

{
  if (param_2 <= 1.0) {
    if (param_2 < 0.0) {
      param_2 = 0.0;
    }
  }
  else {
    param_2 = 1.0;
  }
  *(float *)(param_1 + 0x50) = param_2;
  FUN_0047dd50(1.0 - param_2,param_2,0,0x3f800000);
  return;
}


