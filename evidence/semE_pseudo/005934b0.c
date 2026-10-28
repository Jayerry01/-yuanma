int __fastcall FUN_005934b0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    do {
      piVar1 = *(int **)(*(int *)(param_1 + 0x18) + iVar4 * 4);
      iVar3 = (**(code **)(*piVar1 + 4))();
      iVar2 = piVar1[2];
      *(int *)(param_1 + 8) = iVar2;
      if (iVar3 != 1) {
        if (iVar3 != 3) {
          return iVar3;
        }
        *(int *)(*(int *)(param_1 + 0x28) + 8) = iVar2;
        return 3;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x24));
  }
  return 1;
}


