void FUN_00525900(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  
  cVar1 = FUN_005255e0(param_1);
  if (cVar1 != '\0') {
    FUN_00525610(param_1);
    FUN_00525720(param_1);
    if (param_1[0x19] == 0) {
      DAT_00667a28 = param_1[0x1a];
    }
    else {
      *(undefined4 *)(param_1[0x19] + 0x68) = param_1[0x1a];
    }
    if (param_1[0x1a] != 0) {
      *(undefined4 *)(param_1[0x1a] + 100) = param_1[0x19];
    }
    puVar3 = param_1;
    for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    DAT_00667a2c = DAT_00667a2c + -1;
    FUN_00525620(param_1);
    FUN_005089fd(param_1);
    return;
  }
  FUN_00525630();
  return;
}


