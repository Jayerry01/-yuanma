undefined4 __thiscall FUN_00467840(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 in_stack_00000018;
  int in_stack_0000001c;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  
  *(undefined4 *)(param_1 + 0x68) = in_stack_00000024;
  *(undefined4 *)(param_1 + 100) = in_stack_00000020;
  puVar4 = (undefined4 *)(param_1 + 0x20);
  for (iVar3 = 5; register0x00000010 = (BADSPACEBASE *)((int)register0x00000010 + 4), iVar3 != 0;
      iVar3 = iVar3 + -1) {
    *puVar4 = *(undefined4 *)register0x00000010;
    puVar4 = puVar4 + 1;
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x34) = in_stack_00000018;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  if (in_stack_0000001c != 0) {
    FUN_00429990(0);
    uVar1 = __ftol();
    uVar1 = __ftol(uVar1);
    FUN_00429aa0(in_stack_0000001c,0,uVar1);
    uVar1 = FUN_00429c30(0);
    *(undefined4 *)(param_1 + 0x3c) = uVar1;
    uVar2 = __ftol();
    uVar2 = __ftol(uVar2);
    FUN_00429d00(uVar1,uVar2);
    FUN_00429d80(*(undefined4 *)(param_1 + 0x3c),0,0,0xff,1);
  }
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x40) = 1;
  *(undefined4 *)(param_1 + 0x74) = 1;
  return 1;
}


