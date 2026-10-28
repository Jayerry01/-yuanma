void __thiscall FUN_00550210(int *param_1,char *param_2,char *param_3)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  uVar4 = 0xffffffff;
  pcVar5 = param_2;
  if (param_2 == (char *)0x0) {
    pcVar5 = (char *)&DAT_005d5a24;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    pcVar5 = (char *)((int)&DAT_005d5a20 + ~uVar4 + 3);
    param_2 = (char *)&DAT_005d5a24;
  }
  else {
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    pcVar5 = param_2 + (~uVar4 - 1);
  }
  FUN_00403200(param_2,pcVar5);
  uVar4 = 0xffffffff;
  if (param_3 == (char *)0x0) {
    pcVar5 = (char *)&DAT_005d5a24;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    FUN_00403200(&DAT_005d5a24,~uVar4 + 0x5d5a23);
  }
  else {
    piVar1 = param_1 + 0x191;
    pcVar5 = param_3;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    pcVar5 = (char *)*piVar1;
    uVar6 = param_1[0x192] - (int)pcVar5;
    uVar3 = (int)(param_3 + (~uVar4 - 1)) - (int)param_3;
    if (uVar6 < uVar3) {
      pcVar7 = param_3;
      for (uVar3 = uVar6 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined4 *)pcVar5 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar5 = pcVar5 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar5 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar5 = pcVar5 + 1;
      }
      FUN_00403490(param_3 + (param_1[0x192] - *piVar1),param_3 + (~uVar4 - 1));
    }
    else {
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar5 = *(undefined4 *)param_3;
        param_3 = param_3 + 4;
        pcVar5 = pcVar5 + 4;
      }
      for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar5 = *param_3;
        param_3 = param_3 + 1;
        pcVar5 = pcVar5 + 1;
      }
      FUN_00402b30(*piVar1 + uVar3,param_1[0x192]);
    }
  }
  if ((char)param_1[0x19f] == '\0') {
    uVar4 = 0xffffffff;
    param_1[0x184] = 0;
    param_1[0x185] = 0;
    piVar1 = param_1 + 0x18b;
    pcVar5 = (char *)&DAT_005d5a24;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    puVar9 = (undefined4 *)*piVar1;
    uVar6 = param_1[0x18c] - (int)puVar9;
    uVar3 = ~uVar4 - 1;
    if (uVar6 < uVar3) {
      puVar8 = &DAT_005d5a24;
      for (uVar3 = uVar6 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      FUN_00403490((int)&DAT_005d5a24 + (param_1[0x18c] - *piVar1),~uVar4 + 0x5d5a23);
    }
    else {
      puVar8 = &DAT_005d5a24;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      FUN_00402b30(*piVar1 + uVar3,param_1[0x18c]);
    }
    param_1[0x186] = 0;
    param_1[0x187] = 0;
    param_1[0x188] = 0;
    uVar4 = 0xffffffff;
    param_1[0x189] = 0;
    param_1[0x18a] = 0;
    piVar1 = param_1 + 0x194;
    pcVar5 = (char *)&DAT_005d5a24;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    puVar9 = (undefined4 *)*piVar1;
    uVar6 = param_1[0x195] - (int)puVar9;
    uVar3 = ~uVar4 - 1;
    if (uVar6 < uVar3) {
      puVar8 = &DAT_005d5a24;
      for (uVar3 = uVar6 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      FUN_00403490((int)&DAT_005d5a24 + (param_1[0x195] - *piVar1),~uVar4 + 0x5d5a23);
    }
    else {
      puVar8 = &DAT_005d5a24;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      FUN_00402b30(*piVar1 + uVar3,param_1[0x195]);
    }
    uVar4 = 0xffffffff;
    pcVar5 = (char *)&DAT_005d5a24;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    FUN_00403200(&DAT_005d5a24,~uVar4 + 0x5d5a23);
    param_1[0x19a] = 0;
  }
  param_1[0x19e] = 0;
  cVar2 = FUN_00550530(s_Lobby_lst_005d1180);
  if (cVar2 != '\0') {
    (**(code **)(*param_1 + 4))(param_1[0x19b]);
    return;
  }
  (**(code **)(*param_1 + 0x44))(1);
  return;
}


