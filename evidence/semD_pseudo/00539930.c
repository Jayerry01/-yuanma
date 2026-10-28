void FUN_00539930(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  
  iVar1 = ((&DAT_007232f8)[param_2 * 4] - param_3) * param_1;
  (&DAT_007232f8)[param_2 * 4] =
       (&DAT_007232f8)[param_2 * 4] - ((int)(iVar1 + (iVar1 >> 0x1f & 0x3ffU)) >> 10);
  iVar1 = ((&DAT_007232fc)[param_2 * 4] - param_4) * param_1;
  (&DAT_007232fc)[param_2 * 4] =
       (&DAT_007232fc)[param_2 * 4] - ((int)(iVar1 + (iVar1 >> 0x1f & 0x3ffU)) >> 10);
  iVar1 = (&DAT_00723300)[param_2 * 4];
  param_1 = (iVar1 - param_5) * param_1;
  (&DAT_00723300)[param_2 * 4] = iVar1 - ((int)(param_1 + (param_1 >> 0x1f & 0x3ffU)) >> 10);
  return;
}


