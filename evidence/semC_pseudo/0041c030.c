uint * FUN_0041c030(int param_1)

{
  uint *puVar1;
  byte bVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int unaff_EBX;
  int unaff_EDI;
  uint *puVar7;
  
  puVar3 = _malloc(0x60);
  puVar1 = puVar3 + 0x16;
  (**(code **)(**(int **)(param_1 + 0x75c) + 0x14))(*(int **)(param_1 + 0x75c),puVar1,0);
  puVar7 = puVar3 + 2;
  for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  puVar3[2] = 0x50;
  puVar3[0x15] = 0x20;
  puVar3[0x13] = *(uint *)(unaff_EBX + 0x14);
  puVar3[7] = **(uint **)(unaff_EBX + 4);
  puVar3[8] = *(uint *)(*(int *)(unaff_EBX + 4) + 4);
  puVar3[9] = *(uint *)(*(int *)(unaff_EBX + 4) + 8);
  puVar3[10] = 0x437f0000;
  puVar3[3] = **(uint **)(unaff_EBX + 8);
  puVar3[4] = *(uint *)(*(int *)(unaff_EBX + 8) + 4);
  uVar4 = *(uint *)(*(int *)(unaff_EBX + 8) + 8);
  puVar3[6] = 0x437f0000;
  puVar3[5] = uVar4;
  puVar3[0xb] = **(uint **)(unaff_EBX + 0xc);
  puVar3[0xc] = *(uint *)(*(int *)(unaff_EBX + 0xc) + 4);
  uVar4 = *(uint *)(*(int *)(unaff_EBX + 0xc) + 8);
  puVar3[0xe] = 0x437f0000;
  puVar3[0xd] = uVar4;
  puVar3[0xf] = **(uint **)(unaff_EBX + 0x10);
  puVar3[0x10] = *(uint *)(*(int *)(unaff_EBX + 0x10) + 4);
  uVar4 = *(uint *)(*(int *)(unaff_EBX + 0x10) + 8);
  puVar3[0x12] = 0x437f0000;
  puVar3[0x11] = uVar4;
  bVar2 = __ftol();
  uVar4 = __ftol();
  uVar5 = __ftol();
  *puVar3 = ((bVar2 | 0xffffff00) << 8 | uVar4 & 0xff) << 8 | uVar5 & 0xff;
  puVar3[1] = 0xff;
  (**(code **)(*(int *)*puVar1 + 0xc))((int *)*puVar1,puVar3 + 2);
  (**(code **)(*(int *)*puVar1 + 0x14))
            ((int *)*puVar1,*(undefined4 *)(unaff_EDI + 0x760),puVar3 + 0x17);
  return puVar3;
}


