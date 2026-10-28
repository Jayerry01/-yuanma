void __fastcall FUN_00497670(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int local_8;
  int iStack_4;
  
  FUN_004b48c0(&local_8);
  if (local_8 != *(int *)(param_1 + 0x2194)) {
    do {
      if (*(int **)(local_8 + 0x14) != (int *)0x0) {
        (**(code **)(**(int **)(local_8 + 0x14) + 8))(1);
      }
      *(undefined4 *)(local_8 + 0x14) = 0;
      FUN_0043c6c0();
    } while (local_8 != *(int *)(param_1 + 0x2194));
  }
  FUN_0049ba20();
  iStack_4 = *(int *)(*(int *)(param_1 + 0x21a0) + 8);
  if (iStack_4 != *(int *)(param_1 + 0x21a0)) {
    do {
      iVar4 = iStack_4;
      if (*(int **)(iStack_4 + 0x14) != (int *)0x0) {
        (**(code **)(**(int **)(iStack_4 + 0x14) + 8))(1);
      }
      *(undefined4 *)(iVar4 + 0x14) = 0;
      FUN_0043c6c0();
    } while (iStack_4 != *(int *)(param_1 + 0x21a0));
  }
  FUN_0049ba20();
  piVar3 = (int *)(param_1 + 0x21ac);
  iStack_4 = *(int *)(*(int *)(param_1 + 0x21ac) + 8);
  if (iStack_4 != *(int *)(param_1 + 0x21ac)) {
    do {
      iVar4 = iStack_4;
      if (*(int **)(iStack_4 + 0x14) != (int *)0x0) {
        (**(code **)(**(int **)(iStack_4 + 0x14) + 8))(1);
      }
      *(undefined4 *)(iVar4 + 0x14) = 0;
      FUN_0043c6c0();
    } while (iStack_4 != *piVar3);
  }
  if (*(int *)(param_1 + 0x21b0) != 0) {
    FUN_0049d720(*(undefined4 *)(*piVar3 + 4));
    *(int *)(*piVar3 + 8) = *piVar3;
    *(undefined4 *)(*piVar3 + 4) = 0;
    *(int *)(*piVar3 + 0xc) = *piVar3;
    *(undefined4 *)(param_1 + 0x21b0) = 0;
  }
  piVar3 = (int *)(param_1 + 0x21b8);
  iVar4 = *(int *)(*(int *)(param_1 + 0x21b8) + 8);
  if (iVar4 != *(int *)(param_1 + 0x21b8)) {
    do {
      if (*(int **)(iVar4 + 0x14) != (int *)0x0) {
        (**(code **)(**(int **)(iVar4 + 0x14) + 8))(1);
      }
      iVar2 = *(int *)(iVar4 + 0xc);
      *(undefined4 *)(iVar4 + 0x14) = 0;
      if (iVar2 == 0) {
        iVar2 = *(int *)(iVar4 + 4);
        if (iVar4 == *(int *)(iVar2 + 0xc)) {
          do {
            iVar4 = iVar2;
            iVar2 = *(int *)(iVar4 + 4);
          } while (iVar4 == *(int *)(iVar2 + 0xc));
        }
        if (*(int *)(iVar4 + 0xc) != iVar2) {
          iVar4 = iVar2;
        }
      }
      else {
        for (iVar1 = *(int *)(iVar2 + 8); iVar4 = iVar2, iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
          iVar2 = iVar1;
        }
      }
    } while (iVar4 != *piVar3);
  }
  if (*(int *)(param_1 + 0x21bc) != 0) {
    iVar4 = *(int *)(*piVar3 + 4);
    while (iVar4 != 0) {
      FUN_0049d720(*(undefined4 *)(iVar4 + 0xc));
      iVar2 = *(int *)(iVar4 + 8);
      FUN_00402e90(iVar4,0x18);
      iVar4 = iVar2;
    }
    *(int *)(*piVar3 + 8) = *piVar3;
    *(undefined4 *)(*piVar3 + 4) = 0;
    *(int *)(*piVar3 + 0xc) = *piVar3;
    *(undefined4 *)(param_1 + 0x21bc) = 0;
  }
  return;
}


