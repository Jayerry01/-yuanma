void FUN_00545f10(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = param_1[0x6a];
  param_1[0x1d] = *(int *)(iVar1 + 0x10);
  iVar3 = param_1[0x13];
  param_1[0x1c] = *(int *)(iVar1 + 0x14);
  if (iVar3 == 0) {
    if (param_1[0x19] == 3) {
      *(undefined1 **)(iVar1 + 4) = &LAB_00546190;
      return;
    }
    *(undefined1 **)(iVar1 + 4) = &LAB_005460d0;
  }
  else if (iVar3 == 1) {
    if (param_1[0x19] == 3) {
      *(undefined1 **)(iVar1 + 4) = &LAB_00546370;
    }
    else {
      *(undefined1 **)(iVar1 + 4) = &LAB_00546250;
    }
    *(undefined4 *)(iVar1 + 0x30) = 0;
    if (*(char *)(iVar1 + 0x1c) == '\0') {
      FUN_00545d70(param_1);
    }
    if (*(int *)(iVar1 + 0x34) == 0) {
      FUN_00546000(param_1);
      return;
    }
  }
  else {
    if (iVar3 != 2) {
      *(undefined4 *)(*param_1 + 0x14) = 0x30;
      (**(code **)*param_1)(param_1);
      return;
    }
    puVar2 = (undefined4 *)(iVar1 + 0x44);
    *(undefined1 **)(iVar1 + 4) = &LAB_005464a0;
    *(undefined1 *)(iVar1 + 0x54) = 0;
    if (*(int *)(iVar1 + 0x44) == 0) {
      FUN_00545ed0(param_1);
    }
    iVar1 = param_1[0x17];
    iVar3 = 0;
    if (0 < param_1[0x19]) {
      do {
        FUN_0053e660(*puVar2,iVar1 * 2 + 4);
        iVar3 = iVar3 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar3 < param_1[0x19]);
      return;
    }
  }
  return;
}


