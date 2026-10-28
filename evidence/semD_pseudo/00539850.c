int FUN_00539850(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int local_c;
  int local_8;
  int local_4;
  
  iVar1 = 0x7fffffff;
  iVar5 = 0;
  local_c = 0x7fffffff;
  local_8 = -1;
  local_4 = -1;
  piVar7 = &DAT_00723300;
  iVar6 = 0;
  do {
    iVar2 = piVar7[-2] - param_1;
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    iVar3 = piVar7[-1] - param_2;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    iVar4 = *piVar7 - param_3;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
    }
    iVar4 = iVar2 + iVar3 + iVar4;
    if (iVar4 < local_c) {
      local_c = iVar4;
      local_8 = iVar5;
    }
    iVar4 = iVar4 - (*(int *)((int)&DAT_0072c680 + iVar6) >> 0xc);
    if (iVar4 < iVar1) {
      iVar1 = iVar4;
      local_4 = iVar5;
    }
    piVar7 = piVar7 + 4;
    iVar2 = *(int *)((int)&DAT_0072c260 + iVar6) >> 10;
    *(int *)((int)&DAT_0072c260 + iVar6) = *(int *)((int)&DAT_0072c260 + iVar6) - iVar2;
    *(int *)((int)&DAT_0072c680 + iVar6) = iVar2 * 0x400 + *(int *)((int)&DAT_0072c680 + iVar6);
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 4;
  } while ((int)piVar7 < 0x724300);
  (&DAT_0072c260)[local_8] = (&DAT_0072c260)[local_8] + 0x40;
  (&DAT_0072c680)[local_8] = (&DAT_0072c680)[local_8] + -0x10000;
  return local_4;
}


