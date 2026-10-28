undefined4 FUN_004022b0(char *param_1,int param_2,int param_3,char *param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  
  if ((((param_1 != (char *)0x0) && (param_2 != 0)) && (param_4 != (char *)0x0)) && (0 < param_3)) {
    uVar2 = 0xffffffff;
    pcVar5 = param_4;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    if (0 < (int)(~uVar2 - 1)) {
      iVar6 = 0;
      if (0 < param_3) {
        iVar3 = param_2 - (int)param_1;
        iVar4 = param_3;
        pcVar5 = param_1;
        param_2 = ~uVar2 - 1;
        do {
          param_1 = (char *)CONCAT31(param_1._1_3_,param_4[iVar6]);
          cVar1 = FUN_0050915b(&param_1);
          *pcVar5 = pcVar5[iVar3] - cVar1;
          iVar6 = (iVar6 + 1) % param_2;
          pcVar5 = pcVar5 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      return 1;
    }
  }
  return 0;
}


