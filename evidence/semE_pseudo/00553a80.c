undefined4 __thiscall FUN_00553a80(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = FUN_00553a10(param_1 + 0xe,*(undefined2 *)(param_1 + 0xc),param_2);
  uVar2 = CONCAT31((int3)((uint)uVar1 >> 8),*(undefined1 *)(param_1 + 5)) & 0xffffffef;
  *(char *)(param_1 + 5) = (char)uVar2;
  return CONCAT31((int3)(uVar2 >> 8),1);
}


