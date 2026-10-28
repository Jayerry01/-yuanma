void __fastcall FUN_004975c0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = (int *)(param_1 + 0x21c4);
  iVar4 = *(int *)(*(int *)(param_1 + 0x21c4) + 8);
  if (iVar4 != *(int *)(param_1 + 0x21c4)) {
    do {
      if (*(int **)(iVar4 + 0x14) != (int *)0x0) {
        (**(code **)(**(int **)(iVar4 + 0x14) + 8))(1);
      }
      iVar3 = *(int *)(iVar4 + 0xc);
      *(undefined4 *)(iVar4 + 0x14) = 0;
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
  if (*(int *)(param_1 + 0x21c8) != 0) {
    iVar4 = *(int *)(*piVar1 + 4);
    while (iVar4 != 0) {
      FUN_0049d720(*(undefined4 *)(iVar4 + 0xc));
      iVar3 = *(int *)(iVar4 + 8);
      FUN_00402e90(iVar4,0x18);
      iVar4 = iVar3;
    }
    *(int *)(*piVar1 + 8) = *piVar1;
    *(undefined4 *)(*piVar1 + 4) = 0;
    *(int *)(*piVar1 + 0xc) = *piVar1;
    *(undefined4 *)(param_1 + 0x21c8) = 0;
  }
  return;
}


