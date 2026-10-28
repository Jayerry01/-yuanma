int __thiscall FUN_00566d40(int *param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  
  iVar4 = (int)&DAT_0072685c - (int)param_2;
  do {
    cVar1 = *param_2;
    param_2[iVar4] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  FUN_00593634(&DAT_0072685c);
  iVar4 = 0;
  if (0 < *param_1) {
    piVar5 = (int *)param_1[1];
    do {
      uVar2 = 0xffffffff;
      pcVar6 = &DAT_0072685c;
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      pcVar6 = *(char **)(*piVar5 + 0x120);
      iVar3 = ~uVar2 - 1;
      if (*(int *)(*piVar5 + 0x124) - (int)pcVar6 == iVar3) {
        bVar8 = true;
        pcVar7 = &DAT_0072685c;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar8 = *pcVar6 == *pcVar7;
          pcVar6 = pcVar6 + 1;
          pcVar7 = pcVar7 + 1;
        } while (bVar8);
        if (bVar8) {
          return iVar4;
        }
      }
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar4 < *param_1);
  }
  return -1;
}


