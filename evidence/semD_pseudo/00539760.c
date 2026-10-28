uint FUN_00539760(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint local_4;
  
  local_4 = 0xffffffff;
  iVar3 = *(int *)(&DAT_0072ca80 + param_2 * 4) + -1;
  iVar4 = *(int *)(&DAT_0072ca80 + param_2 * 4);
  iVar5 = 1000;
LAB_00539780:
  iVar2 = iVar3;
  if (iVar4 < 0x100) goto LAB_00539796;
  iVar6 = iVar4;
  if (iVar2 < 0) {
    return local_4 & 0xff;
  }
  goto LAB_005397ee;
LAB_00539796:
  iVar3 = (&DAT_007232fc)[iVar4 * 4] - param_2;
  if (iVar3 < iVar5) {
    iVar6 = iVar4 + 1;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    iVar1 = (&DAT_007232f8)[iVar4 * 4] - param_1;
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    if (iVar3 + iVar1 < iVar5) {
      iVar7 = (&DAT_00723300)[iVar4 * 4] - param_3;
      if (iVar7 < 0) {
        iVar7 = -iVar7;
      }
      iVar7 = iVar3 + iVar1 + iVar7;
      if (iVar7 < iVar5) {
        local_4 = (&DAT_00723304)[iVar4 * 4];
        iVar5 = iVar7;
      }
    }
  }
  else {
    iVar6 = 0x100;
  }
  iVar3 = iVar2;
  iVar4 = iVar6;
  if (-1 < iVar2) {
LAB_005397ee:
    iVar1 = param_2 - (&DAT_007232fc)[iVar2 * 4];
    iVar4 = iVar6;
    if (iVar1 < iVar5) {
      iVar3 = iVar2 + -1;
      if (iVar1 < 0) {
        iVar1 = -iVar1;
      }
      iVar6 = (&DAT_007232f8)[iVar2 * 4] - param_1;
      if (iVar6 < 0) {
        iVar6 = -iVar6;
      }
      if (iVar1 + iVar6 < iVar5) {
        iVar7 = (&DAT_00723300)[iVar2 * 4] - param_3;
        if (iVar7 < 0) {
          iVar7 = -iVar7;
        }
        iVar7 = iVar1 + iVar6 + iVar7;
        if (iVar7 < iVar5) {
          local_4 = (&DAT_00723304)[iVar2 * 4];
          iVar5 = iVar7;
        }
      }
    }
    else {
      iVar3 = -1;
    }
  }
  goto LAB_00539780;
}


