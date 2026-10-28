void FUN_005415c0(int *param_1,char param_2,int param_3,int *param_4)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined1 *puVar11;
  int iVar12;
  int iVar13;
  char *pcVar14;
  int iVar15;
  undefined4 *puVar16;
  int iStack_520;
  int iStack_514;
  int iStack_510;
  char acStack_508 [256];
  int aiStack_408 [258];
  
  if ((param_3 < 0) || (3 < param_3)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x32;
    *(int *)(*param_1 + 0x18) = param_3;
    (**(code **)*param_1)(param_1);
  }
  if (param_2 == '\0') {
    iVar12 = param_1[param_3 + 0x2c];
  }
  else {
    iVar12 = param_1[param_3 + 0x28];
  }
  if (iVar12 == 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x32;
    *(int *)(*param_1 + 0x18) = param_3;
    (**(code **)*param_1)(param_1);
  }
  if (*param_4 == 0) {
    iVar2 = (**(code **)param_1[1])(param_1,1,0x590);
    *param_4 = iVar2;
  }
  iVar2 = *param_4;
  iVar9 = 0;
  *(int *)(iVar2 + 0x8c) = iVar12;
  iStack_520 = 1;
  do {
    bVar1 = *(byte *)(iStack_520 + iVar12);
    uVar5 = (uint)bVar1;
    if (0x100 < (int)(uVar5 + iVar9)) {
      *(undefined4 *)(*param_1 + 0x14) = 8;
      (**(code **)*param_1)(param_1);
    }
    if (uVar5 != 0) {
      cVar7 = (char)iStack_520;
      pcVar14 = acStack_508 + iVar9;
      for (uVar4 = (uint)(bVar1 >> 2); uVar4 != 0; uVar4 = uVar4 - 1) {
        *(uint *)pcVar14 = CONCAT22(CONCAT11(cVar7,cVar7),CONCAT11(cVar7,cVar7));
        pcVar14 = pcVar14 + 4;
      }
      iVar9 = iVar9 + uVar5;
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar14 = cVar7;
        pcVar14 = pcVar14 + 1;
      }
    }
    iStack_520 = iStack_520 + 1;
  } while (iStack_520 < 0x11);
  acStack_508[iVar9] = '\0';
  iVar15 = 0;
  iVar13 = 0;
  iVar8 = (int)acStack_508[0];
  iVar10 = iVar8;
  while (acStack_508[0] != '\0') {
    while (iVar10 == iVar8) {
      cVar7 = acStack_508[iVar13 + 1];
      aiStack_408[iVar13 + 1] = iVar15;
      iVar13 = iVar13 + 1;
      iVar15 = iVar15 + 1;
      iVar10 = (int)cVar7;
    }
    if (1 << ((byte)iVar8 & 0x1f) <= iVar15) {
      *(undefined4 *)(*param_1 + 0x14) = 8;
      (**(code **)*param_1)(param_1);
    }
    iVar15 = iVar15 * 2;
    iVar8 = iVar8 + 1;
    acStack_508[0] = acStack_508[iVar13];
  }
  iVar10 = 0;
  iVar15 = 1;
  do {
    if (*(char *)(iVar15 + iVar12) == '\0') {
      *(undefined4 *)(iVar2 + iVar15 * 4) = 0xffffffff;
    }
    else {
      *(int *)(iVar2 + 0x48 + iVar15 * 4) = iVar10 - aiStack_408[iVar10 + 1];
      iVar10 = iVar10 + (uint)*(byte *)(iVar15 + iVar12);
      *(int *)(iVar2 + iVar15 * 4) = aiStack_408[iVar10];
    }
    iVar15 = iVar15 + 1;
  } while (iVar15 < 0x11);
  *(undefined4 *)(iVar2 + 0x44) = 0xfffff;
  puVar16 = (undefined4 *)(iVar2 + 0x90);
  for (iVar15 = 0x100; iVar15 != 0; iVar15 = iVar15 + -1) {
    *puVar16 = 0;
    puVar16 = puVar16 + 1;
  }
  iVar15 = 0;
  iStack_510 = 0;
  iVar10 = 1;
  iStack_520 = 7;
  do {
    iStack_514 = 1;
    if (*(char *)(iVar10 + iVar12) != '\0') {
      iVar13 = 1 << ((byte)iStack_520 & 0x1f);
      puVar11 = (undefined1 *)(iVar15 + 0x11 + iVar12);
      do {
        iVar8 = aiStack_408[iVar15 + 1] << ((byte)iStack_520 & 0x1f);
        if (0 < iVar13) {
          puVar6 = (undefined1 *)(iVar8 + 0x490 + iVar2);
          piVar3 = (int *)(iVar2 + 0x90 + iVar8 * 4);
          iVar8 = iVar13;
          do {
            *piVar3 = iVar10;
            *puVar6 = *puVar11;
            piVar3 = piVar3 + 1;
            puVar6 = puVar6 + 1;
            iVar8 = iVar8 + -1;
            iVar15 = iStack_510;
          } while (iVar8 != 0);
        }
        iStack_514 = iStack_514 + 1;
        iVar15 = iVar15 + 1;
        puVar11 = puVar11 + 1;
        iStack_510 = iVar15;
      } while (iStack_514 <= (int)(uint)*(byte *)(iVar10 + iVar12));
    }
    iVar10 = iVar10 + 1;
    iStack_520 = iStack_520 + -1;
  } while (-1 < iStack_520);
  if ((param_2 != '\0') && (iVar2 = 0, 0 < iVar9)) {
    do {
      if (0xf < *(byte *)(iVar12 + 0x11 + iVar2)) {
        *(undefined4 *)(*param_1 + 0x14) = 8;
        (**(code **)*param_1)(param_1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar9);
  }
  return;
}


