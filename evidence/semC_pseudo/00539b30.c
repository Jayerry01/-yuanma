int FUN_00539b30(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte *local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  iVar6 = DAT_0072c668;
  local_24 = DAT_0072c660;
  DAT_0072c66c = (DAT_0072c664 + -1) / 3 + 0x1e;
  pbVar1 = DAT_0072c660 + DAT_0072c668;
  local_1c = 0x400;
  iVar2 = DAT_0072c668 / (DAT_0072c664 * 3);
  local_14 = 0x800;
  iVar7 = 0x20;
  iVar5 = 0;
  do {
    iVar3 = (0x400 - iVar5 * iVar5) * 0x100;
    (&DAT_0072ce80)[iVar5] = ((int)(iVar3 + (iVar3 >> 0x1f & 0x3ffU)) >> 10) << 10;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x20);
  iVar5 = iVar6 / 499;
  if (iVar6 % 499 == 0) {
    iVar5 = iVar6 / 0x1eb;
    if (iVar6 % 0x1eb == 0) {
      iVar5 = iVar6 / 0x1e7;
      local_20 = (-(uint)(iVar6 % 0x1e7 != 0) & 0xffffffd0) + 0x5e5;
    }
    else {
      local_20 = 0x5c1;
    }
  }
  else {
    local_20 = 0x5d9;
  }
  local_18 = 0;
  if (0 < iVar2) {
    do {
      iVar5 = (uint)local_24[2] << 4;
      iVar6 = (uint)local_24[1] << 4;
      iVar3 = (uint)*local_24 << 4;
      uVar4 = FUN_00539850(iVar3,iVar6,iVar5);
      FUN_00539930(local_1c,uVar4,iVar3,iVar6,iVar5);
      if (iVar7 != 0) {
        FUN_005399b0(iVar7,uVar4,iVar3,iVar6,iVar5);
      }
      local_24 = local_24 + local_20;
      if (pbVar1 <= local_24) {
        local_24 = local_24 + -DAT_0072c668;
      }
      local_18 = local_18 + 1;
      iVar5 = local_18 / (iVar2 / 100);
      if (local_18 % (iVar2 / 100) == 0) {
        local_1c = local_1c - local_1c / DAT_0072c66c;
        iVar6 = (int)((ulonglong)((longlong)local_14 * 0x77777777) >> 0x20) - local_14;
        iVar5 = -(iVar6 >> 0x1f);
        local_14 = local_14 + (iVar6 >> 4) + iVar5;
        iVar7 = local_14 >> 6;
        if (iVar7 < 2) {
          iVar7 = 0;
        }
        iVar6 = 0;
        if (0 < iVar7) {
          do {
            iVar5 = (((iVar7 * iVar7 - iVar6 * iVar6) * 0x100) / (iVar7 * iVar7)) * local_1c;
            (&DAT_0072ce80)[iVar6] = iVar5;
            iVar6 = iVar6 + 1;
          } while (iVar6 < iVar7);
        }
      }
    } while (local_18 < iVar2);
  }
  return iVar5;
}


