void FUN_00545d70(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  int iVar10;
  int local_14;
  int *piStack_10;
  char cStack_c;
  
  iVar1 = *(int *)(param_1 + 0x1a8);
  if (*(int *)(param_1 + 0x4c) == 1) {
    local_14 = 0x1fe;
    *(undefined1 *)(iVar1 + 0x1c) = 1;
  }
  else {
    local_14 = 0;
    *(undefined1 *)(iVar1 + 0x1c) = 0;
  }
  uVar3 = (**(code **)(*(int *)(param_1 + 4) + 8))
                    (param_1,1,local_14 + 0x100,*(undefined4 *)(param_1 + 100));
  *(undefined4 *)(iVar1 + 0x18) = uVar3;
  iVar4 = *(int *)(iVar1 + 0x14);
  iVar10 = 0;
  if (0 < *(int *)(param_1 + 100)) {
    piStack_10 = (int *)(iVar1 + 0x20);
    do {
      iVar7 = *piStack_10;
      iVar4 = iVar4 / iVar7;
      if (local_14 != 0) {
        *(int *)(*(int *)(iVar1 + 0x18) + iVar10 * 4) =
             *(int *)(*(int *)(iVar1 + 0x18) + iVar10 * 4) + 0xff;
      }
      iVar6 = 0;
      iVar7 = iVar7 + -1;
      puVar2 = *(undefined1 **)(*(int *)(iVar1 + 0x18) + iVar10 * 4);
      iVar5 = FUN_00545eb0(param_1,iVar10,0,iVar7);
      iVar8 = 0;
      do {
        while (iVar5 < iVar8) {
          iVar6 = iVar6 + 1;
          iVar5 = FUN_00545eb0(param_1,iVar10,iVar6,iVar7);
        }
        cStack_c = (char)iVar4;
        puVar2[iVar8] = cStack_c * (char)iVar6;
        iVar8 = iVar8 + 1;
      } while (iVar8 < 0x100);
      if (local_14 != 0) {
        iVar7 = 1;
        puVar9 = puVar2;
        do {
          puVar9 = puVar9 + -1;
          iVar5 = iVar7 + 1;
          *puVar9 = *puVar2;
          puVar2[iVar7 + 0xff] = puVar2[0xff];
          iVar7 = iVar5;
        } while (iVar5 < 0x100);
      }
      iVar10 = iVar10 + 1;
      piStack_10 = piStack_10 + 1;
    } while (iVar10 < *(int *)(param_1 + 100));
  }
  return;
}


