undefined4 __thiscall FUN_0046a670(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 in_stack_00000018;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar5 = (undefined4 *)(param_1 + 0xc);
  puVar4 = (undefined4 *)register0x00000010;
  for (iVar3 = 5; puVar4 = puVar4 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar5 = puVar5 + 1;
  }
  FUN_00429990(0);
  uVar1 = __ftol();
  uVar1 = __ftol(uVar1);
  FUN_00429aa0(in_stack_00000018,0,uVar1);
  uVar1 = FUN_00429c30(0);
  *(undefined4 *)(param_1 + 8) = uVar1;
  uVar2 = __ftol();
  uVar2 = __ftol(uVar2);
  FUN_00429d00(uVar1,uVar2);
  local_4 = 0;
  local_8 = 1;
  param_2 = 0;
  FUN_00429e00(*(undefined4 *)(param_1 + 8),&local_4,&local_8,&param_2);
  FUN_00429d80(*(undefined4 *)(param_1 + 8),0,0,0xff,1);
  *(undefined4 *)(param_1 + 0x20) = 0;
  return 1;
}


