void __fastcall FUN_0054a740(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  if (*(int *)(param_1 + 0x14) == 2) {
    FUN_00553830();
    DAT_0072489c = 4;
    iVar5 = 3;
    do {
      FUN_0054b0c0(&DAT_00724898);
      FUN_0054fe90(0x14);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  for (uVar6 = 0;
      uVar6 < ((*(int *)(param_1 + 0x10c) - *(int *)(param_1 + 0x104)) / 0x18 +
              (*(int *)(param_1 + 0x114) - *(int *)(param_1 + 0x118)) / 0x18 +
              (*(int *)(param_1 + 0x120) - *(int *)(param_1 + 0x110) >> 2) * 0x15) - 0x15U;
      uVar6 = uVar6 + 1) {
    FUN_004e6050(param_1 + 0x104);
    uVar2 = FUN_0054c2c0(uVar6);
    FUN_004e6050(uVar2);
    FUN_00554cb0();
  }
  piVar4 = (int *)(*(int *)(param_1 + 0x110) + 4);
  if (piVar4 < *(int **)(param_1 + 0x120)) {
    do {
      iVar7 = *piVar4;
      iVar5 = iVar7 + 0x1f8;
      for (; iVar7 != iVar5; iVar7 = iVar7 + 0x18) {
        FUN_004c68d0(0);
      }
      FUN_00402e90(*piVar4,0x1f8);
      piVar4 = piVar4 + 1;
    } while (piVar4 < *(int **)(param_1 + 0x120));
  }
  iVar5 = *(int *)(param_1 + 0x104);
  if (*(int *)(param_1 + 0x110) == *(int *)(param_1 + 0x120)) {
    iVar7 = *(int *)(param_1 + 0x114);
    for (; iVar5 != iVar7; iVar5 = iVar5 + 0x18) {
      FUN_004e8500();
    }
  }
  else {
    iVar7 = *(int *)(param_1 + 0x10c);
    for (; iVar5 != iVar7; iVar5 = iVar5 + 0x18) {
      FUN_004c68d0(0);
    }
    iVar5 = *(int *)(param_1 + 0x114);
    for (iVar7 = *(int *)(param_1 + 0x118); iVar7 != iVar5; iVar7 = iVar7 + 0x18) {
      FUN_004c68d0(0);
    }
    FUN_00402e90(*(undefined4 *)(param_1 + 0x118),0x1f8);
  }
  *(undefined4 *)(param_1 + 0x114) = *(undefined4 *)(param_1 + 0x104);
  *(undefined4 *)(param_1 + 0x118) = *(undefined4 *)(param_1 + 0x108);
  *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)(param_1 + 0x10c);
  *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(param_1 + 0x110);
  for (uVar6 = 0;
      uVar6 < ((*(int *)(param_1 + 0x13c) - *(int *)(param_1 + 0x140)) / 0x18 +
              (*(int *)(param_1 + 0x134) - *(int *)(param_1 + 300)) / 0x18 +
              (*(int *)(param_1 + 0x148) - *(int *)(param_1 + 0x138) >> 2) * 0x15) - 0x15U;
      uVar6 = uVar6 + 1) {
    FUN_004e6050(param_1 + 300);
    uVar2 = FUN_0054c2c0(uVar6);
    FUN_004e6050(uVar2);
    FUN_00554cb0();
  }
  piVar4 = (int *)(*(int *)(param_1 + 0x138) + 4);
  if (piVar4 < *(int **)(param_1 + 0x148)) {
    do {
      iVar7 = *piVar4;
      iVar5 = iVar7 + 0x1f8;
      for (; iVar7 != iVar5; iVar7 = iVar7 + 0x18) {
        FUN_004c68d0(0);
      }
      FUN_00402e90(*piVar4,0x1f8);
      piVar4 = piVar4 + 1;
    } while (piVar4 < *(int **)(param_1 + 0x148));
  }
  iVar5 = *(int *)(param_1 + 300);
  if (*(int *)(param_1 + 0x138) == *(int *)(param_1 + 0x148)) {
    iVar7 = *(int *)(param_1 + 0x13c);
    for (; iVar5 != iVar7; iVar5 = iVar5 + 0x18) {
      FUN_004e8500();
    }
  }
  else {
    iVar7 = *(int *)(param_1 + 0x134);
    for (; iVar5 != iVar7; iVar5 = iVar5 + 0x18) {
      FUN_004c68d0(0);
    }
    iVar5 = *(int *)(param_1 + 0x13c);
    for (iVar7 = *(int *)(param_1 + 0x140); iVar7 != iVar5; iVar7 = iVar7 + 0x18) {
      FUN_004e8500();
    }
    FUN_00402e90(*(undefined4 *)(param_1 + 0x140),0x1f8);
  }
  *(undefined4 *)(param_1 + 0x13c) = *(undefined4 *)(param_1 + 300);
  *(undefined4 *)(param_1 + 0x140) = *(undefined4 *)(param_1 + 0x130);
  *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(param_1 + 0x134);
  *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(param_1 + 0x138);
  iVar5 = *(int *)(param_1 + 0x14c);
  iVar7 = *(int *)(param_1 + 0x150);
  iVar3 = FUN_0054cd90(iVar7,iVar7,iVar5,iVar5,0);
  iVar1 = *(int *)(param_1 + 0x150);
  for (; iVar3 != iVar1; iVar3 = iVar3 + 0x18) {
    FUN_0054d0c0(0);
  }
  iVar5 = (int)((ulonglong)((longlong)(iVar7 - iVar5) * -0x2aaaaaab) >> 0x20);
  *(int *)(param_1 + 0x150) = *(int *)(param_1 + 0x150) + ((iVar5 >> 2) - (iVar5 >> 0x1f)) * 0x18;
  FUN_00554970();
  FUN_005544a0();
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 0x1c) = 1;
  return;
}


