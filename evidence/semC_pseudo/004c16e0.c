void __thiscall FUN_004c16e0(int param_1,uint param_2)

{
  ushort *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  uint unaff_EBP;
  uint uVar5;
  int iVar6;
  int local_4;
  
  uVar5 = 0;
  if ((-1 < (int)param_2) &&
     (param_2 < (uint)((*(int *)(param_1 + 0x500) - *(int *)(param_1 + 0x4fc)) / 0x24))) {
    iVar2 = *(int *)(param_1 + 0x500) - *(int *)(param_1 + 0x4fc);
    iVar4 = iVar2 >> 0x1f;
    if (iVar2 / 0x24 + iVar4 != iVar4) {
      local_4 = 0;
      do {
        iVar2 = *(int *)(param_1 + 0x4fc);
        iVar4 = local_4 + iVar2;
        for (puVar1 = *(ushort **)(local_4 + 0x18 + iVar2);
            puVar1 != *(ushort **)(local_4 + 0x1c + iVar2); puVar1 = puVar1 + 4) {
          if (*puVar1 == param_2) {
            if (puVar1 + 4 != *(ushort **)(iVar4 + 0x1c)) {
              FUN_004c6050(puVar1 + 4,*(ushort **)(iVar4 + 0x1c),puVar1,param_2,0);
            }
            *(int *)(iVar4 + 0x1c) = *(int *)(iVar4 + 0x1c) + -8;
            FUN_004c68d0(0);
            break;
          }
        }
        uVar5 = uVar5 + 1;
        local_4 = local_4 + 0x24;
      } while (uVar5 < (uint)((*(int *)(param_1 + 0x500) - *(int *)(param_1 + 0x4fc)) / 0x24));
    }
    iVar2 = *(int *)(param_1 + 0x4fc);
    iVar6 = param_2 * 0x24;
    iVar4 = iVar2 + ((*(int *)(param_1 + 0x500) - *(int *)(param_1 + 0x4fc)) / 0x24 + -1) * 0x24;
    puVar3 = (undefined4 *)(iVar6 + 4 + iVar2);
    *puVar3 = *(undefined4 *)(iVar4 + 4);
    puVar3[1] = *(undefined4 *)(iVar4 + 8);
    puVar3[2] = *(undefined4 *)(iVar4 + 0xc);
    *(undefined1 *)(iVar6 + 0x10 + iVar2) = *(undefined1 *)(iVar4 + 0x10);
    *(undefined2 *)(iVar6 + 0x12 + iVar2) = *(undefined2 *)(iVar4 + 0x12);
    *(undefined2 *)(iVar6 + 0x14 + iVar2) = *(undefined2 *)(iVar4 + 0x14);
    *(undefined1 *)(iVar6 + 0x16 + iVar2) = *(undefined1 *)(iVar4 + 0x16);
    FUN_004c4df0(iVar4 + 0x18);
    *(ushort *)(iVar6 + 0x12 + *(int *)(param_1 + 0x4fc)) = (ushort)param_2;
    puVar3 = (undefined4 *)(*(int *)(param_1 + 0x500) + -0x24);
    *(undefined4 **)(param_1 + 0x500) = puVar3;
    (**(code **)*puVar3)(0);
    iVar2 = *(int *)(param_1 + 0x500) - *(int *)(param_1 + 0x4fc);
    iVar4 = iVar2 >> 0x1f;
    uVar5 = 0;
    if (iVar2 / 0x24 + iVar4 != iVar4) {
      iVar4 = 0;
      do {
        iVar2 = *(int *)(param_1 + 0x4fc) + iVar4;
        for (puVar1 = *(ushort **)(iVar2 + 0x18); puVar1 != *(ushort **)(iVar2 + 0x1c);
            puVar1 = puVar1 + 4) {
          if (*puVar1 == unaff_EBP) {
            *puVar1 = (ushort)param_2;
            break;
          }
        }
        uVar5 = uVar5 + 1;
        iVar4 = iVar4 + 0x24;
      } while (uVar5 < (uint)((*(int *)(param_1 + 0x500) - *(int *)(param_1 + 0x4fc)) / 0x24));
    }
    FUN_004c2a30();
  }
  return;
}


