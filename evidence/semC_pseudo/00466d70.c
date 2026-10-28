undefined4 __thiscall FUN_00466d70(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  char *pcVar10;
  char *in_stack_00000018;
  int in_stack_0000001c;
  char local_20 [32];
  
  *(undefined4 *)(param_1 + 0x1c) = 0;
  puVar9 = (undefined4 *)(param_1 + 8);
  puVar8 = (undefined4 *)register0x00000010;
  for (iVar4 = 5; puVar8 = puVar8 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar9 = *puVar8;
    puVar9 = puVar9 + 1;
  }
  *(int *)(param_1 + 0x44) = in_stack_0000001c;
  if (in_stack_0000001c == 0) {
    if (in_stack_00000018 != (char *)0x0) {
      pcVar10 = local_20;
      for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
        pcVar10[0] = '\0';
        pcVar10[1] = '\0';
        pcVar10[2] = '\0';
        pcVar10[3] = '\0';
        pcVar10 = pcVar10 + 4;
      }
      pcVar10[0] = '\0';
      pcVar10[1] = '\0';
      FUN_0042a8f0(local_20);
      uVar5 = 0xffffffff;
      pcVar10 = local_20;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      iVar4 = -1;
      uVar7 = 0;
      pcVar10 = in_stack_00000018;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      if (iVar4 != -2) {
        do {
          local_20[uVar7 + ~uVar5 + -1] = in_stack_00000018[uVar7];
          uVar6 = 0xffffffff;
          uVar7 = uVar7 + 1;
          pcVar10 = in_stack_00000018;
          do {
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            cVar1 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar1 != '\0');
        } while (uVar7 < ~uVar6 - 1);
      }
      iVar4 = FUN_004351a0(local_20);
      if (iVar4 == 0) {
        FUN_00429990(0);
        uVar2 = __ftol();
        uVar2 = __ftol(uVar2);
        FUN_00429b80(1,1,1,uVar2);
        uVar2 = FUN_00429c30(0);
        *(undefined4 *)(param_1 + 0x1c) = uVar2;
        uVar3 = __ftol(0,0,0xff);
        uVar3 = __ftol(uVar3);
        FUN_00435120(uVar2,uVar3);
      }
      else {
        FUN_00429990(0);
        uVar2 = __ftol();
        uVar2 = __ftol(uVar2);
        FUN_00429aa0(in_stack_00000018,0,uVar2);
        uVar2 = FUN_00429c30(0);
        *(undefined4 *)(param_1 + 0x1c) = uVar2;
      }
      uVar2 = __ftol();
      uVar2 = __ftol(uVar2);
      FUN_00429d00(*(undefined4 *)(param_1 + 0x1c),uVar2);
      FUN_00429d80(*(undefined4 *)(param_1 + 0x1c),0,0,0xff,1);
    }
    FUN_00429990(0);
    uVar2 = __ftol();
    uVar2 = __ftol(uVar2);
    FUN_00429b80(1,1,1,uVar2);
    uVar2 = FUN_00429c30(0);
    *(undefined4 *)(param_1 + 0x20) = uVar2;
    FUN_00429d80(uVar2,0,0,0,1);
    FUN_00429de0(*(undefined4 *)(param_1 + 0x20),0);
  }
  return 1;
}


