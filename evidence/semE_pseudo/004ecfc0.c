undefined4 FUN_004ecfc0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x44))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*param_1 + 0x44))();
    *(undefined4 *)(iVar1 + 0x3c4) = 1;
    iVar1 = *param_1;
    uVar2 = (**(code **)(iVar1 + 0x44))();
    (**(code **)(iVar1 + 0x10))(uVar2);
  }
  return 1;
}


