void FUN_00477140(float *param_1,float param_2,float *param_3)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  float local_40 [16];
  
  iVar3 = 0x10;
  pfVar2 = param_3;
  do {
    fVar1 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    iVar3 = iVar3 + -1;
    *(float *)((int)local_40 + (-4 - (int)param_3) + (int)pfVar2) = param_2 * fVar1;
  } while (iVar3 != 0);
  pfVar2 = local_40;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}



void __thiscall