undefined4 __fastcall FUN_0047fa70(int param_1)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  byte *pbVar9;
  int local_8;
  
  if (*(int *)(param_1 + 0xa0) == 0) {
    return 0;
  }
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x88);
  cVar3 = FUN_0047fd10(*(undefined4 *)(param_1 + 0x88));
  if (cVar3 == '\0') {
    uVar4 = FUN_0047fd40(*(undefined4 *)(param_1 + 0x88));
    *(undefined4 *)(param_1 + 0x98) = uVar4;
  }
  if (DAT_005c8168 < *(int *)(param_1 + 0x98)) {
    *(int *)(param_1 + 0x98) = DAT_005c8168;
  }
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x8c);
  cVar3 = FUN_0047fd10(*(undefined4 *)(param_1 + 0x8c));
  if (cVar3 == '\0') {
    uVar4 = FUN_0047fd40(*(undefined4 *)(param_1 + 0x8c));
    *(undefined4 *)(param_1 + 0x9c) = uVar4;
  }
  if (DAT_005c816c < *(int *)(param_1 + 0x9c)) {
    *(int *)(param_1 + 0x9c) = DAT_005c816c;
  }
  if (DAT_005c8170 == 0) {
    if (0x20 < *(int *)(param_1 + 0x98)) {
      *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) / 2;
    }
    iVar8 = *(int *)(param_1 + 0x9c);
    if (iVar8 < 0x21) goto LAB_0047fb75;
  }
  else {
    if (DAT_005c8170 != 1) goto LAB_0047fb75;
    iVar8 = *(int *)(param_1 + 0x9c);
    iVar2 = *(int *)(param_1 + 0x98);
    if ((iVar8 < iVar2) || (iVar8 < 0x21)) {
      if (0x20 < iVar2) {
        *(int *)(param_1 + 0x98) = iVar2 / 2;
      }
      goto LAB_0047fb75;
    }
  }
  *(int *)(param_1 + 0x9c) = iVar8 / 2;
LAB_0047fb75:
  if (DAT_00628534 != 0) {
    if (*(int *)(param_1 + 0x98) < *(int *)(param_1 + 0x9c)) {
      *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0x98);
    }
    else {
      *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x9c);
    }
  }
  FUN_0047f9e0(*(undefined4 *)(param_1 + 0x98),*(undefined4 *)(param_1 + 0x9c));
  FUN_0052c070(*(undefined4 *)(param_1 + 0x80));
  pbVar5 = (byte *)FUN_0052caf0();
  pbVar9 = (byte *)0x0;
  if (*(int *)(param_1 + 0xa4) != 0) {
    FUN_0052c070(*(undefined4 *)(param_1 + 0x84));
    pbVar9 = (byte *)FUN_0052caf0();
  }
  pbVar6 = operator_new(*(int *)(param_1 + 0x9c) * *(int *)(param_1 + 0x98) * 4);
  if (pbVar6 != (byte *)0x0) {
    local_8 = 0;
    pbVar7 = pbVar6;
    if (0 < *(int *)(param_1 + 0x9c)) {
      do {
        iVar8 = 0;
        if (0 < *(int *)(param_1 + 0x98)) {
          do {
            *pbVar7 = *pbVar5;
            pbVar7[1] = pbVar5[1];
            pbVar7[2] = pbVar5[2];
            if (*(int *)(param_1 + 0xb8) == 0x42d) {
              pbVar7[3] = pbVar5[3];
            }
            else if (*(int *)(param_1 + 0xa4) == 0) {
              if ((((*(int *)(param_1 + 0xa8) == 0) || ((uint)*pbVar5 != *(uint *)(param_1 + 0xac)))
                  || ((uint)pbVar5[1] != *(uint *)(param_1 + 0xb0))) ||
                 ((uint)pbVar5[2] != *(uint *)(param_1 + 0xb4))) {
                pbVar7[3] = 0xff;
              }
              else {
                pbVar7[3] = 0;
              }
            }
            else {
              bVar1 = *pbVar9;
              pbVar9 = pbVar9 + 1;
              pbVar7[3] = bVar1;
            }
            pbVar7 = pbVar7 + 4;
            pbVar5 = pbVar5 + 4;
            iVar8 = iVar8 + 1;
          } while (iVar8 < *(int *)(param_1 + 0x98));
        }
        local_8 = local_8 + 1;
      } while (local_8 < *(int *)(param_1 + 0x9c));
    }
    FUN_0052c070(*(undefined4 *)(param_1 + 0x80));
    FUN_0052ca60(pbVar6);
    FUN_0052fa40();
    FUN_00507850(pbVar6);
    return 1;
  }
  return 0;
}


