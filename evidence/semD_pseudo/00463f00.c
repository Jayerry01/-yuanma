undefined4 __fastcall FUN_00463f00(int param_1)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  piVar1 = *(int **)(param_1 + 8);
  if (((piVar1[0x75] != 3) && (piVar1[0x75] != 2)) && (piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0x80))(3,1,0x10,0);
    bVar6 = true;
    pcVar4 = *(char **)(*(int *)(param_1 + 4) + 4);
    iVar2 = 0xc;
    pcVar3 = pcVar4;
    pcVar5 = s_Con_Forward_005c7354;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pcVar3 == *pcVar5;
      pcVar3 = pcVar3 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (!bVar6) {
      iVar2 = 9;
      bVar6 = true;
      pcVar3 = pcVar4;
      pcVar5 = s_Con_Back_005c7734;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar3 == *pcVar5;
        pcVar3 = pcVar3 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (!bVar6) {
        iVar2 = 0xd;
        bVar6 = true;
        pcVar3 = s_selectcancel_005c7774;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar6 = *pcVar4 == *pcVar3;
          pcVar4 = pcVar4 + 1;
          pcVar3 = pcVar3 + 1;
        } while (bVar6);
        if (!bVar6) {
          return 1;
        }
      }
    }
    FUN_00505f60(DAT_005e0064,0);
  }
  return 1;
}


