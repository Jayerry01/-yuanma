void FUN_00429aa0(char *param_1,int param_2,int param_3,int param_4)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (((DAT_005d5b04 != (int *)0x0) && (param_1 != (char *)0x0)) && (-1 < param_2)) {
    if (DAT_005d5b04[1] != 0) {
      FUN_005089fd(DAT_005d5b04);
      DAT_005d5b04[1] = 0;
    }
    uVar4 = 0xffffffff;
    pcVar6 = param_1;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    pvVar2 = _malloc(~uVar4);
    DAT_005d5b04[1] = (int)pvVar2;
    pcVar6 = (char *)DAT_005d5b04[1];
    pcVar5 = param_1;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      *pcVar6 = cVar1;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    DAT_005d5b04[4] = param_3;
    DAT_005d5b04[5] = param_4;
    if (*DAT_005d5b04 != 0) {
      FUN_00434ac0(*DAT_005d5b04);
    }
    FUN_00434600();
    FUN_00434690(0,param_1,param_2,1,1,param_3,param_4,DAT_005d5b04[0x12]);
    iVar3 = FUN_00434ab0();
    *DAT_005d5b04 = iVar3;
  }
  return;
}


