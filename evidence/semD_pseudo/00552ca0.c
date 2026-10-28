int __thiscall FUN_00552ca0(int *param_1,char *param_2,int param_3,int param_4)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  
  pcVar2 = (char *)param_1[1];
  iVar3 = *param_1;
  if ((uint)(param_3 + param_4) <= (uint)((int)pcVar2 - iVar3)) {
    pcVar5 = (char *)(param_3 + iVar3);
    pcVar7 = param_2 + param_4;
    pcVar6 = pcVar5;
    if ((pcVar5 != pcVar2) && (param_2 != pcVar7)) {
      pcVar1 = param_2 + 1;
      if (pcVar1 == pcVar7) {
        do {
          if (*pcVar6 == *param_2) break;
          pcVar6 = pcVar6 + 1;
        } while (pcVar6 != pcVar2);
      }
      else {
        do {
          while (pcVar4 = pcVar5, pcVar6 = pcVar2, *pcVar5 != *param_2) {
            pcVar5 = pcVar5 + 1;
            if (pcVar5 == pcVar2) goto LAB_00552cfe;
          }
          while( true ) {
            if (pcVar4 == pcVar2) goto LAB_00552cfe;
            if (*pcVar4 == *param_2) break;
            pcVar4 = pcVar4 + 1;
          }
          if ((pcVar4 == pcVar2) || (pcVar5 = pcVar4 + 1, pcVar5 == pcVar2)) break;
          pcVar8 = pcVar5;
          pcVar9 = pcVar1;
          if (*pcVar5 == *pcVar1) {
            do {
              pcVar9 = pcVar9 + 1;
              pcVar6 = pcVar4;
              if ((pcVar9 == pcVar7) || (pcVar8 = pcVar8 + 1, pcVar6 = pcVar2, pcVar8 == pcVar2))
              goto LAB_00552cfe;
            } while (*pcVar8 == *pcVar9);
          }
          pcVar6 = pcVar5;
        } while (pcVar5 != pcVar2);
      }
    }
LAB_00552cfe:
    if (pcVar6 != pcVar2) {
      return (int)pcVar6 - iVar3;
    }
  }
  return -1;
}



// WARNING: Removing unreachable block (ram,0x00552e89)
// WARNING: Removing unreachable block (ram,0x00552e66)
