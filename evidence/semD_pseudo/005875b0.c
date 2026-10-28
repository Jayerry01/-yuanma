undefined4 __fastcall FUN_005875b0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0056e220();
  *(undefined4 *)(param_1 + 0x1e0) = uVar1;
  uVar1 = FUN_0056e220();
  *(undefined4 *)(param_1 + 0x1dc) = uVar1;
  uVar1 = FUN_0056e0d0(param_1 + 0x2ac);
  *(undefined4 *)(param_1 + 0x290) = uVar1;
  uVar1 = FUN_0056e0d0(param_1 + 700);
  *(undefined4 *)(param_1 + 0x294) = uVar1;
  uVar1 = FUN_0056e0d0(param_1 + 0x2cc);
  *(undefined4 *)(param_1 + 0x298) = uVar1;
  uVar1 = FUN_0056e230(param_1 + 0x2ac,param_1,param_1 + 0x29c);
  *(undefined4 *)(param_1 + 0x2a4) = uVar1;
  uVar1 = FUN_0056e230(param_1 + 700,param_1,param_1 + 0x2a0);
  *(undefined4 *)(param_1 + 0x2a8) = uVar1;
  return 1;
}


