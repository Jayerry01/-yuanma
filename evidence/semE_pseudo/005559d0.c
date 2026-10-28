char * __fastcall FUN_005559d0(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  
  iVar2 = *param_1;
  iVar3 = param_1[3];
  uVar5 = 0xffffffff;
  pcVar6 = (char *)(iVar3 + iVar2);
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  iVar4 = param_1[3];
  param_1[3] = iVar4 + ~uVar5;
  if (param_1[1] - iVar2 < (int)(iVar4 + ~uVar5)) {
    iVar4 = (param_1[1] - iVar2) + -1;
    param_1[3] = iVar4;
    *(undefined1 *)(iVar4 + iVar2) = 0;
  }
  return (char *)(iVar3 + iVar2);
}


