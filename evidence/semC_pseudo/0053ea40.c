void FUN_0053ea40(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  if ((0xffdc < param_1[8]) || (0xffdc < param_1[7])) {
    *(undefined4 *)(*param_1 + 0x14) = 0x29;
    *(undefined4 *)(*param_1 + 0x18) = 0xffdc;
    (**(code **)*param_1)(param_1);
  }
  if (param_1[0x30] != 8) {
    *(undefined4 *)(*param_1 + 0x14) = 0xf;
    *(int *)(*param_1 + 0x18) = param_1[0x30];
    (**(code **)*param_1)(param_1);
  }
  if (10 < param_1[9]) {
    *(undefined4 *)(*param_1 + 0x14) = 0x1a;
    *(int *)(*param_1 + 0x18) = param_1[9];
    *(undefined4 *)(*param_1 + 0x1c) = 10;
    (**(code **)*param_1)(param_1);
  }
  iVar3 = 0;
  param_1[0x44] = 1;
  param_1[0x45] = 1;
  if (0 < param_1[9]) {
    piVar4 = (int *)(param_1[0x31] + 0xc);
    do {
      if ((((piVar4[-1] < 1) || (4 < piVar4[-1])) || (*piVar4 < 1)) || (4 < *piVar4)) {
        *(undefined4 *)(*param_1 + 0x14) = 0x12;
        (**(code **)*param_1)(param_1);
      }
      iVar1 = param_1[0x44];
      if (param_1[0x44] <= piVar4[-1]) {
        iVar1 = piVar4[-1];
      }
      param_1[0x44] = iVar1;
      iVar1 = param_1[0x45];
      if (param_1[0x45] <= *piVar4) {
        iVar1 = *piVar4;
      }
      param_1[0x45] = iVar1;
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 0x15;
    } while (iVar3 < param_1[9]);
  }
  iVar3 = 0;
  param_1[0x46] = 8;
  if (0 < param_1[9]) {
    puVar5 = (undefined4 *)(param_1[0x31] + 0x1c);
    do {
      puVar5[2] = 8;
      uVar2 = FUN_0053e5b0(puVar5[-5] * param_1[7],param_1[0x44] << 3);
      *puVar5 = uVar2;
      uVar2 = FUN_0053e5b0(puVar5[-4] * param_1[8],param_1[0x45] << 3);
      puVar5[1] = uVar2;
      uVar2 = FUN_0053e5b0(puVar5[-5] * param_1[7],param_1[0x44]);
      puVar5[3] = uVar2;
      uVar2 = FUN_0053e5b0(puVar5[-4] * param_1[8],param_1[0x45]);
      puVar5[4] = uVar2;
      *(undefined1 *)(puVar5 + 5) = 1;
      puVar5[0xc] = 0;
      iVar3 = iVar3 + 1;
      puVar5 = puVar5 + 0x15;
    } while (iVar3 < param_1[9]);
  }
  iVar3 = FUN_0053e5b0(param_1[8],param_1[0x45] << 3);
  param_1[0x47] = iVar3;
  if ((param_1[9] <= param_1[0x49]) && ((char)param_1[0x32] == '\0')) {
    *(undefined1 *)(param_1[100] + 0x10) = 0;
    return;
  }
  *(undefined1 *)(param_1[100] + 0x10) = 1;
  return;
}


