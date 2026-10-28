uint FUN_0052f510(uint param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  
  if (param_2 != (char *)0x0) {
    iVar3 = -1;
    pcVar4 = param_2;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (iVar3 != -2) {
      if (param_1 < 0x426) {
        if (param_1 == 0x425) {
          uVar2 = FUN_0053b4e0(param_2);
          return uVar2;
        }
        if (param_1 == 0) {
          uVar2 = FUN_0052f630(param_2);
          return uVar2;
        }
        if (param_1 == 0x420) {
          uVar2 = FUN_0053a300(param_2);
          return uVar2;
        }
      }
      else if (param_1 == 0x42d) {
        uVar2 = FUN_0053b960(param_2);
        return uVar2;
      }
      uVar2 = FUN_00530d00(0x501);
      return uVar2 & 0xffffff00;
    }
  }
  uVar2 = FUN_00530d00(0x509);
  return uVar2 & 0xffffff00;
}


