void __thiscall FUN_004c2230(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int local_c;
  
  uVar7 = 0;
  if ((-1 < (int)param_2) &&
     (param_2 < (uint)((*(int *)(param_1 + 0x500) - *(int *)(param_1 + 0x4fc)) / 0x24))) {
    iVar6 = *(int *)(param_1 + 0x500) - *(int *)(param_1 + 0x4fc);
    iVar1 = iVar6 >> 0x1f;
    if (iVar6 / 0x24 + iVar1 != iVar1) {
      local_c = 0;
      do {
        iVar6 = *(int *)(param_1 + 0x4fc);
        iVar1 = local_c + iVar6;
        for (puVar4 = *(ushort **)(local_c + 0x18 + iVar6);
            puVar4 != *(ushort **)(local_c + 0x1c + iVar6); puVar4 = puVar4 + 4) {
          if (*puVar4 == param_2) {
            if (puVar4 + 4 != *(ushort **)(iVar1 + 0x1c)) {
              FUN_004c6050(puVar4 + 4,*(ushort **)(iVar1 + 0x1c),puVar4,param_2,0);
            }
            *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + -8;
            FUN_004e8500();
            break;
          }
        }
        uVar7 = uVar7 + 1;
        local_c = local_c + 0x24;
      } while (uVar7 < (uint)((*(int *)(param_1 + 0x500) - *(int *)(param_1 + 0x4fc)) / 0x24));
    }
    iVar1 = *(int *)(param_1 + 0x4fc);
    iVar8 = param_2 * 0x24;
    iVar6 = *(int *)(iVar1 + 0x18 + iVar8);
    iVar2 = *(int *)(iVar1 + 0x1c + iVar8);
    iVar1 = iVar1 + 0x18 + iVar8;
    iVar5 = FUN_004c6050(iVar2,iVar2,iVar6,param_2,0);
    iVar3 = *(int *)(iVar1 + 4);
    for (; iVar5 != iVar3; iVar5 = iVar5 + 8) {
      FUN_004c68d0(0);
    }
    uVar7 = 0;
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + (iVar2 - iVar6 >> 3) * -8;
    iVar6 = *(int *)(param_1 + 0x500) - *(int *)(param_1 + 0x4fc);
    iVar1 = iVar6 >> 0x1f;
    if (iVar6 / 0x24 + iVar1 != iVar1) {
      do {
        FUN_004c1900(uVar7,param_2);
        uVar7 = uVar7 + 1;
      } while (uVar7 < (uint)((*(int *)(param_1 + 0x500) - *(int *)(param_1 + 0x4fc)) / 0x24));
    }
    iVar1 = *(int *)(param_1 + 0x4fc);
    uVar7 = 0;
    if (*(int *)(iVar1 + 0x1c + iVar8) - *(int *)(iVar1 + 0x18 + iVar8) >> 3 != 0) {
      do {
        FUN_004c24b0(*(undefined2 *)(*(int *)(iVar1 + 0x18 + iVar8) + uVar7 * 8));
        iVar1 = *(int *)(param_1 + 0x4fc);
        uVar7 = uVar7 + 1;
      } while (uVar7 < (uint)(*(int *)(iVar1 + 0x1c + iVar8) - *(int *)(iVar1 + 0x18 + iVar8) >> 3))
      ;
    }
    FUN_004c24b0(param_2);
    FUN_004c2a30();
  }
  return;
}


