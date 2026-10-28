int FUN_0052cce0(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (param_1 == (undefined4 *)0x0) {
    FUN_00530d00(0x509);
    return 0;
  }
  iVar2 = FUN_0052c740(*param_1,param_1[1],param_1[2],*(undefined1 *)(param_1 + 3),
                       *(undefined1 *)((int)param_1 + 0xd));
  if (iVar2 == 0) {
    return 0;
  }
  cVar1 = FUN_0052cb10(iVar2,param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  uVar4 = param_1[6];
  puVar5 = (undefined4 *)param_1[5];
  puVar6 = *(undefined4 **)(iVar2 + 0x14);
  for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  return iVar2;
}


