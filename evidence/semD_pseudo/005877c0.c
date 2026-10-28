undefined4 __thiscall FUN_005877c0(int param_1,float *param_2)

{
  float *pfVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x268)) {
    pfVar1 = (float *)(*(int *)(param_1 + 0x28c) + 0xc);
    do {
      if ((((*param_2 < pfVar1[-1]) && (param_2[1] < *pfVar1)) && (param_2[2] < pfVar1[1])) &&
         (((pfVar1[-1] < param_2[0x12] && (*pfVar1 < param_2[0x13])) && (pfVar1[1] < param_2[0x14]))
         )) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      pfVar1 = pfVar1 + 0x2b;
    } while (iVar2 < *(int *)(param_1 + 0x268));
  }
  return 0;
}


