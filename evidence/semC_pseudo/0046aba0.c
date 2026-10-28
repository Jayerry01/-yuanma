undefined4 __thiscall FUN_0046aba0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  char *pcVar8;
  undefined4 *puVar9;
  char *pcVar10;
  char *pcVar11;
  char *in_stack_0000002c;
  undefined4 in_stack_00000030;
  char local_20 [32];
  
  pcVar8 = in_stack_0000002c;
  puVar9 = (undefined4 *)(param_1 + 0x14);
  puVar7 = (undefined4 *)register0x00000010;
  for (iVar4 = 5; puVar7 = puVar7 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar9 = *puVar7;
    puVar9 = puVar9 + 1;
  }
  puVar7 = (undefined4 *)&stack0x00000018;
  puVar9 = (undefined4 *)(param_1 + 0x28);
  for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar9 = puVar9 + 1;
  }
  if (in_stack_0000002c != (char *)0x0) {
    pcVar11 = local_20;
    for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
      pcVar11[0] = '\0';
      pcVar11[1] = '\0';
      pcVar11[2] = '\0';
      pcVar11[3] = '\0';
      pcVar11 = pcVar11 + 4;
    }
    pcVar11[0] = '\0';
    pcVar11[1] = '\0';
    FUN_0042a8f0(local_20);
    uVar5 = 0xffffffff;
    do {
      pcVar11 = pcVar8;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar11 = pcVar8 + 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar11;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    iVar4 = -1;
    pcVar8 = local_20;
    do {
      pcVar10 = pcVar8;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar10 = pcVar8 + 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar10;
    } while (cVar1 != '\0');
    pcVar8 = pcVar11 + -uVar5;
    pcVar11 = pcVar10 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar11 = pcVar11 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar11 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar11 = pcVar11 + 1;
    }
    iVar4 = FUN_004351a0(local_20);
    if (iVar4 != 0) {
      FUN_00429990(0);
      uVar2 = __ftol();
      uVar2 = __ftol(uVar2);
      FUN_00429aa0(local_20,0,uVar2);
      uVar2 = FUN_00429c30(0);
      *(undefined4 *)(param_1 + 0x10) = uVar2;
      goto LAB_0046acb4;
    }
  }
  FUN_00429990(0);
  uVar2 = __ftol();
  uVar2 = __ftol(uVar2);
  FUN_00429b80(1,1,1,uVar2);
  uVar2 = FUN_00429c30(0);
  *(undefined4 *)(param_1 + 0x10) = uVar2;
  uVar3 = __ftol(0,0,0xff);
  uVar3 = __ftol(uVar3);
  FUN_00435120(uVar2,uVar3);
LAB_0046acb4:
  uVar2 = __ftol();
  uVar2 = __ftol(uVar2);
  FUN_00429d00(*(undefined4 *)(param_1 + 0x10),uVar2);
  FUN_00429d80(*(undefined4 *)(param_1 + 0x10),0,0,0,1);
  FUN_00429990(0);
  uVar2 = __ftol();
  uVar2 = __ftol(uVar2);
  FUN_00429aa0(in_stack_00000030,0,uVar2);
  uVar2 = FUN_00429c30(0);
  *(undefined4 *)(param_1 + 0xc) = uVar2;
  uVar3 = __ftol();
  uVar3 = __ftol(uVar3);
  FUN_00429d00(uVar2,uVar3);
  FUN_00429d80(*(undefined4 *)(param_1 + 0xc),0,0,0xff,1);
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x54) = 1;
  return 1;
}


