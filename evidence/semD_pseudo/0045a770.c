undefined4 __fastcall FUN_0045a770(int param_1)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined2 local_36;
  undefined4 local_34 [13];
  
  iVar3 = FUN_00509f8f(s_server_cfg_005c794c,&DAT_005c67d0);
  uVar4 = 0;
  if (iVar3 != 0) {
    puVar8 = local_34;
    for (iVar7 = 0xc; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    *(undefined2 *)puVar8 = 0;
    bVar2 = *(byte *)(iVar3 + 0xc);
    local_36 = _DAT_005c462c;
    while ((bVar2 & 0x10) == 0) {
      FUN_0050ab32(local_34,0x32,iVar3);
      iVar7 = FUN_0050a22f(local_34,&local_36);
      iVar5 = FUN_0050a22f(0,&local_36);
      if ((iVar7 != 0) && (iVar5 != 0)) {
        FUN_0045b0a0(iVar7,iVar5);
      }
      bVar2 = *(byte *)(iVar3 + 0xc);
    }
    FUN_00509e57(iVar3);
    pcVar6 = (char *)(param_1 + 0x98);
    iVar3 = -1;
    pcVar9 = pcVar6;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    if (iVar3 != -2) {
      iVar3 = (param_1 + 0x40) - (int)pcVar6;
      do {
        cVar1 = *pcVar6;
        pcVar6[iVar3] = cVar1;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
    }
    uVar4 = 1;
  }
  return uVar4;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
