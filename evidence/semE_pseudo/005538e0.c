void __thiscall FUN_005538e0(int param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if ((int)(*(ushort *)(param_1 + 0xc) + param_3) < 0x579) {
    puVar2 = (undefined4 *)(*(ushort *)(param_1 + 0xc) + 0xe + param_1);
    for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar2 = *param_2;
      param_2 = param_2 + 1;
      puVar2 = puVar2 + 1;
    }
    for (uVar1 = param_3 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined1 *)puVar2 = *(undefined1 *)param_2;
      param_2 = (undefined4 *)((int)param_2 + 1);
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
    *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + (short)param_3;
  }
  return;
}


