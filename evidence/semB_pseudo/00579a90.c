void __fastcall FUN_00579a90(int *param_1)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  ushort *puVar10;
  float10 fVar11;
  float fVar12;
  int *piStack_48;
  uint uStack_3c;
  
  FUN_00475590(0,1);
  FUN_00475590(0x14,1);
  FUN_00475590(0x15,1);
  FUN_00475590(1,1);
  FUN_00475950(&DAT_005c7df8,&DAT_005c7df0);
  FUN_00476090(2);
  FUN_00476090(3);
  FUN_0047ec40();
  fVar11 = (float10)FUN_0047ecf0();
  fVar2 = (float)(fVar11 * (float10)(float)param_1[0x54]);
  fVar3 = (float)(fVar11 * (float10)(float)param_1[0x55]);
  FUN_00476090(3);
  piVar5 = (int *)FUN_00476070(0);
  piVar1 = param_1 + 1;
  piVar9 = piVar1;
  for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar9 = *piVar5;
    piVar5 = piVar5 + 1;
    piVar9 = piVar9 + 1;
  }
  FUN_00477b90(3,param_1 + 0x11);
  FUN_00474410();
  if (*param_1 == 1) {
    uVar8 = 0xffffffff;
    piVar5 = param_1 + 0x14;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      iVar7 = *piVar5;
      piVar5 = (int *)((int)piVar5 + 1);
    } while ((char)iVar7 != '\0');
    uStack_3c = ~uVar8 - 1;
  }
  else {
    uStack_3c = FUN_0050b0ec(param_1 + 0x1c);
  }
  if (param_1[0x4f] == 1) {
    fVar12 = (float)uStack_3c * 0.25;
LAB_00579c47:
    FUN_00478150((0.5 - fVar12) * fVar2);
  }
  else if (param_1[0x4f] == 3) {
    fVar12 = (float)uStack_3c * 0.5;
    goto LAB_00579c47;
  }
  fVar12 = fVar3 * 0.5;
  FUN_00478190(fVar12);
  if (param_1[0x50] != 4) {
    if (param_1[0x50] != 5) goto LAB_00579ca0;
    fVar12 = fVar3 * -0.5;
  }
  FUN_00478190(fVar12);
LAB_00579ca0:
  iVar7 = 0;
  if (*param_1 == 1) {
    piStack_48 = param_1 + 0x14;
    if (0 < param_1[0x4e]) {
      piVar5 = param_1 + 0x2c;
      do {
        iVar4 = *piVar5;
        iVar6 = FUN_00593d6d(piStack_48);
        piStack_48 = (int *)((int)piStack_48 + iVar4);
        fVar12 = (float)iVar6 * 0.5 * fVar2;
        FUN_00477db0(fVar12,fVar3,0x3f800000);
        FUN_00474410();
        thunk_FUN_004e8500(piVar1);
        FUN_00479f80(*(undefined4 *)(param_1[0x51] + iVar7 * 4));
        FUN_0047c2e0(0);
        FUN_00474470();
        FUN_004781d0(0x3f800000,0,0,0);
        FUN_00477db0(1.0 / fVar12,1.0 / fVar3,0x3f800000);
        iVar7 = iVar7 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar7 < param_1[0x4e]);
    }
  }
  else if (0 < param_1[0x4e]) {
    puVar10 = (ushort *)(param_1 + 0x1c);
    do {
      fVar12 = (float)(int)(2 - (uint)(*puVar10 < 0x80)) * 0.5 * fVar2;
      FUN_00477db0(fVar12,fVar3,0x3f800000);
      FUN_00474410();
      thunk_FUN_004e8500(piVar1);
      FUN_00479f80(*(undefined4 *)(param_1[0x51] + iVar7 * 4));
      FUN_0047c2e0(0);
      FUN_00474470();
      FUN_004781d0(0x3f800000,0,0,0);
      FUN_00477db0(1.0 / fVar12,1.0 / fVar3,0x3f800000);
      iVar7 = iVar7 + 1;
      puVar10 = puVar10 + 1;
    } while (iVar7 < param_1[0x4e]);
  }
  FUN_00474470();
  FUN_00475590(0x14,2);
  FUN_00475590(0x15,2);
  FUN_00475590(0,0);
  FUN_00475590(1,0);
  return;
}


