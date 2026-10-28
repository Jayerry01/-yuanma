undefined4 * __thiscall FUN_0054cae0(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  piVar1 = param_1 + 3;
  if (param_2 + 3 != piVar1) {
    iVar2 = param_2[4];
    puVar5 = (undefined4 *)param_2[3];
    puVar8 = (undefined4 *)*piVar1;
    uVar3 = iVar2 - (int)puVar5;
    uVar4 = param_1[4] - (int)puVar8;
    if (uVar4 < uVar3) {
      puVar7 = puVar5;
      for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      FUN_00403490((undefined1 *)((param_1[4] - *piVar1) + (int)puVar5),iVar2);
    }
    else {
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar8 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar8 = puVar8 + 1;
      }
      for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      iVar2 = param_1[4];
      iVar6 = *piVar1 + uVar3;
      if (iVar6 != iVar2) {
        FUN_005092c0(iVar6,iVar2,1);
        param_1[4] = param_1[4] + (iVar6 - iVar2);
        return param_1;
      }
    }
  }
  return param_1;
}


