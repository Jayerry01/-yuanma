void * FUN_00404510(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  char cVar1;
  void *pvVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  pvVar2 = _malloc(0x770);
  iVar5 = (int)pvVar2 - (int)param_1;
  do {
    cVar1 = *param_1;
    param_1[iVar5] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  *(undefined4 *)((int)pvVar2 + 0x684) = param_2;
  *(undefined4 *)((int)pvVar2 + 0x688) = param_3;
  *(undefined4 *)((int)pvVar2 + 0x68c) = param_4;
  *(undefined4 *)((int)pvVar2 + 0x6b4) = param_4;
  *(undefined4 *)((int)pvVar2 + 0x694) = 1;
  *(undefined4 *)((int)pvVar2 + 0x698) = 1;
  *(undefined4 *)((int)pvVar2 + 0x690) = param_5;
  *(undefined4 *)((int)pvVar2 + 0x69c) = 0;
  *(undefined4 *)((int)pvVar2 + 0x6c8) = 0;
  *(undefined4 *)((int)pvVar2 + 0x6a0) = 1;
  *(undefined4 *)((int)pvVar2 + 0x6a8) = 0;
  *(undefined4 *)((int)pvVar2 + 0x6a4) = 0;
  *(undefined4 *)((int)pvVar2 + 0x6ac) = 0;
  *(undefined4 *)((int)pvVar2 + 0x6b0) = 0;
  *(undefined4 *)((int)pvVar2 + 0x6b8) = param_5;
  *(undefined1 *)((int)pvVar2 + 0x6be) = 0xb4;
  *(undefined1 *)((int)pvVar2 + 0x6bd) = 0xb4;
  *(undefined1 *)((int)pvVar2 + 0x6bc) = 0xb4;
  *(undefined4 *)((int)pvVar2 + 0x6c0) = 0;
  *(undefined4 *)((int)pvVar2 + 0x6c4) = 0x3f800000;
  *(undefined4 *)((int)pvVar2 + 0x718) = 0;
  *(undefined4 *)((int)pvVar2 + 0x71c) = 0;
  pvVar3 = _malloc(0xc);
  *(void **)((int)pvVar2 + 0x720) = pvVar3;
  *(undefined4 *)((int)pvVar3 + 8) = 0;
  *(undefined4 *)(*(int *)((int)pvVar2 + 0x720) + 4) = 0;
  **(undefined4 **)((int)pvVar2 + 0x720) = 0;
  *(undefined4 *)((int)pvVar2 + 0x724) = 0x42480000;
  *(undefined4 *)((int)pvVar2 + 0x728) = 0x43480000;
  *(undefined4 *)((int)pvVar2 + 0x72c) = 0x3f800000;
  *(undefined4 *)((int)pvVar2 + 0x734) = 0;
  *(undefined4 *)((int)pvVar2 + 0x738) = 0;
  *(undefined4 *)((int)pvVar2 + 0x740) = 0;
  *(undefined4 *)((int)pvVar2 + 0x73c) = 0;
  *(undefined4 *)((int)pvVar2 + 0x744) = 0;
  *(undefined4 *)((int)pvVar2 + 0x450) = 0;
  *(undefined4 *)((int)pvVar2 + 0x454) = 0;
  *(undefined4 *)((int)pvVar2 + 0x458) = 0;
  puVar6 = (undefined4 *)((int)pvVar2 + 0x50);
  for (iVar5 = 0x100; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  uVar4 = FUN_00404810();
  *(undefined4 *)((int)pvVar2 + 0x69c) = uVar4;
  return pvVar2;
}


