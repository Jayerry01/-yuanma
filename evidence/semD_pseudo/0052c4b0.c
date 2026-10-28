undefined4 * FUN_0052c4b0(undefined4 *param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar1 = (undefined4 *)FUN_00530d80(param_3);
  uVar3 = param_2;
  if (param_3 <= param_2) {
    uVar3 = param_3;
  }
  if (puVar1 != (undefined4 *)0x0) {
    if (param_1 != (undefined4 *)0x0) {
      puVar4 = param_1;
      puVar5 = puVar1;
      for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
      FUN_00530db0(param_1);
      param_3 = param_2;
    }
    if (param_2 < param_3) {
      puVar4 = (undefined4 *)((int)puVar1 + param_2);
      for (uVar3 = param_3 - param_2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      for (uVar3 = param_3 - param_2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar4 = 0;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
    }
  }
  return puVar1;
}


