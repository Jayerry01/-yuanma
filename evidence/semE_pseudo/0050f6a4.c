undefined4 FUN_0050f6a4(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    uVar2 = FUN_0050f07a();
    return uVar2;
  }
  if ((DAT_00667710 != (code *)0x0) && (iVar3 = FUN_00512732(DAT_00667710), iVar3 != 0)) {
    uVar2 = (*DAT_00667710)(param_1);
    return uVar2;
  }
  return 0;
}


