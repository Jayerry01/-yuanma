void FUN_0054ce80(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  
  param_1 = (param_2 - param_1) / 0x18;
  if (0 < param_1) {
    piVar4 = param_3 + 3;
    piVar6 = (int *)(param_2 + 0xc);
    do {
      piVar7 = piVar6 + -6;
      piVar5 = piVar4 + -6;
      param_3[-6] = *(undefined4 *)(param_2 + -0x18);
      param_3[-5] = *(undefined4 *)(param_2 + -0x14);
      piVar4[-7] = piVar6[-7];
      if (piVar7 != piVar5) {
        iVar1 = piVar6[-5];
        puVar8 = (undefined4 *)*piVar7;
        puVar11 = (undefined4 *)*piVar5;
        uVar2 = iVar1 - (int)puVar8;
        uVar3 = piVar4[-5] - (int)puVar11;
        if (uVar3 < uVar2) {
          puVar10 = puVar8;
          for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar11 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar11 = puVar11 + 1;
          }
          for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          FUN_00403490((undefined1 *)((piVar4[-5] - *piVar5) + (int)puVar8),iVar1);
        }
        else {
          for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar11 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar11 = puVar11 + 1;
          }
          for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar11 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          iVar1 = piVar4[-5];
          iVar9 = *piVar5 + uVar2;
          if (iVar9 != iVar1) {
            FUN_005092c0(iVar9,iVar1,1);
            piVar4[-5] = piVar4[-5] + (iVar9 - iVar1);
          }
        }
      }
      param_1 = param_1 + -1;
      param_3 = param_3 + -6;
      piVar4 = piVar5;
      piVar6 = piVar7;
      param_2 = param_2 + -0x18;
    } while (param_1 != 0);
  }
  return;
}


