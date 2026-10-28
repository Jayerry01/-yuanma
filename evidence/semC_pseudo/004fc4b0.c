void __thiscall FUN_004fc4b0(int param_1,int param_2)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  
  FUN_004fd580();
  *(int *)(param_1 + 0xc4) = param_2;
  if (param_2 == -2) {
    pfVar1 = (float *)(param_1 + 200);
    *pfVar1 = *(float *)(param_1 + 0xd4);
    *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(param_1 + 0xd8);
    *(undefined4 *)(param_1 + 0xd0) = *(undefined4 *)(param_1 + 0xdc);
    iVar2 = _rand();
    *pfVar1 = (*pfVar1 - 5.0) + (float)(iVar2 % 10);
    iVar2 = _rand();
    *(float *)(param_1 + 0xcc) = (*(float *)(param_1 + 0xcc) - 5.0) + (float)(iVar2 % 10);
  }
  if (-1 < *(int *)(param_1 + 0xc4)) {
    pfVar1 = (float *)(param_1 + 200);
    iVar2 = FUN_004c2bf0(*(int *)(param_1 + 0xc4));
    *pfVar1 = *(float *)(iVar2 + 4);
    *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(iVar2 + 8);
    *(undefined4 *)(param_1 + 0xd0) = *(undefined4 *)(iVar2 + 0xc);
    iVar2 = FUN_004c2bf0(*(undefined4 *)(param_1 + 0xc4));
    iVar2 = *(short *)(iVar2 + 0x14) + -10;
    if (0 < iVar2) {
      iVar3 = _rand();
      *pfVar1 = (*pfVar1 - (float)(iVar2 / 2)) + (float)(iVar3 % iVar2);
      iVar3 = _rand();
      *(float *)(param_1 + 0xcc) =
           (*(float *)(param_1 + 0xcc) - (float)(iVar2 / 2)) + (float)(iVar3 % iVar2);
    }
  }
  if ((*(int *)(param_1 + 0xc4) != -1) && (*(int *)(param_1 + 0xc) != 0)) {
    FUN_00500fa0();
    FUN_00500c60(0);
    FUN_005012a0(0);
  }
  return;
}


