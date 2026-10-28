int * __thiscall FUN_004839e0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_EBX;
  int iVar4;
  int unaff_ESI;
  int unaff_EDI;
  undefined8 uVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  int *piVar9;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 local_10 [4];
  int local_c;
  
  puStack_1c = local_10;
  iVar1 = **(int **)(param_1 + 0x36c54);
  uStack_24 = *(undefined4 *)(param_1 + 0x36bec);
  uStack_20 = 1;
  uStack_28 = 0x483a04;
  local_c = param_1;
  uVar5 = FUN_00482dd0();
  uVar8 = (undefined4)((ulonglong)uVar5 >> 0x20);
  uStack_24 = (undefined4)uVar5;
  piVar9 = *(int **)(param_3 + 0x14);
  uStack_28 = 0;
  iVar1 = (**(code **)(iVar1 + 0x50))
                    (uVar8,*(undefined4 *)(param_3 + 0x10),piVar9,*(undefined4 *)(param_3 + 0x20));
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x10);
    iVar4 = 0;
    iVar3 = *(int *)(param_3 + 0x14);
    *(int **)(param_3 + 0x2c) = piVar9;
    if (0 < *(int *)(param_3 + 0x20)) {
      do {
        FUN_0047f9e0(iVar1,iVar3);
        piVar7 = (int *)0x800;
        (**(code **)(*piVar9 + 0x40))(piVar9,iVar4,&uStack_28,0);
        iVar6 = iVar1 * 4;
        uVar2 = FUN_0047f2f0(0);
        (**(code **)(unaff_EDI + 0x36c08))(iVar1,iVar3,uVar8,unaff_EBX,uVar2,iVar6);
        (**(code **)(*piVar7 + 0x44))(piVar7,iVar4);
        if (1 < iVar1) {
          iVar1 = iVar1 / 2;
        }
        if (1 < iVar3) {
          iVar3 = iVar3 / 2;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(unaff_ESI + 0x20));
    }
    return piVar9;
  }
  return (int *)0x0;
}


