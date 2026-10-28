undefined4 __thiscall FUN_004bc280(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x9c))(param_2);
  if ((iVar1 != 0) && (iVar1 + -0x65c != 0)) {
    uVar2 = (**(code **)(*param_1 + 0xd0))(iVar1 + -0x65c);
    return uVar2;
  }
  return 0;
}


