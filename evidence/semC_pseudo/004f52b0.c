undefined4 FUN_004f52b0(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(*param_1 + 0x44))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*param_1 + 0x44))();
    *(undefined4 *)(iVar1 + 0x3c4) = 0;
    (**(code **)(*param_1 + 0x10))(param_1[0x69]);
  }
  if (param_1[param_1[0xfc] + 0xf2] != 0) {
    (**(code **)(*param_1 + 0x10))(param_1[param_1[0xfc] + 0xf2]);
    (**(code **)(*param_1 + 0x19c))(2);
  }
  piVar2 = (int *)FUN_00487830();
  (**(code **)(*piVar2 + 0x1d8))(1);
  piVar2 = (int *)FUN_00487830();
  (**(code **)(*piVar2 + 0x1dc))(1);
  piVar2 = (int *)FUN_00487830();
  uVar3 = (**(code **)(*piVar2 + 0x74))();
  FUN_0040fa50(0,uVar3);
  piVar2 = (int *)FUN_00487830();
  uVar3 = (**(code **)(*piVar2 + 0x74))(0);
  FUN_0040b100(uVar3);
  piVar2 = (int *)FUN_00487830();
  uVar3 = (**(code **)(*piVar2 + 0x74))(0x3faa3d71,0x42700000);
  FUN_00404cb0(uVar3);
  iVar1 = FUN_00487830();
  (**(code **)(**(int **)(iVar1 + 0x2484) + 0xc))();
  piVar2 = (int *)FUN_00487830();
  (**(code **)(*piVar2 + 0x254))(0);
  piVar2 = (int *)FUN_00487830();
  (**(code **)(*piVar2 + 0x304))(1);
  piVar2 = (int *)FUN_00487830();
  iVar1 = (**(code **)(*piVar2 + 0x2d4))();
  if (iVar1 == 2) {
    piVar2 = (int *)FUN_00487830();
    (**(code **)(*piVar2 + 0x300))(0);
    return 1;
  }
  piVar2 = (int *)FUN_00487830();
  (**(code **)(*piVar2 + 0x300))(1);
  return 1;
}


