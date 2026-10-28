undefined4 __thiscall FUN_00469340(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  bool bVar5;
  
  iVar3 = 0;
  if (*(int *)(param_1 + 0x68) == 0) {
    if (*(int *)(param_1 + 0x38) != 0) {
      iVar3 = FUN_00469a60(param_2);
      if (iVar3 != 0) {
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
      }
      return 1;
    }
  }
  else {
    if (*(int *)(param_1 + 0x1c) == 0) {
      return 1;
    }
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
    bVar5 = *(int *)(param_1 + 0x6c) != 0;
    if (bVar5) {
      *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + 1;
    }
    piVar2 = (int *)**(int **)(param_1 + 8);
    puVar4 = (undefined4 *)**(undefined4 **)(param_1 + 0xc);
    if (piVar2 != *(int **)(param_1 + 8)) {
      do {
        iVar1 = *(int *)(param_1 + 0x6c);
        if (iVar1 == (iVar3 - *(int *)(param_1 + 0x1c)) + 1) {
          if (iVar1 == 0) goto LAB_004693d5;
LAB_004693fb:
          if (bVar5) {
            if (iVar1 <= *(int *)(param_1 + 0x34)) {
              FUN_00466190(1);
              *(undefined4 *)(param_1 + 0x44) = puVar4[2];
              FUN_00466190(0);
            }
            if (*(int *)(param_1 + 0x6c) == *(int *)(param_1 + 0x34) + 1) {
              FUN_00466190(0);
              *(undefined4 *)(param_1 + 0x44) = 0;
            }
          }
        }
        else if (iVar1 == 0) {
LAB_004693d5:
          if (bVar5) {
            *(undefined4 *)(param_1 + 0x6c) = 1;
            FUN_00466190(1);
            *(undefined4 *)(param_1 + 0x44) = puVar4[2];
          }
          iVar1 = *(int *)(param_1 + 0x6c);
          if (iVar1 != 0) goto LAB_004693fb;
        }
        if (((*(int *)(param_1 + 0x1c) <= iVar3) &&
            (iVar3 < *(int *)(param_1 + 0x34) + *(int *)(param_1 + 0x1c))) &&
           (puVar4 != *(undefined4 **)(param_1 + 0xc))) {
          FUN_00465730(piVar2[2]);
          puVar4 = (undefined4 *)*puVar4;
        }
        piVar2 = (int *)*piVar2;
        iVar3 = iVar3 + 1;
      } while (piVar2 != (int *)*(int *)(param_1 + 8));
    }
  }
  return 0;
}


