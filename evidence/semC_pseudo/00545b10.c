void FUN_00545b10(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined1 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  int iStack_20;
  int *piStack_1c;
  int iStack_18;
  
  piVar3 = param_1;
  iVar1 = param_1[0x6a];
  piStack_1c = (int *)(iVar1 + 0x20);
  iVar5 = FUN_00545c70(param_1,piStack_1c);
  if (param_1[0x19] == 3) {
    iVar7 = *param_1;
    *(int *)(iVar7 + 0x18) = iVar5;
    *(int *)(iVar7 + 0x1c) = *piStack_1c;
    *(undefined4 *)(iVar7 + 0x20) = *(undefined4 *)(iVar1 + 0x24);
    *(undefined4 *)(iVar7 + 0x24) = *(undefined4 *)(iVar1 + 0x28);
    *(undefined4 *)(*param_1 + 0x14) = 0x5e;
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 0x5f;
    *(int *)(*param_1 + 0x18) = iVar5;
  }
  (**(code **)(*param_1 + 4))(param_1,1);
  piVar6 = (int *)(**(code **)(param_1[1] + 8))(param_1,1,iVar5,param_1[0x19]);
  iStack_20 = 0;
  iVar7 = iVar5;
  piVar12 = piVar6;
  if (0 < param_1[0x19]) {
    do {
      iVar2 = *piStack_1c;
      iVar8 = iVar7 / iVar2;
      iStack_18 = 0;
      if (0 < iVar2) {
        param_1 = (int *)0x0;
        do {
          uVar4 = FUN_00545d50(piVar3,iStack_20,iStack_18,iVar2 + -1);
          for (iVar10 = (int)param_1; iVar10 < iVar5; iVar10 = iVar10 + iVar7) {
            iVar9 = 0;
            if (0 < iVar8) {
              do {
                iVar11 = *piVar12 + iVar9;
                iVar9 = iVar9 + 1;
                *(undefined1 *)(iVar10 + iVar11) = uVar4;
              } while (iVar9 < iVar8);
            }
          }
          param_1 = (int *)((int)param_1 + iVar8);
          iStack_18 = iStack_18 + 1;
        } while (iStack_18 < iVar2);
      }
      piStack_1c = piStack_1c + 1;
      iStack_20 = iStack_20 + 1;
      iVar7 = iVar8;
      piVar12 = piVar12 + 1;
    } while (iStack_20 < piVar3[0x19]);
    *(int *)(iVar1 + 0x14) = iVar5;
    *(int **)(iVar1 + 0x10) = piVar6;
    return;
  }
  *(int **)(iVar1 + 0x10) = piVar6;
  *(int *)(iVar1 + 0x14) = iVar5;
  return;
}


