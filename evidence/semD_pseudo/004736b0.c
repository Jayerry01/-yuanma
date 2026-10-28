void __thiscall FUN_004736b0(u_long *param_1,char *param_2)

{
  ulong netlong;
  u_long uVar1;
  hostent *phVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  netlong = inet_addr(param_2);
  if (netlong != 0xffffffff) {
    uVar1 = ntohl(netlong);
    *param_1 = uVar1;
    return;
  }
  iVar3 = 0x10;
  bVar6 = true;
  pcVar4 = param_2;
  pcVar5 = &DAT_005c7c50;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    uVar1 = ntohl(0xffffffff);
    *param_1 = uVar1;
    return;
  }
  phVar2 = gethostbyname(param_2);
  if (phVar2 != (hostent *)0x0) {
    uVar1 = ntohl(*(u_long *)*phVar2->h_addr_list);
    *param_1 = uVar1;
    return;
  }
  *param_1 = 0xffffffff;
  return;
}


