undefined4 FUN_0053c9a0(int *param_1)

{
  int iVar1;
  byte bVar2;
  undefined4 *puVar3;
  char cVar4;
  byte *pbVar5;
  int iVar6;
  
  puVar3 = (undefined4 *)param_1[6];
  iVar6 = puVar3[1];
  pbVar5 = (byte *)*puVar3;
  if (iVar6 == 0) {
    cVar4 = (*(code *)puVar3[3])(param_1);
    if (cVar4 == '\0') {
      return 0;
    }
    pbVar5 = (byte *)*puVar3;
    iVar6 = puVar3[1];
  }
  iVar6 = iVar6 + -1;
  bVar2 = *pbVar5;
  pbVar5 = pbVar5 + 1;
  if (iVar6 == 0) {
    cVar4 = (*(code *)puVar3[3])(param_1);
    if (cVar4 == '\0') {
      return 0;
    }
    pbVar5 = (byte *)*puVar3;
    iVar6 = puVar3[1];
  }
  iVar1 = (uint)bVar2 * 0x100 + -2 + (uint)*pbVar5;
  *(undefined4 *)(*param_1 + 0x14) = 0x5b;
  *(int *)(*param_1 + 0x18) = param_1[0x5f];
  *(int *)(*param_1 + 0x1c) = iVar1;
  (**(code **)(*param_1 + 4))(param_1,1);
  *puVar3 = pbVar5 + 1;
  puVar3[1] = iVar6 + -1;
  if (0 < iVar1) {
    (**(code **)(param_1[6] + 0x10))(param_1,iVar1);
  }
  return 1;
}


