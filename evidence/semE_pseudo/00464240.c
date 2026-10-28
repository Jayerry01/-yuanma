void __thiscall FUN_00464240(int param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  
  pcVar4 = (char *)(param_1 + 8);
  pcVar4[0] = '\0';
  pcVar4[1] = '\0';
  pcVar4[2] = '\0';
  pcVar4[3] = '\0';
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined2 *)(param_1 + 0x18) = 0;
  iVar3 = (int)pcVar4 - (int)param_2;
  do {
    cVar1 = *param_2;
    param_2[iVar3] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  uVar2 = 0xffffffff;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  *(uint *)(param_1 + 0x1c) = ~uVar2 - 1;
  *(uint *)(param_1 + 0x6c) = ~uVar2 - 1;
  *(undefined4 *)(param_1 + 0x58) = 1;
  return;
}


