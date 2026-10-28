void __thiscall FUN_00585e30(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 local_ac [43];
  
  iVar3 = *(int *)(param_1 + 0x28c);
  puVar5 = (undefined4 *)(iVar3 + param_2 * 0xac);
  iVar1 = *(int *)(param_1 + 0x268);
  puVar4 = puVar5;
  puVar6 = local_ac;
  for (iVar2 = 0x2b; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  if (0 < iVar1) {
    puVar4 = (undefined4 *)(iVar3 + -0xac + iVar1 * 0xac);
    for (iVar2 = 0x2b; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar5 = local_ac;
    puVar4 = (undefined4 *)(*(int *)(param_1 + 0x28c) + -0xac + *(int *)(param_1 + 0x268) * 0xac);
    for (iVar3 = 0x2b; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar4 = puVar4 + 1;
    }
    *(undefined4 *)(*(int *)(param_1 + 0x28c) + -0xa8 + *(int *)(param_1 + 0x268) * 0xac) = 0;
    *(int *)(param_1 + 0x268) = *(int *)(param_1 + 0x268) + -1;
  }
  return;
}


