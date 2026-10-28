void FUN_0054ff00(undefined4 param_1,undefined4 param_2,int *param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  char *pcVar9;
  char local_34 [16];
  undefined4 local_24 [9];
  
  FUN_0054fec0(param_1,param_2,local_34);
  iVar5 = 0;
  puVar8 = local_24;
  do {
    FUN_00508ae6(puVar8,&DAT_005d1170,local_34[iVar5]);
    iVar5 = iVar5 + 1;
    puVar8 = (undefined4 *)((int)puVar8 + 2);
  } while (iVar5 < 0x10);
  uVar3 = 0xffffffff;
  pcVar9 = (char *)local_24;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  puVar8 = (undefined4 *)*param_3;
  uVar2 = (int)(local_34 + ~uVar3 + 0xf) - (int)local_24;
  uVar4 = param_3[1] - (int)puVar8;
  if (uVar4 < uVar2) {
    puVar7 = local_24;
    for (uVar2 = uVar4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
    FUN_00403490((int)local_24 + (param_3[1] - *param_3),local_34 + ~uVar3 + 0xf);
  }
  else {
    puVar7 = local_24;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
    iVar5 = param_3[1];
    iVar6 = *param_3 + uVar2;
    if (iVar6 != iVar5) {
      FUN_005092c0(iVar6,iVar5,1);
      param_3[1] = param_3[1] + (iVar6 - iVar5);
      return;
    }
  }
  return;
}


