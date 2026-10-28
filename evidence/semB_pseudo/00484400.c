undefined4 * FUN_00484400(uint param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar1 = _malloc(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0xdeadbeef;
  }
  puVar3 = puVar1;
  for (uVar2 = param_1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  for (param_1 = param_1 & 3; param_1 != 0; param_1 = param_1 - 1) {
    *(undefined1 *)puVar3 = 0;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  return puVar1;
}


