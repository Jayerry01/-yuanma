void FUN_005299f0(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    FUN_005255b0(0xa003);
    return;
  }
  puVar1 = (undefined4 *)FUN_00525980();
  FUN_00525610(puVar1);
  if (param_1 == 0x1004) {
    *puVar1 = *param_2;
    puVar1[1] = param_2[1];
    uVar2 = puVar1[0xd] | 2;
    puVar1[2] = param_2[2];
  }
  else if (param_1 == 0x1006) {
    puVar1[3] = *param_2;
    puVar1[4] = param_2[1];
    uVar2 = puVar1[0xd] | 4;
    puVar1[5] = param_2[2];
  }
  else {
    if (param_1 != 0x100f) {
      FUN_005255b0(0xa004);
      FUN_00525620(puVar1);
      return;
    }
    puVar1[6] = *param_2;
    puVar1[7] = param_2[1];
    puVar1[8] = param_2[2];
    puVar1[9] = param_2[3];
    puVar1[10] = param_2[4];
    uVar2 = puVar1[0xd] | 8;
    puVar1[0xb] = param_2[5];
  }
  puVar1[0xd] = uVar2;
  FUN_005260b0(puVar1,2,0);
  FUN_00525620(puVar1);
  return;
}


