void FUN_00475cf0(void)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  float *pfVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  float *pfVar8;
  float10 fVar9;
  float afStack_1c0 [4];
  float fStack_1b0;
  float fStack_1ac;
  float fStack_1a8;
  float fStack_1a4;
  float fStack_1a0;
  float fStack_19c;
  float fStack_198;
  float fStack_194;
  float fStack_190;
  float fStack_18c;
  float fStack_188;
  float fStack_184;
  undefined4 auStack_180 [16];
  undefined1 auStack_140 [64];
  undefined1 auStack_100 [64];
  undefined1 auStack_c0 [64];
  undefined1 auStack_80 [64];
  undefined1 auStack_40 [64];
  
  uVar1 = DAT_005e04e4;
  FUN_00474570(3);
  if ((DAT_005e03a0 < 0) || (1 < DAT_005e03a0)) {
    puVar6 = &DAT_005e0568;
    puVar7 = auStack_180;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
  }
  else {
    thunk_FUN_004e8500(auStack_180);
  }
  if (DAT_005e03a0 != 0) {
    FUN_00474570(1);
    thunk_FUN_004e8500(auStack_100);
  }
  FUN_00474570(0);
  thunk_FUN_004e8500(auStack_140);
  FUN_00474570(uVar1);
  if (DAT_005e03a0 == 0) {
    puVar6 = auStack_180;
    puVar2 = auStack_140;
    puVar4 = auStack_40;
  }
  else {
    puVar6 = auStack_180;
    puVar2 = (undefined1 *)FUN_00476f00(auStack_80,auStack_140,auStack_100,puVar6);
    puVar4 = auStack_c0;
  }
  pfVar3 = (float *)FUN_00476f00(puVar4,puVar2,puVar6);
  pfVar8 = afStack_1c0;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pfVar8 = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pfVar8 = pfVar8 + 1;
  }
  DAT_005e08b4 = -(afStack_1c0[0] + afStack_1c0[3]);
  DAT_005e08b8 = -(fStack_1b0 + fStack_1a4);
  DAT_005e08bc = -(fStack_1a0 + fStack_194);
  DAT_005e08c0 = -(fStack_190 + fStack_184);
  DAT_005e08c4 = -(afStack_1c0[3] - afStack_1c0[0]);
  DAT_005e08c8 = -(fStack_1a4 - fStack_1b0);
  DAT_005e08cc = -(fStack_194 - fStack_1a0);
  DAT_005e08d0 = -(fStack_184 - fStack_190);
  _DAT_005e08d4 = -(afStack_1c0[3] - afStack_1c0[1]);
  _DAT_005e08d8 = -(fStack_1a4 - fStack_1ac);
  _DAT_005e08dc = -(fStack_194 - fStack_19c);
  _DAT_005e08e0 = -(fStack_184 - fStack_18c);
  _DAT_005e08e4 = -(afStack_1c0[1] + afStack_1c0[3]);
  _DAT_005e08e8 = -(fStack_1ac + fStack_1a4);
  _DAT_005e08ec = -(fStack_19c + fStack_194);
  _DAT_005e08f0 = -(fStack_18c + fStack_184);
  _DAT_005e08f4 = -afStack_1c0[2];
  _DAT_005e08f8 = -fStack_1a8;
  _DAT_005e08fc = -fStack_198;
  _DAT_005e0900 = -fStack_188;
  _DAT_005e0904 = -(afStack_1c0[3] - afStack_1c0[2]);
  _DAT_005e0908 = -(fStack_1a4 - fStack_1a8);
  _DAT_005e090c = -(fStack_194 - fStack_198);
  _DAT_005e0910 = -(fStack_184 - fStack_188);
  pfVar3 = &DAT_005e08b4;
  do {
    fVar9 = (float10)FUN_0047ecf0();
    fVar9 = (float10)1.0 / fVar9;
    pfVar8 = pfVar3 + 4;
    *pfVar3 = (float)(fVar9 * (float10)*pfVar3);
    pfVar3[1] = (float)(fVar9 * (float10)pfVar3[1]);
    pfVar3[2] = (float)(fVar9 * (float10)pfVar3[2]);
    pfVar3[3] = (float)(fVar9 * (float10)pfVar3[3]);
    pfVar3 = pfVar8;
  } while ((int)pfVar8 < 0x5e0914);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
