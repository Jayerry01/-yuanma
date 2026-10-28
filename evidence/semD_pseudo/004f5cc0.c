void __fastcall FUN_004f5cc0(int param_1)

{
  undefined4 uVar1;
  
  FUN_004059e0(5);
  uVar1 = FUN_00405df0(0);
  *(undefined4 *)(param_1 + 0x78) = uVar1;
  FUN_004059e0(5);
  uVar1 = FUN_00405df0(0);
  *(undefined4 *)(param_1 + 0x7c) = uVar1;
  FUN_0040b100(uVar1,*(undefined4 *)(param_1 + 0x78));
  FUN_004059e0(5);
  uVar1 = FUN_00405df0(0);
  *(undefined4 *)(param_1 + 0x8c) = uVar1;
  FUN_0040b100(uVar1,*(undefined4 *)(param_1 + 0x7c));
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0x420c0000;
  *(undefined4 *)(param_1 + 0x94) = 0x42f00000;
  *(undefined4 *)(param_1 + 0x98) = 1;
  return;
}


