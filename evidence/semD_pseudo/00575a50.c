undefined4 * __thiscall FUN_00575a50(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar2 = (*(int *)(param_1 + 4) - param_3) / 0x18;
  if (0 < iVar2) {
    puVar3 = param_2;
    do {
      iVar2 = iVar2 + -1;
      puVar4 = (undefined4 *)((param_3 - (int)param_2) + (int)puVar3);
      puVar5 = puVar3;
      for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar3 = puVar3 + 6;
    } while (iVar2 != 0);
  }
  iVar2 = (int)((ulonglong)((longlong)(param_3 - (int)param_2) * -0x2aaaaaab) >> 0x20);
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 0x18;
  return param_2;
}


