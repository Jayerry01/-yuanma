undefined4 FUN_0052f420(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = (*DAT_007dc83c)(param_1);
  if (iVar1 == 0) {
    FUN_00530d00(0x50a);
    return 0;
  }
  uVar2 = FUN_0052f460(iVar1);
  (*DAT_007dc848)(iVar1);
  return uVar2;
}


