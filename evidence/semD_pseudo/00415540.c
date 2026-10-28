FUN_00415540(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  void *pvVar1;
  undefined4 uVar2;
  
  *(int *)(param_2 + 0xc) = param_5;
  if (DAT_005c431c == 0) {
    *(int *)(param_2 + 0x10) = param_6 / 2;
    *(int *)(param_2 + 8) = param_4 / 2;
  }
  else {
    *(int *)(param_2 + 0x10) = param_6;
    *(int *)(param_2 + 8) = param_4;
  }
  pvVar1 = _malloc(*(int *)(param_2 + 0x10) * param_5 * 2);
  *(void **)(param_2 + 0x34) = pvVar1;
  uVar2 = FUN_0041f6b0(0,0,0);
  *(undefined4 *)(param_2 + 0x128) = 0;
  *(undefined4 *)(param_2 + 300) = 0;
  *(undefined4 *)(param_2 + 0x130) = 0;
  *(undefined4 *)(param_2 + 0x134) = 0;
  *(undefined4 *)(param_2 + 0x2c) = uVar2;
  return 1;
}


