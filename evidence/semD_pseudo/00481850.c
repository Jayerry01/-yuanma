void __fastcall FUN_00481850(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  char *pcVar8;
  undefined4 *puVar9;
  
  if (*(int *)(param_1 + 8) != 0) {
    thunk_FUN_005089fd(*(int *)(param_1 + 8));
    *(undefined4 *)(param_1 + 8) = 0;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  uVar4 = 0xffffffff;
  pcVar8 = (char *)&DAT_005d5a24;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  puVar9 = *(undefined4 **)(param_1 + 0xc);
  uVar5 = *(int *)(param_1 + 0x10) - (int)puVar9;
  uVar3 = ~uVar4 - 1;
  if (uVar5 < uVar3) {
    puVar7 = &DAT_005d5a24;
    for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    FUN_00403490((int)&DAT_005d5a24 + (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)),
                 ~uVar4 + 0x5d5a23);
  }
  else {
    puVar7 = &DAT_005d5a24;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    iVar2 = *(int *)(param_1 + 0x10);
    iVar6 = *(int *)(param_1 + 0xc) + uVar3;
    if (iVar6 != iVar2) {
      FUN_005092c0(iVar6,iVar2,1);
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + (iVar6 - iVar2);
      return;
    }
  }
  return;
}


