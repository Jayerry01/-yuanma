undefined4 FUN_004f56d0(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  (**(code **)(*param_1 + 0xcc))(0);
  piVar1 = (int *)FUN_00487830();
  iVar2 = (**(code **)(*piVar1 + 0x2d4))();
  if (iVar2 == 2) {
    piVar1 = (int *)FUN_00487830();
    (**(code **)(*piVar1 + 0x2dc))(1);
  }
  iVar2 = (**(code **)(*param_1 + 0x44))();
  *(undefined4 *)(iVar2 + 0x3c4) = 1;
  if (param_1[param_1[0xfc] + 0xf2] != 0) {
    (**(code **)(*param_1 + 0x14))(param_1[param_1[0xfc] + 0xf2]);
  }
  piVar1 = (int *)FUN_00487830();
  (**(code **)(*piVar1 + 0x254))(1);
  return 1;
}


