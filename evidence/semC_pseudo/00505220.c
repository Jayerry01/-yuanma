void __fastcall FUN_00505220(undefined4 param_1)

{
  undefined1 *puVar1;
  char cVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  int iVar12;
  char *pcVar13;
  undefined4 *puVar14;
  
  if (DAT_006675dc != '\0') {
    uVar11 = 0;
    iVar7 = DAT_0066756c;
    iVar8 = DAT_00667570;
    if (DAT_00667570 - DAT_0066756c >> 6 != 0) {
      iVar6 = 0;
      do {
        if (*(char *)(iVar6 + iVar7) != '\0') {
          FUN_00505660(uVar11 + 1);
          iVar7 = DAT_0066756c;
          iVar8 = DAT_00667570;
        }
        uVar11 = uVar11 + 1;
        iVar6 = iVar6 + 0x40;
      } while (uVar11 < (uint)(iVar8 - iVar7 >> 6));
    }
    FUN_00506e90(iVar8,iVar8,iVar7,param_1,0);
    DAT_00667570 = DAT_00667570 + (iVar8 - iVar7 >> 6) * -0x40;
    iVar7 = DAT_0066758c - DAT_00667588 >> 0x1f;
    uVar11 = 0;
    iVar8 = DAT_00667588;
    iVar6 = DAT_0066758c;
    iVar12 = DAT_0066758c;
    iVar9 = DAT_00667588;
    if ((DAT_0066758c - DAT_00667588) / 0x14 + iVar7 != iVar7) {
      iVar7 = 0;
      do {
        if (*(int *)(iVar7 + 0xc + iVar8) != 0) {
          *(undefined4 *)(iVar7 + 0x10 + iVar8) = 1;
          FUN_00505430(uVar11);
          iVar8 = DAT_00667588;
          iVar6 = DAT_0066758c;
        }
        uVar11 = uVar11 + 1;
        iVar7 = iVar7 + 0x14;
        iVar12 = iVar6;
        iVar9 = iVar8;
      } while (uVar11 < (uint)((iVar6 - iVar8) / 0x14));
    }
    for (; iVar8 != iVar12; iVar8 = iVar8 + 0x14) {
      FUN_004815f0(0);
      iVar6 = DAT_0066758c;
    }
    iVar7 = (int)((ulonglong)((longlong)(iVar12 - iVar9) * -0x66666667) >> 0x20);
    DAT_0066758c = iVar6 + ((iVar7 >> 3) - (iVar7 >> 0x1f)) * 0x14;
    uVar11 = 0xffffffff;
    pcVar13 = (char *)&DAT_005d5a24;
    do {
      if (uVar11 == 0) break;
      uVar11 = uVar11 - 1;
      cVar2 = *pcVar13;
      pcVar13 = pcVar13 + 1;
    } while (cVar2 != '\0');
    uVar5 = (int)DAT_006675b4 - (int)DAT_006675b0;
    uVar4 = ~uVar11 - 1;
    if (uVar5 < uVar4) {
      puVar10 = &DAT_005d5a24;
      puVar14 = DAT_006675b0;
      for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar14 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar14 = puVar14 + 1;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)puVar14 = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        puVar14 = (undefined4 *)((int)puVar14 + 1);
      }
      FUN_00403490((int)&DAT_005d5a24 + ((int)DAT_006675b4 - (int)DAT_006675b0),~uVar11 + 0x5d5a23);
    }
    else {
      puVar10 = &DAT_005d5a24;
      puVar14 = DAT_006675b0;
      for (uVar11 = uVar4 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
        *puVar14 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar14 = puVar14 + 1;
      }
      for (uVar11 = uVar4 & 3; puVar3 = DAT_006675b4, uVar11 != 0; uVar11 = uVar11 - 1) {
        *(undefined1 *)puVar14 = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        puVar14 = (undefined4 *)((int)puVar14 + 1);
      }
      puVar1 = (undefined1 *)((int)DAT_006675b0 + uVar4);
      if (puVar1 != DAT_006675b4) {
        FUN_005092c0(puVar1,DAT_006675b4,1);
        DAT_006675b4 = DAT_006675b4 + ((int)puVar1 - (int)puVar3);
      }
    }
    FUN_005259e0(0);
    FUN_00525900(DAT_006675e4);
    DAT_006675e4 = 0;
    FUN_00527c90(DAT_006675e0);
    DAT_006675e0 = 0;
    DAT_006675dc = '\0';
  }
  return;
}


