uint FUN_0053c370(int *param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  
  puVar2 = (undefined4 *)param_1[6];
  pbVar5 = (byte *)*puVar2;
  iVar4 = puVar2[1];
  do {
    if (iVar4 == 0) {
      uVar3 = (*(code *)puVar2[3])(param_1);
      if ((char)uVar3 == '\0') {
LAB_0053c41a:
        return uVar3 & 0xffffff00;
      }
      pbVar5 = (byte *)*puVar2;
      iVar4 = puVar2[1];
    }
    bVar1 = *pbVar5;
    while( true ) {
      pbVar5 = pbVar5 + 1;
      iVar4 = iVar4 + -1;
      if (bVar1 == 0xff) break;
      *(int *)(param_1[0x65] + 0x14) = *(int *)(param_1[0x65] + 0x14) + 1;
      *puVar2 = pbVar5;
      puVar2[1] = iVar4;
      if (iVar4 == 0) {
        uVar3 = (*(code *)puVar2[3])(param_1);
        if ((char)uVar3 == '\0') goto LAB_0053c41a;
        pbVar5 = (byte *)*puVar2;
        iVar4 = puVar2[1];
      }
      bVar1 = *pbVar5;
    }
    do {
      if (iVar4 == 0) {
        uVar3 = (*(code *)puVar2[3])(param_1);
        if ((char)uVar3 == '\0') goto LAB_0053c41a;
        pbVar5 = (byte *)*puVar2;
        iVar4 = puVar2[1];
      }
      iVar4 = iVar4 + -1;
      uVar3 = (uint)*pbVar5;
      pbVar5 = pbVar5 + 1;
    } while (uVar3 == 0xff);
    if (uVar3 != 0) {
      if (*(int *)(param_1[0x65] + 0x14) != 0) {
        *(undefined4 *)(*param_1 + 0x14) = 0x74;
        *(undefined4 *)(*param_1 + 0x18) = *(undefined4 *)(param_1[0x65] + 0x14);
        *(uint *)(*param_1 + 0x1c) = uVar3;
        (**(code **)(*param_1 + 4))(param_1,0xffffffff);
        *(undefined4 *)(param_1[0x65] + 0x14) = 0;
      }
      param_1[0x5f] = uVar3;
      *puVar2 = pbVar5;
      puVar2[1] = iVar4;
      return 1;
    }
    *(int *)(param_1[0x65] + 0x14) = *(int *)(param_1[0x65] + 0x14) + 2;
    *puVar2 = pbVar5;
    puVar2[1] = iVar4;
  } while( true );
}


