undefined4 __thiscall FUN_00469640(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  iVar2 = param_2;
  iVar4 = 0;
  *(undefined4 *)(param_1 + 0x74) = 1;
  if (*(int *)(param_1 + 0x3c) != 0) {
    FUN_00429de0(*(int *)(param_1 + 0x3c),param_2);
  }
  if (*(int *)(param_1 + 0x68) == 0) {
    piVar5 = (int *)**(int **)(param_1 + 8);
    if (piVar5 != *(int **)(param_1 + 8)) {
      do {
        if (((*(int *)(param_1 + 0x1c) <= iVar4) &&
            (iVar4 < *(int *)(param_1 + 0x34) + *(int *)(param_1 + 0x1c))) &&
           ((int *)piVar5[2] != (int *)0x0)) {
          (**(code **)(*(int *)piVar5[2] + 0xc))(iVar2);
        }
        piVar5 = (int *)*piVar5;
        iVar4 = iVar4 + 1;
      } while (piVar5 != (int *)*(int *)(param_1 + 8));
    }
  }
  else {
    param_2 = 0;
    piVar5 = (int *)**(int **)(param_1 + 0xc);
    FUN_0046ef50(**(undefined4 **)(param_1 + 8),*(undefined4 **)(param_1 + 8),&param_2);
    if (*(int *)(param_1 + 0x34) < param_2) {
      if (piVar5 != *(int **)(param_1 + 0xc)) {
        do {
          (**(code **)(*(int *)piVar5[2] + 0xc))(iVar2);
          piVar5 = (int *)*piVar5;
        } while (piVar5 != (int *)*(int *)(param_1 + 0xc));
      }
    }
    else {
      iVar4 = param_2;
      if (0 < param_2) {
        do {
          (**(code **)(*(int *)piVar5[2] + 0xc))(iVar2);
          piVar5 = (int *)*piVar5;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
    }
  }
  iVar4 = *(int *)(*(int *)(param_1 + 0x10) + 8);
  if (iVar4 != *(int *)(param_1 + 0x10)) {
    do {
      (**(code **)(**(int **)(iVar4 + 0x14) + 0xc))(iVar2);
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
        for (iVar1 = *(int *)(iVar3 + 8); iVar4 = iVar3, iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
          iVar3 = iVar1;
        }
      }
    } while (iVar4 != *(int *)(param_1 + 0x10));
  }
  if (*(int **)(param_1 + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x38) + 0xc))(iVar2);
  }
  *(int *)(param_1 + 0x40) = iVar2;
  return 1;
}


