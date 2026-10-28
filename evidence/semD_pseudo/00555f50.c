int __fastcall FUN_00555f50(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  if (*(int *)(param_1 + 0x5ac) != *(int *)(param_1 + 0x59c)) {
    do {
      cVar2 = FUN_00554be0();
      if (cVar2 == '\0') {
        return 0;
      }
      iVar4 = FUN_005561f0(*(undefined4 *)(*(int *)(param_1 + 0x59c) + 0x14),
                           *(undefined2 *)(*(int *)(param_1 + 0x59c) + 0x10));
      if (iVar4 < 1) {
        return iVar4;
      }
      FUN_00554cb0();
      if (*(int *)(param_1 + 0x59c) == *(int *)(param_1 + 0x5a4) + -0x18) {
        FUN_004e8500();
        FUN_00402e90(*(undefined4 *)(param_1 + 0x5a0),0x1f8);
        piVar3 = (int *)(*(int *)(param_1 + 0x5a8) + 4);
        *(int **)(param_1 + 0x5a8) = piVar3;
        iVar1 = *piVar3;
        *(int *)(param_1 + 0x5a0) = iVar1;
        *(int *)(param_1 + 0x5a4) = iVar1 + 0x1f8;
        *(undefined4 *)(param_1 + 0x59c) = *(undefined4 *)(param_1 + 0x5a0);
      }
      else {
        FUN_004e8500();
        *(int *)(param_1 + 0x59c) = *(int *)(param_1 + 0x59c) + 0x18;
      }
    } while (*(int *)(param_1 + 0x5ac) != *(int *)(param_1 + 0x59c));
  }
  return iVar4;
}


