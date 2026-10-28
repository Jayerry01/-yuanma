void FUN_00505430(uint param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int local_4;
  
  if (-1 < (int)param_1) {
    if (param_1 < (uint)((DAT_0066758c - DAT_00667588) / 0x14)) {
      piVar1 = (int *)(DAT_00667588 + param_1 * 0x14);
      if ((piVar1[3] != 0) && (iVar2 = piVar1[4], piVar1[4] = iVar2 + -1, iVar2 + -1 < 1)) {
        FUN_00528030(1,piVar1 + 3);
        piVar1[3] = 0;
        iVar2 = *piVar1;
        param_1 = piVar1[1] - iVar2;
        piVar1[4] = 0;
        local_4 = -1;
        piVar3 = (int *)&param_1;
        if (param_1 == -1) {
          piVar3 = &local_4;
        }
        iVar4 = *piVar3 + iVar2;
        if (iVar2 != iVar4) {
          FUN_005092c0(iVar2,iVar4,(piVar1[1] - iVar4) + 1);
          piVar1[1] = piVar1[1] + (iVar2 - iVar4);
        }
      }
    }
  }
  return;
}


