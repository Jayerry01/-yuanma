void FUN_005404c0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int local_10;
  
  iVar1 = *(int *)(param_1 + 0x118);
  iVar2 = *(int *)(param_1 + 0x184);
  local_10 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    piVar7 = (int *)(*(int *)(param_1 + 0xc4) + 0xc);
    do {
      iVar3 = (piVar7[6] * *piVar7) / *(int *)(param_1 + 0x118);
      puVar8 = *(undefined4 **)(*(int *)(iVar2 + 0x3c) + local_10 * 4);
      if (0 < iVar3) {
        puVar6 = puVar8 + (iVar1 + 2) * iVar3;
        puVar5 = puVar8 + -iVar3;
        iVar4 = *(int *)(*(int *)(iVar2 + 0x38) + local_10 * 4) - (int)puVar8;
        puVar9 = puVar8 + (iVar1 + 1) * iVar3;
        do {
          *(undefined4 *)(iVar4 + (int)puVar5) = *(undefined4 *)(iVar4 + (int)puVar9);
          *puVar5 = *puVar9;
          *(undefined4 *)(iVar4 + (int)puVar6) = *(undefined4 *)(iVar4 + (int)puVar8);
          *puVar6 = *puVar8;
          puVar5 = puVar5 + 1;
          puVar8 = puVar8 + 1;
          puVar6 = puVar6 + 1;
          iVar3 = iVar3 + -1;
          puVar9 = puVar9 + 1;
        } while (iVar3 != 0);
      }
      local_10 = local_10 + 1;
      piVar7 = piVar7 + 0x15;
    } while (local_10 < *(int *)(param_1 + 0x24));
  }
  return;
}


