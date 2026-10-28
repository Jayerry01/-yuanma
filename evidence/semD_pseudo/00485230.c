void FUN_00485230(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  char *pcVar7;
  ushort *puVar8;
  
  iVar2 = FUN_00485300();
  if (iVar2 != 0xffff) {
    iVar2 = iVar2 + 1;
    cVar6 = '\0';
    pcVar7 = param_1;
    while (iVar2 != 0) {
      iVar2 = iVar2 + -1;
      uVar3 = FUN_00485300();
      if (uVar3 == 0xffff) {
        return;
      }
      for (iVar4 = (uVar3 >> 4) + 1; iVar4 != 0; iVar4 = iVar4 + -1) {
        *pcVar7 = ((byte)uVar3 & 0xf) + 1;
        pcVar7[1] = cVar6;
        cVar6 = cVar6 + '\x01';
        pcVar7 = pcVar7 + 4;
      }
    }
    FUN_0050af1e(param_1,param_2,4,&LAB_00485330);
    iVar2 = 0;
    cVar6 = '\0';
    iVar4 = 0;
    for (pcVar7 = param_1 + param_2 * 4 + -4; param_1 <= pcVar7; pcVar7 = pcVar7 + -4) {
      iVar4 = iVar4 + iVar2;
      cVar1 = *pcVar7;
      *(short *)(pcVar7 + 2) = (short)iVar4;
      if (cVar1 != cVar6) {
        iVar2 = 1 << (0x10U - cVar1 & 0x1f);
        cVar6 = cVar1;
      }
    }
    if (param_2 != 0) {
      puVar8 = (ushort *)(param_1 + 2);
      do {
        uVar5 = 0;
        uVar3 = (uint)*puVar8;
        iVar2 = 0x10;
        do {
          uVar5 = uVar5 * 2 | uVar3 & 1;
          uVar3 = uVar3 >> 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
        *puVar8 = (ushort)uVar5;
        puVar8 = puVar8 + 2;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
  }
  return;
}


