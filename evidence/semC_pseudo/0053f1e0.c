void FUN_0053f1e0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar4 = 0;
  iVar5 = 0;
  for (piVar2 = *(int **)(iVar1 + 0x44); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[9]) {
    if (*piVar2 == 0) {
      iVar4 = iVar4 + piVar2[3] * piVar2[2];
      iVar5 = iVar5 + piVar2[1] * piVar2[2];
    }
  }
  for (piVar2 = *(int **)(iVar1 + 0x48); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[9]) {
    if (*piVar2 == 0) {
      iVar4 = iVar4 + piVar2[3] * piVar2[2] * 0x80;
      iVar5 = iVar5 + piVar2[1] * piVar2[2] * 0x80;
    }
  }
  if (0 < iVar4) {
    iVar3 = FUN_0053ff90(param_1,iVar4,iVar5,*(undefined4 *)(iVar1 + 0x4c));
    if (iVar3 < iVar5) {
      iVar3 = iVar3 / iVar4;
      if (iVar3 < 1) {
        iVar3 = 1;
      }
    }
    else {
      iVar3 = 1000000000;
    }
    for (piVar2 = *(int **)(iVar1 + 0x44); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[9]) {
      if (*piVar2 == 0) {
        iVar4 = piVar2[1];
        if (iVar3 < (int)((iVar4 - 1U) / (uint)piVar2[3] + 1)) {
          piVar2[4] = piVar2[3] * iVar3;
          FUN_0053ffa0(param_1,piVar2 + 10,piVar2[2] * iVar4);
          *(undefined1 *)((int)piVar2 + 0x22) = 1;
        }
        else {
          piVar2[4] = iVar4;
        }
        iVar4 = FUN_0053efb0(param_1,1,piVar2[2],piVar2[4]);
        *piVar2 = iVar4;
        piVar2[5] = *(int *)(iVar1 + 0x50);
        piVar2[6] = 0;
        piVar2[7] = 0;
        *(undefined1 *)((int)piVar2 + 0x21) = 0;
      }
    }
    for (piVar2 = *(int **)(iVar1 + 0x48); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[9]) {
      if (*piVar2 == 0) {
        iVar4 = piVar2[1];
        if (iVar3 < (int)((iVar4 - 1U) / (uint)piVar2[3] + 1)) {
          piVar2[4] = piVar2[3] * iVar3;
          FUN_0053ffa0(param_1,piVar2 + 10,piVar2[2] * iVar4 * 0x80);
          *(undefined1 *)((int)piVar2 + 0x22) = 1;
        }
        else {
          piVar2[4] = iVar4;
        }
        iVar4 = FUN_0053f050(param_1,1,piVar2[2],piVar2[4]);
        *piVar2 = iVar4;
        iVar4 = *(int *)(iVar1 + 0x50);
        piVar2[6] = 0;
        piVar2[5] = iVar4;
        piVar2[7] = 0;
        *(undefined1 *)((int)piVar2 + 0x21) = 0;
      }
    }
  }
  return;
}


