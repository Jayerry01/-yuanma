uint FUN_0053ce30(int *param_1,undefined1 param_2,undefined1 param_3)

{
  byte bVar1;
  byte bVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  byte *pbVar8;
  byte *pbVar9;
  
  puVar3 = (undefined4 *)param_1[6];
  iVar6 = puVar3[1];
  pbVar8 = (byte *)*puVar3;
  *(undefined1 *)(param_1 + 0x32) = param_2;
  *(undefined1 *)((int)param_1 + 0xc9) = param_3;
  if (iVar6 == 0) {
    uVar4 = (*(code *)puVar3[3])(param_1);
    if ((char)uVar4 == '\0') goto LAB_0053d147;
    pbVar8 = (byte *)*puVar3;
    iVar6 = puVar3[1];
  }
  iVar6 = iVar6 + -1;
  bVar1 = *pbVar8;
  pbVar8 = pbVar8 + 1;
  if (iVar6 == 0) {
    uVar4 = (*(code *)puVar3[3])(param_1);
    if ((char)uVar4 == '\0') goto LAB_0053d147;
    pbVar8 = (byte *)*puVar3;
    iVar6 = puVar3[1];
  }
  bVar2 = *pbVar8;
  iVar6 = iVar6 + -1;
  pbVar8 = pbVar8 + 1;
  if (iVar6 == 0) {
    uVar4 = (*(code *)puVar3[3])(param_1);
    if ((char)uVar4 == '\0') goto LAB_0053d147;
    pbVar8 = (byte *)*puVar3;
    iVar6 = puVar3[1];
  }
  iVar6 = iVar6 + -1;
  pbVar9 = pbVar8 + 1;
  param_1[0x30] = (uint)*pbVar8;
  if (iVar6 == 0) {
    uVar4 = (*(code *)puVar3[3])(param_1);
    if ((char)uVar4 == '\0') goto LAB_0053d147;
    pbVar9 = (byte *)*puVar3;
    iVar6 = puVar3[1];
  }
  iVar6 = iVar6 + -1;
  pbVar8 = pbVar9 + 1;
  param_1[8] = (uint)*pbVar9 << 8;
  if (iVar6 == 0) {
    uVar4 = (*(code *)puVar3[3])(param_1);
    if ((char)uVar4 == '\0') goto LAB_0053d147;
    pbVar8 = (byte *)*puVar3;
    iVar6 = puVar3[1];
  }
  iVar6 = iVar6 + -1;
  pbVar9 = pbVar8 + 1;
  param_1[8] = param_1[8] + (uint)*pbVar8;
  if (iVar6 == 0) {
    uVar4 = (*(code *)puVar3[3])(param_1);
    if ((char)uVar4 == '\0') goto LAB_0053d147;
    pbVar9 = (byte *)*puVar3;
    iVar6 = puVar3[1];
  }
  iVar6 = iVar6 + -1;
  pbVar8 = pbVar9 + 1;
  param_1[7] = (uint)*pbVar9 << 8;
  if (iVar6 == 0) {
    uVar4 = (*(code *)puVar3[3])(param_1);
    if ((char)uVar4 == '\0') goto LAB_0053d147;
    pbVar8 = (byte *)*puVar3;
    iVar6 = puVar3[1];
  }
  iVar6 = iVar6 + -1;
  pbVar9 = pbVar8 + 1;
  param_1[7] = param_1[7] + (uint)*pbVar8;
  if (iVar6 == 0) {
    uVar4 = (*(code *)puVar3[3])(param_1);
    if ((char)uVar4 == '\0') {
LAB_0053d147:
      return uVar4 & 0xffffff00;
    }
    pbVar9 = (byte *)*puVar3;
    iVar6 = puVar3[1];
  }
  param_1[9] = (uint)*pbVar9;
  iVar5 = *param_1;
  *(int *)(iVar5 + 0x18) = param_1[0x5f];
  *(int *)(iVar5 + 0x1c) = param_1[7];
  *(int *)(iVar5 + 0x20) = param_1[8];
  *(int *)(iVar5 + 0x24) = param_1[9];
  iVar6 = iVar6 + -1;
  *(undefined4 *)(*param_1 + 0x14) = 100;
  pbVar9 = pbVar9 + 1;
  (**(code **)(*param_1 + 4))(param_1,1);
  if (*(char *)(param_1[0x65] + 0xd) != '\0') {
    *(undefined4 *)(*param_1 + 0x14) = 0x3a;
    (**(code **)*param_1)(param_1);
  }
  if (((param_1[8] == 0) || (param_1[7] == 0)) || (param_1[9] < 1)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x20;
    (**(code **)*param_1)(param_1);
  }
  if ((uint)bVar1 * 0x100 + (uint)bVar2 + -8 != param_1[9] * 3) {
    *(undefined4 *)(*param_1 + 0x14) = 0xb;
    (**(code **)*param_1)(param_1);
  }
  if (param_1[0x31] == 0) {
    iVar5 = (**(code **)param_1[1])(param_1,1,param_1[9] * 0x54);
    param_1[0x31] = iVar5;
  }
  puVar7 = (uint *)param_1[0x31];
  _param_2 = 0;
  if (0 < param_1[9]) {
    do {
      puVar7[1] = _param_2;
      if (iVar6 == 0) {
        uVar4 = (*(code *)puVar3[3])(param_1);
        if ((char)uVar4 == '\0') goto LAB_0053d147;
        pbVar9 = (byte *)*puVar3;
        iVar6 = puVar3[1];
      }
      iVar6 = iVar6 + -1;
      pbVar8 = pbVar9 + 1;
      *puVar7 = (uint)*pbVar9;
      if (iVar6 == 0) {
        uVar4 = (*(code *)puVar3[3])(param_1);
        if ((char)uVar4 == '\0') goto LAB_0053d147;
        pbVar8 = (byte *)*puVar3;
        iVar6 = puVar3[1];
      }
      iVar6 = iVar6 + -1;
      bVar1 = *pbVar8;
      pbVar8 = pbVar8 + 1;
      puVar7[3] = bVar1 & 0xf;
      puVar7[2] = (int)(uint)bVar1 >> 4;
      if (iVar6 == 0) {
        uVar4 = (*(code *)puVar3[3])(param_1);
        if ((char)uVar4 == '\0') goto LAB_0053d147;
        pbVar8 = (byte *)*puVar3;
        iVar6 = puVar3[1];
      }
      puVar7[4] = (uint)*pbVar8;
      iVar5 = *param_1;
      iVar6 = iVar6 + -1;
      pbVar9 = pbVar8 + 1;
      *(uint *)(iVar5 + 0x18) = *puVar7;
      *(uint *)(iVar5 + 0x1c) = puVar7[2];
      *(uint *)(iVar5 + 0x20) = puVar7[3];
      *(uint *)(iVar5 + 0x24) = puVar7[4];
      *(undefined4 *)(*param_1 + 0x14) = 0x65;
      (**(code **)(*param_1 + 4))(param_1,1);
      _param_2 = _param_2 + 1;
      puVar7 = puVar7 + 0x15;
    } while ((int)_param_2 < param_1[9]);
  }
  *(undefined1 *)(param_1[0x65] + 0xd) = 1;
  *puVar3 = pbVar9;
  puVar3[1] = iVar6;
  return CONCAT31((int3)((uint)puVar3 >> 8),1);
}


