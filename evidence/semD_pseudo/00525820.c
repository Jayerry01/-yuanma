undefined4 * FUN_00525820(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == 0) {
    FUN_00525630(0xa001);
    return (undefined4 *)0x0;
  }
  if (DAT_00667a28 != (undefined4 *)0x0) {
    iVar4 = *(int *)((int)DAT_00667a28 + 0x68);
    iVar3 = (int)DAT_00667a28;
    while (iVar1 = iVar4, iVar1 != 0) {
      iVar3 = iVar1;
      iVar4 = *(int *)(iVar1 + 0x68);
    }
    puVar2 = _malloc(0x6c);
    *(undefined4 **)(iVar3 + 0x68) = puVar2;
    if (puVar2 != (undefined4 *)0x0) {
      for (iVar4 = 0x1b; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
      }
      *(int *)(*(int *)(iVar3 + 0x68) + 100) = iVar3;
      *(int *)(*(int *)(iVar3 + 0x68) + 0x60) = param_1;
      *(undefined1 *)(*(int *)(iVar3 + 0x68) + 0x45) = 1;
      FUN_00525640(iVar3);
      DAT_00667a2c = DAT_00667a2c + 1;
    }
    return *(undefined4 **)(iVar3 + 0x68);
  }
  DAT_00667a28 = _malloc(0x6c);
  if (DAT_00667a28 != (undefined4 *)0x0) {
    puVar2 = DAT_00667a28;
    for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    DAT_00667a28[0x18] = param_1;
    *(undefined1 *)((int)DAT_00667a28 + 0x45) = 1;
    FUN_00525640(DAT_00667a28);
    DAT_00667a2c = DAT_00667a2c + 1;
  }
  return DAT_00667a28;
}


