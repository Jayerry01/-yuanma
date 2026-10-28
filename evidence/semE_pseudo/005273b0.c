void FUN_005273b0(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = FUN_00525980();
  if (*(int *)(*(int *)(iVar2 + 0x60) + 0x130) != 0) {
    FUN_00525610(DAT_00667a28);
    piVar1 = *(int **)(*(int *)(iVar2 + 0x60) + 0x130);
    (**(code **)(*piVar1 + 0x44))(piVar1);
    FUN_00525620(iVar2);
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
