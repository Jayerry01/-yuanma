undefined4 __thiscall FUN_00469f70(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  
  puVar3 = (undefined4 *)(param_1 + 0x28);
  for (iVar2 = 5; register0x00000010 = (BADSPACEBASE *)((int)register0x00000010 + 4), iVar2 != 0;
      iVar2 = iVar2 + -1) {
    *puVar3 = *(undefined4 *)register0x00000010;
    puVar3 = puVar3 + 1;
  }
  FUN_00429990(0);
  if (*(int *)(param_1 + 0x30) == 0x41000000) {
    uVar1 = __ftol();
    uVar1 = __ftol(uVar1);
    FUN_00429aa0(&PTR_DAT_005c7bbc,0,uVar1);
  }
  else {
    uVar1 = __ftol();
    uVar1 = __ftol(uVar1);
    FUN_00429b80(1,1,1,uVar1);
  }
  uVar1 = FUN_00429c30(0);
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  if (*(int *)(param_1 + 0x30) != 0x41000000) {
    FUN_00429e90(uVar1,0,0xff,0xff,0);
  }
  FUN_00429d80(*(undefined4 *)(param_1 + 0x24),0xff,0xff,0xff,1);
  uVar1 = __ftol();
  uVar1 = __ftol(uVar1);
  FUN_00429d00(*(undefined4 *)(param_1 + 0x24),uVar1);
  *(undefined4 *)(param_1 + 0x14) = in_stack_00000018;
  *(undefined4 *)(param_1 + 0x18) = in_stack_0000001c;
  *(undefined4 *)(param_1 + 0x20) = in_stack_00000020;
  *(undefined4 *)(param_1 + 0x1c) = in_stack_00000024;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  return 1;
}


