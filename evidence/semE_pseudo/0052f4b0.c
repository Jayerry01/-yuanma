uint FUN_0052f4b0(int param_1,undefined4 param_2)

{
  char cVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  cVar1 = FUN_0053b890(param_1,param_2);
  if (cVar1 != '\0') {
    return 0x42d;
  }
  cVar1 = FUN_0053b4c0(param_1,param_2);
  if (cVar1 != '\0') {
    return 0x425;
  }
  cVar1 = FUN_0053a180(param_1,param_2);
  return -(uint)(cVar1 != '\0') & 0x420;
}


