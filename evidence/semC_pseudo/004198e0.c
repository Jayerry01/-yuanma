void FUN_004198e0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 unaff_retaddr;
  undefined4 uVar6;
  int iVar7;
  
  piVar3 = param_1;
  iVar1 = *(int *)(param_2 + 0x50);
  FUN_0041a970(param_1,0x13,1);
  FUN_0041a970(param_1,0x14,3);
  FUN_00415330(0x3f800000,0x3f800000,0x3f800000);
  piVar4 = *(int **)(iVar1 + 0x10);
  iVar7 = *(int *)(iVar1 + 0xc);
  DAT_005c4618 = *piVar4;
  FUN_0041a490(param_1,1);
  if (0 < iVar7) {
    param_2 = 0;
    param_1 = (int *)iVar7;
    do {
      FUN_0041a970(piVar3,0x1b,0);
      FUN_0041a990(piVar3,0,0xc,1);
      FUN_0041a970(piVar3,0xe,0);
      if (DAT_005c4618 != *piVar4) {
        DAT_005c4618 = *piVar4;
        FUN_0041a490(piVar3,1);
      }
      iVar5 = *(int *)(iVar1 + 4) + param_2;
      iVar7 = *(int *)(*(int *)((&DAT_007e5be0)[DAT_005c4618] + 0x34) + 0x40);
      if (iVar7 == 0) {
        FUN_004157e0(*(int *)((&DAT_007e5be0)[DAT_005c4618] + 0x34));
        (**(code **)(*piVar3 + 0x98))
                  (piVar3,0,*(undefined4 *)(*(int *)((&DAT_007e5be0)[DAT_005c4618] + 0x34) + 0x40));
      }
      else {
        (**(code **)(*piVar3 + 0x98))(piVar3,0,iVar7);
      }
      *(undefined4 *)(*(int *)((&DAT_007e5be0)[DAT_005c4618] + 0x34) + 0x34) = 0;
      if (piVar4[2] == 0) {
        iVar7 = 6;
        uVar6 = 4;
        (**(code **)(*piVar3 + 0x74))(piVar3,4,0x112,iVar5,4,&DAT_005c45b4,6,unaff_retaddr);
      }
      else {
        iVar7 = 0xc;
        uVar6 = 4;
        (**(code **)(*piVar3 + 0x74))(piVar3,4,0x112,iVar5,4,&DAT_005c45c0,0xc,unaff_retaddr);
      }
      FUN_0041a970(piVar3,0x1b,1);
      FUN_0041a990(piVar3,0,0xc,3);
      FUN_0041a970(piVar3,0xe,1);
      iVar7 = *(int *)(iVar1 + 8) + iVar7;
      iVar5 = *(int *)(*(int *)(iVar1 + 0x18) + piVar4[1] * 4);
      iVar2 = *(int *)(iVar5 + 0x40);
      if (iVar2 == 0) {
        FUN_004157e0(iVar5);
        (**(code **)(*piVar3 + 0x98))
                  (piVar3,0,*(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x18) + piVar4[1] * 4) + 0x40)
                  );
      }
      else {
        (**(code **)(*piVar3 + 0x98))(piVar3,0,iVar2);
      }
      *(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x18) + piVar4[1] * 4) + 0x34) = 0;
      if (piVar4[2] == 0) {
        (**(code **)(*piVar3 + 0x74))(piVar3,4,0x112,iVar7,4,&DAT_005c45b4,6,uVar6);
      }
      else {
        (**(code **)(*piVar3 + 0x74))(piVar3,4,0x112,iVar7,4,&DAT_005c45c0,0xc,uVar6);
      }
      piVar4 = piVar4 + 7;
      param_2 = param_2 + 0x80;
      param_1 = (int *)((int)param_1 + -1);
    } while (param_1 != (int *)0x0);
  }
  DAT_007e3360 = 2;
  FUN_0041a970(piVar3,0x13,DAT_007e0eb4);
  FUN_0041a970(piVar3,0x14,DAT_007e0404);
  FUN_00415330();
  return;
}


