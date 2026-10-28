void __fastcall FUN_0054e890(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_4;
  
  FUN_00553830();
  DAT_00724e24 = 4;
  local_4 = 1;
  FUN_005538e0(&local_4,4);
  piVar1 = (int *)(param_1 + 4);
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 8);
  if (iVar4 != *(int *)(param_1 + 4)) {
    do {
      iVar3 = *(int *)(iVar4 + 0x14);
      if (*(char *)(iVar3 + 0x9c) == '\0') {
        FUN_0054f2d0(&DAT_00724e20,iVar3);
        FUN_0054e9a0();
        FUN_00507850(iVar3);
      }
      iVar3 = *(int *)(iVar4 + 0xc);
      if (iVar3 == 0) {
        iVar3 = *(int *)(iVar4 + 4);
        if (iVar4 == *(int *)(iVar3 + 0xc)) {
          do {
            iVar4 = iVar3;
            iVar3 = *(int *)(iVar4 + 4);
          } while (iVar4 == *(int *)(iVar3 + 0xc));
        }
        if (*(int *)(iVar4 + 0xc) != iVar3) {
          iVar4 = iVar3;
        }
      }
      else {
        for (iVar2 = *(int *)(iVar3 + 8); iVar4 = iVar3, iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
          iVar3 = iVar2;
        }
      }
    } while (iVar4 != *piVar1);
  }
  if (*(int *)(param_1 + 8) != 0) {
    iVar4 = *(int *)(*piVar1 + 4);
    while (iVar4 != 0) {
      FUN_0054f7a0(*(undefined4 *)(iVar4 + 0xc));
      iVar3 = *(int *)(iVar4 + 8);
      FUN_00402e90(iVar4,0x18);
      iVar4 = iVar3;
    }
    *(int *)(*piVar1 + 8) = *piVar1;
    *(undefined4 *)(*piVar1 + 4) = 0;
    *(int *)(*piVar1 + 0xc) = *piVar1;
    *(undefined4 *)(param_1 + 8) = 0;
  }
  FUN_00554970();
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


