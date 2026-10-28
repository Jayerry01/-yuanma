void __fastcall FUN_004820c0(int param_1)

{
  DAT_005e0410 = (uint)(0xfffe0100 < *(uint *)(param_1 + 0x36d1c));
  DAT_005e03f8 = (uint)(0xffff0100 < *(uint *)(param_1 + 0x36d24));
  DAT_005e03f4 = *(undefined4 *)(param_1 + 0x36cf0);
  DAT_005e03e4 = *(undefined4 *)(param_1 + 0x36cb0);
  DAT_005e03e8 = *(undefined4 *)(param_1 + 0x36cb4);
  DAT_005e03ec = *(uint *)(param_1 + 0x36c94) >> 5 & 1;
  _DAT_005e03fc = (uint)((*(uint *)(param_1 + 0x36ce8) & 0x16) != 0);
  DAT_005e0400 = *(uint *)(param_1 + 0x36ce8) >> 0x17 & 1;
  return;
}


