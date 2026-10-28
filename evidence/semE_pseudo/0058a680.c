void FUN_0058a680(char *param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar3 = param_2;
  pcVar2 = param_1;
  uVar4 = 0xffffffff;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  param_1 = (char *)(~uVar4 - 1);
  FUN_00509fa2(&param_1,4,1,param_2);
  if (param_1 != (char *)0x0) {
    FUN_00509fa2(pcVar2,param_1,1,uVar3);
  }
  return;
}


