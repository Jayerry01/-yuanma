void __fastcall FUN_00555c10(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  for (uVar2 = 0;
      uVar2 < ((*(int *)(param_1 + 0x5ac) - *(int *)(param_1 + 0x5b0)) / 0x18 +
              (*(int *)(param_1 + 0x5a4) - *(int *)(param_1 + 0x59c)) / 0x18 +
              (*(int *)(param_1 + 0x5b8) - *(int *)(param_1 + 0x5a8) >> 2) * 0x15) - 0x15U;
      uVar2 = uVar2 + 1) {
    FUN_0054c2c0(uVar2);
    FUN_00554cb0();
  }
  piVar1 = (int *)(*(int *)(param_1 + 0x5a8) + 4);
  if (piVar1 < *(int **)(param_1 + 0x5b8)) {
    do {
      iVar3 = *piVar1;
      iVar4 = iVar3 + 0x1f8;
      for (; iVar3 != iVar4; iVar3 = iVar3 + 0x18) {
        FUN_004e8500();
      }
      FUN_00402e90(*piVar1,0x1f8);
      piVar1 = piVar1 + 1;
    } while (piVar1 < *(int **)(param_1 + 0x5b8));
  }
  iVar4 = *(int *)(param_1 + 0x59c);
  if (*(int *)(param_1 + 0x5a8) == *(int *)(param_1 + 0x5b8)) {
    iVar3 = *(int *)(param_1 + 0x5ac);
    for (; iVar4 != iVar3; iVar4 = iVar4 + 0x18) {
      FUN_004e8500();
    }
  }
  else {
    iVar3 = *(int *)(param_1 + 0x5a4);
    for (; iVar4 != iVar3; iVar4 = iVar4 + 0x18) {
      FUN_004e8500();
    }
    iVar4 = *(int *)(param_1 + 0x5ac);
    for (iVar3 = *(int *)(param_1 + 0x5b0); iVar3 != iVar4; iVar3 = iVar3 + 0x18) {
      FUN_004e8500();
    }
    FUN_00402e90(*(undefined4 *)(param_1 + 0x5b0),0x1f8);
  }
  *(undefined4 *)(param_1 + 0x5ac) = *(undefined4 *)(param_1 + 0x59c);
  *(undefined4 *)(param_1 + 0x5b0) = *(undefined4 *)(param_1 + 0x5a0);
  *(undefined4 *)(param_1 + 0x5b4) = *(undefined4 *)(param_1 + 0x5a4);
  *(undefined4 *)(param_1 + 0x5b8) = *(undefined4 *)(param_1 + 0x5a8);
  *(undefined4 *)(param_1 + 0x590) = 0;
  FUN_00553830();
  *(undefined4 *)(param_1 + 0x58c) = 0;
  return;
}


