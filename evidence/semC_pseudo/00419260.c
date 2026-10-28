void FUN_00419260(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  
  iVar1 = *(int *)(param_2 + 0x38) * 6;
  if (DAT_007e0eac < iVar1) {
    DAT_007e0eac = iVar1;
    DAT_005d5adc = FUN_005099a7(DAT_005d5adc,*(int *)(param_2 + 0x38) * 0xc);
  }
  iVar4 = DAT_007eac64;
  puVar3 = DAT_007e2808;
  iVar1 = *(int *)(param_2 + 0x40);
  iVar2 = *(int *)(param_2 + 0x1c);
  DAT_005c4618 = *(int *)(iVar1 + 4);
  FUN_0041a490(param_1,1);
  iVar8 = DAT_005c4618;
  for (iVar6 = *(int *)(param_2 + 0x38); iVar6 != 0; iVar6 = iVar6 + -1) {
    DAT_005c4618 = *(int *)(iVar1 + 4);
    if (DAT_005c4618 != iVar8) {
      FUN_0041a490(param_1,1);
      iVar8 = DAT_005c4618;
    }
    DAT_005c4618 = iVar8;
    iVar8 = 0;
    if (0 < *(int *)(iVar1 + 8)) {
      piVar7 = (int *)(iVar1 + 0x10);
      do {
        iVar5 = piVar7[-1] * iVar4;
        *puVar3 = *(undefined4 *)(iVar2 + iVar5 * 4);
        puVar3[1] = *(undefined4 *)(iVar2 + 4 + iVar5 * 4);
        puVar3[2] = *(undefined4 *)(iVar2 + 8 + iVar5 * 4);
        puVar3[4] = DAT_005d5ae0;
        puVar3[5] = DAT_005d5ae4;
        puVar3[6] = *(undefined4 *)(iVar2 + 0x18 + iVar5 * 4);
        puVar3[7] = *(undefined4 *)(iVar2 + 0x1c + iVar5 * 4);
        iVar5 = *piVar7 * iVar4;
        puVar3[8] = *(undefined4 *)(iVar2 + iVar5 * 4);
        puVar3[9] = *(undefined4 *)(iVar2 + 4 + iVar5 * 4);
        puVar3[10] = *(undefined4 *)(iVar2 + 8 + iVar5 * 4);
        puVar3[0xc] = DAT_005d5ae0;
        puVar3[0xd] = DAT_005d5ae4;
        puVar3[0xe] = *(undefined4 *)(iVar2 + 0x18 + iVar5 * 4);
        puVar3[0xf] = *(undefined4 *)(iVar2 + 0x1c + iVar5 * 4);
        (**(code **)(*param_1 + 0x70))(param_1,2,0x1e2,DAT_007e2808,2,param_3);
        iVar8 = iVar8 + 1;
        piVar7 = piVar7 + 2;
      } while (iVar8 < *(int *)(iVar1 + 8));
    }
    iVar1 = iVar1 + 0xc + *(int *)(iVar1 + 8) * 8;
    iVar8 = DAT_005c4618;
  }
  DAT_005c4618 = iVar8;
  return;
}


