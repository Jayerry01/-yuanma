void FUN_00529730(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  
  uVar3 = FUN_00525980();
  FUN_00525610(uVar3);
  cVar2 = FUN_00528e40(param_1);
  if (cVar2 != '\0') {
    iVar1 = *(int *)(param_1 + 0xe08);
    *(undefined4 *)(param_1 + 0xe08) = 0x1012;
    *(undefined1 *)(param_1 + 0xe02) = 1;
    *(undefined1 *)(param_1 + 0xe00) = 1;
    if (iVar1 != 0x1013) {
      *(undefined4 *)(param_1 + 0xe0c) = 0;
      *(undefined4 *)(param_1 + 0xe10) = 0;
      *(undefined4 *)(param_1 + 0xe1c) = 0;
      *(undefined4 *)(param_1 + 0xe2c) = 0;
      if (*(undefined4 **)(param_1 + 0xe14) != (undefined4 *)0x0) {
        *(undefined4 *)(param_1 + 0xe0) = **(undefined4 **)(param_1 + 0xe14);
      }
    }
    *(uint *)(param_1 + 0xe30) = *(uint *)(param_1 + 0xe30) | 0x800;
    FUN_005260b0(uVar3,1,param_1);
    FUN_00525620(uVar3);
    return;
  }
  FUN_005255b0(0xa004);
  FUN_00525620(uVar3);
  return;
}


