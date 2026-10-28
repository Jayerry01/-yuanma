undefined4 * __thiscall FUN_004f4110(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar1 = param_2;
  iVar4 = (*(int *)(param_1 + 4) - param_3) / 0xc;
  if (0 < iVar4) {
    iVar2 = param_3 - (int)param_2;
    puVar5 = param_2;
    param_2 = (undefined4 *)iVar4;
    do {
      puVar3 = (undefined4 *)(iVar2 + (int)puVar5);
      *puVar5 = *puVar3;
      puVar5[1] = puVar3[1];
      puVar5[2] = puVar3[2];
      param_2 = (undefined4 *)((int)param_2 + -1);
      puVar5 = puVar5 + 3;
    } while (param_2 != (undefined4 *)0x0);
  }
  iVar4 = (int)((ulonglong)((longlong)(param_3 - (int)puVar1) * -0x2aaaaaab) >> 0x20);
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + ((iVar4 >> 1) - (iVar4 >> 0x1f)) * 0xc;
  return puVar1;
}


