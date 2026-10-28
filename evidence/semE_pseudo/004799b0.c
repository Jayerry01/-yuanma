int FUN_004799b0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  
  iVar4 = 4;
  pcVar3 = &DAT_005c8010;
  do {
    iVar2 = -1;
    pcVar5 = pcVar3;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    if ((iVar2 != -2) && (iVar2 = FUN_00479a00(param_1,param_2,iVar4), iVar2 != 0)) {
      return iVar2;
    }
    pcVar3 = pcVar3 + -0x80;
    iVar4 = iVar4 + -1;
    if ((int)pcVar3 < 0x5c7e10) {
      return 0;
    }
  } while( true );
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
