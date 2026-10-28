void FUN_004155c0(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (DAT_005c4308 != 0) {
    uVar1 = __ftol();
    uVar2 = __ftol();
    uVar3 = __ftol();
    *(uint *)(param_1 + 0x2c) = (uint)CONCAT11(uVar1,uVar2) << 8 | uVar3 & 0xff;
    return;
  }
  uVar4 = __ftol();
  uVar4 = __ftol(uVar4);
  uVar4 = __ftol(uVar4);
  uVar4 = FUN_0041f6b0(uVar4);
  *(undefined4 *)(param_1 + 0x2c) = uVar4;
  return;
}


