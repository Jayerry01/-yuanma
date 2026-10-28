undefined4 __thiscall FUN_005611b0(int param_1,char *param_2)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  char *pcVar12;
  char *pcVar13;
  bool bVar14;
  int local_58;
  int local_54;
  int local_50;
  char local_4c [16];
  undefined1 local_3c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a562b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined1 *)(param_1 + 0x250) = 0;
  *(undefined4 *)(param_1 + 0x4b8) = 0;
  if ((*(char *)(param_1 + 0x256) == '\0') && (*(int *)(param_1 + 0x2f4) != 0)) {
    FUN_00507850(*(int *)(param_1 + 0x2f4));
    *(undefined4 *)(param_1 + 0x2f4) = 0;
  }
  uVar9 = 0xffffffff;
  pcVar12 = param_2;
  do {
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar1 != '\0');
  if ((param_2[~uVar9 - 2] == 'b') || (param_2[~uVar9 - 2] == 'B')) {
    *(undefined1 *)(param_1 + 0x252) = 1;
    puVar2 = &DAT_005c4580;
  }
  else {
    *(undefined1 *)(param_1 + 0x252) = 0;
    puVar2 = &DAT_005ca380;
  }
  iVar3 = FUN_00509f8f(param_2,puVar2);
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    FUN_0050a118(local_4c,0x10,1,iVar3);
    iVar10 = 0x11;
    bVar14 = true;
    local_3c = 0;
    pcVar12 = local_4c;
    pcVar13 = s_Section_PVS_V1_0_005d14c8;
    do {
      if (iVar10 == 0) break;
      iVar10 = iVar10 + -1;
      bVar14 = *pcVar12 == *pcVar13;
      pcVar12 = pcVar12 + 1;
      pcVar13 = pcVar13 + 1;
    } while (bVar14);
    if (bVar14) {
      FUN_0050a118((int *)(param_1 + 0x468),4,1,iVar3);
      FUN_0050a118(param_1 + 0x46c,4,1,iVar3);
      FUN_0050a118(param_1 + 0x470,4,1,iVar3);
      FUN_0050a118(param_1 + 0x464,4,1,iVar3);
      FUN_0050a118(param_1 + 0x458,4,3,iVar3);
      FUN_0050a118(param_1 + 0x440,4,3,iVar3);
      FUN_0050a118(param_1 + 0x44c,4,3,iVar3);
      iVar5 = FUN_0050a38c(iVar3);
      FUN_0050a2d3(iVar3,0,2);
      iVar6 = FUN_0050a38c(iVar3);
      FUN_0050a2d3(iVar3,iVar5,0);
      iVar10 = *(int *)(param_1 + 0x464);
      *(int *)(param_1 + 0x474) = *(int *)(param_1 + 0x46c) * *(int *)(param_1 + 0x468);
      pvVar7 = operator_new(iVar10 * 0xc);
      local_4 = 0;
      if (pvVar7 == (void *)0x0) {
        pvVar7 = (void *)0x0;
      }
      else if (-1 < iVar10 + -1) {
        do {
          FUN_0057df30();
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
      local_4 = 0xffffffff;
      *(void **)(param_1 + 0x2e4) = pvVar7;
      pvVar7 = operator_new(iVar6 - iVar5);
      iVar10 = 0;
      *(void **)(param_1 + 0x2e8) = pvVar7;
      local_54 = 0;
      *(undefined4 *)(param_1 + 0x25c) = 0;
      uVar4 = FUN_0056b1f0();
      *(undefined4 *)(param_1 + 0x260) = uVar4;
      local_58 = 0;
      local_50 = 0;
      if (0 < *(int *)(param_1 + 0x464)) {
        param_2 = (char *)0x0;
        do {
          iVar6 = *(int *)(param_1 + 0x2e4) + (int)param_2;
          iVar5 = FUN_0057df40(iVar3,*(int *)(param_1 + 0x2e8) + iVar10);
          iVar10 = iVar10 + *(int *)(iVar6 + 4);
          if (local_54 < iVar5) {
            local_54 = iVar5;
          }
          if (*(int *)(param_1 + 0x25c) < *(int *)(iVar6 + 8)) {
            *(int *)(param_1 + 0x25c) = *(int *)(iVar6 + 8);
          }
          if (*(int *)(param_1 + 0x260) < *(int *)(iVar6 + 8)) {
            *(int *)(param_1 + 0x260) = *(int *)(iVar6 + 8);
          }
          local_58 = local_58 + *(int *)(iVar6 + 8);
          param_2 = (char *)((int)param_2 + 0xc);
          local_50 = local_50 + 1;
        } while (local_50 < *(int *)(param_1 + 0x464));
      }
      FUN_00509e57(iVar3);
      *(int *)(param_1 + 0x264) = local_58 / *(int *)(param_1 + 0x464);
      puVar8 = operator_new(*(int *)(param_1 + 0x25c) * 6);
      *(undefined4 **)(param_1 + 0x2fc) = puVar8;
      if (puVar8 == (undefined4 *)0x0) {
        uVar4 = 0;
      }
      else {
        uVar9 = *(int *)(param_1 + 0x25c) * 6;
        for (uVar11 = uVar9 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
          *puVar8 = 0xffffffff;
          puVar8 = puVar8 + 1;
        }
        for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined1 *)puVar8 = 0xff;
          puVar8 = (undefined4 *)((int)puVar8 + 1);
        }
        puVar8 = operator_new(*(int *)(param_1 + 0x25c) << 2);
        *(undefined4 **)(param_1 + 0x2f8) = puVar8;
        uVar4 = 0;
        if (puVar8 != (undefined4 *)0x0) {
          for (uVar9 = *(uint *)(param_1 + 0x25c) & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
            *puVar8 = 0xffffffff;
            puVar8 = puVar8 + 1;
          }
          for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
            *(undefined1 *)puVar8 = 0xff;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
          }
          if (*(char *)(param_1 + 0x255) != '\0') {
            uVar4 = thunk_FUN_004d5fb0(*(int *)(param_1 + 0x25c) * 3);
            *(undefined4 *)(param_1 + 0x2f4) = uVar4;
          }
          if (*(int *)(param_1 + 0x2f4) == 0) {
            *(undefined1 *)(param_1 + 0x256) = 0;
            pvVar7 = operator_new(*(int *)(param_1 + 0x25c) * 0x48);
            *(void **)(param_1 + 0x2f4) = pvVar7;
            if (pvVar7 == (void *)0x0) {
              ExceptionList = local_c;
              return 0;
            }
          }
          else {
            *(undefined1 *)(param_1 + 0x256) = 1;
          }
          *(undefined1 *)(param_1 + 0x250) = 1;
          uVar4 = 1;
        }
      }
    }
    else {
      FUN_0050ac20(s_Invalid_PVS_file_005d14b4);
      uVar4 = 0;
    }
  }
  ExceptionList = local_c;
  return uVar4;
}


