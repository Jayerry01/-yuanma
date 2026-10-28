void FUN_00545a70(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x58);
  param_1[0x6a] = (int)puVar1;
  *puVar1 = FUN_00545f10;
  puVar1[2] = FUN_00544120;
  puVar1[3] = &LAB_00546670;
  puVar1[0x11] = 0;
  puVar1[0xd] = 0;
  if (4 < param_1[0x19]) {
    *(undefined4 *)(*param_1 + 0x14) = 0x37;
    *(undefined4 *)(*param_1 + 0x18) = 4;
    (**(code **)*param_1)(param_1);
  }
  if (0x100 < param_1[0x15]) {
    *(undefined4 *)(*param_1 + 0x14) = 0x39;
    *(undefined4 *)(*param_1 + 0x18) = 0x100;
    (**(code **)*param_1)(param_1);
  }
  FUN_00545b10(param_1);
  FUN_00545d70(param_1);
  if (param_1[0x13] == 2) {
    FUN_00545ed0(param_1);
  }
  return;
}


