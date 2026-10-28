undefined4 FUN_0053d460(int *param_1)

{
  undefined1 uVar1;
  byte bVar2;
  undefined4 *puVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  int *piVar10;
  byte *pbVar11;
  int iVar12;
  undefined4 *puVar13;
  int iStack_128;
  int iStack_120;
  byte abStack_118 [20];
  uint uStack_104;
  byte abStack_100 [256];
  
  puVar3 = (undefined4 *)param_1[6];
  iStack_128 = puVar3[1];
  puVar8 = (undefined1 *)*puVar3;
  if (iStack_128 == 0) {
    cVar4 = (*(code *)puVar3[3])(param_1);
    if (cVar4 == '\0') {
      return 0;
    }
    iStack_128 = puVar3[1];
    puVar8 = (undefined1 *)*puVar3;
  }
  iStack_128 = iStack_128 + -1;
  uVar1 = *puVar8;
  puVar8 = puVar8 + 1;
  if (iStack_128 == 0) {
    cVar4 = (*(code *)puVar3[3])(param_1);
    if (cVar4 == '\0') {
      return 0;
    }
    iStack_128 = puVar3[1];
    puVar8 = (undefined1 *)*puVar3;
  }
  iStack_128 = iStack_128 + -1;
  pbVar9 = puVar8 + 1;
  iVar5 = CONCAT11(uVar1,*puVar8) - 2;
  do {
    if (iVar5 < 0x11) {
      if (iVar5 != 0) {
        *(undefined4 *)(*param_1 + 0x14) = 0xb;
        (**(code **)*param_1)(param_1);
      }
      *puVar3 = pbVar9;
      puVar3[1] = iStack_128;
      return 1;
    }
    if (iStack_128 == 0) {
      cVar4 = (*(code *)puVar3[3])(param_1);
      if (cVar4 == '\0') {
        return 0;
      }
      iStack_128 = puVar3[1];
      pbVar9 = (byte *)*puVar3;
    }
    uStack_104 = (uint)*pbVar9;
    *(undefined4 *)(*param_1 + 0x14) = 0x50;
    iStack_128 = iStack_128 + -1;
    *(uint *)(*param_1 + 0x18) = uStack_104;
    pbVar9 = pbVar9 + 1;
    (**(code **)(*param_1 + 4))(param_1,1);
    abStack_118[0] = 0;
    iStack_120 = 0;
    iVar12 = 1;
    do {
      if (iStack_128 == 0) {
        cVar4 = (*(code *)puVar3[3])(param_1);
        if (cVar4 == '\0') {
          return 0;
        }
        iStack_128 = puVar3[1];
        pbVar9 = (byte *)*puVar3;
      }
      bVar2 = *pbVar9;
      abStack_118[iVar12] = bVar2;
      iStack_128 = iStack_128 + -1;
      pbVar9 = pbVar9 + 1;
      iVar7 = iStack_120 + (uint)bVar2;
      iVar12 = iVar12 + 1;
      iStack_120 = iVar7;
    } while (iVar12 < 0x11);
    iVar12 = *param_1;
    *(uint *)(iVar12 + 0x18) =
         CONCAT12(abStack_118[3],CONCAT11(abStack_118[2],abStack_118[1])) & 0xff;
    *(uint *)(iVar12 + 0x1c) =
         CONCAT12(abStack_118[4],CONCAT11(abStack_118[3],abStack_118[2])) & 0xff;
    *(uint *)(iVar12 + 0x20) =
         CONCAT12(abStack_118[5],CONCAT11(abStack_118[4],abStack_118[3])) & 0xff;
    *(uint *)(iVar12 + 0x24) =
         CONCAT12(abStack_118[6],CONCAT11(abStack_118[5],abStack_118[4])) & 0xff;
    *(uint *)(iVar12 + 0x28) =
         CONCAT12(abStack_118[7],CONCAT11(abStack_118[6],abStack_118[5])) & 0xff;
    *(uint *)(iVar12 + 0x2c) =
         CONCAT12(abStack_118[8],CONCAT11(abStack_118[7],abStack_118[6])) & 0xff;
    *(uint *)(iVar12 + 0x30) =
         CONCAT12(abStack_118[9],CONCAT11(abStack_118[8],abStack_118[7])) & 0xff;
    *(uint *)(iVar12 + 0x34) =
         CONCAT12(abStack_118[10],CONCAT11(abStack_118[9],abStack_118[8])) & 0xff;
    *(undefined4 *)(*param_1 + 0x14) = 0x56;
    (**(code **)(*param_1 + 4))(param_1,2);
    iVar12 = *param_1;
    *(uint *)(iVar12 + 0x18) =
         CONCAT12(abStack_118[0xb],CONCAT11(abStack_118[10],abStack_118[9])) & 0xff;
    *(uint *)(iVar12 + 0x1c) =
         CONCAT12(abStack_118[0xc],CONCAT11(abStack_118[0xb],abStack_118[10])) & 0xff;
    *(uint *)(iVar12 + 0x20) =
         CONCAT12(abStack_118[0xd],CONCAT11(abStack_118[0xc],abStack_118[0xb])) & 0xff;
    *(uint *)(iVar12 + 0x24) =
         CONCAT12(abStack_118[0xe],CONCAT11(abStack_118[0xd],abStack_118[0xc])) & 0xff;
    *(uint *)(iVar12 + 0x28) =
         CONCAT12(abStack_118[0xf],CONCAT11(abStack_118[0xe],abStack_118[0xd])) & 0xff;
    *(uint *)(iVar12 + 0x2c) =
         CONCAT12(abStack_118[0x10],CONCAT11(abStack_118[0xf],abStack_118[0xe])) & 0xff;
    *(uint *)(iVar12 + 0x30) = CONCAT11(abStack_118[0x10],abStack_118[0xf]) & 0xff;
    *(uint *)(iVar12 + 0x34) = (uint)abStack_118[0x10];
    *(undefined4 *)(*param_1 + 0x14) = 0x56;
    (**(code **)(*param_1 + 4))(param_1,2);
    if ((0x100 < iVar7) || (iVar5 + -0x11 < iVar7)) {
      *(undefined4 *)(*param_1 + 0x14) = 8;
      (**(code **)*param_1)(param_1);
    }
    iStack_120 = 0;
    if (0 < iVar7) {
      do {
        if (iStack_128 == 0) {
          cVar4 = (*(code *)puVar3[3])(param_1);
          if (cVar4 == '\0') {
            return 0;
          }
          iStack_128 = puVar3[1];
          pbVar9 = (byte *)*puVar3;
        }
        iStack_128 = iStack_128 + -1;
        abStack_100[iStack_120] = *pbVar9;
        pbVar9 = pbVar9 + 1;
        iStack_120 = iStack_120 + 1;
      } while (iStack_120 < iVar7);
    }
    iVar5 = (iVar5 + -0x11) - iVar7;
    if ((uStack_104 & 0x10) == 0) {
      iVar12 = uStack_104 + 0x28;
      uVar6 = uStack_104;
    }
    else {
      iVar12 = uStack_104 + 0x1c;
      uVar6 = uStack_104 - 0x10;
    }
    piVar10 = param_1 + iVar12;
    if (((int)uVar6 < 0) || (3 < (int)uVar6)) {
      *(undefined4 *)(*param_1 + 0x14) = 0x1e;
      *(uint *)(*param_1 + 0x18) = uVar6;
      (**(code **)*param_1)(param_1);
    }
    if (*piVar10 == 0) {
      iVar12 = FUN_0053e340(param_1);
      *piVar10 = iVar12;
    }
    puVar13 = (undefined4 *)*piVar10;
    *puVar13 = CONCAT13(abStack_118[3],
                        CONCAT12(abStack_118[2],CONCAT11(abStack_118[1],abStack_118[0])));
    puVar13[1] = CONCAT13(abStack_118[7],
                          CONCAT12(abStack_118[6],CONCAT11(abStack_118[5],abStack_118[4])));
    puVar13[2] = CONCAT13(abStack_118[0xb],
                          CONCAT12(abStack_118[10],CONCAT11(abStack_118[9],abStack_118[8])));
    puVar13[3] = CONCAT13(abStack_118[0xf],
                          CONCAT12(abStack_118[0xe],CONCAT11(abStack_118[0xd],abStack_118[0xc])));
    *(byte *)(puVar13 + 4) = abStack_118[0x10];
    pbVar11 = abStack_100;
    puVar13 = (undefined4 *)(*piVar10 + 0x11);
    for (iVar12 = 0x40; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar13 = *(undefined4 *)pbVar11;
      pbVar11 = pbVar11 + 4;
      puVar13 = puVar13 + 1;
    }
  } while( true );
}


