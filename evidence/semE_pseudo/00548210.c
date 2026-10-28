void FUN_00548210(int param_1,float *param_2,int param_3,int param_4,float param_5,int param_6)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  int iVar4;
  
  if (0 < param_1 * 8) {
    iVar1 = (param_1 * 8 - 1U >> 3) + 1;
    pfVar3 = param_2;
    do {
      if (0 < param_6) {
        pfVar2 = pfVar3;
        iVar4 = param_6;
        do {
          iVar4 = iVar4 + -1;
          *(float *)((param_4 - (int)param_2) + -4 + (int)(pfVar2 + 1)) =
               (*(float *)((param_3 - (int)param_2) + (int)pfVar2) - *pfVar2) * param_5 + *pfVar2;
          pfVar2 = pfVar2 + 1;
        } while (iVar4 != 0);
      }
      pfVar3 = pfVar3 + 8;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}


