void FUN_0052d860(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  if (DAT_0072329c == 0) {
    FUN_00530d00(0x506);
    return;
  }
  if (param_9 != 0) {
    iVar4 = *(int *)(DAT_0072329c + 0x20);
    if ((param_7 != iVar4) || (iVar3 = param_9, param_8 != *(int *)(DAT_0072329c + 0x24))) {
      uVar5 = *(undefined4 *)(DAT_0072329c + 0x24);
      iVar3 = param_7;
      iVar6 = param_8;
      iVar7 = param_9;
      uVar1 = FUN_00530eb0(param_7);
      uVar2 = FUN_00530f00(param_8);
      iVar3 = FUN_005318a0((uVar1 & 0xff) * (uVar2 & 0xff) * param_4 * param_5 * param_6,iVar3,iVar4
                           ,uVar5,iVar6,iVar7);
      if (iVar3 == 0) {
        return;
      }
    }
    if ((uint)(param_2 + param_5) < 2) {
      FUN_0052d330(param_1,param_4);
    }
    else if ((uint)(param_3 + param_6) < 2) {
      FUN_0052d410(param_1,param_2,param_4,param_5);
    }
    else {
      FUN_0052d5e0(param_1,param_2,param_3,param_4,param_5,param_6,iVar3);
    }
    if (((param_7 != *(int *)(DAT_0072329c + 0x20)) || (param_8 != *(int *)(DAT_0072329c + 0x24)))
       && (iVar3 != param_9)) {
      FUN_00530db0(iVar3);
    }
    return;
  }
  FUN_00530d00(0x509);
  return;
}


