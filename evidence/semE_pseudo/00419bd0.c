uint FUN_00419bd0(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = __ftol();
  uVar2 = __ftol();
  uVar3 = __ftol();
  uVar4 = __ftol();
  return uVar4 & 0xff | ((uint)CONCAT11(uVar1,uVar2) << 8 | uVar3 & 0xff) << 8;
}


