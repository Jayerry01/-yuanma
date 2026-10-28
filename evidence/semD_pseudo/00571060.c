int __thiscall FUN_00571060(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  int local_8;
  
  local_8 = 0;
  if (0 < *(int *)(param_1 + 0x30)) {
    piVar5 = *(int **)(param_1 + 0x34);
    do {
      iVar2 = *piVar5;
      uVar3 = 0xffffffff;
      pcVar6 = param_2;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      iVar4 = ~uVar3 - 1;
      if (*(int *)(iVar2 + 0x1c) - (int)*(char **)(iVar2 + 0x18) == iVar4) {
        bVar8 = true;
        pcVar6 = *(char **)(iVar2 + 0x18);
        pcVar7 = param_2;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar8 = *pcVar6 == *pcVar7;
          pcVar6 = pcVar6 + 1;
          pcVar7 = pcVar7 + 1;
        } while (bVar8);
        if (bVar8) {
          return iVar2;
        }
      }
      local_8 = local_8 + 1;
      piVar5 = piVar5 + 1;
    } while (local_8 < *(int *)(param_1 + 0x30));
  }
  return 0;
}


