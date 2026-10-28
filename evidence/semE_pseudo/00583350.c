undefined4 __thiscall FUN_00583350(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (*(int *)(param_2 + 4) != *(int *)(param_1 + 4)) {
    return 0;
  }
  FUN_005833a0(param_1);
  uVar1 = *(int *)(param_1 + 0xc) - 0x268;
  puVar3 = (undefined4 *)(param_1 + 0x268);
  puVar4 = (undefined4 *)(param_2 + 0x268);
  for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  for (uVar1 = uVar1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)puVar4 = *(undefined1 *)puVar3;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  return 1;
}


