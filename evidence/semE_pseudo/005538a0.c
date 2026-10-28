char * __fastcall FUN_005538a0(int *param_1)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  
  uVar5 = 0xffffffff;
  pcVar1 = (char *)(*param_1 + 0xe + (int)param_1);
  pcVar6 = pcVar1;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  iVar3 = *param_1;
  *param_1 = iVar3 + ~uVar5;
  uVar4 = (uint)*(ushort *)(param_1 + 3);
  if ((int)uVar4 < (int)(iVar3 + ~uVar5)) {
    *param_1 = uVar4 - 1;
    *(undefined1 *)(uVar4 + 0xd + (int)param_1) = 0;
  }
  return pcVar1;
}


