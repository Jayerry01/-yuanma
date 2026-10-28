uint FUN_0053a2a0(short *param_1)

{
  short sVar1;
  
  if (((((*param_1 == 0x4d42) && (0x19 < *(uint *)(param_1 + 5))) && (0xb < *(uint *)(param_1 + 7)))
      && ((param_1[0xd] == 1 && (*(int *)(param_1 + 9) != 0)))) && (*(int *)(param_1 + 0xb) != 0)) {
    sVar1 = param_1[0xe];
    param_1 = (short *)CONCAT22((short)((uint)param_1 >> 0x10),sVar1);
    if (((sVar1 == 1) || (sVar1 == 4)) || ((sVar1 == 8 || ((sVar1 == 0x18 || (sVar1 == 0x20)))))) {
      return CONCAT31((int3)((uint)param_1 >> 8),1);
    }
  }
  return (uint)param_1 & 0xffffff00;
}


