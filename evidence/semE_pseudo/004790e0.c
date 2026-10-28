void FUN_004790e0(float param_1)

{
  float fVar1;
  char cVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  float *pfVar6;
  
  pfVar4 = (float *)&DAT_005ecd70;
  iVar5 = 0x100;
  do {
    iVar3 = -1;
    pfVar6 = pfVar4 + -8;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      cVar2 = *(char *)pfVar6;
      pfVar6 = (float *)((int)pfVar6 + 1);
    } while (cVar2 != '\0');
    if ((iVar3 != -2) && (fVar1 = *pfVar4, *pfVar4 = param_1 + fVar1, pfVar4[1] < param_1 + fVar1))
    {
      fVar1 = pfVar4[-1];
      *pfVar4 = 0.0;
      pfVar4[-1] = (float)((int)fVar1 + 1);
      if ((int)pfVar4[-3] <= (int)fVar1 + 1) {
        pfVar4[-1] = 0.0;
      }
    }
    pfVar4 = pfVar4 + 10;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      return;
    }
  } while( true );
}


