undefined4 FUN_004bd0b0(int *param_1)

{
  (**(code **)(*(int *)param_1[0x921] + 8))();
  (**(code **)(*param_1 + 0x40))(0);
  (**(code **)(*param_1 + 0xf4))();
  (**(code **)(param_1[0x922] + 0x1ac))(1);
  if (param_1[0x909] == 1) {
    FUN_00463450();
    FUN_004516d0();
    param_1[0x909] = 0;
  }
  else if (param_1[0x909] == 2) {
    FUN_00463450();
    FUN_00451e60();
    return 1;
  }
  return 1;
}


