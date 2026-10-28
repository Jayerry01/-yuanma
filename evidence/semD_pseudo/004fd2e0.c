void __fastcall FUN_004fd2e0(int param_1)

{
  uint uVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  ushort *puVar5;
  
  if ((*(int *)(param_1 + 0xa8) - *(int *)(param_1 + 0xa4) >> 2 != 0) &&
     (-1 < *(int *)(param_1 + 0xc4))) {
    uVar1 = *(uint *)(*(int *)(param_1 + 0xa8) + -4);
    *(int *)(param_1 + 0xa8) = *(int *)(param_1 + 0xa8) + -4;
    iVar3 = FUN_004c2bf0(*(undefined4 *)(param_1 + 0xc4));
    puVar2 = *(ushort **)(iVar3 + 0x18);
    uVar4 = 0;
    puVar5 = puVar2;
    if (*(int *)(iVar3 + 0x1c) - (int)puVar2 >> 3 != 0) {
      while (*puVar5 != uVar1) {
        uVar4 = uVar4 + 1;
        puVar5 = puVar5 + 4;
        if ((uint)(*(int *)(iVar3 + 0x1c) - *(int *)(iVar3 + 0x18) >> 3) <= uVar4) {
          FUN_004fc4b0(uVar1);
          return;
        }
      }
      *(uint *)(param_1 + 0xb8) = (uint)(byte)puVar2[uVar4 * 4 + 1];
    }
    FUN_004fc4b0(uVar1);
    return;
  }
  *(undefined4 *)(param_1 + 0xb8) = 0;
  if (*(int *)(param_1 + 0xc4) < 0) {
    FUN_004fd580();
    return;
  }
  FUN_004fc4b0(0xfffffffe);
  return;
}


