undefined4 FUN_0053c1a0(int *param_1)

{
  ushort *puVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  
  iVar5 = *param_1 * param_1[1];
  pcVar4 = (char *)FUN_00530d80(iVar5 * 3);
  puVar1 = (ushort *)param_1[5];
  pcVar2 = pcVar4;
  if (pcVar4 == (char *)0x0) {
    return 0;
  }
  for (; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pcVar2 = (char)*puVar1 << 3;
    pcVar2[1] = (byte)(*puVar1 >> 2) & 0xf8;
    pcVar2[2] = (byte)(*puVar1 >> 7) & 0xf8;
    puVar1 = puVar1 + 1;
    pcVar2 = pcVar2 + 3;
  }
  cVar3 = FUN_0052c880(*param_1,param_1[1],1,3,0x80e0,0x1401,pcVar4);
  if (cVar3 == '\0') {
    FUN_00530db0(pcVar4);
    return 0;
  }
  FUN_00530db0(pcVar4);
  return 1;
}


