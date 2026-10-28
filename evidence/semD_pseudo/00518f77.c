int FUN_00518f77(int param_1)

{
  int iVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  
  if (param_1 == 0) {
    DAT_005cda68 = 0xffff;
    ppuVar2 = &PTR_FUN_005cd980;
    ppuVar3 = &PTR_LAB_005cd898;
    for (iVar1 = 0x39; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppuVar3 = *ppuVar2;
      ppuVar2 = ppuVar2 + 1;
      ppuVar3 = ppuVar3 + 1;
    }
  }
  else if (DAT_005cda68 == 0xffff) {
    DAT_005cda68 = 0;
    ppuVar2 = &PTR_FUN_005cd980;
    ppuVar3 = &PTR_LAB_005cd898;
    for (iVar1 = 0x39; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppuVar3 = *ppuVar2;
      ppuVar2 = ppuVar2 + 1;
      ppuVar3 = ppuVar3 + 1;
    }
    FUN_005199d7(&PTR_LAB_005cd898);
    iVar1 = FUN_00518d8a(4,"DisableD3DXPSGP",&param_1,4);
    if (iVar1 == 0) {
      param_1 = 0;
    }
    if (param_1 != 1) {
      iVar1 = FUN_00518ec3(7);
      if (iVar1 == 0) {
        iVar1 = FUN_00518ec3(10);
        if (iVar1 == 0) {
          iVar1 = FUN_00518ec3(6);
          if (iVar1 != 0) {
            FUN_00519060(&PTR_LAB_005cd898);
            DAT_005cda68 = 3;
          }
        }
        else {
          FUN_00519170(&PTR_LAB_005cd898);
          DAT_005cda68 = 2;
        }
      }
      else {
        FUN_00519355(&PTR_LAB_005cd898);
        DAT_005cda68 = 1;
      }
    }
  }
  return DAT_005cda68;
}


