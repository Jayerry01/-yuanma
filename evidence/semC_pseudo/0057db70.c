void __fastcall FUN_0057db70(int param_1)

{
  float *pfVar1;
  undefined4 *puVar2;
  float *pfVar3;
  
  puVar2 = (undefined4 *)FUN_00476090(0);
  *(undefined4 *)(param_1 + 0x1f8) = *puVar2;
  *(undefined4 *)(param_1 + 0x1fc) = puVar2[1];
  *(undefined4 *)(param_1 + 0x200) = puVar2[2];
  puVar2 = (undefined4 *)FUN_00476090(1);
  *(undefined4 *)(param_1 + 0x1ec) = *puVar2;
  *(undefined4 *)(param_1 + 0x1f0) = puVar2[1];
  *(undefined4 *)(param_1 + 500) = puVar2[2];
  pfVar3 = (float *)FUN_00476090(2);
  pfVar1 = (float *)(param_1 + 0x1e0);
  *pfVar1 = *pfVar3;
  *(float *)(param_1 + 0x1e4) = pfVar3[1];
  *(float *)(param_1 + 0x1e8) = pfVar3[2];
  *pfVar1 = -*pfVar1;
  *(float *)(param_1 + 0x1e4) = -*(float *)(param_1 + 0x1e4);
  *(float *)(param_1 + 0x1e8) = -*(float *)(param_1 + 0x1e8);
  puVar2 = (undefined4 *)FUN_00476090(3);
  *(undefined4 *)(param_1 + 0x1d4) = *puVar2;
  *(undefined4 *)(param_1 + 0x1d8) = puVar2[1];
  *(undefined4 *)(param_1 + 0x1dc) = puVar2[2];
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x1d4);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x1d8);
  *(float *)(param_1 + 0x10) = *(float *)(param_1 + 4) - *(float *)(param_1 + 0x34);
  *(float *)(param_1 + 0x14) = *(float *)(param_1 + 8) - *(float *)(param_1 + 0x38);
  *(float *)(param_1 + 0x18) = *(float *)(param_1 + 0xc) - *(float *)(param_1 + 0x3c);
  *(float *)(param_1 + 0x1c) = *(float *)(param_1 + 4) + *(float *)(param_1 + 0x34);
  *(float *)(param_1 + 0x20) = *(float *)(param_1 + 8) + *(float *)(param_1 + 0x38);
  *(float *)(param_1 + 0x24) = *(float *)(param_1 + 0xc) + *(float *)(param_1 + 0x3c);
  *(undefined4 *)(param_1 + 0x1a0) = DAT_005e0888;
  *(undefined4 *)(param_1 + 0x1a4) = DAT_005e0884;
  *(undefined4 *)(param_1 + 0x1a8) = DAT_005e0898;
  return;
}


