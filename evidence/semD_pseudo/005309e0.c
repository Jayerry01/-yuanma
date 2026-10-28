undefined4 FUN_005309e0(HDC param_1)

{
  int iVar1;
  undefined4 *puVar2;
  HBITMAP pHVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 unaff_retaddr;
  undefined4 uVar7;
  undefined4 *local_30;
  BITMAPINFO local_2c;
  
  iVar1 = FUN_0052c490();
  DAT_007242fc = iVar1;
  if (iVar1 == 0) goto LAB_00530ac7;
  if (*(byte *)(iVar1 + 0xc) < 3) {
    uVar7 = 0x80e0;
LAB_00530a1b:
    iVar1 = FUN_0052e890(iVar1,uVar7,0x1401);
  }
  else if (1 < *(byte *)(iVar1 + 0xd)) {
    uVar7 = *(undefined4 *)(iVar1 + 0x20);
    goto LAB_00530a1b;
  }
  if (iVar1 == 0) {
    return 0;
  }
  puVar2 = (undefined4 *)FUN_00530c50();
  if (puVar2 == (undefined4 *)0x0) {
    return 0;
  }
  FUN_00530c60(&local_2c);
  pHVar3 = CreateDIBSection(param_1,&local_2c,0,&local_30,(HANDLE)0x0,0);
  if ((pHVar3 != (HBITMAP)0x0) && (local_30 != (undefined4 *)0x0)) {
    uVar4 = ((-*(int *)(DAT_007242fc + 0x10) & 3U) + *(int *)(DAT_007242fc + 0x10)) *
            *(int *)(DAT_007242fc + 4);
    puVar6 = puVar2;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *local_30 = *puVar6;
      puVar6 = puVar6 + 1;
      local_30 = local_30 + 1;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)local_30 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      local_30 = (undefined4 *)((int)local_30 + 1);
    }
    FUN_00530db0(puVar2);
    if (iVar1 != DAT_007242fc) {
      FUN_0052c1a0(iVar1);
    }
    return unaff_retaddr;
  }
  if (iVar1 != DAT_007242fc) {
    FUN_0052c1a0(iVar1);
  }
LAB_00530ac7:
  FUN_00530d00(0x506);
  return 0;
}


