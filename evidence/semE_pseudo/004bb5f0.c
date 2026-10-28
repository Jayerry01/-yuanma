void __fastcall FUN_004bb5f0(int *param_1)

{
  FUN_0054a6c0(2,0,0,1);
  if (param_1[0x126] != 0) {
    (**(code **)(*param_1 + 0x1ac))(5);
    param_1[0xf0] = 0;
    return;
  }
  (**(code **)(*param_1 + 0x1ac))(param_1[0xf0]);
  param_1[0xf0] = 0;
  return;
}


