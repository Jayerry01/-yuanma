float10 FUN_0051443f(undefined4 param_1,undefined4 param_2,undefined8 param_3,double param_4,
                    undefined4 param_5)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = FUN_0051478a(param_1,&param_4,param_5);
  if (iVar1 == 0) {
    FUN_005144d7();
  }
  iVar1 = FUN_00514a76(param_1);
  if ((DAT_005cd498 == 0) && (iVar1 != 0)) {
    fVar2 = (float10)FUN_005149a1(iVar1,param_2,param_3,0,param_4,param_5);
    return fVar2;
  }
  FUN_00514a29(iVar1);
  FUN_00514ac3();
  return (float10)param_4;
}


