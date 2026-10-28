int * __thiscall FUN_00481230(int *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if (param_2 != param_1) {
    iVar1 = param_2[1];
    puVar4 = (undefined4 *)*param_2;
    puVar7 = (undefined4 *)*param_1;
    uVar3 = param_1[1] - (int)puVar7;
    uVar2 = iVar1 - (int)puVar4;
    if (uVar3 < uVar2) {
      puVar6 = puVar4;
      for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
      FUN_00403490((undefined1 *)((param_1[1] - *param_1) + (int)puVar4),iVar1);
    }
    else {
      for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar7 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar7 = puVar7 + 1;
      }
      for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar7 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
      iVar1 = param_1[1];
      iVar5 = *param_1 + uVar2;
      if (iVar5 != iVar1) {
        FUN_005092c0(iVar5,iVar1,1);
        param_1[1] = param_1[1] + (iVar5 - iVar1);
      }
    }
  }
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  return param_1;
}


