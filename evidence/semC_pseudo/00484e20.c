undefined4 FUN_00484e20(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  undefined4 local_504;
  int local_500;
  int local_4fc;
  int local_4f8;
  int local_4f4;
  uint local_4f0 [316];
  
  iVar3 = FUN_00484560(5);
  local_500 = iVar3 + 0x101;
  iVar4 = FUN_00484560(5);
  local_4f4 = iVar4 + 1;
  iVar5 = FUN_00484560(4);
  uVar8 = 0;
  if (iVar5 != -4) {
    do {
      uVar6 = FUN_00484560(3);
      piVar1 = &DAT_005c8a50 + uVar8;
      uVar8 = uVar8 + 1;
      local_4f0[*piVar1] = uVar6;
    } while (uVar8 < iVar5 + 4U);
    if (0x12 < uVar8) goto LAB_00484e93;
  }
  do {
    piVar1 = &DAT_005c8a50 + uVar8;
    uVar8 = uVar8 + 1;
    local_4f0[*piVar1] = 0;
  } while (uVar8 < 0x13);
LAB_00484e93:
  local_504 = 7;
  iVar5 = FUN_00484860(local_4f0,0x13,0x13,0,0,&local_4fc,&local_504);
  if (iVar5 != 0) {
    return 1;
  }
  uVar7 = iVar3 + 0x101 + iVar4 + 1;
  uVar8 = 0;
  uVar6 = 0;
  if (uVar7 != 0) {
    do {
      iVar4 = FUN_00484590(local_504);
      iVar3 = local_4fc + iVar4 * 6;
      local_4f8 = iVar3;
      FUN_00484560(*(undefined1 *)(local_4fc + 1 + iVar4 * 6));
      uVar2 = *(uint *)(iVar3 + 2);
      if (uVar2 < 0x10) {
        local_4f0[uVar6] = uVar2;
        uVar8 = uVar2;
        uVar6 = uVar6 + 1;
      }
      else if (uVar2 == 0x10) {
        iVar3 = FUN_00484560(2);
        iVar3 = iVar3 + 3;
        uVar2 = uVar6 + iVar3;
        if (uVar7 < uVar2) {
          return 1;
        }
        if (iVar3 != 0) {
          puVar9 = local_4f0 + uVar6;
          for (; uVar6 = uVar2, iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar9 = uVar8;
            puVar9 = puVar9 + 1;
          }
        }
      }
      else {
        if (uVar2 == 0x11) {
          iVar3 = FUN_00484560(3);
          iVar3 = iVar3 + 3;
        }
        else {
          iVar3 = FUN_00484560(7);
          iVar3 = iVar3 + 0xb;
        }
        uVar8 = uVar6 + iVar3;
        if (uVar7 < uVar8) {
          return 1;
        }
        if (iVar3 != 0) {
          puVar9 = local_4f0 + uVar6;
          for (; uVar6 = uVar8, iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar9 = 0;
            puVar9 = puVar9 + 1;
          }
        }
        uVar8 = 0;
      }
    } while (uVar6 < uVar7);
  }
  FUN_00484c90(local_4fc);
  iVar3 = local_500;
  local_504 = 9;
  iVar4 = FUN_00484860(local_4f0,local_500,0x101,&DAT_005c8aa0,&DAT_005c8b20,&local_4fc,&local_504);
  if (iVar4 != 0) {
    return 1;
  }
  local_500 = 6;
  iVar4 = FUN_00484860(local_4f0 + iVar3,local_4f4,0,&DAT_005c8ba0,&DAT_005c8c18,&local_4f8,
                       &local_500);
  iVar3 = local_4f8;
  if (iVar4 == 0) {
    iVar4 = FUN_00484cb0(local_4fc,local_4f8,local_504,local_500);
    if (iVar4 != 0) {
      return 1;
    }
    FUN_00484c90(local_4fc);
    FUN_00484c90(iVar3);
    return 0;
  }
  return 1;
}


