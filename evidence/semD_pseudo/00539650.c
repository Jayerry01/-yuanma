void FUN_00539650(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  piVar5 = &DAT_0072330c;
  iVar4 = 0;
  do {
    iVar3 = piVar5[-4];
    iVar1 = iVar4 + 1;
    piVar2 = piVar5;
    iVar6 = iVar1;
    iVar7 = iVar4;
    if (iVar1 < 0x100) {
      do {
        if (*piVar2 < iVar3) {
          iVar7 = iVar6;
          iVar3 = *piVar2;
        }
        piVar2 = piVar2 + 4;
        iVar6 = iVar6 + 1;
      } while ((int)piVar2 < 0x7242fc);
    }
    if (iVar4 != iVar7) {
      iVar6 = (&DAT_007232f8)[iVar7 * 4];
      (&DAT_007232f8)[iVar7 * 4] = piVar5[-5];
      piVar5[-5] = iVar6;
      iVar6 = (&DAT_007232fc)[iVar7 * 4];
      (&DAT_007232fc)[iVar7 * 4] = piVar5[-4];
      piVar5[-4] = iVar6;
      iVar6 = (&DAT_00723300)[iVar7 * 4];
      (&DAT_00723300)[iVar7 * 4] = piVar5[-3];
      piVar5[-3] = iVar6;
      iVar6 = (&DAT_00723304)[iVar7 * 4];
      (&DAT_00723304)[iVar7 * 4] = piVar5[-2];
      piVar5[-2] = iVar6;
    }
    if (iVar3 != local_8) {
      *(int *)(&DAT_0072ca80 + local_8 * 4) = local_c + iVar4 >> 1;
      iVar6 = local_8 + 1;
      local_c = iVar4;
      local_8 = iVar3;
      if (iVar6 < iVar3) {
        piVar2 = (int *)(&DAT_0072ca80 + iVar6 * 4);
        for (iVar3 = iVar3 - iVar6; iVar3 != 0; iVar3 = iVar3 + -1) {
          *piVar2 = iVar4;
          piVar2 = piVar2 + 1;
        }
      }
    }
    piVar5 = piVar5 + 4;
    iVar4 = iVar1;
  } while ((int)piVar5 < 0x72430c);
  *(int *)(&DAT_0072ca80 + local_8 * 4) = local_c + 0xff >> 1;
  local_8 = local_8 + 1;
  if (local_8 < 0x100) {
    puVar8 = (undefined4 *)(&DAT_0072ca80 + local_8 * 4);
    for (iVar4 = 0x100 - local_8; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar8 = 0xff;
      puVar8 = puVar8 + 1;
    }
  }
  return;
}


