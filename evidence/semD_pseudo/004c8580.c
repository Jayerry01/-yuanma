void FUN_004c8580(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(*param_1 + 0x340))();
  if ((iVar1 == 0) && (param_1[0x8ae] == 0)) {
    param_1[0x854] = 1;
    (**(code **)(param_1[0x922] + 0x1ac))(1);
    if (param_1[0x84b] == 0) {
      iVar1 = param_1[0x898];
      uVar2 = 0;
      uVar3 = 0;
    }
    else if (*(int *)(param_1[0x84b] + 0x3a0) == 0) {
      iVar1 = param_1[0x898];
      uVar3 = 1;
      uVar2 = 1;
    }
    else {
      iVar1 = param_1[0x898];
      uVar3 = 0;
      uVar2 = 1;
    }
    FUN_00463450(iVar1,uVar2,uVar3);
    FUN_00451110(iVar1,uVar2,uVar3);
    param_1[0x854] = 0;
    iVar1 = (**(code **)(*param_1 + 0x380))();
    if (iVar1 != 0) {
      (**(code **)(*param_1 + 0x3c0))(1);
      (**(code **)(*param_1 + 0x34c))(0);
    }
    return;
  }
                    // WARNING: Could not recover jumptable at 0x004c864f. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(param_1[0x922] + 0x1ac))();
  return;
}


