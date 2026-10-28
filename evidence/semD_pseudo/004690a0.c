undefined4 __thiscall FUN_004690a0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  iVar3 = 0;
  piVar4 = (int *)**(int **)(param_1 + 8);
  if (piVar4 != *(int **)(param_1 + 8)) {
    do {
      if (param_3 <= iVar3) {
        return 1;
      }
      if (*(int *)(param_2 + iVar3 * 4) == 0) {
        if ((undefined4 *)piVar4[2] != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)piVar4[2])(1);
        }
        piVar1 = (int *)piVar4[1];
        piVar5 = (int *)*piVar4;
        *piVar1 = (int)piVar5;
        piVar5[1] = (int)piVar1;
        FUN_00402e90(piVar4,0xc);
        iVar2 = *(int *)(param_1 + 0x6c) + -1;
        if (iVar3 < iVar2) {
          *(int *)(param_1 + 0x6c) = iVar2;
        }
        else if (iVar2 == iVar3) {
          *(undefined4 *)(param_1 + 0x6c) = 0;
        }
      }
      else {
        piVar5 = (int *)*piVar4;
      }
      iVar3 = iVar3 + 1;
      piVar4 = piVar5;
    } while (piVar5 != *(int **)(param_1 + 8));
  }
  return 1;
}


