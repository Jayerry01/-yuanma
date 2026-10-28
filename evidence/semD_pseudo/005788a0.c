void __thiscall FUN_005788a0(int param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 *puVar4;
  char local_24 [32];
  undefined4 local_4;
  
  iVar2 = -(int)param_2;
  do {
    cVar1 = *param_2;
    param_2[(int)(local_24 + iVar2)] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  puVar4 = *(undefined4 **)(param_1 + 0xc);
  local_4 = param_3;
  if (puVar4 == *(undefined4 **)(param_1 + 0x10)) {
    FUN_005790d0(puVar4,local_24);
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    return;
  }
  if (puVar4 != (undefined4 *)0x0) {
    pcVar3 = local_24;
    for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      puVar4 = puVar4 + 1;
    }
  }
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 0x24;
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return;
}


