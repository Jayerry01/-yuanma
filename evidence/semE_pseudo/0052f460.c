uint FUN_0052f460(int param_1)

{
  char cVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  cVar1 = FUN_0053b860(param_1);
  if (cVar1 != '\0') {
    return 0x42d;
  }
  cVar1 = FUN_0053b490(param_1);
  if (cVar1 != '\0') {
    return 0x425;
  }
  cVar1 = FUN_0053a150(param_1);
  return -(uint)(cVar1 != '\0') & 0x420;
}


