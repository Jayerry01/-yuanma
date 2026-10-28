void FUN_00419ce0(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  if (0 < param_4) {
    uVar1 = __ftol();
    puVar5 = (undefined4 *)(param_1 + 0x14);
    do {
      uVar2 = __ftol();
      uVar3 = __ftol();
      uVar4 = __ftol();
      *puVar5 = 0;
      puVar5[-1] = ((uVar2 & 0xff | (uVar1 & 0xff) << 8) << 8 | uVar3 & 0xff) << 8 | uVar4 & 0xff;
      puVar5 = puVar5 + param_5;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}


