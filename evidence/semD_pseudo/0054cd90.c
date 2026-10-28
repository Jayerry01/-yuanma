void FUN_0054cd90(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  param_2 = (param_2 - (int)param_1) / 0x18;
  if (0 < param_2) {
    piVar4 = param_3 + 3;
    piVar5 = param_1 + 3;
    do {
      *param_3 = *param_1;
      param_3[1] = param_1[1];
      piVar4[-1] = piVar5[-1];
      if (piVar5 != piVar4) {
        iVar1 = piVar5[1];
        puVar6 = (undefined4 *)*piVar5;
        puVar9 = (undefined4 *)*piVar4;
        uVar2 = iVar1 - (int)puVar6;
        uVar3 = piVar4[1] - (int)puVar9;
        if (uVar3 < uVar2) {
          puVar8 = puVar6;
          for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          }
          for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar9 = (undefined4 *)((int)puVar9 + 1);
          }
          FUN_00403490((undefined1 *)((piVar4[1] - *piVar4) + (int)puVar6),iVar1);
        }
        else {
          for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar9 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar9 = puVar9 + 1;
          }
          for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar9 = *(undefined1 *)puVar6;
            puVar6 = (undefined4 *)((int)puVar6 + 1);
            puVar9 = (undefined4 *)((int)puVar9 + 1);
          }
          iVar1 = piVar4[1];
          iVar7 = *piVar4 + uVar2;
          if (iVar7 != iVar1) {
            FUN_005092c0(iVar7,iVar1,1);
            piVar4[1] = piVar4[1] + (iVar7 - iVar1);
          }
        }
      }
      param_1 = param_1 + 6;
      piVar5 = piVar5 + 6;
      param_3 = param_3 + 6;
      piVar4 = piVar4 + 6;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}


