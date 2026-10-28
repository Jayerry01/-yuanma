undefined4 __fastcall FUN_005795d0(int *param_1)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  ushort *puVar11;
  uint *local_10;
  uint local_c;
  int local_8 [2];
  
  FUN_00579a30();
  if (*param_1 == 1) {
    piVar10 = param_1 + 0x14;
    uVar5 = 0xffffffff;
    param_1[0x4e] = 0;
    piVar8 = piVar10;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      iVar6 = *piVar8;
      piVar8 = (int *)((int)piVar8 + 1);
    } while ((char)iVar6 != '\0');
    piVar8 = piVar10;
    for (iVar6 = ~uVar5 - 1; 0 < iVar6; iVar6 = iVar6 - iVar2) {
      iVar2 = FUN_00579790(piVar8);
      piVar8 = (int *)((int)piVar8 + iVar2);
      param_1[0x4e] = param_1[0x4e] + 1;
    }
    pvVar3 = operator_new(param_1[0x4e] << 2);
    param_1[0x51] = (int)pvVar3;
    local_c = 0;
    if (0 < param_1[0x4e]) {
      local_10 = (uint *)(param_1 + 0x2c);
      do {
        uVar5 = FUN_00579790(piVar10);
        *local_10 = uVar5;
        iVar6 = param_1[0x53];
        piVar8 = piVar10;
        piVar9 = local_8;
        for (uVar7 = uVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *piVar9 = *piVar8;
          piVar8 = piVar8 + 1;
          piVar9 = piVar9 + 1;
        }
        iVar2 = param_1[0x52];
        for (uVar7 = uVar5 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(char *)piVar9 = (char)*piVar8;
          piVar8 = (int *)((int)piVar8 + 1);
          piVar9 = (int *)((int)piVar9 + 1);
        }
        iVar1 = param_1[0x4d];
        *(undefined1 *)((int)local_8 + uVar5) = 0;
        uVar4 = FUN_00579880(local_8,iVar2,iVar6,0xffffff,iVar1,0);
        *(undefined4 *)(param_1[0x51] + local_c * 4) = uVar4;
        piVar10 = (int *)((int)piVar10 + uVar5);
        local_c = local_c + 1;
        local_10 = local_10 + 1;
      } while ((int)local_c < param_1[0x4e]);
      return 1;
    }
  }
  else {
    puVar11 = (ushort *)(param_1 + 0x1c);
    iVar6 = FUN_0050b0ec(puVar11);
    param_1[0x4e] = iVar6;
    pvVar3 = operator_new(iVar6 << 2);
    param_1[0x51] = (int)pvVar3;
    iVar6 = 0;
    if (0 < param_1[0x4e]) {
      do {
        local_c = (uint)*puVar11;
        uVar4 = FUN_00579880(&local_c,param_1[0x52],param_1[0x53],0xffffff,param_1[0x4d],1);
        puVar11 = puVar11 + 1;
        *(undefined4 *)(param_1[0x51] + iVar6 * 4) = uVar4;
        iVar6 = iVar6 + 1;
      } while (iVar6 < param_1[0x4e]);
    }
  }
  return 1;
}


