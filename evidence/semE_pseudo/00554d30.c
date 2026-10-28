void __fastcall FUN_00554d30(int param_1)

{
  ushort uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  uVar1 = *(ushort *)(param_1 + 0x10);
  puVar4 = *(undefined4 **)(param_1 + 0x14);
  puVar2 = (undefined4 *)FUN_00553880();
  for (uVar3 = (uint)(uVar1 >> 2); uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar2 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar2 = puVar2 + 1;
  }
  for (uVar3 = uVar1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar2 = *(undefined1 *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  return;
}


