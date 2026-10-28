void FUN_004c8490(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x364))();
  if (iVar1 == 0) {
    iVar1 = (**(code **)(param_1[0x922] + 0x50))();
    if (iVar1 != 0) {
      (**(code **)(*param_1 + 0xac))(4);
      (**(code **)(*param_1 + 0x28c))();
      (**(code **)(*param_1 + 0x1b8))();
      return;
    }
    (**(code **)(param_1[0x922] + 0x1ac))(1);
    FUN_00463450();
    FUN_0044e1c0();
    (**(code **)(*param_1 + 0x1b8))();
  }
  return;
}


