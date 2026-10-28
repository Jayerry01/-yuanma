undefined4 FUN_00510e4c(undefined4 param_1)

{
  BYTE *pBVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  UINT CodePage;
  UINT *pUVar5;
  BOOL BVar6;
  uint uVar7;
  uint uVar8;
  BYTE *pBVar9;
  int iVar10;
  byte *pbVar11;
  int iVar12;
  byte *pbVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  _cpinfo local_1c;
  uint local_8;
  
  FUN_0050dd18(0x19);
  CodePage = FUN_00510ff9(param_1);
  if (CodePage != DAT_007f1b20) {
    if (CodePage != 0) {
      iVar12 = 0;
      pUVar5 = &DAT_005cd0b8;
LAB_00510e89:
      if (*pUVar5 != CodePage) goto code_r0x00510e8d;
      local_8 = 0;
      puVar15 = &DAT_007f1c40;
      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      iVar12 = iVar12 * 0x30;
      *(undefined1 *)puVar15 = 0;
      pbVar13 = (byte *)(iVar12 + 0x5cd0c8);
      do {
        bVar3 = *pbVar13;
        pbVar11 = pbVar13;
        while ((bVar3 != 0 && (bVar3 = pbVar11[1], bVar3 != 0))) {
          uVar8 = (uint)*pbVar11;
          if (uVar8 <= bVar3) {
            bVar4 = (&DAT_005cd0b0)[local_8];
            do {
              pbVar2 = (byte *)((int)&DAT_007f1c40 + uVar8 + 1);
              *pbVar2 = *pbVar2 | bVar4;
              uVar8 = uVar8 + 1;
            } while (uVar8 <= bVar3);
          }
          pbVar11 = pbVar11 + 2;
          bVar3 = *pbVar11;
        }
        local_8 = local_8 + 1;
        pbVar13 = pbVar13 + 8;
      } while (local_8 < 4);
      DAT_007f1b3c = 1;
      DAT_007f1b20 = CodePage;
      DAT_007f1d44 = FUN_00511043(CodePage);
      DAT_007f1b30 = *(undefined4 *)(iVar12 + 0x5cd0bc);
      DAT_007f1b34 = *(undefined4 *)(iVar12 + 0x5cd0c0);
      DAT_007f1b38 = *(undefined4 *)(iVar12 + 0x5cd0c4);
      goto LAB_00510fdd;
    }
    goto LAB_00510fd8;
  }
  goto LAB_00510e73;
code_r0x00510e8d:
  pUVar5 = pUVar5 + 0xc;
  iVar12 = iVar12 + 1;
  if (0x5cd1a7 < (int)pUVar5) goto code_r0x00510e98;
  goto LAB_00510e89;
code_r0x00510e98:
  BVar6 = GetCPInfo(CodePage,&local_1c);
  uVar8 = 1;
  if (BVar6 == 1) {
    DAT_007f1d44 = 0;
    puVar15 = &DAT_007f1c40;
    for (iVar12 = 0x40; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar15 = 0;
      puVar15 = puVar15 + 1;
    }
    *(undefined1 *)puVar15 = 0;
    if (local_1c.MaxCharSize < 2) {
      DAT_007f1b3c = 0;
      DAT_007f1b20 = CodePage;
    }
    else {
      DAT_007f1b20 = CodePage;
      if (local_1c.LeadByte[0] != '\0') {
        pBVar9 = local_1c.LeadByte + 1;
        do {
          bVar3 = *pBVar9;
          if (bVar3 == 0) break;
          for (uVar7 = (uint)pBVar9[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
            pbVar13 = (byte *)((int)&DAT_007f1c40 + uVar7 + 1);
            *pbVar13 = *pbVar13 | 4;
          }
          pBVar1 = pBVar9 + 1;
          pBVar9 = pBVar9 + 2;
        } while (*pBVar1 != 0);
      }
      do {
        pbVar13 = (byte *)((int)&DAT_007f1c40 + uVar8 + 1);
        *pbVar13 = *pbVar13 | 8;
        uVar8 = uVar8 + 1;
      } while (uVar8 < 0xff);
      DAT_007f1d44 = FUN_00511043(CodePage);
      DAT_007f1b3c = 1;
    }
    DAT_007f1b30 = 0;
    DAT_007f1b34 = 0;
    DAT_007f1b38 = 0;
  }
  else {
    if (DAT_00667864 == 0) {
      uVar14 = 0xffffffff;
      goto LAB_00510fea;
    }
LAB_00510fd8:
    FUN_00511076();
  }
LAB_00510fdd:
  FUN_0051109f();
LAB_00510e73:
  uVar14 = 0;
LAB_00510fea:
  FUN_0050dd79(0x19);
  return uVar14;
}


