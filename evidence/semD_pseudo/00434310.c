void FUN_00434310(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  FUN_00433ad0();
  *DAT_005d9b74 = 0xffffffff;
  uVar1 = FUN_00432bf0(param_1,param_2);
  DAT_005d9b74[0xd] = uVar1;
  DAT_005d9b74[2] = param_1;
  DAT_005d9b74[3] = param_2;
  FUN_00433da0(0,0,0,0);
  FUN_00433c80(DAT_005d9b74,0);
  FUN_00433d10(DAT_005d9b74,0);
  FUN_00433e90();
  return;
}


