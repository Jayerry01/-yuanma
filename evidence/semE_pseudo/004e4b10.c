FUN_004e4b10(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uStack_8;
  
  uStack_8 = 0;
  (**(code **)(*param_1 + 0x50))(param_3,param_4);
  if (param_1[0x17] != param_1[0x18]) {
    puVar1 = (undefined4 *)(param_1[0x17] + -4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = uStack_8;
    }
    param_1[0x17] = param_1[0x17] + -4;
    return 1;
  }
  FUN_004e4da0(&uStack_8);
  return 1;
}


