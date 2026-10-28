void FUN_004c1900(int param_1,int param_2)

{
  float fVar1;
  char cVar2;
  float10 fVar3;
  undefined4 uVar4;
  
  if ((param_1 != param_2) && (cVar2 = FUN_004c1a80(param_1,param_2), cVar2 != '\0')) {
    FUN_004c2bf0(param_1);
    FUN_004c2bf0(param_2);
    fVar3 = (float10)FUN_0047ecf0();
    fVar1 = (float)fVar3;
    cVar2 = FUN_004c1d50(param_1,param_2);
    if (cVar2 != '\0') {
      FUN_00502cd0(param_2,0,fVar1);
      FUN_00502cd0(param_1,0,fVar1);
      return;
    }
    cVar2 = FUN_004c1f70(param_1,param_2);
    if (cVar2 == '\0') {
      cVar2 = FUN_004c2040(param_1,param_2);
      if (cVar2 != '\0') {
        FUN_00502cd0(param_2,2,fVar1);
      }
      cVar2 = FUN_004c2040(param_2,param_1);
      if (cVar2 == '\0') {
        return;
      }
      uVar4 = 2;
    }
    else {
      FUN_00502cd0(param_2,1,fVar1);
      uVar4 = 1;
    }
    FUN_00502cd0(param_1,uVar4,fVar1);
  }
  return;
}


