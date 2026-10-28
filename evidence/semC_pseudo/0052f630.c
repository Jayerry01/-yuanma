undefined4 FUN_0052f630(char *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  
  iVar2 = FUN_00530e70(param_1);
  if (DAT_0072329c == 0) {
    FUN_00530d00(0x506);
    return 0;
  }
  if (param_1 != (char *)0x0) {
    iVar4 = -1;
    pcVar5 = param_1;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    if (iVar4 != -2) {
      if (iVar2 != 0) {
        cVar1 = FUN_005310c0(param_1);
        if (cVar1 != '\0') {
          return 1;
        }
        iVar4 = thunk_FUN_0050a9d0(iVar2,&PTR_DAT_005cfe14);
        if ((((iVar4 == 0) || (iVar4 = thunk_FUN_0050a9d0(iVar2,&PTR_DAT_005cfe10), iVar4 == 0)) ||
            (iVar4 = thunk_FUN_0050a9d0(iVar2,&PTR_DAT_005cfe0c), iVar4 == 0)) ||
           (iVar4 = thunk_FUN_0050a9d0(iVar2,&PTR_DAT_005cfe08), iVar4 == 0)) {
          uVar3 = FUN_0053b960(param_1);
          return uVar3;
        }
        iVar4 = thunk_FUN_0050a9d0(iVar2,&PTR_DAT_005cfe04);
        if (((iVar4 == 0) || (iVar4 = thunk_FUN_0050a9d0(iVar2,&PTR_DAT_005cfe00), iVar4 == 0)) ||
           (iVar4 = thunk_FUN_0050a9d0(iVar2,&DAT_005cfdf8), iVar4 == 0)) {
          uVar3 = FUN_0053b4e0(param_1);
          return uVar3;
        }
        iVar4 = thunk_FUN_0050a9d0(iVar2,&PTR_DAT_005cfdf4);
        if ((iVar4 == 0) || (iVar2 = thunk_FUN_0050a9d0(iVar2,&PTR_DAT_005cfdf0), iVar2 == 0)) {
          uVar3 = FUN_0053a300(param_1);
          return uVar3;
        }
      }
      iVar2 = FUN_0052f420(param_1);
      if (iVar2 == 0) {
        return 0;
      }
      uVar3 = FUN_0052f510(iVar2,param_1);
      return uVar3;
    }
  }
  FUN_00530d00(0x509);
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
