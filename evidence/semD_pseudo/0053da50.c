undefined4 FUN_0053da50(int *param_1)

{
  undefined1 uVar1;
  byte bVar2;
  undefined4 *puVar3;
  char cVar4;
  int iVar5;
  undefined1 *puVar6;
  byte *pbVar7;
  int iVar8;
  
  puVar3 = (undefined4 *)param_1[6];
  iVar8 = puVar3[1];
  puVar6 = (undefined1 *)*puVar3;
  if (iVar8 == 0) {
    cVar4 = (*(code *)puVar3[3])(param_1);
    if (cVar4 == '\0') {
      return 0;
    }
    puVar6 = (undefined1 *)*puVar3;
    iVar8 = puVar3[1];
  }
  iVar8 = iVar8 + -1;
  uVar1 = *puVar6;
  puVar6 = puVar6 + 1;
  if (iVar8 == 0) {
    cVar4 = (*(code *)puVar3[3])(param_1);
    if (cVar4 == '\0') {
      return 0;
    }
    puVar6 = (undefined1 *)*puVar3;
    iVar8 = puVar3[1];
  }
  iVar8 = iVar8 + -1;
  pbVar7 = puVar6 + 1;
  if (CONCAT11(uVar1,*puVar6) != 4) {
    *(undefined4 *)(*param_1 + 0x14) = 0xb;
    (**(code **)*param_1)(param_1);
  }
  if (iVar8 == 0) {
    cVar4 = (*(code *)puVar3[3])(param_1);
    if (cVar4 == '\0') {
      return 0;
    }
    pbVar7 = (byte *)*puVar3;
    iVar8 = puVar3[1];
  }
  iVar8 = iVar8 + -1;
  bVar2 = *pbVar7;
  pbVar7 = pbVar7 + 1;
  if (iVar8 == 0) {
    cVar4 = (*(code *)puVar3[3])(param_1);
    if (cVar4 == '\0') {
      return 0;
    }
    pbVar7 = (byte *)*puVar3;
    iVar8 = puVar3[1];
  }
  iVar5 = (uint)bVar2 * 0x100 + (uint)*pbVar7;
  *(undefined4 *)(*param_1 + 0x14) = 0x52;
  *(int *)(*param_1 + 0x18) = iVar5;
  (**(code **)(*param_1 + 4))(param_1,1);
  param_1[0x3f] = iVar5;
  puVar3[1] = iVar8 + -1;
  *puVar3 = pbVar7 + 1;
  return 1;
}


