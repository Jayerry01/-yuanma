void FUN_005448f0(int *param_1,char param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = param_1[0x6a];
  iVar2 = *(int *)(iVar1 + 0x18);
  if (param_1[0x13] != 0) {
    param_1[0x13] = 2;
  }
  if (param_2 == '\0') {
    if (param_1[0x13] == 2) {
      *(undefined1 **)(iVar1 + 4) = &LAB_00544fb0;
    }
    else {
      *(undefined1 **)(iVar1 + 4) = &LAB_00544a90;
    }
    *(code **)(iVar1 + 8) = FUN_00544120;
    iVar4 = param_1[0x1c];
    if (iVar4 < 1) {
      *(undefined4 *)(*param_1 + 0x14) = 0x38;
      *(undefined4 *)(*param_1 + 0x18) = 1;
      (**(code **)*param_1)(param_1);
    }
    if (0x100 < iVar4) {
      *(undefined4 *)(*param_1 + 0x14) = 0x39;
      *(undefined4 *)(*param_1 + 0x18) = 0x100;
      (**(code **)*param_1)(param_1);
    }
    if (param_1[0x13] == 2) {
      iVar4 = (param_1[0x17] + 2) * 6;
      if (*(int *)(iVar1 + 0x20) == 0) {
        uVar3 = (**(code **)(param_1[1] + 4))(param_1,1,iVar4);
        *(undefined4 *)(iVar1 + 0x20) = uVar3;
      }
      FUN_0053e660(*(undefined4 *)(iVar1 + 0x20),iVar4);
      if (*(int *)(iVar1 + 0x28) == 0) {
        FUN_00544850(param_1);
      }
      *(undefined1 *)(iVar1 + 0x24) = 0;
    }
  }
  else {
    *(undefined1 **)(iVar1 + 4) = &LAB_00544a10;
    *(undefined1 **)(iVar1 + 8) = &LAB_005452a0;
    *(undefined1 *)(iVar1 + 0x1c) = 1;
  }
  if (*(char *)(iVar1 + 0x1c) != '\0') {
    iVar4 = 0;
    do {
      FUN_0053e660(*(undefined4 *)(iVar2 + iVar4 * 4),0x1000);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x20);
    *(undefined1 *)(iVar1 + 0x1c) = 0;
  }
  return;
}


