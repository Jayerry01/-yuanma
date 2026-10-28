void FUN_005297f0(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  
  uVar3 = FUN_00525980();
  FUN_00525610(uVar3);
  cVar2 = FUN_00528e40(param_1);
  if (cVar2 != '\0') {
    if (*(int *)(param_1 + 0xe08) != 0x1011) {
      *(undefined4 *)(param_1 + 0xe08) = 0x1014;
      *(undefined4 *)(param_1 + 0xe1c) = *(undefined4 *)(param_1 + 0xe18);
      iVar1 = *(int *)(param_1 + 0xe14);
      *(undefined1 *)(param_1 + 0xe00) = 0;
      for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
        *(undefined4 *)(iVar1 + 4) = 2;
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


