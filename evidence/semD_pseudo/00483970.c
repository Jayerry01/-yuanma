undefined4 __thiscall FUN_00483970(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x36c0c)) {
    piVar2 = (int *)(param_1 + 0x367d8);
    do {
      if ((param_2 == piVar2[-1]) && (*piVar2 != 0)) {
        puVar4 = (undefined4 *)(iVar1 * 0x20 + 0x367cc + param_1);
        puVar3 = puVar4;
        puVar5 = (undefined4 *)(param_1 + 0x36bec);
        for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar5 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar5 = puVar5 + 1;
        }
        puVar3 = (undefined4 *)(param_1 + 0x36bcc);
        for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar3 = puVar3 + 1;
        }
        return 1;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 8;
    } while (iVar1 < *(int *)(param_1 + 0x36c0c));
  }
  return 0;
}


