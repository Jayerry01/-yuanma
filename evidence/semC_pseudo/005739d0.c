void __fastcall FUN_005739d0(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  int iVar4;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined1 local_c [8];
  float local_4;
  
  if (*(int *)(param_1 + 0x2c) != 0) {
    pfVar1 = (float *)(param_1 + 0x84);
    iVar4 = 8;
    pfVar3 = pfVar1;
    do {
      pfVar2 = (float *)FUN_00476e80(local_c,pfVar3 + 0x28,param_1 + 0x184);
      *pfVar3 = *pfVar2;
      iVar4 = iVar4 + -1;
      pfVar3[1] = pfVar2[1];
      pfVar3[2] = pfVar2[2];
      pfVar3 = pfVar3 + 3;
    } while (iVar4 != 0);
    local_4 = *(float *)(param_1 + 0x8c) + *(float *)(param_1 + 0xd4);
    *(float *)(param_1 + 0x78) = (*pfVar1 + *(float *)(param_1 + 0xcc)) * 0.5;
    *(float *)(param_1 + 0x7c) = (*(float *)(param_1 + 0x88) + *(float *)(param_1 + 0xd0)) * 0.5;
    *(float *)(param_1 + 0x80) = local_4 * 0.5;
    local_30 = *(float *)(param_1 + 0x90) - *pfVar1;
    local_2c = *(float *)(param_1 + 0x94) - *(float *)(param_1 + 0x88);
    local_28 = *(float *)(param_1 + 0x98) - *(float *)(param_1 + 0x8c);
    FUN_0047ec40();
    local_24 = *(float *)(param_1 + 0xb4) - *pfVar1;
    local_20 = *(float *)(param_1 + 0xb8) - *(float *)(param_1 + 0x88);
    local_1c = *(float *)(param_1 + 0xbc) - *(float *)(param_1 + 0x8c);
    FUN_0047ec40();
    local_18 = *(float *)(param_1 + 0xa8) - *pfVar1;
    local_14 = *(float *)(param_1 + 0xac) - *(float *)(param_1 + 0x88);
    local_10 = *(float *)(param_1 + 0xb0) - *(float *)(param_1 + 0x8c);
    FUN_0047ec40();
    FUN_00477b90(0,&local_30);
    FUN_00477b90(1,&local_24);
    FUN_00477b90(2,&local_18);
    FUN_00477b90(3,(float *)(param_1 + 0x78));
  }
  return;
}


