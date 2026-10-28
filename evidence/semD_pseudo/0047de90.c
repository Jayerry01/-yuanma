void __fastcall FUN_0047de90(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 auStack_4c [11];
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0x47dea1;
  FUN_0047c1c0();
  puVar1 = (undefined4 *)(param_1 + 0xb0);
  puVar2 = auStack_4c;
  for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  FUN_0047c100();
  uStack_14 = *(undefined4 *)(param_1 + 0xec);
  uStack_18 = 0x47dec8;
  FUN_0047c0d0();
  uStack_14 = *(undefined4 *)(param_1 + 0xc);
  uStack_18 = *(undefined4 *)(param_1 + 8);
  uStack_1c = *(undefined4 *)(param_1 + 4);
  uStack_20 = 0x47dedb;
  FUN_0047c1e0();
  uStack_14 = 0x47dee5;
  puVar1 = (undefined4 *)FUN_00481b30();
  uStack_14 = 0x47def3;
  puVar2 = (undefined4 *)FUN_00481b30();
  *puVar2 = *puVar1;
  uStack_14 = 0x47df02;
  FUN_00481b90();
  uStack_14 = 0x47df09;
  FUN_00481b90();
  uStack_14 = 0x47df15;
  puVar1 = (undefined4 *)FUN_00481b30();
  uStack_14 = 0x47df21;
  puVar2 = (undefined4 *)FUN_00481b30();
  uVar5 = *(uint *)(param_1 + 0xc);
  for (uVar4 = (uVar5 & 0x7fffffff) >> 1; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  for (uVar5 = uVar5 * 2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined1 *)puVar2 = *(undefined1 *)puVar1;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  uStack_14 = 0x47df3f;
  FUN_00481b90();
  uStack_14 = 0x47df46;
  FUN_00481b90();
  return;
}


