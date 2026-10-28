int __fastcall FUN_00469ac0(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  
  for (puVar1 = (undefined4 *)**(undefined4 **)(param_1 + 0x2c);
      puVar1 != *(undefined4 **)(param_1 + 0x2c); puVar1 = (undefined4 *)*puVar1) {
  }
  FUN_0046a150(0,param_1 + 0x28);
  for (puVar1 = (undefined4 *)**(undefined4 **)(param_1 + 0x2c);
      puVar1 != *(undefined4 **)(param_1 + 0x2c); puVar1 = (undefined4 *)*puVar1) {
  }
  uVar2 = __ftol();
  uVar3 = __ftol();
  return ((uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f)) -
         ((uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f));
}


