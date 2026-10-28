void FUN_00415330(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  uint uVar4;
  
  if ((DAT_005d5a0c != 0) && (iVar1 = *(int *)(DAT_005d5a0c + 0x760), iVar1 != 0)) {
    uVar2 = __ftol();
    uVar3 = __ftol();
    uVar4 = __ftol();
    FUN_0041a950(iVar1,2,(uint)CONCAT11(uVar2,uVar3) << 8 | uVar4 & 0xff);
    _DAT_007e2c94 = param_1;
    _DAT_007e32a8 = param_2;
    _DAT_007e2c9c = param_3;
  }
  return;
}


