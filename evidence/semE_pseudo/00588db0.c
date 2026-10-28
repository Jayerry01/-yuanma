undefined4 __fastcall FUN_00588db0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0056e0d0(param_1 + 0x274);
  *(undefined4 *)(param_1 + 0x29c) = uVar1;
  uVar1 = FUN_0056e0d0(param_1 + 0x284);
  *(undefined4 *)(param_1 + 0x2a0) = uVar1;
  uVar1 = FUN_0056e230(param_1 + 0x274,param_1,0);
  *(undefined4 *)(param_1 + 0x294) = uVar1;
  uVar1 = FUN_0056e230(param_1 + 0x284,param_1,0);
  *(undefined4 *)(param_1 + 0x298) = uVar1;
  return 1;
}


