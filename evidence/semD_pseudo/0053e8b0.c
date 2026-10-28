void FUN_0053e8b0(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int local_4;
  
  piVar3 = param_1;
  local_4 = 0;
  if (0 < param_1[0x49]) {
    param_1 = param_1 + 0x4a;
    do {
      iVar1 = *param_1;
      if (*(int *)(iVar1 + 0x4c) == 0) {
        iVar2 = *(int *)(iVar1 + 0x10);
        if (((iVar2 < 0) || (3 < iVar2)) || (piVar3[iVar2 + 0x24] == 0)) {
          *(undefined4 *)(*piVar3 + 0x14) = 0x34;
          *(int *)(*piVar3 + 0x18) = iVar2;
          (**(code **)*piVar3)(piVar3);
        }
        puVar4 = (undefined4 *)(**(code **)piVar3[1])(piVar3,1,0x82);
        puVar6 = (undefined4 *)piVar3[iVar2 + 0x24];
        puVar7 = puVar4;
        for (iVar5 = 0x20; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        *(undefined2 *)puVar7 = *(undefined2 *)puVar6;
        *(undefined4 **)(iVar1 + 0x4c) = puVar4;
      }
      local_4 = local_4 + 1;
      param_1 = param_1 + 1;
    } while (local_4 < piVar3[0x49]);
  }
  return;
}


