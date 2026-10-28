uint FUN_0053a250(short *param_1)

{
  short sVar1;
  uint in_EAX;
  
  if (((((*param_1 != 0x4d42) || (*(int *)(param_1 + 7) != 0x28)) ||
       (in_EAX = 0, *(int *)(param_1 + 0xb) == 0)) ||
      ((in_EAX = 1, *(int *)(param_1 + 9) < 1 || (1 < param_1[0xd])))) ||
     ((((sVar1 = param_1[0xe], sVar1 != 8 && ((sVar1 != 0x18 && (sVar1 != 0x20)))) && (sVar1 != 4))
      && (sVar1 != 1)))) {
    in_EAX = in_EAX & 0xffffff00;
  }
  return in_EAX;
}


