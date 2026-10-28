void FUN_0041a230(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  if ((*(int *)(DAT_005d5a0c + 0x718) != 0) &&
     (*(int *)(DAT_005d5a0c + 0x71c) != *(int *)(param_3 + 0xc0))) {
    *(int *)(DAT_005d5a0c + 0x71c) = *(int *)(param_3 + 0xc0);
    FUN_0041a9b0(param_2,*(undefined4 *)(DAT_005d5a0c + 0x71c));
  }
  iVar3 = *(int *)(param_3 + 0xd0);
  if (DAT_007e2700 != iVar3) {
    DAT_007e2700 = iVar3;
    FUN_0041a970(param_1,4,iVar3);
  }
  iVar3 = *(int *)(param_3 + 0xcc);
  if (DAT_007e2778 != iVar3) {
    DAT_007e2778 = iVar3;
    if (iVar3 == 0) {
      FUN_0041a990(param_1,0,0x11,1);
      uVar4 = 1;
    }
    else {
      FUN_0041a990(param_1,0,0x11,2);
      uVar4 = 2;
    }
    FUN_0041a990(param_1,0,0x10,uVar4);
  }
  iVar3 = *(int *)(param_3 + 0xd4);
  if (DAT_007e2324 != iVar3) {
    if (iVar3 == 0) {
      uVar4 = 1;
    }
    else {
      uVar4 = 2;
    }
    DAT_007e2324 = iVar3;
    FUN_0041a970(param_1,9,uVar4);
  }
  iVar3 = *(int *)(param_3 + 0xd8);
  if (DAT_007e2774 != iVar3) {
    DAT_007e2774 = iVar3;
    FUN_0041a970(param_1,0x1a,iVar3);
  }
  iVar3 = *(int *)(param_3 + 0xe0);
  if (DAT_007e2bc4 != iVar3) {
    DAT_007e2bc4 = iVar3;
    FUN_0041a970(param_1,0x1d,iVar3);
  }
  iVar3 = *(int *)(param_3 + 0xdc);
  if (DAT_007e0dc0 != iVar3) {
    DAT_007e0dc0 = iVar3;
    FUN_0041a970(param_1,2,iVar3);
  }
  iVar3 = *(int *)(param_3 + 0xc4);
  if (DAT_007e24e4 != iVar3) {
    DAT_007e24e4 = iVar3;
    FUN_0041a970(param_1,7,iVar3);
  }
  iVar3 = *(int *)(param_3 + 200);
  if (DAT_007e276c != iVar3) {
    DAT_007e276c = iVar3;
    FUN_0041a970(param_1,0xe,iVar3);
  }
  iVar3 = 0;
  if (0 < DAT_005c4328) {
    piVar2 = (int *)(param_3 + 0xe4);
    do {
      iVar1 = *piVar2;
      if ((&DAT_007e3360)[iVar3] != iVar1) {
        (&DAT_007e3360)[iVar3] = iVar1;
        if (iVar1 == 2) {
          uVar4 = 3;
        }
        else {
          uVar4 = 1;
        }
        FUN_0041a990(param_1,iVar3,0xc,uVar4);
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar3 < DAT_005c4328);
  }
  return;
}


