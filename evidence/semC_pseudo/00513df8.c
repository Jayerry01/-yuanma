undefined4 FUN_00513df8(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  undefined4 *puVar6;
  undefined4 local_10;
  undefined4 local_c;
  
  bVar1 = false;
  if (param_1 == 2) {
    puVar6 = &DAT_0066799c;
    pcVar5 = DAT_0066799c;
LAB_00513e7e:
    bVar1 = true;
    FUN_0050dd18(1);
    iVar2 = param_1;
  }
  else {
    if (((param_1 != 4) && (param_1 != 8)) && (param_1 != 0xb)) {
      if (param_1 == 0xf) {
        puVar6 = &DAT_006679a8;
        pcVar5 = DAT_006679a8;
      }
      else if (param_1 == 0x15) {
        puVar6 = &DAT_006679a0;
        pcVar5 = DAT_006679a0;
      }
      else {
        if (param_1 != 0x16) {
          return 0xffffffff;
        }
        puVar6 = &DAT_006679a4;
        pcVar5 = DAT_006679a4;
      }
      goto LAB_00513e7e;
    }
    iVar2 = FUN_0050ef73();
    iVar4 = FUN_00513f7a(param_1,*(undefined4 *)(iVar2 + 0x50));
    puVar6 = (undefined4 *)(iVar4 + 8);
    pcVar5 = (code *)*puVar6;
  }
  if (pcVar5 == (code *)0x1) {
    if (!bVar1) {
      return 0;
    }
    FUN_0050dd79(1);
    return 0;
  }
  if (pcVar5 == (code *)0x0) {
    if (bVar1) {
      FUN_0050dd79(1);
    }
                    // WARNING: Subroutine does not return
    __exit(3);
  }
  if (((param_1 == 8) || (param_1 == 0xb)) || (param_1 == 4)) {
    local_c = *(undefined4 *)(iVar2 + 0x54);
    *(undefined4 *)(iVar2 + 0x54) = 0;
    if (param_1 == 8) {
      local_10 = *(undefined4 *)(iVar2 + 0x58);
      *(undefined4 *)(iVar2 + 0x58) = 0x8c;
      goto LAB_00513ef2;
    }
  }
  else {
LAB_00513ef2:
    if (param_1 == 8) {
      if (DAT_005ccd58 < DAT_005ccd5c + DAT_005ccd58) {
        iVar3 = DAT_005ccd58 * 0xc;
        iVar4 = DAT_005ccd58;
        do {
          iVar3 = iVar3 + 0xc;
          *(undefined4 *)(*(int *)(iVar2 + 0x50) + -4 + iVar3) = 0;
          iVar4 = iVar4 + 1;
        } while (iVar4 < DAT_005ccd5c + DAT_005ccd58);
      }
      goto LAB_00513f30;
    }
  }
  *puVar6 = 0;
LAB_00513f30:
  if (bVar1) {
    FUN_0050dd79(1);
  }
  if (param_1 == 8) {
    (*pcVar5)(8,*(undefined4 *)(iVar2 + 0x58));
  }
  else {
    (*pcVar5)(param_1);
    if ((param_1 != 0xb) && (param_1 != 4)) {
      return 0;
    }
  }
  *(undefined4 *)(iVar2 + 0x54) = local_c;
  if (param_1 == 8) {
    *(undefined4 *)(iVar2 + 0x58) = local_10;
  }
  return 0;
}


