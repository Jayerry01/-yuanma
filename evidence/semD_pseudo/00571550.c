int __thiscall FUN_00571550(int *param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  int local_8;
  
  local_8 = 0;
  if (0 < *param_1) {
    piVar4 = (int *)param_1[6];
    do {
      uVar2 = 0xffffffff;
      pcVar5 = param_2;
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      pcVar5 = *(char **)(*piVar4 + 0x18);
      iVar3 = ~uVar2 - 1;
      if (*(int *)(*piVar4 + 0x1c) - (int)pcVar5 == iVar3) {
        bVar7 = true;
        pcVar6 = param_2;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar7 = *pcVar5 == *pcVar6;
          pcVar5 = pcVar5 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar7);
        if (bVar7) {
          return local_8;
        }
      }
      local_8 = local_8 + 1;
      piVar4 = piVar4 + 1;
    } while (local_8 < *param_1);
  }
  return -1;
}


