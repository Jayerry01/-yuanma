undefined1 __fastcall FUN_0057d320(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  
  iVar8 = *param_1;
  if (*(float *)(iVar8 + 0x18) <= (float)param_1[3]) {
    if (*(float *)(iVar8 + 0x24) < (float)param_1[3]) {
      param_1[3] = *(int *)(iVar8 + 0x18);
    }
  }
  else {
    iVar7 = *(int *)(iVar8 + 0x24);
    param_1[7] = 0;
    param_1[3] = iVar7;
  }
  if (*(float *)(iVar8 + 0x10) <= (float)param_1[1]) {
    if (*(float *)(iVar8 + 0x1c) < (float)param_1[1]) {
      fVar9 = (float10)FUN_00593d9a();
      fVar9 = fVar9 + (float10)*(float *)(iVar8 + 0x10);
      goto LAB_0057d39a;
    }
  }
  else {
    fVar9 = (float10)FUN_00593d9a();
    fVar9 = (float10)*(float *)(iVar8 + 0x1c) - fVar9;
LAB_0057d39a:
    param_1[1] = (int)(float)fVar9;
  }
  if (*(float *)(iVar8 + 0x14) <= (float)param_1[2]) {
    if ((float)param_1[2] <= *(float *)(iVar8 + 0x20)) goto LAB_0057d3e0;
    fVar9 = (float10)FUN_00593d9a();
    fVar9 = fVar9 + (float10)*(float *)(iVar8 + 0x14);
  }
  else {
    fVar9 = (float10)FUN_00593d9a();
    fVar9 = (float10)*(float *)(iVar8 + 0x20) - fVar9;
  }
  param_1[2] = (int)(float)fVar9;
LAB_0057d3e0:
  fVar1 = *(float *)(iVar8 + 0x1d4);
  fVar2 = (float)param_1[1];
  fVar3 = *(float *)(iVar8 + 0x1d8);
  fVar4 = (float)param_1[2];
  fVar5 = *(float *)(iVar8 + 0x1dc);
  fVar6 = (float)param_1[3];
  FUN_0047ec40();
  iVar8 = *param_1;
  *(bool *)(param_1 + 10) =
       *(float *)(iVar8 + 0x1a8) <
       (fVar1 - fVar2) * *(float *)(iVar8 + 0x1e0) +
       (fVar3 - fVar4) * *(float *)(iVar8 + 0x1e4) + (fVar5 - fVar6) * *(float *)(iVar8 + 0x1e8);
  fVar4 = (float)param_1[9] * *(float *)(iVar8 + 0x19c);
  fVar1 = *(float *)(iVar8 + 0x19c);
  fVar2 = *(float *)(iVar8 + 0x44);
  fVar3 = *(float *)(iVar8 + 0x48);
  param_1[1] = (int)(fVar4 * (float)param_1[4] + (float)param_1[1] +
                    fVar1 * *(float *)(iVar8 + 0x40));
  param_1[2] = (int)(fVar4 * (float)param_1[5] + (float)param_1[2] + fVar1 * fVar2);
  param_1[3] = (int)(fVar4 * (float)param_1[6] + (float)param_1[3] + fVar1 * fVar3);
  fVar1 = *(float *)(iVar8 + 0x19c) + (float)param_1[7];
  param_1[7] = (int)fVar1;
  if ((float)param_1[8] < fVar1) {
    fVar1 = *(float *)(iVar8 + 400);
    fVar2 = *(float *)(iVar8 + 400);
    iVar8 = _rand();
    param_1[4] = (int)((float)iVar8 * 3.051851e-05 * (fVar2 - -fVar1) + -fVar1);
    fVar2 = -*(float *)(*param_1 + 400);
    fVar1 = *(float *)(*param_1 + 400);
    iVar8 = _rand();
    param_1[6] = -0x40800000;
    param_1[5] = (int)((float)iVar8 * 3.051851e-05 * (fVar1 - fVar2) + fVar2);
    FUN_0047ec40();
    param_1[7] = 0;
    fVar2 = *(float *)(*param_1 + 0x180);
    fVar1 = *(float *)(*param_1 + 0x184);
    iVar8 = _rand();
    param_1[8] = (int)((float)iVar8 * 3.051851e-05 * (fVar1 - fVar2) + fVar2);
  }
  return (char)param_1[10];
}


