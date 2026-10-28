void FUN_0042cfc0(char *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  
  iVar3 = -1;
  uVar4 = 0;
  pcVar5 = param_1;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (iVar3 != -2) {
    do {
      if (DAT_005ca8ec < 2) {
        uVar2 = (byte)PTR_DAT_005ca6e0[param_1[uVar4] * 2] & 1;
      }
      else {
        uVar2 = FUN_0050a85c((int)param_1[uVar4],1);
      }
      if (uVar2 != 0) {
        cVar1 = FUN_0050a722((int)param_1[uVar4]);
        param_1[uVar4] = cVar1;
      }
      uVar2 = 0xffffffff;
      uVar4 = uVar4 + 1;
      pcVar5 = param_1;
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
    } while (uVar4 < ~uVar2 - 1);
  }
  return;
}


