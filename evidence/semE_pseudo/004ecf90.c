undefined4 FUN_004ecf90(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x44))();
  if (iVar1 != 0) {
    iVar1 = *param_1;
    uVar2 = (**(code **)(iVar1 + 0x44))();
    (**(code **)(iVar1 + 0x14))(uVar2);
  }
  return 1;
}


