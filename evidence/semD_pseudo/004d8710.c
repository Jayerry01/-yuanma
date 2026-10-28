void FUN_004d8710(int *param_1,int *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  if (param_3 != 0) {
    piVar1 = (int *)FUN_00487830();
    (**(code **)(*piVar1 + 0x308))(param_3);
  }
  iVar2 = FUN_00487830();
  if ((int *)(iVar2 + 0x2218) != param_2) {
    iVar5 = *(int *)(iVar2 + 0x221c);
    puVar6 = *(undefined4 **)(iVar2 + 0x2218);
    puVar8 = (undefined4 *)*param_2;
    uVar4 = param_2[1] - (int)puVar8;
    uVar3 = iVar5 - (int)puVar6;
    if (uVar4 < uVar3) {
      puVar7 = puVar6;
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
      FUN_00403490((undefined1 *)((param_2[1] - *param_2) + (int)puVar6),iVar5);
    }
    else {
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar8 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
      }
      for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      iVar2 = param_2[1];
      iVar5 = *param_2 + uVar3;
      if (iVar5 != iVar2) {
        FUN_005092c0(iVar5,iVar2,1);
        param_2[1] = param_2[1] + (iVar5 - iVar2);
      }
    }
  }
  iVar2 = FUN_00487830();
  if ((int *)(iVar2 + 0x220c) != param_1) {
    iVar5 = *(int *)(iVar2 + 0x2210);
    puVar6 = *(undefined4 **)(iVar2 + 0x220c);
    puVar8 = (undefined4 *)*param_1;
    uVar4 = param_1[1] - (int)puVar8;
    uVar3 = iVar5 - (int)puVar6;
    if (uVar4 < uVar3) {
      puVar7 = puVar6;
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
      FUN_00403490((undefined1 *)((param_1[1] - *param_1) + (int)puVar6),iVar5);
    }
    else {
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar8 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
      }
      for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      iVar2 = param_1[1];
      iVar5 = *param_1 + uVar3;
      if (iVar5 != iVar2) {
        FUN_005092c0(iVar5,iVar2,1);
        param_1[1] = param_1[1] + (iVar5 - iVar2);
        return;
      }
    }
  }
  return;
}


