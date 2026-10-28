undefined4 FUN_0053d7d0(int *param_1)

{
  undefined1 uVar1;
  byte bVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  ushort uVar7;
  int iVar8;
  int iVar9;
  undefined1 *puVar10;
  byte *pbVar11;
  int iVar12;
  uint uVar13;
  ushort *puVar14;
  int *piStack_c;
  
  puVar3 = (undefined4 *)param_1[6];
  iVar12 = puVar3[1];
  puVar10 = (undefined1 *)*puVar3;
  if (iVar12 == 0) {
    cVar6 = (*(code *)puVar3[3])(param_1);
    if (cVar6 == '\0') {
      return 0;
    }
    puVar10 = (undefined1 *)*puVar3;
    iVar12 = puVar3[1];
  }
  iVar12 = iVar12 + -1;
  uVar1 = *puVar10;
  puVar10 = puVar10 + 1;
  if (iVar12 == 0) {
    cVar6 = (*(code *)puVar3[3])(param_1);
    if (cVar6 == '\0') {
      return 0;
    }
    puVar10 = (undefined1 *)*puVar3;
    iVar12 = puVar3[1];
  }
  iVar12 = iVar12 + -1;
  pbVar11 = puVar10 + 1;
  iVar9 = CONCAT11(uVar1,*puVar10) - 2;
  do {
    iVar5 = iVar9;
    if (iVar5 < 1) {
      if (iVar5 != 0) {
        *(undefined4 *)(*param_1 + 0x14) = 0xb;
        (**(code **)*param_1)(param_1);
      }
      *puVar3 = pbVar11;
      puVar3[1] = iVar12;
      return 1;
    }
    if (iVar12 == 0) {
      cVar6 = (*(code *)puVar3[3])(param_1);
      if (cVar6 == '\0') {
        return 0;
      }
      pbVar11 = (byte *)*puVar3;
      iVar12 = puVar3[1];
    }
    bVar2 = *pbVar11;
    *(undefined4 *)(*param_1 + 0x14) = 0x51;
    uVar13 = bVar2 & 0xf;
    iVar12 = iVar12 + -1;
    *(uint *)(*param_1 + 0x18) = uVar13;
    iVar8 = (int)(uint)bVar2 >> 4;
    *(int *)(*param_1 + 0x1c) = iVar8;
    pbVar11 = pbVar11 + 1;
    (**(code **)(*param_1 + 4))(param_1,1);
    if (3 < uVar13) {
      *(undefined4 *)(*param_1 + 0x14) = 0x1f;
      *(uint *)(*param_1 + 0x18) = uVar13;
      (**(code **)*param_1)(param_1);
    }
    if (param_1[uVar13 + 0x24] == 0) {
      iVar9 = FUN_0053e320(param_1);
      param_1[uVar13 + 0x24] = iVar9;
    }
    iVar9 = param_1[uVar13 + 0x24];
    piStack_c = (int *)&DAT_005adaa0;
    do {
      if (iVar8 == 0) {
        if (iVar12 == 0) {
          cVar6 = (*(code *)puVar3[3])(param_1);
          if (cVar6 == '\0') {
            return 0;
          }
          pbVar11 = (byte *)*puVar3;
          iVar12 = puVar3[1];
        }
        uVar7 = (ushort)*pbVar11;
      }
      else {
        if (iVar12 == 0) {
          cVar6 = (*(code *)puVar3[3])(param_1);
          if (cVar6 == '\0') {
            return 0;
          }
          pbVar11 = (byte *)*puVar3;
          iVar12 = puVar3[1];
        }
        iVar12 = iVar12 + -1;
        bVar2 = *pbVar11;
        pbVar11 = pbVar11 + 1;
        if (iVar12 == 0) {
          cVar6 = (*(code *)puVar3[3])(param_1);
          if (cVar6 == '\0') {
            return 0;
          }
          pbVar11 = (byte *)*puVar3;
          iVar12 = puVar3[1];
        }
        uVar7 = (ushort)bVar2 * 0x100 + (ushort)*pbVar11;
      }
      iVar4 = *piStack_c;
      iVar12 = iVar12 + -1;
      piStack_c = piStack_c + 1;
      pbVar11 = pbVar11 + 1;
      *(ushort *)(iVar9 + iVar4 * 2) = uVar7;
    } while ((int)piStack_c < 0x5adba0);
    if (1 < *(int *)(*param_1 + 0x68)) {
      puVar14 = (ushort *)(iVar9 + 4);
      piStack_c = (int *)0x8;
      do {
        iVar9 = *param_1;
        *(uint *)(iVar9 + 0x18) = (uint)puVar14[-2];
        *(uint *)(iVar9 + 0x1c) = (uint)puVar14[-1];
        *(uint *)(iVar9 + 0x20) = (uint)*puVar14;
        *(uint *)(iVar9 + 0x24) = (uint)puVar14[1];
        *(uint *)(iVar9 + 0x28) = (uint)puVar14[2];
        *(uint *)(iVar9 + 0x2c) = (uint)puVar14[3];
        *(uint *)(iVar9 + 0x30) = (uint)puVar14[4];
        *(uint *)(iVar9 + 0x34) = (uint)puVar14[5];
        *(undefined4 *)(*param_1 + 0x14) = 0x5d;
        (**(code **)(*param_1 + 4))(param_1,2);
        puVar14 = puVar14 + 8;
        piStack_c = (int *)((int)piStack_c + -1);
      } while (piStack_c != (int *)0x0);
    }
    iVar9 = iVar5 + -0x41;
    if (iVar8 != 0) {
      iVar9 = iVar5 + -0x81;
    }
  } while( true );
}


