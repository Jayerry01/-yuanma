FUN_0047f8e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  
  FUN_0052c070(*(undefined4 *)(param_1 + 0x80));
  cVar1 = FUN_0052f5a0(param_2,param_3,param_4);
  if (cVar1 == '\0') {
    return 0;
  }
  FUN_0052eb20(0x1908,0x1400);
  *(undefined4 *)(param_1 + 0xa0) = 1;
  uVar2 = FUN_0047f290(*(undefined4 *)(param_1 + 0x80));
  *(undefined4 *)(param_1 + 0x88) = uVar2;
  uVar2 = FUN_0047f2c0(*(undefined4 *)(param_1 + 0x80));
  *(undefined4 *)(param_1 + 0x8c) = uVar2;
  return 1;
}



undefined1 __thiscall