undefined1 __thiscall FUN_0047f870(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  FUN_0052c070(*(undefined4 *)(param_1 + 0x84));
  cVar1 = FUN_0052f630(param_2);
  if (cVar1 == '\0') {
    return 0;
  }
  FUN_0052eb20(0x1909,0x1400);
  *(undefined4 *)(param_1 + 0xa4) = 1;
  uVar2 = FUN_0047f290(*(undefined4 *)(param_1 + 0x84));
  *(undefined4 *)(param_1 + 0x90) = uVar2;
  uVar2 = FUN_0047f2c0(*(undefined4 *)(param_1 + 0x84));
  *(undefined4 *)(param_1 + 0x94) = uVar2;
  return 1;
}



undefined1 __thiscall