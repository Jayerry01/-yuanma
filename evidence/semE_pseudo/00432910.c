void * FUN_00432910(char *param_1)

{
  char cVar1;
  void *pvVar2;
  char *pcVar3;
  void *pvVar4;
  uint uVar5;
  
  pvVar2 = _malloc(0x10);
  pvVar4 = (void *)0x0;
  if (pvVar2 != (void *)0x0) {
    uVar5 = 0xffffffff;
    pcVar3 = param_1;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    pcVar3 = _malloc(~uVar5);
    *(char **)((int)pvVar2 + 4) = pcVar3;
    if (pcVar3 != (char *)0x0) {
      do {
        cVar1 = *param_1;
        param_1 = param_1 + 1;
        *pcVar3 = cVar1;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
    }
    *(undefined4 *)((int)pvVar2 + 8) = 0;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0;
    pvVar4 = pvVar2;
  }
  return pvVar4;
}


