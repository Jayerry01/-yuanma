int FUN_00509ed4(char *param_1,undefined4 param_2)

{
  size_t sVar1;
  undefined4 uVar2;
  size_t sVar3;
  
  sVar1 = _strlen(param_1);
  FUN_0050c5d1(param_2);
  uVar2 = FUN_00510427(param_2);
  sVar3 = FUN_00509fd1(param_1,1,sVar1,param_2);
  FUN_005104b4(uVar2,param_2);
  FUN_0050c623(param_2);
  return (sVar3 == sVar1) - 1;
}


