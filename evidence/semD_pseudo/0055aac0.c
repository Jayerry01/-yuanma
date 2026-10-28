FUN_0055aac0(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  char local_18 [8];
  char local_10 [16];
  
  if (param_3 < 1) {
    iVar3 = 0;
    do {
      cVar1 = (&DAT_005c9b80)[iVar3];
      local_18[iVar3] = cVar1;
      iVar3 = iVar3 + 1;
    } while (cVar1 != '\0');
  }
  else {
    FUN_00508ae6(local_18,s___0_dd_005d1420,param_3);
  }
  FUN_00508ae6(local_10,local_18,param_2);
  uVar2 = 0xffffffff;
  pcVar4 = local_10;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  iVar3 = 0;
  if (0 < (int)(~uVar2 - 1)) {
    do {
      FUN_004745d0(param_5);
      FUN_00479f80(*(undefined4 *)(param_1 + 0xc04 + local_10[iVar3] * 4));
      FUN_0047c2e0(0);
      FUN_00478150(param_6);
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)(~uVar2 - 1));
  }
  return;
}


