void FUN_0058f0f0(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = *(undefined4 *)(param_3 + 0x24);
  uVar2 = *(undefined4 *)(param_3 + 0x28);
  uVar3 = *(undefined4 *)(param_3 + 0x2c);
  FUN_0047ec40();
  *param_1 = uVar1;
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  return;
}


