void __thiscall FUN_004eba70(int param_1,int param_2)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  int iVar4;
  short *psVar5;
  int local_10;
  float local_c;
  float local_8;
  int local_4;
  
  if (*(int *)(param_1 + 0x80) != 0) {
    psVar5 = *(short **)(param_1 + 0x84);
    iVar4 = 0;
    if (0 < *(int *)(param_1 + 0x80)) {
      do {
        if (*psVar5 == 0) {
          local_8 = *(float *)(psVar5 + 4);
          local_c = *(float *)(psVar5 + 2);
          iVar1 = *(int *)(param_1 + 0x48);
        }
        else {
          iVar1 = *(int *)(param_1 + 0x4c);
          local_c = (float)param_2 * *(float *)(psVar5 + 2);
          local_8 = (float)param_2 * *(float *)(psVar5 + 4);
        }
        iVar1 = FUN_0040bb20(*(undefined4 *)(iVar1 + 0x10 + psVar5[1] * 0x2c),&local_4,0,&local_10);
        pfVar2 = (float *)(iVar1 + 0x18);
        local_10 = local_10 + -1;
        iVar1 = 0;
        if (0 < local_4) {
          do {
            pfVar3 = pfVar2 + 1;
            iVar1 = iVar1 + 1;
            *pfVar2 = local_c + *pfVar2;
            *pfVar3 = local_8 + *pfVar3;
            pfVar2 = pfVar3 + local_10;
          } while (iVar1 < local_4);
        }
        psVar5 = psVar5 + 6;
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(param_1 + 0x80));
    }
  }
  return;
}


