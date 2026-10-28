undefined4 __thiscall FUN_004636d0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_stack_00000018;
  undefined4 in_stack_0000001c;
  
  *(undefined4 *)(param_1 + 0x30) = in_stack_0000001c;
  FUN_00429990(0);
  uVar1 = __ftol();
  uVar1 = __ftol(uVar1);
  if (in_stack_00000018 == 0) {
    FUN_00429b80(1,1,1,uVar1);
    uVar1 = FUN_00429c30(0);
    *(undefined4 *)(param_1 + 8) = uVar1;
    FUN_00429d80(uVar1,0,0,0,1);
  }
  else {
    FUN_00429aa0(in_stack_00000018,0);
    uVar1 = FUN_00429c30(0);
    *(undefined4 *)(param_1 + 8) = uVar1;
    FUN_00429d80(uVar1,0,0,0xff,1);
  }
  uVar1 = __ftol();
  uVar1 = __ftol(uVar1);
  FUN_00429d00(*(undefined4 *)(param_1 + 8),uVar1);
  puVar3 = (undefined4 *)(param_1 + 0xc);
  for (iVar2 = 5; register0x00000010 = (BADSPACEBASE *)((int)register0x00000010 + 4), iVar2 != 0;
      iVar2 = iVar2 + -1) {
    *puVar3 = *(undefined4 *)register0x00000010;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(param_1 + 0x20) = 1;
  return 1;
}


